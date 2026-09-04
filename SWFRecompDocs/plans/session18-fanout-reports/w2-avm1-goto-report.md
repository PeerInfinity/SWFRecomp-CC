# w2-avm1-goto — wave 2: G1 landed (+1 graphics-effective, mode parity CLOSED); rider = HOLD

Session 18, base `8f68a5fea`, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa1d4ffbba7dfead6`. No commits, no pushes.
All runs: `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`, at most 2 concurrent jobs,
`DAWN_INSTALL=/home/robert/CC/dawn-install`. Logs/JSON:
`<scratch>/w2-avm1-goto/{before,after}_*.{log,json}`.

## NEW FILES (coordinator stages by name)

- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-goto.patch` (this deliverable)
- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-goto-report.md` (this file)

No new source files. **One** modified source file: `SWFModernRuntime/src/libswf/swf.c` (+20, −0).

---

## 0. Verdicts

| # | Item | Verdict | Result |
|---|---|---|---|
| **G1** | pre-advance orphaned action-queue drain in `swf.c` | **GO — LANDED, CONFIRMED** | `from_gnash/misc-swfc.all/gotoFrameFromInterval2` graphics `output_mismatch` → **`ruffle_matched`** (+1 effective). No-graphics unchanged (`ruffle_matched`). 24/24 canaries byte-identical. **The corpus's one graphics/no-graphics parity gap is closed.** |
| **R** | rider: `misc-swfc.all/gotoFrameFromInterval` hang | **HOLD (no fix)** | Mechanism nailed and re-measured. G1 does **not** change it. Completion mechanism named below. |
| **R'** | rider sub-question: *why* CI grades only 20 of 21 `misc-swfc.all` dirs | **ANSWERED — not a mystery** | An explicit `--exclude=gotoFrameFromInterval` in `.github/workflows/ruffle-tests.yml:880`. Neither `download_tests.sh` nor `verify_output.py` nor `test.toml` skips it. **It cannot spontaneously start being graded.** |

---

## 1. G1 — patch scope

`SWFModernRuntime/src/libswf/swf.c`, inserted between the `#endif` that closes the browser-WASM
timer/MCL pump block (`#if !defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)`, was `:1351-1408`)
and the `if (manual_next_frame)` natural-advance decision (was `:1409`):

```c
{
        extern size_t actionActionQueuePending(void);
        if (actionActionQueuePending() > 0)
                actionDrainAllInPriorityOrder(app_context);
}
```

plus a 15-line comment. Verbatim port of `swf_core.c:1544-1548`.

Two placement facts worth recording:

1. **The insertion is deliberately OUTSIDE every mode `#ifdef`.** `swf.c`'s timer/MCL drains exist
   *twice* — once in the `#ifdef OFFSCREEN_RENDER` cluster (`:1051-1349`) and once in the
   browser-WASM block (`:1351-1408`). Putting the drain in either arm would have fixed only one
   build. Placing it after the `#endif` gives the graphics test loop, the browser-WASM loop and the
   native-windowed loop the same pre-advance drain `swf_core.c` has had since 2026-06-18. This
   mirrors `swf_core.c`, where the drain is also unconditional.
2. `actionActionQueuePending` / `actionDrainAllInPriorityOrder` are already declared by
   `<actionmodern/action_queue.h>`, included unconditionally at `swf.c:227`; the local `extern` is
   kept only for byte-fidelity with the `swf_core.c` original.

Build coverage checked: the `OFFSCREEN_RENDER` arm is exercised by every `--mode=graphics` run
below; the **non**-`OFFSCREEN_RENDER` native arm was separately syntax-checked
(`gcc -fsyntax-only -DUSE_WEBGPU …  src/libswf/swf.c` → rc=0). No recompiler change, no
`Recompiled*` invalidation, no header/CMake/Emscripten source-list change.

---

## 2. Target test — before/after in BOTH modes

`from_gnash/misc-swfc.all/gotoFrameFromInterval2` (`known_failure = true`, ships
`output.ruffle.txt`; `pass` is unreachable — Flash's `output.txt` wants the `asOrder` assertion to
PASS, which neither Ruffle nor we do).

