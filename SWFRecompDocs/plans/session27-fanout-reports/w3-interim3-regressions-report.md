# w3-interim3-regressions: the 3 regressions of s27 interim #3 (wave 2, cloud)

**New files (this slot):**
- `SWFRecompDocs/plans/session27-fanout-reports/w3-interim3-regressions-report.md` (this file)
- `SWFRecompDocs/plans/session27-fanout-reports/w3-interim3-regressions.patch`

No new fixtures and no changes to `verify_output.py` or `render_canary_tests.txt`. The patch touches two runtime
functions: `action.c` `tfCallGlobalCtorOnField` and `tag.c` `ng_apply_pending_sprite_self_gotos`. Neither is on a
sibling's list in `SIBLING_FILE_MAP.md`. `ng_apply_pending_sprite_self_gotos` was last edited by local N
(`f5565dcf9`).

Box: cloud, Ubuntu 24.04, lavapipe Dawn (`SETUP_STATUS` all OK). Base = `origin/master` `eee2e6204` (code
= `eaa3e70f7` + `c72303e75` + `31d3e3237` on top of `78fee9e13`). Upstream tests were downloaded at
session start (`download_tests.sh avm1 from_gnash visual avm2 from_shumway text fonts`). **Fidelity:** my
*before* render of `regression/avm1_attached_clip_selfgoto_child_parent` has md5 `4cb68ea7…`, byte-identical to CI's
`output.actual.png` on `origin/ruffle-image-results` (`99dcf345`). So local grading of that row is CI-grade.

## VERDICTS

| # | row | responsible commit | verdict | after (graphics & no-graphics) |
|---|---|---|---|---|
| 1 | `avm1/globals_monkeypatch` SEGFAULT | **`85cca4df6`** exposed it. The bug is older (`tfCallGlobalCtorOnField`, from `456fef1b`, before `cceb5133a`). | **GO, fixed** | **SEGFAULT → output_mismatch** in both modes. The output is byte-identical to the pre-interim `cceb5133a` output (251 expected-only / 251 actual-only diff lines, same as before). |
| 2 | `from_gnash/misc-swfc.all/action_execution_order_test12` ruffle_matched → output_mismatch | **`78fee9e13`** (w2b-timers-tail, the goto-queued init flush at the call return) | **NO FIX: reclassification.** The move was predicted and booked as EXPECTED by w2b-timers-tail §1.3/§6. Our output is now **byte-identical to Flash's `output.fp9.txt`**. | unchanged by this patch (output_mismatch, both modes) |
| 3 | `regression/avm1_attached_clip_selfgoto_child_parent` [output] image FAIL | **`f5565dcf9` itself.** It fails at its own landing commit (bisected: f5565dcf9, fe6eb5f9d, 78fee9e13 and HEAD all give the same md5 `4cb68ea7…`). Nothing later broke it: the author graded it in a shared tree that carried peers' uncommitted hunks (their report §5 says so for other rows). | **GO, fixed in code.** The golden is right. | **image FAIL (1120 outliers, max 255) → PASS (0 / 0)**. Trace PASS in both modes, before and after. |

## 1. `avm1/globals_monkeypatch`: SIGSEGV in `findPropertySlot`

**Bisect** (no-graphics, `SWFModernRuntime/` swapped per commit; these commits are runtime-only):
`cceb5133a` MISMATCH, `85cca4df6` SEGFAULT, `f5565dcf9` SEGFAULT, `fe6eb5f9d` SEGFAULT, `78fee9e13` SEGFAULT, HEAD
SEGFAULT. The crash appears in both modes.

**Crash site** (gdb, `SWF_DEBUG_INFO=1`). Output stops after `new MyTextField() called!` (expected line 59). Call chain:

```
findPropertySlot (object.c:205  obj->hash_index[probe])
 <- findPropertyStructWithPrototype
 <- actionCallMethod                       // 5a SUPER arm: super() = CallMethod(super, undefined)
 <- func2_anonymous_12                     // monkeyPatchClass's `cls`: `var zuper = super; ... return zuper();`
 <- invokeFunctionValue
 <- tfCallGlobalCtorOnField (action.c)     // createTextField runs the replaced _global.TextField on the field
 <- actionCallMethod (createTextField arm)
```

