# Session 13 · wave 2 (graphics) — `w2-gfx-video`

Embedded-video char-id-0 alias + exact BT.601 YUV→RGB.

**Agent:** w2-gfx-video · **Date:** 2026-08-06 · **Base:** `10931d62e` (master)
**Worktree:** `.claude/worktrees/agent-ac4817c30fbcb3617` · **No commit made.**
**Design authority:** `SWFRecompDocs/plans/session13-fanout-reports/wave1-gfx-charid0.md`

---

## 0. Headline

**4 of 5 embedded-video image comparisons flip to pass locally, three of them
byte-exact (0 outliers, max diff 0).** The fifth (`h263`) moves from
"blank white stage" to "correct picture with sub-visible IDCT drift":
686 351 outlier channels / max 255 / mean 63.40 → **10 808 / max 2 /
mean 0.0105**. It still fails at `max_outliers = 0` and is not winnable at the
colour layer — ACCEPTED_DIFFS material, exactly as wave 1 priced it.

| comparison | before (CI run `31090651530`) | after (local `--mode=graphics`) | verdict |
|---|---|---|---|
| `visual/video/colorconversion/vp6` | fail · 771 570 outliers · max 255 | **pass** · 0 outliers · max **0** | **FLIP** |
| `visual/video/vp6_dispsize` | fail · 771 570 · max 255 | **pass** · 0 · max **0** | **FLIP** |
| `visual/video/vp6_alphaoffset` | fail · 520 506 · max 255 | **pass** · 0 · max **0** | **FLIP** |
| `visual/video/colorconversion/vp6a` | fail · 731 370 · max 240 | **pass** · 0 outliers · max **1** (tolerance 1) | **FLIP** |
| `visual/video/colorconversion/h263` | fail · 686 351 · max 255 · mean 63.40 | fail · 10 808 · max 2 · mean **0.0105** | band ↓↓, expected non-flip |

The three max-diff-0 results are byte-exactness claims, which is the sanctioned
exception to "never grade a local render against a repo golden" — a 0/0 match
cannot be a local-Dawn-vs-lavapipe artifact. `vp6a`'s max diff 1 sits under its
own `tolerance = 1`, so its verdict is renderer-rounding-insensitive at 1 level
but not at 2; that is the one target with residual CI risk.

---

## 1. What changed (5 files, +~200 / −~30)

Patch: `w2-gfx-video.patch` (`git diff` against `10931d62e`).

### Recompiler — the char-id-0 alias

`SWF_TAG_PLACE_OBJECT_2/3` carrying `HasCharacter` with `CharacterId = 0`
populates a display-list depth with `char_id == 0`, which is the runtime's
"this depth is empty" sentinel (188 read sites). Every render walk then skips
it, and the stage stays blank. Wave 1 refuted the occupied-flag refactor
(56 sites in `tag.c` alone) and proposed a video-scoped alias instead. That is
what is implemented.

| # | file | change |
|---|---|---|
| 1 | `SWFRecomp/include/swf.hpp` | new members `VIDEO_ZERO_ALIAS = 0x4000`, `video_zero_alias`, `video_highest_w/h`, with the rationale comment |
| 2 | `SWFRecomp/src/swf.cpp` `SWF_TAG_DEFINE_VIDEO_STREAM` | id 0 → set `video_zero_alias`, emit the alias; warn if a real stream ever claims `0x4000`; track `video_highest_w/h` |
| 3 | `SWFRecomp/src/swf.cpp` `SWF_TAG_VIDEO_FRAME` | remap `vf_stream_id == 0` → alias, so frame storage is keyed under the id the display object asks for |
| 4 | `SWFRecomp/src/swf.cpp` PO2/PO3 root timeline | `if (has_character && char_id == 0 && video_zero_alias) char_id = video_zero_alias;`, placed **before** the place-before-define degrade |
| 5 | `SWFRecomp/src/swf.cpp` PO2/PO3 sprite body | same remap |
| 6 | `SWFRecomp/src/swf.cpp` `SWF_TAG_PLACE_OBJECT` (tag 4) | same remap (symmetry; no corpus SWF hits it). `RemoveObject` needed nothing — it discards `char_id` |
| 7 | `SWFRecomp/src/swf.cpp` constants header | emit `VIDEO_HIGHEST_W` / `VIDEO_HIGHEST_H` (0 when the movie has no `DefineVideoStream`) |

