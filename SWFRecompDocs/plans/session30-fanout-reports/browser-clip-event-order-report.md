# s30 browser ladder #4: browser-clip-event-order

Local one-task session, 2026-11-27. Predecessor: `browser-timeline-self-goto` (`171b302e4` + `dd2f979a5`).
Commit-tree base: `9dc3e514a` (s30 batch 4). Code: one file, `SWFModernRuntime/src/libswf/tag.c`. No CI dispatched
(per brief). **CI reach: none.** `gcc -E -P` of tag.c is md5-identical to HEAD under `-DNO_GRAPHICS` and under
`-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG`, so both native modes compile the same code as before. Every edit removes a
`NO_GRAPHICS || OFFSCREEN_RENDER` gate whose `#if` arm was already the CI code.

## 0. Verdicts

| § | Item | Verdict |
|---|---|---|
| 1 | Port w1-exec-order req 3 (clip-event merge) to the browser | **PORTED.** The browser root pass now gathers the clip-event EFs, including attachMovie'd clips' children, into one place_seq list. The method pass fires them interleaved with the onEnterFrame methods and the queued exec-block actions, as in CI. |
| 1+ | New: nested clips placed on a sprite's LATER frame never got clip-event enterFrame in the browser | **FIXED** (same commit). This was required for the test11 oracle (mc11/mc21/mc12 never fired). |
| 1 | Oracles: gnash `action_execution_order_test11` / `_test4` | **Order now = FP32 golden.** test11 matches the golden through line 19 (HEAD: diverged at line 6). test4: the tick-2 EF/script interleave is now exact (HEAD diverged at line 12). Both still diverge later, at the clip-removal tick (§3). That is a separate, pre-existing browser removal-model gap, not order. |
| 1 | The three exec-order regression fixtures | **= golden** at HEAD and after the port, on every tick. |
| 1 | Kill switch `-DSWF_EXEC_ORDER_EF_OFF` | **Works.** It moves the sibling fixture (line 5), test11 (line 8) and test4 (line 12); the other two fixtures are unchanged. |
| 2 | Native both modes unchanged | **Yes.** CI preprocess is md5-identical (above), and 58 rows × 2 modes PASS (§4). |
| 2 | DJ + N smoke | DJ `dj_alive.py click` **3/3**. N seeded `N_drive` **984/984 NF byte-identical** to the s30 #2/#3 trace in 2/2 runs, `epvictory`, no errors. Repeated on the FINAL code (commit tree `9dc3e514a` + port incl. the linkage-filter restore, wasm rebuilt and deployed to `docs2/examples` 16:35/16:37): DJ 3/3 alive (rootf 1/2/1), N 1/1 at 984/984. The 5 oracles were rebuilt on the final code too, with the same results as §2. |
| 3 | `graphics_stubs.c` Group 1 | **Measured and priced (§5).** `ng_queue_placement_clip_events`' stub is dead in the browser. `ng_queue_slot_unload_events` is live: about S to port, with a fixture first. |

## 1. Mechanism (functions touched, all in `tag.c`)

HEAD browser tick, inside `tagFlushPendingEnterFrame` (`tag.c:7875`):
1. `tagClipEFCollectRootPass` fired every root-tree clip-event EF immediately. Its browser `#else` arm called the plain
   dispatch.
2. Then `dispatch_attached_clip_enterframe` fired every attachMovie'd clip's children's clip-event EFs.
3. Then `actionDispatchEnterFrameHandlers` ran the method pass. Its `tagClipEFFireNewerOrEqual` /
   `tagClipEFFireRemaining` hooks were browser no-op stubs.

The result: all clip events, then all methods. Queued frame scripts ran only after the dispatcher, so test4's
`mc3 EF, mc2 EF, mc1 EF, mc3 f2, mc2 f2, mc1 f2` came out instead of Flash's per-clip `mc3 EF, mc3 f2, mc2 EF, …`.

