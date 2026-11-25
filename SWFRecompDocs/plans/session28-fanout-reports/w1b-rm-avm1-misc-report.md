# s28 w1b-rm-avm1-misc: hidden Flash gaps behind `ruffle_matched` (avm1 / shumway / timeline / swf / fonts / visual)

Wave 1 (diagnosis + measured prototype). Cloud worker, graphics mode on lavapipe, `origin/master` `a85e0122`.
Corpus downloaded at upstream Ruffle **`d2a801a98`** (2026-11-25 20:06 +01; includes the `num_frames` → `num_ticks`
migration `07d4b9dbc..d2a801a98` on top of `c2f7d24b7`; `verify_output.py` already reads `num_ticks`).

**New files**
- `w1b-rm-avm1-misc-report.md` (this file)
- `w1b-rm-avm1-misc-prototype.patch` (`git diff origin/master -- SWFModernRuntime ruffle-tests/verify_output.py`)
- `w1b-rm-avm1-misc-fixtures/export_timing/{build.py,probe_stop.swf,probe_play.swf}` (Flash probe, see LOCAL ORACLE REQUESTS)

## Verdicts (lead)

**GO — prototype measured: 14 `ruffle_matched → pass` flips in scope (+1 gnash bonus), plus 2 zero-code flash_fixes.**
Every flip is a row whose golden is Linux FP32 (trace-provenance table A), measured in `--mode=graphics`; AVM1 runtime
rows also re-measured in no-graphics (§Measurements). Gates: 57 load/MCL/version rows, 44 BitmapData rows, 16
addProperty/watch rows, 10 gnash rows, 70 `regression/` rows + 7 ASnative rows: **no pass→non-pass anywhere**.

| bucket (owner mechanism) | size | rows flipped (measured) | owner |
|---|---|---|---|
| B1 function SWF-version follows the base clip's CURRENT movie | S | `mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6` | `action.c` `switchToFunctionVersion` |
| B2 SWF5 hides `TextField.prototype` | S | `textfield_props_swf5` (+ bonus `from_gnash/actionscript.all/TextField-v5`, owned by w1b-rm-gnash) | `action.c` `actionGetMemberImpl` FUNCTION/"prototype" arm |
| B3 truncated root SWF never finishes loading | S | `swf/swf_length_too_long`, `swf/lzma_length_too_long` | `verify_output.py` (`SWF_BYTES_LOADED`), `action.c` getBytesLoaded arm of `actionCallMethod`, `swf.c`/`swf_core.c` main loop |
| B4 SWF6 addProperty busy flag is per property (getter+setter shared) | S | `virtual_property_recursion_swf6` | `action.c` `virtualAccessorBlocked` |
| B5 form loader: Flash's lenient UTF-8 read | S | `form_loader_encoding_4` | `action.c` new `formFlashLenientUtf8`, `avm1LoadFormIntoMC` |
| B6 BitmapData result plumbing / Flash pixel arithmetic | S–M | `bitmapdata_custom_rectangle`, `bitmap_data_thorough/paletteMap`, `bitmap_data_thorough/perlinNoise`, `bitmap_data_thorough/copyPixels` | `action.c` `bitmapDataGenerateFilterRect`, `constructGeomRectDynamic`, `bitmapDataPaletteMap`, `perlin_turbulence` + `bitmapDataPerlinNoise`, `bitmapDataCopyPixels` |
| B7 ASnative: every minor of an existing major is a function | S | `asnative_sweep` | `action.c` `builtin_asnative` (+ `asnativeFlashMajorExists`, `asnativeUnknownMinor`) |
| B8 golden lost FP32's trailing spaces (no code) | S | `watch_recursion_swf6`, `watch_recursion_double_swf6` | **flash_fixes candidate** (our output is byte-identical to the archived FP32 capture) |

**NO-GO / HOLD (priced, completion mechanism named)** — 21 rows; table in §Rows. In short:
- `load_cancel_via_unloadclip`, `load_cancel_via_unloadmovie` — M, HOLD: unload must cancel a pending load on the
  same target (MCL still fires `onLoadStart`). Touches `actionFirePendingDirectLoadsImpl`/the MCL drain, which
  **w2-avm1-leads-land owns** this wave → land after it.
- `attach_movie_export_not_yet_run` — M, HOLD on a Flash probe (built): is an export registered by playhead or by parser?
- `tab_ordering_properties_tab_index_edge_case` — S once decided; HOLD on a Flash run of `tab_ordering_properties`
  (the ACCEPTED_DIFFS "conflicting expectations" claim is half-stale: the edge golden IS FP32).
