# w2-gfx-text-smalls — session 20 wave 2. Two independent fixes, two patches.

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a41dd063596b61dbf`
(branched at `ff94b2338`, which is `4b05de6ef` + the docs-only brief commit).
Scratch: `<scratchpad>/w2-gfx-text-smalls/`.

---

## NEW FILES (stage these BY NAME — `git add -u` drops them)

```
SWFRecompDocs/plans/session20-fanout-reports/w2-gfx-text-smalls-1-devicefont.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-gfx-text-smalls-2-edittext-border.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-gfx-text-smalls-report.md
```

No new source files. Both patches edit existing TUs only, so there is nothing to add
to `verify_output.py`'s source list, CMakeLists or the Emscripten build.

**Files touched (all inside my assigned scope):**

| patch | file | region |
|---|---|---|
| 1 | `SWFModernRuntime/src/avm2/avm2_text.c` | new `find_device_font_ladder` + its one call site in `find_device_font_list` (~`:2606`) |
| 2 | `SWFModernRuntime/src/libswf/tag.c` | `textfield_render_cb`'s closed-outline border branch + one `#ifndef MSAA_SAMPLES` guard above the function |
| 2 | `SWFModernRuntime/src/avm2/avm2_display.c` | `avm2_render_textbox` ONLY — the device arm's four `avm2_border_rect` calls (~`:18549`) and the `corner_missing` block (~`:18635`). ~9 000 lines from `w2-evenodd`'s `gfx_finalize_path` (`:8695`) / `gfx_line_style` (`:9212`); coordinator approved, no textual overlap |
| 2 | `ruffle-tests/render_canary_tests.txt` | appended at EOF (expected 3-way conflict) |

**Patch-2 carries BOTH canary members**, for patch 1 and patch 2, in one EOF block —
splitting them would put two same-offset EOF hunks in one file and make the merge worse.
**If patch 1 lands without patch 2, move the `fonts/device_font_kerning` member across.**

---

## 0. Verdict board — lead with this

| fix | verdict | flips | band-only | comparisons |
|---|---|---:|---|---|
| **2 — EditText border corner** | **GO** | **+11** | + 3 rows improved, still failing | `visual/edittext/edittext_caret_empty` `output.{01,02,04,05,06,07,08,09,10,11,12}` all **fail → pass** |
| **1 — device-face bold/italic ladder** | **GO, but book it as ZERO** | **0** | **0 — not even a band move** | `visual/fonts/device-font` 8205 → **8205**; `visual/fonts/leading_device_font` 12 978 → **12 978** |

**Priced total: +11 pixel-comparison flips, 0 regressions.** All eleven are **flips**, not band
moves: every one goes to `0 outliers` with `max difference 31` against a tolerance of 64, i.e.
33 channels of headroom, not a marginal pass.

**Three premises of my brief attacked, all three wrong as stated:**

1. *"The corner is the whole residual of the three EditText rows"* — **REFUTED for two of the
   three.** Only `edittext_caret_empty` (11 cmps) is corner-limited. `edittext_caret_multiline`
   (6 cmps) is a **missing caret**, zero border pixels; `edittext_border_transform` (2 cmps) is
   the **rotated-box diagonal fallback**, and its corners are 95 < its tolerance of 128 so they
   were never outliers. Priced slice: **11 comparisons, not 19.** (Sent to the coordinator
   early; both re-planned.)
2. *"Owner and fix in `SWFRecompDocs/BACKLOG.md`"* — the fix is right, **the owner is wrong.**
   The backlog names `avm2_render_textbox` / `avm2_border_rect`. `edittext_caret_empty` is a
   **SWF v8 AVM1** movie (`CWS` v8, no `RecompiledABC`); its border is drawn by
   `tag.c::textfield_render_cb`. I patched `avm2_display.c` first and measured **zero change**
   — that is how the misattribution surfaced. See §2.2.
