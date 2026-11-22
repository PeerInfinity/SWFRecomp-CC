# Session 25 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-22): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle). Size: full (user 2026-11-22: fan-outs also use
expiring credits, so diminishing returns are fine).
Trace baseline: run `45043930556` (graphics/full) at `746c39489`, results `7f945eb41` (merged `64c742e9e`): 4613 eff,
49 failing graphics rows. Pixel baseline: s24 final `44986836161` at `9561027db` (results `08fdbcad6`): 539 / 613.
Upstream `bcac30c19..3ac8dcb07` (9 commits, 3 new AVM2 tests) — `wave0-upstream-drift-namestatus.txt`.
Wave-0 local oracles (exporter `0ddd12b6a`): `w0-local-oracles/` (attach Ratio + PO3 variants == fixture oracle;
Array generics on Function/MovieClip receivers work in Ruffle).
Parallel LOCAL one-task session: `n-play-game` (N "play game" click does nothing; wsl-launch, Opus, PID 57630,
handshake sent).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift-avm2 | trace | 3 new upstream AVM2 rows (ShaderJob 1/2-channel, recreateTextLine width, LC allowNetworking) | session_018CoDi6J5YQJTWUQrMyZKvW — DELIVERED; prototype LANDED directly `1a10f176e` (+2: `pixelbender_shaderjob_output_channels`, `textblock_recreate_text_line_width`; LC row drift already passing; 0 riders/53, both modes; touches recompiler + browser-shared header → Pages dry run at grading) |
| 2 | w1-textfield-vn | trace | gnash TextField-v6/7/8 plan of record (13 phases) + edittext_set_text_same pair | session_018CoDi6KKD2sWxiZX1qXQHn |
| 3 | w1-avm1-proto-timeline | trace | loaded-root goto routing, TextFormat accessors, attach L4/L5/L2 (oracles in hand) | session_018CoDi7npxwH9NpjHNi23Dm |
| 4 | w1-avm1-filters-complete | both | AVM1 PO3 multi-filter, getter depth, CM/Convolution/DM, dynamic-root bitmaps/text | session_018CoDi7rZSo5uSZfocqWxZk |
| 5 | w1-pixel-nearpass | pixel | ~17 small-excess comparisons | session_018CoDi459cXj5v4ThUCiZ74 |
| 6 | w1-pixel-text | pixel | acid-text*, captions, hardwrap, stylesheet, edittext device transform/gutter, static_text_offstage (c), acid-color-0 | session_018CoDi7WfMsx8cJhBoubZ9c |
| 7 | w1-pixel-blend-mask | pixel | layer_alpha/erase, masks, colortransform, place_object_test, bitmapbuttons | session_018CoDi3WCycTC59VRC5FWW5 |
| 8 | w1-pixel-drawing | both | drawing API, strokes, bitmap fills, dithering; DrawingApiTest hitTest plan | session_018CoDi7j4VX9FRpURSWw5EY |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
