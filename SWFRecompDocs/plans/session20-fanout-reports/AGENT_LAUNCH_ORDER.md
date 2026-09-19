# Session 20 — agent launch-order id map

s14 lesson: **verify a SendMessage recipient against this table before sending.** The
coordinator once crossed two ids and sent a re-prioritisation to the wrong agent. Every brief
also tells its agent to reply "not my brief" if a message does not match its task.

## Batch 1 (launched 2026-09-18, 8 live — the concurrency cap)

| # | label | wave | isolation | task |
|---|---|---|---|---|
| 1 | w1-drift | 1 | main tree, read-only | upstream drift audit vs `~/CC/ruffle` @`f2aaf0703` + ignore-list re-test |
| 2 | w1-gnash-actionorder | 1 | main tree, read-only | `from_gnash/misc-ming.all/action_order/*` 11-row cluster |
| 3 | w1-avm1-globals | 1 | main tree, read-only | avm1 `global*_decls` / `globals_*` / `native_objects_swf6` (6 rows) |
| 4 | w1-gnash-array | 1 | main tree, read-only | gnash `array-v5..v8`, `MovieClip-v6..v8`, `argstest-*`, `TextField-*` (12 rows) |
| 5 | w1-stage3d | 1 | may prototype in throwaway worktree | Stage3D A′ stencil/colorMask + B textures/RTT + `stage3d_bitmap` |
| 6 | w2-coerce | 2 | worktree | `spvPropertyCoerceToNumber` ±Infinity + `_alpha` quantizer |
| 7 | w2-evenodd | 2 | worktree | one even-odd fill across `lineStyle()` (`gfx_line_style`/`gfx_finalize_path`) |
| 8 | w2-gfx-text-smalls | 2 | worktree | device-face bold/italic ladder + EditText border corner |

## Held queue (written briefs; spawn as slots free — NEVER exceed ~8 live)

The 5-hour cap killed 12 live agents in s18 and the weekly cap killed 10 in s16. Nothing is
lost (worktrees keep patches and reports), but resume with a "you were terminated, resume
actively; check disk, rerun only what is missing" brief and **probe the reset with ONE agent
before respawning the queue**.

| label | wave | task | source |
|---|---|---|---|
| w2-bitmapdata-rect | 2 | `avm1/bitmapdata_custom_rectangle` → `ruffle_matched` (+1): built-in `getColorBoundsRect` must construct via the **dynamically-resolved** `flash.geom.Rectangle` | arc §20.5 |
| w1-hitarea | 1 | `hitarea_remove_owner_drag` — ONE mechanism left (the single topmost pick) but the **largest blast radius on the board**: rewrites roll events for every overlapping-button title and must reconcile `tag.c`'s second hover machine. Diagnosis first, implementation only on a GO. | arc §20.5 |
| w1-masks-hittest | 1 | `from_gnash/misc-ming.all/masks_test` at 124/175 — 34 of the 50 remaining diff lines are `hitTest` on masked/mask clips (a **hit-test** slice, not an events one). Rider: `avm1/movieclip_hittest_shapeflag`. | arc §20.5 |
| w2-stage3d | 2 | productionize whatever w1-stage3d's report prices as GO (A′ and/or B) | w1-stage3d report |
| w1-avm2-smalls | 1 | the unpriced avm2 tail: `bom`, `dependent_strings`, `number_to_string`, `swz`, `tab_ordering_properties`, `textblock_recreateline`, `textline_atom_index_at_char_index`, `verify_method_info_duplicate`, `simplebutton_childevents_multichild`, `avm1_root`, `mouse_pick_loader_avm1`, `focus_events_mixed_avm_edittext`, `selection_onsetfocus_mixed_avm`, `loader_applicationDomain`, `loader_load`, `sound_load_multiple` | wave0 inventory |
| w1-avm1-smalls | 1 | the unpriced avm1 tail: `date`, `geturl`, `load_vars`, `stylesheet_load`, `xml_getbytes`, `bitmap_data_thorough/pixelDissolve`, `sandbox_type_remote` (+ `from_shumway/{LoaderLoadBytesTest,as3-loader/events/loader-events,esc}`) | wave0 inventory |
| w2-pixel-followup | 2 | next pixel cluster after the board's head clears: `diffuse_mixed × Filters` (10 cmps, 0 near-pass), `row_banded` (7), `content_displaced × Text` (4). **`blend_modes` ×12 is NO-GO and s18's completion mechanism for it is refuted — do not fund the recompiler A/B sweep.** | playbook §18 + wave0 image board |

## Standing NO-GOs (arc §20.5) — do not re-price without a reason
`avm2/external_interface` (102 lines are one AVM2 test harness) · the audio trio
(`audio_computespectrum`, `netstream_play_flv`/`_stop_replay`/`_seek_flv`, `misc-swfc.all/sound`
— blocked on `computeSpectrum`, FLV audio decode and a mixer tap; s18's "needs a real FFT"
reason was wrong, it is a hand-rolled DFT) · `fonts/embed_name_lookup` ·
`from_avmplus/regress/bug_483783` · `pcre_find_fixedlength` · `avm2/number_tostring` ·
`mixed_avm/avm1_loads_avm2` (harness gate) · `from_gnash/misc-ming.all/GradientFillTest`
(structurally unpromotable) · `from_shumway/bitmapdata/getpixel-from-embedded` (a disposition,
not a fix) · pixel: `blend_modes` ×12.
