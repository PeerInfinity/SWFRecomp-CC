#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <time.h>

// constants.h is generated per-test and contains SWF_FRAME_COUNT
// It's optional - if not present, SWF_FRAME_COUNT defaults are used
#ifdef __has_include
#  if __has_include("constants.h")
#    include "constants.h"
#  endif
#endif

#include <recomp.h>
#include <utils.h>
#include <swf.h>
#include <tag.h>
#include <heap.h>
#include <actionmodern/object.h>

// Forward declarations for array helpers (defined later in file)
static int varToStringBuf(SWFAppContext* app_context, ActionVar* v, char* buf, int buf_size);
static double varToDoubleSimple(ActionVar* v);
static int callArrayMethod(SWFAppContext* app_context, ASArray* arr,
                           const char* method_name, u32 method_name_len,
                           ActionVar* args, u32 num_args);

u32 start_time;

// ==================================================================
// Scope Chain for WITH statement
// ==================================================================

#define MAX_SCOPE_DEPTH 32
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u32 scope_depth = 0;

// ==================================================================
// Recursion Depth Limit
// ==================================================================

u32 g_max_call_depth = 256;  // Default; overridden by tagScriptLimits()
u8 g_execution_halted = 0;   // Set when recursion limit is hit; halts all further script execution
static u32 g_call_depth = 0;

// ==================================================================
// Special Recursion Counter (for getter/setter/valueOf/toString)
// ==================================================================
// Flash/Ruffle tracks a separate "special" recursion counter for
// getter/setter invocations. Hard limit of 66 — non-fatal (returns
// undefined instead of halting execution).

#define MAX_SPECIAL_DEPTH 66
static u32 g_special_depth = 0;

// ==================================================================
// Virtual Property Table (addProperty getter/setter support)
// ==================================================================
// Stores getter/setter function pairs registered via addProperty().
// When a variable is accessed/set, this table is checked first.

// Forward declaration (ASFunction is defined below)
typedef struct ASFunction ASFunction;

typedef struct VirtualProperty {
	char name[256];
	u32 name_length;
	ASFunction* getter;   // NULL = no getter
	ASFunction* setter;   // NULL = no setter
} VirtualProperty;

#define MAX_VIRTUAL_PROPERTIES 64
static VirtualProperty virtual_properties[MAX_VIRTUAL_PROPERTIES];
static u32 virtual_property_count = 0;

static VirtualProperty* findVirtualProperty(const char* name, u32 name_length)
{
	for (u32 i = 0; i < virtual_property_count; i++)
	{
		if (virtual_properties[i].name_length == name_length &&
		    strncmp(virtual_properties[i].name, name, name_length) == 0)
		{
			return &virtual_properties[i];
		}
	}
	return NULL;
}

// ==================================================================
// Function Storage and Management
// ==================================================================

// Function pointer types
typedef void (*SimpleFunctionPtr)(SWFAppContext* app_context);
typedef ActionVar (*Function2Ptr)(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);

// Function object structure
typedef struct ASFunction {
	char name[256];           // Function name (can be empty for anonymous)
	u8 function_type;         // 1 = simple (DefineFunction), 2 = advanced (DefineFunction2)
	u32 param_count;          // Number of parameters

	// For DefineFunction (type 1)
	SimpleFunctionPtr simple_func;

	// For DefineFunction2 (type 2)
	Function2Ptr advanced_func;
	u8 register_count;
	u16 flags;

	// Prototype object (for constructor usage)
	ASObject* prototype_obj;  // Created lazily on first access
} ASFunction;

// Function registry
#define MAX_FUNCTIONS 256
static ASFunction* function_registry[MAX_FUNCTIONS];
static u32 function_count = 0;

// Global Object.prototype with built-in toString returning "[object Object]"
static ASObject* g_object_prototype = NULL;
static ASFunction g_object_toString_func;

static ActionVar builtin_object_toString(SWFAppContext* app_context)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 15;
	ret.data.numeric_value = (u64) "[object Object]";
	return ret;
}

// Get or create the global Object.prototype
static ASObject* getObjectPrototype(SWFAppContext* app_context)
{
	if (g_object_prototype == NULL)
	{
		g_object_prototype = allocObject(app_context, 4);
		retainObject(g_object_prototype);

		// Set up the built-in toString function
		memset(&g_object_toString_func, 0, sizeof(ASFunction));
		strncpy(g_object_toString_func.name, "toString", 255);
		g_object_toString_func.function_type = 1;
		g_object_toString_func.param_count = 0;
		g_object_toString_func.simple_func = (SimpleFunctionPtr) builtin_object_toString;

		// Register in function registry so lookupFunctionFromVar can find it
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_toString_func;

		// Set toString property on Object.prototype
		ActionVar ts_var;
		ts_var.type = ACTION_STACK_VALUE_FUNCTION;
		ts_var.str_size = 0;
		ts_var.data.numeric_value = (u64) &g_object_toString_func;
		setProperty(app_context, g_object_prototype, "toString", 8, &ts_var);
	}
	return g_object_prototype;
}

// Set __proto__ to Object.prototype on a user-created object
static void setObjectProto(SWFAppContext* app_context, ASObject* obj)
{
	ASObject* proto = getObjectPrototype(app_context);
	ActionVar proto_var;
	proto_var.type = ACTION_STACK_VALUE_OBJECT;
	proto_var.str_size = 0;
	proto_var.data.numeric_value = (u64) proto;
	setProperty(app_context, obj, "__proto__", 9, &proto_var);
}

// Helper to look up function by name
static ASFunction* lookupFunctionByName(const char* name, u32 name_len) {
	for (u32 i = 0; i < function_count; i++) {
		if (strlen(function_registry[i]->name) == name_len &&
		    strncmp(function_registry[i]->name, name, name_len) == 0) {
			return function_registry[i];
		}
	}
	return NULL;
}

// Helper to look up function from ActionVar
static ASFunction* lookupFunctionFromVar(ActionVar* var) {
	if (var->type != ACTION_STACK_VALUE_FUNCTION) {
		return NULL;
	}
	return (ASFunction*) var->data.numeric_value;
}

// Invoke a getter/setter function as a "special" invocation.
// Uses g_special_depth (not g_call_depth). Returns the function's return value.
// If special depth limit is reached, returns undefined without invoking.
static ActionVar invokeSpecialFunction(SWFAppContext* app_context, ASFunction* func, ActionVar* arg)
{
	ActionVar undef = {0};
	undef.type = ACTION_STACK_VALUE_UNDEFINED;

	if (func == NULL || g_execution_halted) return undef;

	// Check special recursion limit (non-fatal)
	// Increment before check — Ruffle increments first, then checks >= 66
	g_special_depth++;
	if (g_special_depth >= MAX_SPECIAL_DEPTH)
	{
		g_special_depth--;
		return undef;
	}

	ActionVar result;
	if (func->function_type == 2)
	{
		// DefineFunction2
		ActionVar* registers = NULL;
		if (func->register_count > 0)
		{
			registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
		}

		ASObject* local_scope = allocObject(app_context, 8);
		if (scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_chain[scope_depth++] = local_scope;
		}

		if (arg != NULL)
		{
			// Setter: pass one argument
			result = func->advanced_func(app_context, arg, 1, registers, NULL);
		}
		else
		{
			// Getter: no arguments
			result = func->advanced_func(app_context, NULL, 0, registers, NULL);
		}

		if (scope_depth > 0) scope_depth--;
		releaseObject(app_context, local_scope);
		if (registers != NULL) FREE(registers);
	}
	else
	{
		// Simple DefineFunction (type 1)
		// If setter, push the value arg onto the stack for the function to pop
		if (arg != NULL)
		{
			pushVar(app_context, arg);
		}
		result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
	}

	g_special_depth--;
	return result;
}

// Call just valueOf on an object. Returns the raw result (even if non-primitive).
// Sets *found=1 if valueOf was found and called, 0 otherwise.
// If the input is not an object, returns it unchanged with *found=0.
static ActionVar objectCallValueOf(SWFAppContext* app_context, ActionVar* obj_var, int* found)
{
	*found = 0;
	ASObject* obj = (ASObject*) obj_var->data.numeric_value;
	if (obj == NULL)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	ActionVar* valueOf_prop = getPropertyWithPrototype(obj, "valueOf", 7);
	if (valueOf_prop != NULL)
	{
		if (valueOf_prop->type == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* func = lookupFunctionFromVar(valueOf_prop);
			if (func != NULL)
			{
				*found = 1;
				ActionVar result;
				if (func->function_type == 2 && func->advanced_func != NULL)
				{
					ActionVar* regs = NULL;
					if (func->register_count > 0)
						regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
					result = func->advanced_func(app_context, NULL, 0, regs, obj);
					if (regs != NULL) FREE(regs);
				}
				else if (func->function_type == 1 && func->simple_func != NULL)
				{
					result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				}
				else
				{
					result.type = ACTION_STACK_VALUE_UNDEFINED;
					result.data.numeric_value = 0;
				}
				return result;
			}
		}
		// valueOf is a stored primitive value (including undefined/null from explicit assignment)
		else if (valueOf_prop->type == ACTION_STACK_VALUE_F32 ||
		         valueOf_prop->type == ACTION_STACK_VALUE_F64 ||
		         valueOf_prop->type == ACTION_STACK_VALUE_STRING ||
		         valueOf_prop->type == ACTION_STACK_VALUE_BOOLEAN ||
		         valueOf_prop->type == ACTION_STACK_VALUE_UNDEFINED ||
		         valueOf_prop->type == ACTION_STACK_VALUE_NULL)
		{
			*found = 1;
			return *valueOf_prop;
		}
	}
	return *obj_var;  // No valueOf found, return original
}

// Call just toString on an object. Returns the raw result.
// If found is non-NULL, sets *found = 1 if toString existed and was called, 0 otherwise.
static ActionVar objectCallToString(SWFAppContext* app_context, ActionVar* obj_var, int* found)
{
	if (found) *found = 0;
	ASObject* obj = (ASObject*) obj_var->data.numeric_value;
	if (obj == NULL)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	ActionVar* toString_prop = getPropertyWithPrototype(obj, "toString", 8);
	if (toString_prop != NULL && toString_prop->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* func = lookupFunctionFromVar(toString_prop);
		if (func != NULL)
		{
			if (found) *found = 1;
			ActionVar result;
			if (func->function_type == 2 && func->advanced_func != NULL)
			{
				ActionVar* regs = NULL;
				if (func->register_count > 0)
					regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
				result = func->advanced_func(app_context, NULL, 0, regs, obj);
				if (regs != NULL) FREE(regs);
			}
			else if (func->function_type == 1 && func->simple_func != NULL)
			{
				result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
			}
			else
			{
				result.type = ACTION_STACK_VALUE_UNDEFINED;
				result.data.numeric_value = 0;
			}
			return result;
		}
	}
	ActionVar undef = {0};
	undef.type = ACTION_STACK_VALUE_UNDEFINED;
	return undef;
}

// Convert an object to a primitive value via valueOf/toString.
// If the var is already a primitive, returns it unchanged.
// If no conversion possible, returns undefined.
static ActionVar objectToPrimitive(SWFAppContext* app_context, ActionVar* obj_var, int* out_success)
{
	if (out_success) *out_success = 1;

	if (obj_var->type != ACTION_STACK_VALUE_OBJECT &&
	    obj_var->type != ACTION_STACK_VALUE_ARRAY &&
	    obj_var->type != ACTION_STACK_VALUE_FUNCTION)
	{
		return *obj_var;
	}

	ASObject* obj = (ASObject*) obj_var->data.numeric_value;
	if (obj == NULL)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	// Try valueOf
	ActionVar* valueOf_prop = getPropertyWithPrototype(obj, "valueOf", 7);
	if (valueOf_prop != NULL)
	{
		if (valueOf_prop->type == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* func = lookupFunctionFromVar(valueOf_prop);
			if (func != NULL)
			{
				ActionVar result;
				if (func->function_type == 2 && func->advanced_func != NULL)
				{
					ActionVar* regs = NULL;
					if (func->register_count > 0)
						regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
					result = func->advanced_func(app_context, NULL, 0, regs, obj);
					if (regs != NULL) FREE(regs);
				}
				else if (func->function_type == 1 && func->simple_func != NULL)
				{
					result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				}
				else
				{
					result.type = ACTION_STACK_VALUE_UNDEFINED;
					result.data.numeric_value = 0;
				}

				// If result is a primitive (not an object), use it
				if (result.type != ACTION_STACK_VALUE_OBJECT &&
				    result.type != ACTION_STACK_VALUE_ARRAY &&
				    result.type != ACTION_STACK_VALUE_FUNCTION)
				{
					return result;
				}
			}
		}
		// valueOf is a stored primitive value (boxed Number/Boolean/undefined)
		else if (valueOf_prop->type == ACTION_STACK_VALUE_F32 ||
		         valueOf_prop->type == ACTION_STACK_VALUE_F64 ||
		         valueOf_prop->type == ACTION_STACK_VALUE_STRING ||
		         valueOf_prop->type == ACTION_STACK_VALUE_BOOLEAN ||
		         valueOf_prop->type == ACTION_STACK_VALUE_UNDEFINED)
		{
			return *valueOf_prop;
		}
	}

	// Try toString
	ActionVar* toString_prop = getPropertyWithPrototype(obj, "toString", 8);
	if (toString_prop != NULL)
	{
		if (toString_prop->type == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* func = lookupFunctionFromVar(toString_prop);
			if (func != NULL)
			{
				ActionVar result;
				if (func->function_type == 2 && func->advanced_func != NULL)
				{
					ActionVar* regs = NULL;
					if (func->register_count > 0)
						regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
					result = func->advanced_func(app_context, NULL, 0, regs, obj);
					if (regs != NULL) FREE(regs);
				}
				else if (func->function_type == 1 && func->simple_func != NULL)
				{
					result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				}
				else
				{
					result.type = ACTION_STACK_VALUE_UNDEFINED;
					result.data.numeric_value = 0;
				}

				if (result.type != ACTION_STACK_VALUE_OBJECT &&
				    result.type != ACTION_STACK_VALUE_ARRAY &&
				    result.type != ACTION_STACK_VALUE_FUNCTION)
				{
					return result;
				}
			}
		}
		else if (toString_prop->type == ACTION_STACK_VALUE_STRING)
		{
			return *toString_prop;
		}
	}

	// No conversion possible
	if (out_success) *out_success = 0;
	ActionVar undef = {0};
	undef.type = ACTION_STACK_VALUE_UNDEFINED;
	return undef;
}

void initTime(SWFAppContext* app_context)
{
	start_time = get_elapsed_ms();

	// Initialize global object if not already initialized
	if (global_object == NULL) {
		global_object = allocObject(app_context, 16);  // Start with capacity for 16 global properties
	}
}

// ==================================================================
// Display Control Operations
// ==================================================================

void actionToggleQuality(SWFAppContext* app_context)
{
	// In NO_GRAPHICS mode, this is a no-op
	// In full graphics mode, this would toggle between high and low quality rendering
	// affecting anti-aliasing, smoothing, etc.

	#ifdef DEBUG
	printf("[ActionToggleQuality] Toggled render quality\n");
	#endif
}

// ==================================================================
// avmplus-compatible Random Number Generator
// Based on Adobe's ActionScript VM (avmplus) implementation
// Source: https://github.com/adobe/avmplus/blob/master/core/MathUtils.cpp
// ==================================================================

typedef struct {
	uint32_t uValue;           // Random result and seed for next random result
	uint32_t uXorMask;         // XOR mask for generating the next random value
	uint32_t uSequenceLength;  // Number of values in the sequence
} TRandomFast;

#define kRandomPureMax 0x7FFFFFFFL

// XOR masks for random number generation (generates 2^n - 1 numbers)
static const uint32_t Random_Xor_Masks[31] = {
	0x00000003L, 0x00000006L, 0x0000000CL, 0x00000014L, 0x00000030L, 0x00000060L, 0x000000B8L, 0x00000110L,
	0x00000240L, 0x00000500L, 0x00000CA0L, 0x00001B00L, 0x00003500L, 0x00006000L, 0x0000B400L, 0x00012000L,
	0x00020400L, 0x00072000L, 0x00090000L, 0x00140000L, 0x00300000L, 0x00400000L, 0x00D80000L, 0x01200000L,
	0x03880000L, 0x07200000L, 0x09000000L, 0x14000000L, 0x32800000L, 0x48000000L, 0xA3000000L
};

// Global RNG state (initialized on first use or at startup)
static TRandomFast global_random_state = {0, 0, 0};

// Initialize the random number generator with a seed
static void RandomFastInit(TRandomFast *pRandomFast, uint32_t seed) {
	int32_t n = 31;
	pRandomFast->uValue = seed;
	pRandomFast->uSequenceLength = (1L << n) - 1L;
	pRandomFast->uXorMask = Random_Xor_Masks[n - 2];
}

// Generate next random value using XOR shift
static int32_t RandomFastNext(TRandomFast *pRandomFast) {
	if (pRandomFast->uValue & 1L) {
		pRandomFast->uValue = (pRandomFast->uValue >> 1L) ^ pRandomFast->uXorMask;
	} else {
		pRandomFast->uValue >>= 1L;
	}
	return (int32_t)pRandomFast->uValue;
}

// Hash function for additional randomness
static int32_t RandomPureHasher(int32_t iSeed) {
	const int32_t c1 = 1376312589L;
	const int32_t c2 = 789221L;
	const int32_t c3 = 15731L;

	iSeed = ((iSeed << 13) ^ iSeed) - (iSeed >> 21);
	int32_t iResult = (iSeed * (iSeed * iSeed * c3 + c2) + c1) & kRandomPureMax;
	iResult += iSeed;
	iResult = ((iResult << 13) ^ iResult) - (iResult >> 21);

	return iResult;
}

// Generate a random number (avmplus implementation)
static int32_t GenerateRandomNumber(TRandomFast *pRandomFast) {
	// Initialize if needed (first call or uninitialized)
	if (pRandomFast->uValue == 0) {
		// Use time-based seed for first initialization
		RandomFastInit(pRandomFast, (uint32_t)time(NULL));
	}

	int32_t aNum = RandomFastNext(pRandomFast);
	aNum = RandomPureHasher(aNum * 71L);
	return aNum & kRandomPureMax;
}

// AS2 random(max) function - returns integer in range [0, max)
static int32_t Random(int32_t range, TRandomFast *pRandomFast) {
	if (range <= 0) {
		return 0;
	}

	int32_t randomNumber = GenerateRandomNumber(pRandomFast);
	return randomNumber % range;
}

// ==================================================================
// MovieClip Property Support (for SET_PROPERTY / GET_PROPERTY)
// ==================================================================

// MovieClip structure is defined in action.h

// Global object for ActionScript _global
// This is initialized on first use and persists for the lifetime of the runtime
ASObject* global_object = NULL;

// _root MovieClip for simplified implementation
// Note: totalframes is set from SWF_FRAME_COUNT if available, otherwise defaults to 1
MovieClip root_movieclip = {
	.x = 0.0f,
	.y = 0.0f,
	.xscale = 100.0f,
	.yscale = 100.0f,
	.rotation = 0.0f,
	.alpha = 100.0f,
	.width = 550.0f,
	.height = 400.0f,
	.visible = 1,
	.currentframe = 1,
#ifdef SWF_FRAME_COUNT
	.totalframes = SWF_FRAME_COUNT,
#else
	.totalframes = 1,
#endif
	.framesloaded = 1,  // All frames loaded in NO_GRAPHICS mode
	.name = "_root",
	.target = "_root",
	.droptarget = "",  // No drag/drop in NO_GRAPHICS mode
	.url = "",  // Could be set to actual SWF URL if known
	.highquality = 1.0f,       // Default: high quality
	.focusrect = 1.0f,         // Default: focus rect enabled
	.soundbuftime = 5.0f,      // Default: 5 seconds
	.quality = "HIGH",         // Default: HIGH quality
	.xmouse = 0.0f,  // No mouse in NO_GRAPHICS mode
	.ymouse = 0.0f,  // No mouse in NO_GRAPHICS mode
	.parent = NULL  // _root has no parent
};

// Helper function to get MovieClip by target path
// Simplified: only supports "_root" or empty string
static MovieClip* getMovieClipByTarget(const char* target) {
	if (!target || strlen(target) == 0 || strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
		return &root_movieclip;
	}
	return NULL;  // Other paths not supported yet
}

#ifndef NO_GRAPHICS
// Targeted sprite for SetTarget — when non-NULL, play/stop/goto operate on this sprite
static DisplayObject* targeted_sprite = NULL;

// Forward declaration
extern DisplayObject* findDisplayObjectByName(const char* name);
#endif

#ifndef NO_GRAPHICS
/**
 * Stub for cloneMovieClip - not yet implemented
 * Called by ActionCloneSprite in graphics mode
 */
static void cloneMovieClip(const char* source_name, const char* target_name, int depth) {
	printf("[CloneSprite] STUB: source='%s' -> target='%s' (depth=%d)\n",
	       source_name, target_name, depth);
}
#endif

/**
 * Create a new MovieClip with the specified instance name and parent
 *
 * @param instance_name The name of this MovieClip instance (e.g., "mc1")
 * @param parent The parent MovieClip (can be NULL for orphaned clips)
 * @return Pointer to the newly allocated MovieClip
 *
 * Note: The caller is responsible for freeing the returned MovieClip
 */
static MovieClip* createMovieClip(const char* instance_name, MovieClip* parent) {
	MovieClip* mc = (MovieClip*)malloc(sizeof(MovieClip));
	if (!mc) {
		return NULL;
	}

	// Initialize with default values similar to root_movieclip
	mc->x = 0.0f;
	mc->y = 0.0f;
	mc->xscale = 100.0f;
	mc->yscale = 100.0f;
	mc->rotation = 0.0f;
	mc->alpha = 100.0f;
	mc->width = 0.0f;
	mc->height = 0.0f;
	mc->visible = 1;
	mc->currentframe = 1;
	mc->totalframes = 1;
	mc->framesloaded = 1;
	mc->highquality = 1.0f;
	mc->focusrect = 1.0f;
	mc->soundbuftime = 5.0f;
	strcpy(mc->quality, "HIGH");
	mc->xmouse = 0.0f;
	mc->ymouse = 0.0f;
	mc->droptarget[0] = '\0';
	mc->url[0] = '\0';

	// Set instance name
	strncpy(mc->name, instance_name, sizeof(mc->name) - 1);
	mc->name[sizeof(mc->name) - 1] = '\0';

	// Set parent and construct target path
	mc->parent = parent;

	// Construct target path based on parent
	if (parent == NULL) {
		// No parent - standalone clip
		strncpy(mc->target, instance_name, sizeof(mc->target) - 1);
		mc->target[sizeof(mc->target) - 1] = '\0';
	} else {
		// Has parent - construct path as parent.child
		int written = snprintf(mc->target, sizeof(mc->target), "%s.%s",
		                       parent->target, instance_name);
		if (written >= (int)sizeof(mc->target)) {
			// Path was truncated
			mc->target[sizeof(mc->target) - 1] = '\0';
		}
	}

	return mc;
}

/**
 * Construct the target path for a MovieClip
 *
 * @param mc The MovieClip to get the path for
 * @param buffer The buffer to write the path to
 * @param buffer_size Size of the buffer
 * @return Pointer to the buffer (for convenience)
 *
 * Note: This function returns the pre-computed target path stored in the MovieClip
 */
static const char* constructPath(MovieClip* mc, char* buffer, size_t buffer_size) {
	if (!mc || !buffer || buffer_size == 0) {
		if (buffer && buffer_size > 0) {
			buffer[0] = '\0';
		}
		return buffer;
	}

	// Return the pre-computed target path
	strncpy(buffer, mc->target, buffer_size - 1);
	buffer[buffer_size - 1] = '\0';
	return buffer;
}

// ==================================================================
// Execution Context Tracking (for SET_TARGET / SET_TARGET2)
// ==================================================================

// Global variable to track current execution context
// When NULL, defaults to root_movieclip
static MovieClip* g_current_context = NULL;

// Set the current execution context
static void setCurrentContext(MovieClip* mc) {
	g_current_context = mc;
}

// Get the current execution context
static MovieClip* getCurrentContext(void) {
	return g_current_context ? g_current_context : &root_movieclip;
}

ActionStackValueType convertString(SWFAppContext* app_context, char* var_str)
{
	switch (STACK_TOP_TYPE)
	{
		case ACTION_STACK_VALUE_F32:
		{
			float temp_val = VAL(float, &STACK_TOP_VALUE);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			if (isnan(temp_val)) snprintf(var_str, 17, "NaN");
			else if (isinf(temp_val)) snprintf(var_str, 17, "%sInfinity", temp_val < 0 ? "-" : "");
			else snprintf(var_str, 17, "%.15g", temp_val);
			break;
		}
		case ACTION_STACK_VALUE_F64:
		{
			double temp_val = VAL(double, &STACK_TOP_VALUE);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			if (isnan(temp_val)) snprintf(var_str, 17, "NaN");
			else if (isinf(temp_val)) snprintf(var_str, 17, "%sInfinity", temp_val < 0 ? "-" : "");
			else snprintf(var_str, 17, "%.15g", temp_val);
			break;
		}
		case ACTION_STACK_VALUE_BOOLEAN:
		{
			u64 val = STACK_TOP_VALUE;
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
#if defined(SWF_VERSION) && SWF_VERSION < 5
			snprintf(var_str, 17, "%s", val ? "1" : "0");
#else
			snprintf(var_str, 17, "%s", val ? "true" : "false");
#endif
			break;
		}
		case ACTION_STACK_VALUE_UNDEFINED:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
#if defined(SWF_VERSION) && SWF_VERSION >= 7
			snprintf(var_str, 17, "undefined");
#else
			var_str[0] = '\0';
#endif
			break;
		}
		case ACTION_STACK_VALUE_NULL:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			snprintf(var_str, 17, "null");
			break;
		}
		case ACTION_STACK_VALUE_FUNCTION:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			snprintf(var_str, 17, "[type Function]");
			break;
		}
		case ACTION_STACK_VALUE_MOVIECLIP:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			snprintf(var_str, 17, "_level0");
			break;
		}
		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_ARRAY:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
			snprintf(var_str, 17, "[object Object]");
			break;
		}
		default:
			// STRING, STR_LIST already strings; other types leave as-is
			break;
	}

	return ACTION_STACK_VALUE_STRING;
}

// Helper: read numeric value from ActionVar as double, regardless of F32/F64 type
static inline double varToDouble(ActionVar* v)
{
	if (v->type == ACTION_STACK_VALUE_F64)
		return VAL(double, &v->data.numeric_value);
	return (double)VAL(float, &v->data.numeric_value);
}

// Helper: convert ActionVar to int32 (ECMA-262 ToInt32)
static inline int32_t varToInt32(ActionVar* v)
{
	double d = varToDouble(v);
	if (isnan(d) || isinf(d)) return 0;
	return (int32_t)(int64_t)d;
}

// ECMA-262 ToUint32 - handles values outside int32_t range correctly
static inline uint32_t varToUint32(ActionVar* v)
{
	double d = varToDouble(v);
	if (isnan(d) || isinf(d) || d == 0.0) return 0;
	double posInt = (d > 0 ? 1.0 : -1.0) * floor(fabs(d));
	double mod = fmod(posInt, 4294967296.0);
	if (mod < 0) mod += 4294967296.0;
	return (uint32_t)mod;
}

// Helper: parse string to number matching ECMA-262 ToNumber
// Returns NaN for non-numeric strings (atof returns 0 which is wrong)
static inline double parseStringToNumber(const char* str)
{
	if (str == NULL || str[0] == '\0') return NAN;
	char* end;
	double val = strtod(str, &end);
	if (end == str) return NAN;
	while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
	if (*end != '\0') return NAN;
	return val;
}

// Helper: check if a double is "truthy" (non-zero and not NaN)
static inline int isTruthy(double d)
{
	return !isnan(d) && d != 0.0;
}

// Check truthiness of an ActionVar, respecting type semantics
// Objects, functions, arrays are always truthy
static inline int isVarTruthy(ActionVar* var)
{
	switch (var->type)
	{
		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_FUNCTION:
		case ACTION_STACK_VALUE_ARRAY:
		case ACTION_STACK_VALUE_MOVIECLIP:
			return 1;
		case ACTION_STACK_VALUE_BOOLEAN:
			return var->data.numeric_value != 0;
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_NULL:
			return 0;
		case ACTION_STACK_VALUE_STRING:
		case ACTION_STACK_VALUE_STR_LIST:
		{
			char* s = (char*)(u64)var->data.numeric_value;
			return s != NULL && s[0] != '\0';
		}
		default:
			return isTruthy(varToDouble(var));
	}
}

