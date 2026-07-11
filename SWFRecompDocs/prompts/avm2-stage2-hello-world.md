# Session prompt — AVM2 Stage 2: hello_world end-to-end

> **STATUS: COMPLETE 2026-07-10** (`0fec4fbe6` core, `40e98bb42` CI fan-out).
> All deliverables met: emitter (`SWFRecomp/src/abc/abc_emit.{cpp,hpp}` →
> `RecompiledABC/`), runtime module tree (`SWFModernRuntime/{src,include}/avm2/`),
> harness auto-detection (`-DSWF_AVM2` + `src/avm2/*.c` when `RecompiledABC/`
> exists), CI fan-out + download ALL_CATEGORIES. First CI baseline **8/1198**
> (zero AVM1 regressions after `03c86381d` gated DoABC on the AS3 bit);
> hello_world passes; near-miss
> probes (`add`, `closures`, `es4_inheritance`) fail on named missing opcodes.
> See plan §5 Stage-2 landing note and the avm2 CURRENT_STATUS.md.
> Next session: Stage 3 (tranche 1) — branches/labels in the emitter first.

You are implementing **Stage 2** of `SWFRecompDocs/plans/avm2-support-plan.md`.
Read that plan first (§4 architecture sketch, §5 stages), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then
`SWFRecomp/include/abc/abc_ir.hpp` (the resolved IR you are consuming — its
header comment documents the translation rules and the three deliberate
divergences from Ruffle).

Stage 1 (ABC front-end) landed at `a61e83aaa`: parser + verifier + resolved
IR + `--dump-abc`/`--check-abc` on the SWFRecomp binary. Corpus baseline:
1,202/1,202 parse, 1,193 verify clean (the 9 flags are intentional-bad
bytecode / a lazily-never-verified function — see CURRENT_STATUS).

**LittleCube did not reply to the architecture note within his window; the
user has decided NOT to be conservative.** Implement the §4.2 value/object
layout exactly as sketched. If the user relays feedback mid-stage,
incorporate it — the exposed surfaces are only `Avm2Value`, the ScriptObject
struct, and the vtable tables; keep each in its own small header so a
late reshape stays cheap.

## Goal

```
python3 ruffle-tests/verify_output.py --test=hello_world \
    --tests-dir=ruffle-tests/tests/swfs/avm2 --diff
```
passes (expected output: `Hello world!`, `num_frames = 1`) via a real,
minimal AVM2 backend: a C emitter in the recompiler plus a new runtime
module tree. **Implement only what hello_world's flow needs** — Stage 3 does
the full opcode/coercion matrix; resist building ahead.

## Execution anatomy of hello_world (derived from the Stage-1 dump — run
`SWFRecomp/build/SWFRecomp --dump-abc ruffle-tests/tests/swfs/avm2/hello_world/test.swf`
to see it yourself)

One DoABC tag: 2 classes (`Test` extends Object; `test_fla::MainTimeline`
extends `flash.display::MovieClip`), 2 scripts, 7 method bodies. SymbolClass
binds char 0 → `test_fla.MainTimeline`. Required flow:

1. **Load**: parse ABC, register scripts/classes, run NO script inits yet;
   process SymbolClass; then eager-init only the ABC's *last* script (the
   main/root script — script[1], defining MainTimeline). This is the plan
   §4.4 ordering quirk (Ruffle `movie_clip.rs:4246-4255`).
2. **script[1] init (method[6])**: FindPropStrict/GetProperty walks the
   display chain (Object → EventDispatcher → DisplayObject →
   InteractiveObject → DisplayObjectContainer → Sprite → MovieClip), pushes
   each as scope, `NewClass` MainTimeline, `InitProperty` onto globals. So
   the runtime needs **name-resolvable builtin class stubs for that whole
   chain** (stubs: constructible, correct super links; no display-list
   behavior needed).
3. **Root instantiation**: construct MainTimeline; its constructor
   (method[5]) runs `ConstructSuper` then
   `addFrameScript(0, frame1)` via CallPropVoid — needs a working
   addFrameScript on the MovieClip stub (store closure per frame index).
4. **Frame 1 tick**: run the registered frame script (method[4]):
   `FindPropStrict Test` → **lazy script init**: script[0] not yet run →
   run method[2], which `NewClass`es Test, `InitProperty`s it, and traces
   `"Hello world!"` (the script-level statement). Then `ConstructProp Test`
   → Test constructor (method[1]) → ConstructSuper → Object.
