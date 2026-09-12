# w2-avm1-sort — G1/G2/G3 implementation report

**Deliverables (three patches, apply in this order; all touch only
`SWFModernRuntime/src/actionmodern/action.c`, no new files):**

| # | patch | lines | scope |
|---|---|---|---|
| 1 | `w2-avm1-sort-1-addproperty.patch` | 26 | lazy `func->own_props` before a builtin dispatched on a FUNCTION receiver |
| 2 | `w2-avm1-sort-2-comparator.patch` | 43 | AVM1 sort comparator: type-2 arm gets the local frame + `this` bind |
| 3 | `w2-avm1-sort-3-movieclip-tail.patch` | 395 | `MovieClip.loadVariables` method + deferred `onData` + `_root` string target |

Verified: `git apply --check` of 1→2→3 from pristine `e36bca73e` reproduces the tree byte-for-byte
(md5 match). Runtime-only — the recompiler is untouched, so no `--recompile` is needed to land them.

---

## 1. Verdicts and priced flips

| lead | verdict | measured | note |
|---|---|---|---|
| **G1** `avm1/new_class_prototype_getter` | **DONE, +1 pass** | `output_mismatch 1/6 (act 5)` → **`pass 6/6`** | exactly the wave-1 mechanism |
| **G2** `from_gnash/…/array-v7`, `-v8` | **partial: +26 matching lines each, NO flip** | `604/654` → **`630/654`** (both) | M2 cleared, exactly the 26 lines wave-1 priced. M1/M3/M4 (6 lines) survive |
| **G2** `array-v6` | **NO CHANGE, as predicted** | `623/644` → `623/644` | Ming emits function1 for SWF6; its 4 lines are M1/M3/M4 only |
| **G3** `from_gnash/…/MovieClip-v6/-v7/-v8` | **partial: whole `vars.txt`/`onData` tail now runs, NO flip** | act `921→935`, `954→968`, `1072→1086` (expected 936/969/1087) | `matching_lines` flat — see §4b, one 2-line mechanism gates the alignment |
| **G3 bonus** `avm1/loadvariables_method` | **DONE, +1 pass** (IGN row, **prune it**) | `output_mismatch 0/7 (act 0)` → **`pass 7/7`** | `ruffle-tests/ignored_tests.txt:95`; its own header says "Prune on `pass`" |

**Net effective: +2 pass** (`new_class_prototype_getter`, `loadvariables_method`), plus 26+26+14+14+14
non-flipping matched/emitted lines.

**The brief's `+6` is not reached and could not be**, for a reason wave-1 already flagged and I confirm:
G2 and G3 are each *one mechanism out of four* on their rows, and `ruffle_matched` is all-or-nothing
on the ours-only index set. See §4 for the exact residue on each.

**No regressions anywhere.** 59/59 AVM1 `regression` tests, all 25 unchanged avm1 canaries, `array-v5`
(IGN, must-not-move) and `Function-v6/-v7/-v8` are byte-identical before and after.

---

## 2. Patch 1 — G1, `addProperty` on a fresh function

`actionCallMethod`'s FUNCTION-receiver arm calls a builtin as
`mfunc->advanced_func(..., (void*) func->own_props)`. Every `Object.prototype` builtin bails on
`this_obj == NULL`, and `var f = function(){}` has `own_props == NULL` until something writes a
property on it — so `addProperty` returned `false` and installed nothing. Three lines mint the bag
lazily, following the existing `Function.prototype.call/apply` thisArg precedent verbatim.

**Blast radius is wider than the one test**: `watch`, `unwatch`, `hasOwnProperty` and
`isPropertyEnumerable` took the same NULL and silently no-opped on a fresh function. Canaries
`avm1/watch`, `watch_virtual_property`, `object_properties`, `object_prototypes`, `object_function`,
`prototype_properties`, `is_prototype_of`, `function_as_function`, `function_base_clip` — all
unchanged (they already passed and still do), so nothing depended on the no-op.

