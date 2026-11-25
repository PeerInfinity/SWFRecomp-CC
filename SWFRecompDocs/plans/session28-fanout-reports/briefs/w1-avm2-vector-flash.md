**AVM2 vector rows with FLASH goldens (M): `avm2/graphics_draw_triangles` (1812 excess), `avm2/graphics_gradients`
(3685), `avm2/graphics_simple_shapes` (158), `avm2/sprite_with_frames` (6342), `from_gnash/misc-ming.all/BeginBitmapFill`
(839), `visual/cache_as_bitmap/avm1_color` (1200).**

Every one of these goldens is a real Flash capture (`session27-fanout-reports/golden-provenance.md` §"Re-priced pixel
board", rows 282-312 and 560-790) — they are true Flash targets; several are upstream `known_failure` with a
`.ruffle.png` (Ruffle misses them too). Grep the playbook (`graphics-fanout-playbook.md`) and the arc for prior
STRIKE/NO-GO verdicts on each before starting; `sprite_with_frames` is a 2-frame loop that matches Flash only at some
settle times.

Task: for each row, a per-region diff vs the golden (maps), the mechanism (gradient ramp/interpolation/focal,
triangle UV/culling, bitmap fill smoothing/repeat, colour transform on cacheAsBitmap, AA), and a priced verdict.
Prototype the cheapest real mechanism(s); gate on the render canary and every passing avm2 `graphics_*` row. A row
that needs a Flash rule we can't see from the golden gets a FLASH image request with a minimal fixture.
