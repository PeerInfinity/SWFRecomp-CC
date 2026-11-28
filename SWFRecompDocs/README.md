# SWFRecompDocs

The documentation of [SWFRecomp-CC](../README.md), a static recompiler that turns Flash SWF files (AVM1 and AVM2)
into C for native and WebAssembly builds. This page is the index.

This directory began in 2025 as the [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs)
repository. The session-by-session record (dated status logs, session briefs, fan-out reports, finished plans and
superseded 2025 docs) moved to the public
[SWFRecomp-CC-history](https://github.com/PeerInfinity/SWFRecomp-CC-history) repository in November 2026, at the same
relative paths. Citations written `SWFRecomp-CC-history:<path>` point there, and the stub READMEs in `status/`,
`prompts/`, `games/` and `deprecated/` say what moved.

## Start here

| Doc | What |
|---|---|
| [`../README.md`](../README.md) | What the project is, headline results, code map, relationship to Ruffle |
| [`../GETTING_STARTED.md`](../GETTING_STARTED.md) | Build the recompiler and runtime and run one test |
| [`ARCHITECTURE.md`](ARCHITECTURE.md) | The pipeline, recompiler and runtime layout, test harness and oracle, and the differences from Ruffle's design |
| [`plans/PROJECT_STATE.md`](plans/PROJECT_STATE.md) | **The current state**: corpus results, what is still worth doing, and every non-corpus track |
| [`plans/NO_GO_REGISTER.md`](plans/NO_GO_REGISTER.md) | Work ruled not worth doing, each with its reopen criterion |
| [`BACKLOG.md`](BACKLOG.md) | Known issues and deferred work, one line each |

## Plans, playbooks and arcs (`plans/`)

[`plans/README.md`](plans/README.md) indexes every plan. The live ones:

| Doc | What |
|---|---|
| [`plans/polish-sweep-arc.md`](plans/polish-sweep-arc.md) | The trace-corpus fan-out arc: per-session results and the ranked worklist |
| [`plans/graphics-fanout-playbook.md`](plans/graphics-fanout-playbook.md) | The pixel-parity fan-out playbook |
| [`plans/graphics-image-baseline.md`](plans/graphics-image-baseline.md) | The `images=true` render baseline and how to run it |
| [`plans/flash-oracle-report.md`](plans/flash-oracle-report.md) | How the Flash Player 32 oracle was built, and what it can and cannot capture |
| [`plans/feature-priority-map.md`](plans/feature-priority-map.md) | Feature areas ranked by test yield (numbers from 2026-07; `PROJECT_STATE.md` has the current ones) |
| [`plans/avm2-support-plan.md`](plans/avm2-support-plan.md) | The AVM2 umbrella plan and its architecture sketch |
| [`plans/repo-cleanup-plan.md`](plans/repo-cleanup-plan.md) | The November 2026 repository cleanup |
| [`../tools/coord/README.md`](../tools/coord/README.md) | Fan-out coordinator tooling and brief template |

## Guides (`guides/`)

| Guide | What |
|---|---|
| [`guides/wasm-game-debugging-session-guide.md`](guides/wasm-game-debugging-session-guide.md) | Debugging full games in the browser build: divergence harness first |
| [`guides/divergence-harness-usage.md`](guides/divergence-harness-usage.md) | Finding the first point where our run differs from Ruffle or Flash |
| [`guides/browser-test-harness-usage.md`](guides/browser-test-harness-usage.md) | The browser-WASM test harness |
| [`guides/ci-crash-capture.md`](guides/ci-crash-capture.md) | Cores, binaries and backtraces for intermittent CI crashes |
| [`guides/adding-graphics-tests.md`](guides/adding-graphics-tests.md) | Adding a test to the original `SWFRecomp/tests/graphics/` suite (swfmill-generated SWFs) |
| [`guides/building-docs2-demos.md`](guides/building-docs2-demos.md) | Building the local-only `docs2/` demos |
| [`guides/avm2-sharedobject-host-hook.md`](guides/avm2-sharedobject-host-hook.md) | Persisting AVM2 SharedObjects in the browser |
| [`guides/flash-browser-setup.md`](guides/flash-browser-setup.md) | Running Flash Player in a browser (the oracle is now [`../tools/flash-oracle/`](../tools/flash-oracle/README.md)) |

2025 design guides, kept for the record (the code has moved on since):
[`as3-implementation.md`](guides/as3-implementation.md),
[`as3-seedling-implementation.md`](guides/as3-seedling-implementation.md),
[`abc-parser-implementation.md`](guides/abc-parser-implementation.md),
[`as3-test-swf-generation.md`](guides/as3-test-swf-generation.md),
[`font-implementation.md`](guides/font-implementation.md),
[`font-phase1-implementation.md`](guides/font-phase1-implementation.md).

## Reference (`reference/`)

| Doc | What |
|---|---|
| [`reference/performance-optimizations.md`](reference/performance-optimizations.md) | Every shipped performance optimisation, with measured impact and rejected candidates |
| [`reference/performance-optimizations-vs-ruffle.md`](reference/performance-optimizations-vs-ruffle.md) | The same, compared with what Ruffle already does |
| [`reference/browser-wasm-gate-inventory.md`](reference/browser-wasm-gate-inventory.md) | Code arms that differ between the browser build and the CI builds |
| [`reference/ruffle-local-patches.md`](reference/ruffle-local-patches.md) | Local patches to a Ruffle checkout for oracle and perf tooling |
| [`reference/wasm-build-process.md`](reference/wasm-build-process.md) | How a WASM build is put together |
| [`reference/native-windowed-graphics-assessment.md`](reference/native-windowed-graphics-assessment.md) | Native windowed graphics: what exists and what it would take |
| [`reference/n-level-and-demo-format.md`](reference/n-level-and-demo-format.md) | N's level data and demo (input replay) format |
| [`reference/abc-format.md`](reference/abc-format.md) | Notes on the ABC file format |
| [`reference/trace-swf4-wasm-generation.md`](reference/trace-swf4-wasm-generation.md) | A 2026-02 walkthrough of one SWF → C → WASM build |

## Specifications (`specs/`)

Adobe's published specifications; sources in [`specs/README.md`](specs/README.md):
[SWF 19](specs/swf-spec-19.txt), [ABC 46.16](specs/abc-format-46-16.txt), [AVM2 overview](specs/avm2overview.txt),
[AVM2 opcodes](specs/avm2_opcodes_raw.txt), [`opcodes.as`](specs/opcodes.as), and the [PDFs](specs/pdf/).

## Upstream SWFRecomp (`merge/`, `upstream-comparison/`)

| Doc | What |
|---|---|
| [`merge/README.md`](merge/README.md) | The repository map: this project, LittleCube's upstream, the older forks |
| [`merge/upstream-relationship-2026-07.md`](merge/upstream-relationship-2026-07.md) | The July 2026 decision: a permanent friendly fork that exchanges knowledge, not code |
| [`upstream-comparison/README.md`](upstream-comparison/README.md) | What each architecture does better, and the trap map kept for upstream |

## Elsewhere in the repository

- Test harness: [`../ruffle-tests/README.md`](../ruffle-tests/README.md), with per-suite status under
  `ruffle-tests/tests/swfs/<suite>/_investigation/` and the cross-suite tables in
  [`../ruffle-tests/results/`](../ruffle-tests/results/README.md).
- Flash Player 32 oracle: [`../tools/flash-oracle/README.md`](../tools/flash-oracle/README.md).
- Ruffle-derived code and its attribution: [`../SWFModernRuntime/third_party/ruffle/README.md`](../SWFModernRuntime/third_party/ruffle/README.md).
- Maintenance scripts for these docs: [`scripts/README.md`](scripts/README.md).

## Licence

MIT, as the rest of the repository ([`../LICENSE`](../LICENSE)). The Adobe specifications in `specs/` keep their own
terms; see [`specs/README.md`](specs/README.md).
