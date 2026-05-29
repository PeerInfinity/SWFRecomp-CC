# Building the `docs2/` demos

How to build, deploy, and view the WASM demos under `docs2/`. Every demo is a
browser-WASM build of a recompiled SWF; `docs2/demo.html?test=<id>` plays one,
and `docs2/index.html` lists them from the catalog files.

All paths are relative to the repo root `/home/robert/CC/SWFRecomp-CC` unless
noted. All script paths are under `SWFRecomp/scripts/`.

## Prerequisites

1. **Emscripten on PATH** — `source emsdk/emsdk_env.sh` (the emsdk lives at
   `emsdk/` in the repo). Verify with `emcc --version`.
2. **The native `SWFRecomp` recompiler binary** at `SWFRecomp/build/SWFRecomp`:
   ```bash
   cd SWFRecomp/build && cmake .. && make -j$(nproc)
   ```
   The recompiler turns each `test.swf` into the generated C the WASM build
   compiles. Rebuild it whenever `SWFRecomp/src/` (the recompiler) changes.
3. **Browser-WASM graphics needs no local Dawn.** Graphics demos build with
   emscripten's `--use-port=emdawnwebgpu` (Dawn is fetched by the port on first
   build, then cached). The `~/CC/dawn-install` requirement in CLAUDE.md is only
   for the *native* OFFSCREEN_RENDER test mode, not for the docs2 demos.

