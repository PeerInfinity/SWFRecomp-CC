#ifndef NO_GRAPHICS

#include <swf.h>
#include <tag.h>
#include <hit_test.h>
#include <renderer.h>
#include <utils.h>

extern RenderContext* context;

size_t dictionary_capacity = INITIAL_DICTIONARY_CAPACITY;
size_t display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;

// Note: tagInit() is provided by the generated tagMain.c file

// ---------------------------------------------------------------------------
// Helper 1: Advance sprite timelines recursively
// ---------------------------------------------------------------------------
// Iterates the current global display_list for sprites and advances their
// timelines.  After executing each sprite's frame function (while globals are
// swapped to the sprite's list), recurse to advance any nested sprites.
static void advance_sprite_frames(SWFAppContext* app_context)
{
	for (size_t i = 1; i <= max_depth; ++i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;
		Character* ch = &dictionary[obj->char_id];
		if (ch->type != CHAR_TYPE_SPRITE) continue;

		// Allocate persistent display list on first encounter
		if (obj->sprite_display_list == NULL)
		{
			obj->sprite_dl_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			obj->sprite_display_list = calloc(obj->sprite_dl_capacity, sizeof(DisplayObject));
			obj->sprite_max_depth = 0;
			obj->sprite_current_frame = 0;
		}

		// Swap to sprite's display list context
		DisplayObject* saved_dl = display_list;
		size_t saved_max = max_depth;
		size_t saved_cap = display_list_capacity;

		display_list = obj->sprite_display_list;
		max_depth = obj->sprite_max_depth;
		display_list_capacity = obj->sprite_dl_capacity;

		// When looping back to frame 0, reset the display list (Flash behavior)
		size_t frame = obj->sprite_current_frame;
		if (frame == 0 && max_depth > 0)
		{
			for (size_t j = 1; j <= max_depth; ++j)
			{
				if (display_list[j].sprite_display_list != NULL)
				{
					free(display_list[j].sprite_display_list);
					display_list[j].sprite_display_list = NULL;
				}
				display_list[j].char_id = 0;
			}
			max_depth = 0;
		}

		// Execute current frame function
		if (frame < ch->sprite_frame_count && ch->sprite_frame_funcs[frame] != NULL)
		{
			ch->sprite_frame_funcs[frame](app_context);
		}

		// Recurse: advance nested sprites within this sprite's display list
		advance_sprite_frames(app_context);

		// Save back (display_list pointer may have changed if realloc'd)
		obj->sprite_display_list = display_list;
		obj->sprite_max_depth = max_depth;
		obj->sprite_dl_capacity = display_list_capacity;

		// Restore parent display list
		display_list = saved_dl;
		max_depth = saved_max;
		display_list_capacity = saved_cap;

		// Advance frame (loop back to 0)
		obj->sprite_current_frame = (frame + 1) % ch->sprite_frame_count;
	}
}

