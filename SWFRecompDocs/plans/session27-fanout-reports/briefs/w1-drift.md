**Upstream drift** `3e98d9ba6..1e604fa87` (14 commits; re-check `git -C /root/ruffle log 3e98d9ba6..origin/master` when you start, more may have landed). Categories: `avm2`, `visual`, `avm1`, plus any other category the drift touches.

The commits that touch `tests/` or behaviour we mirror:
- `5128d3943` swaps a **Flash Player reference** into `avm2/pixelbender_dithering` (limit 32500; we are 34301 at `df7729df2`). It is the first real Flash oracle for our CPU PixelBender path (`avm2_pixelbender.c`, bitmap-fill arm added in s26 `1aef9cc7b`). Diagnose the remaining excess by region (dither pattern, edge, colour rounding?), measure against the Flash PNG, and prototype if a mechanism is clear. Never regress this row for a Ruffle match.
- `7facc1fcc`: Flash Player reference for `bitmapdata-clone` (find the row, grade it before/after).
- `d87764213`: JPEG reference tests re-rendered at high quality. s26's last run moved none of our rows; confirm by name against your fresh download, and say whether any limit changed.
- `bc2d4aedc` / `50f28249e`: SharedObject.getLocal under `allowNetworking` (new test + AVM2 behaviour). Grade the new row; prototype the AVM2 behaviour if it fails (Flash-over-Ruffle; read the commit's rationale).
- Behaviour-only commits to price for riders: `cbd7e19b6` (AVM2 rollOut/rollOver dispatch loop shared), `3bbda49f5` (AVM1 level-number sign parsing via strip_prefix: does `_level-1`/`_level+1` parse differently from before, and from us?), `0c7a84f61` (escaped HTML text push), `1e604fa87` (shape path/style zip).

1. Re-run `download_tests.sh` for the touched categories, name-status the drift at your download SHA, and pre-label every expected denominator / status / pixel move the next CI run will show from drift alone (the coordinator reads the interim CI against your list).
2. Price and prototype each fixable row (measured, both modes for shared code).
3. Rider sweep over neighbours (`pixelbender_*`, `bitmapdata_clone*`/`bitmapdata-*`, `shared_object*`, `jpeg*` rows, AVM1 `_level` parsing rows).

A measured, sweep-clean prototype is landed directly by the coordinator, so make it CI-grade.
