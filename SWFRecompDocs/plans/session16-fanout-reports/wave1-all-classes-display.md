# Session 16 · wave 1 · `all_classes/display` — arc scoping

**Agent:** `w1-all-classes-display` (read-only, main tree). **HEAD:** `cd04f80b9`.
**Baseline:** CI run `31748059158` at `3db858cbc` (graphics / full / images=true),
trace 4298/4443 effective.
**Predecessors (diagnosis of record):** `session15-fanout-reports/wave1-t10-descriptor.md`
§4, `session15-fanout-reports/w2-t10-descriptor-report.md`,
`session14-fanout-reports/wave1-t7-describetype.md`, arc doc §16.4.

**Evidence:** six local `verify_output.py --mode=graphics --save-actual` runs at HEAD
(all six `all_classes/display/swf*` rows); a structural XML differ over the parsed
`<type>`/`<factory>` trees (never the runner's positional `matching_lines` —
`results-diff-line-metrics-mislead`); the `dt_*` region of
`SWFModernRuntime/src/avm2/avm2_globals.c:2440-3470`; the display registration in
`SWFModernRuntime/src/avm2/avm2_display.c`; and the oracle
(`~/CC/ruffle/core/src/avm2/globals/flash/display/*.as`, `api_version.rs`,
`tests/tests/swfs/avm2/all_classes/display/Test.as`).

---

## 0. VERDICT

### **GO — +6, one dedicated wave-2 agent, ~900-1,100 lines, MED-HIGH confidence.**

Conditions: (a) the agent must build a **generator**, not hand-transcribe — 360
descriptor rows / 296 parameters / 18 constructors is past the hand-transcription
error budget for an all-or-nothing surface; (b) the agent owns
`avm2_globals.c` `dt_*` **and** `avm2_display.c` alone (no sibling may touch either);
(c) the s15 API-version formula must be **corrected first** (§2.4) or ~30 gates land
on the wrong version.

### Headline corrections to the brief

| brief claim | verdict |
|---|---|
| "+6 all-or-nothing" | **half-refuted.** Truly one grade per row, but `swf9` alone needs **235 of the 360** descriptor rows (65 %) — the other five rows cost only **+35 %** on top. There is no wall; there is a shared 65 % floor. Attempting `swf9` alone is the *worst* value in the arc. |
| "slices 1-5 built every mechanism except the declaredBy re-point" | **REFUTED on two counts.** (1) The declaredBy shape is **not the bulk** — it is 48 of ~1,400 element diffs at swf30 (3.4 %). 90 % of the work is capability **A** (type/parameter descriptor data), which s15 *did* build — this is a **data** arc, not a mechanism arc. (2) Three *further* mechanisms are missing beyond the re-point: a describe-only `access` override (writeonly halves), a per-**described**-class member **hide**, and `implementsInterface` wiring for six interfaces we do not register. |
| "the s15 XMLDocument fix demonstrates the needed shape" | **PARTIALLY REFUTED.** The XMLDocument fix mutates `Avm2PropEntry.defining_class` in the live vtable. `defining_class` also drives `avm2_function_new` scope binding, `class_derive_depth` override arbitration (`avm2_class.c:407`) and **callstack frame naming**. Applying it to Stage's 30 overrides would rename `flash.display::Stage/set alpha()` frames — and `stage_properties2` grades 2071 throws. The correct generalization is **two describe-only fields** (§4.6), which would also have fixed XMLDocument with zero runtime risk. |
| "the 6 rows share one class surface" | **CONFIRMED.** Our actual output is **byte-identical across all six SWF versions** (md5 `eb0d2b08…`, 1753 lines each) — we do no version gating whatsoever on `flash.display`. |

### What makes this GO rather than DEFER

* **Every input is machine-derivable.** All 65 classes have `.as` files in
  `~/CC/ruffle/core/src/avm2/globals/flash/display/` (checked: 65/65 present), with
  full signatures and `[API("N")]` annotations. The six expected files are the
  verification oracle. No judgement calls, no reverse-engineering.
* **The structure is already right.** Zero `<extendsClass>` diffs, zero `<type>`/
  `<factory>` attribute diffs on the 51 classes we emit. Only **2** members exist in
  our runtime that Flash never has (§3.4). The hierarchy work is done.
