# Session 15 · wave 1 · T10 `playerglobal-descriptor` — arc scoping

**Agent:** `w1-t10-descriptor` (read-only, main tree). **HEAD:** `42a324cef`.
**Baseline:** CI run `31647430265` at `bf585e448` (graphics/full/images=true),
trace 4269/4443 effective.
**Predecessors (diagnosis of record):**
`session14-fanout-reports/wave1-t7-describetype.md`,
`session14-fanout-reports/w2-describetype-report.md`,
`polish-sweep-arc.md` §15.3.

Evidence: merged `avm2/_results/results_graphics.json` at the baseline SHA;
**six local `verify_output.py --save-actual` runs at HEAD**
(`all_classes/{xml/swf9, accessibility/swf9, display3D/swf13, display3D/swf30,
display/swf9}` + `accessibilityimplementation`), graded by set-diff of parsed
member elements, never by the runner's positional `matching_lines`
(`results-diff-line-metrics-mislead`); the `dt_*` region of
`SWFModernRuntime/src/avm2/avm2_globals.c`; `avm2_xml.c`, `avm2_text.c`;
and the oracle (`~/CC/ruffle` `globals/flash/**/*.as`, `api_version.rs`,
`tests/tests/swfs/avm2/all_classes/*/Test.as`).

---

## 0. VERDICT

### **GO for a wave-2 agent this session. Priced at +8, not 0.**

The brief's framing ("13 rows, ~16.5k lines, needs typed member registration")
is **true in the count and false in the economics**. The arc is not one lump:

| unit | rows | expected lines | share of the 16.5k | verdict |
|---|---|---|---|---|
| **non-`display` T10** | **7** | **1,219** | **7.4 %** | **GO this session, +7 (+1 rider)** |
| `all_classes/display` | 6 | 15,321 | 92.6 % | stays an arc, all-or-nothing +6 |

**7 of the 13 rows are 7.4 % of the lines.** They are *not* all-or-nothing
against each other — each of the four families flips independently — and one
of them (`display3D/swf30`, the single biggest non-`display` row at 412 lines)
needs **zero new mechanism**: it is pure data entry into the `DtDescClass`
table the s14 pilot already shipped.

**Priced flips for a wave-2 agent, in commit order (early stop still banks):**