5. Exit after MAX_FRAMES (=1) ticks.

The exact IR opcode surface hello_world uses (21 ops, verified against the
dump): CallPropVoid, CallProperty, CoerceA, ConstructProp, ConstructSuper,
DebugFile, DebugLine (both no-ops), FindPropStrict, GetLocal,
GetPropertyStatic, GetScopeObject, InitProperty, NewClass, Pop, PopScope,
PushInt, PushScope, PushString, ReturnValue, ReturnVoid, SetLocal. Emit a
clear `unimplemented op` compile-time or runtime abort for everything else
so other avm2 tests fail honestly rather than silently.

## Deliverables

1. **C emitter** (recompiler, new files in `SWFRecomp/src/abc/`, e.g.
   `abc_emit.{cpp,hpp}` — keep the module's small-files-by-concern rule):
   consume `IrMethod` (run `verifyMethodBody` per body) and emit into a new
   **`RecompiledABC/`** output folder: one C function per method body
   (operand stack → C locals, sized by `computed_max_stack`; branches via
   op-index labels), plus static tables: interned string table, multiname
   table, namespace/ns-set data, class/instance/trait registry, script
   table with init-method pointers + lazy-init flags, SymbolClass root
   binding, exception tables (emit data; runtime dispatch can be a Stage-3
   TODO since hello_world has no try/catch). Wire the existing `swf.cpp`
   DoABC case (`SWF_TAG_DO_ABC`/`SWF_TAG_DO_ABC_DEFINE`) to call the
   emitter when parsing succeeds; keep the parse-summary printf. The
   `is_as3` flag and `symbol_class_bindings` member already exist on `SWF`.
2. **Runtime** (new module tree `SWFModernRuntime/src/avm2/` +
   `include/avm2/` — hard rule: no code in `action.c`, no `ActionVar`):
   - `avm2_value.{c,h}`: 16-byte tagged `Avm2Value`
     {undefined,null,bool,i32,f64,string,object} with avmplus
     Number/Integer duality; only the coercions hello_world needs
     (`coerce_to_string` for trace, `coerce_to_boolean` if needed) —
     port semantics from Ruffle `core/src/avm2/value.rs`, keep the C
     helper names 1:1 with Ruffle's (`avm2_coerce_to_string`, …).
   - `avm2_object.{c,h}`: ScriptObject per Ruffle `script_object.rs:61-79`
     — fixed slot array + dynamic property map + proto + class/vtable ptr.
   - `avm2_class.{c,h}` / vtable: build per-class flattened tables at
     class-definition time from the emitted static data (inherit super's,
     append own traits); native builtins register through the same
     mechanism (playerglobal-shaped surface, plan §4.5).
   - `avm2_globals.{c,h}`: builtin stubs — Object, Class, Function,
     `trace` (writes like AVM1's trace so output capture works), and the
     EventDispatcher→…→MovieClip chain with `addFrameScript`.
   - `avm2_main.{c,h}`: `runSWF_avm2()` — mirror `swf_core.c::runSWF`'s
     tick cadence/exit conditions (MAX_FRAMES define) but dispatch:
     load-ordering from step 1 above, then per-tick frame-script calls.
     **Do NOT edit `swf_core.c` to reference avm2 files** — the
     `wasm-link-smoke` CI job and every AVM1 test link `swf_core.c`
     without the avm2 sources; keep the entry split so AVM1 builds never
     need `src/avm2/*.c` (e.g. the generated avm2 `tagMain.c`/entry calls
     `runSWF_avm2`, and `main.c` stays common or gets a compile-time gate).
   - **GC**: allocate AVM2 objects from the existing heap and register ONE
     new `*GcMarkRoots` participant in the `object.c` aggregator
     (object.c:2028-2034) marking globals/scripts/scope roots — per the
     memory-reclamation rules (every C-side stash rooted or scrubbed). If
     hello_world provably allocates only immortal objects, a
     root-everything-immortal participant + documented Stage-3 TODO is
     acceptable; do not leave allocations invisible to the collector.
3. **Harness wiring** (`ruffle-tests/verify_output.py`): copy
   `RecompiledABC/*.c/.h` into the build dir alongside
   RecompiledScripts/RecompiledTags (copy loop ~line 1648) and add
   `src/avm2/*.c` to core sources **only when the test is avm2** (detect:
   `RecompiledABC/` exists after recompile, or tests-dir is the avm2
   suite). `MAIN_C` is `SWFRecomp/wasm_wrappers/main.c` (line 508);
   `-DMAX_FRAMES` comes from test.toml `num_frames` (lines 670/1908).
4. **CI fan-out** (`ruffle-tests.yml`): add the avm2 suite — the file
   documents the ~6 enumerated places (env DIRS block ~lines 101-107,
   RUN_* flags ~118-119 and ~597-598, category lists ~233-234 and
   ~669-670, and the combine script's categories dict ~1063+). Also add
   avm2 to `download_tests.sh` ALL_CATEGORIES (it's currently opt-in).
   Expected CI baseline after this stage: avm2 1/1202 passing
   (hello_world), everything else failing honestly — that's the
   observable baseline Stage 0 deferred CI for.

## Key references

- **Our own front-end**: `SWFRecomp/include/abc/abc_ir.hpp` (IR + operand
  semantics per opcode), `abc_verifier.hpp` (API: `validateAbcFile`,
  `verifyMethodBody`), `abc_dump.cpp` (`multinameToString` etc. — reuse for
  emitting readable comments into generated C). Debug any test with
  `--dump-abc`.
- **Ruffle** (`~/CC/ruffle/core/src/avm2/`): `value.rs` (coercions),
  `script_object.rs:61-79` (object layout), `vtable.rs` (table build /
  inheritance), `avm2.rs:541-607` (bootstrap ordering),
  `movie_clip.rs:4246-4255` (DoABC/SymbolClass/init ordering quirk),
  `globals/toplevel.rs` (trace), `error.rs` (exact FP error strings when
  you need one).
- **Runtime patterns to mirror**: `swf_core.c::runSWF` (tick loop),
  `object.c:1716-2130` + `:2028-2034` (mark-sweep + root aggregator),
  AVM1 trace output plumbing (so verify_output captures stdout the same way).
- Determinism: `MOCK_DATE_TIME` is defined on every gcc invocation by
  verify_output; nothing extra needed unless you touch Date/random.

## Constraints & conventions

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer.
- **Conflict boundary**: this work owns `SWFRecomp/src/abc/`,
  `SWFRecomp/include/abc/`, `SWFModernRuntime/src/avm2/`,
  `SWFModernRuntime/include/avm2/`, `RecompiledABC/` emit paths, plus
  careful gated edits to `swf.cpp` (DoABC case), `verify_output.py`, and
  `ruffle-tests.yml`. Do NOT touch
  `SWFModernRuntime/src/actionmodern/action.c` (concurrent AVM1 sessions).
- **Zero AVM1 behavior change.** swf.cpp / verify_output.py / workflow are
  shared → run the full pipeline (no-graphics CI) per
  `.claude/pipeline-handoff.md` and confirm no pass→fail across avm1 /
  gnash / shumway / regression. swf_core.c itself should not need edits;
  if you do end up touching shared `OFFSCREEN_RENDER`/graphics-adjacent
  code (you shouldn't this stage), run both CI modes.
- Suggested milestone order (commit at each observable checkpoint):
  emitter skeleton producing compilable empty RecompiledABC → runtime
  value/object/trace standalone → script-init + NewClass path → root
  binding + frame tick → hello_world green locally → harness/CI fan-out →
  full pipeline.
- Do NOT run the full avm2 suite locally (project rule) — single tests
  locally, full suite via CI once wired.

## Exit criteria

- `verify_output.py --test=hello_world --tests-dir=.../avm2` passes
  locally (native, no-graphics).
- CI: avm2 suite wired and green on hello_world (1/1202); other avm2 tests
  fail honestly (build/run failures fine, no shard-killing crashes); zero
  pass→fail regressions in all AVM1 suites; `wasm-link-smoke` still green.
- Optionally verify 2-3 near-miss tranche-1 tests (e.g. `add`) fail for
  *missing-opcode* reasons, not infrastructure reasons — that's the
  Stage-3 starting line.

## End-of-session bookkeeping

- Stage-2 landing note in `SWFRecompDocs/plans/avm2-support-plan.md` §5
  (commits, what's implemented, first avm2 CI baseline).
- Update `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`
  (pass count, how to run, what exists now).
- Update the `avm2-as3-direction` memory (Stage 2 status, next = Stage 3
  tranche 1).
- If the stage is left partial, refresh THIS prompt file with precise
  "resume here" state (mirroring the Stage-1/dispatch-stage4 convention);
  if complete, mark it COMPLETE at the top like the Stage-1 prompt.
