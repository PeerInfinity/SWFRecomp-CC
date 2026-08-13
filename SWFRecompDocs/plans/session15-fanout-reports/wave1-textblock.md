# wave1-textblock — the FTE trio (session 15, dual-axis fan-out #7)

Agent: `w1-textblock`. Read-only wave-1 diagnosis. Baseline `42a324cef`,
grading run `31647430265` @ `bf585e448` (graphics / full / images=true).

---

## 0. Verdict

**GO — +3 effective, verified by a fixture-fitted simulator that reproduces all
three target fixtures byte-for-byte.** This is the highest-confidence GO I can
issue: the mechanism set is not estimated, it is *executed*.

| Test | baseline status | priced after | evidence |
|---|---|---|---|
| `avm2/textline_raw_text_length` | `output_mismatch` | **`pass`** | simulator == `output.txt` exactly |
| `avm2/textblock_line_changes` | `output_mismatch` | **`ruffle_matched`** | simulator == `output.ruffle.txt` exactly |
| `avm2/textblock_releaselines` | `output_mismatch` | **`ruffle_matched`** | simulator == `output.ruffle.txt` exactly |
| `avm2/textblock_recreateline` | `output_mismatch` | `output_mismatch` (line count moves) | adjudicated unflippable in s12; +1..2 correct lines |

Corpus: **4269 → 4272 effective / 4443**.

Canary risk: **zero predicted flips against the passing family**, and the two
riskiest canaries are *proven* insensitive (§5), not merely argued.

### The brief's premise is REFUTED (partially)

The board guessed "likely one FTE mechanism". There are **two disjoint
mechanism clusters** with no shared code path and no shared test:

* **Cluster A — line-chain lifecycle.** `lastLine`, `TextLine::release()`,
  the `releaseLines()` reachability algorithm + its `#2004`/`#2007` taxonomy,
  and a `hide_block_from_script` flag for `validity = "static"`.
  Serves `textblock_line_changes` **and** `textblock_releaselines`.
  Touches **no** field that `textline_raw_text_length` reads.
* **Cluster B — line breaking / measurement.** `next_line_break` must accept
  `CR`, `CRLF`, `U+2028`, `U+2029` (today: `LF` only), and `rawTextLength` must
  be the line's own substring length in UTF-16 code units (today: literally the
  whole block text — see the field comment in `avm2_globals.h:833`).
  Serves `textline_raw_text_length` **only**. Touches nothing cluster A reads.

They share exactly one struct (`Avm2TextLineExt`) and one function
(`tb_do_create_text_line`), at disjoint lines. **They can be landed as two
independent patches, or by two agents, with no coupling.** The board's "one
mechanism" framing would have under-scoped the work by half.

Second refutation: **the trio is a quartet.** `avm2/textblock_recreateline` is
in the same family and is `output_mismatch` at baseline (and was at
`fb36ba11` too — not a regression). It is *not* flippable (s12
`w2-textblock-report.md` §5: needs real embedded-font ascent/descent
`8.3203125`/`2.58984375` and a `numChildren` divergence that makes
`ruffle_matched` unreachable too). Cluster B does move its line count — see §6.

---

## 1. Why the fixtures had to be fetched, and the trap for wave-2

**The main tree's copy of `textblock_line_changes` is STALE (282-line
`output.txt`); upstream is 481.** `textblock_releaselines` and
`textline_raw_text_length` **do not exist on disk at all**. CI downloads fresh
each run, which is why `results_graphics.json` already scores all three.

Grading against the on-disk fixture will show `textblock_line_changes` as a
near-pass and hide the real work. Wave-2 **must** refresh the three dirs first.

`~/CC/ruffle` had `origin/master` fetched to `99f4d491b` during this
investigation (`git pull --ff-only` refused to merge — the checkout has local
edits to `Cargo.lock`, `core/src/tag_utils.rs`, `render/wgpu/Cargo.toml` — so
only the remote ref moved; the working tree is untouched). Extract per-test,
**do not** run `download_tests.sh avm2` (it would refresh the whole 1240-test
suite under ~10 concurrent agents):

