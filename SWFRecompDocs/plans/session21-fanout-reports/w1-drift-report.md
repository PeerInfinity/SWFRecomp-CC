EXPORTER READY @ 0dacba55f

# w1-drift — upstream drift pricing, exporter rebuild, ignore-list re-test (session 21, wave 1)

Every test in this report was run locally with `--mode=graphics --diff --verbose`, one at a time, with
`SWFRECOMP_COMPILE_TIMEOUT=2400`, against the main tree. Most runs were at `263427d08`. Runs after
13:13 local time also include the coordinator's mid-run landings `4077fc4dc`, `a3e7d2858` and
`835d9f539` (see §3). I made no source edits. The logs and the saved actual outputs are in
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/95edbfc6-8c64-421c-a520-00c101a9b3ea/scratchpad/w1-drift/`.

## 0. Exporter

`cargo build --release -p exporter -j 3` succeeded in 20 m 06 s. I changed nothing: our 12 local edits and 3
untracked files compiled against `0dacba55f` unmodified. The new binary is
`~/CC/ruffle/target/release/exporter`, stamped 2026-09-28 12:44.
**Smoke test:** I ran `avm1/removed_clip_function_scope/test.swf` with `-f 4 --trace-log`. The trace is
byte-identical to `output.txt`. That is the right discriminator: this test only passes on a Ruffle that
contains upstream `4b7edd6ad` (scope.rs removed-clip rewrite), which the old binary predates. So the new
binary really does carry the new behaviour.

## 1. Per-test price table: the 9 new and 5 modified upstream tests

| test | local (graphics) | CI row | KF / RTXT | mechanism (owner) | flip price | verdict |
|---|---|---|---|---|---|---|
| `avm1/bitmap_data_draw_return_value` | MISMATCH 3/9 | absent (ungraded) | no | `bitmapDataDraw` returns `undefined` on every non-MovieClip path. It should return 0 on success, -3 for a disposed source and -2 for a non-drawable source (action.c:14567, fall-through `return r` at ~:14600/:14700). Ruffle: `avm1/globals/bitmap_data.rs:507-594` | **+1, cheap** (~15 lines) | **GO** |
| `avm1/bitmap_data_draw_string_target` | MISMATCH 4/40 | absent (ungraded) | no | The same return codes, plus a **string** source must be resolved as a target path from the current target clip (Ruffle `resolve_target_display_object(target_clip_or_root, s)`). Unresolvable → -2. Non-string non-DO → -2. `resolveFlashPathToMC` (action.c:21593) already implements the path grammar | **+1, cheap** (same slot) | **GO** |
| `avm1/goto_rewind_movieclip_replace` | RUFFLE_MATCHED 7/8 | ruffle_matched 7/8 | KF, RTXT | unchanged; already graded | 0 (drift) | — |
| `avm1/removed_clip_function_scope` | MISMATCH 8/12 | output_mismatch 8/12 | no | Upstream `4b7edd6ad` changed Ruffle's rule. When a scope's clip is **removed**, variable lookup substitutes the *current target* (`this` if it is a clip, else the caller's target) and keeps walking. Our GetVariable removed-MC arm (action.c ~:45125-45220, `depth == INT_MIN` → "fall through to root") and the per-call-path base_clip switching implement the OLD rule, and do so inconsistently. We print `global global undefined undefined global` for the three direct/method calls, and `root child root …` (the removed clip's own var still visible) for `readAll.call(undefined)` | **+1, medium** (scope semantics; regression surface = `removed_base_clip_tell_target`, closure / base_clip tests) | **GO** (own slot, oracle = new exporter) |
| `avm2/casi32` | MISMATCH 9/166 | output_mismatch 9/166 | no | `avm2.intrinsics.memory::casi32` (and `mfence`) are not registered, so every call is #1065. Needs `builtin_add_global_fn_ns(ctx,"avm2.intrinsics.memory","casi32",…)` (avm2_globals.c:8219 helper; it already builds the `global/ns::name` frame the expected trace needs). Domain memory comes via avm2_mops.c. #1506 if `(uint)addr > len-4` or `addr % 4`. Otherwise read LE i32, write if equal, return old. Ruffle `core/src/avm2/globals/concurrent.rs` | **+1, cheap** (~40 lines) | **GO** |
| `avm2/date_set_time_out_of_range` | **PASS** | absent (ungraded) | KF, RTXT | we already match Flash where Ruffle fails | 0: **arrives passing = drift, do not book** | — |
| `avm2/gradient_values_readback` | MISMATCH | absent (ungraded) | **KF**, RTXT | Diffed against `output.ruffle.txt` (saved actual) there are 4 mechanisms, all in avm2_filters.c: (a) negative ratios should read back 0 (we give 255); (b) "alphas too few" should keep colors/ratios at full length and pad alphas with 1 (we truncate every array to the shortest); (c) negative/huge `quality` should read back 0 (we give 15); (d) `type = null` should throw `TypeError #2007` from the `set type()` frame inside the ctor (upstream `11624b551`), Gradient**Bevel** and Gradient**Glow**. **A Flash `pass` is unreachable:** Flash keeps `angle: 45`, but four passing tests (`avm2/bevel_filter`, `gradient_glow_filter`, `drop_shadow_filter`, `gradient_bevel_filter`) and `avm1/bitmap_filters` expect the Fixed16-roundtripped `44.999253346524966`. | **+1 effective, as `ruffle_matched`**, cheap-medium | **GO** (target = ruffle_matched, NOT pass) |
| `avm2/textjustifier_locale` | MISMATCH 8/132 | output_mismatch 8/132 | no | Locale validation is missing: `null` → TypeError #2007, `length < 2` → ArgumentError #2004. These throw from a private `setLocale()`, so the stack needs the frames `flash.text.engine::TextJustifier/setLocale()`, `…::TextJustifier()`, `…::SpaceJustifier()`. The frame-push helper `fte_ctor_set` already exists (avm2_text.c:7324). Owner `tj_init` avm2_text.c:6793. Lone surrogates already print `?` like the oracle | **+1, cheap** | **GO** |
| `avm2/textline_has_tabs` | MISMATCH 42/47 | output_mismatch 42/47 | no | `hasTabs` is the constant `tl_const_false` (avm2_text.c:7799). It should be true iff the line's text span (`begin_index`, raw length) contains U+0009 (Ruffle `display_object/text_line.rs has_tabs`) | **+1, cheap** (~15 lines) | **GO** |
| `avm1/mcl_replace_root_swf7_to_swf6` (modified: `output.ruffle.txt` `_name=` → `_name=root movie 6`) | RUFFLE_MATCHED 52/57 | ruffle_matched 52/57 | KF, RTXT, global IGN | Upstream brought `output.ruffle.txt` into line with Flash, and we already print `root movie 6`. The residual is the 5 `rest=` vs `rest=undefined` lines (ACCEPTED_DIFFS) | 0 | — (no change) |
| `fonts/embed_matching/fallback_preferences` (toml `max_outliers = 6`) | trace PASS; image FAIL 24 outliers @ tol 3 | image fail 24 @ tol 3, max_diff 255 | no | tolerance-only change | 0. 24 > 6, so the verdict is unchanged; `excess` goes from 24 to 18 | — |
| `from_shumway/acid/acid-text-5` (toml `max_outliers = 6`) | trace PASS; image FAIL 422 247 | image fail 422 247, image-KF | image KF | tolerance-only change | 0 | — |
| `visual/edittext/edittext_bounds_vs_position` (checks split by `filter = os`) | trace PASS; image PASS 0/0 | image pass, max_diff 0 | no | tolerance-only, and it adds `filter` (see §2) | 0 | — |
| `visual/edittext/edittext_underline_scale2` (adds `os`-filtered check) | trace PASS; image PASS 12 ≤ 16 @ tol 0 | image pass, 12 / max_diff 42 | no | tolerance-only; the macOS-only check is looser | 0 | — |

