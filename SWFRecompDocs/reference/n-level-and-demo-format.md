# N — level data & demo (input replay) format

Reference for the recompiled **N** ("the way of the ninja", Metanet) substrate.
Decoded from the JPEXS decompile of `N.swf` and verified byte-identical on Ruffle
and SWFRecomp native. Companion to
`SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md` (how it was decoded)
and the JS model in `ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/gen/`
(`nLevel.js` = level codec, `nDemo.js` = demo codec).

---

## 1. Level string

A level is one string handed to N's own `App_LoadLevel_Raw(levStr, cb)`:

```
levStr = mapStr "|" objStr
```

`|` is the map/object separator (never appears in either half). Codec:
`nLevel.js` `encode(level)` / `decode(str)`.

### 1.1 mapStr — the tile grid

- Grid is **31 columns (X) × 23 rows (Y) = 713 tiles**. Every level's `mapStr` is
  exactly 713 chars.
- **Column-major, X outer / Y inner**: the char for cell `(mx, my)` is at string
  index `mx*23 + my` (`mx` 0..30, `my` 0..22).
- **Tile state = `charCode - 48`** (`CHAR_PAD = 48`): `'0'` = empty (state 0),
  `'1'` = full solid (state 1). Higher states are the slope/half family and use
  chars `':' ';' '<' '=' …` (charCodes ≥ 58).

Tile state codes (`charCode-48`):

| State | Meaning | State | Meaning |
|------:|---------|------:|---------|
| 0 | empty | 14–21 | 22° slopes (steep S / broad B) |
| 1 | full solid | 22–29 | 67° slopes (S / B) |
| 2–5 | 45° slopes (pn/nn/np/pp) | 30–33 | half tiles (down/right/up/left) |
| 6–9 | concave 45° | | |
| 10–13 | convex 45° | | |

The generator so far uses only 0 (empty) and 1 (full).

### 1.2 objStr — the objects

Objects joined by `"!"`; each is `"<type>^<p0>,<p1>,…"` (`^` separates the type
from its comma-joined numeric params). Empty `objStr` = no objects. Params are
decimal; floats occur (e.g. launchpad direction `0.707106781186547`).

| type | name | params |
|-----:|------|--------|
| 0 | GOLD | `x, y` (optional bonus time; does NOT gate completion) |
| 1 | BOUNCEBLOCK | `x, y` |
| 2 | LAUNCHPAD | `x, y, nx, ny` |
| 3 | TURRET | `x, y` |
| 4 | FLOORGUARD | `x, y, dir` |
| 5 | PLAYER | `x, y` (spawn) |
| 6 | DRONE | `x, y, movetype, isChaser, weaptype, dir` |
| 7 | ONEWAYPLATFORM | `x, y, dir` |
| 8 | THWOMP | `x, y, dir` |
| 9 | TESTDOOR | `x, y, vert, isTrap, doorI, doorJ, isLocked, dI, dJ` |
| 10 | HOMINGLAUNCHER | `x, y` |
| 11 | EXIT | `doorX, doorY, switchX, switchY` |
| 12 | MINE | `x, y` |

**Completion mechanic**: the EXIT is a **switch** + a **door**. Touch the switch
first → it opens the door → touch the open door → `App_LevelPassedEvent`. Gold is
irrelevant to completion.

### 1.3 Coordinates (pixels ↔ cells)

Object params are **free pixel coordinates** (not cell indices). The playfield has
a 1-tile solid border, so:

- **Cell `(mx, my)` center = `(mx*24 + 36, my*24 + 36)` px** (`nLevel.cellToPixel`).
  The `+36` = a half tile (12) + one border tile (24). Tile size = 24 px.
- Top surface of a floor row `fr` = `(fr+1)*24` px. A grounded body (player radius
  10) rests with its **center at `y = (fr+1)*24 − 10`** (e.g. floor row 14 → y=350).
- Collision radii for the distance test `dist < r_obj + r_player` (player r = 10):
  door r = 12 (`tiles.xw`), switch r = 6 (`tiles.xw*0.5`).

### 1.4 Example (built-in "get down", abridged)

```
…713 map chars…|5^156,108!11^396,564,396,420!0^612,108!0^636,108…
   spawn (156,108) ─┘        exit door(396,564) switch(396,420)  gold…
```

---

## 2. Demo (input replay) format

A demo is a recorded input stream N replays deterministically via
`game.LoadDemo(demoStr)` + `game.StartDemoPlayback()`. The player reads it through
`game.GetInputState(inList)`; `game.GetTime()` is the tick counter. Codec:
`nDemo.js` `encodeDemo(perTickMasks)` / `decodeDemo(str)`.

```
demoStr = "<tickCount>:<e0>|<e1>|<e2>|…"
```

