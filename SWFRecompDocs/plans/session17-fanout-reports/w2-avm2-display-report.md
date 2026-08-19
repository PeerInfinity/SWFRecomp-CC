# w2-avm2-display — session 17 wave-2 report

**Agent:** `w2-avm2-display`. Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-acf15cf558cf11d5d`.
Baseline HEAD `88ebde665`; grading run `31877239992` at `aeebf9ede`
(trace 4317/4453 effective, pixels 338/569).
All measurements `verify_output.py --mode=graphics --diff --verbose`,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, ≤ 2 concurrent compiles.

## NEW FILES CREATED BY THESE PATCHES

**None.** All four patches touch exactly two existing files:

| file | T1 | T3 | T5 | T10 |
|---|:-:|:-:|:-:|:-:|
| `SWFModernRuntime/src/avm2/avm2_display.c` | ✔ | ✔ | ✔ | ✔ |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | — | ✔ | — | — |

The header change is five trailing fields (`sr_committed` + four `csr_*`) at the END of
`Avm2DisplayObjectExt` (T3 only) — no new header, no CMake / Emscripten /
`verify_output.py` source-list change needed.

## VERDICTS (read this first)

| lead | verdict | priced | delivered | test |
|---|---|---:|---:|---|
| **T1** quality-scaled `concatenatedMatrix` | **GO — LANDED** | +1 | **+1** | `avm2/displayobject_transform` `output_mismatch` → **PASS** |
| **T3** committed scrollRect | **GO — LANDED** | +1 | **+1** | `avm2/displayobject_scrollrect` `output_mismatch` → **PASS** |
| **T3** pixel rider | **REFUTED (no flip)** | 0 (grade only) | 0 | image comparison unchanged: 4 outliers / limit 0, max diff 255, before AND after |
| **T5 (a)** `pixelBounds` world space | **NO-GO — mechanism REFUTED, and NOT NEEDED** | 0/+1 | — | see §T5 |
| **T5 (b)** `Percent` scale round-trip | **GO — LANDED** | 0/+1 | **+1** | `avm2/bounds_mode` `output_mismatch` → **`ruffle_matched`** (effective pass) |
| **T10** `#2007 targetCoordinateSpace` | **GO — LANDED, cascade unlocked, 0 flips** | 0/+1/+2 | 0 | `avm2/displayobject_getrect` 2/16 → 9/16 matching; `from_shumway/acid/acid-shapes` 0/120 → all 120 produced |


**Net delivered: +3 trace flips** — `avm2/displayobject_transform` and
`avm2/displayobject_scrollrect` to `pass`, `avm2/bounds_mode` to
`ruffle_matched` (which counts in `effective_pass`). 0 pixel flips, 0
regressions in the graded canary set. T10 is the one lead that did not flip,
and it removed a throw plus 7 of its 14 cascade lines and produced all 120
lines of its second row.

## Patches (stackable, in this order — each applies cleanly on the previous)

```
SWFRecompDocs/plans/session17-fanout-reports/w2-avm2-display-T1.patch
SWFRecompDocs/plans/session17-fanout-reports/w2-avm2-display-T3.patch
SWFRecompDocs/plans/session17-fanout-reports/w2-avm2-display-T5.patch
SWFRecompDocs/plans/session17-fanout-reports/w2-avm2-display-T10.patch
```

Dependency: **T10 textually depends on T3** (T3 switches `do_get_bounds` onto
the new `display_l2g_matrix` helper; T10 then restructures the same block into
the `target == self` fast path). T1 and T5 are independent of everything.
Verified mechanically: applying T1→T3→T5→T10 onto pristine `88ebde665` copies
of the two files reproduces this worktree byte-for-byte, and every intermediate
stage (v0..v4) passes `gcc -fsyntax-only`.

**Every line of every patch is inside `avm2_display.c`'s transform/bounds
region plus five trailing struct fields** — no textual overlap with the five
sibling `avm2_display.c` owners (gfx / filters / compose_children / hit-test
edge-exclusivity). The one exception worth flagging to the coordinator: T1
touches `stage_get_quality` / `stage_set_quality` (the Stage accessor block,
unclaimed in `SIBLING_FILE_MAP.md`) and repoints `displayState`'s setter, see
§T1.

