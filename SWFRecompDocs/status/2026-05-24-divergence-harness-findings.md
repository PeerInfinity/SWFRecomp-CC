# 2026-05-24 — Divergence Harness: Findings and Build Notes

Goal of the session: stand up a way to take an arbitrary SWF (specifically the
glaiel game corpus at `~/CC/glaiel/swfs/`), run it through both SWFRecomp and
Ruffle, and identify the first point at which their behavior diverges — either
in `trace()` output or in the rendered image. The .fla source files in
`~/CC/glaiel/` can't be recompiled (no working Flash IDE), so the harness has
to work from the .swf binaries only.

The end product is `tools/divergence/`. See
`SWFRecompDocs/guides/divergence-harness-usage.md` for how to run it.

## What the .fla files contain

`~/CC/glaiel/` has 50 .fla files in two formats. Both are inspectable from the
command line, but neither gives us a recompilation path — what they do give is
*source-level visibility* into the game's ActionScript.

### Old format — 48 of 50 (Flash MX/8 era)

Composite File Binary (CFB / OLE2). Inspectable with Python `olefile`:

```python
import olefile
ole = olefile.OleFileIO('pico.fla')
for path in ole.listdir():
    print(ole.get_size('/'.join(path)), path)
```

Streams inside are `Contents` (root metadata), `Page <N>` (scene timelines),
`Symbol <N>` (one per library item), `Media <N>` (embedded assets). The binary
shape/timeline data is Flash's proprietary format and not readable, but
**ActionScript is stored as plain UTF-16LE text** with original whitespace,
comments, and identifiers intact. From `picoufo/pico.fla`, `Symbol 37`:

```
speed = 3;
xs = _xscale;
timer = 0;
...
onEnterFrame = function () {
    if (!abducted) {
        vol = 10000/Math.abs(_x-_root.pico._x);
        ...
```

49 AS snippets recoverable from `pico.fla` alone. Extraction recipe:

```python
import re
data = ole.openstream('Symbol 37').read()
for s in re.findall(rb'(?:[\x09\x0a\x0d\x20-\x7e]\x00){50,}', data):
    print(s.decode('utf-16le'))
```

### New format — 2 of 50 (Flash CS4+)

`butcherbugs/butcherbug.fla` and `fracuum/tinyworld.fla`. ZIP/XFL archives
containing `DOMDocument.xml` (framerate, dimensions, scenes), one
`LIBRARY/<symbol>.xml` per symbol with named layers, frame scripts as
`<script><![CDATA[...]]>`, shape edges in Flash's text-edge format, and symbol
linkage names (`linkageClassName="Music"`).

**Gotcha:** both files have a 54-byte central-directory mismatch from old
Flash CS, so `unzip` and Python `zipfile` fail. Workaround is to walk local
file headers manually (`b'PK\x03\x04'` scan + zlib decompress).

## Existing infrastructure we built on

### Bytecode injection — already wired up

`docs/injector/ruffle_inject.html` already does runtime SWF injection in the
browser: decompress CWS→FWS, version-bump to 8, find first ShowFrame via tag
scan, splice pre-compiled bytecode in front of it, fix the header length. The
existing payload (`bridge_bytecode.js`) exposes the display list via
`ExternalInterface`. Source AS2 is at `demos/ruffle-inject/BridgeInject.as`,
compiled with MTASC. Bytecode extraction is
`demos/ruffle-inject/extract_bytecode.py`.

The divergence harness reuses the same pattern: a tiny AS2 file compiled by
MTASC, with the resulting `DoInitAction`/`DoAction` tag bytes extracted and
spliced into target SWFs by a Python port of the same insertion logic.

### Determinism — already in place on both sides

- **SWFRecomp**: `MOCK_DATE_TIME` macro defined at compile time by
  `verify_output.py` for every gcc invocation. Default
  `981152406000` ms = 2001-02-03 04:05:06 NPT. `Math.random` is seeded from
  `MOCK_DATE_TIME * 1000` µs in `math.c::GenerateRandomNumber`.
- **Ruffle**: `--deterministic` mode uses the same seed and clock. Two CI
  runs at the same SHA produce byte-identical traces across all suites.

So both runtimes produce reproducible output as long as no input events are
fired. Divergences should reflect implementation differences, not RNG drift.

### Per-frame image capture — already in place on both sides

- **SWFRecomp** (`SWFModernRuntime/src/libswf/capture.c`): reads
  `CAPTURE_TRIGGERS` env var like `F0001:iteration:1,F0002:iteration:2,...`.
  Drops one PNG per trigger to `CAPTURE_OUTPUT_DIR`. Only works in
  graphics-native mode (`--mode=graphics`, defines `OFFSCREEN_RENDER` +
  `HEADLESS_RENDER_ENABLED`).