The port (every build now runs the CI code):
- **`collect_attached_standalone`** + its `g_att_sa_d/mc` scratch (`tag.c:7321-7363`): ungated.
- **`dispatch_enterframe_clip_actions_impl`** (`tag.c:7650`): the `include_attached` gather of attached clips'
  standalone lists (`tag.c:7661-7680`), the overflow fallback's attached loop, and the s28 pend hand-off
  (`tag.c:7720`, `g_clip_ef_collect && include_attached`): all ungated.
- **The pend list:** `g_clip_ef_collect` / `g_clip_ef_pend*` / `clip_ef_pend_end`, plus `tagClipEFFireNewerOrEqual`
  (`tag.c:7611`) and `tagClipEFFireRemaining` (`tag.c:7636`). Ungated, and the browser stubs are deleted. The
  action.c hooks (`action.c:44635`, `:44674`, `:44714`, `:44801`) were already unconditional, so the w1
  `actionAQRunExecNewer` interleave now applies to clip events in the browser unchanged.
- **`tagClipEFCollectRootPass`** (`tag.c:7835`): collects in every build.
- **`dispatch_attached_clip_enterframe` is DELETED.** Its attached clips now join the root gather (CI criterion:
  `attach_standalone` dobj, deduplicated). Its other job, linking each named child MC's `display_obj` (Doodle Jump's blue
  platform "aaa" motion), moves to new browser-only **`ng_link_attached_named_children`** (`tag.c:7806`). That runs at the top of
  `tagClipEFCollectRootPass`, BEFORE the gather instead of after the dispatch. Same result: the clip action's
  by-name lookup finds the already-linked MC. The helper keeps the retired pass's exact clip filter: every tick,
  every cached MC whose `display_obj` lies outside the root DL, skipping `avm1_removed` / `pending_removal`.
