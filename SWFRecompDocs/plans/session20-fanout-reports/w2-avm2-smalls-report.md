# w2-avm2-smalls — session 20 wave 2: rows 1+2 landed (+2 effective), row 3 REFUTED and dropped

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/s20-avm2smalls`, branch `s20-avm2smalls`,
base `870b48fb9`. No commits, no pushes. All runs: no-graphics, **sequential**,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose`, test dirs copied into the worktree's canonical
suite paths and `--recompile`d on first use. Patches 1 and 2 are runtime-only, so the main tree's
`SWFRecomp/build` was copied rather than rebuilt (allowed by the wave-2 rules).

## 0. DELIVERABLES AND NEW FILES (stage these by name)

There are **no new `.c` / `.h` TUs**, so `verify_output.py`'s source list, `CMakeLists` and the
Emscripten build need no edit. Every new file is a document:

    SWFRecompDocs/plans/session20-fanout-reports/w2-avm2-smalls-1-textblock.patch
    SWFRecompDocs/plans/session20-fanout-reports/w2-avm2-smalls-2-numbertostring.patch
    SWFRecompDocs/plans/session20-fanout-reports/w2-avm2-smalls-report.md

All three exist in the worktree **and** are copied to the main tree's reports dir.

| patch | file touched | lines | applies to a clean `870b48fb9` |
|---|---|---|---|
| `w2-avm2-smalls-1-textblock.patch` | `SWFModernRuntime/src/avm2/avm2_text.c` | +12 −0 | yes, alone and in either order with 2 |
| `w2-avm2-smalls-2-numbertostring.patch` | `SWFModernRuntime/src/avm2/avm2_value.c` | +26 −15 | yes, alone and in either order with 1 |

(Verified mechanically: both orders `1→2` and `2→1` apply clean to a pristine checkout of the
two files.) **`w2-avm2-smalls-3-avm1root.patch` does not exist — see §3.** The tree contains
exactly two modified tracked files and nothing else.

---

## 1. Verdicts — REAL before/after, from actual runs

| row | verdict | before | after |
|---|---|---|---|
| `avm2/textblock_recreateline` | **GO — DELIVERED, +1 effective** | `output_mismatch`, 40/180 matching (141 diff lines) | **`ruffle_matched`**, 42/180, diffs **139 ⊆ 140** |
| `avm2/number_to_string` | **GO — DELIVERED, +1 effective** | `output_mismatch`, 237/353 matching (116 diff lines) | **`ruffle_matched`**, 249/353, diffs **104 ⊆ 104** |
| `avm2/avm1_root` | **NO-GO — my own wave-1 pricing REFUTED; patch built, measured, and DROPPED** | `output_mismatch`, 12/58 matching | unchanged (reverted) |

**Net: +2 effective, 0 regressions over a 181-test sweep.**

My wave-1 substitution simulations were exact for rows 1 and 2 (predicted `139 ⊆ 140` and
`104 ⊆ 104`; measured identically) and **wrong for row 3** (predicted `ours 45`, measured `48`) —
and the direction of that error is the whole story of §3.

---

## 2. Regression sweep — 181 tests, stash-diff method, **2 rows changed, both intended**

Every group was run at base **before** any edit and again after, and compared on the full
grading fingerprint (`status`, `actual_lines`, `expected_lines`, `matching_lines`, and
`ours_diff_count ⊆ ruffle_diff_count` where applicable), i.e. a change in output *content* that
affects grading cannot hide. Never `git stash` (shared ref); the A/B was done by applying and
reverting with `git checkout --`.

| group | suite | tests | what it covers | changed |
|---|---|---|---|---|
| FTE | `avm2` | 21 | every `textblock_*` / `textline_*` / `text_element_*` / `element_format_*` / `font_description_*` / `text_engine_*` row | **1** (the intended flip) |
| NUM | `avm2` | 29 | every `number_*`, `int_*`, `uint_*`, plus `matrix3d_precision`, `matrix3d_raw_data`, `matrix3d_copy_raw_data_to`, `matrix3d_determinant`, `matrix3d_interpolate` | **1** (the intended flip) |
| AVMP | `from_avmplus` | 15 | `ecma3/Number/{e15_7_4_2_*, e15_7_4_3_*, toStringLimits, tostring_001, …}` + `ecma3/TypeConversion/{e9_8_1, e9_3_1_*}` | 0 |
| LVL | `avm2` | 3 | `avm1_root`, `mouse_pick_avm1_root`, `mouse_pick_loader_avm1` | 0 |
| MIX | `mixed_avm` | 12 | the whole suite | 0 |
| AVM1 | `avm1` | 3 | `target_path`, `remove_different_level` (+ see note) | 0 |
| AVM1B | `avm1` | 3 | `target_paths/swf4`, `/swf5`, `/swf6` (854-line `_levelN` graders; swf5/swf6 are `ruffle_matched` 200/854 on both sides) | 0 |
| REG | `regression` | 95 | **the whole project regression suite** | 0 (**95/95 pass, before and after**) |

