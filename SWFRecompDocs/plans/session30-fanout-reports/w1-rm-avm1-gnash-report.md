# s30 w1-rm-avm1-gnash: AVM1/gnash `ruffle_matched` rows re-priced against FP32, cheapest rules prototyped

Wave 1 (diagnosis + measured prototype). Cloud worker, branch `fanout/w1-rm-avm1-gnash` from `origin/master` `f4edebdc`
(code = s30 baseline `2d40d3799` lineage). SETUP_STATUS: apt / Pillow / Dawn all OK. Corpus:
`download_tests.sh avm1 from_gnash from_shumway timeline visual fonts` (upstream Ruffle master `66f9073de`, `ls-remote`
at download time; the script prints no SHA), flash-fixes APPLIED 64. Gnash sources read from a fresh clone of
`git.savannah.gnu.org/git/gnash.git`. All measurements `--mode=graphics` on cloud lavapipe unless stated; every
before/after number below was measured on this box (before = `origin/master`, after = the prototype patch).

**New files** (all under `session30-fanout-reports/`):
- `w1-rm-avm1-gnash-report.md` (this file)
- `w1-rm-avm1-gnash-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; 2 files: `action.c`, `tag.c`)
- `w1-rm-avm1-gnash-fixtures/avm1_asnative_mc_probe/` (`create_test_swf.py`, `avm1asm.py` copied from
  `regression/avm1_mc_super_native_probe`, `swf5.swf`, `swf6.swf`, `output.ours-prototype.swf{5,6}.txt`): FLASH request 1
- `w1-rm-avm1-gnash-fixtures/embeddedfont_smalltext_probe/` (`make_variants.py`, `smalltext_on.swf`, `smalltext_off.swf`):
  FLASH request 2

## Verdicts (lead)

**GO (wave 2): 5 rules, measured, +11 `ruffle_matched → pass` (graphics AND no-graphics), 0 status moves and 0 content
moves on every other row of a 648-row gate** (93-row pool + 288 argued neighbours + 267 SWF5/regression rows; §Gates).
All 11 are `known_failure = true` upstream (Ruffle fails them) and every golden is FP32 (s28 `trace-provenance.md`
table A: "golden = Flash").

| # | row | before (graded golden) | after | rule |
|---|---|---|---|---|
| 1 | `from_gnash/actionscript.all/setProperty-v5` | rm, -15/+6 (`output.fp10.txt`) | **pass** | R1 + R2 + R3 |
| 2 | `from_gnash/actionscript.all/setProperty-v6` | rm, -16/+7 | **pass** | R1 |
| 3 | `from_gnash/actionscript.all/setProperty-v7` | rm, -16/+7 | **pass** | R1 |
| 4 | `from_gnash/actionscript.all/setProperty-v8` | rm, -16/+7 | **pass** | R1 |
| 5 | `from_gnash/actionscript.all/Object-v6` | rm, -8/+8 (`output.fp18-20.txt`) | **pass** | R4 (B12) |
| 6 | `from_gnash/actionscript.all/Object-v7` | rm, -8/+8 | **pass** | R4 |
| 7 | `from_gnash/actionscript.all/Object-v8` | rm, -8/+8 | **pass** | R4 |
| 8 | `from_gnash/actionscript.all/LoadVars-v6` | rm, -6/+2 | **pass** | R5a + R5b (B18) |
| 9 | `from_gnash/actionscript.all/LoadVars-v7` | rm, -6/+2 | **pass** | R5a + R5b |
| 10 | `from_gnash/actionscript.all/LoadVars-v8` | rm, -6/+2 | **pass** | R5a + R5b |
| 11 | `from_gnash/misc-swfmill.all/zeroframe_definesprite` | rm, -2/+2 | **pass** | R6 |

Flash-ward line moves without a flip: none kept (Sound-v5 is unchanged: see B20c below).

**Rules (one line each; full mechanism in §Mechanisms):**
- **R1** `ASnative(900, n)` / `ASnative(901, n)` = the MovieClip.prototype natives (gnash `MovieClip_as.cpp:207-255`
  table); a native MC stub held under another name (`createSprite = ASnative(901,0)`, `_root.mk = …`,
  `mc.gd = MovieClip.prototype.getDepth`) runs its builtin arm on the receiver; a stub delegated from a function VALUE
  is not SWF5/6-version-hidden.
- **R2** SWF5 (non-closure) method call: the base clip is the receiver (Ruffle `function.rs:303-309` `this_do`), so
  `setTarget("")` inside it returns to the receiver.
- **R3** `removeMovieClip("")` (ActionRemoveSprite, empty path) targets the current target clip (Ruffle
  `action_remove_sprite` → `resolve_target_display_object`); in SWF6+ that is `_root` (not removable, no-op).
- **R4** (s28 B12) `addProperty` of a watched name that does not exist fires the watcher once (name, undefined,
  undefined, userData; this = obj); its return becomes the getter/setter's underlying value.
- **R5a** (B18) `LoadVars.sendAndLoad` into a target that INHERITS a `loaded` accessor (an XML) writes through the
  setter, no own `loaded`. **R5b** `XML.prototype.load` borrowed by a non-XML receiver loads and delivers through the
  receiver's `onData` (Ruffle returns false: RvF candidate).
- **R6** a sprite's own frame-1 DoAction and its `onClipLoad` see the DefineSprite HEADER counters
  (`_framesloaded = _totalframes = declared`, `_currentframe = 0` for 0 frames) even though they run before
  `process_sprite_init_at_depth`.

**Premise refutations (brief task 2):**
- **"B20b setProperty in tellTarget" is a symptom label, and the bucket was not M.** All 4 `setProperty-v5..v8` rows lose
  their first 6 and last 3-7 checks because `createSprite = ASnative(901, 0); createSprite("mc1", 10)` (setProperty.as:30)
  made no clip: `builtin_asnative` had no class 900/901. One S rule (R1) flips v6-v8; v5 additionally needs R2 + R3.
  No setProperty/tellTarget code was touched.
- **"device-font metrics family on the AVM1 side": refuted for 2 of the 4 rows.** `fonts/device_font_no_ink` and
  `visual/edittext/edittext_device_transform_metrics` (and `_negative`) are **AVM2** SWFs (FileAttributes AS3 bit; SWF
  9 and 41): they belong to w1-rm-avm2. Every shumway / timeline / visual / fonts / mixed_avm rm row in the s30 list is
  AVM2 (scanned all 20), so my pool is 98 avm1 + gnash rows minus 5 sibling rows = **93**.
- **"EmbeddedFontTest is really a DefineFont3 advance-scale bug?": refuted.** Its font is **DefineFont2** (tag 48,
  flags `0xa4` = HasLayout | **SmallText** | WideCodes), not DefineFont3. The real rule is cheaper to state and exact:
  FP32's `textWidth` = **Σ ceil(advance × 12/1024) per glyph** — it reproduces all 12 golden widths exactly
  (46, 78, 230, 156, 186, 194, 247, 222, 148, 99, 86, 86; ours = the unrounded sum 43.6, 73.0, 215.1, …). Its scope
  (SmallText fonts only, or every embedded font) decides the price: FLASH request 2.
- **"B8 loadVariables meth (S, 0 standalone)"**: already landed in s29 (P1, `mcInvokeUserMeth`); the 4 MovieClip rows
  pass. No row in the s30 pool is owned by B8 any more.
- **"B19 hidden setter walk (S-M)"**: its only row, `Global-v6`, is not in the s30 rm list (it passes at baseline). Bucket
  closed upstream of me; no work.

## Rows (all 93 pool rows; graphics, measured at base on this box)

`d` = content diff vs the graded golden (`-golden/+ours`). Every row was `ruffle_matched` at base (93/93), matching the
s30 baseline list. "Δ s29" names a price that changed since the s29 table.

| row | d (base) | one-line diff | owner mechanism | price | Δ s29 | status after |
|---|---|---|---|---|---|---|
| `actionscript.all/setProperty-v5` | -15/+6 | first block missing, `mc2` not removed, `/mc3` | R1 + R2 + R3 | S | was M (B20b, wrong owner) | **pass** |
| `actionscript.all/setProperty-v6..v8` (3) | -16/+7 | `createSprite` made no clip | R1 | S | was M | **pass** ×3 |
| `actionscript.all/Object-v6..v8` (3) | -8/+8 | watch + addProperty | R4 (B12) | S | was M | **pass** ×3 |
| `actionscript.all/LoadVars-v6..v8` (3) | -6/+2 | XML target own `loaded`; borrowed `XML.prototype.load` false | R5a + R5b (B18) | S | was M ("re-entrancy" was the wrong label: it is the borrowed XML loader) | **pass** ×3 |
| `misc-swfmill.all/zeroframe_definesprite` | -2/+2 | `a11b11c11d111` | R6 | S | was M (the recompiler already emits the header count; the bug is read order) | **pass** |
| `actionscript.all/Sound-v5` | -14/+14 | Sound bound by path (76/80 vs 100; `undefined` after unload) | B20c + SWF5 visibility after `MovieClip.prototype.createEmptyMovieClip = ASnative(901,0)` (bare call of the assigned name stays hidden at SWF5: probe B) | M | partly (R1 is half of it) | rm |
| `misc-ming.all/EmbeddedFontTest` | -27/+27 | `textWidth` 43 vs 46 … (12 lines) | per-glyph ceil advance (exact, above); needs a SmallText flag from the recompiler font case to the TextField metrics | S-M after FLASH req 2 | was M-L | rm |
| `actionscript.all/Function-v5` | -4/+4 | `Email.constructor.toString()`; `Email.prototype.__constructor__` | two rules: SWF5 `new` sets no `__constructor__` (S) + B6 SWF5 Function visibility (M) | M | — | rm |
| `actionscript.all/toString_valueOf-v5` | -12/+12 | SWF5 TextField proto; fn prim | B6 | M | — | rm |
| `actionscript.all/String-v5` | -8/+8 | `chr`/`ord` bytes | B7 | M-L | — | rm |
| `actionscript.all/XML-v5` | -9/+9 | nbsp byte; BOM/codepage | B7 | M-L | — | rm |
| `actionscript.all/XML-v8` | -0/+21 | we deliver gnash.xml onLoad, FP32 printed none | s28 oracle question 2 (still open) | ? | — | rm |
| `actionscript.all/array-v5..v8` (4) | -5/+5, -6/+6 | `c[2.2]` length (SWF<7), `addProperty('3')` length, for-in after `sort` | B20a: 3 rules; the for-in order after a native `sort` on a fake array is the hard one and every row needs it | M | — | rm |
| `actionscript.all/Inheritance-v5` | -0/+1 | Flash hangs (truncated golden) | B17 | NO-GO | — | rm |
| `actionscript.all/Inheritance-v6..v8` (3) | -8/+9, -4/+5 | `A.B.B`, `FAAC`, `undefinedFFC` | B17 super re-resolution through the receiver's live chain | M-L | — | rm |
| `actionscript.all/Transform-v8` | -7/+7 | colorTransform clamp lines; cached `_xscale` after matrix write | B20f | M | — | rm |
| `actionscript.all/BitmapData-v8` | -8/+8 | `draw()` edge pixels | B20d | M | — | rm |
| `actionscript.all/HitTest-v8` | -3/+3 | `hitTest(41,25,true)` | B13 (w1-drift-smalls family) | M | — | rm |
| `misc-ming.all/DrawingApiTest` | -1/+1 | curve-edge `hitTest` | B13 | M | — | rm |
| `actionscript.all/ASnative-v5..v8` (4) | -34..39 | Date/Stage natives by id | B16 ASnative id table (R1 adds 900/901 only; 103 Date ctor-by-id is the bulk) | L | — | rm |
| `actionscript.all/Math-v5..v8` (4) | -5/+5 | platform split | B16b (Linux FP32 == ours) | disposition | — | rm |
| `actionscript.all/Microphone-v6..v8` (3), `Camera-v6..v8` (3), `NetConnection-v6..v8` (3), `Stage-v6..v8` (3), `TextField-v6..v8` (3) | — | device / host | untestable (TP table B) | — | — | rm |
| `actionscript.all/MovieClipLoader-v7`, `-v8` | -115/+0 | local MEDIA loadClip | B16 (Windows golden) | L | — | rm |
| `actionscript.all/Date-v5..v8` (4) | -6/+6 | FP10-variant golden | not a target | — | — | rm |
| `actionscript.all/TextFormat-v7`, `-v8` | -38, -36 | device-font `getTextExtent` | B14 device metrics | L | — | rm |
| `misc-ming.all/TextSnapshotTest` | -81/+81 | selection API | B15 | M-L | — | rm |
| `misc-ming.all/callFunction_test` | -6/+6 | `mc1:func` paths | B20g path-qualified CallFunction | M | — | rm |
| `misc-ming.all/displaylist_depths/displaylist_depths_test` | -7/+7 | depth 1048576 / 2130690045 / -30000 | B20g depth-range rules (3 lines, 3 ranges) | M | — | rm |
| `…/displaylist_depths_test2`, `_test3` | -7/+7 | `static3 onClipConstruct` re-run | B20g static re-construct on rewind (exec-order adjacent) | M | — | rm |
| `misc-ming.all/duplicate_movie_clip_test` | -4/+4 | `MovieClip.prototype.duplicateMovieClip` on a **button** | button duplication (needs a button clone, initObj ignored) — the R1 redirect is deliberately not applied to buttons | M | was S-M | rm (byte-identical) |
| `misc-ming.all/init_action/InitActionTest` | -4/+4 | init action order | DoInitAction at tag position | M-L | — | rm |
| `misc-ming.all/loading/LoadBitmapTest` | -2/+2 | JPEG `transparent`; level-`this` `func('img1')` | two rules, one needs a bitmap-format flag from the recompiler | M | — | rm |
| `misc-ming.all/loop/loop_test6`, `loop_test7` | -4/+4, -1/+0 | goto-rewind construct count / unload | exec-order family (frame loops: w1-exec-order files) | M | — | rm |
| `misc-ming.all/path_format_test` | -7/+7 | `x1 == 'mc11_frame4'` | path/goto family | M | — | rm |
| `misc-ming.all/register_class/registerClassTest2` | -6/+6 | onLoad order | registerClass onLoad order | M | — | rm |
| `misc-ming.all/replace_buttons1test` | -3/+3 | `typeof(static1.name)` after backward goto | button re-instantiated on goto-rewind replace | M | was S-M (unread) | rm |
| `misc-ming.all/masks_test` | -16/+16 | mask `hitTest` | B13 / masks | M | — | rm |
| `misc-mtasc.all/levels` | -15/+15 | `_level5.swapDepths(10)` → `_level16394` | level re-keying | M | — | rm |
| `misc-swfc.all/movieclip_destruction_test1` | -12/+12 | `__proto__` after destruction | destruction lifetime | M | — | rm |
| `misc-swfc.all/registerclass_test3` | -12/+12 | `player.movie` undefined | registerClass + attach | M | — | rm |
| `misc-mtasc.all/TextFieldTest` | -1/+1 | height 17.05 vs 20.3 | device font | untestable | — | rm |
| `avm1/target_paths/swf5`, `/swf6` | -163/+127 | debug-player coercion lines + paths | debugger-line policy + path eval | L | — | rm |
| `avm1/asnative_instrument` | -88/+0 | NetConnection ASnative | L (Windows FP32) | L | — | rm |
| `avm1/edittext_onscroller`, `movieclip_library_state_values` | -2 | input / `_xmouse` | untestable | — | — | rm |
| `misc-ming.all/ButtonEventsTest`, `ButtonPropertiesTest`, `DefineTextTest`, `DragDropTest`, `KeyEventOrder`, `NetStream-SquareTest`, `PrototypeEventListeners`, `key_event_test`, `loading/loadMovieTest` | — | mouse/key/stream | untestable (TP table B) | — | — | rm |

Not in my pool (sibling-owned): `ExternalInterface-v8` (w1-native-table), `action_execution_order_test`, `_test6`,
`misc-swfc/action_execution_order_test10`, `loop_test10` (w1-exec-order).

## Mechanisms prototyped (owner functions)

All in `SWFModernRuntime/src/actionmodern/action.c` unless noted. **Functions touched:**

| rule | functions |
|---|---|
| R1 | `builtin_asnative` (new class 900/901 arm); new `actionMCNativeByASnativeId` (name table from gnash `MovieClip_as.cpp`, resolves to the existing `g_mc_method_funcs` stub; ids whose method has no stub keep `asnativeUnknownMinor`); `cfDelegateToMCMethod` + new file-static `g_mc_delegate_from_value`; `actionCallMethod` MOVIECLIP arm: (a) the `mcArmVersionHidden` gate and (b) the `createEmptyMovieClip` SWF5 gate both skip when the call came from a function value, (c) `_mc_user_dispatch`: a `g_mc_method_funcs` stub found under a different name re-dispatches to its own arm via `cfDelegateToMCMethod` (not for buttons, not for the timeline-nav names) |
| R2 | `ClosureFrame` (+ trailing `saved_base`, `base_set`), `enterClosureFrame` (`CF_CTX_RECEIVER` branch also sets `g_base_clip` = receiver), `leaveClosureFrame` (restores it) |
| R3 | `actionRemoveSprite` (empty STRING target → `g_current_context` when it is not `_root`) |
| R4 | new static `addPropertyFireWatcher`; called from `builtin_object_addProperty` and from `actionCallMethod`'s OBJECT `addProperty` arm (the array arm is untouched) |
| R5a | `builtin_loadvars_sendAndLoad` |
| R5b | `builtin_xml_load` (non-XML receiver allowed; XML status/loaded slots only for XML), `aq_dispatch_xml_load` (DOM reset only for XML) |
| R6 | `SWFModernRuntime/src/libswf/tag.c`: new static `sync_sprite_counters_pre_init`; called from `exec_sprite_frame` and `aq_dispatch_clip_load` |

Sibling map: I did **not** touch `setupNativeFuncOwnProps` or any native member/flag table (w1-native-table);
`builtin_asnative` is the id→function dispatch, but w1-native-table should know R1 adds the 900/901 classes there.
`exec_sprite_frame` / `aq_dispatch_clip_load` (`tag.c`) and `actionCallMethod` are browser-ladder-adjacent files; the
edits are local (one call / one gate each). No `action_queue.c`, `swf.c`, `swf_core.c`, `tag_stubs.c` or recompiler edit.

Prototype caveats for wave 2:
- **R1 identity**: `ASnative(901,0) == MovieClip.prototype.createEmptyMovieClip` is `true` with the prototype (same
  stub object, as our 100/101/200/252 classes already do). The `asnative_sweep` comment says Flash hands out a fresh
  object per call; probe section D asks FP32.
- **R1 SWF5**: probe A passes in SWF5 (bare call of a variable holding the native). Probe B (SWF5 bare call of the name
  after `MovieClip.prototype.createEmptyMovieClip = ASnative(901,0)`) still yields nothing: our SWF5 lookup keeps the
  version-hide flag on the reassigned prototype member. Sound-v5 needs B to work (FP32 golden) — Ruffle keeps the flag
  too (`script_object.rs` set_local keeps attributes), so FP32 clears/ignores it on SetMember. Not changed here: the
  property-flag write model is w1-native-table's area and needs the probe first.
- **R1 generality**: the stub-under-another-name redirect (`_root.mk(...)`, probe C/E) is broader than the 4 rows need;
  the gate shows no other row exercises it.
- **R2** applies only on the `CF_CTX_RECEIVER` path (v5 caller, MOVIECLIP receiver). A v5 call with a plain-object
  receiver keeps the caller's base clip (Ruffle: `this_do` falls back to the caller's target — same).
- **R3** has no post-removal "revert target to base clip" step (Ruffle `action_remove_sprite:1948`); no corpus row
  removes its own running target that way.
- **R4** fires only for a watcher on an OBJECT receiver (`g_watch_table[].obj`), not on MovieClip/timeline watches, and
  only when the property was created by this call (Object.as:810-815 pins "existing name: no watcher").
- **R5b** on a plain Object receiver (no `onData`) is unprobed; it now returns true and fires nothing.

## Gates (all measured on this box; before = `origin/master`, after = the prototype patch)

| gate | rows | result |
|---|---|---|
| full pool (every s30 AVM1/gnash rm row I own) | 93 | 11 rm → pass (ledger); 82 rm → rm, **content byte-identical to base** on all 82 |
| argued neighbours: avm1 `grep -iE 'asnative\|watch\|addprop\|loadvars\|xml\|remove\|settarget\|target\|swf5\|v5\|frames\|sprite\|create_empty\|zero\|getter\|setter\|sendandload\|scope\|base_clip\|with'`; regression same + `accessor\|mc_method\|delegate`; gnash `actionscript.all` `XML*`, `XMLNode*`, `LoadVars*`, `Object*`, `with*`, `getvariable*`, `MovieClip*`, `Sound*`, `Global*`, `Function*`, `ASnative*`, `Selection*`, `TextField*`, `enumerate*`, `case*`, `swap*`, `duplicate*`, `Instance*`, `prototype*`, `delete*`; all `misc-swfmill.all`; all `misc-ming.all/loading/*`; `misc-ming.all` `sprite\|frame\|remove\|target\|clip\|place` | 288 | 287 pass → pass, 1 output_mismatch → output_mismatch (baseline status from the CI results JSON at `origin/master`) |
| every SWF5 AVM1 row in avm1/gnash/regression (110, by header version) + every AVM1 `regression/` row (260), not already above | 267 | **267 pass → pass** (aimed at R2: every v5 method call now carries the receiver as base clip) |
| no-graphics (`tag.c` change; the rest is shared) | 15 | the 11 flips pass, `Sound-v5` / `duplicate_movie_clip_test` rm (byte-identical to graphics), `asnative`, `asnative_sweep` pass |
| duplicate_movie_clip_test after the button exclusion | 1 | byte-identical to base (the first after-leg moved it rm → mismatch; fixed by the `!mc->is_button_mc` gate) |

Not run: avm2/avmplus/shumway-AVM2/misc suites (every edit is an AVM1 builtin or an AVM1 clip-counter path) and the
render canary (no renderer edit). Wave 2 should still dispatch CI `graphics` (+ no-graphics on the final run: `tag.c`).

Gate totals: **648 distinct rows**, 11 rm → pass, 0 other status moves, and every pool row outside the ledger is
byte-identical to base. The button exclusion in R1 (added after the 288-row leg to fix `duplicate_movie_clip_test`)
only narrows the redirect; the 267-row leg ran with it. Totals were read from the per-test JSON of each leg, not quoted.

## HOLD / NO-GO, priced (updates the s29 table; completion mechanism + deciding capture)

| bucket | rows | completion mechanism | deciding capture |
|---|---|---|---|
| EmbeddedFontTest per-glyph ceil | 1 (+ any embedded-font `textWidth` row if the rule is general) | recompiler font case (`swf.cpp` DefineFont2/3 flags, next to `font_bold_flags`) emits the SmallText bit; TextField `textWidth` sums `ceil(advance_px)` per glyph for those fonts | **FLASH request 2** (SmallText on/off variants of the corpus SWF): if OFF also ceils, the rule is every embedded font and every Ruffle-golden embedded `textWidth` pass must be re-priced first |
| Sound-v5 | 1 | (a) SWF5 bare-name lookup of a reassigned version-hidden prototype member (probe B); (b) B20c: `new Sound(clip)` binds by target path — `getVolume()` undefined once the clip is removed, rebinds at 100 to a new same-named clip | **FLASH request 1** section B; (b) needs none (FP32 golden) |
| Function-v5 | 1 | SWF5 `new` sets no `__constructor__` (S) + B6 Function/Function.prototype SWF6-flag visibility (`Email.constructor.toString()` undefined) | none (FP32 golden); B6 is the M part |
| B6 SWF5 function `__proto__` visibility | `Function-v5`, `toString_valueOf-v5` | as s28 B6 | none |
| B20a array | 4 | `c[2.2]` → length 3 in SWF<7; `addProperty('3')` on an array extends `length`; for-in order of a fake array after native `sort` (`5,4,2,1,0,sort,length,7,6,3,` v7+) | none (FP32 golden); the sort enumeration order is the blocker in every row |
| LoadBitmapTest | 1 | bitmap "has alpha" flag from `swf.cpp` bitmap cases through `ng_registerBitmapMetadata`; `func('img1')` with `this` = a level → undefined | s29 FLASH request 2 (fixture still not built) |
| duplicate_movie_clip_test | 1 | duplicate of a Button = a Button (typeof object, `_level0.buttdup`), initObj ignored | none (FP32 golden) |
| replace_buttons1test | 1 | a backward goto re-instantiates a button the forward timeline replaced (dynamic `name` gone) | none |
| levels | 1 | `_levelN.swapDepths(d)` re-keys the level to `_level(d+16384)` | none |
| displaylist_depths_test | 1 | depth-range rules for dynamic placement at 1048576 / 2130690045 / -30000 | none |
| B17 Inheritance-v6..v8 | 3 | super re-resolution | none |
| XML-v8 extra onLoad | 1 | — | s28 LOCAL ORACLE REQUEST 2 (still unanswered) |
| loop_test6/7, displaylist_depths_test2/3, registerClassTest2, InitActionTest, path_format_test | 7 | goto-rewind / init-order family | w1-exec-order's frame-loop model first |

## RvF entries to append at wave 2 (not appended here: wave-1 commits only report files)

1. **`XML.prototype.load` on a non-XML receiver** — gnash `LoadVars-v6..v8` (LoadVars.as:195-197, 183). FP32: returns
   `true` and the receiver's `onData` (LoadVars: decode + `onLoad`) runs. Ruffle (`xml.rs:414`) returns `false` and
   loads nothing; its golden prints `FAILED: expected: true obtained: false`. Decision: match Flash (R5b).
2. **SetMember on a version-hidden prototype member in SWF5** (Sound-v5 / setProperty.as:30 idiom) — pending FLASH
   request 1 section B; Ruffle keeps the hide flag.

## New unclaimed leads

1. **ASnative id coverage beyond 900/901.** The native-id table (`builtin_asnative`) still lacks Date-by-id (103
   ctor/statics: the bulk of `ASnative-v5..v8`), Stage, SharedObject, TextField (104), Sound (500). A table generated
   from gnash's `vm.getNative(...)` registrations (grep `getNative(` in `libcore/asobj/*.cpp`) would map each id to the
   member we already implement; w1-native-table's generator could emit it.
2. **R2 is a general SWF5 base-clip rule.** Any v5 `mc.method()` that runs `setTarget("")`, `tellTarget("")`,
   `removeMovieClip("")` or reads a base-clip-relative path now resolves on the receiver; the 267-row SWF5/regression
   gate saw no other mover, so the corpus barely exercises it. A small FP32 fixture (SWF5: `mc.f()` doing
   `setTarget(""); trace(_target)` and `gotoAndStop` inside `tellTarget("")`) would pin it.
3. **EmbeddedFontTest's ceil rule may be the general Flash embedded-glyph advance snap** (SmallText fonts render
   pixel-aligned). If FLASH request 2 says "all embedded fonts", also check `getTextExtent` / `_width` autosize rows.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session30-fanout-reports/w1-rm-avm1-gnash-fixtures/avm1_asnative_mc_probe/` `swf5.swf` and `swf6.swf`,
   trace, 1 frame, direct pinned.** Build: `python3 create_test_swf.py swf5.swf 5; python3 create_test_swf.py swf6.swf 6`
   (stdlib only). Compare against `output.ours-prototype.swf{5,6}.txt`. Sections: A bare call of a variable holding
   `ASnative(901,0)`; **B** SWF5 bare call of `createEmptyMovieClip` after assigning `ASnative(901,0)` onto
   `MovieClip.prototype` (decides Sound-v5's half and the SetMember-on-hidden-member rule); C call through an own
   property `_root.mk`; **D** identity `ASnative(901,0) == MovieClip.prototype.createEmptyMovieClip` and between two
   ASnative calls; E `ASnative(900,10)` (getDepth) borrowed as `a3.gd`; F a bare `cs("inner",1)` inside a method of
   `a3` (which clip it lands on, per version).
2. **FLASH: `session30-fanout-reports/w1-rm-avm1-gnash-fixtures/embeddedfont_smalltext_probe/` `smalltext_on.swf` and
   `smalltext_off.swf`, trace, the corpus row's frames (`num_ticks` of `EmbeddedFontTest`), direct pinned.** Build:
   `python3 make_variants.py <ruffle-tests>/tests/swfs/from_gnash/misc-ming.all/EmbeddedFontTest/test.swf .`.
   `smalltext_on` must reproduce the corpus golden (sanity). Compare the 12 `textWidth` values of `smalltext_off`
   against the golden: equal → the per-glyph ceil applies to every embedded font; different (expected near the
   unrounded sums 43.6, 73.0, 215.1, 145.4, 173.1, 181.7, 230.4, 207.5, 137.8, 92.0, 79.6, 79.6) → SmallText only.
