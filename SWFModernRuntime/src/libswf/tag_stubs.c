#ifdef NO_GRAPHICS

#include <tag.h>
#include <swf.h>
#include <common.h>

// Stub implementations for console-only mode
// Note: tagInit() is provided by the generated tagMain.c file

void tagSetBackgroundColor(u8 red, u8 green, u8 blue)
{
	printf("[Tag] SetBackgroundColor(%d, %d, %d)\n", red, green, blue);
}

void tagShowFrame(SWFAppContext* app_context)
{
	(void)app_context;  // Unused in NO_GRAPHICS mode
	printf("[Tag] ShowFrame()\n");
}

// Stubs for graphics-only tags - should not be called in NO_GRAPHICS mode
// but if they are, we provide empty implementations
#ifdef INCLUDE_GRAPHICS_STUBS
void tagDefineSprite(SWFAppContext* app_context, size_t char_id, frame_func* funcs, size_t frame_count)
{
	(void)app_context; (void)funcs; (void)frame_count;
	printf("[Tag] DefineSprite(char_id=%zu, frame_count=%zu) [ignored in NO_GRAPHICS mode]\n", char_id, frame_count);
}

void tagDefineShape(size_t char_id, size_t shape_offset, size_t shape_size)
{
	printf("[Tag] DefineShape(char_id=%zu) [ignored in NO_GRAPHICS mode]\n", char_id);
}

void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id, u32 cxform_id, u16 clip_depth)
{
	(void)app_context; (void)transform_id; (void)cxform_id; (void)clip_depth;
	printf("[Tag] PlaceObject2(depth=%zu, char_id=%zu) [ignored in NO_GRAPHICS mode]\n", depth, char_id);
}

void defineBitmap(size_t offset, size_t size, u32 width, u32 height)
{
	printf("[Tag] DefineBitmap(width=%u, height=%u) [ignored in NO_GRAPHICS mode]\n", width, height);
}

void finalizeBitmaps()
{
	printf("[Tag] FinalizeBitmaps() [ignored in NO_GRAPHICS mode]\n");
}
#endif

#endif // NO_GRAPHICS
