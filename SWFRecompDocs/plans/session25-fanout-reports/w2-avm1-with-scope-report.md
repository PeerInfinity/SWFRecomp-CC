# s25 w2-avm1-with-scope: DrawingApiTest scope/dispatch residuals

**New files:** this report and `w2-avm1-with-scope.patch`. No new source files and no new fixtures.
Source scope: `SWFModernRuntime/src/actionmodern/action.c` only (+73/−13).

## Verdict

**GO. 1 priced flip, measured in both modes:**
`from_gnash/misc-ming.all/DrawingApiTest`: **output_mismatch → ruffle_matched** (`known_failure = true`).

- All 7 residual lines are fixed: `:126`, `:256/257/264/266`, and both trailing `delete` lines.
- One fix had a side effect: `:125` `! hitTest(376,180,true)` broke, because the call now gets real args. A fourth
  fix brings it back.
- That leaves **1 diff line vs Flash**: `:261 x.hitTest(122, 157, true)`. Flash says FAILED. We and Ruffle say
  PASSED. That line is in Ruffle's own diff, so the row is `ruffle_matched`.
- Graphics and no-graphics produce a byte-identical actual output (md5 `02bf58ae`).

The brief's framing was partly wrong (see Refutations). This was four bugs, not three. Two of them are not
`with`-scope name resolution at all.

## EXPECTED-FLIP LEDGER (for CI)

