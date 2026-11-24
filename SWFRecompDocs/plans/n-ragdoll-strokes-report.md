# N: the "ragdoll thin strokes" were orphan limb clips; the edge dots are Ruffle's curve tolerance (2026-11-23)

One-task session after `n-trap-stroke` (`n-trap-stroke-report.md` §5), launched by `s27-coordinator`.
Baseline: master `ea61076e1` (pulled to `e4275bc4e`). Brief:
`SWFRecompDocs/plans/session27-fanout-reports/n-ragdoll-strokes-prompt.md`.

**Summary**
- **Goal 1, shot-1560 "ragdoll thin strokes": the premise was wrong, and the bug was ours (§1, §2).**
  - Not the ragdoll: its five stick clips are invisible after the level ends.
  - Not Drawing-API strokes either, and not a stroke-width rule.
  - The figure is the ninja (`player.mc`, "testNinjaMCm", frame 167+). We drew **extra limb "bones"** (a torso line,
    a longer hand) that Flash and Ruffle never draw.
  - Cause: a runtime parenting bug. Sprites placed by an **attachMovie'd clip's own timeline** got MovieClips
    parented to `_root`.
  - The OFFSCREEN attached-clip pass then composed those orphans a second time. That left the shared child entries on
    dynamic transform slots, so the real compose used an identity local matrix. The bones are placed with a degenerate
    `d=0` matrix (invisible), and losing it made them visible.
  - Fix in `tag.c` (§3). Fixture `regression/avm1_attached_clip_timeline_child_parent`: image red 1120 px → 0. Its
    golden is the Ruffle exporter's, and the **real Flash Player** oracle agrees at 0 px, trace included.
  - N: the class is gone (shot 1560: 28 → 3 px in the ninja box; frames 1540–1578: 22–43 → 0–6 px).
- **Goal 2, the remaining native residual (§4):**
  - The **fps counter** is N's own `getTimer()` readout: wall clock, not a bug.
  - The **~11 constant edge dots** are Ruffle's scale-dependent curve flattening. An exact-curve model hits **our**
    MSAA samples pixel for pixel, and the Flash oracle is consistent with it. Kept, no change.
- Goal 3 (FRAMELOCK slack) not done (§6).
- CI: handed to the coordinator (§5).

## 1. Locating the class (and why the brief pointed at the wrong thing)

The brief, from n-trap-stroke §5, said: "Drawing-API strokes under a scaled clip; post-level ragdoll standing in the
door". Every part of that turned out wrong.

1. **Which clip.** The new `n_drive` knob `TRACKPLAYER=lo:hi` showed the following during postlevel (probe frames
   1540–1580):
   - the five ragdoll sticks are `v=false`;
   - the figure is `player.mc` playing its landing frames 167→201.
   - N's `RagStick`/`Ragdoll.Draw` use **timeline sprites** (`arm_m`/`leg_m`/`body_m`), not the drawing API.
2. **State vs render.** Exporter and native `NP` lines are equal for every child clip: position, frame and
   rotation/scale to f32 precision. So the difference is in rendering.
3. **Ruffle's tessellation cache, ruled out.** Splices of `testNinjaMCm` matched the exporter at 0–1 px:
   - at frame 173 alone;
   - with N's frame sequence 1→103→167…173;
   - attached into a buffer;
   - next to the five stick clips (visible, invisible, mirrored).

   I also forced the history: a 39% draw, then 20%. That diverges by 63 px (the trap-switch mechanism), and there
   ours = Flash. But Ruffle's debug log (`RUST_LOG=ruffle_core::display_object::graphic=debug`) showed N creates only
   five tessellations of these shapes in 1552 frames, and a splice reproducing exactly those entries still matched.
   So the cache is not the N cause.
4. **The split.** Dark-pixel masks of one region:
   - Ruffle-in-N = splice;
   - ours-in-N had **13 extra dark px**: a torso line and a longer hand.

   Hiding layers on the exporter (staged `_visible=false` per sprite buffer) confirmed that nothing outside the
   player layer draws there.

## 2. Root cause

I instrumented a private copy of the runtime in the N build dir (`render_webgpu_draw_shape` and `compose_children`
logging, `-g` + gdb). Nothing in the shared tree was touched for this.

- **The draws.** All six draws of shape 136 (the 1-twip "bone" line) had uniform world matrices, e.g.
  `0.19,-0.05,0.05,0.19`.
  - Four of them sit under sprites 140/143/144, which place 136 with matrix `a=0.667|0.5, d=0`: degenerate, so the
    line should collapse to nothing.
  - In the splice those same four draws had `c=d=0`, as they should.
- **Double compose.** Every bone entry was composed twice per frame.
  - First compose: parent = identity. The entry is repointed to a dynamic slot and drawn at the stage origin.
  - Second compose: `tid >= baked`, so `compose_children` takes its dynamic-slot branch. That branch builds the local
    matrix from the MC's AS state, or **identity** when there is no MC. The `d=0` is lost.