// ---------------------------------------------------------------------------
// Helper 2: Recursive transform composition for sprite/button children
// ---------------------------------------------------------------------------
// Composes each child's local transform with the parent's already-composed
// global transform, writes the result to GPU, and recurses for nested
// structures (text glyphs, nested sprites, buttons).
//
// Unlike the old compose_child_transforms, this function receives the parent's
// COMPOSED transform (not a transform_id), so it works correctly at any
// nesting depth.  The CPU-side transform_data is never modified — all composed
// results go directly to the GPU xform buffer via renderer_write_transform.
static void compose_children(SWFAppContext* app_context, DisplayObject* dl,
	size_t dl_max_depth, const float parent_composed[16])
{
	const float* transforms = (const float*)app_context->transform_data;

	for (size_t i = 1; i <= dl_max_depth; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];

		// Compose this child's local transform with the parent's global transform
		const float* local_xform = &transforms[obj->transform_id * 16];
		float composed[16];
		hit_test_mat4_multiply(composed, parent_composed, local_xform);
		renderer_write_transform(context, obj->transform_id, composed);

		switch (ch->type)
		{
			case CHAR_TYPE_TEXT:
				// Compose each glyph transform with the composed text transform
				for (size_t j = 0; j < ch->text_size; j++)
				{
					u32 glyph_xform_id = ch->transform_start + (u32)j;
					const float* glyph_local = &transforms[glyph_xform_id * 16];
					float glyph_composed[16];
					hit_test_mat4_multiply(glyph_composed, composed, glyph_local);
					renderer_write_transform(context, glyph_xform_id, glyph_composed);
				}
				break;

			case CHAR_TYPE_MORPH_SHAPE:
			{
				float t = (float)obj->ratio / 65535.0f;
				size_t num_verts = ch->morph_start_size;

				u32* start = (u32*)(app_context->shape_data + ch->morph_start_offset * 4 * sizeof(u32));
				float* end = (float*)(app_context->morph_end_shape_data + ch->morph_end_offset * 2 * sizeof(float));
				u32* scratch = (u32*)malloc(num_verts * 4 * sizeof(u32));

				for (size_t v = 0; v < num_verts; v++)
				{
					float sx = *(float*)&start[v*4 + 0];
					float sy = *(float*)&start[v*4 + 1];
					float ex = end[v*2 + 0];
					float ey = end[v*2 + 1];
					float ix = sx + t * (ex - sx);
					float iy = sy + t * (ey - sy);
					scratch[v*4 + 0] = *(u32*)&ix;
					scratch[v*4 + 1] = *(u32*)&iy;
					scratch[v*4 + 2] = start[v*4 + 2];
					scratch[v*4 + 3] = start[v*4 + 3];
				}

				renderer_update_vertices(context,
					ch->morph_start_offset * 4 * sizeof(u32),
					scratch, num_verts * 4 * sizeof(u32));
				free(scratch);

				for (size_t c = 0; c < ch->morph_color_count; c++)
				{
					float* sc = (float*)(app_context->color_data) + (ch->morph_color_start + c) * 4;
					float* ec = (float*)(app_context->morph_end_color_data) + c * 4;
					float interp[4];
					for (int k = 0; k < 4; k++)
						interp[k] = sc[k] + t * (ec[k] - sc[k]);
					renderer_update_colors(context,
						(ch->morph_color_start + c) * 4 * sizeof(float),
						interp, 4 * sizeof(float));
				}
				break;
			}

			case CHAR_TYPE_SPRITE:
			{
				if (obj->sprite_display_list != NULL)
					compose_children(app_context,
						obj->sprite_display_list, obj->sprite_max_depth,
						composed);
				break;
			}

			case CHAR_TYPE_BUTTON:
			{
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				u8 state = obj->button_state;
				if (ch->button_state_funcs[state] != NULL)
					ch->button_state_funcs[state](app_context);

				compose_children(app_context, display_list, max_depth, composed);

				free(display_list);
				display_list = saved_display_list;
				max_depth = saved_max_depth;
				display_list_capacity = saved_capacity;
				break;
			}

			default:
				break;
		}
	}
}

// ---------------------------------------------------------------------------
// Helper 3: Recursive display list rendering
// ---------------------------------------------------------------------------
// Renders all objects in a display list, recursing into sprites and buttons.
static void render_display_list(SWFAppContext* app_context, DisplayObject* dl, size_t dl_max_depth)
{
	for (size_t i = 1; i <= dl_max_depth; ++i)
	{
		DisplayObject* obj = &dl[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];
		switch (ch->type)
		{
			case CHAR_TYPE_SHAPE:
				renderer_draw_shape(context, ch->shape_offset, ch->size,
					obj->transform_id, obj->cxform_id);
				break;

			case CHAR_TYPE_MORPH_SHAPE:
				renderer_draw_shape(context, ch->morph_start_offset, ch->morph_start_size,
					obj->transform_id, obj->cxform_id);
				break;

			case CHAR_TYPE_TEXT:
				for (size_t j = 0; j < ch->text_size; ++j)
				{
					size_t glyph_index = 2*app_context->text_data[ch->text_start + j];
					renderer_draw_shape(context,
						app_context->glyph_data[glyph_index],
						app_context->glyph_data[glyph_index + 1],
						ch->transform_start + j, ch->cxform_id);
				}
				break;

			case CHAR_TYPE_SPRITE:
				if (obj->sprite_display_list != NULL)
					render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
				break;

			case CHAR_TYPE_BUTTON:
			{
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				u8 state = obj->button_state;
				if (ch->button_state_funcs[state] != NULL)
					ch->button_state_funcs[state](app_context);

				render_display_list(app_context, display_list, max_depth);

				free(display_list);
				display_list = saved_display_list;
				max_depth = saved_max_depth;
				display_list_capacity = saved_capacity;
				break;
			}
		}
	}
}

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	renderer_set_background(context, red, green, blue);
}