* **Iteration is cheap.** Each display row compiles in 0.7 s and runs in 0.27 s once
  the runtime lib is built; the whole 6-row set grades in under 10 s.
* **s15 proved the consumption points don't move as the table grows** (12 rows → 90
  rows, 45 canaries green).

### What would flip this to NO-GO (completion mechanism, per BRIEFS_COMMON §s15 lessons)

If a wave-2 agent lands the swf30 row and cannot get **all five lower versions**
green within its budget, the arc yields **+1, not +6** — and swf30 is the *most*
expensive single row. The named checkpoint: after the generator emits the table,
`swf30` and `swf9` must be graded **together**; if `swf9` still shows unpaired
extras after the class + member gates are applied, stop and report — that means the
gate model is wrong and the remaining four rows will not follow.

---

## 1. The six tests

`ruffle-tests/tests/swfs/avm2/all_classes/display/{swf9,swf10,swf11,swf12,swf13,swf30}`
(one `test.swf` + `output.txt` each, `num_frames = 1`, **no `known_failure`**
upstream). Fixture: `~/CC/ruffle/tests/tests/swfs/avm2/all_classes/display/Test.as`
— 65 `flash.display` class names, `getDefinitionByName` each (miss ⇒
`"<Name> not accessible"`), `describeType(klass, FLASH10_FLAGS & ~INCLUDE_METADATA)`,
printed through `normalizeXML()` which **`sort()`s children at every level**.

**Disposition check (BRIEFS_COMMON §2):** none of the six appears in
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt` or
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`. Nothing is dispositioned away.
(The five `all_classes/events/*` rows ARE ignore-listed as upstream `known_failure`
and are worth **zero** — they are not a rider here.)

Baseline (merged `results_graphics.json` at `3db858cbc`) and local re-measure at HEAD
agree exactly:

| test | status | expected | actual | runner `matching_lines` |
|---|---|---|---|---|
| `all_classes/display/swf9`  | output_mismatch | 1959 | 1753 | 17 |
| `all_classes/display/swf10` | output_mismatch | 2569 | 1753 | 31 |
| `all_classes/display/swf11` | output_mismatch | 2593 | 1753 | 35 |
| `all_classes/display/swf12` | output_mismatch | 2593 | 1753 | 35 |
| `all_classes/display/swf13` | output_mismatch | 2671 | 1753 | 21 |
| `all_classes/display/swf30` | output_mismatch | 2936 | 1753 | 14 |

`matching_lines` is a positional artifact and is **not** used anywhere below.
`swf11` and `swf12` expected files are byte-identical (md5 `03eec1f2…`); all six
actuals are byte-identical.

---

## 2. Premise attacks

### 2.1 "All-or-nothing" — half true, and the half that is false changes the price ★★

Grading is per-file, so yes, each row flips only when *its* file matches exactly.
But the six rows are nested, not parallel. Distinct descriptor rows
`(declaringClass, kind, name)` that need work, measured per version:

| row | expected rows | rows needing a descriptor entry | distinct params |
|---|---|---|---|
| swf9 | 296 | **235** | 223 |
| swf10 | 412 | 322 | 264 |
| swf11 | 418 | 328 | 264 |
| swf13 | 429 | 339 | 280 |
| swf30 | 450 | **360** | 296 |

`swf9` is 65 % of the whole arc's data for 1/6 of the flips; going from `swf9` to all
six costs **+125 rows and the gate tables**. So "any partial table yields +0" is the
right *grading* statement and the wrong *economics* statement: the marginal five rows
are cheap, which is exactly why this is GO.

### 2.2 "The declaredBy re-point is the missing shape" — REFUTED as the bulk ★★

Structural element-level diff at swf30 (paired by `(kind, name, uri)` inside each
class block, so a declaredBy difference shows up as an attribute diff, not as an
add/remove pair):

```
A-type-star (type="*"/returnType="*" → real type)     771   ← s15 capability A, DATA
A-params    (missing <parameter> children)            451   ← s15 capability A, DATA
E-missing-member                                      100
G-missing-class                                        14
H-access-half (writeonly reported readwrite)           13   ← NEW mechanism
X-attr:declaredBy(+type/returnType)                    48   ← the "re-point" shape
X-attr:type (implementsInterface + 4 uint consts)      16
C-extra-member                                          6
```

