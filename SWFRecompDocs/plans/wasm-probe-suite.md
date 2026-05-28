# WASM Probe Suite — Plan

Status: **draft (2026-05-27)**. Builds on the three wasm-fix commits from
this session (`7fd96e6f2`, `2d792bde3`, `aaaf111b4`) and the
`leaf_shared_slot` exploration that confirmed the recompiler doesn't dedupe
matrices (so the hypothesized shared-slot bug isn't reachable from current
recompiler output).

## Goal

A small library of **hand-built minimal SWFs** that each exercise one
specific browser-WASM-graphics behavior. Two purposes:

1. **Regression guard.** Each fix this session is verified end-to-end only
   via Snake's complete gameplay path. If a future change reintroduces one
   of those bugs, Snake will still mostly work and the regression slips
   through. Per-fix probes catch each bug in isolation.

2. **Gap surfacing.** A handful of identified wasm gaps (case-folding in
   SWF≤6, failed-SetTarget flag tracking, clone clip-event dispatch) are
   not exercised by anything in the current corpus. Hand-built probes
   confirm the gap exists and serve as the eventual fix's regression
   test.

The probes are deliberately **minimal**: single-frame (or a few frames),
one piece of bytecode per test, deterministic, no input dependence.
Visual verification is by golden-image comparison; trace verification
(where applicable) is by exact-match against expected output.

## Non-goals

- Not a comprehensive AVM1 coverage suite. The Ruffle AVM1 corpus is
  that. We layer on top, specifically targeting browser-WASM behaviors
  Ruffle's trace tests don't surface.
- Not replacing visual inspection of full demos (Snake, DJ, Pong).
  Those exercise integration; the probes exercise individual
  primitives.
- Not aiming to drive arbitrary Flash content — just our own targeted
  test SWFs.

## Test inventory

Eight probes total. Each lives at
`SWFRecomp/tests/wasm_probes/<slug>/` with the standard structure
(`test.xml`, `test.swf`, `config.toml`,
`RecompiledScripts/`, `RecompiledTags/`, plus a deploy-side
`test_info.json` + `golden.png`).

### Group A — Regression tests for this session's fixes

#### A1. `clone_basic` — duplicateMovieClip dispatch

Verifies the `actionCloneSprite` widening (`7fd96e6f2`).

**Stage:** 320 × 240, one named sprite `src` containing a 40 × 40 red
square, placed at center.

**Bytecode (frame 1):**

```
PushString "src"           ; source name (becomes TARGET on AVM stack)
PushString "dup"           ; new clone name
PushInteger 16384          ; depth
CloneSprite                ; opcode 0x24
PushString "dup"
GetVariable                ; resolve clone reference
PushString "_x"
PushInteger 80             ; shift dup right by 80px from src position
SetMember
```

**Expected (post-fix, current code):** two red squares — `src` at center
(x=160), `dup` at x=80+initial=80px+160=240… actually wait: dup inherits
src's position via the clone-slot copy, so `_x=80` puts dup at x=80
absolute. Two red squares: one at x=80, one at x=160.

**Pre-fix behavior:** `cloneMovieClip` no-op → only `src` visible.

**Verification:** golden screenshot comparison.

---

#### A2. `remove_basic` — actionRemoveSprite + numeric-target coercion

Verifies the `actionRemoveSprite` widening + unconditional
`convertString` (`2d792bde3`).

**Stage:** 320 × 240, one named sprite `src` (red square) at center.

**Bytecode (frame 1):**

```
; First duplicate
PushString "src"
PushString "dup1"
PushInteger 16384
CloneSprite

; Then remove via NUMERIC target (exercises the integer→string coercion
; that Snake exposed)
PushInteger 16384          ; numeric target — should toString to "16384"
RemoveSprite               ; opcode 0x25
```

Hmm — the integer-target path in Snake actually pushes a *named* target
(`var x = "1"; removeMovieClip(x);` where x evaluates to the integer
tail counter). The actual stack-top at `RemoveSprite` time is an INT,
not a STRING. To replicate that pattern we'd push the numeric value of
a variable that resolves to "dup1". Simplest construction:

