# Session prompt — AVM2 Stage 4: tranche 3 (Namespace/QName, Proxy, Dictionary, ByteArray, AMF)

**STATUS: COMPLETE (2026-07-11).** Landed at `7655bb69b`..`ee006f815`:
48/53 candidates pass locally (exit ≥42 met). Misses, all triaged:
bytearray_oom + dictionary_weak_keys (upstream-ignored), amf_xml +
qname_as_lazy_name_attribute_multiname (E4X, deferred),
amf_array_serialization (LocalConnection/NetConnection + test-framework
fetch mock, deferred). Census ceiling 1155/1163 (TRANCHE3_OPS.txt, 124
ops). CI baseline: run 29158224391 — **avm2 411/1200 (34.2%)**, +57 over
tranche 2, zero regressions in any suite, wasm-link-smoke green. See
avm2-support-plan.md §5 tranche-3 landing note and
avm2/_investigation/CURRENT_STATUS.md.

You are implementing the second half of **Stage 4** of
`SWFRecompDocs/plans/avm2-support-plan.md` (§5 "tranches 2+3"; tranche 2
is DONE — see its landing note in §5 and the COMPLETE header of
`SWFRecompDocs/prompts/avm2-stage4-tranche2.md`). Read the plan first
(§4 architecture, §5 stage notes), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then skim
the code you are extending:

- `SWFRecomp/src/abc/abc_emit.cpp` — emitter. You add **PushNamespace**
  and the **lazy-namespace multiname variants** (RTQName/RTQNameL — see
  "Prepared data").
- `SWFModernRuntime/{src,include}/avm2/` — 14-file runtime (tranche 2
  added avm2_vector/regexp/json.c). You add Namespace/QName/Proxy/
  Dictionary/ByteArray/AMF modules and hook Proxy + Dictionary into the
  property engine.

Tranche 2 landed at `1d4f0b6fb`..`9a21db625` (+ `a2f1b7c27` docs). CI
baseline: **avm2 354/1200 (29.5%)**, run 29154109023; 50/55 tranche-2
candidates; zero regressions anywhere; wasm-link-smoke green. Census
ceiling 1148/1162 with 123 ops (`_investigation/STAGE4_OPS.txt`).

## Goal

Tranche 3: **Namespace/QName, Proxy, Dictionary, ByteArray, AMF.**
Candidate list (53 names, statuses as of `9a21db625`):
`ruffle-tests/tests/swfs/avm2/_investigation/TRANCHE3_CANDIDATES.txt`
(amf_* 10, bytearray_* 13, dictionary_* 10, namespace_* 3, proxy_* 8,
qname_* 7, plus the tranche-2 leftovers these unlock: class_call needs
ByteArray, coerce_to_primitive_side_effects needs Proxy).

Exit: **≥42 of the 53 candidates passing in CI; every miss triaged**;
zero pass→fail regressions anywhere (the avm2 354 baseline must stay
green). Known likely-triage members: bytearray_oom (upstream-ignored,
already in `ignored_tests.txt`), qname_as_lazy_name_attribute_multiname
(GetDescendants/E4X), dictionary_weak_keys (weak refs are unobservable
while AVM2 allocations are immortal — check what the test actually
asserts before writing it off).

## Prepared data — use it to sequence the work

Census against the Stage-4 op set (`python3
SWFRecomp/tools/abc_op_census.py --implemented-file
ruffle-tests/tests/swfs/avm2/_investigation/STAGE4_OPS.txt
--filter "^(namespace|qname|proxy|dictionary|bytearray|amf|class_call|coerce_to_primitive)"`):

- **PushNamespace is the only missing opcode that matters**: it blocks
  namespace_constr, proxy_getproperty/setproperty/deleteproperty, and
  qname_indexing (5 of the 53; 6 corpus-wide). It pushes a **Namespace
  VALUE** onto the operand stack — you need a runtime Namespace object
  representation first, so do Namespace/QName before Proxy.
