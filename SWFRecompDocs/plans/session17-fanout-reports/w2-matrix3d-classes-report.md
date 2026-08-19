# Session 17 · wave 2 · `w2-matrix3d-classes` — implementation report

**Agent:** `w2-matrix3d-classes` (worktree `.claude/worktrees/agent-ad3410a8fdecc5ca8`).
**Base:** `88ebde665`. **Brief of record:** `wave1-trace-board.md` §T2 and §T7.
**Grading baseline:** merged CI run `31877239992` at `aeebf9ede`
(`ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`).
All local runs: `--mode=graphics --diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
`DAWN_INSTALL=~/CC/dawn-install`, worktree-local test copies, `--recompile` on
first use of every copied directory.

---

## 0. NEW FILES IN THESE PATCHES (BRIEFS_COMMON s15/s16 lesson)

**NONE.** No new sources, no new headers, no generator scripts. `git apply --stat`
shows only modified files, one per patch, and the four files are **disjoint**, so
the patches apply in any order and can be taken or dropped independently:

| patch | file it modifies | flips |
|---|---|---|
| `w2-matrix3d.patch` | `SWFModernRuntime/src/avm2/avm2_stage3d.c` | `matrix3d_raw_data`, `matrix3d_determinant` |
| `w2-matrix3d-numfmt.patch` | `SWFModernRuntime/src/avm2/avm2_value.c` | `matrix3d_precision` (needs `w2-matrix3d.patch` too) |
| `w2-t7-classes.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | `native_menu_basic` |
| `w2-t7-automation.patch` | `SWFModernRuntime/src/avm2/avm2_events.c` | `automation_classes` |

`w2-t7-fullscreenevent.patch` was **NOT** produced — see §8 (NO-GO with a named
completion mechanism; the leg belongs to `w2-all-classes-events`).

All four verified with `git apply --check -R` against the built tree.

---

## 1. VERDICTS — **GO ×5, +5 flips, ZERO regressions across 41 canary rows**

| lead / leg | verdict | flip |
|---|---|---|
| **T2 (a)** Matrix3D `rawData` is f32 | **GO** | (enables b + c) |
| **T2 (b)** `rawData` length must be exactly 16 | **GO** | `avm2/matrix3d_raw_data` → **pass** |
| **T2 (c)** determinant | **GO**, board's *mechanism* **REFUTED** | `avm2/matrix3d_determinant` → **pass** |
| **T2 rider** AVM2 exponential number→string | **GO** | `avm2/matrix3d_precision` → **pass** |
| **T7** `NativeMenuItem` + the NativeMenu member surface | **GO** | `avm2/native_menu_basic` → **pass** |
| **T7** `flash.automation.*` (5 classes) | **GO** | `avm2/automation_classes` → **pass** |
| **T7** `FullScreenEvent` | **NO-GO this slot** (mechanism named, §8) | 0 |

**T2 landed at its CEILING (+3/3)** — and the board explicitly called
`matrix3d_precision` "the *least* likely of the three to flip". That pricing is
refuted in our favour (§4).

**T7 landed at its CEILING for the two rows I own (+2)**; the third
(`stage_display_state`) is a hold, so T7 is **+2 of a 0/+1/+3 pricing**.

---

## 2. Per-test ledger (before → after)

| test | baseline (CI `31877239992`) | after | Δ matched lines |
|---|---|---|---|
| `avm2/matrix3d_raw_data` | output_mismatch 28/33 | **pass** 33/33 | +5 |
| `avm2/matrix3d_determinant` | output_mismatch 149/182 | **pass** 182/182 | +33 |
| `avm2/matrix3d_precision` | output_mismatch 5/25 | **pass** 25/25 | +20 |
| `avm2/native_menu_basic` | output_mismatch 0/19 | **pass** 19/19 | +19 |
| `avm2/automation_classes` | output_mismatch 1/122 | **pass** 122/122 | +121 |
| `avm2/stage_display_state` | output_mismatch 0/6 | unchanged (NO-GO, §8) | 0 |

