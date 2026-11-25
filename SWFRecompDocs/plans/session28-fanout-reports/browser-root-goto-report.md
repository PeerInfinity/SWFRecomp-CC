# s28 browser-root-goto: the browser's root gotos are the CI arms, and the entered-frame gate term is gone

**Slot:** local one-task session (brief: `browser-root-goto-prompt.md`). **Predecessor:**
`../session27-fanout-reports/browser-parked-frame-report.md` §5.

**Landed (one commit, browser only — CI preprocess equivalent in both CI define sets, §4):**
- Every root goto entry point in action.c now takes the CI arm in the browser too: the GotoFrame / GoToLabel /
  GotoFrame2 / NextFrame / PrevFrame opcodes and the `gotoAndStop` / `gotoAndPlay` / `nextFrame` / `prevFrame` method
  forms on a root receiver. The target frame runs inline (`ng_executeGotoCatchUp`) or right after the calling script
  (`ng_executeGotoTagsOnly` + `ng_runPendingRootGoto`), as in Flash and the CI modes.
- swf.c: the root frame func gate is `is_playing || manual_next_frame` in every build; the browser-only
  "playhead entered an un-run frame" term is **deleted**. Two browser `ng_runPendingRootGoto` slots: after the
  top-of-tick input dispatch, and after the post-frame-func SCRIPT drain (processTimers already ran it after each
  timer batch, timer.c). The inlined-goto wrap-back undo and the tick-boundary `g_defer_sprite_init` clear run in the
  browser too.
- **Ladder item 2 (`ng_apply_pending_sprite_self_gotos`, briefed S): tried, measured, NOT landed** (§5a). It fixed
  the root-level self-loop on the HEAD this session started from. On the HEAD it commits against, it makes a nested
  sprite (`_root.c.n`) vanish from enumeration.
- New fixture `regression/avm1_clipevent_root_goto_stopped` (golden = Flash 32 projector, direct mode, pinned and
  unpinned identical).

## 1. Browser rows (`tools/browser-test/child_probe/`, WSLg Chrome)

"Matches" = the browser trace equals the native trace line for line over native's whole span. Native runs stop at
`num_frames`; the browser keeps ticking, so a looping or `onEnterFrame` fixture prints more lines after that span.

