# Session 13 · wave 2 · T7 `describeType` — P0 + P1 + P2 implementation report

**Agent:** wave-2 worktree (`.claude/worktrees/agent-a655b4467e99edb7c`), branched from
`10931d62e` (master). **Deliverable:** `w2-describetype.patch` (not committed).
**Brief:** `SWFRecompDocs/plans/session13-fanout-reports/wave1-t7-describetype.md` §5 P0–P2.

## 0. Result

**+3 trace tests flip locally, exactly as the wave-1 brief predicted.**

| test | baseline | with patch |
|---|---|---|
| `avm2/describe_type_json` | FAIL — `ReferenceError #1065: Variable describeTypeJSON is not defined` (1/301 lines) | **PASS** |
| `avm2/describe_type_basic` | FAIL (1/152 lines) | **PASS** |
| `from_avmplus/regress/bug_539328` | FAIL (7/15 lines) | **RUFFLE_MATCHED** (= counted as pass) |
| `avm2/function_proto_created` | PASS | **PASS** (regression guard held) |

Two T7 tests deliberately left failing (they are P3/P4, out of scope) but both
improved from "structurally wrong" to "structurally right, wrong types":

* `avm2/describe_type_metadata` — every element/attribute now correct; the only
  remaining diff is the missing `<metadata>`/`<arg>` children (P3, recompiler
  ABI).
* `avm2/describe_type_native` — all 6 accessors and all 8 methods of
  `flash.events::Event` are now emitted with correct names, access and
  `declaredBy`; only the *types* are `*` instead of `Boolean`/`String`/… and
  `isDynamic` is wrong (P4, builtin descriptor + sealing).

## 1. What changed

Three files, all runtime. No recompiler change, no generated-ABI change, so
`RecompiledABC` regeneration is **not** required.

### `SWFModernRuntime/src/avm2/avm2_globals.c` (the bulk, ~990 lines net)

`global_describe_type` (the old ~140-line special-cased emitter) was replaced by
a faithful transcription of Ruffle's two-part model:

* **`dt_describe()`** — the `avmplus.rs describe_type_json` body, producing a C
  intermediate (`DtDesc`: name, isDynamic/isFinal/isStatic, bases, interfaces,
  variables, accessors, methods, constructor params). Scratch-allocated with
  plain `malloc`/`free` so repeated calls (65 per `all_classes` row) never touch
  the AVM2 heap.
* **`dt_json_build()`** — emits that description as a live AS `Object` graph for
  `describeTypeJSON`.
* **`dt_copy_traits()` / `global_describe_type`** — emits the same description
  as E4X, in the exact element and attribute order of `avmplus.as`
  (`bases → interfaces → constructor → variables → accessors → methods`, then the
  nested `<factory>`), because `bug_539328` compares the raw `toString()`.

Specific P0 items from the brief, all done:

1. **`$`-class / `<factory>` model.** A `Class` value is now described as its
   *class* traits: `@base="Class"`, `isDynamic/isFinal/isStatic` all `"true"`,
   bases `[Class, Object]`, traits = `class_object->vtable` ∪ `Class`'s own
   instance vtable (which supplies the synthetic
   `<accessor name="prototype" … declaredBy="Class"/>`) ∪ the class object's
   read-only dynamic props (that is where `avm2_builtin_add_static_const` puts
   builtin statics). The `USE_ITRAITS` pass describes the instance side and
   becomes `<factory>`; for a non-class value it returns `Null`, so instances
   get no factory.
2. **dot→colon `@base` fixed** — `@base` now uses `avm2_class_qname_colons_buf`
   like every other name.
3. **`arg[1]` (flags) is now honoured.** All 11 `DescribeTypeFlags` are read.
   `flash.utils.describeType(v)` defaults to `FLASH10_FLAGS` (`0x05FF`, already
   registered correctly).
4. **The hardcoded Object trio is gone**, replaced by real flag-gated
   enumeration.

P1: **`avmplus::describeTypeJSON` now exists.** Registered through a new
`builtin_add_global_fn_ns_kind()` under **`ns_kind 0x17`
(`PackageInternalNs("avmplus")`)** *and* under the ordinary public kind. The
kind matters — I confirmed from the test's own `RecompiledABC/abc0_tables.c`
that ASC compiles the call site as `QName(PackageInternalNs "avmplus",
"describeTypeJSON")`, and `avm2_ns_fold` deliberately does not fold `0x17` onto
public, so the plain package registration alone still 1065'd.

P2: **the builtin descriptor stayed tiny — much smaller than the brief
budgeted.** Only two special cases were needed:
* `flash.utils::Dictionary`'s constructor is `(Boolean = )` (everything else
  native keeps the avmplus 1-optional-`*` shell form; `Object` and `Class` take
  none).
