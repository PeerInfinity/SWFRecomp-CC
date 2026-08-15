# w2-ignore-bucket — session 16, wave-2, board lead **L4** (the stale ignore bucket)

**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a3fbc9eb720652c4c`
**Base:** `cd04f80b9` (master at session start). No commits, no pushes.

## NEW FILES CREATED BY THE PATCHES: **none.**

Every patch modifies an already-tracked file. Nothing for the coordinator to
`git add` beyond the four paths listed in §"Patch scope".

---

## 1. Verdict, up front

**GO, delivered at the "real" price. +2 trace flips, both verified locally,
plus an unbriefed +2 on the PIXEL axis** (both fixed tests also flip their
image comparison from fail to pass).

| flip | axis | before | after |
|---|---|---|---|
| `avm2/bitmapdata_draw_alpha_erase` | trace | `output_mismatch` (2/8 miss) | **`pass`** |
| `avm2/bitmapdata_draw_alpha_erase` | pixels | `fail` — 15000 outliers, max diff 162 | **`pass`** — 0 outliers, max diff 0 |
| `avm2/edittext_tag_indent` | trace | `output_mismatch` (11/49 miss, 50 actual) | **`pass`** |
| `avm2/edittext_tag_indent` | pixels | `fail` — 7884 outliers, max diff 255 | **`pass`** — 0 outliers, max diff 1 |

Board pricing for L4 was floor +1 / real +2 / ceiling +3 on trace. Delivered
**+2 trace** (the two rows the board named as L4-exclusive). The third,
`stage_scale_factor`, is **w2-geom's** and untouched here — see §5.

Trace baseline moves **4298 → 4300 / 4443 effective**. Pixel baseline moves
**324 → 326 / 569 (56.9% → 57.3%)** — please fold these two rows into the
pixel-axis ledger too, they were not on the pixel board.

---

## 2. Premise attacked: does un-ignoring change the graded number? **No — and
that is exactly why the +2 is real.**

Verified by reading the code, not by assumption:

* `ruffle-tests/verify_output.py` **never opens `ignored_tests.txt`** (grep: zero
  hits in the file). Every test in a suite is run and graded regardless of any
  ignore list.
* `ruffle-tests/filter_results.py` is a *separate post-pass* that reads
  `ignored_tests.txt`, drops those rows, and writes a **new** file
  `<stem>_filtered.json`. It never rewrites `results_graphics.json`.
* `.github/workflows/ruffle-tests.yml` (step "Generate step summary", :1164-1200)
  prints the filtered numbers as the headline and the raw numbers in
  parentheses; both files are published, the raw one unmodified.
* `scripts/corpus_status_diff.py` — the tool the boards use — reads
  `--stem results_graphics` (default), i.e. the **unfiltered** file, and knows
  nothing about ignore lists.

**Consequences, stated precisely:**

1. Editing `avm2/ignored_tests.txt` moves the corpus figure by **exactly zero**.
   The +2 above comes entirely from the two code fixes and would have counted
   even if the ignore entries had been left alone.
2. The reverse is also true and is the trap worth recording: **the eight entries
   in this bucket were never costing us a graded point — they were costing us
   sessions.** Three separate boards (s14, s15, s16) re-costed the same bucket
   because its heading claimed a blocker that stopped being true on 2026-07-23.
   The value of the hygiene half of L4 is that the fourth re-costing does not
   happen.
3. Removing a *failing* row from an ignore list makes the **filtered** number go
   down, not up. That is why the four still-failing rows are kept below (with an
   honest heading) rather than deleted — deleting them would look like a
   filtered-rate regression while changing nothing real. See §6 for the
   alternative if you would rather have the filtered view be strictly
   "accepted diffs only".

---

## 3. Per-entry table (all eight)

Each run locally at `cd04f80b9` with
`python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics --diff --verbose --recompile`
inside this worktree (test dirs `cp -r`'d in, `--recompile` on first use).

| # | entry | status at baseline | classification | action taken |
|---|---|---|---|---|
| 1 | `bitmapdata_draw_alpha_erase` | `output_mismatch`, 2/8 miss | **near-pass, fixed** | code fix + un-ignored |
| 2 | `edittext_tag_indent` | `output_mismatch`, 11/49 miss | **near-pass, fixed** | code fix + un-ignored |
| 3 | `blend_transform` | `ruffle_matched` (already effective) | **mis-filed** — `known_failure = true` in its own `test.toml` ("Broken after the inaccuracy in getPixel/getPixel32 was fixed") | moved to the "Upstream known_failure = true" bucket |
| 4 | `graphics_draw_path` | `ruffle_matched` (already effective) | **mis-filed** — `known_failure = true`, `test.toml` says "output differs from FP due to the winding behavior not being implemented" | moved to the "Upstream known_failure = true" bucket |
| 5 | `displayobject_scrollrect` | `output_mismatch`, 14/33 | open bug, **board L1** (twip quantization in `point_transform_native`) | kept, heading rewritten with mechanism + owner |
| 6 | `displayobject_hittestpoint_boundary` | `output_mismatch`, 18/65 | open bug, **L1 + edge-exclusivity rule + missing leading blank line** | kept, heading rewritten |
| 7 | `geom_transform` | `output_mismatch`, 53/74, `#1009 (accessing field: rawData)` | open bug, **board L2** (`Transform.matrix`/`.matrix3D` duality) | kept, heading rewritten |
| 8 | `stage_scale_factor` | `output_mismatch`, 6/12 | open bug, **owned by w2-geom** | kept, heading rewritten, **NOT touched** |

