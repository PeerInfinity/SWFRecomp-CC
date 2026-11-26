# s28 browser-attached-goto: the Tetris break was a stale cache; attached-clip gotos now use the CI arm, and the deferred pass is gone

Session: local, one task, launched by `s28-coordinator`. Succeeds `browser-root-goto` (`dc6c75a64`).
Commits: `60877dc63` (goal 1), `fa5bd94e7` (goal-4 fixture), the goal-2 commit that carries this report.

## 0. Summary

| Goal | Result |
|---|---|
| 1. Tetris wasm `tagMain.c` s16/s32 | **The brief's premise was overturned.** No s28 emitter commit is involved. The generated C in `flasharchive/Tetris/RecompiledScripts` dated from Jun 29 (pre-s13 `17ba3090d`, when `font_N_advances[]` went s16→s32). `build_test.sh` only re-ran SWFRecomp when `RecompiledScripts/` was *missing*, so a stale tree compiled against current headers. Fix `60877dc63`: `build_test.sh` keeps a `.recomp_stamp`, and regenerates when it is missing or when the SWFRecomp binary, `test.swf` or `config.toml` is newer (`SWF_REUSE_RECOMPILED=1` opts out). All 11 docs2 games (Tetris, Bloons, Checkers, Doodle_Jump, Minesweeper, N, Pacman, Shopping_Cart_Hero, Snake, Storm_the_House, Tron) regenerate and link `wasm --graphics` with `-Wl,--fatal-warnings`: rc=0, 0 warnings, 0 errors. (docs/ itself hosts no games.) |
| 2. attached-clip goto port | **Landed.** `advance_attached_clip_frames` is deleted. The method form uses the CI chain in every build. Opcode self-gotos on an attached root run inline through `ng_gotoFrameByMC` in every build. The browser now calls the self-goto apply pass, restricted to attached roots. Two real defects were found and fixed (§2). |
| 3. self-goto port for timeline sprites (§5a) | Not taken. The browser apply pass is gated to attached roots, so the `nested_sprite_inframe_goto` gate is unchanged (§3). |
| 4. `g_inside_enterframe_dispatch` root-goto drop | **This is a CI bug.** Flash 32 moves the playhead. The fixture is committed in `fa5bd94e7`. The coordinator funded the fix: cloud slot `w3-enterframe-root-goto` landed `4a25debc9`. Browser check in §4. |

## 1. Goal 1 detail

- Symptom: `tagMain.c: incompatible pointer types … 's16 *' vs 's32 *'` on `font_N_advances`.
- Bisect: the stale files' mtime (Jun 29) and a fresh regen (`rm -rf RecompiledScripts RecompiledTags`) fixed it with no source change. Neither suspect commit (`09b2c9130` stroke tables, `558c5a8cf` abc_emit) emits anything that touches font advances.
- Why only Tetris: it is the only catalogue game whose cache predated s13. The others had been regenerated since then.
- Any local game build can hit the same trap after an ABI change, so the stamp is the general fix, not a Tetris one.

## 2. Goal 2: what changed and why

### 2.1 What the deferred pass really served

`advance_attached_clip_frames` (tag.c, browser arm, run from tagShowFrame) replayed a deferred goto on attachMovie'd clips. A code read plus probes showed:

- The method form (`clip.gotoAndStop(n)`) already reached `ng_gotoFrameByMC` in the browser. The pass only caught the declines, and those now fall to `actionGotoFrame` exactly as in CI.
- `findDisplayObjectByName` / `targeted_sprite` never yields an attached holder: its `instance_name` is NULL, the holder is standalone, and the MovieClip lives in `child_mc_cache`. So the remaining real consumer was **opcode self-gotos inside an attached clip's own timeline** (`gotoAndPlay(3)` in the clip's frame script). Those go through `ng_gotoFrameCurrentSprite`.

### 2.2 Defects found (new fixture `regression/avm1_attached_clip_selfgoto_trace`, Flash 32 golden, pinned direct)

The holder sprite works like this:
- f1 traces.
- f2 traces, then runs `gotoFrame(3)+Play`.
- f3 would trace "skipped".
- f4 traces `_currentframe`.
- f5 traces, then runs `gotoFrame(5)` (self, same frame).
- f6 traces `_currentframe`.

Root attaches it and traces `h._currentframe` on root frames 1..9.

| Line | Flash 32 | HEAD native (both modes) | HEAD browser |
|---|---|---|---|
| root f2 | `h.cf=4` | `h.cf=2` | `h.cf=2` |
| `a f4 cf=` | 4 | 2 | **printed twice**: `cf=2` then `cf=4` |
| root f3 | `h.cf=6` | `h.cf=5` | — |
| `a f6 cf=` | 6 | 5 | **printed twice**: `cf=5` then `cf=6` |

1. **CI defect (native, both modes):** on an attached root, an opcode self-goto was recorded and applied a tick late. `_currentframe` read stale for the rest of the frame and on the next root frame.
2. **Browser defect:** the deferred pass re-ran the target frame's DoAction after the CI path had already run it, so every self-goto target script executed twice.

