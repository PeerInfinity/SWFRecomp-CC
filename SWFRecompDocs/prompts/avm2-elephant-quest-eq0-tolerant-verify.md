# Session prompt — Elephant Quest EQ-0/EQ-1: tolerant verify → first native boot

**Objective:** start the Elephant Quest bring-up. The diagnosis session
(2026-07-21) produced the full gap map — **read
`SWFRecompDocs/plans/avm2-elephant-quest.md` first; it is the source of truth**
(recon, the two-layer Ruffle diagnosis, the oracle ruling, the cheap→expensive
gap list, and the Seedling-procedure staging EQ-0..2.5). This session does the
first two stages:

- **EQ-0 (required, the gateway): tolerant per-body verify** so the ABC
  recompiles at all, + a regression test.
- **EQ-1 (if EQ-0 lands): first memory-monitored native build → frame-proven
  boot state** as far as it goes, cataloging (not chasing) new gaps.

Target: `~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf` (jmtb02/
ArmorGames, AS3, SWF v10, 1 DoABC, **1310 bodies**, custom engine, all embedded).
Decompile already at `~/CC/jpexs/output/elephantquest/scripts/`.

## Bake in — don't re-derive (from the diagnosis session)

- **The blocker (gap #1):** `--check-abc` = 1310 bodies, **1 verify_fail** —
  `body=1309 unknown opcode 0xf4`, a `betz` obfuscator decoy in a **dead** body.
  `0xf4` is undefined in AVM2 (real debug ops stop at `0xf3`). It throws at
  `SWFRecomp/src/abc/abc_parser.cpp:830`, propagating to `parseAbc` returning
  **false for the WHOLE ABC** (`:584`) → all 1310 bodies fail to recompile.
  Ruffle survives this via **lazy per-method verify**; we verify AOT.
- **Fix-shape (localized, mirrors Ruffle):** the structural parse already
  succeeds — `readMethodBody` (`abc_parser.cpp:472-507`) stores each body's code
  as an **isolated, length-delimited** byte vector (`code_len` at `:481`), so the
  stream never desyncs. Make opcode-decode failure **per-body**: quarantine the
  offending body (emit a stub that throws `VerifyError`/an AS3 error at runtime if
  ever invoked) instead of aborting the file. Confirm where the decode/verify
  walk actually runs (the throw site is `parseOpcode`; find whether it's the
  verifier `abc_verifier.cpp` and/or the emitter `abc_emit.cpp`) and catch there,
  keeping the other 1309 bodies. **Do NOT** make undefined-opcode tolerance
  global-loose — quarantine one body cleanly; everything else stays strict.
- **Ruffle's failure is a PERF watchdog, not a feature gap** — with AGI.swf
  served, Ruffle runs the whole front half then its 15 s script watchdog kills the
  ~18 s world-map build. `getDefinitionByName("Level"+n)`, filters, and the
  betz/adobe-JSON save-deser all WORK in Ruffle. So EQ is a beat-Ruffle target,
  and the hypothesized init2() API gaps are NOT expected on our side either.
- **Traps:** boot-death scores PASS vs empty output.txt — **always dump frames,
  never trust a green harness** ([[avm2-localconnection-silent-blank-stage]]).
  `arg_present()` is TRUE for null ([[avm2-optional-arg-null-vs-undefined-trap]]).

## §1 — EQ-0: tolerant verify + regression test

1. Implement the quarantine per the fix-shape above (own the recompiler:
   `SWFRecomp/src/abc/`; never touch `action.c`). A quarantined body must (a) not
   abort the file, (b) still emit for every OTHER body, (c) at runtime throw if
   the dead body is ever called (it won't be, in EQ).
2. **Regression test** in `ruffle-tests/tests/swfs/regression/`
   ([[custom-tests-live-in-regression-suite]]): mxmlc can't emit invalid
   bytecode, so hand-craft it — e.g. `~/CC/flex-sdk/bin/mxmlc` a tiny AS3 with two
   traced methods, then **hex-patch one method body's code to insert a `0xf4`**
   (fix its `code_length`); assert the good method traces correctly and the
   recompile no longer aborts. (Check the upstream avm2 `verify_*` /
   `cpool_index_invalid_bytecode_*` tests + `SWFRecomp/tools/abc_corpus_sweep.py`
   for an existing invalid-bytecode SWF to adapt.) Grade locally with
   `verify_output.py --test=... --tests-dir=ruffle-tests/tests/swfs/regression`.
3. Re-run `--check-abc` on Elephant Quest: it should now report the fail but
   **recompile the file** (or add a `--check-abc` mode that quarantines-and-
   continues). Confirm all 1309 good bodies emit.

## §2 — EQ-1: first native build (MEMORY-MONITORED, run ALONE)

**The 262 KB DoABC → 1310 bodies is a huge single-TU compile; at `-O2` it
OOM-crashed a 16 GB WSL box last session. Do the build ALONE (no concurrent
subagents/compiles) and monitor memory (`free -h` / `/usr/bin/time -v`).**

- **Build levers (verify_output.py, verified):**
  - `SWFRECOMP_OPT_LEVEL=-O0` — **the OOM/timeout mitigation** (the ~MB
    `abc0_methods.c` at `-O2` blows the budget; `-O0` compiles in a fraction of
    RAM/time). Use it for the first build.
  - `SWFRECOMP_COMPILE_TIMEOUT=<sec>` (default 300) and
    `SWFRECOMP_RECOMPILE_TIMEOUT` for the large SWF.
  - `GAME_SWF_URL="http://armorgames.com/566862_ElephantQuest.swf"` →
    `-DSWF_URL=...` so `loaderInfo.url`/domain match the Ruffle oracle (the
    sitelock is inert but the domain feeds the right-click menu / Security stubs).
- **Scratch test layout:** a dir under a scratch `--tests-dir` with
  `elephant/test.swf` (copy the SWF), `elephant/test.toml` (`num_ticks = 300`),
  empty `elephant/output.txt`. Run:
  ```bash
  SWFRECOMP_OPT_LEVEL=-O0 GAME_SWF_URL="http://armorgames.com/566862_ElephantQuest.swf" \
    python3 ruffle-tests/verify_output.py --test=elephant --tests-dir=<scratch> --verbose
  ```
- **Frame-prove the boot state** (never trust a green result): run the native
  binary with `AVM2_CPU_DUMP=<prefix>` (+ `AVM2_MAX_TICKS=N` to drive deep
  without a rebuild), convert a few `.ppm`→`.png`, and LOOK. Report the furthest
  non-blank frame (tick + description). Read stdout/stderr for
  `AVM2 uncaught error:` / `Error #1065` / named `unimplemented op`.
- **Expected first wall = gap #3 (New Game):** the unguarded
  `AGIStuff.hideAGILogin()` → `this.agi.hideLoginStatus()` throws #1010 unless
  `agi` is a defined no-op object. Booting to the **title menu** (before New Game)
  is a clean EQ-1 success; New Game itself is EQ-2 (needs the `agi` stub — catalog
  it, don't necessarily fix it this session).
- **Watch native heap** on any world-map build (gap #6): 512 MB arena default; a
  native OOM is a finding to record, not fix.

## §3 — Deliverables

1. EQ-0 shipped: tolerant verify + regression test, both CI modes green, zero
   pass→fail regressions. Pipeline per `.claude/pipeline-handoff.md` (no-graphics;
   +graphics only if render paths were touched — they won't be). Autonomous
   commit/push/CI is authorized.
2. Update `SWFRecompDocs/plans/avm2-elephant-quest.md`: mark EQ-0 done, record the
   EQ-1 frame-proven boot state (which stage reached + evidence), and re-rank any
   newly discovered gaps. Update the `avm2/_investigation/CURRENT_STATUS.md` if
   appropriate.
3. Memory: update [[avm2-elephant-quest-bringup]] with the outcome + any new trap.
4. A sized recommendation for EQ-2 (New Game → world map: the `agi` no-op stub +
   whatever init2() hits), honestly scoped.

## Method rules (binding)

- Single tests locally only; suites via CI. **Frame dumps over trace silence.**
- Run the heavy build ALONE, memory-monitored — the concurrency that OOM-crashed
  WSL is the one thing not to repeat.
- Game is the integration check, **never the oracle** — every runtime/recompiler
  fix graded by an upstream avm2 trace family or a new `regression/` test.
- Don't fix what you can stub; don't stub what the game's own code path can't
  survive — the decompile decides. Perf/footprint OUT OF SCOPE.
- AVM2 work stays in `SWFModernRuntime/src/avm2/` + `SWFRecomp/src/abc/`; never
  touch `action.c`. Commit to master, stage by name, standard trailer.

## Oracle + tooling (already prepared)

- Ruffle oracle is valid **up to the first world-map frame** with an AGI stub;
  the patched exporter (`RUFFLE_LOCAL_FETCH_DIR` navigator + `RUFFLE_MOVIE_URL` +
  `RUFFLE_INPUT_FILE` + `RUST_LOG`) is documented at
  `SWFRecompDocs/reference/ruffle-local-patches.md` (with a re-appliable
  `.patch`). Not needed for EQ-0/EQ-1 (pre-New-Game boot), but ready for EQ-2
  render parity.
- Census reminder ([[avm2-rw-sequels-bringup]]): once EQ recompiles, run
  `abc_op_census.py` over EQ **+ a shipped game as baseline in the same
  tests-dir** — the baseline diff is the signal, not the default "blocked" report.
  Expect near-zero new ops (1309/1310 bodies already verify clean).

## Budget note (delegation)

Fable-led. Opus subagents for legwork: the recompiler quarantine implementation +
regression-test authoring, and the memory-monitored native build + frame-dump
runs (ONE at a time — never concurrent heavy compiles). Fable: the fix-shape
review, the boot-state ruling from frame evidence, and the EQ-2 sizing.
