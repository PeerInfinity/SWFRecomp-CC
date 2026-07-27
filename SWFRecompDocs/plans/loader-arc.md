# Loader arc — triage + tranches

**Created**: 2026-07-26 · **Baseline**: `9f4be9647`'s parent (`cf5b42970`),
`avm2/_results/results_graphics.json` from CI `30185616752`.
**Status**: **tranches 1 + 2 SHIPPED** (`8213dd4d6`) — see
§5 Postmortem at the bottom. Tranches 3–8 are still scoping only. The
re-ranked feature-priority list puts the avm2-platform mass next, and
`flash.display.Loader` is its largest single block.

Scope of this document: the 35 avm2 tests whose name matches
`loader`/`loaderinfo` (32 failing, 3 already passing:
`loaderinfo_properties`, `loaderinfo_root`, `loaderinfo_root_allows`), plus
the 9 `from_shumway/as3-loader/*` failures that ride on the same machinery.

## 1. What exists today

`SWFModernRuntime/src/avm2/avm2_display.c`:

- **`flash.display.LoaderInfo`** is a class with a **single root-movie
  instance** (`g_root_loader_info`, lazily built) whose getters are all
  *hardcoded to the root SWF*: `bytesLoaded`/`bytesTotal` →
  `SWF_ONDISK_SIZE`, `url`/`loaderURL` → `SWF_URL`, `contentType` →
  `"application/x-shockwave-flash"`, `actionScriptVersion` → 3,
  `frameRate`/`width`/`height`/`swfVersion` → the generated stage
  constants, `content` → `ctx->root`, `applicationDomain` → the current
  domain, `loader` → null, `childAllowsParent`/`parentAllowsChild`/
  `sameDomain` → true.
- **`flash.display.Loader`** is a real DisplayObjectContainer whose
  `contentLoaderInfo` is its *own* fresh `LoaderInfo` instance
  (`loader_ensure_cli`), so `addEventListener` on it is a real
  registration. `load` is a no-op except for one special case (the
  ArmorGames `AGI.swf` shell, seeded for Elephant Quest);
  `loadBytes`/`unload`/`unloadAndStop`/`close` are `loader_noop`.
- Missing entirely: `isURLInaccessible`, `sharedEvents`,
  `uncaughtErrorEvents`, `bytes`, `LoaderContext`, `JPEGLoaderContext`.

**The single largest defect is not a missing feature — it is that a fresh
`Loader`'s own LoaderInfo answers with the ROOT movie's numbers.** Every
getter ignores which instance it is called on, so
`new Loader().contentLoaderInfo` reports `content = [object Test]`,
`bytesTotal = 3214`, `url = file:///test.swf`,
`contentType = application/x-shockwave-flash`. That one behaviour is what
breaks the first block of nearly every test in the list, *before* any
loading question arises.

### Ruffle's model (the target)

`~/CC/ruffle/core/src/avm2/object/loaderinfo_object.rs` +
`globals/flash/display/loader_info.rs`:

- A LoaderInfo holds a `LoaderStream`: `NotYetLoaded(movie, root_clip,
  is_stage)` or `Swf(movie, root)`, plus the flags `init_event_fired`,
  `complete_event_fired`, `expose_content`, `errored`, and a
  `content_type` (`Unknown|Swf|Jpeg|JpegXr|Png|Gif`).
- `content_type_hide_before_init()` returns `Unknown` (→ `null`) until
  `init` has fired **on that LoaderInfo**. This is what makes
  `stage.loaderInfo.contentType` null while `root.loaderInfo.contentType`
  is `application/x-shockwave-flash`.
- **The Stage has its OWN LoaderInfo, distinct from the root movie's**
  (`context.rs:390`, `is_stage = true`, vs `movie_clip.rs:335` for the root
  clip). Both call `set_expose_content()` so `content` is readable before
  `init`; only the root clip's ever fires `init`. Our singleton conflates
  the two, which is exactly the `stage_loaderinfo_properties` diff.
- Properties that describe the *loaded movie* throw
  **`Error #2099: The loading object is not sufficiently loaded to provide
  this information.`** while the stream is `NotYetLoaded`:
  `actionScriptVersion`, `childAllowsParent`, `frameRate`, `height`,
  `parentAllowsChild`, `sameDomain`, `swfVersion`, `width`.

## 2. The AOT question, answered

