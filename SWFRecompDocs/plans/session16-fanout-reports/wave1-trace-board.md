# Wave-1 — TRACE-axis board, regenerated (session 16, dual-axis fan-out #8)

**Agent:** `w1-trace-board`. Read-only in the main tree (no source edits, no
commits). Local verification: 20 individual tests re-run at HEAD `cd04f80b9`
with `verify_output.py --mode=graphics --diff`, in two `-P 5` batches
(the one heavier-CPU allowance in this wave). Never a suite.

**Baseline CONFIRMED, exactly: trace 4298 / 4443 effective** at `3db858cbc`
(CI run `31748059158`, graphics / categories=full / images=true), merged into
master's per-suite `results_graphics.json`. Recomputed from the 20 tracked
`*_results/results_graphics.json` blobs with the three `NESTED` dirs excluded
(`from_shumway/avm1`, `from_shumway/timeline`,
`from_gnash/misc-ming.all/displaylist_depths`) exactly as
`scripts/corpus_status_diff.py` does.

> Denominator trap re-confirmed: globbing instead of using the git-tracked path
> list adds `from_avmplus/as3/Vector` (59) and `.../Vector/nonindexproperty` (2)
> and reads **4504 / 4359**. Both are nested inside `from_avmplus`. Use
> `git ls-tree -r --name-only HEAD | grep _results/results_graphics.json`.

---

## 0. Status histogram (whole corpus, at the graded baseline)

| suite | output_mismatch | pass | ruffle_matched | runtime_error | total | effective |
|---|---:|---:|---:|---:|---:|---:|
| audio | 2 | 3 | 0 | 0 | 5 | 3 |
| avm1 | 22 | 678 | 18 | 0 | 718 | 696 |
| avm2 | 66 | 1143 | 31 | 0 | 1240 | 1174 |
| fonts | 0 | 6 | 0 | 0 | 6 | 6 |
| from_avmplus | 5 | 1515 | 53 | 1 | 1574 | 1568 |
| from_gnash/actionscript.all | 13 | 135 | 95 | 0 | 243 | 230 |
| from_gnash/misc-ming.all | 13 | 69 | 29 | 0 | 111 | 98 |
| from_gnash/misc-mtasc.all | 0 | 7 | 2 | 0 | 9 | 9 |
| from_gnash/misc-swfc.all | 5 | 11 | 4 | 0 | 20 | 15 |
| from_gnash/misc-swfmill.all | 0 | 19 | 1 | 0 | 20 | 20 |
| from_shumway | 10 | 207 | 12 | 0 | 229 | 219 |
| import_assets | 1 | 2 | 0 | 0 | 3 | 2 |
| mixed_avm | 4 | 7 | 0 | 0 | 11 | 7 |
| regression | 0 | 72 | 0 | 0 | 72 | 72 |
| stage3d | 0 | 5 | 0 | 0 | 5 | 5 |
| swf | 0 | 4 | 1 | 0 | 5 | 5 |
| text | 1 | 10 | 0 | 0 | 11 | 10 |
| timeline | 2 | 12 | 3 | 0 | 17 | 15 |
| visual | 0 | 142 | 2 | 0 | 144 | 144 |
| **TOTAL** | **144** | **4047** | **251** | **1** | **4443** | **4298** |

**Zero `segfault`, `timeout`, `compile_fail`.** The crash axis is empty except
for the single long-standing `from_avmplus/regress/bug_483783` `runtime_error`.
The cheapest-triage-axis (`runtime-error-is-cheapest-triage-axis`) is therefore
*dry at the status level*; the usable substitute is the `error_signature` field,
which is present on only 21 of the 145 non-effective rows (see §4).

145 non-effective rows. 38 of them are named in a disposition doc; 61 appear in
some `ignored_tests.txt` (global or suite-local) — **and 34 of those ignore
entries have no rationale anywhere**, see §5.

---

## 1. Ranked leads — read this table first

Pricing: **floor** = flips with line-level evidence; **real** = expected from
one wave-2 session; **ceiling** = every row in the cluster.