3. *"100 % of `device-font`'s own residual is a ~15-LOC bug"* — **true only on top of the
   unlanded A1 outline prototype.** At HEAD `device-font` renders **0 ink pixels** (the board's
   own `blank_render` cluster), so there are no glyphs for the ladder to move and it changes
   nothing. Measured, not argued: §1.3. The LOC estimate was accurate (+43 with comments,
   ~21 of code).

**And one premise of session 19 refuted in our favour** — the biggest single finding here:

> s19 A1: *"the device-font arc is REAL, CHEAP and FLIPS NOTHING at today's budgets…
> `device-font` 8205 → **13 065**, render goes blank → correct, count RISES."*

That was measured **without** A1s. In one tree, one build, same session, A/B'd:

| build | `visual/fonts/device-font` outliers (budget **3**) |
|---|---:|
| HEAD | 8 205 (blank render) |
| HEAD + A1 prototype, no ladder | **13 065** ← s19's number, reproduced exactly |
| HEAD + A1 prototype + **patch 1** | **15** |

**The ladder removes 13 050 of A1's 13 065 — 99.89 %.** A1 is not a 13k-outlier band arc; with
patch 1 it is **12 outlier channels (5 pixels) away from flipping `device-font`**. s19's A1
pricing should be reopened. §1.4.

---

## 1. Fix 1 — the device-face bold/italic ladder

### 1.1 Mechanism (confirmed, with the upstream citation)

`avm2_text.c::find_device_font_list` walked the comma-separated family list and, per entry,
called `find_device_font` — **one exact `(name, bold, italic)` probe**. Ruffle's
`get_or_load_device_font` (`core/src/library.rs:576-590`) does the exact probe **and then**
`FontMap::find` (`library.rs:788-845`), the compatibility ladder whose order is pinned by
upstream's own `tests/swfs/fonts/embed_matching/fallback_preferences`:

1. exact `(name, bold, italic)`;
2. if `bold XOR italic`: bold-italic → regular → the other one;
3. else: (bold-italic only) regular → bold → italic → (regular only) bold-italic.

