**Flash's same-frame stale matrix for `hitTest(x, y, true)` (M).**

Inputs: `w1-leads-report.md` §1 (on master), fixture `w1-leads-fixtures/avm1_hittest_root_stale_matrix/` (SWF +
generator + `hittest_model_switches.diag.patch`), and the coordinator's Flash 32 captures in
`w1-local-oracles/w1-leads/` (README). FP32 (pinned == no-pin):
- In the frame where `_root._x`, `c._x` or `_root._xscale` changes, **shapeFlag=true** hitTest answers differently from
  ours (phases B, D, F, G), while the **bounds** test (shapeFlag false) and `localToGlobal` use the live matrix; the
  next frame is consistent again (C, E). Read the full capture: e.g. B `hit(150,150) shape=false bounds=true`, F
  `hit(250,150) shape=false bounds=true`, G `hit(250,150) shape=true bounds=true`.
- `avm1/movieclip_hittest_shapeflag`: FP32 ≠ golden on lines 35/37/39 only (`false`; second donut block after
  `_root._x = 400; _root._xscale = 50` in the same frame). Our 6 ACCEPTED Cat 8 lines (71, 171–177, 296) == golden ==
  FP32.

Task:
1. Fit a model that reproduces ALL phases of the probe exactly (e.g. the shape test uses a world matrix cached at the
   last render for the CLIP but maps the point through the live `_root`?, or uses a cached inverse; try each against
   every phase). Write extra probe variants (nested parent change, `_rotation`, a clip created this frame) as FLASH
   requests if one fit isn't unique.
2. Implement (`action.c` hitTest arm ~80573, plus whatever per-clip render-time matrix snapshot it needs; name
   every function) so the probe matches FP32 in both modes, and `movieclip_hittest_shapeflag` matches FP32 on 35/37/39.
3. Gate: every avm1/gnash/shumway row with `hitTest`, `regression` hitTest fixtures, both modes. The coordinator adds
   the flash_fixes entry for the shapeflag golden + an RvF entry (Ruffle reads the live matrix) at landing: draft both
   texts in your report. Expected status: the row stays failing on Cat 8 (0 flips) — say so.
4. Land the probe as `regression/avm1_hittest_shape_stale_matrix` with the FP32 golden.
5. Also fix the ACCEPTED_DIFFS Cat 8 intro wording (the 6 lines disagree with Flash too, not just Ruffle).
