**AVM1 MovieClip `tabIndex` raw-string mode: fit the FP32 rule and land it (S).**

Context: `session29-fanout-reports/w2-disposition-land-report.md` §3 (the prototype rule was held), FP32 results
`w1-local-oracles/w2-disposition-land/README.md` (13 fixtures, `t00…t12`) and the MTASC captures
`w1-local-oracles/w1-disposition-audit/L3b_tabindex*/flash.txt` (class-main coerces on `_root`).
Facts: on the root, the first set being a string keeps tabIndex RAW in every bytecode form; a fresh
`createEmptyMovieClip` child coerces (t08); a READ before the first set coerces (t11). MTASC's class bootstrap also
coerces — find what it does to the root first (disassemble `L3b_tabindex_v8/test.swf`: does it read/enumerate the
root, or `ASSetPropFlags` it?) and fold it into the rule. Candidate: "raw while the property has never been accessed
and the clip was placed by the timeline", or a lazily-created native property. Prove the rule predicts ALL 13 + 4 MTASC
captures before implementing; also replace the `actionSetMember` NaN-keeps-previous arm (report lead L-tab) if the
captures show it wrong.
Land: `avm1/tab_ordering_properties_tab_index_edge_case` rm→pass; `tab_ordering_properties` and the 17 `avm1/*tab*`
rows unchanged; add regression rows for t08, t11 and one MTASC case with their FP32 goldens (copy SWFs; read
`regression/README.md`). If no rule fits all captures, deliver a HOLD with the table. Siblings: w2-rm-avm1-gnash-land
and w2-timers-goto-land edit action.c too — keep to the tabIndex block of `actionSetMember`; name every function.
