# w1-board-audit — session 14 wave-1: dual-axis board regeneration + audit

**Agent:** wave-1 `board-audit` (read-only diagnosis, main tree).
**Repo state:** `0a99be1a9` (master), clean apart from the pre-existing untracked
`SWFRecomp/tests/gpuprobe/`, `docs2/examples/`, `docs2/gpuprobe_catalog.json`.
**Baseline audited:** CI run `31130292354` at `fb36ba110`
(`mode=graphics categories=full images=true`, merged as `e62ab7471`) —
trace **4237 effective / 4427**, pixels **301/567 (53.1%)**.
**Boards audited:** `polish-sweep-arc.md` §14.3 (trace) and
`graphics-fanout-playbook.md` §12 (pixels).

Nothing was edited outside this file. 13 individual tests were run locally on
copies under the scratchpad (`--tests-dir=<scratch>`); no suite run; no
shared-tree recompile.

---

## 0. TL;DR

- **The headline number is about to move by +9 without anyone implementing
  anything.** 11 upstream tests sit on disk that the baseline run never graded
  (8 `avm1`, 3 `avm2`). I ran all 11: **3 pass + 3 ruffle_matched + 2 fail**
  (avm1) and **3 pass** (avm2). The next CI run should read
  **4246 effective / 4438**, not 4237/4427. **Any session-14 yield claim must
  be stated net of this drift**, or s14 will book +9 of upstream's work as its
  own (§2.1). This is the single most important finding in the audit.
- **The near-pass well is still closed — sixth consecutive session of zero
  refill.** 35 rows at gap ≤ 5 (s13: 36). Across s13 *not one* row moved into
  the ≤ 5 window, no row entered or left the corpus, and every gap that moved
  belongs to the describeType family. "Stop mining this window" stands (§2).
- **The board's own accounting has a systematic error: ignore-listed tests DO
  count toward the 4237 headline.** `effective_pass = pass + ruffle_matched`,
  unfiltered (`verify_output.py:3514`) — and both ignore files say so in their
  own headers. Every prior wave-1 audit (s12, s13, and my own first pass)
  subtracted the ignore-flagged near-pass rows as "excluded". **16 of the 35
  near-pass rows are ignore-flagged and every one of them is worth +1 effective
  if winnable.** The trace axis needs the same hard/soft disposition split the
  pixel axis already has (§2.2).
- **Session 13 introduced a silent gap worsening that CI's pass→fail check
  cannot see**: `avm2/all_classes/display3D/swf12` went gap 60 → **260**
  (`actual_lines` 109 → 321 against `expected_lines` 61). The expected output is
  the single line `Context3D not accessible` plus a 61-line dump; we now emit a
  full 321-line `flash.display3D` describeType dump at SWF 12, where Flash gates
  Stage3D off entirely. describeType P0-P2 **opened a version-gate hole** (§2.3).
- **Four §14.3 / §12 claims are refuted or materially misprized** (§4, §6):
  the `acid-bitmap-draw_quality ×194k` pricing (only one of the two halves is
  gradeable — the other is Ruffle `known_failure`), the "3 named beneficiaries"
  of the Equal/IncrementClamp stencil (one of the three is not in the graded
  suite at all), the blanket "filters struck from flip leads" ruling (two filter
  rows sit at 774k/821k *extra ink*, not low-amplitude residual), and the T7 P4
  slice pricing (+3/+11/+6 = 20 vs 25 live `all_classes` rows).
- **`hairline_edge_drift` really is ≥ 2 mechanisms and the split is now
  measurable** (§6.4): a 25-row AA-tie tail at ≤ 60 excess (capped), a **7-row
  morph-shape family** that is exactly the population s13's curve-subdiv
  deliberately gated out, and a large-excess head (up to 43 329) that is
  misclassified into the cluster entirely.
- **One genuinely new pixel cluster the §12 board does not name:** three
  `offset_translation` rows share an **integer 8-px translate**
  (`scroll_rect_mask` dy=8 dx=8, `cache_as_bitmap/text` dy=8 dx=0,
  `edittext_hscroll` dy=−8 dx=8). §12 frames only the first as "AVM1 scrollRect
  translate"; the shared constant says one mechanism, three beneficiaries (§7).

---

## 1. Method / provenance

**Trace.** Read the 24 merged `_results/results_graphics.json` files.
**Four are stale nested stems** frozen at older SHAs and excluded from all
counts (`from_avmplus/as3/Vector` and `.../Vector/nonindexproperty` @
`67c21aabe`; `from_gnash/misc-ming.all/displaylist_depths` and
`from_shumway/timeline` @ `6871f843e`); `from_shumway/avm1` is fresh at
`fb36ba110` but nested inside its parent and excluded as a double-count (the
`denominator` memory note). The remaining **19 top-level leaf suites** give:

```
total 4427   pass 3984   ruffle_matched 253   fail 190
effective = 3984 + 253 = 4237      <- matches the CI headline exactly
```

`results_graphics_previous.json` in every suite is `1f8396f57` (the s12
closeout), so a full gap-histogram diff **across session 13** is available; §2
uses it.

**Pixels.** `git fetch origin ruffle-image-results` — force-updated to
`ff5502cb8`, `2026-08-06 23:55:12 +0000`, which matches the baseline run's
`generated 2026-08-06T23:55:10Z`, so the PNG extract is the right one. Then:

