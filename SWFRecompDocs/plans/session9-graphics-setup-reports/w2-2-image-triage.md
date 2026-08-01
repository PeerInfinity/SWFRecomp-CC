# w2-2 — `scripts/image_triage.py`: the pixel-triage board, productionized

Session 9 (graphics setup), wave-2 agent 2. Deliverable is a patch, not a commit:
`<scratchpad>/patches/w2-2-image-triage.patch`.

Spec: `w1b-pixel-triage-tooling.md` §5.2. Prototypes lifted:
`image_triage_proto.py` + `image_rank_proto.py` from the session scratchpad.

| file | change |
|---|---|
| `scripts/image_triage.py` | **new**, 1178 lines — features + classifier + dispositions + ranking + text/markdown board |
| `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md` | `simple_loop_test` entry narrowed to frames 1–2 (+ summary-table row split) |
| `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | `display_object_properties` marked stale (now passes); `pixelDissolve` marked trace-axis-only |
| `.gitignore` | `.image-results/`, `image_triage.{json,md}` |

This report itself is already written to the main checkout and is **not** in the
patch (a `git apply` of a create-hunk over an existing file fails).

---

## 1. What it does

One command after merging an `images=true` run and fetching the branch:

```bash
git fetch origin ruffle-image-results
git worktree add .image-results origin/ruffle-image-results
python3 scripts/image_triage.py          # 22-32 s at --jobs 4, 403 comparisons
```

Defaults resolve everything: the image checkout is searched at
`$IMAGE_RESULTS_DIR` → `./.image-results` → `./image-results` →
`../ruffle-image-results` (branch root *or* its `images/` subdir both accepted),
the per-suite `_results/image_results_graphics.json` files and the expected PNGs
come from this checkout, output lands in `image_triage.json` + `image_triage.md`
and the board prints to stdout. A missing checkout exits with the two-line fetch
recipe rather than a traceback.

Other entry points: `--cluster NAME` (members of one cluster, sorted by excess),
`--test SUITE/TEST` (dump every feature of every failing comparison — this is
what reproduces the `w1b` §4 focus-rect evidence: 204 px, bbox (10,10)–(29,29),
`ink_iou 1.00`), `--from-json` (re-rank without recomputing features, ~1 s),
`--stem`, `--jobs`, `--top`, `--swfs-dir`, `--docs-dir`, `--limit`.

Lifted verbatim from the prototypes as the spec directed: `modal`, `key_of`,
`dilate`, `erode`, `edges_of`, `best_shift`, `bands_of`, `features()`, the
15-way `classify()` with its thresholds, `BAND_PROX`, `CLUSTER_PRIOR`,
`BACKEND_FAMILIES`, `score()`, the per-(test, cluster) roll-up, the frame-phase
detector and the printers. `near_miss_band` is imported from
`build_image_report`, `family_of` from `image_baseline_report` — one definition
of the bands, one of the families. `build_image_report.py` is untouched and
still numpy-free (it runs in CI; this tool is local-only and uses numpy+Pillow).

The diff is always recomputed from actual+expected — the published
`<cmp>.difference.png` is ×4-brightened and alpha-mangled and is never read.

The clustering-key lesson is in the module docstring, in `--help`'s epilog, in
the board header line and in the markdown preamble:

> Rank by MECHANISM first. `hairline_edge_drift` owns 35 of the 44 near-pass
> failures and zero of the moderate-or-worse ones, and it is mostly the
> lavapipe-vs-Flash AA gap — near-pass ranking *alone* aims a fix session at the
> least fixable cluster in the corpus.

---

## 2. Validation — reproduces the wave-1 measurements exactly

Run against the same data (run 30680942974 at `375373786`), `--jobs 4`, 22 s
cold / 32 s with markdown+JSON writes.

```
=== image triage: 403 failing comparisons (11 suites, stem=graphics, git_sha=375373786…) ===