The premise "we are an AOT recompiler, so a child SWF loaded at runtime
cannot be recompiled on the fly" is true in general and **almost
irrelevant to this corpus**, because of an existing mechanism:

`ruffle-tests/verify_output.py` already **recompiles every sibling SWF of a
test at build time**:

- `find_child_swfs(test_dir)` → every `*.swf` that is not `test.swf`, plus
  every `.png/.jpg/.jpeg`.
- `recompile_child_swf()` → runs the recompiler into `_child_<name>/`.
- `generate_child_movie_file()` → wraps the child's generated C with a
  per-child symbol prefix (`str_N`, `func_N`, `sprite_N_frame_*`,
  `shape_data`, …), offsets its `string_id`s past the parent's
  `MAX_STRING_ID`, offsets char IDs by `movie_id * 1000`.
- `generate_movie_registry()` → `findMovieEntry(const char* filename)`
  (`SWFModernRuntime/include/libswf/swf.h:385`, `MovieEntry`).
- `get_self_load()` → a `self_movie_entry` for "test.swf loads itself".
- Images get a synthetic `MovieEntry` with `swf_version = 0` and the
  decoded dimensions (`generate_image_movie_file`), and the raw bytes are
  *also* bundled as a data file (`find_data_files` skips only
  `.swf/.fla/.toml/.json/.c/.h/.py`, so `.png/.jpg/.txt/.bin` are
  linked in and reachable via `findDataFile(name)`).

So the child SWFs in these tests — `loadable.swf`, `load1.swf`,
`load2.swf`, `child.swf`, `loaded.swf`, `avm1.swf` — are **already
compiled into the test binary today**. The gaps are:

1. **`MovieEntry` is AVM1-only.** It carries `frame_funcs` + `init_func`
   and nothing for AVM2: `generate_child_movie_file` reads
   `RecompiledScripts/` + `RecompiledTags/` and never looks at
   `RecompiledABC/`. An AVM2 child's ABC therefore is not linked, and
   there is no per-movie ABC/script-init entry point to call.
2. **`install_test_dir()` in `download_tests.sh` copies only top-level
   files.** Upstream stores some children one directory down
   (`loader_child_getdefinition/child/child.swf`,
   `loader_duplicate_class/loader_domain_child/*.swf`,
   `loader_duplicate_coerce/child/child.swf`) and our mirror silently
   drops them — 4 tests cannot pass until the downloader recurses (and
   `find_child_swfs` with it).
3. **`loadBytes` needs a bytes→movie identity.** Both sources are
   build-time-knowable: `[Embed(source="loadable.swf")]` (the recompiler
   knows the source filename) and `URLLoader.load(URLRequest("child.swf"))`
   feeding `loader.loadBytes(urlLoader.data)` (the URL is a literal).
   Tag the ByteArray with its origin filename and `loadBytes` resolves
   through the same `findMovieEntry`.

Per-bucket verdict:

| Bucket | Needs | Verdict |
|---|---|---|
| Unloaded LoaderInfo surface | (a) API + state only | no content of any kind |
| Event sequence w/o content (unknown type, `#2124`) | (a) | events + byte accounting only |
| Image loading (PNG/JPEG) | (b) decoding | **stb_image is already linked** — `src/actionmodern/image_decode.c` uses `stbi_load_from_memory`; AVM2 `BitmapData` has real pixel storage (`avm2_bitmap.c: bd_alloc`, premultiplied ARGB) and renders |
| JPEG-XR | (b) | **no decoder**; stb cannot do JXR. Upstream gates these behind `[required_features] jpegxr` — treat as won't-do |
| Nested-SWF execution | (c) | tractable via the existing child pipeline **once it learns AVM2** (gap 1 above) |
| `framework_*.swz` (Flex) | (c) | won't-do: needs the real Flex framework SWF's classes |
| AVM1 child under an AVM2 parent | (c) + dual-VM | belongs to feature-priority-map arc 8, not here |

## 3. Per-test triage

Line counts are `matching/expected` from the graphics baseline.

### Bucket A — unloaded/undistinguished LoaderInfo state (no loading at all)

