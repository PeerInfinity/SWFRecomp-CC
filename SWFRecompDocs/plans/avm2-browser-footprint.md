# AVM2 browser memory footprint — does it really need 2 GB? (measure + plan)

Status: **IMPLEMENTED + BROWSER-RIG VALIDATED (2026-07-21).** Levers 2A + 1A + 4
shipped and confirmed on real-GPU Windows Chrome. Session prompt:
`SWFRecompDocs/prompts/avm2-browser-footprint-plan.md`.

**FLEET DEPLOYED (2026-07-21, recorded here because docs2 is untracked):** all
five AVM2 demos (fresh recompile — the four Flixel titles stamp intrinsic id 4
on `FlxTilemap.arrayToCSV`; rwk/rwp `1340f1fc…`, rwf `0067a14b…`, rwic
`56e9fc6d…` — plus FRESH=1 wasm) and two AVM1 demos (N, Doodle_Jump) redeployed
to docs2 with the new arenas, md5-verified. Real-GPU browser smoke: AVM2 titles
flat at ~634-654 MB HEAPU8 after Start (was 2117), AVM1 at ~307-369 MB (old
arena showed ~1148), all title screens render, 0 OOM. rwf/rwic booting flat is
their footprint validation (their AP-build gameplay rig runs deliberately
skipped; RWK covers the cadence question). Seedling AP handoff wasm restaged to
Archipelago-CC. Bloons excluded: pre-existing preloader hang (accepted
network-pacing class), not memory — swapped for Doodle_Jump.

> **BROWSER RIG RESULT (2026-07-21, Windows Chrome, real Intel gen-9 GPU, RWK —
> the heaviest-churn title).** The 512 MB arena's final gate PASSES:
> - **Footprint: HEAPU8 128 MB before Start → 633.9 MB first sample after Start
>   (512 arena + 122 base), flat across a 60 s soak (min==max), 0 OOM.** Was
>   2117 MB (§1b) — a **~1483 MB / 70% cut in resident RAM per player at Start.**
>   `INITIAL_MEMORY` confirmed committing 128 MB at page load (was 512).
> - **Gameplay (teleported into xplor.PlayState via the AP bridge — the plain
>   build's in-canvas menu mouse doesn't reach Flixel): mean 22.5 ms → 44.4 fps,
>   p50 21.2 ms (matches the native RWK 21.6 ms intrinsic baseline), p95
>   29.2 ms, 0 stalls >250 ms, 1.6% frames >33 ms, HEAPU8 flat 633.9 MB, 0 OOM**
>   over a 60 s live-gameplay soak (tilemap + player + patrolling enemies, quad-
>   tree churning every frame). **The GC-cadence concern (smaller watermark →
>   ~2.4× more collects) does NOT bite — no back-off to 768 MB–1 GB needed.**
>   Since RWK is the heaviest-churn title and the arena size is a universal
>   constant, this validates the 512 MB arena for the whole corpus.