== CLUSTER TOTALS ==
   79 cmps /  54 tests / near   2  same_geometry_wrong_fill   prior=0.80  | Blend modes 19, Shumway acid 19, Focus highlight 11
   70 cmps /  43 tests / near  35  hairline_edge_drift        prior=0.25  | Text 17, Gradients 8, Timeline 8
   67 cmps /  62 tests / near   0  blank_render               prior=0.30  | Stage3D 26, Video/NetStream 9, Shumway acid 8
   32 cmps /  21 tests / near   1  missing_element            prior=0.60  | Text 18, Filters 4, Text 3
   30 cmps /  28 tests / near   2  diffuse_mixed              prior=0.40  | Text 8, Shumway acid 5, Text 3
   30 cmps /  24 tests / near   1  content_displaced          prior=0.50  | Text 12, Masks 6, BitmapData 3
   29 cmps /  24 tests / near   1  extra_element              prior=0.60  | Masks 9, Filters 7, (unclassified) 3
   19 cmps /   9 tests / near   0  unrelated_content          prior=0.15  | Video 9, Transforms 4, Masks 2
   16 cmps /  15 tests / near   0  halo_penumbra              prior=0.90  | Text 5, Filters 5, Stage3D 2
   13 cmps /  13 tests / near   2  row_banded                 prior=0.55  | Shumway acid 4, Text 3, Text 2
    6 cmps /   4 tests / near   0  global_color_shift         prior=1.00  | Transforms 3, Filters 1, (unclassified) 1
    5 cmps /   3 tests / near   0  no_render                  prior=0.00  | Shumway acid 3, Video 2
    4 cmps /   4 tests / near   0  offset_translation         prior=1.00  | Text 3, Shumway acid 1
    2 cmps /   2 tests / near   0  whole_frame_wrong          prior=0.35  | Filters 1, Gradients 1
    1 cmps /   1 tests / near   0  localized_region           prior=0.55  | Text 1

== CLUSTER x BAND ==
cluster                    a_eps b_tiny c_small d_mod e_large f_cat
same_geometry_wrong_fill       0      2     29     32     16      0
hairline_edge_drift           22     13     26      9      0      0
blank_render                   0      0      1     10     29     27
missing_element                0      1      4      7     18      2
diffuse_mixed                  0      2      6     19      3      0
content_displaced              0      1      2     19      6      2
extra_element                  0      1      3     10     15      0
unrelated_content              0      0      0      1      9      9
halo_penumbra                  0      0      0      7      8      1
row_banded                     0      2      5      6      0      0
global_color_shift             0      0      0      0      2      4
offset_translation             0      0      1      2      1      0
whole_frame_wrong              0      0      0      0      2      0
localized_region               0      0      1      0      0      0
```

Every cell matches `w1b` §2. `no_render` (5) prints as its own cluster row
rather than being folded away.

### Top 20 (as shipped, i.e. with the amended `simple_loop_test` scope)

```
== TOP 20 TESTS (of 277 live test x cluster rows, 369 comparisons; 34 excluded
   as dispositioned / known_failure / no_render) ==
   ranked by MECHANISM x fanout x band-proximity — near-pass alone would put the
   unfixable AA cluster on top
  # score cmp fanT suite/test                                        cluster                  band       excess
  1  5.26  16    4 from_shumway/acid/acid                            same_geometry_wrong_fill c_small    4761
  2  3.27   4    3 visual/focus_highlight/focus_highlight_avm1_button same_geometry_wrong_fill d_moderate 168
  3  2.88   6    3 avm2/focusrect                                    same_geometry_wrong_fill d_moderate 408 [trace-ign]
  4  2.63   1    4 from_shumway/acid/acid-color-0                    same_geometry_wrong_fill c_small    37867
  5  2.37  12    7 visual/edittext/edittext_selection_leading         missing_element          e_large    18179
  6  2.18   1    7 visual/filters/color_matrix                       same_geometry_wrong_fill b_tiny     339
  7  2.11   1   19 visual/blend_modes/add                            same_geometry_wrong_fill d_moderate 13405
  8  2.11   1   19 from_shumway/acid/acid-blend-2                    same_geometry_wrong_fill d_moderate 14912
  9  2.11   1   19 avm2/blend_transform                              same_geometry_wrong_fill d_moderate 15000 [trace-ign]
 10  2.11   1   19 visual/blend_modes/lighten                        same_geometry_wrong_fill d_moderate 18823
 11  2.11   1    4 from_shumway/acid/acid-child                      same_geometry_wrong_fill d_moderate 20544
 12  2.11   1   19 visual/blend_modes/hardlight                      same_geometry_wrong_fill d_moderate 30408
 13  2.11   1   19 visual/blend_modes/overlay_onto_stage             same_geometry_wrong_fill d_moderate 41293
 14  2.11   1   19 visual/blend_modes/darken                         same_geometry_wrong_fill d_moderate 42847
 15  2.11   1    4 from_shumway/acid/acid-bitmapData-copyPixels      same_geometry_wrong_fill d_moderate 53760
 16  2.11   1   19 visual/blend_modes/subtract                       same_geometry_wrong_fill d_moderate 65601
 17  2.11   1   19 visual/blend_modes/multiply                       same_geometry_wrong_fill d_moderate 66608
 18  2.11   1   19 from_shumway/acid/acid-blend                      same_geometry_wrong_fill d_moderate 77416
 19  2.11   1   19 visual/blend_modes/overlay                        same_geometry_wrong_fill d_moderate 84068
 20  1.98  12    5 visual/edittext/edittext_caret_empty               hairline_edge_drift      a_epsilon  21