`matrix3d_{determinant,precision,raw_data}` and `automation_classes` are **not on
local disk** (board §3). I sparse-fetched them from `github.com/ruffle-rs/ruffle`
(`tests/tests/swfs/avm2/<name>`) into my scratchpad and copied them into the
worktree's canonical `ruffle-tests/tests/swfs/avm2/`. **No test content is part
of any patch** — CI already has the upstream corpus.

---

## 3. T2 (c): the board's determinant mechanism is WRONG — the right one is in Ruffle

The board proposed replacing the 4×4 cofactor sum with the plain 3×3 upper-left
minor:

```
m[0]*(m[5]*m[10]-m[9]*m[6]) - m[4]*(m[1]*m[10]-m[9]*m[2]) + m[8]*(m[1]*m[6]-m[5]*m[2])
```

**Refuted by the fixture's own opening block**, which the board did not read (it
worked from the 9 visible lines of a 33-line diff):

```
not affine with translation: -27      rawData = 1,2,1,4, 2,3,2,1, 3,3,4,2, 4,2,4,1
```

The proposed 3×3 minor gives **−1** there, not −27. Indices 3/7/11/15 (the
bottom row) and 12/13/14 (the translation column) each participate in at least
one graded row, so no fixed minor can be right.

What Flash does is a **conditional Laplace expansion evaluated in f32** — Ruffle
already reverse-engineered it from these same fixtures in
`render/src/matrix3d.rs::determinant()`. Ported verbatim as `m3d_determinant`:

* **Zero projection row** (`m[3]==m[7]==m[11]==0`): the translation column never
  participates at all (hence `zero index 12 = NaN: 0`), and `m[15]` is folded
  into the **third row of the inner 3×3** rather than multiplied in afterwards —
  observable only when `m[15]` is ±Infinity, which the `laplace 10r` /
  `inner laplace` rows do.
* **Otherwise**: the expansion runs over the first **row**
  (`m[0] m[4] m[8] m[12]`), not the last column — which is why two infinities
  never meet in one subtraction in a dense matrix
  (`dense index 0 = Infinity: -Infinity`).
* **f32 throughout**: the 1e10-diagonal case in `matrix3d_precision` must report
  `Infinity` (det = 1e40 overflows f32); an f64 accumulation prints `1e+40`.

All 33 lines close.

---

## 4. T2 rider: the last 3 lines of `matrix3d_precision` were the NUMBER FORMATTER

With the Matrix3D patch alone, `matrix3d_precision` went 20 diff lines → **3**,
all the same shape:

```
-  15    transformVectors: 3.00000000000000e+50,...
+  15    transformVectors: 2.9999999999999996e+50,...
-  23    transformVectors: 9.59999999999999e+38,...
-  27    transformVectors: 1.2e+39,...
+  27    transformVectors: 1.2000000000000002e+39,...
```

`transformVectors` is the one Matrix3D entry point that stays in f64 (Ruffle
comments this explicitly), so the *values* were already right. What was wrong is
`avm2_format_number`'s exponential branch in `avm2_value.c`: it implemented the
**old** Ruffle rule (arithmetic truncation to 15 significant digits), which does
not survive the round trip through `precision / pow(10, digits)`:

```
1e40  ->  "0.9999999999999999e+40"     <- not even a legal ECMA representation
3e50  ->  "2.9999999999999996e+50"
```

