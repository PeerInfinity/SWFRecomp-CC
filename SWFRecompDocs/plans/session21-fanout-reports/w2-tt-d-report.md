# w2-tt-d: MovieClip-v6 + -v7, the four mechanisms (session 21, wave 2)

**New files:** none. The patch touches 1 file, `SWFModernRuntime/src/actionmodern/action.c`.

**Patch:** `SWFRecompDocs/plans/session21-fanout-reports/w2-tt-d.patch`. It is built on master
`5fa5fa783` and `git apply --check`s clean on current main. The worktree is
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-tt-d`, branch `s21-w2-tt-d`, and nothing is
committed.

## Verdict: +2 effective, all 4 mechanisms landed before the hour-2 checkpoint, 0 regressions

| test | before | after (`--mode=graphics`) |
|---|---|---|
| `from_gnash/actionscript.all/MovieClip-v6` | output_mismatch, 14 ours-only | **RUFFLE_MATCHED** (0 ours-only; diff 35 → 20) |
| `from_gnash/actionscript.all/MovieClip-v7` | output_mismatch, 14 ours-only | **RUFFLE_MATCHED** (0 ours-only) |
| `from_gnash/actionscript.all/MovieClip-v8` (NO-GO, must not regress) | output_mismatch, 41 ours-only | output_mismatch, **27 ours-only**. The only changes are the same 5 lines turning PASSED plus the onUnload pair, so it is strictly closer |
| `from_gnash/actionscript.all/MovieClip-v5` (canary, KF, RM) | ruffle_matched, 13 diff lines | ruffle_matched, **11 diff lines**. 2097/2100 now PASS, as in Flash |

**Rule 3:** all four MovieClip rows are `known_failure`. Every changed line is Flash's `output.txt`
line, and no row moves `pass → ruffle_matched`.

**CI:** this is AVM1 runtime only, and `action.c` is shared runtime. Run `mode=graphics`; the
default `categories=all` is enough.

## The four mechanisms, each measured on a hand-assembled SWF against the Ruffle exporter oracle

1. **Descendant `onUnload` never produced output.** This is the 2-line block that also realigned
   the `onData` tail (MovieClip.as:660).
   - Instrumentation showed the handler *was* queued and dispatched, **twice**, but printed
     nothing. There were two bugs, both in `aq_dispatch_unload` / `queueOnUnload` (~action.c:25900):
   - **Scope.** Dispatch did `actionSetCurrentContext(pu->mc)`, so the handler's bare names
     (Dejagnu `note`/`pass_check`) resolved against the unloading child and were not found.
     - Ruffle `function.rs`: in SWF6+ a function is a *closure*, and its base clip is the
       *defining* clip.
     - `mc_call_as2_handler_ng` already never switches context.
     - Fix: switch context only for a SWF<6 function (the function's own `swf_version`, falling
       back to `g_swf_version`).
     - `invokeUnloadHandler` gains `INV_EVENT_THIS_MC`, because a type-2 handler's
       `preload_this` had been reading `this` off the switched context.
     - The other 8 `invokeUnloadHandler` callers pass `this_mc = NULL`, so they are unaffected.
   - **Double fire.** `hardref3.removeMovieClip()` queues the child's onUnload, and then
     `removeMovieClip(softref3child)` queued it again. Flash and Ruffle fire it once. Fix: a small
     pending-set of `(func, mc)` pairs, which is skipped on re-queue and cleared on dispatch.
2. **`arguments.caller` from a builtin** (MovieClip.as:2097). The line looked like a caller bug, but
   it was two bugs:
   - **(a)** A Number/Boolean *primitive* receiver dispatched only `toString`/`valueOf`/
     `hasOwnProperty`, so every other method was `undefined`. A user
     `Number.prototype.toLowerCase` never ran: `(5).toLowerCase()` returned undefined.
     - New `primNumBoolCallProtoMethod`, placed just above `actionCallMethod`. It auto-boxes and
       dispatches through the wrapper prototype.
     - It is a line-for-line mirror of the existing String arm's user-override dispatch,
       including the same builtin-placeholder exclusions.
     - It is used only in the numeric/boolean branch's final `else`.
   - **(b)** `builtin_mc_meth` publishes its own `ASFunction` as `g_current_executing_func` around
     the `toLowerCase` call, so the callee's `arguments.caller` is `_root.meth`.
   - Side effect: 2100 `ret == 2` now PASSes as well.
3. **`propinspect == 0`** (MovieClip.as:2191). It needed full-test instrumentation: every
   standalone probe passed.
   - Cause: `GetProperty('mc', _x)` resolved to `_root`.
   - In `resolveSlashPathToMC` (NO_GRAPHICS/OFFSCREEN branch), the script-created-child fallback
     read the name from `dynamic_props`. Root dprops is a mixed store (SetVariable mirrors user
     vars into it), and `mc = _root` (MovieClip.as:2143) shadowed the display child `mc`.
   - Ruffle `resolve_target_path` does display children **first**, then properties.
   - Fix: before the dprops fallback, scan `child_mc_cache` for a live child of `mc` with a
     matching name (lowest depth). This is limited to script-created children
     (`display_obj == NULL`); timeline children were already found by the display-list search.
     The browser-graphics branch already did exactly this cache scan, so this also closes a mode
     asymmetry.
4. **`Boolean.prototype.toString` on a non-Boolean `this`** (MovieClip.as:2590) returns
   `undefined`, not `"[object Object]"`. This matches Ruffle `boolean.rs`, which returns Undefined
   for a non-Bool native.
   - New `builtin_bool_proto_toString`: it returns undefined when there is no boxed primitive,
     otherwise it delegates to `builtin_prim_wrapper_toString`.
   - It is installed through `installBoolProtoToString` at all 3 Boolean.prototype creation
     sites: primary `g_ctors[4]`, the secondary version-group loop `i == 2`, and
     `g_boolean_constructor`.
   - The Number/String prototypes keep the shared function.

## Sibling areas

- **w2-removed-scope** (scope-chain resolution at ~45125-45220): **not touched**. My edits are at
  ~8100 (Boolean), ~16390 (meth), ~21420 (`resolveSlashPathToMC`), ~24380 (`invokeUnloadHandler`),
  ~25900 (unload queue) and ~68200 / ~75480 (primitive dispatch).
  - Semantic neighbour: mechanism 1 changes the scope an onUnload handler runs in.
  - `avm1/removed_clip_function_scope`, that sibling's target, is **byte-identical** before and
    after this patch.
- **w2-mixed** (TextField maxscroll / link hit test / asfunction): not touched.

## Canaries

All sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--recompile` on first use in the worktree. The
3 headlines ran in graphics mode. The 55 canaries ran in no-graphics mode, given the total mode
parity of record and the load on the box.

