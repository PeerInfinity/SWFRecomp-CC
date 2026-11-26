# s29 w1-drift: upstream drift `c2f7d24b7..b7ff32d93` + first flash_fixes STALE/UPSTREAMED check

**New files:**
- `w1-drift-report.md` (this file)
- `w1-drift-prototype.patch`: `SWFModernRuntime/src/avm2/avm2_bitmap.c` only, 94 lines
- `w1-drift-fixtures/palettemap_avm2_index/{Test.as,build.sh}`: a FLASH probe, source only (no AS3 compiler in the cloud)

**Setup:** box `SETUP_STATUS` all OK (apt, Pillow, Dawn). Code at `origin/master` `aa36d43a` (= code `bfa47037b` + docs).
Downloaded `avm1 avm2 from_gnash visual from_shumway mixed_avm` from upstream master **`b7ff32d93`** (2026-11-26 23:42; the
only commit past the brief's `31e07df77` is `b7ff32d93` "extension: Disallow loading player.html in frames", which adds
no corpus rows). All runs below are `--mode=graphics` on lavapipe.

## Verdicts (lead)

| row | upstream cause | in s28 FINAL (`014124ed5`)? | status now (master) | with prototype |
|---|---|---|---|---|
| **`avm2/bitmapdata_palettemap_opaque`** (new) | `aa850487d` + `31e07df77` | absent (new) | **output_mismatch 7/9 lines** | **PASS** |
| `avm1/bitmapdata_palettemap_values` (new) | `745653790` + `e7e02dbec` | absent (new) | **PASS** | PASS (AVM1 not touched) |
| `avm1/bitmap_data_thorough/paletteMap` | `31e07df77` drops `known_failure` + `output.ruffle.txt`; `output.txt` unchanged | pass (951/951) | pass | pass |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | `72d054edd` rewrote `output.ruffle.txt` | rm, `diffs 18 ⊆ ruffle 30` | rm (18 ⊆ 30) | rm |
| `avm1/loadmovie_replace_root` | `07d4b9dbc` num_frames 3 → num_ticks 200, `output.txt` +1 line `Frame tick` | pass 6/6 (already graded on the new 6-line file) | pass | – |
| `avm1/mouse_events_visible_enabled` | `482a9a96c` num_frames 40 → num_ticks 40 | trace pass, image fail (3610 ch, pre-existing) | not re-run (toml-only rename; 40 = 40) | – |
| `avm1/timer_run_actions` | `72d054edd` num_ticks 1 → 10 | pass 18/18 | pass | – |
| `avm1/timer_tie_order`, `avm2/timer_tie_order`, `avm2/timer_checks_per_frame`, `avm2/timer_timeout_ids` | `2fa4e1e4c`, `6f0ac73ff`, `8f67ef815` | pass (56, 64, 6, 11 lines) | pass (the first three re-run) | – |
| `avm2/filter_rewind` | `72d054edd` num_ticks 2 → 10 | pass 8/8 | pass | – |
| `avm2/enter_frame_non_display_dispatcher` | `60aaf317e` | pass 23/23 | not re-run | – |
| `avm2/pixelbender_ordered_dither` | `0f1b6e360` | trace pass 16/16 + image pass (0 ch) | not re-run | – |
| `9c6ab4945` JPEG external-tables test; `4d364fb25` `579558eec` `e6f9bd18d` `bd626f491` | Rust-only test / core refactors | no corpus row | – | – |
| `d2a801a98`, `843671fa2` (num_frames removal; `external_interface`/`shared_object` Rust harness) | runner/Rust-only | no swfs row moved | – | – |

