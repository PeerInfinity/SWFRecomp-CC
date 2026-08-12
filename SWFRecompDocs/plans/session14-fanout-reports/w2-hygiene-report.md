# w2-hygiene — session 14 wave-2: docs / dispositions bundle

**Agent:** wave-2 `hygiene` (docs + list files only, isolated worktree).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a867fd216db8f87c1`
**Base:** fast-forwarded from `0a99be1a9` to **`1ee23314e`** (current master tip,
i.e. after the seven merged s14 wave-2 patches) *before* editing, so
`wave2/w2-hygiene.patch` is a diff vs `1ee23314e` and cannot conflict with a
sibling's already-merged edits to the same disposition files. Three of those
siblings (`w2-host-io`, `w2-watch-family`, `w2-gfx-stencil`) had already touched
`ACCEPTED_DIFFS.md` / the ignore lists.

**No code changes.** Six files touched, all docs or list files:

| file | items |
|---|---|
| `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | 3, 4, 6, 9 |
| `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | 2 |
| `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md` | 4 |
| `ruffle-tests/tests/swfs/from_gnash/_investigation/incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | 8 |
| `SWFRecompDocs/plans/polish-sweep-arc.md` | 7 |
| `ruffle-tests/tests/swfs/from_avmplus/ignored_tests.txt` | 1 (precision fix only) |

Every claim was verified against the merged baseline results files
(`fb36ba110`, CI run `31130292354`) or the tool's own resolver. No suite run, no
CI dispatch, no local test run needed.

---

## Per-item ledger

### 1. `eforin_001` / `eforin_002` disposition — **SKIPPED, already done** (not by a sibling — by session 13)

- `ACCEPTED_DIFFS.md` **Category 12: Implementation-Defined `for...in`
  Enumeration Order** already carries both tests with the full three-way order
  table, the "why `ruffle_matched` cannot rescue these" argument, and the
  decision (`ACCEPTED_DIFFS.md:912`, entries at `:926` and `:954`; summary-table
  rows at `:1087`–`:1088`). It predates `0a99be1a9`.
- Both are listed in `ruffle-tests/tests/swfs/from_avmplus/ignored_tests.txt:20-21`.
- **Deliberately NOT added to the global `ruffle-tests/ignored_tests.txt`.** The
  brief cited CLAUDE.md's "also add it to `ruffle-tests/ignored_tests.txt`"
  rule, but that file's own header (trap 1, `ignored_tests.txt:15-23`) says a
  GLOBAL entry is *also* an image-axis disposition — `image_triage.py` returns
  `image_axis=True` for `test in ignored_global`. Neither eforin test has an
  `[[image_comparisons]]` block, so a global entry buys nothing and mislabels
  the pixel board. Suite-local is the correct home and is where the corpus has
  put every AVM2-side entry of this shape (`loader_load`, `bom`,
  `dependent_strings`, `verify_method_info_duplicate`).
- **One real defect found and fixed** (`from_avmplus/ignored_tests.txt:18-21`):
  the list header claimed "Ours is insertion order (the ES2015+ rule)" for both
  tests. That is true of `eforin_002` but not `eforin_001`, where our order is
  integer-like keys first (`0, year, company, length`). Rewritten, plus the
  same "avmplus IS the Flash VM, do not call ours Flash-matching" warning as
  item 2.

### 2. `RUFFLE_VS_FLASH_DIFFERENCES.md` enumeration-order correction — **EDITED**

`RUFFLE_VS_FLASH_DIFFERENCES.md:315` — the bullet now reads "**We** enumerate in
insertion order" (the "(and Flash)" parenthesis struck), followed by a dated
correction block at `:319-336`:

- states that `from_avmplus` *is* Adobe Tamarin's acceptance suite, so its
  `output.txt` records real Flash-VM order, and cites `eforin_002`
  (`value, valueOf, toString, toNumber, toBoolean` in → `toString, value,
  toNumber, toBoolean, valueOf` expected) as the counter-example;
- names `InlineHashtable` slot/bucket layout as what the avmplus order actually
  is, and points at Category 12 for the three-way table;
- **preserves both DECISIONS verbatim** (`loader_load` 126/128 ceiling, `bom`
  6/9 ceiling, keep insertion order, suite-local ignore) and restates the reason
  as "ES2015+ rule for string keys + no player's hash layout is reproducible",
  with an explicit "do not defend it as Flash-matching again".

### 3. Category 9 — `visual/video/deblocking` entry + `netstream_play_flv` figures — **EDITED**