The re-point is **48 of ~1,419** (3.4 %). The arc is 90 % `DtDescClass` data entry
against the table s15 already shipped.

### 2.3 "Blocked by something else?" — yes, four things, all small ★

1. **Six interfaces we do not register at all**: `IBitmapDrawable`, `IDrawCommand`,
   `IGraphicsFill`, `IGraphicsPath`, `IGraphicsStroke` (+ `GraphicsShaderFill`'s
   membership). 20 missing `<implementsInterface>` lines at swf30. Mechanism exists
   — `avm2_display.c:8908-8913` already hand-wires `interface_count`/`interfaces` on
   builtins for `IGraphicsData`.
2. **`writeonly` accessor halves**: `DisplayObject.blendShader` and
   `Shader.byteCode` are setter-only in playerglobal; we register both halves.
   `DtDescMember.access` exists but is consulted only on the *synthetic* path.
3. **`soundTransform` is declared on the wrong class**: we put it on
   `InteractiveObject` (`avm2_display.c:13795-13797`, with a comment already
   admitting it belongs on Sprite + SimpleButton); Flash declares it **twice**, on
   `Sprite` and on `SimpleButton`, and `InteractiveObject`/`DisplayObjectContainer`/
   `Loader`/`Stage` do **not** have it. Needs a per-**described**-class hide.
4. **`StageQuality` constants are wrong** (`avm2_display.c:14293-14294`): we ship
   `EIGHT_X_LINEAR`/`SIXTEEN_X_LINEAR`; playerglobal has
   `HIGH_8X8`/`HIGH_8X8_LINEAR`/`HIGH_16X16`/`HIGH_16X16_LINEAR`
   (`~/CC/ruffle/.../StageQuality.as`). These are the **only two** members in our
   whole `flash.display` surface that Flash never has at any version. Grep proves no
   test references either name (only the *values* `"8x8linear"` etc., in
   `displayobject_transform`), so the rename is free and is a real correctness fix.

### 2.4 The s15 API-version formula is WRONG below ordinal 12 — must be fixed first ★★

`wave1-t10-descriptor.md` §2.2 records `SWF = 12 + (N - 672) / 2`, "verified against
all six annotations s14 recorded", and adds "odd ordinals are AIR-only and round
**up** to the next SWF version". Both halves break on this arc.

`~/CC/ruffle/core/src/avm2/api_version.rs` (ordinal = `N - 660`) is **not** uniformly
strided below 12, and its `TRANSFER_TABLE` maps every `AIR_*` version to
`VM_INTERNAL` — i.e. **hidden**, not rounded up — under a Flash-Player runtime.
Verified empirically against the six expected files:

| `[API("N")]` | ordinal | ApiVersion | first SWF version that shows it | s15 formula would say |
|---|---|---|---|---|
| 661 | 1 | AIR_1_0 | **never** (`Stage.nativeWindow` absent everywhere) | 6.5 |
| 662 | 2 | FP_10_0 | **10** (`rotationX`, `z`, `blendShader`, `drawPath`, `unloadAndStop`, `currentFrameLabel`) | 7 |
| 665 | 5 | FP_10_0_32 | **10** (`Stage.wmodeGPU`) | 8.5 |
| 667 | 7 | FP_10_1 | **10** (`uncaughtErrorEvents`, `startTouchDrag`, `stageVideos`) | 9.5 |
| 668, 671 | 8, 11 | AIR_2_0, AIR_2_6 | **never** (`Stage.orientation`, `supportedOrientations`) | 10 / 11.5 |
| 670 | 10 | FP_10_2 | **11** (`needsSoftKeyboard`, `Stage.color`, `allowsFullScreen`, `softKeyboardRect`) | 11 ✓ |
| 672 | 12 | SWF_12 | 12 | 12 ✓ |
| 674 | 14 | SWF_13 | 13 (`removeChildren`, `isPlaying`, `Graphics.cubicCurveTo`, `displayContextInfo`) | 13 ✓ |
| 680 / 682 / 686 / 690 | 20 / 22 / 26 / 30 | SWF_16/17/19/21 | 16 / 17 / 19 / 21 (all ⇒ swf30 only) | ✓ |

