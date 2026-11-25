# s28 w2b-gnash-holds: gnash hidden-gap HOLDs answered by Flash (wave 2, implementation)

Cloud worker, branch `fanout/w2b-gnash-holds`. Base `origin/master` `18eb8cb2c` (contains `ace9d2f88`, the w1b B1–B5
landing). Upstream mirror downloaded 2026-11-25 (`download_tests.sh from_gnash avm1`; the blobless Ruffle clone's
HEAD at that time was `d2a801a98`, newer than the brief's `c2f7d24b7`; flash-fixes APPLIED 4). Dawn/apt: OK.

**NEW files**
- `ruffle-tests/tests/swfs/regression/avm1_gnash_flash_probes/` (`create_test_swf.py`, `avm1asm.py`, `test.swf` SWF8,
  `test.toml`, `output.txt` = FP32 capture `w1-local-oracles/w1b-rm-gnash/test.flash32.txt`)
- `ruffle-tests/tests/swfs/regression/avm1_gnash_flash_probes_v6/` (`test.swf`, `test.toml`, `output.txt` = FP32 `test_v6.flash32.txt`)
- `ruffle-tests/tests/swfs/regression/avm1_gnash_flash_probes_v5/` (`test.swf`, `test.toml`, `output.txt` = FP32 `test_v5.flash32.txt`)
- `SWFRecompDocs/plans/session28-fanout-reports/w2b-gnash-holds-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w2b-gnash-holds.patch`

Edited docs (not in the patch): `from_gnash/_investigation/ACCEPTED_DIFFS.md` (Math, ops-v8, Inheritance re-worded),
`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (one entry appended at EOF).

## Verdicts (lead)

**GO, landed on the branch: +10 gnash rows `ruffle_matched → pass`, plus the 3 new regression probes pass, 0
regressions** on the full `from_gnash/actionscript.all` gate (243 rows, graphics AND no-graphics), the avm1 sweep
(167 rows) and the regression subset (53 rows, both modes). Every flip is graded against an FP32 golden.

| # | mechanism | Flash rule (fit to the FP32 traces byte for byte) | flips |
|---|---|---|---|
| B10 | `Selection.setFocus` / `setSelection` | programmatic `setFocus(tf)` selects all at once (begin 0, end = caret = len); `setSelection` with 3+ args is a no-op; 1 arg is a no-op while a selection exists, and from "no selection" (begin -1) still applies `(a, end)` (avm1/selection keeps passing) | `Selection-v6`, `-v7`, `-v8` |
| B11 | NaN `==` | two NaNs are equal only when they are the same number atom: a NaN gets a unique payload when it is first stored (SetVariable / DefineLocal / SetMember / StoreRegister), copies keep it, the `NaN` global and `Number.NaN` share atom 0, `Number(<object>)` makes a fresh one | `ops-v5..v8` (with B11b) |
| B11b | `Less2` with `""` | `"" < X` is false and `X < ""` true for every non-empty X | (ops.as:177, same 4 rows) |
| B2' | `with` cap inside functions | frame level 13 (all versions, landed); SWF6+ functions 12; SWF5 functions 13; after a frame-level overflow a SWF6+ DefineFunction (type 1) called later in that script enters no `with` (fitted, see HOLD below) | probe only (`with-v5..v8` stay pass) |
| P6 | `String.prototype.valueOf()` on the bare prototype | returns the string `"[type Object]"` | probe only |
| B6 | SWF5 function `__proto__` | a built-in function's creation-time `__proto__` is SWF6-flagged (0x80): SWF5 GetMember cannot see it or inherit through it (`constructor` stays visible); a SWF5 function compares like an object whose primitive is undefined unless it has an OWN valueOf/toString ("any function is equal to any other in SWF5", toString_valueOf.as:96); SWF5 `isNaN(fn)` uses the convertFloat model (0) | `Object-v5`, `Number-v5` |
| B19 | SWF6 inherited setter | `a.m = v` calls an inherited addProperty setter hidden by flag 256 or 1024 (not 4096) — the SWF6 setter search uses the SWF7 mask; an own write keeps flag 1024 | `Global-v6` |

**Probe landed:** `regression/avm1_gnash_flash_probes{,_v6,_v5}`, goldens = the coordinator's FP32 captures, all 3 pass
in both modes (before: FAIL, FAIL, FAIL).

**Dispositions re-worded** (task 4): gnash ACCEPTED_DIFFS Math-v5..v8 → platform split (Windows FP32 golden; Linux FP32
== ours); ops-v8 → RESOLVED (real gap, now passes; it was never in an ignore list); Inheritance §1a → golden is FP32
truncated at Flash's hang (decision unchanged), §1b → real Flash gap B17 (completion mechanism named), not "matches
Ruffle, fine". Summary table rows updated. One RvF entry appended (all 7 mechanisms).

## EXPECTED-FLIP LEDGER (for CI)

Trace axis, `ruffle_matched → pass` (both modes; graded goldens are FP32):
- `from_gnash/actionscript.all/Selection-v6`, `Selection-v7`, `Selection-v8`
- `from_gnash/actionscript.all/ops-v5`, `ops-v6`, `ops-v7`, `ops-v8`
- `from_gnash/actionscript.all/Object-v5`, `Number-v5`
- `from_gnash/actionscript.all/Global-v6`
- new rows `regression/avm1_gnash_flash_probes`, `_v6`, `_v5`: absent → **pass**

Trace axis, same status, more matching lines (no verdict change expected on CI): `Function-v5` (148 → 154),
`String-v5` (340 → 344), `MovieClip-v5` (352 → 353), `Date-v5` (308 → 309), `toString_valueOf-v5` (105 → 125;
`output_mismatch` → `ruffle_matched` on this box, where clean master already reads `output_mismatch`; CI baseline has it
`ruffle_matched`).

Pixel axis: **no expected moves.** Nothing touches a render path. The only state a render reads that changed is the
`Selection` begin/end after a programmatic `setFocus` (select-all was already drawn from `g_tf_select_all`); the
render canary (below) is the check.

## Per-test before / after (same box; before = clean `origin/master` worktree, after = this patch)

Before = clean `origin/master` worktree on this box (graphics); after = final patch, graphics AND no-graphics (verdicts
identical in both modes for every row). Gnash rows under `from_gnash/actionscript.all/`.

| row | before | after (g / ng) | mechanism |
|---|---|---|---|
| `Selection-v6` | ruffle_matched | **pass / pass** | B10 |
| `Selection-v7` | ruffle_matched | **pass / pass** | B10 |
| `Selection-v8` | ruffle_matched | **pass / pass** | B10 |
| `Selection-v5` | pass | pass / pass | (SWF5: no text field, -1 everywhere) |
| `ops-v5` | ruffle_matched | **pass / pass** | B11 + B11b |
| `ops-v6` | ruffle_matched | **pass / pass** | B11 + B11b |
| `ops-v7` | ruffle_matched | **pass / pass** | B11 + B11b |
| `ops-v8` | ruffle_matched | **pass / pass** | B11 + B11b |
| `Object-v5` | ruffle_matched | **pass / pass** | B6 |
| `Number-v5` | ruffle_matched | **pass / pass** | B6 (+ `Number.NaN` atom) |
| `Global-v6` | ruffle_matched | **pass / pass** | B19 |
| `with-v5`..`with-v8` | pass | pass / pass | B2' keeps the frame cap |
| `Number-v6..v8`, `Global-v5/v7/v8`, `String-v6..v8`, `toString_valueOf-v6..v8`, `XML-v6`, `XMLNode-v6` | pass | pass / pass | sibling rows (NaN / String / valueOf / XML) |
| `Function-v5` | ruffle_matched (148 lines) | ruffle_matched (154) | B6 partial (HOLD) |
| `toString_valueOf-v5` | output_mismatch (105) | ruffle_matched (125) | B6 |
| `String-v5` / `MovieClip-v5` / `Date-v5` | ruffle_matched (340 / 352 / 308) | ruffle_matched (344 / 353 / 309) | B6 / B11 lines |
| `regression/avm1_gnash_flash_probes` | FAIL (P2 func, P3, P4, P5, P6) | **pass / pass** | all |
| `regression/avm1_gnash_flash_probes_v6` | FAIL (same) | **pass / pass** | all |
| `regression/avm1_gnash_flash_probes_v5` | FAIL (P4, P5, P6) | **pass / pass** | B11, B11b, P6 |


## Gates run

- **Full `from_gnash/actionscript.all` (243 rows), both modes.** Before = clean `origin/master` worktree, graphics
  (all 243). After = this patch: graphics (all 243, on the patch minus the last SWF5-equality / AMF / autobox
  refinements) and no-graphics (all 243, final patch). Then on the final patch: all 60 `-v5` rows in both modes, plus 25
  headline and sibling rows in both modes. Result: **+10 `ruffle_matched → pass`** (the ledger), **0 status regressions**,
  0 matching-line losses. Verdicts are identical across modes for every row. Rows failing before and after
  (`ASnative-v5..v8`, `argstest-v6..8`) are box-local or baseline. I did not run a no-graphics before-leg over all 243;
  graphics-before is the comparison for both after-legs.
- **avm1 sweep, 167 rows** (no-graphics, final patch): everything matching `xml*` (not sockets), `with*`, `string*`
  (not `string_paths*`), `selection*`, `equals*`, `lessthan*`, `greater*`, `strictequals*`, `nan*`, `*swf5*`, `proto*`,
  `*setter*`, `as_set_prop_flags*`, `function*`, `define_function*`, `object_*`, `coerce*`, `watch*`, `global*`,
  `edittext_focus/programmatic/tab*`, `amf*`, `shared_object*`, `local_connection*`, `netconnection*`. 160 pass; the 7
  others (`global_instance_decls`, `global_proto_decls`, `global_proto_decls_delete`, `globals_monkeypatch`,
  `globals_swf5`, `shared_object`, `shared_object_self_ref`) give **byte-identical output on clean master** (md5 table in
  the session log), so they are not regressions. Earlier no-graphics spot runs of `selection`, `selection_asbroadcaster`,
  `selection_handlers`, `edittext_focus_selection`, `edittext_programmatic_focus`, `edittext_tab_focus`,
  `edittext_drag_select`, `edittext_ime_focus_lost`, `focus_remove`, `focus_root_movie`, `focus_keyboard_press`: all pass.
- **regression suite, 53 rows near the change, both modes: 53/53 pass.** These are every `regression/` dir matching
  with/nan/select/focus/coerce/swf5/equal/less/valueof/proto/setter/scope/resolve/string/xml/amf/shared/type1/closure/
  function (excluding avm2_*), plus the w1b list (`avm1_swf6_case_insensitive_builtins`, `lv_cross_swf_version`,
  `ei_mc_this_receiver`, `avm1_watch_long_name`, `avm1_edittext_path_variable_same_frame`) and the 3 new probes.
- **Render canary** (`render_canary.py capture/compare`, `--recompile`), before = clean worktree, after = final patch.
  It covered all 151 non-avm2 members of `render_canary_tests.txt` (216 PNGs): **216 IDENTICAL, 0 DIFFERS, no trace or
  image status changes.** I skipped the 36 `avm2/` members: the AVM2 runtime runs none of the touched code, and I did not
  download that suite. I added no canary member, because no render path is touched.
- Mode parity: no `NO_GRAPHICS`-only code is touched. Both modes were still run on every gate above (except the canary,
  which is graphics by design).


## Mechanism / patch scope

`SWFModernRuntime/src/actionmodern/action.c` (functions touched, all self-localized):
- B11: new statics `avm1NanFreshAtomBits`, `avm1NanGlobalValue`, `avm1NanTagVar`, `avm1NanTagStackSlot` (near the
  scope-chain globals); calls added at the top of `actionSetVariable`, `actionDefineLocal`, `actionSetMember`,
  `actionStoreRegister`; `NaN` global value (`_global.NaN` init and the `actionGetVariable` built-in-constant arm);
  `Number.NaN` (both `g_ctors[3]` and lazy `g_number_constructor` sites); `actionCallFunction` `Number(...)` arm.
- B11b: `actionLess2` string branch.
- B10: new `selection_set_focus_select_all_indices`; `builtin_selection_setFocus` (both select-all sites);
  `builtin_selection_setSelection` (arg-count rule).
- B2': `actionWithStart` (cap rule) + new `actionWithStartK` wrapper (declared in `action.h`); recompiler
  `SWFRecomp/src/action/action.cpp` SWF_ACTION_WITH arm now emits `actionWithStartK(app_context, lift_fn_kind)`
  (0 frame, 1 DefineFunction, 2 DefineFunction2; `lift_fn_kind` already tracked). **Recompiler change: recompile.**
- P6: `builtin_string_proto_valueOf` (bare String.prototype receiver; an autoboxed string keeps the wrapper path).
- B6: new `b6FlagFnProto` (after `getFunctionProto`), called after every built-in-constructor `__proto__` install
  (`ensureCtorOwnProps`-style init sites, the all-ctors loop, ExternalInterface/geometry arms, `createConstructorCopy`,
  secondary Object/extra/Error ctors, lazy String/Number ctors, `g_object_constructor_static`); Object-ctor own_props
  rebuild keeps the flag; `actionGetMember` FUNCTION arm (SWF5 gate before the virtual Function.prototype fallback);
  `actionEquals2` (SWF5 function operands); `varToDoubleSWF` FUNCTION case (SWF5).
- B19: `actionSetMember` general-object arm (setter search mask in SWF6; keep flag 1024 on an own overwrite).

`SWFModernRuntime/src/actionmodern/avm1_amf.c` `w0_value` F64 arm: a tagged NaN goes on the wire as the plain quiet
NaN of the same sign (bytes unchanged vs master).

No `NO_GRAPHICS`-only code, no `swf_core.c`/`tag_stubs.c`/`swf.c`/`tag.c`/`render_webgpu.c`. CI: `graphics`,
`categories=full` (AVM1 runtime + recompiler emission).

## HOLD / not finished (each with its completion mechanism)

- **B2' DefineFunction-after-overflow rule is FITTED, not pinned.** FP32 printed no `P2 func depth` line in SWF6/8 although
  gnash with.as:233-237 (`objA.func`, a type-1 function in SWF6) enters a `with` normally. The only difference is that
  the probe calls the function after a frame-level overflow. Model shipped: that state lasts for the rest of the tick and
  blocks every `with` in a later SWF6+ type-1 function. What is unpinned: how long the state lasts (script, tick or
  movie); whether a type-1 function called while no overflow happened gets 12 or 13 levels; whether frame-level `with`
  after the overflow still works. Completion: FLASH request 1 below. No corpus row depends on it.
- **Function-v5** stays `ruffle_matched` (2 lines): FP32 says `Email.constructor.toString() == undefined` (CallMethod
  through the hidden `__proto__` must also miss `toString`) while `Number.hasOwnProperty(...)` still works through it.
  Completion: FLASH request 2 (CallMethod on a SWF5 function: `toString`, `valueOf`, `hasOwnProperty`, `call`).
- **ActionGreater with `""`** left unchanged: only `Less2` is pinned. FLASH request 3.

## Refutations / premise attacks

- "P2: the `with` cap inside DefineFunction differs from frame level". Half true. FP32 gives 13 for SWF5 functions
  and 12 for SWF6+ DefineFunction2, and with.as shows a SWF6 type-1 function entering `with` normally. So the "zero
  levels in a type-1 function" in the SWF6/8 probe is state left by the frame-level overflow just before the call. It
  is not a per-function-kind cap.
- "B11: Flash compares Number values by bit pattern" (w1b report). Refuted by P4: `0/0` and `Math.sqrt(-1)` both
  produce x86's default NaN, yet FP32 says they differ, and `glob == glob2` (two reads of `NaN`) is true. The rule is
  atom identity. Our existing bit-pattern `==` can express that once each stored NaN carries a unique payload.
- "B10: ignore unless exactly 2 args breaks avm1/selection" (w1b). The break came from the wrong focus state, not the
  arg rule: FP32's programmatic `setFocus` already reports a select-all (0, len, len). A 1-arg call is then a no-op
  everywhere except from begin = -1, which is the avm1/selection case. Both goldens pass.
- B6: "SWF5 hides Function.prototype" alone does not flip Number-v5. The SWF5 `==` for functions has to change too:
  Flash's own source comment says "any function is equal to any other in SWF5".

## Box-local notes (not regressions)

On this box, clean `origin/master` already fails these rows (outputs byte-identical before/after this patch): avm1
`global_instance_decls`, `global_proto_decls`, `global_proto_decls_delete`, `globals_monkeypatch`, `globals_swf5`
(`output_mismatch`), `shared_object`, `shared_object_self_ref` (`runtime_error`), gnash `ASnative-v5..v8`
(`output_mismatch`), `argstest-v6..8` (baseline-failing). These are likely upstream drift (Ruffle HEAD `d2a801a98` at download)
or box environment. They are not in my ledger.

## New unclaimed leads

- B12 `Object-v6..v8` (watch + addProperty) still the cheapest Object row after this.
- The NaN atom model now makes a *passed parameter* NaN compare equal to itself (bits copied), and an anonymous
  arithmetic NaN compared unstored keeps the old bit-pattern rule (`(0/0) == Math.sqrt(-1)` is still true unstored).
  Flash says false for the latter. Low value; a FLASH probe of unstored comparisons would decide it.
- `parseInt("x")` read twice from one variable now equals itself (the w1b lead: an F32 NaN). Stored F32 NaNs are
  widened to tagged F64.

## LOCAL ORACLE REQUESTS

1. **FLASH (trace, direct pinned, SWF 6 and 8):** a `with`-depth follow-up probe (build script: extend
   `regression/avm1_gnash_flash_probes/create_test_swf.py` P2) with: (a) a type-1 function called BEFORE any overflow
   (depth reached: 12 or 13?); (b) the frame-level overflow, then another frame-level 16-nest in the same DoAction;
   (c) the overflow on frame 1, the type-1 function called on frame 2; (d) the overflow inside a function, then the type-1
   function called at frame level. Decides the B2' lifetime and the type-1 cap.
2. **FLASH (trace, SWF5):** CallMethod on functions: `Number.toString()`, `Number.valueOf()`, `Function.toString()`,
   `f.toString()` for a user `f`, `Number.hasOwnProperty("prototype")`, `typeof f.call`, `f.call(null)`. Decides
   Function-v5:689.
3. **FLASH (trace, SWF 6/8):** `ActionGreater` (0x67) with `""`: `"" > "0"`, `"0" > ""`, `"" > ""`.
