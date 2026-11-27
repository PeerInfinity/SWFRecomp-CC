**Land the generated AVM1 native-object table (W2-a) + singleton cleanups (W2-c) + the Array/String identity merge
(W2-d) (M).** Source: `session30-fanout-reports/w1-native-table-report.md` and `w1-native-table-prototype.patch`
(branch `origin/fanout/w1-native-table`; merged to master's reports dir before you start, else fetch it). Generator
copies in `w1-native-table-gen/`.

1. **W2-a**: land the measured table pass (`scripts/gen_avm1_native_table.py`, generated
   `include/actionmodern/avm1_native_table.inc`, `avm1NativeTableApply` at the end of `ensureGlobalInit`, the
   constructor-placeholder repair). Keep only `SWF_NATIVE_TABLE=0` as a kill switch. Ledger from the report: 0 flips,
   the 6 owned rows Flash-ward (`global_proto_decls` 2593 → 878, `_delete` 2215 → 781, `global_instance_decls` 1073 →
   743, argstest-v6/7/8 down), 76-row guard sweep 0 moves.
2. **W2-c (S)**: drop the own `toString` on `Accessibility/Stage/Key/Mouse/Selection/Math` and `Sound.prototype` (FP32
   inherits `Object.prototype.toString`; guard every `"" + Key`-style print in the corpus), the `ASnative`/`ASSetNative`
   own-props swap, `_global.o` stub, and the ~10 inert stubs of report §2.5 (version-gated: see 4).
3. **W2-d (M)**: one `Array` / `String` constructor identity (the GetVariable builtins arm's
   `g_array_constructor_static` / `g_string_constructor` must BE `_global.Array` / `_global.String`); probe
   `_global.Array.NUMERIC` first; eager Accessibility methods gated by SWF version instead of `ensureAccessibilityMethods`.
4. **`min_swf` column**: FP32 per-version dumps now exist (`session30-fanout-reports/w1-local-oracles/w1-native-table/`
   README: the corpus walk at SWF 6/7/8 LNX; v5 degraded to 2 lines, so v5 presence needs its own probe: write a v5
   MTASC/`create_test_swf` fixture as a FLASH request if a stub depends on it). Use them for the gating of anything you
   add. The `manufacturer` position: 3/3 fresh FP32 LNX runs agree with the pre-launch capture (line 579) and only the
   old golden differs; WIN ≠ LNX on this row, so it is an ACCEPTED/RvF disposition (write it), not a flash_fixes swap.
5. Guard: the report's 76-row sweep + every row touching `Key/Mouse/Stage/Selection/Math/Sound/Accessibility/Array/String`
   statics (argue it, ≤ ~80 rows), both modes. Every move by name. Expected flips: price them (the report expects 0 for
   W2-a; say what W2-c/d add).
**You own `setupNativeFuncOwnProps`, the native member tables, `ensureGlobalInit` and the native singleton setup.**
Siblings: w2-array-forin-proto (`actionEnumerate2` ARRAY arm), w2-native-instance (instance layout, XML ctor, filter
instance defaults), w2-drift-smalls-land (tabIndex arms). Name every function you touch.
