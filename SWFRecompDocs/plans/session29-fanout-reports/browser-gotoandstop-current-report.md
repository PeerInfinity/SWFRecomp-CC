# s29 browser-gotoandstop-current: a goto to the frame a clip already shows

One-task local slice, browser ladder. It follows `browser-attached-goto`; that slice's report §4 and §5 were this slice's brief.
Base `d6c7e74cd` (docs only since `bfa47037b`, the CI baseline). Code + fixtures land in one commit (SHA in the coordinator message and `git log`).

## 1. Verdict

**Flash Player 32: a goto to the frame the clip already shows changes nothing except stop/play.** This holds for attached clips, timeline clips and the root, for both gotoAndStop and gotoAndPlay. The frame's PlaceObject (move or new) and RemoveObject do not re-run, and neither does its DoAction. Script edits to the frame's children survive. `gotoAndPlay(current)` plays on to the next frame. This matches Ruffle's AVM1 `no_op_goto` (`core/src/display_object/movie_clip.rs:950-963`).

So the browser guard was right in kind. CI's same-frame branch was wrong in **both** native modes. **One rule in every build now:**

| Site | Before | After |
|---|---|---|
| `ng_gotoFrameByMC` (tag_stubs.c), same-frame branch | re-ran the frame's `sprite_frame_funcs[frame]` (all builds reach it) | no-op beyond the existing stop/play + `currentframe` writes. The old exec stays only when `obj->sprite_needs_init` (frame 0 never ran) |
| action.c method `gotoAndStop/gotoAndPlay`, non-root arm | browser-only `#if !NG && !OR` "gotoAndStop(current) = stop" guard | **deleted**. Every build goes through `ng_gotoFrameByMC` |
| action.c method `gotoAndStop/gotoAndPlay`, root arm | inline catch-up / TagsOnly + `ng_runPendingRootGoto` (re-ran the root frame's DoAction) | new first arm: `root_movieclip.currentframe == frame0+1 && !ng_isInsideSpriteInit()` → `is_playing = is_play`, nothing else |

Functions touched (for the `w1-timers-goto` cloud slot): the **method-call `gotoAndStop`/`gotoAndPlay` branch of action.c's MovieClip method dispatcher** (the same function the `prevFrame`/`nextFrame` method arms live in), and `ng_gotoFrameByMC` in tag_stubs.c. `actionNextFrame`, `actionGotoFrame` and the opcode paths are untouched.

## 2. What the CI branch actually did (both native modes, before)

Shown by `regression/avm1_goto_current_frame_clip` (each line was diffed against the Flash golden):
- `n` = attach then `n.gotoAndStop(1)` in the same script (N's tileMC). **n's frame-1 script ran twice**, and the first run came before `h`'s.
- `gotoAndStop(2)` on frame 2 re-ran the frame's tags. That printed `Warning: Failed to place object at depth 4/5` (the new placements hit their own existing entries) and re-ran `S f2`'s DoAction.
- `gotoAndPlay(2)` on frame 2 re-ran f2's DoAction, whose `stop()` cancelled the play, so the clip **stayed on 2 forever** (Flash: cf=3 next tick).
- Root (`regression/avm1_goto_current_frame_root`): `_root.gotoAndStop(2)` / `gotoAndPlay(2)` from a clip's onEnterFrame, while the root was parked on 2, re-ran root f2's DoAction. The root frame's own script calling `_root.gotoAndStop(2)` was already right (the root DoAction suppression).

## 3. Grading

- Fixtures, native: both new fixtures, plus 6 neighbouring goto fixtures (`avm1_attached_clip_selfgoto_trace`, `avm1_attached_clip_goto_play{,_nonroot}`, `avm1_browser_parked_frame`, `avm1_clipevent_root_goto_stopped`, `avm1_timer_root_goto_stopped_gs`). **8/8 in default (NO_GRAPHICS) and 8/8 in `--mode=graphics`.**
- Fixtures, browser (`tools/browser-test/child_probe`, WSLg Chrome): both fixtures **byte-identical to the Flash golden** (only WebGPU console lines differ). Builds rc=0, 0 wasm-ld warnings under `-Wl,--fatal-warnings`.
- Corpus rows run locally in `--mode=graphics`. All passed at the CI baseline, and all still pass:
  - avm1 22/22: `button_goto`, `duplicate_movie_clip{,_drawing}`, `function_base_clip{,_readded,_removed}`, `goto_*` ×15, `hittest_morph_input`. Three of these motivated the old branch in `1a7da3a0a`: `hittest_morph_input`, `duplicate_movie_clip`, `function_base_clip`.
  - gnash misc-ming 12/12: `consecutive_goto_frame_test`, `frame_label_test`, `gotoFrame2Test`, `goto_frame_test`, `multi_doactions_and_goto_frame_test`, `loop/loop_test{,2,3,4,5,8,9}`.
  - gnash misc-swfc 4/4: `gotoFrameLabelAsFunction`, `movieclip_destruction_test2/3/4`.
- **Doodle Jump (browser, WSLg, functional):** `rebuild_docs2_demos.sh flasharchive --only Doodle_Jump,N --fast`, rc=0, 0 wasm-ld warnings. `dj_alive.py click` reached gameplay in 3/3 runs (root frame 1, rAF climbing, page answering). None of the 3 froze; s28 saw 4/7. Levels are unseeded, so 3 runs say nothing about the freeze (§5).
- **N (browser):** `N_drive` page (the deployed L4 "lockness" route build) rebuilt seeded (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`), rc=0, 0 warnings. Over the 619 ticks it reached in 90 s under load, its NF telemetry is **byte-identical** to the page's previous browser trace (Nov 23). The ND events are the same: switch t=453, kill t=508, retry, re-run. The browser already had the stop semantics, so this is the expected no-change. **Native N was NOT re-run.** The CI modes did change for tileMC (no more frame-1 re-run), so the N ladder's next native route run is the native check.

## 4. Corpus price (expected ledger for the coordinator's run)

- A static grep finds nothing to price by hand: the corpus has no `goto*(…_currentframe)` in any `.as`/`.sc`/`.m4` source. The only reachers are dynamic.
- Every row I could name that reaches the old branch (§3) stays a pass. **Expected: 0 pass→fail, and +2 new passing rows** (`regression/avm1_goto_current_frame_{clip,root}`). The third new row, `regression/avm1_nested_child_swapdepths_remove`, is **expected to FAIL** (open defect, §5). It is new, so it is not a regression.
- Run **both modes**. tag_stubs.c is no-graphics-only code per CLAUDE.md, and the same-frame branch is shared. `categories=all` is enough: no AVM2 or emission change.
- A flip anywhere else is a defect of this slice. The first suspect would be a clip whose `currentframe`/`sprite_current_frame` claims frame N before N's tags ever ran, without `sprite_needs_init` set (the case the old comment guarded).

## 5. Found on the way (not fixed)

1. **OPEN CI+browser defect: removing a sprite's timeline child by script.** `d.swapDepths(100); d.removeMovieClip()` on a child inside a sprite (attached or timeline parent) leaves `h.d` alive (`typeof` = movieclip; Flash: undefined). `ng_updateDisplayDepth` and the removeMovieClip arm only touch the ROOT `display_list`. The parent sprite's `sprite_display_list` entry never moves or clears, so `h.d` re-resolves to it, and the render presumably keeps the old depth too. Fixture `regression/avm1_nested_child_swapdepths_remove` (Flash golden, fails in every build). Size M: both functions need a parent-sprite DL arm, plus `getInstanceAtDepth`/render checks.
2. **Natural-advance order, attached vs timeline siblings.** On a natural advance Flash ran the NEWER attached `h`'s frame script before the older timeline `t`'s. Every build ran `t` first. This is consistent with Flash's newest-first execution list against our "timeline sprites, then attached pump" order. I kept it out of the fixture (S f3 traces nothing). Next step: a dedicated Flash fixture that interleaves timeline-placed and attached roots, before anyone touches the pump order (memory `browser-attached-timeline-shared-pump`: attach-tick order is TAG order).
3. Opcode-form same-frame gotos (`GotoFrame` in a clip's own frame script, tellTarget) were not fixtured. They do not pass through the method arm. Attached holders' opcode self-gotos do reach `ng_gotoFrameByMC` (s28), so they now get the no-op too.

## 6. Next rung (noted, not started)

**Doodle Jump browser freeze after PLAY** (s28 report §3.4): a renderer busy loop ~1 s after PLAY, at a random level.
1. Seed the build (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, as for N_drive above) for a deterministic repro.
2. Take a wasm stack sample while it spins.
3. Check memory `wasm-stack-overflow-64kb`.

DJ's breakable `block.gotoAndStop(4)` path is now the no-op in every build. If the freeze lives in `attachBlocks`, it is not this goto.

## 7. Method notes

- Fixtures use `regression/_lib/avm1asm.py`. Goldens: `tools/flash-oracle/run_trace.py <dir> -o …` (pinned direct, Linux FP32). A clip onEnterFrame driver logs forever under the projector, so bound it by self-removal (`swapDepths(1000)` + `removeMovieClip`).
- The CPU lock was held by a peer's long ledger job for ~20 min at a time. Queue every build under `flock` in the background and wait on the output file.
- The N_drive page in docs2 is a `START_LEVEL=4` build, not level 0. Compare it with its own previous trace (`tools/divergence/game_drive/compare_out/ndrive_ours_trace.txt`, gitignored), not with `ndrive_ruffle_trace.txt` (level 0).