| # | lead | rows | floor/real/ceiling | verdict | owner file(s) | size | evidence | independent slot? |
|---|---|---|---|---|---|---|---|---|
| **L1** | **twip-quantize `localToGlobal`/`globalToLocal`** | 4–6 | **+1 / +2 / +4** | **GO — take first** | `avm2_display.c` `point_transform_native` (:3794-3825) | **XS (4 lines)** | STRONG (arithmetic reproduced by hand) | **YES** |
| **L2** | flash.geom completion: `Transform.matrix`/`matrix3D` duality, `Matrix.copyRowTo/copyColumnTo`, `Transform.getRelativeMatrix3D` | 4 | +1 / +2 / +4 | **GO** | `avm2_display.c` (:9260-9299, :14043-14059), `avm2_stage3d.c` | M | STRONG (3 distinct `error_signature`s) | **YES** (self-localize vs L1) |
| **L3** | trace-smalls #2 (6 unrelated one-liners) | 6 | +2 / +3 / +6 | **GO** | mixed | S each | STRONG for 4, MED for 2 | **YES** |
| **L4** | stale "image-comparison" ignore bucket re-triage | 8 | +1 / +2 / +3 net | **GO (small)** | `avm2/ignored_tests.txt` + code | S–M | STRONG (comment predates graphics mode) | YES (overlaps L1/L2 on 3 rows) |
| **L5** | `all_classes/events` swf9-30 — **not on §16.4** | 5 | 0 / 0 / +5 | **DEFER to the display sibling** | describeType emitters | XL | STRONG (identical shape to `display`) | no — pair with `w1-all-classes-display` |
| **L6** | `avm2/supercalls_coerce` — super get/set/call must throw #1034 | 1 | 0 / +1 / +1 | GO (small) | `avm2_ops.c` / `avm2_class.c` | S–M | STRONG (all 7 codes wrong, one rule) | YES |
| **L7** | ignore-list hygiene + missing dispositions | 34 entries | 0 flips | **GO (doc-only, cheap)** | 6 `ignored_tests.txt` + `ACCEPTED_DIFFS.md` | S | STRONG | YES |
| **L8** | `avm2/button_nested_frame_simple` — 2 extra tick cycles + doubled child framescripts | 1 | 0 / +1 / +1 | DEFER | timeline core | M | MED | no (timeline-order family) |
| — | `all_classes/display` ×6 | 6 | — | **HANDED OFF** to `w1-all-classes-display` | — | — | — | — |
| — | AVM1-child remainder ×11 | 11 | — | **HANDED OFF** to `w1-avm1-child` | — | — | — | — |
| — | `avm2/number_convert_errors` | 1 | — | DEFER (structural, §16.4 stands) | — | L | — | — |
| — | `from_avmplus/regress/bug_483783` | 1 | — | **NO-GO stands** | — | — | — | — |
| — | action_order ×7, `timeline/missing_frame_scripts`, `avm1/looping_child_*` ×3 | 11 | — | **DEFER (timeline-order arc)** | — | L | — | — |
| — | gnash `array-v5..v8`, `MovieClip-v6/7/8`, `argstest-v6/7/8` | 10 | — | **NO-GO stands** | — | — | — | — |
| — | `eforin_001/002` | 2 | — | **NO-GO stands** | — | — | — | — |
| — | `avm1/set_property_values/swf4-7` ×4 | 4 | — | **NO-GO (documented float blocker)** | — | — | — | — |
| — | ignored-6 audit (brief item 4) | 6 | **0** | **CLAIM REFUTED — all six are backed** | — | — | — | — |
| — | s15 "double→string shortest-round-trip" probe | 2+ | — | **REFUTED** (§7) | — | — | — | — |

Summing the GO rows' *real* column: **+9** before anyone touches the two
handed-off clusters or the `events` package.

---

### L1 — twip-quantize `localToGlobal` / `globalToLocal`  ★ take first

**GO. Floor +1, real +2, ceiling +4. Four lines of C.**

`avm2/displayobject_scrollrect`, run at HEAD:

```
- circle.localToGlobal(new Point(10, 20)) = (x=55, y=76)
+ circle.localToGlobal(new Point(10, 20)) = (x=54.999999552965164, y=76.00000098347664)
- circle.globalToLocal(new Point(10, 20)) = (x=-21.4, y=-21.4)
+ circle.globalToLocal(new Point(10, 20)) = (x=-21.406493121385573, y=-21.415585547685623)
```

The *matrix itself already matches byte-for-byte* on the adjacent line
(`concatenatedMatrix = (a=1.2999999523162842, b=0.2…, c=0.1…, d=1.2…, tx=40, ty=50)`),
so this is not a matrix bug. It is the **fifth instance of
`ruffle-geometry-is-integer-twips`**, and the one the 2026-07-30 fix
(`92ca512ed`, `mat_mul` + `rect_union_xform`) did not reach.

`SWFModernRuntime/src/avm2/avm2_display.c:3813-3814`, in `point_transform_native`:

```c
	double tx = m.a * (x * 20.0) + m.c * (y * 20.0) + m.tx;
	double ty = m.b * (x * 20.0) + m.d * (y * 20.0) + m.ty;
```

Ruffle's `Matrix * Point<Twips>` rounds the **f32** rotate/scale product
half-to-even into an i32 twip **before** adding the already-integral
translation. The helper is already in the file — `round_to_i32` at
`avm2_display.c:601-613` (`(double)(int32_t) nearbyintf(f)`), written for
`mat_mul`. Reproduced by hand for the failing line:

```
x=10px -> 200 twips, y=20px -> 400 twips, tx = 40px = 800 twips
200*1.2999999523162842 + 400*0.10000000149011612 = 299.99999106…
round_to_i32 -> 300 ; +800 = 1100 twips = 55.0 px   == expected
our unrounded path -> 299.99999106 + 800 = 1099.99999 -> 54.999999552965164
```

