**AVM1 filters: finish the runtime + authored filter paths (game-visible, few corpus rows).** Categories: `avm1 visual from_shumway regression` (only what you need). Pixel and trace axes.

Board items, all open since the post-s23 `77545c5ac` (`session23-fanout-reports/avm1-runtime-filters-report.md` §6) and s24 w1-avm1-tail:
1. The recompiler keeps only the FIRST simple filter of a DefineSprite PlaceObject3 filter list (`SWFRecomp` `swf.cpp` ≈6085/6552). Nested multi-filter lists and nested ColorMatrix/Convolution filters are lost in render AND in the getter. s24's probe is `session24-fanout-reports/w1-avm1-tail-probe/l1_nested_filters` (`mkl1.py` + `l1_nested_filters.predicted_flash.txt`).
2. The AVM1 `filters` GETTER for PlaceObject3-authored filters only resolves ROOT-depth entries (`ng_objRootDepth`).
3. ColorMatrix / Convolution / DisplacementMap runtime filters are lowered to nothing. Mechanism (from §6): compose CM into the entry's `cx_*` (placed) or into the group blit (dynamic). Convolution/DM need a real filter pass; check what the AVM2 filter layer already has (`render_filtered_core`, the s22/s23 padded filter layer).
4. A dynamic filter root's `attachBitmap` bitmaps, text fields and attached timeline children are not in the filter layer (`dyn_filter_root_draw` runs only Drawing-API paths).
5. The dynamic-clip colour transform is not applied to filter output (dynclip R3).
6. Gradient filters keep a single-colour approximation.

For each: mechanism, price, the corpus rows it would move (grep image-graded rows using these filters; `visual/filters/*`, shumway filter rows), and a measured prototype for the cheap ones with the render-canary md5 sweep. Rows that lack a golden need a `regression/` fixture with a Ruffle-exporter golden: write exact LOCAL ORACLE REQUESTS (SWF generator + frames), since the coordinator runs the exporter locally between waves. Ruffle source: `render/wgpu/src/filters/*`, `core/src/avm1/globals/*filter*.rs`.
