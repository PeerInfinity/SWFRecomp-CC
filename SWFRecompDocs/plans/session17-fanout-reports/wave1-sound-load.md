# s17 wave-1 — `Sound.loadSound` family (agent `w1-sound-load`)

Diagnosis of record for the AVM1 `Sound.loadSound` arc: the 7 new upstream
`avm1/sound_load_*` / `sound_mixed_attach_load` rows that first appeared in the
s16 closeout run `31877239992`, plus the three `from_gnash/actionscript.all/
Sound-v6/-v7/-v8` rows that moved `ruffle_matched` → `output_mismatch` on the
same run.

Baseline: `88ebde665` (results `c7b284034`), grading run `31877239992`
(graphics / categories=full). Trace baseline 4317/4453 effective.

**No new files in the wave-2 patch.** Everything lands in
`SWFModernRuntime/src/actionmodern/action.c`.

---

## 1. Verdict table (priced)

| # | Row | Baseline status | Mechanism | Verdict | Flip |
|---|-----|-----------------|-----------|---------|------|
| 1 | `avm1/sound_load_props` | `output_mismatch` (15 diff lines / 121) | **A** (ExternalSound transform) | **GO — high confidence** | +1 |
| 2 | `from_gnash/actionscript.all/Sound-v6` | `output_mismatch` (was RM) | **A6** (`getBytesLoaded/Total`) | **GO — proven by subset arithmetic** | +1 |
| 3 | `from_gnash/actionscript.all/Sound-v7` | `output_mismatch` (was RM) | **A6** | **GO** | +1 |
| 4 | `from_gnash/actionscript.all/Sound-v8` | `output_mismatch` (was RM) | **A6** | **GO** | +1 |
| 5 | `avm1/sound_load_start_remote` | `output_mismatch` (0 lines emitted) | **B** (async remote load) + A | **GO** | +1 |
| 6 | `avm1/sound_load_streaming_stop_remote` | `output_mismatch` | **B** + A4 | **GO** | +1 |
| 7 | `avm1/sound_load_multiple_remote` | `output_mismatch` | **B** + A4 + A5 | **GO** | +1 |
| 8 | `avm1/sound_load_multiple_instances` | `pass` | — | **PROTECT** | 0 |
| 9 | `avm1/sound_mixed_attach_load` | `pass` | — | **PROTECT** | 0 |
| 10 | `avm1/sound_load_stops_when_dereferenced` | `pass` (empty `output.txt`) | — | **PROTECT** | 0 |

**Floor +4 · real +7 · ceiling +7.**

- Floor (+4) = rows 1–4. Row 1's 15 diff lines were traced individually against
  Ruffle's `Sound`/`ExternalSound` source and every one is explained by the same
  mechanism; rows 2–4's flip was *computed exactly* (§4.2) — the non-subset diff
  set is `{105, 106}` and nothing else.
- Real (+7) = also rows 5–7. Every expected line of all three `_remote` tests is
  accounted for by the model in §5, but they are the only rows that need new
  async plumbing, so they carry integration risk our other rows do not.
