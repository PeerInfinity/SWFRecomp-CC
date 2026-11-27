**The AVM1 native INSTANCE table + XML instance layout (W2-e; M–L).** Source:
`session30-fanout-reports/w1-native-table-report.md` §1.3–§1.5, §3 W2-e, §7 L4/L5. Owns gnash `ExternalInterface-v8`
(rm, 1 failing check: `_objectToXML(new XML())`; **the only rm → pass in reach**), most of `avm1/global_instance_decls`
and the instance half of gnash `argstest-v6/7/8`.

1. **XML instance layout (S–M, do first):** FP32 `new XML()` has the node fields as PROTOTYPE getters (`namespaceURI …
   nodeType`), `attributes` null, no `idMap`; ours puts them as own instance props and `attributes = {}`. Fix the XML /
   XMLNode ctor (AVM1). Target: `ExternalInterface-v8` rm → pass. Guard: all avm1/gnash/regression XML rows.
2. **Instance `__proto__` / `__constructor__` hidden** even after `ASSetPropFlags(inst, null, 0, 1)` (L4, 60 lines).
3. **Filter instance defaults** for `new XFilter()` (L5, 86 lines; FP32 numbers/booleans/arrays where ours is
   `undefined`): read the defaults off the `global_instance_decls` golden (= FP32 LNX).
4. Instance DONT_DELETE and `ColorTransform` instance accessors (report §1.3) if they fall out cheaply.
5. A second generator input (`global_instance_decls/output.txt`) only if it beats hand fixes.
Guard: the 76-row sweep from the w1 report + every row constructing natives (`new XML`, filters, `ColorTransform`,
`Sound`, `LoadVars`…), both modes; every move by name. `global_instance_decls` has 1 TZ line: add `mock_timezone` via a
flash_fixes toml entry only if the golden's capture TZ is known (+0200 at 2020-04-04: say which zone).
Siblings: w2-native-table-land (prototype tables, `ensureGlobalInit`), w2-array-forin-proto (enumerate ARRAY arm),
w2-drift-smalls-land (tabIndex). You own the XML/XMLNode ctors, filter ctors and instance setup. Name every function.
