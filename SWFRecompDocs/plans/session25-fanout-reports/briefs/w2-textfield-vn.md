**gnash `TextField-v6/v7/v8` → ruffle_matched (+3 effective, priced ≈ L).** From `w1-textfield-vn` (report + `w1-textfield-vn-prototype.patch` on master). All three rows are known_failure, so `ruffle_matched` is the landing. The flip requires removing every **ours-only** diff line (our diff-line indices must be a subset of Ruffle's; `verify_output.py` ~3914).

1. Apply the measured prototype: P0 SWF5-imported field, P1b instance `_listeners`, P2 lazy `TextField.prototype` props, P14 setFocus collapsed selection, P15 free-function createTextField depth/name. That gives 78/94/93 → 32/46/44 diff lines with 0 rider moves over 195 rows. Rebase onto origin/master (`action.c` got `5b50cd4a0`, `0f35012bd` since the w1 base) and re-measure.
2. Implement the remaining phases in the report's §2 table: P8 `length` read-only, P18 `_name`/`_target` setter, P19 CallMethod createTextField returns undefined below SWF8, P20 `_ROOT` case-sensitive (v7+), P21 bound `undefined` prints "undefined" (v7+), and the three M phases:
   - P16 variable-binding path semantics (`actionTryBindTextFieldVariable`);
   - P13 createTextField calls `_global.TextField` with `this` = field (identity `===`);
   - P17 device-font metrics on createTextField fields.
   Measure stepwise, as the w1 did. Stop on any step that adds a diff line anywhere.
3. Also the w1's residual lead: the CallMethod `createTextField` arm discards depth and numeric names, and a naive fix regressed v7. Diagnose it before touching it.
4. Sweep: the w1's 195-row set plus every `avm1` TextField/EditText/Selection row and `regression/avm1_*text*`, both modes on the headline rows.

**Coordination:** P14 touches `builtin_selection_setFocus` (Selection focus). The local `n-play-game` session works on AVM1 button/mouse dispatch. Stay out of `tag.c` button/mouse code, and list every Selection/focus function you touch. Sibling `w2-acid-text-kerning` may touch the AVM1 EditText advance loop, and P17 overlaps it, so keep P17 to the createTextField device-font metric path. EXPECTED LEDGER: the 3 rows → ruffle_matched (any subset you reach), 0 other moves.
