**Shumway acid rows with FLASH goldens (M): `acid-mask` output.01/.05/.10 (12k/11k/9.4k excess, max 124–128),
`acid-shapes` (88 excess, max 197), `acid-shapes-testing` (41339), `acid-stroke-0` (52702), `acid-textfield` (15754).**

All seven comparisons have real Flash goldens (`session27-fanout-reports/golden-provenance.md` rows 296-304 and
691-710). Grep the playbook and prior session reports (s22–s27) for each row's history (STRIKE/NO-GO/priced) first.
`acid-shapes` is 88 channels over: find what they are. `acid-mask` max_diff ~124 across 9–12k channels suggests one
systematic mechanism (mask AA / alpha) — test that.

Task: per row, per-region diff vs the golden, the mechanism, a priced verdict; prototype the cheapest real
mechanism(s). Gate: render canary + every passing `from_shumway/acid/*` comparison + `visual` mask rows.
