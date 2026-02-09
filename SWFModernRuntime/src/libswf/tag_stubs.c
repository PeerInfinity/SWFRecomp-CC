#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>

// Stub implementations for console-only mode
// Note: tagInit() is provided by the generated tagMain.c file

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	(void)red; (void)green; (void)blue;
}

void tagShowFrame(SWFAppContext* app_context)
{
	(void)app_context;
}

// No-op stubs for all tag functions so trace tests that happen to
// define shapes, sprites, buttons, sounds, etc. still compile and link.

void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size)
{
	(void)app_context; (void)type; (void)char_id; (void)shape_offset; (void)shape_size;
}

void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
	size_t shape_offset, size_t shape_size,
	size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count)
{
	(void)app_context; (void)char_id; (void)shape_offset; (void)shape_size;
	(void)morph_end_offset; (void)morph_color_start; (void)morph_color_count;
}

void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id)
{
	(void)app_context; (void)char_id; (void)text_start; (void)text_size;
	(void)transform_start; (void)cxform_id;
}

void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth)
{
	(void)app_context; (void)depth; (void)char_id; (void)transform_id;
	(void)cxform_id; (void)clip_depth;
}

void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio)
{
	(void)app_context; (void)depth; (void)char_id; (void)transform_id;
	(void)cxform_id; (void)clip_depth; (void)ratio;
}

void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
	(void)app_context; (void)depth; (void)char_id; (void)transform_id;
	(void)cxform_id; (void)clip_depth; (void)clip_actions; (void)clip_action_count;
}

void tagPlaceObject3(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, u8 blend_mode)
{
	(void)app_context; (void)depth; (void)char_id; (void)transform_id;
	(void)cxform_id; (void)clip_depth; (void)blend_mode;
}

void tagSetFilter(SWFAppContext* app_context, size_t depth,
	u8 type, float blur_x, float blur_y, u8 quality, u8 flags,
	float r, float g, float b, float a, float strength,
	float angle, float distance)
{
	(void)app_context; (void)depth; (void)type; (void)blur_x; (void)blur_y;
	(void)quality; (void)flags; (void)r; (void)g; (void)b; (void)a;
	(void)strength; (void)angle; (void)distance;
}

void tagSetInstanceName(SWFAppContext* app_context, size_t depth, const char* name)
{
	(void)app_context; (void)depth; (void)name;
}

void tagRemoveObject(SWFAppContext* app_context, size_t depth)
{
	(void)app_context; (void)depth;
}

void tagRemoveObject2(SWFAppContext* app_context, size_t depth)
{
	(void)app_context; (void)depth;
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	(void)app_context; (void)char_id; (void)funcs; (void)frame_count;
}

void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count)
{
	(void)app_context; (void)char_id; (void)state_funcs; (void)hit_char_id;
	(void)hit_transform_id; (void)actions; (void)action_count;
}

void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	(void)offset; (void)size; (void)width; (void)height;
}

void finalizeBitmaps()
{
}

void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	(void)app_context; (void)sound_id; (void)format; (void)rate;
	(void)sample_size; (void)stereo; (void)sample_count; (void)data; (void)data_size;
}

void tagStartSound(SWFAppContext* app_context, u16 sound_id,
	int stop, u32 loop_count, u32 in_point, u32 out_point)
{
	(void)app_context; (void)sound_id; (void)stop; (void)loop_count;
	(void)in_point; (void)out_point;
}

void tagSoundStreamHead(SWFAppContext* app_context,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u16 avg_sample_count)
{
	(void)app_context; (void)format; (void)rate; (void)sample_size;
	(void)stereo; (void)avg_sample_count;
}

void tagSoundStreamBlock(SWFAppContext* app_context,
	const u8* data, size_t data_size)
{
	(void)app_context; (void)data; (void)data_size;
}

void tagStopAllSounds(SWFAppContext* app_context)
{
	(void)app_context;
}

#endif // NO_GRAPHICS