### 2.3 The change (one commit, all builds unless noted)

- `tag_stubs.c` `ng_gotoFrameCurrentSprite`:
  - When the current sprite is an attached holder (NULL `instance_name`, found in `child_mc_cache` by `display_obj`), and the frame is not in catch-up, the goto runs **inline** through `ng_gotoFrameByMC(app, att_mc, frame, 0)`. `g_current_sprite_obj` is saved and restored around it. If `ng_gotoFrameByMC` declines, the old flag path runs.
  - The app context comes from a new `ng_setStubAppContext()`, called first thing in both `swfStart`s. This is a deliberate choice: changing the function's signature would have meant editing its caller in `actionGotoFrame`, and the coordinator asked me to keep clear of that function (slot w3 was editing it).
  - `ng_record_sprite_self_goto` is ungated.
- `tag.c` `ng_apply_pending_sprite_self_gotos`:
  - The `catch_up_mode` early-clear is ungated.
  - Browser only: the pass handles **attached roots only** (`if (att_mc == NULL) continue;`). It invalidates the clip's DL entries, finalizes `pending_remove`, then rebuilds with `advance_sprite_frames()` under `g_build_only=1` and `g_advance_defer_nested=0`.
- `swf.c` browser block: calls the apply pass after the post-frame-func `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` (§5a edit 1).
- `tag.c`: `advance_attached_clip_frames` (≈120 lines) and its tagShowFrame call are deleted.
- `action.c` `actionCallMethod` non-root `gotoAndStop/Play` arm:
  - The `#if NO_GRAPHICS||OFFSCREEN … #else <browser defer> #endif` block is replaced by the CI chain in every build: `actionChildMovieGoto` → `ng_gotoFrameByMC` → `actionGotoFrame` (+ `is_playing` for play).
  - One browser-only guard stays in front of it: gotoAndStop to the frame already shown only stops the clip (§4).

## 3. Results

### 3.1 Browser (child_probe, WSLg Chrome, `--fatal-warnings` on every link: fatal=0)

child_probe's diff is against `output.txt` (the Flash golden), not a native run.

| Row | before (HEAD) | after |
|---|---|---|
| `regression/avm1_attached_clip_selfgoto_trace` (new) | DIFF: 2 duplicated target-frame lines (`a f4 cf=2`, `a f6 cf=5`) plus stale cf | **match** |
| `regression/avm1_attached_clip_goto_play` | match | match |
| `regression/avm1_attached_clip_goto_play_nonroot` | match | match |
| `regression/avm1_attached_clip_selfgoto_child_parent` | match; `--pixels` cap5/cap9 IDENTICAL to golden | match; cap5/cap9 IDENTICAL |
| `tools/divergence/runs/nested_sprite_inframe_goto` (injected) | root `m` stutter `2,3,4,5,1,1,2`; `_root.c.n` present | **unchanged**: stutter, `_root.c.n` present on all 70 rows. The apply pass skips timeline sprites, so the §5a nested drop does not arise. |
| `regression/avm1_enterframe_root_goto_opcode` (at `4a25debc9`) | not run before (the predecessor report says the browser dropped it, like CI) | **match**: `f1 / ef cf=1 / after cf=3 / f3 cf=3 / ef cf=3 …` = the FP32 golden (the trace keeps `ef cf=3` while the run lasts) |

### 3.2 Native, both modes

