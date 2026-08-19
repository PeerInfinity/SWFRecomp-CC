# Wave-1 — TRACE-axis board, regenerated (session 17, dual-axis fan-out #9)

**Agent:** `w1-trace-board`. Read-only in the main tree (no source edits, no
commits). Local verification: 22 individual tests re-run at HEAD `88ebde665`
with `verify_output.py --mode=graphics --diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
two batches at `-P 2` / `-P 1` (machine load average 25–31 from ~10 sibling
agents throughout). Never a suite. Three further rows (`avm2/matrix3d_*`) were
graded from the CI-stored outputs because they are **not on local disk** (§3);
`avm2/native_menu_basic`, `avm2/all_classes/events/swf9` and
`from_shumway/as3-loader/events/loader-events` were graded from the CI blobs
plus `check_model.py` rather than burning shared CPU on three very long AVM2
compiles that could not have changed a verdict.

**Baseline CONFIRMED, exactly: trace 4317 / 4453 effective** at results merge
`c7b284034` (CI run `31877239992` at `aeebf9ede`, graphics / categories=full /
images=true). Recomputed from the 20 git-tracked `*_results/results_graphics.json`
blobs with the three `NESTED` dirs excluded (`from_shumway/avm1`,
`from_shumway/timeline`, `from_gnash/misc-ming.all/displaylist_depths`) exactly
as `scripts/corpus_status_diff.py` does.

> **Provenance correction (refutation R7).** The s16 board recorded its baseline
> as "4298 / 4443 at `3db858cbc`". The blobs at `3db858cbc` read **4269 / 4443** —
> that commit *predates* the results merge for run `31748059158`. The s16-start
> baseline actually lives at `82ec2a359` (the merge) and at `cd04f80b9`. This is
> the `ci-baseline-commit-must-postdate-its-run` trap, and it is why the s16→s17
> delta below is computed from `82ec2a359`, not `3db858cbc`.

**s16 → s17 delta** (`scripts/corpus_status_diff.py 82ec2a359 c7b284034`):
intersection 4443, effective **4298 → 4314 (+16)** = **19 gains, 3 regressions**
(all three the `from_gnash` `Sound-v6/-v7/-v8` upstream-fixture drift, §3), plus
**10 new upstream names** (3 `pass`, 7 `output_mismatch`) → **+3** and a
denominator of 4453. Net headline **4298/4443 → 4317/4453**.
(`00b952cb7 → c7b284034`, i.e. the two post-run s16 closeout fixes, is +1 with
0 regressions — `verify_method_info_oob` and `define_bits_lossless2_rgb15`
confirmed.)

---

## 0. Status histogram (whole corpus, at the graded baseline `c7b284034`)

| suite | output_mismatch | pass | ruffle_matched | runtime_error | total | effective |
|---|---:|---:|---:|---:|---:|---:|
| audio | 2 | 3 | 0 | 0 | 5 | 3 |
| avm1 | 26 | 681 | 18 | 0 | 725 | 699 |
| avm2 | 57 | 1155 | 31 | 0 | 1243 | 1186 |
| fonts | 0 | 6 | 0 | 0 | 6 | 6 |
| from_avmplus | 5 | 1515 | 53 | 1 | 1574 | 1568 |
| from_gnash/actionscript.all | 16 | 135 | 92 | 0 | 243 | 227 |
| from_gnash/misc-ming.all | 13 | 69 | 29 | 0 | 111 | 98 |
| from_gnash/misc-mtasc.all | 0 | 7 | 2 | 0 | 9 | 9 |
| from_gnash/misc-swfc.all | 5 | 11 | 4 | 0 | 20 | 15 |
| from_gnash/misc-swfmill.all | 0 | 19 | 1 | 0 | 20 | 20 |
| from_shumway | 7 | 210 | 12 | 0 | 229 | 222 |
| import_assets | 0 | 3 | 0 | 0 | 3 | 3 |
| mixed_avm | 1 | 10 | 0 | 0 | 11 | 10 |
| regression | 0 | 72 | 0 | 0 | 72 | 72 |
| stage3d | 0 | 5 | 0 | 0 | 5 | 5 |
| swf | 0 | 4 | 1 | 0 | 5 | 5 |
| text | 1 | 10 | 0 | 0 | 11 | 10 |
| timeline | 2 | 12 | 3 | 0 | 17 | 15 |
| visual | 0 | 142 | 2 | 0 | 144 | 144 |
| **TOTAL** | **135** | **4069** | **248** | **1** | **4453** | **4317** |

**Zero `segfault`, `timeout`, `compile_fail`** for the fourth session running.
The only non-`output_mismatch` failure in the corpus is the long-standing
`from_avmplus/regress/bug_483783` `runtime_error`. The
`runtime-error-is-cheapest-triage-axis` key is dry at the status level; the
usable substitute remains `error_signature` (§4), present on **18** of the 136
non-effective rows.

136 non-effective rows. **33** are named in a disposition doc; **49** appear in
some `ignored_tests.txt` (global or suite-local) — ignored tests are still run
and still counted in the unfiltered `effective_pass`, so an ignore entry never
removes a row from this board. Ignore-list hygiene: §5.

---

## 1. Ranked leads — read this table first

Pricing: **floor** = flips with line-level evidence; **real** = expected from
one wave-2 session; **ceiling** = every row in the cluster. Every lead below
was re-graded at HEAD this session; nothing is inherited on trust.

| # | lead | rows | floor/real/ceiling | verdict | owner file(s) | size | evidence | independent slot? |
|---|---|---|---|---|---|---|---|---|
| **T1** | **`concatenatedMatrix` off-stage scale must read `Stage.quality`** | 1 (22 lines) | **+1 / +1 / +2** | **GO — take first** | `avm2_display.c:10180` (`double scale = 5.0;`) | **XS (one 6-arm switch)** | **STRONG** (Ruffle `transform.rs:121-127` quoted verbatim; all 22 lines are the one rule) | **YES** |
| **T2** | **Matrix3D: f32 rawData storage + exactly-16 length rule + 3×3 determinant** | 3 (NEW upstream) | **+1 / +2 / +3** | **GO** | `avm2_stage3d.c` (`Avm2Matrix3DExt`, `matrix3d_set_raw_data:1403`, `m3d_determinant:1657`) | S–M | **STRONG** (three f32 round-trips reproduced exactly; the determinant comment in our own source admits the divergence) | **YES** (must download the 3 test dirs first — §3) |
| **T3** | **committed scrollRect** (`next_scroll_rect → scroll_rect`, folded into the world matrix; `local_to_global_matrix_without_own_scroll_rect`) | 1 (6 lines) | **+1 / +1 / +1** (+1 pixel rider) | **GO** | `avm2_display.c` `display_world_matrix` + `hitTestPoint` | S–M | **STRONG** (all 6 remaining diff lines re-run at HEAD; arithmetic closes: 125−71=54, 146−82=64) | **YES** (self-localize vs T1: same file, adjacent function) |
| **T4** | **`all_classes/events` ×5 — the LAST failing `all_classes` package** | 5 | **0 / +3 / +5** | **GO — §17.4's "0 flips" is REFUTED** | `tools/descriptor/gen_display_descriptors.py` (`PKG`), `as_model.py`, `avm2_globals.c` generated region | M–L | **STRONG** (`check_model.py … flash.events` = 95 element mismatches; the landed `flash.display` = 0; other six packages all `pass`) | **YES** |
| **T5** | **`bounds_mode` double cluster: `pixelBounds` world space + `Percent` ×100/÷100 scale round-trip** | 1 (16 lines) | **0 / +1 / +1** | **GO (small), but A/B the Percent half corpus-wide** | `avm2_display.c` (`pixelBounds` getter, `set_width`/`set_height`/`scaleX` path) | XS + XS | **STRONG** (all three ULP constants reproduced exactly by `x*100/100`) | **YES** |
| **T6** | **AVM2/loader near-pass smalls #3 — six unowned one-mechanism rows** | 6 | **+3 / +4 / +6** | **GO** | mixed (`avm2_display.c`, `avm2_text.c`, `avm2_loader.c`, `avm2_domain.c`) | S each | STRONG ×5, MED ×1 | **YES** |
| **T7** | missing builtin class surface (`#1065`): `NativeMenuItem`/`NativeMenu`, `AutomationAction`, (`FullScreenEvent` — see the discrepancy in §T7) | 3 | 0 / +1 / +3 | GO (medium) | AVM2 class registration | M each | STRONG (each dies on one `#1065`) | YES — but `automation_classes` is not on local disk, and `stage_display_state` must be re-baselined first |
| **T8** | `avm2/event_handler_exception` — stack-trace `[file:line]` from ABC `debugfile`/`debugline` + a missing `dispatchEventFunction()` frame | 1 | 0 / +1 / +1 | DEFER (family of 1) | `abc_parser.cpp`/`abc_emit.cpp` + `avm2_error.c` | M | STRONG (6 lines, exactly this) | YES |
| **T10** | **the `#2007 targetCoordinateSpace` cascade** — `getBounds`/`getRect` reject a non-null argument | 2 | **0 / +1 / +2** | **GO (small)** | `avm2_display.c` `getBounds`/`getRect` arg coercion | S | **STRONG** (both rows die on line 3 / actual line 7; everything behind the throw is plain rects) | **YES** |
| **T9** | ignore-list hygiene + missing dispositions (§5) | 19 prune + 9 doc gaps | **0 flips** | **GO (doc-only, cheap)** | 4 `ignored_tests.txt` + `ACCEPTED_DIFFS.md` | S | STRONG (mechanically computed) | YES |
| — | `avm2/method_association`, `avm2/supercalls_coerce`, `avm2/displayobject_hittestpoint_boundary` | 3 | — | **HANDED OFF** → `w2-avm2-smalls` | — | — | — | — |
| — | `avm2/scope_optimizations` | 1 | — | **HANDED OFF** → `w2-scope-opt` | — | — | — | — |
| — | `avm2/mouse_pick_avm1_root`, `avm2/mouse_pick_loader_avm1` (leg E) | 2 | — | **HANDED OFF** → `w2-crossvm-legE` | — | — | — | — |
| — | `avm1/sound_load_*` ×7 + gnash `Sound-v6/-v7/-v8` | 10 | — | **HANDED OFF** → `w1-sound-load` (mechanism relayed, §3) | — | — | — | — |
| — | timeline-order arc ×12 incl. `button_nested_frame_simple` | 12 | — | **HANDED OFF** → `w1-timeline-order` | — | — | — | — |
| — | `text/links_in_scrolled_text` (held s16 patch) | 1 | 0 / 0 / +1 | **HOLD stands — but §17.4's completion mechanism is REFUTED (R4)** | `ng_shared.c` line model | S | — | — |
| — | `avm2/loader_duplicate_class` | 1 | 0 / 0 / +1 | DEFER (child-SWF symbol-class construction order) | — | M | MED | — |
| — | `avm2/number_convert_errors` | 1 | — | DEFER (structural, §17.4 stands) | — | L | — | — |
| — | Standing NO-GOs (§6) | ~30 | — | **NO-GO — do not re-cost** | — | — | — | — |

