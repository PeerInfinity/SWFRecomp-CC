**Pixels, render and bitmap leads** (playbook §25 "Render and bitmap leads" and `shader_as_mask`). Categories: `visual`, `avm2`, `avm1`, `from_shumway`, `from_gnash`, `regression`.

1. **A holder's Drawing-API content paints over its attached children** (S–M): the Flash order is Drawing-API content BELOW all children of that clip. Find the owner in the attached-clip render pass (`tag.c` `render_attached_child`, the depth-ordered attached pass from s25/s26), build a fixture with an exporter-golden request, and price corpus rows (game-visible: N).
2. **Per-movie static bitmap bases for loaded children**: a loaded child's DefineBits* ids collide with/offset into the parent's bitmap registry (memories `child-bitmap-registry-and-offset-audit`, `per-movie-render-tables`). What still renders wrong? Fixture plus price.
3. **AVM1 `draw()` Drawing-API paths still alias** (s26 `1aef9cc7b` draws timeline shapes and static text; Drawing-API fills/strokes under `draw()` are rasterised aliased). Price against the Ruffle/Flash AA model.
4. **`visual/blend_modes/shader_as_mask` 366**: truncating rounding in `renderer_composite_alpha_mask`; a blendShader node with mask/filters/scrollRect still draws NORMAL; a possible RvF (Ruffle composites OVER where Flash REPLACEs). Price each; this row has a Ruffle golden, so check `known_failure` and Flash semantics before chasing it.
5. `from_shumway/bitmapbuttons` 52 (corner AA): cheap mechanism check.
6. Re-test the cheapest third of these NO-GOs: `blend_scroll` 296, `bitmapdata_opaque` 4, `video/colorconversion/h263` 3, `gradientTransform` 9, `MaskTest-2` 7162, `acid-mask`.

Prototype any GO, measured, with a render-canary md5 sweep. Siblings: `w1-applyfilter-tail`, `w1-per-movie-dl-phase3` (loaded children: coordinate through file self-localization).
