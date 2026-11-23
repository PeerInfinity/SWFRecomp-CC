# N: gold-pickup streaks, level 3 route, native pixel residual (2026-11-23)

This was a one-task session following `n-levels` (`n-levels-report.md` §5), launched by the s26 fan-out coordinator. Baseline: master `80389ee69`. Landed: `c948d0e61` (runtime fix + fixture + `TRACKGOLD` probe knob) and the docs/routes commit that carries this report.

**Summary**
- **Goal 1, streaks 2–3 frames late: FIXED (§1).** This was not a timeline bug, and the brief's "nested morph child timeline" suspect was wrong.
  - Every gold clip's `_currentframe` matches Ruffle frame for frame.
  - The cause was the renderer: every instance of a morph character drew the ratio of the **last-composed** instance. N's coins share morphs 568/569. Coins collected 1–3 frames apart all drew at the newest pickup's ratio, which looks like "late" streaks.
- **Goal 2, levels 1 and 3 routes: level 3 DONE, level 1 NOT done (§2).**
  - Level 3 is complete: switch t=762, exit t=966.
  - The level 3 replay is byte-identical between exporter and native graphics, including `h=`/`o=`.
  - In the browser, player telemetry and `o=` are identical on every tick. The only difference: the browser **removes self-removing particle clips 2 ticks late** (`h=` only; a new browser-only finding, §2.3).
  - Level 1 was timeboxed. Its geometry and the approaches that failed are in §2.4.
- **Goal 3, native pixel residual priced by class (§3).** After the fix, the level-0 shots differ by 24–94 px (was 19–132). Five classes, none of them gold.

## 1. The streak lag was shared morph vertices

**Timeline ruled out first.**
- New probe knob `n_drive` `TRACKGOLD=true` prints `NG f= t= i= cf= v=` after each `RunApp` for every gold object off frame 1.
- Level 0 over 900 frames: 232 `NG` lines, byte-identical exporter vs native graphics (and every NF line).
- So the pickup goto and the clip's timeline both match Ruffle.

**Splice reproduction.**
- N's real chars 565/566/568/569/570 were spliced into a minimal SWF (scratch only; N is not open source). The coins were attached into a `createEmptyMovieClip` buffer, with `gotoAndStop("NOT_COLLECTED")`, then `gotoAndPlay("COLLECTED")` from a stopped root's onEnterFrame.
- **One coin:** native vs exporter per-frame images match within AA (4–300 px), with identical bounding boxes every frame.
- **Three coins collected 2 and 3 frames apart:** **10,000–27,000 px** differ per frame while the traces are identical. This reproduces the bug.

**Cause.**
- A `DefineMorphShape` has one vertex range in the GPU vertex buffer (`ch->morph_start_offset`).
- `compose_children` and `tagShowFrame` lerped each morph instance into that shared range with `renderer_update_vertices` / `renderer_update_colors`.
- Those are queue writes that all land before the frame's draws. So every instance drew with whichever instance was composed last. The same applied to morph colours.
- `regression/avm1_parent_child_morph`'s docstring had already noted this as "a separate, pre-existing defect".

**Fix (`c948d0e61`).**
- New `render_webgpu_draw_morph`: per draw, it lerps the start→end vertices into the **per-frame dynamic vertex region**. It gives the morph's solid fill colours their own dynamic colour slots, remapping `style_y` for solid-fill vertices in the morph's colour range.
- If the dynamic pools are full, it falls back to the shared range.
- `tag.c` `draw_morph_instance` feeds it from all four morph draw arms:
  - `render_single_object`
  - `render_display_list` (draw and clip-mask)
  - `draw_mc_mask_geometry`
- The compose-time shared writes are gone, which also saves one `writeBuffer` per morph per frame in the browser.
- AVM2 has its own lerp path (runtime tris) and is untouched.

**Fixture `regression/avm1_morph_instances_ratio`.**
- One red→blue morph. Four instances: two on root, two nested in sprites, at ratios 0 / 65535 / 0 / 65535.
- Golden image and trace come from the Ruffle exporter at tolerance 0.
- Graphics: **9600 outliers without the fix, 0 with it.** No-graphics passes.