- Ceiling is also +7: the family has exactly ten rows and three already pass.
- No pixel-axis component. No row is in `ignored_tests.txt`, `ACCEPTED_DIFFS.md`,
  `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, or
  `FLASH_BUGS_REPLICATED.md`.

---

## 2. Mechanism

There is **one shared mechanism plus one add-on**, not ten per-row fixes.

### Mechanism A — adopt Ruffle's `ExternalSound` record

`~/CC/ruffle` (master `1508316`) `core/src/avm1/globals/sound.rs` defines a
per-`Sound` `external: Option<ExternalSound>` that is `Some` from the moment
`loadSound(url)` is called with *any* first argument. Its comment is the whole
model:

> This is `Some` when this sound has had `loadSound()` called on it, and
> therefore enters a state of being "separated" from its original owner (even
> if it was controlling global sound initially), and can then only ever control
> externally loaded sounds.

The record holds `{is_streaming, will_autoplay, transform, is_loading,
load_id}`; Ruffle's accessors then read:

- `sound_transform()` → **external transform first**, then global, then owner.
- `owner()` → `None` whenever `is_external()`.
- `has_valid_owner()` → `use_global || is_external || owner.is_some()`.

We have exactly the same three-way router already, in
`resolveSoundTransformTarget` (`action.c:1666`) — it just lacks the external
arm. Sub-mechanisms:

| | What | Ruffle site |
|---|---|---|
| **A1** | private transform object, default 100/0/identity, created by every `loadSound(<arg>)`, checked *before* global/owner | `Sound::sound_transform`, `ExternalSound::empty` |
| **A2** | `has_valid_owner` true when external | `sound.rs:246` |
| **A3** | `owner()` → NULL when external | `sound.rs:225` |
| **A4** | `will_autoplay` (= `is_streaming` at creation), cleared by `stop()` | `sound.rs:868` |
| **A5** | `load_id` + `is_loading`: a second `loadSound` while one is in flight fires `onLoad(false)` **synchronously inside the second call**, then bumps `load_id`; the stale completion is dropped by the id check | `sound.rs:596-617`, `loader.rs:1425-1432` |
| **A6** | `getBytesLoaded()`/`getBytesTotal()` return a **number** once loaded | `loader.rs` + `sound.rs:510-526` |

A alone flips rows 1–4.

### Mechanism B — asynchronous load for non-`file` URLs

`load_sound` in `sound.rs:626-647` is explicit:

```rust
// Local files are loaded synchronously on the FP desktop projector;
// that is, execution is paused until the load has completed.
let is_blocking = navigator.resolve_url(&request_url).scheme() == "file";
if is_blocking { load_sound_avm1_blocking(...); return; }
... navigator.spawn_future(load_sound_avm1(...))
```

**Our current synchronous `loadSound` is therefore already correct for every
relative/local URL** — that is precisely why `sound_load_start`,
`sound_start_load`, `sound_multiple_load`, `sound_id3`,
`sound_duration_position_props` pass today. The only thing missing is the
`http://` arm: `loadSound` must return immediately and fire
`onID3`/`onLoad`/autoplay **after the current script**. Whichever way we defer,
the arrival order relative to the frame is unobservable in these three tests
(they only assert ordering against traces in the same script), so the cheapest
faithful option is the proven `XML.load` pattern: an `AQ_KIND_SCRIPT` queue
entry (see `aq_dispatch_xml_load`, `action.c:19614`), which drains right after
the in-progress frame script.

B also needs **B1: URL → data-file resolution**. Ruffle's test navigator maps
`http://<host>/<path>` to `<test_dir>/<host>/<path>`, and `verify_output.py`'s
`find_data_files` keys the registry by that *relative* path
(`verify_output.py:1871-1909`). Our `builtin_sound_loadSound` strips to the
bare basename, so `http://localhost:8000/noise.mp3` misses the entry that is
registered as `localhost/noise.mp3`. `avm1_amf.c:1672 nc_resolve_response` is
the ready-made resolver for exactly this (strip scheme, drop `:port`, try
`host/path`, then bare basename); copy it as a `static` helper in `action.c`
rather than exporting it.

---

## 3. Row 1 — `sound_load_props` (local, no network, no audio)

`test.toml`: `num_ticks = 1`, Rascal-compiled, SWF 15. No mp3 ships; the only
URL used is the deliberately-missing `"invalid.mp3"`. **This row needs no
decoder, no network, and no timing** — it is pure Sound-object state.

Measured diff (`--mode=graphics --diff`, scratch `--tests-dir`), 121 expected
lines, 15 differ, in exactly two clusters:

```
  // s_mc.loadSound("invalid.mp3")
  // s_mc.getVolume()
-  100      +  200
  // s_mc.getPan()
-  0        +  50
     rl: 0 / rr: 100 / lr: 0
-    ll: 100  +  ll: 50
...
  // s_mc2.getVolume()
-  50       +  1
-  90       +  97          (getPan)
-  rl:40 rr:30 lr:20 ll:10  +  rl:6 rr:5 lr:4 ll:3
  // s_mc.getVolume()  (final)
-  1        +  10
-  97       +  87
-  rl:6 rr:5 lr:4 ll:3      +  rl:16 rr:15 lr:14 ll:13
```

Both clusters are A1:

1. **`loadSound("invalid.mp3")` resets the observable transform to
   100 / 0 / {ll:100, lr:0, rl:0, rr:100}** — because the Sound stops reporting
   its owner clip's transform and starts reporting a fresh private one.