- New fixture: no-graphics **pass**, graphics **pass** (HEAD: both fail with the stale-cf lines above).
- Focused gate, agreed with the coordinator: every `regression/avm1_attached_clip_*` and `*selfgoto*` row plus `avm1_enterframe_root_goto_opcode`, 17 rows × both modes. Result: **34/34 pass** (17 no-graphics, 17 graphics).
- Wider attach gate (77 rows that call attachMovie: avm1, from_gnash, from_shumway, regression). Stopped after the first 25 no-graphics rows, because the shared CPU lock was contended (other sessions' batches) and the coordinator's CI full run grades every row. Three of the 25 are non-pass: `avm1/attach_movie_export_not_yet_run` (ruffle_matched), `avm1/globals_monkeypatch` (XMLSocket) and `avm1/movieclip_hittest_shapeflag`. Each has **byte-identical output on the baseline worktree**, so all three are pre-existing.

### 3.2a Expected-flip ledger (for the coordinator's graphics full images + NG full run)

| Row | no-graphics | graphics |
|---|---|---|
| `regression/avm1_attached_clip_selfgoto_trace` | NEW row, pass | NEW row, pass |
| every other row | no flip expected | no flip expected |

The native changes are: an attached-holder opcode self-goto runs inline; `ng_record_sprite_self_goto` is ungated; the apply pass's `catch_up_mode` clear is ungated. They reach only clips created by attachMovie whose own frame script does a GotoFrame. Any flip elsewhere is unexpected and should be reported to me as a defect. The method-form change in action.c and the swf.c/tag.c deletions are browser-only arms; NO_GRAPHICS and OFFSCREEN already ran that chain.

### 3.3 N (attached self-gotos: `tileMC` etc.)

The `n_drive` L1–L4 routes (`routes_ep0.txt`, `START_LEVEL`, `AUTOKILL`, `OBJHASH`, `FREEZE`) were run natively in graphics mode on the baseline worktree (`4b5dca5c2`) and on the after tree. **All four traces are byte-identical** (L1 1338, L2 1282, L3 1297, L4 1007 lines), so no NF/ND telemetry diverges.

### 3.4 Doodle Jump (WSLg Chrome, functional)

Builds: `build_test.sh flasharchive/Doodle_Jump wasm --graphics`, rc=0 and 0 wasm-ld warnings, for both base (worktree at `4a25debc9`) and after. Each was deployed to docs2 in turn. The probe (`$S/dj_alive.py`) clicks PLAY, then polls a page-side rAF counter and `dbgRootFrame` every 0.5 s. Canvas screenshots hang in WSL2 (memory `wsl2-board-screenshot-hang-rootcause`), so the old `dj_gameplay.py` is unusable here.

| Build | Runs reaching gameplay (root frame 1, rAF climbing ~12/s) | Runs that froze right after PLAY |
|---|---|---|
| base `4a25debc9` | 0 | 1 |
| after (this slice) | 3 | 4 |

**s29 lead: Doodle Jump browser freeze, pre-existing.** It reproduces at base. Within about 1 s of PLAY the page's main thread stops answering `page.evaluate` for the remaining 190 s, and the renderer process sits at **~104% CPU**, i.e. a busy loop, not a GPU stall. Levels are random (the browser's `Math.random` is unseeded), which fits a level-dependent loop, for example the `attachBlocks` while loop. Next steps:
1. Seed the browser (`EMCC_CFLAGS=-DMOCK_DATE_TIME=…`, the N recipe) to get a deterministic repro.
2. Break in with a wasm stack sample.
3. Check `wasm-stack-overflow-64kb` (an earlier DJ browser hang).

Not chased in this slice.

## 4. Open question: the same-frame guard

On `gotoAndStop(N)` when the clip already shows N, the browser keeps a guard that **only stops** the clip. CI's `ng_gotoFrameByMC` same-frame branch instead re-runs the frame's tags. Two things depend on the guard:
- Doodle Jump's breakable `attachBlocks` loop: each re-collision calls `block.gotoAndStop(4)`. Without the guard, every call re-placed the break piece at `_y=0`.
- N's `tileMC` (attach, then `gotoAndStop(1)` on frame 1) needs the stop.

I kept the guard browser-only rather than change CI's branch: the CI branch has its own gnash/avm1 coverage, and a CI change would need a corpus run. A Flash fixture for "gotoAndStop(current) on an attached clip whose frame re-places a child" would settle which side is right. That is the next slice's oracle.

## 5. What is left (updates the browser-root-goto §5 table)

| Arm | Where | Completion mechanism |
|---|---|---|
| ~~`advance_attached_clip_frames`~~ | — | **DONE (this slice).** |
| same-frame `gotoAndStop` guard | action.c browser-only `else if` | Write the Flash fixture (§4). Then either make it all-build, or change CI's `ng_gotoFrameByMC` same-frame branch to match. S plus a corpus run. |
| `ng_apply_pending_sprite_self_gotos` for **timeline** sprites | tag.c (browser arm now attached-only) | Still M (browser-root-goto §5a). Drop the `att_mc == NULL` skip, then bisect why the apply pass drops nested `_root.c.n` (s28 tag.c candidates `613c0f100`, `0f2caed84`, `e7afd5ad2`). Oracle: `nested_sprite_inframe_goto` via child_probe (the recipe is now `$S/nprobe.sh`, see §6). |
| dead `pending_remove` consume/finalize code | tag.c, tag_stubs.c | Delete (s27 §2.2). |
| `graphics_stubs.c` Group 1 | browser-eager-init §3.4 | Still unmeasured. |
| ~~CI enterframe root-goto drop~~ | — | **DONE** by cloud slot w3 (`4a25debc9`) from this slice's fixture. |

## 6. Method notes

- `ruffle-tests/tests/swfs/_swfbridge/.../dj_probe/run_native.py` goes through verify_output's `run_binary`, which has a hard-coded 30 s `proc.wait(timeout=30)`. N's long routes need more, so run `build/test_run` directly, with `TZ=NPT-5:45`, `CAPTURE_TRIGGERS`, `CAPTURE_OUTPUT_DIR`, the lavapipe ICD env and a long `timeout`.
- child_probe on a scratch suite: copy `injected.swf` → `test.swf`, the Ruffle `trace.txt` → `output.txt`, and the gate's `test.toml`. Pass the tests dir relative to the repo root, to both `build_child_probe.sh` and `run_child_probe.py --tests-dir`.
- The shared tree moved under the gate: the coordinator applied `4a25debc9`'s action.c change mid-run. I restarted the gate on the new tree and moved the baseline worktree to `4a25debc9`, so before/after differ only by this slice.
- Generated C is an ABI with the runtime headers. Any cached `RecompiledScripts/` older than a header change is suspect, which is why the stamp now exists.
