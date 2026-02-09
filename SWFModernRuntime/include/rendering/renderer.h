#pragma once

// Renderer abstraction layer.
// Dispatches to either flashbang (SDL3 GPU) or WebGPU based on USE_WEBGPU flag.
// Used by swf.c and tag.c — these files include this header instead of
// flashbang.h or render_webgpu.h directly.

#include <common.h>

typedef struct SWFAppContext SWFAppContext;

#if defined(USE_WEBGPU)

#include <render_webgpu.h>
typedef WebGPURenderContext RenderContext;

#define renderer_new()                             render_webgpu_new()
#define renderer_init(app, ctx)                    render_webgpu_init(app, ctx)
#define renderer_poll(app)                         render_webgpu_poll(app)
#define renderer_set_background(ctx, r, g, b)      render_webgpu_set_background(ctx, r, g, b)
#define renderer_open_pass(ctx)                    render_webgpu_open_pass(ctx)
#define renderer_draw_shape(ctx, o, n, t, c)       render_webgpu_draw_shape(ctx, o, n, t, c)
#define renderer_begin_clip_mask(ctx)              render_webgpu_begin_clip_mask(ctx)
#define renderer_end_clip_mask(ctx)                render_webgpu_end_clip_mask(ctx)
#define renderer_end_clip(ctx)                     render_webgpu_end_clip(ctx)
#define renderer_close_pass(ctx)                   render_webgpu_close_pass(ctx)
#define renderer_free(app, ctx)                    render_webgpu_free(app, ctx)
#define renderer_upload_bitmap(ctx, o, s, w, h)    render_webgpu_upload_bitmap(ctx, o, s, w, h)
#define renderer_finalize_bitmaps(ctx)             render_webgpu_finalize_bitmaps(ctx)
#define renderer_upload_extra_transform_id(ctx, t) render_webgpu_upload_extra_transform_id(ctx, t)
#define renderer_upload_extra_transform(ctx, xf)   render_webgpu_upload_extra_transform(ctx, xf)
#define renderer_upload_cxform_id(ctx, id)         render_webgpu_upload_cxform_id(ctx, id)
#define renderer_upload_cxform(ctx, cx)            render_webgpu_upload_cxform(ctx, cx)
#define renderer_compose_text_transforms(ctx, td, pt, gs, c) render_webgpu_compose_text_transforms(ctx, td, pt, gs, c)
#define renderer_compose_sprite_transform(ctx, td, pt, ct) render_webgpu_compose_sprite_transform(ctx, td, pt, ct)
#define renderer_write_transform(ctx, id, xf) render_webgpu_write_transform(ctx, id, xf)
#define renderer_update_vertices(ctx, off, data, sz)  render_webgpu_update_vertices(ctx, off, data, sz)
#define renderer_update_colors(ctx, off, data, sz)    render_webgpu_update_colors(ctx, off, data, sz)
#define renderer_set_blend_mode(ctx, mode)            render_webgpu_set_blend_mode(ctx, mode)
#define renderer_suspend_pass(ctx)                    render_webgpu_suspend_pass(ctx)
#define renderer_resume_pass(ctx)                     render_webgpu_resume_pass(ctx)
#define renderer_begin_offscreen_pass(ctx)            render_webgpu_begin_offscreen_pass(ctx)
#define renderer_end_offscreen_pass(ctx)              render_webgpu_end_offscreen_pass(ctx)
#define renderer_run_blur(ctx, bx, by, q, s, r, g, b, a, c) render_webgpu_run_blur(ctx, bx, by, q, s, r, g, b, a, c)
#define renderer_composite_filtered(ctx, ox, oy)      render_webgpu_composite_filtered(ctx, ox, oy)
#define renderer_ensure_filter_resources(ctx)          render_webgpu_ensure_filter_resources(ctx)

#else

#include <flashbang.h>
typedef FlashbangContext RenderContext;

#define renderer_new()                             flashbang_new()
#define renderer_init(app, ctx)                    flashbang_init(app, ctx)
#define renderer_poll(app)                         flashbang_poll(app)
#define renderer_set_background(ctx, r, g, b)      flashbang_set_window_background(ctx, r, g, b)
#define renderer_open_pass(ctx)                    flashbang_open_pass(ctx)
#define renderer_draw_shape(ctx, o, n, t, c)       flashbang_draw_shape(ctx, o, n, t, c)
#define renderer_begin_clip_mask(ctx)              ((void)0)
#define renderer_end_clip_mask(ctx)                ((void)0)
#define renderer_end_clip(ctx)                     ((void)0)
#define renderer_close_pass(ctx)                   flashbang_close_pass(ctx)
#define renderer_free(app, ctx)                    flashbang_free(app, ctx)
#define renderer_upload_bitmap(ctx, o, s, w, h)    flashbang_upload_bitmap(ctx, o, s, w, h)
#define renderer_finalize_bitmaps(ctx)             flashbang_finalize_bitmaps(ctx)
#define renderer_upload_extra_transform_id(ctx, t) flashbang_upload_extra_transform_id(ctx, t)
#define renderer_upload_extra_transform(ctx, xf)   flashbang_upload_extra_transform(ctx, xf)
#define renderer_upload_cxform_id(ctx, id)         flashbang_upload_cxform_id(ctx, id)
#define renderer_upload_cxform(ctx, cx)            flashbang_upload_cxform(ctx, cx)
#define renderer_compose_text_transforms(ctx, td, pt, gs, c) ((void)0)
#define renderer_compose_sprite_transform(ctx, td, pt, ct) ((void)0)
#define renderer_write_transform(ctx, id, xf) ((void)0)
#define renderer_update_vertices(ctx, off, data, sz)  ((void)0)
#define renderer_update_colors(ctx, off, data, sz)    ((void)0)
#define renderer_set_blend_mode(ctx, mode)            ((void)0)
#define renderer_suspend_pass(ctx)                    ((void)0)
#define renderer_resume_pass(ctx)                     ((void)0)
#define renderer_begin_offscreen_pass(ctx)            ((void)0)
#define renderer_end_offscreen_pass(ctx)              ((void)0)
#define renderer_run_blur(ctx, bx, by, q, s, r, g, b, a, c) ((void)0)
#define renderer_composite_filtered(ctx, ox, oy)      ((void)0)
#define renderer_ensure_filter_resources(ctx)          ((void)0)

#endif