**Blast radius, quoted not re-measured.** Wave 1 scanned all 4 949 corpus SWFs
— every `Define*` family (shape/sprite/button/text/edittext/font/bitmap/morph/
sound/binarydata/video), recursing into `DefineSprite` bodies, plus every
`PlaceObject{,2,3}` carrying `HasCharacter` — for any use of character id 0.
**5 SWFs hit; all 5 are these video tests; the only tags involved are
`DefineVideoStream` (60) and `PlaceObject2` (26); zero hits of any other kind
anywhere in the corpus.** That scan was not repeated here (expensive). Every
one of hunks 3–6 is additionally gated on `video_zero_alias != 0`, which is
only ever set by a `DefineVideoStream` whose id is 0 — so for 4 944 of 4 949
SWFs the recompiler's emitted C differs from HEAD's by exactly the two new
`#define VIDEO_HIGHEST_{W,H} 0` lines in `constants.h`, which nothing reads.

Tag ordering was verified for all 5 targets before relying on the single-pass
alias: `DefineVideoStream` precedes both the `VideoFrame` and the
`PlaceObject2` in the tag stream of every one of them, and the emission lands
in `tagInit()`, which runs before `frame_0`.

```
h263            60(id=0) 26(flags=0x36 depth=1 char=0) 61(stream=0 frame=0) 1 0
vp6             69 60(id=0) 61(stream=0 frame=0) 26(flags=0x36 depth=1 char=0) 1 0
vp6a            69 60(id=0) 61(stream=0 frame=0) 9 26(flags=0x36 depth=1 char=0) 1 0
vp6_dispsize    69 60(id=0) 61(stream=0 frame=0) 26(flags=0x36 depth=1 char=0) 1 0
vp6_alphaoffset 69 60(id=0) 26(flags=0x36 depth=1 char=0) 61(stream=0 frame=0) 1 0
```

Alias value `0x4000` (16384): non-zero, not a real id in any corpus movie, and
small enough that growing the dictionary to reach it is ~790 KB and happens
only for SWFs that use it. Deliberately **not** `0xFFFF` / `0x10000`: several
walks index `dictionary[obj->char_id]` unconditionally, so an id outside
`dictionary_capacity` would be an OOB read rather than a blank frame.

### Runtime

| # | file | change |
|---|---|---|
| 8 | `SWFModernRuntime/src/libswf/tag.c` `tagDefineVideoStream` | add the missing `ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character))`. It previously never touched the dictionary at all — the video "used" `dictionary[0]`, which exists only because it is index 0. **Must land with the alias**: `0x4000` is past the 8192-entry initial allocation |
| 9 | `SWFModernRuntime/src/libswf/swf.c` | guarded `#include "constants.h"` + a **video-gated** raise of `dynamic_bitmap_max_{w,h}` from `VIDEO_HIGHEST_W/H` (capped 2048), placed next to the existing `getDataFilesMaxImageDims` raise |
| 10 | `SWFModernRuntime/src/actionmodern/video_codec.c` | `video_codec_supported`: enable codec 4 (`AV_CODEC_ID_VP6F`) and 5 (`AV_CODEC_ID_VP6A`) |
| 11 | `SWFModernRuntime/src/actionmodern/video_codec.c` | new `yuv420_frame_to_rgba_bt601()`; both decode paths (one-shot `decode_via_libavcodec` and persistent `video_decoder_decode`) use it for `AV_PIX_FMT_YUV420P` / `YUVA420P`. `sws_scale` is kept as the fallback for any other decoded pixel format, and untouched in `video_resample_rgba` |

