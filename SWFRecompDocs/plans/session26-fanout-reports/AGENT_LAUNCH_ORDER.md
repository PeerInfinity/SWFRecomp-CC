# Session 26 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed for s26 2026-11-23): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator local
(merge, CI dispatch, results accounting, exporter oracle `0ddd12b6a`). Size: full.
Baseline: s25 FINAL — graphics/full/images `45078991452` (results `9277f3799`) + no-graphics/full `45079002150`
(results `dffc41cf2`), code `697669e5f`. Read at `9277f3799`: trace 4636 eff / 4677 rows (41 failing); pixels 572/624
(561/613 on the s24 set). No wave-0 run (only docs since).
Upstream `3ac8dcb07..3e98d9ba6` (5 commits) — `wave0-upstream-drift-namestatus.txt`.
Parallel LOCAL one-task sessions: `n-pixel-pass` DONE (report verified) → `n-collector-uaf` (launched, landed `440ecf35b`: removed-clip dprops detach = N retry collector UAF; fixture `avm1_removed_clip_dprops_gc`). `n-pixel-pass` — landed `8301fd233` + `495dbde90` (attached-pump UAF/hijack fix exposed natively by 876e66704; browser enterFrame off-by-one; fixture `avm1_attached_clip_samename_child`; N play-game re-check PASSES native + browser) (launched 02:15 UTC at wave-2 start, run.UsMIbJFi, handshake sent; carries the N play-game re-check for 876e66704).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift | both | 5 upstream commits: `file_reference_upload_request`, `pixelbender_conditional`, `vp6_inter_frames` | session_018CoDi5YzTbaDjXQv7Wga2a — DELIVERED; prototype LANDED directly `c380aecd5` (+1 trace `file_reference_upload_request`, both modes; pixelbender_conditional + vp6 drift = verdict no-ops; 29-row sweep identical) |
| 2 | w1-runtime-robustness | trace | `ng_shared.c` fixed MAX_* caps, float-through-u64 store, `-fno-strict-aliasing` audit | session_018CoDi4WHDYx1GAABAqcRbo |
| 3 | w1-avm1-dispatch-scope | trace | arc §26.4 AVM1 leftovers (bare-call `with`, type-2 flags, function-form timer, hairline hitTest, …) | session_018CoDi41gFdju4MePGmDgyc — DELIVERED; prototype LANDED directly `a18a9cc61` (0 corpus; 7 game-visible AVM1 fixes, 7 fixtures oracle-confirmed (exporter ×6, Ruffle runner ×1); HELD: html_typed_runs (runner differs on insert-at-0), wrap_giveup + mc_resolve (unfixed HOLDs, oracle-confirmed goldens archived); leads: browser createTextField is a no-op, __resolve on clips, DefineFunction2 register OOB → w2-robustness-land) |
| 4 | w1-attached-button-dispatch | both | native `ng_update_button_states_attached` + `String_path_variable_button` | session_018CoDi7Ln3aUjgDoPY2rvxY — DELIVERED; (b) LANDED `0cb6a9512` (+1 px `String_path_variable_button`: button-record EditText binds past the button parent); (a) LANDED `876e66704` (CI-mode attached-clip button dispatch, 0 corpus flips — refuted "CI-visible"; fixture `avm1_attached_clip_button_click`, golden = Ruffle test runner at num_frames=15; tag.c NO_GRAPHICS arm → early no-graphics run). Browser N "play game" re-check → n-pixel-pass |
| 5 | w1-pixel-nearpass | pixel | bevel (3 px), small-excess rows, AVM2 `gfx_gen_ramp` + CPU gradient sampler | session_018CoDi6LaNQmB7xc3hvABEr — DELIVERED; prototype LANDED directly `509768d1d` (+2 px `morph_test1 frame1` (sprite-nested EditText z-order), `filters/bevel` (stb midpoint trunc, recompiler; zero headroom 6/6); AVM2 `gfx_gen_ramp` twin NO-GO (moves away from Flash); oracle request 3_joystick unsatisfiable — mouse-driven `input.json`, exporter has no input replay) |
| 6 | w1-pixel-layer-colour | pixel | layer N1/N3, AVM1 off-diagonal CM, draw() of filtered sources, Drawing-API colour | session_018CoDi6ZWEvZmb1sAonaudB — DELIVERED; prototype LANDED directly `ed35fe421` (0 corpus; N1 filtered child in layer group AVM1+AVM2, placed Drawing-API colour, CM alpha-row cull; 3 fixtures, exporter-confirmed max 0; off-diagonal CM "needs GPU pass" refuted for RGB; N3 + draw()-of-filtered NO-GO: Ruffle differs from Flash) |
| 7 | w1-pixel-tail | pixel | static_text_offstage (c), pixelbender_dithering, acid-color-0, disposition records | session_018CoDi69tgZvsTJJmyB7xMV — DELIVERED; +2 px `static_text_offstage`, `pixelbender_dithering` + 1 trace gnash `BitmapDataDraw` priced (prototype measured, 221-cmp sweep = ledger); `bitmapbuttons` NO-GO refuted (618042 → 52); stage3d premise refuted (CPU shading-budget latch); 20 dispositions drafted (§4) → w2-tail-bitmap-draw, w2-blendshader-cpu-pbj, w2-text-cx-jpeg3 |
| 8 | w1-per-movie-displaylist | trace | per-movie display lists (`video_prototype_lazy_swf6_child`), L arc | session_018CoDi7W2f8gCE4qKFtnijA — DELIVERED; phase 1 LANDED directly `a6a696bf2` (+1 trace `video_prototype_lazy_swf6_child`, both modes; L refuted → M; 104 loaded-child rows + regression 130/130 identical) |
| 9 | w1-trace-tail-audit | trace | re-audit every unowned failing trace row's disposition | session_018CoDi6RBRjLbbF7nJnBmFk — DELIVERED; prototype LANDED directly `f9a36d8fc` (+1 trace gnash `sound`: SWF6 case-insensitive `gotoandPlay`, "no audio" disposition refuted, ignore pruned; pixelDissolve +16 lines, matrix_accuracy_test1 +2; 9 doc corrections queued for closeout, report §6) |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| (landed direct) w1-drift prototype | w1-drift | trace `avm1/file_reference_upload_request` (+1) | — |
| (landed direct) w1-pixel-nearpass prototype | w1-pixel-nearpass T+M | px `from_gnash/misc-ming.all/morph_test1` frame1, `visual/filters/bevel` (+2) | — |
| (landed direct) w1-attached-button-dispatch (b)+(a) | w1-attached-button-dispatch | px `visual/text/String_path_variable_button` (+1); fixture `avm1_attached_clip_button_click` | — |
| (landed direct) w1-pixel-layer-colour prototype | w1-pixel-layer-colour 1+2+3 | 0 corpus; fixtures `layer_group_filtered_child`, `avm2_layer_group_filtered_child`, `avm1_placed_drawing_color` | — |
| (landed direct) w1-per-movie-displaylist phase 1 | w1-per-movie-displaylist | trace `avm1/video_prototype_lazy_swf6_child` (+1) | — |
| (landed direct) w1-avm1-dispatch-scope prototype | w1-avm1-dispatch-scope 1,2,3,4+6,5a,7a | 0 corpus; 7 fixtures | — |
| (landed direct) w1-trace-tail-audit prototype | w1-trace-tail-audit P1–P3 | trace `from_gnash/misc-swfc.all/sound` (+1); lines pixelDissolve 1335→1351, matrix_accuracy_test1 10→12 | — |
| w2-loaded-shell-phase2 | w1-per-movie-displaylist phases 2–5 | 0 corpus expected; fixtures (oracle-gated) | session_018CoDi3qAjMx8NTxuARGv4B |
| w2-attached-holder-render | w1-attached-button-dispatch leads | 0 corpus; holder render fixture (exporter golden archived) + button-order fixtures | session_018CoDi6mwbQ8ti45PPishTC |
| w2-avm2-applyfilter-kernels | w1-pixel-layer-colour §5/§6 lead 1 | 0 flips likely (destpoint_edges −90k ch); fixture | session_018CoDi3QyC6rq1emewZ6Qio — DELIVERED, LANDED `18a58261a` (0 flips: destpoint_edges 149477 → 30394; fixtures HELD: Ruffle trace ±1–2 on 6/23 lines; draw-filtered needs Flash) |
| w2-acid-clip-fill-region | w1-pixel-nearpass leads 1–3 | px `acid-clip` (≤50 %), bevel headroom, acid-text-6 | session_018CoDi4EesSxTLA7Sbzmj5P — DELIVERED, LANDED `5f4db0e60` (+4 px cmp: `acid-clip`, `3_joystick` (1 level headroom), `acid-text-6` output+frame5; w1 "char 6 region order" refuted: cross-layer stroke order; bevel O 2 px HOLD) |
| w2-cm-chain-cab-edge | w1-pixel-layer-colour §3 HOLD + lead 2 | px `cache_as_bitmap/avm1_color` (unpriced); CM chain fixtures | session_018CoDi3eaG9cg1bPYFHbXKC — DELIVERED, LANDED `3a8e02dcd` (0 corpus; inexact PO3 CM folds → live passes; 3 fixtures exporter-confirmed; HOLD (a) refuted with mechanism (Ruffle divides by src.a); cAB avm1_color NO-GO: Flash-ward rule costs 3 passes) |
| w2-tail-bitmap-draw | w1-pixel-tail §1+§2 | px `visual/static_text_offstage`, `avm2/pixelbender_dithering` (+2); trace gnash `BitmapDataDraw` rm → pass; band `bitmapbuttons` | session_018CoDi4RBPJBRoWYRoa2SFa — DELIVERED, LANDED `1aef9cc7b` (+2 px `static_text_offstage`, `pixelbender_dithering`; +1 trace gnash `BitmapDataDraw`; `bitmapbuttons` band 618042 → 52) |
| w2-blendshader-cpu-pbj | w1-pixel-tail §4b | px `avm2/blend_shader_luma_lighten` (odds good); rider `shader_as_mask` | session_018CoDi7FDvcL7M7FaHUNJxk — DELIVERED, LANDED `b66bfdfc8` (+1 px `blend_shader_luma_lighten`; `shader_as_mask` KF 2100 → 366) |
| w2-text-cx-jpeg3 | w1-pixel-tail §3 | 0 flips (acid-color-0 band 17315 → ~325); fixtures | session_018CoDi4MjmBxavJc5ewGTWY — DELIVERED, LANDED `84e4fefc0` (0 flips: acid-color-0 17315 → 314; fixtures `avm1_jpeg3_alpha_bitmap` (exporter golden), `avm1_edittext_placed_cxform_script` (trace); image twin HELD: 9 border-corner px vs Ruffle → w2-edittext-border-cx) |
| w2-robustness-land | w1-runtime-robustness | fixtures ×7 (5 traces + 2 PNGs exporter-confirmed); crash fixes (func2 register OOB, gotoFrameFromInterval runaway) | session_018CoDi6kBSMAMxXhVLgzZdE |
| w2-timer-semantics | w2-robustness-land lead 1 | gotoFrameFromInterval residual; timer fixtures | session_018CoDi69QAZ1ysG4swi6ZAF |
| w2-applyfilter-edge-growth | w2-avm2-applyfilter-kernels HOLD 2 + held fixture | destpoint_edges flip (high risk); glow-kernels fixture | session_018CoDi46SG4bjMhZbxqrbbZ |
| w2-edittext-border-cx | w2-text-cx-jpeg3 held fixture + steps 3–4 | fixture `avm1_edittext_placed_cxform`; acid-color-0 band | session_018CoDi5pCzqSEvju1uLdFYW |
| w2-avm1-text-resolve | w1-avm1-dispatch-scope HOLDs | fixtures `avm1_mc_resolve`, `avm1_wrap_giveup_mixed_runs` (goldens confirmed) | session_018CoDi6PrK2Yq8TssZEvgn5 |

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45094460914 | graphics / full / **images** | 509768d1d (drift +1 trace; trace-tail-audit +1 trace; pixel-nearpass +2 px; recompiler → Pages dry run 45094486900 FAILED at 'Set up job' (actions/configure-pages download timeout, infra), re-dispatched 45101106488) | **DONE, ledger exact**: trace 4639 → 4641 eff / 4680 (+2: `file_reference_upload_request`, gnash `sound`), 0 regressions; pixels +2 (`morph_test1 frame1`, `filters/bevel`) → 574 / 624, 0 regressions. Results `d78d6702c` |
| 45096347136 | no-graphics / full | 876e66704 (+ attached-button (a)+(b): tag.c NO_GRAPHICS arm) | **DONE, ledger exact**: 4637 → 4639 eff / 4680 (+2: `file_reference_upload_request`, gnash `sound`), 0 regressions; new `avm1_attached_clip_button_click` passes. Results `3d82dac3f` |
| 45104409805 | graphics / full / **images** | a18a9cc61 (+ attached-button a+b, layer-colour, per-movie DL phase 1 (+1 trace), acid-clip (+4 px cmp), applyfilter kernels, blendshader (+1 px), dispatch-scope; n-pixel-pass 8301fd233+495dbde90; recompiler → Pages dry run 45104412462 success) | **DONE, ledger exact**: trace 4641 → 4642 eff (+1 `video_prototype_lazy_swf6_child`), 0 regressions; pixels +6 by name (`blend_shader_luma_lighten`, `3_joystick`, `acid-clip`, `acid-text-6` ×2, `String_path_variable_button`) → 583 / 627, bands `shader_as_mask` −83 %, `destpoint_edges` −80 %, 0 regressions; regression 142/142 pass. Results `a32f43a75` |
