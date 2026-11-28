# S4 check: GETTING_STARTED.md on a fresh clone (sections 1–6, including graphics)

- **Guide checked:** `GETTING_STARTED.md` at `master` = `beb2dae` ("docs: repo cleanup S4 draft — new README, GETTING_STARTED, Ruffle attribution"), fetched with `curl` from raw.githubusercontent.com. The clone in section 2 was at the same commit.
- **Date:** 2026-11-28
- **Machine:** cloud container, Ubuntu 24.04.5 LTS, x86_64, 4 cores, running as `root`. `sudo` exists (`/usr/bin/sudo`), so every `sudo` command ran exactly as written.
- **Fresh clone location:** `/tmp/fresh/SWFRecomp-CC`, so `../dawn-install` = `/tmp/fresh/dawn-install` (does not exist).
- **Dawn:** step 6.2's download was skipped as instructed. I used the documented alternative, `export DAWN_INSTALL=/root/CC/dawn-install`. That copy is the same prebuilt tarball, already sha256-verified by the environment setup script. `/root/CC/dawn-install/lib/libwebgpu_dawn.a` exists (39,184,054 bytes), and its MANIFEST says `DAWN_REF=620a520f…`, which matches `scripts/build_dawn.sh`.

## Result

| Test | Mode | Result |
|---|---|---|
| AVM1 `add` | no-graphics (section 5) | **PASS** |
| AVM2 `hello_world` | no-graphics (section 5) | **PASS** |
| AVM1 `add` | graphics (section 6.3) | **PASS** |
| AVM2 `hello_world` | graphics (extra, requested) | **PASS** |

Every step exited 0 and no workaround was needed. The total wall time for the guide's steps (1 through 6.3 plus the extra AVM2 graphics test) was **≈ 283 s (4 min 43 s)**. This excludes the skipped Dawn download.

**Important caveat:** the environment setup script had already installed every apt package in sections 1 and 6.1 ("already the newest version" for all of them). It also had other `-dev` packages that pull in `zlib1g-dev`. So this run **does not prove the apt lists are complete for a bare Ubuntu 24.04 image**, and in fact they are not (see problem P1). Docker was installed, but no daemon was running, so I could not repeat the run on a bare `ubuntu:24.04` image.

## Per-step record

Times come from a wrapper that measures wall time around each command. Output tails are verbatim.

### 1a. `sudo apt-get update`, exit 0, 4.5 s
```
Get:10 http://archive.ubuntu.com/ubuntu noble-updates/universe amd64 Packages [2184 kB]
Get:11 http://security.ubuntu.com/ubuntu noble-security/restricted amd64 Packages [2277 kB]
Get:12 http://archive.ubuntu.com/ubuntu noble-updates/restricted amd64 Packages [2403 kB]
Fetched 12.3 MB in 2s (6026 kB/s)
Reading package lists...
```

### 1b. `sudo apt-get install -y build-essential cmake git python3 ccache`, exit 0, 1.2 s
```
build-essential is already the newest version (12.10ubuntu1).
cmake is already the newest version (3.28.3-1build7).
git is already the newest version (1:2.43.0-1ubuntu7.4).
python3 is already the newest version (3.12.3-0ubuntu2.1).
ccache is already the newest version (4.9.1-1).
0 upgraded, 0 newly installed, 0 to remove and 46 not upgraded.
```
Versions: gcc 13.3.0, cmake 3.28.3, all meeting the stated minimums. `python3` on PATH is `/usr/local/bin/python3` 3.13.18, not the apt 3.12; both meet "3.10 or newer". Free disk: 60 GB.

### 2. `git clone --depth 1 https://github.com/PeerInfinity/SWFRecomp-CC.git` then `cd SWFRecomp-CC`, exit 0, 4.2 s
```
Cloning into 'SWFRecomp-CC'...
```
HEAD `beb2dae`. The checkout is 229 MB on disk.

### 3a. `cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release`, exit 0, 4.3 s
```
-- Check size of __int64 - failed
-- Check size of unsigned __int64
-- Check size of unsigned __int64 - failed
-- Check size of uintptr_t
-- Check size of uintptr_t - done
-- Configuring done (4.3s)
-- Generating done (0.0s)
-- Build files have been written to: /tmp/fresh/SWFRecomp-CC/SWFRecomp/build
```
(The `__int64 … failed` lines are normal zlib/lzma configure probes on Linux.)

### 3b. `cmake --build SWFRecomp/build -j"$(nproc)"`, exit 0, 28.3 s
```
[ 99%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_tool.cpp.o
/tmp/fresh/SWFRecomp-CC/SWFRecomp/src/swf.cpp: In member function 'void PlaceCmCompose::apply(const float*)':
/tmp/fresh/SWFRecomp-CC/SWFRecomp/src/swf.cpp:292:23: warning: writing 160 bytes into a region of size 40 [-Wstringop-overflow=]
  292 |                 memcpy(m, out, sizeof(m));
      |                       ^
/tmp/fresh/SWFRecomp-CC/SWFRecomp/src/swf.cpp:212:16: note: destination object 'PlaceCmCompose::m' of size 40
  212 |         double m[4][5];   // row-major, rows = R,G,B,A, cols = R,G,B,A,bias
      |                ^
[100%] Linking CXX executable SWFRecomp
[100%] Built target SWFRecomp
```
This produced `SWFRecomp/build/SWFRecomp` (2.2 MB). There was exactly one compiler warning (P5). The guide says "a minute or two"; it took 33 s on 4 cores.