**Mechanism.** `tfCallGlobalCtorOnField` called the replaced constructor with `INV_SUPER_CTX` and a MOVIECLIP `this`.
`invokeFunctionValue` then runs `pushSuperContext(this_ptr = MovieClip*, depth 0)`. The prologue binds
`super = {SUPER, MovieClip*, 0}`. `zuper()` reaches `actionCallMethod`'s SUPER arm, which calls
`walkProtoChain(MovieClip*, 0)` and gets the MovieClip back cast to `ASObject*`. `findPropertyStructWithPrototype`
then reads MovieClip memory as `num_used` / `hash_index` / `properties`.

This was always undefined behaviour. Before `85cca4df6`, the garbage happened to pass `getProperty`'s
"obviously corrupt" guard and returned nothing. `85cca4df6` changed the MovieClip contents (the leftovers' EditText and
TextControl state), not the struct layout, so the bytes at those offsets became a non-NULL `hash_index`. This is the
same MovieClip-as-ASObject class that N fixed for the `actionSetMember` setter in `f5565dcf9`.

**Fix** (`action.c` `tfCallGlobalCtorOnField`, +10/−1). Drop `INV_SUPER_CTX` from the flags. Around the
`invokeFunctionValue` call, push `pushSuperContextWithMC(field->dynamic_props, 1, field)` and pop it after. This is the
super context a constructor gets everywhere else:
- `actionInvokeRegisteredClassConstructor` pushes the MC's property bag at depth 1 with the MC as companion;
- `new` pushes the new object at depth 1.

`super()` now walks `props.__proto__` (= the replaced constructor's prototype, which the function already installs)
and finds no `__constructor__`, as before. Nothing else in this function changes.

**Result:** SEGFAULT → output_mismatch in no-graphics and graphics. The output is identical line-for-line to
`cceb5133a`'s, so the row is back to its pre-interim status: a standing NO-GO on output (prototype monkey-patching
lines), not a crash.

## 2. `action_execution_order_test12`: Flash-ward, not a regression to fix

The harness grades `output.fp10.txt`: the `[subtests]` variant with the highest `player_options.version`, with no
runtime version override (`verify_output.py` `_expected_output_name`). `known_failure = true`.

| | line 17 `enterFrameOrder` | line 19 `asOrder` | lines 20–21 totals | vs fp10 Flash (21 lines) | vs fp9 Flash (21 lines) |
|---|---|---|---|---|---|
| Flash fp9 `output.fp9.txt` | PASSED | PASSED `0+1+2+3+4+` | 14 / 0 | 18/21 | 21/21 |
| Flash fp10 `output.fp10.txt` (graded) | FAILED `…4+3+…5+3+…` | PASSED `0+1+2+3+4+` | 13 / 1 | 21/21 | 18/21 |
| Ruffle `output.fp10.ruffle.txt` | PASSED | FAILED `0+1+2+4+` | 13 / 1 | 19/21 | 18/21 |
| ours at `cceb5133a` (ruffle_matched) | PASSED | FAILED `0+1+2+4+3+` | 13 / 1 | 19/21 | 18/21 |
| **ours at `78fee9e13` / HEAD / this patch** | PASSED | **PASSED `0+1+2+3+4+`** | 14 / 0 | **18/21** | **21/21 (byte-identical)** |

