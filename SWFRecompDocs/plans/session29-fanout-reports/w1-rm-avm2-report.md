# s29 w1-rm-avm2: AVM2 `ruffle_matched` pool + the Date TZ harness

Wave 1, cloud. Branch `fanout/w1-rm-avm2`. Code base `origin/master` = `aa36d43a` (s29 scaffold over baseline code
`bfa47037b`). Corpus downloaded 2026-11-26 at upstream Ruffle master **`b7ff32d93`** (newer than the `31e07df77` in
BRIEFS_COMMON). Categories: `avm2 from_avmplus from_shumway timeline fonts visual mixed_avm` (no `avm1`/`from_gnash`;
see canary note). Graphics mode on lavapipe (`SETUP_STATUS`: apt/Pillow/Dawn OK).

**New files**
- `SWFRecompDocs/plans/session29-fanout-reports/w1-rm-avm2-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w1-rm-avm2-prototype.patch` =
  `git diff origin/master -- SWFModernRuntime SWFRecomp ruffle-tests/verify_output.py ruffle-tests/flash_fixes`.
  It creates 15 NEW files `ruffle-tests/flash_fixes/from_avmplus/ecma3/Date/e15_9_5_{4,10,10_1,10_10,10_11,11,12,12_1,13,15_1,17_1,22_1,28_1,29_1,35_1}/test.toml`
  and appends 15 `fixes.json` entries (`kind: "toml"`). Sources are reverted on the branch; this commit holds only these two files.

## Verdicts (lead)

**GO: prototype = 19 rows `ruffle_matched → pass`, 1 row `pass → output_mismatch` (priced, Flash-ward, flash_fixes
candidate). Frozen-patch sweep, graphics, `--recompile`.**

| # | mechanism (owner, functions touched) | rm → pass | size |
|---|---|---|---|
| D1 | **Per-timestamp DST in AVM2 Date** (`avm2_date.c`: new `c_offset_ms_at`, new `dst_ta`; `ensure_tza`, `local_time`, `utc_time`, `format_zone` (now takes the instant) and its caller `format_date`) **+ harness key `mock_timezone`** (`verify_output.py`: new `get_mock_timezone`; `run_env` build in the per-test run loop) **+ 15 flash_fixes `test.toml` entries** | `from_avmplus/ecma3/Date/e15_9_5_22_1`, `_28_1`, `_29_1`, `_35_1`, `_10_10`, `_10_11` (TZ) and `_4`, `_10`, `_10_1`, `_11`, `_12`, `_12_1`, `_13`, `_15_1`, `_17_1` (TZ + `mock_date_time` = the capture instant printed in the golden) | S |
| P | **Debug line info in stack traces** (`abc_emit.cpp` `emitOp`: DebugFile/DebugLine now emit `avm2_debug_file`/`avm2_debug_line`; `avm2_error.c`: new `debug_frame_of`, `avm2_debug_file`, `avm2_debug_line`, `debug_suffix`; `avm2_callstack_push` zeroes the new fields; `callstack_snapshot` prints `[file:line]`, buf 4096→16384; trailing fields `debug_file`/`debug_line` on `Avm2CallFrame` in `avm2_main.h`) | `avm2/event_handler_exception` | S (not M) |
| O1 | **`super` in a freestanding function resolves against Object** (`avm2_ops.c` `super_class_of`) | `avm2/freestanding_superclass` | S |
| O2 | **A slot that shadows an inherited method does not re-point interface aliases** (`avm2_class.c` `avm2_vtable_add_traits`, override arm alias loop) | `avm2/weird_superinterface_properties` | S |
| L1 | **TextField keeps `scrollV` across `height =`** (clamped to maxScrollV) (`avm2_text.c` `avm2_text_set_height_px`; forward decl of `et_maxscroll`) | `avm2/edittext_getcharboundaries_culling` (300 diff lines → 0) | S |

**Priced loss:** `avm2/try_catch_typed` pass → output_mismatch under P (2 lines: ours prints
`at Test()[Z:\tests\tests\swfs\avm2\try_catch_typed\Test.as:33]` and `at test_fla::MainTimeline/frame1()[test_fla.MainTimeline::frame1:1]`).
Its SWF carries DebugFile/DebugLine, and a getStackTrace in FP prints those suffixes (only the debug player has stack traces at
all). So a suffix-less golden is not FP32 output: **flash_fixes candidate** (ORACLE 1). With that swap, P is +2 (net +1 even
without it). Land P with the swap, or land P alone and take the −1 as the documented honest residual.

