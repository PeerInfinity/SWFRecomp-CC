**gnash hidden-gap HOLDs with Flash answers (M).**

Inputs: `w1b-rm-gnash-report.md` (on master; its B1–B5 prototype LANDED as `ace9d2f88`), the probe
`w1b-rm-gnash-fixtures/avm1_gnash_flash_probes/`, and the coordinator's Flash 32 traces of it at SWF 8/6/5 in
`w1-local-oracles/w1b-rm-gnash/` (README). Flash differs from our prototype output on P2 (no `func depth` lines: the
`with` nesting cap inside DefineFunction differs from frame level — re-check B2's counting rule), P3 (`setSelection`
arg-count rule, B10), P4 (the NaN `==` matrix, B11), P5/P6.

Task:
1. Fit and implement B10 (3 rows), B11 (4 rows: `ops-v5..v8` NaN identity + `"" < "0"`), and correct B2's rule inside
   functions from P2 — each to the Flash traces byte for byte, then the gnash rows they flip.
2. Then the cheapest remaining real flips from the w1b report: B6 (SWF5 hides Function.prototype from function
   objects: `Object-v5`, `Number-v5`, M) and B19 (`Global-v6` hidden inherited setter on SetMember, S–M).
3. Land the probe as `regression/avm1_gnash_flash_probes{,_v6,_v5}` with the Flash goldens (it must pass).
4. Re-word the stale gnash ACCEPTED_DIFFS entries the w1b report names (Math-v5..8 → platform split; ops-v8 → real gap,
   remove if flipped; Inheritance §1b → real gap).
Gate: all gnash `actionscript.all` rows + avm1 rows touching XML/with/String/Selection/NaN comparisons, both modes.