2. **Two `Sound` objects targeting the same clip stop sharing state once one of
   them has loaded.** `s_mc2` (never loaded) keeps reading the clip's
   `50 / 90 / {10,20,30,40}`; `s_mc`'s post-load `setVolume(1)/setPan(-2)/
   setTransform({3,4,5,6})` land on its private record and are invisible to
   `s_mc2`, and vice-versa. Our implementation stores the transform on the
   clip's `dynamic_props`, so today they alias.

Two behaviours the expected output pins that the patch must honour:

- `loadSound()` **with no argument at all** must be a complete no-op (Ruffle
  gates on `args.get(0)`); the trace right after it still shows the clip's
  `50 / 90 / {10,20,30,40}`.
- `loadSound("")` **does** create the external record (empty string is still an
  argument). Proof: after `loadSound("")` the script does
  `setVolume(200)/setPan(50)`, and the later `s_mc2` trace still reads the
  clip's original `50 / 90 / {10,20,30,40}` — so those writes did **not** reach
  the clip. Whether `""` also *resets* is unobservable (the following `setPan`
  overwrites all four channels); do what Ruffle does and always reset.
- The `has_valid_owner` gate still runs first: the very first
  `s_mc.loadSound("invalid.mp3")` happens before `createEmptyMovieClip("mc",1)`
  and must create nothing (the trace right after is three `undefined`s). Our
  existing `if (!soundHasValidOwner(...)) return;` already does this.

All 15 lines are accounted for. Verified against Ruffle's `set_pan`
(`ll = 100-pan, rr = 100, lr = rl = 0` for `pan >= 0`) and `get_pan`
(`ll != 100 ? 100-|ll| : |rr|-100`), both of which we already implement
identically — the only defect is *which object* they read and write.

---

## 4. Rows 2–4 — `from_gnash/actionscript.all/Sound-v{6,7,8}`

### 4.1 What actually drifted

The three test SWFs are **byte-identical** to our mirror; `output.txt` is
identical; only `test.toml` (`+with_audio = true`, inert for us) and
`output.ruffle.txt` changed. So **our own output did not change** — upstream
Ruffle got better and our `ruffle_matched` (= "our diff-line indices ⊆ Ruffle's
diff-line indices vs `output.txt`", `verify_output.py:3346`) lost its subset.

Old vs new Ruffle actual: Ruffle's `loadSound("sound1.mp3")` now completes
(blocking local load), so `onLoad` fires *inside* `loadSound`, the
`typeof(getPosition()/duration/getDuration()) == "number"` checks at
`Sound.as:347-349` now pass, `onSoundComplete` arrives, and the Dejagnu totals
go `84/24/108` → `92/20/112`.

### 4.2 Our position — computed exactly

`Sound-v6` actual captured with `--save-actual` and run through
`verify_output.ruffle_subset_match` against the *new* oracle:

```
ours   diff indices: [43, 57, 103, 105, 106, 113, 118, 119]
ruffle diff indices: [41,42,43, 55,56,57, 81..92, 97,98, 103, 113, 118, 119]
subset? False
ours-not-in-ruffle: [105, 106]
  105 | PASSED: typeof(s.getBytesTotal())  == "number" [./Sound.as:345]
  106 | PASSED: typeof(s.getBytesLoaded()) == "number" [./Sound.as:346]
```

**Two lines. That is the entire gap for three tests.** Our actual is already
*ahead* of Ruffle everywhere else (we run 112/112 tests with 106 passes; Ruffle
gets 92). Our remaining `output.txt` failures are:

| idx | line | ours | ruffle | in ruffle's set? |
|-----|------|------|--------|------------------|
| 43 / 57 | `typeof(sN.checkPolicyFile) == 'boolean'` | `undefined` | `undefined` | yes |
| 103 | `s.duration == 209` | `1000` | `0` | yes |
| **105 / 106** | `typeof(s.getBytes{Total,Loaded}()) == "number"` | **`undefined`** | `1` | **NO** |
| 113 | `s.position == 209` | `1000` | `0` | yes |
| 118 / 119 | `#passed` / `#failed` | 106 / 6 | 92 / 20 | yes |

`Sound-v7` and `Sound-v8` differ from `v6` only in the first line (`SWF7`/`SWF8`)
in both `output.txt` and `output.ruffle.txt`, so one fix covers all three.

### 4.3 The fix (A6)

`action.c:37339-37340` currently installs `getBytesLoaded`/`getBytesTotal` as
`addStubMethodToProto` (→ `undefined`). Replace with natives that return
`undefined` unless the Sound has been externally loaded, and the loaded byte
count otherwise. Ruffle just returns `1` unconditionally (`sound.rs:510-526`,
`avm1_stub!`) and therefore *fails* the six pre-load `== 'undefined'` checks at
`Sound.as:110/111/177/178/336/337` that **we currently pass** — so gate on
`__loaded__`/external and keep those six passes. Either shape yields a subset;
the gated one is strictly better and matches Flash.

