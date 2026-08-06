# w2-textblock — implementation report (session 12, wave 2)

Agent: `w2-textblock`. Base HEAD `f166e424e`. Worktree
`.claude/worktrees/agent-a34b2af2c436fac0d`. **No commits, no pushes, no full
suites.** Spec: `wave1-trace-triage.md` §T4.

Deliverable: `w2-textblock.patch` — one file
(`SWFModernRuntime/src/avm2/avm2_text.c`, +49/−5), runtime-only, no recompiler
change.

---

## Headline

| | before | after |
|---|---|---|
| `avm2/textblock_line_changes` | `output_mismatch`, **116** lines differ | **`ruffle_matched`** ✅ |
| `avm2/textblock_recreateline` | `output_mismatch`, 58 differ | `output_mismatch`, 60 differ (see §5) |
| 9 FTE canaries | PASS | PASS |

**+1 effective pass.** Both targets are `known_failure = true` upstream, so
`ruffle_matched` is the ceiling for them (the `w2-b9-fonts` precedent).

---

## 1. The bisect: **there is no culprit commit — the "regression" is corpus drift**

The mission was to bisect s11's nine commits for the one that moved
`textblock_line_changes` from gap 33 to gap 116. **No s11 commit did.** The
answer is visible directly in the two baselines, so no bisect was needed:

| results file at HEAD `f166e424e` | run sha | timestamp | this test |
|---|---|---|---|
| `avm2/_results/results_graphics_previous.json` | `c4496a4c8` | 2026-08-01 | `actual 158 / expected **158** / matching 125` → 33 differ |
| `avm2/_results/results_graphics.json` | `6de650432` | 2026-08-06 | `actual 222 / expected **282** / matching 166` → 116 differ |

**`expected_lines` went 158 → 282.** The expected output is not something our
code can move — the *test itself grew*. Between the two CI runs, upstream Ruffle
rewrote `tests/tests/swfs/avm2/textblock_line_changes`: `Test.as`, `test.swf`,
`output.txt` and `output.ruffle.txt` all changed. The new version adds a
`Last line in block:` trace to every dump, a sixth paragraph of content, a
`line4.validity = "static"` step, a five-call *reset* sequence, a sixth line,
and two more dumps — ten dumps instead of six.

So `textblock_line_changes` was **never a fail→fail regression**. It is
`ruffle-test-download-sync` drift, and it is a *third* member of the
`transition-diff-hides-new-crashes` family, with a new twist worth recording:

> **A gap-histogram diff cannot distinguish "we got worse" from "the test got
> bigger". Diff `expected_lines` too — if the denominator moved, the corpus
> moved, not the code.**

