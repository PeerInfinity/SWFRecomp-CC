# w1-drift-avm2: upstream drift pricing, AVM2 / visual / small suites + harness semantics (session 23, wave 1)

**New files:** `w1-drift-avm2-report.md` (this), `w1-drift-avm2-prototype.patch`
(`git diff origin/master -- SWFModernRuntime ruffle-tests/verify_output.py`, 9 files, +195/−33;
applies clean to `3db378713`; source reverted on this branch).

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Tests downloaded at upstream
**`aa9f62a70`** = `0ddd12b6a` + 1 commit (`tests: Add visual test for VP6 inter frames`), so every row
below is graded against `0ddd12b6a` content except the one extra `visual/video/vp6_inter_frames`.
Ruffle source: blobless clone at `/root/ruffle`.

**Fidelity: proved CI-grade.** I re-ran all 47 new non-AVM1 graded rows `--mode=graphics --images`
on clean `origin/master`. Every trace status AND every pixel number (outliers, diff_channels,
max_diff) is identical to run `44922638965`. Local grading here is CI-grade for these rows.

---

## 0. Headline: GO/NO-GO and priced flips

**Prototype measured (graphics mode, CI-grade box): +15 trace effective, +2 pixel passes.**
It re-flips **all 6 trace drift losses in my half** and **1 of the 3 pixel drift losses**, and adds 9
new-row trace flips (1 of them a row the harness never discovered) plus 1 new pixel pass.
Canaries: 31 neighbouring rows, all unchanged (§7).

