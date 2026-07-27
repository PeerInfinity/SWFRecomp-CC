# Loader arc — triage + tranches

**Created**: 2026-07-26 · **Baseline**: `9f4be9647`'s parent (`cf5b42970`),
`avm2/_results/results_graphics.json` from CI `30185616752`.
**Status**: **tranches 1 + 2 SHIPPED** (`8213dd4d6`, §5 Postmortem),
**tranches 3 + 4 SHIPPED** (`f6ba5c677` + `28577da2a`, §6 Postmortem), and
**tranche 5 SHIPPED** (§7 Postmortem). Tranches 6–8 are still scoping only;
tranche 7 shrank to +1 as a side effect of 3. The re-ranked feature-priority
list puts the avm2-platform mass next, and `flash.display.Loader` is its
largest single block.

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
| 3 | ~~**Image content** — stb decode → `BitmapData` → `Bitmap` as `content`, `contentType` per sniffed format~~ **SHIPPED `f6ba5c677`** | C (minus JXR) | **+3** (`loader_image`, `loader_bitmap_transparency`, `loader_loadbytes_invalid_png`) — all three, plus `loader_visibility_interactive` free; see §6 | medium |
| 4 | ~~**URLLoader over bundled data**~~ **SHIPPED `28577da2a`** | G | **+1** (`url_loader`); prerequisite for two bucket-F tests | small |
| 5 | ~~**Navigator fetch log**~~ **SHIPPED** | E | **+2** (`loader_method`, `loader_load`) — actual: `loader_method` only, plus 5 adopters outside the arc; see §7 | small-medium |
| 6 | **AVM2 child-SWF execution** — `MovieEntry` gains an ABC/script-init entry point, `generate_child_movie_file` handles `RecompiledABC`, `Loader.load`/`loadBytes` resolve through `findMovieEntry`, child root construction + `addChild` into the Loader, event ordering, LoaderInfo reset on reload | F (unblocked part) | **+6** (`loader_events`, `loader_loadbytes_events`, `loader_reuse`, `loader_loaderurl`, `loader_error_in_root_ctor`, `loader_loadbytes_url`) **+ up to 9** `from_shumway/as3-loader/*` | **large** |
| 7 | **Loader hit-testing** | D (minus AVM1) | ~~+3~~ **+1** — image content alone passed `loader_visibility_interactive` and took `loader_noninteractive_try_click_root` to 4/5, so only `loader_try_click_root` is left and it needs tranche 6's SWF content (§6) | medium |
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

## 6. Postmortem — tranches 3 + 4 (`f6ba5c677` + `28577da2a`, CI `30230575524`)

**Predicted +4 (3 for tranche 3, 1 for tranche 4), actual +6. Zero
regressions**; every crash bucket flat (`recomp_fail` 1, `runtime_error` 8,
and segfault/timeout/compile_fail still absent corpus-wide). Corpus 3830 →
3836 effective over the 4419-test intersection with `28577da2a`'s baseline
results; avm2 881 → 886, from_shumway 174 → 175. All four predicted tests
pass, and the extras are `loader_visibility_interactive` (bucket D) and
`from_shumway/flash_net_URLRequest`. Mode parity holds: the five new avm2
passes were verified in `--mode=graphics` locally as well as no-graphics, and
CI's graphics run reproduced the local deltas test-for-test.

| Gain | Suite | Predicted? |
|---|---|---|
| `loader_image`, `loader_bitmap_transparency`, `loader_loadbytes_invalid_png` | avm2 | yes (tranche 3) |
| `url_loader` | avm2 | yes (tranche 4) |
| `loader_visibility_interactive` | avm2 | **no — filed under tranche 7** |
| `flash_net_URLRequest` | from_shumway | **no** |

Line movement in the still-failing tests:
`loader_noninteractive_try_click_root` 0 → 4,
`from_shumway/as3-loader/loaded-content-properties` 35 → 36, `bom` 3 → 4,
`blend_shader_luma_lighten` 0 → 1. No test lost matching lines.

### What the triage got wrong

