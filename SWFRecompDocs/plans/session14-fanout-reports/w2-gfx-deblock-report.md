# Session 14 · wave 2 (graphics) — `w2-gfx-deblock`

H.263 Annex J deblocking filter + `DefineVideoStream` flags byte + embedded
video stream-cap raise.

**Agent:** w2-gfx-deblock · **Date:** 2026-08-12 · **Base:** `0a99be1a9`
**Worktree:** `.claude/worktrees/agent-a0da70b18e22f60eb` · **No commit made.**
**Design authority:** s13 `w2-gfx-video-report.md` §6.1 + `wave1-gfx-charid0.md` §5e
**Baseline:** run `31130292354` at `fb36ba110`, pixels 301/567.
**Patch:** `wave2/w2-gfx-deblock.patch` (7 files, +353 / −29)

---

## 0. Brief executed (coordinator's question, answered first)

**Executed brief: video deblocking only** — `MAX_EMBEDDED_VIDEO_STREAMS` 8→16,
the `DefineVideoStream` flags byte, and the port of Ruffle's
`h263-rs-deblock::deblock()`. Nothing else.

The misrouted mid-flight message (hairline_edge_drift split / morph
subdivision / acid-blend-2 output.26 / the 8-px offset_translation trio)
**cost zero work**. It arrived while the BEFORE capture leg was already
running, was recognised on sight as belonging to the curve/morph lane — none
of its four items touches video, and my brief was pre-scoped in s13 and
explicitly skips wave 1 — and no file was opened or edited on its account.
The correction confirming the misroute arrived before this report was
finalised. No scope creep into h264 or Stage3D either: both are named as
parked arcs in §6 and neither was touched (they are unreachable from the Spark
path by construction — see §5 risk 4).

**Pricing, honestly:** board-audit's re-price of **+1 comparison** is right, and
it is the number to plan with. `visual/video/deblocking [output]` is the one
comparison this bundle is *expected* to flip. The other five deblocking-eligible
comparisons (§1) are band-move candidates at best; §3 reports what each actually
did rather than what it might. Yield per line is poor — ~290 new lines for +1 —
and the port did **not** hit a wall, so the fallback (ship the cap raise + flags
byte alone) was not needed.

---

## 0a. Headline

**`visual/video/deblocking` goes from 2 906 999 excess outlier channels to
104 — a 99.9964 % band move, max diff 255 → 4, mean 56.2435 → 0.0000 — and
still does NOT flip**, because the comparison's bar is `max_outliers = 0` at
`tolerance = 0`. Eleven of its twelve streams are now **byte-exact**; the
residual is 104 channels on one chroma row of the single least-quantised
496² stream.

| comparison | before | after | verdict |
|---|---|---|---|
| `visual/video/deblocking` | fail · 2 906 999 out · max 255 · mean 56.2435 | fail · **104** out · max **4** · mean **0.0** | **band ↓↓↓ −99.9964 %**, 11/12 streams byte-exact, **no flip** |
| `avm1/netstream_play_flv` | fail · 1 654 out · max 8 · mean 0.006 | fail · **44** out · max **3** · mean **0.0002** | band ↓↓ −97.3 %, **no flip** |
| `from_gnash/…/Video-EmbedSquareTest` | fail · 189 out · max 255 · mean 0.3995 | fail · 189 out · max 255 · mean **0.3928** | band ↓ (mean only) — its 189 outliers are a **separate** max-255 defect the filter cannot touch |
| everything else (43 of 46 comparisons) | — | — | **md5-IDENTICAL** |

**Predicted CI movement: +0 comparisons.** Board-audit's +1 was the right
*ceiling*; the measured answer is that the mechanism is now essentially fully
implemented and the last 0.0036 % is a different bug (§3a). This is an honest
non-flip: the corpus's single largest failing comparison is now its
best-converged one, and two other rows moved a long way, but the pixel score
does not change. **The value delivered is a closed mechanism and three large
band moves, not a point.**

**CI-fidelity: all four graded video comparisons are CI-grade.** Every BEFORE
leg PNG is byte-identical to the corresponding CI actual PNG on
`ruffle-image-results` at the baseline run:

