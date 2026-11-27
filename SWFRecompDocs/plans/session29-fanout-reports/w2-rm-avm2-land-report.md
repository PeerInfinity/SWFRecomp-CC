# s29 w2-rm-avm2-land: land w1-rm-avm2 (D1, P, O1, O2, L1) + 3 trace flash_fixes

Wave 2, cloud. Branch `fanout/w2-rm-avm2-land`. Code base `origin/master` = `bbae2ffc7` (docs-only over the s29
baseline code). Corpus downloaded 2026-11-26/27 (categories `avm2 from_avmplus from_shumway visual fonts text avm1
from_gnash`); `download_tests.sh` does not record the upstream SHA, `git ls-remote` right after gave Ruffle master
**`952362ecf`**. `SETUP_STATUS`: apt/Pillow/Dawn OK; graphics on lavapipe.

**New files**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-rm-avm2-land-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-rm-avm2-land.patch` =
  `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/flash_fixes`
  (proved with `git apply --check -R` on the committed tree). It creates these NEW files:
  - `ruffle-tests/flash_fixes/from_avmplus/ecma3/Date/e15_9_5_{4,10,10_1,10_10,10_11,11,12,12_1,13,15_1,17_1,22_1,28_1,29_1,35_1}/test.toml` (15, from the w1 prototype, unchanged)
  - `ruffle-tests/flash_fixes/avm2/try_catch_typed/output.txt` (= `w1-local-oracles/w1-rm-avm2/try_catch_typed.fp32.txt`)
  - `ruffle-tests/flash_fixes/avm2/slot_holes_fail/output.txt`, `…/slot_id_exceeds_trait_count/output.txt` (= `session28-fanout-reports/trace-provenance/avm2__slot_*.r1.txt`)
- Committed on the branch but NOT in the patch (append-only doc, would conflict with sibling appends): the RvF section
  "AVM2 rm pool landed: …" at EOF of `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`.
  Take it with `git show fanout/w2-rm-avm2-land -- ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`.
  No new `.c`/`.h` files.

## Verdict (lead)

**GO. 19 rows `ruffle_matched → pass` + `try_catch_typed` stays pass (now graded against FP32), both modes, 0 other
moves.** Render canary 260/260 PNGs md5-identical, 0 trace/image status changes; regression `avm2_*` 58/58 trace pass.

Changes vs the w1 prototype (everything else is the prototype byte for byte):
1. **P path join fixed to avmplus's rule** (`avm2_error.c` `debug_suffix`). The prototype mapped `;;` → `\` always.
   avmplus `core/StackTrace.cpp` `StackTrace::dumpFilename`: the separator is `\` if the DebugFile string holds ANY
   backslash, else `/`; every `;` becomes that separator unless the previous output char was already a separator. So
   `Z:\…\try_catch_typed;;Test.as` → `Z:\…\try_catch_typed\Test.as` (unchanged result) and swz's Mac-compiled
   `/Users/haydencurtis/…/swz;;Test.as` → `/Users/haydencurtis/…/swz/Test.as`, which is exactly FP32's line. The
   prototype would have printed `…/swz\Test.as`, costing the `swz` interaction a line.
2. **`mock_timezone` made fail-safe** (`verify_output.py`: `get_mock_timezone` + module constants `_TZ_NAME`, `_TZ_OFF`,
   `_TZ_DATE`, `_TZ_RULE`, `_POSIX_TZ_RE`; the run-loop block that reads it in `main`). glibc silently runs a malformed
   TZ as UTC (`TZ=Bogus` → `('Bogus','Bogus')`, offset 0, measured). Now a present key must be a double-quoted
   well-formed POSIX TZ string; anything else (single quotes, unquoted, empty, `America/Los_Angeles`, `Bogus`) books the
   row `runtime_error` with detail `invalid mock_timezone: …` and does not run it. Measured: `e15_9_5_35_1` with
   `mock_timezone = "Bogus"` → `RUNTIME_ERROR (invalid mock_timezone: mock_timezone 'Bogus' is not a POSIX TZ rule string)`.
3. **3 trace flash_fixes** (`fixes.json` entries + `README.md` table rows; upstream sha256 computed from my fresh
   download, `apply_flash_fixes.py` → APPLIED, `--check` → ALREADY 82): `avm2/try_catch_typed`, `avm2/slot_holes_fail`,
   `avm2/slot_id_exceeds_trait_count`. The 15 toml entries from w1 also APPLIED (not STALE) on this download, so their
   sha256s hold. `fixes.json` was re-merged over master's 64 entries (master gained the s29 LOW entries after w1);
   written with `indent=2` (byte-identical re-serialisation of master's part, checked).

## Per-test before/after (same box, `--recompile`; before = clean `origin/master` code with the flash_fixes applied)

| test | before G | before NG | after G | after NG |
|---|---|---|---|---|
| `from_avmplus/ecma3/Date/e15_9_5_4` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_10` | pass† | pass† | pass | pass |
| `…/e15_9_5_10_1` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_10_10` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_10_11` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_11` | pass† | pass† | pass | pass |
| `…/e15_9_5_12` | pass† | pass† | pass | pass |
| `…/e15_9_5_12_1` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_13` | pass† | pass† | pass | pass |
| `…/e15_9_5_15_1` | pass† | pass† | pass | pass |
| `…/e15_9_5_17_1` | pass† | pass† | pass | pass |
| `…/e15_9_5_22_1` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_28_1` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_29_1` | rm | rm | **pass** | **pass** |
| `…/e15_9_5_35_1` (`known_failure`) | rm | rm | **pass** | **pass** |
| `avm2/event_handler_exception` | rm | rm | **pass** | **pass** |
| `avm2/freestanding_superclass` | rm | rm | **pass** | **pass** |
| `avm2/weird_superinterface_properties` | rm | rm | **pass** | **pass** |
| `avm2/edittext_getcharboundaries_culling` | rm | rm | **pass** | **pass** |
| `avm2/try_catch_typed` (FP32 golden) | output_mismatch | output_mismatch | pass | pass |
| `avm2/slot_holes_fail` (FP32 golden) | rm | rm | rm | rm |
| `avm2/slot_id_exceeds_trait_count` (FP32 golden) | rm | rm | rm | rm |
| `avm2/coerce_property` | rm | rm | rm | rm |
| `avm2/swz` | output_mismatch | output_mismatch | output_mismatch | output_mismatch |

