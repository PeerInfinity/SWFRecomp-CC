# GETTING_STARTED.md fresh-clone check — sections 1–5 (no-graphics)

- Date: 2026-11-28
- Guide checked: `GETTING_STARTED.md` at master `beb2daeeeb97339aa07cc647e400a423574adcd4` (curl copy was identical to the cloned file)
- Machine: Ubuntu 24.04.5 LTS, x86_64, 4 cores, running as root (`sudo` exists, so commands ran verbatim with `sudo`)
- Toolchain after section 1: gcc 13.3.0, cmake 3.28.3, Python 3.13.18 (`/usr/local/bin/python3`, preinstalled; apt's `python3` was already satisfied), ccache 4.9.1
- Clone location: `/tmp/fresh/SWFRecomp-CC`
- Section 6 (graphics) skipped as instructed.

## Result

| Test | Result |
|---|---|
| AVM1 `add` | **PASS** |
| AVM2 `hello_world` | **PASS** |

Total wall time for sections 1–5: **~3 min 27 s** (sum of the steps below). No step failed; no workaround was needed.

## Per-step record

### 1a. `sudo apt-get update`
- Exit 0, real 0m2.990s
```
Get:19 http://archive.ubuntu.com/ubuntu noble-backports/universe amd64 Packages [36.0 kB]
Get:20 http://archive.ubuntu.com/ubuntu noble-backports/multiverse amd64 Packages [669 B]
Get:21 http://archive.ubuntu.com/ubuntu noble-backports/main amd64 Packages [49.0 kB]
Fetched 34.3 MB in 2s (18.4 MB/s)
Reading package lists...
```

### 1b. `sudo apt-get install -y build-essential cmake git python3 ccache`
- Exit 0, real 0m2.740s (only ccache + libhiredis were new; the rest was already installed)
```
Selecting previously unselected package ccache.
Preparing to unpack .../ccache_4.9.1-1_amd64.deb ...
Unpacking ccache (4.9.1-1) ...
Setting up libhiredis1.1.0:amd64 (1.2.0-6ubuntu3) ...
Setting up ccache (4.9.1-1) ...
Updating symlinks in /usr/lib/ccache ...
Processing triggers for libc-bin (2.39-0ubuntu8.12) ...
```

### 2. `git clone --depth 1 https://github.com/PeerInfinity/SWFRecomp-CC.git && cd SWFRecomp-CC`
- Exit 0, real 0m3.683s. `.git` = 42 MB, working tree = 188 MB.
```
Cloning into 'SWFRecomp-CC'...
```

### 3a. `cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release`
- Exit 0, real 0m4.289s
```
-- Check size of unsigned __int64 - failed
-- Check size of uintptr_t
-- Check size of uintptr_t - done
-- Configuring done (4.3s)
-- Generating done (0.0s)
-- Build files have been written to: /tmp/fresh/SWFRecomp-CC/SWFRecomp/build
```

### 3b. `cmake --build SWFRecomp/build -j"$(nproc)"`
- Exit 0, real 0m32.600s (nproc = 4). Produced `SWFRecomp/build/SWFRecomp` (2.2 MB). One compiler warning.
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

### 4. `bash ruffle-tests/download_tests.sh avm1 avm2`
- Exit 0, real 0m58.519s. `avm1/` has 768 entries, `avm2/` 1322; `avm1/add` and `avm2/hello_world` present.
```
Downloading Ruffle tests (branch: master)...
Categories: avm1 avm2
Cloning with sparse checkout (tests/tests/swfs/avm1 tests/tests/swfs/avm2)...
=== avm1: found 766 directories ===
Installed 792 tests.
=== avm2: found 1319 directories ===
Installed 1353 tests.
Done! Total: 2145 tests installed.
flash-fix APPLIED    avm2/swf_9_goto_in_construct_frame/output.txt
flash-fix APPLIED    avm1/global_instance_decls/test.toml
flash-fixes: APPLIED 28
```

### 5a. `python3 ruffle-tests/verify_output.py --test=add --diff --verbose`
- Exit 0, real 0m39.108s (cold ccache), **PASS**
```
[1/1] add... PASS [r=0.01s c=38.84s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### 5b. `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff --verbose`
- Exit 0, real 1m02.221s, **PASS**. ccache after this run: 33 hits / 96 misses — the AVM2 build mostly did not reuse the AVM1 build's cached objects.
```
[1/1] hello_world... PASS [r=0.01s c=61.77s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### Extra check (not a guide step): re-ran 5a
- real 0m0.408s, PASS — the "later runs are much faster" claim holds.

Disk used after section 5: clone dir 340 MB (+ ~3.5 MB ccache).

## Doc problems found

None blocking — every command worked verbatim. Issues, most significant first:

1. **First-run time is understated.** §5 says "The first run takes longer (about half a minute)". Measured on 4 cores: AVM1 `add` 39 s, AVM2 `hello_world` 62 s *even after* the AVM1 run warmed ccache (only 33/129 hits). Suggest "about a minute on a 4-core machine; the first AVM2 test takes about as long again, because AVM2 compiles a different set of runtime objects".
2. **"Each should end with:" is not literally true.** The output actually ends with `Fail: 0` and then an empty `Failure breakdown:` header after the two lines shown. Either show the full tail or say "should include".
3. **Disk claim is far over for this path.** §1 says "About 4 GB of free disk for the repository, the build and the downloaded tests"; following §2–5 (avm1 + avm2) used ~340 MB. 4 GB is presumably for the full corpus — say so ("~350 MB for avm1+avm2; up to ~4 GB with every suite").
4. **Unexplained count mismatch in `download_tests.sh` output.** "avm1: found 766 directories / Installed 792 tests" (and 1319 / 1353 for avm2). A newcomer can't tell whether that's an error. One sentence in §4 (nested test directories are counted as tests?) would help.
5. **Compiler warning during §3b is not mentioned.** One `-Wstringop-overflow` warning in `SWFRecomp/src/swf.cpp:292`. Harmless to the result, but a newcomer may think the build is broken; either fix the warning or note "one warning is expected".
6. **Minor wording:** §5's last bullet says CI "runs it sharded (step 7)" — the doc's headings are "sections", and section 7 isn't a step to perform. "(see section 7)" is clearer.
7. **`--verbose` adds nothing visible on a passing test**, so the example output looks identical with or without it; fine, but the flag's purpose isn't explained.
8. **Root/sudo:** not a problem here (sudo was installed even though running as root), but container users without `sudo` will hit "command not found"; a parenthetical "(drop `sudo` if you are root)" would cover it.
9. `Last fresh-clone check` still says "Not yet checked" — this report can be the basis for filling it in (no-graphics: checked 2026-11-28 at `beb2daeee`, both tests pass).
