#include "actionmodern/video_codec.h"

#include <stdlib.h>
#include <string.h>

#ifdef SWF_HAVE_LIBAVCODEC
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
#endif

// Slack bytes appended to every sws_scale destination plane.
//
// libswscale converts in SIMD-sized chunks and can write past the end of the
// last output row. Measured, not assumed: valgrind on visual/video_deblocking
// reports two `Invalid write of size 8` at +0 and +16 past a 246,016-byte
// (w*h*4) malloc'd block, from sws_scale. glibc detects the resulting arena
// damage at the NEXT free — `free(): corrupted unsorted chunks` inside
// av_frame_free — which is why the abort's backtrace pointed at cleanup code
// and not at the writer. ASan does not see it either: the write comes from
// libswscale.so, which is uninstrumented.
//
// FFmpeg's own av_image_alloc pads for exactly this reason. We keep plain
// malloc (callers free() the buffer) and add the same slack; 64 is
// AV_INPUT_BUFFER_PADDING_SIZE, FFmpeg's standard margin.
//
// Found by the CI crash-capture instrument, run 30309564809 shard 30
// (SWFRecompDocs/guides/ci-crash-capture.md).
#define SWS_DST_SLACK 64

int video_codec_supported(int codec_id)
{
	switch (codec_id) {
		case 3: // ScreenVideo — hand-rolled decoder in action.c
			return 1;
#ifdef SWF_HAVE_LIBAVCODEC
		case 2: // Sorenson Spark
			return avcodec_find_decoder(AV_CODEC_ID_FLV1) != NULL;
		case 4: // On2 VP6
			return avcodec_find_decoder(AV_CODEC_ID_VP6F) != NULL;
		case 5: // On2 VP6 with alpha
			return avcodec_find_decoder(AV_CODEC_ID_VP6A) != NULL;
#endif
		default:
			return 0;
	}
}

#ifdef SWF_HAVE_LIBAVCODEC

// ---------------------------------------------------------------------------
// BT.601 YUV 4:2:0 → RGBA, byte-for-byte Ruffle's h263-rs-yuv `bt601`
// (yuv/src/bt601.rs) as used by ruffle_render's Bitmap::to_rgba for BOTH the
// Spark and VP6 decoders.
//
// This deliberately replaces libswscale. sws_scale interpolates chroma and
// rounds differently, which put ~48% of the channels of every embedded-video
// frame 1-3 levels off the Ruffle golden — enough to fail at tolerance 0 while
// looking visually identical. libavcodec's VP6F/VP6A decode is bit-identical
// to Ruffle's nihav VP6 decode, so with this conversion the VP6 tests come out
// byte-exact.
//
// The two properties that matter and that swscale does NOT have:
//   * chroma is NEAREST-NEIGHBOUR — one Cb/Cr sample is reused verbatim for
//     all four corresponding luma pixels. bt601.rs: "This is not the most
//     correct, or nicest, but it's what Flash Player does."
//   * 16.16 fixed point with a +32768 round and the reduced→full range
//     expansion folded into the coefficients.
//
// Alpha (VP6A / AV_PIX_FMT_YUVA420P) comes from plane 3 at full resolution,
// and RGB is clamped to it (bitmap.rs: "RGB components need to be clamped to
// alpha to avoid invalid premultiplied colors") — the renderer's bitmap quad
// path expects premultiplied ARGB.
// ---------------------------------------------------------------------------
static int yuv420_frame_is_supported(int pix_fmt)
{
	return pix_fmt == AV_PIX_FMT_YUV420P || pix_fmt == AV_PIX_FMT_YUVA420P;
}

