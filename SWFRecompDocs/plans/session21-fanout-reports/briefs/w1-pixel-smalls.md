# w1-pixel-smalls — price the unclaimed pixel smalls (wave 1, main tree, read-only; tiny throwaway-worktree probes allowed)

Rows (from `wave0-image-board.md` and playbook §17-§19): `visual/drawing_api/drawing_order` (6658), `avm2/bitmapdata_copypixels` (20800 — note playbook line ~233 says local Dawn shows ~25k PHANTOM outliers here; is it lavapipe-only?), `visual/cache_as_bitmap/nested_rotation`, `visual/filters/blur_scales_with_screen`, `text/br_at_start`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll`, `visual/edittext/edittext_border_transform` ×2 (s20 L1: port Ruffle's `emulate_line_as_rect` into the AVM1 transformed-box branch; 50/43 outliers vs limit 20), `visual/edittext/edittext_device_transform_small_shear`, `from_shumway/acid/acid-text-6` ×2, `avm2/graphics_gradients`, `avm2/bitmap_pixelsnapping` (Bitmap.pixelSnapping unimplemented), `bitmapbuttons` (four 0x43 clipped-bitmap fills render nothing), `visual/blend_modes/layer_alpha`/`layer_erase`.

`blend_modes` a_epsilon rows are CAPPED (playbook) — skip them unless you find the cap's premise is wrong. `edittext_caret_multiline`, device-font and `visual/filters/*` (except blur_scales_with_screen) belong to sibling slots.

For each row: mechanism (owner file:line), comparisons reachable, outliers vs budget (a band lead is not a flip lead — s20's even-odd lesson), GO/NO-GO, and a one-paragraph wave-2 brief for each GO. Rank by flips per LOC. Use the extracted CI PNGs + our local render; never grade a local render against a golden absolutely — reason about mechanism.

Deliverable: `SWFRecompDocs/plans/session21-fanout-reports/w1-pixel-smalls-report.md`.