- **The timing model was NOT settled, and the session brief said it was.**
  §5 concluded "`load()` defers to the next tick's start; `loadBytes()` is
  synchronous" and tranche 3 was told not to change it. But
  `loader_bitmap_transparency` chains **three** `load()`s through each
  other's `complete` handlers inside `num_ticks = 2`, which one-tick-per-link
  cannot finish. Ruffle's actual model is its async executor: the test
  harness (`tests/framework/src/runner.rs::do_tick`) runs it to quiescence
  **after** every tick, so a fetch resolves past the frame that issued it
  (not at the next frame's *start*), and a load spawned inside one of those
  handlers is picked up by the same `executor.run()`. Two ticks suffice
  because all three links share one drain. **Lesson: "defers by a frame" and
  "resolves after this frame" are indistinguishable on a single load and
  wildly different on a chain — a timing model inferred from one-shot tests
  is a hypothesis, not a settled fact.**
- **init/complete are not uniform across content types.** Ruffle's
  `movie_loader_complete` calls `fire_init_and_complete_events` inline only
  when the loaded object is *not* a MovieClip — i.e. only for an image. A
  child SWF's are deferred to the clip's own `on_exit_frame`, one tick later.
  Firing both the same way cost exactly **one matching line** in
  `from_shumway/as3-loader/LoaderTest` (5 → 4), whose `enterFrame` sits
  between the last progress event and `init`. That single line was the only
  signal separating the two models anywhere in the corpus — the line-floor
  watch list earned its keep.
- **`loader_loadbytes_invalid_png`'s `1024` is `content.width`, not
  `bytes.length`.** §3's bucket C row and §5's three-state `bytes` note both
  read it as a byte count; the embedded PNG is 24514 bytes and 1024 is its
  IHDR width. So `bytes`' third state was never on tranche 3's critical path.
- **stb rejects that PNG outright**, with "not enough pixels": its IDAT zlib
  stream is valid *and complete* but only carries 128 of the 512 declared
  rows. The brief guessed stb would cope because it skips CRC checks — the
  corruption is not a CRC. The answer came from the oracle's error arm, not
  the decoder: Ruffle's `decode_png` catches a malformed stream and returns
  an **empty bitmap at the header's declared size**, so
  `stbi_info_from_memory` plus all-transparent pixels is the entire fix.
  **Lesson: on a decoder-tolerance question, read what the oracle does when
  its decoder fails.**
- **Bucket D is mostly a side effect of bucket C, not its own tranche.**
  `loader_visibility_interactive` passes and
  `loader_noninteractive_try_click_root` goes 0 → 4 purely because a Loader
  now has content to hit. Tranche 7 should be re-read as **+1**
  (`loader_try_click_root` alone, and it needs SWF content from tranche 6).

### What it got right

- `transparent` from the decoded channel count rather than "PNG ⇒ true":
  stb reports the *source* comp as 3/3/4 for `test.jpg`/`test.png`/
  `test_rgba.png`, which maps exactly onto the expected false/false/true.
  Ruffle reaches the same answer through
  `BitmapFormat::supports_transparency`.
- JPEG-XR staying sniff-only. It is excluded from the decode branch
  explicitly, and would have been safe regardless — stb cannot read a JXR
  header either, so the fallback would have returned NULL rather than
  erroring the flow.
- Tranche 4 landed first-try with no surprises beyond needing a
  `HTTPStatusEvent.toString` (it was inheriting `Event`'s four fields, the
  same class of bug as tranche 2's ErrorEvent family).

### Shape of the delivered code

`avm2_bitmap.c` gained `avm2_bitmap_from_image_bytes` (stb decode →
premultiplied `BitmapData` → constructed `Bitmap`; truncating premultiply to
match Ruffle's `premultiply_alpha_rgba`). `avm2_display.c`'s loader phase is
now a single `avm2_loader_drain` after the `exitFrame` broadcast: flush the
active list (deferred SWF init/complete, and loadBytes deliveries), then
resolve queued fetches in a bounded loop so chains close inside one tick. The
same file holds the URLLoader pipeline, wired into `avm2_globals.c`'s class
shell through `avm2_display_wire_url_loader`. `Loader.content` now delegates
to `contentLoaderInfo.content` as `Loader.as` does, so it honours the
`expose_content` gate; `load`/`loadBytes`/`unload` share a
`loader_drop_content` that also removes the old content child.

### What tranche 5/6 inherit

- `bytes` reaches its third state only for **bundled** assets, whose storage
  is generated-static. A `loadBytes` source ByteArray is deliberately not
  aliased (the script can resize it), and a child SWF's decompressed bytes
  are not in the movie registry at all — `loader_events`' expected
  `bytes.length` of 1490 is tranche 6's problem, and it needs the registry to
  carry the bytes, not just `file_size`.
- `from_shumway/flash_net_URLLoader` is **not** reachable from tranche 4: it
  fetches an unbundled 2674-byte asset, so it correctly takes the #2032 arm.
  It needs the asset bundled, which is a harness change.
- URLLoader's `dataFormat = "variables"` falls through to text. No test uses
  URLVariables as a URLLoader *response* (only as a request body, which is
  tranche 5's `loader_method`), so parsing it would be untested code.

## 7. Postmortem — tranche 5 (navigator fetch log)

**Predicted +2 (`loader_method`, `loader_load`), actual +6 — but only one of
the two predicted tests.** `loader_method` passes; `loader_load` stops at
126/128 on something the triage never looked at. The other five gains come
from the adopters sweep and from a mechanism the triage did not know the
tranche needed at all.

| Gain | Suite | Predicted? |
|---|---|---|
| `loader_method` | avm2 | yes |
| `net_navigateToURL` | avm2 | sweep candidate |
| `navigateToURL_target_normalize` | avm2 | sweep candidate |
| `geturl_target_normalize` | avm1 | sweep candidate |
| `geturl_opcode_target_normalize` | avm1 | sweep candidate |
| `uncaught_error_basic` | avm2 | **no — not a `log_fetch` test at all** |

Line movement in the still-failing tests: `loader_load` 12 → 126,
`geturl` 0 → 4, `event_handler_exception` 1 → 5,
`uncaught_errors_stringified` 1 → 2, `url_vars` 1 → 3. No test lost
matching lines; `import_assets/empty_url` (the one `log_fetch` test that
passed before this work, with **no** fetch lines expected) still passes.

### What the triage got wrong

- **The blocker was not the log — it was uncaught-error tracing.** Both
  target tests end on a `#1034` that escapes an `ENTER_FRAME` handler, and
  the last two lines of each are that error plus its stack. Ruffle's
  `Avm2::uncaught_error` calls `avm_trace` whenever the player is in Debug
  mode, which the test harness always is, so an uncaught error is *graded
  output*. Our `print_uncaught` wrote to stderr only, with a comment
  asserting the opposite. That single change is worth more than the log
  itself: it also took `uncaught_error_basic` to a pass and moved three
  other tests, and it is the mechanism `loader_error_in_root_ctor`
  (tranche 6) will need.
- **Attribution: a parameter coercion belongs to the CALLER.** Ruffle
  coerces the whole signature in `Activation::init_from_method`, which runs
  before the callee's call-stack frame is pushed, so `loader_method`'s
  `#1034` prints `at Test/onFrame()` and never `at Test/load()`. Our
  `avm2_setup_locals` already popped the frame for the `#1063` arg-count
  check for exactly this reason; the coercion needed the same treatment.
- **`loader_load` is unreachable, and the reason has nothing to do with
  Loader.** Its expected `URLVariables` body is `cccc=true&aaa=bbb` — the
  bag was populated `aaa` then `cccc`. Ruffle's AVM2 dynamic properties live
  in an FNV-hashed `hashbrown` table and enumerate in bucket order; we and
  Flash use insertion order. Ruffle's own `url_vars` test sorts its output to
  dodge this and says so in a comment. Filed in
  `RUFFLE_VS_FLASH_DIFFERENCES.md`; the test is accepted at 126/128.
- **The sweep's AVM1 candidates split cleanly in two, and the triage did not
  see the line.** `geturl_target_normalize` / `geturl_opcode_target_normalize`
  are *pure* navigate-log tests and both went to 100%. `geturl` (4/7) and
  `loadvariables_method` (0/7) want `Param:`/`Body:` **form values** — the
  timeline's variables in enumeration order — and root-timeline variables in
  our runtime live in the global `var_array`/`var_map`, not in
  `root_movieclip.dynamic_props`. There is no insertion order to walk. That
  is a variable-storage gap (the same one `for (i in _root)` has), not a
  navigator one, and it is why the collector in `action.c` is written but
  returns nothing at root scope.
- **`getURL` was not wired at all.** A bare `getURL(url, window)` in a
  timeline script is `MovieClip.prototype.getURL` reached through the
  prototype chain (Ruffle `globals/movie_clip.rs`), and ours was one of the
  name-only stubs. The GetURL2 *opcode* path was separate and already
  present. Two call sites, not one.

### What it got right

- The format, read straight out of `tests/framework/src/backends/navigator.rs`,
  needed no guessing: headers as one trace entry whose first line is
  `  Headers:`, `Mime-Type`/`Body` only when a body exists, and Rust's
  `{:02X?}` slice debug for a non-form body.
- **The placement warning was the single most valuable line in the brief.**
  `fetch` runs inside the spawned load future, which Ruffle's harness polls
  only after the frame — so the block lands *after* the calling frame's
  traces (`loader_method` prints `undefined` from
  `trace(loader.load(request))` **before** its own fetch block). Logging
  inline would have inverted every pair. `navigate_to_url` is the opposite:
  a plain synchronous backend call, printed immediately. The queue-and-flush
  split in `utils.c` exists entirely because of that asymmetry.
- The URL in the log is the request's own URL, not resolved to
  `file:///…` — the brief's guess that §5's absolute-URL lesson applied here
  was wrong, but harmlessly so, because Ruffle logs before `resolve_url`.
- Gating on a per-test macro was the right protection: `url_loader`,
  `loader_events`, `loader_reuse` and every other Loader test are byte
  identical, and `import_assets/empty_url` still emits nothing.

### Shape of the delivered code

`SWFModernRuntime/src/utils.c` (already compiled into every build and both
VMs) gained `swf_log_fetch_queue` / `swf_log_fetch_pending` /
`swf_log_fetch_flush` / `swf_log_navigate`, all no-ops without `-DLOG_FETCH`.
Target normalization (`blank`/`BLANK`/`_BlAnK` → `_blank`) lives in
`swf_log_navigate` because Ruffle normalizes at the navigator sink, shared by
both VMs. `verify_output.py` parses `log_fetch` in `test.toml` and adds
`-DLOG_FETCH=1`, in both the native and the wasm compile paths.

AVM2: `avm2_display.c` grew `avm2_log_fetch_request`, a transcription of
`request_from_url_request` (GET appends data to the query, headers are an
IndexMap insert so a repeat name keeps its first position and last value,
a ByteArray body is its raw bytes, an empty payload demotes POST to GET),
called from `Loader.load` and `URLLoader.load`; `avm2_loader_drain` flushes
the queue at the top of each round. `avm2_globals.c` gained
`flash.net.navigateToURL` (was a no-op), `URLVariables.toString` with
`escapeMultiByte`, and a real `URLRequestHeader` constructor with `name`/
`value` slots. AVM1: `action.c` gained `avm1_log_navigate` plus a real
`MovieClip.prototype.getURL`, reporting from both `actionGetURL` and
`actionGetURL2`.

Uncaught errors are a separate commit: `avm2_error.c`'s `print_uncaught`
now traces `coerce_to_string(value)` plus the Error's `__stacktrace_tail`,
and `avm2_function.c` drops the callee frame around parameter coercion.

### What tranche 6 inherits

- Uncaught-error tracing already works, so `loader_error_in_root_ctor`
  (0/4) needs only the child-SWF execution itself.
- `loader_load` will not pass on any amount of Loader work; do not re-file
  it under a later tranche.