ActionStackValueType convertFloat(SWFAppContext* app_context)
{
	switch (STACK_TOP_TYPE)
	{
		case ACTION_STACK_VALUE_STRING:
		case ACTION_STACK_VALUE_STR_LIST:
		{
			char* str = NULL;
			if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
				str = (char*) VAL(u64, &STACK_TOP_VALUE);
			else
			{
				// For string lists, flatten to first string for numeric conversion
				u64* str_list = (u64*) &STACK_TOP_VALUE;
				if (str_list[0] > 0)
					str = (char*) str_list[1];
			}
			if (str != NULL && str[0] != '\0')
			{
				char* end;
				double temp;
				int parsed = 0;
#if defined(SWF_VERSION) && SWF_VERSION >= 6
				// SWF6+ supports hex (0x) and octal (0) prefix in string-to-number
				const char* s = str;
				int neg = 0;
				while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r') s++;
				if (*s == '-') { neg = 1; s++; }
				else if (*s == '+') { s++; }
				if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
				{
					long val = strtol(s, &end, 16);
					if (end != s) { temp = neg ? -(double)val : (double)val; parsed = 1; }
				}
				else if (s[0] == '0' && s[1] >= '0' && s[1] <= '7')
				{
					long val = strtol(s, &end, 8);
					if (end != s) { temp = neg ? -(double)val : (double)val; parsed = 1; }
				}
#endif
				if (!parsed)
				{
					// Prevent C strtod from parsing special values that
					// ActionScript doesn't recognize as string-to-number
					const char* p = str;
					while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') p++;
					if (*p == '+' || *p == '-') p++;
					if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X'))
					{
						// Hex prefix — only SWF6+ handles via strtol above
						end = (char*)str;
						temp = 0.0;
					}
					else if ((p[0] == 'I' || p[0] == 'i' || p[0] == 'N' || p[0] == 'n') &&
							 (strncasecmp(p, "Infinity", 8) == 0 || strncasecmp(p, "inf", 3) == 0 ||
							  strncasecmp(p, "nan", 3) == 0))
					{
						// C strtod recognizes Infinity/inf/NaN but Flash doesn't
						end = (char*)str;
						temp = 0.0;
					}
					else
					{
						temp = strtod(str, &end);
					}
				}
				// If no characters were consumed, it's NaN (or 0 in SWF < 5)
				if (!parsed && end == str)
				{
#if defined(SWF_VERSION) && SWF_VERSION < 5
					temp = 0.0;
#else
					temp = NAN;
#endif
				}
				// If there are trailing non-whitespace characters, it's NaN
				// Exception: SWF < 5 uses parseFloat semantics (accepts partial parses)
				else if (!parsed)
				{
#if !defined(SWF_VERSION) || SWF_VERSION >= 5
					while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
					if (*end != '\0') temp = NAN;
#endif
				}
				else
				{
					// parsed via hex/octal — check trailing chars
					while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
					if (*end != '\0') temp = NAN;
				}
				STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
				VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			}
			else
			{
				// Empty string -> 0.0 in all SWF versions
				// ECMA-262 section 9.3.1: empty string converts to +0
				double temp = 0.0;
				STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
				VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			}
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_BOOLEAN:
		{
			// true -> 1.0, false -> 0.0
			double temp = STACK_TOP_VALUE ? 1.0 : 0.0;
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_NULL:
		{
			// SWF < 7: null converts to 0.0
			// SWF >= 7: null converts to NaN (ECMA-262)
#if defined(SWF_VERSION) && SWF_VERSION >= 7
			double temp = NAN;
#else
			double temp = 0.0;
#endif
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_UNDEFINED:
		{
			// SWF < 7: undefined converts to 0.0
			// SWF >= 7: undefined converts to NaN (ECMA-262)
#if defined(SWF_VERSION) && SWF_VERSION < 7
			double temp = 0.0;
#else
			double temp = NAN;
#endif
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_F32:
			return ACTION_STACK_VALUE_F32;

		case ACTION_STACK_VALUE_F64:
			return ACTION_STACK_VALUE_F64;

		case ACTION_STACK_VALUE_MOVIECLIP:
		{
			// MovieClips convert to NaN in all SWF versions
			// (their toString returns the target path like "_level0" which is non-numeric)
			double temp = NAN;
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_FUNCTION:
		case ACTION_STACK_VALUE_ARRAY:
		{
			// Try to extract primitive via valueOf
			ASObject* obj = NULL;
			if (STACK_TOP_TYPE == ACTION_STACK_VALUE_OBJECT || STACK_TOP_TYPE == ACTION_STACK_VALUE_ARRAY)
				obj = (ASObject*) STACK_TOP_VALUE;

			if (obj != NULL)
			{
				ActionVar* valueOf_prop = getPropertyWithPrototype(obj, "valueOf", 7);
				if (valueOf_prop != NULL)
				{
					if (valueOf_prop->type == ACTION_STACK_VALUE_FUNCTION)
					{
						ASFunction* func = lookupFunctionFromVar(valueOf_prop);
						if (func != NULL)
						{
							ActionVar result;
							if (func->function_type == 2 && func->advanced_func != NULL)
							{
								ActionVar* regs = NULL;
								if (func->register_count > 0)
									regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
								result = func->advanced_func(app_context, NULL, 0, regs, obj);
								if (regs != NULL) FREE(regs);
							}
							else if (func->function_type == 1 && func->simple_func != NULL)
							{
								result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
							}
							else
							{
								result.type = ACTION_STACK_VALUE_UNDEFINED;
								result.data.numeric_value = 0;
							}

							// If valueOf returned a primitive, use it
							if (result.type != ACTION_STACK_VALUE_OBJECT &&
							    result.type != ACTION_STACK_VALUE_ARRAY &&
							    result.type != ACTION_STACK_VALUE_FUNCTION)
							{
								POP();
								pushVar(app_context, &result);
								if (result.type == ACTION_STACK_VALUE_F64 || result.type == ACTION_STACK_VALUE_F32)
									return result.type;
								// Recursively convert non-numeric primitives (string, boolean, etc.)
								return convertFloat(app_context);
							}
						}
					}
					// valueOf is a stored primitive value (boxed Number/Boolean)
					else if (valueOf_prop->type == ACTION_STACK_VALUE_F32 ||
					         valueOf_prop->type == ACTION_STACK_VALUE_F64)
					{
						POP();
						pushVar(app_context, valueOf_prop);
						return valueOf_prop->type;
					}
				}
			}

			// No valueOf or valueOf didn't return a number
			// SWF < 7: objects convert to 0.0 (Flash 6 and earlier behavior)
			// SWF >= 7: objects convert to NaN (ECMA-262 compliant)
#if defined(SWF_VERSION) && SWF_VERSION < 7
			double temp = 0.0;
#else
			double temp = NAN;
#endif
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		default:
			return STACK_TOP_TYPE;
	}
}

ActionStackValueType convertDouble(SWFAppContext* app_context)
{
	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_F32)
	{
		double temp = VAL(double, &STACK_TOP_VALUE);
		STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
		VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
	}
	
	return ACTION_STACK_VALUE_F64;
}

void pushVar(SWFAppContext* app_context, ActionVar* var)
{
	switch (var->type)
	{
		case ACTION_STACK_VALUE_F32:
		case ACTION_STACK_VALUE_F64:
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_NULL:
		case ACTION_STACK_VALUE_BOOLEAN:
		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_FUNCTION:
		case ACTION_STACK_VALUE_ARRAY:
		case ACTION_STACK_VALUE_MOVIECLIP:
		{
			PUSH(var->type, var->data.numeric_value);

			break;
		}

		case ACTION_STACK_VALUE_STRING:
		{
			// Use heap pointer if variable owns memory, otherwise use numeric_value as pointer
			char* str_ptr = var->data.string_data.owns_memory ?
				var->data.string_data.heap_ptr :
				(char*) var->data.numeric_value;

			PUSH_STR_ID(str_ptr, var->str_size, var->string_id);

			break;
		}

		default:
		{
			// Fallback: push as raw value with original type
			PUSH(var->type, var->data.numeric_value);
			break;
		}
	}
}

void peekVar(SWFAppContext* app_context, ActionVar* var)
{
	var->type = STACK_TOP_TYPE;
	var->str_size = STACK_TOP_N;

	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STR_LIST)
	{
		var->data.numeric_value = (u64) &STACK_TOP_VALUE;
		var->string_id = 0;  // String lists don't have IDs
	}
	else if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
	{
		// For strings, store pointer and mark as not owning memory (it's on the stack)
		var->data.numeric_value = VAL(u64, &STACK_TOP_VALUE);
		var->data.string_data.heap_ptr = (char*) var->data.numeric_value;
		var->data.string_data.owns_memory = false;
		var->string_id = VAL(u32, &STACK[SP + 12]);  // Read string_id from stack
	}
	else
	{
		var->data.numeric_value = VAL(u64, &STACK_TOP_VALUE);
		var->string_id = 0;  // Non-string types don't have IDs
	}

	// Initialize owns_memory to false for non-heap strings
	// (When the value is in numeric_value, not string_data.heap_ptr)
	if (var->type == ACTION_STACK_VALUE_STRING)
	{
		var->data.string_data.owns_memory = false;
	}
}

void popVar(SWFAppContext* app_context, ActionVar* var)
{
	peekVar(app_context, var);

	POP();
}

void peekSecondVar(SWFAppContext* app_context, ActionVar* var)
{
	u32 second_sp = SP_SECOND_TOP;
	var->type = STACK[second_sp];
	var->str_size = VAL(u32, &STACK[second_sp + 8]);

	if (STACK[second_sp] == ACTION_STACK_VALUE_STR_LIST)
	{
		var->data.numeric_value = (u64) &VAL(u64, &STACK[second_sp + 16]);
		var->string_id = 0;
	}
	else if (STACK[second_sp] == ACTION_STACK_VALUE_STRING)
	{
		var->data.numeric_value = VAL(u64, &STACK[second_sp + 16]);
		var->data.string_data.heap_ptr = (char*) var->data.numeric_value;
		var->data.string_data.owns_memory = false;
		var->string_id = VAL(u32, &STACK[second_sp + 12]);
	}
	else
	{
		var->data.numeric_value = VAL(u64, &STACK[second_sp + 16]);
		var->string_id = 0;
	}

	if (var->type == ACTION_STACK_VALUE_STRING)
	{
		var->data.string_data.owns_memory = false;
	}
}

void actionPrevFrame(SWFAppContext* app_context)
{
	// Suppress unused parameter warning
	(void)app_context;

	// Access global frame control variables
	extern size_t current_frame;
	extern size_t next_frame;
	extern int manual_next_frame;

	// Move to previous frame if not already at first frame
	if (current_frame > 0)
	{
		next_frame = current_frame - 1;
		manual_next_frame = 1;
	}
	// If already at frame 0, do nothing (stay on current frame)
}

void actionAdd(SWFAppContext* app_context)
{
	// Flash evaluates left operand before right.
	// Pop right raw, convert left first, then right.
	ActionVar a_raw;
	popVar(app_context, &a_raw);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	pushVar(app_context, &a_raw);
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);

		double c = b_val + a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);

		double c = b_val + a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else
	{
		float c = VAL(float, &b.data.numeric_value) + VAL(float, &a.data.numeric_value);
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionAdd2(SWFAppContext* app_context, char* str_buffer)
{
	// Flash Add2 algorithm:
	// 1. Pop both operands
	// 2. Call valueOf on each object operand (right first for Flash evaluation order)
	// 3. If either raw type or valueOf result is a string → string concatenation
	//    - Objects with primitive valueOf: convert that primitive to string
	//    - Objects with non-primitive valueOf: call toString, fallback to "[type Object]"
	//    - Objects with no valueOf: use convertString → "[object Object]"
	// 4. Else → numeric addition using original operands (convertFloat calls valueOf again)
	//    - Objects with primitive valueOf: use that result for numeric conversion
	//    - Objects with non-primitive valueOf: convertFloat on original (valueOf called again)

	// Pop right operand (a = top of stack)
	ActionVar a_raw;
	popVar(app_context, &a_raw);

	// Pop left operand (b = second on stack)
	ActionVar b_raw;
	popVar(app_context, &b_raw);

	// Determine which operands are objects
	int a_is_obj = (a_raw.type == ACTION_STACK_VALUE_OBJECT ||
	                a_raw.type == ACTION_STACK_VALUE_ARRAY ||
	                a_raw.type == ACTION_STACK_VALUE_FUNCTION);
	int b_is_obj = (b_raw.type == ACTION_STACK_VALUE_OBJECT ||
	                b_raw.type == ACTION_STACK_VALUE_ARRAY ||
	                b_raw.type == ACTION_STACK_VALUE_FUNCTION);

	// Call valueOf on object operands (right first for Flash evaluation order)
	ActionVar a_vo = a_raw;
	int a_vo_found = 0;
	int a_vo_is_prim = !a_is_obj;  // non-objects are already primitive
	if (a_is_obj)
	{
		a_vo = objectCallValueOf(app_context, &a_raw, &a_vo_found);
		a_vo_is_prim = (a_vo.type != ACTION_STACK_VALUE_OBJECT &&
		                a_vo.type != ACTION_STACK_VALUE_ARRAY &&
		                a_vo.type != ACTION_STACK_VALUE_FUNCTION);
	}

	ActionVar b_vo = b_raw;
	int b_vo_found = 0;
	int b_vo_is_prim = !b_is_obj;
	if (b_is_obj)
	{
		b_vo = objectCallValueOf(app_context, &b_raw, &b_vo_found);
		b_vo_is_prim = (b_vo.type != ACTION_STACK_VALUE_OBJECT &&
		                b_vo.type != ACTION_STACK_VALUE_ARRAY &&
		                b_vo.type != ACTION_STACK_VALUE_FUNCTION);
	}

	// Check if string path: either raw type or valueOf result is a string
	if (a_raw.type == ACTION_STACK_VALUE_STRING || b_raw.type == ACTION_STACK_VALUE_STRING ||
	    a_vo.type == ACTION_STACK_VALUE_STRING || b_vo.type == ACTION_STACK_VALUE_STRING)
	{
		// STRING CONCATENATION PATH
		char str_b_buf[17], str_a_buf[17];
		const char* str_b_ptr = NULL;
		const char* str_a_ptr = NULL;
		size_t len_b = 0, len_a = 0;

		// Get string for left operand (b)
		if (!b_is_obj)
		{
			pushVar(app_context, &b_raw);
			convertString(app_context, str_b_buf);
			str_b_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
			POP();
			len_b = str_b_ptr ? strlen(str_b_ptr) : 0;
		}
		else if (b_vo_is_prim)
		{
			// valueOf returned a primitive — convert it to string
			pushVar(app_context, &b_vo);
			convertString(app_context, str_b_buf);
			str_b_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
			POP();
			len_b = str_b_ptr ? strlen(str_b_ptr) : 0;
		}
		else if (b_vo_found)
		{
			// valueOf was found but returned non-primitive — try toString
			ActionVar ts = objectCallToString(app_context, &b_raw, NULL);
			if (ts.type == ACTION_STACK_VALUE_STRING)
			{
				str_b_ptr = (const char*) ts.data.numeric_value;
				len_b = ts.str_size ? ts.str_size : (str_b_ptr ? strlen(str_b_ptr) : 0);
			}
			else
			{
				str_b_ptr = "[type Object]";
				len_b = 13;
			}
		}
		else
		{
			// No valueOf found — try toString before falling back to convertString
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &b_raw, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			{
				str_b_ptr = (const char*) ts.data.numeric_value;
				len_b = ts.str_size ? ts.str_size : (str_b_ptr ? strlen(str_b_ptr) : 0);
			}
			else if (ts_found)
			{
				str_b_ptr = "[type Object]";
				len_b = 13;
			}
			else
			{
				pushVar(app_context, &b_raw);
				convertString(app_context, str_b_buf);
				str_b_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
				POP();
				len_b = str_b_ptr ? strlen(str_b_ptr) : 0;
			}
		}

		// Get string for right operand (a)
		if (!a_is_obj)
		{
			pushVar(app_context, &a_raw);
			convertString(app_context, str_a_buf);
			str_a_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
			POP();
			len_a = str_a_ptr ? strlen(str_a_ptr) : 0;
		}
		else if (a_vo_is_prim)
		{
			pushVar(app_context, &a_vo);
			convertString(app_context, str_a_buf);
			str_a_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
			POP();
			len_a = str_a_ptr ? strlen(str_a_ptr) : 0;
		}
		else if (a_vo_found)
		{
			ActionVar ts = objectCallToString(app_context, &a_raw, NULL);
			if (ts.type == ACTION_STACK_VALUE_STRING)
			{
				str_a_ptr = (const char*) ts.data.numeric_value;
				len_a = ts.str_size ? ts.str_size : (str_a_ptr ? strlen(str_a_ptr) : 0);
			}
			else
			{
				str_a_ptr = "[type Object]";
				len_a = 13;
			}
		}
		else
		{
			// No valueOf found — try toString before falling back to convertString
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &a_raw, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			{
				str_a_ptr = (const char*) ts.data.numeric_value;
				len_a = ts.str_size ? ts.str_size : (str_a_ptr ? strlen(str_a_ptr) : 0);
			}
			else if (ts_found)
			{
				str_a_ptr = "[type Object]";
				len_a = 13;
			}
			else
			{
				pushVar(app_context, &a_raw);
				convertString(app_context, str_a_buf);
				str_a_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
				POP();
				len_a = str_a_ptr ? strlen(str_a_ptr) : 0;
			}
		}

		// Concatenate (left + right = b + a)
		size_t total_len = len_b + len_a;
		if (total_len < 17)
		{
			memcpy(str_buffer, str_b_ptr, len_b);
			memcpy(str_buffer + len_b, str_a_ptr, len_a);
			str_buffer[total_len] = '\0';
			PUSH_STR(str_buffer, total_len);
		}
		else
		{
			char* heap_str = (char*) HALLOC(total_len + 1);
			memcpy(heap_str, str_b_ptr, len_b);
			memcpy(heap_str + len_b, str_a_ptr, len_a);
			heap_str[total_len] = '\0';
			PUSH_STR(heap_str, total_len);
		}
	}
	else
	{
		// NUMERIC ADDITION PATH
		// For objects with primitive valueOf: use that result
		// For objects with non-primitive valueOf or no valueOf: push original (convertFloat
		// calls valueOf again, matching Flash's double-valueOf behavior)

		// Left (b)
		if (b_is_obj && b_vo_is_prim)
			pushVar(app_context, &b_vo);
		else
			pushVar(app_context, &b_raw);
		convertFloat(app_context);
		ActionVar b_num;
		popVar(app_context, &b_num);

		// Right (a)
		if (a_is_obj && a_vo_is_prim)
			pushVar(app_context, &a_vo);
		else
			pushVar(app_context, &a_raw);
		convertFloat(app_context);
		ActionVar a_num;
		popVar(app_context, &a_num);

		if (a_num.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = VAL(double, &a_num.data.numeric_value);
			double b_val = b_num.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b_num.data.numeric_value) : VAL(double, &b_num.data.numeric_value);
			double c = b_val + a_val;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}
		else if (b_num.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = a_num.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a_num.data.numeric_value) : VAL(double, &a_num.data.numeric_value);
			double b_val = VAL(double, &b_num.data.numeric_value);
			double c = b_val + a_val;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}
		else
		{
			float c = VAL(float, &b_num.data.numeric_value) + VAL(float, &a_num.data.numeric_value);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
		}
	}
}

void actionSubtract(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);
	
	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);
	
	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
		
		double c = b_val - a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);
		
		double c = b_val - a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else
	{
		float c = VAL(float, &b.data.numeric_value) - VAL(float, &a.data.numeric_value);
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionMultiply(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);
	
	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);
	
	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
		
		double c = b_val*a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);
		
		double c = b_val*a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else
	{
		float c = VAL(float, &b.data.numeric_value)*VAL(float, &a.data.numeric_value);
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionDivide(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);
	
	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);
	
	double a_val = varToDouble(&a);
	double b_val = varToDouble(&b);

	if (a_val == 0.0)
	{
#if defined(SWF_VERSION) && SWF_VERSION < 5
		// SWF4: divide by zero returns "#ERROR#"
		PUSH_STR("#ERROR#", 8);
#else
		// SWF5+: divide by zero returns Infinity/-Infinity/NaN
		double c = b_val / a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
#endif
	}
	else
	{
		double c = b_val / a_val;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
}

void actionModulo(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	if (varToDouble(&a) == 0.0)
	{
		// SWF 4: Division by zero returns error string
		PUSH_STR("#ERROR#", 8);
	}
	else
	{
		if (a.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = VAL(double, &a.data.numeric_value);
			double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);

			double c = fmod(b_val, a_val);
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}

		else if (b.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
			double b_val = VAL(double, &b.data.numeric_value);

			double c = fmod(b_val, a_val);
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}

		else
		{
			float c = fmodf(VAL(float, &b.data.numeric_value), VAL(float, &a.data.numeric_value));
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
		}
	}
}

void actionEquals(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	double a_val = varToDouble(&a);
	double b_val = varToDouble(&b);
	u64 result = (a_val == b_val) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionLess(SWFAppContext* app_context)
{
	// Pop both raw first, then convert left-to-right (Flash evaluation order)
	ActionVar right;
	popVar(app_context, &right);
	ActionVar left;
	popVar(app_context, &left);

	// Convert left operand first (for correct valueOf side-effect ordering)
	pushVar(app_context, &left);
	convertFloat(app_context);
	popVar(app_context, &left);

	pushVar(app_context, &right);
	convertFloat(app_context);
	popVar(app_context, &right);

	double left_val = varToDouble(&left);
	double right_val = varToDouble(&right);
	u64 result = (left_val < right_val) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionLess2(SWFAppContext* app_context)
{
	// ActionLess2 (0x48) — SWF5+ only
	// Pop both operands raw, convert objects, then compare.
	ActionVar right;
	popVar(app_context, &right);
	ActionVar left;
	popVar(app_context, &left);

	// Convert object operands via valueOf only (number hint — no toString fallback)
	if (left.type == ACTION_STACK_VALUE_OBJECT || left.type == ACTION_STACK_VALUE_ARRAY)
	{
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &left, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			left = vo;
		}
		// else: no valueOf or returned non-primitive → numeric path gives NaN
	}
	if (right.type == ACTION_STACK_VALUE_OBJECT || right.type == ACTION_STACK_VALUE_ARRAY)
	{
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &right, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			right = vo;
		}
	}

	// If both are strings, lexicographic comparison
	int left_is_str = (left.type == ACTION_STACK_VALUE_STRING || left.type == ACTION_STACK_VALUE_STR_LIST);
	int right_is_str = (right.type == ACTION_STACK_VALUE_STRING || right.type == ACTION_STACK_VALUE_STR_LIST);

	if (left_is_str && right_is_str)
	{
		const char* left_str = (left.type == ACTION_STACK_VALUE_STR_LIST) ?
			(const char*)((u64*)&left.data.numeric_value)[1] :
			(const char*)left.data.numeric_value;
		const char* right_str = (right.type == ACTION_STACK_VALUE_STR_LIST) ?
			(const char*)((u64*)&right.data.numeric_value)[1] :
			(const char*)right.data.numeric_value;

		if (left_str == NULL) left_str = "";
		if (right_str == NULL) right_str = "";

		u64 bool_val = (strcmp(left_str, right_str) < 0) ? 1 : 0;
		PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
	}
	else
	{
		// Numeric comparison — convert both to double via stack-based convertFloat
		pushVar(app_context, &left);
		convertFloat(app_context);
		popVar(app_context, &left);

		pushVar(app_context, &right);
		convertFloat(app_context);
		popVar(app_context, &right);

		double left_val = varToDouble(&left);
		double right_val = varToDouble(&right);
		if (isnan(left_val) || isnan(right_val))
		{
			// NaN comparison returns undefined
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		}
		else
		{
			u64 bool_val = (left_val < right_val) ? 1 : 0;
			PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
		}
	}
}

void actionGreater(SWFAppContext* app_context)
{
	// ActionGreater (0x67) — SWF6+ only
	// Pop both, convert objects via valueOf (number hint), then compare.
	ActionVar right;
	popVar(app_context, &right);
	ActionVar left;
	popVar(app_context, &left);

	// Convert object operands via valueOf only (number hint — no toString fallback)
	if (left.type == ACTION_STACK_VALUE_OBJECT || left.type == ACTION_STACK_VALUE_ARRAY)
	{
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &left, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			left = vo;
		}
	}
	if (right.type == ACTION_STACK_VALUE_OBJECT || right.type == ACTION_STACK_VALUE_ARRAY)
	{
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &right, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			right = vo;
		}
	}

	// If both are strings, lexicographic comparison
	int left_is_str = (left.type == ACTION_STACK_VALUE_STRING || left.type == ACTION_STACK_VALUE_STR_LIST);
	int right_is_str = (right.type == ACTION_STACK_VALUE_STRING || right.type == ACTION_STACK_VALUE_STR_LIST);

	if (left_is_str && right_is_str)
	{
		const char* left_str = (left.type == ACTION_STACK_VALUE_STR_LIST) ?
			(const char*)((u64*)&left.data.numeric_value)[1] :
			(const char*)left.data.numeric_value;
		const char* right_str = (right.type == ACTION_STACK_VALUE_STR_LIST) ?
			(const char*)((u64*)&right.data.numeric_value)[1] :
			(const char*)right.data.numeric_value;

		if (left_str == NULL) left_str = "";
		if (right_str == NULL) right_str = "";

		u64 bool_val = (strcmp(left_str, right_str) > 0) ? 1 : 0;
		PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
	}
	else
	{
		// Numeric comparison
		pushVar(app_context, &right);
		convertFloat(app_context);
		popVar(app_context, &right);

		pushVar(app_context, &left);
		convertFloat(app_context);
		popVar(app_context, &left);

		double left_val = varToDouble(&left);
		double right_val = varToDouble(&right);
		if (isnan(left_val) || isnan(right_val))
		{
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		}
		else
		{
			u64 bool_val = (left_val > right_val) ? 1 : 0;
			PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
		}
	}
}

void actionAnd(SWFAppContext* app_context)
{
	ActionVar a;
	popVar(app_context, &a);

	ActionVar b;
	popVar(app_context, &b);

	int result = isVarTruthy(&a) && isVarTruthy(&b);
	PUSH(ACTION_STACK_VALUE_BOOLEAN, (u64)result);
}

void actionOr(SWFAppContext* app_context)
{
	ActionVar a;
	popVar(app_context, &a);

	ActionVar b;
	popVar(app_context, &b);

	int result = isVarTruthy(&a) || isVarTruthy(&b);
	PUSH(ACTION_STACK_VALUE_BOOLEAN, (u64)result);
}