`resolve_font` **20 lines above** already ran exactly that ladder for embedded faces. Device
faces got none of it, so a span asking for a style the family does not register fell through
`find_device_font_list`'s `return NULL` to the metrics-only baked `noto_device_font`
(`avm2_text.c:2528`, em 20480 / ascent 21931) — losing the run's glyphs **and** inflating the
line box, because real Tinos is em 2048 / ascent 1825 (26.7 px at size 30 vs Noto's 32.1 px).
That is the measured "+5 px low on line 1, +8 px on line 2, 36 px line pitch vs the golden's 33".

**Per-entry, not two-pass.** `layout.rs:563-590` loops the comma-separated names and calls
`get_or_sort_device_fonts` on **each**, so the ladder belongs inside the loop. The
"exact over all names, then ladder over all names" two-pass shape is
`get_or_load_default_font` (`library.rs:500-533`), which serves the `_sans`/`_serif`
`DefaultFont` aliases — a different code path we do not implement. Patch 1 puts the ladder
per entry.

### 1.2 Patch scope

`SWFModernRuntime/src/avm2/avm2_text.c`, one file, +43/-3 lines (21 of them code):
a new `static const Avm2FontData* find_device_font_ladder(name, len, bold, italic)` directly
above `is_ws`, plus swapping the single `find_device_font` call in `find_device_font_list`
for it. Nothing else in the runtime changes; every call site of `resolve_font` is untouched.

### 1.3 Pricing — BAND vs FLIP, stated plainly: **NEITHER.**

`--mode=graphics --images`, local Dawn, this worktree:

| comparison | budget | before | after | verdict |
|---|---|---:|---:|---|
| `visual/fonts/device-font` | tol 0, max_outliers **3** | 8 205 | **8 205** | **unchanged — not a flip, not a band move** |
| `visual/fonts/leading_device_font` | tol 128, max_outliers **0** | 12 978 | **12 978** | unchanged |
| `fonts/device_font_kerning` | tol 0, max_outliers 0 | 0 PASS, max diff 0 | **0 PASS, max diff 0** | no regression |
| `fonts/device_font_no_ink` | tol 0, max_outliers 0 | 0 PASS, max diff 0 | **0 PASS, max diff 0** | no regression |
| `avm2/edittext_get_char_index_at_point` | tol 0, max_outliers 0 | 0 PASS, max diff 0 | **0 PASS, max diff 0** | no regression |

Why zero: `visual/fonts/device-font`'s render at HEAD has **0 ink pixels** (I counted them:
expected 2 735, ours 0 — the wave-0 board's `blank_render` cluster label is literal). The
device faces `test.toml` registers are emitted **metrics-only**, so no glyph the ladder
re-routes can draw. The ladder changes *which metrics-only face* the italic run selects, and
a metrics-only face draws nothing either way. `device-font` also has an **empty `output.txt`**
and a fixed-size, non-autosized field, so the line-geometry change is not trace-visible.
`leading_device_font`'s two faces (`TestFontGap0`, `TestFontGap100`) register regular only
and the SWF asks for regular, so the ladder never fires there at all.

**Land it as a correctness prerequisite, not as yield.** It is a live engine bug for any
content whose device family lacks an italic or bold face (the run silently disappears and the
line box grows), and it is the enabling half of the A1 arc below — but on today's corpus it is
worth exactly 0 flips and 0 band.

### 1.4 The measurement that makes patch 1 worth landing — and re-prices s19's A1

To prove the patch is not dead code I applied s19's archived
`UNLANDED-devicefont-prototype.patch` **temporarily** (recompiler only; reverted, rebuilt, and
NOT delivered), and A/B'd the ladder underneath it in the same tree and the same Dawn build:

| build | `device-font` (budget 3) | `leading_device_font` (budget 0) |
|---|---:|---:|
| HEAD | 8 205 | 12 978 |
| + A1 prototype, ladder OFF | **13 065** | 18 |
| + A1 prototype, ladder **ON** | **15** | 18 |

s19's 13 065 and 18 both reproduce to the digit, so the two measurements are comparable.
**The ladder is 99.89 % of A1's residual on `device-font`.** s19 priced A1 as "a correctness
arc, not a flip arc" off the 13 065 — that verdict was taken **without its own sub-lead
applied**, and it does not survive applying it: A1 + patch 1 leaves `device-font` at
**15 outlier channels = 5 isolated pixels** against a budget of 3.

Residual after A1 + ladder, forensically:

* `device-font`: **5 pixels**, `(63,45) (77,70) (106,47) (114,31) (166,45)`, every one
  `ours (255,255,255)` vs `expected (0,0,0)` — single missing black pixels on a
  `quality = "low"` (1-bit, MSAA_SAMPLES == 1) glyph raster. Pixel-centre ties, not geometry:
  the x positions, advances, kerning, glyph size and line pitch are all exact now.
* `leading_device_font`: **6 pixels**, `(50|102|154, 80|180)`, `ours 64` vs `expected 255` —
  a 3/4-covered sample where Ruffle has none. Different mechanism, unaffected by the ladder.

---

## 2. Fix 2 — the EditText border's bottom-right corner

### 2.1 Mechanism — the corner is PARTIAL, and no boolean can express that

Ruffle draws the closed box outline as **one `LineStrip`**, indices `[0,1,2,3,0]`
(`render/wgpu/src/descriptors.rs:237`, `pipelines.rs:118`
`PrimitiveTopology::LineStrip`), whose vertices sit at the `HALF_PX`-offset box corners. The
**top and left** segments run *through* their corners (they start/end at the far corners), so
TL, TR and BL are solid. The **bottom and right** segments both *terminate at the centre of
the bottom-right corner pixel*: the bottom inks only its left half, the right only its top
half. Union = 3/4 of the pixel, never 4/4.

Our painter emits four **full-coverage** quads, so that pixel could only ever be 0 % or 100 %
inked. The `corner_missing` boolean chose between those two, and the goldens want neither.
Measured in the goldens (value of the BR corner pixel; 0 = solid black on white):

| golden | box | golden BR | ours (before) | tolerance |
|---|---|---:|---:|---:|
| `visual/edittext/edittext_caret_empty` ×12 boxes | 40 × 20 at whole px | **95** | 0 | **64, max_outliers 0** |
| `visual/edittext/edittext_border_transform` `.04`/`.06` ×6 | 15 px grid | 95 | 0 | 128 |
| `avm2/edittext_autosize_height_dynamic` | 36 × 44 at origin | **111** | 0 | 128 |
| `visual/edittext/edittext_selection_leading` | | **111** | 0 | 128 |

`e5dff31ab`'s `MSAA_SAMPLES > 1` comment ("both antialiased segments cover the corner, so it
is always painted") is **half right and wholly misleading**: the corner IS painted, but only
partially. `edittext_caret_empty` is `quality = "high"` and disproves the "always" — as the
backlog says. A previous session had also tried the *other* boolean (open the corner, i.e.
white): the `tag.c` comment records it cost 36 channels at 255-vs-95, i.e. **160 off** where
full-black is **95 off**. Both booleans fail a tolerance of 64. Only a partial pixel passes.

**The fix**: end the bottom rect half a device pixel short and extend the right rect half a
device pixel down, so the two **meet at the corner pixel's centre** exactly as Ruffle's two
line segments do, and let MSAA resolve it. At `MSAA_SAMPLES == 4` the union of "left half" and
"top half" covers 3 of the 4 standard WebGPU sample positions → **64 of 255**, i.e. **31 from
the golden's 95** instead of 95. Measured output: `max difference 31` on all twelve.

MSAA-gated in both painters (`#if MSAA_SAMPLES > 1`): at `MSAA_SAMPLES == 1` the lone
pixel-centre sample lands exactly on the new edge and would drop the corner to white, and the
aliased arm already has its own four-golden measured rule from `e5dff31ab` which I did not
touch. `text/auto_size/{height,return,width}` are the `quality = "low"` rows that rule serves;
they are AVM2 and aliased, so patch 2 is inert for them by construction.

### 2.2 Refutation: the BACKLOG's owner attribution is wrong for the flip-bearing rows

The backlog entry (`SWFRecompDocs/BACKLOG.md:719-733`) names `avm2_render_textbox` /
`avm2_border_rect`. I patched exactly that first — **and `edittext_caret_empty` did not move a
single channel** (36/95 before, 36/95 after, twice over). The reason:

| test | SWF | `RecompiledABC` | border painter |
|---|---|---|---|
| `visual/edittext/edittext_caret_empty` | `CWS` **v8** | no | **`tag.c::textfield_render_cb`** (AVM1) |
| `visual/edittext/edittext_border_transform` | `CWS` **v8** | no | **`tag.c`** (AVM1) |
| `avm2/edittext_autosize_height_dynamic` | `CWS` v41 | yes | `avm2_display.c` |
| `visual/edittext/edittext_selection_leading` | `CWS` v41 | yes | `avm2_display.c` |
| `text/auto_size/*` | `CWS` v15 | yes | `avm2_display.c`, aliased arm |

So the flip-bearing half of patch 2 is in **`tag.c`**. I fixed **both** painters, because it is
one bug with two implementations and the AVM2 half measurably improves two more rows (§2.3) —
but the +11 comes entirely from `tag.c`.

### 2.3 Patch scope

* `SWFModernRuntime/src/libswf/tag.c` — `textfield_render_cb`, the `else` (closed-outline)
  branch of the `has_border` block: two new locals `bot_w` / `rgt_h`, MSAA-gated, used by the
  bottom and right `renderer_draw_rect` calls. Plus one `#ifndef MSAA_SAMPLES / #define 4`
  guard above the function (the harness only passes `-DMSAA_SAMPLES=N` when N != 4, mirroring
  `avm2_display.c:18379`). +37/-2, 6 lines of code.
  The `line_rect` (device-font + matrix) branch is **untouched**.
* `SWFModernRuntime/src/avm2/avm2_display.c` — `avm2_render_textbox` only:
  the device arm (`flags & 4u`) gains a `corner_dev` local used by its bottom and right rects,
  and the embedded-font arm's `corner_missing` block gains a `corner_ext` local (`dtw` on the
  aliased arm, `dtw/2` on the MSAA arm) that the bottom/right rects use instead of `dtw`.
  The existing `corner_missing` verdict is **kept**, so fractional-extent boxes behave exactly
  as before — that is what protects `edittext_border_transform` `.01-.03` (tolerance 0). +62/-8.
