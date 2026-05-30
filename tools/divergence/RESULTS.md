# Divergence Test Results — local_batch demos

Each `docs2/examples/local_batch/` demo was (a) rebuilt as a docs2 WASM graphics
demo from its `~/CC/flasharchive/` source SWF, and (b) run through the divergence
harness (`tools/divergence/divergence_test.py`), which compares SWFRecomp
(graphics-native) against Ruffle on both `trace()` output and per-frame rendered
images.

- **Source SWFs:** `~/CC/flasharchive/`
- **Harness usage:** `SWFRecompDocs/guides/divergence-harness-usage.md`
- **Run command per demo:** `python3 tools/divergence/divergence_test.py "<swf>" --frames 16`
- **Frame count:** 16 (matches the image-capture cap, see note 1)
- **Image comparison:** strict (tolerance 0, max-outliers 0)
- **Per-run outputs:** `tools/divergence/runs/<stem>/` (gitignored)

Date of run: 2026-05-29

## Investigation notes (read before interpreting results)

1. **`MAX_CAPTURES 16` in `capture.c`** hard-caps PNG capture at the first 16
   frames regardless of `--frames`. The tick loop still runs the full count (a
   30-frame probe produced 16 PNGs but 29 tracer ticks), but **image comparison
   only covers frames 1–16.** Trace comparison is unaffected (covers all ticks).
   Concrete consequence: **Checkers** diverges at frame 19 (auto-instance name
   `instance4` vs `instance6`) — visible at `--frames 20` but *not* caught here
   at 16. To detect later divergences, bump that `#define` and rebuild.

2. **Recompiler 30s timeout (`verify_output.py::recompile_swf`).** The divergence
   harness recompiles the *injected* SWF with a hardcoded 30s limit. Two large
   SWFs exceeded it: **Art of War** (1.5MB) and **Castle Hero** (14MB). Their
   docs2 WASM demos built fine (that path recompiles the original with a longer
   timeout); only the divergence-side recompile timed out. Bump the 30s limit to
   recover them.

3. **Tracer (`_root.onEnterFrame`) fires on both sides for every game except
   Snake.** Snake (the only SWF originally authored as v5) doesn't dispatch its
   tracer `onEnterFrame` under SWFRecomp and emits no `trace()` of its own, so
   its report is image-only. The tracer mechanism itself is sound (minimal
   stopped/playing-root probes dispatch every tick).

   > Tooling caveat: game `trace()` output can contain non-UTF8 bytes, so plain
   > `grep -c '^F'` reports a blank/0 count on those files (grep treats them as
   > binary). Use `grep -a` for accurate F-line counts.

## Summary (14 demos)

| Demo | WASM build | Trace (ruffle/swfrecomp) | Trace result | Image diff (≤f16) |
|---|---|---|---|---|
| Achievement Unlocked | ✅ | 250 / 278 | diverge L18: `k=1` vs spurious `instance1=undefined` | f1, 720550 px |
| Age of War | ✅ | 61 / 61 | **identical** | f1, 308209 px |
| Art of War | ✅ | — / — | ⚠️ harness recompile **timeout** | — |
| Avalanche | ✅ | 76 / 91 | diverge L2: `instance1 _x=…` vs spurious `instance3=undefined` | f1, 51067 px |
| Bloons | ✅ | 295 / 504 | diverge L0: Ruffle `MochiServices Connecting…` (no net in SWFRecomp) | f1, 1228800 px |
| Bloons TD | ✅ | 166 / 198 | diverge L5: `_root.reserved` + frame-advance mismatch (`_cf` 1 vs 3) | f1, 1228800 px |
| Bloons TD 2 | ✅ | 173 / 233 | diverge L6: same `reserved` + frame-advance pattern | f2, 7758 px |
| Bloxorz | ✅ | 76 / 91 | diverge L2: `backser _x=…` vs `percentr="Preloading…"` | f1, 165000 px |
| Castle Hero | ✅ | — / — | ⚠️ harness recompile **timeout** | — |
| Checkers | ✅ | 16 / 16 | **identical** (real diverge at f19 is past the 16-frame window) | f2, 339 px |
| Doodle Jump | ✅ | 211 / 211 | **identical** | f1, 15440 px |
| Duck Life 1 | ✅ | 482 / 497 | diverge L15: `hat=0` vs spurious `game=undefined` | f1, 65236 px |
| Duck Life 2 - World Champion | ✅ | 271 / 316 | diverge L4: `loadcheat=0` vs `loadcheat=0.5` | f1, 1176829 px |
| Snake | ✅ | 87 / 0 | tracer not dispatched on SWFRecomp side (image-only) | f1, 2517 px (30f run) |