void actionNot(SWFAppContext* app_context)
{
	// Evaluate truthiness based on type, then negate
	ActionStackValueType type = STACK_TOP_TYPE;
	u64 val = STACK_TOP_VALUE;
	int is_truthy = 0;

	switch (type)
	{
		case ACTION_STACK_VALUE_F32:
		{
			float f = VAL(float, &val);
			is_truthy = (f != 0.0f && !isnan(f));
			break;
		}
		case ACTION_STACK_VALUE_F64:
		{
			double d = VAL(double, &val);
			is_truthy = (d != 0.0 && !isnan(d));
			break;
		}
		case ACTION_STACK_VALUE_BOOLEAN:
			is_truthy = (val != 0);
			break;
		case ACTION_STACK_VALUE_STRING:
		case ACTION_STACK_VALUE_STR_LIST:
		{
			char* s = (char*) val;
			is_truthy = (s != NULL && s[0] != '\0');
			break;
		}
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_NULL:
			is_truthy = 0;
			break;
		default:
			// Objects, arrays, functions, movieclips are truthy
			is_truthy = (val != 0);
			break;
	}

	POP();
	u64 result = is_truthy ? 0 : 1;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionToInteger(SWFAppContext* app_context)
{
	ActionVar v;
	convertFloat(app_context);
	popVar(app_context, &v);

	double d = varToDouble(&v);
	double result;

	if (isnan(d) || isinf(d)) {
		result = 0.0;
	} else {
		result = (double)(int32_t)d;
	}

	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionToNumber(SWFAppContext* app_context)
{
	// Convert top of stack to number
	// convertFloat() handles all type conversions:
	// - Number: return as-is
	// - String: parse as number (empty→0, invalid→NaN)
	// - Boolean: true→1, false→0
	// - Null/undefined: NaN
	convertFloat(app_context);
	// Value is already converted on stack in-place
}

void actionToString(SWFAppContext* app_context, char* str_buffer)
{
	// Convert top of stack to string
	// If already string, this does nothing
	// If float, converts using snprintf with %.15g format
	convertString(app_context, str_buffer);
}

void actionStackSwap(SWFAppContext* app_context)
{
	// Pop top value (value1)
	ActionVar val1;
	popVar(app_context, &val1);

	// Pop second value (value2)
	ActionVar val2;
	popVar(app_context, &val2);

	// Push value1 (was on top, now goes to second position)
	pushVar(app_context, &val1);

	// Push value2 (was second, now goes to top)
	pushVar(app_context, &val2);
}

/**
 * actionTargetPath - Returns the target path of a MovieClip
 *
 * Opcode: 0x45 (ActionTargetPath)
 * Stack: [ movieclip ] -> [ path_string | undefined ]
 *
 * Pops a value from the stack. If it's a MovieClip, pushes its target path
 * as a string (e.g., "_root.mc1.mc2"). If it's not a MovieClip, pushes undefined.
 *
 * Path format: Dot notation (e.g., "_root.mc1.mc2")
 *
 * Edge cases:
 * - Non-MovieClip values (numbers, strings, objects): Returns undefined
 * - _root MovieClip: Returns "_root"
 * - Nested MovieClips: Returns full path from _root
 *
 * SWF version: 5+
 * Opcode: 0x45
 */
void actionTargetPath(SWFAppContext* app_context, char* str_buffer)
{
	// Get type of value on stack
	u8 type = STACK_TOP_TYPE;

	// Pop value from stack
	ActionVar val;
	popVar(app_context, &val);

	// Check if value is a MovieClip
	if (type == ACTION_STACK_VALUE_MOVIECLIP) {
		// Get the MovieClip pointer from the value
		MovieClip* mc = (MovieClip*) val.data.numeric_value;

		if (mc) {
			// Get the pre-computed target path from the MovieClip
			const char* path = mc->target;
			int len = strlen(path);

			// Copy path to string buffer
			strncpy(str_buffer, path, 256);  // MovieClip.target is 256 bytes
			str_buffer[255] = '\0';  // Ensure null termination

			// Push the path string
			PUSH_STR(str_buffer, len);
		} else {
			// Null MovieClip pointer - return undefined
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		}
	} else {
		// Not a MovieClip, return undefined per specification
		// "If the object is not a MovieClip, the result is undefined"
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	}
}

/**
 * Helper structure to track enumerated property names
 * Used to prevent duplicates when walking the prototype chain
 */
typedef struct EnumeratedName {
	const char* name;
	u32 name_length;
	struct EnumeratedName* next;
} EnumeratedName;

/**
 * Check if a property name has already been enumerated
 */
static int isPropertyEnumerated(EnumeratedName* head, const char* name, u32 name_length)
{
	EnumeratedName* current = head;
	while (current != NULL)
	{
		if (current->name_length == name_length &&
		    strncmp(current->name, name, name_length) == 0)
		{
			return 1; // Found - property was already enumerated
		}
		current = current->next;
	}
	return 0; // Not found
}

/**
 * Add a property name to the enumerated list
 */
static void addEnumeratedName(EnumeratedName** head, const char* name, u32 name_length)
{
	EnumeratedName* node = (EnumeratedName*) malloc(sizeof(EnumeratedName));
	if (node == NULL)
	{
		return; // Out of memory, skip this property
	}
	node->name = name;
	node->name_length = name_length;
	node->next = *head;
	*head = node;
}

/**
 * Free the enumerated names list
 */
static void freeEnumeratedNames(EnumeratedName* head)
{
	while (head != NULL)
	{
		EnumeratedName* next = head->next;
		free(head);
		head = next;
	}
}

void actionEnumerate(SWFAppContext* app_context, char* str_buffer)
{
	// Step 1: Pop variable name from stack
	// Stack layout for strings: +0=type, +4=oldSP, +8=length, +12=string_id, +16=pointer
	u32 string_id = VAL(u32, &STACK[SP + 12]);
	char* var_name = (char*) VAL(u64, &STACK[SP + 16]);
	u32 var_name_len = VAL(u32, &STACK[SP + 8]);
	POP();

#ifdef DEBUG
	printf("[DEBUG] actionEnumerate: looking up variable '%.*s' (len=%u, id=%u)\n",
	       var_name_len, var_name, var_name_len, string_id);
#endif

	// Step 2: Look up the variable
	ActionVar* var = NULL;
	if (string_id > 0)
	{
		// Constant string - use array lookup (O(1))
		var = getVariableById(string_id);
	}
	else
	{
		// Dynamic string - use hashmap (O(n))
		var = getVariable(var_name, var_name_len);
	}

	// Step 3: Check if variable exists and is an object
	if (!var || var->type != ACTION_STACK_VALUE_OBJECT)
	{
#ifdef DEBUG
		if (!var)
			printf("[DEBUG] actionEnumerate: variable not found\n");
		else
			printf("[DEBUG] actionEnumerate: variable is not an object (type=%d)\n", var->type);
#endif
		// Variable not found or not an object - push null terminator only
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

	// Step 4: Get the object from the variable
	ASObject* obj = (ASObject*) VAL(u64, &var->data.numeric_value);
	if (obj == NULL)
	{
#ifdef DEBUG
		printf("[DEBUG] actionEnumerate: object pointer is NULL\n");
#endif
		// Null object - push null terminator only
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

	// Step 5: Collect all enumerable properties from the entire prototype chain
	// We need to collect them first to push in reverse order

	// Temporary storage for property names (we'll push them to stack after collecting)
	typedef struct PropList {
		const char* name;
		u32 name_length;
		struct PropList* next;
	} PropList;

	PropList* prop_head = NULL;
	u32 total_props = 0;

	// Track which properties we've already seen (to handle shadowing)
	EnumeratedName* enumerated_head = NULL;

	// Walk the prototype chain
	ASObject* current_obj = obj;
	int chain_depth = 0;
	const int MAX_CHAIN_DEPTH = 100; // Prevent infinite loops

	while (current_obj != NULL && chain_depth < MAX_CHAIN_DEPTH)
	{
		chain_depth++;

#ifdef DEBUG
		printf("[DEBUG] actionEnumerate: walking prototype chain depth=%d, num_used=%u\n",
		       chain_depth, current_obj->num_used);
#endif

		// Enumerate properties from this level
		for (u32 i = 0; i < current_obj->num_used; i++)
		{
			const char* prop_name = current_obj->properties[i].name;
			u32 prop_name_len = current_obj->properties[i].name_length;
			u8 prop_flags = current_obj->properties[i].flags;

			// Skip if property is not enumerable (DontEnum)
			if (!(prop_flags & PROPERTY_FLAG_ENUMERABLE))
			{
#ifdef DEBUG
				printf("[DEBUG] actionEnumerate: skipping non-enumerable property '%.*s'\n",
				       prop_name_len, prop_name);
#endif
				continue;
			}

			// Skip if we've already enumerated this property name (shadowing)
			if (isPropertyEnumerated(enumerated_head, prop_name, prop_name_len))
			{
#ifdef DEBUG
				printf("[DEBUG] actionEnumerate: skipping shadowed property '%.*s'\n",
				       prop_name_len, prop_name);
#endif
				continue;
			}

			// Add to enumerated list
			addEnumeratedName(&enumerated_head, prop_name, prop_name_len);

			// Add to property list (for later pushing to stack)
			PropList* node = (PropList*) malloc(sizeof(PropList));
			if (node != NULL)
			{
				node->name = prop_name;
				node->name_length = prop_name_len;
				node->next = prop_head;
				prop_head = node;
				total_props++;

#ifdef DEBUG
				printf("[DEBUG] actionEnumerate: added enumerable property '%.*s'\n",
				       prop_name_len, prop_name);
#endif
			}
		}

		// Move to prototype via __proto__ property
		ActionVar* proto_var = getProperty(current_obj, "__proto__", 9);
		if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
		{
			current_obj = (ASObject*) proto_var->data.numeric_value;
#ifdef DEBUG
			printf("[DEBUG] actionEnumerate: following __proto__ to next level\n");
#endif
		}
		else
		{
			// End of prototype chain
			current_obj = NULL;
		}
	}

	// Free the enumerated names list
	freeEnumeratedNames(enumerated_head);

#ifdef DEBUG
	printf("[DEBUG] actionEnumerate: collected %u enumerable properties total\n", total_props);
#endif

	// Step 6: Push null terminator first
	// This marks the end of the enumeration for for..in loops
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);

	// Step 7: Push property names from the list (they're already in reverse order)
	while (prop_head != NULL)
	{
		PUSH_STR((char*)prop_head->name, prop_head->name_length);

		PropList* next = prop_head->next;
		free(prop_head);
		prop_head = next;
	}
}


int evaluateCondition(SWFAppContext* app_context)
{
	ActionStackValueType type = STACK_TOP_TYPE;
	u64 val = STACK_TOP_VALUE;
	POP();

	switch (type)
	{
		case ACTION_STACK_VALUE_F32:
		{
			float f = VAL(float, &val);
			return (f != 0.0f && !isnan(f));
		}
		case ACTION_STACK_VALUE_F64:
		{
			double d = VAL(double, &val);
			return (d != 0.0 && !isnan(d));
		}
		case ACTION_STACK_VALUE_BOOLEAN:
			return (val != 0);
		case ACTION_STACK_VALUE_STRING:
		case ACTION_STACK_VALUE_STR_LIST:
		{
			char* s = (char*) val;
			return (s != NULL && s[0] != '\0');
		}
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_NULL:
			return 0;
		default:
			// Objects, arrays, functions are truthy
			return (val != 0);
	}
}

int strcmp_list_a_list_b(u64 a_value, u64 b_value)
{
	char** a_list = (char**) a_value;
	char** b_list = (char**) b_value;
	
	u64 num_a_strings = (u64) a_list[0];
	u64 num_b_strings = (u64) b_list[0];
	
	u64 a_str_i = 0;
	u64 b_str_i = 0;
	
	u64 a_i = 0;
	u64 b_i = 0;
	
	u64 min_count = (num_a_strings < num_b_strings) ? num_a_strings : num_b_strings;
	
	while (1)
	{
		char c_a = a_list[a_str_i + 1][a_i];
		char c_b = b_list[b_str_i + 1][b_i];
		
		if (c_a == 0)
		{
			if (a_str_i + 1 != min_count)
			{
				a_str_i += 1;
				a_i = 0;
				continue;
			}
			
			else
			{
				return c_a - c_b;
			}
		}
		
		if (c_b == 0)
		{
			if (b_str_i + 1 != min_count)
			{
				b_str_i += 1;
				b_i = 0;
				continue;
			}
			
			else
			{
				return c_a - c_b;
			}
		}
		
		if (c_a != c_b)
		{
			return c_a - c_b;
		}
		
		a_i += 1;
		b_i += 1;
	}
	
	EXC("um how lol\n");
	return 0;
}

int strcmp_list_a_not_b(u64 a_value, u64 b_value)
{
	char** a_list = (char**) a_value;
	char* b_str = (char*) b_value;
	
	u64 num_a_strings = (u64) a_list[0];
	
	u64 a_str_i = 0;
	
	u64 a_i = 0;
	u64 b_i = 0;
	
	while (1)
	{
		char c_a = a_list[a_str_i + 1][a_i];
		char c_b = b_str[b_i];
		
		if (c_a == 0)
		{
			if (a_str_i + 1 != num_a_strings)
			{
				a_str_i += 1;
				a_i = 0;
				continue;
			}
			
			else
			{
				return c_a - c_b;
			}
		}
		
		if (c_a != c_b)
		{
			return c_a - c_b;
		}
		
		a_i += 1;
		b_i += 1;
	}
	
	EXC("um how lol\n");
	return 0;
}

int strcmp_not_a_list_b(u64 a_value, u64 b_value)
{
	char* a_str = (char*) a_value;
	char** b_list = (char**) b_value;
	
	u64 num_b_strings = (u64) b_list[0];
	
	u64 b_str_i = 0;
	
	u64 a_i = 0;
	u64 b_i = 0;
	
	while (1)
	{
		char c_a = a_str[a_i];
		char c_b = b_list[b_str_i + 1][b_i];
		
		if (c_b == 0)
		{
			if (b_str_i + 1 != num_b_strings)
			{
				b_str_i += 1;
				b_i = 0;
				continue;
			}
			
			else
			{
				return c_a - c_b;
			}
		}
		
		if (c_a != c_b)
		{
			return c_a - c_b;
		}
		
		a_i += 1;
		b_i += 1;
	}
	
	EXC("um how lol\n");
	return 0;
}

void actionStringEquals(SWFAppContext* app_context, char* a_str, char* b_str)
{
	// Pop both raw values first so we can check types before conversion
	ActionVar a;
	popVar(app_context, &a);
	ActionVar b;
	popVar(app_context, &b);

	// Convert object operands via toString only (string hint — no valueOf fallback)
	if (a.type == ACTION_STACK_VALUE_OBJECT || a.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &a, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			a = ts;
		else
		{
			a.type = ACTION_STACK_VALUE_STRING;
			a.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}
	if (b.type == ACTION_STACK_VALUE_OBJECT || b.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &b, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			b = ts;
		else
		{
			b.type = ACTION_STACK_VALUE_STRING;
			b.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}

	// Convert non-string types to strings via the stack
	if (a.type != ACTION_STACK_VALUE_STRING && a.type != ACTION_STACK_VALUE_STR_LIST)
	{
		pushVar(app_context, &a);
		convertString(app_context, a_str);
		popVar(app_context, &a);
	}
	if (b.type != ACTION_STACK_VALUE_STRING && b.type != ACTION_STACK_VALUE_STR_LIST)
	{
		pushVar(app_context, &b);
		convertString(app_context, b_str);
		popVar(app_context, &b);
	}

	int cmp_result;

	int a_is_list = a.type == ACTION_STACK_VALUE_STR_LIST;
	int b_is_list = b.type == ACTION_STACK_VALUE_STR_LIST;

	if (a_is_list && b_is_list)
	{
		cmp_result = strcmp_list_a_list_b(a.data.numeric_value, b.data.numeric_value);
	}
	else if (a_is_list && !b_is_list)
	{
		cmp_result = strcmp_list_a_not_b(a.data.numeric_value, b.data.numeric_value);
	}
	else if (!a_is_list && b_is_list)
	{
		cmp_result = strcmp_not_a_list_b(a.data.numeric_value, b.data.numeric_value);
	}
	else
	{
		const char* sa = (const char*) a.data.numeric_value;
		const char* sb = (const char*) b.data.numeric_value;
		if (sa == NULL) sa = "";
		if (sb == NULL) sb = "";
		cmp_result = strcmp(sa, sb);
	}

	u64 result = (cmp_result == 0) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionStringLength(SWFAppContext* app_context, char* v_str)
{
	ActionVar v;
	convertString(app_context, v_str);
	popVar(app_context, &v);

	float str_size = (float) v.str_size;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &str_size));
}

void actionStringExtract(SWFAppContext* app_context, char* str_buffer)
{
	// Pop length
	convertFloat(app_context);
	ActionVar length_var;
	popVar(app_context, &length_var);
	int length = varToInt32(&length_var);

	// Pop index
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int index = varToInt32(&index_var);

	// Pop string
	char src_buffer[17];
	convertString(app_context, src_buffer);
	ActionVar src_var;
	popVar(app_context, &src_var);
	const char* src = src_var.data.string_data.owns_memory ?
		src_var.data.string_data.heap_ptr :
		(char*) src_var.data.numeric_value;

	// Get source string length
	int src_len = src_var.str_size;

	// Handle out-of-bounds index
	if (index < 0) index = 0;
	if (index >= src_len) {
		str_buffer[0] = '\0';
		PUSH_STR(str_buffer, 0);
		return;
	}

	// Handle out-of-bounds length
	if (length < 0) length = 0;
	if (index + length > src_len) {
		length = src_len - index;
	}

	// Extract substring
	int i;
	for (i = 0; i < length && i < 16; i++) {  // Limit to buffer size
		str_buffer[i] = src[index + i];
	}
	str_buffer[i] = '\0';

	// Push result
	PUSH_STR(str_buffer, i);
}

void actionMbStringLength(SWFAppContext* app_context, char* v_str)
{
	// Convert top of stack to string (if it's a number, converts it to string in v_str)
	convertString(app_context, v_str);

	// Get the string pointer from stack
	const unsigned char* str = (const unsigned char*) VAL(u64, &STACK_TOP_VALUE);

	// Pop the string value
	POP();

	// Count UTF-8 characters
	int count = 0;
	while (*str != '\0') {
		// Check UTF-8 sequence length
		if ((*str & 0x80) == 0) {
			// 1-byte sequence (0xxxxxxx)
			str += 1;
		} else if ((*str & 0xE0) == 0xC0) {
			// 2-byte sequence (110xxxxx)
			str += 2;
		} else if ((*str & 0xF0) == 0xE0) {
			// 3-byte sequence (1110xxxx)
			str += 3;
		} else if ((*str & 0xF8) == 0xF0) {
			// 4-byte sequence (11110xxx)
			str += 4;
		} else {
			// Invalid UTF-8, skip one byte
			str += 1;
		}
		count++;
	}

	// Push result
	float result = (float)count;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionMbStringExtract(SWFAppContext* app_context, char* str_buffer)
{
	// Pop count (number of characters to extract)
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);
	int count = varToInt32(&count_var);

	// Pop index (starting character position)
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int index = varToInt32(&index_var);

	// Pop string
	char input_buffer[17];
	convertString(app_context, input_buffer);
	ActionVar src_var;
	popVar(app_context, &src_var);
	const char* src = src_var.data.string_data.owns_memory ?
		src_var.data.string_data.heap_ptr :
		(char*) src_var.data.numeric_value;

	// If index or count are invalid, return empty string
	if (index < 0 || count < 0) {
		str_buffer[0] = '\0';
		PUSH_STR(str_buffer, 0);
		return;
	}

	// Navigate to starting character position (UTF-8 aware)
	const unsigned char* str = (const unsigned char*)src;
	int current_char = 0;

	// Skip to index'th character
	while (*str != '\0' && current_char < index) {
		// Advance by one UTF-8 character
		if ((*str & 0x80) == 0) {
			str += 1;  // 1-byte character
		} else if ((*str & 0xE0) == 0xC0) {
			str += 2;  // 2-byte character
		} else if ((*str & 0xF0) == 0xE0) {
			str += 3;  // 3-byte character
		} else if ((*str & 0xF8) == 0xF0) {
			str += 4;  // 4-byte character
		} else {
			str += 1;  // Invalid, skip one byte
		}
		current_char++;
	}

	// If we reached end of string before index, return empty
	if (*str == '\0') {
		str_buffer[0] = '\0';
		PUSH_STR(str_buffer, 0);
		return;
	}

	// Extract count characters
	const unsigned char* start = str;
	current_char = 0;

	while (*str != '\0' && current_char < count) {
		// Advance by one UTF-8 character
		if ((*str & 0x80) == 0) {
			str += 1;
		} else if ((*str & 0xE0) == 0xC0) {
			str += 2;
		} else if ((*str & 0xF0) == 0xE0) {
			str += 3;
		} else if ((*str & 0xF8) == 0xF0) {
			str += 4;
		} else {
			str += 1;
		}
		current_char++;
	}

	// Copy substring to buffer
	int length = str - start;
	if (length > 16) length = 16;  // Buffer size limit
	memcpy(str_buffer, start, length);
	str_buffer[length] = '\0';

	// Push result
	PUSH_STR(str_buffer, length);
}

void actionCharToAscii(SWFAppContext* app_context)
{
	// Convert top of stack to string
	char str_buffer[17];
	convertString(app_context, str_buffer);

	// Pop the string value
	ActionVar v;
	popVar(app_context, &v);

	// Get pointer to the string
	const char* str = (const char*) v.data.numeric_value;

	// Handle empty string edge case
	if (str == NULL || str[0] == '\0' || v.str_size == 0) {
		// Push NaN for empty string (Flash behavior)
		float result = 0.0f / 0.0f;  // NaN
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Get ASCII/Unicode code of first character
	// Use unsigned char to ensure values 128-255 are handled correctly
	float code = (float)(unsigned char)str[0];

	// Push result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &code));
}

void actionStringAdd(SWFAppContext* app_context, char* a_str, char* b_str)
{
	ActionVar a;
	convertString(app_context, a_str);
	peekVar(app_context, &a);
	
	ActionVar b;
	convertString(app_context, b_str);
	peekSecondVar(app_context, &b);
	
	u64 num_a_strings;
	u64 num_b_strings;
	u64 num_strings = 0;
	
	if (b.type == ACTION_STACK_VALUE_STR_LIST)
	{
		num_b_strings = *((u64*) b.data.numeric_value);
	}
	
	else
	{
		num_b_strings = 1;
	}
	
	num_strings += num_b_strings;
	
	if (a.type == ACTION_STACK_VALUE_STR_LIST)
	{
		num_a_strings = *((u64*) a.data.numeric_value);
	}
	
	else
	{
		num_a_strings = 1;
	}
	
	num_strings += num_a_strings;
	
	PUSH_STR_LIST(b.str_size + a.str_size, (u32) sizeof(u64)*(num_strings + 1));
	
	u64* str_list = (u64*) &STACK_TOP_VALUE;
	str_list[0] = num_strings;
	
	if (b.type == ACTION_STACK_VALUE_STR_LIST)
	{
		u64* b_list = (u64*) b.data.numeric_value;
		
		for (u64 i = 0; i < num_b_strings; ++i)
		{
			str_list[i + 1] = b_list[i + 1];
		}
	}
	
	else
	{
		str_list[1] = b.data.numeric_value;
	}
	
	if (a.type == ACTION_STACK_VALUE_STR_LIST)
	{
		u64* a_list = (u64*) a.data.numeric_value;
		
		for (u64 i = 0; i < num_a_strings; ++i)
		{
			str_list[i + 1 + num_b_strings] = a_list[i + 1];
		}
	}
	
	else
	{
		str_list[1 + num_b_strings] = a.data.numeric_value;
	}
}

// ==================================================================
// MovieClip Control Actions
// ==================================================================

void actionNextFrame(SWFAppContext* app_context)
{
	(void)app_context;  // Not used but required for consistent API
	// Advance to the next frame
	extern size_t current_frame;
	extern size_t next_frame;
	extern int manual_next_frame;

	next_frame = current_frame + 1;
	manual_next_frame = 1;
}

/**
 * ActionPlay - Start playing from the current frame
 *
 * Opcode: 0x06
 * SWF version: 3+
 * Stack: [] -> [] (no stack operations)
 *
 * Description:
 *   Instructs the Flash Player to start playing at the current frame.
 *   The timeline will advance automatically on each frame tick after
 *   this action is executed.
 *
 * Behavior:
 *   - Sets the global playing state to true (is_playing = 1)
 *   - Timeline advances to next frame on next tick
 *   - If already playing, this is a no-op (safe to call multiple times)
 *   - Opposite of ActionStop (0x07)
 *
 * Implementation notes (NO_GRAPHICS mode):
 *   - Only affects the main timeline in current implementation
 *   - SetTarget support for controlling individual sprites/MovieClips
 *     is not yet implemented (requires MovieClip architecture)
 *   - Frame advancement is handled by the frame loop in swf_core.c
 *   - The frame loop checks is_playing and breaks if it's 0
 *
 * Edge cases handled:
 *   - Play when already playing: No-op, safe behavior
 *   - Multiple consecutive play calls: All are no-ops, state stays 1
 *   - Play after stop: Resumes playback from current frame
 *
 * Limitations:
 *   - SetTarget not supported: Cannot control individual sprite timelines
 *   - Only one global playing state: All timelines share the same state
 *
 * See also:
 *   - actionStop() / ActionStop (0x07): Stop playback
 *   - swf_core.c: Frame loop that checks is_playing
 */
void actionPlay(SWFAppContext* app_context)
{
	(void)app_context;
#ifndef NO_GRAPHICS
	if (targeted_sprite != NULL)
	{
		targeted_sprite->sprite_is_playing = 1;
		return;
	}
#endif
	is_playing = 1;
}

void actionStop(SWFAppContext* app_context)
{
	(void)app_context;
#ifndef NO_GRAPHICS
	if (targeted_sprite != NULL)
	{
		targeted_sprite->sprite_is_playing = 0;
		return;
	}
#endif
	is_playing = 0;
}

void actionTrace(SWFAppContext* app_context)
{
	if (g_execution_halted) { POP(); return; }

	ActionStackValueType type = STACK_TOP_TYPE;

	switch (type)
	{
		case ACTION_STACK_VALUE_STRING:
		{
			printf("%s\n", (char*) STACK_TOP_VALUE);
			break;
		}

		case ACTION_STACK_VALUE_STR_LIST:
		{
			u64* str_list = (u64*) &STACK_TOP_VALUE;

			for (u64 i = 0; i < str_list[0]; ++i)
			{
				printf("%s", (char*) str_list[i + 1]);
			}

			printf("\n");

			break;
		}

		case ACTION_STACK_VALUE_F32:
		{
			float f = VAL(float, &STACK_TOP_VALUE);
			if (isnan(f)) printf("NaN\n");
			else if (isinf(f)) printf("%sInfinity\n", f < 0 ? "-" : "");
			else if (f == 0.0f) printf("0\n");
			else printf("%.15g\n", f);
			break;
		}

		case ACTION_STACK_VALUE_F64:
		{
			double d = VAL(double, &STACK_TOP_VALUE);
			if (isnan(d)) printf("NaN\n");
			else if (isinf(d)) printf("%sInfinity\n", d < 0 ? "-" : "");
			else if (d == 0.0) printf("0\n");
			else printf("%.15g\n", d);
			break;
		}

		case ACTION_STACK_VALUE_UNDEFINED:
		{
			printf("undefined\n");
			break;
		}

		case ACTION_STACK_VALUE_BOOLEAN:
		{
#if defined(SWF_VERSION) && SWF_VERSION < 5
			printf("%d\n", STACK_TOP_VALUE ? 1 : 0);
#else
			printf("%s\n", STACK_TOP_VALUE ? "true" : "false");
#endif
			break;
		}

		case ACTION_STACK_VALUE_NULL:
		{
			printf("null\n");
			break;
		}

		case ACTION_STACK_VALUE_FUNCTION:
		{
			printf("[type Function]\n");
			break;
		}

		case ACTION_STACK_VALUE_MOVIECLIP:
		{
			// MovieClip traces as its target path
			// TODO: use actual target path for non-root MovieClips
			printf("_level0\n");
			break;
		}

		case ACTION_STACK_VALUE_OBJECT:
		{
			// Flash's trace() calls toString on objects:
			// - toString found, returns string → print that string
			//   (e.g. Object.prototype.toString returns "[object Object]")
			// - toString found, returns non-string → "[type Object]"
			// - no toString found → "[type Object]"
			ActionVar obj_var;
			obj_var.type = STACK_TOP_TYPE;
			obj_var.data.numeric_value = STACK_TOP_VALUE;
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &obj_var, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			{
				const char* s = (const char*) ts.data.numeric_value;
				printf("%s\n", s ? s : "");
			}
			else
			{
				printf("[type Object]\n");
			}
			break;
		}

		case ACTION_STACK_VALUE_ARRAY:
		{
			// Print array as comma-separated values using join(",")
			ASArray* arr = (ASArray*) STACK_TOP_VALUE;
			if (arr != NULL)
			{
				// Use callArrayMethod toString for consistent formatting
				ActionVar comma_arg = {0};
				comma_arg.type = ACTION_STACK_VALUE_STRING;
				comma_arg.str_size = 1;
				VAL(u64, &comma_arg.data.numeric_value) = (u64) ",";
				callArrayMethod(app_context, arr, "join", 4, &comma_arg, 1);
				// The result is on the stack — print it
				if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
				{
					const char* s = (const char*) VAL(u64, &STACK_TOP_VALUE);
					if (s) printf("%s", s);
				}
				POP();
			}
			printf("\n");
			break;
		}

		default:
		{
			// Unknown type - print nothing but don't crash
			printf("\n");
			break;
		}
	}

	fflush(stdout);

	POP();
}

/**
 * ActionGotoFrame - Go to specified frame and stop
 *
 * Opcode: 0x81
 * SWF Version: 3+
 *
 * Jumps to the specified frame in the timeline and stops playback.
 * This implements the "gotoAndStop" semantics - the timeline will
 * jump to the target frame and halt there.
 *
 * Frame indexing: The frame parameter is 0-based (frame 0 is the first frame).
 *
 * Behavior:
 * - Sets next_frame to the specified frame index
 * - Sets manual_next_frame flag to trigger the jump
 * - Sets is_playing = 0 to stop playback at the target frame
 * - Validates frame boundaries (frame must be < g_frame_count)
 * - If frame is out of bounds, ignores the jump (continues current frame)
 *
 * @param stack - Pointer to the runtime stack (unused but required for API consistency)
 * @param sp - Pointer to stack pointer (unused but required for API consistency)
 * @param frame - Target frame index (0-based)
 */
/**
 * utf8_strlen - Count the number of Unicode characters in a UTF-8 string.
 * Continuation bytes (0x80-0xBF) are skipped, so multi-byte characters count as 1.
 */
static size_t utf8_strlen(const char* str)
{
	size_t count = 0;
	for (const unsigned char* p = (const unsigned char*)str; *p; ++p)
	{
		// Count only non-continuation bytes (leading bytes start a new character)
		if ((*p & 0xC0) != 0x80)
			count++;
	}
	return count;
}

void actionGotoFrame(SWFAppContext* app_context, u16 frame)
{
	(void)app_context;

#ifndef NO_GRAPHICS
	if (targeted_sprite != NULL)
	{
		targeted_sprite->sprite_next_frame = frame;
		targeted_sprite->sprite_manual_next_frame = 1;
		targeted_sprite->sprite_is_playing = 0;
		return;
	}
#endif

	extern size_t current_frame;
	extern size_t next_frame;
	extern int manual_next_frame;
	extern int is_playing;
	extern size_t g_frame_count;

	if (frame >= g_frame_count)
	{
		return;
	}

	next_frame = frame;
	manual_next_frame = 1;
	is_playing = 0;

	// Update _currentframe immediately so scripts can read the new value
	root_movieclip.currentframe = frame + 1;  // 1-indexed
}

/**
 * findFrameByLabel - Lookup frame number by label
 *
 * Searches the frame_label_data array (generated by SWFRecomp) for a matching label.
 * Returns the frame index if found, -1 otherwise.
 *
 * @param label - The frame label to search for
 * @return Frame index (0-based) or -1 if not found
 */
int findFrameByLabel(const char* label)
{
	if (!label)
	{
		return -1;
	}

	// Extern declarations for generated frame label data
	typedef struct {
		const char* label;
		size_t frame;
	} FrameLabelEntry;

	extern FrameLabelEntry frame_label_data[];
	extern size_t frame_label_count;

	// Search through frame labels
	for (size_t i = 0; i < frame_label_count; i++)
	{
		if (frame_label_data[i].label && strcmp(frame_label_data[i].label, label) == 0)
		{
			return (int)frame_label_data[i].frame;
		}
	}

	return -1;  // Not found
}

/**
 * ActionGoToLabel - Navigate to a frame by its label
 *
 * Looks up the frame number associated with the specified label and jumps to that frame.
 * If the label is not found, the action is ignored (per Flash spec).
 *
 * Frame labels are defined in the SWF file using FrameLabel tags and extracted
 * by SWFRecomp during compilation.
 *
 * @param stack - The execution stack (unused)
 * @param sp - Stack pointer (unused)
 * @param label - The frame label to navigate to
 */
void actionGoToLabel(SWFAppContext* app_context, const char* label)
{
	extern size_t next_frame;
	extern int manual_next_frame;
	extern int is_playing;

	// Debug output
	printf("// GoToLabel: %s\n", label ? label : "(null)");
	fflush(stdout);

	if (!label)
	{
		return;
	}

	// Look up frame by label
	int frame_index = findFrameByLabel(label);

	if (frame_index >= 0)
	{
		// Navigate to the frame
		next_frame = (size_t)frame_index;
		manual_next_frame = 1;

		// Stop playback (like gotoAndStop)
		is_playing = 0;

		// Note: Actual navigation will occur in the frame loop
	}
	// If label not found, ignore (per Flash spec - no action taken)
}

/**
 * ActionGotoFrame2 - Stack-based frame navigation
 *
 * Stack: [ frame_identifier ] -> [ ]
 *
 * Pops a frame identifier (number or string) from the stack and navigates
 * to that frame. The Play flag controls whether to stop or continue playing.
 *
 * Frame identifier can be:
 * - A number: Frame index (0-based)
 * - A string: Frame label, optionally prefixed with target path (e.g., "/MovieClip:label")
 *
 * Edge cases:
 * - Negative frame numbers: Treated as frame 0
 * - Invalid frame types: Ignored with warning
 * - Nonexistent labels: Ignored (spec says action is ignored)
 * - Target paths: Parsed but not fully supported in NO_GRAPHICS mode
 *
 * SWF version: 4+
 * Opcode: 0x9F
 *
 * @param stack Pointer to the runtime stack
 * @param sp Pointer to stack pointer
 * @param play_flag 0 = go to frame and stop, 1 = go to frame and play
 * @param scene_bias Number to add to numeric frame (for multi-scene movies)
 */
void actionGotoFrame2(SWFAppContext* app_context, u8 play_flag, u16 scene_bias)
{
	// Pop frame identifier from stack
	ActionVar frame_var;
	popVar(app_context, &frame_var);

	// Resolve frame number from stack value
	s32 frame_num = -1;
	int resolved = 0;

	if (frame_var.type == ACTION_STACK_VALUE_F32) {
		float frame_float;
		memcpy(&frame_float, &frame_var.data.numeric_value, sizeof(float));
		frame_num = (s32)frame_float;
		resolved = 1;
	}
	else if (frame_var.type == ACTION_STACK_VALUE_F64) {
		double frame_double;
		memcpy(&frame_double, &frame_var.data.numeric_value, sizeof(double));
		frame_num = (s32)frame_double;
		resolved = 1;
	}
	else if (frame_var.type == ACTION_STACK_VALUE_I32) {
		s32 frame_int;
		memcpy(&frame_int, &frame_var.data.numeric_value, sizeof(s32));
		frame_num = frame_int;
		resolved = 1;
	}
	else if (frame_var.type == ACTION_STACK_VALUE_BOOLEAN) {
		frame_num = (s32)(frame_var.data.numeric_value & 1);
		resolved = 1;
	}
	else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
		const char* frame_str = (const char*)frame_var.data.numeric_value;
		if (frame_str == NULL) return;

		// Parse target path if present (format: "target:frame" or "/target:frame")
		const char* frame_part = frame_str;
		const char* colon = strchr(frame_str, ':');

		if (colon != NULL) {
			frame_part = colon + 1;
		}

		// Check if frame_part is numeric
		char* endptr;
		long parsed = strtol(frame_part, &endptr, 10);

		if (endptr != frame_part && *endptr == '\0') {
			frame_num = (s32)parsed;
			resolved = 1;
		}
		// else: frame label — not yet supported
	}

	if (!resolved) {
		// Undefined, null, or unsupported type — silently ignore
		return;
	}

	if (frame_num < 0) frame_num = 0;
	frame_num += scene_bias;

	// Navigate: GotoFrame2 uses 1-based frame numbers, actionGotoFrame uses 0-based
	actionGotoFrame(app_context, (u16)(frame_num - 1));

	if (play_flag) {
		is_playing = 1;
	}
}

/**
 * actionEndDrag - Stops dragging the currently dragged sprite/MovieClip
 *
 * Opcode: 0x28 (ActionEndDrag)
 * Stack: [] -> []
 *
 * Ends the drag operation in progress, if any. If no sprite is being dragged,
 * this operation has no effect.
 *
 * In NO_GRAPHICS mode, this updates the drag state tracking but does not
 * perform actual sprite/mouse interaction.
 */
void actionEndDrag(SWFAppContext* app_context)
{
	// Clear drag state
	if (is_dragging) {
		#ifdef DEBUG
		printf("[EndDrag] Stopping drag of '%s'\n",
			   dragged_target ? dragged_target : "(null)");
		#endif

		is_dragging = 0;

		// Free the dragged target name if it was allocated
		if (dragged_target) {
			free(dragged_target);
			dragged_target = NULL;
		}

		#ifndef NO_GRAPHICS
		// In graphics mode, additional cleanup would happen here:
		// - Stop updating sprite position with mouse
		// - Re-enable normal sprite behavior
		// - Update display list
		#endif
	} else {
		#ifdef DEBUG
		printf("[EndDrag] No drag in progress\n");
		#endif
	}

	// No stack operations - END_DRAG has no parameters
	(void)app_context;  // Suppress unused parameter warning
}

/**
 * ActionStopSounds - Stops all currently playing sounds
 *
 * Stack: [ ... ] -> [ ... ] (no stack changes)
 *
 * Instructs Flash Player to stop playing all sounds. This operation:
 * - Stops all currently playing audio across all timelines
 * - Has global effect (not affected by SetTarget)
 * - Does not prevent new sounds from playing
 * - Has no effect on the stack
 * - Has no parameters
 *
 * Implementation notes:
 * - NO_GRAPHICS mode: This is a no-op (no audio system available)
 * - Full graphics mode: Would interface with audio subsystem to stop all channels
 *
 * SWF version: 4+
 * Opcode: 0x09
 *
 * @param stack Pointer to the runtime stack (unused - no stack operations)
 * @param sp Pointer to stack pointer (unused - no stack operations)
 */
void actionStopSounds(SWFAppContext* app_context)
{
	#ifndef NO_GRAPHICS
	tagStopAllSounds(app_context);
	#else
	(void)app_context;
	#endif
}

/**
 * ActionGetURL - Load a URL into browser frame or Flash level
 *
 * Opcode: 0x83
 * SWF Version: 3+
 *
 * Instructs Flash Player to get the URL specified by the url parameter.
 * The URL can be any type: HTML file, image, or another SWF file.
 * If playing in a browser, the URL is displayed in the frame specified by target.
 *
 * Special targets:
 * - "_blank": Open in new window
 * - "_self": Open in current window/frame
 * - "_parent": Open in parent frame
 * - "_top": Open in top-level frame
 * - "_level0", "_level1", etc.: Load SWF into Flash Player level
 * - Named string: Open in named frame/window
 *
 * Current Implementation:
 * This is a simplified implementation for NO_GRAPHICS mode that logs the URL
 * request to stdout. Full implementation would require:
 * - Browser integration or HTTP client for web URLs
 * - SWF loader for _level targets
 * - Frame/window management for browser targets
 *
 * Edge cases handled:
 * - Null URL or target (logged as "(null)")
 * - Empty strings (logged as-is)
 *
 * @param stack Pointer to the runtime stack (unused in current implementation)
 * @param sp Pointer to stack pointer (unused in current implementation)
 * @param url The URL to load (can be relative or absolute)
 * @param target The target window/frame/level
 */
void actionGetURL(SWFAppContext* app_context, const char* url, const char* target)
{
	// Handle null pointers
	const char* safe_url = url ? url : "(null)";
	const char* safe_target = target ? target : "(null)";

	// Log the URL request for verification in NO_GRAPHICS mode
	// Format: "// GetURL: <url> -> <target>"
	printf("// GetURL: %s -> %s\n", safe_url, safe_target);

	// Note: Full implementation would check target type and dispatch accordingly:
	// - _level targets: Load SWF file into specified level
	// - Browser targets (_blank, _self, etc.): Open in browser window/frame
	// - Named targets: Open in named frame/window
	// - JavaScript URLs: Execute JavaScript (if enabled)
	// - Security: Check cross-domain policy, validate URL scheme
}

void actionGetVariable(SWFAppContext* app_context)
{
	// Read variable name info from stack
	// Stack layout for strings: +0=type, +4=oldSP, +8=length, +12=string_id, +16=pointer
	u32 string_id = VAL(u32, &STACK[SP + 12]);
	char* var_name = (char*) VAL(u64, &STACK[SP + 16]);
	u32 var_name_len = VAL(u32, &STACK[SP + 8]);

	// Pop variable name
	POP();

	// Check virtual property table first (addProperty getters)
	{
		VirtualProperty* vp = findVirtualProperty(var_name, var_name_len);
		if (vp != NULL && vp->getter != NULL)
		{
			ActionVar result = invokeSpecialFunction(app_context, vp->getter, NULL);
			pushVar(app_context, &result);
			return;
		}
	}

	// First check scope chain (innermost to outermost)
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			// Try to find property in this scope object
			ActionVar* prop = getProperty(scope_chain[i], var_name, var_name_len);
			if (prop != NULL)
			{
				// Found in scope chain - push its value
				PUSH_VAR(prop);
				return;
			}
		}
	}

	// Not found in scope chain - check global variables
	ActionVar* var = NULL;
	if (string_id != 0)
	{
		// Constant string - use array (O(1))
		var = getVariableById(string_id);

		// Fall back to hashmap if array lookup doesn't find the variable
		// (This can happen for catch variables that are set by name but have a string ID)
		if (var == NULL || (var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0))
		{
			var = getVariable(var_name, var_name_len);
		}
	}
	else
	{
		// Dynamic string - use hashmap (O(n))
		var = getVariable(var_name, var_name_len);
	}

	if (!var || (var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0))
	{
#if !defined(SWF_VERSION) || SWF_VERSION >= 5
		// Check special variables (SWF5+ only — SWF4 has no built-in constants)
		if (var_name_len == 4 && strncmp(var_name, "this", 4) == 0)
		{
			// "this" refers to the current object context (root MovieClip)
			extern MovieClip root_movieclip;
			PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)&root_movieclip);
			return;
		}

		// _root and _level0 both refer to the root MovieClip
		if ((var_name_len == 5 && strncmp(var_name, "_root", 5) == 0) ||
		    (var_name_len == 7 && strncmp(var_name, "_level0", 7) == 0))
		{
			extern MovieClip root_movieclip;
			PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)&root_movieclip);
			return;
		}

		// Check built-in global constants
		if (var_name_len == 3 && strncmp(var_name, "NaN", 3) == 0)
		{
			double nan_val = NAN;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &nan_val));
			return;
		}
		else if (var_name_len == 8 && strncmp(var_name, "Infinity", 8) == 0)
		{
			double inf_val = INFINITY;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &inf_val));
			return;
		}
		else if (var_name_len == 9 && strncmp(var_name, "undefined", 9) == 0)
		{
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			return;
		}
		else if (var_name_len == 4 && strncmp(var_name, "null", 4) == 0)
		{
			PUSH(ACTION_STACK_VALUE_NULL, 0);
			return;
		}
		else if (var_name_len == 7 && strncmp(var_name, "_global", 7) == 0)
		{
			extern ASObject* global_object;
			if (global_object == NULL)
			{
				global_object = allocObject(app_context, 16);
			}
			// Lazily add valueOf=undefined (heap must be ready for HALLOC)
			static int global_valueOf_set = 0;
			if (!global_valueOf_set)
			{
				ActionVar undef_val = {0};
				undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
				setProperty(app_context, global_object, "valueOf", 7, &undef_val);
				global_valueOf_set = 1;
			}
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)global_object);
			return;
		}
		else if (var_name_len == 6 && strncmp(var_name, "System", 6) == 0)
		{
			// Lazily create System built-in object
			static ASObject* system_object = NULL;
			if (system_object == NULL)
			{
				system_object = allocObject(app_context, 4);
				ASObject* security_obj = allocObject(app_context, 4);
				ActionVar sandbox_val = {0};
				sandbox_val.type = ACTION_STACK_VALUE_STRING;
				sandbox_val.str_size = 13;
				VAL(u64, &sandbox_val.data.numeric_value) = (u64)"localWithFile";
				setProperty(app_context, security_obj, "sandboxType", 11, &sandbox_val);
				ActionVar security_var = {0};
				security_var.type = ACTION_STACK_VALUE_OBJECT;
				VAL(u64, &security_var.data.numeric_value) = (u64)security_obj;
				setProperty(app_context, system_object, "security", 8, &security_var);
			}
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)system_object);
			return;
		}