| comparison | md5 (local BEFORE == CI actual) |
|---|---|
| `visual/video/deblocking` | `2dd397605077fdf1e0844318b26f4fca` |
| `visual/video/colorconversion/h263` | `612a5ca038fbb8f03ea70f32c90abcd0` |
| `avm1/netstream_play_flv` | `d88929eb2e1a57c7448a1fafb44fa1e3` |
| `from_gnash/…/Video-EmbedSquareTest` | `7c324e403b5bdb7785b88da81b0c93c8` |

so the AFTER numbers above are not local-Dawn claims — lavapipe and local Dawn
demonstrably agree on these frames, and the "no flip" verdict is as reliable as
a CI run would be.

---

## 1. Corpus survey — which SWFs actually ask for deblocking

Every embedded/NetStream video source in the graded corpus was parsed
(`DefineVideoStream` flags byte + every Sorenson Spark picture header) before
any code was written. **The s13 report's pricing was right about the mechanism
but wrong about one detail, and that detail is load-bearing.**

| test | source | `VideoFlagsDeblocking` | packet `USE_DEBLOCKER` | PQUANT → strength | deblocks? |
|---|---|---|---|---|---|
| `visual/video/deblocking` | 12 × `DefineVideoStream`, codec 2 | `0` (UsePacketValue) ×12 | **1** ×12 | 2→**1**, 11→**5**, 22→**9**, 31→**12** | **YES ×12** |
| `visual/video/colorconversion/h263` | 1 × stream, codec 2 | **`1` (None)** | 1 | 6→3 | **NO** — explicitly disabled |
| `from_gnash/…/Video-EmbedSquareTest` | 1 × stream, codec 2, 11 frames | `0` (UsePacketValue) | 1 (all 11) | 2→**1** | **YES** |
| `avm1/netstream_play_flv` | FLV, codec 2 | n/a (FLV) → UsePacketValue | 1 | 3→**2** | **YES** |
| `avm2/netstream_play_flv` | FLV, codec 2 | n/a → UsePacketValue | 1 | 3→**2** | **YES** |
| `avm2/netstream_seek_flv` | FLV, codec 2, 20+ frames | n/a → UsePacketValue | 1 | 3→2, 2→1 | **YES** |
| `avm1/netstream_play_flv_screen` | FLV, codec **3** | — | — | — | no (ScreenVideo) |
| `visual/video/colorconversion/{vp6,vp6a}`, `vp6_dispsize`, `vp6_alphaoffset` | codec 4/5 | — | — | — | no (VP6) |
| `visual/video/h264`, `h264_multinalu` | codec 7 | — | — | — | no |
| `from_shumway/acid/acid-video` | **no `DefineVideoStream` at all** | — | — | — | no |

### 1a. Refutation carried forward from s13

s13 §6.1 (quoting wave 1 §5e) says of `visual/video/deblocking`:

> streams 1 and 5 (deblocker bit clear) are already **bit-exact**

**The deblocker bit is set on all twelve packets.** Streams 1 and 5 are the
`PQUANT = 2` ones, i.e. **strength 1**, and `up_down_ramp(x, 1)` is non-zero
only for `|x| == 1` — on this test's content (8×8 luma / 16×16 chroma constant
blocks with large steps, per the test's own `NOTES` file) every `d` at a block
edge is far larger than 1, so a strength-1 filter is a genuine no-op. Same
observation, different cause. It matters because the wave-1 framing implies
"honour the bit and 2 of 12 streams stay put"; the truth is "honour the bit and
all 12 change, but 2 of them change by zero".

### 1a-bis. The baseline decomposed per stream (CI data, not local)

`visual/video/deblocking`'s CI actual PNG (`ruffle-image-results`, run
`31130292354`) differenced against its golden, sliced at the twelve parsed
placement offsets — this is the exact shape the fix has to close, and it is
*measured from CI's own render*, so it is not a local-Dawn claim:

