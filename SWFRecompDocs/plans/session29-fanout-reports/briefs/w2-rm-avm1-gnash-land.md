**Land w1-rm-avm1-gnash P1–P4, P6–P9 and replace P5 with the general MovieClip super context (M).**

Read `session29-fanout-reports/w1-rm-avm1-gnash-report.md` and `w1-rm-avm1-gnash-prototype.patch`. FP32 results:
`w1-local-oracles/w1-rm-avm1-gnash/README.md`.
1. Land P1 (`meth`), P2 (`_width` sign; FP32 confirms the `H` section), P3 (BOM), P4 (blendMode; FP32 confirms `B`),
   P6 (export frame gate), P7 (unloadClip cancels the queued load), P8, P9 as measured.
2. **P5 is refuted as scoped.** FP32 runs `super(...)` from a plain function called on a MovieClip: `U(7)` sets `u=7`,
   `Boolean(false)` makes `valueOf` return false, `Number(5)` gives `toString`/`valueOf` 5, wrong-type natives read
   `undefined`, `String.valueOf` gives the clip path. Implement lead 1 (push a super context for MC method calls, or
   resolve `this.__proto__.__constructor__` on demand) so `avm1_mc_super_native_probe` matches
   `super_native_probe.fp32.txt` byte for byte, and MovieClip-v6/v7/v8 still flip. Re-run the report's 282-row gate +
   56-row attach/export re-gate: a general super change can move other rows — list every move by name.
3. Add `regression/avm1_mc_super_native_probe` (golden = the FP32 capture) and
   `regression/avm1_rotation_matrix_fixed` from `w1-local-oracles/w1-rm-avm1-gnash/matrix_probe/` (golden `flash.txt`).
   If we fail the matrix fixture, implement 16.16 matrix entries for `_rotation`-derived matrices (prices `matrix_test`)
   if S; else ship the fixture only if we pass it and report the gap.
Ledger: the report's +6 rm→pass by name (both modes) + new rows; Flash-ward line moves on ExternalInterface-v8 and
String-v5. Siblings: w2-disposition-land (`actionNewObject` TextField arm, global-init tail, tabIndex block in
action.c), w2-timers-goto-land (`actionNextFrame`/`actionPrevFrame`, timer.c, `ng_executeGotoCatchUp`), the browser
ladder (`ng_gotoFrameByMC` same-frame branch). You touch `ng_shared.c` / `tag.h` / `swf.cpp`: name every function.