#endif

		// Variable not found
#if defined(SWF_VERSION) && SWF_VERSION >= 6
		// SWF6+: undefined variables return undefined
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
#else
		// SWF < 6: undefined variables return empty string
		PUSH_STR("", 0);
#endif
		return;
	}

	// Push variable value to stack
	PUSH_VAR(var);
}

void actionSetVariable(SWFAppContext* app_context)
{
	// Stack layout: [name, value] <- sp
	// According to spec: Pop value first, then name
	// So VALUE is at top (*sp), NAME is at second (SP_SECOND_TOP)

	u32 value_sp = SP;
	u32 var_name_sp = SP_SECOND_TOP;

	// Read variable name info
	// Stack layout for strings: +0=type, +4=oldSP, +8=length, +12=string_id, +16=pointer
	u32 string_id = VAL(u32, &STACK[var_name_sp + 12]);

	char* var_name = (char*) VAL(u64, &STACK[var_name_sp + 16]);

	u32 var_name_len = VAL(u32, &STACK[var_name_sp + 8]);

	// Check virtual property table first (addProperty setters)
	{
		VirtualProperty* vp = findVirtualProperty(var_name, var_name_len);
		if (vp != NULL && vp->setter != NULL)
		{
			// Pop the value from stack and invoke setter with it
			ActionVar value_var;
			peekVar(app_context, &value_var);
			POP_2();
			invokeSpecialFunction(app_context, vp->setter, &value_var);
			return;
		}
	}

	// First check scope chain (innermost to outermost)
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			// Try to find property in this scope object
			ActionVar* prop = getProperty(scope_chain[i], var_name, var_name_len);
			if (prop != NULL)
			{
				// Found in scope chain - set it there
				ActionVar value_var;
				peekVar(app_context, &value_var);
				setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var);

				// Pop both value and name
				POP_2();
				return;
			}
		}
	}

	// Not found in scope chain - set as global variable

	ActionVar* var;
	if (string_id != 0)
	{
		// Constant string - use array (O(1))
		var = getVariableById(string_id);
	}
	else
	{
		// Dynamic string - use hashmap (O(n))
		var = getVariable(var_name, var_name_len);
	}

	if (!var)
	{
		// Failed to get/create variable
		POP_2();
		return;
	}

	// Set variable value (uses existing string materialization!)
	setVariableWithValue(var, STACK, value_sp);

	// Pop both value and name
	POP_2();
}

void actionDefineLocal(SWFAppContext* app_context)
{
	// Stack layout: [name, value] <- sp
	// According to AS2 spec for DefineLocal:
	// Pop value first, then name
	// So VALUE is at top (*sp), NAME is at second (SP_SECOND_TOP)

	u32 value_sp = SP;
	u32 var_name_sp = SP_SECOND_TOP;

	// Read variable name info
	// Stack layout for strings: +0=type, +4=oldSP, +8=length, +12=string_id, +16=pointer
	u32 string_id = VAL(u32, &STACK[var_name_sp + 12]);
	char* var_name = (char*) VAL(u64, &STACK[var_name_sp + 16]);
	u32 var_name_len = VAL(u32, &STACK[var_name_sp + 8]);

	// DefineLocal ALWAYS creates/updates in the local scope
	// If there's a scope object (function context), define it there
	// Otherwise, fall back to global scope (for testing without full function support)

	if (scope_depth > 0 && scope_chain[scope_depth - 1] != NULL)
	{
		// We have a local scope object - define variable as a property
		ASObject* local_scope = scope_chain[scope_depth - 1];

		ActionVar value_var;
		peekVar(app_context, &value_var);

		// Set property on the local scope object
		// This will create the property if it doesn't exist, or update if it does
		setProperty(app_context, local_scope, var_name, var_name_len, &value_var);

		// Pop both value and name
		POP_2();
		return;
	}

	// No local scope - fall back to global variable
	// This allows testing DefineLocal without full function infrastructure
	ActionVar* var;
	if (string_id != 0)
	{
		// Constant string - use array (O(1))
		var = getVariableById(string_id);
	}
	else
	{
		// Dynamic string - use hashmap (O(n))
		var = getVariable(var_name, var_name_len);
	}

	if (!var)
	{
		// Failed to get/create variable
		POP_2();
		return;
	}

	// Set variable value
	setVariableWithValue(var, STACK, value_sp);

	// Pop both value and name
	POP_2();
}

void actionDeclareLocal(SWFAppContext* app_context)
{
	// DECLARE_LOCAL pops only the variable name (no value)
	// It declares a local variable initialized to undefined

	// Stack layout: [name] <- sp

	// Read variable name info
	u32 string_id = VAL(u32, &STACK[SP + 12]);
	char* var_name = (char*) VAL(u64, &STACK[SP + 16]);
	u32 var_name_len = VAL(u32, &STACK[SP + 8]);

	// Check if we're in a local scope (function context)
	if (scope_depth > 0 && scope_chain[scope_depth - 1] != NULL)
	{
		// We have a local scope object - declare variable as undefined property
		ASObject* local_scope = scope_chain[scope_depth - 1];

		// Create an undefined value
		ActionVar undefined_var;
		undefined_var.type = ACTION_STACK_VALUE_UNDEFINED;
		undefined_var.str_size = 0;
		undefined_var.data.numeric_value = 0;

		// Set property on the local scope object
		// This will create the property if it doesn't exist
		setProperty(app_context, local_scope, var_name, var_name_len, &undefined_var);

		// Pop the name
		POP();
		return;
	}

	// Not in a function - show warning and treat as no-op
	// (In AS2, DECLARE_LOCAL outside a function is technically invalid)
	printf("Warning: DECLARE_LOCAL outside function for variable '%s'\n", var_name);

	// Pop the name
	POP();
}

void actionSetTarget2(SWFAppContext* app_context)
{
	// Convert top of stack to string if needed
	char str_buffer[17];
	convertString(app_context, str_buffer);

	// Get target path from stack
	const char* target_path = (const char*) VAL(u64, &STACK_TOP_VALUE);

	// Pop the target path
	POP();

	// Delegate to actionSetTarget for unified resolution logic
	actionSetTarget(app_context, target_path ? target_path : "");
}

void actionGetProperty(SWFAppContext* app_context)
{
	// Pop property index
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int prop_index = varToInt32(&index_var);

	// Pop target path
	convertString(app_context, NULL);
	const char* target = (const char*) VAL(u64, &STACK_TOP_VALUE);
	POP();

	// Get the MovieClip object
	MovieClip* mc = getMovieClipByTarget(target);

	// Get property value based on index
	float value = 0.0f;
	const char* str_value = NULL;
	int is_string = 0;

	switch (prop_index) {
		case 0:  // _x
			value = mc ? mc->x : 0.0f;
			break;
		case 1:  // _y
			value = mc ? mc->y : 0.0f;
			break;
		case 2:  // _xscale
			value = mc ? mc->xscale : 100.0f;
			break;
		case 3:  // _yscale
			value = mc ? mc->yscale : 100.0f;
			break;
		case 4:  // _currentframe
			value = mc ? (float)mc->currentframe : 1.0f;
			break;
		case 5:  // _totalframes
			value = mc ? (float)mc->totalframes : 1.0f;
			break;
		case 6:  // _alpha
			value = mc ? mc->alpha : 100.0f;
			break;
		case 7:  // _visible
			value = mc ? (mc->visible ? 1.0f : 0.0f) : 1.0f;
			break;
		case 8:  // _width
			value = mc ? mc->width : 0.0f;
			break;
		case 9:  // _height
			value = mc ? mc->height : 0.0f;
			break;
		case 10: // _rotation
			value = mc ? mc->rotation : 0.0f;
			break;
		case 11: // _target
			str_value = mc ? mc->target : "";
			is_string = 1;
			break;
		case 12: // _framesloaded
			value = mc ? (float)mc->framesloaded : 1.0f;
			break;
		case 13: // _name
			str_value = mc ? mc->name : "";
			is_string = 1;
			break;
		case 14: // _droptarget
			str_value = mc ? mc->droptarget : "";
			is_string = 1;
			break;
		case 15: // _url
			str_value = mc ? mc->url : "";
			is_string = 1;
			break;
		case 16: // _highquality
			value = mc ? (float)mc->highquality : 1.0f;
			break;
		case 17: // _focusrect
			value = mc ? (float)mc->focusrect : 1.0f;
			break;
		case 18: // _soundbuftime
			value = mc ? mc->soundbuftime : 5.0f;
			break;
		case 19: // _quality (returns numeric: 0=LOW, 1=MEDIUM, 2=HIGH, 3=BEST)
			// Convert quality string to numeric value
			if (mc) {
				if (strcmp(mc->quality, "LOW") == 0) {
					value = 0.0f;
				} else if (strcmp(mc->quality, "MEDIUM") == 0) {
					value = 1.0f;
				} else if (strcmp(mc->quality, "HIGH") == 0) {
					value = 2.0f;
				} else if (strcmp(mc->quality, "BEST") == 0) {
					value = 3.0f;
				} else {
					value = 2.0f;  // Default to HIGH
				}
			} else {
				value = 2.0f;  // Default to HIGH
			}
			break;
		case 20: // _xmouse (SWF 5+)
			value = mc ? mc->xmouse : 0.0f;
			break;
		case 21: // _ymouse (SWF 5+)
			value = mc ? mc->ymouse : 0.0f;
			break;
		default:
			// Unknown property - push 0
			value = 0.0f;
			break;
	}

	// Push result
	if (is_string) {
		PUSH_STR(str_value, strlen(str_value));
	} else {
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
	}
}

void actionRandomNumber(SWFAppContext* app_context)
{
	// Pop maximum value
	convertFloat(app_context);
	ActionVar max_var;
	popVar(app_context, &max_var);
	int max = varToInt32(&max_var);

	// Generate random number using avmplus-compatible RNG
	// This matches Flash Player's exact behavior for speedrunners
	int random_val = Random(max, &global_random_state);

	// Push result as float
	float result = (float) random_val;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionAsciiToChar(SWFAppContext* app_context, char* str_buffer)
{
	// Convert top of stack to number
	convertFloat(app_context);

	// Pop the numeric value
	ActionVar a;
	popVar(app_context, &a);

	// Get integer code (truncate decimal)
	int code = varToInt32(&a);

	// Handle out-of-range values (wrap to 0-255)
	code = code & 0xFF;

	// Create single-character string
	str_buffer[0] = (char)code;
	str_buffer[1] = '\0';

	// Push result string
	PUSH_STR(str_buffer, 1);
}

void actionMbCharToAscii(SWFAppContext* app_context, char* str_buffer)
{
	// Convert top of stack to string
	convertString(app_context, str_buffer);

	// Get string pointer from stack
	const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);

	// Pop the string value
	POP();

	// Handle empty string edge case
	if (str == NULL || str[0] == '\0') {
		float result = 0.0f;  // Return 0 for empty string
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Decode UTF-8 first character
	unsigned int codepoint = 0;
	unsigned char c = (unsigned char)str[0];

	if ((c & 0x80) == 0) {
		// 1-byte sequence (0xxxxxxx)
		codepoint = c;
	} else if ((c & 0xE0) == 0xC0) {
		// 2-byte sequence (110xxxxx 10xxxxxx)
		codepoint = ((c & 0x1F) << 6) | ((unsigned char)str[1] & 0x3F);
	} else if ((c & 0xF0) == 0xE0) {
		// 3-byte sequence (1110xxxx 10xxxxxx 10xxxxxx)
		codepoint = ((c & 0x0F) << 12) |
		            (((unsigned char)str[1] & 0x3F) << 6) |
		            ((unsigned char)str[2] & 0x3F);
	} else if ((c & 0xF8) == 0xF0) {
		// 4-byte sequence (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
		codepoint = ((c & 0x07) << 18) |
		            (((unsigned char)str[1] & 0x3F) << 12) |
		            (((unsigned char)str[2] & 0x3F) << 6) |
		            ((unsigned char)str[3] & 0x3F);
	}

	// Push result as float
	float result = (float)codepoint;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionGetTime(SWFAppContext* app_context)
{
	u32 delta_ms = get_elapsed_ms() - start_time;
	float delta_ms_f32 = (float) delta_ms;

	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &delta_ms_f32));
}

void actionMbAsciiToChar(SWFAppContext* app_context, char* str_buffer)
{
	// Convert top of stack to number
	convertFloat(app_context);

	// Pop the numeric value
	ActionVar a;
	popVar(app_context, &a);

	// Get integer code point
	float value = a.type == ACTION_STACK_VALUE_F32 ? VAL(float, &a.data.numeric_value) : (float)VAL(double, &a.data.numeric_value);
	unsigned int codepoint = (unsigned int)value;

	// Validate code point range (0 to 0x10FFFF for valid Unicode)
	if (codepoint > 0x10FFFF) {
		// Push empty string for invalid code points
		str_buffer[0] = '\0';
		PUSH_STR(str_buffer, 0);
		return;
	}

	// Encode as UTF-8
	int len = 0;
	if (codepoint <= 0x7F) {
		// 1-byte sequence
		str_buffer[len++] = (char)codepoint;
	} else if (codepoint <= 0x7FF) {
		// 2-byte sequence
		str_buffer[len++] = (char)(0xC0 | (codepoint >> 6));
		str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
	} else if (codepoint <= 0xFFFF) {
		// 3-byte sequence
		str_buffer[len++] = (char)(0xE0 | (codepoint >> 12));
		str_buffer[len++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
		str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
	} else {
		// 4-byte sequence
		str_buffer[len++] = (char)(0xF0 | (codepoint >> 18));
		str_buffer[len++] = (char)(0x80 | ((codepoint >> 12) & 0x3F));
		str_buffer[len++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
		str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
	}
	str_buffer[len] = '\0';

	// Push result string
	PUSH_STR(str_buffer, len);
}

void actionTypeof(SWFAppContext* app_context, char* str_buffer)
{
	// Peek at the type without modifying value
	u8 type = STACK_TOP_TYPE;

	// Pop the value
	POP();

	// Determine type string based on stack type
	const char* type_str;
	switch (type)
	{
		case ACTION_STACK_VALUE_F32:
		case ACTION_STACK_VALUE_F64:
			type_str = "number";
			break;

		case ACTION_STACK_VALUE_STRING:
		case ACTION_STACK_VALUE_STR_LIST:
			type_str = "string";
			break;

		case ACTION_STACK_VALUE_FUNCTION:
			type_str = "function";
			break;

		case ACTION_STACK_VALUE_BOOLEAN:
			type_str = "boolean";
			break;

		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_ARRAY:
			type_str = "object";
			break;

		case ACTION_STACK_VALUE_MOVIECLIP:
			type_str = "movieclip";
			break;

		case ACTION_STACK_VALUE_NULL:
			type_str = "null";
			break;

		case ACTION_STACK_VALUE_UNDEFINED:
			type_str = "undefined";
			break;

		default:
			type_str = "undefined";
			break;
	}

	// Copy to str_buffer and push
	int len = strlen(type_str);
	strncpy(str_buffer, type_str, 16);
	str_buffer[len] = '\0';
	PUSH_STR(str_buffer, len);
}

void actionDelete2(SWFAppContext* app_context, char* str_buffer)
{
	// Delete2 deletes a named property/variable
	// Pops the name from the stack, deletes it, pushes success boolean

	// Read variable name from stack
	u32 var_name_sp = SP;
	u8 name_type = STACK[var_name_sp];
	char* var_name = NULL;
	u32 var_name_len = 0;

	// Get the variable name string
	if (name_type == ACTION_STACK_VALUE_STRING)
	{
		var_name = (char*) VAL(u64, &STACK[var_name_sp + 16]);
		var_name_len = VAL(u32, &STACK[var_name_sp + 8]);
	}
	else if (name_type == ACTION_STACK_VALUE_STR_LIST)
	{
		// Materialize string list
		var_name = materializeStringList(STACK, var_name_sp);
		var_name_len = strlen(var_name);
	}

	// Pop the variable name
	POP();

	// Default: assume deletion succeeds (Flash behavior)
	bool success = true;

	// Try to delete from scope chain (innermost to outermost)
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			// Check if property exists in this scope object
			ActionVar* prop = getProperty(scope_chain[i], var_name, var_name_len);
			if (prop != NULL)
			{
				// Found in scope chain - delete it
				success = deleteProperty(app_context, scope_chain[i], var_name, var_name_len);

				// Push result and return
				float result = success ? 1.0f : 0.0f;
				PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
				return;
			}
		}
	}

	// Not found in scope chain - check global variables
	// Note: In Flash, you cannot delete variables declared with 'var', so we return false
	// However, if the variable doesn't exist at all, we return true (Flash behavior)
	if (hasVariable(var_name, var_name_len))
	{
		// Variable exists but is a 'var' declaration - cannot delete
		success = false;
	}
	else
	{
		// Variable doesn't exist - Flash returns true
		success = true;
	}

	// Push result
	float result = success ? 1.0f : 0.0f;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

/**
 * Helper function to check if an object is an instance of a constructor
 *
 * Implements the same logic as ActionScript's instanceof operator:
 * 1. Checks prototype chain - walks __proto__ looking for constructor's prototype
 * 2. Checks interface implementation - for AS2 interfaces
 *
 * @param obj_var Pointer to the object to check
 * @param ctor_var Pointer to the constructor function
 * @return 1 if object is instance of constructor, 0 otherwise
 */
static int checkInstanceOf(ActionVar* obj_var, ActionVar* ctor_var)
{
	// Primitives (number, string, undefined) are never instances
	if (obj_var->type == ACTION_STACK_VALUE_F32 ||
		obj_var->type == ACTION_STACK_VALUE_F64 ||
		obj_var->type == ACTION_STACK_VALUE_STRING ||
		obj_var->type == ACTION_STACK_VALUE_UNDEFINED)
	{
		return 0;
	}

	// Object and constructor must be object types
	if (obj_var->type != ACTION_STACK_VALUE_OBJECT &&
		obj_var->type != ACTION_STACK_VALUE_ARRAY &&
		obj_var->type != ACTION_STACK_VALUE_FUNCTION)
	{
		return 0;
	}

	if (ctor_var->type != ACTION_STACK_VALUE_OBJECT &&
		ctor_var->type != ACTION_STACK_VALUE_FUNCTION)
	{
		return 0;
	}

	ASObject* obj = (ASObject*) obj_var->data.numeric_value;
	ASObject* ctor = (ASObject*) ctor_var->data.numeric_value;

	if (obj == NULL || ctor == NULL)
	{
		return 0;
	}

	// Get the constructor's "prototype" property
	ActionVar* ctor_proto_var = getProperty(ctor, "prototype", 9);
	if (ctor_proto_var == NULL)
	{
		return 0;
	}

	// Get the prototype object
	if (ctor_proto_var->type != ACTION_STACK_VALUE_OBJECT)
	{
		return 0;
	}

	ASObject* ctor_proto = (ASObject*) ctor_proto_var->data.numeric_value;
	if (ctor_proto == NULL)
	{
		return 0;
	}

	// Walk up the object's prototype chain via __proto__ property
	// Start with the object's __proto__
	ActionVar* current_proto_var = getProperty(obj, "__proto__", 9);

	// Maximum chain depth to prevent infinite loops
	int max_depth = 100;
	int depth = 0;

	while (current_proto_var != NULL && depth < max_depth)
	{
		depth++;

		// Check if this prototype matches the constructor's prototype
		if (current_proto_var->type == ACTION_STACK_VALUE_OBJECT)
		{
			ASObject* current_proto = (ASObject*) current_proto_var->data.numeric_value;

			if (current_proto == ctor_proto)
			{
				// Found a match!
				return 1;
			}

			// Continue up the chain
			current_proto_var = getProperty(current_proto, "__proto__", 9);
		}
		else
		{
			// Non-object in prototype chain, stop
			break;
		}
	}

	// Check interface implementation (ActionScript 2.0 implements keyword)
	if (implementsInterface(obj, ctor))
	{
		return 1;
	}

	// Not found in prototype chain or interfaces
	return 0;
}

void actionCastOp(SWFAppContext* app_context)
{
	// CastOp implementation (ActionScript 2.0 cast operator)
	// Pops object to cast, pops constructor, checks if object is instance of constructor
	// Returns object if cast succeeds, null if it fails

	// Pop object to cast
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// Pop constructor function
	ActionVar ctor_var;
	popVar(app_context, &ctor_var);

	// Check if object is an instance of constructor using prototype chain + interfaces
	if (checkInstanceOf(&obj_var, &ctor_var))
	{
		// Cast succeeds - push the object back
		pushVar(app_context, &obj_var);
	}
	else
	{
		// Cast fails - push null
		ActionVar null_var;
		null_var.type = ACTION_STACK_VALUE_NULL;
		null_var.data.numeric_value = 0;
		null_var.str_size = 0;
		pushVar(app_context, &null_var);
	}
}

void actionDuplicate(SWFAppContext* app_context)
{
	// Get the type of the top stack entry
	u8 type = STACK_TOP_TYPE;

	// Handle different types appropriately
	if (type == ACTION_STACK_VALUE_STRING)
	{
		// For strings, we need to copy both the pointer and the length
		const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
		u32 len = STACK_TOP_N;  // Length is stored at offset +8
		u32 id = VAL(u32, &STACK[SP + 12]);  // String ID is at offset +12

		// Push a copy of the string (shallow copy - same pointer)
		PUSH_STR_ID(str, len, id);
	}
	else
	{
		// For other types (numeric, etc.), just copy the value
		u64 value = STACK_TOP_VALUE;
		PUSH(type, value);
	}
}

void actionReturn(SWFAppContext* app_context)
{
	// The return value is already at the top of the stack.
	// The generated C code includes a "return;" statement that exits
	// the function, leaving the value on the stack for the caller.
	// No operation needed here - the translation layer handles
	// the actual return via C return statement.
}

void actionIncrement(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double val = VAL(double, &a.data.numeric_value);
		double result = val + 1.0;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
	}
	else
	{
		float val = VAL(float, &a.data.numeric_value);
		float result = val + 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
	}
}

void actionDecrement(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double val = VAL(double, &a.data.numeric_value);
		double result = val - 1.0;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
	}
	else
	{
		float val = VAL(float, &a.data.numeric_value);
		float result = val - 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
	}
}

void actionInstanceOf(SWFAppContext* app_context)
{
	// Pop constructor function
	ActionVar constr_var;
	popVar(app_context, &constr_var);

	// Pop object
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// Check if object is an instance of constructor using prototype chain + interfaces
	int result = checkInstanceOf(&obj_var, &constr_var);

	// Push result as float (1.0 for true, 0.0 for false)
	float result_val = result ? 1.0f : 0.0f;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_val));
}

void actionEnumerate2(SWFAppContext* app_context, char* str_buffer)
{
	// Pop object reference from stack
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// Push undefined as terminator
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);

	// Handle different types
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Object enumeration - push property names in reverse order
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj != NULL && obj->num_used > 0)
		{
			// Enumerate properties in reverse order (last to first)
			// This way when they're popped, they'll come out in the correct order
			for (int i = obj->num_used - 1; i >= 0; i--)
			{
				const char* prop_name = obj->properties[i].name;
				u32 prop_name_len = obj->properties[i].name_length;

				// Push property name as string
				PUSH_STR(prop_name, prop_name_len);
			}
		}

		#ifdef DEBUG
		printf("// Enumerate2: enumerated %u properties from object\n",
			obj ? obj->num_used : 0);
		#endif
	}
	else if (obj_var.type == ACTION_STACK_VALUE_ARRAY)
	{
		// Array enumeration - push indices as strings
		ASArray* arr = (ASArray*) obj_var.data.numeric_value;

		if (arr != NULL && arr->length > 0)
		{
			// Enumerate indices in reverse order
			for (int i = arr->length - 1; i >= 0; i--)
			{
				// Convert index to string
				snprintf(str_buffer, 17, "%d", i);
				u32 len = strlen(str_buffer);

				// Push index as string
				PUSH_STR(str_buffer, len);
			}
		}

		#ifdef DEBUG
		printf("// Enumerate2: enumerated %u indices from array\n",
			arr ? arr->length : 0);
		#endif
	}
	else
	{
		// Non-object/non-array: just the undefined terminator
		#ifdef DEBUG
		printf("// Enumerate2: non-enumerable type, only undefined pushed\n");
		#endif
	}
}