**Item 9 is the one line in the patch that could regress the corpus, and its
gate is load-bearing.** `dynamic_bitmap_max_{w,h}` feeds
`render_webgpu.c:1219-1230`, which sets the bitmap texture array's *padded*
dimensions, which the shader's UV normalisation divides by — raising it
unconditionally shifts every bitmap render in the corpus. `VIDEO_HIGHEST_W/H`
are recompiler-emitted per-SWF and are `0` for every movie without a
`DefineVideoStream`, so the raise is inert everywhere else. Without it,
`render_webgpu.c:2350` (`if (src_w > ctx->dynamic_bitmap_max_w) return;`) drops
a 640×480 frame against the AVM1 default of 256×256 and you get a blank frame
*after* fixing the sentinel.

### The conversion (item 11) — why this is the flip-bearing change

Ported verbatim from Ruffle's `h263-rs-yuv::bt601`
(`~/.cargo/git/checkouts/h263-rs-*/yuv/src/bt601.rs`), which
`ruffle_render/src/bitmap.rs` uses for **both** the Spark and the VP6 decoders:

```
R = clamp(((Y-16)*76309 + (Cr-128)*104597                  + 32768) >> 16, 0, 255)
G = clamp(((Y-16)*76309 + (Cr-128)*(-53279) + (Cb-128)*(-25675) + 32768) >> 16, 0, 255)
B = clamp(((Y-16)*76309                  + (Cb-128)*132201 + 32768) >> 16, 0, 255)
A = 255                                            (Yuv420p)
A = a_plane[x];  R,G,B = min(R,A), min(G,A), min(B,A)   (Yuva420p)
```

Two properties `sws_scale` does not have and cannot be configured into:

* **nearest-neighbour chroma** — one Cb/Cr sample reused verbatim for all four
  corresponding luma pixels (`cb[(y>>1)*cbls + (x>>1)]`). bt601.rs's own
  comment: *"This is not the most correct, or nicest, but it's what Flash
  Player does."* swscale interpolates.
* 16.16 fixed point with a `+32768` round and the reduced→full range expansion
  folded into the coefficients.

`frame->linesize[i]` is honoured on every plane. The right shift is applied
only to non-negative intermediates (`r = (r < 0) ? 0 : (r >> 16)`), so the port
never relies on C's implementation-defined `>>` on negatives — a negative
numerator can only clamp to 0 anyway, so this is exactly Ruffle's
`clamp(arith_shr(v,16), 0, 255)`.

The `min(rgb, a)` clamp matches `bitmap.rs`'s *"RGB components need to be
clamped to alpha to avoid invalid premultiplied colors"*, which is what the
renderer's bitmap-quad path expects (`render_webgpu.c`: "Keep premultiplied —
renderer uses premultiplied alpha blend mode").

The old shipped path was `sws_scale(SWS_BILINEAR)` +
`sws_setColorspaceDetails(ITU601, src=limited, dst=full)`. That put ~48 % of
the channels of every embedded-video frame 1–3 levels off the golden — visually
identical, dead at `tolerance = 0`. **That, not the decoder, is what made the
whole video family look A-INHERENT.** libavcodec's VP6F/VP6A decode is
bit-identical to Ruffle's nihav VP6 decode; the entire visible gap on three of
these tests was the colour conversion.

---

## 2. Per-target results

All runs: `python3 ruffle-tests/verify_output.py --test=… --tests-dir=ruffle-tests/tests/swfs/visual --mode=graphics --recompile`,
local Dawn at `~/CC/dawn-install`, in the worktree with the freshly cmake-built
recompiler. Test dirs `cp -r`'d from the main repo (never pointed at it).

