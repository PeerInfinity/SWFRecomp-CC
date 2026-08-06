# Session 13 · wave 1 (graphics) — char-id-0 "empty depth" sentinel

**Agent:** w1-gfx-charid0 · **Date:** 2026-08-06 · **Base:** `10931d62e` (master)
**Baseline:** run `31090651530` at `1f8396f57`, pixels 286/567.
**Status:** READ-ONLY diagnosis. No repo file was edited; all experiments ran in
the scratchpad. One local `--mode=graphics` run of
`visual/video/colorconversion/h263`.

---

## 0. Verdict (read this if you read nothing else)

| claim | verdict |
|---|---|
| char-id-0 sentinel blocks all 5 embedded-video comparisons | **CONFIRMED**, mechanism traced end to end |
| `h263` "should render but comes out blank" | **CONFIRMED** — local actual render is 640×480 of **one colour** (pure white, 1 unique pixel value) |
| "~21 sites in tag.c" | **REFUTED** — **56** in `tag.c`, **122** `== 0` repo-wide, **188** counting `!= 0`. The occupied-flag refactor is *bigger* than the board priced it |
| "sentinel fix alone yields 0 flips" (my brief's own suggestion) | **REFUTED** — a sentinel fix **plus** two small, fully-characterised follow-ons yields **3 certain + 1 likely = 3–4 flips** |
| video family is "arc-sized, 21 comparisons" | **PARTLY REFUTED** — the *embedded* slice (5 cmps) is a ~1-session job; NetStream/h264/deblocking/acid stay arc-sized |

**Flip estimate for wave 2: +3 certain, +1 likely (3–4).**
`visual/video/colorconversion/vp6`, `visual/video/vp6_dispsize`,
`visual/video/vp6_alphaoffset` are **proven byte-exact** against their goldens
by offline reconstruction (0 outliers, max diff 0).
`visual/video/colorconversion/vp6a` reconstructs to max diff 1 and its
`tolerance = 1`, so it should pass too.
`visual/video/colorconversion/h263` is **NOT winnable** (decoder-level IDCT
drift; best achievable 3 outliers at `max_outliers = 0`) — it is an
ACCEPTED_DIFFS candidate with an image-axis scope marker.

Not a subtlety to skip: **the sentinel fix on its own really does yield 0
flips** — it makes 1 of 5 tests draw *something* and leaves 4 blank. The flips
come from the sentinel fix **+ VP6 codec gate + an exact YUV→RGB port**, landed
together. See §6.

---

## 1. The 5 comparisons and their current failure mode

From the merged `visual/_results/image_results_graphics.json`
(run `31090651530`, `git_sha 1f8396f57`). All 5 are `status=fail`,
`reason=pixel_mismatch`, `trace_status=pass`, `known_failure=false`:

| comparison | size | tolerance | max_outliers | outliers | max_diff | mean_diff |
|---|---|---:|---:|---:|---:|---:|
| `visual/video/colorconversion/h263` | 640×480 | 0 | 0 | 686 351 | 255 | 63.40 |
| `visual/video/colorconversion/vp6` | 640×480 | 0 | 0 | 771 570 | 255 | 63.71 |
| `visual/video/colorconversion/vp6a` | 640×480 | **1** | 0 | 731 370 | 240 | 39.24 |
| `visual/video/vp6_dispsize` | 640×480 | 0 | 0 | 771 570 | 255 | 63.71 |
| `visual/video/vp6_alphaoffset` | 976×400 | 0 | 0 | 520 506 | 255 | 39.52 |

**Failure mode measured locally, not inferred.** Running

```
python3 ruffle-tests/verify_output.py --test=video/colorconversion/h263 \
    --tests-dir=ruffle-tests/tests/swfs/visual --mode=graphics --images \
    --image-out-dir=<scratch>
```

trace-passes and exports `output.actual.png`, which is **640×480 with exactly
one unique pixel value, `(255,255,255,255)`**. Not "wrong content", not "partial
content" — nothing is drawn at all. `blank_render`, confirmed at the pixel
level. (The other four are the same class; the board already had them as
`blank_render` / `e_large`.)

The remaining video-family comparisons, for scope hygiene (23 failing across
the corpus, of which these 5 are the subject):

```
avm1  netstream_play_flv, netstream_play_flv_screen        (NetStream, codec 2/3)
avm2  netstream_play_flv, netstream_seek_flv               (NetStream, codec 2)
from_gnash/misc-ming.all  Video-EmbedSquareTest
from_shumway acid/acid-video output.10, output.20          (no_render)
visual video/deblocking                                    (12 streams, codec 2)
visual video/h264 frame2..frame11, video/h264_multinalu    (codec 7 / NetStream)
```

---

## 2. The sentinel collision — traced end to end

### 2a. What the SWFs actually contain

Parsed directly from the tag streams (scratch parser, not from any doc):

```
colorconversion/h263      DefineVideoStream id=0 640x480 flags=0x02 codec=2 ; PO2 flags=0x36 depth=1 char=0
colorconversion/vp6       DefineVideoStream id=0 640x480 flags=0x00 codec=4 ; PO2 flags=0x36 depth=1 char=0
colorconversion/vp6a      DefineVideoStream id=0 640x480 flags=0x00 codec=5 ; PO2 flags=0x36 depth=1 char=0
vp6_dispsize              DefineVideoStream id=0 640x480 flags=0x00 codec=4 ; PO2 flags=0x36 depth=1 char=0
vp6_alphaoffset           DefineVideoStream id=0 976x400 flags=0x00 codec=5 ; PO2 flags=0x36 depth=1 char=0
deblocking                DefineVideoStream id=1..12       flags=0x00 codec=2 ; PO2 flags=0x06 depth=1..12 char=1..12
```

`flags=0x36` = `HasRatio | HasName | HasMatrix | **HasCharacter**`. So these are
**Place** ops that carry `HasCharacter = 1` and `CharacterId = 0`. That is the
whole bug: SWF distinguishes *"this PlaceObject names a character"* (a flag)
from *"the character's id"* (a field), and our model collapses the two.

### 2b. Where the collapse happens — the recompiler

`SWFRecomp/src/swf.cpp:3551` reads `has_character` and `:3561-3573` reads
`char_id`, then every emission site passes **only `char_id`**:

```
swf.cpp:4469   tagPlaceObject2Ratio(app_context, depth, char_id, transform_id, cxform_id, clip_depth, ratio, is_replace)
swf.cpp:4493   tagPlaceObject2(...)
swf.cpp:5793 / 5834 / 5883   the sprite-body equivalents (5883 literally writes `has_character ? char_id : (u16)0`)
```

The runtime therefore **cannot tell the two cases apart, even in principle**.
Verified against the checked-in recompiler output:

```
ruffle-tests/tests/swfs/visual/video/vp6_dispsize/RecompiledTags/tagMain.c
  11: tagVideoFrame(app_context, 0, 0, video_data + 0, 20493);
  13: tagPlaceObject2Ratio(app_context, 1, 0, 1, 0, 0, 0, 0);   <-- char_id = 0
  37: tagDefineVideoStream(app_context, 0, 640, 480, 4);
```

### 2c. Where the collapse bites — the runtime

`tagPlaceObject2Ratio` (`tag.c:8948`) has the modify gate at `:9168`:

```c
// char_id=0 means "modify existing entry" (PlaceObject2 without HasCharacter)
if (char_id == 0 && display_list[depth].char_id != 0) { ...update-only...; return; }
```

Depth 1 is empty on the first frame, so `display_list[1].char_id == 0` and the
gate does **not** fire. Execution falls through to the full-placement block at
`tag.c:9220`, which writes `display_list[depth].char_id = char_id;` — i.e. the
slot is populated **with char_id 0**, `max_depth` is bumped, and the entry is
now bit-for-bit indistinguishable from an empty depth.

Every display-list walk then skips it. The three that matter for pixels:

| walk | line | effect |
|---|---|---|
| `tagRerenderFrame` root render loop | `tag.c:5658` `if (obj->char_id == 0) continue;` | **the blank** |
| `tagShowFrame` root render loop | `tag.c:6574` | same |
| `render_display_list` (nested/sprite) | `tag.c:3392` | same for video inside a sprite |

`render_single_object` (`tag.c:3137`) *does* have a complete video branch at
`:3143` — `ng_isVideoChar(obj->char_id)` →
`actionGetEmbeddedVideoFramePixels` → `renderer_draw_bitmap_quad_scaled`. It is
simply never reached, because the loop `continue`s one level above it. The
video registry itself is fine: `ng_record_video` /
`ng_isVideoChar` (`ng_shared.c:288/308`) key on `char_id` and happily accept 0.

**Collision CONFIRMED.** It is not a decoder problem, not a size-cap problem
(the s12 bitmapmax agent already refuted both), and not a recompiler-parsing
problem — the tags are recompiled faithfully. It is a **display-list model**
problem that starts in the recompiler ABI.

---

## 3. Sentinel-site inventory — the board's "21" is a 5× undercount

`grep -c "char_id == 0"` per file, current HEAD:

```
SWFModernRuntime/src/libswf/tag.c        56
SWFModernRuntime/src/libswf/tag_stubs.c  31     (NO_GRAPHICS twin)
SWFModernRuntime/src/actionmodern/action.c 27
SWFModernRuntime/src/avm2/avm2_display.c  4
SWFModernRuntime/src/libswf/ng_shared.c   3
SWFModernRuntime/src/avm2/avm2_main.c     1
                                        ---
                                        122
plus `char_id != 0`:                     66   (tag.c 42, action.c 6, tag_stubs 5, avm2_* 8, swf*.c 4, ...)
                                        ---
                                    TOTAL 188
```

Classified (tag.c's 56, by enclosing function — full mapping was generated,
summarised here):

- **Render / paint (3 sites, the ones that produce the blank):** `tag.c:3392`
  `render_display_list`, `:5658` `tagRerenderFrame`, `:6574` `tagShowFrame`.
- **Placement semantics (2 sites, load-bearing, must NOT change meaning):**
  `:8159` `tagPlaceObject2`, `:9168` `tagPlaceObject2Ratio` — these are the
  genuine *"HasCharacter = 0 → modify"* tests. Any occupied-flag refactor has to
  split these two specifically, and they are the only two where the sentinel is
  semantically *correct* rather than incidental.
- **Timeline / sprite advance (≈14):** `advance_sprite_frames` ×4,
  `advance_nested_sprite_frames` ×2, `advance_attached_clip_*` ×2,
  `presync_nested_*` ×2, `process_sprite_*init*` ×2, `ng_loopback_entry_survives` ×2.
- **Event dispatch (≈12):** `dispatch_enterframe_clip_actions*` ×4,
  `dispatch_clip_event_{press,release,roll,flag}_dl` ×4,
  `dispatch_button_key_actions`, `dispatch_attached_clip_enterframe`,
  `fire_entry_unloads`, `fire_eager_constructors`.
- **Naming / lookup (≈6):** `tagSetInstanceName` ×2, `findDisplayObjectByName`,
  `ng_update_button_states_in_dl`, `hasPlayingSprites`,
  `hasClipEnterFrameHandlers_impl`.
- **Geometry / hit-test (≈4):** `sprite_content_bounds_twips`,
  `find_drop_target_*` ×2, `compose_children`.
- **Misc registry/state (≈15):** `ng_construct_pending_registerclass_sprites` ×2,
  `ng_record_attached_playable`, `ng_apply_pending_sprite_self_gotos`,
  `upgrade_sprite_initialized`, `set_enterframe_eligible_recursive`,
  `ng_simulateButtonTransition`, `ng_setButtonDisplayState`, `gather_clip_ef_entries`, …

**Consequence for the fix design:** the "add a `DisplayObject.occupied` flag and
convert the sentinel sites" plan the s12 report sketched is a **188-site,
semantically-per-site** refactor across the AVM1 display list, its NO_GRAPHICS
twin, `action.c`, and the AVM2 display walk. That is 2–3 sessions of pure
regression risk on the single most load-bearing data structure in the runtime,
for **5 comparisons**. Do not do it for this. (It may still be right *someday*,
as a correctness item; it is the wrong lever for this session.)

---

## 4. The fix: alias char id 0 in the **recompiler**, don't touch the sentinel

### 4a. The decisive measurement

I scanned **all 4 949 corpus SWFs** for any use of character id 0 — every
`Define*` tag family (shape/sprite/button/text/edittext/font/bitmap/morph/
sound/binarydata/video), recursing into `DefineSprite` bodies, plus every
`PlaceObject` / `PlaceObject2` / `PlaceObject3` carrying `HasCharacter` with id
0. Result:

```
5 SWFs hit. All 5 are the video tests. In all 5 the only tag involved is
DefineVideoStream (60) + PlaceObject2 (26). Zero hits of any other kind
anywhere in the corpus.
```

So a **video-scoped alias** is complete for the entire corpus, and its blast
radius is *provably* those 5 SWFs. Nothing else in 4 949 files can observe the
change.

### 4b. The change

Give SWF character id 0 a synthetic non-zero runtime id, decided by the
recompiler, applied to the three places the id travels. The runtime's
`char_id == 0` sentinel keeps its current meaning everywhere, untouched.

Recompiler (`SWFRecomp/src/swf.cpp`), gated on `video_zero_alias != 0` so it is
a literal no-op for every other SWF:

1. `SWF_TAG_DEFINE_VIDEO_STREAM` (`~:4960-4995`): if the parsed
   `video_char_id == 0`, set `video_zero_alias = SWF_VIDEO_ZERO_ALIAS` and emit
   `tagDefineVideoStream(app_context, video_zero_alias, w, h, codec)`.
   Keep `defined_chars.insert(alias)`; also `insert(0)` is no longer needed.
2. `SWF_TAG_VIDEO_FRAME` (`~:4921-4957`): if `vf_stream_id == 0 &&
   video_zero_alias`, emit the alias — otherwise
   `actionStoreEmbeddedVideoFrame` keys frames under 0 while the display object
   asks for the alias, and you get a blank frame *after* fixing the blank
   object.
3. PlaceObject char-id read, **both** copies: main timeline `~:3563-3573` and
   sprite body `~:5291`. After the existing read, add
   `if (has_character && char_id == 0 && video_zero_alias) char_id = video_zero_alias;`.
   Put it **before** the place-before-define degrade at `:3584` (that check
   already short-circuits on `char_id != 0`, so either order works, but before
   is clearer). Do the same for `PlaceObject` (tag 4, `~:3488`) and
   `RemoveObject` (tag 5) for symmetry — neither occurs in the corpus.

Choice of alias: **`#define SWF_VIDEO_ZERO_ALIAS 0x4000` (16384)**, plus a
recompiler diagnostic if a real `Define*` ever claims that id. Rationale: it
must be (a) non-zero, (b) not a real id in the movie, (c) small enough that
growing the dictionary to cover it is free. 16385 × `sizeof(Character)` ≈
790 KB — negligible, and only for SWFs that actually use it. Do **not** pick
0xFFFF or 0x10000: the walks at `tag.c:1667`, `:1676`, `:1772`, `:5660` index
`dictionary[obj->char_id]` *unconditionally*, so an alias outside
`dictionary_capacity` is an OOB read, not a blank frame.

Runtime, one line, to make (c) true:

4. `tagDefineVideoStream` (`tag.c:11498`) currently only calls
   `ng_record_video` — it **never touches the dictionary at all** (today the
   video "uses" `dictionary[0]`, which exists because it is index 0). Add
   `ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));`
   as its first statement, matching `tagDefineSpriteEx` (`:10623`) and
   `tagDefineButton` (`:10772`). The entry stays zeroed (`CHAR_TYPE_SHAPE`,
   size 0), which is exactly what the video branch's early return at `:3143`
   assumes.

### 4c. Rejected alternatives (and why)

- **`DisplayObject.occupied` flag** — §3: 188 sites, wrong risk/reward here.
- **Pass `has_character` through the `tagPlaceObject*` ABI** — the "correct"
  model (it is exactly Ruffle's `PlaceObjectAction::{Place, Modify, Replace}`),
  but it changes the signature of 6 runtime entry points and every recompiler
  emission site, and it still requires triaging which of the 188 sentinel reads
  mean "no character" vs "empty depth". Same cost as the flag. **Note it as the
  eventual right shape; do not scope it now.**
- **Remap *every* character id by +1 globally** — touches every id-reading tag
  in the recompiler (~25 tag families, `SymbolClass`, `ExportAssets`,
  `DefineScalingGrid`, button hit ids, `DoInitAction`, sprite placement tables)
  and collides with the existing per-child-movie char-id offsetting
  (`INITIAL_DICTIONARY_CAPACITY` comment, `config.cpp:32 char_id_base`). Far more
  surface than the video-scoped alias, for zero extra corpus coverage.

---

## 5. Flip potential — measured, not estimated

This is the part the board got wrong, and it is worth reading carefully.

### 5a. Method

`video_codec.c::decode_via_libavcodec` is the only decode path. I rebuilt it
standalone in the scratchpad against the system libavcodec (60.31.102) —
same `avcodec_find_decoder` / `avcodec_send_packet` / `avcodec_receive_frame`
sequence — fed it the exact `VideoFrame` payloads extracted from the 5 SWFs,
and compared the result to the repo goldens. No repo file was modified.

### 5b. As-is (current `sws_scale` path): all 5 hopeless

Every one of the 5 payloads **decodes successfully today**, at exactly the
golden dimensions (including `vp6_alphaoffset`, whose 3-byte `OffsetToAlpha`
prefix ffmpeg handles, and `vp6_dispsize`, whose bogus display-size header
ffmpeg ignores — matching Flash and Ruffle):

```
h263            DECODED 640x480 yuv420p
vp6             DECODED 640x480 yuv420p
vp6a            DECODED 640x480 yuva420p
vp6_dispsize    DECODED 640x480 yuv420p
vp6_alphaoffset DECODED 976x400 yuva420p
```

But converted through the shipped `sws_scale(SWS_BILINEAR)` +
`sws_setColorspaceDetails(ITU601, src=limited, dst=full)` path, versus golden:

| test | outliers (>0) | share | max |
|---|---:|---:|---:|
| h263 | 392 707 | 42.6 % | 4 |
| vp6 | 449 774 | 48.8 % | 3 |
| vp6_dispsize | 449 774 | 48.8 % | 3 |

At `tolerance = 0, max_outliers = 0` that is a dead loss. **This is the number
that made the video family look A-INHERENT, and it is an artifact of
`sws_scale`, not of the decoder.**

### 5c. With Ruffle's exact BT.601 conversion: three tests go to ZERO

Ruffle converts YUV→RGBA in `h263-rs-yuv::bt601::yuv420_to_rgba`
(`~/.cargo/git/checkouts/h263-rs-a2d07b33b85627b5/b3f9055/yuv/src/bt601.rs`),
used by `ruffle_render/src/bitmap.rs:174/210/221` for **both** codecs. It is
16.16 fixed point with **nearest-neighbour chroma** (the file's own comment:
*"The `chroma_b` and `chroma_r` samples are simply reused without any
interpolation for all four corresponding pixels. This is not the most correct,
or nicest, but it's what Flash Player does."*):

```
R = clamp(((Y-16)*76309 + (Cr-128)*104597              + 32768) >> 16, 0, 255)
G = clamp(((Y-16)*76309 + (Cr-128)*(-53279) + (Cb-128)*(-25675) + 32768) >> 16, 0, 255)
B = clamp(((Y-16)*76309              + (Cb-128)*132201 + 32768) >> 16, 0, 255)
A = 255                                    (Yuv420p)
A = a_plane;  R,G,B = min(R,A), min(G,A), min(B,A)     (Yuva420p — bitmap.rs:225-230)
```

Applying that formula to **libavcodec's own decoded planes** and comparing to
the goldens:

| test | outliers (>0) | max | verdict |
|---|---:|---:|---|
| **`vp6`** | **0** | **0** | byte-exact |
| **`vp6_dispsize`** | **0** | **0** | byte-exact (golden md5 identical to `vp6`) |
| **`vp6_alphaoffset`** (premultiplied src-over on white) | **0** | **0** | byte-exact |
| **`vp6a`** (premultiplied src-over on `SetBackgroundColor #FF6699`) | 118 (0.013 %) | **1** | `tolerance = 1` → passes |
| `h263` | 10 808 (1.17 %) | 2 | **fails** |

**libavcodec's VP6F/VP6A decode is bit-identical to Ruffle's nihav VP6
decode.** The entire visible gap on three of these tests is `sws_scale`'s
chroma interpolation and rounding. That is a ~40-line replacement.

The `vp6a` 118 is my *Python* model of the GPU's premultiplied blend against
the background (rounding of `rgb + bg*(255-a)/255`); the real blend is done in
float on the GPU and may well be 0. Either way, `tolerance = 1` covers it.

### 5d. `h263` is decoder-level and not winnable

The 10 808 residual is spatially uniform over the whole frame, max 2 — the
signature of IDCT precision, not of colour. Sweeping every libavcodec
`idct_algo` (0..30 + 128, with and without `AV_CODEC_FLAG_BITEXACT`):

```
FF_IDCT_FAAN (20)   3 outliers, max 1     <- one pixel, (447,289), all 3 channels
FF_IDCT_XVID (14)   4 671
FF_IDCT_INT  (1)    8 450
everything else    10 808
```

3 outliers still fails `max_outliers = 0`. And `h263-rs`'s IDCT
(`h263/src/decoder/cpu/idct.rs`, 201 lines) is an **f32 basis-table** IDCT —
which is why FAAN (also float) gets closest, and why matching it exactly would
require replacing libavcodec's H.263 decoder wholesale, not configuring it.
**Do not ship `idct_algo = FF_IDCT_FAAN`**: a float IDCT is a determinism
hazard across CI shards with different CPU feature sets, and it buys a band
move on a test that still fails.

`h263` → **ACCEPTED_DIFFS Category 9**, with an explicit
`<!-- image-axis: visual/video/colorconversion/h263 output -->` scope marker
(the existing Category 9 entry covers `netstream_play_flv` only).

### 5e. Bonus finding — `visual/video/deblocking` (not in scope, but priced)

`deblocking` uses real char ids 1..12, so the sentinel does not touch it. I
decoded its streams and compared them against the golden at their parsed
placement offsets (integer pixel translations, so the compare is exact):

```
stream 1  (248x248 @ 4,4)     0 outliers    <- BIT-EXACT
stream 5  (248x248 @ 4,256)   0 outliers    <- BIT-EXACT
stream 2  (248x248 @ 256,4)   12 861, max 10
stream 9  (496x496 @ 4,508)   34 675, max 4
stream 12 (496x496 @ 508,1008) 321 868, max 50
```

The exact ones are the packets with the deblocker bit clear. Ruffle applies
`h263-rs-deblock::deblock()` post-decode when
`VideoDeblocking::Level1 || (UseVideoPacketValue && PictureOption::USE_DEBLOCKER)`
(`ruffle/video/software/src/decoder/h263.rs:81-90`); libavcodec does not do the
same thing. So `deblocking` needs: (a) the `DefineVideoStream` **flags byte**
plumbed — the recompiler reads `cur_pos[9]` for the codec and **discards
`cur_pos[8]` entirely** (`swf.cpp:4979`); (b) a port of the 559-line
`deblock.rs` + `QUANT_TO_STRENGTH`; (c) the per-picture quantizer, which
libavcodec does not expose (parse it from the H.263 header ourselves). Also
independently blocked by `MAX_EMBEDDED_VIDEO_STREAMS = 8`
(`action.c:3416`) while the test has **12** streams — streams 9-12 are silently
dropped, which is exactly why the board classified it `missing_element`.
**Not a wave-2 item.** Raising the cap to 16 is a 1-line band improvement.

---

## 6. Wave-2 brief

**Title:** `w2-gfx-charid0` — embedded-video display + exact YUV.
**Expected flips: 3 certain, 1 likely.** Runtime + recompiler, so the worktree
needs a cmake rebuild **and** `--recompile` on first use of any copied test dir
(playbook §5 + the s10 w2-button trap).

### 6a. Change list

| # | file | function / line | change |
|---|---|---|---|
| 1 | `SWFRecomp/src/swf.cpp` | `SWF_TAG_DEFINE_VIDEO_STREAM` ~`:4960-4995` | if id 0 → `video_zero_alias = 0x4000`; emit alias |
| 2 | `SWFRecomp/src/swf.cpp` | `SWF_TAG_VIDEO_FRAME` ~`:4921-4957` | remap `vf_stream_id == 0` → alias |
| 3 | `SWFRecomp/src/swf.cpp` | PO2/PO3 char-id read `:3563-3573` **and** sprite copy `:5291` | `if (has_character && char_id == 0 && video_zero_alias) char_id = video_zero_alias;` |
| 4 | `SWFRecomp/src/swf.cpp` | tag 4 / tag 5 char-id reads (`~:3488`) | same remap, symmetry only |
| 5 | `SWFRecomp/src/swf.cpp` | near `:1032` (`BITMAP_HIGHEST_W/H`) | emit `#define VIDEO_HIGHEST_W/H` = max declared `DefineVideoStream` dims (0 if none) |
| 6 | `SWFModernRuntime/src/libswf/tag.c` | `tagDefineVideoStream` `:11498` | add `ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));` |
| 7 | `SWFModernRuntime/src/libswf/swf.c` | `~:1635-1644` | raise `dynamic_bitmap_max_w/h` from `VIDEO_HIGHEST_W/H` (same shape as the `getDataFilesMaxImageDims` raise). **Gate on `VIDEO_HIGHEST_W > 0`** |
| 8 | `SWFModernRuntime/src/actionmodern/video_codec.c` | `video_codec_supported` `:31-42` | `case 4:` → `avcodec_find_decoder(AV_CODEC_ID_VP6F) != NULL`; `case 5:` → `AV_CODEC_ID_VP6A` |
| 9 | `SWFModernRuntime/src/actionmodern/video_codec.c` | `decode_via_libavcodec` `:88-119` | **replace `sws_getContext`/`sws_setColorspaceDetails`/`sws_scale` with the §5c integer conversion.** Nearest chroma (`cb[(y>>1)*cw + (x>>1)]`); honour `frame->linesize[i]`; `AV_PIX_FMT_YUVA420P` → alpha from plane 3 with the `min(rgb, a)` clamp; else `A = 255`. Keep `sws_scale` in `video_resample_rgba` (src≠dst path only) |
| 10 | `SWFModernRuntime/src/actionmodern/action.c` | `:3416` | `MAX_EMBEDDED_VIDEO_STREAMS` 8 → 16 (band move on `deblocking`; free) |

Notes for the implementer:
- Item 9 is the **flip-bearing** change. The right-shift must be arithmetic on a
  signed 32-bit intermediate (`int32_t`); if you want to be pedantic about
  C's implementation-defined `>>` on negatives, use a floor-div helper.
- Item 7 matters more than it looks: without it,
  `render_webgpu.c:2350` (`if (src_w > ctx->dynamic_bitmap_max_w ...) return;`)
  drops a 640×480 frame against the AVM1 default of **256×256**
  (`render_webgpu.c:1111`) and you get a blank frame *after* fixing the
  sentinel. **Gate it on video presence** — `dynamic_bitmap_max_w/h` feeds
  `bitmap_highest_w/h` at `render_webgpu.c:1219-1230`, which sets the texture
  array's padded dimensions, which the shader's UV normalisation divides by.
  Raising it unconditionally changes **every** bitmap render in the corpus.
  This is the one line in the whole patch that can cause a corpus-wide
  regression.
- Item 6 must land with item 1; without it the walks that index
  `dictionary[obj->char_id]` unconditionally (`tag.c:1667/1676/1772/5660`) read
  past the 8192-entry initial allocation.
- The video render branch is inside `#ifdef OFFSCREEN_RENDER`
  (`tag.c:3140`). Browser-WASM video stays unrendered — out of scope, worth a
  one-line note in the report.

### 6b. Expected-flip ledger

| comparison | before | after | confidence |
|---|---|---|---|
| `visual/video/colorconversion/vp6` | fail 771 570 | **pass** | HIGH — 0 outliers reconstructed |
| `visual/video/vp6_dispsize` | fail 771 570 | **pass** | HIGH — 0 outliers reconstructed |
| `visual/video/vp6_alphaoffset` | fail 520 506 | **pass** | HIGH — 0 outliers reconstructed |
| `visual/video/colorconversion/vp6a` | fail 731 370 | **pass** | MEDIUM — max diff 1, `tolerance = 1`; risk is GPU blend rounding |
| `visual/video/colorconversion/h263` | fail 686 351 | fail, band ↓↓ (63.4 → ~0.01 mean) | expected NON-flip; document |
| `visual/video/deblocking` | fail 3 243 005 | fail, band ↓ | expected NON-flip (streams 9-12 now decode) |
| `avm1/netstream_play_flv`, `avm2/netstream_play_flv`, `avm2/netstream_seek_flv` | fail | fail, band ↓ | codec-2 NetStream tests share the conversion change |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | fail | unknown, likely band ↓ | not analysed |
| `from_shumway/acid/acid-video output.10/.20` | `no_render` | unchanged expected | not analysed |

Residual GPU-path risks that the reconstruction could not cover (all cheap to
check on the first local A/B): the quad's inverse-matrix scale is
`src_w / (dst_w * 20.0f)` = 0.05, not exactly representable in binary float, so
edge texels are the place to look if a test lands at 1-2 outliers; the sampler
is Nearest + ClampToEdge (`render_webgpu.c:2363` and the sampler desc), which is
what makes a 1:1 draw exact in the first place; `quality = "low"` on all 5 →
`MSAA_SAMPLES == 1`, so no AA fringe.

### 6c. Canary set

Standing `render_canary_tests.txt` (20 tests / 37 comparisons) — **all 37 must
be md5-identical**. Items 1-6 and 8-10 cannot touch a non-video SWF (§4a proves
no other corpus SWF uses char id 0; items 8/9 are inside video decode). Item 7
is the exception and is the whole reason the canary is mandatory: if any canary
row moves, item 7's gate is wrong.

Additional, beyond the standing set (must be captured before/after by hand):

```
visual/video/colorconversion/{h263,vp6,vp6a}   visual/video/{vp6_dispsize,vp6_alphaoffset,deblocking}
avm1/netstream_play_flv   avm1/netstream_play_flv_screen
avm2/netstream_play_flv   avm2/netstream_seek_flv
from_gnash/misc-ming.all/Video-EmbedSquareTest
```

Trace side: the `netstream_*` trace tests currently pass and must stay passing
(`netstream_play_flv` is in `ignored_tests.txt` for its *image* only). Run the
standard stash-diff sweep over `netstream*` + `video*` + the `regression` suite.

### 6d. Docs to update at closeout

- `ACCEPTED_DIFFS.md` Category 9: extend to
  `visual/video/colorconversion/h263` and `visual/video/deblocking` with
  `<!-- image-axis: ... -->` scope markers and the measured numbers from §5d/§5e
  (so `image_triage.py` stops ranking them).
- `ruffle-tests/ignored_tests.txt`: add the two above *only* if their trace
  tests fail — they currently pass, so probably not.
- `SWFRecompDocs/plans/video-codec-support-plan.md`: mark Phase B done, and
  record that Phase B turned out to be a **colour-conversion** job rather than
  a decoder job (the plan's own risk register has this backwards).
- `graphics-fanout-playbook.md` §11 lead list: strike "char-id-0 depth
  sentinel (21 tag.c sites)"; replace with the §3 site count and the §4 alias
  design, and re-price "video (21)" as "16 arc-sized + 5 landed".

---

## 7. Premises attacked

1. **"~21 sites in tag.c"** → 56 in `tag.c`, 122 repo-wide, 188 with the
   `!= 0` complement. The occupied-flag plan is 2-3× the board's estimate.
2. **"Embedded video placement uses char id 0 in a way that collides"** →
   confirmed, and narrowed to a precise ABI defect: the recompiler discards
   `HasCharacter` and the runtime has no way to recover it.
3. **"Sentinel fix alone yields 0 flips; what else is needed?"** → the
   *sentinel* fix alone does yield 0 flips, but the honest answer to "what else"
   is much smaller than expected: two changes (VP6 codec gate + exact YUV
   conversion), both ~40 lines, and the family flips 3-4.
4. **"Do we decode h263? If no decoder exists, say so."** → we decode **all
   four** relevant codecs today (2/4/5 verified end-to-end; 7 maps to H264).
   Codec 4/5 are gated *off* in `video_codec_supported`, not missing.
5. **ACCEPTED_DIFFS Category 9's framing** ("different fixed-point arithmetic
   internally… 1-3 levels in solid regions") is **wrong for VP6 and partly wrong
   for Spark**. VP6 is bit-exact; Spark is bit-exact except for IDCT precision
   and the missing deblock filter. The 1-3 level drift the entry describes is
   `sws_scale`, which the entry never names. Correct it at closeout.
6. **The s12 board's `deblocking` classification** ("`missing_element`,
   12 streams, codec 2 → decoder gap") → the missing elements are streams 9-12,
   dropped by `MAX_EMBEDDED_VIDEO_STREAMS = 8`. Different bug, one line.

## 8. Reproduction

Scratchpad artifacts (not in the repo):
`scratchpad/swftags.py` (tag dump), `scratchpad/scan0.py` (corpus char-id-0
scan), `scratchpad/probe.c` (shipped decode path), `scratchpad/probe2.c` /
`probe3.c` (plane dump + `idct_algo` sweep), `scratchpad/*.payload|.yuv|.raw`.
The conversion comparisons are ~30 lines of numpy over the dumped planes and
the repo goldens; all numbers in §5 are reproducible from those five files plus
`pkg-config --libs libavcodec libswscale libavutil`.