| test | axis | before | after |
|---|---|---|---|
| `from_gnash/misc-ming.all/DrawingApiTest` | trace (graphics + no-graphics) | output_mismatch (7 diff lines + 2 extra) | **ruffle_matched** (1 line, `:261`, also in Ruffle's diff) |
| (none) | pixel | — | no pixel moves expected (canary 99/99 identical) |

Nothing else should move. All other 217 sweep rows produced a byte-identical actual output before and after.

## Mechanisms and fixes (all in `action.c`)

### 1. Bare `hitTest`/`getBounds`/`getRect` reached CallMethod with 0 args (line 126)

- **Bug:** a strict-aliasing miscompile in the `_bm_match` arm of `actionCallFunction`. The arm stored the arg
  count with `VAL(float, &ActionVar.data.numeric_value) = (float)num_args` and then `pushVar` read the `u64`.
  Under gcc `-O2` the float store was dropped, so `actionCallMethod` popped `num_args = 0`.
- **Proof:** instrumented `actionCallMethod` printed `n=0`. Adding one `fprintf` that read the bits made it
  `n=2`.
- **Consequence:** every bare `hitTest(x, y, true)` returned false.
  - That is why `:126` failed.
  - `:125 ! hitTest(...)` only passed by accident.
  - w1's "the call never reaches the hitTest arm" was this bug: the arm was reached, with no args.
- **Fix:** new `static cfDelegateToMCMethod()`. It re-pushes the args, pushes the count as F64 via `memcpy`, then
  the clip and the name, and calls `actionCallMethod`. The `_bm_match` arm now uses it.
- The other `VAL(float, &…numeric_value) = 0.0f` sites in `action.c` store 0.0f into a zeroed struct, so the
  dropped store is harmless there. They are left alone.

### 2. Bare `createEmptyMovieClip` inside `with (clip)` created the child on the timeline (lines 256–266)

- **Mechanism:**
  - The CallFunction arm used `g_current_context` (root) and ignored the with-scope.
  - So `with (a) { createEmptyMovieClip("x", 20) }` made `_root.x`, not `a.x`.
  - The earlier `x = 223` (a SetVariable inside `with (zshape)` inside `with (a)`) correctly landed on `_root`.
  - The later `x.hitTest(...)` inside `with (a)` therefore missed `a.x` (no such child) and resolved the timeline
    number 223.
- **Fix:** new `static cfWithScopeMethodTarget()` finds the innermost with-scope that answers the name:
  - a with-scope MovieClip answers;
  - a with-scope plain object that carries the name stops the search and keeps the old path.
- When a clip answers (SWF ≥ 6), the `createEmptyMovieClip` CallFunction arm delegates to the CallMethod
  MOVIECLIP arm through `cfDelegateToMCMethod`. This matches Ruffle: the name resolves on the with-object, so
  `this` is that clip.
- `zshape` is also created as `a.zshape` now. The `zshape.*` lines still pass, because `a` is at the identity
  transform.

### 3. Zero-area triangles counted as hits (line 125, exposed by fix 1)

- **Mechanism:** the committed-path triangle hit test in the `actionCallMethod` MOVIECLIP `hitTest` arm
  (drawing-API refinement) treats `d1 = d2 = d3 = 0` as inside.
- A hairline (`lineStyle(0)`) builds width-0 stroke quads. A point anywhere on the hairline's supporting line
  scores as a hit. `(376, 180)` lies on the y = 180 line of the 220..280 hairline.
- **Fix:** skip triangles whose area is below 1e-9 in both the fill and the line loops.
- **Known gap (lead below):** a point exactly ON a hairline used to hit through this artefact and now misses.
  Ruffle hit-tests strokes at a minimum width of 1 px.

### 4. `delete this.onEnterFrame` inside a type-1 `onEnterFrame` (2 trailing lines)

- **This is not delete semantics.** `actionDelete` worked. It deleted from the wrong object.
- **Mechanism:**
  - In `actionDispatchEnterFrameHandlers` (children arm), the type-1 (DefineFunction, which Ming emits) handler
    ran with `INV_LOCAL_SCOPE` only: no this-stack and no `this` binding.
  - So `GetVariable("this")` hit the `check_special_vars` fallback, which returns the closure base clip (the
    defining timeline, `_root`).
  - The first delete removed nothing relevant (it returned true on root's bag), the handler kept firing, and
    later deletes returned false.
  - Instrumented: `[DEL] mc=<root>` while `[EF] mc=a`.
- **Fix:** add `INV_BIND_THIS` for type-1 handlers. This binds `this` = the receiver on the handler's local frame.
  It is lexical, so nested calls' `this` is unchanged.
- **Ruffle reference:** `core/src/avm1/function.rs` `Avm1Function::exec`: `local_this = this` unless
  PRELOAD/SUPPRESS_THIS is set, i.e. the receiver for every DefineFunction1.
- **Out of scope:** the root arm (`this` is root anyway) and the `n-play-game` button/mouse dispatch were not
  touched.

**Functions touched:**
- `actionDispatchEnterFrameHandlers` (children arm flags only);
- new `cfWithScopeMethodTarget`;
- new `cfDelegateToMCMethod`;
- `actionCallFunction` (the `createEmptyMovieClip` arm head and the `_bm_match` arm);
- `actionCallMethod` (the MOVIECLIP `hitTest` drawing-path triangle loops).

No button or mouse dispatch code was touched.

## Per-test before/after (clean `origin/master` 1decadf0 vs patch, same box)

| test | mode | before | after |
|---|---|---|---|
| from_gnash/misc-ming.all/DrawingApiTest | graphics | output_mismatch (`fe51ae96`) | **ruffle_matched** (`02bf58ae`) |
| from_gnash/misc-ming.all/DrawingApiTest | no-graphics | output_mismatch (`fe51ae96`) | **ruffle_matched** (`02bf58ae`) |

Line-level after (graphics = no-graphics): the only diff vs `output.txt` is `:261` (see Refutations).

## Sweep (graphics, 218 rows, actual-output md5 A/B)

**Which rows:**
- Every row whose SWF (or child SWF) contains ActionWith 0x94: 61 SWFs → 58 test rows. Of these, 41 also contain
  `createEmptyMovieClip` and 8 contain `hitTest`.
- avm1 / misc-ming / misc-swfc rows that have DefineFunction 0x9B plus `onEnterFrame`.
- The bare-call rows: `ButtonEventsTest`, `mouse_events`, `button_v5/v6/children`, `movieclip_hittest*`,
  `hittest_lockroot/morph/winding_rule`.
- `avm1/delete*`.
- The **whole regression suite** (118 rows).

The gnash `delete*`/`MovieClip-v*` rows are in the WITH set.

**Result:**
- 217/218 rows are md5-identical in status and output.
- The only mover is DrawingApiTest.
- Status counts after: 180 PASS, 29 RUFFLE_MATCHED, 7 mismatch rows (pre-existing, unchanged output), 2
  non-rows:
  - `regression/_results` is a results dir;
  - the `from_gnash/misc-ming.all/register_class` name didn't resolve in my list.
- Regression suite: 117/117 PASS before and after.

**No-graphics A/B, 14 rows:** DrawingApiTest, with-v6, with-v7, MovieClip-v6, MovieClip-v8, getvariable-v6,
masks_test, ButtonEventsTest, RollOverOutTest, event_handler_scope_test, avm1/this_scoping,
movieclip_hittest_shapeflag, regression/enterframe_type1_args, regression/resolve_type1_args. All are identical
except DrawingApiTest (same flip).

**Render canary:** the avm1 / from_gnash / visual members of `render_canary_tests.txt` (59 tests, 99 PNGs), before
vs after: **99 IDENTICAL**, no trace or image status changes. The canary set was not extended, because no render
path changed.

## Refutations / premise attacks

- **"Bare `hitTest()` inside `with` must resolve through the with-scope":** already true on master (w1 landed the
  retarget). The real cause was the 0-arg miscompile (fix 1).
- **"`x` resolves to the wrong object via with-scope name resolution":** GetVariable's with-scope child lookup was
  correct. The bug was on the creation side: `createEmptyMovieClip` ignored `with`.
- **"`delete` of `onEnterFrame` returns false / clip-event table":** handler slots are plain `dynamic_props`
  entries, and `actionDelete` is correct. The bug is `this` binding in type-1 enterFrame dispatch.
- **`:261 x.hitTest(122,157,true)`, unfixable here and not booked:**
  - The gnash source says *"flashplayer 10.0.12.10 for linux fails this, whereas 9.0.115.0 doesn't"*.
  - `output.txt` (FAILED) is the Flash-10 behaviour. Ruffle (PASSED) is Flash 9 / exact geometry.
  - The point is outside the even-odd fill and 0.72 px from the stroke centreline, against a 0.9 px half-width:
    it is a stroke hit by geometry.
  - Before the patch the line "matched" only because `x` was the number 223.
  - Matching Flash 10 needs a Flash oracle for its stroke hit rule under scaling. This is an `ACCEPTED_DIFFS`
    candidate (Flash-version-dependent), for the coordinator to decide. I did not edit the disposition docs.

## Not finished / leads

- **Hairline hit test (new lead, S):** committed `lineStyle(0)` paths can no longer be hit at all through the
  triangle test (before, they hit only through the collinear artefact).
  - Ruffle tests strokes at a minimum of 1 screen px.
  - Completion: route committed paths with `stroke_built_half_w ≈ 0` through `drawingSegDistHit` over
    `stroke_poly` at a half-width of 0.5 px / scale.
  - No sweep row moved.
- **Sibling bare-call arms ignore `with` the same way (S each, unpriced):** `createTextField` (hard-codes root),
  `attachMovie`, `getNextHighestDepth`, `getInstanceAtDepth` in `actionCallFunction`. Each can delegate through
  `cfWithScopeMethodTarget` / `cfDelegateToMCMethod`. No corpus row was found that needs them, so they were left
  alone to keep sweep risk at 0.
- **Other dispatchers with type-1 handlers and no `this` binding:** the root enterFrame arm is fine (`this` is
  root). Other arms that run type-1 handlers with `INV_LOCAL_SCOPE` but without `INV_BIND_THIS` (e.g.
  `actionDispatchRootVarMapEnterFrame`) may have the same latent bug. Unswept.

## LOCAL ORACLE REQUESTS

None. A Flash (not Ruffle) oracle for `:261` would settle its disposition, but it is not blocking.

Upstream corpus: `download_tests.sh avm1 from_gnash from_shumway visual` at session time (2026-11-22, upstream
master). Code base `origin/master` 1decadf0.