* `ruffle-tests/render_canary_tests.txt` — +33 at EOF (see §4).

### 2.4 Per-comparison before/after (local, `--mode=graphics --images`)

Baselines are the CI run `34666689502` @ `d8da5a18c` rows in
`ruffle-tests/tests/swfs/*/_results/image_results_graphics.json`, **and** re-measured locally
in this worktree before the patch — the two agree on every row below.

| comparison | tol / max_out | before | after | verdict |
|---|---|---:|---:|---|
| `visual/edittext/edittext_caret_empty` `output.01` | 64 / 0 | 36 out, md 95 | **0 out, md 31** | **FLIP** |
| … `output.02` | 64 / 0 | 36 / 95 | **0 / 31** | **FLIP** |
| … `output.03` | 64 / 0 **+ 192 escape** | 0 / 95 pass | 0 / 31 pass | held |
| … `output.04` – `output.11` (8 rows) | 64 / 0 | 36 / 95 each | **0 / 31 each** | **FLIP ×8** |
| … `output.12` | 65 / 0 | 36 / 95 | **0 / 31** | **FLIP** |
| `visual/edittext/edittext_border_transform` `output.01` | 0 / 0 | 0, md 0 pass | **0, md 0 pass** | held (byte-identical) |
| … `output.02` | 0 / 0 | 0, md 0 | **0, md 0** | held |
| … `output.03` | 0 / 0 | 0, md 0 | **0, md 0** | held |
| … `output.04` | 128 / 20 | 51, md 207 | **50**, md 207 | band −1, still fail |
| … `output.05` | 128 / 20 | 0, md 97 pass | 0, md 97 pass | held |
| … `output.06` | 128 / 20 | 44, md 207 | **43**, md 207 | band −1, still fail |
| `visual/edittext/edittext_gutter` | 128 / 0 | 1 032 | **1 014** | band −18, still fail |
| `visual/edittext/edittext_selection_leading` `.01-.08`,`.10`,`.12` | 128 / 0 | 0 out, **md 111** | 0 out, **md 47** | held, +64 headroom |
| … `output.09`, `output.11` | 128 / 36 | 36 out (at limit), md 255 | **36 out, md 255** | held, unchanged |
| `avm2/edittext_autosize_height_dynamic` | 128 / 0 | 0 out, **md 111** | 0 out, **md 47** | held, +64 headroom |
| `avm2/edittext_get_char_index_at_point` | 0 / 0 | 0, md 0 | **0, md 0** | held (byte-identical) |
| `fonts/device_font_kerning` | 0 / 0 | 0, md 0 | **0, md 0** | held |
| `fonts/device_font_no_ink` | 0 / 0 | 0, md 0 | **0, md 0** | held |
| `avm1/frame_size_translated_positive` | 0 / 1 | 1 out (at limit) | **1 out** | held, unchanged |
| `visual/edittext/edittext_caret_multiline` `.01-.06` | 64 / 0 | 60 each | **60 each** | unchanged — not this bug |