Summing the GO rows' *real* column: **+14** before anyone touches a handed-off
cluster. T1+T3 alone are two small edits in one file for +2.

---

### T1 — `concatenatedMatrix`'s off-stage scale is hard-coded 5  ★ take first

**GO. Floor +1, real +1, ceiling +2. One switch statement.**

`avm2/displayobject_transform` re-run at HEAD: **22 diff lines, every one of
them the same rule.**

```
-  6  16x16 TextField (a=1.25, b=0, c=0, d=1.25, tx=0, ty=0)
+  6  16x16 TextField (a=5,    b=0, c=0, d=5,    tx=0, ty=0)
- 14  low TextField   (a=20,   b=0, c=0, d=20,   tx=0, ty=0)
+ 14  low TextField   (a=5,    b=0, c=0, d=5,    tx=0, ty=0)
- 16  medium TextField(a=10,   b=0, c=0, d=10,   tx=0, ty=0)
- 69  concatenatedMatrix=(a=420, b=0, c=0, d=10, tx=0, ty=0)
+ 69  concatenatedMatrix=(a=210, b=0, c=0, d=5,  tx=0, ty=0)
```

`SWFModernRuntime/src/avm2/avm2_display.c:10180`, inside
`transform_get_concatenated_matrix`:

```c
	double scale = 5.0;  // StageQuality::High
```

Ruffle, `core/src/avm2/globals/flash/geom/transform.rs:121-127`, verbatim:

```rust
let scale = match activation.context.stage.quality() {
    StageQuality::Low => 20.0,
    StageQuality::Medium => 10.0,
    StageQuality::High | StageQuality::Best => 5.0,
    StageQuality::High8x8 | StageQuality::High8x8Linear => 2.5,
    StageQuality::High16x16 | StageQuality::High16x16Linear => 1.25,
};
```

Our structure is already right (on-stage → world matrix; Stage itself and
off-stage → quality-scaled *local* matrix); only the constant is wrong. The
fixture walks all seven quality values twice — once with the child off-stage
(both `TextField` and `stage` rows scale) and once with it on-stage (only the
`stage` rows scale), and our output is `5` in all 22 places.

**Rider found in the same read:** the on-stage branch must use Ruffle's
`local_to_global_matrix_without_own_scroll_rect()`, not `display_world_matrix`.
That is the *same* API T3 needs, so T1 and T3 belong in one slot.

**Refutation that would flip this to NO-GO:** none found — but note this is a
+1, not a +2: the "+5 more rows in `bounds_mode`'s neighbours" claim in §17.4 is
refuted (R2). The only plausible second row is `avm2/matrix`-family fallout,
which is already `pass`.

**Canaries:** `avm2/displayobject_getbounds`, `avm2/geom_transform`,
`avm2/stage_quality`, `avm2/bounds_mode`, `from_shumway/local2global`.

### T2 — Matrix3D is f32 internally (3 NEW upstream rows)

**GO. Floor +1, real +2, ceiling +3.** Three tests that arrived with the
2026-08-15 upstream sync, none owned by anybody, all one small family.

**(a) `rawData` is stored as f32, not f64.** Every expected value in
`avm2/matrix3d_precision` (20 diff lines) and `avm2/matrix3d_raw_data`
(3 of 5) is the **f32 round-trip** of ours:

| we print | Flash prints | check |
|---|---|---|
| `1.0000001` | `1.0000001192092896` | = `(double)(float)1.0000001` |
| `1.00000001` | `1` | = `(double)(float)1.00000001` |
| `1e+50` | `Infinity` | f32 overflow |
| `9.599999999999998e+38` | `Infinity` | f32 max = 3.4e38 |
| `-1.999999999999999e+41` | `-Infinity` | f32 overflow |

`Avm2Matrix3DExt` is `{ double m[16]; }` (`avm2_stage3d.c:1335`). Storing
`float m[16]` (or quantizing on every write) closes all of these.

**(b) `rawData` / `copyRawDataFrom` must accept a Vector of length exactly 16.**
`matrix3d_set_raw_data:1409` tests `src->length >= 16`; the fixture proves
`Length 17` and `Length 32` must leave the matrix **unchanged**:

```
- Length 17: 1,2,3,4,...,16          (expected: rejected, matrix unchanged)
+ Length 17: 100,101,...,115         (ours: took the first 16)
```

One character (`>=` → `==`). Worth 2 of `matrix3d_raw_data`'s 5 lines.

**(c) `determinant` is the 3×3 upper-left minor only.** All 9 visible diff
lines of `avm2/matrix3d_determinant` (33 missing) are:

```
exp: zero index 12 = NaN: 0        exp: zero index 13 = Infinity: 0
act: zero index 12 = NaN: NaN      act: zero index 13 = Infinity: NaN
```

i.e. rawData indices **12/13/14 (the translation row) must never participate**.
Our `m3d_determinant` (`avm2_stage3d.c:1657`) does a full 4×4 cofactor
expansion, and its own comment says so:

```c
	// 3x3 upper-left cofactor expansion is what Flash's `determinant` is
	// documented to return for an affine matrix; use the full 4x4 form so the
	// value stays right for projection matrices too.
```

The new fixture settles the question against that choice. Replace with
`m[0]*(m[5]*m[10]-m[9]*m[6]) - m[4]*(m[1]*m[10]-m[9]*m[2]) + m[8]*(m[1]*m[6]-m[5]*m[2])`.

**Attack the pricing:** `matrix3d_precision` is the *least* likely of the three
to flip — beyond the f32 storage it also wants `transformVectors` to accumulate
in f64 while `transformVector` clamps to f32 (expected
`transformVectors: 3.00000000000000e+50` on the same line where
`transformVector` reads `Infinity`), and that expected string carries a
15-significant-digit format we do not produce anywhere. Price `raw_data` and
`determinant` as the floor; treat `precision` as the ceiling.

**Blocker to state in the brief:** `avm2/matrix3d_{determinant,precision,raw_data}`
are **not on local disk** (§3). Download them before starting or the agent will
grade nothing.

### T3 — committed scrollRect (the last 6 lines of `displayobject_scrollrect`)

**GO. Floor +1, real +1, ceiling +1, plus a plausible pixel rider.**

Re-run at HEAD, the whole diff is 6 lines and they are one mechanism:

