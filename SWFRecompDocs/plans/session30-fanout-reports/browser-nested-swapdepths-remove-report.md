# s30 browser ladder #2: nested timeline child swapDepths + removeMovieClip (`browser-nested-swapdepths-remove`)

Predecessor: `browser-attach-child-early` (`3944257a4`, report §5). Brief:
`browser-nested-swapdepths-remove-prompt.md`.

## 1. Verdict

**FIXED in every build.** `regression/avm1_nested_child_swapdepths_remove` (golden = Flash Player 32,
booked expected-fail since s29 `c91637b7a`) now passes in both native modes and in the browser
(child_probe). Across the 74-row sweep × 2 native modes, nothing else moved. Doodle Jump and N still work
in the browser. N's L4 route is 984/984 NF ticks byte-identical to the Ruffle exporter trace.

## 2. Mechanism

All three swapDepths arms and removeMovieClip located a clip's display entry **by instance name in the
GLOBAL `display_list`**:
- swapDepths: `ng_updateDisplayDepth` (`tag_stubs.c:2281`) and `ng_swapDisplayDepths` (`tag_stubs.c:2577`).
- removeMovieClip: `ng_findDisplayEntryByName` + memset in the method arm (`action.c:83368`).

The global list is the root list, or a sprite's list while it is swapped in for that sprite's own frame
script. So when a sprite's timeline child was moved or removed from a ROOT script
(`_root.h.d.swapDepths(100); _root.h.d.removeMovieClip()`), the entry in `h`'s `sprite_display_list`
stayed at depth 4:
- removeMovieClip did evict the MovieClip from `child_mc_cache`.
- The next `h.d` lookup then went through `findOrCreateMovieClip` → `findDisplayEntryInParent`. That
  scans the parent's `display_obj->sprite_display_list`, found the stale entry, and conjured a fresh
  clip (`typeof` = movieclip).
- The getDepth rows still read 100, because `mc->depth` was updated even though the entry was not.

A latent second bug came from the same lookup: a nested `d.removeMovieClip()` / `d.swapDepths(n)` would
clear or move an unrelated **root** clip that happened to be named `d`.

Fix (new, ungated, so it applies to every build):
- `tag_stubs.c:2456` **`ng_nestedDLSlotOf(mc, &idx)`** returns the owner (`mc->parent->display_obj`) and
  the slot index of a non-root clip's entry in its parent's own list. It finds the slot from
  `mc->display_obj` when that points inside the buffer, else by name at `mc->depth + 16384`.
- It returns NULL, which keeps the old by-name path, in four cases:
  - the parent is root, or it has no list of its own;
  - the entry is not found;
  - **the parent's list is the one currently swapped into `display_list`**: a sprite's own frame script
    already worked through the global by-name path, so it is left alone.
- `tag_stubs.c:2499` **`ng_nestedUpdateDisplayDepth`** is the move/swap with `ng_updateDisplayDepth`'s
  slot semantics:
  - placed_at_frame / place_gen stay with the depth, and both slots get `depth_swapped`;
  - the list grows via `ng_spriteDLRealloc`, which rebases aliases;
  - the displaced sibling's `mc->depth` is updated;
  - every `display_obj` aimed at either slot is retargeted;
  - `sprite_max_depth` is grown or shrunk;
  - depths at or above `AVM_CLONE_SLOT_CAP` are left alone, like the root path.
- `tag_stubs.c:2563` **`ng_nestedRemoveDisplayEntry`** clears the slot and shrinks max. It leaves the
  entry's child list unreferenced, the same as the root path's memset.
- `action.c` call sites:
  - **numeric swapDepths** (`:81843`): runs the nested move BEFORE `mc->depth` changes, and skips
    `ng_updateDisplayDepth` when the move was handled;
  - **MovieClip-arg swapDepths** (`:81731`) and **string-arg swapDepths** (`:81802`): take the nested
    swap when both clips have a nested slot under the same parent;
  - **removeMovieClip** (`:83368`): the global by-name slot clear (and its slot UNLOAD queue) only runs
    when the nested clear did not apply.

