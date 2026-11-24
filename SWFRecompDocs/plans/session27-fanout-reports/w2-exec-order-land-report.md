# w2-exec-order-land — wave-2 implementation (session 27, dual-axis #19)

**New files:**
- `SWFRecompDocs/plans/session27-fanout-reports/w2-exec-order-land-report.md` (this file)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-exec-order-land.patch`: the landing patch (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <2 fixture dirs>`)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-exec-order-land-initaction-proposal.patch`: the **proposal-only** recompiler hunk for item 3. It is NOT part of the landing patch; it goes to `w2-timers-land`.
- `ruffle-tests/tests/swfs/regression/avm1_exec_order_dynamic_eligible/` (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt` = Flash `flash.wrapped.txt`)
- `ruffle-tests/tests/swfs/regression/avm1_goto_backward_enterframe_once/` (same layout, `output.txt` = Flash `flash.wrapped.txt`)

**Measurement setup:**
- Box: `SETUP_STATUS` all OK (Dawn/lavapipe). Base `origin/master` `53540ff0`.
- Corpus: `download_tests.sh avm1 from_gnash from_shumway`, plus `avm2 visual text fonts` for the canary. Upstream Ruffle HEAD `1e604fa87`.
- Baselines: graphics = wave-0 run `45300086369` (`origin/ruffle-test-results` `da51f878`, code `d70f2c0aa`); no-graphics = `81d32b9b2`.

---

## 0. Verdicts and priced flips

| # | Item | Verdict | Trace flips | Pixel flips |
|---|---|---|---|---|
| 1 | Land the w1 prototype: the `swf.c tagMain` eligibility mark + the one-`onEnterFrame`-per-tick guard | **GO, landed.** | the 2 new regression fixtures; 0 corpus rows | 0 |
| 2 | Nested-frame order: our nested child ran its frame after the root's enterFrame/DoAction; Flash runs it before | **GO, landed (contained, S).** Root cause: the **Phase-3 deferral** of nested sprite advance (`advance_nested_sprite_frames` ran after the root frame func). It is **not root-last** (`4e66127cc`) and **not the flat exec-list** gap. The fix runs the nested pass FIRST, before Phase 1. | `regression/avm1_exec_order_dynamic_eligible` (with item 1); 0 corpus status moves on 423 rows × 2 modes | 0 (canary, §4) |
| 3 | Same-frame DoInitAction after the frame's placements (`movieclip_destruction_test1`) | **Measured PROPOSAL only.** It is a recompiler emission change (`swf.cpp`), not frame-loop code, so it belongs to `w2-timers-land` (owner of DoInitAction emission). Patch: `w2-exec-order-land-initaction-proposal.patch`. | 0 (124 DoInitAction rows: 0 status moves, 3 rows closer to Flash) | — |
| 4 | Both CI modes | Every headline was run in graphics AND no-graphics. Outputs are byte-identical across modes on 422/423 sweep rows. The exception is `PlaceAndRemove` (KF panic row, §3.4). | — | — |

### EXPECTED-FLIP LEDGER (check CI against this)

**Trace axis, both modes (graphics AND no-graphics):**
- `regression/avm1_exec_order_dynamic_eligible`: NEW row, **pass**.
- `regression/avm1_goto_backward_enterframe_once`: NEW row, **pass**.
- **No corpus row changes status.** On 423 rows × 2 modes there were 0 moves vs `da51f878` / `81d32b9b2`.
- Byte-only movers, status unchanged (any status move on these is unexpected):
  - `from_gnash/misc-ming.all/action_order/ActionOrderTest3`, `ActionOrderTest4`, `ActionOrderTest5`
  - `action_execution_order_extend_test`, `action_execution_order_test11`
  - `PlaceAndRemove` (graphics only)

**Pixel axis:** **none.** Canary 220/220 md5-identical. No image row is expected to move.

**Upstream drift** is not mine to claim: note any row absent from the baseline JSON.

**CI mode:** shared runtime (`action.c`, `swf_core.c`, `swf.c`). **Run both legs**: graphics + no-graphics, `categories=all` (AVM1-only change).

**Functions touched:**
- `SWFModernRuntime/src/libswf/swf.c`:
  - `tagMain`: eligibility-mark slot (w1); nested-pass-early call + `presync_nested_sprite_currentframe` gate + the late Phase-3 gate, all `OFFSCREEN_RENDER` only.
  - new `static exec_order_nested_early` (OFFSCREEN only).
