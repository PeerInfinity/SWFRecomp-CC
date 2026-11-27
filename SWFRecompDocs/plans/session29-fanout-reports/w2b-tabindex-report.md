# s29 w2b-tabindex: AVM1 MovieClip `tabIndex` raw-string mode (wave 2, implementation)

**NEW FILES**
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-tabindex-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-tabindex.patch`
- `SWFRecompDocs/plans/session29-fanout-reports/w2b-tabindex-oracle/{make_fixture.py,t_child_numstr_null/test.swf,test.toml}` (optional FLASH request)
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_fn2_root_raw/{test.swf,test.toml,output.txt,README.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_fresh_child_coerce/{test.swf,test.toml,output.txt,README.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_read_first_coerce/{test.swf,test.toml,output.txt,README.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_mtasc_class_main/{test.swf,test.toml,output.txt,Test.as,README.txt}`

**Edited (committed on the branch; doc edits are NOT in the patch, per the patch spec):**
- `SWFModernRuntime/src/actionmodern/action.c` (in the patch)
- `ruffle-tests/ignored_tests.txt`: the edge case is pruned.
- `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`: the entry and its summary row are marked RESOLVED.
- `RUFFLE_VS_FLASH_DIFFERENCES.md`: new entry appended at EOF.
- `regression/README.md`: 4 new rows.

## Verdict: GO. One rule fits all 17 FP32 captures; landed

| item | verdict | flip |
|---|---|---|
| `avm1/tab_ordering_properties_tab_index_edge_case` | **GO** | ruffle_matched 1/4 → **pass 4/4** |
| `actionSetMember` NaN-keeps-previous arm (lead L-tab) | **replaced.** The MTASC capture `m.tabIndex=0; m.tabIndex="t"` gives `-2147483648`, not 0 | covered by the new regression rows |
| `tab_ordering_properties` and the other 30 `avm1` tab/tabIndex rows | unchanged (A/B identical) | none |
| 4 new `regression/` rows (FP32 goldens) | pass. All 4 fail on clean master | new rows |

### The rule (proven before implementing)

On the **timeline-placed root**, the native MovieClip `tabIndex` accessor does not exist until some **name lookup on
the root misses its own properties**. Three kinds of lookup do this:
- a read of `this.tabIndex`;
- an unresolved scope name (the very first op of MTASC's DoInitAction is `GetVariable "Test"` while `Test` is still
  undefined, and `CallFunction "ASSetPropFlags"` follows);
- a prototype-method call such as `this.createEmptyMovieClip`.

A `SetMember tabIndex` before that creates a **plain own property**. The value stays raw, and the property is
sticky: it shadows the accessor from then on, so `5` and then `"asdf3"` both stay raw.

These do **not** materialise the accessor:
- a lookup satisfied by an own root property (the function `f` in t04/t05/t06);
- the keyword targets (`this`, `_root`, `_global`, `_parent`, `_levelN`).

Script-created clips coerce from their first set (t08). Once the accessor coerces, a non-numeric value gives
**INT_MIN**. This agrees with Ruffle's `set_tab_index` (`_ => Some(i32::MIN)`).

**MTASC disassembly** (`L3b_tabindex_v8/test.swf`, CWS):
- DoInitAction: `ConstantPool`, then `Push "Test"; GetVariable; Not; Not; If` (an unresolved root-scope lookup),
  then the class definition, and `ASSetPropFlags(Test.prototype, null, 1)`. The `ASSetPropFlags` call targets the
  prototype, not the root.
- Frame 1: `Push "MTASC_MAIN"; StoreRegister 0; Pop; this; Test.main(this)` via CallMethod.
- `main` is a DefineFunction2 with 6 registers and flags `0x29` (PreloadThis | SuppressArguments | SuppressSuper; no
  PreloadRoot). Its param is `mc`→r2, and it does `GetVariable "_root"; StoreRegister 3`.

So nothing reads or enumerates the root, and nothing calls `ASSetPropFlags` on it. The only root interaction before
`main` is the **missed scope lookups**: that is the fold-in.

**Prediction table.** Every row matches FP32 under our patched runtime. The scratch suite was run with
`--mode=graphics`, one test per FP32 capture:

