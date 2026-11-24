# N: level-1 trap-switch stroke, exit-door panels, L2/L4 browser replay (2026-11-23)

One-task session after `n-browser-pfx` (`n-browser-pfx-report.md` §5), launched by the s26 fan-out coordinator.
Baseline: master `9bd4ca1e7`. Landed: `d70f2c0aa` (recompiler fix + two `regression/` fixtures) and the docs commit
that carries this report.

**Summary**
- **Goal 1, level-1 trap switch (27 px): NOT OUR BUG (§1).** The brief's "1-px stroke coverage / quantisation" premise
  was wrong. Spliced alone, at any scale and subpixel offset, the switch matches the exporter at **0 px**. Ruffle's
  half-coverage comes from its **tessellation cache** (`core/src/tessellation_cache.rs`, added 2026-07-16):
  - Ruffle reuses a shape's tessellation for any draw within **2×** of a cached scale.
  - N draws char 525 → 188 at 7.5% (locked-door trigger) and at 5% (trap switch).
  - The 5% instance reuses the 7.5% tessellation, so its 1-twip strokes come out **0.67 device px**.
  - Flash rasterises each draw at its own matrix (min 1 px). Per the Flash-over-Ruffle ruling we do **not** replicate
    it; no renderer change.
- **Goal 2, exit-door panels (36–64 px): FIXED (§2), `d70f2c0aa`.** This was a recompiler draw-order bug, not
  animation phase or subpixel:
  - Within a style layer we emitted strokes in **record order**.
  - Ruffle (and Flash) draw them in **line-style-id order**.
  - N's panel (char 202) strokes an inner rect with style 2 before the style-1 outer rect that shares its right edge.
  - Splice: 18–36 px on every frame from the opening → **0 px on all 40 frames**.
  - N level-0 shots: the door class is gone (§2.3).
- **Goal 3, seeded browser replay of L2/L4 (§3):**
  - L4: tick-exact (984 NF + 56 ND lines, 0 diffs).
  - L2: all 1033 NF ticks identical. The probe's own `frame=` counter is 1 behind after the death. Likely the
    FRAMELOCK wall-clock slack, not a runtime divergence.
- **CI:** graphics/full/images run `45300086369`: **0 trace regressions, 0 image regressions**, both new fixtures
  pass (§4). The results merge into master and the Pages
  deploy are left to the s27 coordinator, at its request: its wave-1 also touches the recompiler.

## 1. Trap switch: Ruffle's tessellation cache, not our stroke rule

**Splice.** I spliced chars 188/524/525 (`debugDoorTriggerMC`) into a minimal SWF (scratch only; N is not open
source):
- attached into a `createEmptyMovieClip` buffer at N's trap scale, `_xscale = tiles.xw*0.4167 = 5%` (net ×0.417);
- `gotoAndStop("exit_closed")`;
- compared native graphics with the exporter (`WGPU_BACKEND=vulkan`) at tolerance 0.

Result: **0 px** at scales 4/5/6/6.25/7.5% and at offsets .0/.25/.3/.5/.75. Our 1-px hairline floor (`hairline_restage`)
already matches Ruffle's `width.max(1/scale)` for a lone instance.

**Two instances.** N's locked-door branch scales the same trigger clip by `r*1.5` (7.5%), and the trap branch by `r`
(5%). Ratio 1.5 < 2, so the instances share one Ruffle tessellation.

| splice | exporter vs native |
|---|---|
| 5% drawn first, 7.5% second | 77 px (the 7.5% one reuses the 5% mesh: 1.5 px strokes) |
| 7.5% drawn first, 5% second | 31 px. Ruffle's 5% glyph is **`4c4c4c`**, the exact value n-browser-pfx §4 measured in N |

Ruffle's code path (exporter at `0ddd12b6a`):
- `graphic.rs:259` computes `current_scale` from the draw matrix;
- `get_or_retessellate_handle` calls `find_near_and_touch`, which matches within `RETESSELLATION_SCALE_THRESHOLD = 2.0`;
- the tessellator's `min_screen_width = 1/scale` uses the **cached** scale, not the current one.

So a hairline's on-screen width is `current/cached` px (0.5–2 px), depending on which instance drew first.

**Disposition.**
- Flash has no such cache. Its hairline is 1 px per draw; Ruffle's own `transform_width` comment says so.
- This is a Ruffle approximation, so we keep the Flash rule and leave the 27 px. A Ruffle-made golden is not a Flash
  oracle here.
- It is not a corpus test diff, so it gets no `RUFFLE_VS_FLASH_DIFFERENCES.md` entry.
- **Prune criterion:** if a future Ruffle drops or narrows the cache, the 27 px should vanish with no change on our
  side.

