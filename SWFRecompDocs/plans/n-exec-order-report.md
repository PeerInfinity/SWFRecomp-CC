# N: AVM1 exec order (root enterFrame last) and TextField `_x` bounds fold (2026-11-22)

This is a one-task session following `n-collector-uaf` (`n-collector-uaf-report.md` §5), launched by the s26 fan-out coordinator. Baseline was master `55c59d329`.

**Summary**
- **Goal 1, exec order: half fixed, half a priced NO-GO.**
  - The "root last" half is LANDED. `_root`'s `onEnterFrame` now runs after the tick's queued child frame scripts, the way Ruffle does it.
    - Sweep: 343 candidate rows. Only 4 are reordered at all, and none changes status. 3 move closer to expected.
  - The per-clip sibling interleave among children is a NO-GO. It is the exec-list rearchitecture, and its fixture is parked.
  - **This overturns the brief's diagnosis of N (§3).** N's last telemetry diff is the sibling half, not the root half. The probe samples from its own clip, not from `_root`. It is also not visible: the particle is removed before render on the same tick in both players.
- **Goal 2, TextField `_x`: fixed.** Flash's rule (from gnash's Flash-verified `EmbeddedFontTest`) is `_x = tx + xscale·bounds.xmin`. Ours applied it only to fields found by name in the ROOT display list, so nested fields read the raw `tx`.
- Goal 3 (levels 1–4 routes) not started.

## 1. Fixture and the order difference

`ruffle-tests/tests/swfs/regression/avm1_exec_order_attached_selfremove/`: a generated SWF with a Ruffle-exporter golden.
- `create_test_swf.py <out> root` builds the regression test: one attachMovie'd 3-frame `pfx` clip `a` that self-removes on frame 3, plus `_root.onEnterFrame` and root frame scripts.
- `create_test_swf.py <out> sibling` builds the full shape: timeline sprite `tl`, plus `a`, plus `b` attached one frame later. It is parked in `SWFRecompDocs/plans/n-exec-order-sibling-fixture/` with the golden (`output.txt`) and our output before and after the fix.

One tick of the sibling shape (root frame 3; expected first, ours before the fix second):

| Ruffle (exporter) | ours before |
|---|---|
| `b ef` | `b ef` |
| `b f2` | `a ef` |
| `a ef` | `tl ef` |
| `a f3 remove` | `root ef a=movieclip …` ← sees `a` on its removal tick |
| `tl ef` | `tl f3` |
| `tl f3` | `b f2` |
| `root ef a=undefined …` | `a f3 remove` |
| `root f3` | `root f3` |

Ruffle runs one FIFO in exec-list order: clips newest-first, each clip's enterFrame and then its frame script, `_root` last (`avm1/runtime.rs::run_frame`, `movie_clip.rs::run_frame_avm1`).

Ours has two problems:
1. It flushes every enterFrame, root's included, before any child script (`tagFlushPendingEnterFrame`).
2. It queues timeline-sprite scripts ahead of attached-clip scripts.

The landed fix resolves the `root ef` rows only. The parked `sibling` variant still differs on the child rows.

## 2. Verdicts

### 2a. Root last: LANDED

**Mechanism.**
- `tag.c tagFlushPendingEnterFrame` sets `g_defer_root_enterframe` around `actionDispatchEnterFrameHandlers` and `actionDispatchRootVarMapEnterFrame`.
- The two root arms only record `g_root_ef_pending`. The dynamic_props arm is now `static dispatch_root_dprops_enterframe`.
- `actionFireDeferredRootEnterFrame` (action.c) fires the pending arms:
  - right before the first root DoAction (`aq_dispatch_script`) pops from the action queue (`aq_pre_dispatch`, at all 4 dispatch sites in `action_queue.c`);
  - otherwise at the end of `actionDrainAllInPriorityOrder` or `actionDrainActionQueueByKind(SCRIPT)`. That second case covers OFFSCREEN's and `swf_core.c`'s stopped-root fallback;
  - otherwise at an end-of-tick safety point in both `swf.c` and `swf_core.c`, after the orphan drain.