**+11 flips, 0 regressions, 3 rows improved but still failing, 2 rows given 64 channels of
new headroom.** The risk set was chosen by scanning every comparison in the baseline JSON for
`quality != "low"` + a `border` mention in the test source + `tolerance < 64` — 11 rows, all
of them above.

### 2.5 The upstream `test.toml` check for `edittext_caret_empty` (brief trap (a))

Re-checked against the session's fresh `~/CC/ruffle` @ **`f2aaf0703`**:

```
diff ~/CC/ruffle/tests/tests/swfs/visual/edittext/edittext_caret_empty/test.toml \
     ruffle-tests/tests/swfs/visual/edittext/edittext_caret_empty/test.toml   → IDENTICAL
md5  …/output.01.expected.png                → b811b4f469d356e871c261cf4730d14c  (both)
```

`edittext_caret_multiline` and `edittext_border_transform` likewise byte-identical, `test.toml`
and goldens. **No further tolerance drift since s19's `0fa6a04af` find** — the bar is still
`tolerance = 64, max_outliers = 0` on eleven rows and `64 + a 192 escape check` on `output.03`.

And trap (b) — s19's "a real regression moves `max_diff`, drift moves only `outliers`" — is
what makes these eleven safe to book as ours: `max_diff` moves **95 → 31**, and it moves
because our pixels changed, not because a number in a TOML did. s19 was right that the 2026-09-06
`0fa6a04af` tolerance tightening (128 → 64, zero golden bytes changed) is what turned these red;
that also means the older "our 95 was enough" is gone for good, and 31 is the first value that
clears the new bar.