`Twips::from_pixels` also rounds (`(px*20.0).round() as i32`), so the input
conversion `x * 20.0` should become `round_to_i32((float)(x * 20.0))` in the
same edit for non-integral input points.

**Why this is low risk (reuse the 2026-07-30 argument verbatim):** every
expected output in the corpus comes from Flash, which is *also* integer twips,
so quantizing can only move toward the oracle. The last instance of this fix
touched 176 content-grepped canaries with zero regressions.

Rows that carry this signature today:

| test | miss / expected | note |
|---|---|---|
| `avm2/displayobject_scrollrect` | 14 / 33 | **every** diff line is a `localToGlobal`/`globalToLocal` pair — plausibly a clean +1 |
| `avm2/displayobject_hittestpoint_boundary` | 18 / 65 | partly this, partly an edge-exclusivity rule + one missing leading blank line (see below) |
| `avm2/bounds_mode` | 16 / 269 | s15 measured `3.076923076923077` vs `3.0769230769230775` here — one ULP, i.e. this mechanism, not formatting (§7) |
| `avm2/stage_scale_factor` | 6 / 12 | `localX/localY` lines; the `contentsScaleFactor: 2` half is separate |
| `avm2/matrix` | 56 / 338 | `1.836970198721029e-16` vs `1.8369701987210297e-16` — same class; also needs L2's `copyRowTo` |

**Canary the wave-2 agent must run** (this touches the hit-test/bounds/focus
families): `avm2/tab_ordering_arrows`, `avm2/getbounds*`,
`avm2/displayobject_getbounds`, `from_shumway/stroke1`,
`avm2/flash_media_video_rotation_probe`, `avm2/localconnection`.

**Refutation that would flip this to NO-GO:** if `displayobject_scrollrect`'s
remaining diffs after quantization are not zero — the `After 50ms delay` block
(`circle.localToGlobal … = (x=-16, y=-6)`) may be a separate scrollRect-offset
rule. Grade that block first.

### L2 — flash.geom completion

**GO. Floor +1, real +2, ceiling +4.**

Three distinct, individually cheap gaps, all in the `flash.geom` builtin
surface, all confirmed by `error_signature` at the graded baseline:

1. **`Transform.matrix` / `Transform.matrix3D` duality** →
   `avm2/geom_transform` (53 / 74 missing, and it **aborts at expected line 24**,
   so ~50 of the 53 are cascade). Expected semantics, straight from the fixture:
   assigning `.matrix` must make `.matrix3D` return a *promoted* `Matrix3D`
   (`rawData 2,3,0,0,4,5,0,0,0,0,1,0,6,7,0,1`) and assigning `.matrix3D` must
   make `.matrix` return **null**. We return the 2D matrix and `null`
   respectively, then die on `#1009 … (accessing field: rawData)`.
   Getter/setter pair lives at `avm2_display.c:14059` (`add_getset(… "matrix3D",
   transform_get_matrix3d …)`).
2. **`flash.geom.Matrix.copyRowTo` / `copyColumnTo` are simply not registered.**
   `avm2_display.c:14043-14045` registers only the `…From` halves; grep confirms
   no `copyRowTo` outside `avm2_stage3d.c` (where the *Matrix3D* versions do
   exist, `:2377-2380`). → `avm2/matrix`, `error_signature = TypeError #1006:
   copyRowTo is not a function` (56 / 338 missing).
3. **`Transform.getRelativeMatrix3D` missing** →
   `from_shumway/avm2/flash/geom/matrix3d/TransformBasics`, `#1006:
   getRelativeMatrix3D is not a function` (8 / 13 missing).

`avm2/displayobject_transform` (22 / 89) is the fourth row in the family and
should be graded after 1–3 land rather than briefed separately.

**Attack the premise:** `avm2/matrix` will probably NOT flip from (2) alone —
its remaining lines include the one-ULP numbers that L1 owns. Price `matrix` as
an L1∩L2 joint row, not as L2's floor.

### L3 — trace-smalls #2 (six independent one-liners)

**GO. Floor +2, real +3, ceiling +6.** All verified at HEAD; none is in any
disposition doc.