**All 55 statuses are unchanged from `results_graphics`.** The 11 non-`pass` rows were A/B'd on
**raw output** against a baseline made by `git apply -R` of the patch, same worktree and same
session. 10 are byte-identical. `MovieClip-v5` differs only by the 2 lines that became PASSED (see
the table above).

- **avm1 (27 rows):**
  - `arguments`, `function_base_clip_removed`, `is_prototype_of`,
    `load_cancel_via_removemovieclip`, `movieclip_in_removed_button`,
    `movieclip_prototype_extension`, `object_prototypes`, `prototype_enumerate`,
    `prototype_properties`
  - `remove_movie_clip`, `removed_base_clip_tell_target`, `removed_clip_halts_script`,
    `removed_target_clip_scope`, `string_paths_unload`, `target_clip_removed`, `target_path`
  - `tell_target`, `tell_target_invalid`, `tell_target_invalid_swf6`
  - `unload`, `unload_clip_event`, `unload_nested_child`, `unloadmovie`
  - `target_paths/swf4`: pass
  - Unchanged and byte-identical: `target_paths/swf5`, `/swf6` (RM); `removed_clip_function_scope`
    (MM)
- **gnash actionscript.all (20 rows):**
  - `Boolean-v5..v8`: pass
  - `Number-v6..v8`: pass; `Number-v5`: RM, byte-identical
  - `Function-v6..v8`: pass; `Function-v5`: RM, byte-identical
  - `Object-v6`: RM, byte-identical
  - `MovieClip-v5`: RM, strictly better
  - `getvariable-v6`: pass
  - `targetPath-v6..v8`: pass
  - `with-v6`: RM, byte-identical
  - `delete-v6`: pass
- **gnash misc-swfc (5 rows):**
  - `movieclip_destruction_test1`: RM, byte-identical
  - `_test2`: pass
  - `_test3`, `_test4`: MM, byte-identical
  - `soft_reference_test1`: pass
- **regression (3 rows):** `onunload_type1_args`, `onunload_type1_local_frame`,
  `string_prim_method_type1_args`: pass.

**Not added:** a new `regression/` fixture. Every behaviour is graded by the corpus rows above. The
hand-assembled probe SWFs and their Ruffle-exporter outputs are in the scratchpad
(`…/w1-trace-tail/probe*/`); promote one if the coordinator wants a guard.

## New unclaimed leads

1. **`R.mc = R; createEmptyMovieClip("mc")` then `R.mc`** (SetMember, not SetVariable).
   - Ruffle keeps the property (`_level0`); we return the child. GetMember must prefer own
     properties over children, the reverse of target paths.
   - It is outside every corpus ours-only set today. Probe:
     `…/w1-trace-tail/probe/Probe.as` line "m3".
2. **Deferred-removed child depth.** Ruffle reports `hardref3child.getDepth()` as `-32770` after
   the parent is removed; we report `1`. gnash's Flash oracle (MovieClip.as:715) says **1**, so we
   match Flash here. This is a Ruffle-vs-Flash note, not a bug.
3. **`dc(Boolean)` via `super()` on a MovieClip receiver** does not leave a boxed `false` on the
   clip. MovieClip.as:2596 wants `"false"`, and we now read `undefined` (previously
   `"[object Object]"`). Both are wrong, and the line is inside Ruffle's diff set, so it is free for
   promotion.
4. **Other builtins that call back into script** (sort comparators, `Array.prototype` callbacks,
   `watch` handlers) still leave `arguments.caller` as the enclosing user function. Only `meth` is
   fixed here. The general rule is Ruffle's "caller = previous callee".
