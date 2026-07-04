#ifdef NO_GRAPHICS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <setjmp.h>
#include <swf.h>
#include "constants.h"

// Frame rect offset — defaults to 0 for SWFs with origin at (0,0).
// Generated constants.h defines these for SWFs with translated frame rects.
#ifndef FRAME_X_MIN_TWIPS
#define FRAME_X_MIN_TWIPS 0
#endif
#ifndef FRAME_Y_MIN_TWIPS
#define FRAME_Y_MIN_TWIPS 0
#endif
#include <tag.h>
#include <action.h>
#include <action_queue.h>
#include <sprite_frame_scripts.h>
#include <variables.h>
#include <object.h>
#include <utils.h>
#include <heap.h>

// Core runtime state - exported
int quit_swf = 0;
// Set ONLY by FSCommand:quit (either form of actionGetURL). Unlike
// `quit_swf` which is also emitted at the end of a SWF's last frame as
// a normal end-of-movie marker, `g_force_quit` means the SWF explicitly
// asked to terminate: break out of the tick loop on next iteration.
int g_force_quit = 0;
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
float g_drag_virt_x = 0.0f;   // virtual stage X of dragged clip (twips)
float g_drag_virt_y = 0.0f;   // virtual stage Y of dragged clip (twips)
char g_drag_target_name[256] = "";  // name of most-recently dragged clip (persists after stopDrag)

// Default findMovieEntry/getPreludeEntry stubs when no child movies are linked
#ifndef HAS_CHILD_MOVIES
MovieEntry* findMovieEntry(const char* filename) {
	(void)filename;
	return NULL;
}
MovieEntry* getPreludeEntry(int idx) {
	(void)idx;
	return NULL;
}
#endif

// Default findDataFile stub when no data files are linked
#ifndef HAS_DATA_FILES
DataFileEntry* findDataFile(const char* filename) {
	(void)filename;
	return NULL;
}
void getDataFilesMaxImageDims(int* out_w, int* out_h) {
	if (out_w) *out_w = 0;
	if (out_h) *out_h = 0;
}
#endif

// Goto catch-up state
int catch_up_mode = 0;
int goto_from_action = 0;
int catch_up_backward = 0;    // 1 if current catch-up is a backward goto
// Set by ng_executeGotoCatchUp when it inlines the target frame's script during
// the caller frame's body. Cleared in the main loop after funcs[current_frame]
// returns. The recompiler emits a wrap-back at the end of the LAST frame's body
// (next_frame=0; manual_next_frame=1) to loop the timeline; that wrap-back
// fires unconditionally and overrides a goto+play that the script issued
// earlier in the same frame. We use this flag to undo the wrap-back's effect
// on manual_next_frame so the natural advance moves to current_frame+1
// (gotoAndPlay) or stays put (gotoAndStop). Key test: from_shumway/timeline/timeline_as2_1.
int g_goto_inlined_in_caller_frame = 0;
// Phase 4 (TRANSFORMED_BY_SCRIPT_WRAP_BACK): set to 1 when a natural backward
// wrap triggers catch-up, signaling actionDrainOnloadAndScript to clean up
// unsurvivors before scripts run. Cleared on first drain.
int g_natural_wrap_cleanup_pending = 0;
// Set to 1 for exactly one frame execution: the frame_0 re-run that immediately
// follows a natural backward timeline wrap (last frame loops back to frame 0).
// Mirrors Ruffle's `is_rewind` on the implicit `run_goto(1)` it does for the
// loop wrap (NextFrame::First branch). tagPlaceObject2 consults this so a
// timeline Place landing on an occupied depth — e.g. one a script swapDepths'd
// a different character into — is treated as a modify of the existing child
// (Ruffle's run_goto `(_, Some(prev_child), true)` arm) rather than refused.
int g_loopback_replay = 0;
// Armed by the natural-backward-wrap branch; converted to g_loopback_replay
// immediately before funcs[current_frame] runs (so it's scoped tightly to the
// root frame re-run and doesn't leak into advance_sprite_frames).
int g_loopback_replay_armed = 0;
size_t catch_up_target = 0;   // target frame for backward goto protection
int g_deferred_goto_play = 0; // Set when gotoAndPlay targets root from inside a sprite
int g_deferred_root_goto = 0; // Set when GotoFrame targets root from inside a sprite — skip re-running current frame
// Phase G (GOTO_FIFO_UNIFICATION_INCREMENTAL): retired g_deferred_goto_queue,
// g_deferred_goto_queue_count, g_deferred_goto_script, g_deferred_goto_target,
// and the MAX_DEFERRED_GOTO_QUEUE-sized backing array. Phase E removed all push
// sites (the inline target script call now runs at the end of
// ng_executeGotoCatchUp), so the outer drain loop in the per-tick retry was
// dead code from Phase E onward.
int g_tag_skip_mode = 0;            // 1 = tag functions are no-ops (scripts-only re-run)
// Phase E (GOTO_FIFO_UNIFICATION_INCREMENTAL): one-shot flag set by callers
// of ng_executeGotoCatchUp that need the inline target-frame script call to be
// skipped (e.g. actionGotoFrame's was_clamped path: gotoAndStop(9999) clamps to
// the last frame but Flash does not run that frame's actions).
int g_skip_inline_target_script = 0;