void actionBitAnd(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	int32_t a_int = varToInt32(&a);
	int32_t b_int = varToInt32(&b);
	double result = (double)(b_int & a_int);
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionBitOr(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	int32_t a_int = varToInt32(&a);
	int32_t b_int = varToInt32(&b);
	double result = (double)(b_int | a_int);
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionBitXor(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar a;
	popVar(app_context, &a);

	convertFloat(app_context);
	ActionVar b;
	popVar(app_context, &b);

	int32_t a_int = varToInt32(&a);
	int32_t b_int = varToInt32(&b);
	double result = (double)(b_int ^ a_int);
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionBitLShift(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar shift_count_var;
	popVar(app_context, &shift_count_var);

	convertFloat(app_context);
	ActionVar value_var;
	popVar(app_context, &value_var);

	int32_t shift_count = varToInt32(&shift_count_var) & 0x1F;
	int32_t value = varToInt32(&value_var);
	double result = (double)(value << shift_count);
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionBitRShift(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar shift_count_var;
	popVar(app_context, &shift_count_var);

	convertFloat(app_context);
	ActionVar value_var;
	popVar(app_context, &value_var);

	int32_t shift_count = varToInt32(&shift_count_var) & 0x1F;
	int32_t value = varToInt32(&value_var);
	double result = (double)(value >> shift_count);
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionBitURShift(SWFAppContext* app_context)
{
	convertFloat(app_context);
	ActionVar shift_count_var;
	popVar(app_context, &shift_count_var);

	convertFloat(app_context);
	ActionVar value_var;
	popVar(app_context, &value_var);

	uint32_t shift_count = varToUint32(&shift_count_var) & 0x1F;
	uint32_t value = varToUint32(&value_var);
	uint32_t shifted = value >> shift_count;
	// SWF8 treats unsigned right shift result as signed (Flash bug/quirk)
#if defined(SWF_VERSION) && SWF_VERSION == 8
	double result = (double)(int32_t)shifted;
#else
	double result = (double)shifted;
#endif
	PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
}

void actionStrictEquals(SWFAppContext* app_context)
{
	// Pop first argument (no type conversion - strict equality!)
	ActionVar a;
	popVar(app_context, &a);

	// Pop second argument (no type conversion - strict equality!)
	ActionVar b;
	popVar(app_context, &b);

	float result = 0.0f;

	// First check: types must match
	if (a.type == b.type)
	{
		// Second check: values must match
		switch (a.type)
		{
			case ACTION_STACK_VALUE_F32:
			{
				float a_val = VAL(float, &a.data.numeric_value);
				float b_val = VAL(float, &b.data.numeric_value);
				result = (a_val == b_val) ? 1.0f : 0.0f;
				break;
			}

			case ACTION_STACK_VALUE_F64:
			{
				// Compare raw bits so NaN === NaN is true (Flash quirk)
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
			}

			case ACTION_STACK_VALUE_STRING:
			{
				const char* str_a = (const char*) a.data.numeric_value;
				const char* str_b = (const char*) b.data.numeric_value;
				// Check for NULL pointers first
				if (str_a != NULL && str_b != NULL) {
					result = (strcmp(str_a, str_b) == 0) ? 1.0f : 0.0f;
				} else {
					// If either is NULL, they're only equal if both are NULL
					result = (str_a == str_b) ? 1.0f : 0.0f;
				}
				break;
			}

			case ACTION_STACK_VALUE_STR_LIST:
			{
				// For string lists, use strcmp_list_a_list_b
				int cmp_result = strcmp_list_a_list_b(a.data.numeric_value, b.data.numeric_value);
				result = (cmp_result == 0) ? 1.0f : 0.0f;
				break;
			}

			// For other types (OBJECT, etc.), compare raw values
			default:
				#ifdef DEBUG
				printf("[DEBUG] STRICT_EQUALS: type=%d, a.ptr=%p, b.ptr=%p, equal=%d\n",
					a.type, (void*)a.data.numeric_value, (void*)b.data.numeric_value,
					a.data.numeric_value == b.data.numeric_value);
				#endif
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
		}
	}
	else
	{
		// different types, result remains 0.0f (false)
		#ifdef DEBUG
		printf("[DEBUG] STRICT_EQUALS: type mismatch - a.type=%d, b.type=%d\n", a.type, b.type);
		#endif
	}

	// Push boolean result
	u64 bool_val = (result != 0.0f) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
}

void actionEquals2(SWFAppContext* app_context)
{
	// Pop first argument (arg1)
	ActionVar a;
	popVar(app_context, &a);

	// Pop second argument (arg2)
	ActionVar b;
	popVar(app_context, &b);

	// Object-to-primitive conversion via valueOf/toString
	int a_is_obj = (a.type == ACTION_STACK_VALUE_OBJECT || a.type == ACTION_STACK_VALUE_ARRAY);
	int b_is_obj = (b.type == ACTION_STACK_VALUE_OBJECT || b.type == ACTION_STACK_VALUE_ARRAY);

	if (a_is_obj && b_is_obj)
	{
#if !defined(SWF_VERSION) || SWF_VERSION < 6
		// SWF5 and below: try valueOf on both; if both produce primitives, compare those.
		// If either fails to produce a primitive, fall back to reference equality.
		ActionVar a_prim = objectToPrimitive(app_context, &a, NULL);
		ActionVar b_prim = objectToPrimitive(app_context, &b, NULL);
		int a_ok = (a_prim.type != ACTION_STACK_VALUE_UNDEFINED);
		int b_ok = (b_prim.type != ACTION_STACK_VALUE_UNDEFINED);
		if (a_ok && b_ok)
		{
			a = a_prim;
			b = b_prim;
			// fall through to primitive comparison
		}
		else
		{
			// Reference equality
			u64 bool_val = (a.data.numeric_value == b.data.numeric_value) ? 1 : 0;
			PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
			return;
		}
#else
		// SWF6+: reference equality for object vs object
		u64 bool_val = (a.data.numeric_value == b.data.numeric_value) ? 1 : 0;
		PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
		return;
#endif
	}
	else if (a_is_obj)
	{
		// Convert via valueOf only (number hint — no toString fallback)
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &a, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			a = vo;
		}
		// else: leave as object (will likely mismatch types → false)
	}
	else if (b_is_obj)
	{
		int vo_found = 0;
		ActionVar vo = objectCallValueOf(app_context, &b, &vo_found);
		if (vo_found && vo.type != ACTION_STACK_VALUE_OBJECT &&
		    vo.type != ACTION_STACK_VALUE_ARRAY && vo.type != ACTION_STACK_VALUE_FUNCTION)
		{
			b = vo;
		}
	}

	float result = 0.0f;

	// ECMA-262 equality algorithm (Section 11.9.3)

	// 1. If types are the same, use strict equality
	if (a.type == b.type)
	{
		switch (a.type)
		{
			case ACTION_STACK_VALUE_F32:
			{
				float a_val = VAL(float, &a.data.numeric_value);
				float b_val = VAL(float, &b.data.numeric_value);
				// NaN is never equal to anything, including itself (ECMA-262)
				if (isnan(a_val) || isnan(b_val)) {
					result = 0.0f;
				} else {
					result = (a_val == b_val) ? 1.0f : 0.0f;
				}
				break;
			}

			case ACTION_STACK_VALUE_F64:
			{
				// Compare raw bits so NaN == NaN is true (Flash quirk)
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
			}

			case ACTION_STACK_VALUE_STRING:
			{
				const char* str_a = (const char*) a.data.numeric_value;
				const char* str_b = (const char*) b.data.numeric_value;
				if (str_a != NULL && str_b != NULL) {
					result = (strcmp(str_a, str_b) == 0) ? 1.0f : 0.0f;
				} else {
					result = (str_a == str_b) ? 1.0f : 0.0f;
				}
				break;
			}

			case ACTION_STACK_VALUE_BOOLEAN:
			{
				// Boolean values are stored in numeric_value as 0 (false) or 1 (true)
				u32 a_val = (u32) a.data.numeric_value;
				u32 b_val = (u32) b.data.numeric_value;
				result = (a_val == b_val) ? 1.0f : 0.0f;
				break;
			}

			case ACTION_STACK_VALUE_NULL:
			{
				// null == null is true
				result = 1.0f;
				break;
			}

			case ACTION_STACK_VALUE_UNDEFINED:
			{
				// undefined == undefined is true
				result = 1.0f;
				break;
			}

			default:
				// For other types (OBJECT, etc.), compare raw values (reference equality)
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
		}
	}
	// 2. Special case: null == undefined (ECMA-262)
	else if ((a.type == ACTION_STACK_VALUE_NULL && b.type == ACTION_STACK_VALUE_UNDEFINED) ||
	         (a.type == ACTION_STACK_VALUE_UNDEFINED && b.type == ACTION_STACK_VALUE_NULL))
	{
		result = 1.0f;
	}
	// 2b. Number type mismatch (F32 vs F64): convert both to double
	else if ((a.type == ACTION_STACK_VALUE_F32 || a.type == ACTION_STACK_VALUE_F64) &&
	         (b.type == ACTION_STACK_VALUE_F32 || b.type == ACTION_STACK_VALUE_F64))
	{
		double a_val = varToDouble(&a);
		double b_val = varToDouble(&b);
		// Flash quirk: NaN == NaN is true (compare as doubles after conversion)
		u64 a_bits = VAL(u64, &a_val);
		u64 b_bits = VAL(u64, &b_val);
		result = (a_bits == b_bits) ? 1.0f : 0.0f;
	}
	// 3. Number vs String: convert string to number
	else if ((a.type == ACTION_STACK_VALUE_F32 || a.type == ACTION_STACK_VALUE_F64) &&
	         b.type == ACTION_STACK_VALUE_STRING)
	{
		const char* str_b = (const char*) b.data.numeric_value;
		double b_num = parseStringToNumber(str_b);
		double a_val = varToDouble(&a);
		if (isnan(a_val) || isnan(b_num)) {
			result = 0.0f;
		} else {
			result = (a_val == b_num) ? 1.0f : 0.0f;
		}
	}
	else if (a.type == ACTION_STACK_VALUE_STRING &&
	         (b.type == ACTION_STACK_VALUE_F32 || b.type == ACTION_STACK_VALUE_F64))
	{
		const char* str_a = (const char*) a.data.numeric_value;
		double a_num = parseStringToNumber(str_a);
		double b_val = varToDouble(&b);
		if (isnan(a_num) || isnan(b_val)) {
			result = 0.0f;
		} else {
			result = (a_num == b_val) ? 1.0f : 0.0f;
		}
	}
	// 4. Boolean: convert to number and compare recursively
	else if (a.type == ACTION_STACK_VALUE_BOOLEAN)
	{
		double a_num = a.data.numeric_value ? 1.0 : 0.0;

		if (b.type == ACTION_STACK_VALUE_F32 || b.type == ACTION_STACK_VALUE_F64)
		{
			double b_val = varToDouble(&b);
			if (isnan(b_val)) {
				result = 0.0f;
			} else {
				result = (a_num == b_val) ? 1.0f : 0.0f;
			}
		}
		else if (b.type == ACTION_STACK_VALUE_STRING)
		{
			const char* str_b = (const char*) b.data.numeric_value;
			double b_num = parseStringToNumber(str_b);
			if (isnan(b_num)) {
				result = 0.0f;
			} else {
				result = (a_num == b_num) ? 1.0f : 0.0f;
			}
		}
		else if (b.type == ACTION_STACK_VALUE_NULL || b.type == ACTION_STACK_VALUE_UNDEFINED)
		{
			result = 0.0f;
		}
	}
	else if (b.type == ACTION_STACK_VALUE_BOOLEAN)
	{
		double b_num = b.data.numeric_value ? 1.0 : 0.0;

		if (a.type == ACTION_STACK_VALUE_F32 || a.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = varToDouble(&a);
			if (isnan(a_val)) {
				result = 0.0f;
			} else {
				result = (a_val == b_num) ? 1.0f : 0.0f;
			}
		}
		else if (a.type == ACTION_STACK_VALUE_STRING)
		{
			const char* str_a = (const char*) a.data.numeric_value;
			double a_num = parseStringToNumber(str_a);
			if (isnan(a_num)) {
				result = 0.0f;
			} else {
				result = (a_num == b_num) ? 1.0f : 0.0f;
			}
		}
		else if (a.type == ACTION_STACK_VALUE_NULL || a.type == ACTION_STACK_VALUE_UNDEFINED)
		{
			result = 0.0f;
		}
	}
	// 5. null or undefined compared with anything else (except each other) is false
	else if (a.type == ACTION_STACK_VALUE_NULL || a.type == ACTION_STACK_VALUE_UNDEFINED ||
	         b.type == ACTION_STACK_VALUE_NULL || b.type == ACTION_STACK_VALUE_UNDEFINED)
	{
		result = 0.0f;
	}
	// 6. Different types not covered above: false
	// (This handles cases like object vs number, etc.)

	// Push boolean result
	u64 bool_val = (result != 0.0f) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
}

void actionStringGreater(SWFAppContext* app_context)
{
	// Pop both operands
	ActionVar a;
	popVar(app_context, &a);
	ActionVar b;
	popVar(app_context, &b);

	// Convert object operands via toString only (string hint — no valueOf fallback)
	if (a.type == ACTION_STACK_VALUE_OBJECT || a.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &a, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			a = ts;
		else
		{
			a.type = ACTION_STACK_VALUE_STRING;
			a.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}
	if (b.type == ACTION_STACK_VALUE_OBJECT || b.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &b, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			b = ts;
		else
		{
			b.type = ACTION_STACK_VALUE_STRING;
			b.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}

	// Convert non-string primitives to strings for comparison
	char buf_a[17], buf_b[17];
	const char* str_a;
	const char* str_b;

	if (a.type == ACTION_STACK_VALUE_STRING)
		str_a = (const char*) a.data.numeric_value;
	else
	{
		pushVar(app_context, &a);
		convertString(app_context, buf_a);
		str_a = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();
	}

	if (b.type == ACTION_STACK_VALUE_STRING)
		str_b = (const char*) b.data.numeric_value;
	else
	{
		pushVar(app_context, &b);
		convertString(app_context, buf_b);
		str_b = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();
	}

	if (str_a == NULL) str_a = "";
	if (str_b == NULL) str_b = "";

	// Compare: b > a
	u64 result = (strcmp(str_b, str_a) > 0) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

// ==================================================================
// Inheritance (EXTENDS opcode)
// ==================================================================

void actionExtends(SWFAppContext* app_context)
{
	// Pop superclass constructor from stack
	ActionVar superclass;
	popVar(app_context, &superclass);

	// Pop subclass constructor from stack
	ActionVar subclass;
	popVar(app_context, &subclass);

	// Verify both are objects/functions
	if (superclass.type != ACTION_STACK_VALUE_OBJECT &&
	    superclass.type != ACTION_STACK_VALUE_FUNCTION)
	{
#ifdef DEBUG
		printf("[DEBUG] actionExtends: superclass is not an object/function (type=%d)\n",
		       superclass.type);
#endif
		return;
	}

	if (subclass.type != ACTION_STACK_VALUE_OBJECT &&
	    subclass.type != ACTION_STACK_VALUE_FUNCTION)
	{
#ifdef DEBUG
		printf("[DEBUG] actionExtends: subclass is not an object/function (type=%d)\n",
		       subclass.type);
#endif
		return;
	}

	// Get constructor objects
	ASObject* super_func = (ASObject*) superclass.data.numeric_value;
	ASObject* sub_func = (ASObject*) subclass.data.numeric_value;

	if (super_func == NULL || sub_func == NULL)
	{
#ifdef DEBUG
		printf("[DEBUG] actionExtends: NULL constructor object\n");
#endif
		return;
	}

	// Create new prototype object
	ASObject* new_proto = allocObject(app_context, 0);
	if (new_proto == NULL)
	{
#ifdef DEBUG
		printf("[DEBUG] actionExtends: Failed to allocate new prototype\n");
#endif
		return;
	}

	// Get superclass prototype property
	ActionVar* super_proto_var = getProperty(super_func, "prototype", 9);

	// Set __proto__ of new prototype to superclass prototype
	if (super_proto_var != NULL)
	{
		setProperty(app_context, new_proto, "__proto__", 9, super_proto_var);
	}

	// Set constructor property to superclass
	setProperty(app_context, new_proto, "constructor", 11, &superclass);

#ifdef DEBUG
	printf("[DEBUG] actionExtends: Set constructor property - type=%d, ptr=%p\n",
		superclass.type, (void*)superclass.data.numeric_value);

	// Verify it was set correctly
	ActionVar* check = getProperty(new_proto, "constructor", 11);
	if (check != NULL) {
		printf("[DEBUG] actionExtends: Retrieved constructor - type=%d, ptr=%p\n",
			check->type, (void*)check->data.numeric_value);
	}
#endif

	// Set subclass prototype to new object
	ActionVar new_proto_var;
	new_proto_var.type = ACTION_STACK_VALUE_OBJECT;
	new_proto_var.data.numeric_value = (u64) new_proto;
	new_proto_var.str_size = 0;

	setProperty(app_context, sub_func, "prototype", 9, &new_proto_var);

	// Release our reference to new_proto
	// (setProperty retained it when setting as prototype)
	releaseObject(app_context, new_proto);

#ifdef DEBUG
	printf("[DEBUG] actionExtends: Prototype chain established\n");
#endif

	// Note: No values pushed back on stack
}

// ==================================================================
// Register Storage (up to 256 registers for SWF 5+)
// ==================================================================

#define MAX_REGISTERS 256
static ActionVar g_registers[MAX_REGISTERS];

void actionStoreRegister(SWFAppContext* app_context, u8 register_num)
{
	// Validate register number
	if (register_num >= MAX_REGISTERS) {
		return;
	}

	// Peek the top of stack (don't pop!)
	ActionVar value;
	peekVar(app_context, &value);

	// Store value in register
	g_registers[register_num] = value;
}

void actionPushRegister(SWFAppContext* app_context, u8 register_num)
{
	// Validate register number
	if (register_num >= MAX_REGISTERS) {
		// Push undefined for invalid register
		float undef = 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &undef));
		return;
	}

	ActionVar* reg = &g_registers[register_num];

	// Push register value to stack
	if (reg->type == ACTION_STACK_VALUE_F32 || reg->type == ACTION_STACK_VALUE_F64) {
		PUSH(reg->type, reg->data.numeric_value);
	} else if (reg->type == ACTION_STACK_VALUE_STRING) {
		const char* str = (const char*) reg->data.numeric_value;
		PUSH_STR(str, reg->str_size);
	} else if (reg->type == ACTION_STACK_VALUE_STR_LIST) {
		// String list - push reference
		PUSH_STR_LIST(reg->str_size, 0);
	} else {
		// Undefined or unknown type - push 0
		float undef = 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &undef));
	}
}

void actionStringLess(SWFAppContext* app_context)
{
	// Pop both operands
	ActionVar a;
	popVar(app_context, &a);
	ActionVar b;
	popVar(app_context, &b);

	// Convert object operands via toString only (string hint — no valueOf fallback)
	if (a.type == ACTION_STACK_VALUE_OBJECT || a.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &a, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			a = ts;
		else
		{
			// toString not found or returned non-string → use fallback
			a.type = ACTION_STACK_VALUE_STRING;
			a.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}
	if (b.type == ACTION_STACK_VALUE_OBJECT || b.type == ACTION_STACK_VALUE_ARRAY)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, &b, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			b = ts;
		else
		{
			b.type = ACTION_STACK_VALUE_STRING;
			b.data.numeric_value = ts_found ? (u64)"[type Object]" : (u64)"[object Object]";
		}
	}

	// Convert non-string primitives to strings for comparison
	char buf_a[17], buf_b[17];
	const char* str_a;
	const char* str_b;

	if (a.type == ACTION_STACK_VALUE_STRING)
		str_a = (const char*) a.data.numeric_value;
	else
	{
		pushVar(app_context, &a);
		convertString(app_context, buf_a);
		str_a = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();
	}

	if (b.type == ACTION_STACK_VALUE_STRING)
		str_b = (const char*) b.data.numeric_value;
	else
	{
		pushVar(app_context, &b);
		convertString(app_context, buf_b);
		str_b = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();
	}

	if (str_a == NULL) str_a = "";
	if (str_b == NULL) str_b = "";

	// Compare: b < a
	u64 result = (strcmp(str_b, str_a) < 0) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionImplementsOp(SWFAppContext* app_context)
{
	// ActionImplementsOp implements the ActionScript "implements" keyword
	// It specifies the interfaces that a class implements, for use by instanceof and CastOp

	// Step 1: Pop constructor function (the class) from stack
	ActionVar constructor_var;
	popVar(app_context, &constructor_var);

	// Validate that it's an object
	if (constructor_var.type != ACTION_STACK_VALUE_OBJECT)
	{
		fprintf(stderr, "ERROR: actionImplementsOp - constructor is not an object\n");
		return;
	}

	ASObject* constructor = (ASObject*) constructor_var.data.numeric_value;

	// Step 2: Pop count of interfaces from stack
	ActionVar count_var;
	popVar(app_context, &count_var);

	// Convert to number if needed
	u32 interface_count = 0;
	if (count_var.type == ACTION_STACK_VALUE_F32)
	{
		interface_count = (u32) *((float*)&count_var.data.numeric_value);
	}
	else if (count_var.type == ACTION_STACK_VALUE_F64)
	{
		interface_count = (u32) *((double*)&count_var.data.numeric_value);
	}
	else
	{
		fprintf(stderr, "ERROR: actionImplementsOp - interface count is not a number\n");
		return;
	}

	// Step 3: Allocate array for interface constructors
	ASObject** interfaces = NULL;
	if (interface_count > 0)
	{
		interfaces = (ASObject**) malloc(sizeof(ASObject*) * interface_count);
		if (interfaces == NULL)
		{
			fprintf(stderr, "ERROR: actionImplementsOp - failed to allocate interfaces array\n");
			return;
		}

		// Pop each interface constructor from stack
		// Note: Interfaces are pushed in order, so we pop them in reverse
		for (u32 i = 0; i < interface_count; i++)
		{
			ActionVar iface_var;
			popVar(app_context, &iface_var);

			if (iface_var.type != ACTION_STACK_VALUE_OBJECT)
			{
				fprintf(stderr, "ERROR: actionImplementsOp - interface %u is not an object\n", i);
				// Clean up allocated interfaces
				for (u32 j = 0; j < i; j++)
				{
					releaseObject(app_context, interfaces[j]);
				}
				free(interfaces);
				return;
			}

			// Store in reverse order (last popped goes first)
			interfaces[interface_count - 1 - i] = (ASObject*) iface_var.data.numeric_value;
		}
	}

	// Step 4: Set the interface list on the constructor
	// This transfers ownership of the interfaces array
	setInterfaceList(app_context, constructor, interfaces, interface_count);

#ifdef DEBUG
	printf("[DEBUG] actionImplementsOp: constructor=%p, interface_count=%u\n",
		(void*)constructor, interface_count);
#endif

	// Note: No values pushed back on stack (ImplementsOp has no return value)
}

/**
 * ActionCall - Calls a subroutine (frame actions)
 *
 * Stack: [ frame_identifier ] -> [ ]
 *
 * Pops a frame identifier from the stack and executes the actions in that frame.
 * After the frame actions complete, execution resumes at the instruction after
 * the ActionCall instruction.
 *
 * Frame identifier can be:
 * - A number: Frame index (0-based in g_frame_funcs array)
 * - A string (numeric): Parsed as frame number
 * - A string (label): Frame label (requires label registry - not implemented)
 * - With target path: "/target:frame" or "/target:label" (requires MovieClip tree - not implemented)
 *
 * Edge cases:
 * - Negative frame numbers: Ignored (no action)
 * - Out of range frames: Ignored (no action)
 * - Invalid frame types: Ignored with warning
 * - Null/undefined: Ignored (no action)
 * - Frame labels: Parsed and logged but not executed (requires label registry)
 * - Target paths: Parsed and logged but not executed (requires MovieClip infrastructure)
 *
 * SWF version: 4+
 * Opcode: 0x9E
 *
 * @param stack Pointer to the runtime stack
 * @param sp Pointer to stack pointer
 */
void actionCall(SWFAppContext* app_context)
{
	// Access global frame info (set by swfStart)
	extern frame_func* g_frame_funcs;
	extern size_t g_frame_count;
	extern int quit_swf;

	// Pop frame identifier from stack
	ActionVar frame_var;
	popVar(app_context, &frame_var);

	if (frame_var.type == ACTION_STACK_VALUE_F32) {
		// Numeric frame
		float frame_float;
		memcpy(&frame_float, &frame_var.data.numeric_value, sizeof(float));

		// Handle negative frames (ignore)
		s32 frame_num = (s32)frame_float;
		if (frame_num < 0) {
			printf("// Call: negative frame %d (ignored)\n", frame_num);
			fflush(stdout);
			return;
		}

		// Validate frame is in range
		if (g_frame_funcs && (size_t)frame_num < g_frame_count) {
			printf("// Call: frame %d\n", frame_num);
			fflush(stdout);

			// Save quit_swf state to prevent frame from terminating execution
			int saved_quit_swf = quit_swf;
			quit_swf = 0;

			// Call the frame function (executes frame actions)
			// Note: This calls the full frame function including ShowFrame
			g_frame_funcs[frame_num](app_context);

			// Restore quit_swf state (only quit if we were already quitting)
			quit_swf = saved_quit_swf;
		} else {
			printf("// Call: frame %d out of range (ignored, total frames: %zu)\n", frame_num, g_frame_count);
			fflush(stdout);
		}
	}
	else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
		// Frame label or number as string - may include target path
		const char* frame_str = (const char*)frame_var.data.numeric_value;

		if (frame_str == NULL) {
			printf("// Call: null frame identifier (ignored)\n");
			fflush(stdout);
			return;
		}

		// Parse target path if present (format: "target:frame" or "/target:frame")
		const char* target = NULL;
		const char* frame_part = frame_str;
		const char* colon = strchr(frame_str, ':');

		if (colon != NULL) {
			// Target path present
			size_t target_len = colon - frame_str;
			static char target_buffer[256];

			if (target_len < sizeof(target_buffer)) {
				memcpy(target_buffer, frame_str, target_len);
				target_buffer[target_len] = '\0';
				target = target_buffer;
				frame_part = colon + 1;  // Frame label/number after the colon
			}
		}

		// Check if frame_part is numeric or a label
		char* endptr;
		long frame_num = strtol(frame_part, &endptr, 10);

		if (endptr != frame_part && *endptr == '\0') {
			// It's a numeric frame
			if (frame_num < 0) {
				if (target) {
					printf("// Call: target '%s', negative frame %ld (ignored)\n", target, frame_num);
				} else {
					printf("// Call: negative frame %ld (ignored)\n", frame_num);
				}
				fflush(stdout);
				return;
			}

			if (target) {
				// Target path specified - requires MovieClip infrastructure
				printf("// Call: target '%s', frame %ld (target paths not implemented)\n", target, frame_num);
				fflush(stdout);
				// Note: Full implementation would require MovieClip tree traversal
			} else {
				// Main timeline - can execute
				if (g_frame_funcs && (size_t)frame_num < g_frame_count) {
					printf("// Call: frame %ld\n", frame_num);
					fflush(stdout);

					// Save quit_swf state to prevent frame from terminating execution
					int saved_quit_swf = quit_swf;
					quit_swf = 0;

					// Call the frame function (executes frame actions)
					g_frame_funcs[frame_num](app_context);

					// Restore quit_swf state
					quit_swf = saved_quit_swf;
				} else {
					printf("// Call: frame %ld out of range (ignored, total frames: %zu)\n", frame_num, g_frame_count);
					fflush(stdout);
				}
			}
		} else {
			// It's a frame label
			if (target) {
				printf("// Call: target '%s', label '%s' (frame labels not implemented)\n", target, frame_part);
			} else {
				printf("// Call: label '%s' (frame labels not implemented)\n", frame_part);
			}
			fflush(stdout);

			// Note: Frame label lookup requires:
			// - Frame label registry (mapping labels to frame numbers)
			// - SWFRecomp to parse FrameLabel tags (tag type 43) and generate the registry
			// - MovieClip context switching for target paths
		}
	}
	else if (frame_var.type == ACTION_STACK_VALUE_UNDEFINED) {
		// Undefined - ignore
		printf("// Call: undefined frame (ignored)\n");
		fflush(stdout);
	}
	else {
		// Invalid type - ignore with warning
		printf("// Call: invalid frame type %d (ignored)\n", frame_var.type);
		fflush(stdout);
	}
	// If frame not found or invalid, do nothing (per SWF spec)
}

// Helper function to print a string value that may be a regular string or STR_LIST
static void printStringValue(ActionVar* var)
{
	if (var->type == ACTION_STACK_VALUE_STRING) {
		printf("%s", (const char*)var->data.numeric_value);
	} else if (var->type == ACTION_STACK_VALUE_STR_LIST) {
		// STR_LIST: first element is count, rest are string pointers
		u64* str_list = (u64*)var->data.numeric_value;
		u64 count = str_list[0];
		for (u64 i = 0; i < count; i++) {
			printf("%s", (const char*)str_list[i + 1]);
		}
	}
	// For other types, print nothing (empty string)
}

/**
 * ActionGetURL2 - Stack-based URL loading with HTTP method support
 *
 * Stack: [ url, target ] -> [ ]
 *
 * Pops target and URL from stack, then performs URL loading based on flags:
 * - SendVarsMethod (bits 7-6): 0=None, 1=GET, 2=POST
 * - LoadTargetFlag (bit 1): 0=browser window, 1=sprite path
 * - LoadVariablesFlag (bit 0): 0=load content, 1=load variables
 *
 * In NO_GRAPHICS mode: Logs the operation but does not perform actual
 * HTTP requests, browser integration, SWF loading, or variable setting.
 * Full implementation would require:
 * - HTTP client (libcurl or similar)
 * - Platform-specific browser integration
 * - SWF parser and loader
 * - Full sprite/timeline variable management
 * - Security sandbox enforcement
 *
 * SWF version: 4+
 * Opcode: 0x9A
 *
 * @param stack Pointer to the runtime stack
 * @param sp Pointer to stack pointer
 * @param send_vars_method HTTP method: 0=None, 1=GET, 2=POST
 * @param load_target_flag Target type: 0=window, 1=sprite
 * @param load_variables_flag Load type: 0=content, 1=variables
 */
void actionGetURL2(SWFAppContext* app_context, u8 send_vars_method, u8 load_target_flag, u8 load_variables_flag)
{
	// Pop target from stack
	// convertString() is called to handle the case where the value might be a number
	// that needs to be converted to a string, though in practice URLs/targets are always strings
	char target_str[17];
	ActionVar target_var;
	convertString(app_context, target_str);
	popVar(app_context, &target_var);

	// Pop URL from stack
	char url_str[17];
	ActionVar url_var;
	convertString(app_context, url_str);
	popVar(app_context, &url_var);

	// Determine HTTP method
	const char* method = "NONE";
	if (send_vars_method == 1) method = "GET";
	else if (send_vars_method == 2) method = "POST";

	// Determine operation type
	bool is_sprite = (load_target_flag == 1);
	bool load_vars = (load_variables_flag == 1);

	// Log the operation (NO_GRAPHICS mode implementation)
	// In a full implementation, this would perform the actual operation
	if (is_sprite) {
		// Load into sprite/movieclip
		if (load_vars) {
			// Load variables into sprite
			// Full implementation: Make HTTP request, parse x-www-form-urlencoded response,
			// set variables in target sprite scope
			printf("// LoadVariables: ");
			printStringValue(&url_var);
			printf(" -> ");
			printStringValue(&target_var);
			printf(" (method: %s)\n", method);
		} else {
			// Load SWF into sprite
			// Full implementation: Download SWF file, parse it, load into target sprite path
			printf("// LoadMovie: ");
			printStringValue(&url_var);
			printf(" -> ");
			printStringValue(&target_var);
			printf("\n");
		}
	} else {
		// Load into browser window
		if (load_vars) {
			// Load variables into timeline
			// Full implementation: Make HTTP request, parse response, set variables in timeline
			printf("// LoadVariables: ");
			printStringValue(&url_var);
			printf(" (method: %s)\n", method);
		} else {
			// Open URL in browser
			// Full implementation: Open URL in specified browser window/frame using
			// platform-specific APIs (e.g., system(), ShellExecute on Windows, open on macOS)
			printf("// OpenURL: ");
			printStringValue(&url_var);
			printf(" (target: ");
			printStringValue(&target_var);
			if (send_vars_method != 0) {
				printf(", method: %s", method);
			}
			printf(")\n");
		}
	}
}

void actionInitArray(SWFAppContext* app_context)
{
	// 1. Pop array element count
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);
	u32 num_elements = (u32) varToInt32(&count_var);

	// 2. Allocate array
	ASArray* arr = allocArray(app_context, num_elements);
	if (!arr) {
		// Handle allocation failure - push empty array or null
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &(float){0.0f}));
		return;
	}
	arr->length = num_elements;

	// 3. Pop elements and populate array
	// Per SWF spec: elements were pushed in reverse order (rightmost first, leftmost last)
	// Stack has: [..., elem_N, elem_N-1, ..., elem_1] with elem_1 on top
	// We pop and store sequentially: pop elem_1 -> arr[0], pop elem_2 -> arr[1], etc.
	for (u32 i = 0; i < num_elements; i++) {
		ActionVar elem;
		popVar(app_context, &elem);
		arr->elements[i] = elem;

		// If element is array, increment refcount
		if (elem.type == ACTION_STACK_VALUE_ARRAY) {
			retainArray((ASArray*) elem.data.numeric_value);
		}
		// Could also handle ACTION_STACK_VALUE_OBJECT here if needed
	}

	// 4. Push array reference to stack
	PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
}