| row | miss | mechanism (evidence) | strength |
|---|---|---|---|
| `avm2/delayed_symbolclass` | 8 / 28 | **pure ordering.** re-run at HEAD: our lines 1-2 are `In SecondFrameChild class initializer` / `script initializer`; Flash emits them at lines **7-8**, after `Called complete event!`. A pure 2-line shift — nothing else in the 28-line fixture differs. A frame-2-only class's script+class initializer must run when that frame is reached, not at load. Same family as `avmplus-driver-eager-init-blanks-tests`. | STRONG |
| `from_shumway/as3-loader/LoaderTest2` | 1 / 7 | `testSymbol present: false` vs `true` — a symbol exported by the loaded child SWF is not visible through the loader's `applicationDomain`. s15 priced this +1 and it was never taken. | STRONG |
| `text/links_in_scrolled_text` | 1 / 1 | expects `Success!`, we emit a **blank line** (not nothing) — the trace fires with an empty string. `input.json`-driven link click in a scrolled `TextField`. | STRONG |
| `from_shumway/acid/acid-morph` | 2 / 6 | booleans 3 and 4 are **transposed**: expected `true,false,false,true,false,false`, ours `true,false,true,false,false,false`. One predicate pair evaluated in the wrong order (re-run at HEAD confirms exactly 2 diff lines). | STRONG |
| `avm2/method_association` | 4 / 5 | expected `1107 / 1107 / 1034 / Passed / Passed`, we print `Passed ×4`. Missing the VerifyError **#1107** for an illegal method association (a `method_info` bound to two traits) plus the #1034 that follows. Sibling of the passing `verify_*` family; owner is `SWFRecomp/src/abc/abc_parser.cpp`. | MED |
| `avm2/scope_optimizations` | 1 / 4 | `[class field]` vs `0`. Decoded from `RecompiledABC/abc0_methods.c`: with `coerce Superclass` before `pushscope`, `findpropstrict field` must resolve against the **static (verifier) type** of the scope object — `Superclass` has no `field` trait so it falls through to the global class `field`; without the coerce the runtime type `Subclass` supplies the slot (`0`). Needs a scope-entry static-type annotation from the recompiler. | MED — real but it is a verifier feature for +1 |

Take the first four as one slot; `method_association` and `scope_optimizations`
only if the slot has room.

### L4 — the stale "image-comparison" ignore bucket

**GO (small).** `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:58` heads eight
entries with

```
# Image-comparison tests (need the graphics renderer; revisit with a future avm2 graphics mode)
```

That rationale is **dead**: graphics mode landed 2026-07-23, mode parity is
complete, and the corpus is now graded *in* `--mode=graphics`. All eight rows
are ordinary graphics-mode **trace** failures, and none has a written
disposition:

| row | status | miss / expected | disposition of the diff |
|---|---|---|---|
| `bitmapdata_draw_alpha_erase` | output_mismatch | 2 / 8 | `BitmapData.draw` ignores `alphaBitmapData` and the ERASE blend entirely (`after alpha`/`after erase` equal the *before* values). Contained, **+1 candidate** |
| `stage_scale_factor` | output_mismatch | 6 / 12 | `contentsScaleFactor` hard-coded 1, must be 2; plus Stage `localToGlobal` must ignore the Stage's own matrix (L1 rider) |
| `edittext_tag_indent` | output_mismatch | 11 / 49 | HTML `indent` must be **negative** (`-1638` vs our `1638`, `-10` vs `3267`) and one line-break differs |
| `displayobject_scrollrect` | output_mismatch | 14 / 33 | **L1** |
| `displayobject_hittestpoint_boundary` | output_mismatch | 18 / 65 | L1 + an edge-exclusivity rule (10 boundary points must read `false`) + a missing leading blank line |
| `geom_transform` | output_mismatch | 53 / 74 | **L2** |
| `blend_transform` | ruffle_matched | — | already effective |
| `graphics_draw_path` | ruffle_matched | — | already effective |

Net new flips beyond L1/L2: `bitmapdata_draw_alpha_erase`,
`edittext_tag_indent`, `stage_scale_factor` → floor +1, real +2, ceiling +3.
The wave-2 slot should also **rewrite the heading** so the next board does not
re-cost this bucket a fourth time.

### L5 — `all_classes/events` (five rows, NOT on §16.4)

§16.4 lists `all_classes/display` (+6) only. `all_classes/events` is five more
rows with the **identical failure shape**:

| package | rows | expected lines | actual lines |
|---|---|---|---|
| `display/swf{9,10,11,12,13,30}` | 6 | 1959 / 2569 / 2593 / 2593 / 2671 / 2936 | **1753 on every single one** |
| `events/swf{9,10,11,12,30}` | 5 | 1030 / 1638 / 1750 / 1814 / 2353 | **731, 731, 731, 731, 735** |

An actual-line count that is *constant across five SWF versions while the
expected grows by 1300 lines* means the emitter stops at a fixed class, not
that it under-describes each class. Whatever the display sibling finds about
the `declaredBy` / defining-class re-point almost certainly applies here.

**s15's refutation still stands and must not be re-litigated:** these five are
`known_failure = true` upstream, but `output.ruffle.txt` is within 3-8 lines of
the Flash expectation (1033/1646/1758/1822/2361 vs 1030/1638/1750/1814/2353),
so there is **no cheap `ruffle_matched` path**.

**Verdict: DEFER, and relay this section to `w1-all-classes-display` so the two
packages get one joint ruling (+6 or +11), not two.**

