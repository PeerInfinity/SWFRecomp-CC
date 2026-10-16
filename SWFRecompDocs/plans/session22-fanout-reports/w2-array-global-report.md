# s22 wave-2 — w2-array-global: array creation resolves `_global.Array` + `hasOwnProperty.call(array, …)` crash

**New files:** none (source edits only, in 3 existing files). Deliverables: this report and
`w2-array-global.patch` (= `git diff origin/master -- SWFModernRuntime`; no recompiler,
`verify_output.py` or canary-list change).

Branch `fanout/w2-array-global`, base `origin/master` `b492a86e4`. Box: cloud, `SETUP_STATUS`
all OK (apt, Pillow, Dawn). Corpus: `download_tests.sh avm1 from_gnash` (+ `visual avm2
from_shumway fonts text` for the render canary) from upstream Ruffle master at session time; a
blobless clone made minutes earlier sits at **`45366370e`**, the coordinator's sync point.

## Verdict: GO — 4 effective flips, 0 regressions (trace), render canary 102/102 md5-identical

| test | axis | clean origin/master | with patch | |
|---|---|---|---|---|
| avm1/array_constructor | trace | **SEGFAULT** (30/53) | **PASS** 53/53 | flip |
| from_gnash/actionscript.all/array-v6 | trace | MISMATCH (15 diff lines) | **RUFFLE_MATCHED** | flip (drift re-flip) |
| from_gnash/actionscript.all/array-v7 | trace | MISMATCH (14) | **RUFFLE_MATCHED** | flip (drift re-flip) |
| from_gnash/actionscript.all/array-v8 | trace | MISMATCH (14) | **RUFFLE_MATCHED** | flip (drift re-flip) |
| avm1/globals_monkeypatch | trace | MISMATCH 205 diff lines | MISMATCH 203 | `[]` and `split()` rows now match Flash; no status move |
| avm1/as_broadcaster | trace | MISMATCH 199 | MISMATCH 199 (identical) | see §4: needs a 1-line hook in w2-as-core's region |

