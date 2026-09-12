# Session 19 · wave 2 · `w2-bitmapdata` — slice BD (copyPixels blend / self / alpha) + copy-rect rider

**Agent:** `w2-bitmapdata`, worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a628121837cd13cef`
(branch `worktree-agent-af491cbcaed487092`, base `e36bca73e`). **No commits, no pushes.**
**Brief:** `w2-bitmapdata-brief.md`. **Diagnosis of record:** `w1-drift-report.md` §2 (slice BD)
and, for the rider, `w1-gfx-geometry-report.md` §2.2 (routed to me by the coordinator mid-task
because it lands in `bd_copy_pixels`, the same function).

## Deliverables (two patches, meant as two commits)

| file | contents | files touched |
|---|---|---|
| `w2-bitmapdata.patch` | **slice BD** — `blend_over` formula (scalar + wasm SIMD), self-copy direction rule, alpha rule; plus 4 new render-canary members | `SWFModernRuntime/src/avm2/avm2_bitmap.c`, `SWFModernRuntime/src/actionmodern/action.c`, `ruffle-tests/render_canary_tests.txt` |
| `w2-bitmapdata-4-copyrect.patch` | **copy-rect rider** — `bd_copy_pixels` / `bd_threshold` stop pre-clamping the source rect | `SWFModernRuntime/src/avm2/avm2_bitmap.c` |

**No new files.** Nothing added to `verify_output.py`'s source list, CMakeLists or the Emscripten
build. `render_canary_tests.txt` is a data file, not a TU.

`action.c` functions touched (for the sibling overlap check the brief asked for): **exactly one**,
`bitmapDataCopyPixels` (around line 12747). No other function in that file is modified, so there is
no textual overlap with `w2-avm2-json`.

---

## 0. VERDICTS

### Slice BD — GO, all four priced flips land, zero regressions

| test | before (CI graphics baseline `627830f2a`) | after | verdict |
|---|---|---|---|
| `avm2/bitmapdata_copypixels_blend` | `output_mismatch` 0/1029 | **`pass`** | priced flip, landed |
| `avm2/bitmapdata_copypixels_self` | `output_mismatch` 571/612 | **`pass`** | priced flip, landed |
| `avm1/bitmapdata_copypixels_self` | `output_mismatch` 600/612 | **`pass`** | priced flip, landed |
| `avm2/bitmapdata_copypixels_alpha_merge` | `output_mismatch` 5/9 | **`pass`** 9/9 | priced flip, landed — also averts the −1 upstream drift |

**+4 effective** (and the fourth is +1 *and* a −1 averted, exactly as `w1-drift` priced it). Wave-1's
pricing survived intact on every row, magnitude included — unusual, and it is because §2a/§2a′ were
arithmetic proofs rather than estimates.

### Copy-rect rider — GO, trace-neutral, pixel payoff only

| test | before | after | verdict |
|---|---|---|---|
| `from_shumway/acid/acid-bitmapData-copyPixels` [image] | **fail**, 53 760 outliers, max diff 238 | **pass**, **0 outliers, max diff 0** | priced flip, landed (+1 image comparison) |
| same test, trace | `pass` | `pass` | unchanged |
| 69 AVM2-routed bitmap tests, trace | — | **0 additional moves, 0 regressions** | clean |
| 69 canary PNG comparisons | — | 1 DIFFERS, and it is this row | clean |

The two patches are **independently applicable on `e36bca73e`** (`git apply --check` passes for each
alone) and apply cleanly in sequence, so they can land as two commits in either order.

---

## 1. Slice BD mechanism (re-verified, not taken on trust)

### 1a. `blend_over` — `(256 − sa) >> 8`, not `(255 − sa) / 255`

Ruffle `0c6a734da` (`core/src/bitmap/bitmap_data.rs:164`) with the comment *"verified against Flash
Player output across the full 0..255 alpha range"*. Our `avm2_bitmap.c::blend_over` carried the old
`/255` form; `actionmodern/action.c::bitmapDataCopyPixels` carried two more copies of it.

I did **not** re-derive the 1024-row table replay — `w1-drift` §2a already did that and the test
itself is the proof: `avm2/bitmapdata_copypixels_blend` encodes the formula in ActionScript, asserts
`--- mismatches / 0` against Flash, and now **passes 1029/1029**. An arithmetic claim that a test
checks arithmetically does not need a second model.

**What I did add: an exhaustive check of the rewritten wasm SIMD kernel.** The old
`blend_over_span_simd` reproduced `/255` via the magic pair `(x*32897)>>23`; that is wrong for the
new formula and native/wasm would have silently disagreed. The new kernel does the subtract in
16-bit lanes (`256` does not fit a byte lane) and is a plain `u16` multiply + logical `>>8`, since
`255*256 = 65 280 < 65 536`. I emulated the exact lane ops (`i16x8_sub`, `i16x8_mul` with its
16-bit wrap, `u16x8_shr`, `i16x8_add`, `v128_and 0x00FF`, `u8x16_narrow_i16x8` saturation) in scalar
C and compared against `blend_over` for **all 16 777 216 `(src_alpha, dest_channel, src_channel)`
combinations: 0 mismatches** (`<scratchpad>/w2-bitmapdata/simdcheck.c`). The body is lane-independent,
so that is exhaustive, not a sample. This matters because CI never builds wasm and the standing
`-DAVM2_BLIT_VERIFY` guard only fires in a browser.

### 1b. Self-copy direction — `reverse = dx >= 0 && dy >= 0`

Ruffle `ea3956e89`, `core/src/bitmap/operations/copy_on_cpu.rs::copy_on_cpu_self`. Overlapping
regions inside one buffer must be walked backwards — **but only when both axis deltas agree in
sign**; when they disagree Flash Player genuinely reads pixels it already overwrote, and the new
tests pin those rows. So this is not "fix the clobbering", it is "reproduce Flash's clobbering
exactly where Flash clobbers".

* **AVM2** (`bd_copy_pixels`): the legacy per-pixel loop gained a `self_reverse` flag and reversed
  index mapping. Deltas are read off the *post-intersection* regions
  (`dst_region.x_min >= src_region.x_min`), which is the same comparison Ruffle makes.
* **AVM1** (`bitmapDataCopyPixels`): this path used to **snapshot** the source buffer whenever
  `src == dest`. A snapshot is "correct" and therefore wrong — it never clobbers, so it can never
  reproduce the mixed-sign rows. Replaced with the same direction rule; the snapshot is now taken
  only for the alpha-bitmap arm, which has no direction rule of its own. Deltas are taken
  pre-clamping (`dx - rx`, `dy - ry`); clamping shifts the source and destination minima together,
  so the difference is preserved.

**One refutation worth recording.** Ruffle's *no-blend* self path is not per-pixel at all — it
`copy_within`s whole rows (a memmove), and only the row direction comes from `reverse`. A per-pixel
loop is only equivalent to that if the x order never matters when the y order is wrong. It does hold:
when `dy != 0` the source row and destination row are distinct, so x order is unobservable; when
`dy == 0` the flag reduces to `dx >= 0`, which is exactly the memmove-correct direction. I walked all
nine sign combinations before writing the loop; both new `_self` tests then passed 612/612, which is
the empirical half of the same argument.

### 1c. The alpha rule (2 lines)

`bd_copy_pixels`' alpha-bitmap arm had:

```c
if (src->transparency) final_alpha = (a == 255) ? CA(sc) : ((a * CA(sc)) >> 8);
else                   final_alpha = a;                  /* <- wrong for a < 255 */
```

The `else` arm is what **Ruffle** does (`operations.rs:1198`), and it is what
`avm2/bitmapdata_copypixels_alpha_merge` rows 5–6 catch it on. Flash runs the same `>> 8` scale with
the source alpha pinned at 255: alpha-pixel 254 yields 253 (`0xfd`), not 254; alpha-pixel 1 yields 0,
so the destination survives untouched as `40342410`. Flash's own `output.txt` rows for `st=false` are
byte-identical to the `st=true, s=255` rows, which is only true under the pinned-255 reading.

Since a non-transparent BitmapData stores alpha 255 in every pixel, the two arms collapse to one
expression over `sa_eff = src->transparency ? CA(sc) : 255`.

**This makes us beat Ruffle on a `known_failure` test** — legitimate per BRIEFS_COMMON rule 3
(`known_failure` says *Ruffle* fails; `output.txt` is Flash's). The test moved
`output_mismatch → pass`, not `→ ruffle_matched`, so it is not the rule-3 trap.

---

## 2. Slice BD verification sweep — 149 tests, 4 moves, all intended

Every run: worktree tree, `SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential, `--recompile` (first use of
each copied dir), `--verbose`. Verdicts parsed from the run logs
(`<scratchpad>/w2-bitmapdata/sweep_after.out`) and diffed against the **main tree's**
`_results/results_graphics.json` — the CI graphics baseline — by
`<scratchpad>/w2-bitmapdata/cmp2.py`.