```
git archive origin/ruffle-image-results | tar -x -C <scratch>/image-results
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 2 \
    --out <scratch>/board.json --markdown <scratch>/board.md
```

567 comparisons (566 unique — `from_shumway/avm1` double-counts one), 301 pass,
3 skip, **263 failing rows** = 7 HARD-dispositioned + 23 Ruffle `known_failure`
+ **233 rankable**; 8 SOFT trace-axis flags kept per playbook §3.

Every candidate below was cross-checked against `ruffle-tests/ignored_tests.txt`,
the per-suite `ignored_tests.txt`, and the four AVM1 disposition docs **before**
being costed.

---

## 2. Trace board — near-pass regeneration

**35 rows at gap ≤ 5** (gap = `max(expected−matching, actual−expected)`), of
which **16 carry an ignore flag** (`G` = global, `S` = suite-local). Full list:

| gap | ign | test | e/a/m | owner |
|---:|:--:|---|---|---|
| 1 | G | `avm1/native_objects_swf6` | 115/115/114 | — |
| 1 | | `avm2/mouse_pick_avm1_root` | 2/2/1 | dual-VM arc |
| 1 | | `avm2/scope_optimizations` | 4/4/3 | abc-verifier lattice (out of scope) |
| 1 | S | `avm2/verify_method_info_duplicate` | 2/1/1 | s11 hard oracle conflict |
| 1 | | `from_avmplus/recursion/pcre_find_fixedlength` | 20/20/19 | documented ceiling |
| 1 | | `from_avmplus/regress/bug_483783` | 1/0/0 | dependent-string reclamation (s10 B7) |
| 1 | | `from_shumway/as3-loader/LoaderTest2` | 7/7/6 | loader tranche 6 |
| 1 | | `from_shumway/bitmapdata/getpixel-from-embedded` | 2/2/1 | lossless decode rounding |
| 1 | | `mixed_avm/avm2_loads_avm1_loads_into_root` | 2/1/1 | dual-VM arc |
| 1 | | `mixed_avm/avm2_loads_avm1_v9` | 8/7/7 | dual-VM arc |
| 1 | | `text/links_in_scrolled_text` | 1/0/0 | input arc (wrap-aware enumerator) |
| 2 | G | `avm1/sandbox_type_remote` | 3/1/1 | — |
| 2 | S | `avm2/bitmapdata_draw_alpha_erase` | 8/8/6 | — |
| 2 | S | `avm2/loader_load` | 128/128/126 | RUFFLE_VS_FLASH (hashbrown order) |
| 2 | S | `avm2/netstream_flv_date` | 4/2/2 | host-I/O bucket |
| 2 | G | `avm2/sandbox_type_remote` | 3/1/1 | — |
| 2 | S | `avm2/sound_rootless` | 7/5/5 | host-I/O bucket |
| 2 | S | `avm2/swz` | 2/0/0 | — |
| 2 | | `from_shumway/acid/acid-morph` | 6/6/4 | s12 w2-singles: line 4 needs recompiler |
| 2 | | `mixed_avm/avm2_loads_avm1_loads_avm2_doabc` | 3/1/1 | dual-VM arc |
| 3 | G | `avm1/geturl` | 7/4/4 | — |
| 3 | S | `avm2/bom` | 9/9/6 | RUFFLE_VS_FLASH (ceiling 6/9) |
| 3 | | `from_shumway/as3-loader/LoaderLoadBytesTest` | 4/3/1 | loader tranche 6 |
| 3 | | `mixed_avm/avm2_loads_avm1_doabc` | 4/1/1 | dual-VM arc |
| 3 | | `mixed_avm/avm2_loads_avm1_v10` | 8/7/5 | dual-VM arc |
| 4 | | `audio/g711` | 6/8/2 | `computeSpectrum` audio-backend arc (s13 §4.2) |
| 4 | S | `avm2/loader_applicationDomain` | 4/0/0 | — |
| 4 | | `avm2/method_association` | 5/4/1 | abc-verifier lattice |
| 4 | S | `avm2/sound_constructor_with_args` | 6/2/2 | host-I/O bucket |
| 4 | S | `from_avmplus/ecma3/Statements/eforin_001` | 16/16/12 | **see §3.2 — both routes blocked** |
| 4 | | `mixed_avm/avm1_loads_avm2` | 7/3/3 | dual-VM arc |
| 5 | | `avm1/shared_stack` | 16/12/11 | dual-VM arc |
| 5 | | `avm2/selection_onsetfocus_mixed_avm` | 5/0/0 | dual-VM arc |
| 5 | S | `from_gnash/misc-swfc.all/sound` | 7/12/7 | host-I/O |
| 5 | S | `from_shumway/fuzz/f40458686…` | 19/19/14 | fuzz cluster (§3.1) |

**s13's hygiene bundle L8 items 1 and 3 landed**: `avm2/loader_load`,
`avm2/bom` and `avm2/verify_method_info_duplicate` are now suite-ignored (they
were the two cheapest-looking decoys in the corpus). That worked.

### 2.0 Refill across session 13 — ZERO, sixth consecutive session

Diffing `results_graphics_previous.json` (`1f8396f57`) against
`results_graphics.json` (`fb36ba110`) over all 4427 rows:

```
status transitions (excl. pass->pass):
  251  ruffle_matched -> ruffle_matched
  189  output_mismatch -> output_mismatch
    6  output_mismatch -> pass
    2  output_mismatch -> ruffle_matched
    1  runtime_error -> runtime_error
NEW failing rows absent from previous: (none)
rows present previously, gone now:      (none)
counts: prev 4427  cur 4427
```

