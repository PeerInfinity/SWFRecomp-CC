**ARRAY `for…in` walks the `__proto__` chain (W2-b; M).** Source: `session30-fanout-reports/w1-native-table-report.md`
§3 / §7 L1. FP32 lists enumerable INHERITED names when enumerating an array (the AS2 `Array.prototype.foo` gotcha);
our `actionEnumerate2` ARRAY arm (`action.c:~56872`) does not walk `__proto__`. It owns 524 lines of
`global_proto_decls` (`Key/Mouse/Selection/Stage._listeners.*`) and ~160 of `_delete`; `_listeners` also carries an own
`constructor` in FP32.

1. Implement Flash's order for arrays: own indices / own named props, then inherited enumerable names, in FP32's order
   (fit to `global_proto_decls` golden + a small FP32 fixture: an array with indices, own named props, and
   `Array.prototype.x` / `Object.prototype.y` added, enumerated at SWF 6 and 8; also `ASSetPropFlags` unhidden
   inherited names; write it with MTASC and ship a FLASH request if no existing golden pins the order. Check the
   existing goldens first: `avm1/array_enumerate`, gnash `array-v5..8` B20a "for-in order of an array with sort/length
   own props" (s28 w1b-rm-gnash) is likely the same mechanism).
2. Guard: EVERY avm1/gnash/shumway/regression row with a `for (… in <array>)` (grep test.as/.sc sources; argue the set),
   both modes; every move by name. A `pass → *` is a priced loss only if its golden is not Flash; otherwise a defect.
3. Measure on top of origin/master AND (if it has landed) w2-native-table-land: the `global_proto_decls` delta.
Ledger + kill switch `SWF_ARRAY_FORIN_PROTO=0`. Siblings: w2-native-table-land owns native tables/`ensureGlobalInit`;
you own only the enumerate ARRAY arm (and helpers you add). Name every function.
