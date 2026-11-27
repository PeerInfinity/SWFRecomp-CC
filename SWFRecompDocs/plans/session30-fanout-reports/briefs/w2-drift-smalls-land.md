**Land w1-drift-smalls (items A, C, D, E) with the FP32 answers to its requests (S–M).**

Read `session30-fanout-reports/w1-drift-smalls-report.md` (on branch `origin/fanout/w1-drift-smalls`; the coordinator
merges it to master before you start, else fetch it) and its `w1-drift-smalls-prototype.patch`. FP32 answers:
`session30-fanout-reports/w1-local-oracles/w1-drift-smalls/README.md`.

1. **C, tabIndex, all targets.** FP32 (request 1): on timeline clips, script clips and Buttons, `-1` → `undefined`, `-2`
   and `-2147483648` stay, `delete x.tabIndex` returns `false` and keeps the value; v6 == v8. So land the prototype's
   text-field arms WITHOUT the `MC_IS_TEXTFIELD` gates (on clips the value is in `dynamic_props` as DONTENUM:
   `actionDelete` must skip it there too). Fixtures: the prototype's `regression/avm1_tabindex_textfield_v6/_v8` + a new
   `regression/avm1_tabindex_clip_button_v6/_v8` from the request-1 SWFs (golden = the FP32 files in
   `w1-local-oracles/w1-drift-smalls/tabindex_clip_button.v{6,8}.lnx.txt`). Re-run the 38-row tabIndex family.
2. **D, `avm2/html_text_img_parsing`.** FP32 per-case `#2044` counts (request 2; 2 runs identical): 1 per `<img src>`
   tag EXCEPT case 10, `<img src='a.jpg'><img src='b.jpg'>` with no surrounding text, which starts only 1 load (adjacent
   identical images are NOT merged; empty `src` still loads). Derive the rule (an image run that is the whole text?
   only the first of a leading image run? read Flash's HTML-to-TextFormat model in the row's golden HTML dumps),
   make the corpus count 95, and land D only if the row reaches PASS (rm → pass). Otherwise HOLD D with the measured count.
3. **A, `avm2/xmldocument_tostring` (new row).** Land the 23/32 prototype, then attempt the M completion: XMLNode/
   XMLDocument fields as real instance traits (slots or native getset backed by `Avm2XmlNodeExt`), every
   `xn_get`/`xn_set` moved onto them. Gate: the 10-row XML family + `all_classes/xml/*` (describeType: variable vs
   accessor; check FP32-provenance of those goldens) + for-in over an XMLNode. If the trait move costs any pass, land
   the 23/32 part only and price the rest.
4. **E, `movieclip_hittest_shapeflag` lines 71/296**: land as measured (recompiler `{6,0,0}` layer marker + scale-aware
   minimum stroke width); rebuild the recompiler and `--recompile`; re-run the 35-row hitTest family. Rewrite the
   ACCEPTED_DIFFS "Morph fill boundary precision" entry ("stroke minimum width ignored scale"; lines 171–177 remain
   ACCEPTED device-font outlines).
Ledger: +4 regression rows (2 textfield, 2 clip/button), `xmldocument_tostring` mm → mm (or pass), `html_text_img_parsing`
rm → pass (or HOLD), hittest_shapeflag mm → mm (6 → 4 lines). Both modes for the tabIndex rows (`action.c` shared).
Siblings: w2-native-table-land / w2-array-forin-proto / w2-native-instance edit other `action.c` functions; you own only
`actionSetMember` tabIndex block and `actionDelete`'s tabIndex arm in `action.c`. Name every function.