```

Identical ordering and scores to `w1b` §3.1. `w1b` ran with the pre-amendment
docs and reports 274 rows / 364 comparisons / 39 excluded; running this tool
with the pre-amendment docs reproduces those three numbers exactly, together
with its 11-row dispositioned table. Top groups also match: acid 19, blend 19,
focus 11, Stage3D 26 [BACKEND], EditText hairline 17 (near 15), EditText
missing 15, EditText displaced 11.

---

## 3. Three deviations from the prototype, all deliberate

### 3.1 Dispositions are parsed from the docs, not hardcoded

`image_rank_proto.py` carried a 7-entry hand-written `DISPOSITIONED` dict, which
goes stale the moment someone edits `ACCEPTED_DIFFS.md`. The tool now scans
`avm1/_investigation/ACCEPTED_DIFFS.md`,
`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` and
`from_gnash/_investigation/ACCEPTED_DIFFS.md` for the three shapes that actually
carry an entry subject — `### \`name\` — why` headings, `**Test:** \`name\``
lines, and the leading backticked cell of a summary-table row — plus
`ignored_tests.txt`. Prose backticks are deliberately **not** scanned: they name
APIs and neighbouring tests, and scanning them would disposition half the corpus.
Match precedence: `suite/path/test` (exact) → bare name inside the doc's own
suite scope (exact) → bare name outside it (**"matched by basename — VERIFY"**,
the caveat `w1b` §3.2 asked for; `avm2/netstream_play_flv` is the one live case).

### 3.2 A trace-axis statement is NOT a pixel disposition — the big one

Applying `ignored_tests.txt` the way `filter_results.py` does (global ∪
suite-local) dispositions **113 of the 403 failing comparisons** and deletes most
of the board: all 26 Stage3D, the whole bitmapdata family, `avm2/focusrect`,
`blend_transform`. That is wrong, and the reason is in `avm2/ignored_tests.txt`'s
own header — *"seeded 2026-07-10 … before any AVM2 implementation exists …
re-triage each bucket as support grows"*. It is a **trace-axis** work list; image
comparisons never gate trace pass/fail, so it says nothing about the pixels.

So the tool splits the sources two ways:

* **Hard** (excluded from the board): an image-axis ACCEPTED_DIFFS /
  RUFFLE_VS_FLASH entry, or the **global** `ruffle-tests/ignored_tests.txt`
  (which CLAUDE.md requires an ACCEPTED_DIFFS test to be added to).
* **Soft** (kept on the board, flagged `[trace-ign]` on the row and summarised
  under `TRACE-AXIS FLAGS`): a suite-local ignore list, or a doc entry whose text
  is about diff *lines* rather than pixels.

