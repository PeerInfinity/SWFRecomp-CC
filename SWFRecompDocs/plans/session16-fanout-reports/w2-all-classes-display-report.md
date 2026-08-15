# Session 16 · wave 2 · `all_classes/display` — implementation report

**Agent:** `w2-all-classes-display` (worktree `agent-a15a954ea7dd4a5cf`).
**Base:** `cd04f80b9`. **Brief of record:** `wave1-all-classes-display.md`.
**Patch:** `w2-all-classes-display.patch` (same directory).

---

## 0. VERDICT — **GO, +6 / +6, ZERO REGRESSIONS.**

**All six `all_classes/display` rows PASS; all 70 canary rows landed on exactly
their baseline status.**

The wave-1 pricing held exactly: six flips, one agent, one patch.
The three wave-1 conditions were all met — a generator (not hand
transcription), exclusive ownership of the `dt_*` tables, and the **corrected**
API-version rule applied first.

| row | before | after | expected lines | our lines after |
|---|---|---|---|---|
| `all_classes/display/swf9`  | output_mismatch (1753/1959) | **pass** | 1959 | 1959 |
| `all_classes/display/swf10` | output_mismatch (1753/2569) | **pass** | 2569 | 2569 |
| `all_classes/display/swf11` | output_mismatch (1753/2593) | **pass** | 2593 | 2593 |
| `all_classes/display/swf12` | output_mismatch (1753/2593) | **pass** | 2593 | 2593 |
| `all_classes/display/swf13` | output_mismatch (1753/2671) | **pass** | 2671 | 2671 |
| `all_classes/display/swf30` | output_mismatch (1753/2936) | **pass** | 2936 | 2936 |

