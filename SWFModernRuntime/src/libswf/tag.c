#ifndef NO_GRAPHICS

#include <swf.h>
#include <tag.h>
#include <renderer.h>
#include <utils.h>

extern RenderContext* context;

size_t dictionary_capacity = INITIAL_DICTIONARY_CAPACITY;
size_t display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;

// Note: tagInit() is provided by the generated tagMain.c file

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	renderer_set_background(context, red, green, blue);
}

void tagShowFrame(SWFAppContext* app_context)
{
	renderer_open_pass(context);

	u16 active_clip_depth = 0;

	for (size_t i = 1; i <= max_depth; ++i)
	{
		// End active clip if we've passed its range
		if (active_clip_depth > 0 && i > active_clip_depth)
		{
			renderer_end_clip(context);
			active_clip_depth = 0;
		}

		DisplayObject* obj = &display_list[i];

		if (obj->char_id == 0)
		{
			continue;
		}

		// Check if this object is a clip mask
		if (obj->clip_depth > 0)
		{
			Character* ch = &dictionary[obj->char_id];
			if (ch->type == CHAR_TYPE_SHAPE)
			{
				renderer_begin_clip_mask(context);
				renderer_draw_shape(context, ch->shape_offset, ch->size, obj->transform_id, obj->cxform_id);
				renderer_end_clip_mask(context);
				active_clip_depth = obj->clip_depth;
			}
			continue;
		}

		Character* ch = &dictionary[obj->char_id];

		switch (ch->type)
		{
			case CHAR_TYPE_SHAPE:
				renderer_draw_shape(context, ch->shape_offset, ch->size, obj->transform_id, obj->cxform_id);
				break;
			case CHAR_TYPE_TEXT:
				renderer_upload_extra_transform_id(context, obj->transform_id);
				for (size_t j = 0; j < ch->text_size; ++j)
				{
					size_t glyph_index = 2*app_context->text_data[ch->text_start + j];
					renderer_draw_shape(context, app_context->glyph_data[glyph_index], app_context->glyph_data[glyph_index + 1], ch->transform_start + j, ch->cxform_id);
				}
				break;
			case CHAR_TYPE_SPRITE:
			{
				// Save current display list state
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				// Create temporary sprite display list
				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				// Execute sprite's first frame to build its display list
				if (ch->sprite_frame_count > 0 && ch->sprite_frame_funcs[0] != NULL)
				{
					ch->sprite_frame_funcs[0](app_context);
				}

				// Render sprite's display list contents
				for (size_t j = 1; j <= max_depth; ++j)
				{
					DisplayObject* sprite_obj = &display_list[j];
					if (sprite_obj->char_id == 0) continue;

					Character* sprite_ch = &dictionary[sprite_obj->char_id];
					if (sprite_ch->type == CHAR_TYPE_SHAPE)
					{
						renderer_draw_shape(context, sprite_ch->shape_offset, sprite_ch->size,
							sprite_obj->transform_id, sprite_obj->cxform_id);
					}
				}

				// Restore main display list
				free(display_list);
				display_list = saved_display_list;
				max_depth = saved_max_depth;
				display_list_capacity = saved_capacity;
				break;
			}
		}
	}

	if (active_clip_depth > 0)
	{
		renderer_end_clip(context);
	}

	renderer_close_pass(context);
}

void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = type;
	dictionary[char_id].shape_offset = shape_offset;
	dictionary[char_id].size = shape_size;
}

void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_TEXT;
	dictionary[char_id].text_start = text_start;
	dictionary[char_id].text_size = text_size;
	dictionary[char_id].transform_start = transform_start;
	dictionary[char_id].cxform_id = cxform_id;
}

void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth)
{
	ENSURE_SIZE(display_list, depth, display_list_capacity, sizeof(DisplayObject));

	display_list[depth].char_id = char_id;
	display_list[depth].transform_id = transform_id;
	display_list[depth].cxform_id = cxform_id;
	display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
	display_list[depth].clip_depth = clip_depth;

	if (depth > max_depth)
	{
		max_depth = depth;
	}
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_SPRITE;
	dictionary[char_id].sprite_frame_funcs = funcs;
	dictionary[char_id].sprite_frame_count = frame_count;
}

void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	renderer_upload_bitmap(context, offset, size, width, height);
}

void finalizeBitmaps()
{
	renderer_finalize_bitmaps(context);
}

#endif // NO_GRAPHICS
