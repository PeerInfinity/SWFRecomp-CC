# Dead-payload skip (`skip_avm1_payload`) — status (2026-09-02)

Brief: `SWFRecompDocs/prompts/avm2-dead-payload-skip-prompt.md`.
Design context: `SWFRecompDocs/plans/avm2-in-browser-assessment.md` §2.1 (what
the data is and who reads it) and §2.2 ("cheap extra win" bullet — this slice;
the payload BLOB is still unbuilt, see "Is the blob still worth it").
Baseline: `68518b088` (the TU-split slice's closeout; CI 33710871686 default /
33710882328 forced-on, both zero-transition, merged at `709b24ab9`).

## What the mode is for

For an **AS3** SWF the AVM1 byte payloads in `RecompiledTags/draws.c` are dead
code. Their only readers are

- `tagInit`'s `defineBitmap(offset, size, w, h, char_id)` and
  `tagDefineSound(app_context, …, sound_data + off, len)`, and
- the AVM1 frame bodies' `tagSoundStreamBlock(app_context, sound_data + off, …)`
  and `tagVideoFrame(app_context, …, video_data + off, …)` in `tagMain.c`,

and an AS3 build (`SWF_AVM2`) enters through `runSWF_avm2`, which calls neither
`tagInit` nor `tagMain` (`wasm_wrappers/main.c` — `swfStart`, the only caller of
both, is in the `#else` arm). AVM2 carries its OWN copies of the same bytes in
`RecompiledABC/abc_timeline.c` (`bmp_N_rgba`, `snd_N_bytes`, `bin_N_bytes`),
read through `avm2_generated_bitmaps/_sounds/_binaries`, and those are
untouched here — `abc_timeline.c` is byte-identical in both modes.

For the original Seedling that dead payload was **138.7 MB of the 142.1 MB
`draws.c`** and **20.7 MB of the 22.0 MB `draws.o`**, i.e. two thirds of the
whole generated C and two thirds of the static data.

The recompiler option is `skip_avm1_payload`, a boolean:

