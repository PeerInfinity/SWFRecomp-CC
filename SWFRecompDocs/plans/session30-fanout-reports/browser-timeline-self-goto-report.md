# s30 browser ladder #3: browser-timeline-self-goto

Local one-task session, 2026-11-27. Predecessor: `browser-nested-swapdepths-remove` (`92f7d5e8a`).
Code: **`171b302e4`** (browser port + dead `pending_remove` deletion) and **`dd2f979a5`** (a timeline
sprite's own GotoFrame opcode applies inline, all builds, + a new Flash fixture). Commit-tree base:
`715a5300c` (s30 batch 3). No CI dispatched (per brief).

## 0. Verdicts

| § | Item | Verdict |
|---|---|---|
| 0 | Browser A/B of `w1-exec-order` (`17bc522de`) | **Browser = FP32 golden on all three fixtures. The kill switch changes only the sibling fixture.** No port needed. The browser clip-event half (req 3) stays unported, as the w1 report says. |
| 1 | Timeline-sprite `ng_apply_pending_sprite_self_gotos` port | **PORTED** (`171b302e4`). The s28 §5a nested drop **no longer reproduces** on current HEAD, so no bisect was needed. Gate `nested_sprite_inframe_goto`: browser 50/50 (HEAD: `m` and `_root.c.n` stutter with period 6). |
| 1+ | New: a timeline sprite's own GotoFrame opcode lands a tick-phase late in **every build** | **FIXED** (`dd2f979a5`). Found by the new FP32 fixture `regression/avm1_timeline_selfgoto_child_replace`, which failed in both native modes and the browser. Priced locally only, see §4. |
| 2 | Dead browser `pending_remove` code | **Proven dead and DELETED** (`171b302e4`), the field too. |
| 3 | Native both modes unchanged | **Yes.** 55 rows × 2 modes are byte-identical against a HEAD mirror and all pass. The new fixture fails before and passes after, in both modes. |

## 1. Item 0: exec-order browser A/B (child_probe, WSLg Chrome, `-Wl,--fatal-warnings`)

Each column is one build; `=` means that tick equals the golden. Ticks are delimited by `root fN` lines. The browser keeps
ticking past the golden's span, so the comparison covers the golden-length prefix. The `WebGPU:` console lines are filtered:
two of them, "canvas configured with a different format" and "no frame completed in 3000 ms", land mid-trace and are
SwiftShader noise.

| Fixture (golden) | HEAD build | `EMCC_CFLAGS=-DSWF_EXEC_ORDER_EF_OFF` |
|---|---|---|
| `avm1_exec_order_sibling_interleave` (exporter = FP32, 38 lines) | t1–t6 `=` (38/38) | t1 `=`, **t2 t3 t4 differ**, t5 t6 `=` (first diff line 5: `tl ef` before `a f2`) |
| `avm1_attach_timeline_frame_order` (FP32, 82 lines) | t1–t6 `=` (82/82) | t1–t6 `=` (82/82) |
| `avm1_exec_order_attached_selfremove` (18 lines) | t1–t6 `=` (18/18) | t1–t6 `=` (18/18) |

This is exactly the w1 prediction: req 1 works in the browser, and only the sibling fixture depends on it. The fixtures were
re-run on the final tree (§5): all still match.

## 2. Item 1: the port, and the bug it uncovered

### 2.1 The port (`171b302e4`)
- `tag.c` `ng_apply_pending_sprite_self_gotos` (`tag.c:2523`): the browser-only `if (att_mc == NULL) continue;`
  filter is deleted. Of the s28 §5a "3 edits", the other two had already landed in s28 browser-attached-goto: the swf.c
  call (`swf.c:1330`) and the ungated `ng_record_sprite_self_goto` call.
- Same function, replay tail (`tag.c:2612-2635`): the CI `process_sprite_needs_init` block for the rebuilt target
  frame was `NO_GRAPHICS || OFFSCREEN_RENDER` only. Now in the browser it runs for timeline sprites (`if (att_mc == NULL)`).
  Attached roots keep their build-only `advance_sprite_frames` tail (`tag.c:2637`).
- The comments in `swf.c` (`swf.c:1324`, plus the stale OFFSCREEN "browser keeps the deferred path" note) and in `tag_stubs.c`
  `ng_gotoFrameCurrentSprite` are updated.
- **The §5a drop is gone.** The port alone, on the pre-batch-3 tree, gave the gate 50/50 with `_root.c.n` present
  in every row. Whatever s28 hit between `43bdb35a8` and `aa595bbc6` was fixed by an s29/s30 landing. Not bisected,
  because there is nothing left to bisect.

### 2.2 The bug the port's fixture found (`dd2f979a5`, every build)
The gate's target frames place no children, so the replay tail was untested. New fixture
`regression/avm1_timeline_selfgoto_child_replace`:
- Sprite `s` (3 frames): f1 places child sprite `k`, f2 removes it, f3 does `gotoAndPlay(1)` (opcode).
- The root traces `s._currentframe` and `s.k._currentframe` each frame.
- Golden: Flash Player 32 direct, 2 runs, identical 27-line prefix (= 9 ticks).

| | tick 3 root line | tick-3 queued scripts after the root script |
|---|---|---|
| **Flash 32** | `root f3 s.cf=1 k.cf=1` | `k f1 cf=1`, then `s f1` |
| HEAD, no-graphics / graphics / browser | `root f3 s.cf=3 k.cf=undefined` | `s f1`, then `k f1 cf=1` |

**Mechanism.** `tag_stubs.c` `ng_gotoFrameCurrentSprite` (`tag_stubs.c:1239`) ran the opcode form inline only for
attachMovie'd roots (s28). For a timeline sprite it set `sprite_manual_next_frame` and recorded the goto for the post-drain
apply pass, which runs after the root frame script. So the root read the issuing frame, and the target's new child did not
exist yet. The method form (`this.gotoAndPlay`) was already inline through `ng_gotoFrameByMC`.

**Fix** (`tag_stubs.c:1286-1306`): when the running script's `g_current_context` is this sprite's clip
(`display_obj == obj`), take the same `ng_gotoFrameByMC(…, play=0)` path. A guard handles name clashes:
`ng_gotoFrameByMC` resolves `mc->name` in the global (root) list first, so the inline path is used only when that lookup
misses or lands on this very entry. A nested clip that shares a root clip's name keeps the deferred path (the s30 #2
bug class). After this commit, the apply pass handles only those fallbacks and goto records from other paths.

