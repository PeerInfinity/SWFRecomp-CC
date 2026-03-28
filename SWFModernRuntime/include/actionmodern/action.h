#pragma once

#include <swf.h>
#include <variables.h>
#include <stackvalue.h>
#include <setjmp.h>

// SWF version — set at startup from constants.h, controls runtime behavior
extern int g_swf_version;
// Recursion depth limit (set by tagScriptLimits, default 256)
extern u32 g_max_call_depth;
// Execution halt flag — set when recursion limit is hit, prevents all further script execution
extern u8 g_execution_halted;

// Forward declarations
typedef struct MovieClip MovieClip;

// MovieClip structure for Flash movie clip properties
struct MovieClip {
	float x, y;
	float xscale, yscale;
	float rotation;
	float alpha;
	float width, height;
	int visible;
	int currentframe;
	int totalframes;
	int framesloaded;
	char name[256];
	char target[256];
	char original_target[256]; // Target path from creation time (never updated by _name changes, used for removed MC toString)
	char droptarget[256];
	char url[512];
	// SWF 4+ properties
	float highquality;     // Property 16: _highquality (0, 1, or 2)
	float focusrect;       // Property 17: _focusrect (0 or 1)
	float soundbuftime;    // Property 18: _soundbuftime (in seconds)
	char quality[16];      // Property 19: _quality ("LOW", "MEDIUM", "HIGH", "BEST")
	float xmouse;
	float ymouse;
	MovieClip* parent;     // Parent MovieClip (_root has NULL parent)
	void* dynamic_props;   // ASObject* for user-defined properties (lazily allocated)
	u8 lockroot;           // _lockroot property (0 = false, 1 = true)
	u8 blend_mode;         // blendMode as integer (0=default→"normal", 1="normal", 2="layer", ...14="hardlight")
	u8 is_button_mc;       // 1 if this MC represents a SWF button (affects _parent resolution in SWF5)
	int depth;             // ActionScript display depth (-16384 for _root, SWF_depth-16384 for timeline clips, AS-space for dynamic clips)
	u8 depth_swapped;      // 1 if depth was changed by swapDepths (prevents display list overwrite in actionGetMember)
	u8 unloaded;           // 1 if unloadMovie was called on this MC (frame/bytes properties return 0)
	u8 load_failed;        // 1 if loadMovie was called but the URL was not found (_framesloaded/-1, getBytesTotal/-1, getSWFVersion/-1)
	u8 pending_removal;    // 1 if MC was removed from display list but persists for one more frame (depth transformed)
	u8 avm1_removed;       // 1 if MC was removed from display list (halts script execution)
	u32 byte_size;         // getBytesLoaded/getBytesTotal value (0 = dynamic/attached clip)
	u16 swf_version;       // SWF version of the movie loaded into this MC (for getSWFVersion)
	void* display_obj;     // Pointer to this MC's DisplayObject entry (for direct child lookup without global display_list)
	u32 last_transform_id; // Last synced transform_id (for _x/_y from display list)
	u8 as_set_flags;       // Bitmask: bit 0 = _x set by AS, bit 1 = _y set by AS
	int ng_textfield_idx;  // index into ng_textfields, or -1 if not a textfield
	// Drawing API bounds tracking (updated by moveTo/lineTo calls)
	float draw_xmin, draw_xmax, draw_ymin, draw_ymax;
	int draw_has_bounds;   // 1 if any moveTo/lineTo was called
	void* drawing_state;   // DrawingState* (lazily allocated, used by Drawing API)
	void* mask_mc;         // MovieClip* that masks this MC (set by setMask), NULL if none
	u8 is_mask;            // 1 if this MC is used as a mask for another MC (skip normal rendering)
	// AS2 event dispatch state
	u8 mc_mouse_inside;    // 1 if mouse is currently inside this MC's hit area
	u8 mc_as_pressed;      // 1 if button was pressed while mouse was inside this MC
	u8 mc_enterframe_eligible; // 0 on creation tick, set to 1 on next tick so onEnterFrame doesn't fire on creation frame
	u8 movie_id;               // Which SWF movie defined this MC (0=main, 1+=child). Used for per-movie export table isolation in attachMovie.
	// Color transform for dynamic MCs (createEmptyMovieClip, etc.) not in the display list.
	// Default: multipliers=100, offsets=0. Used by Color.getTransform/setTransform when
	// ng_getColorTransform fails (no display_list entry).
	float cx_ra, cx_ga, cx_ba, cx_aa;
	float cx_rb, cx_gb, cx_bb, cx_ab;
	// Attached BitmapData (from attachBitmap) — raw pixel pointer for GPU rendering
	uint32_t* attached_bitmap_pixels;   // ARGB premultiplied pixel data (NULL if none)
	u16 attached_bitmap_width;
	u16 attached_bitmap_height;
};