- toml: `[input] skip_avm1_payload = true` (what `docs/recompiler/pipeline.js`
  now writes for every in-browser recompile, and what the runnable-zip
  bundle's `config.toml` therefore carries);
- env: `SWF_SKIP_AVM1_PAYLOAD=1` forces it on regardless of the toml — how
  `verify_output.py` and CI force it across a corpus run;
- workflow: `ruffle-tests.yml` input `skip_avm1_payload`, exported as
  `SWF_SKIP_AVM1_PAYLOAD` for the whole job.

**Default is off, it is additionally gated on `is_as3`, and at off the emitted
C is byte-identical to before the option existed — for AVM1 and AS3 SWFs
alike** (see "Verification" 1).

## Design as landed

### Which arrays

Only the three with no AVM2 reader. Checked, not assumed — every `draws.c`
array against `SWFModernRuntime/src/avm2/`:

| Array | AVM2 refs | Kept? |
|---|---|---|
| `shape_data`, `transform_data`, `color_data`, `gradient_data`, `cxform_data`, `uninv_mat_data`, `morph_end_shape_data`, `morph_end_color_data` | 4–37 each | **kept** (render walk, CPU raster, hit test) |
| `glyph_data`, `text_data`, `text_char_codes`, `path_data` | 0 direct, but they are AVM1-shared text/hit-test tables and are small | **kept** — out of scope, no measurable win |
| `bitmap_data` | 0 (the 32 hits are `ext->bitmap_data`, an unrelated struct field) | **dropped** |
| `sound_data` | 0 | **dropped** |
| `video_data` | 0 anywhere in the runtime — there is no AVM2 video path at all | **dropped** |

§2.1's table omitted `morph_end_shape_data` from the "read by AVM2" list; it
is read (8 references), and it is kept.

### How the two halves stay consistent

`SWFRecomp/src/swf.cpp`, with `Config::skip_avm1_payload` →
`Context::skip_avm1_payload` → `SWF::skip_avm1_payload` (the same three-hop
plumbing `try_helper` and `tu_split` use).

- `SWF::dropPayload()` = `skip_avm1_payload && is_as3`.
- **The bytes** never accumulate: every `bitmap_data << …` /
  `sound_data << …` / `video_data << …` write goes through
  `payloadSink(stream)`, which returns a `std::ostream` over a `NullStreamBuf`
  (`overflow`/`xsputn` discard) when dropping. So the 84 MB of bitmap hex is
  not built inside the recompiler either — Seedling's recompiler peak RSS
  falls 0.32 → 0.11 GiB, which matters because the recompiler is itself a
  wasm32 process in the page.
- **The references** are skipped in lockstep: each of the five `defineBitmap`
  sites, `tagDefineSound`, `tagSoundStreamBlock` and `tagVideoFrame` is
  wrapped in `if (emitPayloadRef())`. So `tagInit` does not become
  reachable-but-wrong — it stays valid C that simply defines no bitmaps and no
  sounds, and the frame bodies stay valid C with no stream/video blocks.
  Nothing is `#if`-ed out and no consumer is deleted.
- **The arrays are still defined**, in exactly the one-element empty form an
  SWF with none of that content already produces
  (`u8 bitmap_data[1] = {\n\t0\n};`, and `extern u8 bitmap_data[1];` in
  `draws.h`). That is what keeps every other TU linking unchanged:
  `wasm_wrappers/main.c` still does
  `app_context.bitmap_data = (char*)bitmap_data; … = sizeof(bitmap_data)` and
  `guest_main_graphics.c` still exports `get_bitmap_data[_size]`. Nothing on
  the AVM2 path reads either (`build_static_bitmap_pools` bails at
  `ctx->current_bitmap == 0`, and only `defineBitmap` — i.e. `tagInit` —
  increments that), so the value they now see is a 1-byte array and a size of
  1 instead of 14 MB and 14 MB.
- `finalizeBitmaps()` is likewise not emitted (it is gated on the emitted
  pixel count, now 0).

**The `avm1_payload_kept` latch.** The reference sites decide during tag
parsing; the array sizes are decided at the end of `parseAllTags`. The one way
those two could disagree is a `FileAttributes` tag arriving AFTER a payload
tag — illegal for SWF 8+ (it must be first) but nothing in the parser enforces
it — which would emit `defineBitmap` calls before `is_as3` was known and then
drop the bytes underneath them. `emitPayloadRef()` and `payloadSink()` latch
`avm1_payload_kept` whenever they DO emit, and the final
`drop_payload = dropPayload() && !avm1_payload_kept` falls back to full
emission in that case. Cost of the fallback: no saving for such a SWF; cost of
not having it: a movie whose offsets point past the end of a 1-byte array.

### What was deliberately NOT done

The payload **blob** (§2.2 proper): `draws_payload.bin` / `abc_payload.bin`,
offsets in the tables and `avm2_payload_relocate(base)`. Out of scope per the
brief, and this slice's measurements change the case for it — see the last
section.

Nothing in the runtime changed. No `#ifdef` was added to any consumer, and
`tagInit` is emitted for an AS3 SWF exactly as before minus those calls.

## Verification

**1. Default emission byte-identical (option OFF).** Recompiled a 19-test
mixed set — `avm1/{try_catch_finally, math_swf8, stylesheet, sound_start_stop,
bitmap_data_colortransform, netstream_play_flv_screen}`,
`visual/video/colorconversion/vp6` (an AVM1 SWF with `video_data`),
`avm2/{try_catch, hello_world, loader_events, stage_displayobject_properties,
sound_play, soundmixer_stopall, stage3d_raytrace}`,
`visual/{bitmapdata_copypixels_with_alpha_oob, cache_as_bitmap/cab_mask_alpha}`,
`from_shumway/{avm2/flash/display/bitmapdata/bitmapdata-clone,
acid/acid-bitmap-fill-2}`, `from_avmplus/ecma3/Array/e15_4_1` — plus
`loader_events`'s `loadable.swf` under `symbol_prefix = "loadable_"`, with the
reverted (pre-change) binary and again with the new one
(`git diff -- SWFRecomp > p.patch; git apply -R p.patch`, rebuild, recompile,
restore, rebuild, recompile, `diff -r`; NOT `git stash`, which is shared across
this repo's worktrees). **No difference** across `RecompiledScripts`,
`RecompiledTags` and `RecompiledABC`. The baseline binary was also run with
`SWF_SKIP_AVM1_PAYLOAD=1` set, to confirm the env var is inert before the
option exists.

**2. `gcc -fsyntax-only -Wall -Werror=return-type -std=c17`** over every
generated `.c` of that set in both modes — **187 files each, zero errors**, and
the identical set of pre-existing `-Wmissing-braces` warnings on `draws.c` in
both. `verify_output.py` compiles generated C with `-w`, so this is the only
local thing that would see a malformed declaration.

**3. Native, option forced ON across the corpus.** `ruffle-tests.yml`,
`mode=graphics`, `categories=full`, `skip_avm1_payload=1` — see the CI section
below. The corpus DOES exercise the path: **74 AS3 SWFs carry an AVM1 payload**
(47 `avm2`, 14 `visual`, 13 `from_shumway`; scanner:
`tools/scan_swf.py`), including every `avm2/sound*` trace test
(`DefineSound`, 8–20 KB) and the `visual/` bitmap image-comparison tests
(`DefineBitsLossless2`), up to `avm2/away3d_advanced_shallow_water_demo`
(645 KB of JPEG) and `from_shumway/acid/acid-blend` (955 KB). One AS3 CHILD
SWF has one too (`from_shumway/as3-loader/events/loader-events/child.swf`).
No AS3 SWF in the corpus has `SoundStreamBlock` or `VideoFrame`, so those two
emission sites are exercised only by the AVM1 half of the byte-identity check
above and by the games.

**4. Sizes and timings, measured** (this box, `gcc -O1 -w -c draws.c` with the
`verify_output.py` include set; `/usr/bin/time -v` for peak RSS):

| | Seedling (orig, 7.8 MB SWF) | | Robot Wants Puppy (536088) | |
|---|---|---|---|---|
| | **off** | **on** | **off** | **on** |
| `draws.c` | 142,071,958 B | **3,362,856 B** | 25,657,021 B | **306,487 B** |
| `draws.o` (-O1) | 21,988,656 B | **1,259,184 B** | 3,899,856 B | **129,424 B** |
| total generated C | 190.7 MB | **52.0 MB** | 41.0 MB | **15.7 MB** |
| `gcc -O1 -c draws.c` | 69.9 s | **1.2 s** | 10.7 s | **0.1 s** |
| gcc peak RSS | 2.28 GiB | **0.05 GiB** | 0.47 GiB | **0.02 GiB** |
| recompile wall | 6.7 s | 5.0 s | 1.2 s | 1.5 s |
| recompiler peak RSS | 0.32 GiB | **0.11 GiB** | 0.06 GiB | 0.03 GiB |

§2.2 predicted −120 MB of C, −20.7 MB static and −83 s: measured **−138.7 MB**
of `draws.c` (−138.7 MB of the total C), **−20.73 MB** static, **−68.7 s**
(the 83 s figure was from a more loaded box; the same 2.4 GiB → 0.05 GiB gcc
peak holds). `abc_timeline.c` is byte-identical in both modes, i.e. the AVM2
copies of those same bytes are all still there.

**5. In the page** (`docs/recompiler`, Windows Chrome via Playwright from WSL,
snapshot `968e34acb`, `pipeline.js` with `try_helper` + `tu_split = 1500000` +
`skip_avm1_payload`). **Served from a FRESH port (8033) rooted at the repo**,
so the URL is `/docs/recompiler/index.html`: the long-lived `:8010` listener on
this box is `python3 -m http.server -d docs2 8010` (verified via
`readlink /proc/<pid>/cwd` + `ps`), and BOTH `/recompiler/` and
`/docs/recompiler/` 404 on it — check the listener before believing a "still
broken" browser result.

| SWF | Recompile | In-browser compile | Result |
|---|---|---|---|
| **Seedling, original** | 27 C files, **49.74 MB** (was 182.04 MB), 41.0 / 38.1 s (was 52.1 s) | 24 files → **18.51 MB guest in 277.4 s** and, on a second run, **237.4 s** (was 38.28 MB / 414.1 s at `39ad765df`, and 668.8 s before the TU split) | title screen renders as before (480×480, 2 frames @ 30 fps, PLAY button); guest data [64 KB, 20.55 MB) of the 101 MB arena, was [64 KB, 45.3 MB) |
| **Snailiad, original** | 37 C files, **62.33 MB** (was 216.08 MB), 50.3 s | 34 files → **28.35 MB guest in 1646.4 s** (was 51.78 MB / 1717.5 s) | boots and renders as before (800×480, 2 frames @ 24 fps): sky, terrain, title panel |
| `avm2/try_catch` | 14 files, 0.5 s | 11 files → 109.6 KB guest in 12.3 s | traces all 11 lines, **byte-identical to `output.txt`** |
| `avm1/try_catch_finally` (control) | 9 files, 0.5 s | 7 files → 101.5 KB guest in 9.1 s | **119/119 lines, byte-identical to `output.txt`** — the AVM1 path is unaffected with the option on, as designed |

So Seedling's in-browser compile is **1.5–1.7× faster again** on top of the TU
split (668.8 → 414.1 → 277.4/237.4 s, **2.4–2.8× overall**) and its guest module
halves. Snailiad's compile barely moves (1717.5 → 1646.4 s, −4 %) because its
time is dominated by its nineteen method chunks, not by `draws.c` — but its
generated C drops 3.5× and its guest module 1.8×, which is what the zip and the
arena see.

**Peak memory.** Per-process `chrome.exe` working sets sampled every 3 s from
WSL (`tasklist.exe`). The single-process maximum is **not** a usable number on
this box: an unrelated 1.61 GiB renderer of the user's own Chrome sits above
everything the page does, and it was never exceeded during either run — which
is itself the result, since the TU-split slice measured a 2.57 GB process for
Seedling and that process was the 142 MB `draws.c` TU. The honest signal is the
rise in the SUM over all `chrome.exe` processes above its pre-run baseline:
**+1.8 GiB for Seedling** and **+2.0 GiB for Snailiad** (over a ~9.7 GiB
ambient baseline), i.e. the whole page including the host, the renderer and the
GPU process — no longer a single 2.5 GB compile worker.

**6. Bundle path.** Assembled a runnable bundle by hand exactly as
`pipeline.js` zips one (`docs/recompiler/bundle/` runtime snapshot + the
option-on generated C of `avm2/sound_play` + `NAME` + `config.toml` carrying
`skip_avm1_payload = true`) and ran its `build.sh`: **88 TUs, links,
`out/sound_play.wasm` 3.5 MB, 2 m 19 s** with `draws.c` no longer among the
expensive TUs. Served and run in Windows Chrome, it traces **19/19 lines
byte-identical to `output.txt`** — and `sound_play` is a test whose AVM1
`sound_data` this option DROPPED, so the three sounds it plays are coming from
AVM2's own `snd_N_bytes` in `abc_timeline.c`, which is exactly the claim the
whole slice rests on. This is where the −68.7 s / −2.23 GiB gcc figure lands for
a user who downloads the zip for a big title.

## CI

Both runs at `968e34acb`, `mode=graphics`, `categories=full`.

**Default (option off) — run `33716779642`**, conclusion success, results merged.
`scripts/corpus_status_diff.py 968e34acb WORKTREE --per-suite`:

```
=== intersection: 4482 tests (968e34acb -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4122 ->  4122 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4357 ->  4357 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

**Forced ON — run `33716808437`**, `skip_avm1_payload=1`, conclusion success,
all shards green. Compared against the default-emission run at the SAME commit
over the 4482-key intersection (`corpus_status_diff` rules: full histogram,
intersection only, nested `_results` excluded):

```
=== intersection: 4482 tests (968e34acb -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4122 ->  4122 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4357 ->  4357 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

**Zero transitions and an identical histogram** with all 74 payload-carrying AS3
SWFs in the corpus emitted without their `bitmap_data`/`sound_data`. Those
numbers come from the run's `ruffle-test-results` ARTIFACT: a
`skip_avm1_payload` run deliberately publishes NOTHING (guard below), and
`origin/ruffle-test-results` was still at the default run's `f32b2218a`
afterwards — which is the check that the guard held.

The publish guard: `ruffle-tests.yml` picks its result-JSON stem from `mode`
alone, so a forced-on run would force-push its numbers over
`results_graphics.json` and poison the `{STEM}_previous.json` baseline the next
default run diffs against (memory `ci-verify-run-results-clobber`).
`inputs.skip_avm1_payload == ''` now guards both publish steps, alongside
`extra_defines`, `single_test`, `try_helper` and `tu_split` — the third slice in
a row to have to add it. `verify_output.py`'s `.recomp_mode` stamp became
`try_helper=<0|1> tu_split=<n> skip_avm1_payload=<0|1>` so a cached tree from a
different mode regenerates.

**Pages deploy.** `deploy-pages.yml` run `33721194488` at `fc3ffa3db`. (Only
`pipeline.js` is tracked under `docs/recompiler/`; `SWFRecomp.wasm`, `bundle/`
and `host/` are gitignored and rebuilt by the workflow.)

## Is the payload blob still worth it?

**No — not on these numbers.** §2.2's blob (`draws_payload.bin` /
`abc_payload.bin`, offsets in the tables, `avm2_payload_relocate(base)`, the
loader `malloc`ing it above the arena, ~1 developer day) was justified by three
things, and this slice moved all three:

| What the blob was for | Then | Now |
|---|---|---|
| in-browser peak memory (the 142 MB `draws.c` TU alone was 2.54 GB) | 2.5 GB peak process | that TU is gone; no page process exceeded the box's ambient 1.61 GiB, and the whole page's rise is ~1.8 GiB |
| C text round-tripping through the wasmer virtual FS | 182 MB for Seedling, 216 MB for Snailiad | **49.7 MB** and **62.3 MB** |
| zip size / static data | 31 MB static, ~33 MB zip | 10.3 MB static (22.0 → 1.3 MB `draws.o`), and the guest module 38.3 → 18.5 MB |

What the blob would still buy is `abc_timeline.c`: 33 MB of C and 9.4 MB of
static data for Seedling (28.2 MB / 168 bitmaps + 60 sounds for Snailiad), i.e.
now **the largest single generated TU** — but it compiles in 54 s at 1.38 GB in
the browser, which is no longer near any ceiling, and the AVM2 runtime genuinely
reads those bytes, so the blob there is a real relocation mechanism rather than
a deletion. Recommendation: **the arc is complete**; open the blob only if a
specific title turns out to be blocked on the zip size or on the 101 MB arena,
and re-measure first — the numbers that motivated it no longer hold.

## Residuals / notes

- **The option is gated on `is_as3`, not on "will be run under AVM2".** The one
  configuration where those differ is an AS3 SWF loaded as a CHILD by an
  **AVM1** parent: the AVM1 loader calls a child's `init_func` (= its
  `tagInit`) from `action.c`, so with the option on such a child would no
  longer define its bitmaps/sounds on the AVM1 side. No corpus test is in that
  shape (the only AS3 child with a payload, `from_shumway/as3-loader`'s, has an
  AS3 parent), the option is off by default, and the page only ever recompiles
  one SWF at a time. Worth remembering if the mode is ever made a default.
- `BITMAP_COUNT` / `BITMAP_HIGHEST_W|H` in `constants.h` are unchanged: the
  bitmaps are still parsed and counted, only their pixels are not written out.
  Under AVM2 those constants feed a `bitmap_count`-sized index table in
  `render_webgpu_init` (40 bytes per bitmap) and nothing else — the static
  pools are built from `ctx->current_bitmap`, which only `defineBitmap`
  increments.
- Not done here (and not asked for): making the mode the NATIVE default. It is
  a pure win for an AS3 native build too, but "AS3 SWF" and "built with
  `SWF_AVM2`" are decided by different things (the FileAttributes bit vs. the
  presence of `RecompiledABC/`), and the AVM1-parent case above is the seam.
  Flipping it should be its own change with its own corpus run.