void actionSetMember(SWFAppContext* app_context)
{
	// Stack layout (from top to bottom):
	// 1. value (the value to assign)
	// 2. property_name (the name of the property)
	// 3. object (the object to set the property on)

	// Pop the value to assign
	ActionVar value_var;
	popVar(app_context, &value_var);

	// Pop the property name
	// The property name should be a string on the stack
	ActionVar prop_name_var;
	popVar(app_context, &prop_name_var);

	// Get the property name as string
	const char* prop_name = NULL;
	u32 prop_name_len = 0;

	if (prop_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		// If it's a string, use it directly
		prop_name = (const char*) prop_name_var.data.numeric_value;
		prop_name_len = prop_name_var.str_size;
	}
	else if (prop_name_var.type == ACTION_STACK_VALUE_F32 || prop_name_var.type == ACTION_STACK_VALUE_F64)
	{
		// If it's a number, convert it to string (for array indices)
		// Use a static buffer for conversion
		static char index_buffer[32];
		if (prop_name_var.type == ACTION_STACK_VALUE_F32)
		{
			float f = VAL(float, &prop_name_var.data.numeric_value);
			snprintf(index_buffer, sizeof(index_buffer), "%.15g", f);
		}
		else
		{
			double d = VAL(double, &prop_name_var.data.numeric_value);
			snprintf(index_buffer, sizeof(index_buffer), "%.15g", d);
		}
		prop_name = index_buffer;
		prop_name_len = strlen(index_buffer);
	}
	else
	{
		// Unknown type for property name - error case
		// Just pop the object and return
		POP();
		return;
	}

	// Pop the object
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// Check if the object is actually an object type
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;
		if (obj != NULL)
		{
			// Set the property on the object
			setProperty(app_context, obj, prop_name, prop_name_len, &value_var);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_ARRAY)
	{
		ASArray* arr = (ASArray*) obj_var.data.numeric_value;
		if (arr != NULL)
		{
			// Check for "length" property
			if (prop_name_len == 6 && strncmp(prop_name, "length", 6) == 0)
			{
				// Set array length (truncate or extend)
				int new_len = 0;
				if (value_var.type == ACTION_STACK_VALUE_F32)
					new_len = (int) VAL(float, &value_var.data.numeric_value);
				else if (value_var.type == ACTION_STACK_VALUE_F64)
					new_len = (int) VAL(double, &value_var.data.numeric_value);
				if (new_len >= 0)
				{
					if ((u32)new_len > arr->capacity)
					{
						arr->elements = (ActionVar*) realloc(arr->elements, sizeof(ActionVar) * new_len);
						// Zero-init new elements
						for (u32 i = arr->capacity; i < (u32)new_len; i++)
						{
							arr->elements[i].type = ACTION_STACK_VALUE_UNDEFINED;
							arr->elements[i].data.numeric_value = 0;
							arr->elements[i].str_size = 0;
						}
						arr->capacity = new_len;
					}
					arr->length = new_len;
				}
			}
			else
			{
				// Try as numeric index
				char* endptr;
				long index = strtol(prop_name, &endptr, 10);
				if (*endptr == '\0' && index >= 0)
				{
					setArrayElement(app_context, arr, (u32)index, &value_var);
				}
			}
		}
	}
	// If it's not an object or array type, we silently ignore the operation
	// (Flash behavior for setting properties on non-objects)
}

void actionInitObject(SWFAppContext* app_context)
{
	// Step 1: Pop property count from stack
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);
	u32 num_props = (u32) varToInt32(&count_var);

#ifdef DEBUG
	printf("[DEBUG] actionInitObject: creating object with %u properties\n", num_props);
#endif

	// Step 2: Allocate object with the specified number of properties
	ASObject* obj = allocObject(app_context, num_props);
	if (obj == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate object in actionInitObject\n");
		// Push null/undefined object on error
		PUSH(ACTION_STACK_VALUE_OBJECT, 0);
		return;
	}

	// Step 3: Pop property value/name pairs from stack
	// SWF bytecode pushes name first, then value, so value is on top
	// Stack order is: [..., name1, value1, ..., nameN, valueN, count]
	// So after popping count, top of stack is valueN
	for (u32 i = 0; i < num_props; i++)
	{
		// Pop property value first (it's on top)
		ActionVar value;
		popVar(app_context, &value);

		// Pop property name (it's below the value)
		ActionVar name_var;
		popVar(app_context, &name_var);
		const char* name = NULL;
		u32 name_length = 0;

		// Handle string name
		if (name_var.type == ACTION_STACK_VALUE_STRING)
		{
			name = name_var.data.string_data.owns_memory ?
				name_var.data.string_data.heap_ptr :
				(const char*) name_var.data.numeric_value;
			name_length = name_var.str_size;
		}
		else
		{
			// If name is not a string, skip this property
			fprintf(stderr, "WARNING: Property name is not a string (type=%d), skipping\n", name_var.type);
			continue;
		}

#ifdef DEBUG
		printf("[DEBUG] actionInitObject: setting property '%.*s'\n", name_length, name);
#endif

		// Store property using the object API
		// This handles refcount management if value is an object
		setProperty(app_context, obj, name, name_length, &value);
	}

	// Set __proto__ to Object.prototype for prototype chain inheritance
	setObjectProto(app_context, obj);

	// Step 4: Push object reference to stack
	// The object has refcount = 1 from allocation
	PUSH(ACTION_STACK_VALUE_OBJECT, (u64) obj);

#ifdef DEBUG
	printf("[DEBUG] actionInitObject: pushed object %p to stack\n", (void*)obj);
#endif
}

// Helper function to push undefined value
static void pushUndefined(SWFAppContext* app_context)
{
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
}

void actionDelete(SWFAppContext* app_context)
{
	// Stack layout (from top to bottom):
	// 1. property_name (string) - name of property to delete
	// 2. object_name (string) - name of variable containing the object

	// Pop property name
	ActionVar prop_name_var;
	popVar(app_context, &prop_name_var);

	const char* prop_name = NULL;
	u32 prop_name_len = 0;

	if (prop_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		prop_name = prop_name_var.data.string_data.owns_memory ?
			prop_name_var.data.string_data.heap_ptr :
			(const char*) prop_name_var.data.numeric_value;
		prop_name_len = prop_name_var.str_size;
	}
	else
	{
		// Property name must be a string
		// Return true (AS2 spec: returns true for invalid operations)
		float result = 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Pop object name (variable name)
	ActionVar obj_name_var;
	popVar(app_context, &obj_name_var);

	const char* obj_name = NULL;
	u32 obj_name_len = 0;

	if (obj_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		obj_name = obj_name_var.data.string_data.owns_memory ?
			obj_name_var.data.string_data.heap_ptr :
			(const char*) obj_name_var.data.numeric_value;
		obj_name_len = obj_name_var.str_size;
	}
	else
	{
		// Object name must be a string
		// Return true (AS2 spec: returns true for invalid operations)
		float result = 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Look up the variable to get the object
	ActionVar* obj_var = getVariable((char*)obj_name, obj_name_len);

	// If variable doesn't exist, return true (AS2 spec)
	if (obj_var == NULL)
	{
		float result = 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// If variable is not an object, return true (AS2 spec)
	if (obj_var->type != ACTION_STACK_VALUE_OBJECT)
	{
		float result = 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Get the object
	ASObject* obj = (ASObject*) obj_var->data.numeric_value;

	// If object is NULL, return true
	if (obj == NULL)
	{
		float result = 1.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Delete the property
	bool success = deleteProperty(app_context, obj, prop_name, prop_name_len);

	// Push result (1.0 for success, 0.0 for failure)
	float result = success ? 1.0f : 0.0f;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionGetMember(SWFAppContext* app_context)
{
	// 1. Convert and pop property name (top of stack)
	char str_buffer[17];
	convertString(app_context, str_buffer);
	const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 prop_name_len = STACK_TOP_N;
	POP();

	// 2. Pop object (second on stack)
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// 3. Handle different object types
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Handle AS object
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj == NULL)
		{
			pushUndefined(app_context);
			return;
		}

		// Look up property with prototype chain support
		ActionVar* prop = getPropertyWithPrototype(obj, prop_name, prop_name_len);

		if (prop != NULL)
		{
			// Property found - push its value
			pushVar(app_context, prop);
		}
		else
		{
			// Property not found - push undefined
			pushUndefined(app_context);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// Handle string properties
		if (strcmp(prop_name, "length") == 0)
		{
			// Get string pointer
			const char* str = obj_var.data.string_data.owns_memory ?
				obj_var.data.string_data.heap_ptr :
				(const char*) obj_var.data.numeric_value;

			// Push length as float (UTF-8 character count, not byte count)
			float len = (float) utf8_strlen(str);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &len));
		}
		else
		{
			// Other properties don't exist on strings
			pushUndefined(app_context);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_ARRAY)
	{
		// Handle array properties
		ASArray* arr = (ASArray*) obj_var.data.numeric_value;

		if (arr == NULL)
		{
			pushUndefined(app_context);
			return;
		}

		// Check if accessing the "length" property
		if (strcmp(prop_name, "length") == 0)
		{
			// Push array length as float
			float len = (float) arr->length;
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &len));
		}
		else
		{
			// Try to parse property name as an array index
			char* endptr;
			long index = strtol(prop_name, &endptr, 10);

			// Check if conversion was successful and entire string was consumed
			if (*endptr == '\0' && index >= 0)
			{
				// Valid numeric index
				ActionVar* elem = getArrayElement(arr, (u32)index);
				if (elem != NULL)
				{
					// Element exists - push its value
					pushVar(app_context, elem);
				}
				else
				{
					// Index out of bounds - push undefined
					pushUndefined(app_context);
				}
			}
			else
			{
				// Non-numeric property name - arrays don't have other properties
				pushUndefined(app_context);
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		// Handle function properties (e.g., MyClass.prototype)
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;
		if (func != NULL && strcmp(prop_name, "prototype") == 0)
		{
			// Lazily create prototype object on first access
			if (func->prototype_obj == NULL)
			{
				func->prototype_obj = allocObject(app_context, 4);
				retainObject(func->prototype_obj);
				// Set Object.prototype as __proto__ for prototype chain
				setObjectProto(app_context, func->prototype_obj);
			}
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64) func->prototype_obj);
		}
		else
		{
			pushUndefined(app_context);
		}
	}
	else
	{
		// Other primitive types (number, undefined, etc.) - push undefined
		pushUndefined(app_context);
	}
}

void actionNewObject(SWFAppContext* app_context)
{
	// 1. Pop constructor name (string)
	ActionVar ctor_name_var;
	popVar(app_context, &ctor_name_var);
	const char* ctor_name;
	u32 ctor_name_len;
	if (ctor_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		ctor_name = ctor_name_var.data.string_data.owns_memory ?
			ctor_name_var.data.string_data.heap_ptr :
			(const char*) ctor_name_var.data.numeric_value;
		ctor_name_len = ctor_name_var.str_size;
	}
	else
	{
		// Fallback if not a string (shouldn't happen in normal cases)
		ctor_name = "Object";
		ctor_name_len = 6;
	}

	// 2. Pop number of arguments
	convertFloat(app_context);
	ActionVar num_args_var;
	popVar(app_context, &num_args_var);
	u32 num_args = (u32) varToInt32(&num_args_var);

	// 3. Pop arguments from stack (store them temporarily)
	// Limit to 16 arguments for simplicity
	ActionVar args[16];
	if (num_args > 16)
	{
		num_args = 16;
	}

	// Pop arguments: SWF pushes last arg first, so first arg is on top of stack
	for (u32 i = 0; i < num_args; i++)
	{
		popVar(app_context, &args[i]);
	}

	// 4. Create new object based on constructor name
	void* new_obj = NULL;
	ActionStackValueType obj_type = ACTION_STACK_VALUE_OBJECT;

	if (strcmp(ctor_name, "Array") == 0)
	{
		// Handle Array constructor
		if (num_args == 0)
		{
			// new Array() - empty array
			ASArray* arr = allocArray(app_context, 4);
			arr->length = 0;
			new_obj = arr;
		}
		else if (num_args == 1 &&
		         (args[0].type == ACTION_STACK_VALUE_F32 ||
		          args[0].type == ACTION_STACK_VALUE_F64))
		{
			// new Array(length) - array with specified length
			float length_f = (args[0].type == ACTION_STACK_VALUE_F32) ?
				VAL(float, &args[0].data.numeric_value) :
				(float) VAL(double, &args[0].data.numeric_value);
			u32 length = (u32) length_f;
			ASArray* arr = allocArray(app_context, length > 0 ? length : 4);
			arr->length = length;
			new_obj = arr;
		}
		else
		{
			// new Array(elem1, elem2, ...) - array with elements
			ASArray* arr = allocArray(app_context, num_args);
			arr->length = num_args;
			for (u32 i = 0; i < num_args; i++)
			{
				arr->elements[i] = args[i];
				// Retain if object/array
				if (args[i].type == ACTION_STACK_VALUE_OBJECT)
				{
					retainObject((ASObject*) args[i].data.numeric_value);
				}
				else if (args[i].type == ACTION_STACK_VALUE_ARRAY)
				{
					retainArray((ASArray*) args[i].data.numeric_value);
				}
			}
			new_obj = arr;
		}
		obj_type = ACTION_STACK_VALUE_ARRAY;
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Object") == 0)
	{
		// Handle Object constructor
		// Create empty object with initial capacity
		ASObject* obj = allocObject(app_context, 8);
		setObjectProto(app_context, obj);
		new_obj = obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Date") == 0)
	{
		// Handle Date constructor
		// In a full implementation, this would parse date arguments
		// For now, create object with basic time property set to current time
		ASObject* date = allocObject(app_context, 4);

		// Set time property to current milliseconds since epoch
		ActionVar time_var;
		time_var.type = ACTION_STACK_VALUE_F64;
		double current_time = (double)time(NULL) * 1000.0;  // Convert to milliseconds
		VAL(double, &time_var.data.numeric_value) = current_time;
		setProperty(app_context, date, "time", 4, &time_var);

		new_obj = date;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "String") == 0)
	{
		// Handle String constructor
		// new String() or new String(value)
		ASObject* str_obj = allocObject(app_context, 4);

		// If argument provided, convert to string and store as value property
		if (num_args > 0)
		{
			// Convert first argument to string
			char str_buffer[256];
			const char* str_value = "";

			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				str_value = args[0].data.string_data.owns_memory ?
					args[0].data.string_data.heap_ptr :
					(const char*) args[0].data.numeric_value;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				snprintf(str_buffer, sizeof(str_buffer), "%.15g", VAL(float, &args[0].data.numeric_value));
				str_value = str_buffer;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				snprintf(str_buffer, sizeof(str_buffer), "%.15g", VAL(double, &args[0].data.numeric_value));
				str_value = str_buffer;
			}

			// Store as property
			ActionVar value_var;
			value_var.type = ACTION_STACK_VALUE_STRING;
			value_var.str_size = strlen(str_value);
			value_var.data.string_data.heap_ptr = strdup(str_value);
			value_var.data.string_data.owns_memory = true;
			setProperty(app_context, str_obj, "value", 5, &value_var);
		}

		new_obj = str_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Number") == 0)
	{
		// Handle Number constructor
		// new Number() or new Number(value)
		ASObject* num_obj = allocObject(app_context, 4);

		// Store numeric value as property
		ActionVar value_var;
		if (num_args > 0)
		{
			// Convert first argument to number
			if (args[0].type == ACTION_STACK_VALUE_F32 || args[0].type == ACTION_STACK_VALUE_F64)
			{
				value_var = args[0];
			}
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				const char* str = args[0].data.string_data.owns_memory ?
					args[0].data.string_data.heap_ptr :
					(const char*) args[0].data.numeric_value;
				double num = atof(str);
				value_var.type = ACTION_STACK_VALUE_F64;
				VAL(double, &value_var.data.numeric_value) = num;
			}
			else
			{
				// Default to 0
				value_var.type = ACTION_STACK_VALUE_F32;
				VAL(float, &value_var.data.numeric_value) = 0.0f;
			}
		}
		else
		{
			// No arguments - default to 0
			value_var.type = ACTION_STACK_VALUE_F32;
			VAL(float, &value_var.data.numeric_value) = 0.0f;
		}

		setProperty(app_context, num_obj, "value", 5, &value_var);
		new_obj = num_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Boolean") == 0)
	{
		// Handle Boolean constructor
		// new Boolean() or new Boolean(value)
		ASObject* bool_obj = allocObject(app_context, 4);

		// Store boolean value as property
		ActionVar value_var;
		value_var.type = ACTION_STACK_VALUE_F32;

		if (num_args > 0)
		{
			// Convert first argument to boolean (0 or 1)
			float bool_val = 0.0f;

			if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				bool_val = (VAL(float, &args[0].data.numeric_value) != 0.0f) ? 1.0f : 0.0f;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				bool_val = (VAL(double, &args[0].data.numeric_value) != 0.0) ? 1.0f : 0.0f;
			}
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				const char* str = args[0].data.string_data.owns_memory ?
					args[0].data.string_data.heap_ptr :
					(const char*) args[0].data.numeric_value;
				bool_val = (str != NULL && strlen(str) > 0) ? 1.0f : 0.0f;
			}

			VAL(float, &value_var.data.numeric_value) = bool_val;
		}
		else
		{
			// No arguments - default to false
			VAL(float, &value_var.data.numeric_value) = 0.0f;
		}

		setProperty(app_context, bool_obj, "value", 5, &value_var);
		new_obj = bool_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else
	{
		// Try to find user-defined constructor function
		ASFunction* ctor_func = lookupFunctionByName(ctor_name, ctor_name_len);

		if (ctor_func != NULL)
		{
			// User-defined constructor found
			// Create new object to serve as 'this'
			ASObject* obj = allocObject(app_context, 8);
			new_obj = obj;

			// Set __proto__ to constructor's prototype (for prototype chain inheritance)
			if (ctor_func->prototype_obj != NULL)
			{
				ActionVar proto_var;
				proto_var.type = ACTION_STACK_VALUE_OBJECT;
				proto_var.str_size = 0;
				proto_var.data.numeric_value = (u64) ctor_func->prototype_obj;
				setProperty(app_context, obj, "__proto__", 9, &proto_var);
			}

			// Call the constructor with 'this' binding
			if (ctor_func->function_type == 1)
			{
				// DefineFunction (type 1) - simple function
				// Set 'this' variable to new object, push args, call constructor
				if (ctor_func->simple_func != NULL)
				{
					// Set 'this' as a local variable so GetVariable("this") finds it
					ActionVar this_var;
					this_var.type = ACTION_STACK_VALUE_OBJECT;
					this_var.str_size = 0;
					this_var.data.numeric_value = (u64) obj;
					setVariableByName("this", &this_var);

					// Push arguments onto stack for parameter binding
					// Arguments are already in args[] in pop order (first arg = args[0])
					// But DefineFunction binds params by popping, so push in reverse
					for (int i = (int)num_args - 1; i >= 0; i--)
					{
						pushVar(app_context, &args[i]);
					}

					g_call_depth++;
					ActionVar return_value;
					return_value = ((ActionVar(*)(SWFAppContext*))ctor_func->simple_func)(app_context);
					g_call_depth--;

					// Per ECMAScript spec: if constructor returns object, use it
					if (return_value.type == ACTION_STACK_VALUE_OBJECT && return_value.data.numeric_value != 0)
					{
						releaseObject(app_context, obj);
						new_obj = (ASObject*) return_value.data.numeric_value;
						retainObject((ASObject*) new_obj);
					}
				}
			}
			else if (ctor_func->function_type == 2)
			{
				// DefineFunction2 (type 2) - advanced function with registers
				// This supports 'this' binding and proper constructor semantics

				// Prepare arguments for the constructor
				ActionVar registers[256] = {0};  // Max registers

				// Call constructor with 'this' binding
				// Note: Return value is discarded per ActionScript spec for constructors
				if (ctor_func->advanced_func != NULL)
				{
					ActionVar return_value = ctor_func->advanced_func(app_context, args, num_args, registers, obj);

					// Check if constructor returned an object (override default behavior)
					// Per ECMAScript spec: if constructor returns object, use it; otherwise use 'this'
					if (return_value.type == ACTION_STACK_VALUE_OBJECT && return_value.data.numeric_value != 0)
					{
						// Constructor returned an object - use it instead of default 'this'
						releaseObject(app_context, obj);  // Release the originally created object
						new_obj = (ASObject*) return_value.data.numeric_value;
						retainObject((ASObject*) new_obj);  // Retain the returned object
					}
					// Note: If constructor returns non-object, we use the original 'this' object
				}
			}

			PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
			return;
		}
		else
		{
			// Unknown constructor - create generic object
			ASObject* obj = allocObject(app_context, 8);
			new_obj = obj;
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
			return;
		}
	}
}

/**
 * ActionNewMethod (0x53) - Create new object by calling method on object as constructor
 *
 * Stack layout: [method_name] [object] [num_args] [arg1] [arg2] ... <- sp
 *
 * SWF Specification behavior:
 * 1. Pops the name of the method from the stack
 * 2. Pops the ScriptObject from the stack
 *    - If method name is blank: object is treated as function object (constructor)
 *    - If method name not blank: named method of object is invoked as constructor
 * 3. Pops the number of arguments from the stack
 * 4. Executes the method call as constructor
 * 5. Pushes the newly constructed object to the stack
 *
 * Current implementation:
 * - Built-in constructors supported: Array, Object, Date, String, Number, Boolean
 * - String/Number/Boolean wrapper objects store primitive values in 'valueOf' property
 * - Function objects as constructors: SUPPORTED (blank method name with function object)
 * - User-defined constructors: SUPPORTED (method property containing function object)
 * - 'this' binding: SUPPORTED for DefineFunction2, limited for DefineFunction
 * - Constructor return value: Discarded per spec (always returns new object)
 *
 * Remaining limitations:
 * - Prototype chains not implemented (requires __proto__ property support)
 * - DefineFunction (type 1) has limited 'this' context support
 */
void actionNewMethod(SWFAppContext* app_context)
{
	// Pop in order: method_name, object, num_args, then args

	// 1. Pop method name (string)
	char str_buffer[17];
	convertString(app_context, str_buffer);
	const char* method_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 method_name_len = STACK_TOP_N;
	POP();

	// 2. Pop object reference
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// 3. Pop number of arguments
	convertFloat(app_context);
	ActionVar num_args_var;
	popVar(app_context, &num_args_var);
	u32 num_args = (u32) varToInt32(&num_args_var);

	// 4. Pop arguments from stack (store them temporarily)
	// Limit to 16 arguments for simplicity
	ActionVar args[16];
	if (num_args > 16)
	{
		num_args = 16;
	}

	// Pop arguments: SWF pushes last arg first, so first arg is on top
	for (u32 i = 0; i < num_args; i++)
	{
		popVar(app_context, &args[i]);
	}

	// 5. Get the method property from the object
	const char* ctor_name = NULL;

	// Check for blank/empty method name (SWF spec: treat object as function)
	if (method_name == NULL || method_name_len == 0 || method_name[0] == '\0')
	{
		// Blank method name: object should be invoked as function/constructor
		// The object should be a function object (ACTION_STACK_VALUE_FUNCTION)
		if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* func = (ASFunction*) obj_var.data.numeric_value;

			if (func != NULL)
			{
				// Create new object for 'this' context
				ASObject* new_obj = allocObject(app_context, 8);

				// TODO: Set up prototype chain (new_obj.__proto__ = func.prototype)
				// This requires prototype support in the object system

				// Call function as constructor with 'this' binding
				ActionVar return_value;

				if (func->function_type == 2)
				{
					// DefineFunction2 with full register support
					ActionVar* registers = NULL;
					if (func->register_count > 0) {
						registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
					}

					// Create local scope for function
					ASObject* local_scope = allocObject(app_context, 8);
					if (scope_depth < MAX_SCOPE_DEPTH) {
						scope_chain[scope_depth++] = local_scope;
					}

					// Call with 'this' context set to new object
					return_value = func->advanced_func(app_context, args, num_args, registers, new_obj);

					// Pop local scope
					if (scope_depth > 0) {
						scope_depth--;
					}
					releaseObject(app_context, local_scope);

					if (registers != NULL) FREE(registers);
				}
				else
				{
					// Simple DefineFunction (type 1)
					// Push arguments onto stack for the function
					for (u32 i = 0; i < num_args; i++)
					{
						pushVar(app_context, &args[i]);
					}

					// Call simple function (cast to correct return type — generated functions return ActionVar)
					return_value = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				}

				// According to SWF spec: constructor return value should be discarded
				// Always return the newly created object
				// (unless constructor explicitly returns an object, but we simplify here)
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
				return;
			}
		}

		// If not a function object, push undefined
		pushUndefined(app_context);
		return;
	}

	ASFunction* user_ctor_func = NULL;

	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj != NULL)
		{
			// Look up the method property
			ActionVar* method_prop = getProperty(obj, method_name, method_name_len);

			if (method_prop != NULL)
			{
				if (method_prop->type == ACTION_STACK_VALUE_STRING)
				{
					// Get constructor name from the property (for built-in constructors)
					ctor_name = method_prop->data.string_data.owns_memory ?
						method_prop->data.string_data.heap_ptr :
						(const char*) method_prop->data.numeric_value;
				}
				else if (method_prop->type == ACTION_STACK_VALUE_FUNCTION)
				{
					// Property is a user-defined function - use it as constructor
					user_ctor_func = (ASFunction*) method_prop->data.numeric_value;
				}
			}
		}
	}

	// 6. Create new object based on constructor name
	void* new_obj = NULL;

	if (ctor_name != NULL && strcmp(ctor_name, "Array") == 0)
	{
		// Handle Array constructor
		if (num_args == 0)
		{
			// new Array() - empty array
			ASArray* arr = allocArray(app_context, 4);
			arr->length = 0;
			new_obj = arr;
		}
		else if (num_args == 1 &&
		         (args[0].type == ACTION_STACK_VALUE_F32 ||
		          args[0].type == ACTION_STACK_VALUE_F64))
		{
			// new Array(length) - array with specified length
			float length_f = (args[0].type == ACTION_STACK_VALUE_F32) ?
				VAL(float, &args[0].data.numeric_value) :
				(float) VAL(double, &args[0].data.numeric_value);
			u32 length = (u32) length_f;
			ASArray* arr = allocArray(app_context, length > 0 ? length : 4);
			arr->length = length;
			new_obj = arr;
		}
		else
		{
			// new Array(elem1, elem2, ...) - array with elements
			ASArray* arr = allocArray(app_context, num_args);
			arr->length = num_args;
			for (u32 i = 0; i < num_args; i++)
			{
				arr->elements[i] = args[i];
				// Retain if object/array
				if (args[i].type == ACTION_STACK_VALUE_OBJECT)
				{
					retainObject((ASObject*) args[i].data.numeric_value);
				}
				else if (args[i].type == ACTION_STACK_VALUE_ARRAY)
				{
					retainArray((ASArray*) args[i].data.numeric_value);
				}
			}
			new_obj = arr;
		}
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) new_obj);
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Object") == 0)
	{
		// Handle Object constructor
		ASObject* obj = allocObject(app_context, 8);
		new_obj = obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Date") == 0)
	{
		// Handle Date constructor (simplified)
		ASObject* date = allocObject(app_context, 4);
		new_obj = date;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "String") == 0)
	{
		// Handle String constructor
		// new String() or new String(value)
		ASObject* str_obj = allocObject(app_context, 4);

		if (num_args > 0)
		{
			// Convert first argument to string and store it
			// Store the string value so it can be retrieved with valueOf() or toString()
			ActionVar string_value = args[0];

			// If not already a string, we'd need to convert it
			// For now, store the value as-is with property name "valueOf"
			setProperty(app_context, str_obj, "valueOf", 7, &string_value);
		}
		else
		{
			// new String() with no arguments - store empty string
			ActionVar empty_str;
			empty_str.type = ACTION_STACK_VALUE_STRING;
			empty_str.data.numeric_value = (u64) "";
			setProperty(app_context, str_obj, "valueOf", 7, &empty_str);
		}

		new_obj = str_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Number") == 0)
	{
		// Handle Number constructor
		// new Number() or new Number(value)
		ASObject* num_obj = allocObject(app_context, 4);

		if (num_args > 0)
		{
			// Store the numeric value
			ActionVar num_value = args[0];

			// Convert to float if not already numeric
			if (num_value.type != ACTION_STACK_VALUE_F32 &&
			    num_value.type != ACTION_STACK_VALUE_F64)
			{
				// For strings, convert to number
				if (num_value.type == ACTION_STACK_VALUE_STRING)
				{
					const char* str = num_value.data.string_data.owns_memory ?
						num_value.data.string_data.heap_ptr :
						(const char*) num_value.data.numeric_value;
					float fval = (float) atof(str);
					num_value.type = ACTION_STACK_VALUE_F32;
					num_value.data.numeric_value = VAL(u64, &fval);
				}
				else
				{
					// Default to 0 for other types
					float zero = 0.0f;
					num_value.type = ACTION_STACK_VALUE_F32;
					num_value.data.numeric_value = VAL(u64, &zero);
				}
			}

			setProperty(app_context, num_obj, "valueOf", 7, &num_value);
		}
		else
		{
			// new Number() with no arguments - store 0
			ActionVar zero_val;
			float zero = 0.0f;
			zero_val.type = ACTION_STACK_VALUE_F32;
			zero_val.data.numeric_value = VAL(u64, &zero);
			setProperty(app_context, num_obj, "valueOf", 7, &zero_val);
		}

		new_obj = num_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Boolean") == 0)
	{
		// Handle Boolean constructor
		// new Boolean() or new Boolean(value)
		ASObject* bool_obj = allocObject(app_context, 4);

		if (num_args > 0)
		{
			// Convert first argument to boolean
			// In ActionScript/JavaScript, false values are: false, 0, NaN, "", null, undefined
			ActionVar bool_value;
			bool truthy = true;  // Default to true

			if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				float fval = VAL(float, &args[0].data.numeric_value);
				truthy = (fval != 0.0f && !isnan(fval));
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				double dval = VAL(double, &args[0].data.numeric_value);
				truthy = (dval != 0.0 && !isnan(dval));
			}
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				const char* str = args[0].data.string_data.owns_memory ?
					args[0].data.string_data.heap_ptr :
					(const char*) args[0].data.numeric_value;
				truthy = (str != NULL && str[0] != '\0');
			}
			else if (args[0].type == ACTION_STACK_VALUE_UNDEFINED)
			{
				truthy = false;
			}

			// Store as a number (1.0 for true, 0.0 for false)
			float bool_as_float = truthy ? 1.0f : 0.0f;
			bool_value.type = ACTION_STACK_VALUE_F32;
			bool_value.data.numeric_value = VAL(u64, &bool_as_float);
			setProperty(app_context, bool_obj, "valueOf", 7, &bool_value);
		}
		else
		{
			// new Boolean() with no arguments - store false (0)
			ActionVar false_val;
			float zero = 0.0f;
			false_val.type = ACTION_STACK_VALUE_F32;
			false_val.data.numeric_value = VAL(u64, &zero);
			setProperty(app_context, bool_obj, "valueOf", 7, &false_val);
		}

		new_obj = bool_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
	else if (user_ctor_func != NULL)
	{
		// User-defined constructor function from object property
		// Create new object for 'this' context
		ASObject* new_obj_inst = allocObject(app_context, 8);

		// TODO: Set up prototype chain (new_obj.__proto__ = func.prototype)

		// Call function as constructor with 'this' binding
		ActionVar return_value;

		if (user_ctor_func->function_type == 2)
		{
			// DefineFunction2 with full register support
			ActionVar* registers = NULL;
			if (user_ctor_func->register_count > 0) {
				registers = (ActionVar*) calloc(user_ctor_func->register_count, sizeof(ActionVar));
			}

			// Create local scope for function
			ASObject* local_scope = allocObject(app_context, 8);
			if (scope_depth < MAX_SCOPE_DEPTH) {
				scope_chain[scope_depth++] = local_scope;
			}

			// Call with 'this' context set to new object
			return_value = user_ctor_func->advanced_func(app_context, args, num_args, registers, new_obj_inst);

			// Pop local scope
			if (scope_depth > 0) {
				scope_depth--;
			}
			releaseObject(app_context, local_scope);

			if (registers != NULL) FREE(registers);
		}
		else
		{
			// Simple DefineFunction (type 1)
			// Push arguments onto stack for the function
			for (u32 i = 0; i < num_args; i++)
			{
				pushVar(app_context, &args[i]);
			}

			// Call simple function (cast to correct return type — generated functions return ActionVar)
			return_value = ((ActionVar(*)(SWFAppContext*))user_ctor_func->simple_func)(app_context);
		}

		// According to SWF spec: constructor return value should be discarded
		// Always return the newly created object
		// (unless constructor explicitly returns an object, but we simplify here)
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj_inst);
	}
	else
	{
		// Method not found or not a valid constructor - push undefined
		pushUndefined(app_context);
	}
}