| test | trace | image status | outliers | max diff | mean diff |
|---|---|---|---:|---:|---:|
| `video/colorconversion/vp6` | pass | **pass** | 0 (limit 0) | 0 | 0 |
| `video/vp6_dispsize` | pass | **pass** | 0 (limit 0) | 0 | 0 |
| `video/vp6_alphaoffset` | pass | **pass** | 0 (limit 0) | 0 | 0 |
| `video/colorconversion/vp6a` | pass | **pass** | 0 (limit 0) | 1 (tol 1) | — |
| `video/colorconversion/h263` | pass | fail | 10 808 (limit 0) | 2 | 0.0105 |

`h263` residual histogram over all 1 228 800 channels:
`{0: 1 217 992, 1: 8 695, 2: 2 113}`. Spatially uniform across the frame, max
2 — the signature of IDCT precision, not colour. It reproduces wave 1's offline
reconstruction (10 808 / max 2) exactly, which is independent confirmation that
the shipped GPU path now matches the reference conversion bit-for-bit and that
everything left is inside libavcodec's H.263 decoder.

Wave 1 swept every libavcodec `idct_algo`: `FF_IDCT_FAAN` gets to 3 outliers /
max 1, still failing `max_outliers = 0`, and a float IDCT is a determinism
hazard across CI shards with different CPU feature sets. **Not shipped.**
Matching `h263-rs`'s f32 basis-table IDCT would mean replacing libavcodec's
H.263 decoder wholesale.

Browser-WASM note: the video render branch is inside `#ifdef OFFSCREEN_RENDER`
(`tag.c:3140` / `:3472`), so browser-WASM video stays unrendered. Unchanged by
this patch, out of scope.

---

## 3. Canary ledger

### 3.1 Standing render canary — **21 tests / 38 comparisons, ALL md5-IDENTICAL**

```
RENDER CANARY  before=before  after=after   21 tests / 38 comparisons
  IDENTICAL    38
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

| test | cmps | verdict |
|---|---:|---|
| `avm1/color` | 1 | IDENTICAL |
| `avm1/bitmap_data_fillrect` | 1 | IDENTICAL |
| `avm1/mask_with_drawing` | 1 | IDENTICAL |
| `avm1/movieclip_setmask` | 1 | IDENTICAL |
| `avm1/edittext_tag_indent` | 1 | IDENTICAL |
| `avm1/focusrect_swf5` | 12 | IDENTICAL |
| `avm1/bitmapdata_applyfilter_colormatrix` | 1 | IDENTICAL |
| `avm2/blend_multiply_alpha` | 1 | IDENTICAL |
| `visual/simple_shapes/winding_rule` | 1 | IDENTICAL |
| `visual/cache_as_bitmap/shape_changed` | 1 | IDENTICAL |
| `from_shumway/timeline/timeline_as2_5` | 7 | IDENTICAL |
| `from_shumway/acid/acid-gradient-0` | 1 | IDENTICAL |
| `regression/avm2_timeline_stroke_gradient` | 1 | IDENTICAL |
| `regression/avm2_timeline_gradients` | 1 | IDENTICAL |
| `regression/mask_sibling_union` | 1 | IDENTICAL |
| `visual/simple_shapes/masks` | 1 | IDENTICAL |
| `visual/simple_shapes/gradients/gradients` | 1 | IDENTICAL |
| `visual/filters/drop_shadow` | 1 | IDENTICAL |
| `visual/filters/color_matrix` | 1 | IDENTICAL |
| `visual/blend_modes/multiply` | 1 | IDENTICAL |
| `regression/avm2_morph` | 1 | IDENTICAL |

**This canary was run the strict way, not the cheap way.** Both legs used
`--recompile` AND a *separately cmake-rebuilt recompiler binary* — the `before`
leg was captured after `git stash`-ing all five files and rebuilding `SWFRecomp`
from pristine sources, the `after` leg after restoring and rebuilding again. So
it A/Bs the recompiler emission *and* the runtime together, which is exactly
what the item-9 `dynamic_bitmap_max` gate needs: **if that gate were wrong,
every bitmap-bearing canary row would have moved, because the padded texture
dimensions feed the shader's UV divisor.** None moved.

The `after` leg ran 10× faster (153 s vs 1447 s) purely because ccache is
content-keyed: only the three edited runtime `.c` files missed per test, while
`action.c` and everything else hit the cache the `before` leg had just
populated. Mode-1 (stale recompiler output) is ruled out independently —
`ruffle-tests/tests/swfs/avm1/color/RecompiledTags/constants.h` carries the new
`#define VIDEO_HIGHEST_W 0` / `_H 0`, so the after leg's generated C really did
come from the rebuilt binary.

