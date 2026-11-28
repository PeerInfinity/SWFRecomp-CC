# S4 check: GETTING_STARTED.md on a bare `ubuntu:24.04` container

Date: 2026-11-28. Followed `GETTING_STARTED.md` sections 1–6 word for word inside a pristine `ubuntu:24.04`
Docker container. I fixed nothing in the repo.

## Result

**Every step passed on the first try. No workarounds and no extra packages were needed.** Section 1's apt list was
enough for sections 1–5 on an image that started with 92 packages. Section 6.1's list was enough for graphics mode.

| Check | Mode | Result | First run | Repeat run (ccache) |
|---|---|---|---|---|
| AVM1 `add` | no-graphics (§5) | **PASS** | 45.3 s | 0.6 s |
| AVM2 `hello_world` | no-graphics (§5) | **PASS** | 73.1 s | 1.1 s |
| AVM1 `add` | graphics (§6.3) | **PASS** | 51.3 s | 1.6 s |
| AVM2 `hello_world` | graphics (§6.3) | **PASS** | 51.7 s | — |

The step 6.2 prebuilt Dawn download (curl, then sha256sum, then tar) was **not** denied by any permission or safety
check. It downloaded, the checksum matched (`/tmp/dawn.tgz: OK`), and it extracted to `/work/dawn-install`. The
harness found it at `../dawn-install` with no `DAWN_INSTALL` set.

## Environment

- Host: cloud session container, Linux 6.18.44, Docker Engine 29.9.3 (the daemon was started for this check with
  `dockerd`, storage driver overlayfs, cgroup v1).
- Image: `ubuntu:24.04`, pulled fresh for this check (none was cached locally).
  `docker image inspect ubuntu:24.04 --format '{{.Id}} {{.Created}}'` →
  `sha256:562111b88caa79c71391c0c4d3c2114a7d5c35915c20561fd893cb1e07929e6b 2026-11-10T18:35:18.402877569Z`
  (Ubuntu 24.04.5 LTS). At the start it had 92 dpkg packages, no `sudo`, `gcc`, `git`, `curl` or `python3`. At the
  end it had 361.
- Container: 4 CPUs, 15 GiB RAM. I ran as root, so I dropped `sudo` from every apt command, as section 1's note says.
  That note appears only in section 1. Section 6.1 and the Pillow line also use `sudo`, and I dropped it there too.
- Repo: `git clone --depth 1` of `master` at **14ae96bb**, a descendant of d62ed2bd. `GETTING_STARTED.md` is
  byte-identical to d62ed2bd.
- **Network deviation (environment-specific, not a doc issue):** this sandbox allows outbound HTTPS only through an
  egress proxy at `127.0.0.1` with its own CA. So I started the container with `--network host`, the CA bundle mounted
  read-only at `/ccr-ca.crt`, and env vars `HTTPS_PROXY`/`https_proxy`/`NO_PROXY`, `SSL_CERT_FILE`, `CURL_CA_BUNDLE`,
  `GIT_SSL_CAINFO` and `REQUESTS_CA_BUNDLE` pointing at it. This installs no packages and changes nothing in the
  image's filesystem. apt used plain-HTTP `archive.ubuntu.com` directly. A normal machine needs none of this.
- Exact container command:
  `docker run -d --name bare --network host -v /root/.ccr/ca-bundle.crt:/ccr-ca.crt:ro -e HTTPS_PROXY=… -e https_proxy=… -e NO_PROXY=… -e no_proxy=… -e SSL_CERT_FILE=/ccr-ca.crt -e CURL_CA_BUNDLE=/ccr-ca.crt -e GIT_SSL_CAINFO=/ccr-ca.crt -e REQUESTS_CA_BUNDLE=/ccr-ca.crt ubuntu:24.04 sleep infinity`
- Each step ran as `docker exec -w <dir> bare bash -lc '<command>'`. Steps 1–2 ran in `/work` and the rest in
  `/work/SWFRecomp-CC` (the repo root, as the guide says). The wall time is measured around the `docker exec`.