Same box, same corpus, `--mode=graphics` (CI's mode) for every row; the no-graphics run of the
headline set gives the identical status table (§3). array-v6..v8 are `known_failure = true` with
`.fp24.ruffle.txt`; `ruffle_matched` is their ceiling and it is where they were before upstream
`dd4e73d59` rewrote the Ruffle files. (They are not Flash-correct passes being traded away: they
were MISMATCH before this patch.)

### EXPECTED-FLIP LEDGER (coordinator: check CI against this)

Trace axis (graphics and no-graphics both):
- `avm1/array_constructor`: SEGFAULT → **pass**
- `from_gnash/actionscript.all/array-v6`: fail → **ruffle_matched**
- `from_gnash/actionscript.all/array-v7`: fail → **ruffle_matched**
- `from_gnash/actionscript.all/array-v8`: fail → **ruffle_matched**
- no status change, line content only: `avm1/globals_monkeypatch` (205 → 203 diff lines).

Pixel axis: **no expected movement.** The change is AVM1 object semantics only. Render canary
result: 102/102 PNGs md5-identical, no trace or image status changes.

Anything else moving on CI is not expected from this patch.

## 1. Mechanism and patch scope

Upstream `dd4e73d59` (`ArrayBuilder::new`): every array a script creates without `new Array()`
gets, AT CREATION, own `__proto__ = _global.Array.prototype` and own `constructor =
_global.Array` (both DONT_ENUM|DONT_DELETE), read as **data** (`get_data`: attributes ignored,
getters not called, and the data slot survives an `addProperty` on the same name). No class →
neither slot; class without prototype → `constructor` only (the FP24 branch; FP 9-17 would drop
it, and `.fp24` is what we grade).

All edits are in `SWFModernRuntime/src/actionmodern/action.c` unless noted:

- **`include/actionmodern/object.h` + `object.c`**: two TRAILING `ASArray` fields,
  `virt_ctor` (`struct ASFunction*`) and `no_proto_fallback` (u8), zeroed in `allocArray`.
- **`arrayResolveGlobalCtor()`** (new static, placed just above `actionInitArray`):
  - reads `_global.Array` with `findPropertyRaw` on `getActiveGlobal()` (data slot, version
    group aware). The engine registers `_global.Array` as `g_ctors[1]` while scripts observe
    `g_array_constructor_static` (`Array`, `Array.prototype.constructor`); the helper maps the
    former to the latter (new static `g_array_ctor_registered`, set next to the `REG_FUNC`).
  - **fast path** (the hot one): `_global.Array` is a function whose `prototype_obj` is the proto
    the creation site already installed → set `arr->virt_ctor` and return. **No allocation, no
    props insert.** Before `ensureGlobalInit` has run (it is lazy; any `_global` access runs it)
    the class is necessarily the builtin, so that case takes the fast path too.
  - **slow path** (script replaced `_global.Array`): writes `__proto__` (or deletes it) and
    `constructor` into `props`, and sets `no_proto_fallback` so member reads stop falling back
    to the builtin Array.prototype.
- **Virtual own `constructor`** (`virt_ctor`), honoured in: `actionGetMember` array arm (read),
  `actionSetMember` array arm (materialise into props with DONT_ENUM|DONT_DELETE, then the normal
  write), `actionDelete` array arm (returns false), `callArrayMethod` `hasOwnProperty` (true).
  for-in never sees it (correct: DONT_ENUM).
- **Creation sites wired**: `actionInitArray` (literals), `setupArgumentsProps` (`arguments`, so
  both the runtime path and the recompiler's `swf_setup_arguments_props`), the three `split`
  result pushes in `callStringPrimitiveMethod`, `Array(...)` called by name, **`Array` called
  through an alias** (`var f = Array; f()`: it used to return `undefined`, a pre-existing bug the
  test exposes; now the "built-in constructor as plain function" arm dispatches it), and
  `Array.call(...)`. The by-name and alias arms share a new `pushArrayCalledAsFunction()`
  (the old by-name body, moved). `new Array()` is untouched (keeps the inherited constructor).
- **Crash fix (M3b)**, ported as-is from `w1-drift-avm1-prototype.patch` hunks 1-2:
  `builtin_object_hasOwnProperty` routes an ASArray receiver to `callArrayMethod`'s
  `hasOwnProperty` arm instead of mis-casting it to `ASObject*`.

Self-localisation vs `SIBLING_FILE_MAP.md`: all regions are this slot's; nothing touches
w2-as-core's AsBroadcaster/ContextMenu/AsSetupError/`actionCallMethod` object-method arm/
`objectToPrimitive` regions. The only shared-looking hunk is the `REG_FUNC("Array")` +1 line in
`ensureGlobalInit`.

## 2. Perf (hard requirement)

Tight loop, hand-built SWF8 (`r1 = 0; do { r2 = [r1, 1, 2]; r1++ } while (r1 < 1e6)`), native
no-graphics build kept with `SWF_KEEP_BUILD_DIR`, same box:

| | instructions (callgrind, whole run) | wall (3 runs) |
|---|---|---|
| clean origin/master | 2,901,540,584 | 0.616 / 0.616 / 0.569 s |
| with patch | 2,950,611,517 (**+49.1 M = +49 instr/literal, +1.7 %**) | 0.600 / 0.612 / 0.583 s |

`arrayResolveGlobalCtor` is 41 instr/literal inclusive (one hashed lookup of `Array` on the
global). Zero new allocations per literal.

**Premise refuted (useful for a later slot):** the brief's "do not allocate a props table per
literal" was already violated by origin/master itself: `actionInitArray` allocates `props`
(`allocObject`, ~478 instr) and inserts `__proto__` (`setPropertyWithFlags`, ~923 instr) for
EVERY literal: ~1400 of the ~2200 instr per literal. See New leads.

## 3. Canaries and regression suite

Graphics, before vs after, 45 tests (all `avm1/array*` (15), `avm1/arguments`, `as_broadcaster`,
the three tests `dd4e73d59` rewrote (`global_proto_decls`, `global_proto_decls_delete`,
`globals_monkeypatch`), `coerce_to_object_monkeypatch`, `function_suppress_and_preload`,
`funky_function_calls`, `string_methods*` (3), `enumerate`, `instanceof_coercions`; gnash
`array-v5..v8`, `Function-v5..v8` (also rewritten by `dd4e73d59`), `String-v6/-v8`,
`Inheritance-v6`, `ASnative-v6`; regression `array_element_type1_args`,
`array_method_type1_args`, `fn_call_builtin_type1_args`, `string_prim_method_type1_args`,
`sort_comparator_type1_args`):

- Status moves: exactly the 4 ledger flips.
- Diff content compared line by line for every row (not just status): only `array_constructor`,
  `array-v6/7/8` and `globals_monkeypatch` (205→203, both moved lines now equal Flash) changed.
  `global_proto_decls` (3694), `global_proto_decls_delete` (3697) and `as_broadcaster` (199)
  are byte-identical in their diffs.
- `avm1/arguments` regressed in an intermediate build (globals not yet initialised → slow path
  → `arguments instanceof Array` false); fixed by the lazy-global fast path above and re-verified
  PASS in both modes.
- No-graphics (mode parity; shared runtime), before → after: array_constructor SEGFAULT→PASS,
  array-v6/7/8 MISMATCH→RUFFLE_MATCHED, arguments PASS=PASS, array-v5 RUFFLE_MATCHED (both),
  as_broadcaster and globals_monkeypatch MISMATCH (both). Identical to graphics.
- `regression/` suite: the 5 array/arguments/call fixtures above PASS before and after. No new
  fixture: `avm1/array_constructor` is a Flash-oracle test that pins every new behaviour
  (literal, arguments, `Array()`, split, `new Array()`, replaced/primitive/missing/getter
  `_global.Array`, local `Array` shadowing, delete/assign of the own `constructor`).

Render canary (`render_canary.py`, standing `render_canary_tests.txt`, graphics, A/B md5):
60 tests / 102 comparisons: **IDENTICAL 102, DIFFERS 0**, appeared/vanished/no-render 0, no
trace or image status changes. The standing set already contains AVM1 tests that build arrays
(filters arrays, `bitmap_data_*`), so no member was added.

## 4. `avm1/as_broadcaster` "with Array replaced" — for w2-as-core

The line stays `false` here because native `installAsBroadcaster` (`action.c` ~39262, w2-as-core's
region) builds `_listeners` with a bare `allocArray`. Proven on this box (then reverted): adding

```c
    ASArray* listeners = allocArray(app_context, 4);
    arrayResolveGlobalCtor(app_context, listeners, g_array_prototype, PROPERTY_FLAGS_DONTENUM);
```

turns the row into `true` (`broadcaster._listeners.__proto__ === tracingArray.prototype`), with
no other change in the test's 199-line diff. If w2-as-core instead ports `AsBroadcaster.initialize`
to AS semantics and creates `_listeners` as a literal, it gets this for free from
`actionInitArray`. `arrayResolveGlobalCtor` is forward-declared above `setupArgumentsProps`, so it
is callable from that region. Whichever lands second must make sure the `_listeners` array goes
through it.

## 5. Refutations / premise checks

- "Don't allocate a props table per literal": origin/master already does (§2). The patch adds
  none; the virtual-`constructor` design was kept as asked.
- `Array === _global.Array` is **false** in our runtime today (two ASFunctions,
  `g_array_constructor_static` vs `g_ctors[1]`). Not fixed here (wide blast radius); the helper
  reports the script-visible one so `[].constructor === Array` stays true.
- `originalArray()` (native Array through an alias) returned `undefined` before: fixed in scope,
  because `array_constructor` needs it.

## 6. Not done / follow-ups (each with its completion mechanism)

- **Other native array producers** (`slice`, `concat`, `splice`, `sort(RETURNINDEXEDARRAY)`,
  filter `.matrix` getters, `TextField.getTextFormat` lists, …) also use `ArrayBuilder::new`
  upstream. Not wired (outside the brief's four sites; no headline needs them).
  `globals_monkeypatch` rows 46-50 (`AN_ARRAY.slice()`, `A_COLOR_MATRIX_FILTER.matrix`,
  `A_CONVOLUTION_FILTER.matrix` → `MyArray`) are exactly these. Mechanism: call
  `pushCreatedArray()` / `arrayResolveGlobalCtor()` at each site; the fast path keeps it cheap.
  The test stays MISMATCH regardless (203 lines; it is `known_failure`).
- `globals_monkeypatch` row 42 (`ARRAY()` through a class static, i.e. a CallMethod on a native
  Array function) still yields `undefined`: the `actionCallMethod` object-method arm (w2-as-core
  owns that arm in s22) lacks the alias dispatch added here to `actionCallFunction`.
  Mechanism: route a `simple_func == NULL` function named `Array` to
  `pushArrayCalledAsFunction()` there, after w2-as-core lands.

## New unclaimed leads

1. **Array-literal cost, ~60 % removable.** Per literal, origin/master spends ~478 instr in
   `allocObject` for `props` plus ~923 in `setPropertyWithFlags("__proto__")`, out of ~2200.
   With `virt_ctor` in place the same trick works for `__proto__`: leave `props == NULL` on the
   fast path (the getMember fallback already resolves the builtin Array.prototype). Blockers to
   audit first: `props->native_type = NATIVE_ARRAY` readers, and the index-hole branch of the
   array getMember arm, which only crawls the prototype when `props != NULL`
   (`Array.prototype[3] = x; sparse[3]`). Needs games in the perf harness, not just tests.
2. **`Array !== _global.Array`** (two ctor objects). Any test comparing them, or replacing one
   and reading the other, diverges. Unify on one ASFunction.
3. `Array()` called **by name** at 63916 bypasses scope resolution, so a script-replaced
   `_global.Array` called as `Array()` still runs the native one (Flash calls the replacement).

## LOCAL ORACLE REQUESTS

none