Net with everything: **+19 −1**. No hidden moves elsewhere: canary 217/217 PNGs md5-identical, 0 trace/image status
changes; `regression/avm2_*` 58/58 pass; every gate below is all-pass.

**Premise attacks (first-class):**
1. **The brief's "Windows-DST rows stay soft NO-GO" is refuted.** 35_1/10_10/10_11 are not Windows-only quirks we can't
   emulate. The goldens show DST under the *current* US rule in every year (e.g. `Fri Apr 3 17:00:00 GMT-0700 1970`; the
   1970 historical start was Apr 26). glibc gives exactly that from the POSIX rule string `PST8PDT,M3.2.0,M11.1.0`. With
   per-timestamp DST all three pass. `America/Los_Angeles` (historical tzdb) does NOT work: measured 35_1 6, 10_10 62,
   10_11 12 diff lines.
2. **The s28 report's "22_1 passes as-is under TZ=America/Los_Angeles" was a calendar accident.** The old model read ONE
   offset at the REAL wall clock (`ensure_tza` used `time(NULL)`). s28 measured in November (PST). The same override
   run between March and November would print `GMT-0700` everywhere and fail. An override is only deterministic with
   per-timestamp DST (D1).
3. **"setMinutes/setUTCMinutes DST-of-result bug" (28_1/29_1) is not a separate bug.** It is the missing DST term
   (`utc_time` = ES3 `t − LocalTZA − DST(t − LocalTZA)`). D1 fixes both with no setter-specific code.