// Global root MovieClip
extern MovieClip root_movieclip;

// Current execution context (MovieClip scope for variable resolution)
extern MovieClip* g_current_context;

// Event 'this' MC — set by onEnterFrame/onLoad dispatch before calling
// DefineFunction2 with this_obj=NULL. The generated code's 'preload this'
// path consumes this (sets it to NULL after reading).
extern MovieClip* g_event_this_mc;

// Override 'this' — passes arbitrary ActionVar as 'this' to DefineFunction2.
// Used for primitive thisArg in call/apply and undefined this in empty-method-name calls.
#ifndef DYNAMIC_GUEST
extern ActionVar g_override_this;
extern int g_override_this_set;
#endif

// Check if the current execution context's base clip has been removed.
// Used by generated code to halt script execution after function calls.
int actionBaseClipRemoved(void);

// Set the current execution context
void actionSetCurrentContext(MovieClip* mc);
// Set/get the base clip (the clip whose timeline code is executing).
// actionSetTarget("") resets to base_clip, not root.
void actionSetBaseClip(MovieClip* mc);
MovieClip* actionGetBaseClip(void);
// Create or find a cached MovieClip by instance name
MovieClip* actionFindOrCreateMovieClip(SWFAppContext* app_context, const char* instance_name, MovieClip* parent);
// Initialize default textfield properties on a clone of a dynamic textfield
void actionInitDynTextFieldClone(SWFAppContext* app_context, MovieClip* mc);
// Invalidate cached MovieClip when removed from display list (swf_depth for disambiguation)
void actionInvalidateCachedMovieClip(SWFAppContext* app_context, const char* name, int swf_depth);
// Mark MC for deferred removal: transform depth and set pending_removal flag
void actionMarkMCPendingRemoval(SWFAppContext* app_context, const char* name, int swf_depth);
// Finalize pending removals: invalidate MCs marked for removal in a previous frame
void actionFinalizePendingRemovals(SWFAppContext* app_context);
// Check if a named MC at given depth has an AS-level onUnload property
int actionMCHasOnUnloadProperty(const char* name, int swf_depth);
// Fire the AS-set onUnload handler on a MovieClip being removed (call BEFORE Invalidate)
void actionFireOnUnload(SWFAppContext* app_context, const char* instance_name, int swf_depth);
// Fire all pending deferred onUnload handlers (queued by removeMovieClip); call from tagShowFrame
void actionFirePendingUnloads(SWFAppContext* app_context);
// Fire all pending deferred onLoadInit handlers (queued by MCL loadClip); call from tagShowFrame
void actionFirePendingLoadInits(SWFAppContext* app_context);
// ImportAssets: load an imported SWF's init function in the current context
void actionImportAssets(SWFAppContext* app_context, const char* url);
// Query button MC state for the button state machine in tag.c
// Returns mc->visible for the named button MC (1=visible, 0=hidden; defaults to 1 if MC not found)
int actionGetMCVisible(SWFAppContext* app_context, const char* instance_name);
// Returns the 'enabled' property for the named button MC (1=enabled, 0=disabled; defaults to 1)
int actionGetMCEnabled(SWFAppContext* app_context, const char* instance_name);

// VAL macro must be defined before other macros that use it
#define VAL(type, x) *((type*) x)

// Stack macros - use STACK, SP, OLDSP from swf.h (app_context->stack, etc.)
#define PUSH(t, v) \
	OLDSP = SP; \
	SP -= 4 + 4 + 8 + 8; \
	SP &= ~7; \
	STACK[SP] = t; \
	VAL(u32, &STACK[SP + 4]) = OLDSP; \
	VAL(u64, &STACK[SP + 16]) = v;