| suite | tests | unchanged | moved |
|---|---:|---:|---:|
| `avm1` (every `*bitmap*`, incl. all 20 `bitmap_data_thorough/*`) | 46 | 45 | 1 (`bitmapdata_copypixels_self` → `pass`) |
| `avm2` (every `*bitmap*`) | 63 | 60 | 3 (the three AVM2 headline flips) |
| `from_gnash` (`BitmapData-v5..v8`, `BitmapDataDraw`) | 5 | 5 | 0 |
| `from_shumway` (acid bitmap/bitmapData + `bitmapdata/*` + `avm1/bitmapdata/*`) | 14 | 14 | 0 |
| `regression` (bitmap-adjacent members) | 9 | 9 | 0 |
| `visual` (canary members + `bitmapdata_copypixels_with_alpha_oob`) | 12 | 12 | 0 |
| **total** | **149** | **145** | **4** |

**Zero regressions.** Named rows the brief asked about specifically:

* **Filter / draw compositing through the same `blend_over`** — `avm2/bitmapdata_applyfilter_{blur,
  colormatrix,destpoint,destpoint_edges,identity}`, `avm2/bitmapdata_draw{,_alpha_erase,_cab_quality,
  _colortransform,_cpu_overwrite_gpu,_filters,_masks,_rotation,_self_via_graphic,_stage}`,
  `avm2/bitmapdata_drawwithquality`, `avm1/bitmapdata_applyfilter_colormatrix`,
  `avm1/bitmap_data_draw_cliprect`: **all `pass`, all unchanged.**
