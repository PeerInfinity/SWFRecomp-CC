# Session 21 · wave 2 · `w2-px-c`: the two EditText browser-only gates (hscroll, selection)

**Deliverables (new files; stage by name):**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-c-1-hscroll.patch`
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-c-2-selection.patch`
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-c-report.md` (this file)
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-c-ef-fixture/` (`mk.py`, `ef_attach.swf`,
  `ef_attach.output.txt`, `ef_timeline.swf`, `ef_timeline.output.txt`). This is an oracle fixture for
  §4. It is **not** a patch: do not add it to `regression/` until the mechanism is fixed.

Worktree `.claude/worktrees/w2-px-c` (branch `s21-w2-px-c`, base `ad29c869e`, recompiler rebuilt in
the worktree). No commits.

**Applying against current master (`0fd566061`):** the code hunks of both patches pass
`git apply --check`, alone and in sequence. The applied pair is byte-identical to the code I
A/B-tested. Each patch also appends one member to `render_canary_tests.txt`; that file has moved on
master, so apply with `--3way` and keep all blocks, as usual.

**Distance from w2-px-b's border branch** (`tag.c::textfield_render_cb`, which ends ~5835): my
`tag.c` hunks start at ~6072 (hscroll) and run through ~6300 (selection-colour override in the
glyph loop). All of them are inside `textfield_glyph_render_cb`, ≥ 230 lines away, so there is no
textual overlap. The only `action.c` hunk is a 7-line exported wrapper appended after
`tf_view_hscroll_px` (~77680), nowhere near clip-matrix storage.

## Verdicts and flips

| patch | comparison | before → after | verdict |
|---|---|---|---|
| **1** `hscroll` | `visual/cache_as_bitmap/edittext_hscroll` [output.02] | fail 960 → **pass, 0** | **+1 flip** |
| 1 | same, [output.01] | 96 → 96 | unchanged, different owner (EditText DropShadow, §3) |
| **2** `selection` | `visual/cache_as_bitmap/edittext_selection` [output.02] | 6 783 → **315** (limit 8) | **band −95 %, 0 flips** |
| 2 | same, [output.01] / [output.03] | 366 / 373 → unchanged | blocked, EditText DropShadow (+ a 1-px caret x offset on .03) |

**+1 flip and one −95 % band move, 0 regressions, 0 trace moves.** Both patches are graphics-only:
`textfield_glyph_render_cb` compiles only under `!NO_GRAPHICS`, so per-change `mode=graphics` CI is
enough.

### Premise refuted (rule 1), and the actual mechanism for the flip
**Un-gating the hscroll block by itself flips nothing.** That block is the *caret auto-scroll* of a
**focused** single-line field. `edittext_hscroll` never focuses its field. Its script is
`onKeyDown(Escape) { text.hscroll = text.maxhscroll; }`, i.e. the **author-set `hscroll`**, and the
renderer never read that value in any build. So patch 1 does two things:
1. It renders the author-set `hscroll`: the text is translated by `-hscroll` px, as in Ruffle's
   `render_self`. This is what flips `.02`.
2. It removes the gate on the caret auto-scroll.

The two are **independent offsets**, and that is the design `804787bf1`
(`links_in_scrolled_text`) already chose for the click hit test: `tf_view_hscroll_px` (author) +
`_tf_scroll_x` (caret). The render now subtracts exactly what the hit test adds back. Before this
patch, render and hit test *disagreed* for any AS-scrolled field in every build: `804787bf1`'s hit
test was scroll-aware while the render was not.

## Why each gate existed (blame)

- **hscroll caret auto-scroll** (`#if !NO_GRAPHICS && !OFFSCREEN_RENDER` at ~6081). This is
  browser-WASM editable-field work. Its own comment gives the reason: "in OFFSCREEN/headless nothing
  is focused → caret_char<0 → no shift → CI render byte-identical". It is the same premise as the
  caret gate, and the caret gate has already been un-gated with this refutation, written into
  `tag.c` above the caret code: "Ruffle's own goldens for `edittext_caret_empty` contain the
  caret bar … headless included". `input.json` focus and TextControl events **are** replayed in CI.
- **Selection highlight** (~6133). Its comment says "Browser-WASM only, same rationale as the caret
  — nothing is selected in headless/OFFSCREEN". Same refuted premise. It also drew the
  **wrong thing** for Ruffle parity: a light-blue box with the text left in its own colour. Ruffle
  (`edit_text.rs render_selection_background_for_line` + `render_layout_box`) draws:
  - a **BLACK** box (GRAY only for an unfocused `alwaysShowSelection` field, which our AVM1
    producer never reports);
  - spanning first-selected-char left edge → last-selected-char right edge;
  - over the line box (ascent + descent; leading only if the selection continues to the next
    line);
  - with every selected glyph drawn with an identity colour transform, i.e. **white**.

  Patch 2 ports that for the single-line case, which is the only case the existing block handled;
  multi-line selection is still undrawn.

## Verification: render canary, md5 bar

- **Legs:** `before` (master + fresh recompiler, `--recompile`), `afterA` (patch 1), `afterAB`
  (patches 1 + 2).
- **Set:** 64 tests / 133 PNGs. That is the whole standing `render_canary_tests.txt` (including its
  6 `regression` members and the new AVM2 `edittext_caret_multiline`) plus every AVM1/AVM2
  image-graded test that focuses or selects an EditText or touches `hscroll`/`scroll`:
  - `visual/cache_as_bitmap/edittext_{hscroll,selection,scroll}`
  - `visual/edittext/edittext_{caret_empty,caret_multiline,selection_leading,border_transform,device_transform_small_rotation}`
  - `visual/focus_highlight/focus_highlight_{render,move}`, `avm2/edittext_always_show_selection`
  - trace carriers: `text/links_in_scrolled_text`, `avm1/edittext_hscroll`,
    `avm1/textfield_props_swf8`, `avm1/clone_sprite_edittext`

  The candidates came from a tag/string scan of every test with an `input.json` plus
  `image_comparisons`.

