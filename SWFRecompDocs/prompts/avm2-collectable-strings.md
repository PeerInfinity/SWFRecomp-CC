# Session prompt — AVM2 collectable strings (fix the runtime-wide leak / OOM)

You are making **AVM2 strings garbage-collectable**. Today `Avm2String`
allocations are never reclaimed: the browser Seedling demo leaks **~52 KB/tick
(~94 MB/min)** and OOM-exits after **~6–7 minutes of play** (measured RWK-3,
`AVM2_HEAP_STATS`). It also drove the ~1.4 GB PlayState boot spike that forced
the 1984 MB arena. This is **runtime-wide** — every AVM2 game accumulates it;
fixing it is what lets long manual playthroughs (Seedling, RWK) run
indefinitely. Not RWK/Seedling-specific; it's core runtime.

Read first: memory `avm2-stage11-gc` (the mark-sweep design), `avm2-rwk3-browser-demo`
(the leak measurement + `AVM2_HEAP_STATS`), and the avm2 suite `CURRENT_STATUS.md`.

## The exact mechanism (verified 2026-07-16)

- `avm2_alloc` (`avm2_main.c:57`) = `heap_alloc` (o1heap) + `avm2_gc_note_alloc(size)`.
  The note only advances the collect **watermark**; it does NOT enroll the
  allocation in the sweep census.
- The GC (`avm2_gc.c`, Stage 11) is mark-sweep over `g_gc_head`, a linked list
  of **`Avm2Object`** (header has `gc_next` + `gc_mark`). Only objects are
  enrolled; mark walks roots (values, scopes, slots, ext arrays) and sweeps
  unmarked between ticks (watermark 4 MB; `AVM2_GC_STRESS`=1 → every tick).
- `Avm2String` (`avm2_value.h:29`) is `{ uint32_t len; const char* utf8; }` —
  **no GC header, never on `g_gc_head`** → allocated by `avm2_string_new` /
  `avm2_string_concat` (`avm2_value.c:79/95`) and abandoned. FlxTilemap's
  `arrayToCSV` quadratic concat is the boot spike; per-tick trace/format/E4X
  concat is the steady leak.

## The work

Make strings a swept species. Rough shape (choose the cleanest against the
actual code):

1. **Enroll strings** in a collectable census — either a GC header on
   `Avm2String` (a `gc_next` + `gc_mark`, mirroring `Avm2Object`) or a parallel
   string list — populated by `avm2_string_new`/`avm2_string_concat`.
2. **Mark reachable strings.** `Avm2Value` holds `const Avm2String*` for string
   values; the mark phase must mark string values **everywhere it already marks
   object values** — operand stack, slots, dynamic props, scope chain,
   arguments, ext dense/sparse arrays. `avm2_gc_mark_value` is the natural hook
   (extend it to handle `AVM2_VALUE_STRING`).
3. **Audit the C-side escape surface — the risky part.** Any live
   `const Avm2String*` held OUTSIDE an Avm2Value must be pinned or marked as a
   root, or the sweep frees a live string → UAF. Enumerate them: interned /
   literal strings (`avm2_string_from_literal`), interned multinames/property
   names, class/display names, AMF aliases, E4X node text, module-static
   strings, anything cached across ticks. Pin literals/interned (immortal) and
   root the rest. **Missing one = use-after-free**, not a leak.
4. **Sweep** unmarked strings between ticks alongside the object sweep.

## Grading (this is high-blast-radius core code — over-verify)

- **`AVM2_GC_STRESS=1` is the tripwire**: collect every tick, so any missed
  root surfaces as an immediate UAF/crash instead of a rare one. Run the whole
  avm2 suite AND a Seedling + RWK smoke under stress locally before CI.
- **Regression test** (`ruffle-tests/tests/swfs/regression/`, mxmlc): loop-concat
  to a large string (e.g. build ~50–100 KB in a loop), assert completion +
  correct final length + a slice — proves concat garbage is reclaimed mid-run,
  not just that it doesn't crash. Add a second that stashes a string in a slot
  across a forced collect and re-reads it (proves live strings survive).
- **Soak**: drive Seedling (and/or RWK) many hundreds of ticks headless with
  `AVM2_HEAP_STATS=1`; assert steady-state memory is **flat**, not climbing.
  Record the before/after KB-per-tick in the session memory.
- **BOTH CI modes, zero pass→fail** — this touches the value model + GC, the
  highest blast radius in the runtime. Also confirms the boot spike drops (RWK
  and Seedling PlayState peak should fall well under the arena).

## After it lands (manual-test payoff)

Rebuild + restage the Seedling AND RWK browser wasm (per
`avm2-flashpunk-text-font-name-resolve`'s rebuild recipe — the staged
Archipelago-CC wasm does NOT auto-track runtime changes) so a long manual
playthrough no longer OOMs. Note this in the session memory.

## Boundaries

- Core runtime only (`src/avm2/`); do NOT touch `action.c` / the AVM1 GC.
- Don't regress the Stage-11 object sweep semantics (over-retain-on-mark-OOM,
  collect-between-ticks-only).
- Pinning literals/interned strings immortal is fine and expected — correctness
  over reclaiming the last byte.

Finish per `.claude/pipeline-handoff.md` — both CI modes, zero pass→fail;
update `CURRENT_STATUS.md`; write a session memory with the before/after leak
numbers and the escape-surface list you pinned/rooted (future GC work needs it).
