// Graphics HOST module for the in-browser SWF recompiler (stage 2).
//
// Pre-built with Emscripten (WebGPU via emdawnwebgpu, ASYNCIFY frame loop) by
// SWFRecomp/scripts/build_graphics_host.sh with -DDYNAMIC_HOST. It contains the
// whole SWFModernRuntime but NO per-SWF generated code. The per-SWF "guest"
// (RecompiledTags/ + RecompiledScripts/ + guest_main_graphics.c) is compiled in
// the browser and instantiated by pipeline.js against this host's memory:
//
//   * The guest imports the host's memory and is linked at --global-base =
//     GUEST_ARENA_BASE (below the host's own data), so its tables live inside
//     host memory in a region the host never uses.
//   * The host is linked with --table-base = HOST_TABLE_BASE, leaving table
//     slots [1, HOST_TABLE_BASE) unused; pipeline.js mirrors the guest's own
//     function table into those slots, so every function pointer the guest
//     stores (frame_funcs, sprite frame funcs, Function2 bodies, sprite frame
//     script tables) is valid in the host with no translation.
//   * Runtime functions the guest calls are host exports (build script exports
//     every defined symbol). Runtime globals the guest references go through
//     bridge_globals.h (DYNAMIC_GUEST) and the get_*_addr accessors below.
//   * Generated data tables the runtime reads directly (transform_data etc.)
//     are declared as pointers in this build (libswf/generated_data.h) and set
//     from the guest's addresses via the set* functions below.

#include <stdio.h>
#include <string.h>
#include <emscripten.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <variables.h>
#include <libswf/generated_data.h>

#ifndef DYNAMIC_HOST
#error "host_main_graphics.c must be compiled with -DDYNAMIC_HOST"
#endif

// Reserved by the build script: table slots below this belong to the guest.
#ifndef HOST_TABLE_BASE
#define HOST_TABLE_BASE 262144
#endif

// Guest data arena: the host is linked with -sGLOBAL_BASE=GUEST_ARENA_END, so
// its own static data, stack and heap all live at or above that address and
// [GUEST_ARENA_BASE, GUEST_ARENA_END) is never touched by the host. The guest is
// linked with --global-base=GUEST_ARENA_BASE, a constant pipeline.js also knows,
// so the guest can be compiled before the host is even loaded.
#ifndef GUEST_ARENA_BASE
#define GUEST_ARENA_BASE 65536u
#endif
#ifndef GUEST_ARENA_END
#define GUEST_ARENA_END (101u * 1024u * 1024u)
#endif

SWFAppContext app_context = { .frame_funcs = NULL, .frame_count = 0 };

// --- Generated tables, pointer form (see generated_data.h) ---
float (*transform_data)[16] = NULL;
u32 (*shape_data)[4] = NULL;
u32 (*glyph_data)[1] = NULL;
u32* text_data = NULL;
u16* text_char_codes = NULL;
float* cxform_data = NULL;
u8* bitmap_data = NULL;
float (*morph_end_shape_data)[2] = NULL;
FrameLabelEntry* frame_label_data = NULL;
size_t frame_label_count = 0;

// tagInit is normally generated (tagMain.c); here it forwards to the guest's.
static void (*tagInit_func)(SWFAppContext*) = NULL;
void tagInit(SWFAppContext* ctx) { if (tagInit_func) tagInit_func(ctx); }

// --- Weak stubs for NO_GRAPHICS/OFFSCREEN_RENDER-only symbols ---
// swf.c's goto catch-up path (ng_executeGotoCatchUp) references these; in a
// normal graphics build that function is dead and GC'd before the linker
// checks undefined symbols, but this host exports every runtime symbol (so
// the guest can import any of them), which keeps it alive. Weak, so a real
// definition (if one ever moves out of the NO_GRAPHICS block) wins.
__attribute__((weak)) int g_defer_sprite_init = 0;
__attribute__((weak)) int ng_swapToRootDL(DisplayObject** saved_dl, size_t* saved_max, size_t* saved_cap) { (void)saved_dl; (void)saved_max; (void)saved_cap; return 0; }
__attribute__((weak)) void ng_restoreFromRootDL(DisplayObject* saved_dl, size_t saved_max, size_t saved_cap) { (void)saved_dl; (void)saved_max; (void)saved_cap; }
__attribute__((weak)) void ng_run_deferred_sprite_init_before(SWFAppContext* ctx, size_t target_frame) { (void)ctx; (void)target_frame; }
__attribute__((weak)) void ng_run_deferred_sprite_init_on_or_after(SWFAppContext* ctx, size_t target_frame) { (void)ctx; (void)target_frame; }
__attribute__((weak)) void actionRewindCleanup(SWFAppContext* ctx) { (void)ctx; }

// --- Exported configuration API (called from pipeline.js) ---

EMSCRIPTEN_KEEPALIVE int get_guest_arena(void) { return (int)GUEST_ARENA_BASE; }
EMSCRIPTEN_KEEPALIVE int get_guest_arena_size(void) { return (int)(GUEST_ARENA_END - GUEST_ARENA_BASE); }
EMSCRIPTEN_KEEPALIVE int get_host_table_base(void) { return HOST_TABLE_BASE; }