- `SWFModernRuntime/src/libswf/swf_core.c`:
  - `swfStart` playing branch: nested-pass-early call, presync gate, late Phase-3 gate.
  - new `static exec_order_nested_early`.
  - The past-last-frame branch is untouched (see §2.3).
- `SWFModernRuntime/src/actionmodern/action.c`: `actionDispatchEnterFrameHandlers`, `static dispatch_root_dprops_enterframe` (w1 guard, verbatim).
- `SWFModernRuntime/include/actionmodern/action.h`: `struct MovieClip` gains the trailing field `size_t ef_fired_tick` (w1, verbatim).
- `ruffle-tests/render_canary_tests.txt`: 4 covering members appended at EOF.
- **No edits to `tag.c`, `swf.cpp`, `timer.c`, `tag_stubs.c`.** The browser-WASM arm of `swf.c` keeps its order.

Kill switch for A/B: `SWF_EXEC_ORDER_NESTED_EARLY=0` restores the old Phase-3 slot. The w1 guard has no switch, as in the prototype.

---

## 1. Item 1: the prototype, landed verbatim

The w1 patch applied cleanly to `53540ff0`. It is unchanged in the landing patch except for context. Both fixtures are now under `regression/`, and their goldens are the coordinator's **Flash** captures:
- `w1-local-oracles/w1-exec-order/<fixture>/flash.wrapped.txt`.
- The cut is at `num_frames`: 10 frames for `dynamic_eligible`, 14 for `goto_backward`.
- Flash == Ruffle byte for byte on both.

`avm1_goto_backward_enterframe_once` passes with the prototype alone (every loop tick reads `onEnterFrame, Frame 3, Frame 2`). `avm1_exec_order_dynamic_eligible` also needed item 2.

## 2. Item 2: the nested-frame order

### 2.1 Mechanism (owner)

One tick of the old loop (`swf_core.c swfStart`, and its `swf.c tagMain` OFFSCREEN twin):

1. **Phase 1**: `advance_sprite_frames` with `g_advance_defer_nested=1` advances the ROOT-LEVEL sprites only, and their scripts queue.
2. The attached pump, then `presync_nested_sprite_currentframe`.
3. **Root frame func**: the recompiler-emitted drain runs the queued Phase-1 scripts. Root-last fires `_root.onEnterFrame` right before the first root DoAction pops (`aq_pre_dispatch`). Then the root DoAction runs.
4. **Phase 3**: `advance_nested_sprite_frames` advances sprites nested inside root-level sprites. **Their frame scripts queue only now**, and drain in the Phase-7b `actionDrainActionQueueByKind(SCRIPT)`.

So on any tick where a nested sprite (`outer.inner`) advances, its frame script ran **after** `_root.onEnterFrame` and the root's DoAction.

Ruffle (`avm1/runtime.rs:500-526 run_frame`) walks `clip_exec_list` newest-first, and each clip queues its enterFrame and frame actions. `inner` is instantiated after `outer`, and both after `_root`, so the queue reads `inner`, `outer`, `_root` (root last). Flash agrees on the fixture: `inner f2 creates e t=0` comes before `root ef t=1`.

**Brief question answered: neither root-last nor the exec-list.** Root-last (`4e66127cc`) is correct and stays. It can only defer the root arm to after scripts that are already *queued*, and the nested scripts were not queued yet. The full sibling exec-list interleave (w1 §3, XL) is a different, finer gap. This one was a coarse phase split, and it is contained.

### 2.2 Fix

The nested pass runs **first**, before Phase 1: `exec_order_nested_early()` in both loops. With it:
- `presync_nested_sprite_currentframe` is skipped. It existed only to paper over the phase split, and it would read one frame ahead.
- The late Phase-3 call is skipped.

**Why before Phase 1 and not right after it.** I measured right-after first, and it regressed `avm1/execution_order4`, a Flash-IDE golden (`test.fla`). `clip1` places `child` on its frame 2:
- Flash runs `child`'s next frame FIRST on the following tick (`clip1.child: frame 2` precedes `clip2`/`clip1: frame 3`). That is exec-list newest-first.
- With the nested pass after Phase 1, `child` advanced on the same tick `clip1` placed it.

Before Phase 1 is both the faithful order and the passing one.