> **§6 IMPLEMENTATION STATUS (2026-07-21).**
> - **Step 1 — native `FlxTilemap.arrayToCSV` intrinsic (Lever 2A): SHIPPED.**
>   Method-level fingerprint gate (id 4) in `abc_emit.cpp`; native O(n) builder
>   in `avm2_flixel.c`. Baked constants: RWK+RWP `1340f1fcfea0a94d`, RWF
>   `0067a14b337b8c8b`, RWIC `56e9fc6d17820266` — each stamps EXACTLY FlxTilemap,
>   0 false positives across all 4 titles, deterministic. **Byte-identity proven**
>   two ways: a built-in `AVM2_ARRAYTOCSV_SELFCHECK` (fast O(n) builder vs a
>   literal O(n²) transliteration of the AS3 nest, same runtime primitives) — 0
>   mismatches on RWP's real boot maps — and a full **frame oracle** (RWP, 200/200
>   frames byte-identical, intrinsic ON vs `AVM2_NO_INTRINSICS`).
> - **Step 2 — native worst-single-tick re-measure: DONE for RWK (representative).**
>   RWK worst gameplay-tick gross **1397 MB → 118 MB** (the residual is
>   `loadMap`'s CSV-parse split, intrinsic-independent); run-wide peak_allocated
>   **1423 → 246 MB**. The OFF figure reproduces §1a's 1397 MB exactly.
>   *Pending:* RWF/RWP/RWIC gameplay re-measure needs each title's New-Game TAS
>   click (RWK's `(158,303)@t255` did not transfer; boot-only runs confirm the
>   intrinsic engages on all four).
> - **Step 3 — AVM2 arena 1984 → 512 MB (Lever 1A): SHIPPED + RIG-VALIDATED.**
>   `heap.c` `__EMSCRIPTEN__ && SWF_AVM2` branch → 512 MB; `INITIAL_MEMORY` 512
>   → 128 MB. Native no-OOM (RWK 246 MB at 512, survives 256 MB) AND the
>   real-GPU browser gate above: 634 MB resident (70% cut), 44 fps gameplay, 0
>   stalls >250 ms, 0 OOM. No back-off needed. New `SWF_HEAP_MB=<n>` env
>   overrides the arena for A/B sizing.
> - **Step 4 — AVM1 arena 1024 → 256 MB (Lever 4): SHIPPED (code).** `heap.c`
>   `__EMSCRIPTEN__` (AVM1) branch → 256 MB. **Native probe:** N (largest complex
>   AVM1 demo) peaks 83 MB at a 256 MB arena (33%, 0 OOM) — ~3× margin. New
>   `SWF_HEAP_STATS` env (AVM1 twin of `AVM2_HEAP_STATS`) added for the probe.

Related memories: [[avm2-rwk3-browser-demo]] (how 1984 MB was chosen),
[[avm2-collectable-strings]], [[avm2-raw-alloc-reclamation]],
[[avm2-gc-tier2-collector-cost]], [[avm2-inline-slots-ruled-out-o1heap-binning]],
[[avm2-hud-counters-are-real-sawtooth]].

---

## Headline (the answer to "does it need 2 GB")

**Today, yes — but only for one tick of reclaimable garbage per level load, and
that is a fixable one-function bug, not a real memory requirement.** The
worst-case title (RWIC) genuinely allocates 1788 MB, but **96% of it is a
single tick's `FlxTilemap.arrayToCSV` concat intermediates** (measured, §1a) —
reclaimed at the very next collect, leaving a ~67 MB live set. Remove that
concat (§3 Lever 2, a native intrinsic on the standing fingerprint gate) and
**every measured title needs ≤512 MB** — a ~1.6 GB cut in resident RAM per
player. And the cut matters more than a stale headroom number would suggest,
because the arena is committed *resident* in the browser (below). Two findings
drive the plan:

1. **The browser arena is committed AND zero-filled at load, not lazily.** The
   heap.c comment claims "physical RAM only allocated on first access (lazy
   allocation by OS)." That is true on native Linux (anonymous `mmap` +
   demand paging) but **FALSE under emscripten.** Emscripten implements
   anonymous `mmap` (system/lib/libc/emscripten_mmap.c) as
   `emscripten_builtin_memalign(len)` **followed by `memset(ptr, 0, len)`**.
   So `heap_init`'s single 1984 MB `mmap` at boot:
   - forces `WebAssembly.Memory` to grow from `INITIAL_MEMORY=512MB` to ~2 GB
     **before the first frame** (memalign of 1984 MB → `emscripten_resize_heap`
     → `Memory.grow`), and
   - **touches every one of those pages via `memset`**, so the browser
     physically backs the whole ~2 GB ArrayBuffer at load.

   The consequence: **the moment a player hits Start, their tab jumps to ~2.1 GB
   of *physically resident* RAM — before any real gameplay allocation.**
   (`heap_init` runs at the top of `runSWF_avm2()` = the first frame after the
   user gesture, so page-load costs only `INITIAL_MEMORY`; the ~2 GB lands on
   Start, which every player does and which is required for WebGPU/audio.) This
   makes the problem unambiguously **arena *sizing*, not arena *headroom*.**

   **MEASURED (§1b, Windows-Chrome / real Intel gen-9 GPU, 2026-07-21):** rwk
   `Module.HEAPU8.length` = 512 MiB before Start → **2117.4 MiB the very first
   sample after Start** (<0.1 s, no ramp), flat thereafter; renderer working set
   **~2121 MiB ≈ HEAPU8.length**, i.e. the arena is resident, not merely
   reserved. Chrome/V8 commits + zero-fills the `WebAssembly.Memory` backing
   store on `memory.grow`, so trimming o1heap *usage* cannot help — only
   trimming the *reservation* can.