EMSCRIPTEN_KEEPALIVE
void configureAppContext(int frame_count, int fps, int swf_version, int width, int height) {
    extern int g_swf_version;
    extern int g_main_movie_swf_version;
    extern int g_use_network;
    g_swf_version = swf_version;
    g_main_movie_swf_version = swf_version;
    g_use_network = 0;

    app_context.frame_count = frame_count;
    app_context.fps = fps;
    app_context.width = width;
    app_context.height = height;
    // Browser build: render target == stage, no viewport fit (main.c does the
    // same for non-test builds).
    app_context.render_width = width;
    app_context.render_height = height;
    app_context.stage_scale = 1.0f;
    app_context.stage_fit_x = 1.0f;
    app_context.stage_fit_y = 1.0f;
    app_context.heap_full_size = 128 * 1024 * 1024;
}

EMSCRIPTEN_KEEPALIVE void setFrameFuncs(frame_func* funcs) { app_context.frame_funcs = funcs; }
EMSCRIPTEN_KEEPALIVE void setTagInit(void (*func)(SWFAppContext*)) { tagInit_func = func; }

EMSCRIPTEN_KEEPALIVE void setShapeData(void* data, int size) {
    app_context.shape_data = (char*)data; app_context.shape_data_size = size;
    shape_data = (u32 (*)[4])data;
}
EMSCRIPTEN_KEEPALIVE void setTransformData(void* data, int size) {
    app_context.transform_data = (char*)data; app_context.transform_data_size = size;
    transform_data = (float (*)[16])data;
}
EMSCRIPTEN_KEEPALIVE void setColorData(void* data, int size) {
    app_context.color_data = (char*)data; app_context.color_data_size = size;
}
EMSCRIPTEN_KEEPALIVE void setStageToNdc(float* matrix) { app_context.stage_to_ndc = matrix; }
EMSCRIPTEN_KEEPALIVE void setBitmapInfo(int count, int highest_w, int highest_h) {
    app_context.bitmap_count = count;
    app_context.bitmap_highest_w = highest_w;
    app_context.bitmap_highest_h = highest_h;
}
EMSCRIPTEN_KEEPALIVE void setUninvMatData(void* data, int size) {
    app_context.uninv_mat_data = (char*)data; app_context.uninv_mat_data_size = size;
}
EMSCRIPTEN_KEEPALIVE void setGradientData(void* data, int size) {
    app_context.gradient_data = (char*)data; app_context.gradient_data_size = size;
}
EMSCRIPTEN_KEEPALIVE void setBitmapData(void* data, int size) {
    app_context.bitmap_data = (char*)data; app_context.bitmap_data_size = size;
    bitmap_data = (u8*)data;
}
EMSCRIPTEN_KEEPALIVE void setGlyphData(void* data, int size) {
    app_context.glyph_data = (u32*)data; app_context.glyph_data_size = size;
    glyph_data = (u32 (*)[1])data;
}
EMSCRIPTEN_KEEPALIVE void setTextData(void* data, int size, void* char_codes) {
    app_context.text_data = (u32*)data; app_context.text_data_size = size;
    text_data = (u32*)data;
    text_char_codes = (u16*)char_codes;   // NULL when the generated code has none
}
EMSCRIPTEN_KEEPALIVE void setCxformData(void* data, int size) {
    app_context.cxform_data = (char*)data; app_context.cxform_data_size = size;
    cxform_data = (float*)data;
}
EMSCRIPTEN_KEEPALIVE void setMorphData(void* shape, int shape_size, void* color, int color_size) {
    app_context.morph_end_shape_data = (char*)shape; app_context.morph_end_shape_data_size = shape_size;
    app_context.morph_end_color_data = (char*)color; app_context.morph_end_color_data_size = color_size;
    morph_end_shape_data = (float (*)[2])shape;
}
EMSCRIPTEN_KEEPALIVE void setFrameLabels(void* data, int count) {
    frame_label_data = (FrameLabelEntry*)data;
    frame_label_count = (size_t)count;
}

// --- Global variable addresses for the guest's bridge_globals ---
extern int catch_up_mode;
extern int g_tag_skip_mode;
extern int quit_swf;
extern ActionVar g_override_this;
extern int g_override_this_set;
EMSCRIPTEN_KEEPALIVE int* get_catch_up_mode_addr(void) { return &catch_up_mode; }
EMSCRIPTEN_KEEPALIVE int* get_g_tag_skip_mode_addr(void) { return &g_tag_skip_mode; }
EMSCRIPTEN_KEEPALIVE int* get_quit_swf_addr(void) { return &quit_swf; }
EMSCRIPTEN_KEEPALIVE void* get_g_override_this_addr(void) { return &g_override_this; }
EMSCRIPTEN_KEEPALIVE int* get_g_override_this_set_addr(void) { return &g_override_this_set; }

// --- Entry point ---
EMSCRIPTEN_KEEPALIVE
void runSWF(void) {
    printf("Starting SWF execution (graphics host)...\n");
    swfStart(&app_context);
}

int main(void) {
    printf("Graphics host loaded (table base %d, guest arena [%u, %u)).\n",
           HOST_TABLE_BASE, GUEST_ARENA_BASE, GUEST_ARENA_END);
    return 0;
}
