# s29 browser-dj-freeze: Doodle Jump hangs right after PLAY

One-task local slice, browser ladder. It follows `browser-gotoandstop-current` (code `c91637b7a`). The bug was first recorded in `session28-fanout-reports/browser-attached-goto-report.md` §3.4.
Base: master after `d628a86fd`.

## 1. Verdict

- **The DJ freeze is an infinite same-frame self-goto loop, and `c91637b7a` already fixed it for DJ.** On the seeded browser build at `a9fb68b42` (the s28 "after" build), **4 of 6 seeds hang** within about 1 s of PLAY. At HEAD the same 6 seeds, plus 4 more, **all reach gameplay (0/10 hang)**.
- **The same loop was still open for timeline-placed clips in every build.** This slice fixes it in `ng_gotoFrameCurrentSprite` (tag_stubs.c) and adds the fixture `regression/avm1_selfgoto_current_frame_opcode`, which has a Flash Player 32 golden. At HEAD that fixture hangs (timeout) in both native modes. With the fix it passes in both.
- It is **not** a stack overflow (memory `wasm-stack-overflow-64kb`): `STACK_SIZE=8MB` is still in `build_test.sh`, and the stack samples are shallow.

## 2. The loop (wasm stack samples, CDP `Debugger.pause`, `--profiling-funcs` build)

All four freezing seeds at `a9fb68b42` give the same shape:

```
runSWF > actionDrainAllInPriorityOrder > aq_dispatch_sprite_script > script_0
  > actionGotoFrame > ng_gotoFrameByMC > exec_sprite_frame > sprite_{2,17}_frame_0
  > actionQueueSpriteScript / tagPlaceObject2 / ng_on_place_object2 ...
```

- `sprite_2` is the exported `coin` clip and `sprite_17` is `Inverse`. Both are **1-frame item clips** that DJ attaches when it spawns items, so whether they appear depends on the seed.
- Each one's only frame script is `gotoAndPlay(1)`, i.e. the opcodes `GotoFrame(0)` + `Play`. `script_3` (Inverse) is byte-identical to `script_0` (coin), and wasm-opt folded the two, so the samples show `script_0` for both.
- **Before `c91637b7a`:** `ng_gotoFrameByMC`'s same-frame branch re-ran frame 0. That queued the frame's script again (`actionQueueSpriteScript`), and the drain that was already running picked it up, ran the goto again, and so on forever.
- `c91637b7a` made a goto to the current frame a stop/play-only no-op, which ends the loop for attached clips.
- Why the s28 numbers looked flaky: the levels were unseeded, so the result depended on whether an item spawned in the first second.

## 3. The remaining hole and the fix

- **The hole:** a timeline-placed clip running the same opcode pair goes through `actionGotoFrame` → `ng_isInsideSprite()` → `ng_gotoFrameCurrentSprite`, not through `ng_gotoFrameByMC`. That function sets the manual nav, records the self-goto, and re-queues the target frame's script (`actionQueuePendingSpriteScript`) even when the target is the frame already shown. So the same infinite loop occurs, in both native modes and in the browser (tag_stubs.c is shared).
- **The fix:** a first arm in `ng_gotoFrameCurrentSprite` (all builds). If not in catch-up, and `sprite_needs_init != 1`, and the target equals either the shown frame or the pending self-goto's target, it does `sprite_is_playing = 0` and returns. The trailing `Play` opcode then resumes, as in Flash (`no_op_goto`).
  - The shown frame is `(sprite_current_frame + fc - 1) % fc`. `sprite_current_frame` holds the NEXT frame (memory `sprite-current-frame-is-next-not-displayed`).
  - The pending-target half covers a script that a different-frame goto queued, which then gotos its own frame.
- `sprite_needs_init` values:
  - Only `1` means "frame 0 never ran".
  - A timeline clip's frame-0 script runs from the queue while the clip is in eager-init state `3`, and its frame-0 tags have already been placed. The first version of the guard, `!sprite_needs_init`, missed exactly this case.
- **Fixture `regression/avm1_selfgoto_current_frame_opcode`:** the clips are `c1` (attached, 1 frame), `d1` (attached, 2 frames), `c2` (timeline, 1 frame) and `d2` (timeline, 2 frames). Each one's frame 1 does `trace` + `gotoAndPlay(1)`.
  - Flash runs each frame-1 script once. The 2-frame clips play on to frame 2.
  - D's frame 2 deliberately traces nothing. On a natural advance, Flash runs the newer attached `d1`'s script before the timeline `d2`'s, and every build of ours runs `d2` first. This is the advance-order question from `browser-gotoandstop-current` §5.2, kept out of this fixture.