// Push string with ID: accepts char* from generated code, converts to UTF-16 with caching
void push_str_id_fn(SWFAppContext* app_context, const char* str, u32 byte_len, u32 id);
#define PUSH_STR_ID(v, n, id) push_str_id_fn(app_context, (const char*)(v), (u32)(n), (u32)(id))

// Push string without ID (for dynamic strings from runtime code, converts char* to UTF-16)
#define PUSH_STR(v, n) push_str_id_fn(app_context, (const char*)(v), (u32)(n), 0)

// Push pre-existing UTF-16 string directly (no conversion)
#define PUSH_U16(v, n) \
	OLDSP = SP; \
	SP -= 4 + 4 + 8 + 8; \
	SP &= ~7; \
	STACK[SP] = ACTION_STACK_VALUE_STRING; \
	VAL(u32, &STACK[SP + 4]) = OLDSP; \
	VAL(u32, &STACK[SP + 8]) = (u32)(n); \
	VAL(u32, &STACK[SP + 12]) = 0; \
	VAL(u64, &STACK[SP + 16]) = (u64)(v);

// Push pre-existing UTF-16 string with string ID
#define PUSH_U16_ID(v, n, id) \
	OLDSP = SP; \
	SP -= 4 + 4 + 8 + 8; \
	SP &= ~7; \
	STACK[SP] = ACTION_STACK_VALUE_STRING; \
	VAL(u32, &STACK[SP + 4]) = OLDSP; \
	VAL(u32, &STACK[SP + 8]) = (u32)(n); \
	VAL(u32, &STACK[SP + 12]) = (u32)(id); \
	VAL(u64, &STACK[SP + 16]) = (u64)(v);

#define PUSH_VAR(p) pushVar(app_context, p);

#define POP() \
	if (SP < INITIAL_STACK_SIZE) SP = VAL(u32, &STACK[SP + 4]);

#define POP_2() \
	POP(); \
	POP();

#define STACK_TOP_TYPE STACK[SP]
#define STACK_TOP_N VAL(u32, &STACK[SP + 8])
#define STACK_TOP_ID VAL(u32, &STACK[SP + 12])
#define STACK_TOP_VALUE VAL(u64, &STACK[SP + 16])

#define SP_SECOND_TOP VAL(u32, &STACK[SP + 4])
#define STACK_SECOND_TOP_TYPE STACK[SP_SECOND_TOP]
#define STACK_SECOND_TOP_N VAL(u32, &STACK[SP_SECOND_TOP + 8])
#define STACK_SECOND_TOP_ID VAL(u32, &STACK[SP_SECOND_TOP + 12])
#define STACK_SECOND_TOP_VALUE VAL(u64, &STACK[SP_SECOND_TOP + 16])

#define INITIAL_STACK_SIZE 8388608  // 8 MB
#define INITIAL_SP INITIAL_STACK_SIZE

extern ActionVar* temp_val;

void initTime(SWFAppContext* app_context);

void pushVar(SWFAppContext* app_context, ActionVar* p);
void popVar(SWFAppContext* app_context, ActionVar* var);
void peekVar(SWFAppContext* app_context, ActionVar* var);
void peekSecondVar(SWFAppContext* app_context, ActionVar* var);
void setVariableByName(const char* var_name, ActionVar* value);

void actionPrevFrame(SWFAppContext* app_context);
void actionToggleQuality(SWFAppContext* app_context);

void actionAdd(SWFAppContext* app_context);
void actionAdd2(SWFAppContext* app_context, char* str_buffer);
void actionSubtract(SWFAppContext* app_context);
void actionMultiply(SWFAppContext* app_context);
void actionDivide(SWFAppContext* app_context);
void actionModulo(SWFAppContext* app_context);
void actionEquals(SWFAppContext* app_context);
void actionLess(SWFAppContext* app_context);
void actionLess2(SWFAppContext* app_context);
void actionEquals2(SWFAppContext* app_context);
void actionAnd(SWFAppContext* app_context);
void actionOr(SWFAppContext* app_context);
void actionNot(SWFAppContext* app_context);
void actionToInteger(SWFAppContext* app_context);
void actionToNumber(SWFAppContext* app_context);
void actionToString(SWFAppContext* app_context, char* str_buffer);
void actionStackSwap(SWFAppContext* app_context);
void actionDuplicate(SWFAppContext* app_context);
void actionGetMember(SWFAppContext* app_context);
void actionTargetPath(SWFAppContext* app_context, char* str_buffer);
void actionEnumerate(SWFAppContext* app_context, char* str_buffer);

