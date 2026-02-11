#pragma once

#include <common.h>
#include <swf.h>

// Core tag functions - always available
void tagInit(SWFAppContext* app_context);
void tagSetBackgroundColor(u8 red, u8 green, u8 blue);
void tagShowFrame(SWFAppContext* app_context);

// Tag functions needed by both graphics and trace (NO_GRAPHICS) builds.
// In NO_GRAPHICS mode, tag_stubs.c provides no-op implementations.
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size);
void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
    size_t shape_offset, size_t shape_size,
    size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count);
void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id);
void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth);
void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio);
void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count);
void tagPlaceObject3(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u8 blend_mode);
void tagSetFilter(SWFAppContext* app_context, size_t depth,
    u8 type, float blur_x, float blur_y, u8 quality, u8 flags,
    float r, float g, float b, float a, float strength,
    float angle, float distance);
void tagSetFilterHighlight(SWFAppContext* app_context, size_t depth,
    float r, float g, float b, float a);
void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name);
void tagRemoveObject(SWFAppContext* app_context, size_t depth);
void tagRemoveObject2(SWFAppContext* app_context, size_t depth);
void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count);
void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count);
void defineBitmap(size_t offset, size_t size, u32 width, u32 height);
void finalizeBitmaps();
void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
    u8 format, u8 rate, u8 sample_size, u8 stereo,
    u32 sample_count, const u8* data, size_t data_size);
void tagStartSound(SWFAppContext* app_context, u16 sound_id,
    int stop, u32 loop_count, u32 in_point, u32 out_point);
void tagSoundStreamHead(SWFAppContext* app_context,
    u8 format, u8 rate, u8 sample_size, u8 stereo,
    u16 avg_sample_count);
void tagSoundStreamBlock(SWFAppContext* app_context,
    const u8* data, size_t data_size);
void tagStopAllSounds(SWFAppContext* app_context);
void tagScriptLimits(u16 max_recursion, u16 timeout);
