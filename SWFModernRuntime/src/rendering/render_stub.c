// render_stub.c — no-op implementation of the render_webgpu_* API.
//
// Purpose: compile the browser-WASM graphics arm (!NO_GRAPHICS &&
// !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS) NATIVELY, with no GPU, no SDL and
// no Dawn link, so that sanitizers (ASAN + -DHEAP_PASSTHROUGH in heap.c) can
// reach the attached-clip / display-list machinery that only that build mode
// executes. All draw/upload calls are no-ops; init mimics the real renderer's
// observable side effects (renderer_ok=1 and the xform/cxform slot counts
// that tag.c's dynamic slot allocators read), so tag.c's full per-tick render
// walk — compose_children, child_mc_cache passes, textfield glyph iteration —
// still runs and dereferences everything it would dereference in a browser.
//
// Build: compile INSTEAD OF render_webgpu.c, with -DUSE_WEBGPU and a webgpu.h
// on the include path (only needed for the WGPU* typedef fields in
// WebGPURenderContext — never dereferenced here).

#include <stdlib.h>
#include <render_webgpu.h>
#include <libswf/swf.h>

// Input-event globals normally defined by render_webgpu.c's emscripten
// callback section and drained per-frame by swf.c. No events ever arrive in
// the stub harness, so empty ring / never-blurred is correct.
#define TEXT_INPUT_RING_SIZE 64
int g_text_input_ring[TEXT_INPUT_RING_SIZE];
int g_text_input_ring_head = 0;
int g_text_input_ring_tail = 0;
int g_window_focus_lost = 0;
#define IME_TEXT_BUF_SIZE 256
char g_ime_compose_text[IME_TEXT_BUF_SIZE];
char g_ime_commit_text[IME_TEXT_BUF_SIZE];
int g_ime_compose_pending = 0;
int g_ime_commit_pending = 0;

WebGPURenderContext* render_webgpu_new(void)
{
	return (WebGPURenderContext*)calloc(1, sizeof(WebGPURenderContext));
}

void render_webgpu_init(SWFAppContext* app_context, WebGPURenderContext* ctx)
{
	(void)app_context;
	// Mirror the real init's slot-count math (render_webgpu.c ~830/~903) so
	// tag.c's g_xform_slot_capacity / g_cxform_slot_capacity match a real run.
	u32 orig_slots = (u32)(ctx->transform_data_size / (16 * sizeof(float)));
	ctx->xform_slot_count = orig_slots + 512;
	u32 orig_cxform_slots = (u32)(ctx->cxform_data_size / (20 * sizeof(float)));
	ctx->cxform_slot_count = orig_cxform_slots + 256;
	ctx->renderer_ok = 1;
}