**Function:** `actionCallMethod` (FUNCTION-receiver arm, type-2 sub-arm).

---

## 3. Patch 2 — G2, the sort-comparator calling convention

`_invoke_sort_comparator` gave the type-2 arm `INV_CAPTURED_SCOPE` only. Both arms now share
`INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BASE_CLIP | INV_BIND_THIS` with `this = undefined`
(Flash/Ruffle call a comparator as a plain function). The if/else is collapsed: the split *was* the
bug, not a semantic.

I re-verified the wave-1 claim in the tree rather than taking it: `array-v7/RecompiledScripts/
script_defs.c:1809 func2_randomComparator_19` binds its parameters with literal
`setVariableByName("a", &args[0])` / `("b", &args[1])`, and `array-v6` emits `DefineFunction`
(function1) for the same source. So v7/v8 were writing comparator parameters onto the root timeline
and v6 was not — exactly the observed split.

`&undef_this` does **not** change the ABI `this` pointer for a type-2 callee:
`invokeFunctionValue` derives `this_ptr` only from OBJECT/MOVIECLIP/ARRAY/FUNCTION tags, so an
UNDEFINED `this_var` yields the same `NULL` the old `this_var = NULL` did. The only type-2 change is
the fresh local frame plus the by-name `this` bind.

**Result:** array-v7/-v8 `604/654 → 630/654`. **+26 lines each, exactly the M2 bill**, zero over- or
under-shoot.

### Blast-radius sweep (mandatory, since every AVM1 array sort goes through this)
- `regression/sort_comparator_captured_scope`, `regression/sort_comparator_type1_args` — the two
  tests the helper's own comment names: **pass, unchanged**.
- All 59 non-AVM2 `regression` tests: **59/59 pass**, unchanged (see §6 for why the AVM2 half was
  skipped).
- `avm1/array_sort`, `array_sort_random` (443 lines), `array_call_method`, `array_concat`,
  `array_shift`, `array_slice`, `array_splice`, `array_reverse`, `array_properties`,
  `array_enumerate`, `array_prototyping`, `array_constructor`, `array_length`, `array_trivial`,
  `array_unshift`, `init_array_invalid`, `global_array` — unchanged.
- `from_gnash/actionscript.all/array-v5` (IGN, line-tracked): `551/560` → `551/560`, **unmoved**.
- `from_gnash/actionscript.all/Function-v6/-v7/-v8`: pass, unchanged.
- `from_shumway/avm1/array` + a 16-test shumway AVM1 sample: see §6.

**Function:** `_invoke_sort_comparator`.

### What patch 2 does NOT fix (honest pricing)
The 6 surviving ours-only lines on v7/v8 (and all 4 on v6) are wave-1's M1/M3/M4, and the
"they are probably the same variable corruption" hypothesis is now **refuted by measurement**: the
comparator fix cleared 26 and left M1/M3/M4 untouched on every version. They are three genuinely
separate mechanisms:
- M1 — `gaparray.hasOwnProperty('4'/'16'/'2')` false on explicitly-set sparse indices;
- M3 — a sort with a bogus comparator *empties* `trysortarray` (4 → 0) where Flash leaves it;
- M4 — `ar.__proto__ = 8` ⇒ `typeof` must be `"number"`.

Wave-1 could not reproduce M1 or M4 in isolation; that still stands. **`array-v6` is the cheapest
flip in the family (4 lines, 3 mechanisms, no comparator work) and is now completely independent of
this patch.**

---

## 4. Patch 3 — G3, the `loadVariables` / `onData` tail

Wave-1 named this as "our run ends before the `loadVariables`/`onData` + `onUnload` tail". That is
right, and the cause turned out to be **four** separate defects, not one:

**(a) `MovieClip.loadVariables` had no implementation at all.** It is a registered *name* in
`g_mc_method_funcs` (so `typeof mc.loadVariables == "function"`) with no branch in the MOVIECLIP
method dispatch where `loadMovie`/`unloadMovie` live — calling it was a silent no-op. Added, mirroring
Ruffle `globals/movie_clip.rs::load_variables`: `object_into_request` (the clip's own variables become
the GET query or the POST body) + `loader.rs::load_form_into_object`. The load body is factored out of
the existing ActionGetURL2 tag-form branch into `avm1LoadFormIntoMC`, so the two forms now share one
implementation (and one charset policy).

**(b) `onData` was never fired by either form.** Added a small deferred queue drained from
`processLoadVarsLoads`. That host matters: the obvious hook, `actionFirePendingDirectLoads`, is called
by **both** frame loops behind `while (g_pending_direct_load_count > 0 …)`, so a second queue hung off
it would have starved. `processLoadVarsLoads` is the existing "fire the form loader's callbacks"
hook, is called unconditionally by `libswf/swf_core.c:~1476` and `libswf/swf.c:~1302`, and needs **no
edit to either frame loop** — which is also what keeps NO_GRAPHICS/graphics parity free.

**(c) The handler got no `arguments`.** `MovieClip.as:2207` asserts `arguments.length == 0`; Ruffle
dispatches `ActionType::Method{args: vec![]}`. A type-1 handler has no `arguments` unless the caller
binds one, so the invoke uses `INV_LOCAL_SCOPE | INV_ACT_ARGUMENTS`. The frame carries only
`this`/`arguments`, and `actionSetVariable` only writes to a scope frame that *already* carries the
name, so the handler's own `dataLoaded++` still lands on the timeline (verified: the second round
traces `dataLoaded: 1`).

**(d) `loadVariables("vars.txt", _root)` was silently dropped.** That form compiles to a GetURL2 with
`loadTarget=1` and the **string** `"_root"` on the stack, not a resolved MovieClip. The target
resolver handled `_levelN`, `this` and `""`, then fell through to a `child_mc_cache` *name* scan,
which never matches `_root`. Added the `_root` case. Without this the gnash handler's second load
never happened and the tail stopped after one `onData`.

### 4a. Measured effect
| test | before | after | expected |
|---|---|---|---|
| `avm1/loadvariables_method` | `output_mismatch 0/7 (act 0)` | **`pass 7/7`** | — |
| `MovieClip-v6` | act 921 | act **935** | 936 |
| `MovieClip-v7` | act 954 | act **968** | 969 |
| `MovieClip-v8` | act 1072 | act **1086** | 1087 |
| `avm1/loadvariables`, `loadvariables2`, `load_vars`, `loadvars_tostring` | pass/29-35 | **identical** | — |
| `avm1/unload`, `unload_clip_event`, `unloadmovie`, `unload_nested_child` | pass | **identical** | — |

The full tail now runs on all three MovieClip rows: both `onData` rounds, `arguments.length == 0`,
`_root.var2`/`var3`, and `#total tests run: 927`.

### 4b. Why `matching_lines` is still 901/934/1020 — and what would move it
**One 2-line mechanism gates the entire tail's index alignment.** Expected lines 922-923 are

```
PASSED: this._target == '/hardref3/hardref3child' [./MovieClip.as:660]
_level0.hardref3.hardref3child.onUnload called
```

`hardref3` is swapped to depth `-32849` at `MovieClip.as:714`; its child's `onUnload` fires much later,
at teardown. We never fire it, so our 14 new tail lines sit two indices low and *none* of them align
— and the missing pair also costs us a third ours-only line, `FAILED: Tests run 926 (expected 927)`,
because the Dejagnu counter is two short. Land the descendant-`onUnload`-on-removed-depth mechanism
(memory `removemovieclip-descendant-onunload-defer` is the nearest existing note) and 12 of the 14
new lines align at once, taking MovieClip-v6/-v7 to **one** remaining ours-only cluster
(`MovieClip.as:2590` `mc.toString() == undefined`, `:2191` `propinspect == 0`, `:2097`
`arguments.caller`). `_root.var1` (the UTF-8-BOM key in `vars.txt`) and `#passed`/`#failed` are
**free** — Ruffle fails them too (`output.fp23.ruffle.txt` is byte-identical to ours there), so they
are inside Ruffle's diff set.

