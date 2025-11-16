#pragma once

#include <stackvalue.h>

// Forward declaration for o1heap
typedef struct O1HeapInstance O1HeapInstance;

#ifndef NO_GRAPHICS
#define INITIAL_DICTIONARY_CAPACITY 1024
#define INITIAL_DISPLAYLIST_CAPACITY 1024

typedef struct Character
{
	size_t shape_offset;
	size_t size;
} Character;

typedef struct DisplayObject
{
	size_t char_id;
	u32 transform_id;
} DisplayObject;
#endif

typedef void (*frame_func)();

extern frame_func frame_funcs[];

typedef struct SWFAppContext
{
	frame_func* frame_funcs;
	size_t frame_count;

#ifndef NO_GRAPHICS
	int width;
	int height;

	const float* stage_to_ndc;

	size_t bitmap_count;
	size_t bitmap_highest_w;
	size_t bitmap_highest_h;

	char* shape_data;
	size_t shape_data_size;
	char* transform_data;
	size_t transform_data_size;
	char* color_data;
	size_t color_data_size;
	char* uninv_mat_data;
	size_t uninv_mat_data_size;
	char* gradient_data;
	size_t gradient_data_size;
	char* bitmap_data;
	size_t bitmap_data_size;
#endif

	// Heap management fields
	O1HeapInstance* heap_instance;
	char* heap;
	int heap_inited;
	size_t heap_current_size;
	size_t heap_full_size;
} SWFAppContext;

extern char* stack;
extern u32 sp;
extern u32 oldSP;

extern int quit_swf;
extern int is_playing;
extern size_t current_frame;
extern size_t next_frame;
extern int manual_next_frame;

// Global frame access for ActionCall opcode
extern frame_func* g_frame_funcs;
extern size_t g_frame_count;

// Drag state tracking (works in both graphics and NO_GRAPHICS modes)
extern int is_dragging;         // 1 if a sprite is being dragged, 0 otherwise
extern char* dragged_target;    // Name of the target being dragged (or NULL)

#ifndef NO_GRAPHICS
extern Character* dictionary;

extern DisplayObject* display_list;
extern size_t max_depth;
#endif

void swfStart(SWFAppContext* app_context);