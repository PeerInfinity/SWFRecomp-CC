# 2026-05-27 — Snake countdown 2/1 misplacement + GAMEOVER wrap

Follow-up to the DJ stuck-back-label handoff (`e5b50f2bc` / `cc3966823`).

## TL;DR

Three Snake gameplay bugs investigated. Two fixed; one diagnosed but left as a known limitation (separate handoff worthy of its own session).

- **Bug A (FIXED, runtime):** Countdown "3" centered correctly, but "2" and "1" jumped to canvas origin (0, 0). Cause: `tagPlaceObject2` clobbers the existing transform_id to identity on a Move=1+HasCharacter=1 REPLACE when the SWF tag has no HasMatrix. Recompiler emits `transform_id=0` as the "no HasMatrix" sentinel (swf.cpp:3478-3480). Per Ruffle's `apply_place_object`, matrix is only written when HasMatrix=true. Gate the assignment so cross-frame REPLACE with `transform_id=0` preserves the prior transform_id (and skips `ng_cache_transform`).

- **Bug B (NOT FIXED, documented):** Game field invisible during play. Snake creates segments via `duplicateMovieClip` (AVM1 opcode 0x24 / `actionCloneSprite`). The full clone implementation (`ng_cloneSprite` + `ng_cloneSpriteFromMC` + `child_mc_cache` integration, plus clip-event dispatch / sprite-init phasing) only exists in tag_stubs.c — used by NO_GRAPHICS and OFFSCREEN_RENDER builds. In browser-WASM graphics, `actionCloneSprite` calls a `cloneMovieClip` stub at action.c:20144 that silently no-ops. Snake's gameplay logic still ticks (so it eventually goes out-of-bounds and reaches game-over) but no snake segments are placed. Fix requires porting the tag_stubs.c clone primitives to browser-WASM tag.c — substantial new feature.

