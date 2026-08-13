# w2-textblock — the FTE trio, LANDED (session 15, dual-axis fan-out #7)

Agent: `w2-textblock` (wave-2, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac3db62fee7f90ce9`).
Brief: `wave1-textblock.md` (GO, +3 effective). Baseline `42a324cef`.

---

## 0. Verdict — GO CONFIRMED, all three priced flips measured locally

| Test | baseline (measured here) | after | priced | got |
|---|---|---|---|---|
| `avm2/textblock_line_changes` | `output_mismatch` (469 vs 481 lines) | **`ruffle_matched`** | `ruffle_matched` | ✅ |
| `avm2/textblock_releaselines` | `output_mismatch` | **`ruffle_matched`** | `ruffle_matched` | ✅ |
| `avm2/textline_raw_text_length` | `output_mismatch` | **`pass`** | `pass` | ✅ |
| `visual/definefont4` | `output_mismatch` | **`pass`** | *unpriced* | 🎁 **+1** |

**+4 effective (priced +3, plus the coordinator's free rider). Corpus
4269 → 4273 / 4443.** Wave-1's pricing survived intact — no magnitude haircut,
no mechanism refutation. Both clusters landed on the *first* build; the wave-1
simulator was an exact spec (I re-verified it reproduces all three fresh
fixtures byte-for-byte before porting).

`definefont4` is owned by **cluster B**, A/B'd in three legs (§3).

Patches (separate, independently landable, in brief order):

* `SWFRecompDocs/plans/session15-fanout-reports/w2-textblock-a.patch` — cluster A
  (line-chain lifecycle), 136 insert / 19 delete.
* `SWFRecompDocs/plans/session15-fanout-reports/w2-textblock-b.patch` — cluster B
  (line breaking / measurement), applies on top of A.

---

## 1. Cluster A — line-chain lifecycle

Files: `SWFModernRuntime/src/avm2/avm2_text.c`,
`SWFModernRuntime/include/avm2/avm2_globals.h` (one trailing struct field).

| # | Function / site | Change |
|---|---|---|
| A1 | new `tb_get_last_line` (avm2_text.c:7212–7229); registration at :7877 | `lastLine` walks `first_line`→`next_line` to the tail. It used to be *registered as `tb_get_first_line`* — a literal alias. |
| A2 | new `tl_release` (:7506–7544) | Ruffle `TextLine::release()`: reseat `first_line` if the released line was the head, invalidate self, invalidate **all successors before the unlink**, splice `prev`/`next`, then null `text_block`/`previous_line`/`next_line`. Assigns `validity` directly, bypassing `tl_set_validity`'s state machine (static→invalid is otherwise forbidden, and a static line *is* releasable). |
| A3 | `tb_release_lines` rewritten (:7546–7601) | Was an explicit stub (*"multi-line release is unimplemented"*). Now: `#2007 firstLine` / `#2007 lastLine` for nulls, then reachability from `first_line` for the first match (`#2004` if unreachable), the `a === b` fast path **after** the reachability check, then a second scan for the other endpoint (`#2004` if unreachable), then release the contiguous run carrying each successor forward. Argument order is irrelevant by construction. Throws with **no** `Error$/throwError()` frame (native method) — matches all 20 graded stack traces. |
| A4 | `hide_block_from_script` — `avm2_globals.h` trailing field; `tl_script_block` (:6870); `tl_get_text_block` (:6875); `tl_set_validity` (:6939); `tb_create_text_line` (:7447); `tb_recreate_text_line` (:7481, :7495); `tb_do_create_text_line` (:7407) | `validity = "static"` no longer nulls the internal block link; it sets a flag that hides the block from **script** only. The line stays in the chain and stays releasable. Both `previousLine` validators switched to the script-visible view (Ruffle writes that check in AS as `previousLine.textBlock !== this`). The flag is cleared on create and recreate; it is deliberately **not** cleared by `tl_release` (a released static line keeps reporting `textBlock == null`). |
| A- | `textblock_ext_of` (:7007) | New `obj_is_class`-guarded accessor so `tl_release` can reach the block ext from a line's back-edge. |

`avm2_strict_eq` lost its only call site in this file with the stub rewrite.

## 2. Cluster B — line breaking / measurement

| # | Function / site | Change |
|---|---|---|
| B1 | `next_line_break` rewritten (avm2_text.c:7325–7358) | Was a byte scan for `'\n'` only. Now walks UTF-16 code units and breaks on `LF`, `CR`, `CRLF` (one break, two units), `U+2028` and `U+2029`; the separator stays in the line it terminates. Returns a **UTF-16** index. |
| B2 | `tb_do_create_text_line` (:7386–7412), `avm2_globals.h` field comments | `pos`/`begin_index`/`end_index` are UTF-16 code-unit offsets; the content-shrink guard compares against `u16_length(text)` in the same unit system; `raw_text_length = next - pos` (this line's substring) instead of the whole block text. |

The layout-core banner comment ("splits on `'\n'` and NOTHING else … `'\r'` is
not a break") was corrected in the same hunk — it was the load-bearing false
claim.

---

## 3. Canary ledger

All runs local, native `no-graphics`, `--recompile`, sequentially (2 lanes max,
shared machine). **Zero regressions.**

| Canary | baseline | with A+B | note |
|---|---|---|---|
| `avm2/textline_splitting_basic` | pass | **pass** | the riskiest one (`next_line_break`; its 21 inputs include `"\r"` and `"\r\n"`). Wave-1's "PROVEN safe" holds — and its inputs are pure ASCII, so B2's unit change is a no-op there too. |
| `avm2/textblock_createline_fte` | pass | **pass** | `rawTextLength: 11` on `"Hello World"` still grades; the content-shrink `pos > len` path compares in the new unit system consistently. |
| `avm2/textblock_properties` | pass | **pass** | `lastLine` on an empty block → `null` under the chain walk. |
| `avm2/textline_validity` | pass | **pass** | 162 graded lines of static/userInvalid semantics unaffected by A4. |
| `avm2/textblock_createline_errors` | pass | **pass** | `#2004` taxonomy + the `Error$/throwError()` frame unchanged for createTextLine. |
| `avm2/textline_name` | pass | **pass** | |
| `avm2/textline_throwerror` | pass | **pass** | |
| `avm2/textline_inapplicable_properties` | pass | **pass** | |
| `avm2/content_element_basic` | pass | **pass** | `ce_get_text_block_begin_index` is a different getter; untouched. |
| `avm2/text_element_basic` | pass | **pass** | |
| `avm2/textblock_recreateline` | `output_mismatch` | `output_mismatch` | **NOT a regression** — see §4.1. Its diff *improves*: the matched prefix now runs through line 33, i.e. `atomCount` (31→32) **and** `rawTextLength` both read `18` and match expected, where they previously read the whole-block length. First divergence moves to line 34 (`8.3203125` vs `12`) — the embedded-font ascent that makes this test unflippable. |
| `visual/definefont4` | `output_mismatch` | **`pass`** | **FREE RIDER CONFIRMED, +1 beyond the priced +3** — see below. |

### `visual/definefont4` — the coordinator's free-rider tip is CORRECT

A/B'd properly on this machine, three legs, same test dir, same SWF:

| leg | result |
|---|---|
| `HEAD` (`42a324cef`) | `output_mismatch` — 24 actual lines vs 0 expected |
| `HEAD` + cluster A | `output_mismatch` — byte-identical to HEAD |
| `HEAD` + cluster A + cluster B | **`pass`** — 0 lines |

Baseline signature (identical in `results.json`, `results_graphics.json` and
both `_previous` files, i.e. stable across CI runs and across both build modes):

```
TypeError: Error #1009: Cannot access a property or method of a null object reference.
	(accessing field: getEffectiveLineHeight)
	at flashx.textLayout.compose::TextFlowLine/2008::getLineLeading()
	at flashx.textLayout.compose::BaseCompose/calculateLeadingParameters()
	at flashx.textLayout.compose::BaseCompose/finishComposeLine()      ... x24
	at flashx.textLayout.factory::StringTextLineFactory/createTextLines()
```

**Cluster B owns this flip, not cluster A.** definefont4 is a TLF
(`flashx.textLayout`) movie with no `.as` source, which is why the corpus-wide
`*.as` grep in wave-1 §5 could not see it — I found it independently by grepping
cached `RecompiledABC/abc0_methods.c` for `flash.text.engine::TextBlock` (§4.5).
TLF's `StringTextLineFactory` composes by walking `createTextLine` and advancing
its own absolute-position cursor by `textLine.rawTextLength`; with the old
whole-block value the cursor overshot on the first line, and `BaseCompose`
finished a composition step against a null `TextFlowLine`. Fixing B2 makes the
cursor arithmetic consistent and the whole compose loop terminates correctly.

Its `image_comparisons.output` was also failing at baseline (16086 outliers,
max diff 255). Image status is NOT measured here (local no-graphics; and image
comparisons never gate trace pass/fail) — the render axis should be re-read from
the next `images=true` run.

### Two false failures worth naming for the next agent

`definefont4` first reported **`compile_fail` — "compilation timed out"** in both
batched and sequential runs. That is the load artifact BRIEFS_COMMON §3 warns
about, in a specific form worth recording: definefont4's TLF blob compiles in
~87–94 s in CI but took **895 s** on this machine at load average 14 with ~20
concurrent `verify_output.py` processes — straight through
`verify_output.py`'s **300 s default gcc/link budget**. The fix is
`SWFRECOMP_COMPILE_TIMEOUT=2400` in the environment (env var, no CLI flag); with
it the same test graded `pass` on the first try. Any agent triaging a big-ABC
test on a loaded box will hit this.

---

## 4. Notes for accounting

1. **`avm2/textblock_recreateline` stays `output_mismatch` — NOT a regression.**
   Adjudicated unflippable in s12 (`session12-fanout-reports/w2-textblock-report.md`
   §5: needs real embedded-font ascent/descent `8.3203125`/`2.58984375`, plus a
   `numChildren` divergence that puts `ruffle_matched` out of reach too). Cluster B
   *moves its diff* (`rawTextLength` on line 32 goes whole-block → 18, matching
   expected; `atomCount` on line 31 wants 18 and remains a stub), so the line
   counts change. **This is the fourth time this test has been at risk of being
   misfiled as a regression.**

2. **The Flash successor-dissociation rule is deliberately NOT implemented.**
   Wave-1 §4 prices it net **−1**: it would flip `releaselines`
   `ruffle_matched → pass` (+0, it already counts) while breaking `line_changes`
   out of `ruffle_matched` (−1), and `line_changes` can never reach `pass`
   anyway. Worth an entry in `RUFFLE_COMPAT_TWEAKS.md` if the board wants the
   negative disposition on the record.

3. **Fixture freshness is load-bearing.** The main tree's
   `textblock_line_changes` was the stale 282-line `output.txt`;
   `textblock_releaselines` and `textline_raw_text_length` had no local dir at
   all. All three were extracted per test from `~/CC/ruffle` `origin/master`
   (`99f4d491b`) — `download_tests.sh` was **not** run. CI downloads fresh, so
   the merged run grades the same fixtures I did.

4. **Sibling conflict (`w2-t10-descriptor`).** My furthest edit in `avm2_text.c`
   is line 7880; the `AccessibilityImplementation` block it touches is at
   line 9285 (post-patch) — ~1400 lines away, no shared hunk. I do not touch
   `avm2_globals.c`. My `avm2_globals.h` change is one trailing field in
   `Avm2TextLineExt` plus three field comments.

5. **Corpus exposure re-verified independently.** `grep -rl` for
   `releaseLines|lastLine|rawTextLength|createTextLine|recreateTextLine` over
   every `*.as` in the corpus hits only the known FTE family plus
   `stage3d_raytrace` (a local variable named `lastLine` in `OGSL.as` — false
   positive). A second sweep over cached `RecompiledABC/abc0_methods.c` for
   `flash.text.engine::TextBlock` — which catches SWF-only tests with no `.as`
   source — adds exactly one name the `.as` grep could not see:
   `visual/definefont4` (see §3).

6. **Patch fidelity verified mechanically.** `patch -p1 < A` then
   `patch -p1 < B` against pristine `HEAD` copies of both files reproduces the
   exact tree these results were measured on (`diff -q` identical, both files).
   Both patches apply with no fuzz.

7. CI recommendation: `mode=graphics`, `categories=full` (AVM2 runtime),
   `images=false`. Note `visual/definefont4` lives in the CI **`misc`** group,
   so `categories=full` is required for the +1 to be visible at all.

## 5. Ledger for the merged CI run

```
avm2/textline_raw_text_length   output_mismatch -> pass             +1 eff   (cluster B)
avm2/textblock_line_changes     output_mismatch -> ruffle_matched   +1 eff   (cluster A)
avm2/textblock_releaselines     output_mismatch -> ruffle_matched   +1 eff   (cluster A)
visual/definefont4              output_mismatch -> pass             +1 eff   (cluster B, unpriced free rider)
avm2/textblock_recreateline     output_mismatch -> output_mismatch   0       (2 more lines correct; NOT a regression)
10 FTE canaries                 pass            -> pass              0
corpus 4269/4443 -> 4273/4443 effective
```