**Pricing.**
- `render_canary` A/B covered every image row with a `DefineMorphShape`: `from_shumway/acid/acid-morph`, `from_gnash/misc-ming.all/morph_test1` (frames 1–4), `from_shumway/invalidClipDepth`, `regression/avm1_parent_child_morph`, `regression/avm2_morph`, `visual/cache_as_bitmap/morph`, plus the new fixture.
- Result: **11/12 byte-identical.** Only the new fixture moves (fail→pass).
- `emcc -fsyntax-only` was clean, and the full browser N_drive build (§2.3) links with the fix.

**N proof (native graphics, `FRAMELOCK`, level 0 script).**
- Pickup cluster, frames 325–372, worst shot: **289 px → 55 px**. It is flat at the ~30 px fps/AA floor.
- n-levels shot 1776: 132 → 61 px.
- Telemetry (`OBJHASH` `h=`/`o=`): byte-identical over the common span.
- No-graphics has no renderer, so the fix cannot affect it.

**CI.** Observable in graphics images only; trace is unchanged. The coordinator grades `c948d0e61` in a follow-up graphics/images run. The fix is browser-visible, so it ships with the closeout Pages deploy.

## 2. Routes

### 2.1 Level 3 "the box, the box!" (no enemies): complete

The route is in `routes_ep0.txt`. It was authored with `search.py`, which grows a prefix one landing at a time.

1. Run left onto the left launchpad (120,576). It throws the player into the left box's ceiling. Hold R into the box: **key (252,420) reached at t≈134.** This opens the bottom-right locked door (696,564).
2. Out of the box, land, then **jump over the left launchpad.** It re-fires on contact, so running right on the floor sends you back into the box. Then run right through the open door onto the right launchpad (732,576).
   - The launch apex is always y≈317 (straight or angled).
3. **Wall-jump** off the right wall during the rise (apex 261) and brake onto the one-way (708,324). Stand at y=302.
4. Hold J for **45 ticks** to reach apex 224 and land on (708,252).
   - 25 ticks reaches only 231, 1 px short.
5. Jump left onto the edge of (660,204), then settle onto it with `3:-|10:R`.
6. Step to its left edge (x≈643), jump along the switch box's left face, **wall-jump at 18 ticks while still rising fast, holding R throughout** (apex y≈34). Land on the roof: **switch t=762.**
7. Momentum carries you into the 24-px chimney right of the box. The held-L/LJ input bounces you back up onto the roof. Run left off it onto the central box (stand 134).
8. Jump the U's right wall (top y=72), brake with `5:-|20:R`: **exit t=966.** Level 4 loads in attempt 1.

### 2.2 Replay

`START_LEVEL=3 AUTOKILL=true OBJHASH=true FREEZE=""`.

| leg | lines | diff |
|---|---|---|
| exporter `-f 1500` vs native graphics (`build/test_run` direct) | 1096 NF/ND | **0** (incl. `h=`/`o=`) |
| exporter vs browser WASM (`n_drive_compare.py ours`, SwiftShader) | 966 a0 NF | player fields 0, `o=` 0, **`h=` 310** |

Events are identical in all three: switch t=762, exit t=966, level 4 autokill t=60.

### 2.3 Browser finding: self-removing particle clips leave 2 ticks late

The `h=` diffs come in 2-tick blocks. The exporter's clip count drops (a `pfx` clip removed itself on its last frame), and the browser's drops 2 ticks later. Examples: t=34–37, 162–165, 298–303, 540–546.

- Native graphics is exact (0 `h=` diffs). So this is the browser loop, not shared code.
- Native was fixed for the same symptom by n-exec-order (root-last) and n-levels Bug A (promote after the deferred root ef).
- The browser's `swf.c` per-frame order likely lacks the equivalent.
- It is visible: the particle's last frame lingers for 2 frames.
- Not fixed here.

Browser build recipe:
1. Copy the route SWF into `SWFRecomp/tests/flasharchive/N_drive/test.swf`.
2. `rm -rf RecompiledScripts RecompiledTags`.
3. `build_test.sh flasharchive/N_drive wasm --graphics`. **`--graphics` is required.** Without it the build is NO_GRAPHICS and fails to link with "initial memory too small". It takes 2.5 min at `EMCC_CORES=4`.
4. `deploy_example.sh flasharchive/N_drive ../docs2/examples --no-index --graphics`.

