**ruffle_matched pool, AVM1 + gnash side: re-price the remaining w1b NO-GO/HOLD buckets against FP32 and prototype the
cheap ones (S–M per bucket).**

s28's w1b slots priced ~20 mechanisms and landed 73 rm→pass. What is left: `session28-fanout-reports/w1b-rm-gnash-report.md`
(§HOLD, §NO-GO / priced; 70 rows across 20 mechanisms) and `w1b-rm-avm1-misc-report.md` (§Rows: the AVM1 NO-GO/HOLD rows).
Current rm list: `s29-baseline-trace-rm.txt`. Golden provenance per row: `session28-fanout-reports/trace-provenance.md`
(rm rows with non-Flash goldens are NOT targets). Split by VM (memory note: triage by VM, not by symptom): this slot owns
AVM1-VM rows only (avm1, gnash, AVM1 shumway/timeline rows); AVM2 rows belong to w1-rm-avm2.

Cheapest named on the board: gnash `ExternalInterface-v8` (S), the `loadVariables` method rows (S). Then: the
load-cancel HOLDs (`load_cancel_via_unloadclip` — did s28's unloadMovie cancel `e7afd5ad2` fix the loadClip half?),
`attach_movie_export_not_yet_run` (Flash probe was built in s28 — is there a capture in `w1-local-oracles/`?),
`Inheritance-v6..v8` super re-resolution (M–L), and the native-object enumeration model ONLY as pricing (the
disposition-audit sibling owns that question).
Task: for every remaining AVM1 rm row with a Flash golden, a one-line current diff + owner mechanism + price. Prototype
every S/M you can measure; deliver `w1-rm-avm1-gnash-prototype.patch` with an exact rm→pass ledger by name and a
regression-suite + canary check. HOLD rows: name the Flash capture that would decide them (FLASH requests with SWFs).
Siblings: w1-disposition-audit (UNSURE items: native-object enumeration, tab_ordering, hittest_shapeflag, globals_swf5),
w1-timers-goto (gotoFrameFromInterval*). Name every function you touch.