- The deferred dprops arm still runs under `g_inside_enterframe_dispatch=1`, so the goto-deferral rules that key on that flag see the same state.
- Kill switch for A/B work: `SWF_EXEC_ORDER_ROOT_LAST=0`.
- Not deferred: the past-last-frame branch of `swf_core.c` and the browser post-quit loop in `swf.c`. Both call the dispatchers directly, outside the flush.

**Sweep (priced before landing).**
- Candidates: every test SWF (decompressed) containing the string `onEnterFrame` in `avm1`, `from_gnash`, `from_shumway`, `regression` and the misc categories. That is 343 rows, run in no-graphics.
- Instrument: a temporary probe logged each tick where the deferred root handler existed AND at least one queued action ran between flush and fire, i.e. ticks where the order actually changed. The probe was removed before landing.
- **Only 4 corpus rows reorder**, all in gnash `misc-ming.all/action_order`. They were A/B'd with the kill switch in both modes:

| row | CI baseline | off → on (diff lines vs expected) | status |
|---|---|---|---|
| `ActionOrderTest3` | output_mismatch | 109 → 105 | unchanged |
| `ActionOrderTest4` | output_mismatch | 96 → 94 | unchanged |
| `ActionOrderTest5` | output_mismatch | 63 → 61 | unchanged |
| `action_execution_order_test4` | ruffle_matched | byte-identical | unchanged |

- Both modes produce identical output for all 4.
- In ActionOrderTest3, `onEnterFrame` moves from before the child's `static unload` row to after it, which is the expected relative order. The rows' remaining mismatch is the per-clip interleave plus ctor/load ordering: the arc §26.4 NO-GO family, still open.
- Every other row in the 343 (all of `avm1`, the gnash Dejagnu suites, `regression/avm1_attach*`, `avm1_attached_clip_*`) is provably untouched: the probe never fired.
- The probe only recorded no-graphics runs. Graphics shares the flush and drain code; CI grades it.

### 2b. Per-clip sibling interleave: NO-GO (parked)

What a faithful version needs:
1. Each child's enterFrame fires immediately before that child's own queued frame script.
2. The script queue itself is in exec-list (instantiation) order across timeline and attached clips.
3. The clip-event `onClipEvent(enterFrame)` walk (display-list order, children before parents) merges into the same order.

This is the "flat instantiation-ordered exec list" rearchitecture that memory `divergence-tracer-exec-order` (option A) already deferred.

Cost: unlike root-last, it reorders every tick with two or more scripted or enterFrame children. That is most of gnash `action_order` and a large share of avm1 clip-event rows, and the instrumented sweep would have hundreds of hits rather than 4.

Not attempted. Completion mechanism, if someone takes it on:
- give MovieClip/DisplayObject an instantiation serial;
- queue child enterFrames as `AQ_KIND_SCRIPT`-priority entries keyed by clip;
- sort the tick's child entries by (serial desc, enterFrame-before-script) before the drain;
- price it with the same probe technique on the parked `sibling` fixture plus the 343-row list.

## 3. N on the landed build (brief §1 premise overturned)

- Build: `START_LEVEL=1 OBJHASH=true AUTOKILL=true FREEZE="" n_drive/build.sh "400:-/300:R"`. Compared with `exporter -f 900` against native `run_native.py --frames 900`.
- Result: NF/ND lines 456/456, identical except `h=` at a=0 t=56 and t=58, the same two lines as before.
- Why the fix does not move them:
  - N's `NF` line (and its `h=` hash) is traced from `__ndrive__.onEnterFrame`, the probe's own `createEmptyMovieClip` clip (`NDrive.as:53`). It is not traced from `_root.onEnterFrame`.
  - `__ndrive__` is OLDER than the pfx particles, so in Ruffle the pfx self-removal runs before the probe's enterFrame. That is the §2b sibling order, not root-last.