### L6 — `avm2/supercalls_coerce`

One rule, seven lines:

```
expected  #1: 1034  #2: 1034  #3: 1034  #4: 1034  #5: 1034  #6: 1034  #7: 1009
actual    super getter called / super setter called / #3: 1063 / #4: 1077 / #5: 1037 / #6: 1070 / #7: 1010
```

Every `super` property get/set/call whose argument or return fails coercion
must raise **#1034 Type Coercion failed**; we raise five different codes and, on
the first two, do not raise at all. Contained; +1.

### L7 — ignore-list hygiene (0 flips, but it keeps costing sessions)

Three defects, all mechanical:

1. **16 `from_shumway/fuzz/*` entries are `pass`** (including
   `fuzz/e152812e2cfc…`, which *s15 itself fixed*). The file's own 2026-08-01
   prune criterion says an entry that is `pass` must be removed because it
   hides a win. Same for `avm2` `int_toprecision` and `uint_toprecision` (both
   `pass` after s15). `bytearray_oom` is also `pass` but is deliberately kept —
   it records an UPSTREAM `ignore = true`, so leave it.
2. **The stale "image-comparison" heading** (L4).
3. **34 ignore entries have no rationale in any of the four disposition docs
   and no inline comment naming them**, notably:
   `from_gnash/misc-swfc.all/{sound, matrix_accuracy_test1}`,
   `from_gnash/actionscript.all/{argstest-v6,-v7,-v8, array-v5}`,
   `from_gnash/misc-ming.all/register_class/RegisterClassTest4`,
   `from_shumway/{MaskTest-3, avm1movie, flash_net_SharedObject,
   flash_text_TextField2, getobjectsunderpoint}`,
   `from_shumway/avm1/hitarea`, and the whole avm2 "upstream known_failure"
   bucket. `from_gnash/misc-swfc.all/sound` is the clearest: its `output.txt`
   is **truncated** (7 lines, ending mid-suite at `PASSED: snd.position == 0
   [sound.sc:39]`) while the SWF's own harness runs to `__END_OF_TEST__` in 12
   lines and self-reports `FAILED: TOTAL tests run: 1, expected: 2` — i.e.
   Ruffle abandoned the run and the fixture records the abandonment. Unpassable
   by construction; write it up.
   `from_shumway/avm1/hitarea` and the global `shared_object` /
   `shared_object_self_ref` are **inert** (no results row at all).

---

## 2. Ignored-tests audit (brief item 4) — **the s15 claim is REFUTED**

The brief (from `w2-watch-order-report.md` §6) says the six names under
`ruffle-tests/ignored_tests.txt` → "Permanently accepted diffs" have no backing
disposition. **All six are backed.** Verified by direct grep of the four docs:

| name | status now | backing entry | lead? |
|---|---|---|---|
| `date` | `output_mismatch` 6289/6335 (avm1); **`pass` in avm2** | `ACCEPTED_DIFFS.md` **×4**: `:19` NaN/Infinity year in the multi-arg ctor (~9 pairs), `:34` TimezoneOffset precision for extreme dates (~1), `:67` UTCHours at −8.64e15 (~18), `:236` Infinity getter values (~14) | **NO** — 46 diffs, all-or-nothing, ≥42 of them inside the four accepted categories |
| `native_objects_swf6` | `output_mismatch` 114/115 | `ACCEPTED_DIFFS.md:82` + `RUFFLE_VS_FLASH_DIFFERENCES.md:31` | **NO** — re-ran at HEAD, exactly 1 diff, line 56 `new TextField(): non-object: undefined` vs our `native`. We are Flash-correct; the fixture is Ruffle's own and `known_failure = true` |
| `mcl_replace_root_swf7_to_swf5` | **`ruffle_matched`** (56/57) | `RUFFLE_VS_FLASH_DIFFERENCES.md:58` + `RUFFLE_COMPAT_TWEAKS.md:46` | **NO** — already effective |
| `mcl_replace_root_swf7_to_swf6` | **`ruffle_matched`** (52/57) | same | **NO** |
| `movieclip_library_state_values` | **`ruffle_matched`** (76/78) | `ACCEPTED_DIFFS.md:280` (default mouse position) + `:297` (VFS URL path format) + summary rows `:1097-1098` | **NO** |
| `tab_ordering_properties_tab_index_edge_case` | **`ruffle_matched`** (1/4) | `ACCEPTED_DIFFS.md:353` + summary row `:1105` | **NO** |

**Net yield of the audit: 0 flips.** Four of the six are already
`ruffle_matched`, i.e. already inside `effective_pass`, so even a perfect fix is
a bonus upgrade and not a headline flip (`ruffle-matched-hides-regression`
applies in reverse). The two that are genuinely failing (`date`,
`native_objects_swf6`) are the two with the most disposition text against them.

