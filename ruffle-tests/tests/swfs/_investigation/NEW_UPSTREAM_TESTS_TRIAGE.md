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

## CI enumeration gap — ROOT CAUSE FOUND & FIXED (2026-06-18, follow-up session)

The earlier hypothesis in this doc (an "artifact flow" mystery in how the
sharded run enumerates the uploaded recompiled-test-data) was **wrong**. The
real cause was much simpler: the Gnash shard step in
`.github/workflows/ruffle-tests.yml` carried explicit **`--exclude`** flags that
dropped exactly these three tests:

```
--tests-dir="$GNASH_MING_DIR"  ... --exclude=gotoFrame2Test
--tests-dir="$GNASH_SWFC_DIR"  ... --exclude=gotoFrameFromInterval --exclude=gotoFrameFromInterval2
```

These were added in commit `4b79110d6` ("Add --exclude flag and skip hanging
Gnash tests in CI", 2026-04-03) as a stopgap because all three were **hanging**
(infinite loops / runaway) before the timeline-control fixes. `verify_output.py`
applies `--exclude` after `discover_tests`, so the shards simply never graded
them — which is why CI's `misc-ming.all` total read 110 and `misc-swfc.all` read
19 even though local discovery finds 111 / 20.

**Fix:** removed the excludes for the two now-fixed tests so CI grades them:

- `gotoFrame2Test` → **PASS** (un-excluded)
- `gotoFrameFromInterval2` → **ruffle_matched** (un-excluded)
- `gotoFrameFromInterval` → **stays excluded** (see below)

`gotoFrameFromInterval` (no "2") remains excluded on purpose. It is a
`known_failure` runaway: both we *and* Ruffle diverge from Flash
(Flash's `output.txt` cleanly terminates with 3 tests + `__END_OF_TEST__`;
Ruffle's `output.ruffle.txt` is an unbounded runaway). Locally it hangs ~35s
(9 GB RSS — within-tick timer/goto catch-up looping with O(n²) `asOrder` string
growth, bounded only by `timer.c`'s `iteration_limit=10000`) until the 30s
per-test runner timeout kills it. Grading it would only add a `timeout` failure
and burn ~30s of CI per run with zero pass-rate upside. Making the runtime cap
the runaway like a frame-capped player is the OPTIONAL follow-up below; it is
deferred because it touches the core "keep ticking past num_frames for
onEnterFrame" main-loop policy that many tests rely on.

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

### Scoping decision (2026-06-18 follow-up session): DEFER

Re-scoped against the actual test source (`shared_object/test.as`,
`output1.txt`/`output2.txt`) — confirms the analysis above. The full effort is:

- **AMF0 codec (serializer + deserializer)** covering Number, Boolean, String,
  Null, Undefined, anonymous Object, ECMA Array, Strict Array, Date, XML
  (typed-object), and references. This is the bulk of the work (~several hundred
  lines of fiddly format code).
- **Byte-exact `getSize()`** — `output1.txt` asserts `size: 279` *exactly*. The
  serializer must reproduce Flash/Ruffle's AMF0 byte layout precisely (including
  property key ordering, ECMA-array `length` framing, the `09` object-end
  marker, etc.). Byte-exactness is brittle: any ordering or framing mismatch
  fails the assertion, and there is no partial credit.
- **`.sol` container format** — 6-byte header, `TCSO` magic, padding, the
  shared-object name, AMF version byte, then the AMF0 body.
- **`verify_output.py` two-run harness** — run with no `.sol` (compare
  `output1.txt`, persist the flushed `.sol`), then re-run with it present
  (compare `output2.txt`). Plus discovery support so the `output1.txt`/
  `output2.txt` pair is recognized (currently `resolve_expected_filename`
  returns `None` → the tests are skipped entirely).
- **AVM1 edge semantics** the read-back branch exercises: array holes →
  `elem0,undefined,undefined,undefined,elem4`, `length == 5`,
  `hasOwnProperty('0')==true` / `('1')==false`, string property `array['prop']`,
  negative index `array[-1]`, nested object, `Date.getTime()`, `XML` typeof, and
  `delete obj.data` returning **false** (SharedObject `data` is non-deletable).

**Decision: do NOT implement now.** Two tests do not justify a from-scratch
byte-exact AMF0 codec plus a new two-run harness, and the byte-exact `getSize`
gate makes it a long debugging tail. Revisit only if (a) more SharedObject/AMF0
tests appear upstream, or (b) a shipped game actually needs LSO persistence —
at which point the codec earns its keep beyond the test suite. Until then these
two stay undiscovered (zero pass-rate impact) and documented here.