```
- 26  circle.localToGlobal(new Point(10, 20))      = (x=-16,    y=-6)
+ 26  circle.localToGlobal(new Point(10, 20))      = (x=55,     y=76)
- 28  scrollChild.localToGlobal(new Point(10, 20)) = (x=-130.3, y=-99.4)
- 31  scrollChild.transform.concatenatedMatrix = (a=1.709999918937683, …, tx=54,  ty=64)
+ 31  scrollChild.transform.concatenatedMatrix = (a=1.7099998766183875, …, tx=125, ty=146)
- 33  circle.hitTestPoint(400, 400, true) = false
+ 33  circle.hitTestPoint(400, 400, true) = true
```

`circle.scrollRect = (x=50, y=60, …)`; the scaled offset is exactly
125 − 54 = 71 and 146 − 64 = 82 twip-pixels. The s16 twip-quantization work
already made lines 1–25 byte-exact — this is purely the **latched, committed**
`scroll_rect` that Ruffle folds into `display_world_matrix()` for self *and each
ancestor* via `Matrix::translate(-x_min, -y_min)`.

Two riders that fall out of the same edit:
* the a/b/c/d on line 31 must be *re-rounded* — expected `1.709999918937683`
  (the f32 of 1.71) vs our f64-accumulated `1.7099998766183875`, i.e. Ruffle's
  `Matrix * Matrix` is f32 and the extra translate re-quantizes;
* `concatenatedMatrix` must exclude the object's **own** scroll rect but include
  its ancestors' (`local_to_global_matrix_without_own_scroll_rect`) — line 31 is
  `scrollChild`, whose *parent* `circle` carries the scrollRect.

**Must be driven by the frame loop, not the renderer** (mode parity), per §17.4.

**Pixel rider (do not price, but grade it):** `avm2/displayobject_scrollrect`'s
image comparison fails at **4 outliers over a limit of 0** — the smallest excess
on the whole image board. If the committed rect moves the blit, this row flips
on both axes; if it does not, the 4 pixels are an independent AA tie.

### T4 — `all_classes/events` ×5: §17.4's "0 flips" is REFUTED

**GO. Floor 0, real +3, ceiling +5.** §17.4 rules this "0 flips … correctness/
foundation item only". Three measurements say otherwise.

1. **It is the last failing `all_classes` package.** At the baseline,
   `accessibility` (3), `display` (6), `display3D` (3), `errors` (3),
   `security` (4) and `xml` (2) are **all `pass`**; only `events` ×5 fails.
2. **The model is already 95 element-mismatches from correct**, and the tool to
   measure it exists and needs no build:
   ```
   $ python3 tools/descriptor/check_model.py .../all_classes/display flash.display
   TOTAL mismatches: 0
   $ python3 tools/descriptor/check_model.py .../all_classes/events  flash.events
   == swf9: 14   swf10: 20   swf11: 20   swf12: 20   swf30: 21   TOTAL: 95
   ```
   95 across 1030–2353 expected lines per version.
3. **The 95 collapse into two defects**, not 95:
   * `IEventDispatcher`'s five interface methods need
     `uri="flash.events:IEventDispatcher"` on the `<method>` element (10 of every
     version's mismatches — the MODEL-ONLY/FLASH-ONLY pair is the same method
     with and without `uri`);
   * constructor arity gating by API version — `FocusEvent` (we carry an extra
     trailing `String` param), `KeyboardEvent`, `GestureEvent`,
     `PressAndTapGestureEvent`, `TransformGestureEvent` (we carry 1–2 extra
     trailing optionals that Flash only grows at a later API version).

The generator hard-codes `PKG = "flash.display"`
(`gen_display_descriptors.py:44`) and splices into `avm2_globals.c` between the
two markers (`:2986` / `:4099`, 1113 generated lines). Parameterizing `PKG` and
re-running is the whole build step; the 95 mismatches are the work.

**Why the floor is 0 and not 3:** the runtime currently emits **731 lines on
swf9/10/11/12 and 735 on swf30** against 1030–2353 expected — a pin, i.e. the
emitter does not describe the events classes at all yet, so descriptor tables
alone may not be sufficient; the classes also have to be registered and gated.
That is exactly the shape `w2-all-classes-display` solved in s16 for +6.

**s15's refutation still stands and must not be re-litigated:** all five are
`known_failure = true` upstream but their `output.ruffle.txt` is within 3–8
lines of Flash, so there is **no cheap `ruffle_matched` path**.

### T5 — `bounds_mode`'s two clusters (and two §17.4 magnitude refutations)

**GO (small). Floor 0, real +1, ceiling +1.** `avm2/bounds_mode` re-run at
HEAD is **16 diff lines**, and they are two mechanisms, not three:

**(a) `transform.pixelBounds` is WORLD space (6 rows).**

```
   9  // hitbox.getRect(hitbox)   → (x=-32.75, y=-32.75, w=65, h=65)
  10  // hitbox.transform.pixelBounds
- 11  (x=0,     y=0,     w=65, h=65)
+ 11  (x=-0.75, y=-0.75, w=65, h=65)
```

Ruffle: `pixel_bounds(mode) = world_bounds(mode) = bounds_with_transform(&local_to_global_matrix())`
(`display_object.rs:1366`). We are returning bounds in the *caller's* /
document-class space (the same numbers `getBounds(this)` gives), not stage
space. §17.4 calls this "10 rows in `bounds_mode`; a 0.75 px origin offset" —
**it is 6 rows, and the 0.75 is not a constant, it is the document class's own
stage offset** (R1).

**(b) `scaleX`/`scaleY` round-trip through a percentage (9 rows + 1).**

Every mismatched scale is exactly one ULP above naive f64 division, and
`value * 100.0 / 100.0` reproduces all three constants bit-for-bit:

| expression | naive f64 | `x*100/100` | expected |
|---|---|---|---|
| `200/65` | `3.076923076923077` | **`3.0769230769230775`** | `3.0769230769230775` |
| `100/65` | `1.5384615384615385` | **`1.5384615384615388`** | `1.5384615384615388` |
| `5/3` | `1.6666666666666667` | **`1.666666666666667`** | `1.666666666666667` |

Ruffle stores scale as `Percent(f64)` — `from_unit(u) = u * 100.0`,
`unit() = self.0 / 100.0` (`core/src/types.rs:5-20`) — and `set_width` /
`set_height` go through `set_scale_x(Percent::from_unit(new_scale_x))`
(`display_object.rs:1715`). §17.4 says "6 rows"; it is **9 in `bounds_mode`
alone** plus the `5/3` row (R3).

**Attack your own pricing before taking (b).** This changes **every**
`scaleX`/`scaleY` read in the corpus. Exactly-representable scales
(`scaleX = 2` → `2*100/100 = 2`) are unaffected, so the blast radius is only
non-dyadic ratios — but that is still a full-corpus A/B, not a canary. Take (a)
first; (b) is the half that can regress.

`bounds_mode` is `known_failure = true` upstream and sits in the avm2
suite-local ignore list — it is still **counted** in the graded number, so the
flip is worth +1.

### T6 — AVM2/loader near-pass smalls #3 (six unowned rows, none dispositioned)

**GO. Floor +3, real +4, ceiling +6.**

| row | miss | mechanism (evidence, graded this session) | strength |
|---|---|---|---|
| `avm2/displayobject_early_init` | 53 → really **3** | The 53 is a **1-line-offset cascade**. Expected emits `Caught error: ArgumentError: Error #2015: Invalid BitmapData.` three times (at expected lines 2, 10 and 14) and we emit it **zero** times; every other line matches, shifted. Constructing a `Bitmap` subclass whose linked `BitmapData` is invalid/unlinked must throw **#2015** and the fixture's `try` must catch it. Fix three throws → +1. | **STRONG** |
| `avm2/textfield_input_events` | 16 | Pure **ordering**: the `textInput` handler must observe the **old** text. Expected pairs are `New text: <empty>` / `R`; ours are `New text: R` / `<empty>`, for all six keypresses plus backspace and `!`. One rule: dispatch `textInput` *before* mutating the field, `change` after. | **STRONG** |
| `avm2/large_preload_image_from_bytes` | 6 | Pure **ordering**: `exitFrame in Test` must be emitted *before* the loader's `init` event; we emit it after `complete`. Same `avm2-loader-timing-is-executor-drain` family. Siblings `large_preload_from_url` (11) and `large_preload_from_bytes` (33) sit on the same axis and should be graded in the same slot. | **STRONG** |
| `from_shumway/as3-loader/loaderinfo/loaded-content-properties` | 12 | **Four property values, each printed three times.** `childSandboxBridge` and `parentSandboxBridge` must be **`null`**, we give `undefined`; `isURLInaccessible` must be **`true`**, we give `false`; `uncaughtErrorEvents` must be an `[object UncaughtErrorEvents]`, we give `undefined`. Nothing else in the 48-line sweep differs. | **STRONG** |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | 3 | The loaded child's own trace `from loadee: loaded` never appears at all and the remaining two lines shift up. `Loader.loadBytes` does not run the loadee's frame-1 script before dispatching `init`. Sibling of the `LoaderTest2` fix s16 landed. | **STRONG** |
| `avm2/appdomain_lookup_edge_cases` | 25 | **Cascade unlock.** We die at expected line 8 with an *uncaught* `#1065` out of `ApplicationDomain.getDefinition("<integerValue>")`; Flash raises **VerifyError #1107** there (the fixture prints `error: 1107` twice), which the test's `catch` handles, and 24 further lines follow. Line 7 (`hasDefinition("<integerValue>")` → `true` vs our `false`) is the same name-validation rule. | MED (cascade, so the ceiling is real but the floor is not) |