**Correct rule for the generator:**
```
ord = N - 660
ord >= 12 :  even -> min_swf = 12 + (ord - 12) / 2 ;  odd -> AIR-only, HIDE ALWAYS
ord <  12 :  {0: always, 2: 10, 5: 10, 7: 10, 10: 11} ; all others AIR-only, HIDE ALWAYS
```
(`ord < 12` FP entries are FP_10_0/FP_10_0_32/FP_10_1 → SWF 10, FP_10_2 → SWF 11 —
SWF file version stepped 10→11 at FP 10.2.) This affects **~30 of the 51** per-member
gates and **~25 of the 32** class gates; getting it wrong silently costs all five
lower rows. **Fold the correction back into `wave1-t10-descriptor.md` §2.2 / the arc
doc**, because the shipped `min_swf` comment in `avm2_globals.c:2470-2477` repeats it.

### 2.5 Ordering risk — nil ★

`normalizeXML()` `sort()`s children at every level (verified in the display fixture,
identical helper to xml/accessibility/display3D). Synthetic members may be appended
in any order; only attribute order inside an element matters, and our attribute order
is already proven by the 15 passing `all_classes` rows.

### 2.6 "Fitting the tests" objection — answered

The table can be generated from Ruffle's `.as` declarations (the actual playerglobal
API, independently versioned) and *verified* against the expected files, rather than
transcribed from the expected files. s15 did the reverse (generated from expected,
cross-checked against `.as`); either is defensible, but with 65 `.as` files present
the `.as`-first direction is strictly better here and is what §5 specifies.

---

## 3. Per-test line accounting — every line assigned

Structural accounting; identity holds exactly for all six rows
(`expected = notAcc + newClassLines + matched + missing`,
`actual = notAcc + gatedClassLines + matched + extra`, verified by script):

| row | exp | act | exp "not accessible" | act "not accessible" | lines in classes we lack | lines in classes Flash hides | matched | missing | extra |
|---|---|---|---|---|---|---|---|---|---|
| swf9  | 1959 | 1753 | 32 | 14 | 36  | 281 | 647 | 1244 | 811 |
| swf10 | 2569 | 1753 | 6  | 14 | 130 | 54  | 849 | 1584 | 836 |
| swf11 | 2593 | 1753 | 6  | 14 | 130 | 54  | 849 | 1608 | 836 |
| swf12 | 2593 | 1753 | 6  | 14 | 130 | 54  | 849 | 1608 | 836 |
| swf13 | 2671 | 1753 | 5  | 14 | 130 | 16  | 881 | 1655 | 842 |
| swf30 | 2936 | 1753 | 0  | 14 | 331 | 0   | 897 | 1708 | 842 |

### 3.1 The `missing`/`extra` columns, by cause (line-exact)

**swf30** — missing 1708, extra 842:

| cause | missing lines | extra lines | mechanism |
|---|---|---|---|
| member element rewritten in place (`type="*"`→real / declaredBy / access) — accessor | 562 | 562 | **A** (+ new §4.6/§4.7 for 48 of them) |
| …same, method | 270 | 270 | **A** |
| …same, constant (`BitmapDataChannel` `int`→`uint`) | 4 | 4 | **D** (built) |
| `<parameter>` children | 514 | — | **A** |
| `</method>` closers (self-closing → open element) | 242 | — | **A** |
| `<constructor>` + `</constructor>` | 16 + 16 | — | **A** (`ctor_params`, built) |
| members absent from our runtime (accessor 30, variable 22, method 8, constant 4) | 64 | — | **E** synthetic (built) / real registration |
| `<implementsInterface>` | 20 | — | **NEW** §4.8 |
| members we have that Flash never has (`StageQuality.{EIGHT,SIXTEEN}_X_LINEAR`) | — | 2 | rename, §2.3(4) |
| `soundTransform` on 4 wrong classes | — | 4 | **NEW** §4.7 |
| **totals** | **1708** | **842** | |

**swf9** — missing 1244, extra 811. Same shape, plus the version axis:

| cause | missing | extra |
|---|---|---|
| member rewritten in place (accessor 434 / method 204 / constant 4) | 642 | 642 |
| `<parameter>` + `</method>` | 373 + 184 | — |
| `<constructor>` + closer | 5 + 5 | — |
| members absent from our runtime | 22 | — |
| `<implementsInterface>` | 13 | — |
| **members we emit that Flash hides at SWF 9** (accessor 111, method 56) | — | **167** |
| `StageQuality` wrong constants | — | 2 |
| **totals** | **1244** | **811** |

swf10/11/12/13 sit monotonically between the two (per-member-gate extras
167 → 59 → 36 → 36 → 28 → 4 as the version rises).

### 3.2 Class-level axis (fully derived)

| version | classes accessible (expected) | classes we expose | need a class gate | need to be created |
|---|---|---|---|---|
| swf9 | 33 | 51 | 21 | 3 |
| swf10 | 59 | 51 | 3 | 11 |
| swf11/12 | 59 | 51 | 3 | 11 |
| swf13 | 60 | 51 | 2 | 11 |
| swf30 | 65 | 51 | 0 | 14 |

32 distinct classes need `avm2_builtin_class_api` gating (26 at SWF 10, 1 at 13,
5 at 30). 14 classes must be created:
`AVLoader`(30) `ActionScriptVersion`(all) `BitmapEncodingColorSpace`(30)
`ColorCorrection`(10) `ColorCorrectionSupport`(10) `GraphicsShaderFill`(10)
`IBitmapDrawable`(all) `IDrawCommand`(10) `IGraphicsFill`(10) `IGraphicsPath`(10)
`IGraphicsStroke`(10) `JPEGXREncoderOptions`(30) `NativeMenu`(10) `SWFVersion`(all).

Most are cheap: `NativeMenu` is an **empty** subclass of `EventDispatcher` (32 lines,
all inherited); `AVLoader` is `Loader` + one `load` method (173 lines, all but 3
inherited); five are pure constant bags; five are empty marker interfaces.

### 3.3 The re-point rows in full (29 distinct rows, both directions)

*Flash declares it on the BASE, we over-attribute to the subclass* — 30 `Stage`
accessors registered as real 2071-throwing overrides (`avm2_display.c:14211-14247`):
`accessibilityImplementation accessibilityProperties alpha blendMode cacheAsBitmap
contextMenu filters focusRect mask mouseEnabled name opaqueBackground rotation
rotationX rotationY rotationZ scale9Grid scaleX scaleY scaleZ scrollRect tabEnabled
tabIndex transform visible x y z` → `flash.display::DisplayObject` (or
`::InteractiveObject` for the six InteractiveObject-surface ones).
**Not** in this set — Flash really does declare these on `Stage`, and we already
agree: `height`, `width`, `textSnapshot`, `constructor`, `colorCorrection`.

*Flash declares it on the SUBCLASS, we report the ancestor* —
`Stage`: `addChild addChildAt addEventListener dispatchEvent hasEventListener
mouseChildren numChildren removeChildAt setChildIndex swapChildrenAt willTrigger`;
`Loader`: `addChild addChildAt removeChild removeChildAt setChildIndex`;
`LoaderInfo`: `dispatchEvent`.

*Declared on a different sibling* — `soundTransform`: report `flash.display::Sprite`
on `Sprite`/`MovieClip`, `flash.display::SimpleButton` on `SimpleButton`, and **hide**
on `InteractiveObject`/`DisplayObjectContainer`/`Loader`/`Stage`.

### 3.4 Members we have that Flash never has

Exactly **two**, both `StageQuality` constants (§2.3-4). Everything else we register
under `flash.display` is either correct or version-gated. That is a strong signal that
the class surface itself is sound and this really is a descriptor arc.

---

## 4. Mechanisms — built vs. new