- **Who composes at identity.** The OFFSCREEN attached pass (`tagRerenderFrame`, `offscreen_attached_pass_member`)
  composed 17 MCs with `parent == &root_movieclip`:
  - `instance18964…18974` (the ninja's limb sprites) and `footL/footR/handL/handR/pelvis/shoulder`;
  - each with a standalone `display_obj` whose `sprite_display_list` aliases the real children's lists.
- **Who made them.** A gdb trap on their creation gave this chain:
  `ng_attached_run_tree → advance_sprite_frames → process_sprite_needs_init(&root_movieclip) →
  process_sprite_init_at_depth → actionFindOrCreateMovieClip(name, root)`.
  - After a sprite's frame function runs, `advance_sprite_frames` initialises newly placed children with
    `parent = actionFindMovieClipByName(obj->instance_name)`, falling back to `_root`.
  - `ng_attached_run_tree` advances the attached clip through a temp one-entry list.
  - An attachMovie'd clip's entry has **no instance name** (`ng_attachMovie` mints a standalone `display_obj`). So
    every sprite the clip's timeline places got a second MovieClip under `_root`.
- **Flash/Ruffle.** The children belong to the attached clip. Trace oracle on the fixture (identical in Ruffle and in
  Flash Player 32): `typeof _root.kid = undefined`, `h.kid._target = /h/kid`.

## 3. Fix

`SWFModernRuntime/src/libswf/tag.c`:
- `advance_sprite_frames`, post-frame child-init block (NO_GRAPHICS / OFFSCREEN): the parent is now
  1. `ng_mc_for_sprite_obj(obj)` for a named entry. It prefers the clip bound to this very entry over a same-named
     clip elsewhere; this is the helper the same function already uses for its `_currentframe` sync.
  2. Else the attached clip, when `obj` is the entry `ng_attached_run_tree` is advancing (file statics
     `g_attached_advance_obj/mc`, set and restored around its `advance_sprite_frames` call).
  3. Else `_root`, as before.
- `ng_attached_run_tree`: sets and restores those statics.

Not changed:
- The goto-rebuild init block (~L2520, `parent_for_init` from the same name lookup) has the same shape. No measured row
  reaches it with an unnamed attached entry, so it is left for a reproducer.
- The browser loop has its own child-init path. Not measured here; the fix's code is shared but the changed block is
  `#if NO_GRAPHICS || OFFSCREEN_RENDER`.

## 4. Fixture, local evidence, pricing

**Fixture `regression/avm1_attached_clip_timeline_child_parent`:**
- Exported sprite "holder": frame 1 empty; frame 2 places
  - `kid` (a sprite holding a red 20×20 square);
  - `bone` (a sprite placing a blue 40×4 rect with `a=1, d=0`);
  - and stops.
- Root attaches it at (100, 60) and traces at frame 4.
- Golden: Ruffle exporter frame 3. The Flash oracle (`tools/flash-oracle/run_image.py`) is **identical at 0 px**, and
  `run_trace.py` matches `output.txt`, so this golden is a Flash oracle.
- One instance per shape, so Ruffle's tessellation cache cannot skew it.

| fixture | before | after |
|---|---|---|
| graphics image | 1120 outliers: extra red square at the stage origin, collapsed blue bone drawn | **0** |
| graphics trace | pass | pass |
| no-graphics trace | pass | pass |

**N, level-0 native pixel pass.** Same recipe as n-gold-streaks §3: native F(k+1) vs exporter best of k−2..k,
delta > 24. Telemetry (`NF`/`ND`) is byte-identical before and after.

| shot | 205 | 487 | 609 | 766 | 998 | 1237 | 1378 | 1560 | 1684 | 1776 |
|---|---|---|---|---|---|---|---|---|---|---|
| px before | 28 | 24 | 36 | 37 | 29 | 24 | 38 | 53 | 64 | 51 |
| px after | 32 | 20 | 32 | 37 | 29 | 24 | 34 | 32 | 60 | 51 |
| of which fps counter | 19 | 6 | 13 | 24 | 17 | 11 | 13 | 17 | 15 | 6 |
| ninja/door box | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 28 → **3** | 0 | 0 |

Postlevel window, ninja box (px), every 2nd frame 1540–1578: before 22–43 per frame, after **0–6**. Shot-to-shot
noise is ±5 px, from the fps counter.

**Pricing.**
- Static scan of every corpus `test.swf`: AVM1 SWFs that call `attachMovie` on an exported sprite whose timeline
  places a sprite at frame ≥ 2. These are the only rows that can reach the attached branch.
- Result: **1 corpus row**, `avm1/netstream_play_flv_screen`. Graphics image 0 outliers; passes in both modes.
- The named branch changes behaviour only when a different clip of the same name exists **and** a clip is bound to the
  entry; full CI grades it.
- Local sweep, graphics mode: 18 attached-clip / exec-order / morph regression fixtures, all pass.
  - `avm1_attach_*`, `avm1_attached_clip_*` ×15
  - `avm1_exec_order_attached_selfremove`
  - `avm1_morph_instances_ratio`

## 5. CI grading

Committed and pushed (SHA in the commit carrying this report). Per the brief, `ruffle-tests.yml` was **not**
dispatched from this session; the SHA, the change class and the expected moves went to `s27-coordinator` for its next
graphics/full/images grading run.

Expected moves:
- **trace:** 0 moves. The fixture is new, and its trace also passed before the fix.
- **images:** new fixture `[output] pass`. No other image row expected to move (only one corpus row can reach the
  attached branch, and it is byte-identical locally).
- **no-graphics:** no moves.

*CI result: graded in the coordinator's s27 interim #2 graphics run. The by-name result is recorded in the s27 arc doc,
not here. Successor session: `n-l2l4-pixel-pass` (L2/L4 native pixel pass, then the goto-rebuild `_root` fallback
reproducer).*

## 6. Goal 2 detail: the remaining native residual

**fps counter (6–24 px/shot, bottom-left): not ours.** It is N's `APP_FPSBOX`, fed by `getTimer()` deltas, so wall
clock. FRAMELOCK pins game ticks, not the fps readout.

**The ~11 constant edge dots: Ruffle's curve tolerance, not ours.**
- **Where.** One per sloped/concave tile, the same pixels every shot, e.g. (122,86), (57,26), (26,38). Ours draws
  0xCACAD0 (uncovered), Ruffle 0xA2A2AC (2/4 MSAA samples).
- **Which tile.** A probe `NH` hit-walk at (122,86) names `tileMC128` (×24%, frame 10). That is shape 458: a concave
  quarter-circle made of two quadratic curves.
- **Splice.** A lone spliced tile reproduces it. At (122,86): ours 202, Ruffle 127, **Flash 164**.
- **Exact model** (4 standard MSAA sample points vs the exact quadratic boundary, plus 16×16 area):

  | pixel | exact | ours (Levien 2 twips) | Ruffle (Levien 0.1 px device = 8.3 twips at ×0.24) |
  |---|---|---|---|
  | (122,86) | 0 samples, area 0.15 | 0, 0.17 | **2**, 0.21 |
  | (123,83) | 2, 0.73 | 2, 0.75 | **3**, 0.80 |
  | (123,84) | 0, 0.16 | 0, 0.17 | **1**, 0.20 |

  - Ours hits the exact curve's sample pattern pixel for pixel.
  - Ruffle's coarser runtime flattening (`DEFAULT_TOLERANCE / scale`) explains its values exactly.
  - Flash's analytic AA (≈25% at (122,86)) is consistent with the exact curve.
- **Disposition.** Kept per the Flash-over-Ruffle ruling. Not a corpus diff, so no doc entry.
- **Prune criterion:** if a future Ruffle flattens finer at small scales, these dots vanish with no change here.

**Not done:** goal 3 (pin FRAMELOCK slack to 1 tick, re-check the L2 `frame=` skew).

## 7. Next blocker / next slice

1. **N native level 0 is now at its floor:** fps counter + Ruffle-tolerance dots + the level-1 trap switch (Ruffle's
   tess cache). Nothing ours is left in the 10 shots. The next N value is in other levels' native pixel passes
   (L2/L4 routes exist), or the browser.
2. **Same-class site:** the goto-rebuild child-init block (`tag.c` ~L2520) still uses the global name lookup with a
   `_root` fallback. Build a reproducer (attachMovie'd clip + `gotoAndStop(n)` to a frame that places a sprite) before
   touching it.
3. **Probe hygiene (optional):** FRAMELOCK slack (n-trap-stroke §3).

## 8. Tooling / traps

- **Instrument a private runtime copy, not the shared tree.**
  - Wrap `run_native.py` in a `subprocess.Popen` logger to capture the exact gcc commands.
  - Edit the copied `*.c` in the build dir, recompile just those files (`-g` for gdb), and relink. About 10–60 s per
    iteration, with zero risk to peers' files.
  - Scripts: scratch `logpopen.py`, `rebuild.py`.
- **`__builtin_trap()` on a named creation + `gdb -batch -ex run -ex bt`** found the orphan-MC creator in one run.
- **Splice matches, game doesn't:** first diff **dark-pixel masks** of the game crops against the splice, per player.
  It showed which player changed between splice and game (ours, not Ruffle), which overturned "Ruffle cache again".
- **Ruffle's retessellation log:** `RUST_LOG=ruffle_core::display_object::graphic=debug` prints every
  `Graphic id= retessellated: new_scale=`. It gives a game's real cache history with no rebuild.
- **Flash oracle (`tools/flash-oracle/`):** `run_trace.py <dir>` and `run_image.py <dir> -o x.png --ticks N`. A
  hand-built SWF needs a root `ShowFrame` (Ruffle tolerates its absence; Flash never fires the Loader INIT).
- **`hitTest(x, y, true)` on an exact edge pixel can miss.** Use the bounding-box form to name the clip, then
  splice.
- `verify_output.py` reports image FAILs but they never gate pass/fail. Read the `[image:output]` line.
