# Session 12 · wave-2 · `w2-singles`

Three diagnosed trace leads from `wave1-trace-singles.md`. **Two shipped and
verified locally (+2 effective pass); the third is REFUTED and reverted** — its
wave-1 premise ("the recompiler emission is complete") does not hold for AVM2
SWFs, and the fix is not reachable from the runtime.

| # | Lead | Predicted | Shipped | Local result |
|---|---|---|---|---|
| 1 | `avm2/edittext_device_transform_layout` | +1 → `ruffle_matched` | **YES** | `output_mismatch` → **`ruffle_matched`** ✅ |
| 2 | number→string tie-break (`avm2/perspective_projection`) | +1 → `pass` | **YES** | `output_mismatch` → **`pass`** ✅ |
| 3 | B6 morph hit-test (`from_shumway/acid/acid-morph`) | +1 → `pass` | **NO — reverted** | got 1 of 2 wrong lines; line 4 unreachable without a recompiler change |

Net predicted CI delta: **+2 unfiltered `effective_pass`, 0 regressions.**
Patch: `SWFRecompDocs/plans/session12-fanout-reports/w2-singles.patch`
(2 files, +111/−4). Baseline compared against
`ruffle-tests/tests/swfs/*/_results/results_graphics.json` @ `6de650432`.

---

## Fix 1 — `getCharBoundaries` misses the field's bounds origin

`SWFModernRuntime/src/avm2/avm2_text.c:8142-8151` (`txt_get_char_boundaries`).
Exactly the wave-1 proposal, no scope creep:

```c
x_min += et->bounds_x + GUTTER;
x_max += et->bounds_x + GUTTER;
y_min += et->bounds_y + GUTTER - vscroll_off;
y_max += et->bounds_y + GUTTER - vscroll_off;
```

Ruffle `edit_text.rs:774-790` (`layout_to_local_matrix`) translates by
`bounds.x_min/y_min + GUTTER`; we translated by `GUTTER` alone. All 32 changed
lines of the target were exactly `+ bounds.x_min`.

**Invariants honoured** (all three from wave 1):

1. `et->bounds_x` is read **RAW** — no `avm2_text_self_bounds()`, no
   `et_apply_lazy_bounds()`. Ruffle's `char_bounds` (`edit_text.rs:2413`) reads
   `self.0.bounds.get()` and never applies pending autosize bounds. A 6-line
   comment at the site records why, so a future reader does not "tidy" it into
   the accessor.
2. hscroll untouched (net-zero per `edit_text.rs:2428-2431`).
3. `getLineMetrics` (`:8076`) **deliberately not shipped** — it buys no measured
   line and would put `from_shumway/flash_text_TextField` at risk. Left for a
   future session; the mechanism is identical.

## Fix 2 — Rust-vs-glibc shortest-repr tie-break

`SWFModernRuntime/src/avm2/avm2_value.c:495-588`, one new static function
`tie_round_away_from_zero()` called from `shortest_digits()` at `:618`.

glibc's `printf` resolves an exact decimal midpoint **to-even**; Rust's
`f64: Display` (which Ruffle prints through) resolves it **away from zero**.
`966.67828369140625` → glibc `966.6782836914062`, Rust `966.6782836914063`.

Three-stage detector, cheapest first — **the only change to the existing hot
path is one `prec >= 13 && n == prec + 1` test**:

* **Stage 0 (new, not in the wave-1 plan) — pure arithmetic, no formatting.**
  A tie needs `d`'s exact decimal expansion to terminate at `prec+2`
  significant digits. Writing `d = m·2^p` with `m` odd, that expansion is
  `m·5^-p` (p<0) or `m·2^p` (p≥0), so its digit count is one `frexp` + one
  `log10`. Rejects with a 1-digit slack. **Measured: kills 88.8 % of values
  (1 328 518 / 1 495 841) and cuts entries into the expensive stage from
  84 822 → 3 912 (21.7×), with the fire count bit-identical.** Without this the
  `%.767e` call would have run on ~5.7 % of all non-integer formats.