### 4.4 Two optional free-riders (worth +4 `output.txt` lines and a *full pass*)

Not needed for the flip (`ruffle_matched` already counts as effective pass), but
each is ~10 lines and together they take all three rows from `ruffle_matched` to
a real `pass`, which is immune to the next upstream oracle rewrite:

- **`s.duration == 209`.** `sound1.mp3` is **MPEG-2** Layer III (836 bytes,
  32 kbps → `836*8/32000 = 209 ms` exactly). Our estimator
  (`action.c:2276-2305`) only tables MPEG-1 Layer II/III and falls back to
  `1000.0` for everything else. Adding the MPEG-2/2.5 Layer III table
  (`{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160}`) flips idx 103 **and** idx
  113 (`position == duration` after completion). **Zero blast radius on avm1**:
  every mp3 under `avm1/` is MPEG-1 Layer III (checked all 11) — only the four
  gnash fixtures are MPEG-2/2.5, so this must be A/B'd against `Sound-v5..v8`
  alone. Caveat: it also changes `silence.mp3` from 1000 ms to ~23 s, which
  could move an `onSoundComplete` we currently get for free — A/B it as its own
  leg.
- **`checkPolicyFile`.** A `boolean` own property on every `Sound` instance
  (Flash has it; Ruffle does not). Must be `PROPERTY_FLAGS_DONTENUM`:
  `avm1/sound_props_swf6`'s expected output has *nothing* between
  `Enumerated` and `Enumerated prototype`.

With A6 + both free-riders the diff set becomes empty and `#passed: 112 /
#failed: 0` matches Flash → `pass` on all three.

---

## 5. Rows 5–7 — the three `_remote` tests

All three are Rascal-compiled SWF 15, **1 frame, 24 fps**, `use_network = true`,
`num_ticks = 100`/`150`/`150`, and each ships `localhost/noise.mp3` (4180 B,
MPEG-1 L3 32 kbps → **1045 ms**, i.e. ~25 frames — a 6.25 s tick budget at 150
ticks, ample). Our runtime already ticks 1-frame movies for the full
`MAX_FRAMES` while running the script exactly once (this is how
`sound_load_start` gets three `onSoundComplete`s in 100 ticks), so **no timing
headroom problem exists.**

Current actual: `sound_load_start_remote` emits **nothing at all**;
`streaming_stop_remote` emits `before/after`; `multiple_remote` emits
`loading sound / loading again / after loading again`. Cause is single and
mundane — `builtin_sound_loadSound` does `findDataFile("noise.mp3")`, the
registry key is `localhost/noise.mp3`, so it returns `NULL` and the function
returns before firing anything (B1).

Line-by-line model (mechanisms in brackets):

**`sound_load_start_remote`** — expected `onLoad true` (one line).
`loadSound(url)` [B: defer]; `setVolume(50)` [A1: private]; `start()` twice →
no-op because nothing is loaded yet (our `builtin_sound_start` already returns
when `__duration__ <= 0`; Ruffle warns "No sound is attached"). Drain →
`onLoad(true)`. `will_autoplay = is_streaming = false` → no playback, so
`onSoundComplete` never fires and the `i<1` re-`start()` never runs. ✔

**`sound_load_streaming_stop_remote`** — expected `before / after / onLoad true`.
`loadSound(url, true)` [B] creates external with `will_autoplay = true` [A4];
`stop()` clears it [A4]. Drain → `onLoad(true)`, no autoplay. **This row is the
proof that `onLoad` must be deferred**: a synchronous `onLoad` would print
`before / onLoad true / after`. ✔

**`sound_load_multiple_remote`** — expected
`loading sound / loading again / onLoad false / after loading again / onLoad true / Sound complete`.
The `onLoad false` sitting *between* two traces of the same script is the whole
point: it is emitted **synchronously inside the second `loadSound`** because the
first load is still `is_loading` [A5]. Then `load_id` 0→1, the first deferred
completion is dropped by the id check, the second fires `onLoad(true)`; the
handler calls `start(0, 9)` (loops ignored for streaming, Ruffle forces 1) and
`will_autoplay` re-starts it; ~25 frames later `onSoundComplete` → `Sound
complete`. ✔