Functions touched: `ng_nestedDLSlotOf`, `nested_dl_retarget`, `ng_nestedUpdateDisplayDepth`,
`ng_nestedRemoveDisplayEntry` (new, `tag_stubs.c`, + decls in `tag.h`); the swapDepths and
removeMovieClip method arms in `action.c` (`actionCallMethod`'s MovieClip method dispatch). There are
**no frame-loop edits and no `tag.c` / `swf.c` / `swf_core.c` / `action_queue.c` edits**, so nothing
overlaps `w1-exec-order`.

## 3. Before / after

| build | before (HEAD `6481e7c42`) | after |
|---|---|---|
| no-graphics native | FAIL: lines 3, 7 `after remove=movieclip` | PASS |
| graphics native | FAIL: same 2 lines | PASS |
| browser (child_probe, `-Wl,--fatal-warnings`, 0 link warnings) | `h d after remove=movieclip`, `t d after remove=movieclip` | all 8 lines = golden (only the WebGPU console-noise lines differ, in both builds) |

The baseline was a mirror root: HEAD `SWFModernRuntime` via `git archive`, everything else symlinked.
The same mirror was used for the child_probe baseline.

## 4. Sweep ledger

- **Row set (74):** every test dir in `avm1`, `from_gnash`, `from_shumway` and `regression` whose (decompressed)
  SWF contains the string `swapDepths` or `removeMovieClip`. That is 18 `swapDepths`-only, 12 both and 44
  `removeMovieClip`-only; `from_shumway` has none.
- **Why the set is complete:** the change is reachable only through those two MovieClip method names,
  and a method call carries its name as a literal string in the SWF. The global `removeMovieClip(target)`
  opcode (`actionRemoveSprite`) is untouched.
- **Method:** each row ran `verify_output.py --diff` in both modes, on the baseline mirror and on the
  working tree. Captures were compared byte for byte, with whitespace and timing lines filtered out.
- **Why that compares actual output:** none of the 74 rows has `[approximations]`. So the diff capture
  identifies the actual output exactly, for the 15 ruffle_matched rows too.

| mode | before | after | moved |
|---|---|---|---|
| no-graphics | 73 effective pass, 1 fail | 74 / 0 | only the fixture (fail→pass) |
| graphics | 73 / 1 | 74 / 0 | only the fixture (fail→pass) |

No CI was dispatched (per brief). CI should confirm: the fixture flips, and nothing else moves. The
MovieClip-arg and string-arg nested swap arms are exercised by sweep rows but have no fixture of their
own (see §6).

## 5. Games (browser, WSLg Chrome = functional only)

- **Doodle Jump** (`rebuild_docs2_demos.sh flasharchive --only Doodle_Jump --fast`; `dj_alive.py
  click`): 3/3 runs reached root frame 1, the page answered every eval, and rAF climbed.
- **N** (`N_drive`, `EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000 build_test.sh flasharchive/N_drive wasm
  --graphics` + `deploy_example.sh … --no-index --graphics`):
  - 2 runs of `n_drive_compare.py ours`, 1043 lines each, identical apart from timestamps.
  - The route reaches `epvictory`, with no PAGEERROR.
  - 984/984 NF ticks are byte-identical to the exporter trace. That includes `t=297` `h=` this time,
    which matches the predecessor's run-1 value and so is still the known run-to-run variable tick.
  - The first 413 lines equal the predecessor's trace, apart from that tick and the shot timestamps.

## 6. Findings for others

- **Trap: `deploy_example.sh` without `--no-index` regenerates `docs2/catalog.json` (+79 lines) and
  drops `docs2/opcode-index.json`.** Both were reverted here. Use `--no-index` for probe deploys.
- **Trap: `build_test.sh … wasm` needs `emsdk_env.sh` sourced** ("Emscripten (emcc) not found!").
  Without it, the following `deploy_example.sh` silently redeploys the PREVIOUS build.
- **Open, unfixtured (Flash golden needed):**
  - nested MovieClip-arg / string-arg `swapDepths` between two timeline siblings of a non-root sprite
    (now takes the nested swap);
  - a nested `removeMovieClip` of a clip whose entry has clip-action `onUnload` (the slot UNLOAD queue
    is root-only, before and after);
  - CI non-root attach registration aliases (`attach_registration`, `tag_stubs.c:838`) get a stale
    `sprite_max_depth` if the attached clip's own list grows by a nested swapDepths.

## 7. Next (successor = browser ladder item 3)

**The timeline-sprite self-goto port (s28 `browser-root-goto` report §5a) + the dead browser
`pending_remove` consume code.**
- The browser calls `ng_apply_pending_sprite_self_gotos` for ATTACHED roots only (s28
  `browser-attached-goto`). The timeline-sprite half was measured in s28 and NOT landed: on `aa595bbc6`
  it dropped nested `_root.c.n` from enumeration. The candidate commits are listed in §5a and were never
  bisected.
- Oracle: the `tools/divergence/gates/nested_sprite_inframe_goto` gate via child_probe (recipe in s28
  §6). First re-measure on the current HEAD: the drop may already be gone after s29/s30 landings.
- The dead `pending_remove` consume/finalize code in the browser arms (`tag.c:1146`, `tag.c:2643`,
  `tag_stubs.c:1556-1579`) is the cleanup half. It is in `tag.c`, so coordinate with `w1-exec-order`'s
  landing before you touch it.
- Grade any new fixture natively in both modes first (s27 rule).