| Test | Lines | What it actually needs |
|---|---|---|
| `loaderinfo_loadurl` | 8/12 | `url` must be **null** for a Loader's own LoaderInfo in all four states (fresh, after `load`, after `unload`, after `loadBytes`); `loaderURL` stays `file:///test.swf` |
| `loaderinfo_properties_not_loaded` | 15/23 | `#2099` from the 8 movie-describing getters while not loaded |
| `stage_loaderinfo_properties` | 22/24 | `isURLInaccessible` → false (currently `undefined` — property absent), and **`stage.loaderInfo` must be a distinct never-`init`ed LoaderInfo** so `contentType` is null |
| `loaderinfo_events` | 4/7 | fire `init` on the root movie's LoaderInfo, ordered **after frame 1's `exitFrame` and before frame 2's `enterFrame`** |

Note the constraint the currently-passing `loaderinfo_properties` imposes:
its frame-2 script reads `contentType`/`actionScriptVersion`/… off the ROOT
LoaderInfo and expects real values — consistent with `init` having fired at
the end of frame 1. Any `#2099` gate must be keyed on the *stream state* of
the specific LoaderInfo, never on "is this a Loader's".

### Bucket B — event sequence with no content

| Test | Lines | Needs |
|---|---|---|
| `loader_unknown_content` | 0/24 | `load("data.txt")` → `open`, two `progress` (0/20 then 20/20), `ioError` carrying `Error #2124: Loaded file is an unknown type. URL: …`; `content` null; `bytes.length` 0; `frameRate` throws `#2099` throughout |
| `loader_bytes_unknown_content` | 1/14 | same via `loadBytes` of an `[Embed]`ed `.txt` (no `open` event); note `bytesLoaded/bytesTotal` are the *data* length (20), not the parent SWF's — ours prints 1695 |
| `loaderinfo_more` | 0/6 | `applicationDomain` **null** until `init`, then the `LoaderContext`'s domain, then null again after `unload`; `bytesLoaded/Total` 0 after `unload`. Needs `LoaderContext` (`#1065` today) and a `complete` event, but never touches `content` |

`bytes` has a three-state behaviour worth writing down once:
**null** before any load, an **empty ByteArray** while loading/unknown, the
real bytes once a SWF is loaded (`loader_events` expects `bytes.length` to
become 1490 for an 893-byte child — the *decompressed* size).

### Bucket C — image content

