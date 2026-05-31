# Divergence Harness — Usage Guide

`tools/divergence/` runs an arbitrary SWF through both SWFRecomp and Ruffle
and reports the first point at which they disagree — either in `trace()`
output or in the rendered image.

Background and design decisions:
`SWFRecompDocs/status/2026-05-24-divergence-harness-findings.md`.

## One-time setup

### MTASC (AS2 compiler)
Must be at `~/CC/mtasc/bin/mtasc` with the standard library at
`~/CC/mtasc/ocaml/mtasc/std`. Override with `MTASC_BIN` /
`MTASC_STD` env vars if installed elsewhere.

### Build the tracer
```bash
tools/divergence/build_tracer.sh
```
Compiles `Tracer.as` → `tracer.swf` → `tracer_bytecode.bin`. Run this once
on first use, and any time you edit `Tracer.as`.

### Build the patched Ruffle exporter
The exporter at `~/CC/ruffle/exporter` has a local patch adding a
`--trace-log` flag (see findings doc for the patch contents).

```bash
cd ~/CC/ruffle && cargo +nightly build --release -p exporter
```
The nightly toolchain requirement is Ruffle's, not ours. Build takes about
8 minutes the first time, seconds on incremental rebuilds. Binary lands at
`~/CC/ruffle/target/release/exporter`.

## Running a divergence test

```bash
python3 tools/divergence/divergence_test.py <input.swf> [--frames N] [--out DIR]
                                            [--tolerance N] [--max-outliers N]
                                            [--skip-ruffle] [--skip-swfrecomp]
                                            [--recompile]
```

Example:
```bash
python3 tools/divergence/divergence_test.py ~/CC/glaiel/swfs/Pong.swf --frames 30
cat tools/divergence/runs/Pong/divergence.txt
```

### Flags

| Flag | Default | Notes |
|---|---|---|
| `--frames N` | 30 | Number of ticks to capture on each side. The injected tracer auto-quits after `MAX_FRAMES=100` (hardcoded in `Tracer.as`). |
| `--out DIR` | `tools/divergence/runs/<stem>/` | Output directory. |
| `--tolerance N` | 0 | Per-channel pixel tolerance (0-255). 0 = exact match. |
| `--max-outliers N` | 0 | Max channels allowed to exceed tolerance per frame. |
| `--trace-rel-tol R` | 1e-5 | Relative tolerance for numeric tokens in the trace diff. Absorbs f32-vs-f64 precision noise (e.g. an `_xscale` differing at the 8th sig-fig because SWFRecomp stores scale as `float` while Ruffle derives it in f64 from an f32 matrix). |
| `--trace-abs-tol A` | 1e-4 | Absolute tolerance for numeric tokens near zero, where relative tolerance breaks down. |
| `--trace-exact` | off | Byte-exact trace comparison (both trace tolerances → 0). Use to inspect the absorbed float-precision lines directly. |
| `--skip-ruffle` | off | Reuse existing Ruffle outputs (e.g. when only the SWFRecomp side has changed). |
| `--skip-swfrecomp` | off | Same for the other side. |
| `--recompile` | off | Force SWFRecomp to re-run the recompiler (otherwise it reuses cached `RecompiledScripts/`). |

### Output layout

```
tools/divergence/runs/<stem>/
  injected.swf                    target SWF with tracer spliced in (input to both runtimes)
  ruffle/
    trace.txt                     Ruffle's trace output
    NN.png                        per-frame PNGs (zero-padded to width of total)
  swfrecomp/
    test.swf                      copy of injected.swf
    test.toml                     generated; declares per-frame image_comparisons
    RecompiledScripts/            SWFRecomp recompiler output
    build/
      test_run                    compiled native binary
      F0001.png ... F<N>.png      per-frame PNGs
    trace.txt                     SWFRecomp's stdout (trace lines + runtime banner)
    stderr.txt                    SWFRecomp's stderr
  divergence.txt                  first-divergence report
```

### Frame numbering

Ruffle indexes captures from 0, SWFRecomp from 1, both representing "state
after frame N has run":

| Tracer tick | Ruffle file | SWFRecomp file |
|---|---|---|
| F1 | `00.png` (or `0.png` for ≤10 frames) | `F0001.png` |
| F2 | `01.png` | `F0002.png` |
| ... | ... | ... |

`divergence_test.py` handles the mapping automatically.

## Interpreting the report

```
=== Divergence report: Pong ===
Frames compared: 20
Trace lines: ruffle=76, swfrecomp=96
Trace: first divergence at filtered line 6
  ruffle:    F2 _currentframe=2
  swfrecomp: F2 _currentframe=1
  context (filtered lines 3-5):
       3: F1 _root.instance2 _x=260 _y=190.6 _cf=1 _vis=true
       4: F1 _root.instance2.instance3 _x=-13.65 _y=-58.1 _cf=2 _vis=true
       5: F1 _root.instance2.instance3.progbar _x=-49.9 _y=0 _cf=1 _vis=true
Image: first divergence at frame 1: max_diff=255 (50459 outliers exceed limit of 0, max difference 255)
```

- **Trace lines: A vs B**: total filtered (noise-removed) trace lines from
  each side. A big gap usually means one side exited the tick loop early —
  not always a bug (`fscommand("quit")` from the tracer), but worth checking
  the last few lines of each `trace.txt`.
