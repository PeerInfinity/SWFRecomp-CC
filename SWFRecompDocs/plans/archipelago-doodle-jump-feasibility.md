# Doodle Jump — flashSubstrate integration feasibility probe

> **Status: PROBE BRIEF, 2026-06-01.** Written by the Archipelago-CC side
> for the SWFRecomp-CC instance to execute. This is a **read/write +
> control feasibility probe**, NOT an integration build. Find out what
> Doodle Jump exposes to injected ActionScript *first*; we decide which
> `flashSubstrate` features it can support *after*. Do not design the
> integration up front.

## Context

Archipelago-CC's `flashSubstrate` (multi-runtime Flash-as-procgen-substrate)
has its contract + shared panel + per-region capability seams committed and
tested — but only against a JS placeholder game. A placeholder can be made
to "support" any capability we invent, so it validates the *contract*, not
*content integration*. To validate the remaining capabilities we need a
**real game**, and Doodle Jump is the candidate: it's **AVM1** and already
mostly running in SWFRecomp (see the `2026-05-2x-doodle-jump-*` status
docs + `SWFRecomp/tests/flasharchive/Doodle_Jump`), so it's on the proven
AVM1-cooperative `__swfBridge`/`ExternalInterface` path that the EI +
memory-poke probes already validated on both SWFRecomp and Ruffle.

Doodle Jump is acknowledged to be an **awkward** fit (endless vertical
scroller: continuous height/score, no discrete rooms/levels, small powerup
set, enemies). That's fine — the goal is to learn whether a real-but-awkward
game stresses the design productively, or whether we should fall back to a
purpose-built AVM1 fixture. **"Here's the little it can support" and even
"feature X is impossible because Y" are valuable results.**

## What `flashSubstrate` capabilities map onto (the questions)

For each, report **possible / partial / not-possible**, with the *specific*
AS hooks (class/property paths via `getDefinitionByName` or the path-walker,
events, functions) that make it work — or the specific obstacle. Where a
"tiny proof" is requested, actually run it in headed Chrome (the same
graphics-WASM + EI harness as the prior probes) and report the observed
result, then revert the probe code.

### 1. Locations — read game state for AP objectives (feasibility only)

Can injected AS detect/observe events usable as AP "locations/objectives"?
Likely candidates for DJ:
- **score/height milestones** (e.g. reach 5000) — is the score/height value
  readable via the AS object graph? Pollable (`readState`-style) or
  event-driven?
- **powerup pickups** (jetpack / spring / propeller hat) — observable?
- **enemy kills / other discrete events** — observable?

Which values are reachable, and do any fire observable events vs needing
polling? (Maps to the `locations: cooperative | memory_poke` capability.)

### 2. Items — write state to grant AP items (feasibility only)

Can injected AS *write* state to grant an AP item — force a powerup, modify
jump height, toggle an ability? What's writable vs read-only? (Maps to the
`items: pull | push` capability.)

### 3. Goal / completion (feasibility only)

Is there a readable win / death / score-threshold the substrate could treat
as region completion?

### 4. Platform & item PLACEMENT control — **feasibility + tiny proof**

This is the deeper question: can injected AS **intercept or replace the
code that places platforms and items**? This is the test of *procgen-rendered
content* (Mode 2) — not just observing game state, but having procgen author
the game's actual content.
- Which class/function places platforms + items as the game scrolls? Is it
  reachable / overridable / patchable via injected AS?
- What is the placement data shape (coords, platform types, item types)?
- **Tiny proof:** force one platform to a known position, OR swap one item's
  type, and confirm the change actually takes effect in the running game.

If placement is controllable, a DJ "zone" could be an *authored stretch of
platforms* rather than a teleport target — which reshapes the zone model for
this game. Report that implication if the proof succeeds.

### 5. Playback bot — simulated-keypress steering — **feasibility + steering proof**

Can a playback bot drive DJ automatically? Unlike the maze / text-adventure
substrates (which "walk" by dispatching events), DJ needs **real-time motor
control**: find a reachable next platform, synthesize keypresses to steer
the player there, react to physics. This is a harder playback model than
anything currently in the codebase, so feasibility is genuinely unknown.
- **Input path:** can simulated keypresses (left/right) actually reach the
  game — via the recompiled runtime's input layer, synthetic DOM key
  events, or an injected-AS input hook? Which works?
- **Perception:** are player position + nearby platform positions readable
  enough (rate, accuracy) to choose a target and steer?
- **Steering proof:** read player + nearest-reachable-platform positions,
  inject left/right keypresses, and show the player can be steered toward a
  target platform — even crudely. Report how well it tracks (lands reliably?
  drifts? physics fights it?).

This maps to the deferred `getPlaybackController` capability. A working
(even crude) steering proof tells us automated playback of a real-time
action game is viable; a clear "input can't be injected" / "can't steer
reliably" tells us playback for this class of game needs a different
approach.

## Deliverable

A capability report: for each of the 5, **possible / partial / not-possible**
with the specific AS hooks or the specific obstacle; for #4 and #5, the
observed result of the tiny proof (reverted after). Plus a recommendation:

- **Is Doodle Jump a good enough driver for flashSubstrate steps 4–7**
  (item-push, teleport/zones, memory-poke, real-game migration), or should
  Archipelago-CC fall back to a purpose-built AVM1 fixture?
- Which capabilities DJ supports well, which awkwardly, which not at all —
  so the AP side knows which steps it can actually exercise against DJ.

## Method

Use the injected-AS / `ExternalInterface` approach proven in the EI +
memory-poke probes (`action.c` EI handler, `swf_bridge.js`-style shim,
graphics-WASM in headed Chrome via WSLg/DISPLAY). Probe code is throwaway —
revert after capturing results, as with the prior probes. AVM1 path only
(DJ is AVM1); no AVM2 work implied.

## Cross-references

- `archipelago-phase3-slice3-reconciliation.md` — the `__swfBridge` contract
  + the EI (outward) and inward-read (PULL) experiments this builds on.
- Archipelago-CC `NewDocs/plans/procedural-generation/flash-substrate-unification.md`
  — the `flashSubstrate` design, the capability axis (Option B), the zone
  model, and the step sequencing (4–8) this probe informs.
