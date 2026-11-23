# N: gold-pickup "residue" streaks — closeout (2026-11-22)

One-task session, successor to `n-play-game` (`SWFRecompDocs/plans/n-play-game-report.md`
§6.1 lead 1). Baseline master `900815332`.

**Result: not a bug in the browser build.** The vertical yellow streaks are
N's own coin-pickup animation, and they clear on their own. The earlier
"streaks stay" observation came from a single SwiftShader screenshot taken
about 1 s after the pickups. At SwiftShader frame rates the 29-frame pickup
animation takes several seconds, so that screenshot caught it mid-animation.
It is **not** a regression from `161ecf124`.

Fixturing the coin surfaced one real, separate bug in **graphics-native**
image capture (OFFSCREEN only). It is fixed and pinned by a new fixture
(§5).

## 1. Repro

- Browser build of master (`build_test.sh flasharchive/N wasm --graphics --clean`,
  deployed to `docs2/examples/flasharchive/N`).
- Drive: `tools/divergence/game_drive/n_click_probe.py flasharchive/N
  "click@690,142;click@576,100;wait@12;hold@Space,1;hold@ArrowRight,3;wait@1;wait@5;wait@10"`.

| screenshot | after the run right | streaks |
|---|---|---|
| `wait@1` | ~1.5 s | 2 streaks, ~35 px above the collected coins |
| `wait@5` | ~7 s | gone |
| `wait@10` | ~17 s | gone; the collected coins do not come back |

A longer drive (left 4 s, right 6 s, jump, left 3 s) collected dozens of
coins. Every streak cleared within a few seconds.

## 2. Which clip the streak is

The coin is `debugGoldMC`, char 570, a 30-frame DefineSprite.
`GoldObject` creates it with `gfx.CreateSprite("debugGoldMC", LAYER_OBJECTS)`,
which does `spritebuffer<N>.attachMovie(...)`: a **non-root** attach into a
`createEmptyMovieClip` buffer. `Init` sets `_xscale = _yscale = r` (≈6),
`_visible = true` and `gotoAndStop("NOT_COLLECTED")`. `Dissapear` does
`mc.gotoAndPlay("COLLECTED")`.

| frames | content |
|---|---|
| 1 `NOT_COLLECTED` | `stop()`, coin shape 565 at depth 5 |
| 2–4 `COLLECTED` | flash rectangle 566 (scaled ×25 / ×6.49) + pickup sound |
| 5–15 | **morph 568**: the coin square → a tall thin bar from −11000 to −4000 twips (above the coin) |
| 16–28 | **morph 569**: that bar → a small dot at the top |
| 29 | shape 566 at identity (tiny bar) |
| 30 | remove depth 1, `this._visible = false`; then loops to frame 1 while hidden |

**The streak is morph 568/569, the authored "coin flies up" effect.** Ruffle's
own attract demo shows the same yellow streak under the ninja mid-animation.

## 3. Regression or not

Not a regression. I bisected by reasoning plus fixtures rather than by
rebuilding old commits:

- `161ecf124` moved attached clips (coins included) onto the shared CI pump.
  The pump skips only `natural_oneshot` (`pfx*`) clips, and those keep their
  counter path. The coin now plays its real timeline (placement tags +
  DoActions), which is what Flash does.
- Fixture A (scratch only): N's real chars 565–570 extracted into a minimal
  SWF, the coin root-attached and then non-root-attached into a
  `createEmptyMovieClip` buffer, ×50 scale, with N's
  `_visible false→true` / `gotoAndStop` / `gotoAndPlay("COLLECTED")` sequence.
  In the browser build the streak rises, shrinks and is gone by frame 29, as
  in the Ruffle exporter frame-by-frame. Per-instance morph ratios render in
  the browser now, so the "attached morphs draw at ratio 0" note in memory
  `n-laser-is-frozen-particle-sprite-not-drawing-api` no longer applies to
  shared-pump clips.