void tagShowFrame(SWFAppContext* app_context)
{
	// --- Advance sprite timelines (recursive) ---
	advance_sprite_frames(app_context);

	// --- Dispatch onEnterFrame clip actions ---
	for (size_t i = 1; i <= max_depth; ++i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0 || obj->clip_action_count == 0) continue;

		for (size_t a = 0; a < obj->clip_action_count; a++)
		{
			if (obj->clip_actions[a].event_flags & CLIP_EVENT_ENTER_FRAME)
			{
				obj->clip_actions[a].action(app_context);
			}
		}
	}

	// --- Button hit testing + state machine + action dispatch ---
	// Must run BEFORE transform composition so the pre-render pass
	// composes transforms for the correct (updated) button state.
	// Iterate front-to-back (highest depth first). The first button that hits
	// gets the over/down state; all others stay in up state.
	//
	// BUTTONCONDACTION condition bits:
	//   Bit 0: IdleToOverDown       Bit 4: OverDownToOverUp (click/release)
	//   Bit 1: OutDownToIdle        Bit 5: OverUpToOverDown (press)
	//   Bit 2: OutDownToOverDown    Bit 6: OverUpToIdle (mouse leave)
	//   Bit 3: OverDownToOutDown    Bit 7: IdleToOverUp (mouse enter)
	//   Bit 8: OverDownToIdle
	{
		int found_hover = 0;
		for (size_t i = max_depth; i >= 1; i--)
		{
			DisplayObject* obj = &display_list[i];
			if (obj->char_id == 0) continue;

			Character* ch = &dictionary[obj->char_id];
			if (ch->type != CHAR_TYPE_BUTTON) continue;

			u8 old_state = obj->button_state;

			if (!found_hover)
			{
				// Look up the hit-test shape
				Character* hit_ch = &dictionary[ch->button_hit_char_id];
				if (hit_ch->type == CHAR_TYPE_SHAPE)
				{
					// Compose PlaceObject2 transform with hit-record transform
					const float* place_xf = (const float*)(app_context->transform_data) + obj->transform_id * 16;
					const float* hit_xf = (const float*)(app_context->transform_data) + ch->button_hit_transform_id * 16;
					float composed[16];
					hit_test_mat4_multiply(composed, place_xf, hit_xf);

					int hit = hit_test_shape(app_context->shape_data,
						hit_ch->shape_offset, hit_ch->size,
						composed,
						app_context->mouse.stage_x,
						app_context->mouse.stage_y);

					if (hit)
					{
						found_hover = 1;
						if (app_context->mouse.button_down)
							obj->button_state = 2;  // down (OverDown)
						else
							obj->button_state = 1;  // over (OverUp)
					}
					else
					{
						obj->button_state = 0;  // up (Idle)
					}
				}
			}
			else
			{
				obj->button_state = 0;  // up (another button is hovered)
			}

			// Dispatch actions on state transitions
			u8 new_state = obj->button_state;
			if (old_state != new_state && ch->button_action_count > 0)
			{
				// Encode transition as BUTTONCONDACTION bitmask
				u16 transition = 0;
				if (old_state == 0 && new_state == 1)      transition = 0x0001; // IdleToOverUp
				else if (old_state == 1 && new_state == 0)  transition = 0x0002; // OverUpToIdle
				else if (old_state == 1 && new_state == 2)  transition = 0x0004; // OverUpToOverDown
				else if (old_state == 2 && new_state == 1)  transition = 0x0008; // OverDownToOverUp
				else if (old_state == 2 && new_state == 0)  transition = 0x0100; // OverDownToIdle
				else if (old_state == 0 && new_state == 2)  transition = 0x0080; // IdleToOverDown

				if (transition != 0)
				{
					for (size_t a = 0; a < ch->button_action_count; a++)
					{
						if (ch->button_actions[a].condition & transition)
							ch->button_actions[a].action(app_context);
					}
				}
			}

			obj->button_prev_state = old_state;
		}
	}

	// Compose transforms recursively BEFORE the render pass.
	// For sprites/buttons: compose_children handles all nesting levels,
	// passing the composed parent transform down so nested text/sprite/button
	// children get correctly composed global transforms.
	// For top-level text/morph: compose directly (parent is identity/self).
	for (size_t i = 1; i <= max_depth; ++i)
	{
		DisplayObject* obj = &display_list[i];
		if (obj->char_id == 0) continue;

		Character* ch = &dictionary[obj->char_id];
		if (ch->type == CHAR_TYPE_SPRITE)
		{
			if (obj->sprite_display_list != NULL)
			{
				const float* sprite_xform = (const float*)app_context->transform_data + obj->transform_id * 16;
				compose_children(app_context,
					obj->sprite_display_list, obj->sprite_max_depth,
					sprite_xform);
			}
		}
		else if (ch->type == CHAR_TYPE_BUTTON)
		{
			DisplayObject* saved_display_list = display_list;
			size_t saved_max_depth = max_depth;
			size_t saved_capacity = display_list_capacity;

			display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
			display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
			max_depth = 0;

			u8 state = obj->button_state;
			if (ch->button_state_funcs[state] != NULL)
				ch->button_state_funcs[state](app_context);

			const float* btn_xform = (const float*)app_context->transform_data + obj->transform_id * 16;
			compose_children(app_context, display_list, max_depth, btn_xform);

			free(display_list);
			display_list = saved_display_list;
			max_depth = saved_max_depth;
			display_list_capacity = saved_capacity;
		}
		else if (ch->type == CHAR_TYPE_TEXT)
		{
			renderer_compose_text_transforms(context,
				app_context->transform_data,
				obj->transform_id,
				ch->transform_start,
				ch->text_size);
		}
		else if (ch->type == CHAR_TYPE_MORPH_SHAPE)
		{
			float t = (float)obj->ratio / 65535.0f;
			size_t num_verts = ch->morph_start_size;

			u32* start = (u32*)(app_context->shape_data + ch->morph_start_offset * 4 * sizeof(u32));
			float* end = (float*)(app_context->morph_end_shape_data + ch->morph_end_offset * 2 * sizeof(float));
			u32* scratch = (u32*)malloc(num_verts * 4 * sizeof(u32));

			for (size_t v = 0; v < num_verts; v++)
			{
				float sx = *(float*)&start[v*4 + 0];
				float sy = *(float*)&start[v*4 + 1];
				float ex = end[v*2 + 0];
				float ey = end[v*2 + 1];
				float ix = sx + t * (ex - sx);
				float iy = sy + t * (ey - sy);
				scratch[v*4 + 0] = *(u32*)&ix;
				scratch[v*4 + 1] = *(u32*)&iy;
				scratch[v*4 + 2] = start[v*4 + 2];
				scratch[v*4 + 3] = start[v*4 + 3];
			}

			renderer_update_vertices(context,
				ch->morph_start_offset * 4 * sizeof(u32),
				scratch, num_verts * 4 * sizeof(u32));
			free(scratch);

			for (size_t c = 0; c < ch->morph_color_count; c++)
			{
				float* sc = (float*)(app_context->color_data) + (ch->morph_color_start + c) * 4;
				float* ec = (float*)(app_context->morph_end_color_data) + c * 4;
				float interp[4];
				for (int k = 0; k < 4; k++)
					interp[k] = sc[k] + t * (ec[k] - sc[k]);
				renderer_update_colors(context,
					(ch->morph_color_start + c) * 4 * sizeof(float),
					interp, 4 * sizeof(float));
			}
		}
	}

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
			case CHAR_TYPE_MORPH_SHAPE:
				renderer_draw_shape(context, ch->morph_start_offset, ch->morph_start_size, obj->transform_id, obj->cxform_id);
				break;
			case CHAR_TYPE_TEXT:
				for (size_t j = 0; j < ch->text_size; ++j)
				{
					size_t glyph_index = 2*app_context->text_data[ch->text_start + j];
					renderer_draw_shape(context, app_context->glyph_data[glyph_index], app_context->glyph_data[glyph_index + 1], ch->transform_start + j, ch->cxform_id);
				}
				break;
			case CHAR_TYPE_SPRITE:
				if (obj->sprite_display_list != NULL)
					render_display_list(app_context, obj->sprite_display_list, obj->sprite_max_depth);
				break;
			case CHAR_TYPE_BUTTON:
			{
				DisplayObject* saved_display_list = display_list;
				size_t saved_max_depth = max_depth;
				size_t saved_capacity = display_list_capacity;

				display_list_capacity = INITIAL_DISPLAYLIST_CAPACITY;
				display_list = (DisplayObject*) calloc(display_list_capacity, sizeof(DisplayObject));
				max_depth = 0;

				u8 state = obj->button_state;
				if (ch->button_state_funcs[state] != NULL)
					ch->button_state_funcs[state](app_context);

				render_display_list(app_context, display_list, max_depth);

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

void tagDefineMorphShape(SWFAppContext* app_context, size_t char_id,
    size_t shape_offset, size_t shape_size,
    size_t morph_end_offset, size_t morph_color_start, size_t morph_color_count)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_MORPH_SHAPE;
	dictionary[char_id].morph_start_offset = shape_offset;
	dictionary[char_id].morph_start_size = shape_size;
	dictionary[char_id].morph_end_offset = morph_end_offset;
	dictionary[char_id].morph_color_start = morph_color_start;
	dictionary[char_id].morph_color_count = morph_color_count;
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
	display_list[depth].sprite_display_list = NULL;
	display_list[depth].sprite_max_depth = 0;
	display_list[depth].sprite_dl_capacity = 0;
	display_list[depth].sprite_current_frame = 0;
	display_list[depth].clip_actions = NULL;
	display_list[depth].clip_action_count = 0;

	if (depth > max_depth)
	{
		max_depth = depth;
	}
}