My local image numbers for the four modified image tests are identical to the CI row values (24,
422 247, 0, 12/42). **Priced trace yield from drift: 6 tests** (`bitmap_data_draw_return_value`,
`bitmap_data_draw_string_target`, `casi32`, `textjustifier_locale`, `textline_has_tabs`,
`removed_clip_function_scope`) plus **1 effective** (`gradient_values_readback` →
ruffle_matched). All 7 are new-test yield, which is legitimate only because we flip them.
`date_set_time_out_of_range` is drift, not yield.

## 2. REFUTATION: our image comparator uses OR semantics, Ruffle uses AND

`ruffle-tests/verify_output.py:483` (`compare_images`) says *"test passes if ANY check passes (Ruffle
semantics)"*. That is **wrong, and has been since multi-check support was introduced.** Ruffle's
`tests/framework/src/runner/image_test.rs:142-181`, and its origin commit `b49538e34` (2025-05-23,
"we want to check that the image has 0 outliers for tolerance 128, **and** 10 outliers for tolerance
5"), return a failure on the **first failing** check. Every applicable check must pass. The typical
upstream pattern (tol 0 / N outliers + tol 144 / 0 outliers) only makes sense as AND. The same
misreading is repeated in `ruffle-tests/tests/swfs/_investigation/HEADLESS_SETUP.md:226` and in the
s14/s15 reports (`w2-gfx-stencil`, `w2-gfx-scrollrect`, `wave1-gfx-displace-blend`). Upstream also has
a per-check `filter` (`os = "macos"`, `arch = "aarch64"`) that we ignore entirely (verify_output.py:262-282).
Under OR, a filtered-out macOS or aarch64 relaxation gets applied on Linux/x86.

**Pricing (pixel axis, negative, honesty fix).** An OR-fail is always an AND-fail, so the fix can only move
pass → fail. From the images run `35423176371` rows (`max_diff`, `diff_channels` = outliers at tol 0):
- **Proven false pass: `from_shumway/acid/acid-clip`.** Its checks are (150/0, 64/140, 0/7000). It passes
  on 150/0, but `diff_channels` = 7033 > 7000 fails the tol-0 check.
- **50 multi-check comparisons that currently pass cannot be decided** from stored stats. Every one needs
  the outlier count at an intermediate tolerance: `acid/acid` ×18, `acid-blend-2` ×5, `acid-video` ×3,
  `acid-small` ×2, `acid-bitmap-fill(-2)`, `acid-bitmapData-draw`, `acid-clip-2`, `acid-color-2`,
  `acid-shapes`, `from_shumway/flash_text_TextField2`, `avm2/graphics_bitmaps`, `stage3d_blend`,
  `stage3d_rotating_cube`, `visual/cache_as_bitmap/masks` ×7, `oversize/swf_{9,10}_masks`,
  `scroll_rect_scaled`, `cache_as_bitmap/text`, `blend_modes/overlay_onto_stage`.
- `filter` support moves nothing today: in all three filtered tomls, under AND, the ignored check is the looser one.
- Trace pass/fail is unaffected (images never gate trace).

**Verdict: GO as a tooling slot, not as yield.** Make `compare_images` require every check to pass,
evaluate `filter` against `os = "linux"` / `arch = "x86_64"` (skip non-matching checks; error if none
remain, as Ruffle does), and record **per-check** outliers in the stats. Then dispatch one
`images=true` run to re-baseline the 413. Expect at least −1 (`acid-clip`) and up to about −50. Book the
drop as a baseline correction and say so in the closeout. The coordinator should decide whether to take
the honest number this session.

## 3. Ignore-list re-test

Every IGN-flagged failing row in `wave0-trace-inventory.txt` has an ignore entry dated before
2026-09-01. `git blame` gives the oldest as 2026-02-10 and the newest as 2026-08-15. So all qualified,
and I re-ran 34 of the 36 once, sequentially. Two I left to their owner, `w1-trace-tail`:
`avm2/simplebutton_childevents_multichild` and `avm2/sound_load_multiple`.

**Result: no hidden wins; 33 of 34 unchanged.** Where the positional diff count disagreed with CI, I
re-ran with `--save-actual` and scored the output with `verify_output.compare_output`. The exact
counts equal CI: `stylesheet_load` 1/49, `global_instance_decls` 26/758, `avm2/avm1_root` 12/58,
`RegisterClassTest4` 7/42 (actual 54), and `argstest-v6/7/8` (actual lines equal CI). The one row that
moved:

- `from_gnash/actionscript.all/array-v5`: output_mismatch 553/560 → **RUFFLE_MATCHED**. This is **not**
  a hidden win. It ran at 13:28:54, after the coordinator landed `835d9f539` (w2-arraysort-m3, 13:27:43),
  and that commit already removed the ignore entry.

Unchanged: `load_vars`, `sandbox_type_remote` (avm1+avm2), `stylesheet_load`, `globals_swf5`,
`native_objects_swf6`, `movieclip_hittest_shapeflag`, `global_instance_decls`, `global_proto_decls`,
`global_proto_decls_delete`, `bitmap_data_thorough/pixelDissolve`, `avm1/date`, `audio_computespectrum`,
`avm1_root`, `bom`, `dependent_strings`, `loader_applicationDomain`, `loader_load`, `netstream_play_flv`,
`netstream_play_stop_replay`, `netstream_seek_flv`, `number_tostring`, `swz`,
`verify_method_info_duplicate`, `eforin_001`, `eforin_002`, `argstest-v6/7/8`, `RegisterClassTest4`,
`matrix_accuracy_test1`, `misc-swfc.all/sound`, `from_shumway/esc`.

**Prune audit.** I checked every entry in every ignore list against the current `results_graphics.json`.
Only one entry is `pass`, `avm2/bytearray_oom`, and it is deliberately kept: it records an upstream
`ignore = true`, as documented at avm2/ignored_tests.txt:209-211. **No prunes to propose.** Two further
entries are `pass` in one suite but must stay under the global-list rule: `netstream_play_flv` (avm1
pass, avm2 fail) and `netstream_play_flv_screen` (image axis). Three unrelated observations:
- `from_shumway/esc` compile took 540 s under load; the result is unchanged.
- `mcl_replace_root_swf7_to_swf6` is still correctly ignored. Upstream changed its `output.ruffle.txt`, but
  the ACCEPTED_DIFFS `rest=` rationale is untouched.
- My `git blame` loop triggered git's background auto-gc once. It is harmless, but siblings may see an
  "Auto packing" notice.

## 4. Wave-2 slots I would fund

1. **w2-drift-avm2-smalls** (+3, cheap, one agent). Register `avm2.intrinsics.memory::{casi32,mfence}`
   (avm2_globals.c + avm2_mops.c), add TextJustifier `setLocale` validation with native frames
   (avm2_text.c `tj_init`), and make `TextLine.hasTabs` real (avm2_text.c:7799). Headlines: `casi32`,
   `textjustifier_locale`, `textline_has_tabs`. Watch for textual overlap with the landed caret work in
   avm2_text.c (it touches different functions).
2. **w2-bitmapdraw-rc** (+2, cheap). `bitmapDataDraw` (action.c:14567): return 0/-2/-3 like Ruffle
   `bitmap_data.rs:507-594`, and resolve string sources via `resolveFlashPathToMC` from the current
   target. Headlines: `bitmap_data_draw_return_value`, `bitmap_data_draw_string_target`. Regression
   check: `avm1/bitmap_data_*`, `avm1/bitmap_filters`.
3. **w2-gradient-readback** (+1 effective → `ruffle_matched`, cheap-medium). avm2_filters.c: clamp
   negative ratios to 0, pad short alphas with 1 without truncating colors/ratios, map quality
   out-of-range to 0, and throw #2007 from `set type()` for Gradient Bevel/Glow. **Do not** touch the
   Fixed16 angle roundtrip: 5 passing tests depend on it. Must not regress `avm2/*_filter` or
   `avm1/bitmap_filters`.
4. **w2-removed-scope** (+1, medium). Port upstream `4b7edd6ad`: when the scope's clip is removed,
   substitute the current target (`this` if it is a clip, else the caller's target) instead of the
   root fallback / skip. Apply it uniformly across CallFunction, CallMethod and `Function.call`.
   Headline: `removed_clip_function_scope`. Must keep `removed_base_clip_tell_target`, `swf5_no_closure`,
   `swf5_to_6_cross_call` and the regression suite green. The exporter is fresh if more oracle cases
   are wanted.
5. **w2-image-and-semantics** (tooling; pixel −1 to about −50, a correction and not yield). Covered in §2.
   Needs one `images=true` CI run after landing.

## 5. New unclaimed leads

- The **image comparator OR/AND bug** (§2) is the big one. Every past pixel flip booked on a
  multi-check comparison (the s14 stencil and scrollrect flips especially) is unverified until the
  re-baseline.
- `from_gnash/misc-swfc.all/sound`: expected 7/7 all match, but we emit 5 extra lines ("TOTAL tests run:
  1, expected: 2" among them). It is an IGN row whose residual is ours-only extra output; re-check the
  ACC rationale against that.
- `avm2/audio_computespectrum` is still all-or-nothing: 478 lines of #1006, one per frame.
