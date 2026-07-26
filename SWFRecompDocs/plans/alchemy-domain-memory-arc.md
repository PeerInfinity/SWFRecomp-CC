# Arc: Alchemy domain memory (mops) — 13 tests + real-game value

**DONE — `5da28a6a5`, CI `30179405893` (2026-07-25): +14, predicted 13.**
All 13 `from_avmplus/mops/*` pass (each at full line count, including
`mops_basics` 56/56, previously a timeout), plus `avm2/domain_memory`
(1/133 → 133/133) as the 14th. Zero regressions; crash histogram improved
(runtime_error 21 → 8, timeout 4 → 3). The prescription below survived
contact intact — the load-bearing choices were re-fetching
`ext->bytes/len` through the ByteArray on every access (never caching the
pointer across `set_length` reallocs) and the persistent 1024-byte
zero-filled scratch while nothing is assigned.

Original handoff below, kept for the design rationale. Fable design pass
2026-07-25 (code sites verified at `6ad610ad5`).

## Goal

The 13 `from_avmplus/mops/*` tests (li8, li16, li32, lf32, lf64, lix8,
lix16, si8, si16, si32, sf32, sf64, mops_basics), all blank today: the
emitter generates `avm2_unimplemented_op(act, "Li8", 1)` for every memory
opcode, which kills the driver's eager init
([[avmplus-driver-eager-init-blanks-tests]] pattern — verified by
recompiling `mops/li8/test.swf` locally).

Beyond the corpus: every Alchemy/CrossBridge-compiled SWF runs on these
opcodes. This is the only current arc with direct game-bring-up value.

## Verified current state

- **Recompiler**: opcodes `Li8…Sf64` (0x35–0x3E) and `Sxi1/Sxi8/Sxi16`
  (0x50–0x52) parse and verify (`abc_parser.hpp:104`, `abc_ir.hpp:129`,
  operand-free case list at `abc_parser.cpp:615-640`). `abc_emit.cpp` has
  stack-effect entries but NO emission — the generated C calls
  `avm2_unimplemented_op`. There are NO dedicated lix8/lix16 opcodes in
  the enum — ASC compiles `lix8(addr)` as `li8 + sxi8` (confirm by
  recompiling `mops/lix8/test.swf` and reading the op comments; if a
  genuinely unknown opcode shows up the parser would have said so).
- **Runtime**: `flash.system.ApplicationDomain` exists as a minimal
  singleton (`avm2_globals.c:1549-1600`: `currentDomain`,
  `hasDefinition`, `getDefinition`, GC-rooted via
  `avm2_gc_mark_roots_globals`). No `domainMemory`, no
  `MIN_DOMAIN_MEMORY_LENGTH`.
- **ByteArray**: `Avm2ByteArrayExt { bytes, len, cap, position,
  endian_little, object_encoding }` (`avm2_globals.h:137-145`), with
  `avm2_bytearray_ext_of(v)` and a public `set_length` that **reallocs
  `bytes`**.

## Prescribed design

### Memory model (the load-bearing decision)

Domain memory IS the assigned ByteArray's buffer — no copy, no separate
allocation. Store the ByteArray **object pointer** on the context
(`ctx->domain_memory`, `Avm2Object*`, NULL = unset) and have every mops
access re-fetch `ext->bytes`/`ext->len` through it. Two consequences:

1. **ByteArray interop comes free.** The li8 test writes through
   `ByteArray.writeInt/writeFloat/writeDouble` and reads through mops
   loads on the same bytes; sharing the buffer makes that work with zero
   extra code.
2. **NEVER cache the bytes pointer** across calls (in a ctx field, a
   static, or emitter-level) — `set_length` reallocs, and the tests grow
   the ByteArray after assignment. Fetch-per-access is the correctness
   baseline; a perf-motivated cached base+len (invalidated from
   set_length) is a later, separate change for real games, not this arc.

When `ctx->domain_memory` is NULL, accesses use a lazily-allocated,
zero-filled **default scratch of exactly `MIN_DOMAIN_MEMORY_LENGTH`
(1024) bytes** — the li8 test's first assertion is
`LI8(1024)` → `RangeError #1506` *before* any domainMemory is assigned,
which proves an unset domain still has an addressable (1024-byte) memory.
Pin the rest of the unset/cleared semantics from `mops_basics` (what the
`domainMemory` getter returns when unset — likely `null`; what assigning
`null` does; the error for assigning a too-short ByteArray — read the
exact code from its output.txt, do not guess it).

### Runtime surface (new `avm2_mops.c` or a section in avm2_bytearray.c)

- `ApplicationDomain.MIN_DOMAIN_MEMORY_LENGTH` static const = 1024
  (`avm2_builtin_add_static_const`).