- **Ruffle**: the `exporter` binary (`~/CC/ruffle/exporter`) takes `-f N` or
  `-f all` and writes per-frame PNGs to an output directory.

Notable: SWFRecomp's `CAPTURE_TRIGGERS` keys (`iteration:N`, `fs_command`,
`last_frame`) mirror Ruffle's `ImageTrigger` enum exactly — `capture.c` was
modeled on Ruffle's test framework. Both runtimes already speak the same
per-frame-capture language.

### Ruffle exporter — needed a small patch for trace

The vendored Ruffle exporter uses `NullLogBackend` (the default), which
silently drops `trace()` output. We added a `--trace-log PATH` flag (~25 lines
in `~/CC/ruffle/exporter/src/{cli.rs,exporter.rs,lib.rs}`) that wires a
`TraceLogBackend` (`Arc<Mutex<String>>` so it survives rayon's
`par_iter` in the multi-SWF path) into `PlayerBuilder.with_log()` and writes
the captured text to a file after all frames have rendered.

The patch is additive — `trace_log: Option<PathBuf>` defaults to `None`, so
behavior is unchanged for other uses of the same binary. Ruffle's master
branch requires the nightly toolchain (uses `as_array_of_cells`); build with
`cargo +nightly build --release -p exporter`.

## Architecture decisions

### Why bytecode injection (not prelude SWF)