**Fixture** `regression/avm1_hairline_scaled_instances`:
- An original equivalent shape (12-px square, 1-twip outlines, inner half-rect) at ×8.333 in an exported sprite.
- Attached at 5% (subpixel origin), 12.5%, 31.25% and 5% again.
- The scales are **more than 2× apart on purpose**, so the exporter golden is also the Flash rule.
- Red check: with `hairline_restage` short-circuited it fails by 714 px. Green at tolerance 0 in graphics; trace
  passes in no-graphics too.

## 2. Exit-door panels: strokes must draw in line-style-id order

### 2.1 Isolation

I spliced `debugExitMC` (530 → 528 frame, 202/203 panels, 31 frames; its StartSound stripped) and attached it at
N's `r*2` = 24%, then `gotoAndPlay("exit_opening")`. Compared over 40 frames:

- Frames 1–3 (closed): 0 px.
- Then **18 or 36 px on every frame**, always one or two columns at the **left panel's right edge**, tracking the
  slide (x 86 → 75).

Shape 202, record order:
1. inner rect `(-126..307, -444..445)`, fill 1, **line style 2** (`cccccc`);
2. outer rect `(-313..307, -620..620)`, **line style 1** (`333333`).

Both strokes cover x=307. Ruffle shows `cccccc` on that column; we showed `333333`.

### 2.2 Cause and fix

- Ruffle `render/src/shape_utils.rs` `flush_layer`: *"Paths are drawn in order of style id, not based on the order of
  the draw commands."* Each layer's edges are collected per style id and emitted fills-then-strokes, both in id order.
  Flash's painter's order is the same, which is why Ruffle documents it.
- Fills already followed it (`emit_layer_fills`, sorted by layer and fill id). The stroke loop in
  `SWFRecomp/src/swf.cpp` walked `paths` in record order.
- **Fix:** the loop iterates a `stable_sort` of path indices by `(line_style_list, line_style)`. Layers stay ascending,
  as `emit_layer_fills` needs. Within one style, record order is kept. Morph start/end lockstep and the hairline run
  table are appended inside the same loop, so they stay consistent.
- Not changed: Ruffle also *joins* a style's segments into one path, which affects join geometry at shared vertices.
  No measured row needs it.
- **Splice after the fix: 0 px on all 40 frames.**

**Fixture** `regression/avm1_stroke_style_id_order`:
- An original shape: inner rect stroked style 2 (red) first, outer rect stroked style 1 (blue) second, sharing the
  right edge.
- A second instance does the same with 1-twip hairlines (the N case).
- The exporter golden shows red on the shared edge. Red without the fix: **716 px**. Green at tolerance 0 in graphics;
  passes in no-graphics.

### 2.3 Pricing

**Static scan.** I wrote a parser of every DefineShape1–4 / DefineMorphShape1–2 in all 5220 corpus SWFs. It flags a
shape when, within a layer, a lower line-style id gets edges after a higher one: those are the only shapes whose
output changes. Hits: `avm1/movieclip_hittest_shapeflag` (no image), `from_shumway/3_joystick`,
`from_shumway/acid/acid-scale`, `from_shumway/acid/acid-small`, `visual/simple_shapes/strokes/scale`, plus the new
fixture.

**A/B on the image rows** (temporary env switch back to record order, same build):

| row | record order | id order |
|---|---|---|
| 3_joystick | pass, 0 outliers | pass, 0 outliers |
| acid/acid-scale | pass, 0 | pass, 0 |
| acid/acid-small output.01 / .05 | pass, 2496 / 2190 outliers (limit 3000) | pass, **507 / 426** |
| simple_shapes/strokes/scale | fail, 19287 | fail, 19287 |

N level-0 native pixel pass with the fix. Same recipe and shots as `n-gold-streaks-report.md` §3: native F(k+1) vs
exporter best of k−2..k, delta > 24.

| shot | 205 | 487 | 609 | 766 | 998 | 1237 | 1378 | 1560 | 1684 | 1776 |
|---|---|---|---|---|---|---|---|---|---|---|
| px (n-gold-streaks) | 24 | 26 | 27 | 31 | 27 | 62 | 72 | 94 | 61 | 61 |
| px (now) | 28 | 24 | 36 | 37 | 29 | 24 | 38 | 53 | 64 | 51 |
| of which door box (552–624, 480–504) | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 28 | 0 | 0 |

- Shots 1237/1378: the door class is gone.
- Shot 1560: the 28 px in the door box is the post-level ragdoll standing in it (the known thin-stroke class).
- 1684/1776 are level 1. The trap switch's 27 px remains by design (§1).
- The rest is the fps counter (6–24 px, wall clock) plus the same ~12 px of scattered single-pixel edges.
  Shot-to-shot noise is ±5 px plus fps.

## 3. Seeded browser replay, levels 2 and 4

