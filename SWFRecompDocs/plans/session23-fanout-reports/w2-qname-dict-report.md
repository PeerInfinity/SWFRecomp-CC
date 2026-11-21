# w2-qname-dict — AVM2 QName runtime names are multinames, not Dictionary keys; #1069 vs #1081 (session 23, wave 2)

**New files:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-qname-dict-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-qname-dict.patch` (the deliverable; 1 file, `SWFModernRuntime/src/avm2/avm2_ops.c`)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-qname-dict-sweep.tsv` (per-row before/after for all 311 swept rows)

No new source files, no fixture dirs, no `render_canary_tests.txt` change, no `SWFRecomp/` change (so `--recompile` is not needed).

## Verdict: GO on all three parts, part 3 included and NOT narrowed. +1 trace flip, 0 regressions.

| Part | What | Status |
|---|---|---|
| 1 | `dict_object_key()` rejects QName objects, so `dict[qn]` is a multiname access | **GO**, shipped |
| 2 | `in` keeps the identity lookup for a QName on a Dictionary | **GO**, shipped |
| 3 | single-namespace miss on a dynamic receiver is #1069 (not #1081); runtime-name miss messages carry `uri::local` | **GO**, shipped in the prototype's full width (lead 3 included) |

The env gates `W1_NO_QNAME_DICT` and `W1_QN_ERR` are gone; everything is unconditional.

## EXPECTED-FLIP LEDGER (what the coordinator should see on CI)

| Axis | Test | Before | After |
|---|---|---|---|
| trace (both modes) | `avm2/dictionary_qname_keys` | output_mismatch 29/45 | **pass 45/45** |
| pixel | none | — | — (render canary 144/144 md5-identical) |

Nothing else should move. CI should run `categories=full`, because this is AVM2 runtime code and from_avmplus pins the error codes. Graphics mode is the per-change mode. `avm2_ops.c` is shared runtime with no `NO_GRAPHICS` arm, so a no-graphics run is optional. I checked the headline row in no-graphics locally too: it passes.

## Headline before/after (clean origin/master `0ed6fef6d` vs this patch, same box, `--mode=graphics`)

| Test | Before | After |
|---|---|---|
| `avm2/dictionary_qname_keys` | output_mismatch 29/45 | pass 45/45 (graphics **and** no-graphics) |

## Part 3 risk sweep (the brief's gate): 311 rows, 0 moves besides the headline

I ran every row on clean origin/master (a separate worktree) and with the patch, on the same box at `-P 2`, in graphics mode. Per-row data is in `w2-qname-dict-sweep.tsv`.

| Sweep | Rows | Selection argument | Moves |
|---|---|---|---|
| 1 | 113 | Every avm2 / from_avmplus `output.txt` containing `1069`/`1081` (30). Every from_avmplus `Test.as` containing `1069`/`1081` (22: `Error1069PropertyNotFound`, `Error1081ReadSealedErrorNs`, `AccStatPropViaSubClass[WIntermediate]`, `bug_678952`, `WildcardOperator`, `bug_654807_swf12/13`, `DictionarySubclass`, `nonindexproperty/v10,v11`, …). Every avm2 `output.txt` containing `ReferenceError` (28). The report's 44-row family: all 46 avm2 `*dictionary*`/`*qname*`/`*namespace*`/`*proxy*` rows plus `core_exceptions`, `catch_class` and `rtqname_not_namespace`. | headline only |
| 2 | 174 real (+25 helper subdirs that are not tests) | Lead-3 pricing: every from_avmplus `Test.as` mentioning `ReferenceError` (171), every from_avmplus `Test.as` using `ns::name` access, and avm2 `.as` sources using `ns::` | **0** |
| 3 | 14 + 10 | Parent test dirs of the helper subdirs that sweep 2 missed. Also 10 `regression/avm2_*` rows: the ones whose sources use Dictionary/QName/Namespace/`::`/ReferenceError, plus dynprop/findprop/typed-value/static-slot neighbours. | **0** |

- **Fidelity:** this box grades the same as CI. All 287 real rows of sweeps 1 and 2 have *before* statuses identical to `origin/ruffle-test-results` `results_graphics.json` at `08709f658` (0 mismatches).
- **After totals:** sweep 1 goes from 105 pass / 5 mismatch / 3 ruffle_matched to 106 / 4 / 3. Sweep 2 stays at 170 pass / 2 mismatch / 2 ruffle_matched. Sweep 3 is 24/24 pass in both legs.
- **Line counts:** no row other than the headline moved even its matching-line count.
- **`known_failure` check:** no `ruffle_matched` row changed, so no pass→ruffle_matched regression is possible.

