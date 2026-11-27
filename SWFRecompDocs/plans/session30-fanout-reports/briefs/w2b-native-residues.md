**AVM1 native-object residues that FP32 has now pinned (S each; land what is Flash-ward and moves no pass).**

Base: master `a18a0e033` or newer (w2-native-table-land + w2-array-forin-proto LANDED; w2-native-instance landing
next: rebase onto the newest `origin/master` before your final measurement). Read
`w2-native-table-land-report.md` §4/§7, `w2-native-instance-report.md`, and the FP32 answers in
`w1-local-oracles/w2-native-table-land/README.md` and `w1-local-oracles/w2-native-instance/README.md`.

1. **`ASnative` has no `__proto__` and no `constructor` at SWF6+** (FP32: `typeof ASnative.call` undefined,
   `ASnative.__proto__` undefined). Ours hides them from enumeration only.
2. **SWF5: `Object.prototype.hasOwnProperty` is not visible** (FP32 prints empty for every `x.hasOwnProperty(..)` in a
   SWF5 movie). Check the other SWF6+ Object.prototype members at v5 too (`isPropertyEnumerable`, `isPrototypeOf`,
   `addProperty`?): read the FP32 v5 dumps in `w1-local-oracles/w1-native-table/`.
3. **v5: `RemoteLSOUsage.getURLPageSupport` is a function** (stubs install only at SWF6+).
4. **`Sound.prototype.checkPolicyFile` / `areSoundsInaccessible`**: invisible to for..in on `new Sound()` even after an
   unhide (FP32, native-instance fixture line 12). Then move `w1-local-oracles/w2-native-instance/` into
   `regression/avm1_native_instance_layout/` with `fp32.lnx.txt` as golden (it must pass).
5. **L2 `Object` ctor identity** (`Key.constructor === _global.Object`, the String merge pattern), and **L3
   `_global.hasOwnProperty(k)` → undefined**. Probe each with an FP32-checkable fixture line first. If you build
   one, hand-assemble it and put it in LOCAL ORACLE REQUESTS.
6. **`avm1/global_instance_decls` nondeterminism** (w2-drift-smalls-land lead): `new BitmapData` instance lines flip
   between `[[object Object]]` and `[undefined]` across runs of one binary. Run it ≥ 5× under `--asan` / valgrind,
   find the uninitialised read, fix it. Determinism is a correctness bug.
7. **`global_instance_decls` TZ line**: the golden prints `GMT+0200` on 2020-04-04 (CEST). If `test.toml` / the
   runner can set `TZ` per test (check `verify_output.py`), use `Europe/Berlin`; else price it.
Ledger: every row in `w2-native-table-land-fixtures/sweep_list.txt` + the native-instance sweep, both modes, by name.
`global_proto_decls` is now **ruffle_matched** on master (combined landing); keep it there or better.
Siblings: w2-rm-avm1-gnash-land owns `builtin_asnative` ids 900/901 and the R1–R6 functions; coordinate through
named functions only.
