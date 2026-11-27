# w1-native-table LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27, FP32 LNX direct pinned)

- Req 1 (`min_swf` column): `fx/<test>.v{5,6,7,8}/test.swf` = the corpus SWF15 bytecode with the header version byte
  patched (v5 decompressed to FWS). Outputs `<test>.v<N>.lnx.txt` (`_delete` with `--log-warnings`, auto).
  - v5: degraded to 2 lines (`Testing _global` / `Done`): the walk needs SWF6+ ops. Presence at v5 needs a v5-native probe.
  - v6 4077 / v7 4097 / v8 4562 lines (`global_proto_decls`); v6 vs v7 differ by 72 lines; v8 vs the SWF15 golden differ by 24 lines (gating continues past SWF8).
  - `_delete`: v6 3917 / v7 3935 / v8 4165.
- Req 3 (`capabilities.manufacturer`): 2 more LNX runs of `global_proto_decls_delete` (`.v15.lnx.r2/r3.txt`) are
  byte-identical to the s30 pre-launch LNX capture: 3/3 fresh runs put `Testing _global.System.capabilities.manufacturer`
  at line 579; only the (older) golden has it at 582. So it is NOT run-to-run on today's host: the golden's host/build
  differs. WIN ≠ LNX on this row (host-dependent members), so per the flash_fixes rule keep the golden; the 2 lines are
  an ACCEPTED/RvF disposition, not a swap.
- Req 2 (unobservable-columns probe): not run; wave 2 writes the fixture.
