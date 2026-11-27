**ruffle_matched pool, AVM1 + gnash side (M; re-price against FP32, then prototype the cheapest rules).**

156 rm rows at the baseline (`session30-fanout-reports/s30-baseline-trace-rm.txt`); about 110 have FLASH goldens
(s28 `trace-provenance.md`; re-derive per row from TP before citing). Yours: every AVM1-VM rm row in `avm1/`,
`from_gnash/*`, `from_shumway/` (AVM1 side), `regression/`, `timeline/`, `visual/`, `fonts/` MINUS the rows other slots
own: the native-object table rows + `ExternalInterface-v8` (w1-native-table), the gnash `action_order` / `loop` family
(w1-exec-order), `movieclip_hittest_shapeflag` + tabIndex (w1-drift-smalls).

Prior pricing of record: s28 `session28-fanout-reports/w1b-rm-gnash-report.md` (B6–B20g "priced, not worked"),
`w1b-rm-avm1-misc-report.md`, and s29 `session29-fanout-reports/w1-rm-avm1-gnash-report.md` (73 rows priced after +7
flips; its table is the newest per-row price). Register §1a "w1b priced" row names the completion cell of each bucket.

Task:
1. Re-run every row in your pool on origin/master (graphics; ≤ -P 2; it is a ~70-row argued sweep). Diff vs golden
   and vs `output.ruffle.txt`. Classify by OWNER mechanism, not symptom (memory: bucket by VM, label names symptoms
   not owners). Note every row whose price changed since s29 (the s29 landings moved some).
2. Attack the s28/s29 prices: the cheapest buckets named were B8 `loadVariables` meth (S, 0 standalone), B19 hidden
   setter walk (S–M), B20g singletons (`LoadBitmapTest`, `zeroframe_definesprite`, `loop_test7`, `displaylist_depths_test`,
   `levels`), B18 LoadVars re-entrancy, B12 watch+addProperty, B20a array enumeration, B20b setProperty in tellTarget,
   B6 SWF5 function `__proto__` visibility. Also the device-font metrics family on the AVM1 side (`device_font_no_ink`,
   `edittext_device_transform_metrics`, gnash `TextFormat-v7/8`, `EmbeddedFontTest`: is EmbeddedFontTest really a
   DefineFont3 advance-scale bug? that is the cheap half) and `target_paths/swf5/6` (L).
3. **Measured prototype** of every S rule you can land; exact rm→pass ledger by name, plus the Flash-ward line moves.
   Gate: the full pool + the `regression/` suite near each change + the AVM1 rows of the s29 rm-avm1-gnash gate.
   A `pass → rm` move on a `known_failure = true` test is a REGRESSION.
4. For everything you do not prototype: a one-line price + completion mechanism per bucket (update the s29 table).
   FLASH requests for any bucket whose rule needs an FP32 probe (ship SWFs + `Test.as`; MTASC recipe in CLAUDE.md).
Deliver `w1-rm-avm1-gnash-prototype.patch`. Siblings: w1-native-table (do NOT edit `setupNativeFuncOwnProps` or native
member tables), w1-drift-smalls (TextField tabIndex, hitTest), w1-exec-order (frame loops, `action_queue.c`).
Name every function you touch.