// Execute goto catch-up inline (called from actionGotoFrame)
// Processes intermediate frame tags and target frame tags immediately
void ng_executeGotoCatchUp(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	// If called from inside a sprite init context, swap to root DL
	// so that root frame functions (PlaceObject2, RemoveObject2, etc.)
	// operate on the correct display list.
	DisplayObject* saved_sprite_dl = NULL;
	size_t saved_sprite_max = 0, saved_sprite_cap = 0;
	int swapped = ng_swapToRootDL(&saved_sprite_dl, &saved_sprite_max, &saved_sprite_cap);

	// Advance placement generation so goto target frame's placements
	// are distinguishable from the calling frame's placements.
	extern size_t g_place_gen;
	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	// Self-goto guard: a goto targeting the frame whose own script is currently
	// executing (e.g. GotoFrame2 play=1 / gotoAndPlay(_currentframe) issued from
	// the running frame) must NOT replay tags or re-run funcs[target]. The
	// playhead is already on `target`; re-running funcs[target] here re-queues
	// that same script, which re-issues the goto → unbounded loop (the script
	// FIFO never drains). Flash does not re-execute the current frame's actions
	// on a same-frame goto within the tick — it just confirms the playhead and
	// lets is_playing (set by any trailing Stop/Play in the same script) decide
	// whether the NEXT tick advances. Consume the goto request and return so the
	// main loop's natural advance (current_frame++ when is_playing) still applies.
	// Key test: from_gnash/misc-ming.all/gotoFrame2Test (GotoFrame2 play=1 to the
	// current frame, then Stop()).
	if (target == original_frame) {
		goto_from_action = 0;
		manual_next_frame = 0;
		current_frame = target;
		return;
	}

	ng_display_clear_after(app_context, target);

	// Process ALL frames (intermediate + target) with catch_up_mode=1
	// so only tags execute (PlaceObject, etc.) and scripts are suppressed.
	// The target frame's script will run later via the main loop's catch-up
	// after the calling script finishes.
	// Save/restore g_tag_skip_mode so nested gotos (from deferred scripts)
	// properly process tags.
	// Set g_defer_sprite_init so tagShowFrame defers process_sprite_needs_init:
	// sprite init scripts must fire AFTER the deferred parent-frame DoAction.
	int saved_tag_skip = g_tag_skip_mode;
	extern int g_defer_sprite_init;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	// Phase 7b: suppress sprite-DoAction queueing while we replay goto tags —
	// queued scripts would land in the SCRIPT FIFO before the target frame's
	// root DoAction (queued later when the main loop runs funcs[target] with
	// g_tag_skip_mode=1), producing sprite-first-then-root order. Instead,
	// sprite scripts fire synchronously inside ng_run_deferred_sprite_init_impl
	// after the target frame's root script drains.
	actionGotoCatchupEnter();
	if (target <= original_frame)
	{
#ifdef NO_GRAPHICS
		// Clean up dynamic MCs and reset swapped depths before backward replay
		{
			extern void actionRewindCleanup(SWFAppContext* app_context);
			actionRewindCleanup(app_context);
		}
#endif
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
		// ng_display_clear_after preserved initialized sprite entries so
		// tagPlaceObject2's catch-up path could modify them (matching Ruffle's
		// survives_rewind). Any sprite whose depth was not re-placed during
		// catch-up must be cleared now.
		{
			extern void ng_display_cleanup_unplaced_after(SWFAppContext*, size_t);
			ng_display_cleanup_unplaced_after(app_context, target);
		}
	}
	else
	{
		for (size_t f = original_frame + 1; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
	}
	actionGotoCatchupLeave();
	catch_up_mode = 0;
	g_tag_skip_mode = saved_tag_skip;
	// Do NOT restore g_defer_sprite_init here — keep it set so that the
	// calling frame's tagShowFrame (which runs after this returns) also defers
	// sprite init. g_defer_sprite_init is cleared in the deferred-script loop
	// after ng_run_deferred_sprite_init completes.
	(void)saved_defer_sprite;
	current_frame = target;

	// Drain CLIP_INIT and REGISTER_CTOR queued during catch-up.
	// tagShowFrame's safety drain skipped these while g_goto_catchup_active>0.
	// aq_drain's clip->avm1_removed filter skips entries whose MC was
	// invalidated by a RemoveObject in a later catch-up frame — mirrors
	// Ruffle's run_goto goto_commands aggregation where place+remove pairs
	// in the same goto cancel out without firing the constructor.
	// CLIP_CONSTRUCT (clip-event handler) drains chronologically per-frame
	// during catch-up — see comment in tag.c tagShowFrame.
	// Key test: register_class/RegisterClassTest3.
	actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
	actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);

	// Restore sprite DL if we swapped
	if (swapped)
		ng_restoreFromRootDL(saved_sprite_dl, saved_sprite_max, saved_sprite_cap);

	// Leave goto_from_action and manual_next_frame set so the main loop
	// will run the target frame's script after the calling script finishes.
	// But we need to clear them to avoid double-processing of tags.
	goto_from_action = 0;
	manual_next_frame = 0;

	// Phase E (GOTO_FIFO_UNIFICATION_INCREMENTAL): inline the target frame's
	// script call here in scripts-only mode (g_tag_skip_mode=1) wrapped in
	// drain-suppress. The recompiler-emitted actionQueueScript inside
	// funcs[target] lands the target's script into AQ_KIND_SCRIPT. The
	// drain-suppress prevents funcs[target]'s own SHOW_FRAME drain from
	// firing — the outer drain (the calling script's recompiler-emitted
	// SHOW_FRAME drain) picks up the entry, FIFO-interleaved with sprite
	// scripts queued earlier in the same calling-script body.
	//
	// Pre-Phase-E behavior: pushed `target` into g_deferred_goto_queue and
	// the swf_core.c outer loop drained it as a separate Phase 0/1/2/3
	// sequence. Phase F adds back sprite-init-via-queue so eager-init no
	// longer needs the explicit Phase 1/3 calls.
	int skip_inline = g_skip_inline_target_script;
	g_skip_inline_target_script = 0;  // one-shot
	if (!skip_inline && target < g_frame_count && funcs[target])
	{
		// Phase F (GOTO_FIFO_UNIFICATION_INCREMENTAL): wrap the inline target
		// script call with deferred sprite init so eager-init scripts queue
		// alongside the target frame's root script in proper FIFO order.
		//   Phase 1: sprites placed BEFORE target → queue first.
		//   Phase 2 (target script): queues "root <target>" via gate.
		//   Phase 3: sprites placed ON or AFTER target → queue last.
		// All entries land in AQ_KIND_SCRIPT and the outer (caller) drain
		// processes them in FIFO order. The drain-suppress wrap on the target
		// script call is preserved so funcs[target]'s own SHOW_FRAME drain
		// (if any) doesn't pre-drain entries the caller still owns.
		extern void ng_run_deferred_sprite_init_before(SWFAppContext*, size_t);
		extern void ng_run_deferred_sprite_init_on_or_after(SWFAppContext*, size_t);
		extern int g_defer_sprite_init;
		int saved_defer_phase_f = g_defer_sprite_init;
		g_defer_sprite_init = 0;
		ng_run_deferred_sprite_init_before(app_context, target);
		int saved_tag_skip_phase_e = g_tag_skip_mode;
		g_tag_skip_mode = 1;
		actionDrainSuppressEnter();
		funcs[target](app_context);
		actionDrainSuppressLeave();
		g_tag_skip_mode = saved_tag_skip_phase_e;
		ng_run_deferred_sprite_init_on_or_after(app_context, target);
		g_defer_sprite_init = saved_defer_phase_f;
		// Signal to the main loop that we inlined the target script while the
		// caller frame was running. The recompiler-emitted wrap-back at the end
		// of the LAST frame (next_frame=0; manual_next_frame=1) would otherwise
		// override the natural advance and loop the timeline back to frame 0
		// even though the script just gotoAndPlay'd to a specific target.
		g_goto_inlined_in_caller_frame = 1;
	}
}