* Nothing at all for the `length` constant — `register_class_object_lengths()`
  (`avm2_globals.c:4590`) *already* installs `length` as a read-only static
  const on `Object`/`Class`/`int`/…, so once the static side walks read-only
  dynamic props it appears for free. My first draft added a synthetic one and it
  showed up twice; that code was removed.

Three engine-shaped rules had to be modelled to get the flags right:

* **`HIDE_OBJECT`** skips methods whose declaring class is `Object`. The brief's
  non-conflict claim is **confirmed**: `function_proto_created` calls with
  `HIDE_OBJECT` cleared and stays green, while `describe_type_basic`'s
  `new Object()` line (`<type … isStatic="false"/>`, empty) now matches.
* **The ES3 trio is restated by hand on `Class` and `Function`** (a bootstrap
  ordering artefact, `es3_trio_hosts` at `avm2_globals.c:4695`). avmplus
  declares `hasOwnProperty`/`isPrototypeOf`/`propertyIsEnumerable` once, on
  `Object`, and inherits. `dt_is_object_as3_method()` recognises the restated
  copies and reports them as `declaredBy="Object"` with the AS3 uri, so
  `HIDE_OBJECT` removes them — without which every class's static side printed
  three spurious `declaredBy="Class"` methods.
* **`HIDE_NSURI_METHODS` needs a namespace-ORIGIN axis.** Ruffle compares
  namespaces with `exact_version_match`, so playerglobal's AS3 and a SWF's own
  AS3 are *different* namespaces despite an identical URI — that is precisely
  what lets `Base`'s `AS3::as3Method` survive while `int`'s inherited
  `toFixed`/`valueOf`/… are suppressed. We have no API versions, so I used
  native-vs-ABC origin (taken from the **declaring class**, not the method ref —
  a setter-only entry leaves `method` empty). Paired with
  `dt_native_as3_method()`, which reports the instance methods of *top-level*
  native classes (`Object`, `int`, `String`, …) as AS3-namespaced the way
  avmplus really declares them (flash.* classes keep their public spelling,
  which is why the test is on the declaring class having no package).

### `SWFModernRuntime/include/avm2/avm2_class.h` + `avm2_class.c` (16 lines)

* New `uint8_t Avm2PropEntry.is_iface_alias`, set in
  `add_iface_aliases_from()`. Our runtime copies a public implementation into
  each implemented interface's namespace so interface-typed call sites resolve;
  avmplus has no such trait, so without the marker every implemented member was
  reported twice (once public, once with `uri="pkg:IFace"`).
* New export `avm2_class_resolve_interfaces()` — a one-line wrapper over the
  existing file-static `resolve_interfaces`, for the `all_interfaces` walk.

## 2. Flagged risk from the brief: NOT taken

The brief warned against marking builtins `AVM2_CLASS_FLAG_SEALED` for
`isDynamic` correctness (enforced at `avm2_ops.c:211`). **No class flags are
written by this patch at all** — and it turned out none were needed:
`describe_type_basic`'s `isDynamic`/`isFinal` expectations already matched
(`int` is already SEALED|FINAL, `Dictionary` already dynamic). The separate
describe-only bit the brief recommended was therefore not needed either; the
only class left wanting it is `flash.events::Event` (`describe_type_native`),
which is a P4 test regardless. **`avm2_ops.c` is untouched.**

## 3. Per-test results (all local, `--mode=no-graphics`, sequential)

### Targets
```
describe_type_basic     PASS
describe_type_json      PASS
function_proto_created  PASS
bug_539328              RUFFLE_MATCHED   (from_avmplus/regress)
```

### Canaries (all passed at baseline; all still pass)
```
avm2/av_classes                          PASS
avm2/catch_scope_slot                    PASS
avm2/displayobject_name_from_timeline    PASS
avm2/font_enumeratefonts                 PASS
avm2/null_void_types                     PASS
avm2/number_autoconv                     PASS   ← the sharpest one: pins
                                                  int's HIDE_NSURI suppression
avm2/property_is_enumerable              PASS
avm2/static_length                       PASS   ← pins class-object `length`
avm2/supercall_two_classobjects          PASS
avm2/vector_object_final                 PASS
avm2/all_classes/security/swf11          PASS   ← the one all_classes row that
                                                  passes at baseline
from_avmplus/ecma3/ObjectObjects/hasOwnProperty        PASS
from_avmplus/ecma3/ObjectObjects/propertyIsEnumerable  PASS
```
`hasOwnProperty`/`propertyIsEnumerable`/`static_length` were chosen deliberately:
they are the tests that would break if the AS3-vs-public re-keying or the
class-object static-const surface had been changed for real rather than
described differently.