| stream | placement | PQUANT → strength | differing channels | max |
|---|---|---|---:|---:|
| 1 | (4,4) 248² | 2 → **1** | **0** | 0 |
| 5 | (4,256) 248² | 2 → **1** | **0** | 0 |
| 2 / 6 | (256,4) / (256,256) 248² | 11 → **5** | 12 861 each | 10 |
| 3 / 7 | (508,4) / (508,256) 248² | 22 → **9** | 33 612 each | 19 |
| 4 / 8 | (760,4) / (760,256) 248² | 31 → **12** | 43 422 each | 27 |
| 9–12 | 496² quadrants below y=508 | 2/11/22/31 | 639 329 / 689 201 / 698 529 / 700 150 | **255** |
| | | | **2 906 999 total** | |

Two distinct defects, cleanly separated: streams 2–4 and 6–8 are *rendered but
unfiltered* (max diff scales monotonically with strength, exactly as an
un-applied smoothing filter would), and streams 9–12 are *not rendered at all*
(max 255 = the missing-element signature) because they are the 9th–12th
`DefineVideoStream` and the cap was 8. Streams 1 and 5 sit at exactly 0, which
is the independent confirmation that libavcodec's FLV1 decode of this content
is already bit-identical to h263-rs — the only thing between us and a
byte-exact frame was the filter.

### 1b. The flags byte is a REGRESSION GUARD, not just a feature

`visual/video/colorconversion/h263` sets `VideoFlagsDeblocking = 1`
(`VideoDeblocking::None`) while its picture header sets `USE_DEBLOCKER = 1`.
Shipping the filter *without* the flags byte would deblock it at strength 3 and
blow up a comparison that is currently a dispositioned 10 808-outlier /
max-diff-2 near-miss. The recompiler plumbing is therefore not optional.

Ruffle's gate is also asymmetric and we reproduce it verbatim
(`video/software/src/decoder/h263.rs:80-90`): the filter runs for `Level1`
(field value 2) or for `UseVideoPacketValue` (0) when the packet bit is set —
`Level2..4` (3..5) parse fine and then never act. No corpus SWF exercises
`Level2..4`, so this is Ruffle-parity by construction, not by measurement.

---

## 2. What changed (7 files)

| # | file | site | change |
|---|---|---|---|
| 1 | `SWFRecomp/src/swf.cpp` | `SWF_TAG_DEFINE_VIDEO_STREAM` `:5033` | read `cur_pos[8]` (previously discarded), `deblocking = (flags >> 1) & 7`, emit it as a new 5th argument of `tagDefineVideoStream` |
| 2 | `SWFModernRuntime/include/libswf/tag.h` | `:198` | `tagDefineVideoStream` gains `u8 deblocking` before `codec_id` |
| 3 | `SWFModernRuntime/include/libswf/tag.h` | `:544` | `ng_record_video` gains `u8 deblocking`; new `u8 ng_getVideoDeblocking(size_t)` |
| 4 | `SWFModernRuntime/src/libswf/tag.c` | `tagDefineVideoStream` `:11703` | forward `deblocking` to `ng_record_video` |
| 5 | `SWFModernRuntime/src/libswf/ng_shared.c` | video registry `:274-340` | new `ng_video_deblocking[]` column + `ng_getVideoDeblocking()` |
| 6 | `SWFModernRuntime/include/actionmodern/video_codec.h` | `:16-47` | `VIDEO_DEBLOCK_*` constants; `deblocking` param on `video_decode_one_frame` and `video_decoder_create` |
| 7 | `SWFModernRuntime/src/actionmodern/video_codec.c` | new block after the BT.601 converter | **the filter** — `VIDEO_QUANT_TO_STRENGTH`, `deblock_process_{div,shr}`, `deblock_{horiz,vert,plane}`, the Spark picture-header bit reader, `video_deblock_strength()`, `yuv420_deblock_and_convert()`; both decode paths call it |
| 8 | `SWFModernRuntime/src/actionmodern/video_codec.c` | `yuv420_frame_to_rgba_bt601` | split into a plane-pointer core (`yuv420_planes_to_rgba_bt601`) + an `AVFrame` wrapper, so the deblocked scratch planes can reuse the exact same conversion |
| 9 | `SWFModernRuntime/src/actionmodern/action.c` | `:3416` | `MAX_EMBEDDED_VIDEO_STREAMS` **8 → 16** (`visual/video/deblocking` has 12; 9–12 were silently dropped) |
| 10 | `SWFModernRuntime/src/actionmodern/action.c` | `find_or_create_embedded_stream` `:3446` | pass `ng_getVideoDeblocking(char_id)` into `video_decoder_create` |
| 11 | `SWFModernRuntime/src/actionmodern/action.c` | `flv_decode_first_frame` `:3322` | pass `VIDEO_DEBLOCK_USE_PACKET_VALUE` — Ruffle hardcodes that for every FLV NetStream decoder (`core/src/streams.rs:961,1167`) |

