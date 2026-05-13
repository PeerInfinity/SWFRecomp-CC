#include "actionmodern/video_codec.h"

#include <stdlib.h>
#include <string.h>

#ifdef SWF_HAVE_LIBAVCODEC
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
#endif

int video_codec_supported(int codec_id)
{
	switch (codec_id) {
		case 3: // ScreenVideo — hand-rolled decoder in action.c
			return 1;
#ifdef SWF_HAVE_LIBAVCODEC
		case 2: // Sorenson Spark
			return avcodec_find_decoder(AV_CODEC_ID_FLV1) != NULL;
#endif
		default:
			return 0;
	}
}

#ifdef SWF_HAVE_LIBAVCODEC

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

	sws = sws_getContext(w, h, (enum AVPixelFormat)frame->format,
	                     w, h, AV_PIX_FMT_RGBA,
	                     SWS_BILINEAR, NULL, NULL, NULL);
	if (!sws) goto done;

	// Ruffle's h263-rs-yuv uses ITU-R BT.601 with TV-range YUV input
	// (16..235 luma, 16..240 chroma) expanded to full-range RGB output
	// (0..255). H.263 / Sorenson Spark streams don't carry colorspace tags so
	// swscale auto-detection can pick the wrong matrix or range and shift
	// solid colors by 1-3 levels. Force the choice explicitly.
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

	rgba = (unsigned char*)malloc((size_t)w * (size_t)h * 4);
	if (!rgba) goto done;

	uint8_t* dst_data[4] = { rgba, NULL, NULL, NULL };
	int dst_linesize[4] = { w * 4, 0, 0, 0 };
	if (sws_scale(sws, (const uint8_t* const*)frame->data, frame->linesize,
	              0, h, dst_data, dst_linesize) <= 0) {
		free(rgba); rgba = NULL;
		goto done;
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

	unsigned char* dst = (unsigned char*)malloc((size_t)dst_w * (size_t)dst_h * 4);
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