**Premise correction (rule 1):** the brief says the range is the paletteMap pair plus the JPEG refactors. Since
`c2f7d24b7` it actually also holds the **timer series** (`30cd66cba`..`6f0ac73ff`), the num_ticks migrations and
`pixelbender_ordered_dither` / `enter_frame_non_display_dispatcher`. **All of those were already in the s28 FINAL
download**: FINAL ran about 19:20–20:41 UTC on 11-26, after `6f0ac73ff` (11-25 23:43 UTC) and before `745653790`
(11-26 21:12 UTC). Every one is in `results_graphics.json` at `014124ed5` with the new line totals (e.g.
`loadmovie_replace_root` expected 6 = the new file). s28 `w3-new-timer-rows` already covered the timer rows.
**Only the two paletteMap rows are new to us.** No drift is booked as yield.

**Priced flip: +1 trace row, `avm2/bitmapdata_palettemap_opaque` new → pass** (new-row yield, not drift). The 4864 → 4866
row total moves by +2 new rows, both passing with the prototype: effective pass +2. Without the prototype it is +1 pass
and +1 fail. GO for wave 2 as a small patch (S), pending the FLASH capture below.

## 1. AVM2 `paletteMap` was a no-op

`SWFModernRuntime/src/avm2/avm2_bitmap.c:5417` (master) registered `paletteMap` as `bd_noop__mut`, so every case printed
the untouched dest `0xFF000000`:

```
-    1  transparent zero alpha sum: 0x00000000      +  0xFF000000
-    2  transparent half alpha sum: 0x80122234      +  0xFF000000
-    3  transparent full alpha sum: 0xFF112233      +  0xFF000000
-    4  transparent alpha only: 0x7F000000          +  0xFF000000
-  5-7  opaque {zero,half,full} alpha sum: 0xFF112233   +  0xFF000000
     8  opaque alpha only: 0xFF000000   (matched by accident)
```

**Prototype** (`w1-drift-prototype.patch`): new `static Avm2Value bd_palette_map(Avm2Activation*)` placed right
after `bd_copy_channel`, plus `BD_MUTATOR(bd_palette_map)`, with the registration switched to `bd_palette_map__mut`. It is a
port of Ruffle `operations.rs::palette_map` and of our AVM1 arm:
- source / rect / point read the same way as `bd_copy_channel` (`rect_to_xywh`, `read_point_i32`,
  `pr_clamp_intersection`);
- four 256-entry LUTs hold the **full 32-bit** `coerce_to_u32` entries. A null or non-object argument gives identity
  `i << shift`, and a hole reads as undefined, i.e. 0;
- per pixel: `unmul(src)`, wrap-add the four LUT entries, then `premul(sum, dst->transparency)`. An opaque target
  therefore keeps alpha 0xFF and writes the colour as is (the `31e07df77` rule). A transparent target premultiplies with
  the summed alpha byte. That is how `0x80112233` reads back as `0x80122234`: the round trip goes through the existing
  `premul`/`unmul` pair (`FLASH_PREMUL_FACTOR`), with no new rounding code.
- A same-bitmap call (`src == dst`) reads the live buffer pixel by pixel, like Ruffle's `source == None` arm.

**AVM1 arm** (`action.c::bitmapDataPaletteMap`, ~`action.c:14300-14420`) already had both rules: full 32-bit entries,
FP32-pinned by `avm1/bitmap_data_thorough/paletteMap` (s28 trace-provenance: golden = Flash), and `if
(!dest_bmp->transparent) sum |= 0xFF000000u`. That is why `bitmapdata_palettemap_values` passes on master. In the AVM1 arm,
`sum |= 0xFF000000` followed by `premultiplyAlpha` equals Ruffle's `to_premultiplied_alpha(false)`, so it was not
touched. **Functions touched: `avm2_bitmap.c::bd_palette_map` (new), the `BD_MUTATOR` list, and
`avm2_bitmap_register`'s `paletteMap` line.** None of the files the parallel ladders touch (`tag.c` / `action.c` /
`ng_shared.c` / `swf.c` / `render_webgpu.c`) is edited.