| mode | before | after |
|---|---|---|
| **graphics** (`--mode=graphics`) | **`output_mismatch`** — 24 lines: Ruffle's 23 plus a surplus root frame (`Entering unreachable frame 7 !`, `FAILED: _root._currentframe: expected: "6", obtained: "7"`, totals `#passed: 0 / #failed: 2`) | **`ruffle_matched`** — 23 lines, byte-identical to `output.ruffle.txt` |
| **no-graphics** (default) | `ruffle_matched` | **`ruffle_matched`** (unchanged) |

Raw: `before_gfi2_gfx.log` / `after_T.json` / `before_NG.json` / `after_NG.json`.

**Pricing (honest):** **+1 graphics-effective, not +1 pass.** The corpus-level value is that
`CLAUDE.md` / MEMORY's standing caveat — "*mode parity is complete EXCEPT
`from_gnash/misc-swfc.all/gotoFrameFromInterval2`*" — can now be retired. Both modes agree.

### Premise attack (rule 1)

The w1 diagnosis priced this as "one surplus natural frame advance, nothing else". **Confirmed
exactly**: the after-output is byte-identical to Ruffle's oracle, so the entire 21-line inventory
"gap" really was the one over-advance and its two derived Dejagnu totals. No part of the w1
mechanism needed revision. The one thing w1 could not resolve (why CI grades 20 of 21 dirs) is
answered in §4 and is unrelated to G1.

---

## 3. Canary ledger — 24 tests, `--mode=graphics`, ZERO changes

Bar: identical status, and for the two non-`pass` rows identical `--diff` output (a
`ruffle_matched` verdict is itself a byte-identity assertion against `output.ruffle.txt`).

| suite / dir | test | before | after |
|---|---|---|---|
| `from_gnash/misc-swfc.all` | `gotoFrameLabelAsFunction` | pass | pass |
| `from_gnash/misc-swfc.all` | `action_execution_order_test12` | ruffle_matched | ruffle_matched |
| `avm1` | `default_names` | pass | pass |
| `avm1` | `goto_advance1` | pass | pass |
| `avm1` | `goto_both_ways2` | pass | pass |
| `avm1` | `goto_execution_order` | pass | pass |
| `avm1` | `goto_methods` | pass | pass |
| `avm1` | `goto_rewind3` | pass | pass |
| `avm1` | `timeline_function_def` | pass | pass |
| `from_shumway` | `avm1/text-bind` | pass | pass |
| `regression` | `avm1_child_timeline_advance` | pass | pass |
| `regression` | `avm1_child_timeline_frame1_stop` | pass | pass |
| `regression` | `avm1_child_timeline_holder_stop` | pass | pass |
| `regression` | `avm1_child_timeline_loop` | pass | pass |
| `regression` | `avm2_goto_catchup_scale` | pass | pass |
| `regression` | `avm2_timeline_gradients` | pass | pass |
| `regression` | `avm2_timeline_solid` | pass | pass |
| `regression` | `avm2_timeline_stroke_gradient` | pass | pass |
| `regression` | `avm2_timeline_text` | pass | pass |
| `regression` | `enterframe_type1_args` | pass | pass |
| `regression` | `onunload_type1_local_frame` | pass | pass |
| `regression` | `root_enterframe_cross_swf_version` | pass | pass |
| `regression` | `watch_timeline_named_params` | pass | pass |
| `regression` | `watch_timeline_reentrant` | pass | pass |

Notes:
- `action_execution_order_test12` and `gotoFrameLabelAsFunction` are exactly the two "adjacent swfc
  timing" canaries w1 named; `default_names` and `from_shumway/avm1/text-bind` are the two tests the
  surrounding `swf.c` comments name as the natural-wrap / last-tick-capture keys. All four hold.
- The `regression` set is every dir in that suite whose name matches `goto|frame|interval|timeline`
  (14 of 88). The four `avm1_child_timeline_*` rows are the Multi-SWF arc's loaded-child playhead
  gates — the family most exposed to a drain moving one step earlier.
- **Image comparisons are byte-stable too**: `avm2_timeline_gradients`
  `0 outliers (limit 0), max difference 128` and `avm2_timeline_stroke_gradient`
  `0 outliers (limit 0), max difference 255` before *and* after; `avm2_timeline_solid` SKIP both
  legs (no `output.expected.png`). Image comparisons do not gate pass/fail, but identical numbers
  are free evidence that the graphics frame loop did not shift.