† These 6 pass in the before leg only because the flash_fixes toml (applied by the download) already carries
`mock_date_time`, which master's harness honours. On the CI baseline (no toml) all 15 Date rows are `ruffle_matched`
(`s29-baseline-trace-rm.txt`, checked by name). So the CI move for all 15 is rm → pass; 6 of them come from the toml's
`mock_date_time` alone, 9 need D1 + `mock_timezone`.

## mock_timezone on CI (brief item 2): proved

- Every CI verify step (`ruffle-tests.yml` lines 351, 691, 716, 738, 764, 790, 816, 843, 1238) exports `TZ: NPT-5:45`
  and runs `verify_output.py` (the per-shard parallelism is separate jobs, each a plain `verify_output.py` run; the
  "Combine shard results" step only merges JSON). There is no other runner path: `run_binary` is the only executor of
  `test_run`, called from the main loop (with `run_env`) and from `_rerun_subtest_variants` (with a copy of `run_env`).
  The main loop sets `run_env["TZ"]` from the key; `run_binary` applies `extra_env` AFTER `env.setdefault("TZ",
  "NPT-5:45")` and over the inherited `os.environ`, so the key beats the job-level TZ. Mode-independent (no `--mode`
  branch on this path). `--wasm` builds `continue` before the run step (no runtime to set).
- Proved: `TZ=NPT-5:45 verify_output.py --test=ecma3/Date/e15_9_5_35_1` (no-graphics, the CI env) → PASS. All 15 Date
  rows pass in no-graphics (table above).
- The keys arrive on CI because `download_tests.sh` runs `apply_flash_fixes.py` for the categories it downloads
  (from_avmplus is one). A STALE upstream toml falls back to NPT and the row shows up as rm again (named, not silent).

## Interaction with sibling w2-disposition-land (`avm2/swz`) — measured, not just predicted

