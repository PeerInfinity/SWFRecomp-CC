#include <recomp.h>
#include <swf.h>
#include <out.h>
#include "constants.h"

#ifndef FRAME_RATE
#define FRAME_RATE 12
#endif

#ifndef SWF_VERSION
#define SWF_VERSION 4
#endif

#ifndef SWF_USE_NETWORK
#define SWF_USE_NETWORK 0
#endif

#include "draws.h"

SWFAppContext app_context = {
    .frame_funcs = NULL,
    .frame_count = 0
};

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <string.h>
#include <actionmodern/action.h>
#include <actionmodern/stackvalue.h>

EMSCRIPTEN_KEEPALIVE
void runSWF() {
    printf("Starting SWF execution from JavaScript...\n");
    swfStart(&app_context);
}

// Host->AS inward bridge: synchronously invoke an ExternalInterface callback the
// SWF registered via ExternalInterface.addCallback(name, ...), passing one
// optional string arg, and return its string result as UTF-8. This is the
// host-initiated (addCallback) EI direction — the opposite of the cooperative
// __swfBridge pull (AS-initiated ExternalInterface.call -> window[name]) — and
// is what flashPanel's memory-poke style needs (configure(json) / readState()).
// The browser exposes this to JS via Module.ccall('swf_ei_call_internal', ...).
//
// Safe to call from a JS timer: the movie loop parks at emscripten_sleep between
// frames (ASYNCIFY), so this runs while no frame is mid-execution — the same
// quiescent window where the cooperative pull observes state. addCallback only
// registers when g_external_call_handler is installed (page exposed
// window.__swfBridge), so ExternalInterface.available must be true first.
extern uint16_t* utf8_to_u16(SWFAppContext* app_context, const char* utf8, u32 byte_len, u32* out_u16_len);

EMSCRIPTEN_KEEPALIVE
const char* swf_ei_call_internal(const char* name, const char* arg) {
    static char out_buf[262144];   // 256 KB — ample for a realistic readState JSON
    out_buf[0] = '\0';

    ActionVar av;
    memset(&av, 0, sizeof(av));
    int argc = 0;
    if (arg && arg[0]) {
        u32 n16 = 0;
        uint16_t* u16 = utf8_to_u16(&app_context, arg, (u32)strlen(arg), &n16);
        av.type = ACTION_STACK_VALUE_STRING;
        av.str_size = n16;
        av.data.string_data.heap_ptr = u16;
        av.data.string_data.owns_memory = true;
        argc = 1;
    } else {
        av.type = ACTION_STACK_VALUE_UNDEFINED;
    }

    ActionVar r = actionEI_callInternalInterface(&app_context, name, &av, argc);
    ei_actionvar_to_utf8(&r, out_buf, sizeof(out_buf));   // STRING -> UTF-8; else ""
    return out_buf;
}
#endif

#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)
void input_events_load(const char* path);
#endif

int main(int argc, char* argv[]) {
    extern int g_swf_version;
    g_swf_version = SWF_VERSION;
    extern int g_main_movie_swf_version;
    g_main_movie_swf_version = SWF_VERSION;
    extern int g_use_network;
    g_use_network = SWF_USE_NETWORK;

    app_context.frame_funcs = frame_funcs;
    app_context.frame_count = FRAME_COUNT;
    app_context.fps = FRAME_RATE;

    app_context.shape_data = (char*)shape_data;
    app_context.shape_data_size = sizeof(shape_data);
    app_context.transform_data = (char*)transform_data;
    app_context.transform_data_size = sizeof(transform_data);

#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)
    app_context.width = FRAME_WIDTH;
    app_context.height = FRAME_HEIGHT;
    app_context.stage_to_ndc = stage_to_ndc;
    app_context.bitmap_count = BITMAP_COUNT;
    app_context.bitmap_highest_w = BITMAP_HIGHEST_W;
    app_context.bitmap_highest_h = BITMAP_HIGHEST_H;
    app_context.color_data = (char*)color_data;
    app_context.color_data_size = sizeof(color_data);
    app_context.uninv_mat_data = (char*)uninv_mat_data;
    app_context.uninv_mat_data_size = sizeof(uninv_mat_data);
    app_context.gradient_data = (char*)gradient_data;
    app_context.gradient_data_size = sizeof(gradient_data);
    app_context.bitmap_data = (char*)bitmap_data;
    app_context.bitmap_data_size = sizeof(bitmap_data);
    app_context.glyph_data = (u32*)glyph_data;
    app_context.glyph_data_size = sizeof(glyph_data);
    app_context.text_data = text_data;
    app_context.text_data_size = sizeof(text_data);
    app_context.cxform_data = (char*)cxform_data;
    app_context.cxform_data_size = sizeof(cxform_data);
    app_context.morph_end_shape_data = (char*)morph_end_shape_data;
    app_context.morph_end_shape_data_size = sizeof(morph_end_shape_data);
    app_context.morph_end_color_data = (char*)morph_end_color_data;
    app_context.morph_end_color_data_size = sizeof(morph_end_color_data);
#endif

#ifdef HAS_TEST_HARNESS
    {
        extern void test_harness_init(SWFAppContext*);
        test_harness_init(&app_context);
    }
#endif

#ifndef __EMSCRIPTEN__
    printf("SWF Runtime Loaded (Native Build)\n\n");
#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)
    if (argc > 1) {
        input_events_load(argv[1]);
    }
#endif
    swfStart(&app_context);
#else
    printf("WASM SWF Runtime Loaded!\n");
    printf("This is a recompiled Flash SWF running in WebAssembly.\n\n");
    printf("Call runSWF() from JavaScript to execute the SWF.\n");
#endif

    return 0;
}