// Movie control
void actionGoToLabel(SWFAppContext* app_context, const char* label);
void actionGotoFrame2(SWFAppContext* app_context, u8 play_flag, u16 scene_bias);

// Frame label lookup (returns -1 if not found, otherwise frame index)
int findFrameByLabel(const char* label);

void actionStringEquals(SWFAppContext* app_context, char* a_str, char* b_str);
void actionStringLength(SWFAppContext* app_context, char* v_str);
void actionStringExtract(SWFAppContext* app_context, char* str_buffer);
void actionMbStringLength(SWFAppContext* app_context, char* v_str);
void actionMbStringExtract(SWFAppContext* app_context, char* str_buffer);
void actionStringAdd(SWFAppContext* app_context, char* a_str, char* b_str);
void actionStringLess(SWFAppContext* app_context);
void actionImplementsOp(SWFAppContext* app_context);
void actionCharToAscii(SWFAppContext* app_context);

void actionGetVariable(SWFAppContext* app_context);
void actionSetVariable(SWFAppContext* app_context);
void actionSetTarget2(SWFAppContext* app_context);
void actionDefineLocal(SWFAppContext* app_context);
void actionDeclareLocal(SWFAppContext* app_context);
void actionGetProperty(SWFAppContext* app_context);
void actionSetProperty(SWFAppContext* app_context);
void actionCloneSprite(SWFAppContext* app_context);
void actionRemoveSprite(SWFAppContext* app_context);
void actionSetTarget(SWFAppContext* app_context, const char* target_name);

void actionNextFrame(SWFAppContext* app_context);
void actionPlay(SWFAppContext* app_context);
void actionStop(SWFAppContext* app_context);
void actionGotoFrame(SWFAppContext* app_context, u16 frame);
void actionTrace(SWFAppContext* app_context);
void actionStartDrag(SWFAppContext* app_context);
void actionEndDrag(SWFAppContext* app_context);
void actionStopSounds(SWFAppContext* app_context);
void actionGetURL(SWFAppContext* app_context, const char* url, const char* target);
void actionRandomNumber(SWFAppContext* app_context);
void actionAsciiToChar(SWFAppContext* app_context, char* str_buffer);
void actionMbCharToAscii(SWFAppContext* app_context, char* str_buffer);
void actionGetTime(SWFAppContext* app_context);
void actionMbAsciiToChar(SWFAppContext* app_context, char* str_buffer);
void actionTypeof(SWFAppContext* app_context, char* str_buffer);
void actionCastOp(SWFAppContext* app_context);
void actionCallFunction(SWFAppContext* app_context, char* str_buffer);
void actionReturn(SWFAppContext* app_context);
void actionInitArray(SWFAppContext* app_context);
void actionInitObject(SWFAppContext* app_context);
void actionIncrement(SWFAppContext* app_context);
void actionDecrement(SWFAppContext* app_context);
void actionInstanceOf(SWFAppContext* app_context);
void actionEnumerate2(SWFAppContext* app_context, char* str_buffer);
void actionDelete(SWFAppContext* app_context);
void actionDelete2(SWFAppContext* app_context, char* str_buffer);
void actionBitAnd(SWFAppContext* app_context);
void actionBitOr(SWFAppContext* app_context);
void actionBitXor(SWFAppContext* app_context);
void actionBitLShift(SWFAppContext* app_context);
void actionBitRShift(SWFAppContext* app_context);
void actionBitURShift(SWFAppContext* app_context);
void actionStrictEquals(SWFAppContext* app_context);
void actionGreater(SWFAppContext* app_context);
void actionStringGreater(SWFAppContext* app_context);
void actionExtends(SWFAppContext* app_context);
void actionStoreRegister(SWFAppContext* app_context, u8 register_num);
void actionPushRegister(SWFAppContext* app_context, u8 register_num);
void actionResetRegisters(void);