- **Latent browser double-fire removed (code reading, no fixture):** the retired pass chose clips by that same
  address-range test, so it also re-dispatched the sub-list of any NESTED timeline sprite with a cached MC (its entry
  lives in its parent's sprite DL, outside the root DL). The root gather already recurses into those, so a clip-event EF
  three or more levels deep fired twice per tick in the browser. The gather now takes attached clips by the CI criterion
  (`attach_standalone`, deduplicated by dobj).
- **`advance_sprite_frames_impl`** (`tag.c:1813-1844`): the per-advanced-sprite `process_sprite_needs_init` for children
  its frame just placed is ungated.
  - Before: in the browser, a child placed by a sprite's frame ≥ 2 kept `sprite_initialized = 0` forever. The browser
    tagShowFrame's `process_sprite_needs_init` only reaches children of sprites that need init themselves.
    `gather_clip_ef_entries` requires ≥ 2, so its `onClipEvent(enterFrame)` never fired (test11 mc11/mc21/mc12; their
    `onLoad` did fire, through the placement-time LOAD queue).
  - Uses `ng_mc_for_sprite_obj` and `g_attached_advance_obj/mc`, both already ungated.
- Comment-only: the `collect_attached_standalone` header and the `tagFlushPendingEnterFrame` call site.

Kept browser-only: `upgrade_attached_clip_initialized` (`tag.c:2869`, per-tagShowFrame 1→2 promotion of attached
lists). It covers a superset of the clips the CI-criterion gather walks, so every gathered entry is promoted.

## 2. Exec-order browser A/B (child_probe, WSLg Chrome, every link `-Wl,--fatal-warnings`, zero wasm-ld warnings)

Each column is one build. A cell gives the first line differing from the golden over the golden-length prefix (`=` means the whole
prefix matches). The `WebGPU:` SwiftShader console lines are filtered. Builds: HEAD = `b004187ca` tree; port = final
code; OFF = port + `EMCC_CFLAGS=-DSWF_EXEC_ORDER_EF_OFF`.

| Oracle (golden) | HEAD | port | port + EF_OFF |
|---|---|---|---|
| gnash `action_execution_order_test11` (FP32, 32 lines) | line 6 | **line 20** (lines 1-19 `=`) | line 8 |
| gnash `action_execution_order_test4` (FP32, 26 lines) | line 12 | **line 18** (lines 1-17 `=`) | line 12 |
| `avm1_exec_order_sibling_interleave` (38) | `=` | `=` | line 5 (`tl ef` before `a f2`) |
| `avm1_attach_timeline_frame_order` (82) | `=` | `=` | `=` |
| `avm1_exec_order_attached_selfremove` (18) | `=` | `=` | `=` |

Past the golden span, HEAD and the port traces of the three fixtures are identical over their common length (the only
difference is the capture-cut last line).

test11 asOrder, the test's own self-check (FP32 `0+1+2+3+4+5+6+3+8+4+10+6+3+4+14+15+25+10+26+6+27+3+28+4+29+20+21+22+23+24+`):
- HEAD browser: `0+1+2+3+4+5+3+4+8+3+4+14+3+4+25+26+27+28+29+3+4+20+…`. The nested EFs (6/10/15) are missing,
  `mc21 onLoad` (8) is after mc1 EF, and the scripts come after all EFs.
- Port: `0+1+2+3+4+5+6+3+8+4+10+6+3+4+14+15+25+10+26+6+27+3+28+4+29+` **= FP32 through id 29**, then
  `15+10+6+3+4+20+…`: one extra EF tick at the removal frame (§3).
- enterFrameOrder: the FP32 prefix `0+2+1+3+2+1+4+3+2+1+5+4+3+2+1+` is now exact, followed by the same extra removal-tick EFs.

## 3. What still differs on the oracles: browser RemoveObject2 never finalizes (pre-existing, NOT order)

Both oracles' remaining diff starts on the frame whose tags `RemoveObject2` clips that have an unload handler:
- test4 frame 3: mc1/mc2/mc3.
- test11 frame 6: mc1/mc2.

The browser fires one more round of their EFs before the unloads, and keeps firing EFs AFTER `onUnload` on later ticks. Flash/CI fire neither.

Mechanism:
- `tagRemoveObject2` (`tag.c:16142`, the `_ro2_has_unload` branch) defers Mark + `clear_display_entry` to `queue_pending_finalize_mc`.
- In the browser that function, `run_pending_finalize_mark_only` and `run_pending_finalize` are **no-op stubs**
  (`tag.c:15643-15656`, the `#else` of the pending-finalize block opened at `tag.c:15492`).
- So a RemoveObject2'd clip with an `onUnload` / `onClipEvent(unload)` handler is never marked `pending_removal` before
  that tick's EF (`tagFlushPendingEnterFrame` → `run_pending_finalize_mark_only`, CI-only, `tag.c:7906`). Its display entry is never
  cleared either: it gets its unload event and then lives on.

The same rows were identical at HEAD, so the port neither causes nor hides this. It is the next slice (§6.1).

## 4. Native ledger (both modes)

- **Proof:** tag.c is the only file changed, and its CI preprocess is md5-identical to HEAD in both CI configs, re-checked on the commit tree
  `9dc3e514a`: NO_GRAPHICS `d8279210…`, OFFSCREEN `70d0159a…`.
- **Rows** (the s30 #3 56-row set plus the two gnash oracles): `regression/avm1_attach*`, `avm1_exec_order*`,
  `avm1_*goto*`, `avm1/goto*`, gnash `action_execution_order_test11` / `_test4`. **58 × 2 modes = 116/116 PASS**
  (`verify_output.py --diff`, run on the port tree before batch 4 landed).
- Because the object code is identical, no HEAD-mirror byte compare was needed: native output cannot move. A second
  run would only re-measure batch 4, which the coordinator prices.

## 5. Item 3: `graphics_stubs.c` Group 1, measured

| Stub (browser `#ifndef OFFSCREEN_RENDER`) | Real impl | Browser callers | Verdict / price |
|---|---|---|---|
| `ng_queue_placement_clip_events` (`graphics_stubs.c:117`) | `tag.c:13323` (CLIP_INIT/CONSTRUCT queue + drain for a clone slot) | `tag_stubs.c:2790` (`ng_cloneSprite`) and `:3166` (`ng_duplicateMovieClip`), **both inside `NO_GRAPHICS \|\| OFFSCREEN_RENDER`** | **Dead in the browser.** Deleting the stub means ungating the real one: S, zero behaviour change. It is only meaningful together with the browser clone display-list slot (`tag_stubs.c:2743` / `:3033` gates, kept off for the Snake transform-sharing bug). That is an M with its own risk, and it would also give browser clones clip-event EF/unload. |
| `ng_queue_slot_unload_events` (`graphics_stubs.c:129`) | `tag.c:13335` (pure: queues the slot's `onClipEvent(unload)` actions) | **Ungated**: `action.c:69576`, `:69635` (actionRemoveSprite / RemoveSprite opcode) and `:84502` (`removeMovieClip` method, root-slot arm) | **Live.** Browser clones have no root slot, so the lookup misses for them, as the stub's comment says. But a **timeline-placed root clip** moved to a positive depth (`swapDepths`) and then `removeMovieClip`'d IS found by `ng_findDisplayEntryByName`, and the browser drops its `onClipEvent(unload)`. CI fires it. **Price: S.** Ungate `tag.c:13335` and delete the stub. First write a Flash fixture: a timeline clip with `onClipEvent(unload)`, then `swapDepths(10)`, then `removeMovieClip()`, then trace. Grade it natively, then in child_probe. |

## 6. Next (successor = browser ladder item 5)

1. **Port the pending-finalize queue to the browser.** This is the oracle residual of §3:
   - `queue_pending_finalize_mc`, `run_pending_finalize_mark_only`, `run_pending_finalize`, `ng_depth_has_pending_finalize`
     (`tag.c:15492-15656`);
   - the CI-only mark call in `tagFlushPendingEnterFrame`;
   - the drain call sites in `action_queue.c` (`:365`, `:579`, `:656`, already unconditional, calling the stubs).
   - Oracles: test11 lines 20+ and test4 lines 18+ (both FP32). Expect both to reach full PASS in child_probe.
   - **M**, because browser games remove clips with unload handlers all the time (N particles, DJ platforms). Smoke both.
2. `ng_queue_slot_unload_events` port + fixture (§5): S.
3. Unfixtured: browser `upgrade_attached_clip_initialized` (address-range criterion) vs CI
   `ng_upgrade_attached_standalone_initialized` (tick boundary, `attach_standalone` criterion). The browser one promotes
   every out-of-root-DL dobj per tagShowFrame, so the two may promote a newly attached clip's children at different
   tick phases (unmeasured hypothesis). No oracle row seen; fixture first if a game shows an attach-tick EF.
4. Still open from s30 #2: nested `removeMovieClip` of a clip with clip-action `onUnload` (the slot UNLOAD queue is
   root-only), and stale `attach_registration` `sprite_max_depth` after a nested swapDepths grow.

## 7. Traps

- The coordinator committed batch 4 (`9dc3e514a`, touching tag.c) into the shared tree mid-session, with my edits
  dirty. The working copy kept both. `git diff HEAD` showed only my hunks, and the final browser oracles were rebuilt on
  that tree (§2 "port" column = commit tree).
- `n_drive_compare.py ours 75` runs out of time at about NF 490-505 on SwiftShader. Use `170` to reach `epvictory` (984 NF).
- `dj_alive.py` / the DJ+N build script live in earlier sessions' scratchpads, not the repo. The deploy needs the explicit
  `<repo>/docs2/examples` argument (s30 #3 trap); check the wasm mtime.