Status totals across the sweep: base `{pass 164, ruffle_matched 8, output_mismatch 8, recomp_fail 1}`
→ post `{pass 164, ruffle_matched 10, output_mismatch 6}`. **No `pass → ruffle_matched` move
anywhere** (the regression shape rule 3 names).

*Harness note, not a result*: `--test=target_paths` names a **parent** directory whose real tests
are `target_paths/swf4|5|6`; `verify_output.py` treats the parent as a test and reports
`recomp_fail` for it. That is why the base sweep shows one `recomp_fail` and the post sweep does
not — I replaced the parent with its three children (group AVM1B) rather than carry a phantom row.
Nothing regressed.

---

## 3. Row 3 — `avm2/avm1_root`: I refuted my own wave-1 pricing. **The standing NO-GO was right.**

This is the most important thing in this report, and it is a refutation of the brief I wrote.

**What wave 1 measured (correct):** 46 raw diff lines, exactly **one** ours-only index —
`[2] _level0: undefined`, where Flash's `output.txt` and Ruffle's `output.ruffle.txt` agree and we
said `_level0`. **What wave 1 concluded (wrong):** "1-3 lines of code; gate `_level0` when level 0
holds an AVM2 movie."

**I built it, and it works — and it is a trap.** Gating the four `level 0 → root_movieclip` sites
in `action.c` on `g_avm1_under_avm2_ready` does flip the row to **`ruffle_matched` (48 ⊆ 53),
+1 effective**. But the actual-output A/B shows it changes **four** lines, not one:

```
 3  _level0: _level0                                  ->  _level0: undefined      (index 2  — GAINED, matches Flash)
13  _level0: _level0                                  ->  _level0: undefined      (index 12 — LOST,  Flash says `_level0`)
22  _level0.level0Clip: _level0.level0Clip            ->  ... undefined           (index 21 — LOST,  Flash-exact before)
24  typeof _level0.level0Clip: movieclip              ->  ... undefined           (index 23 — LOST,  Flash-exact before)
```

`matching_lines` goes **12 → 10**: three Flash-correct lines traded for one. The `+1 effective`
headline would have read "no regressions" while the row got further from Flash — precisely the
`ruffle-matched-hides-regression` trap, and precisely the trap I flagged in my own wave-1 report.

**Why no narrower gate exists.** Flash's own `output.txt` contains *both* answers, ten lines apart:

* the AVM1 child the AVM2 `Loader` inserted prints, in its frame 1,
  `this: _root`, `_parent: undefined`, **`_level0: undefined`**;
* a **second** AVM1 movie (`other_child.swf`), loaded by `MovieClipLoader` into a clip inside the
  first, prints `this: _level0.as3Loader.defined_avm1_name.child_via_mcl`, **`_level0: _level0`**,
  `_level0.as3Loader: _level0.as3Loader`, `typeof _level0.as3Loader: movieclip`, and then
  `ReferenceError #1056: Cannot create property level0Clip on Test` — i.e. by then `_level0`
  resolves **to the AVM2 root object itself**.

So the rule is temporal: `_level0` is undefined until the Loader has attached its content, and
resolves straight through the AVM2 containers afterwards. I tried two narrowing gates and
measured both:

1. `g_avm1_under_avm2_ready && g_child_swf_init` — **fails**: `g_child_swf_init` is set for *any*
   MCL/loadMovie child init, so it covers the second child too. All four lines still moved.
2. A dedicated `g_avm1u2_first_frame`, set only inside `avm1UnderAvm2RunFrame`'s `frame_idx == 0`
   pass — **also fails**: in our runtime the MCL drain for `other_child.swf` executes *nested
   inside* the first child's frame-0 pass, so the flag is still set when the second child traces.

That nesting is the cross-VM attachment-ordering difference the standing verdict named.
**s15 `w2-avm1-child-report.md` row 8, s16 `wave1-avm1-child.md` lead H and s17
`w2-crossvm-legE-report.md` are vindicated**, and the ceiling statement in
`RUFFLE_VS_FLASH_DIFFERENCES.md:462` is correct as written. The row is genuinely blocked on
cross-VM target-path/attachment timing, not on a one-line gate.