* **Stage 1** — `%.*e` at `prec+1`; a true tie always shows `'5'` there.
* **Stage 2** — `%.767e` is glibc's *exact*, zero-padded expansion (768 sig
  digits covers every finite f64; the longest, `2^-1074`, needs 751). Declare a
  tie iff digit `prec+1` is `'5'` and all the rest are `'0'`, then increment the
  `prec+1`-digit mantissa with carry (bumping `exp10` on 99…9 → 100…0).
* **Safety net** — the away-from-zero neighbour is `strtod`-checked; if it does
  not round-trip, glibc's answer is kept. Rust never emits a non-round-tripping
  representation, so this can only ever be the right fallback.

### Corpus-safety evidence (beyond wave 1's token scan)

Wave 1 proved 0 regression candidates across 5 095 expected-output files.
I added an independent standalone harness (`scratchpad/tietest{2,3}.c`) that
replays the real `shortest_digits`/`format_plain` code with and without the fix
over **1 495 841 positive doubles** (half f32-derived, half random bit
patterns):

```
prefiltered=1328518
tested=1495841  changed=1659  stage2_entries=3912  fired=3356  roundtrip_breaks=0
```

* `roundtrip_breaks = 0` — every re-rounded value still parses back to the
  original double.
* `changed` and `fired` are **identical with and without stage 0**, i.e. the
  arithmetic prefilter rejects zero true ties.
* `fired` (3 356) ≈ 2× `changed` (1 659) as expected: on about half of exact
  midpoints the last digit is odd, so to-even *also* rounds up and the two rules
  agree.
* The four known target values reproduce Rust's output byte-for-byte
  (`966.6782836914063`, `135.73892211914063`, `74.05337524414063`,
  `28.483901977539063`).

Entry point is AVM2-only (`avm2_format_number`); AVM1's formatter in
`actionmodern/action.c` is untouched.

## Fix 3 — B6 morph hit-test: **REFUTED, reverted**

Implemented, measured, and backed out. The blocker is concrete and reproducible.

### What wave 1 got right
`ext->is_morph_shape`, `ext->char_id` and `ext->ratio` are all correctly
maintained on the AVM2 side. Instrumented at both probes:

```
mpg is_morph=1 char=1 ratio=0     find=0
mpg is_morph=1 char=1 ratio=54237 find=0
```

### What wave 1 got wrong
`ng_find_morph_path(1, …)` returns **0** — the libswf morph-path registry is
empty in an AVM2 build. `ng_record_morph_path(1, 0, 30)` is emitted by the
recompiler into **`RecompiledTags/tagMain.c`'s `frame_0`**
(`SWFRecomp/src/swf.cpp:9427`, `context.tag_main <<`), i.e. into the AVM1 tag
stream. AVM2 SWFs run `tagInit()` (which for this test only registers a sprite)
and then drive their own timeline — `frame_0` is never called, so `path_data`
offsets are never registered. `ng_hitTestMorphPath` is compiled in and correct;
nothing can reach it.

### The AVM2-table fallback I then tried, and why it also fails
The AVM2 tables *do* carry morph geometry (`Avm2ShapeGeom.morph_end_offset` +
`morph_end_shape_data`, what the T6 render walk lerps at `avm2_display.c:14647`).
I implemented the full fix off those: ratio-lerped vertex AABB in
`point_in_self`, ratio-lerped triangles in `shape_contains_local`,
`morph_pick_geometry` in `has_pick_geometry` — no change to
`display_self_bounds`/`char_self_bounds`, per the hard constraint.

Result: **line 3 fixed, line 4 still wrong** (`true false false false` vs
expected `true false false true`). The instrumented cause:

```
aabb  char=1 ratio=0     n=27 box=(-4900.0,-3440.0)-(-2180.0,-880.0)   <- == tag StartBounds, exact
aabb  char=1 ratio=54237 n=27 box=(  372.0,  837.1)-( 1569.4,1587.9)
probe char=1 ratio=54237 local=(580.0,2020.0) inAABB=0 tri=0
```

`morph_end_shape_data[0..26]` spans only **x 1254…2917, y 1728…2560**, but the
tag's `EndBounds` are **x 1239…5119, y 1720…3660** and `path_data[0..29]`'s end
vertices do reach `5119`. The start tessellation matches its bounds exactly; the
**end tessellation is a truncated 1:1 re-pairing of the start topology** and does
not span the end shape. (Corroborating: chars 4 and 5 both carry
`morph_end_offset = 27` with counts 36 and 18 into a 45-row array — they
overlap.) So the AVM2 tessellation tables cannot reconstruct the mid-tween
outline, and the probe at local `(580, 2020)` is outside the lerped AABB.

