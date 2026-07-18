# Session prompt — avm2 quick pair: displayobject_rotation drift + real AVM2 HUD memory counters

Two small, independent AVM2 tasks batched to share one CI pipeline. Both are
well-scoped; neither should grow.

Read first: `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`
(the 2026-07-18 entries mention both), memory `avm2-rwk-ap-handoff` (where the
HUD-counter trap was discovered), and CLAUDE.md's **Browser Performance
Measurement** section (standing capability — WSL Chrome is SwiftShader; any
perf-flavored browser measurement goes through the Windows Playwright rig,
recipe at `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`).

## Task A — `displayobject_rotation` upstream drift (pass→fail, 1 line)

From the weak-orphan-registry CI run (2026-07-18, `.pipeline-state` note):
upstream grew the test's expected output 1275→1284 lines with a **new
rotation-normalization expectation, and we miss exactly 1 line** — verified
locally at the time as unrelated to the GC change (pure upstream drift; the
test was passing before the upstream sync).

1. `python3 ruffle-tests/verify_output.py --test=displayobject_rotation --diff --verbose`
   to see the exact missing/differing line.
2. Read Ruffle's current rotation handling (`~/CC/ruffle`, AVM2
   DisplayObject rotation — they normalize to (-180, 180]) and the test's
   `test.as` to understand what new case the 9 added lines exercise.
3. Fix our AVM2 rotation get/set normalization to match. Watch the classic
   edge cases: negative inputs, values ≥ 360, exactly ±180, NaN/Infinity
   (AS3 setter semantics), and float formatting of the result (our
   number→string must match Ruffle's output for e.g. `-180` vs `180`).
4. If the diff turns out to be genuinely unfixable (platform UB, inconsistent
   expected output), it goes through the ACCEPTED_DIFFS.md process instead —
   but expect a real fix; "we miss 1 line" smells like one normalization
   branch.

## Task B — wire real AVM2 counters into the browser perf HUD

The trap (found by the RWK AP session, documented in CURRENT_STATUS.md): the
perf HUD's "live AS objs / arrays" readout is **AVM1-only** — the AVM2
browser loop passes literal zeros, so any browser-side AVM2 memory gate
asserts 0 == 0.

- Call site: `SWFModernRuntime/src/avm2/avm2_main.c:481` —
  `swf_perf_report(elapsed, frame_budget_ms, present_ms, 0, 0)`.
- The accessors ALREADY EXIST: `avm2_gc_live_objects()` /
  `avm2_gc_live_strings()` (+ `avm2_gc_live_bytes()`), declared in
  `include/avm2/avm2_gc.h:92-94`. Pass objects + strings in the two int
  slots.
- HUD label: `swf.c:31` (EM_JS `swf_perf_report`) renders
  `'live AS objs ' + live_obj + ' arrays ' + live_arr` (swf.c:135 area).
  The EM_JS is shared between VMs — smallest correct change wins: either a
  VM-neutral label ("live objs / strs|arrs") or gate the label under
  `SWF_AVM2`. Don't restructure the HUD.
- Consider exposing `avm2_gc_live_bytes()` too if a third slot is cheap
  (e.g. fold into the label string) — optional, only if it stays a
  one-line-per-layer change.
- After the fix, update the CURRENT_STATUS.md trap note ("runtime exposes no
  AVM2 heap counter to JS") to point at the new counters, so the next
  browser-memory gate is written against them.

**Verify (functional, not perf — WSL headed Chrome is fine for this):** load
`demo.html?test=avm2/rwk` with the perf HUD on; counters must be nonzero,
plausible (RWK idle ≈ tens of thousands of objects), and ~flat while idling
(the weak-orphan fix landed — flat is the expected steady state). If you take
any frame-time measurement while you're in there, that's perf → Windows rig,
never WSL numbers.

## Grading / pipeline

- Task A is trace-observable → full pipeline per `.claude/pipeline-handoff.md`.
  Rotation setters feed display transforms (shared with render paths) → run
  **BOTH CI modes**. Zero pass→fail; `displayobject_rotation` flips to PASS.
- Task B is browser-only (CI can't observe the HUD) but rides the same
  commit; the wasm-link-smoke job observes the compile. Rebuild + redeploy
  the AVM2 demos only if you want the HUD fix live (incremental is fine —
  no layout changes); restaging Archipelago-CC is NOT needed for a HUD-only
  change unless a runtime .c that ships in their staged wasm changed (Task A
  does change one — so restage per the `avm2-flashpunk-text-font-name-resolve`
  lesson).
- Session memory: the rotation semantics delta (what Flash/Ruffle normalize,
  what we did wrong), and note the HUD counters are now real.

## Budget note (delegation)

Opus-led session — both tasks are small and well-specified. Escalate to Fable
only if the rotation normalization interacts with something deeper (e.g. our
matrix decomposition returning a different-but-equivalent angle, which would
make this a representation question rather than a formatting one).

## Boundaries

- AVM2 only (`src/avm2/` + the two swf.c HUD lines); don't touch AVM1
  semantics or the AVM1 HUD counters.
- Don't expand scope into other rotation-adjacent tests unless the same fix
  flips them (report any freebies in the memory).
