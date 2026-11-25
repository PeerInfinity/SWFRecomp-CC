# s28 w2-test12-land — Flash's "queued enterFrame survives same-tick removal" rule, landed

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w2-test12-land-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-test12-land.patch` (`git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt` + the 2 new regression dirs; 11 files; `git apply --check -R` OK on this branch, forward `--check` OK on `origin/master` `b21ac9a0`)
- `ruffle-tests/tests/swfs/regression/avm1_enterframe_removed_same_tick/{create_test_swf.py,test.swf,test.toml,output.txt}`
  (SWF 8; `output.txt` = the coordinator's FP32 capture `w1-local-oracles/w1-test12-enterframe/avm1_enterframe_removed_same_tick.flash32.txt`, byte for byte)
- `ruffle-tests/tests/swfs/regression/avm1_enterframe_removed_same_tick_swf7/{test.swf,test.toml,output.txt}`
  (SWF 7, built by the same generator with arg `7`; `output.txt` = `…_swf7.flash32.txt`)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-test12-land-fixtures/avm1_enterframe_removed_same_tick_noprobe/{create_test_swf.py,test.swf,test.toml,output.predicted.txt}`
  (FLASH request; NOT a golden yet; see LOCAL ORACLE REQUESTS)

Box: `SETUP_STATUS` all OK. Before leg = `origin/master` `b21ac9a0`; tests downloaded from upstream Ruffle master
(`git ls-remote` reads **`d2a801a98`**, newer than the brief's `c2f7d24b7`; `avm1/root_onload_loaded_level` is a new
upstream row, i.e. drift). All runs `--mode=graphics` unless marked NG.

## Verdict

**GO. Expected flip: +1 `from_gnash/misc-swfc.all/action_execution_order_test12` output_mismatch → pass** (both modes).
0 status losses across the 138-row sweep. Canary: 5/5 md5-identical.

**The two new regression rows land at 24/25 lines (output_mismatch), not pass.** The one line left is
`frame 4 typeof(a.k)=movieclip`. That is a separate removal-semantics rule (a loop-back-removed clip with onUnload stays
name-reachable for the tick), not part of the enterFrame rule; see lead L1. Completion mechanism: lead L1, or the
`_noprobe` FLASH capture (request 1), which would land a row that passes now. Coordinator's choice: land the two rows
as failing-by-one-line (they pin 24 Flash lines that this patch fixed; before = 8/25), or hold them until request 1
comes back and land `_noprobe` instead.

## 1. The ONE rule (fits every Flash capture, byte for byte on the EF rows)

> A clip alive and enterFrame-eligible at the start of a tick, which this tick's advance removes (a parent's loop-back
> or a root RemoveObject2), **still runs its queued onEnterFrame iff (a) it carries an `onUnload` function and
> (b) it has no PlaceObject clip actions.** It runs in its exec-list slot (newest first), after the advance.

Fit table (every row is a Flash 32 capture or a Flash-provenance golden):

| clip | onUnload | clip actions | removed by | Flash fires on removal tick? | rule |
|---|---|---|---|---|---|
| test12 `mc1`,`mc2` (4/3 frames) | yes | no | root RemoveObject2 | yes (`1+2+` at tick 8) | fire |
| test12 `mc21`,`mc12`,`mc11` (1 frame) | yes | no | parent loop-back | yes (`4+`, `5+`, 3rd `3+`) | fire |
| extend_test `mc_blu` (SWF 6, child of mc_red) | yes | no | parent's RemoveObject2 | yes (`mc_blu enterFrame executed`, y5 FAILED line) | fire |
| extend_test `mc_red` (SWF 6) | yes | **yes** (`onClipEvent(load)` only, flags `0x00000001`) | root RemoveObject2 | **no** (y2 stays `as_in_root`) | drop |
| `avm1/clip_events` clip (SWF 15) | yes | **yes** | root RemoveObject2 | no | drop |
| `avm1/movieclip_in_removed_button` child (SWF 8) | **no** | no | button removed | no | drop |
| fixture `k` (1 frame) | yes | no | parent `a` loop-back | yes, `a.cf=1` (after the advance) | fire |
| fixture `b` (2 frames), `s` (1 frame) | yes | no | root RemoveObject2 | yes | fire |
| fixture `n`, `t` | **no** | no | root RemoveObject2 | no | drop |
| fixture `c` | no | **yes** | root RemoveObject2 | no | drop |
| fixture `a` (frame 6) | no | no | root RemoveObject2 | no (no `a EF rf=6`) | drop |

