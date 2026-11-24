**Holder Drawing-API z-order, the full model** (w1-render-bitmap-leads §1 HOLD + 1b). Categories: `avm1`, `from_gnash`, `visual`, `regression`.

s27 `202340a12` landed the narrow fix: a holder's Drawing-API content draws under its attached children (`action.c actionRenderHolderDrawingsInline`, `tag.c render_attached_child` + the `tagRerenderFrame` attached pass). Fixture `regression/avm1_holder_drawing_under_children` (golden = Flash). Remaining:
1. **The full model** interleaves the late sprite-text pass (M). Read the report's §1 for what the narrow fix leaves out, and build fixtures that show it.
2. **1b: a childless empty clip's drawing layers above higher-depth attached siblings** (M). Fixture `session27-fanout-reports/w1-render-bitmap-leads-fixtures/avm1_empty_clip_drawing_depth_order/`. **Its `hand.expected.png` == FLASH at 0 px** (`SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/w1-render-bitmap-leads/avm1_empty_clip_drawing_depth_order/flash.png`), so land it as `output.expected.png` once you pass. The naive full variant regressed `from_gnash/misc-ming.all/BeginBitmapFill` (KF, 939 → 1188): find the depth rule that satisfies both.
3. Sweep every attached-clip / Drawing-API / createEmptyMovieClip image row plus the canary (md5). N is game-visible here (memory `n-play-game-click`); keep `regression/avm1_attached_clip_holder_render` and the N attached fixtures green.

This touches `tag.c` render paths that the local N session (`n-ragdoll-strokes`) may also touch. Name every function, and keep the edit inside the attached/drawing passes.