I applied `w1-disposition-audit-prototype.patch` (its runtime files only) ON TOP of my tree, swapped in the FP32 swz
golden (`trace-provenance/avm2__swz.r1.txt`), ran graphics, then reverted both (tree re-verified == my patch). Both
patches apply together cleanly (hunks separable: theirs adds `avm2_error_callstack_tail`, mine edits
`callstack_snapshot` / `debug_suffix`). Result: **2 of 3 lines match**, swz stays output_mismatch:

```
     1  Error #2044: Unhandled securityError:. text=Error #2046: The loaded file did not have a valid signature.
-    2  	at Test()[/Users/haydencurtis/Desktop/rust/ruffle/tests/tests/swfs/avm2/swz/Test.as:12]
+    2  	at Test()[/Users/haydencurtis/Desktop/rust/ruffle/tests/tests/swfs/avm2/swz/Test.as:16]
     3  	at test_fla::MainTimeline/frame1()[test_fla.MainTimeline::frame1:3]
```

The path is now right (fix 1 above). The residual is the line: Test.as:12 is `new URLLoader()`, :16 is `load()`. The
sibling snapshots the stack at `load()`; FP reports the stack captured at the dispatcher's construction (their own
lead L2). **Completion (S, sibling side):** snapshot the call stack in the URLLoader constructor and keep it on the
loader for the unhandled-error report. With that, swz passes vs its FP32 flash_fix. **Ledger prediction for both
landed: `swz` stays output_mismatch (1 line).**

## EXPECTED-FLIP LEDGER (CI graphics `categories=full`, and no-graphics)

Trace axis, vs the s29 baseline (`45878805896` G / `45878818309` NG):
- **rm → pass (19), both modes:** `from_avmplus/ecma3/Date/e15_9_5_4`, `e15_9_5_10`, `e15_9_5_10_1`, `e15_9_5_10_10`,
  `e15_9_5_10_11`, `e15_9_5_11`, `e15_9_5_12`, `e15_9_5_12_1`, `e15_9_5_13`, `e15_9_5_15_1`, `e15_9_5_17_1`,
  `e15_9_5_22_1`, `e15_9_5_28_1`, `e15_9_5_29_1`, `e15_9_5_35_1`; `avm2/event_handler_exception`,
  `avm2/freestanding_superclass`, `avm2/weird_superinterface_properties`, `avm2/edittext_getcharboundaries_culling`.
- **pass → pass with a swapped golden:** `avm2/try_catch_typed`. Land the swap and P together: either one alone makes
  it pass → output_mismatch (measured: master code vs the FP32 golden = mismatch; w1 measured P vs the old golden = mismatch).
- **stay rm, golden swapped to FP32:** `avm2/slot_holes_fail`, `avm2/slot_id_exceeds_trait_count`.
- **unchanged:** `avm2/coerce_property` (rm), `avm2/swz` (mm; see the interaction, 1 line short even with the sibling).
- Nothing else. The 23 other `ecma3/Date` rows + `avm2/date*`/`amf_invalid_date` are re-measured pass.

Pixel axis: **0 moves** (canary 260/260 identical; the code touches no render path).

## Gates (graphics, final code, `--recompile`)

| gate | result |
|---|---|
| headline 24 rows | table above; graphics == no-graphics row for row |
| `regression/avm2_*` (58) | 58/58 trace pass. Image: `avm2_layer_group_alpha` 2815 / `avm2_layer_group_erase` 2702 outliers FAIL = the s29 pixel baseline exactly (`s29-baseline-pixel-failing.txt`), not moved |
| D1 gate: 23 other `from_avmplus/ecma3/Date` rows + `avm2/date`, `date_parse`, `date_set_time_out_of_range`, `amf_invalid_date` | 27/27 pass |
| render canary (195 tests, 260 PNGs; before = clean master, after = patch, both `--recompile`) | **260 IDENTICAL**, 0 DIFFERS/APPEARED/VANISHED, 0 trace and 0 image status changes |

