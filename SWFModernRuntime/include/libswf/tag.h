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
void tagDefineEditTextProps(SWFAppContext* app_context, size_t char_id,
    const char* plain_text, const char* raw_html_text, u32 text_color,
    u16 font_id, u16 font_height, s16 max_length,
    u8 align, u16 left_margin, u16 right_margin, u16 indent, s16 leading,
    const char* variable_name, u16 flags,
    s32 bounds_xmin, s32 bounds_xmax, s32 bounds_ymin, s32 bounds_ymax);
void tagCSMTextSettings(size_t text_id, const char* anti_alias_type, const char* grid_fit_type, float thickness, float sharpness);
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
void tagDefineFontInfo(SWFAppContext* app_context, u16 font_id, const char* name, int bold, int italic);

// NO_GRAPHICS helpers for sprite timeline control from action.c
#ifdef NO_GRAPHICS
void ng_advanceSprites(SWFAppContext* app_context);
int ng_isInsideSprite(void);
int ng_hasPlayingSprites(void);
void ng_stopCurrentSprite(void);
void ng_playCurrentSprite(void);
void ng_gotoFrameCurrentSprite(u16 frame);
size_t ng_getSpriteFrameCount(void);
size_t ng_findDisplayEntryByName(const char* name);
// Find a display entry at the given SWF depth that is a direct child of root.
// Returns: 0=not found, 1=non-sprite (shape/text), 2=sprite (name written to out_name)
int ng_findRootChildAtSWFDepth(size_t swf_depth, char* out_name, size_t out_name_size);
size_t ng_findChildEntryDepth(const char* parent_name, const char* child_name);
void ng_updateDisplayDepth(const char* name, int new_as_depth);
void ng_swapDisplayDepths(const char* name1, const char* name2);
void ng_renameDisplayEntry(const char* old_name, const char* new_name);
void ng_display_clear_after(size_t target_frame);
int ng_isSpriteAtDepth(size_t depth);
int ng_isButtonAtDepth(size_t depth);
int ng_isTextFieldAtDepth(size_t depth);
const char* ng_getTextFieldInitialText(size_t depth);
u32 ng_getTextFieldColor(size_t depth);
u32 ng_getTextFieldColorByIdx(int idx);
int ng_getTextFieldIdx(size_t depth);
u16 ng_getTextFieldFlags(int tf_idx);
u16 ng_getTextFieldFontId(int tf_idx);
u16 ng_getTextFieldFontHeight(int tf_idx);
s16 ng_getTextFieldMaxLength(int tf_idx);
u8 ng_getTextFieldAlign(int tf_idx);
u16 ng_getTextFieldLeftMargin(int tf_idx);
u16 ng_getTextFieldRightMargin(int tf_idx);
u16 ng_getTextFieldIndent(int tf_idx);
s16 ng_getTextFieldLeading(int tf_idx);
const char* ng_getTextFieldVariableName(int tf_idx);
void ng_getTextFieldBounds(int tf_idx, s32* xmin, s32* xmax, s32* ymin, s32* ymax);
const char* ng_getTextFieldRawHtml(int tf_idx);
const char* ng_getTextFieldInitialTextByIdx(int tf_idx);
const char* ng_getFontName(u16 font_id);
int ng_getFontBold(u16 font_id);
int ng_getFontItalic(u16 font_id);
int ng_getTransformId(size_t depth, u32* out_id);
int ng_getTransformXY(size_t depth, float* out_x, float* out_y);
// TextField variable binding — called from tag_stubs.c at placement time
void actionInitTextFieldVariable(SWFAppContext* app_context, const char* var_name, const char* init_text);
// Enumerate child instance names for a MovieClip (for for-in enumeration)
// callback receives (name, name_len, user_data) for each child
void ng_enumerateChildren(const char* parent_name, void (*callback)(const char* name, u32 name_len, void* user_data), void* user_data);
#endif