**Not one still-failing row moved into the gap ≤ 5 window.** Every gap that
moved at all belongs to the describeType family (§2.3). Denominator identical
on both sides. The s12/s13 verdict — *the near-pass well is a closed inventory,
stop mining it* — is **CONFIRMED for a sixth session** and should be treated as
settled rather than re-verified each session.

### 2.1 Corpus drift: 11 ungraded tests, +9 free effective  ★★

`find <suite> -name test.toml` vs the graded set:

| suite | on disk | graded | ungraded |
|---|---:|---:|---|
| `avm1` | 726 | 718 | `{virtual_property,watch}_special_recursion{,_double}_swf{6,7}` (8) |
| `avm2` | 1228 | 1226 | `av_networking_params`, `av_tag_data`, `property_priority_scope_cache_order` (3) |

(`avm2/external_interface` shows as "graded, not on disk" only because its dir
carries no `test.toml`; it is graded and failing, not drift.)
All other 17 leaf suites match exactly.

I ran all 11 locally on scratch copies:

| test | status |
|---|---|
| `avm1/virtual_property_special_recursion_swf6` | **ruffle_matched** |
| `avm1/virtual_property_special_recursion_swf7` | **pass** |
| `avm1/virtual_property_special_recursion_double_swf6` | **pass** |
| `avm1/virtual_property_special_recursion_double_swf7` | **pass** |
| `avm1/watch_special_recursion_swf6` | **ruffle_matched** |
| `avm1/watch_special_recursion_swf7` | **fail** (output_mismatch) |
| `avm1/watch_special_recursion_double_swf6` | **ruffle_matched** |
| `avm1/watch_special_recursion_double_swf7` | **fail** (output_mismatch) |
| `avm2/av_networking_params` | **pass** |
| `avm2/av_tag_data` | **pass** |
| `avm2/property_priority_scope_cache_order` | **pass** |

**Projected next-run baseline: 4246 effective / 4438 (+9 effective, +11
denominator, 2 new failures).**

Consequences the coordinator must act on:

1. **State s14's yield net of +9.** Otherwise the closeout books upstream's
   work. The `baseline-postdate` and `transition-diff` memory traps are exactly
   this shape.
2. The 2 new failures (`watch_special_recursion_swf7`,
   `watch_special_recursion_double_swf7`) are **not regressions** — they are new
   arrivals, and they join a family we already fail: `avm1/watch_recursion_swf7`
   (gap 6) and `avm1/watch_recursion_double_swf7` (gap 2709) are pre-existing.
   The swf6 variants ruffle_match, the swf7 variants fail — a version-gated
   defect in `watch` re-entry (memory: `virtual-property-reentry-per-entry-model`).
   That makes it a **4-row family with one mechanism**, which is a better wave-2
   target than anything left in the near-pass window.
3. Whether CI actually picks these up depends on the download step; if the s14
   run comes back at 4427 again, the local mirror is *ahead* of CI's download
   and the drift is deferred, not cancelled.

### 2.2 The ignore-list accounting error  ★★

`verify_output.py:3514` — `"effective_pass": stats["pass"] + ruffle_matched` —
with **no ignore filtering anywhere**. Both ignore files state this explicitly
in their own headers:

> *"This moves no graded number: the headline corpus figure is the UNFILTERED
> effective_pass, and ignored tests are run and counted there either way. It
> only fixes the filtered report."* — `avm2/ignored_tests.txt` header

Yet the s12 and s13 wave-1 audits (and my own first regeneration) both reported
the near-pass window as "N rows, of which M are ignore-listed", implying the
ignore-listed ones were out of play. **They are not.** All 16 ignore-flagged
near-pass rows are worth +1 effective each if winnable, and the suite-local
lists were seeded *mechanically from directory-name prefixes before any AVM2
implementation existed* (same file header) — precisely the provenance that made
the pixel axis introduce its hard/soft split.

**Recommendation:** apply the pixel axis's hard/soft rule to the trace axis.
Hard = a disposition doc entry (unwinnable). Soft = a suite-local ignore entry
with no doc backing (still a candidate; it only affects the *filtered* report).
Under that rule the 16 flagged rows split roughly: 4 hard (`loader_load`, `bom`,
`verify_method_info_duplicate`, `eforin_001` — see §3.2), 12 soft, of which the
`avm2` host-I/O bucket (`netstream_flv_date`, `sound_rootless`,
`sound_constructor_with_args`, `swz`, `loader_applicationDomain`) is 5 rows at
gap 2–4 that nobody has costed since the bucket was seeded in 2026-07.

### 2.3 The one silent worsening across s13: a version-gate hole  ★

Only one still-failing row got materially worse, and it is a real defect:

| test | gap | e / a / m |
|---|---|---|
| `avm2/all_classes/display3D/swf12` | 60 → **260** | 61 / **109 → 321** / 1 |

`output.txt` for that test is 61 lines and opens with the single line
**`Context3D not accessible`** — Flash gates `flash.display3D` off below SWF 13.
Its siblings `swf13` (326 lines) and `swf30` (412 lines) start straight into the
`Context3D` dump. We now emit the **same 321-line dump at every version**, so
s13's describeType P0-P2 made the SWF-12 row 5× too long. CI's pass→fail check
saw nothing (it was already failing) — the `transition-diff-hides-new-crashes`
trap.