- **Bug C (FIXED, recompiler):** "GAMEOVER" wrapped as "GAMEO" / "VER" — mid-word break. Cause: the recompiler emits `glyph_count + 1` transforms per text record (one pre-advance position, then one POST-advance per loop iteration). The trailing post-advance entry is unused for single-record DefineText but collides with the first glyph of the next record when `tagDefineText` accumulates multi-record texts (it tracks total `text_size` but only the first record's `transform_start`). Snake's "GAMEOVER" is two records ("GAME" at y=1108, "OVER" at y=2512); the trailing transform 174 of record 1 (tx=2706, ty=1108) became the position of record 2's first glyph "O", shifting all of record 2 left by one column and dropping the last glyph onto the next line. Restructure both the DefineText loop (swf.cpp:2814-2838) and the EditText static-double-emit loop (swf.cpp:3038-3063) to emit exactly `glyph_count` transforms, one per glyph at its pre-advance position.

## How the diagnostic chain worked

### Bug C verification first (was-this-a-regression check)

1. Checked out `7bb0ec869` (just before the font-registration fix `028149055`), rebuilt Snake `--clean`, click-through to game-over, screenshot. **All three bugs present pre-fix.** So none are regressions from the recent font / URL / MC-invalidate work — all three pre-exist the last two sessions' changes. Restored master.

### Bug A diagnostic chain

2. **Reproduce.** `/tmp/snake-play2.py` clicks the slug button (stage 45, 208 → canvas pixel via bounding-box math) using `hover` + explicit `mouse.down()/up()` (a `page.mouse.click` at the same coords was being swallowed by the button's OVER-state animation without firing the click action). Snapshots every 0.5s for 30s. Shots show "3" centered, "2" / "1" at top-left, "GO!" centered.

3. **Trace placement.** Frame_3 click → button_13_action_4 (`script_4.c`) sets `level=1` / `levName="SLUG"` / `actionPlay()`. Timeline advances to frame_4 which removes title elements and places char 18 at depth 2 (transform 131 = tx=2860, ty=2518 → ~canvas center for a 320×320 stage). Frame_16 then runs `tagPlaceObject2(app_context, 2, 19, 0, 0, 0, 1)` — REPLACE depth 2's char_id 18 with char_id 19 (the "2" DefineText), `transform_id=0`, `is_replace=1`. Frame_29 same pattern for char_id 20 ("1").

4. **Recompiler check.** `swf.cpp:3478-3480`: when a SWF PlaceObject2 tag has `HasMatrix=false`, the recompiler emits `transform_id = 0`. Always. So 0 is the documented "no matrix specified" sentinel.

5. **Runtime check.** `tagPlaceObject2` at line ~5780 (post-flag-checks, fresh-or-cross-frame placement) unconditionally writes `display_list[depth].transform_id = transform_id` and calls `ng_cache_transform`. For cross-frame REPLACE with `transform_id=0`, this clobbers the prior transform_id to identity (slot 0 = transform_data[0] = identity matrix). Result: chars 19/20 render at (0, 0) instead of inheriting frame_4's transform 131. Ruffle's `apply_place_object` (display_object.rs) only writes the matrix when HasMatrix is true on the place-object record — that's the behavior we should mirror.

6. **Fix.** Gate the assignment on `!(is_replace && transform_id == 0 && is_cross_frame_replace)`. `is_cross_frame_replace` was already computed upstream (line 5762) as `display_list[depth].char_id != 0 && place_gen != g_place_gen` — exactly the condition where preserving the prior transform is correct. Fresh placements (slot was empty before line 5780) are unaffected because the existing `transform_id` was already 0 there. Within-same-frame REPLACE (an unusual case) is left alone — those go through the same-frame path at lines 5724-5750 with a slightly different gate, and Snake doesn't exercise it.

### Bug C diagnostic chain

7. **Inspect rendered output.** GAMEOVER shows 5 glyphs on line 1 ("GAMEO"), 3 on line 2 ("VER"). Total 8 glyphs = `len("GAMEOVER")`. So the renderer is reading all 8 glyphs but positioning them wrong.

8. **Parse the raw SWF.** `/tmp/parse_snake_text.py` (one-shot SWF DefineText parser) on Snake.swf char_id 32 prints:

    ```
    DefineText char_id=32
      rec[0] flags=8f font=2 x_off=2 y_off=1108 height=1280 glyph_count=4
        glyphs (idx,adv): [(20, 676), (14, 676), (26, 676), (18, 676)]   # GAME
      rec[1] flags=83 x_off=2 y_off=2512 glyph_count=4
        glyphs (idx,adv): [(28, 676), (35, 676), (18, 676), (31, 676)]   # OVER
    ```

    So the SWF source has GAMEOVER intentionally split across two y-offsets — line 1 (y=1108) "GAME", line 2 (y=2512) "OVER". The "GAMEO / VER" output is wrong; "GAME / OVER" is the intended layout.

9. **Inspect recompiled transforms.** `RecompiledTags/draws.c` transform_data slice:

    ```
    transform 170: tx=2,    ty=1108      # G (rec 1, glyph 0)
    transform 171: tx=678,  ty=1108      # A
    transform 172: tx=1354, ty=1108      # M
    transform 173: tx=2030, ty=1108      # E
    transform 174: tx=2706, ty=1108      # (trailing post-advance, unused)
    transform 175: tx=2,    ty=2512      # O (rec 2, glyph 0)
    transform 176: tx=678,  ty=2512      # V
    transform 177: tx=1354, ty=2512      # E
    transform 178: tx=2030, ty=2512      # R
    transform 179: tx=2706, ty=2512      # (trailing post-advance, unused)
    ```

    Each record emits **5 transforms** for **4 glyphs** — one extra per record. The recompiler at `swf.cpp:2814-2838` writes one `recompileMatrix` BEFORE the loop (the first glyph's position) then one inside each iteration AFTER `temp_matrix.translate_x += advance` (the next glyph's start position). Total = `glyph_count + 1`. The final iteration's post-advance write is unused.

10. **Why this breaks multi-record.** `tagDefineText` (tag.c:4707-4715) accumulates a multi-record DefineText by extending `text_size` to span both records but storing only the first record's `transform_start`. The renderer walks glyphs `[transform_start, transform_start + text_size)` assuming the transform indices are contiguous. With `glyph_count + 1` per record, record 2 effectively starts at `transform_start + glyph_count + 1`, but the renderer expects it at `transform_start + glyph_count`. So record 2's first glyph "O" reads transform 174 (record 1's trailing entry: tx=2706, ty=1108) instead of transform 175 (tx=2, ty=2512). Each subsequent glyph in record 2 is also off by one — V reads 175, E reads 176, R reads 177 — and the renderer never reaches transform 178 (which would be R's correct position). The unused trailing 179 stays unused.

11. **Why this didn't surface earlier.** Single-record DefineText is the common case (DJ static text, Snake's "SNAKE" title, "CHOOSE LEVEL:", "SLUG WORM PYTHON", "SCORE:", "LEVEL:", etc.). In single-record, the renderer reads exactly `glyph_count` transforms and the unused trailing entry is dead data. Multi-record DefineText only appears when the original Flash author placed multiple lines of static text inside a single DefineText — and the only test SWF we've exercised that does this with multiple records on different y-offsets is Snake's GAMEOVER (and possibly some local_batch SWFs we haven't visually validated). DJ uses DefineEditText for everything, which has a different render path (TextFieldGlyphRun layout in `actionIterateTextFieldGlyphs`), not the static glyph transform array.

12. **Fix.** Restructure both DefineText recompiler loops:
    - DefineText (`swf.cpp:2814-2838`): remove the pre-loop `recompileMatrix` + increment, move the in-loop `recompileMatrix` to BEFORE the `temp_matrix.translate_x += advance` line. Net: one transform per glyph at its pre-advance position.
    - EditText static double-emit (`swf.cpp:3038-3063`): same restructure.

    Subsequent transform indices in the same SWF shift down by one per text record, but the recompiler emits the indices consistently in `tagDefineText(...)` calls, so the runtime sees aligned data.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`tagPlaceObject2` preserves transform on cross-frame REPLACE without HasMatrix** (`SWFModernRuntime/src/libswf/tag.c:~5780`). The gate `!(is_replace && transform_id == 0 && is_cross_frame_replace)` skips the unconditional `transform_id = transform_id` + `ng_cache_transform` write. The recompiler emits `transform_id=0` as the "SWF tag had no HasMatrix" sentinel (`SWFRecomp/src/swf.cpp:3478-3480`); Ruffle's `apply_place_object` only writes the matrix when HasMatrix is true. **Do NOT** remove the gate — without it, every Move=1+HasCharacter=1 re-place that doesn't specify a new matrix snaps the entry to canvas origin (Snake countdown frame_16/29).

- **Recompiler emits exactly `glyph_count` transforms per DefineText record** (`SWFRecomp/src/swf.cpp:~2817-2838` and `~3042-3063`). One `recompileMatrix` per loop iteration, at the pre-advance position, then accumulate the advance. **Do NOT** re-add a pre-loop emit or move the emit to after `temp_matrix.translate_x += advance` — that re-introduces the trailing transform that breaks multi-record DefineText (Snake's "GAMEOVER" wraps as "GAMEO/VER").

## Known limitations carried forward (NEW)

- **`cloneMovieClip` (browser-WASM graphics) is a stub** (`SWFModernRuntime/src/actionmodern/action.c:20144`). `actionCloneSprite` (AVM1 opcode 0x24, `duplicateMovieClip`) silently no-ops in the default `--mode=graphics` browser build. NO_GRAPHICS and OFFSCREEN_RENDER both use the full `ng_cloneSprite` / `ng_cloneSpriteFromMC` implementation from `SWFModernRuntime/src/libswf/tag_stubs.c:2016+`, which integrates with `child_mc_cache`, sprite frame_0 replay, clip-action LOAD/CONSTRUCT dispatch, and the survives-rewind protection in `tagPlaceObject2` (via `clone_replaced` flag). Porting requires either (a) lifting the relevant block out of tag_stubs.c into a shared compilation unit, or (b) adding a thin browser-WASM clone primitive that reuses the same data structures. Either path is a self-contained feature project — leave as a known gap for now. Affects: Snake gameplay (no snake segments rendered, "the snake moves and eats food and eventually dies" off-screen). Any other graphics-WASM SWF that uses `duplicateMovieClip` would be similarly invisible (not an issue for DJ which uses `attachMovie`).

## Baselines after fix

- Trace divergence (DJ): 407=407.
- DJ menu (no click): dl=9 stable, 8 unique canvases, 0 errors. Button labels centered.
- DJ Info click: sub-screen renders; "mushroom: inverse control" not truncated.
- DJ Options → back round-trip: menu renders clean (no stuck "back" label).
- Snake title (no click): "SNAKE" centered at top, "CHOOSE LEVEL:" + "SLUG WORM PYTHON" + URL positioned correctly.
- Snake countdown (click slug): "3" centered, "2" centered, "1" centered, "GO!" centered. Game proceeds to gameplay (still no snake segments — Bug B) then game-over.
- Snake game-over: "GAME" / "OVER" on two lines (not "GAMEO/VER"). SCORE / LEVEL bottom labels intact.
- Snake probe.py flasharchive/Snake: dl=16 stable, 8 ok canvases, 0 errors.
- Pong: dl=3 stable, 0 errors.

## Tools / state

- Status: 2 unpushed commits expected (one runtime fix, one recompiler fix) plus this docs handoff (3 commits total).
- Probes added during diagnosis (all in `/tmp`, none committed):
  - `/tmp/snake-play2.py` — hover + mouse.down/up at slug button + 30s of half-second screenshots. Use this instead of `mouse.click` (the click can be eaten by the button's OVER-state sprite animation).
  - `/tmp/parse_snake_text.py` — SWF DefineText parser; lists per-record flags, font, x_off / y_off, height, glyph indices and advances. Reusable for any tagged char in any SWF.
- Recompiler rebuild required for the swf.cpp change: `cd SWFRecomp/build && make`, then re-recompile all tests `--clean` to pick up the new transform layout. Tests deployed individually via `build_test.sh` + `deploy_example.sh`.

Push when ready.
