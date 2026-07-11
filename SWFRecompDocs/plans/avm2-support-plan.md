# AVM2 (ActionScript 3) Support — Umbrella Plan

**Status:** Draft v1, 2026-07-10. Planning session output; not yet started.
**Phase-1 success metric (user-confirmed):** pass rate on Ruffle's avm2 trace-test
corpus, mirrored into `ruffle-tests/tests/swfs/avm2/` — the same playbook that
took avm1 to 96.7% filtered.
**Coordination:** the architecture sketch (§4) goes to LittleCube via GitHub
issue + Discord per the friendly-fork arrangement
(`SWFRecompDocs/merge/upstream-relationship-2026-07.md`) — after this draft is
reviewed, before implementation locks in the object-model layout.

This plan is grounded in three surveys run 2026-07-10: Ruffle's AVM2
implementation (~66K lines Rust at `~/CC/ruffle/core/src/avm2/`), the Ruffle
avm2 test corpus (1,149 tests), and our own pipeline. Key file references are
cited inline so later sessions can drill in.

---

## 1. Why now

- AVM1 is at diminishing returns: avm1 96.7% filtered, all remaining failures
  triaged; from_shumway 100% filtered; Gnash tails have dedicated plans.
- The prerequisites AVM2 benefits from have landed: the mark-sweep GC
  (default-on, root-aggregator model) and the `invokeFunctionValue()` dispatch
  core (Stage 4 nearly complete; only the invocation-flag *normalization* is
  still in motion — see §7 Risks).
- LittleCube's assessment (2026-03): the objects/functions architecture will be
  "almost completely reused, at least in terms of design"; his open question is
  name/variable fetching — which §4.3 answers concretely.

## 2. What the test corpus demands (survey summary)

Corpus: `~/CC/ruffle/tests/tests/swfs/avm2/`, **1,149 test dirs**. Every test
ships a pre-compiled `test.swf` + `output.txt` — no AS3 compiler in the test
loop (Flex SDK 4.16.1 at `~/CC/flex-sdk` is available for authoring custom
regression tests).

- **~997 tests (87%) are pure trace tests** (no image comparison, renderer,
  network, or known_failure in test.toml). 109 are image-comparison, 140
  renderer-touching, 40 known_failure.
- **694 tests** import nothing from flash.* beyond
  MovieClip/Sprite/DisplayObject and have no image comparison — the realistic
  phase-1 ceiling.
- Root-class idioms: `extends MovieClip` (430), `extends Sprite` (226), bare
  `class Test` with script-level statements (~833, overlapping). Logic runs at
  script init / in the constructor; **only 32 tests use `addFrameScript`**, so
  the timeline/event machinery can be deferred past the first tranches.
- **Tranche 1 (~90 tests, pure language):** operators/bitwise, coercion
  (`coerce_*`, `convert_*`, `astypelate`), int/uint/Number/Boolean, strings,
  arrays, OOP (`es3_/es4_inheritance`, interfaces, `class_*`),
  functions/closures (`function_call_*`, `closures`), `try_catch`/`throw`.
  Full list in the 2026-07-10 survey (session transcript) — regenerate with the
  import-based filter if needed.
- **Tranche 2 (~50):** `vector_*`, `json_*`, `regexp_*`, object/proto edge cases.
- **Tranche 3 (~60):** `namespace/qname/proxy/dictionary`, ByteArray, AMF.
- **Deferred:** `xml_*`/E4X (~51 — needs a full XML engine), everything
  graphics/network/audio/AIR/Stage3D. AVM1↔AVM2 interop tests are a handful,
  all graphics/interactive — out of scope early.

## 3. What we already have (pipeline survey summary)

**Test harness — generalizes cheaply:**
- `verify_output.py` discovery/build/grade is suite-parametric via
  `--tests-dir`. Needed edits: add avm2 to `SUITE_DIRS` (~line 517); the
  avm1-scoped defaults `TESTS_DIR`/`RUFFLE_UPSTREAM` (lines 504/513) stay as
  defaults. Per-suite `ignored_tests.txt` and `_results/` work for free.
- `download_tests.sh` currently **filters OUT** AVM2 via
  `swf_is_avm2.py --filter-avm1`; the classifier (FileAttributes AS3 bit /
  DoABC presence) is already correct — add an avm2 category with the filter
  inverted.
- CI `ruffle-tests.yml`: mechanical per-suite fan-out edits in ~6 enumerated
  places (the file documents them at lines 88-90). Phase 1 runs `no-graphics`
  mode only. `MOCK_DATE_TIME` determinism carries over unchanged.

