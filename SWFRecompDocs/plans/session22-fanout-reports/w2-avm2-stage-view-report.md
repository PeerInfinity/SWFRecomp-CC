# w2-avm2-stage-view: AVM2 `stage.scaleMode`/`align` view transform + `DisplayObject.z` projection (s22 wave 2, cloud)

**NEW FILES:**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-avm2-stage-view-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-avm2-stage-view.patch`
  (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`;
  `git apply --check -R` passes on this branch's tree)

No new source files, no new fixture dirs, no recompiler change (`SWFRecomp/` untouched, so `--recompile` is not needed).

**Box / provenance.** `SETUP_STATUS`: apt, Pillow and Dawn all OK. Corpus `avm2 visual avm1 from_shumway fonts text` was downloaded
from upstream Ruffle master **`45366370e`** (the coordinator's sync SHA; my blobless clone's `origin/master` also resolves to it). Base:
`origin/master` = `b78134bd1`.
**Cloud↔CI fidelity is PROVEN on all three headline rows**: my clean-master *before* renders are md5-identical to CI's actual PNGs on
`origin/ruffle-image-results` for `avm2/pixelbender_effect_glassDisplace` (`f2102846…`), `avm2/displayobject_z` (`6a93f9d9…`) and
`avm2/geom_transform` (`48f5ac3e…`). So the after-grades below are CI-grade.

---

## 1. Verdict: GO, +3 pixel flips measured, 0 trace moves

| test | axis | before (clean `b78134bd1`) | after (this patch) | budget | verdict |
|---|---|---:|---:|---:|---|
| `avm2/pixelbender_effect_glassDisplace` | pixel | 784 195 outliers, **fail** | **17**, max diff 49 | 1003 @tol3 | **fail → PASS** |
| `avm2/displayobject_z` | pixel (2 checks) | 211 814 @tol100 / 223 951 @tol10, **fail** | **6407 / 17 244** | 6500 / 17 500 | **fail → PASS** |
| `avm2/geom_transform` | pixel | 12 746 @tol10, **fail** | **3417** | 4000 | **fail → PASS** (unpriced bonus) |
| the same three | trace | pass | pass | | unchanged |

`geom_transform` was not in the brief. It assigns `transform.matrix3D` with a non-zero `raw[14]`, which goes through `m3d_tz_set`. The
same projection that fixes `displayobject_z` fixes it.

Margins are thin but deterministic (renders are byte-identical run to run): `displayobject_z` has 93 outliers of headroom @tol100 and 256 @tol10;
`geom_transform` has 583. The residual on both is the soft 1-texel edge ramp Flash draws on matrix3D objects. The `test.toml` FIXME
names it; on the 15.9×-scaled bitmap it is an ~8-px bilinear-looking ramp. We draw a hard nearest-sampled edge. I did not model it (see §5).

## 2. EXPECTED-FLIP LEDGER (check CI against this)

**Pixel axis (`images=true` run), fail → pass:**
- `avm2/pixelbender_effect_glassDisplace`
- `avm2/displayobject_z`
- `avm2/geom_transform`

**Pixel axis, must stay byte-identical:** everything else. The 14 other `viewport_dimensions` image tests were all md5-identical
before→after: edittext `background_basic_scale2`, `border_basic_scale2`, `underline_scale2`; filters `any_blur_`, `blur_`,
`displacement_map_`, `drop_shadow_scales_with_screen`; `pixelbender_effect_twirl`, `pixelbender_effect_BlurredFocus`,
`bitmapdata_draw_cab_quality`, `stage3d_program_constants_bytearray_be/le`, `stage_scale_factor`, `edittext_get_char_index_at_point`.

**Trace axis: no moves expected.** 0 status changes across 135 A/B rows (§4), and the 6-test no-graphics spot check passes.

## 3. Mechanism and patch scope (all in `SWFModernRuntime/src/avm2/avm2_display.c` plus one struct field)

