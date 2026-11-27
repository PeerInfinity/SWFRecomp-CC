# browser-attach-child-early — s30 browser ladder #1 (report)

Local one-task session, 2026-11-27. Predecessor: `browser-attach-order`
(`session29-fanout-reports/browser-attach-order-report.md` §5, code `078350610`).

## 1. Verdict

**Both browser-only defects are FIXED.** The browser now matches the fixture's FP32 golden
`regression/avm1_attach_timeline_frame_order` on all 82 lines. It prints 0 placement warnings
over a 2786-line run (before: 82-line prefix diverged at `pt`, 10+ warnings per loop).
Native output is unchanged in both modes: the change is a browser-only arm plus a flag that
is only ever raised in the browser. Minesweeper radios, Doodle Jump and N still work.

| Brief item | Result |
|---|---|
| 1. attached clip's timeline child advances on attach tick | FIXED: `ng_attachMovie` force-build now runs under `g_build_only` (no deletion; Minesweeper still needs the build of still-unbuilt holders) |
| 2. ride-along `Failed to place object at depth 1.` | FIXED: owner = a guard lost in s28 `613c0f100`; restored |
| 3. native both modes unchanged | 24 rows × 2 modes = 48/48 PASS |
| 4. DJ + N functional | DJ reached gameplay 5/5 (one run had slow rAF); N NF byte-identical except one tick that varies run to run (§4) |

## 2. Mechanism

### 2a. Early advance (`SWFModernRuntime/src/libswf/tag_stubs.c`, `ng_attachMovie`, ~line 680–725)

The browser-only (`#if !NO_GRAPHICS && !OFFSCREEN_RENDER`) "force nested build" block after
`funcs[0]` called `advance_sprite_frames` with `g_advance_defer_nested = 0`.

- Since s27 browser-eager-init, `funcs[0]`'s placements already build the timeline children
  (`sprite_display_list != NULL`).
- So `advance_sprite_frames` took its normal (non-`just_allocated`) path and stepped each
  child to frame 2 on the attach tick. `ap60.pt` then ran one frame ahead for the rest of the run.

**Fix:** set `g_build_only = 1` around the call (saved and restored).
`advance_sprite_frames` (`tag.c` ~1450) then has two cases:
- an unbuilt holder still runs its `just_allocated` frame 0;
- an already-built sprite goes to `advance_sprite_children_only`, which recurses without moving its playhead.

`ng_gotoFrameByMC`'s replay build (`tag_stubs.c` ~1585) already uses exactly this mode, for the
same Minesweeper `frb_states` reason.

**Why not delete the block:** its job is the still-unbuilt nested holders under
`g_advance_defer_nested`, Minesweeper's `frb_states_mc` cid 7/9/11/13/16 bounds. I kept the
block in build-only form rather than take that risk. The radio area is pixel-identical (§3).

### 2b. Spurious warning (`SWFModernRuntime/src/libswf/tag.c`, `tagPlaceObject2` ~13642, `tagPlaceObject2Ratio` ~14515)

When a sprite wraps naturally, `advance_sprite_frames` (`tag.c` ~1766) re-runs frame 0.
- **CI builds** raise `g_loopback_replay`, which skips the occupied-depth gate.
- **Browser** raises `g_nested_loopback_quiet` instead. Frame 0's same-char re-place of a surviving
  child is then refused by the gate, and that refusal *is* the survives_rewind outcome.

The gate's printf used to sit under `if (!g_nested_loopback_quiet)`. s28 w2-occupied-depth
(`613c0f100`) restructured that block into keep-both plus refuse and dropped the guard. Since then
the flag was set and never read (`git log -S`). With s28's `ng_same_char_forward_replace`, every
browser loop of a same-char frame-0 placement printed the warning.

**Fix:** at the top of both gates, `g_nested_loopback_quiet` now refuses silently, clearing the
pending clip actions and instance name the same way the refuse path does. It also skips
keep-both, which would otherwise stack a duplicate child on every loop in SWF≤5 content.
`g_nested_loopback_quiet` is defined in all builds but only set in the browser `#else` arm, so
CI behaviour is unchanged by construction.

## 3. Evidence

**Browser fixture** (`tools/browser-test/child_probe`, `-Wl,--fatal-warnings`, 0 wasm-ld warnings):

| | first 82 trace lines vs golden | `Warning:` lines |
|---|---|---|
| before (HEAD 9467fb0d8) | 3 cells differ: `pt f2` on tick 1, `pt f3`/`f1` one frame ahead after that | 10+ per loop cycle |
| after | **identical** | **0** in 2786 lines |

**Native** (`verify_output.py`, default + `--mode=graphics`, rows `regression/avm1_attach*`,
`avm1_attached_clip*`, `avm1_exec_order*`, `avm1/attach*` = 24 rows): 48/48 PASS.

**Minesweeper** (`rebuild_docs2_demos.sh flasharchive --only Minesweeper,Doodle_Jump --fast`,
rc=0, 0 link warnings; menu captured by GPU readback ~9 s after Run):
- The radio area (x 255–400, y 125–195) has **0 px** diff against the pre-change capture from
  the Nov 24 docs2 build. The circles and dot are present, and labels sit beside the circles.
- All 7206 px of whole-frame diff are in the mine graphic. They come from the render commits
  since that build, not from this change.

**Doodle Jump** (`dj_alive.py click`): 5/5 reached root frame 1, page answered every eval.
- 4 runs: rAF climbing (to ~40–60 at 10 s).
- 1 run: slow, rAF 6 → 6 in its last 0.5 s sample. SwiftShader load. Not judged a freeze, because the page answered.

**N** (`N_drive`, seeded `EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, built directly with
`build_test.sh flasharchive/N_drive wasm --graphics` + `deploy_example.sh`):
- Run 1: 413 lines. Identical to the s29 trace except NF `t=297` `h=` (clip-position hash).
- Run 2: 394 lines, and its `t=297` matches the **old** trace. So that tick's `h=` varies between
  runs of the same build; it is not this change. Otherwise byte-identical.

## 4. Findings for others

- **`rebuild_docs2_demos.sh flasharchive --only N_drive --fast` fails** ("BUILD FAILED", no
  detail). Direct `build_test.sh flasharchive/N_drive wasm --graphics` + `deploy_example.sh … --graphics`
  works. Unclear if the wrapper ever supported N_drive (s29 reports don't say how it was rebuilt).
- **The browser N_drive `h=` at `t=297` varies between runs of the same build** (2 runs, 2 values:
  `33537650:25435215` and `33537320:25435040`). Earlier "byte-identical" N comparisons were lucky
  on this tick. A short-lived particle probably depends on wall-clock timing. The README's `ND cp`
  probe names the clip; not done here.
- `docs2/examples/flasharchive/Minesweeper` was last built Nov 24. Its menu capture right after
  Run (the stock `minesweeper_capture.py`, 3 s) is blank grey. Captures from ~6 s on are fine.

## 5. Next (successor = browser ladder item 2)

`regression/avm1_nested_child_swapdepths_remove` (s29 browser-gotoandstop-current §open).
- A sprite's timeline child that does `swapDepths` + `removeMovieClip` never leaves the parent's
  sprite display list: `ng_updateDisplayDepth` / `removeMovieClip` handle the root DL only. The
  fixture fails **by design in every build**, so this is not browser-only.
- Grade natively in both modes first (s27 rule).
- `ng_updateDisplayDepth` is defined in `tag_stubs.c` and called from `action.c`/`tag.c`. Keep clear of the w1-exec-order files (`swf.c`/`swf_core.c`,
  `action_queue.c`, `tag.c` advance functions).
