# avm2 Suite — Current Status

Last updated: 2026-07-11 — Stage 3 (tranche-1 pure-language tests) landed.

**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **Stage 3 local result: 152 / 166 tranche-1 candidates passing**
  (`_investigation/TRANCHE1_CANDIDATES.txt`, the name-pattern superset of
  the plan's ~90-test tranche 1 — the ≥80-of-~90 exit criterion is met with
  room to spare). Awaiting the full-suite CI baseline; Stage 2's was 8/1198.
- **Static op-surface ceiling: 1069 / 1162 censused tests** (was 61) with
  the Stage-3 op surface of 122 IR ops
  (`python3 SWFRecomp/tools/abc_op_census.py --implemented-file <ops>`).
  Remaining blocking ops: ApplyType (80 tests — Vector, tranche 2),
  PushNamespace (6), GetDescendants (4, E4X), CheckFilter (3), the alchemy
  load/store ops (1).
- **What exists now (Stage 3, 2026-07-11):**
  - **Emitter** (`SWFRecomp/src/abc/abc_emit.cpp`): full-body emission —
    `op_N:` labels for every branch/switch/exception target, gotos for
    Jump/IfTrue/IfFalse/LookupSwitch, inline (noreturn) aborts for
    unsupported ops with NO truncation. Bodies with active exception tables
    push an `Avm2TryFrame` (setjmp) whose handler dispatches to the catch
    target with the thrown value as the sole stack entry; `sp`/`scope_n`
    are volatile in such bodies. Emits int/uint/double pools, method
    signatures (flags, param types, optional defaults, return type,
    activation traits, `is_function`), class interfaces + protected ns,
    trait default values, and the SWF version
    (`avm2_generated_swf_version` — sort/parse quirks are version-gated).
    Class/script initializer bodies are marked "interpreter mode" (avmplus
    runs them interpreted; the index fast path then ignores the ns set —
    class_init_interpreter_mode, array_access_interpreter).
  - **Runtime** (`SWFModernRuntime/src/avm2/`, now 11 files): full coercion
    matrix + abstract eq/lt + ECMA Add split; Number→string via shortest
    round-trip decimal + Ruffle's MAX_PRECISION exponential arm;
    string_to_f64/int ports (incl. the >15-digit and powi rounding quirks);
    property engine with getters/setters (GETSET merge), prototype chains,
    bound-method caching (obj.m === obj.m), interface-ns aliases,
    protected-ns aliases with override sync, slot metadata tables
    (shadowed parent slots keep their own defaults — supercalls), typed
    slot coercion, sealed/dynamic miss semantics (1069 vs 1081/1056,
    strict "public" = empty-URI Namespace/Package); functions/closures
    (NewFunction, NewActivation, arguments/rest, optional defaults,
    unchecked functions, 1063 with FP display names, call/apply,
    fn.prototype incl. explicit-null state); typed exceptions
    (setjmp/longjmp try frames, is_of_type catch matching, catch-scope
    objects with a synthetic sealed class named after the variable,
    uncaught errors abort only the current top-level entry); debug call
    stack + Error.getStackTrace (construction-time snapshot, FP frame
    names); builtins: Object/Class/Function, String (UTF-16-aware
    length/charAt/charCodeAt/index math over UTF-8 storage, Flash-table
    case mapping, split/slice/substr/substring/indexOf/lastIndexOf/
    localeCompare/fromCharCode incl. surrogate pairs), Number/int/uint/
    Boolean (toString radix, toFixed/toPrecision/toExponential in Rust
    digit-string style), Array (dense+sparse storage, holes resolving
    through the prototype, avmplus qsort port with SWF-version compare
    quirks, sortOn, splice/slice/indexOf/removeAt/insertAt/...), Math
    (avmplus RNG seeded from MOCK_DATE_TIME), Error family (exact FP
    message strings), toplevel (trace/isNaN/isFinite/parseInt/parseFloat/
    escape/unescape/getQualifiedClassName/getDefinitionByName in both
    flash.utils and avmplus namespaces), stubs for XML/XMLList/Date/
    flash.geom.Point.
  - **Harness**: `verify_output.py` gained Ruffle-framework approximations
    semantics — numeric compare is enabled by the presence of an
    `[approximations]` section (epsilon 0 = exact double equality) and
    `max_relative` is honored. Tests with no section keep exact string
    compare, so AVM1 suites can only gain from this.
- **Remaining tranche-1 misses (14, all triaged):**
  - RegExp (tranche 2): string_match, string_replace, string_search,
    string_split, function_unbound_this (also needs dispatchEvent).
  - Vector/ApplyType (tranche 2): try_catch, class_call (also ByteArray),
    array_vector_null_callback.
  - describeType / E4X XML output (deferred): number_autoconv,
    function_proto_created.
  - ByteArray/AMF (tranche 3): number_autoconv_amf.
  - Display/graphics (Stage 5): nan_scale.
  - Upstream `ignore = true`: number_tostring (added to
    ignored_tests.txt along with bytearray_oom in the Stage-3 audit).
- **ABC front-end (Stage 1)** and **Stage-2 wiring** unchanged — see git
  history of this file for the Stage-1/2 tables.
- Run one test: `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Do NOT run the full
  suite locally (project rule) — full suite via CI.

## Tranche targets (from the 2026-07-10 corpus survey)

1. **Tranche 1 (~90):** pure language — DONE 2026-07-11 (see above).
2. **Tranche 2 (~50):** Vector, JSON, RegExp, object/proto edge cases.
   Vector (ApplyType) is the single biggest unlock: 80 censused tests.
3. **Tranche 3 (~60):** Namespace/QName/Proxy/Dictionary, ByteArray, AMF.
4. **Deferred:** XML/E4X (~51 + describeType), frame-lifecycle tests
   (Stage 5), graphics.
