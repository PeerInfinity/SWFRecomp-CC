# w2-native-instance LOCAL ORACLE REQUEST 1 (s30 coordinator, 2026-11-27)

FP32 LNX direct pinned, 3 frames: `fp32.lnx.txt` for the slot's `avm1_native_instance_layout/test.swf` (copied
from `fanout/w2-native-instance`, `w2-native-instance-fixture/`).

- vs `output.provisional.txt` (the patched output): **11 / 12 lines identical**; 2 diff lines (1 line).
- vs `output.before.txt` (clean master): 18 diff lines. The patch is Flash-ward on every section.
- The one residue, line 12: `sound for-in after unhide:` FP32 `[]`, ours `[checkPolicyFile,]`. FP32's
  `Sound.prototype.checkPolicyFile` is not visible to for..in on a `new Sound()` even after an
  `ASSetPropFlags(..., null, 0, 1)` unhide. This is the w2-native-table-land §4 "Sound.prototype.checkPolicyFile /
  areSoundsInaccessible" item (prototype accessor + instance layout), not this patch's.

Not moved under `regression/` (it would fail on line 12). It becomes a regression row with `fp32.lnx.txt` as its golden
once the Sound.prototype item lands.