// Super context for OOP constructor/method chains
void actionGetCurrentSuperInfo(u64* out_this, u32* out_depth);

// Returns nearest lockroot ancestor MC (for preload_root in DefineFunction2)
MovieClip* actionGetLockRoot(void);

// Resolve a __proto__ ActionVar to an ASObject* (returned as void*).
// Handles OBJECT (direct cast) and SUPER (unwrap via proto chain walk).
void* resolveProtoVar(ActionVar* proto_var);

void actionDefineFunction(SWFAppContext* app_context, const char* name, void (*func)(SWFAppContext*), u32 param_count);
int actionCall(SWFAppContext* app_context);
void actionCallMethod(SWFAppContext* app_context, char* str_buffer);
void actionGetURL2(SWFAppContext* app_context, u8 send_vars_method, u8 load_target_flag, u8 load_variables_flag);
void actionSetMember(SWFAppContext* app_context);
void actionNewObject(SWFAppContext* app_context);
void actionNewMethod(SWFAppContext* app_context);

// Function pointer type for DefineFunction2
typedef ActionVar (*Function2Ptr)(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);

void actionDefineFunction2(SWFAppContext* app_context, const char* name, Function2Ptr func, u32 param_count, u8 register_count, u16 flags);
int actionWithStart(SWFAppContext* app_context);
void actionWithEnd(SWFAppContext* app_context);

// Exception handling (try-catch-finally)
void actionThrow(SWFAppContext* app_context);
void actionThrowPending(SWFAppContext* app_context);
void actionTryBegin(SWFAppContext* app_context);
jmp_buf* actionGetExceptionJmpBuf(SWFAppContext* app_context);
void actionCatchEnter(SWFAppContext* app_context);
void actionCatchToVariable(SWFAppContext* app_context, const char* var_name);
void actionCatchToRegister(SWFAppContext* app_context, u8 reg_num);
void actionCatchGetException(SWFAppContext* app_context, ActionVar* out);
void actionTryEnd(SWFAppContext* app_context);
void actionClearException(SWFAppContext* app_context);
bool actionExceptionPending(SWFAppContext* app_context);
void actionSetReturnPending(SWFAppContext* app_context, ActionVar* value);
bool actionReturnPending(SWFAppContext* app_context);
ActionVar actionGetPendingReturn(SWFAppContext* app_context);

// Macro for inline setjmp in generated code
#define ACTION_TRY_SETJMP(app_context) setjmp(*actionGetExceptionJmpBuf(app_context))

// Control flow
int evaluateCondition(SWFAppContext* app_context);
bool actionWaitForFrame(SWFAppContext* app_context, u16 frame);
bool actionWaitForFrame2(SWFAppContext* app_context);

// Forward declaration (defined in object.h)
typedef struct ASArray ASArray;

// Public helper called from recompiler-generated code when DefineFunction2 has
// the preload_arguments flag. Sets up callee/caller/__proto__ on the preloaded
// arguments array, using the global g_current_executing_func / g_prev_executing_func.
void swf_setup_arguments_props(SWFAppContext* app_context, ASArray* arr);

// Key event dispatch — called from swf_core.c after delivering EV_KEY_DOWN/EV_KEY_UP.
// Broadcasts onKeyDown/onKeyUp to all registered Key listeners.
void actionDispatchKeyDown(SWFAppContext* app_context);
void actionDispatchKeyUp(SWFAppContext* app_context);
// Mouse event dispatch — called from swf_core.c after delivering mouse events.
// Broadcasts onMouseDown/onMouseUp/onMouseMove to all registered Mouse listeners.
void actionDispatchMouseDown(SWFAppContext* app_context);
void actionDispatchMouseUp(SWFAppContext* app_context);
void actionDispatchMouseMove(SWFAppContext* app_context);
// Tab key focus advance — called on Tab key press (before Key.broadcastMessage).
// reversed=1 for Shift+Tab (go backward), 0 for Tab (go forward).
void actionAdvanceTabFocus(SWFAppContext* app_context, int reversed);
// Flush deferred rollOver/rollOut events queued by Selection.setFocus().
void actionFlushDeferredRollEvents(SWFAppContext* app_context);