| Row | Browser before (HEAD) | Browser after | Native no-graphics / graphics |
|---|---|---|---|
| `avm1_timer_root_goto_stopped_gs` | `after cf=3` ×9, then `f3` (frame 3's DoAction ~8 timer batches late) | **matches** (3 lines) | pass / pass |
| `avm1_timer_root_goto_stopped_nf` | `after cf=1` ×340, `f2` never (the browser `nextFrame` **method was a no-op**) | **matches** (3 lines) | pass / pass |
| `avm1_goto_backward_enterframe_once` | an extra `onEnterFrame` before each inline `Frame 2` (target ran next tick) | **matches** (22 lines) | pass / pass |
| `avm1_root_identity_and_playhead` | matches (then loops: a 3-frame root, no stop) | matches, same loop | pass / pass |
| `avm1_clipevent_root_goto_stopped` (new) | an extra `after cf=3`: the handler ran on after the goto removed its clip, frame 3 ran later | **matches Flash** (3 lines) | pass / pass |
| `tools/divergence/gates/nested_sprite_inframe_goto` (injected tracer, Ruffle expected) | root-level `m`: `…5,1,1,2…` (period 6) | unchanged: this slice does not land the self-goto port (§5a) | pass / pass |
| `avm1_browser_parked_frame` | matches | matches | pass / pass |
| `avm1_browser_eager_init`, `avm1_attached_clip_goto_play` | match | match | — |

The `_gs` row's interval is 10 ms at 10 fps, so each processTimers call fires ~10 callbacks. Before, the browser
`gotoAndStop` arm only moved `current_frame` and left frame 3 to the next tick's frame func, so the callback kept
firing until then. Now the callback's `ng_executeGotoTagsOnly` + timer.c's per-batch `ng_runPendingRootGoto` run
frame 3 (which clears the interval) right after the first callback.

**The new fixture.** `onClipEvent(enterFrame)` on clip `c` does `_root.gotoAndStop(3)` on a stopped root (Doodle
Jump's game-over: `if (_root.gameOver) { ...; _root.gotoAndStop(3); }` in the hero's handler). Frame 3 removes `c`.
Flash 32: `f1 cf=1` / `ef 1 cf=1` / `f3 cf=3 c=undefined`. There is no `after cf=` line because Flash aborts the rest of
a handler whose clip the goto removed. Native already did this in both modes. HEAD's browser printed `after cf=3`.

## 2. Two browser-only traps the port hit (both fixed in this slice)

1. **`g_suppress_root_doaction`'s marker.** The browser suppresses a root DoAction when the frame func re-enters the
   frame whose DoAction ran last (a 1-frame playing root loops onto itself). An inline goto runs the target's DoAction
   outside that gate, so after frame 3's `gotoAndPlay(2)` the marker still said 3, and the next tick's real entry
   into frame 3 was suppressed (`goto_backward_enterframe_once` lost every second `Frame 3`). The marker is file-scope
   now, and `ng_executeGotoCatchUp` / `ng_runPendingRootGoto` record their target (`NG_NOTE_ROOT_DOACTION_RAN`,
   `((void)0)` under OFFSCREEN).
2. **Input runs at the top of the browser tick.** OFFSCREEN pumps input after the frame func, and its
   `ng_runPendingRootGoto` follows. In the browser, a button release's `_root.gotoAndStop(n)` (TagsOnly) left
   `manual_next_frame=1`, so the gate re-ran the ORIGINAL frame before the post-frame slot. Doodle Jump showed its
   menu for one tick under the sub-screen's first entries. Hence the second slot right after the input dispatch.

Also needed:
- The browser `tagShowFrame` now returns on `g_tag_skip_mode`, like the CI arm, so the scripts-only target replay does
  not run the per-tick tail (render, buttons, pumps) a second time.
- tag.c's `g_tag_skip_mode` early returns (PlaceObject2 family, SetColorMatrix*, SetInstanceName) are ungated.
- `actionRewindCleanup` (action.c) and `ng_run_deferred_sprite_init_*` / `ng_fire_deferred_constructors` (tag.c) are
  ungated. Before this slice `ng_executeGotoCatchUp` was dead in the browser, so wasm-ld never asked for them. The first
  link failed on exactly these, and `--fatal-warnings` stayed clean after.

## 3. Games (WSLg Chrome = SwiftShader: function only; `getDisplayListJSON` + `dbgRootFrame` per poll)

| Game | After this slice | Same as before? |
|---|---|---|
| Pacman | preloader → menu (root `1:0`, PLAY GAME chid 30); click → game, **41 entries** | yes (s27 numbers). This is the path the deleted entered-frame term existed for. |
| Doodle Jump menu buttons (frames 4, 5) | sub-screen with **3 entries**, menu cleared | same end state. The intermediate one-tick menu+sub-screen mix (trap 2) is fixed. |
| Doodle Jump PLAY | gameplay, hero bouncing / jetpack, score climbing | yes. One HEAD run reached game over in ~1 s; two other HEAD runs and all of mine stayed in play for 10 s. The level is random (unseeded browser `Math.random`), so that is layout, not behaviour. |
| Doodle Jump sub-screen "back" | no reaction to my probe's click | same at HEAD (probe targeting, not the runtime) |
| Tetris | **not measured**: `build_test.sh flasharchive/Tetris wasm` fails in its generated `tagMain.c` (`const s16[42]` passed as `const s32 *`). Stale generated C vs the current runtime header, the same with or without this slice. | — |

The N routes were not re-run. N's frame loop is the parked tail (stopped root, `onEnterFrame`), which this slice does
not touch, and the N ladder session owns the N deploys.

## 4. CI reach

`cpp -P -undef` per CI define set (`-DNO_GRAPHICS`; `-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG`), comments and
whitespace stripped, current HEAD vs this tree. In action.c, swf.c, tag.c and tag_stubs.c the only differences are:
- `if (g_script_only_mode || g_tag_skip_mode) return;` split into two returns (tagSetColorMatrixLive / Folded);
- a line break before `else if (actionChildMovieGoto(...))`;
- `NG_NOTE_ROOT_DOACTION_RAN(target);`, which is `((void)0)` there;
- the gate condition's line breaks.

No semantic change, so no CI run is needed for this commit. It rides the coordinator's next grading run and Pages
deploy.

## 5. What is left (updates the s27 §5 table)

| Arm | Where | Completion mechanism |
|---|---|---|
| `advance_attached_clip_frames` in tagShowFrame | tag.c browser arm + the non-root half of the method `gotoAndStop` (action.c, still `#else`) | Unchanged from s27: route an attachMovie'd clip's goto through `ng_gotoFrameByMC` / the CI non-root arm (`actionChildMovieGoto` → `ng_gotoFrameByMC` → `actionGotoFrame`) and delete the deferred pass. Re-check Doodle Jump's `attachBlocks` reentrancy (block.gotoAndStop in a while loop, and the "already on frame N → only stop" guard). Oracle: `avm1_attached_clip_goto_play{,_nonroot}`, `avm1_attached_clip_selfgoto_child_parent`, then DJ. M |
| `ng_apply_pending_sprite_self_gotos` | swf.c browser post-frame-func block | **Now M, not S (§5a).** Port = the 3 edits in §5a, plus finding why the apply pass drops a nested sprite on the current HEAD. Oracle: the `nested_sprite_inframe_goto` gate via child_probe (recipe in §6). |
| dead `pending_remove` consume/finalize code | tag.c, tag_stubs.c | Delete (s27 §2.2). Not taken: this slice was already M. |
| `graphics_stubs.c` Group 1 (`ng_queue_placement_clip_events`, `ng_queue_slot_unload_events`) | browser-eager-init §3.4 | Still unmeasured. |
| ~~Browser timer/stopped-root goto timing~~ | — | **DONE (this slice).** |
| ~~entered-frame gate term~~ | — | **DONE (this slice).** |

### 5a. The self-goto port: measured, not landed

The edits:
1. swf.c: call `ng_apply_pending_sprite_self_gotos` after the browser's post-frame-func
   `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)`;
2. tag_stubs.c `ng_gotoFrameCurrentSprite`: ungate the `ng_record_sprite_self_goto` call;
3. tag.c: ungate the apply pass's `catch_up_mode` guard.

Gate `nested_sprite_inframe_goto` (native passes both modes; browser via child_probe):

| Browser build | root-level `m` `_cf` | nested `_root.c.n` |
|---|---|---|
| session-start HEAD `43bdb35a8` + root-goto port | `2,3,4,5,1,1,2` (stutter) | present, correct |
| `43bdb35a8` + root-goto port + the 3 edits | `2,3,4,5,2,3,4,5` | present: **all 61 lines match** |
| current HEAD `aa595bbc6` alone | stutter | present |
| `aa595bbc6` + root-goto port + the 3 edits | `2,3,4,5,2,3,4,5` | **gone from every row** (deterministic, 2 runs) |
| same, with only the swf.c call removed | stutter | present |

So the apply pass interacts with something that landed between `43bdb35a8` and `aa595bbc6`. Candidates are the
s28 w2 runtime commits; the tag.c ones are the likeliest (`613c0f100` occupied-depth PlaceObject,
`0f2caed84` timeline onUnload closure scope, `e7afd5ad2` loaded-shell goto). Not bisected. The `catch_up_mode`
replay inside the apply pass (reset the sprite's list + replay frames 0..T) is where to look first.

The ported CI root arm keeps CI's Dejagnu-era rule: a GotoFrame **opcode** to the root from inside an
`onEnterFrame` dispatch is dropped (`g_inside_enterframe_dispatch`). The browser now drops it too, where before it
moved the playhead a tick late. The method forms (`_root.gotoAndStop`) are unaffected, and this is native/CI
behaviour. If a browser game regresses on an onEnterFrame-driven root goto, this rule is the first suspect, and it is
also a Flash-parity question for CI.

## 6. Method notes

- **The working tree is shared.** Mid-slice the coordinator committed other sessions' tag.c / action.c / swf.c hunks
  under this session's edits, so my probe builds include them. Stage by hunk and redo the CI-preprocess check against
  the *current* HEAD before committing.
- `build_test.sh … wasm` needs `source emsdk/emsdk_env.sh` first. Without it every game "builds" rc=1, and
  `deploy_example.sh` then silently copies the PREVIOUS wasm.
- **Re-verify on the tree you commit.** The self-goto port passed every check on the session-start HEAD and broke a
  nested sprite after the coordinator's mid-session commits. Only a final rebuild on the commit tree showed it.
- A child_probe build for a scratch suite takes a tests dir relative to the repo root
  (`../../../../tmp/.../suite`). The `nested_sprite_inframe_goto` gate needs its tracer-INJECTED SWF
  (`tools/divergence/runs/nested_sprite_inframe_goto/injected.swf`); the raw gate SWF prints nothing.
- A Flash oracle run of a new hand-assembled fixture is the fastest SWF sanity check. My first version printed only
  `f1` in Flash AND natively: I had forgotten `prefix=defs`, so the sprite was undefined.