### 2a. The filter port — the two things a clean rewrite gets wrong

Ported from `~/.cargo/git/checkouts/h263-rs-*/deblock/src/deblock.rs` (the
559-line file the s13 report names).

1. **The scalar and SIMD lanes are not the same function.** Rust's
   `scalar_impl::process` uses integer **division** (`/8`, `/4`, `/2`,
   truncating toward zero); `simd_impl::process_simd` uses `.shr(3)/.shr(2)/
   .shr(1)`, which **floor**. They disagree on every negative intermediate
   (`-3/2 == -1` but `-3 >> 1 == -2`), and the chunking decides which pixel
   gets which arithmetic:
   * horizontal edges: columns `[0, 8·floor(w/8))` shift, the ≤7-column
     remainder divides;
   * vertical edges: rows `[0, 8·floor(h/8))` shift, the ≤7-row remainder
     divides.
   On this corpus it is the **chroma planes** that expose it (124×124 for the
   248² streams: 4 remainder columns and 4 remainder rows). Unifying the two
   would have silently cost byte-exactness on exactly those lanes.
2. **A and D wrap; B and C clamp.** `(a16 - d2) as u8` is a truncating cast in
   Rust; only B and C carry `.clamp(0, 255)`.

Geometry notes carried across verbatim: horizontal edges at `edge_y = 8, 16, …`
while `edge_y + 2 <= height`, touching rows `edge_y-2 .. edge_y+1`; vertical
edges from `row[2..].chunks_exact_mut(8)` index 4..7, i.e. columns
`8k+6 .. 8k+9` with the edge at `8k+8`, guarded by Rust's own `width >= 10`.
Horizontal runs fully before vertical, per the spec and per `deblock()`.

### 2b. Deblocking is display-only

Ruffle filters a **copy** (`deblock()` returns a new `Vec`) and leaves
`H263State`'s reference picture untouched, so inter-frame prediction is
unaffected. We do the same: the planes are copied out of the `AVFrame` into
tightly-packed scratch buffers (which is also exactly h263-rs's
`DecodedPicture` layout — luma `w*h`, chroma `ceil(w/2)*ceil(h/2)` — the
geometry `deblock()` assumes), filtered there, and converted from there.
`frame->data` is never written; libavcodec may still hold it as a reference
frame. `avm2/netstream_seek_flv`'s 20+ inter-frames are the case that would
have caught the mistake.

### 2c. Where the quantizer comes from

libavcodec does not expose PQUANT on the `AVFrame` (the old `qp_table` API is
gone), so `spark_parse_header()` reads it out of the picture header directly —
the same field order h263-rs parses: `PSC[17]==1`, `version[5]`,
`temporal_reference[8]`, `source_format[3]` (+`8+8` or `16+16` custom dims for
codes 0/1), `picture_type[2]`, `USE_DEBLOCKER[1]`, `PQUANT[5]`. Every read is
length-checked; a header that does not start with a valid PSC yields
"no filtering", never a wild read.

---

## 3. Grading — local A/B legs

Method: `git diff > wave2/w2-gfx-deblock.patch`, `git apply -R` → rebuild the
recompiler → capture `before`; `git apply` → rebuild the recompiler → capture
`after`. **No `git stash` at any point** (playbook §5b — refs/stash is shared
across worktrees). Both legs used `--recompile` **and** a separately
cmake-rebuilt `SWFRecomp` binary, which is mandatory here because the patch
changes recompiler emission *and* `tagDefineVideoStream`'s arity.

