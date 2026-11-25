# s28 w1-test12-enterframe — gnash `action_execution_order_test12` line 17 (enterFrame on clips removed this tick)

**New files (all under `session28-fanout-reports/`):**
- `w1-test12-enterframe-report.md` (this file)
- `w1-test12-enterframe-prototype.patch` (`git diff origin/master -- SWFModernRuntime`, sources reverted)
- `w1-test12-enterframe-fixtures/avm1_enterframe_removed_same_tick/` (SWF 8) and `…_swf7/` (the same file at SWF 7):
  `create_test_swf.py`, `test.swf`, `test.toml`, `output.ours-before.txt`, `output.ours-proto-mode1.txt`.
  There is no `output.txt` yet: the golden must come from Flash (LOCAL ORACLE REQUESTS).
- `w1-test12-enterframe-fixtures/avm1_dis.py`: a small AVM1 tag and action disassembler (stdlib only), used for every
  SWF reading in this report.

Box: `SETUP_STATUS` all OK (Dawn, apt, Pillow). Tests downloaded from upstream Ruffle master; a fresh clone reads
`c2f7d24b7`. Before leg = `origin/master` `d5f9726d`.

## Verdicts

| Item | Verdict | Flips |
|---|---|---|
| Unconditional rule ("a clip alive at tick start gets its onEnterFrame even if this tick's advance removes it") | **NO-GO as is: net −1.** | +1 `from_gnash/misc-swfc.all/action_execution_order_test12`; **−1 `avm1/clip_events`, −1 `avm1/movieclip_in_removed_button`** (both pass → output_mismatch) |
| The same rule gated to SWF ≤ 7 (prototype default) | **HOLD on Flash. It gates clean but the gate is a guess.** | **+1 `action_execution_order_test12`**, 0 losses across the 125-row sweep, graphics + NG headline parity |

The prototype `w1-test12-enterframe-prototype.patch` has a runtime switch `SWF_EF_SNAPSHOT`:
`0` is the exact before leg, `1` is unconditional, and `2` (the default) applies the rule to SWF ≤ 7 only.

**Why HOLD rather than GO.** The SWF ≤ 7 gate is the cheapest discriminator that fits all three goldens. But test12
is SWF 7, `clip_events` is SWF 15 and `movieclip_in_removed_button` is SWF 8, and those two are Ruffle goldens whose
Flash provenance is unknown. A second discriminator fits the data equally well: a **multi-frame playing clip** removed
by a root RemoveObject2 fires, and a **1-frame clip** does not. test12's `mc1`/`mc2` are 4- and 3-frame sprites; the
`clip_events` clip and the button's child are 1-frame sprites. A third reading is that those two Ruffle goldens are
simply not what FP32 does. Landing a version gate on that evidence would be overfitting.

**Completion mechanism:** the three FLASH captures below.
- (a) If FP32 reproduces the `clip_events` and `movieclip_in_removed_button` goldens, the fixture's `s`/`t` (1-frame)
  vs `b`/`n` (2-frame) rows and its v7/v8 pair pick the discriminator. Wave 2 then lands the prototype with that gate
  (≈ +20 LOC on top of the patch, for example a `total_frames > 1` test at snapshot time instead of the version test).
- (b) If FP32 contradicts those goldens (fires the method handler on the removal tick), land mode 1 unconditionally
  and add `flash_fixes` entries for both rows.

Either way test12 flips, and the action_order NO-GO rows do not move except extend_test (below).

## 1. What clips 4 and 5 are (premise check)

Source: `test.swf` disassembled (no `.sc` is shipped; savannah cgit returned 502). Root timeline, 15 frames, SWF 7:

| root frame | tags |
|---|---|
| 0 | `enterFrameOrder = loadOrder = unloadOrder = "0+"` |
| 1 | DefineSprite 5/6/7 (1 frame each: one shape), 8 (`mc1`: 4 frames, places `mc11`=spr5 @d1 on its f1 and `mc12`=spr6 @d2 on its f3), 9 (`mc2`: 3 frames, places `mc21`=spr7 on its f2) |
| 2 | PlaceObject2 `mc1` d1, `mc2` d2; DoAction defines `mc1.onEnterFrame` (+"2+"), `mc2.onEnterFrame` (+"1+"), onLoad/onUnload |
| 3 | DoAction defines `mc1.mc11.onEnterFrame` (+"**3+**") |
| 4 | DoAction defines `mc2.mc21.onEnterFrame` (+"**4+**") |
| 5 | DoAction defines `mc1.mc12.onEnterFrame` (+"**5+**") |
| 7 | RemoveObject2 d1, d2 (mc1, mc2); DoAction checks lines 16–18 |

