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
#ifdef NO_GRAPHICS
	u32 last_transform_id; // Last synced transform_id (for _x/_y from display list)
	u8 as_set_flags;       // Bitmask: bit 0 = _x set by AS, bit 1 = _y set by AS
	int ng_textfield_idx;  // index into ng_textfields, or -1 if not a textfield
	// Drawing API bounds tracking (updated by moveTo/lineTo calls)
	float draw_xmin, draw_xmax, draw_ymin, draw_ymax;
	int draw_has_bounds;   // 1 if any moveTo/lineTo was called
	// AS2 event dispatch state
	u8 mc_mouse_inside;    // 1 if mouse is currently inside this MC's hit area
	u8 mc_as_pressed;      // 1 if button was pressed while mouse was inside this MC
#endif
};

// Global root MovieClip
extern MovieClip root_movieclip;

// Current execution context (MovieClip scope for variable resolution)
extern MovieClip* g_current_context;

// Set the current execution context
void actionSetCurrentContext(MovieClip* mc);
// Create or find a cached MovieClip by instance name
MovieClip* actionFindOrCreateMovieClip(SWFAppContext* app_context, const char* instance_name, MovieClip* parent);
// Invalidate cached MovieClip when removed from display list
void actionInvalidateCachedMovieClip(SWFAppContext* app_context, const char* name);
// Fire the AS-set onUnload handler on a MovieClip being removed (call BEFORE Invalidate)
void actionFireOnUnload(SWFAppContext* app_context, const char* instance_name);
// Fire all pending deferred onUnload handlers (queued by removeMovieClip); call from tagShowFrame
void actionFirePendingUnloads(SWFAppContext* app_context);

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
void actionDefineFunction(SWFAppContext* app_context, const char* name, void (*func)(SWFAppContext*), u32 param_count);
void actionCall(SWFAppContext* app_context);
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
// Tab key focus advance — called on Tab key press (before Key.broadcastMessage).
// reversed=1 for Shift+Tab (go backward), 0 for Tab (go forward).
void actionAdvanceTabFocus(SWFAppContext* app_context, int reversed);

// AS2 onEnterFrame dispatch — call after sprite initialization to fire mc.onEnterFrame
// for any MovieClip that has the property set. Iterates cache in reverse creation order
// (front-to-back: higher depth fires first) to match Flash's dispatch order.
void actionDispatchEnterFrameHandlers(SWFAppContext* app_context);
// Dispatch root timeline onEnterFrame stored in var_map (DefineFunction/SetVariable path).
void actionDispatchRootVarMapEnterFrame(SWFAppContext* app_context);

#ifdef NO_GRAPHICS
// AS2 MC event dispatch — called from swf_core.c on mouse events.
// Iterates child_mc_cache, checks hit area, and calls onPress/onDragOver etc.
void actionDispatchMCPress(SWFAppContext* app_context);
void actionDispatchMCRelease(SWFAppContext* app_context);
void actionDispatchMCMouseMove(SWFAppContext* app_context);
#endif
