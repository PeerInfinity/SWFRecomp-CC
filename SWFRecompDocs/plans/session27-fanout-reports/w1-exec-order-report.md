# w1-exec-order — wave-1 diagnosis (session 27, dual-axis #19)

**New files (all under `session27-fanout-reports/`):**
- `w1-exec-order-report.md` (this file)
- `w1-exec-order-prototype.patch` (`git diff origin/master -- SWFModernRuntime`; 3 files, +40 lines)
- `w1-exec-order-fixtures/avm1_exec_order_dynamic_eligible/` (`create_test_swf.py`, `test.swf`, `test.toml`, `ours_nographics.txt`)
- `w1-exec-order-fixtures/avm1_goto_backward_enterframe_once/` (`create_test_swf.py <out> plain`, `test.swf`, `test.toml`)

**Measurement setup:**
- Measured on `origin/master` `ae7f50cb` (the wave-0 `d70f2c0aa` stroke-order commit is included).
- Baseline is the s26 record pair (`df7729df2` graphics, `81d32b9b2` no-graphics). The wave-0 run had not published when I started.
- Corpus: `download_tests.sh avm1 from_gnash from_shumway` (upstream Ruffle master at session time; my Ruffle clone HEAD is `1e604fa87`). `regression` comes from git.
- Box: `SETUP_STATUS` all OK (Dawn/lavapipe present). Every headline row below was run in **both** modes.

---

## 0. Verdicts and priced flips