### 2.4 Level 1 "cloud city": not done (geometry + what failed)

**Required order:** key (204,204) → locked door (48,348) opens → switch (36,396) → exit (708,492).
- The (60,60) switch is a decoy. It triggers exit (372,444) but also closes the trap door (360,372) on that exit's hollow.

**Exit side is easy.**
- Run right 156 ticks to the 24-px chimney (x 744–768).
- The exit cave (672–744, 456–504) opens into it, and a few jumps there entered the cave (attempt reached (694,494)).

**The hard part is the key.**
- It sits in the upper-left cloud's hollow (≈170–310 × 145–240).
- The hollow opens only through a ~22-px notch at about (289–312, 120–168), so you enter from above, e.g. from the bounce blocks (420/516/612, 132), tops y=120.

**Getting high is the blocker.**
- The full jump is 78 px.
- The chimney's left wall has a ~100-px gap (column bottom ≈431 to bottom-cloud top ≈528). Chimney climbing stalls at y≈465.
- The left-wall floor jump hits the underside of the left cloud (y=480).
- The bottom-right cloud's steps are rounded bumps. The player stalls at (643,389) below the column's left face (x=672).
- Single-wall climbing (four rhythms on two walls) never nets height.
- A wall-jump off bounce block (180,492)'s side has not been made to work: the attempts either released J early or rose under the block.

**Next things to try:**
- That block wall-jump with J held through the rise (the level-3 box-face recipe: `8:J|18:RJ|1:R|1:J|20:RJ`).
- Pushing a bounce block up from below and riding its spring.
- Approaching the middle cloud's bump (360–408, top 336) from block (540,300).

## 3. Native pixel residual by class (goal 3)

Level-0 recipe from `n-levels-report.md` §4, re-run with the fix. Native F(k) vs exporter best of k-2..k; a pixel counts when its max channel delta is >24.

| shot | 205 | 487 | 609 | 766 | 998 | 1237 | 1378 | 1560 | 1684 | 1776 |
|---|---|---|---|---|---|---|---|---|---|---|
| px (was, n-levels) | 26 | 25 | 28 | 19 | 25 | 61 | 64 | 88 | 61 | 132 |
| px (now) | 24 | 26 | 27 | 31 | 27 | 62 | 72 | 94 | 61 | 61 |

| class | px/shot | where | note |
|---|---|---|---|
| fps counter | 11–19 | bottom-left | wall clock, expected |
| scattered AA | ~12 | tile/stroke edges, same 4–5 px every shot | single pixels |
| open exit door panels | 36–64 | (552–624, 480–504), from the switch on | the sliding panels are 1–2 px off. Door-animation phase or subpixel; unexplored |
| ragdoll thin strokes | part of 1560 | post-level body near the door | the known thin-stroke class (`n-thin-strokes-no-min-width`) |
| level-1 trap switch (60,60) | 27 | 1684, 1776 | **inner glyph dark on ours, mid-grey on Ruffle**. A colour transform or alpha on a nested part is not applied. Cheapest real lead |

**The gold class is gone.** Shot-to-shot noise is ±5 px, because the fps counter reads the wall clock.

## 4. Next blocker / next slice

0. **Browser particle self-removal 2 ticks late (§2.3).** This is the only browser-vs-Ruffle telemetry divergence on a full level route, and it is visible. Port native's root-last / promote ordering to the browser loop. Fixture shape: n-levels' `regression/avm1_attach_from_stopped_root_enterframe` run through a `wasm_probes/` harness.
1. **Level 1 route (§2.4).**
2. **Level-1 trap-switch colour (§3), 27 px.** Then the exit-door panel offset.

## 5. Tooling / traps

- `TRACKGOLD` (n_drive README §"s26 n-gold-streaks additions").
- A jump only fires on a fresh J press while grounded or on a wall. A J segment that starts in the air does nothing. Wait for touchdown.
- Jump height grows with hold time up to ~45 ticks (78 px).
- The best wall-jump comes while still rising fast, holding toward the wall throughout. Near the apex it gains only ~20 px.