**Completion mechanism** (for whoever funds leg F/E): make the AVM1 child's own first frame run
*before* the Loader attaches its content, and the MCL drain for movies loaded *from* that child
run *after* — then `_level0` can be gated on attachment state rather than on a boot flag, and
Flash's two answers both fall out. That is the same execution-order rotation
`w2-loaders`' `mixed_avm/avm2_loads_avm1_events` needs (my wave-1 §4.1).

**Everything from row 3 was reverted** (`git checkout -- SWFModernRuntime/src/actionmodern/action.c`);
the post sweep above re-ran LVL/MIX/AVM1/AVM1B afterwards and `avm1_root` is back at its baseline
`output_mismatch` 12/58.

### A trap worth recording for anyone who revisits `action.c` from the AVM2 side

My first row-3 build produced **nine `compile_fail`s** across `mixed_avm` and `avm1` while every
`avm2` row built fine. The cause: `g_avm1_under_avm2_ready`, `avm1UnderAvm2Substrate` and
everything around them live inside a single `#ifdef SWF_AVM2` block (`action.c:24939`). A helper
*declared* above that block and *defined* inside it links fine in an AVM2 build and fails at
**link** time — not compile time — in a pure-AVM1 build. In the results JSON this reads as a
catastrophic multi-suite regression. Any future `action.c` call into that substrate needs an
`#else` stub. (Confirmed the nesting with an `awk` preprocessor-depth scan, per the standing
"read `#ifdef` nesting" note.)

---

## 4. Patch 1 — `tb_recreate_text_line` must clear `userData` and zero x/y

`SWFModernRuntime/src/avm2/avm2_text.c`, function `tb_recreate_text_line` only. +12 lines,
9 of them comment.

```c
	tl->user_data = avm2_null();
	tl->display.mtx_tx = 0;
	tl->display.mtx_ty = 0;
```

Two oracles, both named in the comment:

* **Ruffle `TextBlock.as:127`**: `textLine.userData = null;` under the comment *"Clear AS-side
  properties of the text line"*. **`null`, not `undefined`** — a freshly *created* line carries
  `undefined` (`avm2_text.c:7515`), which is why this is a distinct assignment and not a re-use of
  the create path.
* **Ruffle `TextLine::reset_properties` (`core/src/display_object/text_line.rs:92-97`)**:
  `set_x(Twips::ZERO); set_y(Twips::ZERO);` before the re-layout. A recreated line keeps its
  identity, so a stale `y` survives otherwise. In our model `x`/`y` are `ext->mtx_tx/mtx_ty`
  (twips); plain assignment is how every other site in `avm2_display.c` sets them, and there is no
  invalidation bookkeeping to run (`do_set_y`'s extra `mark_transformed_by_script` /
  `avm1movie_sync_position` work is EditText- and AVM1Movie-specific and cannot apply to a
  TextLine).

**Flash agrees with both**: `textblock_recreateline/output.txt` traces `null` for
`line2.userData` and `0` for `line2.y` immediately after `recreateTextLine`. This is not a Ruffle
chase.

**Why nothing else in the 180-line fixture moves**: `dumpInfo`, which produces every other line,
prints only `validity` / `textBlock` / `previousLine` / `nextLine`; the script re-assigns
`line2.y = 60` explicitly after each later recreate. The two `ruffle_matched` neighbours that
recreate lines hardest — `textblock_line_changes` (437/481) and `textblock_releaselines`
(748/752) — are byte-identical before and after.

---

## 5. Patch 2 — the ECMA-262 notation boundary, and a **proof** of its blast radius

`SWFModernRuntime/src/avm2/avm2_value.c`, `avm2_format_number` + `format_plain`. +26 −15.

The decision was `floor(log10(d)) < -6.0 || >= 21.0`. ECMA-262 §7.1.12.1 does not use `log10`: it
uses the decimal exponent `n` of the **shortest round-tripping** representation and takes fixed
notation iff `-6 < n <= 21`. `shortest_digits`' `exp10` is `n-1`, so the test is
`e10 < -6 || e10 > 20`. The call to `shortest_digits` is hoisted above the branch (it was already
made in *both* arms) and `format_plain` now takes the digits from the caller:

```c
-static int format_plain(char* buf, int buf_size, double d)
+static int format_plain(char* buf, int buf_size, const char* digs, int n, int e)
```