| # | Row | CI now | Proto | Hunk | Verdict |
|---|---|---|---|---|---|
| 1 | `avm2/event_handler_exception` | fail (drift) | **ruffle_matched** | frame rename | GO |
| 2 | `avm2/filereference_browse_select` | fail (drift) | **pass** | FileReference dates | GO |
| 3 | `from_avmplus/as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | fail (drift) | **pass** | `<?xml ` → #1092 | GO |
| 4 | `from_avmplus/e4x/XML/bug_564468` | fail (drift) | **ruffle_matched** | `<?xml ` → #1092 | GO |
| 5 | `from_avmplus/e4x/XML/misc_errors` | fail (drift) | **ruffle_matched** | `<?xml ` → #1092 | GO |
| 6 | `from_avmplus/regress/bug_478501` | fail (drift) | **pass** | NUL escape | GO |
| 7 | `avm2/xml_unescaping_nul_char_ref` (new) | fail | **pass** | NUL decode/escape + literal comments/PIs | GO |
| 8 | `avm2/xml_many_namespace_declarations` (new) | fail | **pass** | uncapped attribute list | GO |
| 9 | `avm2/edittext_event_link_case_insensitive` (new) | fail | **pass** | caseless `event:` | GO |
| 10 | `avm2/bitmapdata_encode_png_visual` (new) | fail | **pass**, image **pass** | encode default ByteArray / #2006 | GO |
| 11 | `avm2/bitmapdata_encode_png_roundtrip` (new) | fail | **pass** | + `BitmapData.compare` | GO |
| 12 | `avm2/bitmapdata_encode_jpeg_visual` (new) | fail | **pass** (image still fails) | encode default ByteArray | GO (trace) |
| 13 | `avm2/textfield_default_text_format_null` (new) | fail | **pass** | #2007 null format | GO |
| 14 | `avm2/perspective_projection_center` (new) | fail | **pass** | #2007 null point | GO |
| 15 | `avm2/allow_networking` (new, **never graded**) | absent | **pass** (+1 row) | harness H1 + Sound fetch log | GO |
| P1 | `avm2/stage3d_texture_bytearray_compressed_alpha` [output] | pixel fail (drift) | **pixel pass** (max 2 ≤ tol 4) | ATF 2nd alpha endpoint | GO |
| P2 | `avm2/bitmapdata_encode_png_visual` [output] | pixel fail | **pixel pass** (0 outliers) | as #10 | GO |

Rows 1–6 are drift re-flips, not yield. Row 15 grows the graded denominator by 1 (pass).

**NO-GO via code (drift that is not ours to win):** `avm2/graphics_draw_path` and
`visual/cache_as_bitmap/avm1_color` (pixel pass→fail). Upstream swapped Ruffle-rendered goldens for
Flash screenshots and marked both `known_failure`. **Our CI render is byte-identical to the new
`output.ruffle.png`** (and to the old golden), so we lose exactly where Ruffle loses. The only re-flip
is the harness-policy question H3 (§4) or real Flash-rasterizer fidelity work, which is a renderer
project, not a drift fix.

---

## 1. Price table: every DRIFT status move (trace and pixel), pre-labelled

### 1a. Trace (intersection 4563; the 8 losses; my half = 6)

| Row | Move | Label | Upstream cause | Our owner | Re-flip price |
|---|---|---|---|---|---|
| `avm2/event_handler_exception` | ruffle_matched→fail | **DRIFT (sidecar)** | `05a511c05` renamed Ruffle's playerglobal `dispatchEventInternal`→`dispatchEventFunction` in `output.ruffle.txt` | `avm2_events.c:741` hard-codes the old Ruffle name | 1 string. Measured → ruffle_matched. Flash's `output.txt` already says `dispatchEventFunction` (it differs from the sidecar only by `[Z:\…Test.as:N]` debug suffixes), so this is Flash-correct as well. |
| `avm2/filereference_browse_select` | pass→fail | **DRIFT (framework fixture)** | `9ca80fab8`: `tests/framework/src/backends/ui.rs` `TestFileSelection` now returns creation 2000-10-20T01:02:03Z and modification 2000-10-25T04:05:06Z instead of `None`. It is used for open AND save dialogs. | `avm2_net.c:2649` `fileref_get_date` returns null | Split getters returning `new Date(972003723000)` / `new Date(972446706000)` after the existing #2037 check. Measured → pass; 6 other `filereference_*` rows still pass. |
| `from_avmplus/as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | ruffle_matched→fail | **DRIFT (Ruffle fixed; sidecar + `known_failure` deleted)** | `944e4973d` quick_xml 0.39 | `avm2_e4x.c` `<?` arm (≈2193) always raises #1097 | avmplus `XMLParser`: a caseless `<?xml ` opening with no `?>` is kXMLUnterminatedXMLDecl #1092. Measured → **pass**. |
| `from_avmplus/e4x/XML/bug_564468` | ruffle_matched→fail | **DRIFT** (same) | Ruffle now passes lowercase only | same | Same hunk. Measured → ruffle_matched. Our hunk also passes Flash's upper/mixed-case lines. The 4 residual lines (`<![cdata[` caseless CDATA, `#2023`) are pre-existing and inside the sidecar. |
| `from_avmplus/e4x/XML/misc_errors` | ruffle_matched→fail | **DRIFT** (same) | same | same | Same hunk. Measured → ruffle_matched (residual: pre-existing #1095 vs #1090). |
| `from_avmplus/regress/bug_478501` | ruffle_matched→fail | **DRIFT (Ruffle fixed; sidecar deleted)** | `1a54c10d7` AVM2 decodes `&#0;`/`&#x0;` to NUL and escapes NUL back as `&#x0;` | `avm2_e4x.c` `esc_attribute_value`/`esc_element_value` (≈1250) and `decode_entities` (`cp == 0` kept raw) | 3 small edits. Measured → **pass**. |
| `avm1/netconnection_serialize_arrays`, `from_gnash/misc-ming.all/NetStream-SquareTest` | — | not mine | — | — | `w1-drift-avm1` |

No trace row moved without an upstream test change (`corpus_status_diff`: 0 gains, 0 other moves).

### 1b. Pixel (intersection 587; full per-row numeric diff, not just band moves)

I compared **every** intersection row on status, max_diff, diff_channels, outliers and mean_diff
(not only the `image_status_diff` 5% band floor). Exactly 9 rows changed. All 9 have an upstream
change to their test files. **No pixel row moved without a test change: the CI rasterizer did not
change.**

| Row | Move | Label | Evidence | Re-flip |
|---|---|---|---|---|
| `avm2/graphics_draw_path` | pass→fail (664) | **DRIFT: Flash re-golden** (`e7d71c98b`, adds `output.ruffle.png` + `known_failure = true`) | our CI PNG vs `output.ruffle.png`: **0 diff**; vs old golden: 0 diff | NO-GO via code; H3 policy only |
| `visual/cache_as_bitmap/avm1_color` | pass→fail (1200) | **DRIFT: Flash re-golden** (`045db00b3` "Correct avm1_color reference against Flash Player 32") | vs `output.ruffle.png`: **0 diff** | NO-GO via code; H3 only |
| `avm2/stage3d_texture_bytearray_compressed_alpha` | pass→fail (8192 > 66) | **DRIFT: Ruffle decoder fix + re-golden** (`5021d0ed7`) | `avm2_jpegxr.c:352` reads the 2nd alpha endpoint at byte `blocks + 4i`. That is Ruffle's old bug, ported verbatim ("We follow Ruffle byte for byte"). | **GO, 1 line**: `alpha[(blocks + i) * 4]`. Measured → pass (0 outliers, max 2, tol 4). `…_compressed_raw_alpha` byte-identical numbers; `stage3d_context3d_string_args` pass. |
| `avm2/graphics_simple_shapes` | band a→b (2→158) | DRIFT: Flash re-golden + `known_failure` | vs `output.ruffle.png`: 2 channels (= our old residue) | as graphics_draw_path |
| `avm2/graphics_gradients` | band b→c (148→3685) | DRIFT: same | vs `output.ruffle.png`: 1321 channels, max 73 (old golden: 1320) | same |
| `avm2/sprite_with_frames` | c→c (914→6342) | DRIFT: same | vs `output.ruffle.png`: 914, max 1 (= old) | same |
| `avm2/stage3d_fractal` | band-only (<5%) | DRIFT: same | already catastrophic | — |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | a→d (12→1794) | DRIFT (`74323048b` "Fix … Video-EmbedSquareTest", re-golden) | vs `output.ruffle.png` 535 channels (old golden 1057) | gnash: `w1-drift-avm1` |
| `visual/edittext/edittext_underline_scale2` | outliers 0→12, still pass | **NOT a move**: upstream toml raised the non-macOS check's `max_outliers` 0→12, so the summary picks a different binding check | max_diff 42 and diff_channels 12 unchanged; pixels identical | — |

---

## 2. New non-AVM1 rows (49 added `test.toml` in my categories + 1 post-range)

All 47 graded ones ran clean on `origin/master` and matched CI exactly. Matching-line counts are from
clean runs. `kf` = top-level `known_failure` with `output.ruffle.txt` (ruffle_matched is an
acceptable target but Flash-correct is preferred).

| Row | CI trace | Pixel | Mechanism (owner) | Price | Verdict |
|---|---|---|---|---|---|
| `amf_sealed_class_dynamic_properties`, `bytearray_amf3_shared_references`, `bytearray_insertion_reborrow`, `context3d_clear_mask`, `loader_unloadandstop_subclass`, `loaderinfo_child_progress`, `netconnection_call_with_responder`, `vector_prototype_some`, `text/html_entity_whitespace` | pass | — | — | — | already won |
| `vector_indexing_cutoffs` (kf) | ruffle_matched | — | — | — | already effective |
| `visual/scroll_rect_culling` | pass | **pass** | — | — | already won |
| `visual/video/vp6_inter_frames` (post-`0ddd12b6a`) | pass | **16/16 pass** | — | — | will land as +1 trace, +16 pixel on the next CI download |
| `edittext_event_link_case_insensitive` | 0/1 | — | `avm2_text.c:10709` `et_open_url` matched `event:` case-sensitively | 6 lines | **GO, prototyped → pass** |
| `xml_many_namespace_declarations` | 1/2 | — | `avm2_e4x.c:1932` `RawAttr attrs[128]` silently drops attributes 129+ | growable spill buffer | **GO, prototyped → pass** |
| `xml_unescaping_nul_char_ref` | 13/19 | — | NUL decode/escape (`1a54c10d7`), and comments/PIs kept literal (`cea0f2cf9`: `avm2_e4x.c` comment arm ≈2160 and PI arm used `decode_entities_str`) | small | **GO, prototyped → pass** |
| `textfield_default_text_format_null` | 7/20 | — | `avm2_text.c` `txt_set_default_text_format` silently ignores null; FP throws #2007 | 7 lines | **GO, prototyped → pass** |
| `perspective_projection_center` | 6/34 | — | `avm2_display.c` `pp_set_center` reads NaN from null; FP throws #2007 (`8dc906c9b`) | 7 lines | **GO, prototyped → pass** |
| `bitmapdata_encode_png_visual` | fail | fail 20890 | `avm2_bitmap.c` `bd_encode` returned null when the output ByteArray is omitted (FP allocates one) | default ByteArray + #2006 order | **GO, prototyped → pass + pixel pass** |
| `bitmapdata_encode_png_roundtrip` | 1/33 | — | the above, plus `BitmapData.compare` did not exist (#1069) | port of Ruffle `compare` (≈50 lines) | **GO, prototyped → pass** |
| `bitmapdata_encode_jpeg_visual` | fail | fail 36883 | trace: the encode null; pixel: **no JPEG encoder** (bd_encode is PNG-only; Ruffle uses image-rs `JpegEncoder`, tol 14 vs Flash) | trace prototyped → pass; pixel needs a baseline JPEG encoder (≈400 lines C, port image-rs) | trace GO; pixel → slot **S3** |
| `bitmapdata_encode` | 1/147 | — | PNG sections now right (prototype); stops at the first JPEG section (`length > 0: false`, #2030) | JPEG encoder + the RangeError/#2004/#3699 option checks | **S3** |
| `context3d_draw_to_bitmap_data` | 2/15 | fail 7500 | `avm2_stage3d.c:4733` `drawToBitmapData` is `s3d_noop` (Ruffle implemented it in `b36debbc7`) | back-buffer readback into the BitmapData + #3692 "buffers must be cleared" state | slot **S4** |
| `stage3d/draw_to_bitmap_data_unconfigured` | 3/8 | — | same noop; missing #3692 after configure without clear | same | **S4** |
| `stage3d_missing_vertex_stream` (kf) | 13/37 | — | reads pixels through `drawToBitmapData` (all `0`), plus draw with unset streams | same readback; ruffle_matched target | **S4** |
| `primitive_bound_methods` (kf), `weird_number_bound_methods` (kf) | 5/11, 9/12 | — | we mint a fresh closure per property read. avmplus caches the bound closure per method keyed by receiver atom (`7c929ae8f`): int-valued 0 / 0.0 share; −0.0 and NaN are fresh boxes; interned strings share. | per-method last-receiver cache in the get-property → bind path | slot **S6** (Flash-correct is better than the Ruffle sidecar, which says NaN/−0 are identical) |
| `array_join_reentrant` / `vector_join_reentrant` (kf) | 58/68, 10/96 | — | `avm2_array.c:1242` / `avm2_vector.c:1275` re-read `length` each step; FP snapshots length (missing tail → empty strings; Vector throws RangeError #1125 when popped mid-join) | small | slot **S5** |
| `array_sort_arguments` (kf), `vector_sort_arguments` (kf) | 42/442, 1/355 | — | sort argument coercion (`"16"` → #1034 to Function; Vector `sort()` arity #1063) and native frames (`Array$/_sort()`, `builtin::apply()`) | medium | **S5** |
| `array_constructor` | 21/234 | — | `new Array(-1)` etc.: missing native frames `Error$/throwError()` + `Array()`, plus length/argument semantics | medium | **S5** |
| `error_stack_trace_class_names` | 127/135 | — | `avm2_error.c:177` `avm2_callstack_frame_name`: user namespaces print the URI (`Test/http://example.com/custom::m()`); package-internal and file-private classes print bare (`Hidden()`, `Priv()`, not `pkg::Hidden` / `Test.as$1::Priv`) | small | slot **S7** |
| `error_stack_trace_limit` | 600/674 | — | FP caps the captured stack depth; we print all 868 lines | small | **S7** |
| `displayobjectcontainer_remove_reentrant` | 2/257 | — | no #2094 "Event dispatch recursion overflow" guard → runaway (27 942 lines); expects `dispatchEventFunction` frames (prototype hunk already emits them) | medium | slot **S8** |
| `displayobjectcontainer_remove_reparent`, `displayobjectcontainer_removechildren_events` | 59/189, 21/56 | — | `avm2_display.c:7484/7515` removal ordering: FP detaches each child before its `removed`/`removedFromStage` reach listeners, one child at a time; we dispatch for all, then splice; reparent-in-listener is overwritten | medium | **S8** |
| `hit_test_scroll_rect` | 69/99 | — | `avm2_display.c:17407` `hitTestPoint` ignores scrollRect clipping/offset (after render) | medium | slot **S9** |
| `loaderinfo_root_progress`, `…_goto` | 3/7, 4/10 | — | root LoaderInfo never dispatches its final `progress` (bytesLoaded == bytesTotal) before `complete` (`avm2_display.c` ≈6359–6426 has it only for child loaders) | small | **S9** |
| `shared_object_get_local_error` | 1/21 | — | `avm2_amf.c:2017` `so_get_local` never throws #2134 (invalid name chars, bad/unrelated localPath, secure flag) | small-medium | **S9** |
| `amf_xmllist` | 4/12 | — | `avm2_amf.c` ≈825/1079: FP writes an XMLList as an empty anonymous object (AMF3 `0a 03 01`, AMF0 `03 00 00 09`); we serialize its children as properties | small | **S9** |
| `worker_terminate` | 1/56 | — | `flash.system::Worker` is only a stub entry (`avm2_globals.c:7411`); `Worker.current` is null → #1009 | primordial Worker + state machine + #3732 etc. | medium-large; HOLD (completion: a Worker slot, low value per row) |
| `textfield_get_text_format_args`, `textfield_set_text_format_args` | 50/567, 81/904 | — | AVM2 twins of the w2-tf-css AVM1 rows: begin/end index validation (#2006 RangeError) and clamping | medium | hand to **w2-tf-css** (same family; its brief only names the AVM1 rows) |
| `edittext_set_text_same`, `…_after_edits` (kf) | 92/115, 84/138 | — | AVM2 twins: assigning the same text re-applies `defaultTextFormat` | small-medium | hand to **w2-tf-css** |
| `visual/filters/empty_child_filter_bounds` | pass | fail 72840 | `68dcb8931` render fix | — | **w2-padded-filter** (noted, not triaged) |
| `visual/static_text_offstage` | pass | fail 19216 | 3 sub-mechanisms, read from `generate.py` + PNGs: (a) DefineText culled by its **tag bounds** (we draw the RED text whose bounds are off-stage; we drop the CYAN one); (b) the 4 px MAGENTA corner glyph at (0,0) is not drawn; (c) `BitmapData.draw` of an off-stage sprite's text renders nothing (YELLOW holder is empty). The frame-3 GREEN move matches. | medium | pixel slot (`w1-pixel-misc` family); HOLD |
| `dictionary_qname_keys` | — | — | **already graded in s22** (CI downloads upstream master at run time) | — | w2-qname-dict |

### Where the "189 extra rows" come from: refuted, it is **79**

`corpus_status_diff` convention (nested dirs excluded): s22 **4563** → now **4642** rows; effective
4503 → **4515**. Including the 47 nested `from_shumway/avm1` duplicates: 4689 rows / 4562 effective.
I cannot reproduce 4752 / 4625 from any stem (`results.json`, `results_graphics.json` or
`metadata.total_available` all give 4689). The difference, 63 rows, all of them effective, looks
like a counting artifact.

Real growth: **79 new rows, 0 removed**, every one a new upstream test:

- avm1: 31 (25 mismatch, 4 pass, 2 ruffle_matched); `w1-drift-avm1`'s half.
- avm2: 42 (8 pass, 1 ruffle_matched, 33 mismatch).
- stage3d: 1 (mismatch). text: 1 (pass). visual: 3 (all trace pass).
- regression: 1 (pass; our own `aaf953dff` fixture).

No suite or subtest became newly graded. In fact the reverse: H1 below shows 3 new upstream tests
that are **silently not graded**.

---

## 3. Modified tests: which verdicts moved and why

- **`f0aa96e0c` (2095 files)** only renamed `num_frames`→`num_ticks` with the same integer: 2100
  conversions across the corpus, 0 value changes. One exception is `avm1/globals_monkeypatch` 1→5
  in its own commit (sibling's row). Our harness reads either key, so this is a verified no-op.
- **`e7d71c98b` + `045db00b3` + `74323048b`**: Flash re-goldens; §1b.
- **`5021d0ed7`**: ATF fix + re-golden; §1b, GO.
- **`944e4973d` / `1e5c01030` / `95f1e71e9` (quick_xml 0.38→0.41)**: deleted the avmplus sidecars
  and/or `known_failure` on the 3 XML-decl rows and added `xml_many_namespace_declarations`; §1a.
- **`1a54c10d7`, `cea0f2cf9`**: bug_478501 + xml_unescaping_nul_char_ref; prototyped.
- **`05a511c05`**: event_handler_exception sidecar rename; prototyped.
- **`9ca80fab8`**: framework file-dialog dates; prototyped.
- `xml_mismatched_tag`, avmplus e4x others, shumway `as3-loader`, and the remaining deleted
  `output.ruffle.txt` files: **no verdict moved** (none appears among the intersection moves).

---

## 4. Harness semantics: num_ticks vs num_frames, and the other framework changes in range

**Ruffle (`tests/framework/src/runner.rs:237`)**: `num_ticks` drives `Player::tick(frame_time)`
(`core/src/player.rs:554`). That accumulates `dt = tick_rate or 1000/header_fps` against the **live**
`frame_duration()`, runs 0..N frames, then `update_sockets / net_connections / workers / timers`, and
`StreamManager::tick`. `num_frames` runs exactly `run_frame(); update_timers(frame_time); audio.tick()`.

**Ours (`verify_output.py:1033` `get_num_frames`)**: either key becomes `MAX_FRAMES`, one frame per
iteration. They are equivalent iff the live frame rate equals the header rate and `tick_rate` is unset.

| Gap | Rows | Evidence | Price |
|---|---|---|---|
| **G-a: `tick_rate`** | none | `tick_rate` appears in **0** tomls at `0ddd12b6a` | 0 |
| **G-b: header fps 0/negative/NaN** (`stage_framerate_zero/negative` `num_ticks=1`, `stage_framerate_nan` 4) | 0 movers | upstream's own commit notes (`4f5d0ac08`, `d461b4804`): with ticks the player runs "a few extra frames, but they execute no code". Our run is the same single frame as before; statuses unchanged. | 0 |
| **G-c: `sleep_to_meet_frame_rate` timer rows** (`avm2/timer`, `timer_reset`, `timer_setdelay`, `from_shumway/avm1/{lookup,setinterval,settimeout}`, `from_shumway/flash_utils_Timer`) | 0 movers | all 7 converted with the same counts; all still **pass** | 0 |
| **G-d: runtime `stage.frameRate` ≠ header with ticks > 1** | **`avm2/stage3d_texture`** (header 24, `stage.frameRate = 60`, `num_ticks = 5`, converted in range). Under Ruffle ticks that is ≈2.5 frames per tick, ≈12 frames total; we run 5. Possible minors (frameRate assignment equal to the header, so no effect): `stage3d_raytrace`, `stage3d_fractal`, `key_input_*`, `h264_multinalu`, `edittext_ime_focus_lost`. | owned by **w2-stage3d-text**: tell them the capture frame may be ≈12, not 5 | proposal: emulate `Player::tick`, i.e. `-DTICK_MS=1000/header_fps` and let the runtime's frame loop run `floor(accum / (1000/live_fps))` frames per tick, only for `num_ticks` tomls. ≈40 lines across verify_output + both frame loops; **HOLD** until a row proves a gain (currently 0 provable rows). |
| **G-e: sockets/NetConnection/NetStream/worker updates per tick** | 0 known | our runtime services these in its frame loop regardless of key | 0 |

**Other framework changes in range** (`git log 45366370e..0ddd12b6a -- tests/framework`):

- **H1 (real bug, GO) `[subtests]` with no `player_options.version` are never discovered.**
  `5701ce322` / `c95bde93f` introduced subtests keyed on `player_options.allow_networking`.
  `verify_output.py:357` starts `best_version = -1` and scores a missing version as −1 with a strict
  `>`, so no variant ever wins, `resolve_expected_filename` returns None, and the test is silently
  absent. Affected across the whole corpus: **3 rows**:
  - `avm2/allow_networking` (mine). Prototype (`best_version = -2`, first variant wins = `all` =
    Ruffle's default `NetworkingAccessMode::All`) + Sound fetch-log hunk → **pass**. Without the
    Sound hunk it fails only on the two `Sound` `Navigator::fetch` blocks (`avm2_media.c`
    `sound_start_url_load` never logged).
  - `avm1/allow_networking_import_assets`, `…2` (sibling's; not run here).

  Discovery on my suites changes only by these rows (avm2 1334→1335). The `internal`/`none`
  variants would need real `allowNetworking` enforcement (SecurityError #2146/#2149…). That is
  NO-GO (canonical-variant mode grades one variant).
- `9ca80fab8` TestFileSelection dates: §1a (runtime fixture, prototyped).
- `ec58df5f7` "Don't draw frames that aren't captured" (`render_no_draw` keeps scrollRect side
  effects): no semantic change for us.
- `4daa26053`/`84db1047b`/`c1617eefe`/`684ee52fc`/`2955398b5`/`5cbd33339` `[[compilers]]` (swfasm/asc
  at test time): **no gap**. All 4540 upstream test dirs ship a prebuilt `test.swf`.
- **H3 (policy, coordinator's call): image analog of `ruffle_matched`.** Image comparisons now carry
  `known_failure` + `output.ruffle.png` (6 rows from `e7d71c98b`/`045db00b3`). The grader already
  flags `known_failure` (`fail_known_failure` = 8 avm2 + 3 visual) but books them as plain fails.
  Crediting "matches `output.ruffle.png` within the comparison's tolerance" would re-credit exactly
  `graphics_draw_path` and `cache_as_bitmap/avm1_color` (byte-identical), and nothing else in this
  set (simple_shapes/gradients/sprite_with_frames keep their old residue against the sidecar). Under
  the Flash-over-Ruffle ruling these remain real Flash misses; I recommend reporting them as a
  separate `ruffle_matched` image bucket **without** counting them as passes. Adjacent to
  `w1-pixel-misc`'s `ignore = true` gap.

---

## 5. Mechanism groups → wave-2 slots I would fund

| Slot | Scope | Expected flips (measured where marked) | Files |
|---|---|---|---|
| **S1 `w2-drift-avm2-land`** (land the prototype) | the 9-file patch as is: frame rename, FileReference dates, `<?xml` #1092, NUL decode/escape, literal comment/PI, attribute spill, caseless `event:`, #2007 ×2, encode default-array/#2006 + `compare`, ATF endpoint, Sound fetch log, H1 discovery fix | trace **+15 measured**: 6 drift re-flips (`event_handler_exception`, `filereference_browse_select`, `Error1092XmlUnterminatedXmlDecl`, `bug_564468`, `misc_errors`, `bug_478501`) + `xml_unescaping_nul_char_ref`, `xml_many_namespace_declarations`, `edittext_event_link_case_insensitive`, `bitmapdata_encode_png_visual`, `bitmapdata_encode_png_roundtrip`, `bitmapdata_encode_jpeg_visual`, `textfield_default_text_format_null`, `perspective_projection_center`, `allow_networking` (+1 row). Pixel **+2 measured** (`stage3d_texture_bytearray_compressed_alpha`, `bitmapdata_encode_png_visual`). | `avm2_{bitmap,display,e4x,events,jpegxr,media,net,text}.c`, `verify_output.py` |
| **S3 `w2-bitmapdata-jpeg`** | baseline JPEG encoder (port image-rs `JpegEncoder`: quality-scaled IJG tables, Huffman std tables, sampling as image-rs), JPEG option validation (quality > 100 RangeError, 0→1, #2004 unknown compressor, #3699 > 65500) | `avm2/bitmapdata_encode` (trace), `bitmapdata_encode_jpeg_visual` [output] (pixel, tol 14; plausible but unproven, Ruffle passes with the same encoder) | `avm2_bitmap.c` (+ new TU or inside it) |
| **S4 `w2-context3d-readback`** | `Context3D.drawToBitmapData` readback + "clear before draw" #3692 state | `avm2/context3d_draw_to_bitmap_data` (trace + pixel), `stage3d/draw_to_bitmap_data_unconfigured`, likely `stage3d_missing_vertex_stream` (kf) | `avm2_stage3d.c:4733`; coordinate with **w2-stage3d-text** |
| **S5 `w2-array-vector-args`** | join length snapshot, sort arg coercion/arity errors, Array ctor + `Error$/throwError()` native frames | `array_join_reentrant`, `vector_join_reentrant` (kf), `array_sort_arguments` (kf), `vector_sort_arguments` (kf), `array_constructor` (expect 2–3 pass, rest partial) | `avm2_array.c`, `avm2_vector.c` |
| **S6 `w2-bound-method-cache`** | per-method last-receiver bound-closure cache keyed by atom identity (ints by value, doubles boxed, strings by interned pointer) | `primitive_bound_methods` (kf), `weird_number_bound_methods` (kf) | AVM2 get-property → bind path |
| **S7 `w2-stack-trace-names`** | frame-name formatting (namespace URI, internal/private class names) + max stack depth | `error_stack_trace_class_names`, `error_stack_trace_limit` | `avm2_error.c:177` |
| **S8 `w2-doc-removal-events`** | per-child detach-then-dispatch ordering, reparent inside listeners, #2094 dispatch-recursion guard | `displayobjectcontainer_remove_reentrant`, `…_remove_reparent`, `…_removechildren_events` | `avm2_display.c:7484-7560`, `avm2_events.c` |
| **S9 `w2-avm2-small-errors`** (grab-bag, all small) | `SharedObject.getLocal` #2134; root LoaderInfo final `progress`; AMF XMLList-as-empty-object; `hitTestPoint` scrollRect | `shared_object_get_local_error`, `loaderinfo_root_progress`, `loaderinfo_root_progress_goto`, `amf_xmllist`, `hit_test_scroll_rect` | `avm2_amf.c`, `avm2_display.c` |

Fund order: **S1** (measured, mechanical) ≫ S9, S7, S5 (cheap, trace) > S4 (trace + pixel, shared
with stage3d) > S3 (one pixel + one trace, ≈400 lines) > S8, S6. Not funded: Worker (1 row), the
allow_networking `internal`/`none` variants, and the e7d71c98b re-goldens (renderer fidelity vs Flash).

---

## 6. Refutations

- **"189 extra graded rows."** It is 79 new upstream rows (4563→4642; 4689 with nested). 4752 is
  not reproducible from any results stem.
- **"`f0aa96e0c` may change our semantics."** It does not, for any graded row. All 2100 conversions
  keep their integer, `tick_rate` is unused corpus-wide, and the 7 `sleep_to_meet_frame_rate` timer
  rows still pass. The only plausible divergence is G-d `stage3d_texture`, which is unproven and
  owned by w2-stage3d-text.
- **"The CI rasterizer may have moved."** It did not. Every one of 587 intersection pixel rows is
  numerically identical except the 9 with upstream test changes. The one "move" without a PNG change
  (`edittext_underline_scale2`) is a toml `max_outliers` edit with identical pixels.
- **"`graphics_draw_path` / `avm1_color` are renderer regressions to fix."** They are not
  regressions, and not fixable by matching Ruffle. Our pixels equal Ruffle's new `output.ruffle.png`
  exactly; upstream moved the goldens to Flash and marked them `known_failure`.
- **Pricing self-attack.** Every flip in §0 was **measured**, not inferred from diff lines. The two
  ruffle_matched re-flips (`bug_564468`, `misc_errors`) are restorations of their s22 state, not
  passes.

## 7. Prototype evidence (graphics, CI-grade box; before = CI run 44922638965)

- Flipped rows: see §0 (every "Proto" cell is a measured run).
- **Canaries, all unchanged:**
  - `filereference_{browse_cancel,load,save,save_and_browse,save_and_load,uninitialized}` (pass ×6)
  - e4x: `e11_1_4`, `e9_1_1_9`, `e13_4_3`, `e13_4_4_17`, `e13_4_4_27`, `bug157735`, `e13_5_4_17`, `avm2/xml_text` (pass ×8)
  - `avm2/xml_{as_attribute,attribute,attribute_name,duplicate_attribute,equals_namespace_check,explicit_use_namespace}` (pass ×6)
  - textfield/projection: `bitmapdata_draw_cpu_overwrite_gpu` (pass + image identical),
    `edittext_{autosize_lazy_bounds_vs_relayout,getcharboundaries,scroll_event,wordwrap_word}`,
    `perspective_projection` (pass ×6)
  - `bitmapdata_colortransform` (pass; image numbers identical)
  - `stage3d_texture_bytearray_compressed_raw_alpha` (image numbers identical),
    `stage3d_context3d_string_args`
  - regression: `avm2_e4x_parse_bounded`, `avm2_bitmapdata_draw_textfield` (pass)
- `displayobjectcontainer_remove_reentrant` stays failing (runaway recursion; S8).
- Not run: no-graphics mode. No hunk touches `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms. The
  WASM build is unaffected (no new TU; `avm2_media.c` gains an `#include <utils.h>` that is already
  in the Emscripten include path via `avm2_net.c`).
- Patch notes for S1:
  - The attribute spill buffer is a static, grow-only heap block. That is safe because the AVM2 GC
    collects only between ticks (`avm2_main.c:786/872`) and children are parsed after the attribute
    pass returns.
  - The Sound fetch log is under `#if SWF_LOG_FETCH_ENABLED`, so non-`log_fetch` builds are
    byte-identical.

## New unclaimed leads

- **AVM2 twins of the w2-tf-css rows** (`avm2/textfield_{get,set}_text_format_args`,
  `avm2/edittext_set_text_same(_after_edits)`) are not in any slot's brief. Hand them to w2-tf-css
  (same family) or price them in its successor.
- `from_avmplus/e4x/XML/bug_564468` residual: caseless `<![cdata[` (avmplus accepts `<![Cdata[`);
  that would reach a full **pass** (Flash), beyond ruffle_matched.
- `from_avmplus/e4x/XML/misc_errors` residual: `missing " after attribute` should be #1095, not
  #1090. A one-error-code fix to a full pass.
- `visual/static_text_offstage` sub-mechanism (c): `BitmapData.draw` of an off-stage sprite renders
  nothing. That may affect other draw-to-bitmap rows; worth a grep by the pixel slots.
- G-d tick emulation, if w2-stage3d-text finds `stage3d_texture`'s capture frame matters.

## LOCAL ORACLE REQUESTS

none
