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
| 4 | w1-attached-button-dispatch | both | native `ng_update_button_states_attached` + `String_path_variable_button` | session_018CoDi7Ln3aUjgDoPY2rvxY |
| 5 | w1-pixel-nearpass | pixel | bevel (3 px), small-excess rows, AVM2 `gfx_gen_ramp` + CPU gradient sampler | session_018CoDi6LaNQmB7xc3hvABEr |
| 6 | w1-pixel-layer-colour | pixel | layer N1/N3, AVM1 off-diagonal CM, draw() of filtered sources, Drawing-API colour | session_018CoDi6ZWEvZmb1sAonaudB |
| 7 | w1-pixel-tail | pixel | static_text_offstage (c), pixelbender_dithering, acid-color-0, disposition records | session_018CoDi69tgZvsTJJmyB7xMV |
| 8 | w1-per-movie-displaylist | trace | per-movie display lists (`video_prototype_lazy_swf6_child`), L arc | session_018CoDi7W2f8gCE4qKFtnijA |
| 9 | w1-trace-tail-audit | trace | re-audit every unowned failing trace row's disposition | session_018CoDi6RBRjLbbF7nJnBmFk — DELIVERED; prototype LANDED directly `f9a36d8fc` (+1 trace gnash `sound`: SWF6 case-insensitive `gotoandPlay`, "no audio" disposition refuted, ignore pruned; pixelDissolve +16 lines, matrix_accuracy_test1 +2; 9 doc corrections queued for closeout, report §6) |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| (landed direct) w1-drift prototype | w1-drift | trace `avm1/file_reference_upload_request` (+1) | — |
| (landed direct) w1-trace-tail-audit prototype | w1-trace-tail-audit P1–P3 | trace `from_gnash/misc-swfc.all/sound` (+1); lines pixelDissolve 1335→1351, matrix_accuracy_test1 10→12 | — |

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