```bash
cd ~/CC/ruffle
for t in textblock_line_changes textblock_releaselines textline_raw_text_length; do
  d=<worktree>/ruffle-tests/tests/swfs/avm2/$t; mkdir -p $d
  for f in $(git ls-tree --name-only origin/master tests/tests/swfs/avm2/$t/); do
    git show origin/master:$f > $d/$(basename $f)
  done
done
# then ALWAYS --recompile on first use (new test.swf, stale RecompiledABC)
```

Upstream provenance (the arc that produced all three, newest first):
`99f4d491b` static-validity behaviour, `f4f9380a9` releaseLines matches Flash,
`c97d2d9c2` carriage returns in FTE lines, `f9ac716c2` values reported for FTE
lines, `1c9a332ee` implement `releaseLines`, `99777b6b6` internal link for
static lines, `7af53788a` improve `lastLine`.

---

## 2. Measured baseline diffs (this machine, `--recompile --diff`)

| Test | expected | actual | vs graded target |
|---|---|---|---|
| `textline_raw_text_length` | 30 | 28 | 30 / 28 lines differ vs `output.txt` |
| `textblock_line_changes` | 481 | 469 | **58 / 46** differ vs `output.ruffle.txt` (99/87 vs `output.txt`) |
| `textblock_releaselines` | 752 | 695 | 271 / 214 differ vs `output.txt` |

### `textline_raw_text_length` — two defects, both cluster B

```
-  line 0: rawTextLength=3 textBlockBeginIndex=0     (expected)
+  line 0: rawTextLength=5 textBlockBeginIndex=0     (ours: whole-block length)
```
and `Carriage Return` / `Line separator` / `Paragraph separator` produce **one**
line instead of two — `next_line_break` (`avm2_text.c:7287`) scans for `'\n'`
only. `CRLF` and `LF` already work.

### `textblock_line_changes` / `textblock_releaselines` — cluster A only

Every `Last line in block:` line is wrong (16 in `line_changes`, 22 in
`releaselines`) because `lastLine` is **wired to the `firstLine` getter**
(`avm2_text.c:7734`). `releaseLines` (`avm2_text.c:7442`) is an explicit stub —
its own comment says *"multi-line release is unimplemented"* — so it throws no
`#2007`/`#2004` and performs no chain surgery.

**Why the alias ever passed:** in the OLD 282-line fixture every `Last line in
block:` value was `line-0` or `line-unknown`, i.e. identical to `firstLine` —
because *Ruffle's own* `lastLine` was equally wrong then. Upstream `7af53788a`
fixed Ruffle, which rewrote `output.ruffle.txt`, which is what actually broke
us. The alias was fitted to a Ruffle bug, not to Flash.

---

## 3. Mechanism, exactly (Ruffle is the spec; both known_failures grade against it)

Sources: `core/src/display_object/text_line.rs`,
`core/src/avm2/object/text_block_object.rs`,
`core/src/avm2/globals/flash/text/engine/text_block.rs` @ `99f4d491b`.

**A1 — `lastLine`.** `block.lines()` = `successors(first_line, |l| l.next_line)`;
`lastLine` is its last element. Not "newest line", not `firstLine`.

**A2 — `TextLine::release()`.**
```
block = self.text_block            (INTERNAL link, asserted non-null)
if self is block.first_line: block.first_line = self.next
self.validity = invalid
for l in self.next_lines(): l.validity = invalid     # successors BEFORE unlink
if prev: prev.next = next
if next: next.prev = prev
self.text_block = null; self.prev = null; self.next = null
```

**A3 — `releaseLines(a, b)`** (native, so its stack frame is
`flash.text.engine::TextBlock/releaseLines()` with **no** `Error$/throwError()`
frame — unlike `createTextLine`, cf. `textblock_createline_errors/output.txt`):
```
a == null -> TypeError #2007 "Parameter firstLine must be non-null."
b == null -> TypeError #2007 "Parameter lastLine must be non-null."
walk lines() for the FIRST index matching (a or b); none -> ArgumentError #2004
if a is b: a.release(); return          # only AFTER the reachability check
walk on from that index+1 for the SECOND match; none -> #2004
release every line in [first .. first+count)  (snapshot the slice first)
```
Argument order is irrelevant by construction; a line of another block, or a
line unreachable from `first_line`, is `#2004`.