```
PushString "dupName"       ; var name
PushString "dup1"          ; var value
SetVariable                ; dupName = "dup1"
PushString "src"
PushString "dup1"
PushInteger 16384
CloneSprite
PushString "dupName"
GetVariable                ; pushes "dup1"
RemoveSprite
```

(Actually a string here doesn't exercise the integer-coercion. The
*minimal* coverage of the integer path is `PushInteger N; RemoveSprite`
where the clone's name is the string form of N — i.e. a clone made via
`duplicateMovieClip("src", "1", 16385)` then `removeMovieClip(1)` with
the literal integer 1. That mirrors Snake's `tail` counter pattern.)

**Expected (post-fix):** only `src` visible after removal.

**Pre-fix behavior:** stub printf → `dup1` accumulates and remains visible.
Or, even with the widening in place, the integer-target path bails early
unless `convertString` is unconditional (the Snake symptom).

**Verification:** golden screenshot — single red square at center.

---

#### A3. `set_property_x` — opcode SetProperty `_x` un-gate

Verifies the `actionSetProperty` `as_set_flags |= 1` un-gate
(`aaaf111b4`).

**Stage:** 320 × 240, one named sprite `mover` (red square) at center.

**Bytecode (frame 1):**

```
PushString "mover"         ; target
PushFloat 0.0              ; property index 0 = _x
PushInteger 100            ; value
SetProperty                ; opcode 0x23
```

**Expected (post-fix):** red square at x=100 (left of center).

**Pre-fix behavior:** `mc->x = 100` is written but `mc->as_set_flags`
stays 0 → compose-time `apply_as_transform` skips → renders at
timeline-center.

**Verification:** golden screenshot.

---

#### A4. `settarget_empty_to_child` — empty-target route

Verifies the `getMovieClipByTarget("")` un-gate (`aaaf111b4`).

**Stage:** 320 × 240, one named sprite `child` (red square) at center
plus a second different-color reference sprite `ref` at a fixed
non-center position (blue square at top-left).

**Bytecode (frame 1):**

```
SetTarget "child"          ; opcode 0x8B (string arg)
PushString ""              ; current target
PushFloat 0.0              ; _x
PushInteger 50             ; new x
SetProperty                ; opcode 0x23 — should hit child, not root
SetTarget ""               ; pop back to base
```

**Expected (post-fix):** `child` at x=50 (left side), `ref` at top-left
unmoved. Stage layout intact (no root-level shift).

**Pre-fix behavior:** `getMovieClipByTarget("")` returned root →
SetProperty hit root → `root._x = 50` → tag.c's root-transform compose
shifted the entire stage 50px left. Both `child` and `ref` would appear
shifted leftward together.

**Verification:** golden screenshot — specifically check `ref` position
(if it's shifted, the bug is back).

---

### Group B — Probes for unfixed gaps

#### B1. `case_insensitive_settarget_swf5` — SWF≤6 case-folding

Surfaces the `findDisplayObjectByName` / `swf_name_match` mismatch in
browser-WASM.

**Stage:** 320 × 240, **SWF version 5**, one named sprite `MyClip`
(camelCase) — red square at center.

**Bytecode (frame 1):**

```
SetTarget "myclip"         ; lowercase — SWF≤6 should case-fold
PushString ""
PushFloat 0.0
PushInteger 100
SetProperty
SetTarget ""
```

**Expected (Flash / Ruffle / our NO_GRAPHICS):** `MyClip` at x=100,
case-folded lookup succeeded.

**Expected (current browser-WASM):** the case-sensitive
`findDisplayObjectByName` misses `MyClip` because we're searching for
`myclip` → SetTarget falls through to `getMovieClipByTarget` fallback,
which also misses → final fallback paths land us at root → SetProperty
hits root → stage shifts left 100px. Visually: red square stays at
canvas center (it didn't move) but the canvas border / background may
also appear shifted if root has visible geometry.

**Verification:** golden screenshot AND a brief trace comparison vs
Ruffle (run the .swf through Ruffle's headless mode and compare). This
is the test where Ruffle's reference matters most because the gap is
specifically a divergence from Flash semantics.

**When to enable:** depends on fix priority. This probe lands as a
red-status test until the gap is fixed.

---

#### B2. `settarget_failure_flag` — invalid SetTarget should invalidate flags

Surfaces the missing `g_settarget_invalid` flag-tracking in browser-WASM.

**Stage:** 320 × 240, two named sprites — `valid` (blue) at top-left,
`ref` (red) at center. Plus an outer "stage backdrop" with visible
border so root-shift is detectable.

**Bytecode (frame 1):**

```
SetTarget "nonexistent"    ; fails — should set g_settarget_invalid=1
PushString ""              ; current target — should be None/invalid
PushFloat 0.0
PushInteger 100
SetProperty                ; should NO-OP (MC builtins return undefined
                           ;  / no-op on invalid SetTarget)
SetTarget ""
```

**Expected (Flash / Ruffle / our NO_GRAPHICS):** SetProperty no-op
because `g_settarget_invalid=1`. Both `valid` and `ref` unmoved.
Stage layout intact.

**Expected (current browser-WASM):** flag stays 0; SetProperty hits
`getMovieClipByTarget("")` which (post-fix) returns
`g_current_context` (which post-failed-setTarget is still
`&root_movieclip` because the fall-through path set it there). So
the SetProperty hits root, stage shifts. Same visual symptom as B1
but for a different underlying gap.

**Verification:** golden screenshot + Ruffle reference comparison.

---

#### B3. `clone_clip_actions` — onClipEvent on duplicated sprites

Surfaces the `ng_queue_placement_clip_events` / `ng_queue_slot_unload_events`
stubs in `graphics_stubs.c`. Currently the only test of the linker stubs.

**Stage:** 320 × 240, one named sprite `src` with attached clip events:

```
onClipEvent(load) {
    _root.loadedFlag = 1;
    _x = _x + 50;          ; shift self right when loaded
}
```

**Bytecode (frame 1):**

```
PushString "src"
PushString "dup"
PushInteger 16385
CloneSprite                ; should fire dup.onClipEvent(load)
```

**Expected (Flash / Ruffle / our NO_GRAPHICS / OFFSCREEN_RENDER):** the
cloned `dup` fires its inherited onLoad → `dup._x += 50` → `dup` appears
50px right of `src`'s position.

**Expected (current browser-WASM):** `ng_queue_placement_clip_events`
is a no-op (`graphics_stubs.c:100`). onLoad never fires on the clone.
`dup` stays at `src`'s position (both overlapping at center).

**Verification:** golden screenshot. Trace optional — can also bind a
`trace("loaded")` inside onLoad and verify trace output count.

---

### Group C — Future-proofing

#### C1. `leaf_shared_slot` — recompiler matrix-dedupe canary

**Already built.** Lives at
`SWFRecomp/tests/wasm_probes/leaf_shared_slot/`. Two named shapes at
identical matrices. With current recompiler (no dedupe), behavior is
correct. If a future patch adds matrix dedupe, this test surfaces the
resulting shared-slot mutation bug immediately.

Commit as-is.

---

## Shared infrastructure

### Directory layout

```
SWFRecomp/tests/wasm_probes/
├── README.md                       # short index
├── leaf_shared_slot/               # (already exists)
├── clone_basic/
│   ├── test.xml                    # swfmill source
│   ├── test.swf                    # built artifact
│   ├── config.toml                 # recompiler config
│   ├── golden.png                  # expected screenshot
│   ├── golden_ruffle.png           # optional: Ruffle reference
│   ├── expected_trace.txt          # optional: trace match (if any)
│   └── RecompiledScripts|Tags/     # generated, .gitignore'd
├── remove_basic/
└── ...
```

### Build pipeline

A single script
`SWFRecomp/scripts/build_wasm_probes.sh` that:

1. For each `wasm_probes/<slug>/test.xml`: invoke
   `swfmill xml2swf test.xml test.swf`.
2. Recompile each via `bash -c 'ulimit -v 4194304; exec
   build/SWFRecomp config.toml'`.
3. Run `build_test.sh wasm_probes/<slug> wasm --graphics` to build
   the WASM artifact.
4. Run `deploy_example.sh wasm_probes/<slug>
   $(pwd)/docs2/examples --no-index --graphics` to publish.

Idempotent — skip rebuild when sources are unchanged (compare mtimes
on `test.xml` vs `test.swf`).

### Verification harness

A single script `tools/probe_test.py` (or similar) that:

1. Starts a local HTTP server (reuse existing `tools/browser-test/serve.py`
   helper).
2. For each probe, navigates to `demo.html?test=wasm_probes/<slug>`,
   clicks Run, waits a fixed time (1.5s default — probes are designed
   to settle within 1 frame), captures a CDP screenshot.
3. Compares against `golden.png` with pixel-diff threshold.
4. Reports pass/fail per probe + an HTML report with side-by-side
   golden vs actual.

Threshold: tight (max 5 diff pixels, max 16 channel delta). Probes
are deterministic so any meaningful drift is real.

### Ruffle reference comparison (B-group)

For B1 / B2, the bug is specifically a divergence from Flash semantics.
Visual comparison vs Ruffle's headless renderer is the authoritative
check.

Approach: invoke Ruffle's `ruffle_test_runner` (or similar headless
mode) on each B-group SWF, capture its output, compare to our
graphics-WASM output. If Ruffle says position is X and we say Y, gap
confirmed. The existing `ruffle-tests/verify_output.py` already has
hooks for graphics-mode runs; reuse that infra rather than building
parallel.

### Trace verification (where applicable)

For probes that also emit `trace()` calls (B3 with `trace("loaded")`,
or any test we want to instrument), compare against `expected_trace.txt`
using simple diff. Don't run trace-only mode — these are graphics
probes; if a trace assertion is wanted, it's a side-channel check that
fires from inside the WASM build.

---

## Phased rollout

### Phase 0 — Infrastructure (foundation)

- [ ] `SWFRecomp/tests/wasm_probes/README.md` describing the suite.
- [ ] `SWFRecomp/scripts/build_wasm_probes.sh` to compile/deploy all.
- [ ] `tools/wasm_probe_runner.py` (or extend `tools/browser-test/...`)
      to run + screenshot + diff.
- [ ] `.gitignore` entries for generated `RecompiledScripts|Tags/` and
      `build/wasm/`.
- [ ] CI wiring: add a `wasm-probes` job that runs the harness and
      uploads diff artifacts on failure. **Optional for v1** — local
      runs may suffice initially.

### Phase 1 — Group A (regression tests)

Land probes in this order, generating goldens from the current
post-fix runtime:

1. A4 (`settarget_empty_to_child`) — highest value: regression for the
   most recent fix.
2. A3 (`set_property_x`) — simplest probe; good shakedown of the harness.
3. A1 (`clone_basic`).
4. A2 (`remove_basic`).

Each commit: probe + golden + harness wiring. Expected timeline:
half-day per probe once Phase 0 is in. ~2 days total.

### Phase 2 — Commit C1

`leaf_shared_slot` is already built; add to harness, generate golden,
commit. **<1 hour.**

### Phase 3 — Group B (unfixed-gap probes)

These land as **red status** (intentionally failing graphics-WASM
output) until the underlying gap is fixed. Goldens come from a Ruffle
reference capture, not the current implementation.

5. B1 (`case_insensitive_settarget_swf5`) — most likely to be wanted
   by users (SWF5 content is common).
6. B2 (`settarget_failure_flag`) — internal correctness, less commonly
   triggered.
7. B3 (`clone_clip_actions`) — the most interesting "I didn't know
   this was broken" probe.

Each commit: probe + Ruffle golden + harness wiring + a `KNOWN_RED` /
`KNOWN_BROKEN` marker that the harness honors (skip from "regression"
pass/fail, surface in a separate "currently broken" report).

When the gap is fixed (separate session), the fix's commit moves the
probe from KNOWN_RED to required-passing.

---

## Open questions

1. **Should B-group probes block CI?** Recommendation: no, mark them
   KNOWN_RED so they don't block, but surface them in a separate
   "wasm-gaps" report. Promote to required-passing once the matching
   fix lands.

2. **Where do we store goldens?** Options:
   - Inside the test dir (`wasm_probes/<slug>/golden.png`). Pros:
     locality, easy to update. Cons: bloats repo with binary blobs.
   - Separate `wasm_probes/_goldens/` dir with a shallow PR-friendly
     diff workflow. Pros: easier to review golden changes. Cons:
     splits sources.

   **Recommendation:** in-tree at `wasm_probes/<slug>/golden.png`. The
   probes are tiny (5–10 KB PNGs at 320×240).

3. **How do we detect golden drift across the WebGPU stack?** Browser
   versions, GPU drivers, ANGLE / SwiftShader differences could
   introduce 1–2 channel diffs that aren't real regressions. Need to
   set the pixel-diff threshold experimentally — start tight (5 pixels
   / 16 channel delta), loosen if false positives appear in CI.

4. **Do we want to invoke Ruffle inline, or pre-capture references?**
   Pre-capture is simpler (commit `golden_ruffle.png` once) but stale
   if Ruffle's behavior changes. Inline-invoke is more robust but adds
   a Ruffle dependency to the CI step. **Recommendation:** pre-capture
   for v1, document the capture command, revisit if Ruffle's behavior
   drifts.

5. **swfmill bytecode coverage.** swfmill can encode all the AVM1
   opcodes we need (PushData, GetVariable, SetMember, SetProperty,
   CloneSprite, RemoveSprite, SetTarget — all verified working in the
   `leaf_shared_slot` build). What about `onClipEvent` clip-action
   attachment to a PlaceObject2? Per the swfmill schema, PlaceObject2
   takes `<clipActions>` as a sub-element. Need to verify the XML
   syntax with a small test before committing to B3's design.

6. **Should we extend the suite over time as new wasm gaps surface?**
   Yes — the framework should accommodate adding probes piecemeal. The
   build script iterates `wasm_probes/*/`, no hardcoded list.

7. **Trace-vs-visual split.** Currently the proposal mixes
   trace-checking (optional) into visual probes. An alternative: make
   visual and trace strictly separate probe modes, each with its own
   harness. The current proposal keeps them together because the SWFs
   themselves are graphics-mode-specific; adding a trace assertion is
   incidental. Revisit if the suite grows large.

---

## Risks

- **Golden flakiness.** First time we run on a different driver / GPU,
  pixel-exact match may fail. Mitigation: experimental threshold + a
  "regenerate golden" workflow that's a single command.
- **swfmill XML quirks.** I already hit `<FillStyle type="0">` not
  parsing — actual element is `<Solid>`. Each new probe may surface
  one or two of these. Mitigation: small validated probes per session,
  not big-bang.
- **Build pipeline cost.** Each probe currently takes ~30s to compile
  + recompile + WASM-build. 8 probes = 4 minutes. Acceptable for
  local dev; CI step adds 4 min if all run sequentially. Mitigation:
  parallelize if it becomes annoying.
- **Test infra bit-rot.** Probes that don't actually run won't catch
  regressions. Mitigation: run them locally every session that
  touches relevant runtime code, even if no probe-relevant change is
  intended.

---

## Effort estimate

Total: **~3–4 days** of focused work for all 8 probes + Phase 0
infrastructure.

| Phase | Hours | Notes |
|-------|-------|-------|
| Phase 0 | 6–8 | One-time infrastructure |
| Phase 1 (A-group) | 6–8 | 4 probes × ~2h each |
| Phase 2 (C1) | <1 | Already built; just wire in |
| Phase 3 (B-group) | 6–9 | 3 probes × ~2–3h each (Ruffle reference adds time) |

A two-session split is natural: Phase 0 + Phase 1 + Phase 2 in
session 1 (full regression-test suite green), Phase 3 in session 2
(gap-probes red-status, surfacing the unfixed gaps).

---

## Success criteria

- [ ] All A-group + C1 probes pass golden comparison on a fresh build.
- [ ] All B-group probes are deployed and run, marked KNOWN_RED with a
      side-by-side Ruffle reference image.
- [ ] One-line invocation (`tools/wasm_probe_runner.py` or similar)
      produces a clear pass/fail report.
- [ ] CI step (optional v1) blocks PRs that regress an A-group probe.
- [ ] When a wasm-gap fix lands, moving the corresponding B-group
      probe from KNOWN_RED to required-passing is a single config
      change.