Honest note: `debug_suffix` (fix 1) was edited while the canary AFTER leg was running, so that leg's later tests built
the new `debug_suffix`, earlier ones the prototype's. The function only runs for frames that executed a DebugFile op,
and the edit changes output only for a path with no backslash or a single `;`; no canary member moved either way. The
4 P rows (`try_catch_typed`, `event_handler_exception`, `coerce_property`, `swz`) were re-run on the final code in both
modes (pass/pass/rm/mm). The O1/O2/L1 gates from w1 (15 super, 25 interface/slot, 19 edittext rows) were not re-run:
that code is the w1 frozen patch byte for byte and master changed only `avm2_bitmap.c` since (covered by the canary).

## Functions touched (all files)

- `SWFModernRuntime/src/avm2/avm2_date.c`: new `c_offset_ms_at`, new `dst_ta`; `ensure_tza`, `local_time`,
  `utc_time`, `format_zone` (now takes the instant), `format_date`.
- `SWFModernRuntime/src/avm2/avm2_error.c`: new `debug_frame_of`, `avm2_debug_file`, `avm2_debug_line`,
  `debug_suffix` (rewritten per avmplus here); `avm2_callstack_push` (zeroes the new fields); `callstack_snapshot`
  (prints the suffix; buffer 4096 → 16384). Not touched: `avm2_error_callstack_tail` (sibling's).
- `SWFModernRuntime/include/avm2/avm2_error.h` (decls), `avm2_main.h` (trailing `debug_file`/`debug_line` on
  `Avm2CallFrame`).
- `SWFModernRuntime/src/avm2/avm2_ops.c`: `super_class_of`. `avm2_class.c`: `avm2_vtable_add_traits` (override-arm
  alias loop). `avm2_text.c`: `avm2_text_set_height_px` (+ forward decl of `et_maxscroll`).
- `SWFRecomp/src/abc/abc_emit.cpp`: `emitOp` DebugFile/DebugLine arms emit `avm2_debug_file`/`avm2_debug_line`.
- `ruffle-tests/verify_output.py`: new `get_mock_timezone` + `_TZ_*`/`_POSIX_TZ_RE`; `main` per-test run loop
  (`run_env` build).
- None of `tag.c`, `action.c`, `ng_shared.c`, `swf.c`, `swf_core.c`, `tag_stubs.c`, `render_webgpu.c`, `timer.c`.

## Item 4 — regression fixture for P: none (corpus covers nesting)

`try_catch_typed` grades two nested AS frames from different DebugFile sources (`Test.as:33` callee under
`frame1:1` caller) with a native frame (`getDefinitionByName`, no suffix) on top; `event_handler_exception` grades the
event-dispatch path. The `/` join is graded by `swz` once the sibling's securityError path lands. No AS3 compiler in the
cloud to build a deeper debug SWF anyway; not worth a Flash request.

## O3 (slot-id VerifyError #1107) — priced, NOT landed (HOLD, S–M, +2)

With the FP32 goldens now swapped in, `slot_holes_fail` and `slot_id_exceeds_trait_count` need: a load-time check in
class/trait setup (the `avm2_class.c` `avm2_vtable_add_traits` slot arm, around `slot_id = t->slot_or_disp_id`, is
where a raw id > the trait block's own count is visible), but only under avmplus `allowEarlyBinding` (base chain to
Object entirely same-ABC); on violation the WHOLE ABC must fail before any script init, print the uncaught
`VerifyError: Error #1107: …` + blank line, and the document-class lookup must then raise `ReferenceError #1065`
(`slot_id_exceeds_trait_count` only). That is ABC-level failure semantics we do not have today, so not S.
**Completion mechanism:** a pre-init verifier pass over every class's instance/class traits in the ABC loader, plus an
"ABC failed" state that skips its scripts and leaves its classes undefined.

## New unclaimed leads

- **L-swz (S, sibling w2-disposition-land):** URLLoader unhandled-error stack = stack at construction (above). +1 (`swz`).
- **N1 (S, AVM1, from w1):** `actionmodern/date.c` `date_ensure_tza` has the same implicit-int `timegm` + real-wall-clock
  offset; port D1.
- **N5 (from w1):** sweep other `from_avmplus` goldens printing `GMT-0[78]00 2025` for more capture-host rows.

## LOCAL ORACLE REQUESTS

None.