```
before → afterA : IDENTICAL 132, DIFFERS 1  edittext_hscroll output.02  fail → pass
                  TRACE STATUS CHANGES: none
afterA → afterAB: IDENTICAL 132, DIFFERS 1  edittext_selection output.02  fail → fail (6783 → 315)
                  TRACE STATUS CHANGES: none
```

**Caret rows md5-identical in both legs, as required.** `visual/edittext/edittext_caret_empty` has
12 comparisons (all pass) and the AVM2 `visual/edittext/edittext_caret_multiline` has 6 (all pass).
`edittext_selection_leading` (12, AVM2) and `avm2/edittext_always_show_selection` are also
identical and still passing. The AVM2 painter is a separate code path; these confirm it was not
disturbed.

## 3. What still blocks the remaining four comparisons (completion mechanism)

- **All of them carry an EditText DropShadowFilter.** The PlaceObject3 filter list has one
  DropShadow, colour `0xCC00CC`. It shows in the goldens as a 1–2 px magenta fringe right of and
  below the glyphs (and, on `edittext_selection .02`, below and right of the black selection box).
  We draw no fringe. That is the s18 HOLD **"an EditText is never drawn by `render_single_object`,
  so PlaceObject3 filters on a DefineEditText are a structural no-op"** (`edittext_border_filters`).
  - `edittext_hscroll .01`: 96 channels, all fringe.
  - `edittext_selection .01` 366 and `.03` 373: fringe-dominated.
  - `edittext_selection .02` 315: fringe, plus one column (x = 73, rows 26–31) where the golden's
    selection-box right edge is fractionally covered and ours is solid.

  The completion mechanism is to route EditText content through the filtered-layer capture. That
  one mechanism owns 4 comparisons (the three `edittext_selection` rows, `edittext_hscroll .01`),
  plus `edittext_border_filters`, the priced s18 item.
- **`edittext_selection .03` also has an AVM1 caret-x offset:** our end-of-text caret is at x = 74,
  Ruffle's at 73 (Ruffle: `caret_x = x + advance` of the last glyph). It is small and separate, in
  the AVM1 caret code (already un-gated). I did not change it here because it would move
  `edittext_caret_empty`'s passing rows and needs its own A/B.

## 4. The attachMovie-nested `onClipEvent(enterFrame)` gates (5440/5568/7292/7366), measured (report-only)

**The corpus has no coverage.** A tag scan of every non-AVM2 SWF (an exported DefineSprite whose
timeline places a child with clip actions, in a SWF that calls `attachMovie`) finds **zero** tests.
The corpus says nothing either way, so I built an oracle fixture (`w2-px-c-ef-fixture/mk.py`,
hand-assembled SWF 8):
- `ef_attach`: exported symbol `lib` places child `inner` with `onClipEvent(enterFrame){trace("ef …")}`,
  and `_root.attachMovie("lib","a",1)` attaches it.
- `ef_timeline`: the same symbol placed on the root timeline (control).

Expected outputs come from the Ruffle exporter (`--trace-log`, 4 frames): `start` + 3 × `ef …`
for both.

| fixture | no-graphics | graphics | Ruffle |
|---|---|---|---|
| `ef_timeline` (control) | **PASS** | **PASS** | start + 3 ef |
| `ef_attach` | **MISMATCH**: only `start`, zero `ef` | **MISMATCH**: only `start`, zero `ef` | start + 3 ef |

So the gap is **real, trace-visible, and present in BOTH native modes**: clip actions on a child
nested inside an attachMovie'd clip never fire. The browser-only code is **not** a sufficient
fix. A throwaway probe un-gated all four sites (and compiled `upgrade_attached_clip_initialized`
for OFFSCREEN): `ef_attach` still produced zero `ef` lines. The browser path depends on the rest of
the gated 2359–2636 block (`advance_attached_clip_frames` builds the attached clip's authoritative
`sprite_display_list`, which is what gets the child and its clip actions placed and promoted),
while native attaches populate the child list another way.

**Completion mechanism, for a future slot:** trace where native `ng_attachMovie` runs the attached
symbol's frame 0 and whether the resulting child entries get `sprite_initialized ≥ 2` and a
reachable walk. Then land the fix with this fixture promoted to `regression/`: its expected output
is from Ruffle, not from us. NO_GRAPHICS is affected too, so that slot needs both CI modes.

## Repro

```bash
WT=.claude/worktrees/w2-px-c; export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
# list: render_canary_tests.txt + the 15 extras above, deduplicated (scratch pxc_ab_uniq.txt)
python3 ruffle-tests/render_canary.py capture --label before  --tests LIST --tier all --recompile -P 2 --timeout 5400
git apply --exclude=ruffle-tests/render_canary_tests.txt w2-px-c-1-hscroll.patch
python3 ruffle-tests/render_canary.py capture --label afterA  --tests LIST --tier all -P 2 --timeout 5400
git apply --exclude=ruffle-tests/render_canary_tests.txt w2-px-c-2-selection.patch
python3 ruffle-tests/render_canary.py capture --label afterAB --tests LIST --tier all -P 2 --timeout 5400
python3 ruffle-tests/render_canary.py compare before afterA; python3 ruffle-tests/render_canary.py compare afterA afterAB
# enterFrame fixture (put each .swf + output.txt + `num_frames = 4` in a scratch regression-style dir)
python3 ruffle-tests/verify_output.py --tests-dir=<dir> --test=w2pxc_ef_attach --mode=graphics --recompile --diff --verbose
```
