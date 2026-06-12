# DJ level loader — increment 2 (region swaps, arrow gating, blue movers, goal visuals)

**Date:** 2026-06-11 (same day as the first increment + the stack-fix hunt).
**Request:** `~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/dj-loader-integration-addendum-1.md`
(the post-first-increment ladder). **Harness:**
`ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/` (README updated).

All four ladder items landed and verified, plus the new injector-module
deliverable. No runtime/recompiler source changed — loader AS + page shim +
harness + tools only.

## ⚠ SYNC FLAGS for the AP side (re-copy required)

1. **`loader_bytecode.bin` — REBUILD AND RE-COPY** (Loader.as gained the
   reconfigure path, the mover engine, goal visuals, and the pre-takeover
   hero guard). Wide build recipe unchanged:
   `python3 gen_fixture.py --stage-width 600 && STAGE_WIDTH=600 ./build_loader.sh`.
2. **`dj_swf_bridge.js` — CHANGED, re-vendor verbatim.** Three additions:
   - `__swfConfigGen()` — your proposed per-configure integer counter,
     adopted as-is (`configure()` bumps it; the loader polls 1 int/tick and
     re-pulls the config string on change). Loader is backward-compatible
     with pages lacking it (gen polling disables; first-configure still works).
   - **Arrow-key gating** — capture-phase `keydown` listener on `window`
     blocks ArrowLeft/ArrowRight unless the exact item names `Left arrow` /
     `Right arrow` are in the held set. Gates the KEY (works identically for
     Ruffle and the WASM canvas); keyup is never blocked so a held key can't
     wedge if its item were revoked mid-press.
   - **P| record FORMAT v2** — two trailing fields `|sweepMin|sweepMax`
     (center-sweep bounds in DJ coords, EMPTY for static platforms). Encoder
     + `gen_fixture.py` updated in lockstep; the loader treats
     empty/missing as static, so v1 strings still parse.
3. **`swfPatch.js` can be replaced**: the canonical browser injector now
   exists — `tools/divergence/swf_inject.mjs`, ES module,
   `injectSwf(swfBytes, bytecodeBytes, {stageWidth, minVersion}) →
   Uint8Array` (FWS+CWS, SWF≥6 subset; throws on ZWS/SWF5 rather than emit a
   wrong file; browser `DecompressionStream` with node:zlib fallback).
   Byte-identity vs `inject_tracer.py` is pinned by
   `node tools/divergence/test_swf_inject.mjs` — IDENTICAL for both plain
   (677548B) and `--stage-width 600` (677549B) against today's bytecode.

## Increment results (all events via the full EI bridge → mock host)

### 1. Region swaps via re-configure — DONE (Ruffle + browser-WASM)

Zero-input verification: start region_4_4 with "Brown platforms" granted at
15s → brown p9 → `sendExit(side_exit_W, W)` → host configures region_3_4 →
loader re-authors in ONE tick (claim/park re-position; batched MC ops are
safe post stack-fix) + respawns at the new entrance → climb fires region_3_4's
`loc_0` → brown p7 → `sendExit(side_exit_E, E)` → back to region_4_4 with
`checkedLocations=[loc_0]` → **no loc_0 re-send on revisit**, the portal
re-arms, and the ping-pong continues (7 swaps in a 45s Ruffle run; identical
sequence on browser-WASM). Pickup dedupe is host-owned via the `C|` record
exactly as specced; gated platforms re-evaluate onto the new region within a
tick (forced items re-apply after every configure). Regions with more
platforms than the native 15 blocks work (region_4_3's 17: fresh attaches
for idx 15/16).

The mock host now follows the preset's `exits` table on sendExit and carries
the global collected set across swaps (`dj_host_mock.js`), so any region
graph walk is testable standalone; `regions.js` (generated) carries all five
payloads. Harness knobs: `INJECT_JS='window.__DJ_START_REGION="...";
window.__DJ_GRANTS=[{at:ms,item:"..."}]' ./run_wasm.sh 30`.

### 2. Arrow input gating — DONE (Ruffle + browser-WASM)

