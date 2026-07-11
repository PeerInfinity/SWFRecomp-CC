# Session prompt — AVM2 Stage 4: tranche 2 (Vector, RegExp, JSON, proto edge cases)

You are implementing **Stage 4** of `SWFRecompDocs/plans/avm2-support-plan.md`
(§5 "tranches 2+3"; this session covers tranche 2). Read that plan first
(§4 architecture, §5 stage notes incl. the Stage-3 landing note), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then skim
the code you are extending:

- `SWFRecomp/src/abc/abc_emit.cpp` — Stage-3 emitter (full-body emission,
  labels/gotos, setjmp try frames, signatures/pools/interfaces in static
  data). You mainly add **ApplyType** here.
- `SWFModernRuntime/{src,include}/avm2/` — 11-file runtime. Property
  engine + builtins live here; you add Vector/RegExp/JSON modules and
  extend the class machinery for parameterized types.

Stage 3 landed at `2ceede962` (+ `4a5b5af07` docs). CI baseline:
**avm2 296/1198 (24.7%)**, 152/166 tranche-1 candidates, zero AVM1
regressions, wasm-link-smoke green. Static op census: 1069/1162 covered
with 122 ops (`_investigation/STAGE3_OPS.txt`).

## Goal

Tranche 2: **Vector, RegExp, JSON, object/proto edge cases.** Candidate
list (55 names, statuses as of `2ceede962`):
`ruffle-tests/tests/swfs/avm2/_investigation/TRANCHE2_CANDIDATES.txt`
(vector_* 29, regexp_* 6, json_* 4, plus proto edge cases and the
tranche-1 leftovers these features unlock: string_match/replace/search/
split, try_catch, class_call, array_vector_null_callback,
function_unbound_this, ...).

Exit: **≥45 of the 55 candidates passing in CI; every miss triaged**;
zero pass→fail regressions anywhere (avm2 included — the 296 baseline
tests must stay green).

## Prepared data — use it to sequence the work

Census against the Stage-3 op set
(`python3 SWFRecomp/tools/abc_op_census.py
--implemented-file ruffle-tests/tests/swfs/avm2/_investigation/STAGE3_OPS.txt`):

- **ApplyType is the ONLY missing opcode** for the tranche: it blocks all
  29 vector_* candidates (and 80 tests corpus-wide — the single biggest
  unlock left). json_*/regexp_* are already op-covered: pure builtin work.
- The `--filter` flag scopes the census (e.g. `--filter "^vector_"`).

## Deliverables (suggested order — commit at each observable checkpoint)

1. **Vector** (biggest win, do it first):
   - Parser/IR already carry TypeName multinames (kind 0x1d,
     `base_type` + `type_params` in `AbcMultiname`) — but the EMITTER's
     `Avm2AbcMultiname` struct does NOT emit them yet. Extend the static
     data (base_type + param multiname indices), then implement
     `ApplyType` (emitter + `avm2_op_applytype`): pop type args, produce
     the parameterized class object `Vector.<T>`.
   - Runtime model: a parameterized-class cache on the Vector class
     (one `Avm2Class` per distinct T — is/as/coercion need identity),
     element storage typed by T (coerce on write; int/uint/Number
     defaults per element type), `fixed` flag (RangeError 1126 on
     grow — try_catch asserts its exact message), length get/set,
     the Array-like method family. Port semantics from Ruffle
     `core/src/avm2/globals/vector.rs` + `VectorObject.as` and
     `vector.rs` (storage). Reuse the avmplus qsort already in
     avm2_array.c for Vector.sort (it is exported for exactly that
     reason in Ruffle; factor ours out of avm2_array.c similarly).
   - `Vector.<int>(other)` conversion calls (class_call test), `is/as`
     with parameterized types, `toString`/`join`.
2. **RegExp**: decision point — we need an ECMA-262 regex engine in C
   that also compiles for WASM (emcc). Recommended: vendor **QuickJS's
   libregexp** (MIT, self-contained ~2 files + cutils, ECMA-compatible,
   used for exactly this elsewhere); add under
   `SWFModernRuntime/third_party/` and wire into verify_output.py's
   avm2 file list + wasm builds. Alternatives (hand-rolled subset, PCRE2)
   are worse (semantics drift / heavy dep). Then: RegExp class
   (source/flags/global/ignoreCase/multiline/lastIndex, exec/test),
   String.match/replace/search/split regex paths ($-replacement
   patterns, replace-with-function, global flag semantics) — port from
   Ruffle `core/src/avm2/regexp.rs` + `globals/string.rs`.
   NOTE: Ruffle's `regress` engine and libregexp may differ on exotic
   patterns; run the regexp_* expected outputs early to catch drift
   before building on top.
