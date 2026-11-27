# s30 w2-rm-avm2-land: land w1-rm-avm2's 8 S rules, HOLD L1′, + pixelBounds, clip-layer pick, 2 FP32 golden fixes

Wave 2, cloud. Branch `fanout/w2-rm-avm2-land`. Base `origin/master` = `41b9c208` (code = s29 FINAL `2d40d3799`).
Corpus downloaded 2026-11-27 at upstream Ruffle master **`66f9073de`** (categories `avm2 from_avmplus from_shumway
timeline visual`). `SETUP_STATUS`: apt, Pillow, Dawn all OK. Every measurement is `--mode=graphics` on lavapipe.
Runtime-only change (no recompiler edit, so no `--recompile`). No `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm
touched, so no no-graphics leg.

**New files**
- `SWFRecompDocs/plans/session30-fanout-reports/w2-rm-avm2-land-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-rm-avm2-land.patch`
- `ruffle-tests/tests/swfs/regression/avm2_mask_removal_script/{Test.as,test.swf,test.toml,output.txt}` (FP32 fixture)
- `ruffle-tests/tests/swfs/regression/avm2_pixelbounds_offlist/{Test.as,test.swf,test.toml,output.txt}` (FP32 fixture)
- `ruffle-tests/flash_fixes/from_shumway/timeline/nav/clipDepth/test.toml` (`kind: "toml"`, `num_ticks` 3 → 4)
- `ruffle-tests/flash_fixes/avm2/swf_9_goto_in_construct_frame/output.txt` (FP32 cut at a tick boundary)

**Modified (non-source):** `ruffle-tests/flash_fixes/fixes.json` (+2 entries), `ruffle-tests/flash_fixes/README.md`
(+2 rows), `ruffle-tests/tests/swfs/regression/README.md` (+2 rows), `ruffle-tests/render_canary_tests.txt`
(+`from_shumway/MaskTest-3` at EOF), `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
(2 sections appended at EOF).

The patch = `git diff origin/master -- SWFModernRuntime ruffle-tests/render_canary_tests.txt ruffle-tests/flash_fixes
<the two new regression dirs>` (the docs files are on the branch commit, not in the patch). Exact command: `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/flash_fixes ruffle-tests/tests/swfs/regression/avm2_mask_removal_script
ruffle-tests/tests/swfs/regression/avm2_pixelbounds_offlist` (18 files, +402 −9; `--binary` for the two `test.swf`). Proven:
`git apply --check -R` on the branch and `git apply --check` on a clean `origin/master` worktree both OK.
**The coordinator must land
the two flash_fixes entries together with the code**: both rows stay `ruffle_matched` without the code (measured, the
before leg below ran against the fixed goldens).

## Verdicts (lead)

**GO: +11 rows `ruffle_matched → pass` + 1 new regression row, 0 losses, 0 other moves in a 64-row gate.**
All 11 are `known_failure` upstream, so `rm → pass` is the Flash direction (Ruffle prints `output.ruffle.txt`).

| item | verdict |
|---|---|
| 1. R1, R2, M1, BA, RE, PI, FTE-1, FTE-2 | **LANDED** verbatim from `w1-rm-avm2-prototype.patch` minus the L1′ hunks. 8 rm → pass, as w1 measured |
| 2. L1′ | **HOLD** (not in the patch). Completion: FP32 cannot pin the tick of a file-loaded child's traces (oracle README §0); land only with an `input.json` `Wait` fix for `loader_try_click_root` and a `num_ticks` fix for `xml_appendchild_swf_v21`, which need a gradeable FP32 capture first (e.g. a wrapper that boots the child, or an in-SWF tick counter traced by the child) |
| 3. M1 scope | kept on the RemoveObject TAG path only (`run_remove_op` timeline arm). FP32 `mask_removal` added as `regression/avm2_mask_removal_script`: **passes before and after** (our `removeChild` already keeps `maskee.mask`) |
| 4. `clipDepth` | flash_fixes `kind: "toml"` `num_ticks = 4` (verified: our 4-tick output == the 8-line golden == FP32). The clip-layer `getObjectsUnderPoint` rule priced **S** (one helper, 5-row blast radius) and **implemented** → rm → pass |
| 5. `swf_9_goto_in_construct_frame` | **swap chosen** (exact): flash_fixes `output.txt` = FP32 capture's first 19 lines (identical in both captures, = the golden minus its mid-tick line 20); `num_ticks` stays 3. With R2: rm → pass |
| 6. `pixelBounds` | **implemented** (off-stage → transformed bounds × 5): corpus row rm → pass; FP32 fixture `regression/avm2_pixelbounds_offlist` mismatch → pass |
| 7. `array_sort_swf10_32bit` | no swap, no code; RvF entry written (host-bitness split: LNX FP32 = `_64bit` golden, WIN FP32 = `_32bit` golden) |
| 8. RvF entries | written (EOF of `RUFFLE_VS_FLASH_DIFFERENCES.md`: 11 numbered items + the array_sort section). L1′'s entry (w1 item 3) is NOT written: L1′ is held |