So the G3 flip is now **2 mechanisms + 3 one-liners away**, not 4 mechanisms away — but it is not
reached by this patch, and I am not claiming it.

**Functions touched:** new statics `avm1QueueFormDataEvent`, `avm1FireFormDataEvent`,
`avm1FireFormDataEvents` (beside `g_pending_direct_loads`), `avm1LoadFormIntoMC` (beside
`parseURLEncodedVars`), `avm1_form_urlencode` + `avm1_log_form_fetch` (inside the existing
`#if SWF_LOG_FETCH_ENABLED` block); edits to `processLoadVarsLoads` (one call), `actionGetURL2`
(loadVariables branch: `_root` target case + delegate to the helper + queue), `actionCallMethod`
(MOVIECLIP arm: new `loadVariables` branch).

---

## 5. Refutations / corrections to the brief and to wave-1

1. **The brief's "G3 = our run ends before the tail, 11 lines, one mechanism" is too kind.** It is
   four defects (§4a-d), only one of which ("`onData` never fires") is what the phrasing suggests.
   The method form of `MovieClip.loadVariables` did not exist at all.
2. **The brief's `+6` pricing overstates by 4.** G2 (+0 flips) and G3 (+0 flips) each clear one
   mechanism out of four on an all-or-nothing subset test. Wave-1 said this explicitly for G2
   ("M2 alone flips nothing"); the brief's headline number did not carry it through. The two real
   flips are G1 and the `loadvariables_method` row the brief did not know about.
3. **"M1/M3/M4 might be comparator-scope fallout" — refuted.** Patch 2 cleared exactly 26 lines on
   v7/v8 and zero on v6; the residue is unchanged on all three.
4. **`avm1/loadvariables_method` is an ignore-list row that should now be pruned.** Its own rationale
   block (`ruffle-tests/ignored_tests.txt:73-83`) diagnoses precisely defect (a) and sets the criterion
   "Prune on `pass`". It now passes. `load_vars` (29/35) is **unchanged** and stays ignored; its gap is
   the second `LoadVars.load()` `onLoad` block, a different mechanism.
5. **Sibling-collision check (brief §"Siblings"):** I did **not** edit `mc_call_as2_handler_ng`,
   `setVariableOnLocalScope`, `actionNextFrame`'s event arm, or the EV_MOUSE_WHEEL/onScroller path.
   `avm1FireFormDataEvent` is a deliberate private copy of `mc_call_as2_handler_ng`'s invoke ritual
   rather than a call into it — both because that function belongs to **w2-avm1-events** this session
   and because it can only find handlers in `mc->dynamic_props`, which is the wrong store for the
   ROOT clip (root timeline variables live in the global `var_map`). No textual overlap with any
   sibling's region.

---

## 6. What I ran (all `--mode=no-graphics`; mode parity is complete per `BRIEFS_COMMON`)

Baseline captured at pristine `e36bca73e` in this worktree *before* any edit; after-run with all
three patches applied. Full ledger: `<scratchpad>/w2-avm1-sort/{before,after}/*.json`.

| batch | tests | before | after |
|---|---|---|---|
| `avm1` headline + canaries | 27 | 24 pass / 3 mismatch | **26 pass / 1 mismatch** |
| `from_gnash/actionscript.all` | 10 | 3 pass / 7 mismatch | 3 pass / 7 mismatch (line counts above) |
| `from_shumway/avm1/array` | 1 | pass | pass |
| `regression` (AVM1 half, 59) | 59 | 59 pass | **59 pass** |
| broad AVM1 + shumway sweep | 40 | (see §6a) | (see §6a) |