Current Ruffle (`core/src/avm2/value.rs::f64_to_string_finite_nonzero`) takes the
**shortest round-tripping decimal** and, for a positive exponent only, cuts the
mantissa *text* to 16 characters ("Flash shows large numbers with smaller
precision for some reason"), plus a two-bit-pattern special case that prints
`1e+308`. Ported (30 lines). Verified against the three expected strings with a
standalone probe before rebuilding, then confirmed by the test.

This is a **corpus-wide** formatting change (every AVM2 number outside
`[1e-6, 1e21)`), hence a **separate patch** — see the number-format canary tier
in §9, all green. It is a real correctness fix independent of this lead.

---

## 5. T2: exact patch scope (`w2-matrix3d.patch`, `avm2_stage3d.c` only)

`Avm2Matrix3DExt` becomes `float m[16]` with `m3d_widen` / `m3d_narrow` helpers,
so the **externally visible API is unchanged** — `avm2_geom_matrix3d_new(ctx,
const double*)` and `avm2_geom_matrix3d_read(o, double*)` keep their `double*`
signatures and convert internally. `avm2_display.c`'s three call sites are
untouched, which keeps this patch out of every sibling's file.

Sites made f32, each pinned by a `matrix3d_precision` line:

| entry point | rule |
|---|---|
| `rawData` get/set, `Matrix3D(v)` ctor | store f32, widen on read; length **== 16** exactly |
| `m3d_mul_f` | matrix product accumulates in f32 |
| `appendTranslation` | **not** a matrix product — adds the f32-cast arguments straight onto `m[12..14]` |
| `prependTranslation`, `append`/`prependScale` | build the temp from **f32-cast** arguments, then f32 product |
| `append`/`prependRotation` | Rodrigues formula in f64, narrowed to f32 before the product |
| `determinant` | §3 |
| `transformVector` / `deltaTransformVector` | cast the input vector to f32, accumulate in f32 |
| `transformVectors` | **stays f64** (widened matrix) — graded on lines adjacent to the two above |
| `position` set, `copyColumnFrom`/`copyRowFrom`, `copyRawDataFrom` | quantize on write |
| `invert`, `recompose`, `decompose`, `Utils3D.project*` | f64 math on a widened copy, narrowed on store |

**Deliberately NOT taken:** Ruffle raises `#2183 "Scale values must not be zero"`
from `appendScale`/`prependScale` and uses a `|det| > 1e-11` invertibility
threshold; `invert` here keeps its `det == 0` test. Neither is required by a
priced row and neither has fixture backing in our corpus.
*Completion mechanism if wanted later:* `matrix3d_invert` and
`matrix3d_recompose_edge_cases` are the two rows that would move.

---

## 6. T7 `NativeMenuItem` / `NativeMenu` (`w2-t7-classes.patch`, `avm2_display.c` only)

`avm2/native_menu_basic` is a `runtime = "AIR"`, SWF 17 fixture. It died on line 1
with `#1065: Variable NativeMenuItem is not defined`; `NativeMenu` already existed
(s16 minted it as an empty `EventDispatcher` subclass for `all_classes/display`)
but had **no members at all**.

Implemented from Ruffle's playerglobal stubs: `NativeMenuItem` (11 accessors,
ctor `(label = "", isSeparator = false)`) and the full 18-member `NativeMenu`
surface. The graded semantics that are easy to get wrong, all straight from the
fixture:

* `items` hands out a **copy** — `menu.items == menu.items` is `false`, and
  `menu.items.push(3)` does not change the menu;
* the `items` **setter** is `removeAllItems()` + one `addItem()` per element, so
  `menu.items = [item, 4, item]` throws `#1034` *after* the first item is already
  stored (`[NMI](test0)` survives);