So "clips 4 and 5" are **`mc2.mc21` and `mc1.mc12`**: timeline-placed **1-frame children** of looping sprites. Each
gets its handler on the root frame right after it is placed. **The very next tick, its parent's loop-back removes it**
(mc2 wraps from f2 to f0, mc1 from f3 to f0). Each has exactly one enterFrame opportunity: the tick that removes it.

The brief's premise is half right. The cause is **not** enterFrame on a newly created clip, and **not** the ordering of
the enterFrame list. It is "an onEnterFrame queued for a clip that this tick's advance then removes". The FP10 string
also shows two less obvious instances of the same rule, which the brief did not name:

```
FP10 = 0+ | 1+2+ | 3+1+2+ | 4+3+1+2+ | 5+3+1+2+ | 1+2+          (ticks 4,5,6,7,8; our g_tick_count)
FP9  = 0+ | 1+2+ | 3+1+2+ | 3+1+2+   | 1+2+     |  —
ours = FP9 exactly (EFDBG trace: tick 4 mc2,mc1; 5,6 mc11,mc2,mc1; 7 mc2,mc1; 8 mc1/mc2 skipped as removed)
```

- tick 6: `4+` (mc21, removed by mc2's wrap) **and** `3+` (mc11, still alive).
- tick 7: `5+` (mc12) **and `3+` (mc11)**: mc11 is also removed this tick by mc1's wrap, so FP10 fires it 3× vs our 2×.
- tick 8: `1+2+`: **mc1/mc2 removed by the ROOT's RemoveObject2 still fire** in FP10.

The order inside a tick (newest clip first, `4+3+1+2+`) is exactly Ruffle's exec-list order (`avm1/runtime.rs` run_frame
newest-first), and ours already matches it. So the whole FP9→FP10 delta is one rule. Ruffle drops it here: in
`player.rs:2175` `run_actions`, a queued non-unload action is skipped when `clip.avm1_removed() ||
avm1_pending_removal()`. That is FP9's behaviour. **FP10+ does not drop the queued enterFrame of a clip removed later in
the same tick.** Ruffle has no player-version gating for this (`grep player_version core/src`: only
version strings and AVM2 error stacks). Its fp10 subtest is `known_failure` for exactly this reason.

The same FP9→FP10 split shows up in other gnash `[subtests]` rows, and all of them point the same way: FP10 runs more
queued work for clips removed in the same tick.
- `action_execution_order_test`: FP10 adds "as in frame2 of mc_blu".
- `action_execution_order_extend_test`: FP10 adds "mc_blu enterFrame executed".
- `movieclip_destruction_test3`: FP10 adds "actions here should not be executed".
- `PlaceAndRemove`: FP10 adds 5 "Done".

