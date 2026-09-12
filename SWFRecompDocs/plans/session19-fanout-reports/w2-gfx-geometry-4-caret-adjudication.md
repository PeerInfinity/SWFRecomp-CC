# w2-gfx-geometry addendum — `visual/edittext/edittext_caret_empty` is UPSTREAM DRIFT, not a regression

**Verdict: NOT MINE, and not anyone's patch. No `w2-gfx-geometry-4-caretfix.patch` is delivered,
deliberately — there is nothing in our tree to revert or narrow.** The 11 pass → fail comparisons in
run `34657699925` are caused by an upstream Ruffle commit that **tightened the test's tolerance from
128 to 64** while our rendered pixels did not move by a single bit.

Measured in a worktree rebased on current master (`53b7df481`, i.e. past `b50d40036` and the EditText
border-corner change `e5dff31ab`), local Dawn, `--mode=graphics --images --recompile`.

---

## 1. The one-line proof

`max_diff` is **95 in both runs**:

| run | SHA / date | `outliers` | `max_diff` | verdict |
|---|---|---|---|---|
| s18 `33945288707` | `12d2ec06b` · 2026-09-05 | **0** | **95** | pass ×12 |
| new `34657699925` | `f48c532bf` · 2026-09-12 | **36** | **95** | fail ×11, pass ×1 |

A render regression moves `max_diff`. This one does not. The same 95-magnitude difference was present
and *tolerated* in s18; it is now *not tolerated*.

## 2. The upstream commit

`~/CC/ruffle` `0fa6a04af` — "core: Improve subpixel caret rendering", Kamil Jarosz, **2026-09-06**
(i.e. the day AFTER the s18 image run, and it is an ancestor of our synced `0631814db`). It changes
exactly two files, `core/src/display_object/edit_text.rs` and this test's `test.toml`:

```
-tolerance = 128        (x11)
+tolerance = 64
 [image_comparisons."output.03"]
-tolerance = 128
+[[...checks]] tolerance = 64  max_outliers = 3
+[[...checks]] tolerance = 192
```

**Zero `*.expected.png` files changed in that commit** (`git show --stat | grep -c expected.png` → 0),
so the goldens we compare against are the same bytes as in s18.

Two corroborations:
- Our `test.toml` is byte-identical to upstream's post-`0fa6a04af` version, and both it and
  `output.01.expected.png` carry mtime **09-11 14:21** — the session-start test-tree sync named in
  `BRIEFS_COMMON.md`. That is when the tolerance arrived.
- **`output.03` is the only comparison still green, and it is the only one upstream gave a
  `tolerance = 192` escape check.** That is a fingerprint of a tolerance change; a render regression
  has no reason to spare exactly the row with the loosened second check.

## 3. Our render did not move — direct A/B across all six landed patches

Ran the test at the **session base `e36bca73e`** (before any of the six patches, mine included) and at
current master `53b7df481`:

| | `output.01.actual.png` md5 | verdicts |
|---|---|---|
| `e36bca73e` (pre-everything) | `ce4b0a5334b77e0de9bb53e903eadfcf` | 11 fail @36/95, `output.03` pass |
| `53b7df481` (current master) | `ce4b0a5334b77e0de9bb53e903eadfcf` | identical |

**Byte-identical.** This is a stronger test than reverting individual patches: it predates all six,
so it cannot be confounded by what a worktree base did or did not already contain. It also settles the
coordinator's caveat — **`w2-gfx-text` was right**, and its "byte-identically with every patch
reverted" note in `e5dff31ab` agrees with this measurement.

## 4. Why my LINESTYLE2 patch could not have done it anyway

The 36 outlier channels are 12 pixels at `(45,25) (90,25) (135,25) (180,25)` and the same four x at
`y = 50` and `y = 75` — a 45×25 grid, i.e. **the bottom-right corner pixel of each of the 12 EditText
boxes**. Ours is `(0,0,0)`, Ruffle's `(95,95,95)`.

That pixel is drawn by `avm2_display.c::avm2_render_textbox`, which paints the border as four
full-coverage `avm2_border_rect()` quads. It is runtime EditText border geometry and never touches
`SWFRecomp/src/swf.cpp`'s `drawLines`/`drawLineCap`/`drawLineJoin` — the only thing patch 3 changed.
It is also not a caret, despite the test's name.