**Premise attacked and refuted: these do NOT need real HTTP.** The `README.md`
in each test asks a *human* to run `python -m http.server`; Ruffle's own CI
serves them from the `localhost/` directory through its test navigator, and our
harness bundles that directory into `data_registry.c` under the identical key.
No socket, no clock, no wall-time. Nothing in the three expected outputs
depends on *when* the load lands, only on *after the current script*.

**Premise attacked: MP3 decode is not required.** Nothing in the family decodes
samples — `duration` comes from the CBR frame-header estimate we already have,
`audio_assertions` are not graded by `verify_output.py` (image/audio assertions
never gate trace pass/fail), and `minimp3` is only used by the real audio
output path. The one decode-adjacent gap is the MPEG-2 bitrate table (§4.4).

---

## 6. Patch scope for wave 2

Single file: `SWFModernRuntime/src/actionmodern/action.c`. **No new files, no
new headers** (a new `.h` would also have to be added to `verify_output.py`'s
explicit source list at `:2154`).

| Site | Line (baseline) | Change | ~LOC |
|------|------------------|--------|------|
| `soundHasValidOwner` | 1655 | `if (soundIsExternal(obj)) return 1;` [A2] | 2 |
| `resolveSoundTransformTarget` | 1666 | external arm **first**, before the `soundUsesGlobal` arm [A1] | 6 |
| `resolveSoundOwner` | 1597 | return NULL when external [A3] (fidelity; not required by any graded row — land it behind its own A/B) | 3 |
| `builtin_sound_loadSound` | 2197 | create/replace the external record (transform defaults + `is_streaming`/`will_autoplay`/`is_loading`/`load_id`); fire `onLoad(false)` when a load is already in flight [A5]; store `__bytes_total__` [A6]; branch to the deferred path for scheme'd URLs [B] | 70 |
| **new** `sound_resolve_url_data()` | near 2190 | copy of `avm1_amf.c:1672 nc_resolve_response` as `static` [B1] | 25 |
| **new** `aq_dispatch_sound_load()` | near 2190 | `load_id` check → duration/id3/`__loaded__` → `onID3` → `onLoad(success)` → autoplay if `will_autoplay`; mirrors `loader.rs:1410-1462` and the `aq_dispatch_xml_load` retain/free discipline | 60 |
| `builtin_sound_stop` | 2429 | clear `will_autoplay` [A4] | 3 |
| Sound prototype init | 37339 | real `getBytesLoaded`/`getBytesTotal` natives replacing the two `addStubMethodToProto` calls [A6] | 30 |
| *(optional)* duration estimator | 2276 | MPEG-2/2.5 Layer III bitrate table | 10 |
| *(optional)* Sound constructor | ~1706 | `checkPolicyFile = false`, DONTENUM | 5 |

**Total ~200 lines, one TU.**

Implementation traps:

1. **Create the external record OUTSIDE the `#ifdef HAS_DATA_FILES` block.**
   Everything from the data lookup to the callbacks in `builtin_sound_loadSound`
   is currently inside that guard (`action.c:2242-2386`). `sound_load_props`
   happens to define `HAS_DATA_FILES` (its `test.as` counts as a data file —
   `find_data_files` deliberately does not skip `test.as`), but a Sound test with
   *no* sibling files would silently lose the whole mechanism.
2. **Keep local/relative URLs synchronous.** Making them async breaks
   `sound_load_start` (needs `start()` to see a loaded sound in the same script)
   and `sound_duration_position_props`. Route on "has a scheme that isn't
   `file`", matching `sound.rs:631-637`.
3. `checkPolicyFile` must be DONT_ENUM (`sound_props_swf6`).
4. Grade against a **fresh** upstream mirror. Our local
   `from_gnash/.../Sound-v{6,7,8}/output.ruffle.txt` is the **stale** oracle and
   will report a false `ruffle_matched`; the 7 new `avm1/sound_*` dirs are
   absent locally altogether. A ready sparse checkout of upstream master
   (`1508316`) is at
   `<scratchpad>/w1sound/ruffle-new/tests/tests/swfs/`; the seven avm1 dirs are
   already staged at `<scratchpad>/w1sound/tsuite/` and Sound-v6/v7 at
   `<scratchpad>/w1sound/gsuite/`. `cp -r` into the worktree's canonical suite
   paths and pass `--recompile` on first use. (These mirrors are gitignored, so
   nothing needs committing and CI re-downloads the fresh copies anyway.)

### Tests to grade (headline)

`avm1/sound_load_props`, `avm1/sound_load_start_remote`,
`avm1/sound_load_streaming_stop_remote`, `avm1/sound_load_multiple_remote`,
`from_gnash/actionscript.all/Sound-v6`, `-v7`, `-v8`.

