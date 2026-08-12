# Wave-1 scoping report — AVM1 tick-pipeline arc (`avm1-tick`)

Session 14 dual-axis fan-out, wave 1. Read-only investigation; no source edits,
no commits.

**Target:** `from_gnash/misc-ming.all/action_order/action_execution_order_test11`
**Brief's claim:** "our frame pipeline runs phases globally where Flash/Ruffle
interleave per-clip (each clip's enterFrame adjacent to its own advance), and
test11 asserts the interleaved order."

**Verdict: DEFER — dedicated session, not wave-2-sized.** The brief's premise is
*partly refuted*: only one of the three residual defects is per-clip EF+advance
adjacency. The other two are separable, but the whole test is all-or-nothing
(no `known_failure` / `output.ruffle.txt`, so partial credit = 0), and the one
architectural defect requires unwinding five interlocking pipeline mechanisms.
Predicted yield of a fully successful arc: **+1 test** (test11), with
`action_execution_order_extend_test` a *conditional* +1 that also needs an
unrelated missing feature.

---

## 1. Target status at HEAD (`0a99be1a9`)

Test disambiguation: two `*test11*` directories exist —
`from_gnash/misc-ming.all/action_order/action_execution_order_test11` (this one)
and `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test11`
(passing, unrelated). `verify_output.py --test=action_execution_order_test11`
**fails to resolve** (its suite search only scans top-level `SUITE_DIRS`, not
gnash sub-suites). Correct invocation:

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all/action_order \
  --test=action_execution_order_test11 --diff --verbose
```

Result at HEAD: **26/32 lines, `output_mismatch`** — identical to CI baseline
`results_graphics.json` (26/32). No `known_failure`, no `output.ruffle.txt`;
`test.toml` is just `num_frames = 30`. Not in `ignored_tests.txt` and not in any
of the four AVM1 disposition docs (`ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`).

Residual diff (expected `-` / actual `+`):

```
     7  mc2 onEnterFrame called
-    8  mc21 onLoad called
+    8  mc1 onEnterFrame called
-    9  mc1 onEnterFrame called
+    9  mc21 onLoad called
    10  mc21 onEnterFrame called
...
-   28  PASSED: _root.doActionOrder  ==  '0+1+2+3+4+5+'
+   28  FAILED: expected '0+1+2+3+4+5+' obtained 0+2+1+3+4+5+
-   29  PASSED: _root.asOrder  ==  '0+1+2+3+4+5+6+3+8+4+10+6+3+4+14+15+25+10+26+6+27+3+28+4+29+20+21+22+23+24+'
+   29  FAILED: ... obtained 0+1+2+3+4+5+6+3+4+8+10+6+3+4+14+26+25+27+15+10+6+3+4+28+29+20+21+22+23+24+
-   30  #passed: 5        +   30  #passed: 3
-   31  #failed: 0        +   31  #failed: 2
```

**Assertions: 3 of 5 pass** (`loadOrder`, `enterFrameOrder`, `unloadOrder`).
Failing: `doActionOrder`, `asOrder`. Brief's "3 of 5" is confirmed.

### Test structure (decoded from `RecompiledTags/tagMain.c` + `RecompiledScripts`)

| Clip | char | placed by | depth | children |
|---|---|---|---|---|
| `mc1` | 6 (`sprite_6`) | root frame 1, **first** | root d2 | `mc11` (f1), `mc12` (f3) |
| `mc2` | 8 (`sprite_8`) | root frame 1, **second** | root d3 | `mc21` (f2) |
| `mc11` | 4 (`sprite_4`) | mc1 frame 1 | mc1 d1 | — |
| `mc12` | 5 (`sprite_5`) | mc1 frame 3 | mc1 d2 | — |
| `mc21` | 7 (`sprite_7`) | mc2 frame 2 | mc2 d1 | — |

`doActionOrder` / `asOrder` id emitters (`script_defs.c` string constants):

| script | owner | `doActionOrder` | `asOrder` |
|---|---|---|---|
| `script_0` | root frame 0 | `0+` | `0+` |
| `script_4` | **mc12** (`sprite_5`) frame **1** | `1+` | `25+` |
| `script_5` | **mc21** (`sprite_7`) frame **2** | `2+` | `26+` |
| `script_3` | **mc11** (`sprite_4`) frame **3** | `3+` | `27+` |
| `script_12` | mc1 (`sprite_6`) frame 4 | `4+` | `28+` |
| `script_19` | mc2 (`sprite_8`) frame 4 | `5+` | `29+` |

The three nested-child scripts (`1+`,`2+`,`3+`) all fire on the **same tick** —
mc11 was placed 2 ticks before mc21, which was placed 1 tick before mc12, and
their frame offsets (3, 2, 1) cancel exactly. So `doActionOrder`'s `1,2,3` pins a
**single-tick global reverse-instantiation order across different parents**:
mc12 (newest) → mc21 → mc11 (oldest).

---

## 2. Mechanism — Ruffle side

Ruffle's AVM1 tick is a **single interleaved walk**, not phases.

`~/CC/ruffle/core/src/avm1/runtime.rs:517-545` — `Avm1::run_frame` walks the
global `clip_exec_list` (head insertion at
`runtime.rs:562-568 add_to_exec_list` ⇒ LIFO = reverse instantiation, one flat
list across the whole tree, parents and children of different parents
interleaved) and for each live clip calls `clip.run_frame_avm1(context)`.

`~/CC/ruffle/core/src/display_object/movie_clip.rs:450-467` —
```rust
pub fn run_frame_avm1(self, context) {
    let is_load_frame = !self.0.contains_flag(MovieClipFlags::INITIALIZED);
    if is_load_frame { self.event_dispatch(context, ClipEvent::Load); self.0.set_initialized(true); }
    else             { self.event_dispatch(context, ClipEvent::EnterFrame); }
    if self.playing() { self.run_frame_internal(context, true, true, false); }  // ← this clip's tags, inline
}
```
`ClipEvent::Load` is dispatched at **exactly one site** in the whole codebase
(`movie_clip.rs:455`, confirmed by `grep -rn "ClipEvent::Load" core/src/`).

`~/CC/ruffle/core/src/display_object/movie_clip.rs:1554-1563` — `instantiate_child`
runs a freshly-placed AVM1 child's **first frame inline, at placement time**:
```rust
child.post_instantiation(context, None, Instantiator::Movie, false); // → add_to_exec_list
child.enter_frame(context);
if let Some(child) = child.as_movie_clip() && !movie.is_action_script_3() {
    child.run_frame_avm1(context);   // fires Load + runs frame 0 tags, inline, in tag order
}
```
`post_instantiation` → `movie_clip.rs:2750-2753` → `context.avm1.add_to_exec_list`.

This explains all three passing assertions and both failing ones:
- **`loadOrder` = placement order (FIFO)** — Load fires inline at placement, in
  tag order. (We match.)
- **`enterFrameOrder` = LIFO** — every subsequent frame goes through the exec
  list. (We match, thanks to the 2026-05-08 flat-LIFO refactor.)
- **`doActionOrder` = flat-global LIFO** across parents on the shared tick.
- **line 8/9** — the newly-placed clip's Load is emitted *inside its parent's
  own advance*, which sits between that parent's EnterFrame and the *next*
  clip's EnterFrame.

Tick-by-tick replay of Ruffle against expected `output.txt` reproduces all 32
lines exactly, including the leading `enterFrameOrder` group boundaries
(`[0] [2,1] [3,2,1] [4,3,2,1] [5,4,3,2,1]` = one group per tick).

---

## 3. Mechanism — our side (file:line)

Our AVM1 tick is a **five-phase global pipeline**, identical in both modes:

| Phase | graphics (`swf.c`) | no-graphics (`swf_core.c`) | what |
|---|---|---|---|
| 1 | `swf.c:918` | `swf_core.c:1054` | `advance_sprite_frames` with `g_advance_defer_nested=1` — advance **all** root-level sprites, queue their frame scripts |
| 1b | `swf.c:~928` | `swf_core.c:~1063` | `ng_advance_attached_clip_playheads` |
| 1c | `swf.c:937` | `swf_core.c:1073` | `presync_nested_sprite_currentframe` — *papers over* the phase split by pre-writing `mc->currentframe` for clips that won't advance until phase 5 |
| 2 | recompiler-emitted `tagFlushPendingEnterFrame` inside `frame_funcs[n]`; fallback `swf.c:1052` | fallback `swf_core.c:1134` | `tag.c:4676` — construct-drain, then `dispatch_enterframe_clip_actions` (`tag.c:4500`) + `actionDispatchEnterFrameHandlers` (`action.c:35516`) for the **entire tree at once** |
| 3 | recompiler-emitted `actionDrainAllInPriorityOrder` | same | drains queued frame scripts **and** the deferred clip-`LOAD` callbacks (`aq_dispatch_clip_load`, `tag.c:8061` / queued at `tag.c:8107-8127`) |
| 4 | `swf.c:1083` | `swf_core.c:1137` | `advance_nested_sprite_frames` (`tag.c:1726`) — advance nested children |

Three concrete divergences:

**D1 — global phase split instead of per-clip interleave (the brief's claim).**
Phase 1 advances *all* root sprites before phase 2 fires *any* enterFrame; and a
newly-placed child's `LOAD` is not dispatched inline but queued as a
`PendingClipLoad` (`tag.c:389`, queued `tag.c:8107`, dispatched `tag.c:8061`)
and drained in phase 3, i.e. after every enterFrame. Net effect on lines 8/9:
we emit `mc11 EF, mc2 EF, mc1 EF, mc21 Load`; Flash/Ruffle emit
`mc11 EF, mc2 EF, mc21 Load, mc1 EF`. **This is the brief's defect, and it
accounts for exactly 2 of the 6 wrong lines.**

**D2 — nested advance is per-parent-subtree LIFO, not flat-global LIFO
(NOT in the brief).** `advance_nested_sprite_frames` (`tag.c:1726-1790`) sorts
*root-level* depths by `place_seq` DESC (`tag.c:1732-1758`), then for each
root sprite swaps into its subtree and calls `advance_sprite_frames`, which
sorts *again* within that subtree (`tag.c:1128-1158`). The result is
`{parent LIFO} × {child LIFO}`, not a single flat ordering. mc2 has a larger
`place_seq` than mc1, so mc2's subtree (→ `mc21`, `2+`) runs before mc1's
subtree (→ `mc12`, `1+`) — even though `mc12` is the globally most-recently
instantiated clip. Ruffle's single flat `clip_exec_list` gives `mc12, mc21,
mc11` = `1+2+3+`. **This is the entire `doActionOrder` failure.**
Note the exact same defect was fixed for *clip-event enterFrame* on 2026-05-08
by rewriting `dispatch_enterframe_clip_actions` (`tag.c:4492-4530`) to gather a
flat cross-tree array and sort by `place_seq` DESC — the advance passes were
never given the same treatment. **The fix has direct in-file precedent.**

**D3 — `asOrder` needs both.** Expected tail
`14+ 15+ 25+ 10+ 26+ 6+ 27+ 3+ 28+ 4+ 29+` interleaves each nested clip's own
frame script (`25`=mc12, `26`=mc21, `27`=mc11) with the ids `10/6/3`; ours emits
`14+ 26+ 25+ 27+ 15+ 10+ 6+ 3+ 4+ 28+ 29+` — the three nested scripts clumped
(and in D2's wrong order), then everything else clumped. Fixing D2 alone
reorders `26+25+27+` → `25+26+27+` but leaves them clumped; the interleave needs
D1.

**Consequence: the test is all-or-nothing.** With no `output.ruffle.txt` and no
`known_failure` in `test.toml`, subset promotion is unavailable — 31/32 scores
exactly as much as 26/32 (zero). D2 alone flips no test.

---

## 4. Siblings

Scan of every non-pass test in `avm1`, `from_gnash`, `from_shumway`, `timeline`,
`mixed_avm`, `text`, `audio`, `import_assets`, `visual` (`results_graphics.json`
at baseline), filtered for enterFrame/onLoad-ordering content, then diffed
locally where plausible:

| Test | Status | Verdict |
|---|---|---|
| `misc-ming/action_order/action_execution_order_extend_test` | 7/32 | **Real sibling, conditional.** Its diff shows the D1 signature verbatim: expected `mc_blu EF → as in frame2 of mc_blu → mc_red EF → as in frame2 of mc_red`; we emit `mc_blu EF, mc_red EF, as in frame2 of mc_red, … as in frame2 of mc_blu`. But it is **also** blocked on the separately-documented missing feature "`onLoad`/`onUnload` **method**-handler dispatch for plain timeline-placed sprites" (`from_gnash/_investigation/CURRENT_STATUS.md:182`, `blocked/ACTION_EXECUTION_ORDER_EXTEND_PLAN.md`). Needs both to flip. Note its expected output *contains* a `FAILED:` line (`_root.y5`) that we currently "pass" — fixing D1 would correctly flip us to Flash's failing behaviour. |
| `misc-ming/action_order/ActionOrderTest3` / `4` / `5` | 4/62, 10/64, 6/51 | **Not siblings.** `ActionOrderTest4`'s diff is entirely the registerClass `ctor / static load / dynamic load` axis and we over-produce lines past `<end of expected>`. `SPRITE_EXEC_LIST_LIFO_PLAN.md` already documents that 3/4/5 place sprites in depth-ascending order so exec-list ordering is not their blocker. |
| `misc-ming/action_order/action_execution_order_test6` | 0/24 | Separate, documented (`incomplete/ACTION_EXECUTION_ORDER_TEST6_PLAN.md`). |
| `misc-ming/action_order/PlaceAndRemove` | 15/96 | Placement/removal axis, far from this. |
| `from_shumway/as3-loader/events/loader-events` | 5/36 | AVM2 loader events; matched the text filter only. |

**Sibling yield: +1 test max this arc (test11); +1 more (extend_test) only in
combination with an unrelated feature.** This is a `+1`, not a `+N`, arc.

### Stale-doc correction

`from_gnash/_investigation/incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` header says
"test5 (26/35) and test11 (27/32) remain output_mismatch". At baseline
`action_execution_order_test5` is **PASS 35/35** and test11 is **26/32**. That
doc's `<!-- TESTS: -->` list and residual note should be refreshed by whoever
next touches it.

---

## 5. Blast radius

This is the most regression-prone area of the codebase, and D1 in particular is
not a local change. Any of these mechanisms exists *because* the pipeline is
phase-global, and would need to be re-derived or removed:

1. `g_advance_defer_nested` + `advance_nested_sprite_frames` (`tag.c:1726`) — the
   phase-1/phase-4 split itself.
2. `presync_nested_sprite_currentframe` (`swf.c:937`, `swf_core.c:1073`,
   `:1197`) — exists *only* to make phase-2 enterFrame observe phase-4
   `_currentframe` values. Memory: `nested-cf-presync`.
3. `PendingClipLoad` deferral (`tag.c:389`, `:8061`, `:8107`) plus
   `actionDrainOnloadAndScript` (`tag.c:4165`) and the pointer-rebase / free
   scrubbing at `tag.c:9893`, `:10069`.
4. `tagFlushPendingEnterFrame`'s **recompiler-emitted call site** — it is placed
   between the frame's Place/Remove tags and the script drain (see
   `RecompiledTags/tagMain.c`, every `frame_N`). Moving enterFrame per-clip
   means changing emission in `SWFRecomp/src/`, i.e. invalidating every
   `Recompiled*` cache corpus-wide.
5. `advance_sprite_frames`' just-placed guard (`placed_at_tick == g_tick_count`
   skip, `tag.c:~1783`) which encodes Ruffle's "clips added mid-iteration are
   not visited this tick" — see
   `SWFRecompDocs/plans/defer-newly-placed-sprite-advance-plan.md`.
6. goto catch-up suppression (`g_goto_catchup_active`, `tag.c:405-410`) and
   Phase-1 eager init (`g_eager_init_depth`, `tag.c:~9049`
   `CALL_FRAME(..., sprite_frame_funcs[0])`), both of which assume the phase
   split. Memory gotchas: `goto-catchup-placed-clip-no-advance`,
   `manual-nav-must-sync-mc-currentframe`, `sprite-self-goto-sametick`,
   `self-goto-catchup-loop`.
7. `ng_advance_attached_clip_playheads` / `ng_promote_attached_playheads` —
   attachMovie'd clips are a *separate* pump that would need to join the same
   ordering. Memory: `attached-clip-playhead`.
8. The `dispatch_enterframe_clip_actions` gathered-array rebase frame
   (`ClipEFRebaseFrame`, `tag.c:4531`) — a flat gather that must survive
   display-list reallocation *during* dispatch. Any flat gather added to the
   advance passes needs the same protection (`sprite-dl-realloc-rebase`).

### Canary set (mandatory for any implementation attempt)

**Regression suite** (`--tests-dir=ruffle-tests/tests/swfs/regression`, 73
tests — always include, per standing policy). Highest-signal members:
`enterframe_type1_args`, `root_enterframe_cross_swf_version`, `onload_type1_args`,
`onunload_type1_args`, `onunload_type1_local_frame`, `mc_event_type1_args`,
`mc_event_cross_swf_version`, `onconstruct_type1_args`,
`onconstruct_cross_swf_version`, `ei_closure_scope_order`,
`avm2_goto_catchup_scale`, `avm2_timeline_solid/stroke_gradient/gradients/text`.

**gnash misc-ming (all currently green in the two touched families):**
`action_order/action_execution_order_test1/2/3/5/7/8-v5/8-v6/9`,
`action_order/action_execution_order_test` (ruffle_matched 7/19),
`action_order/action_execution_order_test4` (ruffle_matched 19/26),
`loop/loop_test`, `loop_test2/3/4/5/8/9`, `loop_test6/7/10` (ruffle_matched),
`loop/simple_loop_test`.
**Highest-risk (added specifically to pin re-place order):**
`reverse_execute_PlaceObject2_test1/2`.
Plus `instanceNameTest`, `attachMovieTest`, `static_vs_dynamic1/2`,
`displaylist_depths/displaylist_depths_test11`, `place_and_remove_object_test`,
`get_frame_number_test`, `shape_test`, `event_handler_scope_test`,
`new_child_in_unload_test`, `ResolveEventsTest`.

**gnash misc-swfc:** `stackscope`, `edittext_test1`, `submoviegetvar`,
`movieclip_destruction_test2` (50/52 — must not drop; this is the test that
killed the previous Phase-4 dispatcher-sort attempt).

**avm1 lifecycle/event-order battery (30, all green):** `goto_rewind1/2/3`,
`execution_order1/2/3`, `goto_execution_order/2`, `goto_both_ways1/2`,
`rewind_depth`, `unload`, `unload_clip_event`, `unload_nested_child`,
`unloadmovie`, `mcl_unloadclip`, `clip_events`, `bad_placeobject_clipaction`,
`movieclip_in_removed_button`, `on_construct`, `register_and_init_order`,
`set_interval`, `swf5_to_6_cross_call`, `swf6_to_5_cross_call`, `attach_movie`,
`init_object_order`, `movieclip_state_values`,
`movieclip_library_state_values`, `button_children`,
`depth_replacement_audio_unloading`, `create_empty_movie_clip`.

**shumway:** `duplicateMovieClip/{dontremove,duplicateMovieClip,samedepth,name-coercion}`,
`from_shumway/timeline/*`.

**Games (D1 only — divergence harness, not the trace suite):** N, Tetris,
Doodle Jump, Minesweeper. Nested-sprite advance order and clip-`LOAD` timing are
load-bearing there; see `SWFRecompDocs/guides/wasm-game-debugging-session-guide.md`.

**CI:** `mode=graphics`, `categories=all`. If the recompiler emission of
`tagFlushPendingEnterFrame` moves (D1), also run `no-graphics` — the change
touches shared runtime *and* invalidates every `Recompiled*` cache.

---

## 6. If it were a go — implementation plan

Two independent tracks. Do **not** land D2 alone: it flips zero tests and
reorders every nested sprite frame script in the corpus.

**Track A (narrow, precedented, ~2-3h + battery):** flat-global LIFO advance.
Replace `advance_nested_sprite_frames`' `{root LIFO} × {subtree LIFO}` recursion
(`tag.c:1726-1830`) with the same shape as `dispatch_enterframe_clip_actions`
(`tag.c:4492-4530`): a `gather_*` walk that collects `(DisplayObject*,
owning display list, parent MC, place_seq)` for every nested sprite across the
whole tree into a flat capped array, one insertion sort by `place_seq` DESC, one
pass. Reuse the `ClipEFRebaseFrame` pattern verbatim for realloc safety, and keep
the existing `placed_at_tick == g_tick_count` skip and `catch_up_mode` early-out
per entry. Fall back to the current recursion on cap overflow.
Flips: `doActionOrder` (assertion 4 of 5). Test still fails.

**Track B (architectural, dedicated session):** per-clip EF+advance adjacency.
Requires collapsing phases 1/2/4 into a single flat `place_seq`-DESC walk over
the whole tree in which each clip does `{Load-or-EnterFrame; advance its own
playhead and run its own tags}`, with a freshly-placed child's frame-0
`LOAD` + frame-0 script fired **inline** at the `tagPlaceObject2*` site rather
than queued as `PendingClipLoad`. Then delete `presync_nested_sprite_currentframe`
and `g_advance_defer_nested`, and move the recompiler's `tagFlushPendingEnterFrame`
emission (which invalidates all `Recompiled*` caches). Every item in §5 needs
re-derivation. Gate behind a runtime flag for A/B against the game harnesses.

Expected flips if both land: **test11 → PASS (+1)**. `extend_test` becomes a
2-of-2 blocker (this + `ACTION_EXECUTION_ORDER_EXTEND_PLAN`'s onLoad-method
dispatch), so a follow-on **+1** is plausible but not this arc.

---

## 7. Recommendation

**Defer with full diagnosis** (this document). Rationale:

- Ceiling is +1 test, +1 conditional. The `polish-sweep-arc.md` §14.3 framing
  ("an arc, not a rider") is right that it isn't a rider — but the arc's payout
  does not scale, because there is no cluster of tests behind it.
- Because test11 has no `known_failure` / `output.ruffle.txt`, partial progress
  scores zero. Track A alone (the cheap, precedented half) buys nothing while
  spending full corpus-wide timeline-order regression risk.
- Track B touches the recompiler's frame-func emission and five interlocking
  runtime mechanisms in the single most regression-prone area of the codebase.
  A same-session wave-2 attempt would almost certainly end as a revert.
- Better session shape if picked up later: pair Track B with
  `ACTION_EXECUTION_ORDER_EXTEND_PLAN` (onLoad/onUnload method dispatch for
  timeline-placed sprites) so the session's ceiling is +2 rather than +1, and
  budget a full day with the games divergence harness in the loop.

Refutation logged: **the brief's single-mechanism framing is wrong.**
`doActionOrder` — one of the two failing assertions — is not per-clip adjacency
at all, it is flat-global vs. per-subtree LIFO in the nested advance pass, and
that half already has a working in-file precedent from 2026-05-08.
