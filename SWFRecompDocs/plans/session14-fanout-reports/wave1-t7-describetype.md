# Session 14 · wave 1 · T7 `describeType` — P3 + P4 scoping

**Agent:** wave-1 diagnosis (read-only, main tree). **HEAD:** `0a99be1a9`.
**Baseline:** CI run `31130292354` (`graphics/full/images=true`, commit
`fb36ba110`), merged at `e62ab7471`. Trace 4237 effective.
**Predecessors:** `session13-fanout-reports/wave1-t7-describetype.md` (the
P0–P4 split), `session13-fanout-reports/w2-describetype-report.md` (P0–P2
shipped), `polish-sweep-arc.md` §14.3.

Evidence: merged `avm2/_results/results_graphics.json` at the baseline SHA,
**nine** local `verify_output.py` runs at HEAD (`--save-actual` block diffs, not
the runner's positional line metric), the runtime
(`SWFModernRuntime/src/avm2/`), the recompiler (`SWFRecomp/src/abc/`),
`SWFRecomp --dump-abc` over every describeType consumer, and the oracle
(`~/CC/ruffle` `avmplus.rs` / `avmplus.as` / `metadata.rs` / `api_version.rs` /
`globals/flash/**/*.as`).

---

## 0. TL;DR

* **P0 (new this session, folded in from the board audit): s13's P0–P2 opened a
  version-gate hole and it is now the top item in this brief.**
  `all_classes/display3D/swf12` regressed 109 → 321 actual lines (gap 60 → 260)
  because we emit the full `flash.display3D` dump at every SWF version. I
  measured it independently and **refute the audit's "flipping it outright is
  optimistic" caveat**: with the gate plus the native-constructor rule the row
  flips completely (§2.2 / §4.1). CI will not flag it on its own — the row was
  already failing, the `transition-diff-hides-new-crashes` trap.
* **P3 is confirmed, exactly +1, and its blast radius is exactly one test.**
  I diffed `describe_type_metadata`'s actual against expected with
  `<metadata>`/`<arg>` stripped: **byte-identical**. Every element, attribute,
  ordering and `declaredBy` P0–P2 produces is already right. And
  `--dump-abc | grep -c '\[metadata:'` is **0** for `describe_type_json`,
  `describe_type_basic`, `function_proto_created` and `bug_539328` — only
  `describe_type_metadata` (15 traits) carries trait metadata anywhere in the
  describeType consumer set. **GO.**
* **The P4 sub-slice test counts (+3/+11/+6) are correct**, but the s13
  brief's *cost ordering inside them is wrong*, and I found three
  describeType-side rule bugs that no descriptor can fix and that block whole
  rows on their own (§2.2–2.4).
* **The s13 pilot (`describe_type_native` alone, +1) undersells the cheap
  end by 8×.** A single wave-2 agent building the descriptor machinery can
  reach **+8** — `describe_type_native`, `all_classes/display3D/swf12`,
  `all_classes/errors/{swf9,swf10,swf30}`, `all_classes/security/{swf12,swf13,swf30}`
  — because two of those slices need *no member descriptors at all* and one
  needs only three tiny entries. **GO, re-scoped** (§6).
* **`all_classes/display` (6 tests, 15,321 lines) stays an arc**, and so do
  `xml` (+2) and `accessibility` (+3) — those three need real member
  registration, not just types.
* **P3 and the P4 pilot must be the SAME agent**: both rewrite `DtMember`,
  `dt_collect_vtable`, `dt_json_members` and `dt_copy_traits`. Splitting them
  guarantees a merge conflict in the `dt_*` region of `avm2_globals.c`.

### 0.1 Coordinator mid-flight items — both incorporated

1. **Version-gate hole (`display3D/swf12`)** — incorporated as **§2.2 (new P0)**
   and as commit 5 of the plan in §6, with the implementation-ready mechanism
   in §4.1 (`avm2_builtin_class_api` + the oracle-verified `[API(N)]` table).
   One refutation of the audit's pricing is recorded there.
2. **"25 live `all_classes` rows, not 20"** — reconciled in **§2.1**. Both
   numbers are right for different denominators: **25 rows exist, 20 are
   graded.** The delta is exactly the 5 `all_classes/events` rows, which sit in
   `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:54-58` under *upstream
   `known_failure` = true*. They move the headline row count but **not the
   effective-pass number**, so this brief prices in graded rows (20) and flags
   the 5 separately rather than quietly adopting either figure.

---

## 1. PREMISE ATTACKS

### 1.1 "`describe_type_metadata` matches 5 of 125 lines" — the metric lies ★★

`results_graphics.json` reports `expected_lines=125, matching_lines=5`, which
reads as *"structurally broken"*. It is not: our actual is 36 lines, all of
them correct, and the runner's positional compare shifts every line once the
`<metadata>` children are missing. This is the `results-diff-line-metrics-mislead`
memory in its purest form. Verified mechanically:

```
strip <metadata>/<arg>/</metadata> from expected, collapse
"<x ...>...</x>" that lost all children into "<x .../>"
→ IDENTICAL after stripping metadata
```

Do not let a wave-2 agent "fix the structure". There is nothing to fix.

### 1.2 "P4a `display3D` is the cheapest slice (18 classes of constants)" — half right ★★

`display3D` is **three tests with three different costs**, not one slice:

| test | what it actually needs |
|---|---|
| `display3D/swf12` (61 lines) | **API gating only** (+ the native-constructor rule). Block-diffed at HEAD: all 22 constants of the three accessible classes already carry the right `type=`; the *only* content delta is a spurious `<constructor><parameter index="1" type="*" optional="true"/></constructor>` in each `<factory>`. Everything else is the 15 classes we expose that Flash hides. |
| `display3D/swf13` (326 lines) | + the full `Context3D`/`Program3D`/`VertexBuffer3D`/`IndexBuffer3D` descriptor (39 methods, 15 accessors, 97 parameters) |
| `display3D/swf30` (412 lines) | + 5 more gated classes (43 methods, 26 accessors, 110 parameters) |

So `display3D/swf12` is a near-free +1 and `display3D/swf13,swf30` belong with
`display` in the arc, not with the pilot.

### 1.3 "`security` is part of the mid-cost P4b bundle" — it is the CHEAPEST row in the whole arc ★★

`all_classes/security/swf12`'s *entire* expected output is 19 lines, and our
actual differs by exactly one thing: `flash.security::CertificateStatus`
**does not exist in our runtime**. Nine `String` constants and an API gate flip
it. `swf13`/`swf30` (identical files) add two more stub classes,
`X500DistinguishedName` (6 readonly `String` accessors + `toString`) and
`X509Certificate` (13 readonly accessors), with **no methods to implement** —
the test only calls `describeType`. `security/swf11` already passes (all three
inaccessible) and pins the gate from below.

### 1.4 "P4 = typed descriptors" — three of the blockers are describeType RULE bugs, not missing types ★★

None of these can be fixed by a descriptor table, all three are ≤20 LOC, and
each one currently corrupts *every* `all_classes` row:

1. **The native-constructor fallback is wrong.** `dt_collect_ctor`
   (`avm2_globals.c:2418-2446`) gives every native class an
   `(* = )` shell constructor. Flash emits **no** `<constructor>` element for
   a zero-parameter constructor, so we inject 3 spurious lines into every
   builtin `<factory>` in the corpus. Verified safe to invert: the only
   natives any passing test describes with a constructor are `int` (`(*=)`)
   and `flash.utils::Dictionary` (`(Boolean=)`), and both are already spelled
   out by name. `Object`/`Class` are already excluded.
2. **`length` is over-reported.** `register_class_object_lengths`
   (`avm2_globals.c:4655-4696`) installs a read-only static `length` on 26
   classes including `flash.errors::{IOError,EOFError,MemoryError,IllegalOperationError}`.
   `grep -rn 'name="length"' all_classes/*/*/output.txt` → **zero hits**;
   `describe_type_basic` shows it only on `Object`/`int`/`Class`.
   `avm2/static_length`'s expected output names **only top-level classes** — no
   `flash.*` — so the four packaged entries are safe to drop (or, zero-risk,
   skipped in `dt_collect_static_consts`).
3. **`Error.getStackTrace` is mis-namespaced.** `dt_native_as3_method`
   (`avm2_globals.c:2120-2126`) tags *every* method of a package-less native
   class as AS3. Ruffle's `Error.as` declares
   `public native function getStackTrace():String` — **public**. Because we tag
   it AS3, `HIDE_NSURI_METHODS` (superclass method-namespace skip) deletes it
   from all seven `flash.errors` subclasses, which is a missing line in every
   `errors/*` block. The Error hierarchy needs an exclusion.

### 1.5 A real hierarchy bug found in passing ★

`flash.errors::EOFError` is registered with `super = Error`
(`avm2_error.c:1623-1643`, the seven-name loop) but Flash and Ruffle both
declare `public dynamic class EOFError extends IOError`. Observable outside
describeType: `eofError is IOError` is `false` for us and `true` in Flash.
One-line fix (`IOError` is `made[0]`, created before `EOFError`).

### 1.6 Disposition check

None of the 22 still-live T7 tests appears in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, or `ruffle-tests/ignored_tests.txt`. The five
`all_classes/events/*` rows remain in `avm2/ignored_tests.txt:54-58` (upstream
`known_failure`) and are worth **zero** — unchanged from s13.

---

## 2. Verified status at HEAD

Baseline `results_graphics.json` (SHA `fb36ba110`) plus local re-runs. The s13
P0–P2 flips held: `describe_type_basic` 152/152 **pass**, `describe_type_json`
301/301 **pass**, `bug_539328` **ruffle_matched**.

| test | status | expected lines | note |
|---|---|---|---|
| `describe_type_metadata` | mismatch | 125 | **P3, +1** — only `<metadata>` missing (§1.1) |
| `describe_type_native` | mismatch | 23 | P4 pilot, one class |
| `all_classes/display3D/swf12` | mismatch | 61 | gate + ctor rule only |
| `all_classes/display3D/swf13` | mismatch | 326 | Context3D descriptor |
| `all_classes/display3D/swf30` | mismatch | 412 | + 5 gated classes |
| `all_classes/security/swf12` | mismatch | 19 | one missing class |
| `all_classes/security/swf13` | mismatch | 53 | three missing classes |
| `all_classes/security/swf30` | mismatch | 53 | identical file to swf13 |
| `all_classes/security/swf11` | **pass** | 3 | gate canary |
| `all_classes/errors/swf9` | mismatch | 121 | rules + Error descriptor |
| `all_classes/errors/swf10` | mismatch | 140 | + DRMManagerError gate |
| `all_classes/errors/swf30` | mismatch | 140 | identical file to swf10 |
| `all_classes/accessibility/swf9` | mismatch | 73 | real members missing |
| `all_classes/accessibility/swf10,swf30` | mismatch | 88 ea. | + 2 interfaces |
| `all_classes/xml/swf9,swf30` | mismatch | 116 ea. | 12 slots + 10 typed methods |
| `all_classes/display/swf{9,10,11,12,13,30}` | mismatch | 1959…2936 | the arc |

### 2.1 Row-count reconciliation with the board audit (25 vs 20)

| set | rows | graded? |
|---|---|---|
| `all_classes/display` | 6 | yes |
| `all_classes/events` | 5 | **no** — `avm2/ignored_tests.txt:54-58`, upstream `known_failure = true` |
| `all_classes/display3D` | 3 | yes |
| `all_classes/errors` | 3 | yes |
| `all_classes/accessibility` | 3 | yes |
| `all_classes/security` | 3 failing + `swf11` passing | yes |
| `all_classes/xml` | 2 | yes |
| **`all_classes` total** | **25 rows / 20 graded-and-failing** | |
| + `describe_type_metadata`, `describe_type_native` | 2 | yes |
| **T7 family total** | **27 rows / 22 graded-and-failing** | |

Both figures in circulation are correct against different denominators. The
board audit's 25 counts *rows*; my brief's 20 counts *rows that can move the
effective-pass number*. The gap is exactly `all_classes/events`, which is
upstream `known_failure` — per the `avm2-net-tranche2-socket-replay` lesson,
`known_failure` upstream means **Ruffle is not the oracle** there, so those five
are not merely "already ignored", they are unpriced until someone re-derives
their expectation from Flash. **This brief prices 20**; if the board wants the
27-row headline it should carry the 5 as a separate, explicitly-unpriced line.

### 2.2 P0 — the version-gate hole s13 opened ★★ (NEW, from the board audit)

| test | gap | expected / actual / matching |
|---|---|---|
| `avm2/all_classes/display3D/swf12` | 60 → **260** | 61 / **109 → 321** / 1 |

Before s13, `describeType` emitted a stub `<type>` per class, so the SWF-12 row
was merely wrong-and-short. P0–P2 made every class emit its full description,
and because we have **no API-version axis at all**, the 15 `flash.display3D`
classes Flash hides below their `[API(N)]` version are now dumped in full. CI's
pass→fail check cannot see this — the row was failing before and after
(`transition-diff-hides-new-crashes`).

This is not a regression in the sense of a wrong output becoming a crash; the
row is strictly further from correct and the s14 CI run will show it as such.
It is also **not a describeType bug**: the same missing axis over-produces here
and *under*-produces at `all_classes/security/swf12` (§1.3), where a class Flash
exposes at SWF 12 does not exist for us at all.

**Refutation of the audit's pricing.** The audit says "flips `display3D/swf12`
outright is optimistic (it also needs the 61-line accessible subset)". Measured
at HEAD with `--save-actual` and a per-class block diff, the accessible subset
is **already byte-exact**: `Context3DBlendFactor`, `Context3DClearMask` and
`Context3DCompareMode` reproduce all 22 of their `<constant>` lines with the
right `type=` (String/int, derived from the stored `Avm2Value` kind), the
`prototype` accessor, both `<extendsClass>` lines and the `<factory>` wrapper.
The *only* content delta in those three blocks is the spurious three-line
`<constructor><parameter index="1" type="*" optional="true"/></constructor>`
that §1.4-(1) removes. So **gate + native-ctor rule ⇒ the row flips**, and the
"not accessible" text is already proven byte-exact by
`all_classes/security/swf11`, which passes today by emitting exactly three
`X not accessible` lines through the same path.

**It is not a ~1-line change**, though. There is no class-availability table to
add a predicate to: `avm2_builtin_class` unconditionally calls
`builtin_global_define_ro` + `avm2_domain_add` (`avm2_globals.c:377-378`). The
mechanism is §4.1 — a sibling constructor that skips only those two calls —
plus 15 annotated registration sites in `avm2_stage3d.c`. Roughly 60 LOC.

**22 live graded tests remain** (25 in s13 − the 3 P0–P2 flips).

---

## 3. P3 — ABC trait metadata → `describe_type_metadata` (+1)

### 3.1 The exact spec (oracle-verified)

* JSON shape (`metadata.rs:80-103`): each entry is
  `{ name: <String>, value: [ { key: <String>, value: <String> }, … ] }` —
  note the item list lives under the key **`value`**, not `items`.
* Placement (`avmplus.rs`):
  * variables/constants — `get_metadata_for_slot`, array **always present**
    (possibly empty) when `INCLUDE_METADATA`;
  * methods — `get_metadata_for_disp`, same rule;
  * accessors — **union of the getter's and the setter's**, and the key is
    `null` unless the union is non-empty (`:365-386`);
  * type level — Ruffle stub, empty array. `describe_type_metadata` expects
    none, so keep the stub.
* XML (`avmplus.as:42-62`): `copyMetadata` appends
  `<metadata name="…"><arg key="…" value="…"/>…</metadata>` **after**
  `copyParams` and after the `@uri` attribute (`copyUriAndMetadata`). Our
  emitter already sets `@uri` last and appends `<parameter>` first, so
  appending metadata children at the end of each element is correct as-is.
* Key/value pool index 0 → empty string (`pool_string`, not `_or_err`);
  `[mda("abcd")]` is one item with `key=""`. Generated `abc0_strings[0]` is
  already `{ 0, "" }`, so `data->strings[idx]` needs no special case.
* Ordering inside a trait is ABC order; `normalizeXML` sorts the children, so
  `describe_type_metadata` cannot see it — keep ABC order anyway (Flash's).

The union rule is graded three ways by the test and all three are confirmed
against `Test.as`:
`Described.virtual` = getter's 2 + setter's 1 → 3;
`ExtendedDescribed.virtual` = its own getter's 3 + the **inherited** setter's 1
→ 4; `ExtendedDescribed.toBeOverriddenOnlySetter` = **only** the override's 3
(the shadowed base setter contributes nothing, because the union is over the
*resolved* vtable halves).

### 3.2 Edit sites, file:line

**Recompiler (parse side is already done — `abc_parser.cpp:401-430`, `:473-479`,
`:575-578` fill `AbcTrait::metadata` and `AbcFile::metadata`; `abc_emit.cpp`
contains zero occurrences of "metadata").**

1. `SWFModernRuntime/include/avm2/avm2_abc.h:62-70` — add
   ```c
   typedef struct { uint32_t key; uint32_t value; } Avm2AbcMetadataItem;   // string indices
   typedef struct { uint32_t name; uint32_t item_count;
                    const Avm2AbcMetadataItem* items; } Avm2AbcMetadata;
   ```
   and **append** `uint32_t metadata_count; const Avm2AbcMetadata* metadata;`
   to `Avm2AbcTrait`. Appending is safe: the generated arrays use positional
   initializers (`abc0_c1_it[] = { { 0, 29, 0, 27, 0, { 0, 0, 0 } }, … }`), and
   C zero-fills missing trailing members, so a stale `RecompiledABC` still
   compiles (it just reports no metadata).
2. `SWFRecomp/src/abc/abc_emit.cpp:965-979` — `emitTraitArray` is the **single**
   emission point for all four trait kinds (called at `:3602`, `:3603`, `:3690`,
   `:3781`). Give it a `const AbcFile&` parameter, emit one
   `static const Avm2AbcMetadataItem <sym>_md<i>_items[]` +
   `static const Avm2AbcMetadata <sym>_md<i>[]` pair per metadata-bearing
   trait *before* the trait array, then extend the positional initializer with
   `, <count>, <sym>_md<i>` (or `, 0, NULL`). All four call sites have `abc` in
   scope. **Do not touch `fold_traits` (`:833-862`)** — it is the intrinsic
   fingerprint and must stay metadata-blind, or every native-intrinsic match
   in `avm2-intrinsic-fingerprint-gate` breaks.
3. `SWFModernRuntime/include/avm2/avm2_class.h:44-73` — append to
   `Avm2PropEntry`: `const Avm2AbcMetadata* metadata; uint32_t metadata_count;
   const Avm2AbcMetadata* setter_metadata; uint32_t setter_metadata_count;`.
   No new file pointer is needed: the string pool is reachable via
   `e->type_file` for SLOT entries (set unconditionally at `avm2_class.c:627`)
   and `e->method.file` / `e->setter.file` for the accessor/method halves.
   The struct is built by `memset` + field assignment only (no positional
   initializers anywhere), so growing it is ABI-free — same precedent as
   `is_iface_alias` in s13.
4. `SWFModernRuntime/src/avm2/avm2_class.c:589-820` (`avm2_vtable_add_traits`) —
   copy `t->metadata`/`metadata_count` onto `e` in all three kind branches, and
   **also in the two accessor-merge early-`continue` paths**
   (`:735-755` getter-onto-setter → `existing->metadata`; `:759-771`
   setter-onto-getter → `existing->setter_metadata`). The override path at
   `:781-812` copies the whole entry, so an override's metadata correctly
   replaces the parent's, and the alias-fixup loop carries it along.
5. `SWFModernRuntime/src/avm2/avm2_globals.c`:
   * `:1896-1905` `DtMember` — add `DtMeta* metas; uint32_t meta_count;` plus
     new `DtMeta { char* name; DtMetaArg* args; uint32_t arg_count; }` and
     `DtMetaArg { char* key; char* value; }` scratch structs (same `malloc`
     discipline as `DtParam`);
   * `:1979-2013` `dt_params_free`/`dt_members_free`/`dt_desc_free` — free them;
   * `:2306-2390` `dt_collect_vtable` — fill from the entry in all three
     branches; for GETSET/GETTER/SETTER take the union of `metadata` and
     `setter_metadata`, getter first (Ruffle's order);
   * `:2597-2639` `dt_json_members` — replace the `want_md` stub at `:2624-2631`
     with real emission and the accessor "null unless non-empty" rule;
   * `:2700-2750` `dt_copy_traits` — append `<metadata>`/`<arg>` children after
     the existing `@uri`/`<parameter>` code in the variable, accessor and
     method loops.

### 3.3 Risk and cost

* **Blast radius: one test.** Confirmed by `--dump-abc` over all five
  describeType consumers (§0). `describe_type_json` stays byte-identical
  because `com.ruffle::RuffleTest` carries no metadata and our current
  array/`null` split already matches Ruffle exactly.
* **Generated-ABI reach:** every `RecompiledABC` regenerates. CI handles it;
  **locally, `--recompile` on the first run is mandatory** or you get the
  `stale-recompiledabc` false COMPILE_FAIL. A recompiler change also means a
  manual `cmake` build of `SWFRecomp` before any local verify.
* **Size:** the metadata pool is empty for essentially the whole corpus (0 of
  the 4 non-metadata describeType tests; 15 traits in the one that has it).
  Flex-built SWFs will grow a few KB of static tables. Low.
* **Cost:** ~120 LOC recompiler + ~140 LOC runtime. **Confidence HIGH.**

---

## 4. P4 — verified sub-slice counts and a re-ordered cost model

The s13 counts are right: **+3** (`display3D`), **+11** (`security` 3 +
`accessibility` 3 + `errors` 3 + `xml` 2), **+6** (`display`). The cost
ordering is not. Measured, cheapest first:

| slice | tests | lines | what it actually needs |
|---|---|---|---|
| **A. describeType rules** | 0 | — | native-ctor default, `length` policy, Error-AS3 exclusion (§1.4). Prerequisite for every row below. |
| **B. API-version gate (= the §2.2 P0)** | +1 | 61 | `display3D/swf12`. A `min_swf` on 20 builtin registrations. Also unblocks C and the `swf10/swf30` half of D. |
| **C. `flash.security`** | +3 | 125 | 3 new stub classes, 9 constants + 19 readonly accessors + 1 method, all describeType-only. |
| **D. `flash.errors`** | +3 | 401 | A→ + `Error` descriptor (`errorID:int`, ctor `(String=,int=)`, `getStackTrace:String`), `DRMManagerError` descriptor + gate, `EOFError extends IOError`. |
| **E. `flash.events::Event`** | +1 | 23 | 14 member types, 3 ctor params, one describe-only sealed bit. |
| **F. `xml`** | +2 | 232 | 12 real `public var` slots on `XMLNode`, 10 typed methods, `XMLDocument::toString` override. Member work. |
| **G. `accessibility`** | +3 | 249 | 14 methods + 2 vars on `AccessibilityImplementation`, 2 statics on `Accessibility`, 8 vars on `AccessibilityProperties`, 2 gated interfaces. Member work. |
| **H. `display3D` 13/30** | +2 | 738 | ~70 typed members + 207 parameters. |
| **I. `display`** | +6 | 15,321 | 65 classes, 1,257 typed members. **Arc.** |

### 4.1 The API-version mechanism (B, and the gate half of C/D/G)

Ruffle annotates playerglobal classes `[API("N")]` and maps `N - 660` onto
`ApiVersion` (`api_version.rs`). Confirmed against every expected file:

| annotation | ordinal | gate | classes |
|---|---|---|---|
| `[API("667")]` | 7 = `FP_10_1` | SWF ≥ 10 | `flash.errors::DRMManagerError`, `flash.accessibility::{ISearchableText,ISimpleTextSelection}` |
| `[API("672")]` | 12 = `SWF_12` | SWF ≥ 12 | `flash.security::CertificateStatus` |
| `[API("674")]` | 14 = `SWF_13` | SWF ≥ 13 | `flash.security::{X500DistinguishedName,X509Certificate}`, `Context3D`, `Context3DProgramType`, `Context3DRenderMode`, `Context3DStencilAction`, `Context3DTextureFormat`, `Context3DTriangleFace`, `Context3DVertexBufferFormat`, `IndexBuffer3D`, `Program3D`, `VertexBuffer3D` |
| `[API("682")]` | 22 = `SWF_17` | SWF ≥ 17 | `Context3DProfile` |
| `[API("686")]` | 26 = `SWF_19` | SWF ≥ 19 | `Context3DMipFilter`, `Context3DTextureFilter`, `Context3DWrapMode` |
| `[API("692")]` | 32 = `SWF_22` | SWF ≥ 22 | `Context3DBufferUsage` |

`display3D/swf12` expects exactly the 3 **unannotated** classes
(`Context3DBlendFactor`, `Context3DClearMask`, `Context3DCompareMode`) — an
exact match for this table.

**Implementation:** a new
`Avm2Class* avm2_builtin_class_api(ctx, ns, name, super, uint8_t min_swf)`
next to `avm2_builtin_class` (`avm2_globals.c:330-382`) that builds the class
identically but **skips only the two exposure calls** (`builtin_global_define_ro`
at `:377` and `avm2_domain_add` at `:378`) when `ctx->swf_version < min_swf`.
The class must still exist — `Stage3D.requestContext3D` mints a `Context3D`
internally regardless of SWF version. This is exactly the shape of the
existing `air_hidden_lookup` / `air_ifilepromise` pair
(`avm2_globals.c:3595-3604`) and of the `swf_version >= 13` JSON gate
(`:4832-4836`), so the idiom is already blessed. Call sites: the constant-bag
loop and class registrations in `avm2_stage3d.c:2218-2430` (15), `avm2_error.c`
DRMManagerError (1), the new `flash.security` module (3), accessibility
interfaces (2).

### 4.2 `describe_type_native` — the exact remaining delta

One class. `isDynamic` false; six accessors (`bubbles` `Boolean`, `cancelable`
`Boolean`, `currentTarget` `Object`, `eventPhase` `uint`, `target` `Object`,
`type` `String`); constructor `(String, Boolean=, Boolean=)`; eight methods
(`clone`→`flash.events::Event`, `formatToString`→`String` with one
non-optional `String` parameter, `isDefaultPrevented`→`Boolean`,
`preventDefault`/`stopImmediatePropagation`/`stopPropagation`→`void`,
`toString`→`String`). The member *set*, ordering, `access` and `declaredBy` are
already exactly right — s13 P0–P2 got all of that.

`isDynamic` is the only place a class flag is needed, and it is needed **only
here**: every `all_classes` row describes *Class* values, whose static side is
unconditionally `isDynamic="true" isFinal="true"`, and whose `<factory>` element
carries no `isDynamic` attribute at all. So put a describe-only `is_dynamic`
byte in the descriptor and **do not touch `AVM2_CLASS_FLAG_SEALED`** (enforced
at `avm2_ops.c:211`) — the s13 warning stands.

### 4.3 Descriptor shape (new file recommended)

```c
typedef struct { const char* type; uint8_t optional; } Avm2DescParam;
typedef struct { const char* name; uint8_t kind;      // method/getter/setter/slot
                 const char* type;                    // returnType | accessor type
                 uint8_t param_count; const Avm2DescParam* params; } Avm2DescMember;
typedef struct { const char* ns; const char* name;
                 uint8_t describe_dynamic;            // 0 = report isDynamic="false"
                 uint8_t ctor_param_count; const Avm2DescParam* ctor_params;
                 const Avm2DescMember* members; } Avm2DescClass;   // NULL-name terminated
```

Consumed at four points that already exist and today fall through to `"*"`:
`dt_collect_vtable`'s three `dt_sdup("*")` fallbacks (`:2355`, `:2377`,
`:2386`), `dt_collect_ctor` (`:2418-2446`), and the `is_dynamic` computation in
`dt_describe` (`:2503-2510`). Lookup key is `(defining_class ns, name)` + member
name, so inherited members resolve against the class that declared them
(`errorID` must report `declaredBy="Error"` on every `flash.errors` subclass).

**Put the tables in a NEW file** `SWFModernRuntime/src/avm2/avm2_describe_desc.c`
(+ a small header). Keeping ~500 lines of hand-written tables out of the
already 5,000-line `avm2_globals.c` is what makes this arc survivable across
sessions, and it shrinks the merge surface for every future wave.

The eventual generator (Ruffle's 470 `.as` files → these tables) is still the
right endgame for slices F–I; the pilot should hand-write A–E so that the
generator has a known-good target to reproduce.

---

## 5. Files a wave-2 implementer would edit (sibling conflict map)

**P3:**
* `SWFRecomp/src/abc/abc_emit.cpp` — `emitTraitArray` (`:965-984`) only
* `SWFModernRuntime/include/avm2/avm2_abc.h` — `Avm2AbcTrait` (`:62-70`)
* `SWFModernRuntime/include/avm2/avm2_class.h` — `Avm2PropEntry` (`:44-73`)
* `SWFModernRuntime/src/avm2/avm2_class.c` — `avm2_vtable_add_traits` (`:589-820`)
* `SWFModernRuntime/src/avm2/avm2_globals.c` — the `dt_*` region (`:1890-2790`)

**P4 pilot (adds):**
* `SWFModernRuntime/src/avm2/avm2_describe_desc.c` + `include/avm2/avm2_describe_desc.h` — **new**
* `SWFModernRuntime/src/avm2/avm2_security.c` + registration hook — **new** (3 stub classes)
* `SWFModernRuntime/src/avm2/avm2_globals.c` — `avm2_builtin_class_api` (near `:330`),
  `register_class_object_lengths` (`:4655`), `avm2_globals_init` registration list (`:4700+`)
* `SWFModernRuntime/src/avm2/avm2_error.c` — `:1622-1660` (EOFError super, DRMManagerError gate)
* `SWFModernRuntime/src/avm2/avm2_stage3d.c` — `:2135-2430` (API annotations)
* `SWFModernRuntime/CMakeLists.txt` — two new source files

**Conflict warning for the coordinator:** `avm2_globals.c` is the single
highest-traffic AVM2 file. P3 and the P4 pilot both rewrite `DtMember`,
`dt_collect_vtable`, `dt_json_members` and `dt_copy_traits`. **Assign both to
one agent.** No other s14 sibling should be given `avm2_globals.c`,
`avm2_class.{c,h}`, `avm2_abc.h`, `avm2_error.c`, `avm2_stage3d.c`, or
`abc_emit.cpp`.

---

## 6. Recommendation

### P3 — **GO.** One commit, +1, HIGH confidence.
Blast radius mechanically proven to be one test. The only procedural cost is
the generated-ABI regeneration (`categories=full`, `--recompile` locally).

### P0 version gate — **GO, and take it first.**
It is a prerequisite for `display3D/swf12`, for all three `security` rows and
for `errors/{swf10,swf30}`, it closes a hole s13 opened, and it is the only
item here that gets *worse* if deferred (every future descriptor improvement
lengthens the over-produced SWF-12 dump further).

### P4 pilot — **GO, re-scoped from "one class" to "+8".**
Take it as one agent, in this commit order, so an early stop still banks value:

| commit | content | flips |
|---|---|---|
| 1 | **Rules A**: native-ctor default, `length` policy, Error-AS3 exclusion | 0 (prerequisite; improves every `all_classes` row) |
| 2 | **P0 gate**: `avm2_builtin_class_api` + `display3D` annotations — closes the §2.2 hole | +1 `display3D/swf12` |
| 3 | **P3** (ABC trait metadata; recompiler + runtime) | +1 `describe_type_metadata` |
| 4 | Descriptor infra (new file) + `Event` descriptor + describe-only dynamic bit | +1 `describe_type_native` |
| 5 | `Error`/`DRMManagerError` descriptors + `EOFError extends IOError` + DRM gate | +3 `errors/{swf9,swf10,swf30}` |
| 6 | `flash.security` ×3 + gates | +3 `security/{swf12,swf13,swf30}` |

**Predicted total: +9 trace** (P3 +1, P0/P4 pilot +8). Commits 1–4 are the
mandatory core (+3, and they close the s13 hole); 5–6 are the stretch (+6) and
are independent of each other. Confidence: HIGH for 1–4 and 6, MEDIUM for 5
(the `EOFError` super change and the `getStackTrace` namespace change both reach
outside describeType). Commit 2's only real risk is that hiding a *name* must
not hide the *class*: `Stage3D.requestContext3D` mints a `Context3D` internally
at every SWF version, so the gate must skip only `builtin_global_define_ro` +
`avm2_domain_add`, never the construction — pin it with `avm2/stage3d_errors`.

**Ordering rationale:** commits 1–2 are placed first because §2.2 is a latent
worsening that the s14 CI run will surface. Commit 2 depends on commit 1 (the
native-constructor rule is the last remaining delta in `display3D/swf12`'s three
accessible classes), so they cannot be reordered.

### Do NOT open this session
`xml` (+2), `accessibility` (+3), `display3D/swf13,swf30` (+2) and `display`
(+6). Those need real member registration or ~1,300 typed members. Book them as
**`T10-playerglobal-descriptor`**, an arc, with the `.as`→table generator as its
first deliverable — now with a hand-written reference implementation (this
pilot's tables) to validate the generator against.

### Board correction for `polish-sweep-arc.md` §14.3
> T7 P3 (recompiler ABC metadata → `describe_type_metadata`, +1) and P4
> playerglobal descriptor slices (+3/+11/+6, arc-sized; `describe_type_native`
> is the clean pilot)

should become

> T7 **P0 version gate** (closes the hole s13's P0-P2 opened at
> `all_classes/display3D/swf12`, 109→321 actual lines, invisible to the
> pass→fail check), **P3** (+1, blast radius 1 test) and a **re-sliced P4**:
> a +8 pilot (describeType rule fixes + descriptor infra + `Event`/`Error`
> descriptors + API-version gate + `flash.security`), with
> `xml`/`accessibility`/`display3D` 13-30/`display` (13 tests, 16,540 lines)
> spun out as `T10-playerglobal-descriptor`. Family size is **27 rows / 22
> graded** — the 5 `all_classes/events` rows are upstream `known_failure` and
> unpriced.

---

## 7. Canary list

All pass at the baseline SHA; all must stay green.

**describeType / E4X consumers (the complete corpus list — enumerated from
`grep -rl describeType --include=*.as` plus a scan of every
`RecompiledABC/*.c` for source-less SWFs):**
`avm2/describe_type_basic`, `avm2/describe_type_json`,
`avm2/function_proto_created`, `from_avmplus/regress/bug_539328`
(`ruffle_matched` — a move to plain `pass`/`fail` is a **regression signal**,
per `ruffle-matched-hides-regression`), `avm2/all_classes/security/swf11`
(the gate-from-below canary), `avm2/number_autoconv` (pins `int`'s
`HIDE_NSURI_METHODS` suppression), `avm2/null_void_types`,
`avm2/displayobject_name_from_timeline`, `avm2/font_enumeratefonts`,
`avm2/catch_scope_slot`, `avm2/supercall_two_classobjects`,
`avm2/vector_object_final`.

**Rule-change canaries:** `avm2/static_length` (the `length` policy),
`avm2/property_is_enumerable`,
`from_avmplus/ecma3/ObjectObjects/hasOwnProperty`,
`from_avmplus/ecma3/ObjectObjects/propertyIsEnumerable`.

**Error-slice canaries (commit 4):** `avm2/error_stack_trace`,
`avm2/error_stack_trace_edge_cases`, `avm2/error_tostring`,
`avm2/error_tostring_more`, `avm2/error_prototype`, `avm2/error_throwerror`,
`avm2/bytearray_errors`, `avm2/bytearray` (EOFError-vs-IOError `is` checks),
`avm2/json_errors`.

**API-gate canaries (commit 5):** `avm2/json_version_gated`,
`avm2/cross_api_version_call_older`, `avm2/cross_api_version_call_newer`,
`avm2/air_hidden_lookup`, `avm2/stage3d_errors`, `avm2/stage3d_errors_swf_29`,
`avm2/abstract_classes`.

**Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`) — the
whole AVM2 half is a canary for P3's generated-ABI change; at minimum:**
`avm2_typed_value_ops`, `avm2_slot_default_template`,
`avm2_static_and_store_slots`, `avm2_tolerant_verify_quarantine`,
`avm2_findprop_this_resolution`, `avm2_embed_bytearray`, `avm2_agi_shell`,
`avm2_gc_dynprop_tombstone_purge`.
*(No regression-suite test references `describeType` — verified by
`grep -rl describeType --include=*.as ruffle-tests/tests/swfs/regression`. If
the pilot lands, a `regression/avm2_describetype_descriptor` test pinning the
native-constructor and `length` rules would be a cheap, durable guard.)*

**CI dispatch:** `mode=graphics`, `categories=full` (AVM2 runtime **and**
recompiler emission). Expect a longer run — every `RecompiledABC` regenerates.
`images=false`; no render code is touched, so there is no pixel-axis effect.

---

## 8. Local-verification notes for the implementer

* `verify_output.py`'s `matching_lines` is a **positional** compare; one
  missing element makes a structurally-correct output look 4 % correct. Grade
  with `--save-actual` and a block diff (§1.1), not the runner's number.
* A recompiler change needs a manual `cmake --build SWFRecomp/build` **and**
  `--recompile` on the first run of every test, or you get
  `undefined reference` / COMPILE_FAIL noise that is not real
  (`stale-recompiledabc`).
* Useful one-liner for auditing metadata reach:
  `./SWFRecomp/build/SWFRecomp --dump-abc <swf> | grep -c '\[metadata:'`.
* `all_classes` tests have no `Test.as` (upstream binary SWFs); read
  `output.txt` and Ruffle's `globals/flash/**/*.as` as the paired oracle.