so the expensive probe loop runs **once** per format instead of twice, and `log10` disappears from
the path. (That matters: the function carries a comment saying number formatting is ~10 % of
Seedling's frame self-time. The hot integer fast path is untouched and still returns first.)

**The blast radius is proved, not sampled.** A ULP walk of ±4000 neighbours around both boundaries
plus a 600 000-value random sweep (400 k random bit patterns + structured decade sweeps) finds
that **exactly 36 doubles change branch in the entire double range**:

* the **5** representable values in `[9.99999999999999e-7, 9.999999999999997e-7]` — fixed →
  exponential (these are `number_to_string`'s 10 lines, ± sign);
* the **31** in `[9.99999999999996e+20, 9.999999999999999e+20]` — exponential → fixed (its other
  2 lines).

Nothing else moves, which is why 44 numeric corpus rows are byte-identical across the change.

Two things I checked before trusting the flip, both of which my wave-1 report listed as open risks:

* **`format_plain` can emit 21 digits.** For `digs="9999999999999999", e=20` it takes the
  `e + 1 >= n` arm and writes 16 digits + 5 zeros = `999999999999999900000`. The wave-1 worry
  ("it has never been asked to do this") is resolved: it does it correctly, and it is bounds-safe
  (`if (pos < buf_size - 1)`) regardless.
* **No caller's buffer is too small.** Every `avm2_format_number` call site passes ≥ 24 bytes
  (21 digits + sign + NUL = 23); the two 16/24-byte buffers in `avm2_globals.c:1926` and
  `avm2_flixel.c:357` use `snprintf`, not this function.
* The `1e+308` special case still fires: both special doubles have `e10 = 307 > 20`, so they stay
  in the exponential arm.

---

## 6. Refutations (carried forward from wave 1, plus two new ones)

1. **`raw / ours-only` is a SCREENING ratio, not a verdict — verify alignment before believing it.**
   It is faithful when our actual and the expectation are *aligned* at those indices and the
   differences are pure values (rows 1 and 2: simulation predicted the post-fix subset counts
   exactly). It is meaningless when our actual is *shifted* and Ruffle happens to coincide with
   Flash inside the shifted window.
2. **`mixed_avm/avm2_loads_avm1_events` (21 raw → 4 ours-only) is such an artifact.** Printed
   against Ruffle's own trace, our output is Ruffle's sequence with the child's frame 1 and its
   `child` trace transposed and `frame 2` missing before `init` — two mechanisms, both s19
   `w1-loaders` §3.3's, session-sized. It is not a four-line fix.
3. **`from_shumway/as3-loader/events/loader-events` (31 raw → 7 ours-only) likewise**: a missing
   `root loader: httpStatus 1293`, a loaded root whose default instance name is `null` instead of
   `instanceN`, and the same frame-vs-load ordering. Three mechanisms, s19 §3.4's.
4. **NEW — row 3 above.** The ours-only metric can be *right* and the pricing still wrong, when the
   fix that produces the missing line also changes lines that were already correct. **Grade a
   candidate fix by diffing ACTUAL output, not by substituting expected text.** My substitution
   simulation was exact for the two aligned rows and misled me on the one where the change
   propagates.
5. **NEW — a `+1 effective` can still be a quality regression on the same row**, not only on a
   sibling (the `verify_method_info_duplicate` precedent in `ACCEPTED_DIFFS.md` Cat 2 is about a
   sibling). Row 3 would have lost 3 Flash-exact lines to gain 1, inside one test.

### Prior verdicts these two landed patches refute (doc edits below)

* **`avm2/textblock_recreateline`** — s12 "adjudicated unflippable"; s15 `wave1-textblock.md` and
  `w2-textblock-report.md` "+1..2 correct lines, NOT a regression, no flip"; s16's board
  "cannot be reproduced locally at all". It reproduces locally and flips on 3 field assignments.
* **`avm2/number_to_string`** — s18 `w2-avmplus-numerics-report.md` §7: *"w1's H1(a) … buys 12 of
  `number_to_string`'s 116 lines and **0 flips on its own**; the other 104 need the subnormal
  Dragon4 arm."* The 104 are indices where Ruffle is also wrong, so they are free; H1(a) alone is
  the flip. The pricing counted raw diff lines against Flash and never ran the ruffle-subset check.
* **`avm2/avm1_root`** — my own wave-1 report refuted (§3); the standing verdict stands.

---

## 7. Doc edits these changes require (I made none — wave 2 ships code + report)

1. **`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`**, §"The name of
   an AVM1 root loaded by an AVM2 `Loader`" (~line 462). Keep the decision and the ceiling. **Add**
   the §3 measurement: the row is one ours-only index from `ruffle_matched`, and taking that index
   costs three Flash-exact lines, because Flash's own `output.txt` answers `_level0: undefined` in
   the child's frame 1 and `_level0: _level0` ten lines later in a second AVM1 movie — so the rule
   is temporal (attachment state), not static. Record the two gates that were built and measured as
   failures (`g_child_swf_init`; a dedicated first-frame flag) so nobody builds them a third time.
   The header's "58 expected / 46 differing lines at HEAD" is still accurate.
2. **`SWFRecompDocs/plans/polish-sweep-arc.md`**, the s20 closeout (§21): strike
   `textblock_recreateline`'s "adjudicated unflippable" and s18's "H1(a) … 0 flips on its own";
   both are now landed flips. Record row 3 as a re-confirmed NO-GO with a *measured* reason.
3. **`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md:1234**, the parenthetical that
   mentions `avm2/number_to_string` while dispositioning `number_tostring`: add that the row is
   `ruffle_matched` as of s20 and that the subnormal shortest-round-trip arm is what still keeps it
   off `pass`. (`number_tostring` itself — the Category 14 NO-GO — is untouched and unaffected.)
4. **No ignore-list edits.** `avm2/ignored_tests.txt` lists `avm1_root` in its
   upstream-`known_failure` bucket, whose own prune criterion is "prune the moment it reaches
   `pass`" — it did not, so it stays. `textblock_recreateline` and `number_to_string` are not
   listed anywhere.

---

## 8. `tab_ordering_properties` — **LANDED, `pass`** (superseded; do NOT carry into session 21)

**Corrected after merge.** This section originally nominated the row for a dedicated session-21
slot. That is obsolete: a sibling landed it earlier in session 20 as `166b2b4f4`
("seal TextField/SimpleButton"), and `avm2/tab_ordering_properties` is
`output_mismatch` (171 diff lines) → **`pass`**, +1. My merge is `476b45fdc`.

It shipped with exactly the two mechanisms diagnosed in my wave-1 report, implemented as sketched:

* `textfield->flags |= AVM2_CLASS_FLAG_SEALED;` / `button->flags |= AVM2_CLASS_FLAG_SEALED;`
* a forward-declared `obj_tab_enabled` so `io_get_tab_enabled` returns the per-type default
  instead of the raw ext field.

**Where my estimate was wrong, and the lesson.** I priced the canary at 134 tests (111 `avm2`
tests mention `TextField`, 23 mention `SimpleButton`) and held the row out of my own patch set on
that basis. The real canary was **12 tests**. The reason is a static property of AS3 that my grep
could not see: a miss on a *typed* reference (`var t:TextField; t.foo`) is a **compile** error, so
only an **untyped** receiver (`var t:*` / `Object`) can reach the sealed-object runtime path at
all. That collapses the candidate set from "every test that mentions the class" to "every test
that touches one of these classes through an untyped reference".

Holding it out was still the right call on the information I had — the sibling's argued canary is
what made it cheap, not a smaller change — but the estimate itself was conservative by an order of
magnitude. **Method note for future blast-radius pricing: when the change is to a *class-shape*
rule, filter the candidate set by what the type system lets a script actually express, not by
textual mentions of the class.** That is the same shape as this session's other two measurement
lessons — the cheap screen (grep / ours-only count) screens; the property that actually decides is
narrower.

Nothing in this family is left open on this row.

---

## 9. New unclaimed leads

* **Anything in `action.c` that calls into the AVM1-under-AVM2 substrate needs an `#else` stub**
  (§3). This is a live footgun for the leg E/F work, and it fails at link time in a way that reads
  as a nine-test multi-suite regression.
* **`format_plain` no longer re-derives the shortest digits**, so `avm2_format_number` is now one
  `shortest_digits` call plus no `log10` per non-integer format. If anyone re-measures the
  Seedling number-formatting share quoted at `avm2_value.c:686`, that number has moved.
* The three leads from my wave-1 report that this slot did not take remain open and unchanged:
  `simplebutton_childevents_multichild` (default instance-name counter, shared with
  `loader-events`), `textline_atom_index_at_char_index` (two FTE mechanisms), and
  `avm2/sound_load_multiple` (`loadCompressedDataFromByteArray` + the `#2037`/`#2084` sequencing).