None of the eight had a disposition entry in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, or the global `ruffle-tests/ignored_tests.txt`
(grepped all five; zero hits). The board's claim that the bucket is unbacked is
**confirmed**.

---

## 4. The two fixes

### 4.1 `bitmapdata_draw_alpha_erase` — BlendMode.ALPHA / .ERASE on the CPU draw path

**Baseline diff (2 of 8 lines):**

```
- alphaData after alpha: 44224365      + alphaData after alpha: ff224466
- eraseData after erase: bb1f1f5f      + eraseData after erase: ff202060
```

i.e. `BitmapData.draw(new Bitmap(src), null, null, "alpha"/"erase")` was a
**complete no-op**. The other six lines already passed, because they exercise
the *other* half of the rule: with a bare `BitmapData` (not a `Bitmap` display
object) as the source, alpha/erase genuinely do nothing in Flash, and we already
modelled that (`core/src/bitmap/operations.rs:1459` in Ruffle carries the same
early return).

**Mechanism.** Ruffle cannot express ALPHA/ERASE as a hardware blend — both
"require layer tracking" (`render/wgpu/src/blend.rs:13-14`) — so they run as
complex-blend shaders against an offscreen layer. The shaders are three lines
each (`render/wgpu/shaders/blend/{alpha,erase}.wgsl`), on **premultiplied**
values, and neither ever reads the source *colour*:

```wgsl
alpha:  if (src.a > 0.0) { return vec4(dst.rgb * src.a,       src.a * dst.a); } else { discard; }
erase:  if (src.a > 0.0) { return vec4(dst.rgb * (1.0-src.a), (1.0-src.a) * dst.a); } else { discard; }
```

Because the whole operation is "scale the premultiplied destination by a scalar
taken from the source alpha", it has an **exact** integer CPU equivalent — no
GPU needed, no rasterization needed. Our `BitmapData` storage is already
premultiplied and already carries Flash's brute-forced un-premultiply table
(`avm2_bitmap.c:53 FLASH_PREMUL_FACTOR`, copied from Ruffle's
`bitmap_data.rs`), so the arithmetic closes byte-exactly:

```
alpha:  dst 0xFF224466 -> premul (34,68,102,255), f = src.a = 0x44 = 68
        (v*68+127)/255 -> (9,18,27,68)
        unmul with FLASH_PREMUL_FACTOR[68] = 245508 -> 0x22,0x43,0x65
        => 0x44224365                                        == expected
erase:  dst 0xFF202060 -> premul (32,32,96,255), f = 255-68 = 187
        (v*187+127)/255 -> (23,23,70,187)
        unmul with FLASH_PREMUL_FACTOR[187] -> 0x1f,0x1f,0x5f
        => 0xBB1F1F5F                                        == expected
```

