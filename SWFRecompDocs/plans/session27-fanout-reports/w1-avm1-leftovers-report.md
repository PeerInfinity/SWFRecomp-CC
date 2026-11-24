# s27 w1-avm1-leftovers: AVM1 leftovers (unified mouse pick, EditText path scope, dotted `__resolve`, `setNewTextFormat` size/font, Cut/Copy/Paste, SWF≤6 case-insensitive builtins)

**New files** (all under `session27-fanout-reports/`):
- this report;
- `w1-avm1-leftovers-prototype.patch` (`git diff origin/master -- SWFModernRuntime`; `action.c` +342/−210, `tag.c` +22; sources reverted);
- `w1-avm1-leftovers-fixtures/`, 8 fixture dirs. Each holds `create_test_swf.py`, `avm1asm.py` (the s26 copy), `test.swf`, `test.toml`
  and `output.txt`, plus `input.json` where needed. The generators regenerate `test.swf` byte for byte.
  - `avm1_mc_button_unified_pick/` (item 1, input)
  - `avm1_edittext_path_variable_scope/` (item 2)
  - `avm1_edittext_path_variable_same_frame/` (item 2 lead, **fails** after the prototype)
  - `avm1_resolve_dotted_getvariable/` (item 3, HOLD; plus `output.ours.txt`)
  - `avm1_set_new_text_format_size/` (item 4)
  - `avm1_edittext_cut_copy_selection/` (item 5, input)
  - `avm1_swf6_case_insensitive_builtins/` (item 6)
  - `avm1_swf7_case_sensitive_builtins/` (item 6 lead twin; its generator calls the SWF6 one with version 7; plus `output.ours.txt`)

Base: `origin/master` `ae7f50cb` (code = `005bea42a` + `d70f2c0aa`). Baseline results: `df7729df2`. The wave-0 run had not published
when I started, so no stroke-order rows are involved here. Corpus: `download_tests.sh avm1 from_gnash from_shumway`, 2026-11-24
(upstream Ruffle `1e604fa87`). Ruffle source: blobless clone at `1e604fa87`. Box: SETUP_STATUS all OK (Dawn on lavapipe).
Every run below is `--mode=graphics` unless it says otherwise.

## Verdicts

| # | item | verdict | price | fixture: master → prototype (graphics) |
|---|---|---|---|---|
| 1 | AS-handler clip mouse dispatch joins the DefineButton pick | **GO** (prototyped). The brief **understated** it: `onPress` fired on *every* overlapping handler clip | S (not M) | `avm1_mc_button_unified_pick` 6/21 → **pass** (no-graphics too) |
| 2 | EditText path-variable scope for non-button fields | **GO** (prototyped), and it is **three bugs**, not one: the `:` separator, the scope, and the retry that never registers | S | `avm1_edittext_path_variable_scope` 5/10 → **pass** |
| 2b | … when the field and its target clip are placed on the **same** frame | **HOLD**, new lead: a ghost `mc` is materialized under `_root` | M | `avm1_edittext_path_variable_same_frame` 5/11 → 5/11 |
| 3 | `__resolve` through dotted GetVariable paths | **Premise REFUTED** for intermediate segments (already right on master). The one divergence (final segment) is **HOLD: Ruffle-vs-Flash unknown** | XS once decided | `avm1_resolve_dotted_getvariable` 16/18 vs the Ruffle-source golden (not prototyped) |
| 4 | `setNewTextFormat` size/font | **GO** (prototyped). It is **trace-visible**, not only a render bug | S | `avm1_set_new_text_format_size` 4/5 → **pass** |
| 5 | Cut/Copy act on the whole text | **GO** (prototyped). Wider than briefed: Paste also ignores the selection, and none of the three work on `createTextField` fields | S | `avm1_edittext_cut_copy_selection` 2/9 → **pass** |
| 6 | SWF≤6 case-sensitive builtin arms | **GO** (prototyped): 3 dispatchers, 64 names | XS–S | `avm1_swf6_case_insensitive_builtins` 34/42 → **pass**. The SWF7 twin is unchanged, 37/40 (reverse leak, lead) |
| 7 | the 38 failing graphics rows | **0 movers**: no failing row reaches these paths | — | 10 AVM1/gnash failing rows re-run, all unchanged |

**Priced corpus flips: 0.** Every GO is a correctness fix pinned by a fixture.