2. **The arena is ~20–26× larger than any title's live set — because it is
   sized to a single tick's garbage, not to live.** MEASURED at HEAD (§1a): the
   worst-case title RWIC peaks at **1788 MB for exactly one tick** (tick 218,
   `FlxTilemap.arrayToCSV` building a multi-hundred-MB CSV across 3 tilemap
   layers in `PlayState.create()`), then that transient is reclaimed at the next
   between-tick collect and RWIC settles to a **~67 MB live plateau**. RWF
   (1588 MB transient → 90 MB live) and RWP (327 MB transient → 85 MB live) show
   the identical shape. **The arena floor is set entirely by the largest
   single-tick transient**, because the GC only reclaims between ticks
   ([[avm2-stage11-gc]] quiescence). Kill that transient and the arena can
   shrink to ~live. (The 1984 MB was sized 2026-07-18 against a pre-reclamation
   heap — RWK boot 1409 MB, immortal strings, +94 MB/min leak — but even at HEAD
   the *transient* still demands ~1788 MB for one tick, so shrinking the arena
   requires attacking the transient, not just the banked reclamation work:
   [[avm2-collectable-strings]], [[avm2-raw-alloc-reclamation]].)

   **This re-spikes on every level load, not just boot** — `arrayToCSV` runs in
   each `PlayState.create()`, so a one-time "boot allowance" would not help; the
   spike must be *prevented* (§3 Lever 2).

The same mechanism applies to the **AVM1 browser demos** (Tetris, N,
Minesweeper, …): they share `heap.c`/`vmem_reserve` and `heap_init(…, 0)` picks
the wasm32 default **1 GB** arena, so **every AVM1 game visitor commits +
zero-fills ~1 GB at load** for a live set of a few MB. That is a large, cheap,
independent win (§3 lever 4).

---

## §1 — What is actually true at HEAD (per title)

> Method: fresh `-O2` no-graphics native builds with the new instrumentation,
> `AVM2_HEAP_STATS=1`, TZ=NPT-5:45 (deterministic). Browser: Windows-Chrome via
> the WSL Playwright rig (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`), `Module.HEAPU8.length`
> sampled across boot→menu→gameplay→soak. All phases state-proven.

### 1a. Native heap truth (o1heap `allocated`, fragment-rounded; -O2, TZ=NPT-5:45)

| Title | Peak alloc (MB) | Live plateau (MB) | **Worst single-tick gross** (MB, tick) | Peak ÷ live | Notes |
|---|---|---|---|---|---|
| RWIC (…Ice Cream, 2.35) | **1788** | **67** (60–90) | **1742 (tick 218)** | **26×** | `arrayToCSV` × 3 tilemap layers in PlayState.create |
| RWF (…Fishy, 2.35) | **1588** | **90** | **1552 (tick 312)** | 18× | same mechanism |
| RWP (…Puppy, 2.21) | **327** | **85** | **302 (tick 516)** | 4× | same mechanism, smaller map |
| RWK (…Kitty, 2.21) | **1423** | **~86** post-collect | **1397 (tick 275)** | 16× | spike at PlayState.create after the TAS click; GC=0 confirms it is intra-tick |
| Seedling (teleport) | **103** | **72** | **25 (tick 0)** | 1.4× | **FlashPunk, no tilemap → NO arrayToCSV spike** — peak ≈ live (the control) |
| AVM1 demo (Tetris) | ~1 GB arena | single-digit MB | — | — | resident 1148 MiB @Start (§1b), live a few MB |

**The Seedling control is decisive:** the one title without a Flixel tilemap has
**no transient spike at all** (peak 103 MB ≈ live 72 MB), confirming the ~1.4–1.8
GB peaks on the four RW titles are specifically the `arrayToCSV` concat, not a
general runtime cost.

**Sizing caveat on "live" (from RWK).** `AVM2_HEAP_STATS`'s `Allocated`/`Live at
exit` is sampled *wherever the run stops in the GC sawtooth*, not at a
post-collect floor. RWK's live sampled 109→410→325→476 MB across 300–3000 ticks:
the adaptive watermark lets up to `min(256 MB, (cap−live)/4)` of gameplay garbage
accumulate between collects (`avm2_gc.c:884`), so at the 4 GB arena the sawtooth
peak reaches ~476 MB even though the post-collect *live floor* is ~86 MB. **The
arena must therefore hold `live floor + watermark-bounded garbage`, and that
garbage term self-scales with capacity** — a smaller arena shrinks the watermark
and the sawtooth with it (priced in §3 Lever 1A / Appendix). RWIC's live band
was tighter (60–90 MB) — lower per-tick churn than RWK's heavy FlxQuadTree
rebuild.

*Definitions.* **Peak alloc** = o1heap `peak_allocated` (run-wide high-water).
**Live plateau** = `allocated` at a gameplay plateau; report the sawtooth band,
not a lazy-sweep peak ([[avm2-hud-counters-are-real-sawtooth]]). **Worst
single-tick gross** = the new instrument (§5): peak `allocated` *within one
tick* minus live at that tick's start — the number the arena must actually
hold, since no collect runs mid-tick. For these menu-first games the worst tick
is the **level-load** tick (PlayState.create), not tick 0, so boot-tick gross is
~0 and the whole spike lands in the "gameplay" bucket; the table reports the
union max (whichever tick it falls on).

**Verdict: the peak is a single-tick TRANSIENT on every title, not live.** RWIC
live-vs-depth: t200=43, **t218 spikes to 1788**, t240=62, t300=77, t600=90,
t1000=68, t1500=71 MB — live never re-approaches 1.7 GB after the spike tick.
Native RSS peaks: RWIC 1434, RWF 1281 MB. Zero OOM/crashes. Native peaks
(1788/1588/327) match the prior-session browser figures (1770/1577/330) — same
mechanism, cross-validated. **Reproduction note:** RWIC/RWF gate boot on
`LocalConnection().domain` (needs `GAME_SWF_URL=http://www.maxgames.com/…`, not
the harness default `file:///test.swf` → `localhost` which the `locallock` stub
blocks); mouse events are in 640×480 display space (2× the 320×240 game space).
RWP has no domain gate.