**Riders to grade in the same slot** once the `exitFrame`/`init` ordering lands:
`avm2/large_preload_from_url` (11), `avm2/large_preload_from_bytes` (33) and
`from_shumway/as3-loader/events/loader-events` (27 — which improved 31 → 27 in
s16 with nobody touching it) are all the same loader event-ordering axis. If
they follow, T6's ceiling rises to **+9**.

`loader-events` came back at the very end of the session (459 s of compile) and
**confirms the rider classification and splits off a second, cheaper defect**:

```
-  4  added instance3          - 19  construct instance4, parent: null
+  4  added instance2          + 18  construct null, parent: null
- 24  run frame 1 in instance2 - 35  instance4
+ 21  run frame 1 in null      + 36  null
```

* the **ordering** half is the T6 axis: loader `progress`/`complete` and
  `init`/`httpStatus`/`complete` must interleave with `enterFrame` /
  `exitFrame` / `run frame N` the way Flash orders them, and every one of the
  27 lines is a permutation, never a missing line;
* the **naming** half is separable and probably cheaper: a Loader-loaded child's
  display objects must receive auto-assigned `instanceN` names from the *shared*
  global instance counter. We give them `null` (four lines) and our counter is
  one behind on line 4 (`instance2` where Flash says `instance3`), i.e. the
  loaded child never advances it. Fixing only that half is worth 6 of the 27
  lines and is independent of the event order.


### T7 — the `#1065` missing-builtin-class cluster

Three rows, three absent classes, each killing its test on line 1:

| row | miss | missing | note |
|---|---|---|---|
| `avm2/stage_display_state` | 6 | `flash.events.FullScreenEvent` | **DISCREPANCY — re-baseline before pricing.** It **passes locally** at the graded SHA in graphics mode (run twice, once with `--recompile`), and its `test.swf`/`output.txt` are byte-identical to upstream `ruffle 437be1498`. But its `RecompiledABC/` dates from **Aug 6** and `--recompile` did **not** refresh it (mtimes unchanged), so the likeliest reading is that the stale local ABC makes the local PASS the false one; the alternative is a stale CI row (the `ActionOrderTest3/4`/`RegisterClassTest4` precedent §17.4 names). Do **not** count it in the floor either way. |
| `avm2/native_menu_basic` | 19 | `flash.display.NativeMenuItem` / `NativeMenu` | wants the full add/remove index semantics with `#1034`, `#2007`, `#2006` — M |
| `avm2/automation_classes` | 121 | `AutomationAction` | **not on local disk** (§3) |

Floor 0, real +1, ceiling +3. `stage_display_state` is the cheapest.

### T8 — `avm2/event_handler_exception` (stack-trace source locations)

**DEFER, family of one.** Six diff lines, re-run at HEAD:

```
- 	at Function/<anonymous>()[Z:\tests\tests\swfs\avm2\event_handler_exception\Test.as:10]
+ 	at Function/<anonymous>()
- 	at flash.events::EventDispatcher/dispatchEventFunction()
+ 	at flash.events::EventDispatcher/dispatchEvent()
```

Two things: stack-trace frames must carry the `[file:line]` suffix, which comes
from the ABC's `debugfile` / `debugline` opcodes (we record neither), and there
is one missing intermediate frame, `dispatchEventFunction()` above
`dispatchEvent()`. **Only two corpus fixtures contain a `[Z:\tests` stack
suffix and the other (`avm2/coerce_property`) already passes**, so the whole
debug-info feature buys exactly +1. Defer unless a slot has room.

### T9 — ignore-list hygiene (0 flips, but it has cost four sessions)

See §5 for the ready-to-apply worklist (file + line + action).
### T10 — the `#2007 targetCoordinateSpace` cascade

**GO (small). Floor 0, real +1, ceiling +2.** s15 filed this as "riders on the
Matrix3D `#2007` helper"; that helper landed in s15 and neither row moved,
because these are `getBounds`/`getRect` sites. Re-graded locally this session,
and both are **cascade rows, not rewrites**:

```
avm2/displayobject_getrect  (14 missing of 16)
   1  [object Shape]
   2  [object MorphShape]
-  3  (x=33.25, y=25.7, w=67.15, h=75.95)
+  3  TypeError: Error #2007: Parameter targetCoordinateSpace must be non-null.
+  4  	at flash.display::DisplayObject/getBounds()
```

Every one of the 14 lines behind the throw is a plain rect string. The fixture
has already printed its two display objects, so they exist — our `getBounds`
argument coercion is producing `null` for a `targetCoordinateSpace` Flash
accepts (the `MorphShape` on line 2 is the obvious suspect). One coercion fix
unlocks 14 lines.

`from_shumway/acid/acid-shapes` (120 missing of 120) carries the identical
signature and dies at **actual line 7 of 120**, so it is the same shape of
unlock, not a 120-line rewrite. Grade it in the same slot.

---

## 2. Handed off this session — listed, NOT re-priced

| cluster | rows | agent | anything this board adds |
|---|---|---|---|
| `avm2/method_association`, `avm2/supercalls_coerce`, `avm2/displayobject_hittestpoint_boundary` | 3 | `w2-avm2-smalls` | **R5:** the "missing leading blank line" in `hittestpoint_boundary` is **not** a harness bug. 16 corpus fixtures have an `output.txt` starting with a blank line and **13 of them `pass`**. It is a per-test first-trace difference, so grade the fixture's own first `trace()`, don't go looking in `verify_output.py`. |
| `avm2/scope_optimizations` | 1 | `w2-scope-opt` | — |
| `avm2/mouse_pick_avm1_root` (1 line), `avm2/mouse_pick_loader_avm1` (37) | 2 | `w2-crossvm-legE` | — |
| `avm1/sound_load_*` ×7 (new upstream) + `from_gnash` `Sound-v6/-v7/-v8` | 10 | `w1-sound-load` | **Mechanism found for all three gnash rows:** the only diff is `typeof(s.checkPolicyFile) == 'boolean'` → we return `undefined`. `grep -rn checkPolicyFile SWFModernRuntime/src` shows it on **NetStream**'s prototype (`action.c:37674`, deliberately `UNDEFINED`) and on the AVM2 `LoaderContext`, but **nowhere on AVM1 `Sound`**. Adding `Sound.prototype.checkPolicyFile = false` (a real Boolean) is a one-property add worth **+3**. Also: of the 7 new `sound_load_*`, 3 already `pass` (`multiple_instances`, `stops_when_dereferenced`, `mixed_attach_load`); the 4 failures are `sound_load_props` (15/111) and three `*_remote` rows (1, 1, 4) that need the localhost fixture server. |
| timeline-order arc ×12 (`action_order` ×7, `timeline/missing_frame_scripts`, `avm1/looping_child_swf{5,9,32}`, `avm2/button_nested_frame_simple`) | 12 (**+1 proposed**) | `w1-timeline-order` | Re-confirmed at the baseline: `button_nested_frame_simple` still miss 0 / 27 exp / 39 act; `looping_child_swf{5,9,32}` still byte-identical to each other at 141 exp / 207 act. **New 13th row proposed: `timeline/frame_script_cleanup_goto2` (22 lines).** Graded locally: after the goto, whole blocks of `Container`/`Child`/`GrandChild`/`LeafChild` framescripts come out in the wrong order (we emit the `Main frame2` block where Flash emits `Child frame1` / `GrandChild addFrameScript` / `GrandChild frame1` / `LeafChild frame1` first) — the same nested-sprite advance-order mechanism as `looping_child_*`. |

---

## 3. Upstream drift

**Ten new names arrived between the s16 and s17 grading runs** — exactly the ten
§16's board predicted:

| new test | status | lines |
|---|---|---|
| `avm1/sound_load_multiple_instances` | **pass** | 19/19 |
| `avm1/sound_load_stops_when_dereferenced` | **pass** | 0/0 |
| `avm1/sound_mixed_attach_load` | **pass** | 13/13 |
| `avm1/sound_load_props` | output_mismatch | 96/111 |
| `avm1/sound_load_multiple_remote` | output_mismatch | 2/6 |
| `avm1/sound_load_start_remote` | output_mismatch | 0/1 |
| `avm1/sound_load_streaming_stop_remote` | output_mismatch | 2/3 |
| `avm2/matrix3d_determinant` | output_mismatch | 149/182 |
| `avm2/matrix3d_precision` | output_mismatch | 5/25 |
| `avm2/matrix3d_raw_data` | output_mismatch | 28/33 |

Denominator **4443 → 4453**, effective **+3** from the drift alone.

**Three regressions, all fixture drift, none a code regression.**
`from_gnash/actionscript.all/Sound-v6/-v7/-v8` moved `ruffle_matched →
output_mismatch` when upstream rewrote their `output.ruffle.txt`: Ruffle now
passes the `checkPolicyFile` assertions, so our diff stopped being a subset of
its diff. The underlying gap (8 lines each) is unchanged and is one missing
property — see §2, relayed to `w1-sound-load`.

**Only 3 failing rows improved between the two baselines** (all still failing):
`displayobject_scrollrect` 14 → 6 (s16 twip quantization),
`loader_duplicate_class` 25 → 19, `as3-loader/events/loader-events` 31 → 27.