- CI mode for this change is **`graphics`** (`swf.c` is not compiled at all under `NO_GRAPHICS`).
  A no-graphics dispatch is not required; the one no-graphics run above is only the parity check.
- **Recommended CI dispatch:** `mode=graphics`, `categories=all`, `images=false`. `swf.c` is shared
  runtime (graphics test loop + browser-WASM + native-windowed), but `NO_GRAPHICS` builds
  `swf_core.c` instead, so the weekly no-graphics canary is unaffected by construction.

---

## 4. Rider — `from_gnash/misc-swfc.all/gotoFrameFromInterval`

### 4a. Why CI grades 20 of 21 dirs — ANSWERED (this was the coordinator's open question)

Not `download_tests.sh`, not `verify_output.py` discovery, not a `test.toml` flag. It is an
explicit workflow exclusion:

```
.github/workflows/ruffle-tests.yml:875-880
  python3 ruffle-tests/verify_output.py -v --mode=... --tests-dir="$GNASH_SWFC_DIR" ... \
    --exclude=gotoFrameFromInterval || true
```

Added in `4b79110d6` ("Add --exclude flag and skip hanging Gnash tests in CI", 2026-04-03) for three
tests; two were un-excluded on 2026-06-18 when they were fixed, and this one was **deliberately
kept**, with the reasoning written into the workflow comment and into
`ruffle-tests/tests/swfs/_investigation/NEW_UPSTREAM_TESTS_TRIAGE.md` §"gotoFrameFromInterval —
Ruffle is wrong (not pursued)".

Mechanically, `verify_output.py` applies `--exclude` at `:4010-4012` and computes
`total_available = len(tests)` at `:4014` — i.e. **after** exclusion. That is precisely why
`from_gnash/misc-swfc.all/_results/results_graphics.json` reads `total_available: 20` while 21 dirs
sit on disk. `discover_tests` itself finds it fine (it has `test.swf` + `output.txt`), and
`download_tests.sh` installs it (the dir is present locally after a plain sync).

**Consequence for the coordinator:** the feared "if CI picks it up we gain a `timeout` row" cannot
happen by accident. It is excluded by name, permanently, until someone edits the workflow. There is
no denominator risk and no decision to make this session.

### 4b. Does G1 change it? — NO

- **no-graphics:** G1 touches only `swf.c`; the no-graphics loop is `swf_core.c`, which has had this
  drain since 2026-06-18. Nothing could change, and nothing did.