- `domainMemory` getter/setter on the ApplicationDomain class (instance
  accessors; the singleton is the only instance). Setter validates
  ByteArray-ness and min length (codes from mops_basics), stores the
  object, and the GC root marker at `avm2_globals.c:1554` must mark it
  (add alongside `g_current_domain`).
- Op helpers, `Avm2Value`-in/`Avm2Value`-out so the emitter stays dumb:
  `avm2_op_li8/li16/li32/lf32/lf64(act, addr_val)` and
  `avm2_op_si8/si16/si32/sf32/sf64(act, value_val, addr_val)` and
  `avm2_op_sxi1/sxi8/sxi16(act, v)`. Coerce the address with
  `avm2_coerce_to_i32`. Range check: `addr < 0 || (uint32_t)addr + SIZE >
  len` → `RangeError` `"Error #1506: The specified range is invalid."`
  (mind overflow: do the sum in int64 or check `addr > len - SIZE` after
  the len >= SIZE guard).
- Semantics: loads zero-extend (li8 → 0..255, li16 → 0..65535), li32
  yields a signed int32; lf32 widens float→double; stores truncate the
  coerced i32 (si8 stores the low byte) / narrow double→float for sf32.
  Byte order is **always little-endian regardless of
  `ByteArrayExt.endian_little`** — the test comments say exactly this
  ("memory opcodes use native endianness") and set the ByteArray to
  LITTLE_ENDIAN only so writeInt matches. memcpy on x86/wasm is fine;
  note the assumption in a comment.
- `sxi1/sxi8/sxi16`: pure int ops, no memory: sign-extend the low 1/8/16
  bits (`(int32_t)(v << 31) >> 31` shape).

### Emitter (abc_emit.cpp)

13 cases in the opcode switch, mirroring the existing one-liner style:

    // loads: addr on top, replaced in place
    stk[sp - 1] = avm2_op_li8(act, stk[sp - 1]);
    // stores: value under addr — CONFIRM order against the existing
    // stack-effect entries for these ops before hardcoding
    sp -= 2; avm2_op_si8(act, stk[sp], stk[sp + 1]);
    // sxi: in place
    stk[sp - 1] = avm2_op_sxi8(act, stk[sp - 1]);

The store operand order (value,addr vs addr,value) is recorded in the
stack-effect table abc_emit.cpp already carries for these opcodes — read
it, then sanity-check against avmplus (`instr si8: value and addr popped,
addr on top`). Getting this backwards passes no test and corrupts all of
them, so verify with `mops/si8` FIRST — it's the pure store test.

## Slices

1. **Runtime core** — ctx field + scratch + helpers + #1506 + accessors +
   const + GC marking. Compiles standalone; nothing exercises it yet.
2. **Emitter cases** — after this, `mops/li8` and `mops/si8` run; iterate
   locally on those two singles until green.
3. **Sweep the remaining 11** one test at a time
   (`--tests-dir .../from_avmplus/mops` once li8/si8 pass), pinning
   mops_basics details from its expected output as they surface.

## Hazards

- **Stale pointer**: the only real crash risk in this arc — see the
  memory-model rule above. If a test grows domainMemory mid-run and a
  helper cached `bytes`, that's a use-after-free ASAN would catch and CI
  segfault-histogram would show; keep fetch-per-access and it cannot
  happen.
- **GC**: `ctx->domain_memory` is a root. Miss the mark and the ByteArray
  collects mid-test.
- **Version/API sweep** ([[version-gate-new-api-surface]]): grep
  currently-PASSING tests for `domainMemory|MIN_DOMAIN_MEMORY_LENGTH`
  before landing — a visibility test may pass today only because the
  member is missing. (None expected — mops are ancient — but the check is
  one grep.)
- The blanked tests may hide post-mops failures: a test that stops being
  blank can newly fail on unrelated later assertions. Judge each of the
  13 by its full diff, not blank-vs-nonblank.

## Process

Standard pipeline (`.claude/pipeline-handoff.md`): commit per slice,
graphics CI `categories=full`, one watcher,
`corpus_status_diff.py <sha> WORKTREE --per-suite`, histogram vs baseline
segfault 3 / timeout 4 / runtime_error 21 / recomp_fail 1. Baseline
commit for the diff: the commit before your first change
([[ci-baseline-commit-must-postdate-its-run]]). Docs after CI:
feature-priority-map (map + memory), CURRENT_STATUS, this header,
`.pipeline-state`.

## After this arc (queue, from the 2026-07-25 re-rank)

Builtin-container subclasses (~7 upper bound; `extends Array` allocates
`AVM2_OBJ_SCRIPT` — `avm2_class_construct` inherits `native_ext_size` but
not object kind; the Dictionary/bug_687838 members of the cluster look
like separate causes) · as3/ByteArray (5, undiagnosed, 2 timeouts) ·
recursion/pcre_* (5, undiagnosed) · declared-ABC method arity checking
(`avm2/wrong_arg_count`, `avm2/error_geterrormessage`).
