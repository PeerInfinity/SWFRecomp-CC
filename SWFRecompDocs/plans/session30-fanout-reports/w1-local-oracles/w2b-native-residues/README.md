# w2b-native-residues LOCAL ORACLE REQUEST 1 (s30 coordinator, 2026-11-27)

FP32 LNX direct pinned, 3 frames: `v{5,6,8}.lnx.txt` for `residue_probe.v{5,6,8}.swf` (copied from
`fanout/w2b-native-residues`), against the slot's `v*.ours_after.txt`.

**Identical on every line except line 21, at all three versions:** `for (k in Object)` → FP32 `Object keys: ` (empty);
ours after the patch `__proto__,constructor,` (before the patch: `registerClass,`). Both legs are wrong; the L2
identity merge exposed `_global.Object`'s own `__proto__`/`constructor` as enumerable. Fix: those two own slots of
`_global.Object` are DONT_ENUM (as `registerClass` already is). Everything else confirmed: the SWF5 receiver
matrix, ASnative's member list + `instanceof`, the L2 identity lines, `Object.prototype = 5`, `_global.hasOwnProperty`.
Not promoted to `regression/` until line 21 matches.