**CI mode plan: UNCHANGED — `swf_core.c` was NOT touched.** Verified at the
build level, not just by inspection: `verify_output.py:2191` notes that
`-DSWF_AVM2` routes `main.c` to `runSWF_avm2()` **instead of** `swf_core.c`'s
`swfStart()`, so every AVM2 test in either mode reaches the tick loop in
`avm2_main.c` and therefore `avm2_display_run_tick()` — where the latch lives.
`swf.c` vs `swf_core.c` only differ on the AVM1 path and the renderer. The
committed rect lands identically in both modes with no `#ifdef`, and nothing
in these four patches sits behind `NO_GRAPHICS` / `OFFSCREEN_RENDER`.
`graphics` remains the right per-change mode; the weekly no-graphics canary
covers the other arm. `categories=full` is appropriate (AVM2 runtime change).

---

## T1 — `concatenatedMatrix` reads the live `Stage.quality` — **GO, +1**

**Premise CONFIRMED verbatim.** Local re-run at `88ebde665`: every diff line of
`avm2/displayobject_transform` is the hard-coded `double scale = 5.0` at
`avm2_display.c:10180`, and the fixture (`Test.as` `checkQuals`) walks
`["best","high","16x16","16x16linear","8x8","8x8linear","low","medium"]` twice.

**Mechanism.** `transform.rs:121-127` maps quality → scale
(Low 20, Medium 10, High|Best 5, 8x8|8x8Linear 2.5, 16x16|16x16Linear 1.25).
Our `Stage.quality` was a pair of stubs — getter returned the literal `"HIGH"`,
setter was a no-op — so the setting the fixture writes was thrown away.
The patch adds one file-static `Avm2StageQuality`, `quality.rs`'s
`from_str` (case-SENSITIVE, matching AVM2's `parse()`; invalid values leave the
setting unchanged, `stage.rs:412`) and `into_avm_str` (Flash always reports
uppercase; the two `*Linear` settings report as their non-linear twin).

**Three pricing/scope findings of my own:**

1. **The initial value must follow the harness, not the literal `HIGH`.**
   `verify_output.py:2550` emits `-DMSAA_SAMPLES=1` for `quality = "low"` and
   nothing otherwise, so `MSAA_SAMPLES` is an exact quality predicate. The
   static is initialised from it (1 → `low`, else `high`; the 2/8/16 arms are
   written out but the harness never emits them). Corpus scan: `stage_properties`
   is the only test that traces `stage.quality`, it runs at the default quality
   and still expects `HIGH`; the 266 `quality = "low"` tests never read it.
2. **Rendering is deliberately NOT driven from the new static.** The MSAA
   sample count is fixed at build time, so a mid-run `stage.quality = "low"`
   cannot change what the GPU already built — which is also true in Ruffle
   (its renderer keeps its own pipeline sample count). Zero render risk.
3. **Latent bug found and fixed in the same hunk:** `displayState`'s setter was
   registered as `stage_set_quality` (`avm2_display.c:14801`) purely because
   that function used to be a no-op. Once `quality` stores a value that wiring
   becomes a real aliasing bug, so `displayState` got its own inert setter.
   (`"normal"` / `"fullScreen"` parse as no quality, so behaviour is unchanged
   either way — this is hygiene, not a flip.)

**Ledger:** `avm2/displayobject_transform` `output_mismatch` (22 diff lines) →
**PASS**, all 89 lines. Confirms the board's R2 refutation: it is +1, not +2
(`bounds_mode` has no `concatenatedMatrix` row).

---

## T3 — committed scrollRect — **GO, +1** (pixel rider REFUTED)

**Premise CONFIRMED exactly.** Baseline re-run: 6 diff lines, all one
mechanism — `localToGlobal`/`globalToLocal` ×4, `scrollChild.transform.
concatenatedMatrix` (tx 125→54, ty 146→64) and `hitTestPoint(400,400,true)`.

**Mechanism, as implemented.** Ruffle keeps two rects per object:
`next_scroll_rect` (what AS wrote, what the `scrollRect` getter reports,
`display_object.rs:899`) and `scroll_rect` (what bounds, hit tests and the
local↔global matrices read). `DisplayObject::pre_render` copies one to the
other once per frame (`display_object.rs:2426-2430`). Four parts:

1. `Avm2DisplayObjectExt` gains `sr_committed` + `csr_{x,y}{min,max}`
   (trailing fields). `has_scroll_rect`/`sr_*` stay the `next` half.
2. `avm2_commit_scroll_rects()` — the latch — walks the stage render list,
   latching every child (invisible ones included, as `pre_render` does) and
   recursing only into children that are actually rendered (visible, or drawn
   as a clip mask), mirroring `container.rs:559`.
   **It is called from `avm2_display_run_tick()`, one line after
   `render_apply_text_bounds()` and before `run_due_timers()` — the frame
   loop, not the renderer.** That is the mode-parity requirement from §17.4,
   and it is also why the fixture's 50 ms timer sees the committed rect while
   the constructor (lines 12–23) does not.