static void yuv420_frame_to_rgba_bt601(const AVFrame* frame, int w, int h,
                                       unsigned char* rgba)
{
	const uint8_t* yp  = frame->data[0];
	const uint8_t* cbp = frame->data[1];
	const uint8_t* crp = frame->data[2];
	const uint8_t* ap  = (frame->format == AV_PIX_FMT_YUVA420P) ? frame->data[3] : NULL;

	const int yls  = frame->linesize[0];
	const int cbls = frame->linesize[1];
	const int crls = frame->linesize[2];
	const int als  = ap ? frame->linesize[3] : 0;

	for (int y = 0; y < h; y++) {
		const uint8_t* yrow  = yp  + (size_t)y * (size_t)yls;
		const uint8_t* cbrow = cbp + (size_t)(y >> 1) * (size_t)cbls;
		const uint8_t* crrow = crp + (size_t)(y >> 1) * (size_t)crls;
		const uint8_t* arow  = ap ? ap + (size_t)y * (size_t)als : NULL;
		unsigned char* out   = rgba + (size_t)y * (size_t)w * 4;

		for (int x = 0; x < w; x++) {
			// 76309   == round((255/219) * 65536)
			// 104597  == round((255/224) * 1.402 * 65536)
			// -53279  == round(-(255/224) * 1.402 * (0.299/0.587) * 65536)
			// -25675  == round(-(255/224) * 1.772 * (0.114/0.587) * 65536)
			// 132201  == round((255/224) * 1.772 * 65536)
			int32_t gray = ((int32_t)yrow[x] - 16) * 76309;
			int32_t cb   = (int32_t)cbrow[x >> 1] - 128;   // nearest chroma
			int32_t cr   = (int32_t)crrow[x >> 1] - 128;

			int32_t r = gray + cr * 104597 + 32768;
			int32_t g = gray + cr * -53279 + cb * -25675 + 32768;
			int32_t b = gray + cb * 132201 + 32768;

			// clamp(v >> 16, 0, 255). Shifting only non-negative values keeps
			// this free of C's implementation-defined `>>` on negatives; a
			// negative numerator can only ever clamp to 0 anyway.
			r = (r < 0) ? 0 : (r >> 16); if (r > 255) r = 255;
			g = (g < 0) ? 0 : (g >> 16); if (g > 255) g = 255;
			b = (b < 0) ? 0 : (b >> 16); if (b > 255) b = 255;

			int32_t a = 255;
			if (arow) {
				a = (int32_t)arow[x];
				if (r > a) r = a;
				if (g > a) g = a;
				if (b > a) b = a;
			}

			out[x * 4 + 0] = (unsigned char)r;
			out[x * 4 + 1] = (unsigned char)g;
			out[x * 4 + 2] = (unsigned char)b;
			out[x * 4 + 3] = (unsigned char)a;
		}
	}
}

static enum AVCodecID map_flv_codec_id(int codec_id)
{
	switch (codec_id) {
		case 2: return AV_CODEC_ID_FLV1;
		case 4: return AV_CODEC_ID_VP6F;
		case 5: return AV_CODEC_ID_VP6A;
		case 7: return AV_CODEC_ID_H264;
		default: return AV_CODEC_ID_NONE;
	}
}

static int decode_via_libavcodec(int codec_id,
                                 const unsigned char* payload, int payload_len,
                                 int* out_w, int* out_h,
                                 unsigned char** out_rgba)
{
	enum AVCodecID avid = map_flv_codec_id(codec_id);
	if (avid == AV_CODEC_ID_NONE) return 0;

	const AVCodec* codec = avcodec_find_decoder(avid);
	if (!codec) return 0;

	AVCodecContext* cctx = avcodec_alloc_context3(codec);
	AVPacket* pkt = av_packet_alloc();
	AVFrame* frame = av_frame_alloc();
	struct SwsContext* sws = NULL;
	unsigned char* rgba = NULL;
	int ok = 0;

	if (!cctx || !pkt || !frame) goto done;
	if (avcodec_open2(cctx, codec, NULL) < 0) goto done;

	pkt->data = (uint8_t*)payload;
	pkt->size = payload_len;

	if (avcodec_send_packet(cctx, pkt) < 0) goto done;
	if (avcodec_receive_frame(cctx, frame) < 0) goto done;

	int w = frame->width;
	int h = frame->height;
	if (w <= 0 || h <= 0) goto done;

	rgba = (unsigned char*)malloc((size_t)w * (size_t)h * 4 + SWS_DST_SLACK);
	if (!rgba) goto done;

	if (yuv420_frame_is_supported(frame->format)) {
		// Exact Ruffle conversion — see yuv420_frame_to_rgba_bt601.
		yuv420_frame_to_rgba_bt601(frame, w, h, rgba);
	} else {
		// Any other decoded pixel format (e.g. an H.264 profile that isn't
		// 8-bit 4:2:0) still goes through libswscale.
		sws = sws_getContext(w, h, (enum AVPixelFormat)frame->format,
		                     w, h, AV_PIX_FMT_RGBA,
		                     SWS_BILINEAR, NULL, NULL, NULL);
		if (!sws) { free(rgba); rgba = NULL; goto done; }
		{
			const int* inv_table = sws_getCoefficients(SWS_CS_ITU601);
			const int* table     = sws_getCoefficients(SWS_CS_DEFAULT);
			sws_setColorspaceDetails(sws,
			                          inv_table, /*srcRange=*/0,   // limited / TV
			                          table,     /*dstRange=*/1,   // full
			                          /*brightness=*/0,
			                          /*contrast=*/1 << 16,
			                          /*saturation=*/1 << 16);
		}
		uint8_t* dst_data[4] = { rgba, NULL, NULL, NULL };
		int dst_linesize[4] = { w * 4, 0, 0, 0 };
		if (sws_scale(sws, (const uint8_t* const*)frame->data, frame->linesize,
		              0, h, dst_data, dst_linesize) <= 0) {
			free(rgba); rgba = NULL;
			goto done;
		}
	}

	*out_w = w;
	*out_h = h;
	*out_rgba = rgba;
	ok = 1;

done:
	if (sws) sws_freeContext(sws);
	if (frame) av_frame_free(&frame);
	if (pkt) av_packet_free(&pkt);
	if (cctx) avcodec_free_context(&cctx);
	return ok;
}