### Verdict and the exact next step
B6 is a **recompiler-emission gap after all**, though not the one §12.3 named:
the geometry (`path_data`) is complete, but its `(char_id, offset, size)` index
is emitted only into the AVM1 tag stream. The minimal fix is to add
`path_offset` / `path_size` (and morph end bounds) to `Avm2ShapeGeom` /
`Avm2CharInfo` in `SWFRecomp/src/swf.cpp`, then route
`avm2_display.c:has_pick_geometry / shape_contains_local / point_in_self` to
`ng_hitTestMorphPath` + a ratio-lerped tag-bounds AABB. That is a recompiler
change requiring a full `--recompile` sweep — explicitly out of scope here.
Recommend re-filing §12.3's B6 line as *"recompiler: morph path index is
tag-stream-only, absent from the AVM2 tables"*.

**Nothing from fix 3 is in the patch.** `avm2_display.c`, `shape_hit_test.c` and
`include/libswf/tag.h` are byte-identical to `f166e424e`, so the sibling agents
editing `avm2_display.c` (w2-errframes, w2-avclasses, w2-gfx-bitmapmax,
w2-gfx-autosize) have no conflict with me.

---

## Per-test ledger

All runs local, `--mode` default (no-graphics), single-test, in the isolated
worktree. "Baseline" = `results_graphics.json` @ `6de650432`; every test was
also re-verified failing/passing in the worktree before the change.

### Targets

| Test | Suite | Baseline | After | Δ |
|---|---|---|---|---|
| `edittext_device_transform_layout` | avm2 | `output_mismatch` | **`ruffle_matched`** | **+1 eff** |
| `perspective_projection` | avm2 | `output_mismatch` | **`pass`** | **+1** |
| `acid-morph` | from_shumway/acid | `output_mismatch` | `output_mismatch` | 0 (reverted) |

### Canaries — fix 1 (edittext / device font)

| Test | Suite | Baseline | After |
|---|---|---|---|
| `edittext_autosize_lazy_bounds_vs_relayout` | avm2 | pass | **pass** |
| `edittext_autosize_lazy_bounds_props` | avm2 | pass | **pass** |
| `edittext_getcharboundaries` | avm2 | pass | **pass** |
| `edittext_getcharboundaries_scroll` | avm2 | pass | **pass** |
| `edittext_getcharboundaries_missing_glyphs` | avm2 | pass | **pass** |
| `edittext_getcharboundaries_culling` | avm2 | ruffle_matched | **ruffle_matched** |
| `edittext_getcharboundaries_missing_embedded_font` | avm2 | ruffle_matched | **ruffle_matched** |
| `edittext_get_char_index_at_point` | avm2 | pass | **pass** |
| `edittext_at_point_methods_basic` | avm2 | pass | **pass** |
| `edittext_line_metrics` | avm2 | pass | **pass** |
| `edittext_wrap_breaks` | avm2 | pass | **pass** |
| `edittext_empty_text_format` | avm2 | pass | **pass** |
| `device_font_kerning` | fonts | pass | **pass** |
| `device_font_glyph_fallback` | fonts | pass | **pass** |
| `device_font_list` | fonts | pass | **pass** |
| `edittext/edittext_device_transform_basic` | visual | pass | **pass** |
| `edittext/edittext_device_transform_metrics` | visual | ruffle_matched | **ruffle_matched** |
| `edittext/edittext_device_transform_negative` | visual | ruffle_matched | **ruffle_matched** |
| `flash_text_TextField` | from_shumway | ruffle_matched | **ruffle_matched** |

`edittext_autosize_lazy_bounds_vs_relayout` — the single highest-risk row, the
one that would break if `bounds_x` were read through the lazy-bounds accessor —
was run first and stays `pass`.

### Canaries — fix 2 (number formatting)