3. Two new helpers mirroring `display_object.rs:1487` and `:1505`:
   `display_l2g_matrix_no_own_sr()` (every **ancestor** with a committed rect
   folds `translate(-x_min,-y_min)` in ahead of its own matrix — the
   concatenatedMatrix flavour) and `display_l2g_matrix()` (the same walk with
   the object's **own** translate applied first). `display_world_matrix()` is
   left alone as the raw ancestor concat the render walk uses, so the renderer
   — which already applies the scroll translate next to the stencil it pushes
   — is untouched and cannot double-apply.
4. Script-visible geometry repointed onto the new helpers: `getBounds`/`getRect`,
   `localToGlobal`/`globalToLocal`, `hitTestPoint` (both arms), `hitTestObject`,
   `point_in_self`, `pixelBounds`, and `concatenatedMatrix` (the
   without-own-rect flavour). `bounds_with_transform`'s scroll-rect override now
   reads the committed rect.
   The mouse-pick / drag / focus-highlight sites keep `display_world_matrix`
   on purpose: they are sibling-owned regions this session and the change is a
   provable no-op for every object without a scroll rect.

**One extra fix the diff needed that the board did not name.** Our container
`hit_test_shape_obj()` had no `world_bounds(Engine).contains(point)` gate,
which `movie_clip.rs:2688` applies first — that gate is *what performs the
crop*, and without it `hitTestPoint(400,400,true)` walked straight into
`scrollChild`. The patch adds the gate **only for objects with a committed
scroll rect**: for an ordinary container `world_bounds` is the union of
everything below it, so the gate can never change an answer there, and
restricting it keeps the blast radius at zero for the mouse-pick family.

**REFUTATION — the board's "second rider" (f32 re-quantisation) is a
non-issue.** The board asked for `Matrix * Matrix` to re-round through f32
because expected `a = 1.709999918937683` while we produce
`1.7099998766183875`. That line **already matched at baseline**: the test's
`[approximations] max_relative = 1.1920928955078125e-07` is exactly one f32
ULP, and the two values differ by 2.5e-8 relative. Only `tx`/`ty` (125 vs 54)
were ever out of tolerance. Making `mat_mul` f32-exact would have perturbed
every bounds computation in the corpus for zero grading benefit — **not done**.

**RENDER CANARY (T3's required check) — `IDENTICAL 3 / DIFFERS 0`.**
`render_canary.py capture/compare` over `avm2/displayobject_scrollrect`,
`avm2/blend_multiply_alpha` and `regression/avm2_morph`, both legs with
`--recompile`, `-P 1`, the `before` leg produced by `git apply -R` of the full
stack and the worktree verified byte-identical to `v4` afterwards
(`RESTORED OK` / `WORKTREE MATCHES v4`):

```
RENDER CANARY  before=w2disp_before  after=w2disp_after   3 tests / 3 comparisons
  IDENTICAL     3
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES:
    avm2/displayobject_scrollrect   output_mismatch -> pass   (trace text differs)
  IMAGE STATUS CHANGES: (none)
```

Every rendered PNG is md5-identical across the patch; the *only* thing that
moved is the trace status of the row this patch targets. (`compare` exits
non-zero whenever anything moved at all, trace included — that is the tool
working, not a failure.) **Canary blind spot, stated honestly:** the standing
`render_canary_tests.txt` set has no scrollRect member and only four AVM2
members, so the set was reduced to the three AVM2/regression rows that can
actually exercise this change, with `avm2/displayobject_scrollrect` added
because it is the fixture under test. The covering evidence for the rest of the
transform/bounds region is the tolerance-zero golden matches on
`displayobject_set_matrix_nested` (3 comparisons) and `displayobject_mask`
recorded below, which are absolute verdicts rather than A/B checks.

**PIXEL RIDER — REFUTED, graded both ways.** `avm2/displayobject_scrollrect`'s
image comparison is byte-for-byte the same verdict before and after:
`4 outliers exceed limit of 0, max difference 255`. The committed rect does
not move the blit (the renderer already applied the uncommitted rect, and after
the latch the two are equal at render time by construction), so those 4 pixels
are an independent AA tie, exactly the alternative the board allowed for. This
row flips on the trace axis only.

---

## T5 — `bounds_mode` — **(b) GO, +1; (a) NO-GO and unnecessary**

Baseline re-run at `88ebde665` reproduces the board's count exactly: **16 diff
lines**, 6 `pixelBounds` + 10 scale.

### (b) `Percent` round-trip — CONFIRMED, all 10 rows fixed, and it is the whole +1

Ruffle stores scale as `Percent(f64)`: `from_unit(u) = u * 100.0`,
`unit() = p / 100.0` (`core/src/types.rs:5-20`). **Every** producer goes
through `from_unit` — the matrix decomposition (`display_object.rs:499-500`)
as well as `set_scale_x` / `set_width` / `set_height` (`:1715`) — and every
consumer (the getters and the matrix rebuild) through `unit()`. The patch adds
`scale_percent_roundtrip(u) = (u*100.0)/100.0` at the three store sites
(`cache_scale_rotation`, `set_scale_x_internal`, `set_scale_y_internal`).
All three constants reproduce bit-exactly and by nothing else:

| expression | ours (baseline) | round-trip | expected |
|---|---|---|---|
| `200/65` | `3.076923076923077` | `3.0769230769230775` | `3.0769230769230775` |
| `100/65` | `1.5384615384615385` | `1.5384615384615388` | `1.5384615384615388` |
| `200/120` | `1.6666666666666667` | `1.666666666666667` | `1.666666666666667` |

**Pricing attack on my own change — the blast radius is much smaller than the
board feared.** Two independent bounds on it:

1. `mtx_a/b/c/d` are `float`. `(float)3.0769230769230775` and
   `(float)3.076923076923077` are the *same float*, so the round trip cannot
   move one pixel of geometry, one bounds number, or one matrix read anywhere
   in the corpus. It moves **only** double-precision `scaleX`/`scaleY` reads.
2. The round trip is the identity for far more values than "non-dyadic"
   suggests — the two roundings usually cancel. Measured: `(v*100)/100 != v`
   for **14.1 %** of uniform samples in [0.01, 100] (28115/200000) and
   **14.1 %** of small-integer ratios `a/b, a,b < 200` (5599/39601). `0.1`,
   `1.5`, `2.0` and even `52428.8` (the `Video.width` saturation constant) all
   round-trip exactly.

So this is a canary-able change, not the full-corpus A/B the board expected.
One genuinely new behaviour to note: a scale above `DBL_MAX/100 ≈ 1.797e306`
now saturates to `Infinity` (`u*100` overflows), which is exactly what Ruffle's
`Percent(f64)` does; no corpus fixture reaches that magnitude.

### (a) `pixelBounds` — the board's mechanism is REFUTED

§17.4 and the board both say we "return the caller's / document-class space"
and need world space. **We already compute world space** —
`transform_get_pixel_bounds` has called `display_world_matrix` all along — and
the fixture proves our world bounds are right, because
`hitbox.getBounds(this)` = `(-0.75, -0.75, 65, 65)` is an **expected-and-matching**
line one row above the failing `pixelBounds`. The 0.75 is not "the document
class's own stage offset" either; it is the same for every frame and object.

The real expected values are not world bounds under any single rule:

| object | local bounds (`getRect(self)`) | world bounds (`getBounds(this)`, we MATCH) | expected `pixelBounds` |
|---|---|---|---|
| `hitbox` (MovieClip + shape) | `(-32.75,-32.75,65,65)` | `(-0.75,-0.75,65,65)` | `(0,0,65,65)` |
| `hitbox` frame 5 | `(-32.75,-32.75,120,65)` | `(-0.75,-0.75,120,65)` | `(0,0,120,65)` |
| `textbox` (TextField) | `(-2,-2,530,140)` | `(10,190,530,140)` | `(12,192,0,0)` |

The `hitbox` rows are the world rect translated by exactly `+0.75, +0.75`
(size preserved). The `textbox` row is a **degenerate zero-size rect at the
field's world origin** — `matrix * Rectangle::ZERO`, i.e. Flash treated the
field's self bounds as empty. Three hypotheses were tested against all three
rows and all three fail: "world bounds without strokes" (predicts the textbox
row unchanged at `(10,190,530,140)`), "matrix × ZERO" (predicts `(32,32,0,0)`
for hitbox), and "truncate the origin toward zero, keep the size" (right for
hitbox, wrong for textbox). Note the test is `known_failure = true` upstream —
Ruffle does not match it either (`output.ruffle.txt` of the sibling
`from_shumway/.../transform/pixelBounds` differs from its `output.txt` too).

### The decisive evidence — and why `bounds_mode` flips anyway

`avm2/bounds_mode` ships **two** expectation files, and `diff` between them is
**exactly the 6 `pixelBounds` lines and nothing else**:

```
11,56,101,146   output.txt  (x=0, y=0, w=65, h=65)      output.ruffle.txt  (x=-0.75, y=-0.75, w=65, h=65)
191             output.txt  (x=0, y=0, w=120, h=65)     output.ruffle.txt  (x=-0.75, y=-0.75, w=120, h=65)
236             output.txt  (x=12, y=192, w=0, h=0)     output.ruffle.txt  (x=10, y=190, w=530, h=140)
```

Ruffle's own `pixelBounds` values **are ours, to the digit**. So "make
`pixelBounds` world space" is not a fix at all — it is a description of what
both Ruffle and this runtime already do, and the remaining gap is a
Flash-vs-Ruffle difference that Ruffle itself does not model. That is the
refutation, and it is also the flip:

**`avm2/bounds_mode` `output_mismatch` → `ruffle_matched` (+1 effective pass),
from T5(b) alone.** Once the 10 scale rows match, every line we produce is
either the Flash expectation or Ruffle's, so the harness's
`ruffle_matched` axis catches it. The board's "real +1" was right; its
mechanism attribution was not — the +1 comes entirely from the half it called
"the half that can regress", and none of it from the half it said to take
first.

**Disposition follow-up:** the 6 `pixelBounds` rows now belong in
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
(our output matches Ruffle's actual behaviour; the Flash oracle disagrees with
both) — except that we do **not** know Flash's rule, so the honest entry is a
`RUFFLE_VS_FLASH_DIFFERENCES` note that cites the probe fixture below as the
open question. I did not write it because `w2-tooling-hygiene` owns the
disposition docs this session.

**Verdict: NO-GO on implementing (a); it is not needed and the mechanism the
board named is refuted.**

**Completion mechanism (what flips it to GO):** a Flash-oracle probe fixture in
`ruffle-tests/tests/swfs/regression/` that traces `transform.pixelBounds` for
(i) a bare Shape at a fractional world position, (ii) a Sprite with one
offset child, (iii) a TextField, and (iv) each of those again *after* a frame
has rendered. That separates "origin quantisation" from "TextField degenerate"
from "edge bounds" in one run. Without it, any implementation is numerology on
a single 0.75.

---

## T10 — `#2007 targetCoordinateSpace` — **GO; cascade unlocked, 0 flips here**

**The board's diagnosis is REFUTED in its details and confirmed in its shape.**
It says "our `getBounds` argument coercion is producing `null` for a
`targetCoordinateSpace` Flash accepts (the `MorphShape` is the obvious
suspect)". The `MorphShape` is innocent: `displayobject_getrect/Test.as` passes
the **literal `null`** sixteen times (`firstChild.getBounds(null)`), and Flash
accepts it. Ruffle never throws here at all —
`args.try_get_object(0).and_then(as_display_object).unwrap_or(dobj)`
(`display_object.rs:1038` / `:1060`) — so `null`, `undefined`, a missing
argument and a non-DisplayObject all mean "my own coordinate space".
Corpus scan: **no** `output.txt` anywhere expects
`#2007 … targetCoordinateSpace`, and `displayobject_getrect` is the only
fixture in the corpus that calls `getBounds(null)`.

The patch replaces the throw with the `unwrap_or(self)` fallback and adds
Ruffle's `target == self` fast path (`get_dobj_bounds`, `display_object.rs:1011`
— "no AABB transform needed"), which also removes a needless round trip through
`mat_invert`'s whole-twip quantisation.

**Result on `avm2/displayobject_getrect`: 2/16 matching → 9/16 matching**, the
throw and all 14 cascade lines gone. It does **not** flip, and the 7 survivors
are one single unowned mechanism:

```
-  4  (x=33.65, y=26.1,  w=66.35, h=75.19999999999999)   <- expected getRect
+  4  (x=33.25, y=25.7,  w=67.15, h=75.95)               <- ours (== getBounds)
- 11  (x=10.5,  y=10.5,  w=19, h=19)                     <- expected getBounds
+ 11  (x=12,    y=12,    w=16, h=16)                     <- ours (== getRect)
```

`getBounds` and `getRect` are registered to the **same** function
(`avm2_display.c:14188-14189`); Ruffle passes `BoundsMode::Script` to one and
`BoundsMode::ScriptWithoutStrokes` to the other (`display_object.rs:914-934`).
The diff runs in *both* directions: for a timeline `DefineShape` our bounds are
the stroke-inclusive `ShapeBounds` (so `getRect` is 0.4 px too wide), and for a
runtime `Graphics` drawing our AABB never adds the stroke half-width at all (so
`getBounds` is 1.5 px too narrow).

**This is the SAME mechanism T5(a) needs**, and it is *not* runtime-only:
`Avm2CharInfo` (`avm2_abc.h:344`) carries one bounds rect per character, so the
DefineShape4 `EdgeBounds` a stroke-free `getRect` needs must be emitted by the
recompiler. That is out of scope for a runtime-only slot and belongs in a
combined next-session lead:

> **Next-session lead — `BoundsMode` end to end.** (1) recompiler: emit
> `EdgeBounds` alongside `ShapeBounds` in `Avm2CharInfo`; (2) runtime: thread a
> `BoundsMode` parameter through `bounds_with_transform` / `display_self_bounds`
> / `char_self_bounds`; (3) runtime-only and independently worth doing: expand
> the `Graphics` drawing AABB by the active `lineStyle` half-width for the
> stroke-inclusive modes. Pays `avm2/displayobject_getrect` (7 lines, the last
> ones), the `getRect` rows of any future bounds fixture, and is a prerequisite
> for whatever `pixelBounds` turns out to be. Note (3) lands in the `Graphics`
> region owned this session by `w2-gfx-drawgraphicsdata`.

### T10's second row — `from_shumway/acid/acid-shapes`: cascade unlocked, one constant away

Baseline (board, re-confirmed): dies at **actual line 7 of 120** on the same
`#2007`. After the patch it produces **all 120 lines**, and every one of them is
wrong by the *same* constant:

```
-  1..120  24 34      (expected, ×120)
+  1..120  20 30      (ours,     ×120)
```

`+4` on both axes = a **2 px stroke omitted on each of the four sides**, and
this one is **runtime-only, not a recompiler change**: the movie's ABC string
table (`RecompiledABC/abc0_tables.c:95-103`) contains
`graphics / beginFill / lineStyle / moveTo / lineTo / curveTo / endFill /
drawCircle` plus `getBounds / width / height`, i.e. the shapes are drawn at
runtime through the Graphics API, and our drawing AABB
(`draw_union_point`, `avm2_display.c:~7788`) unions the raw path points and
never adds the active line half-width. `Avm2GraphicsExt` already carries the
width it needs (`clw`, "line width (pixels)").

> **Next-session lead — Graphics stroke bounds (`acid-shapes`, +1, runtime-only).**
> Expand the drawing AABB by `clw / 2` on all four sides while a line style is
> active, when accumulating `draw_*`. Expected: `from_shumway/acid/acid-shapes`
> `output_mismatch` → **pass** (all 120 lines are the same string, so it is a
> single-constant flip); `avm2/displayobject_getrect` stays at 7 mismatches
> (lines 11/13 fix, 12/14 break) until `BoundsMode` lands, at which point
> **both** rows flip together. Not done here for three reasons, all of which a
> next session removes: it is a fifth item outside this brief, it lands in the
> `Graphics` recording region owned this session by `w2-gfx-drawgraphicsdata`,
> and its blast radius (every AVM2 test that calls `lineStyle` and then reads
> bounds / `width` / `height` / `hitTest`) needs its own canary sweep that
> would not have fit in the slot.

---

## Blast-radius argument (why the canary set is the right one)

Outside AVM2 `scrollRect` users, **T3 is a provable no-op**:
`display_l2g_matrix()` and `display_l2g_matrix_no_own_sr()` reduce to
`display_world_matrix()` term-for-term when no ancestor and no self has
`sr_committed`, the new hit-test gate is guarded on `sr_committed`, and
`bounds_with_transform`'s override is guarded on `sr_committed`. Only four
fixtures in the whole corpus assign an AVM2 `scrollRect`, and **all four are
graded below with the patch applied**: `avm2/displayobject_scrollrect`
(`output_mismatch` → **pass**), `avm2/stage_properties2` (pass → pass),
`avm2/stage_overriden_setters` (pass → pass) and
`avm2/edittext_autosize_lazy_bounds_props` (pass → pass). The last one is the
sharpest of the three no-change rows: it assigns `scrollRect = Rectangle(1,2,3,4)`
to a `TextField` and then reads `width`/`height` in the same callback, expecting
the rect **not** to have taken effect (`0,0,100,4`) — exactly the
next-vs-committed distinction this patch introduces.

**T5's** only script-visible effect is `scaleX`/`scaleY` doubles (the float cast
into the matrix erases the ULP), so the canary axis is "tests that trace a
non-dyadic scale": `displayobject_width`, `displayobject_height`,
`displayobject_rotation`, `displayobject_invalid_floats` (the NaN path — note
`NaN*100/100 == NaN`, and a scale above ~1.8e306 now saturates to Infinity,
which is Ruffle's behaviour too), `geom_transform`, `edittext_bounds_scale`,
`displayobject_set_matrix_nested`, `tab_ordering_arrows`.

**T10's** effects are (i) `getBounds`/`getRect` no longer throw and (ii)
`obj.getBounds(obj)` returns untransformed bounds instead of `inverse(W)·W`
bounds — a ≤1-twip change wherever a fixture asks an object for its own space:
`bounds_mode`, `displayobject_getbounds_shape`, `button_bounds`, `empty_bounds`.

**T1** is inert unless a fixture writes `Stage.quality` (only
`displayobject_transform` does) or reads it (only `stage_properties` does).

### Pixel-axis evidence (T3 rider), stated precisely

The stored **CI** image baseline and my **local post-patch** render agree to the
outlier, for both graded rows:

| row | CI baseline (`image_results_graphics.json` @ `c7b284034`) | local, patched |
|---|---|---|
| `avm2/displayobject_scrollrect:output` | `fail — 4 outliers exceed limit of 0, max difference 255` | `fail — 4 outliers exceed limit of 0, max difference 255` |
| `avm2/displayobject_getbounds_shape:output` | `fail — 28348 outliers exceed limit of 3800, max difference 255` | `fail — 28348 outliers exceed limit of 3800, max difference 255` |

Byte-identical outlier counts on the row the pixel board (`wave1-gfx-board` P8)
priced. The committed rect does not move the blit — expected, because the render
walk keys off `has_scroll_rect` (unchanged) and after the latch the two rects are
equal at render time by construction. **P8's 4 pixels are not a scrollRect
defect and should be re-owned to the AA/tie bucket.**

---

## Implementation notes the coordinator should know

* **Cost of the latch.** `avm2_commit_scroll_rects()` is one extra O(display
  tree) walk per tick, sitting immediately next to the `render_apply_text_bounds()`
  walk that already runs unconditionally, so it does not change the asymptotic
  per-frame cost of the AVM2 loop. A `g_scroll_rect_users` early-out would make
  it free for the ~100 % of content that never assigns a `scrollRect`; it was
  **deliberately not added** so that the delivered patch is byte-identical to
  the one every number in this report was measured on (s16 lesson). It is a
  two-line follow-up if a game profile ever shows it.
* **`display_world_matrix()` still exists and is still correct** — it is the raw
  ancestor concat, and the render walk / mouse-pick / drag / focus-highlight
  sites deliberately still use it. Anyone adding a new *script-visible*
  geometry accessor should use `display_l2g_matrix()` instead.
* **The `scrollRect` getter is unchanged** and still reports the uncommitted
  rect, which is right: `display_object.rs:899` returns `next_scroll_rect()`.
* **Header change is additive and trailing.** `sr_committed` + four `csr_*`
  ints at the end of `Avm2DisplayObjectExt`. Exts are zero-initialised, so an
  object that never sees the latch reads as "no committed rect", which is the
  correct initial state.
* **Possible double-assignment to flag.** `SIBLING_FILE_MAP.md` lists a
  `(pending) w2-scrollrect` agent owning "`avm2_display.c` `display_world_matrix`
  / scroll_rect latch, `action.c` frame loop" — which is T3. My own map entry
  also names "committed scrollRect fold into `display_world_matrix`". If that
  agent was launched, its patch and `w2-avm2-display-T3.patch` will collide
  head-on; take one or the other, not both. Note the difference in approach:
  this patch does **not** touch `action.c` and does **not** change
  `display_world_matrix` itself, so it needs no AVM1-side coordination and
  leaves the render walk alone.

---

## Completion mechanisms for everything not delivered

| item | why it did not flip | what flips it |
|---|---|---|
| `avm2/bounds_mode` **full** `pass` (T5a) | It flipped to `ruffle_matched` instead, which is worth the same +1. Reaching `pass` needs Flash's `pixelBounds` rule, which Ruffle does not model either: the `hitbox` rows are the world rect translated `+0.75,+0.75` with the size preserved, the `textbox` row is a zero-size rect at the field's world origin. No single rule fits all three. | A Flash-oracle probe fixture in `regression/`: `transform.pixelBounds` for a bare Shape at a fractional world position, a Sprite with one offset child, and a TextField — each before AND after a render. Separates origin quantisation / TextField-degenerate / edge-bounds in one run. Low priority: the +1 is already banked. |
| `avm2/displayobject_getrect` (T10) | 7 surviving lines are all `BoundsMode` — `getBounds` and `getRect` are registered to the same function, and the diff runs in both directions (timeline shapes too wide for `getRect`, runtime drawings too narrow for `getBounds`). | (1) recompiler: emit DefineShape4 `EdgeBounds` into `Avm2CharInfo`; (2) runtime: thread a `BoundsMode` through `bounds_with_transform` / `display_self_bounds` / `char_self_bounds`; (3) runtime: expand the `Graphics` AABB by `clw/2`. |
| `from_shumway/acid/acid-shapes` (T10) | Every one of the 120 produced lines is off by the same `+4,+4` — a 2 px stroke missing from the runtime `Graphics` AABB. | (3) above **alone**, and it is runtime-only. Highest-confidence unclaimed +1 I found this session. |
| `avm2/displayobject_scrollrect` image (T3 rider) | 4 outliers, unchanged before and after; not a scrollRect defect. | Re-own to the AA/tie bucket on the pixel board; it needs a rasteriser-tie investigation, not geometry. |

---

## Method note for s18 — the s16 `pkill` lesson needs one more clause

`BRIEFS_COMMON` §s16 says to select processes by **worktree hash** instead of
tool name, because every agent runs the identical `verify_output.py` command
line. That protects *siblings* — it does **not** protect **your own other
batches**. Re-ordering my run list mid-session, I killed the driver of batch A
by worktree hash and took out batch B's in-flight `verify_output.py` with it,
losing one canary that had to be re-queued.

The complete rule: **select by the PID you captured when you launched the
batch** (`p=$!`), or by a token unique to *that batch* (the per-batch scratchpad
log path passed on the command line), never by the worktree hash alone. The
harness's own guard says the same thing — it now blocks
`pgrep … | xargs kill` outright unless you pass `# PATTERN-KILL-OK`.

## Per-test ledger (every run graded this slot)

31 distinct tests run to completion in this worktree with the full T1+T3+T5+T10 stack applied. **3 gains, 0 regressions.**

| test | baseline (CI `results_graphics.json` @ `c7b284034`) | after (local, patched) | image comparison |
|---|---|---|---|
| `avm2/bounds_mode` | output_mismatch | **ruffle_matched** **← GAIN** | — |
| `avm2/button_bounds` | pass | **pass** | — |
| `avm2/displayobject_getbounds_shape` | pass | **pass** | 28348 outliers exceed limit of 3800, max difference 255 |
| `avm2/displayobject_getrect` | output_mismatch | **output_mismatch** | — |
| `avm2/displayobject_height` | pass | **pass** | — |
| `avm2/displayobject_hittestobject` | pass | **pass** | — |
| `avm2/displayobject_hittestpoint` | pass | **pass** | — |
| `avm2/displayobject_invalid_floats` | pass | **pass** | — |
| `avm2/displayobject_invalid_props` | pass | **pass** | — |
| `avm2/displayobject_mask` | pass | **pass** | image OK |
| `avm2/displayobject_rotation` | pass | **pass** | — |
| `avm2/displayobject_scrollrect` | output_mismatch | **pass** **← GAIN** | 4 outliers exceed limit of 0, max difference 255 |
| `avm2/displayobject_set_matrix_nested` | pass | **pass** | image OK |
| `avm2/displayobject_transform` | output_mismatch | **pass** **← GAIN** | — |
| `avm2/displayobject_width` | pass | **pass** | — |
| `avm2/displayobject_x` | pass | **pass** | — |
| `avm2/displayobjectcontainer_getobjectsunderpoint` | pass | **pass** | — |
| `avm2/edittext_autosize_lazy_bounds_props` | pass | **pass** | — |
| `avm2/edittext_bounds_scale` | pass | **pass** | — |
| `avm2/empty_bounds` | pass | **pass** | — |
| `avm2/geom_transform` | pass | **pass** | image OK |
| `avm2/mouse_pick_masking` | pass | **pass** | — |
| `avm2/mouse_pick_text` | pass | **pass** | — |
| `avm2/stage_displayobject_properties` | pass | **pass** | — |
| `avm2/stage_overriden_setters` | pass | **pass** | — |
| `avm2/stage_properties` | pass | **pass** | — |
| `avm2/stage_properties2` | pass | **pass** | — |
| `avm2/tab_ordering_arrows` | pass | **pass** | — |
| `from_shumway/acid/acid-shapes` | output_mismatch | **output_mismatch** | 93057 outliers exceed limit of 0, max difference 255 |
| `from_shumway/avm2/flash/geom/transform/pixelBounds` | ruffle_matched | **ruffle_matched** | — |
| `from_shumway/local2global` | pass | **pass** | — |
