# Getting started

This page takes a fresh machine to one passing AVM1 test and one passing AVM2 test from Ruffle's test suite. See the end of this page for when it was last
checked end to end on a fresh clone.

Everything here is for **Linux x86_64**; the commands are for **Ubuntu 24.04**, which is what CI runs. Other
distributions work if they have the same tools. On Windows, use WSL2.

## 1. Prerequisites

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git python3 ccache
```

- `gcc`/`g++` 13 or newer, CMake 3.28 or newer, Python 3.10 or newer. The test harness uses only the Python standard
  library.
- `ccache` is optional, but it makes the second and later test runs much faster: every test compiles the runtime
  sources, and ccache caches them.
- About 4 GB of free disk for the repository, the build and the downloaded tests.

## 2. Clone

```bash
git clone --depth 1 https://github.com/PeerInfinity/SWFRecomp-CC.git
cd SWFRecomp-CC
```

`--depth 1` skips the history, which is several hundred MB. Drop it if you want `git log`.

All commands below are run from the repository root.

## 3. Build the recompiler

```bash
cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release
cmake --build SWFRecomp/build -j"$(nproc)"
```

This produces `SWFRecomp/build/SWFRecomp`, which turns a `.swf` into C. It takes a minute or two. Rebuild it after
pulling changes to `SWFRecomp/`.

**The runtime is not built separately.** `SWFModernRuntime/` is compiled together with each test's generated C by the
test harness (step 5), so there is nothing to build for it now.

## 4. Download the tests

The upstream tests are not stored in this repository. This script fetches them from
[ruffle-rs/ruffle](https://github.com/ruffle-rs/ruffle) (`tests/tests/swfs/`) with a sparse, blob-less git checkout,
installs them under `ruffle-tests/tests/swfs/<suite>/`, and then applies this project's Flash-verified golden
corrections (`ruffle-tests/flash_fixes/`):

```bash
bash ruffle-tests/download_tests.sh avm1 avm2
```

With no arguments it fetches only `avm1`. The other suites are `from_avmplus`, `from_gnash`, `from_shumway`, `visual`,
`timeline`, `text`, `swf`, `import_assets`, `audio`, `fonts`, `mixed_avm` and `stage3d`. Re-running it refreshes the
tests from Ruffle's current `master`. This project's own suite, `ruffle-tests/tests/swfs/regression/`, is part of the
repository and needs no download.

## 5. Run one test

`verify_output.py` recompiles the test's `test.swf`, compiles the generated C with the runtime, runs the binary, and
compares its trace output line by line with the test's `output.txt`.

**An AVM1 test** (the default suite is `avm1`):

```bash
python3 ruffle-tests/verify_output.py --test=add --diff --verbose
```

**An AVM2 test** (name the suite directory with `--tests-dir`):

```bash
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff --verbose
```

Each should end with:

```
Total tests:     1
Pass:            1 (100.0%)
```

The first run takes longer (about half a minute) because the runtime sources are compiled for the first time.

- Any test directory works the same way: `--tests-dir=ruffle-tests/tests/swfs/<suite>` plus `--test=<directory name>`.
  Nested suites are directories too, for example `--tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all`.
- `--diff` prints expected vs actual lines when they differ. The generated C stays in the test directory
  (`RecompiledScripts/`, `RecompiledTags/`, and `RecompiledABC/` for AVM2), so you can read what the recompiler made.
- **Run single tests only.** The full corpus is more than 4,900 tests and takes hours on one machine; CI runs it
  sharded (step 7).

These runs use the default **no-graphics** build: the headless player loop (`SWFModernRuntime/src/libswf/swf_core.c`)
with no renderer. That is enough for trace output.

## 6. Optional: graphics mode

`--mode=graphics` builds the production player loop (`swf.c`) with the WebGPU renderer, rendering offscreen through
[Dawn](https://dawn.googlesource.com/dawn) on a software Vulkan driver, so no GPU is needed. This is the mode CI grades
in. Trace results are the same as no-graphics apart from a few audio rows.

1. Install software Vulkan and the optional codec libraries:

   ```bash
   sudo apt-get install -y pkg-config mesa-vulkan-drivers libvulkan1 libavcodec-dev libavutil-dev libswscale-dev libjxr-dev liblzma-dev
   ```

   The codec libraries are optional; without them, the few tests that decode AAC audio or JPEG-XR images fail.

2. Get a Dawn build. The harness looks for it in `dawn-install/` **next to** the repository (`../dawn-install`), or
   wherever the `DAWN_INSTALL` environment variable points. Either:
   - download the prebuilt one that CI uses (Ubuntu 24.04 x86_64, 29 MB, built from the commit pinned in
     `scripts/build_dawn.sh`):

     ```bash
     curl -fL -o /tmp/dawn.tgz https://github.com/PeerInfinity/dawn-prebuilt/releases/download/dawn-620a520f/dawn-prebuilt-620a520f-ubuntu24.04-x64.tar.gz
     echo "6a9f926ceb60b832598cd5f759a244897227cf5d4ebd26677152534879636a7e  /tmp/dawn.tgz" | sha256sum -c
     tar xzf /tmp/dawn.tgz -C ..      # creates ../dawn-install
     ```

   - or build it from source (about 30 minutes; needs `ninja-build`):

     ```bash
     bash scripts/build_dawn.sh ../dawn-install
     ```

3. Run a test in graphics mode:

   ```bash
   python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff
   ```

To compare rendered frames with the tests' expected PNGs as well, install Pillow (`python3 -m pip install Pillow`) and
add `--images`. Image comparisons are reported separately and never decide a test's pass or fail. More detail:
[`HEADLESS_SETUP.md`](ruffle-tests/tests/swfs/_investigation/HEADLESS_SETUP.md).

## 7. Where the results and CI are

- **Result tables:** [`ruffle-tests/results/`](ruffle-tests/results/README.md). `RUFFLE_RESULTS_GRAPHICS.md` is the
  per-suite summary from the most recent graphics-mode CI run. Per-test detail (status, timings, diffs) is in each
  suite's `ruffle-tests/tests/swfs/<suite>/_results/`.
- **Project state:** [`SWFRecompDocs/plans/PROJECT_STATE.md`](SWFRecompDocs/plans/PROJECT_STATE.md), with the dated
  headline numbers and what is still worth doing.
- **CI:** [`.github/workflows/ruffle-tests.yml`](.github/workflows/ruffle-tests.yml) ("Ruffle Tests"). It is dispatched
  by hand, downloads the corpus, shards it across runners, and publishes the results to the `ruffle-test-results`
  branch, which is merged into `master`. Inputs: `mode` (`graphics` / `no-graphics`), `categories` (`all` = avm1, avm2,
  from_gnash, from_shumway and regression; `full` adds from_avmplus and the nine small suites), `images`, and
  `single_test`.
- **Known and accepted differences:** `ruffle-tests/ignored_tests.txt`, and the documents in
  `ruffle-tests/tests/swfs/avm1/_investigation/` (`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
  `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`).

## Going further

- Building a SWF for the browser (WebAssembly) needs Emscripten: `scripts/setup_build_env.sh` installs it, and
  `SWFRecomp/scripts/` has the build scripts. Guide: [`SWFRecompDocs/guides/`](SWFRecompDocs/guides/).
- The architecture, test infrastructure and debugging workflow are described in
  [`SESSION_START_GUIDE.md`](ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md). It is written for
  development sessions, so it assumes the commands above.

## Last fresh-clone check

Not yet checked (first draft, 2026-11-28).
