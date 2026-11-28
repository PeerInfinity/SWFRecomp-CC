# s30 w2-rm-avm1-gnash-land: R1–R6 landed, plus ASnative identity, Sound-v5 and EmbeddedFontTest (+13 rm → pass)

Wave 2 (implementation). Cloud worker, branch `fanout/w2-rm-avm1-gnash-land`. Final base: `origin/master` `74e5f4cb`
(contains s30 batch 2 `a18a0e03`, w1-exec-order `17bc522d` and browser-nested-swapdepths `92f7d5e8`). SETUP_STATUS:
apt / Pillow / Dawn all OK. Corpus: `download_tests.sh avm1 from_gnash fonts text visual swf timeline from_shumway`
(upstream Ruffle master `66f9073de` at download time, from `ls-remote`), flash-fixes applied. Everything was measured on
this box with `--mode=graphics` on cloud lavapipe unless a row says otherwise. Every leg used `--recompile`, because
the recompiler changed.

**New files:**
- `SWFRecompDocs/plans/session30-fanout-reports/w2-rm-avm1-gnash-land-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-rm-avm1-gnash-land.patch` (`git diff --binary origin/master` over
  `SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt` + the 2 fixture dirs;
  apply with `git apply` (binary hunks for `test.swf`); `git apply --check -R` passes on the branch and `git apply
  --check` passes on `origin/master` `74e5f4cb`)
- `ruffle-tests/tests/swfs/regression/avm1_asnative_mc_probe_swf5/` (`test.swf`, `output.txt`, `test.toml`,
  `create_test_swf.py`, `avm1asm.py`): the w1 probe at SWF5. Its golden is **FP32** (`swf5.lnx.txt` from
  `w1-local-oracles/w1-rm-avm1-gnash/`). `test.swf` is byte-identical to `create_test_swf.py test.swf 5`.
- `ruffle-tests/tests/swfs/regression/avm1_asnative_mc_probe_swf6/` (same files): the probe at SWF6, golden **FP32**
  (`swf6.lnx.txt`).