### 3.2 Video-adjacent trace + band checks (beyond the standing set)

Baseline = merged CI `results_graphics.json` / `image_results_graphics.json`,
run `31090651530` at `1f8396f57`.

| test | trace before | trace after | image before (CI) | image after (local) |
|---|---|---|---|---|
| `avm1/netstream_play_flv` | pass | **pass** | 52 400 out · max 64 · mean 0.132 | 1 654 out · max 8 · **band ↓↓** |
| `avm1/netstream_play_flv_screen` | pass | **pass** | 44 751 out · max 235 | 44 751 · max 235 · **unchanged** (codec 3 ScreenVideo, hand-rolled decoder, not touched — correct) |
| `avm2/netstream_play_flv` | output_mismatch | **output_mismatch** | 229 724 out · max 255 | 229 724 · max 255 · unchanged |
| `avm2/netstream_seek_flv` | output_mismatch | **output_mismatch** | 40 943 out · max 255 | 40 943 · max 255 · unchanged |
| `visual/video/deblocking` | pass | **pass** (no crash) | 3 243 005 out · mean 56.2982 | 2 906 999 out · mean 56.2435 · band ↓ |

Zero trace-status movement. The two `avm2` netstream rows landing on
*byte-identical* outlier counts to CI's is a useful side-signal that local Dawn
and CI lavapipe agree on these frames.

`deblocking` improved slightly *without* the stream-cap raise: its 8 decodable
streams now go through the exact conversion. The remaining gap is streams 9–12
being dropped plus the missing deblock filter (§6.1).

---

## 4. Expected CI movement

Pixel axis (`images=true` run):

| comparison | before | expected after | confidence |
|---|---|---|---|
| `visual/video/colorconversion/vp6` | fail | **pass** | HIGH — local 0 outliers / max 0 |
| `visual/video/vp6_dispsize` | fail | **pass** | HIGH — local 0 / 0 |
| `visual/video/vp6_alphaoffset` | fail | **pass** | HIGH — local 0 / 0 |
| `visual/video/colorconversion/vp6a` | fail | **pass** | MEDIUM — local max diff 1 against `tolerance = 1`; a lavapipe-vs-Dawn 1-level move in the premultiplied blend against the `#FF6699` background would break it |
| `visual/video/colorconversion/h263` | fail 686 351 / mean 63.40 | fail 10 808 / mean 0.0105 | band ↓↓ — a large mean-diff improvement on a still-failing row |
| `visual/video/deblocking` | fail 3 243 005 / mean 56.2982 | fail 2 906 999 / mean 56.2435 | small band ↓, **measured** — its char ids are 1..12 so the alias never fires, but it shares the conversion |
| `avm1/netstream_play_flv` | fail 52 400 / max 64 | fail 1 654 / max 8 | band ↓↓, **measured** |
| `avm1/netstream_play_flv_screen` | fail 44 751 / max 235 | unchanged | **measured** — codec 3 ScreenVideo has its own decoder |
| `avm2/netstream_play_flv`, `avm2/netstream_seek_flv` | fail | unchanged | **measured** — these fail before the frame reaches the conversion |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | fail 189 / max 255 / tol 5 | unknown | not measured |
| `from_shumway/acid/acid-video output.10/.20` | `no_render` | unchanged | not analysed |

**Net expected pixel-axis movement: +4 (286/567 → 290/567, 50.4 % → 51.1 %),
plus a large band improvement on `h263` and probable band moves on the four
NetStream rows.**