void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
	tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
	display_list[depth].clip_actions = clip_actions;
	display_list[depth].clip_action_count = clip_action_count;

	// Dispatch onLoad immediately
	for (size_t i = 0; i < clip_action_count; i++)
	{
		if (clip_actions[i].event_flags & CLIP_EVENT_LOAD)
		{
			clip_actions[i].action(app_context);
		}
	}
}

void tagPlaceObject2Ratio(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, u16 ratio)
{
	ENSURE_SIZE(display_list, depth, display_list_capacity, sizeof(DisplayObject));

	display_list[depth].char_id = char_id;
	display_list[depth].transform_id = transform_id;
	display_list[depth].cxform_id = cxform_id;
	display_list[depth].has_cxform = (cxform_id != 0) ? 1 : 0;
	display_list[depth].clip_depth = clip_depth;
	display_list[depth].ratio = ratio;
	display_list[depth].sprite_display_list = NULL;
	display_list[depth].sprite_max_depth = 0;
	display_list[depth].sprite_dl_capacity = 0;
	display_list[depth].sprite_current_frame = 0;
	display_list[depth].clip_actions = NULL;
	display_list[depth].clip_action_count = 0;

	if (depth > max_depth)
	{
		max_depth = depth;
	}
}

void tagRemoveObject(SWFAppContext* app_context, size_t depth)
{
	if (depth <= max_depth)
	{
		// Dispatch onUnload clip actions before clearing
		if (display_list[depth].clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].clip_actions[a].action(app_context);
			}
		}
		if (display_list[depth].sprite_display_list != NULL)
		{
			free(display_list[depth].sprite_display_list);
			display_list[depth].sprite_display_list = NULL;
		}
		display_list[depth].char_id = 0;
		display_list[depth].transform_id = 0;
		display_list[depth].cxform_id = 0;
		display_list[depth].has_cxform = 0;
		display_list[depth].clip_depth = 0;
		display_list[depth].clip_actions = NULL;
		display_list[depth].clip_action_count = 0;
	}
}

