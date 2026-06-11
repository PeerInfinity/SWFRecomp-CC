# Doodle Jump physics measurements for Archipelago-CC (2026-06-11)

**Request:** `Archipelago-CC/NewDocs/plans/procedural-generation/dj-physics-measurement-spec.md`
(bounceDemo `'dj'` physics profile needs measured constants + structural semantics).
**Harness:** `ruffle-tests/tests/swfs/_swfbridge/livetest/dj_probe/Measure.as` (+
`build_measure.sh`, `parse_measure.py`, `finalize_measurements.py`) — a physics
sibling of the feasibility `Probe.as`, 9 experiments, run on graphics-native
(headless) and Ruffle (ground truth).
**Delivered:** 15 per-run JSON traces + `dj_constants_summary.json` to
`Archipelago-CC/NewDocs/plans/procedural-generation/dj-measurements/`.

## Measured constants (raw, 20 ticks/s, px/tick)

| Quantity | Value |
|---|---|
| Header fps / Ruffle-measured | 20.0 / 20.02 Hz |
| Gravity | +4 px/tick² (same rising/falling) |
| Terminal fall | 22 (no rising cap; jetpack hit −95.3) |
| Plain bounce | vy=0 on hit tick, −28.3 next (= −17·1.9f+4); apex 114.1 px |
| Spring | −64; apex 544 px (confirmed by a natural spring under Ruffle) |
| Brown break | bounces WITHOUT zeroing vy: vy−32.3+4 (−6.3 at terminal); breaks same tick; debris falls 8 px/tick forever and stays landable |
| Air control | flat ±10 px/tick, no vx state, both keys cancel, instant stop |
| Wrap | x−23>240 → 0; x<−23 → 240 (entirely-offscreen, instant) |
| Catch | feet point-tests at x±23, 1-tick lookahead vs 60×40.15 bbox; half-span 53; no snap (feet rest 7.5–19.55 px above bbox top); no tunneling |
| Scroll | pre-move hero y<185 while rising → container scrolls; world_y = screen_y − container._y |
| Blue mover | ±5 px/tick uniform, local x turns 195/15, period 72 ticks, starts 0 moving right (deterministic, NO RNG); no velocity inheritance |
| Jetpack | sustained net −1 px/tick² × exactly 100 ticks |
| Spacing | next block 55.15 px above prev (+17/20 for powerups); spring prob 1/(15−score/2000) rises with height |

## Runtime finding (this repo)

**Graphics-native does not run `onClipEvent(enterFrame)` of nested timeline
children of `attachMovie`'d clips after an injected-AS `gotoAndStop`** — the
forced-blue block's inner mover (cloud frame 3, child "aaa", `this._x += ac`)
and the brown frame-4 debris child never tick natively, while Ruffle runs them
(and browser-WASM has the separate `be332528c` fix). Everything else measured
was **byte-identical per tick** native vs Ruffle (freefall, launch, bounce,
spring, keys/wrap, jetpack, catch). Not fixed here — measurement used Ruffle
for the affected experiments per the spec's "Ruffle wins" rule.