Trace axis: **no expected movement.** No trace-visible surface changes — the
alias is invisible to ActionScript (`_root.video` still resolves by instance
name, which `tagSetInstanceName` sets by depth, not by char id), and the
conversion only affects decoded pixels. `video_codec_supported` returning 1 for
codecs 4/5 changes `NetStream`/`Video` behaviour only in that VP6 streams now
actually decode.

CI dispatch recommendation: `mode=graphics`, `categories=all` for the trace
gate; the pixel claims need a deliberate `images=true` run.

---

## 5. Merge risks

1. **Sibling conflicts.** My `tag.c` touch is a single 9-line insertion at
   `tagDefineVideoStream` (~`:11498`), far from the setMask paint loops and
   from `action.c:~34563`. `action.c` is **not** touched at all.
   `avm2_render_node` is not touched. `swf.c` touch is two hunks near the top
   include block and `swfStart`'s bitmap-sizing block (~`:1644`). Textual
   conflict risk: low.
2. **`vp6a` at tolerance 1.** The only target whose pass depends on a
   1-level margin. If CI's lavapipe rounds the premultiplied src-over against
   the `SetBackgroundColor #FF6699` stage differently by one level *in the same
   direction*, it fails. The other three have a 0-level margin, so they are
   insensitive to rasteriser rounding of the video quad itself (Nearest +
   ClampToEdge, `quality = "low"` → `MSAA_SAMPLES == 1`, no AA fringe).
3. **`ENSURE_SIZE` in `tagDefineVideoStream`.** New allocation on a path that
   previously did none. It runs once per `DefineVideoStream` at `tagInit` time,
   uses the standard `grow_ptr` macro that every other `tagDefine*` uses, and
   for the 5 alias SWFs grows the dictionary from 8192 to ≥16385 entries
   (~790 KB via HALLOC). Non-alias video SWFs (`deblocking`, ids 1..12) hit an
   already-sufficient capacity and the macro is a no-op.
4. **`#include "constants.h"` in `swf.c`.** Guarded with
   `__has_include`, so a stale `RecompiledTags/` from before the
   `VIDEO_HIGHEST_*` emission still builds (the raise is additionally
   `#if defined(VIDEO_HIGHEST_W)`-guarded). No other translation unit is
   affected.
5. **`sws_scale` is still linked** — `video_resample_rgba` and the non-4:2:0
   fallback still use it, so `SWS_DST_SLACK` and the libswscale dependency stay
   as-is. The known libswscale over-write (crash-capture run `30309564809`) is
   no longer reachable from the embedded-video decode path at all, which is a
   small robustness bonus.
6. **Recompiler ABI unchanged.** No `tagPlaceObject*` signature changed; the
   alias is entirely inside the recompiler's own bookkeeping. The "right" fix
   long-term is to pass `has_character` through the ABI (Ruffle's
   `PlaceObjectAction::{Place, Modify, Replace}`) — noted, not scoped.
7. **Trace-axis risk: none identified.** `video_codec_supported` now returns 1
   for codecs 4/5, so `NetStream`/`Video` objects fed VP6 will decode where they
   previously no-op'd. That can only change *pixels*; no trace surface reads it.
   The four netstream trace tests and `deblocking` were re-run and hold their
   baseline statuses (§3.2).

### 5b. PROCESS WARNING for the coordinator — the stash stack is shared

`refs/stash` lives in the **common** git dir, so **every worktree agent shares
one stash stack**. Mid-session my `git stash push` (for the canary `before` leg)
was popped by a sibling agent, who then re-stashed my work under the label
`"restored: agent-other WIP (accidentally popped by agent-a01a7b03ea563e62a)"`;
my own `git stash pop` then pulled *their* setMask/maskB WIP
(`action.h` + `action.c` + `tag.c`, 379 lines) into my tree.