4. **Nine more Date rows the provenance called "untestable (today-dependent / wall clock)" are testable.** Their goldens
   print the FP32 capture instant (Jul 23 2025, ~21:56–22:03 PDT). Rows like `currentTime+30d` depend on the month
   length of "now", and `12_1` starts at `now + 31 days`. Pinning `mock_date_time` to the printed instant makes them
   pass. Instants used: 1753333006000 (`_4`), 1753333373000 (`_12_1`), 1753333172000 (the rest, from `_10_1`'s printed time).
5. **Bucket P is S, not M, and it is +1 at best today, not +1 free.** Only 2 corpus goldens carry `[file:line]`. Of the 91
   avm2/avmplus/shumway/timeline/mixed goldens with `\tat` lines, exactly 4 SWFs carry DebugFile strings:
   `event_handler_exception` (+1), `coerce_property` (stays rm: residual is FP's real heap address `Object@ca74cb9`;
   ours now differs from FP on that 1 line only, down from 3), `loader_load` (already failing, network), and
   `try_catch_typed` (−1, above).
6. **Found and fixed on the way: `timegm` is undeclared in every runtime build.** The flags are `-std=c17
   -D_POSIX_C_SOURCE=200809L -w`, so the call is implicit-int, the result is truncated to 32 bits and the warning is
   hidden. It was harmless for the old "now" read, but wrong for any pre-1901/post-2038 instant (it printed
   `GMT+1670264235 1905`). D1 uses the file's own §15.9.1 algebra instead. **The AVM1 `date.c` `date_ensure_tza` has the
   same pattern** (lead N1).

## D1 — the Date TZ harness: design decision

- **How Ruffle pins TZ:** `core/src/backend/locale.rs` `DeterministicLocaleBackend::default()` is a FIXED
  `FixedOffset::east(20700)` (+5:45, no DST), used by `tests/framework/src/runner.rs` for EVERY test. There is no
  per-test key upstream, so there is nothing upstream-compatible to reuse.
- **Key:** `mock_timezone = "<POSIX TZ>"` in `test.toml`. It is project-only, exactly like the existing `mock_date_time`
  and `mock_platform`, which no upstream toml uses either. `verify_output.py` puts it in `run_env["TZ"]`. `run_binary`
  applies `extra_env` AFTER `env.setdefault("TZ", "NPT-5:45")`, so it also beats the job-level `TZ: NPT-5:45` that
  `.github/workflows/ruffle-tests.yml` exports on every verify step (checked: lines 351, 691, 716, 738, 764, 790, 816,
  843, 1238). `test_env.json` can still override it. Image-variant rebuilds copy `run_env`, so they get it too.
- **Delivery:** flash_fixes `kind: "toml"`, the same shape as the s28 `place_object_test*` "corpus convention
  mismatch" entries. The golden is untouched; the toml makes our run emulate the FP32 capture host. The STALE guard
  protects it: if upstream edits a test.toml, the fix is not applied and the row falls back to NPT.
- **Runtime model:** LocalTZA = the smaller of the offsets at mock-time −33 d and +148 d (standard time in either
  hemisphere). DST(t) = (offset at t) − LocalTZA. Under NPT (or any zone without DST) this is the old fixed offset,
  bit for bit, and every non-overridden test runs under NPT.
- **Browser/WASM side effect (intended):** Emscripten's `localtime_r` follows the browser's zone, so in-browser AVM2
  `Date` now applies DST per timestamp, as FP does. It used to apply one offset taken at page load.

### D1 measurement (kept binaries re-run under each TZ; diff lines vs golden)

| row | NPT (master == proto) | LA, old fixed model | LA, per-ts DST | POSIX rule, per-ts DST |
|---|---|---|---|---|
| 22_1 | 132 | 0* | 22 | **0** |
| 28_1 | 6 | 6 | 0 | **0** |
| 29_1 | 2 | 2 | 0 | **0** |
| 35_1 | 18 | 6 | 6 | **0** |
| 10_10 | 62 | 52 | 62 | **0** |
| 10_11 | 186 | 66 | 12 | **0** |

\* only because the run date was in November (premise attack 2).

## Bucket O — verifier / interface traits (priced against the ABCs)

- **O1 `freestanding_superclass` (S, prototyped):** method[1] is a `NewFunction` closure with `GetSuper
  AS3::hasOwnProperty`. FP prints the function for all three receivers. We (and Ruffle) raised VerifyError #1035.
  Fix: `super_class_of` returns Object for a function activation (`act->callee != NULL && act->file != NULL`, no bound
  class). The only corpus golden mentioning #1035 is the `error_geterrormessage` message table (unaffected).
- **O2 `weird_superinterface_properties` (S, prototyped):** C extends B (B implements I, method `f`). C declares a
  public SLOT `f`. FP: `c.f` is undefined, but `(c as I).I::f` is still B's method. Our override arm re-pointed every
  alias that shared the old implementation, including the `I::f` alias. Now that happens only when the new trait has
  the same kind (a real override). Accessor merges `continue` before this arm, so only slot↔method replacement changes.
- **New O3 rows `slot_holes_fail` + `slot_id_exceeds_trait_count` (S–M, NOT prototyped, golden ≠ Flash):** avmplus
  `Traits::buildBindings` (core/Traits.cpp ~l.800) rejects a raw slot id > the trait block's own `nameCount` when
  `allowEarlyBinding()` holds, with VerifyError #1107. Both ABCs do this (Subclass: 1 trait, slot_id 2; C: 1 trait,
  slot_id 2). FP32 captures already on master (`session28-fanout-reports/trace-provenance/avm2__slot_*.r1.txt`) print
  `VerifyError: Error #1107…` (+ `ReferenceError: Error #1065: Variable SlotTest is not defined.`). The upstream goldens
  are EMPTY by Ruffle convention. **Completion:** (a) flash_fixes `output.txt` swaps from the r1 captures; (b) a
  load-time check over every class's instance/class traits whose base chain to Object is entirely same-ABC (the safe
  subset of `allowEarlyBinding`). On violation, fail that ABC: print the uncaught #1107, run no script of it, and let
  the document-class lookup raise #1065. That is +2 after (a); without (a) it is 0/−0 (rm either way).

## Bucket P — debug line info: see the verdict table and premise attack 5

Format: the DebugFile string `<dir>;;<file>` prints as `<dir>\<file>`. Frame scripts carry a bare
`test_fla.MainTimeline::frame1`, printed as-is (`coerce_property` golden: `[test_fla.MainTimeline::frame1:3]`, matched
exactly). The setter is guarded: it writes only when the top call frame IS that emitted method (file + method_index),
so a body run without its own frame never relabels its caller. A folded (deduplicated) body with a different
method_index simply prints no suffix. Release SWFs carry no debug ops, so there is no cost there.

## The AVM2 text-layout bucket (re-priced vs FP32)