| # | slice | flips | new mechanism | confidence |
|---|---|---|---|---|
| 1 | `display3D/swf30` descriptor data | **+1** | none | **HIGH** |
| 2 | per-member / per-const API gate | **+1** (`display3D/swf13`) | ~20 LOC | **HIGH** |
| 3 | `flash.accessibility` real registration + descriptors | **+2** (`accessibility/swf9`, **`accessibilityimplementation`**) | synthetic-member pass (~45 LOC) | MED-HIGH |
| 4 | 2 gated `flash.accessibility` interfaces | **+2** (`accessibility/swf10,swf30`) | none (s14's `avm2_builtin_class_api`) | MED |
| 5 | const-type override + `flash.xml` descriptors | **+2** (`xml/swf9,swf30`) | ~15 LOC | MED |
| — | `all_classes/display` | +6 | — | **NO-GO this session** |

**Total +8**, of which **+1 (`avm2/accessibilityimplementation`) is a rider
outside the 13-row T10 set** that nobody has priced before (§3.3).

### NO-GO, and why it is not a marginal-slice-yields-0 situation

`all_classes/display` is genuinely all-or-nothing (§4): its six rows share one
class surface, so any partial table yields **+0** until the whole thing lands.
But the six rows are *separable from the other seven* — they share only the
mechanisms, and every mechanism `display` needs is built by slices 1–5 above.
So deferring `display` costs this session nothing and makes next session's
`display` attempt pure data entry against a proven mechanism set.

---

## 1. PREMISE ATTACKS

### 1.1 "13 all_classes rows" — CONFIRMED exactly ★

Measured at the baseline SHA. s14's +9 all landed and held; the T7 family is
now 13 graded-and-failing rows plus the 5 unpriced `events` rows:

```
all_classes/accessibility/swf9      output_mismatch  exp=73    act=27
all_classes/accessibility/swf10     output_mismatch  exp=88    act=27
all_classes/accessibility/swf30     output_mismatch  exp=88    act=27
all_classes/xml/swf9                output_mismatch  exp=116   act=61
all_classes/xml/swf30               output_mismatch  exp=116   act=61
all_classes/display3D/swf13         output_mismatch  exp=326   act=211
all_classes/display3D/swf30         output_mismatch  exp=412   act=267
all_classes/display/swf9            output_mismatch  exp=1959  act=1497
all_classes/display/swf10           output_mismatch  exp=2569  act=1497
all_classes/display/swf11           output_mismatch  exp=2593  act=1497
all_classes/display/swf12           output_mismatch  exp=2593  act=1497
all_classes/display/swf13           output_mismatch  exp=2671  act=1497
all_classes/display/swf30           output_mismatch  exp=2936  act=1497
                                                     ---------
                                            13 rows, 16,540 expected lines
```
`describe_type_{basic,json,metadata,native}`, `all_classes/errors/*`,
`all_classes/security/*`, `display3D/swf12` are all **pass** — s14 held.
`all_classes/events/*` (5) remain in `avm2/ignored_tests.txt:54-58` under
upstream `known_failure` and are worth zero (unchanged).

Row count and line count are both exact. **No refutation.**

### 1.2 "needs typed member registration" — REFUTED as a blocking premise ★★

The 13 rows need **five** distinct capabilities, and "typed member
registration" (in the sense of *adding members to the runtime*) is needed by
only two of the four non-`display` families:

| capability | status at HEAD | who needs it |
|---|---|---|
| A. type + parameter descriptors on existing members | **ALREADY BUILT** (s14 `DtDescClass`/`dt_desc_apply`, `avm2_globals.c:2441-2632`) | every row |
| B. class-level API-version gate | **ALREADY BUILT** (s14 `avm2_builtin_class_api`, `:396`) | accessibility swf10/30, display |
| C. per-**member** / per-**const** API gate | missing, ~20 LOC | display3D/swf13, display |
| D. per-const **type** override | missing, ~15 LOC | xml, display |
| E. members that do not exist in our runtime | missing, ~45 LOC (or real registration) | accessibility, xml, display |

**The decisive measurement.** `all_classes/display3D/swf30` — 412 lines, the
largest non-`display` row — has, at HEAD:

```
ours-extra members: 0
missing  members:   0
our type="*" lines: 69   (18 of them are the legitimate Class `prototype` accessors)
expected member elements: 139   expected <parameter> elements: 110
```

Every member Flash reports, we already register; every member we register,
Flash reports. **The entire 145-line gap is 51 members whose `returnType`/`type`
reads `*` and whose `<parameter>` children are absent.** That is capability A,
which shipped in s14. This row is **data, not registration** — a direct
refutation of the brief's mechanism claim for the biggest tractable row.

### 1.3 "~16.5k lines" — TRUE but a 12× overstatement of the tractable work ★★

92.6 % of the 16,540 lines are the six `display` rows. The seven rows a wave-2
agent can flip this session total **1,219 lines** — and even that overstates
it, because the four families are near-duplicates of each other:

* `xml/swf9` and `xml/swf30` expected files are **byte-identical** (`diff` → no output).
* `accessibility/swf10` and `accessibility/swf30` are **byte-identical**.
* `accessibility/swf10` = `accessibility/swf9` + exactly two interface blocks.
* `display3D/swf30` = `display3D/swf13` + the five API-gated constant bags,
  which we already emit correctly (they were proven byte-exact by
  `display3D/swf12` passing in s14).

The *distinct* content behind the 7 rows is **one 116-line file, one 88-line
file and one 412-line file** — 616 lines of oracle, yielding 7 flips.

### 1.4 The all_classes fixture SORTS its children — member ordering is free ★

`~/CC/ruffle/tests/tests/swfs/avm2/all_classes/*/Test.as` `normalizeXML()`
does `childStrs.sort()` before printing. Confirmed in the xml, accessibility,
display3D and display fixtures (same helper, copy-pasted). So a wave-2 agent
may append synthetic/descriptor members **in any order** — only *attribute*
order inside an element matters (attributes are printed in `data.attributes()`
order), and our existing attribute order is already proven by the s14 flips.

This kills the ordering risk the s13/s14 briefs carried for `dt_collect_*`.

### 1.5 There is a `+1` rider nobody has priced: `avm2/accessibilityimplementation` ★★

Not in the 13-row T10 set, not on the board, `output_mismatch` at baseline
(exp 18 lines). Actual at HEAD:

```
undefined
undefined
TypeError: Error #1006: accDoDefaultAction is not a function.
	at Test()
```

`flash.accessibility::AccessibilityImplementation` is an **empty stub class**
(`avm2_text.c:9142-9146` — `avm2_builtin_class(...)` and nothing else). Giving
it the 12 methods + 2 vars that `all_classes/accessibility/swf9` also demands
flips both rows at once. This is the only place in the arc where **real**
registration (rather than describe-only synthesis) buys an extra flip, and it
is the reason slice 3 should register for real (§3.3).

### 1.6 Disposition check

None of the 13 rows, and not `accessibilityimplementation`, appears in
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`,
`ruffle-tests/ignored_tests.txt` or `avm2/ignored_tests.txt` (except the 5
`events` rows, which stay excluded). Nothing here is dispositioned away.

---

## 2. What "typed member registration" means concretely after the s14 pilot

s14 shipped `DtDescClass` (`avm2_globals.c:2441-2576`), a `static const` table
keyed by `(ns, name)` of the **defining** class, with per-member
`(name, kind, type, param_count, params)` rows and a `ctor_params` list. It is
consumed at exactly four points, all of which today fall through to `"*"`:

* `dt_desc_apply` (`:2602`) — called from the three `dt_collect_vtable`
  branches (`:2652` method, `:2685` accessor, `:2709`/`:2720` getset halves);
* `dt_collect_ctor` (`:2766`) — the native-constructor path;
* `dt_describe` (`:2878`) — the describe-only `isDynamic` bit.

Twelve rows in that table reproduce `describe_type_native`,
`all_classes/errors/*` and `all_classes/security/*` byte-for-byte. **The pilot
proved the shape is right and that the four consumption points do not change
as the table grows.** What it did *not* build is anything that (a) adds a
member the vtable lacks, (b) hides a member below an API version, or (c)
retypes a static constant. Those are the three ~15-45 LOC gaps below.

### 2.1 Gap E — synthetic (describe-only) members, ~45 LOC

Add `uint8_t synthetic` and (optional) `const char* uri` / `uint8_t is_static`
to `DtDescMember`, plus a pass that, after `dt_collect_vtable`, walks
`cls` → `super_class` and appends each descriptor class's `synthetic` rows
that were **not** already collected from the vtable (dedupe by name+kind).
Two insertion points, both already isolated in `dt_describe`
(`avm2_globals.c:2907-2924`):

```c
if (class_side) { ... dt_collect_static_consts(ctx, d, cls); }   // ← static synthetics
else            { dt_collect_vtable(ctx, d, &cls->ivtable, ...); } // ← instance synthetics
```

`<variable>` elements carry **no `declaredBy`** in the expected output (verified
across xml + accessibility), so the super-chain walk only needs `declaredBy`
for synthetic *methods* — set it to the descriptor class's qname.

### 2.2 Gap C — per-member / per-const API gate, ~20 LOC

Add `uint8_t min_swf` to `DtDescMember` and to the new const-descriptor row;
skip the member in `dt_collect_vtable` / `dt_collect_static_consts` when
`ctx->swf_version < min_swf`. **Describe-side only** — do not try to hide the
property from lookup. Flash really does hide it, but no graded test calls a
gated member on an under-versioned SWF, and hiding it for real would need a
per-entry availability check on the hot property path.

The `[API("N")]` → SWF mapping (oracle: `api_version.rs`, ordinal = `N - 660`):

```
SWF_version = 12 + (N - 672) / 2      for even ordinals ≥ 12
```
Verified against all six annotations s14 recorded (672→12, 674→13, 682→17,
686→19, 692→22) and the ones this arc needs (676→14, 690→21, 700→26, 706→29).
Odd ordinals are AIR-only and round **up** to the next SWF version under a
Flash-Player runtime (`api_version.rs` `map_to_available`).

### 2.3 Gap D — per-const type override, ~15 LOC

`dt_collect_static_consts` (`:2733-2764`) derives the reported type from the
stored `Avm2Value.kind`, and **our value model has no UINT kind** —
`avm2_uint_value()` is documented "Integer if it fits, else Number"
(`include/avm2/avm2_value.h:81`). So `XMLNodeType.ELEMENT_NODE`, stored via
`avm2_uint_value(1)` (`avm2_xml.c:3634`), can only ever report `int`, while
Flash reports `uint`.

This is **not** fixable by changing the value: it is per-class declared-trait
information. Proof that a global rule would be wrong —
`flash.display3D::Context3DClearMask`'s constants are `type="int"` in the
expected output (that row passes today), while `flash.xml::XMLNodeType`'s are
`type="uint"`. Add a `{ name, type, min_swf }` const array to `DtDescClass` and
consult it in `dt_collect_static_consts`.

---

## 3. The slice plan (hand this to the wave-2 worktree agent)

Order matters: slices 1 and 2 need no new mechanism-plus-data coupling and are
near-certain; 3–5 each add one small mechanism. Every slice is independently
mergeable and leaves the corpus no worse.

### 3.1 Slice 1 — `display3D/swf30` (+1). Pure data. **HIGH.**

**Files:** `avm2_globals.c` (`dt_desc_classes` table only).
**Data:** 51 member rows + 110 parameter entries across five descriptor
classes, transcribed from `~/CC/ruffle/core/src/avm2/globals/flash/`:

| class | members | source |
|---|---|---|
| `flash.display3D::Context3D` | 37 | `display3D/Context3D.as` |
| `flash.events::EventDispatcher` | 6 | `events/EventDispatcher.as` |
| `flash.display3D::IndexBuffer3D` | 3 | `display3D/IndexBuffer3D.as` |
| `flash.display3D::VertexBuffer3D` | 3 | `display3D/VertexBuffer3D.as` |
| `flash.display3D::Program3D` | 2 | `display3D/Program3D.as` |

**Blast radius of the `EventDispatcher` row: zero on any passing test.** The
complete set of graded `describeType` consumers is `describe_type_basic`,
`describe_type_json`, `describe_type_native`, `describe_type_metadata`,
`function_proto_created`, `number_autoconv`, `from_avmplus/regress/bug_539328`
and the `all_classes` rows (verified by
`grep -rn describeType --include=*.as ruffle-tests/tests/swfs`;
`displayobject_name_from_timeline` and `font_enumeratefonts` *import*
`describeType` but never call it). `describe_type_json`'s subject
`com.ruffle::RuffleTest` extends `RuffleBase`, **not** `EventDispatcher`.

**Recommended method, not hand-transcription:** write a throwaway extractor
(scratchpad, not committed) over the Ruffle `.as` files — the declarations are
one-line `public function name(a:int, b:String = "x"):Type` forms with
`[API("N")]` on the preceding line — and emit the C table text. Same effort,
far lower transcription-error risk, and it is the seed of the `display`
generator.

### 3.2 Slice 2 — `display3D/swf13` (+1). Adds gap C. **HIGH.**

Measured delta at HEAD after slice 1 would be exactly **14 members we emit
that Flash hides at SWF 13, and zero missing**:

```
accessor  backBufferHeight / backBufferWidth / maxBackBufferHeight /
          maxBackBufferWidth / profile / supportsVideoTexture   (Context3D)
method    createRectangleTexture / createVideoTexture /
          setProgramConstantsFromByteArray / setSamplerStateAt  (Context3D)
constant  BGRA_PACKED / BGR_PACKED / COMPRESSED_ALPHA /
          RGBA_HALF_FLOAT                     (Context3DTextureFormat)
```

All fourteen carry an `[API("N")]` annotation in `Context3D.as` /
`Context3DTextureFormat.as` (`grep -n 'API(' ` → 12 hits in `Context3D.as`).
Add `min_swf` marks; the four constants also exercise the const-descriptor row
introduced in slice 5 — **either do slice 5's const struct first, or give the
const array a `min_swf`-only form here and add `type` in slice 5.**

**Canaries** (all pass at baseline, all must stay green):
`stage3d_bitmap` (SWF 13 — the lowest-version Stage3D test, the sharpest gate
canary), `stage3d_x_y` (SWF 15), `stage3d_errors`, `stage3d_errors_swf_29`,
`context3d_creation`, `stage3d_triangle`, `agal_compiler`, `abstract_classes`,
`all_classes/display3D/swf12`, `all_classes/security/swf11`.

### 3.3 Slice 3 — `accessibility/swf9` + `accessibilityimplementation` (+2). Adds gap E. **MED-HIGH.**

`all_classes/accessibility/swf9`'s complete delta at HEAD (measured):

```
1 accessor type   Accessibility.active                     * → Boolean
2 static methods  Accessibility.sendEvent(DisplayObject, uint, uint, Boolean=):void
                  Accessibility.updateProperties():void
12 methods + 2 vars   AccessibilityImplementation           (all absent today)
6 vars                AccessibilityProperties               (all absent today)
```

**Register `AccessibilityImplementation` FOR REAL, not synthetically** — that
is what buys the `accessibilityimplementation` rider (§1.5). Oracle is
`~/CC/ruffle/core/src/avm2/globals/flash/accessibility/AccessibilityImplementation.as`,
which is a complete, tiny reference implementation: `errno:uint = 0`,
`stub:Boolean = false`, ten methods returning `null`/`0`/`false`, and
`get_accRole`/`get_accState` calling `Error.throwError(Error, 2143/2144)`.
Our runtime already carries both messages (`avm2_error.c:996-997`).
Registration site: `avm2_text.c:9139-9149` (the existing empty-stub block).
Types still come from the descriptor table (natives record no signature), so
slice 3 needs *both* real registration and ~20 table rows.

`AccessibilityProperties`' 6 vars and `Accessibility`'s 2 static methods have
no rider — do those **synthetically** (gap E) unless the real registration is
free.

**Risk on the rider only:** the expected output grades a `getStackTrace()`
containing `at Error$/throwError()` and
`at flash.accessibility::AccessibilityImplementation/get_accRole()`. If our
native-frame naming does not reproduce those two lines, the rider stays failed
— but `accessibility/swf9` still flips, because describeType does not see the
stack. Do not let the rider block the slice.

**Canaries:** `avm2/accessibility` (pass), `error_stack_trace`,
`error_stack_trace_edge_cases`, `error_throwerror`, `error_tostring`.

### 3.4 Slice 4 — `accessibility/swf10` + `swf30` (+2). No new mechanism. **MED.**

Both files are byte-identical and equal `swf9` plus exactly two interface
blocks. `swf9` already emits the two `not accessibile` lines correctly today
(the classes simply do not exist for us), so the gate must be **`min_swf = 10`
via s14's `avm2_builtin_class_api`** and must not regress `swf9`.

```
flash.accessibility::ISearchableText        [API("667")] = FP_10_1 → SWF ≥ 10
    accessor searchText           readonly String  uri="flash.accessibility:ISearchableText"
flash.accessibility::ISimpleTextSelection   [API("667")] → SWF ≥ 10
    accessor selectionActiveIndex readonly int     uri="flash.accessibility:ISimpleTextSelection"
    accessor selectionAnchorIndex readonly int     uri="flash.accessibility:ISimpleTextSelection"
```

Interface describeType already works end-to-end: `<factory>` correctly omits
`<extendsClass>` and `uri=` is emitted at `avm2_globals.c:3141/3153/3165`,
pinned by `from_avmplus/regress/bug_539328` (`ruffle_matched` — a move to plain
`pass`/`fail` on that row is a **regression signal**, per
`ruffle-matched-hides-regression`). Set `AVM2_CLASS_FLAG_INTERFACE`; the
accessors can be synthetic rows carrying an explicit `uri`.

**Canaries:** `all_classes/accessibility/swf9` (gate from below),
`all_classes/security/swf11`, `bug_539328`, `air_hidden_lookup`,
`json_version_gated`, `cross_api_version_call_{older,newer}`.

### 3.5 Slice 5 — `xml/swf9` + `xml/swf30` (+2). Adds gap D. **MED.**

Both expected files are byte-identical. Complete delta at HEAD (measured):

| what | count | mechanism |
|---|---|---|
| `XMLNode` accessor types (`attributes`→Object, `childNodes`→Array, `localName`/`namespaceURI`/`prefix`→String) | 5 | A (table) |
| `XMLNode` method types + params | 8 | A |
| `XMLDocument` method types + params (`createElement`, `createTextNode`, `parseXML`) | 3 | A |
| ctor signatures — `XMLNode(uint, String)`, `XMLDocument(String=)` | 2 | A (`ctor_params`, already supported) |
| `XMLNode` public vars (`firstChild`, `lastChild`, `nextSibling`, `nodeName`, `nodeType`, `nodeValue`, `parentNode`, `previousSibling`) | 8 | **E** |
| `XMLDocument` own vars (`docTypeDecl`, `idMap`, `ignoreWhite`, `xmlDecl`) | 4 | **E** |
| `XMLNodeType` constants `int` → `uint` | 7 | **D** |
| `toString` must report `declaredBy="flash.xml::XMLDocument"` | 1 | see below |

**Do the vars synthetically, NOT as real slots.** Our `XMLNode` stores every
one of them as a dynamic property (`xn_set`/`xn_get`, `avm2_xml.c:2960-3160`);
introducing real public slots would change `for..in` enumerability and
property-lookup order under eight currently-passing tests. Synthetic costs
nothing and is invisible outside describeType.

**`toString`:** Ruffle declares `override public function toString()` on
`XMLDocument`; we register it only on `XMLNode` (`avm2_xml.c:3615`). Preferred
fix is the real one — `avm2_builtin_add_method(ctx, doc, "toString", …)` — but
if any XML canary moves, fall back to a describe-only `declared_by` override
field on `DtDescMember` (zero runtime risk).

**Canaries (all pass at baseline):** `avm2/flash_xml`, `flash_xml_cloneNode`,
`flash_xml_namespace`, `flash_xml_removeNode`, `xml_ignore_white`,
`xml_namespace_methods`, `xmldocument`, `xmlnode`.

---

## 4. Why `all_classes/display` stays an arc (NO-GO)

Measured at HEAD on `display/swf9` (1,959 lines), deduplicated by
`(kind, name, declaredBy)`:

```
types  we expose that Flash does not at SWF 9 : 18   (Graphics*, Shader*, Stage3D,
                                                     JPEG/PNGEncoderOptions, …)
types  Flash has that we do not               :  3   (ActionScriptVersion,
                                                     IBitmapDrawable, SWFVersion)
member rows ours-extra (need per-member gate) : 129  (blendShader, rotationX/Y/Z, z,
                                                     scaleZ, softKeyboard*, drawPath, …)
member rows missing                           :  51  (incl. Stage's own re-declared
                                                     overrides of addChild/dispatchEvent/
                                                     willTrigger, StageQuality HIGH_8X8*,
                                                     SWFVersion/ActionScriptVersion consts)
```
and `display/swf30` grades **1,257 member elements with 751 parameters across
65 types**. So `display` needs, on top of the full descriptor table:

1. 18 class-level gates + 3 new classes;
2. ~129 per-member gates at six different SWF versions;
3. `Stage`'s describe-side **re-declaration** of inherited members as its own
   (`declaredBy="flash.display::Stage"` on `addChild`, `dispatchEvent`,
   `hasEventListener`, `willTrigger`, `setChildIndex`, … — avmplus's Stage
   overrides them to throw) — a `declared_by` override, a mechanism none of
   slices 1–5 strictly requires;
4. two classes' worth of members we simply do not implement.

**All six rows share one class surface, so any partial table yields +0.** That
is the honest "marginal slice yields nothing" answer the brief asked for — but
it applies *only* to `display`, not to the other seven rows.

**What makes `display` cheap next session:** slices 1–5 build every mechanism
it needs except the `declared_by` override (~10 LOC), and slice 1's extractor
becomes the generator. `display` then reduces to running the generator over
`~/CC/ruffle/core/src/avm2/globals/flash/display/*.as` + `events/*.as` +
`geom/*.as` and reconciling the 21-class membership delta — one focused
session for +6.

---

## 5. Sibling-conflict map

**All five slices belong to ONE agent.** Every one of them writes the
`dt_*` region of `avm2_globals.c` (`:2440-2790`); splitting guarantees a
textual conflict — the same conclusion s14 reached for P3 + the P4 pilot.

| file | region |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `DtDescParam`/`DtDescMember`/`DtDescClass` + table (`:2441-2576`), `dt_desc_apply` (`:2602`), `dt_collect_vtable` (`:2632`), `dt_collect_static_consts` (`:2733`), `dt_describe` (`:2850-2924`) |
| `SWFModernRuntime/src/avm2/avm2_text.c` | `:9139-9149` accessibility stub block (slices 3, 4) |
| `SWFModernRuntime/src/avm2/avm2_xml.c` | `:3582-3645` `avm2_register_xml_legacy` (slice 5, `toString` only) |

Checked against `scratchpad/s15-agent-roster.md`: **no other session-15 agent
touches any AVM2 file** (fuzz16 / watch-order / action-order are AVM1; the rest
are graphics). Clean.

No recompiler change, no `abc_emit.cpp`, **no generated-ABI move** — unlike
s14's P3, nothing here invalidates `RecompiledABC`, so `--recompile` is
ordinary hygiene rather than mandatory, and CI will not pay the full-corpus
regeneration cost again.

---

## 6. CI dispatch

`mode=graphics`, `categories=full` (`all_classes` and `from_avmplus/regress/
bug_539328` both live outside the classic five), `images=false` — no render
code is touched, zero pixel-axis effect.

---

## 7. Board correction for `polish-sweep-arc.md` §15.3

> T10-playerglobal-descriptor arc (13 all_classes rows, ~16.5k lines, needs
> typed member registration)

should become

> **T10-playerglobal-descriptor: 13 rows / 16,540 lines, but 7 of the rows are
> 7.4 % of the lines.** `display3D/swf30` (412 lines) needs **zero new
> mechanism** — measured ours-extra = missing = 0, the whole gap is `type="*"`
> and absent `<parameter>` children, i.e. pure `DtDescClass` data. A single
> wave-2 agent is priced at **+8**: `display3D/{swf30,swf13}`,
> `accessibility/{swf9,swf10,swf30}`, `xml/{swf9,swf30}` and the previously
> unpriced rider **`avm2/accessibilityimplementation`** (an empty stub class at
> `avm2_text.c:9142`). Three ~15-45 LOC mechanisms are needed —
> describe-only synthetic members, per-member/per-const API gate
> (`SWF = 12 + (N-672)/2`), per-const type override (our value model has **no
> UINT kind**, so `XMLNodeType`'s `uint` constants can only come from a table).
> `all_classes/display` alone stays the arc: 6 rows, 15,321 lines, 65 classes,
> 1,257 members, **all-or-nothing** (+0 until complete, then +6), and it
> additionally needs 18 class gates, 3 new classes, ~129 per-member gates and a
> `declaredBy` override for `Stage`'s re-declared inherits. Every mechanism it
> needs except that last one is built by the +8 slice — book it as pure data
> entry via a generator over `~/CC/ruffle/.../globals/flash/**/*.as`.

---

## 8. Reproduction notes

```bash
# per-row actual (main tree; all_classes has no sibling owner)
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
  --test=all_classes/display3D/swf30 --save-actual=/tmp/.../d3d30.actual
```
Grade with a **set-diff of parsed member elements**
(`(kind, name, declaredBy)`), never the runner's `matching_lines`: on
`display3D/swf13` the runner reports `expected=326 matching=6`, which reads as
"structurally broken" when the row is in fact structurally perfect and only
untyped. The five failing families' `matching_lines` (5–19 out of 73–2936) are
positional-compare artifacts across the board.