void tagRemoveObject2(SWFAppContext* app_context, size_t depth)
{
	if (depth <= max_depth)
	{
		// Dispatch onUnload clip actions before clearing
		if (display_list[depth].clip_action_count > 0)
		{
			for (size_t a = 0; a < display_list[depth].clip_action_count; a++)
			{
				if (display_list[depth].clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
					display_list[depth].clip_actions[a].action(app_context);
			}
		}
		if (display_list[depth].sprite_display_list != NULL)
		{
			free(display_list[depth].sprite_display_list);
			display_list[depth].sprite_display_list = NULL;
		}
		display_list[depth].char_id = 0;
		display_list[depth].transform_id = 0;
		display_list[depth].cxform_id = 0;
		display_list[depth].has_cxform = 0;
		display_list[depth].clip_depth = 0;
		display_list[depth].clip_actions = NULL;
		display_list[depth].clip_action_count = 0;
	}
}

void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_SPRITE;
	dictionary[char_id].sprite_frame_funcs = funcs;
	dictionary[char_id].sprite_frame_count = frame_count;
}

void tagDefineButton(SWFAppContext* app_context, size_t char_id, frame_func* state_funcs, size_t hit_char_id, u32 hit_transform_id, ButtonAction* actions, size_t action_count)
{
	ENSURE_SIZE(dictionary, char_id, dictionary_capacity, sizeof(Character));

	dictionary[char_id].type = CHAR_TYPE_BUTTON;
	dictionary[char_id].button_state_funcs = state_funcs;
	dictionary[char_id].button_hit_char_id = hit_char_id;
	dictionary[char_id].button_hit_transform_id = hit_transform_id;
	dictionary[char_id].button_actions = actions;
	dictionary[char_id].button_action_count = action_count;
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