Refutations of the w1 candidates:
- **SWF-version gate: refuted twice.** The fixture prints identically at SWF 7 and 8 (coordinator capture), and
  extend_test is SWF 6, yet FP10 drops `mc_red`.
- **"Multi-frame playing clip" gate: refuted.** Fixture `s` and `k` are 1-frame clips and fire; `n` is 2-frame and doesn't.
- **"Root RemoveObject2 vs parent loop-back" gate: refuted.** Both paths fire (`k` vs `b`/`s`) and both drop (`n`/`t`).
- The w1 report's unexplained **`mc_red` non-fire is explained**: mc_red has PlaceObject clip actions. Unconditional
  mode moved extend_test *away* on that line; this rule moves it only toward the golden (§3).
- Mechanism reading: (a) matches Flash's deferred removal (a clip with an unload handler stays alive until its unload
  runs; without one it is destroyed at once). (b) is consistent with Flash bundling a clip-action clip's
  onClipEvent(enterFrame) and its onEnterFrame into one clip-event queue entry, which is dropped for a removed clip.
  The data proves the gate, not the internals.

**Second Flash fact the fixture shows (also landed):** a clip's `onClipEvent(enterFrame)` runs in the same exec-list
walk as the `onEnterFrame` methods (`t EF, n EF, c clipEvent(enterFrame), s EF, b EF, a EF`). We ran every clip event
first. `clip_events` still holds: a clip's own clip event precedes its own method, and its newer child's precedes both.

## 2. Patch (functions touched; self-localized)

