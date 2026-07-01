# N portals — plan (future session)

Date: 2026-06-30. Goal (user): insert **up to 4 portals per N level**, each drawn
with a **directional arrow** (N/E/S/W) indicating its direction — mirroring the
Doodle Jump portal work. Recommended as its **own session** (see §Why separate).

## The DJ precedent (read first)

DJ already does exactly this — portals with direction arrows:
- **`SWFRecompDocs/status/2026-06-12-dj-loader-increment-3.md` §3.2 "Portal doors —
  host-riding + direction arrows"**: each door is drawn once via drawing API with a
  **white direction triangle** per the goal's `side` (N/E/S/W); verified W (left
  arrow) and E (right arrow). Doors live on `_root`, positioned per tick; dim to
  low `_alpha` when their host is item-gated away.
- `ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/dj_swf_bridge.js` —
  `level.portals` + `sidePortals` map; portal→side bookkeeping.
- `dj_loader/dj_host_mock.js`, `dj_loader/README.md` — host feeds portals; on touch
  the SWF calls `__swfSendExit("portalId|side")` (portal = an AP region exit).
- Related memory: [[dj-level-loader]], [[archipelago-rando-integration]].

## How this maps onto N (what to investigate)

N is SIMPLER than DJ for portals: single 31×23 screen, **no scrolling/container**,
so no host-riding — portals sit at fixed pixel positions. Reuse our substrate:
- **Rendering**: an injected high-depth `_root` clip (`createEmptyMovieClip` +
  `moveTo`/`lineTo`/`beginFill`) drawing each portal body + a direction triangle,
  positioned via `nLevel.cellToPixel` (cell center = `mx*24+36`). N's own renderer
  is untouched; the NLoader already runs injected clips, so drawing-API portals on
  `_root` should render fine. (N's in-game graphics gaps — laser/particle
  persistence, BACKLOG — are unrelated to injected drawing clips.)
- **Placement / config**: extend the `__swfBridge` level payload with a `portals`
  list (`{id, cell:[mx,my], side:N|E|S|W}`), fed like the level string. Up to 4.
- **Detection**: the NLoader onEnterFrame checks player distance to each portal
  (same pattern as the exit switch/door radius test) → on touch fire
  `__swfSendExit("portalId|side")` (align to the framework's `sendLocation`/
  `sendExit` at P4). Decide semantics: AP **region exit** (touch → host loads the
  next region, direction = which edge) vs in-level teleport A↔B. DJ's arrows are
  region-exit directions, so region-exit is the likely intent.
- **Generator integration** (after the mechanic works): `nGenerate` places up to 4
  portals (typically at region edges so N/E/S/W arrows point off-screen); `nVerify`
  / host round-trips them. Portals become the N substrate's region-transition
  primitive for Archipelago (plan `n-level-generator-plan.md` §P4/§P5).

## Suggested increments (each Ruffle-verified)

1. **Draw 4 portals + arrows** from a baked/config portal list; eyeball on Ruffle
   (headed) that bodies + N/E/S/W triangles render at the right cells.
2. **Detect touch** → `__swfSendExit("portalId|side")`; host logs it (extend the
   queue/host mock). Drive with a demo that walks the ninja into a portal.
3. **Generator placement** — `nGenerate` emits ≤4 portals per level at edges;
   verify the ninja can reach at least the intended one.
4. **Framework/AP** — portals as region exits in the Archipelago-CC substrate.

## Why separate session

- Distinct workstream: injection + **rendering** (drawing portal + arrow) +
  teleport/exit-signal logic — closer to the DJ loader/graphics work than to the
  momentum/physics generator this session built.
- Investigation-first (read the DJ precedent, find N's draw/detect hooks) — benefits
  from fresh context; the current session is long and loaded with generator
  internals.
- Clean dependency: portals don't need the physics generator; they plug into the
  same `__swfBridge` substrate. Generator placement (increment 3) layers on top
  once the mechanic works.