**The LOCAL `ruffle-tests/tests/swfs` tree is still stale and is NOT a drift
oracle** (unchanged from s16 §3, re-verified). Missing locally and therefore
ungradable without a download: **`avm2/matrix3d_determinant`,
`avm2/matrix3d_precision`, `avm2/matrix3d_raw_data`** (T2's whole cluster),
plus `avm2/automation_classes` (121/122) and `avm2/textblock_recreateline`
(139/180). Anyone briefed on T2 or T7 must run the downloader first.

---

## 4. The error-signature axis

18 of the 136 non-effective rows carry an `error_signature`:

| signature | rows | disposition |
|---|---|---|
| `#1065: Variable {FullScreenEvent, NativeMenuItem, AutomationAction} is not defined` | `stage_display_state`, `native_menu_basic`, `automation_classes` | **T7** |
| `#1065: Variable <integerValue> is not defined` | `appdomain_lookup_edge_cases` | **T6** (should be `#1107`) |
| `#2007: Parameter targetCoordinateSpace must be non-null` | `avm2/displayobject_getrect` (14/16), `from_shumway/acid/acid-shapes` (120/120) | **T10** — re-graded locally: `displayobject_getrect` prints its two display objects then dies on *expected line 3*, and all 14 lines behind the throw are plain rect strings. Cascade unlock, not a rewrite. |
| `#1006: computeSpectrum is not a function` | `avm2/audio_computespectrum`, `audio/aac`, `audio/g711` | **NO-GO** (real media decode) |
| `#1006: loadCompressedDataFromByteArray is not a function` | `avm2/sound_load_multiple` | ignore-listed host-I/O bucket |
| `#1121 duplicate method body` | `verify_method_info_duplicate` | **NO-GO**, `ACCEPTED_DIFFS.md:114` (fixing it demotes the *passing* `_oob` — re-confirmed by the s16 post-run fix) |
| `#1034 … cannot convert Object@…` | `avm2/loader_load` | **NO-GO** (hashbrown order) |
| `#1034 … cannot convert flash.display::MovieClip … to DuplicateClass` | `avm2/loader_duplicate_class` | DEFER — the real cause is `getChildAt()` `#2006` inside the child SWF's symbol-class constructor: the child timeline's children are not placed before the class ctor runs |
| `#2067 ExternalInterface not available` | `avm2/external_interface` | 102/105 |
| `#1009 …` misc | `from_shumway/esc`, `large_preload_from_bytes` | `esc` is ignore-listed and its `output.txt` is a **timing line** (`388 bytes in 78 ms`) → unpassable as written |
| `Error: Exception in first listener` | `avm2/event_handler_exception` | **T8** |
| `RangeError #2006` | `avm2/avm1_root` | dispositioned (`RUFFLE_VS_FLASH`, `_level-61440`) |

---

## 4b. The near-pass well, regenerated — every failing row at `miss ≤ 60`, with its owner

`miss = expected_lines − matching_lines`. `results.json` truncates the stored
outputs at ~51 lines, so the `lines` triple is the reliable field and the text
is not. **Sort by both** `miss` *and* `actual − expected`: two rows here have
`miss == 0` and fail purely on extra output, and `avm2/displayobject_early_init`
has `miss == 53` and three real defects.

| miss | exp | act | test | owner |
|---:|---:|---:|---|---|
| 0 | 27 | 39 | `avm2/button_nested_frame_simple` | HO `w1-timeline-order` |
| 0 | 7 | 12 | `from_gnash/misc-swfc.all/sound` | NO-GO (§6) |
| 1 | 115 | 115 | `avm1/native_objects_swf6` | NO-GO (§6) |
| 1 | 1 | 0 | `avm1/sound_load_start_remote` | HO `w1-sound-load` |
| 1 | 3 | 2 | `avm1/sound_load_streaming_stop_remote` | HO `w1-sound-load` |
| 1 | 2 | 2 | `avm2/mouse_pick_avm1_root` | HO `w2-crossvm-legE` |
| 1 | 4 | 4 | `avm2/scope_optimizations` | HO `w2-scope-opt` |
| 1 | 2 | 1 | `avm2/verify_method_info_duplicate` | NO-GO (§6) |
| 1 | 20 | 20 | `from_avmplus/recursion/pcre_find_fixedlength` | NO-GO (§6) |
| 1 | 1 | 0 | `from_avmplus/regress/bug_483783` | NO-GO (§6) |
| 1 | 2 | 2 | `from_shumway/bitmapdata/getpixel-from-embedded` | §6b |
| 1 | 1 | 0 | `text/links_in_scrolled_text` | HOLD (s16 patch, R4) |
| 2 | 3 | 1 | `avm1/sandbox_type_remote` | NO-GO (§6) |
| 2 | 128 | 128 | `avm2/loader_load` | NO-GO (§6) |
| 2 | 3 | 1 | `avm2/sandbox_type_remote` | NO-GO (§6) |
| 2 | 2 | 0 | `avm2/swz` | NO-GO (§6) |
| 2 | 2 | 13 | `from_shumway/esc` | NO-GO (§6) |
| 3 | 7 | 4 | `avm1/geturl` | NO-GO (§6) |
| 3 | 9 | 9 | `avm2/bom` | NO-GO (§6) |
| 3 | 4 | 3 | `from_shumway/as3-loader/LoaderLoadBytesTest` | **T6** |
| 4 | 6 | 8 | `audio/g711` | NO-GO (§6) |
| 4 | 6 | 3 | `avm1/sound_load_multiple_remote` | HO `w1-sound-load` |
| 4 | 4 | 0 | `avm2/loader_applicationDomain` | NO-GO (§6) |
| 4 | 5 | 4 | `avm2/method_association` | HO `w2-avm2-smalls` |
| 4 | 16 | 16 | `from_avmplus/ecma3/Statements/eforin_001` | NO-GO (§6) |
| 4 | 7 | 3 | `mixed_avm/avm1_loads_avm2` | AVM1-child remainder |
| 5 | 16 | 12 | `avm1/shared_stack` | §6b |
| 5 | 33 | 33 | `avm2/matrix3d_raw_data` | **T2** |
| 5 | 5 | 0 | `avm2/selection_onsetfocus_mixed_avm` | DEFER leg F |
| 6 | 35 | 30 | `avm1/load_vars` | NO-GO (§6) |
| 6 | 338 | 338 | `avm1/movieclip_hittest_shapeflag` | NO-GO (§6) |
| 6 | 33 | 33 | `avm2/displayobject_scrollrect` | **T3** |
| 6 | 11 | 10 | `avm2/event_handler_exception` | **T8** |
| 6 | 25 | 25 | `avm2/large_preload_image_from_bytes` | **T6** |
| 6 | 6 | 2 | `avm2/stage_display_state` | **T7** (re-baseline) |
| 6 | 12 | 12 | `avm2/stage_scale_factor` | NO-GO (§6) |
| 6 | 32 | 32 | `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | HO `w1-timeline-order` |
| 7 | 7 | 0 | `avm1/loadvariables_method` | NO-GO (§6) |
| 7 | 8 | 8 | `avm2/supercalls_coerce` | HO `w2-avm2-smalls` |
| 8 | 17 | 17 | `avm1/xml_getbytes` | NO-GO (§6) |
| 8 | 8 | 0 | `avm2/id3_info` | §6b |
| 8 | 121 | 121 | `from_gnash/actionscript.all/Sound-v6` | HO `w1-sound-load` |
| 8 | 121 | 121 | `from_gnash/actionscript.all/Sound-v7` | HO `w1-sound-load` |
| 8 | 121 | 121 | `from_gnash/actionscript.all/Sound-v8` | HO `w1-sound-load` |
| 8 | 18 | 18 | `from_gnash/misc-swfc.all/matrix_accuracy_test1` | NO-GO (§6) |
| 9 | 560 | 560 | `from_gnash/actionscript.all/array-v5` | NO-GO (§6) |
| 10 | 304 | 304 | `avm1/globals_swf5` | NO-GO (§6) |
| 10 | 11 | 1 | `avm2/netstream_play_stop_replay` | NO-GO (§6) |
| 10 | 10 | 10 | `from_avmplus/ecma3/Statements/eforin_002` | NO-GO (§6) |
| 10 | 22 | 27 | `timeline/missing_frame_scripts` | HO `w1-timeline-order` |
| 11 | 27 | 17 | `avm2/large_preload_from_url` | **T6** rider |
| 12 | 900 | 900 | `avm2/soundmixer_soundtransform` | NO-GO (§6) |
| 12 | 93 | 95 | `from_gnash/misc-ming.all/DrawingApiTest` | NO-GO (§6) |
| 12 | 48 | 48 | `from_shumway/as3-loader/loaderinfo/loaded-content-properties` | **T6** |
| 13 | 18 | 16 | `from_gnash/misc-swfc.all/movieclip_destruction_test3` | §6b |
| 14 | 16 | 5 | `avm2/displayobject_getrect` | **T10** |
| 15 | 18 | 24 | `audio/aac` | NO-GO (§6) |
| 15 | 111 | 111 | `avm1/sound_load_props` | HO `w1-sound-load` |
| 16 | 269 | 269 | `avm2/bounds_mode` | **T5** |
| 16 | 16 | 26 | `avm2/loader_try_click_root` | AVM1-child remainder |
| 16 | 16 | 1 | `avm2/netstream_play_flv` | NO-GO (§6) |
| 16 | 19 | 7 | `avm2/sound_load_multiple` | NO-GO (§6) |
| 16 | 25 | 24 | `avm2/textfield_input_events` | **T6** |
| 18 | 65 | 65 | `avm2/displayobject_hittestpoint_boundary` | HO `w2-avm2-smalls` |
| 19 | 48 | 48 | `avm2/loader_duplicate_class` | DEFER §6b |
| 19 | 19 | 3 | `avm2/native_menu_basic` | **T7** |
| 20 | 25 | 25 | `avm2/matrix3d_precision` | **T2** |
| 20 | 34 | 37 | `from_avmplus/e4x/Expressions/e11_1_4` | **UNOWNED** |
| 21 | 644 | 644 | `from_gnash/actionscript.all/array-v6` | NO-GO (§6) |
| 21 | 23 | 24 | `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | NO-GO (§6) |
| 22 | 89 | 89 | `avm2/displayobject_transform` | **T1** |
| 22 | 34 | 29 | `timeline/frame_script_cleanup_goto2` | HO `w1-timeline-order` **(new)** |
| 24 | 24 | 20 | `from_gnash/misc-ming.all/action_order/action_execution_order_test6` | HO `w1-timeline-order` |
| 25 | 32 | 11 | `avm2/appdomain_lookup_edge_cases` | **T6** |
| 25 | 32 | 28 | `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` | HO `w1-timeline-order` |
| 27 | 36 | 37 | `from_shumway/as3-loader/events/loader-events` | **T6** rider (graded late — see T6) |
| 31 | 32 | 12 | `from_gnash/misc-ming.all/PrototypeEventListeners` | **UNOWNED** |
| 32 | 40 | 24 | `from_gnash/misc-swfc.all/movieclip_destruction_test4` | **UNOWNED** |
| 33 | 51 | 25 | `avm2/large_preload_from_bytes` | **T6** rider |
| 33 | 182 | 182 | `avm2/matrix3d_determinant` | **T2** |
| 35 | 936 | 921 | `from_gnash/actionscript.all/MovieClip-v6` | NO-GO (§6) |
| 35 | 969 | 954 | `from_gnash/actionscript.all/MovieClip-v7` | NO-GO (§6) |
| 36 | 1371 | 1371 | `avm1/bitmap_data_thorough/pixelDissolve` | NO-GO (§6) |
| 36 | 42 | 57 | `from_gnash/misc-ming.all/register_class/RegisterClassTest4` | NO-GO (§6) |
| 37 | 42 | 40 | `avm2/mouse_pick_loader_avm1` | HO `w2-crossvm-legE` |
| 38 | 84 | 83 | `avm2/dependent_strings` | NO-GO (§6) |
| 45 | 51 | 58 | `from_gnash/misc-ming.all/action_order/ActionOrderTest5` | HO `w1-timeline-order` |
| 46 | 6335 | 6335 | `avm1/date` | NO-GO (§6) |
| 46 | 58 | 34 | `avm2/avm1_root` | dispositioned (`_level-61440`) |
| 48 | 49 | 2 | `avm1/stylesheet_load` | NO-GO (§6) |
| 48 | 49 | 31 | `avm2/focus_events_mixed_avm_edittext` | DEFER leg F |
| 49 | 49 | 1 | `avm2/netstream_seek_flv` | NO-GO (§6) |
| 50 | 654 | 654 | `from_gnash/actionscript.all/array-v7` | NO-GO (§6) |
| 50 | 654 | 654 | `from_gnash/actionscript.all/array-v8` | NO-GO (§6) |
| 53 | 54 | 51 | `avm2/displayobject_early_init` | **T6** |
| 54 | 64 | 105 | `from_gnash/misc-ming.all/action_order/ActionOrderTest4` | HO `w1-timeline-order` |
| 58 | 887 | 887 | `avm2/simplebutton_soundtransform` | **UNOWNED** |
| 58 | 62 | 73 | `from_gnash/misc-ming.all/action_order/ActionOrderTest3` | HO `w1-timeline-order` |

**Only four rows in the whole well are genuinely unowned after this board** (`as3-loader/events/loader-events` was the fifth until its late local grade moved it under T6):

| row | miss / exp | what it is |
|---|---|---|
| `from_avmplus/e4x/Expressions/e11_1_4` | 20 / 34 | E4X expression semantics; we emit 37 lines for 34 expected, so it is over-emitting, not truncating. Unprobed. |
| `from_gnash/misc-ming.all/PrototypeEventListeners` | 31 / 32 | We emit **12** of 32 lines — an early abort, so this is a cascade, not 31 independent defects. Cheapest of the five to probe. |
| `from_gnash/misc-swfc.all/movieclip_destruction_test4` | 32 / 40 | Sibling of `movieclip_destruction_test3` (§6b); same nested-clip removal mechanism, so they are one lead of 2 rows. |
| `avm2/simplebutton_soundtransform` | 58 / 887 | Sibling of the ignore-listed `avm2/soundmixer_soundtransform` (12 / 900). 58 of 887 lines — a `SoundTransform` property-surface sweep, not a mixer job. Worth a look because its sibling is 12 lines from passing. |

Everything else at `miss ≤ 60` is priced above, handed off, or on the standing
NO-GO list — i.e. **the near-pass well is now a closed inventory**, which is the
same state `polish-sweep-arc.md` §"polish-sweep" reached for the s10 well.


---

## 5. Ignore-list hygiene — ready-to-apply worklist for a doc/hygiene wave-2 agent

106 entries across 8 tracked `ignored_tests.txt` files. Every classification
below is mechanical: status read from `c7b284034`'s blobs; "rationale" =
the name appears in one of the four disposition docs **or** in an inline
comment in its own ignore file **or** the upstream `test.toml` carries the
`known_failure = true` / `ignore = true` flag its bucket claims.

### 5a. PRUNE — `pass` in every suite where they appear, meeting the files' own 2026-08-01 criterion (19 entries)

*(20 entries meet the raw `pass` test; `netstream_play_flv_screen` is the 20th and is a trap — see 5b.)*

| file:line | entry | status | action |
|---|---|---|---|
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:49` | `localconnection` | `pass` | **delete** — NEW this session (s16 `w2-avm1-child` landed the AVM1↔AVM2 bridge). The bucket comment above it still says "not re-costed"; update it. |
| `.../avm2/ignored_tests.txt:120` | `int_toprecision` | `pass` | **delete** (carried over from s16, still undone) |
| `.../avm2/ignored_tests.txt:128` | `uint_toprecision` | `pass` | **delete** (ditto) |
| `.../from_shumway/ignored_tests.txt:24-39` | the 16 `fuzz/*` entries | all `pass` | **delete all 16**, and rewrite the bucket header (it asserts "All 16 re-confirmed still failing on 2026-08-01" — false since s15/s16 fixed the AVM1 timeline-order block) |

### 5b. DO NOT PRUNE despite being `pass` (2 entries — both are traps)

| file:line | entry | why it stays |
|---|---|---|
| `ruffle-tests/ignored_tests.txt:72` | `netstream_play_flv_screen` | `pass` on trace, but this is a **GLOBAL** entry = an IMAGE-axis disposition (`image_triage.py` returns `image_axis=True` for global entries). Trap 1 in that file's own header. Its image comparison still fails. |
| `.../avm2/ignored_tests.txt:135` | `bytearray_oom` | `pass`, but records an UPSTREAM `ignore = true` in its own `test.toml` (verified), not our scope call |

### 5c. INERT — no results row at all (3 entries)

`ruffle-tests/ignored_tests.txt:92` `shared_object`, `:93` `shared_object_self_ref`
(both ship `output1.txt`/`output2.txt`, no `output.txt`, so `discover_tests()`
skips them) and `.../from_shumway/avm1/ignored_tests.txt:19` `hitarea`.
All three already carry an inline comment saying so. **Action: none** — but a
future prune must not read "no status" as "nonexistent".

### 5d. NO RATIONALE ANYWHERE — write one, or delete (9 entries, + 5 flag-backed-but-reason-free)

Not in any disposition doc, not named in an inline comment, no upstream flag.
(The five `fuzz/*` rows that also land here are covered by 5a and are omitted.)

| file:line | entry | status | proposed action |
|---|---|---|---|
| `ruffle-tests/ignored_tests.txt:45` | `load_vars` | `output_mismatch` 30/35 | bucket says "require network connections, HTTP POST or browser-level form submission" — but the net/socket tranches landed. **Re-triage or write the 6-line residual up.** |
| `ruffle-tests/ignored_tests.txt:46` | `loadvariables_method` | `output_mismatch` 0/7 | same bucket; we emit **zero** lines. Write up or re-triage. |
| `ruffle-tests/ignored_tests.txt:47` | `stylesheet_load` | `output_mismatch` 2/49 | same bucket. |
| `ruffle-tests/ignored_tests.txt:105` | `sandbox_type_remote` | `output_mismatch` in **both** avm1 and avm2 (2/3 each) | sits under "Infrastructure not yet available (network/IPC)"; two lines from passing. Grade it before writing it off. |
| `.../avm2/ignored_tests.txt:48` | `audio_computespectrum` | `output_mismatch` | host-I/O bucket header covers the *bucket*; add the per-name line (real FFT over decoded PCM). |
| `.../avm2/ignored_tests.txt:51` | `netstream_play_stop_replay` | `output_mismatch` | ditto |
| `.../avm2/ignored_tests.txt:52` | `netstream_seek_flv` | `output_mismatch` | ditto |
| `.../avm2/ignored_tests.txt:53` | `sound_load_multiple` | `output_mismatch`, `#1006 loadCompressedDataFromByteArray` | ditto |
| `.../avm2/ignored_tests.txt:56` | `soundmixer_soundtransform` | `output_mismatch` 888/900 | **12 lines from passing** — this one should be re-triaged, not documented |
| `.../from_shumway/ignored_tests.txt:51,52,54,55,56` | `MaskTest-3`, `avm1movie`, `flash_net_SharedObject`, `flash_text_TextField2`, `getobjectsunderpoint` | all `ruffle_matched` | the bucket header explicitly declines to give a per-test reason ("a real divergence list, not a capability list"). All five carry upstream `known_failure = true` (verified), so they are *backed*, but a one-line reason each would stop them heading every regeneration. |

### 5e. Backed ONLY by a verified upstream flag (46 entries) — leave alone

Every one of the 33 `test.toml`s behind the avm2 "Upstream known_failure = true"
bucket and the two `ignore = true` entries was opened and checked this session:
**all 33 carry the flag their bucket claims.** No action.

### 5f. Refutation of the s16 count (R8)

The s16 board reported "**34 entries have no rationale in any of the four
disposition docs**" and named `from_gnash/misc-swfc.all/{sound,
matrix_accuracy_test1}`, `argstest-v6/-v7/-v8`, `array-v5` and
`register_class/RegisterClassTest4` among them. Those six all carry **detailed
inline rationales in their own ignore files** (7–12 comment lines each, with
plan-doc cross-references). Counting doc-mentions alone over-reports by ~3×.
The defensible number is **15 with no rationale of any kind**, of which 5 are
prune candidates anyway → **9 real documentation gaps** (5d), plus 5 more
(from_shumway) that are flag-backed but reason-free.

---

## 6. §17.4 lead status, re-verified at the baseline

| §17.4 item | status now | ruling |
|---|---|---|
| `text/links_in_scrolled_text` HELD patch | re-run at HEAD: still exactly 1 line, expected `Success!`, we emit a **blank line** | **HOLD stands, completion mechanism REWRITTEN (R4)** |
| `avm2/method_association` (+1, 2 commits) | unchanged, 4/5 | **HANDED OFF** |
| `avm2/scope_optimizations` (+1, recompiler) | unchanged, 1/4 | **HANDED OFF** |
| `avm2/supercalls_coerce` (+1) | unchanged, 7/8 | **HANDED OFF** |
| `all_classes/events` ×5 "0 flips" | still pinned at 731/731/731/731/735 actual | **REFUTED → T4, real +3** |
| `avm2/number_convert_errors` | unchanged, 831/871 | **DEFER stands** (structural) |
| cross-VM hit test leg E | unchanged | **HANDED OFF** |
| cross-VM focus / Tab / `Selection` leg F | `selection_onsetfocus_mixed_avm` 5/5 (we emit **zero**), `focus_events_mixed_avm_edittext` 48/49 | **DEFER stands** — no cheap slice; all three requirements together |
| timeline-order arc ×12 | unchanged | **HANDED OFF** |
| committed scroll rect | 6 lines, all one mechanism | **GO → T3** |
| `displayobject_hittestpoint_boundary` "not a geometry row" | agreed, but see R5 on the blank line | **HANDED OFF** |
| `transform.pixelBounds` "10 rows" | **6 rows** | **magnitude REFUTED (R1) → T5(a)** |
| quality-scaled `concatenatedMatrix` "22 + 5 rows" | **22 rows in `displayobject_transform`, 0 in `bounds_mode`** | **magnitude REFUTED (R2) → T1** |
| `width=`/`height=` setter ULPs "6 rows" | **9 rows + a 10th**, mechanism identified exactly | **magnitude REFUTED (R3) → T5(b)** |
| `Stage.localToGlobal` ignores the Stage's own matrix | only `stage_scale_factor` exercises it, and that test needs a simulated 2× display | **NO-GO stands** |
| standing NO-GOs (`bug_483783`, gnash `array-v5..v8` / `MovieClip-v6/7/8` / `argstest-v6/7/8`, `eforin_001/002`, `set_property_values/swf4-7`, `loader_load`, `bom`, `swz`, `loader_applicationDomain`, `verify_method_info_duplicate`, `pcre_find_fixedlength`, `misc-swfc.all/sound`) | all unchanged at the baseline | **NO-GO — not re-costed** |
| ignore-list hygiene | undone | **GO → T9 / §5** |

---

## 6b. Graded but NOT worth an s17 slot (unowned, evidence recorded so nobody re-grades them)

| row | miss | what it actually is |
|---|---|---|
| `avm1/shared_stack` | 5 | A child SWF's frame-2 pass truncates. Expected `in child frame 2/1:`, we print `in frame 2/1:` and then stop after 12 of 16 lines. AVM1 multi-SWF target resolution + a lost second pass. MED. |
| `avm2/id3_info` | 8 | We emit exactly **one blank line**. Needs real ID3v2 tag parsing out of the mp3 into a `Sound.id3` `ID3Info` object (album/artist/comment/genre/songName/track/year). All-or-nothing, MED. |
| `from_gnash/misc-swfc.all/movieclip_destruction_test3` | 13 | A nested clip is **not removed at frame 10** — the two `nestedMovieClip removed` / `actions here should not be executed` lines never fire and three assertions invert (`getDepth()` 10 vs −32779, `typeof` movieclip vs undefined, `as_order` `0+` vs `0+1+2+`). Timeline RemoveObject on a nested clip; belongs with the timeline arc but is `swfc`-flavoured. MED. |
| `from_shumway/bitmapdata/getpixel-from-embedded` | 1 | `200d04` vs our `220a06` — one embedded-image pixel, per-channel delta (+2, −3, +2). `decoder-tolerance-read-the-oracle` territory; a +1 for a decoder rewrite. |
| `avm2/loader_duplicate_class` | 19 | Improved 25 → 19 in s16. Real cause: `getChildAt()` throws `#2006` **inside** the child SWF's `DuplicateClass` constructor, so `this.childFromDomainChild` is `null` and the `#1034` follows — the child SWF's timeline children are not placed before its symbol-class constructor runs. Child-movie construction order, not a domain bug. M. |

---

## 7. Soft `[trace-ign]` rows whose image comparison ALSO fails

A suite-local `ignored_tests.txt` entry says nothing about the pixels
(`image_triage.py` returns `image_axis=False` for suite-local lists — "kept on
the board"). Six such rows fail their image comparison at the baseline:

| row | trace | image outliers / limit | excess | free pixel flip? |
|---|---|---|---|---|
| `avm2/displayobject_scrollrect` | output_mismatch | 4 / 0 | **4** | **YES — the smallest excess on the image board.** Rides T3. |
| `avm2/displayobject_hittestpoint_boundary` | output_mismatch | 976 / 900 | **76** | **Plausible** — 8 % over. Rides the handed-off shape-hit-test edge rule. |
| `avm2/graphics_draw_path` | **ruffle_matched** (already effective) | 764 / 0 | 764 | **PIXEL-ONLY lead** — no trace value, but it is an unowned image row |
| `avm2/netstream_seek_flv` | output_mismatch | 40 943 / 271 | 40 672 | NO-GO (real decoder) |
| `avm2/netstream_play_flv` | output_mismatch | 229 724 / 0 | 229 724 | NO-GO (documented, `ACCEPTED_DIFFS` Cat 9) |
| `avm2/stage_scale_factor` | output_mismatch | 1 912 924 / 0 | 1 912 924 | NO-GO (needs a simulated 2× display) |

Three more soft rows have **passing** image comparisons and should be left
alone: `avm2/blend_transform`, `from_shumway/MaskTest-3`,
`from_shumway/flash_text_TextField2`.

---

## 8. Refutations (yield)

1. **R1 — `transform.pixelBounds` is 6 rows, not 10**, and the mechanism is not
   "a 0.75 px origin offset" but the wrong coordinate space: Ruffle's
   `pixel_bounds` is `world_bounds`, i.e. `bounds_with_transform(&local_to_global_matrix())`.
2. **R2 — the quality-scaled `concatenatedMatrix` cluster has no `bounds_mode`
   members.** §17.4 priced "22 rows in `displayobject_transform`, 5 more in
   `bounds_mode`'s neighbours". `bounds_mode`'s 16 diff lines are 6 `pixelBounds`
   + 9 scale-ULP + 1 `getBounds` rect; **zero** are `concatenatedMatrix`. T1 is
   a +1, not a +2.
3. **R3 — the `width=`/`height=` ULP cluster is 9 rows, not 6, and its mechanism
   is now closed**: Ruffle's `Percent` type round-trips scale through
   `×100` / `÷100` (`core/src/types.rs:5-20`). All three observed constants
   (`3.0769230769230775`, `1.5384615384615388`, `1.666666666666667`) are
   reproduced bit-exactly by that round trip and by nothing else.
4. **R4 — `links_in_scrolled_text`'s "phantom empty 15th line" is
   Ruffle-CANONICAL, not our artefact.** `core/src/html/text_format.rs:1072`
   pushes `HTML_NEWLINE` on **every** `</p>`, the last one included; the field's
   HTML is 14 `<p>` elements, so Ruffle's text also ends in `\n`. And
   `core/src/html/layout.rs:156` splits on `[\n, \r, \t]`, so the trailing `\n`
   yields a final **empty line** in Ruffle's layout too. Therefore §17.4's
   branch "if Flash says 7, exclude the phantom line from the scroll window"
   would move us **away** from the oracle. **Rewritten completion mechanism:**
   our `maxscroll = 8` is very likely correct; grade the *click's* target line
   against the layout's per-line `offset_y` (Ruffle
   `EditText::maxscroll`/`bottom_scroll`, `edit_text.rs:1006`/`:1035`, both
   measure against `bounds.height() - GUTTER*2`, not against a line count).
   The remaining suspect is our line-height/leading, not the line inventory.
5. **R5 — the "missing leading blank line" is not a harness bug.** 16 corpus
   fixtures have an `output.txt` whose first line is blank; **13 of them pass**.
   Only `loader_duplicate_class`, `displayobject_hittestpoint_boundary` and
   `audio_computespectrum` fail that way, and each for its own reason.
6. **R6 — `all_classes/events` is not a "0 flips, correctness-only" item.** It
   is the last failing `all_classes` package, the model grades at 95 element
   mismatches against 0 for the landed `flash.display`, and the two defects
   behind the 95 are an `uri=` attribute on interface methods and constructor
   arity gating.
7. **R7 — the s16 board's baseline commit was wrong** (4269, not 4298, at
   `3db858cbc`); the graded blobs live at the results merge `82ec2a359`.
8. **R8 — "34 unbacked ignore entries" over-reports by ~3×** (§5f). The
   defensible figure is 15 with no rationale of any kind, 9 of them actionable
   (plus 5 that are flag-backed but reason-free).
9. **R9 — a new prune candidate the s16 sweep could not have seen:**
   `avm2/ignored_tests.txt:49 localconnection` is `pass` as of s16's cross-VM
   bridge.
10. **R10 — `netstream_play_flv_screen` is a false prune candidate**: it is
    `pass` on trace but its GLOBAL entry is the disposition for a still-failing
    image comparison.
11. **R11 — `avm2/stage_display_state` may be a false row in the baseline.** It
    passes locally at the graded SHA in graphics mode (twice, once with
    `--recompile`) with a fixture byte-identical to upstream, yet the graded CI
    row is `output_mismatch` with `#1065 FullScreenEvent`. Its `RecompiledABC/`
    is dated Aug 6 and `--recompile` did **not** refresh it, so the stale local
    ABC is the likeliest cause of the false *local* pass — but the alternative
    (a stale CI row, the `ActionOrderTest3/4` precedent) has to be excluded in
    CI before anyone prices it. **Corollary worth keeping: `--recompile` does
    not always regenerate `Recompiled*` for an AVM2 test.**
12. **`avm2/displayobject_early_init` is a 3-line test, not a 53-line one.**
    Sorting the well by `expected − matching` puts it at 53; the actual defect
    is three missing `#2015 Invalid BitmapData` throws and a one-line offset.
    A cascade row can look 17× more expensive than it is — always diff the
    *aligned* text, never the counter.

---

## 9. Method notes for the wave-2 briefs

- `SWFRECOMP_COMPILE_TIMEOUT=2400` was mandatory: single AVM2 tests compiled in
  **91 s** (`displayobject_scrollrect`), **323 s** (`links_in_scrolled_text`) and
  **459 s** (`from_shumway/as3-loader/events/loader-events`) at load average
  25–33. The stock 300 s cap would have reported the last two as false
  `COMPILE_FAIL`s — the 459 s row is the new high-water mark for this corpus.
- `results.json` truncates `expected_output`/`actual_output` at ~51 lines with a
  `... (N lines before/after) ...` marker. `matrix3d_precision` (25 lines) and
  `matrix3d_raw_data` (33) fit and were graded from the blob; `matrix3d_determinant`
  (182) did not, and only 9 of its 33 diffs are visible — enough to name the
  mechanism, not enough to price the flip.
- Sort the well by **both** `expected − matching` and `actual − expected`. Two
  rows have `miss == 0` and fail purely on extra output, and one row
  (`displayobject_early_init`) has `miss == 53` and three real defects.
- `tools/descriptor/check_model.py <suite-dir> <package>` is a **build-free
  oracle** for any `all_classes` package. Use it before costing a describeType
  lead; it took 4 s to turn §17.4's "0 flips, XL" into a +3.
- `~/CC/ruffle` at `437be1498` was the oracle for T1, T5 and R4. For "what
  exactly does Flash do" questions on `flash.geom`/`flash.display`, reading
  Ruffle's function is faster and far more reliable than fitting the fixture.
- **`--recompile` does not always regenerate `Recompiled*` for an AVM2 test.**
  `avm2/stage_display_state` was re-run twice with `--recompile` and its
  `RecompiledABC/` mtimes stayed at Aug 6 (`r=0.02s`). If a local result
  disagrees with the graded CI row, check the cache mtimes before believing
  either — see R11.
- The five image-axis rows that are also trace-ignored (§7) are the cheapest
  place to look for a **dual-axis** flip. `avm2/displayobject_scrollrect` at
  excess 4 is the single closest image comparison in the corpus and it rides a
  trace lead (T3) that is already GO.
- Test-name resolution: `--test=NAME` takes the **suite-relative** path
  (`as3-loader/loaderinfo/loaded-content-properties`,
  `all_classes/events/swf9`), not a basename, and errors out if the name exists
  in more than one suite (`sandbox_type_remote` does).
