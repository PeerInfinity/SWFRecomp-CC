// Guest main for graphics mode: exports frame functions, data arrays, and bridge_init.
// Compiled in-browser with Wasmer clang, linked with wasm-ld --allow-undefined.
// Runtime functions (tag*, action*, etc.) become WASM imports resolved by the host.

#include <recomp.h>
#include <out.h>
#include "constants.h"
#include "draws.h"
#include "bridge_globals.h"

// Export the frame function array info for JS to read
__attribute__((export_name("get_frame_count")))
int get_frame_count(void) { return FRAME_COUNT; }

__attribute__((export_name("get_fps")))
int get_fps(void) {
#ifdef FRAME_RATE
    return FRAME_RATE;
#else
    return 12;
#endif
}

__attribute__((export_name("get_swf_version")))
int get_swf_version(void) { return SWF_VERSION; }

__attribute__((export_name("get_frame_width")))
int get_frame_width(void) {
#ifdef FRAME_WIDTH
    return FRAME_WIDTH;
#else
    return 550;
#endif
}

__attribute__((export_name("get_frame_height")))
int get_frame_height(void) {
#ifdef FRAME_HEIGHT
    return FRAME_HEIGHT;
#else
    return 400;
#endif
}

// Export data array addresses and sizes for JS to pass to the host
__attribute__((export_name("get_shape_data")))
void* get_shape_data(void) { return (void*)shape_data; }
__attribute__((export_name("get_shape_data_size")))
int get_shape_data_size(void) { return sizeof(shape_data); }

__attribute__((export_name("get_transform_data")))
void* get_transform_data(void) { return (void*)transform_data; }
__attribute__((export_name("get_transform_data_size")))
int get_transform_data_size(void) { return sizeof(transform_data); }

__attribute__((export_name("get_color_data")))
void* get_color_data(void) { return (void*)color_data; }
__attribute__((export_name("get_color_data_size")))
int get_color_data_size(void) { return sizeof(color_data); }

__attribute__((export_name("get_stage_to_ndc")))
void* get_stage_to_ndc(void) { return (void*)stage_to_ndc; }

__attribute__((export_name("get_bitmap_count")))
int get_bitmap_count(void) { return BITMAP_COUNT; }
__attribute__((export_name("get_bitmap_highest_w")))
int get_bitmap_highest_w(void) { return BITMAP_HIGHEST_W; }
__attribute__((export_name("get_bitmap_highest_h")))
int get_bitmap_highest_h(void) { return BITMAP_HIGHEST_H; }

// These may be empty arrays but need valid pointers
__attribute__((export_name("get_uninv_mat_data")))
void* get_uninv_mat_data(void) { return (void*)uninv_mat_data; }
__attribute__((export_name("get_uninv_mat_data_size")))
int get_uninv_mat_data_size(void) { return sizeof(uninv_mat_data); }

__attribute__((export_name("get_gradient_data")))
void* get_gradient_data(void) { return (void*)gradient_data; }
__attribute__((export_name("get_gradient_data_size")))
int get_gradient_data_size(void) { return sizeof(gradient_data); }

__attribute__((export_name("get_bitmap_data")))
void* get_bitmap_data(void) { return (void*)bitmap_data; }
__attribute__((export_name("get_bitmap_data_size")))
int get_bitmap_data_size(void) { return sizeof(bitmap_data); }

__attribute__((export_name("get_glyph_data")))
void* get_glyph_data(void) { return (void*)glyph_data; }
__attribute__((export_name("get_glyph_data_size")))
int get_glyph_data_size(void) { return sizeof(glyph_data); }

__attribute__((export_name("get_text_data")))
void* get_text_data(void) { return (void*)text_data; }
__attribute__((export_name("get_text_data_size")))
int get_text_data_size(void) { return sizeof(text_data); }

__attribute__((export_name("get_cxform_data")))
void* get_cxform_data(void) { return (void*)cxform_data; }
__attribute__((export_name("get_cxform_data_size")))
int get_cxform_data_size(void) { return sizeof(cxform_data); }

__attribute__((export_name("get_morph_end_shape_data")))
void* get_morph_end_shape_data(void) { return (void*)morph_end_shape_data; }
__attribute__((export_name("get_morph_end_shape_data_size")))
int get_morph_end_shape_data_size(void) { return sizeof(morph_end_shape_data); }

__attribute__((export_name("get_morph_end_color_data")))
void* get_morph_end_color_data(void) { return (void*)morph_end_color_data; }
__attribute__((export_name("get_morph_end_color_data_size")))
int get_morph_end_color_data_size(void) { return sizeof(morph_end_color_data); }

#ifdef MAX_STRING_ID
__attribute__((export_name("get_max_string_id")))
int get_max_string_id(void) { return MAX_STRING_ID; }
#else
__attribute__((export_name("get_max_string_id")))
int get_max_string_id(void) { return 0; }
#endif