int render_webgpu_poll(SWFAppContext* app_context) { (void)app_context; return 0; }
void render_webgpu_set_background(WebGPURenderContext* c, u8 r, u8 g, u8 b) { (void)c; (void)r; (void)g; (void)b; }
void render_webgpu_upload_bitmap(WebGPURenderContext* c, size_t o, size_t s, u32 w, u32 h) { (void)c; (void)o; (void)s; (void)w; (void)h; }
void render_webgpu_finalize_bitmaps(WebGPURenderContext* c) { (void)c; }
void render_webgpu_open_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_upload_stage_transform(WebGPURenderContext* c, const float m[16]) { (void)c; (void)m; }
void render_webgpu_upload_extra_transform_id(WebGPURenderContext* c, u32 t) { (void)c; (void)t; }
void render_webgpu_upload_extra_transform(WebGPURenderContext* c, float* t) { (void)c; (void)t; }
void render_webgpu_upload_cxform_id(WebGPURenderContext* c, u32 id) { (void)c; (void)id; }
void render_webgpu_upload_cxform(WebGPURenderContext* c, float* cx) { (void)c; (void)cx; }
void render_webgpu_draw_shape(WebGPURenderContext* c, size_t o, size_t n, u32 t, u32 cx) { (void)c; (void)o; (void)n; (void)t; (void)cx; }
void render_webgpu_draw_rect(WebGPURenderContext* c, float x, float y, float w, float h, float r, float g, float b, float a, u32 t, u32 cx) { (void)c; (void)x; (void)y; (void)w; (void)h; (void)r; (void)g; (void)b; (void)a; (void)t; (void)cx; }
void render_webgpu_draw_tris(WebGPURenderContext* c, const float* v, u32 n, float r, float g, float b, float a, u32 t, u32 cx) { (void)c; (void)v; (void)n; (void)r; (void)g; (void)b; (void)a; (void)t; (void)cx; }
void render_webgpu_draw_gradient_tris(WebGPURenderContext* c, const float* v, u32 n, u8 gt, u8 sm, u8 in, float fr, const u8* ramp, const float* mat, u32 t, u32 cx) { (void)c; (void)v; (void)n; (void)gt; (void)sm; (void)in; (void)fr; (void)ramp; (void)mat; (void)t; (void)cx; }
void render_webgpu_draw_bitmap_quad(WebGPURenderContext* c, const uint32_t* px, u32 w, u32 h, float x, float y, u32 t, u32 cx) { (void)c; (void)px; (void)w; (void)h; (void)x; (void)y; (void)t; (void)cx; }
void render_webgpu_draw_bitmap_quad_scaled(WebGPURenderContext* c, const uint32_t* px, u32 sw, u32 sh, u32 dw, u32 dh, float x, float y, u32 t, u32 cx) { (void)c; (void)px; (void)sw; (void)sh; (void)dw; (void)dh; (void)x; (void)y; (void)t; (void)cx; }
void render_webgpu_draw_bitmap_tris(WebGPURenderContext* c, const float* v, u32 n, const uint32_t* px, u32 sw, u32 sh, const float* m6, int rep, int smo, u32 t, u32 cx) { (void)c; (void)v; (void)n; (void)px; (void)sw; (void)sh; (void)m6; (void)rep; (void)smo; (void)t; (void)cx; }
void render_webgpu_begin_clip_mask(WebGPURenderContext* c) { (void)c; }
void render_webgpu_end_clip_mask(WebGPURenderContext* c) { (void)c; }
void render_webgpu_end_clip(WebGPURenderContext* c) { (void)c; }
void render_webgpu_close_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_compose_text_transforms(WebGPURenderContext* c, const char* td, u32 pt, u32 gs, size_t n) { (void)c; (void)td; (void)pt; (void)gs; (void)n; }
void render_webgpu_compose_sprite_transform(WebGPURenderContext* c, const char* td, u32 pt, u32 ct) { (void)c; (void)td; (void)pt; (void)ct; }
void render_webgpu_write_transform(WebGPURenderContext* c, u32 id, const float xf[16]) { (void)c; (void)id; (void)xf; }
void render_webgpu_write_cxform(WebGPURenderContext* c, u32 slot, const float cx[20]) { (void)c; (void)slot; (void)cx; }
void render_webgpu_update_vertices(WebGPURenderContext* c, size_t o, const void* d, size_t s) { (void)c; (void)o; (void)d; (void)s; }
void render_webgpu_update_colors(WebGPURenderContext* c, size_t o, const void* d, size_t s) { (void)c; (void)o; (void)d; (void)s; }
void render_webgpu_set_blend_mode(WebGPURenderContext* c, u8 m) { (void)c; (void)m; }
void render_webgpu_suspend_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_resume_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_begin_offscreen_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_end_offscreen_pass(WebGPURenderContext* c) { (void)c; }
void render_webgpu_run_blur(WebGPURenderContext* c, float bx, float by, u8 q, float st, float r, float g, float b, float a, int col) { (void)c; (void)bx; (void)by; (void)q; (void)st; (void)r; (void)g; (void)b; (void)a; (void)col; }
void render_webgpu_composite_filtered(WebGPURenderContext* c, float ox, float oy, float tr, float tg, float tb, float ta) { (void)c; (void)ox; (void)oy; (void)tr; (void)tg; (void)tb; (void)ta; }
void render_webgpu_ensure_filter_resources(WebGPURenderContext* c) { (void)c; }
void render_webgpu_free(SWFAppContext* app_context, WebGPURenderContext* c) { (void)app_context; free(c); }
