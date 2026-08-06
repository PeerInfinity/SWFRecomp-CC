# Session 13 · wave 1 · T7 `describeType` — arc scoping doc

**Agent:** wave-1 diagnosis (read-only). **HEAD:** `10931d62e` (master).
**Baseline:** CI run 31090651530 (`mode=graphics categories=full images=true`,
commit `1f8396f57`) — trace 4229 effective passes, pixels 286/567.
**Charter:** the trace board (`polish-sweep-arc.md` §13.3) named T7 the largest
remaining trace mechanism and asked for *a scoping doc, not a patch*. This is
that doc.

Sources of evidence: merged `results_graphics.json` across all suites, six
local `verify_output.py --diff` runs at HEAD, our runtime
(`SWFModernRuntime/src/avm2/`), our recompiler (`SWFRecomp/src/abc/`), and the
oracle (`~/CC/ruffle`, `core/src/avm2/globals/avmplus.{rs,as}` +
`api_version.rs` + 470 playerglobal `.as` files).

---

## 0. TL;DR

* **The live pool is 25 tests / 17,723 mismatched lines** — 2.6× the board's
  "~6800 lines". T7 is *bigger* than booked, not smaller.
* **It is not one mechanism, it is four**, and they have wildly different
  costs. In ascending order: (1) the `$`-class / `<factory>` model we never
  built, (2) `describeTypeJSON` + flag handling, which does not exist at all,
  (3) ABC trait metadata, which the recompiler parses and then throws away,
  (4) **a complete typed descriptor for the `flash.*` builtin surface plus
  per-class API-version gating** — which is ~90 % of the line count and is
  really a *playerglobal-declaration* project wearing a `describeType` label.
* **XML infrastructure is NOT a blocker.** Refuted below (§4.1): our E4X
  engine already produces byte-exact `toXMLString`/`normalizeXML` output for
  these shapes — `avm2/function_proto_created` passes today on exactly this
  path.
* **Realistic wave-2 slice: +3 tests** (`describe_type_json`,
  `describe_type_basic`, `from_avmplus/regress/bug_539328`, 459 lines) for one
  worktree agent, with a fourth (`describe_type_metadata`, +1) if that agent
  also takes a recompiler-ABI change. The 20 `all_classes/*` rows should be
  booked as a **separate multi-session arc**, sliced by package.

---

## 1. PREMISE ATTACKS (yield first)

### 1.1 "There is a memory hint that describeType failures are SCOPING-related" — REFUTED, label collision ★★

The brief points at memory `avm1-amf0-tranche7-scoping`. That memory is about
**net/socket tranche 7** (AVM1 AMF0 + `NetConnection.call` + SharedObject,
shipped `702d38a35`); the word "scoping" in its filename is *arc scoping*, and
its "T7" is a tranche number in a different numbering scheme entirely. It has
nothing to do with `describeType`, and there is no lexical/namespace-scoping
component to any diff measured here. This is a textbook instance of the
`worklist-labels-name-symptoms-not-owners` trap — do not send a wave-2 agent
hunting for a scope-chain bug.

*(The one genuinely namespace-shaped item in this arc is the
`avmplus`-package-internal visibility of `describeTypeJSON`, §5.2 P1 — but
that is a registration detail, not a scoping defect.)*

### 1.2 "~24 live tests, ~6800 failing lines" — the test count is right, the line count is 2.6× low

Measured from the merged `results_graphics.json` at the baseline commit:

