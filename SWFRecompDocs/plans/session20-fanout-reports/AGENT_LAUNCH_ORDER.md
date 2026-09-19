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

## Batch 2 (spawned as batch-1 slots freed)

| # | label | wave | isolation | task | replaced |
|---|---|---|---|---|---|
| 9 | w1-avm2-smalls | 1 | main tree, read-only | the 16-row unpriced `avm2` tail + 3 loader riders | w1-avm1-globals |
| 10 | w2-goto-framescript | 2 | worktree | `goto_framescript_queued/{swf9,swf10,swf13}` + `…_same_frame`, M1 version-gate + M2 `ext->playing` placement — **+4 eff for ~25 LOC, cheapest yield on the board** (priced by w1-drift) | w1-drift |
| 11 | w2-avm1-nearflips | 2 | worktree | `xml_getbytes` phase error, `geturl` re-diagnosis, 7 stale ignore prunes, `image_triage.py:911` wording bug (all from w1-drift's refutations) | w1-gnash-actionorder |

## Completed, with verdicts

| label | outcome |
|---|---|
| w1-avm1-globals | **+1 priced, not funded.** Cluster refuted: 2 rows, not 5 (`DONT_DELETE`/CONFIGURABLE flag, not an inventory gap). Raw inventory diff-lines overstate the real defect count **30–180×** on `known_failure` rows. `globals_swf5` NO-GO — upstream ships two contradictory Flash captures and we already pass the other three rows. Found: `results_flash.json` is 0 pass / 3 fail on 2026-04-13 fixtures, still wired into CI. |
| w1-drift | **CI name-set delta EMPTY** (proved two ways: commit timestamps + a 4527−95=4432=4440−8 name reconciliation). So every flip this session is real yield, not drift. Spun off agents 10 and 11. |
| w1-gnash-actionorder | **Premise REFUTED, 0 flips, slot saved.** See the method lesson below. |

## Method lesson earned this session — absence from the board ≠ unpriced

I funded the `from_gnash/.../action_order` cluster on the inference *"largest cluster the s20
board doesn't name ⇒ unclaimed cheap yield."* **That inference is inverted.** Those rows are
absent from `polish-sweep-arc.md` §20.5 because **s17 STRUCK them** (the strike is recorded at
`polish-sweep-arc.md:2277`), after the family had been adjudicated in six consecutive sessions
(s13, s14, s15, s17, s18, s19 — s19 re-verified 9 of the 11 rows byte-identical one session
ago). They are also not one mechanism: eight core rows = five mechanisms, two of them
**sign-opposite** (`_test6` wants cancelled-placement events to FIRE, `PlaceAndRemove` wants
them SUPPRESSED), which is why three prior implementation attempts each bought +1/+2 lines.

**Rule for future coordinators: before funding a cluster because the board omits it, grep the
arc doc for a STRIKE on it.** A struck family looks identical to an unpriced one from the
failure inventory alone.

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


## Batch 3 + resumes (spawned as slots freed)

| label | wave | task | origin |
|---|---|---|---|
| w2-goto-framescript | 2 | the 4-row `goto_framescript_queued` arc | w1-drift's GO |
| w2-avm1-nearflips | 2 | `xml_getbytes`, `geturl`, 7 ignore prunes, `image_triage.py` | w1-drift's refutations |
| w2-masks-hittest | 2 | `masks_test` hitTest arity | held-queue |
| w2-arraysort (resume of w1-gnash-array) | 2 | Flash-exact quicksort arc, **user-funded** | user ruling |
| w2-avm2-smalls (resume of w1-avm2-smalls) | 2 | textblock/number_to_string/avm1_root | its own nomination |
| w2-stage3d (resume of w1-stage3d) | 2 | productionize the measured A′/B prototype | its own prototype |
| w2-smalls-2 | 2 | `bitmapdata_custom_rectangle` + `tab_ordering_properties` | §20.5 + sibling |

**Resuming a completed wave-1 agent as its own wave-2 implementer was the cheapest
pattern this session** — it keeps every located line number, every measurement and every
refutation, at zero re-derivation cost. Used four times (arraysort, avm2-smalls, stage3d,
and masks by message). The agent creates its own worktree with `git worktree add`; the
coordinator reaps it.

## Ledger at the early grading run (`35421084855` @ `8040b8f63`)

Trace flips realised and headline re-checked at merge: **+8**
- `from_gnash/misc-ming.all/masks_test` → ruffle_matched (`0298748e8`)
- `avm1/xml_getbytes` → pass (`974be3738`)
- `avm2/goto_framescript_queued_same_frame`, `/swf9`, `/swf10` → pass; `/swf13` → ruffle_matched (`9bf25e809`)
- `avm1/bitmapdata_custom_rectangle` → ruffle_matched; `avm2/tab_ordering_properties` → pass (`166b2b4f4`)

Pixel flips realised: **+11** (`visual/edittext/edittext_caret_empty` ×11, `6cf74920c`)

Honest zero-flip work landed: the AVM2 even-odd fill (`78030002d`, −152 channels), the
array ladder's M1+M4 (`6b7486783`, one mechanism from +3 now), the four-path coercion gate
(`3a8870200` + `d5278b4e9`, new `regression` fixture 18/36 wrong → PASS), the device-face
ladder (`6cf74920c`, a prerequisite that moves nothing alone).

Still out at dispatch: w2-avm2-smalls (+3 priced), w2-stage3d (+8 pixels measured).