**Recompiler — hook points exist, translation is greenfield:**
- `swf.cpp:6170` DoABC (tag 82) commented-out stub; `swf.cpp:4746` SymbolClass
  (76) no-op; `swf.cpp:4719-4744` FileAttributes already reads the AS3 bit but
  the branch is disabled.
- AVM1 model to parallel: DoAction → `RecompiledScripts/script_N.c` via
  `action/action.cpp` (two-pass label discovery + emit). AVM2 is per-SWF
  class/method definitions, not per-frame scripts → new emit target
  **`RecompiledABC/`** (per-method C functions + class/trait registry tables).

**Runtime — display/services reusable, VM greenfield:**
- Reusable (~25K lines): `tag.c` display list, `ng_shared.c`, rendering,
  hit-test, audio, timers, heap/o1heap.
- GC: mark-sweep in `object.c:1716-2130`; roots via the fixed aggregator at
  `object.c:2028-2034`. AVM2 objects join as a **new `*GcMarkRoots`
  participant** (per the memory-reclamation rules: every C-side stash rooted or
  scrubbed).
- Entry: `swf_core.c::runSWF()` ticks `funcs[current_frame]`. AVM2 needs
  **`runSWF_avm2()`** sharing the tick cadence/timers/exit conditions but
  replacing frame-func dispatch with: construct root class once after
  `tagInit`, then per-tick broadcast events + `addFrameScript` closures.
- **Not reused:** `action.c` (73,918 lines) and the `ActionVar` prototype-chain
  object model. AVM2's sealed-class/trait/slot model is structurally different.
  Hard rule: **the AVM2 runtime gets its own module tree
  (`SWFModernRuntime/src/avm2/`) from day one** — no second action.c.

## 4. Architecture sketch (LittleCube attachment)

### 4.1 Compiler pipeline — adopt Ruffle's verify/optimize design as the AOT front-end

The decisive survey finding: Ruffle does **not** interpret raw ABC. Its
verifier (`verify.rs`, 1,228 lines) translates AbcOp → a resolved internal
`Op` IR (~140 variants, `op.rs`): multinames/classes/methods pre-resolved from
the constant pool, jump offsets rewritten to op indices, compare-and-branch
fused, exception tables resolved, `getproperty` split into
Static/Fast(indexing)/Slow(dynamic). Its type-aware optimizer
(`optimizer/type_aware.rs`, 2,388 lines) then runs forward abstract
interpretation over a type lattice and lowers property ops to **direct slot
indices** (`GetSlot`/`SetSlot`) and calls to **vtable disp_ids**
(`CallMethod`) or native fn pointers.

That is exactly the front-end an AOT compiler wants. Our pipeline:

```
DoABC bytes → ABC parser → verifier/resolver (Ruffle verify.rs semantics)
  → typed IR (Ruffle Op-equivalent, static data instead of GC refs)
  → optional type-lattice pass (slot/dispatch lowering)
  → C emitter: one C function per ABC method body into RecompiledABC/
```

Because method bodies declare `max_stack`/`local_count` and the verifier
resolves stack depths statically, **operand-stack slots compile to C locals**,
not a runtime byte-buffer stack — a structural improvement over the AVM1
translator. Ship the IR + a dump tool first (Stage 1) so translation is
debuggable before any codegen exists.

### 4.2 Value & object model

- **`Avm2Value`**: 16-byte tagged value (Ruffle asserts the same size):
  `{undefined, null, bool, i32, f64, string, object}` with avmplus
  Number/Integer duality (i32-representable numbers canonicalize; coercions per
  `value.rs` — `coerce_to_{boolean,number,i32,u32,string,type}` map 1:1 to C
  helpers). Distinct type from AVM1's `ActionVar`; conversion shims only at
  interop boundaries (much later).
- **Objects**: mirror Ruffle's `ScriptObjectData` (`script_object.rs:61-79`):
  fixed **slot array** for declared traits + a dynamic property map for expando
  props (sealed classes have no dynamic map; reads on sealed → ReferenceError)
  + `proto` link + class/vtable pointers.
- **VTable** (`vtable.rs`): per-class flattened tables —
  QName→Property (slot_id | disp_id | virtual get/set), `slot_table` (type +
  default), `method_table` (C function pointers). Built by inheriting the
  superclass tables and appending subclass traits; overrides reuse the parent
  disp_id. In AOT these tables are **static const data emitted by the
  recompiler** — no runtime construction cost for SWF-defined classes.
- **GC**: AVM2 heap objects allocate from the existing heap and register a new
  mark-roots participant in the `object.c` aggregator; the mark phase walks
  slot arrays + dynamic maps + scope chains.