void actionSetProperty(SWFAppContext* app_context)
{
	// Stack layout: [target_path] [property_index] [value] <- sp
	// Pop in reverse order: value, index, target

	// 1. Pop value
	ActionVar value_var;
	popVar(app_context, &value_var);

	// 2. Pop property index
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int prop_index = varToInt32(&index_var);

	// 3. Pop target path
	convertString(app_context, NULL);
	const char* target = (const char*) VAL(u64, &STACK_TOP_VALUE);
	POP();

	// 4. Get the MovieClip object
	MovieClip* mc = getMovieClipByTarget(target);
	if (!mc) return; // Invalid target

	// 5. Set property value based on index
	// Convert value to float for numeric properties
	float num_value = 0.0f;
	const char* str_value = NULL;

	if (value_var.type == ACTION_STACK_VALUE_F32 || value_var.type == ACTION_STACK_VALUE_F64) {
		num_value = (float) VAL(float, &value_var.data.numeric_value);
	} else if (value_var.type == ACTION_STACK_VALUE_STRING) {
		str_value = (const char*) value_var.data.numeric_value;
		num_value = (float) atof(str_value);
	}

	switch (prop_index) {
		case 0:  // _x
			mc->x = num_value;
			break;
		case 1:  // _y
			mc->y = num_value;
			break;
		case 2:  // _xscale
			mc->xscale = num_value;
			break;
		case 3:  // _yscale
			mc->yscale = num_value;
			break;
		case 6:  // _alpha
			mc->alpha = num_value;
			break;
		case 7:  // _visible
			mc->visible = (num_value != 0.0f);
			break;
		case 8:  // _width
			mc->width = num_value;
			break;
		case 9:  // _height
			mc->height = num_value;
			break;
		case 10: // _rotation
			mc->rotation = num_value;
			break;
		case 13: // _name
			if (str_value) {
				strncpy(mc->name, str_value, sizeof(mc->name) - 1);
				mc->name[sizeof(mc->name) - 1] = '\0';
			}
			break;
		// Read-only properties - ignore silently
		case 4:  // _currentframe
		case 5:  // _totalframes
		case 11: // _target
		case 12: // _framesloaded
		case 14: // _droptarget
		case 15: // _url
		case 20: // _xmouse
		case 21: // _ymouse
			// Do nothing - these are read-only
			break;
		default:
			// Unknown property - ignore
			break;
	}
}

/**
 * ActionCloneSprite - Clones a sprite/MovieClip
 *
 * Stack: [ target_name, source_name, depth ] -> [ ]
 *
 * Pops three values from the stack:
 * - depth (number): z-order depth for the clone
 * - source (string): path to sprite to clone
 * - target (string): name for the new clone
 *
 * Creates a duplicate of the source MovieClip with the specified name at the given depth.
 *
 * Edge cases:
 * - Null/empty strings: Treated as empty string names
 * - Negative depth: Accepted (some Flash versions allow this)
 * - Non-existent source: No-op in NO_GRAPHICS mode; would fail silently in Flash
 *
 * SWF version: 4+
 * Opcode: 0x24
 */
void actionCloneSprite(SWFAppContext* app_context)
{
	// Stack layout: [target_name] [source_name] [depth] <- sp
	// Pop in reverse order: depth, source, target

	// Pop depth (convert to float first)
	convertFloat(app_context);
	ActionVar depth;
	popVar(app_context, &depth);

	// Pop source sprite name
	ActionVar source;
	popVar(app_context, &source);
	const char* source_name = (const char*) source.data.numeric_value;

	// Handle null source name
	if (source_name == NULL) {
		source_name = "";
	}

	// Pop target sprite name
	ActionVar target;
	popVar(app_context, &target);
	const char* target_name = (const char*) target.data.numeric_value;

	// Handle null target name
	if (target_name == NULL) {
		target_name = "";
	}

	#ifndef NO_GRAPHICS
	// Full implementation would:
	// 1. Find source MovieClip in display list
	// 2. Create deep copy of sprite and its children
	// 3. Add to display list at specified depth
	// 4. Assign new name
	cloneMovieClip(source_name, target_name, (int)VAL(float, &depth.data.numeric_value));
	#else
	// NO_GRAPHICS mode: Parameters are validated and popped
	// In full graphics mode, this would clone the MovieClip
	#ifdef DEBUG
	printf("[CloneSprite] source='%s' -> target='%s' (depth=%d)\n",
	       source_name, target_name, (int)VAL(float, &depth.data.numeric_value));
	#endif
	#endif
}

/**
 * ActionRemoveSprite (0x25) - Removes a clone sprite from the display list
 *
 * Stack: [ target ] -> [ ]
 *
 * Pops a target path (string) from the stack and removes the corresponding
 * clone movie clip from the display list. Only sprites created with
 * ActionCloneSprite can be removed (not sprites from the original SWF).
 *
 * Edge cases handled:
 * - Non-existent sprite: No error, silently ignored
 * - Empty string: No-op
 * - Null target: Handled gracefully (no crash)
 *
 * NO_GRAPHICS mode: This is a no-op as there's no display list
 * Graphics mode: Would remove sprite from display list and release resources
 *
 * SWF version: 4+
 * Opcode: 0x25
 */
void actionRemoveSprite(SWFAppContext* app_context)
{
	// Pop target sprite name from stack
	ActionVar target;
	popVar(app_context, &target);
	const char* target_name = (const char*) target.data.numeric_value;

	// Handle null/empty gracefully
	if (target_name == NULL || target_name[0] == '\0') {
		#ifdef DEBUG
		printf("[RemoveSprite] Empty or null target, skipping\n");
		#endif
		return;
	}

	#ifndef NO_GRAPHICS
	// TODO: Full graphics implementation requires:
	// 1. Display list management system
	// 2. MovieClip reference counting
	// 3. Proper resource cleanup
	//
	// When implemented, this should:
	// - Look up the target sprite in the display list
	// - Verify it's a clone (created by ActionCloneSprite)
	// - Remove it from the display list
	// - Decrement reference count and free if needed
	// - Update any parent/child relationships
	//
	// For now, log in debug mode
	#ifdef DEBUG
	printf("[RemoveSprite] Graphics mode stub: would remove %s\n", target_name);
	#endif
	#else
	// NO_GRAPHICS mode: This is a complete no-op
	// There's no display list to remove from
	#ifdef DEBUG
	printf("[RemoveSprite] %s\n", target_name);
	#endif
	#endif
}

void actionSetTarget(SWFAppContext* app_context, const char* target_name)
{
	// Empty string or NULL means return to main timeline
	if (!target_name || strlen(target_name) == 0) {
		setCurrentContext(&root_movieclip);
#ifndef NO_GRAPHICS
		targeted_sprite = NULL;
#endif
		return;
	}

	// Check for _root
	if (strcmp(target_name, "_root") == 0 || strcmp(target_name, "/") == 0) {
		setCurrentContext(&root_movieclip);
#ifndef NO_GRAPHICS
		targeted_sprite = NULL;
#endif
		return;
	}

#ifndef NO_GRAPHICS
	// Try to resolve as a named sprite in the display list
	DisplayObject* obj = findDisplayObjectByName(target_name);
	if (obj != NULL) {
		targeted_sprite = obj;
		return;
	}
#endif

	// Fallback to MovieClip resolution
	MovieClip* target_mc = getMovieClipByTarget(target_name);
	if (target_mc) {
		setCurrentContext(target_mc);
	}
}

// ==================================================================
// WITH Statement Implementation
// ==================================================================

void actionWithStart(SWFAppContext* app_context)
{
	// Pop object from stack
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Get the object pointer
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		// Push onto scope chain (if valid and space available)
		if (obj != NULL && scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_chain[scope_depth++] = obj;
#ifdef DEBUG
			printf("[DEBUG] actionWithStart: pushed object %p onto scope chain (depth=%u)\n", (void*)obj, scope_depth);
#endif
		}
		else
		{
			if (obj == NULL)
			{
				// Push null marker to maintain balance
				scope_chain[scope_depth++] = NULL;
#ifdef DEBUG
				printf("[DEBUG] actionWithStart: object is null, pushed null marker (depth=%u)\n", scope_depth);
#endif
			}
			else
			{
				fprintf(stderr, "ERROR: Scope chain overflow (depth=%u, max=%u)\n", scope_depth, MAX_SCOPE_DEPTH);
			}
		}
	}
	else
	{
		// Non-object type - push null marker to maintain balance
		if (scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_chain[scope_depth++] = NULL;
#ifdef DEBUG
			printf("[DEBUG] actionWithStart: non-object type %d, pushed null marker (depth=%u)\n", obj_var.type, scope_depth);
#endif
		}
	}
}

void actionWithEnd(SWFAppContext* app_context)
{
	// Pop from scope chain
	if (scope_depth > 0)
	{
		scope_depth--;
#ifdef DEBUG
		printf("[DEBUG] actionWithEnd: popped from scope chain (depth=%u)\n", scope_depth);
#endif
	}
	else
	{
		fprintf(stderr, "ERROR: actionWithEnd called with empty scope chain\n");
	}
}

// ============================================================================
// Exception Handling (Try-Catch-Finally)
// ============================================================================

// Exception state structure
#include <setjmp.h>

// TODO: Current setjmp/longjmp implementation has a critical flaw!
// The problem: setjmp is called inside actionTryExecute(), which is called from within
// the if statement. When longjmp is triggered, it returns to setjmp inside actionTryExecute,
// which then returns false. However, the C runtime is still executing inside the try block's
// code body, so execution continues from where longjmp was called rather than jumping to
// the catch block.
//
// Solution needed: Generate code that places setjmp at the script function level, not inside
// a helper function. The generated code should look like:
//
//   if (setjmp(exception_handler) == 0) {
//       // try block
//   } else {
//       // catch block
//   }
//
// This requires modifying the SWFRecomp translator to emit setjmp inline rather than
// calling actionTryExecute().

typedef struct {
	bool exception_thrown;
	ActionVar exception_value;
	int handler_depth;
	jmp_buf exception_handler;
	int has_jmp_buf;
} ExceptionState;

static ExceptionState g_exception_state = {false, {0}, 0, {0}, 0};

void actionThrow(SWFAppContext* app_context)
{
	// Pop value to throw
	ActionVar throw_value;
	popVar(app_context, &throw_value);

	// Set exception state
	g_exception_state.exception_thrown = true;
	g_exception_state.exception_value = throw_value;

	// Check if we're in a try block
	if (g_exception_state.handler_depth == 0) {
		// Uncaught exception - print error message and exit
		printf("[Uncaught exception: ");

		if (throw_value.type == ACTION_STACK_VALUE_STRING) {
			const char* str = (const char*) VAL(u64, &throw_value.data.numeric_value);
			printf("%s", str);
		} else if (throw_value.type == ACTION_STACK_VALUE_F32) {
			float val = VAL(float, &throw_value.data.numeric_value);
			printf("%g", val);
		} else if (throw_value.type == ACTION_STACK_VALUE_F64) {
			double val = VAL(double, &throw_value.data.numeric_value);
			printf("%g", val);
		} else {
			printf("(type %d)", throw_value.type);
		}

		printf("]\n");

		// Exit to stop script execution
		exit(1);
	}

	// Inside a try block - jump to catch handler using longjmp
	// NOTE: Due to current implementation flaw (see TODO above), this doesn't
	// properly skip remaining try block code. Fix requires inline setjmp in generated code.
	if (g_exception_state.has_jmp_buf) {
		longjmp(g_exception_state.exception_handler, 1);
	}
}

void actionTryBegin(SWFAppContext* app_context)
{
	// Push exception handler onto handler stack
	g_exception_state.handler_depth++;

	// Clear exception flag for new try block
	g_exception_state.exception_thrown = false;
	g_exception_state.has_jmp_buf = 0;
}

bool actionTryExecute(SWFAppContext* app_context)
{
	// Set up exception handler using setjmp
	// This will be called again when longjmp is triggered
	// WARNING: This function-based approach has a control flow flaw (see TODO above)
	int exception_occurred = setjmp(g_exception_state.exception_handler);
	g_exception_state.has_jmp_buf = 1;

	// If exception occurred (longjmp was called), return false to execute catch block
	if (exception_occurred != 0) {
		g_exception_state.exception_thrown = true;
		return false;
	}

	// No exception yet, execute try block
	return true;
}

jmp_buf* actionGetExceptionJmpBuf(SWFAppContext* app_context)
{
	// Return pointer to the exception handler jump buffer
	// This allows setjmp to be called inline in generated code
	g_exception_state.has_jmp_buf = 1;
	return &g_exception_state.exception_handler;
}

void actionCatchToVariable(SWFAppContext* app_context, const char* var_name)
{
	// Store caught exception in named variable
	if (g_exception_state.exception_thrown)
	{
		setVariableByName(var_name, &g_exception_state.exception_value);
		g_exception_state.exception_thrown = false;
	}
}

void actionCatchToRegister(SWFAppContext* app_context, u8 reg_num)
{
	// Store caught exception in register
	if (g_exception_state.exception_thrown)
	{
#ifdef DEBUG
		printf("[DEBUG] actionCatchToRegister: storing exception in register %d\n", reg_num);
#endif
		// Validate register number
		if (reg_num >= MAX_REGISTERS) {
			fprintf(stderr, "ERROR: Invalid register number %d for catch\n", reg_num);
			g_exception_state.exception_thrown = false;
			return;
		}

		// Store exception value in the specified register
		g_registers[reg_num] = g_exception_state.exception_value;

		// Clear the exception flag
		g_exception_state.exception_thrown = false;
	}
}

void actionTryEnd(SWFAppContext* app_context)
{
	// Pop exception handler from handler stack
	g_exception_state.handler_depth--;

	// Clear jmp_buf flag
	g_exception_state.has_jmp_buf = 0;

	if (g_exception_state.handler_depth == 0)
	{
		// Clear exception if at top level
		g_exception_state.exception_thrown = false;
	}

#ifdef DEBUG
	printf("[DEBUG] actionTryEnd: handler_depth=%d\n", g_exception_state.handler_depth);
#endif
}

// ============================================================================

void actionDefineFunction(SWFAppContext* app_context, const char* name, void (*func)(SWFAppContext*), u32 param_count)
{
	// Create function object
	ASFunction* as_func = (ASFunction*) malloc(sizeof(ASFunction));
	if (as_func == NULL) {
		fprintf(stderr, "ERROR: Failed to allocate memory for function\n");
		return;
	}

	// Initialize function object
	strncpy(as_func->name, name, 255);
	as_func->name[255] = '\0';
	as_func->function_type = 1;  // Simple function
	as_func->param_count = param_count;
	as_func->simple_func = (SimpleFunctionPtr) func;
	as_func->advanced_func = NULL;
	as_func->register_count = 0;
	as_func->flags = 0;
	as_func->prototype_obj = NULL;

	// Register function
	if (function_count < MAX_FUNCTIONS) {
		function_registry[function_count++] = as_func;
	} else {
		fprintf(stderr, "ERROR: Function registry full\n");
		free(as_func);
		return;
	}

	// If named, store in variable
	if (strlen(name) > 0) {
		ActionVar func_var;
		func_var.type = ACTION_STACK_VALUE_FUNCTION;
		func_var.str_size = 0;
		func_var.data.numeric_value = (u64) as_func;
		setVariableByName(name, &func_var);
	} else {
		// Anonymous function: push to stack
		PUSH(ACTION_STACK_VALUE_FUNCTION, (u64) as_func);
	}
}

void actionDefineFunction2(SWFAppContext* app_context, const char* name, Function2Ptr func, u32 param_count, u8 register_count, u16 flags)
{
	// Create function object
	ASFunction* as_func = (ASFunction*) malloc(sizeof(ASFunction));
	if (as_func == NULL) {
		fprintf(stderr, "ERROR: Failed to allocate memory for function\n");
		return;
	}

	// Initialize function object
	strncpy(as_func->name, name, 255);
	as_func->name[255] = '\0';
	as_func->function_type = 2;  // Advanced function
	as_func->param_count = param_count;
	as_func->simple_func = NULL;
	as_func->advanced_func = func;
	as_func->register_count = register_count;
	as_func->flags = flags;
	as_func->prototype_obj = NULL;

	// Register function
	if (function_count < MAX_FUNCTIONS) {
		function_registry[function_count++] = as_func;
	} else {
		fprintf(stderr, "ERROR: Function registry full\n");
		free(as_func);
		return;
	}

	// If named, store in variable
	if (strlen(name) > 0) {
		ActionVar func_var;
		func_var.type = ACTION_STACK_VALUE_FUNCTION;
		func_var.str_size = 0;
		func_var.data.numeric_value = (u64) as_func;
		setVariableByName(name, &func_var);
	} else {
		// Anonymous function: push to stack
		PUSH(ACTION_STACK_VALUE_FUNCTION, (u64) as_func);
	}
}

void actionCallFunction(SWFAppContext* app_context, char* str_buffer)
{
	if (g_execution_halted) return;

	// 1. Pop function name (string) from stack
	char func_name_buffer[17];
	convertString(app_context, func_name_buffer);
	const char* func_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 func_name_len = STACK_TOP_N;
	POP();

	// 2. Pop number of arguments
	ActionVar num_args_var;
	popVar(app_context, &num_args_var);
	u32 num_args = 0;

	if (num_args_var.type == ACTION_STACK_VALUE_F32)
	{
		num_args = (u32) VAL(float, &num_args_var.data.numeric_value);
	}
	else if (num_args_var.type == ACTION_STACK_VALUE_F64)
	{
		num_args = (u32) VAL(double, &num_args_var.data.numeric_value);
	}

	// 3. Pop arguments from stack (in reverse order)
	ActionVar* args = NULL;
	if (num_args > 0)
	{
		args = (ActionVar*) HALLOC(sizeof(ActionVar) * num_args);
		for (u32 i = 0; i < num_args; i++)
		{
			popVar(app_context, &args[i]);
		}
	}

	// 4. Check for built-in global functions first
	int builtin_handled = 0;

	// parseInt(string) - Parse string to integer
	if (func_name_len == 8 && strncmp(func_name, "parseInt", 8) == 0)
	{
		if (num_args > 0)
		{
			// Convert first argument to string
			char arg_buffer[17];
			const char* str_value = NULL;

			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				str_value = (const char*) args[0].data.numeric_value;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				// Convert float to string
				float fval = VAL(float, &args[0].data.numeric_value);
				snprintf(arg_buffer, 17, "%.15g", fval);
				str_value = arg_buffer;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				// Convert double to string
				double dval = VAL(double, &args[0].data.numeric_value);
				snprintf(arg_buffer, 17, "%.15g", dval);
				str_value = arg_buffer;
			}
			else
			{
				// Undefined or other types -> NaN
				str_value = "NaN";
			}

			// Parse integer from string
			float result = (float) atoi(str_value);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
		else
		{
			// No arguments - return NaN
			if (args != NULL) FREE(args);
			float nan_val = 0.0f / 0.0f;
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &nan_val));
			builtin_handled = 1;
		}
	}
	// parseFloat(string) - Parse string to float
	else if (func_name_len == 10 && strncmp(func_name, "parseFloat", 10) == 0)
	{
		if (num_args > 0)
		{
			// Convert first argument to string
			char arg_buffer[17];
			const char* str_value = NULL;

			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				str_value = (const char*) args[0].data.numeric_value;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				// Convert float to string
				float fval = VAL(float, &args[0].data.numeric_value);
				snprintf(arg_buffer, 17, "%.15g", fval);
				str_value = arg_buffer;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				// Convert double to string
				double dval = VAL(double, &args[0].data.numeric_value);
				snprintf(arg_buffer, 17, "%.15g", dval);
				str_value = arg_buffer;
			}
			else
			{
				// Undefined or other types -> NaN
				str_value = "NaN";
			}

			// Parse float from string
			float result = (float) atof(str_value);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
		else
		{
			// No arguments - return NaN
			if (args != NULL) FREE(args);
			float nan_val = 0.0f / 0.0f;
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &nan_val));
			builtin_handled = 1;
		}
	}
	// isNaN(value) - Check if value is NaN
	else if (func_name_len == 5 && strncmp(func_name, "isNaN", 5) == 0)
	{
		if (num_args > 0)
		{
			// Convert to number and check if NaN
			float val = 0.0f;
			if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				val = VAL(float, &args[0].data.numeric_value);
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				val = (float) VAL(double, &args[0].data.numeric_value);
			}
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				// Try to parse as number
				const char* str = (const char*) args[0].data.numeric_value;
				val = (float) atof(str);
			}

			float result = (val != val) ? 1.0f : 0.0f;  // NaN != NaN is true
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
		else
		{
			// No arguments - isNaN(undefined) = true
			if (args != NULL) FREE(args);
			float result = 1.0f;
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
	}
	// isFinite(value) - Check if value is finite
	else if (func_name_len == 8 && strncmp(func_name, "isFinite", 8) == 0)
	{
		if (num_args > 0)
		{
			// Convert to number and check if finite
			float val = 0.0f;
			if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				val = VAL(float, &args[0].data.numeric_value);
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				val = (float) VAL(double, &args[0].data.numeric_value);
			}
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				const char* str = (const char*) args[0].data.numeric_value;
				val = (float) atof(str);
			}

			// Check if finite (not NaN and not infinity)
			float result = (val == val && val != INFINITY && val != -INFINITY) ? 1.0f : 0.0f;
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
		else
		{
			// No arguments - isFinite(undefined) = false
			if (args != NULL) FREE(args);
			float result = 0.0f;
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
			builtin_handled = 1;
		}
	}

	// Object(value) — wraps primitives in wrapper objects
	else if (func_name_len == 6 && strncmp(func_name, "Object", 6) == 0)
	{
		if (num_args > 0)
		{
			ActionVar* arg = &args[0];
			if (arg->type == ACTION_STACK_VALUE_OBJECT || arg->type == ACTION_STACK_VALUE_ARRAY ||
			    arg->type == ACTION_STACK_VALUE_FUNCTION)
			{
				// Object(object) returns the object itself
				ActionVar result = *arg;
				if (args != NULL) FREE(args);
				pushVar(app_context, &result);
			}
			else if (arg->type == ACTION_STACK_VALUE_NULL || arg->type == ACTION_STACK_VALUE_UNDEFINED)
			{
				// Object(null/undefined) returns empty object
				ASObject* obj = allocObject(app_context, 8);
				if (args != NULL) FREE(args);
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64)obj);
			}
			else
			{
				// Wrap number/boolean/string in an object with valueOf property
				ASObject* wrapper = allocObject(app_context, 4);
				setProperty(app_context, wrapper, "valueOf", 7, arg);
				if (args != NULL) FREE(args);
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64)wrapper);
			}
		}
		else
		{
			// Object() with no args returns empty object
			ASObject* obj = allocObject(app_context, 8);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)obj);
		}
		builtin_handled = 1;
	}

	// ASSetPropFlags(obj, props, clearFlags, setFlags)
	// Modifies property attribute flags for version-based visibility
	else if (func_name_len == 14 && strncmp(func_name, "ASSetPropFlags", 14) == 0)
	{
		if (num_args >= 4 && args[3].type == ACTION_STACK_VALUE_OBJECT)
		{
			ASObject* obj = (ASObject*)(u64)args[3].data.numeric_value;
			s32 clear_flags = varToInt32(&args[0]);
			s32 set_flags = varToInt32(&args[1]);

			// Get property name(s)
			const char* prop_name = NULL;
			u32 prop_name_len = 0;
			if (args[2].type == ACTION_STACK_VALUE_STRING)
			{
				prop_name = (const char*)args[2].data.numeric_value;
				prop_name_len = args[2].str_size;
			}

			if (obj != NULL && prop_name != NULL)
			{
				// Find property and modify its flash_flags
				for (u32 i = 0; i < obj->num_used; i++)
				{
					if (obj->properties[i].name_length == prop_name_len &&
					    strncmp(obj->properties[i].name, prop_name, prop_name_len) == 0)
					{
						obj->properties[i].flash_flags = (u16)((obj->properties[i].flash_flags & ~clear_flags) | set_flags);
						break;
					}
				}
			}
		}
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
		builtin_handled = 1;
	}

	// addProperty(name, getter, setter) — registers virtual getter/setter on _root
	else if (func_name_len == 11 && strncmp(func_name, "addProperty", 11) == 0)
	{
		float result = 0.0f;  // false by default

		if (num_args >= 3 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			const char* prop_name = (const char*) args[0].data.numeric_value;
			u32 prop_name_len = args[0].str_size;

			// Get getter function (arg 1)
			ASFunction* getter = NULL;
			if (args[1].type == ACTION_STACK_VALUE_FUNCTION)
			{
				getter = (ASFunction*) args[1].data.numeric_value;
			}

			// Get setter function (arg 2, can be null)
			ASFunction* setter = NULL;
			if (args[2].type == ACTION_STACK_VALUE_FUNCTION)
			{
				setter = (ASFunction*) args[2].data.numeric_value;
			}

			// Register in virtual property table
			if (virtual_property_count < MAX_VIRTUAL_PROPERTIES && prop_name_len < 256)
			{
				// Check if already exists — update in place
				VirtualProperty* existing = findVirtualProperty(prop_name, prop_name_len);
				if (existing != NULL)
				{
					existing->getter = getter;
					existing->setter = setter;
				}
				else
				{
					VirtualProperty* vp = &virtual_properties[virtual_property_count++];
					strncpy(vp->name, prop_name, prop_name_len);
					vp->name[prop_name_len] = '\0';
					vp->name_length = prop_name_len;
					vp->getter = getter;
					vp->setter = setter;
				}
				result = 1.0f;  // true = success
			}
		}

		if (args != NULL) FREE(args);
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		builtin_handled = 1;
	}

	// If not a built-in function, look up user-defined functions
	if (!builtin_handled)
	{
		ASFunction* func = lookupFunctionByName(func_name, func_name_len);

		if (func != NULL && g_call_depth >= g_max_call_depth - 1)
		{
			// Recursion depth limit reached - halt all script execution
			if (args != NULL) FREE(args);
			g_execution_halted = 1;
			pushUndefined(app_context);
		}
		else if (func != NULL)
		{
			g_call_depth++;

			if (func->function_type == 2)
			{
				// DefineFunction2 with registers and this context
				ActionVar* registers = NULL;
				if (func->register_count > 0) {
					registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
				}

				// Create local scope object for function-local variables
				// Start with capacity for a few local variables
				ASObject* local_scope = allocObject(app_context, 8);

				// Push local scope onto scope chain
				if (scope_depth < MAX_SCOPE_DEPTH) {
					scope_chain[scope_depth++] = local_scope;
				}

				ActionVar result = func->advanced_func(app_context, args, num_args, registers, NULL);

				// Pop local scope from scope chain
				if (scope_depth > 0) {
					scope_depth--;
				}

				// Clean up local scope object
				// Release decrements refcount and frees if refcount reaches 0
				releaseObject(app_context, local_scope);

				if (registers != NULL) FREE(registers);
				if (args != NULL) FREE(args);

				pushVar(app_context, &result);
			}
			else
			{
				// Simple DefineFunction (type 1)
				// Simple functions expect arguments on the stack, not in an array
				// We need to push arguments back onto stack in correct order

				// Remember stack position BEFORE pushing arguments
				// After function executes (pops args + pushes return), sp should be sp_before + 24
				u32 sp_before_args = SP;

				// Push arguments onto stack in order (first to last)
				// The function will pop them and bind to parameter names
				for (u32 i = 0; i < num_args; i++)
				{
					pushVar(app_context, &args[i]);
				}

				// Free args array before calling function
				if (args != NULL) FREE(args);

				// Call the simple function (cast to correct return type — generated functions return ActionVar)
				ActionVar func_result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				pushVar(app_context, &func_result);
			}

			g_call_depth--;
		}
		else
		{
			// Function not found - push undefined
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
	}
}