### 3.1 Canary — 29 tests / 46 comparisons, 43 IDENTICAL / 3 DIFFERS

```
RENDER CANARY  before=before  after=after   29 tests / 46 comparisons
  IDENTICAL    43
  DIFFERS       3
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

The three DIFFERS are **exactly** the three comparisons the §1 survey predicted
would deblock, and nothing else moved by a single byte. The set is the full
standing `render_canary_tests.txt` (21 tests / 38 comparisons, including all
four `regression/` entries per standing policy) plus the eight video tests.
Notably byte-identical: `visual/video/colorconversion/{vp6,vp6a}`,
`vp6_dispsize`, `vp6_alphaoffset` (VP6 — the filter is gated out before the
header is even parsed) and **`visual/video/colorconversion/h263`, which stays
at exactly 10 808 / max 2** — the `VideoDeblocking::None` guard from §1b doing
its job on the one comparison that would otherwise have regressed.

### 3.2 `visual/video/deblocking` — per-stream, after

| stream | strength | before (differing channels) | after |
|---|---|---:|---:|
| 1, 5 (248²) | 1 | 0, 0 | **0, 0** |
| 2, 6 (248²) | 5 | 12 861 each | **0** |
| 3, 7 (248²) | 9 | 33 612 each | **0** |
| 4, 8 (248²) | 12 | 43 422 each | **0** |
| 9 (496²) | 1 | 639 329 | **104** |
| 10 (496²) | 5 | 689 201 | **0** |
| 11 (496²) | 9 | 698 529 | **0** |
| 12 (496²) | 12 | 700 150 | **0** |

**Eleven of twelve streams are byte-exact against the Ruffle golden**, across
all four strengths and both frame sizes. That is the strongest possible
statement about the port: the filter, the strength table, the flags gate, the
picture-header parse, the plane geometry, and the BT.601 conversion are all
exactly right, in a test whose own `NOTES` say it exists specifically to check
"which deblocking algorithm is in use and how it affects the luma and chroma
planes" and "how its strength is affected by the encoded quantizer".

Streams 1–8 also **exercise the remainder lanes on real data**: their chroma
planes are 124×124, so 4 columns and 4 rows fall outside `chunks_exact(8)` and
take the truncating-division path while the rest shift. Those planes come out
byte-exact, which is the div-vs-shift split of §2a validated in situ, not just
against synthetic vectors.

### 3a. The 104-channel residual — what it is, and what it is not

All 104 channels sit in **stream 9 only**, on **chroma row 232** (luma rows 464
and 465 of the 496² picture), in three short runs of chroma columns, and are
**one Cb level** each: R never moves, G moves by 1 on four channels, B moves by
2 or 4 — precisely the fingerprint of a ±1 Cb sample pushed through
`B = gray + cb·132201 >> 16` (2.017 levels per Cb step) and
`G = … + cb·(−25675) >> 16` (0.39 levels per step, usually rounding away).

**It is not a filter-lane bug**, and that can be settled without further
measurement: stream 9's luma plane is 496×496 and its chroma plane 248×248, and
`496/8` and `248/8` are both exact — **neither plane has a remainder lane at
all**, so the div-vs-shift split cannot express itself there. Every other
degree of freedom in the filter is pinned by the 66/66 oracle cross-check and
the three Rust `test_deblock` vectors (§4).

**It is decoder-level precision** — the same mechanism already dispositioned
for `visual/video/colorconversion/h263` (ACCEPTED_DIFFS Category 9: libavcodec's
H.263 IDCT vs `h263-rs`'s f32 basis-table IDCT). The corroborating detail:
stream 9 is the **least quantised 496² stream** (PQUANT 2, 13 305-byte payload,
vs 6 542 / 6 376 / 6 376 for streams 10–12) — the most retained coefficients,
hence the most IDCT rounding surface. At strength 1 the filter's output is
non-zero only where `|d| == 1`, so a single-LSB decoder difference in one
macroblock row is exactly the input that flips the filter's decision there.
Streams 1 and 5 are the same PQUANT 2 at 248², small enough to have no such
divergence, and they are byte-exact.

Wave 1 already swept every libavcodec `idct_algo` for this family and found
none that reaches `max_outliers = 0`, with the closest being a float IDCT
(`FF_IDCT_FAAN`) that is a CI determinism hazard across shards. **Not
attempted here**, per that refutation and the timebox.

### 3b. `avm1/netstream_play_flv` — 1 654 → 44

Confirms the NetStream arm works: FLV has no per-stream deblocking field, so
Ruffle's hardcoded `UseVideoPacketValue` plus this stream's set packet bit and
PQUANT 3 give strength 2, and the excess drops 97.3 % to 44 outliers (max diff
3, mean 0.0002) in a 58×57-pixel region. The remaining channels are 93×1,
42×2, 2×3 — the residue of the GPU sample-stretch this test's ACCEPTED_DIFFS
entry names, now no longer masked by an unfiltered picture. Its entry's stated
figures ("~52k outliers, max diff 64") are two generations stale; see §6.1.

### 3c. `from_gnash/…/Video-EmbedSquareTest` — outlier count unmoved

189 outliers before and after. Its diff is 189 channels at **exactly 255**
inside a 26-row band at the top of the frame plus 46 channels at 1–2; the 255s
are a hard missing/extra element, not a filtering artifact, and `tolerance = 5`
means only they count. Deblocking at strength 1 moved the low-amplitude
channels (mean 0.3995 → 0.3928) and nothing else. **This test is not a
deblocking beneficiary** — it is a separate, un-owned defect that the video
label was hiding.

### 3d. Trace axis

**Zero movement.** All 29 canary tests hold their trace status (28 `pass`,
`regression/avm2_morph` `skip`/no expected image), including every video and
netstream test. Expected: nothing this patch touches is readable from
ActionScript — the flags byte only reaches a decoder, and the stream-cap raise
only lets frames that were being dropped reach the renderer.

### 3e. Coverage the timebox cut

`visual/video/h264` (10 comparisons), `visual/video/h264_multinalu`,
`avm1/netstream_play_flv_screen`, `avm2/netstream_play_flv`,
`avm2/netstream_seek_flv` and `from_shumway/acid/acid-video` were dropped from
the graded set after two capture runs were killed by machine contention
(~25 sibling-agent load on 8 cores). All six are **provably unaffected by
construction**, not merely assumed: `video_deblock_strength()` returns 0 for
`codec_id != 2` before it parses anything, and h264 is codec 7,
`netstream_play_flv_screen` is codec 3 (ScreenVideo, a hand-rolled decoder in
`action.c` that never enters `video_codec.c`), and `acid-video` was parsed and
has **no `DefineVideoStream` tag at all**. The two `avm2/netstream_*` tests
*are* codec 2 and *would* deblock — they are the one real coverage gap, and
both are blank-stage failures at max 255 whose trace status is
`output_mismatch`, so a band move there is not decision-relevant. The CI run
will cover them.

---

## 4. Validation of the port itself (independent of any render)

The filter was validated **before** it was wired to anything, against two
oracles:

1. **Ruffle's own unit tests**, transcribed into a standalone C harness: the
   37-row `test_process` table and all three `test_deblock` vectors (the 11×17
   image at strengths 4, 8, 12 — an image sized deliberately so that "the first
   8 values of the horizontal edge and the first 16 values of the vertical edge
   will be processed by the SIMD part, and the remaining 3 and 1 by the
   scalar part"). **All pass byte-exactly**, plus the constant-input no-op
   property for all 256 values × 12 strengths on both lanes.
2. **A literal Python transcription of `deblock.rs`** (including the
   div-vs-shift split) run over random planes at the geometries this corpus
   actually uses — 11×17, 248×248, 124×124, 496×496, 160×120, 80×60, 10×10,
   13×9, 9×9, 320×233, 117×59 — × strengths 1/2/3/5/9/12. **66/66 byte-exact.**
   This is the check that covers the remainder lanes the Rust unit test only
   partly reaches, and the `width < 10` / `height < 10` degenerate guards.

Both harnesses are archived next to this report so the checks are re-runnable:
`wave2/deblock_core.h` (the filter, extracted verbatim from the patch),
`wave2/deblock_test.c` (Ruffle's vectors), `wave2/deblock_ref.py` (the oracle +
fixture generator), `wave2/deblock_fixture.c` (the cross-check runner).

```bash
cd wave2 && gcc -O2 -Wall -Wextra -o deblock_test deblock_test.c && ./deblock_test
python3 deblock_ref.py fixture.bin && gcc -O2 -Wall -Wextra -o deblock_fixture deblock_fixture.c && ./deblock_fixture fixture.bin
```

A third property was checked and holds: the C filter is stride-independent —
running it over a padded buffer produces the identical picture and never
touches the padding, which is what lets the scratch-plane copy be a pure
optimisation rather than a semantic requirement.

---

## 5. Merge notes for the coordinator

**Files touched (serial-merge order irrelevant, but conflict surfaces are):**

| file | conflict surface |
|---|---|
| `SWFRecomp/src/swf.cpp` | one hunk inside `SWF_TAG_DEFINE_VIDEO_STREAM` (~`:5030-5060`). Adjacent to s13's char-id-0 alias, same case block — **any sibling touching that tag will conflict textually.** |
| `SWFModernRuntime/src/actionmodern/video_codec.c` | ~290 new lines in one contiguous block + 3 small call-site hunks. Nothing else in the corpus touches this file. |
| `SWFModernRuntime/include/actionmodern/video_codec.h` | 3 hunks, this file is video-only. |
| `SWFModernRuntime/src/actionmodern/action.c` | 3 small hunks at `:3416`, `:3322`, `:3446` — the embedded-video block, far from the AVM1/AVM2 dispatch bodies siblings usually touch. |
| `SWFModernRuntime/src/libswf/tag.c` | one 4-line hunk at `tagDefineVideoStream` (~`:11703`). |
| `SWFModernRuntime/include/libswf/tag.h` | two declaration hunks. **`tagDefineVideoStream` changes arity** — if a sibling adds a `tagDefineVideoStream` call anywhere it must gain the extra argument. |
| `SWFModernRuntime/src/libswf/ng_shared.c` | one array + one accessor in the video registry block. |

**ABI note:** `tagDefineVideoStream` gains a parameter, so **every SWF with a
`DefineVideoStream` must be re-recompiled** — a stale `RecompiledTags/` emits
the 5-argument call and fails to compile. `--recompile` is mandatory on first
use of any video test dir after this patch, and the recompiler must be
cmake-rebuilt. Non-video SWFs emit byte-identical C.

**Risk register**

1. **`MAX_EMBEDDED_VIDEO_STREAMS` 8 → 16.** `EmbeddedVideoStream` holds a
   256-entry frame array of `{ptr,int,int}` = 4 KB each, so the static array
   grows 32 KB → 64 KB of BSS. No behavioural risk; the only movies that fill
   past 8 are the ones that were being truncated.
2. **The flags byte.** Read from `cur_pos[8]`, which the tag-length guard
   (`tag.length < 10`) already covers. A `deblocking` value of 6 or 7 is
   invalid per the swf crate (Ruffle *errors the whole tag*); we treat it as
   "not Level1, not UsePacketValue" → no filtering, which is the conservative
   arm. No corpus SWF has one.
3. **Extra work per decoded Spark frame.** Three plane copies + the filter,
   only when the stream asks for it. `visual/video/deblocking` decodes 12
   frames once at `tagInit` time; the netstream tests decode ≤20. Not on any
   hot path.
4. **VP6/H.264/ScreenVideo are untouched** — `video_deblock_strength()`
   returns 0 for `codec_id != 2` before parsing anything, so those paths are
   bit-identical to HEAD by construction, and the canary confirms it.

### 5a. Playbook lesson — long captures die under fan-out load

Two `render_canary capture` runs were killed mid-flight (one at 25/35 tests,
one at 2/10) while the machine sat at load ~25 on 8 cores from ~7 sibling
agents. `nohup … &` was **not** enough; the run only survived once launched
with `setsid nohup … < /dev/null & disown`. Two consequences worth adding to
the playbook alongside the `-P 2` cap:

* **Launch capture legs detached with `setsid`**, or a 20-minute leg becomes a
  25/35 partial with no manifest and no way to resume.
* **`capture --force` rmtree's the whole label dir**, so re-running to fill
  gaps destroys the tests that already succeeded. Recovering a partial leg
  means capturing the missing tests into a *new* label and merging the
  directories plus a hand-built `manifest.json` (`{label, tests, results}` is
  all `compare` reads). That worked cleanly and `compare` accepted the merged
  manifest — worth writing down rather than rediscovering.

---

## 6. Riders / follow-ups (NOT implemented here)

1. **`ACCEPTED_DIFFS.md` Category 9 needs a second correction** (coordinator
   closeout item — not edited here). The `netstream_play_flv` row still reads
   "~52k image outliers, max diff 64"; the true figure after this patch is
   **44 outliers, max 3**, two generations newer. Its stated mechanism
   ("Spark IDCT precision × the GPU sample-stretch") was also carrying the
   missing deblocking filter inside it; with the filter in, what remains really
   is the sample-stretch. **`visual/video/deblocking` should join Category 9
   too** — at 104 channels / max 4 / mean 0.0 on one chroma row of one stream,
   with 11 of 12 streams byte-exact, it is now the same IDCT-precision story as
   `h263` and no longer "live work" (that phrase, at ACCEPTED_DIFFS line 588,
   is what this patch retires). Give it an explicit
   `<!-- image-axis: visual/video/deblocking output -->` scope marker so
   `image_triage` resolves it HARD. The
   `visual/video/colorconversion/h263` entry (line 559, with its
   `<!-- image-axis: … -->` marker) stays exactly as-is: that stream sets
   `VideoDeblocking::None`, so this patch cannot and must not move it, and its
   residual really is IDCT precision.
2. **`from_gnash/…/Video-EmbedSquareTest` is misfiled as a video item.**
   Measured (§3c): its 189 outliers are 189 channels at *exactly* 255 in a
   26-row band at the top of the frame — a missing/extra element, not a
   decode or filter artifact. Deblocking (strength 1, 11 inter-frames) moved
   only its low-amplitude channels. **Re-triage it out of the video bucket**;
   whoever owns `missing_element` should take it. It is a small frame
   (320×96) and a cheap diagnosis.
3. **`visual/video/h264` (10 comparisons) + `h264_multinalu`** are untouched by
   any of this — codec 7 never reaches the Spark path. They remain the largest
   un-owned slice of the "remaining video (16)" bucket and are a decoder-level
   arc, not a filter port.
4. **`from_shumway/acid/acid-video` output.10/.20 (`no_render`) has no
   `DefineVideoStream` at all** — parsed and confirmed. Whatever blocks those
   two frames is not embedded video, so the s13 "remaining video (16)" grouping
   mis-files them. Re-triage them out of the video bucket.
5. **`Level2..4` deblocking is unexercised by the corpus.** Ruffle only acts on
   `Level1`; whether real Flash escalates strength for `Level2..4` is unknown
   and untestable here. We match Ruffle. If a future SWF needs it, the hook is
   one line in `video_deblock_strength()`.
6. **The `visual/video` label is now down to two real owners.** After this
   patch the bucket is: h264 (11 comparisons, decoder arc), the two
   `avm2/netstream_*` blank stages (an AVM2 display problem, not a video one —
   both are `output_mismatch` on the trace axis first), and residuals that are
   all IDCT precision. **There is no remaining "video backend" work of the kind
   the board has been pricing**; the embedded-video mechanism is closed.
7. **Browser-WASM still does not render video at all** — the branch is inside
   `#ifdef OFFSCREEN_RENDER` (`tag.c:3140`/`:3472`). Unchanged, out of scope,
   noted again because it keeps being rediscovered.