Wave-1's §0 table is correct about the number and right to flag it; only the
attribution ("got materially worse during s11's text/font work", "a regression
in everything but the status field") is wrong. The four other rows in that table
moved the *good* way and are genuine.

### Consequence: the local corpus is stale, and local triage silently lies

CI re-downloads the corpus every run; the working tree does not. At HEAD the
main tree still holds the **158-line** version of this test, so
`verify_output.py --test=textblock_line_changes` locally scores 33 differ while
CI scores 116 — the same binary, two different tests, no warning. Anyone
"verifying at HEAD" locally would have confirmed the stale number and concluded
the CI board was wrong.

I re-synced 11 FTE test directories from upstream inside my worktree. **Only two
had drifted**, both silently:

| test | drifted files |
|---|---|
| `avm2/textblock_line_changes` | `Test.as`, `test.swf`, `output.txt` (158→282), `output.ruffle.txt` |
| `avm2/textblock_recreateline` | `output.ruffle.txt` only (Ruffle fixed its own `firstLine`) |

**Recommended chore for whoever merges this wave** (main tree, not mine to
touch): re-run `ruffle-tests/download_tests.sh avm2` (or at minimum re-sync
those two directories) so local triage matches CI. All numbers in this report
are measured against the **fresh** corpus, i.e. what CI will actually run.

---

## 2. What the new test grades, and the target that mattered

`ruffle_matched` is **not** an exact match against `output.ruffle.txt`. It is a
subset test over *line indices*: promote when the set of lines where we differ
from Flash's `output.txt` is a subset of the set where **Ruffle** differs from
the same file (`verify_output.py:3277 ruffle_subset_match`). On the new
282-line test Ruffle differs at **42** indices — all ten `Last line in block:`
lines plus the post-recreate chain. Every one of the ten `First line in block:`
lines is **not** in that set, so Ruffle now gets `firstLine` right and we had to
as well.

Working backwards from that 42-index budget gave three rules, all of which the
Flash oracle and `output.ruffle.txt` agree on:

**Rule A — `validity = "static"` releases the line from its block.**
`TextLineValidity.STATIC` means "still valid, but the TextBlock no longer holds
a reference to it", so the transition *into* `"static"` nulls `textBlock`. Only
the exact string `"static"`; `"invalid"` and arbitrary user strings leave the
back-edge alone (the new fixture grades both arms). 6 lines on the old test,
more on the new.

**Rule B — `recreateTextLine` re-runs creation in place.** It returns the *same*
TextLine (identity is load-bearing for text layout modules), and:
* resets `validity = "valid"` and `textBlock = this` — whatever the line was
  before, including released;
* `previousLine = arg`, and `arg.nextLine = textLine`;
* `nextLine = null` (the line that used to follow keeps its now-stale
  `previousLine`, exactly as FP leaves it);
* `specifiedWidth = width`;
* argument taxonomy is `createTextLine`'s — null `textLine`, a `previousLine`
  that is not valid or belongs to another block, and an out-of-range width all
  raise **#2004 through `Error.throwError`**.

The validity/`textBlock` reset is not cosmetic: the new test's reset sequence
recreates five released lines in a row and **each one is the next call's
`previousLine`**, so without the reset the chain trips its own #2004 check and
the run dies at expected line 192.

**Rule C — `firstLine` is the HEAD of the chain, not the newest line.** We were
assigning `tb->first_line` on every `createTextLine`. Only a creation (or
recreation) with a **null** `previousLine` starts a new chain and re-seats it.
This reproduces all ten graded values, including the two `line-unknown` dumps
where a null-prev `createTextLine` displaces the original head, and the return
to `line-0` after the reset sequence. `lastLine` stays aliased to `firstLine`
(Ruffle's stub) — all ten of its lines are inside Ruffle's diff set, so they are
free.

---

## 3. Files and lines

`SWFModernRuntime/src/avm2/avm2_text.c` only, +49/−5, three hunks:

| hunk | ~line | rule |
|---|---|---|
| `tl_set_validity` | 6835 | A — `if (str_is(s, "static")) tl->text_block = NULL;` |
| `tb_do_create_text_line` tail | 7268 | C — `if (pl == NULL) tb->first_line = line;` |
| `tb_recreate_text_line` | 7309–7346 | B — full rewrite (was a 4-line stub) |

All three are inside the TextBlock/TextLine region and additive; no
reformatting, no new file-scope symbols, no header change. **Sibling collision
check:** `w2-avclasses` (~6126), `w2-singles` (~8142) and `w2-gfx-autosize`
(~3892) are all clear of 6835 and 7268–7346. The only shared helper touched is
the pre-existing local `tb_throw_2004_via_throwerror` (7183), which I call but
do not modify — no `avm2_error.c` edit, so **no serialization needed with the T1
agents**.

---

## 4. Per-test ledger

Measured locally, no-graphics, on the **freshly synced** corpus, `--recompile`
on every run (the sync invalidated all `RecompiledABC/` caches). Before-state
produced by reverting the patch and re-running the identical sweep
(`stash-diff-sweep`).

| test | before | after | Δ |
|---|---|---|---|
| **`avm2/textblock_line_changes`** | `output_mismatch` 116 differ | **`ruffle_matched`** | **+1 effective** |
| `avm2/textblock_recreateline` | `output_mismatch` 58 differ | `output_mismatch` 60 differ | see §5 |
| `avm2/textblock_createline_errors` | PASS | PASS | — |
| `avm2/textblock_createline_fte` | PASS | PASS | — |
| `avm2/textblock_properties` | PASS | PASS | — |
| `avm2/textline_validity` | PASS | PASS | — |
| `avm2/textline_name` | PASS | PASS | — |
| `avm2/textline_splitting_basic` | PASS | PASS | — |
| `avm2/textline_inapplicable_properties` | PASS | PASS | — |
| `avm2/textline_throwerror` | PASS | PASS | — |
| `avm2/content_element_basic` | PASS | PASS | — |

`textline_throwerror`, `textblock_createline_errors` and `content_element_basic`
are three of T1's six named must-not-move passes; all three stay green with the
new `Error$/throwError()` push inside `recreateTextLine`.

**No canary comes from a "culprit commit ledger", because there is no culprit
commit** (§1). The s11 flips are structurally out of reach instead: the only s11
commit that touched `avm2_text.c` was `730a3db4d` (w2-b9-fonts, device-font TTF
plumbing), whose four flips (`fonts/device_font_{kerning,glyph_fallback,list}`,
`visual/edittext/edittext_device_transform_basic`) live in the device-font
registry and EditText layout paths. My three hunks touch only
`Avm2TextLineExt`/`Avm2TextBlockExt` bookkeeping and share no symbol, struct
field or call site with them.

**Blast radius is fully enumerated.** `tl->text_block` is read at exactly two
places (`tl_get_text_block`, the `createTextLine` #2004 check); `tb->first_line`
at two (`tb_get_first_line`, backing both `firstLine` and `lastLine`, and
`tb_release_lines`). Grepping the whole corpus for `TextBlock|TextLine` in
`*.as` returns 18 files, of which 4 are the unrelated `flash.text.TextLineMetrics`
class, 3 are `visual/edittext/edittext_device_transform_*` (which mention
neither `validity`, `recreateTextLine` nor `firstLine`), and 1 is
`avm2/abstract_classes` (constructor-throws only). **The 11 tests in the ledger
are the complete set.**

---

## 5. `textblock_recreateline`: 58 → 60 diff lines, and why that is not a loss

Semantically it improved a lot — `specifiedWidth` now reports 1200, `firstLine`
now reports `line-0` in both dumps, and all four graded `#2004` stack traces are
emitted with their `Error$/throwError()` frame (before: only two, each missing
the frame). That is 10 more correct lines of content.

The raw count still went up 2, because of a **positional shift** that pre-dates
this patch. `recreateTextLine` in Flash resets the TextLine's *DisplayObject*
state — `y` back to 0, children removed, **event listeners removed**, and 15
visual properties (`blendMode`, `alpha`, `mask`, the scales/rotations,
`visible`, `cacheAsBitmap`, `opaqueBackground`, `z`, `userData`). We reset none
of it, so the test's second `dispatchEvent` still fires and emits one extra
`Event listener called` line, which slides every following line by one. Before,
our output was 89 lines (10 short at the tail); now it is 99 against 98 expected
(1 long). Classic `results-diff-line-metrics-mislead`.

**This test cannot pass** either way: lines 32–35 want `atomCount`/
`rawTextLength` of 18 and `ascent`/`descent` of `8.3203125`/`2.58984375`, i.e.
the recreated line's *own* substring length and real embedded-font metrics.
Our TextLine metrics are the constants 12/3 (`tl_const_12`/`tl_const_3`,
deliberate — `avm2_text.c:6851`). And `ruffle_matched` is out of reach too, for
the opposite reason: Ruffle reports `numChildren == 0` where Flash and we both
report 1, so Ruffle's diff set does not contain that index and we would have to
*break* a Flash-correct behaviour to become a subset of it.

I deliberately stopped short of the DisplayObject reset: it needs positional and
child/listener mutators that `avm2_text.c` does not import, so it means editing
`avm2_display.c` for a test that cannot flip. **Well-specified follow-up, worth
~40 diff lines on one already-failing test — low priority.**

---

## 6. Predicted CI flips

Run `graphics`, `categories=full` (AVM2 runtime), `images=false`.

* **`avm2/textblock_line_changes`: `output_mismatch` → `ruffle_matched`.** +1
  effective pass; corpus `4204 → 4205`.
* `avm2/textblock_recreateline`: stays `output_mismatch`; its `matching_lines`
  will move 40 → 38 out of 98. **No status change.** Flagged here so the next
  board does not re-file it as a regression.
* Everything else: unchanged. Mode parity is complete and this patch has no
  `#ifdef` arms, so no-graphics is expected identical.

**Do not** expect the local 116→0 number to appear as a *gap* improvement unless
CI's corpus still holds the 282-line test — it will, since CI downloads fresh.

---

## 7. Risks

1. **Rule A is a behavioural change to a public setter.** Any code that sets
   `validity = "static"` and then reads `textBlock` sees `null`. Both oracles
   agree, and `textline_validity` (the 162-line validity state-machine test)
   sets `"static"` and stays green.
2. **Rule C changes what `firstLine` *and* `lastLine` return** (they share a
   getter). `textblock_createline_fte` grades `firstLine === line` and
   `textblock_properties` grades both on an empty block; both stay green.
   `tb_release_lines` compares against `tb->first_line` and is now comparing
   against the real head — strictly more correct, and no corpus test calls
   `releaseLines`.
3. **Rule B adds three throw sites that did not throw before.** Only two tests
   in the corpus call `recreateTextLine` and both are in the ledger.
4. **The local corpus is stale** (§1). Anyone re-verifying these numbers must
   sync first or they will measure the 158-line test.

## 8. Dispositions

Nothing here belongs in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md` or
`FLASH_BUGS_REPLICATED.md` — every rule matches Flash's own output, and
`textblock_line_changes` reaching `ruffle_matched` is the ordinary upstream-
`known_failure` outcome the harness already models. Neither target is in any
`ignored_tests.txt`.

Two board-hygiene items for the session closeout:

* Add to the pipeline handoff, next to the existing "diff the gap histogram"
  note: **also diff `expected_lines`** — a moved denominator is corpus drift,
  not a code regression.
* Re-sync the corpus (`download_tests.sh avm2`) so local triage stops
  disagreeing with CI on `textblock_line_changes`.