- **New entry** `ACCEPTED_DIFFS.md:594-640`, heading
  `### \`visual/video/deblocking\` — Spark IDCT precision, one Cb level on one
  chroma row (104 outlier channels, max 4)` with the image-axis scope marker
  `<!-- image-axis: visual/video/deblocking output -->` at `:596`. Body carries
  the deblock report's §3.2/§3a evidence: 2 906 999 → 104 channels, max 255 → 4,
  mean 56.2435 → 0.0000, 11/12 streams byte-exact; all 104 in stream 9 on chroma
  row 232; one Cb level (R still, G ±1 on four channels, B ±2/±4); the
  no-remainder-lane proof (496/8 and 248/8 both exact) that rules out a
  filter-lane bug; PQUANT 2 / 13 305-byte payload as the corroborating "most
  IDCT rounding surface" detail. Decision: accept, capped with `h263`; no ignore
  list (trace passes); standing scope invariant on the single `output`
  comparison. The report's two riders (`Video-EmbedSquareTest` misfiled as
  video; `h264{,_multinalu}` a decoder arc) are named as explicitly **not**
  dispositioned.
- **Retired** the old `**Explicitly NOT dispositioned:** visual/video/deblocking
  is live work…` paragraph (was `ACCEPTED_DIFFS.md:588-592`); the new entry says
  in its "Superseded note" what replaced it and why.
- **`netstream_play_flv` restated**: heading at `:643` now reads
  "(44 outliers, max diff 3)"; body `:653-676` replaces the single-paragraph
  two-term story with a three-row measurement table
  (~52 000/64 → 1 654/8 at `fb36ba110` → **44/3** post-deblock) and names the
  missing deblocking filter as the second term that had been hiding inside the
  "IDCT precision" label. Residual restated as 93×1 + 42×2 + 2×3 in a 58×57
  region = the GPU sample-stretch. A parenthetical flags 44/3 as a local Dawn
  measurement to be re-baselined from the first `images=true` CI run carrying
  the deblock patch.
- The `visual/video/colorconversion/h263` entry (`:557`) was **left untouched**
  per the report: that stream sets `VideoDeblocking::None`.

Resolver check (`scripts/image_triage.py::Dispositions`, run against the edited
docs): `visual/video/deblocking [output]` → `hard=True` with
`[image-axis SCOPE: visual/video/deblocking output]`; `h263` unchanged;
`from_gnash …/Video-EmbedSquareTest [frame1]` and `visual/video/h264 [output]`
still `(None, None, False)` — the new prose did not accidentally disposition
either rider.

### 4. The two stale image dispositions (board-audit §5) — **VERIFIED; §5's "unapplied" half REFUTED; citations refreshed**

Board-audit §5 says both "were on s13's L8 hygiene list and are still
unapplied — one line each". Checked: **both were applied by s13's hygiene pass**
(`session13-fanout-reports/w2-hygiene-report.md` §8). What was actually stale was
only the *baseline citation* (s13 cited `1f8396f57` / run `31090651530`).

Re-measured at the current baseline `fb36ba110` / run `31130292354`:

| row | measured | file:line |
|---|---|---|
| `avm1/display_object_properties [output]` | `pass`, outliers 0 (max_diff 79, 724 diff_channels, all in tolerance) | `avm1/_investigation/ACCEPTED_DIFFS.md:818-827` |
| `from_gnash …/loop/simple_loop_test [frame1…frame7]` | all 7 `pass`, outliers 0, max_diff 0 | `from_gnash/_investigation/ACCEPTED_DIFFS.md:687-694` |

Both entries got a dated re-confirmation paragraph that also records the
refutation, and (for the avm1 one) a note that `image_triage.py` listing them
under "DISPOSITIONED BUT NOT FAILING" is the tool working as designed, not an
outstanding edit. The `<!-- image-axis: frames 1-2 only -->` scope marker on
`simple_loop_test` was **kept** (s13's reasoning: a future frame-3 failure must
still classify as live work) — verified still resolving `frame1 → hard`,
`frame3 → None`.

### 5. `avm2/dependent_strings` — **SKIPPED, already documented** (s13, 2026-08-06)

Status at baseline: `output_mismatch` (unchanged). Its disposition is
`RUFFLE_VS_FLASH_DIFFERENCES.md` §"Ruffle-internal rope-string introspection:
`ruffle::isDependent()`" (`:401-456`), with `<!-- image-axis: none -->`, the
`__ruffle__` namespace analysis, the "Flash would print the same blank lines"
argument, and the decision — plus the suite-local listing at
`avm2/ignored_tests.txt:143` with an eight-line rationale comment at `:129-135`.
Resolver returns `TRACE-AXIS ENTRY, kept on the board`, which is correct: no
`[[image_comparisons]]` block. Nothing to add. (`polish-sweep-arc.md` §14 does
not name a further mechanism for it.)

### 6. `verify_method_info_oob` — **VERIFIED; recommendation refuted for the third time; one line added**