A/B with the Playwright steer schedule (`STEER_KEYS=1`, grant `Left arrow`
@5s): during the un-granted ArrowRight hold the hero's `hx` never moved
(189/170 ticks pinned at 120, zero rightward samples on either tier); after
the grant the ArrowLeft hold moved it −10/tick (DJ's native flat air
control). Input is gated, physics untouched, `_level1` stays dead.

### 3. Blue movers under the AP sweep spec — DONE (with findings)

Loader positions sweeping blues EVERY tick at the triangle wave
(`BLUE_SPEED=5`, `t = regionTick` = ticks since region entry/respawn, t=0 at
the spawn state, phases restart on respawn/re-configure). The native mover
child "aaa" (charId 32) is frozen at local 0 (`ac=0`), which makes the mover
geometrically identical to a green at the block origin — SWF geometry
confirms charId 35's bounds are x∈[−30,30] at placement (0,0), same
y[0,40.15] catch band as greens — so `block._x` IS the platform center with
**no offset**.

**x(t) table: EXACT match on all three tiers** against
`region_4_3_expected.json` `movers.p9.x_by_tick` (e.g. our rt=273 → world
240 = your x(273); full ±5/tick triangle, turns at 15/585, period 228).
Verified end-to-end: region_4_3 zero-input climb (loc_0+loc_1), bounce under
the mover, grant `Blue platforms`, mover caught as a pass-through stepping
stone, chain continued p10..p14, `sendExit(side_exit_N, N)` fired, and the
swap into region_4_2 brought ITS mover up live from entry.

**Finding (for your sim): the mover CATCH TICK is knife-edge and
Ruffle ≠ your sim.** Ruffle (ground truth) and browser-WASM catch at
**rt=179 in perfect agreement** (mover at world 260, moving left; feet point
277 inside bbox 230..290 — geometrically sound), but your sim catches at
**t=289** (x=320). At your t≈175–179 apexes the overlap also looks
geometrically valid (e.g. x(179)=260, same bbox math), so your step() seems
to MISS an overlap window real DJ catches — likely the per-tick sampling
order of mover-move vs feet-test vs the 1-tick climb phase offset. Logic is
unaffected (everything catches eventually and continues the chain; the
verifier only needs eventually-catchable), but if you ever want tick-exact
mover parity for playback, the catch sampling is where to look. Happy to
trade per-tick traces.

**Finding (ours, dev tier only): graphics-native catches movers with a
wider/shifted effective bbox** — it missed the rt=179 window and then caught
at rt=273 with the nearest foot ~7px OUTSIDE the mover's true bbox
(feet dj-97 vs bbox 30..90). Production tiers (Ruffle, browser-WASM) agree
with each other to the tick and pixel, so this is a graphics-native
attached-clip hitTest margin to chase in a future runtime session — logged,
not blocking (native completes the full chain regardless).

### 4. Goal visuals — DONE (Ruffle + browser-WASM screenshots)

Pickup hosts get the native `coin` sprite (exonerated post-stack-fix)
floating above the platform, removed on collection and never re-offered when
`checkedLocations` covers them; portal hosts get a translucent drawing-API
"door" (purple, drawn in container space). Both park/remove correctly across
item-gating, respawn, and region swaps (old region's visuals are swept on
re-configure). Verified visually on both browser tiers (Ruffle screenshot
shows the door above the broken brown at the column top at the moment of the
portal landing).

## Misc

- Your ASYNCIFY `runSWF`-from-`onRuntimeInitialized` re-entrancy finding:
  acknowledged; our harness's ready-flag polling already defers — noted in
  the harness README so future pages don't regress it.
- `run_browser.js` now saves a `final.png` end-of-run screenshot
  (SCREENSHOT_DIR) — handy for visual checks on both tiers.
- The committed fixture default remains region_4_4 @ 240px (the embed builds
  wide itself); `gen_fixture.py --region region_4_3 --grant-item
  "Blue platforms" --grant-tick 220` reproduces the native mover validation.

## Next (per the addendum ladder)

Springs/jetpacks are post-v1 (absent from the committed preset). From our
side the v1 loop (hand-play to Victory) now has every mechanical piece:
swaps + gating + movers + visuals. We're ready for hand-play reports; the
likely polish areas are visuals (marker styling, locked-state padlocks if
you want gate_rules surfaced) and any catch-feel issues from real play.