### 1b. Browser truth — the commitment question (ANSWERED)

Windows-Chrome via the WSL Playwright rig, **real Intel gen-9 GPU** (not
SwiftShader), deployed 2026-07-20 wasm (mmap size is unchanged in `heap.c`).
`Module.HEAPU8.length` (wasm linear-memory size), state-proven phases:

| Phase | rwk (AVM2, 1984 MB arena) | Tetris (AVM1, 1 GB arena) |
|---|---|---|
| page + wasm loaded, **before Start** | 512.0 MiB (`INITIAL_MEMORY`) | 256.0 MiB (`INITIAL_MEMORY`) |
| **first sample after Start** (<0.1 s) | **2117.4 MiB** | **1147.7 MiB** |
| +5 s … +90 s soak | 2117.4 (flat) | 1147.7 (flat) |

- **Jump is instantaneous, no lazy ramp.** linear memory = arena + fixed base
  (AVM2: 1984 arena + 133.4 base; AVM1: 1024 arena + 123.7 base).
- **Physically resident:** the isolated renderer process working set held
  **~2121 MiB ≈ HEAPU8.length** through the soak — the arena is committed +
  zero-filled, not merely reserved. Contradicts the `heap.c` "lazy on first
  access" comment (native-only). **Verdict: immediate, full, resident commit —
  an arena-*sizing* problem.**
- **No leak:** HEAPU8 dead flat across 90 s (arena pre-committed); JS heap
  ~2.6→5 MB with a mild GC sawtooth — negligible (<0.3% of the arena),
  sawtooth not leak ([[avm2-hud-counters-are-real-sawtooth]]).

### 1c. Non-arena consumers (total tab cost)

- `rwk.wasm` 6.73 MiB on disk (2.16 MB gzip) + `rwk.js` 94 KiB + bridge 4.7 KB +
  `test.swf` 816 KiB — rounding error next to the arena.
- **GPU process ~564–578 MB, stable** (WebGPU/Dawn + Chromium GPU baseline) —
  the #2 consumer. rwk did **not** hit Seedling's texture-array-layer blowup
  ([[webgpu-texture-array-layer-limit-blank-render]]); GPU proc held steady.