- **One 4-bit input mask per game tick**: `L=1, R=2, J=4, JTRIG=8`
  (JTRIG = jump *rising edge*; set it only on the first tick a jump is pressed,
  then hold `J`). Masks OR together (e.g. run-right + start-jump = `R|J|JTRIG` = 14).
- **7 ticks packed per list entry**, as nibbles at shifts 0, 4, 8, 12, 16, 20, 24
  of a 32-bit integer (`entry = Σ mask_k << (4·k)`, k = 0..6). The 8th nibble
  (shift 28) is unused — hence 7, not 8, per entry.
- `tickCount` is the total number of ticks; the last entry is zero-padded.
- Canonical constant: "hold right" for a full 7-tick entry = `2·(16⁷−1)/15` =
  **35791394**. So `"28:35791394|35791394|35791394|35791394"` = hold right 28 ticks.

Separators: `:` (count↔entries) then `|` (between entries). Both are safe against
the level string's chars.

---

## 3. Input resolution — the key question

**Input can change on EVERY game tick. One tick is the maximum resolution; there
is no finer control, and no coarser constraint.** The 7-ticks-per-entry packing is
purely a storage detail (nibbles in a 32-bit int) — it does **not** reduce
resolution. Verified: a demo of 10 distinct per-tick masks encodes and decodes
byte-exactly.

Our loader drives **exactly one `game.Tick()` per frame**, so demo tick N = game
tick N = one input mask. At N's native 30 fps a tick is 1/30 s; headless it's
deterministic (wall-clock independent).

**So we are already at maximum input resolution** — every tick in our generated
demos is explicitly specified (`hold-right`, `run + K-hold jump`, etc.). The wide
safety margins in the generator are **not** a resolution limit. They come from:

1. **Sparse calibration.** `nMotion_calib.json` sampled only 4 hold values
   (`K ∈ {3,8,15,30}`) × 4 entry speeds. `apexHeight`, `airtime`, `airDist`, and
   the arc are **interpolated** between those points, so we pad (`GAP_MARGIN` 36px,
   `CLEAR` 12px) to cover interpolation error.
2. **Conservative construction.** Full-speed-only jumps, whole-tile platform
   padding (`INTER`), envelope caps below the true maximum.

Because we control every tick, the *achievable* precision is ~one horizontal step
per tick (≈ `vx` px, ≤ 5 px at full speed) plus tile snapping — far tighter than
today's margins. Closing that gap needs **denser measurement**, not finer input.

---

## 4. Batch tests to tighten margins (before tighter courses)

Fixed level layout, minor per-tick input variations, record telemetry (the
`NF`/`NEV` lines → `nTelemetry.js`), and read the fine sensitivity. Three sweeps,
in priority order:

1. **Dense hold sweep — `K = 1..30` at full entry speed.** Replaces the 4-point K
   grid with the exact `apexHeight(K)`, `airtime(K)`, `airDist(K)`, and full arc for
   every hold. Directly removes the interpolation error that `CLEAR`/`GAP_MARGIN`
   pad against. *Highest value.*
2. **Jump-trigger timing sweep.** Same level, vary the run-up tick count by ±1..±3
   (trigger the jump one tick earlier/later). Expected landing shift ≈ `vx` per tick
   (~5 px). Confirms we can place the takeoff to ~5 px and quantifies how much of the
   margin is real model error vs. timing slack.
3. **Dense entry-speed sweep.** Run-up ticks `1..45` (→ entry vx 0.15..5) at a fixed
   hold, to densify the entry-speed axis of `airDist`/arc.

Each sweep is a batch of probe levels (one per variation) run through **one** Ruffle
QUEUE session and parsed per-level — the same rig as `calibrate.mjs`
(`nProbe.buildProbeMatrix` already accepts arbitrary `runUps`/`holds` arrays, so a
dense sweep is `buildProbeMatrix([45], [1,2,…,30])`). Output: a denser
`nMotion_calib.json` → shrink `GAP_MARGIN`, `CLEAR`, `INTER`, and the envelope caps,
enabling tighter-packed courses with a small, *measured* safety margin instead of a
wide guessed one.

**Acceptance stays the same:** real N via Ruffle (`nVerify`) is the final judge;
denser calibration just lets construction propose tighter geometry that still passes.

---

## 5. Where the code lives

`ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/gen/`:
`nLevel.js` (level codec + model), `nDemo.js` (demo codec), `nMotion.js` +
`nMotion_calib.json` (measured motion model), `nReach.js` (reachability/plans),
`nGenerate.js` (generators), `nProbe.js` + `nTelemetry.js` + `calibrate.mjs`
(measurement rig), `nVerify.js` (Ruffle acceptance gate).