// Helper: convert an ActionVar to a string for array join/toString.
// Writes into buf (max buf_size chars), returns length written.
static int varToStringBuf(SWFAppContext* app_context, ActionVar* v, char* buf, int buf_size)
{
	if (v == NULL || v->type == ACTION_STACK_VALUE_UNDEFINED || v->type == ACTION_STACK_VALUE_NULL)
	{
		buf[0] = '\0';
		return 0;
	}
	switch (v->type)
	{
		case ACTION_STACK_VALUE_STRING:
		{
			const char* s = v->data.string_data.owns_memory ?
				v->data.string_data.heap_ptr : (const char*) v->data.numeric_value;
			if (s == NULL) { buf[0] = '\0'; return 0; }
			int len = snprintf(buf, buf_size, "%s", s);
			return len < buf_size ? len : buf_size - 1;
		}
		case ACTION_STACK_VALUE_F32:
		{
			float f = VAL(float, &v->data.numeric_value);
			if (isnan(f)) return snprintf(buf, buf_size, "NaN");
			if (isinf(f)) return snprintf(buf, buf_size, "%sInfinity", f < 0 ? "-" : "");
			int len = snprintf(buf, buf_size, "%.15g", (double)f);
			return len < buf_size ? len : buf_size - 1;
		}
		case ACTION_STACK_VALUE_F64:
		{
			double d = VAL(double, &v->data.numeric_value);
			if (isnan(d)) return snprintf(buf, buf_size, "NaN");
			if (isinf(d)) return snprintf(buf, buf_size, "%sInfinity", d < 0 ? "-" : "");
			int len = snprintf(buf, buf_size, "%.15g", d);
			return len < buf_size ? len : buf_size - 1;
		}
		case ACTION_STACK_VALUE_BOOLEAN:
			return snprintf(buf, buf_size, "%s", v->data.numeric_value ? "true" : "false");
		case ACTION_STACK_VALUE_ARRAY:
		{
			// Recursively convert nested array to comma-separated string
			ASArray* nested = (ASArray*) v->data.numeric_value;
			if (nested == NULL) { buf[0] = '\0'; return 0; }
			int pos = 0;
			for (u32 i = 0; i < nested->length && pos < buf_size - 1; i++)
			{
				if (i > 0 && pos < buf_size - 1) buf[pos++] = ',';
				ActionVar* elem = getArrayElement(nested, i);
				char elem_str[64];
				int elen = varToStringBuf(app_context, elem, elem_str, sizeof(elem_str));
				for (int j = 0; j < elen && pos < buf_size - 1; j++)
					buf[pos++] = elem_str[j];
			}
			buf[pos] = '\0';
			return pos;
		}
		case ACTION_STACK_VALUE_OBJECT:
		case ACTION_STACK_VALUE_MOVIECLIP:
			return snprintf(buf, buf_size, "[object Object]");
		case ACTION_STACK_VALUE_FUNCTION:
			return snprintf(buf, buf_size, "[type Function]");
		default:
			buf[0] = '\0';
			return 0;
	}
}

// Helper: convert ActionVar to double for array methods
static double varToDoubleSimple(ActionVar* v)
{
	if (v == NULL) return 0.0;
	switch (v->type)
	{
		case ACTION_STACK_VALUE_F32: return (double) VAL(float, &v->data.numeric_value);
		case ACTION_STACK_VALUE_F64: return VAL(double, &v->data.numeric_value);
		case ACTION_STACK_VALUE_BOOLEAN: return v->data.numeric_value ? 1.0 : 0.0;
		case ACTION_STACK_VALUE_STRING:
		{
			const char* s = v->data.string_data.owns_memory ?
				v->data.string_data.heap_ptr : (const char*) v->data.numeric_value;
			if (s == NULL) return 0.0;
			char* endptr;
			double d = strtod(s, &endptr);
			if (endptr == s) return NAN;
			return d;
		}
		case ACTION_STACK_VALUE_NULL: return 0.0;
		default: return NAN;
	}
}

// Helper function to call built-in array methods
// Returns 1 if method was handled, 0 if not found
static int callArrayMethod(SWFAppContext* app_context,
                           ASArray* arr,
                           const char* method_name, u32 method_name_len,
                           ActionVar* args, u32 num_args)
{
	// push(elem1, elem2, ...) - add elements, return new length
	if (method_name_len == 4 && strncmp(method_name, "push", 4) == 0)
	{
		for (u32 i = 0; i < num_args; i++)
		{
			setArrayElement(app_context, arr, arr->length, &args[i]);
		}
		double len = (double) arr->length;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &len));
		return 1;
	}

	// pop() - remove and return last element
	if (method_name_len == 3 && strncmp(method_name, "pop", 3) == 0)
	{
		if (arr->length == 0)
		{
			pushUndefined(app_context);
		}
		else
		{
			arr->length--;
			ActionVar* elem = &arr->elements[arr->length];
			pushVar(app_context, elem);
		}
		return 1;
	}

	// shift() - remove and return first element
	if (method_name_len == 5 && strncmp(method_name, "shift", 5) == 0)
	{
		if (arr->length == 0)
		{
			pushUndefined(app_context);
		}
		else
		{
			ActionVar first = arr->elements[0];
			for (u32 i = 0; i < arr->length - 1; i++)
			{
				arr->elements[i] = arr->elements[i + 1];
			}
			arr->length--;
			pushVar(app_context, &first);
		}
		return 1;
	}

	// unshift(elem1, ...) - prepend elements, return new length
	if (method_name_len == 7 && strncmp(method_name, "unshift", 7) == 0)
	{
		if (num_args > 0)
		{
			// Ensure capacity
			u32 new_length = arr->length + num_args;
			while (new_length > arr->capacity)
			{
				u32 new_cap = arr->capacity * 2;
				if (new_cap < new_length) new_cap = new_length;
				arr->elements = (ActionVar*) realloc(arr->elements, sizeof(ActionVar) * new_cap);
				arr->capacity = new_cap;
			}
			// Shift existing elements right
			for (int i = (int)arr->length - 1; i >= 0; i--)
			{
				arr->elements[i + num_args] = arr->elements[i];
			}
			// Insert new elements at front
			for (u32 i = 0; i < num_args; i++)
			{
				arr->elements[i] = args[i];
			}
			arr->length = new_length;
		}
		double len = (double) arr->length;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &len));
		return 1;
	}

	// reverse() - reverse in place, return array ref
	if (method_name_len == 7 && strncmp(method_name, "reverse", 7) == 0)
	{
		for (u32 i = 0; i < arr->length / 2; i++)
		{
			ActionVar tmp = arr->elements[i];
			arr->elements[i] = arr->elements[arr->length - 1 - i];
			arr->elements[arr->length - 1 - i] = tmp;
		}
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		return 1;
	}

	// join(separator) - join elements with separator string
	if (method_name_len == 4 && strncmp(method_name, "join", 4) == 0)
	{
		const char* sep = ",";
		u32 sep_len = 1;
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			sep = args[0].data.string_data.owns_memory ?
				args[0].data.string_data.heap_ptr : (const char*) args[0].data.numeric_value;
			if (sep == NULL) sep = "null";
			sep_len = strlen(sep);
		}
		else if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			// undefined separator → use comma (Flash behavior)
			sep = ",";
			sep_len = 1;
		}

		// Build joined string
		u32 buf_cap = 256;
		char* buf = (char*) HALLOC(buf_cap);
		u32 buf_len = 0;

		for (u32 i = 0; i < arr->length; i++)
		{
			if (i > 0)
			{
				while (buf_len + sep_len + 1 > buf_cap)
				{
					buf_cap *= 2;
					buf = (char*) realloc(buf, buf_cap);
				}
				memcpy(buf + buf_len, sep, sep_len);
				buf_len += sep_len;
			}
			char elem_str[64];
			ActionVar* elem = getArrayElement(arr, i);
			int elen = varToStringBuf(app_context, elem, elem_str, sizeof(elem_str));
			while (buf_len + elen + 1 > buf_cap)
			{
				buf_cap *= 2;
				buf = (char*) realloc(buf, buf_cap);
			}
			memcpy(buf + buf_len, elem_str, elen);
			buf_len += elen;
		}
		buf[buf_len] = '\0';

		// Push as heap-allocated string
		ActionVar result = {0};
		result.type = ACTION_STACK_VALUE_STRING;
		result.str_size = buf_len;
		result.data.string_data.heap_ptr = buf;
		result.data.string_data.owns_memory = true;
		pushVar(app_context, &result);
		return 1;
	}

	// toString() - same as join(",")
	if (method_name_len == 8 && strncmp(method_name, "toString", 8) == 0)
	{
		// Reuse join logic with ","
		ActionVar comma_arg = {0};
		comma_arg.type = ACTION_STACK_VALUE_STRING;
		comma_arg.str_size = 1;
		VAL(u64, &comma_arg.data.numeric_value) = (u64) ",";
		return callArrayMethod(app_context, arr, "join", 4, &comma_arg, 1);
	}

	// concat(arr1, arr2, ...) - return new array with all elements
	if (method_name_len == 6 && strncmp(method_name, "concat", 6) == 0)
	{
		// Count total elements needed
		u32 total = arr->length;
		for (u32 i = 0; i < num_args; i++)
		{
			if (args[i].type == ACTION_STACK_VALUE_ARRAY)
			{
				ASArray* other = (ASArray*) args[i].data.numeric_value;
				if (other) total += other->length;
			}
			else
			{
				total++;
			}
		}

		ASArray* result = allocArray(app_context, total > 0 ? total : 4);
		// Copy this array's elements
		for (u32 i = 0; i < arr->length; i++)
		{
			setArrayElement(app_context, result, result->length, &arr->elements[i]);
		}
		// Append each argument
		for (u32 i = 0; i < num_args; i++)
		{
			if (args[i].type == ACTION_STACK_VALUE_ARRAY)
			{
				ASArray* other = (ASArray*) args[i].data.numeric_value;
				if (other)
				{
					for (u32 j = 0; j < other->length; j++)
					{
						setArrayElement(app_context, result, result->length, &other->elements[j]);
					}
				}
			}
			else
			{
				setArrayElement(app_context, result, result->length, &args[i]);
			}
		}
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) result);
		return 1;
	}

	// slice(start, end) - return new array with elements [start, end)
	if (method_name_len == 5 && strncmp(method_name, "slice", 5) == 0)
	{
		int start = 0;
		int end = (int) arr->length;

		if (num_args > 0) start = (int) varToDoubleSimple(&args[0]);
		if (num_args > 1 && args[1].type != ACTION_STACK_VALUE_UNDEFINED)
		{
			double d = varToDoubleSimple(&args[1]);
			if (!isnan(d)) end = (int) d;
		}

		// Handle negative indices
		if (start < 0) start = (int)arr->length + start;
		if (end < 0) end = (int)arr->length + end;
		if (start < 0) start = 0;
		if (end > (int)arr->length) end = (int)arr->length;
		if (start > end) start = end;

		ASArray* result = allocArray(app_context, (end - start) > 0 ? (end - start) : 4);
		for (int i = start; i < end; i++)
		{
			setArrayElement(app_context, result, result->length, &arr->elements[i]);
		}
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) result);
		return 1;
	}

	// splice(start, deleteCount, insert1, insert2, ...) - modify in-place, return deleted
	if (method_name_len == 6 && strncmp(method_name, "splice", 6) == 0)
	{
		// Flash: splice() with no args or splice(undefined) returns undefined
		if (num_args == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			pushUndefined(app_context);
			return 1;
		}

		int start = (int) varToDoubleSimple(&args[0]);

		// Handle negative start and clamp
		if (start < 0) start = (int)arr->length + start;
		if (start < 0) start = 0;
		if (start > (int)arr->length) start = (int)arr->length;

		int delete_count;
		if (num_args <= 1)
		{
			// No deleteCount: delete from start to end
			delete_count = (int) arr->length - start;
		}
		else if (args[1].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			// Flash: splice(start, undefined) returns undefined
			pushUndefined(app_context);
			return 1;
		}
		else
		{
			double dc = varToDoubleSimple(&args[1]);
			if (isnan(dc)) { pushUndefined(app_context); return 1; }
			delete_count = (int) dc;
			// Flash: negative deleteCount returns undefined (no modification)
			if (delete_count < 0) { pushUndefined(app_context); return 1; }
		}

		if (start + delete_count > (int)arr->length) delete_count = (int)arr->length - start;

		// Collect deleted elements into result array
		ASArray* deleted = allocArray(app_context, delete_count > 0 ? delete_count : 4);
		for (int i = 0; i < delete_count; i++)
		{
			setArrayElement(app_context, deleted, deleted->length, &arr->elements[start + i]);
		}

		// Number of elements to insert
		u32 insert_count = (num_args > 2) ? num_args - 2 : 0;
		int shift = (int)insert_count - delete_count;

		if (shift > 0)
		{
			// Growing: ensure capacity and shift right
			u32 new_length = arr->length + shift;
			while (new_length > arr->capacity)
			{
				u32 new_cap = arr->capacity * 2;
				if (new_cap < new_length) new_cap = new_length;
				arr->elements = (ActionVar*) realloc(arr->elements, sizeof(ActionVar) * new_cap);
				arr->capacity = new_cap;
			}
			// Shift tail right
			for (int i = (int)arr->length - 1; i >= start + delete_count; i--)
			{
				arr->elements[i + shift] = arr->elements[i];
			}
			arr->length = new_length;
		}
		else if (shift < 0)
		{
			// Shrinking: shift left
			for (u32 i = start + delete_count; i < arr->length; i++)
			{
				arr->elements[i + shift] = arr->elements[i];
			}
			arr->length += shift;
		}

		// Insert new elements
		for (u32 i = 0; i < insert_count; i++)
		{
			arr->elements[start + i] = args[2 + i];
		}

		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) deleted);
		return 1;
	}

	// sort() - sort array (simplified: lexicographic by default)
	if (method_name_len == 4 && strncmp(method_name, "sort", 4) == 0)
	{
		// Simple bubble sort with string comparison (Flash default)
		// TODO: support sort flags and custom comparators
		for (u32 i = 0; i < arr->length; i++)
		{
			for (u32 j = i + 1; j < arr->length; j++)
			{
				char a_str[64], b_str[64];
				varToStringBuf(app_context, &arr->elements[i], a_str, sizeof(a_str));
				varToStringBuf(app_context, &arr->elements[j], b_str, sizeof(b_str));
				if (strcmp(a_str, b_str) > 0)
				{
					ActionVar tmp = arr->elements[i];
					arr->elements[i] = arr->elements[j];
					arr->elements[j] = tmp;
				}
			}
		}
		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		return 1;
	}

	return 0;
}

// Helper function to call built-in string methods
// Returns 1 if method was handled, 0 if not found
static int callStringPrimitiveMethod(SWFAppContext* app_context, char* str_buffer,
                                      const char* str_value, u32 str_len,
                                      const char* method_name, u32 method_name_len,
                                      ActionVar* args, u32 num_args)
{
	// toUpperCase() - no arguments
	if (method_name_len == 11 && strncmp(method_name, "toUpperCase", 11) == 0)
	{
		// Convert string to uppercase
		int i;
		for (i = 0; i < str_len && i < 16; i++)
		{
			char c = str_value[i];
			if (c >= 'a' && c <= 'z')
			{
				str_buffer[i] = c - ('a' - 'A');
			}
			else
			{
				str_buffer[i] = c;
			}
		}
		str_buffer[i] = '\0';
		PUSH_STR(str_buffer, i);
		return 1;
	}

	// toLowerCase() - no arguments
	if (method_name_len == 11 && strncmp(method_name, "toLowerCase", 11) == 0)
	{
		// Convert string to lowercase
		int i;
		for (i = 0; i < str_len && i < 16; i++)
		{
			char c = str_value[i];
			if (c >= 'A' && c <= 'Z')
			{
				str_buffer[i] = c + ('a' - 'A');
			}
			else
			{
				str_buffer[i] = c;
			}
		}
		str_buffer[i] = '\0';
		PUSH_STR(str_buffer, i);
		return 1;
	}

	// charAt(index) - 1 argument
	if (method_name_len == 6 && strncmp(method_name, "charAt", 6) == 0)
	{
		int index = 0;
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_F32)
		{
			index = (int)VAL(float, &args[0].data.numeric_value);
		}

		// Bounds check
		if (index < 0 || index >= str_len)
		{
			str_buffer[0] = '\0';
			PUSH_STR(str_buffer, 0);
		}
		else
		{
			str_buffer[0] = str_value[index];
			str_buffer[1] = '\0';
			PUSH_STR(str_buffer, 1);
		}
		return 1;
	}

	// substr(start, length) - 2 arguments
	if (method_name_len == 6 && strncmp(method_name, "substr", 6) == 0)
	{
		int start = 0;
		int length = str_len;

		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_F32)
		{
			start = (int)VAL(float, &args[0].data.numeric_value);
		}
		if (num_args > 1 && args[1].type == ACTION_STACK_VALUE_F32)
		{
			length = (int)VAL(float, &args[1].data.numeric_value);
		}

		// Handle negative start (count from end)
		if (start < 0)
		{
			start = str_len + start;
			if (start < 0) start = 0;
		}

		// Bounds check
		if (start >= str_len || length <= 0)
		{
			str_buffer[0] = '\0';
			PUSH_STR(str_buffer, 0);
		}
		else
		{
			if (start + length > str_len)
			{
				length = str_len - start;
			}

			int i;
			for (i = 0; i < length && i < 16; i++)
			{
				str_buffer[i] = str_value[start + i];
			}
			str_buffer[i] = '\0';
			PUSH_STR(str_buffer, i);
		}
		return 1;
	}

	// substring(start, end) - 2 arguments (different from substr!)
	if (method_name_len == 9 && strncmp(method_name, "substring", 9) == 0)
	{
		int start = 0;
		int end = str_len;

		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_F32)
		{
			start = (int)VAL(float, &args[0].data.numeric_value);
		}
		if (num_args > 1 && args[1].type == ACTION_STACK_VALUE_F32)
		{
			end = (int)VAL(float, &args[1].data.numeric_value);
		}

		// Clamp to valid range
		if (start < 0) start = 0;
		if (end < 0) end = 0;
		if (start > str_len) start = str_len;
		if (end > str_len) end = str_len;

		// Swap if start > end
		if (start > end)
		{
			int temp = start;
			start = end;
			end = temp;
		}

		int length = end - start;
		if (length <= 0)
		{
			str_buffer[0] = '\0';
			PUSH_STR(str_buffer, 0);
		}
		else
		{
			int i;
			for (i = 0; i < length && i < 16; i++)
			{
				str_buffer[i] = str_value[start + i];
			}
			str_buffer[i] = '\0';
			PUSH_STR(str_buffer, i);
		}
		return 1;
	}

	// indexOf(searchString, startIndex) - 1-2 arguments
	if (method_name_len == 7 && strncmp(method_name, "indexOf", 7) == 0)
	{
		const char* search_str = "";
		int search_len = 0;
		int start_index = 0;

		if (num_args > 0)
		{
			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				search_str = (const char*)args[0].data.numeric_value;
				search_len = args[0].str_size;
			}
		}
		if (num_args > 1 && args[1].type == ACTION_STACK_VALUE_F32)
		{
			start_index = (int)VAL(float, &args[1].data.numeric_value);
			if (start_index < 0) start_index = 0;
		}

		// Search for substring
		int found_index = -1;
		if (search_len == 0)
		{
			found_index = start_index <= str_len ? start_index : -1;
		}
		else
		{
			for (int i = start_index; i <= str_len - search_len; i++)
			{
				int match = 1;
				for (int j = 0; j < search_len; j++)
				{
					if (str_value[i + j] != search_str[j])
					{
						match = 0;
						break;
					}
				}
				if (match)
				{
					found_index = i;
					break;
				}
			}
		}

		float result = (float)found_index;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return 1;
	}

	// Method not found
	return 0;
}

void actionCallMethod(SWFAppContext* app_context, char* str_buffer)
{
	if (g_execution_halted) return;

	// 1. Pop method name (string) from stack
	char method_name_buffer[17];
	convertString(app_context, method_name_buffer);
	const char* method_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 method_name_len = STACK_TOP_N;
	POP();

	// 2. Pop object (receiver/this) from stack
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// 3. Pop number of arguments
	ActionVar num_args_var;
	popVar(app_context, &num_args_var);
	u32 num_args = 0;

	if (num_args_var.type == ACTION_STACK_VALUE_F32)
	{
		num_args = (u32) VAL(float, &num_args_var.data.numeric_value);
	}
	else if (num_args_var.type == ACTION_STACK_VALUE_F64)
	{
		num_args = (u32) VAL(double, &num_args_var.data.numeric_value);
	}

	// 4. Pop arguments from stack (in reverse order)
	ActionVar* args = NULL;
	if (num_args > 0)
	{
		args = (ActionVar*) HALLOC(sizeof(ActionVar) * num_args);
		for (u32 i = 0; i < num_args; i++)
		{
			popVar(app_context, &args[i]);
		}
	}

	// 5. Check for empty/blank method name - invoke object as function
	if (method_name_len == 0 || (method_name_len == 1 && method_name[0] == '\0'))
	{
		// Empty method name - invoke the object itself as a function
		if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
		{
			// Object is a function - invoke it
			ASFunction* func = lookupFunctionFromVar(&obj_var);

			if (func != NULL && g_call_depth >= g_max_call_depth - 1)
			{
				// Recursion depth limit reached - halt all script execution
				if (args != NULL) FREE(args);
				g_execution_halted = 1;
				pushUndefined(app_context);
				return;
			}
			else if (func != NULL && func->function_type == 2)
			{
				// Invoke DefineFunction2
				ActionVar* registers = NULL;
				if (func->register_count > 0) {
					registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
				}

				// No 'this' binding for direct function call (pass NULL)
				g_call_depth++;
				ActionVar result = func->advanced_func(app_context, args, num_args, registers, NULL);
				g_call_depth--;

				if (registers != NULL) FREE(registers);
				if (args != NULL) FREE(args);

				pushVar(app_context, &result);
				return;
			}
			else if (func != NULL && func->function_type == 1 && func->simple_func != NULL)
			{
				// Invoke simple function (DefineFunction type 1)
				// Push arguments onto stack for parameter binding
				for (u32 i = 0; i < num_args; i++)
				{
					pushVar(app_context, &args[i]);
				}
				if (args != NULL) FREE(args);

				g_call_depth++;
				ActionVar result;
				result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				g_call_depth--;

				pushVar(app_context, &result);
				return;
			}
			else
			{
				// Unknown function type or NULL - push undefined
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
		}
		else
		{
			// Object is not a function - cannot invoke, push undefined
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
	}

	// 6. Look up the method on the object and invoke it
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj == NULL)
		{
			// Null object - push undefined
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		// Look up the method property (with prototype chain support)
		ActionVar* method_prop = getPropertyWithPrototype(obj, method_name, method_name_len);

		if (method_prop != NULL && method_prop->type == ACTION_STACK_VALUE_FUNCTION)
		{
			// Get function object
			ASFunction* func = lookupFunctionFromVar(method_prop);

			if (func != NULL && g_call_depth >= g_max_call_depth - 1)
			{
				// Recursion depth limit reached - halt all script execution
				if (args != NULL) FREE(args);
				g_execution_halted = 1;
				pushUndefined(app_context);
			}
			else if (func != NULL && func->function_type == 2)
			{
				// Invoke DefineFunction2 with 'this' binding
				ActionVar* registers = NULL;
				if (func->register_count > 0) {
					registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
				}

				g_call_depth++;
				ActionVar result = func->advanced_func(app_context, args, num_args, registers, (void*) obj);
				g_call_depth--;

				if (registers != NULL) FREE(registers);
				if (args != NULL) FREE(args);

				pushVar(app_context, &result);
			}
			else if (func != NULL && func->function_type == 1 && func->simple_func != NULL)
			{
				// Invoke simple function (DefineFunction type 1) as method
				for (u32 i = 0; i < num_args; i++)
				{
					pushVar(app_context, &args[i]);
				}
				if (args != NULL) FREE(args);

				g_call_depth++;
				ActionVar result;
				result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				g_call_depth--;

				pushVar(app_context, &result);
			}
			else
			{
				// Invalid function - push undefined
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
		}
		else
		{
			// Method not found or not a function - push undefined
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_ARRAY)
	{
		// Array - call built-in array methods
		ASArray* arr = (ASArray*) obj_var.data.numeric_value;

		if (arr == NULL)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		int handled = callArrayMethod(app_context, arr,
		                               method_name, method_name_len,
		                               args, num_args);

		if (args != NULL) FREE(args);

		if (!handled)
		{
			pushUndefined(app_context);
		}
		return;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// String primitive - call built-in string methods
		const char* str_value = (const char*) obj_var.data.numeric_value;
		u32 str_len = obj_var.str_size;

		int handled = callStringPrimitiveMethod(app_context, str_buffer,
		                                         str_value, str_len,
		                                         method_name, method_name_len,
		                                         args, num_args);

		if (args != NULL) FREE(args);

		if (!handled)
		{
			// Method not found - push undefined
			pushUndefined(app_context);
		}
		return;
	}
	else
	{
		// Not an object, array, or string - push undefined
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
		return;
	}
}

void actionStartDrag(SWFAppContext* app_context)
{
	// Buffer for string conversion (needed for numeric targets)
	char str_buffer[17];

	// Pop target sprite name (convert to string if needed)
	convertString(app_context, str_buffer);
	ActionVar target;
	popVar(app_context, &target);
	const char* target_name = (target.type == ACTION_STACK_VALUE_STRING) ?
		(const char*) target.data.string_data.heap_ptr : "";

	// Pop lock center flag (convert to float if needed)
	convertFloat(app_context);
	ActionVar lock_center;
	popVar(app_context, &lock_center);

	// Pop constrain flag (convert to float if needed)
	convertFloat(app_context);
	ActionVar constrain;
	popVar(app_context, &constrain);

	float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int has_constraint = 0;

	// Check if we need to pop constraint rectangle
	// Convert to integer to check if non-zero
	if (constrain.type == ACTION_STACK_VALUE_F32) {
		has_constraint = ((int)VAL(float, &constrain.data.numeric_value) != 0);
	} else if (constrain.type == ACTION_STACK_VALUE_F64) {
		has_constraint = ((int)VAL(double, &constrain.data.numeric_value) != 0);
	}

	if (has_constraint) {
		// Pop constraint rectangle (y2, x2, y1, x1 order)
		// Convert each to float before popping
		convertFloat(app_context);
		ActionVar y2_var;
		popVar(app_context, &y2_var);

		convertFloat(app_context);
		ActionVar x2_var;
		popVar(app_context, &x2_var);

		convertFloat(app_context);
		ActionVar y1_var;
		popVar(app_context, &y1_var);

		convertFloat(app_context);
		ActionVar x1_var;
		popVar(app_context, &x1_var);

		x1 = (x1_var.type == ACTION_STACK_VALUE_F32) ? VAL(float, &x1_var.data.numeric_value) : (float)VAL(double, &x1_var.data.numeric_value);
		y1 = (y1_var.type == ACTION_STACK_VALUE_F32) ? VAL(float, &y1_var.data.numeric_value) : (float)VAL(double, &y1_var.data.numeric_value);
		x2 = (x2_var.type == ACTION_STACK_VALUE_F32) ? VAL(float, &x2_var.data.numeric_value) : (float)VAL(double, &x2_var.data.numeric_value);
		y2 = (y2_var.type == ACTION_STACK_VALUE_F32) ? VAL(float, &y2_var.data.numeric_value) : (float)VAL(double, &y2_var.data.numeric_value);
	}

	int lock_flag = 0;
	if (lock_center.type == ACTION_STACK_VALUE_F32) {
		lock_flag = ((int)VAL(float, &lock_center.data.numeric_value) != 0);
	} else if (lock_center.type == ACTION_STACK_VALUE_F64) {
		lock_flag = ((int)VAL(double, &lock_center.data.numeric_value) != 0);
	}

	// Set drag state
	// First, clear any existing drag (Flash only allows one sprite to be dragged at a time)
	if (is_dragging && dragged_target) {
		free(dragged_target);
	}

	is_dragging = 1;
	// Duplicate the target name (manual strdup for portability)
	if (target_name && *target_name) {
		size_t len = strlen(target_name);
		dragged_target = (char*) malloc(len + 1);
		if (dragged_target) {
			strcpy(dragged_target, target_name);
		}
	} else {
		dragged_target = NULL;
	}

	#ifdef DEBUG
	printf("[StartDrag] %s (lock:%d, constrain:%d)\n",
		   target_name ? target_name : "(null)", lock_flag, has_constraint);
	if (has_constraint) {
		printf("  Bounds: (%.1f,%.1f)-(%.1f,%.1f)\n", x1, y1, x2, y2);
	}
	#endif

	#ifndef NO_GRAPHICS
	// Full implementation would also:
	// 1. Find target MovieClip in display list
	// 2. Store drag parameters (lock_flag, constraints)
	// 3. Update position each frame based on mouse input
	// startDragMovieClip(target_name, lock_flag, has_constraint, x1, y1, x2, y2);
	#endif
}

// ==================================================================
// Control Flow - WaitForFrame
// ==================================================================

/**
 * actionWaitForFrame - Check if a frame is loaded
 *
 * @param stack - The execution stack
 * @param sp - Stack pointer
 * @param frame - Frame number to check (0-based in bytecode, 1-based in MovieClip)
 * @return true if frame is loaded, false otherwise
 *
 * This opcode was designed for streaming SWF files where frames load progressively.
 * For modern usage with instantly-loaded SWFs, we simplify by assuming all frames
 * that exist are loaded.
 */
bool actionWaitForFrame(SWFAppContext* app_context, u16 frame)
{
	// Get the current MovieClip (simplified: always use root)
	MovieClip* mc = &root_movieclip;

	if (!mc) {
		// No MovieClip available - frame not loaded
		return false;
	}

	// Check if frame exists
	// Note: Frame numbers in WaitForFrame are 0-based in the bytecode,
	// but MovieClip properties are 1-based. Convert for comparison.
	u16 frame_1based = frame + 1;

	if (frame_1based > mc->totalframes) {
		// Frame doesn't exist
		return false;
	}

	// For non-streaming SWF files, all frames that exist are loaded
	// In a full streaming implementation, we would check:
	// if (frame_1based <= mc->frames_loaded) return true;
	// For now, assume all frames are loaded
	return true;
}

bool actionWaitForFrame2(SWFAppContext* app_context)
{
	// Pop frame identifier from stack
	ActionVar frame_var;
	popVar(app_context, &frame_var);

	// For simplified implementation: assume all frames are loaded
	// In a full implementation, this would check if the frame is actually loaded
	// by examining the MovieClip's frames_loaded count

	// Debug output to show what frame was checked
#ifdef DEBUG
	if (frame_var.type == ACTION_STACK_VALUE_F32)
	{
		printf("[DEBUG] WaitForFrame2: checking frame %d (assuming loaded)\n", (int)frame_var.value.f32);
	}
	else if (frame_var.type == ACTION_STACK_VALUE_STRING)
	{
		const char* frame_str = (const char*)frame_var.value.u64;
		printf("[DEBUG] WaitForFrame2: checking frame '%s' (assuming loaded)\n", frame_str);
	}
#endif

	// Simplified: always return true (frame loaded)
	// This is appropriate for non-streaming SWF files where all content loads instantly
	return true;
}
