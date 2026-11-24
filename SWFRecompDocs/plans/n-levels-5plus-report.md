# N "levels 5+": episodes 1–2 native vs the oracles, the textWidth tab metric, and unit-scale EditText box snapping (2026-11-24)

One-task session after `n-l2l4-pixel-pass` (`n-l2l4-pixel-pass-report.md` §7), launched by `s27-coordinator`.
Brief: `SWFRecompDocs/plans/session27-fanout-reports/n-levels-5plus-prompt.md`.

**Summary**
- **Brief §Goal 1 premise was wrong: episode 0 has only levels 0–4.** `START_LEVEL=5` wraps to level id 0 (the probe
  now traces `ND level id= ep= lv=`). "Levels 5+" was taken to mean the next ten levels: **episodes 1 and 2**. New
  n_drive knobs `START_EPISODE` and `AUTOEXIT` walk a whole episode in one run (§1).
- **Episodes 1 and 2, native vs exporter, frame-locked (§2):** telemetry (`NF`/`ND` incl. `h=`/`o=`) is
  **byte-identical** on both (1341 and 1248 lines; every death, exit and level load lands on the same frame).
  Gameplay pixels are at the floor (≤98 px/frame on ep 1, ≤54 on ep 2). The only large diffs (2–5.7k px) are the
  menu / level-load / retry console screens, which are the known tab-stop disagreement: the exporter uses Ruffle's
  2.7·size stops, and **the Flash oracle puts ours 3–4× closer than the exporter** (§3).
- **No new "ours" class in gameplay.** Against **Flash**, native and the exporter are equally far off (1.3–2.8k px),
  all of it ONE class that both Ruffle and we get wrong: **Flash pixel-snaps thin strokes** (hairlines and 1-px lines
  land solid on one pixel; 2-px lines snap to pixel edges). N's console box, gold-coin outlines and one-way platform
  edges all show it. Pinned with a Flash golden, parked as the next slice (§4).
- **Goal 2, tab metric (§5): fixed.** `ng_shared.c`'s textWidth/autoSize/maxhscroll metric now uses Flash's default
  stops: `T = 2·(⌊asc⌋+⌊desc⌋)` counted from the field edge, where the origin includes the gutter, leftMargin,
  blockIndent **and indent**. textWidth excludes the margins. The painter gained explicit `TextFormat.tabStops` (from
  the text origin; a tab past the last stop does not advance) and the same margin/indent origin. Fixture
  `regression/avm1_edittext_tabstops_metric`, Flash golden (trace + image).
