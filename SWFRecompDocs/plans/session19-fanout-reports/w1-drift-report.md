# Session 19 · wave 1 · `w1-drift` — upstream drift audit + new-test pricing

**Agent:** `w1-drift` (main tree, read-only: no source edits, no commits).
**Base:** `254145a5b` on `master` (HEAD moved to `e36bca73e` mid-session; nothing below depends on
it). **Brief:** `session19-fanout-reports/w1-drift-brief.md`.
**Baselines read fresh** from `ruffle-tests/tests/swfs/*/_results/results_graphics.json`
(graphics run `34645805030` at `0ccafbc4e`) and from `~/CC/ruffle` at `0631814db`. The coordinator's
later baseline (results `627830f2a`, run `34648878013`, 4412 effective / 4518 intersection) differs
from mine by exactly the one drift row in §A5 — `avm2/bitmapdata_copypixels_alpha_merge`,
`ruffle_matched` → `output_mismatch` — which is the same −1 I priced independently below.
All local runs: `--mode=graphics --diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
strictly sequential. Logs/JSON: `<scratchpad>/w1-drift/runs/`.

---

## 0. VERDICTS — 8 priced effective flips (6 `pass`, 2 `ruffle_matched`), in 4 slices; 3 NO-GO/HOLD

| # | test | baseline | verdict | flip | file(s) | LOC |
|---|---|---|---|---|---|---|
| 1 | `avm2/bitmapdata_copypixels_blend` | 0/1029 (new) | **GO (proven)** | → **pass** | `avm2_bitmap.c` | ~6 (+~15 wasm SIMD) |
| 2 | `avm2/bitmapdata_copypixels_alpha_merge` | was `ruffle_matched`, **now `output_mismatch` 5/9 (upstream drift)** | **GO (proven)** | → **pass** (averts −1 *and* +1), 9/9 | same as #1, +2 lines | ~2 |
| 3 | `avm2/bitmapdata_copypixels_self` | 571/612 (new) | **GO** | → **pass** | `avm2_bitmap.c` | ~20 |
| 4 | `avm1/bitmapdata_copypixels_self` | 600/612 (new) | **GO** | → **pass** | `actionmodern/action.c` | ~20 |
| 5 | `avm2/displayobject_z` (trace) | 6/38 (new) | **GO** | → **pass** | `avm2_display.c` | ~30 |
| 6 | `avm2/geom_transform` (trace) | 71/74 | **GO** (same change as #5) | → **pass** | `avm2_display.c` | 0 extra |
| 7 | `from_avmplus/ecma3/JSON/adhoc` | 33/40, KF | **GO (cheap half)** | → **`ruffle_matched`** (+1); `pass` needs a 2nd mechanism | AVM2 JSON number path | small + medium |
| 8 | `avm1/bitmapdata_custom_rectangle` | 15/42, KF | **GO (medium confidence)** | → **`ruffle_matched`** (+1); `pass` needs `generateFilterRect` | `actionmodern/action.c` | ~25 + medium |
| P1 | `avm2/geom_transform` **pixels** | fail (8746 excess) | **NO-GO this wave** | 0 | renderer-wide | — |
| P2 | `avm2/displayobject_z` **pixels** | fail (264306 excess) | **NO-GO this wave** | 0 | renderer-wide | — |
| P3 | `avm2/bitmapdata_draw_cab_quality` **pixels** | fail (2320 excess) | **HOLD (medium)** | +1 pixel cmp | `avm2_bitmap.c` | ~80–150 |

**Headline: +6 pass, +2 `ruffle_matched`, −1 drift loss averted, across 3 runtime files,
~100 LOC, no new files, no recompiler change.** Trace-axis only; the pixel axis yields
nothing cheap here (P1/P2 both need a real perspective-projection pipeline).

Slice packaging (files disjoint):
* **Slice BD** (`avm2_bitmap.c` + `actionmodern/action.c`): #1 #2 #3 #4 → **+4 pass** (one of
  which also averts the drift −1).
* **Slice Z** (`avm2_display.c` only): #5 #6 → **+2 pass**.
* **Slice JSON** (#7) belongs with `w1-avm2`'s `avm2/json_parse_numbers` — same mechanism (§6).
* **Slice AVM1-RECT** (#8) is AVM1 built-in Rectangle resolution — `actionmodern/action.c`,
  textually near slice BD's AVM1 hunk; give both to one agent or separate them by function.

---

## 1. PART A — corpus vs upstream: the drift lists are EMPTY. Three refutations.

Method: enumerated tests with `verify_output.discover_tests` over both trees, then compared
every file byte-for-byte. Scripts and raw lists in `<scratchpad>/w1-drift/`.

**A1. Zero stale test dirs. Zero divergent graded files.**
* Discovered tests: **4430 local, 4430 upstream, identical sets** (no local-only, no upstream-only).
* Dirs containing `test.swf`: 4437 on both sides, identical.
* Of 22 893 files present on both sides, **0 differ in content**. The local tree is exactly
  upstream `0631814db` for everything that grades.
* The only local-only *directories* are build artifacts (`RecompiledABC/` etc.).
* s18's four stale dirs (`avm2/av_networking_params`, `av_tag_data`, `dictionary_primitive_keys`,
  `property_priority_scope_cache_order`) are **gone** — already cleaned up.

**A2. Zero orphan `output.ruffle.txt`.** s18 pruned 39; the fresh sync re-added none. Every local
`output.ruffle.txt` exists upstream with identical bytes.

> **Why A2 matters in both directions.** `ruffle_matched` is decided entirely by files upstream
> owns — the test's `output.ruffle.txt` plus `known_failure` in `test.toml` — compared as a
> *subset* rule. Upstream can therefore move one of our rows in either direction with **no change
> from us**: `0c6a734da` shrank Ruffle's diff set and cost us `avm2/bitmapdata_copypixels_alpha_merge`
> (§A5), while a *stale* local `output.ruffle.txt` that upstream has widened or deleted would hand
> us a `ruffle_matched` we no longer deserve (s18 found exactly one such live trap among its 39).
> A drift audit that only looks at `output.txt` is blind to half of this. Today: clean on both
> sides — every `output.ruffle.txt` we hold is byte-identical to upstream's.

**A3. Local-only files that are NOT test content** (harmless; listed for the record):
* Tracked, project-added, present in CI: `avm1/external_interface/{test.toml,test_harness.c}`,
  `avm1/{global_instance_decls,global_proto_decls,global_proto_decls_delete}/output.flash.txt`,
  `avm2/loader_loadbytes_url/test.local.toml`, and the six per-suite `ignored_tests.txt`.
  (`avm1/external_interface` has upstream `test.swf` + `output.txt` but **no upstream `test.toml`** —
  ours is a project addition. It grades, and it **passes** 84/84.)
* Untracked residue from old syncs: **23 `test.fla` + 2 `as_source.txt` + 1 `test.fla`-class file**
  under `avm1/*` and `avm2/{displayobject_rotation,json_stringify}`. Upstream no longer ships these
  particular ones. They are never read by the runner and never discovered — **zero effect on
  grading, in CI or locally**. Deleting them is optional housekeeping; I deleted nothing.

**A4. REFUTATION — every `DRIFT(n)` flag on the wave-0 trace inventory is a counting artifact.**
The inventory's `DRIFT(n)` compares a raw `wc -l`-style count (which counts trailing blank lines)
against the baseline's *normalized* `expected_lines` (`compare_output` strips leading/trailing
blanks). Checked all **4426 graded rows**: the fresh, normalized expected-line count equals the
baseline's for **every single one — zero real expected-line drift corpus-wide**.

| test | inventory DRIFT | raw `wc -l` | normalized (= baseline) |
|---|---|---|---|
| `avm2/geom_transform` | 75 | 75 | **74** |
| `avm2/displayobject_z` | 40 | 40 | **38** |
| `avm1/date` | 6336 | 6336 | **6335** |
| `avm1/bitmap_data_thorough/pixelDissolve` | 1374 | 1374 | **1371** |
| `avm2/audio_computespectrum` | 120 | 120 | **118** |

So my own brief's premises "`geom_transform`… fresh output.txt is 75 lines" and
"`displayobject_z`… fresh 40 lines" are **wrong**; both tests were already graded against their
current, post-`45be8d536` expectations. Any sibling brief that treats a `DRIFT(n)` flag as
upstream movement should ignore it.

**A5. What actually moved after CI's download.** The graphics run's Setup job downloaded the corpus
at **2026-09-11 20:45 UTC**. Upstream commits after that moment (2026-09-11 20:57 UTC, all by
kjarosh) are the *entire* drift surface:

| commit | effect on our corpus |
|---|---|
| `22739e86a` | **new test** `avm2/bitmapdata_copypixels_blend` (ungraded) |
| `8b96dace0` | **new test** `avm1/bitmapdata_copypixels_self` (ungraded) |
| `6c2c08188` | **new test** `avm2/bitmapdata_copypixels_self` (ungraded) |
| `0c6a734da` (core `blend_over`) | rewrote `avm2/bitmapdata_copypixels_alpha_merge/output.ruffle.txt` → **our `ruffle_matched` dies** (locally reproduced: `output_mismatch` 5/9; confirmed by the coordinator's run `34648878013` at 4412); also loosened `from_shumway/acid/acid-text-3` image tolerance 0→1 (already `pass`, stays `pass`) |
| `ea3956e89` (core self-copy) | rewrote `from_gnash/actionscript.all/BitmapData-v8/output.ruffle.txt` — **no risk**: locally re-run, still `ruffle_matched` (`diffs 8 ⊆ ruffle 8`) |

Net at the next CI, with no code change: **denominator +3, effective −1** (alpha_merge — already
realised in run `34648878013`, 4413 → 4412).
`f6b589799` (avm1/bitmap_data_copypixels expected PNG + tolerance, 19:28 UTC) landed *before* the
download and is already graded (`pass`, image `pass`).

**A6. One more ungraded row, and it is deliberate.** `from_gnash/misc-swfc.all/gotoFrameFromInterval`
is on disk but has no `_results` row: `.github/workflows/ruffle-tests.yml:880` passes
`--exclude=gotoFrameFromInterval` (known_failure runaway where Ruffle diverges too; it would burn
~30 s of CI per run). Not drift. Everything else on disk has a row, and **no row lacks a dir**.

---

## 2. Slice BD — BitmapData blend exactness + self-copy direction (#1 #2 #3 #4)

### 2a. `blend_over` has the wrong rounding, and the new test proves it arithmetically

Ruffle `0c6a734da` replaced `src + (dst*(255−sa))/255` with `src + ((dst*(256−sa))>>8)`
("verified against Flash Player across the full 0..255 alpha range"). The new test
`avm2/bitmapdata_copypixels_blend` **encodes that formula in ActionScript** and Flash reports
`--- mismatches / 0`:

```as3
private function blendChannel(dest:uint, src:uint, srcAlpha:uint):uint {
    return premultiply(src, srcAlpha) + ((dest * (256 - srcAlpha)) >> 8);
}
```

Ours (`SWFModernRuntime/src/avm2/avm2_bitmap.c:109-117`) is the old `/255` form; AVM1 carries two
more copies of it (`actionmodern/action.c:12863-12866` and `:12899-12902`).

**Proof it is sufficient, not just necessary.** I replayed the test's three curated tables through
our *actual* helpers (`premul()` = `(c*a+127)/255`, `unmul()` = our `FLASH_PREMUL_FACTOR` LUT
extracted verbatim from `avm2_bitmap.c`), swapping only the blend line:

| table | lines | old formula | new formula |
|---|---:|---:|---:|
| `--- blend` | 256 | 188 ✓ / 68 ✗ | **256 ✓ / 0 ✗** |
| `--- blend with an alpha source` | 256 | — | **256 ✓ / 0 ✗** |
| `--- alpha multiplier` | 512 | — | **512 ✓ / 0 ✗** |

That is 1024 of the test's 1029 lines exact, through our own premultiply/unmultiply path, with a
**six-line** change. Our LUT and premultiply already match Ruffle's byte-for-byte, and the test
carries **no `known_failure` and no `output.ruffle.txt`** — i.e. upstream Ruffle passes it — so
`pass` is the reachable target, not `ruffle_matched`.

The remaining 5 lines are the three sweep headers, the `--- mismatches` label and its `0`; the
sweeps go silent because `testColorChannels`/`testAlphaChannel` test exactly this formula.
(Our current run emits 20 `mismatch:` lines, which is why `matching_lines` is 0/1029 — pure offset.)

### 2a′. `avm2/bitmapdata_copypixels_alpha_merge` is reachable as an exact **pass**, not just `ruffle_matched`

(Answering the coordinator's question. The drift itself is established, not re-derived here:
ruffle `0c6a734da` at 2026-09-11T20:57Z shrank Ruffle's own diff set to {5,6}, our unchanged 9-line
output is no longer a subset, hence `ruffle_matched` → `output_mismatch`. Reproduced locally, 5/9.)

I modelled the test exactly — our `premul()`, our `FLASH_PREMUL_FACTOR` LUT, our `has_alpha` arm of
`bd_copy_pixels`, the test's own `new BitmapData(1,1,st,…)` construction — and swept the two
candidate changes (`<scratchpad>/w1-drift/sim_merge.py`). The model reproduces our *actual* run's
diff set exactly, which validates it:

| model | diff vs Flash (`output.txt`) | diff vs Ruffle (`output.ruffle.txt`) | grade |
|---|---|---|---|
| today's code | **{1,3,5,6}** ( = our real run, 5/9 ✓) | {1,3,5} | `output_mismatch` |
| + new `blend_over` only | {5,6} | **{}** | `ruffle_matched` |
| + new `blend_over` **and** the alpha rule below | **{}** | {5,6} | **`pass` (9/9)** |

The second change is two lines. Lines 5–6 are the `st=false` block (a **non-transparent** source),
where `bd_copy_pixels` takes the `else` arm at `avm2_bitmap.c:1372-1375`:

```c
if (src->transparency) final_alpha = (a == 255) ? CA(sc) : ((a * CA(sc)) >> 8);
else                   final_alpha = a;        // <-- wrong for a < 255
```

Flash applies the same `>> 8` scaling with `srcA = 255`: for alpha-pixel `a = 254` Flash's result
carries alpha `0xfd` (253 = `(254*255)>>8`), not `0xfe`; for `a = 128` it is 127, which then blends
to `0x9f` over the `0x40` destination — the exact expected byte. Making the `else` arm use the same
expression (`(a == 255) ? 255 : ((a * 255) >> 8)`) reproduces all five values of lines 5 and 6,
including the `a = 1` case (`final_alpha` 0 → the destination survives untouched as `40342410`).
The comment above that branch claims the two paths agree; Flash's own output refutes it.

Note this makes us **beat Ruffle** on a `known_failure` test — legitimate and worth +1 (a KF flag
says *Ruffle* fails, and `output.txt` is Flash's). It also means the same two lines will keep
`ruffle_matched` alive if only the blend half of slice BD lands.

**Wasm note:** `blend_over_span_simd` (`avm2_bitmap.c:309`) hand-rolls the `/255` as a
`*32897 >> 23` magic multiply. The new formula is *simpler* in SIMD (`(x*(256−sa)) >> 8`), but the
kernel must be rewritten in the same patch or native and wasm will disagree.

### 2b. Self-copy overwrite order (#3 #4)

`copyPixels` with `source === dest` and overlapping rects: Flash iterates in the direction that
avoids clobbering unread pixels — but only when the two axes agree. Ruffle `ea3956e89`:

```rust
let dx = dest.x_min - source.x_min;  let dy = dest.y_min - source.y_min;
let reverse = dy >= 0 && dx >= 0;   // otherwise FP really does read overwritten data
```

Ours keeps `same_buf` on the legacy *forward* per-pixel loop (`avm2_bitmap.c:1345-1400`, with an
explicit comment that the span kernels are skipped for self-copies) — i.e. exactly the pre-fix
Ruffle behaviour, which is why both new tests fail on precisely the overlapping-rect rows
(avm2 41 lines, avm1 12 lines). The fix is to pick the iteration order from `dx`/`dy` in that loop
(and in AVM1's `bitmapDataCopyPixels`). The blend arm must stay per-pixel; the no-blend arm may
use `memmove` per row.

Both new self tests are `known_failure`-free with no `output.ruffle.txt` → target is **pass**.

### 2c. Canaries for slice BD (all currently `pass`, several with image comparisons)

`avm1/bitmap_data_copypixels`, `avm2/bitmapdata_copypixels`, `avm2/bitmapdata_copypixels_alpha_combine`,
`avm2/bitmapdata_draw`, `avm2/bitmapdata_draw_self_via_graphic` (its comment at
`avm2_bitmap.c:2196-2205` documents a *deliberate* one-LSB truncation tie to the old formula —
**read it before touching `blend_over`**), `avm2/bitmapdata_applyfilter_*`,
`from_gnash/actionscript.all/BitmapData-v5..v8`, `from_shumway/acid/acid-bitmapData-copyPixels`,
`from_shumway/bitmapdata/*`, plus the `regression/` suite.

---

## 3. Slice Z — `DisplayObject.z` (#5 #6). One mechanism, both tests, `avm2_display.c` only

Ruffle `45be8d536` + `core/src/display_object.rs:275`: `z` is a **separate `f64 tz` on the display
object base**, not part of the 2D matrix. Four wiring points:

1. `get z` → `tz` (we return `do_get_zero`, registered at `avm2_display.c:16629`).
2. `set z` → store `tz` **and** `set_has_matrix3d_stub(true)` — this is why the expected output
   flips `transform.matrix` to `null` and `transform.matrix3D` to a live Matrix3D right after
   `sprite.z = 0`.
3. `Transform.matrix3D` getter: `Matrix3D::from_matrix(matrix)` then `set_tz(z as f32)` —
   our `m3d_from_ext` (`:11284`) hardcodes `raw[14] = 0`.
4. `Transform.matrix3D` setter: `set_z(matrix3d.tz())`, and the null arm sets `z = 0` —
   our `m3d_to_ext` (`:11303`) drops `raw[14]`.

Our `displayobject_z` run dies at expected line 9 with `#1009 … (accessing field: rawData)`
because step 2 never sets the stub bit; `geom_transform`'s 3 diff lines are all
`sprite3D.transform.matrix3D.rawData … ,6,7,**0**,1` vs Flash's `,6,7,**8**,1` — step 3/4 only.

**No struct change needed.** The file already stores per-display-object scalars as `dont_enum`
dynamic properties (`M3D_STUB_KEY` at `:11262`, the four `__pp*` perspective slots at `:11812`);
a `__mtz` slot follows the same idiom, keeping the patch inside `avm2_display.c` and out of
`avm2_globals.h` (which siblings edit). `1000000000` and `-1000000000` round-trip exactly in f32,
so the expected `rawData` needs no special casing.

Canaries: `avm2/geom_transform`, `matrix3d*` (22 tests), `perspective_projection_basic`,
`displayobject_getrect`, `displayobject_getbounds*`, `stage3d_*`, `from_shumway/*/matrix3d/*`.
Watch for objects that set `z` and then read `transform.matrix` — that now returns `null`.

**P1/P2 — the pixel halves are NO-GO this wave.** Ruffle renders `z` for real:
`render/src/transform.rs` carries `tz` down the transform stack, `render/wgpu/src/globals.rs`
builds `projection × view` from `PerspectiveProjection::default()` (fov 55°, focal length
`(w/2)·tan((π−fov)/2) ≈ 480.25` at 500 px), and each draw's world matrix gets `tz` in row 3.
`displayobject_z` deliberately probes the near-plane cull (`b1.z = -490` invisible, `-450` visible)
and a 100-deep vanishing-point stack. Our render path has no `tz` and no projection matrix at all
(`perspectiveProjection` exists only as an AS-visible value object). Even after slice Z,
`displayobject_z`'s image goes from "flat white" to "8 unscaled bitmaps stacked", and
`geom_transform`'s 8746 excess outliers are exactly the missing `focal/(focal+z)` shrink of its
`tz = 8` sprite. Completion mechanism if someone wants it later: a per-object
`scale-about-projection-centre` factor `focal/(focal+tz)` applied in the render walk plus a
near-plane reject at `focal + tz <= 0` — a graphics-agent slice, not a drift-agent one, and it
should be priced against the whole `[image_comparisons]` tolerance table (`checks` with
`max_outliers` 6500/17500), not against pixel identity.

---

## 4. #7 `from_avmplus/ecma3/JSON/adhoc` — reachable target is `ruffle_matched` cheaply, `pass` with a 2nd fix

Our 7 diffs split cleanly:

| lines | ours | Ruffle | mechanism |
|---|---|---|---|
| 2, 6, 20, 24 | `FAILED! expected: -1750000000000 got: -1948310528` (and `-1e+12 → 727379968`) | **PASSES** | our JSON number path truncates to int32 |
| 16, 17, 18 | `FAILED!` | **also FAILED** (same three lines, same text) | reviver returning `undefined`: array hole vs `undefined` |

`-1948310528` and `727379968` are `-1.75e12` and `-1e12` wrapped to 32 bits, in **both**
`JSON.parse` and `JSON.stringify` — one storage/coercion site, not two behaviours.
Fixing only that leaves our diff set == Ruffle's {16,17,18} → **`ruffle_matched` (+1)**, which is
legitimate here (the test *is* `known_failure`; Ruffle really does fail those three).
Full `pass` additionally needs Flash's reviver semantics, which are asymmetric and worth a
separate look: line 16 wants `[1,undefined,3]` where Ruffle yields a hole, line 17 wants
`["1",,3]` (a hole) where Ruffle yields `undefined`.

**Sibling hand-off:** `w1-avm2` owns `avm2/json_parse_numbers` (31/131, KF, RTXT) and
`avm2/json_parse_errors` (4/84); upstream `af88e41a5` ("avm2: Improve number parsing in JSON")
is the commit behind both. The int32 truncation above is almost certainly the same site. Whoever
takes it should price both tests together — my +1 here may already be inside their estimate
(**do not double-count**).

---

## 5. #8 `avm1/bitmapdata_custom_rectangle` — two mechanisms, only one of them cheap

Upstream `2748d21b3` / `017ee8c9a` / `56e4fb9d3` / `3ee9acff9` / `ad7b6c124` (2026-09-05..09-10)
make AVM1 built-ins resolve `flash.geom.{Rectangle,Matrix,Point,ColorTransform}` **dynamically**,
so a user who overwrites `flash.geom.Rectangle` sees their own constructor called (with its traces,
and with its exceptions propagating out of the built-in).

We already do this for `BitmapData.rectangle` (expected line 14 `rectangle: [object Object]`
matches), but **not** for `getColorBoundsRect` (we emit a native `(x=0, y=0, w=3, h=3)` where Flash
runs the user's function) and we bail out early after the "throwing function" section — our output
is 30 lines vs 42. Fix: route those built-in Rectangle constructions through the same dynamic
lookup. ~25 LOC in `actionmodern/action.c`.

`generateFilterRect` is a **second, unimplemented method** (we return `undefined`; so does Ruffle,
on all four of its own diff lines). With only the dynamic-Rectangle fix our diff set should collapse
onto Ruffle's → **`ruffle_matched` (+1)**; a full `pass` (42/42) needs `generateFilterRect` to
return the filter-grown rect (Flash returns `(x=0,y=0,w=3,h=3)` for a default `BevelFilter` on a
3×3 — cheap to hard-price only after someone checks the filter-growth rule). Confidence on the
`ruffle_matched` flip: **medium** — it depends on our line *shape* matching Ruffle's, not just the
line contents.

---

## 6. #P3 `avm2/bitmapdata_draw_cab_quality` — HOLD, and the root cause is a one-liner plus real work

Trace already `pass` (no trace output); the image is 100 % of the verdict. Expected shows a blue
triangle in the lower-right band; we render flat black there. Root cause is not subtle:

```c
avm2_builtin_add_method(ctx, bd, "drawWithQuality", bd_noop);   // avm2_bitmap.c:3757
```

`drawWithQuality` is a **no-op stub**, so the whole `bd.drawWithQuality(sprite, …)` call draws
nothing. Re-pointing it at `bd_draw` is one line, but that alone will draw the *whole* triangle:
`bd_draw` ignores the `clipRect` argument entirely (`avm2_bitmap.c:2718`: "clip_rect not supported
yet"), and the test's clipRect `(0,10,40,10)` is what selects the lower half. `blendMode
"difference"` and the `ColorTransform(0,1,1)` are already supported, and `drawTriangles` geometry
exists (`avm2_display.c:9805`), so the missing pieces are: (a) the registration, (b) clipRect in
`bd_draw`'s shape-raster path, (c) confirming a `cacheAsBitmap` Sprite source rasterizes.
Estimated ~80–150 LOC, pixel-only payoff (+1 comparison), so it belongs to a graphics agent
(`w1-gfx-geometry` already owns the BitmapData/draw image family) rather than to a drift slice.

---

## 7. Refutations and traps (read these before pricing anything nearby)

1. **All `DRIFT(n)` flags on the wave-0 board are noise** (§A4). Nothing in the corpus has a changed
   expected-line count. Do not re-derive "upstream moved" from that column.
2. **`from_gnash/actionscript.all/BitmapData-v8` is NOT a drift casualty.** Its `output.ruffle.txt`
   did change under our feet, but `ruffle_subset_match` is a *subset* test and we re-run
   `ruffle_matched` (`diffs 8 ⊆ ruffle 8`). Only `avm2/bitmapdata_copypixels_alpha_merge` actually
   breaks — verified by running both.
3. **The three "new" tests are real and will grade next CI** (they are upstream, and CI downloads
   fresh). The s18 lesson (four "new" dirs that were stale local residue) does **not** repeat:
   local and upstream test sets are now byte-identical.
4. **A KF test's `pass` and its `ruffle_matched` are different targets.** `JSON/adhoc` and
   `bitmapdata_custom_rectangle` are `known_failure`: fixing toward `output.txt` is right, and
   landing on `ruffle_matched` is a legitimate +1 — but for the three *new* copypixels tests there
   is no `output.ruffle.txt` at all, so anything short of `pass` is a miss.
5. **Diff-line counts mislead here.** `bitmapdata_copypixels_blend` reads as 0/1029 but is one
   formula away from 1029/1029; `bitmapdata_custom_rectangle` reads as 15/42 but is two mechanisms
   deep. `geom_transform` reads as 71/74 on trace yet its *pixel* half needs an entire projection
   pipeline — the two axes of one test are priced in different orders of magnitude.
6. **`blend_over` is shared, and one existing comment ties a passing test to the OLD rounding**
   (`avm2_bitmap.c:2196-2205`, `avm2/bitmapdata_draw_self_via_graphic`). That comment describes the
   GPU-vs-CPU tie, not the `/255` rounding itself, but whoever lands slice BD must re-read it and
   re-run that test.

---

## 8. Test evidence (all local, `--mode=graphics`, sequential)

| test | status | lines | note |
|---|---|---|---|
| `avm2/geom_transform` | `output_mismatch` | 71/74 | image fail 12746 outliers — **byte-identical to CI** |
| `avm2/displayobject_z` | `output_mismatch` | 6/38 | dies at `#1009 … rawData`; image flat white |
| `avm1/bitmapdata_copypixels_self` | `output_mismatch` | 600/612 | new test, first grading |
| `avm2/bitmapdata_copypixels_self` | `output_mismatch` | 571/612 | new test, first grading |
| `avm2/bitmapdata_copypixels_blend` | `output_mismatch` | 0/1029 (actual 1049) | 20 `mismatch:` lines shift everything |
| `avm2/bitmapdata_copypixels_alpha_merge` | `output_mismatch` | 5/9 | **was `ruffle_matched` in CI** — drift reproduced; diff set {1,3,5,6} matches the model in §2a′ |
| `from_gnash/actionscript.all/BitmapData-v8` | `ruffle_matched` | 409/417 | drift survived, `diffs 8 ⊆ ruffle 8` |
| `avm1/bitmapdata_custom_rectangle` | `output_mismatch` | 15/42 | actual 30 lines |
| `from_avmplus/ecma3/JSON/adhoc` | `output_mismatch` | 33/40 | 4 ours-only + 3 shared-with-Ruffle |
| `avm2/bitmapdata_draw_cab_quality` | `pass` (trace) | — | image fail 2400/80 outliers |

---

## 9. New unclaimed leads

* **`from_gnash/misc-swfc.all/gotoFrameFromInterval` is excluded from CI by hand**
  (`ruffle-tests.yml:880`). The rationale (both we and Ruffle run away; 30 s of CI) predates a lot
  of timeline work. Someone should re-test it locally once: if it now terminates, un-excluding it
  is +1 denominator and possibly +1 effective. Nobody owns it.
* **26 untracked stale files** (`test.fla`, `as_source.txt`) under `ruffle-tests/tests/swfs/avm1`
  and `avm2` no longer exist upstream. Harmless, but a `download_tests.sh --prune-untracked` mode
  (never `--clean`, which wipes `_investigation/`) would stop the drift-audit noise. Not mine.
* **`avm1/external_interface` has a project-authored `test.toml` + `test_harness.c`** with no
  upstream counterpart. It passes 84/84, but nothing documents it; if upstream ever adds its own
  `test.toml` they will collide silently.
* **The AVM1 `blend_over` duplicates** (`action.c:12863`, `:12899`) and the AVM2 one will drift
  apart again unless slice BD lands them together. Worth one shared helper.
* **`avm2/textblock_recreateline`** (41/181, KF, RTXT) had its `output.ruffle.txt` touched by
  `45be8d536` *before* the CI download, so it is graded — but it sits in the same z/Matrix3D blast
  radius as slice Z and nobody on this fan-out owns it.
