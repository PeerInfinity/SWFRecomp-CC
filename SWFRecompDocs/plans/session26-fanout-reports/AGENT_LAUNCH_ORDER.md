# Session 26 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed for s26 2026-11-23): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator local
(merge, CI dispatch, results accounting, exporter oracle `0ddd12b6a`). Size: full.
Baseline: s25 FINAL — graphics/full/images `45078991452` (results `9277f3799`) + no-graphics/full `45079002150`
(results `dffc41cf2`), code `697669e5f`. Read at `9277f3799`: trace 4636 eff / 4677 rows (41 failing); pixels 572/624
(561/613 on the s24 set). No wave-0 run (only docs since).
Upstream `3ac8dcb07..3e98d9ba6` (5 commits) — `wave0-upstream-drift-namestatus.txt`.
Parallel LOCAL one-task session: `n-pixel-pass` (launched at wave-2 start).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift | both | 5 upstream commits: `file_reference_upload_request`, `pixelbender_conditional`, `vp6_inter_frames` | session_018CoDi5YzTbaDjXQv7Wga2a — DELIVERED; prototype LANDED directly `c380aecd5` (+1 trace `file_reference_upload_request`, both modes; pixelbender_conditional + vp6 drift = verdict no-ops; 29-row sweep identical) |
| 2 | w1-runtime-robustness | trace | `ng_shared.c` fixed MAX_* caps, float-through-u64 store, `-fno-strict-aliasing` audit | session_018CoDi4WHDYx1GAABAqcRbo |
| 3 | w1-avm1-dispatch-scope | trace | arc §26.4 AVM1 leftovers (bare-call `with`, type-2 flags, function-form timer, hairline hitTest, …) | session_018CoDi41gFdju4MePGmDgyc |
| 4 | w1-attached-button-dispatch | both | native `ng_update_button_states_attached` + `String_path_variable_button` | session_018CoDi7Ln3aUjgDoPY2rvxY — DELIVERED; (b) LANDED `0cb6a9512` (+1 px `String_path_variable_button`: button-record EditText binds past the button parent); (a) LANDED `876e66704` (CI-mode attached-clip button dispatch, 0 corpus flips — refuted "CI-visible"; fixture `avm1_attached_clip_button_click`, golden = Ruffle test runner at num_frames=15; tag.c NO_GRAPHICS arm → early no-graphics run). Browser N "play game" re-check → n-pixel-pass |
| 5 | w1-pixel-nearpass | pixel | bevel (3 px), small-excess rows, AVM2 `gfx_gen_ramp` + CPU gradient sampler | session_018CoDi6LaNQmB7xc3hvABEr — DELIVERED; prototype LANDED directly `509768d1d` (+2 px `morph_test1 frame1` (sprite-nested EditText z-order), `filters/bevel` (stb midpoint trunc, recompiler; zero headroom 6/6); AVM2 `gfx_gen_ramp` twin NO-GO (moves away from Flash); oracle request 3_joystick unsatisfiable — mouse-driven `input.json`, exporter has no input replay) |
| 6 | w1-pixel-layer-colour | pixel | layer N1/N3, AVM1 off-diagonal CM, draw() of filtered sources, Drawing-API colour | session_018CoDi6ZWEvZmb1sAonaudB — DELIVERED; prototype LANDED directly `ed35fe421` (0 corpus; N1 filtered child in layer group AVM1+AVM2, placed Drawing-API colour, CM alpha-row cull; 3 fixtures, exporter-confirmed max 0; off-diagonal CM "needs GPU pass" refuted for RGB; N3 + draw()-of-filtered NO-GO: Ruffle differs from Flash) |
| 7 | w1-pixel-tail | pixel | static_text_offstage (c), pixelbender_dithering, acid-color-0, disposition records | session_018CoDi69tgZvsTJJmyB7xMV |
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
| (landed direct) w1-trace-tail-audit prototype | w1-trace-tail-audit P1–P3 | trace `from_gnash/misc-swfc.all/sound` (+1); lines pixelDissolve 1335→1351, matrix_accuracy_test1 10→12 | — |

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45094460914 | graphics / full / **images** | 509768d1d (drift +1 trace; trace-tail-audit +1 trace; pixel-nearpass +2 px; recompiler → Pages dry run 45094486900) | running |
| 45096347136 | no-graphics / full | 876e66704 (+ attached-button (a)+(b): tag.c NO_GRAPHICS arm) | queued |
