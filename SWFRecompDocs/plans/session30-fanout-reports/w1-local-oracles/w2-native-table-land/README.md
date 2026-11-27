# w2-native-table-land LOCAL ORACLE REQUEST 1 (s30 coordinator, 2026-11-27)

FP32 LNX direct pinned, 3 frames: `v{5,6,7,8}.lnx.txt` for `native_identity_probe.v{5..8}.swf` (copied from
`fanout/w2-native-table-land`, `w2-native-table-land-fixtures/`), against the slot's `v*.ours_after.txt`.

**Confirmed (identical lines, all versions):** `Array === _global.Array`, `_global.Array.NUMERIC == 16`,
`String === _global.String`, `typeof String.fromCharCode`, `[].constructor === _global.Array`, `Key.constructor ===
Object`, Key own toString false / string `[object Object]`, the AssetCache stubs at v6+, ASSetNative own props.

**Residues (ours ≠ FP32):**
1. **v6–v8: `ASnative` has NO `__proto__` and no `constructor` at all** (`typeof ASnative.call` = undefined,
   `ASnative.__proto__` = undefined; FP32 v6 prints `hasOwnProperty` empty, v7/v8 `undefined`). Ours still has both
   (own, and `ASnative.call` is a function). The patch's "empty own bag" hides them from enumeration only.
2. **v5: `hasOwnProperty` does not exist** (FP32 prints empty for every `x.hasOwnProperty(...)` line; ours `true`).
   `Object.prototype.hasOwnProperty` is SWF6+-hidden in Flash; ours is visible at SWF5. Pre-existing, not this patch.
3. **v5: `RemoteLSOUsage.getURLPageSupport` is a function** in FP32 (ours undefined: the stubs install at SWF6+).

All three are small and Flash-ward; none blocks landing (no corpus row moves on them per the slot's sweep).