// AS2 onEnterFrame dispatch — call after sprite initialization to fire mc.onEnterFrame
// for any MovieClip that has the property set. Iterates cache in reverse creation order
// (front-to-back: higher depth fires first) to match Flash's dispatch order.
void actionDispatchEnterFrameHandlers(SWFAppContext* app_context);
// Mark dynamic MCs (createEmptyMovieClip, no display_obj) as eligible for next tick's enterFrame.
// Called after frame processing to ensure MCs created mid-script get marked on the same tick.
void actionMarkDynamicMCsEnterFrameEligible(void);
// Dispatch root timeline onEnterFrame stored in var_map (DefineFunction/SetVariable path).
void actionDispatchRootVarMapEnterFrame(SWFAppContext* app_context);
// Dispatch _root.onLoad (fires once after first frame completes).
void actionDispatchRootOnLoad(SWFAppContext* app_context);
// Dispatch AS-level onLoad on a MovieClip (walks __proto__ chain for onLoad handler).
void actionDispatchMCOnLoad(SWFAppContext* app_context, MovieClip* mc);
// Queue a MovieClip for deferred onLoad dispatch.
void actionQueueMCOnLoad(MovieClip* mc);
// Flush pending onLoad dispatches for dynamically-attached MCs.
void actionFlushPendingOnLoads(SWFAppContext* app_context);
int actionHasPendingOnLoads(void);
// Check if any onEnterFrame handlers are registered.
int actionHasEnterFrameHandlers(void);

// Timer system (setInterval / setTimeout / clearInterval)
void processTimers(SWFAppContext* app_context, double frame_duration_ms);
int hasActiveTimers(void);

// ExternalInterface bridge
// External call handler: called when AS code invokes ExternalInterface.call(name, ...args)
typedef ActionVar (*ExternalCallHandler)(SWFAppContext*, const char* name, ActionVar* args, int arg_count);
extern ExternalCallHandler g_external_call_handler;

// After-tick handler: called at the end of each frame tick (for test harness injection)
typedef void (*AfterTickHandler)(SWFAppContext*, int tick_number);
extern AfterTickHandler g_after_tick_handler;

// Call a registered EI callback by name (for test harness / host environment)
ActionVar actionEI_callInternalInterface(SWFAppContext* app_context, const char* name, ActionVar* args, int arg_count);

// Convert an ActionVar STRING to a UTF-8 C string in buf. Returns bytes written.
int ei_actionvar_to_utf8(ActionVar* var, char* buf, int buf_size);

// Set __proto__ on an object to Object.prototype (for test harness use)
void ei_set_object_proto(SWFAppContext* app_context, void* obj);

// Drawing API data structures (used by beginFill/moveTo/lineTo/curveTo/endFill)
typedef struct {
	u8 type;           // 0=MOVE_TO, 1=LINE_TO, 2=CURVE_TO
	float x, y;        // endpoint (pixels)
	float cx, cy;      // control point (CURVE_TO only)
} DrawCmd;

typedef struct {
	float fill_r, fill_g, fill_b, fill_a;
	int has_fill;
	float line_width;   // pixels (0 = no stroke)
	float line_r, line_g, line_b, line_a;
	int has_line;
	// Gradient fill data (mutually exclusive with solid fill)
	int has_gradient;
	u8 gradient_type;      // 0x10=linear, 0x12=radial, 0x13=focal_radial
	u8 spread_mode;        // 0=pad, 1=reflect, 2=repeat
	u8 interpolation;      // 0=RGB, 1=linearRGB
	float focal_ratio;     // -1.0 to 1.0 for focal radial
	u8 gradient_ramp[256 * 4];    // pre-generated 256 RGBA8 entries
	float gradient_matrix[16];    // 4x4 column-major matrix (gradient space → stage twips)
	// Gradient line style data
	int has_line_gradient;
	u8 line_gradient_type;
	u8 line_spread_mode;
	u8 line_interpolation;
	float line_focal_ratio;
	u8 line_gradient_ramp[256 * 4];
	float line_gradient_matrix[16];
	// Tessellated output (filled after endFill)
	float* fill_verts;     // x,y pairs in twips (triangle vertices)
	u32 fill_vert_count;   // number of vertices (multiple of 3)
	float* line_verts;     // x,y pairs in twips (line quad triangles)
	u32 line_vert_count;
} DrawPath;