Result: the fixture passes in both native modes and in the browser.

## 3. Item 2: `pending_remove` is dead (proof), deleted

1. **No writer.** `git grep pending_remove` over the runtime, the recompiler, the wasm wrappers and the scripts finds no
   assignment of a non-zero value. The last writers (`tagRemoveObject(2)` `= 1`) were removed in `96952c641`
   (s27 browser-parked-frame: RemoveObject = the CI arms). The recompiler never emits the field.
2. **No garbage source.** Every `DisplayObject` store is `calloc`/`HCALLOC`, or a struct copy of an existing entry
   (`tag.c` `*under = *slot`). No display list is `malloc`'d or `realloc`'d uninitialised. So the field is always 0, and every
   `if (…pending_remove)` body is unreachable in every build.
3. **Deleted:**
   - `finalize_pending_removes_recursive` and its `tagShowFrame` call (before the browser `AQ_KIND_LOAD` drain);
   - the browser consume blocks in `tagPlaceObject2` and `tagPlaceObject2Ratio`;
   - the finalize loop in `tag_stubs.c` `ng_gotoFrameByMC`'s replay;
   - the attached finalize loop inside `ng_apply_pending_sprite_self_gotos`;
   - the `u8 pending_remove` field in `swf.h`.

   Three comments that cited the walk were fixed. `invalidate_mc_for_dl_entry` and `clear_display_entry` still have other
   callers.

## 4. Native ledger (both modes; ACTUAL `--diff` byte-compare vs a HEAD mirror)

The mirror is HEAD `SWFModernRuntime` from `git archive`, with every other top-level entry symlinked. It needs
`scripts/` (`check_charid_wrapping`), or verify_output dies on import.

Row set (56): `regression/avm1_attach*`, `avm1_exec_order*`, `avm1_*goto*`, `avm1/goto*`, plus the new fixture. None has
`[approximations]`.

| Tree | no-graphics | graphics |
|---|---|---|
| HEAD mirror (`0224aaf25`) | 55 pass, new fixture FAIL | 55 pass, new fixture FAIL |
| port + cleanup (`171b302e4` content, pre-batch-3) | byte-identical to HEAD on all 56 | byte-identical on all 56 |
| + inline fix | 56 pass; only the fixture moved (FAIL→PASS) | 56 pass; only the fixture moved |
| **commit tree** (`715a5300c` + both commits) | 56/56 pass, byte-identical to the row above | 56/56, identical |

Also: the gate `nested_sprite_inframe_goto` passes natively in both modes with the final code.

CI reach of `171b302e4`: under `-DNO_GRAPHICS` and under `-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG` (`gcc -E -P`), the
only change in tag.c, tag_stubs.c and swf.c is the removed `u8 pending_remove;` line. `dd2f979a5` **does** change CI
semantics, and it is priced only on the 56 rows. **The next grading run is its real price** (`categories=all`). It touches
every timeline sprite whose own frame script issues GotoFrame/GoToLabel.