The wave-1 **named checkpoint** ("grade swf30 and swf9 together; if swf9 still
shows unpaired extras after the class + member gates, the gate model is wrong")
was cleared on the first build that carried the corrected gate rule: swf30 and
swf9 flipped in the same build, and swf10-13 followed with no further change.

---

## 1. NEW FILES IN THIS PATCH (BRIEFS_COMMON s15 lesson)

Four, all under `tools/descriptor/`, none compiled or linked:

```
tools/descriptor/as_model.py                 (parser + [API] -> min_swf rule)
tools/descriptor/xml_model.py                (model -> describeType elements;
                                              expected-file parser)
tools/descriptor/check_model.py              (grader: model vs the six oracles,
                                              and --actual: ours vs expected)
tools/descriptor/gen_display_descriptors.py  (C emitter)
```

**There is NO new C source or header.** The generated tables are spliced
directly into `SWFModernRuntime/src/avm2/avm2_globals.c` between two markers.
That was a deliberate reversal of my first attempt, which put them in a new
`avm2_desc_display.h`: `verify_output.py` builds by copying an **explicit list**
of source files into a flat directory (`verify_output.py:2154`), so a new header
is invisible to it unless the list is edited — and it would also have to be
added to CMakeLists and to the Emscripten build. That is precisely the s15
incident of record, and the first build failed exactly that way
(`avm2_globals.c:2992:10: fatal error: avm2_desc_display.h: No such file`).
Everything in the block is `static`, so nothing leaks past the TU.

Coordinator staging note: `git apply --stat` will show `tools/descriptor/*.py`
as new; stage those four by name along with the five modified C/H files.

---

## 2. Files changed

| file | what |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_globals.c` | +4 mechanism pieces (~110 LOC) and the **1,114-line generated table block**. Corrected the shipped `min_swf` comment (it stated the wrong API-version rule). |
| `SWFModernRuntime/src/avm2/avm2_display.c` | 6 marker interfaces + `disp_implements`, 9 new classes, 11 class API gates, the StageQuality constant fix, AVLoader. ~190 lines. |
| `SWFModernRuntime/src/avm2/avm2_pixelbender.c` | 7 `avm2_builtin_class` → `avm2_builtin_class_api(..., 10)` (the Shader family). |
| `SWFModernRuntime/src/avm2/avm2_bitmap.c` | `BitmapData implements IBitmapDrawable`; PNG/JPEGEncoderOptions gated to 16. |
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | `Stage3D` gated to 13. |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | one declaration (`avm2_display_ibitmapdrawable`). |

**Sibling-overlap check (coordinator's mid-task note).** `w2-geom` owns
`point_transform_native` (~:3813) and the flash.geom registration
(Matrix/Transform, ~:14022+ in the original numbering). My `avm2_display.c`
edits are at the graphics-extras block (~:8900-9010), the DisplayObject/Loader
registration (~:13746/:13899) and the flash.display constant-bag block
(~:14290-14400). No function or line is shared. `avm2_bitmap.c` is touched only
at `avm2_register_bitmap`'s two registration sites, not in any pixel path.

---

## 3. Method — the generator, and why it is not "fitting the tests"

`tools/descriptor/as_model.py` parses Ruffle's playerglobal ActionScript stubs
(`<ruffle>/core/src/avm2/globals/**/*.as` — 459 classes, 65 of them
`flash.display`): class modifiers, `extends`/`implements`, constructors,
`function`/`get`/`set`/`var`/`const` members with full parameter types and
defaults, and the `[API("N")]` annotations. `xml_model.py` renders that model
as the `describeType` element tree, resolving type names through each file's
own imports.

**The acceptance test is free and it ran first.** `check_model.py` diffs the
model against all six expected files element-for-element, keyed on
`(kind, name)` inside each class block:

```
$ python3 tools/descriptor/check_model.py
== swf9: 0 element mismatches      == swf12: 0
== swf10: 0                        == swf13: 0
== swf11: 0                        == swf30: 0
TOTAL mismatches: 0
```

That is 0 out of ~2,900 elements across six versions, derived from the `.as`
declarations with **no reference to the expected files as a source**. The
expected files are only ever read as the oracle. This is the direction wave-1
§2.6 asked for, and it is the reason the arc landed in one build cycle rather
than an iteration loop.

`check_model.py --actual OURS EXPECTED` is the same differ pointed at one of
our own `--save-actual` captures; it replaces the runner's positional
`matching_lines`, which reported 14/2936 on swf30 at baseline while every
`<type>` attribute and `<extendsClass>` already matched.

### Regenerating

```bash
python3 tools/descriptor/gen_display_descriptors.py \
    --actual <a BASELINE all_classes/display/swf30 --save-actual capture>
```

`--actual` must be a **baseline** capture (generated block emptied, or predating
this arc): it is used only to derive the per-described-class exception tables,
which already correct what it records, so feeding a corrected output back would
erase them. A class the capture predates falls back to its superclass's entry —
exact for the classes this patch adds, which inherit their whole instance
surface. The generator also prints the checklist for the hand-written half (the
32 class gates and the per-class `implements` list).

---

## 4. The corrected API-version rule (wave-1 §2.4) — confirmed in the build

Implemented once, in `as_model.api_min_swf`, and restated in the `min_swf`
comment in `avm2_globals.c` (which shipped the wrong rule since s15):

```
ord = N - 660
ord >= 12 : even -> min_swf = 12 + (ord - 12) / 2 ; odd -> AIR-only, min_swf = 255
ord <  12 : {0: always, 2: 10, 5: 10, 7: 10, 10: 11} ; all others AIR-only, 255
```

`255` means hidden at every version (a Flash Player runtime maps every `AIR_*`
ApiVersion to `VM_INTERNAL`), **not** rounded up. This is what makes
`Stage.nativeWindow`, `Stage.orientation` and all 18 of `NativeMenu`'s members
absent at swf30, and what makes `NativeMenu` itself an empty `EventDispatcher`
subclass. The s15 formula would have put ~30 of the 51 per-member gates and
~25 of the 32 class gates on the wrong version; with it, no lower row flips.

---

## 5. Mechanisms added (all describe-only)

Wave-1 named F/G/H/I; the implementation merges G and H into one table and
generalises F, so there are three new pieces plus one lookup change:

1. **`DtDescRedecl`** (`{name, kind, is_static, declared_by}`), a
   per-**described**-class list applied as a post-pass
   (`dt_apply_redeclares`). `declared_by != NULL` re-points `declaredBy`;
   `declared_by == NULL` hides the member on that class. One table covers both
   directions of the Stage re-point (Flash overrides `addChild` where we
   inherit it; Flash overrides only the *setter* half of `alpha` so `declaredBy`
   stays `DisplayObject` where we register both halves) and the
   `soundTransform` hide. **60 entries generated: 54 re-points + 7 hides**
   (wave-1 predicted 48 + 4; the extra 6 + 3 are AVLoader, which wave-1 counted
   as a new class rather than as re-point rows, and the two misnamed
   `StageQuality` constants).
   *This is deliberately NOT the s15 XMLDocument shape.* Wave-1 §4.6 is
   confirmed by inspection: `defining_class` is read by `avm2_function_new`
   scope binding, by `class_derive_depth` override arbitration
   (`avm2_class.c:407`) and by callstack frame naming, so mutating it for
   Stage's 30 accessors would have renamed every `flash.display::Stage/set x()`
   frame that `stage_properties2` grades. `dt_apply_redeclares` touches only the
   `DtDesc` report.
2. **`DtDescClass.chain_lookup`** + `dt_desc_lookup()`: a member lookup that
   starts at the class our vtable says declares the member and, if that row does
   not name it, walks *up* the superclass chain, accepting only ancestor rows
   that opt in. Off for every hand-written row, so their behaviour is bit-identical;
   on for all 65 generated rows. Needed because our native registration and
   playerglobal disagree about which class carries an override — the descriptor
   DATA is the same either way, and `declaredBy` is corrected separately.
3. **`access` on the non-synthetic path** (wave-1's I): `dt_desc_apply` now
   applies the row's `access` when it has one. That is what reports
   `DisplayObject.blendShader` and `Shader.byteCode` as `writeonly` — Flash's
   playerglobal declares them setter-only while we register both halves.
   Zero effect on the pre-s16 rows: the only pre-existing rows carrying an
   `access` string are the two `flash.accessibility` interface accessors, and
   both are `synthetic=1` (never reached from the vtable path).
4. **"Shadow" rows** (not in the wave-1 plan, ~1 row in practice): where our
   vtable declares a member on a class playerglobal does not, the type lookup
   finds nothing and the member keeps its `*` fallback. `soundTransform` is the
   standing case (we register it once on `InteractiveObject`; playerglobal
   declares it twice, on `Sprite` and on `SimpleButton`). The generator parks a
   non-synthetic row on OUR declaring class so the data resolves, while the
   re-point/hide table still fixes ownership per described class.

### Descriptor data actually emitted

497 member rows · 82 distinct parameter lists · 18 constructors · 115 constants
· 54 re-points · 7 hides · 1 shadow row, over 65 `DtDescClass` rows —
**1,114 generated lines**. (Wave-1 priced "360 rows / 296 params"; that counted
only rows that *needed work*. Emitting every declared member is what lets the
same row serve both the vtable-fill path and the synthetic path.)

---

## 6. Class layer

**14 classes created**, exactly the wave-1 list: `AVLoader`(20, extends Loader),
`ActionScriptVersion`, `BitmapEncodingColorSpace`(16), `ColorCorrection`(10),
`ColorCorrectionSupport`(10), `GraphicsShaderFill`(10),
`JPEGXREncoderOptions`(16), `NativeMenu`(10, empty EventDispatcher subclass),
`SWFVersion`, and the five marker interfaces `IBitmapDrawable`(always),
`IDrawCommand`/`IGraphicsFill`/`IGraphicsPath`/`IGraphicsStroke`(10).

**32 class API gates** (26 at SWF 10, 1 at 13, 4 at 16, 1 at 20), spread over
four files because that is where the classes are registered.

**20 `<implementsInterface>` lines** now come out right:
`DisplayObject`/`BitmapData` → `IBitmapDrawable`; the six drawGraphicsData
carriers → `IGraphicsFill`/`IGraphicsStroke`/`IGraphicsPath` alongside the
existing `IGraphicsData`.

**`StageQuality` constant fix** (wave-1 §2.3-4, a real correctness bug, not a
test accommodation): we shipped `EIGHT_X_LINEAR`/`SIXTEEN_X_LINEAR`, which
Adobe has at no version. Renamed to playerglobal's
`HIGH_8X8`/`HIGH_8X8_LINEAR`/`HIGH_16X16`/`HIGH_16X16_LINEAR` (the two missing
values added). Wave-1's claim that no test names either identifier is confirmed
by grep; `displayobject_transform` uses only the string *values*.

### Class-gate blast radius: measured, and it is zero

`gaterisk.py` (scratch) cross-joined every gated class name against every test
whose `.as` sources mention it and whose `test.swf` header version is BELOW the
gate, across the **entire corpus** (all suites):

```
0 at-risk (test, class) pairs
```

No test anywhere references an API-gated `flash.display` class from an
under-versioned SWF, so the gates cannot break a row by name resolution. The
per-**member** gates are describe-only by construction (`dt_desc_member_hidden`
is called only from `dt_collect_vtable`) and cannot affect lookup at all.

---

## 7. Canary results

**70 canary rows graded** (`--mode=graphics`, `-P 2`, baseline = merged CI run
`31748059158` at `3db858cbc`, read out of
`ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.md`).

### **ZERO REGRESSIONS. Every canary landed on exactly its baseline status.**

| tier | rows | baseline | after |
|---|---|---|---|
| 1 — describeType consumers | `describe_type_basic`, `describe_type_json`, `describe_type_metadata`, `describe_type_native`, `number_autoconv`, `function_proto_created`, `static_length`, `displayobject_name_from_timeline`, `font_enumeratefonts` | 9 × pass | **9 × pass** |
| 1 — the interface-describeType pin | `from_avmplus/regress/bug_539328` | ruffle_matched | **ruffle_matched** (no drift — checked explicitly per `ruffle-matched-hides-regression`) |
| 2 — `all_classes` rows the table already served | `errors/{swf9,swf10,swf30}`, `security/{swf11,swf12,swf13,swf30}`, `display3D/{swf12,swf13,swf30}`, `xml/{swf9,swf30}`, `accessibility/{swf9,swf10,swf30}` | 15 × pass | **15 × pass** |
| 3 — `avm2_display.c` blast radius | `stage_properties`, `stage_properties2`, `stage_overriden_setters`, `stage_displayobject_properties`, `stage_access`, `stage_mousechildren`, `stage_mouseenabled`, `stage_invalidate`, `stage_loaderinfo_properties`, `stage_stage3Ds_vector`, `stage_domain_getQualifiedDefinitionNames`, `displayobject_metaData`, `displayobject_subclass`, `simplebutton_childprops`, `sound_rootless`, `soundchannel_soundtransform_exists`, `graphics_draw_triangles`, `graphics_path`, `bitmapdata_draw`, `bitmapdata_draw_stage`, `bitmapdata_drawwithquality`, `loader_events`, `abstract_classes` | 23 × pass | **23 × pass** |
| 3 — already failing at baseline | `stage_display_state`, `displayobject_transform`, `simplebutton_soundtransform`, `loader_load` | 4 × output_mismatch | **4 × output_mismatch** (unchanged) |
| 3 — `graphics_draw_path` | | ruffle_matched | **ruffle_matched** |
| 4 — API-gate axis | `stage3d_bitmap`, `stage3d_x_y`, `stage3d_errors`, `stage3d_errors_swf_29`, `context3d_creation`, `json_version_gated`, `cross_api_version_call_older`, `cross_api_version_call_newer`, `air_hidden_lookup` | 9 × pass | **9 × pass** |
| 4 — SWF-9 gate risk (added by me) | `loader_jpegxr`, `loader_jpegxr_alpha`, `loader_bitmap_transparency`, `avm1movie_addcallback_call` | 4 × pass | **4 × pass** |
| 5 — must NOT drift | `all_classes/events/{swf9,swf10,swf11,swf12,swf30}` | 5 × output_mismatch | **5 × output_mismatch** (no drift) |

The Tier-3 pins that would have caught the wrong mechanism choice are all green:
`stage_properties2` and `stage_overriden_setters` grade Stage's 2071 throws by
**callstack frame**, which is exactly what the s15 `defining_class` mutation
would have renamed for all 30 re-pointed accessors.
`displayobject_transform` (which reads the StageQuality string *values*) is
unchanged at its baseline status, confirming the constant rename is
value-transparent.

**Load caveat, resolved.** The first pass ran while the box was at load ~25
(≈10 concurrent fan-out agents on 8 cores) and produced 3 `compile_fail`s plus
several killed-without-summary rows. All were the FALSE failures
`BRIEFS_COMMON` §3 warns about: two causes, (a) copied test dirs need
`--recompile` on first use, and (b) the default 300 s per-file gcc cap is hit
under that load (`Error: compilation timed out` at `c=300.70s`). Every one of
them was re-run sequentially on an idle box with `--recompile` and
`SWFRECOMP_COMPILE_TIMEOUT=2400`, and every one landed on its baseline status
(`stage_loaderinfo_properties` → pass, `soundchannel_soundtransform_exists` →
pass, `simplebutton_soundtransform` → output_mismatch as at baseline). No
result in the table above rests on a run that hit a timeout.

**Canary blind spot (BRIEFS_COMMON s15 lesson).** The standing *render* canary
does not exercise any of this: the patch is trace-only, touches no renderer
path, and has zero pixel-axis effect. Tier 3 above is the covering grade. The
one file I touched that a render sibling might also touch is `avm2_bitmap.c`,
and only at `avm2_register_bitmap`'s two registration statements.

**All six headline rows were re-verified on the FINAL tree** (after a
late whitespace-only cleanup that removed a then-unused macro), sequentially on
an idle box: 6/6 PASS.

---

## 8. `all_classes/events` rider — measured, and NO

The coordinator asked whether the generator could cover `flash.events` for
free. It nearly can, and the answer is still no:

* Running the same grader over the events suite gives **113 element mismatches
  across 5 versions** (vs 0 for display) — ~97 % correct, but not free.
* Two of the three residual causes are real **Ruffle-vs-playerglobal
  divergences in the `.as` stubs**, not gaps in the model:
  `KeyboardEvent`(11 vs 9 params), `MouseEvent`, `TouchEvent`,
  `TransformGestureEvent`, `PressAndTapGestureEvent` and `FocusEvent`
  constructors carry AIR-era extra parameters that Flash's playerglobal does
  not report. Fixing those means hand-overriding the oracle — the opposite of
  this arc's method, and it needs its own adjudication.
* The third is a **new mechanism**: interface members need `uri="flash.events:
  IEventDispatcher"`, which display's six empty marker interfaces never exercise.
* The five rows are ignore-listed upstream `known_failure` and are worth
  **zero flips** (confirmed again here: all five are `output_mismatch` at
  baseline AND after this patch — they must not drift, and they did not).
* The owning file would be `avm2_events.c`, outside this brief's ownership.

**Recommendation:** leave `all_classes/events` on the board as a separate,
cheap-but-not-free arc (~1 mechanism + ~6 adjudications), and reuse
`tools/descriptor/` verbatim — `check_model.py <suite-dir> flash.events`
already grades it. Its value is 0 trace flips, so it is only worth doing as a
correctness/foundation item.

---

## 9. Wave-1 claims — held, corrected, refuted

| wave-1 claim | outcome |
|---|---|
| GO, +6, one agent, ~900-1,100 lines | **HELD.** +6/+6. Patch is ~1,465 inserted lines, of which 1,097 are generated. |
| Model is machine-derivable from the `.as` files; expected files are only the oracle | **HELD, and stronger than priced** — 0/2,900 element mismatches on the first grader run. |
| The s15 API-version formula is wrong below ordinal 12; AIR is hidden, not rounded up | **HELD.** The empirical mapping in §2.4 is exactly right; all five lower rows depend on it. |
| Do NOT reuse the XMLDocument `defining_class` mutation | **HELD** (by inspection; `dt_apply_redeclares` is report-only). |
| The declaredBy re-point is 3.4 % of the diff, not the bulk | **HELD.** 54 re-point entries against 497 member rows. |
| Exactly two members exist in our runtime that Flash never has | **HELD** (`StageQuality.{EIGHT,SIXTEEN}_X_LINEAR`). |
| 29 distinct re-point rows / 4 hides | **Slightly under-counted**: 54 entries / 7 hides once AVLoader and the StageQuality pair are included. Same mechanism, no extra cost. |
| "Four mechanisms beyond the re-point" (F/G/H/I) | **3 + 1.** G and H are one table; F generalises into it; I is 1 line. One mechanism wave-1 did NOT foresee: the shadow row (§5.4), ~10 LOC in the generator, 0 LOC in C. |
| swf9 is 65 % of the data; the marginal five rows are cheap | **HELD** — swf10-13 needed no work at all beyond the gate columns. |
| No rider (`all_classes/events` worth 0) | **HELD** — see §8. |

---

## 10. Reproduction

```bash
cd <worktree>
export DAWN_INSTALL=$HOME/CC/dawn-install
# free acceptance test, no build:
python3 tools/descriptor/check_model.py                  # -> TOTAL mismatches: 0
# a row:
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/avm2 \
  --test=all_classes/display/swf30 --mode=graphics
# structural residual diff, if one ever reappears:
python3 tools/descriptor/check_model.py --actual OURS.txt \
  ruffle-tests/tests/swfs/avm2/all_classes/display/swf30/output.txt
```

Scratch analysis scripts (not committed):
`.../scratchpad/w2acd/{gaterisk.py,baseline.py,run.sh,cmp.py}`.

---

## 11. Board update for `polish-sweep-arc.md` §16.4

> **all_classes/display: DONE, +6 (s16 w2).** All six rows pass. Derived —
> not transcribed — from Ruffle's playerglobal `.as` stubs by
> `tools/descriptor/` (4 scripts, checked in); `check_model.py` grades the
> model against the six expected files with **0 element mismatches** and needs
> no build, so the arc landed in one build cycle. 497 member rows / 82
> parameter lists / 18 ctors / 115 constants / 54 declaredBy re-points / 7
> hides, spliced into `avm2_globals.c` between markers (NOT a new header —
> `verify_output.py` copies an explicit source list, the s15 trap, and the
> first build hit it). 14 new classes, 32 class API gates, 6 marker interfaces,
> and the `StageQuality.{EIGHT,SIXTEEN}_X_LINEAR` → `HIGH_8X8[_LINEAR]` /
> `HIGH_16X16[_LINEAR]` correctness fix. The **corrected** API-version rule
> (`as_model.api_min_swf`; AIR ordinals hidden at every version, non-uniform
> stride below ordinal 12) is now the single implementation and the
> `avm2_globals.c` comment was corrected with it. New describe-only mechanisms:
> `DtDescRedecl` (per-described-class declaredBy re-point OR hide, applied as a
> post-pass — never the s15 `defining_class` mutation), `DtDescClass.chain_lookup`
> (opt-in superclass fall-through for member lookup), `access` on the
> non-synthetic path, and generator-side "shadow" rows. Class gates are proven
> harmless corpus-wide: 0 tests reference a gated `flash.display` class from an
> under-versioned SWF. `all_classes/events` remains NOT a rider — 113 element
> mismatches, 6 of them real Ruffle-vs-playerglobal `.as` divergences, plus an
> interface-`uri` mechanism, for 0 flips.