---

## 3. Tests run

Everything below ran in this worktree, `--mode=graphics`, sequentially (`-P 1`),
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `DAWN_INSTALL=/home/robert/CC/dawn-install`,
test dirs `cp -r`'d into the worktree's canonical suite paths with `Recompiled*` stripped
(the main tree's suites were never used as `--tests-dir`).

### 3.1 Render canary — md5 identity A/B, both patches at once

`ruffle-tests/render_canary.py capture --tier all -P 1 --timeout 5400` on each leg, then
`compare`. The `before` leg was produced by `git apply -R` of both patch diffs (never
`git stash` — `refs/stash` is shared) and restored afterwards; the tree is back to both
patches applied and `git status` shows only my four files.

```
RENDER CANARY  before=before  after=after   44 tests / 75 comparisons
  IDENTICAL    73
  DIFFERS       2
  APPEARED      0   VANISHED 0   NO_RENDER 0
  DIFFERS:
    visual/edittext/edittext_border_transform  output.04   diff_channels 12/40000  max 64
    visual/edittext/edittext_border_transform  output.06   diff_channels 12/40000  max 64
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

The two members patch 2 adds do not exist on the `before` side (reverting patch 2 removes them
from `render_canary_tests.txt`), so they were captured separately as label `before2` with the
patches reverted and compared against the same `after`:

```
RENDER CANARY  before=before2  after=after   2 comparisons
  IDENTICAL     1     fonts/device_font_kerning  output
  DIFFERS       1     avm2/edittext_autosize_height_dynamic  output
                        diff_channels 42/800000  max 64   image status: pass -> pass
```

**Total measured blast radius across all 77 canary comparisons: 3 differ, 74 byte-identical,
0 status changes in either axis.** All three differences are the BR corner pixel and nothing
else — 12 channels (4 corners) on each `edittext_border_transform` tick and 42 channels
(14 corners) on `edittext_autosize_height_dynamic`, every one at `max 64`, i.e. exactly the
0 → 64 corner move.

Two canary members are the direct proof of the two MSAA gates and of patch 1's inertness:

* `text/auto_size/width` — **IDENTICAL**. It is the set's `quality = "low"` EditText-border
  member (s19 added it for exactly this arm), so the `MSAA_SAMPLES == 1` path is confirmed
  untouched.
* `fonts/device_font_kerning` — **IDENTICAL**. A tolerance-0, max_outliers-0, CI-passing test
  that really does resolve `[fonts.*]` device faces, so patch 1's ladder is confirmed inert
  where the exact probe already hits.

`visual/edittext/edittext_caret_empty` is not a canary member; its eleven flips are measured
directly in §2.4 (and re-verified after the final comment-only edit: 12/12 PASS, max diff 31).

### 3.2 `regression` suite

`--tests-dir=ruffle-tests/tests/swfs/regression --mode=graphics --images`, the six text/EditText
fixtures plus the four `regression/` canary members:

| test | result |
|---|---|
| `regression/avm1_parent_child_text` | PASS |
| `regression/avm2_bitmapdata_draw_textfield` | PASS |
| `regression/avm2_parent_child_static_text` | PASS |
| `regression/avm2_static_text` | PASS |
| `regression/avm2_timeline_text` | PASS |
| `regression/avm2_contextmenu_stub` | PASS |
| `regression/avm2_morph`, `avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`, `mask_sibling_union`, `mask_nested_intersect` | PASS, **byte-identical on both canary legs** |

6/6 on the targeted run, 0 image comparisons exported (i.e. none failed), and the tracked
`regression/` tree is clean afterwards (`--verbose` deliberately omitted, since it copies
actual PNGs into the test dir and would dirty a tracked suite). Per the standing rule I did
not run the suite in full.

### 3.3 Note on the final edit

After the canary legs I corrected three comment blocks that mis-cited `edittext_caret_empty` /
`edittext_border_transform` as evidence for the **AVM2** painter (they are AVM1 — §2.2), and
re-ran `edittext_caret_empty`: 12/12 PASS, max difference 31, unchanged. Comments only; no
emitted code changed.

---

## 4. Canary audit (what the standing set could NOT see)

The 42-member standing set had **no member for either change class**:

* **AVM2 EditText border on the antialiased arm.** The only EditText-border members were
  `visual/edittext/edittext_border_transform` — which is **AVM1** (`CWS` v8), so it exercises
  `tag.c`, not `avm2_render_textbox` — and `text/auto_size/width`, which is AVM2 but
  `quality = "low"`, i.e. the `MSAA_SAMPLES == 1` arm. s19 added that one *specifically* to
  cover the aliased arm and noted the gap; the antialiased arm stayed uncovered.
  → added **`avm2/edittext_autosize_height_dynamic`** (tier 1: quality high, tolerance 128,
  CI-passing, six bordered autosized fields through the arm patch 2 changes).
* **AVM2 device-face lookup.** No member registered a `[fonts.*]` device face at all, so a
  change to `find_device_font_list` could only ever report IDENTICAL.
  → added **`fonts/device_font_kerning`** (tier 1: quality high, tolerance 0, max_outliers 0,
  CI-passing at max diff 0 — a full-headroom absolute verdict).

Both appended at EOF of `ruffle-tests/render_canary_tests.txt` with the usual block comment;
a 3-way conflict with the other graphics agents is expected and all blocks should be kept.

No new pipeline was added to `render_webgpu.c`, so the "never a literal 4" rule has nothing to
bite on here; both new gates are `#if MSAA_SAMPLES == 1` / `> 1` on the macro.

---

## 5. Refutations, collected

1. **The corner is NOT the whole residual of the three EditText rows** (§0 item 1). 8 of the 19
   comparisons are a different mechanism. Priced slice 11, not 19.
2. **The backlog's owner for the corner is wrong** — `edittext_caret_empty` is AVM1/`tag.c`,
   not `avm2_render_textbox` (§2.2). Measured by patching the named owner and getting a
   byte-identical render.
3. **"100 % of device-font's residual is a ~15-LOC bug" is conditional on unlanded work**
   (§1.3). At HEAD the ladder moves nothing at all, because the render is blank.
4. **s19's A1 pricing is wrong in the other direction** (§1.4). A1 + the ladder is 15 outliers
   against a budget of 3, not 13 065. Priced without its own sub-lead.
5. **`e5dff31ab`'s MSAA comment is half-right, not wrong**: the corner IS always painted on the
   MSAA arm; the error is that it is painted *fully*. Worth recording because the obvious
   reading of the backlog ("give the bottom and right rects their true fractional device
   extent `(by+bh)/dtw`") would have **regressed** `edittext_border_transform` `.01-.03`, which
   pass at tolerance 0 *because* today's `corner_missing` drops the corner on fractional
   extents. Patch 2 keeps that verdict and changes only the corner-present case.

---

## 6. New unclaimed leads

**L1 — `visual/edittext/edittext_border_transform` `.04` (50/20) and `.06` (43/20): the
rotated-box diagonal fallback.** Owner: `avm2_display.c::avm2_draw_border_line` — no, corrected:
these are AVM1, so the owner is **`tag.c::textfield_render_cb`'s transformed-box path** (the
`has_matrix`, non-`device_box` branch, which draws the border as axis-aligned rects **in local
space through a GPU transform slot**). Ruffle instead emits `emulate_line_as_rect`
(`render/src/lines.rs`): a 1-DEVICE-pixel-thick rect fitted between two **already transformed**
stage points. Ours transforms a locally-thickened rect, so the thickness is scaled and sheared
by the matrix and the diagonal edges land differently. Completion mechanism: after the corner
fix, **every** remaining outlier channel in both comparisons lies on the rotated box's diagonal
edges (x 35-55, y 36-72, plus one at (17,78)) — zero on any axis-aligned edge and zero at any
corner. So porting `emulate_line_as_rect` into the AVM1 transformed-box branch is the whole
residual of both rows. Priced: 2 comparisons; 50 and 43 outliers against a limit of 20, so it
must land most of it, not part.

**L2 — `visual/edittext/edittext_caret_multiline` ×6: the caret is never drawn.** Already
handed to the coordinator, who is giving it its own slot. Each comparison's entire residual is
**20 pixels of solid black** (`ours 255`, `expected 0`), a 1 × 20 vertical bar at
`x = 2 → 22 → 42` (ticks 1-3, char index) and `y = 2-21 → 22-41 → 42-61` (ticks 4-6, line
index). Zero border pixels differ, so patch 2 leaves it at 60/60 exactly.
**Sequencing answer the coordinator asked for: it does NOT touch `avm2_render_textbox`.** The
test is `CWS` v41 with `RecompiledABC`, i.e. AVM2 — so the caret belongs next to
`avm2_display.c`'s EditText **text/selection** drawing (`avm2_render_underlines` and the
selection-highlight code near `avm2_text.c:3926` are the analogues), not to the box painter
patch 2 edits. A caret agent can run **in parallel** with patch 2 as long as it stays out of
`avm2_render_textbox`.