Worth recording: the exact-integer table is *load-bearing*. The naive
`round(p*255/a)` unmultiply gives `0x44224465` (G off by one) and
`floor(p*255/a)` gives `0x44214365` (R off by one); only Flash's table
reproduces all three channels. Anyone tempted to "simplify" the round trip to
float will silently break this test.

**Patch** (`w2-ignore-bitmapdata_draw_alpha_erase.patch`, runtime-only,
`SWFModernRuntime/src/avm2/avm2_bitmap.c`, +75/-3):

* new `static uint32_t blend_alpha_erase(dst, src, erase)` next to the existing
  `blend_mode_apply` family;
* new `static void bd_blit_alpha_erase(dst, src, tx, ty, erase)` immediately
  before `bd_draw` — self-localized, reuses the existing `PixelRegion` helpers,
  touches no shared function;
* `bd_draw` records `blend_is_erase` alongside the existing
  `blend_alpha_or_erase`, and dispatches to the blit for a **Bitmap
  display-object source under a translation-only matrix**. Every other shape
  (BitmapData source, TextField source, Sprite/shape source, rotated/scaled
  Bitmap) keeps the previous no-op, so the blast radius is exactly the case
  that was wrong;
* the stale comment on the blend-mode enum ("alpha/erase … handled at the call
  site") is corrected.

**Ownership note:** the brief flagged `BitmapData.draw`'s CPU path as mine and
the GPU/renderer paths as a sibling's. This patch touches `avm2_bitmap.c` only —
no `render_webgpu.c`, no filters, no `avm2_display.c`.

**Premise correction:** the board (and the brief) described this row as
"`BitmapData.draw` ignores `alphaBitmapData`". There is no `alphaBitmapData`
anywhere in this test — that is a `copyPixels` parameter. The test passes
`"alpha"` and `"erase"` as the **blendMode** argument (arg 3) of `draw`. The
mechanism is the blend-mode pair, not the alpha-channel-source parameter. The
priced outcome is unaffected.

### 4.2 `edittext_tag_indent` — DefineEditText `Indent` is SI16, not UI16

**Baseline diff (11 lines, two symptoms, ONE cause):**

```
  -1638 / -1638  ->  1638 / 1638       (text2)
  -10   / -10    ->  3267 / 3267       (text3)
  -4    / -4     ->  3273 / 3273       (text5)
  lines for text2/3/5: "abcdabcd" + ""  ->  "a" + "bcdabcd"
```

`-1638px = -32760 twips`; read unsigned that is `32776 twips = 1638px`.
`-10px = -200 twips`; read unsigned that is `65336 twips = 3266.8 -> 3267px`.
The **line-wrap half of the diff is the same bug**: a first line indented by
+3267px leaves room for exactly one glyph, so `abcdabcd` wrapped after `a`.
Fixing the sign fixed all 11 lines — the test went straight to `pass`, no
residue.

The SWF19 documentation does say UI16 for this field and it is wrong; Ruffle
carries the identical note at `swf/src/read.rs:2413`:
*"the documentation says that indent is UI16, in reality it seems to be SI16"*.
Our **AVM1** tag reader already had it right (`SWFRecomp/src/swf.cpp:3078`,
`s16 indent`) — only the **AVM2** timeline reader was unsigned, which is why
this never showed up on the avm1 suite.

**Patch** (`w2-ignore-edittext_tag_indent.patch`, +9/-3, two files):

* `SWFRecomp/src/abc/abc_timeline.cpp` — `indent` declared `int16_t` (it sat in
  a shared declaration line with the genuinely-unsigned `left_margin` /
  `right_margin`, which is how it got the wrong type), read as
  `(int16_t) body.u16()`, with the Ruffle citation in a comment;
* `SWFModernRuntime/include/avm2/avm2_abc.h:414` — `Avm2EditTextData::indent`
  becomes `int16_t` (its neighbour `leading` was already `int16_t`).

**Blast radius, measured exactly.** I parsed every `DefineEditText` (tag 37)
in all **4963** `test.swf` files under `ruffle-tests/tests/swfs` and looked for
`HAS_LAYOUT` with the Indent high bit set. **Exactly two SWFs in the entire
corpus have a negative indent:**

```
AVM2   avm2/edittext_tag_indent/test.swf   32768 -> -32768, 65336 -> -200, 65456 -> -80 twips
AVM1   avm1/edittext_tag_indent/test.swf   32768 -> -32768, 65336 -> -200, 65456 -> -80 twips
```

The AVM1 twin is the **same fixture**, read through `swf.cpp`'s already-correct
`s16 indent` — and it is **`pass` at the baseline**. So the two suites were
running the identical SWF through two readers that disagreed about one field's
signedness, and only the AVM2 one failed. That is as clean an oracle as this
corpus offers, and it means the recompiler patch can change the output of
**exactly one test**. The edittext canaries below are therefore confirmatory
(they prove nothing else moved), not exploratory.

**This is a RECOMPILER change**, so it needs `--recompile` to be observed and it
changes the emitted `avm2_generated_edittexts[]` table for any AVM2 SWF whose
DefineEditText has `HAS_LAYOUT` and an indent with the high bit set. A fresh
`cmake` build of `SWFRecomp` was made in this worktree for the measurement (the
copied main-tree `build/` is only valid for runtime-only patches — its
`CMakeCache.txt` points at the main tree and would have compiled main-tree
sources; it was deleted and reconfigured).

---

## 5. `stage_scale_factor` — status only, NOT touched

Left exactly as it was, per the brief. Baseline (run `31748059158`):
`output_mismatch`, 6 of 12 expected lines missing; image comparison fails with
1912924 outliers. Two independent halves, matching the board: `contentsScaleFactor`
hard-coded to 1 where 2 is expected, and `localX`/`localY` lines that are L1's
twip-quantization signature. Its ignore entry is retained in the rewritten block
with that mechanism named; **w2-geom should delete the `stage_scale_factor` line
from `avm2/ignored_tests.txt` if the twip fix flips it** — that is a one-line
edit inside my ignore-list patch's hunk, so apply mine first and let w2-geom's
land on top, or tell me and I will re-cut.

---

## 6. Ignore-list rewrite

`w2-ignore-bucket-ignorelist.patch` (`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`,
+41/-5):

* the dead heading is replaced with a dated re-triage block that states *why*
  the old rationale was dead (graphics mode landed 2026-07-23; the corpus is
  graded in graphics mode), and dispositions all eight entries by name;
* `bitmapdata_draw_alpha_erase` and `edittext_tag_indent` are **removed** — the
  file's own 2026-08-01 prune criterion ("remove iff the status is exactly
  `pass`, because the entry is hiding a win") now applies to them;
* `blend_transform` and `graphics_draw_path` are **moved** into the existing
  "Upstream known_failure = true (Ruffle itself fails these)" bucket, where they
  always belonged;
* the four survivors keep their entries under a heading that names each row's
  actual mechanism and its owning board lead, and states the removal condition.

**Adjacent finding in the same file, deliberately NOT folded into my patch
(board lead L7's territory).** Re-checked every one of the 52 entries in
`avm2/ignored_tests.txt` against the graded `results_graphics.json`: exactly
three are `pass`. Two of them — **`int_toprecision`** and **`uint_toprecision`**
(both fixed in s15) — meet this file's own prune criterion verbatim and are
hiding wins in the filtered report. The third, `bytearray_oom`, is `pass` but is
deliberately retained because it records an UPSTREAM `ignore = true`. I left all
three alone so L7's owner gets a clean file to patch; if no L7 slot runs this
session, deleting those two lines is a safe zero-risk follow-up.

**The alternative I did not take, for you to rule on.** A stricter reading of
this file's purpose is that an ignore list should hold only *accepted* diffs and
*upstream* decisions — never open bugs with named owners. Under that reading the
four survivors should be deleted outright, which would drop the avm2 **filtered**
count by 4 (0 change to the graded corpus figure). I kept them because a
filtered-rate drop in the same CI run that carries two real flips is a confusing
signal, and because three of the four have GO leads landing this very session and
will be deletable on merit within days. Say the word and I will re-cut the patch
with them removed.

---

## 7. Canaries

The change classes are (a) `BitmapData.draw` blending and (b) AVM2 EditText tag
layout. Neither is covered by `render_canary_tests.txt` (that set is shape /
gradient / stroke oriented), so I graded a hand-picked sibling set instead —
**this is the canary blind spot to record**: no standing canary exercises
`BitmapData.draw` blend modes or DefineEditText layout fields.

Baseline status for every row is taken from the merged `results_graphics.json`
at `3db858cbc`; the "after" column is a local `--mode=graphics` run in this
worktree, `-P 2`.

**Operational finding worth carrying forward (cost me ~40 min).** The first
pass of this batch produced four `compile_fail`s and four zero-byte logs. All
were **false**. Run with `--verbose`, the failure reads:

```
[1/1] edittext_margins... COMPILE_FAIL [r=0.00s c=301.08s]
  Error: compilation timed out
```

`verify_output.py`'s per-file gcc timeout defaults to **300 s**
(`verify_output.py:2682`). With ~10 fan-out agents on the box the load average
sat at **31-35** and ordinary AVM2 tests blew straight through it. The lever is
the documented env var:

```bash
SWFRECOMP_COMPILE_TIMEOUT=2400 python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics
```

**Every wave-2 agent in a fan-out session should export this before running any
canary batch.** The standing rule "compile failures under load are false" is
right, but re-running at the same 300 s ceiling just reproduces the false
failure — the ceiling itself has to move. (The zero-byte logs are the same
event with the process killed before it printed anything.)

**Canary set trim, and why it is justified.** The edittext half of the canary
set was cut from 11 rows to 6 after the blast-radius scan above proved that
**exactly one SWF in the whole 4963-file corpus** can change behaviour under the
indent patch. The remaining 6 exist to prove the freshly-`cmake`-built
recompiler emits identically to the main tree's build for *unaffected* tests,
which 6 rows establish as well as 11.

**Result: 26 / 26 clean. ZERO regressions on either patch.** Every `pass` stayed
`pass`; all three `ruffle_matched` rows (`blend_transform`, `graphics_draw_path`,
`edittext_tab_stops`) held `ruffle_matched`.

| test | before | after |
|---|---|---|
| `bitmapdata_copypixels_blend_over` | pass | pass |
| `bitmapdata_draw` | pass | pass |
| `bitmapdata_draw_colortransform` | pass | pass |
| `bitmapdata_draw_cpu_overwrite_gpu` | pass | pass |
| `bitmapdata_draw_filters` | pass | pass |
| `bitmapdata_draw_masks` | pass | pass |
| `bitmapdata_draw_rotation` | pass | pass |
| `bitmapdata_draw_self_via_graphic` | pass | pass |
| `bitmapdata_draw_stage` | pass | pass |
| `bitmapdata_drawwithquality` | pass | pass |
| `blend_multiply_alpha` | pass | pass |
| `blend_transform` | ruffle_matched | ruffle_matched |
| `edittext_align` | pass | pass |
| `edittext_autosize` | pass | pass |
| `edittext_bullet` | pass | pass |
| `edittext_default_format` | pass | pass |
| `edittext_getlinemetrics` | pass | pass |
| `edittext_html` | pass | pass |
| `edittext_leading` | pass | pass |
| `edittext_line_metrics` | pass | pass |
| `edittext_margins` | pass | pass |
| `edittext_tab_stops` | ruffle_matched | ruffle_matched |
| `edittext_width_height` | pass | pass |
| `edittext_wordwrap_word` | pass | pass |
| `edittext_wrap_breaks` | pass | pass |
| `graphics_draw_path` | ruffle_matched | ruffle_matched |

Coverage read: rows 1-11 exercise **every** other `BitmapData.draw` shape in the
suite — bare-BitmapData source, Bitmap-display-object source, colorTransform,
masks, rotation (the non-identity-2x2 GPU fallback my dispatch must NOT steal),
self-draw-via-graphic, stage source, quality variants, the `copyPixels`
blend-over sibling, and a non-trivial blend mode (`multiply`). Rows 13-25 are the
EditText tag-layout confirmation set. `blend_transform` and `graphics_draw_path`
are my own bucket's two `ruffle_matched` rows, re-graded to prove the ignore-list
move does not disturb them.

---

## 8. Patch scope (exact files, for staging by name)

| patch | files |
|---|---|
| `w2-ignore-bitmapdata_draw_alpha_erase.patch` | `SWFModernRuntime/src/avm2/avm2_bitmap.c` |
| `w2-ignore-edittext_tag_indent.patch` | `SWFRecomp/src/abc/abc_timeline.cpp`, `SWFModernRuntime/include/avm2/avm2_abc.h` |
| `w2-ignore-bucket-ignorelist.patch` | `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` |

All three are independent and can be merged in any order. **No new files.**

**Cross-agent conflict check, run against the reports directory at 23:13.**
Diffed the file lists of every sibling patch present
(`w2-geom.patch`, `w2-geom-a.patch`, `w2-avm1-child.patch`,
`w2-avm1-child-probe.patch`, `w2-avm1-child-docs.patch`): siblings touch
`avm2_display.c`, `avm2_stage3d.c` and
`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`. **Zero overlap with my
three files**, and I am the only agent editing
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`. The one coordination point
remains `stage_scale_factor` (§5): if w2-geom's twip fix flips it, delete that
one line from the block my ignore patch writes.
The two code patches touch no file any sibling was assigned
(`avm2_display.c`, `render_webgpu.c`, `avm2_filters.c`, Loader/depth code are
all untouched).

CI mode for the merged run: **`graphics`** (both fixes are shared runtime /
recompiler code, not `NO_GRAPHICS`-only), **`categories=full`** is advisable
because the recompiler's emission changed (`avm2_generated_edittexts[]`), which
is exactly the trigger the CI-categories policy names.

---

## 9. Refutations / notes for the next board

1. **"Un-ignoring gains points" — false.** `ignored_tests.txt` is invisible to
   `verify_output.py` and to `corpus_status_diff.py`. Only code fixes move the
   graded number. (§2)
2. **"`bitmapdata_draw_alpha_erase` is about `alphaBitmapData`" — false.** It is
   about the `blendMode` argument of `BitmapData.draw`. (§4.1)
3. **`edittext_tag_indent` was priced as "11 lines, indent sign + one line-break
   difference", i.e. two mechanisms. It is ONE mechanism** — the wrap difference
   is a downstream consequence of the sign error. (§4.2)
4. **Two of the eight (`blend_transform`, `graphics_draw_path`) were never
   failures at all** — both are `ruffle_matched`, i.e. already inside
   `effective_pass`, and both are `known_failure = true` upstream. Any board that
   costs this bucket at "8 rows" is over-counting by 2. (§3)
5. **The shared scratchpad is NOT per-agent.** Two of my scratchpad scripts were
   overwritten mid-session by siblings writing the same generic filenames
   (`base.py`, `copy_canaries.sh`) into
   `/tmp/claude-1000/.../<session>/scratchpad/` — the directory is keyed by
   SESSION, not by agent. Namespace every scratchpad file with your agent id.
   Nothing was lost here (the collision hit two throwaway helpers, and my
   result logs live in a uniquely-named subdirectory), but a batch driver or a
   results file clobbered this way would silently corrupt a ledger.
6. **Both fixes are dual-axis.** The trace board and the pixel board were
   costing these rows separately; neither noticed that the image comparison
   fails *for the same reason* the trace does. `wave1-gfx-board.md:415-420`
   carries both rows as soft `[trace-ign]` flags with their outlier counts
   (15 000 and 7 884), i.e. the pixel board explicitly kept them on its list —
   so these two pixel flips are **new gains, not double-counting** any gfx
   sibling's claim. Worth a general sweep of the remaining
   `[image_comparisons]` tests whose trace also fails: the image diff may come
   free once the trace is right.