**Removal safety.** Running a child before its parent's tags means that when the parent removes the child this tick, the child has already queued its script. Ruffle drops such actions (`player.rs:2174-2177`: "We don't run frame actions if the clip was removed (or scheduled to be removed) after it queued the action"). Ours does the same: `action_queue.c aq_sprite_ctx_removed` checks the clip and its ancestors for `avm1_removed` / `pending_removal` / `INT_MIN`. That is exactly what moves `PlaceAndRemove` toward Flash in graphics (§3.4).

### 2.3 Scope limits (deliberate)

- **The past-last-frame branch of `swf_core.c` is unchanged.** It dispatches `onEnterFrame` directly, not through the deferred flush, and drains scripts after that. Moving the nested pass there changes no script order, so I left it alone.
- **Browser-WASM keeps its order.** It advances timeline sprites inside `tagShowFrame`, CI does not cover it, and there is no Flash measurement for it. The `swf.c` hunks are `#ifdef OFFSCREEN_RENDER`.
- **Nested vs. a newer ROOT-LEVEL sibling.** A root-level clip placed after `outer.inner` should run before `inner` in Flash; ours still runs every nested sprite before every root-level one. That is the sibling exec-list interleave (w1 §3 P2), still NO-GO. `action_execution_order_test11`'s `asOrder` is that row (§3.3).

## 3. Evidence

### 3.1 Headline before/after (same box; before = clean `origin/master`, after = this patch)

| row | mode | status before → after | Flash LCS before → after (expected lines) | actual lines before → after | bytes |
|---|---|---|---|---|---|
| `regression/avm1_exec_order_dynamic_eligible` | NG | mismatch → pass | 33 → 35 (35) | 35 → 35 | moved |
| `regression/avm1_exec_order_dynamic_eligible` | GR | mismatch → pass | 30 → 35 (35) | 32 → 35 | moved |
| `regression/avm1_goto_backward_enterframe_once` | NG | mismatch → pass | 22 → 22 (22) | 28 → 22 | moved |
| `regression/avm1_goto_backward_enterframe_once` | GR | mismatch → pass | 22 → 22 (22) | 28 → 22 | moved |
| `regression/avm1_exec_order_attached_selfremove` | NG | pass → pass | 18 → 18 (18) | 18 → 18 | identical |
| `regression/avm1_exec_order_attached_selfremove` | GR | pass → pass | 18 → 18 (18) | 18 → 18 | identical |
| `regression/avm1_attach_from_stopped_root_enterframe` | NG | pass → pass | 13 → 13 (13) | 13 → 13 | identical |
| `regression/avm1_attach_from_stopped_root_enterframe` | GR | pass → pass | 13 → 13 (13) | 13 → 13 | identical |
| `avm1/execution_order4` | NG | pass → pass | 12 → 12 (12) | 12 → 12 | identical |
| `avm1/execution_order4` | GR | pass → pass | 12 → 12 (12) | 12 → 12 | identical |
| `avm1/hitarea_lazy_getter` | NG | pass → pass | 6 → 6 (6) | 6 → 6 | identical |
| `avm1/hitarea_lazy_getter` | GR | pass → pass | 6 → 6 (6) | 6 → 6 | identical |
| `avm1/hitarea_remove_owner_drag` | NG | pass → pass | 10 → 10 (10) | 10 → 10 | identical |
| `avm1/hitarea_remove_owner_drag` | GR | pass → pass | 10 → 10 (10) | 10 → 10 | identical |
| `avm1/hitarea_remove_sibling` | NG | pass → pass | 4 → 4 (4) | 4 → 4 | identical |
| `avm1/hitarea_remove_sibling` | GR | pass → pass | 4 → 4 (4) | 4 → 4 | identical |
| `avm1/hitarea_sweep` | NG | pass → pass | 33 → 33 (33) | 33 → 33 | identical |
| `avm1/hitarea_sweep` | GR | pass → pass | 33 → 33 (33) | 33 → 33 | identical |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest3` | NG | mismatch → mismatch | 18 → 19 (62) | 83 → 73 | moved |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest3` | GR | mismatch → mismatch | 18 → 19 (62) | 83 → 73 | moved |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest4` | NG | mismatch → mismatch | 30 → 31 (64) | 94 → 84 | moved |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest4` | GR | mismatch → mismatch | 30 → 31 (64) | 94 → 84 | moved |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest5` | NG | mismatch → mismatch | 24 → 24 (51) | 58 → 48 | moved |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest5` | GR | mismatch → mismatch | 24 → 24 (51) | 58 → 48 | moved |
| `from_gnash/misc-ming.all/action_order/PlaceAndRemove` (output.fp9.txt) | NG | mismatch → mismatch | 15 → 15 (91) | 45 → 45 | identical |
| `from_gnash/misc-ming.all/action_order/PlaceAndRemove` (output.fp9.txt) | GR | mismatch → mismatch | 15 → 15 (91) | 45 → 15 | moved |
| `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` (output.fp9.txt) | NG | mismatch → mismatch | 22 → 23 (31) | 28 → 28 | moved |
| `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` (output.fp9.txt) | GR | mismatch → mismatch | 22 → 23 (31) | 28 → 28 | moved |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | NG | mismatch → mismatch | 27 → 27 (32) | 32 → 32 | moved |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | GR | mismatch → mismatch | 27 → 27 (32) | 32 → 32 | moved |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | NG | ruffle_matched → ruffle_matched | 21 → 21 (26) | 26 → 26 | identical |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | GR | ruffle_matched → ruffle_matched | 21 → 21 (26) | 26 → 26 | identical |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | NG | ruffle_matched → ruffle_matched | 18 → 18 (23) | 23 → 23 | identical |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | GR | ruffle_matched → ruffle_matched | 18 → 18 (23) | 23 → 23 | identical |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | NG | ruffle_matched → ruffle_matched | 20 → 20 (23) | 23 → 23 | identical |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | GR | ruffle_matched → ruffle_matched | 20 → 20 (23) | 23 → 23 | identical |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | NG | ruffle_matched → ruffle_matched | 35 → 35 (52) | 50 → 50 | identical |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | GR | ruffle_matched → ruffle_matched | 35 → 35 (52) | 50 → 50 | identical |

