# DJ level loader — increment 3 (visual polish) + a real gameplay bug found

**Date:** 2026-06-12. **Request:**
`~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/dj-loader-integration-addendum-2.md`
(post-V1 polish ladder). **Harness:**
`ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/`.

All four items (3.1–3.4) landed and screenshot-verified on Ruffle +
browser-WASM, native trace-verified. **Plus a root-cause find your 3.1
report led us to that is bigger than visuals — see "the jetpack bug" below.**

## ⚠ SYNC FLAGS for the AP side

- **`loader_bytecode.bin` — REBUILD AND RE-COPY** (everything below is
  Loader.as-side). Recipe unchanged.
- **`dj_swf_bridge.js` — UNCHANGED** this increment (as your addendum
  predicted: no format/encoder changes). The mock host (test-only, not
  vendored) gained `window.__DJ_TOUR=[{at,region}]` timed region tours.

## THE JETPACK BUG (your 3.1 "coins on wrong hosts" — found and fixed)

Your repro hint (3+ region walk) surfaced it, but the mechanism is wilder
than stale visuals: **native powerup contamination from the pre-takeover
window**. During the ~17 staged-init ticks the NATIVE game runs with random
blocks + powerups, and the pinned hero can brush a random **nail** →
`hero.jetpack = true` survives into the authored level. DJ's jetpack branch
**increments `lastblockhit` every rising tick** — which our landing
detection read as the hero landing on successive platform indices →
**phantom `sendLocation`/`sendExit` storms with no landings at all**
(observed live: an instant `sendExit` for a branch portal the hero never
reached, then a 4_4↔4_3 configure ping-pong as each new region's idx-3
portal "fired" — and phantom collections dimming/creating coins on
arbitrary hosts, i.e. your "coins on platforms that host no pickup").
Whether a given session is poisoned is per-run RNG (Ruffle/browser runs are
unseeded), which is why our deterministic harness runs looked clean and
your real play didn't.

Fix, both belts: the takeover/respawn reset now clears all native powerup
state (`jetpack/jetcount/move_inversed/counter/jumpspeed/maxjump`), and
landing detection ignores `lastblockhit` changes while a jetpack is live
(DJ's jetpack march is never a landing; authored levels can't grant
jetpacks — `attribute[]` is only ever 0/2). Verified: the previously
reproducible instant-exit ping-pong is gone; a 3-region timed tour
(region_3_3 → 4_3 → 4_2) runs with ZERO phantom events and exactly one
sendLocation per actually-landed pickup (2 sendLocations across 5 swaps in
the 30s browser-WASM ping-pong; revisit dedupe intact).

## 3.1 Coins — fixed + collected state

- Coins are repositioned to their host EVERY tick (`vizTick`), so no stale
  binding can survive region swaps; swept hosts would carry their coin too.
- On collection (and for `checkedLocations` on configure/revisit) the coin
  now **stays at `_alpha` 25** — the readable "already collected" state you
  asked for — instead of vanishing. Verified visually (dimmed coin in place
  mid-climb after collection; full coin on first visit).
- The "wrong host" reports were the jetpack bug above (phantom collections),
  plus increment-2 coins never being re-pinned after creation.

## 3.2 Portal doors — host-riding + direction arrows

Increment 2 drew doors via `container.createEmptyMovieClip`, which did not
behave as a container-space child in real play (your bug report). Doors
(and the new ghosts) now live on `_root` and are positioned EVERY tick from
`host_x + container-local y + container._y` — tier-agnostic, scrolls
exactly with the level, and swept-mover hosts get door-riding for free
(same `hostX()` as coins/ghosts). Each door is drawn once with a **white
direction triangle** per the goal's `side` (N/E/S/W); verified W (left
arrow) and E (right arrow) in screenshots. Doors dim to `_alpha` 22 while
their host platform is item-gated away, full ~80 when the host exists.
(Padlocked rule-gated variant skipped — no `gate_rules` in the preset, per
your "skip unless cheap".)

## 3.3 Background — full-stage coverage on wide builds

Finding: DJ's grid-art instance is **UNNAMED on the timeline** —
`_root.background` never referenced it (even DJ's own
`_root.background._y = 400` in the hero load handler is a silent no-op!),
so scaling/tiling the original is impossible from AS, and dynamic clones
would render ABOVE gameplay (dynamic depths stack over timeline content).
Implemented instead: a flat paper-toned fill (0xFAF2E8) drawn inside the
CONTAINER at depth 50 (below our blocks at 6000+, and the container itself
is timeline-below the hero/header, so it can never cover gameplay),
spanning x∈[238, Stage.width+2] for the full level height; redrawn per
configure. On 240 builds it's skipped. Verified on the wide Ruffle build:
the 240..600 strip is covered, hero/platforms/ghost/door render above it.
A grid-line texture to blend with the left strip's art is possible polish
if the user wants it (~250 line strokes, drawn once).

## 3.4 Item-gated ghosts

Gated-absent platforms now show a 60×13 translucent rect (blue `#5B9BD5` /
brown `#A0784F` at alpha 24) at the platform slot — a SEPARATE `_root`
drawing clip, so the parked real block stays un-catchable. **Gated swept
blues' ghosts ride the live x(t) triangle wave** (same `sweepX` and
`regionTick` as the real mover, so the reveal is seamless). Broken browns
are not ghosted (they're present-but-broken, a different state from
gated-absent — matches your "do NOT ghost those" naturally). Verified:
brown ghost at the column top pre-grant; mover ghost sweeping at the screen
edge in the region_4_2 tour shot.

## Verification matrix

| Check | Ruffle | browser-WASM | native |
|---|---|---|---|
| Full contract sequence (region_4_4 fixture) | PASS | PASS | PASS |
| Ping-pong swaps + revisit dedupe | PASS | PASS (2 sendLocations / 5 swaps) | n/a (EI) |
| 3-region tour (3_3→4_3→4_2), zero phantom events | PASS | — | n/a |
| Ghost + dimmed door (pre-grant) | screenshot | — | trace |
| Full door + arrow (W and E) | screenshot | screenshot (W) | trace |
| Collected-coin dim in place | screenshot | trace | trace |
| Wide bg fill | screenshot | — | trace |

(The browser tiers share the page shim and showed identical event traces
throughout; per-element screenshots were taken on whichever tier was
cheapest to drive at that moment.)

## For your hand-play pass

The in-app one-click verify you offered would be welcome on: arrow glyph
legibility at real size, the bg fill tone against the grid art, ghost alpha
(24) readability, and whether collected-coin-at-25 reads as "done" vs
"broken". All four are one-line constants in Loader.as — tell us numbers
and we re-cut the bin same-day.