> Note: changing **runtime** code (`SWFModernRuntime/src/`) does NOT require
> rebuilding the recompiler — but it DOES require rebuilding every demo whose
> behavior you want to reflect the change (the runtime is compiled into each
> demo's `.wasm`).

## The two-step model: build → deploy

Every demo is produced by two scripts:

- **`build_test.sh <test_name> [native|wasm] [--clean] [--graphics] [--headless]`**
  — recompiles `SWFRecomp/tests/<test_name>/test.swf` and compiles the WASM into
  `SWFRecomp/tests/<test_name>/build/wasm/`. For demos always use `wasm`.
- **`deploy_example.sh <test_name> [docs_dir] [--no-index] [--graphics]`**
  — copies the built `.wasm`/`.js` + `test.swf` into `<docs_dir>/<test_name>/`,
  writes `.demo_type`, and (unless `--no-index`) regenerates the index/catalog.
  **`docs_dir` defaults to `docs/examples` (the OLD tree) — for docs2 you must
  pass `"$(pwd)/docs2/examples"` explicitly.**

`--graphics` must be passed to **both** scripts for a graphics (rendered) demo;
omit it for a trace (text-output) demo. The two demo types use different runtime
sources and HTML templates.

### Single trace demo

```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh <test_name> wasm
SWFRecomp/scripts/deploy_example.sh <test_name> "$(pwd)/docs2/examples" --no-index
```

### Single graphics demo (e.g. Pong)

```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh glaiel/Pong wasm --graphics
SWFRecomp/scripts/deploy_example.sh glaiel/Pong "$(pwd)/docs2/examples" --no-index --graphics
```

Use `--no-index` when deploying a single demo so you don't rewrite the shared
index/catalog for everything else. (Drop it only if you want the index
regenerated for the standard `catalog.json` examples — see "Catalogs" below.)

`--clean` on `build_test.sh` forces a from-scratch recompile + rebuild (use it
if the recompiler changed or a stale cache is suspected).

## Deployed layout (per demo)

`docs2/examples/<test_name>/` contains:

| File | Purpose |
|---|---|
| `<name>.wasm`, `<name>.js` | the emscripten build (`<name>` = basename of test_name) |
| `index.html` | per-demo loader page |
| `test.swf` | the original SWF (enables the in-page Ruffle comparison) |
| `test_info.json` | metadata (swf version, etc.) |
| `.demo_type` | `trace` or `graphics` — read by the index generator |

The demo `.wasm`/`.js`/`test.swf` are **gitignored build artifacts**; the
catalog JSONs and `demo.html`/`index.html` are tracked.

## Batch builds

- **`build_all_examples.sh [docs_dir]`** — rebuilds and deploys every test in
  `SWFRecomp/tests/` (minus `excluded_tests.conf`), then regenerates the index +
  `catalog.json`. Pass `"$(pwd)/docs2/examples"` for docs2. Full regeneration;
  slow. This is the standard hand-written/avm1 example set (the `catalog.json`
  entries).
- **`build_swf_batch.sh [swf_dir] [--docs-dir <rel>] [--namespace <ns>] [--catalog-name <file>] [--demo-type <type>]`**
  — turns a directory of arbitrary `.swf` files into demos under a namespace.
  This is how the `flasharchive/` and `glaiel/` categories were built (each SWF
  → `SWFRecomp/tests/<ns>/<name>/` → `docs2/examples/<ns>/<name>/`, with its own
  `<ns>_catalog.json`). Defaults: `swf_dir=local_swf_batch/`, `docs-dir=docs`,
  `namespace=local_batch`, `catalog-name=local_catalog.json`. For docs2 pass
  `--docs-dir docs2`. `clean_swf_batch.sh` removes a batch.
- **`build_wasm_probes.sh [--force] [<slug>]`** — builds + deploys the regression
  probes under `SWFRecomp/tests/wasm_probes/` to `docs2/examples/wasm_probes/`.
  Idempotent on SWF timestamps; use `--force` after a runtime change (the probe
  `.wasm` won't otherwise rebuild for `.c`-only changes). Used by
  `tools/wasm_probe_runner.py`.

## Catalogs and the index

`docs2/index.html` fetches four catalogs and renders demo cards:

| Catalog | Built by | Covers |
|---|---|---|
| `catalog.json` | `generate_examples_index.sh` (called by `build_all_examples.sh`/`deploy_example.sh` without `--no-index`) | the standard `examples/*` set |
| `flasharchive_catalog.json` | `generate_local_catalog.py` / `build_swf_batch.sh --namespace flasharchive --catalog-name flasharchive_catalog.json` | `examples/flasharchive/*` |
| `glaiel_catalog.json` | same, `--namespace glaiel --catalog-name glaiel_catalog.json` | `examples/glaiel/*` |
| `local_catalog.json` | `build_swf_batch.sh` default namespace | `examples/local_batch/*` |

`generate_examples_index.sh` intentionally **skips** `examples/local_batch/`
(and the other namespaced dirs) so it can reproduce `catalog.json` identically
regardless of local batches — namespaced catalogs are managed separately by
`generate_local_catalog.py`.

To regenerate just a namespace catalog after a manual single-demo deploy:
```bash
python3 SWFRecomp/scripts/generate_local_catalog.py \
    --docs-dir "$(pwd)/docs2" --namespace glaiel --catalog-name glaiel_catalog.json
```
(See the script's `--help`; defaults are namespace=`local_batch`,
catalog_name=`local_catalog.json`.)

## Viewing locally

Serve `docs2/` over HTTP (WASM won't load from `file://`):

```bash
cd docs2 && python3 -m http.server 8000
# then open  http://localhost:8000/demo.html?test=glaiel/Pong
#       or   http://localhost:8000/index.html   (catalog of all demos)
```

The probe harness `tools/browser-test/serve.py` serves `docs2/` the same way
(used by the Playwright probes in `tools/browser-test/baseline-probes/`).

**Graphics demos require a WebGPU-capable browser.** Headless/automated runs use
Chrome with `--enable-unsafe-webgpu --ignore-gpu-blocklist` (see any baseline
probe). Trace demos have no such requirement.

## Quick reference

```bash
# one graphics demo to docs2
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh <ns>/<name> wasm --graphics
SWFRecomp/scripts/deploy_example.sh <ns>/<name> "$(pwd)/docs2/examples" --no-index --graphics

# one trace demo to docs2
SWFRecomp/scripts/build_test.sh <name> wasm
SWFRecomp/scripts/deploy_example.sh <name> "$(pwd)/docs2/examples" --no-index

# rebuild the probe demos after a runtime change
SWFRecomp/scripts/build_wasm_probes.sh --force

# rebuild everything (standard examples) + index for docs2
SWFRecomp/scripts/build_all_examples.sh "$(pwd)/docs2/examples"

# view
cd docs2 && python3 -m http.server 8000   # http://localhost:8000/demo.html?test=<id>
```