`avm2/all_classes/security/swf12` (19/3/0 vs `swf13`/`swf30` at 53/3/0) is the
mirror-image case on the under-producing side, so the version axis in
`all_classes` is wrong in both directions.

**Pricing:** one version predicate in the class-availability table. Flips
`display3D/swf12` outright is optimistic (it also needs the 61-line accessible
subset), but it is a prerequisite for *all* 25 `all_classes` rows being
gradeable and is a ~1-line change in the right place. Put it in the describeType
wave-2 brief, not a separate one.

The other three movers are benign: `avm1/global_instance_decls` 745 → **732**
(the s13 audit's +29-line flag reversed itself, `actual_lines` 815 → 786), and
`avm2/textblock_recreateline` / `avm2/all_classes/events/*` moved by ≤ 1.

---

## 3. What cluster key pays now

Both historical keys (`error_signature` Counter; "expected #NNNN got no error")
have been dry since session 5. Over the current 190 failures:

**Line-count relation** — over 48 / equal 48 / under 94. Not discriminating.

**The key that pays this session is the *replication multiplier*: how many rows
one mechanism flips.** 48 of 190 failures (25%) sit in a multi-member family
where every member fails for the same reason:

| fails / members | family | ign |
|---:|---|---|
| 6 / 6 | `avm2/all_classes/display` | — |
| 5 / 5 | `avm2/all_classes/events` | S |
| 4 / 4 | `avm1/set_property_values` (swf4-7) | — |
| 4 / 4 | `from_gnash/actionscript.all/array` (v5-v8) | S |
| 3 / 3 | `avm1/looping_child` (swf5/9/32) | — |
| 3 / 3 | `avm2/all_classes/accessibility` | — |
| 3 / 3 | `avm2/all_classes/display3D` | — |
| 3 / 3 | `avm2/all_classes/errors` | — |
| 3 / 4 | `avm2/all_classes/security` | — |
| 3 / 4 | `from_gnash/actionscript.all/MovieClip` (v6-v8) | — |
| 3 / 4 | `from_gnash/actionscript.all/TextField` (v6-v8) | — |
| 3 / 4 | `from_gnash/actionscript.all/argstest` (v6-v8) | S |
| 3 / 3 | `mixed_avm/avm2_loads_avm1` | — |
| 2 / 2 | `avm2/all_classes/xml` | — |

Add the two directory-scoped families that the name-stripping key misses:

- **`avm2` describeType family — 27 rows** (25 `all_classes` + `describe_type_metadata` + `describe_type_native`). Unchanged as the corpus's biggest single mechanism.
- **`from_gnash/misc-ming.all/action_order/` — 7 rows** (`PlaceAndRemove` 81, `ActionOrderTest3` 58, `ActionOrderTest4` 54, `ActionOrderTest5` 45, `extend_test` 25, `test6` 24, `test11` 6). The AVM1 tick-pipeline arc named in §14.3.
- **`from_shumway/fuzz/` — 16 rows** (§3.1), all suite-ignored, all headline-eligible.

Ranked by rows-per-mechanism: **describeType 27 > from_shumway/fuzz 16 >
action_order 7 > mixed_avm dual-VM 7 > from_gnash actionscript.all version
triples 13 across 4 families**. That ordering, not the near-pass window, is the
board.

### 3.1 The `from_shumway/fuzz` cluster — 16 rows nobody has looked at

30 fuzz tests: 12 pass, 2 ruffle_matched, **16 output_mismatch**. 15 of the 16
**over-produce** trace lines (`actual` > `expected`, ratio 1.1× to 2.4×; the
largest is `42f71d860e…` at 173 actual vs 71 expected). The 16th
(`f40458686…`, gap 5) produces exactly 19 for 19 with 14 matching — an ordering
difference, not over-production.

These are deliberately malformed SWFs; the expected output records how Flash
*stops* recovering. All 16 are `S`-flagged (suite-local ignore) and therefore
invisible to every board regeneration to date, yet all 16 count toward the 4237
headline (§2.2). 17 of the 31 fuzz dirs carry `known_failure = true` with an
`output.ruffle.txt`, so **`ruffle_matched` is a live second route** for those.

I did not diagnose the mechanism (that is a wave-2 deep dive) — but "16 rows,
one suite, one directory, one shared signature, never triaged" is the largest
un-owned block in the corpus after describeType. **Highest-value new wave-2
slot.**

### 3.2 `eforin_001` / `eforin_002` — a decoy, and a doc that is wrong

Both are gap ≤ 10, both suite-ignored, both look like a clean +2. I ran them:

```
eforin_002 (10 expected, 10 actual, 0 matching)
-  ...[toString]  -> +  ...[value]
-  ...[value]     -> +  ...[valueOf]
-  ...[toNumber]  -> +  ...[toString]
   (every line traces "PASSED!" — ONLY the enumeration order differs)
```

`MyObject` inserts `value, valueOf, toString, toNumber, toBoolean`.
**Our order is exactly insertion order.** avmplus's (the expected file) is
`toString, value, toNumber, toBoolean, valueOf`. Ruffle's (`output.ruffle.txt`,
present because both carry `known_failure = true`) is a *third* order:
`toBoolean, value, toString, valueOf, toNumber`.