Recovered with no loss on either side: I re-stashed their three files under an
owner-identifying label (`stash@{0}`, "maskB WIP of sibling agent — re-stashed
by agent-ac4817c3 after cross-worktree stash collision"), restored my own five
files from the `git diff` I had saved to the scratchpad *before* stashing, and
dropped the duplicate stash entry by SHA (`7561e548`). Verified: `git diff
--stat` after recovery is byte-identical to `git stash show --stat` of the
entry that held my work.

**Standing lesson for the fan-out playbook: worktree agents must never use
`git stash` for A/B legs.** Save a `git diff` to the scratchpad and use
`git apply -R` / `git apply` instead — index-addressed `stash@{0}` is a shared
mutable global. If a stash is unavoidable, save the diff first and pop **by
SHA**, never by index. `stash@{0}` at handoff time is a sibling's, not mine.

---

## 6. Riders / follow-ups (NOT implemented here)

1. **`visual/video/deblocking`** — out of scope by brief. Needs (a)
   `MAX_EMBEDDED_VIDEO_STREAMS` 8 → 16 in `action.c:3416` (the test has **12**
   streams; 9–12 are silently dropped today — that, not a decoder gap, is why
   the board classified it `missing_element`); (b) the `DefineVideoStream`
   **flags byte** plumbed through the recompiler, which currently reads
   `cur_pos[9]` for the codec and discards `cur_pos[8]` entirely; (c) a port of
   Ruffle's 559-line `h263-rs-deblock::deblock()` + `QUANT_TO_STRENGTH`; (d)
   the per-picture quantizer, which libavcodec does not expose (would have to
   be parsed from the H.263 header). Wave 1 measured its streams against the
   golden at their parsed placement offsets: streams 1 and 5 (deblocker bit
   clear) are already **bit-exact**; 2, 9, 12 are off by 12 861 / 34 675 /
   321 868. The cap raise alone is a 1-line band move.
2. **`ACCEPTED_DIFFS.md` Category 9 correction** — noted for coordinator
   closeout, not edited here. The existing entry's framing ("different
   fixed-point arithmetic internally… 1–3 levels in solid regions") is **wrong
   for VP6** (now proven byte-exact) and **partly wrong for Spark** (bit-exact
   except IDCT precision and the missing deblock filter). The 1–3 level drift
   the entry describes was `sws_scale`, which the entry never names, and which
   this patch removes. Category 9 should be re-scoped to
   `visual/video/colorconversion/h263` (10 808 outliers / max 2 / mean 0.0105,
   IDCT precision, `<!-- image-axis: … -->` marker) and `visual/video/deblocking`,
   and its `netstream_play_flv` justification revisited.
3. **Occupied-flag / `has_character` ABI** — the general fix for the char-id-0
   sentinel. 188 sites, semantically per-site, across the AVM1 display list,
   its NO_GRAPHICS twin, `action.c`, and the AVM2 display walk. Correct
   someday; wrong lever for 5 comparisons.
4. **`SWFRecompDocs/plans/video-codec-support-plan.md`** — Phase B is done, and
   turned out to be a **colour-conversion** job rather than a decoder job. The
   plan's risk register has that backwards.
5. **`graphics-fanout-playbook.md` §11 lead list** — strike "char-id-0 depth
   sentinel (21 tag.c sites)"; the real count is 56 in `tag.c` / 188 repo-wide,
   and the lever was the recompiler alias. Re-price "video (21)" as
   "16 arc-sized + 5 landed".

---

## 7. Reproduction

```bash
# in the worktree, with the recompiler cmake-built there
python3 ruffle-tests/verify_output.py --test=video/colorconversion/vp6 \
  --tests-dir=ruffle-tests/tests/swfs/visual --mode=graphics --recompile
# … likewise video/colorconversion/{vp6a,h263}, video/{vp6_dispsize,vp6_alphaoffset}

DAWN_INSTALL=$HOME/CC/dawn-install \
python3 ruffle-tests/render_canary.py capture --label after --recompile --jobs 2
python3 ruffle-tests/render_canary.py compare before after
```

Test directories were `cp -r`'d from the main repo into the worktree's
canonical suite path; `--recompile` on first use of each (mandatory anyway,
the recompiler changed).