#endif // SWF_HAVE_LIBAVCODEC

int video_resample_rgba(const unsigned char* src_rgba, int src_w, int src_h,
                        unsigned char** out_rgba, int dst_w, int dst_h)
{
	if (!src_rgba || !out_rgba || src_w <= 0 || src_h <= 0 || dst_w <= 0 || dst_h <= 0)
		return 0;

	unsigned char* dst = (unsigned char*)malloc((size_t)dst_w * (size_t)dst_h * 4 + SWS_DST_SLACK);
	if (!dst) return 0;

#ifdef SWF_HAVE_LIBAVCODEC
	struct SwsContext* sws = sws_getContext(src_w, src_h, AV_PIX_FMT_RGBA,
	                                        dst_w, dst_h, AV_PIX_FMT_RGBA,
	                                        SWS_BILINEAR, NULL, NULL, NULL);
	if (sws) {
		const uint8_t* src_data[4] = { src_rgba, NULL, NULL, NULL };
		int src_linesize[4] = { src_w * 4, 0, 0, 0 };
		uint8_t* dst_data[4] = { dst, NULL, NULL, NULL };
		int dst_linesize[4] = { dst_w * 4, 0, 0, 0 };
		int rv = sws_scale(sws, src_data, src_linesize, 0, src_h,
		                   dst_data, dst_linesize);
		sws_freeContext(sws);
		if (rv > 0) { *out_rgba = dst; return 1; }
	}
	// libswscale failed — fall through to nearest neighbour.
#endif

	for (int y = 0; y < dst_h; y++) {
		int sy = (y * src_h) / dst_h;
		if (sy >= src_h) sy = src_h - 1;
		for (int x = 0; x < dst_w; x++) {
			int sx = (x * src_w) / dst_w;
			if (sx >= src_w) sx = src_w - 1;
			const unsigned char* sp = src_rgba + (sy * src_w + sx) * 4;
			unsigned char* dp = dst + (y * dst_w + x) * 4;
			dp[0] = sp[0]; dp[1] = sp[1]; dp[2] = sp[2]; dp[3] = sp[3];
		}
	}
	*out_rgba = dst;
	return 1;
}

int video_decode_one_frame(int codec_id, int frame_type,
                           const unsigned char* payload, int payload_len,
                           int* out_w, int* out_h,
                           unsigned char** out_rgba)
{
	(void)frame_type;
	if (!payload || payload_len <= 0 || !out_w || !out_h || !out_rgba) return 0;

#ifdef SWF_HAVE_LIBAVCODEC
	switch (codec_id) {
		case 2: // Sorenson Spark
		case 4: // VP6
		case 5: // VP6 alpha
		case 7: // H.264
			return decode_via_libavcodec(codec_id, payload, payload_len,
			                              out_w, out_h, out_rgba);
		default:
			break;
	}
#endif

	// Codec 3 (ScreenVideo) is handled by the legacy decoder in action.c;
	// callers route it there directly.
	(void)codec_id;
	return 0;
}

// ---------------------------------------------------------------------------
// Persistent decoder
// ---------------------------------------------------------------------------
struct VideoDecoderCtx {
	int codec_id;
#ifdef SWF_HAVE_LIBAVCODEC
	AVCodecContext* cctx;
	struct SwsContext* sws;
	int sws_w, sws_h;
	int sws_pixfmt;
#else
	int unused;
#endif
};