The `watch_virtual_property` precedent does not repeat here — **but it does
repeat one bucket over**, see L4: `avm2/ignored_tests.txt`'s eight
"image-comparison" entries are the s16 analogue (listed, unbacked, and their
stated reason is factually dead).

---

## 3. Upstream drift

**At the graded run the name-set was correct.** Compared the results keys
against upstream `ruffle` `origin/master` `99f4d491b` (fetched 2026-08-12,
i.e. the day before run `31748059158`):

```
avm2   upstream 1244  results 1240  upstream-only 4  results-only 0
avm1   upstream  721  results  718  upstream-only 3  results-only 0
visual / timeline / text / mixed_avm / from_shumway : exact
```

Every upstream-only name is a non-test: `shared_object` (ships
`output1.txt`/`output2.txt`, no `output.txt`), `shared_object_self_ref`,
`avm1/__framework__`, and three nested resource dirs under
`large_preload_from_bytes` / `_from_url`.

**Upstream HAS moved since.** `git ls-remote` puts `ruffle-rs/ruffle` master at
`5ee0627aa`; `gh api compare 99f4d491b...5ee0627aa` over `tests/tests/swfs/`
shows:

- **new**: `avm1/sound_load_multiple_instances`, `sound_load_props`,
  `sound_load_stops_when_dereferenced`, `sound_mixed_attach_load`, and three
  `*_remote` sound tests with `localhost/` fixtures;
  `avm2/matrix3d_determinant`, `matrix3d_precision`, `matrix3d_raw_data`
  (all seven+three ABSENT from our results).
- **modified**: `from_gnash/actionscript.all/Sound-v6`, `-v7`, `-v8` — all
  three are currently **`ruffle_matched`**, so a changed expected file can move
  them in either direction. Treat any move as drift, not as a regression.
- also modified: `avm1/sound_load_start`, `avm1/sound_start_stop`,
  `avm2/stage3d_fractal` (all currently `pass`).

**Expect the s16 denominator to grow ~4443 → ~4453.** The three new
`matrix3d_*` tests land straight onto s15's Matrix3D work and are the cheapest
free-rider check in the session.

**The LOCAL `ruffle-tests/tests/swfs` tree is stale in both directions and is
NOT a drift oracle.** It is missing `avm2/automation_classes`,
`visual/define_bits_lossless2_rgb15`, `avm2/textblock_recreateline` and every
`matrix3d_*`; and it still carries dead dirs
(`avm1/{watch,virtual_property}_special_recursion_*` ×8 — the pre-rename names;
`avm2/av_networking_params`, `avm2/av_tag_data` — deleted upstream;
`avm2/property_priority_scope_cache_order`;
`from_gnash/misc-swfc.all/gotoFrameFromInterval`). Practical consequence for
wave 2: **`avm2/automation_classes` (121/122 missing) and
`avm2/textblock_recreateline` (139/180) cannot be reproduced locally at all** —
they must be re-downloaded first or graded only in CI.

---

## 4. The error-signature axis (the cheapest triage key, and how far it goes)

Only 21 of the 145 non-effective rows carry an `error_signature`. Grouped:

| signature | failing rows | disposition |
|---|---|---|
| `#1006: copyRowTo is not a function` | `avm2/matrix` | **L2** |
| `#1006: getRelativeMatrix3D is not a function` | `from_shumway/…/TransformBasics` | **L2** |
| `#1009 … (accessing field: rawData)` | `avm2/geom_transform` | **L2** |
| `#2007: Parameter targetCoordinateSpace must be non-null.` | `avm2/displayobject_getrect` (14/16), `from_shumway/acid/acid-shapes` (120/120) | s15 called these riders on the Matrix3D `#2007` helper; **that helper landed and these did NOT move** — the `getBounds`/`getRect` sites are separate. `acid-shapes` dies at actual line 7 of 120, so it is a *potential* cascade unlock, not a 120-line rewrite. Worth one probe. |
| `#1006: computeSpectrum is not a function` | `avm2/audio_computespectrum`, `audio/aac`, `audio/g711` | NO-GO (real media decode; s14 host-I/O re-cost) |
| `#1065: Variable {AutomationAction, NativeMenuItem, FullScreenEvent} is not defined` | `automation_classes`, `native_menu_basic`, `stage_display_state` | three missing builtin classes; each is a class-surface add. MED, +3 ceiling — but `automation_classes` is not on local disk (§3) |
| `#1121 duplicate method body` | `verify_method_info_duplicate` | NO-GO, `ACCEPTED_DIFFS.md:114` (fixing it demotes the *passing* `_oob` — the `ruffle-matched-hides-regression` trap, refuted in 3 sessions) |
| `#2067 ExternalInterface not available` | `avm2/external_interface` | 102/105 missing |
| `#1009 …` misc | `esc`, `large_preload_from_bytes`, `RegExp/replace` | `from_shumway/esc` is a real AVM2 bug: `#1009 at Util::Hashtable/makeTable() at global$init()`, then `#1010 … (accessing field: kind)`. 13 actual vs 2 expected. Probe-worthy but the expected output is `388 bytes in 78 ms` (a timing line) → **unpassable as written**; ignore-listed already. |