**Lead 3 priced: +0 extra flips and 0 costs.** The `#1081`-on-dynamic rule is wider than Ruffle's, but none of the 311 swept rows depends on it. Removing it matches Ruffle and avmplus (`ScriptObject` picks `kReadSealedErrorNs` only for ns-set multinames). It also makes the code's own comment block consistent: it already argued by multiname kind, but then OR'd in `dynamic`.

## Mechanism (owner `SWFModernRuntime/src/avm2/avm2_ops.c`)

1. **`dict_object_key()` (≈253):** `if (avm2_qname_ext_of(name_val) != NULL) return 0;`. The Dictionary arm was shadowing the existing QName arms in `avm2_op_getproperty_dyn` and the set/delete paths, so `dict[qn]` was an identity key. 9 of the 16 diff lines in the headline row came from this alone.
2. **`avm2_op_in` (≈4135):** once part 1 is in, `in` would also route a QName to name space. Upstream says `namePubNs in dict` is false while `"name" in dict` is true, so on a Dictionary a QName name keeps the `avm2_object_find_dynamic_obj` identity probe.
3. **Error selection and text:**
   - **`getproperty_common` (≈729):** `ns_read = mn_attr || (mn_nsset && !mn_public)`. The `dynamic ||` term is dropped, and a public miss on a dynamic receiver still returns `undefined` above it. This follows Ruffle `core/src/avm2/object/script_object.rs` `get_dynamic_property` (line 384 at upstream `aa9f62a70`): `if multiname.has_multiple_ns() { InvalidNsRead } else { InvalidRead }`.
   - The attribute → #1081 arm (`as3/Vector/bug_678952`) is kept unchanged. The sealed-QName → #1069 contract (`catch_class`, `AccStatPropViaSubClass`) is unchanged; both rows were swept and still pass.
   - **Message text:** the new `static` helper `qualified_miss_name()` builds the `uri::local` spelling when there is exactly one non-empty URI. It is applied to the miss paths of `getproperty_qname` (#1069/#1081), `setproperty_qname` (#1056) and `avm2_op_getproperty_rtns_l` (#1069). This mirrors what `mn_display_name` already does for static sites. The snprintf runs only on the throw path.

## Graphics canary

- `render_canary.py capture` over the standing 89-test `render_canary_tests.txt`, before vs after, `-P 4`.
- Result: **144/144 PNGs IDENTICAL**, no trace-status or image-status changes.
- The change class (AVM2 property-miss errors and Dictionary QName keys) has no render surface, so no new canary member was added.
- The fast before leg (40 s) came from ccache content hits on the master `avm2_ops.c` compiled during the sweeps, not from stale binaries.

## Regression suite

10 `regression/avm2_*` rows pass in both legs: `e4x_parse_bounded`, `findprop_this_resolution`, `gc_dynprop_tombstone_purge`, `gc_string_survives_collect`, `goto_catchup_scale`, `localconnection_domain`, `reflect_trait_hooks`, `static_and_store_slots`, `tolerant_verify_quarantine`, `typed_value_ops`.

There is no new fixture. The new behaviour already has an external-oracle corpus test, the headline row itself, whose expected output is Ruffle's/Flash's upstream file (no `known_failure`).

## Refutations / premise checks

- **Brief premise "part 3 may cost from_avmplus #1069/#1081 pins": refuted.** All 22 from_avmplus sources that name those codes, and all 171 that test `ReferenceError`, are unchanged.
- **The prototype's rule is exactly the full-width rule.** Under `W1_QN_ERR`, its `(!nsset && !public) ? attr : (dynamic || attr || (nsset && !public))` reduces to `attr || (nsset && !public)`, because the `dynamic && public` case returns before it. So the w1 44-row sweep had already exercised the full width; I widened it to 311 rows.
- **Upstream drift:** tests were downloaded fresh from upstream Ruffle master on 2026-11-21 (≈17:15 UTC; upstream HEAD shortly after was `aa9f62a70`, past the brief's `0ddd12b6a`). None of the 287 CI-comparable rows differs from CI's `08709f658` grading, so no drift reached this sweep.

## Not finished

Nothing. CI grading of the ledger is the coordinator's step (`categories=full`, graphics).

## New unclaimed leads

- None found in this slot. The 311-row sweep turned up no row whose miss error code is still wrong.
- The other non-passing rows in the sweep were unchanged and are owned elsewhere: `avm2/avm1_root`, `dependent_strings`, `error_stack_trace_class_names`, `filereference_browse_select`, `verify_method_info_duplicate` and `xml_many_namespace_declarations` (drift, per w1).

## LOCAL ORACLE REQUESTS

none
