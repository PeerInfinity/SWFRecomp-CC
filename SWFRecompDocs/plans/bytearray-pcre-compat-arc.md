# Arc: ByteArray hardening + Tamarin-PCRE compat — two independent tracks, ~8–11 tests

**STATUS: DONE 2026-07-26 — `997d0c003` + `db7135ae5` + `e482c8b02` +
`4cdea28fe` + `1884c6ab9`, CI `30185616752` (graphics, `categories=full`).
Delivered +11 corpus against a predicted 8–11, zero pass→fail regressions,
and the crash histogram's timeout 3 → 0 (this doc predicted 3 → 1;
`avm2/bytearray_oom` turned out to be the same infinite loop, so it came
free). The full write-up is
`ruffle-tests/tests/swfs/from_avmplus/_investigation/CURRENT_STATUS.md`
§"Fix landed: the ByteArray + Tamarin-PCRE compat arc".**

Two corrections to the prescription below, both found while implementing:

- **1b's iteration count is 4 and 2, not 8-16k.** `0x100000000 -
  0xFFFFC000 = 0x4000`, stepped by 4096. The tests are short; they were
  hanging on the *first* iteration.
- **2b cannot finish `pcre_find_fixedlength`.** Its `match(re)` row records
  avmplus returning 500 real capture *values*; the >255 rewrite only
  restores grouping, so that test caps at 19/20 unless libregexp is forked
  (its bytecode stores capture indices as bytes). Track 2 therefore yields
  4 tests, not 5 — the shortfall was covered by `avm2/bytearray_oom` on
  track 1.

---

Opus-ready handoff. Fable diagnosis pass 2026-07-26 (code sites and every
test diff verified at `48d443f01`). The map listed both clusters as
"undiagnosed"; they are now fully diagnosed and neither needs new
architecture. The tracks share nothing — land them as separate commit
series in either order.

## Track 1 — ByteArray (6 tests)

| Test | now | sub-cause |
|---|---|---|
| `as3/ByteArray/ByteArray` | 424/425 | 1a — the single failing line is `hasAtomProperty false` |
| `as3/ByteArray/ByteArray_bug662851_32bit` | timeout | 1b |
| `as3/ByteArray/ByteArray_bug662851_64bit` | timeout | 1b |
| `as3/ByteArray/ByteArrayLzma` | 7/397, `#2030` | 1c |
| `as3/ByteArray/ByteArrayLzmaThirdParty` | 0/2, `#2058` | 1c |
| `from_shumway/lzma_bytes` | 0/2, `#2058` | 1c |

### 1a. `in` on a ByteArray checks index < length (trivial)

`5 in ba` where `ba.length == 3` must be `false`; `1 in ba` true
(Test.as:1142-1155). `avm2_op_in` (`avm2_ops.c:3280`) falls through to
`avm2_has_public_property`, which answers true. Add the ByteArray arm
(numeric index → `idx < ext->len`); mirror wherever Array/Vector indices
are already special-cased in the hasproperty path. One line of yield but
it completes a 424/425 test.

### 1b. Huge `length` must throw `#1000` — currently an INFINITE LOOP

`ba_set_length` (`avm2_bytearray.c:106-123`): the capacity doubling
`while (new_cap < new_len) new_cap *= 2` overflows uint32 to 0 once
`new_cap` reaches 2^31, then spins forever (`0*2 == 0`). That is what the
two "timeouts" are — a hang, not slowness, and a real-game bug worth
fixing regardless of tests.

Both tests loop `new ByteArray().length = i` for i from
0xFFFFC000/0xFFFFE000 (32/64-bit variant) to 2^32 step 4096, expecting
`Error #1000` **every iteration** (~8-16k iterations — the guard must
throw *before* any allocation attempt or the test is slow even when
correct). The test header links the exact avmplus source
(tamarin-redux `ByteArrayGlue.cpp` lines 132/147, kMaxObjectSize /
minimumCapacity checks) — pin the threshold from it; the tested range
means anything ≥ 0xFFFFC000 must throw. Note 0xFFFFC000 = 2^32 − 0x4000.

Upstream marks both `ignore = true` ("TODO Ruffle OOMs") but OUR runner
grades them (they sit in results as `timeout`) — fixing them flips two
corpus tests and one-ups Ruffle.

### 1c. LZMA codec (the only real work in this arc)

`compress("lzma")`/`uncompress("lzma")` are deliberately absent
(`avm2_bytearray.c:14-17` — "matching Ruffle-without-lzma"; compress
yields empty, uncompress throws `#2058`). But upstream runs these tests
with the `lzma` feature ON (`required_features` in both test.toml), so
the expected outputs are real LZMA round-trips.

Format: Ruffle uses `lzma_rs::lzma_compress/lzma_decompress`
(`~/CC/ruffle/core/src/avm2/bytearray.rs:212,239`) — the **LZMA-alone
format** (13-byte header: 1 props byte, u32le dict size, u64le
uncompressed size). `ByteArrayLzmaThirdParty` decompresses blobs made by
an external tool, which pins the format independently; verify the
13-byte header against its embedded data before writing any code.

Vendor the LZMA SDK C code (public domain, Igor Pavlov):
`LzmaDec.{c,h}`, `LzmaEnc.{c,h}`, `LzFind.{c,h}`, `7zTypes.h` — into
`SWFModernRuntime/third_party/lzma/`, wired the same way as `libtess2`
and `quickjs-libregexp` (copy their build integration; the CI
`wasm-link-smoke` job will catch a broken WASM link). Pure C99, no OS
deps — WASM-safe.