**Measured, prototype applied (graphics):** `avm2/bitmapdata_palettemap_opaque` PASS. Unchanged and passing:
- `avm1/bitmapdata_palettemap_values`, `avm1/bitmap_data_thorough/paletteMap`, `avm1/bitmap_data`
- `avm2/all_classes/display/swf9` (describeType lists paletteMap)
- regression `avm2_bitmapdata_draw_edittext_box` and `avm2_bitmapdata_draw_filtered`

`from_gnash/actionscript.all/BitmapData-v8` stays rm (8 ⊆ 8), the same as FINAL.

**Blast radius:** I scanned every downloaded SWF, decompressed (`avm1 avm2 from_gnash visual from_shumway
mixed_avm`), for the `paletteMap` string. AVM2 callers: only `avm2/bitmapdata_palettemap_opaque` (plus the
`all_classes/display/*` describeType rows, which print the signature only). AVM1 callers (untouched code):
`avm1/bitmap_data`, `bitmap_data_thorough/paletteMap`, `bitmapdata_palettemap_values`, gnash `BitmapData-v8`. I did not
scan `from_avmplus` (Tamarin ecma/as3/e4x acceptance; it has no flash.display) or the misc small categories other than
`visual`/`mixed_avm`. The wave-2 worker should run `categories=all` graphics; `full` is not needed because no recompiler
emission is involved.

**Not replicated (RvF candidate, needs FLASH):** Ruffle's AVM2 arm reads `arg.get_enumerant_value(i)`. For an
`ArrayObject` that is the enumerant name `i-1` (`array_object.rs:249-266`: `index.checked_sub(1)`, so `i == 0` reads
the property `"null"`, i.e. undefined, i.e. 0). **Ruffle's AVM2 paletteMap is therefore off by one: `lut[i] = arr[i-1]`.**
The corpus row can't see this (all 256 entries are equal, and index 0 is never sampled). The AVM1 arm and the docs say
`arr[i]`. The prototype reads `arr[i]`. The FLASH probe below decides it. If FP32 says `arr[i]`, add an RvF entry. If it
says `arr[i-1]`, which is very unlikely, flip one line. The params are typed `Array`, so Vector/Object args coerce-throw
before the call. The prototype's non-Array fallback (`avm2_get_public_property(i)`) is defensive only.

## 2. Golden provenance of the two new rows