- **graphics, with G1 applied:** re-run under a 2 GiB cgroup (`systemd-run --user --scope
  -p MemoryMax=2G -p MemorySwapMax=0`, so a shared 16 GiB box cannot be OOM'd) → **SIGKILL after
  17.7 s wall at 2.65 GB max RSS**, with stdout frozen at line 21 (`frame7`). Identical shape to the
  pre-patch no-graphics behaviour w1 measured (`TIMEOUT [x=31.81s]`). G1 makes graphics *agree* with
  no-graphics here, and no-graphics already hung.

### 4c. Mechanism — measured, and sharper than "infinite loop"

The frame-7 script (`RecompiledScripts/script_5.c`) registers **two** `setInterval` callbacks whose
delay is the double `0x3F1A36E2EB1C432D` = **0.0001 ms**. The intervals are cleared only by the
frame-8 script (`script_6.c`, two `clearInterval` calls). The callback appends `"x" + i++` to
`_root.asOrder` and traces nothing.

`SWFModernRuntime/src/actionmodern/timer.c::processTimers` advances every timer by one whole
`frame_duration_ms` per tick (`:420-424`) and then drains in a `do { … } while (fired_any)` loop
capped by `int iteration_limit = 10000` (`:430-433`). With `delay_ms = 0.0001` and
`frame_duration_ms ≈ 83.3`, a single tick owes ~833,000 firings per timer; the guard stops it at
10,000 loop iterations × 2 timers = **20,000 callbacks in one tick**, each doing an O(n) string
concat on a string that is already O(n) — **O(n²) bytes allocated inside one tick**. The root
playhead never reaches frame 8, so `clearInterval` never runs and the next tick repeats it.

So it is **not literally non-terminating** (w1's wording): it is a *bounded* runaway —
10,000 iterations × 2 timers × 30 ticks — that is simply many minutes and ~9 GB of RSS wide, so it
always dies on the runner's 30 s wall clock (`verify_output.py::run_binary`, `proc.wait(timeout=30)`
— note the `"runtime timeout (>10s)"` detail string at `:4261` is stale, the real cap is 30 s).
Distinction matters because it means the fix is a *rate* policy, not a loop-termination bug.

### 4d. Verdict: HOLD, with the completion mechanism named

**Do not fix in this slice.** Reasons, in order of weight:

1. **Zero measurable upside.** The test is excluded from CI by name (§4a), so no fix can move a
   corpus number until the workflow exclusion is also removed — a separate, coordinator-level edit.
2. **The fix is a corpus-wide semantics change, not a local one.** The completion mechanism is a
   **minimum-interval clamp**: two lines, `timer.c:199` and `timer.c:259`
   (`t->delay_ms = delay;` → clamp to a floor; Ruffle's floor is 10 ms). Two lines, but it re-times
   *every* `setInterval`/`setTimeout` in the corpus — including the Dejagnu harness that the whole
   `from_gnash/actionscript.all` suite drives through `setInterval`. That is a full-corpus,
   both-modes CI dispatch to price, which the brief's "≤ ~30 lines **and safe**" bar excludes.
3. Ruffle itself is wrong here (its `output.ruffle.txt` is a runaway that reports 10 tests instead
   of Flash's 3 and continues *past* `__END_OF_TEST__`), so even a perfect clamp buys
   `ruffle_matched`, never `pass`.

**But the lead is better than "not pursued" implies** — new evidence, worth recording: our current
21-line prefix is **byte-identical to `output.ruffle.txt`'s first 18 lines** (`diff` of the two
prefixes is empty; we are simply missing the 14 runaway lines after). And Ruffle's runaway grows by
exactly **10 `x`s per tick**, which is what a 10 ms floor yields at ~83 ms/frame. So a 10 ms clamp is
a *plausible* path to `ruffle_matched` on this test, not merely a hang fix. Anyone taking it should
budget: clamp + un-exclude in the workflow + one full-corpus graphics run + one no-graphics run,
and expect firing-count churn on every `setInterval` test.

---

## 5. What I ran

- Baselines (all `--recompile` on first use of each copied dir, `--mode=graphics` unless noted):
  target `gotoFrameFromInterval2` (graphics + no-graphics), groups A (2 swfc), B (7 avm1),
  C (1 shumway), D (14 regression). 25 test-runs.
- Patch applied; identical 25 test-runs re-executed (`after_*`), plus `gcc -fsyntax-only` on the
  non-`OFFSCREEN_RENDER` arm of `swf.c`.
- Rider: 4 bounded runs. `ulimit -v 3G` is **useless** for this runtime (it reserves 4 GiB of VA up
  front for the heap allocator and dies with `Failed to reserve 4294967296 bytes of virtual address
  space`) — use `systemd-run --user --scope -p MemoryMax=…` instead. Recorded here so the next
  agent does not re-learn it.
- Nothing was run in the main tree; the main tree's `SWFRecomp/build` was copied in (runtime-only
  patch, so this is valid per the wave-2 rules).

## 6. New unclaimed leads

1. **`verify_output.py`'s timeout detail string is stale.** `:4261` reports
   `"runtime timeout (>10s)"` but `run_binary` waits 30 s (`:3446`). Any triage that trusts the
   string under-reads how long a hanging test actually burns. One-line doc fix.
2. **`processTimers` has no minimum-interval floor** (§4c). Independent of the rider test: any real
   content calling `setInterval(f, 1)` gets ~83 callbacks per frame from us versus ~8 from Ruffle and
   ~1-2 from Flash. This is a model-level divergence with a game-perf face, not just a test face.
   Site: `timer.c:199` / `:259`. Owner: unassigned.
3. **The `misc-swfc.all` exclusion is invisible from the results files.** `total_available` is
   post-exclusion, so a workflow `--exclude` looks exactly like "upstream doesn't have this test".
   Two sessions have now spent time on this. Worth a line in the corpus-status tooling (e.g. have
   `corpus_status_diff.py` or the inventory generator surface workflow `--exclude` entries).