### 4. `bash ruffle-tests/download_tests.sh avm1 avm2`, exit 0, 55.1 s
```
=== avm1: found 766 directories ===
Installed 792 tests.

=== avm2: found 1319 directories ===
Installed 1353 tests.

Done! Total: 2145 tests installed.
...
flash-fix APPLIED    avm2/swf_9_goto_in_construct_frame/output.txt
flash-fix APPLIED    avm1/global_instance_decls/test.toml
flash-fixes: APPLIED 28
```
`avm1/add/` (output.txt, test.as, test.swf, test.toml) and `avm2/hello_world/` (Test.as, output.txt, test.fla, test.swf, test.toml) are present. The script prints its summary block twice, before and after the flash-fix lines (P6).

### 5a. `python3 ruffle-tests/verify_output.py --test=add --diff --verbose`, exit 0, 38.5 s. **PASS**
```
[1/1] add... PASS [r=0.01s c=38.27s x=0.00s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### 5b. `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff --verbose`, exit 0, 59.2 s. **PASS**
```
[1/1] hello_world... PASS [r=0.01s c=59.00s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### 5c. (extra, to check the ccache claim) the same command as 5a, run again, exit 0, 0.4 s. **PASS**
```
[1/1] add... PASS [r=0.00s c=0.22s x=0.01s]
```
The claim that "later runs are much faster" holds: compile time dropped from 38 s to 0.2 s.

### 6.1 `sudo apt-get install -y pkg-config mesa-vulkan-drivers libvulkan1 libavcodec-dev libavutil-dev libswscale-dev libjxr-dev liblzma-dev`, exit 0, 1.3 s
```
pkg-config is already the newest version (1.8.1-2build1).
mesa-vulkan-drivers is already the newest version (25.2.8-0ubuntu0.24.04.5).
libvulkan1 is already the newest version (1.3.275.0-1build1).
libavcodec-dev is already the newest version (7:6.1.1-3ubuntu5).
libavutil-dev is already the newest version (7:6.1.1-3ubuntu5).
libswscale-dev is already the newest version (7:6.1.1-3ubuntu5).
libjxr-dev is already the newest version (1.2~git20170615.f752187-5.1ubuntu2).
liblzma-dev is already the newest version (5.6.1+really5.4.5-1ubuntu0.4).
0 upgraded, 0 newly installed, 0 to remove and 46 not upgraded.
```

### 6.2 Dawn (download skipped as instructed; I used the documented `DAWN_INSTALL` alternative)
```
$ ls -la /root/CC/dawn-install/lib/libwebgpu_dawn.a
-rw-r--r-- 1 ubuntu ubuntu 39184054 Mar  8  2026 /root/CC/dawn-install/lib/libwebgpu_dawn.a
$ export DAWN_INSTALL=/root/CC/dawn-install
```
The download command itself was not run. I did check that the release URL resolves with an HTTP HEAD request only: it returned HTTP 200 with `Content-Length: 28838470` (≈ 29 MB, matching the guide). The `sha256sum -c` and `tar` lines were not exercised.

I also confirmed what happens when neither `../dawn-install` nor `DAWN_INSTALL` is set: `verify_output.py --test=add --mode=graphics --diff` exits 1 with:
```
Error: Dawn library not found at /tmp/fresh/dawn-install/lib/libwebgpu_dawn.a
Build Dawn first and install to /tmp/fresh/dawn-install
```
(see P7).

### 6.3 `python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff` (with `DAWN_INSTALL` set), exit 0, 45.1 s. **PASS**
```
============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### 6.3b (extra, requested) `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --mode=graphics --diff`, exit 0, 40.6 s. **PASS**
```
============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### Links and claims in §7 / "Going further"
Every path the guide names exists in the fresh clone: `scripts/build_dawn.sh`, `HEADLESS_SETUP.md`, `ruffle-tests/results/README.md`, `RUFFLE_RESULTS_GRAPHICS.md`, `PROJECT_STATE.md`, `.github/workflows/ruffle-tests.yml`, `ignored_tests.txt`, the four avm1 `_investigation` docs, `scripts/setup_build_env.sh`, `SWFRecompDocs/guides/`, `SESSION_START_GUIDE.md`, `ruffle-tests/flash_fixes/`, `swf_core.c` and `regression/`. The workflow inputs `mode`, `categories`, `images` and `single_test` exist. The `all` and `full` descriptions match the workflow's own description text. `build_dawn.sh` pins `620a520f…` and uses `ninja`.

## Doc problems found

**P1 — Missing prerequisite: `zlib1g-dev` (high confidence; would break section 5 on a bare image).**
The runtime sources include `<zlib.h>` (for example `SWFModernRuntime/src/avm2/avm2_bytearray.c:28`, `avm2_bitmap.c`, `avm2_cpu_raster.c`). The test link line in `ruffle-tests/verify_output.py` (around line 3521) passes `-lz`, and `/usr/lib/x86_64-linux-gnu/libz.so` comes from `zlib1g-dev`. The recompiler build is unaffected because it bundles its own zlib (`SWFRecomp/lib/zlib`). However, I checked the recursive apt dependency closure (Depends + Recommends) of section 1's packages (`build-essential cmake git python3 ccache`; 1072 packages), and it does **not** contain `zlib1g-dev`. Section 6.1's closure does not contain it either. It was present here only because the environment had other `-dev` packages installed. On a bare Ubuntu 24.04, section 5 should therefore fail to compile with `fatal error: zlib.h: No such file or directory`. I did not observe this failure because I had no bare image. Fix: add `zlib1g-dev` to section 1's `apt-get install` line.

**P2 — The section 1 package list cannot be proven complete by this run.** All packages were preinstalled, so other implicit dependencies of a bare image could also be missing. A real bare-image check (for example `docker run ubuntu:24.04`) is still needed before the "Last fresh-clone check" footer can honestly be filled in.

**P3 — Section 5's "Each should end with" block is not what the run actually ends with.** The real output ends with three more lines after `Pass: 1 (100.0%)`:
```
Fail:            0

Failure breakdown:
```
An empty "Failure breakdown:" header on a passing run looks alarming to a newcomer. Suggested fix: show the whole tail, or say "should include".

**P4 — The first-run time claim is low.** The guide says "about half a minute". The measured first runs were 38 s for AVM1 `add` and 59 s for AVM2 `hello_world` (AVM2 compiles more, because `RecompiledABC` is uncached on first use). Graphics first runs were 45 s and 41 s. Suggested wording: "about a minute".

**P5 — An unmentioned compiler warning in step 3.** `SWFRecomp/src/swf.cpp:292` produces `-Wstringop-overflow` ("writing 160 bytes into a region of size 40") on GCC 13.3. It appears to be a GCC false positive: `m` is `double[4][5]` = 160 bytes. Still, a newcomer will see a "buffer overflow"-looking warning in the only build step. Either silence it in code or say in the guide that one warning is expected.

**P6 — Cosmetic: `download_tests.sh` prints its "Downloading … / Installed … / Done! Total" summary twice,** once before and once after the `flash-fix APPLIED` lines. A newcomer may think the download ran twice. This is not a doc error, but section 4 could mention the 28 `flash-fix APPLIED` lines so they are not mistaken for errors.

**P7 — The graphics-mode error message does not point at the guide's remedies.** Without Dawn, the harness says "Build Dawn first and install to …/dawn-install". It does not mention the `DAWN_INSTALL` variable or the prebuilt download, which is the path the guide recommends first. This is a harness wording issue, not a guide error, but it is the first thing a newcomer sees if 6.2 is skipped.

**P8 — Minor inconsistency in where Dawn is unpacked.** The guide extracts the tarball with `tar xzf /tmp/dawn.tgz -C ..`, which is correct for `verify_output.py`'s default of `PROJECT_ROOT.parent / "dawn-install"`. The tarball's own `MANIFEST.txt` says `tar xzf <this archive> -C ~/CC (creates ~/CC/dawn-install; or set DAWN_INSTALL)`. These agree only when the repository is cloned inside `~/CC`. The guide never says to clone there, and section 2 clones into the current directory. A reader who follows the MANIFEST will get the P7 error unless they set `DAWN_INSTALL`.

**P9 — Section 6.3 has no `--verbose`, so a pass shows no per-test line.** The graphics runs print only the summary block, with no `[1/1] add... PASS` line. This is fine, but it is inconsistent with section 5's commands. Consider adding `--verbose` to 6.3 for symmetry.

**P10 — Minor: §7 says per-test detail is in "each suite's `ruffle-tests/tests/swfs/<suite>/_results/`".** For `from_gnash` there is no top-level `_results/`; the results are in each nested sub-suite (`from_gnash/<sub>/_results/`). This is worth a parenthetical, since section 5 already mentions nested suites.

**P11 — Minor: "Pillow" install (`python3 -m pip install Pillow`) on Ubuntu 24.04** fails with `externally-managed-environment` (PEP 668) under the system Python, unless the user is in a venv or passes `--break-system-packages`. `sudo apt-get install python3-pil` works without either. I could not reproduce this here. Stock 24.04 ships the PEP 668 marker (`/usr/lib/python3.12/EXTERNALLY-MANAGED`, which is present in this container). However, this container's `python3` is a non-stock 3.13 that already has Pillow, so `pip install --dry-run Pillow` just reported "already satisfied". `--images` was out of scope.

### Not doc problems, but noted
- In the clone this session started in, only the session branch had been fetched, so `git checkout -B fanout/s4-check-graphics origin/master` first failed with "Needed a single revision". `git fetch origin master:refs/remotes/origin/master` fixed it. This concerns the task's own instructions, not the guide.
- `python3` resolving to a non-apt 3.13 in `/usr/local/bin` is an environment quirk and did not matter.
