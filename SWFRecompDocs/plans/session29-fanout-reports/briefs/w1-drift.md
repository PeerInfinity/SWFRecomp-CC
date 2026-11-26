**Upstream drift `c2f7d24b7..origin/master` + the first flash_fixes STALE/UPSTREAMED check (S).**

Upstream Ruffle since the s28 drift slot (re-fetch at start and extend the range if newer commits landed):
`745653790` + `e7e02dbec` (new row `avm1/bitmapdata_palettemap_values`; avm1 keeps whole values from the paletteMap
channel arrays), `aa850487d` + `31e07df77` (new row `avm2/bitmapdata_palettemap_opaque`; paletteMap results stay opaque
in opaque bitmaps), `avm1/bitmap_data_thorough/paletteMap` loses `known_failure` and its 954-line `output.ruffle.txt`
(we already pass it), `9c6ab4945` (Rust-only JPEG test, no corpus row), plus core refactors
(`4d364fb25`, `579558eec`, `e6f9bd18d`, `bd626f491`: borrowed JPEG/lossless data, lazy JpegTables). Also check
`git diff --stat c2f7d24b7 origin/master -- tests/` for any other moved row (e.g. gnash
`misc-swfc.all/gotoFrameFromInterval/output.ruffle.txt` changed; `avm1/loadmovie_replace_root`,
`avm1/mouse_events_visible_enabled`, `avm2/filter_rewind`, the timer rows): confirm whether each is already in our
s28 FINAL results or is new/changed since its download.

Task:
1. For every row the range adds or changes: download the category, run it (graphics mode), and report status. For the
   two paletteMap rows: implement the rule if we fail (`SWFModernRuntime` BitmapData paletteMap, AVM1 and AVM2 arms;
   name the functions). Both rules must be checked against FLASH, not only Ruffle: if the golden is Ruffle-made (look at
   the upstream commit/PR for how `output.txt` was produced), write a FLASH trace request with the test SWF.
2. A changed `output.ruffle.txt` on a row we grade `ruffle_matched` (gotoFrameFromInterval) can move our status: price it.
3. Run `python3 ruffle-tests/apply_flash_fixes.py --check` after your download (all categories that have fixes:
   avm1, avm2, from_gnash, visual, from_shumway…) and report every STALE / UPSTREAMED line with the upstream commit
   that caused it. A STALE entry means upstream edited the file under our fix: diff the new upstream file against both
   our fix and the old upstream file, and say whether the fix still holds (re-pin) or must be re-derived against Flash.
Deliver the patch (new rows passing) or a NO-CHANGE report naming every upstream row in the range with its status.
Siblings: none touch BitmapData paletteMap.
