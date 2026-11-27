# s29 w2-rm-avm1-gnash-land: w1 P1–P4, P6–P9 landed, P5 replaced by a general MovieClip super context, 16.16 rotation matrix

**New files**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-rm-avm1-gnash-land-report.md` (this report)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-rm-avm1-gnash-land.patch`
  (`git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  plus the two new fixture dirs; 13 files. `git apply --check -R` passes on the branch, and `git apply --check` passes on a
  fresh `origin/master` `c91637b7` worktree)
- `ruffle-tests/tests/swfs/regression/avm1_mc_super_native_probe/` (`create_test_swf.py`, `avm1asm.py`, `test.swf`,
  `test.toml`, `output.txt` = `w1-local-oracles/w1-rm-avm1-gnash/super_native_probe.fp32.txt` verbatim). `test.swf` is
  byte-identical to `python3 create_test_swf.py out.swf 8`.
- `ruffle-tests/tests/swfs/regression/avm1_rotation_matrix_fixed/` (`Test.as`, `test.swf`, `test.toml`, `output.txt` =
  `w1-local-oracles/w1-rm-avm1-gnash/matrix_probe/flash.txt` verbatim; SWF = the coordinator's MTASC build)

Also edited (not new): `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (1 entry appended at
EOF). `ruffle-tests/verify_output.py` and `render_canary_tests.txt` are unchanged.

**Box.** Cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Branch `fanout/w2-rm-avm1-gnash-land` from
`origin/master` `c91637b7` (code = `faeaaba4b`). Corpus: `download_tests.sh avm1 from_gnash`, upstream Ruffle master at
download ≈ `cd94f4540` (the script prints no SHA; that is `ls-remote` right after), flash-fixes APPLIED 27. Every
measurement is A/B on this box: **before = a clean `origin/master` worktree** (`/root/wt`, its own `SWFRecomp` build),
after = this patch, both legs `--mode=graphics --recompile`, actual trace outputs compared **byte for byte**.

## Verdicts (lead)

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | P1 `meth`, P2 `_width` sign, P3 BOM, P4 blendMode, P6 export frame gate, P7 unloadClip cancel, P8 EI `class`, P9 SWF5 split | **LANDED** as the w1 prototype, with one fix to P6 (below) | `attach_movie_export_not_yet_run`, `load_cancel_via_unloadclip`, `MovieClip-v5` |
| 2 | P5 (narrow Boolean `super`) | **DROPPED, replaced by M**: a general MovieClip super context. `regression/avm1_mc_super_native_probe` matches FP32 **byte for byte** (18/18 lines; before: 11 lines differ) | `MovieClip-v6`, `-v7`, `-v8` still flip |
| 3 | `_rotation`-derived matrix in 16.16 (prices `matrix_test`) | **LANDED (S)**, read-back only. `regression/avm1_rotation_matrix_fixed` passes (before: 2 lines differ) | **`from_gnash/misc-ming.all/matrix_test`** (new, not in w1's +6) |
| 4 | P6 bug found in this wave | **FIXED.** w1's P6 released a later-frame export in the frame's tag stream, which runs *after* the hoisted DoInitAction prologue, so an init action attaching its own frame's export got `undefined`: `register_class/registerClassTest2` went rm 8 → **23** diff lines (an init action's `attachMovie("libItem3")`). The w1 gate missed it (that row must have run on stale `RecompiledScripts`). The release now goes into the frame prologue in stream order with DoInitAction/ImportAssets; the row is byte-identical to base. | — |
| 5 | Gate | **682 rows, 0 regressions.** Every row outside the ledger is byte-identical to base. No-graphics headline leg = graphics, byte for byte. Render canary 99/99 md5-IDENTICAL. | — |

**Expected CI movement (both modes): trace +7 `ruffle_matched → pass` + 2 new passing regression rows; 2 rm rows move
Flash-ward without a status change; image axis 0.**

## EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

Trace axis. Identical in `graphics` and `no-graphics` (measured: 12-row no-graphics leg, outputs byte-identical to
graphics). Every golden below is FP32 (s28 `trace-provenance.md` "golden = Flash"; the MovieClip rows grade
`output.fp23.txt`). All seven are `known_failure = true` upstream, so Ruffle itself fails them.

| row | before (ours − golden lines) | after | mechanism |
|---|---|---|---|
| `avm1/attach_movie_export_not_yet_run` | rm, 1 | **pass** | P6 |
| `avm1/load_cancel_via_unloadclip` | rm, 2 | **pass** | P7 |
| `from_gnash/actionscript.all/MovieClip-v5` | rm, 10 | **pass** | P1 |
| `from_gnash/actionscript.all/MovieClip-v6` | rm, 20 | **pass** | P1 + P2 + P3 + M |
| `from_gnash/actionscript.all/MovieClip-v7` | rm, 20 | **pass** | P1 + P2 + P3 + M |
| `from_gnash/actionscript.all/MovieClip-v8` | rm, 25 | **pass** | P1 + P2 + P3 + P4 + M |
| `from_gnash/misc-ming.all/matrix_test` | rm, 5 | **pass** | 16.16 matrix |
| `regression/avm1_mc_super_native_probe` (NEW) | fail, 11 | **pass** | M + P2 + P4 |
| `regression/avm1_rotation_matrix_fixed` (NEW) | fail, 2 | **pass** | 16.16 matrix |
| `from_gnash/actionscript.all/ExternalInterface-v8` | rm, 4 | rm, **3** (Flash-ward) | P8 |
| `from_gnash/actionscript.all/String-v5` | rm, 14 | rm, **8** (Flash-ward) | P9 |

Pixel axis: **no expected movement.** None of the ledger rows has an image comparison, and the canary is md5-identical.

## M: the MovieClip super context (replaces P5)

FP32 (`super_native_probe.fp32.txt`): `super(...)` in a plain function called as a method of a MovieClip calls
`this.__proto__.__constructor__` with the clip as `this`. The w1 prototype's narrow arm only modelled
`Boolean()`. It printed `voB=undefined`, `tsN/tsS=[object Object]`, `voS=_level0` and `u=undefined`, all wrong.

Mechanism (all `SWFModernRuntime/src/actionmodern/action.c`):
- **`actionCallFunction`, `super` arm**: new statics `mcSuperOnDemandClip` + `mcSuperOnDemandCall`, defined just above
  `actionCallFunction`. When `this` is a MovieClip that no active super context belongs to (a registerClass constructor's
  context has the clip as companion or its `dynamic_props` as receiver, so those keep the old path), it resolves
  `this.__proto__` through `actionGetMember`. It then finds `__constructor__` on that proto's chain and:
  - script constructor: runs it with the clip as `this` (the MC user-method arm's flags, plus `INV_VERSION_SWITCH`), with
    `pushSuperContextWithMC(base_proto, 1, mc)` so a nested `super()` resolves `base_proto.__proto__`. Gives `u=7`.
  - native `Boolean` / `Number`: stores the primitive under a script-unreachable DontEnum key (`"\x01mc_native_prim"`)
    on the clip's `dynamic_props`. `String` and other natives stay no-ops (FP32 shows nothing observable for `String`).
- **Native read-back on a clip receiver.** The MC user-method arm of `actionCallMethod` calls natives with
  `this_obj = NULL`. New `g_mc_native_recv`/`g_mc_native_func` are set around that call only, and only when the callee
  is one of the wrapper natives. Arms added to `builtin_wrapper_valueOf`, `builtin_prim_wrapper_toString`,
  `builtin_bool_proto_toString` and `builtin_string_proto_valueOf`: Boolean natives read a Boolean primitive and Number
  natives a Number one; every other wrapper native answers `undefined` on a clip (FP32 `tsS`, `tsN` on a Boolean clip);
  `String.prototype.valueOf` gives the clip path.
- **Distinct native identities.** Number.prototype.valueOf/toString and Boolean.prototype.valueOf shared one
  `ASFunction` (`g_wrapper_valueOf_func` / `g_prim_wrapper_toString_func`), so a clip could not tell `Number.prototype.
  valueOf` from `Boolean.prototype.valueOf`. New `installPrimProtoDistinct` / `distinctPrimProtoSlot` swap those slots
  for clones with the **same C bodies** (every `advanced_func ==` check still matches; no code compares the struct
  addresses, grep-verified). They are called in `ensureGlobalInit` after `installBoolProtoToString(g_ctors[4]…)` and in the
  secondary version group's ctor loop. A side effect that also matches Flash: `Number.prototype.valueOf !=
  Boolean.prototype.valueOf` now.

Re-gate: the general super moved **no row** outside the ledger (682 rows; the whole `from_gnash` family including
`Inheritance-v5..v8`, `Function-v5`, `misc-mtasc.all`, `trace-as2/super`, plus 164 avm1 rows with every
`super|proto|constructor|registerclass|inherit|boolean|number|string|valueof|tostring|class` name).

## 16.16 rotation matrix

`transformMatrixGetter` (`action.c`): when the clip's matrix was rebuilt from `_rotation`/`_xscale`/`_yscale`
(`as_set_flags & (4|8|16)`, no live exact `transform.matrix` assignment), a/b/c/d round to 1/65536 (FP32: `cos 30° =
0.86602783203125`, `cos 45° = 0.707107543945313`, 90° multiples exact, `_yscale=-100` gives `d=-1`). It applies to
read-back only. `getLocalMatrixForMC` and the renderer's float matrix are untouched, so this cannot move a pixel.
`getBounds`/`localToGlobal`/`concatenatedMatrix` also keep the double matrix: no corpus row prices them, so they are a gap,
listed below.

## P6 as landed (one change from the w1 prototype)

`SWFRecomp/src/swf.cpp` `SWF::interpretTag` EXPORT_ASSETS case: `tagExportFrameReached` for an export in frame ≥ 2 is
appended to `current_frame_init_actions` (the frame prologue, in stream order with DoInitAction and ImportAssets) rather
than to `context.tag_main`. `tagExportDeferToFrame` still goes to `tagInit`. The prologue runs on every pass through the
frame (goto skip mode included); the release is idempotent.

## Gates (before = clean `origin/master` worktree, after = patch; byte-exact actual-output compare)

| gate | rows | result |
|---|---|---|
| whole `from_gnash` family (actionscript.all 243, misc-ming.all 63 + nested `action_order`/`displaylist_depths`/`init_action`/`loading`/`loop`/`register_class`, misc-mtasc 9, misc-swfc 21, misc-swfmill 15 + `trace-as2/*`) | 411 | 4 MovieClip + matrix_test rm → pass; EI-v8 / String-v5 Flash-ward; **everything else byte-identical** |
| avm1: every s29-baseline rm row, every name matching the w1 sweep regex plus `super/proto/constructor/registerclass/inherit/boolean/number/string/valueof/tostring/matrix/transform/rotation/export/class`, every SWF with ExportAssets past frame 1, nested `target_paths`/`set_property_values`/`malformed_actions` | 164 | 2 rm → pass; rest byte-identical |
| regression: the w1 argued subset (`mcl/unload/loadvar/form/blend/width/scale/export/attach/ei_/split/meth/geturl/load/lv_/string/xml/bitmap/mc_` + the super/proto/matrix names, minus avm2) + the 2 new fixtures | 107 | 105 byte-identical pass → pass; 2 new rows fail → pass |
| **total** | **682** | status: 547 pass→pass, 99 rm→rm, 17 mm→mm, 8 recomp_fail→recomp_fail (all byte-identical), 7 rm→pass, 2 new, 2 rm content moves (ledger) |
| attach/export re-gate (subset of the above: every `*attach*`/`*export*` row in the three suites + the 27 SWFs my tag scan finds with ExportAssets past frame 1, + `registerClassTest2`, which the scan misses) | 57 | only `attach_movie_export_not_yet_run` moves (→ pass); `registerClassTest2` byte-identical after the P6 fix |
| no-graphics, headline rows (7 flips, 2 fixtures, EI-v8, String-v5, `registerClassTest2`) | 12 | same statuses as graphics; the rm rows' outputs byte-identical to graphics |
| render canary: every `render_canary_tests.txt` member in avm1/from_gnash/regression, `capture` both legs `--recompile` | 77 tests / 99 PNGs | **99 IDENTICAL, 0 differs**, no trace or image status change |

The 17 mm and 8 recomp_fail rows are all pre-existing (`s29-baseline-trace-failing.txt`: `global_proto_decls*`,
`external_interface_monkeypatch`, `argstest-v6..v8`, `GradientFillTest`, `matrix_accuracy_test1`, …). The recomp_fail rows
are the container dirs (`loop/`, `register_class/`, `target_paths/`, …) whose nested tests were run separately.

After the gate I made two behaviour-neutral edits: the hidden key's length constant 16 → 15 (it was the NUL-inclusive
length, but set and get used the same constant), and a `releaseObject` for the throwaway Number wrapper in the clip
`toString` arm. I re-ran the only rows that reach that code: the probe and `MovieClip-v6/v7/v8`, both modes, all pass.

**Canary coverage gap (stated, not fixed).** P2 (`_width` sign) and P4 (`blendMode` 0 ignored / 15 → normal) are the
only render-reachable rules. No avm1/gnash/regression image row scripts either, so the canary cannot see them; adding a
member would need a golden-less image fixture. Pixel risk is limited to SWFs that set `blendMode = 0`/`15` or write
`_width`/`_height` on a negatively scaled clip.

CI to dispatch: `categories=full` in **both modes**. The recompiler changes, and `ng_shared.c` is shared.

## Not finished / gaps (with completion mechanism)

| gap | mechanism | decider |
|---|---|---|
| `super()` into natives other than Boolean/Number on a clip (`String`, `Date`, `Array`, `Object`, …) | no-ops today. FP32 shows nothing observable for `String` via the probe's readers; others unprobed | FLASH trace: the probe extended with `Date`/`Array`/`Object` and `this.getTime()`, `this.length`, `this.push` read-backs |
| `super.method()` (CallMethod on `super`) inside a plain function on a clip | unchanged: it still uses whatever super context is active (often none). M only covers `super(...)` | FLASH trace: `this.__proto__.__proto__.f = …; super.f()` on a clip |
| 16.16 for `getBounds`/`localToGlobal`/`concatenatedMatrix` and render | read-back of `transform.matrix` only | a corpus row or a Flash probe that prices it; the render side needs an image row |
| P2 `_height` symmetry, P4 blendMode 16/255 | confirmed by FP32 (probe `H`/`B` sections now pass byte-exact) | done |

## New unclaimed leads

1. **Stale super context across an MC method call.** The MC user-method arm of `actionCallMethod` pushes no super context.
   So a clip method called from inside an object method used to see the *caller's* context for `super()`. M now
   short-circuits that when `this` is a clip, but `super.method()` still sees it.
2. **The w1 gate's stale-`RecompiledScripts` hole.** Any wave-1 row measured without `--recompile` after a recompiler
   change is suspect. Here it hid `registerClassTest2`. Wave-2 gates touching `SWFRecomp/` should always pass `--recompile`.
3. **Exports for Sound / `BitmapData.loadBitmap`** (w1 lead 3) still see a not-yet-reached export. They are unprobed.

## LOCAL ORACLE REQUESTS

None blocking. Optional, for the gaps above:
1. FLASH trace, direct pinned: `regression/avm1_mc_super_native_probe` extended with `Date`, `Array`, `Object` sections
   (decides whether M's native no-ops are right). The fixture builder is in the dir; I did not build the extension.
