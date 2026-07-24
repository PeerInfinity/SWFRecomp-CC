# Session prompt — AVM2 String/Unicode arc (feature-priority map, arc 1)

Work the **top-ranked arc** in `SWFRecompDocs/plans/feature-priority-map.md`:
AVM2 String/Unicode semantics. ~102 `ecma3/Unicode` tests plus
`ecma3/String/esplit_002` and `ematch_004`, from **two** runtime bugs, both
already located to the line. This is the best effort-to-yield item in the
whole corpus.

Read first:
- `SWFRecompDocs/plans/feature-priority-map.md` — the corpus-wide ranking
  (why this is first, and what comes after).
- `ruffle-tests/tests/swfs/from_avmplus/_investigation/CURRENT_STATUS.md` —
  suite state, baselines, the avmplus-driver gotcha.

## State (2026-07-24, `119676bfa`)

Full corpus graphics baseline `eabb3b366`: 3211/4463 (71.9%). Last session
landed `d36c8da2b` (root SymbolClass must inherit Sprite → trace
`TypeError #2023`): +156 from_avmplus, +4 avm2, 0 regressions, e4x
2/177 → 160/177, from_avmplus 55.3% → ~65.4%.

⚠️ **The most recent CI run (`30121943045`) lost shard 25/30** to the known
apt/Vulkan flake, so 141 tests corpus-wide were never executed (52 in
from_avmplus). Your first CI run will therefore report those ~141 as
"newly passing" — **that is shard recovery, not your fix.** Subtract them
before claiming yield. Likewise `ecma3/String` currently reads 41 tests, not
its true 83.

## The two bugs (diagnosed, not guesses)

### Bug 1 — `search`/`match` don't coerce the pattern to a string

`SWFModernRuntime/src/avm2/avm2_regexp.c:567 pattern_to_regexp()` hands the
raw `Avm2Value` to the RegExp constructor. `regexp_init_from_args()`
(line 395) correctly maps `undefined` → `""` (ECMA §15.10.4.1), so
`"abc".search(undefined)` compiles an **empty** pattern, which matches at
index 0.

Ruffle (`core/src/avm2/globals/string.rs::search` and `match_internal`)
does `pattern.coerce_to_string(activation)?` **before** constructing, so
`undefined` becomes the literal pattern `"undefined"` — which never matches
the test strings. Expected `-1` (search) and `null` (match).

`pattern_to_regexp` is called from exactly two places — `string_match_regex`
(line 582) and `string_search_regex` (line 623) — so fixing it there is
safe; `replace` does not go through it, and Ruffle's `replace` deliberately
does *not* do this coercion.

Our non-global `match` already returns `avm2_null()` on no-match
(line 615), so **one fix repairs all four failing assertions**
(`search()`, `search(undefined)`, `match()`, `match(undefined)`).

### Bug 2 — `String.split('')` splits by UTF-8 byte, not UTF-16 code unit

`avm2_string.c::avm2_string_split_plain` (line 354), empty-delimiter branch
(~line 381): `for (uint32_t i = 0; i < s->len && i < limit; i++)` pushes
1-**byte** substrings. `s->len` is the UTF-8 byte length.

Measured: U+0080–U+00FF → 256 elements instead of 128 (2-byte UTF-8);
U+4E00–U+4EFA → 753 instead of 251 (3-byte). ASCII is unaffected, which is
why `u0000_BasicLatin` scores 17/21 and every other block 16/21.

The right helper already exists in that file: `utf16_unit_at(s, index,
&bs, &bl)`, used by `string_char_at` (line 160) — including its astral
handling (a 4-byte codepoint yields ONE code unit, surfaced as U+FFFD).
Mirror `charAt`: iterate `utf16_length(s)` units and honour `limit`.

## Expected yield

Every `ecma3/Unicode` test fails on exactly these five lines
(`search(undefined)`, `search()`, `match(undefined)`, `match()`,
`split('')`), repeated once per Unicode block in the file. 102 of 108 tests
should flip. Also in the blast radius: `ecma3/String/esplit_002` (30/94) and
`ecma3/String/ematch_004` (blanked).

Not in scope but adjacent, worth a look if cheap: `ecma3/Unicode/utf8count`
fails a single `str_utf8 == str_utf16` equality — a different bug.

## Workflow

**Never run a full suite locally — single tests only:**

```bash
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/from_avmplus \
    --test=ecma3/Unicode/u0080_Latin_1Supplement --diff --verbose
```

Good local probes: `u0000_BasicLatin` (ASCII — split already correct),
`u0080_Latin_1Supplement` (2-byte), `u4E00_CJKUnifiedIdeographs` (3-byte),
`ecma3/String/esplit_002`, `ecma3/String/ematch_004`. Also re-check a few
AVM2 regex/string tests in the `avm2` suite (`string_slice_substr_substring`,
`regexp_*`) before dispatching.

This touches shared AVM2 runtime code, so CI is `categories=full`:

```bash
gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f categories=full
```

Autonomous commit/push/CI is authorized — run the pipeline end-to-end per
`.claude/pipeline-handoff.md`, commit directly to `master` with the standard
trailer, and report any pass→fail regressions by name. If a shard fails on
"Install Vulkan + libavcodec + verify Dawn cache hit", that is the known
apt flake (`graphics-ci-aptget-flaky-shards`), not your change — but note
which tests went ungraded.

## When done

1. Update `from_avmplus/_investigation/CURRENT_STATUS.md` and the
   "Landed" + "Recommendation" sections of
   `SWFRecompDocs/plans/feature-priority-map.md` with actual CI yield.
2. Regenerate `python3 scripts/generate_failing_by_feature.py --suite=from_avmplus`.
   The results now carry `error_signature`, so the generated doc should
   gain a **"Failing Tests by Uncaught Error"** table — read it, and use it
   to re-rank the remaining arcs instead of re-deriving root causes by hand.
3. If there is session left, the next two arcs are **`Date`** (~155 tests;
   AVM2 Date is a 3-method stub in `avm2_amf.c:1763`, AVM1 has a complete
   1014-line implementation in `actionmodern/date.c` to port from) and the
   **ES3 `.prototype` surface + `Function.length`** (~35 blanked tests;
   `String`/`Array`/`Number`/`Boolean` register zero prototype functions,
   and `parseInt.length` returns 0 where 2 is expected).