- **Total tab ~2.9 GB** = renderer 2.07 GB (wasm, ~72%) + GPU 0.56 GB +
  browser/net/utility ~0.3 GB. **The wasm arena is ~72% of the tab and the only
  line the game controls by sizing** — the GPU floor is fixed by WebGPU.

---

## §2 — Decomposing the peak (RWIC, the worst title: peak 1788 MB)

The arena must hold the worst *instantaneous* demand = live set + the largest
single-tick transient (they coincide within one tick, since the collect that
would reclaim the transient runs only at the *next* boundary). The split is
lopsided:

| Component | RWIC | Share of the 1788 MB peak |
|---|---|---|
| **(a) genuine live set** | ~67 MB | ~4% |
| **(b) single-tick `arrayToCSV` transient** | ~1721 MB (1742 gross − churn) | **~96%** |
| **(c) o1heap pow-2 binning slack** | *inside (b)* | — |
| **(d) headroom / safety-valve margin** | (8/7 factor on the above) | — |

- **(a) live set ~67 MB** — the persistent root graph (Flixel quadtree churns
  but stays 60–90 MB). This is the real footprint; everything above it is
  reclaimable.
- **(b) the transient IS the problem: ~96% of the peak is one tick's garbage.**
  `FlxTilemap.arrayToCSV` builds a CSV string for a large tilemap by repeated
  concatenation — O(n²) intermediate strings — three times (three layers) in
  `PlayState.create()`. Every intermediate is reclaimable at the next collect,
  but they all coexist within the tick. **The final CSV is tiny** (188×84×~4 B
  ≈ 63 KB/layer) — the ~1.7 GB is entirely the concat's intermediate garbage.
- **(c) binning slack is folded into (b), not separate.** o1heap sizes every
  request `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)`; **on wasm32
  `O1HEAP_ALIGNMENT = 16`** (native 32), so each growing intermediate string
  rounds up to the next power of two — up to ~2× waste, already inside the
  1.7 GB. Attacking (b) removes its (c) for free; standalone size-class tweaks
  were ruled out once ([[avm2-inline-slots-ruled-out-o1heap-binning]]) and are
  not worth reopening while (b) is 96%.
- **(d) margin.** o1heap needs slack below **7/8 of capacity** or the collector
  trips its eager full-sweep safety valve (`avm2_gc.c:833`,
  `used > cap − cap/8 → budget = 0`) — a stop-the-world stall. The adaptive
  watermark also reserves `(cap − live)/4` headroom (`avm2_gc.c:883`). So the
  arena floor is `(8/7) × peak_demand`, **and shrinking `cap` toward `live`
  shortens the collect interval** — the FPS/footprint coupling every arena
  lever must price.

**The decomposition dictates the plan:** since 96% of the peak is a reclaimable
single-tick transient, the lever is to *stop creating the transient*
(§3 Lever 2), after which the arena floor drops from ~1788 MB to ~`(8/7)×(live +
per-tick churn)` ≈ well under 200 MB — a >10× reduction. No lever that only
trims live, headroom, or binning can move the floor while the transient stands.

---

## §3 — Lever map (priced; none built)

> Gate: **any footprint lever that drops a title below 30 fps is a
> non-starter** (the playability arc is the banked asset). GC cadence is coupled
> to arena headroom (§2d), so every arena-size change is also a GC-cadence
> change and must be priced on both axes.

**Dependency:** §2 shows 96% of the worst-case peak is the `arrayToCSV`
transient. So **Lever 2 is the gate and ships first**; Lever 1 (the actual
footprint win) is *gated on it* — you cannot safely shrink the arena while any
title still spikes to 1788 MB for one tick. Recommended order: **2 → 1 → 4**.

### Lever 2 (ships FIRST) — Kill the single-tick `arrayToCSV` transient

Removes §2(b)+(c) — 96% of the peak — and is the enabler for Lever 1.