Both legs are **this box, same corpus download**.
- "before" = clean `origin/master` (`53540ff0`).
- "after" = this patch.
- LCS = matching lines vs the Flash golden (`output.txt`; gnash fp9 rows vs `output.fp9.txt`).

What the table shows:
- `dynamic_eligible` graphics "before" had 32 lines: the late eligibility mark of item 1, plus the nested order of item 2.
- AOT3/4/5 move exactly as w1 measured: the goto catch-up's two extra `onEnterFrame` calls per loop tick are gone.

### 3.2 Sweep (423 rows × 2 modes)

**Candidates (423):**
- every SWF in `avm1`/`from_gnash`/`from_shumway`/`regression` whose decompressed bytes contain `onEnterFrame`. This is the w1 323-row set (now 312 + overlap);
- ∪ every SWF with a DefineSprite that places another DefineSprite (nested timeline sprites; 111 rows, the only rows the nested pass can touch).

**Legs:**
- *after* (full patch) on all 423 rows in both modes.
- *after with `SWF_EXEC_ORDER_NESTED_EARLY=0`* on the 111 nested rows in both modes: the clean A/B of item 2.

**Results:**
- **Status vs the CI baselines** (`da51f878` graphics, `81d32b9b2` no-graphics): **0 moves on 423 rows in either mode.** The only new rows are the 2 fixtures (PASS) and `avm2_edittext_placed_cxform`, which is not in the baselines.
- **Item-2 A/B (111 nested rows):**