### Still failing (unchanged status, improved content)
```
avm2/describe_type_metadata   MISMATCH — needs P3 (ABC trait metadata)
avm2/describe_type_native     MISMATCH — needs P4 (typed builtin descriptor)
```

## 4. Expected CI movement

`mode=graphics`, `categories=full` (the change is AVM2 runtime).

* **+2** in the `avm2` suite (`describe_type_basic`, `describe_type_json`).
* **+1** in `from_avmplus` (`regress/bug_539328` → `ruffle_matched`, which the
  runner counts in `pass_list`).
* **Net +3 effective passes** → 4232 from the 4229 baseline, if nothing else moves.
* No pixel-axis effect (no render code touched). Image comparisons never gate.

`all_classes/*` output changes substantially (much closer to correct) but none
of those rows flips; `security/swf11` — the only one that passes — is verified
green.

## 5. Merge risks

* **Low collision surface.** `avm2_globals.c` and `avm2_class.{c,h}` were named
  as mine alone this session; siblings are in `tag.c`, `render_webgpu.c`,
  `action.c` and the recompiler. The `avm2_class.c` edits are two isolated
  insertions (one line inside `add_iface_aliases_from`, one 4-line wrapper
  before `avm2_class_has_interface`).
* **`Avm2PropEntry` grew one byte.** It is a runtime-internal struct built only
  by `memset`+field assignment (no positional initializers anywhere, checked)
  and copied by value through `avm2_vtable_append`, so no generated code and no
  ABI is affected.
* **One new global name** (`avmplus::describeTypeJSON`, both public and
  package-internal kinds). It did not exist before, so nothing can be shadowed.
* **`describeType` output changed for every class**, so any test not in the
  canary list that calls it would move. I enumerated the corpus two ways
  (`grep describeType` over `*.as`, and over every `RecompiledABC/*.c` so that
  source-less SWFs are covered); the complete consumer list is the 11 test dirs
  above plus `all_classes/*`, and all of them are accounted for.
* **`malloc`/`free` in AVM2 code.** Deliberate: the description never outlives
  the call (`avm2_string_from_literal` copies), and keeping it off the o1heap
  avoids leaking a few MB per `all_classes` row into a heap that is never
  compacted. Every path frees, including the two early `!d.valid` returns.

## 6. What P3 / P4 can now build on

The P0 groundwork is the part that was genuinely missing, and it is now reusable:

* **`DtDesc` is the single description**, and both emitters read it. P3
  (metadata) is now: add a `DtMember.metadata` list, fill it in
  `dt_collect_vtable`, and emit it in `dt_copy_traits`/`dt_json_members`
  (`copyUriAndMetadata` order is already correct, and the `metadata` JSON key is
  already flag-gated the way Ruffle gates it, including the accessor-specific
  "null unless non-empty" rule).
* **`dt_collect_ctor` and the accessor/method branches already have the single
  place** where a typed builtin descriptor (P4) would be consulted — today they
  fall through to `"*"` and the 1-optional-`*` constructor. A descriptor table
  keyed by class + member name plugs in at exactly three `dt_sdup("*")` sites.
* **`describe_type_native` is now a pure P4-pilot**: the element set, ordering,
  `declaredBy`, `access` and the `<constructor>` element are all already right
  for `flash.events::Event`; only 14 member types, 3 constructor parameters and
  one `isDynamic` bit are missing. That is a much better shape for the
  ".as → descriptor generator" spike the wave-1 doc recommends than it was.
* **The origin-aware `HIDE_NSURI_METHODS` and the `is_iface_alias` marker** are
  the two engine facts a P4 descriptor would otherwise have rediscovered the
  hard way.
* Untouched and still open: `Vector.<T>` type names are handled
  (`dt_mn_name_buf` spells out TypeName multinames — `describe_type_basic`'s
  `__AS3__.vec::Vector.<int>` line passes), so that brief item is **done**, not
  deferred.

## 7. Housekeeping notes

* Test dirs were copied into the worktree's canonical suite paths and run with
  `--recompile` on first use; the main repo's test dirs were never targeted.
  (The two "COMPILE_FAIL / ld returned 1" results seen mid-session were stale
  `RecompiledTags` in freshly-copied dirs — `undefined reference to
  avm2_generated_fonts` — and cleared on `--recompile`, per the
  `stale-recompiledabc` memory. They were not real failures.)
* `SWFRecomp/build` was copied from the main repo rather than rebuilt; no
  `SWFRecomp/src/` file is touched by this patch, so that shortcut is valid.
* Nothing was committed anywhere.