- `target_paths/swf5`, `target_paths/swf6` — L, NO-GO: 36 debug-player diagnostic lines each + slash/dot path
  semantics on variable targets.
- `asnative_instrument` — L, NO-GO (soft: Windows FP32): real dispatch for the NetConnection/NetStream native tables.
- 16 AVM2 rows (shumway/timeline/fonts/visual) — all M/L; mechanisms below; none is an AVM1-misc S bucket.

**Rows other slots own (listed, not worked):** `from_shumway/acid/*` images → w1-acid-flash (the three acid TRACE rows
`acid-shapes-testing`, `acid-text-x`, `acid-textfield` are in my table below, unworked). `place_object_test*`,
`path_format_test`, `action_order/*`, `test10`, `test12`, `movieclip_hittest_shapeflag` are not in my suites.

## Stale dispositions (by name)

1. `ACCEPTED_DIFFS.md` summary rows `mcl_replace_root_swf7_to_swf5` / `_swf6` ("Ruffle vs Flash (SWF7 undefined
   concatenation) … our `"" + undefined` = `"undefined"` is correct per Flash") — **STALE**: FP32 prints the golden
   (`rest=`). Also stale: the RvF section "MCL Callback Unset Parameter Concatenation in SWF7" (it asserts our
   `rest=undefined` is Flash), and the `ruffle-tests/ignored_tests.txt` "Permanently accepted diffs" entries for both.
2. `RUFFLE_COMPAT_TWEAKS.md` "Double onLoadProgress for Root Replacement Loads" — mis-filed: the FP32 golden has both
   `onLoadProgress` blocks, so it is Flash behaviour, not a Ruffle-only tweak (move to a Flash-behaviour note).
3. `ACCEPTED_DIFFS.md` `tab_ordering_properties_tab_index_edge_case` ("conflicting test expectations … Ruffle known
   failure") — premise half-stale: FP32 prints the edge-case golden byte for byte. Whether `tab_ordering_properties`
   (graded pass, not provenance-checked) is Flash decides which golden is the outlier → LOCAL ORACLE REQUEST 1.
4. `ruffle-tests/ignored_tests.txt` `form_loader_encoding_4` (network/form bucket) — reason obsolete: no network needed,
   it was a decoding rule (B5). Prune on landing.
5. Code comment, `action.c` `actionGetMemberImpl` FUNCTION/"prototype" arm: "TextField.prototype is exposed (matches
   Ruffle) … Gnash's `typeof(TextField.prototype) == 'undefined'` check fails under this exposure, but Ruffle fails that
   same check" — stale: FP32 and gnash's Flash-made `TextField-v5` golden both say `undefined`.