1. **Stage.scaleMode / Stage.align are stored** (statics `g_stage_scale_mode`, `g_stage_align` next to the setters, ~13714).
   - The scaleMode setter matches the four names case-insensitively (Ruffle `stage.rs` `FromWStr for StageScaleMode`). The getter returns the stored name.
   - align parses T/B/L/R char-by-char, case-folded, ignoring everything else (Ruffle `FromWStr for StageAlign`). The getter emits them in
     AVM2 order T,B,L,R (`globals/flash/display/stage.rs get_align`).
   - Both setters call `avm2_stage_view_apply`. The getters used to be hard-coded `"showAll"` / `""`. No `output.txt` in the corpus
     contains a scaleMode or align name, and every setter in the corpus writes `noScale` / `TOP_LEFT`, so the getters cannot move a trace.
   - Deliberate gap: an invalid scaleMode is ignored. Ruffle throws ArgumentError #2008; no corpus test does this.
2. **`avm2_stage_view_apply`** (right after the render gate's `#endif`, with a no-op stub outside the gate) is a literal port of Ruffle
   `display_object/stage.rs build_matrices`:
   - the per-mode scale (NoScale = the HiDPI `VIEWPORT_SCALE_FACTOR`);
   - the L>R>centre and T>B>centre placement of the width/height delta, truncated to twips (`Twips::from_pixels`);
   - the result goes into a private `stage_to_ndc` together with `stage_scale` / `stage_fit_{x,y}`, on both `app` and the live `context`.
   - **Bit-identity guard:** when the computed (sx, sy, tx, ty) equals the harness's showAll/centred fit, the ORIGINAL pointer and values
     are restored verbatim. That covers every test whose viewport == stage, and every 2× viewport at scale_factor 2 (`stage_scale_factor`).
     So only glassDisplace's render can move.
   - The fit is baked into the projection, not a SetViewport, exactly like `wasm_wrappers/main.c`. Content outside the movie box (the 57 344
     golden px below/right of it) therefore draws into the margins with no extra work. The brief's "unclipped stage rect" was already true.
3. **`DisplayObject.z` perspective** (`avm2_z_project` + `g_avm2_render_tz`, just above `avm2_render_node`):
   - tz accumulates additively down the walk (Ruffle `render/src/transform.rs:26`).
   - Each node's OWN content draws (bitmap/shape/morph/text/statictext/Graphics/opaqueBackground) get `S(k)·world`: a scale by
     k = f/(f + tz) about the viewport centre, with f = (viewport_w/2)·tan(62.5°) (= 480.25 px at 500 px, `render/wgpu/src/globals.rs:30-63`).
   - The scale goes onto the leaf only. Children inherit the unprojected world plus the accumulated tz.
   - A node with w ≤ 0 (tz ≤ −f) has its own content culled, while its children are still visited.
   - The projected translation stays unrounded, because Ruffle's shader works in continuous f32.
   - When tz == 0 the draw matrix is the unchanged `world`, which is what keeps every non-z test bit-identical.
   - Not modelled: rotationX/Y, a per-object `perspectiveProjection`, and z under filters or bitmap caching. Ruffle also ignores the
     per-object projection (its TODO).
4. `Avm2DisplayObjectExt.render_tz` (`include/avm2/avm2_globals.h`) is a mid-struct field, not appended after `blend_mode_id`, so it
   cannot collide with siblings' trailing fields. `m3d_tz_set` keeps it in sync with the `__mtz` dyn prop, so the render walk never does a
   dynamic lookup.
5. `ruffle-tests/render_canary_tests.txt`: two members appended at EOF, `avm2/stage_scale_factor` (noScale at a 2× HiDPI viewport,
   which exercises the restore branch) and `avm2/pixelbender_effect_twirl` (showAll non-uniform fit). Both are CI-passing; before this
   patch the canary had no AVM2 view-transform member.

Sibling map: I touched only my own regions (the scaleMode/align setters, the render-gate tail, the head of the `avm2_render_node` body and
its leaf-draw block, plus `m3d_tz_set`). `w2-filter-fixes` also edits `avm2_render_filtered` / `avm2_render_alpha_masked`, which are
separate functions; my edits in `avm2_render_node` sit in the body after those dispatch arms.

## 4. Canary, regression suite, trace A/B (same box, clean master vs patch)

- **Standing canary** (`render_canary.py capture`, the whole list including my 2 EOF members): 72 tests / 127 PNGs, **IDENTICAL 127,
  DIFFERS 0**; trace status changes none; image status changes none.
- **Extra A/B list** (63 tests, 44 PNGs). Every viewport_dimensions test, every avm2/visual test whose SWF or Test.as sets scaleMode,
  every test that sets `z` / `matrix3D` / rotation*, and 6 extra AVM2 `regression/` rows (`avm2_parent_child_render`,
  `avm2_timeline_solid`, `avm2_static_text`, `avm2_timeline_text`, `avm2_parent_child_static_text`, `avm2_goto_catchup_scale`).
  Result: IDENTICAL 41, DIFFERS 3 (exactly the ledger); **trace status changes none** (63/63 same, `ruffle_matched` rows included).
- **Regression suite**: 5 regression rows in the standing canary plus the 6 above. All md5-identical, all trace-pass both legs.
- **No-graphics** (the getters run in both modes): `stage_properties2`, `stage_overriden_setters`, `displayobject_z`, `geom_transform`,
  `perspective_projection_basic`, `stage_scale_factor` all PASS with the patch.
- No new regression fixture: every new behaviour that renders has a corpus test. The behaviours that don't (non-centre align under a
  larger viewport, exactFit/noBorder) are under LOCAL ORACLE REQUESTS.

