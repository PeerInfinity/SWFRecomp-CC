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
| from_gnash/misc-swfc.all | `gotoFrameFromInterval` | Yes | timeout (`known_failure`) | Ruffle is wrong (runaway) — not pursued |
| from_gnash/misc-swfc.all | `gotoFrameFromInterval2` | Yes | **ruffle_matched** (fixed) | timer-callback gotoAndPlay over-advance fixed |

## CI does not yet grade the three new Gnash tests (pre-existing enumeration gap)

CI run `27767514089` (no-graphics, my fix) confirmed **zero regressions** across
all 8 suites, but its graded counts still show `misc-ming.all` total **110** and
`misc-swfc.all` total **19** — i.e. `gotoFrame2Test`, `gotoFrameFromInterval`, and
`gotoFrameFromInterval2` are **absent from CI results entirely**, before *and*
after my change. These tests have been in upstream master since 2026-05-16
(commit `8e2852107`), so several past CI runs never graded them either.

This is NOT caused by my change and NOT a recompiler failure: CI's "Download
Ruffle test SWFs" installs all 404 gnash tests, CI's "Run recompiler" step
reports 0 failures, `run_tests.py` recompiles all 111 misc-ming tests locally
(111/111), and `verify_output.discover_tests` finds 111 locally (incl.
gotoFrame2Test). The gap is in how the **sharded run** enumerates/consumes the
uploaded recompiled-test-data artifact — the shards' graded set omits these
dirs. Diagnosing the artifact flow (Setup upload → shard download →
`verify_output --shard`) is a separate CI-infrastructure follow-up; it must not
destabilize the working pipeline. **Consequence:** `gotoFrame2Test`'s
timeout→PASS fix is verified locally and produces no CI regression, but is not
yet reflected in CI pass counts until the enumeration gap is closed.

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

## gotoFrameFromInterval2 — FIXED (ruffle_matched)

Both interval tests are `known_failure` (Ruffle itself fails them; they ship
`output.ruffle.txt`). Mechanism: a **cross-frame** `gotoAndPlay(6)` issued from a
`setInterval` callback (`func_16`, fired in `processTimers`) when `_currentframe==2`.

We were landing on frame 6 ("Entering frame 6") but then **over-advancing to
frame 7** ("Entering unreachable frame 7"), so `_root._currentframe` read 7
instead of 6 — the *only* diff vs Ruffle beyond the shared `asOrder` FAILED line.

Root cause (confirmed by instrumentation): the bare `gotoAndPlay(6)` dispatches
through the MovieClip-nav path (`action.c` `_is_mc_nav` arm, root target):
`actionGotoFrame(5)` runs `ng_executeGotoCatchUp`, which **drain-suppresses** the
target frame's queued DoAction (`script_3`, which calls `Stop()`), then
`is_playing = 1` (play flag). When the goto comes from a *frame script*, the
caller's SHOW_FRAME drain runs `script_3` same-tick and its `Stop()` wins. But
from a *timer callback* there is no enclosing drain, so `script_3` stays queued;
the main loop's natural advance then sees `is_playing == 1` and moves cf 5→6
**before** `Stop()` ever runs (it drains a tick late, when cf is already 6).

Fix (`swf_core.c`, after `processTimers`/onLoad/MCL drains, before the advance):
drain any orphaned pending ONLOAD/SCRIPT queue entries
(`actionActionQueuePending() > 0` → `actionDrainAllInPriorityOrder`). `g_aq_count`
is normally 0 here (frame funcs drain at SHOW_FRAME), so it is a no-op on the
common path; it only fires for scripts a timer/event-callback goto orphaned.
`script_3`'s `Stop()` now settles `is_playing=0` before the advance → no
over-advance, `_root._currentframe == 6`. Promotes the test to `ruffle_matched`
(remaining diff = the shared `asOrder` FAILED line, ⊆ Ruffle's diff).

CI side-effect (benign, no pass-rate impact): three pre-existing
`output_mismatch` *runaway* tests in misc-ming.all (`ActionOrderTest3`,
`ActionOrderTest4`, `RegisterClassTest4`) emit +11 `actual_lines` each — the
drain runs their timer-queued scripts one extra round per tick, so each loops
slightly further before terminating. `matching_lines` is **unchanged** (4/62,
9/64, 3/42), status stays `output_mismatch`, effective pass unchanged, no new
timeouts. CI run `27773253214`: zero pass→fail regressions across all 8 suites.

## gotoFrameFromInterval — Ruffle is wrong (not pursued)

`gotoFrameFromInterval` (no "2") is a different test that *legitimately* reaches
"frame7". Flash (`output.txt`) cleanly terminates: 3 tests, `#passed: 3`. **Ruffle
itself is buggy here** — its `output.ruffle.txt` is a runaway: `_root.asOrder`
grows unboundedly (`x0xx1xx2…x89…`), it reports 10 tests instead of 3, and output
continues *past* `__END_OF_TEST__`. We currently time out (infinite loop, a
distinct pre-existing issue). Per the working rule "reach ruffle_matched unless
Ruffle is doing something wrong" — Ruffle is doing something wrong here (does not
match Flash, doesn't cleanly terminate), so matching its buggy runaway is not a
worthwhile target. Left as `known_failure`. (The timeout itself — making our
runtime terminate the runaway like a frame-capped player rather than hang — is a
separate, lower-priority follow-up; it would not change the pass rate since the
test is a `known_failure` Ruffle also fails.)

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