- **Not a visible linger.** Our pfx script still runs in the same tick's drain, before render, so the particle is gone from the rendered frame in both players. The "lingers one frame" in `n-pixel-pass-report.md` §4B is the probe's observation, not pixels.
- What the landed fix does for N: N's own `RunApp` (`_root.onEnterFrame`) now sees the same child state Ruffle's does. Telemetry is otherwise unchanged.
- To make N's telemetry byte-identical without §2b: sample NF from the FRAMELOCK root wrapper (`NDrive.preFrame`) instead of the probe clip. That is a tooling change; it re-baselines `ruffle_exporter_trace.txt`.

## 4. TextField `_x`/`_y` (goal 2): FIXED

**Flash evidence.**
- gnash `from_gnash/misc-ming.all/EmbeddedFontTest/output.txt`. gnash's expectations are Flash-verified, and Ruffle's own rule agrees.
  - `tf1._x == 48`, `tf1._y == 28` for a field at tx=50, ty=30 px with bounds min −2,−2 px.
  - `tf3._x == 18` at xscale 16.
- So Flash's `_x = tx + xscale·xmin`, which is Ruffle `edit_text.rs` `x()` + `bounds_x_offset`. That puts this under the flash-over-ruffle ruling: Flash and Ruffle agree.
- The Flash-IDE fixture `avm1/edittext_autosize` (xmin −40 tw) sets `_x` before reading it, so it does not discriminate.

**Our bug.**
- `actionGetMemberImpl` `_x`/`_y` folded the offset in only when `ng_findDisplayEntryByName(mc->name)` found the field in the ROOT display list.
- Fields nested in a timeline-placed sprite or an attachMovie'd clip (N's HUD) fell back to raw `mc->x` (= tx). The browser root arm and `actionGetProperty` case 0/1 never folded it at all.

**Fix.**
- New `actionTextFieldBoundsOffset(mc, axis)` = `scale × bounds.min`, the Ruffle formula.
- Applied in the GetMember fallback, the GetProperty arms, and (via the placement matrix) the browser root arm, whenever the axis is not AS-set.
- The setter still stores the requested value, so a set/get round trip is unchanged.

**Fixture:** `regression/avm1_textfield_x_bounds_offset`. Rows: root-placed, scaled root-placed, nested in a placed sprite, nested in an attached sprite, and a setter round trip. The nested rows were red (10 vs 8) and are green in both modes.

**Check set**: 100 rows × 2 modes:
- avm1 `*edittext*`/`*textfield*`/`*text_field*`/`clone_sprite_edittext*`;
- the 15 gnash misc-ming rows with IDE-gutter fields that read `_x`;
- regression `*text*`;
- result: all equal to the CI baseline.
- Three graphics/no-graphics `runtime_error`s under `-P 4` load (`place_and_remove_object_insane_test`, `replace_sprites1test`, `replace_buttons1test`) pass or ruffle-match on a serial rerun. They were transient.

**Left alone (named):**
- `getMCBuiltinProperty` and `GetVariable("_x")` inside tellTarget still return raw `mc->x`; a TextField cannot be a tellTarget.
- When AS sets `_x`, Ruffle stores `base.x = x − offset`, so the field draws 2 px further right than ours. That is a render-only residual, not trace-visible.
- The root arm resolves the field by NAME in the root DL. A nested field named like a root clip would read that clip's transform, the same class as `avm1_attached_clip_samename_child`.

## 5. Next slice's line

1. N telemetry byte-identity: either the §3 probe re-sample (tooling, cheap) or §2b (rearchitecture; price with the parked fixture first).
2. Episode 0 levels 1–4 with routes that complete them, so thwumps and drones interact with the player (`author.py` on the exporter; hash `r.objects`).
3. After w2-attached-holder-render: the native 1:1 pixel pass.

## CI / Pages

- CI-observable: this commit. It touches shared `swf_core.c`, so the coordinator's final no-graphics leg should include it.
- The browser TextField arm is browser-only.
- No own dispatch. Pages: the coordinator deploys at closeout.