### 4.3 Name resolution (LittleCube's open question)

AS3 bytecode makes the static/dynamic split explicit, and the verifier makes it
free at runtime for the common case:

1. **Compile-time-known QNames on known-class receivers** → the optimizer
   lowers to `slot_table[i]` / `method_table[j]` — in C, a direct array index
   or direct call. No string ever touched at runtime.
2. **Static multinames without a known receiver class** → runtime lookup keyed
   by (interned name, namespace-set id) against the receiver's vtable
   `PropertyMap`. All ABC constant-pool strings are **interned at recompile
   time into a global string-id table emitted as static data** — the AVM1
   string-id-interning plan's endpoint, but free here because the constant pool
   already enumerates every name.
3. **Runtime multinames** (RTQName/MultinameL — name and/or namespace popped
   from the stack) → the slow path only; same interned lookup after coercion.

Case sensitivity is uniform (AS3 is always case-sensitive), so none of AVM1's
SWF-version folding applies.

### 4.4 Execution semantics to mirror

- **Scope**: two layers like Ruffle (`scope.rs`) — captured copy-on-write
  ScopeChain on closures + a live per-activation scope stack; `findproperty`
  searches live stack → captured chain → defining script's globals.
- **Exceptions**: per-method exception tables (from/to/target as op indices,
  catch class) resolved at recompile time; runtime dispatch via the existing
  `setjmp`/`longjmp` pattern (`g_exception_state` precedent), with typed-catch
  matching by class. Error-message parity spec: Ruffle's `error.rs` (2,114
  lines of exact numbered FP messages).
- **DoABC/SymbolClass ordering quirk** (`movie_clip.rs:4246-4255`): on a
  frame's first execution — parse/load ALL ABC (no initializers), process ALL
  SymbolClass tags (bind classes to characters), THEN run eager script
  initializers. Needed for flascc games; bake into the recompiler's emit order.
- **Events**: DOM-style 3-phase dispatch (capture/target/bubble) +
  **broadcast events** (`enterFrame`, `exitFrame`, `frameConstructed`,
  `render`) delivered to all constructed objects in creation order regardless
  of display-list membership. Deferred to Stage 5 (only 32 tranche-relevant
  tests need frames at all).

### 4.5 Builtin library strategy — hand-written core now, playerglobal-compatible surface

Ruffle implements flash.* + toplevel **in AS3 itself**: 470 `.as` files
(22,804 lines) compiled by `asc.jar` into `playerglobal_avm2.swf`; only
`native`-flagged leaf methods (119 Rust files) are host code, bridged via
generated tables (`build_playerglobal/`). Long-term, we can **recompile that
same playerglobal ABC through our own backend** and hand-write only the native
leaves in C — the `[Ruffle(...)]` metadata is a ready inventory of the required
native surface, and their stub tracker enumerates known-unimplemented methods.

But running playerglobal requires a nearly complete VM (Ruffle's own bootstrap
is a delicate multi-phase dance, `avm2.rs:541-607`). So:

- **Stages 2–4: hand-written C builtins** for the tranche-1/2/3 core (Object,
  Class, Function, Array, String, Number/int/uint, Boolean, Error family,
  Math, JSON, RegExp, Vector, Dictionary, ByteArray) — same approach that
  worked for AVM1, but registered through the vtable/native-method mechanism
  so the binding surface stays **playerglobal-shaped**.
- **Later stage: playerglobal adoption** — recompile Ruffle's playerglobal ABC
  (MIT/Apache-2.0, license-compatible; use their prebuilt artifact to avoid an
  asc.jar/Java build dependency) and migrate builtins onto it incrementally.
  Decision point deliberately deferred until the VM survives tranche 3.

## 5. Stages

- **Stage 0 — scaffolding** — **DONE 2026-07-10 (local half)**: avm2 category
  in `download_tests.sh` (new `swf_is_avm2.py --filter-avm2` inverted filter;
  opt-in, not in ALL_CATEGORIES yet), `SUITE_DIRS` entry (last, so bare-name
  collisions keep resolving to AVM1 suites), `.gitignore` block,
  `tests/swfs/avm2/ignored_tests.txt` seeded (221 entries: GPU/AIR 63,
  host-I/O 50, image-comparison 76, upstream known_failure 32),
  `_investigation/CURRENT_STATUS.md`. Verified end-to-end: 1,202 tests
  download; `hello_world` fails honestly (output_mismatch, empty output).
  **CI fan-out deliberately deferred to Stage 2** — with zero passing tests a
  CI baseline observes nothing (ci-only-when-observable), and the workflow
  file is in active use by concurrent AVM1 sessions.