Both goldens came in through a Claude-assisted upstream PR ("Assisted-by: Claude Code"). Both commits shipped
`output.txt` together with a differing `output.ruffle.txt` + `known_failure`, and the follow-up core commit deleted
`output.ruffle.txt` once Ruffle matched. So `output.txt` was **not** produced by the Ruffle of the time. The commit
messages state the Flash behaviour ("Flash Player keeps them opaque and writes the color as is"; "Flash Player adds up
the full 32-bit values"), but nothing in the repo proves a real FP capture. The AVM1 full-32-bit rule is independently
FP32-confirmed (s28 trace-provenance row `avm1/bitmap_data_thorough/paletteMap`: golden = Flash, and that golden's
`0xff0004a9` opaque-alpha case is the opaque rule too). The AVM2 opaque rule and the 0x80 premul round trip are not
independently confirmed. **FLASH requests below**: grade against FP32, and a mismatch is a `flash_fixes` candidate.

## 3. `gotoFrameFromInterval` changed `output.ruffle.txt`: priced, no movement

`72d054edd` changed 16 lines of the gnash Ruffle file (Ruffle's per-interval `asOrder` strings got shorter: timers
now run at most once each per update). FINAL already graded against the new file. I also re-graded our actual output
offline with `verify_output.ruffle_subset_match` against both versions: **new `(True, 18, 30)`, old (`c2f7d24b7`)
`(True, 18, 30)`**. Our 18 diff lines are a subset under either file, so the change is a 0-row move. The golden is Flash
(s28 trace-provenance line 291), so the row is a real 18-line gap. It is owned by the timer floor lead
(`w1b-rm-gnash` B20g; arc §28: 10 ms floor), not by drift.

## 4. flash_fixes `--check` after download: 0 STALE, 0 UPSTREAMED

`python3 ruffle-tests/apply_flash_fixes.py --check` after downloading avm1, avm2, from_gnash and visual (every suite
that has entries; `from_shumway` has none) prints `ALREADY` for **all 62 entries**. The download itself printed
`flash-fixes: APPLIED 62`. That means **no STALE line and no UPSTREAMED line**. Nothing in `c2f7d24b7..b7ff32d93`
touches a file under a fix: the range's `tests/` stat lists no fixed path. Every fix holds as pinned, so no re-pin and
no Flash re-derivation is needed.

## Refutations / attacks on my own pricing

- "The paletteMap pair is the only drift": refuted. ~20 more commits are in the range, but all were graded in FINAL (above).
- "`bitmap_data_thorough/paletteMap` losing `known_failure` can move us": no. We pass it outright (951/951), so the
  rm fallback was never in play.
- "AVM2 paletteMap is a pixel-axis lead too": no image row calls it (scan above).
- "Ruffle's AVM2 arm is the spec": refuted on reading. It has an off-by-one we deliberately don't copy (Flash probe).

## New unclaimed leads

1. **Stale status doc:** `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md:214` and `:360` still say
   `bitmap_data_thorough/paletteMap` is rm with "mask each LUT entry `& 0xFF`". The code dropped the mask (FP32) and the
   row passes. It is a doc fix for whoever owns that file.
2. **Other AVM2 BitmapData no-ops:** `merge` and `perlinNoise` are still `bd_noop__mut` (`avm2_bitmap.c`, the same
   block). In the same string scan (avm2, visual, mixed_avm, from_shumway), **`perlinNoise`** appears only in
   `avm2/away3d_advanced_shallow_water_demo`. That row is trace pass (0 lines) and image fail in FINAL, so it is at most
   a pixel lead inside a large 3D demo, with low odds. **`merge`** is too common a substring: it matched 20+ unrelated
   SWFs. Pricing it needs an ABC-level scan for a `callproperty merge` on a BitmapData receiver. Unpriced.

## LOCAL ORACLE REQUESTS

1. **FLASH: `avm2/bitmapdata_palettemap_opaque` (corpus SWF), trace, `num_ticks = 1`, AVM2 (the wrapper is fine for
   AVM2).** Compare against `output.txt` (9 lines). Key lines: `transparent half alpha sum: 0x80122234` (premul round
   trip) and the three `opaque … 0xFF112233` lines. A mismatch is a flash_fixes candidate.
2. **FLASH: `avm1/bitmapdata_palettemap_values` (corpus SWF, SWF8 Rascal), trace, direct mode pinned, 1 tick.** Compare
   against `output.txt` (19 lines). We pass the Ruffle golden; this checks the golden itself (holes, short arrays,
   strings, `red plain object with indices`, `all ones` → `0xFFFFFFFE`).
3. **FLASH: `session29-fanout-reports/w1-drift-fixtures/palettemap_avm2_index/` (build `./build.sh`, mxmlc, SWF15),
   trace, 1 frame.** Decides AVM2 `arr[i]` (our prototype) vs Ruffle's `arr[i-1]`. Predictions per line:

   | line | `arr[i]` (prototype) | Ruffle `arr[i-1]` |
   |---|---|---|
   | `identity arrays opaque` | `0xFF102030` | `0xFF0F1F2F` |
   | `index zero transparent` | `0xFFAA0000` | `0xFE000000` |
   | `identity arrays transparent half` | round trip of `0x80102030` | shifted |
   | `null red, identity rest opaque` | `0xFF102030` | `0xFF101F2F` |
   | `Done` | | |

   If Flash prints the `arr[i]` column: add an RvF entry (Ruffle AVM2 paletteMap off by one) and add this fixture as
   `regression/avm2_bitmapdata_palettemap_index` with the FP32 output as its golden.