(Filtered trace-line counts. "px" = channels exceeding strict tolerance on the
first diverging frame. Snake was run earlier at `--frames 30`; all others at 16.)

## Cross-cutting patterns

- **Spurious `_root.instanceN=undefined` globals** appear on the SWFRecomp side
  in several games (Achievement Unlocked → `instance1`, Avalanche → `instance3`,
  Duck Life 1 → `game`). SWFRecomp enumerates `_root` properties that Ruffle does
  not — a recurring, real AVM1 divergence worth a dedicated look.
- **Frame-advance timing** differs in the Bloons family: at the same tick Ruffle
  reports a lower `_currentframe`/`_cf` than SWFRecomp (e.g. Bloons TD `F2`:
  Ruffle still at frame 1 state, SWFRecomp at frame 3). Preloader pacing.
- **Network/MochiAds**: Bloons traces `MochiServices Connecting…` under Ruffle;
  SWFRecomp has no network layer, so this diverges immediately (expected).
- **Trace fully matches** for Age of War, Checkers, Doodle Jump within 16 frames.
- **Every game's image diverges by frame 1–2.** Most are full-frame
  (`max_diff=255`, huge outlier counts) → background/preloader rendering differs
  fundamentally; a few are tiny (Checkers `max_diff=3`, Bloons TD 2 = 204) →
  sub-pixel/AA only.

## Per-demo detail

### Achievement Unlocked
Trace diverges at filtered line 18 — Ruffle has `F2 _root k=1`; SWFRecomp instead
emits `F2 _root instance1=undefined` (a spurious enumerable global; `instance1`
sorts before `k`). Image: frame 1, `max_diff=253`, 720550 outliers.

### Age of War
Trace **identical** (61 lines). Image: frame 1, `max_diff=255`, 308209 outliers.

### Art of War  ⚠️
WASM demo built OK. Divergence test failed: the recompiler **timed out** (30s
limit) recompiling the 1.5MB injected SWF. Ruffle side produced 240 F-lines.
Recoverable by bumping the recompile timeout.

### Avalanche
Trace diverges at filtered line 2 — Ruffle dumps `_root.instance1` display state;
SWFRecomp emits a spurious `_root instance3=undefined` global instead. Image:
frame 1, `max_diff=255`, 51067 outliers.

### Bloons
Trace diverges at line 0 — Ruffle's first line is `MochiServices Connecting…`
(MochiAds network init), which SWFRecomp (no network layer) never emits. Image:
frame 1, full-frame (`max_diff=255`, 1228800 outliers).

### Bloons TD
Trace diverges at line 5 — `_root.reserved` placement plus a frame-advance
mismatch (`F2 _currentframe=3` on SWFRecomp vs Ruffle still showing frame-1
state). Image: frame 1, full-frame (1228800 outliers).

### Bloons TD 2
Same pattern as Bloons TD (diverge at line 6: `reserved` + faster frame advance).
Image: frame 2, `max_diff=204`, 7758 outliers.

### Bloxorz
Trace diverges at line 2 — Ruffle dumps `_root.backser` display state; SWFRecomp
emits `_root percentr="Preloading Game ... 0 %"` (preloader var) first. Image:
frame 1, `max_diff=255`, 165000 outliers.

### Castle Hero  ⚠️
WASM demo built OK. Divergence test failed: recompiler **timed out** (30s) on the
14MB injected SWF. Ruffle side produced 1275 F-lines. Recoverable by bumping the
recompile timeout (and likely needs more than a small bump given the size).

### Checkers
Trace **identical** within 16 frames. (At `--frames 20` it diverges at frame 19:
`diff_picker.instance4` vs `instance6` — an auto-instance-counter difference now
outside the window.) Image: frame 2, `max_diff=3`, 339 outliers (sub-pixel).

### Doodle Jump
Trace **identical** (211 lines). Image: frame 1, `max_diff=255`, 15440 outliers.

### Duck Life 1
Trace diverges at line 15 — Ruffle has `_root hat=0`; SWFRecomp emits a spurious
`_root game=undefined` (sorts before `hat`). Image: frame 1, `max_diff=255`,
65236 outliers.

### Duck Life 2 - World Champion
Trace diverges at line 4 — `_root loadcheat=0` (Ruffle) vs `loadcheat=0.5`
(SWFRecomp): a real value mismatch in a game variable. Image: frame 1,
`max_diff=255`, 1176829 outliers.

### Snake
SWFRecomp's tracer printed `TRACER: start` but dispatched `_root.onEnterFrame`
0 times (Ruffle: 87 F-lines); Snake emits no `trace()` of its own, so this is an
image-only comparison. Image: frame 1, `max_diff=204`, 2517 outliers. See note 3.