## 4. Grading

- **Fixture, native:** HEAD = timeout in both modes; after = pass in both modes.
- **Native no-graphics (graded with the fix in place):**
  - regression goto rows: 22 run, 21 pass. The one fail is `avm1_nested_child_swapdepths_remove`, a fixture designed to fail (open defect, predecessor §5.1).
  - avm1 goto rows: 22/22 pass.
  - **Stash-diff** (fix vs HEAD `tag_stubs.c`, same lock hold, `--save-actual`): 22 gnash rows, **all byte-identical**. That is misc-ming (5 goto rows + loop_test…loop_test10) and misc-swfc (`gotoFrameFromInterval{,2}`, `gotoFrameLabelAsFunction`, `movieclip_destruction_test1-4`). It includes the 3 `ruffle_matched` rows `gotoFrameFromInterval{,2}` and `loop/loop_test10`.
- **Native graphics (`--mode=graphics`):**
  - regression goto rows: 21/22. The one fail is again `avm1_nested_child_swapdepths_remove`, with the same 2 designed lines.
  - avm1 goto rows: 22/22 pass.
  - Stash-diff: the same 22 gnash rows, **all byte-identical**.
- **Browser (WSLg Chrome, functional):**
  - The seeded DJ build with the fix linked with rc=0 and 0 wasm-ld warnings (`-Wl,--fatal-warnings`). 8 seeds (`…000/002/003/004/010-013`) all reached gameplay (root frame 1, page answering), with **0 hangs**. This includes the 4 seeds that hang at `a9fb68b42`.
  - The rAF rate was 24-102 per 10 s under machine load. That is not a perf number.
  - Fixture via `tools/browser-test/child_probe` (build rc=0, 0 wasm-ld warnings): **byte-identical to the Flash golden**. Only the WebGPU console lines differ.

Expected CI ledger: +1 new passing row (`regression/avm1_selfgoto_current_frame_opcode`), 0 flips elsewhere. Any flip is a defect of this slice. The suspect would be a timeline sprite whose frame script gotos the frame it shows (or its pending target) and expected that frame to re-run.

## 5. Old DJ render bugs (memory `dj-platform-rendering`): noted, not fixed

Checked with HEAD's seeded build at mdt `981152406000`, using frame captures from the in-wasm `window.dbgCaptureBoard()` readback (Playwright canvas screenshots hang in WSL2):
- **Blue platform invisible: does NOT reproduce.** Blue (charId 32→35) platforms draw during play.
- **Brown platform:** it draws (with the crack art). The **break animation was not exercised**: the random-steer probe never landed on a brown platform before game over. So this one is unverified, not confirmed fixed.
- Game-over screen: clean, with no platforms drawn over it (follow-up #3 in that memory did not show).

## 6. Method notes (reusable)

- **Seeding the browser without a rebuild per seed.** This is a local-only, uncommitted hack (the patched file is kept in the session scratchpad). Under `-DDJ_SEED_FROM_JS`, `math.c` seeds the RNG from the page URL `?mdt=<ms>`, falling back to `Date.now()`, and logs `[DJSEED] mdt=…`. So one build covers every seed, and an unseeded run still prints its seed. Build with `EMCC_CFLAGS="-DDJ_SEED_FROM_JS --profiling-funcs"`. Two traps:
  - A `\d` inside `EM_ASM` is a C string escape. It silently became `d`, and the regex never matched.
  - A top-level comma inside an `EM_ASM` body splits the macro arguments.
- The graphics DJ wasm build takes ~1.5 min with `EMCC_CORES=4`.
- **Old-tree build without a recompiler binary.** For `a9fb68b42`, make a worktree, copy the main tree's `RecompiledScripts`/`RecompiledTags`, and set `SWF_REUSE_RECOMPILED=1`. The recompiler did not change in between.
- **Probe:** `dj_freeze.py`. It installs a page-side rAF counter, calls `Module._dbgRootFrame()`, and treats a `page.evaluate` timeout of 3 s as a hang. It then pauses 3× through a CDP `Debugger.pause` and prints the wasm frames. The scratch copy lives in the session scratchpad; the logic is the same as `ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/run_pausestack.js`.
