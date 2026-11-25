**Occupied-depth PlaceObject: Flash's SWF-5 keep-both rule + drop Ruffle's warning line (M–L).**

Inputs: `w1-render-flash-headroom-report.md` §2, §5 (branch `origin/fanout/w1-render-flash-headroom` if not yet on
master) and the coordinator's Flash 32 captures in `w1-local-oracles/w1-render-flash-headroom/` (README there).
Measured facts (FP32, direct pinned):
- `from_gnash/misc-ming.all/place_object_test` (SWF 5): Flash keeps BOTH objects placed at one depth, the newcomer
  BEHIND the occupant (`#passed: 7`; root image capture
  `session27-fanout-reports/golden-provenance/from_gnash__misc-ming.all__place_object_test__output.direct-pinned.png`).
  The same SWF with the version byte patched to 6/7/8/10 → `#passed: 3 #failed: 4` (refusal, like us). **SWF 5 only.**
- **Flash never prints `Warning: Failed to place object at depth N.`** It is a Ruffle log line, and we print it to the
  trace (`tag.c` `tagPlaceObject2`, ~`:12688`). With it removed:
  - `from_gnash/misc-ming.all/place_object_test2` (SWF 6, ruffle_matched): FP32 == `output.txt` → **pass**.
  - `path_format_test` (SWF 6, rm): FP32 == golden + 1 Flash debug line; expect it to stay rm/mismatch — check.
  - `avm1/placeobject_occupied_depth` (SWF 15): FP32 == `output.txt` minus its 2 warning lines. The coordinator adds
    a flash_fixes entry for that golden at landing (so it stays passing); `from_shumway/fuzz/e1528…/output.txt` also
    carries the line — report what it needs (the coordinator will try FP32 on it).
  - Do NOT edit `fixes.json`; list the expected moves by name.

Task:
1. Implement the SWF-5 keep-both rule (newcomer behind, both rendered, both hit-testable/named) in `tag.c`
   `tagPlaceObject2` + the display list (a per-depth "under" chain or a sub-depth key: choose and justify; remove /
   replace / getDepth / name lookup / swapDepths semantics on the pair must stay sane). Ruffle-era SWF5 content is rare
   but gnash tests use it.
2. Remove the warning print (both modes: check `swf_core.c` / `tag_stubs.c` NO_GRAPHICS arms for the same printf).
3. Ledger: trace `place_object_test` rm → pass (its xtrace content then matches Flash), `place_object_test2` rm →
   pass; pixels `place_object_test` / `shape_test` excess drop (they stay failing vs their non-Flash goldens: give the
   numbers vs the golden AND vs the Flash root capture). Grep every corpus `output.txt`/`output.ruffle.txt` for the
   warning and every root-timeline occupied-depth Place (the w1 report's `occ.py` sweep: 4 gnash rows + avm1 +
   2 shumway fuzz) and give each one's expected status.
4. Gate: those rows + gnash `misc-ming.all` + avm1 rows with `depth`/`place` in the name + `regression`, both modes.
5. Fixture: `regression/avm1_place_occupied_depth_swf5` (SWF 5, two pairs, trace `getDepth`/names + image), golden =
   FLASH (write it under LOCAL ORACLE REQUESTS with the built SWF; land it with a placeholder golden marked HELD).