* **`avm2/bitmapdata_draw_self_via_graphic`** — the test whose comment at `avm2_bitmap.c:2197`
  documents a deliberate one-LSB tie. It still `pass`es. The comment's premise was about
  `blend_over_round` (which emulates the wgpu f32 path and I did **not** touch); its cross-reference
  to `blend_over`'s truncation is now stale in wording but the tie it describes is unaffected — the
  two functions were already separate, and the test proves it both on trace and, in §4, on pixels.
* **`regression/bitmap_pool_layer_cap`** and the other three `regression/` bitmap members: `pass`,
  unchanged.
* The three tests that were already failing before and still are — `avm1/bitmap_data_thorough/
  pixelDissolve`, `avm1/bitmapdata_custom_rectangle`, `avm2/bitmap_filter_abstract`,
  `from_shumway/bitmapdata/getpixel-from-embedded` — are unchanged at their baseline statuses.
  Three `ruffle_matched` rows (`bitmap_data_thorough/{copyPixels,paletteMap,perlinNoise}`) and two
  from_gnash `ruffle_matched` rows also held.

---

## 3. Copy-rect rider (`w2-bitmapdata-4-copyrect.patch`)

`bd_copy_pixels` and `bd_threshold` both did:

```c
PixelRegion src_region = pr_for_region_i32(sx, sy, sw, sh);
pr_clamp(&src_region, src->width, src->height);          /* loses the off-bitmap part */
pr_clamp_intersection(&dst_region, dx, dy, src_region.x_min, src_region.y_min, size, …);
```

Ruffle (`operations.rs::copy_pixels`, `::threshold`) passes `PixelRegion::for_whole_size(source)`
plus the **raw** rect, so `Rectangle(-8,-8,16,16)` both clips to `(0,0,8,8)` *and* shifts the
destination point by `+8,+8`. Pre-clamping first anchors the intersection on the clamped origin and
throws that shift away. Fix is the sibling's 3 lines, applied to both functions.

**Interaction with slice BD — stated explicitly, as the coordinator asked.** The two changes sit in
the same function and they do touch: slice BD's `self_reverse` flag is computed from
`dst_region.x_min >= src_region.x_min`, and the rider changes what those minima are for an
off-bitmap rect. The rule survives, because it is a comparison of the two *post-intersection*
minima and the rider makes those minima **more** correct, not less — it is the same comparison
Ruffle makes at the same point in its own pipeline. Nothing else is shared: the rider changes
region geometry only and never touches a blend, an alpha or an iteration order.

**Ledger (trace), 69 AVM2-routed bitmap tests** — `avm2` (58), `from_shumway` (7), `regression` (4),
`visual` (0 after excluding canary-owned dirs); `avm1` and `from_gnash` are out of the blast radius
by construction (AVM1 BitmapData never enters `avm2_bitmap.c`). Result: **66 unchanged, 3 moved —
and the 3 are slice BD's own flips, already counted.** The rider adds **zero** trace moves and
**zero** trace regressions. Its payoff is the image row in §4.

