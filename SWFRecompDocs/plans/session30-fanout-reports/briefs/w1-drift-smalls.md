**Upstream drift `b7ff32d93..origin/master` + the flash_fixes STALE/UPSTREAMED check + four small trace leads (S each).**

A. **Drift (S).** Upstream Ruffle since the s29 drift slot: `b7ff32d93..66f9073de` (11 commits, 2026-11-27; re-fetch and
   extend if newer). One new corpus row: `avm2/xmldocument_tostring` (`Test.as` + `output.txt`). Run it (graphics),
   report status; if it fails, implement the rule (AVM2 `XMLDocument`/`XMLNode.toString`; name the functions). Its golden
   may be Ruffle-made: read the upstream commit/PR, and if not Flash-provenance write a FLASH trace request (ship the SWF).
   `git diff --stat b7ff32d93 origin/master -- tests/` for any other moved golden/toml, each named with its status.
B. **flash_fixes check.** After your download (every category with an entry), `python3 ruffle-tests/apply_flash_fixes.py
   --check`. 94 entries now (93 + `from_shumway/acid/acid-large`, added at s30 launch). Report every STALE / UPSTREAMED
   line with the upstream commit that caused it, and for a STALE one whether the fix still holds.
C. **TextField `tabIndex` (S, implement).** FP32 capture at s30 launch:
   `session30-fanout-reports/pre-launch-oracles/tf_tabindex_null/` (`Test.as`, v6 + v8 SWFs, FP32 outputs as
   `v6/output.txt`, `v8/output.txt`; README §7). Our null rule already holds for text fields. Gaps: a NEGATIVE value
   unsets (`-1` → `undefined`; ours 4294967295), `delete t.tabIndex` is a no-op (ours unsets), `tabIndex` is enumerable
   on a text field (ours not). Make the fixture pass; add it as `regression/avm1_tabindex_textfield_v6` / `_v8` (golden =
   the FP32 file). Check clips/buttons for the negative and delete rules too (`regression/avm1_tabindex_*` from s29 w2b
   are FP32 goldens; if a clip/button probe is needed, write a FLASH request).
D. **`avm2/html_text_img_parsing` #2044 path (S–M, price + prototype).** rm, 505/600. Fresh FP32 LNX capture
   (`pre-launch-oracles/html_text_img_parsing/lnx.txt`): LNX prints the same 95 `Error #2044: Unhandled IOErrorEvent`
   lines as the (Windows) golden; LNX ≠ golden on exactly 1 line (510: `#2035 URL Not Found` vs LNX `#2124 Loaded file
   is an unknown type`). So the platform-split NO-GO (register §1a) covers 1 line, not the row. Implement the unhandled
   ErrorEvent #2044 report for an `<img>` load failure (s29 `w2-disposition-land-report.md` L2 names `ul_deliver`); price
   the row (it cannot reach pass without the platform line; say which side we print and why).
E. **`avm1/movieclip_hittest_shapeflag` lines 71 and 296 (S–M, diagnose + prototype).** Pre-launch README §1: golden ==
   FP32 LNX; lines 171–177 stay ACCEPTED (device fonts). Line 71 (`// layers` section, `hitTest(300, 400, true)`: FP32
   `true`, ours `false`) is shape geometry. Line 296 (morph boundary: FP32 `false`, ours `true`) matches Ruffle's
   integer-twip morph path (`lerp_twips` + i64 cross product; memory note "Ruffle geometry is integer twips"). Name the
   owner of each, prototype, and run the hitTest family (`avm1/*hittest*`, `regression/*hittest*`) A/B. The row cannot
   flip; it is a lead, so price it as 2 lines.
Deliver `w1-drift-smalls-prototype.patch` with a per-item before/after table. Siblings: w1-rm-avm1-gnash (AVM1
builtins), w1-native-table (`setupNativeFuncOwnProps`, native member tables: do not edit those). Name every function.
