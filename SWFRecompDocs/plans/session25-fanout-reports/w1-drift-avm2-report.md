# s25 w1-drift-avm2 — upstream drift, AVM2

**New files:** `w1-drift-avm2-report.md` (this file) and `w1-drift-avm2-prototype.patch` (390 lines; `git apply`s cleanly
on `origin/master` `ca14fe02`).

## Verdicts (lead)

| Row | s25 baseline (graphics) | With prototype (graphics / no-graphics) | Verdict |
|---|---|---|---|
| `avm2/pixelbender_shaderjob_output_channels` | output_mismatch (8 lines: #2162 thrown) | **PASS / PASS** | **GO, +1 flip** (S, 6 lines) |
| `avm2/textblock_recreate_text_line_width` (`known_failure = true`) | output_mismatch (3 lines) | **PASS / PASS** | **GO, +1 flip** (M: recompiler + runtime). Flash-correct; Ruffle itself still fails line 4 (`output.ruffle.txt` reads `1000 1000`), so this is a real `pass`, not `ruffle_matched` |
| `avm2/local_connection_allow_networking` (ungraded in s25 baseline) | not in `results_graphics.json` (arrived later) | **PASS / PASS at baseline, no code** | **drift, already passing. Book as new-row drift (+1 row, +1 pass), not as yield** |

Priced: **+2 trace flips** (both rows are new upstream rows, so the trace baseline denominator grows by 3 with this download and
the pass count grows by 3). **0 rider moves** in either mode across 53 neighbours plus 1 regression row.

## 1. Drift inventory

Upstream master at download time = **`3ac8dcb07`**: `git ls-remote` on 2026-11-22, and the same as wave-0's SHA, so
nothing new has landed since `wave0-upstream-drift-namestatus.txt`. `git diff --name-status bcac30c19 3ac8dcb07 -- tests/tests/swfs`
touches exactly three test dirs, all **A** (new), all `avm2`. There are **no changed-expected and no deleted rows**,
and no other category is touched (`tests/src/*` harness changes are Ruffle-runner only: Xvfb plus the allowNetworking
player option). Commits: `e4e3c0208`+`5d629cec4` (textblock), `b9929aaf3`+`9051addab`+`76d96f63e` (pixelbender),
`562a59507`+`3ac8dcb07` (LC). `f6c489f84` and `8d5f96d74` are irrelevant (dependency bump and Ruffle's own test runner).

## 2. Per-row mechanism

### 2a. `pixelbender_shaderjob_output_channels` — GO
- Ruffle `b9929aaf3` (`shader_job.rs start`): a 1/2-channel (`float`/`float2`) output raises #2162 **only for a BitmapData
  target**. ByteArray / Vector.<Number> targets take the narrow output as-is. The wgpu readback half is Ruffle-internal.
- Ours: `SWFModernRuntime/src/avm2/avm2_pixelbender.c:2085` gated `out_channels != 3 && != 4` for every target.
  The writeback already strides by `out_channels` for ByteArray/Vector.
- Prototype: allow 1/2 channels when `target_bd == NULL`. That covers the ShaderJob byte targets only, because the
  filter/fill paths set `g_pb_target_override`, so `target_bd` is non-NULL and they keep the #2162 gate.
- `9051addab` (smpl coordinate-size bits in the dst mask) is an **assembler-only** change that alters the shipped `.pbj` bytes. Our
  decoder already tolerates those bits: the row passes with only the gate change.

### 2b. `textblock_recreate_text_line_width` — GO (3 mechanisms, all needed)
Baseline diff: `rawTextLength: 2 29` (want `29 29`), `width: 0 0` (want `579.9 579.9`), `height: 0 0` (want `20 20`).
1. **recreateTextLine never re-split the line** (`avm2_text.c tb_recreate_text_line`). It kept the begin/end/raw length of the line's
   first content (`"ab"`). Ruffle's `do_create_text_line(line_to_use)` re-runs the split on the current content. Prototype:
   recompute `begin/end/raw_text_length/line_index` exactly as `tb_do_create_text_line` does. Set `creation_result`.
   A *complete* block returns **null without touching the line**, as Ruffle does; `userData = null` still runs first, per TextBlock.as:129.
   (Ruffle `5d629cec4` itself only re-applies the fallback EditText's width. We have no fallback EditText.)
2. **TextLines had no bounds.** Flash's `width`/`height` here are the *logical* line box:
   - width = Σ hmtx advances: 24×1000 + 5×999 = 28995 units × 20/1000 = **579.9**. It is rounded to twips once on the
     total; per-glyph rounding would read 580.
   - height = typo ascent 800 + descent 200 (SpaceAB.sfd stores them as offsets from Ascent/Descent) = **20**. The ink box
     would be 1002 units = 20.04, so this is the logical box, not ink.
   Prototype: `tl_layout_box` (`avm2_text.c`) computes the box at create/recreate time from the block's EMBEDDED_CFF face. The
   face lookup is factored out of the existing `tl_metric` as `tl_block_face`, with unchanged behaviour. The
   `bounds_with_transform` change (`avm2_display.c`) unions that box into a TextLine's self bounds. If any code point is
   missing from the face's cmap, the box stays unset, so the line keeps the old 0×0.
3. **Advances never reached the runtime.** `SWFRecomp/src/abc/abc_timeline.cpp` `TAG_DEFINE_FONT4` now also walks
   `hhea`/`hmtx`/`cmap` (format 12 when present, else format 4). It emits a sorted `(codepoint, advance)` table per face.
   `Avm2Cff4FontData` (`avm2_abc.h`) gains the **trailing** fields `adv`/`adv_count`, and the empty-table initialiser zero-fills them.
   `Avm2TextLineExt` gains trailing `box_valid/box_w/box_asc/box_desc` fields.

**Browser build (not measured):** the browser host receives the guest's table by pointer, and the table already holds a
`const char*`, so a trailing pointer field is layout-safe. Both sides compile from the same header. A `deploy-pages
dry_run` should confirm it at landing.

### 2c. `local_connection_allow_networking` — drift only
`verify_output.py resolve_expected_filename` handles version-less `[subtests]` tables (s23 H1's `-2` start): it grades the
FIRST variant, `all` → `output.all.txt`, and runs with no allowNetworking restriction. We already match `all` byte-for-byte in both modes.
The `none` variant (#2146 SecurityErrors) is ungraded by design. Implementing it would require a per-subtest player option
we don't model, so it isn't worth doing for grading.

## 3. Before/after (measured in the cloud, Dawn on lavapipe)

| Row | before g | before ng | after g | after ng |
|---|---|---|---|---|
| pixelbender_shaderjob_output_channels | MISMATCH | MISMATCH | PASS | PASS |
| textblock_recreate_text_line_width | MISMATCH | MISMATCH | PASS | PASS |
| local_connection_allow_networking | PASS | PASS | PASS | PASS |
| regression/avm2_sound_bytes_and_group_format (TextBlock/GroupElement) | PASS | PASS | PASS | PASS |

**Rider sweep (after-leg, both modes):** all 53 avm2 `pixelbender_*`, `textblock_*`, `textline_*`, `text_engine_*`,
`localconnection*`, `local_connection*` rows. Every row's status equals its s25 baseline (`results_graphics.json`;
no-graphics compared to `results.json`):
- 49 pass. Includes `textline_metrics`, the EMBEDDED_CFF ascent/descent row whose face lookup was refactored, and all 26 ShaderJob users.
- 4 ruffle_matched, unchanged: `textblock_line_changes`, `textblock_recreateline`, `textblock_releaselines`,
  `textline_atom_index_at_char_index`. These are the recreate/chain rows; the new complete→null arm did not move any of them.
- Image axis: the 8 pixelbender image rows still pass. `pixelbender_dithering` still fails at exactly the pixel-baseline numbers
  (1297344 outliers, max 255; baseline `08fdbcad6`), so it was not moved.
- No other category uses FTE or ShaderJob. I grepped `text/`, `fonts/` and `mixed_avm/` after downloading them. DefineFont4 SWFs elsewhere only
  gain a static table.

The patch touches shared AVM2 runtime and recompiler code, so CI landing should be `categories=full`. Graphics is enough
per policy, because none of the changed code is no-graphics-only; no-graphics was measured here regardless.

## Refutations / premise checks
- The brief treated `9051addab` (smpl size bits) as a possible runtime port. It is assembler-only, and no runtime change is needed.
- Ruffle's own fix for the textblock row (`set_width` on the fallback) is **not** what flips it for us. Flash's width is
  the advance sum, and Ruffle still fails that line, which is why it keeps `known_failure`. Our flip comes from actual FTE metrics.
- The LC row needs no allowNetworking modelling: it is already a pass.

## New unclaimed leads
- `TextBlock.recreateTextLine` lacks Ruffle's `previousLine === textLine` #2004 check (TextBlock.as:119). No graded row exercises it.
- TextLine width wrapping: `next_line_break` ignores `width`. Now that advances exist, width-based line breaking for
  EMBEDDED_CFF faces is reachable. Unpriced: no current failing row was identified that needs it.
- The TextLine box covers only EMBEDDED_CFF faces with a full cmap. Device-font TextLines still report 0×0. Unpriced.

## LOCAL ORACLE REQUESTS
none