`bd_pixel_dissolve` (`:1776`) and `bd_apply_filter` (`:3169`) share the same shape and are **not**
fixed here — out of the rider's stated scope, and their Ruffle counterparts need checking
individually. Left as a lead (§6).

---

## 4. Render canary — 69 comparisons, 2 DIFFERS, both intended

A blend-formula change is exactly the class the pixel axis sees, so the canary is the deliverable
here as much as the code. Two full captures on the *same* worktree, `--jobs 1 --timeout 5400
--recompile`, local Dawn (byte-deterministic, so the bar is md5 identity with no epsilon):

* `before` — clean tree at `e36bca73e` (both patches reverted with `git apply -R`).
* `after` — both patches applied.
* 37 tests / **69 PNGs** each.

### 4a. Canary coverage audit — the standing set could NOT see this change, so I extended it

The wave-2 rule says to audit the canary against your own change class. The standing set's bitmap
members are `avm1/bitmap_data_fillrect` (fillRect), `avm1/bitmapdata_applyfilter_colormatrix`
(applyFilter) and `from_shumway/acid/acid-bitmap-fill{,-2}` (render-side bitmap *style* fills).
**None of them reaches `blend_over`.** Four covering members added to
`ruffle-tests/render_canary_tests.txt` (all Tier 1 — image-PASSING in graphics run `34645805030`):

| member | reaches | tol |
|---|---|---|
| `from_shumway/acid/acid-bitmapData-copyPixels` | copyPixels blend arm | 0 |
| `visual/bitmapdata_copypixels_with_alpha_oob` | copyPixels alphaBitmapData arm (§1c) | 0 |
| `from_shumway/acid/acid-bitmapData-draw` | `BitmapData.draw` composite | 0 / 650 |
| `avm2/bitmapdata_draw_self_via_graphic` | draw self-blend, the 1-LSB GPU-vs-CPU tie | 0 |

Four further image-bearing bitmap rows were run as **ad-hoc extras** for this change only, from a
scratch list — deliberately *not* added to the standing file, since they duplicate coverage the four
new members already give: `avm1/bitmap_data_copypixels`, `avm2/bitmapdata_draw`,
`avm2/bitmapdata_draw_colortransform`, `avm2/bitmapdata_draw_alpha_erase`.

### 4b. Result

```
RENDER CANARY  before=before  after=after   37 tests / 69 comparisons
  IDENTICAL    67
  DIFFERS       2
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
```

| DIFFERS row | channel stats | status | owner | verdict |
|---|---|---|---|---|
| `avm1/bitmap_data_copypixels` [output] | 423 / 3 240 000 channels, mean **0.0001**, **max 1**, bbox (24,78)-(435,790) | image `pass → pass`, trace `pass → pass` | **slice BD** | **INTENDED.** This is the `/255 → (256−sa)>>8` one-LSB rounding change, seen through AVM1's `copyPixels`. 0.013 % of channels, none by more than one LSB. The test's tolerance is 2 and it stays `pass`. A result of *zero* here would have meant the AVM1 half of the patch was dead. |
| `from_shumway/acid/acid-bitmapData-copyPixels` [output] | 53 760 / 880 000 channels, mean 5.31, max 238, bbox (32,32)-(256,256) | image **`fail → pass`**, trace `pass → pass` | **copy-rect rider** | **INTENDED — this is the rider's flip.** Independently measured with the image instrument at three tree states (below). |

**Nothing else moved.** In particular the whole filter/draw family the brief flagged —
`avm1/bitmapdata_applyfilter_colormatrix`, `visual/filters/{glow_pass_scaling,drop_shadow,
color_matrix,displacement_map_through_applyFilter}`, `avm2/bitmapdata_draw{,_colortransform,
_alpha_erase}`, `from_shumway/acid/acid-bitmapData-draw` and
`avm2/bitmapdata_draw_self_via_graphic` (the 1-LSB-tie test) — is **byte-identical** across the two
legs, as are all 7 `visual/cache_as_bitmap/masks` comparisons, all 12 `avm1/focusrect_swf5`, all 7
`from_shumway/timeline/timeline_as2_5`, all 6 `visual/edittext/edittext_border_transform`, all 5
`from_shumway/acid/acid-blend-2` and the three `regression/` render members.

### 4c. Attribution of the flip (the coordinator asked for this explicitly)

`from_shumway/acid/acid-bitmapData-copyPixels` measured with `--mode=graphics --images` at three
tree states, one test each:

| tree | image result |
|---|---|
| clean `e36bca73e` | **FAIL** — 53 760 outliers, max difference 238 |
| **slice BD only** | **FAIL** — 53 760 outliers, max difference 238 (bit-for-bit unchanged) |
| **copy-rect only** | **PASS** — **0 outliers, max difference 0** (byte-exact) |

So the flip is **entirely** the copy-rect rider's: slice BD neither helps nor hurts it, and copy-rect
alone is sufficient. The ledgers do not need merging. (This also reproduces `w1-gfx-geometry`'s
53 760 → 0 exactly, on a different machine state.)

### 4d. A trap worth recording

The canary's per-test `[pass]` bracket during **capture** is the *trace* status — it renders PNGs but
runs no image comparison. Every one of the 37 rows printed `[pass]` on the `before` leg, including
`acid-bitmapData-copyPixels`, which was failing its image check by 53 760 outliers at that very
moment. The image verdict only appears in `compare` (and in a `--images` run). Read the compare
report or run with `--images`; never read a capture-phase bracket as an image verdict.

---

## 5. Risks

1. **The wasm SIMD kernel is unexercised by CI.** It is proven byte-exact offline (§1a) but no CI
   job builds wasm, so a typo class that the emulation shares with the source would survive. The
   in-tree `-DAVM2_BLIT_VERIFY` guard is the backstop and still works.
2. **Two CPU compositors now disagree with `blend_over` on purpose.**
   `avm2_cpu_raster.c::cpu_blend_over` and `avm2_display.c::avm2_cpu_blend_over` keep the `/255`
   form, and their comments still say "matches avm2_bitmap.c blend_over". I did **not** edit them:
   they emulate the *wgpu* composite (f32 + round), not Ruffle's CPU `blend_over`, so changing them
   would be a render-path change with no evidence behind it — and `avm2_display.c` is
   **`w2-loaders`' file**, so editing it would have been a textual collision. The stale comments are
   a documentation debt, not a behaviour bug; §6 records them.
3. **AVM1's alpha-bitmap arm still lacks the `a == 255` special case** (`action.c`, the
   `bdcp_alpha_path` block). That is a real divergence from both Ruffle and Flash, but it is outside
   slice BD's priced scope and `avm1/bitmap_data_thorough/copyPixels` is `ruffle_matched` today —
   changing it blind risks that row. §6.
4. **AVM1 clamps where Ruffle wraps.** The AVM1 blend keeps its `if (oa > 255) oa = 255` guards; AVM2
   and Ruffle wrap at `uint8`. For well-formed premultiplied pixels (`src_c <= sa`) the sum can never
   exceed 255, so the two agree on everything a `setPixel`/`fillRect` path can produce. I left the
   clamps rather than widen the diff.
5. **Local `_results/*.json` are dirty in the worktree.** Running with `--test` does not rewrite the
   tracked results files in a usable way (my first comparison script was fooled by exactly this —
   the rows it read were the git-tracked ones, not the run's), so the ledgers above are parsed from
   run logs. The patches are produced with explicit pathspecs and contain **no** `_results` churn.

---

## 6. New unclaimed leads

* **`bd_pixel_dissolve` (`avm2_bitmap.c:1776`) and `bd_apply_filter` (`:3169`)** carry the same
  pre-clamp shape the rider just fixed in `bd_copy_pixels`/`bd_threshold`. Ruffle's counterparts
  need reading one at a time — `bd_copy_channel` was already correct, so the shape is not
  automatically a bug. Nobody owns these.
* **AVM1 `copyPixels`' alpha-bitmap arm** (risk 3 above) — needs an oracle run before touching, and
  `avm1/bitmap_data_thorough/copyPixels` is the row at stake.
* **Stale cross-references** in `avm2_cpu_raster.c:109` and `avm2_display.c:17424` ("matches
  avm2_bitmap.c blend_over") and in `avm2_bitmap.c:2197`. Comment-only; deliberately not edited to
  avoid a collision with `w2-loaders`.
* **`avm1/bitmapdata_custom_rectangle`** — the brief's optional rider — was **not attempted**. The
  coordinator's copy-rect rider arrived mid-task and took its budget, and the brief gates the
  rectangle rider on BD being "done and verified", which consumed the rest. Its diagnosis in
  `w1-drift-report.md` §5 is untouched and still holds: after the blend work the test is still
  `output_mismatch` at 30 actual lines vs 42 expected, dying right after the "throwing function"
  section, and the two mechanisms (dynamic `flash.geom.Rectangle` resolution in
  `getColorBoundsRect`; `generateFilterRect`) are exactly as described. Its `+1 ruffle_matched` is
  still on the table for a follow-up.