| row | diff | verdict |
|---|---|---|
| `avm2/edittext_getcharboundaries_culling` | 300 | **L1 → pass** (s28 lead L1 confirmed: FP keeps scrollV across height changes; golden scroll-4 block starts at line 3 for every h) |
| `fonts/device_font_no_ink`, `from_shumway/flash_text_TextField` (5), `avm2/edittext_device_transform_layout` (20), `visual/edittext/edittext_device_transform_metrics` (8), `_negative` (untestable) | — | **soft NO-GO**: device-font metrics come from the capture host's system fonts (flash_fixes README rule 4). Completion: a host-font model, i.e. FP32 captures of the same rows on the CI image's fonts. Not S |
| `from_shumway/flash_text_TextField2` | 9 | soft NO-GO: Windows-FP32 golden (Linux FP32 drops blank lines) |
| `from_shumway/acid/acid-text-x` | 1 | `trace(t.x)` after `autoSize = CENTER`: FP 168 vs our 167.95 (3360 vs 3359 twips). `et_relayout` center arm: `(2*bx + bw − width)/2` in integer twips. One sample cannot tell pixel-rounding of x from a 2-twip width difference. **S once a Flash probe exists** (ORACLE 2) |
| `from_shumway/acid/acid-textfield` | 6 | M: run coalescing after replaceText/appendText/setTextFormat (span model) |
| `avm2/edittext_tab_stops` (6), `edittext_set_text_same_after_edits` (48) | — | M (s28 bucket L unchanged) |

## Bucket M — frame/event lifecycle (re-price only; no code)

Measured diffs (ours vs golden, by content):
- `timeline/swf_9_event_goto_frame_script` (2 = 1 moved line): `gotoAndStop(3)` from the root's ADDED_TO_STAGE handler.
  FP constructs frame 3's child (`MyChild Constructor`) BEFORE running `Main frame3`; we run the script first.
- `timeline/swf_9_frame_script_dynamic_goto` (2 = 1 moved line): `NodeChild frame1` calls `child.gotoAndStop(2)` during
  the frame-script phase. FP runs `LeafChild 2 frame2` at the TAIL OF THE SAME frame-script pass (before the next
  enterFrame); we run it in the next frame's pass (after `Main frame2`).
- `avm2/simplebutton_childevents_script_order` (1 moved line), `timeline/frame_script_button_order` (1 extra
  `MyContainer frame1`): button-state container frame scripts.
- `loader_events_2` (30), `mixed_avm/avm2_loads_avm1_events` (18), `swf_9_goto_in_construct_frame` (12),
  `simplebutton_childevents_multichild` (101), `LoaderTest` (1): loaded-child tick order / SimpleButton state children (s28 verdict stands).

**Smallest separable rule:** "SWF ≤ 9: a goto that lands during a construct or frame-script phase queues the target
frame's script to run after the target frame's children are constructed, within the current phase (appended to the
current frame-script pass)". It covers the two `swf_9_*` rows (+2, S–M). Owner: the AVM2 goto / frame-script queue
(`avm2_display.c` timeline goto, `swf.c` frame loop). Gate: every `timeline/` + `avm2/goto_*` + `swf_9_*` row. The
button rows and the loader rows are separate mechanisms (M).

## Buckets left as s28 priced them (no new evidence)

N (typed nulls L; sort64 waits on its flash-fix), R (platform: `Number/cos`, `html_text_img_parsing`,
`soundchannel_*`, `uncaught_errors_stringified`), S (`displayobjectcontainer_stopallmovieclips_nonconstructed`: FP crash).
`avm2/error_1034_debug_string`: the golden is debug-player #1034 value spelling (`<Fri Feb 27 03:04:05 GMT+0100 2009>@ADDRESS`,
`[]@ADDRESS`, `MC{…}`, …) across 19 lines, plus a CET host zone. M (debug-player value stringification), not a TZ row. A
`mock_timezone = "CET-1CEST,M3.5.0,M10.5.0/3"` would fix only its Date line.

## Measurement (graphics, frozen patch, `--recompile`)

| leg | result |
|---|---|
| 15 Date rows | 15 pass (before: 15 rm) |
| `event_handler_exception`, `freestanding_superclass`, `weird_superinterface_properties`, `edittext_getcharboundaries_culling` | 4 pass (before: 4 rm) |
| `try_catch_typed` | output_mismatch (before: pass); 2 lines, Flash-ward |
| `coerce_property`, `slot_holes_fail`, `slot_id_exceeds_trait_count`, `error_1034_debug_string`, acid-text-x, acid-textfield, flash_text_TextField, flash_text_TextField2 | rm (= before); `loader_load` fail (= before) |
| D1 gate: 23 other `ecma3/Date` rows (e15_9_1_1_1, 2_1, 3_1_1, 3_2_1, 3_8_1, 4_2, 4_3, 5_2, 5_3, 5_5, 5_6, 5_7, 5_42, 5_10_3, 5_21_1, 5_23_1, 5_23_3_rt, 5_24_1, 5_26_1, 5_30_1, 5_34_1, 5_36_1, 5_37_1) + `avm2/date`, `date_parse`, `date_set_time_out_of_range`, `amf_invalid_date` | 27/27 pass |
| O1 gate: 15 avm2 super rows (class_supercalls_*, constructsuper_null, super_get_call, supercalls_coerce, supercalls_weird, superinterface_*, …) | 14 pass + weird_superinterface (rm then) |
| O2 gate: 17 `as3/Definitions/{Interfaces,Super}` + 8 avm2 interface/slot rows | 25/25 pass |
| L1 gate: 19 avm2 edittext autosize/scroll/getcharboundaries/height rows | 19/19 pass |
| `regression/avm2_*` | 58/58 pass |
| render canary (195 tests, 217 PNGs, `before` = clean master, `after` = patch, both `--recompile`) | **217 IDENTICAL**, 0 differs, 0 trace/image status changes |