`SWFModernRuntime/src/actionmodern/action.c` (all new code sits just above `actionDispatchEnterFrameHandlers`):
- `EfSnapEntry`, `ef_snapshot_enabled` (default ON; `SWF_EF_SNAPSHOT=0` gives the pre-patch removal behaviour, for A/B
  only), `ef_mc_or_ancestor_removed`, **new `ef_removal_keeps_enterframe`** (the rule's (a)+(b)),
  `actionSnapshotEnterFrameCandidates` (records only rule-passing clips, plus their `place_seq`), `ef_invoke_handler`,
  `ef_fire_removed_snapshot_slot`. These come from the w1 prototype; the version gate is gone.
- `actionDispatchEnterFrameHandlers`: walks from `max(child_mc_count, top snapshot slot)`, fires removed snapshot
  entries in their slot, and runs the clip-event interleave hooks. The hooks only run in the outermost pass
  (`g_ef_dispatch_nest`), so a nested re-run from goto catch-up never fires the outer pass's pending entries. Dynamic
  clips and `_levelN` roots, which have no timeline `place_seq`, flush every pending clip event before their method,
  which keeps the old order for them.

`SWFModernRuntime/src/libswf/tag.c`:
- **new `clip_ef_fire_entry`**: the body of the flat clip-EF loop in `dispatch_enterframe_clip_actions_impl`, moved
  into a helper with no behaviour change. The loop now calls it.
- `dispatch_enterframe_clip_actions_impl`: in collect mode (root pass only, CI modes) it hands the sorted entries to a
  heap list registered on the `ClipEFRebaseFrame` chain (so `ng_spriteDLRealloc`/`ng_freeSpriteDL` still
  rebase/NULL them), then returns.
- **new** `tagClipEFCollectRootPass`, `tagClipEFFireNewerOrEqual`, `tagClipEFFireRemaining`, static `clip_ef_pend_end`.
  Clip events fired through the hooks run with `g_inside_enterframe_dispatch = 0`, as before, because that flag
  changes root-goto handling.
- `tagFlushPendingEnterFrame`: calls `tagClipEFCollectRootPass` instead of `dispatch_root_enterframe_clip_actions`.
- **Browser-WASM: the interleave is compiled out** (`#else` stubs; `dispatch_attached_clip_enterframe` keeps its slot).
  The removal rule (action.c + `swf.c` snapshot call) applies in every build. **The browser build was not compiled
  here: there is no emsdk in the cloud box.** The `#else` arms are trivial stubs, but a `deploy-pages` dry run is the
  real check.

`SWFModernRuntime/src/libswf/swf.c` `tagMain` and `swf_core.c` `swfStart`: one `actionSnapshotEnterFrameCandidates()`
call before `exec_order_nested_early()`, as in the prototype. `swf_core.c` past-last-frame branch: uses
`tagClipEFCollectRootPass` (NG parity).

Not touched: `queue_pending_finalize_mc`/`run_pending_finalize` (w2-avm1-leads-land), the ladders' goto functions, render code.

## 3. Per-test before/after (same box; before = clean origin/master sources, after = patch)

| test | graphics before | graphics after | NG before | NG after |
|---|---|---|---|---|
| `from_gnash/misc-swfc.all/action_execution_order_test12` | output_mismatch 19/22 | **pass 22/22** | output_mismatch 19/22 | **pass 22/22** |
| `avm1/clip_events` | pass 19/19 | pass 19/19 | pass | pass |
| `avm1/movieclip_in_removed_button` | pass 4/4 | pass 4/4 | pass | pass |
| `regression/avm1_enterframe_removed_same_tick` (new) | output_mismatch 8/25 | output_mismatch **24/25** | 8/25 | **24/25** |
| `regression/avm1_enterframe_removed_same_tick_swf7` (new) | 8/25 | **24/25** | — | — |
| `misc-ming.all/action_order/action_execution_order_extend_test` (NO-GO) | output_mismatch 8/32 | output_mismatch 8/32, **content moves toward fp10** | same | same |
| `…/action_execution_order_test` | ruffle_matched 7/19 | identical text | ruffle_matched | identical |
| `…/action_execution_order_test4` | output_mismatch 19/26 | identical text | output_mismatch | identical |
| `misc-ming.all/event_handler_scope_test` | pass | pass | pass | pass |

The test12 diff (both modes) is exactly line 17: `PASSED: _root.enterFrameOrder == 0+1+2+3+1+2+3+1+2+1+2+`.

extend_test line movement: after the patch it prints `mc_blu enterFrame executed` before `as in frame4 of root`, and
`FAILED: expected: 'as_in_root' obtained: mc_blu onEnterFrame called [...:182]`. Both are fp10-golden lines. It does
**not** print `mc_red enterFrame executed` (also correct). The index-aligned match count stays 8/32 because the
existing `mc_red onLoad` misalignment sits above it. Status unchanged.

NO-GO rows **byte-identical before/after** (diff text compared): `ActionOrderTest3/4/5`, `PlaceAndRemove`,
`action_execution_order_test11`, `action_execution_order_test4`, `action_execution_order_test6`.

`action_execution_order_test4`: CI baseline says `ruffle_matched`, local says output_mismatch **in both legs** with the
same 19/26 lines and identical text. This is the w1 report's local/CI difference, not this patch.

## 4. Gate

- **138-row sweep, graphics, after-leg vs the s28 CI baseline (`7c3cfdcb7`) statuses.** The sweep is the w1 125-row
  argument, plus every avm1/gnash/shumway/regression row whose SWF carries both PlaceObject clip actions and
  `onEnterFrame` (interleave coverage: `duplicate_movie_clip_test`, `event_handler_scope_test`, `timeline_var_test`,
  `issue_2870`, `netstream_play_flv_screen`), plus `from_shumway/timeline/timeline_as2_1`. Counts: gnash 41, avm1 56,
  regression 40, shumway 1.
  Moves: **test12 → pass**; the 2 new regression rows; `avm1/root_onload_loaded_level` (new upstream row, drift,
  passes); `action_execution_order_test4` (local/CI, above). Every other row has the same status and match count as CI.
- **Regression suite:** the 40 regression rows in the sweep (every `onEnterFrame` user plus
  `*enterframe*|*exec_order*|*remove*|*unload*|*loop*|*timeline*`): 40/40 unchanged pass.
- **Render canary:** only 5 of the 189 canary members carry AVM1 `onEnterFrame` or clip actions, the only inputs this
  patch reads (scanned: avm1, from_gnash, from_shumway, regression, visual, text, fonts; the avm2 members cannot reach
  the AVM1 dispatch). `render_canary.py capture/compare` on those 5 (`avm1/netstream_play_flv_screen`,
  `regression/avm1_parent_child_{render,bitmap_fill,morph,text}`): **IDENTICAL 5/5, no trace/image status change.**
  The full 189-member canary was not run, by this argument.
- Mode parity: the NG legs for the headline rows are in §3 (the patch touches `swf_core.c`).

## 5. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| axis | test | expected |
|---|---|---|
| trace | `from_gnash/misc-swfc.all/action_execution_order_test12` | output_mismatch → **pass** (graphics and no-graphics) |
| trace | `regression/avm1_enterframe_removed_same_tick` | NEW row, output_mismatch 24/25 (line 18, lead L1) |
| trace | `regression/avm1_enterframe_removed_same_tick_swf7` | NEW row, output_mismatch 24/25 (line 18, lead L1) |
| trace | `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` | stays output_mismatch; text moves toward fp10 (2 golden lines gained) |
| trace | everything else | no move |
| pixel | — | **no move** (canary 5/5 md5-identical; no render code touched) |

## 6. RvF entry draft (append at EOF of `RUFFLE_VS_FLASH_DIFFERENCES.md` on landing)

```
## gnash action_execution_order_test12 (fp10): onEnterFrame of a clip removed later in the same tick

**Test:** `from_gnash/misc-swfc.all/action_execution_order_test12` (graded `output.fp10.txt`; Ruffle runs it as
`known_failure`). Flash 32 prints `output.fp10.txt` (trace-provenance: golden = Flash). Ruffle prints `output.fp9.txt`
line 17:

    FAILED: _root.enterFrameOrder: expected: "0+1+2+3+1+2+3+1+2+1+2+" , obtained: "0+1+2+3+1+2+4+3+1+2+5+3+1+2+1+2+"

Flash 10+ keeps the onEnterFrame queued for a clip at the start of a frame when that frame's timeline advance then
removes the clip (a parent's loop-back or a RemoveObject2), PROVIDED the clip has an onUnload function and no
PlaceObject clip actions. mc2.mc21 / mc1.mc12 / mc1.mc11 (removed by their parent's loop-back) and mc1 / mc2 (removed by
the root's RemoveObject2) all carry onUnload and fire. Discriminators, all FP32: regression/avm1_enterframe_removed_same_tick{,_swf7}
(b/s/k fire; n/t without onUnload and c with clip actions do not; SWF 7 == SWF 8), gnash action_execution_order_extend_test
fp10 (mc_blu fires; mc_red, onUnload + onClipEvent(load), does not), avm1/clip_events and avm1/movieclip_in_removed_button
(goldens = FP32: clip actions / no onUnload, no fire). Ruffle (`core/src/player.rs` `run_actions`) skips every queued
non-unload action whose clip is `avm1_removed()` or `avm1_pending_removal()`, which is Flash 9's behaviour.
Flash also runs a clip's onClipEvent(enterFrame) in the same exec-list walk as the onEnterFrame methods (the fixture's
`t EF, n EF, c clipEvent(enterFrame), s EF`).
**Decision:** match Flash 32 (s28 w2-test12-land: action.c `ef_removal_keeps_enterframe` + tag.c clip-event interleave).
```

## New unclaimed leads

- **L1: a loop-back-removed clip with onUnload stays name-reachable for the rest of the tick** (fixture line 18:
  `frame 4 typeof(a.k)=movieclip` after `k unload`; we print `undefined`). Tried and reverted here. Routing a
  non-surviving onUnload child of a natural loop-back through `queue_pending_finalize_mc`, the same way
  `tagRemoveObject2`'s has_unload path does, is not enough: the deferral fired, but `a.k` (GetMember on the parent clip)
  still resolved `undefined` once the clip was marked (`actionMarkMCPendingRemovalDirect`). The RemoveObject2 case
  works only through the GetVariable path (`typeof(b)`). Mechanism to price: the member lookup on a clip skips
  `pending_removal`/`avm1_removed` children. Owner: the GetMember child-clip resolution in `action.c`, plus the
  loop-back block in `tag.c` `advance_sprite_frames` (the `lb_wrapped` arm) and the pending-finalize queue, which
  w2-avm1-leads-land owns this wave. Flips the 2 new regression rows to pass.
- **`action_execution_order_test4` local vs CI** (ruffle_matched in CI, output_mismatch locally in both legs, same
  lines): still worth a CI single-test re-read. Not caused by this patch.
- The extend_test fp10 index misalignment (the `mc_red onLoad` rule, s20 B1/B2) is still the blocker on that row.

## LOCAL ORACLE REQUESTS

1. **FLASH: `SWFRecompDocs/plans/session28-fanout-reports/w2-test12-land-fixtures/avm1_enterframe_removed_same_tick_noprobe/test.swf`**
   (SWF 8, built by its `create_test_swf.py`), trace, 8 frames, **direct, pinned**. It is the landed fixture minus the
   `typeof(a.k)` probe: root frame 4 traces just `frame 4`. Expected: `output.predicted.txt`, which is the SWF 8 capture
   with line 18 replaced by `frame 4`. Our patched runtime prints that exactly, with no other differences. If Flash
   matches, land it as `regression/avm1_enterframe_removed_same_tick_noprobe` with the capture as `output.txt`; it passes.
2. (Optional, sharpens rule (b).) No capture yet covers a clip that has clip actions **and** is removed by a parent's
   loop-back. Every clip-action case so far is a RemoveObject2. Not needed for this landing.