- GetDescendants blocks only qname_as_lazy_name_attribute_multiname
  (E4X op — triage or throw the FP error if that's what the test wants).
- **Emitter gap beyond opcodes**: the proxy tests read/write/delete
  `p.flash_proxy::proxy_var` via **RTQName/RTQNameL multinames (lazy
  NAMESPACE)** — `emitOp` currently returns false (named abort) for
  `mnLazyNs` on Get/Set/Delete/CallProperty. You must add `*_dyn_ns`
  emission + runtime helpers that pop the Namespace value (and name, for
  RTQNameL) from the stack. Grep `mnLazyNs` in abc_emit.cpp for every
  bail-out site.

## Deliverables (suggested order — commit at each observable checkpoint)

1. **Namespace + QName** (unblocks the op + the lazy-ns machinery):
   classes with native_ext state (Namespace: prefix/uri; QName:
   uri/localName), constructors per Ruffle
   `globals/{Namespace,QName}.as` + `object/{namespace,qname}_object.rs`
   (constructor arg matrices, toString/valueOf, equality — Namespace ==
   compares uri), PushNamespace emission + `avm2_op_pushnamespace`,
   RTQName/RTQNameL property-op variants end-to-end, QName-valued
   property access (GetProperty with a QName OBJECT as the lazy name —
   qname_indexing), enumeration order quirks
   (namespace_enumeration_order/qname_enumeration).
2. **Dictionary** (`flash.utils.Dictionary`): object-identity keys
   beside string keys (primitive keys coerce to string? — port Ruffle
   `object/dictionary_object.rs` exactly: it keys objects by identity
   and primitives as strings), for-in/for-each enumeration interleaving,
   `delete`, `in`, hasOwnProperty. The dictionary_access_no_pubns
   runtime_error is probably the JIT-probe pattern from Stage 3 — check
   the 1056/1081 gates. Weak keys: read the test before triaging.
3. **Proxy** (`flash.utils.Proxy`, ns
   `http://www.adobe.com/2006/actionscript/flash/proxy`): property-engine
   hooks — when a receiver's class chain hits Proxy, route dynamic-name
   misses to getProperty/setProperty/deleteProperty/callProperty/
   hasProperty and enumeration to nextNameIndex/nextName/nextValue (port
   Ruffle `object/proxy_object.rs`); unimplemented-override errors
   (2088-family). Then coerce_to_primitive_side_effects (Proxy toString/
   valueOf via callProperty).
4. **ByteArray** (`flash.utils.ByteArray`): endian-aware read*/write*
   family, position/length/bytesAvailable, [] index access, toString
   (utf8 w/ BOM handling — bytearray_readutf8bytes_with_bom /
   bytearray_utf16), compress/uncompress (zlib is already linked — the
   AVM1 runtime uses it; check verify_output.py's link line), writeUTF/
   readUTF, errors (EOFError 2030 — flash.errors classes landed in
   tranche 2). Port from Ruffle `bytearray.rs` +
   `globals/flash/utils/ByteArray.as`. Then class_call.
5. **AMF3/AMF0 + registerClassAlias** (`writeObject`/`readObject`,
   `flash.net.registerClassAlias/getClassByAlias`): the wire format is
   NOT in Ruffle core — it lives in the flash-lso crate; a local
   checkout exists at
   `~/.cargo/git/checkouts/rust-flash-lso-19ba36a644beb8b7` (read
   `flash_lso/src/amf3/write.rs`/`read.rs` + `amf0/*`), with Ruffle's
   AVM2 bridge in `core/src/avm2/amf.rs` (typed vs dynamic objects,
   sealed-trait serialization via public_vtable_properties, Vector/
   Dictionary/XML markers, reference tables). Hand-write the C
   (avm2_amf.c); amf_* tests assert exact byte dumps via toString of
   the ByteArray, so the reference tables (string/object/trait refs)
   must be exact. amf_nondynamic_function_prop needs registerClassAlias.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode); confirm
  zero pass→fail across ALL suites (incl. the avm2 354 baseline) and
  wasm-link-smoke green.
- **Conflict boundary**: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`,
  `SWFModernRuntime/third_party/`, `RecompiledABC/` paths. Do NOT touch
  `SWFModernRuntime/src/actionmodern/action.c`. New src/avm2/*.c files
  must be added to verify_output.py `compile_native`'s avm2 list (the
  one allowed edit there). wasm-link-smoke builds AVM1 demos only — no
  workflow edit needed for new avm2 files.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. The census tool and
  `--dump-abc` are local-safe.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Tranche-2 gotchas you must not trip over

- **Local iteration**: loop verify_output.py per test (~3.7 s warm via
  ccache); a batch script greping `^(Pass|Effective pass):  *1` over the
  candidate list works well (tranche 2 used exactly that). Don't build a
  bash exact-diff harness — [approximations] and NUL handling bite.
- **Include what you call**: the runtime compiles with `-w`; a missing
  `#include <stdlib.h>` made strtod silently return int garbage in
  tranche 2. When a libc call misbehaves only inside the test binary,
  check includes first.
- Movies whose SymbolClass has **no char-0 binding** construct each
  bound class in tag order, best-effort (skips un-realized slots —
  `avm2_main.c`). Don't make that path fatal; negative_volume_panned's
  vacuous pass depends on it.
- Before chasing an ordering diff, read the test's `output.txt` header:
  some expectations are **hand-edited to Ruffle's HashMap iteration
  order** (json_stringify) and are unmatchable in principle → triage.
- Error 1034 debug strings: the VALUE side prints `ns::Class@...`, the
  TARGET class prints dotted `ns.Class` (avm2_class.c). Error-family
  name/message are instance SLOTS; prototype-CHAIN reads only see
  dynamic props.
- Parameterized-class identity, application caches, and "extends the
  builtin base, coerce args to the base not the receiver's exact class"
  (Vector.concat) are the patterns to copy if Dictionary/Proxy need
  per-shape classes.
- "public" for dynamic props = EMPTY-URI Namespace/Package only; the
  proxy flash_proxy ns must NOT unify with public. Miss codes: sealed →
  1069, dynamic+non-public → 1081, set-miss → 1056. Interpreter-mode
  bodies take the index fast path regardless of ns set.
- GC: AVM2 allocations remain census-invisible/immortal; ByteArray
  storage should follow the same rule (bytearray_oom is ignored — don't
  chase OOM behavior).

## End-of-session bookkeeping

- Tranche-3 landing note in `avm2-support-plan.md` §5.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline; the
  op set gains PushNamespace — write STAGE4_OPS.txt forward or add
  TRANCHE3_OPS.txt and re-census).
- Update the `avm2-stage4-tranche2` / direction memories (Stage 4
  status; what's next — likely Stage 5 frame lifecycle, or the E4X/XML
  plan if tranche 3 finishes Stage 4).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2/3/tranche-2
  convention).
