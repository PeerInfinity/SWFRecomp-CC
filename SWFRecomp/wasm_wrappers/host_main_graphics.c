// Graphics host module for in-browser SWF recompiler demo.
// Pre-built with Emscripten (WebGPU, ASYNCIFY). Per-SWF generated code
// is compiled in-browser and dynamically linked via shared memory + function table.

#include <stdio.h>
#include <string.h>
#include <emscripten.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <variables.h>

// The app context is configured by JS before calling runSWF()
SWFAppContext app_context = {
    .frame_funcs = NULL,
    .frame_count = 0
};

// Pre-allocated frame function array (max 1024 frames)
#define MAX_FRAMES 1024
static frame_func host_frame_funcs[MAX_FRAMES];

// tagInit is normally provided by generated tagMain.c. In the host module,
// it's a function pointer set by JS to call the guest's tagInit.
static void (*tagInit_func)(SWFAppContext*) = NULL;

void tagInit(SWFAppContext* ctx) {
    if (tagInit_func) tagInit_func(ctx);
}

// These symbols are normally defined in generated code (draws.c, constants.c, tagMain.c).
// The host provides zero-length defaults; actual data comes from the guest module
// via setShapeData/setTransformData/etc. which set app_context pointers directly.
// The extern references in tag.c/action.c need SOME definition to link.
float transform_data[1][16] = {{0}};
u32 shape_data[1][4] = {{0}};
u32 text_data[1] = {0};
float morph_end_shape_data[1][2] = {{0}};

#include <actionmodern/stackvalue.h>
FrameLabelEntry* frame_label_data = NULL;
size_t frame_label_count = 0;

// --- Stubs for symbols defined in tag_stubs.c/swf_core.c but referenced by action.c ---
// These are needed because the graphics build uses tag.c/swf.c instead.

u8 g_current_movie_id = 0;
float (*g_active_transform_data)[16] = 0;

// findDataFile is in swf_core.c — stub for graphics mode
DataFileEntry* findDataFile(const char* filename) { return NULL; }

// ng_lookupExportVersion is in tag_stubs.c — stub returns -1 (not found)
int ng_lookupExportVersion(const char* name) { return -1; }
int ng_lookupExportVersionForMovie(const char* name, u8 movie_id) { return -1; }

// These are defined in tag_stubs.c (NO_GRAPHICS only) but referenced by action.c
size_t ng_getCharIdByMC(MovieClip* mc) { return 0; }
size_t ng_getSpriteByteSize(size_t char_id) { return 0; }
int ng_gotoFrameByMC(SWFAppContext* ctx, MovieClip* mc, u16 frame, int play) { return 0; }
size_t ng_lookupExportForMovie(const char* name, u8 movie_id) { return 0; }
void tagImportCharacter(SWFAppContext* ctx, size_t char_id, const char* name) {}
void tagScriptLimits(u16 max_recursion, u16 timeout) {}

// Event dispatch stubs — these are in NO_GRAPHICS code paths only
void actionAdvanceTabFocus(SWFAppContext* ctx, int direction) {}
void actionFlushDeferredRollEvents(SWFAppContext* ctx) {}

// --- Exported configuration API (called from JS bridge) ---

EMSCRIPTEN_KEEPALIVE
void configureAppContext(int frame_count, int fps, int swf_version, int width, int height) {
    extern int g_swf_version;
    g_swf_version = swf_version;
    extern int g_use_network;
    g_use_network = 0;

    app_context.frame_funcs = host_frame_funcs;
    app_context.frame_count = frame_count;
    app_context.fps = fps;
    app_context.width = width;
    app_context.height = height;
    app_context.heap_full_size = 128 * 1024 * 1024;  // 128 MB (vs 1 GB default)
}

EMSCRIPTEN_KEEPALIVE
void setFrameFunc(int index, void (*func)(SWFAppContext*)) {
    if (index >= 0 && index < MAX_FRAMES) {
        host_frame_funcs[index] = func;
    }
}

EMSCRIPTEN_KEEPALIVE
void setTagInit(void (*func)(SWFAppContext*)) {
    tagInit_func = func;
}

EMSCRIPTEN_KEEPALIVE
void setShapeData(void* data, int size) {
    app_context.shape_data = (char*)data;
    app_context.shape_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setTransformData(void* data, int size) {
    app_context.transform_data = (char*)data;
    app_context.transform_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setColorData(void* data, int size) {
    app_context.color_data = (char*)data;
    app_context.color_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setStageToNdc(float* matrix) {
    app_context.stage_to_ndc = matrix;
}

EMSCRIPTEN_KEEPALIVE
void setBitmapInfo(int count, int highest_w, int highest_h) {
    app_context.bitmap_count = count;
    app_context.bitmap_highest_w = highest_w;
    app_context.bitmap_highest_h = highest_h;
}

EMSCRIPTEN_KEEPALIVE
void setUninvMatData(void* data, int size) {
    app_context.uninv_mat_data = (char*)data;
    app_context.uninv_mat_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setGradientData(void* data, int size) {
    app_context.gradient_data = (char*)data;
    app_context.gradient_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setBitmapData(void* data, int size) {
    app_context.bitmap_data = (char*)data;
    app_context.bitmap_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setGlyphData(void* data, int size) {
    app_context.glyph_data = (u32*)data;
    app_context.glyph_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setTextData(void* data, int size) {
    app_context.text_data = (u32*)data;
    app_context.text_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setCxformData(void* data, int size) {
    app_context.cxform_data = (char*)data;
    app_context.cxform_data_size = size;
}

EMSCRIPTEN_KEEPALIVE
void setMorphData(void* shape_data, int shape_size, void* color_data, int color_size) {
    app_context.morph_end_shape_data = (char*)shape_data;
    app_context.morph_end_shape_data_size = shape_size;
    app_context.morph_end_color_data = (char*)color_data;
    app_context.morph_end_color_data_size = color_size;
}

// --- Global variable address accessors (for bridge_globals) ---

extern int catch_up_mode;
extern int g_tag_skip_mode;
extern int quit_swf;

EMSCRIPTEN_KEEPALIVE int* get_catch_up_mode_addr(void) { return &catch_up_mode; }
EMSCRIPTEN_KEEPALIVE int* get_g_tag_skip_mode_addr(void) { return &g_tag_skip_mode; }
EMSCRIPTEN_KEEPALIVE int* get_quit_swf_addr(void) { return &quit_swf; }

// g_override_this and g_override_this_set are in action.c
extern ActionVar g_override_this;
extern int g_override_this_set;
EMSCRIPTEN_KEEPALIVE void* get_g_override_this_addr(void) { return &g_override_this; }
EMSCRIPTEN_KEEPALIVE int* get_g_override_this_set_addr(void) { return &g_override_this_set; }

// --- Entry points ---

EMSCRIPTEN_KEEPALIVE
void runSWF() {
    printf("Starting SWF execution (graphics host)...\n");
    swfStart(&app_context);
}

// Note: the real audio_fill_buffer is in audio_output_web.c and returns float*.
// We don't need a stub since it's compiled from audio_output_web.c.

int main() {
    printf("Graphics host module loaded.\n");
    printf("Configure via JS, then call runSWF().\n");
    return 0;
}