6. Code comments "matching Ruffle" in `bitmapDataPaletteMap` (`& 0xFF`), `perlin_turbulence` ("Ruffle uses bf_x here
   (matches SVG spec bug)"), `bitmapDataCopyPixels` alpha-bitmap arm, `bitmapDataGenerateFilterRect` (stub) — each was
   written to the Ruffle golden; FP32 differs (B6).

Not stale (checked): `from_shumway/ignored_tests.txt` reasons for `MaskTest-3`, `avm1movie`, `flash_text_TextField2`,
`getobjectsunderpoint` ("Ruffle and we agree; Flash's capture does not") are consistent with table A. RvF's
platform-split list (`asnative_instrument`, `flash_text_TextField2`, `loader-events`) is right: those three are soft
(Windows FP32 golden).

## Mechanisms and evidence (GO buckets)

### B1 — function version = base clip's current movie (2 rows)
`mcl_replace_root_swf7_to_swf{5,6}`: a SWF7 root defines MCL callbacks, then loads a SWF5/6 child into `_level0`.
FP32 prints `rest=` (SWF<7 `"" + undefined`) in **every** callback, `onLoadStart` included; Ruffle and we kept the
defining movie's v7 (`rest=undefined`). The callbacks' closure (`d=closure var`) still works, so Flash keeps the
scope chain but takes the *version* from the function's base clip (`_level0`), whose movie is now the child.
Prototype (`switchToFunctionVersion`): if `func->base_clip == &root_movieclip` and `root_movieclip.swf_version`
(set in the MCL pre-phase, `action.c` ~:42093) differs from `func->swf_version`, run at the root's version.
In a normal movie the two are equal, so the arm is inert. Gate: all 57 avm1 load/MCL/level/version rows and the 10
`regression/*cross_swf_version*` fixtures unchanged.

### B2 — SWF5 `TextField.prototype` is undefined (1 + 1 bonus)
`textfield_props_swf5` lines 3–4: FP32 `undefined`/`undefined` for `TextField.prototype` / `typeof`. Gnash's
Flash-made `TextField-v5` golden agrees (`PASSED: TextField.prototype == undefined`). `new TextField()` still links to
the hidden prototype (the golden enumerates its properties). Prototype: the existing SWF5 AsBroadcaster hide in the
`actionGetMemberImpl` FUNCTION arm also covers `&g_textfield_constructor`. Bonus flip: gnash `TextField-v5` rm → pass
(it is table-A "golden = Flash"; tell w1b-rm-gnash).

### B3 — truncated root SWF (2 rows)
`swf_length_too_long` (FWS, header 734, file 334) and `lzma_length_too_long` (ZWS, header 649, 413 bytes decode).
FP32: `getBytesLoaded()` = bytes actually decoded, `getBytesTotal()` = header; and the root **does not wrap** to
frame 1 (it never finished loading; `onEnterFrame` keeps ticking). Prototype: `verify_output.py`
`_swf_available_len()` → `-DSWF_BYTES_LOADED=N` **only when N < header length** (a scan of all 1459 downloaded
`test.swf` in avm1/shumway/timeline/swf/fonts/visual/regression finds exactly these 2); the root getBytesLoaded arm
returns it; `swf.c`/`swf_core.c` cancel the recompiler-emitted natural wrap under the same define. Both rows pass in
graphics AND no-graphics. Note for the browser build: the define is harness-only; a real streaming model is the
general fix (not needed by the corpus). Avm2/gnash/avmplus SWFs were not scanned (not downloaded) — CI will show it,
and the define cannot fire on a non-truncated SWF.

### B4 — SWF6 addProperty re-entry (1 row)
`virtual_property_recursion_swf6` o2: FP32 prints `setter b`, `getter`, `Done: e` — the read of `o2.prop` *inside the
setter* does not call the getter, and the write inside the (later) getter does not call the setter. Our SWF6 key was
per (receiver, name, getter-vs-setter). Prototype: SWF6 counts getter+setter frames together. SWF7+ (entry-keyed,
65 deep) untouched. Family gate (16 rows: `add_property`, `virtual_property_recursion_*`, `watch*`) all unchanged,
and `watch_recursion_swf6/double_swf6` remain byte-identical to FP32.

### B5 — form loader lenient UTF-8 (1 row)
`form_loader_encoding_4` (SWF6, no codepage): FP32 reads each lead byte with its 1–3 following bytes **without
validating them**: `cp = ((lead & mask) << 6k) + Σ (trail_i − 0x80) << …`. Checked byte-exact on both lines:
`C4 D6`→U+0156, `DC 20`→U+06A0, `DF 20`→U+0760, a lead at EOF is dropped, stray trail bytes pass as U+00xx
(Shift-JIS line). Valid UTF-8 is unchanged by construction. Shapes the test does not exercise (negative/over-range
cp, surrogates) fall back to emitting the lead byte; unprobed.

### B6 — BitmapData (4 rows)
- `bitmapdata_custom_rectangle`: `generateFilterRect` was a stub returning `undefined`. FP32 returns the source rect
  for the default BevelFilter (inner), **built through the live `flash.geom.Rectangle`** (a replaced class runs, a
  throwing one throws), and when `flash.geom` is not an object, `rectangle`/`generateFilterRect`/`getColorBoundsRect`
  all return `-1`. Prototype models the identity case only; the outset for blur/glow/drop-shadow/outer filters is
  unprobed.
- `paletteMap`: FP32 adds the **full 32-bit** array entries (`0xCC + 0x156 + 0x78 = 0x29A`); we (as Ruffle) masked each
  to `& 0xFF`. An opaque target keeps alpha 0xFF whatever the summed alpha byte.
- `perlinNoise`: FP32 treats a negative base like its magnitude (golden: the `baseX=-2` block equals the
  `objLooksLikeNum`(=2) block), and the stitch-Y frequency uses `bf_y` (Ruffle copies the SVG reference's `bf_x` typo).
  Both changes applied together; 0/8485 lines differ after.
- `copyPixels`: three FP32 rules. (1) an alphaBitmapData passed **without** an alphaPoint argument (4 args) is ignored;
  a 5th argument (even null/undefined/`{}`) applies it at (0,0). (2) The mask scales every **premultiplied** channel,
  alpha included, by `a >> 8` (opaque `0xff345678` × 0x12 → `0x112d5a78`; Ruffle's unpremultiply / re-premultiply gave
  `0x12395571`). The existing `(256 − sa) >> 8` blend then matches FP32 unchanged. (3) `mergeAlpha` is ToBoolean
  (`(int)NaN` from `undefined` merged on x86).
Gate (44 rows: every `avm1/bitmap*`, every `bitmap_data_thorough/*`, gnash `BitmapData-v8`): only the 4 flips;
`pixelDissolve` keeps its 20 index-diffs; gnash `BitmapData-v8` keeps its 8; 6 image comparisons in the set pass at 0
outliers.

### B7 — ASnative major table (1 row)
`asnative_sweep` probes `ASnative(i, 9999)` for i < 65536. FP32 returns a function for 73 majors; we returned a value
for 2. Prototype: a 73-entry major list; an unimplemented minor of a listed major returns one shared no-op native.
Calling it returns `undefined` (real Flash natives do something; no corpus row calls a dead minor).

### B8 — flash_fixes candidates (2 rows, no code)
`watch_recursion_swf6` (1 line) and `watch_recursion_double_swf6` (4 lines): FP32 prints `  o2.prop: ` with a
trailing space; the golden was stripped. Our graphics output is **byte-identical** to
`trace-provenance/avm1__watch_recursion_swf6.r1.txt` and `…double_swf6.r1.txt` (cmp, before and after the
prototype). Coordinator: add both captures to `flash_fixes/fixes.json` → 2 flips with zero code.

## Rows (all 38 in scope)

`d` = `<` lines in `diff output.txt ours` (content diff, graphics, before). Status before = baseline `ruffle_matched`.

| row | d | mechanism (one line) | bucket / verdict | after |
|---|---|---|---|---|
| `avm1/asnative_instrument` | 131 | NetConnection/NetStream native tables (2100/2101…) not dispatched to instrumentable natives; Windows-FP32 golden (Linux prints `null` for 2 device getters) | L NO-GO (soft) | rm |
| `avm1/asnative_sweep` | 71 | every minor of an existing ASnative major is a function | B7 | **pass** |
| `avm1/attach_movie_export_not_yet_run` | 1 | exports registered at `tagInit` for the whole SWF; FP32 has no frame-2 export at frame 1 | M HOLD (oracle 2) | rm |
| `avm1/bitmap_data_thorough/copyPixels` | 71 | alpha-bitmap arm arithmetic + 4-arg ignore + mergeAlpha ToBoolean | B6 | **pass** |
| `avm1/bitmap_data_thorough/paletteMap` | 71 | `& 0xFF` LUT mask; opaque alpha | B6 | **pass** |
| `avm1/bitmap_data_thorough/perlinNoise` | 43 | negative base; stitch-Y `bf_x` typo | B6 | **pass** |
| `avm1/bitmapdata_custom_rectangle` | 12 | generateFilterRect stub; non-object `flash.geom` → -1 | B6 | **pass** |
| `avm1/form_loader_encoding_4` | 2 | lenient UTF-8 | B5 | **pass** |
| `avm1/load_cancel_via_unloadclip` | 2 | unloadClip does not cancel the pending loadClip (child + onLoadInit still run) | M HOLD (after w2-avm1-leads-land) | rm |
| `avm1/load_cancel_via_unloadmovie` | 3 | same, loadMovie + MCL | M HOLD | rm |
| `avm1/mcl_replace_root_swf7_to_swf5` | 1 | B1 | B1 | **pass** |
| `avm1/mcl_replace_root_swf7_to_swf6` | 5 | B1 | B1 | **pass** |
| `avm1/tab_ordering_properties_tab_index_edge_case` | 3 | FP32 stores a string `tabIndex` raw on `_root`; we coerce (as `tab_ordering_properties` expects) | S once oracle 1 answers | rm |
| `avm1/target_paths/swf5` | 84 | 36 debug-player `Parameters of primitive types are no longer coerced…` lines + `eval`/`_x` of slash/dot paths that end on a variable (`a/../a.root_var` → undefined in FP32) | L NO-GO | rm |
| `avm1/target_paths/swf6` | 84 | same | L NO-GO | rm |
| `avm1/textfield_props_swf5` | 2 | B2 | B2 | **pass** |
| `avm1/virtual_property_recursion_swf6` | 0 (+2 extra) | B4 | B4 | **pass** |
| `avm1/watch_recursion_double_swf6` | 4 | trailing spaces stripped from golden | B8 flash_fix | rm (== FP32) |
| `avm1/watch_recursion_swf6` | 1 | same | B8 flash_fix | rm (== FP32) |
| `fonts/device_font_no_ink` (AVM2) | 14 | device-font `getCharBoundaries` height: FP32 h=8/16 (size 10/20), we 10/20 (ascent+descent vs FP32's) | M NO-GO (device-font metrics family) | rm |
| `from_shumway/MaskTest-3` (AVM2) | 1 | `s.mask = <timeline Shape>` reads `null` on the next frame in FP32 | M NO-GO, needs probe | rm |
| `from_shumway/acid/acid-shapes-testing` (AVM2, trace) | 12 | stroked-shape `getBounds` x 9.35 vs 9.3 (stroke half-width twip rounding) | M NO-GO (bounds family) | rm |
| `from_shumway/acid/acid-text-x` (AVM2, trace) | 1 | `168` vs `167.95`: FP32 integer-pixel text metric | S–M NO-GO (text-metric rounding; overlaps w2-glyph-quarter-snap) | rm |
| `from_shumway/acid/acid-textfield` (AVM2, trace) | 5 | text-run count after replaceText/appendText/setTextFormat (run coalescing) | M NO-GO (adjacent to w2-text-edit-land span model) | rm |
| `from_shumway/as3-loader/LoaderTest` (AVM2) | 1 | `enterFrame` vs Loader event order (one line) | M NO-GO (loader delivery tick) | rm |
| `from_shumway/as3-loader/events/loader-events` (AVM2) | 17 | child construct/added/frame order across Loader ticks; Windows-FP32 golden | L NO-GO (soft) | rm |
| `from_shumway/avm1movie` (AVM2) | 10 | AVM1Movie loaded into AVM2: loadee init / complete / hit tests never run | L NO-GO | rm |
| `from_shumway/avm2/flash/geom/transform/pixelBounds` (AVM2) | 1 | off-display `transform.pixelBounds` = 500×500 in FP32 for a 100×100 rect (×5 unexplained) | S if rule known; oracle 3 | rm |
| `from_shumway/flash_text_TextField` (AVM2) | +5 | device-font `getTextLineMetrics` / `bottomScrollV` (we fail 5 self-checks FP32 passes) | M–L NO-GO (device-font metrics) | rm |
| `from_shumway/flash_text_TextField2` (AVM2) | 9 | narrow-field word wrap; Windows-FP32 golden | L NO-GO (soft) | rm |
| `from_shumway/getobjectsunderpoint` (AVM2) | 3 | we return a Shape FP32 excludes (+ one `[object Sprite]` line missing) | M NO-GO | rm |
| `from_shumway/timeline/nav/clipDepth` (AVM2) | 4 | timeline clipDepth masks not reflected as AVM2 mask state across frames | M NO-GO | rm |
| `swf/lzma_length_too_long` | 9 | B3 | B3 | **pass** |
| `swf/swf_length_too_long` | 6 | B3 | B3 | **pass** |
| `timeline/frame_script_button_order` (AVM2) | +1 | extra `MyContainer frame1` (button-state container frame script runs once more) | M NO-GO (AVM2 frame-script order) | rm |
| `timeline/swf_9_event_goto_frame_script` (AVM2) | 1 | child constructor vs frame-script order on goto | M–L NO-GO (§27.4 interleave family) | rm |
| `timeline/swf_9_frame_script_dynamic_goto` (AVM2) | 1 | same family, one line moved | M–L NO-GO | rm |
| `visual/edittext/edittext_device_transform_metrics` (AVM2) | 8 | device text `getCharBoundaries` x/height under a transform (FP32 x=102/52, scaled heights) | M NO-GO (device-font transform family) | rm |

Pricing check (premise attack): 16 in-scope rows have a table-A index count ≤ 3. Only 5 of them flip or become
flash_fixes here (`form_loader_encoding_4`, `mcl_replace_root_swf7_to_swf5`, `textfield_props_swf5`,
`virtual_property_recursion_swf6`, `watch_recursion_swf6`). The other 11 (`attach_movie_export_not_yet_run`,
`load_cancel_*` ×2, `tab_ordering_*`, `MaskTest-3`, `acid-text-x`, `LoaderTest`, `pixelBounds`,
`frame_script_button_order`, `swf_9_*` ×2) each need their own mechanism, most of them AVM2. Meanwhile 7 flips came
from rows with 6–71 diff lines (B3, B6, B7), where one rule moves every line. A small diff did not predict a cheap fix.

## Measurements

Graphics (CI mode), single tests, `-P 2`. Before = baseline `ruffle_matched` (all 38 reproduced locally at
`a85e0122`); after = prototype.

- Headline flips, graphics: `mcl_replace_root_swf7_to_swf5/6`, `textfield_props_swf5`, `swf_length_too_long`,
  `lzma_length_too_long`, `virtual_property_recursion_swf6`, `form_loader_encoding_4`,
  `bitmapdata_custom_rectangle`, `bitmap_data_thorough/{paletteMap,perlinNoise,copyPixels}`, `asnative_sweep`: PASS.
  Bonus: gnash `TextField-v5` PASS.
- No-graphics (AVM1 runtime + `swf_core.c`): see §Gates (re-measured at the end).
- Gates (graphics): see §Gates.

## Gates

GATES_PLACEHOLDER

## New unclaimed leads

1. **Flash's `generateFilterRect` outset** for blur/glow/drop-shadow/outer bevel is unknown (prototype models only
   the identity case). A Flash sweep of filter kinds would let AVM1 *and* AVM2 (`bd_generate_filter_rect` is the same
   Ruffle stub) report real rects.
2. **AVM2 copyPixels / paletteMap / perlinNoise** (`avm2_bitmap.c`) carry the same Ruffle formulas B6 corrects for
   AVM1 (`& 0xFF`-style LUTs, `bf_x` stitch typo, unpremultiply alpha-mask walk). Check the avm2 `bitmapdata_*` rows
   against these rules before assuming Ruffle parity there.
3. **B1 generalises**: any closure defined by a movie later replaced at the same level (loadMovieNum into an occupied
   level, not only MCL into `_level0`) should run at the new movie's version. Only the root case is prototyped.
4. **Debug-player diagnostics in goldens**: `target_paths/*` grade 36 FP32 debug-projector lines each, while
   `bitmapdata_custom_rectangle`'s golden omits the same diagnostic. Flash-made goldens are inconsistent about
   debugger lines; a harness-level policy (strip from goldens via flash_fixes, or emit) is a coordinator decision.

## LOCAL ORACLE REQUESTS

1. **FLASH: `avm1/tab_ordering_properties`** (corpus test, no build), trace, `num_ticks` 1, **direct** (pinned is fine:
   no `_global` enumeration). Compare the `===== movie clip =====` block, `after set 7` (`tabIndex = 'x'` after
   `-2147483648`): golden says the numeric value is kept. If FP32 agrees, the two goldens are both Flash and the rule is
   "a non-numeric string is stored raw only while the stored value is not yet a number / only for `this` on the
   timeline" (needs a third probe); if FP32 prints `x`, `tab_ordering_properties` is a flash_fixes candidate and
   `…_edge_case` flips with raw storage.
2. **FLASH: `w1b-rm-avm1-misc-fixtures/export_timing/probe_stop.swf` and `probe_play.swf`** (built by `build.py`
   from the corpus fixture; both run in our pipeline), trace, ~4 s each, **direct**. `probe_stop`: frame 1 `stop()`s
   and an `onEnterFrame` traces `attachMovie("LateExport","e",5)` every tick; the export lives in frame 2, never
   reached. Every line `undefined` ⇒ exports register when the playhead reaches the frame (implement by moving
   `tagRegisterExport` into the frame function); `_level0.e` from some tick ⇒ parser-driven (implement as
   "available one tick after load"). `probe_play` is the control (frame 2 is reached).
3. **FLASH (optional, needs an AS3 build): off-display `pixelBounds`.** `var mc = new MovieClip();
   mc.graphics.beginFill(0x44AA); mc.graphics.drawRect(10, 20, 37, 53); mc.x = 7; trace(mc.transform.pixelBounds);
   mc.scaleX = 2; trace(mc.transform.pixelBounds); addChild(mc); trace(mc.transform.pixelBounds);` — the shumway row
   only shows 100→500; two non-square sizes and an offset would pin the ×5 rule.