* `addItemAt` checks in the order **coerce → range (`#2006`) → null (`#2007`)`,
  which is why `addItemAt(item, -1)` is a RangeError while `addItem(null)` is an
  ArgumentError.

### Version-gate rule applied (`version-gate-new-api-surface`)

Both classes carry `[API("667")]` in playerglobal. Under the corrected s16 rule
(`ord = N − 660`; for `ord < 12` the map is `{0: always, 2: 10, 5: 10, 7: 10,
10: 11}`, everything else AIR-only = 255), ordinal 7 → **min_swf 10**, so both
are registered with `avm2_builtin_class_api(..., 10)`.

Every *member* except `NativeMenuItem.enabled` is `[API("668")]` → ordinal 8 →
**AIR-only = 255**, i.e. hidden from `describeType` at every Flash Player
version. That hiding is **describe-only** (`dt_desc_member_hidden` is reached
only from `dt_collect_vtable`), so registering the members as real natives cannot
change what `all_classes/display` prints — and I checked name-by-name that all 18
NativeMenu members I register already have a matching `min_swf = 255` row **of
the right kind** (accessor vs method) in `dtd_m_NativeMenu` (`avm2_globals.c`),
which is what the hide lookup keys on. A kind mismatch would have leaked a member
into the describeType output; there is none, and all three graded
`all_classes/display` rows stayed `pass`.

`NativeMenuItem` needs no descriptor table: `grep -l NativeMenuItem
all_classes/display/swf*/output.txt` returns **nothing** — the fixture drives a
hardcoded class-name list (swf9's expected output literally says
`NativeMenu not accessible`) and `NativeMenuItem` is not on it.

Registration replaces the existing two-line `NativeMenu` mint in
`avm2_display.c`'s flash.display constant-bag block (~:14890) with
`register_native_menu(ctx, b)`, defined in a static block immediately before
`avm2_register_display`. **Sibling-overlap check:** the other `avm2_display.c`
owners this session are the gfx region (`gfx_draw_graphics_data` ~:8819), the
filters render path, `compose_children`, the hit-test region, and the
transform/bounds region (~:10180). No function or line is shared.

*(Brief deviation, deliberate: the brief said "class registration in
`avm2_globals.c`". That file holds the descriptor **tables**; the class itself
has always been minted in `avm2_display.c`, and moving it would have collided
with `w2-all-classes-events`, who owns the `avm2_globals.c` generated block.)*

---

## 7. T7 `flash.automation` (`w2-t7-automation.patch`, `avm2_events.c` only)

Five classes, 122 expected lines, **passed on the first build**:
`AutomationAction`, `KeyboardAutomationAction`, `MouseAutomationAction`,
`StageCapture`, `StageCaptureEvent`. Ported from Ruffle's
`flash/automation/*.as`.

**Version gate: none.** No `[API]` annotation on any of the five, so all exist at
every SWF version (the fixture is SWF 9) and they use plain `avm2_builtin_class`,
not the `_api` variant. No `all_classes` fixture covers `flash.automation`, so
there is no describeType surface to keep in step.

Two mechanisms the fixture forces:

1. **Builtin-constructor arity (`#1063`).** Our native builtins do not enforce
   declared arity anywhere (`Avm2MethodRef.param_count` is stored but never
   read), and the fixture opens every class with a deliberately wrong call and
   prints the `#1063` text. Rather than add global arity enforcement — a
   corpus-wide behaviour change far outside this brief — the patch adds a
   **local** `auto_check_argc(act, qname, min, max)` used by the four
   constructors: `Expected` is the required count on underflow and the total
   count on overflow, which is exactly what the fixture's three `#1063` lines
   show. *(Generalising this is a standing lead: `param_count` is already
   populated for native builtins, so a global check is one call site in the
   builtin invoke path — but it needs its own slot and its own canary sweep.)*
2. **`#1074` on read-only accessors.** `StageCaptureEvent.url/checksum/pts` are
   getter-only, and our existing `AVM2_PROP_GETTER` write path already emits
   `Error #1074: Illegal write to read-only property X on
   flash.automation.StageCaptureEvent.` verbatim — no new machinery.

`StageCaptureEvent`'s three fields borrow slots already present in the shared
`Avm2EventExt` (`response_url` → `url`, `key_code` → the uint `checksum`,
`bytes_loaded` → `pts`) instead of growing `avm2_globals.h`. The header already
documents that reuse pattern (`ContextMenuEvent.mouseTarget` reuses
`related_object`), it keeps this patch to a single `.c` file and out of
`w2-all-classes-events`'s way, and `StageCaptureEvent` extends `Event`
**directly**, so none of the three donor fields is reachable through its own
vtable — the aliasing is unobservable.

Replicated playerglobal quirk: `clone()` forwards only **five** arguments, so the
clone's `pts` comes back `0`; the fixture grades exactly that.

---

## 8. T7 `FullScreenEvent` — NO-GO this slot, and the board's discrepancy is RESOLVED

**The board's "DISCREPANCY — it passes locally" reading is refuted.** Re-graded
at HEAD in graphics mode from a **freshly copied** test directory with
`--recompile` (no stale `RecompiledABC/` anywhere), `avm2/stage_display_state` is
`output_mismatch`, exactly matching the CI row:

```
-  1  FullScreenEvent.fullScreen - unimplemented
+  1  ReferenceError: Error #1065: Variable FullScreenEvent is not defined.
+  2  	at test_fla::MainTimeline/frame1()
```

The CI row is correct; the local "pass" the board saw was the stale local ABC, as
it suspected. **Do not spend a slot re-baselining it.**

**Why NO-GO rather than a quick class add** — the first two reasons are the real
ones:

1. `flash.events.FullScreenEvent` is a **flash.events** class, and
   `w2-all-classes-events` is regenerating the entire flash.events descriptor
   block this session. Adding a class to that namespace out of band would change
   `all_classes/events/swf{9,10,11,12,30}` — the five rows that agent is fixing —
   and would very likely conflict with their generated table.
2. The class alone is not enough. Frame 1 does
   `stage.addEventListener(FullScreenEvent.FULL_SCREEN, onFullScreen)` and then
   assigns `stage.displayState`; our `stage_get_display_state`
   (`avm2_display.c:11533`) is a hardcoded `"normal"` and the setter is a no-op.
   The six expected lines are **two** dispatches — `fullScreenInteractive` then
   `normal` — i.e. Flash grants the request, dispatches, then immediately reverts
   (a fullscreen request made without a user gesture is denied) and dispatches
   again.
3. The "unimplemented" lines are the fixture's **own hardcoded traces** — the
   SWF's string pool carries `"FullScreenEvent.fullScreen - unimplemented"`
   alongside commented-out `"// OnFullScreen ..."` variants — so `fullScreen` and
   `interactive` do **not** need real values.

**Completion mechanism (flips it to GO): (a)** `w2-all-classes-events` emits
`flash.events.FullScreenEvent` (constants `FULL_SCREEN`,
`FULL_SCREEN_INTERACTIVE_UPDATED`; accessors `fullScreen`, `interactive`) from
their generator; **(b)** `Stage.displayState` latches the assigned string,
synchronously dispatches a `FullScreenEvent`, then reverts to `"normal"` and
dispatches a second one. Worth exactly **+1** (`avm2/stage_display_state`,
6 lines).

---

## 9. Canaries — 41 rows, **ZERO regressions**

Baselines from CI run `31877239992`. All run locally in the worktree,
`--mode=graphics`, ≤ 2 concurrent, `--recompile` on first use.

### Tier 1 — Matrix3D family (the f32 conversion's blast radius): 18/18 on baseline

| test | baseline | after |
|---|---|---|
| `avm2/matrix3d` | pass | **pass** |
| `avm2/matrix3d_append` | pass | **pass** |
| `avm2/matrix3d_append_rotation` | ruffle_matched | **ruffle_matched** |
| `avm2/matrix3d_compose` | pass | **pass** |
| `avm2/matrix3d_copy_column` | pass | **pass** |
| `avm2/matrix3d_copy_raw_data_from` | pass | **pass** |
| `avm2/matrix3d_copy_raw_data_to` | pass | **pass** |
| `avm2/matrix3d_copy_row` | pass | **pass** |
| `avm2/matrix3d_invert` | pass | **pass** |
| `avm2/matrix3d_position` | pass | **pass** |
| `avm2/matrix3d_prepend` | pass | **pass** |
| `avm2/matrix3d_recompose_edge_cases` | ruffle_matched | **ruffle_matched** |
| `avm2/matrix3d_transform_vector` | pass | **pass** |
| `avm2/matrix3d_transpose` | pass | **pass** |
| `avm2/geom_transform` | pass | **pass** |
| `avm2/utils3d` | pass | **pass** |
| `avm2/perspective_projection` (1443 lines) | pass | **pass** |
| `avm2/displayobject_transform` | output_mismatch 67/89 | **output_mismatch, 22 diff lines — identical** |

### Tier 2 — number formatting (the `numfmt` patch's blast radius): 19/19 on baseline

`avm2/`: `coerce_string_precision`, `number_convert_edge_cases`, `math`,
`divide`, `parse_float`, `is_finite`, `number_toexponential`,
`number_toexponential2`, `number_toprecision`, `number_tofixed`, `matrix`,
`displayobject_height`, `displayobject_rotation` — **all pass** (all were pass).
`from_avmplus/`: `ecma3/Number/tostring_001`, `ecma3/Number/e15_7_1`,
`ecma3/Number/e15_7_2`, `ecma3/TypeConversion/e9_4_1`,
`ecma3/Expressions/e11_5_2` — **all effective-pass** (baselines: three
`ruffle_matched`, two `pass`; none demoted).

`avm2/number_tostring` (baseline output_mismatch 873/1050) stays
`output_mismatch` but its printed diff shrank from 177 mismatched lines to
**145** — every remaining line is a *radix* conversion (`(radix = 3)`,
`(radix = 6)`, …), which this patch does not touch. Counted as **no
regression, possible small line gain**, not a flip.

### Tier 3 — describeType / Stage3D (the T7 patches' blast radius): 8/8 on baseline

| test | baseline | after |
|---|---|---|
| `avm2/all_classes/display/swf9` | pass | **pass** |
| `avm2/all_classes/display/swf10` | pass | **pass** |
| `avm2/all_classes/display/swf30` | pass | **pass** |
| `avm2/all_classes/events/swf30` | output_mismatch 25/2353 | **output_mismatch** (unchanged; owned by `w2-all-classes-events`) |
| `avm2/stage3d_blend` | pass | **pass** |
| `avm2/stage3d_rotating_cube` | pass | **pass** |
| `avm2/stage3d_errors` | pass | **pass** |
| `avm2/stage3d_x_y` | pass | **pass** |

**Build-state note:** the canaries were graded as the four patches landed, so a
few tier-1 rows first ran against a partial tree. `avm2/matrix3d` and
`avm2/matrix3d_append` were therefore **re-graded on the final combined tree**
(all four patches applied) and both still `pass`; every other row in all three
tiers was already graded against a tree containing `w2-matrix3d.patch` +
`w2-matrix3d-numfmt.patch`, and tiers 2–3 against all four.

`all_classes/display/{swf9,swf10,swf30}` are the rows that would have caught a
leaked NativeMenu member or an unexpected `NativeMenuItem` class; the Stage3D
rows reach Matrix3D through `setProgramConstantsFromMatrix`.

### Canary blind spots (s15 lesson)

* The standing graphics `render_canary` set does **not** exercise Matrix3D at
  all — none of these patches touches a render path, and all four modified files
  are AVM2-runtime-only, so the pixel axis is untouched by construction.
* No canary covers **AVM1** number formatting: the `numfmt` patch touches
  `avm2_value.c` only; AVM1 has its own formatter in `action.c` and is untouched
  by construction.
* The covering tests I graded for the exponential path are the five
  `from_avmplus/ecma3` rows plus `avm2/number_to*` (four rows) in tier 2.

---

## 10. Attack on my own pricing (s16 lesson)

* **T2 was priced +1 / +2 / +3 with `precision` "the least likely to flip". It
  landed +3**, and the reason `precision` flipped is a lead the board did not
  have: 3 of its 20 diff lines were an AVM2 **number-formatting** bug, not
  Matrix3D. The board's "that expected string carries a 15-significant-digit
  format we do not produce anywhere" note turned out to be a 30-line port of a
  function Ruffle had already rewritten.
* **T2 (c)'s stated mechanism was wrong**, and one line of the fixture's *first*
  block refutes it. The board read only the 9 visible lines of a 33-line diff.
  Standing lesson: when a fixture has more missing lines than the runner prints,
  read `Test.as`, not the truncated diff.
* **T7 was priced 0 / +1 / +3 with `stage_display_state` as "the cheapest".** It
  is in fact the **most** expensive of the three — it needs a class *and* a Stage
  state machine *and* it sits in a sibling's file — while `native_menu_basic`
  (priced "M") and `automation_classes` (121 missing lines, which looks like the
  scariest of the three) were both cheap, because Ruffle's playerglobal stubs are
  complete line-for-line specifications. **A big missing-line count is not a big
  implementation.**
* **Ruffle's own source was the single highest-leverage input in this slot.**
  Four of the five flips were ports of code Ruffle had already derived from the
  same fixtures (`matrix3d.rs`, `value.rs`, `NativeMenu*.as`, `automation/*.as`).
  For any lead whose row is a *missing or wrong builtin*, reading
  `~/CC/ruffle` (or sparse-fetching the current tree, as I did — the local clone
  is stale) should be step 1, before writing any C.
