#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>
#include <action.h>

// Simple sprite registry for NO_GRAPHICS mode
// Allows sprite frame scripts (e.g. DoAction inside DefineSprite) to execute
#define MAX_SPRITES_NG 64
static struct {
	size_t char_id;
	frame_func* funcs;
	size_t frame_count;
} ng_sprites[MAX_SPRITES_NG];
static size_t ng_sprite_count = 0;

// Simple display list for NO_GRAPHICS mode
#define MAX_DISPLAY_NG 64
static struct {
	size_t depth;
	size_t sprite_idx;     // index into ng_sprites, or (size_t)-1 for non-sprite
	size_t current_frame;
	int is_playing;
} ng_display[MAX_DISPLAY_NG];
static size_t ng_display_count = 0;

static size_t ng_find_sprite(size_t char_id)
{
	for (size_t i = 0; i < ng_sprite_count; i++)
		if (ng_sprites[i].char_id == char_id)
			return i;
	return (size_t)-1;
}

// Clear the NO_GRAPHICS display list (called on goto-rewind)
void ng_display_clear(void)
{
	ng_display_count = 0;
}

// Stub implementations for console-only mode
// Note: tagInit() is provided by the generated tagMain.c file

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	(void)red; (void)green; (void)blue;
}

void tagShowFrame(SWFAppContext* app_context)
{
	// Advance sprite timelines for NO_GRAPHICS mode
	for (size_t i = 0; i < ng_display_count; i++)
	{
		size_t si = ng_display[i].sprite_idx;
		if (si == (size_t)-1) continue;
		if (!ng_display[i].is_playing) continue;

		size_t fc = ng_sprites[si].frame_count;
		if (fc <= 1) continue;  // Single-frame sprites don't advance

		size_t next = (ng_display[i].current_frame + 1) % fc;
		ng_display[i].current_frame = next;

		// Execute the next frame function
		if (ng_sprites[si].funcs && ng_sprites[si].funcs[next])
			ng_sprites[si].funcs[next](app_context);
	}
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
	(void)transform_id; (void)cxform_id; (void)clip_depth;
	// Check if this is placing a new sprite (char_id > 0 means new placement)
	if (char_id > 0)
	{
		size_t si = ng_find_sprite(char_id);
		if (si != (size_t)-1 && ng_display_count < MAX_DISPLAY_NG)
		{
			// Check if depth already has the same sprite (skip re-execution)
			for (size_t i = 0; i < ng_display_count; i++)
			{
				if (ng_display[i].depth == depth)
				{
					if (ng_display[i].sprite_idx == si)
					{
						// Same sprite already at this depth - don't re-execute
						return;
					}
					// Different sprite - replace and execute frame 0
					ng_display[i].sprite_idx = si;
					ng_display[i].current_frame = 0;
					ng_display[i].is_playing = 1;
					if (ng_sprites[si].funcs && ng_sprites[si].funcs[0])
						ng_sprites[si].funcs[0](app_context);
					return;
				}
			}
			// New entry
			ng_display[ng_display_count].depth = depth;
			ng_display[ng_display_count].sprite_idx = si;
			ng_display[ng_display_count].current_frame = 0;
			ng_display[ng_display_count].is_playing = 1;
			ng_display_count++;
			// Execute frame 0
			if (ng_sprites[si].funcs && ng_sprites[si].funcs[0])
				ng_sprites[si].funcs[0](app_context);
		}
	}
}

void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
	u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio)
{
	(void)ratio;
	// Delegate to tagPlaceObject2 for sprite execution
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
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

void tagSetFilterHighlight(SWFAppContext* app_context, size_t depth,
	float r, float g, float b, float a)
{
	(void)app_context; (void)depth; (void)r; (void)g; (void)b; (void)a;
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
	(void)app_context;
	for (size_t i = 0; i < ng_display_count; i++)
	{
		if (ng_display[i].depth == depth)
		{
			// Remove by shifting
			for (size_t j = i; j + 1 < ng_display_count; j++)
				ng_display[j] = ng_display[j + 1];
			ng_display_count--;
			return;
		}
	}
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	(void)app_context;
	if (ng_sprite_count < MAX_SPRITES_NG)
	{
		ng_sprites[ng_sprite_count].char_id = char_id;
		ng_sprites[ng_sprite_count].funcs = funcs;
		ng_sprites[ng_sprite_count].frame_count = frame_count;
		ng_sprite_count++;
	}
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

void tagScriptLimits(u16 max_recursion, u16 timeout)
{
	(void)timeout;
	g_max_call_depth = max_recursion;
}

#endif // NO_GRAPHICS
