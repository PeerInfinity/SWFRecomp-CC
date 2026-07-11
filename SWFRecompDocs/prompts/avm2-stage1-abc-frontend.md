# Session prompt — AVM2 Stage 1: ABC front-end (parser + resolved IR + dump tool)

You are implementing **Stage 1** of `SWFRecompDocs/plans/avm2-support-plan.md`.
Read that plan first (especially §4.1 compiler pipeline, §5 stages), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`. Stage 0
(harness scaffolding) landed at `da7964f16`; the avm2 corpus downloads via
`ruffle-tests/download_tests.sh avm2` (1,202 tests, each with `test.swf`).

## Goal

A C++ ABC front-end in the recompiler that parses and pre-resolves AVM2
bytecode, plus a dump tool — **no C code generation and no runtime work yet**
(that's Stage 2).

Deliverables:
1. **ABC parser** in a new module tree `SWFRecomp/src/abc/` (headers under
   `SWFRecomp/include/abc/`): constant pool (ints, uints, doubles, strings,
   namespaces, ns-sets, multinames), method infos + bodies, metadata,
   instances/classes, scripts, traits, exception tables. DoABC (tag 82) and
   DoABC2/"DoABCDefine" carry the payload; SymbolClass (76) parsing can be
   read+recorded but nothing acts on it yet.
2. **Verifier / IR translation** modeled on Ruffle's design: translate raw
   ops into a resolved internal IR — multiname/class/method references
   resolved to **static table indices** (never runtime pointers), jump
   offsets rewritten to op indices, compare-and-branch fusion optional,
   exception tables resolved to op-index ranges. Stack-depth checking per
   method (max_stack/local_count validation) is in scope; the type-lattice
   optimizer is NOT (later stage, plan §4.1).
3. **`--dump-abc` tool**: given a SWF, print a readable dump (constant pool,
   classes/traits, per-method IR listing). Decide the cleanest home — a flag
   on the SWFRecomp binary or a small separate tool target — and follow the
   existing build layout (`SWFRecomp/CMakeLists.txt`, scripts in
   `SWFRecomp/scripts/`).

## Key references

- **Binary format ground truth:** `~/CC/ruffle/swf/src/avm2/read.rs` (1,091
  lines), `types.rs`, `opcode.rs` — a complete, compact ABC reader to port
  from. Prefer this over the Adobe AVM2 Overview PDF when they disagree.
- **IR design:** `~/CC/ruffle/core/src/avm2/verify.rs` (AbcOp→Op translation,
  offset rewriting, exception resolution) and `op.rs` (~140-variant resolved
  IR). Our IR must use static indices where Ruffle uses GC refs (plan §7.3).
- **Hook points in our recompiler:** `SWFRecomp/src/swf.cpp:6170` (DoABC
  commented stub), `:4746` (SymbolClass no-op), `:4719` (FileAttributes AS3
  bit — currently falls through; make AS3 SWFs route to the ABC parser
  instead of silently producing empty AVM1 output, gated so AVM1 SWFs are
  untouched).

## Exit criteria

- The parser + verifier run clean over **all 1,202 downloaded corpus SWFs**
  (write a small sweep script, e.g. `SWFRecomp/tools/` or scratchpad, that
  extracts DoABC from each `test.swf` and parses+verifies). Parsing the full
  corpus locally is fine and required — the "never run full suites locally"
  rule is about *executing tests*, not parsing files. Report a
  parse/verify failure table if any remain, with triage notes.
- `--dump-abc` output for `hello_world` and 2–3 tranche-1 tests
  (e.g. `add`, `closures`, `es4_inheritance`) spot-checked by hand against
  the `.as` source for plausibility.
- Zero behavior change for AVM1: if `swf.cpp` shared paths are touched, run
  the pipeline (no-graphics CI) per `.claude/pipeline-handoff.md` and confirm
  no pass→fail; if changes are purely additive new files, CI is optional per
  the ci-only-when-observable rule. Do NOT wire the avm2 suite into CI —
  that's deliberately deferred to Stage 2 (plan §5 Stage 0 note).

## Constraints & conventions

- Trunk-based: commit directly to `master`; autonomous commit/push/CI is
  authorized (CLAUDE.md). Standard commit trailer.
- Conflict boundary: AVM2 work owns `SWFRecomp/src/abc/`,
  `SWFRecomp/include/abc/`, and minimal gated edits in `swf.cpp`. Do NOT
  touch `SWFModernRuntime/src/actionmodern/action.c` — a concurrent session
  is doing AVM1 dispatch Stage 4 there.
- Structure rule from the plan: this is a new module tree; keep files small
  and split by concern (pool, parser, verifier, ir, dump) — no monoliths.
- LittleCube may reply to the architecture sketch mid-stage; his input window
  targets the Stage-2 object layout, so nothing here blocks on it, but if the
  user relays feedback that affects the IR, incorporate before finishing.

## End-of-session bookkeeping

- Add a Stage-1 landing note to `SWFRecompDocs/plans/avm2-support-plan.md`
  (§5) with commits + the corpus parse/verify pass count.
- Update `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`.
- Update the `project_avm2_direction` memory (Stage 1 status, next = Stage 2).
- If the stage is left partial, refresh THIS prompt file with precise
  "resume here" state, mirroring the dispatch-stage4 prompt convention.