**Every golden is analytic** (derived from Ruffle source at `1e604fa87`) until the coordinator's oracle runs; see LOCAL ORACLE REQUESTS.
For each GO fixture, the prototype's output equals the derived golden.

## Argued sweep (prototype vs the `df7729df2` CI rows: status plus matching-line count; single tests, `-P 2`)

The sweeps total **299 rows** (some overlap), with **0 movers**. One mid-prototype regression set was found and fixed (item 1, below).

| family (why) | rows | movers |
|---|---|---|
| **Item 6.** Every SWF≤6 corpus SWF whose bytes hold a non-exact case variant of a canonicalized name (`/tmp` scanner over avm1/gnash/shumway/regression; 121 hits, mostly `typeof` literals). The 17 with real variants (`case-v5/v6`, `Date`, `Boolean`, `toString_valueOf`, `Global`, `ops`, `Key` (v5/v6 each), `loadMovieTest`, `new_child_in_unload_test`, `array_trivial`, `object_string_coerce_swf5`), plus 14 more: `native_objects_swf6`, `math_swf6`, `is_finite_swf6`, `swf5_encoding`, `enumerate`, `define_local_with_paths`, gnash `String`/`array` v5/v6, `DefineEditTextVariableNameTest`, `MovieClip-v6`, `XML-v6` | 31 | 0 |
| **Items 4+5.** Every corpus SWF that calls `setNewTextFormat` (avm1 `edittext_*`/`textfield_*`/`html_text_img_*`, gnash `TextField-v6/7/8`, both regression `set_new_text_format` rows), plus `regression/avm1_edittext_html_delete_runs` | 38 | 0 |
| **Item 5.** TextControl input rows (`edittext_input`, `_input_newlines`, `_password_copy`, `_paste_empty`, `_place_caret`, `_restrict`, `_restrict_paste`, `_tab_focus`, `button_keypress_vs_textinput`, `input_dead_keys_windows`) | 10 | 0 (all pass) |
| **Item 2.** Every corpus SWF whose DefineEditText has a variable (scanner): all path-variable rows, a sample of the 350 gnash `_root._trace_text` rows (including failing `RegisterClassTest4`), plus input/TextField rows | 27 | 0 |
| **Item 1.** Every avm1/gnash/shumway/regression row whose `input.json` holds a Mouse event | 58 | 0 (after the fix below) |
| **Item 7.** Failing baseline rows that could reach these paths: `globals_swf5`, `native_objects_swf6`, `set_property_values/swf4`, `movieclip_hittest_shapeflag`, `date`, `sandbox_type_remote`, `external_interface_monkeypatch`, gnash `argstest-v6/7/8` | 10 | 0 (identical line counts) |
| **regression suite**, every non-AVM2/non-layer/mask row (graphics) | 125 | **0: 125/125 pass** (2 rows postdate the CI JSON and are absent from it: new landings, not movers) |

**Item 1's regression set during prototyping** (fixed before the final sweep):
- The first cut restricted `onPress` to the single topmost *sprite*, and so dropped the AS handlers that live on a **DefineButton instance**
  (`is_button_mc` wrapper, `_level0.button.onPress`).
- That moved three rows pass→fail: `avm1/focus_mouse`, gnash `ButtonEventsTest` (ruffle_matched 676 → 130) and shumway
  `mouse-transparency`.
- The fix: button wrappers keep their own path, because their events ride on tag.c's button pick. All three rows are back to
  baseline, and the 58-row re-sweep has 0 movers.
- **Lesson for wave 2:** an AVM1 `Button` object's AS handlers are dispatched by `actionDispatchMCPress` too. Any unified-pick
  change must keep them.

No-graphics: the item-1 fixture passes in both modes. The prototype touches no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-only arm
(`tag.c` is linked in both modes). The `setNewTextFormat` arm is `NO_GRAPHICS || OFFSCREEN_RENDER`, as before.

---

## 1. One mouse pick for handler clips and DefineButtons

**Mechanism (master).** Two dispatchers disagree with Ruffle's `run_mouse_pick` → `mouse_pick_avm1`, which returns ONE interactive
object per event: the first hit in render order, either a DefineButton or a button-mode clip. A button-mode clip returns itself
before recursing, so its children never pick.
- `actionDispatchMCPress` (`action.c`, s26 line ~82195) fires `onPress` on **every** clip whose AABB holds the mouse. There is no
  topmost rule, no ancestor rule and no DefineButton check.
