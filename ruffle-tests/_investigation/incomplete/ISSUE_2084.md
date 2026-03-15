# issue_2084 — Nested attachMovie with registerClass

**Status**: 4/16 (25%)
**Category**: Nested sprite init ordering

## Test Structure

Uses `registerClass` to bind Main and Column classes to exported sprites, then tests nested `attachMovie` initialization:

1. **Main class** (registered to export "main", char_id=4):
   - `onLoad`: creates two columns via `attachMovie("column", "col_mc_1", 1)` and `attachMovie("column", "col_mc_2", 2)`
   - First column at `_x=10, _y=1`; second at `_x=100, _y=20`

2. **Column class** (registered to export "column", char_id=9):
   - `onLoad`: attaches 4 icon sprites via `attachIcon` method
   - Icons positioned at `_y=20, 40, 60, 80`

3. **Root**: Places "main_mc" (sprite_4) at depth 0 → triggers Main.onLoad → triggers Column.onLoad for each column

### Expected output
```
col_mc_1 0,0          ← Column traces its position
col_mc_2 0,0
Column onLoad 0,0     ← First column onLoad fires, attaches icons
icon_1 20,20
icon_2 20,20
icon_3 40,20
icon_4 10,40
Column onLoad 0,0     ← Second column onLoad fires, attaches icons
icon_1 20,20
icon_2 20,20
icon_3 40,20
icon_4 10,40
onEnterFrame          ← Enter frame handler
col1 40,100
col2 0,0
```

### Current output (4/16)
```
col_mc_1 0,0          ✓
col_mc_2 0,0          ✓
Column onLoad 0,0     ✓
icon_1 1,1            ✗ (expected 20,20)
icon_2 20,20          ✓
icon_3 40,1           ✗ (expected 40,20)
icon_4 10,40          — missing, output ends
```

## Two Distinct Bugs

### Bug 1: Icon y-coordinates wrong (1 instead of 20)

`icon_1` and `icon_3` get y=1 instead of y=20. The value 1 is suspiciously the parent column's `_y` value (first column has `_y=1`). This suggests child sprites placed via `attachMovie` with `initObject` are inheriting the parent's y-coordinate instead of using the explicitly-set value from the initObject.

**Likely root cause**: When `attachMovie` applies initObject properties, the `_y` property may be set before the MC's position is fully initialized, or the nested MC x/y sync from the display object transform (added in the recent nested MC fix) is overwriting the AS-set `_y` value.

**Investigation needed**:
- Check order of operations in `attachMovie`: when are initObject properties applied vs when is the display_obj transform synced?
- Check if `as_set_flags` is properly set when initObject applies `_y`, preventing later transform sync from overwriting it

### Bug 2: Second Column onLoad never fires (lines 9-16 missing)

The entire second "Column onLoad" block and the onEnterFrame block are missing. The second column (`col_mc_2`) is created but its onLoad handler never executes.

**Likely root cause**: `attachMovie` fires `registerClass` constructor + `onLoad` for the first column. When the first column's onLoad runs (attaching icons), something prevents the second column's onLoad from queueing or firing. Possibilities:
- `actionQueueMCOnLoad` may not handle multiple pending onLoads from the same parent
- The first column's onLoad may consume the onLoad dispatch slot
- The second `attachMovie` may not properly trigger constructor/onLoad because it reuses the same registered class

**Investigation needed**:
- Check `actionQueueMCOnLoad` — does it support multiple queued onLoads?
- Check if both columns get their constructor called in `attachMovie`
- Check `ng_fire_child_constructors` and deferred onLoad dispatch order

## Files to Modify

- `SWFModernRuntime/src/actionmodern/action.c`:
  - `attachMovie` handler (line ~43892): initObject application order, onLoad queueing
  - `actionQueueMCOnLoad` / `actionDispatchQueuedOnLoads`: multiple pending onLoad support
  - Nested MC x/y sync (line ~33383): check interaction with initObject `_y`

## Related Tests

- `register_and_init_order` (233/233 PASS) — registerClass ordering (simpler case)
- `register_class_return_value` (16/16 PASS) — registerClass basics
- `init_object_order` (15/15 PASS) — initObject property application
- `loadmovie_registerclass` (PASS) — registerClass with loadMovie
