// Frame-capture state machine. See capture.h for the public API.
//
// Extracted from swf_headless.c so swf.c (OFFSCREEN_RENDER mode) can drive
// the same scheduling code. Renderer-touching paths gate on
// HEADLESS_RENDER_ENABLED; verify_output.py defines that for image-comparison
// tests under both --mode=graphics and --mode=graphics-headless-legacy.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libswf/capture.h>
#include <libswf/swf.h>
#include <renderer.h>

// The active RenderContext is owned by the frame-loop file (swf.c or
// swf_headless.c). We borrow it via extern.
extern RenderContext* context;

#define MAX_CAPTURES 16

typedef enum {
	CAPTURE_LAST_FRAME,
	CAPTURE_ITERATION,
	CAPTURE_FS_COMMAND,
} CaptureType;

typedef struct {
	char name[128];
	CaptureType type;
	int iteration;
	int saved;
} CaptureEntry;

static CaptureEntry g_captures[MAX_CAPTURES];
static int g_capture_count = 0;
static char g_capture_output_dir[512] = ".";
static int g_has_last_frame_capture = 0;
// Next fs_command capture index to consume + currently-pending one (-1 = none).
static int g_fscommand_capture_idx = 0;
static int g_fscommand_pending = -1;
// Internal tick counter, incremented by capture_tick_pre_frame so callers
// don't need to thread their tick_count through the API.
static int g_capture_tick = 0;

void parse_capture_triggers(void)
{
	const char* dir = getenv("CAPTURE_OUTPUT_DIR");
	if (dir) {
		strncpy(g_capture_output_dir, dir, sizeof(g_capture_output_dir) - 1);
		g_capture_output_dir[sizeof(g_capture_output_dir) - 1] = '\0';
	}

	const char* env = getenv("CAPTURE_TRIGGERS");
	if (!env || !*env) return;

	char buf[4096];
	strncpy(buf, env, sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = '\0';

	char* saveptr = NULL;
	for (char* token = strtok_r(buf, ",", &saveptr);
	     token && g_capture_count < MAX_CAPTURES;
	     token = strtok_r(NULL, ",", &saveptr))
	{
		CaptureEntry* e = &g_captures[g_capture_count];
		memset(e, 0, sizeof(*e));

		char* colon1 = strchr(token, ':');
		if (!colon1) continue;
		size_t name_len = (size_t)(colon1 - token);
		if (name_len >= sizeof(e->name)) name_len = sizeof(e->name) - 1;
		memcpy(e->name, token, name_len);
		e->name[name_len] = '\0';

		char* type_str = colon1 + 1;
		if (strncmp(type_str, "last_frame", 10) == 0) {
			e->type = CAPTURE_LAST_FRAME;
			g_has_last_frame_capture = 1;
		} else if (strncmp(type_str, "iteration:", 10) == 0) {
			e->type = CAPTURE_ITERATION;
			e->iteration = atoi(type_str + 10);
		} else if (strncmp(type_str, "fs_command", 10) == 0) {
			e->type = CAPTURE_FS_COMMAND;
		} else {
			continue;
		}
		g_capture_count++;
	}
}

#ifdef HEADLESS_RENDER_ENABLED
static void save_capture(CaptureEntry* e)
{
	if (e->saved) return;
	char path[1024];
	snprintf(path, sizeof(path), "%s/%s.png", g_capture_output_dir, e->name);
	if (renderer_save_png(context, path))
		fprintf(stderr, "[capture] Saved %s\n", path);
	else
		fprintf(stderr, "[capture] Failed to save %s\n", path);
	e->saved = 1;

	// Stop copying to the readback buffer once nothing else needs it.
	int still_need_capture = 0;
	for (int i = 0; i < g_capture_count; i++) {
		if (!g_captures[i].saved && (g_captures[i].type == CAPTURE_LAST_FRAME ||
		    g_captures[i].type == CAPTURE_FS_COMMAND))
			still_need_capture = 1;
	}
	if (!still_need_capture)
		context->capture_requested = 0;
}
#endif

int capture_has_pending(void)
{
#ifdef HEADLESS_RENDER_ENABLED
	for (int i = 0; i < g_capture_count; i++) {
		if (!g_captures[i].saved) return 1;
	}
#endif
	return 0;
}

// Called from actionFSCommand when fscommand("capture", ...) fires. Runs
// BEFORE tagShowFrame in the same tick (DoAction precedes ShowFrame), so
// requesting capture here means close_pass will copy to the readback buffer.
void capture_on_fscommand(void)
{
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	for (int i = g_fscommand_capture_idx; i < g_capture_count; i++) {
		if (g_captures[i].type == CAPTURE_FS_COMMAND && !g_captures[i].saved) {
			renderer_request_capture(context);
			g_fscommand_pending = i;
			g_fscommand_capture_idx = i + 1;
			return;
		}
	}
#endif
}

void capture_tick_pre_frame(void)
{
	g_capture_tick++;
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	int need_capture = 0;
	if (g_has_last_frame_capture) need_capture = 1;
	for (int ci = 0; ci < g_capture_count; ci++) {
		if (g_captures[ci].type == CAPTURE_ITERATION &&
		    g_captures[ci].iteration == g_capture_tick &&
		    !g_captures[ci].saved)
			need_capture = 1;
	}
	if (need_capture)
		renderer_request_capture(context);
#endif
}

void capture_tick_after_events(SWFAppContext* app_context)
{
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	int need_render = 0;
	for (int ci = 0; ci < g_capture_count; ci++) {
		CaptureEntry* e = &g_captures[ci];
		if (!e->saved && e->type == CAPTURE_ITERATION && e->iteration == g_capture_tick) {
			need_render = 1;
			break;
		}
	}
	if (need_render) {
		extern void tagRerenderFrame(SWFAppContext* app_context);
		tagRerenderFrame(app_context);
	}
#else
	(void)app_context;
#endif
}

void capture_tick_post_frame(void)
{
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	for (int ci = 0; ci < g_capture_count; ci++) {
		CaptureEntry* e = &g_captures[ci];
		if (e->saved) continue;
		if (e->type == CAPTURE_ITERATION && e->iteration == g_capture_tick)
			save_capture(e);
	}
	if (g_fscommand_pending >= 0) {
		save_capture(&g_captures[g_fscommand_pending]);
		g_fscommand_pending = -1;
	}
#endif
}

void capture_save_last_frame(void)
{
#ifdef HEADLESS_RENDER_ENABLED
	if (!context || !context->renderer_ok) return;
	for (int ci = 0; ci < g_capture_count; ci++) {
		if (g_captures[ci].type == CAPTURE_LAST_FRAME && !g_captures[ci].saved)
			save_capture(&g_captures[ci]);
	}
#endif
}