- `actionDispatchMCMouseMove` already uses one topmost handler sprite (`ng_roll_pick_topmost`, s26), but it **ignores DefineButtons**.
- `tag.c`'s three-phase pick (`ng_update_button_states`, s26) lets a button-mode sprite block the DefineButtons beneath it, but
  nothing blocks in the other direction.

**Measured** (`avm1_mc_button_unified_pick`, master; the same result in both modes):

| zone | layout | master | Ruffle (source) |
|---|---|---|---|
| Z1 | DefineButton B1 under clip m1 | m1 only | m1 only |
| Z2 | clip m2 under DefineButton B2 | **B2 and m2** (rollOver, press, release, rollOut) | B2 only |
| Z3 | clip lo under clip hi | rollOver hi; **press/release lo and hi**; a stray `lo onRollOut` | hi only |
| Z4 | handler `par` holding handler `kid` | **`kid` gets onPress/onRelease/onRollOut** | par only |

The stray `lo onRollOut` happens because the press sets `mc_mouse_inside` on `lo`, so the next move fires RollOut without a
RollOver ever having fired.

**Prototype:**
- **`tag.c`, `ng_update_button_states`:** after the PICK phase of an *outermost* call (`saved_phase == BTN_PHASE_LEGACY`), store
  the winner in new statics `g_btn_last_pick_obj` / `_sprite` / `_seq`.
- **`tag.c`, new `int ng_btn_last_pick(MovieClip** sprite, unsigned* seq)`** reads them. The pick always runs before the MC
  dispatch on move, press and release (`input_events.c:182/201/219`; `swf_core.c:548/576/602`).
- **`action.c`, new `static ng_defbutton_won_pick()`:** 1 when the last pick was won by a DefineButton.
- **`actionDispatchMCPress`:** `press_picked = ng_defbutton_won_pick() ? NULL : ng_roll_pick_topmost(mx, my)`. A sprite clip
  fires only when it is `press_picked`. An `is_button_mc` wrapper (a DefineButton instance's own AS handlers) keeps the old path.
  - A forward declaration of `ng_roll_pick_topmost` was added.
- **`actionDispatchMCMouseMove`:** `roll_picked` is NULL when a DefineButton won.
- **Release** follows the press automatically, because `mc_as_pressed` is now set only on the picked clip.

**Price S**, not M: the unified pick already exists in `tag.c`. The fix only has to publish it and consume it.

**Residuals:**
- Dynamic (`createEmptyMovieClip`) handler clips are in `ng_roll_pick_topmost`. Whether `tag.c`'s walks also order them against
  DefineButtons was not probed. The fixture uses timeline clips only.
- An `is_button_mc` wrapper still fires by AABB on press. It is not filtered by the sprite pick, because filtering it regressed
  three rows. It is probably right whenever its DefineButton won.

## 2. EditText `variable` paths on non-button fields

**Three bugs, measured** (`avm1_edittext_path_variable_scope`; sprite `s` places `mc`, then the fields one frame later):
1. **Separator** (`actionTryBindTextFieldVariable`, `ng_syncTextToVar`, `actionNotifyPropertyChange`). Paths split at the
   right-most **`.`** only, and `is_path` tests `strchr('.')`.
   - `"mc:foo"` became a simple name: `s["mc:foo"] = "F"`.
   - `"_root.s.mc:bar"` split as `_root.s` + `"mc:bar"`.
   - Ruffle `resolve_variable_path` uses `path.rfind(":.")`, with no SWF-version gate.
2. **Scope.** The path's target resolved through `actionGetVariable` in **`g_current_context`**; only button children climbed to
   the parent (s26). So `"mc.baz"` on a field in `s` looked for `_root.mc`. Ruffle runs `resolve_variable_path(parent, ..)` in a
   child frame for the parent, climbed past buttons.
   - The retry queue (`actionRetryUnboundTextFields`) runs from whatever clip's frame is current, so a retry could resolve anywhere.
   - `ng_syncTextToVar` (field → variable on typing) had the same scope bug.
3. **Retry never binds.** The `set_initial_value = 0` retry `return 1`'d **before** `actionRegisterTextFieldBinding`. So a field
   whose target appeared later left the queue unbound, and later writes never reached its text (`s.late.q = "X"` left `t5.text`
   at `"L"`). Ruffle `bind_variables` → `try_bind(.., false)` still calls `set_bound_display_object`.

Master: 5/10. Prototype: pass (10/10, equal to the Ruffle-source golden).

**Prototype:**
- New statics:
  - `tfVarPathSep` (right-most `:` or `.`);
  - `tfVarScopeClip` (parent, climbed past buttons, else `_root`);
  - `tfVarResolveTarget` (GetVariable of the target part, with `actionSetCurrentContext(scope)` around it).
- They are used in `actionTryBindTextFieldVariable` (path branch; the s26 button-only gate is subsumed), `ng_syncTextToVar` and
  the registry last-segment match in `actionNotifyPropertyChange`.
- The retry path registers the binding before returning.
- Not touched: the legacy `child_mc_cache` scan in `actionSetMember` (~:59511, `strrchr('.')`, current context) and
  `tfDynamicRebindVariable` (createTextField `variable =`). Both have the same `.`-only split. Wave 2 should route them through
  `tfVarPathSep` / `tfVarResolveTarget` too (XS), with a fixture.

**2b, the same-frame HOLD (new lead, M).** When `mc` and the fields are placed on the **same** frame of `s` (the common Flash-IDE
case), the bind-time `GetVariable "mc"` (context `s`) does not find `s`'s already-created `mc`. Instead it materializes a **second
`mc` under `_root`**: a `createMovieClip` backtrace shows `parent = root_movieclip`. The bindings land on that ghost.
`avm1_edittext_path_variable_same_frame`: 5/11 on master and on the prototype, with every path binding `undefined`.
- Owner: `actionGetVariable`'s child-by-name lookup during sprite construction vs `findOrCreateMovieClip` (`action.c` ~:24258;
  `ng_findDisplayEntryByName` is the flat root display list).