`SWFRecompDocs/plans/completed/runtime-swf-injection-demos.md` documents three
ways to instrument a running SWF: ActionScript `loadMovie` inspection, C-side
`test_harness.c` hooks, and "prelude SWF" (LittleCube's pattern). For runtime
*API* implementation, prelude SWF is the winner.

For *divergence detection* the considerations are different: the same
instrumentation has to run identically under both runtimes. Prelude SWFs are
asymmetric — SWFRecomp's `verify_output.py` recognises `prelude_*.swf` and
loads it before the main SWF, but Ruffle's exporter has no equivalent
convention. We'd need a wrapper SWF or a Ruffle CLI change.

Bytecode injection sidesteps that: we mutate the target SWF once and hand the
same bytes to both runtimes. Both see identical input. The cost is that we
mutate the game, but for read-only instrumentation that's acceptable.

### Why a per-frame state dump as `trace()` lines (not ExternalInterface)

Existing injection demos use `ExternalInterface` to push structured data out
to JavaScript. That doesn't help us here:

1. The Ruffle exporter is headless and has no JS bridge.
2. SWFRecomp's graphics-native binary also has no JS bridge.
3. `trace()` already goes to stdout/log on both sides — same channel, same
   ordering semantics.

So the tracer emits one `trace()` call per state observation:

```
F1 _currentframe=1
F1 _root.instance1 _x=275 _y=200 _cf=1 _vis=true
F1 _root.instance2 _x=260 _y=190.6 _cf=1 _vis=true
F2 _currentframe=2
...
```

Line-diffing two trace logs identifies the first divergence at the
granularity of *one observation per line*. A divergence in one variable
doesn't push every subsequent line out of alignment, which is what would
happen with a single line per tick.

### Why duplicate Ruffle and SWFRecomp on every run (not a shared reference)

The harness re-runs Ruffle on every invocation rather than caching a
`output.txt` reference (the way `verify_output.py` does for the test suite).
Reason: we're iterating on SWFRecomp and the tracer together — the tracer
emits a slightly different signature any time we tweak it, and Ruffle is the
ground truth for *that* signature. Caching the Ruffle output would require
invalidating it any time we touch `Tracer.as`. Cheap enough to re-run for
~30 frames (a few seconds each), so we just do.

## What turned up on the first real run

`tools/divergence/divergence_test.py ~/CC/glaiel/swfs/Pong.swf --frames 20`,
strict pixel match, no input events:

```
Trace lines: ruffle=76, swfrecomp=96
Trace: first divergence at filtered line 6
  ruffle:    F2 _currentframe=2
  swfrecomp: F2 _currentframe=1
Image: first divergence at frame 1: max_diff=255 (50459 outliers)
```

Two distinct bugs in a single sub-second run on the smallest glaiel SWF:

1. **Trace divergence**: `_root._currentframe` advances 1→2→3 in Ruffle but
   stays stuck at 1 in SWFRecomp from frame 2 onward. Possibly the same
   class of root-frame-sync bug that's been getting iterated on through
   `g_deferred_root_goto` and friends in `swf.c`/`swf_core.c` recently
   (see MEMORY.md entries dated 2026-05-11).
2. **Image divergence**: frame 1's PNGs disagree at 50k+ pixel positions
   with max channel difference 255 — same 550×400 RGBA dimensions, so a
   real rendering difference, not a sizing/format mismatch. Could be
   background-fill, preloader state, or an empty/uninitialized render
   target.

Both are real, both happen on frame 1-2, neither requires input events.

Also worth noting: SWFRecomp produced **16 PNGs for 20 requested frames**
while Ruffle produced 20 — meaning SWFRecomp's tick loop is running fewer
ticks than Ruffle for the same num_frames. That's a third divergence on top
of the two above, surfaced just by counting capture artifacts.

## Known noise filters

These appeared in the first run and were added to `NOISE_PATTERNS` in
`divergence_test.py`:

- `$version=...` — `flash.system.Capabilities.version` is platform-dependent
  ("LNX 32,0,0,0" vs "WIN 32,0,0,0 "). Pure platform metadata; can never
  match.
- `SWF Runtime Loaded` and `[HEAP] Initialized` — SWFRecomp's startup banner
  to stderr/stdout. Not from the tracer.

Other categories likely to appear (left unfiltered for now until they show
up):

- Floating-point precision drift: `_x=274.95` vs `_x=274.9499969482422`. The
  tracer doesn't `Math.round()` deliberately, since rounding can hide real
  divergences. If FP drift drowns the signal, add a numeric-tolerance
  comparator (similar to `_lines_approx_equal` in `verify_output.py`).
- Object pointer addresses (if any leak into traces via `[object Object]`
  default toString).
- Asynchronously-loaded resource timing if MovieClipLoader behavior
  diverges.

## Open questions / future work

- **Frame numbering alignment.** Ruffle's `0.png` corresponds to SWFRecomp's
  `F0001.png` (state after the first tick). The mapping is encoded in
  `divergence_test.py`. If Ruffle's exporter ever changes how it indexes
  captures, this will quietly skew. Currently relies on
  `for i in 0..totalframes { run_frame(); capture; }` semantics.
- **Image tolerance defaults.** Strict (0/0) catches everything. Real
  AA/subpixel differences will trigger it for any rendering work. The CLI
  flags `--tolerance N --max-outliers N` are there, but we haven't picked
  defaults for "acceptable" cross-runtime drift.
- **Number of frames.** Default 30. Most divergences worth catching seem to
  show up in the first few ticks (Pong manifested at frame 1-2). Longer runs
  cost more and produce noisier diffs. If we want to catch later divergences
  (post-preloader, mid-game state machines), we'd need either much higher
  frame counts or a "skip first N frames" option.
- **Input simulation.** Skipped per user direction — current divergences
  surface pre-input. If we eventually want to script input, both runtimes
  already accept event-stream files (`input.json` in SWFRecomp, similar in
  Ruffle's test framework); they'd need to drive deterministic input
  identically.
- **Scope of trace dump.** The tracer currently emits:
  `_currentframe`, sorted scalar `for..in _root`, and a depth-3 capped
  display-list walk (`_x`, `_y`, `_currentframe`, `_visible`) per MC. Enough
  to catch most state divergences. Things deliberately *not* emitted:
  `_xscale`/`_yscale`/`_rotation`/`_alpha` (noisy on animated content),
  user-defined object properties beyond `_root` scalars (could miss
  game-state divergences in nested data structures).

## Files produced this session

```
tools/divergence/
  Tracer.as              AS2 source for per-frame state dumper
  build_tracer.sh        compile via MTASC + extract bytecode
  extract_bytecode.py    pulls AVM1 tag bytes from compiled tracer SWF
  tracer.swf             compiled tracer (CWS, 1042 bytes)
  tracer_bytecode.bin    extracted DoInitAction+DoAction bytes (1918 bytes)
  inject_tracer.py       splice tracer into target SWF before first ShowFrame
  run_swfrecomp.py       drive graphics-native, capture PNGs + trace
  divergence_test.py     end-to-end harness; writes divergence.txt
  runs/<stem>/           outputs per game (gitignored — not committed)
```

Patch in `~/CC/ruffle/exporter/src/`:
- `cli.rs`: `--trace-log PATH` flag.
- `exporter.rs`: `TraceLogBackend` struct (`Arc<Mutex<String>>`), wired into
  `PlayerBuilder.with_log()` when the flag is set.
- `lib.rs`: write the captured trace to the configured path after all frames
  render.

The Ruffle patch is local-only. If we ever update the `~/CC/ruffle` clone
from upstream, the patch will need to be reapplied (or upstreamed).
