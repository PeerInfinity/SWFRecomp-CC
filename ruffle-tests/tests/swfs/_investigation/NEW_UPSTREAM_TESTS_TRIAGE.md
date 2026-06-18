# New Upstream Tests Triage (2026-06-18)

Tests that exist in the freshly-synced upstream Ruffle checkout
(`download_tests.sh`) but were **not** present in the last CI `results.json`
snapshot, i.e. added upstream after the previous run and not yet tracked in any
planning document. Found by diffing each suite's on-disk test directories
against its committed `_results/results.json`.

## Summary

| Suite | Test | Discoverable? | Status (2026-06-18) | Notes |
|-------|------|---------------|---------------------|-------|
| avm1 | `shared_object` | **No** (no `output.txt`/`test.toml`) | not run | SharedObject persistence + two-run harness — see below |
| avm1 | `shared_object_self_ref` | **No** | not run | same infra gap |
| from_gnash/misc-ming.all | `gotoFrame2Test` | Yes | **PASS** (fixed this session) | self-goto loop fix |
| from_gnash/misc-swfc.all | `gotoFrameFromInterval` | Yes | timeout (`known_failure`) | cross-frame gotoAndPlay-from-callback |
| from_gnash/misc-swfc.all | `gotoFrameFromInterval2` | Yes | output_mismatch (`known_failure`) | cross-frame gotoAndPlay-from-callback |

`__framework__` (in `avm1/`) is the AVM1 test framework helper
(`ClassDefinition.as` / `ArgumentDefinition.as` / `Utils.as`), not a runnable
test — correctly absent from results.

## gotoFrame2Test — FIXED (PASS)

`misc-ming.all/gotoFrame2Test` is **not** a `known_failure`; expected output is
4 `PASSED` lines then halt. We were **timing out** (infinite loop).

Root cause: a **self-goto** — `GotoFrame2 play=1` whose target frame is the
frame whose own DoAction is currently executing (the test does
`gotoAndPlay(_currentframe)` then `Stop()`). `ng_executeGotoCatchUp`
(`swf_core.c`) inline-re-runs `funcs[target]`, which re-queues that same
script, which re-issues the goto → the script FIFO never drains.

Fix (`swf_core.c::ng_executeGotoCatchUp`): when `target == original_frame`,
consume the goto request (clear `goto_from_action` / `manual_next_frame`, keep
`current_frame`) and return **without** replaying tags or re-running
`funcs[target]`. Flash does not re-execute the current frame's actions on a
same-frame goto within the tick; it confirms the playhead and lets `is_playing`
(set by the trailing `Stop()`) decide the next-tick advance. Natural advance
(`current_frame++` when `is_playing`) is preserved for the self-goto-and-play
case (no trailing stop).

Regression check: AVM1 goto battery (`goto_frame_number`, `goto_methods`,
`goto_rewind3`, `issue_9885`, `tell_target`, `execution_order2`, `set_interval`)
7/7 PASS; Gnash misc-ming goto/loop battery 8/9 effective (the lone mismatch,
`action_order/action_execution_order_test5`, is a documented pre-existing
failure and is **byte-identical** with/without this change). `loop_test6` and
`loop_test10` both ruffle_matched.

## gotoFrameFromInterval / gotoFrameFromInterval2 — remaining `known_failure`

Both are `known_failure` (Ruffle itself fails them; they ship `output.ruffle.txt`).
Distinct mechanism from gotoFrame2Test: a **cross-frame** `gotoAndPlay(6)` issued
from a setInterval/onEnterFrame callback (when `_currentframe==2`). We land on
frame 6 correctly ("Entering frame 6"), but then **over-advance to frame 7**
("Entering unreachable frame 7"), so `_root._currentframe` reads 7 instead of 6.

For `gotoFrameFromInterval2`, this over-advance is the *only* diff vs Ruffle
beyond the shared `asOrder` FAILED line (which both Ruffle and we emit). Fixing
the over-advance — making the target frame's `Stop()` win after a callback-driven
`gotoAndPlay` — would promote it to `ruffle_matched`. The fix lives in the
deferred-goto-from-callback path (the most fragile area of the runtime); deferred
to a follow-up with full-suite CI verification.

## shared_object / shared_object_self_ref — SharedObject persistence (infra gap)

Both are SharedObject (Local Shared Object) tests with **no `test.toml` and no
`output.txt`** (upstream too), so they are **invisible to `verify_output.py`
discovery** (`resolve_expected_filename` returns `None`) — they neither run nor
affect the pass rate. Ruffle runs them with a special **two-run** harness:

- Run 1: empty/no `.sol` → executes the "initialize" branch, traces `output1.txt`,
  and `flush()` writes a `.sol` file.
- Run 2: the pre-populated `.sol` (`RuffleTest.sol` / `RuffleTestRef.sol`,
  committed in the test dir) is present → executes the "read back" branch,
  traces `output2.txt`.

Passing them requires, beyond our current stub `SharedObject.getLocal`
(`action.c::builtin_sharedobject_getLocal`, returns a fresh empty object;
`getSize`/`flush` are stubs):

1. A two-run mode in `verify_output.py` (run, compare `output1.txt`, persist the
   `.sol`, re-run with it present, compare `output2.txt`).
2. Real SharedObject persistence backed by AMF0 `.sol` (Local Shared Object)
   serialization, including `getSize()` returning the exact serialized byte count
   (`output1.txt` asserts `size: 279`).
3. Round-tripping Array (with holes / negative indices / string props), Date, XML,
   and nested Objects through AMF0.

This is a sizeable feature with low ROI (2 tests). Left untracked-but-documented;
not added to `ignored_tests.txt` because they are not discovered (adding them
would have no effect and could mislead).
