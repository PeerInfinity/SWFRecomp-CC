# w2-removed-scope: report (session 21, wave 2)

**New files:** none. The patch only modifies tracked files, so `git apply` + `git add -u` is enough.
Deliverables: `w2-removed-scope.patch` and this report.
Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a13d0a46a8c6887e4`. It was rebased onto
master `0fd566061`, which includes `7c91e4727`, and every result below was re-run on the rebased tree.

## Verdict: GO, +1 trace (`avm1/removed_clip_function_scope`), 0 regressions

| test | CI baseline (graphics, results @ `0341c033a`) | after (graphics, rebased worktree) |
|---|---|---|
| `avm1/removed_clip_function_scope` | output_mismatch 8/12 | **pass 12/12** (no-graphics: pass) |

- **Canary: 115 tests in graphics mode, rebased tree.** 114 rows are unchanged against baseline. The
  other two rows moved, and both are master drift:
  - `from_gnash/misc-ming.all/NetStream-SquareTest` went to ruffle_matched because of `9930c8a23`.
  - `from_gnash/actionscript.all/MovieClip-v5` went from 350 to 352/363. The A-leg (rebased master
    without my patch) also gives 352/363, so this comes from `7c91e4727`.
- **Regression suite:** all 97 tests pass in graphics mode, unchanged vs baseline.
- **No-graphics mode** passes on the headline, `removed_target_clip_scope`,
  `string_paths_variable_scopes`, `removed_base_clip_tell_target`, `swf5_no_closure` and
  `swf5_to_6_cross_call`. `tag_stubs.c` is compiled in both modes, so **CI should run both modes.**
- No disposition-doc or ignore-list entries exist for the headline test, and it is not `known_failure`.

## 1. Mechanism: two independent bugs, and the flip needs both fixes

### (a) Call-path rule: upstream `4b7edd6ad`

**What Ruffle does.** Functions are handled in `Avm1Function::exec` (`function.rs`) and
`Scope::resolve` (`scope.rs`).
- A SWF6+ closure's base clip is `self.base_clip.resolve_reference()`: the defining clip, or the clip
  now at its path.
- If neither exists, the base clip is **`this_do`**. That is `this` when `this` is a display object
  (even a removed one), and otherwise the caller's `target_clip_or_root()`.
- Since `4b7edd6ad`, a removed clip in the scope chain is replaced by that same target during lookup.
  The old "if a removed clip has the name, read root instead" fallback is gone.

**What we did before.** Most call paths set `g_current_context = func->base_clip` directly. There were
about 20 raw sites, plus the `invokeFunctionValue` core and `enterClosureFrame`. So a removed defining
clip was entered as-is, and `GetVariable`'s dead-context arm then read the **root timeline first and
the removed clip's own props second**. The paths also did not agree with each other:
- The CallMethod MOVIECLIP arms (`CF_CTX_MC_FALLBACK` → receiver) and the object arms
  (`CF_CTX_LIVE` → keep the caller) already approximated `this_do`.
- CallFunction (`CF_CTX`), Function.call/apply (core `INV_BASE_CLIP`), the event dispatchers and the
  callbacks entered the dead clip.

That is why `readAll.call(undefined)` printed `root child root …`: root vars, then the dead clip's
`childOnly`.

**Fix.** A new `actionClosureBaseClip(app_context, base_clip, this_mc)` in `action.c`, declared in
`action_internal.h`, returns, in order:
1. The base clip when it is live. This is untouched, so behaviour is identical for every live clip.
2. Otherwise `reResolveDeadBaseClip`.
3. Otherwise `this_mc`.
4. Otherwise the caller's `g_current_context`.

Every base-clip entry now goes through it:
- the core's two `INV_BASE_CLIP` arms (this = the MOVIECLIP `this_var`)
- `enterClosureFrame` `CF_CTX`. `actionCallFunction` now passes the scope-chain MOVIECLIP it found
  the callee on as the receiver (Ruffle `Callable(this, fn)`).
- the enterFrame dispatchers (mc / root), `actionDispatchMCOnLoad` / `actionDispatchMCOnConstruct` (mc)
- EI `callInternalInterface`, `objectCallValueOf` / `objectCallToString`, LoadVars / Sound callbacks
- the watch callback and addProperty setter in SetMember, the initObject setter (mc)
- the function-object method arms in CallMethod (`own_func`, `mfunc`), and the TextSnapshot-style ctor
  (`ts_ctor`)
- `call_function_with_this`
- `timer.c` function-form timers
- `registered_class.c` registered-class ctors (this = mc)

No raw `g_current_context = …->base_clip` site is left.

### (b) Ghost re-resolution: `ng_updateDisplayDepth` strands the root sentinel (`tag_stubs.c`)

`child.swapDepths(1000)` grows the root `display_list`: `calloc` plus `memcpy`, and the old buffer is
leaked, not freed. The root sentinel (`root_movieclip.display_obj`, `ng_shared.c`) keeps pointing at
the OLD buffer, which still holds `child` at depth 1.

After `child.removeMovieClip()`, `resolveSlashPathToMC("/child")` misses in the new list. It then falls
back to the sentinel's stale list and conjures a fresh `child` MC at depth -16383. The debugging trace
showed `found_entry = old_dl[1]` with `display_list` equal to the new buffer.

So `reResolveDeadBaseClip` "re-resolved" the removed defining clip to that ghost, and every
after-removal call printed `global global undefined undefined global`. The fix calls
`ng_sync_root_display_obj()` after the grow when the sentinel mirrored the old buffer. This is the
same stranded-holder bug class as memory `sprite-dl-realloc-rebase`, at a root-DL grow site that had
not been migrated.

**Why both are needed.**
- With (b) only, CallFunction still enters the dead clip, and the root-then-own-props fallback prints
  `root child …`.
- With (a) only, the ghost is "live", so `actionClosureBaseClip` returns it.

## 2. Refutation: "unify GetVariable's removed-clip lookup onto the new rule"

The brief said our lookup "still uses the old rule". My first cut also deleted `GetVariable`'s
`depth == INT_MIN` root fallback, so that a removed current target resolved like a live one. That
**regressed two passing tests**:
- `avm1/removed_target_clip_scope`: 35 → 34
- `avm1/string_paths_variable_scopes`: 5 → 4

The reason is that the dead-context arm is no longer reached by closures. It is reached by code
running **on** a clip that was removed mid-script, for example a frame script after
`removeMovieClip(this)`. For that case Ruffle's `action_remove_sprite` resets the target to root and
pushes root's Target scope (`activation.rs:1953-1967`), and the root fallback is the right emulation.
The fallback is therefore kept, and its comment is rewritten to say what it now models.

The upstream `scope.rs` change is fully expressed at call entry: we never enter a removed defining
clip unless it is `this` itself, which is what Ruffle does too.

## 3. Pricing and hit coverage

In an instrumented pre-rebase run of the same 115-test canary (markers since removed), the
removed-base branch (`base_this` / `base_caller`) fired **only in the headline test**. The root-sentinel
sync fired 8 times across the canary, with no status changes. So the change is narrow in the corpus:
+1, with no other movers.

## 4. Interaction with master `7c91e4727` (coordinator note)

**(1) onUnload.** `aq_dispatch_unload` now switches context only for SWF5 handlers.
`invokeUnloadHandler` has no `INV_BASE_CLIP`, so SWF6+ onUnload handlers do not go through
`actionClosureBaseClip`, and **there is no textual or behavioural overlap**. That path keeps the
drain's ambient context rather than Ruffle's `this_do`, but I left it alone (see lead 3).

**(2) GetProperty child-before-var target lookup.** Unrelated code. It merged cleanly (`git apply
--3way`, all hunks applied cleanly). `MovieClip-v5` is identical with and without my patch.

## 5. Tests run (all graphics unless noted; `SWFRECOMP_COMPILE_TIMEOUT=2400`)

- Headline, before: MISMATCH 8/12, graphics, pre-patch. After: PASS in both graphics and no-graphics.
- **Canary (115):**
  - the 80 avm1 tests whose SWF uses `removeMovieClip`, `unloadMovie` or `swapDepths`, or whose name
    matches closure, scope, remov, unload, base_clip, target, swf5_ or this_. This includes
    `removed_base_clip_tell_target`, `removed_clip_halts_script`, `removed_target_clip_scope`,
    `function_base_clip*`, `swf5_no_closure`, `swf5_to_6_cross_call`, all `string_paths_*`,
    `this_*`, `target_clip_*`, `tell_target*`, `unload*`, `set_target_2_*` and
    `virtual_property_recursion_scope`
  - 28 from_gnash tests (MovieClip-v5, AsBroadcaster, Sound, displaylist_depths, loop_test*,
    movieclip_destruction_*, …)
  - 6 regression tests and 1 visual test
  - Full table: scratchpad `w2-removed-scope/cmp_v3.txt`.
- **Regression suite, all 97:** **97/97 pass, 0 changed vs baseline** (scratchpad `w2-removed-scope/cmp_reg.txt`).

## 6. New unclaimed leads

1. **SetVariable on a removed scope clip.** Ruffle's `Scope::set` skips a removed Target scope and
   ends at the global scope, so an undeclared assignment inside a closure whose clip was removed goes
   to `_global`. We write to whatever context we entered, which after this patch is `this_do`, and
   before it was the dead clip. No corpus test covers this. Build a fixture with the new exporter if
   it gets funded.
2. **Removal by method vs by action.** Only the RemoveSprite **action** (`removeMovieClip(this)`)
   resets Ruffle's target to root. `this.removeMovieClip()` (a method call) does not, so later bare
   names still resolve on the removed clip through the new substitution. Our dead-context fallback
   treats both forms as "root first". Possibly latent in some unload tests.
3. **SWF6+ onUnload handlers (`7c91e4727`)** run in the drain's ambient context, not in Ruffle's
   base clip. Ruffle's base clip is the defining clip if it is alive, else `this_do`, and `this_do`
   is the unloading clip. The difference shows only when a handler reads a bare name that is defined
   on the unloading clip but not on root.
4. **`actionBaseClipRemoved` (`continue_if_base_clip_exists`)** still checks
   `g_current_executing_func->base_clip->avm1_removed`. In Ruffle the callee's base clip is
   `this_do`, which is live, so a closure whose defining clip was removed should **not** halt after
   inner calls. We would halt. Not exercised by the corpus. Fixing it needs a per-call
   effective-base-clip record.
5. **The root-DL grow in `ng_updateDisplayDepth` still leaks the old buffer** and does not rebase
   `MovieClip.display_obj` pointers into it (Class A). Other root children keep reading stale entry
   copies after any `swapDepths` to depth ≥ ~−15360. The proper fix is `ng_spriteDLRealloc` (rebase
   + free), the way the clone path was migrated. I held back because freeing turns the stale
   C-stack `saved_dl` restores in the sprite brackets into use-after-free.
6. **With-scopes on removed clips.** In `with(removedClip){…}` Ruffle substitutes the target for the
   removed With scope as well. `scope_mc[i]` lookups on a removed clip are untouched here.