| # | capability | status | needed for |
|---|---|---|---|
| A | type / returnType / `<parameter>` / `ctor_params` descriptors | **BUILT** (s14 + s15, `DtDescClass`) | 90 % of the lines |
| B | class-level API gate (`avm2_builtin_class_api`) | **BUILT** (s14) | 32 classes |
| C | per-member / per-const API gate (`DtDescMember.min_swf`) | **BUILT** (s15) | 51 members |
| D | per-const type override (`DtDescConst`) | **BUILT** (s15) | 4 `BitmapDataChannel` consts |
| E | describe-only synthetic members (`dt_collect_synthetic`) | **BUILT** (s15) | 79 rows |
| **F** | **describe-only `declared_by` on a row of THIS class's table** | **NEW, ~8 LOC** | Stage's 30 over-attributed accessors, soundTransform on Sprite/SimpleButton/MovieClip |
| **G** | **per-described-class `redeclares[]`** (report an inherited member as this class's own) | **NEW, ~25 LOC** | Stage ×11, Loader ×5, LoaderInfo ×1 |
| **H** | **per-described-class `hides[]`** | **NEW, ~15 LOC** | soundTransform on 4 classes |
| **I** | **`access` override on the non-synthetic path** | **NEW, ~5 LOC** | `blendShader`, `Shader.byteCode` |
| **J** | interface registration + `implementsInterface` wiring | pattern exists (`avm2_display.c:8908`) | 6 interfaces × ~13 classes |

### 4.6 Why F+G, and not the XMLDocument `defining_class` mutation

The s15 XMLDocument fix (`avm2_xml.c:3630-3646`, commit `941d19f33`) walks
`doc->ivtable` and rewrites the copied entry's `defining_class`. That is a **live
vtable mutation**, and `defining_class` is read at runtime by
`avm2_function_new` (scope/`super` binding, `avm2_class.c:903`, `avm2_ops.c:512/593`),
by `class_derive_depth` override arbitration (`avm2_class.c:407-408`), and by
callstack frame naming. Applying it to Stage's overrides would rename every
`flash.display::Stage/set x()` frame to `flash.display::DisplayObject/set x()`; the
`stage_properties2` / `stage_overriden_setters` rows grade 2071 throws.

**F** is safe because the lookup key is already the entry's `defining_class`:
`dt_desc_apply(m, dt_desc_find(e->defining_class), …)`. For a `Stage` instance,
`alpha`'s `defining_class` **is** `Stage` (we re-registered it), so the override lives
in `Stage`'s own `DtDescClass` row and can never leak onto `DisplayObject`'s own
`alpha`. The s15 report's objection ("the row that would carry the override is
XMLNode's") applies only to the *inherited*, unmodified-entry case — which is exactly
what **G** exists for. **G would also have fixed XMLDocument with zero runtime risk**
and should replace the mutation there as a follow-up.

---

## 5. Implementation plan

### Files (and the sibling-conflict map)

| file | region | what changes |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `2440-2510` structs; `2935-2977` `dt_desc_classes[]`; `3016` `dt_desc_member_hidden`; `3035` `dt_desc_apply`; `3061` `dt_collect_vtable`; `3173` `dt_collect_static_consts`; `3245` `dt_collect_synthetic`; `3301` `dt_collect_ctor` | +3 struct fields (`declared_by`, class-level `redeclares[]`, `hides[]`) + ~50 LOC of mechanism + **~700-850 lines of generated table** |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `8900-9000` (IGraphicsData block), `13795` (soundTransform — comment only), `14182-14310` (Stage + constant bags) | 14 new classes, 6 interfaces + `implementsInterface` wiring, 21 existing `avm2_builtin_class` → `avm2_builtin_class_api` conversions (the other 11 gated classes are new), StageQuality constant fix. ~150-200 lines |

**Exclusive ownership required.** Any sibling touching `avm2_globals.c` `dt_*` or
`avm2_display.c` will conflict textually. This is one agent's job end to end — the
same conclusion s14 and s15 reached for this table.

No recompiler change, no `abc_emit.cpp`, no generated-ABI move ⇒ `RecompiledABC` stays
valid; `--recompile` is hygiene, not a requirement.

### Slices (each independently verifiable; the row only flips at the end)

1. **Generator** (scratchpad, not committed). Parse
   `~/CC/ruffle/core/src/avm2/globals/flash/display/*.as` + `events/EventDispatcher.as`:
   class decl (`final`, `extends`, `implements`, class-level `[API]`), members
   (`function get/set`, `function`, `var`, `static const`), parameter types +
   defaults, member-level `[API]`. Map `[API("N")]` → `min_swf` with the **corrected**
   §2.4 rule. Emit `DtDescMember`/`DtDescParam`/`DtDescConst`/`DtDescClass` text in the
   existing s15 style. Then **diff the generator's model against the six expected
   files** and fail loudly on any mismatch — that diff is the acceptance test and it
   costs no runtime build.
2. **Mechanisms F/G/H/I** (~55 LOC in the `dt_*` region). Land with the s15 rows
   untouched; re-grade the 15 passing `all_classes` rows before adding display data.
3. **Class layer** in `avm2_display.c`: 14 new classes, 6 interfaces + wiring, 32
   class gates, StageQuality fix.
4. **Table** into `dt_desc_classes[]` (57 entries; `flash.events::EventDispatcher`'s
   existing 6-member row is reused, not duplicated).
5. **Gate + re-point + hide tables**: 51 `min_swf` marks, 29 re-point rows, 4 hides,
   2 access overrides, 4 `uint` const overrides.
6. **Grade all six**, then the canary set.

**Recommended commit order for early banking:** none. Unlike the s15 slice plan, no
intermediate state here flips a row. Land it as one patch or not at all — but
checkpoint at slice 1's model-vs-expected diff, which is free and decides the arc.

---

## 6. Canary set

**Tier 1 — describeType consumers (the complete graded set; verified by
`grep -rn describeType --include=*.as ruffle-tests/tests/swfs`):**
`describe_type_basic`, `describe_type_json`, `describe_type_metadata`,
`describe_type_native`, `number_autoconv`, `function_proto_created`, `static_length`,
`displayobject_name_from_timeline`, `font_enumeratefonts` (last two *import* it but
never call it — cheap, include anyway), and
`from_avmplus/regress/bug_539328` — **`ruffle_matched` at baseline; a move to plain
`pass`/`fail` is a REGRESSION signal** (`ruffle-matched-hides-regression`). This row
is the interface-describeType pin and matters doubly here (6 new interfaces).

**Tier 2 — `all_classes` rows already passing (the table this arc grows 5×):**
`errors/{swf9,swf10,swf30}`, `security/{swf11,swf12,swf13,swf30}`,
`display3D/{swf12,swf13,swf30}`, `xml/{swf9,swf30}`,
`accessibility/{swf9,swf10,swf30}` — 15 rows. `security/swf11` and `display3D/swf12`
are the gate-from-below pins; `display3D/swf12` is also the `Context3DClearMask`
`int` pin that proves a global unsigned→uint rule is wrong.

**Tier 3 — `avm2_display.c` blast radius (this is the tier s15 never had to run):**
`stage_properties`, `stage_properties2`, `stage_overriden_setters`,
`stage_displayobject_properties`, `stage_access`, `stage_mousechildren`,
`stage_mouseenabled`, `stage_display_state`, `stage_invalidate`,
`stage_loaderinfo_properties`, `stage_stage3Ds_vector`,
`stage_domain_getQualifiedDefinitionNames` (checked: enumerates the **user** domain
only, so new builtins are invisible to it — still grade it),
`displayobject_transform` (uses the StageQuality *values*),
`displayobject_metaData`, `displayobject_invalid_props`, `displayobject_subclass`,
`simplebutton_soundtransform`, `simplebutton_childprops`,
`sound_rootless`, `soundchannel_soundtransform_exists`,
`graphics_draw_path`, `graphics_draw_triangles`, `graphics_path`,
`bitmapdata_draw`, `bitmapdata_draw_stage`, `bitmapdata_drawwithquality`,
`loader_events`, `loader_load`, `abstract_classes`.

**Tier 4 — API-gate axis:** `stage3d_bitmap` (SWF 13), `stage3d_x_y`,
`stage3d_errors`, `stage3d_errors_swf_29`, `context3d_creation`,
`json_version_gated`, `cross_api_version_call_older`,
`cross_api_version_call_newer`, `air_hidden_lookup`.

**Tier 5 — must NOT drift:** `all_classes/events/{swf9,swf10,swf11,swf12,swf30}`
stay `output_mismatch` (ignore-listed upstream `known_failure`).

**Canary blind spot (BRIEFS_COMMON s15 lesson):** the standing *render* canary does
not exercise any of this — the patch is trace-only, `images=false`, zero pixel-axis
effect. The covering grade is Tier 3 above.

---

## 7. Could it be more, or fewer?

**More: no.** The five `all_classes/events/*` rows are the only other tests blocked on
the same table, and they are ignore-listed as upstream `known_failure` — effective
value **zero**. No non-`all_classes` test consumes these descriptors (Tier 1 is the
complete `describeType` grep, and none of those subjects is a `flash.display` class).
There is no rider here, unlike s15's `accessibilityimplementation`.

**Fewer: possible, and this is the real risk.** The credible failure modes, in
descending likelihood:
1. The §2.4 gate mapping is applied as s15 documented it ⇒ **+1** (swf30 only).
2. One wrong type string anywhere ⇒ that row alone fails; if it is in a
   version-independent class, **all six** fail. Mitigated entirely by slice 1's
   model-vs-expected diff.
3. `Stage`'s bidirectional re-point is done with the XMLDocument `defining_class`
   mutation ⇒ Tier 3 stack-trace canaries move; recoverable by switching to F/G.
4. Budget: ~900-1,100 lines including a generator is a full wave-2 session. If the
   agent also has to debug an unrelated area, it will not finish. **Give it nothing
   else.**

---

## 8. Board correction for `polish-sweep-arc.md` §16.4

> Trace: all_classes/display 6-row surface (+6 all-or-nothing; slices 1-5 built every
> mechanism except the declaredBy/defining_class re-point shape, which the s15
> XMLDocument fix now demonstrates)

should become

> **all_classes/display: GO, +6, one dedicated agent, ~900-1,100 lines.** Measured at
> `cd04f80b9`: our output is byte-identical across all six SWF versions (we do zero
> version gating on `flash.display`); 360 descriptor rows / 296 params / 18
> constructors / 57 declaring classes are needed, of which swf9 alone needs 235 — the
> other five rows cost +35 %, so it is a shared floor, not a wall. The declaredBy
> re-point is **3.4 %** of the diff, not the bulk: 90 % is `DtDescClass` **data**
> (capability A, already built). Four *additional* mechanisms are needed beyond the
> re-point — describe-only `access` override (2 rows), per-described-class member
> hide (`soundTransform`, 4 rows), `implementsInterface` wiring for 6 unregistered
> interfaces (20 lines), and 14 new classes (mostly constant bags / empty markers /
> `NativeMenu` = empty EventDispatcher subclass / `AVLoader` = Loader + one method).
> **The s15 API-version formula is wrong below ordinal 12 and mis-states the AIR rule
> (AIR ordinals are HIDDEN under Flash Player, not rounded up); ~30 of the 51
> per-member gates and ~25 of the 32 class gates depend on the corrected rule** —
> see `session16-fanout-reports/wave1-all-classes-display.md` §2.4. Do NOT reuse the
> s15 XMLDocument `defining_class` mutation for Stage: `defining_class` drives
> callstack frame naming and `stage_properties2` grades 2071 throws; use two
> describe-only fields instead (§4.6), which would also have fixed XMLDocument.
> Only **two** members exist in our runtime that Flash never has
> (`StageQuality.{EIGHT,SIXTEEN}_X_LINEAR` — misnamed; playerglobal has
> `HIGH_8X8[_LINEAR]`/`HIGH_16X16[_LINEAR]`), and there are **zero**
> `<extendsClass>` / `<type>` attribute diffs: the class surface is sound, this is a
> descriptor-data arc. No rider (`all_classes/events/*` is ignore-listed
> `known_failure`, worth 0).

---

## 9. Reproduction

```bash
cd /home/robert/CC/SWFRecomp-CC
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
  --test=all_classes/display/swf30 --mode=graphics --save-actual=/tmp/d30.actual
```
Grade with a structural set-diff of parsed `<type>`/`<factory>` children keyed by
`(kind, name, declaredBy)` — **never** the runner's positional `matching_lines`
(14/2936 on swf30, which reads as "structurally broken" when `<extendsClass>` and
every `<type>` attribute already match). Analysis scripts used for this report live in
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/b9a79013-.../scratchpad/acd/`
(`cls.py`, `rows.py`, `gate.py`, `acct.py`, `acct2.py`) — throwaway, not committed.