## 5. Browser before/after (child_probe; before = HEAD mirror build, after = final code)

| Fixture | HEAD | final |
|---|---|---|
| gate `nested_sprite_inframe_goto` (Ruffle expected, 50 lines) | DIVERGE line 27 (`c.n` and `m` `_cf` stutter) | **50/50** (port alone: 50/50 too) |
| `avm1_timeline_selfgoto_child_replace` (FP32, 27) | DIVERGE line 7 (`s.cf=3 k.cf=undefined`) | **27/27** |
| `avm1_exec_order_sibling_interleave` (38) | 38/38 | 38/38 |
| `avm1_attach_timeline_frame_order` (82) | 82/82 | 82/82 |
| `avm1_exec_order_attached_selfremove` (18) | 18/18 | 18/18 |
| `avm1_goto_target_child_order_{gotoscript,normal}` | 6/6, 5/5 | same |
| `avm1_selfgoto_current_frame_opcode` | 8/8 | 8/8 |
| `avm1_sprite_goto_script_overflow` | 65/65 | 65/65 |
| `avm1_goto_current_frame_clip` | 23/23 | 23/23 |
| `avm1_attached_clip_selfgoto_{trace,child_parent}` | 14/14, 6/6 | same |
| `avm1_browser_eager_init` | 10/10 | 10/10 |
| `avm1/goto_execution_order` | 2/2 | 2/2 |

Past the golden span, every row's before and after traces are identical over their common length, except the two moved
rows. All links had zero wasm-ld warnings. The gate, the new fixture and the sibling fixture were rebuilt once more on
the actual commit tree (with batch 3): 50/50, 27/27 and 38/38.

**Games, final build** (WSLg Chrome = functional only):
- **Doodle Jump** `dj_alive.py click`: 3/3 reached root frame 1, rAF climbed to 59–65 by 10 s, and every eval answered.
- **N** (`N_drive`, seeded `-DMOCK_DATE_TIME=981152406000`): 2 runs, each 1043 lines with 984 NF and reaching
  `epvictory`, no PAGEERROR. All **984/984 NF lines are byte-identical** to the s30 #2 trace (itself = exporter),
  including the run-variable `t=297`.

## 6. Traps found on the way

- **`deploy_example.sh flasharchive/N_drive --no-index --graphics` deploys to `docs/examples`, not `docs2`.** The default
  `EXAMPLES_DIR` is `../docs/examples`. My first N smoke therefore ran the PREVIOUS session's `docs2` wasm. It
  "passed" byte-identically, which proves nothing. Pass the dir: `deploy_example.sh flasharchive/N_drive
  <repo>/docs2/examples --no-index --graphics`. Then check the `docs2/examples/flasharchive/N_drive/N_drive.wasm` mtime.
  The stray `docs/examples/flasharchive/` it created is untracked; delete it.
- **Parallel verify_output of ONE test in two modes races** on the test dir's `RecompiledScripts`
  (`FileNotFoundError: script_1.c`, reported as a runtime_error). Parallelise across tests, never across the modes of
  one test.
- **ccache misses per test on the runtime** (per-test `-D`s), so each native run is about 1 min. Two lock users
  starve each other: a cached native run waits behind every 3.5-min browser build. Run one 4-wide xargs pool inside
  ONE `flock` hold instead, which is the same -j4 budget.
- **The coordinator landed batch 3 mid-session** (14:29, between my native pricing and the browser sweep). The
  commit-tree re-runs in §4 and §5 are the ones that count.

## 7. Next (successor = browser ladder item 4)

1. **Price `dd2f979a5` in the next grading run.** If a row regresses, the first suspect is a sprite whose frame script
   `gotoAndPlay`s itself and whose observers relied on the old one-tick-phase lag. Reverting this one commit restores HEAD
   behaviour; `171b302e4` stands alone.
2. **Browser clip-event exec order (w1 req 3):** port `tagClipEFCollectRootPass` plus `tagClipEFFireNewerOrEqual` to the
   browser root pass, with `dispatch_attached_clip_enterframe` joining the pend list. Oracle: gnash
   `action_execution_order_test11`/`_test4` in child_probe. Their browser order should then move off the kill-switch
   order. M.
3. **`graphics_stubs.c` Group 1** (`ng_queue_placement_clip_events`, `ng_queue_slot_unload_events`), still unmeasured
   since s27. S to measure.
4. Open from s30 #2, still unfixtured: nested `removeMovieClip` of a clip with clip-action `onUnload` (the slot UNLOAD
   queue is root-only), and stale `attach_registration` `sprite_max_depth` after a nested swapDepths grow.