- This is likely the bigger game-visible half: a HUD sprite with `score` / `mc:label` fields bound to a sibling clip.

## 3. `__resolve` through dotted GetVariable paths

**The premise is partly refuted.** On master, a missing **intermediate** segment already calls `__resolve` (`o.b.c`, `o.b.d.e`,
`o:b.c`, clips `m.q.c` and `_root.m.q.c`), and SetVariable `o.w.c` resolves once. This matches Ruffle `resolve_target_path`,
which reads each segment with `object.get` → `call_resolve_fn`.

**The one divergence** is the **final** segment.
- Ruffle `get_variable` checks it with `object.has_property(var_name)`, which does **not** call `__resolve`. It then falls through
  the scope chain to undefined (`activation.rs:2850`).
- We call `__resolve("zz")` for `o.zz` and `m.zz` and return its object.
- Fixture: 16/18 against the Ruffle-source golden.

**HOLD, not GO:**
- Ruffle's `has_property` here is a scope-walk device (try the next scope), and Flash may well call `__resolve` on the final
  segment too.
- Flash over Ruffle (rule 3), and there is no Flash oracle in the cloud.
- **Completion:** a Flash capture of the fixture. If Flash = Ruffle, skip `__resolve` on the final segment of the dotted
  GetVariable path (XS, in `actionGetVariable`'s dot-path branch, ~:49524) and land the fixture. If Flash = ours, record the row in
  `RUFFLE_VS_FLASH_DIFFERENCES.md`.
- The exporter run (LOCAL ORACLE REQUESTS) will at least confirm the Ruffle side.

## 4. `setNewTextFormat` size/font

**Measured, and the trace-side premise is real.** On a plain field holding `"AB"`, `setNewTextFormat({size:40, font:"_serif"})`
changed `textWidth`/`textHeight` at once (16→52, 18→56 on this box's device font). Meanwhile `getTextFormat(0)` still said 12 /
Times New Roman, and `getNewTextFormat().size` = 40.
- Ruffle `set_new_text_format` only stores the format, so the existing text keeps its metrics until the next `text =`.
- The CallMethod `setNewTextFormat` arm (`actionCallMethod`) writes the field-wide `_tf_fontHeight` / `_tf_fontId` /
  `_tf_fontName`, which lay out the **existing** text. It is the size/font twin of the s26 colour bug.

**Prototype:**
- New statics `tf_snf_slot`, `tf_snf_defer` and `tf_snf_apply_pending`, with a 16-slot `g_tf_snf` side table keyed by clip.
- When the field already has text, the arm parks size/font instead of writing them.
- The parked values are applied at the next text replacement:
  - `actionSetMember`'s `text` arm, when `tf_ps_text_assign` is not a same-text no-op;
  - the html-synonym `htmlText` arm;
  - `tf_replace_selection` (typing/paste with `ins_len > 0`).
- An empty field still writes immediately, which is the old path.

`avm1_set_new_text_format_size` 4/5 → pass. The fixture prints only booleans and format values, so it is independent of
device-font metrics.

**Residuals:**
- leading/margins/indent/letterSpacing/bullet/tabStops/align still apply immediately, the same bug class. Extend the slot (XS each).
- Typing one char after a parked size makes the whole field take the new size. Ruffle sizes only the new span, so the real fix is
  span-model-driven metrics (M).
- Slot overflow recycles slot 0 (prototype-grade).
- A slot holds a raw clip pointer. A removed clip's slot is never freed, but it is only matched by pointer.

## 5. Cut / Copy / Paste

**Measured, and wider than briefed** (`avm1_edittext_cut_copy_selection`: `"ABCDE"`, selection [1,3), then Copy, Paste at 0, Cut
[2,4), Cut+Copy on a caret, Paste). On master **nothing happened at all**:
- `actionTextControlCopy`, `actionTextControlCut` and `actionTextControlPaste` gate on `ng_textfield_idx < 0`, so a
  **`createTextField` field (idx −2) is skipped**. Typing and Backspace use `MC_IS_TEXTFIELD` and work.
- On a timeline field, by code-read:
  - **Copy** takes the whole text, even with a collapsed caret.
  - **Cut** clears the whole text, fires no `onChanged`, and also acts on a collapsed caret.
  - **Paste** **appends at the end** (or replaces everything after select-all), ignores the selection and caret, fires no
    `onChanged`, keeps newlines in single-line fields, and returns without deleting the selection when `restrict` filters
    everything.

**Ruffle** (`edit_text.rs`):
- `is_text_control_applicable`: Copy/Cut need `!password && !selection.is_caret()`.
- Copy: `text[sel]`.
- Cut: the same, then `replace_text(sel, "")`, caret at `sel.start`, `changed` → `onChanged`.
- Paste = `text_input(clipboard)`: it replaces the selection, the caret lands after the insertion, `onChanged` fires, newlines are
  dropped when not multiline, control characters are dropped, and a restrict that filters everything still deletes the selection.

**Prototype:**
- New statics:
  - `tf_selected_range`;
  - `tf_is_password`;
  - **`tf_replace_selection`**, the shared body extracted verbatim from `actionTextFieldInput`: selection/select-all range, maxChars
    tail truncation, `tf_ps_on_typed`, text store, binding sync, caret, invalidate, `onChanged`.
- `actionTextFieldInput` now calls `tf_replace_selection`. Typing is byte-identical (the 10 input rows pass).
- `actionTextControlCopy`, `actionTextControlCut` and `actionTextControlPaste` were rewritten on top of these.

Master 2/9 → pass.

**Residuals:**
- maxChars truncates the *tail* (ours, also for typing). Ruffle clips the *insertion* to `available_chars`.
- Cut in a non-selectable field: Ruffle puts the caret at the end.
- Both residuals are unprobed. Neither has a corpus row.

## 6. SWF≤6 case-insensitive builtin arms

**Census** (fixture `avm1_swf6_case_insensitive_builtins`, SWF6; 42 rows of `label: typeof value`; plus a canonical-spelling
control twin built in my scratch dir).
- Most case variants already work, because they fall through to a case-insensitive property lookup that finds a real function:
  `isnan`, `NUMBER`, `Math.FLOOR`, `String.FROMCHARCODE`, `_root.GETDEPTH`, MovieClip CallMethod, `onenterframe` handler names,
  `MATH`, `Stage.WIDTH` and more.
- **The broken ones are names whose global property holds a no-op stub, so only the `strncmp` arm does the work:**
  - bare CallFunction `parseInt`, `parseFloat`, `escape` and `Object` → undefined;
  - String primitive CallMethod `toUpperCase`, `charAt` and `indexOf` → undefined;
  - Array CallMethod `join` → undefined.

  That is 8 rows. The variant run equals the canonical twin after the fix.

**Prototype:**
- New `static swf6CanonBuiltinName(name, len, table)`. When `g_swf_version <= 6`, it maps a case variant onto the arm's canonical
  spelling. It returns `name` unchanged for SWF7+ or no match.
- Three NULL-terminated tables, holding every name the dispatcher's `strncmp` arms compare:
  - `k_swf6_cf_builtins` (38 names), applied at `actionCallFunction` entry (a `memcpy` into `_cf_buf`, same length);
  - `k_swf6_array_methods` (13), at `callArrayMethod` entry;
  - `k_swf6_string_methods` (13), at `callStringPrimitiveMethod` entry.
- `actionCallMethod`'s MovieClip arms already use `strncasecmp`, so they need no table.

34/42 → pass. The 31-row corpus sweep shows no movers.

**Caveat:** `g_swf_version` is the root's version (the same limit as s26's `_MC_NAV_NCMP`).

**Reverse leak (new lead):** the **SWF7 twin** shows case variants that **resolve in SWF7** although Ruffle is case-sensitive there:
- `(10).TOSTRING(16)` → `"a"`;
- `_root.GETDEPTH()` → −16384;
- `_root.CREATEEMPTYMOVIECLIP` creates the clip.

The cause is the `strncasecmp` MovieClip arms in `actionCallMethod` and the number-method path. The fixture is 37/40 on master and
on the prototype; its golden (`output.txt`) is the Ruffle-source prediction.

The display properties (`_X`, `_NAME`) are correctly case-insensitive in every version: Ruffle `stage_object.rs get_by_name`
says "case insensitive, regardless of SWF version". Fixing the leak is S, but needs care: it is the mirror of this item and could
move SWF7 corpus rows. Price it after the exporter confirms the twin.

**Canonical-spelling bugs found by the census** (taken out of the landing fixture and unprobed beyond this):
- bare `getNextHighestDepth()` / `getInstanceAtDepth()` in **SWF6** return 0 / a clip. Ruffle: `VERSION_7`, so undefined. The
  CallFunction arms lack the version gate that the CallMethod path has.
- `Object().hasOwnProperty("a")` → undefined (Ruffle: false, `VERSION_6`).
- `getVersion()` → undefined. Ruffle defines no `getVersion` global, so this row is Ruffle-unknowable; Flash returns a version
  string.

## 7. Failing-row re-check

There are 10 failing rows that could reach these paths; they are listed in the sweep table. Every status and matching-line count
is identical to the baseline.
- `globals_swf5`'s residual (−10) is SWF5 class *availability*, not case. Examples: `LoadVars` and `LocalConnection` are
  `[type Function]` in Flash's SWF5 output and undefined in ours, and `TextField` is the reverse. That is not this brief.
- The action_order family and the `global_*` rows were not re-diagnosed (standing NO-GOs, and nothing moved).

---

## Functions touched (for sibling coordination)

**`SWFModernRuntime/src/actionmodern/action.c`:**
- **New statics:**
  - item 2: `tfVarPathSep`, `tfVarScopeClip`, `tfVarResolveTarget`;
  - item 4: `tf_snf_slot`, `tf_snf_defer`, `tf_snf_apply_pending` (+ `g_tf_snf`);
  - item 5: `tf_selected_range`, `tf_is_password`, `tf_replace_selection`;
  - item 6: `swf6CanonBuiltinName` (+ 3 tables);
  - item 1: `ng_defbutton_won_pick`.
  - Forward declarations of `tf_replace_selection`, `tf_fmt_flag_set` and `ng_roll_pick_topmost`.
- **Modified:**
  - item 2: `actionNotifyPropertyChange` (registry separator), `actionTryBindTextFieldVariable` (path branch, retry
    registration), `ng_syncTextToVar` (path branch);
  - item 4: `actionSetMember` (two one-line `tf_snf_apply_pending` hooks: the `text` arm and the html-synonym `htmlText` arm),
    `actionCallMethod` (the `setNewTextFormat` arm only);
  - item 6: `actionCallFunction` (entry canonicalization only), `callArrayMethod` and `callStringPrimitiveMethod` (entry line);
  - item 5: `actionTextControlCopy`, `actionTextControlCut`, `actionTextControlPaste`, `actionTextFieldInput` (body moved);
  - item 1: `actionDispatchMCPress`, `actionDispatchMCMouseMove`.

**`SWFModernRuntime/src/libswf/tag.c`:** `ng_update_button_states` (publishes the outermost pick), plus new
`ng_btn_last_pick` and its 3 statics.

**Not touched:** `swf.c`, `swf_core.c`, `tag_stubs.c`, `ng_shared.c`, `timer.c`, the recompiler.

**Sibling overlap:**
- `w1-timers-robustness`: none.
- `w1-browser-avm1-gaps`: `createTextField`'s browser arms are not touched.
- The local N ladder: `tag.c` `ng_update_button_states` gets 8 lines after the PICK phase.

## Refutations / premise attacks (summary)
- **Item 1, "M":** the pick already exists in `tag.c` (s26 three-phase), so the merge is S. The bigger bug was unbriefed:
  `onPress` fired on *every* overlapping clip, and on children of handler clips.
- **Item 2, "scope":** scope is one of three bugs. The `:` separator (the brief's own `_root.mc:foo` example) and the
  never-registered retry both fail on master, and so does the same-frame ghost-clip case (2b).
- **Item 3:** intermediate-segment `__resolve` already works. Only the final segment differs, and that may be Ruffle-specific.
- **Item 4, "render":** the defect is visible in **trace** (`textWidth`/`textHeight`), not only in pixels.
- **Item 5, "Cut/Copy":** Paste is equally wrong, and all three were silent no-ops on `createTextField` fields.
- **Item 6, "grep the arms":** only stub-backed names break. Most variants already work through the case-insensitive property
  lookup. The census also found the **reverse** bug, SWF7 MovieClip arms that are case-*in*sensitive.

## New unclaimed leads
1. **Same-frame ghost child** (2b, M): `GetVariable "mc"` during the parent sprite's frame-1 construction materializes a second
   `mc` under `_root`. Fixture: `avm1_edittext_path_variable_same_frame`. It probably affects any frame-1 script or binding that
   names a sibling placed in the same frame of a nested sprite, not only text bindings.
2. **SWF7 case leak** (S): `actionCallMethod` MovieClip arms (`strncasecmp`) and number methods resolve case variants in SWF7+.
   Fixture: `avm1_swf7_case_sensitive_builtins`.
3. **SWF6 version gate on bare `getNextHighestDepth` / `getInstanceAtDepth`** (XS). Ruffle `VERSION_7`; our CallFunction arms
   answer in SWF6.
4. **`Object().hasOwnProperty` → undefined in SWF6** (XS–S, unprobed root cause).
5. **The other two `.`-only path-variable sites** (XS): `actionSetMember`'s legacy scan and `tfDynamicRebindVariable`.
6. **maxChars**: ours truncates the tail, Ruffle clips the insertion (`available_chars`), for typing and paste (XS + an input
   fixture).
7. **`setNewTextFormat` leading/margins/indent/letterSpacing/align/tabStops** apply to existing text immediately. This is the same
   class as item 4, with the same deferral (XS each).

## LOCAL ORACLE REQUESTS

The fixtures are in `w1-avm1-leftovers-fixtures/`. Each holds a committed `test.swf`, and `python3 create_test_swf.py test.swf`
regenerates it byte for byte.

1. **Exporter, frame traces** (`exporter -s -f <num_frames> --trace-log out.txt test.swf out.png`). For each, compare
   `out.txt` with the committed `output.txt`.
   - `avm1_swf6_case_insensitive_builtins` (`-f 3`). Expected: 42 lines.
   - `avm1_swf7_case_sensitive_builtins` (`-f 3`). Expected: 40 lines, every variant undefined except `_X`/`_NAME`/`unescape`.
     This settles lead 2.
   - `avm1_set_new_text_format_size` (`-f 1`). Watch `unchanged w=true h=true` and `size0=12` on line 2.
   - `avm1_resolve_dotted_getvariable` (`-f 1`). Watch whether `  resolve zz` is printed before `o.zz` / `m.zz`. The golden
     says no; ours (`output.ours.txt`) says yes. A **Flash** capture of this one decides item 3.
   - `avm1_edittext_path_variable_scope` (`-f 5`) and `avm1_edittext_path_variable_same_frame` (`-f 4`). Both should print
     `s.mc.foo=F … s.t5.text=X`.
2. **Ruffle test runner (input.json):**
   - `avm1_mc_button_unified_pick` (`num_frames = 22`; MouseMove/Down/Up per zone, one step per frame). Expected: the 21
     committed lines; Z2 is B2 only, Z3 hi only, Z4 par only.
   - `avm1_edittext_cut_copy_selection` (`num_frames = 6`; Copy / Paste / Cut / Cut+Copy / Paste). Expected: the 9 committed lines.
3. If a golden matches, land the dir under `regression/` with the prototype's corresponding hunk. The two HOLD fixtures
   (`_same_frame`, `_swf7_`) stay out of `regression/` until their fix lands.