102 comparisons carry the soft flag (avm2 90, from_shumway 12) and stay
rankable; 6 are hard-dispositioned. Whether an entry is image-axis is decided by
keywords in the entry body (`image`, `outlier`, `px`, `MSAA`, `.png`,
`antialias` — `pixel` is excluded on purpose: `pixelDissolve`'s body is full of
"dest pixel positions"), overridable by an explicit marker (§3.3).

### 3.3 `<!-- image-axis: … -->`, so a disposition can carry a scope

The keyword heuristic cannot read a negation ("has **no** `[image_comparisons]`
block" contains "image"), and no per-test match can express "frames 1–2 only".
Both are fixed by one marker an entry can carry in its body:

```
<!-- image-axis: none -->             trace-axis entry; keep its comparisons on the board
<!-- image-axis: frames 1-2 only -->  partial: only frame1/frame2 are dispositioned
```

The marker is authoritative (it beats the heuristic wherever they disagree), and
a frame range is applied **per comparison**: `frame3`–`frame7` of
`simple_loop_test` come back onto the board (ranks 64 / 123 / 214, as three
test×cluster rows) while `frame1`/`frame2` stay dispositioned and print
`[in scope: frames 1-2 only]`. That is what moves the count from 11 dispositioned
/ 364 live to 6 / 369.

---

## 4. Doc fixes folded into the same patch

**`from_gnash …/loop/simple_loop_test` — narrowed, not deleted.** The entry now
reads "**FRAMES 1–2 ONLY**" with a scope-correction block: frames 1–2 are 242 and
483 excess px (the accepted hairline pixel-snapping); frames 3–7 are 7442 / 7683
/ 14400 / 14702 / 21600 — up to **30×** the accepted magnitude — and are
`blank_render` / `extra_element` / `missing_element`, i.e. a timeline loop phase
off-by-one, live work. The summary table gains a second row saying so, and the
entry carries `<!-- image-axis: frames 1-2 only -->` so the tool enforces the
narrowing instead of merely describing it.

**`avm1/display_object_properties` — marked stale.** The comparison passes in the
`375373786` baseline. The entry is kept (the mechanism is real and a tolerance
change could resurface it) with a status note, and its summary-table row is
struck through. The tool reports it under `DISPOSITIONED BUT NOT FAILING` rather
than silently dropping the row — the behaviour `w1b` §3.2 asked for.

**`avm1/bitmap_data_thorough/pixelDissolve` — marked trace-axis-only.** Its ~38
diffs are output *lines*; the test has no `[image_comparisons]` block at all, so
it dispositions nothing on the pixel side. Marked `<!-- image-axis: none -->`,
and the summary-table cell now says "(trace lines; **no image comparison
exists**)".

---

## 5. Notes for whoever picks this up

- **Two frame-phase suspects, both worth a look**:
  `from_gnash …/simple_loop_test` (now partly back on the board) and
  `visual/edittext/edittext_border_transform` (6 cmps, 4 mechanisms, never
  dispositioned). The section prints them even when dispositioned, because a
  disposition is written about *one* mechanism and a phase mismatch across frames
  is usually not that one.
- **`--docs-dir`** exists so a merged run's JSONs can be graded against a working
  branch's disposition docs (that is how the amended-doc numbers above were
  produced without touching the main checkout). Default is `--swfs-dir`.
- **The head of the board is not the near-pass band** — it is
  `same_geometry_wrong_fill`, decomposing into blend-mode compositing (19),
  Shumway acid (19) and focus highlight (11). `w1b` §4 has the rider write-up and
  its regression risk (21 already-passing sibling comparisons).
- Deliberately **not** built, per `w1b` §5.4: no image-side `filter_results.py`,
  no cross-run cluster diffing (the `ruffle-image-results` branch is force-pushed
  with no history, so the previous run's actual PNGs are gone by the next run).
- Still open from `w1b` §5.3: `triage_image_tests.py --from-ranked ranked.json
  --top N`, so the fixability oracle runs on the board's head instead of sweeping
  403. The row JSON this tool writes is the intended input.