- **Found on the way (§6): unit-scale EditText boxes were never pixel-snapped.** Flash snaps every axis-aligned
  embedded-font box with `trunc((t + 2 twips) / 1 px)`. We only did that for non-unit scales (Ruffle's rule). Fixture
  `regression/avm1_edittext_border_subpixel` (Flash golden): 4956 → 48 px.
- Goal 3 (same-tick self-goto visibility): not started.

## 1. Tooling (n_drive)

- `START_EPISODE=e` (build.sh env): `gamedata.LoadEpisodeNum(e)`, then `START_LEVEL` as before. `search.py` takes
  `E.L` (e.g. `1.3`) or a bare `L` (episode 0).
- `AUTOEXIT=true`: when an attempt's script ends, the probe calls the level's exit object's own `PlayerHitTrigger()` +
  `PlayerHitExit()`. That runs N's real level-passed flow (postlevel → Space → next level). If the scripted attempt
  died, the retry of the same level exits at tick 10. One run walks all five levels of an episode (~2.5k frames).
- Coverage script per level: `40:-|60:R|30:RJ|60:L|30:LJ|60:-` (280 ticks), ×10 attempts.
- Episode survey (`OBJDUMP`, object types per level):

| level | name | object types (N `OBJTYPE_*`: count) |
|---|---|---|
| 1.0 | cavern | gold 12, bounce 2, launchpad 1, drone 2, mine 14 |
| 1.1 | like happy little puppies | gold 69, bounce 4, floor guard 2, one-way 5 |
| 1.2 | little dipper | gold 32, bounce 5, launchpad 2, drone 4, one-way 6 |
| 1.3 | slides | gold 20, turret 1, thwump 1, door 3, mine 6 |
| 1.4 | steps | gold 52, launchpad 3, drone 2, door 1 |
| 2.0 | square stairs | gold 27, bounce 3, drone 2 |
| 2.1 | shaft..s | gold 57, one-way 30, door 5 |
| 2.2 | who's sick of thwumps? | gold 49, turret 1, thwump 4, door 4 |
| 2.3 | chasm | bounce 4, drone 3, door 2 |
| 2.4 | (don't) go for the gold | gold 23, floor guard 1, door 8 |

## 2. Native vs exporter (episodes 1 and 2)

- Recipe: `START_EPISODE=1|2 AUTOEXIT=true OBJHASH=true FREEZE="" build.sh <script>`.
  - Exporter: `WGPU_BACKEND=vulkan exporter -s -f 2700|2900`.
  - Native: `run_native.py --frames 2710` (it builds the binary; the 30 s run cap then trips), then `build/test_run`
    directly with `CAPTURE_TRIGGERS` every 16th frame, in two chunks (the `capture.c` 4096-byte cap).
  - `MAX_FRAMES` is compiled in: build with the full frame count, not a short one.
- Telemetry: byte-identical on both episodes. Events: ep 1 drone kill t=264, exits, steps-level drone kill t=145;
  ep 2 thwump crush t=275, two chasm falls (type 5).
- Pixels (count of max channel delta > 24, native `F(k)` vs exporter frame `k-1`):
  - gameplay: ep 1 4–98 px, ep 2 ≤54 px (fps counter + edge AA, the level-0 floor);
  - menu / load / retry screens: 1.7k–5.7k px, all console text (tab stops) + the console box hairline (§3, §4).

## 3. Flash spot checks

`tools/flash-oracle/run_image.py <dir with test.swf = injected ep1 SWF> --ticks … --max-duration 120`.

| tick | screen | Flash vs native | Flash vs exporter (best of k-3..k+1) |
|---|---|---|---|
| 32 | load console | 1297 | 4157 |
| 640 | retry/load console | 1338 | 4530 |
| 1104 | load console | 1306 | 5545 |
| 304 | gameplay (cavern) | 1498 | 1522 |
| 880 | gameplay (puppies) | 2759 | 2773 |
| 1344 | gameplay (little dipper) | 2071 | 2118 |

- On the console screens ours matches Flash's tab layout. The 1.3k left is the console box (DefineShape2 char 2, a
  300×16 px rect with a 1-twip `#333333` outline): Flash draws each edge solid on one row/col (240/256, 44/344); ours
  and Ruffle split each edge 50/50 over the two pixels it straddles.
- In gameplay native ≈ exporter (25–72 px apart). The shared gap to Flash is the same stroke class: gold-coin
  outlines and one-way platform lines are crisp in Flash, half-coverage in both Ruffle and ours.

## 4. Next slice: Flash thin-stroke pixel snapping (pinned, not implemented)

Flash Player 32, 60×20 px stroked rects (no fill) placed at +0/5/10/15 twips (parked fixture
`SWFRecompDocs/plans/n-levels-5plus-hairline-fixture/`, Flash golden `output.expected.flash.png`):

| line width | +0 | +5 | +10 | +15 twips |
|---|---|---|---|---|
| 1 twip (hairline) | solid on px 10 | 10 | 10 | 10 |
| 20 twips (1 px) | solid on px 10 | 10 | 10 | 10 |
| 30 twips (1.5 px) | 2 px at 60% | AA | AA (3 px) | AA |
| 40 twips (2 px) | px 9–10 | 9–10 | 10–11 | 10–11 |

- Hairlines and 1-px strokes are drawn solid on pixel `floor(edge)`. A 2-px stroke's centre snaps to the nearest pixel
  edge. A 1.5-px stroke is plain AA. Ruffle and ours draw every stroke unsnapped (centred on the edge, AA'd).
- This is the whole remaining gap to Flash on N gameplay and load screens. It is a renderer-wide change: stroke
  tessellation is in shape space (recompiler), and snapping needs device space (runtime). It would move many image
  rows whose goldens are Ruffle-made, so it needs its own slice with an images grading run.

## 5. Goal 2: tab metric + painter tabStops

Flash Player 32 trace of `regression/avm1_edittext_tabstops_metric` ('A' square font, advance 5 px at 10 px,
`T = 2·(175+39) = 428` twips at 10 px):

| field | text | Flash textWidth | before (= Ruffle) | rule |
|---|---|---|---|---|
| d | `A\tA`, `\t\tA`, `AAAAAA\tA` | 45 | 59 | default stops from field edge, truncated to px |
| b | 20 px, `\t\tA` | 93 | 64 | T at the run size |
| c | centred, `\tA` | 24 | 39 | layout left, then centre |
| s | tabStops [15,40], `\tA\t\tA` | 45 | 45 | stops from text origin; past the last stop = no move |
| e | tabStops [15], `AAAAAAAA\tA` | 45 | 45 | pen past the stop: no move |
| m | leftMargin 10, `\tA\tA` | 35 | — | origin = gutter + margin; textWidth excludes margin |
| n | indent 10, `\tA\tA` | 35 | — | indent moves the origin too |
| q | leftMargin 10 + tabStops [15,40] | 45 | — | explicit stops from the text origin |
| w | `A\tA\tA\tA\tA` | 88 | — | |

- `ng_shared.c`: `ng_next_tab_stop` default branch = Flash rule; `ng_set_tab_font` sets T and the origin from the
  measured font, leftMargin(+blockIndent, bullet) and indent in `ng_computeTextWidth` / `ng_wrap_count_lines`.
  The old `2.7·size` survives only as the no-metrics fallback.
- `action.c computeTextFieldDimension`: margins/indent are now read for UNWRAPPED fields too (they were read only
  under `wordWrap`). The unwrapped width path uses them for the tab origin only, and the height paths ignore them
  unless wrapping (checked: `ng_computeTextHeight` / `ng_computeScrollMixedFont` gate on `word_wrap`).
- `action.c actionTextFieldTabStopsTwips` (new): reads `_tf_tabStops` for the painter.
- `tag.c`: `tf_tab_stop` = explicit stops or `tf_default_tab_stop`; `TF_TAB_REF` gives the origin per paragraph
  (gutter + margin + first-line indent + bullet).
- Fixture passes trace + image in graphics, trace in no-graphics (image tolerance 64 = sub-pixel glyph AA, 0
  outliers).

## 6. Unit-scale EditText box snap

- Flash, `regression/avm1_edittext_border_subpixel` (25 bordered 30×12 px fields at +0/5/10/15/19 twips in x and y):
  boxes at +0..15 twips draw on that pixel, +19 on the next, i.e. `trunc((t + 2 twips) / 20) · 20`. That is the rule
  `textfield_render_cb` already applied to non-unit scales (Ruffle's `EditTextPixelSnapping`). Ruffle skips unit
  scale; Flash does not.
- Fix: `tag.c textfield_render_cb` snaps the translation at unit scale too. The size stays as is at unit scale (not
  pinned for fractional sizes).
- 4956 → 48 px vs Flash. The 48 left are one AA'd corner pixel per box and sub-pixel glyph edges (max_outliers 60).
- This did NOT move N's box: that box is a DefineShape hairline (§4), not an EditText.

## 7. Sweep and pricing

- **Rows:** 78 graphics rows (+11 no-graphics), the union of:
  - every row whose SWF has a TAB in DefineEditText text, an AS string constant, or ABC, or names `tabStops`
    (a tag/action-level scan; a raw byte scan over-matched 80 rows);
  - every image row with a bordered DefineEditText or AS `border`/`background` text fields (`visual/edittext/*`,
    `visual/fonts/*`, the shumway text rows, `avm1_edittext_placed_cxform{,_script}`, `avm2_edittext_placed_cxform`,
    `avm1_edittext_scaled_glyphs`, `avm1_edittext_wordwrap_render`, `avm1_edittext_tab_render`, …).
- **Graded against** `origin/ruffle-test-results` (results + image_results, fetched 2026-11-24), by trace status and
  image outlier count per comparison.
- **Moves: none from this change.**
  - Every trace status equals the baseline in both modes (incl. the ruffle_matched rows `TextFormat-v7/v8`,
    `EmbeddedFontTest`, `device_font_no_ink`, `acid-text-x`, `flash_text_TextField`,
    `edittext_device_transform_negative`/`_metrics`).
  - Every image comparison has the baseline's exact outlier count (e.g. `captions` 6528, `stylesheet` 2089,
    `acid-textfield-scroll` 552, `edittext_border_transform.04` 16), except:
  - `from_shumway/acid/acid-color-0`: baseline pass (3) → 1138 outliers locally. **Not this change:** a detached
    worktree at HEAD `931383092` with NONE of these hunks fails identically (1138). Either a commit after interim
    #3 or the shared recompiler build (`SWFRecomp/build` is symlinked in, and peers' uncommitted `swf.cpp` lives
    there). Reported to the coordinator. Its golden is Ruffle-made ("not Flash", golden-provenance). In the
    moved pixels the local render is slightly closer to Flash than the golden (640 vs 706 channels > 3).
- Trap: an env kill switch read via `getenv` in `textfield_render_cb` did not take effect through
  `verify_output.py` (the `avm1_edittext_border_subpixel` md5 was identical "on" and "off", although the snap
  provably changes it 4956 → 48). Don't price an A/B with an in-binary env switch through verify_output; use a
  worktree build per arm.

## 8. CI grading

Per the brief, `ruffle-tests.yml` was not dispatched from this session. SHA, change class and expected moves went to
`s27-coordinator`.

Expected moves: trace = 2 new regression rows pass (both modes); no corpus trace row moves. Images = 2 new fixture
images pass; no corpus image row moves (the `acid-color-0` local failure predates this change). Browser-visible:
text layout is shared code (Pages deploy is the coordinator's).

*CI result: pending the coordinator's grading run.*

## 9. Next blocker

1. **Flash thin-stroke pixel snapping (§4)**: the only remaining N gap to Flash. Renderer-wide, image-row pricing
   needed.
2. Same-tick visibility of a clip's own self-goto (brief goal 3, carried).
3. Tabs inside word-wrapped fields: `tf_soft_wrap_breaks` still uses fixed per-character advances (carried).
4. Episodes 3+: same AUTOEXIT recipe; ep 1–2 found no new runtime class, so expect diminishing returns.

## 10. Traps

- **`MAX_FRAMES` is compiled into the native binary** (`verify_output.py -DMAX_FRAMES`): building through
  `run_native.py --frames 30` and then running `test_run` directly stops at frame 30.
- The exporter's PNGs are `NNNN.png`, 0-based: native `F(k)` ≈ exporter `k-1`.
- An EditText-looking box can be a DefineShape. Check the SWF's char table before touching the text renderer.