Our runtime already follows the FP10 side for frame **actions** (`action_execution_order_test` passes, as
ruffle_matched against fp10; `movieclip_destruction_test3` passes fp10). It follows the FP9 side only for
**enterFrame**, through the explicit skip in `actionDispatchEnterFrameHandlers` (action.c, "Skip Marked MCs …
avm1/clip_events expects no onEnterFrame after RemoveObject2").

### The counter-evidence (a refutation of the naive rule)

- `avm1/clip_events` (SWF 15): a 1-frame clip removed by the root's RemoveObject2. The golden has **no**
  `clip onEnterFrame` (and no `clip enterFrame` clip event) on the removal tick.
- `avm1/movieclip_in_removed_button` (SWF 8): a 1-frame sprite inside a button. The root's RemoveObject2 removes the
  button, and the golden has **no** child onEnterFrame on that tick.
- `extend_test` fp10 (SWF 6): on the removal tick FP10 fires `mc_blu` (the removed clip's **child**) but **not** `mc_red`
  (the directly removed clip, stopped, with onClipEvent actions), because `y2` stays `as_in_root`. Unconditional mode
  fires both.

Note also that extend_test's RemoveObject2 comes **after** the frame-4 DoAction in tag order, so in Flash mc_blu was
not yet removed when its EF ran. Our recompiled frame runs the RemoveObject2 before the pre-DoAction flush, so to us it
looks "removed this tick". The `mc_red` non-fire is not explained by any model tried here. extend_test is a standing
NO-GO with other unexplained FP behaviour (the `mc_red.onLoad` rule, B1/B2 in s20).

## 2. Owner and prototype

**Owner:** `SWFModernRuntime/src/actionmodern/action.c` `actionDispatchEnterFrameHandlers`, the removed-ancestor skip.
That skip alone is not enough, because:
- a clip removed by its parent's loop-back is already gone from `child_mc_cache`, which `actionRewindCleanup` NULLs and
  trims, when `tagFlushPendingEnterFrame` runs;
- its `dynamic_props` has been detached (`actionDeferDpropsRelease` sets it to NULL; the object itself lives until the
  next tick boundary).

**Mechanism.** Our tick order is Phase-3-early/Phase-1 sprite advance (`swf.c` before `frame_funcs[current_frame]`,
`swf_core.c` the same), then root tags, then flush, then DoAction. So the "alive at tick start" set must be
snapshotted **before the advance**.

**Prototype** (`w1-test12-enterframe-prototype.patch`, +117/−1). Functions touched:
- `action.c`:
  - new `actionSnapshotEnterFrameCandidates`. Before the advance it records every live, non-button clip with a
    function `onEnterFrame` that would be eligible this tick, as `(mc, func, cache index)`. Eligible means
    `sprite_initialized >= 2` for display-backed clips, `mc_enterframe_eligible` for dynamic clips and level roots.
  - new statics `ef_invoke_handler` (the same invoke flags as the existing arm) and `ef_fire_removed_snapshot_slot`.
  - `actionDispatchEnterFrameHandlers`: the loop now starts at `max(child_mc_count, top snapshot slot)`, and at each slot
    fires the snapshot entries whose clip has since been removed or evicted, in the same newest-first position.
    `ef_fired_tick` still guards against firing twice per tick.
- `swf.c` (main loop, every build) and `swf_core.c` (NG main loop): one call to `actionSnapshotEnterFrameCandidates()`
  right before `exec_order_nested_early()`.

The handler runs with `this` = the removed clip. It captures the function at snapshot time, because a removed clip has
no members (Ruffle semantics), so a run-time lookup finds nothing.

## 3. Gate (graphics; A/B is the SAME binary with `SWF_EF_SNAPSHOT=0` vs mode)

The sweep set has 125 rows, chosen by argument:
- gnash: all of `misc-ming.all/action_order/*` (16) and all of `misc-swfc.all/*` (22): 38 rows.
- avm1: every test whose SWF contains `onEnterFrame` (39), plus the order/removal rows `clip_events`,
  `clip_event_propagation_order`, `execution_order1-4`, `goto_execution_order{,2}`, `remove_movie_clip`, `unload*`,
  `removed_clip_halts_script`, `target_clip_removed`, `remove_different_level`: 53 rows. No avm1 test has
  `enterframe` in its name.
- regression: every row using `onEnterFrame`, plus `*enterframe*|*exec_order*|*remove*|*unload*|*loop*|*timeline*`:
  34 rows.

| suite | mode 0 (before) | mode 1 (unconditional) | mode 2 (SWF ≤ 7) |
|---|---|---|---|
| from_gnash (38) | 22 pass / 7 rm / 9 fail | **+test12** | **+test12** |
| avm1 (53) | 51 pass / 2 rm / 0 fail | **−clip_events, −movieclip_in_removed_button** | no move |
| regression (34) | 34 pass | no move | no move |

Line movement on the action_order NO-GOs (`--save-actual`, modes 0/1/2):
- `ActionOrderTest3/4/5`, `PlaceAndRemove`, `action_execution_order_test11`: **byte-identical** in all modes.
- `action_execution_order_extend_test` (graded fp10): modes 1 and 2 are identical (SWF 6 ≤ 7). Matching lines go
  **22 → 23 / 32**. "mc_blu enterFrame executed" and `y5 FAILED … mc_blu onEnterFrame called` move **toward** the
  golden. "mc_red enterFrame executed" plus `y2 FAILED … mc_red onEnterFrame called` move **away** (FP10 does not fire
  mc_red, see §1). Status stays output_mismatch.

No-graphics (the patch touches `swf_core.c`), modes 0 and 2:
- `test12`: MISMATCH → PASS.
- `extend_test` MISMATCH, `action_execution_order_test` ruffle_matched, `movieclip_destruction_test3` PASS,
  `clip_events` PASS, `movieclip_in_removed_button` PASS: all unchanged.
- Line 19 (`asOrder`, the s27 init flush) is untouched: test12 passes byte-for-byte with fp10 in both modes.

`misc-ming.all/action_order/action_execution_order_test4` fails **locally in both legs**, identically, and is not on the
s28 baseline failing list. It is a pre-existing local/CI difference, not caused by this patch: an EF-vs-sprite-frame
interleave (`x1 = …7+9+11+8+10+…`). Worth a CI re-read, but it is not this lead.

## 4. Regression fixture (needs a Flash golden)

`w1-test12-enterframe-fixtures/avm1_enterframe_removed_same_tick{,_swf7}`: 6 root frames, `num_ticks = 8`, the same file
at SWF 8 and SWF 7. It splits every candidate discriminator:

| clip | frames | removed by | onUnload | notes |
|---|---|---|---|---|
| `a.k` | 1 | parent `a`'s loop-back (test12's mc21/mc12 shape) | yes | traces `a._currentframe`: **2** means EF ran *before* the advance, **1** means a not-dropped queued action after it |
| `b` | 2 (playing) | root RemoveObject2 (test12's mc1/mc2 shape) | yes | traces own `_currentframe` |
| `n` | 2 (playing) | root RemoveObject2 | no | |
| `s` | 1 | root RemoveObject2 (clip_events shape) | yes | |
| `t` | 1 | root RemoveObject2 | no | |
| `c` | 1 | root RemoveObject2 | — | `onClipEvent(enterFrame)` arm (the prototype does not cover clip events) |
| `a` | 2 | root RemoveObject2 on frame 6 | — | |

Our before output: `output.ours-before.txt`. Mode 1 adds `k EF rf=4 a.cf=1`, `t/n/s/b EF rf=5`, `a EF rf=6`.
Side finding: before and after, we print `frame 5 typeof(b)=movieclip` after b's RemoveObject2 (b has onUnload). Flash
will say whether that holds.

## 5. RvF entry draft (the coordinator appends it on landing)

```
## gnash action_execution_order_test12 (fp10): onEnterFrame of a clip removed later in the same tick

**Test:** `from_gnash/misc-swfc.all/action_execution_order_test12` (graded `output.fp10.txt`; Ruffle runs it as
`known_failure`). **Flash 32** (direct, pinned; `session27-fanout-reports/flash-oracle-captures/action_execution_order_test12/flash32.lnx.direct.txt`)
prints `output.fp10.txt` byte for byte:

    FAILED: _root.enterFrameOrder: expected: "0+1+2+3+1+2+3+1+2+1+2+" , obtained: "0+1+2+3+1+2+4+3+1+2+5+3+1+2+1+2+"

Flash 10+ runs the onEnterFrame queued for a clip at the start of a frame even when that frame's timeline advance then
removes the clip: mc2.mc21 / mc1.mc12, removed by their parent's loop-back, fire once each; mc1.mc11 fires on its
removal tick; mc1/mc2 fire on the tick the root's RemoveObject2 removes them. Ruffle (`player.rs` `run_actions` skips a
queued action whose clip is `avm1_removed()`/`avm1_pending_removal()`) prints Flash 9's `output.fp9.txt` line 17.
**Decision:** match Flash 32. <gate as landed: SWF<=7 | multi-frame | unconditional + flash_fixes for clip_events /
movieclip_in_removed_button>, per the s28 oracle captures of `avm1_enterframe_removed_same_tick{,_swf7}`.
```

## New unclaimed leads

- **The `extend_test` mc_red non-fire.** FP10 fires the removed clip's child (`mc_blu`) but not `mc_red` itself on the
  removal tick. Note that our recompiled frame runs a RemoveObject2 that follows a DoAction in tag order *before* the
  pre-DoAction EF flush (`tagFlushPendingEnterFrame` comes after all of the frame's display tags). Flash processes tags
  in order. Cheap to check: the recompiler's emission order for `DoAction; RemoveObject2` frames.
- **`action_execution_order_test4`** fails locally in both legs but not in the CI baseline. Worth a CI single-test
  re-read; the cause may be a cloud-box difference.
- **`typeof(b)` after RemoveObject2 of a clip with onUnload** stays `movieclip` in the frame's own DoAction (fixture
  row `frame 5`). The Flash capture will say whether that is right.

## LOCAL ORACLE REQUESTS

1. **FLASH: `SWFRecompDocs/plans/session28-fanout-reports/w1-test12-enterframe-fixtures/avm1_enterframe_removed_same_tick/test.swf`**,
   trace, 8 frames, **direct, pinned**. This becomes the fixture golden. Compare the `k/b/n/s/t/c/a EF` rows on the
   removal ticks (rf=4, rf=5, rf=6) against `output.ours-before.txt` and `output.ours-proto-mode1.txt`, and read the
   `a.cf=` value on the k row (2 = EF before advance, 1 = queued after).
2. **FLASH: the same at `…/avm1_enterframe_removed_same_tick_swf7/test.swf`** (SWF 7), trace, 8 frames, direct,
   pinned. Any difference from #1 proves a SWF-version gate.
3. **FLASH: corpus `ruffle-tests/tests/swfs/avm1/clip_events/test.swf`** (4 frames) and
   **`avm1/movieclip_in_removed_button/test.swf`** (4 frames), trace, direct, pinned. Do they match their Ruffle
   goldens, i.e. no enterFrame on the RemoveObject2 tick? If not, both are flash_fixes candidates, and the unconditional
   rule (mode 1) lands.
