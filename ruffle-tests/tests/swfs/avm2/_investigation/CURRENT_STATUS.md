# avm2 Suite — Current Status

Last updated: 2026-07-10 — suite scaffolded, no AVM2 implementation yet.

**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **0 / ~1,149 passing.** The recompiler has no DoABC support yet
  (`SWFRecomp/src/swf.cpp:6170` stub); every test fails honestly at the
  recompile step. This is expected until plan Stage 2 (hello_world
  end-to-end) lands.
- Download: `ruffle-tests/download_tests.sh avm2` (opt-in — not in
  ALL_CATEGORIES until CI wiring lands with Stage 2). The category keeps
  AVM2 SWFs via `swf_is_avm2.py --filter-avm2` (inverted vs. the AVM1 suites).
- Run one test: `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Do NOT run the full suite
  locally (project rule).
- `ignored_tests.txt` seeded 2026-07-10 with 4 mechanical buckets (GPU/AIR 63,
  host-I/O 50, image-comparison 76, upstream known_failure 32 = 221 entries).
  Re-triage buckets as support grows; the ~694 non-ignored trace-only tests
  are the phase-1 ceiling.
- CI: NOT wired yet (deliberate — zero observable value while nothing
  passes; lands with Stage 2, see plan §5 Stage 0 note).

## Tranche targets (from the 2026-07-10 corpus survey)

1. **Tranche 1 (~90):** pure language — operators, coercion, primitives,
   strings, arrays, OOP/interfaces, functions/closures, try/catch.
2. **Tranche 2 (~50):** Vector, JSON, RegExp, object/proto edge cases.
3. **Tranche 3 (~60):** Namespace/QName/Proxy/Dictionary, ByteArray, AMF.
4. **Deferred:** XML/E4X (~51, needs XML engine — deferred but NOT ignored),
   frame-lifecycle tests (32 use addFrameScript → plan Stage 5), graphics.
