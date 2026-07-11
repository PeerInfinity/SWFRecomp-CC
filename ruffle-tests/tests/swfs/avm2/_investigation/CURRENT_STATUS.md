# avm2 Suite — Current Status

Last updated: 2026-07-10 — Stage 2 (hello_world end-to-end) landed; first
passing test + CI wiring.

**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **1 / 1,202 passing (hello_world)** — the Stage-2 baseline. Every other
  test fails honestly: `runtime_error` with a named
  `AVM2: unimplemented op <Op> at op index N` on stderr (or a build/parse
  failure for exotic inputs). Stage 3 (tranche-1 opcode/coercion matrix)
  grows this.
- **What exists now (Stage 2, 2026-07-10, `0fec4fbe6` + `40e98bb42`):**
  - **Recompiler**: `SWFRecomp/src/abc/abc_emit.{cpp,hpp}` emits
    `RecompiledABC/` per test (static pools, class/script/trait registry,
    SymbolClass bindings, one C function per verified method body).
    Verify-failing bodies get an aborting stub. Opcode surface: exactly
    hello_world's 21 ops; anything else emits a runtime abort and truncates
    the body (safe while no branch op is in the surface).
  - **Runtime**: `SWFModernRuntime/{src,include}/avm2/` — `Avm2Value`
    (16-byte tagged, Ruffle-1:1 coercion names), ScriptObject + flattened
    vtables, scope chains, definition domain with lazy script init, builtin
    stubs (Object/Class/Function, EventDispatcher→…→MovieClip chain with
    `addFrameScript`, `trace`), `runSWF_avm2()` implementing the
    DoABC → SymbolClass → eager-last-script → root-construction ordering
    (Ruffle movie_clip.rs:4246-4255) + MAX_FRAMES tick loop.
  - **Harness**: `verify_output.py` auto-detects an avm2 test by the
    presence of `RecompiledABC/` after recompile, adds `src/avm2/*.c` and
    `-DSWF_AVM2` (routes `main.c` to `runSWF_avm2`). AVM1 builds are
    untouched (`swf_core.c`/`action.c` unmodified).
- **ABC front-end (Stage 1, 2026-07-10):** parser + verifier/resolved-IR in
  `SWFRecomp/src/abc/` (+ `include/abc/`). Inspect any SWF with
  `SWFRecomp/build/SWFRecomp --dump-abc <test.swf>` or `--check-abc`.
  Full-corpus sweep: `python3 SWFRecomp/tools/abc_corpus_sweep.py`
  (parsing only — safe locally). Baseline: 1,202/1,202 parse clean,
  1,193/1,202 verify clean; all 9 flags triaged as correct (see git history
  of this file for the table).
- Download: `ruffle-tests/download_tests.sh avm2` (now in ALL_CATEGORIES).
- Run one test: `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Do NOT run the full
  suite locally (project rule) — full suite via CI.
- CI: wired (Stage 2) — `ruffle-tests.yml` runs the suite under
  `categories=all|no_gnash|avm2`, shards it like avm1, and commits
  `_results/` to the `ruffle-test-results` branch.
- `ignored_tests.txt` seeded 2026-07-10 with 4 mechanical buckets (GPU/AIR
  63, host-I/O 50, image-comparison 76, upstream known_failure 32 = 221
  entries). The ~694 non-ignored trace-only tests are the phase-1 ceiling.

## Tranche targets (from the 2026-07-10 corpus survey)

1. **Tranche 1 (~90):** pure language — operators, coercion, primitives,
   strings, arrays, OOP/interfaces, functions/closures, try/catch.
   Near-miss probes `add`, `closures`, `es4_inheritance` all fail on a
   missing opcode (NewFunction etc.), not infrastructure — the Stage-3
   starting line.
2. **Tranche 2 (~50):** Vector, JSON, RegExp, object/proto edge cases.
3. **Tranche 3 (~60):** Namespace/QName/Proxy/Dictionary, ByteArray, AMF.
4. **Deferred:** XML/E4X (~51, needs XML engine — deferred but NOT ignored),
   frame-lifecycle tests (32 use addFrameScript → plan Stage 5), graphics.