**Why the `regression` suite is the 59 non-`avm2_*` tests, not all 92:** the AVM2 members cost
~160 s each under this session's load (~4 h for the pair of runs), and none of the three patches is
reachable from AVM2 — `_invoke_sort_comparator`, `actionCallMethod`'s FUNCTION/MOVIECLIP arms,
`actionGetURL2` and `processLoadVarsLoads` are all AVM1-only. The `avm2_*` rows plus
`bitmap_pool_layer_cap` and the two `mask_*` rows were excluded on that basis; CI covers them.

### 6a. Broad-but-shallow sweep (brief's explicit ask)
`avm1`: arguments, as2_oop, as2_super_and_this_v6, closure_scope, delete, enumerate, getproperty,
object_constructor, object_function, object_prototypes, object_resolve, register_class,
string_methods, this_scoping, timer_run_actions, funky_function_calls,
movieclip_prototype_extension, array_prototyping, array_constructor, array_length, array_trivial,
array_unshift, init_array_invalid, global_array.
`from_shumway/avm1`: array, callee, doactionorder, loadevent, loadvariables, lookup, moviecliploader,
nativeinheritance, operations, property-paths, propertycase, scope, super, target, undefined, watch.
None of these appears in `wave0-trace-inventory.txt` (which lists only failing rows), so every one is
expected to pass.

Result: **avm1 24/24 pass. shumway 11/11 pass** — but note the trap: five of the sixteen shumway names
(`doactionorder`, `loadvariables`, `property-paths`, `propertycase`, `undefined`) are **parent
directories holding sub-tests**, not leaf tests, and the runner reports them as `RECOMP_FAIL`
("SWF file `test.swf' not found"). That is a test-selection artifact, not a result. Re-run as leaves
(`--test=loadvariables/loadvariables`, `--test=undefined/undefined-swf6`, …): all 11 sub-tests pass,
including both `from_shumway/avm1/loadvariables/*` rows, which is the most direct independent check
on patch 3. Sweep total: **35/35 pass, zero movement.**

---

## 7. New unclaimed leads

1. **Descendant `onUnload` on a clip swapped to a removed depth never fires** (§4b). 2 lines on each of
   MovieClip-v6/-v7/-v8, and it is the single thing standing between patch 3 and 12 aligned lines per
   row. Highest-value follow-on to this work.
2. **`loadVariables` with `method` on a non-log_fetch build does no request at all.** We read the local
   fixture and ignore the GET query / POST body entirely (they only reach `swf_log_fetch_queue`). Fine
   for the corpus, wrong for any content that round-trips state through the query string.
3. **We do not dispatch the `data` clip event.** Ruffle's `load_form_into_object` fires *both*
   `onData` (the method) and `ClipEvent::Data` (the `onClipEvent(data)` handler). Only the method half
   is implemented here; no corpus test in my slice covers the clip-event half.
4. **`avm1_collect_form_values` reads `mc->dynamic_props`,** so a form POST whose target is the ROOT
   clip sends nothing — root timeline variables live in the global `var_map`. Not exercised by
   `loadvariables_method` (its target is a child clip), but it is a real hole in `getURL`-family
   form posting from the root.
5. **`array-v6` is a clean, comparator-independent +1** (4 ours-only lines / 3 mechanisms: sparse
   `hasOwnProperty`, "sort with a bogus comparator must not empty the array", `__proto__ = 8` typeof).
   Patch 2 does not touch it either way.
6. **The `_root`-as-string target hole probably is not unique to loadVariables.** The same
   "string target pushed as a constant, resolved by a `child_mc_cache` name scan" pattern sits in the
   loadMovie arm of `actionGetURL2`; worth a grep for other `_root`/`_parent`/path-string targets that
   fall through the same scan.