**A4 — `hide_block_from_script`.** `validity = "static"` must NOT null the
internal `text_block` (today `avm2_text.c:6930` does). It sets a separate flag
that makes the **script-visible** `textBlock` getter return `null` forever,
while the line stays in the block's chain and stays releasable. This is
load-bearing: `releaselines` does `line1.validity="static"` then
`releaseLines(line1, line2)` and expects the release to **succeed**.
Corollary: the `previousLine` validation in `createTextLine`/`recreateTextLine`
(`avm2_text.c:7381`, `7415`) must switch to the **script-visible** view, because
Ruffle's check is written in AS as `previousLine.textBlock !== this`.

**B1 — `next_line_break`.** Break on `0x0A | 0x0D | 0x2028 | 0x2029`;
`CR LF` consumes two units; the separator is **included** in the line.

**B2 — `rawTextLength = end_index - begin_index`**, and `begin/end` are
**UTF-16 code-unit** indices, not bytes (`"ab cd"` → begin 3, raw 2).
`avm2_text.c` already has `u16_length` (:77) and `u16_to_byte` (:91).

---

## 4. Proof: fixture-fitted simulator

`/tmp/claude-1000/.../scratchpad/w1tb_sim.py` implements exactly A1–A4 + B1–B2
and replays each Test.as.

```
$ python3 w1tb_sim.py rt | diff - textline_raw_text_length/output.txt        -> IDENTICAL
$ python3 w1tb_sim.py lc | diff - textblock_line_changes/output.ruffle.txt   -> IDENTICAL
$ python3 w1tb_sim.py rl | diff - textblock_releaselines/output.ruffle.txt   -> IDENTICAL
```

The mechanism set is therefore **complete and sufficient** — there is no
residual defect hiding behind these. Copy the simulator into the worktree and
use it as a line-level oracle while porting.

### Do NOT chase the Flash fixtures (an anti-goal worth naming)

`releaselines` is 4 lines from a full `pass`: after
`block.createTextLine(line4, …)` Flash invalidates **and dissociates** the
displaced successor (`line5` → `validity: invalid, previousLine: null`) while
Ruffle leaves it `valid` with `previousLine: line-4` (Ruffle's own TODO in
`do_create_text_line`). Implementing that Flash rule would:

* flip `releaselines` `ruffle_matched → pass` (**+0 effective**, it already
  counts), and
* break `line_changes` out of `ruffle_matched` (**−1 effective**) — it hits the
  identical construct at `output.ruffle.txt:347–352`, and `line_changes` can
  never reach `pass` anyway (~50 further Flash-vs-Ruffle deltas: Flash's
  `recreateTextLine` dissociates old successors and its static semantics differ).

**Net −1. Replicate Ruffle exactly; do not implement the dissociation rule.**

---

## 5. Canaries (wave-2 must run these) and why the risk is near zero

Baseline statuses from `ruffle-tests/tests/swfs/avm2/_results/results_graphics.json`.

| Canary | passing today | exposure | assessment |
|---|---|---|---|
| `textline_splitting_basic` | pass | `next_line_break` (its cases include `"\r"`, `"\r\n"`) | **PROVEN safe**: all 21 of its inputs produce an identical break sequence under the old and new rules (`\r`-terminal and `\r\n` already coincide). |
| `textblock_createline_fte` | pass | `rawTextLength` | **PROVEN safe**: grades `line3.rawTextLength: 11` on `"Hello World"` — no break, so whole-block == substring. Also exercises content-shrink (`pos > len` → `complete`), which must keep comparing in the *same* unit system after B2. |
| `textblock_properties` | pass | `lastLine` | Safe: reads `lastLine` once on an empty block → `null`; the chain walk also yields `null`. |
| `textline_validity` | pass | A4 static semantics | Safe: sets `static`/`userInvalid` but never reads `.textBlock`. Do not touch `tb_set_content`'s `lines_head` invalidation — its comment ties it to this test. |
| `textblock_createline_errors` | pass | `#2004` taxonomy | Safe: only `validity="invalid"` + `createTextLine`; no `releaseLines`. Its fixture is the reference for which frames each error carries. |
| `content_element_basic`, `text_element_basic` | pass | `textBlockBeginIndex` on ContentElement (`ce_get_text_block_begin_index`, a different getter) | Safe. |
| `textline_name`, `textline_inapplicable_properties`, `textline_throwerror` | pass | none | Safe. |
| `stage3d_raytrace` | pass | grep hit for `lastLine` | False positive — a local variable in `OGSL.as`. |