## Functions touched (all runtime)

- `SWFModernRuntime/src/avm2/avm2_display.c`:
  - new `swf9_goto_cleanup_push` (R1), called from `run_goto` (SWF ≤ 9 arm)
  - new `swf9_construct_goto_children` (R2), called at the top of `run_local_frame_scripts`
  - `run_remove_op` (M1, timeline-removal `else` arm only)
  - `transform_get_pixel_bounds` (pixelBounds: `is_on_stage` ? 1/20 : 5/20)
  - new `goup_clip_layer_hidden`, called from `doc_get_objects_under_point`'s child-push loop (clipDepth)
  - Sibling w2-drift-smalls owns `avm2_display.c` html img loads; none of the above is near those.
- `SWFModernRuntime/src/avm2/avm2_ops.c`: `avm2_op_in` (BA)
- `SWFModernRuntime/src/avm2/avm2_value.c`: new `pow2_digit`, `avmplus_pow2_parse`; `avm2_string_to_int` (PI)
- `SWFModernRuntime/src/avm2/avm2_text.c`: new `g_fte_line_text`, `line_text_of`, `tl_atom_index_of`; `ce_text_of`,
  `tb_do_create_text_line`, `tb_recreate_text_line`, `tl_get_has_tabs`, `tl_get_atom_index_at_char_index`
  (FTE-1, FTE-2; the sibling's `avm2_text.c` img arm is untouched)
- `SWFModernRuntime/third_party/quickjs-libregexp/libregexp.c`: `lre_exec_backtrack` `REOP_line_start_m` arm (RE)

## New rules (mechanism)

- **pixelBounds.** FP32 (`w1-local-oracles/w1-rm-avm2/pixelbounds_offlist/fp32.lnx.txt`): an object with no path to
  the stage reports its transformed bounds (own x/y/scale included) × 5 on every component; on stage the normal
  bounds; empty → 0. Implemented as one factor in `transform_get_pixel_bounds`. The corpus row's line 2 is
  `(x=0, y=0, w=500, h=500)`. **Unverified:** an object inside an off-stage parent (we scale the full concat).
  Gate: every corpus SWF containing `pixelBounds` (5: `bounds_mode` stays rm unchanged, `edittext_autosize_lazy_bounds_props`
  and `edittext_bounds_scale` stay pass, the corpus row + fixture flip; the 5th is the AVM1 `regression/avm1_pixelbounds_dynamic_child`,
  a different code path).
- **clip layers in `getObjectsUnderPoint`.** The test (decoded from `clipDepth.xml`) traces
  `"Masked: " + !getObjectsUnderPoint(new Point(275, 200)).length`. Frame 1: clip (depth 1, clipDepth 5) at x 50..150 px,
  the bar at depth 3 spans the point → FP `true` (nothing). Frame 2: the clip moves to x 225..325, covering the point →
  FP STILL `true`. So FP never reports a clip layer or anything it masks, wherever the point lies (a point-in-mask
  rule would give `false` on frame 2). Frame 3: the clip is replaced by one with clipDepth 2 → the bar is reported
  (`false`). Frame 4: `gotoAndStop(1)` keeps that depth-1 clip (same character) → `false`. Our 4-tick output with the
  rule == golden. Gate: all 5 corpus SWFs containing `getObjectsUnderPoint`: `displayobjectcontainer_getobjectsunderpoint`
  and `hittesting/hittesting` stay pass, `from_shumway/getobjectsunderpoint` and `avm1movie` stay rm (unchanged).

## Per-test before/after (same box; before = clean `origin/master` code + this branch's test data/fixes)

| test | before | after |
|---|---|---|
| `timeline/swf_9_frame_script_dynamic_goto` | rm | **pass** |
| `timeline/swf_9_event_goto_frame_script` | rm | **pass** |
| `from_shumway/MaskTest-3` (trace; image) | rm; img PASS 0 | **pass**; img PASS 0 |
| `from_avmplus/regress/bug_558863_swf10` | rm | **pass** |
| `from_avmplus/regress/bug_479786` | rm | **pass** |
| `from_avmplus/as3/Math/e15_1_2_2` | rm | **pass** |
| `avm2/textblock_releaselines` | rm | **pass** |
| `avm2/textline_atom_index_at_char_index` | rm | **pass** |
| `avm2/swf_9_goto_in_construct_frame` (fixed golden) | rm | **pass** |
| `from_shumway/timeline/nav/clipDepth` (`num_ticks = 4`) | rm | **pass** |
| `from_shumway/avm2/flash/geom/transform/pixelBounds` | rm | **pass** |
| `regression/avm2_pixelbounds_offlist` (new) | mismatch | **pass** |
| `regression/avm2_mask_removal_script` (new) | pass | pass |

Note: with the ORIGINAL goldens, `swf_9_goto_in_construct_frame` is rm with 1 diff line after R2 (our 19 lines vs the
20-line golden) and `clipDepth` prints 6 lines at `num_ticks = 3`; both are rm on master either way.

## Gate (64 rows, before vs after, graphics): only the 12 ledger rows above moved

Rows (all at baseline both legs unless in the table above): timeline ×17 (every row, incl. `frame_script_cleanup*`,
`frame_script_construct`, `missing_frame_scripts`, `swf_9_frame_script_button_order`, `swf_9_frame_script_cleanup_goto{,2}`,
`swf_9_frame_script_dynamic_goto_2`); avm2 `movieclip_goto_during_frame_script`, `movieclip_queued_noop_goto_swf9`,
`swf_9_goto_in_enter_frame{,_simple}`, `swf_9_queued_goto_scripts{,_construct}`, `swf_9_versioning`; masks
`MaskTest`, `MaskTest-2`, `displayobject_mask`, `mask_reapply`, `mouse_pick_masking` (image outliers unchanged: 115,
7162, 38, 0 — the CI baseline counts); ByteArray `bytearray`, `bytearray_errors`, `bug_558863_swf11`,
`as3/ByteArray/ByteArray`; RegExp `regexp_test`, `regexp_exec`, `as3/RegExp/replace`, `as3/RegExp/bug_513020`; parseInt
`parse_int`, `ecma3/GlobalObject/e15_1_2_2_1`, `_2`; FTE `textblock_line_changes` (rm), `textblock_recreateline` (rm),
`textline_validity`, `textline_raw_text_length`, `textline_has_tabs`, `textblock_properties`; pixelBounds /
getObjectsUnderPoint blast radius (above); regression `avm2_sound_bytes_and_group_format` (FTE GraphicElement),
`avm2_goto_catchup_scale`, `avm2_child_simplebutton`, `avm2_parent_child_render` (image PASS).
w1's own per-rule gates (G1–G7, ~170 rows) ran on byte-identical code for the 8 landed rules; this gate re-checks
the combination plus the two new rules.

## Render canary

**Full standing canary, A/B md5 (`render_canary.py capture fbefore/fafter`, `--timeout 5400`, all 204 members incl. the
new `from_shumway/MaskTest-3`): 269 comparisons IDENTICAL, 0 DIFFERS / APPEARED / VANISHED / NO_RENDER. Trace status
changes: only `from_shumway/MaskTest-3` rm → pass (ledger). Image status changes: none.** (A first scoped run over 10
mask members gave the same: 22/22 identical.) The only render-reachable rule is M1; `from_shumway/MaskTest-3` (1 image
cmp, CI pass) is appended at EOF of `render_canary_tests.txt` as its covering member. Categories downloaded for the
canary: `avm1 fonts from_gnash text` on top of the five above.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

Trace axis, `ruffle_matched → pass` (11):
`timeline/swf_9_frame_script_dynamic_goto`, `timeline/swf_9_event_goto_frame_script`, `from_shumway/MaskTest-3`,
`from_avmplus/regress/bug_558863_swf10`, `from_avmplus/regress/bug_479786`, `from_avmplus/as3/Math/e15_1_2_2`,
`avm2/textblock_releaselines`, `avm2/textline_atom_index_at_char_index`, `avm2/swf_9_goto_in_construct_frame`
(needs its flash_fix), `from_shumway/timeline/nav/clipDepth` (needs its flash_fix),
`from_shumway/avm2/flash/geom/transform/pixelBounds`.
New rows: `regression/avm2_pixelbounds_offlist` (pass), `regression/avm2_mask_removal_script` (pass).
Pixel axis: **no moves expected** (`MaskTest-3` image PASS both legs; mask rows' outlier counts unchanged).
Losses: **none**. CI: `categories=full`, graphics (AVM2 runtime + from_avmplus rows).

## Refutations / premise attacks

- **"swf_9_goto_in_construct_frame needs `num_ticks` + swap" → swap only.** With R2 our `num_ticks = 3` output is
  exactly the FP32 capture's first 19 lines, which end at a clean tick boundary (FP's 6-line cycle starts with
  `MyContainer enterFrame`). No toml change is needed.
- **"clipDepth getObjectsUnderPoint is M" → S.** One rule (skip clip layers and their maskees), 5-row blast radius,
  measured; the frame-2 golden line refutes the point-in-clip-shape variant.
- **"M1 should also cover script removeChild" → refuted by FP32** (fixture passes on master and after).

## Not finished / limits

- L1′ HOLD (above).
- pixelBounds for an object inside an off-stage parent: no capture (FLASH request 1 below).
- M1 for goto-driven removals: no capture (w1's ORACLE 4 goto variant; needs a timeline SWF).

## New unclaimed leads

- **N1:** `atomCount` should count code points (w1 N2), still ungraded.
- **N2:** pixelBounds of a nested off-stage object (×5 of the full concat vs of the own matrix).

## LOCAL ORACLE REQUESTS

1. FLASH (optional, pins N2): extend `w1-local-oracles/w1-rm-avm2/pixelbounds_offlist/Test.as` with
   `var p:Sprite = new Sprite(); p.x = 3; p.scaleX = 2; p.addChild(s);` (p NOT added to the stage) and trace
   `s.transform.pixelBounds`; trace, direct, 1 frame. Our model prints the full-concat × 5.