**L3 — `visual/fonts/device-font` is 12 outlier channels from a flip IF A1 lands with
patch 1** (§1.4). Residual is 5 isolated missing black pixels on a `quality = "low"` 1-bit
glyph raster — `(63,45) (77,70) (106,47) (114,31) (166,45)`, all `255` vs `0`. Budget is
`max_outliers 3` (channels), so 5 pixels = 15 channels must become ≤ 1 pixel. That is a
pixel-centre-tie question on the aliased raster, the same family as s19's N5, **not** a
geometry question — advances, kerning, glyph size and the 33 px line pitch are all exact
after the ladder. Completion mechanism: re-run the A1 prototype + patch 1 and diff the
aliased fill rule at those five coordinates against Ruffle's `quality = "low"` raster.
Whoever takes A1 should take this with it; A1's cost/benefit is completely different now
(+110 LOC for a flip-candidate, not for a band).

**L4 — `visual/fonts/leading_device_font`'s last 6 pixels are NOT device-font.** With A1 +
patch 1 it sits at 18 outlier channels = 6 pixels, `(50|102|154, 80|180)`, `ours 64` vs
`expected 255` — we ink a 3/4-covered sample where Ruffle inks nothing. `max_outliers 0`, so
it needs all six. A different mechanism from L3 (we have *extra* ink, not missing ink) and
untouched by the ladder; looks like a thin-stroke/edge-rule question.

**L5 — `visual/edittext/edittext_gutter` moved 1 032 → 1 014 on the corner fix alone**, i.e.
18 of its channels were corner pixels and 1 014 are something else. `max_outliers 0`,
tolerance 128, max diff 255 — a large, separate EditText defect that nobody has characterised
this session.

**L6 — two rows are sitting exactly ON their outlier limit** and will flip red on any
neighbouring change: `visual/edittext/edittext_selection_leading` `.09`/`.11` (36 of 36) and
`avm1/frame_size_translated_positive` (1 of 1). Both are unchanged by my patches (verified),
but they are zero-margin tripwires worth knowing about before the next border/text patch.