- **Stage 1 — ABC front-end** — **DONE 2026-07-10**: parser
  (`SWFRecomp/src/abc/abc_parser.cpp`, ported from Ruffle `swf/src/avm2/read.rs`),
  verifier/IR translation (`abc_verifier.cpp`, modeled on `core/src/avm2/verify.rs`:
  reachability walk, op splits — GetLex/CallSuperVoid/GetGlobalSlot/compare-branches —
  offsets→op indices, exception resolution, plus static stack/scope-depth checking
  that Ruffle leaves to its optimizer), resolved IR with static table indices
  (`include/abc/abc_ir.hpp`), and `SWFRecomp --dump-abc` / `--check-abc` modes
  (`abc_dump.cpp`, `abc_tool.cpp`). Gated `swf.cpp` hooks: DoABC (72/82) parses +
  verifies with a printed summary, SymbolClass read+recorded (no-op), FileAttributes
  AS3 bit prints a clear not-yet-supported notice. Sweep
  (`SWFRecomp/tools/abc_corpus_sweep.py`): **1,202/1,202 corpus SWFs parse clean;
  1,193 verify clean; all 9 verify-flagged are correct flags** — 8 tests
  intentionally ship invalid bytecode (`verification`, `verify_*`,
  `cpool_index_invalid_bytecode_*` — they expect runtime VerifyErrors), and
  `json_errors` embeds a never-called template function with genuinely unbalanced
  scope depth at a merge (Ruffle's own `merge_with` would throw 1031 if it were
  invoked; lazy verification means it never is). Dumps spot-checked against `.as`
  sources for `hello_world`, `add`, `closures`, `es4_inheritance`. IR divergences
  from Ruffle documented in `abc_ir.hpp` (GetGlobalScope not lowered, PushNaN kept,
  Coerce/AsType/IsType keep multiname indices).
- **Stage 2 — hello_world end-to-end** — **DONE 2026-07-10** (`0fec4fbe6`
  core + `40e98bb42` CI fan-out): C emitter `SWFRecomp/src/abc/abc_emit.{cpp,hpp}`
  lowers verified IR into `RecompiledABC/` (static pools/class/script/trait/
  SymbolClass tables + one C function per body; operand stack = C local array
  sized by `computed_max_stack`); runtime module tree
  `SWFModernRuntime/{src,include}/avm2/` — 16-byte `Avm2Value` (coercion
  helpers named 1:1 with Ruffle value.rs), ScriptObject (slots + dynamic map
  + vtable ptr), flattened vtables (inherit super + append traits), captured
  scope chains, Ruffle-style definition domain with lazy script init,
  builtin stubs (Object/Class/Function, EventDispatcher→…→MovieClip with
  native addFrameScript, trace), `runSWF_avm2()` with the §4.4 load ordering.
  Entry split: `wasm_wrappers/main.c` dispatches on `-DSWF_AVM2` (set by
  verify_output.py when `RecompiledABC/` exists); `swf_core.c`/`action.c`
  untouched. GC: Stage-2 AVM2 allocations are census-invisible/immortal; a
  `g_avm2_gc_mark_roots` participant hook is registered in the object.c
  aggregator with the Stage-3 enrollment TODO. Stage-2 opcode surface =
  hello_world's 21 ops; everything else aborts at runtime with a named
  `unimplemented op` (verified on `add`/`closures`/`es4_inheritance` — the
  Stage-3 starting line). Exit met: hello_world passes locally; first avm2
  CI baseline **8/1198** (hello_world + 7 tests already inside the Stage-2
  surface: duplicate_defs, eager_init, lazyinit, nonconflicting_declarations,
  slot_disp_id_shared_numbering, swf8, symbolclass_invalid_utf8; 1163 named
  unimplemented-op aborts, 0 compile failures) with the suite wired into
  `ruffle-tests.yml` and `download_tests.sh` ALL_CATEGORIES. Follow-up
  `03c86381d`: DoABC emission gated on the FileAttributes AS3 bit (inert in
  AVM1 SWFs, matching Flash/Ruffle) — fixes the one AVM1-side regression the
  first CI run caught (gnash swfmill mixed-bytecode-as2); zero regressions in
  the confirming run.