- Trace: `_currentframe` / `_visible` for 40 frames match the Ruffle exporter
  in no-graphics, graphics-native and the browser.

## 4. Root cause

None in the browser. The brief's premise came from a mid-animation sample.

## 5. Bug found and fixed: hidden root-attached clips drawn in captured images

Fixture A in `--mode=graphics` matched Ruffle until frame 30. From frame 31
on, the **coin square reappeared**, even though `_visible` traced `false`. A
1-frame attached square with `_visible=false` reproduced it.

- **Cause:** `tagRerenderFrame` is the OFFSCREEN per-tick image-capture
  render. Its root-attached `child_mc_cache` pass composed and drew every
  root-attached clip **without** checking `mc->visible`. `tagShowFrame`'s pass
  goes through `render_attached_child`, which returns on `!mc->visible`. A
  `ZZDBG` print confirmed the live render skipped the clip (`vis=0`), so only
  the capture drew it.
- **Fix:** `tag.c` `tagRerenderFrame`: `if (!mc->visible) continue;`. This is
  OFFSCREEN-only code, so the browser and no-graphics builds are unaffected.
- **Fixture:** `regression/avm1_attached_clip_hidden_capture`. Three
  root-attached squares: a red coin-like 3-frame loop that hides itself, a
  blue one hidden and then re-shown, and a green control. The trace and
  `output.expected.png` come from the local Ruffle exporter at `0ddd12b6a`
  (default high quality).
  - Graphics: image **FAIL, 3200 outliers** without the fix, **PASS, 0
    differing pixels** with it. The trace passes both ways (an image-only
    bug).
  - No-graphics: PASS.
  - Fixture A's frames 31 and 40 went from the coin square (2500 px) to blank.

## 6. CI / Pages

- **CI:** CI-observable in graphics **images only**; trace results are
  unchanged. Handed to the s25 coordinator, who folds this SHA into its next
  grading run (interim 4 or the final). No CI run was dispatched from this
  session, to avoid racing on `ruffle-test-results`.
  **Result:** s25 FINAL grading run at `697669e5f`, which includes `2afd3e36d`
  (graphics `45078991452` + no-graphics `45079002150`):
  `regression/avm1_attached_clip_hidden_capture` PASSES on both image and
  trace, with 0 regressions corpus-wide.
- **Pages:** no deploy needed. No browser-visible code changed, and
  `tagRerenderFrame` is `#ifdef OFFSCREEN_RENDER`.

## 7. Next blocker (next slice's line)

I drove N into episode 00 level 0 in both builds. Ruffle was driven through
`docs2/examples/flasharchive/N_ruffle/` and needed a focus click before the
menu clicks register; the scratch driver is described below. Our build
differs from Ruffle in three visible ways:

1. **Tile colour.** Ruffle draws the walls in blue-grey `0x797A88`; ours are
   the raw dark grey (#333).
   - `TileMapCell` does `new Color(mc).setRGB(7960968)` on each attached
     `tileMC`.
   - `d83fbab22` added dynamic-clip colour transforms for Drawing-API clips,
     but a `Color` on an attachMovie'd *sprite* clip is evidently not reaching
     the browser renderer.
   - This is the most visible difference and the **next slice**.
2. **The time bar is missing.** Ruffle draws a purple bar with a seconds
   counter at the top. This is `n-play-game` lead #4, now confirmed against
   Ruffle.
3. **The level-name text is missing.** Ruffle shows "Episode 0 Level 0: the
   motherlode" at the bottom; ours shows nothing.

Items 2 and 3 are probably one HUD/text issue on attached GUI clips.

The comparison drivers are scratch-only and not committed:
- `n_click_probe.py` for our build.
- A small Playwright script for the Ruffle page. Load
  `examples/flasharchive/N_ruffle/index.html`, wait 10 s, click inside the
  player once to focus it, then click at stage coordinates offset by the
  `#c` box.