Both routes are blocked: the avmplus route needs a port of Tamarin's
`InlineHashtable` slot layout (corpus-wide risk for every `for-in`); the
`ruffle_matched` route needs hashbrown FNV bucket order, already ruled
unreproducible. **These belong in a disposition doc, not on the board.**

**But they refute a load-bearing sentence in
`RUFFLE_VS_FLASH_DIFFERENCES.md` §"AVM2 dynamic-property enumeration order":**

> *"**We** (and Flash) enumerate in insertion order"*

`from_avmplus` **is** Adobe Tamarin's own acceptance suite — its `output.txt` is
real Flash-VM behaviour, and it is **not insertion order**. The
`loader_load` / `bom` *decisions* survive (Ruffle's expectation is still
unreproducible hashbrown order), but the stated *reason* is factually wrong and
will mislead the next reader who tries to defend insertion order as "correct".
One-paragraph correction, plus ignore-list/doc entries for `eforin_001`
and `eforin_002`.

---

## 4. §14.3 trace board — per-lead verdict at HEAD

| §14.3 lead | verdict |
|---|---|
| **T7 P3 → `describe_type_metadata`, +1** | **CONFIRMED open.** 125 exp / 36 act / 5 match (was 125/7/0 — P0-P2 improved it by 5 lines). Pricing +1 is right. |
| **T7 P4 playerglobal descriptor slices, +3/+11/+6, arc-sized; `describe_type_native` the clean pilot** | **CONFIRMED open, MISPRICED LOW.** `describe_type_native` 23/19/1. The `all_classes` family is **25 live rows**, not 20: display ×6, events ×5 (suite-ignored but headline-eligible, §2.2), display3D ×3, errors ×3, accessibility ×3, security ×3, xml ×2. Full family incl. the two `describe_type_*` = **27**. Also inherits the §2.3 version-gate hole — fold that into the same brief. |
| **AVM1 tick-pipeline arc (`test11`: per-clip EF+advance adjacency, 3 of 5 assertions)** | **CONFIRMED open.** `action_execution_order_test11` 32/32/26, gap 6. §14.3 calls it "an arc, not a rider" — agreed, and the arc is **7 rows**, not 1: `PlaceAndRemove` (96/45/15), `ActionOrderTest3` (62/73/4), `ActionOrderTest4` (64/105/10), `ActionOrderTest5` (51/58/6), `extend_test` (32/28/7), `test6` (24/20/0), `test11` (32/32/26). 5 siblings in the same dir already pass, so the machinery exists. |
| **`avm2_loads_avm1` needs AVM1-child-execution AND LocalConnection bridge (two arcs)** | **CONFIRMED.** 7 `mixed_avm` rows at gaps 1,1,2,3,3,4,13 plus `avm2/mouse_pick_avm1_root` (1), `avm2/selection_onsetfocus_mixed_avm` (5), `avm1/shared_stack` (5) — a 10-row arc. Correctly deferred. |
| **`from_shumway/acid/acid-morph` (s12 leftover)** | still 6/6/4, gap 2; line 4 still needs the recompiler change. Unchanged. |

**Not on §14.3 and worth adding:** `avm1/watch_*_special_recursion_swf7` ×2 new
(§2.1) joining `avm1/watch_recursion_swf7` + `watch_recursion_double_swf7` = a
4-row version-gated `watch` re-entry family; and the `from_shumway/fuzz` block
(§3.1).

---

## 5. Pixel board — regeneration and cluster deltas

567 comparisons, **301 pass (53.1%)**, 3 skip, 263 failing rows =
7 HARD + 23 Ruffle `known_failure` + **233 rankable**. Denominator unchanged
from s13 — **no pixel-axis corpus drift**.