- **Stage 3 — tranche 1 (~90 language tests)** — **DONE 2026-07-11**: full
  emitter rework (labels + gotos for all control flow, no truncation,
  setjmp try-frame prologues, pools/signatures/interfaces/protected-ns/
  SWF-version in the static data, interpreter-mode marking for class and
  script initializers) + the tranche-1 op surface (122 IR ops; census
  ceiling 61 → 1069 tests). Runtime grew from 6 to 11 modules
  (avm2_function/error/number/string/array.c): coercion matrix, shortest
  round-trip Number formatting, property engine (accessors, proto chains,
  bound-method cache, interface/protected aliases with override sync, slot
  metadata for shadowed slots, 1069/1081/1056 miss semantics),
  functions/closures (arguments/rest/defaults/unchecked/1063), typed
  exceptions (longjmp dispatch, catch-scope objects, FP error strings,
  debug call stack + getStackTrace), and the builtin core (Object/Class/
  Function/String/Number/int/uint/Boolean/Array/Math/Error family/toplevel
  + XML/XMLList/Date/Point stubs). verify_output.py approximations now
  match Ruffle's framework (section-gated numeric compare + max_relative).
  Exit met: **152/166 tranche-1 candidates** pass in CI (≥80-of-~90
  criterion); full-suite CI baseline **296/1198 (24.7%, up from 8)** with
  zero regressions in any suite; all 14 misses triaged to later-tranche
  deps (RegExp ×5, Vector ×3, describeType ×2, AMF ×1, Proxy ×1,
  display ×1, upstream-ignored ×1) in
  `avm2/_investigation/CURRENT_STATUS.md`. Landed at `2ceede962`.
- **Stage 4 — tranches 2+3 (~110 tests)**: Vector, JSON, RegExp, proto edge
  cases; Namespace/QName/Proxy/Dictionary, ByteArray, AMF. Exit: climbing
  toward the 694-test phase-1 ceiling; re-triage what's left.
- **Stage 5 — frame lifecycle + display basics**: broadcast events, 3-phase
  dispatch, `addFrameScript`, DisplayObject hierarchy bridged onto the existing
  display list. Unlocks the timeline-dependent minority + starts the path
  toward renderer-touching tests.
- **Later / separate plans**: playerglobal recompilation, E4X/XML engine,
  graphics-mode avm2 tests, AVM1↔AVM2 interop, AS3 games.

Custom AVM2 regression tests go in `ruffle-tests/tests/swfs/regression/`
(compiled with `~/CC/flex-sdk/bin/mxmlc`), per the existing convention.

## 6. Verification & workflow

- Grade with `verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2`
  locally per-test only; full suite via CI (`no-graphics` mode) per
  `.claude/pipeline-handoff.md`. Determinism via `MOCK_DATE_TIME` unchanged.
- The avm2 suite is additive — zero shared code with the AVM1 runtime until
  interop, so avm1-suite regressions from AVM2 work should be structurally
  impossible; CI runs both suites anyway.
- Conflict boundary with concurrent AVM1 sessions: AVM2 work owns
  `SWFModernRuntime/src/avm2/`, `SWFRecomp/src/abc/` (new), `RecompiledABC/`
  emit paths, and the Stage-0 harness edits; it does not touch `action.c`.

## 7. Risks & open questions

1. **LittleCube architecture input** — the sketch (§4) answers his
   name-fetching question; sent 2026-07-10 (GitHub issue + Discord).
   **No reply as of 2026-07-10 end of Stage 1; user decision: proceed with
   the §4.2 layout as sketched, non-conservatively.** If feedback arrives
   mid-Stage-2, the exposed surfaces are only Avm2Value / ScriptObject /
   vtable tables (kept in small dedicated headers so a reshape is cheap).
2. **Dispatch-core normalization still in flight** (AVM1 Stage 4b). AVM2 has
   its own call machinery, so no hard dependency — but if AVM2 method dispatch
   ends up wanting to share `invokeFunctionValue` concepts, wait for the
   normalized flag semantics before mirroring them.
3. **IR references**: Ruffle's `Op` holds GC pointers to runtime
   Class/Method objects; our IR must lower these to static table indices at
   recompile time. Design this into the IR from day one.
4. **Verifier corner cases** (obfuscated SWFs: mid-op jumps, non-boundary
   exception offsets, avmplus segfault quirks). Not exercised by the test
   corpus — punt with clean errors, revisit for games.
5. **Error-message parity**: many tests likely assert exact FP error strings;
   port from Ruffle's `error.rs` as needed rather than inventing wording.
6. **Numeric-string dynamic keys** ("cursed" avmplus uint-key special case,
   `script_object.rs:87-95`) and the Vector indexing version-bug
   (`type_aware.rs:1526-1543`) — replicate deliberately; candidates for
   `FLASH_BUGS_REPLICATED.md`-style documentation on the avm2 side.
7. **Scale**: Ruffle's engine core (ex-globals) is ~35K lines Rust; ours will
   be comparable C. The tranche structure exists precisely so value lands
   incrementally.