VideoDecoderCtx* video_decoder_create(int codec_id)
{
	if (!video_codec_supported(codec_id)) return NULL;

	VideoDecoderCtx* ctx = (VideoDecoderCtx*)calloc(1, sizeof(VideoDecoderCtx));
	if (!ctx) return NULL;
	ctx->codec_id = codec_id;

#ifdef SWF_HAVE_LIBAVCODEC
	enum AVCodecID avid = map_flv_codec_id(codec_id);
	if (avid == AV_CODEC_ID_NONE) { free(ctx); return NULL; }

	const AVCodec* codec = avcodec_find_decoder(avid);
	if (!codec) { free(ctx); return NULL; }

	ctx->cctx = avcodec_alloc_context3(codec);
	if (!ctx->cctx) { free(ctx); return NULL; }

	if (avcodec_open2(ctx->cctx, codec, NULL) < 0) {
		avcodec_free_context(&ctx->cctx);
		free(ctx);
		return NULL;
	}
#endif
	return ctx;
}

void video_decoder_destroy(VideoDecoderCtx* ctx)
{
	if (!ctx) return;
#ifdef SWF_HAVE_LIBAVCODEC
	if (ctx->sws) sws_freeContext(ctx->sws);
	if (ctx->cctx) avcodec_free_context(&ctx->cctx);
#endif
	free(ctx);
}

int video_decoder_decode(VideoDecoderCtx* ctx, int frame_type,
                         const unsigned char* payload, int payload_len,
                         int* out_w, int* out_h,
                         unsigned char** out_rgba)
{
	(void)frame_type;
	if (!ctx || !payload || payload_len <= 0 || !out_w || !out_h || !out_rgba)
		return 0;

#ifdef SWF_HAVE_LIBAVCODEC
	if (!ctx->cctx) return 0;

	AVPacket* pkt = av_packet_alloc();
	AVFrame* frame = av_frame_alloc();
	unsigned char* rgba = NULL;
	int ok = 0;

	if (!pkt || !frame) goto done;

	pkt->data = (uint8_t*)payload;
	pkt->size = payload_len;

	if (avcodec_send_packet(ctx->cctx, pkt) < 0) goto done;
	if (avcodec_receive_frame(ctx->cctx, frame) < 0) goto done;

	int w = frame->width;
	int h = frame->height;
	if (w <= 0 || h <= 0) goto done;

	rgba = (unsigned char*)malloc((size_t)w * (size_t)h * 4 + SWS_DST_SLACK);
	if (!rgba) goto done;

	if (yuv420_frame_is_supported(frame->format)) {
		// Exact Ruffle conversion — see yuv420_frame_to_rgba_bt601. This is
		// the path every embedded DefineVideoStream (Spark / VP6 / VP6A) and
		// every FLV NetStream frame takes.
		yuv420_frame_to_rgba_bt601(frame, w, h, rgba);
	} else {
		// (Re)build sws context if dimensions or pixel format changed.
		if (!ctx->sws || ctx->sws_w != w || ctx->sws_h != h ||
		    ctx->sws_pixfmt != frame->format) {
			if (ctx->sws) { sws_freeContext(ctx->sws); ctx->sws = NULL; }
			ctx->sws = sws_getContext(w, h, (enum AVPixelFormat)frame->format,
			                          w, h, AV_PIX_FMT_RGBA,
			                          SWS_BILINEAR, NULL, NULL, NULL);
			if (!ctx->sws) { free(rgba); rgba = NULL; goto done; }
			ctx->sws_w = w; ctx->sws_h = h; ctx->sws_pixfmt = frame->format;

			const int* inv_table = sws_getCoefficients(SWS_CS_ITU601);
			const int* table     = sws_getCoefficients(SWS_CS_DEFAULT);
			sws_setColorspaceDetails(ctx->sws,
			                          inv_table, /*srcRange=*/0,
			                          table,     /*dstRange=*/1,
			                          /*brightness=*/0,
			                          /*contrast=*/1 << 16,
			                          /*saturation=*/1 << 16);
		}

		uint8_t* dst_data[4] = { rgba, NULL, NULL, NULL };
		int dst_linesize[4] = { w * 4, 0, 0, 0 };
		if (sws_scale(ctx->sws, (const uint8_t* const*)frame->data, frame->linesize,
		              0, h, dst_data, dst_linesize) <= 0) {
			free(rgba); rgba = NULL;
			goto done;
		}
	}

	*out_w = w;
	*out_h = h;
	*out_rgba = rgba;
	ok = 1;

done:
	if (frame) av_frame_free(&frame);
	if (pkt) av_packet_free(&pkt);
	return ok;
#else
	(void)payload_len;
	return 0;
#endif
}