| fixture | discriminating event before first set | rule predicts | FP32 | ours after |
|---|---|---|---|---|
| t00 corpus replica | none (`GetVariable "this"` is a keyword) | raw | raw | pass |
| t01 no FileAttributes | none | raw | raw | pass |
| t02 `_root` GetVariable | none (keyword) | raw | raw | pass |
| t03 `this` in a register | none | raw | raw | pass |
| t04 fn2 on root | `CallFunction "f"`, which hits an OWN property | raw | raw | pass |
| t05 fn1 on root | same as t04 | raw | raw | pass |
| t06 fn2, `_root` in a register | same as t04 | raw | raw | pass |
| t07 InitAction root | none | raw | raw | pass |
| t08 fresh child | target is a script-created clip | coerce | coerce | pass |
| t09 SWF6 / t10 SWF7 | none | raw | raw | pass / pass |
| t11 read first | `GetMember tabIndex` on the root: a miss | coerce | coerce (`undefined` first) | pass |
| t12 body on frame 2 | none | raw | raw | pass |
| `L3b_tabindex` (v6), `_v7`, `_v8` (MTASC) | `GetVariable "Test"` misses (DoInitAction) | coerce, INT_MIN for NaN | coerce, INT_MIN | pass ×3 |
| corpus `tab_edge_corpus.flash.txt` | none | raw | raw | pass |

**Attacking the rule:**
- The 17 captures cannot tell "a missed lookup" apart from "any lookup that walks past the own properties".
  Those are the same event in AVM1.
- They also cannot tell whether a timeline-placed CHILD behaves like the root. We apply raw mode to `_root` only,
  the only clip ever seen raw.
- Over-triggering is the safe direction: it falls back to the coercing setter, which was our only behaviour before.
  So the hooks err broad. Any missed GetVariable/CallFunction in root context, or GetMember/CallMethod on the root,
  flips it.
- Under-triggering would need some root interaction that we don't hook, before a first set of a non-number. No
  corpus row does that (A/B below).

## 1. Patch scope: `SWFModernRuntime/src/actionmodern/action.c` only

- **New static block** just before `actionGetVariable`: `g_tab_root_native`, `g_tab_root_raw`, `tabRootNoteLookup`,
  `tabRootNoteScopeLookup`, `tabRootNoteMemberLookup`. The hooks are side-effect-free: one `hashmap_get(var_map)` and
  one `getProperty(root dynamic_props)`, and both return early once a flag is set.
- **One-line hooks**, each tagged `// s29 w2b-tabindex`:
  - `actionGetVariableImpl`, after the name POP;
  - `actionGetMemberImpl`, after the object pop;
  - `actionCallFunction`, after the name POP;
  - `actionCallMethod`, after the object pop, when there is a method name.
- **`actionSetMember` tabIndex block:**
  - New raw arm: root, not a textfield or button, and (`g_tab_root_raw` or not `g_tab_root_native`). It stores
    the value as-is as an enumerable own prop plus the root global variable, and sets `g_tab_root_raw`.
  - MC/button NaN arm: `return` (keep previous) becomes `INT_MIN`.
  - The TextField u32 arm is unchanged.

Siblings: `w2-rm-avm1-gnash-land` and `w2-timers-goto-land` also edit `action.c`. My hunks are the 7 listed by
`grep '^@@'` in the patch: the new block before `actionGetVariable` plus five one-liners or arms. They are small
and context-local, so expect clean 3-way merges. No recompiler, `verify_output.py` or canary-list change.

## 2. Per-test before/after (same box, graphics; before = clean `origin/master` `85144f5dd`)

Upstream avm1 corpus: `download_tests.sh avm1` at 2026-11-27 (Ruffle master ≈ `952362ecf`).

| test | before | after |
|---|---|---|
| `avm1/tab_ordering_properties_tab_index_edge_case` | ruffle_matched 1/4 | **pass 4/4** |
| `regression/avm1_tabindex_fn2_root_raw` | output_mismatch 1/4 | **pass 4/4** |
| `regression/avm1_tabindex_fresh_child_coerce` | output_mismatch 1/4 | **pass 4/4** |
| `regression/avm1_tabindex_read_first_coerce` | output_mismatch 2/5 | **pass 5/5** |
| `regression/avm1_tabindex_mtasc_class_main` | output_mismatch 2/6 | **pass 6/6** |

**No-graphics after:** the 4 regression rows, the edge case and `tab_ordering_properties` all pass. The change is
in shared code with no `NO_GRAPHICS` arm.

### Guard set (graphics A/B, 31 avm1 rows: every `*tab*` name plus every test whose `.as` mentions `tabIndex`). All identical

These pass in both legs:

| test | lines (both legs) |
|---|---|
| `button_keypress_vs_tab` | 20/20 |
| `clone_sprite_edittext` | 94/94 |
| `clone_sprite_edittext_dynamic` | 86/86 |
| `define_font_glyph_table_order` (image) | pass |
| `define_font_glyph_table_overlap` (image) | pass |
| `edittext_tab_focus` | 13/13 |
| `edittext_tab_stops` | 60/60 |
| `focus_keyboard_press` | 60/60 |
| `focus_root_movie` | 2/2 |
| `focusrect_focuslost` (image) | pass |
| `focusrect_mouse_swf9` (image) | pass |
| `focusrect_swf6` (image) | pass |
| `movieclip_default_state` | 69/69 |
| `movieclip_state_values` | 114/114 |
| `mutable_this` | 18/18 |
| `tab_ordering_automatic_basic` | 92/92 |
| `tab_ordering_automatic_order_grid` | 21/21 |
| `tab_ordering_automatic_order_same_position` | 12/12 |
| `tab_ordering_children` | 208/208 |
| `tab_ordering_custom_basic` | 71/71 |
| `tab_ordering_custom_duplicate_index` | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | 12/12 |
| `tab_ordering_custom_m1` | 29/29 |
| `tab_ordering_events` | 150/150 |
| `tab_ordering_events_mouse` | 65/65 |
| `tab_ordering_movieclip_enabled_default` | 462/462 |
| `tab_ordering_properties` | 293/293 |
| `tab_ordering_reverse` | 51/51 |
| `tab_ordering_tabbable` | 47/47 |
| `textfield_props_swf8` | 210/210 |

`movieclip_library_state_values` is ruffle_matched 76/78 in both legs.

### Regression suite (graphics, after leg)

29 rows near the change all pass: every regression row matching `tab|focus|root|mtasc|class|setmember|getmember|
global|swf5|textfield`. That covers the root-onload, root-goto, closure-base-clip, textfield-ctor-shadow and watch
SetMember rows, plus 3 avm2 rows.

### Render canary (`render_canary.py`, md5 A/B)

- **Scope:** the 75 `avm1/` + `regression/` members of `render_canary_tests.txt` (74 tests, 91 PNGs).
- **Result:** IDENTICAL 91, DIFFERS 0, no trace or image status changes.
- **Not run:** the avm2/visual/shumway/gnash members. Those suites are not downloaded here, they run no AVM1
  `SetMember`, and no render code is touched.

## EXPECTED-FLIP LEDGER (CI graphics; no-graphics identical)

**Trace axis:**

| suite/test | baseline (`014124ed5`) | expected |
|---|---|---|
| `avm1/tab_ordering_properties_tab_index_edge_case` | ruffle_matched 1/4 (ignored) | **pass 4/4** (pruned from `ignored_tests.txt`, so it now counts in the filtered headline) |
| `regression/avm1_tabindex_fn2_root_raw` | (new) | **pass 4/4** |
| `regression/avm1_tabindex_fresh_child_coerce` | (new) | **pass 4/4** |
| `regression/avm1_tabindex_read_first_coerce` | (new) | **pass 5/5** |
| `regression/avm1_tabindex_mtasc_class_main` | (new) | **pass 6/6** |

Nothing else moves. The NaN→INT_MIN change could in principle touch any MC/button that is set to a non-numeric
tabIndex after a numeric one. The 31-row guard set shows no such row in avm1. Rows outside avm1 that set a
MovieClip tabIndex to a string (gnash/shumway) were not swept. If CI moves one, it is this arm.

**Pixel axis:** no expected moves. None of the ledger rows has `[image_comparisons]`, and the canary is identical.

## Not finished / limits (with completion mechanism)

- **Timeline-placed children.** It is unknown whether a timeline-placed child (not the root) is raw before its first
  lookup. We keep it coercing. Completion: a FLASH fixture (frame-placed sprite `c`, `c.tabIndex = "x"` as the
  first op, after nothing but `GetVariable "c"`).
- **Numeric strings** (`tabIndex = "5"` on a coercing clip). We give 5; Ruffle gives INT_MIN. No capture exists.
  Completion: one FP32 trace.
- **`null`.** Ruffle unsets on `null`; we coerce it to 0. No capture exists. Completion: the same FP32 fixture, with
  a `null` row.
- **`delete _root.tabIndex` after raw mode** does not clear `g_tab_root_raw`. This is not observed in any test.

## New unclaimed leads

- **L-tab-2:** the numeric-string and `null` coercion rules above (one FP32 fixture decides both).
- The CI full-run outcome for non-avm1 rows that set a string tabIndex on an MC (see the ledger caveat).

## LOCAL ORACLE REQUESTS

- (Optional, not blocking this landing.) **FLASH:** `session29-fanout-reports/w2b-tabindex-oracle/t_child_numstr_null/`
  (generator `make_fixture.py`, SWF8, 2 frames), trace, direct. The script is
  `c.tabIndex="x"; trace(c.tabIndex); m=createEmptyMovieClip("m",5); m.tabIndex="5"; trace(m.tabIndex);
  m.tabIndex=null; trace(m.tabIndex)`, where `c` is a timeline-placed sprite.
  - Ours today: `-2147483648`, `5`, `0`.
  - It decides three questions: whether a timeline child is raw (line 1, `x`?), whether a numeric string coerces
    to INT_MIN (line 2), and whether `null` unsets the value (line 3, `undefined`?).