- Toolchain installed by §1: gcc 13.3.0, cmake 3.28.3, Python 3.12.3, git 2.43.0, ccache 4.9.1. All meet the stated
  minimums.

## Timings vs. the guide's claims

| Guide claim | Measured | OK? |
|---|---|---|
| §3 build "under a minute on 4 cores" | 4.7 s configure + 36.8 s build | yes |
| §3 "one `-Wstringop-overflow` warning from `src/swf.cpp`" | exactly one, `swf.cpp:292` | yes |
| §4 "about a minute" | 63.0 s | yes |
| §4 `avm1: found 766 directories` / `Installed 792 tests` | identical (avm2: 1319 / 1353) | yes |
| §4 `flash-fix APPLIED` lines | 28 lines, `flash-fixes: APPLIED 28` | yes |
| §5 first AVM1 "about 40 s" | 45.3 s | yes |
| §5 first AVM2 "about a minute" | 73.1 s | roughly (a bit over) |
| §5 repeats "under a second" | 0.6 s (AVM1), 1.1 s (AVM2, whole command) | roughly (the harness's own `c=` was 0.57 s) |
| §6.2 tarball "29 MB" | 27.5 MiB (= 28.9 MB) | yes |
| §6.3 first graphics "about 45 seconds" | 51.3 s | yes |
| §1 disk "about 350 MB for this page" | repo + build + tests 340 MB; plus 88 MB dawn-install, 9 MB ccache | yes for §1–5 (excludes apt) |

## Doc problems found

No step failed. These are the wording and accuracy issues I saw, most important first:

1. **The "Last fresh-clone check" section is stale.** It still says "Not yet checked (first draft, 2026-11-28)".
   This run (and the two earlier cloud-image checks) can now be cited: bare `ubuntu:24.04`, 14ae96bb, all four PASS.
2. **The disk estimate leaves out system packages.** "About 350 MB for this page" is right for the repo, build and
   tests. But on a bare image the §1 apt install adds several hundred MB (the container's writable layer ended at
   about 1.5 GB after §1, §6.1 and Pillow; `/usr` was 978 MB). The guide could say "plus about 1 GB of apt packages
   on a bare system".
3. **The "Drop `sudo`" note appears only once.** Section 6.1 and the Pillow line still say `sudo apt-get …`. A short
   "(drop `sudo` as in section 1)" there, or a single note at the top, would help root/container users. This is
   minor; the meaning was clear.
4. **The expected output in §5 is not exactly what prints.** The real line is
   `[1/1] add... PASS [r=0.01s c=44.89s x=0.01s]` (with phase timings, from `--verbose`), then a `=====` rule rather
   than `...`, and a trailing empty `Failure breakdown:` line. A newcomer can still match it, but the guide could
   show the real line or say "followed by phase timings".
5. **The §5 repeat-run claim ("under a second") is borderline for AVM2.** The whole AVM2 command took 1.1 s, while
   the harness's own compile phase was 0.57 s. It could say "about a second".
6. **The §6 "Optional: images" paragraph cannot be checked with the guide's tests.** I installed `python3-pil` and
   ran `--images` on `add`. It reported `image-comparison instrument ON (Pillow 10.2.0)` and PASS, but `add` has no
   expected PNG, so nothing was compared. If the guide wants that paragraph checkable, it could name a test that has
   an `output.expected.png`.
7. **Harmless cmake configure noise.** `Check size of __int64 - failed` (from the bundled zlib) is printed during §3
   configure. Not worth mentioning unless newcomers ask. Listed for completeness.

Things I specifically checked and found **correct**:
- §1's package list is complete for §1–5 on a bare image.
- §6.1's list is complete for graphics mode. `curl` comes from §6.1 and `ca-certificates` from §1, so the HTTPS
  download works.
- `tar xzf /tmp/dawn.tgz -C ..` from the repo root creates `../dawn-install` as stated.
- The MANIFEST's `~/CC` hint behaves as the guide warns.
- No interactive prompts (tzdata etc.) appeared during apt installs.
- `python3-pil` installs via apt as stated.

## Full per-step record

The command, exit code, wall time, and last 15 lines of output for each step. Steps named `s5c`, `s5d`, `s6_3c` and
`s6_x_*` are extra checks of the guide's repeat-run and `--images` claims, not separate guide steps.

### `s1a_apt_update`

- Command: `apt-get update`
- Exit code: 0
- Wall time: 4.7 s

```
Get:7 http://security.ubuntu.com/ubuntu noble-security/restricted amd64 Packages [2277 kB]
Get:8 http://security.ubuntu.com/ubuntu noble-security/main amd64 Packages [1514 kB]
Get:9 http://security.ubuntu.com/ubuntu noble-security/multiverse amd64 Packages [55.6 kB]
Get:10 http://archive.ubuntu.com/ubuntu noble/main amd64 Packages [1808 kB]
Get:11 http://archive.ubuntu.com/ubuntu noble/multiverse amd64 Packages [331 kB]
Get:12 http://archive.ubuntu.com/ubuntu noble/restricted amd64 Packages [117 kB]
Get:13 http://archive.ubuntu.com/ubuntu noble-updates/multiverse amd64 Packages [61.7 kB]
Get:14 http://archive.ubuntu.com/ubuntu noble-updates/main amd64 Packages [1843 kB]
Get:15 http://archive.ubuntu.com/ubuntu noble-updates/restricted amd64 Packages [2403 kB]
Get:16 http://archive.ubuntu.com/ubuntu noble-updates/universe amd64 Packages [2184 kB]
Get:17 http://archive.ubuntu.com/ubuntu noble-backports/main amd64 Packages [49.0 kB]
Get:18 http://archive.ubuntu.com/ubuntu noble-backports/multiverse amd64 Packages [669 B]
Get:19 http://archive.ubuntu.com/ubuntu noble-backports/universe amd64 Packages [36.0 kB]
Fetched 34.2 MB in 3s (9792 kB/s)
Reading package lists...
```

### `s1b_apt_install`

- Command: `apt-get install -y build-essential cmake git ca-certificates python3 zlib1g-dev ccache`
- Exit code: 0
- Wall time: 24.5 s

```

Setting up build-essential (12.10ubuntu1) ...

Setting up libheif1:amd64 (1.17.6-1ubuntu4.10) ...

Setting up libgd3:amd64 (2.3.3-9ubuntu5) ...

Setting up libc-devtools (2.39-0ubuntu8.12) ...

Setting up libheif-plugin-aomdec:amd64 (1.17.6-1ubuntu4.10) ...

Setting up libheif-plugin-aomenc:amd64 (1.17.6-1ubuntu4.10) ...

Processing triggers for libc-bin (2.39-0ubuntu8.12) ...

```

### `s2a_clone`

- Command: `git clone --depth 1 https://github.com/PeerInfinity/SWFRecomp-CC.git`
- Exit code: 0
- Wall time: 5.0 s

```
Updating files:  87% (8156/9374)
Updating files:  88% (8250/9374)
Updating files:  89% (8343/9374)
Updating files:  90% (8437/9374)
Updating files:  91% (8531/9374)
Updating files:  92% (8625/9374)
Updating files:  93% (8718/9374)
Updating files:  94% (8812/9374)
Updating files:  95% (8906/9374)
Updating files:  96% (9000/9374)
Updating files:  97% (9093/9374)
Updating files:  98% (9187/9374)
Updating files:  99% (9281/9374)
Updating files: 100% (9374/9374)
Updating files: 100% (9374/9374), done.
```

### `s3a_cmake_config`

- Command: `cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release`
- Exit code: 0
- Wall time: 4.7 s

```
-- Check size of unsigned long
-- Check size of unsigned long - done
-- Check size of unsigned long long
-- Check size of unsigned long long - done
-- Check size of size_t
-- Check size of size_t - done
-- Check size of __int64
-- Check size of __int64 - failed
-- Check size of unsigned __int64
-- Check size of unsigned __int64 - failed
-- Check size of uintptr_t
-- Check size of uintptr_t - done
-- Configuring done (4.6s)
-- Generating done (0.0s)
-- Build files have been written to: /work/SWFRecomp-CC/SWFRecomp/build
```

### `s3b_cmake_build`

- Command: `cmake --build SWFRecomp/build -j"$(nproc)"`
- Exit code: 0
- Wall time: 36.8 s

```
[ 95%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_timeline.cpp.o
[ 96%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_devicefont.cpp.o
[ 97%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_parser.cpp.o
[ 97%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_verifier.cpp.o
[ 98%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_dump.cpp.o
[ 99%] Building CXX object CMakeFiles/SWFRecomp.dir/src/abc/abc_tool.cpp.o
/work/SWFRecomp-CC/SWFRecomp/src/swf.cpp: In member function 'void PlaceCmCompose::apply(const float*)':
/work/SWFRecomp-CC/SWFRecomp/src/swf.cpp:292:23: warning: writing 160 bytes into a region of size 40 [-Wstringop-overflow=]
  292 |                 memcpy(m, out, sizeof(m));
      |                       ^
/work/SWFRecomp-CC/SWFRecomp/src/swf.cpp:212:16: note: destination object 'PlaceCmCompose::m' of size 40
  212 |         double m[4][5];   // row-major, rows = R,G,B,A, cols = R,G,B,A,bias
      |                ^
[100%] Linking CXX executable SWFRecomp
[100%] Built target SWFRecomp
```

### `s4_download`

- Command: `bash ruffle-tests/download_tests.sh avm1 avm2`
- Exit code: 0
- Wall time: 63.0 s

```
flash-fix APPLIED    avm2/displayobject_mask/output.expected.png
flash-fix APPLIED    avm2/displayobject_scrollrect/output.expected.png
flash-fix APPLIED    avm2/graphics_bad_direct_commands/output.expected.png
flash-fix APPLIED    avm2/loader_loadbytes_events/output.expected.png
flash-fix APPLIED    avm2/mouse_pick_dobj_mask/output.expected.png
flash-fix APPLIED    avm2/mouse_pick_non_interactive_dobj_mask/output.expected.png
flash-fix APPLIED    avm2/dependent_strings/output.txt
flash-fix APPLIED    avm2/loader_applicationDomain/output.txt
flash-fix APPLIED    avm2/swz/output.txt
flash-fix APPLIED    avm2/try_catch_typed/output.txt
flash-fix APPLIED    avm2/slot_holes_fail/output.txt
flash-fix APPLIED    avm2/slot_id_exceeds_trait_count/output.txt
flash-fix APPLIED    avm2/swf_9_goto_in_construct_frame/output.txt
flash-fix APPLIED    avm1/global_instance_decls/test.toml
flash-fixes: APPLIED 28
```

### `s5a_avm1_add`

- Command: `python3 ruffle-tests/verify_output.py --test=add --diff --verbose`
- Exit code: 0
- Wall time: 45.3 s

```
[1/1] add... PASS [r=0.01s c=44.89s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s5b_avm2_hello`

- Command: `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff --verbose`
- Exit code: 0
- Wall time: 73.1 s

```
[1/1] hello_world... PASS [r=0.01s c=72.49s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s5c_avm1_add_repeat`

- Command: `python3 ruffle-tests/verify_output.py --test=add --diff --verbose`
- Exit code: 0
- Wall time: 0.6 s

```
[1/1] add... PASS [r=0.00s c=0.25s x=0.00s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s5d_avm2_repeat`

- Command: `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff --verbose`
- Exit code: 0
- Wall time: 1.1 s

```
[1/1] hello_world... PASS [r=0.00s c=0.57s x=0.01s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s6_1_apt`

- Command: `apt-get install -y curl pkg-config mesa-vulkan-drivers libvulkan1 libavcodec-dev libavutil-dev libswscale-dev libjxr-dev liblzma-dev`
- Exit code: 0
- Wall time: 14.9 s

```

Setting up libavutil-dev:amd64 (7:6.1.1-3ubuntu5) ...

Setting up libswresample-dev:amd64 (7:6.1.1-3ubuntu5) ...

Setting up libavcodec-dev:amd64 (7:6.1.1-3ubuntu5) ...

Setting up va-driver-all:amd64 (2.20.0-2ubuntu0.2) ...

Setting up libswscale-dev:amd64 (7:6.1.1-3ubuntu5) ...

Processing triggers for libc-bin (2.39-0ubuntu8.12) ...

Processing triggers for libgdk-pixbuf-2.0-0:amd64 (2.42.10+dfsg-3ubuntu3.3) ...

```

### `s6_2a_curl`

- Command: `curl -fL -o /tmp/dawn.tgz https://github.com/PeerInfinity/dawn-prebuilt/releases/download/dawn-620a520f/dawn-prebuilt-620a520f-ubuntu24.04-x64.tar.gz`
- Exit code: 0
- Wall time: 2.4 s

```
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed

  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0

 25 27.5M   25 7054k    0     0  5916k      0  0:00:04  0:00:01  0:00:03 5916k
 95 27.5M   95 26.1M    0     0  11.9M      0  0:00:02  0:00:02 --:--:-- 19.4M
100 27.5M  100 27.5M    0     0  12.1M      0  0:00:02  0:00:02 --:--:-- 19.2M
```

### `s6_2b_sha`

- Command: `echo "6a9f926ceb60b832598cd5f759a244897227cf5d4ebd26677152534879636a7e  /tmp/dawn.tgz" | sha256sum -c`
- Exit code: 0
- Wall time: 0.1 s

```
/tmp/dawn.tgz: OK
```

### `s6_2c_tar`

- Command: `tar xzf /tmp/dawn.tgz -C ..`
- Exit code: 0
- Wall time: 0.9 s

```
```

### `s6_3a_avm1_add_gfx`

- Command: `python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff --verbose`
- Exit code: 0
- Wall time: 51.3 s

```
[1/1] add... PASS [r=0.00s c=50.31s x=0.62s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s6_3b_avm2_hello_gfx`

- Command: `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --mode=graphics --diff --verbose`
- Exit code: 0
- Wall time: 51.7 s

```
[1/1] hello_world... PASS [r=0.00s c=50.68s x=0.57s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s6_3c_gfx_repeat`

- Command: `python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff --verbose`
- Exit code: 0
- Wall time: 1.6 s

```
[1/1] add... PASS [r=0.00s c=0.76s x=0.52s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

### `s6_x_pil`

- Command: `apt-get install -y python3-pil`
- Exit code: 0
- Wall time: 3.1 s

```

Unpacking python3-pil:amd64 (10.2.0-1ubuntu1.5) ...

Setting up python3-olefile (0.46-3) ...

Setting up libwebpdemux2:amd64 (1.3.2-0.4build3) ...

Setting up libraqm0:amd64 (0.10.1-1build1) ...

Setting up libimagequant0:amd64 (2.18.0-1build1) ...

Setting up python3-pil:amd64 (10.2.0-1ubuntu1.5) ...

Processing triggers for libc-bin (2.39-0ubuntu8.12) ...

```

### `s6_x_images`

- Command: `python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff --verbose --images`
- Exit code: 0
- Wall time: 2.0 s

```
[images] image-comparison instrument ON (Pillow 10.2.0), no --image-out-dir (no PNG export)
[1/1] add... PASS [r=0.00s c=0.90s x=0.72s]

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0

Failure breakdown:
```