typedef struct {
	DrawPath* paths;
	u32 path_count;
	u32 path_capacity;
	// Current pen position
	float pen_x, pen_y;
	int pen_set;
	// Current fill style (set by beginFill or beginGradientFill)
	float fill_r, fill_g, fill_b, fill_a;
	int has_fill;
	// Gradient fill state (set by beginGradientFill)
	int has_gradient;
	u8 gradient_type;
	u8 gradient_spread;
	u8 gradient_interp;
	float gradient_focal;
	u8 gradient_ramp[256 * 4];
	float gradient_matrix[16];
	// Current line style (set by lineStyle)
	float line_w;
	float line_r, line_g, line_b, line_a;
	int has_line;
	// Line gradient state (set by lineGradientStyle)
	int has_line_gradient;
	u8 line_gradient_type;
	u8 line_gradient_spread;
	u8 line_gradient_interp;
	float line_gradient_focal;
	u8 line_gradient_ramp[256 * 4];
	float line_gradient_matrix[16];
	// Active path commands (between beginFill and endFill)
	DrawCmd* cmds;
	u32 cmd_count;
	u32 cmd_capacity;
} DrawingState;

// Drawing render info (used by tag.c in graphics mode)
typedef struct {
	const float* fill_verts;  // twips, triangle vertices (x,y pairs)
	u32 fill_count;           // vertex count
	float fill_r, fill_g, fill_b, fill_a;
	int has_gradient;
	u8 gradient_type;         // 0x10, 0x12, 0x13
	u8 spread_mode;
	float focal_ratio;
	const u8* gradient_ramp;  // 256*4 RGBA8 entries
	const float* gradient_matrix; // 4x4 column-major
	const float* line_verts;
	u32 line_count;
	float line_r, line_g, line_b, line_a;
	int has_line_gradient;
	u8 line_gradient_type;
	u8 line_spread_mode;
	float line_focal_ratio;
	const u8* line_gradient_ramp;
	const float* line_gradient_matrix;
	u32 transform_id;         // MC's transform slot
	u32 cxform_id;            // MC's cxform slot
} DrawingRenderInfo;

typedef void (*DrawingRenderCallback)(const DrawingRenderInfo* info, void* user_data);
int actionIterateDrawings(DrawingRenderCallback cb, void* user_data);

// Masked MC iteration: callback receives (masked_mc_paths, mask_mc_paths) pairs
typedef struct {
	int path_count;
	const DrawingRenderInfo* paths;   // array of path_count entries
} DrawingMCInfo;

typedef void (*DrawingMaskedCallback)(const DrawingMCInfo* masked, const DrawingMCInfo* mask, void* user_data);
int actionIterateMaskedDrawings(DrawingMaskedCallback cb, void* user_data);

// Get Drawing API paths for a specific MovieClip (by instance name).
// Returns the number of paths filled into out[]. Used by tag.c for sprite clip masks.
int actionGetMCDrawingPathsByName(const char* instance_name, DrawingRenderInfo* out, int max_out);

// Attached bitmap iteration: callback for rendering BitmapData attached to MCs
typedef struct AttachedBitmapInfo {
	const uint32_t* pixels;   // ARGB premultiplied pixel data
	u32 width;
	u32 height;
	float x_twips;            // position in stage coordinates (twips)
	float y_twips;
} AttachedBitmapInfo;

typedef void (*AttachedBitmapCallback)(const AttachedBitmapInfo* info, void* user_data);
int actionIterateAttachedBitmaps(AttachedBitmapCallback cb, void* user_data);

// Text field rendering info (used by tag.c in graphics mode)
typedef struct TextFieldRenderInfo {
	int has_background;
	u32 background_color;  // 24-bit RGB
	int has_border;
	u32 border_color;      // 24-bit RGB
	float x, y, w, h;     // position and size in pixels
} TextFieldRenderInfo;

// Get text field count and info for rendering. Returns count of text fields.
// For each text field, calls callback with the render info and user data.
typedef void (*TextFieldRenderCallback)(const TextFieldRenderInfo* info, void* user_data);
int actionIterateTextFields(TextFieldRenderCallback cb, void* user_data);