Semantics to pin from `ByteArrayLzma/Test.as` + output.txt (397 lines —
read it end to end, it is one long error-taxonomy test): empty/zero
buffers are no-ops, wrong-algorithm cross decompression throws (which of
`#2030` end-of-file vs `#2058` decompress-error per case is pinned by
the output), position/length after each op. The existing zlib arms
(`ba_compress` at `avm2_bytearray.c:1067`) show the buffer-swap
pattern to follow.

## Track 2 — Tamarin-PCRE compat in the regex preprocessor (5 tests)

All five `recursion/pcre_*` tests. **Read the expected outputs as
behavior recordings, not as assertions to satisfy**: avmplus's own run
FAILED some of its assertions, and output.txt records those `FAILED!
expected: -1 got: 0` lines verbatim. We must reproduce avmplus's
*behavior* (including its assertion failures), not make the assertions
pass. Every needed behavior is implementable in `re_preprocess`
(`avm2_regexp.c:174`) — do NOT patch vendored libregexp.

### 2a. Patterns with >255 capture groups must compile and match (4 tests)

libregexp hard-caps captures at 255 (`libregexp.c:59
CAPTURE_COUNT_MAX`); a pattern with more fails to compile and "never
matches" (returns -1/null). avmplus PCRE handles them fine. The tests:

- `pcre_could_be_empty_branch`: 406 nested capturing parens in a
  `(((…a)…))*` pattern; expects `search == 0` (a clean avmplus PASS).
- `pcre_is_anchored` / `pcre_is_startline` /
  `pcre_find_firstassertedchar`: line 1 (500 × `(?:`) already passes;
  line 2 (500 × capturing `(`) must MATCH at 0 so the output reads
  `FAILED! expected: -1 got: 0` — avmplus's own recorded assertion
  failure.

Fix in the preprocessor: count capturing groups; if ≥ 255 **and the
pattern contains no backreferences (`\1`-style) and no named-group
references**, rewrite `(` → `(?:` (skip `(?` constructs and escaped/
class parens). Today such patterns are guaranteed never-match, so the
rewrite can only improve behavior; patterns with backrefs stay on the
never-match path (none in the corpus need them).

### 2b. `pcre_find_fixedlength` (10/20) — two families in one test

Read `Test.as` + output.txt row by row; the 20 lines decompose into:

- The `strOriginal` rows (deep nesting): likely the same >255-captures
  cause as 2a — avmplus MATCHED (rows recorded as its own FAILED with
  `got: 4`), we return -1. Verify the pattern's group count from the
  source before assuming.
- The lookbehind rows: avmplus PCRE enforces **fixed-length lookbehind**
  — `(?<=a?)`, `(?<=a+)`, `(?<=a*)` are compile errors (→ never-match →
  -1, recorded as PASSED because the assertion expected -1), and a
  **nested group containing variable-length alternation**
  (`(?<=(a{3}|b{2}))`) is also rejected, while the same alternation
  bare at top level (`(?<=a{3}|b{2})`) is legal (PCRE rule: top-level
  branches may differ in length; nested constructs must be fixed).
  libregexp implements ES2018 variable lookbehind, so we currently
  match where PCRE errors. Implement a lookbehind-content validator in
  the preprocessor; on violation route the pattern to the existing
  failed-compile/never-match path. Pin every row's direction from the
  output — do not derive the rule from PCRE docs alone.

## Risks

- **2a's rewrite changes observable group results** for any >255-group
  pattern whose match/exec output is consumed — gate strictly on the
  ≥255 + no-backrefs condition where today's behavior is
  never-matches; that makes it monotone.
- **2b's validator must not over-reject.** Lookbehind appears elsewhere
  in the corpus (`ecma3/RegExp`, avm2 regexp tests are largely passing).
  Only reject what PCRE rejects; when a row is ambiguous, leave it
  matching and accept the smaller yield. Full CI is the check.
- **1c is the only sizeable code addition**: keep the vendored LZMA
  minimal (decode+encode, no threading — drop `LzFindMt`), follow the
  existing third_party wiring, and let `wasm-link-smoke` prove the WASM
  link.
- **1b ordering**: the #1000 guard must precede allocation AND the
  memset-zero path; also audit `ba_write_at`/`writeBytes` callers of
  `ba_set_length` for the same overflow (a write at position 0xFFFFF000
  hits the identical doubling loop).
- `#1000` message text: pin from `Utils.grabError` usage — the test
  compares only the error-number prefix, but other tests print full
  messages; match avmplus wording.

## Expected yield

Track 1: 6 (1a: 1, 1b: 2, 1c: 3). Track 2: 5. Ceiling 11; call it
**8–11** — the uncertain edges are ByteArrayLzma's 397 assertion lines
(more taxonomy may hide behind the round-trip) and find_fixedlength's
row-by-row mix. Zero expected outside these tests, but 2b touches the
shared regex path — watch the avm2 suite's regexp tests in the diff.

## Process

Standard pipeline (`.claude/pipeline-handoff.md`): commit per sub-cause,
graphics CI `categories=full`, one watcher,
`corpus_status_diff.py <sha> WORKTREE --per-suite`. Baseline = the
commit before your first change. Histogram to beat: segfault 3 /
timeout 3 / runtime_error 8 / recomp_fail 1 — and this arc should take
**timeout 3 → 1** (the two 662851 hangs). Docs after CI:
feature-priority-map (map + memory), from_avmplus CURRENT_STATUS, this
header, `.pipeline-state`.

## After this arc (queue)

Declared-ABC method arity checking (`avm2/wrong_arg_count`,
`avm2/error_geterrormessage`) · then the from_avmplus long tail is
mostly `known_failure` ceiling and one-off polish; the map's next real
mass is on the avm2-platform side (Loader 31, net/socket 30, input 25).