Status at baseline `fb36ba110`: **`pass`**. Listing a passing test in an ignore
list hides a win (the 2026-08-01 prune criterion), so it must not be listed —
this is the same conclusion s13 reached. It is already documented in the two
places that matter: `ACCEPTED_DIFFS.md` Category 2 entry for the *sibling*
`avm2/verify_method_info_duplicate` (`:114-165`) and the standing NOTE beside
that entry in `avm2/ignored_tests.txt:136-141`.

Added at `ACCEPTED_DIFFS.md:159-165`: the s14 re-verification (`_oob` pass,
`_duplicate` output_mismatch 1/2, both unchanged) and an explicit "raised in
three sessions, refuted in all three" so the fourth session does not re-cost it.

### 7. `polish-sweep-arc.md` §0 note — **EDITED**

New subsection `### 0.1 Ignore-listed tests still count — hard vs soft on the
trace axis ★★` at `polish-sweep-arc.md:51-77`, citing board-audit §2.2. It
states: `verify_output.py:3514` computes `effective_pass = pass +
ruffle_matched` with no ignore filtering; both ignore files say so in their own
headers (header quoted); an ignore-listed near-pass is worth the same +1 as any
other row (16 of 35 at s14); and the trace axis now adopts the pixel axis's
hard/soft split — **hard** = disposition-doc-backed (drop from the board),
**soft** = suite-local list entry with no doc backing (still a candidate, only
affects the filtered report), with the "seeded mechanically from directory-name
prefixes" provenance that motivated the split.

### 8. `SPRITE_EXEC_LIST_LIFO_PLAN.md` stale figures — **EDITED**

Verified from `from_gnash/misc-ming.all/_results/results_graphics.json` at
`fb36ba110`: `action_execution_order_test5` = **pass 35/35**;
`action_execution_order_test11` = **output_mismatch, 26/32** (6 lines differ,
actual 32 / expected 32). The doc claimed test5 26/35 and test11 27/32 (the
latter a local 2026-05-08 measurement never reconciled with CI).

- `:3` — `<!-- TESTS: -->` now lists only `action_execution_order_test11`.
- `:4-8` — test5 moved into the `PROMOTED` block with its PASS 35/35 evidence.
- `:9-19` — residual comment refreshed with both correct figures, an explicit
  note that the old header figures were stale, and a **CURRENT DIAGNOSIS OF
  RECORD** pointer to
  `SWFRecompDocs/plans/session14-fanout-reports/wave1-avm1-tick.md` (D1/D2
  split, +1 ceiling, DEFER recommendation) with "read it before reopening this
  plan; the sections below are 2026-05 history".
- `:76-80` — the "Affected tests (CI 91a39c2c)" table relabelled *historical
  snapshot* with a three-test current-status line above it.

The 2026-05 "Test deltas" tables further down were left intact: they are dated
measurement records, not current-status claims.

### 9. Summary-table updates — **DONE**

`ACCEPTED_DIFFS.md` summary table (avm1):

- `:1079` `netstream_play_flv` — magnitude column now "**44** image outliers,
  max diff **3** (was ~52k/64, then 1654/8)", decision column records both
  mechanism corrections (colour half 2026-08-06, deblock half 2026-08-12).
- `:1080` **new row** `visual/video/deblocking` — 104 channels / max 4 / mean
  0.0 (was 2 906 999 / 255), image-axis-only, with the one-Cb-level-on-stream-9
  summary.
- No other rows needed changes: items 1, 5 and 6 added no new dispositioned
  tests, and item 4's rows were already struck-through/annotated.

---

## Not touched, deliberately

| item | reason |
|---|---|
| Category 10 / `watch_*` entries | resolved by the merged `w2-watch-family` patch (brief) |
| `from_shumway/fuzz/*` rows | owned by the fuzz-triage agent (brief) |
| `visual/video/colorconversion/h263` entry | deblock report §6.1: that stream is `VideoDeblocking::None`; its residual really is IDCT precision and this patch must not move it |
| global `ruffle-tests/ignored_tests.txt` | no entry added — see item 1; every test in this bundle either passes, has no image comparison, or is already suite-local-listed |
| `graphics-fanout-playbook.md` §12 / `polish-sweep-arc.md` §14.3 board rows | coordinator owns board errata; §0.1 is a method note, not a board edit |
| any C/C++/Python source | none needed |

## Verification commands used

```bash
# statuses and image comparisons, from the merged baseline results files
python3 <scratch>/chk.py     # image_results_graphics.json rows
python3 <scratch>/chk2.py    # results_graphics.json statuses
python3 <scratch>/chk3.py    # test5 / test11 line counts

# disposition resolution against the EDITED docs, using image_triage's own class
python3 <scratch>/disp.py    # Dispositions(swfs_root, ruffle_root).lookup(...)
```

All four scripts live in the session scratchpad, read-only against the worktree.