The canary's 20 avm1/gnash/text members were NO_RESULT in BOTH legs: those categories were not downloaded. The patch has
no AVM1 code (D1 is `avm2_date.c` only), so this hides nothing.
Not run: no-graphics (no `NO_GRAPHICS`/`swf_core.c` code touched). CI for landing: **`categories=full`** (AVM2 runtime +
recompiler emission), graphics.

## RvF entries to add (coordinator; append at EOF of RUFFLE_VS_FLASH_DIFFERENCES.md)

1. **s29 w1-rm-avm2 Date capture host.** 15 avmplus `ecma3/Date` goldens are FP32 output on a US-Pacific Windows host
   (current US DST rule for every year), captured 2025-07-23 ~22:00 PDT. Ruffle's runner pins +5:45, no DST, which
   Ruffle uses for every test. We emulate the capture host per test (`mock_timezone`, `mock_date_time`) through
   flash_fixes toml entries.
2. Freestanding-function `super` (`freestanding_superclass`): FP resolves against Object; Ruffle VerifyError #1035.
3. Interface aliases are not re-pointed by a shadowing slot (`weird_superinterface_properties`; Ruffle's own FIXME in
   `vtable.rs` `copy_interface_properties`).
4. `scrollV` survives a TextField height change (`edittext_getcharboundaries_culling`); Ruffle's `relayout` resets it.
5. FP debug-player `[file:line]` stack-frame suffixes (`event_handler_exception`, `coerce_property`); Ruffle prints none.

## New unclaimed leads

- **N1 (S, AVM1):** `actionmodern/date.c` `date_ensure_tza` uses the same implicit-int `timegm` and the same
  real-wall-clock fixed offset. Port D1's model (it is a no-op under NPT). AVM1 TZ-golden rows such as
  `avm1/global_instance_decls` (GMT+0200) could then take a `mock_timezone` too. Sibling w1-rm-avm1-gnash's territory.
- **N2 (S–M, +2 after flash-fix):** O3 slot-id verifier (above).
- **N3 (S–M, +2):** SWF9 goto frame-script queue rule (bucket M).
- **N4 (S once probed):** autoSize CENTER x rounding (`acid-text-x`).
- **N5:** other `from_avmplus` rows may print the 2025 capture instant or PDT dates and currently pass by luck or are
  listed "untestable". `grep -l 'GMT-0[78]00 2025' from_avmplus/**/output.txt` is the sweep. Only the 15 above were in
  the rm list.

## LOCAL ORACLE REQUESTS

1. **FLASH: `avm2/try_catch_typed`, trace, direct (debug projector).** Expect `\tat Test()[Z:\tests\tests\swfs\avm2\try_catch_typed\Test.as:33]`
   and `\tat test_fla::MainTimeline/frame1()[test_fla.MainTimeline::frame1:1]`. If FP32 prints that (or any suffix),
   add a flash_fixes `output.txt` swap. P then flips the row back to pass (if our line numbers agree).
2. **FLASH: `from_shumway/acid/acid-text-x` variant probe (needs a local AS3 build):** a TextField with
   `autoSize = CENTER` over widths 100..110 px × texts of 1..5 chars, `trace(t.x, t.width)`. Decides N4.
3. **FLASH (confirmation, optional): `from_avmplus/ecma3/Date/e15_9_5_35_1`, trace, LINUX projector run with host
   `TZ=PST8PDT,M3.2.0,M11.1.0`.** Expect == golden, which would prove the golden is reproducible on Linux FP32 under this
   exact host config. Not blocking: the 15 goldens are already FP32 (s28 provenance).
4. Flash-fix candidates with captures ALREADY on master (no new run needed): `avm2/slot_holes_fail`,
   `avm2/slot_id_exceeds_trait_count` → `output.txt` = `session28-fanout-reports/trace-provenance/avm2__slot_*.r1.txt`.
