# s30 browser ladder #5: browser-pending-finalize

Local one-task session, 2026-11-27. Predecessor: `browser-clip-event-order` (`cd519d658`).
**Landed on master: `b8671fd2f`** (browser-only; tag.c + graphics_stubs.c). **Local branch, NOT pushed:
`local/s30-rmc-clipaction-unload` @ `29565880b`** (native/CI code, action.c + the rider fixture; for the
coordinator / s31 to land and grade). No CI dispatched (per brief).

**CI reach of `b8671fd2f`: none.** `gcc -E -P` of tag.c is md5-identical to HEAD under `-DNO_GRAPHICS`
(`d8279210…`) and `-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG` (`70d0159a…`), the same hashes the predecessor recorded.
graphics_stubs.c compiles nothing in either CI set (its body is `#if USE_WEBGPU && !NO_GRAPHICS` plus `#ifndef OFFSCREEN_RENDER`), and its preprocess is
identical as well.

## 0. Verdicts

| § | Item | Verdict |
|---|---|---|
| 1 | Port the browser pending-finalize queue | **PORTED** (`b8671fd2f`). |
| 1 | Oracles: gnash `action_execution_order_test11` lines 20+ / `_test4` lines 18+ | **Full = FP32 golden in the browser**: test11 32/32, test4 26/26 (HEAD: line 20 / line 18). |
| 1 | 3 exec-order fixtures | **= golden** (38 / 82 / 18 lines), on the final code. |
| 2 | Rider `ng_queue_slot_unload_events` | **Browser FIXED** (`b8671fd2f`): the browser now runs the unload, so browser = native. **The FP32 fixture found an EVERY-BUILD bug**: native fails it in both modes. Fixed on the local branch only (§3). |
| 3 | Native both modes unchanged | **Yes.** md5 proof above, plus 58 rows × 2 modes = **116/116 PASS** on the working tree. |
| 3 | DJ / N smoke | DJ `dj_alive.py click` **3/3 alive**. N `N_drive` **984/984 NF byte-identical** to the s30 #4 trace, reaches `epvictory` at frame 1250 / tick 477. Both builds were deployed to `docs2/examples` at 17:20 / 17:22 from the commit tree. |

## 1. Mechanism (functions touched)

HEAD browser:
- `tagRemoveObject2` (`tag.c:15964`, the `_ro2_has_unload` branch → `queue_pending_finalize_mc`, `tag.c:16132`) and
  `tagRemoveObject` (`tag.c:15951`) hand a removed clip that has an unload handler to the pending-finalize queue.
- In the browser, the queue functions were no-op stubs in the `#else` of the queue block, so the clip was never marked
  `pending_removal` before that tick's EF, and its display entry was never cleared.
- Result: the clip got one more EF round on its removal tick, ran `onUnload`, and then kept getting EF on later ticks.

`b8671fd2f` (every build now compiles the CI code):
- **`tag.c` queue block:** `ng_depth_has_pending_finalize` (`:15502`), `queue_pending_finalize_mc` (`:15510`),
  `run_pending_finalize_mark_only` (`:15543`) and `run_pending_finalize` (`:15552`) are ungated, and the browser stubs are deleted. The state table and
  its realloc/free scrub funnel were already all-build.
- **`tagFlushPendingEnterFrame`** (`tag.c:7875`): the `run_pending_finalize_mark_only` call (`:7906`) is ungated. Queued clips
  are now marked before the EF gather in the browser too.
- **The drains** (`action_queue.c:365/579/656`) were already unconditional. They now reach the real `run_pending_finalize`.
- **`actionMarkMCPendingRemovalDirect`** (`action.c:26537`) and **`clear_display_entry`** were already all-build.
- **`ng_queue_slot_unload_events`** (`tag.c:13340`): the CI gate is closed before the function and reopened after it, so
  the function did not move and the CI preprocess is unchanged. Its `graphics_stubs.c` stub is deleted. Callers: `actionRemoveSprite`
  (`action.c:~69576/69635`) and the `removeMovieClip` method's root-slot arm (`action.c:~84502`).
- `ng_queue_placement_clip_events`' browser stub is kept. It is still dead in the browser (both callers are CI-gated; see the s30 #4 report §5).

Not ported, deliberately: the CI-only blocks in `tagPlaceObject2` / `tagPlaceObject2Ratio` (`tag.c:~14038`,
`~14735`: cross-frame sprite REPLACE preservation) and `tagSetInstanceName` (`tag.c:~17043`: Remove+Place name-change
pending). They read `ng_depth_has_pending_finalize`, but they are a wider REPLACE/name model with no browser oracle yet. Port
them only behind a fixture (gnash `loop_test10`, `RegisterClassTest4`, `replace_sprites1test` are the CI oracles).

## 2. Exec-order browser A/B (child_probe, WSLg Chrome, every link `-Wl,--fatal-warnings`)

Each cell gives the first line that differs from the golden over the golden-length prefix (`=` = whole prefix matches).
HEAD = s30 #4 final (`cd519d658` code); port = `b8671fd2f`.