## 5. Not finished / known gaps (each with its completion mechanism)

- **Flash's soft edge on matrix3D objects** (the residual on both z rows): not modelled. Completion mechanism: only if a future z test
  fails on edges. That would need the bitmap draw sampled bilinear with an extended edge for projected objects; a Ruffle render
  (oracle request 1) would tell us whether Ruffle's own golden is Flash's.
- **Stage.stageWidth/stageHeight under noScale** still return the movie size. Ruffle returns viewport/scale_factor and fires
  `Event.RESIZE`. That moves no corpus test: glassDisplace has no trace, and `stage_scale_factor` gives 550 either way. Completion
  mechanism: a trace test that reads stageWidth after noScale on a non-matching viewport.
- **Mouse device→stage mapping** does not see the new view matrix. No corpus test has mouse input under noScale with a mismatched
  viewport. Completion mechanism: route the AVM2 mouse unproject through `app->stage_to_ndc` when a game needs it.
- **Invalid scaleMode → #2008** is not thrown (see §3.1).
- **Emscripten build not compiled here** (no emsdk in the cloud). The new code sits under the exact `#if` of the existing render gate
  and uses only symbols that gate already uses. Completion mechanism: the coordinator's `deploy-pages.yml -f dry_run=true`, or the next
  Pages deploy.

## 6. New unclaimed leads

- `avm2/stage3d_bitmap` and `avm2/stage3d_texture` (in my extra list, both still failing, untouched) and the AVM1 view transform. AVM1's
  `Stage.scaleMode` is a separate path; I did not check whether any AVM1 image test sets noScale on a mismatched viewport.
- `visual/filters/any_blur_scales_with_screen` (4884/0) and `visual/edittext/edittext_gutter` (1014/0) are failing viewport/edittext rows,
  untouched by this patch. They are not view-transform bugs: their fit is the default.

## LOCAL ORACLE REQUESTS

1. (Optional) **Ruffle exporter, `avm2/displayobject_z/test.swf`, `quality = "high"`**: the rendered PNG. It would tell us whether the
   soft 8-px edge in the golden is Flash-only (so Ruffle's own render has hard edges like ours) and confirm the −480.25 cull. Not needed
   for the flip.
2. **New fixture oracle (align/exactFit/noBorder)**: a tiny AS3 SWF, 200×100 stage, viewport 400×400 (`scale_factor` 1), drawing a 200×100
   red rect at (0,0) plus a blue 20×20 square at (−10,−10). It then sets, in turn, `scaleMode` ∈ {noScale, exactFit, noBorder} ×
   `align` ∈ {"", "TL", "BR", "tlbr"}, and traces `stage.scaleMode`, `stage.align` after each set. Need: Flash (preferred) or the Ruffle
   exporter trace, plus a frame-1 PNG for 2-3 of the combinations. That would become `regression/avm2_stage_scalemode_align`.