Edited docs (not in the patch): `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (3
entries appended at EOF) and `ruffle-tests/tests/swfs/regression/README.md` (2 rows).

## Verdicts (lead)

**GO, landed: +13 `ruffle_matched → pass` in graphics AND no-graphics, plus 2 new FP32 regression fixtures passing.
0 other status moves and 0 content moves on an 860-row gate (845 rows byte-identical before vs after). The render
canary is 231/231 md5-identical.**

| item | result |
|---|---|
| 1. R1–R6 as measured | **GO**: the 11 w1 rows rm → pass, byte-identical to the w1 prototype's outputs |
| 2. ASnative identity (FP32 §D) | **GO**: at SWF6+ every call returns a fresh wrapper; SWF5 keeps the shared stub. Costs no row. Pinned by `regression/avm1_asnative_mc_probe_swf6` |
| 3. Sound-v5 | **GO, full**: `from_gnash/actionscript.all/Sound-v5` rm → pass (100/100, byte-identical to FP32). Two rules: SetMember clears the native hide flag (FP32 §B), and SWF5 loses the Sound binding through deferred removal |
| 4. EmbeddedFontTest | **GO, full**: `from_gnash/misc-ming.all/EmbeddedFontTest` rm → pass (87/87). It needed the SmallText per-glyph ceil plus one more rule: `tf10._x` read off a scaled text field is whole twips |
| 5. Function-v5 (optional) | **HOLD, not landed.** The S part (SWF5 `new` sets no `__constructor__`) fixes 1 of the row's 2 diff lines. The row stays rm without B6, and the S part touches about 10 `new` sites. Priced below |

## EXPECTED-FLIP LEDGER (CI: graphics AND no-graphics; `tag.c` and `ng_shared.c` are shared)

Trace axis, rm → pass (every golden is FP32: s28 trace-provenance table A, "golden = Flash"; all are `known_failure =
true` upstream):

| # | row | before (box) | after (box) | rule |
|---|---|---|---|---|
| 1 | `from_gnash/actionscript.all/setProperty-v5` | rm 3/52 | **pass** 52/52 | R1+R2+R3 |
| 2 | `from_gnash/actionscript.all/setProperty-v6` | rm 3/52 | **pass** | R1 |
| 3 | `from_gnash/actionscript.all/setProperty-v7` | rm 3/52 | **pass** | R1 |
| 4 | `from_gnash/actionscript.all/setProperty-v8` | rm 3/52 | **pass** | R1 |
| 5 | `from_gnash/actionscript.all/Object-v6` | rm 325/333 | **pass** | R4 |
| 6 | `from_gnash/actionscript.all/Object-v7` | rm 325/333 | **pass** | R4 |
| 7 | `from_gnash/actionscript.all/Object-v8` | rm 325/333 | **pass** | R4 |
| 8 | `from_gnash/actionscript.all/LoadVars-v6` | rm 146/152 | **pass** | R5a+R5b |
| 9 | `from_gnash/actionscript.all/LoadVars-v7` | rm 146/152 | **pass** | R5a+R5b |
| 10 | `from_gnash/actionscript.all/LoadVars-v8` | rm 146/152 | **pass** | R5a+R5b |
| 11 | `from_gnash/misc-swfmill.all/zeroframe_definesprite` | rm 1/3 | **pass** | R6 |
| 12 | `from_gnash/actionscript.all/Sound-v5` | rm 86/100 | **pass** 100/100 | R1 + S1 + S2 |
| 13 | `from_gnash/misc-ming.all/EmbeddedFontTest` | rm 60/87 | **pass** 87/87 | F1 + F2 |
| new | `regression/avm1_asnative_mc_probe_swf5` | mismatch 4/8 | **pass** | R1 + S1 (FP32 golden) |
| new | `regression/avm1_asnative_mc_probe_swf6` | mismatch 3/8 | **pass** | R1 + I1 (FP32 golden) |

No-graphics (box, headline legs before/after): the same 13 move rm → pass, both fixtures go mismatch → pass, and
`Function-v5` stays rm (identical line counts). `asnative`, `asnative_sweep`, `Sound-v6`, `MovieClip-v5` and
`DefineEditTextTest` pass in both legs.

Pixel axis: **no expected moves.** None of the 13 rows has `[image_comparisons]`. Canary 231/231 identical (below).

`Function-v5` does not move (rm both legs, 154/158).

The rebased re-measure (base `74e5f4cb`) is in §Gates, leg G2.

## Rules landed (owner functions)

All in `SWFModernRuntime/src/actionmodern/action.c` unless noted. R1–R6 are the w1 prototype exactly as measured
(`w1-rm-avm1-gnash-prototype.patch`, applied unchanged). The other rules are new in this wave.

| rule | what | functions touched |
|---|---|---|
| R1 | `ASnative(900\|901, n)` = MovieClip.prototype natives; a native MC stub held under another name runs its arm on the receiver; a stub delegated from a function VALUE is not version-hidden | `builtin_asnative` (900/901 arm); new `actionMCNativeByASnativeId`; `cfDelegateToMCMethod` + file-static `g_mc_delegate_from_value`; `actionCallMethod` MOVIECLIP arm (the `mcArmVersionHidden` gate, the `createEmptyMovieClip` SWF5 gate, the `_mc_user_dispatch` redirect) |
| R2 | SWF5 method call: the base clip is the receiver | `ClosureFrame` (trailing `saved_base`, `base_set`), `enterClosureFrame`, `leaveClosureFrame` |
| R3 | `removeMovieClip("")` targets the current target clip | `actionRemoveSprite` |
| R4 | `addProperty` of a watched, not-yet-existing name fires the watcher once | new static `addPropertyFireWatcher`; `builtin_object_addProperty`; `actionCallMethod` OBJECT `addProperty` arm |
| R5a | `LoadVars.sendAndLoad` into an inherited `loaded` setter | `builtin_loadvars_sendAndLoad` |
| R5b | `XML.prototype.load` on a non-XML receiver loads through its `onData` | `builtin_xml_load`, `aq_dispatch_xml_load` |
| R6 | the sprite's own frame-1 DoAction / `onClipLoad` see the DefineSprite header counters | `SWFModernRuntime/src/libswf/tag.c`: new static `sync_sprite_counters_pre_init`; `exec_sprite_frame`; `aq_dispatch_clip_load` |
| **I1** | At SWF6+, `ASnative(900\|901, n)` returns a FRESH function object per call (FP32 §D: `== MovieClip.prototype.X` false, two calls false); SWF5 keeps the shared stub (true/true) | `actionMCNativeByASnativeId` (heap copy of the stub, GC-linked, recorded in a file-static wrap table); new `actionMCNativeStubOf` (stub-or-wrapper → stub); the two `g_mc_method_funcs` range checks now call it: `actionCallFunction` (bare-name native-stub delegate) and `actionCallMethod` `_mc_user_dispatch` (R1 redirect) |
| **S1** | A script SetMember of a version-hidden **native** MovieClip.prototype member clears its hide bits (FP32 §B). Gate: the property still holds a `g_mc_method_funcs` stub or wrapper, so script-defined hidden properties keep their flags | `actionSetMember` (OBJECT arm, right after the TextField-native guard); `actionCallFunction` `createEmptyMovieClip` arm: at SWF5 it now defers to the prototype member when that member is visible and is the native, and delegates through `cfDelegateToMCMethod` on the with-target or the current clip |
| **S2** | SWF5: a `Sound` loses its owner when the clip is removed, even when the clip has an `onUnload` handler (Sound.as:268-269). SWF6+ keeps the binding through the deferred-removal window, unchanged | `resolveSoundOwner` |
| **F1** | SmallText fonts: the AVM1 `textWidth` getter sums `ceil(advance × size / em)` whole pixels per glyph (FP32 probe: SmallText-only; cleared, FP32 gives the unrounded sum, truncated) | recompiler `SWFRecomp/src/swf.cpp` (DefineFont2/3 flags bit 0x20 → new `font_smalltext_flags` in `SWFRecomp/include/swf.hpp`; emits `tagDefineFontSmallText(id)` ONLY for SmallText fonts, after kerning); `tag.c` new `tagDefineFontSmallText`; `ng_shared.c` trailing `small_text` field on the font record, new `ng_record_font_small_text`, new `ng_setSmallTextCeilMode` + static mode flag, `ng_computeTextWidth` unwrapped loop; `action.c` `computeTextFieldDimension` sets the mode around its `ng_computeTextWidth` call only; `include/libswf/tag.h` prototypes |
| **F2** | A text field's `_x` read off the placement matrix plus the bounds fold is quantised to whole twips (`spvTwipsQuantizePixels`). The float fold gave `49.6000061` for a 0.2-scaled field; FP32 gives `49.6` (EmbeddedFontTest.c:308). Ruffle prints 49.65 | `actionGetMemberImpl` `_x`: the native/offscreen arm's text-field fold and its browser twin. `_y` is untouched (no row needs it) |

Scope notes:
- F1 is deliberately narrow. Only the AVM1 `textWidth` property read sees the ceil. Autosize `_width`, word-wrapped
  width, `textHeight`, `getTextExtent`, AVM2 and glyph rendering are all unchanged. The recompiler emits nothing new
  for non-SmallText fonts, so their generated code is byte-identical.
- I1's wrap table grows only on `ASnative(900|901)` calls at SWF6+, so `actionMCNativeStubOf` is a two-compare check
  for every other movie.
- No new `.c`/`.h` files. Sibling-owned functions untouched: `setupNativeFuncOwnProps`, `ensureGlobalInit`,
  `installNativeToString`, `actionGetVariable`'s Array/String arm, `action_queue.c`, `tagClipEFFireNewerOrEqual`.
  `swf.c`, `swf_core.c` and `tag_stubs.c` are not touched.

## SmallText corpus census (brief item 4 guard)

A scan of every `.swf` in avm1, from_gnash, regression, fonts, text, visual, swf, timeline and from_shumway for
DefineFont2/3 with flags & 0x20 (scanner logic is described below; script not shipped):
- **109 `from_gnash/misc-ming.all` rows** (+ the `Dejagnu.swf` side files in actionscript.all): Ming's "Bitstream Vera
  Sans" (DF2 id 3/5/6/7, flags 0xa4), used by the on-screen xtrace log. Of their gnash sources, only
  `EmbeddedFontTest.c` reads `textWidth`/`textHeight`/`getTextExtent`. `DefineEditTextTest`, `DefineTextTest`,
  `TextSnapshotTest`, `BeginBitmapFill`, `DefineEditTextVariableNameTest`, `NetStream-SquareTest` and `matrix_test`
  match only on `_width`/`autoSize` comments, which F1 does not reach.
- `avm1/device_font_spacing` (DF3 'Noto Sans_16pt_st' / 'Courier New_16pt_st', flags 0xa4): passes before and after,
  byte-identical.
- `from_shumway/acid/acid-text-3` (DF3, flags 0x24, AVM2): pass before and after, byte-identical. AVM2 never sets
  the mode.

All 111 are in the gate below: 0 content moves outside EmbeddedFontTest.

## Gates (this box; before = clean `origin/master` runtime AND recompiler, after = this patch; content = filtered actual output)

| leg | base | rows | result |
|---|---|---|---|
| G1 graphics, 860 rows: s30 rm pool (98 avm1+gnash rows), every `regression/` row (322), SWF5 rows by header (107), SmallText rows (109+2), w1's argued R1/R2/R4/R5 neighbour greps extended with sound/textfield/edittext/font (370) | `92f7d5e8` | 860 | **15 status moves, all ledger** (13 rm → pass + 2 new fixtures). **845 rows byte-identical.** Before = 754 pass / 98 rm / 8 mismatch; after = 769 / 85 / 6. The before leg matched CI's committed per-suite results on every row except the 2 new fixtures and 4 rows the just-landed siblings moved (`action_execution_order_test4`, `_test11`, `regression/avm1_exec_order_sibling_interleave`, `regression/avm1_nested_child_swapdepths_remove`: their ledgers, identical before/after here) |
| G2 graphics, rebased: headline + pool + every `regression/` row (including batch 2's new fixtures) | `74e5f4cb` | 443 | **15 ledger moves, 428 byte-identical**, 0 other moves (§G2) |
| no-graphics headline (21 rows: the 13, both fixtures, `Function-v5`, `asnative`, `asnative_sweep`, `Sound-v6`, `MovieClip-v5`, `DefineEditTextTest`) | `92f7d5e8` | 21 | the same 15 moves; every other row unchanged |
| render canary: `render_canary_tests.txt` minus its 36 `avm2/` members (avm2 not downloaded; no AVM2 path is touched: F1's mode is AVM1-only and I1/S1/S2 are AVM1 builtins) | `92f7d5e8` | 167 tests / 231 PNGs | **231 IDENTICAL, 0 DIFFERS**, no trace or image status changes |

One measurement accident, for the record: the first after-leg had a debug-strip bug that dropped `_x`'s fallback
`PUSH`, so 20 rows printed `_x = undefined`. I caught it from the content diff (cmp before/after), fixed it, and
re-ran the whole after-leg from scratch. The numbers above come from the clean re-run.

### G2 (rebased onto `74e5f4cb`)

443 rows: every s30 rm pool row (98), every `regression/` row on the new base (including batch 2's new fixtures), and
the no-graphics headline set, measured in graphics mode. Both legs ran on `74e5f4cb`.
- Before: 343 pass / 97 rm / 3 mismatch. After: 358 / 84 / 1.
- **Status moves: exactly the 15 ledger rows** (13 rm → pass + the 2 new fixtures). **428 rows are byte-identical**
  before vs after.
- The 1 remaining mismatch is `from_gnash/misc-ming.all/ButtonEventsTest`. It is mismatch in BOTH legs with identical
  content. It was rm on the `92f7d5e8` base, so the move comes from batch 2 (`a18a0e03`), not this patch. The
  coordinator should check it against batch 2's ledger.
- `regression/` is 100% pass after (aside from the 2 fixtures, which pass only with the patch).

## Priced HOLD / not landed

| item | rows | why held | completion mechanism |
|---|---|---|---|
| Function-v5 S part (SWF5 `new` sets no `__constructor__`) | `from_gnash/actionscript.all/Function-v5` (stays rm) | It fixes Function.as:719 only; :689 `Email.constructor.toString() == undefined` is B6 (SWF5 Function / Function.prototype visibility, M). `__constructor__` is written at about 10 `new` sites (`actionNewObject` family, lines ~66100-67990, 81791), so a one-site gate would be partial and an all-site gate is a wide SWF5 change for a row that stays rm | land together with B6, gated `g_swf_version < 6` at every `__constructor__` write in the `new` paths; FP32 golden already on master |
| F2 for `_y` | none | no corpus row needs it; same float-fold artifact class | quantise the text-field `_y` fold the same way when a row shows it |
| F1 for wrapped / autosize / `getTextExtent` | none found | FP32 probe only measured unwrapped `textWidth`; no SmallText row reads the others | FP32 capture of a SmallText field with `wordWrap` / `autoSize` before widening |

## Refutations / premise checks

- **"Sound-v5 = B20c path binding (M)"**: the path binding already existed (`resolveSoundOwner` re-resolves the target
  path on every call: Ruffle `caebd7f57`). The row needed S1 (so `c1` exists at all in SWF5) and the SWF5
  deferred-removal rule S2. Price S, not M.
- **"EmbeddedFontTest = SmallText ceil only"**: the ceil fixes 26 of the 27 diff lines. The last line, `tf10._x ==
  49.6`, is a float artifact in the text-field `_x` fold (F2), unrelated to fonts.
- **"ASnative identity might cost ledger rows"**: it cost none. Every `g_mc_method_funcs` identity check goes through
  `actionMCNativeStubOf`. `mcArmVersionHidden` still compares the prototype's own value, and that is still the stub
  unless a script SetMembered it.

## RvF entries (appended to `RUFFLE_VS_FLASH_DIFFERENCES.md`)

1. `XML.prototype.load` on a non-XML receiver: FP32 returns true and runs the receiver's `onData`; Ruffle returns false
   (LoadVars-v6..v8).
2. SetMember on a version-hidden native MovieClip.prototype member clears the hide flag in Flash; Ruffle keeps it. Also
   SWF5 Sound loses its binding through deferred removal; Ruffle keeps it (Sound-v5).
3. ASnative(900/901) identity: a fresh object per call at SWF6+ (an ours ≠ Flash record; Ruffle's side not checked).

## flash_fixes candidates

None. Every ledger row's golden is already FP32.

## New unclaimed leads

1. **SetMember on OTHER native-hidden members.** S1 is gated to MovieClip.prototype native stubs. FP32 §B suggests the
   general rule is "any script SetMember of a version-hidden property clears the hide bits". An FP32 probe (SWF5:
   `Object.prototype.addProperty = …` or `TextField.prototype.X = …` on a SWF6-tagged member, then a read) would say
   whether to widen it.
2. **Text-field `_x`/`_y` float fold** (F2): any scaled DefineEditText placement can print `…0000061`-style values on
   `_y` too. A grep of failing goldens for 7-digit tails on `_y` reads would find any rows.
3. Carried from w1 and still open: the ASnative id table beyond 900/901 (Date 103 by id is the bulk of
   `ASnative-v5..v8`), the B20a array rules, B17 super re-resolution.

## LOCAL ORACLE REQUESTS

None needed for landing. Optional for lead 1: **FLASH, trace, SWF5, direct pinned**: a 1-frame fixture that
SetMembers `ASSetPropFlags`-hidden (SWF6-tagged) natives on `Object.prototype` and `TextField.prototype` and reads them
back bare and through an instance. Not built here.