---

## 5. Near-pass well, regenerated

Ranked by `expected_lines − matching_lines` (results.json truncates the stored
outputs at ~51 lines, so every row below ≤ 20 was re-derived or re-run):

```
miss  exp  act  test
   0   27   39  avm2/button_nested_frame_simple      (extra output only: 2 spare tick cycles)
   0    7   12  from_gnash/misc-swfc.all/sound       (fixture truncated — unpassable, §L7)
   1  115  115  avm1/native_objects_swf6             NO-GO (§2)
   1    2    2  avm2/mouse_pick_avm1_root            -> w1-avm1-child
   1    4    4  avm2/scope_optimizations             L3
   1    2    1  avm2/verify_method_info_duplicate    NO-GO (ACCEPTED_DIFFS.md:114)
   1   20   20  from_avmplus/recursion/pcre_find_fixedlength  DEFER (see below)
   1    1    0  from_avmplus/regress/bug_483783      NO-GO stands
   1    7    7  from_shumway/as3-loader/LoaderTest2  L3
   1    2    2  from_shumway/bitmapdata/getpixel-from-embedded  (200d04 vs 220a06 — decoder rounding)
   1    8    7  mixed_avm/avm2_loads_avm1_v9         -> w1-avm1-child
   1    1    0  text/links_in_scrolled_text          L3
   2    3    1  avm1/sandbox_type_remote  |  2  3  1  avm2/sandbox_type_remote
   2    8    8  avm2/bitmapdata_draw_alpha_erase     L4
   2  128  128  avm2/loader_load                     NO-GO (RUFFLE_VS_FLASH hashbrown order)
   2    2    0  avm2/swz                             NO-GO (ACCEPTED_DIFFS Cat 13)
   2    6    6  from_shumway/acid/acid-morph         L3
   3    9    9  avm2/bom                             NO-GO (same hashbrown order)
   4    4    0  avm2/loader_applicationDomain        NO-GO (Cat 13)
   4    5    4  avm2/method_association              L3
   4    7    3  mixed_avm/avm1_loads_avm2            -> w1-avm1-child
   6   12   12  avm2/stage_scale_factor              L4
   7    8    8  avm2/supercalls_coerce               L6
   8   28   28  avm2/delayed_symbolclass             L3  ★ cheapest real mechanism in the well
  11   49   50  avm2/edittext_tag_indent             L4
  14   33   33  avm2/displayobject_scrollrect        L1  ★
  14   16    5  avm2/displayobject_getrect           #2007 getRect probe
  16  269  269  avm2/bounds_mode                     L1 rider
  18   65   65  avm2/displayobject_hittestpoint_boundary  L1 + edge rule
  22   89   89  avm2/displayobject_transform         L2 rider
  53   74   26  avm2/geom_transform                  L2  ★ (aborts at line 24; ~50 of 53 are cascade)
  56  338  286  avm2/matrix                          L1 ∩ L2
```

Two rows deserve their own note because they *look* like the cheapest in the
corpus and are not:

- **`avm2/button_nested_frame_simple` (miss 0).** Every expected line matches;
  we emit 12 EXTRA lines. `test.toml` says `num_ticks = 3`; we run two further
  tick cycles, and inside them the child's framescripts fire **twice**
  (`Child framescript 2` / `Child framescript 2`,
  `Child framescript 1: myField = 2` / `Child After set: myField = 2` twice).
  Two defects, both in the timeline core. DEFER (L8).
- **`from_avmplus/recursion/pcre_find_fixedlength` (miss 1).** The one diff line
  is avmplus's own failure message, and matching it requires our `String.match`
  to return a ~500-element array where we return 1 (`got: hello,blah,blah,…`
  vs `got: hello`). A regex capture-semantics rewrite for +1. DEFER.

---

## 6. §16.4 lead status, re-verified at HEAD `cd04f80b9`