| Oracle (golden) | HEAD | port (`b8671fd2f`) |
|---|---|---|
| gnash `action_execution_order_test11` (FP32, 32 lines) | line 20 | **`=`** |
| gnash `action_execution_order_test4` (FP32, 26 lines) | line 18 | **`=`** |
| `avm1_exec_order_sibling_interleave` (38) | `=` | `=` |
| `avm1_attach_timeline_frame_order` (82) | `=` | `=` |
| `avm1_exec_order_attached_selfremove` (18) | `=` | `=` |
| `avm1_swapdepths_remove_clipevent_unload` (FP32, 13; local branch) | line 6, **no `c unload` at all** | line 6 (= native HEAD: unload fires, typeof `undefined`) |
| same, port + local-branch native fix | n/a | **`=`** |

## 3. Rider: FP32 fixture `regression/avm1_swapdepths_remove_clipevent_unload` (on the local branch)

The fixture places a timeline clip `c` with `onClipEvent(enterFrame)` + `onClipEvent(unload)`. Its frame-2 script runs `c.swapDepths(10); c.removeMovieClip()`. The
control clip `k` has the same handlers but is not swapped, so its `removeMovieClip` is a no-op. FP32 golden (direct, 2 captures identical):

```
c after remove=movieclip            <- Flash keeps a clip with an unload handler until its unload runs
c unload t=2 typeof=movieclip       <- unload at the end of the frame script, clip still resolvable
k ef 2                              <- no `c ef 2`
f3 c=undefined k=movieclip
```

Native (both modes, HEAD) printed `undefined` on both lines. The cause: the `removeMovieClip` defer test
(`_rmc_has_unload`, `action.c:~84466-84487`; the same test as `_rs_has_unload` in `actionRemoveSprite`, `action.c:~69535-69556`)
counts only an AS `onUnload` (self or descendant), never a slot `onClipEvent(unload)` clip action. And even when it defers, it
memsets the display slot at once, so a timeline clip (resolved by display-list name) is gone.

Local-branch fix (`29565880b`), in `actionRemoveSprite` and the `removeMovieClip` method:
- The defer test also counts `ng_compute_has_unload(slot)` (`tag_stubs.c:1154`).
- A slot with a clip-action unload goes to `queue_pending_finalize_mc` instead of being memset, as `tagRemoveObject2`'s
  deferred path does.

Pricing:
- **64 rows** (every non-bridge SWF with a `removeMovieClip` / `unloadMovie` string), no-graphics, ACTUAL `--diff`
  byte compare, main vs branch: **only the fixture moved (fail→pass), 53→54 PASS.**
- Graphics: the fixture PASSES, the 64 rows are unpriced.
- **The opcode form (`RemoveSprite` 0x25) is not string-detectable, so the `_rs_*` arm is priced by fixture only.**
- In the browser (port + branch), the fixture = golden.

Why it is not on master: it is CI code, and the timing rule applied. The fixture is on the branch too, since on master it would add a
by-design failing row to the final grading run.

## 4. Native + browser before/after

| | before | after |
|---|---|---|
| native NO_GRAPHICS / graphics, tag.c CI preprocess | `d8279210` / `70d0159a` | identical |
| 58-row ledger × 2 modes (s30 #4 set) | 116/116 (s30 #4) | 116/116 |
| browser test11 / test4 | line 20 / line 18 | full = golden |
| browser rider fixture | unload dropped | unload fires (= native); = golden with the branch |
| DJ click | 3/3 (s30 #4) | 3/3 |
| N_drive NF | 984 | 984, byte-identical |

## 5. Next (successor)

1. **Land + grade `local/s30-rmc-clipaction-unload`** (`29565880b`, one action.c hunk pair + fixture). Run a CI graphics +
   no-graphics grading. Expected movement: the fixture only (from the 64-row no-graphics price), plus any opcode-form
   `RemoveSprite` rows with slot unload handlers (unpriced).
2. Fixture first, then port: the browser `tagPlaceObject2` / `tagPlaceObject2Ratio` REPLACE preservation and `tagSetInstanceName`
   Remove+Place name-change blocks (§1, "Not ported"). They are the last CI consumers of `ng_depth_has_pending_finalize`.
3. Carried from s30 #4 §6: `upgrade_attached_clip_initialized` vs CI `ng_upgrade_attached_standalone_initialized` (unfixtured);
   nested `removeMovieClip` of a clip with clip-action `onUnload` (the slot UNLOAD queue is root-only; the branch fix
   inherits that); stale `attach_registration` `sprite_max_depth` after a nested swapDepths grow.
4. `ng_queue_placement_clip_events` browser stub: still dead. It only matters with the browser clone display-list slot (M).

## 6. Traps

- `n_drive_compare.py` prints only the ND lines. The NF lines go to
  `tools/divergence/game_drive/compare_out/ndrive_ours_trace.txt`, so compare THAT file's `^NF` lines (a `grep -c ^NF` of stdout gives 1).
- The FP32 trace of a test that `stop()`s while a clip keeps tracing EF is always `stop=TRUNCATED`. Take the stable
  prefix over 2 captures, and set `num_frames` so native emits exactly that prefix (here 5 → 13 lines).
- A CI gate around a function you want to ungate: close and reopen the gate around the function instead of moving it.
  The CI preprocess stays byte-identical, and the md5 proof stays trivial.
