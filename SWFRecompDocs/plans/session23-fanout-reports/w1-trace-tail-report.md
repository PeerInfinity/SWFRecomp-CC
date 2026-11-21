# w1-trace-tail: the non-drift trace tail (session 23, wave 1)

**New files on this branch:** this report and `w1-trace-tail-prototype.patch` (388 lines, `git diff origin/master -- SWFModernRuntime SWFRecomp`,
4 runtime files). No source changes are committed; the patch is the prototype.

**Environment:**
- Cloud box. `SETUP_STATUS` is all OK (apt, Pillow, Dawn).
- Upstream Ruffle tests are at **`0ddd12b6a`** (`download_tests.sh avm1 avm2 from_gnash audio fonts`). The Ruffle source is a blobless clone at the same SHA.
- Baseline is `_results/*/results_graphics.json` on origin/master. `origin/ruffle-test-results` was last updated 2026-11-15, so the in-flight s23 baseline runs had not landed yet.
- Every run below is a single test, `--mode=graphics` unless it says otherwise, with at most `-P 2`.

---

## 0. Verdicts and priced flips

| # | Row(s) | Verdict | Flips | Cost | Evidence |
|---|---|---|---|---|---|
| 1 | `avm1/edittext_html_duplicate_attributes` (KF) | **GO S** | **+1 pass** (Flash-exact; Ruffle's sidecar differs at lines 59 and 221, so it cannot land as `ruffle_matched`) | S | Prototype: 241/247 → **247/247 PASS** in both modes. 30-row neighbour sweep unchanged |
| 2a | `from_gnash/misc-swfc.all/movieclip_destruction_test3` (KF) | **GO M** | **+1 pass** (fp10-exact) | M | Prototype: 5/18 → **18/18 PASS** in both modes. 72-row sweep: only the target rows move |
| 2b | `…/movieclip_destruction_test4` (KF) | **HOLD** | 0 now (8/40 → 38/40 lines) | +S on top of 2a | Two lines are left, with the completion mechanism in §2.4 |
| 3 | `audio/aac`, `audio/g711` | **GO M** | **+2 pass** | M (not L) | Numerical check of the G.711 path in §3. No prototype |
| 4a | `avm2/dictionary_qname_keys` (new upstream, `653ef4f41`) | **GO S/M** | **+1 pass** | S/M | Prototype: 29/45 → **45/45 PASS**. 44-row AVM2 sweep unchanged |
| 4b | `avm2/textline_metrics` | **GO M** | +1 pass | M | One mechanism: DefineFont4 typo metrics (§4.2) |
| 4c | `fonts/device_font_name_case` | **GO M** | +1 pass | M | One mechanism: the AVM1 device-font slot (§4.3) |
| 5 | `MovieClip-v8`, `globals_monkeypatch`, `GradientFillTest`, the action_order family | **NO-GO (unchanged)** | 0 | — | Line counts are byte-identical to the baseline. `globals_monkeypatch` is upstream drift (§5) |

**Total priced: +7.** Of these, **+3 are proven by prototype** (items 1, 2a and 4a). Another +4 are GO-M without a prototype: audio ×2, `textline_metrics` and `device_font_name_case`.

---

## 1. `edittext_html_duplicate_attributes`: GO S, +1 (prototyped)

**Brief premise ("one mechanism"): partly refuted.** The 6 lines come from three small mechanisms, and all three are in the patch.

| Lines | Mechanism | Owner |
|---|---|---|
| 220, 226, 236, 241 (color) | `tf_parse_html` never applies styleSheet CSS, so the TFRunTable that `getTextFormat` reads is unstyled. It also has no `<span>` arm. | `action.c` `tf_parse_html` (≈27152) and the html=true `htmlText` SetMember site (≈54611) |
| 231 (`url=http://a.example/`) | AVM1 `getTextFormat` **never copies `href` from the run**, with or without CSS. This is a corpus-wide pre-existing bug: `url` is always `""`. | `action.c` getTextFormat (≈73443) |
| 221 (`[1]` = `\r`, color=255) | `getTextFormat(i,i+1)` on a paragraph-break char skips the break marker run and falls back to field defaults. Flash returns the paragraph's format. | same |

**Prototype:**
- A static `g_tf_parse_css_styles` holds the field's `styleSheet._styles` for one `tf_parse_html` call.
- `tf_css_apply_tag()` follows Ruffle `html/text_format.rs`:
  - `<p>`, `<a>`: tag selector, then `.class`.
  - `<span>`: `.class` only.
  - The class value is taken verbatim; `tf_get_attr` already resolves a duplicated attribute to its last occurrence.
  - The selector sets color, size, bold, italic and underline.
- A `TF_TAG_SPAN` arm is added, active only when a stylesheet is set.
- `getTextFormat` copies `url` from the run when it has range args.
- A query that lands on a break marker uses the marker's own format (args form only).

**Evidence:**
- Graphics: PASS 247/247. No-graphics: PASS.
- 30-row neighbour sweep (every avm1 row whose `.as` uses getTextFormat or styleSheet, plus all `edittext_html*`): every row keeps its exact baseline status and line count. Rows covered:
  - the `edittext_html_swf6/7/8` 5377-line rows
  - `stylesheet`, `stylesheet_transform`, `edittext_stylesheet`
  - `textfield_props_swf8`
  - the failing `textfield_get_text_format_args` 87/269 and `textfield_set_text_format_args` 127/232 (unchanged)
- `known_failure = true`; `output.ruffle.txt` differs from `output.txt` at 59 and 221, so this is a Flash-correct pass.

**Wave-2 scope:** the `action.c` hunks of the patch. Re-run the 30-row list from §1 plus `regression/` text rows.

---

## 2. `movieclip_destruction_test3/4`: the s22 premise is refuted; a real mechanism was found

### 2.1 Refutations

- **"The attached chain's frame-8 scripts land AFTER the root frame-9 check" (s22 §7): refuted.** A trace instrument on `exec_sprite_frame` and `actionQueueSpriteScriptCaptured` shows the following:
  - The attached `mc1 → mc11 → mc111 → mc1111` chain runs its frame 1 at attach time (root frame 3).
  - It then **never executes another frame**.
  - No frame-8 script is ever queued, so this is not an ordering problem.
- **"The removal did happen (`mcARef.getDepth() == -32779` passes)" (s22 §7): refuted.** `mcARef` is a *separate* clip created at frame 15 (gnash `.sc` source line 130ff). `nestedMovieClip` is never removed in our run: `typeof == movieclip` and depth 10 at frame 12.
- **`MOVIECLIP_DESTRUCTION_TEST3/4_PLAN` (2026-05-19): refuted for test3.** It said "blocked on SPRITE_REWIND_IDENTITY for sprite frame DoAction firing" and "defer `removeMovieClip`". Neither is needed: test3 passes with neither.

### 2.2 Root mechanism

`ng_advance_attached_clip_playheads` (`tag.c:2045`) is the CI-mode (NO_GRAPHICS/OFFSCREEN) "PROGRESS #15" pump. It is **a counter only**: it bumps `sprite_current_frame` and `_currentframe` and never runs the attached clip's frame tags or DoActions, nor its children's timelines. Its own header (`tag.c:1990`) records "executing attached-clip frame scripts … left as a documented follow-up".

**Every attachMovie'd multi-frame clip in CI modes has a frozen timeline after frame 1.** Only its counter moves.

### 2.3 Prototype (3 env-gated parts, in the patch)

1. **`W1_ATTACH_RUN`: `w1_attached_post_order()` in `tag.c`.**
   - For each promoted attached clip, it advances the clip's real timeline. Each object is advanced alone through a 1-entry scratch display list fed to `advance_sprite_frames`, with `g_advance_defer_nested=1`.
   - The order is **children first (post-order)**. This matches Ruffle's newest-first `clip_exec_list`: a subtree built at attach instantiates parent before child, so the deepest child runs first.
   - The attached root's frames run under its own MovieClip context, because its `display_obj` has no `instance_name`.
   - Queued payload pointers are repointed through `actionQueueRebaseSpriteObjPayloads`.
   - The counter semantics (`scf` = shown frame) are converted to and from the timeline semantics (`scf` = next frame to run).
2. **`W1_UNLOAD_CHILD_FIRST`:** `removeMovieClip` queues the children's `onUnload` before the parent's, matching Flash fp10 and Ruffle `avm1_unload`.
3. **`W1_RUN_SELF_UNLOAD_ALIVE`** in `aq_dispatch_sprite_script`:
   - A clip removed by `removeMovieClip` but kept alive by **its own** `onUnload` still runs its already-queued frame action.
   - A clip whose **ancestor** was removed does not.
   - This is the fp10 rule behind `as_order "0+1+2+4+"` and `x=100`: mc1 has `onUnload` and runs `4+`; mc11 does not and its `3+` is dropped.
   - **Caveat:** it is derived from this one fixture.
     - fp9 (`output.fp9.txt`) skips both actions; the harness grades the highest-version subtest, fp10.
     - Ruffle follows fp9 here (its fp10 sidecar shows `0+1+2+` and `x=as_should_be_discarded`).
     - Without part 3, test3 lands on **`ruffle_matched` 14/18**. That is a status move from fail, but it is not Flash.

**Results** (all three flags on):

| Row | Baseline | Prototype graphics | Prototype no-graphics |
|---|---|---|---|
| `movieclip_destruction_test3` | fail 5/18 | **pass 18/18** (the trace matches `output.fp10.txt` exactly, including `actions here should not be executed`) | **pass** |
| `movieclip_destruction_test4` | fail 8/40 | fail 38/40 lines | same 2-line diff |

**Regression sweep** (all flags on, 72 rows):
- **Scope:** every avm1 and from_gnash test whose decompressed SWF contains `attachMovie` (46 rows; that is the only path that sets `attached_playable`), plus every avm1/gnash row with unload/remove/destruct in its name (26 rows).
- **Result:** every row keeps its baseline status and line count except the two targets and `globals_monkeypatch`. That one is flag-independent upstream drift (§5).
- **Rows covered** include `attachMovieLoopingTest`, `attachMovieTest`, `register_and_init_order`, `removed_clip_halts_script`, `unload*`, `MovieClip-v5..v8`, `place_and_remove_object*` and `movieclip_destruction_test1/2`.
- **Not covered:** from_shumway, timeline/misc and the games were not downloaded. Part 1 changes behaviour for every attached multi-frame clip, so wave 2 needs a graphics `full` CI run plus the `no-graphics` leg (the code sits in `NO_GRAPHICS || OFFSCREEN_RENDER` arms).

### 2.4 test4's last 2 lines: completion mechanism

The two lines are `brother6.onUnload`'s `typeof(this.mc31) == movieclip` and `this.mc31.getDepth() == -16382`.
- In Flash, a removed parent whose timeline child defines its own `onUnload` still resolves `this.mc31`, and the child keeps its unshifted depth.
- Ours resolves it to `undefined`, because the deferred-removal branch sets `mc->display_obj = NULL` (`action.c` ≈75705) and member lookup on the removed parent goes through the display object.
- **Rejected attempt:** keeping `display_obj` gives **`ruffle_matched`**, i.e. Ruffle's wrong depths (−16387) and the brother4 child left alive. That is wrong direction, and it is not in the patch.
- **Completion:** resolve a removed parent's named children through `child_mc_cache` (`child->parent == mc`, `depth != INT_MIN`) when `display_obj == NULL`. Size S. That would make the row +1, so 2a and 2b together are worth +2.

**Wave-2 scope:**
- `tag.c` (pump), `action.c` (the removeMovieClip unload order), `action_queue.c` (the dispatch keep rule).
- Remove the `getenv` gates.
- Watch the browser-WASM `advance_attached_clip_natural` path, which is separate and untouched.

---

## 3. `audio/aac`, `audio/g711`: GO M, +2 (priced; no prototype)

**Today's diff:** each `Measuring...` is followed by `TypeError: Error #1006: computeSpectrum is not a function` (aac 3/18, g711 2/6).

**What a pass needs:**
- The expected text is exact (no `approx` in `test.toml`), but the SWF self-grades with built-in tolerances:
  - amplitude within [0.95, 1.05]
  - per-sample reconstruction error < 0.025 (aac) or < 0.05 (g711)
  - L/R phasor agreement < 0.01
- **The fit is not fully phase-agnostic.** The 256-sample window spans 5.15 cycles of 444 Hz, so the fitted amplitude leaks with phase. For a perfect sine it ranges **0.974–1.026**, which passes at all 400 phases tested. Exact decode therefore always passes.
- **G.711 numerical check** (my Python decode of `tone_alaw_mono.flv` / `tone_mulaw_mono.flv`):
  - A-law and µ-law tables, 8 kHz.
  - **Linear** resampling to 44.1 kHz passes at **all 835 window positions from 200 to 900 ms**, but with a thin margin: minimum amplitude **0.953**.
  - A 16-tap windowed sinc gives 0.963. Prefer sinc, or at least cubic.
- **AAC:** libavcodec (already linked by `video_codec.c`). FLV SoundFormat 10:
  - AACPacketType 0 carries the AudioSpecificConfig, which becomes the codec extradata.
  - AACPacketType 1 carries raw frames.
  - Rates are 22.05 kHz, 44.1 kHz and 48 kHz, so resample.
  - The stereo −3 dB comes from ffmpeg's `-ac 2` upmix and is already in the encoded data, so decode faithfully and do not compensate.

**Scope:**
1. `avm2_net.c` `ns_video_tick_one` (≈2194) already walks FLV tags and **skips audio (tag 8)**. Decode the non-lookahead audio tags into a per-stream 44.1 kHz stereo float ring. Mono is duplicated to L and R.
2. Add `SoundMixer.computeSpectrum(ba, FFTMode=false, stretch=0)` to `avm2_media.c` (the SoundMixer statics are at ≈359):
   - Write 512 floats: L then R, each `ring[end-512+2i]` for i < 256.
   - This is Flash's "every second sample" stretch, which the fixture compensates for.
   - Respect ByteArray endianness.
3. Add the G.711 tables (about 40 lines).

The measurement points are 400 ms and 800 ms into a 1 s tone, so the window never lands in the AAC priming or the tail.

The work also feeds the ignored `avm2/audio_computespectrum`, which needs a Sound-object mix tap as well: out of scope.

---

## 4. New upstream rows

### 4.1 `avm2/dictionary_qname_keys` (upstream `653ef4f41`): GO S/M, +1 (prototyped)

**Mechanism:** a `QName` value in a runtime-name slot is a multiname (uri, local), not a Dictionary identity key. The exception is `in`, which keeps identity-key semantics: `namePubNs in dict` is false while `"name" in dict` is true.

There are three parts, all in `avm2_ops.c`:
1. **`dict_object_key()` (≈244) must reject QName objects.** The existing QName arm in `avm2_op_getproperty_dyn` (≈948) was being shadowed by the Dictionary arm; 9 of the 16 diff lines are this one line. This part is default-on in the patch; `W1_NO_QNAME_DICT` opts out.
2. **`in` keeps the identity lookup for a QName on a Dictionary** (`avm2_op_in` ≈4088).
3. **Error text** (`W1_QN_ERR`):
   - A single-namespace (QName or RTQNameL) miss on a *dynamic* receiver is **#1069**, not #1081. Ruffle `script_object.rs:383` picks InvalidNsRead only when `has_multiple_ns()`. Ours forces #1081 on any dynamic receiver (`ns_read = dynamic || …`, ≈723).
   - The message carries `uri::local`, so `getproperty_qname`, `setproperty_qname` (#1056) and `getproperty_rtns_l` need the qualified name.

**Result:** 29/45 → **PASS 45/45**.

**44-row AVM2 sweep** with `W1_QN_ERR` on: all `dictionary_*`, `qname_*`, `*namespace*`, `proxy_{get,set,has,delete}property`, `core_exceptions`, `catch_class` and `rtqname_not_namespace`. Every row keeps its baseline status. Two new upstream rows have no baseline: `amf_sealed_class_dynamic_properties` passes, and `xml_many_namespace_declarations` fails 1/2 with the flags off too, so it is drift.

**Risk:** part 3 changes a generic error code. Wave 2 must run `categories=full` (from_avmplus pins #1069/#1081 heavily; see the `getproperty_common` comment block about `catch_class` / `AccStatPropViaSubClass`).

### 4.2 `avm2/textline_metrics`: GO M, +1

- **Ours:** constant `ascent=12 descent=3` (`avm2_text.c:8132`, `tl_const_12` / `tl_const_3`).
- **Flash:** `size × typoAscender / upem` and `size × |typoDescender| / upem` from the embedded CFF font. TestFont.ttf has OS/2 typo 800/−200 at 1000 upem, which gives 8/2, 16/4 and 32/8. hhea and usWin would give descent 0, so the typo metrics are the ones that count.
- **The real blocker:** the recompiler has **no DefineFont4 (tag 91) handling at all**.

**Scope:**
1. Recompiler: emit a DefineFont4 table (name, bold/italic, font bytes or just the parsed metrics). `abc_devicefont.cpp:255` `readVMetrics` already implements ttf_parser's ascender/descender rules; reuse it.
2. `TextBlock.createTextLine` records the ElementFormat `fontSize` and the `fontDescription.fontName` (EMBEDDED_CFF lookup).
3. The getters compute the metric, rounded to twips like Ruffle's `to_pixels()`.

There is no `output.ruffle.txt`, so Ruffle passes this row.

### 4.3 `fonts/device_font_name_case`: GO M, +1 (AVM1 device-font slot)

- All 12 checks read `A=true, B=true`: every name measures the same width.
- **Cause:** the `[fonts.*]` test-device-font table (`avm2_generated_device_fonts`) is emitted only on the ABC path (`abc_timeline.cpp:2256` → `emitDeviceFonts`), so an AVM1 SWF gets no registry. The AVM1 `textWidth` path never consults one either.
- AVM2's `find_device_font_list` / `find_device_font_ladder` (`avm2_text.c:2704-2775`) already does Ruffle's comma-split, trim and style ladder.

**Scope:**
1. Emit the device-font table for AVM1 main movies too.
2. AVM1 text measurement (`action.c` `extractTextFieldParams` / device-font mode) resolves the TextFormat font through that lookup. The match is case-insensitive and exact: no prefix, suffix or space tolerance, and a miss goes to the default device font.
3. It then uses that face's advances.

**Sibling rows:** `device_font_glyph_fallback`, `device_font_kerning` and `device_font_list` pass today; `device_font_no_ink` is `ruffle_matched` 4/18. All four belong in the wave-2 sweep.

---

## 5. Re-confirmed NO-GOs (one run each)

| Row | Baseline | Now | Same shape? |
|---|---|---|---|
| `actionscript.all/MovieClip-v8` | fail 1035/1087 | 1035/1087 | yes (s22 §9: 7 mechanisms) |
| `misc-ming.all/GradientFillTest` | fail 123/278 | 123/278 | yes |
| `action_order/ActionOrderTest3/4/5` | 4/62, 10/64, 6/51 | identical | yes |
| `action_order/PlaceAndRemove` | 15/96 | 15/96 | yes |
| `action_order/…_extend_test` | 7/32 | 7/32 | yes |
| `action_order/…_test11` | 26/32 | 26/32 | yes |
| `action_order/…_test6` | ruffle_matched 19/24 | same | yes |
| `avm1/globals_monkeypatch` | fail 41/250 | **43/306** | **upstream drift** (see below) |

**`globals_monkeypatch`:**
- Expected went from 250 to 306 lines. Upstream modified `Test.as`, `assets.swf`, both output files and `test.toml`, and added `socket.json`. The commits are `6cc7a26a9`, `38bf3b5a3`, `92990b059`, `810ae0105`, `a6388aef4` and `147cacd6c` ("resolve X dynamically").
- The count is identical with my flags off. The NO-GO reason (built-ins must resolve `_global.*` dynamically) is, if anything, widened by upstream.
- Pricing belongs to `w1-drift-avm1`.

---

## 6. Wave-2 slots I would fund

| Slot | Files | Rows | Cost | CI |
|---|---|---|---|---|
| A: AVM1 htmlText CSS + getTextFormat url/para | `action.c` (`tf_parse_html`, getTextFormat) | `edittext_html_duplicate_attributes` **+1** | S | graphics `all` + no-graphics leg (shared code) |
| B: attached-clip natural timeline | `tag.c` pump, `action.c` removeMovieClip, `action_queue.c` | `movieclip_destruction_test3` **+1**, `_test4` +1 with §2.4 | M (+S) | graphics `full` **and** no-graphics; game spot-checks (attached HUD clips start animating) |
| C: QName multiname keys | `avm2_ops.c` | `dictionary_qname_keys` **+1** | S/M | graphics `full` (from_avmplus error codes) |
| D: NetStream audio tap + computeSpectrum | `avm2_net.c`, `avm2_media.c`, `video_codec.c` | `audio/aac`, `audio/g711` **+2** | M | graphics `full` + misc group |
| E: DefineFont4 metrics | recompiler font emission, `avm2_text.c` | `textline_metrics` +1 | M | graphics `full`, `--recompile` |
| F: AVM1 device-font registry | `abc_timeline.cpp`/`abc_devicefont.cpp` emission gate, `action.c` text measure | `device_font_name_case` +1 | M | graphics `all` + fonts/text misc + image canary |

Every slot needs a `regression/` suite check (I ran none; this is wave 1). Slot B needs a fixture for the attached-clip later-frame script from an oracle: see LOCAL ORACLE REQUESTS.

---

## New unclaimed leads

1. **Attached clips' timelines are frozen after frame 1 in CI modes** (§2.2). This is corpus-wide and game-visible:
   - Every attachMovie'd multi-frame clip's later-frame DoActions and nested animations never run.
   - Only 2 of 46 attachMovie corpus rows notice, so coverage is thin and games are the likely casualties.
   - Browser-WASM has its own one-shot `advance_attached_clip_natural`, which runs placement tags only.
2. **AVM1 `getTextFormat(i,j).url` is always `""`.** Fixed in prototype slot A.
3. **The `#1081`-on-dynamic rule (`avm2_ops.c` ≈723) is wider than Ruffle's.** Ruffle gives #1069 for single-namespace misses on dynamic objects. This goes beyond the Dictionary row (§4.1 part 3).
4. **DefineFont4 is ignored by the recompiler,** so FTE `EMBEDDED_CFF` text measures and renders with a fallback everywhere.
5. **fp9/fp10 subtests:** the harness grades the highest version.
   - `movieclip_destruction_test3`'s fp10 expectations (removed-but-alive clip runs its queued action, script continues after removing its ancestor) differ from fp9 and from Ruffle.
   - Any other `[subtests.fp9/fp10]` gnash rows may hide the same version split. Worth a census.
6. **New upstream text rows for the drift slots** (I touched them only as sweep neighbours):

| Row | Lines |
|---|---|
| `textfield_get_text_format_args` | 87/269 |
| `textfield_set_text_format_args` | 127/232 |
| `textfield_set_text_format_text_change` | 1/37 |
| `edittext_set_text_same` | 28/70 |
| `edittext_set_text_same_after_edits` | 30/98 |

All five are unchanged by my patch. Slot A's getTextFormat fixes sit in the same function, so price them together.

## LOCAL ORACLE REQUESTS

1. **Fixture for slot B** (optional; it strengthens the generic part 1 beyond one gnash row). Please provide a Ruffle exporter trace (30 ticks) for a minimal AVM1 SWF8:
   - The root attaches (`attachMovie`) a 4-frame library clip whose frames 2–4 each `trace(this._name + " f" + this._currentframe)`, and whose frame-1-placed timeline child traces its own frames 2–4 the same way.
   - What it settles: the per-tick order of child vs parent vs root frame scripts after attach, which is the post-order claim in §2.3.
   - Flash would be better than Ruffle if available, since rule 3 is Flash-only.
2. **None needed** for slots A, C, D, E or F: each fixture's expected output is Flash, and Ruffle passes C, E and F (no sidecar).