There are two ways to count:
- **By assertion:** ours went from 2 wrong Flash assertions to 1. Line 19 now matches BOTH Flash goldens; before, it
  matched neither (and was not even Ruffle's value).
- **By raw line count against the graded fp10 file:** one line worse (19 → 18). The totals lines 20–21 are derived
  from the assertions. They used to agree with fp10 only by accident: one wrong PASS (line 17) and one wrong FAIL (line
  19) cancelled out.

Line 17 is player-version behaviour. FP10 runs enterFrame on clips 4 and 5 once each, while FP9 and Ruffle do not.
Our output now equals FP9 Flash exactly.

The w2b-timers-tail report (§1.3, §6 ledger) predicted and booked this exact move as EXPECTED. The real Flash we can
run is FP32. Whether FP32 behaves like FP9 or FP10 on line 17 is unknown (LOCAL ORACLE REQUEST below).

**Decision: no code change; reclassify.** Matching fp10's line 17 would mean an FP10-only enterFrame rule that Ruffle
does not implement and FP9 does not have, for one row; that is not worth it. Options for the coordinator:
- (a) accept the −1 effective as Flash-correct;
- (b) add a from_gnash disposition: "== Flash fp9 golden byte-for-byte; fp10 line 17 is player-version enterFrame
  behaviour";
- (c) a harness rule that grades a `[subtests]` row as passing when it equals ANY Flash variant. That is a
  `verify_output.py` change (shared with w2-allow-networking-subtests' subtest code), not done here: it would move
  every row that matches a lower-version Flash golden, and that needs its own audit.

## 3. `avm1_attached_clip_selfgoto_child_parent` image: orphans from the self-goto replay

The CI actual (red square at the stage origin, plus the collapsed d=0 "bone" drawn) is the same artifact pair that
`438121c22` fixed on the natural-advance path (`avm1_attached_clip_timeline_child_parent`, passes):
- an orphan child composed at identity;
- the real child's compose reading an identity local matrix.

The attached-pass dump showed two `kid` and two `bone` MovieClips:
- the real ones, parent `h`, not pass members;
- orphans with parent `_root` (same `display_obj`), drawn by the OFFSCREEN attached pass at identity.

A trap on `actionFindOrCreateMovieClip("kid", _root)` gave:

```
actionFindOrCreateMovieClip <- tagPlaceObject2 (Phase-7b pre-create: parent = g_current_context)
 <- sprite_5_frame_3 <- exec_sprite_frame <- ng_apply_pending_sprite_self_gotos (the replay loop) <- tagMain
```

**Mechanism.** `ng_apply_pending_sprite_self_gotos` rebuilds the target frame by replaying the sprite's frames through
`CALL_FRAME`. `exec_sprite_frame` binds the clip as context only for a NAMED entry (`ng_mc_for_sprite_obj`). An
attachMovie'd root's entry is unnamed, and this pass runs at the top of the tick with `g_current_context = _root`.
So `tagPlaceObject2`'s Phase-7b pre-create (`actionFindOrCreateMovieClip(name, g_current_context)`) mints `_root`-parented
orphans for every named child.

`f5565dcf9` fixed the later `process_sprite_needs_init` parent (`att_mc`), so the trace passes: `h.kid` resolves to the
real clip, and the orphans are not `_root`-visible by name in the trace. But the orphans were still created and drawn.

**Fix** (`tag.c` `ng_apply_pending_sprite_self_gotos`, +11). When `att_mc` was bound (attached root), set
`actionSetCurrentContext(att_mc)` and `actionSetBaseClip(att_mc)` around the replay loop, and restore both after.
`ng_attached_run_tree` does exactly this for the natural advance (`if (self_mc && obj->instance_name == NULL)`). Named
entries and non-attached sprites are untouched (`att_mc == NULL`).

**Golden.** Unchanged and correct: the Ruffle exporter's frame 5. The author reports the Flash Player 32 oracle agrees
at 0 px (`n-l2l4-pixel-pass-report.md` §4: "equal to Flash's tick 6 at 0 px"). The fix makes us match it exactly
(0 outliers, max diff 0).

## Per-test before/after (same box; before = clean `origin/master`, after = this patch)

| row | mode | before | after |
|---|---|---|---|
| `avm1/globals_monkeypatch` | no-graphics | SEGFAULT | output_mismatch (== `cceb5133a` output) |
| `avm1/globals_monkeypatch` | graphics | SEGFAULT | output_mismatch (same diff as no-graphics) |
| `from_gnash/misc-swfc.all/action_execution_order_test12` | no-graphics | output_mismatch (== fp9 Flash) | same |
| `from_gnash/misc-swfc.all/action_execution_order_test12` | graphics | output_mismatch (== fp9 Flash) | same |
| `regression/avm1_attached_clip_selfgoto_child_parent` | no-graphics | trace PASS | trace PASS |
| `regression/avm1_attached_clip_selfgoto_child_parent` | graphics | trace PASS, **image FAIL 1120 outliers / max 255** (md5 == CI actual) | trace PASS, **image PASS 0 / 0** |

## Regression-suite + nearby-row sweep (graphics, A/B)

44 rows were run in both legs. I compared trace output text and every actual-PNG md5.
- **Regression suite, 22 rows:** every `avm1_attach*`, `avm1_attached_clip_*`, `avm1_goto_*`,
  `avm1_exec_order_attached_selfremove`, `avm1_loaded_bare_goto_seq`, `avm1_textfield_attached_depth_order` and
  `avm1_timer_root_goto_*` row.
- **from_gnash:** `actionscript.all/TextField-v6/v7/v8` (these replace `_global.TextField`, so they reach
  `tfCallGlobalCtorOnField`) and `MovieClip-v6/v7/v8`.
- **avm1:** `globals_monkeypatch`, `external_interface_monkeypatch`, `coerce_to_object_monkeypatch`,
  `as2_super_and_this_v6/v8`, `as2_super_via_manual_prototype`, `super_edge_cases`, `attach_movie`,
  `attach_movie_export_not_yet_run`, `attach_movie_stop`, `empty_movieclip_can_attach_movies`, and
  `netstream_play_flv_screen` (the one corpus row that reaches the attached branch).

**Result:** only the 2 headline rows moved (the globals_monkeypatch output text and the selfgoto image md5 plus its
status). For the other 42 rows, trace output and image md5s are byte-identical before and after. 42/44 pass or
ruffle_matched after. The two that don't:
- `external_interface_monkeypatch`: MISMATCH, identical in both legs;
- `globals_monkeypatch`: SEGFAULT → MISMATCH.

## Graphics render canary (`render_canary.py`, full 185-test / 251-PNG set, `-P 3`)

`before` = clean `origin/master`, `after` = this patch. Results: **IDENTICAL 251, DIFFERS 0**, APPEARED/VANISHED/NO_RENDER 0, **trace status changes: none,
image status changes: none.** The standing set contains no attached-clip self-goto row. The covering row is
`regression/avm1_attached_clip_selfgoto_child_parent` itself, measured above. I did not append it to
`render_canary_tests.txt`: its image is graded by the regression suite on every CI run.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace (graphics AND no-graphics):**
- `avm1/globals_monkeypatch`: **runtime_segfault → output_mismatch** (its pre-interim `cceb5133a` status; NOT a pass,
  and its output text equals `cceb5133a`'s).
- `from_gnash/misc-swfc.all/action_execution_order_test12`: **no move from this patch** (stays output_mismatch; see §2
  for the reclassification. It is still −1 effective against the interim-#2 baseline by design).
- `regression/avm1_attached_clip_selfgoto_child_parent`: trace stays **pass**.
- Anything else moving is unexpected. If something does, the highest-risk classes are:
  - rows where `_global.TextField` is a user function whose body uses `super` (super now resolves from the field's
    props at depth 1 instead of reading MovieClip memory);
  - attachMovie'd clips whose own frame script self-gotos to a frame that places named sprites (no more `_root`
    orphans; those children's frame code now runs with the clip as context/base clip during the rebuild).

**Pixel (graphics images):**
- `regression/avm1_attached_clip_selfgoto_child_parent [output]`: **fail → pass** (1120 outliers / max 255 → 0 / 0).
- No other image row expected (canary above).

## HOLDs / NO-GOs and completion mechanisms

- `action_execution_order_test12` back to a graded pass: needs one of
  - (a) a disposition entry (coordinator);
  - (b) an "any Flash `[subtests]` variant" harness rule plus its own audit;
  - (c) FP10's line-17 enterFrame rule, priced NO-GO here: one row, and Ruffle and FP9 disagree with it.

  An FP32 trace (request below) decides whether the modern-Flash target is FP9-like (we already match it) or
  FP10-like.
- `globals_monkeypatch` output itself: standing NO-GO (prototype/global monkey-patching); untouched.

## New unclaimed leads

- **The MovieClip-as-ASObject super context is general.** `invokeFunctionValue` with `INV_SUPER_CTX` and a MOVIECLIP
  `this` pushes the raw `MovieClip*` as the super-context `this`. This happens for every MC-receiver call through the
  default flag superset (event handlers, etc.).
  - Any `super` / `super()` in such a body walks MovieClip memory (UB; it is luck-dependent whether it crashes).
  - The general fix is to translate `this_is_mc` into `pushSuperContextWithMC(mc->dynamic_props, depth, mc)` in
    `invokeFunctionValue`. Not done here, because it changes super resolution on many call paths and needs a sweep
    of its own.
  - Third member of the class after the `f5565dcf9` `actionSetMember` setter and this `tfCallGlobalCtorOnField`.
- `ng_apply_pending_sprite_self_gotos` still runs a NON-attached unnamed sprite's replay with `_root` context. This
  is the same orphan risk if such an entry places named children. `att_mc` is NULL there, and there is no owner to
  bind without `ng_mc_for_sprite_obj`, which needs a name.

## LOCAL ORACLE REQUESTS

- FLASH: `ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/action_execution_order_test12/test.swf`, trace,
  `--wrapped`, 30 frames. Compare line 17 (`enterFrameOrder`) against `output.fp9.txt` (PASSED) and `output.fp10.txt`
  (FAILED `…4+3+…5+3+…`). If FP32 prints PASSED, our output equals modern Flash byte-for-byte, and the row's fp10
  grading is the only reason it fails.
