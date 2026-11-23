# N: in-game tile colour + missing HUD (time bar, level name): closeout (2026-11-22)

This one-task session is the successor to `n-gold-residue` (`n-gold-residue-report.md` §7). Baseline: master `6063933ad`.

**Result: all three visible differences are fixed in the browser build.** They were three separate runtime bugs:

| # | Symptom | Root cause | Fix |
|---|---|---|---|
| 1 | Walls drawn raw `#333`; Ruffle draws `0x797A88` | `Color` on an attachMovie'd **sprite** clip was never read at render | `tag.c`: the attached clip's world colour is passed into `compose_children` |
| 2 | Time bar missing | Non-root attached clips were drawn in `child_mc_cache` **creation** order, so N's tiles (created at level load into a lower buffer) painted over the HUD (created at startup into the top buffer) | `tag.c`: the attached post-loop passes draw in Flash depth order |
| 3 | Time readout and "Episode 0 Level 0: the motherlode" text missing | `ng_shared.c` stored EditText metadata in a fixed 64-entry table. N defines **197** EditTexts, so fields #65+ (the HUD's 985 and 1026) were silently dropped and never got a TextField wrapper. The same fixed tables dropped shapes past 256 (N has 291) and morphs past 64 (N has 86), so their bounds were missing too | `ng_shared.c`: those six registries are now growable |

## 1. Repro and rig

- Browser: `build_test.sh flasharchive/N wasm --graphics --clean`, then `deploy_example.sh flasharchive/N ../docs2/examples --no-index --graphics`. Run `source emsdk/emsdk_env.sh` first, or the build dies with "emcc not found" in a background shell.
- Drive: `tools/divergence/game_drive/n_click_probe.py flasharchive/N "click@690,142;click@576,100;wait@12;wait@6;hold@Space,1"`. I used a scratch copy that screenshots only `#canvas` (`pg.locator("#canvas").screenshot(...)`). The full-page shot cuts off the bottom 40 px of the stage, which is exactly where the level name sits.
- **Ruffle oracle without clicks:** inject a probe (`tools/divergence/inject_tracer.py`) that attaches N's own HUD symbols (`timeIndicator`, `guiLevelNameMC`) to `_root` and to a `createEmptyMovieClip` buffer at tick 60. Then run the exporter for about 70 frames. The exporter cannot enter gameplay: `ValidateEpisodeReached` reads an empty SharedObject, and level load stalls. Attaching the HUD symbols directly avoids needing to enter gameplay.
- **Trap: `inject_tracer.py` bumps the SWF to version 8 by default.** N is SWF **6**, where identifiers are case-insensitive: N defines `NinjaGUI` and then adds `NinjaGui.prototype.ShowInGame/HideInGame/DrawLevelName`. At v8 both Ruffle and we lose those methods and the HUD never shows, which confounds any HUD probe. Always pass `--min-version 6` for N. Our SWF≤6 case folding is correct at v6.

## 2. Bug 1: tile colour

N's `TileMapCell` does `gfx.CreateSprite("tileMC", LAYER_TILES)`, which is `spritebuffer1700.attachMovie(...)`, followed by `new Color(mc).setRGB(7960968)`. That is about 825 tinted sprite clips.

- `setLocalCTRaw` mirrors the colour into `mc->cx_*`, and `mcSyncColorToDisplayObj` writes it to the clip's **standalone** `display_obj`. That struct is a container and is never drawn itself.
- `render_attached_child` (both builds) and `tagRerenderFrame`'s root-attached capture pass called `compose_children(..., parent_cx = NULL, 0)`. So no colour transform ever reached the clip's children. `d83fbab22` (s25 `w2-dynclip-cxform`) had covered only Drawing-API clips and attached bitmaps.
- **CI was wrong too, not just the browser:** the fixture showed graphics-native drawing root-attached tinted sprites untinted.