// Text field glyph rendering info (used by tag.c for headless glyph rendering)
typedef struct TextFieldGlyphInfo {
    u16 font_id;          // SWF font ID
    u16 font_height;      // font size in twips
    u32 text_color;       // 24-bit RGB
    float x, y, w, h;    // field bounds in pixels
    const char* text_utf8; // text content (UTF-8, null-terminated)
    size_t text_len;      // text length in bytes
} TextFieldGlyphInfo;

typedef void (*TextFieldGlyphCallback)(const TextFieldGlyphInfo* info, void* user_data);
int actionIterateTextFieldGlyphs(TextFieldGlyphCallback cb, void* user_data);

// Focus rect rendering info (used by tag.c in graphics mode)
typedef struct FocusRectInfo {
	float x, y, w, h;  // world-space bounds in twips
} FocusRectInfo;

// Get focus rect bounds if one should be drawn. Returns 1 if should draw, 0 if not.
int actionGetFocusRectInfo(FocusRectInfo* out);

#ifdef NO_GRAPHICS
// AS2 MC event dispatch — called from swf_core.c on mouse events.
// Iterates child_mc_cache, checks hit area, and calls onPress/onDragOver etc.
void actionDispatchMCPress(SWFAppContext* app_context);
void actionDispatchMCRelease(SWFAppContext* app_context);
void actionDispatchMCMouseMove(SWFAppContext* app_context);
// Global AS2 onMouseDown/onMouseUp/onMouseMove dispatch — fires on ALL sprite MCs.
void actionDispatchMCMouseDown(SWFAppContext* app_context);
void actionDispatchMCMouseUp(SWFAppContext* app_context);
void actionDispatchMCMouseMoveGlobal(SWFAppContext* app_context);
// Dispatch key events to focused MC — fires onKeyDown/onKeyUp on g_focused_mc.
// Enter/Space on focused MC with onPress → simulated press+release.
void actionDispatchKeyDownToFocused(SWFAppContext* app_context, int key_code);
void actionDispatchKeyPressToFocused(SWFAppContext* app_context, int key_code);
void actionDispatchKeyUpToFocused(SWFAppContext* app_context, int key_code);
// Focus highlight state: 0=INACTIVE, 1=ACTIVE_HIDDEN, 2=ACTIVE_VISIBLE.
// MC key handlers (onKeyDown/Up) require is_active (>=1).
// Enter/Space press simulation requires is_visible (==2).
void actionResetHighlightState(void);
// Version-aware highlight reset matching Ruffle's should_reset_highlight:
// event_type: 0=mouse_move, 1=left_down, 2=left_up, 3=right_down, 4=right_up
// Left down always resets. Others only reset for SWF < 9.
// Middle mouse never resets (not listed).
void actionResetHighlightForEvent(int event_type);
void actionUpdateHighlightState(void);
// Virtual hover tracking: Tab focus sets g_tab_hovered_mc; mouse events clear it.
// Per-frame ng_update_button_states should be skipped while virtual hover is active.
int actionHasVirtualHover(void);
void actionClearVirtualHover(void);
// End virtual hover: fire rollOut (DoAction + AS2) on Tab-hovered MC, then clear.
// Must be called BEFORE ng_update_button_states/actionDispatchMCMouseMove.
void actionEndVirtualHoverOnMouse(SWFAppContext* app_context);
// Mouse click focus acquisition — on mouse down, check if clicked MC is focusable.
void actionMouseClickFocus(SWFAppContext* app_context);
// Window focus lost — clear keyboard focus, firing onRollOut + onKillFocus.
void actionWindowFocusLost(SWFAppContext* app_context);

// Clipboard and text control operations — called from swf_core.c on input events.
void actionSetClipboardText(const char* text);
void actionTextControlPaste(SWFAppContext* app_context);
void actionTextControlCopy(SWFAppContext* app_context);
void actionTextControlCut(SWFAppContext* app_context);
void actionTextControlSelectAll(SWFAppContext* app_context);
void actionTextControlMoveRight(SWFAppContext* app_context);
void actionTextControlMoveLeft(SWFAppContext* app_context);
void actionTextControlEnter(SWFAppContext* app_context);
void actionTextControlBackspace(SWFAppContext* app_context);
void actionTextFieldInput(SWFAppContext* app_context, int codepoint);
#endif