3. **JSON**: hand-written C in a new avm2_json.c — `JSON.parse` (reviver)
   + `JSON.stringify` (replacer fn/array, space indent) per ECMA-262 with
   avmplus quirks; port from Ruffle `core/src/avm2/globals/json.rs`.
   Number formatting reuses `avm2_format_number`. Cyclic structures →
   TypeError #1129 exact string.
4. **Proto/object edge cases** (small, test-driven): prototype_set_null,
   error_prototype, findprop_global_prototype,
   constructprop_dynamic_primitive, amf_nondynamic_function_prop —
   diff each and fix; most are one-line rules in the property engine.
5. **Cheap unlocks if time permits**: minimal
   EventDispatcher.addEventListener/dispatchEvent + Event stub
   (function_unbound_this); Proxy is tranche 3 — do NOT start it.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode); confirm
  zero pass→fail across ALL suites (incl. the avm2 296 baseline) and
  wasm-link-smoke green.
- **Conflict boundary**: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`, `RecompiledABC/` paths. Do NOT
  touch `SWFModernRuntime/src/actionmodern/action.c`. New src/avm2/*.c
  files must be added to verify_output.py `compile_native`'s avm2 list
  (the one allowed edit there) — and to the wasm-link-smoke path if the
  runtime file set is enumerated there too (check `ruffle-tests.yml`).
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. The census tool and
  `--dump-abc` are local-safe.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Stage-3 gotchas you must not trip over

- **Fast local iteration**: Stage 3 used a scratchpad harness
  (build_avm2.sh: copy sources + per-file `ccache gcc` at ~0.4 s/test;
  run_batch.sh: exact-diff PASS/FAIL). Rebuild that pattern — but its
  exact string compare is STRICTER than verify_output.py
  ([approximations] sections enable numeric compare with max_relative)
  and bash mangles NUL bytes in output; confirm ambiguous FAILs through
  verify_output.py before chasing them.
- "public" for dynamic props = EMPTY-URI Namespace/Package only; AS3 ns
  unifies with public only inside `avm2_propkey_matches`. Miss codes:
  sealed → 1069, dynamic+non-public → 1081, set-miss → 1056.
- Class/script INITIALIZERS are "interpreter mode" (emitter marks them;
  `interp` arg on *_dyn helpers): index fast path ignores the ns set.
- Redeclared slots get NEW indices; slot defaults live in per-vtable
  `Avm2SlotMeta` tables; protected/interface members are vtable aliases
  and overrides sync every alias sharing the old implementation.
- ReturnVoid coerces undefined to the return type; unchecked functions
  (is_function + untyped default-free params) skip 1063.
- Array semantics: holes resolve through the prototype
  (`resolve_hole`), pop removes the last non-hole, avmplus qsort with
  SWF<11/SWF<13 quirks gated on `avm2_generated_swf_version`.
- Number/string parity: string_to_f64 uses `f64_powi` (NOT pow);
  toFixed/toExponential format from shortest DIGITS. Don't "fix" 1-ulp
  diffs covered by a test's max_relative.
- GC: AVM2 allocations remain census-invisible/immortal (fine for
  MAX_FRAMES-bounded tests; revisit only if something OOMs). Vector
  storage should follow the same rule.
- The 9 corpus SWFs failing verification are intentional; VerifyError
  bodies throw catchable VerifyErrors with OUR verifier's message text —
  if a verify_* test asserts FP's exact 10xx wording, map codes to FP
  strings at emit time rather than rewording the verifier.

## End-of-session bookkeeping

- Stage-4/tranche-2 landing note in `avm2-support-plan.md` §5.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline, new
  census ceiling with the Stage-4 op set — update STAGE3_OPS.txt or add
  STAGE4_OPS.txt).
- Update the `avm2-stage3-tranche1` / direction memories (Stage 4 status,
  next = tranche 3).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2/3 convention).