### Canaries (all currently passing; the standing render canary is blind to this change class)

1. `avm1/sound_load_start` — sync local load + `start()` + 3× `onSoundComplete`.
   The single best guard against accidentally making local loads async.
2. `avm1/sound_multiple_load` — two sequential `loadSound`s on one Sound
   (guards A5's `onLoad(false)` from firing on the *local* path).
3. `avm1/sound_duration_position_props` — `onID3`/`onLoad`/`onSoundComplete`
   ordering, `duration`/`position` props, streaming local autoplay.
4. `avm1/sound_id3` — `new Sound(_root)` + `onID3` before `onLoad` (guards A3).
5. `avm1/sound_props_swf6` (+ `sound_props_swf5`) — prototype/instance
   enumeration; the only guard on the `checkPolicyFile` DONT_ENUM trap.
6. `avm1/sound_getters`, `sound_setters`, `sound_gettransform_props`,
   `sound_owner_reference` — transform routing for Sounds that never load
   (guards the A1 reorder).
7. `from_gnash/actionscript.all/Sound-v5` — currently `ruffle_matched`;
   `[ruffle-matched-trap]` applies, it must not drop.
8. The three protected new rows: `sound_load_multiple_instances`,
   `sound_mixed_attach_load`, `sound_load_stops_when_dereferenced`.

### Suggested leg split

- **Leg A** (A1–A3, A6): flips `sound_load_props` + `Sound-v6/-v7/-v8` = **+4**,
  no async plumbing, ~50 LOC. Land first and grade alone.
- **Leg B** (B, B1, A4, A5): flips the three `_remote` rows = **+3**, ~150 LOC.
- **Leg C** (optional): MPEG-2 duration table + `checkPolicyFile` → converts the
  three gnash rows from `ruffle_matched` to `pass` (+0 effective, +4 line
  metric, drift-proof). A/B separately — the duration change also moves
  `silence.mp3` from 1000 ms to ~23 s.

---

## 7. Refutations / premises attacked

- **"The family may need real HTTP timing — possibly unpassable."** Refuted.
  Ruffle's own harness serves these from a directory; our `data_registry.c`
  already embeds it under the identical `localhost/noise.mp3` key
  (`verify_output.py:1871`). The blocker is a basename-only lookup, not a
  network model.
- **"The gnash rows need `loadSound` async/streaming work."** Refuted, and it
  is nearly the opposite: the upstream drift is Ruffle *adopting* the
  synchronous blocking local load we already had. Our gnash actual is ahead of
  Ruffle's on 14 checks; the gap is two `getBytes*` lines.
- **"`Sound-v6/-v7/-v8` regressed."** Refuted — the SWFs and `output.txt` are
  byte-identical to our mirror; only the oracle moved. Pure upstream drift, per
  s16 §17.3's own prediction.
- **"`ruffle_matched` means we reproduce Ruffle's output."** Refuted — it is a
  *subset over diff-line indices* vs `output.txt` (`verify_output.py:3346`).
  Reasoning from the old `output.ruffle.txt` as if it were our actual output
  would have mis-priced this whole leg; the `--save-actual` capture was what
  reduced "8 mismatching lines" to "2".
- **"`loadSound` resets the owner clip's sound transform."** Refuted by
  `sound_load_props`'s `s_mc2` traces — the clip keeps its values; it is the
  *Sound* that stops looking at the clip.
- **"MP3 decode presence gates this arc."** Refuted for the trace axis; only the
  CBR header estimate matters, and only for the optional §4.4 leg.
- **Residual risk on rows 5–7 (why they are "real", not "floor"):** they are the
  only rows requiring new queue plumbing. If the `AQ_KIND_SCRIPT` drain turns
  out to run at a different point than `XML.load`'s comment claims, the fix is
  to move the dispatch to the `g_pending_mcl_loads_next_tick` style bucket
  (`action.c:35322`) — the trace expectations are satisfied by any deferral of
  ≥ 1 script boundary, so this is a knob, not a blocker.

## 8. Completion mechanism for the one HOLD

Leg C's MPEG-2 duration change is **HOLD, not GO**: it is worth 0 effective
points and carries a real (if small) chance of moving an `onSoundComplete` that
currently lands for free on `silence.mp3`/`stereo8.mp3`. It flips to GO if a
wave-2 A/B shows `Sound-v5..v8` unchanged or improved with the table applied in
isolation.
