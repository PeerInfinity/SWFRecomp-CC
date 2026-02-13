#ifdef NO_GRAPHICS

#include <stdlib.h>
#include <swf.h>
#include <tag.h>
#include <action.h>
#include <variables.h>
#include <utils.h>
#include <heap.h>

// Core runtime state - exported
int quit_swf = 0;
int is_playing = 1;
int bad_poll = 0;
size_t current_frame = 0;
size_t next_frame = 0;
int manual_next_frame = 0;
ActionVar* temp_val = NULL;

// Global frame access for ActionCall opcode
frame_func* g_frame_funcs = NULL;
size_t g_frame_count = 0;

// Drag state tracking
int is_dragging = 0;
char* dragged_target = NULL;

// Goto catch-up state
int catch_up_mode = 0;
int goto_from_action = 0;
int catch_up_backward = 0;    // 1 if current catch-up is a backward goto
size_t catch_up_target = 0;   // target frame for backward goto protection

// Console-only swfStart implementation
void swfStart(SWFAppContext* app_context)
{
	printf("=== SWF Execution Started (NO_GRAPHICS mode) ===\n");

	// Allocate stack into app_context (use system malloc, not heap - stack is allocated before heap_init)
	app_context->stack = (char*) malloc(INITIAL_STACK_SIZE);
	if (!app_context->stack) {
		fprintf(stderr, "Failed to allocate stack\n");
		return;
	}
	app_context->sp = INITIAL_SP;
	app_context->oldSP = 0;

	// Initialize subsystems
	quit_swf = 0;
	is_playing = 1;
	bad_poll = 0;
	current_frame = 0;
	next_frame = 0;
	manual_next_frame = 0;

	// Store frame info globally for ActionCall opcode
	g_frame_funcs = app_context->frame_funcs;
	g_frame_count = app_context->frame_count;

	initTime(app_context);
	initMap();

	// Initialize heap allocator
	if (!heap_init(app_context, 0)) {  // 0 = use default size (64 MB)
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	tagInit(app_context);

	// Run frames in console mode
	frame_func* funcs = app_context->frame_funcs;
	current_frame = 0;
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	size_t tick_count = 0;

	// Forward declaration for catch-up display list management
	extern void ng_display_clear_after(size_t target_frame);

	while (!quit_swf && tick_count < max_ticks)
	{
		tick_count++;
		printf("[Frame %zu]\n", current_frame);

		if (current_frame >= g_frame_count)
		{
			printf("Frame %zu out of bounds (max %zu), stopping.\n", current_frame, g_frame_count);
			break;
		}
		if (funcs[current_frame])
		{
			funcs[current_frame](app_context);
		}
		else
		{
			printf("No function for frame %zu, stopping.\n", current_frame);
			break;
		}

		// Goto catch-up: when an action (GotoFrame, GoToLabel, etc.) triggered
		// a goto, process intermediate frame tags inline to match Flash's behavior.
		// Flash processes PlaceObject/RemoveObject for intermediate frames within
		// the same frame advance, but skips DoAction tags (main timeline scripts).
		// In our model, catch_up_mode=1 causes generated frame functions to skip
		// their script_N() calls while still executing tag functions.
		if (goto_from_action && manual_next_frame)
		{
			size_t original_frame = current_frame;
			size_t target = next_frame;
			manual_next_frame = 0;
			goto_from_action = 0;

			// Remove display list entries placed after the target frame
			ng_display_clear_after(target);

			catch_up_mode = 1;
			if (target <= original_frame)
			{
				// Backward goto: replay tags from frame 0 to target.
				// Protect display list entries placed at or before target from
				// RemoveObject2 (they're part of the preserved state).
				catch_up_backward = 1;
				catch_up_target = target;
				for (size_t f = 0; f <= target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
				catch_up_backward = 0;
			}
			else
			{
				// Forward goto: process tags for frames between current and target
				for (size_t f = original_frame + 1; f <= target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
			}
			catch_up_mode = 0;
			current_frame = target;

			// After catch-up, the goto's advance is consumed; fall through
			// to the normal advance logic below.
		}

		// Advance to next frame
		// IMPORTANT: Process manual_next_frame BEFORE checking is_playing
		// This ensures that gotoFrame/gotoAndStop commands execute the target frame
		// even when they stop playback
		if (manual_next_frame)
		{
			current_frame = next_frame;
			manual_next_frame = 0;
		}
		else if (is_playing)
		{
			// Only advance naturally if we're still playing
			current_frame++;
		}
		else
		{
			// Stopped and no manual jump - exit loop
			break;
		}
	}

	printf("\n=== SWF Execution Completed ===\n");

	// Cleanup
	heap_shutdown(app_context);
	freeMap();
	free(app_context->stack);
}

#endif // NO_GRAPHICS