Build: `EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000 build_test.sh flasharchive/N_drive wasm --graphics` plus
`deploy_example.sh … --no-index --graphics`, with `START_LEVEL=k AUTOKILL=true OBJHASH=true OBJDUMP=true FREEZE=""` and
the `routes_ep0.txt` line. Exporter `-f 1400`. Trace via `n_drive_compare.py ours` (SwiftShader, function only).

| level | NF ticks (exporter ∩ browser) | NF diffs | ND diffs |
|---|---|---|---|
| 4 (drone, death + exit) | 984 | **0** | 0 of 56 |
| 2 (thwumps, death + exit) | 1033 | **0** (incl. `h=`/`o=`) | 6 of 155: `frame=` only |

**The L2 `frame=` skew.**
- `run->dead` is at frame 292 / tick 115 in both players.
- `dead->retrywait` is exporter frame 332 vs browser 331, both at tick 155. Every later phase line is shifted by 1.
- `frame` is the probe clip's own enterFrame counter. Under FRAMELOCK, `preFrame` grants
  `APP_GAMETIME_REMAINDER = 1.5 ticks` of slack, but RunApp still reads `getTimer()`.
- So a SwiftShader frame that spends more than half a tick inside RunApp (the death frame spawns the ragdoll) can run
  two game ticks in one probe frame. The exporter's clock barely moves.
- Not proven (no per-frame tick log taken). It is consistent with:
  - every per-tick NF line matching;
  - L4's death not showing it.
- **Next step if it matters:** set the slack to exactly 1 tick (`REMAINDER = TICKLEN`) or log `frame` beside each NF.

## 4. CI grading

Run `45300086369` (`d70f2c0aa`, graphics / full / images=true). Baseline: the coordinator's `005bea42a` graphics run
on `origin/ruffle-test-results`.

Results commits: old `df7729df2` (built at `005bea42a`), new `da51f878f` (built at `d70f2c0aa`).

**Trace** (`scripts/corpus_status_diff.py df7729df2 da51f878f --stem results_graphics`):
- Intersection 4722 tests: pass 4422 → 4422, ruffle_matched 262 → 262, output_mismatch 38 → 38. Effective 4684 → 4684.
- **0 regressions, 0 gains, 0 other status moves.**
- New: `regression/avm1_stroke_style_id_order` and `regression/avm1_hairline_scaled_instances` both pass.

**Images** (`scripts/image_status_diff.py df7729df2 da51f878f`):
- pass 592 → 592, fail 41 → 41, skip 3 → 3, ignored 6 → 6.
- **0 regressions, 0 gains, 0 band moves.** No reason changes, no new crash-class skips.
- Both new fixtures are `[output] pass`.
- Expected per §2.3: acid-small's outlier drop stays inside a passing comparison, and strokes/scale's 19287 outliers
  are unchanged.

No-graphics leg not run: the change is recompiler emission, so both modes see the same generated C, and the
fixtures pass locally in no-graphics. The coordinator owns the next combined grading run.

## 5. Next blocker / next slice

1. **Level-1 trap switch: closed as a Ruffle artifact (§1).** Nothing to do unless Ruffle changes its cache.
2. **N native residual is now fps counter + ~12 px of scattered edge pixels + the ragdoll thin-stroke class** (shot
   1560). The ragdoll is the remaining real class. It is drawing-API strokes under a scaled clip, so splice it the
   same way (memory `n-thin-strokes-no-min-width`).
3. **Optional probe hygiene:** pin FRAMELOCK's slack to one tick so browser `frame=` stays exact under SwiftShader (§3).
4. Strokes of one style are still emitted per record rather than joined into one path (Ruffle joins them). It only
   matters for join geometry where two records of the same style meet. No measured row needs it.

## 6. Tooling / traps

- **Splice tools** (scratch, reusable pattern):
  - `extract2.py <swf> <exportName>` walks a sprite's PlaceObject char ids recursively and pickles every needed
    definition.
  - `mk.py` attaches the export into a buffer, with per-instance `x:y:scale` via `EXTRA=` and `ORDER=rev`.
  - `run_native.py` builds a 3-frame splice in ~4 s (ccache), so a tolerance-0 sweep costs seconds per point.
- **When one instance matches the oracle and the game doesn't, add the game's OTHER instances of the same character**
  (memory `n-play-game-click`, splice + stagger). Here the missing ingredient was a second scale, not a second time.
- **Ruffle's tessellation cache makes scaled-stroke widths depend on draw history.** Any exporter golden with two
  instances of one stroked shape at scales within 2× is order-dependent and not a Flash oracle.
- Exporter frames for >10 frames are zero-padded (`00.png`); `run_native.py` captures only ticks 1–16 unless you pass
  `--capture-ticks`.
- A `verify_output.py` run keeps no actual PNG unless `--images --image-out-dir` is given and the comparison fails.
  Use `run_native.py` for PNGs you want to keep.
