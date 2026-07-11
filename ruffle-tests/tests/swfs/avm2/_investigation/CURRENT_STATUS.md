# avm2 Suite — Current Status

Last updated: 2026-07-10 — Stage 1 (ABC front-end) landed; no codegen yet.

**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **0 / 1,202 passing (expected).** Stage 1 landed the ABC front-end: the
  recompiler now parses + verifies every DoABC tag (see below) but emits no
  C for it, so every test still fails honestly (output_mismatch) at run
  time. First passes land with plan Stage 2 (hello_world end-to-end).
- **ABC front-end (Stage 1, 2026-07-10):** parser + verifier/resolved-IR in
  `SWFRecomp/src/abc/` (+ `include/abc/`). Inspect any SWF with
  `SWFRecomp/build/SWFRecomp --dump-abc <test.swf>` (readable dump: pool,
  classes/traits, per-method IR) or `--check-abc <swf...>` (machine-readable
  ABC-CHECK lines). Full-corpus sweep:
  `python3 SWFRecomp/tools/abc_corpus_sweep.py` (parsing only — safe to run
  locally on the whole corpus).
- **Sweep baseline (2026-07-10): 1,202/1,202 parse clean; 1,193/1,202 verify
  clean; 17,162 method bodies.** All 9 verify-flagged SWFs are correct flags,
  not front-end bugs:
  | test | result | triage |
  |------|--------|--------|
  | cpool_index_invalid_bytecode_1/2/3 | 1032 (×2), class-index | intentional bad bytecode; expects VerifyErrors |
  | verification | 1011 (opcode 0x6b) ×3 bodies | intentional (test4/5/6 expect 1011/1020/1021) |
  | verify_dxns_without_flag | 1114 | intentional (FP reports it as 1015 — note for error-parity later) |
  | verify_exception_target_two_jumps | 1024 | intentional (FP says 1030; same rejection, different code) |
  | verify_jump_to_middle_of_op | 1021 | intentional |
  | verify_stack | 1023 ×3 bodies | intentional; unreachable-overflow bodies correctly NOT flagged |
  | json_errors | 1031 scope unbalanced | never-called Flash-template function, genuinely unverifiable; FP/Ruffle never verify it (lazy). Test itself is unaffected. |
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