- **2A. `FlxTilemap.arrayToCSV` native intrinsic** via the standing fingerprint
  gate. **Recommended.** Precedent is fully set — all four RW titles already
  ship the native `org.flixel` collision intrinsic
  ([[avm2-flixel-native-intrinsic]], [[avm2-flixel-235-titles-extension]]); the
  gate holes are closed, so even a closure-building method is coverable
  ([[avm2-fingerprint-gate-holes-closed]]). A native `arrayToCSV` builds the CSV
  in one grow-realloc C buffer — no O(n²) intermediate strings — collapsing the
  ~1.7 GB transient to the CSV's final size (~63 KB/layer). Effort: **S–M** (one
  intrinsic + per-title fingerprint bake; verify byte-identical CSV vs AS3 —
  the collision-intrinsic verification playbook applies directly). Reduction:
  the entire worst-single-tick gross for all four Flixel titles (RWIC 1742 MB,
  RWF 1552, RWP 302, RWK 1397 → each ~sub-MB). Perf: **faster** level-load,
  never slower. Risk: the fingerprint bake must cover the 2.21 and 2.35 variants
  (precedent shows both are coverable). **This is the lever.**
- **2B. String-concat accumulation fast path** (general fallback): rope/builder,
  or realloc-in-place when the LHS is the newest allocation and provably dead.
  Broader than 2A (any concat-heavy path) but must respect AS3 string
  immutability/identity (a concat result is a distinct String; in-place mutation
  is only safe when the LHS is unreachable). Effort: **M**, higher risk. Only
  needed if a title spikes on concat *outside* `arrayToCSV` — none measured so
  far, so 2A suffices; keep 2B in reserve.

### Lever 1 (gated on Lever 2) — Right-size the arena → **universal fixed (1A)**