| Test | Lines | Needs |
|---|---|---|
| `loader_image` | 0/8 | `progress`×2, `init`, `complete` for `test.png`; `contentType` null before `init` then `image/png` |
| `loader_bitmap_transparency` | 1/14 | three sequential loads (jpg, png, rgba png); `content` is a **`Bitmap`**; `contentType` per format; `bitmapData.transparent` false/false/**true** |
| `loader_loadbytes_invalid_png` | 0/4 | a deliberately malformed PNG that Flash still decodes (upstream ruffle#18831); `content` is a Bitmap, `contentType` `image/png`, `bytes.length` 1024 |
| `loader_jpegxr`, `loader_jpegxr_alpha` | 0/2, 0/1 | JPEG-XR decoder — **won't-do** |

### Bucket D — Loader as a mouse target

| Test | Lines | Needs |
|---|---|---|
| `loader_visibility_interactive` | 0/1 | a click must hit the Loader (needs image content from bucket C first) |
| `loader_noninteractive_try_click_root` | 0/5 | `mouseEnabled`/`mouseChildren` on a Loader wrapping image content; `e.target` resolution walks to the Loader / the wrapper Sprite / the Stage. Ours currently reports `[object Test] (root1)` or Stage for every click |
| `loader_try_click_root` | 0/16 | same but the content is a SWF (bucket F), and sub-pixel stage coords (`248.25`) are expected |
| `mouse_pick_loader_avm1` | 5/42 | AVM1 child inside an AVM2 parent — **dual-VM arc**, not this one |

### Bucket E — navigator / fetch logging

| Test | Lines | Needs |
|---|---|---|
| `loader_method` | 16/85 | all 66 of our lines already match in content; the only missing output is the `Navigator::fetch:` blocks (`URL`/`Method`/`Mime-Type`/`Body`). `log_fetch = true` in `test.toml`. Also: an empty `URLVariables` must stringify to `""` (we print `[object URLVariables]`), and `data = []`/`{}`/`""` selects GET vs POST |
| `loader_load` | 12/128 | same plus `requestHeaders` serialization: duplicate header names collapse to the **last** value while keeping first-appearance order |

These two need no loading at all — they need the runtime to *log the
request it would have made*, at `Loader.load`/`URLLoader.load` time, in
Ruffle's navigator format. Both test.tomls say outright that the test does
not run successfully in Flash Player either; it grades Ruffle's navigator.

### Bucket F — nested SWF execution

| Test | Lines | Needs beyond the AVM2 child pipeline |
|---|---|---|
| `loader_events` | 8/92 | full event sequence with real byte counts; child's `stage`/`parent` are null in its constructor, set by the time `ADDED_TO_STAGE` fires; `loader.contentLoaderInfo === loader.content.loaderInfo`; `parameters` (2 flashvars from the child SWF) |
| `loader_loadbytes_events` | 2/30 | as above via `loadBytes` of an `[Embed]`ed SWF; `bytes.position` must stay 0; re-`addChild`ing the content moves it out of the Loader (`numChildren` 1 → 0) |
| `loader_reuse` | 7/38 | loading twice into one Loader; the LoaderInfo **resets to NotYetLoaded** between loads (`reset_init_and_complete_events`) |
| `loader_loaderurl` | 2/6 | `loaderInfo.url`/`loaderURL` chain across a 3-deep load (`test.swf` → `load1.swf` → `load2.swf`) |
| `loader_error_in_root_ctor` | 0/4 | `URLLoader` read of `child.swf` (bucket G) then `loadBytes`; an uncaught error in the child's root constructor must abort `init`/`complete` and print `Error: …\n\tat Child()` |
| `loader_loadbytes_url` | 1/12 | self-load recursion 4 deep, each with a `new ApplicationDomain()`; the URL grows `/[[DYNAMIC]]/<id>` per level. `get_self_load` already exists for AVM1 |
| `loader_child_getdefinition` | 2/5 | **blocked on the downloader** (nested `child/child.swf`) + `getDefinitionByName` inside the child's domain |
| `loader_duplicate_class` | 2/48 | **blocked on the downloader** (3 nested child SWFs) + full `ApplicationDomain` isolation: same class name in parent/child/other-child domains, `applicationDomain.getDefinition`, script initializers per movie |
| `loader_duplicate_coerce`, `loader_duplicate_coerce_new_domain` | 1/3, 1/4 | **blocked on the downloader**; an interface defined in both SWFs must coerce across domains |
| `loader_applicationDomain` | 0/4 | needs the real Flex `framework_*.swz` classes — **won't-do** |

### Bucket G — URLLoader over bundled files

| Test | Lines | Needs |
|---|---|---|
| `url_loader` | 0/25 | `URLLoader.load` reading `data.txt`/`data.bin` through `findDataFile`, `dataFormat` text/binary, `open`/`progress`/`httpStatus`/`complete`/`ioError` (`Error #2032` for the missing file), and `data` visible only after `complete` |

Also `jpeg_loader_context` (0/6) — `flash.system.JPEGLoaderContext`
(`checkPolicyFile`, `deblockingFilter`) does not exist (`#1065`). It is
pure class surface, unrelated to real loading, and belongs with tranche 1.

## 4. Ranked tranches

Predictions are stated per the feature-priority-map convention: they get
postmortemed against CI.

| # | Tranche | Buckets | Predicted tests | Size |
|---|---|---|---|---|
| 1 | **Per-instance LoaderInfo state machine** — `LoaderStream` equivalent (NotYetLoaded/Loaded + `init_fired`/`expose_content`/`content_type`), a **separate Stage LoaderInfo**, `#2099` on the 8 movie getters, `url` null until loaded, `isURLInaccessible`, `sharedEvents`, root-movie `init`/`complete` firing at the frame-1 `exitFrame` boundary, `LoaderContext` + `JPEGLoaderContext` class surface | A + `jpeg_loader_context` | **+5** (`loaderinfo_loadurl`, `loaderinfo_properties_not_loaded`, `stage_loaderinfo_properties`, `loaderinfo_events`, `jpeg_loader_context`) and ~45 newly-matching lines in 8 more | small |
| 2 | **Load pipeline without content** — `open`/`progress`/`complete`/`ioError` dispatch, byte accounting from the real source length, the three-state `bytes`, `#2124` for unknown types, `applicationDomain` from `LoaderContext`, `unload` resetting the stream | B | **+3** (`loader_unknown_content`, `loader_bytes_unknown_content`, `loaderinfo_more`) | small |
| 3 | **Image content** — stb decode → `BitmapData` → `Bitmap` as `content`, `contentType` per sniffed format | C (minus JXR) | **+3** (`loader_image`, `loader_bitmap_transparency`, `loader_loadbytes_invalid_png`) | medium |
| 4 | **URLLoader over bundled data** | G | **+1** (`url_loader`); prerequisite for two bucket-F tests | small |
| 5 | **Navigator fetch log** | E | **+2** (`loader_method`, `loader_load`) | small-medium |
| 6 | **AVM2 child-SWF execution** — `MovieEntry` gains an ABC/script-init entry point, `generate_child_movie_file` handles `RecompiledABC`, `Loader.load`/`loadBytes` resolve through `findMovieEntry`, child root construction + `addChild` into the Loader, event ordering, LoaderInfo reset on reload | F (unblocked part) | **+6** (`loader_events`, `loader_loadbytes_events`, `loader_reuse`, `loader_loaderurl`, `loader_error_in_root_ctor`, `loader_loadbytes_url`) **+ up to 9** `from_shumway/as3-loader/*` | **large** |
| 7 | **Loader hit-testing** | D (minus AVM1) | **+3** (`loader_visibility_interactive`, `loader_noninteractive_try_click_root`, `loader_try_click_root`) | medium |
| 8 | **Nested-child download + ApplicationDomain isolation** — recurse in `install_test_dir`/`find_child_swfs`, then per-movie domains with duplicate class names | F (blocked part) | **+4** (`loader_child_getdefinition`, `loader_duplicate_class`, `loader_duplicate_coerce`, `loader_duplicate_coerce_new_domain`) | large |

**Won't-do (3 tests):** `loader_jpegxr`, `loader_jpegxr_alpha` (no JPEG-XR
decoder; upstream feature-gates them), `loader_applicationDomain` (Flex
framework SWZ). **Elsewhere (1):** `mouse_pick_loader_avm1` → dual-VM arc.

Reachable total: **26 of the 32** avm2 failures, plus up to 9 in
from_shumway. Tranches 1+2 are **8 tests for a small amount of work** and
are the recommended first implementation session; they are also
load-bearing for every later tranche, because all of them depend on the
LoaderInfo state machine being per-instance.

### Ordering note

Tranche 1 must land before 2–8: today every LoaderInfo getter ignores its
receiver, so any later work would be built on a getter set that cannot
distinguish "the root movie", "the Stage", "a Loader that has not loaded",
and "a Loader that has". Tranche 6 is the one genuinely large item and the
only one that touches the recompiler + harness rather than just the
runtime.

### Session gate

The scoping brief authorised implementing the first tranche only if triage
found **≥5 tests needing pure API surface / trivial event sequences**.
Tranche 1 lands on 5 with `jpeg_loader_context` folded in, but four of the
five (`loaderinfo_events`'s event ordering, the Stage-LoaderInfo split,
`#2099` gating, `url`-null semantics) are a state-machine change to
`avm2_display.c`'s LoaderInfo rather than new surface — it sits right on the
line the gate draws. It is small (one file), self-contained, and
CI-verifiable, with the only regression risk being the three
already-passing `loaderinfo_*` tests.

## 5. Postmortem — tranches 1 + 2 (`8213dd4d6`, CI `30226375815`)

**Predicted +8, actual +12. Zero regressions**; every crash bucket flat
(`recomp_fail` 1, `runtime_error` 8, and segfault/timeout/compile_fail
still absent corpus-wide). Corpus 3818 → 3830 effective over the
4419-test intersection with `2a03793a6`; avm2 871 → 881, from_shumway
172 → 174. All eight predicted tests pass; four more came free:

| Gain | Suite | Predicted? |
|---|---|---|
| `loaderinfo_loadurl`, `loaderinfo_properties_not_loaded`, `stage_loaderinfo_properties`, `loaderinfo_events`, `jpeg_loader_context` | avm2 | yes (tranche 1) |
| `loader_unknown_content`, `loader_bytes_unknown_content`, `loaderinfo_more` | avm2 | yes (tranche 2) |
| `loader_jpegxr`, `loader_jpegxr_alpha` | avm2 | **no — filed as won't-do** |
| `avm1movie` (→ ruffle_matched), `image-loading` | from_shumway | **no** |

### What the triage got right

Every per-test requirement in buckets A and B held exactly as written.
The three non-negotiable constraints were the load-bearing ones:

- Keying every gate on the **receiving instance's** stream state, never on
  "is this a Loader's LoaderInfo", is what let `loaderinfo_properties`
  (root, frame 2) and `loaderinfo_properties_not_loaded` (fresh Loader)
  coexist. `loaderinfo_properties`'s reads really are on frame 2 — the
  recompiled ABC puts `contentType` in `test_fla.MainTimeline::frame2` —
  so hiding contentType until `init` costs nothing.
- The Stage's LoaderInfo genuinely had to become a separate object. The
  split is two lines in `do_get_loader_info` (dispatch on the display
  ext's `is_stage`) plus a second lazily-built singleton.
- Firing the root's init/complete immediately after the `exitFrame`
  broadcast in `avm2_display_run_tick` (Ruffle `run_exit_frame`) produced
  `loaderinfo_events`'s order on the first try.

### What it got wrong

- **`loader_jpegxr` and `loader_jpegxr_alpha` are not won't-do.** Both
  were written off as needing a JPEG-XR decoder. They only `trace` the
  `contentType`, and image comparisons do not gate pass/fail here, so
  sniffing the `II\xBC` magic and reporting `image/jpegxr` is the entire
  test. **Lesson: check what a test actually asserts before filing it
  under a missing decoder** — the `[required_features]` key in
  `test.toml` describes what *upstream Ruffle* needs to render the frame,
  not what the trace output needs.
- **Two `from_shumway` tests outside the scoped 9 came along too**:
  `avm1movie` (→ ruffle-matched) and `image-loading` (→ pass). The scope
  only counted the `as3-loader/*` directory, so the "up to 9 in
  from_shumway" figure was a floor for the wrong reason — Loader work
  reaches tests whose names never say "loader".
- `loaderinfo_more` was filed as needing "a `complete` event" — true, but
  it also pinned the **timing model**: `load()` must defer to the next
  frame (its two `applicationDomain` traces are both null before the
  handler runs), while `loader_bytes_unknown_content` proves `loadBytes`
  is **synchronous** (its whole event sequence prints before the line
  after the call). That asymmetry was not in the triage and is the single
  most important behavioural detail in tranche 2.
- The `#2124` message needs an **absolute** URL (`file:///data.txt`);
  Ruffle resolves the request URL against the loading movie's URL before
  the load starts. The triage quoted the message but not the resolution.

### Line-count movement in the not-yet-passing tests

No test anywhere lost matching lines. The largest gains sit in tranche 6's
bucket, which is the next big block: `loader_events` 8 → 19,
`loader_loadbytes_events` 2 → 11, `loader_reuse` 7 → 14,
`from_shumway/as3-loader/loaderinfo/loaded-content-properties` 3 → 35,
`as3-loader/LoaderTest` 1 → 5. Outside the arc, `delayed_symbolclass`
3 → 16 and the three `large_preload_*` tests 4–8 → 16–19 — all of them
were blocked on the same "a Loader never fires anything" hole.

### Shape of the delivered code

`SWFModernRuntime/src/avm2/avm2_display.c` holds the state machine
(`Avm2LoaderInfoExt` with `kind`/`loaded`/`expose_content`/`init_fired`/
`complete_fired`/`errored`/`content_type`), the pipeline
(`loader_sniff`, `loader_resolve_url`, `loader_deliver`, a deferred-load
queue drained at the tick's start, an active-load list drained after
`exitFrame`), and the two frame hooks. `avm2_globals.c` holds
`LoaderContext`/`JPEGLoaderContext`/`ImageDecodingPolicy`.
`avm2_events.c` gained C-side `ProgressEvent`/`IOErrorEvent` constructors
and the per-subclass `toString` field lists — the ErrorEvent family was
inheriting `TextEvent`'s and printing `[TextEvent …]`, which would have
broken every bucket-B and bucket-G expectation on its own.

### What tranche 3 inherits

`content` is still null for every load and `bytes` still hands back an
empty ByteArray, because no loaded content is instantiated. The pipeline
already sniffs PNG/JPEG/GIF correctly and marks the stream loaded, so
tranche 3 is exactly "decode the bytes stb already can read into a
`BitmapData`, wrap it in a `Bitmap`, and set it as the stream's root
clip" — the events, byte accounting and `contentType` around it are done.