// Execute goto tags-only: processes intermediate frame tags (PlaceObject,
// RemoveObject, etc.) immediately so that avm1_removed gets set synchronously,
// but does NOT queue deferred scripts or modify current_frame.
// The actual script execution and frame advancement is left to the main loop
// via goto_from_action / manual_next_frame / g_deferred_root_goto.
// Used when a root goto happens from a non-sprite-init context (regular frame
// script calling _root.nextFrame(), etc.) and we need synchronous removal but
// must avoid double-executing the target frame's script.
void ng_executeGotoTagsOnly(SWFAppContext* app_context)
{
	if (!goto_from_action || !manual_next_frame) return;

	// Advance placement generation
	extern size_t g_place_gen;
	g_place_gen++;

	frame_func* funcs = g_frame_funcs;
	size_t original_frame = current_frame;
	size_t target = next_frame;

	ng_display_clear_after(app_context, target);

	int saved_tag_skip = g_tag_skip_mode;
	extern int g_defer_sprite_init;
	int saved_defer_sprite = g_defer_sprite_init;
	g_tag_skip_mode = 0;
	g_defer_sprite_init = 1;
	catch_up_mode = 1;
	if (target <= original_frame)
	{
#ifdef NO_GRAPHICS
		{
			extern void actionRewindCleanup(SWFAppContext* app_context);
			actionRewindCleanup(app_context);
		}
#endif
		catch_up_backward = 1;
		catch_up_target = target;
		for (size_t f = 0; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
		catch_up_backward = 0;
		{
			extern void ng_display_cleanup_unplaced_after(SWFAppContext*, size_t);
			ng_display_cleanup_unplaced_after(app_context, target);
		}
	}
	else
	{
		for (size_t f = original_frame + 1; f <= target && f < g_frame_count; f++)
		{
			current_frame = f;
			if (funcs[f]) funcs[f](app_context);
		}
	}
	catch_up_mode = 0;
	g_tag_skip_mode = saved_tag_skip;
	g_defer_sprite_init = saved_defer_sprite;

	// Restore current_frame — the main loop manages frame advancement.
	// Leave goto_from_action and manual_next_frame set so the main loop's
	// catch-up path processes the target frame (scripts + sprite init).
	current_frame = original_frame;

	// Set deferred root goto so the main loop skips re-running the current
	// frame function and goes straight to goto catch-up.
	g_deferred_root_goto = 1;
}

// ---------------------------------------------------------------------------
// Input Event Pump (Phase 3)
// Loads a pre-processed event file and delivers events at tick boundaries.
// ---------------------------------------------------------------------------

typedef enum {
    EV_WAIT,
    EV_MOUSE_MOVE,
    EV_MOUSE_DOWN_LEFT,  EV_MOUSE_UP_LEFT,
    EV_MOUSE_DOWN_RIGHT, EV_MOUSE_UP_RIGHT,
    EV_MOUSE_DOWN_MIDDLE, EV_MOUSE_UP_MIDDLE,
    EV_MOUSE_WHEEL,
    EV_KEY_DOWN, EV_KEY_UP,
    EV_TEXT_INPUT,
    EV_TEXT_CONTROL,
    EV_FOCUS_GAINED, EV_FOCUS_LOST,
    EV_SET_CLIPBOARD_TEXT,
    EV_IME_PREEDIT,
    EV_IME_COMMIT,
} InputEventType;

typedef struct {
    InputEventType type;
    float x, y;    // for mouse events (stage pixels)
    int code;      // for key events, text codepoint
    char ctrl[32]; // for TEXT_CONTROL
    char text[1024]; // for SET_CLIPBOARD_TEXT
} InputEvent;

static InputEvent* g_events = NULL;
static size_t g_event_count = 0;
static size_t g_event_pos = 0;
static int g_key_press_consumed = 0;  // Set when button keyPress handles KEY_DOWN; gates TEXT_INPUT

void input_events_load(const char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) return;
    char line[1088];
    size_t count = 0;
    while (fgets(line, sizeof(line), f)) count++;
    rewind(f);
    g_events = malloc(count * sizeof(InputEvent));
    if (!g_events) { fclose(f); return; }
    g_event_count = 0;
    while (fgets(line, sizeof(line), f)) {
        InputEvent ev = {0};
        if (strncmp(line, "WAIT", 4) == 0)
            ev.type = EV_WAIT;
        else if (strncmp(line, "MOUSE_MOVE ", 11) == 0)
            { sscanf(line + 11, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_MOVE; }
        else if (strncmp(line, "MOUSE_DOWN_LEFT ", 16) == 0)
            { sscanf(line + 16, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_LEFT; }
        else if (strncmp(line, "MOUSE_UP_LEFT ", 14) == 0)
            { sscanf(line + 14, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_LEFT; }
        else if (strncmp(line, "MOUSE_DOWN_RIGHT ", 17) == 0)
            { sscanf(line + 17, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_RIGHT; }
        else if (strncmp(line, "MOUSE_UP_RIGHT ", 15) == 0)
            { sscanf(line + 15, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_RIGHT; }
        else if (strncmp(line, "MOUSE_DOWN_MIDDLE ", 18) == 0)
            { sscanf(line + 18, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_DOWN_MIDDLE; }
        else if (strncmp(line, "MOUSE_UP_MIDDLE ", 16) == 0)
            { sscanf(line + 16, "%f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_UP_MIDDLE; }
        else if (strncmp(line, "MOUSE_WHEEL ", 12) == 0)
            { sscanf(line + 12, "%d", &ev.code); ev.type = EV_MOUSE_WHEEL; }
        else if (strncmp(line, "KEY_DOWN ", 9) == 0)
            { sscanf(line + 9, "%d", &ev.code); ev.type = EV_KEY_DOWN; }
        else if (strncmp(line, "KEY_UP ", 7) == 0)
            { sscanf(line + 7, "%d", &ev.code); ev.type = EV_KEY_UP; }
        else if (strncmp(line, "TEXT_INPUT ", 11) == 0)
            { sscanf(line + 11, "%d", &ev.code); ev.type = EV_TEXT_INPUT; }
        else if (strncmp(line, "TEXT_CONTROL ", 13) == 0)
            { sscanf(line + 13, "%31s", ev.ctrl); ev.type = EV_TEXT_CONTROL; }
        else if (strncmp(line, "FOCUSGAINED", 11) == 0)
            ev.type = EV_FOCUS_GAINED;
        else if (strncmp(line, "FOCUSLOST", 9) == 0)
            ev.type = EV_FOCUS_LOST;
        else if (strncmp(line, "IME_PREEDIT ", 12) == 0) {
            ev.type = EV_IME_PREEDIT;
            // Format: "IME_PREEDIT cursor_from cursor_to text"
            int cf = -1, ct = -1;
            int n = 0;
            sscanf(line + 12, "%d %d %n", &cf, &ct, &n);
            ev.code = cf; // cursor_from in code field
            ev.x = (float)ct; // cursor_to in x field
            if (n > 0 && line[12 + n] != '\0') {
                strncpy(ev.text, line + 12 + n, sizeof(ev.text) - 1);
                ev.text[sizeof(ev.text) - 1] = '\0';
                // Strip trailing newline
                size_t tl = strlen(ev.text);
                while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
                    ev.text[--tl] = '\0';
            } else {
                ev.text[0] = '\0';
            }
        }
        else if (strncmp(line, "IME_COMMIT ", 11) == 0) {
            ev.type = EV_IME_COMMIT;
            strncpy(ev.text, line + 11, sizeof(ev.text) - 1);
            ev.text[sizeof(ev.text) - 1] = '\0';
            size_t tl = strlen(ev.text);
            while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
                ev.text[--tl] = '\0';
        }
        else if (strncmp(line, "SET_CLIPBOARD_TEXT", 18) == 0 && line[18] == ' ') {
            ev.type = EV_SET_CLIPBOARD_TEXT;
            // "SET_CLIPBOARD_TEXT " = 19 chars prefix; text starts at position 19
            strncpy(ev.text, line + 19, sizeof(ev.text) - 1);
            ev.text[sizeof(ev.text) - 1] = '\0';
            size_t tlen = strlen(ev.text);
            while (tlen > 0 && (ev.text[tlen-1] == '\n' || ev.text[tlen-1] == '\r'))
                ev.text[--tlen] = '\0';
        }
        else if (strncmp(line, "SET_CLIPBOARD_TEXT\n", 18) == 0
              || strncmp(line, "SET_CLIPBOARD_TEXT\r", 18) == 0
              || strcmp(line, "SET_CLIPBOARD_TEXT") == 0) {
            ev.type = EV_SET_CLIPBOARD_TEXT;
            ev.text[0] = '\0';
        }
        else continue;
        g_events[g_event_count++] = ev;
    }
    fclose(f);
}

static void input_events_deliver(SWFAppContext* app_context, InputEvent* ev)
{
    MouseState* ms = &app_context->mouse;
    switch (ev->type) {
    case EV_MOUSE_MOVE: {
        float new_sx = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        float new_sy = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        int mouse_actually_moved = (new_sx != ms->stage_x || new_sy != ms->stage_y);
        ms->stage_x = new_sx;
        ms->stage_y = new_sy;
        ms->moved = 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Update virtual drag position while dragging
        if (is_dragging) {
            g_drag_virt_x = ms->stage_x;
            g_drag_virt_y = ms->stage_y;
        }
        // Update text field drag selection
        if (ms->button_down) {
            extern void actionTextFieldDragSelect(SWFAppContext* app_context);
            actionTextFieldDragSelect(app_context);
        }
        // Dispatch onClipEvent(mouseMove) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_MOVE);
        // Dispatch onClipEvent(rollOver/rollOut/dragOver/dragOut) on hit-area transitions
        dispatch_clip_event_roll(app_context);
        // Broadcast Mouse.onMouseMove to Mouse listeners
        actionDispatchMouseMove(app_context);
        // Ruffle skips hover re-evaluation when mouse didn't move and
        // there's a hovered object (skip_mouse_hover = true). Mirror this
        // by only running button state + roll dispatch when mouse moved,
        // OR when there is no Tab virtual hover to protect.
        if (mouse_actually_moved || !actionHasVirtualHover()) {
            // End Tab virtual hover FIRST — fires rollOut (DoAction+AS2) on
            // the old Tab-hovered MC before ng_update_button_states fires
            // rollOver on the new mouse-hovered MC. This gives correct
            // per-object interleaving: old rollOut completes before new rollOver.
            if (mouse_actually_moved)
                actionEndVirtualHoverOnMouse(app_context);
            // Run per-event button state machine
            ng_update_button_states(app_context);
            // Dispatch AS2 roll/drag over/out events to dynamic MCs
            actionDispatchMCMouseMove(app_context);
        }
        // Global AS2 mc.onMouseMove dispatch to all sprite MCs
        actionDispatchMCMouseMoveGlobal(app_context);
        // Mouse move resets focus highlight (SWF<9 only; SWF9+ only left mouse down resets)
        actionResetHighlightForEvent(0); // 0=mouse_move
        break;
    }
    case EV_MOUSE_DOWN_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 1;
        ms->clicked = 1;
        // Key code 1 = VK_LBUTTON: toggle on mouse down
        app_context->keys.toggled[1] ^= 1;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Dispatch onClipEvent(mouseDown) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        // Broadcast Mouse.onMouseDown to Mouse listeners
        actionDispatchMouseDown(app_context);
        // Global AS2 mc.onMouseDown dispatch to all sprite MCs
        actionDispatchMCMouseDown(app_context);
        // Mouse click focus acquisition (before press dispatch so focus traces precede onPress)
        actionMouseClickFocus(app_context);
        // Run per-event button state machine (processes OverUpToOverDown = press)
        ng_update_button_states(app_context);
        dispatch_clip_event_press(app_context);
        // Re-evaluate roll/drag transitions: button-down may convert ROLL→DRAG state
        dispatch_clip_event_roll(app_context);
        // Dispatch AS2 onPress to dynamic MCs
        actionDispatchMCPress(app_context);
        // Left mouse down always resets focus highlight (all SWF versions)
        actionResetHighlightForEvent(1); // 1=left_down
        // Clear Tab virtual hover
        actionClearVirtualHover();
        break;
    case EV_MOUSE_UP_LEFT:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        ms->button_down = 0;
        ms->released = 1;
        { extern void actionTextFieldDragEnd(SWFAppContext*); actionTextFieldDragEnd(app_context); }
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Dispatch onClipEvent(mouseUp) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        // Broadcast Mouse.onMouseUp to Mouse listeners
        actionDispatchMouseUp(app_context);
        // Global AS2 mc.onMouseUp dispatch to all sprite MCs
        actionDispatchMCMouseUp(app_context);
        // Run per-event button state machine (processes OverDownToOverUp = release)
        ng_update_button_states(app_context);
        dispatch_clip_event_release(app_context);
        // Re-evaluate roll/drag transitions: button-up may convert DRAG→ROLL state
        dispatch_clip_event_roll(app_context);
        // Dispatch AS2 onRelease/onReleaseOutside to dynamic MCs
        actionDispatchMCRelease(app_context);
        // Mouse up (left) resets focus highlight (SWF<9 only)
        actionResetHighlightForEvent(2); // 2=left_up
        // Clear Tab virtual hover
        actionClearVirtualHover();
        break;
    case EV_MOUSE_DOWN_MIDDLE:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        // Middle mouse button = VK_MBUTTON = key code 4
        app_context->keys.down[4] = 1;
        app_context->keys.toggled[4] ^= 1;
        // Middle click fires onClipEvent(mouseDown) but NOT button press
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_DOWN);
        actionDispatchMouseDown(app_context);
        actionDispatchMCMouseDown(app_context);
        break;
    case EV_MOUSE_UP_MIDDLE:
        ms->stage_x = ev->x * 20.0f + FRAME_X_MIN_TWIPS;
        ms->stage_y = ev->y * 20.0f + FRAME_Y_MIN_TWIPS;
        root_movieclip.xmouse = ev->x + (float)FRAME_X_MIN_TWIPS / 20.0f;
        root_movieclip.ymouse = ev->y + (float)FRAME_Y_MIN_TWIPS / 20.0f;
        app_context->keys.down[4] = 0;
        dispatch_clip_event_flag(app_context, CLIP_EVENT_MOUSE_UP);
        actionDispatchMouseUp(app_context);
        actionDispatchMCMouseUp(app_context);
        break;
    case EV_KEY_DOWN: {
        if (ev->code >= 0 && ev->code < 256) {
            app_context->keys.down[ev->code] = 1;
            // Toggle state for all keys on key-down (isToggled tracks press count parity)
            app_context->keys.toggled[ev->code] ^= 1;
        }
        app_context->keys.last_key_down = ev->code;
        // ASCII value: printable ASCII range (32-126)
        app_context->keys.last_key_ascii = (ev->code >= 32 && ev->code <= 126) ? ev->code : 0;
        // Dispatch onClipEvent(keyDown) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_DOWN);
        // Dispatch onKeyDown to focused MC (fires before Key broadcast)
        actionDispatchKeyDownToFocused(app_context, ev->code);
        // Broadcast onKeyDown to Key listeners
        actionDispatchKeyDown(app_context);

        // Dead key composition: peek ahead at TEXT_INPUT events before button keyPress.
        // Only letter keys (A-Z, code 65-90) can participate in dead key composition.
        // Non-letter keys (Enter, Space, Tab, etc.) always get normal keyPress handling
        // even if their TextInput codepoint differs from the key code.
        int is_letter_key = (ev->code >= 65 && ev->code <= 90);
        int key_lower = is_letter_key ? ev->code + 32 : ev->code;
        int has_matching_text_input = 0;
        int has_non_matching_text_input = 0;
        int has_any_text_input = 0;
        if (is_letter_key) {
            // Scan ahead for TEXT_INPUT events following this KEY_DOWN
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    has_any_text_input = 1;
                    int cp = g_events[peek].code;
                    if (cp == key_lower || cp == ev->code)
                        has_matching_text_input = 1;
                    else
                        has_non_matching_text_input = 1;
                }
            }
        }
        if (has_any_text_input && !has_matching_text_input) {
            // Pure composition (e.g., dead key " + a = ä): all TEXT_INPUTs are composed.
            // Process them now and suppress button keyPress entirely.
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    actionTextFieldInput(app_context, g_events[peek].code);
                    g_events[peek].type = -1;  // mark as consumed
                }
            }
            g_key_press_consumed = 0;
        } else if (has_non_matching_text_input) {
            // Mixed: dead key flush + raw key (e.g., dead key " + r = " then r).
            // Process non-matching TEXT_INPUTs now, then fire button keyPress.
            for (size_t peek = g_event_pos + 1; peek < g_event_count; peek++) {
                if (g_events[peek].type == EV_KEY_UP || g_events[peek].type == EV_KEY_DOWN
                    || g_events[peek].type == EV_WAIT) break;
                if (g_events[peek].type == EV_TEXT_INPUT) {
                    int cp = g_events[peek].code;
                    if (cp != key_lower && cp != ev->code) {
                        actionTextFieldInput(app_context, cp);
                        g_events[peek].type = -1;  // mark as consumed
                    }
                }
            }
            int key_press_handled = dispatch_button_key_actions(app_context, ev->code);
            g_key_press_consumed = key_press_handled;
            if (!key_press_handled)
                actionDispatchKeyPressToFocused(app_context, ev->code);
            if (!key_press_handled && ev->code == 9) {
                int shift_held = (app_context->keys.down[16] != 0);
                actionAdvanceTabFocus(app_context, shift_held);
            }
        } else {
            // Normal case: no dead key composition involved.
            int key_press_handled = dispatch_button_key_actions(app_context, ev->code);
            g_key_press_consumed = key_press_handled;
            if (!key_press_handled)
                actionDispatchKeyPressToFocused(app_context, ev->code);
            if (!key_press_handled && ev->code == 9) {
                int shift_held = (app_context->keys.down[16] != 0);
                actionAdvanceTabFocus(app_context, shift_held);
            }
        }
        break;
    }
    case EV_KEY_UP:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 0;
        // Update Key.getCode()/getAscii() for the keyUp event
        app_context->keys.last_key_down = ev->code;
        app_context->keys.last_key_ascii = (ev->code >= 32 && ev->code <= 126) ? ev->code : 0;
        // Dispatch onClipEvent(keyUp) to all clips
        dispatch_clip_event_flag(app_context, CLIP_EVENT_KEY_UP);
        // Dispatch onKeyUp to focused MC
        actionDispatchKeyUpToFocused(app_context, ev->code);
        // Broadcast onKeyUp to Key listeners
        actionDispatchKeyUp(app_context);
        break;
    case EV_TEXT_INPUT:
        // If a button keyPress already consumed this key, suppress the text input
        if (g_key_press_consumed) {
            g_key_press_consumed = 0;
            break;
        }
        g_key_press_consumed = 0;
        actionTextFieldInput(app_context, ev->code);
        break;
    case EV_TEXT_CONTROL:
        if (strcmp(ev->ctrl, "Paste") == 0)
            actionTextControlPaste(app_context);
        else if (strcmp(ev->ctrl, "Copy") == 0)
            actionTextControlCopy(app_context);
        else if (strcmp(ev->ctrl, "Cut") == 0)
            actionTextControlCut(app_context);
        else if (strcmp(ev->ctrl, "SelectAll") == 0)
            actionTextControlSelectAll(app_context);
        else if (strcmp(ev->ctrl, "MoveRight") == 0)
            actionTextControlMoveRight(app_context);
        else if (strcmp(ev->ctrl, "MoveLeft") == 0)
            actionTextControlMoveLeft(app_context);
        else if (strcmp(ev->ctrl, "MoveHome") == 0)
            actionTextControlMoveHome(app_context);
        else if (strcmp(ev->ctrl, "MoveEnd") == 0)
            actionTextControlMoveEnd(app_context);
        else if (strcmp(ev->ctrl, "Enter") == 0)
            actionTextControlEnter(app_context);
        else if (strcmp(ev->ctrl, "Backspace") == 0)
            actionTextControlBackspace(app_context);
        else if (strcmp(ev->ctrl, "Delete") == 0)
            actionTextControlDelete(app_context);
        break;
    case EV_SET_CLIPBOARD_TEXT:
        actionSetClipboardText(ev->text);
        break;
    case EV_IME_PREEDIT:
        { extern void actionTextFieldImeCompose(SWFAppContext*, const char*, int, int);
          actionTextFieldImeCompose(app_context, ev->text, ev->code, (int)ev->x); }
        break;
    case EV_IME_COMMIT:
        { extern void actionTextFieldImeCommit(SWFAppContext*, const char*);
          actionTextFieldImeCommit(app_context, ev->text); }
        break;
    case EV_FOCUS_LOST:
        // Window/tab lost focus: clear keyboard focus
        actionWindowFocusLost(app_context);
        break;
    case EV_FOCUS_GAINED:
        // Window/tab regained focus: no-op (focus is not auto-restored)
        break;
    default:
        break;
    }
}

static void input_events_pump_tick(SWFAppContext* app_context)
{
    while (g_event_pos < g_event_count) {
        InputEvent* ev = &g_events[g_event_pos];
        if (ev->type == EV_WAIT) {
            g_event_pos++;
            return;
        }
        input_events_deliver(app_context, ev);
        g_event_pos++;
        // Flush deferred rollOver/rollOut events between each event delivery.
        // Selection.setFocus() called from event handlers (e.g., Key listener
        // doing programmatic focus cycling) queues rollOver/rollOut that must
        // fire before the next event (e.g., KeyUp) is processed.
        actionFlushDeferredRollEvents(app_context);
    }
}

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
	g_force_quit = 0;
	is_playing = 1;
	bad_poll = 0;
	current_frame = 0;
	next_frame = 0;
	manual_next_frame = 0;

	// Store frame info globally for ActionCall opcode
	g_frame_funcs = app_context->frame_funcs;
	g_frame_count = app_context->frame_count;


	// MCL pending load dispatch (used after processTimers and in exit conditions)
	extern void actionFirePendingLoadInits(SWFAppContext* app_context);
	extern void actionPromotePendingMCLLoads(SWFAppContext* app_context);
	extern int g_pending_mcl_load_count;
	extern int g_pending_mcl_load_count_this_tick;
	extern int g_pending_mcl_load_count_next_tick;
	// Direct loadMovie pending load dispatch
	extern void actionFirePendingDirectLoads(SWFAppContext* app_context);
	extern int g_pending_direct_load_count;

	initTime(app_context);
	initMap();

	// Initialize heap allocator
	if (!heap_init(app_context, 0)) {  // 0 = use default size (64 MB)
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	// Allocate display state (in GRAPHICS mode these come from swf.c)
	// Must use HCALLOC (heap allocator) so grow_ptr can FREE them without SIGABRT
	dictionary = HCALLOC(INITIAL_DICTIONARY_CAPACITY, sizeof(Character));
	display_list = HCALLOC(INITIAL_DISPLAYLIST_CAPACITY, sizeof(DisplayObject));
	if (!dictionary || !display_list) {
		fprintf(stderr, "Failed to allocate display state\n");
		return;
	}

	// Initialize root display sentinel and set root_movieclip.display_obj
	extern void ng_sync_root_display_obj(void);
	extern void* ng_get_root_display_obj(void);
	ng_sync_root_display_obj();
	extern MovieClip root_movieclip;
	root_movieclip.display_obj = ng_get_root_display_obj();

#ifdef SWF_URL
	strncpy(root_movieclip.url, SWF_URL, sizeof(root_movieclip.url) - 1);
	root_movieclip.url[sizeof(root_movieclip.url) - 1] = '\0';
#endif
#ifdef SWF_FILE_SIZE
	root_movieclip.byte_size = SWF_FILE_SIZE;
#endif

	tagInit(app_context);

	// Set root movieclip as default execution context (for 'this' resolution)
	actionSetCurrentContext(&root_movieclip);

	// Run prelude SWFs before the main frame loop.
	// Preludes share the same _global, var_array, and scope — no version isolation.
	// Their init + frame 0 run once to set up prototypes, constructors, etc.
	{
		MovieEntry* prelude;
		for (int pi = 0; (prelude = getPreludeEntry(pi)) != NULL; pi++) {
			prelude->init_func(app_context);
			if (prelude->frame_count > 0 && prelude->frame_funcs != NULL
			    && prelude->frame_funcs[0] != NULL) {
				prelude->frame_funcs[0](app_context);
			}
		}
	}

	// Initialize execution timeout (set via MAX_EXECUTION_MS define)
#ifdef MAX_EXECUTION_MS
	actionSetMaxExecutionDuration(MAX_EXECUTION_MS);
#endif
	actionResetExecutionTimer();

	// Set up longjmp target for execution timeout abort
	{
		jmp_buf timeout_jmp;
		if (setjmp(timeout_jmp) != 0) {
			// Returned here from timeout longjmp — execution was halted
			goto frame_loop_exit;
		}
		actionSetTimeoutJmp(&timeout_jmp);
	}

	// Run frames in console mode
	frame_func* funcs = app_context->frame_funcs;
	current_frame = 0;
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	size_t tick_count = 0;

	// Continue until max_ticks. quit_swf prevents timeline looping but per-tick
	// handlers (onEnterFrame, sprite timelines, clip events) keep firing.
	while (tick_count < max_ticks)
	{
		tick_count++;

		// Bump global tick counter so DisplayObject.placed_at_tick stamps
		// from this tick can be distinguished from earlier ticks. See
		// SWFRecompDocs/plans/defer-newly-placed-sprite-advance-plan.md.
		{ extern size_t g_tick_count; g_tick_count++; }

		// Flash clears the action stack at each frame boundary: DoAction blocks
		// within a frame share stack (later blocks see earlier pushes), but the
		// stack resets between frames so leftover pushes don't leak to the next
		// frame. Matches Flash/Gnash — Ruffle clears per-DoAction (stricter).
		// Key test: misc-swfc/stackscope (var1/var2 set via cross-block share;
		// var3 undefined because it would require cross-frame leakage).
		app_context->sp = INITIAL_SP;
		app_context->oldSP = 0;

		// Check execution timeout — if halted, stop all further processing
		{
			extern u8 g_execution_halted;
			if (g_execution_halted) break;
		}

		// FSCommand:quit was called in a prior tick — exit as soon as nothing
		// is still asking to run. Without this, SWFs that FSCommand:quit from
		// a non-last frame but still have the natural end-of-movie loopback
		// (manual_next_frame=1, next_frame=0) would restart frame 0 and loop
		// forever. Uses `g_force_quit` — set only by the FSCommand:quit path,
		// NOT by the recompiler-emitted `quit_swf = 1` at the end of the last
		// frame (that's the regular end-of-movie marker, which needs to allow
		// sprite scripts queued that tick to still drain). Bypasses
		// `hasPlayingSprites`: once FSCommand:quit fires, sprites that loop
		// forever (no AS stop()) must not keep the player alive — that's the
		// pattern behind the fuzz `81004241…` indefinite loop.
		{
			extern int hasPlayingSounds(void);
			extern int hasActiveNetStreams(void);
			extern int g_force_quit;
			if (g_force_quit && !(g_events && g_event_pos < g_event_count)
			    && !actionHasEnterFrameHandlers()
			    && !hasActiveTimers()
			    && !hasPlayingSounds()
			    && !hasActiveNetStreams()
			    && !hasClipEnterFrameHandlers()) break;
		}

		// Process deferred unloadMovie state (MC properties change on next frame)
		extern void actionProcessDeferredUnloads(void);
		actionProcessDeferredUnloads();

		// Drain-suppress invariant: depth must be 0 at every tick boundary.
		// A leak indicates a missing actionDrainSuppressLeave somewhere; catch
		// it here at the next tick instead of letting it silently corrupt later
		// drain behavior.
#ifndef NDEBUG
		if (actionDrainSuppressed()) {
			fprintf(stderr, "drain-suppress depth leaked across tick: %d\n",
			        actionDrainSuppressed());
			abort();
		}
#endif

		// Reset per-tick edge flags
		app_context->mouse.moved = 0;
		app_context->mouse.clicked = 0;
		app_context->mouse.released = 0;
		app_context->keys.last_key_down = -1;

		// Clear g_defer_sprite_init at tick boundary. ng_executeGotoCatchUp
		// intentionally leaves it set so the calling frame's tagShowFrame
		// continues to defer sprite init for the rest of THAT tick. Without
		// a tick-boundary clear, a leak from a regular-frame-script
		// gotoAndPlay/gotoAndStop persists into subsequent frames, where it
		// suppresses process_sprite_needs_init for newly-placed sprites
		// (sprite_initialized stays 0 → onEnterFrame clip-actions never
		// dispatch). The sprite-init context call sites at action.c
		// 24758/25250/55081/55122/55160 already clear it inline; this
		// covers the regular-frame-script gotos that exit the action
		// handler with the flag still set. Key test: misc-ming/timeline_var_test.
		{ extern int g_defer_sprite_init; g_defer_sprite_init = 0; }

		// Finalize MCs that were marked for pending removal in the previous frame.
		// They persisted for one frame (scripts could still access them); now invalidate.
		actionFinalizePendingRemovals(app_context);

		// Promote pending MCL loads queued during the previous tick into the
		// "fire this tick" bucket, so events drain AFTER the loader's
		// next-frame DoAction has run (matches Flash semantics — see
		// SHUMWAY_AVM1_SUBTREES_PLAN.md Part B).
		actionPromotePendingMCLLoads(app_context);

		// Frame-first: advance sprites and run frame scripts before delivering events.
		// This ensures that listeners registered in frame scripts receive events from
		// the same tick (matching Flash/Ruffle's frame-then-event execution order).
		if (current_frame < g_frame_count)
		{
			// Two-phase sprite advancement matching Ruffle's execution order:
			// Phase 1: Advance root-level sprites (defer nested child recursion)
			// Phase 2: Run root frame script (EnterFrame flushes between RemoveObject & DoAction)
			// Phase 3: Advance nested children of sprites
			extern int g_advance_defer_nested;
			g_advance_defer_nested = 1;
			advance_sprite_frames(app_context);
			g_advance_defer_nested = 0;

			// Auto-advance attachMovie'd multi-frame clips (PROGRESS #15). Runs in
			// Phase 1 like a timeline sprite, before the root frame func reads
			// _currentframe. Skips clips attached this tick (not yet promoted) and
			// stopped clips.
			{
				extern void ng_advance_attached_clip_playheads(SWFAppContext* app_context);
				ng_advance_attached_clip_playheads(app_context);
			}

			// Pre-sync the AS-visible _currentframe of deferred nested sprites
			// (advanced in Phase 3 below) so a clip created this/last tick whose
			// onEnterFrame fires in the Phase-2 flush reads their post-advance
			// value, matching Ruffle's instantiation-ordered exec list (#10a).
			// Writes only mc->currentframe — playhead + scripts stay in Phase 3.
			{
				extern void presync_nested_sprite_currentframe(SWFAppContext* app_context);
				presync_nested_sprite_currentframe(app_context);
			}

			// Mark ENTER_FRAME dispatch as pending. The actual dispatch happens in
			// tagFlushPendingEnterFrame() which is called:
			//   1. By the recompiler-emitted code right before each DoAction (after RemoveObject)
			//   2. As fallback in tagShowFrame (for frames with no DoAction)
			// This ensures ENTER_FRAME fires after RemoveObject (skip removed clips)
			// but before DoAction (matching Flash's per-frame lifecycle ordering).
			{
				extern int g_enterframe_flush_pending;
				g_enterframe_flush_pending = 1;
			}

			// Run root frame function if the root timeline is playing
			if (is_playing || manual_next_frame)
			{
				// If a deferred root goto is pending (from a sprite script targeting root),
				// skip running funcs[current_frame] — go straight to goto catch-up.
				if (g_deferred_root_goto)
				{
				}
				else if (funcs[current_frame])
				{
					g_loopback_replay = g_loopback_replay_armed;
					g_loopback_replay_armed = 0;
					funcs[current_frame](app_context);
					g_loopback_replay = 0;
					// If a goto inside the script inlined the target frame's body
					// AND the recompiler-emitted last-frame wrap-back fired
					// afterward (signature: next_frame=0; manual_next_frame=1),
					// undo the wrap-back so the natural advance moves to
					// current_frame+1 (gotoAndPlay) or stays in place
					// (gotoAndStop). Without this, gotoAndPlay from inside the
					// last frame's script would loop back to 0.
					//
					// Skip the undo if g_deferred_root_goto is set — that signal
					// comes from ng_executeGotoTagsOnly (e.g.,
					// test.gotoAndStop("/:N") with a force_root path), which
					// relies on manual_next_frame=1 + next_frame=target staying
					// set so the main loop processes the deferred goto on the
					// next iteration. (Key test: avm1/goto_frame_number.)
					if (g_goto_inlined_in_caller_frame)
					{
						g_goto_inlined_in_caller_frame = 0;
						if (manual_next_frame && next_frame == 0 && !g_deferred_root_goto) {
							manual_next_frame = 0;
						}
					}
				}
				else
				{
					break;
				}
			}
			// Fallback: if root is stopped (no frame function ran), flush pending
			// ENTER_FRAME directly. Without this, dynamic MCs (createEmptyMovieClip)
			// with onEnterFrame handlers would never get dispatched while root is stopped.
			{
				extern int g_enterframe_flush_pending;
				if (g_enterframe_flush_pending)
					tagFlushPendingEnterFrame(app_context);
			}
			// Phase 3: advance nested sprite children (deferred from Phase 1)
			advance_nested_sprite_frames(app_context);

			// Phase 7b: drain any AQ_KIND_SCRIPT entries queued during
			// advance_sprite_frames (Phase 1 + Phase 3) that weren't covered
			// by the recompiler-emitted SHOW_FRAME drain inside
			// funcs[current_frame] — happens when root is stopped
			// (is_playing=0) and funcs didn't run, leaving sprite-tick
			// scripts orphaned in the queue. Also catches sprite scripts
			// queued AFTER funcs returned (advance_nested_sprite_frames
			// runs after funcs).
			actionDrainActionQueueByKind(app_context, AQ_KIND_SCRIPT);

			// Apply any sprite-frame-script gotoAndPlay that targeted its OWN
			// sprite WITHIN this tick (#10). Sprite scripts only run in the drain
			// above, so the manual flag is set too late for the advance passes;
			// applying it here (rebuild to target, resume at target+1) avoids the
			// one-tick-late goto + stutter the deferred top-of-loop path produces.
			ng_apply_pending_sprite_self_gotos(app_context);
		}
		else
		{
			// Past the last frame: keep dispatching per-tick AS handlers
			// (onEnterFrame, sprite timelines, clip ENTER_FRAME events).
			// Break if quit_swf and no remaining input events, handlers, or playing sprites.
			{
				extern int hasPlayingSounds(void);
				extern int hasActiveNetStreams(void);
				extern int hasPlayingLevels(void);
				if (quit_swf && !(g_events && g_event_pos < g_event_count)
				    && !actionHasEnterFrameHandlers()
				    && !hasPlayingSprites()
				    && !hasActiveTimers()
				    && !hasPlayingSounds()
				    && !hasActiveNetStreams()
				    && !hasPlayingLevels()
				    && !hasClipEnterFrameHandlers()
				    && g_pending_mcl_load_count == 0
				    && g_pending_direct_load_count == 0) break;
			}
			{
				extern int g_advance_defer_nested;
				g_advance_defer_nested = 1;
				advance_sprite_frames(app_context);
				g_advance_defer_nested = 0;
			}
			// Auto-advance attachMovie'd multi-frame clips past the last root frame
			// too (Flash keeps attached clips playing). PROGRESS #15.
			{
				extern void ng_advance_attached_clip_playheads(SWFAppContext* app_context);
				ng_advance_attached_clip_playheads(app_context);
			}
			// Pre-sync deferred nested sprites' _currentframe before the enterFrame
			// dispatch below (mirror of the playing branch; #10a).
			{
				extern void presync_nested_sprite_currentframe(SWFAppContext* app_context);
				presync_nested_sprite_currentframe(app_context);
			}
			// Set enterframe_eligible for all initialized sprites (recursive into buttons)
			{
				extern void set_enterframe_eligible_recursive(DisplayObject*, size_t);
				set_enterframe_eligible_recursive(display_list, max_depth);
			}
			// Dispatch clip event ENTER_FRAME (recursive, children before parents)
			{
				extern MovieClip root_movieclip;
				extern void dispatch_enterframe_clip_actions(SWFAppContext*, DisplayObject*, size_t, MovieClip*);
				dispatch_enterframe_clip_actions(app_context, display_list, max_depth, &root_movieclip);
			}
			actionDispatchEnterFrameHandlers(app_context);
			actionDispatchRootVarMapEnterFrame(app_context);
			advance_nested_sprite_frames(app_context);

			// Phase 7b: drain sprite SCRIPT entries queued during
			// advance_sprite_frames in the past-last-frame branch
			// (no funcs[current_frame] runs here, so the recompiler-emitted
			// drain doesn't fire — same orphaned-script issue as the
			// is_playing=0 branch above).
			actionDrainActionQueueByKind(app_context, AQ_KIND_SCRIPT);

			// Same-tick self gotoAndPlay application (#10); see the playing branch.
			ng_apply_pending_sprite_self_gotos(app_context);
		}

		// Promote this tick's freshly-attached multi-frame clips to active so the
		// pump advances them STARTING NEXT tick (PROGRESS #15). Runs after the
		// deferred attach-init drain (inside the root frame func) so a clip's
		// frame-1 this.stop() has applied before it is ever advanced.
		{
			extern void ng_promote_attached_playheads(void);
			ng_promote_attached_playheads();
		}

		// Mark dynamic MCs (createEmptyMovieClip) as eligible for next tick's enterFrame.
		// Must happen every tick AFTER the frame function returns, so that MCs created
		// by DoAction scripts get marked even when the pre-DoAction tagFlushPendingEnterFrame
		// already consumed the dispatch for this tick.
		actionMarkDynamicMCsEnterFrameEligible();

		// Flush deferred rollOver/rollOut events from Selection.setFocus() calls
		// that occurred during frame scripts. These fire asynchronously (after script
		// completes) but before input events are processed.
		actionFlushDeferredRollEvents(app_context);

		// Deliver queued input events for this tick (after frame scripts ran)
		if (g_events) {
			input_events_pump_tick(app_context);
		}

		// Per-tick button state re-evaluation (NO_GRAPHICS mode).
		// Catches _visible/_enabled changes from enterFrame/action scripts
		// that don't have an associated mouse event.
		// Skip when Tab virtual hover is active: Ruffle's update_mouse_state
		// uses skip_mouse_hover=true when hovered is Some and mouse didn't move,
		// so button states are NOT re-evaluated during frame ticks with virtual hover.
		if (!actionHasVirtualHover())
			ng_update_button_states(app_context);

		// Goto catch-up + deferred script processing.
		// An outer loop retries because deferred scripts (from ng_executeGotoCatchUp)
		// may trigger new gotos (via ng_executeGotoTagsOnly) that need catch-up.
		// Safety limit: prevent infinite goto catch-up within a single tick.
		// Tests like gotoFrame2Test can trigger GotoFrame2 inside a deferred
		// script which re-triggers catch-up, creating an infinite cycle.
		int goto_retry_limit = 16;
		for (;;)
		{
		if (--goto_retry_limit <= 0) break;
		// Phase 4 (TRANSFORMED_BY_SCRIPT_WRAP_BACK): treat the recompiler-emitted
		// natural backward wrap (`manual_next_frame=1; next_frame=0` at end of last
		// frame, with no script-initiated goto) as an implicit goto so the existing
		// catch-up path runs. In Ruffle, run_frame_internal converts the past-end
		// wrap into `run_goto(1, is_implicit=true)` (NextFrame::First branch in
		// movie_clip.rs:1303), which aggregates final-frame placements via
		// survives_rewind and applies them through apply_place_object — preserving
		// matrix-by-script entries and removing entries with no matching final
		// placement. Routing natural-wrap through goto-style catch-up gives us the
		// same semantics: tagPlaceObject2's catch_up_backward survives branch is
		// gated on transformed_by_script (Phase 3), and ng_display_cleanup_unplaced_after
		// removes stale entries (e.g. an MC placed only on the final frame when
		// frame 0 doesn't re-place it). Key test: place_and_remove_object_insane_test.
		// Only fire when current_frame is at the LAST timeline frame — this is
		// the recompiler-emitted end-of-movie wrap-back. If a script already
		// performed a goto earlier in the frame (e.g. dontremove's script_2
		// GotoFrame(1)), current_frame was reset to the goto target (1), not
		// the last frame (2). The recompiler emits its natural-wrap
		// unconditionally at end of last frame, but ng_executeGotoCatchUp has
		// already handled the transition; treating this as natural-wrap would
		// re-run funcs[target] inline, double-firing target frame's scripts.
		if (manual_next_frame && !goto_from_action && next_frame < current_frame
		    && current_frame + 1 == g_frame_count
		    && !g_force_quit)
		{
			// Only fire when there are display-list entries placed at frames
			// after the wrap target. The catch-up's inline funcs[target]
			// re-runs target frame's DoAction scripts, which double-fires
			// trace-only iterations like avm1/looping where the trace-per-
			// frame model expects exactly one trace per natural tick. Stale
			// entries are the load-bearing signal: we need the catch-up to
			// remove unsurvivors (mc_green at depth 4 in
			// place_and_remove_object_insane_test) and apply
			// transformed_by_script preservation. Tests without such entries
			// don't need the catch-up replay.
			//
			// Also skip when FSCommand:quit was issued during this frame —
			// the SWF asked to terminate, so re-running funcs[target] inline
			// just duplicates the most recent script's trace
			// (shumway/fuzz/81004241… queues FSCommand:quit on its last
			// frame which then emits the natural-wrap; the outer loop's
			// g_force_quit check terminates the next tick, so the inline
			// catch-up's funcs[target] only adds spurious trace output).
			extern DisplayObject* display_list;
			extern size_t max_depth;
			int has_stale = 0;
			for (size_t d = 1; d <= max_depth && d < 16384; d++) {
				if (display_list[d].char_id != 0
				    && display_list[d].placed_at_frame > next_frame) {
					has_stale = 1;
					break;
				}
			}
			if (has_stale) {
				goto_from_action = 1;
				g_natural_wrap_cleanup_pending = 1;
			}
		}
		// Goto catch-up: when an action (GotoFrame, GoToLabel, etc.) triggered
		// a goto, process intermediate frame tags inline to match Flash's behavior.
		// Flash processes PlaceObject/RemoveObject for intermediate frames within
		// the same frame advance, but skips DoAction tags (main timeline scripts).
		// In our model, catch_up_mode=1 causes generated frame functions to skip
		// their script_N() calls while still executing tag functions.
		while (goto_from_action && manual_next_frame)
		{
			size_t original_frame = current_frame;
			size_t target = next_frame;
			manual_next_frame = 0;
			goto_from_action = 0;

			// Remove display list entries placed after the target frame
			ng_display_clear_after(app_context, target);

			catch_up_mode = 1;
			if (target <= original_frame)
			{
				// Backward goto: replay tags from frame 0 to target.
				// Intermediate frames (0..target-1) suppress scripts.
				// Target frame runs normally (scripts included).
				// Backward protection stays on through target frame so
				// RemoveObject2 doesn't remove entries placed during rebuild.
#ifdef NO_GRAPHICS
				// Clean up dynamic MCs and reset swapped depths before replay
				{
					extern void actionRewindCleanup(SWFAppContext* app_context);
					actionRewindCleanup(app_context);
				}
#endif
				catch_up_backward = 1;
				catch_up_target = target;
				for (size_t f = 0; f < target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
				catch_up_mode = 0;
				// Execute target frame with scripts enabled but
				// backward protection still active
				if (target < g_frame_count)
				{
					current_frame = target;
					if (funcs[target]) funcs[target](app_context);
				}
				catch_up_backward = 0;
				{
					extern void ng_display_cleanup_unplaced_after(SWFAppContext*, size_t);
					ng_display_cleanup_unplaced_after(app_context, target);
				}
			}
			else
			{
				// Forward goto: process intermediate frames (current+1..target-1)
				// with scripts suppressed, then target frame normally.
				for (size_t f = original_frame + 1; f < target && f < g_frame_count; f++)
				{
					current_frame = f;
					if (funcs[f]) funcs[f](app_context);
				}
				catch_up_mode = 0;
				// Execute target frame with scripts enabled
				if (target < g_frame_count)
				{
					current_frame = target;
					if (funcs[target]) funcs[target](app_context);
				}
			}
			current_frame = target;

			g_deferred_root_goto = 0;

			// After catch-up, the goto's advance is consumed; fall through
			// to the normal advance logic below.
		}

		// Phase G (GOTO_FIFO_UNIFICATION_INCREMENTAL): the outer 3-phase deferred
		// goto drain that used to live here was retired. Phase E moved the
		// target-frame script call inline into ng_executeGotoCatchUp wrapped in
		// drain-suppress, and Phase F added the surrounding
		// ng_run_deferred_sprite_init_before/_on_or_after calls there. Sprite
		// scripts and the target's root script all land in AQ_KIND_SCRIPT and
		// drain in FIFO order via the recompiler-emitted SHOW_FRAME drain. The
		// per-tick retry below still reruns catch-up if a deferred script
		// triggered ng_executeGotoTagsOnly.

		// If deferred scripts triggered a new goto (via ng_executeGotoTagsOnly),
		// retry the catch-up loop to process it within this tick.
		if (goto_from_action && manual_next_frame) continue;
		break;
		} // end outer for(;;) retry loop

		// Process deferred failed loadMovie state (apply between frame scripts and timers)
		{
			extern void actionProcessDeferredFailedLoads(void);
			actionProcessDeferredFailedLoads();
		}

		// Fire deferred direct loadMovie inits (non-MCL loads queued during frame scripts)
		{
			int dl_guard = 0;
			while (g_pending_direct_load_count > 0 && dl_guard++ < 32)
				actionFirePendingDirectLoads(app_context);
		}

		// Advance multi-frame _levelN loads by one frame this tick. Levels are
		// not in display_list, so advance_sprite_frames doesn't reach them — but
		// their timelines still need to play after the initial loadMovieNum.
		{
			extern void actionAdvancePlayingLevels(SWFAppContext*);
			actionAdvancePlayingLevels(app_context);
		}

		// Flush pending onLoads queued during frame scripts (before timers)
		actionFlushPendingOnLoads(app_context);

		// Process timers after frame actions + deferred scripts
		{
			double frame_duration_ms = (app_context->fps > 0) ? (1000.0 / app_context->fps) : 83.33;
			processTimers(app_context, frame_duration_ms);
			// Fire deferred LoadVars.load() onData callbacks.
			{
				extern void processLoadVarsLoads(SWFAppContext*);
				processLoadVarsLoads(app_context);
			}
			// Process sound playback (fire onSoundComplete callbacks)
			{
				extern void processSoundPlayback(SWFAppContext*, double);
				processSoundPlayback(app_context, frame_duration_ms);
			}
			// Process NetStream playback (fire onStatus events)
			{
				extern void processNetStreams(SWFAppContext*, double);
				processNetStreams(app_context, frame_duration_ms);
			}
			// Process LocalConnection messages (end-of-frame delivery)
			{
				extern void processLocalConnectionMessages(SWFAppContext*);
				processLocalConnectionMessages(app_context);
			}
		}

		// Flush pending onLoad dispatches for dynamically-attached MCs
		// (queued during attachMovie, fires after current script/timer completes)
		actionFlushPendingOnLoads(app_context);

		// Dispatch any MCL loads queued by timer callbacks or chained from
		// onLoadInit handlers. Drains _this_tick only — loads in _next_tick
		// (deferred when the loader has more frames coming) wait for the
		// next tick's promote step. Loop because each dispatch may queue
		// more loads via chained loadClip from onLoadInit.
		{
			int mcl_guard = 0;
			while (g_pending_mcl_load_count_this_tick > 0 && mcl_guard++ < 32)
				actionFirePendingLoadInits(app_context);
		}

		// Last-tick MCL drain: if this is the final iteration (tick_count
		// has reached max_ticks, so the next while-check will exit),
		// promote any pending _next_tick loads and drain them before
		// exiting. Without this, a deferral that pushes events past the
		// last allowed tick would silently drop them. Mirrors Flash:
		// the player keeps ticking past the last frame to drain pending events.
		if (tick_count >= max_ticks && g_pending_mcl_load_count_next_tick > 0) {
			actionPromotePendingMCLLoads(app_context);
			int mcl_guard = 0;
			while (g_pending_mcl_load_count_this_tick > 0 && mcl_guard++ < 32)
				actionFirePendingLoadInits(app_context);
		}

		// A goto issued from a timer/event callback (setInterval, etc.) queues the
		// target frame's DoAction via ng_executeGotoCatchUp's drain-suppressed
		// funcs[target] call. Unlike a goto from a frame script — where the
		// caller's SHOW_FRAME drain runs the target script this tick — a
		// timer-callback goto leaves it orphaned in the queue. A gotoAndPlay's
		// is_playing=1 then survives into the natural advance below before the
		// target frame's own stop() runs, over-advancing one frame. Drain any
		// orphaned ONLOAD/SCRIPT entries now so the target frame's actions
		// (e.g. stop()) settle is_playing before the advance. g_aq_count is
		// normally 0 here (frame funcs drain at SHOW_FRAME), so this is a no-op
		// on the common path. Key test: from_gnash/misc-swfc.all/gotoFrameFromInterval2.
		{
			extern size_t actionActionQueuePending(void);
			if (actionActionQueuePending() > 0)
				actionDrainAllInPriorityOrder(app_context);
		}

		// After-tick hook (for test harness / external interface injection)
		{
			typedef void (*AfterTickHandler)(SWFAppContext*, int);
			extern AfterTickHandler g_after_tick_handler;
			if (g_after_tick_handler)
				g_after_tick_handler(app_context, (int)tick_count);
		}

		// Phase B (GOTO_FIFO_UNIFICATION_INCREMENTAL): drop any deferred
		// sprite-script entries accumulated during this tick. Phase B is
		// infrastructure only — nothing dispatches the queue. Clearing
		// here prevents stale entries from leaking across ticks. Phase C
		// will replace this no-op clear with FIFO dispatch when
		// g_unify_sprite_drain is set.
		actionResetPendingSpriteScriptQueue();

		// Advance to next frame
		// IMPORTANT: Process manual_next_frame BEFORE checking is_playing
		// This ensures that gotoFrame/gotoAndStop commands execute the target frame
		// even when they stop playback
		if (current_frame >= g_frame_count)
		{
			// Past the end of the frame list — only continue if events, timers, or handlers remain
			if (hasActiveTimers()) continue;
			if (g_events && g_event_pos < g_event_count) continue;
			if (actionHasEnterFrameHandlers() || hasPlayingSprites() || hasClipEnterFrameHandlers()) continue;
			if (g_pending_mcl_load_count > 0) continue;
			if (g_pending_direct_load_count > 0) continue;
			{ extern int hasPlayingLevels(void); if (hasPlayingLevels()) continue; }
			{ extern int hasPlayingSounds(void); if (hasPlayingSounds()) continue; }
			{ extern int hasActiveNetStreams(void); if (hasActiveNetStreams()) continue; }
			break;
		}
		else if (manual_next_frame)
		{
#ifdef NO_GRAPHICS
			// Natural backward wrap (e.g. last frame loops back to frame 0):
			// invalidate cached MCs and clear display entries that were placed
			// at frames > target. Mirrors Ruffle's wrap-as-implicit-goto
			// behavior where the rewind cleans up stale later-frame state so
			// that names placed only at later frames don't bleed into the
			// next loop's frame 0. Goto-from-action cases go through
			// ng_executeGotoCatchUp, which handles its own cleanup; this
			// branch only runs for the recompiler-emitted natural wrap-back
			// at the end of the last frame (goto_from_action == 0).
			if (!goto_from_action && next_frame < current_frame)
			{
				extern void actionInvalidateCachedMovieClip(SWFAppContext*, const char*, int);
				for (size_t d = 1; d <= max_depth && d < 16384; d++)
				{
					if (display_list[d].char_id != 0 &&
					    display_list[d].placed_at_frame > next_frame &&
					    display_list[d].instance_name != NULL)
					{
						actionInvalidateCachedMovieClip(app_context,
						    display_list[d].instance_name, (int)d);
					}
				}
				ng_display_clear_after(app_context, next_frame);
				extern void ng_display_cleanup_unplaced_after(SWFAppContext*, size_t);
				ng_display_cleanup_unplaced_after(app_context, next_frame);
				// The upcoming re-run of funcs[next_frame] is a rewind (loop
				// wrap). Arm the flag so tagPlaceObject2 modifies — rather than
				// refuses — a Place that lands on a depth a script swapDepths'd
				// a different character into. Converted to g_loopback_replay
				// right before funcs runs, cleared right after.
				g_loopback_replay_armed = 1;
			}
#endif
			current_frame = next_frame;
			manual_next_frame = 0;
			root_movieclip.currentframe = (int)current_frame + 1;  // Keep 1-indexed _currentframe in sync
		}
		else if (is_playing)
		{
			// Only advance naturally if we're still playing
			current_frame++;
			// Hold _currentframe at the last frame once the playhead runs
			// past the timeline (single-frame / non-looping root with no
			// stop() that keeps ticking for child sprites). The funcs gate
			// (current_frame < g_frame_count, above) already stops frame
			// scripts re-running; without this clamp _currentframe would
			// drift past the timeline. Multi-frame looping movies wrap via
			// manual_next_frame (recompiler swf.cpp:733) so current_frame
			// stays in range and this is a no-op. Mirrors swf.c. Key game:
			// Shopping Cart Hero (1-frame root, no stop()).
			size_t _disp_frame = (g_frame_count > 0 && current_frame >= g_frame_count)
			                   ? g_frame_count - 1 : current_frame;
			root_movieclip.currentframe = (int)_disp_frame + 1;  // Keep 1-indexed _currentframe in sync
		}
		else
		{
			// Root stopped — but child sprites may still be playing
			if (hasPlayingSprites())
			{
				// Stay at current_frame, sprites advance via advance_sprite_frames above
				continue;
			}
			// Root stopped but timers are active — keep ticking
			if (hasActiveTimers()) continue;
			// Root stopped but onEnterFrame handlers still registered — keep ticking
			if (actionHasEnterFrameHandlers() || hasClipEnterFrameHandlers()) continue;
			// Truly stopped — but continue if events remain
			if (g_events && g_event_pos < g_event_count) continue;
			// Pending MCL/loadMovie loads must drain before we exit, so
			// onLoadStart/onLoadComplete/onLoadInit listeners get a chance to
			// run (key test: avm1/string_paths_eval2 — root calls stop() at
			// end of frame 0 but pending loadClip in _next_tick still needs
			// promote+drain on tick 2).
			if (g_pending_mcl_load_count > 0) continue;
			if (g_pending_direct_load_count > 0) continue;
			break;
		}
	}

frame_loop_exit:
	// Deactivate timeout longjmp (jmp_buf is stack-local, must not be used after return)
	actionSetTimeoutJmp(NULL);

	printf("\n=== SWF Execution Completed ===\n");

	// Env-gated (SWF_MEM_REPORT) leak-tracking summary; must precede
	// heap_shutdown, which unmaps the pool the MC registry lives in.
	swfMemReportAtExitIfEnabled();

	// Cleanup (dictionary/display_list freed by heap_shutdown; stack uses system malloc)
	heap_shutdown(app_context);
	freeMap();
	free(app_context->stack);
}

#endif // NO_GRAPHICS