No test outside `avm2/` calls `releaseLines`/`rawTextLength`/`lastLine`
(corpus-wide grep over `*.as`).

---

## 6. Wave-2 patch scope

Single file **`SWFModernRuntime/src/avm2/avm2_text.c`** + one trailing field in
`SWFModernRuntime/include/avm2/avm2_globals.h`. Every use of
`Avm2TextLineExt.text_block` is confined to `avm2_text.c` (verified by grep) —
no cross-file threading.

| # | Site | Change | ~LOC |
|---|---|---|---|
| A1 | `avm2_text.c:7734` | new `tb_get_last_line` walking `first_line`→`next_line`; unbind the `firstLine` alias | 12 |
| A2 | new, near `tb_release_lines` | `static void tl_release(Avm2Context*, Avm2Object*)` per §3 A2 | 35 |
| A3 | `avm2_text.c:7442` | rewrite `tb_release_lines`; `throw_2007` (:41) with `"firstLine"`/`"lastLine"`, `fte_throw_2004` **without** the `Error$/throwError` push | 55 |
| A4 | `:6930`, `:6866`, `:7381`, `:7415`, `avm2_globals.h:836` | trailing `uint8_t hide_block_from_script;`; set it instead of nulling `text_block`; script-visible getter; both `previousLine` validators use the script view; clear it in `reset`/`do_create` | 18 |
| B1 | `avm2_text.c:7287` | `next_line_break` over UTF-16 units, `0x0A/0x0D/0x2028/0x2029`, CRLF pairs | 28 |
| B2 | `:7345`, `avm2_globals.h:833` | `tl->raw_text_length = next - pos`; `begin/end` in u16 units via `u16_to_byte`/`u16_length`; fix the field comment | 8 |

~155 lines, no `#ifdef` arms → no-graphics parity expected identical.

**Sequencing.** A and B are independent; land A first (2 tests, the recovered
"regression"), B second. If split across agents, the only textual overlap is the
`Avm2TextLineExt` struct — append fields at the end, one per agent.

**Handoff checklist.**
1. Refresh the three fixtures (§1). `--recompile` on first run.
2. Port A1–A4, then B1–B2; diff against `w1tb_sim.py` output at every step.
3. Run, sequentially (shared machine): `textblock_line_changes`,
   `textblock_releaselines`, `textline_raw_text_length`, then the canaries
   `textline_splitting_basic`, `textblock_createline_fte`, `textblock_properties`,
   `textline_validity`, `textblock_createline_errors`, `textline_name`,
   `textline_throwerror`, `textline_inapplicable_properties`,
   `content_element_basic`, `text_element_basic`.
4. `textblock_recreateline`: expect its **line counts to move** (`rawTextLength`
   line 32 goes `whole-block → 18`, matching expected; `atomCount` on line 31
   also wants 18 and stays a stub). **Status stays `output_mismatch` — flag it in
   the ledger so the next board does not re-file it as a regression** (this is
   the third time this test has been mistaken for one).
5. CI: `mode=graphics`, `categories=full` (AVM2 runtime), `images=false`.

---

## 7. Ledger for the merged CI run

```
avm2/textline_raw_text_length   output_mismatch -> pass             +1 eff
avm2/textblock_line_changes     output_mismatch -> ruffle_matched   +1 eff   (recovers the s15 "regression")
avm2/textblock_releaselines     output_mismatch -> ruffle_matched   +1 eff
avm2/textblock_recreateline     output_mismatch -> output_mismatch   0       (line count moves; NOT a regression)
everything else                 unchanged
corpus 4269/4443 -> 4272/4443 effective
```

## 8. Dispositions checked

`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt` — **no entry** for
any `textblock_*` / `textline_*` test. The only prior adjudication is
`session12-fanout-reports/w2-textblock-report.md` §5 (`textblock_recreateline`
unflippable), which this report honours. §4 above adds a new negative
disposition worth recording if the patch lands: *the Flash successor-dissociation
rule is deliberately not implemented — it is net −1 effective.*