- **Trace: first divergence**: line index into the filtered traces. Context
  shows the 3 preceding identical lines for orientation. Numbers are compared
  with tolerance (see `--trace-rel-tol`), so this is the first *meaningful*
  divergence, skipping float-precision noise.
- **Trace: N line(s) differed only within numeric tolerance**: appears when
  float-precision noise was absorbed (e.g. f32 scale storage). It is NOT a bug;
  re-run with `--trace-exact` if you want to see those lines. Without this, the
  harness used to get permanently stuck on the first computed scale/position in
  component-heavy games.
- **Image: first divergence**: lowest 1-based frame number whose PNG pair
  fails the tolerance check. `max_diff` is the largest single-channel
  absolute difference (0-255); `outliers` is the number of channels (R, G,
  B, A counted independently) exceeding the per-channel tolerance.

When both diverge at the same frame, the trace divergence is usually the
more informative starting point. When only the image diverges, look at
`runs/<stem>/<side>/...png` side by side and at the difference PNG that gets
written alongside.

## Tuning

### Image tolerance
Real cross-runtime rendering will rarely match byte-for-byte due to
sub-pixel positioning and anti-aliasing differences. If the strict default
catches noise rather than real bugs, loosen it:
```bash
python3 tools/divergence/divergence_test.py game.swf --tolerance 8 --max-outliers 1000
```
`--tolerance 8` allows each channel to differ by up to 8/255 (~3%).
`--max-outliers N` allows up to N channels per frame to exceed that
tolerance (channels, not pixels — 4 channels per pixel).

### Trace noise filter
Add patterns to `NOISE_PATTERNS` in `divergence_test.py` when a known
platform-dependent string starts showing up at the top of the trace diff.
Both sides are filtered identically, so adding a pattern is safe.

Currently filtered:
- `$version=` — `Capabilities.version` platform tag
- `^SWF Runtime Loaded` — SWFRecomp startup banner
- `^\[HEAP\]` — SWFRecomp heap init banner

### What the tracer emits
Edit `tools/divergence/Tracer.as`, then re-run `build_tracer.sh`. The
current scope:
- `F<n> _currentframe=<frame>` once per tick
- `F<n> _root <prop>=<scalar>` for each enumerable scalar property on
  `_root` (sorted, skips underscore-prefixed builtins)
- `F<n> <mcpath> _x=<x> _y=<y> _cf=<f> _vis=<v>` for each MovieClip in the
  display list (sorted by path, depth-capped at 3, max 50 entries per
  frame)

To dump additional fields (`_xscale`, `_alpha`, `_rotation`), add them to
the line built in `dump_display_list`. Be aware that animated content will
trigger noisy diffs on these — the strict default omits them for that
reason. To dump deeper into objects (e.g. game-state objects on `_root`),
extend `dump_scalars` to recurse into non-scalar `for..in` values; cap
recursion depth to avoid cycles.

### Frame count
Lower `--frames` for faster iteration during debugging (15 is enough to
catch most early divergences and runs in a second or two on the SWFRecomp
side). Raise it past 30 if a bug is suspected later in startup. Above ~100
you'll need to bump `MAX_FRAMES` in `Tracer.as` and rebuild the tracer.

## Common gotchas

- **"Ruffle exporter not built"**: the patched exporter isn't compiled yet.
  Run `cd ~/CC/ruffle && cargo +nightly build --release -p exporter`.
- **"Tracer bytecode not found"**: `tracer_bytecode.bin` is missing. Run
  `tools/divergence/build_tracer.sh`.
- **SWFRecomp build fails on first run**: usually a runtime header change
  that invalidated cached `RecompiledScripts/`. Rerun with `--recompile`.
- **Different PNG counts**: SWFRecomp's PNG count below `--frames` usually
  means its tick loop terminated early (FSCommand:quit, `_root.stop()` plus
  no scripts requesting frames, etc.) — itself a divergence. The trace log
  on each side will show the last tick that ran.
- **SWF is AVM2 (SWF version ≥ 9)**: the tracer is AS2 and won't execute in
  AVM2. The injector still runs, but no trace lines appear. SWFRecomp's
  AVM2 support is limited anyway. To detect: `head -c 4 game.swf | xxd` —
  byte 3 is the version.
- **Modified Ruffle clone**: the `--trace-log` patch is local. If you pull
  upstream Ruffle changes, reapply the patch (or upstream it).

## Quick reference

```bash
# First time
tools/divergence/build_tracer.sh
cd ~/CC/ruffle && cargo +nightly build --release -p exporter

# Per game (fresh run)
python3 tools/divergence/divergence_test.py <game.swf> --frames 30
cat tools/divergence/runs/<stem>/divergence.txt

# Iterate on SWFRecomp side only
python3 tools/divergence/divergence_test.py <game.swf> --frames 30 --skip-ruffle

# Force a full SWFRecomp recompile
python3 tools/divergence/divergence_test.py <game.swf> --recompile

# Inspect frame N side-by-side
xdg-open tools/divergence/runs/<stem>/ruffle/<N-1>.png
xdg-open tools/divergence/runs/<stem>/swfrecomp/build/F<N as 4 digits>.png
```