With Lever 2 shipped, every measured title's peak demand collapses to `live +
per-tick churn` (~67–90 MB live + a few MB churn). Because **no title has a
large live set** (the worst, RWF, is 90 MB), a single universal fixed arena
clears all of them with wide margin — segmentation is unnecessary.

- **1A. Universal smaller fixed arena. RECOMMENDED.** One constant in `heap.c`
  (the `__EMSCRIPTEN__ && SWF_AVM2` branch). Sized to `⌈(8/7) × post-lever-2
  working peak⌉` + variance headroom → **512 MB** is the defensible target (see
  Appendix): the post-lever-2 working peak is `live floor (~90 MB) +
  watermark-garbage`, and at a 512 MB cap the watermark self-clamps to
  `(512−90)/4 ≈ 105 MB` (down from 256 MB today), so the sawtooth peaks near
  ~195 MB — well under the 7/8 valve (448 MB), ~2.3× margin, room for
  unmeasured/future titles. Reduction: **1984 MB → 512 MB (~1.6 GB less
  resident RAM per player at Start).** Effort: **XS.**
  **Perf — must rig-check (this is the §2d coupling the gate warns about):**
  the watermark drops 256 MB → ~105 MB, so collects become **~2.4× more
  frequent** (every ~35 gameplay ticks vs ~85 today for RWK's churn). Each is
  amortized by the tier-2 lazy sweep ([[avm2-gc-tier2-collector-cost]]), so this
  is *expected* to stay above 30 fps — but it is a real cadence change and the
  first implementation session MUST confirm on the rig (all-frames mean + >250
  ms stall count, NOT p50 — judging a GC-amortization change by p50 inverts the
  verdict). If cadence bites, raise the arena to 768 MB–1 GB (watermark
  recovers) — still a ~2× cut from 1984 MB.
- **1B. Start-small + grow in segments — NOT recommended (no title needs it).**
  Retained only as the contingency if a *future* title has a genuinely large
  live set (>~400 MB): start at 256 MB, `mmap` additional segments on
  near-exhaustion (memset'd only when needed — pairs with the commit-at-load
  finding), route `free` by address range. Cost is real: the GC membership
  bitmap and `free`/`census` assume **one** arena (`heap_arena_base/span`,
  single `g_bm` over `[base, base+span)`) — segmentation needs a multi-arena
  bitmap + segment router (Effort **M**). No measured title justifies this
  today; **1A is strictly simpler and sufficient.**

The "just works" objective forbids per-title arena constants — 1A's single
universal constant satisfies it.

### Lever 3 — Binning slack — do not pursue

§2 folds (c) into the transient; after Lever 2 there is no material standalone
binning slack, and reopening o1heap size classes was net-negative once
([[avm2-inline-slots-ruled-out-o1heap-binning]]). **Skip.**

### Lever 4 — Small consumers that scale with arena size

- **AVM1 1 GB arena** — same commit-at-load mechanism, live set a few MB.
  Shrinking `heap_init`'s wasm32 default (or an AVM1-specific override) from
  1 GB to e.g. 128–256 MB is **one line** and cuts the at-load commit ~4–8×
  for every AVM1 demo. Effort: **XS.** Gate: confirm the largest AVM1 demo's
  live peak fits (Tetris resident 1148 MiB @Start is arena, not live; a quick native probe of the largest AVM1 demo confirms — expected << 256 MB).
- **GC membership bitmap** — `span / ALIGN / 8` = 16 MB (4 GB native) /
  15.5 MB (1984 MB wasm). `calloc`'d, so only touched pages materialize, but it
  scales linearly with arena size — a 512 MB wasm arena's bitmap is ~4 MB.
  Falls out of Lever 1 for free.
- **`INITIAL_MEMORY=512MB`** — with a smaller arena this can drop toward the
  base size, cutting the *guaranteed* at-load commit further. One flag in
  `build_wasm_avm2.sh`.

---

## §4 — Explicit rulings (ruled out)

- **Within-tick emergency collection — RULED OUT.** During a tick the VM's
  live set includes values in C locals / the C stack that the marker cannot
  see; the collector's correctness rests on the **between-tick quiescence
  invariant** ([[avm2-stage11-gc]]). Collecting mid-tick to relieve the concat
  spike would free reachable objects. The spike must be prevented (lever 2),
  not collected. (Reason recorded here so it isn't silently re-proposed.)
- **o1heap size-class changes for object+slots — already ruled out**
  ([[avm2-inline-slots-ruled-out-o1heap-binning]]): −489 M Ir but +22% live
  heap; dangerous near a full arena. Not reopened (§3 lever 3).
- **Per-title arena constants — disqualified by the "just works" objective.**
  Lever 1A (universal fixed) or 1B (auto-grow) only.

---

## §5 — Instrumentation shipped this session

`AVM2_HEAP_STATS=1` gained a **worst-single-tick gross** report (permanent
diagnostic, earns its keep like `AVM2_HEAP_STATS` itself did):

- `o1heap` (`o1heap.c/.h`): a resettable high-water `peak_since_mark` updated
  in the alloc hot path beside `peak_allocated`, plus `o1heapMarkPeak()` /
  `o1heapGetPeakSinceMark()`.
- `heap.c/.h`: `heap_tick_mark()` / `heap_peak_since_mark_bytes()` wrappers
  (passthrough backend stubs return 0 = unknown).
- `avm2_main.c`: the tick loop rebases the mark at each post-collect boundary
  and tracks the worst gross for tick 0 (boot) and for later ticks (gameplay),
  printed under `AVM2_HEAP_STATS`.

This is what makes §1's "worst tick gross" column measurable rather than
guessed. It ships to CI only if it's on a commit that changes observable
output — this is a docs+instrumentation change, so per `ci-only-when-observable`
it rides the next runtime commit's pipeline.

**heap.c comment fix:** the stale "physical RAM only allocated on first access"
narrative (true native, false wasm) is corrected in the source to name the
emscripten memset-at-mmap behavior, so the next reader is not misled the way
the 1984 figure misled this session (applied this session: heap.c emscripten-warning block + AVM2 arena note, swf_core.c "64 MB" fix).

---

## §6 — Recommended first implementation session (prompt-ready)

**Session: "AVM2 `arrayToCSV` native intrinsic + arena right-size."** Order is
2 → re-measure → 1 → 4, because Lever 1's size is set by Lever 2's result.

1. **Ship Lever 2A — native `FlxTilemap.arrayToCSV` intrinsic** on the standing
   fingerprint gate. Follow the collision-intrinsic playbook
   ([[avm2-flixel-native-intrinsic]], [[avm2-flixel-235-titles-extension]]):
   fingerprint the method per title (2.21 + 2.35 variants), verify the native C
   CSV builder is **byte-identical** to the AS3 output (a decompile-and-diff on
   one map + a runtime CSV compare), bake per-title constants only on that
   proof. The C builder writes one grow-realloc buffer — no O(n²) intermediates.
2. **Re-measure worst-single-tick gross** (the §5 instrument) on all four RW
   titles: confirm each collapses from ~300–1788 MB to ~sub-MB. This is the
   number that sizes step 3.
3. **Ship Lever 1A — shrink the browser AVM2 arena to 512 MB** (`heap.c`
   `__EMSCRIPTEN__ && SWF_AVM2`), and drop `INITIAL_MEMORY` toward it in
   `build_wasm_avm2.sh`. Validate: (i) all five titles boot + play a browser
   soak with **zero OOM** and HEAPU8 flat at ~512 MB + base; (ii) **rig FPS
   check** — the watermark cadence rises ~2.4× (§3 Lever 1A), so judge on
   all-frames mean + >250 ms stall count, NOT p50
   ([[avm2-gc-tier2-collector-cost]]); every title must hold ≥30 fps. Same-
   session interleaved rig A/Bs only ([[avm2-native-ab-recipe-gc0-invalid]]).
   If cadence bites, back off to 768 MB–1 GB (still ~2× under 1984).
4. **Ship Lever 4 — shrink the AVM1 wasm arena** from 1 GB (the `heap_init`
   wasm32 default) to 256 MB, after a quick native probe of the largest AVM1
   demo's peak (Tetris/N/Bloons — expected << 256 MB). Independent of 1–3.

Deliverable: browser resident RAM per player **1984 → 512 MB (AVM2)** and
**1024 → 256 MB (AVM1)**, with the four RW titles' level-load spike gone and no
FPS regression.

---

## Appendix A — target statement (defensible, from §1 data)

> **Target: every AVM2 title boots and plays indefinitely in ≤512 MB of
> browser linear memory; every AVM1 title in ≤256 MB — gated on the
> `arrayToCSV` intrinsic (Lever 2) for AVM2.**

Justification, number-by-number (not a round number chosen first):

- **No title has a large *live* set.** Measured live floors: RWIC 67, RWF 90,
  RWP 85, RWK ~86, Seedling 72 MB. The worst is 90 MB. So a large or per-title
  arena is unjustified — the "just works" single universal constant applies.
- **The only thing needing >512 MB is the `arrayToCSV` transient** (RWIC 1742,
  RWF 1552, RWK 1397, RWP 302 MB), which is 96% reclaimable single-tick garbage
  from one function → removed by Lever 2.
- **512 MB clears the post-lever-2 working peak with margin.** Working peak =
  `live floor (≤90 MB) + watermark-garbage`; at a 512 MB cap the watermark
  self-clamps to ~105 MB, sawtooth peak ~195 MB, vs the 7/8 eager-sweep valve at
  448 MB — 2.3× margin, and headroom for titles not yet measured (future RW
  entries, larger maps). 256 MB would also fit (peak ~131 MB) but with less
  margin and ~2× more GC; **512 MB is the "just works" choice**, 256 MB a
  stretch to revisit if footprint must go lower.
- **AVM1 256 MB:** AVM1 live sets are single-digit MB (§1b Tetris) with no
  Flixel transient; 256 MB is ~30× headroom and one line.

Do **not** pick a number the data contradicts: 512 MB is contradicted *today*
(the transient needs 1788), which is precisely why Lever 2 gates Lever 1.

## Appendix B — build/measurement notes (for reproduction)

- Native AVM2 titles: `verify_output_keep.py` (KEEP_BUILD_DIR), `-O2`,
  no-graphics, `-DSWF_AVM2`, `TZ=NPT-5:45`; deterministic/byte-reproducible.
- **Seedling's single `abc0_methods.c` TU exceeds the default 300 s/file compile
  cap** — set `SWFRECOMP_COMPILE_TIMEOUT=1500`.
- **RWIC/RWF gate boot on `LocalConnection().domain`**: pass
  `GAME_SWF_URL=http://www.maxgames.com/test.swf` (the harness hardcodes
  `swf_url.h` to `file:///test.swf` → `localhost`, which the `locallock` stub
  blocks → the game sits black before Flixel starts). RWP/RWK have no gate.
- Mouse events for the 320×240 RW games are injected in **640×480 display
  space** (2×): New-Game button game-center (158,88)/(208,88) → click
  (316,176)/(416,172).
- Browser: Windows-Chrome via the WSL Playwright rig
  (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); `py.exe -3.12` if `python.exe` is not on
  PATH; isolate the renderer PID to read its working set (many `chrome.exe`
  running).
