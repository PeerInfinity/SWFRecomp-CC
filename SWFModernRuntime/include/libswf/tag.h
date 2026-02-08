#pragma once

#include <common.h>
#include <swf.h>

// Core tag functions - always available
void tagInit(SWFAppContext* app_context);
void tagSetBackgroundColor(u8 red, u8 green, u8 blue);
void tagShowFrame(SWFAppContext* app_context);

#ifndef NO_GRAPHICS
// Graphics-only tag functions
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size);
void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
    size_t shape_offset, size_t shape_size,
    size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count);
void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id);
void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth);
void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio);
void tagRemoveObject2(SWFAppContext* app_context, size_t depth);
void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count);
void defineBitmap(size_t offset, size_t size, u32 width, u32 height);
void finalizeBitmaps();
#endif
