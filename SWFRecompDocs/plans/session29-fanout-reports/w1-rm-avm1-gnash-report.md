# s29 w1-rm-avm1-gnash: AVM1/gnash `ruffle_matched` rows re-priced against FP32, cheap ones prototyped

Wave 1 (diagnosis + measured prototype). Cloud worker, `origin/master` `aa36d43a` (code = s29 baseline `bfa47037b`
lineage). Corpus: `download_tests.sh avm1 from_gnash` (upstream Ruffle master, ≈`952362ecf` at report time; the
script does not print a SHA), flash-fixes APPLIED 26. SETUP_STATUS: apt/Pillow/Dawn OK. All measurements
`--mode=graphics` on cloud lavapipe unless noted; every target and gate row was re-run locally at base and after.

**New files** (all under `session29-fanout-reports/`):
- `w1-rm-avm1-gnash-report.md` (this file)
- `w1-rm-avm1-gnash-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; 4 files: `action.c`,
  `ng_shared.c`, `include/libswf/tag.h`, `SWFRecomp/src/swf.cpp`)
- `w1-rm-avm1-gnash-fixtures/avm1_mc_super_native_probe/` (`create_test_swf.py`, `avm1asm.py` copied from s28
  w1b-rm-gnash, `test.swf`, `test.toml`, `output.ours-base.txt`, `output.ours-prototype.txt`): FLASH request 1

## Verdicts (lead)

**GO (wave 2): 9 small rules, measured, +6 `ruffle_matched → pass` (graphics AND no-graphics), 0 status moves and
0 content moves anywhere else on a 282-row gate + 56-row attach/export re-gate.** Every flip's golden is FP32
(trace-provenance table A; `MovieClip-v8` is the Windows-FP32 golden, and the one Linux/Windows split line in it,
:2394, we already printed the Windows way before the patch).

| # | row | before (graded golden) | after | mechanism(s) |
|---|---|---|---|---|
| 1 | `avm1/attach_movie_export_not_yet_run` | rm, -1/+1 (`_level0.fromFrame1` where FP32 says `undefined`) | **pass** | P6 export frame gate |
| 2 | `avm1/load_cancel_via_unloadclip` | rm, -0/+2 (child ran + `onLoadInit`) | **pass** | P7 unloadClip cancels the queued load |
| 3 | `from_gnash/actionscript.all/MovieClip-v5` | rm, -10/+10 | **pass** | P1 `meth` |
| 4 | `from_gnash/actionscript.all/MovieClip-v6` | rm, -20/+20 (`output.fp23.txt`) | **pass** | P1 + P2 `_width` sign + P3 BOM + P5 Boolean super |
| 5 | `from_gnash/actionscript.all/MovieClip-v7` | rm, -20/+20 (`output.fp23.txt`) | **pass** | P1 + P2 + P3 + P5 |
| 6 | `from_gnash/actionscript.all/MovieClip-v8` | rm, -25/+25 (`output.fp23.txt`, Windows FP32) | **pass** | P1 + P2 + P3 + P4 blendMode + P5 |

Line-level Flash-ward moves with no flip: `ExternalInterface-v8` -4/+4 → -3/+3 (P8, the remaining line is the
native-enumeration model), `String-v5` -14/+14 → -8/+8 (P9; the rest is s28 B6 + B7).

**HOLD → closed this wave:** `load_cancel_via_unloadclip` (s28 HOLD "after w2-avm1-leads-land": the unloadMovie cancel
`e7afd5ad2` never reached `MovieClipLoader.unloadClip`), `attach_movie_export_not_yet_run` (s28 capture
`w1-local-oracles/w1b-rm-avm1-misc/export_timing_probe_stop.flash32.txt` decides it).

**NO-GO / HOLD, priced:** the other 73 AVM1 Flash-golden rm rows, by owner mechanism, in §Rows and §HOLD. Cheapest
remaining (S–M, 1 row each, every one needs its own mechanism): `zeroframe_definesprite`, `LoadBitmapTest`,
`replace_buttons1test`, `duplicate_movie_clip_test`, `Transform-v8`; mechanism-bucket wins: s28 B12 `Object-v6..v8`
(3), s28 B18 `LoadVars-v6..v8` (3), s28 B20a `array-v5..v8` (4).

## Scope and premise attacks

- **Scope by VM.** The s29 rm list has 185 rows; 79 are AVM1-VM rows with a Flash golden (trace-provenance table A):
  6 `avm1/*` + 73 `from_gnash/*`. The 18 shumway/timeline/fonts/visual/mixed_avm table-A rows in the rm list are AVM2
  (the s28 w1b-avm1-misc table already says so) and belong to w1-rm-avm2. The 29 other AVM1 rm rows are not targets:
  25 untestable (Camera/NetConnection/Stage/device-font TextField/input.json fixtures/`_xmouse`/SharedObject) and
  4 gnash `Date-v5..8` (graded `output.fp10.txt`, which FP32 no longer prints).
- **"ExternalInterface-v8 is S" — half refuted.** It has two mechanisms. `_toAS` of a `class` node (`eval` of the
  class name) is S and is in the prototype. The other line is `EI._objectToXML(new XML)`: FP32 serializes **every**
  property of the XML object, DontEnum prototype methods included (`toString`, `appendChild`, … as `<null/>`),
  XMLNode accessors first and in Flash's native order, `attributes` as `<null/>`, and no `idMap`. That is the
  native-object enumeration model (disposition-audit sibling's UNSURE item), not an S serializer arm. Row stays rm.
- **"the `loadVariables` method rows (S)" — confirmed, and it was bigger than priced.** s28 B8 said "0 standalone
  flips". With B8 (`this.meth` on loadVariables/getURL/loadMovie) plus three more small rules found in the same rows
  (B-W `_width` resets a negative scale, B-BOM SWF6+ form loader drops a UTF-8 BOM, B-BM blendMode 0/15, B-BOOL
  `super()` into Boolean on an MC `this`), **all four `MovieClip-v5..v8` rows flip**.
- **`load_cancel_via_unloadclip` HOLD — closed.** s28's `e7afd5ad2` (`actionCancelPendingLoadsFor`) is called from
  `mc.unloadMovie()` only; `MovieClipLoader.unloadClip` never called it. One call in `builtin_mcl_unloadClip` flips
  the row.
- **`attach_movie_export_not_yet_run` HOLD — closed by the s28 capture.** `w1-local-oracles/w1b-rm-avm1-misc/
  export_timing_probe_stop.flash32.txt`: 131 ticks of `undefined` with the export in a never-reached frame 2 →
  exports register when the playhead reaches the frame. Prototyped as an attachMovie-only gate (imports, font and
  registerClass lookups unchanged).
- **A small diff is still not a cheap row.** `zeroframe_definesprite` (-2/+2), `loop_test7` (-1), `LoadBitmapTest`
  (-2/+2), `matrix_test` (-5/+5), `action_execution_order_test` (-1) each need their own M mechanism (table below).

## Rows (all 79 AVM1 Flash-golden rm rows)

`d` = unified content diff vs the graded golden (`-golden/+ours`), graphics, measured at base on this box. Owner
in the s28 bucket name where one exists (`B…` = `w1b-rm-gnash-report.md`, `m…` = `w1b-rm-avm1-misc-report.md`).
"other slot" rows are listed, not worked.

| row | d (base) | one-line diff | owner mechanism | price | status after |
|---|---|---|---|---|---|
| `avm1/attach_movie_export_not_yet_run` | -1/+1 | frame-1 attachMovie of a frame-2 export succeeds | P6 | S | **pass** |
| `avm1/load_cancel_via_unloadclip` | -0/+2 | child runs + `onLoadInit` after `unloadClip` | P7 | S | **pass** |
| `from_gnash/actionscript.all/MovieClip-v5..v8` (4) | -10..25 | `mcm == N` ×8-12, `_yscale` -50, `var1` BOM, `toString` after Boolean super, blendMode 0/15 | P1-P5 | S each | **pass** ×4 |
| `from_gnash/actionscript.all/ExternalInterface-v8` | -4/+4 → -3/+3 | `_objectToXML(new XML)` property set/order; `_toAS(class Date)` | P8 (done) + native-object enumeration (hidden prototype members, native order, `attributes` null, no `idMap`) | M-L, disposition-audit owns | rm |
| `from_gnash/actionscript.all/String-v5` | -14/+14 → -8/+8 | multi-char split (done); `chr`/`ord` bytes (B7); `__proto__.valueOf` prim (B6) | P9 + B6 + B7 | M-L | rm |
| `avm1/tab_ordering_properties_tab_index_edge_case` | -3/+3 | `asdf` stored raw vs `undefined`/`5` | m: string tabIndex storage rule | S once decided | rm (disposition-audit UNSURE item) |
| `avm1/target_paths/swf5`, `/swf6` | -163/+127 | debug-player `Parameters of primitive types…` lines + slash/dot variable paths | m: debugger-line policy + path eval | L | rm |
| `avm1/asnative_instrument` | -88/+0 | NetConnection/NetStream ASnative tables not instrumentable | m L (Windows FP32) | L | rm |
| `from_gnash/actionscript.all/ASnative-v5..v8` (4) | -34/-39 | Date/Stage/… natives by id (`e().valueOf()`) | B16 ASnative id table | L (Windows golden) | rm |
| `from_gnash/actionscript.all/Math-v5..v8` (4) | -5/+5 | `Math.pow(1)` etc. | B16b platform split (Linux FP32 == ours) | — (disposition) | rm |
| `from_gnash/actionscript.all/Microphone-v6..v8` (3) | -31/+31 | `Microphone.get()` object | B16 device | — (Windows golden) | rm |
| `from_gnash/actionscript.all/MovieClipLoader-v7`, `-v8` | -115/+0 | local MEDIA loadClip fires no callbacks | B16 MCL local load path | L (Windows golden) | rm |
| `from_gnash/actionscript.all/TextFormat-v7` / `-v8` | -38 / -36 | `getTextExtent` widths | B14 device-font metrics | L | rm |
| `from_gnash/misc-ming.all/EmbeddedFontTest` | -27/+27 | embedded `textWidth` ~7% narrow | B14 (DefineFont3 advance scale?) | M-L | rm |
| `from_gnash/misc-ming.all/TextSnapshotTest` | -81/+81 | `getSelectedText` etc. | B15 TextSnapshot selection model | M-L | rm |
| `from_gnash/actionscript.all/BitmapData-v8` | -8/+8 | `near(bm, 23..26, 15)` edge pixels | B20d draw() AA at a 2-colour edge | M | rm |
| `from_gnash/actionscript.all/Function-v5` | -4/+4 | `Email.constructor.toString()` undefined; `prototype.__constructor__` hidden | B6 SWF5 function-proto visibility | M | rm |
| `from_gnash/actionscript.all/toString_valueOf-v5` | -12/+12 | SWF5 `TextField` instance has no `toString`/`valueOf`; prim of functions | B6 + TextField SWF5 proto | M | rm |
| `from_gnash/actionscript.all/HitTest-v8` | -3/+3 | `a.hitTest(41,25,true)` FP32 false | B13 stale render-time matrix | M (other slot: hittest family) | rm |
| `from_gnash/misc-ming.all/DrawingApiTest` | -1/+1 | Flash `hitTest(122,157,true)` false (curve edge) | B13 / shape hit precision | M | rm |
| `from_gnash/actionscript.all/Inheritance-v5` | -0/+1 | Flash hangs at cyclic `instanceof` (golden truncated) | B17 | NO-GO (don't replicate a hang) | rm |
| `from_gnash/actionscript.all/Inheritance-v6..v8` (3) | -8/+9, -4/+5 ×2 | `A.B.B`, `FAAC`, `FFFC`, `undefinedFFC`, ctor-call counts | B17 super re-resolution via the receiver's live chain | M-L | rm |
| `from_gnash/actionscript.all/LoadVars-v6..v8` (3) | -6/+2 | `loaded` own prop; 2nd `load()` inside `onLoad` returns false and run stops | B18 | M | rm |
| `from_gnash/actionscript.all/Object-v6..v8` (3) | -8/+8 | watch + addProperty: watcher return becomes the underlying value | B12 | M | rm |
| `from_gnash/actionscript.all/Sound-v5` | -14/+14 | Sound bound by target path (volume 76/80 vs 100, `undefined` after unload) | B20c | M | rm |
| `from_gnash/actionscript.all/Transform-v8` | -7/+7 | 2 colorTransform clamp lines; `trans.matrix = …` keeps cached `_xscale`/`_rotation` | B20f (cached-scale model: our MC renders from the cached fields, so not S) | M | rm |
| `from_gnash/actionscript.all/XML-v5` | -9/+9 | SWF5 nbsp byte; BOM/codepage load | B7 | M-L | rm |
| `from_gnash/actionscript.all/XML-v8` | -0/+21 | we deliver gnash.xml `onLoad`, FP32 printed none | s28 oracle question 2 (still open) | ? | rm |
| `from_gnash/actionscript.all/array-v5..v8` (4) | -5/+5, -6/+6 | `c.length == 3`, `a.length == 4`, for-in order with `sort`/`length` own props | B20a (3 rules) | M | rm |
| `from_gnash/actionscript.all/setProperty-v5..v8` (4) | -15..16/+6..7 | run aborts after `:40` (`Tests run 36/37 of 46`) | B20b tellTarget/with setProperty block | M | rm |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test` | -1/+0 | `as in frame2 of mc_blu` missing | §27.4 interleave family | M-L (other slot) | rm |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test6` | -4/+4 | `mc2 Load` before `x` | §27.4 | M-L (other slot) | rm |
| `from_gnash/misc-swfc.all/action_execution_order_test10` | -9/+7 | `mc4` lifetime checks | §27.4 | M-L (other slot) | rm |
| `from_gnash/misc-ming.all/init_action/InitActionTest` | -4/+4 | `0+1+3+2+…`: FP32 runs each DoInitAction at its tag position, interleaved with PlaceObject onClipInitialize | init actions hoisted to frame prologue (`swf.cpp` DO_INIT_ACTION, "mirrors Ruffle's preload pass") | M-L (corpus-wide ordering risk) | rm |
| `from_gnash/misc-ming.all/callFunction_test` | -6/+6 | CallFunction on `mc1:func` paths (`x6 == _root.mc1`) | B20g path-qualified CallFunction | M | rm |
| `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test` | -7/+7 | `dynamicmc1048576` undefined | B20g depth range | M | rm |
| `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test2`, `_test3` | -7/+7 | `static3 onClipConstruct` / `depth3Constructed == 2` | B20g static clip re-construct order | M | rm |
| `from_gnash/misc-ming.all/duplicate_movie_clip_test` | -4/+4 | `MovieClip.prototype.duplicateMovieClip` borrowed onto a Button → undefined | B20g duplicate of a button | S-M | rm |
| `from_gnash/misc-ming.all/loading/LoadBitmapTest` | -2/+2 | `loadBitmap` of a JPEG → `transparent` true; `func('img1')` with `this` = a level → object | two rules: transparent = source has alpha (needs a bitmap-format flag from the recompiler through `tag.c`/`tag_stubs.c` registration); level `this` → undefined | M | rm |
| `from_gnash/misc-ming.all/loop/loop_test6` | -4/+4 | `mc1Constructed == 2` vs 1 | goto-rewind construct count | M | rm |
| `from_gnash/misc-ming.all/loop/loop_test7` | -1/+0 | missing the queued `movieClip1 unloaded` after a backward goto re-creates then removes the clip | goto-rewind unload queue (§27.4-adjacent) | M | rm |
| `from_gnash/misc-ming.all/loop/loop_test10` | -20/+16 | init/construct order | B20 / §27.4 | M-L | rm |
| `from_gnash/misc-ming.all/matrix_test` | -5/+5 | `c=8.74e-8, d=0.999999999999996` vs exact 0/1 after `_yscale` flip / `_rotation=±90` | float-precision rotation (`f32` π); FP32 is exact here but prints `1.2e-16`-class values elsewhere | M (probe) | rm |
| `from_gnash/misc-ming.all/path_format_test` | -7/+7 | `x1 == 'mc11_frame4'` vs 0 (+1 debugger line) | path/goto family (s28 w2-occupied-depth listed it) | M | rm |
| `from_gnash/misc-ming.all/register_class/registerClassTest2` | -6/+6 | `onLoad` order `clipevs` before `clip3` | registerClass onLoad order | M | rm |
| `from_gnash/misc-swfc.all/registerclass_test3` | -12/+12 | `player.movie` undefined | registerClass + attach | M | rm |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | -12/+12 | `mc6.__proto__` after destruction | destruction/proto lifetime | M | rm |
| `from_gnash/misc-ming.all/replace_buttons1test` | -3/+3 | `typeof(...)` string vs undefined | button replace | S-M (unread) | rm |
| `from_gnash/misc-mtasc.all/levels` | -15/+15 | `_level5.swapDepths(10)` → `_level16394` (level name = depth + 16384) | level re-keying on swapDepths | M | rm |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval`, `…2` | -3/+3 | `asOrder` `0+` only | timer/goto | — (w1-timers-goto owns) | rm |
| `from_gnash/misc-swfmill.all/zeroframe_definesprite` | -2/+2 | `a11b11c11d111` vs `a00b11c22d000`: `_framesloaded`/`_totalframes` = advertised DefineSprite frame count (0/1/2), `_currentframe` 0 for a 0-frame sprite | sprite frame count from the header (recompiler `DefineSprite` + runtime getters) | M | rm |

Not targets (29 AVM1 rows): 25 untestable (trace-provenance table B: `edittext_onscroller`, `movieclip_library_state_values`,
`Camera-v6..8`, `NetConnection-v6..8`, `Stage-v6..8`, `TextField-v6..8`, `ButtonEventsTest`, `ButtonPropertiesTest`,
`DefineTextTest`, `DragDropTest`, `KeyEventOrder`, `NetStream-SquareTest`, `PrototypeEventListeners`, `key_event_test`,
`loadMovieTest`, `masks_test`, `misc-mtasc.all/TextFieldTest`) and `Date-v5..v8` (FP10-variant golden). The
AVM2-VM rm rows (shumway/timeline/fonts/visual/mixed_avm, 18 with Flash goldens) belong to w1-rm-avm2.

## Mechanisms prototyped (owner functions)

All in `SWFModernRuntime/src/actionmodern/action.c` unless noted. Functions touched (sibling map):

| id | rule (FP32 evidence) | functions |
|---|---|---|
| P1 B8 `meth` | `MovieClip.prototype.loadVariables/getURL/loadMovie` are AS wrappers that always call `this.meth(method)`; a user `_root.meth` runs once per call, even with no args (gnash MovieClip.as:2251-2305, FP32 golden PASSED ×12) | new static `mcInvokeUserMeth`; `builtin_mc_getURL`; `actionCallMethod` MOVIECLIP arm, `loadMovie` and `loadVariables` branches (a user meth's numeric result also selects the loadVariables method) |
| P2 B-W | a `_width`/`_height` write resets a negative scale to positive (MovieClip.as:1517-1529: `_yscale` -50 → 50, bounds 5..15) | `mcSetEffectiveWidth`, `mcSetEffectiveHeight` (`fabs` on the previous scales; height by symmetry, unprobed) |
| P3 B-BOM | SWF6+ form loader (no codepage) drops a leading UTF-8 BOM (MovieClip.as:2209 `_root.var1 == 'val1'` from a BOM-prefixed `vars.txt`) | `avm1LoadFormIntoMC` |
| P4 B-BM | `blendMode = 0` is ignored, `= 15` is stored and reads `""` (MovieClip.as:2375-2384; Linux and Windows FP32 captures agree) | `actionSetMember` MC `blendMode` arm (renderer sees mode 15 as normal); `actionGetMemberImpl` MC `blendMode` arm |
| P5 B-BOOL | `this.__proto__.__constructor__ = Boolean; super();` in a plain function called on a MovieClip makes `Boolean.prototype.toString` answer `"false"` on it (MovieClip.as:2585-2596) | new static `mcSuperIntoNativeBoolean` (called from `actionCallFunction`'s `super` Pattern-A arm only when there is no super context); `builtin_bool_proto_toString` (NULL `this` → MC receiver) |
| P6 export frame | an ExportAssets in frame N>1 is not attachable until the playhead runs frame N (s28 `export_timing` FP32 probe) | `SWFRecomp/src/swf.cpp` `SWF::interpretTag` EXPORT_ASSETS case (emits `tagExportDeferToFrame` in tagInit + `tagExportFrameReached` in that frame's tag stream); `ng_shared.c` struct `ng_export_ent` (+`frame_pending`), `ng_register_export_entry`, new `ng_lookupExportForMovieReached`, `ng_export_set_pending`, `tagExportDeferToFrame`, `tagExportFrameReached`; `tag.h` decls; `action.c` the two attachMovie lookups only: the bare-call arm in `actionCallFunction` and the MOVIECLIP-method arm in `actionCallMethod` |
| P7 unloadClip cancel | `MovieClipLoader.unloadClip` cancels a still-queued load of the same target, as `mc.unloadMovie` does | `builtin_mcl_unloadClip` (+ forward decl of `actionCancelPendingLoadsFor`) |
| P8 EI `class` | `ExternalInterface._toAS(<class>Name</class>)` = `eval(Name)` (ExternalInterface.as:336-344) | `actionEI_toAS` |
| P9 SWF5 split | SWF5 `split` with a multi-character delimiter does not split (String.as:390-393, 441-442) | `callStringPrimitiveMethod` `split` arm |

Prototype caveats for wave 2:
- P5 is deliberately narrow: only the native `Boolean` constructor, only without a super context. The general rule
  (super() with an MC `this` and no registerClass context calls `this.__proto__.__constructor__` with the MC as
  `this`) is unmeasured; `mc.dc(Date)` already passes for an unrelated reason. Wave 2 should either keep it narrow or
  probe `Number`/`String`/user constructors first.
- P6 runs `tagExportFrameReached` on every pass through the frame (idempotent), including goto skip mode. A
  loaded child movie's exports clear by `g_current_movie_id`, with a name-only fallback; no corpus row exercises a
  child's late export. ImportAssets resolution is untouched (it reads `ng_lookupExport`).
- P4 maps mode 15 to normal for the renderer; what Flash draws for 15 is unprobed (no corpus image row sets it).
- P1 resolves `meth` through `actionGetMember` on every loadVariables/getURL/loadMovie call; the builtin meth is
  detected and skipped, so nothing changes unless a user replaced it.

## Gates (all measured on this box; before = `origin/master`, after = the prototype patch)

| gate | rows | result |
|---|---|---|
| all 79 AVM1 Flash-golden rm targets, graphics, `--recompile` | 79 | 6 rm → pass (ledger); 73 stay rm; content moved only on `ExternalInterface-v8` (-4 → -3) and `String-v5` (-14 → -8), both Flash-ward |
| avm1 argued sweep (`ls avm1 \| grep -iE 'mcl\|unload\|loadvar\|form_loader\|blend\|width\|scale\|attach_movie\|geturl\|meth\|split\|loadmovie\|load_cancel\|external_interface\|loadclip'`) | 78 | 75 pass → pass, 2 rm → rm (+1 flip counted above), `external_interface_monkeypatch` (mm) byte-identical to base |
| gnash passing neighbours (`String-v6..8`, `ExternalInterface-v6/7`, `MovieClipLoader-v5/6`, `LoadVars-v5`, `Global-v5/7/8`, `TextField-v5`, `XMLNode-v8`, `XML-v7`, `Transform-v6/7`, `misc-ming.all/loading/LoadVarsTest`) | 17 | all pass → pass |
| export-after-frame-1 SWFs (scan of every avm1/gnash/regression `test.swf` for ExportAssets past frame 1: 31 rows) | 31 | no status move; the 7 rm rows among them keep identical diffs; `ActionOrderTest3/4/5` (mm) byte-identical to base |
| attach/export re-gate after adding the method-path gate (every `avm1/*attach*`, `regression/*attach*`, the 31 export rows) | 56 | only `attach_movie_export_not_yet_run` moves (→ pass) |
| `regression/` argued subset (`ls regression \| grep -iE 'mcl\|unload\|loadvar\|form\|blend\|width\|scale\|export\|attach\|^ei_\|split\|meth\|geturl\|load\|lv_\|string\|xml\|bitmap'`, minus avm2, plus the 4 export-scan rows) | 91 | 91/91 pass |
| no-graphics (`swf_core.c` untouched; `ng_shared.c` is shared) | 8 | the 6 flips pass, `ExternalInterface-v8` / `String-v5` rm — identical to graphics |
| render canary, every `render_canary_tests.txt` member in avm1/from_gnash/regression (`render_canary.py capture` both legs, `--recompile`) | 75 tests / 97 PNGs | **97 IDENTICAL, 0 differs**, no trace or image status change |

Status totals over the 282 distinct rows of the main sweep: 199 pass → pass, 73 rm → rm, 6 rm → pass, 4 mm → mm
(content byte-identical). Not run: avm2/avmplus/shumway/misc suites (not downloaded; every edit is AVM1-only or the
recompiler's ExportAssets case, which emits nothing for exports in frame 1) and full CI. Wave 2 should dispatch CI
`categories=full` (graphics + no-graphics) because the recompiler changes.

## HOLD / NO-GO, priced (completion mechanism and the Flash capture that would decide each)

| bucket | rows | completion mechanism | deciding Flash capture |
|---|---|---|---|
| native-object enumeration (EI `_objectToXML`) | `ExternalInterface-v8` (1 line left) | `ei_objectToXML_buf` must walk the full native property list incl. DontEnum prototype members, Flash native order, functions as `<null/>`, `attributes` `<null/>` on a document node, no `idMap` | the corpus golden already is FP32; the open part is the general enumeration model — **disposition-audit sibling owns it**, no new request from me |
| P5 generality (super into natives on an MC `this`) | none extra in corpus; wave-2 scope | keep P5 narrow (Boolean only) or generalise to `Number`/`String`/user ctors | **FLASH request 1** (`avm1_mc_super_native_probe`) |
| P2 `_height` symmetry, P4 blendMode 15/16/255 | none extra in corpus | P2 height arm and P4 16+ are by symmetry / extrapolation | FLASH request 1 (H and B sections) |
| `LoadBitmapTest` transparent | 1 | thread "source bitmap has alpha" (DefineBitsLossless2 / JPEG3 vs JPEG2 / Lossless) from `SWFRecomp/src/swf.cpp` bitmap cases through `ng_registerBitmapMetadata` (`tag.c`, `tag_stubs.c`) to `bitmapDataLoadBitmap`; plus `this` = a level → undefined | FLASH request 2 (needs a fixture with a Lossless2 opaque bitmap; not built: our SWF assembler has no bitmap tags) |
| `matrix_test` rotation exactness | 1 | either compute `_rotation`/`_yscale` matrices in double, or snap ±90/180 | FLASH request 3 (trace `transform.matrix` after `_rotation` = 30/45/90/180 and `_yscale` sign flips; AS-only, fixture not built) |
| `zeroframe_definesprite` | 1 | DefineSprite header frame count drives `_totalframes`/`_framesloaded`; `_currentframe` 0 for 0 frames | none (golden is FP32); M because the recompiler clamps sprite frame counts to the ShowFrame count |
| `InitActionTest` | 1 | emit DoInitAction inline at its tag position instead of the frame prologue (`swf.cpp` DO_INIT_ACTION `current_frame_init_actions`) | none (golden is FP32); M-L because every SWF with a DoInitAction after a same-frame PlaceObject moves — a tag-order scan sizes it first |
| B12 `Object-v6..v8` | 3 | addProperty on a watched name fires the watcher; its return becomes the getter/setter's underlying value (Object.as:790-840) | none needed (FP32 golden) |
| B18 `LoadVars-v6..v8` | 3 | 2nd `load()` from inside `onLoad` returns false; `loaded` not an own prop | none needed |
| B20a `array-v5..v8` | 4 | `c.length == 3` (array.as:444), `a.length == 4` (:1394), for-in order of own `sort`/`length` | none needed |
| B17 `Inheritance-v6..v8` | 3 | `super` re-resolves through the receiver's live `__proto__` chain on every call (Inheritance.as:250-340) | none needed |
| `XML-v8` extra onLoad block | 1 | — | s28 LOCAL ORACLE REQUEST 2 (still unanswered in `w1-local-oracles/`) |

## New unclaimed leads

1. **P5 is a symptom of a missing MC super context.** `super()` from any plain function called on a MovieClip is a
   no-op in our runtime (`actionCallFunction` Pattern A requires `hasSuperContext()`, which only registerClass
   constructors and object `new` set). The probe's `U(7)` row shows `u=undefined` for a user constructor too. If FP32
   prints `u=7`, the general fix (push a super context with the MC for method calls, or resolve
   `this.__proto__.__constructor__` on demand) is the real wave-2 item and may move other rows.
2. **The ASnative/getURL `meth` idiom generalises.** Flash's AS-implemented MovieClip methods (`loadVariables`,
   `getURL`, `loadMovie`) call user-replaceable helpers; P1 covers `meth`. Other AS-wrapper natives that consult
   overridable members (e.g. `MovieClip.prototype.getURL` → `this.meth`, `LoadVars.load` → `this.onData`?) may hide
   more Flash-only behaviour; unaudited.
3. **Exports in later frames are common in gnash SWFs** (31 corpus SWFs, scan in §Gates). Now that attachMovie
   honours the frame, the Sound export lookups (`ng_lookupExport` callers in `action.c`, e.g. the sound-duration path) and `BitmapData.loadBitmap`
   (`bitmapDataLoadBitmap`) still see a not-yet-reached export. Whether Flash gates those too is unprobed.
4. **SWF5 split** now treats a multi-char delimiter like the empty one; gnash String.as:340-375 (SWF6 block) has more
   limit/undefined edge rules we already pass. No further SWF5 split rows in the corpus.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session29-fanout-reports/w1-rm-avm1-gnash-fixtures/avm1_mc_super_native_probe/test.swf` (SWF8), trace,
   2 frames, direct pinned.** Build: `python3 create_test_swf.py test.swf 8` (stdlib only; `avm1asm.py` alongside).
   Compare against `output.ours-prototype.txt` (prototype) and `output.ours-base.txt` (origin/master). Sections:
   `S` super() into Boolean(false/true)/Number(5)/String("str")/user `U(7)` on five MCs, read back through each
   native toString/valueOf and `u` (decides P5's scope and lead 1); `H` `_height`/`_width` writes after negative
   scales (decides P2's height arm); `B` blendMode 15/16/255/0/1/14 after "multiply" (decides P4 past 15).
2. **FLASH (fixture not built): `BitmapData.loadBitmap` transparency.** A SWF8 with three exported bitmaps —
   DefineBitsJPEG2, DefineBitsLossless (24-bit), DefineBitsLossless2 fully opaque — tracing
   `BitmapData.loadBitmap(name).transparent` for each. Decides `LoadBitmapTest` line 1 (golden already says JPEG2 =
   false) and whether "has an alpha channel" or "has a non-opaque pixel" is the rule.
3. **FLASH (fixture not built, AS-only): rotation matrix exactness.** `createEmptyMovieClip`, then for `_rotation` in
   30, 45, 90, -90, 180 trace `transform.matrix`; then `_rotation = 0; _yscale = -100;` trace. Decides `matrix_test`
   (snap vs double precision).
