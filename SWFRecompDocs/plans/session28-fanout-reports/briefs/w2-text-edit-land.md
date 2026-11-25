**Land the text-edit tail with the Flash answers (S–M).**

Inputs: `w1-text-edit-tail-report.md` (on master), `w1-text-edit-tail-prototype.patch` (three compile-time switches),
fixtures `w1-text-edit-tail-fixtures/`, and the coordinator's Flash 32 captures in `w1-local-oracles/w1-text-edit-tail/`
(README). Flash answers:
- (a) restrict-filtered key: Flash == `candidate.ruffle_fire_delete.txt` (fires onChanged and deletes the selection)
  → `TF_RESTRICT_DROP 1`.
- (b) setNewTextFormat paragraph keys: Flash == `candidate.ruffle_defer.txt` → the defer model (plus the getter half
  the report calls GO-shaped regardless).
- (c) AVM2 selection rect under a colorTransform: **Flash tints it** (== `candidate.tinted_master.png` in every gap
  pixel; Ruffle's untinted rect is wrong) → keep our master behaviour; write the RvF entry text (Ruffle draws the
  selection rect untinted) in your report.

Task: land (a) and (b) as real code (no leftover `#define` switches: delete the losing arms), and land all three
fixtures in `regression/` with FLASH goldens: the two `.flash32.txt` traces as `output.txt` (with their `input.json`),
and for (c) the Flash `draw()` capture `avm2_edittext_selection_cxform.draw.png` as `output.expected.png` with a
tolerance/max_outliers that passes our render while still failing the untinted candidate by a wide margin (state
both numbers). Gate: the 74 + 37 rows of the w1 report's sweep + avm1/avm2 `edittext`/`textfield`/`selection` rows +
`regression` text fixtures, both modes for the AVM1 items.