Cluster totals (all failing rows, so directly comparable to s13's audit §4.1):

| cluster | s12 board | s13 board | **now** | Δ s13→s14 |
|---|---:|---:|---:|---:|
| `hairline_edge_drift` | 56 | 66 | **63** | −3 |
| `blank_render` | 53 | 50 | **45** | −5 |
| `same_geometry_wrong_fill` | 54 | 37 | **37** | 0 |
| `diffuse_mixed` | 24 | 30 | **32** | +2 |
| `halo_penumbra` | 17 | 13 | **15** | +2 |
| `missing_element` | — | — | **15** | |
| `unrelated_content` | — | — | **14** | |
| `content_displaced` | — | — | **13** | |
| `extra_element` | 30 | 14 | **9** | −5 |
| `row_banded` / `no_render` / `offset_translation` / `whole_frame_wrong` / `localized_region` / `global_color_shift` | | | 5 / 5 / 4 / 3 / 2 / 1 | |
| **total live rows** | 302 | 278 | **263** | −15 |

−15 is exactly s13's booked pixel yield, so the accounting reconciles.

Rankable band distribution (233 rows): a_epsilon 37, b_tiny 22, c_small 35,
d_moderate 63, e_large 41, f_catastrophic 30, no_render 5. **59 rankable
near-passes**, but per playbook rule 3 that number is not the board.

HARD dispositions grew 4 → **7** (s13 added the `simple_shapes/masks` pair and
`h263`); SOFT trace-axis flags steady at 8 (all `avm2`). Two dispositions are
now **stale** and the tool says so: `avm1/display_object_properties` (passes)
and `from_gnash .../loop/simple_loop_test` (all 7 frames pass). Both were on
s13's L8 hygiene list and are still unapplied — one line each.

---

## 6. §12 pixel board — per-lead verdict

### 6.1 bitmap-fill U-pinning — **CONFIRMED as a mechanism, MISPRICED as a bundle**

| comparison | cluster | excess | budget | note |
|---|---|---:|---:|---|
| `from_shumway/acid/acid-bitmap-fill [output]` | `diffuse_mixed` | **100 361** | 300 | ink IoU 0.72, edge 90%, halo 99% |
| `from_shumway/acid/acid-bitmap-draw_quality_high [output]` | `blank_render` | **194 784** | 0 | *actual is flat (1.000 one colour)*, expected 70.9% ink |
| `from_shumway/acid/acid-bitmap-draw_quality_low [output]` | `blank_render` | **194 784** | 0 | **Ruffle `known_failure` — not gradeable** |
| `from_shumway/acid/acid-bitmapData-copyPixels [output]` | `same_geometry_wrong_fill` | 53 760 | 0 | ink IoU 1.00, 8.1% repainted |

Three problems with the §12 framing:

1. **"×194k" reads as two comparisons; only one is gradeable.** `_low` is
   upstream `known_failure` — matching its PNG is explicitly not a goal
   (playbook §3). Max flip from that pair is **+1**, not +2. s13's own audit
   said this and §12 restated the doubled figure anyway.
2. **The two are different mechanisms.** `acid-bitmap-fill` is
   `diffuse_mixed` with 72% ink IoU — geometry present, wrong sampling (the
   U-pinning signature from `wave1-gfx-blend2.md` §8). `acid-bitmap-draw_quality_high`
   is `blank_render`, *flat one colour* — a missing `BitmapData.draw` backend.
   Fixing U-pinning cannot flip a flat frame. Do not put them in one brief.
3. **`acid-bitmapData-copyPixels` (53 760) is the missing fourth member** and is
   nowhere in §12. `same_geometry_wrong_fill` at ink IoU 1.00 with 8.1%
   repainted is a fill-sampling signature, i.e. the *same* lane as
   `acid-bitmap-fill`.

**Honest price: U-pinning = +1 flip likely (`acid-bitmap-fill`), +1 possible
(`copyPixels`), plus route-A relief on `acid-blend-2 output.15/26`.
`BitmapData.draw` backend = separate lead, +1 max.**

### 6.2 Equal/IncrementClamp stencil — **CONFIRMED mechanism, one beneficiary is not graded**

s13's `w2-gfx-maskC-report.md` §7 names three: `avm2/displayobject_scrollrect`,
`regression/mask_nested_intersect`, and the `cache_as_bitmap/masks` family.

- `avm2/displayobject_scrollrect` — **12 382**, `extra_element`, *"42% of our ink
  not present in expected"*. CONFIRMED, and it is now a clean single-mechanism
  pin test as the report claims.
- `regression/mask_nested_intersect` — **not in the graded suite.** The
  `regression` image results contain exactly 6 comparisons
  (`avm2_graphics_runtime`, `avm2_morph`, `avm2_timeline_gradients`,
  `avm2_timeline_solid`, `avm2_timeline_stroke_gradient`, `mask_sibling_union`)
  and this is not one of them. It contributes **0 CI comparisons**. The report
  did say "still out of the suite"; §12 dropped that qualifier.
- `cache_as_bitmap/masks` — **6 live comparisons**, output.01/03/04/05
  `same_geometry_wrong_fill` at 1690/2170/1777/1769 and output.02/06
  `halo_penumbra` at 2701/709. All `c_small`, all tolerance 0. A flip needs
  exactness, so treat these as band moves unless the fix is provably complete.

**Honest price: 1 near-certain band-to-flip (`displayobject_scrollrect`), up to
6 more that are more likely band moves. "3 named beneficiaries" is 2 graded.**

The adjacent `cab_mask_alpha` / `cab_mask_filters` / `cab_mask_transform` rows
(4644 / 4968 / 2340, all `extra_element`, all *"78–79% of our ink not present in
expected"*) share the signature and are **not named in §12** — likely riders on
the same change.

### 6.3 AVM1 scrollRect translate — **CONFIRMED and now quantified; it is a 3-row cluster** ★

`visual/simple_shapes/scroll_rect_mask` — 11 310, `offset_translation`,
**`dy=8 dx=8 removes 80% of the diff`**. Confirmed exactly as §12 states.

But the classifier puts three rows in that cluster with the *same integer
constant*:

| comparison | excess | fit |
|---|---:|---|
| `visual/cache_as_bitmap/edittext_hscroll [output.02]` | 960 | `dy=−8 dx=8` removes 85% |
| `visual/cache_as_bitmap/text [output]` | 7 410 | `dy=8 dx=0` removes 58% |
| `visual/simple_shapes/scroll_rect_mask [output]` | 11 310 | `dy=8 dx=8` removes 80% |
| `text/br_at_start [output]` | 14 411 | `dy=2 dx=2` removes 67% (different constant) |

An 8-px offset appearing three times across scrollRect, cacheAsBitmap-text and
hscroll is one composition bug, not three. **Reprice from +1 to +3 candidates,
and brief it as "the 8-px offset", not "AVM1 scrollRect".**

### 6.4 `hairline_edge_drift` is ≥ 2 mechanisms — **CONFIRMED, and the split is measurable** ★

59 rankable rows, segmented by magnitude and subject:

- **AA-tie tail, 25 rows at ≤ 60 excess.** `duplicate_font` 3, `edittext_stylesheet` 6,
  `acid-text-x` 6, `glyph` 6, `displayobject_mask` 8, `avm2_button_scroll_rect` 9,
  `match_style` 12, `acid-text-6 [frame5]` 12, `auto_size/height` 12,
  `loader_events` 16, `loader_loadbytes_events` 16, `MaskTest` 17,
  `auto_size/return` 18, blend_modes ×4, mouse_pick masks ×2, border_transform ×2,
  … Keep capped (playbook §11 fonts ruling, re-verified).
- **Morph family, 7 rows.** `from_gnash/misc-ming.all/morph_test1`
  frames 1–6 (212 / 789 / 789 / 789 / 789 / 589) + `visual/cache_as_bitmap/morph`
  (2 832). **This is exactly the population s13's curve-subdiv gated out**
  ("morph end-shape gated out — index-paired vertices would desync"). The
  §14.3 hypothesis ("splitter is large-deviation DefineShape quadratic present")
  is therefore not just plausible — the morph rows are its named, measured
  residue, and extending adaptive subdivision to morph shapes with paired
  vertex handling is a **7-comparison lead**.
- **Large-excess head, misclassified.** `visual/filters/glow_with_alpha_strength`
  **43 329**, `visual/edittext/edittext_underline_scale2` **27 656**,
  `avm2/bitmapdata_applyfilter_colormatrix` 7 419, `acid-gradient` 6 639,
  `cache_as_bitmap/drawing_api` 2 295, `edittext_underline` 1 974. A "100% on
  edges, ink IoU 1.00" verdict at 27k–43k channels is a systematic sub-pixel
  *position* error over a large ink area, not a tie. `edittext_underline` +
  `edittext_underline_scale2` are a **2-row single-mechanism family** (underline
  stroke geometry) that appears on no board.

### 6.5 Curve-joint vertex placement (`acid-blend-2 output.26`) — **CONFIRMED, +1 not +2**

`output.26` alone remains: excess **1**, max diff **127** against a 120 budget,
`same_geometry_wrong_fill`, ink IoU 1.00. `output.15` flipped in s13, so the row
is worth **+1**. Full geometry, the exact pixel, and the 25-unit headroom risk on
`output.40` are already documented in `session13-fanout-reports/wave1-gfx-blend2.md` §2 —
a wave-2 agent should read that rather than re-derive it.

### 6.6 Deblocking — **CONFIRMED, and it is the largest single comparison in the corpus**

`visual/video/deblocking [output]` — `missing_element`, excess **2 906 999**,
*"58% of expected ink absent"*. §14.3's cost (stream cap 8→16 + flags byte +
559-line deblock port) buys exactly **+1 comparison**. Worst yield-per-line on
the board; correct to leave it parked unless a video arc is opened.

### 6.7 "Filters struck from flip leads" — **PARTIALLY REFUTED**

§11/§12's ruling is that the filter family is a shared low-amplitude residual
against 0–18 budgets. True for the bevel/blur/glow near-passes. **Not true for
these two**, which sit in `extra_element` with enormous *extra* ink:

| comparison | cluster | excess | why |
|---|---|---:|---|
| `visual/filters/blur_fractional [output]` | `extra_element` | **774 090** | 77% of our ink not present in expected |
| `visual/filters/blur_quality [output]` | `extra_element` | **821 415** | 72% of our ink not present in expected |

Painting 3/4 of a frame with ink the reference does not have is a structural
defect, not an amplitude residual. Also unaccounted: the displacement-map trio
(`displacement_map_through_applyFilter` / `_through_filters` 27 565 each,
`_scales_with_screen` 99 353) all `content_displaced` with *"69% of expected ink
missing AND 49% of ours unexpected"* — a displacement-map channel/offset
mapping bug, three rows, one mechanism, on no board.

**Recommendation: keep the near-pass filter rows capped, but strike the blanket
"filters are struck" wording — it currently hides 5 structurally-wrong rows.**

### 6.8 Backends — sizes for the record

`blank_render` × Stage3D/AGAL = **25 comparisons** (excesses 85k–1.92M);
h264 = **12** (`frame2`–`frame11` + `output` + `h264_multinalu`), all
`unrelated_content`/`blank_render` in the catastrophic band. Both remain
arc-sized and correctly parked. Together they are 37 of the 233 rankable rows
(16%) — worth stating so the 53.1% figure is read correctly.

---

## 7. Ranked wave-2 board for session 14

Yield ÷ effort × confidence. **All flip counts are per-CI-run at the merged
baseline, and are stated separately from the +9 drift in §2.1.**

### Trace

| # | lead | est. | conf | effort | note |
|---|---|---|---|---|---|
| T1 | **`from_shumway/fuzz` block triage** (§3.1) | up to **+16** | MED on size, LOW on any single row | MED | 16 rows, one directory, shared over-production signature, never triaged. 17 have a Ruffle oracle → `ruffle_matched` is a second route. Biggest un-owned block in the corpus. |
| T2 | **describeType T7 P3 + P4 + the §2.3 version gate** | +1 firm, up to +27 family | HIGH | LARGE | Fold the `display3D/swf12` version predicate into the same brief — it is a prerequisite, not a separate task. |
| T3 | **`watch` re-entry swf7 family** (§2.1, §2.3) | **+4** | MED | MED | `watch_recursion_swf7`, `watch_recursion_double_swf7` (existing) + the 2 new arrivals. swf6 variants all ruffle_match, swf7 all fail — one version-gated defect. Read `virtual-property-reentry-per-entry-model` first. |
| T4 | **`action_order` 7-row family** | +2 firm, riders to +7 | MED | MED-LARGE | §14.3 already calls it an arc; the size (7, not 1) justifies a dedicated slot. |
| T5 | **avm2 host-I/O bucket re-triage** (§2.2) | up to **+5** | LOW-MED | SMALL | `netstream_flv_date` (2), `sound_rootless` (2), `sound_constructor_with_args` (4), `swz` (2), `loader_applicationDomain` (4). Suite-ignored on a 2026-07 mechanical prefix rule, never re-costed, all headline-eligible. Cheapest unexplored trace surface. |
| T6 | **hygiene bundle** | 0 flips | HIGH | XS | (a) `eforin_001`/`eforin_002` disposition + the RUFFLE_VS_FLASH correction (§3.2); (b) the two stale image dispositions (§5); (c) `avm2/dependent_strings` (s13 L8 item 2, still undocumented); (d) `verify_method_info_oob` (s12/s13 rec, still unlisted); (e) a one-paragraph note in `polish-sweep-arc.md` §0 that ignore-listed rows count toward the headline (§2.2). |

**Remove from the roster:** the near-pass window as a source. Sixth session of
zero refill; every unflagged row in §2 is arc-owned or disposition-owned.

### Pixels

| # | lead | est. | conf | effort | note |
|---|---|---|---|---|---|
| P1 | **Morph curve subdivision** (§6.4) | **+7 candidates** | MED | MED | `morph_test1` frames 1–6 + `cache_as_bitmap/morph`. Directly extends s13's shipped adaptive subdivision to the population it gated out; the design constraint (index-paired vertices must not desync) is already written down in `w2-curve-subdiv-report.md`. Best yield-per-effort on the pixel axis. |
| P2 | **The 8-px offset** (§6.3) | **+3 candidates** | MED | SMALL-MED | `scroll_rect_mask`, `cache_as_bitmap/text`, `edittext_hscroll [output.02]`. One integer constant, three rows. §12 lists only the first. |
| P3 | **bitmap-fill U-pinning** (§6.1) | +1 firm, +1 rider | HIGH | MED | `acid-bitmap-fill` (+ `acid-bitmapData-copyPixels` as rider). **Split `acid-bitmap-draw_quality_high` out into its own `BitmapData.draw` backend item — it is `blank_render`, a different defect, and `_low` is not gradeable.** |
| P4 | **Equal/IncrementClamp stencil** (§6.2) | +1 firm, up to +6 band moves | MED | MED | `displayobject_scrollrect` is the pin test; `cache_as_bitmap/masks` ×6 and `cab_mask_*` ×3 are riders. Note `regression/mask_nested_intersect` is **not graded** — do not count it. |
| P5 | **`acid-blend-2 output.26`** (§6.5) | **+1** | HIGH | SMALL | Fully diagnosed already; watch the 25-unit headroom on `output.40`. |
| P6 | **displacement-map trio** (§6.7) | +3 candidates | LOW-MED | MED | Not on any board. `content_displaced`, 69%/49% ink mismatch, three rows one mechanism. |
| P7 | **`edittext_underline` pair** (§6.4) | +2 candidates | LOW-MED | SMALL-MED | 1 974 / 27 656, hairline-misclassified, one stroke-geometry mechanism. |

**Remove from the roster:** deblocking (§6.6 — +1 for a 559-line port), Stage3D
(25 comparisons, arc), h264 (12, arc). **Correct on the board rather than
re-brief:** the "filters struck" blanket ruling (§6.7).

---

## 8. Reproduction

```bash
S=<scratch>/board-audit

# trace: dedup'd corpus + near-pass + gap-histogram diff vs previous
#   scripts: $S/nearpass.py, $S/gapdiff.py
#   19 top-level leaf suites; excluded stale nested stems
#   from_avmplus/as3/Vector{,/nonindexproperty}, from_gnash/misc-ming.all/
#   displaylist_depths, from_shumway/timeline; and the from_shumway/avm1
#   double-count.

# corpus drift
find ruffle-tests/tests/swfs/<suite> -name test.toml | wc -l   # vs results total

# pixels
git fetch origin ruffle-image-results                # -> ff5502cb8, 2026-08-06 23:55Z
git archive origin/ruffle-image-results | tar -x -C $S/image-results
python3 scripts/image_triage.py --images-dir $S/image-results --jobs 2 \
    --out $S/board.json --markdown $S/board.md
# NOTE: board.json contains ALL 263 failing rows; HARD dispositions are marked
# by the `dispositioned` key (NOT `disposition`) and `known_failure`. Filtering
# on the wrong key silently re-admits 7 dispositioned rows.

# per-test probes, on COPIES under $S/probe (never the shared tree)
python3 ruffle-tests/verify_output.py --tests-dir=$S/probe/<dir> --test=<name> --diff
```

Tests run locally this session (13): `from_avmplus/ecma3/Statements/{eforin_001,
eforin_002}`; `avm1/{virtual_property_special_recursion_swf6, _swf7,
_double_swf6, _double_swf7, watch_special_recursion_swf6, _swf7, _double_swf6,
_double_swf7}`; `avm2/{av_networking_params, av_tag_data,
property_priority_scope_cache_order}`. All on scratch copies; parallelism capped
at 2.
