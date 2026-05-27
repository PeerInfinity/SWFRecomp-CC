# 2026-05-27 — Snake title text + DefineText X/Y offset bit swap

Follow-up to the Doodle Jump button-text-centered handoff (`ac54a1679` / `0c4b4a38a`).

**This handoff covers commit `1fbbdb85d`.**

## TL;DR

- **Root cause:** SWFRecomp's DefineText TEXTRECORD parser had the `StyleFlagsHasXOffset` and `StyleFlagsHasYOffset` bits **swapped** at `swf.cpp:2665-2666`. Per SWF File Format Spec §11.3 the flag byte bits are (high→low): reserved×4, HasFont, HasColor, HasYOffset (bit 1), HasXOffset (bit 0). The recompiler read bit 1 as `has_x_offset` and bit 0 as `has_y_offset`.
- **Bug manifests** only when exactly one of X / Y is set in the SWF:
  - Both set → reads two SI16 fields in X-then-Y order (matches SWF order). Both values land in the correct slots. ✓
  - Neither set → no fields read. ✓
  - Only Y set (Snake's "SNAKE" record: `flag=0x8e`, Y_OFFSET=1108) → the recompiler thinks "only X" is set, reads the single SI16 (which is actually Y_OFFSET=1108) into `x_offset`, then `temp_matrix.translate_x += 1108`. translate_y stays 0. Per-glyph transforms end up with `tx=advance+1108`, `ty=0` — Y shift dropped entirely.
  - Only X set → symmetric: X value lands in `y_offset`.
- **Fix:** swap the two bits at lines 2665-2666. The field data ORDER (`configureNextField` for X before Y) was already correct.
- **Visible result:** Snake title screen now renders correctly. Before: "SNAKE" cut off above canvas top, "SLUG WORM PYTHON" overflowing right edge. After: pixel-aligned to Ruffle reference. Per-glyph transforms for char 8 now correctly have `tx=0..2704` (advancing X), `ty=1108` (Y_OFFSET = baseline position below top of bounds).

## How the diagnostic chain worked

1.  **User report:** "Snake title screen, all of the text is appearing up and to the right of where it should be."
2.  **Capture our render + Ruffle reference** via `~/CC/ruffle/target/release/exporter --frames 30`. Confirmed:
    - Ruffle: "SNAKE" at top center, "CHOOSE LEVEL:" below, "SLUG WORM PYTHON" middle, "www.neave.com/webgames" footer.
    - Our render: "SNAKE" mostly clipped (only descenders visible at canvas y=0-25), "CHOOSE LEVEL:" shifted right and up, "SLUG WORM PYTHON" running off right edge, footer invisible.
    - Letter sizes identical → translation issue, not scale.
3.  **Confirm pre-existing** (not caused by the previous handoff's `ac54a1679` fix): checked out HEAD~2 of `action.c`, rebuilt Snake, screenshot matched current output exactly. Restored HEAD.
4.  **Inspect recompiled output.** `tagDefineText(app_context, 8, ..., transform_start=42, ..., 66, 3971, 84, 1121)` for "SNAKE". Per-glyph transforms 42-46 had `scale=1.25, tx ∈ {1108, 1784, 2460, 3136, 3812}, ty=0`. Advance per glyph = 676 twips.
5.  **Spot the suspicious value:** `tx=1108` for the first glyph but bounds say `xmin=66`. If 1108 were a real X_OFFSET it'd shift glyphs ~+50px right; if it were Y_OFFSET it'd put the baseline 55px below text top (right where Ruffle puts it). The number screamed "this is in the wrong column."
6.  **Parse the raw SWF** with a one-off Python script (`/tmp/parse_swf_text.py`). Output:
    ```
    DefineText char_id=8 ... matrix=(65536, 65536, 0, 0, 0, 0)
      rec[0] font=2 color=(0,0,0) x_off=None y_off=1108 height=1280 glyph_count=5
    ```
    The SWF stores Y_OFFSET=1108, X_OFFSET=None. The recompiler emitted that 1108 into the X column. Bug confirmed.
7.  **Read the SWF flag byte** (`/tmp/parse_swf_flags.py`): `flag=0x8e = 0b10001110` → bit 1=1 (HasYOffset), bit 0=0 (HasXOffset). Recompiler at `swf.cpp:2665` reads `bool has_x_offset = (flags & 0b0010)` → reads bit 1 as X. Bits swapped vs spec.
8.  **Fix:** swap the two bit assignments. Rebuild SWFRecomp, re-recompile Snake with `--clean`, rebuild wasm. Per-glyph transforms now show `tx=0, ty=1108` for the first glyph, advancing X correctly for subsequent glyphs.
9.  **Visual confirmation:** Snake title screen pixel-matches Ruffle.

## Why no other tests regressed

The bug was inert in three of four cases:
- **Neither X nor Y set:** no field reads, no translation accumulation. No bug regardless of bit interpretation.
- **Both set:** flags read swapped, but the byte stream contains two SI16 fields in X-then-Y order. `configureNextField` is called twice (once for each "set" flag) and the values land in `tag.fields[0]` and `tag.fields[1]` in stream order. The recompiler then assigns:
  - `x_offset = fields[current_field++]` (gets the first stream field — actual X_OFFSET)
  - `y_offset = fields[current_field++]` (gets the second stream field — actual Y_OFFSET)
  By a coincidence of read-order vs flag-interpretation symmetry, both-set ends up correct.
- **Only X set** or **only Y set:** the conditional `if (has_x_offset)` etc. fires for the wrong axis, and the single SI16 in the stream gets misrouted.

Most static text in test SWFs falls into "neither" or "both" — that's why this bug survived this long without other reports. Snake's title is one of the few SWFs in our test set that uses Y_OFFSET alone (used to position the baseline below the text bounding box's top edge).

DJ's static text didn't regress because DJ's static fields are double-emitted as DefineEditText with the dynamic glyph render path (which computes baseline from font metrics, not from per-glyph transform ty). The dynamic path was always correct; only static-only DefineText (chars without `tagDefineEditTextProps`) exposed the bug.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`swf.cpp:2666-2670` DefineText TEXTRECORD style flag bits.** Per SWF File Format Spec §11.3, bit 1 = `StyleFlagsHasYOffset`, bit 0 = `StyleFlagsHasXOffset`. **Do NOT** flip these back to the pre-fix ordering — that re-introduces the Snake title-text bug. The `configureNextField` and `tag.fields[current_field++]` read order below already matches the SWF byte stream (X-before-Y), so only the bit interpretation needed swapping.

## Baselines after fix

- Trace divergence: 407=407 (DJ).
- DJ menu (no click, 8s): dl=9 stable, 8 unique canvases, 0 errors.
- DJ Info click: info sub-screen renders correctly with centered "back" button.
- DJ play-click: hero bounces continuously, score climbs (sustained bouncing fix from `11f66a345` preserved).
- Snake (8s): dl=16 stable, 8 ok canvases, 0 errors. Title screen text positioned correctly.
- Pong: dl=3 stable, 0 errors. Preloader render matches Ruffle (the hand-drawn "Loading" + "GlaielGames.com" text is intentionally messy in both renders). Note: probe sometimes hits a Playwright screenshot timeout for frames 2+ on Pong — pre-existing and unrelated to this fix.

## Tools / state

- Status: 1 unpushed commit ahead of origin/master (`1fbbdb85d` + 2 prior unpushed: `ac54a1679`, `0c4b4a38a`).
- Probes used:
  - `/tmp/snake-shot.py` — visible (headed) Snake screenshot.
  - `/tmp/parse_swf_text.py` — parse SWF DefineText records (bounds, glyph_bits, advance_bits, per-record flags + X_OFFSET / Y_OFFSET / height).
  - `/tmp/parse_swf_flags.py` — raw flag-byte dump for a given char_id with explicit bit breakdown.
  - `/tmp/dj-menu-shot.py`, `/tmp/dj-click-test.py`, `/tmp/dj-play-probe.py` — DJ menu / click / play probes (carried forward from prior handoff).
- The recompiler must be rebuilt (`cd SWFRecomp/build && make`) and tests re-recompiled with `--clean` to pick up parser changes; deploy_example.sh is fine without rebuild because it copies pre-built outputs.

Push when ready.