Fix (`tag.c`):
- New `attached_mc_local_cxform` builds the colour from `mc->cx_*` plus `mc->alpha`. Parentless `_root` / `_levelN` clips are treated as identity, because `getOrCreateLevel` HCALLOCs zero `cx_*`.
- New `attached_mc_world_cxform` composes the clip's colour under every non-root ancestor and mints one dynamic cxform slot. Slots are **deduplicated per frame** through an 8-entry cache that `cxform_overrides_reset` clears, because there are only 256 dynamic slots and N tints about 825 clips with the same colour.
- `render_attached_child` and the `tagRerenderFrame` root-attached pass pass that colour as `parent_cx` / `parent_cxform_id`.
- In `compose_children`, the attached-child branch (an attached clip that lives in its parent's `sprite_display_list`) used to build an **alpha-only** cxform. It now takes the full `mc->cx_*` tint as well.

Side effect: `_alpha` on a root-attached / standalone attached sprite clip now renders. Before, nothing read it. This is Flash-correct.

Fixture: `regression/avm1_attached_clip_color`. Root-attached grey squares:
- `a`: `setRGB(0x797A88)`.
- `p`: `setRGB(0xC08000)`, with an attached white child `k` that must take the tint too.
- `c`: untinted control.

The trace (`getRGB`) and the PNG are from the Ruffle exporter (`-s -f 3`, default quality).
- Graphics: trace PASS, image **0 outliers, max diff 0**. Before the fix, the image showed `a` and `p` raw grey and `k` white.
- No-graphics: PASS.

N's own case (attach into a `createEmptyMovieClip` buffer) can't be in a CI fixture, because the OFFSCREEN capture draws root-attached clips only. It is verified in the browser on N itself: the walls are blue-grey.

## 3. Bug 2: time bar hidden under the tiles

The time bar is `timeIndicator` (char 987). Its child `bar` (sprite 984) is a 101-frame morph-ratio animation of morph 982. It is attached into the GUI buffer `spritebuffer2100` at startup.

The probe showed the HUD state is correct in our build at pre-level: `_visible` true, `bar._xscale` 284, `txt` set. A copy attached in the menu rendered fine. In-game it sits at y=12 / y=580, on top of the border wall tiles.

- `tagShowFrame`'s browser post-loop pass draws every non-root attached clip in `child_mc_cache` order, which is creation order.
- The tiles (`spritebuffer1700`) are created at each level load, so they come after the startup GUI clips and painted over the HUD.
- Flash draws `_root`'s children by depth, and each subtree in depth order.

Fix (`tag.c`): `attached_sort_render_order`. It gathers the pass's clips and sorts them by depth path from the top of the chain: the level first, then each ancestor's depth, shorter path first, ties broken by cache order. It uses `qsort` over precomputed keys, about 1000 clips for N. It applies to both the `tagShowFrame` pass and the OFFSCREEN `tagRerenderFrame` root-attached pass, so CI capture and browser agree.

A one-shot dump of the sorted order in N confirmed buffers 1100 → 2900 in order, each buffer's children by depth, and nested `bar` / `txtbox` after their parent. After the fix the purple time bar shows at the top in pre-level.

## 4. Bug 3: HUD text never instantiated (fixed tables in `ng_shared.c`)

The probe in N (native and browser) showed `guiLevelNameMC` and `timeIndicator.txtbox` with `_width` 0 and **no** TextField child in for..in. Ruffle has `instance534` and the others, `w=288` / `96`.

An N-tag fixture (N's font 3, EditTexts 985/1026 and sprites 986/987/1027, spliced into a minimal SWF) rendered **pixel-exact** in our graphics build. So the failure needed N's state.

Instrumenting `ng_on_place_object2` showed the placement runs with the right context (`ctx=guiLevelNameMC1`) but skips the TextField-wrapper branch. `ng_find_textfield(1026)` was −1, because `ng_record_textfield_props` returns early once `MAX_TEXTFIELDS_NG` (64) is reached. 1026 is N's 197th EditText.

The same file had fixed tables, with the same silent drop, for:

| table | cap | N count |
|---|---|---|
| shape bounds (`MAX_CHAR_BOUNDS_NG`) | 256 | 291 shapes |
| morph end bounds | 64 | 86 morphs |
| shape paths | 256 | 291 shapes |
| morph paths | 64 | 86 morphs |
| winding ids | 64 | — |

Missing bounds and paths mean `_width` 0 and wrong hit tests for late characters. That is why N's `bar._width` read 0.

Fix: `ng_table_grow` (doubling `realloc`, zero-filled). All six registries are now heap arrays with a `*_cap`. Pointers returned into `ng_textfields` (variable name, text, CSM strings) are used only as call-local values. Growth happens only when define tags run, so `realloc` moving the table is safe.

Fixture: `regression/avm1_many_chars_registry`. It defines 70 EditTexts, 300 shapes and 70 morphs, and its sprites place the last of each. The trace covers `_width` / `_height`, `hitTest`, and the bound variable text through the auto-named child. The expected output is from the Ruffle exporter. It is trace-only, because device-font text in the exporter isn't comparable. PASS in no-graphics and graphics.

The other fixed caps in `ng_shared.c` were left alone: buttons 64, fonts 32, videos 32, sounds 128, exports 1024. N is under all of them (57 buttons, 5 fonts, 39 sounds). They are the next candidates if a game hits the same symptom.

## 5. Landing, CI, Pages

- Commit `be31edbfd`.
- **`ng_shared.c` collision:** the s25 coordinator was landing `w2-textfield-vn` (`4dd9d2865`) at the same time. It added a parallel array `ng_textfield_src_swf_version[MAX_TEXTFIELDS_NG]`, using the macro this slice removes. We resolved it by message: they committed their staged index first, and then I folded the version into the `ng_textfields` struct as a field. `ng_getTextFieldSrcSwfVersion`'s name and behaviour are unchanged, and gnash `TextField-v6` / `-v8` stay `ruffle_matched`.
- **Local checks:**
  - Both new fixtures PASS in graphics and no-graphics.
  - `avm1_dynclip_color_transform` and `avm1_attached_clip_hidden_capture` still match at 0 px.
  - `avm1_attach_clipevent_enterframe` PASS.
- **CI:** I dispatched none (per the brief). The coordinator folded `be31edbfd` into the s25 FINAL grading at `697669e5f` (my commit plus `w2-nearpass-land`): graphics full+images `45078991452` and no-graphics full `45079002150`. Both legs are needed because `ng_shared.c` is shared code. Expected moves:
  - images: root-attached tinted / `_alpha` sprites now render tinted;
  - images: root-attached clips are now drawn in depth order;
  - trace: only SWFs with more than 64 EditTexts, 256 shapes or 64 morphs change.
  - **Result (coordinator):** `regression/avm1_attached_clip_color` PASSES in both modes. There are 0 trace or pixel regressions corpus-wide. The only image-band move is `visual/filters/bevel` improving from 732 to 3 excess pixels (from `w2-nearpass-land`). The growable registries moved nothing else.
- **Pages (corrected after the coordinator's check):**
  - My dry run `45078593255` succeeded.
  - My real deploy `45078853881` was cancelled by the concurrency group.
  - `45079004983` (the coordinator's, at `697669e5f`) was ALSO a dry run, so its upload and deploy steps were skipped. **Nothing from this slice reached the live site during the session.** The coordinator then dispatched the real deploy `45081434401` (head `5a1d7b4e0`, which contains `be31edbfd`). It succeeded, and both its "Upload Pages artifact" and "Deploy to GitHub Pages" steps ran. Live re-verification of the in-browser recompiler on that deploy was not done in this session.
  - So my live in-browser recompiler runs exercised the OLDER deployed runtime. On it, `avm1_attached_clip_hidden_capture` traces match. `avm1_attached_clip_color` traces `getRGB` as `undefined` because of a **pre-existing browser gap**, read from source: `colorGetRGB`'s non-OFFSCREEN `#else` arm returns `undefined`, so setRGB writes but getRGB never reads the colour back. That is independent of this change and listed as a lead in §6.
  - N itself is in `docs2` (local only, not OSS), so I verified it on the local build of the same runtime (§6).

## 6. N after the fixes, and the next blocker

I drove (canvas-only screenshots) into episode 0, level 0, ran left and right with jumps, and collected gold. All of these now match Ruffle:
- walls `0x797A88`;
- the purple time bar filling at the top, with its seconds readout (`75.52` in pre-level, rising as gold is collected, `102.476`);
- "Episode 0 Level 0: the motherlode" at the bottom, staying visible in play, which is correct because N's `HideAll` doesn't hide it;
- the episode-select grid.

**Next slice's line:** play through a level end to end (exit-door switch, door opening, level-complete transition to level 1) and through a death/retry, comparing against Ruffle. Automation hasn't reached the exit yet, so whether level completion works is still unknown. Smaller leads:
1. Browser `Color.getRGB` / `getTransform` return `undefined` (`action.c` `colorGetRGB` / `colorGetTransform` `#else` arms). This is trace-visible in the browser only.
2. `ng_shared.c` still has fixed caps for buttons (64), fonts (32), videos (32), sounds (128) and exports (1024). A bigger game will hit them with the same silent-drop symptom.
3. Root-attached EditText fields with a **device** font: not checked.
