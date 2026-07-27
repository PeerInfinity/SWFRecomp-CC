# CI crash capture — cores, binaries, and backtraces for intermittent crashes

**What it is:** every `ruffle-tests.yml` shard (and the single-test job) now
arms the kernel to dump core when a test binary dies on a signal, and
`verify_output.py` preserves the core **together with the exact binary and
sources that produced it**. If anything crashed, the job prints a gdb
backtrace into its own log and uploads the evidence as an artifact.

**Why it exists:** `avm2/edittext_align` segfaults intermittently — 60/60
correct trace lines, then SIGSEGV — and *only* in full-shard graphics CI runs
(0/70 local repros, 0/17 single-test CI dispatches, ASan-clean twice, clean
under `MALLOC_PERTURB_` and under the CI renderer). The shard job is the only
instrument that has ever reproduced it, and it was throwing the evidence away.
Two attribution attempts by inference both produced wrong answers
(`SWFRecompDocs/plans/loader-arc.md` §7). A core dump replaces inference.

It is a **standing instrument**, not a one-off: it fires for any test, in any
suite, in any mode, that dies on any fatal signal (SIGSEGV, SIGABRT, ...).

## What you get

Artifact `crash-cores-shard-<N>` (or `crash-cores-single-test`), one directory
per crashed test, named `<suite>__<test>`:

| File | What it is |
|---|---|
| `core.test_run.<pid>.gz` | the core dump, gzipped by the kernel dump helper |
| `test_run` | the exact unstripped binary the core belongs to |
| `sources.tar.gz` | the generated + runtime `.c`/`.h` that built it |
| `meta.json` | test, suite, rc, pid, git sha, run id, `ldd`, stderr tail, the results entry |

The job log also carries `thread apply all bt` + `info registers` for each
capture, so a red run is often diagnosable without downloading anything.

## Reading a capture offline

```bash
gh run download <run_id> -n crash-cores-shard-7 -D /tmp/cap
cd /tmp/cap/avm2__edittext_align
gunzip -c core.test_run.*.gz > core
mkdir src && tar xzf sources.tar.gz -C src
gdb -ex 'set debuginfod enabled off' -ex 'dir src' -ex bt ./test_run core
```

CI builds with `SWF_DEBUG_INFO=1` (`-g1`: function + line tables, no locals),
so backtraces carry `file:line`. `-g1` does not change codegen — it cannot
perturb the crash it is there to explain. Measured cost: no change in compile
time, `test_run` 1.4 → 2.3 MB.

Graphics builds link Dawn from the runner's cache; if a frame lands inside
`libwebgpu_dawn.so` you will only get an address plus the module name from the
core's `NT_FILE` note. `meta.json`'s `ldd` output records what was linked —
pull the matching Dawn from the `dawn-prebuilt-linux-x64-*` cache key if you
need symbols in there.

## Moving parts

- `.github/actions/crash-capture-setup` — points `kernel.core_pattern` at
  `/usr/local/bin/swf-core-dump.sh`, which gzips the dump into
  `/tmp/swf-cores/core.<comm>.<pid>.gz`. The pipe is not decoration: the
  native heap reserves 4 GB of address space (`heap.c`
  `DEFAULT_FULL_HEAP_SIZE`), so a plain core is a 4 GB *apparent-size* sparse
  file — cheap on disk but ruinous for anything that reads it end to end.
  `/tmp/swf-cores` is 0777 and deliberately **not** sticky: the helper runs as
  root, and under a sticky bit the runner user could not move the root-owned
  core into its per-test subdirectory.
- `verify_output.py` — `enable_core_dumps()` raises `RLIMIT_CORE` (soft 0 →
  hard unlimited, no privileges needed) when `SWF_CORE_CAPTURE_DIR` is set;
  `capture_crash_artifacts()` runs at the crash site, inside the `with
  TemporaryDirectory()` that owns the build dir — a step later would find the
  binary already deleted.
- `.github/actions/crash-capture-collect` — one `ls` on the happy path. gdb is
  installed and the artifact uploaded **only** when a capture directory
  exists, so a green run pays nothing.

## Using it locally

```bash
# core_pattern must land somewhere you can read; the default `core` in cwd works.
SWF_CORE_CAPTURE_DIR=/tmp/swf-cores \
  python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics
```

`SWF_CORE_CAPTURE_MAX` (default 3) bounds how many captures accumulate in the
directory — counted across processes, since a CI shard runs ~10
`verify_output.py` invocations and they share the runner's disk. Unset
`SWF_CORE_CAPTURE_DIR` and the whole path is a no-op.