The cap/join hypothesis was reasonable (a caret *is* the sub-2-px regime my own calibration note
flags), but it does not survive contact: patch 3 only ever fires for a DefineShape4 LINESTYLE2 word,
and the fresh corpus scan found exactly five SWFs with a non-round one — this is not among them.

## 5. Is the 95-difference a real gap? Yes — and here is the owner and the mechanism

Upstream did not tighten the tolerance arbitrarily; they tightened it because Ruffle's own caret got
more precise. Our 95 is a genuine EditText-border rendering gap that was simply under the old bar.

**It belongs to the EditText border arm, i.e. whoever owns `e5dff31ab`** (`w2-gfx-text` /
`avm2_render_textbox`), not to geometry. Completion mechanism, so it is actionable:

- The border is four full-coverage rects, so the shared bottom-right corner pixel can only ever be
  **0 % or 100 % inked** — today's `corner_missing` flag just chooses between those two. Ruffle's is
  **63 % inked** (95 on a white ground). No setting of a boolean can produce 63 %.
- The fix is therefore to give the bottom and right rects their true **fractional** device extent on
  the antialiased arm — `(by + bh) / dtw` unrounded — and let MSAA resolve the partial coverage,
  instead of the binary include/exclude. Note `e5dff31ab` deliberately left the `#else`
  (`MSAA_SAMPLES > 1`) arm alone and its comment asserts "both antialiased segments cover the corner,
  so it is always painted"; **this test is `quality = "high"` and disproves that assertion.**
- Blast radius: every `edittext_border_*` row (four are tier-1 canary comparisons) plus the
  `text/auto_size/*` rows `e5dff31ab` just tuned. It needs the same four-golden measurement
  `e5dff31ab` did for the Low arm, done on the High arm.
- `visual/edittext/edittext_caret_multiline` is in the new image JSON and absent from s18's — same
  family, worth folding into that slice.

## 6. Ledger

### All 12 `edittext_caret_empty` comparisons (tolerance from the synced `test.toml`)

| comparison | tol | s18 `33945288707` | master `53b7df481` | base `e36bca73e` |
|---|---|---|---|---|
| `output.01` | 64 | pass, 0 out, md 95 | **fail, 36 out, md 95** | fail, 36 out, md 95 |
| `output.02` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.03` | 64 + **192 escape** | pass, 0, 95 | **pass**, 0, 95 | pass, 0, 95 |
| `output.04` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.05` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.06` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.07` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.08` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.09` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.10` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.11` | 64 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |
| `output.12` | 65 | pass, 0, 95 | fail, 36, 95 | fail, 36, 95 |

s18 tolerances were **128** on all twelve. The rendered PNG is byte-identical in the two local columns.

### My three flips, re-verified at current master `53b7df481`

| comparison | expected | measured at master | |
|---|---|---|---|
| `avm2/displayobject_getbounds_shape` | 3 716, PASS (limit 3 800) | **3 716, PASS** | ✅ holds |
| `visual/blend_across_masks_issue_24549` | 0, PASS | **0, PASS**, max diff 0 | ✅ holds |
| `avm2/graphics_simple_shapes` | 154 | **154** | ✅ holds |
| `avm2/graphics_gradients` | 349 | **349** | ✅ holds |
| `avm2/graphics_bitmaps` | 959, PASS (limit 4 000) | **959, PASS** | ✅ holds |
| `from_shumway/acid/acid-small` (tripwire) | 25 989 / 25 959, PASS | **25 989 / 25 959, PASS** | ✅ tripwire green |

Nothing I landed has drifted across the six commits that followed it.

## 7. Recommendation

1. Record `visual/edittext/edittext_caret_empty` ×11 as **upstream drift** (`BRIEFS_COMMON` rule 12),
   not a regression, in the run-`34657699925` readout.
2. Route the underlying 95-magnitude BR-corner gap to the EditText border owner with §5.
3. Process note worth carrying forward: the misc categories' image baseline was s18's run
   `33945288707` from **2026-09-05**, while the test tree was re-synced from upstream on **09-11**.
   Any misc-category pass → fail in this session's first images run must be checked against the
   upstream `test.toml` before it is attributed to a patch. `max_diff` unchanged + `outliers` moved is
   the cheap tell.