| §16.4 lead | status now | ruling |
|---|---|---|
| `all_classes/display` 6-row surface (+6) | all 6 still `output_mismatch`; **actual pinned at exactly 1753 lines on all six** while expected runs 1959→2936 | **HANDED OFF** to `w1-all-classes-display`. Add §L5: `events` is 5 more rows with the same pin (731/731/731/731/735) — ask for one joint ruling |
| AVM1-child remainder (depth constant −77824) | 11 rows still failing: `mixed_avm/{avm1_loads_avm2, avm2_loads_avm1, _v9, _v10}`, `avm2/{avm1_root, mouse_pick_avm1_root, mouse_pick_loader_avm1, loader_try_click_root, focus_events_mixed_avm_edittext, selection_onsetfocus_mixed_avm}`, `import_assets/avm1_imports_avm1`. Re-ran `mouse_pick_avm1_root`: **exactly one missing line, `avm1 child clicked`** | **HANDED OFF** to `w1-avm1-child` |
| `number_convert_errors` | unchanged, 831/871 missing; `number_convert_edge_cases` landed in s15 | **DEFER** — structural (`Number$/_convert` + `builtin::` frames + int/uint forwarders) |
| `bug_483783` NO-GO | still the corpus's **only** `runtime_error` (`heap_alloc(76396) failed`) | **NO-GO stands.** Completion mechanism unchanged: avmplus dependent strings + a GC single-block-free change |
| `action_order` DEFER | all 7 rows still failing (`ActionOrderTest3/4/5`, `PlaceAndRemove`, `extend_test`, `test6`, `test11`) | **DEFER stands.** Add `timeline/missing_frame_scripts` and `avm1/looping_child_swf{5,9,32}` to the same arc — see below |
| gnash `array-v5..v8`, `MovieClip-v6/7/8` | unchanged | **NO-GO stands** (s15 counted 6 and 4 independent mechanisms respectively) |
| `eforin_001/002` | unchanged | **NO-GO stands** (avmplus `InlineHashtable` probe order; every passing for-in test depends on our insertion order) |
| ignored-6 audit | done | **CLAIM REFUTED** — §2 |

**Timeline-order arc, consolidated (do not split across wave-2 slots):**
`action_order` ×7 + `timeline/missing_frame_scripts` (a `Spawn` clip keeps
advancing after Flash stops advancing it) + `avm1/looping_child_swf{5,9,32}`
(three rows whose expected AND actual outputs are **byte-identical to each
other** — one mechanism, 207 actual vs 141 expected, nested-sprite advance
order) + `avm2/button_nested_frame_simple`. **12 rows, one arc, +12 ceiling.**
That is the largest single-mechanism family left on the trace board and it is
the right shape for a *solo* session, never a fan-out slot.

---

## 7. Refutations (yield)

1. **s15 board §1 cluster 12, "our double→string is not shortest-round-trip" —
   REFUTED.** `SWFModernRuntime/src/avm2/avm2_value.c:593 shortest_digits()`
   already does Rust/Ruffle-identical shortest round-trip (`%.*e` + `strtod`
   probe from prec 0..17) *plus* the exact-decimal-tie away-from-zero re-round
   at `:504 tie_round_away_from_zero()` that glibc gets wrong. The cited pairs
   are **different doubles**, both already in shortest form:
   `float("1.836970198721029e-16") != float("1.8369701987210297e-16")` and
   `float("3.076923076923077") != float("3.0769230769230775")` (the former is
   exactly `40/13`). The gap is arithmetic — and for the `bounds_mode` /
   `matrix` rows the arithmetic in question is **L1's missing twip
   quantization**. Do not brief a formatting probe.
2. **s15's "`#2007` riders" claim — partly refuted.** The Matrix3D `#2007`
   helper landed in s15; `avm2/displayobject_getrect` and
   `from_shumway/acid/acid-shapes` still carry
   `#2007: Parameter targetCoordinateSpace must be non-null` unchanged. Those
   are `getBounds`/`getRect` sites, not `Matrix3D` sites — a separate edit.
3. **"the ignored-6 have no backing disposition" — REFUTED** (§2). The real
   unbacked bucket is one file over (§L4/L7).
4. **`avm2/matrix`'s error signature is not its whole story.** Adding
   `copyRowTo` alone will not flip it (56 missing lines, one-ULP numbers among
   them). Anyone briefing L2 must price `matrix` jointly with L1.
5. **`from_gnash/misc-swfc.all/sound` is not a 5-line near-pass.** Its expected
   file is a *truncated* capture of an abandoned Ruffle run; the SWF's own
   harness self-reports `FAILED: TOTAL tests run: 1, expected: 2` and prints
   `__END_OF_TEST__`. Unpassable as written.

---

## 8. Method notes for the wave-2 briefs

- Local `-P 5` batching worked (20 tests, two batches, ~7 min/batch wall) but
  the machine had ~16 concurrent `verify_output.py` processes from siblings at
  peak. Nothing flaked; every failure re-verified.
- `results.json` truncates `actual_output`/`expected_output` to ~51 lines with
  a `... (N lines before) ...` marker. For anything priced off a stored diff,
  the `lines` triple (`expected_lines`, `actual_lines`, `matching_lines`) is
  the reliable field; the text is not.
- `expected_lines − matching_lines` and `actual_lines − expected_lines` are
  **different** questions. Two rows in the well have `miss == 0` and fail purely
  on extra output. Sort by both.
- `RecompiledABC/abc0_methods.c` in a test directory is a readable disassembly
  with opcode comments — for AVM2 semantics questions it is faster and more
  reliable than guessing at the missing `Test.as` (most avm2 dirs ship no
  source).
- Three ignore lists now contain entries that are `pass`. Any board that
  computes a "filtered" number is reading a stale filter (§L7).