| Test | Suite | Baseline | After |
|---|---|---|---|
| `perspective_projection_basic` | avm2 | pass | **pass** |
| `geom_transform` | avm2 | output_mismatch | **output_mismatch, line metrics identical** (`actual 26 / expected 74 / matching 21` before and after) |
| `convert_number` | avm2 | pass | **pass** |
| `number_autoconv` | avm2 | pass | **pass** |
| `matrix3d` | avm2 | pass | **pass** |
| `matrix3d_invert` | avm2 | pass | **pass** |
| `int_toprecision` | avm2 | ruffle_matched | **ruffle_matched** |

### Canaries — fix 3
Not run: the change is fully reverted, so `avm2/hittest_morph`,
`avm2/morph_shape`, `regression/avm2_morph`, `avm1/hittest_morph{,_input}` and
`from_gnash/misc-ming.all/morph_test1` cannot be affected. (`hittest_morph` and
`morph_shape` were nevertheless run mid-session and stayed `pass`.)

**Zero regressions across 26 executed canaries.**

---

## Files and lines

| File | Lines | What |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_text.c` | 8136-8151 | `+ et->bounds_x/bounds_y` in the layout→local origin, plus the raw-read invariant comment |
| `SWFModernRuntime/src/avm2/avm2_value.c` | 495-588 (new fn), 616-621 (call) | `tie_round_away_from_zero()` + its guarded call from `shortest_digits()` |

Sibling-collision check: `avm2_value.c` is also edited by w2-xs at ~654
(`ToPrimitive` hint) — my insertion is at 495-588 and the call site at 616-621,
both above it; the hunks are ~60 lines apart and should merge cleanly, though
w2-xs's line numbers shift by +101. `avm2_text.c` is also edited by
w2-avclasses (~6126), w2-textblock and w2-gfx-autosize (~3892) — my hunk is at
8136, well clear of all three.

## Risks

* **Fix 1** — low. Arithmetically a no-op for any field with
  `bounds.x_min == bounds.y_min == 0`, which is every `new TextField()` (17 of
  the 20 corpus tests that call these APIs). The 3 exposed tests are all in the
  ledger above and none moved. Only risk is a future refactor routing
  `et->bounds_x` through the lazy accessor; the comment at the site guards
  against it.
* **Fix 2** — low, and now also perf-safe. Behaviour risk was settled twice
  independently (wave-1 corpus token scan: 0 regression candidates in 5 095
  files; my 1.5 M-value replay: 0 round-trip breaks). Perf risk was the one open
  item and stage 0 closes it — 88.8 % arithmetic rejection, and the pre-existing
  integer fast path at `avm2_value.c:589` still short-circuits before any of
  this. Residual: the stage-2 buffers are ~1.5 KB of stack, but they live in a
  separate function only entered at `prec >= 13` after stage 0, so the hot path
  never allocates them.
* **CI mode / categories** — `mode=graphics`, `categories=full` (both fixes are
  AVM2 runtime), `images=false`. Neither target carries `[[image_comparisons]]`
  on the changed axis; fix 1's target has none at all, so both are
  pixel-board-neutral.
* **Filtered vs unfiltered** — `edittext_device_transform_layout` is in
  `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:65`, so its flip banks in the
  **unfiltered** `effective_pass` headline only, not in the filtered report.
  `perspective_projection` banks in both.

## Cross-cutting notes for the arc doc

* Wave 1's "replay the shipped algorithm against the generated tables checked
  into the test directory" technique is genuinely cheap and it *did* correctly
  prove `path_data` is complete. What it could not see is **whether the
  generated code that consumes those tables is ever executed in the relevant VM
  mode.** For anything AVM2, "the recompiler emits it" must be followed by
  "…into which stream?" — `context.tag_main` output is AVM1-only. Worth adding
  to the standing triage list next to `bucket-by-vm`.
* Two-of-three wave-1 premises held under implementation; the third inverted
  (wave 1 refuted §12.3's "recompiler-side" label, and implementation
  re-established it for a *different* reason). Net: a §12.x parenthetical is
  still not a scoping verdict, but neither is a read-only refutation of one.
* Reusable: for any output-formatting change, "scan every numeric token in every
  expected-output file" (wave 1) plus "replay the real code over ~10^6 values
  and assert the round-trip invariant" (here) is a two-sided proof that costs
  minutes and removes the need for a speculative full-suite run.
