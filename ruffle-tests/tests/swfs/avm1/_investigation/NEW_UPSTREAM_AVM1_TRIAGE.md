# New Upstream AVM1 Tests — Triage (2026-06-19)

The `avm1` suite grew from 654 → **701 tests** as `download_tests.sh` syncs fresh
from `ruffle-rs/ruffle` master each run. The older `CURRENT_STATUS.md` "100%
filtered, zero failures" claim was based on the 654-test snapshot and is stale.
This doc triages every non-ignored failing avm1 test in the fresh CI
`results.json` (SHA `1bef9e7b1`, 2026-06-19), so future sessions don't have to
re-discover them.

How the list was found: glob `**/test.swf` on disk minus the `test` names in
`_results/results.json`, then filter `results.json` for status ∉
{pass, ruffle_matched} and not in `ignored_tests.txt`.

## Already resolved this session

- **`watch_special_recursion_{swf6,double_swf6}` → ruffle_matched**;
  **`{swf7,double_swf7}` segfault → clean output_mismatch** (ignored). Version-aware
  watch re-entrancy bound. See `ACCEPTED_DIFFS.md` Category 10 and the watch fix
  commit `1bef9e7b1`.
- **`geturl_target_normalize`, `geturl_opcode_target_normalize` → ignored.** They
  trace Ruffle's internal `Navigator::navigate_to_url:` dispatch log (URL/Target
  lines), not Flash trace output — same category as the long-ignored `geturl`. We
  don't (and shouldn't) emit Ruffle's navigator log.

## Remaining non-ignored failures (21 after the two geturl ignores)

### Bucket A — Infrastructure-blocked / deferred (11)

| Test | Need | Notes |
|------|------|-------|
| `amf_array_serialization` | AMF0/3 codec | Same deferred byte-exact AMF codec as the `shared_object` SharedObject tests (see `_investigation/NEW_UPSTREAM_TESTS_TRIAGE.md`). |
| `amf_serialize_typed_objects` | AMF0/3 codec | " |
| `netconnection_serialize_arrays` | AMF0/3 codec | " |
| `file_reference_list_browse_cancel` | FileReference file-dialog input | Headless has no OS file dialog; needs a synthetic browse-result injection path in `verify_output.py`. |
| `file_reference_list_browse_select` | FileReference file-dialog input | " |
| `file_reference_list_browse_invalid_filters` | FileReference file-dialog input | " (50% — partial: validates filter parsing before the dialog). |
| `looping_child_swf5` | Multi-SWF child-frame execution | Child SWF frames/labels don't advance/label correctly ("in frame" vs "in child frame"). |
| `looping_child_swf9` | Multi-SWF child-frame execution | " |
| `looping_child_swf32` | Multi-SWF child-frame execution | " |
| `shared_stack` | Multi-SWF child-frame execution | Stops at the child's frame 2; child frames don't run. Same root family as `looping_child_*`. |
| `load_cancel_via_removemovieclip` | loadMovie cancel lifecycle | Cancelling an in-flight load by removing the target clip; likely tied to the multi-SWF load path. |

### Bucket B — Documented / known (1)

| Test | Notes |
|------|-------|
| `sound_setters` | Sound `setVolume` after `mc._name` rename needs `_root.<varname>` to survive the rename — the soft-reference rebinding gap already noted in `CURRENT_STATUS.md` (2026-05-22) and `[[soft-ref-rebinding-blocks-movieclip-vN]]`. |

### Bucket C — Tractable, no infra needed (9 — future-fix candidates)

| Test | % | Effort | Notes |
|------|---|--------|-------|
| `set_property_values/swf5` | 92.9% | Medium-large | Per-property value coercion/clamping. e.g. extreme sets should read back `-107374182.4` (= INT_MIN twips ÷ 20) but we return 0; some sets should reject (read 0/1) but we keep 10. **No `output.ruffle.txt` → needs full match** (123 lines). |
| `set_property_values/swf6` | 92.9% | Medium-large | Same source, SWF6 gates. |
| `set_property_values/swf7` | 92.9% | Medium-large | Same source, SWF7 gates. |
| `set_property_values/swf4` | 22.3% | Large | Same source but a much bigger SWF4 gap (likely SWF4 property-number addressing). |
| `coerce_to_primitive_resolve` | 72.7% | Small-medium | `__resolve`-through-`toString`/`valueOf` coercion ordering; a `[type Object]` line emitted out of order + one trailing line short. No ruffle file → full match. |
| `array_unshift` | 79.5% | Medium | Array `unshift` sparse/own-property + length semantics (gnash array-vN territory; see `[[array-shift-densify-enum]]`). No ruffle file. |
| `array_reverse` | 66.4% | Medium | Array `reverse` sparse/own-property semantics. No ruffle file. |
| `virtual_property_special_recursion_swf6` | 16.7% | Medium | `addProperty` getter/setter deep re-entry (the accessor analog of the watch fix). Two issues: setter arg order is swapped (`setter: ,b` vs expected `setter: b,`) and the recursion-fallback value/ordering differs. Uses the existing `g_active_accessors` machinery. |
| `virtual_property_special_recursion_double_swf6` | 27.3% | Medium | Same as above, mutual prop1↔prop2. |

## Recommended next targets

1. **`coerce_to_primitive_resolve`** — smallest tractable gap (~6 lines), self-contained `__resolve`/coercion ordering.
2. **`virtual_property_special_recursion_swf6/double_swf6`** — adjacent to the just-landed watch fix; the setter-arg-order bug looks like a contained dispatch fix that may also help the `set`/`addProperty` family broadly.
3. **`set_property_values/swf5-7`** — 93% and self-contained, but a full-match line grind (twips overflow + per-property reject rules) with no RM shortcut.

Bucket A is genuinely blocked on infrastructure (AMF codec, file-dialog input, multi-SWF child frames) — low ROI until a shipped game or a larger test cohort needs those subsystems.