| group | tests | expected lines | matched | **gap** |
|---|---|---|---|---|
| `avm2/all_classes/display/swf{9,10,11,12,13,30}` | 6 | 15,321 | 6 | **15,315** |
| `avm2/all_classes/events/swf{9,10,11,12,30}` | 5 | *(suite-ignored)* | | *(8,575)* |
| `avm2/all_classes/display3D/swf{12,13,30}` | 3 | 799 | 2 | **797** |
| `avm2/all_classes/errors/swf{9,10,30}` | 3 | 401 | 0 | **401** |
| `avm2/all_classes/accessibility/swf{9,10,30}` | 3 | 249 | 3 | **246** |
| `avm2/all_classes/security/swf{12,13,30}` | 3 | 125 | 0 | **125** |
| `avm2/all_classes/xml/swf{9,30}` | 2 | 232 | 0 | **232** |
| `avm2/describe_type_{basic,json,metadata,native}` | 4 | 601 | 2 | **599** |
| `from_avmplus/regress/bug_539328` | 1 | 15 | 7 | **8** |
| **live total** | **25** | **17,743** | **20** | **17,723** |

`avm2/all_classes/events/*` (5 rows) are in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` under *"Upstream
known_failure = true (Ruffle itself fails these)"* — they are worth **zero**
and must be excluded from any estimate. `avm2/all_classes/security/swf11`
already passes (3/3 — it is the empty-output version). `avm2/av_classes`,
named "sibling-owned" on the s12 board, **now passes 340/340 and does not use
`describeType` at all** — strike it from this arc.

Disposition check: **none** of the 25 appears in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, or any `ignored_tests.txt`. All 25 are legitimately
open.

### 1.3 "T7 is one mechanism" — REFUTED; it is four, and one of them is ~90 % of the mass

See §5. The `all_classes/*` rows (20 of 25 tests, 17,116 of 17,723 lines) do
not fail because `describeType` is wrong — they fail because *the thing being
described does not exist in typed form*. Our builtins are C registrations with
no return types, no parameter types, no optionality, and no API version. A
byte-perfect `describeType` would still print the wrong document for every one
of them.

### 1.4 The board's `all_classes` framing hides a second, independent requirement

`all_classes/*` tests **version-gate the builtin surface**, and we get it wrong
in *both* directions:

* `all_classes/display3D/swf12` — Flash exposes exactly 3 of 18 classes at
  SWF 12; **we resolve all 18** (15 spurious `<type>` blocks). Ruffle tags
  `Context3D` `[API("674")]` = `ApiVersion::SWF_13`.
* `all_classes/accessibility/swf9` — we happen to be *right* (both
  `ISearchableText`/`ISimpleTextSelection` correctly report "not accessibile"),
  but only by accident: we never implemented them at all. At swf10/swf30 the
  same two classes must be **present**, and we still won't have them.

This is a genuinely separate axis from `describeType` and should be costed
separately.

---

## 2. What every one of these tests actually does

Two shapes, and the difference matters for how exact we must be:

**Shape A — normalized XML (23 of 25 tests).** `all_classes/*` and
`describe_type_{basic,metadata,native}` all ship the same `normalizeXML()`
helper: it prints `<name`, then `for each (attr in data.attributes())`, then
**sorts the stringified children lexicographically** before printing them.
⇒ **Element order is normalized away.** We do *not* have to reproduce avmplus's
Traits-hashtable iteration order. **Attribute order is not sorted** and must
match exactly (`name`, `access`, `type`, `declaredBy`, `uri` for accessors;
`name`, `declaredBy`, `returnType`, `uri` for methods — the `uri` lands last
because `copyUriAndMetadata` runs after `copyParams`).

**Shape B — raw `toString()` (`bug_539328` only).** An avmplus assertion whose
*expected* text is a `FAILED! expected: … got: …` line, where the `got:` half is
real Flash output. Here **element order does matter** (`extendsClass`,
`extendsClass`, `accessor`, `factory`) — but Ruffle's `copyTraits` order
(bases → interfaces → constructor → variables → accessors → methods, then
factory) happens to produce exactly that. Mirroring `avmplus.as` gets it for
free.

**Shape C — plain object dump (`describe_type_json` only).** No XML at all;
`printObject` walks the `describeTypeJSON` result over 12 flag combinations.

---

## 3. Our implementation today

`SWFModernRuntime/src/avm2/avm2_globals.c:1758-1975`
(`global_describe_type` + `dt_set_attr`/`dt_child`/`dt_param`), registered at
`:3728-3731`:

```c
builtin_add_global_fn_ns(ctx, "flash.utils", "describeType", global_describe_type_utils);
builtin_add_global_fn_ns(ctx, "avmplus",     "describeType", global_describe_type);
```

Its own comment (`:1758-1764`) is honest about the scope:

> "Scope: attributes, the extendsClass chain, the constructor …, and Object's
> three AS3 instance methods. **Trait enumeration for arbitrary classes is not
> modeled yet.**"

What it emits: `@name`, `@base`, `@isDynamic`, `@isFinal`, `@isStatic`; one
`<extendsClass>` per superclass; a `<constructor>` from
`Avm2AbcMethodData.param_types`/`optionals` when the class came from ABC, or a
hardcoded `<parameter index="1" type="*" optional="true"/>` for builtins; and,
for `Object` instances only, a hardcoded `hasOwnProperty`/`isPrototypeOf`/
`propertyIsEnumerable` trio.

What it does **not** do:

1. **`arg[1]` (flags) is read nowhere.** All 11 `DescribeTypeFlags` are
   ignored. This alone breaks `describe_type_json` (12 flag combinations) and
   `describe_type_basic` (`HIDE_OBJECT`).
2. **No `$`-class / static-side model.** For a `Class` value we describe the
   *instance* class. Flash describes the C-traits: `base="Class"`,
   `isDynamic="true" isFinal="true" isStatic="true"` (**constant for every
   class object** — verified across all 14 `<type>` blocks of
   `describe_type_basic`), the class's *static* traits, `<extendsClass
   type="Class"/>` + `<extendsClass type="Object"/>`, an `<accessor
   name="prototype" access="readonly" type="*" declaredBy="Class"/>`, and a
   nested `<factory type="…">` carrying the whole instance side.
3. **No `<factory>`, `<implementsInterface>`, `<variable>`, `<constant>`,
   `<accessor>`, `<method>`, `<metadata>`** — six of the eight element kinds.
4. **`@base` is emitted in dot form.** `avm2_globals.c:1897` calls
   `avm2_class_qname_buf` (dot) where every other name uses
   `avm2_class_qname_colons_buf`. Observed: `base="Test.as$38.Base"`,
   `base="flash.xml.XMLNode"`, `base="flash.events.EventDispatcher"` where
   Flash says `::`. **One-line fix; affects every test in the arc.**
5. **Builtin `isDynamic`/`isFinal` are wrong** because `avm2_builtin_class`
   (`avm2_globals.c:330-351`) leaves `flags = 0`. `flash.events::Event`
   reports `isDynamic="true"`; Flash says `false`.

Verified diffs at HEAD (local runs, sequential):

| test | symptom |
|---|---|
| `describe_type_native` | 0/23. `isDynamic` wrong; generic `*` constructor instead of `(String, Boolean=, Boolean=)`; **zero** of the 6 accessors and 8 methods. |
| `describe_type_basic` | 1/152. Class values described as instances (no `base="Class"`, no `factory`); `new Object()` prints the Object trio where Flash prints `<type …/>` (that is `HIDE_OBJECT`); dot-form `@base`; no ABC traits at all. |
| `describe_type_json` | 1/301. **`ReferenceError: Error #1065: Variable describeTypeJSON is not defined.`** — the entry point does not exist. |
| `all_classes/accessibility/swf9` | 1/73. Class resolution + version gating already **correct**; 100 % of the diff is describeType content. |
| `all_classes/xml/swf9` | 0/116. Same, plus dot-form `@base`. All three classes exist. |
| `all_classes/display3D/swf12` | 1/61. 15 spurious classes (no API gating) + describeType content. |
| `regress/bug_539328` | 7/15. `describeType(IBar, FLASH10_FLAGS).toString()` returns **the empty string** — an E4X element with no children stringifies to its (empty) text content, which is correct E4X; the real defect is that we generate no children for an interface. |

---

## 4. The oracle model, and what we can already satisfy

Ruffle splits it in two, and **we should copy the split verbatim**:

* `core/src/avm2/globals/avmplus.rs:19-71` — native `describeTypeJSON(o, flags)`
  → a plain object `{name, isDynamic, isFinal, isStatic, traits}` where
  `traits = {bases, interfaces, variables, accessors, methods, constructor,
  metadata}`; each field is `null` unless its `INCLUDE_*` flag is set
  (`:89-437`).
* `core/src/avm2/globals/avmplus.as:32-137` — pure AS that walks that object
  into XML, then calls `describeTypeJSON(value, flags | USE_ITRAITS)` a second
  time to build `<factory>`.
* `core/src/avm2/globals/flash/utils.as:9-18` — `flash.utils.describeType(v)` =
  `avmplus.describeType(v, FLASH10_FLAGS)`, with the `#1010`-on-`undefined`
  pre-check we already have.

`FLASH10_FLAGS` = `INCLUDE_BASES|INTERFACES|VARIABLES|ACCESSORS|METHODS|
METADATA|CONSTRUCTOR|TRAITS|HIDE_NSURI_METHODS|HIDE_OBJECT` (note: **no**
`USE_ITRAITS`).

Two avmplus rules that are easy to miss:

* **`HIDE_NSURI_METHODS`** (`avmplus.rs:158-172`): collect every non-empty
  namespace that declares a *method* in the **superclass** vtable; skip every
  trait in those namespaces. This is what suppresses inherited `AS3::` methods.
* **`<constructor>` is emitted only when the constructor has ≥1 parameter**
  (`avmplus.rs:388-397`), and `INCLUDE_CONSTRUCTOR` must be set.
* **`readonly` slot ⇒ `<constant>`, otherwise `<variable>`**
  (`avmplus.as:83`) — the element name, not an attribute.

### 4.1 REFUTATION: "XML infra gaps block everything else" ★

They do not. `avm2/function_proto_created` **passes today** and its expected
output is a 12-line `describeType` XML dump (`output.txt:51-61`) produced
through `dt_child`/`dt_set_attr` → `avm2_xml_object_for_node` → our E4X
`toXMLString` — including two-space indentation of nested `<parameter>`. The
E4X engine (`avm2_xml.c`, 94 builtin registrations), `E4XNode`,
`avm2_e4x_element/attribute/insert_at/append_attribute`, `attributes()`,
`children()`, `name()`, `sort()` on the AS side — all already exercised by
these very tests. **No XML work is required by this arc.**

### 4.2 What data we already hold (the good news)

For **ABC-defined classes** our runtime holds everything Ruffle reads:

| Ruffle needs | we have |
|---|---|
| `vtable.resolved_traits()` — name, ns, kind | `Avm2Class.ivtable` → `Avm2PropEntry{key, kind}` (`avm2_class.h:44-67`); `kind` ∈ SLOT/METHOD/GETTER/SETTER/**GETSET** |
| `Property::ConstSlot` vs `Slot` | `Avm2PropEntry.is_const` |
| slot type name | `Avm2PropEntry.type_mn` + `type_file` |
| method return/param types, optionality | `Avm2MethodRef{file, method_index}` → `Avm2AbcMethodData.return_type_mn` / `param_types[]` / `optionals[]` (`avm2_abc.h:103-120`) |
| `method.bound_class()` (`declaredBy`) | `Avm2PropEntry.defining_class` (+ `setter_defining_class` for split accessor halves) |
| `ns.as_uri()` (`@uri`) | `Avm2PropEntry.key.ns_uri` / `ns_len` / `ns_kind` |
| `class_def.all_interfaces()` | `Avm2Class.interfaces` + `resolve_interfaces` (`avm2_class.c:1614`) — **direct only; needs a transitive walk** |
| static traits | `cls->class_object->vtable`, built at `avm2_class.c:1368-1382` |

Two data shortfalls even on the ABC side:

* **`Vector.<T>` type names.** `avm2_propkey_from_qname` fails on TypeName
  multinames (kind `0x1d`). `describe_type_basic`'s last line wants
  `type="__AS3__.vec::Vector.<int>"`. `avm2_class.c:1721` already handles
  `0x1d` for resolution; the *name formatter* is the missing piece
  (`avm2_vector.c:255-300` builds the same string for real classes).
* **Trait metadata is parsed and discarded.** `SWFRecomp/src/abc/abc_parser.cpp`
  reads the metadata pool (`:401-430`, `:575-578`) and per-trait indices
  (`:473-479`) into `AbcMetadata`/`Trait::metadata`; `abc_emit.cpp` contains
  **zero** occurrences of "metadata", and `Avm2AbcTrait` (`avm2_abc.h:62-70`)
  and `Avm2AbcFileData` have no field for it. Emitting it is an additive,
  append-at-the-end generated-ABI change (same shape as `intrinsic_id` on
  `Avm2AbcClassData`).

### 4.3 What we do NOT hold (the bad news, and it is the bulk)

`avm2_builtin_add_method(ctx, cls, "name", fn)` — that is the entire
signature. No return type, no parameter types, no optionality, no `uri`, no
API version. Same for `add_getter`/`add_getset`/`add_static_method`. There are
**1,344 such registrations** across `SWFModernRuntime/src/avm2/*.c`:

| helper | sites |
|---|---|
| `avm2_builtin_add_method` | 518 |
| `avm2_builtin_add_getset` | 351 |
| `avm2_builtin_add_getter` | 168 |
| `avm2_builtin_add_static_const` | 136 |
| `avm2_builtin_add_static_method` | 54 |
| others | 117 |

And a structural wrinkle: **builtin static consts are not traits.**
`avm2_builtin_add_static_const` (`avm2_globals.c:541-552`) stores a
`dont_enum + read_only` **dynamic property** on the class object, deliberately
("statics-as-slots would need slot storage"). Any static-side enumeration must
walk the class object's dynamic-prop list as well as its vtable, and derive
`type` from the stored `Avm2Value` kind (String/int/uint/Number) — which,
usefully, is exactly enough for the constant-only enum classes that dominate
`display3D` and `events`.

Now compare against what `all_classes` demands:

| suite/version | classes | methods | accessors | variables | constants | interfaces |
|---|---|---|---|---|---|---|
| `display/swf30` | 65 | 410 | 705 | 27 | 115 | 48 |
| `display/swf9` | 33 | 286 | 482 | 0 | 76 | 27 |
| `display3D/swf30` | 18 | 43 | 26 | 0 | 70 | 1 |
| `display3D/swf12` | 3 | 0 | 3 | 0 | 22 | 0 |
| `errors/swf30` | 8 | 9 | 17 | 16 | 0 | 0 |
| `accessibility/swf30` | 5 | 14 | 9 | 8 | 0 | 0 |
| `security/swf30` | 3 | 1 | 22 | 0 | 9 | 0 |
| `xml/swf9` | 3 | 19 | 13 | 20 | 7 | 0 |

`display/swf30` alone wants 1,257 typed members — **more than our entire
`flash.*` registration count for every package combined**. This is the number
that should decide the arc's shape.

---

## 5. PHASED PLAN

Phases are ordered by dependency. Flip estimates are per-phase *marginal*.

### P0 — `$`-class model, `<factory>`, and the four one-line defects
**0 flips on its own. Prerequisite for everything.**
Files: `SWFModernRuntime/src/avm2/avm2_globals.c` only.

1. Split `global_describe_type` into a *static side* and an *instance side*.
   For a `Class` value: `@base="Class"`, `@isDynamic="true"`, `@isFinal="true"`,
   `@isStatic="true"` (constants — verified against all 14 `<type>` blocks of
   `describe_type_basic` and every `all_classes` expectation), bases =
   `[Class, Object]`, traits from `cls->class_object->vtable` **and** its
   `read_only` dynamic props, plus the synthetic `<accessor name="prototype"
   access="readonly" type="*" declaredBy="Class"/>`. Then a nested
   `<factory type="<qname>">` carrying the instance side.
   For a non-class value: no factory (Ruffle returns `Null` from the
   `USE_ITRAITS` pass).
2. `@base` → `avm2_class_qname_colons_buf` (`:1897`).
3. Honor `act->args[1]` as `DescribeTypeFlags`; `flash.utils.describeType`
   passes `FLASH10_FLAGS` (0x05FE… see `avmplus.as:21-30`).
4. Replace the hardcoded Object trio with a real, flag-gated enumeration.
   **Regression guard, verified:** `avm2/function_proto_created` (passing
   today) calls `avmplus.describeType(o, FLASH10_FLAGS & ~HIDE_OBJECT)` — its
   `RecompiledABC/abc0_methods.c:512-535` shows the `HIDE_OBJECT` mask being
   cleared — so honoring `HIDE_OBJECT` keeps it green *and* fixes
   `describe_type_basic`'s `new Object()` line. These two tests do **not**
   conflict.

**Risk:** the `length` constant. `Object$`, `int$` and `Class$` show
`<constant name="length" type="int"/>`; `Dictionary$` and every ABC class do
not. That is the native-vs-playerglobal distinction — needs a one-bit flag on
the handful of natively-implemented builtin classes, not a general rule.

### P1 — `avmplus::describeTypeJSON` + trait enumeration over our vtables
**+1 test (`avm2/describe_type_json`, 300 lines).**
Files: `avm2_globals.c` (new `global_describe_type_json` ≈ 250 LOC).

Port `avmplus.rs:19-437` directly: build an `Avm2Object` with `name`,
`isDynamic`, `isFinal`, `isStatic`, `traits`; `traits` gets
`bases`/`interfaces`/`variables`/`accessors`/`methods`/`constructor`/`metadata`,
each `null` unless its flag is set. Implement `HIDE_NSURI_METHODS` (superclass
method-namespace skip list), `HIDE_OBJECT`, `USE_ITRAITS`, and the
"skip traits that also exist on an implemented interface" rule
(`avmplus.rs:250-256`, `:339-346`).

**Registration wrinkle (the one namespace item in this arc):** the test's
helper is `package avmplus { public class MyHelper { … describeTypeJSON(…) } }`
calling the name *unqualified*, which resolves through
`PackageInternalNs("avmplus")`. `builtin_key` (`avm2_globals.c:263-273`)
hardcodes `ns_kind = 0x16` (package/public). `describeTypeJSON` must be
registered with **kind `0x17`** and uri `"avmplus"`. Verify
`builtin_global_define`/`avm2_domain_add` accept a non-public kind — if they
do not, that is a small extension, not a redesign.

This phase needs **no XML** and no builtin descriptors: `describe_type_json`
describes `com.ruffle::RuffleTest`, an ABC class.

### P2 — XML builder over the JSON, + a micro builtin descriptor
**+2 tests (`avm2/describe_type_basic` 151 lines, `from_avmplus/regress/bug_539328` 8 lines).**
Files: `avm2_globals.c`; plus the `Vector.<T>` type-name formatter
(`avm2_vector.c` has the string builder at `:255-300`).

Rewrite the XML side as a literal transcription of `avmplus.as:32-137` reading
the P1 JSON — that buys correct element order (matters only for
`bug_539328`) and correct attribute order (matters everywhere) for free.

`describe_type_basic` additionally needs a *tiny* builtin descriptor set —
this is the cheap end of the P4 problem and should be hand-written here rather
than generated:

* `Object$`: `<constant name="length" type="int"/>`
* `int$`: `MAX_VALUE`, `MIN_VALUE`, `length` (all `int`)
* `Class$`: `length`; `Class` factory: the `prototype` accessor
* `flash.utils::Dictionary`: constructor `(Boolean = )`, `isDynamic="true"`
* `int`/`Dictionary` sealed/final bits

**Risk (medium, flagged):** `isDynamic` correctness means marking builtin
classes `AVM2_CLASS_FLAG_SEALED`, and that flag is **enforced** at
`avm2_ops.c:211` (the dynamic-property gate). Flipping it on a class whose
instances the runtime internally decorates with dynamic props causes #1056
throws far from here. There is precedent for doing it per-class
(`avm2_globals.c:2673-2691` seals a 10-class stub group and then *un*-seals
`GameInputControl`). **Recommendation: add a separate `describe_dynamic` /
`describe_final` bit rather than repurposing `SEALED`,** unless the
implementer is prepared to audit each class.

### P3 — ABC trait metadata (recompiler + runtime)
**+1 test (`avm2/describe_type_metadata`, 125 lines).**
Files: `SWFRecomp/src/abc/abc_emit.cpp` (+ `abc_parser.cpp` already done),
`SWFModernRuntime/include/avm2/avm2_abc.h`, `avm2_class.h`
(`Avm2PropEntry`), `avm2_class.c` (`avm2_vtable_add_traits`), `avm2_globals.c`.

Emit the metadata pool (`{name, [{key, value}]}`) plus per-trait index arrays
as **append-at-the-end** fields on `Avm2AbcFileData` / `Avm2AbcTrait`, so
existing positional initializers stay valid (the `intrinsic_id` precedent,
`avm2_abc.h:147-150`). Carry the pointer onto `Avm2PropEntry`; emit
`<metadata name="…"><arg key="…" value="…"/></metadata>` per `avmplus.as:43-56`.

**Generated-ABI reach:** every test's `RecompiledABC` must be regenerated —
CI handles this, but a local `--recompile` is mandatory before believing any
local result (see memory `stale-recompiledabc`).

Note for the implementer: an accessor's metadata is the **union** of the
getter's and the setter's (`avmplus.rs:365-378`), and top-level `<type>`
metadata is a Ruffle stub (`avmplus.rs:400-412`) — `describe_type_metadata`'s
expectation must be checked against Flash, not Ruffle, if it has any.

### P4 — the builtin descriptor + API-version gating arc
**+20 tests max (all of `all_classes/*`), 17,116 lines. NOT a wave-2 item.**

This is a *declaration* project. Two co-requisites:

**(a) A typed descriptor for the `flash.*` surface.** The realistic source is
`~/CC/ruffle/core/src/avm2/globals/**/*.as` — 470 files with full AS3
signatures. A generator script (`tools/`, offline, output checked in as C
tables) can emit `{class, member, kind, type, declaredBy, uri, access,
optional, api_version}` mechanically. **Design decision the arc must settle
up front:** does `describeType` report the *descriptor* or the *real vtable*?
Reporting the descriptor makes `all_classes` pass while `describeType` lies
about members we have not implemented — which is arguably what an
API-compatibility layer should do, but it is a policy call, not a detail. The
alternative (thread types through all 1,344 registration sites) is a much
larger and much more invasive change.

**(b) Per-class/per-member API-version gating.** Ruffle's `[API("N")]` maps to
`api_version.rs`'s `ApiVersion` ordinal as `N - 660`; `SWF_12 = 12`,
`SWF_13 = 14`, `SWF_17 = 22`, `SWF_30 = 48`. We already do this ad hoc for
three cases — JSON at SWF 13 (`avm2_globals.c:3963-3968`), four `Event`
constants at SWF 17 (`avm2_events.c:2049-2071`), Math-on-Number at SWF 16 —
using `if (ctx->swf_version >= N)` on the **root** movie's version, which is
the correct gate (`avm2/cross_api_version_call_{older,newer}` prove it). The
generator should emit the same idiom, or a table the registration loop
consults.

Slice by package, cheapest first:

| slice | tests | lines | classes / typed members |
|---|---|---|---|
| **P4a** `display3D` | 3 | 797 | 18 classes, mostly `String`/`int` constants — derivable from the values we already store; `swf12` needs only the API gate + P0 |
| **P4b** `security` + `accessibility` + `errors` + `xml` | 11 | 1,004 | ~19 classes, ~120 typed members |
| **P4c** `display` | 6 | 15,315 | 65 classes, 1,257 typed members |

P4c is the single largest line block in the whole trace corpus and should be
costed as its own multi-session project (or explicitly declined — see §7).

---

## 6. Wave-2 recommendation

**Take one worktree agent: P0 + P1 + P2 → +3 tests (459 lines), one commit
per phase.** It is self-contained in `avm2_globals.c` (plus one small
`avm2_vector.c` helper), needs no recompiler change, needs no generated-ABI
change, has a fully-enumerated regression surface, and it builds the engine
every later phase depends on. Confidence: **HIGH** for `describe_type_json` and
`describe_type_basic`; **MEDIUM** for `bug_539328` (exact `toString()` shape,
plus the odd `::IBar` / `uri="Test.as$34:IBar"` spellings Flash emits for a
package-less interface — treat it as a rider, not a commitment).

**Optionally add P3 → +4** if the agent is comfortable with a recompiler
emit + generated-ABI change; run CI with `categories=full` and expect every
`RecompiledABC` to regenerate.

**Do not open P4 this session.** Recommend instead a spike deliverable: the
`.as` → descriptor generator prototyped against **`flash.events::Event`
alone** (6 accessors + 8 methods → `describe_type_native`, +1 test, 23 lines)
and then `display3D` (+3 tests, 797 lines). Those two steps prove both halves
of the mechanism — typed members and API gating — before anyone commits to
`display`'s 1,257 members.

**Canary set for any of the above** (tests that touch `describeType`,
`getQualifiedClassName`, `getQualifiedSuperclassName`, or E4X `toXMLString`
and pass today — all must stay green):
`avm2/function_proto_created`, `avm2/null_void_types`, `avm2/number_autoconv`,
`avm2/number_autoconv_amf`, `avm2/av_classes`,
`avm2/displayobject_name_from_timeline`, `avm2/font_enumeratefonts{,_filter,_order}`,
`avm2/all_classes/security/swf11`, plus the standard AVM2 XML/E4X set.

---

## 7. Strategic note for the board

At 17,723 lines, T7 is the largest single line block left in the trace corpus —
but **86 % of it (`all_classes/display` + the rest of P4) is not a
`describeType` problem at all.** It is the cost of not having a declarative
playerglobal. Two honest options for §13.3:

1. **Re-book it.** Split T7 into `T7-describeType` (5 tests, 607 lines — of
   which P0–P3 flips 4 / 584 lines; `describe_type_native` is the fifth and
   needs only a *one-class* builtin descriptor for `flash.events::Event`,
   6 accessors + 8 methods, so it is the natural P4 pilot) and a new
   `T10-playerglobal-descriptor` (20 tests, 17,116 lines) that is explicitly
   an arc, not a mechanism.
2. **Cap it.** Take P0–P3 (+4), then declare `all_classes/*` capped pending
   the descriptor-generator spike — the same treatment `blend_modes` got.

Either way the board's current line — "T7 describeType is the largest
mechanism (24 live tests, ~6800 lines)" — should be corrected to **25 live
tests / 17,723 lines, four mechanisms**, with the note that the 5
`all_classes/events` rows are upstream `known_failure` and worth zero.