| row | mode | status (both legs) | bytes | vs Flash |
|---|---|---|---|---|
| `regression/avm1_exec_order_dynamic_eligible` | both | MISMATCH → **PASS** | moved | = Flash |
| `misc-ming.all/action_order/action_execution_order_extend_test` (KF) | both | MISMATCH | moved | **closer**: LCS +1 on all 4 goldens (fp9 22→23/31, fp10 21→22/32); `_root.x2 == 'as_in_root'` FAILED → PASSED (`mc_blu`'s frame 2 now runs before the root frame) |
| `misc-ming.all/action_order/action_execution_order_test11` (no sidecar) | both | MISMATCH | moved | line LCS unchanged 27/32; `asOrder` token LCS 25 → 24/30. The B1 sibling interleave (§2.3): Flash interleaves nested and root-level clips by instantiation order, and both of our orders are wrong |
| `misc-ming.all/action_order/PlaceAndRemove` (KF panic) | **graphics only** | MISMATCH | 45 → 15 lines | **closer**: the 15 lines equal Flash's first 15 (`Done` ×15); the 15 bogus `moo N` + `FAILED: This MovieClip should never be constructed` pairs are gone. No-graphics is unchanged (§3.4) |
| other 107 nested rows | both | unchanged | **byte-identical** | — |

- **Item-1 rows** (the w1 guard, priced by w1 on 323 rows): AOT3/4/5 move as w1 measured (§3.1). `gotoFrameFromInterval`/`2` are byte-identical.

### 3.3 action_order family and the s26 fixtures

All of these are in §3.1 in both modes:
- `ActionOrderTest3/4/5`, `PlaceAndRemove`, `_extend_test`, `test11`, `action_execution_order_test4`;
- `gotoFrameFromInterval`/`2`, `movieclip_destruction_test1`;
- the s26 `regression/avm1_attach_from_stopped_root_enterframe` and `avm1_exec_order_attached_selfremove`;
- `avm1/hitarea_*` (the `_droptarget` rows from root-last).

No status moves.

### 3.4 Mode-parity note: `PlaceAndRemove` (KF panic row)

Before the patch, both modes printed 45 identical lines. After it, graphics prints 15 lines (= Flash's prefix), and no-graphics still prints 45.

**Structure:**
- root → `sprite6` (2 frames; frame 2 places `sprite5`);
- `sprite5` (frame 1 `doStuff`/`setTimeout`; frame 2 places `sprite4`);
- `sprite4`'s frame-1 script is the "should never be constructed" check.

**What graphics does now:** the nested `sprite5` advances to frame 2 (placing `sprite4`) before `sprite6` loops back and removes it. `sprite4`'s queued frame-1 script is then dropped by `aq_sprite_ctx_removed` (ancestor removed), which is the Ruffle rule.

**Likely no-graphics owner, not fixed:** the NO_GRAPHICS arm runs a newly placed child's frame 1 inline (`process_sprite_needs_init` in `advance_sprite_frames`) instead of queueing it, so nothing drops it.

**Impact:** status MISMATCH in both modes, before and after. The row has 91/96 Flash lines in 30 ticks, so no flip is possible. It is a new lead (§6), not a regression. The graded mode moved toward Flash.

## 4. Canary

`ruffle-tests/render_canary.py capture` over the standing set plus the 4 members appended at EOF. The new members are nested-sprite image rows, because the standing set held only 1 of the 111 nested-sprite rows:
- `from_shumway/timeline/timeline_as2_5`
- `timeline/timeline_loop`
- `acid/acid-child`
- `regression/avm1_nested_po3_filters`

Setup: `--jobs 2`, `--timeout 5400`, `before` = clean `origin/master`, `after` = this patch.

```
RENDER CANARY  before=before  after=after   154 tests / 220 comparisons
  IDENTICAL   220
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**220/220 md5-identical. Pixel ledger: empty.**

## 5. Item 3: same-frame DoInitAction (measured proposal, for `w2-timers-land`)

**Flash rule** (`movieclip_destruction_test1`, Flash golden lines 35–44): frame 12's DoInitAction for sprite 8 sees `mc6`, which is placed before the init tag. It also sees **`mc7`, which is placed AFTER the init tag in the same frame**. So Flash runs a frame's init actions after **all** of the frame's placements, and before its DoActions.

**Ours:** `swf.cpp` buffers every DoInitAction into the frame prologue (the `/*__SWFRECOMP_PROLOGUE_n__*/` marker at the top of `frame_N`, "mirrors Ruffle's preload"). So it runs before any placement.

**The fix is recompiler emission, not the frame loop**, so it is out of my scope and delivered as a proposal.

**`w2-exec-order-land-initaction-proposal.patch`** (`SWFRecomp/src/swf.cpp`, `SWFRecomp/include/swf.hpp`, 49 lines):
- A new buffer `current_frame_late_inits` receives the root-frame `tagDoInitActionGuarded` calls.
- It is emitted right before each root-frame close `tagFlushPendingEnterFrame`, in three places: SHOW_FRAME after the buffered removes, END_TAG, and the truncated-frame close. That is after the frame's placements and before the DoAction drain.
- **v3 refinement (needed):** when an ImportAssets follows inits in the same frame, those earlier inits are flushed into the top prologue first. They keep stream order with the import.
  - v1 (no refinement) regressed `avm1/do_init_action_child` PASS → MISMATCH. Flash runs the child's own init before the imported movie's inits.
  - v2 (moving `actionImportAssets` late too) would re-time ImportAssets on 249 rows (every gnash Dejagnu import), too broad to price here.

**Measured, graphics, `--recompile`, all 124 SWFs with a root DoInitAction** (avm1 75, from_gnash 24, from_shumway 4, regression 21). Proposal v3 vs `origin/master`+this patch:
- **0 status moves.**
- 4 rows change bytes:

| row | status | Flash diff lines before → after |
|---|---|---|
| `misc-swfc.all/movieclip_destruction_test1` | ruffle_matched | 32 → **16**. Frame-12 block fixed except `mc6/mc7.__proto__` identity (2 lines, a separate mechanism). The rest is the goto-skipped init (`w2-timers-land` item 1) |
| `misc-swfc.all/registerclass_test3` | ruffle_matched | 24 → **8** (`typeof(player.movie) == movieclip` + `__proto__` now PASS ×2) |
| `misc-swfc.all/action_execution_order_test10` | ruffle_matched | 16 → **12** (`typeof(mc4)`, `mc4.__proto__` PASS) |
| `misc-ming.all/register_class/registerClassTest2` | ruffle_matched | 12 → 12 (reorders a `clip3.frame0 actions` / `clipevs.onLoad` pair; equal distance) |

**Priced flips: 0.** All four are ruffle_matched, and stay there (`registerclass_test3`'s Ruffle-side diff grows 16 → 32, but its status is unchanged). With `w2-timers-land` item 1 also landed, `movieclip_destruction_test1` would be at about 2 lines from Flash: still no flip, because of the `__proto__` identity.

**Interaction risk for the owner:** it runs inits after same-frame placements' CONSTRUCT/CLIP_INIT drains. On these 124 rows that is Flash-correct or neutral. A registerClass-in-init + same-frame placement shape is the case to watch (`registerClassTest2` reorder).

## 6. New unclaimed leads

- **No-graphics inline frame-1 of a newly placed child** (`PlaceAndRemove` mode split, §3.4): queue it like graphics does, so `aq_sprite_ctx_removed` can drop it. XS–S. Price it on the 111-row nested set plus the AOT family; it is no-graphics-only code (`#ifdef NO_GRAPHICS` arm of `advance_sprite_frames` / `process_sprite_needs_init`).
- **`mc6/mc7.__proto__` identity in `movieclip_destruction_test1`** (2 lines after item-3 + timers item 1): `check_equals(mcN.__proto__, …)` prints `[object Object]` on both sides but fails. That is an object-identity mismatch on a registered-class prototype. A fixture would price it.
- **Nested vs newer root-level sibling order** (§2.3): the remaining coarse half of w1 §3 P2. It is now a smaller step than before: a single sort of the root-level + nested advance set by `place_seq`, instead of two passes. It still needs a global serial across DLs (P0) first.
- The w1 lead *`swf.c` OFFSCREEN runs `ng_promote_attached_playheads` before `ng_apply_pending_sprite_self_gotos`, while `swf_core.c` runs it after* is still unverified. I did not touch it.

## LOCAL ORACLE REQUESTS

none. Both fixtures already carry Flash goldens. Item 3 is graded against existing Flash goldens (gnash `output.txt`).

## README rows for `regression/README.md` (coordinator: add with the patch)

```
| `avm1_exec_order_dynamic_eligible` | **a nested timeline sprite runs its frame BEFORE `_root.onEnterFrame` and the root frame script** (s27 `w2-exec-order-land`: nested pass before Phase 1 in `swf.c`/`swf_core.c`), and a clip created by a nested-sprite script / a stopped root's deferred `onEnterFrame` / an attach-init script first fires `onEnterFrame` the tick after creation in graphics too (s27 `w1-exec-order` eligibility slot). Golden = **Flash Player 32** (`num_frames` cut; = Ruffle) |
| `avm1_goto_backward_enterframe_once` | **`onEnterFrame` fires once per tick when a frame script does a backward `gotoAndPlay`** (was 3×: the goto catch-up re-ran the dispatcher; s27 `w1-exec-order` `ef_fired_tick` guard). Golden = **Flash Player 32** (`num_frames` cut; = Ruffle) |
```