| # | Item | Verdict | Priced flips | Owner |
|---|---|---|---|---|
| 1 | Dynamic-MC eligibility mark, graphics vs no-graphics | **GO (XS).** Real and observable. **swf_core.c is right, swf.c (graphics) was wrong.** Fix is in the prototype patch. | **0** (fixture only; 115-row graphics sweep, 0 moves) | `swf.c tagMain` |
| 1b | **Brief premise corrected:** the fix touches **no no-graphics-only code**. It edits the `OFFSCREEN_RENDER` arm of `swf.c`; `swf_core.c` already had the right order. | — | — | — |
| 2a | **NEW: `onEnterFrame` fires 3× per tick when a frame script does a goto.** Applies to `_root` and dynamic MCs: any inline goto catch-up re-runs the enterFrame dispatcher twice. | **GO as a correctness fix (XS)**, but it is **not a flip lead** | **0** (323-row sweep: 3 rows reorder, all closer to expected, 0 status moves) | `tag.c ng_run_deferred_sprite_init_impl` → `action.c actionDispatchEnterFrameHandlers` |
| 2b | action_order family after root-last (6 rows) | **NO-GO, unchanged.** Actual-line counts are identical to the s20 record (83/94/58/45/28/32). Only `test11` (and bug 2 of `_extend_test`) is the sibling exec-list mechanism; the other four first-diverge on B2/B3/B4 or a Ruffle-shared divergence. | 0 | §2 |
| 2c | Flat, instantiation-ordered exec-list rewrite | **NO-GO as a flip arc.** Priced at **XL (4 phases, about 2–3 dedicated sessions)** for **0 priced flips**. The one row it owns (`test11`) also needs `asOrder`, and `_extend_test` also needs B2. The "family" framing is **refuted** (first-divergence table, §2). | 0 | §3 |
| 3 | `RegisterClassTest4` | **Not the exec-list family.** Ours equals Ruffle through line 7 (line 3 is Ruffle's own divergence). Ours first leaves Ruffle at line 8: the unload/ctor swap on the sprite loop-back (B4 identity), the same signature as AOT4 line 13. The STRIKE stands (`from_gnash/_investigation/ACCEPTED_DIFFS.md:231`). | 0 | §4 |

**CI-mode note for the coordinator:**
- **Item 1 alone is graphics-only.**
- **Item 2a is shared runtime (`action.c` plus a trailing `MovieClip` field in `action.h`)**, so if it lands it needs both CI legs (graphics + no-graphics, `categories=full` is not needed: AVM1-only).
- I ran every headline row in both modes. Outputs are byte-identical across modes after the patch.

Functions touched (prototype only, reverted from my commit):
- `swf.c`: `tagMain` (the eligibility-mark slot).
- `action.c`: `actionDispatchEnterFrameHandlers`, `dispatch_root_dprops_enterframe` (static).
- `action.h`: `struct MovieClip` gains the trailing field `size_t ef_fired_tick`.
- **No edits to `swf_core.c` or `tag.c`.**

---

## 1. Mode divergence: dynamic-MC enterFrame eligibility

### 1.1 Mechanism

`actionMarkDynamicMCsEnterFrameEligible` sets `mc_enterframe_eligible` on every clip with `display_obj == NULL` (createEmptyMovieClip, duplicate/attach clones without a DL entry, `_levelN` roots). `actionDispatchEnterFrameHandlers` skips any such clip whose flag is 0.

| loop | order after the root frame func |
|---|---|
| `swf_core.c swfStart` (no-graphics) | fallback flush → Phase-3 `advance_nested_sprite_frames` → `actionDrainActionQueueByKind(SCRIPT)` (fires a stopped root's deferred `_root.onEnterFrame`) → `ng_fire_pending_attach_inits` → `ng_apply_pending_sprite_self_gotos` → `ng_promote_attached_playheads` → **mark** |
| `swf.c tagMain` (graphics, before) | fallback flush → **mark** → Phase 3 → SCRIPT drain → attach-inits → promote → self-gotos |

A clip created by any script that runs after the graphics mark misses it. Those scripts are: a nested (Phase-3) sprite frame script, a stopped root's deferred `onEnterFrame`, or an attach-init (frame-1) script. Such a clip is still ineligible at the next tick's flush, so **in graphics its first `onEnterFrame` came one tick late.**

### 1.2 Which one is right

Ruffle and Flash fire the first `onEnterFrame` the tick AFTER creation, whichever script created the clip:
- `avm1/globals/movie_clip.rs` `create_empty_movie_clip` → `post_instantiation(.., run_frame=true)`.
- That calls `construct_as_avm1_object` → `run_frame_avm1`, which dispatches **Load** and sets `INITIALIZED` at creation (`display_object/movie_clip.rs:457-466`).
- The clip is head-pushed onto `clip_exec_list` (`add_to_exec_list`).
- So the next `Avm1::run_frame` walk (`avm1/runtime.rs:500-526`) dispatches `EnterFrame`.

The Flash side of the same rule (created on tick N, first enterFrame on N+1) is already locked by `avm1/create_empty_movie_clip`. **no-graphics (`swf_core.c`) matches; graphics was wrong.**

### 1.3 Fixture (distinguishes the two orders)

`w1-exec-order-fixtures/avm1_exec_order_dynamic_eligible/` (generated SWF8, 3 root frames, root stops on frame 3; `_root.onEnterFrame` increments `_root.t`). Three clips with `onEnterFrame` tracing `<name> ef t=<t>`:
- `e`: created by the frame-2 script of `inner`, a sprite nested in `outer` (a Phase-3 script).
- `d`: created by the stopped root's `_root.onEnterFrame` at t==4 (a deferred-root, SCRIPT-drain script).
- `g`: created by the frame-1 attach-init script of the attachMovie'd `ai` at t==6.

The first `onEnterFrame` of each clip:

| clip | no-graphics (= Ruffle rule) | graphics before | graphics after patch |
|---|---|---|---|
| `e` | `e ef t=1` (tick after creation) | first is `e ef t=2` (**one tick late**) | `e ef t=1` |
| `d` | `d ef t=4` | `d ef t=5` (late) | `d ef t=4` |
| `g` | `g ef t=6` | `g ef t=7` (late) | `g ef t=6` |

After the patch, graphics output is **byte-identical** to no-graphics (35 lines; `ours_nographics.txt`).

The fixture is not yet promoted to `regression/`: its golden must come from the exporter (see LOCAL ORACLE REQUESTS). The rows that matter are the first `e ef` / `d ef` / `g ef` lines. Other lines (sibling order, the leading `inner f1`) are whatever Ruffle says.

### 1.4 Fix (in the prototype patch)

`swf.c tagMain`:
- The mark now runs at its old slot **only in the browser build** (`#ifndef OFFSCREEN_RENDER`). That build has no SCRIPT drain at that point, so it keeps its s26 n-pixel-pass behaviour.
- In `OFFSCREEN_RENDER` it moves to the end of the post-frame-func block, after `ng_apply_pending_sprite_self_gotos`. That is the same position as `swf_core.c` (last of the post-frame steps).

### 1.5 Price (graphics sweep)

**Candidates:** every SWF in `avm1`, `from_gnash`, `from_shumway`, `regression` whose decompressed bytes contain `onEnterFrame` AND one of `createEmptyMovieClip`/`attachMovie`/`duplicateMovieClip`/`loadMovie`/`createTextField`. That is **115 rows**, run in `--mode=graphics`.

**Probe (removed):**
- At the new mark slot it recorded every dynamic MC still ineligible, i.e. created between the old and new slots.
- It logged when one of those actually dispatched `onEnterFrame` on the next flush.

**Results:**
- **13 corpus rows hit the probe:**
  - `avm1/create_empty_movie_clip`
  - `avm1/movieclip_invalid_get_bounds_1..4`
  - `avm1/remove_different_level`
  - gnash `MovieClip-v6/v7/v8`
  - `misc-ming.all/DragDropTest`, `DrawingApiTest`, `NetStream-SquareTest`, `ResolveEventsTest`
  - plus 3 regression rows that save actual (`avm1_closure_base_clip_root_frame`, `avm1_removed_clip_dprops_gc`, `enterframe_type1_args`)
- A/B with `--save-actual`: **all 13 are byte-identical before vs after in graphics, and identical to no-graphics.** The probe overcounts: `actionDispatchEnterFrameHandlers` also marks at its own tail, so another dispatch in the same tick had already armed most of them.
- **115/115 rows keep their baseline status. 0 moves, 0 flips. Only the fixture changes.**

---

## 2. action_order family after root-last (rows re-measured, both modes)

`--save-actual` in both modes; the graphics output equals no-graphics byte for byte on all 7 rows (before and after the prototype). "LCS" is the matching-line count against Flash's `output.txt`.

| row | baseline status | exp / actual (s20 → now) | first diverging line (Flash vs ours) | mechanism (bucket from `session20 w1-gnash-actionorder` §1) |
|---|---|---|---|---|
| `ActionOrderTest3` | output_mismatch, KF | 62 / 83 → 83 | **L4** `static unload: undefined` vs `static unload: 0` (Ruffle = Flash to L62) | **B4.** The outgoing `Segments` clip's static `onClipEvent(unload)` reads `this.c` from the *replacement* registered-class `Segments` (c=0) at the same depth/name. The unload runs after the inter-tag replacement, so `this` resolves to the new clip. Next missing: `dynamic load: 0` |
| `ActionOrderTest4` | output_mismatch, KF | 64 / 94 → 94 | **L9** an extra `onEnterFrame` between `Frame 3 actions: 0` and `Frame 2 actions: 0` (Ruffle = Flash to L64) | **NEW, §2.1.** The backward `gotoAndPlay(2)` from frame 3 re-fires `_root.onEnterFrame` twice. With the prototype, the first divergence moves to **L13**: `dynamic unload: 0` before `ctor: 1` (B4 loop-back identity) |
| `ActionOrderTest5` | output_mismatch, KF | 51 / 58 → 58 | **L4** `onEnterFrame` vs `dynamic load: 0` | **Ruffle-shared.** `output.ruffle.txt` diverges at the **same line with the same text as ours**: Flash defers this onLoad past the next enterFrame and frame script. Not exec-list. Behind it, the same extra-ef rows as AOT4 |
| `PlaceAndRemove` | output_mismatch, KF panic, no Ruffle sidecar | 91 (fp9) / 45 → 45 | **L2** `Done` vs `moo 1` + `FAILED: This MovieClip should never be constructed` | **B3.** Place+remove cancellation within one goto sweep. Also completes 15 of 96 cycles in 30 ticks |
| `action_execution_order_extend_test` | output_mismatch, KF | 31 (fp9) / 28 → 28 | **L8** missing `mc_red load executed` | **B2.** The onLoad *method* of a timeline-placed sprite is never dispatched. Bug 2 behind it (`mc_blu`/`mc_red` enterFrame order) is the B1 exec-list interleave |
| `action_execution_order_test11` | output_mismatch, no sidecar | 32 / 32 → 32 | **L8/9** `mc21 onLoad` ↔ `mc1 onEnterFrame` swapped; `doActionOrder 0+2+1+…`, `asOrder` | **B1, the only true sibling-exec-list row.** Byte-identical to s14–s20 |

**Root-last (`4e66127cc`) moved line order inside AOT3/4/5 but no actual-line count.** The s20 counts are reproduced exactly.

### 2.1 NEW: the goto catch-up fires `onEnterFrame` twice more

**Fixture:** `w1-exec-order-fixtures/avm1_goto_backward_enterframe_once/`.
- Root has 4 frames and a `_root.onEnterFrame` tracing `onEnterFrame`. Frame 3 does `gotoAndPlay(2)` while `loops < 3`.
- The `plain` variant has no sprites and no init actions. The variants `sprite`/`init`/`uncond` behave the same way.

| | one loop tick |
|---|---|
| Flash (gnash AOT3/4/5 goldens, L6–8 / L7–9) and Ruffle (`run_goto` → `run_frame_internal` on the target frame queues its DoAction in the same tick, `movie_clip.rs:1880-1895`) | `onEnterFrame, Frame 3, Frame 2` |
| ours, both modes, kill switch `SWF_EXEC_ORDER_ROOT_LAST=0` changes nothing | `onEnterFrame, Frame 3, onEnterFrame, onEnterFrame, Frame 2` |
| prototype, both modes | `onEnterFrame, Frame 3, Frame 2` |

**Owner:**
- `swf_core.c` and `swf.c` `ng_executeGotoCatchUp` Phase F call `ng_run_deferred_sprite_init_before` and `ng_run_deferred_sprite_init_on_or_after`.
- Both go through `tag.c ng_run_deferred_sprite_init_impl`, which **ends with `actionDispatchEnterFrameHandlers`**.
- That dispatcher re-runs the `_root` arm (`g_root_enterframe_eligible`) and every dynamic MC (whose `mc_enterframe_eligible` is never consumed).
- Display-list sprites are safe because their `enterframe_eligible` is consumed per tick.
- So every inline goto adds two extra `onEnterFrame` calls to `_root` and to each `createEmptyMovieClip` clip.

**Prototype fix:** exactly one `onEnterFrame` per clip per tick.
- `size_t ef_fired_tick` stamped with `g_tick_count` in the children loop of `actionDispatchEnterFrameHandlers`, and at the top of `dispatch_root_dprops_enterframe`. The deferred root arm also goes through the latter.
- This is the Ruffle invariant: `run_frame` walks each clip once per frame.
- I chose a guard over deleting the dispatch in `ng_run_deferred_sprite_init_impl`. That call still serves the not-yet-consumed DL sprites it was written for, which the guard does not touch.

**Price (no-graphics sweep with a logging guard):**
- **323 rows**: every SWF containing `onEnterFrame` in `avm1`/`from_gnash`/`from_shumway`/`regression`.
- The guard suppressed a call on **5 rows**:
  - `ActionOrderTest3`/`4`/`5`: 10 root calls each.
  - `misc-swfc.all/gotoFrameFromInterval`/`2`: 2 each. Those two are **byte-identical before vs after** in both modes (`gotoFrameFromInterval2` still equals `output.ruffle.txt` byte for byte).
- **0 status moves on all 324 sweep lines** vs the no-graphics baseline (`81d32b9b2`).
- Moves:

| row | LCS vs Flash | actual lines | first divergence |
|---|---|---|---|
| AOT3 | 18 → 19 | 83 → 73 | L4 (unchanged) |
| AOT4 | 30 → 31 | 94 → 84 | L9 → L13 |
| AOT5 | 24 (unchanged) | 58 → 48 | L4 (unchanged) |

  All three are KF rows; none reaches `ruffle_matched`, since B4 sits behind it.
- Graphics headline check with the full prototype: the 7 family rows, both fixtures, and 19 regression rows (`avm1_attach*`, `avm1_attached_clip_*`, `avm1_exec_order_attached_selfremove`, `enterframe_type1_args`, `root_enterframe_cross_swf_version`, `avm2_goto_catchup_scale`) are **19/19 PASS**, and the family rows are byte-identical across modes.

**Recommendation:**
- Land 2a with item 1 as one small runtime-correctness slice.
- It buys no flip. Its value is that **every game that does `_root.onEnterFrame` plus a frame-script goto ran its per-frame handler 3× on goto ticks**: physics, counters and timers advance 3× on those frames.
- It needs both CI legs.
- Promote `avm1_goto_backward_enterframe_once` to `regression/` once the exporter golden exists.

---

## 3. Pricing the flat, instantiation-ordered exec-list rewrite

**Premise attack:**
- The brief prices this as the completion mechanism of "the action_order family". The first-divergence table refutes that.
- Only `test11`, plus bug 2 of `_extend_test`, first-diverges on the per-clip interleave.
- AOT3/4 and RCT4 first-diverge on B4 (loop-back unload/ctor identity), PlaceAndRemove on B3, `_extend_test` on B2, and AOT5 on a divergence Ruffle shares.
- So the rewrite's priced corpus yield is **0 flips**:
  - `test11` is all-or-nothing (no sidecar) and also fails `asOrder`, which is the same interleave on a longer trace. It is plausible as a +1 *only* if phase 3 below is exact.
  - `_extend_test` also needs B2.
  - The arc's real customers are N's telemetry (`n-exec-order-report.md` §3) and the parked sibling fixture (`SWFRecompDocs/plans/n-exec-order-sibling-fixture`).

**Phase plan, in case someone funds it for game fidelity rather than corpus yield:**

| phase | scope | size | risk / blast radius |
|---|---|---|---|
| P0 | Give `MovieClip` an instantiation serial (stamped where clips enter `child_mc_cache`, root = 0). Add an env-gated exec-trace hook that logs `(serial, kind)` per dispatched enterFrame and frame script per tick. Build the A/B harness on the 343-row `onEnterFrame` list + the sibling fixture. | S | none (instrumentation) |
| P1 | One enterFrame walk: merge `dispatch_root_enterframe_clip_actions` (clip-event, DL-recursive, children before parents) and `actionDispatchEnterFrameHandlers` (`child_mc_cache` reverse) into one serial-descending walk. Each clip gets clip-event EF then `onEnterFrame`, root last. Keep `tagFlushPendingEnterFrame` as the only caller (with the 2a guard). | M | every avm1 clip-event row with ≥2 clips having both kinds; gnash clip-event rows |
| P2 | Per-clip interleave: queue each enterFrame as an `AQ_KIND_SCRIPT` entry keyed by clip serial. Stable-sort the tick's SCRIPT entries by `(serial desc, EF before frame script)` before the drain, so the advance code (`advance_sprite_frames` / `advance_nested_sprite_frames` / `ng_advance_attached_clip_playheads`) does not have to move. Then retire `presync_nested_sprite_currentframe`, which exists only to paper over the phase split. | L | the hundreds of rows with ≥2 scripted children (n-exec-order §2b estimate); every `Recompiled*` cache stays valid |
| P3 | Root frame and goto paths: the recompiler-emitted `tagFlushPendingEnterFrame` call before each root DoAction (`SWFRecomp/src/swf.cpp:1237/1601/1664`), the Phase E/F inline catch-up (`ng_executeGotoCatchUp`, `ng_run_deferred_sprite_init_impl`), and root-last (`g_root_ef_pending`) re-derived against the sorted queue. | L | recompiler change; full corpus cache invalidation; both CI modes; the goto rows (`gotoFrame*`, `goto_rewind*`, `loop_test*`) |

**Total: XL**, about 2–3 dedicated one-task sessions, not fan-out slots. Each phase is gated on a zero-move A/B. **Priced corpus flips: 0** (+1 `test11` speculative after P3). **NO-GO for the fan-out stands.** Completion mechanism: the four phases above, P0 first, with the parked sibling fixture as the acceptance test.

---

## 4. RegisterClassTest4 (mechanism only)

| line | Flash | Ruffle | ours |
|---|---|---|---|
| 3–4 | `2 0`, `load … c: 0` | `load … c: 0`, `2 0` | `load … c: 0`, `2 0` (= Ruffle) |
| 8–9 | `Bug ctor: 1`, `unload … c: 0` | `Bug ctor: 1`, `unload … c: 0` | `unload … c: 0`, `2 undefined` … |

- The first Flash divergence (L3: the registered-class onLoad fires before the child DoAction `2 0`) is shared with Ruffle. This is the documented ACCEPTED_DIFFS item 1.
- **Our own** first divergence is L8. On the `mc` sprite's loop-back, ours fires the old `Segments`' unload before the new instance's ctor, and then reads `_level0.mc.Segments.c` through the removed clip (`undefined`, ACCEPTED_DIFFS item 2).
- That is **B4** (inter-tag UNLOAD / sprite-rewind identity, `blocked/INTER_TAG_UNLOAD_PLAN.md` + `blocked/SPRITE_REWIND_IDENTITY_PLAN.md`), the same signature as AOT4's post-prototype L13 (`dynamic unload: 0` before `ctor: 1`).
- **Not the exec-list family.** The 2a guard does not touch it (0 guard hits, byte-identical). The STRIKE stands; completion mechanism unchanged: B4 plans landing together.

---

## 5. Refutations / corrections to the brief

1. "This touches no-graphics-only code": **false.** The divergent loop is graphics (`swf.c`), and the fix is in its `OFFSCREEN_RENDER` arm. Item 1 needs only the graphics leg. Item 2a (`action.c`, shared) needs both.
2. "Marks dynamic MovieClips eligible (for enterFrame / frame scripts)": the mark gates **only `onEnterFrame` property handlers** of DL-less clips (`actionDispatchEnterFrameHandlers`). Frame scripts and clip events never read it.
3. "action_order family" as one exec-order family: **refuted** (§2). One row of six is the exec-list interleave.
4. AOT3/4/5's long-standing extra `onEnterFrame` rows were never exec order. They are the goto double-dispatch (§2.1).

## 6. New unclaimed leads

- **2a itself** (XS, shared runtime): land it with item 1 for game fidelity. Any title using `_root.onEnterFrame` plus frame-script gotos is affected. Check the browser build: `swf.c`'s browser loop may call `ng_run_deferred_sprite_init*` through the same `ng_executeGotoCatchUp`; the guard covers it too, but this is untested in WASM.
- `swf.c` OFFSCREEN runs `ng_promote_attached_playheads` *before* `ng_apply_pending_sprite_self_gotos`; `swf_core.c` runs it after. This is a second, unverified mode-order difference in the same block. A self-goto on an attached clip attached this tick would show it (XS probe).
- AOT3 L4 (B4 sub-case): a static `onClipEvent(unload)` of an inter-tag-replaced clip reads `this` as the replacement. A narrower lead than the whole B4 plan: dispatch the unload with the outgoing clip's own MovieClip as `this`, not a name lookup. Worth a fixture before pricing.

## LOCAL ORACLE REQUESTS

1. `SWFRecompDocs/plans/session27-fanout-reports/w1-exec-order-fixtures/avm1_exec_order_dynamic_eligible/test.swf`: `exporter -s -f 10 --trace-log out.txt test.swf out.png`. I need the full trace as `output.txt`. Check: the first `e ef`, `d ef` and `g ef` lines read `t=1`, `t=4` and `t=6` (the line after `inner f2 creates e t=1` / `root ef creates d t=4` / `ai f1 creates g t=6`, before the following `root ef`). No timers in the SWF.
2. `…/avm1_goto_backward_enterframe_once/test.swf`: `exporter -s -f 14 --trace-log out.txt`. I need the full trace. Check: every loop tick reads `onEnterFrame, Frame 3, Frame 2` (no `onEnterFrame` between Frame 3 and Frame 2).

With those goldens, both fixtures can move to `ruffle-tests/tests/swfs/regression/` (README rows) in wave 2 alongside the prototype.
