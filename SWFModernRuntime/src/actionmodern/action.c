#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

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
#include <map.h>
#include <actionmodern/object.h>
#include "unicode_case_tables.h"

// Forward declarations for array helpers (defined later in file)
static int varToStringBuf(SWFAppContext* app_context, ActionVar* v, char* buf, int buf_size);
static double varToDoubleSimple(ActionVar* v);
static int _sort_compare_vars(SWFAppContext* app_context, ActionVar* a, ActionVar* b, int flags);
static ActionVar objectCallToString(SWFAppContext* app_context, ActionVar* obj_var, int* found);
static int callArrayMethod(SWFAppContext* app_context, ASArray* arr,
                           const char* method_name, u32 method_name_len,
                           ActionVar* args, u32 num_args);

u32 start_time;

// ECMAScript ToInt32 conversion (used for array length)
static int32_t ecmaToInt32(double d)
{
	if (isnan(d) || isinf(d) || d == 0.0) return 0;
	double n = fmod(d, 4294967296.0);
	if (n < 0) n += 4294967296.0;
	if (n >= 2147483648.0) n -= 4294967296.0;
	return (int32_t) n;
}

static uint32_t ecmaToUint32(double d)
{
	if (isnan(d) || isinf(d) || d == 0.0) return 0;
	double n = fmod(d, 4294967296.0);
	if (n < 0) n += 4294967296.0;
	return (uint32_t) n;
}

// ==================================================================
// UTF-16 String Infrastructure
// ==================================================================

// Pre-defined UTF-16 constant strings (used by convertString, pushVar, etc.)
static const uint16_t u16_empty[] = {0};
static const uint16_t u16_true[] = {'t','r','u','e',0};
static const uint16_t u16_false[] = {'f','a','l','s','e',0};
static const uint16_t u16_null[] = {'n','u','l','l',0};
static const uint16_t u16_undefined[] = {'u','n','d','e','f','i','n','e','d',0};
static const uint16_t u16_NaN[] = {'N','a','N',0};
static const uint16_t u16_Infinity[] = {'I','n','f','i','n','i','t','y',0};
static const uint16_t u16_neg_Infinity[] = {'-','I','n','f','i','n','i','t','y',0};
static const uint16_t u16_zero[] = {'0',0};
static const uint16_t u16_one[] = {'1',0};
static const uint16_t u16_type_Function[] = {'[','t','y','p','e',' ','F','u','n','c','t','i','o','n',']',0};
static const uint16_t u16_object_Object[] = {'[','o','b','j','e','c','t',' ','O','b','j','e','c','t',']',0};
static const uint16_t u16_type_Object[] = {'[','t','y','p','e',' ','O','b','j','e','c','t',']',0};
static const uint16_t u16_level0[] = {'_','l','e','v','e','l','0',0};
static const uint16_t u16_comma[] = {',',0};
static const uint16_t u16_string[] = {'s','t','r','i','n','g',0};
static const uint16_t u16_number[] = {'n','u','m','b','e','r',0};
static const uint16_t u16_boolean[] = {'b','o','o','l','e','a','n',0};
static const uint16_t u16_movieclip[] = {'m','o','v','i','e','c','l','i','p',0};
static const uint16_t u16_object[] = {'o','b','j','e','c','t',0};
static const uint16_t u16_function[] = {'f','u','n','c','t','i','o','n',0};
static const uint16_t u16_dynamic[] = {'d','y','n','a','m','i','c',0};
static const uint16_t u16_input[] = {'i','n','p','u','t',0};
static const uint16_t u16_none[] = {'n','o','n','e',0};
static const uint16_t u16_left[] = {'l','e','f','t',0};
static const uint16_t u16_right[] = {'r','i','g','h','t',0};
static const uint16_t u16_center[] = {'c','e','n','t','e','r',0};
static const uint16_t u16_Error[] = {'E','r','r','o','r',0};
static const uint16_t u16_block[] = {'b','l','o','c','k',0};
static const uint16_t u16_normal[] = {'n','o','r','m','a','l',0};
static const uint16_t u16_pixel[] = {'p','i','x','e','l',0};
static const uint16_t u16_localWithFile[] = {'l','o','c','a','l','W','i','t','h','F','i','l','e',0};
static const uint16_t u16_StandAlone[] = {'S','t','a','n','d','A','l','o','n','e',0};
static const uint16_t u16_WIN_ver[] = {'W','I','N',' ','3','2',',','0',',','0',',','0',0};
static const uint16_t u16_Windows_XP[] = {'W','i','n','d','o','w','s',' ','X','P',0};
static const uint16_t u16_Macromedia_Windows[] = {'M','a','c','r','o','m','e','d','i','a',' ','W','i','n','d','o','w','s',0};
static const uint16_t u16_en[] = {'e','n',0};
static const uint16_t u16_justify[] = {'j','u','s','t','i','f','y',0};
static const uint16_t u16_Times_New_Roman[] = {'T','i','m','e','s',' ','N','e','w',' ','R','o','m','a','n',0};
static const uint16_t u16_default_colortransform[] = {'(','r','e','d','M','u','l','t','i','p','l','i','e','r','=','1',',',' ','g','r','e','e','n','M','u','l','t','i','p','l','i','e','r','=','1',',',' ','b','l','u','e','M','u','l','t','i','p','l','i','e','r','=','1',',',' ','a','l','p','h','a','M','u','l','t','i','p','l','i','e','r','=','1',',',' ','r','e','d','O','f','f','s','e','t','=','0',',',' ','g','r','e','e','n','O','f','f','s','e','t','=','0',',',' ','b','l','u','e','O','f','f','s','e','t','=','0',',',' ','a','l','p','h','a','O','f','f','s','e','t','=','0',')',0};
static const uint16_t u16_default_matrix[] = {'(','a','=','1',',',' ','b','=','0',',',' ','c','=','0',',',' ','d','=','1',',',' ','t','x','=','0',',',' ','t','y','=','0',')',0};
static const uint16_t u16_default_rect[] = {'(','x','=','0',',',' ','y','=','0',',',' ','w','=','0',',',' ','h','=','0',')',0};

// Count UTF-16 code units needed for a UTF-8 string
static int utf8_utf16_length(const char* s, int byte_len)
{
	int count = 0;
	int i = 0;
	while (i < byte_len)
	{
		unsigned char c = (unsigned char)s[i];
		if (c < 0x80) { count++; i++; }
		else if (c < 0xE0) { count++; i += 2; }
		else if (c < 0xF0) { count++; i += 3; }
		else { count += 2; i += 4; } // surrogate pair = 2 UTF-16 code units
	}
	return count;
}

// Decode one UTF-8 character, return code point, advance *pos
static uint32_t utf8_decode_one(const char* s, int byte_len, int* pos)
{
	unsigned char c = (unsigned char)s[*pos];
	uint32_t cp;
	if (c < 0x80) { cp = c; *pos += 1; }
	else if (c < 0xE0 && *pos + 1 < byte_len) {
		cp = ((uint32_t)(c & 0x1F) << 6) | (s[*pos+1] & 0x3F);
		*pos += 2;
	}
	else if (c < 0xF0 && *pos + 2 < byte_len) {
		cp = ((uint32_t)(c & 0x0F) << 12) | ((uint32_t)(s[*pos+1] & 0x3F) << 6) | (s[*pos+2] & 0x3F);
		*pos += 3;
	}
	else if (*pos + 3 < byte_len) {
		cp = ((uint32_t)(c & 0x07) << 18) | ((uint32_t)(s[*pos+1] & 0x3F) << 12) |
		     ((uint32_t)(s[*pos+2] & 0x3F) << 6) | (s[*pos+3] & 0x3F);
		*pos += 4;
	}
	else { cp = 0xFFFD; *pos += 1; }
	return cp;
}

// Convert UTF-8 to heap-allocated UTF-16. Returns uint16_t* (from heap_alloc).
static uint16_t* utf8_to_u16(SWFAppContext* app_context, const char* utf8, u32 byte_len, u32* out_u16_len)
{
	if (byte_len == 0 || utf8 == NULL) {
		*out_u16_len = 0;
		return (uint16_t*) u16_empty;
	}
	int count = utf8_utf16_length(utf8, (int)byte_len);
	uint16_t* result = (uint16_t*) heap_alloc(app_context, (count + 1) * sizeof(uint16_t));
	int u = 0, i = 0;
	while (i < (int)byte_len) {
		uint32_t cp = utf8_decode_one(utf8, (int)byte_len, &i);
		if (cp < 0x10000) {
			result[u++] = (uint16_t)cp;
		} else {
			uint32_t adj = cp - 0x10000;
			result[u++] = (uint16_t)(0xD800 | (adj >> 10));
			result[u++] = (uint16_t)(0xDC00 | (adj & 0x3FF));
		}
	}
	result[u] = 0;
	*out_u16_len = (u32)u;
	return result;
}

// Convert UTF-16 to UTF-8 in caller-provided buffer. Returns bytes written (not including NUL).
static int u16_to_utf8(const uint16_t* u16, u32 u16_len, char* out, int out_size)
{
	if (out_size <= 0) return 0;
	if (u16 == NULL) { out[0] = '\0'; return 0; }
	int pos = 0;
	for (u32 i = 0; i < u16_len && pos < out_size - 1; i++) {
		uint16_t unit = u16[i];
		// Check for surrogate pair
		if (unit >= 0xD800 && unit <= 0xDBFF && i + 1 < u16_len) {
			uint16_t low = u16[i + 1];
			if (low >= 0xDC00 && low <= 0xDFFF) {
				uint32_t cp = 0x10000 + ((uint32_t)(unit - 0xD800) << 10) + (low - 0xDC00);
				if (pos + 4 > out_size - 1) break;
				out[pos++] = (char)(0xF0 | (cp >> 18));
				out[pos++] = (char)(0x80 | ((cp >> 12) & 0x3F));
				out[pos++] = (char)(0x80 | ((cp >> 6) & 0x3F));
				out[pos++] = (char)(0x80 | (cp & 0x3F));
				i++;
				continue;
			}
		}
		// Lone surrogate → U+FFFD
		if (unit >= 0xD800 && unit <= 0xDFFF) {
			if (pos + 3 > out_size - 1) break;
			out[pos++] = (char)0xEF;
			out[pos++] = (char)0xBF;
			out[pos++] = (char)0xBD;
			continue;
		}
		if (unit < 0x80) {
			out[pos++] = (char)unit;
		} else if (unit < 0x800) {
			if (pos + 2 > out_size - 1) break;
			out[pos++] = (char)(0xC0 | (unit >> 6));
			out[pos++] = (char)(0x80 | (unit & 0x3F));
		} else {
			if (pos + 3 > out_size - 1) break;
			out[pos++] = (char)(0xE0 | (unit >> 12));
			out[pos++] = (char)(0x80 | ((unit >> 6) & 0x3F));
			out[pos++] = (char)(0x80 | (unit & 0x3F));
		}
	}
	out[pos] = '\0';
	return pos;
}

// Lexicographic comparison of two UTF-16 strings (like strcmp)
static int u16_cmp(const uint16_t* a, u32 a_len, const uint16_t* b, u32 b_len)
{
	u32 min_len = a_len < b_len ? a_len : b_len;
	for (u32 i = 0; i < min_len; i++) {
		if (a[i] != b[i]) return (int)a[i] - (int)b[i];
	}
	return (int)a_len - (int)b_len;
}

// Fast ASCII-to-UTF-16 conversion (for number strings which are always ASCII)
static uint16_t* ascii_to_u16(SWFAppContext* app_context, const char* ascii, int len, u32* out_len)
{
	uint16_t* result = (uint16_t*) heap_alloc(app_context, (len + 1) * sizeof(uint16_t));
	for (int i = 0; i < len; i++)
		result[i] = (uint16_t)(unsigned char)ascii[i];
	result[len] = 0;
	*out_len = (u32)len;
	return result;
}

// Get UTF-16 string pointer from ActionVar
static const uint16_t* varGetU16Ptr(ActionVar* v)
{
	if (v->type != ACTION_STACK_VALUE_STRING) return NULL;
	return v->data.string_data.owns_memory ?
		v->data.string_data.heap_ptr : (const uint16_t*) v->data.numeric_value;
}

// Concatenate two UTF-16 strings into a new heap-allocated buffer
static uint16_t* u16_concat(SWFAppContext* app_context, const uint16_t* a, u32 a_len,
                             const uint16_t* b, u32 b_len, u32* out_len)
{
	u32 total = a_len + b_len;
	uint16_t* result = (uint16_t*) heap_alloc(app_context, (total + 1) * sizeof(uint16_t));
	if (a_len > 0) memcpy(result, a, a_len * sizeof(uint16_t));
	if (b_len > 0) memcpy(result + a_len, b, b_len * sizeof(uint16_t));
	result[total] = 0;
	*out_len = total;
	return result;
}

// push_str_id_fn: converts char* to UTF-16 (with caching for constant strings) and pushes onto stack
void push_str_id_fn(SWFAppContext* app_context, const char* str, u32 byte_len, u32 id)
{
	uint16_t* u16;
	u32 u16_len;

	if (id > 0 && app_context->max_string_id > 0 && id < app_context->max_string_id) {
		// Lazy-init cache on first use
		if (app_context->str_cache == NULL) {
			app_context->str_cache = (uint16_t**) calloc(app_context->max_string_id, sizeof(uint16_t*));
			app_context->str_cache_len = (u32*) calloc(app_context->max_string_id, sizeof(u32));
		}
		if (app_context->str_cache != NULL && app_context->str_cache[id] != NULL) {
			u16 = app_context->str_cache[id];
			u16_len = app_context->str_cache_len[id];
		} else {
			u16 = utf8_to_u16(app_context, str, byte_len, &u16_len);
			if (app_context->str_cache != NULL) {
				app_context->str_cache[id] = u16;
				app_context->str_cache_len[id] = u16_len;
			}
		}
	} else {
		if (byte_len == 0 || str == NULL) {
			u16 = (uint16_t*) u16_empty;
			u16_len = 0;
		} else {
			u16 = utf8_to_u16(app_context, str, byte_len, &u16_len);
		}
	}

	OLDSP = SP;
	SP -= 4 + 4 + 8 + 8;
	SP &= ~7;
	STACK[SP] = ACTION_STACK_VALUE_STRING;
	VAL(u32, &STACK[SP + 4]) = OLDSP;
	VAL(u32, &STACK[SP + 8]) = u16_len;
	VAL(u32, &STACK[SP + 12]) = id;
	VAL(u64, &STACK[SP + 16]) = (u64)u16;
}

// ==================================================================
// Scope Chain for WITH statement
// ==================================================================

#define MAX_SCOPE_DEPTH 32
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u8 scope_is_with[MAX_SCOPE_DEPTH];       // 1 = with scope, 0 = function scope
static MovieClip* scope_mc[MAX_SCOPE_DEPTH];     // non-NULL if scope entry is a MovieClip
static u32 scope_depth = 0;

// Forward declarations for MC property helpers (defined in WITH section)
static int getMCBuiltinProperty(MovieClip* mc, const char* name, u32 name_len, ActionVar* result);
static int setMCBuiltinProperty(SWFAppContext* app_context, MovieClip* mc, const char* name, u32 name_len, ActionVar* value);

// Stored app_context for use by setVariableOnLocalScope (called from variables.c
// which doesn't have app_context). Set at entry to actionCallFunction/actionCallMethod.
static SWFAppContext* g_scope_app_context = NULL;

// Set to the receiver ASObject whenever a C function (advanced_func) is called
// as an object method via actionCallMethod. Used by AsBroadcaster methods to
// identify which object they are operating on.
static ASObject* g_c_function_this_obj = NULL;

// Expose local scope for parameter binding (used by setVariableByName)
// Skips 'with' scopes to find the nearest function scope.
ASObject* getCurrentLocalScope(void)
{
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (!scope_is_with[i] && scope_chain[i] != NULL)
			return scope_chain[i];
	}
	return NULL;
}

// Try to set a variable on the current local scope (function scope).
// Returns true if we're inside a function and the variable was set on local scope.
// Returns false if no local scope exists (caller should fall through to global).
bool setVariableOnLocalScope(const char* var_name, ActionVar* value)
{
	ASObject* local_scope = getCurrentLocalScope();
	if (local_scope == NULL)
		return false;

	u32 name_len = strlen(var_name);

	// Use setProperty which properly allocates with HALLOC (matching releaseObject's FREE)
	setProperty(g_scope_app_context, local_scope, var_name, name_len, value);
	return true;
}

// ==================================================================
// Recursion Depth Limit
// ==================================================================

int g_swf_version = 5;       // SWF version — set at startup from constants.h
u32 g_max_call_depth = 256;  // Default; overridden by tagScriptLimits()
u8 g_execution_halted = 0;   // Set when recursion limit is hit; halts all further script execution
static u32 g_call_depth = 0;

// ==================================================================
// Effective SWF Version (accounts for function context)
// ==================================================================
// In Flash, DefineFunction (SWF5 opcode) causes code inside functions
// to behave as SWF5+ even in a SWF4 file. When inside a function call
// (g_call_depth > 0) and the SWF version is < 5, we promote to version 5.
#define EFFECTIVE_SWF_VERSION() ((g_swf_version < 5 && g_call_depth > 0) ? 5 : g_swf_version)

// ==================================================================
// Special Recursion Counter (for getter/setter/valueOf/toString)
// ==================================================================
// Flash/Ruffle tracks a separate "special" recursion counter for
// getter/setter invocations. Hard limit of 66 — non-fatal (returns
// undefined instead of halting execution).

#define MAX_SPECIAL_DEPTH 66
static u32 g_special_depth = 0;

// Forward declaration (ASFunction is defined below)
typedef struct ASFunction ASFunction;

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

	// Own properties on the function object itself (e.g., toString override)
	ASObject* own_props;  // Created lazily when SetMember is called
} ASFunction;

// Function registry
#define MAX_FUNCTIONS 256
static ASFunction* function_registry[MAX_FUNCTIONS];
static u32 function_count = 0;

// Global Object.prototype with built-in toString and valueOf
static ASObject* g_object_prototype = NULL;

// Global Array.prototype — shared by all arrays for instanceof and arguments.__proto__
static ASObject* g_array_prototype = NULL;

// Currently executing user-defined function — used to set arguments.caller
static ASFunction* g_current_executing_func = NULL;
// Previously executing function — used for arguments.caller in preloaded-arguments functions
static ASFunction* g_prev_executing_func = NULL;
static ASFunction g_object_toString_func;
static ASFunction g_object_valueOf_func;
static ASFunction g_object_hasOwnProperty_func;
static ASFunction g_object_isPropertyEnumerable_func;
static ASFunction g_object_isPrototypeOf_func;
static ASFunction g_object_watch_func;
static ASFunction g_object_unwatch_func;
static ASFunction g_wrapper_toString_func;
static int g_wrapper_toString_init = 0;

// --- Object.prototype.watch() / unwatch() watcher table ---
#define MAX_WATCH_ENTRIES 64
typedef struct {
	ASObject* obj;          // NULL for timeline/MovieClip variable watches
	MovieClip* mc;          // Non-NULL for timeline variable watches (obj==NULL)
	char prop_name[64];
	u32 prop_name_len;
	ASFunction* watcher_func;
	ActionVar user_data;    // userData (3rd arg passed to watch())
} WatchEntry;
static WatchEntry g_watch_table[MAX_WATCH_ENTRIES];
static int g_watch_count = 0;

// Built-in toString for Object(primitive) wrappers — returns valueOf as string
static ActionVar builtin_wrapper_toString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 15;
	ret.data.numeric_value = (u64) u16_object_Object;

	if (this_obj != NULL)
	{
		ASObject* obj = (ASObject*) this_obj;
		ActionVar* val_prop = getProperty(obj, "valueOf", 7);
		if (val_prop != NULL && val_prop->type != ACTION_STACK_VALUE_FUNCTION)
		{
			char buf[64];
			int len = varToStringBuf(app_context, val_prop, buf, sizeof(buf));
			// Convert UTF-8 result to UTF-16 for storage
			u32 u16_len;
			uint16_t* u16_str = ascii_to_u16(app_context, buf, len, &u16_len);
			ret.data.string_data.heap_ptr = u16_str;
			ret.data.string_data.owns_memory = true;
			ret.str_size = u16_len;
		}
	}
	return ret;
}

static ActionVar builtin_object_toString(SWFAppContext* app_context)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	if (g_swf_version < 6) {
		// SWF5 uses "[type Object]" format for user-created objects
		ret.str_size = 13;
		ret.data.numeric_value = (u64) u16_type_Object;
	} else {
		// SWF6+ uses "[object Object]" format
		ret.str_size = 15;
		ret.data.numeric_value = (u64) u16_object_Object;
	}
	return ret;
}

// --- Stub class toString (always "[type Object]" regardless of SWF version) ---
// Used for stub class instances (PrintJob, etc.) which trace as "[type Object]" in SWF < 7,
// overriding the Object.prototype.toString that would otherwise return "[object Object]".
static ActionVar builtin_type_object_toString(SWFAppContext* app_context)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 13;
	ret.data.numeric_value = (u64) u16_type_Object;
	return ret;
}

static ASFunction g_type_object_toString_func;

// --- Native object toString (always "[object Object]" regardless of SWF version) ---
// Used for static native objects (Math, Key, Mouse, Stage, etc.) which always trace
// as "[object Object]" even in SWF5, unlike user-created objects.
static ActionVar builtin_native_object_toString(SWFAppContext* app_context)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 15;
	ret.data.numeric_value = (u64) u16_object_Object;
	return ret;
}

static ASFunction g_native_toString_func;
static int g_native_toString_init = 0;

// Install a toString method that always returns "[object Object]" on a native ASObject.
// This bypasses Object.prototype.toString's SWF version check.
static void installNativeToString(SWFAppContext* app_context, ASObject* obj)
{
	if (!g_native_toString_init) {
		memset(&g_native_toString_func, 0, sizeof(ASFunction));
		strncpy(g_native_toString_func.name, "toString", 255);
		g_native_toString_func.function_type = 1;
		g_native_toString_func.simple_func = (SimpleFunctionPtr) builtin_native_object_toString;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_native_toString_func;
		g_native_toString_init = 1;
	}
	ActionVar ts_var = {0};
	ts_var.type = ACTION_STACK_VALUE_FUNCTION;
	ts_var.data.numeric_value = (u64) &g_native_toString_func;
	setPropertyWithFlags(app_context, obj, "toString", 8, &ts_var, PROPERTY_FLAGS_DONTENUM);
}

// --- Generic stub method (returns undefined) ---
// Used as a no-op placeholder for prototype method stubs.
static ActionVar builtin_stub_method(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)args; (void)arg_count; (void)registers; (void)this_obj;
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	return ret;
}

#define MAX_PROTO_STUB_FUNCS 64
static ASFunction g_proto_stub_funcs[MAX_PROTO_STUB_FUNCS];
static int g_proto_stub_func_count = 0;

// Add a stub function property to a prototype object.
// flags controls ENUMERABLE/WRITABLE/CONFIGURABLE behavior.
static void addStubMethodToProto(SWFAppContext* app_context, ASObject* proto, const char* name, u32 name_len, u8 flags)
{
	if (g_proto_stub_func_count >= MAX_PROTO_STUB_FUNCS) return;
	ASFunction* fn = &g_proto_stub_funcs[g_proto_stub_func_count++];
	memset(fn, 0, sizeof(ASFunction));
	strncpy(fn->name, name, 255);
	fn->function_type = 2;
	fn->advanced_func = (Function2Ptr) builtin_stub_method;
	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = fn;
	ActionVar fv = {0};
	fv.type = ACTION_STACK_VALUE_FUNCTION;
	fv.data.numeric_value = (u64) fn;
	setPropertyWithFlags(app_context, proto, name, name_len, &fv, flags);
}

// Built-in hasOwnProperty checks if a property exists directly on the object
static ActionVar builtin_object_hasOwnProperty(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_BOOLEAN;
	ret.str_size = 0;
	ret.data.numeric_value = 0; // false by default

	if (this_obj != NULL && args != NULL && arg_count >= 1)
	{
		ASObject* obj = (ASObject*) this_obj;
		const char* prop_name = NULL;
		u32 prop_name_len = 0;
		char coerced_buf[64];

		if (args[0].type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* _u16 = varGetU16Ptr(&args[0]);
			prop_name_len = (u32)u16_to_utf8(_u16, args[0].str_size, coerced_buf, sizeof(coerced_buf));
			prop_name = coerced_buf;
		}
		else if (args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			// undefined coerces to "undefined" for property names
			prop_name = "undefined";
			prop_name_len = 9;
		}
		else if (args[0].type == ACTION_STACK_VALUE_NULL)
		{
			// null coerces to "null" for property names
			prop_name = "null";
			prop_name_len = 4;
		}
		else
		{
			// Coerce non-string argument to string (numbers, booleans)
			int len = varToStringBuf(app_context, &args[0], coerced_buf, sizeof(coerced_buf));
			prop_name = coerced_buf;
			prop_name_len = (u32) len;
		}

		if (prop_name != NULL)
		{
			// Use hasPropertyRaw to check existence ignoring flash_flags visibility
			// (hasOwnProperty returns true even for hidden properties)
			if (hasPropertyRaw(obj, prop_name, prop_name_len))
			{
				ret.data.numeric_value = 1; // true
			}
		}
	}
	return ret;
}

// Built-in isPropertyEnumerable(name) — checks if OWN property exists and is enumerable
static ActionVar builtin_object_isPropertyEnumerable(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_BOOLEAN;
	ret.str_size = 0;
	ret.data.numeric_value = 0; // false by default

	if (this_obj != NULL && args != NULL && arg_count >= 1)
	{
		ASObject* obj = (ASObject*) this_obj;
		const char* prop_name = NULL;
		u32 prop_name_len = 0;
		char coerced_buf[64];

		if (args[0].type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* _u16 = varGetU16Ptr(&args[0]);
			prop_name_len = (u32)u16_to_utf8(_u16, args[0].str_size, coerced_buf, sizeof(coerced_buf));
			prop_name = coerced_buf;
		}
		else
		{
			int len = varToStringBuf(app_context, &args[0], coerced_buf, sizeof(coerced_buf));
			prop_name = coerced_buf;
			prop_name_len = (u32) len;
		}

		if (prop_name != NULL)
		{
			// Check own properties only (not prototype chain)
			for (u32 i = 0; i < obj->num_used; i++)
			{
				if (obj->properties[i].name_length == prop_name_len &&
				    strncmp(obj->properties[i].name, prop_name, prop_name_len) == 0)
				{
					// Property exists — check if it's enumerable
					if (obj->properties[i].flags & PROPERTY_FLAG_ENUMERABLE)
					{
						ret.data.numeric_value = 1; // true
					}
					break;
				}
			}
		}
	}
	return ret;
}

// Built-in isPrototypeOf(obj) — checks if `this` appears in obj's prototype chain
static ActionVar builtin_object_isPrototypeOf(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_BOOLEAN;
	ret.str_size = 0;
	ret.data.numeric_value = 0; // false by default

	if (this_obj != NULL && args != NULL && arg_count >= 1)
	{
		ASObject* self = (ASObject*) this_obj;

		// Get the object to check
		ASObject* check_obj = NULL;
		int is_function_arg = 0;
		if (args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0)
		{
			check_obj = (ASObject*) args[0].data.numeric_value;
		}
		else if (args[0].type == ACTION_STACK_VALUE_FUNCTION && args[0].data.numeric_value != 0)
		{
			// Functions have own_props that acts as their object
			ASFunction* func = (ASFunction*) args[0].data.numeric_value;
			check_obj = func->own_props;
			is_function_arg = 1;
		}

		if (check_obj != NULL)
		{
			// Walk check_obj's __proto__ chain looking for self
			ASObject* current = check_obj;
			int max_depth = 64; // prevent infinite loops
			while (current != NULL && max_depth-- > 0)
			{
				ActionVar* proto_var = getProperty(current, "__proto__", 9);
				if (proto_var == NULL || proto_var->type != ACTION_STACK_VALUE_OBJECT || proto_var->data.numeric_value == 0)
					break;
				ASObject* proto = (ASObject*) proto_var->data.numeric_value;
				if (proto == self)
				{
					ret.data.numeric_value = 1; // true
					break;
				}
				current = proto;
			}
		}

		// Functions implicitly inherit from Object.prototype (via Function.prototype)
		// If chain walk didn't find self, check if self is Object.prototype
		if (ret.data.numeric_value == 0 && is_function_arg)
		{
			if (g_object_prototype != NULL && self == g_object_prototype)
				ret.data.numeric_value = 1;
		}
	}
	return ret;
}

// Built-in valueOf returns `this` (the object it's called on)
static ActionVar builtin_object_valueOf(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	if (this_obj != NULL)
	{
		ret.type = ACTION_STACK_VALUE_OBJECT;
		ret.str_size = 0;
		ret.data.numeric_value = (u64) this_obj;
	}
	else
	{
		ret.type = ACTION_STACK_VALUE_UNDEFINED;
		ret.str_size = 0;
		ret.data.numeric_value = 0;
	}
	return ret;
}

// Built-in Object.prototype.watch(prop, fn [, userData]) — register a watcher for property changes
static ActionVar builtin_object_watch(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret_false = {0};
	ret_false.type = ACTION_STACK_VALUE_BOOLEAN;
	ret_false.data.numeric_value = 0;
	if (arg_count < 2) return ret_false;
	if (args[1].type != ACTION_STACK_VALUE_FUNCTION) return ret_false;

	// When this_obj == NULL (called via actionCallFunction at timeline level),
	// treat it as a timeline/MovieClip variable watch on g_current_context.
	ASObject* obj = NULL;
	MovieClip* mc = NULL;
	if (this_obj != NULL) {
		obj = (ASObject*) this_obj;
	} else {
		mc = g_current_context ? g_current_context : &root_movieclip;
		if (mc == NULL) return ret_false;
	}

	char prop_name[64] = {0};
	u32 prop_name_len = 0;
	if (args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* u16 = varGetU16Ptr(&args[0]);
		if (u16 != NULL)
			prop_name_len = (u32)u16_to_utf8(u16, args[0].str_size, prop_name, (int)(sizeof(prop_name) - 1));
	}
	ASFunction* wf = (ASFunction*) args[1].data.numeric_value;

	// Store userData (3rd arg, or undefined if not provided)
	ActionVar user_data = {0};
	user_data.type = ACTION_STACK_VALUE_UNDEFINED;
	if (arg_count >= 3) user_data = args[2];

	// Update existing entry if already watching this prop on this object/mc
	for (int i = 0; i < g_watch_count; i++) {
		if (g_watch_table[i].obj == obj &&
		    g_watch_table[i].mc == mc &&
		    g_watch_table[i].prop_name_len == prop_name_len &&
		    strncmp(g_watch_table[i].prop_name, prop_name, prop_name_len) == 0)
		{
			g_watch_table[i].watcher_func = wf;
			g_watch_table[i].user_data = user_data;
			ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_BOOLEAN; ret.data.numeric_value = 1;
			return ret;
		}
	}
	// Add new entry
	if (g_watch_count < MAX_WATCH_ENTRIES) {
		g_watch_table[g_watch_count].obj = obj;
		g_watch_table[g_watch_count].mc = mc;
		strncpy(g_watch_table[g_watch_count].prop_name, prop_name, sizeof(g_watch_table[0].prop_name) - 1);
		g_watch_table[g_watch_count].prop_name_len = prop_name_len;
		g_watch_table[g_watch_count].watcher_func = wf;
		g_watch_table[g_watch_count].user_data = user_data;
		g_watch_count++;
		ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_BOOLEAN; ret.data.numeric_value = 1;
		return ret;
	}
	return ret_false;
}

// Built-in Object.prototype.unwatch(prop) — remove a property watcher
static ActionVar builtin_object_unwatch(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_BOOLEAN;
	ret.data.numeric_value = 0;
	if (arg_count < 1) return ret;

	// Determine target: ASObject (this_obj != NULL) or MovieClip timeline (this_obj == NULL)
	ASObject* obj = NULL;
	MovieClip* mc = NULL;
	if (this_obj != NULL) {
		obj = (ASObject*) this_obj;
	} else {
		mc = g_current_context ? g_current_context : &root_movieclip;
		if (mc == NULL) return ret;
	}

	char prop_name[64] = {0};
	u32 prop_name_len = 0;
	if (args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* u16 = varGetU16Ptr(&args[0]);
		if (u16 != NULL)
			prop_name_len = (u32)u16_to_utf8(u16, args[0].str_size, prop_name, (int)(sizeof(prop_name) - 1));
	}
	for (int i = 0; i < g_watch_count; i++) {
		if (g_watch_table[i].obj == obj &&
		    g_watch_table[i].mc == mc &&
		    g_watch_table[i].prop_name_len == prop_name_len &&
		    strncmp(g_watch_table[i].prop_name, prop_name, prop_name_len) == 0)
		{
			for (int j = i; j < g_watch_count - 1; j++)
				g_watch_table[j] = g_watch_table[j + 1];
			g_watch_count--;
			ret.data.numeric_value = 1;
			return ret;
		}
	}
	return ret;
}

// Built-in Error.prototype.toString — returns the message property
static ActionVar builtin_error_toString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 5;
	ret.data.numeric_value = (u64) u16_Error;

	if (this_obj != NULL)
	{
		ASObject* obj = (ASObject*) this_obj;
		ActionVar* msg = getPropertyWithPrototype(obj, "message", 7);
		if (msg != NULL && msg->type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* u16 = varGetU16Ptr(msg);
			if (u16 != NULL && msg->str_size > 0)
			{
				ret.data.numeric_value = (u64) u16;
				ret.str_size = msg->str_size;
			}
		}
	}
	return ret;
}

static ASFunction g_error_toString_func;

// Built-in String.fromCharCode(code1, code2, ...) — static method on String constructor
// Each argument is coerced to uint16, producing one UTF-16 code unit per argument.
static ASFunction g_string_fromCharCode_func;
static ActionVar builtin_string_fromCharCode(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 0;
	ret.data.numeric_value = 0;

	if (arg_count == 0)
		return ret;

	// Each arg produces one UTF-16 code unit
	uint16_t* buf = (uint16_t*) heap_alloc(app_context, (arg_count + 1) * sizeof(uint16_t));
	u32 pos = 0;

	for (u32 i = 0; i < arg_count; i++)
	{
		double d = 0.0;
		switch (args[i].type)
		{
			case ACTION_STACK_VALUE_F32: d = (double) VAL(float, &args[i].data.numeric_value); break;
			case ACTION_STACK_VALUE_F64: d = VAL(double, &args[i].data.numeric_value); break;
			case ACTION_STACK_VALUE_BOOLEAN: d = args[i].data.numeric_value ? 1.0 : 0.0; break;
			default: d = 0.0; break;
		}

		// ToUint16: mod 65536
		int code;
		if (isnan(d) || isinf(d)) code = 0;
		else
		{
			double n = fmod(d, 65536.0);
			if (n < 0) n += 65536.0;
			code = (int)n;
		}

		// NUL code unit terminates C-string semantics, stop here
		if (code == 0) break;

		buf[pos++] = (uint16_t)code;
	}
	buf[pos] = 0;

	ret.str_size = pos;
	ret.data.string_data.heap_ptr = buf;
	ret.data.string_data.owns_memory = true;
	return ret;
}

// ============================================================================
// Math object built-in methods
// ============================================================================

// Forward declarations for functions defined later in file
static ActionStackValueType convertFloat(SWFAppContext* app_context);

// builtin_math_random is defined later (after TRandomFast/RNG definitions)
static ActionVar builtin_math_random(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);
// initMathObject is defined later (after all Math builtins)
static void initMathObject(SWFAppContext* app_context);

// Static ASFunction objects for Math methods (18 methods)
static ASFunction g_math_funcs[18];
static ASObject* g_math_object = NULL;
static int g_math_init_done = 0;

// ============================================================================
// Geometry class globals (Point, Matrix, Rectangle)
// ============================================================================
static ASObject* g_point_prototype = NULL;
static ASObject* g_matrix_prototype = NULL;
static ASObject* g_rect_prototype = NULL;
static ASFunction g_point_methods[7];   // toString, add, subtract, equals, clone, offset, normalize
static ASFunction g_point_statics[3];   // distance, interpolate, polar
static ASFunction g_matrix_methods[12]; // toString, clone, identity, scale, rotate, translate, concat, invert, createBox, createGradientBox, transformPoint, deltaTransformPoint
static ASFunction g_rect_methods[15];   // toString, clone, equals, isEmpty, setEmpty, contains, containsPoint, containsRectangle, inflate, inflatePoint, intersection, intersects, offset, offsetPoint, union
static int g_geom_init_done = 0;

// ============================================================================
// Color class globals (AVM1 Color object)
// ============================================================================
static ASObject* g_color_prototype = NULL;
static ASFunction g_color_methods[4];  // getTransform, setTransform, getRGB, setRGB
static int g_color_init_done = 0;

// ============================================================================
// flash.geom.ColorTransform globals
// ============================================================================
static ASObject* g_color_transform_prototype = NULL;
static ASFunction g_ct_methods[2];    // concat, toString
static ASFunction g_ct_rgb_getter;
static ASFunction g_ct_rgb_setter;
static int g_color_transform_init_done = 0;

// Coerce Math arguments to f64 via the stack (calls valueOf on objects).
// Flash coerces min(arg_count, max_args) arguments, left to right.
static void coerceMathArgs(SWFAppContext* app_context, ActionVar* args, u32 arg_count, u32 max_args)
{
	u32 n = arg_count < max_args ? arg_count : max_args;
	for (u32 i = 0; i < n; i++)
	{
		pushVar(app_context, &args[i]);
		convertFloat(app_context);
		popVar(app_context, &args[i]);
	}
}

// Helper: extract f64 from a coerced ActionVar
static inline double mathArgToDouble(ActionVar* v)
{
	if (v->type == ACTION_STACK_VALUE_F64)
		return VAL(double, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_F32)
		return (double) VAL(float, &v->data.numeric_value);
	return NAN;
}

// Helper: return f64 ActionVar
static inline ActionVar mathReturnDouble(double val)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_F64;
	ret.str_size = 0;
	VAL(double, &ret.data.numeric_value) = val;
	return ret;
}

// --- Unary Math functions (abs, sin, cos, tan, exp, log, sqrt, round, floor, ceil, atan, asin, acos) ---

static ActionVar builtin_math_abs(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(fabs(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_sin(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(sin(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_cos(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(cos(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_tan(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(tan(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_exp(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(exp(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_log(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(log(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_sqrt(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(sqrt(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_round(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	double x = mathArgToDouble(&args[0]);
	// Flash uses floor(x + 0.5) which gives round(-12.5) = -12
	return mathReturnDouble(floor(x + 0.5));
}

static ActionVar builtin_math_floor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(floor(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_ceil(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(ceil(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_atan(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(atan(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_asin(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(asin(mathArgToDouble(&args[0])));
}

static ActionVar builtin_math_acos(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	return mathReturnDouble(acos(mathArgToDouble(&args[0])));
}

// --- Binary Math functions (atan2, pow, min, max) ---

static ActionVar builtin_math_atan2(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count < 2) return mathReturnDouble(NAN);
	double y = mathArgToDouble(&args[0]);
	double x = mathArgToDouble(&args[1]);
	return mathReturnDouble(atan2(y, x));
}

static ActionVar builtin_math_pow(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(NAN);
	double base = mathArgToDouble(&args[0]);
	// Missing second arg → NaN; pow(1, NaN) = 1 per IEEE 754
	double exponent = (arg_count >= 2) ? mathArgToDouble(&args[1]) : NAN;
	return mathReturnDouble(pow(base, exponent));
}

static ActionVar builtin_math_min(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(INFINITY);
	if (arg_count == 1) return mathReturnDouble(NAN);
	double a = mathArgToDouble(&args[0]);
	double b = mathArgToDouble(&args[1]);
	if (isnan(a) || isnan(b)) return mathReturnDouble(NAN);
	// Handle -0: if a == b and one is -0, return -0
	if (a < b) return mathReturnDouble(a);
	if (b < a) return mathReturnDouble(b);
	// a == b: return the one that might be -0
	return mathReturnDouble(signbit(a) ? a : b);
}

static ActionVar builtin_math_max(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	if (arg_count == 0) return mathReturnDouble(-INFINITY);
	if (arg_count == 1) return mathReturnDouble(NAN);
	double a = mathArgToDouble(&args[0]);
	double b = mathArgToDouble(&args[1]);
	if (isnan(a) || isnan(b)) return mathReturnDouble(NAN);
	if (a > b) return mathReturnDouble(a);
	if (b > a) return mathReturnDouble(b);
	// a == b: return the one that is NOT -0
	return mathReturnDouble(signbit(a) ? b : a);
}

// --- ASnative (class 200 = Math) ---

// NaN stub: coerces args (calling valueOf on first two) but always returns NaN.
// Returned by ASnative(200, invalid_index).
static ActionVar builtin_math_nan_stub(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	return mathReturnDouble(NAN);
}

// ASnative(class_id, method_index) — returns a native method by numeric address.
// Currently handles class 200 (Math): returns the Math function at the given index,
// or a NaN stub (with valueOf coercion side-effects) for out-of-range indices.
static ActionVar builtin_asnative(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	ActionVar undef = {0};
	undef.type = ACTION_STACK_VALUE_UNDEFINED;
	if (arg_count < 2) return undef;

	int class_id     = (int)mathArgToDouble(&args[0]);
	int method_index = (int)mathArgToDouble(&args[1]);

	if (class_id == 200) {
		// Math class: ensure the Math object and its function table are ready
		initMathObject(app_context);
		// Valid indices 0–17 map directly to g_math_funcs[]
		if (method_index >= 0 && method_index < 18) {
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_FUNCTION;
			VAL(u64, &result.data.numeric_value) = (u64)&g_math_funcs[method_index];
			return result;
		}
		// Out-of-range index → NaN stub (still coerces its args via valueOf)
		static ASFunction g_nan_stub;
		static int g_nan_stub_init = 0;
		if (!g_nan_stub_init) {
			memset(&g_nan_stub, 0, sizeof(ASFunction));
			strncpy(g_nan_stub.name, "stub", 255);
			g_nan_stub.function_type = 2;
			g_nan_stub.advanced_func = (Function2Ptr)builtin_math_nan_stub;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_nan_stub;
			g_nan_stub_init = 1;
		}
		ActionVar result = {0};
		result.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &result.data.numeric_value) = (u64)&g_nan_stub;
		return result;
	}

	return undef;
}

// --- Math object initialization ---

static void initMathObject(SWFAppContext* app_context)
{
	if (g_math_init_done) return;

	g_math_object = allocObject(app_context, 32);
	retainObject(g_math_object);

	// Register constants (explicit values; M_PI etc. not available with -std=c17)
	ActionVar cv = {0};
	cv.type = ACTION_STACK_VALUE_F64;

	VAL(double, &cv.data.numeric_value) = 3.14159265358979323846;
	setProperty(app_context, g_math_object, "PI", 2, &cv);
	VAL(double, &cv.data.numeric_value) = 2.71828182845904523536;
	setProperty(app_context, g_math_object, "E", 1, &cv);
	VAL(double, &cv.data.numeric_value) = 0.69314718055994530942;
	setProperty(app_context, g_math_object, "LN2", 3, &cv);
	VAL(double, &cv.data.numeric_value) = 2.30258509299404568402;
	setProperty(app_context, g_math_object, "LN10", 4, &cv);
	VAL(double, &cv.data.numeric_value) = 1.44269504088896340736;
	setProperty(app_context, g_math_object, "LOG2E", 5, &cv);
	VAL(double, &cv.data.numeric_value) = 0.43429448190325182765;
	setProperty(app_context, g_math_object, "LOG10E", 6, &cv);
	VAL(double, &cv.data.numeric_value) = 1.41421356237309504880;
	setProperty(app_context, g_math_object, "SQRT2", 5, &cv);
	VAL(double, &cv.data.numeric_value) = 0.70710678118654752440;
	setProperty(app_context, g_math_object, "SQRT1_2", 7, &cv);

	// Register methods
	struct { const char* name; u32 name_len; Function2Ptr func; } math_methods[] = {
		{"abs",    3, (Function2Ptr)builtin_math_abs},
		{"sin",    3, (Function2Ptr)builtin_math_sin},
		{"cos",    3, (Function2Ptr)builtin_math_cos},
		{"tan",    3, (Function2Ptr)builtin_math_tan},
		{"exp",    3, (Function2Ptr)builtin_math_exp},
		{"log",    3, (Function2Ptr)builtin_math_log},
		{"sqrt",   4, (Function2Ptr)builtin_math_sqrt},
		{"round",  5, (Function2Ptr)builtin_math_round},
		{"floor",  5, (Function2Ptr)builtin_math_floor},
		{"ceil",   4, (Function2Ptr)builtin_math_ceil},
		{"atan",   4, (Function2Ptr)builtin_math_atan},
		{"asin",   4, (Function2Ptr)builtin_math_asin},
		{"acos",   4, (Function2Ptr)builtin_math_acos},
		{"atan2",  5, (Function2Ptr)builtin_math_atan2},
		{"pow",    3, (Function2Ptr)builtin_math_pow},
		{"min",    3, (Function2Ptr)builtin_math_min},
		{"max",    3, (Function2Ptr)builtin_math_max},
		{"random", 6, (Function2Ptr)builtin_math_random},
	};

	for (int i = 0; i < 18; i++)
	{
		memset(&g_math_funcs[i], 0, sizeof(ASFunction));
		strncpy(g_math_funcs[i].name, math_methods[i].name, 255);
		g_math_funcs[i].function_type = 2;
		g_math_funcs[i].param_count = 0;
		g_math_funcs[i].advanced_func = math_methods[i].func;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_math_funcs[i];

		ActionVar fv = {0};
		fv.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &fv.data.numeric_value) = (u64)&g_math_funcs[i];
		setProperty(app_context, g_math_object, math_methods[i].name, math_methods[i].name_len, &fv);
	}

	// Math is a native static object — always returns "[object Object]" regardless of SWF version
	installNativeToString(app_context, g_math_object);

	g_math_init_done = 1;
}

// ============================================================================
// Date class implementation
// ============================================================================

// Forward declarations for functions defined later in this file
static void initDatePrototype(SWFAppContext* app_context);
static void setObjectProto(SWFAppContext* app_context, ASObject* obj);

static ASFunction g_date_constructor;
static ASFunction g_date_funcs[40]; // 20 getters + 17 setters + toString + valueOf + UTC
static ASObject* g_date_prototype = NULL;
static int g_date_init_done = 0;
static double g_date_local_tza_ms = 0.0; // local timezone offset in ms (positive = east of UTC)
static int g_date_tza_init = 0;

#define DATE_MS_PER_DAY 86400000.0
#define DATE_MS_PER_HOUR 3600000.0
#define DATE_MS_PER_MINUTE 60000.0
#define DATE_MS_PER_SECOND 1000.0

// --- Date math utility functions (ECMAScript 3 algorithms) ---

static double date_day(double t) { return floor(t / DATE_MS_PER_DAY); }

static double date_time_within_day(double t) {
	double r = fmod(t, DATE_MS_PER_DAY);
	if (r < 0) r += DATE_MS_PER_DAY;
	return r + 0.0; // eliminate -0
}

static int date_days_in_year(int y) {
	if (y % 4 != 0) return 365;
	if (y % 100 != 0) return 366;
	if (y % 400 != 0) return 365;
	return 366;
}

static double date_day_from_year(double y) {
	return 365.0 * (y - 1970.0) + floor((y - 1969.0) / 4.0) - floor((y - 1901.0) / 100.0) + floor((y - 1601.0) / 400.0);
}

static double date_time_from_year(double y) {
	return DATE_MS_PER_DAY * date_day_from_year(y);
}

static double date_year_from_time(double t) {
	// Binary search for the year
	double day = date_day(t);
	// Approximate year
	double y = floor(day / 365.2425) + 1970.0;
	// Adjust: find the year such that day_from_year(y) <= day < day_from_year(y+1)
	while (date_day_from_year(y + 1) <= day) y++;
	while (date_day_from_year(y) > day) y--;
	return y;
}

static int date_in_leap_year(double t) {
	double y = date_year_from_time(t);
	return date_days_in_year((int)y) == 366 ? 1 : 0;
}

static int date_day_within_year(double t) {
	return (int)(date_day(t) - date_day_from_year(date_year_from_time(t)));
}

static const int date_month_start[2][13] = {
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}, // non-leap
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}, // leap
};

static int date_month_from_time(double t) {
	int dwy = date_day_within_year(t);
	int leap = date_in_leap_year(t);
	for (int m = 11; m >= 0; m--) {
		if (dwy >= date_month_start[leap][m]) return m;
	}
	return 0;
}

static int date_date_from_time(double t) {
	int dwy = date_day_within_year(t);
	int leap = date_in_leap_year(t);
	int m = date_month_from_time(t);
	return dwy - date_month_start[leap][m] + 1;
}

static int date_week_day(double t) {
	double d = fmod(date_day(t) + 4.0, 7.0); // Jan 1 1970 = Thursday (4)
	if (d < 0) d += 7.0;
	return (int)d;
}

static double date_hour_from_time(double t) { return fmod(floor(t / DATE_MS_PER_HOUR), 24.0); }
static double date_min_from_time(double t) { return fmod(floor(t / DATE_MS_PER_MINUTE), 60.0); }
static double date_sec_from_time(double t) { return fmod(floor(t / DATE_MS_PER_SECOND), 60.0); }
static double date_ms_from_time(double t) { return floor(fmod(t, DATE_MS_PER_SECOND)); }

// Fix negative modular results and -0 for time components
static double date_hour_from_time_safe(double t) {
	double r = date_hour_from_time(t);
	if (r < 0) r += 24.0;
	return r + 0.0;
}
static double date_min_from_time_safe(double t) {
	double r = date_min_from_time(t);
	if (r < 0) r += 60.0;
	return r + 0.0;
}
static double date_sec_from_time_safe(double t) {
	double r = date_sec_from_time(t);
	if (r < 0) r += 60.0;
	return r + 0.0;
}
static double date_ms_from_time_safe(double t) {
	double r = date_ms_from_time(t);
	if (r < 0) r += 1000.0;
	return r + 0.0;
}

static double date_make_time(double hour, double min, double sec, double ms) {
	if (!isfinite(hour) || !isfinite(min) || !isfinite(sec) || !isfinite(ms)) {
		// Infinity propagates, NaN propagates
		return hour * DATE_MS_PER_HOUR + min * DATE_MS_PER_MINUTE + sec * DATE_MS_PER_SECOND + ms;
	}
	return trunc(hour) * DATE_MS_PER_HOUR + trunc(min) * DATE_MS_PER_MINUTE + trunc(sec) * DATE_MS_PER_SECOND + trunc(ms);
}

static double date_make_day(double year, double month, double date_d) {
	if (!isfinite(year) || !isfinite(month)) return NAN;
	year = trunc(year);
	month = trunc(month);
	if (isfinite(date_d)) date_d = trunc(date_d);
	double y = year + floor(month / 12.0);
	double m = fmod(month, 12.0);
	if (m < 0) m += 12.0;
	int mi = (int)m;
	// Find day number for the start of month m in year y
	int leap = date_days_in_year((int)y) == 366 ? 1 : 0;
	double day_start = date_day_from_year(y) + (double)date_month_start[leap][mi];
	return day_start + date_d - 1.0;
}

static double date_make_date(double day, double time_v) {
	if (!isfinite(day) || !isfinite(time_v)) return day * DATE_MS_PER_DAY + time_v;
	return day * DATE_MS_PER_DAY + time_v;
}

static void date_ensure_tza(void) {
	if (g_date_tza_init) return;
	g_date_tza_init = 1;
	// Compute local timezone offset from system
	time_t now = time(NULL);
	struct tm gmt_tm, local_tm;
	gmtime_r(&now, &gmt_tm);
	localtime_r(&now, &local_tm);
	// Difference in seconds
	time_t gmt_epoch = timegm(&gmt_tm);
	time_t local_epoch = timegm(&local_tm);
	double offset_sec = difftime(local_epoch, gmt_epoch);
	g_date_local_tza_ms = offset_sec * 1000.0;
}

static double date_utc_to_local(double t) {
	date_ensure_tza();
	return t + g_date_local_tza_ms;
}

static double date_local_to_utc(double t) {
	date_ensure_tza();
	return t - g_date_local_tza_ms;
}

// --- Date internal timestamp access ---

static double date_get_time(ASObject* obj) {
	ActionVar* v = getProperty(obj, "__date_time__", 13);
	if (v == NULL) return NAN;
	if (v->type == ACTION_STACK_VALUE_F64) return VAL(double, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_F32) return (double)VAL(float, &v->data.numeric_value);
	return NAN;
}

static void date_set_time(SWFAppContext* ctx, ASObject* obj, double t) {
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_F64;
	VAL(double, &v.data.numeric_value) = t;
	setProperty(ctx, obj, "__date_time__", 13, &v);
}

// --- Date.prototype.toString ---

static const char* date_day_names[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
static const char* date_month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

static ActionVar date_return_string(SWFAppContext* app_context, const char* str, u32 len) {
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len = 0;
	uint16_t* u16 = utf8_to_u16(app_context, str, len, &u16_len);
	ret.str_size = u16_len;
	ret.data.numeric_value = (u64)u16;
	return ret;
}

static ActionVar builtin_date_toString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)args; (void)arg_count; (void)registers;
	if (this_obj == NULL) return date_return_string(app_context, "Invalid Date", 12);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);

	if (isnan(t) || isinf(t)) {
		return date_return_string(app_context, "Invalid Date", 12);
	}

	double lt = date_utc_to_local(t);
	double y = date_year_from_time(lt);
	int month = date_month_from_time(lt);
	int day = date_date_from_time(lt);
	int wday = date_week_day(lt);
	int hour = (int)date_hour_from_time_safe(lt);
	int min = (int)date_min_from_time_safe(lt);
	int sec = (int)date_sec_from_time_safe(lt);

	date_ensure_tza();
	int offset_min = (int)(g_date_local_tza_ms / DATE_MS_PER_MINUTE);
	int offset_h = offset_min / 60;
	int offset_m = offset_min % 60;
	if (offset_m < 0) offset_m = -offset_m;

	char buf[80];
	int year_i = (int)y;
	if (year_i < 0) {
		snprintf(buf, sizeof(buf), "%s %s %d %02d:%02d:%02d GMT%+03d%02d %d",
			date_day_names[wday], date_month_names[month], day,
			hour, min, sec, offset_h, offset_m, year_i);
	} else {
		snprintf(buf, sizeof(buf), "%s %s %d %02d:%02d:%02d GMT%+03d%02d %d",
			date_day_names[wday], date_month_names[month], day,
			hour, min, sec, offset_h, offset_m, year_i);
	}

	return date_return_string(app_context, buf, (u32)strlen(buf));
}

// --- Date.prototype.valueOf ---

static ActionVar builtin_date_valueOf(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	double t = date_get_time((ASObject*)this_obj);
	return mathReturnDouble(t);
}

// --- Date getter helpers ---

static double date_arg_to_double(SWFAppContext* app_context, ActionVar* v) {
	if (v->type == ACTION_STACK_VALUE_F64) return VAL(double, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_F32) return (double)VAL(float, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_BOOLEAN) return v->data.numeric_value ? 1.0 : 0.0;
	if (v->type == ACTION_STACK_VALUE_UNDEFINED) {
		return (EFFECTIVE_SWF_VERSION() < 7) ? 0.0 : NAN;
	}
	if (v->type == ACTION_STACK_VALUE_NULL) return NAN;
	if (v->type == ACTION_STACK_VALUE_STRING) {
		return varToDoubleSimple(v);
	}
	if (v->type == ACTION_STACK_VALUE_OBJECT) {
		// Call valueOf
		ASObject* o = (ASObject*)(u64)v->data.numeric_value;
		if (o != NULL) {
			ActionVar* vo = getPropertyWithPrototype(o, "valueOf", 7);
			if (vo != NULL && vo->type == ACTION_STACK_VALUE_FUNCTION) {
				ASFunction* func = (ASFunction*)vo->data.numeric_value;
				if (func != NULL && func->advanced_func != NULL) {
					ActionVar result = func->advanced_func(app_context, NULL, 0, NULL, (void*)o);
					return varToDoubleSimple(&result);
				}
			}
		}
		return NAN;
	}
	return NAN;
}

// Flash's integer conversion for date args: NaN → 0, Inf → propagates through arithmetic
static double date_to_integer(double x) {
	if (isnan(x)) return 0.0;
	if (!isfinite(x)) return x;
	return trunc(x);
}

// --- 20 getter methods ---

#define DATE_GETTER(name, expr_local, expr_utc, is_utc) \
static ActionVar builtin_date_##name(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) { \
	(void)app_context; (void)args; (void)arg_count; (void)registers; \
	if (this_obj == NULL) return mathReturnDouble(NAN); \
	double t = date_get_time((ASObject*)this_obj); \
	if (isnan(t) || !isfinite(t)) return mathReturnDouble(NAN); \
	if (is_utc) { return mathReturnDouble(expr_utc); } \
	else { double lt = date_utc_to_local(t); (void)lt; return mathReturnDouble(expr_local); } \
}

DATE_GETTER(getFullYear, date_year_from_time(lt), date_year_from_time(t), 0)
DATE_GETTER(getYear, date_year_from_time(lt) - 1900.0, date_year_from_time(t) - 1900.0, 0)
DATE_GETTER(getMonth, (double)date_month_from_time(lt), (double)date_month_from_time(t), 0)
DATE_GETTER(getDate, (double)date_date_from_time(lt), (double)date_date_from_time(t), 0)
DATE_GETTER(getDay, (double)date_week_day(lt), (double)date_week_day(t), 0)
DATE_GETTER(getHours, date_hour_from_time_safe(lt), date_hour_from_time_safe(t), 0)
DATE_GETTER(getMinutes, date_min_from_time_safe(lt), date_min_from_time_safe(t), 0)
DATE_GETTER(getSeconds, date_sec_from_time_safe(lt), date_sec_from_time_safe(t), 0)
DATE_GETTER(getMilliseconds, date_ms_from_time_safe(lt), date_ms_from_time_safe(t), 0)
// getTime returns raw UTC timestamp (even Infinity)
static ActionVar builtin_date_getTime(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	double t = date_get_time((ASObject*)this_obj);
	return mathReturnDouble(t);
}
DATE_GETTER(getUTCFullYear, 0, date_year_from_time(t), 1)
DATE_GETTER(getUTCYear, 0, date_year_from_time(t) - 1900.0, 1)
DATE_GETTER(getUTCMonth, 0, (double)date_month_from_time(t), 1)
DATE_GETTER(getUTCDate, 0, (double)date_date_from_time(t), 1)
DATE_GETTER(getUTCDay, 0, (double)date_week_day(t), 1)
DATE_GETTER(getUTCHours, 0, date_hour_from_time_safe(t), 1)
DATE_GETTER(getUTCMinutes, 0, date_min_from_time_safe(t), 1)
DATE_GETTER(getUTCSeconds, 0, date_sec_from_time_safe(t), 1)
DATE_GETTER(getUTCMilliseconds, 0, date_ms_from_time_safe(t), 1)

// getTimezoneOffset: returns -(offset_ms / 60000)
static ActionVar builtin_date_getTimezoneOffset(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	double t = date_get_time((ASObject*)this_obj);
	if (isnan(t) || !isfinite(t)) return mathReturnDouble(NAN);
	date_ensure_tza();
	return mathReturnDouble(-(g_date_local_tza_ms / DATE_MS_PER_MINUTE));
}

// --- 17 setter methods ---
// TimeClip: clamp result to valid range, otherwise NaN
static double date_time_clip(double t) {
	if (!isfinite(t)) return NAN;
	if (fabs(t) > 8.64e15) return NAN;
	return t;
}

// setFullYear(year [, month [, day]])
static ActionVar builtin_date_setFullYear(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double y = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double m = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : (double)date_month_from_time(lt);
	double d = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : (double)date_date_from_time(lt);
	double u = date_time_clip(date_local_to_utc(date_make_date(date_make_day(y, m, d), date_time_within_day(lt))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setMonth(month [, day])
static ActionVar builtin_date_setMonth(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double m = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	if (isnan(m)) m = 0.0;
	double d = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : (double)date_date_from_time(lt);
	double u = date_time_clip(date_local_to_utc(date_make_date(date_make_day(date_year_from_time(lt), m, d), date_time_within_day(lt))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setDate(day)
static ActionVar builtin_date_setDate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double d = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double u = date_time_clip(date_local_to_utc(date_make_date(date_make_day(date_year_from_time(lt), (double)date_month_from_time(lt), d), date_time_within_day(lt))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setHours(hour [, min [, sec [, ms]]])
static ActionVar builtin_date_setHours(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double h  = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double mi = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_min_from_time_safe(lt);
	double s  = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : date_sec_from_time_safe(lt);
	double ms = (arg_count >= 4) ? date_arg_to_double(app_context, &args[3]) : date_ms_from_time_safe(lt);
	double u = date_time_clip(date_local_to_utc(date_make_date(date_day(lt), date_make_time(h, mi, s, ms))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setMinutes(min [, sec [, ms]])
static ActionVar builtin_date_setMinutes(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double mi = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double s  = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_sec_from_time_safe(lt);
	double ms = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : date_ms_from_time_safe(lt);
	if (!isfinite(mi)) mi = -2147483648.0;
	if (!isfinite(s))  s  = -2147483648.0;
	if (!isfinite(ms)) ms = -2147483648.0;
	double u = date_time_clip(date_local_to_utc(date_make_date(date_day(lt), date_make_time(date_hour_from_time_safe(lt), mi, s, ms))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setSeconds(sec [, ms])
static ActionVar builtin_date_setSeconds(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double s  = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double ms = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_ms_from_time_safe(lt);
	double u = date_time_clip(date_local_to_utc(date_make_date(date_day(lt), date_make_time(date_hour_from_time_safe(lt), date_min_from_time_safe(lt), s, ms))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setMilliseconds(ms)
static ActionVar builtin_date_setMilliseconds(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double ms = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double u = date_time_clip(date_local_to_utc(date_make_date(date_day(lt), date_make_time(date_hour_from_time_safe(lt), date_min_from_time_safe(lt), date_sec_from_time_safe(lt), ms))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setTime(ms) — sets the raw UTC timestamp
static ActionVar builtin_date_setTime(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double ms = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	if (isfinite(ms)) ms = trunc(ms);
	ms = date_time_clip(ms);
	date_set_time(app_context, obj, ms);
	return mathReturnDouble(ms);
}

// setYear(year [, month [, day]]) — legacy: year 0-99 → 1900+year
static ActionVar builtin_date_setYear(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double lt = date_utc_to_local(t);
	double y = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	if (isnan(y) || !isfinite(y)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	y = trunc(y);
	if (y >= 0 && y <= 99) y = 1900.0 + y;
	double m = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : (double)date_month_from_time(lt);
	double d = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : (double)date_date_from_time(lt);
	double u = date_time_clip(date_local_to_utc(date_make_date(date_make_day(y, m, d), date_time_within_day(lt))));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// --- UTC setter variants ---

// setUTCFullYear(year [, month [, day]])
static ActionVar builtin_date_setUTCFullYear(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double y = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double m = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : (double)date_month_from_time(t);
	double d = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : (double)date_date_from_time(t);
	double u = date_time_clip(date_make_date(date_make_day(y, m, d), date_time_within_day(t)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCMonth(month [, day])
static ActionVar builtin_date_setUTCMonth(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double m = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	if (isnan(m)) m = 0.0;
	double d = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : (double)date_date_from_time(t);
	double u = date_time_clip(date_make_date(date_make_day(date_year_from_time(t), m, d), date_time_within_day(t)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCDate(day)
static ActionVar builtin_date_setUTCDate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double d = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double u = date_time_clip(date_make_date(date_make_day(date_year_from_time(t), (double)date_month_from_time(t), d), date_time_within_day(t)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCHours(hour [, min [, sec [, ms]]])
static ActionVar builtin_date_setUTCHours(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double h  = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double mi = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_min_from_time_safe(t);
	double s  = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : date_sec_from_time_safe(t);
	double ms = (arg_count >= 4) ? date_arg_to_double(app_context, &args[3]) : date_ms_from_time_safe(t);
	double u = date_time_clip(date_make_date(date_day(t), date_make_time(h, mi, s, ms)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCMinutes(min [, sec [, ms]])
static ActionVar builtin_date_setUTCMinutes(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double mi = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double s  = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_sec_from_time_safe(t);
	double ms = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : date_ms_from_time_safe(t);
	if (!isfinite(mi)) mi = -2147483648.0;
	if (!isfinite(s))  s  = -2147483648.0;
	if (!isfinite(ms)) ms = -2147483648.0;
	double u = date_time_clip(date_make_date(date_day(t), date_make_time(date_hour_from_time_safe(t), mi, s, ms)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCSeconds(sec [, ms])
static ActionVar builtin_date_setUTCSeconds(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double s  = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double ms = (arg_count >= 2) ? date_arg_to_double(app_context, &args[1]) : date_ms_from_time_safe(t);
	double u = date_time_clip(date_make_date(date_day(t), date_make_time(date_hour_from_time_safe(t), date_min_from_time_safe(t), s, ms)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// setUTCMilliseconds(ms)
static ActionVar builtin_date_setUTCMilliseconds(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return mathReturnDouble(NAN);
	ASObject* obj = (ASObject*)this_obj;
	double t = date_get_time(obj);
	if (isnan(t)) { date_set_time(app_context, obj, NAN); return mathReturnDouble(NAN); }
	double ms = (arg_count >= 1) ? date_arg_to_double(app_context, &args[0]) : NAN;
	double u = date_time_clip(date_make_date(date_day(t), date_make_time(date_hour_from_time_safe(t), date_min_from_time_safe(t), date_sec_from_time_safe(t), ms)));
	date_set_time(app_context, obj, u);
	return mathReturnDouble(u);
}

// --- Date.UTC() static method ---

static ActionVar builtin_date_UTC(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers; (void)this_obj;
	// 0-1 args: return undefined
	if (arg_count < 2) {
		ActionVar ret = {0};
		ret.type = ACTION_STACK_VALUE_UNDEFINED;
		return ret;
	}

	double year_d = date_arg_to_double(app_context, &args[0]);
	// Year: C-style int32 cast for NaN/Infinity handling (matches Flash)
	int32_t yi = (int32_t)year_d;
	double year = (double)yi;
	if (yi < 100) year = 1900.0 + year;

	double month = date_arg_to_double(app_context, &args[1]);
	double day   = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : 1.0;
	double hour  = (arg_count >= 4) ? date_arg_to_double(app_context, &args[3]) : 0.0;
	double min_v = (arg_count >= 5) ? date_arg_to_double(app_context, &args[4]) : 0.0;
	double sec   = (arg_count >= 6) ? date_arg_to_double(app_context, &args[5]) : 0.0;
	double ms    = (arg_count >= 7) ? date_arg_to_double(app_context, &args[6]) : 0.0;

	// Month: NaN → NaN (not integer-converted like in setters)
	if (isnan(month)) return mathReturnDouble(NAN);
	month = trunc(month);
	day = trunc(day); hour = trunc(hour); min_v = trunc(min_v); sec = trunc(sec); ms = trunc(ms);

	double d = date_make_day(year, month, day);
	double t = date_make_time(hour, min_v, sec, ms);
	return mathReturnDouble(date_make_date(d, t));
}

// --- Date constructor ---

static ASObject* date_construct(SWFAppContext* app_context, ActionVar* args, u32 arg_count) {
	initDatePrototype(app_context);
	ASObject* date = allocObject(app_context, 4);

	// Set __proto__ to Date.prototype
	ActionVar proto_var = {0};
	proto_var.type = ACTION_STACK_VALUE_OBJECT;
	proto_var.data.numeric_value = (u64)g_date_prototype;
	setProperty(app_context, date, "__proto__", 9, &proto_var);

	double t;
	if (arg_count == 0) {
#ifdef MOCK_DATE_TIME
		t = (double)(MOCK_DATE_TIME);
#else
		struct timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		t = (double)ts.tv_sec * 1000.0 + (double)(ts.tv_nsec / 1000000);
#endif
	} else if (arg_count == 1) {
		// Single arg: timestamp or valueOf of object
		t = date_arg_to_double(app_context, &args[0]);
	} else {
		// 2-7 args: year, month [, day [, hour [, min [, sec [, ms]]]]]
		double year_d = date_arg_to_double(app_context, &args[0]);
		// Year: C-style int32 cast for NaN/Infinity handling (matches Flash)
		int32_t yi = (int32_t)year_d;
		double year = (double)yi;
		if (yi < 100) year = 1900.0 + year;

		double month = date_arg_to_double(app_context, &args[1]);
		double day   = (arg_count >= 3) ? date_arg_to_double(app_context, &args[2]) : 1.0;
		double hour  = (arg_count >= 4) ? date_arg_to_double(app_context, &args[3]) : 0.0;
		double min_v = (arg_count >= 5) ? date_arg_to_double(app_context, &args[4]) : 0.0;
		double sec   = (arg_count >= 6) ? date_arg_to_double(app_context, &args[5]) : 0.0;
		double ms    = (arg_count >= 7) ? date_arg_to_double(app_context, &args[6]) : 0.0;

		if (isnan(month)) { month = trunc(month); } else { month = trunc(month); }
		day = trunc(day); hour = trunc(hour); min_v = trunc(min_v); sec = trunc(sec); ms = trunc(ms);

		double d = date_make_day(year, month, day);
		double time_v = date_make_time(hour, min_v, sec, ms);
		t = date_local_to_utc(date_make_date(d, time_v));
	}

	date_set_time(app_context, date, t);
	return date;
}

// Date constructor callback (for advanced_func)
static ActionVar builtin_date_constructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers; (void)this_obj;
	// This is called when Date is used as a constructor via the prototype-based path
	// The actual construction happens in actionNewObject / actionNewMethod
	// Return undefined — the caller uses 'this' object
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	return ret;
}

// --- Date prototype initialization ---

static void initDatePrototype(SWFAppContext* app_context) {
	if (g_date_init_done) return;
	g_date_init_done = 1;

	memset(&g_date_constructor, 0, sizeof(ASFunction));
	strncpy(g_date_constructor.name, "Date", 255);
	g_date_constructor.function_type = 2;
	g_date_constructor.param_count = 0;
	g_date_constructor.advanced_func = (Function2Ptr)builtin_date_constructor;
	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = &g_date_constructor;

	g_date_prototype = allocObject(app_context, 48);
	retainObject(g_date_prototype);
	g_date_constructor.prototype_obj = g_date_prototype;

	// Set __proto__ to Object.prototype
	setObjectProto(app_context, g_date_prototype);

	// Register all methods
	struct { const char* name; u32 name_len; Function2Ptr func; } date_methods[] = {
		{"toString",           8, (Function2Ptr)builtin_date_toString},
		{"valueOf",            7, (Function2Ptr)builtin_date_valueOf},
		{"getFullYear",       11, (Function2Ptr)builtin_date_getFullYear},
		{"getYear",            7, (Function2Ptr)builtin_date_getYear},
		{"getMonth",           8, (Function2Ptr)builtin_date_getMonth},
		{"getDate",            7, (Function2Ptr)builtin_date_getDate},
		{"getDay",             6, (Function2Ptr)builtin_date_getDay},
		{"getHours",           8, (Function2Ptr)builtin_date_getHours},
		{"getMinutes",        10, (Function2Ptr)builtin_date_getMinutes},
		{"getSeconds",        10, (Function2Ptr)builtin_date_getSeconds},
		{"getMilliseconds",   15, (Function2Ptr)builtin_date_getMilliseconds},
		{"getTime",            7, (Function2Ptr)builtin_date_getTime},
		{"getTimezoneOffset", 17, (Function2Ptr)builtin_date_getTimezoneOffset},
		{"getUTCFullYear",    14, (Function2Ptr)builtin_date_getUTCFullYear},
		{"getUTCYear",        10, (Function2Ptr)builtin_date_getUTCYear},
		{"getUTCMonth",       11, (Function2Ptr)builtin_date_getUTCMonth},
		{"getUTCDate",        10, (Function2Ptr)builtin_date_getUTCDate},
		{"getUTCDay",          9, (Function2Ptr)builtin_date_getUTCDay},
		{"getUTCHours",       11, (Function2Ptr)builtin_date_getUTCHours},
		{"getUTCMinutes",     13, (Function2Ptr)builtin_date_getUTCMinutes},
		{"getUTCSeconds",     13, (Function2Ptr)builtin_date_getUTCSeconds},
		{"getUTCMilliseconds",18, (Function2Ptr)builtin_date_getUTCMilliseconds},
		{"setFullYear",       11, (Function2Ptr)builtin_date_setFullYear},
		{"setMonth",           8, (Function2Ptr)builtin_date_setMonth},
		{"setDate",            7, (Function2Ptr)builtin_date_setDate},
		{"setHours",           8, (Function2Ptr)builtin_date_setHours},
		{"setMinutes",        10, (Function2Ptr)builtin_date_setMinutes},
		{"setSeconds",        10, (Function2Ptr)builtin_date_setSeconds},
		{"setMilliseconds",   15, (Function2Ptr)builtin_date_setMilliseconds},
		{"setTime",            7, (Function2Ptr)builtin_date_setTime},
		{"setYear",            7, (Function2Ptr)builtin_date_setYear},
		{"setUTCFullYear",    14, (Function2Ptr)builtin_date_setUTCFullYear},
		{"setUTCMonth",       11, (Function2Ptr)builtin_date_setUTCMonth},
		{"setUTCDate",        10, (Function2Ptr)builtin_date_setUTCDate},
		{"setUTCHours",       11, (Function2Ptr)builtin_date_setUTCHours},
		{"setUTCMinutes",     13, (Function2Ptr)builtin_date_setUTCMinutes},
		{"setUTCSeconds",     13, (Function2Ptr)builtin_date_setUTCSeconds},
		{"setUTCMilliseconds",18, (Function2Ptr)builtin_date_setUTCMilliseconds},
	};

	int num_date_methods = 38;
	for (int i = 0; i < num_date_methods; i++) {
		memset(&g_date_funcs[i], 0, sizeof(ASFunction));
		strncpy(g_date_funcs[i].name, date_methods[i].name, 255);
		g_date_funcs[i].function_type = 2;
		g_date_funcs[i].param_count = 0;
		g_date_funcs[i].advanced_func = date_methods[i].func;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_date_funcs[i];

		ActionVar fv = {0};
		fv.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &fv.data.numeric_value) = (u64)&g_date_funcs[i];
		setProperty(app_context, g_date_prototype, date_methods[i].name, date_methods[i].name_len, &fv);
	}

	// Register Date.UTC as a static method on the constructor
	{
		static ASFunction g_date_utc_func;
		memset(&g_date_utc_func, 0, sizeof(ASFunction));
		strncpy(g_date_utc_func.name, "UTC", 255);
		g_date_utc_func.function_type = 2;
		g_date_utc_func.param_count = 0;
		g_date_utc_func.advanced_func = (Function2Ptr)builtin_date_UTC;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_date_utc_func;

		ActionVar utc_fv = {0};
		utc_fv.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &utc_fv.data.numeric_value) = (u64)&g_date_utc_func;

		// Set on the constructor's own_props (accessed as Date.UTC)
		if (g_date_constructor.prototype_obj != NULL) {
			// We need to set UTC on the constructor function itself, not its prototype
			// ASFunction has own_props for this
			if (g_date_constructor.own_props == NULL) {
				g_date_constructor.own_props = allocObject(app_context, 4);
				retainObject(g_date_constructor.own_props);
			}
			setProperty(app_context, g_date_constructor.own_props, "UTC", 3, &utc_fv);
		}
	}
}

// ============================================================================

// Built-in valueOf for primitive wrapper objects (new Object(5))
static ActionVar builtin_wrapper_valueOf(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.str_size = 0;
	ret.data.numeric_value = 0;

	if (this_obj != NULL)
	{
		ASObject* obj = (ASObject*) this_obj;
		ActionVar* prim = getProperty(obj, "valueOf_value", 13);
		if (prim != NULL)
			ret = *prim;
	}
	return ret;
}

// Built-in toString for Object(primitive) wrappers — returns primitive value as string
static ActionVar builtin_prim_wrapper_toString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_STRING;
	ret.str_size = 0;
	ret.data.numeric_value = 0;

	if (this_obj != NULL)
	{
		ASObject* obj = (ASObject*) this_obj;
		ActionVar* prim = getProperty(obj, "valueOf_value", 13);
		if (prim != NULL)
		{
			if (prim->type == ACTION_STACK_VALUE_STRING)
			{
				return *prim;
			}
			else
			{
				// Convert primitive to string
				static char buf[64];
				int len = varToStringBuf(app_context, prim, buf, sizeof(buf));
				u32 u16_len;
				uint16_t* u16_ptr = ascii_to_u16(app_context, buf, len, &u16_len);
				ret.data.numeric_value = (u64) u16_ptr;
				ret.str_size = u16_len;
				return ret;
			}
		}
	}
	ret.data.numeric_value = (u64) u16_object_Object;
	ret.str_size = 15;
	return ret;
}

static ASFunction g_wrapper_valueOf_func;
static ASFunction g_prim_wrapper_toString_func;
static int g_wrapper_funcs_init = 0;

// Get or create the global Object.prototype
static ASObject* getObjectPrototype(SWFAppContext* app_context)
{
	if (g_object_prototype == NULL)
	{
		g_object_prototype = allocObject(app_context, 12);
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

		// Set up the built-in valueOf function (type-2: needs this_obj)
		memset(&g_object_valueOf_func, 0, sizeof(ASFunction));
		strncpy(g_object_valueOf_func.name, "valueOf", 255);
		g_object_valueOf_func.function_type = 2;
		g_object_valueOf_func.param_count = 0;
		g_object_valueOf_func.register_count = 0;
		g_object_valueOf_func.advanced_func = (Function2Ptr) builtin_object_valueOf;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_valueOf_func;

		// Set valueOf property on Object.prototype
		ActionVar vo_var;
		vo_var.type = ACTION_STACK_VALUE_FUNCTION;
		vo_var.str_size = 0;
		vo_var.data.numeric_value = (u64) &g_object_valueOf_func;
		setProperty(app_context, g_object_prototype, "valueOf", 7, &vo_var);

		// Set up the built-in hasOwnProperty function (type-2: needs this_obj + args)
		memset(&g_object_hasOwnProperty_func, 0, sizeof(ASFunction));
		strncpy(g_object_hasOwnProperty_func.name, "hasOwnProperty", 255);
		g_object_hasOwnProperty_func.function_type = 2;
		g_object_hasOwnProperty_func.param_count = 1;
		g_object_hasOwnProperty_func.register_count = 0;
		g_object_hasOwnProperty_func.advanced_func = (Function2Ptr) builtin_object_hasOwnProperty;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_hasOwnProperty_func;

		// Set hasOwnProperty on Object.prototype
		ActionVar hop_var;
		hop_var.type = ACTION_STACK_VALUE_FUNCTION;
		hop_var.str_size = 0;
		hop_var.data.numeric_value = (u64) &g_object_hasOwnProperty_func;
		setProperty(app_context, g_object_prototype, "hasOwnProperty", 14, &hop_var);

		// Set up isPropertyEnumerable function (type-2: needs this_obj + args)
		memset(&g_object_isPropertyEnumerable_func, 0, sizeof(ASFunction));
		strncpy(g_object_isPropertyEnumerable_func.name, "isPropertyEnumerable", 255);
		g_object_isPropertyEnumerable_func.function_type = 2;
		g_object_isPropertyEnumerable_func.param_count = 1;
		g_object_isPropertyEnumerable_func.register_count = 0;
		g_object_isPropertyEnumerable_func.advanced_func = (Function2Ptr) builtin_object_isPropertyEnumerable;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_isPropertyEnumerable_func;

		ActionVar ipe_var;
		ipe_var.type = ACTION_STACK_VALUE_FUNCTION;
		ipe_var.str_size = 0;
		ipe_var.data.numeric_value = (u64) &g_object_isPropertyEnumerable_func;
		setProperty(app_context, g_object_prototype, "isPropertyEnumerable", 20, &ipe_var);

		// Set up isPrototypeOf function (type-2: needs this_obj + args)
		memset(&g_object_isPrototypeOf_func, 0, sizeof(ASFunction));
		strncpy(g_object_isPrototypeOf_func.name, "isPrototypeOf", 255);
		g_object_isPrototypeOf_func.function_type = 2;
		g_object_isPrototypeOf_func.param_count = 1;
		g_object_isPrototypeOf_func.register_count = 0;
		g_object_isPrototypeOf_func.advanced_func = (Function2Ptr) builtin_object_isPrototypeOf;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_isPrototypeOf_func;

		ActionVar ipo_var;
		ipo_var.type = ACTION_STACK_VALUE_FUNCTION;
		ipo_var.str_size = 0;
		ipo_var.data.numeric_value = (u64) &g_object_isPrototypeOf_func;
		setProperty(app_context, g_object_prototype, "isPrototypeOf", 13, &ipo_var);

		// Set up watch function (type-2: needs this_obj + args)
		memset(&g_object_watch_func, 0, sizeof(ASFunction));
		strncpy(g_object_watch_func.name, "watch", 255);
		g_object_watch_func.function_type = 2;
		g_object_watch_func.param_count = 2;
		g_object_watch_func.register_count = 0;
		g_object_watch_func.advanced_func = (Function2Ptr) builtin_object_watch;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_watch_func;
		ActionVar watch_var;
		watch_var.type = ACTION_STACK_VALUE_FUNCTION;
		watch_var.str_size = 0;
		watch_var.data.numeric_value = (u64) &g_object_watch_func;
		setProperty(app_context, g_object_prototype, "watch", 5, &watch_var);

		// Set up unwatch function (type-2: needs this_obj + args)
		memset(&g_object_unwatch_func, 0, sizeof(ASFunction));
		strncpy(g_object_unwatch_func.name, "unwatch", 255);
		g_object_unwatch_func.function_type = 2;
		g_object_unwatch_func.param_count = 1;
		g_object_unwatch_func.register_count = 0;
		g_object_unwatch_func.advanced_func = (Function2Ptr) builtin_object_unwatch;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_object_unwatch_func;
		ActionVar unwatch_var;
		unwatch_var.type = ACTION_STACK_VALUE_FUNCTION;
		unwatch_var.str_size = 0;
		unwatch_var.data.numeric_value = (u64) &g_object_unwatch_func;
		setProperty(app_context, g_object_prototype, "unwatch", 7, &unwatch_var);

		// Mark all built-in Object.prototype properties as non-enumerable (DontEnum)
		for (u32 i = 0; i < g_object_prototype->num_used; i++)
			g_object_prototype->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
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
	// Mark __proto__ as non-enumerable
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (obj->properties[i].name_length == 9 &&
		    strncmp(obj->properties[i].name, "__proto__", 9) == 0)
		{
			obj->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
			break;
		}
	}
}

// Set up arguments object properties: __proto__ = Array.prototype, callee, caller.
// Called after creating the arguments ASArray for any user-defined function call.
static void setupArgumentsProps(SWFAppContext* app_context, ASArray* arr,
                                 ASFunction* callee_func, ASFunction* caller_func)
{
	// Lazily create Array.prototype (shared singleton)
	if (g_array_prototype == NULL)
	{
		g_array_prototype = allocObject(app_context, 4);
		retainObject(g_array_prototype);
		setObjectProto(app_context, g_array_prototype);
	}

	// Allocate props object on the array for non-index properties
	if (arr->props == NULL)
	{
		arr->props = allocObject(app_context, 4);
		retainObject(arr->props);
	}

	// __proto__ = Array.prototype (non-enumerable)
	{
		ActionVar pv = {0};
		pv.type = ACTION_STACK_VALUE_OBJECT;
		pv.data.numeric_value = (u64)g_array_prototype;
		setPropertyWithFlags(app_context, arr->props, "__proto__", 9, &pv, PROPERTY_FLAGS_DONTENUM);
	}

	// callee = the function being called (non-enumerable)
	{
		ActionVar cv = {0};
		cv.type = ACTION_STACK_VALUE_FUNCTION;
		cv.data.numeric_value = (u64)callee_func;
		setPropertyWithFlags(app_context, arr->props, "callee", 6, &cv, PROPERTY_FLAGS_DONTENUM);
	}

	// caller = the function that initiated this call, or null (non-enumerable)
	{
		ActionVar cr = {0};
		if (caller_func != NULL)
		{
			cr.type = ACTION_STACK_VALUE_FUNCTION;
			cr.data.numeric_value = (u64)caller_func;
		}
		else
		{
			cr.type = ACTION_STACK_VALUE_NULL;
		}
		setPropertyWithFlags(app_context, arr->props, "caller", 6, &cr, PROPERTY_FLAGS_DONTENUM);
	}
}

// Public wrapper for setupArgumentsProps — called from recompiler-generated code
// when DefineFunction2 has the preload_arguments flag. Uses the global function
// context (g_current_executing_func = callee, g_prev_executing_func = caller).
void swf_setup_arguments_props(SWFAppContext* app_context, ASArray* arr)
{
	setupArgumentsProps(app_context, arr, g_current_executing_func, g_prev_executing_func);
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
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = NULL;
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

// Invoke an addProperty getter with a specific this_obj
static ActionVar invokePropertyGetter(SWFAppContext* app_context, ASFunction* func, void* this_obj)
{
	ActionVar undef = {0};
	undef.type = ACTION_STACK_VALUE_UNDEFINED;
	if (func == NULL || g_execution_halted) return undef;

	g_special_depth++;
	if (g_special_depth >= MAX_SPECIAL_DEPTH)
	{
		g_special_depth--;
		return undef;
	}

	ActionVar result;
	if (func->function_type == 2)
	{
		ActionVar* registers = NULL;
		if (func->register_count > 0)
			registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));

		ASObject* local_scope = allocObject(app_context, 8);
		if (scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = local_scope;
		}

		result = func->advanced_func(app_context, NULL, 0, registers, this_obj);

		if (scope_depth > 0) scope_depth--;
		releaseObject(app_context, local_scope);
		if (registers != NULL) FREE(registers);
	}
	else
	{
		result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
	}

	g_special_depth--;
	return result;
}

// Invoke an addProperty setter with a specific this_obj and value argument
static void invokePropertySetter(SWFAppContext* app_context, ASFunction* func, void* this_obj, ActionVar* value)
{
	if (func == NULL || g_execution_halted) return;

	g_special_depth++;
	if (g_special_depth >= MAX_SPECIAL_DEPTH)
	{
		g_special_depth--;
		return;
	}

	if (func->function_type == 2)
	{
		ActionVar* registers = NULL;
		if (func->register_count > 0)
			registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));

		ASObject* local_scope = allocObject(app_context, 8);
		if (scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = local_scope;
		}

		func->advanced_func(app_context, value, 1, registers, this_obj);

		if (scope_depth > 0) scope_depth--;
		releaseObject(app_context, local_scope);
		if (registers != NULL) FREE(registers);
	}
	else
	{
		if (value != NULL) pushVar(app_context, value);
		((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
	}

	g_special_depth--;
}

// ============================================================================
// Native toString implementations for flash.geom classes
// ============================================================================

static ActionVar colorTransformToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	ActionVar result = {0};
	result.type = ACTION_STACK_VALUE_STRING;
	result.data.numeric_value = (u64) u16_default_colortransform;
	result.str_size = 130;
	return result;
}

// Forward declarations needed by matrixToString/rectangleToString/createTransformObject
static int varToStringBufFull(SWFAppContext* app_context, ActionVar* v, char* buf, int buf_size);
// getPropertyWithPrototype is non-static (declared in object.h / defined in object.c)
static inline ActionVar makeF64(double d);
static ActionVar ctToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);
// Forward declarations for functions used by transform helpers/getters before their definitions
static double propToDouble(ASObject* obj, const char* name, u32 name_len);
static ASObject* createRectObj(SWFAppContext* app_context, ActionVar* x, ActionVar* y, ActionVar* w, ActionVar* h);
static float normalizeRotation(float r);
static void setAddProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 nlen, ASFunction* getter, ASFunction* setter);
static void initGeomPrototypes(SWFAppContext* app_context);
static void initColorTransformPrototype(SWFAppContext* app_context);

static ActionVar matrixToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	double a=1, b=0, c=0, d=1, tx=0, ty=0;
	ActionVar* av;
	av = obj ? getPropertyWithPrototype(obj, "a", 1) : NULL;  if (av) a  = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "b", 1) : NULL;  if (av) b  = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "c", 1) : NULL;  if (av) c  = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "d", 1) : NULL;  if (av) d  = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "tx", 2) : NULL; if (av) tx = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "ty", 2) : NULL; if (av) ty = varToDoubleSimple(av);
	char sa[64], sb[64], sc[64], sd[64], stx[64], sty[64];
	ActionVar fa = makeF64(a), fb = makeF64(b), fc = makeF64(c), fd = makeF64(d);
	ActionVar ftx = makeF64(tx), fty = makeF64(ty);
	varToStringBufFull(app_context, &fa, sa, sizeof(sa));
	varToStringBufFull(app_context, &fb, sb, sizeof(sb));
	varToStringBufFull(app_context, &fc, sc, sizeof(sc));
	varToStringBufFull(app_context, &fd, sd, sizeof(sd));
	varToStringBufFull(app_context, &ftx, stx, sizeof(stx));
	varToStringBufFull(app_context, &fty, sty, sizeof(sty));
	char buf[512];
	int len = snprintf(buf, sizeof(buf), "(a=%s, b=%s, c=%s, d=%s, tx=%s, ty=%s)", sa, sb, sc, sd, stx, sty);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

static ActionVar rectangleToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	double x=0, y=0, w=0, h=0;
	ActionVar* av;
	av = obj ? getPropertyWithPrototype(obj, "x", 1) : NULL;      if (av) x = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "y", 1) : NULL;      if (av) y = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "width", 5) : NULL;  if (av) w = varToDoubleSimple(av);
	av = obj ? getPropertyWithPrototype(obj, "height", 6) : NULL; if (av) h = varToDoubleSimple(av);
	char sx[64], sy[64], sw[64], sh[64];
	ActionVar fx = makeF64(x), fy = makeF64(y), fw = makeF64(w), fh = makeF64(h);
	varToStringBufFull(app_context, &fx, sx, sizeof(sx));
	varToStringBufFull(app_context, &fy, sy, sizeof(sy));
	varToStringBufFull(app_context, &fw, sw, sizeof(sw));
	varToStringBufFull(app_context, &fh, sh, sizeof(sh));
	char buf[256];
	int len = snprintf(buf, sizeof(buf), "(x=%s, y=%s, w=%s, h=%s)", sx, sy, sw, sh);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

// Helper: set a toString function on an ASObject using a native Function2Ptr
static void setNativeToString(SWFAppContext* app_context, ASObject* obj, Function2Ptr func)
{
	ASFunction* f = (ASFunction*) calloc(1, sizeof(ASFunction));
	strncpy(f->name, "toString", 255);
	f->function_type = 2;
	f->advanced_func = func;
	ActionVar fv = {0};
	fv.type = ACTION_STACK_VALUE_FUNCTION;
	fv.data.numeric_value = (u64) f;
	setProperty(app_context, obj, "toString", 8, &fv);
}

// Forward declarations for Transform getter/setter functions (defined after varToStringBufFull)
static ActionVar transformMatrixGetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformMatrixSetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformCTGetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformCTSetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformConcatMatrixGetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformConcatCTGetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);
static ActionVar transformPixelBoundsGetter(SWFAppContext*, ActionVar*, u32, ActionVar*, void*);

// Global ASFunctions for Transform addProperty getters/setters (lazy initialized)
static int g_transform_funcs_init = 0;
static ASFunction g_transform_matrix_getter_func;
static ASFunction g_transform_matrix_setter_func;
static ASFunction g_transform_ct_getter_func;
static ASFunction g_transform_ct_setter_func;
static ASFunction g_transform_concat_mat_getter_func;
static ASFunction g_transform_concat_ct_getter_func;
static ASFunction g_transform_pix_bounds_getter_func;

static void initTransformFuncs(void)
{
	if (g_transform_funcs_init) return;
	g_transform_funcs_init = 1;
#define INIT_TRANSFORM_FUNC(var, func_ptr, fname) \
	memset(&(var), 0, sizeof(ASFunction)); \
	strncpy((var).name, fname, 255); \
	(var).function_type = 2; \
	(var).advanced_func = (Function2Ptr)(func_ptr);
	INIT_TRANSFORM_FUNC(g_transform_matrix_getter_func,      transformMatrixGetter,       "get matrix")
	INIT_TRANSFORM_FUNC(g_transform_matrix_setter_func,      transformMatrixSetter,       "set matrix")
	INIT_TRANSFORM_FUNC(g_transform_ct_getter_func,          transformCTGetter,           "get colorTransform")
	INIT_TRANSFORM_FUNC(g_transform_ct_setter_func,          transformCTSetter,           "set colorTransform")
	INIT_TRANSFORM_FUNC(g_transform_concat_mat_getter_func,  transformConcatMatrixGetter, "get concatenatedMatrix")
	INIT_TRANSFORM_FUNC(g_transform_concat_ct_getter_func,   transformConcatCTGetter,     "get concatenatedColorTransform")
	INIT_TRANSFORM_FUNC(g_transform_pix_bounds_getter_func,  transformPixelBoundsGetter,  "get pixelBounds")
#undef INIT_TRANSFORM_FUNC
}

// Create a flash.geom.Transform object for a MovieClip with live data via addProperty getters.
static ASObject* createTransformObject(SWFAppContext* app_context, MovieClip* mc)
{
	initTransformFuncs();

	ASObject* transform = allocObject(app_context, 8);
	setObjectProto(app_context, transform);

	// Store MC reference as "__mc__" property (MOVIECLIP type)
	ActionVar mc_val = {0};
	mc_val.type = ACTION_STACK_VALUE_MOVIECLIP;
	mc_val.data.numeric_value = (u64) mc;
	setProperty(app_context, transform, "__mc__", 6, &mc_val);

	// Set up addProperty virtual getters/setters for each property
	setAddProperty(app_context, transform, "matrix",                    6,  &g_transform_matrix_getter_func,      &g_transform_matrix_setter_func);
	setAddProperty(app_context, transform, "colorTransform",           14,  &g_transform_ct_getter_func,          &g_transform_ct_setter_func);
	setAddProperty(app_context, transform, "concatenatedMatrix",       18,  &g_transform_concat_mat_getter_func,  NULL);
	setAddProperty(app_context, transform, "concatenatedColorTransform", 26, &g_transform_concat_ct_getter_func,  NULL);
	setAddProperty(app_context, transform, "pixelBounds",              11,  &g_transform_pix_bounds_getter_func,  NULL);

	return transform;
}

// ============================================================================
// Geometry class implementations (Point, Matrix, Rectangle)
// ============================================================================

// Helper: convert ActionVar to string in buf, calling toString for objects
static int varToStringBufFull(SWFAppContext* app_context, ActionVar* v, char* buf, int buf_size)
{
	if (v == NULL) { buf[0] = '\0'; return 0; }
	if (v->type == ACTION_STACK_VALUE_OBJECT && v->data.numeric_value != 0)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, v, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* u16 = varGetU16Ptr(&ts);
			if (u16 && ts.str_size > 0) return u16_to_utf8(u16, ts.str_size, buf, buf_size);
		}
		return snprintf(buf, buf_size, "[object Object]");
	}
	// Normalize -0 → 0 for float/double
	if (v->type == ACTION_STACK_VALUE_F64) {
		double d = VAL(double, &v->data.numeric_value);
		if (d == 0.0 && signbit(d)) return snprintf(buf, buf_size, "0");
	} else if (v->type == ACTION_STACK_VALUE_F32) {
		float f = VAL(float, &v->data.numeric_value);
		if (f == 0.0f && signbit(f)) return snprintf(buf, buf_size, "0");
	}
	return varToStringBuf(app_context, v, buf, buf_size);
}

// ============================================================================
// Transform helper functions (NO_GRAPHICS only) and getter/setter implementations
// ============================================================================

#ifdef NO_GRAPHICS
// Root MovieClip CT globals (root has no ng_display entry)
static double g_root_cx_ra = 100.0, g_root_cx_ga = 100.0;
static double g_root_cx_ba = 100.0, g_root_cx_aa = 100.0;
static double g_root_cx_rb = 0.0,   g_root_cx_gb = 0.0;
static double g_root_cx_bb = 0.0,   g_root_cx_ab = 0.0;

// Get ng_display entry index for a MC. Returns (size_t)-1 for root or not found.
static size_t getDisplayEntryIdxForMC(MovieClip* mc)
{
	extern MovieClip root_movieclip;
	if (mc == NULL || mc == &root_movieclip) return (size_t)-1;
	size_t parent_idx = getDisplayEntryIdxForMC(mc->parent);
	return ng_findDisplayEntryIdxWithParent(mc->name, parent_idx);
}

// Get local matrix (in pixels) for a MC.
// Uses ng_getMatrixFromEntry as the base (from transform_data), then overlays any
// AS-set fields (xscale/yscale/rotation via as_set_flags bits 4/8/16, tx/ty via bits 1/2).
static void getLocalMatrixForMC(MovieClip* mc,
	double* a, double* b, double* c, double* d, double* tx, double* ty)
{
	// Try to get base matrix from ng_display (transform_data)
	size_t idx = getDisplayEntryIdxForMC(mc);
	double ba = 1.0, bb = 0.0, bc = 0.0, bd = 1.0, btx = 0.0, bty = 0.0;
	int has_base = (idx != (size_t)-1) && ng_getMatrixFromEntry(idx, &ba, &bb, &bc, &bd, &btx, &bty);
	if (!has_base) {
		// Fall back to AS-set values (or defaults)
		double xs = (double)mc->xscale / 100.0;
		double ys = (double)mc->yscale / 100.0;
		double rot = (double)mc->rotation * 3.14159265358979323846 / 180.0;
		double cr = cos(rot), sr = sin(rot);
		ba = xs*cr; bb = xs*sr; bc = -(ys*sr); bd = ys*cr;
		btx = (double)mc->x; bty = (double)mc->y;
	}
	// Apply AS overrides for scale/rotation (bits 4|8|16) and translation (bits 1|2)
	if (mc->as_set_flags & (4|8|16)) {
		double xs = (double)mc->xscale / 100.0;
		double ys = (double)mc->yscale / 100.0;
		double rot = (double)mc->rotation * 3.14159265358979323846 / 180.0;
		double cr = cos(rot), sr = sin(rot);
		ba = xs*cr; bb = xs*sr; bc = -(ys*sr); bd = ys*cr;
	}
	if (mc->as_set_flags & 1) btx = (double)mc->x;
	if (mc->as_set_flags & 2) bty = (double)mc->y;
	*a = ba; *b = bb; *c = bc; *d = bd; *tx = btx; *ty = bty;
}

// Get local CT as raw Fixed8 int16 values.
static void getLocalCTRaw(MovieClip* mc,
	s16* ra, s16* ga, s16* ba, s16* aa,
	s16* rb, s16* gb, s16* bb, s16* ab)
{
	extern MovieClip root_movieclip;
	if (mc == &root_movieclip) {
		*ra = (s16)lround(g_root_cx_ra * 256.0 / 100.0);
		*ga = (s16)lround(g_root_cx_ga * 256.0 / 100.0);
		*ba = (s16)lround(g_root_cx_ba * 256.0 / 100.0);
		*aa = (s16)lround(g_root_cx_aa * 256.0 / 100.0);
		*rb = (s16)lround(g_root_cx_rb);
		*gb = (s16)lround(g_root_cx_gb);
		*bb = (s16)lround(g_root_cx_bb);
		*ab = (s16)lround(g_root_cx_ab);
		return;
	}
	size_t idx = getDisplayEntryIdxForMC(mc);
	if (idx == (size_t)-1) {
		*ra = 256; *ga = 256; *ba = 256; *aa = 256;
		*rb = 0;   *gb = 0;   *bb = 0;   *ab = 0;
		return;
	}
	double dra, dga, dba, daa, drb, dgb, dbb, dab;
	ng_getCTFromEntry(idx, &dra, &dga, &dba, &daa, &drb, &dgb, &dbb, &dab);
	*ra = (s16)lround(dra * 256.0 / 100.0);
	*ga = (s16)lround(dga * 256.0 / 100.0);
	*ba = (s16)lround(dba * 256.0 / 100.0);
	*aa = (s16)lround(daa * 256.0 / 100.0);
	*rb = (s16)lround(drb);
	*gb = (s16)lround(dgb);
	*bb = (s16)lround(dbb);
	*ab = (s16)lround(dab);
}

// Set local CT from raw Fixed8 int16 values.
static void setLocalCTRaw(MovieClip* mc,
	s16 ra, s16 ga, s16 ba, s16 aa,
	s16 rb, s16 gb, s16 bb, s16 ab)
{
	extern MovieClip root_movieclip;
	if (mc == &root_movieclip) {
		g_root_cx_ra = (double)ra * 100.0 / 256.0;
		g_root_cx_ga = (double)ga * 100.0 / 256.0;
		g_root_cx_ba = (double)ba * 100.0 / 256.0;
		g_root_cx_aa = (double)aa * 100.0 / 256.0;
		g_root_cx_rb = (double)rb;
		g_root_cx_gb = (double)gb;
		g_root_cx_bb = (double)bb;
		g_root_cx_ab = (double)ab;
		return;
	}
	size_t idx = getDisplayEntryIdxForMC(mc);
	if (idx == (size_t)-1) return;
	ng_setCTOnEntry(idx,
		(double)ra * 100.0 / 256.0,
		(double)ga * 100.0 / 256.0,
		(double)ba * 100.0 / 256.0,
		(double)aa * 100.0 / 256.0,
		(double)rb, (double)gb, (double)bb, (double)ab);
}

// Extract CT raw Fixed8 values from a ColorTransform ASObject.
static void ctObjToRaw(ASObject* ct_obj,
	s16* ra, s16* ga, s16* ba, s16* aa,
	s16* rb, s16* gb, s16* bb, s16* ab)
{
	double rm = propToDouble(ct_obj, "redMultiplier",   13);
	double gm = propToDouble(ct_obj, "greenMultiplier", 15);
	double bm = propToDouble(ct_obj, "blueMultiplier",  14);
	double am = propToDouble(ct_obj, "alphaMultiplier", 15);
	double ro = propToDouble(ct_obj, "redOffset",        9);
	double go = propToDouble(ct_obj, "greenOffset",     11);
	double bo = propToDouble(ct_obj, "blueOffset",      10);
	double ao = propToDouble(ct_obj, "alphaOffset",     11);
	*ra = isnan(rm) ? 256 : (s16)lround(rm * 256.0);
	*ga = isnan(gm) ? 256 : (s16)lround(gm * 256.0);
	*ba = isnan(bm) ? 256 : (s16)lround(bm * 256.0);
	*aa = isnan(am) ? 256 : (s16)lround(am * 256.0);
	*rb = isnan(ro) ? 0 : (s16)lround(ro);
	*gb = isnan(go) ? 0 : (s16)lround(go);
	*bb = isnan(bo) ? 0 : (s16)lround(bo);
	*ab = isnan(ao) ? 0 : (s16)lround(ao);
}

// 2D affine composition: result = outer * inner (outer applied after inner).
static void composeMat2D(
	double oa, double ob, double oc, double od, double otx, double oty,
	double ia, double ib, double ic, double id, double itx, double ity,
	double* ra, double* rb, double* rc, double* rd, double* rtx, double* rty)
{
	*ra  = oa*ia + oc*ib;
	*rb  = ob*ia + od*ib;
	*rc  = oa*ic + oc*id;
	*rd  = ob*ic + od*id;
	*rtx = oa*itx + oc*ity + otx;
	*rty = ob*itx + od*ity + oty;
}

// Get concatenated matrix for a MC (from root down to MC).
static void getConcatMatrixForMC(MovieClip* mc,
	double* a, double* b, double* c, double* d, double* tx, double* ty)
{
	MovieClip* chain[32];
	int depth = 0;
	MovieClip* cur = mc;
	while (cur != NULL && depth < 32) {
		chain[depth++] = cur;
		cur = cur->parent;
	}
	getLocalMatrixForMC(chain[0], a, b, c, d, tx, ty);
	for (int i = 1; i < depth; i++) {
		double oa, ob, oc, od, otx, oty;
		getLocalMatrixForMC(chain[i], &oa, &ob, &oc, &od, &otx, &oty);
		double ra, rb, rc, rd, rtx, rty;
		composeMat2D(oa, ob, oc, od, otx, oty, *a, *b, *c, *d, *tx, *ty,
		             &ra, &rb, &rc, &rd, &rtx, &rty);
		*a = ra; *b = rb; *c = rc; *d = rd; *tx = rtx; *ty = rty;
	}
}

// Compose two CTs in raw Fixed8 (outer applied after inner).
static void composeCTRaw(
	s16 o_ra, s16 o_ga, s16 o_ba, s16 o_aa, s16 o_rb, s16 o_gb, s16 o_bb, s16 o_ab,
	s16 i_ra, s16 i_ga, s16 i_ba, s16 i_aa, s16 i_rb, s16 i_gb, s16 i_bb, s16 i_ab,
	s16* r_ra, s16* r_ga, s16* r_ba, s16* r_aa,
	s16* r_rb, s16* r_gb, s16* r_bb, s16* r_ab)
{
	*r_ra = (s16)(((s32)o_ra * (s32)i_ra) >> 8);
	*r_ga = (s16)(((s32)o_ga * (s32)i_ga) >> 8);
	*r_ba = (s16)(((s32)o_ba * (s32)i_ba) >> 8);
	*r_aa = (s16)(((s32)o_aa * (s32)i_aa) >> 8);
	*r_rb = (s16)(o_rb + (((s32)o_ra * (s32)i_rb) >> 8));
	*r_gb = (s16)(o_gb + (((s32)o_ga * (s32)i_gb) >> 8));
	*r_bb = (s16)(o_bb + (((s32)o_ba * (s32)i_bb) >> 8));
	*r_ab = (s16)(o_ab + (((s32)o_aa * (s32)i_ab) >> 8));
}

// Get concatenated CT for a MC (innermost first, compose outward).
static void getConcatCTForMC(MovieClip* mc,
	s16* ra, s16* ga, s16* ba, s16* aa,
	s16* rb, s16* gb, s16* bb, s16* ab)
{
	MovieClip* chain[32];
	int depth = 0;
	MovieClip* cur = mc;
	while (cur != NULL && depth < 32) {
		chain[depth++] = cur;
		cur = cur->parent;
	}
	getLocalCTRaw(chain[0], ra, ga, ba, aa, rb, gb, bb, ab);
	for (int i = 1; i < depth; i++) {
		s16 ora, oga, oba, oaa, orb, ogb, obb, oab;
		getLocalCTRaw(chain[i], &ora, &oga, &oba, &oaa, &orb, &ogb, &obb, &oab);
		s16 rra, rga, rba, raa, rrb, rgb, rbb, rab;
		composeCTRaw(ora, oga, oba, oaa, orb, ogb, obb, oab,
		             *ra, *ga, *ba, *aa, *rb, *gb, *bb, *ab,
		             &rra, &rga, &rba, &raa, &rrb, &rgb, &rbb, &rab);
		*ra = rra; *ga = rga; *ba = rba; *aa = raa;
		*rb = rrb; *gb = rgb; *bb = rbb; *ab = rab;
	}
}

// Create a Matrix ASObject from 2D affine components.
static ASObject* makeMatrixObject(SWFAppContext* app_context,
	double a, double b, double c, double d, double tx, double ty)
{
	initGeomPrototypes(app_context);
	ASObject* obj = allocObject(app_context, 8);
	if (g_matrix_prototype != NULL) {
		ActionVar proto_var = {0};
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.data.numeric_value = (u64) g_matrix_prototype;
		setProperty(app_context, obj, "__proto__", 9, &proto_var);
	}
	ActionVar v;
	v = makeF64(a);  setProperty(app_context, obj, "a",  1, &v);
	v = makeF64(b);  setProperty(app_context, obj, "b",  1, &v);
	v = makeF64(c);  setProperty(app_context, obj, "c",  1, &v);
	v = makeF64(d);  setProperty(app_context, obj, "d",  1, &v);
	v = makeF64(tx); setProperty(app_context, obj, "tx", 2, &v);
	v = makeF64(ty); setProperty(app_context, obj, "ty", 2, &v);
	return obj;
}

// Create a CT ASObject from raw Fixed8 values.
static ASObject* makeCTObject(SWFAppContext* app_context,
	s16 ra, s16 ga, s16 ba, s16 aa,
	s16 rb, s16 gb, s16 bb, s16 ab)
{
	initColorTransformPrototype(app_context);
	ASObject* obj = allocObject(app_context, 10);
	if (g_color_transform_prototype != NULL) {
		ActionVar proto_var = {0};
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.data.numeric_value = (u64) g_color_transform_prototype;
		setProperty(app_context, obj, "__proto__", 9, &proto_var);
	}
	ActionVar v;
	v = makeF64((double)ra / 256.0); setProperty(app_context, obj, "redMultiplier",   13, &v);
	v = makeF64((double)ga / 256.0); setProperty(app_context, obj, "greenMultiplier", 15, &v);
	v = makeF64((double)ba / 256.0); setProperty(app_context, obj, "blueMultiplier",  14, &v);
	v = makeF64((double)aa / 256.0); setProperty(app_context, obj, "alphaMultiplier", 15, &v);
	v = makeF64((double)rb);         setProperty(app_context, obj, "redOffset",        9, &v);
	v = makeF64((double)gb);         setProperty(app_context, obj, "greenOffset",     11, &v);
	v = makeF64((double)bb);         setProperty(app_context, obj, "blueOffset",      10, &v);
	v = makeF64((double)ab);         setProperty(app_context, obj, "alphaOffset",     11, &v);
	return obj;
}
#endif // NO_GRAPHICS

static ActionVar transformMatrixGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj) return r;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return r;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return r;
#ifdef NO_GRAPHICS
	double a, b, c, d, tx, ty;
	getLocalMatrixForMC(mc, &a, &b, &c, &d, &tx, &ty);
	ASObject* mat = makeMatrixObject(app_context, a, b, c, d, tx, ty);
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) mat;
#else
	(void)app_context;
#endif
	return r;
}

static ActionVar transformMatrixSetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj || arg_count < 1) return undef;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return undef;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return undef;
	if (args[0].type != ACTION_STACK_VALUE_OBJECT || args[0].data.numeric_value == 0) return undef;
	ASObject* mat_obj = (ASObject*) args[0].data.numeric_value;
	if (!getProperty(mat_obj, "a", 1)) return undef;
#ifdef NO_GRAPHICS
	double a  = propToDouble(mat_obj, "a",  1);
	double b  = propToDouble(mat_obj, "b",  1);
	double c  = propToDouble(mat_obj, "c",  1);
	double d  = propToDouble(mat_obj, "d",  1);
	double tx = propToDouble(mat_obj, "tx", 2);
	double ty = propToDouble(mat_obj, "ty", 2);
	if (isnan(a))  a  = 0.0; if (isnan(b))  b  = 0.0;
	if (isnan(c))  c  = 0.0; if (isnan(d))  d  = 0.0;
	if (isnan(tx)) tx = 0.0; if (isnan(ty)) ty = 0.0;
	mc->x = (float)tx;
	mc->y = (float)ty;
	double xs = sqrt(a*a + b*b);
	double ys = sqrt(c*c + d*d);
	double rot_deg = atan2(b, a) * 180.0 / 3.14159265358979323846;
	mc->xscale = (float)(xs * 100.0);
	mc->yscale = (float)(ys * 100.0);
	mc->rotation = normalizeRotation((float)rot_deg);
	mc->as_set_flags |= (1|2|4|8|16);
#endif
	return undef;
}

static ActionVar transformCTGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj) return r;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return r;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return r;
#ifdef NO_GRAPHICS
	s16 ra, ga, ba, aa, rb, gb, bb, ab;
	getLocalCTRaw(mc, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab);
	ASObject* ct = makeCTObject(app_context, ra, ga, ba, aa, rb, gb, bb, ab);
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) ct;
#else
	(void)app_context;
#endif
	return r;
}

static ActionVar transformCTSetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj || arg_count < 1) return undef;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return undef;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return undef;
	if (args[0].type != ACTION_STACK_VALUE_OBJECT || args[0].data.numeric_value == 0) return undef;
	ASObject* ct_obj = (ASObject*) args[0].data.numeric_value;
	if (!getProperty(ct_obj, "redMultiplier", 13)) return undef;
#ifdef NO_GRAPHICS
	s16 ra, ga, ba, aa, rb, gb, bb, ab;
	ctObjToRaw(ct_obj, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab);
	setLocalCTRaw(mc, ra, ga, ba, aa, rb, gb, bb, ab);
#endif
	return undef;
}

static ActionVar transformConcatMatrixGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj) return r;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return r;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return r;
#ifdef NO_GRAPHICS
	double a, b, c, d, tx, ty;
	getConcatMatrixForMC(mc, &a, &b, &c, &d, &tx, &ty);
	ASObject* mat = makeMatrixObject(app_context, a, b, c, d, tx, ty);
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) mat;
#else
	(void)app_context;
#endif
	return r;
}

static ActionVar transformConcatCTGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj) return r;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return r;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return r;
#ifdef NO_GRAPHICS
	s16 ra, ga, ba, aa, rb, gb, bb, ab;
	getConcatCTForMC(mc, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab);
	ASObject* ct = makeCTObject(app_context, ra, ga, ba, aa, rb, gb, bb, ab);
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) ct;
#else
	(void)app_context;
#endif
	return r;
}

static ActionVar transformPixelBoundsGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* tobj = (ASObject*) this_obj;
	if (!tobj) return r;
	ActionVar* mc_ref = getProperty(tobj, "__mc__", 6);
	if (!mc_ref || mc_ref->type != ACTION_STACK_VALUE_MOVIECLIP) return r;
	MovieClip* mc = (MovieClip*) mc_ref->data.numeric_value;
	if (!mc) return r;
#ifdef NO_GRAPHICS
	size_t entry_idx = getDisplayEntryIdxForMC(mc);
	float lxmin, lxmax, lymin, lymax;
	if (!ng_getDisplayEntryBounds(entry_idx, &lxmin, &lxmax, &lymin, &lymax)) {
		// Empty clip: return (x=0, y=0, w=0, h=0) rectangle
		ActionVar zero = makeF64(0.0);
		ASObject* rect = createRectObj(app_context, &zero, &zero, &zero, &zero);
		r.type = ACTION_STACK_VALUE_OBJECT;
		r.data.numeric_value = (u64) rect;
		return r;
	}
	double ca, cb, cc, cd, ctx, cty;
	getConcatMatrixForMC(mc, &ca, &cb, &cc, &cd, &ctx, &cty);
	double lx0 = (double)lxmin, lx1 = (double)lxmax;
	double ly0 = (double)lymin, ly1 = (double)lymax;
	double cx0 = ca*lx0 + cc*ly0 + ctx, cy0 = cb*lx0 + cd*ly0 + cty;
	double cx1 = ca*lx1 + cc*ly0 + ctx, cy1 = cb*lx1 + cd*ly0 + cty;
	double cx2 = ca*lx0 + cc*ly1 + ctx, cy2 = cb*lx0 + cd*ly1 + cty;
	double cx3 = ca*lx1 + cc*ly1 + ctx, cy3 = cb*lx1 + cd*ly1 + cty;
	double pxmin = cx0, pxmax = cx0, pymin = cy0, pymax = cy0;
	if (cx1 < pxmin) pxmin = cx1; if (cx1 > pxmax) pxmax = cx1;
	if (cx2 < pxmin) pxmin = cx2; if (cx2 > pxmax) pxmax = cx2;
	if (cx3 < pxmin) pxmin = cx3; if (cx3 > pxmax) pxmax = cx3;
	if (cy1 < pymin) pymin = cy1; if (cy1 > pymax) pymax = cy1;
	if (cy2 < pymin) pymin = cy2; if (cy2 > pymax) pymax = cy2;
	if (cy3 < pymin) pymin = cy3; if (cy3 > pymax) pymax = cy3;
	ActionVar rx = makeF64(pxmin), ry = makeF64(pymin);
	ActionVar rw = makeF64(pxmax - pxmin), rh = makeF64(pymax - pymin);
	ASObject* rect = createRectObj(app_context, &rx, &ry, &rw, &rh);
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) rect;
#else
	(void)app_context;
#endif
	return r;
}

// Helper: read a named property from an object ActionVar (returns NULL if not object)
static ActionVar* geomGetProp(ActionVar* obj_var, const char* name, u32 len)
{
	if (obj_var == NULL) return NULL;
	if (obj_var->type == ACTION_STACK_VALUE_OBJECT && obj_var->data.numeric_value != 0)
		return getProperty((ASObject*)obj_var->data.numeric_value, name, len);
	return NULL;
}

// Helper: read a property as double, returning NAN if the property is missing
// (unlike varToDoubleSimple(NULL) which returns 0.0)
static double propToDouble(ASObject* obj, const char* name, u32 name_len)
{
	ActionVar* prop = getProperty(obj, name, name_len);
	if (prop == NULL) return NAN;
	return varToDoubleSimple(prop);
}

// Helper: create a Point object with x and y properties
static ASObject* createPointObj(SWFAppContext* app_context, ActionVar* x_val, ActionVar* y_val)
{
	ASObject* obj = allocObject(app_context, 4);
	ActionVar proto_var = {0};
	proto_var.type = ACTION_STACK_VALUE_OBJECT;
	proto_var.data.numeric_value = (u64) g_point_prototype;
	setProperty(app_context, obj, "__proto__", 9, &proto_var);
	if (x_val) setProperty(app_context, obj, "x", 1, x_val);
	if (y_val) setProperty(app_context, obj, "y", 1, y_val);
	return obj;
}

// Helper: create a Point object from two doubles
static ASObject* createPointObjF64(SWFAppContext* app_context, double x, double y)
{
	ActionVar xv = {0}, yv = {0};
	xv.type = ACTION_STACK_VALUE_F64;
	VAL(double, &xv.data.numeric_value) = x;
	yv.type = ACTION_STACK_VALUE_F64;
	VAL(double, &yv.data.numeric_value) = y;
	return createPointObj(app_context, &xv, &yv);
}

// Helper: create a Rectangle object with x, y, width, height properties
static ASObject* createRectObj(SWFAppContext* app_context, ActionVar* x, ActionVar* y, ActionVar* w, ActionVar* h)
{
	initGeomPrototypes(app_context);
	ASObject* obj = allocObject(app_context, 6);
	ActionVar proto_var = {0};
	proto_var.type = ACTION_STACK_VALUE_OBJECT;
	proto_var.data.numeric_value = (u64) g_rect_prototype;
	setProperty(app_context, obj, "__proto__", 9, &proto_var);
	if (x) setProperty(app_context, obj, "x", 1, x);
	if (y) setProperty(app_context, obj, "y", 1, y);
	if (w) setProperty(app_context, obj, "width", 5, w);
	if (h) setProperty(app_context, obj, "height", 6, h);
	return obj;
}

// Helper: make an F64 ActionVar
static inline ActionVar makeF64(double d)
{
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_F64;
	VAL(double, &v.data.numeric_value) = d;
	return v;
}

// Helper: register a method on a prototype
static void registerGeomMethod(ASFunction* func, const char* name, Function2Ptr impl, SWFAppContext* app_context, ASObject* proto)
{
	memset(func, 0, sizeof(ASFunction));
	strncpy(func->name, name, 255);
	func->function_type = 2;
	func->param_count = 0;
	func->advanced_func = impl;
	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = func;
	ActionVar fv = {0};
	fv.type = ACTION_STACK_VALUE_FUNCTION;
	VAL(u64, &fv.data.numeric_value) = (u64)func;
	setProperty(app_context, proto, name, (u32)strlen(name), &fv);
}

// --- Point methods ---

static ActionVar pointConstructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	if (arg_count == 0) {
		ActionVar zero = makeF64(0.0);
		setProperty(app_context, obj, "x", 1, &zero);
		setProperty(app_context, obj, "y", 1, &zero);
	} else if (arg_count == 1) {
		setProperty(app_context, obj, "x", 1, &args[0]);
		ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
		setProperty(app_context, obj, "y", 1, &undef);
	} else {
		setProperty(app_context, obj, "x", 1, &args[0]);
		setProperty(app_context, obj, "y", 1, &args[1]);
	}

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar pointToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	char buf[512];
	char xbuf[128], ybuf[128];
	ActionVar* xv = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* yv = obj ? getProperty(obj, "y", 1) : NULL;
	varToStringBufFull(app_context, xv, xbuf, sizeof(xbuf));
	varToStringBufFull(app_context, yv, ybuf, sizeof(ybuf));
	int len = snprintf(buf, sizeof(buf), "(x=%s, y=%s)", xbuf, ybuf);

	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

static ActionVar pointAdd(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar* tx = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* ty = obj ? getProperty(obj, "y", 1) : NULL;
	double sx = varToDoubleSimple(tx), sy = varToDoubleSimple(ty);

	// Read pt.x and pt.y from argument — non-object → NaN
	double ox = NAN, oy = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		ox = propToDouble(pt, "x", 1);
		oy = propToDouble(pt, "y", 1);
	}

	ASObject* result = createPointObjF64(app_context, sx + ox, sy + oy);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar pointSubtract(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar* tx = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* ty = obj ? getProperty(obj, "y", 1) : NULL;
	double sx = varToDoubleSimple(tx), sy = varToDoubleSimple(ty);

	// Read pt.x and pt.y from argument — non-object → NaN
	double ox = NAN, oy = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		ox = propToDouble(pt, "x", 1);
		oy = propToDouble(pt, "y", 1);
	}

	ASObject* result = createPointObjF64(app_context, sx - ox, sy - oy);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar pointEquals(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = 0;
	if (obj == NULL || arg_count == 0) return r;

	ActionVar* tx = getProperty(obj, "x", 1);
	ActionVar* ty = getProperty(obj, "y", 1);
	double sx = varToDoubleSimple(tx), sy = varToDoubleSimple(ty);

	if (args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		ActionVar* px = getProperty(pt, "x", 1);
		ActionVar* py = getProperty(pt, "y", 1);
		double ox = varToDoubleSimple(px), oy = varToDoubleSimple(py);
		if (sx == ox && sy == oy) r.data.numeric_value = 1;
	}
	return r;
}

static ActionVar pointClone(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar* xv = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* yv = obj ? getProperty(obj, "y", 1) : NULL;
	ASObject* result = createPointObj(app_context, xv, yv);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar pointOffset(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	ActionVar* xv = getProperty(obj, "x", 1);
	ActionVar* yv = getProperty(obj, "y", 1);
	double sx = varToDoubleSimple(xv), sy = varToDoubleSimple(yv);

	double dx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double dy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	ActionVar nxv = makeF64(sx + dx);
	ActionVar nyv = makeF64(sy + dy);
	setProperty(app_context, obj, "x", 1, &nxv);
	setProperty(app_context, obj, "y", 1, &nyv);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar pointNormalize(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	ActionVar* xv = getProperty(obj, "x", 1);
	ActionVar* yv = getProperty(obj, "y", 1);

	// If x is undefined or y is null/undefined, special handling per Flash behavior
	int x_is_non_numeric = (xv == NULL || xv->type == ACTION_STACK_VALUE_UNDEFINED ||
	                         xv->type == ACTION_STACK_VALUE_OBJECT);
	int y_is_null = (yv != NULL && yv->type == ACTION_STACK_VALUE_NULL);

	if (x_is_non_numeric || y_is_null) {
		// Can't normalize — set x/y to NaN if thickness is provided, else leave as-is
		if (arg_count == 0) {
			// normalize() with no thickness — set both to NaN only if non-special
			if (!x_is_non_numeric) {
				ActionVar nanv = makeF64(NAN);
				setProperty(app_context, obj, "x", 1, &nanv);
			}
			if (!y_is_null) {
				ActionVar nanv = makeF64(NAN);
				setProperty(app_context, obj, "y", 1, &nanv);
			}
		}
		// With thickness but non-numeric x or null y — leave unchanged
		ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
	}

	double sx = varToDoubleSimple(xv);
	double sy = varToDoubleSimple(yv);
	double thickness = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double length = sqrt(sx * sx + sy * sy);

	if (length > 0) {
		double scale = thickness / length;
		ActionVar nxv = makeF64(sx * scale);
		ActionVar nyv = makeF64(sy * scale);
		setProperty(app_context, obj, "x", 1, &nxv);
		setProperty(app_context, obj, "y", 1, &nyv);
	}
	// length == 0: no change

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

// Point static methods
static ActionVar pointDistance(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	ActionVar r = {0};
	if (arg_count < 2) { r.type = ACTION_STACK_VALUE_F64; VAL(double, &r.data.numeric_value) = NAN; return r; }

	// Both args must be Point instances (check __proto__)
	for (int i = 0; i < 2; i++) {
		if (args[i].type != ACTION_STACK_VALUE_OBJECT || args[i].data.numeric_value == 0) {
			r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
		}
		ActionVar* proto = getProperty((ASObject*)args[i].data.numeric_value, "__proto__", 9);
		if (proto == NULL || proto->type != ACTION_STACK_VALUE_OBJECT ||
		    (ASObject*)proto->data.numeric_value != g_point_prototype) {
			r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
		}
	}

	ASObject* p1 = (ASObject*)args[0].data.numeric_value;
	ASObject* p2 = (ASObject*)args[1].data.numeric_value;
	double x1 = varToDoubleSimple(getProperty(p1, "x", 1));
	double y1 = varToDoubleSimple(getProperty(p1, "y", 1));
	double x2 = varToDoubleSimple(getProperty(p2, "x", 1));
	double y2 = varToDoubleSimple(getProperty(p2, "y", 1));
	double dx = x2 - x1, dy = y2 - y1;

	r.type = ACTION_STACK_VALUE_F64;
	VAL(double, &r.data.numeric_value) = sqrt(dx * dx + dy * dy);
	return r;
}

static ActionVar pointInterpolate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	// Point.interpolate(pt1, pt2, f) → Point(pt2.x + f*(pt1.x-pt2.x), pt2.y + f*(pt1.y-pt2.y))
	double x1 = NAN, y1 = NAN, x2 = NAN, y2 = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		x1 = varToDoubleSimple(getProperty((ASObject*)args[0].data.numeric_value, "x", 1));
		y1 = varToDoubleSimple(getProperty((ASObject*)args[0].data.numeric_value, "y", 1));
	}
	if (arg_count > 1 && args[1].type == ACTION_STACK_VALUE_OBJECT && args[1].data.numeric_value != 0) {
		x2 = varToDoubleSimple(getProperty((ASObject*)args[1].data.numeric_value, "x", 1));
		y2 = varToDoubleSimple(getProperty((ASObject*)args[1].data.numeric_value, "y", 1));
	}
	double f = (arg_count > 2) ? varToDoubleSimple(&args[2]) : NAN;

	ASObject* result = createPointObjF64(app_context, x2 + f * (x1 - x2), y2 + f * (y1 - y2));
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar pointPolar(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	double len = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double angle = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	ASObject* result = createPointObjF64(app_context, len * cos(angle), len * sin(angle));
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

// --- Matrix methods ---

static ActionVar matrixConstructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	static const char* names[] = {"a","b","c","d","tx","ty"};
	static const u32 lens[] = {1,1,1,1,2,2};
	static const double defaults[] = {1,0,0,1,0,0};

	if (arg_count == 0) {
		for (int i = 0; i < 6; i++) {
			ActionVar v = makeF64(defaults[i]);
			setProperty(app_context, obj, names[i], lens[i], &v);
		}
	} else {
		u32 count = arg_count < 6 ? arg_count : 6;
		for (u32 i = 0; i < count; i++)
			setProperty(app_context, obj, names[i], lens[i], &args[i]);
		for (u32 i = count; i < 6; i++) {
			ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
			setProperty(app_context, obj, names[i], lens[i], &undef);
		}
	}

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixToStringDynamic(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	char buf[1024];
	static const char* names[] = {"a","b","c","d","tx","ty"};
	static const u32 lens[] = {1,1,1,1,2,2};
	char vals[6][128];
	for (int i = 0; i < 6; i++) {
		ActionVar* v = obj ? getProperty(obj, names[i], lens[i]) : NULL;
		varToStringBufFull(app_context, v, vals[i], sizeof(vals[i]));
	}
	int len = snprintf(buf, sizeof(buf), "(a=%s, b=%s, c=%s, d=%s, tx=%s, ty=%s)",
	                   vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);

	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

static ActionVar matrixClone(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ASObject* result = allocObject(app_context, 8);
	ActionVar proto_var = {0};
	proto_var.type = ACTION_STACK_VALUE_OBJECT;
	proto_var.data.numeric_value = (u64) g_matrix_prototype;
	setProperty(app_context, result, "__proto__", 9, &proto_var);

	static const char* names[] = {"a","b","c","d","tx","ty"};
	static const u32 lens[] = {1,1,1,1,2,2};
	for (int i = 0; i < 6; i++) {
		ActionVar* v = obj ? getProperty(obj, names[i], lens[i]) : NULL;
		if (v) setProperty(app_context, result, names[i], lens[i], v);
	}

	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar matrixIdentity(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }
	static const char* names[] = {"a","b","c","d","tx","ty"};
	static const u32 lens[] = {1,1,1,1,2,2};
	static const double vals[] = {1,0,0,1,0,0};
	for (int i = 0; i < 6; i++) {
		ActionVar v = makeF64(vals[i]);
		setProperty(app_context, obj, names[i], lens[i], &v);
	}
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixScale(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double sx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double sy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	// a*=sx, c*=sx, tx*=sx, b*=sy, d*=sy, ty*=sy
	double a = varToDoubleSimple(getProperty(obj, "a", 1));
	double b = varToDoubleSimple(getProperty(obj, "b", 1));
	double c = varToDoubleSimple(getProperty(obj, "c", 1));
	double d = varToDoubleSimple(getProperty(obj, "d", 1));
	double tx = varToDoubleSimple(getProperty(obj, "tx", 2));
	double ty = varToDoubleSimple(getProperty(obj, "ty", 2));

	ActionVar va = makeF64(a * sx); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(b * sy); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(c * sx); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(d * sy); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(tx * sx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(ty * sy); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixRotate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double angle = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double cosA = cos(angle), sinA = sin(angle);

	double a = varToDoubleSimple(getProperty(obj, "a", 1));
	double b = varToDoubleSimple(getProperty(obj, "b", 1));
	double c = varToDoubleSimple(getProperty(obj, "c", 1));
	double d = varToDoubleSimple(getProperty(obj, "d", 1));
	double tx = varToDoubleSimple(getProperty(obj, "tx", 2));
	double ty = varToDoubleSimple(getProperty(obj, "ty", 2));

	double na = a * cosA + b * (-sinA);
	double nb = a * sinA + b * cosA;
	double nc = c * cosA + d * (-sinA);
	double nd = c * sinA + d * cosA;
	double ntx = tx * cosA + ty * (-sinA);
	double nty = tx * sinA + ty * cosA;

	ActionVar va = makeF64(na); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(nb); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(nc); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(nd); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(ntx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(nty); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixTranslate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double dx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double dy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	double tx = varToDoubleSimple(getProperty(obj, "tx", 2));
	double ty = varToDoubleSimple(getProperty(obj, "ty", 2));

	ActionVar vtx = makeF64(tx + dx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(ty + dy); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixConcat(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double a = varToDoubleSimple(getProperty(obj, "a", 1));
	double b = varToDoubleSimple(getProperty(obj, "b", 1));
	double c = varToDoubleSimple(getProperty(obj, "c", 1));
	double d = varToDoubleSimple(getProperty(obj, "d", 1));
	double tx = varToDoubleSimple(getProperty(obj, "tx", 2));
	double ty = varToDoubleSimple(getProperty(obj, "ty", 2));

	double ma = NAN, mb = NAN, mc = NAN, md = NAN, mtx = NAN, mty = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* m = (ASObject*)args[0].data.numeric_value;
		ma = varToDoubleSimple(getProperty(m, "a", 1));
		mb = varToDoubleSimple(getProperty(m, "b", 1));
		mc = varToDoubleSimple(getProperty(m, "c", 1));
		md = varToDoubleSimple(getProperty(m, "d", 1));
		mtx = varToDoubleSimple(getProperty(m, "tx", 2));
		mty = varToDoubleSimple(getProperty(m, "ty", 2));
	}

	// Right multiply: this = this * m
	double na  = a * ma + b * mc;
	double nb  = a * mb + b * md;
	double nc  = c * ma + d * mc;
	double nd  = c * mb + d * md;
	double ntx = tx * ma + ty * mc + mtx;
	double nty = tx * mb + ty * md + mty;

	ActionVar va = makeF64(na); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(nb); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(nc); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(nd); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(ntx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(nty); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixInvert(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double a = varToDoubleSimple(getProperty(obj, "a", 1));
	double b = varToDoubleSimple(getProperty(obj, "b", 1));
	double c = varToDoubleSimple(getProperty(obj, "c", 1));
	double d = varToDoubleSimple(getProperty(obj, "d", 1));
	double tx = varToDoubleSimple(getProperty(obj, "tx", 2));
	double ty = varToDoubleSimple(getProperty(obj, "ty", 2));

	double det = a * d - b * c;
	double inv_det = 1.0 / det;

	double na  =  d * inv_det;
	double nb  = -b * inv_det;
	double nc  = -c * inv_det;
	double nd  =  a * inv_det;
	double ntx = (c * ty - d * tx) * inv_det;
	double nty = (b * tx - a * ty) * inv_det;

	ActionVar va = makeF64(na); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(nb); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(nc); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(nd); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(ntx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(nty); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixCreateBox(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double sx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double sy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;
	double rot = (arg_count > 2) ? varToDoubleSimple(&args[2]) : NAN;
	double dtx = (arg_count > 3) ? varToDoubleSimple(&args[3]) : 0.0;
	double dty = (arg_count > 4) ? varToDoubleSimple(&args[4]) : 0.0;

	double cosR = cos(rot), sinR = sin(rot);
	ActionVar va = makeF64(sx * cosR); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(sy * sinR); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(-sx * sinR); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(sy * cosR); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(dtx); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(dty); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixCreateGradientBox(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double w = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double h = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;
	double rot = (arg_count > 2) ? varToDoubleSimple(&args[2]) : 0.0;
	double dtx = (arg_count > 3) ? varToDoubleSimple(&args[3]) : 0.0;
	double dty = (arg_count > 4) ? varToDoubleSimple(&args[4]) : 0.0;

	double scaleX = w / 1638.4;
	double scaleY = h / 1638.4;
	double cosR = cos(rot), sinR = sin(rot);
	ActionVar va = makeF64(scaleX * cosR); setProperty(app_context, obj, "a", 1, &va);
	ActionVar vb = makeF64(scaleY * sinR); setProperty(app_context, obj, "b", 1, &vb);
	ActionVar vc = makeF64(-scaleX * sinR); setProperty(app_context, obj, "c", 1, &vc);
	ActionVar vd = makeF64(scaleY * cosR); setProperty(app_context, obj, "d", 1, &vd);
	ActionVar vtx = makeF64(dtx + w / 2.0); setProperty(app_context, obj, "tx", 2, &vtx);
	ActionVar vty = makeF64(dty + h / 2.0); setProperty(app_context, obj, "ty", 2, &vty);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar matrixTransformPoint(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	double a = varToDoubleSimple(obj ? getProperty(obj, "a", 1) : NULL);
	double b = varToDoubleSimple(obj ? getProperty(obj, "b", 1) : NULL);
	double c = varToDoubleSimple(obj ? getProperty(obj, "c", 1) : NULL);
	double d = varToDoubleSimple(obj ? getProperty(obj, "d", 1) : NULL);
	double tx = varToDoubleSimple(obj ? getProperty(obj, "tx", 2) : NULL);
	double ty = varToDoubleSimple(obj ? getProperty(obj, "ty", 2) : NULL);

	double px = NAN, py = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		px = propToDouble(pt, "x", 1);
		py = propToDouble(pt, "y", 1);
	}

	ASObject* result = createPointObjF64(app_context, a * px + c * py + tx, b * px + d * py + ty);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar matrixDeltaTransformPoint(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	double a = varToDoubleSimple(obj ? getProperty(obj, "a", 1) : NULL);
	double b = varToDoubleSimple(obj ? getProperty(obj, "b", 1) : NULL);
	double c = varToDoubleSimple(obj ? getProperty(obj, "c", 1) : NULL);
	double d = varToDoubleSimple(obj ? getProperty(obj, "d", 1) : NULL);

	double px = NAN, py = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		px = propToDouble(pt, "x", 1);
		py = propToDouble(pt, "y", 1);
	}

	ASObject* result = createPointObjF64(app_context, a * px + c * py, b * px + d * py);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

// --- Rectangle methods ---

static ActionVar rectangleConstructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	static const char* names[] = {"x","y","width","height"};
	static const u32 lens[] = {1,1,5,6};

	if (arg_count == 0) {
		ActionVar zero = makeF64(0.0);
		for (int i = 0; i < 4; i++)
			setProperty(app_context, obj, names[i], lens[i], &zero);
	} else {
		u32 count = arg_count < 4 ? arg_count : 4;
		for (u32 i = 0; i < count; i++)
			setProperty(app_context, obj, names[i], lens[i], &args[i]);
		for (u32 i = count; i < 4; i++) {
			ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
			setProperty(app_context, obj, names[i], lens[i], &undef);
		}
	}

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectToStringDynamic(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	char buf[512];
	char xb[64], yb[64], wb[64], hb[64];
	ActionVar* xv = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* yv = obj ? getProperty(obj, "y", 1) : NULL;
	ActionVar* wv = obj ? getProperty(obj, "width", 5) : NULL;
	ActionVar* hv = obj ? getProperty(obj, "height", 6) : NULL;
	varToStringBufFull(app_context, xv, xb, sizeof(xb));
	varToStringBufFull(app_context, yv, yb, sizeof(yb));
	varToStringBufFull(app_context, wv, wb, sizeof(wb));
	varToStringBufFull(app_context, hv, hb, sizeof(hb));
	int len = snprintf(buf, sizeof(buf), "(x=%s, y=%s, w=%s, h=%s)", xb, yb, wb, hb);

	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

static ActionVar rectClone(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar* xv = obj ? getProperty(obj, "x", 1) : NULL;
	ActionVar* yv = obj ? getProperty(obj, "y", 1) : NULL;
	ActionVar* wv = obj ? getProperty(obj, "width", 5) : NULL;
	ActionVar* hv = obj ? getProperty(obj, "height", 6) : NULL;
	ASObject* result = createRectObj(app_context, xv, yv, wv, hv);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar rectEquals(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = 0;
	if (obj == NULL || arg_count == 0) return r;

	// Must be a Rectangle instance
	if (args[0].type != ACTION_STACK_VALUE_OBJECT || args[0].data.numeric_value == 0) return r;
	ASObject* other = (ASObject*)args[0].data.numeric_value;
	ActionVar* proto = getProperty(other, "__proto__", 9);
	if (proto == NULL || proto->type != ACTION_STACK_VALUE_OBJECT ||
	    (ASObject*)proto->data.numeric_value != g_rect_prototype) return r;

	double sx = varToDoubleSimple(getProperty(obj, "x", 1));
	double sy = varToDoubleSimple(getProperty(obj, "y", 1));
	double sw = varToDoubleSimple(getProperty(obj, "width", 5));
	double sh = varToDoubleSimple(getProperty(obj, "height", 6));
	double ox = propToDouble(other, "x", 1);
	double oy = propToDouble(other, "y", 1);
	double ow = propToDouble(other, "width", 5);
	double oh = propToDouble(other, "height", 6);

	if (sx == ox && sy == oy && sw == ow && sh == oh)
		r.data.numeric_value = 1;
	return r;
}

static ActionVar rectIsEmpty(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_BOOLEAN;
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);
	// isEmpty: !(width > 0 && height > 0) — NaN/undefined → true
	r.data.numeric_value = (w > 0 && h > 0) ? 0 : 1;
	return r;
}

static ActionVar rectSetEmpty(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj) {
		ActionVar zero = makeF64(0.0);
		setProperty(app_context, obj, "x", 1, &zero);
		setProperty(app_context, obj, "y", 1, &zero);
		setProperty(app_context, obj, "width", 5, &zero);
		setProperty(app_context, obj, "height", 6, &zero);
	}
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectContains(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};

	if (arg_count < 2) { r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double px = varToDoubleSimple(&args[0]);
	double py = varToDoubleSimple(&args[1]);
	if (isnan(px) || isnan(py)) { r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = (px >= x && px < x + w && py >= y && py < y + h) ? 1 : 0;
	return r;
}

static ActionVar rectContainsPoint(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};

	if (arg_count == 0) { r.type = ACTION_STACK_VALUE_BOOLEAN; r.data.numeric_value = 0; return r; }

	double px, py;
	if (args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		px = propToDouble(pt, "x", 1);
		py = propToDouble(pt, "y", 1);
	} else {
		px = NAN; py = NAN;
	}

	if (isnan(px) || isnan(py)) { r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = (px >= x && px < x + w && py >= y && py < y + h) ? 1 : 0;
	return r;
}

static ActionVar rectContainsRectangle(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};

	if (arg_count == 0 || args[0].type != ACTION_STACK_VALUE_OBJECT || args[0].data.numeric_value == 0) {
		r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
	}

	ASObject* other = (ASObject*)args[0].data.numeric_value;
	double ox = propToDouble(other, "x", 1);
	double oy = propToDouble(other, "y", 1);
	double ow = propToDouble(other, "width", 5);
	double oh = propToDouble(other, "height", 6);

	if (isnan(ox) || isnan(oy) || isnan(ow) || isnan(oh)) {
		r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
	}

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	double right = x + w, bottom = y + h;
	double oright = ox + ow, obottom = oy + oh;

	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = (ox >= x && oy >= y && oright <= right && obottom <= bottom) ? 1 : 0;
	return r;
}

static ActionVar rectInflate(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double dx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double dy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	double x = varToDoubleSimple(getProperty(obj, "x", 1));
	double y = varToDoubleSimple(getProperty(obj, "y", 1));
	double w = varToDoubleSimple(getProperty(obj, "width", 5));
	double h = varToDoubleSimple(getProperty(obj, "height", 6));

	ActionVar vx = makeF64(x - dx); setProperty(app_context, obj, "x", 1, &vx);
	ActionVar vy = makeF64(y - dy); setProperty(app_context, obj, "y", 1, &vy);
	ActionVar vw = makeF64(w + 2 * dx); setProperty(app_context, obj, "width", 5, &vw);
	ActionVar vh = makeF64(h + 2 * dy); setProperty(app_context, obj, "height", 6, &vh);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectInflatePoint(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double dx = NAN, dy = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		dx = propToDouble(pt, "x", 1);
		dy = propToDouble(pt, "y", 1);
	}

	double x = varToDoubleSimple(getProperty(obj, "x", 1));
	double y = varToDoubleSimple(getProperty(obj, "y", 1));
	double w = varToDoubleSimple(getProperty(obj, "width", 5));
	double h = varToDoubleSimple(getProperty(obj, "height", 6));

	ActionVar vx = makeF64(x - dx); setProperty(app_context, obj, "x", 1, &vx);
	ActionVar vy = makeF64(y - dy); setProperty(app_context, obj, "y", 1, &vy);
	ActionVar vw = makeF64(w + 2 * dx); setProperty(app_context, obj, "width", 5, &vw);
	ActionVar vh = makeF64(h + 2 * dy); setProperty(app_context, obj, "height", 6, &vh);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectIntersection(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	double ox = NAN, oy = NAN, ow = NAN, oh = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* other = (ASObject*)args[0].data.numeric_value;
		ox = propToDouble(other, "x", 1);
		oy = propToDouble(other, "y", 1);
		ow = propToDouble(other, "width", 5);
		oh = propToDouble(other, "height", 6);
	}

	double left = (x > ox) ? x : ox;
	double top = (y > oy) ? y : oy;
	double right = ((x + w) < (ox + ow)) ? (x + w) : (ox + ow);
	double bottom = ((y + h) < (oh + oy)) ? (y + h) : (oh + oy);

	ActionVar rx, ry, rw, rh;
	if (right > left && bottom > top) {
		rx = makeF64(left); ry = makeF64(top);
		rw = makeF64(right - left); rh = makeF64(bottom - top);
	} else {
		rx = makeF64(0); ry = makeF64(0);
		rw = makeF64(0); rh = makeF64(0);
	}

	ASObject* result = createRectObj(app_context, &rx, &ry, &rw, &rh);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

static ActionVar rectIntersects(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	// Calls intersection logic inline
	ASObject* obj = (ASObject*) this_obj;
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = 0;

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	double ox = NAN, oy = NAN, ow = NAN, oh = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* other = (ASObject*)args[0].data.numeric_value;
		ox = propToDouble(other, "x", 1);
		oy = propToDouble(other, "y", 1);
		ow = propToDouble(other, "width", 5);
		oh = propToDouble(other, "height", 6);
	}

	double left = (x > ox) ? x : ox;
	double top = (y > oy) ? y : oy;
	double right_val = ((x + w) < (ox + ow)) ? (x + w) : (ox + ow);
	double bottom_val = ((y + h) < (oh + oy)) ? (y + h) : (oh + oy);

	if (right_val > left && bottom_val > top)
		r.data.numeric_value = 1;
	return r;
}

static ActionVar rectOffset(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double dx = (arg_count > 0) ? varToDoubleSimple(&args[0]) : NAN;
	double dy = (arg_count > 1) ? varToDoubleSimple(&args[1]) : NAN;

	double x = varToDoubleSimple(getProperty(obj, "x", 1));
	double y = varToDoubleSimple(getProperty(obj, "y", 1));

	ActionVar vx = makeF64(x + dx); setProperty(app_context, obj, "x", 1, &vx);
	ActionVar vy = makeF64(y + dy); setProperty(app_context, obj, "y", 1, &vy);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectOffsetPoint(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;
	if (obj == NULL) { ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r; }

	double dx = NAN, dy = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* pt = (ASObject*)args[0].data.numeric_value;
		dx = propToDouble(pt, "x", 1);
		dy = propToDouble(pt, "y", 1);
	}

	double x = varToDoubleSimple(getProperty(obj, "x", 1));
	double y = varToDoubleSimple(getProperty(obj, "y", 1));

	ActionVar vx = makeF64(x + dx); setProperty(app_context, obj, "x", 1, &vx);
	ActionVar vy = makeF64(y + dy); setProperty(app_context, obj, "y", 1, &vy);

	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

static ActionVar rectUnion(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*) this_obj;

	double x = varToDoubleSimple(obj ? getProperty(obj, "x", 1) : NULL);
	double y = varToDoubleSimple(obj ? getProperty(obj, "y", 1) : NULL);
	double w = varToDoubleSimple(obj ? getProperty(obj, "width", 5) : NULL);
	double h = varToDoubleSimple(obj ? getProperty(obj, "height", 6) : NULL);

	double ox = NAN, oy = NAN, ow = NAN, oh = NAN;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
		ASObject* other = (ASObject*)args[0].data.numeric_value;
		ox = propToDouble(other, "x", 1);
		oy = propToDouble(other, "y", 1);
		ow = propToDouble(other, "width", 5);
		oh = propToDouble(other, "height", 6);
	}

	double left = (x < ox) ? x : ox;
	double top = (y < oy) ? y : oy;
	double right_val = ((x + w) > (ox + ow)) ? (x + w) : (ox + ow);
	double bottom_val = ((y + h) > (oh + oy)) ? (y + h) : (oh + oy);

	ActionVar rx = makeF64(left), ry = makeF64(top);
	ActionVar rw = makeF64(right_val - left), rh = makeF64(bottom_val - top);
	ASObject* result = createRectObj(app_context, &rx, &ry, &rw, &rh);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64) result;
	return r;
}

// --- Geometry initialization ---

static void initGeomPrototypes(SWFAppContext* app_context)
{
	if (g_geom_init_done) return;
	g_geom_init_done = 1;

	// Point prototype
	g_point_prototype = allocObject(app_context, 12);
	retainObject(g_point_prototype);
	setObjectProto(app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[0], "toString",  (Function2Ptr)pointToString,  app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[1], "add",       (Function2Ptr)pointAdd,       app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[2], "subtract",  (Function2Ptr)pointSubtract,  app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[3], "equals",    (Function2Ptr)pointEquals,     app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[4], "clone",     (Function2Ptr)pointClone,      app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[5], "offset",    (Function2Ptr)pointOffset,     app_context, g_point_prototype);
	registerGeomMethod(&g_point_methods[6], "normalize", (Function2Ptr)pointNormalize,  app_context, g_point_prototype);

	// Matrix prototype
	g_matrix_prototype = allocObject(app_context, 16);
	retainObject(g_matrix_prototype);
	setObjectProto(app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[0],  "toString",            (Function2Ptr)matrixToStringDynamic,     app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[1],  "clone",               (Function2Ptr)matrixClone,               app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[2],  "identity",            (Function2Ptr)matrixIdentity,            app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[3],  "scale",               (Function2Ptr)matrixScale,               app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[4],  "rotate",              (Function2Ptr)matrixRotate,              app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[5],  "translate",           (Function2Ptr)matrixTranslate,           app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[6],  "concat",              (Function2Ptr)matrixConcat,              app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[7],  "invert",              (Function2Ptr)matrixInvert,              app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[8],  "createBox",           (Function2Ptr)matrixCreateBox,           app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[9],  "createGradientBox",   (Function2Ptr)matrixCreateGradientBox,   app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[10], "transformPoint",      (Function2Ptr)matrixTransformPoint,      app_context, g_matrix_prototype);
	registerGeomMethod(&g_matrix_methods[11], "deltaTransformPoint", (Function2Ptr)matrixDeltaTransformPoint, app_context, g_matrix_prototype);

	// Rectangle prototype
	g_rect_prototype = allocObject(app_context, 20);
	retainObject(g_rect_prototype);
	setObjectProto(app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[0],  "toString",           (Function2Ptr)rectToStringDynamic,    app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[1],  "clone",              (Function2Ptr)rectClone,              app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[2],  "equals",             (Function2Ptr)rectEquals,             app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[3],  "isEmpty",            (Function2Ptr)rectIsEmpty,            app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[4],  "setEmpty",           (Function2Ptr)rectSetEmpty,           app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[5],  "contains",           (Function2Ptr)rectContains,           app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[6],  "containsPoint",      (Function2Ptr)rectContainsPoint,      app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[7],  "containsRectangle",  (Function2Ptr)rectContainsRectangle,  app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[8],  "inflate",            (Function2Ptr)rectInflate,            app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[9],  "inflatePoint",       (Function2Ptr)rectInflatePoint,       app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[10], "intersection",       (Function2Ptr)rectIntersection,       app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[11], "intersects",         (Function2Ptr)rectIntersects,         app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[12], "offset",             (Function2Ptr)rectOffset,             app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[13], "offsetPoint",        (Function2Ptr)rectOffsetPoint,        app_context, g_rect_prototype);
	registerGeomMethod(&g_rect_methods[14], "union",              (Function2Ptr)rectUnion,              app_context, g_rect_prototype);
}

// ============================================================================
// AVM1 Color object implementation
// ============================================================================

// ECMA-262 ToInt32: NaN/Inf/zero -> 0; otherwise truncate and wrap to int32 range.
static int32_t ecmaToInt32Color(double d)
{
	if (!isfinite(d) || d == 0.0) return 0;
	double t = d < 0.0 ? ceil(d) : floor(d);
	double m = fmod(t, 4294967296.0);
	if (m < 0.0) m += 4294967296.0;
	if (m >= 2147483648.0) m -= 4294967296.0;
	return (int32_t)m;
}

// Quantize a Color setTransform multiplier value (percentage units) through int16 fixed-point.
// Input d is in percentage units (100.0 = 100%). Output is in same units.
// Formula: int16 = (int32(d) * 256) / 100 (integer division), then stored as int16*100/256.
static double quantifyColorMult(double d)
{
	int32_t i32 = ecmaToInt32Color(d);
	int32_t scaled = (int32_t)((int64_t)i32 * 256 / 100);
	return (double)(int16_t)scaled * 100.0 / 256.0;
}

// Quantize a Color setTransform addend value through int16.
// Input d is in pixel units. Output is the int16-truncated value.
static double quantifyColorAdd(double d)
{
	int32_t i32 = ecmaToInt32Color(d);
	return (double)(int16_t)i32;
}

// Helper: get the MC instance name stored on a Color object (as UTF-8 in out_buf).
// Returns 1 if found and valid, 0 otherwise.
static int colorGetMCName(ASObject* obj, char* out_buf, size_t buf_size)
{
	if (!obj) return 0;
	ActionVar* nv = getProperty(obj, "__mc_name__", 11);
	if (!nv || nv->type != ACTION_STACK_VALUE_STRING) return 0;
	const uint16_t* u16 = varGetU16Ptr(nv);
	if (!u16 || nv->str_size == 0) return 0;
	u16_to_utf8(u16, nv->str_size, out_buf, (u32)buf_size);
	return out_buf[0] != '\0';
}

// Color.getTransform() -> Object{ra,ga,ba,aa,rb,gb,bb,ab}
static ActionVar colorGetTransform(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*)this_obj;
	char name[256] = {0};
	double ra = 100.0, ga = 100.0, ba = 100.0, aa = 100.0;
	double rb = 0.0,   gb = 0.0,   bb = 0.0,   ab = 0.0;

#ifdef NO_GRAPHICS
	if (colorGetMCName(obj, name, sizeof(name)))
		ng_getColorTransform(name, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab);
#endif

	ASObject* result = allocObject(app_context, 8);
	ActionVar v;
	v = makeF64(ra); setProperty(app_context, result, "ra", 2, &v);
	v = makeF64(ga); setProperty(app_context, result, "ga", 2, &v);
	v = makeF64(ba); setProperty(app_context, result, "ba", 2, &v);
	v = makeF64(aa); setProperty(app_context, result, "aa", 2, &v);
	v = makeF64(rb); setProperty(app_context, result, "rb", 2, &v);
	v = makeF64(gb); setProperty(app_context, result, "gb", 2, &v);
	v = makeF64(bb); setProperty(app_context, result, "bb", 2, &v);
	v = makeF64(ab); setProperty(app_context, result, "ab", 2, &v);

	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_OBJECT;
	r.data.numeric_value = (u64)result;
	return r;
}

// Color.setTransform(obj) - reads ra/ga/ba/aa/rb/gb/bb/ab from obj (own-properties only).
// Each value is quantized through int16 fixed-point.
static ActionVar colorSetTransform(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* self = (ASObject*)this_obj;
	if (arg_count == 0) return undef;

	// Argument must be an object
	ASObject* param = NULL;
	if (args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0)
		param = (ASObject*)args[0].data.numeric_value;
	if (!param) return undef;

	char name[256] = {0};
#ifdef NO_GRAPHICS
	if (!colorGetMCName(self, name, sizeof(name))) return undef;

	// Read current transform
	double ra, ga, ba, aa, rb, gb, bb, ab;
	if (!ng_getColorTransform(name, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab)) return undef;

	// Apply only own-properties from param (not inherited via __proto__)
	ActionVar* pv;
	pv = getProperty(param, "ra", 2); if (pv) ra = quantifyColorMult(varToDoubleSimple(pv));
	pv = getProperty(param, "ga", 2); if (pv) ga = quantifyColorMult(varToDoubleSimple(pv));
	pv = getProperty(param, "ba", 2); if (pv) ba = quantifyColorMult(varToDoubleSimple(pv));
	pv = getProperty(param, "aa", 2); if (pv) aa = quantifyColorMult(varToDoubleSimple(pv));
	pv = getProperty(param, "rb", 2); if (pv) rb = quantifyColorAdd(varToDoubleSimple(pv));
	pv = getProperty(param, "gb", 2); if (pv) gb = quantifyColorAdd(varToDoubleSimple(pv));
	pv = getProperty(param, "bb", 2); if (pv) bb = quantifyColorAdd(varToDoubleSimple(pv));
	pv = getProperty(param, "ab", 2); if (pv) ab = quantifyColorAdd(varToDoubleSimple(pv));

	ng_setColorTransform(name, ra, ga, ba, aa, rb, gb, bb, ab);
#endif
	return undef;
}

// Color.getRGB() -> int32 color value from addend components, or undefined if target invalid.
static ActionVar colorGetRGB(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* obj = (ASObject*)this_obj;
	char name[256] = {0};

#ifdef NO_GRAPHICS
	if (!colorGetMCName(obj, name, sizeof(name))) return undef;
	double ra, ga, ba, aa, rb, gb, bb, ab;
	if (!ng_getColorTransform(name, &ra, &ga, &ba, &aa, &rb, &gb, &bb, &ab)) return undef;

	uint32_t color_u = ((uint32_t)(int32_t)rb << 16) |
	                   ((uint32_t)(int32_t)gb << 8) |
	                   (uint32_t)(int32_t)bb;
	return makeF64((double)(int32_t)color_u);
#else
	return undef;
#endif
}

// Color.setRGB(n) - sets ra=ga=ba=0, rb/gb/bb from n's bytes; aa and ab unchanged.
static ActionVar colorSetRGB(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* obj = (ASObject*)this_obj;
	if (arg_count == 0) return undef;
	char name[256] = {0};

#ifdef NO_GRAPHICS
	if (!colorGetMCName(obj, name, sizeof(name))) return undef;
	double ra_cur, ga_cur, ba_cur, aa_cur, rb_cur, gb_cur, bb_cur, ab_cur;
	if (!ng_getColorTransform(name, &ra_cur, &ga_cur, &ba_cur, &aa_cur, &rb_cur, &gb_cur, &bb_cur, &ab_cur))
		return undef;

	// Decompose n into R, G, B bytes (0-255 each); zero the multipliers ra/ga/ba
	int32_t n = ecmaToInt32Color(varToDoubleSimple(&args[0]));
	double new_rb = (double)((n >> 16) & 0xFF);
	double new_gb = (double)((n >> 8)  & 0xFF);
	double new_bb = (double)(n & 0xFF);

	ng_setColorTransform(name, 0.0, 0.0, 0.0, aa_cur, new_rb, new_gb, new_bb, ab_cur);
#endif
	return undef;
}

static void initColorPrototype(SWFAppContext* app_context)
{
	if (g_color_init_done) return;
	g_color_init_done = 1;
	g_color_prototype = allocObject(app_context, 4);
	retainObject(g_color_prototype);
	setObjectProto(app_context, g_color_prototype);
	registerGeomMethod(&g_color_methods[0], "getTransform", (Function2Ptr)colorGetTransform, app_context, g_color_prototype);
	registerGeomMethod(&g_color_methods[1], "setTransform", (Function2Ptr)colorSetTransform, app_context, g_color_prototype);
	registerGeomMethod(&g_color_methods[2], "getRGB",       (Function2Ptr)colorGetRGB,       app_context, g_color_prototype);
	registerGeomMethod(&g_color_methods[3], "setRGB",       (Function2Ptr)colorSetRGB,       app_context, g_color_prototype);
}

// Color constructor: new Color(mc) where mc is a MovieClip or button reference.
static ActionVar colorConstructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*)this_obj;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	if (!obj) return undef;

	if (arg_count >= 1 && args[0].type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		MovieClip* mc = (MovieClip*) VAL(u64, &args[0].data.numeric_value);
		if (mc && mc->name[0] != '\0')
		{
			// Store target as "_level0.name" string property
			char target_str[512];
			int tlen = snprintf(target_str, sizeof(target_str), "_level0.%s", mc->name);
			u32 t_u16_len;
			uint16_t* t_u16 = ascii_to_u16(app_context, target_str, tlen, &t_u16_len);
			ActionVar tvar = {0};
			tvar.type = ACTION_STACK_VALUE_STRING;
			tvar.str_size = t_u16_len;
			tvar.data.string_data.heap_ptr = t_u16;
			tvar.data.string_data.owns_memory = true;
			setProperty(app_context, obj, "target", 6, &tvar);

			// Store MC instance name as hidden __mc_name__ property (DONTENUM)
			u32 n_u16_len;
			int nlen = (int)strlen(mc->name);
			uint16_t* n_u16 = ascii_to_u16(app_context, mc->name, nlen, &n_u16_len);
			ActionVar nvar = {0};
			nvar.type = ACTION_STACK_VALUE_STRING;
			nvar.str_size = n_u16_len;
			nvar.data.string_data.heap_ptr = n_u16;
			nvar.data.string_data.owns_memory = true;
			setPropertyWithFlags(app_context, obj, "__mc_name__", 11, &nvar, PROPERTY_FLAGS_DONTENUM);
		}
	}
	return undef;
}

// ============================================================================
// flash.geom.ColorTransform implementation
// ============================================================================

// Helper: read a CT instance property as double via prototype chain.
static inline double ctPropToDouble(ASObject* obj, const char* name, u32 nlen)
{
	ActionVar* v = obj ? getPropertyWithPrototype(obj, name, nlen) : NULL;
	if (!v) return 0.0;
	return varToDoubleSimple(v);
}

// Helper: read a CT property, convert to F64, format as string (matches Flash toString behavior).
static void ctFormatProp(SWFAppContext* app_context, ASObject* obj, const char* name, u32 nlen, char* buf, int bufsz)
{
	ActionVar* v = obj ? getPropertyWithPrototype(obj, name, nlen) : NULL;
	double d = v ? varToDoubleSimple(v) : 0.0;
	ActionVar fv = makeF64(d);
	varToStringBufFull(app_context, &fv, buf, bufsz);
}

// ColorTransform.toString()
// Returns "(redMultiplier=V, greenMultiplier=V, ...)"
static ActionVar ctToString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*)this_obj;
	char rm[64], gm[64], bm[64], am[64], ro[64], go_[64], bo[64], ao[64];
	ctFormatProp(app_context, obj, "redMultiplier",   13, rm,  sizeof(rm));
	ctFormatProp(app_context, obj, "greenMultiplier", 15, gm,  sizeof(gm));
	ctFormatProp(app_context, obj, "blueMultiplier",  14, bm,  sizeof(bm));
	ctFormatProp(app_context, obj, "alphaMultiplier", 15, am,  sizeof(am));
	ctFormatProp(app_context, obj, "redOffset",        9, ro,  sizeof(ro));
	ctFormatProp(app_context, obj, "greenOffset",     11, go_, sizeof(go_));
	ctFormatProp(app_context, obj, "blueOffset",      10, bo,  sizeof(bo));
	ctFormatProp(app_context, obj, "alphaOffset",     11, ao,  sizeof(ao));
	char buf[1024];
	int len = snprintf(buf, sizeof(buf),
		"(redMultiplier=%s, greenMultiplier=%s, blueMultiplier=%s, alphaMultiplier=%s, "
		"redOffset=%s, greenOffset=%s, blueOffset=%s, alphaOffset=%s)",
		rm, gm, bm, am, ro, go_, bo, ao);
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, buf, len, &u16_len);
	r.str_size = u16_len;
	r.data.string_data.heap_ptr = u16;
	r.data.string_data.owns_memory = true;
	return r;
}

// ColorTransform.concat(other): mutates this in place.
// Formula: this.mult = this.mult * other.mult
//          this.offset = this_orig.mult * other.offset + this.offset
static ActionVar ctConcat(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* obj = (ASObject*)this_obj;
	if (!obj) return undef;
	if (arg_count == 0) return undef;
	if (args[0].type != ACTION_STACK_VALUE_OBJECT || args[0].data.numeric_value == 0) return undef;
	ASObject* other = (ASObject*)args[0].data.numeric_value;

	// Read this
	double rm = ctPropToDouble(obj, "redMultiplier",   13);
	double gm = ctPropToDouble(obj, "greenMultiplier", 15);
	double bm = ctPropToDouble(obj, "blueMultiplier",  14);
	double am = ctPropToDouble(obj, "alphaMultiplier", 15);
	double ro = ctPropToDouble(obj, "redOffset",        9);
	double go = ctPropToDouble(obj, "greenOffset",     11);
	double bo = ctPropToDouble(obj, "blueOffset",      10);
	double ao = ctPropToDouble(obj, "alphaOffset",     11);

	// Read other
	double orm = ctPropToDouble(other, "redMultiplier",   13);
	double ogm = ctPropToDouble(other, "greenMultiplier", 15);
	double obm = ctPropToDouble(other, "blueMultiplier",  14);
	double oam = ctPropToDouble(other, "alphaMultiplier", 15);
	double oro = ctPropToDouble(other, "redOffset",        9);
	double ogo = ctPropToDouble(other, "greenOffset",     11);
	double obo = ctPropToDouble(other, "blueOffset",      10);
	double oao = ctPropToDouble(other, "alphaOffset",     11);

	// Write new values: mult = this.mult * other.mult
	//                   offset = this.mult_orig * other.offset + this.offset
	ActionVar v;
	v = makeF64(rm * orm); setProperty(app_context, obj, "redMultiplier",   13, &v);
	v = makeF64(gm * ogm); setProperty(app_context, obj, "greenMultiplier", 15, &v);
	v = makeF64(bm * obm); setProperty(app_context, obj, "blueMultiplier",  14, &v);
	v = makeF64(am * oam); setProperty(app_context, obj, "alphaMultiplier", 15, &v);
	v = makeF64(rm * oro + ro); setProperty(app_context, obj, "redOffset",    9, &v);
	v = makeF64(gm * ogo + go); setProperty(app_context, obj, "greenOffset", 11, &v);
	v = makeF64(bm * obo + bo); setProperty(app_context, obj, "blueOffset",  10, &v);
	v = makeF64(am * oao + ao); setProperty(app_context, obj, "alphaOffset", 11, &v);
	return undef;
}

// ColorTransform rgb getter: returns (rOff & 0xFF)<<16 | (gOff & 0xFF)<<8 | (bOff & 0xFF)
static ActionVar ctRgbGetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	ASObject* obj = (ASObject*)this_obj;
	ActionVar* rv = obj ? getPropertyWithPrototype(obj, "redOffset",    9) : NULL;
	ActionVar* gv = obj ? getPropertyWithPrototype(obj, "greenOffset", 11) : NULL;
	ActionVar* bv = obj ? getPropertyWithPrototype(obj, "blueOffset",  10) : NULL;
	int32_t r = rv ? (int32_t)varToDoubleSimple(rv) : 0;
	int32_t g = gv ? (int32_t)varToDoubleSimple(gv) : 0;
	int32_t b = bv ? (int32_t)varToDoubleSimple(bv) : 0;
	uint32_t packed = ((uint32_t)(r & 0xFF) << 16) | ((uint32_t)(g & 0xFF) << 8) | (uint32_t)(b & 0xFF);
	return makeF64((double)(int32_t)packed);
}

// ColorTransform rgb setter: n=ToInt32(value); rOff=(n>>16)&0xFF; gOff=(n>>8)&0xFF; bOff=n&0xFF;
//   rMult=gMult=bMult=0; aMult and aOff unchanged.
static ActionVar ctRgbSetter(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	ASObject* obj = (ASObject*)this_obj;
	if (!obj || arg_count == 0) return undef;
	double d = varToDoubleSimple(&args[0]);
	int32_t n = ecmaToInt32Color(d);
	double r = (double)((n >> 16) & 0xFF);
	double g = (double)((n >> 8)  & 0xFF);
	double b = (double)(n & 0xFF);
	ActionVar zero = makeF64(0.0);
	setProperty(app_context, obj, "redMultiplier",   13, &zero);
	setProperty(app_context, obj, "greenMultiplier", 15, &zero);
	setProperty(app_context, obj, "blueMultiplier",  14, &zero);
	ActionVar rv = makeF64(r); setProperty(app_context, obj, "redOffset",    9, &rv);
	ActionVar gv = makeF64(g); setProperty(app_context, obj, "greenOffset", 11, &gv);
	ActionVar bv = makeF64(b); setProperty(app_context, obj, "blueOffset",  10, &bv);
	return undef;
}

// Helper: set up an addProperty virtual getter/setter on an object.
static void setAddProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 nlen,
                           ASFunction* getter, ASFunction* setter)
{
	ActionVar marker = {0};
	marker.type = ACTION_STACK_VALUE_UNDEFINED;
	setProperty(app_context, obj, name, nlen, &marker);
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (obj->properties[i].name_length == nlen &&
		    strncmp(obj->properties[i].name, name, nlen) == 0)
		{
			obj->properties[i].getter = (void*)getter;
			obj->properties[i].setter = (void*)setter;
			break;
		}
	}
}

static void initColorTransformPrototype(SWFAppContext* app_context)
{
	if (g_color_transform_init_done) return;
	g_color_transform_init_done = 1;

	g_color_transform_prototype = allocObject(app_context, 14);
	retainObject(g_color_transform_prototype);
	setObjectProto(app_context, g_color_transform_prototype);

	// Insert properties in REVERSE of desired enumeration order (Enumerate2 uses LIFO).
	// Desired enum order: toString, concat, rgb, blueOffset, greenOffset, redOffset,
	//   alphaOffset, blueMultiplier, greenMultiplier, redMultiplier, alphaMultiplier
	// Insert order (first = last enumerated):
	//   alphaMultiplier, redMultiplier, greenMultiplier, blueMultiplier,
	//   alphaOffset, redOffset, greenOffset, blueOffset, rgb, concat, toString
	ActionVar one  = makeF64(1.0);
	ActionVar zero = makeF64(0.0);
	setProperty(app_context, g_color_transform_prototype, "alphaMultiplier", 15, &one);
	setProperty(app_context, g_color_transform_prototype, "redMultiplier",   13, &one);
	setProperty(app_context, g_color_transform_prototype, "greenMultiplier", 15, &one);
	setProperty(app_context, g_color_transform_prototype, "blueMultiplier",  14, &one);
	setProperty(app_context, g_color_transform_prototype, "alphaOffset",     11, &zero);
	setProperty(app_context, g_color_transform_prototype, "redOffset",        9, &zero);
	setProperty(app_context, g_color_transform_prototype, "greenOffset",     11, &zero);
	setProperty(app_context, g_color_transform_prototype, "blueOffset",      10, &zero);

	// rgb virtual property (addProperty getter/setter)
	memset(&g_ct_rgb_getter, 0, sizeof(ASFunction));
	g_ct_rgb_getter.function_type = 2;
	g_ct_rgb_getter.advanced_func = (Function2Ptr)ctRgbGetter;
	memset(&g_ct_rgb_setter, 0, sizeof(ASFunction));
	g_ct_rgb_setter.function_type = 2;
	g_ct_rgb_setter.advanced_func = (Function2Ptr)ctRgbSetter;
	setAddProperty(app_context, g_color_transform_prototype, "rgb", 3, &g_ct_rgb_getter, &g_ct_rgb_setter);

	// concat method (before toString so toString is last-inserted = first-enumerated)
	registerGeomMethod(&g_ct_methods[0], "concat",   (Function2Ptr)ctConcat,   app_context, g_color_transform_prototype);
	// toString method
	registerGeomMethod(&g_ct_methods[1], "toString", (Function2Ptr)ctToString, app_context, g_color_transform_prototype);
}

// flash.geom.ColorTransform constructor
// new ColorTransform(rMult, gMult, bMult, aMult, rOff, gOff, bOff, aOff)
// Defaults: 1, 1, 1, 1, 0, 0, 0, 0
static ActionVar colorTransformConstructor(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers;
	ASObject* obj = (ASObject*)this_obj;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	if (!obj) return undef;

	double rMult = (arg_count > 0) ? varToDoubleSimple(&args[0]) : 1.0;
	double gMult = (arg_count > 1) ? varToDoubleSimple(&args[1]) : 1.0;
	double bMult = (arg_count > 2) ? varToDoubleSimple(&args[2]) : 1.0;
	double aMult = (arg_count > 3) ? varToDoubleSimple(&args[3]) : 1.0;
	double rOff  = (arg_count > 4) ? varToDoubleSimple(&args[4]) : 0.0;
	double gOff  = (arg_count > 5) ? varToDoubleSimple(&args[5]) : 0.0;
	double bOff  = (arg_count > 6) ? varToDoubleSimple(&args[6]) : 0.0;
	double aOff  = (arg_count > 7) ? varToDoubleSimple(&args[7]) : 0.0;

	ActionVar v;
	v = makeF64(rMult); setProperty(app_context, obj, "redMultiplier",   13, &v);
	v = makeF64(gMult); setProperty(app_context, obj, "greenMultiplier", 15, &v);
	v = makeF64(bMult); setProperty(app_context, obj, "blueMultiplier",  14, &v);
	v = makeF64(aMult); setProperty(app_context, obj, "alphaMultiplier", 15, &v);
	v = makeF64(rOff);  setProperty(app_context, obj, "redOffset",        9, &v);
	v = makeF64(gOff);  setProperty(app_context, obj, "greenOffset",     11, &v);
	v = makeF64(bOff);  setProperty(app_context, obj, "blueOffset",      10, &v);
	v = makeF64(aOff);  setProperty(app_context, obj, "alphaOffset",     11, &v);
	return undef;
}

// Call just valueOf on an object. Returns the raw result (even if non-primitive).
// Sets *found=1 if valueOf was found and called, 0 otherwise.
// If the input is not an object, returns it unchanged with *found=0.
static ActionVar objectCallValueOf(SWFAppContext* app_context, ActionVar* obj_var, int* found)
{
	*found = 0;
	if (obj_var->data.numeric_value == 0)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	// For functions, use own_props (not the ASFunction struct) for property lookup
	ASObject* obj;
	if (obj_var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* fn = (ASFunction*) obj_var->data.numeric_value;
		obj = fn->own_props;
		if (obj == NULL) return *obj_var;  // No own_props, no valueOf
	}
	else if (obj_var->type == ACTION_STACK_VALUE_ARRAY)
	{
		// Arrays have a different struct layout — use props for property lookup
		ASArray* arr = (ASArray*) obj_var->data.numeric_value;
		obj = arr->props;
		if (obj == NULL) return *obj_var;  // No props, no valueOf
	}
	else
	{
		obj = (ASObject*) obj_var->data.numeric_value;
	}

	// Arrays only check own properties for valueOf (not inherited from Object.prototype)
	// This prevents Object.prototype.valueOf from hijacking array-to-primitive conversion.
	ActionVar* valueOf_prop = (obj_var->type == ACTION_STACK_VALUE_ARRAY)
	    ? getProperty(obj, "valueOf", 7)
	    : getPropertyWithPrototype(obj, "valueOf", 7);
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
		// valueOf is a non-callable object (e.g. obj.valueOf = {}) — treat as found,
		// return undefined to prevent fallback to toString
		else if (valueOf_prop->type == ACTION_STACK_VALUE_OBJECT ||
		         valueOf_prop->type == ACTION_STACK_VALUE_ARRAY)
		{
			*found = 1;
			ActionVar undef = {0};
			undef.type = ACTION_STACK_VALUE_UNDEFINED;
			return undef;
		}
	}
	return *obj_var;  // No valueOf found, return original
}

// Call just toString on an object. Returns the raw result.
// If found is non-NULL, sets *found = 1 if toString existed and was called, 0 otherwise.
static ActionVar objectCallToString(SWFAppContext* app_context, ActionVar* obj_var, int* found)
{
	if (found) *found = 0;
	if (obj_var->data.numeric_value == 0)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	// For functions, use own_props for property lookup
	ASObject* obj;
	if (obj_var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* fn = (ASFunction*) obj_var->data.numeric_value;
		obj = fn->own_props;
		if (obj == NULL)
		{
			ActionVar undef = {0};
			undef.type = ACTION_STACK_VALUE_UNDEFINED;
			return undef;
		}
	}
	else if (obj_var->type == ACTION_STACK_VALUE_ARRAY)
	{
		// Arrays have a different struct layout — use props for property lookup
		ASArray* arr = (ASArray*) obj_var->data.numeric_value;
		obj = arr->props;
		if (obj == NULL)
		{
			ActionVar undef = {0};
			undef.type = ACTION_STACK_VALUE_UNDEFINED;
			return undef;
		}
	}
	else
	{
		obj = (ASObject*) obj_var->data.numeric_value;
	}

	// Arrays only check own properties for toString (not inherited from Object.prototype)
	// This prevents Object.prototype.toString from returning '[object Object]' for arrays.
	ActionVar* toString_prop = (obj_var->type == ACTION_STACK_VALUE_ARRAY)
	    ? getProperty(obj, "toString", 8)
	    : getPropertyWithPrototype(obj, "toString", 8);
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

	if (obj_var->data.numeric_value == 0)
	{
		ActionVar undef = {0};
		undef.type = ACTION_STACK_VALUE_UNDEFINED;
		return undef;
	}

	// For functions, use own_props (not the function struct itself) for property lookup
	ASObject* obj;
	if (obj_var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* func = (ASFunction*) obj_var->data.numeric_value;
		obj = func->own_props;
		if (obj == NULL)
		{
			// No own_props — function has no valueOf/toString, return undefined
			if (out_success) *out_success = 0;
			ActionVar undef = {0};
			undef.type = ACTION_STACK_VALUE_UNDEFINED;
			return undef;
		}
	}
	else
	{
		obj = (ASObject*) obj_var->data.numeric_value;
	}

	// Try valueOf via prototype chain (finds Object.prototype.valueOf too)
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

				// valueOf returned non-primitive (e.g. Object.prototype.valueOf
				// returning `this`) — bail without falling through to toString.
				// Flash comparisons return false for bare objects.
				if (out_success) *out_success = 0;
				ActionVar undef = {0};
				undef.type = ACTION_STACK_VALUE_UNDEFINED;
				return undef;
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

	// No valueOf found at all — try toString as last resort
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

// --- Math.random (defined here after TRandomFast/RNG are available) ---

static ActionVar builtin_math_random(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	coerceMathArgs(app_context, args, arg_count, 2);
	// Generate [0, 1) using the avmplus-compatible RNG
	int32_t raw = GenerateRandomNumber(&global_random_state);
	double result = (double)(raw & 0x7FFFFFFF) / 2147483648.0;
	return mathReturnDouble(result);
}

// ==================================================================
// MovieClip Property Support (for SET_PROPERTY / GET_PROPERTY)
// ==================================================================

// MovieClip structure is defined in action.h

// Global object for ActionScript _global
// This is initialized on first use and persists for the lifetime of the runtime
ASObject* global_object = NULL;

// MovieClip constructor function (for MovieClip.prototype access)
ASFunction g_movieclip_constructor;
int g_movieclip_constructor_init = 0;

// MovieClip prototype method stubs (static storage)
#define MC_METHOD_COUNT 20
static ASFunction g_mc_method_funcs[MC_METHOD_COUNT];

static void initMovieClipPrototype(SWFAppContext* app_context)
{
	if (g_movieclip_constructor_init) return;

	memset(&g_movieclip_constructor, 0, sizeof(ASFunction));
	strncpy(g_movieclip_constructor.name, "MovieClip", 255);
	g_movieclip_constructor.function_type = 1;
	g_movieclip_constructor.param_count = 0;

	// Create prototype
	ASObject* proto = allocObject(app_context, 32);
	retainObject(proto);
	g_movieclip_constructor.prototype_obj = proto;

	// Set __proto__ to Object.prototype
	setObjectProto(app_context, proto);

	// Method stub names (DontEnum functions on MovieClip.prototype)
	static const struct { const char* name; u32 len; } mc_methods[MC_METHOD_COUNT] = {
		{"attachMovie", 11},
		{"createEmptyMovieClip", 20},
		{"createTextField", 15},
		{"duplicateMovieClip", 18},
		{"getBounds", 9},
		{"getBytesLoaded", 14},
		{"getBytesTotal", 13},
		{"getDepth", 8},
		{"getInstanceAtDepth", 18},
		{"getNextHighestDepth", 19},
		{"getSWFVersion", 13},
		{"getURL", 6},
		{"globalToLocal", 13},
		{"localToGlobal", 13},
		{"removeMovieClip", 15},
		{"setMask", 7},
		{"startDrag", 9},
		{"stopDrag", 8},
		{"swapDepths", 10},
		{"getTextSnapshot", 15},
	};

	memset(g_mc_method_funcs, 0, sizeof(g_mc_method_funcs));
	for (int i = 0; i < MC_METHOD_COUNT; i++)
	{
		strncpy(g_mc_method_funcs[i].name, mc_methods[i].name, 255);
		g_mc_method_funcs[i].function_type = 1;
		g_mc_method_funcs[i].param_count = 0;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_mc_method_funcs[i];

		ActionVar func_val = {0};
		func_val.type = ACTION_STACK_VALUE_FUNCTION;
		func_val.data.numeric_value = (u64) &g_mc_method_funcs[i];
		setProperty(app_context, proto, mc_methods[i].name, mc_methods[i].len, &func_val);
	}

	// Mark all methods and __proto__ as DontEnum
	for (u32 i = 0; i < proto->num_used; i++)
	{
		proto->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
	}

	g_movieclip_constructor_init = 1;
}

// TextField constructor function and prototype
static ASFunction g_textfield_constructor;
static int g_textfield_constructor_init = 0;
// TextField prototype method stubs (static storage)
static ASFunction g_tf_getTextFormat_func;
static ASFunction g_tf_setTextFormat_func;
static ASFunction g_tf_getNewTextFormat_func;
static ASFunction g_tf_setNewTextFormat_func;
static ASFunction g_tf_getDepth_func;
static ASFunction g_tf_removeTextField_func;
static ASFunction g_tf_replaceSel_func;
static ASFunction g_tf_replaceText_func;

// Helper: check if an ASObject is a bare TextField instance (created via new TextField())
static int isTextFieldInstance(ASObject* obj) {
	if (!g_textfield_constructor_init || g_textfield_constructor.prototype_obj == NULL) return 0;
	ActionVar* proto_var = getProperty(obj, "__proto__", 9);
	if (proto_var == NULL || proto_var->type != ACTION_STACK_VALUE_OBJECT) return 0;
	return (ASObject*)proto_var->data.numeric_value == g_textfield_constructor.prototype_obj;
}

// Helper: check if a property name is a native TextField property
// These properties are "virtual" on TextField — setting them on a bare new TextField() has no effect
// SWF7-: 30 native props (filters/sharpness/thickness/antiAliasType/gridFitType are settable)
// SWF8+: all 35 data properties are native
static int isNativeTextFieldProperty(const char* name, u32 len) {
	static const struct { const char* n; u32 l; } props[] = {
		{"styleSheet",10}, {"mouseWheelEnabled",17}, {"condenseWhite",13}, {"restrict",8},
		{"textHeight",10}, {"textWidth",9}, {"bottomScroll",12}, {"length",6},
		{"selectable",10}, {"multiline",9}, {"password",8}, {"wordWrap",8},
		{"background",10}, {"border",6}, {"html",4}, {"embedFonts",10},
		{"maxChars",8}, {"maxhscroll",10}, {"hscroll",7}, {"variable",8},
		{"htmlText",8}, {"type",4}, {"text",4}, {"autoSize",8},
		{"tabIndex",8}, {"textColor",9}, {"backgroundColor",15}, {"borderColor",11},
		{"maxscroll",9}, {"scroll",6},
		// SWF8+ only: these 5 also become native
		{"filters",7}, {"sharpness",9}, {"thickness",9}, {"antiAliasType",13}, {"gridFitType",11}
	};
	int count = (g_swf_version >= 8) ? 35 : 30;
	for (int i = 0; i < count; i++) {
		if (props[i].l == len && strncmp(name, props[i].n, len) == 0) return 1;
	}
	return 0;
}

static void initTextFieldPrototype(SWFAppContext* app_context)
{
	if (g_textfield_constructor_init) return;
	if (g_swf_version < 6) return; // TextField constructor doesn't exist in SWF5

	memset(&g_textfield_constructor, 0, sizeof(ASFunction));
	strncpy(g_textfield_constructor.name, "TextField", 255);
	g_textfield_constructor.function_type = 1;
	g_textfield_constructor.param_count = 0;

	// Create prototype with capacity for 35 properties + 8 methods + __proto__ + __constructor__
	ASObject* proto = allocObject(app_context, 48);
	retainObject(proto);
	g_textfield_constructor.prototype_obj = proto;

	// Set __proto__ to Object.prototype
	setObjectProto(app_context, proto);

	// Add 35 enumerable properties in the exact order Flash enumerates them.
	// All start as undefined on the prototype; instances shadow them with real values.
	ActionVar undef_val = {0};
	undef_val.type = ACTION_STACK_VALUE_UNDEFINED;

	static const char* tf_prop_names[] = {
		"styleSheet", "mouseWheelEnabled", "condenseWhite", "restrict",
		"textHeight", "textWidth", "bottomScroll", "length",
		"selectable", "multiline", "password", "wordWrap",
		"background", "border", "html", "embedFonts",
		"maxChars", "maxhscroll", "hscroll", "variable",
		"htmlText", "type", "text", "autoSize",
		"tabIndex", "textColor", "backgroundColor", "borderColor",
		"maxscroll", "scroll", "filters", "sharpness",
		"thickness", "antiAliasType", "gridFitType"
	};
	static const u32 tf_prop_lens[] = {
		10, 17, 13, 8,
		10, 9, 12, 6,
		10, 9, 8, 8,
		10, 6, 4, 10,
		8, 10, 7, 8,
		8, 4, 4, 8,
		8, 9, 15, 11,
		9, 6, 7, 9,
		9, 13, 11
	};

	// Register in REVERSE order so that for-in enumeration (LIFO stack) yields forward order.
	// Flash enumerates TextField props as: styleSheet first, gridFitType last.
	for (int i = 34; i >= 0; i--)
	{
		setProperty(app_context, proto, tf_prop_names[i], tf_prop_lens[i], &undef_val);
	}

	// Add 8 method functions (DontEnum — they don't show up in for..in)
	struct {
		const char* name;
		u32 name_len;
		ASFunction* func;
	} tf_methods[] = {
		{"getTextFormat", 13, &g_tf_getTextFormat_func},
		{"setTextFormat", 13, &g_tf_setTextFormat_func},
		{"getNewTextFormat", 16, &g_tf_getNewTextFormat_func},
		{"setNewTextFormat", 16, &g_tf_setNewTextFormat_func},
		{"getDepth", 8, &g_tf_getDepth_func},
		{"removeTextField", 15, &g_tf_removeTextField_func},
		{"replaceSel", 10, &g_tf_replaceSel_func},
		{"replaceText", 11, &g_tf_replaceText_func},
	};

	// replaceText (last entry) only exists in SWF7+
	int tf_method_count = (g_swf_version < 7) ? 7 : 8;
	for (int i = 0; i < tf_method_count; i++)
	{
		memset(tf_methods[i].func, 0, sizeof(ASFunction));
		strncpy(tf_methods[i].func->name, tf_methods[i].name, 255);
		tf_methods[i].func->function_type = 1;
		tf_methods[i].func->param_count = 0;

		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = tf_methods[i].func;

		ActionVar func_val = {0};
		func_val.type = ACTION_STACK_VALUE_FUNCTION;
		func_val.data.numeric_value = (u64) tf_methods[i].func;
		setProperty(app_context, proto, tf_methods[i].name, tf_methods[i].name_len, &func_val);
	}

	// Mark method properties and __proto__ as DontEnum
	for (u32 i = 0; i < proto->num_used; i++)
	{
		const char* pname = proto->properties[i].name;
		if (strcmp(pname, "__proto__") == 0 ||
		    strcmp(pname, "getTextFormat") == 0 ||
		    strcmp(pname, "setTextFormat") == 0 ||
		    strcmp(pname, "getNewTextFormat") == 0 ||
		    strcmp(pname, "setNewTextFormat") == 0 ||
		    strcmp(pname, "getDepth") == 0 ||
		    strcmp(pname, "removeTextField") == 0 ||
		    strcmp(pname, "replaceSel") == 0 ||
		    strcmp(pname, "replaceText") == 0)
		{
			proto->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
		}
	}

	// Register TextField.StyleSheet as a property on the constructor (SWF7+)
	if (g_swf_version >= 7)
	{
		static ASFunction g_stylesheet_ctor;
		memset(&g_stylesheet_ctor, 0, sizeof(ASFunction));
		strncpy(g_stylesheet_ctor.name, "StyleSheet", 255);
		g_stylesheet_ctor.function_type = 1;
		if (g_textfield_constructor.own_props == NULL)
		{
			g_textfield_constructor.own_props = allocObject(app_context, 4);
			retainObject(g_textfield_constructor.own_props);
		}
		ActionVar ss_val = {0};
		ss_val.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &ss_val.data.numeric_value) = (u64)&g_stylesheet_ctor;
		setProperty(app_context, g_textfield_constructor.own_props, "StyleSheet", 10, &ss_val);
	}

	g_textfield_constructor_init = 1;
}

// ============================================================
// TextFormat constructor and property coercion
// ============================================================
static ASFunction g_textformat_constructor;
static int g_textformat_constructor_init = 0;

// TextFormat property names (19 properties)
static const char* tf_prop_names[] = {
	"font", "size", "color", "bold", "italic", "underline",
	"align", "leftMargin", "rightMargin", "indent", "leading",
	"blockIndent", "bullet", "kerning", "letterSpacing", "tabStops",
	"url", "target", "display"
};
static const u32 tf_prop_lens[] = {
	4, 4, 5, 4, 6, 9,
	5, 10, 11, 6, 7,
	11, 6, 7, 13, 8,
	3, 6, 7
};
#define TF_PROP_COUNT 19
#define TF_FONT_MAX_LENGTH 64

// Coercion type enum
enum TFCoercionType {
	TF_COERCE_NONE = 0,
	TF_COERCE_STRING,     // font, url, target
	TF_COERCE_INTEGER,    // size, indent, leading, blockIndent
	TF_COERCE_NONNEG_INT, // leftMargin, rightMargin
	TF_COERCE_UNSIGNED,   // color
	TF_COERCE_FLOAT,      // letterSpacing
	TF_COERCE_BOOLEAN,    // bold, italic, underline, bullet, kerning
	TF_COERCE_ALIGN,      // align
	TF_COERCE_TABSTOPS,   // tabStops
	TF_COERCE_DISPLAY,    // display
};

static int getTextFormatCoercionType(const char* name, u32 len) {
	if (len == 4 && strncmp(name, "font", 4) == 0) return TF_COERCE_STRING;
	if (len == 3 && strncmp(name, "url", 3) == 0) return TF_COERCE_STRING;
	if (len == 6 && strncmp(name, "target", 6) == 0) return TF_COERCE_STRING;
	if (len == 4 && strncmp(name, "size", 4) == 0) return TF_COERCE_INTEGER;
	// SWF7 and below: indent/leading/blockIndent clamp negative to 0
	// SWF8+: allow negative values (plain integer coercion)
	if (len == 6 && strncmp(name, "indent", 6) == 0) return (g_swf_version < 8) ? TF_COERCE_NONNEG_INT : TF_COERCE_INTEGER;
	if (len == 7 && strncmp(name, "leading", 7) == 0) return (g_swf_version < 8) ? TF_COERCE_NONNEG_INT : TF_COERCE_INTEGER;
	if (len == 11 && strncmp(name, "blockIndent", 11) == 0) return (g_swf_version < 8) ? TF_COERCE_NONNEG_INT : TF_COERCE_INTEGER;
	if (len == 10 && strncmp(name, "leftMargin", 10) == 0) return TF_COERCE_NONNEG_INT;
	if (len == 11 && strncmp(name, "rightMargin", 11) == 0) return TF_COERCE_NONNEG_INT;
	if (len == 5 && strncmp(name, "color", 5) == 0) return TF_COERCE_UNSIGNED;
	if (len == 13 && strncmp(name, "letterSpacing", 13) == 0) return TF_COERCE_FLOAT;
	if (len == 4 && strncmp(name, "bold", 4) == 0) return TF_COERCE_BOOLEAN;
	if (len == 6 && strncmp(name, "italic", 6) == 0) return TF_COERCE_BOOLEAN;
	if (len == 9 && strncmp(name, "underline", 9) == 0) return TF_COERCE_BOOLEAN;
	if (len == 6 && strncmp(name, "bullet", 6) == 0) return TF_COERCE_BOOLEAN;
	if (len == 7 && strncmp(name, "kerning", 7) == 0) return TF_COERCE_BOOLEAN;
	if (len == 5 && strncmp(name, "align", 5) == 0) return TF_COERCE_ALIGN;
	if (len == 8 && strncmp(name, "tabStops", 8) == 0) return TF_COERCE_TABSTOPS;
	if (len == 7 && strncmp(name, "display", 7) == 0) return TF_COERCE_DISPLAY;
	return TF_COERCE_NONE;
}

// Helper: check if an ASObject is a TextFormat instance
static int isTextFormatInstance(ASObject* obj) {
	if (!g_textformat_constructor_init || g_textformat_constructor.prototype_obj == NULL) return 0;
	ActionVar* proto_var = getProperty(obj, "__proto__", 9);
	if (proto_var == NULL || proto_var->type != ACTION_STACK_VALUE_OBJECT) return 0;
	return (ASObject*)proto_var->data.numeric_value == g_textformat_constructor.prototype_obj;
}

// Banker's rounding (round half to even)
static double bankersRound(double x) {
	if (x != x) return x; // NaN
	double f = x - floor(x); // fractional part in [0, 1)
	if (fabs(f - 0.5) < 1e-10) {
		// Exactly 0.5 — round to even
		double down = floor(x);
		double up = down + 1.0;
		if (fmod(fabs(down), 2.0) < 0.5) return down; // down is even
		return up;
	}
	return round(x);
}

// Coerce value for TextFormat integer property (size, indent, leading, blockIndent)
static ActionVar tfCoerceInteger(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	double d = 0;
	if (value->type == ACTION_STACK_VALUE_F64)
		d = VAL(double, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_F32)
		d = (double) VAL(float, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_BOOLEAN)
		d = value->data.numeric_value ? 1.0 : 0.0;
	else if (value->type == ACTION_STACK_VALUE_STRING) {
		char _vtd_buf[512];
		const uint16_t* _vtd_u16 = varGetU16Ptr(value);
		u16_to_utf8(_vtd_u16, value->str_size, _vtd_buf, sizeof(_vtd_buf));
		d = atof(_vtd_buf);
	}
	else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		int _vof_found = 0;
		ActionVar vof = objectCallValueOf(app_context, value, &_vof_found);
		if (vof.type == ACTION_STACK_VALUE_F64)
			d = VAL(double, &vof.data.numeric_value);
		else if (vof.type == ACTION_STACK_VALUE_F32)
			d = (double) VAL(float, &vof.data.numeric_value);
		else
			d = 0.0 / 0.0; // NaN
	} else {
		d = 0.0 / 0.0; // NaN
	}
	// NaN, ±Infinity → -2147483648
	if (d != d || d == (1.0/0.0) || d == -(1.0/0.0)) {
		result.type = ACTION_STACK_VALUE_F64;
		double v = -2147483648.0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	if (g_swf_version < 8)
		d = (d >= 0) ? floor(d) : -floor(-d); // SWF7 and below: truncate toward zero
	else
		d = bankersRound(d); // SWF8+: banker's rounding (round half to even)
	// Out of int32 range → -2147483648
	if (d > 2147483647.0 || d < -2147483648.0) {
		result.type = ACTION_STACK_VALUE_F64;
		double v = -2147483648.0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	result.type = ACTION_STACK_VALUE_F64;
	double v = (double)(s32)d;
	result.data.numeric_value = VAL(u64, &v);
	return result;
}

// Coerce for non-negative integer (leftMargin, rightMargin)
static ActionVar tfCoerceNonNegInt(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	double d = 0;
	if (value->type == ACTION_STACK_VALUE_F64)
		d = VAL(double, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_F32)
		d = (double) VAL(float, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_BOOLEAN)
		d = value->data.numeric_value ? 1.0 : 0.0;
	else if (value->type == ACTION_STACK_VALUE_STRING) {
		char _vtd_buf[512];
		const uint16_t* _vtd_u16 = varGetU16Ptr(value);
		u16_to_utf8(_vtd_u16, value->str_size, _vtd_buf, sizeof(_vtd_buf));
		d = atof(_vtd_buf);
	}
	else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		int _vof_found = 0;
		ActionVar vof = objectCallValueOf(app_context, value, &_vof_found);
		if (vof.type == ACTION_STACK_VALUE_F64)
			d = VAL(double, &vof.data.numeric_value);
		else if (vof.type == ACTION_STACK_VALUE_F32)
			d = (double) VAL(float, &vof.data.numeric_value);
		else
			d = 0.0 / 0.0;
	} else {
		d = 0.0 / 0.0;
	}
	result.type = ACTION_STACK_VALUE_F64;
	// NaN → 0
	if (d != d) {
		double v = 0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	// +Infinity → -2147483648 (positive overflow, not clamped)
	if (d == (1.0/0.0)) {
		double v = -2147483648.0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	// -Infinity → 0 (negative, clamped)
	if (d == -(1.0/0.0)) {
		double v = 0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	if (g_swf_version < 8)
		d = (d >= 0) ? floor(d) : -floor(-d); // SWF7: truncate toward zero
	else
		d = bankersRound(d); // SWF8+: banker's rounding
	// Positive overflow → -2147483648
	if (d > 2147483647.0) {
		double v = -2147483648.0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	// Negative (including large negative overflow) → 0
	if (d < 0) {
		double v = 0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	double v = (double)(s32)d;
	result.data.numeric_value = VAL(u64, &v);
	return result;
}

// Coerce for unsigned integer (color)
static ActionVar tfCoerceUnsigned(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	double d = 0;
	if (value->type == ACTION_STACK_VALUE_F64)
		d = VAL(double, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_F32)
		d = (double) VAL(float, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_BOOLEAN)
		d = value->data.numeric_value ? 1.0 : 0.0;
	else if (value->type == ACTION_STACK_VALUE_STRING) {
		char _vtd_buf[512];
		const uint16_t* _vtd_u16 = varGetU16Ptr(value);
		u16_to_utf8(_vtd_u16, value->str_size, _vtd_buf, sizeof(_vtd_buf));
		d = atof(_vtd_buf);
	}
	else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		int _vof_found = 0;
		ActionVar vof = objectCallValueOf(app_context, value, &_vof_found);
		if (vof.type == ACTION_STACK_VALUE_F64)
			d = VAL(double, &vof.data.numeric_value);
		else if (vof.type == ACTION_STACK_VALUE_F32)
			d = (double) VAL(float, &vof.data.numeric_value);
		else
			d = 0.0 / 0.0;
	} else {
		d = 0.0 / 0.0;
	}
	// NaN, ±Infinity → 0
	if (d != d || d == (1.0/0.0) || d == -(1.0/0.0)) {
		result.type = ACTION_STACK_VALUE_F64;
		double v = 0;
		result.data.numeric_value = VAL(u64, &v);
		return result;
	}
	// ECMAScript ToUint32: truncate toward zero, then mod 2^32
	double truncated = (d >= 0) ? floor(d) : -floor(-d);
	double mod = fmod(truncated, 4294967296.0);
	if (mod < 0) mod += 4294967296.0;
	result.type = ACTION_STACK_VALUE_F64;
	result.data.numeric_value = VAL(u64, &mod);
	return result;
}

// Coerce for float (letterSpacing)
static ActionVar tfCoerceFloat(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	double d = 0;
	if (value->type == ACTION_STACK_VALUE_F64)
		d = VAL(double, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_F32)
		d = (double) VAL(float, &value->data.numeric_value);
	else if (value->type == ACTION_STACK_VALUE_BOOLEAN)
		d = value->data.numeric_value ? 1.0 : 0.0;
	else if (value->type == ACTION_STACK_VALUE_STRING) {
		char _vtd_buf[512];
		const uint16_t* _vtd_u16 = varGetU16Ptr(value);
		u16_to_utf8(_vtd_u16, value->str_size, _vtd_buf, sizeof(_vtd_buf));
		d = atof(_vtd_buf);
	}
	else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		int _vof_found = 0;
		ActionVar vof = objectCallValueOf(app_context, value, &_vof_found);
		if (vof.type == ACTION_STACK_VALUE_F64)
			d = VAL(double, &vof.data.numeric_value);
		else if (vof.type == ACTION_STACK_VALUE_F32)
			d = (double) VAL(float, &vof.data.numeric_value);
		else
			d = 0.0 / 0.0;
	} else {
		d = 0.0 / 0.0;
	}
	result.type = ACTION_STACK_VALUE_F64;
	result.data.numeric_value = VAL(u64, &d);
	return result;
}

// Coerce for string (font, url, target)
static ActionVar tfCoerceString(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	if (value->type == ACTION_STACK_VALUE_STRING) {
		result = *value;
		return result;
	}
	if (value->type == ACTION_STACK_VALUE_OBJECT) {
		ActionVar str_result = objectCallToString(app_context, value, NULL);
		if (str_result.type == ACTION_STACK_VALUE_STRING) return str_result;
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	// Number/bool → store raw value (Flash keeps original type for font/url/target)
	return *value;
}

// Coerce for boolean (bold, italic, underline, bullet, kerning)
static ActionVar tfCoerceBoolean(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	// Boolean coercion
	int b = 0;
	if (value->type == ACTION_STACK_VALUE_BOOLEAN)
		b = value->data.numeric_value ? 1 : 0;
	else if (value->type == ACTION_STACK_VALUE_F64) {
		double d = VAL(double, &value->data.numeric_value);
		b = (d != 0 && d == d) ? 1 : 0;
	} else if (value->type == ACTION_STACK_VALUE_F32) {
		float f = VAL(float, &value->data.numeric_value);
		b = (f != 0 && f == f) ? 1 : 0;
	} else if (value->type == ACTION_STACK_VALUE_STRING) {
		b = (value->str_size > 0) ? 1 : 0;
	} else if (value->type == ACTION_STACK_VALUE_OBJECT || value->type == ACTION_STACK_VALUE_ARRAY || value->type == ACTION_STACK_VALUE_FUNCTION) {
		b = 1;
	}
	result.type = ACTION_STACK_VALUE_BOOLEAN;
	result.data.numeric_value = b;
	return result;
}

// Coerce for align enum
static ActionVar tfCoerceAlign(SWFAppContext* app_context, ActionVar* value, ASObject* obj) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		// Setter: null/undefined → keep current (sentinel)
		result.type = 255;
		return result;
	}
	// Get string value
	char _align_buf[64];
	const char* s = NULL;
	u32 slen = 0;
	ActionVar _align_src = {0};
	if (value->type == ACTION_STACK_VALUE_STRING) {
		_align_src = *value;
	} else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		ActionVar str_result = objectCallToString(app_context, value, NULL);
		if (str_result.type == ACTION_STACK_VALUE_STRING) {
			_align_src = str_result;
		}
	}
	if (_align_src.type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _align_u16 = varGetU16Ptr(&_align_src);
		u16_to_utf8(_align_u16, _align_src.str_size, _align_buf, sizeof(_align_buf));
		s = _align_buf;
		slen = _align_src.str_size;
	}
	if (s != NULL) {
		// Valid values: "left", "center", "right", "justify"
		if ((slen == 4 && strncmp(s, "left", 4) == 0) ||
		    (slen == 6 && strncmp(s, "center", 6) == 0) ||
		    (slen == 5 && strncmp(s, "right", 5) == 0) ||
		    (slen == 7 && strncmp(s, "justify", 7) == 0)) {
			result.type = ACTION_STACK_VALUE_STRING;
			result.data.numeric_value = _align_src.data.numeric_value;
			result.str_size = slen;
			return result;
		}
	}
	// Invalid value — keep current (return a sentinel to indicate "no change")
	result.type = 255; // sentinel
	return result;
}

// Coerce for tabStops (array)
static ActionVar tfCoerceTabStops(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_NULL || value->type == ACTION_STACK_VALUE_UNDEFINED) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	// Get array length and element access
	u32 len = 0;
	ASArray* src_arr = NULL;
	ASObject* src_obj = NULL;
	if (value->type == ACTION_STACK_VALUE_ARRAY) {
		src_arr = (ASArray*) value->data.numeric_value;
		if (src_arr) len = src_arr->length;
	} else if (value->type == ACTION_STACK_VALUE_OBJECT) {
		// Array-like object with length property
		src_obj = (ASObject*) value->data.numeric_value;
		ActionVar* len_var = getProperty(src_obj, "length", 6);
		if (len_var && len_var->type == ACTION_STACK_VALUE_F64)
			len = (u32) VAL(double, &len_var->data.numeric_value);
		else if (len_var && len_var->type == ACTION_STACK_VALUE_F32)
			len = (u32) VAL(float, &len_var->data.numeric_value);
		else {
			result.type = ACTION_STACK_VALUE_NULL;
			return result;
		}
	} else {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	// Create new array with coerced elements
	ASArray* new_arr = allocArray(app_context, len);
	for (u32 i = 0; i < len; i++) {
		ActionVar elem = {0};
		elem.type = ACTION_STACK_VALUE_UNDEFINED;
		if (src_arr) {
			ActionVar* e = getArrayElement(src_arr, i);
			if (e) elem = *e;
		} else if (src_obj) {
			char idx_buf[12];
			snprintf(idx_buf, sizeof(idx_buf), "%u", i);
			ActionVar* e = getProperty(src_obj, idx_buf, strlen(idx_buf));
			if (e) elem = *e;
		}
		// Coerce element to integer (same as tfCoerceInteger)
		ActionVar coerced = tfCoerceInteger(app_context, &elem);
		setArrayElement(app_context, new_arr, i, &coerced);
	}
	result.type = ACTION_STACK_VALUE_ARRAY;
	result.data.numeric_value = (u64) new_arr;
	return result;
}

// Coerce for display enum: "block", "inline", "none" only. Invalid/null/undefined → "block".
static ActionVar tfCoerceDisplay(SWFAppContext* app_context, ActionVar* value) {
	ActionVar result = {0};
	if (value->type == ACTION_STACK_VALUE_STRING) {
		char _disp_buf[64];
		const uint16_t* _disp_u16 = varGetU16Ptr(value);
		u16_to_utf8(_disp_u16, value->str_size, _disp_buf, sizeof(_disp_buf));
		u32 slen = value->str_size;
		if ((slen == 5 && strncmp(_disp_buf, "block", 5) == 0) ||
		    (slen == 6 && strncmp(_disp_buf, "inline", 6) == 0) ||
		    (slen == 4 && strncmp(_disp_buf, "none", 4) == 0)) {
			return *value;
		}
	}
	// null/undefined/invalid → "block"
	result.type = ACTION_STACK_VALUE_STRING;
	result.data.numeric_value = (u64) u16_block;
	result.str_size = 5;
	return result;
}

// Apply TextFormat property coercion and set. Returns 1 if handled, 0 if not a TextFormat property.
static int textFormatSetProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_len, ActionVar* value) {
	int coercion = getTextFormatCoercionType(name, name_len);
	if (coercion == TF_COERCE_NONE) return 0;

	ActionVar coerced;
	switch (coercion) {
		case TF_COERCE_STRING:     coerced = tfCoerceString(app_context, value); break;
		case TF_COERCE_INTEGER:    coerced = tfCoerceInteger(app_context, value); break;
		case TF_COERCE_NONNEG_INT: coerced = tfCoerceNonNegInt(app_context, value); break;
		case TF_COERCE_UNSIGNED:   coerced = tfCoerceUnsigned(app_context, value); break;
		case TF_COERCE_FLOAT:      coerced = tfCoerceFloat(app_context, value); break;
		case TF_COERCE_BOOLEAN:    coerced = tfCoerceBoolean(app_context, value); break;
		case TF_COERCE_ALIGN:      coerced = tfCoerceAlign(app_context, value, obj); break;
		case TF_COERCE_TABSTOPS:   coerced = tfCoerceTabStops(app_context, value); break;
		case TF_COERCE_DISPLAY:    coerced = tfCoerceDisplay(app_context, value); break;
		default: return 0;
	}
	// Sentinel for align/display: invalid value → don't change
	if (coerced.type == 255) return 1;
	// Font name truncation to 64 chars
	if (coercion == TF_COERCE_STRING && name_len == 4 && strncmp(name, "font", 4) == 0 &&
	    coerced.type == ACTION_STACK_VALUE_STRING) {
		if (coerced.str_size > TF_FONT_MAX_LENGTH) {
			const uint16_t* _tf_trunc_u16 = varGetU16Ptr(&coerced);
			uint16_t* truncated = (uint16_t*) malloc((TF_FONT_MAX_LENGTH + 1) * sizeof(uint16_t));
			memcpy(truncated, _tf_trunc_u16, TF_FONT_MAX_LENGTH * sizeof(uint16_t));
			truncated[TF_FONT_MAX_LENGTH] = 0;
			coerced.data.numeric_value = (u64) truncated;
			coerced.str_size = TF_FONT_MAX_LENGTH;
		}
	}
	setProperty(app_context, obj, name, name_len, &coerced);
	return 1;
}

static void initTextFormatPrototype(SWFAppContext* app_context);

#ifdef NO_GRAPHICS
// Create a TextFormat object populated from a textfield's metadata.
// If tf_idx < 0, returns a TextFormat with default values (for dynamic/non-EditText fields).
// If is_new_text_format is true, always populates all properties (getNewTextFormat behavior).
// If is_new_text_format is false, only populates if field has text (getTextFormat behavior).
// override_align: -1 = use tag-defined alignment; 0-3 = force left/right/center/justify.
static ASObject* createTextFormatFromField(SWFAppContext* app_context, int tf_idx, int has_text, int is_new_text_format, int override_align) {
	initTextFormatPrototype(app_context);
	ASObject* tf_obj = allocObject(app_context, 24);
	if (g_textformat_constructor.prototype_obj != NULL) {
		ActionVar proto_var = {0};
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.data.numeric_value = (u64) g_textformat_constructor.prototype_obj;
		setProperty(app_context, tf_obj, "__proto__", 9, &proto_var);
		for (u32 i = 0; i < tf_obj->num_used; i++) {
			if (strcmp(tf_obj->properties[i].name, "__proto__") == 0) {
				tf_obj->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
				break;
			}
		}
	}

	// If getTextFormat on empty field, return all-null TextFormat
	if (!is_new_text_format && !has_text) {
		ActionVar null_val = {0};
		null_val.type = ACTION_STACK_VALUE_NULL;
		for (int i = 0; i < TF_PROP_COUNT; i++)
			setProperty(app_context, tf_obj, tf_prop_names[i], tf_prop_lens[i], &null_val);
		return tf_obj;
	}

	// Populate properties from textfield metadata
	ActionVar val = {0};

	// align
	{
		const uint16_t* align_u16 = u16_left;
		u32 align_u16_len = 4;
		int a = 0; // default: left
		if (override_align >= 0) {
			a = override_align; // caller-computed HTML-aware alignment
		} else if (tf_idx >= 0) {
			a = (int) ng_getTextFieldAlign(tf_idx); // tag-defined alignment
		}
		if (a == 1) { align_u16 = u16_right; align_u16_len = 5; }
		else if (a == 2) { align_u16 = u16_center; align_u16_len = 6; }
		else if (a == 3) { align_u16 = u16_justify; align_u16_len = 7; }
		val.type = ACTION_STACK_VALUE_STRING;
		val.data.numeric_value = (u64) align_u16;
		val.str_size = align_u16_len;
		setProperty(app_context, tf_obj, "align", 5, &val);
	}

	// font
	{
		const char* font_name = "Times New Roman";
		if (tf_idx >= 0) {
			u16 fid = ng_getTextFieldFontId(tf_idx);
			const char* fn = ng_getFontName(fid);
			if (fn[0] != '\0') font_name = fn;
		}
		u32 _fn_u16_len;
		uint16_t* _fn_u16 = ascii_to_u16(app_context, font_name, (int)strlen(font_name), &_fn_u16_len);
		val.type = ACTION_STACK_VALUE_STRING;
		val.data.numeric_value = (u64) _fn_u16;
		val.str_size = _fn_u16_len;
		setProperty(app_context, tf_obj, "font", 4, &val);
	}

	// size (font_height in twips → pixels: / 20)
	// Default to 12 when HasFont is false (font_height=0)
	double font_size = 12.0;
	if (tf_idx >= 0) {
		u16 raw_height = ng_getTextFieldFontHeight(tf_idx);
		if (raw_height > 0)
			font_size = (double)raw_height / 20.0;
	}
	val.type = ACTION_STACK_VALUE_F64;
	VAL(double, &val.data.numeric_value) = font_size;
	val.str_size = 0;
	setProperty(app_context, tf_obj, "size", 4, &val);

	// color
	double color_val_d = 0.0;
	if (tf_idx >= 0) {
		// ng_getTextFieldColor returns by depth, but we have tf_idx.
		// Use the stored text_color from ng_textfields directly.
		extern u32 ng_getTextFieldColorByIdx(int idx);
		color_val_d = (double)ng_getTextFieldColorByIdx(tf_idx);
	}
	val.type = ACTION_STACK_VALUE_F64;
	VAL(double, &val.data.numeric_value) = color_val_d;
	setProperty(app_context, tf_obj, "color", 5, &val);

	// bold, italic
	// For HTML fields: derive from HTML markup, not font flags
	// If HTML has mixed formatting (e.g., some <b> tagged, some not), return null
	int bold_is_null = 0, italic_is_null = 0;
	int is_bold = 0, is_italic = 0;
	if (tf_idx >= 0) {
		u16 tf_flags_bi = ng_getTextFieldFlags(tf_idx);
		if (tf_flags_bi & 0x0040) {
			// HTML field: check raw HTML for mixed bold/italic
			const char* raw_html_bi = ng_getTextFieldRawHtml(tf_idx);
			int has_b_tag = (strstr(raw_html_bi, "<b>") != NULL || strstr(raw_html_bi, "<B>") != NULL);
			int has_i_tag = (strstr(raw_html_bi, "<i>") != NULL || strstr(raw_html_bi, "<I>") != NULL);
			// If tag exists but doesn't wrap ALL content → mixed → null
			if (has_b_tag) {
				// Check if entire content is wrapped in <b>
				if (strncmp(raw_html_bi, "<b>", 3) == 0 || strncmp(raw_html_bi, "<B>", 3) == 0) {
					is_bold = 1;  // all bold
				} else {
					bold_is_null = 1;  // mixed
				}
			}
			// else: no <b> tag → is_bold stays 0 (false)
			if (has_i_tag) {
				if (strncmp(raw_html_bi, "<i>", 3) == 0 || strncmp(raw_html_bi, "<I>", 3) == 0) {
					is_italic = 1;  // all italic
				} else {
					italic_is_null = 1;  // mixed
				}
			}
		} else {
			// Non-HTML field: use font flags
			u16 fid = ng_getTextFieldFontId(tf_idx);
			is_bold = ng_getFontBold(fid);
			is_italic = ng_getFontItalic(fid);
		}
	}
	val.str_size = 0;
	if (bold_is_null) {
		val.type = ACTION_STACK_VALUE_NULL;
		val.data.numeric_value = 0;
	} else {
		val.type = ACTION_STACK_VALUE_BOOLEAN;
		val.data.numeric_value = is_bold ? 1 : 0;
	}
	setProperty(app_context, tf_obj, "bold", 4, &val);
	if (italic_is_null) {
		val.type = ACTION_STACK_VALUE_NULL;
		val.data.numeric_value = 0;
	} else {
		val.type = ACTION_STACK_VALUE_BOOLEAN;
		val.data.numeric_value = is_italic ? 1 : 0;
	}
	setProperty(app_context, tf_obj, "italic", 6, &val);

	// underline (default false)
	val.type = ACTION_STACK_VALUE_BOOLEAN;
	val.data.numeric_value = 0;
	setProperty(app_context, tf_obj, "underline", 9, &val);

	// bullet (default false)
	setProperty(app_context, tf_obj, "bullet", 6, &val);

	// kerning: for getTextFormat, parse from HTML kerning="1" attribute; for getNewTextFormat, default false
	{
		int kerning_val = 0;
		if (!is_new_text_format && tf_idx >= 0) {
			const char* raw_html = ng_getTextFieldRawHtml(tf_idx);
			if (raw_html != NULL) {
				const char* kattr = strstr(raw_html, "kerning=\"");
				if (kattr != NULL) {
					kattr += 9; // skip past 'kerning="'
					if (*kattr == '1') kerning_val = 1;
				}
			}
		}
		val.data.numeric_value = kerning_val;
	}
	setProperty(app_context, tf_obj, "kerning", 7, &val);

	// leading (twips → pixels)
	double leading_px = 0.0;
	if (tf_idx >= 0) {
		leading_px = (double)ng_getTextFieldLeading(tf_idx) / 20.0;
	}
	val.type = ACTION_STACK_VALUE_F64;
	VAL(double, &val.data.numeric_value) = leading_px;
	setProperty(app_context, tf_obj, "leading", 7, &val);

	// leftMargin (twips → pixels)
	double lm_px = 0.0;
	if (tf_idx >= 0) {
		lm_px = (double)ng_getTextFieldLeftMargin(tf_idx) / 20.0;
	}
	VAL(double, &val.data.numeric_value) = lm_px;
	setProperty(app_context, tf_obj, "leftMargin", 10, &val);

	// rightMargin (twips → pixels)
	double rm_px = 0.0;
	if (tf_idx >= 0) {
		rm_px = (double)ng_getTextFieldRightMargin(tf_idx) / 20.0;
	}
	VAL(double, &val.data.numeric_value) = rm_px;
	setProperty(app_context, tf_obj, "rightMargin", 11, &val);

	// indent (twips → pixels)
	double indent_px = 0.0;
	if (tf_idx >= 0) {
		indent_px = (double)ng_getTextFieldIndent(tf_idx) / 20.0;
	}
	VAL(double, &val.data.numeric_value) = indent_px;
	setProperty(app_context, tf_obj, "indent", 6, &val);

	// blockIndent (default 0)
	VAL(double, &val.data.numeric_value) = 0.0;
	setProperty(app_context, tf_obj, "blockIndent", 11, &val);

	// letterSpacing (default 0)
	VAL(double, &val.data.numeric_value) = 0.0;
	setProperty(app_context, tf_obj, "letterSpacing", 13, &val);

	// tabStops (empty array)
	ASArray* empty_arr = allocArray(app_context, 0);
	val.type = ACTION_STACK_VALUE_ARRAY;
	val.data.numeric_value = (u64) empty_arr;
	setProperty(app_context, tf_obj, "tabStops", 8, &val);

	// target (empty string)
	val.type = ACTION_STACK_VALUE_STRING;
	val.data.numeric_value = (u64) u16_empty;
	val.str_size = 0;
	setProperty(app_context, tf_obj, "target", 6, &val);

	// url (empty string)
	val.data.numeric_value = (u64) u16_empty;
	val.str_size = 0;
	setProperty(app_context, tf_obj, "url", 3, &val);

	// display (default "block")
	val.data.numeric_value = (u64) u16_block;
	val.str_size = 5;
	setProperty(app_context, tf_obj, "display", 7, &val);

	return tf_obj;
}
#endif

static void initTextFormatPrototype(SWFAppContext* app_context) {
	if (g_textformat_constructor_init) return;

	memset(&g_textformat_constructor, 0, sizeof(ASFunction));
	strncpy(g_textformat_constructor.name, "TextFormat", 255);
	g_textformat_constructor.function_type = 1;
	g_textformat_constructor.param_count = 0;

	// Create prototype object
	ASObject* proto = allocObject(app_context, 12);
	g_textformat_constructor.prototype_obj = proto;

	// Set __proto__ to Object.prototype
	extern ASObject* g_object_prototype;
	if (g_object_prototype != NULL) {
		ActionVar proto_val = {0};
		proto_val.type = ACTION_STACK_VALUE_OBJECT;
		proto_val.data.numeric_value = (u64) g_object_prototype;
		setProperty(app_context, proto, "__proto__", 9, &proto_val);
	}

	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = &g_textformat_constructor;

	g_textformat_constructor_init = 1;
}

// ============================================================
// XML / XMLNode Implementation
// ============================================================

static ASFunction g_xml_constructor;
static ASFunction g_xmlnode_constructor;
static int g_xml_constructor_init = 0;

// Forward declarations
static void initXMLPrototype(SWFAppContext* app_context);

// Static method ASFunctions for XMLNode.prototype
static ASFunction g_xml_fn_parseXML;
static ASFunction g_xml_fn_createElement;
static ASFunction g_xml_fn_createTextNode;
static ASFunction g_xml_fn_appendChild;
static ASFunction g_xml_fn_removeNode;
static ASFunction g_xml_fn_insertBefore;
static ASFunction g_xml_fn_hasChildNodes;
static ASFunction g_xml_fn_cloneNode;
static ASFunction g_xml_fn_toString;
static ASFunction g_xml_fn_getNamespaceForPrefix;
static ASFunction g_xml_fn_getPrefixForNamespace;
static ASFunction g_xml_fn_getBytesLoaded;
static ASFunction g_xml_fn_getBytesTotal;

// Check if obj is an XML/XMLNode instance (walks __proto__ chain)
static int isXMLNodeInstance(ASObject* obj) {
	if (!g_xml_constructor_init || g_xmlnode_constructor.prototype_obj == NULL) return 0;
	ActionVar* pv = getProperty(obj, "__proto__", 9);
	int depth = 0;
	while (pv != NULL && pv->type == ACTION_STACK_VALUE_OBJECT && depth < 10) {
		ASObject* proto = (ASObject*) pv->data.numeric_value;
		if (proto == NULL) break;
		if (proto == g_xmlnode_constructor.prototype_obj) return 1;
		pv = getProperty(proto, "__proto__", 9);
		depth++;
	}
	return 0;
}

// Allocate a persistent string copy
static char* xml_strdup(SWFAppContext* app_context, const char* s, u32 len) {
	(void)app_context;
	char* c = (char*) malloc(len + 1);
	memcpy(c, s, len);
	c[len] = '\0';
	return c;
}

// Set a null-valued property
static void xml_set_null(SWFAppContext* ctx, ASObject* obj, const char* name, u32 nlen) {
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_NULL;
	setProperty(ctx, obj, name, nlen, &v);
}

// Set an object-valued property
static void xml_set_obj(SWFAppContext* ctx, ASObject* obj, const char* name, u32 nlen, ASObject* val) {
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_OBJECT;
	v.data.numeric_value = (u64) val;
	setProperty(ctx, obj, name, nlen, &v);
}

// Set a string-valued property (makes a copy of the string, converts UTF-8 to UTF-16)
static void xml_set_str(SWFAppContext* ctx, ASObject* obj, const char* name, u32 nlen, const char* val, u32 vlen) {
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_STRING;
	u32 u16_len = 0;
	uint16_t* u16_copy = utf8_to_u16(ctx, val, vlen, &u16_len);
	v.str_size = u16_len;
	v.data.numeric_value = (u64) u16_copy;
	setProperty(ctx, obj, name, nlen, &v);
}

// Create a new XML node
static ASObject* xml_create_node(SWFAppContext* app_context, int nodeType,
                                  const char* nodeName, u32 nameLen,
                                  const char* nodeValue, u32 valueLen) {
	initXMLPrototype(app_context);
	ASObject* node = allocObject(app_context, 20);

	// Set __proto__ to XMLNode.prototype
	if (g_xmlnode_constructor.prototype_obj != NULL) {
		ActionVar pv = {0};
		pv.type = ACTION_STACK_VALUE_OBJECT;
		pv.data.numeric_value = (u64) g_xmlnode_constructor.prototype_obj;
		setProperty(app_context, node, "__proto__", 9, &pv);
	}

	// nodeType
	ActionVar nt = {0};
	nt.type = ACTION_STACK_VALUE_F64;
	VAL(double, &nt.data.numeric_value) = (double) nodeType;
	setProperty(app_context, node, "nodeType", 8, &nt);

	// nodeName
	if (nodeName != NULL) {
		xml_set_str(app_context, node, "nodeName", 8, nodeName, nameLen);
	} else {
		xml_set_null(app_context, node, "nodeName", 8);
	}

	// nodeValue
	if (nodeValue != NULL) {
		xml_set_str(app_context, node, "nodeValue", 9, nodeValue, valueLen);
	} else {
		xml_set_null(app_context, node, "nodeValue", 9);
	}

	// Navigation — all null initially
	xml_set_null(app_context, node, "parentNode", 10);
	xml_set_null(app_context, node, "firstChild", 10);
	xml_set_null(app_context, node, "lastChild", 9);
	xml_set_null(app_context, node, "previousSibling", 15);
	xml_set_null(app_context, node, "nextSibling", 11);

	// childNodes — empty array
	ASArray* children = allocArray(app_context, 0);
	ActionVar cn = {0};
	cn.type = ACTION_STACK_VALUE_ARRAY;
	cn.data.numeric_value = (u64) children;
	setProperty(app_context, node, "childNodes", 10, &cn);

	// attributes — always an object (Flash has attributes defined on text nodes too)
	{
		ASObject* attrs = allocObject(app_context, 4);
		xml_set_obj(app_context, node, "attributes", 10, attrs);
	}

	// Namespace properties — parse prefix:localName from nodeName
	if (nodeType == 1 && nodeName != NULL) {
		// Look for ':' separator
		const char* colon = NULL;
		for (u32 i = 0; i < nameLen; i++) {
			if (nodeName[i] == ':') { colon = &nodeName[i]; break; }
		}
		if (colon != NULL) {
			u32 prefix_len = (u32)(colon - nodeName);
			u32 local_len = nameLen - prefix_len - 1;
			xml_set_str(app_context, node, "prefix", 6, nodeName, prefix_len);
			xml_set_str(app_context, node, "localName", 9, colon + 1, local_len);
		} else {
			xml_set_str(app_context, node, "prefix", 6, "", 0);
			xml_set_str(app_context, node, "localName", 9, nodeName, nameLen);
		}
		xml_set_null(app_context, node, "namespaceURI", 12);
	} else {
		xml_set_null(app_context, node, "prefix", 6);
		xml_set_null(app_context, node, "localName", 9);
		xml_set_null(app_context, node, "namespaceURI", 12);
	}

	return node;
}

// Sync firstChild/lastChild/sibling links from childNodes array
static void xml_sync_children(SWFAppContext* app_context, ASObject* parent) {
	ActionVar* cn_prop = getProperty(parent, "childNodes", 10);
	if (cn_prop == NULL || cn_prop->type != ACTION_STACK_VALUE_ARRAY) return;
	ASArray* children = (ASArray*) cn_prop->data.numeric_value;
	if (children == NULL) return;

	u32 count = children->length;
	if (count == 0) {
		xml_set_null(app_context, parent, "firstChild", 10);
		xml_set_null(app_context, parent, "lastChild", 9);
		return;
	}

	for (u32 i = 0; i < count; i++) {
		ASObject* child = NULL;
		if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT)
			child = (ASObject*) children->elements[i].data.numeric_value;
		if (child == NULL) continue;

		xml_set_obj(app_context, child, "parentNode", 10, parent);

		if (i == 0)
			xml_set_null(app_context, child, "previousSibling", 15);
		else
			xml_set_obj(app_context, child, "previousSibling", 15,
				(ASObject*) children->elements[i-1].data.numeric_value);

		if (i == count - 1)
			xml_set_null(app_context, child, "nextSibling", 11);
		else
			xml_set_obj(app_context, child, "nextSibling", 11,
				(ASObject*) children->elements[i+1].data.numeric_value);
	}

	xml_set_obj(app_context, parent, "firstChild", 10,
		(ASObject*) children->elements[0].data.numeric_value);
	xml_set_obj(app_context, parent, "lastChild", 9,
		(ASObject*) children->elements[count-1].data.numeric_value);
}

// Check if 'ancestor' is an ancestor of 'node' (circular reference check)
static int xml_is_ancestor(ASObject* node, ASObject* ancestor) {
	ActionVar* pv = getProperty(node, "parentNode", 10);
	int depth = 0;
	while (pv != NULL && pv->type == ACTION_STACK_VALUE_OBJECT && depth < 100) {
		ASObject* p = (ASObject*) pv->data.numeric_value;
		if (p == NULL) break;
		if (p == ancestor) return 1;
		pv = getProperty(p, "parentNode", 10);
		depth++;
	}
	return 0;
}

// Remove a node from its parent
static void xml_do_remove(SWFAppContext* app_context, ASObject* node) {
	ActionVar* pp = getProperty(node, "parentNode", 10);
	if (pp == NULL || pp->type != ACTION_STACK_VALUE_OBJECT) return;
	ASObject* parent = (ASObject*) pp->data.numeric_value;
	if (parent == NULL) return;

	ActionVar* cn_prop = getProperty(parent, "childNodes", 10);
	if (cn_prop == NULL || cn_prop->type != ACTION_STACK_VALUE_ARRAY) return;
	ASArray* children = (ASArray*) cn_prop->data.numeric_value;
	if (children == NULL) return;

	// Find and remove from array
	for (u32 i = 0; i < children->length; i++) {
		if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT &&
			(ASObject*) children->elements[i].data.numeric_value == node) {
			// Shift remaining elements
			for (u32 j = i; j < children->length - 1; j++)
				children->elements[j] = children->elements[j + 1];
			children->length--;
			break;
		}
	}

	// Clear this node's links
	xml_set_null(app_context, node, "parentNode", 10);
	xml_set_null(app_context, node, "previousSibling", 15);
	xml_set_null(app_context, node, "nextSibling", 11);

	// Rebuild parent's links
	xml_sync_children(app_context, parent);
}

// Append child to parent
static void xml_do_append(SWFAppContext* app_context, ASObject* parent, ASObject* child) {
	if (parent == child) return;
	if (xml_is_ancestor(parent, child)) return;

	// Check existing parent
	ActionVar* pp = getProperty(child, "parentNode", 10);
	if (pp != NULL && pp->type == ACTION_STACK_VALUE_OBJECT && pp->data.numeric_value != 0) {
		ASObject* old_parent = (ASObject*) pp->data.numeric_value;
		if (old_parent == parent) return; // Already a child of this parent — no-op (Flash behavior)
		xml_do_remove(app_context, child);
	}

	// Add to childNodes array
	ActionVar* cn_prop = getProperty(parent, "childNodes", 10);
	if (cn_prop == NULL || cn_prop->type != ACTION_STACK_VALUE_ARRAY) return;
	ASArray* children = (ASArray*) cn_prop->data.numeric_value;
	if (children == NULL) return;

	// Purge elements that were added directly via Array.push() without going through
	// DOM APIs. Such elements have no parentNode set (or a wrong parentNode).
	// Flash rebuilds childNodes from actual DOM children when appendChild is called.
	{
		u32 write = 0;
		for (u32 i = 0; i < children->length; i++) {
			int keep = 1;
			if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT) {
				ASObject* elem = (ASObject*) children->elements[i].data.numeric_value;
				if (elem != NULL) {
					ActionVar* elem_pp = getProperty(elem, "parentNode", 10);
					// Keep only elements whose parentNode points to this parent
					if (elem_pp == NULL ||
					    elem_pp->type != ACTION_STACK_VALUE_OBJECT ||
					    (ASObject*)elem_pp->data.numeric_value != parent) {
						keep = 0;
					}
				}
			}
			if (keep)
				children->elements[write++] = children->elements[i];
		}
		children->length = write;
	}

	// Grow array if needed (allocArray uses malloc, so we must use realloc/free here)
	if (children->length >= children->capacity) {
		u32 new_cap = children->capacity < 4 ? 4 : children->capacity * 2;
		ActionVar* new_elems = (ActionVar*) realloc(children->elements, new_cap * sizeof(ActionVar));
		if (new_elems == NULL) return;
		// Zero out the new portion
		memset(&new_elems[children->capacity], 0, (new_cap - children->capacity) * sizeof(ActionVar));
		children->elements = new_elems;
		children->capacity = new_cap;
	}

	ActionVar cv = {0};
	cv.type = ACTION_STACK_VALUE_OBJECT;
	cv.data.numeric_value = (u64) child;
	children->elements[children->length++] = cv;

	xml_sync_children(app_context, parent);
}

// Insert newChild before refChild in parent
static void xml_do_insert_before(SWFAppContext* app_context, ASObject* parent,
                                  ASObject* newChild, ASObject* refChild) {
	if (parent == newChild) return;
	if (xml_is_ancestor(parent, newChild)) return;

	// Check existing parent
	ActionVar* pp = getProperty(newChild, "parentNode", 10);
	if (pp != NULL && pp->type == ACTION_STACK_VALUE_OBJECT && pp->data.numeric_value != 0) {
		ASObject* old_parent = (ASObject*) pp->data.numeric_value;
		if (old_parent == parent) return; // Already a child of this parent — no-op
		xml_do_remove(app_context, newChild);
	}

	ActionVar* cn_prop = getProperty(parent, "childNodes", 10);
	if (cn_prop == NULL || cn_prop->type != ACTION_STACK_VALUE_ARRAY) return;
	ASArray* children = (ASArray*) cn_prop->data.numeric_value;
	if (children == NULL) return;

	// Find refChild position
	u32 pos = children->length; // default: append
	for (u32 i = 0; i < children->length; i++) {
		if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT &&
			(ASObject*) children->elements[i].data.numeric_value == refChild) {
			pos = i;
			break;
		}
	}

	// Grow if needed (allocArray uses malloc, so we must use realloc/free here)
	if (children->length >= children->capacity) {
		u32 new_cap = children->capacity < 4 ? 4 : children->capacity * 2;
		ActionVar* new_elems = (ActionVar*) realloc(children->elements, new_cap * sizeof(ActionVar));
		if (new_elems == NULL) return;
		memset(&new_elems[children->capacity], 0, (new_cap - children->capacity) * sizeof(ActionVar));
		children->elements = new_elems;
		children->capacity = new_cap;
	}

	// Shift elements to make room
	for (u32 i = children->length; i > pos; i--)
		children->elements[i] = children->elements[i - 1];

	ActionVar cv = {0};
	cv.type = ACTION_STACK_VALUE_OBJECT;
	cv.data.numeric_value = (u64) newChild;
	children->elements[pos] = cv;
	children->length++;

	xml_sync_children(app_context, parent);
}

// ---- Entity escaping/unescaping ----

// Unescape XML entities. Returns a new malloc'd string.
static char* xml_unescape(SWFAppContext* app_context, const char* input, u32 len, u32* out_len) {
	(void)app_context;
	char* buf = (char*) malloc(len + 1);
	u32 wi = 0;
	for (u32 i = 0; i < len; ) {
		if (input[i] == '&') {
			if (i + 5 <= len && strncmp(&input[i], "&amp;", 5) == 0) {
				buf[wi++] = '&'; i += 5;
			} else if (i + 4 <= len && strncmp(&input[i], "&lt;", 4) == 0) {
				buf[wi++] = '<'; i += 4;
			} else if (i + 4 <= len && strncmp(&input[i], "&gt;", 4) == 0) {
				buf[wi++] = '>'; i += 4;
			} else if (i + 6 <= len && strncmp(&input[i], "&apos;", 6) == 0) {
				buf[wi++] = '\''; i += 6;
			} else if (i + 6 <= len && strncmp(&input[i], "&quot;", 6) == 0) {
				buf[wi++] = '"'; i += 6;
			} else if (i + 2 < len && input[i+1] == '#') {
				// Numeric character reference: &#NN; or &#xHH;
				u32 j = i + 2;
				int codepoint = 0;
				if (j < len && input[j] == 'x') {
					// Hex: &#xHH;
					j++;
					while (j < len && input[j] != ';') {
						char c = input[j];
						if (c >= '0' && c <= '9') codepoint = codepoint * 16 + (c - '0');
						else if (c >= 'a' && c <= 'f') codepoint = codepoint * 16 + (c - 'a' + 10);
						else if (c >= 'A' && c <= 'F') codepoint = codepoint * 16 + (c - 'A' + 10);
						else break;
						j++;
					}
				} else {
					// Decimal: &#NN;
					while (j < len && input[j] != ';') {
						if (input[j] >= '0' && input[j] <= '9')
							codepoint = codepoint * 10 + (input[j] - '0');
						else break;
						j++;
					}
				}
				if (j < len && input[j] == ';') {
					j++; // skip ';'
					// Encode as UTF-8
					if (codepoint < 0x80) {
						buf[wi++] = (char)codepoint;
					} else if (codepoint < 0x800) {
						buf[wi++] = (char)(0xC0 | (codepoint >> 6));
						buf[wi++] = (char)(0x80 | (codepoint & 0x3F));
					} else if (codepoint < 0x10000) {
						buf[wi++] = (char)(0xE0 | (codepoint >> 12));
						buf[wi++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
						buf[wi++] = (char)(0x80 | (codepoint & 0x3F));
					} else {
						buf[wi++] = (char)(0xF0 | (codepoint >> 18));
						buf[wi++] = (char)(0x80 | ((codepoint >> 12) & 0x3F));
						buf[wi++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
						buf[wi++] = (char)(0x80 | (codepoint & 0x3F));
					}
					i = j;
				} else {
					buf[wi++] = input[i++]; // Malformed — pass through '&'
				}
			} else {
				buf[wi++] = input[i++]; // Unknown entity — pass through '&'
			}
		} else {
			buf[wi++] = input[i++];
		}
	}
	buf[wi] = '\0';
	*out_len = wi;
	return buf;
}

// Escape XML special characters. Returns a new malloc'd string.
static char* xml_escape(SWFAppContext* app_context, const char* input, u32 len, u32* out_len) {
	(void)app_context;
	// Worst case: every char expands to 6 chars (&apos;)
	char* buf = (char*) malloc(len * 6 + 1);
	u32 wi = 0;
	for (u32 i = 0; i < len; i++) {
		switch (input[i]) {
			case '&':  memcpy(&buf[wi], "&amp;", 5);  wi += 5; break;
			case '<':  memcpy(&buf[wi], "&lt;", 4);   wi += 4; break;
			case '>':  memcpy(&buf[wi], "&gt;", 4);   wi += 4; break;
			case '\'': memcpy(&buf[wi], "&apos;", 6); wi += 6; break;
			case '"':  memcpy(&buf[wi], "&quot;", 6); wi += 6; break;
			default:   buf[wi++] = input[i]; break;
		}
	}
	buf[wi] = '\0';
	*out_len = wi;
	return buf;
}

// ---- XML Parser ----

static void xml_parse_into(SWFAppContext* app_context, ASObject* doc, const char* text, u32 text_len) {
	// Check ignoreWhite property
	int ignore_white = 0;
	ActionVar* iw = getPropertyWithPrototype(doc, "ignoreWhite", 11);
	if (iw != NULL && iw->type == ACTION_STACK_VALUE_BOOLEAN && iw->data.numeric_value)
		ignore_white = 1;
	else if (iw != NULL && iw->type == ACTION_STACK_VALUE_F64) {
		double d = VAL(double, &iw->data.numeric_value);
		if (d != 0.0) ignore_white = 1;
	}

	// Stack of parent nodes for nesting
	#define XML_STACK_MAX 64
	ASObject* stack[XML_STACK_MAX];
	int stack_top = 0;
	stack[0] = doc;

	u32 pos = 0;
	u32 text_start = pos;

	while (pos < text_len) {
		if (text[pos] == '<') {
			// Flush accumulated text
			if (pos > text_start) {
				u32 ue_len = 0;
				char* unescaped = xml_unescape(app_context, &text[text_start], pos - text_start, &ue_len);
				// Check ignoreWhite
				int is_whitespace_only = 1;
				if (ignore_white) {
					for (u32 k = 0; k < ue_len; k++) {
						if (unescaped[k] != ' ' && unescaped[k] != '\t' &&
						    unescaped[k] != '\n' && unescaped[k] != '\r') {
							is_whitespace_only = 0; break;
						}
					}
				} else {
					is_whitespace_only = 0;
				}
				if (!is_whitespace_only || !ignore_white) {
					ASObject* tn = xml_create_node(app_context, 3, NULL, 0, unescaped, ue_len);
					xml_do_append(app_context, stack[stack_top], tn);
				}
				free(unescaped);
			}

			pos++; // skip '<'
			if (pos >= text_len) break;

			if (text[pos] == '/') {
				// Closing tag </tag>
				pos++; // skip '/'
				while (pos < text_len && text[pos] != '>') pos++;
				if (pos < text_len) pos++; // skip '>'
				if (stack_top > 0) stack_top--;
			}
			else if (pos + 2 < text_len && text[pos] == '!' && text[pos+1] == '-' && text[pos+2] == '-') {
				// Comment <!-- ... -->
				pos += 3; // skip !--
				while (pos + 2 < text_len && !(text[pos] == '-' && text[pos+1] == '-' && text[pos+2] == '>'))
					pos++;
				if (pos + 2 < text_len) pos += 3; // skip -->
			}
			else if (pos + 7 < text_len && strncmp(&text[pos], "![CDATA[", 8) == 0) {
				// CDATA <![CDATA[...]]>
				pos += 8; // skip ![CDATA[
				u32 cdata_start = pos;
				while (pos + 2 < text_len && !(text[pos] == ']' && text[pos+1] == ']' && text[pos+2] == '>'))
					pos++;
				u32 cdata_len = pos - cdata_start;
				char* cdata_text = xml_strdup(app_context, &text[cdata_start], cdata_len);
				ASObject* tn = xml_create_node(app_context, 3, NULL, 0, cdata_text, cdata_len);
				xml_do_append(app_context, stack[stack_top], tn);
				free(cdata_text);
				if (pos + 2 < text_len) pos += 3; // skip ]]>
			}
			else if (pos + 7 < text_len && strncmp(&text[pos], "!DOCTYPE", 8) == 0) {
				// DOCTYPE <!DOCTYPE ...>
				u32 dt_start = pos - 1; // include '<'
				while (pos < text_len && text[pos] != '>') pos++;
				if (pos < text_len) pos++; // skip '>'
				u32 dt_len = pos - dt_start;
				xml_set_str(app_context, doc, "docTypeDecl", 11, &text[dt_start], dt_len);
			}
			else if (text[pos] == '?') {
				// Processing instruction <?...?>
				u32 pi_start = pos - 1; // include '<'
				pos++; // skip '?'
				while (pos + 1 < text_len && !(text[pos] == '?' && text[pos+1] == '>'))
					pos++;
				if (pos + 1 < text_len) pos += 2; // skip ?>
				u32 pi_len = pos - pi_start;
				// Check if it's <?xml ...?>
				if (pi_len > 5 && strncmp(&text[pi_start + 2], "xml ", 4) == 0) {
					xml_set_str(app_context, doc, "xmlDecl", 7, &text[pi_start], pi_len);
				}
			}
			else {
				// Opening tag <tag attr="val" ...> or self-closing <tag ... />
				u32 name_start = pos;
				while (pos < text_len && text[pos] != ' ' && text[pos] != '\t' &&
				       text[pos] != '\n' && text[pos] != '\r' &&
				       text[pos] != '>' && text[pos] != '/') pos++;
				u32 name_len = pos - name_start;

				ASObject* elem = xml_create_node(app_context, 1,
					&text[name_start], name_len, NULL, 0);

				// Parse attributes — collect into temp array first.
				// We insert them in REVERSE parse order into the ASObject so that
				// actionEnumerate2 (LIFO) yields forward (parse) enumeration order.
				// Namespace resolution scans the temp array in forward parse order
				// (Flash first-attribute-wins) and must be done before freeing.
				#define XML_MAX_ATTRS 64
				struct { char* name; u32 name_len; char* value; u32 value_len; }
					parsed_attrs[XML_MAX_ATTRS];
				u32 num_parsed_attrs = 0;

				while (pos < text_len && text[pos] != '>' && text[pos] != '/') {
					// Skip whitespace
					while (pos < text_len && (text[pos] == ' ' || text[pos] == '\t' ||
					       text[pos] == '\n' || text[pos] == '\r')) pos++;
					if (pos >= text_len || text[pos] == '>' || text[pos] == '/') break;

					// Attribute name
					u32 attr_name_start = pos;
					while (pos < text_len && text[pos] != '=' && text[pos] != ' ' &&
					       text[pos] != '>' && text[pos] != '/') pos++;
					u32 attr_name_len = pos - attr_name_start;
					if (attr_name_len == 0) break;

					// Skip = and quote
					if (pos < text_len && text[pos] == '=') pos++;
					char quote = '"';
					if (pos < text_len && (text[pos] == '"' || text[pos] == '\'')) {
						quote = text[pos]; pos++;
					}

					// Attribute value
					u32 attr_val_start = pos;
					while (pos < text_len && text[pos] != quote) pos++;
					u32 attr_val_len = pos - attr_val_start;
					if (pos < text_len) pos++; // skip closing quote

					// Unescape and save to temp array
					u32 ue_len = 0;
					char* ue_val = xml_unescape(app_context, &text[attr_val_start], attr_val_len, &ue_len);

					if (num_parsed_attrs < XML_MAX_ATTRS) {
						parsed_attrs[num_parsed_attrs].name = xml_strdup(app_context, &text[attr_name_start], attr_name_len);
						parsed_attrs[num_parsed_attrs].name_len = attr_name_len;
						parsed_attrs[num_parsed_attrs].value = ue_val;
						parsed_attrs[num_parsed_attrs].value_len = ue_len;
						num_parsed_attrs++;
					} else {
						free(ue_val);
					}
				}

				// Insert attributes into ASObject in REVERSE parse order.
				// actionEnumerate2 pushes in forward array order then LIFO-reverses,
				// so reverse insertion gives correct forward (parse) enumeration order.
				{
					ActionVar* attrs_prop = getProperty(elem, "attributes", 10);
					if (attrs_prop != NULL && attrs_prop->type == ACTION_STACK_VALUE_OBJECT) {
						ASObject* attrs = (ASObject*) attrs_prop->data.numeric_value;
						if (attrs != NULL) {
							for (int ai = (int)num_parsed_attrs - 1; ai >= 0; ai--) {
								xml_set_str(app_context, attrs,
									parsed_attrs[ai].name, parsed_attrs[ai].name_len,
									parsed_attrs[ai].value, parsed_attrs[ai].value_len);
							}
						}
					}
				}

				// Check for self-closing />
				int self_closing = 0;
				if (pos < text_len && text[pos] == '/') {
					self_closing = 1;
					pos++; // skip '/'
				}
				if (pos < text_len && text[pos] == '>') pos++; // skip '>'

				xml_do_append(app_context, stack[stack_top], elem);

				// Populate idMap if element has an 'id' attribute (scan temp array)
				for (u32 ai = 0; ai < num_parsed_attrs; ai++) {
					if (parsed_attrs[ai].name_len == 2 &&
					    strncmp(parsed_attrs[ai].name, "id", 2) == 0) {
						ActionVar* idmap_prop = getProperty(doc, "idMap", 5);
						if (idmap_prop != NULL && idmap_prop->type == ACTION_STACK_VALUE_OBJECT) {
							ASObject* idmap = (ASObject*) idmap_prop->data.numeric_value;
							if (idmap != NULL) {
								ActionVar ev = {0}; ev.type = ACTION_STACK_VALUE_OBJECT;
								ev.data.numeric_value = (u64) elem;
								setProperty(app_context, idmap,
									parsed_attrs[ai].value, parsed_attrs[ai].value_len, &ev);
							}
						}
						break;
					}
				}

				// Resolve namespaceURI: scan own-element temp array in forward parse order
				// (Flash first-attribute-wins semantics), then walk up ancestors via ASObject.
				{
					ActionVar* nn = getProperty(elem, "nodeName", 8);
					if (nn != NULL && nn->type == ACTION_STACK_VALUE_STRING) {
						char _xml_fname_buf[512];
						const uint16_t* _xml_fname_u16 = varGetU16Ptr(nn);
						u16_to_utf8(_xml_fname_u16, nn->str_size, _xml_fname_buf, sizeof(_xml_fname_buf));
						const char* full_name = _xml_fname_buf;
						u32 full_len = (u32)strlen(full_name);
						// Determine element's prefix
						const char* elem_prefix = "";
						u32 elem_prefix_len = 0;
						for (u32 ci = 0; ci < full_len; ci++) {
							if (full_name[ci] == ':') {
								elem_prefix = full_name;
								elem_prefix_len = ci;
								break;
							}
						}

						int resolved = 0;

						// 1. Scan own element's attributes from temp array (forward parse order).
						//    Temp array preserves forward parse order regardless of ASObject order.
						for (u32 ai = 0; ai < num_parsed_attrs && !resolved; ai++) {
							const char* aname = parsed_attrs[ai].name;
							if (strncmp(aname, "xmlns", 5) != 0) continue;
							// Derive this attr's prefix
							const char* ap = (aname[5] == ':') ? &aname[6] : "";
							u32 ap_len = strlen(ap);
							if (ap_len == elem_prefix_len &&
							    (elem_prefix_len == 0 || strncmp(ap, elem_prefix, elem_prefix_len) == 0)) {
								const char* uri = parsed_attrs[ai].value;
								u32 uri_len = parsed_attrs[ai].value_len;
								if (uri_len > 0) {
									xml_set_str(app_context, elem, "namespaceURI", 12, uri, uri_len);
									resolved = 1;
								}
							}
						}

						// 2. Walk up ancestors (their attributes are in ASObject, order is fine
						//    for specific-prefix lookups since each xmlns:prefix is unique).
						for (int check = 0; check <= stack_top && !resolved; check++) {
							ASObject* check_node = stack[stack_top - check];
							ActionVar* a_prop = getProperty(check_node, "attributes", 10);
							if (a_prop == NULL || a_prop->type != ACTION_STACK_VALUE_OBJECT) continue;
							ASObject* aobj = (ASObject*) a_prop->data.numeric_value;
							if (aobj == NULL) continue;
							for (u32 i = 0; i < aobj->num_used && !resolved; i++) {
								const char* aname = aobj->properties[i].name;
								if (strncmp(aname, "xmlns", 5) != 0) continue;
								if (aobj->properties[i].value.type != ACTION_STACK_VALUE_STRING) continue;
								const char* ap = (aname[5] == ':') ? &aname[6] : "";
								u32 ap_len = strlen(ap);
								if (ap_len == elem_prefix_len &&
								    (elem_prefix_len == 0 || strncmp(ap, elem_prefix, elem_prefix_len) == 0)) {
									char _ns_uri_buf[512];
									const uint16_t* _ns_uri_u16 = varGetU16Ptr(&aobj->properties[i].value);
									u32 uri_len = aobj->properties[i].value.str_size;
									u16_to_utf8(_ns_uri_u16, uri_len, _ns_uri_buf, sizeof(_ns_uri_buf));
									u32 uri_utf8_len = (u32)strlen(_ns_uri_buf);
									if (uri_utf8_len > 0 || uri_len > 0) {
										xml_set_str(app_context, elem, "namespaceURI", 12, _ns_uri_buf, uri_utf8_len);
										resolved = 1;
									}
								}
							}
						}
					}
				}

				// Free temp attribute array
				for (u32 ai = 0; ai < num_parsed_attrs; ai++) {
					free(parsed_attrs[ai].name);
					free(parsed_attrs[ai].value);
				}

				if (!self_closing && stack_top < XML_STACK_MAX - 1) {
					stack[++stack_top] = elem;
				}
			}

			text_start = pos;
		} else {
			pos++;
		}
	}

	// Flush trailing text
	if (pos > text_start) {
		u32 ue_len = 0;
		char* unescaped = xml_unescape(app_context, &text[text_start], pos - text_start, &ue_len);
		int is_ws = 1;
		if (ignore_white) {
			for (u32 k = 0; k < ue_len; k++) {
				if (unescaped[k] != ' ' && unescaped[k] != '\t' &&
				    unescaped[k] != '\n' && unescaped[k] != '\r') { is_ws = 0; break; }
			}
		} else { is_ws = 0; }
		if (!is_ws || !ignore_white) {
			ASObject* tn = xml_create_node(app_context, 3, NULL, 0, unescaped, ue_len);
			xml_do_append(app_context, stack[stack_top], tn);
		}
		free(unescaped);
	}
	#undef XML_STACK_MAX
}

// ---- XML toString Serializer ----

// Appends serialized XML to a dynamic buffer
typedef struct { char* buf; u32 len; u32 cap; } XmlBuf;

static void xb_ensure(SWFAppContext* app_context, XmlBuf* xb, u32 extra) {
	(void)app_context;
	while (xb->len + extra >= xb->cap) {
		xb->cap = xb->cap < 256 ? 256 : xb->cap * 2;
		xb->buf = (char*) realloc(xb->buf, xb->cap);
	}
}

static void xb_append(SWFAppContext* app_context, XmlBuf* xb, const char* s, u32 len) {
	xb_ensure(app_context, xb, len + 1);
	memcpy(&xb->buf[xb->len], s, len);
	xb->len += len;
	xb->buf[xb->len] = '\0';
}

static void xml_serialize_node(SWFAppContext* app_context, ASObject* node, XmlBuf* xb) {
	ActionVar* nt_prop = getProperty(node, "nodeType", 8);
	if (nt_prop == NULL) return;
	int nodeType = (int) varToDoubleSimple(nt_prop);

	if (nodeType == 3) {
		// Text node — escape and output nodeValue
		ActionVar* nv = getProperty(node, "nodeValue", 9);
		if (nv != NULL && nv->type == ACTION_STACK_VALUE_STRING) {
			char _xml_nv_buf[4096];
			const uint16_t* _xml_nv_u16 = varGetU16Ptr(nv);
			u16_to_utf8(_xml_nv_u16, nv->str_size, _xml_nv_buf, sizeof(_xml_nv_buf));
			const char* text = _xml_nv_buf;
			if (nv->str_size > 0) {
				u32 esc_len = 0;
				char* escaped = xml_escape(app_context, text, (u32)strlen(text), &esc_len);
				xb_append(app_context, xb, escaped, esc_len);
				free(escaped);
			}
		}
		return;
	}

	if (nodeType != 1) return;

	ActionVar* nn_prop = getProperty(node, "nodeName", 8);
	char _xml_nn_buf[512];
	const char* nodeName = NULL;
	u32 name_len = 0;
	if (nn_prop != NULL && nn_prop->type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _xml_nn_u16 = varGetU16Ptr(nn_prop);
		u16_to_utf8(_xml_nn_u16, nn_prop->str_size, _xml_nn_buf, sizeof(_xml_nn_buf));
		nodeName = _xml_nn_buf;
		name_len = (u32)strlen(nodeName);
	}

	// If nodeName is null (document root), just serialize children
	if (nodeName == NULL) {
		ActionVar* cn = getProperty(node, "childNodes", 10);
		if (cn != NULL && cn->type == ACTION_STACK_VALUE_ARRAY) {
			ASArray* children = (ASArray*) cn->data.numeric_value;
			if (children != NULL) {
				for (u32 i = 0; i < children->length; i++) {
					if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT) {
						ASObject* child = (ASObject*) children->elements[i].data.numeric_value;
						if (child != NULL) xml_serialize_node(app_context, child, xb);
					}
				}
			}
		}
		return;
	}

	// Element with name — check for children
	ActionVar* cn = getProperty(node, "childNodes", 10);
	ASArray* children = NULL;
	if (cn != NULL && cn->type == ACTION_STACK_VALUE_ARRAY)
		children = (ASArray*) cn->data.numeric_value;
	int has_children = (children != NULL && children->length > 0);

	// Opening tag
	xb_append(app_context, xb, "<", 1);
	xb_append(app_context, xb, nodeName, name_len);

	// Attributes
	ActionVar* attrs_prop = getProperty(node, "attributes", 10);
	if (attrs_prop != NULL && attrs_prop->type == ACTION_STACK_VALUE_OBJECT) {
		ASObject* attrs = (ASObject*) attrs_prop->data.numeric_value;
		if (attrs != NULL) {
			for (u32 i = 0; i < attrs->num_used; i++) {
				if (attrs->properties[i].name[0] == '\0') continue;
				if (strcmp(attrs->properties[i].name, "__proto__") == 0) continue;
				xb_append(app_context, xb, " ", 1);
				u32 anl = strlen(attrs->properties[i].name);
				xb_append(app_context, xb, attrs->properties[i].name, anl);
				xb_append(app_context, xb, "=\"", 2);
				if (attrs->properties[i].value.type == ACTION_STACK_VALUE_STRING) {
					char _xml_av_buf[512];
					const uint16_t* _xml_av_u16 = varGetU16Ptr(&attrs->properties[i].value);
					u32 avl = attrs->properties[i].value.str_size;
					u16_to_utf8(_xml_av_u16, avl, _xml_av_buf, sizeof(_xml_av_buf));
					if (avl > 0) {
						u32 av_utf8_len = (u32)strlen(_xml_av_buf);
						u32 el = 0;
						char* ev = xml_escape(app_context, _xml_av_buf, av_utf8_len, &el);
						xb_append(app_context, xb, ev, el);
						free(ev);
					}
				}
				xb_append(app_context, xb, "\"", 1);
			}
		}
	}

	if (!has_children) {
		xb_append(app_context, xb, " />", 3);
	} else {
		xb_append(app_context, xb, ">", 1);
		for (u32 i = 0; i < children->length; i++) {
			if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT) {
				ASObject* child = (ASObject*) children->elements[i].data.numeric_value;
				if (child != NULL) xml_serialize_node(app_context, child, xb);
			}
		}
		xb_append(app_context, xb, "</", 2);
		xb_append(app_context, xb, nodeName, name_len);
		xb_append(app_context, xb, ">", 1);
	}
}

// ---- Built-in Method Implementations ----

static ActionVar builtin_xml_toString(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_STRING;
	if (this_obj == NULL) { ret.data.numeric_value = (u64) u16_empty; ret.str_size = 0; return ret; }
	XmlBuf xb = {0};
	xml_serialize_node(app_context, (ASObject*) this_obj, &xb);
	if (xb.buf == NULL) { ret.data.numeric_value = (u64) u16_empty; ret.str_size = 0; return ret; }
	// Convert UTF-8 xb.buf to UTF-16
	u32 ts_u16_len = 0;
	uint16_t* ts_u16 = utf8_to_u16(app_context, xb.buf, xb.len, &ts_u16_len);
	free(xb.buf);
	ret.data.numeric_value = (u64) ts_u16;
	ret.str_size = ts_u16_len;
	return ret;
}

static ActionVar builtin_xml_parseXML(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	if (this_obj == NULL || arg_count == 0) return ret;
	ASObject* doc = (ASObject*) this_obj;

	// Get the text argument
	char _xml_parse_buf[4096];
	const char* text = NULL;
	u32 text_len = 0;
	if (args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _xml_parse_u16 = varGetU16Ptr(&args[0]);
		u16_to_utf8(_xml_parse_u16, args[0].str_size, _xml_parse_buf, sizeof(_xml_parse_buf));
		text = _xml_parse_buf;
		text_len = (u32)strlen(text);
	}
	if (text == NULL || text_len == 0) return ret;

	// Orphan existing children
	ActionVar* cn = getProperty(doc, "childNodes", 10);
	if (cn != NULL && cn->type == ACTION_STACK_VALUE_ARRAY) {
		ASArray* children = (ASArray*) cn->data.numeric_value;
		if (children != NULL) {
			for (u32 i = 0; i < children->length; i++) {
				if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT) {
					ASObject* child = (ASObject*) children->elements[i].data.numeric_value;
					if (child != NULL) {
						xml_set_null(app_context, child, "parentNode", 10);
						xml_set_null(app_context, child, "previousSibling", 15);
						xml_set_null(app_context, child, "nextSibling", 11);
					}
				}
			}
			children->length = 0;
		}
	}
	xml_set_null(app_context, doc, "firstChild", 10);
	xml_set_null(app_context, doc, "lastChild", 9);

	// Parse
	xml_parse_into(app_context, doc, text, text_len);
	return ret;
}

static ActionVar builtin_xml_createElement(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0};
	if (arg_count == 0 || args[0].type != ACTION_STACK_VALUE_STRING) {
		ret.type = ACTION_STACK_VALUE_UNDEFINED; return ret;
	}
	char _xml_cname_buf[512];
	const uint16_t* _xml_cname_u16 = varGetU16Ptr(&args[0]);
	u16_to_utf8(_xml_cname_u16, args[0].str_size, _xml_cname_buf, sizeof(_xml_cname_buf));
	const char* name = _xml_cname_buf;
	u32 name_len = (u32)strlen(name);
	ASObject* node = xml_create_node(app_context, 1, name, name_len, NULL, 0);
	ret.type = ACTION_STACK_VALUE_OBJECT;
	ret.data.numeric_value = (u64) node;
	return ret;
}

static ActionVar builtin_xml_createTextNode(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0};
	char _xml_tnode_buf[512];
	const char* text = "";
	u32 text_len = 0;
	if (arg_count > 0 && args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _xml_tnode_u16 = varGetU16Ptr(&args[0]);
		u16_to_utf8(_xml_tnode_u16, args[0].str_size, _xml_tnode_buf, sizeof(_xml_tnode_buf));
		text = _xml_tnode_buf;
		text_len = (u32)strlen(text);
	}
	ASObject* node = xml_create_node(app_context, 3, NULL, 0, text, text_len);
	ret.type = ACTION_STACK_VALUE_OBJECT;
	ret.data.numeric_value = (u64) node;
	return ret;
}

static ActionVar builtin_xml_appendChild(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	if (this_obj == NULL || arg_count == 0) return ret;
	if (args[0].type != ACTION_STACK_VALUE_OBJECT) return ret;
	ASObject* child = (ASObject*) args[0].data.numeric_value;
	if (child == NULL) return ret;
	xml_do_append(app_context, (ASObject*) this_obj, child);
	return ret;
}

static ActionVar builtin_xml_removeNode(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	if (this_obj == NULL) return ret;
	xml_do_remove(app_context, (ASObject*) this_obj);
	return ret;
}

static ActionVar builtin_xml_insertBefore(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	if (this_obj == NULL || arg_count < 2) return ret;
	if (args[0].type != ACTION_STACK_VALUE_OBJECT) return ret;
	ASObject* newChild = (ASObject*) args[0].data.numeric_value;
	if (newChild == NULL) return ret;
	ASObject* refChild = NULL;
	if (args[1].type == ACTION_STACK_VALUE_OBJECT)
		refChild = (ASObject*) args[1].data.numeric_value;
	if (refChild == NULL) {
		xml_do_append(app_context, (ASObject*) this_obj, newChild);
	} else {
		xml_do_insert_before(app_context, (ASObject*) this_obj, newChild, refChild);
	}
	return ret;
}

static ActionVar builtin_xml_hasChildNodes(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0};
	ret.type = ACTION_STACK_VALUE_BOOLEAN;
	ret.data.numeric_value = 0;
	if (this_obj == NULL) return ret;
	ActionVar* cn = getProperty((ASObject*) this_obj, "childNodes", 10);
	if (cn != NULL && cn->type == ACTION_STACK_VALUE_ARRAY) {
		ASArray* children = (ASArray*) cn->data.numeric_value;
		if (children != NULL && children->length > 0)
			ret.data.numeric_value = 1;
	}
	return ret;
}

static ActionVar builtin_xml_cloneNode(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	if (this_obj == NULL) return ret;
	ASObject* src = (ASObject*) this_obj;

	int deep = 0;
	if (arg_count > 0) {
		if (args[0].type == ACTION_STACK_VALUE_BOOLEAN)
			deep = args[0].data.numeric_value ? 1 : 0;
		else if (args[0].type == ACTION_STACK_VALUE_F64) {
			double d = VAL(double, &args[0].data.numeric_value);
			deep = (d != 0.0) ? 1 : 0;
		}
	}

	// Get source properties
	ActionVar* nt = getProperty(src, "nodeType", 8);
	int nodeType = nt ? (int) varToDoubleSimple(nt) : 1;
	ActionVar* nn = getProperty(src, "nodeName", 8);
	char _clone_nn_buf[512];
	const char* nodeName = NULL; u32 nameLen = 0;
	if (nn && nn->type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _clone_nn_u16 = varGetU16Ptr(nn);
		u16_to_utf8(_clone_nn_u16, nn->str_size, _clone_nn_buf, sizeof(_clone_nn_buf));
		nodeName = _clone_nn_buf;
		nameLen = (u32)strlen(nodeName);
	}
	ActionVar* nv = getProperty(src, "nodeValue", 9);
	char _clone_nv_buf[512];
	const char* nodeValue = NULL; u32 valLen = 0;
	if (nv && nv->type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _clone_nv_u16 = varGetU16Ptr(nv);
		u16_to_utf8(_clone_nv_u16, nv->str_size, _clone_nv_buf, sizeof(_clone_nv_buf));
		nodeValue = _clone_nv_buf;
		valLen = (u32)strlen(nodeValue);
	}

	ASObject* clone = xml_create_node(app_context, nodeType, nodeName, nameLen, nodeValue, valLen);

	// Copy attributes
	ActionVar* src_attrs = getProperty(src, "attributes", 10);
	if (src_attrs && src_attrs->type == ACTION_STACK_VALUE_OBJECT) {
		ASObject* sa = (ASObject*) src_attrs->data.numeric_value;
		ActionVar* dst_attrs = getProperty(clone, "attributes", 10);
		if (sa && dst_attrs && dst_attrs->type == ACTION_STACK_VALUE_OBJECT) {
			ASObject* da = (ASObject*) dst_attrs->data.numeric_value;
			if (da) {
				for (u32 i = 0; i < sa->num_used; i++) {
					if (sa->properties[i].name[0] == '\0') continue;
					if (strcmp(sa->properties[i].name, "__proto__") == 0) continue;
					setProperty(app_context, da, sa->properties[i].name,
						strlen(sa->properties[i].name), &sa->properties[i].value);
				}
			}
		}
	}

	// Deep clone: recursively clone children
	if (deep) {
		ActionVar* cn = getProperty(src, "childNodes", 10);
		if (cn && cn->type == ACTION_STACK_VALUE_ARRAY) {
			ASArray* children = (ASArray*) cn->data.numeric_value;
			if (children) {
				for (u32 i = 0; i < children->length; i++) {
					if (children->elements[i].type == ACTION_STACK_VALUE_OBJECT) {
						ASObject* child_src = (ASObject*) children->elements[i].data.numeric_value;
						if (child_src) {
							ActionVar deep_arg = {0};
							deep_arg.type = ACTION_STACK_VALUE_BOOLEAN;
							deep_arg.data.numeric_value = 1;
							ActionVar child_clone = builtin_xml_cloneNode(app_context, &deep_arg, 1, NULL, child_src);
							if (child_clone.type == ACTION_STACK_VALUE_OBJECT) {
								xml_do_append(app_context, clone, (ASObject*) child_clone.data.numeric_value);
							}
						}
					}
				}
			}
		}
	}

	ret.type = ACTION_STACK_VALUE_OBJECT;
	ret.data.numeric_value = (u64) clone;
	return ret;
}

static ActionVar builtin_xml_getNamespaceForPrefix(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_NULL;
	if (this_obj == NULL || arg_count == 0) return ret;
	char _xml_prefix_buf[512];
	const char* prefix = NULL;
	u32 prefix_len = 0;
	if (args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _xml_prefix_u16 = varGetU16Ptr(&args[0]);
		u16_to_utf8(_xml_prefix_u16, args[0].str_size, _xml_prefix_buf, sizeof(_xml_prefix_buf));
		prefix = _xml_prefix_buf;
		prefix_len = (u32)strlen(prefix);
	}
	if (prefix == NULL) return ret;

	// Flash treats ANY attribute starting with "xmlns" as a namespace declaration.
	// Derived prefix: if name[5]==':' then everything after ':', otherwise "".
	ASObject* cur = (ASObject*) this_obj;
	int depth = 0;
	while (cur != NULL && depth < 100) {
		ActionVar* attrs_prop = getProperty(cur, "attributes", 10);
		if (attrs_prop && attrs_prop->type == ACTION_STACK_VALUE_OBJECT) {
			ASObject* attrs = (ASObject*) attrs_prop->data.numeric_value;
			if (attrs) {
				for (u32 i = 0; i < attrs->num_used; i++) {
					const char* aname = attrs->properties[i].name;
					if (strncmp(aname, "xmlns", 5) != 0) continue;
					if (attrs->properties[i].value.type != ACTION_STACK_VALUE_STRING) continue;
					// Derive this attr's prefix
					const char* ap = (aname[5] == ':') ? &aname[6] : "";
					u32 ap_len = strlen(ap);
					if (ap_len == prefix_len && (prefix_len == 0 || strncmp(ap, prefix, prefix_len) == 0)) {
						ret.type = ACTION_STACK_VALUE_STRING;
						ret.str_size = attrs->properties[i].value.str_size;
						ret.data.numeric_value = attrs->properties[i].value.data.numeric_value;
						return ret;
					}
				}
			}
		}
		ActionVar* pp = getProperty(cur, "parentNode", 10);
		if (pp == NULL || pp->type != ACTION_STACK_VALUE_OBJECT) break;
		cur = (ASObject*) pp->data.numeric_value;
		depth++;
	}
	return ret;
}

static ActionVar builtin_xml_getPrefixForNamespace(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_NULL;
	if (this_obj == NULL || arg_count == 0) return ret;
	char _xml_uri_buf[512];
	const char* uri = NULL;
	u32 uri_len = 0;
	if (args[0].type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _xml_uri_u16 = varGetU16Ptr(&args[0]);
		u16_to_utf8(_xml_uri_u16, args[0].str_size, _xml_uri_buf, sizeof(_xml_uri_buf));
		uri = _xml_uri_buf;
		uri_len = (u32)strlen(uri);
	}
	if (uri == NULL) return ret;

	// Flash treats ANY attribute starting with "xmlns" as a namespace declaration.
	// The prefix is: if name[5]==':' then everything after ':', otherwise "".
	ASObject* cur = (ASObject*) this_obj;
	int depth = 0;
	while (cur != NULL && depth < 100) {
		ActionVar* attrs_prop = getProperty(cur, "attributes", 10);
		if (attrs_prop && attrs_prop->type == ACTION_STACK_VALUE_OBJECT) {
			ASObject* attrs = (ASObject*) attrs_prop->data.numeric_value;
			if (attrs) {
				for (u32 i = 0; i < attrs->num_used; i++) {
					const char* aname = attrs->properties[i].name;
					if (strncmp(aname, "xmlns", 5) != 0) continue;
					if (attrs->properties[i].value.type != ACTION_STACK_VALUE_STRING) continue;
					char _xml_nsv_buf[512];
					const uint16_t* _xml_nsv_u16 = varGetU16Ptr(&attrs->properties[i].value);
					u32 vl = attrs->properties[i].value.str_size;
					u16_to_utf8(_xml_nsv_u16, vl, _xml_nsv_buf, sizeof(_xml_nsv_buf));
					const char* v = _xml_nsv_buf;
					u32 v_utf8_len = (u32)strlen(v);
					if (v_utf8_len == uri_len && strncmp(v, uri, uri_len) == 0) {
						// Derive prefix: after ':' if present at position 5, else ""
						const char* p = (aname[5] == ':') ? &aname[6] : "";
						u32 p_len = (u32)strlen(p);
						u32 p_u16_len = 0;
						uint16_t* p_u16 = ascii_to_u16(app_context, p, (int)p_len, &p_u16_len);
						ret.type = ACTION_STACK_VALUE_STRING;
						ret.str_size = p_u16_len;
						ret.data.numeric_value = (u64) p_u16;
						return ret;
					}
				}
			}
		}
		ActionVar* pp = getProperty(cur, "parentNode", 10);
		if (pp == NULL || pp->type != ACTION_STACK_VALUE_OBJECT) break;
		cur = (ASObject*) pp->data.numeric_value;
		depth++;
	}
	return ret;
}

static ActionVar builtin_xml_getBytesLoaded(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	return ret;
}

static ActionVar builtin_xml_getBytesTotal(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj) {
	ActionVar ret = {0}; ret.type = ACTION_STACK_VALUE_UNDEFINED;
	return ret;
}

// Helper to init a static method ASFunction
static void xml_init_method(ASFunction* fn, const char* name, Function2Ptr func) {
	memset(fn, 0, sizeof(ASFunction));
	strncpy(fn->name, name, 255);
	fn->function_type = 2;
	fn->advanced_func = func;
	fn->param_count = 0;
}

static void initXMLPrototype(SWFAppContext* app_context) {
	if (g_xml_constructor_init) return;

	// Initialize method ASFunctions
	xml_init_method(&g_xml_fn_parseXML, "parseXML", builtin_xml_parseXML);
	xml_init_method(&g_xml_fn_createElement, "createElement", builtin_xml_createElement);
	xml_init_method(&g_xml_fn_createTextNode, "createTextNode", builtin_xml_createTextNode);
	xml_init_method(&g_xml_fn_appendChild, "appendChild", builtin_xml_appendChild);
	xml_init_method(&g_xml_fn_removeNode, "removeNode", builtin_xml_removeNode);
	xml_init_method(&g_xml_fn_insertBefore, "insertBefore", builtin_xml_insertBefore);
	xml_init_method(&g_xml_fn_hasChildNodes, "hasChildNodes", builtin_xml_hasChildNodes);
	xml_init_method(&g_xml_fn_cloneNode, "cloneNode", builtin_xml_cloneNode);
	xml_init_method(&g_xml_fn_toString, "toString", builtin_xml_toString);
	xml_init_method(&g_xml_fn_getNamespaceForPrefix, "getNamespaceForPrefix", builtin_xml_getNamespaceForPrefix);
	xml_init_method(&g_xml_fn_getPrefixForNamespace, "getPrefixForNamespace", builtin_xml_getPrefixForNamespace);
	xml_init_method(&g_xml_fn_getBytesLoaded, "getBytesLoaded", builtin_xml_getBytesLoaded);
	xml_init_method(&g_xml_fn_getBytesTotal, "getBytesTotal", builtin_xml_getBytesTotal);

	// ---- XMLNode constructor ----
	memset(&g_xmlnode_constructor, 0, sizeof(ASFunction));
	strncpy(g_xmlnode_constructor.name, "XMLNode", 255);
	g_xmlnode_constructor.function_type = 1;

	ASObject* xmlnode_proto = allocObject(app_context, 20);
	g_xmlnode_constructor.prototype_obj = xmlnode_proto;

	// Set XMLNode.prototype.__proto__ = Object.prototype
	if (g_object_prototype != NULL) {
		ActionVar pv = {0};
		pv.type = ACTION_STACK_VALUE_OBJECT;
		pv.data.numeric_value = (u64) g_object_prototype;
		setProperty(app_context, xmlnode_proto, "__proto__", 9, &pv);
	}

	// Install methods on XMLNode.prototype
	#define INSTALL_METHOD(name, nlen, fn_ptr) do { \
		ActionVar mv = {0}; mv.type = ACTION_STACK_VALUE_FUNCTION; \
		mv.data.numeric_value = (u64)(fn_ptr); \
		setProperty(app_context, xmlnode_proto, name, nlen, &mv); \
	} while(0)

	INSTALL_METHOD("appendChild", 11, &g_xml_fn_appendChild);
	INSTALL_METHOD("removeNode", 10, &g_xml_fn_removeNode);
	INSTALL_METHOD("insertBefore", 12, &g_xml_fn_insertBefore);
	INSTALL_METHOD("hasChildNodes", 13, &g_xml_fn_hasChildNodes);
	INSTALL_METHOD("cloneNode", 9, &g_xml_fn_cloneNode);
	INSTALL_METHOD("toString", 8, &g_xml_fn_toString);
	INSTALL_METHOD("getNamespaceForPrefix", 21, &g_xml_fn_getNamespaceForPrefix);
	INSTALL_METHOD("getPrefixForNamespace", 21, &g_xml_fn_getPrefixForNamespace);
	INSTALL_METHOD("getBytesLoaded", 14, &g_xml_fn_getBytesLoaded);
	INSTALL_METHOD("getBytesTotal", 13, &g_xml_fn_getBytesTotal);

	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = &g_xmlnode_constructor;

	// ---- XML constructor ----
	memset(&g_xml_constructor, 0, sizeof(ASFunction));
	strncpy(g_xml_constructor.name, "XML", 255);
	g_xml_constructor.function_type = 1;

	ASObject* xml_proto = allocObject(app_context, 16);
	g_xml_constructor.prototype_obj = xml_proto;

	// XML.prototype.__proto__ = XMLNode.prototype
	{
		ActionVar pv = {0};
		pv.type = ACTION_STACK_VALUE_OBJECT;
		pv.data.numeric_value = (u64) xmlnode_proto;
		setProperty(app_context, xml_proto, "__proto__", 9, &pv);
	}

	// Install XML-specific methods on XML.prototype
	INSTALL_METHOD("parseXML", 8, &g_xml_fn_parseXML);
	INSTALL_METHOD("createElement", 13, &g_xml_fn_createElement);
	INSTALL_METHOD("createTextNode", 14, &g_xml_fn_createTextNode);

	// Default ignoreWhite = false on XML.prototype (tests override via XML.prototype.ignoreWhite = true)
	{
		ActionVar fw = {0}; fw.type = ACTION_STACK_VALUE_BOOLEAN;
		setProperty(app_context, xml_proto, "ignoreWhite", 11, &fw);
	}

	#undef INSTALL_METHOD

	if (function_count < MAX_FUNCTIONS)
		function_registry[function_count++] = &g_xml_constructor;

	g_xml_constructor_init = 1;
}

// Create a new XML document object
static ASObject* xml_create_document(SWFAppContext* app_context) {
	initXMLPrototype(app_context);
	ASObject* doc = xml_create_node(app_context, 1, NULL, 0, NULL, 0);

	// Override __proto__ to XML.prototype (not XMLNode.prototype)
	if (g_xml_constructor.prototype_obj != NULL) {
		ActionVar pv = {0};
		pv.type = ACTION_STACK_VALUE_OBJECT;
		pv.data.numeric_value = (u64) g_xml_constructor.prototype_obj;
		setProperty(app_context, doc, "__proto__", 9, &pv);
	}

	// XML-specific properties
	// Note: ignoreWhite is NOT set as own property — it inherits from XML.prototype
	// (default false). Tests set XML.prototype.ignoreWhite = true to affect all instances.

	ASObject* idmap = allocObject(app_context, 4);
	xml_set_obj(app_context, doc, "idMap", 5, idmap);

	xml_set_str(app_context, doc, "contentType", 11,
		"application/x-www-form-urlencoded", 33);

	ActionVar zero_val = {0}; zero_val.type = ACTION_STACK_VALUE_F64;
	setProperty(app_context, doc, "status", 6, &zero_val);

	return doc;
}

// _root MovieClip for simplified implementation
// Note: totalframes is set from SWF_FRAME_COUNT if available, otherwise defaults to 1
MovieClip root_movieclip = {
	.x = 0.0f,
	.y = 0.0f,
	.xscale = 100.0f,
	.yscale = 100.0f,
	.rotation = 0.0f,
	.alpha = 100.0f,
	.width = 0.0f,    // Computed dynamically from content bounds in mcGetEffectiveSize
	.height = 0.0f,
	.visible = 1,
	.currentframe = 1,
#ifdef SWF_FRAME_COUNT
	.totalframes = SWF_FRAME_COUNT,
#else
	.totalframes = 1,
#endif
	.framesloaded = 1,  // All frames loaded in NO_GRAPHICS mode
	.name = "",       // _root._name is empty string in Flash
	.target = "/",    // _root._target is "/" (slash-path format)
	.droptarget = "",  // No drag/drop in NO_GRAPHICS mode
	.url = "file:///test.swf",  // SWF URL (matches Ruffle test expectations)
	.highquality = 1.0f,       // Default: high quality
	.focusrect = -1.0f,        // Default: null (sentinel: -1.0f = null)
	.soundbuftime = 5.0f,      // Default: 5 seconds
	.quality = "HIGH",         // Default: HIGH quality
	.xmouse = 0.0f,  // No mouse in NO_GRAPHICS mode
	.ymouse = 0.0f,  // No mouse in NO_GRAPHICS mode
	.parent = NULL,  // _root has no parent
	.dynamic_props = NULL,
	.lockroot = 0,
	.blend_mode = 0,
	.depth = -16384,   // _root is at Flash "level 0" depth
};

// Helper function to get MovieClip by target path
// Simplified: only supports "_root" or empty string
static MovieClip* getMovieClipByTarget(const char* target) {
	if (!target || strlen(target) == 0) {
		// Empty target = "this clip" = current execution context (not necessarily root).
		// When running inside a sprite frame, g_current_context points to the sprite's MC.
#ifdef NO_GRAPHICS
		return g_current_context ? g_current_context : &root_movieclip;
#else
		return &root_movieclip;
#endif
	}
	if (strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
		return &root_movieclip;
	}
	return NULL;  // Other paths not supported yet
}

#ifndef NO_GRAPHICS
// Targeted sprite for SetTarget — when non-NULL, play/stop/goto operate on this sprite
static DisplayObject* targeted_sprite = NULL;

// Forward declaration
extern DisplayObject* findDisplayObjectByName(const char* name);
#else
// NO_GRAPHICS child lookup by instance name — returns depth or SIZE_MAX if not found
extern size_t ng_findDisplayEntryByName(const char* name);
// Search for a named child within a named parent's display list
extern size_t ng_findChildEntryDepth(const char* parent_name, const char* child_name);
// Update ng_display depth for a named root-level entry (used by swapDepths)
extern void ng_updateDisplayDepth(const char* name, int new_as_depth);
// Swap ng_display depths of two named root-level entries (used by swapDepths)
extern void ng_swapDisplayDepths(const char* name1, const char* name2);
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
	mc->focusrect = -1.0f;   // -1.0f sentinel = null
	mc->soundbuftime = 5.0f;
	strcpy(mc->quality, "HIGH");
	mc->xmouse = 0.0f;
	mc->ymouse = 0.0f;
	mc->droptarget[0] = '\0';
	mc->url[0] = '\0';
	mc->dynamic_props = NULL;
	mc->lockroot = 0;
	mc->blend_mode = 0;
	mc->depth = 0;
#ifdef NO_GRAPHICS
	mc->last_transform_id = 0;
	mc->as_set_flags = 0;
	mc->ng_textfield_idx = -1;
	mc->draw_xmin = mc->draw_xmax = mc->draw_ymin = mc->draw_ymax = 0.0f;
	mc->draw_has_bounds = 0;
	mc->mc_mouse_inside = 0;
	mc->mc_as_pressed = 0;
#endif

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
		// Has parent - construct target path using / separator (Flash uses slash-path format)
		int parent_len = strlen(parent->target);
		int written;
		if (parent_len == 1 && parent->target[0] == '/') {
			// Parent is root "/" — child target is "/childName"
			written = snprintf(mc->target, sizeof(mc->target), "/%s", instance_name);
		} else {
			written = snprintf(mc->target, sizeof(mc->target), "%s/%s",
			                   parent->target, instance_name);
		}
		if (written >= (int)sizeof(mc->target)) {
			mc->target[sizeof(mc->target) - 1] = '\0';
		}
	}

	return mc;
}

// MovieClip cache: ensures same instance name always returns same pointer
// so properties (dynamic_props) persist across lookups
#define MAX_CHILD_MOVIECLIPS 128
MovieClip* child_mc_cache[MAX_CHILD_MOVIECLIPS];
int child_mc_count = 0;

static MovieClip* findOrCreateMovieClip(SWFAppContext* app_context, const char* instance_name, MovieClip* parent) {
	(void)app_context;  // used only in NO_GRAPHICS for TextField init
	MovieClip* mc = NULL;
	int is_new = 0;

	// Check cache first
	for (int i = 0; i < child_mc_count; i++) {
		if (child_mc_cache[i] != NULL &&
		    strcmp(child_mc_cache[i]->name, instance_name) == 0 &&
		    child_mc_cache[i]->parent == parent) {
			mc = child_mc_cache[i];
			break;
		}
	}

	if (mc != NULL) {
#ifdef NO_GRAPHICS
		// Check if textfield was re-placed with a different char_id
		size_t cdepth = ng_findDisplayEntryByName(instance_name);
		if (cdepth != SIZE_MAX && ng_isTextFieldAtDepth(cdepth)) {
			int new_tf_idx = ng_getTextFieldIdx(cdepth);
			if (new_tf_idx != mc->ng_textfield_idx) {
				// Textfield changed — need to re-init properties below
				is_new = 1;
			}
		}
#endif
		if (!is_new) return mc;
	} else {
		mc = createMovieClip(instance_name, parent);
		is_new = 1;
	}

#ifdef NO_GRAPHICS
	// Init or re-init: sync x/y from transform_data
	if (mc != NULL) {
		size_t depth = ng_findDisplayEntryByName(instance_name);
		if (depth != SIZE_MAX) {
			// Sync ActionScript depth: SWF depth - 16384
			mc->depth = (int)depth - 16384;
			float init_x, init_y;
			if (ng_getTransformXY(depth, &init_x, &init_y)) {
				mc->x = init_x;
				mc->y = init_y;
			}
			float init_xs, init_ys, init_rot;
			if (ng_getTransformScaleRotation(depth, &init_xs, &init_ys, &init_rot)) {
				mc->xscale = init_xs;
				mc->yscale = init_ys;
				mc->rotation = init_rot;
			}
			u32 tid;
			if (ng_getTransformId(depth, &tid)) {
				mc->last_transform_id = tid;
			}
			// Pre-populate TextField default properties
			if (ng_isTextFieldAtDepth(depth)) {
				if (mc->dynamic_props == NULL) {
					mc->dynamic_props = (void*) allocObject(app_context, 32);
					retainObject((ASObject*) mc->dynamic_props);
				}
				ASObject* props = (ASObject*) mc->dynamic_props;

				// Set __proto__ to TextField.prototype
				initTextFieldPrototype(app_context);
				if (g_textfield_constructor.prototype_obj != NULL) {
					ActionVar proto_val = {0};
					proto_val.type = ACTION_STACK_VALUE_OBJECT;
					proto_val.data.numeric_value = (u64) g_textfield_constructor.prototype_obj;
					setProperty(app_context, props, "__proto__", 9, &proto_val);
					// Mark __proto__ as DontEnum
					for (u32 pi = 0; pi < props->num_used; pi++) {
						if (strcmp(props->properties[pi].name, "__proto__") == 0) {
							props->properties[pi].flags &= ~PROPERTY_FLAG_ENUMERABLE;
							break;
						}
					}
				}

				int tf_idx = ng_getTextFieldIdx(depth);
				mc->ng_textfield_idx = tf_idx;
				u16 tf_flags = ng_getTextFieldFlags(tf_idx);
				// Flag bits: 0x0001=WordWrap, 0x0002=Multiline, 0x0004=Password,
				//            0x0008=ReadOnly, 0x0010=NoSelect, 0x0020=Border,
				//            0x0040=HTML, 0x0080=UseOutlines, 0x0100=AutoSize

				// text property (initial text from DefineEditText)
				// Flash multiline fields have a trailing '\n' in their initial text,
				// but only when there is no variable binding (variable-bound fields
				// derive their text from the variable, not from the tag default).
				const char* init_text = ng_getTextFieldInitialText(depth);
				char* init_text_ml = NULL;
				if ((tf_flags & 0x0002) && ng_getTextFieldVariableName(tf_idx)[0] == '\0') {
					// Multiline with no variable binding: append trailing newline
					size_t _ml_len = strlen(init_text);
					init_text_ml = (char*) malloc(_ml_len + 2);
					memcpy(init_text_ml, init_text, _ml_len);
					init_text_ml[_ml_len]     = '\n';
					init_text_ml[_ml_len + 1] = '\0';
					init_text = init_text_ml;
				}
				ActionVar text_val = {0};
				text_val.type = ACTION_STACK_VALUE_STRING;
				{
					u32 _it_u16_len;
					uint16_t* _it_u16 = utf8_to_u16(app_context, init_text, (u32)strlen(init_text), &_it_u16_len);
					text_val.str_size = _it_u16_len;
					VAL(u64, &text_val.data.numeric_value) = (u64)_it_u16;
				}
				if (init_text_ml) free(init_text_ml);
				setProperty(app_context, props, "text", 4, &text_val);
				// htmlText — for HTML fields, wrap with <P ALIGN><FONT> tags
				const char* raw_html = ng_getTextFieldRawHtml(tf_idx);
				ActionVar html_text_val = {0};
				html_text_val.type = ACTION_STACK_VALUE_STRING;
				if (tf_flags & 0x0040) {
					// HTML field: wrap content with Flash-style markup
					const char* align_names[] = {"LEFT", "RIGHT", "CENTER", "JUSTIFY"};
					u8 align_idx = ng_getTextFieldAlign(tf_idx);
					const char* align_name = (align_idx < 4) ? align_names[align_idx] : "LEFT";
					u16 fid = ng_getTextFieldFontId(tf_idx);
					const char* font_name = ng_getFontName(fid);
					if (font_name[0] == '\0') font_name = "Times New Roman";
					u16 raw_height = ng_getTextFieldFontHeight(tf_idx);
					int font_size = (raw_height > 0) ? (raw_height / 20) : 12;
					u32 text_color = ng_getTextFieldColorByIdx(tf_idx);
					// Convert inline tags to uppercase (Flash convention)
					size_t raw_len = strlen(raw_html);
					char* upper_html = (char*) malloc(raw_len + 1);
					memcpy(upper_html, raw_html, raw_len + 1);
					for (size_t ci = 0; ci + 2 < raw_len; ci++) {
						if (upper_html[ci] == '<') {
							if (upper_html[ci+1] == 'b' && (upper_html[ci+2] == '>' || upper_html[ci+2] == ' '))
								upper_html[ci+1] = 'B';
							else if (upper_html[ci+1] == 'i' && (upper_html[ci+2] == '>' || upper_html[ci+2] == ' '))
								upper_html[ci+1] = 'I';
							else if (upper_html[ci+1] == 'u' && (upper_html[ci+2] == '>' || upper_html[ci+2] == ' '))
								upper_html[ci+1] = 'U';
							else if (upper_html[ci+1] == '/' && ci + 3 < raw_len) {
								if (upper_html[ci+2] == 'b' && upper_html[ci+3] == '>')
									upper_html[ci+2] = 'B';
								else if (upper_html[ci+2] == 'i' && upper_html[ci+3] == '>')
									upper_html[ci+2] = 'I';
								else if (upper_html[ci+2] == 'u' && upper_html[ci+3] == '>')
									upper_html[ci+2] = 'U';
							}
						}
					}
					// Build wrapped HTML string
					size_t buf_size = raw_len + 256;
					char* wrapped = (char*) malloc(buf_size);
					snprintf(wrapped, buf_size,
						"<P ALIGN=\"%s\"><FONT FACE=\"%s\" SIZE=\"%d\" COLOR=\"#%06X\" LETTERSPACING=\"0\" KERNING=\"0\">%s</FONT></P>",
						align_name, font_name, font_size, text_color, upper_html);
					free(upper_html);
					u32 _wr_u16_len;
					uint16_t* _wr_u16 = utf8_to_u16(app_context, wrapped, (u32)strlen(wrapped), &_wr_u16_len);
					free(wrapped);
					html_text_val.str_size = _wr_u16_len;
					VAL(u64, &html_text_val.data.numeric_value) = (u64)_wr_u16;
				} else {
					u32 _rh_u16_len;
					uint16_t* _rh_u16 = utf8_to_u16(app_context, raw_html, (u32)strlen(raw_html), &_rh_u16_len);
					html_text_val.str_size = _rh_u16_len;
					VAL(u64, &html_text_val.data.numeric_value) = (u64)_rh_u16;
				}
				setProperty(app_context, props, "htmlText", 8, &html_text_val);
				// textColor (from DefineEditText)
				u32 tc = ng_getTextFieldColor(depth);
				ActionVar color_val = {0};
				color_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &color_val.data.numeric_value) = (double)tc;
				setProperty(app_context, props, "textColor", 9, &color_val);
				// backgroundColor (default white)
				ActionVar bg_val = {0};
				bg_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &bg_val.data.numeric_value) = 16777215.0;
				setProperty(app_context, props, "backgroundColor", 15, &bg_val);
				// borderColor (default black)
				ActionVar bc_val = {0};
				bc_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &bc_val.data.numeric_value) = 0.0;
				setProperty(app_context, props, "borderColor", 11, &bc_val);
				// Boolean properties
				ActionVar false_val = {0};
				false_val.type = ACTION_STACK_VALUE_BOOLEAN;
				VAL(u32, &false_val.data.numeric_value) = 0;
				ActionVar true_val = {0};
				true_val.type = ACTION_STACK_VALUE_BOOLEAN;
				VAL(u32, &true_val.data.numeric_value) = 1;
				// background (default false)
				setProperty(app_context, props, "background", 10, &false_val);
				// border (from DefineEditText Border flag)
				setProperty(app_context, props, "border", 6, (tf_flags & 0x0020) ? &true_val : &false_val);
				// type ("input" if !ReadOnly, "dynamic" otherwise)
				ActionVar type_val = {0};
				type_val.type = ACTION_STACK_VALUE_STRING;
				if (tf_flags & 0x0008) {  // ReadOnly
					type_val.str_size = 7;
					VAL(u64, &type_val.data.numeric_value) = (u64)u16_dynamic;
				} else {
					type_val.str_size = 5;
					VAL(u64, &type_val.data.numeric_value) = (u64)u16_input;
				}
				setProperty(app_context, props, "type", 4, &type_val);
				// length (string length of initial text)
				ActionVar len_val = {0};
				len_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &len_val.data.numeric_value) = (double)strlen(init_text);
				setProperty(app_context, props, "length", 6, &len_val);
				// multiline (from DefineEditText Multiline flag)
				setProperty(app_context, props, "multiline", 9, (tf_flags & 0x0002) ? &true_val : &false_val);
				// wordWrap (from DefineEditText WordWrap flag)
				setProperty(app_context, props, "wordWrap", 8, (tf_flags & 0x0001) ? &true_val : &false_val);
				// password (from DefineEditText Password flag)
				setProperty(app_context, props, "password", 8, (tf_flags & 0x0004) ? &true_val : &false_val);
				// selectable (!NoSelect)
				setProperty(app_context, props, "selectable", 10, (tf_flags & 0x0010) ? &false_val : &true_val);
				// html (from DefineEditText HTML flag)
				setProperty(app_context, props, "html", 4, (tf_flags & 0x0040) ? &true_val : &false_val);
				// embedFonts (from DefineEditText UseOutlines flag)
				setProperty(app_context, props, "embedFonts", 10, (tf_flags & 0x0080) ? &true_val : &false_val);
				// condenseWhite (default false)
				setProperty(app_context, props, "condenseWhite", 13, &false_val);
				// maxChars (from DefineEditText MaxLength, null if -1)
				s16 max_len = ng_getTextFieldMaxLength(tf_idx);
				if (max_len < 0) {
					ActionVar null_val = {0};
					null_val.type = ACTION_STACK_VALUE_NULL;
					setProperty(app_context, props, "maxChars", 8, &null_val);
				} else {
					ActionVar maxc_val = {0};
					maxc_val.type = ACTION_STACK_VALUE_F64;
					VAL(double, &maxc_val.data.numeric_value) = (double)max_len;
					setProperty(app_context, props, "maxChars", 8, &maxc_val);
				}
				// variable (from DefineEditText VariableName)
				const char* var_name = ng_getTextFieldVariableName(tf_idx);
				ActionVar var_val = {0};
				var_val.type = ACTION_STACK_VALUE_STRING;
				{
					u32 _vn_u16_len;
					uint16_t* _vn_u16 = ascii_to_u16(app_context, var_name, (int)strlen(var_name), &_vn_u16_len);
					var_val.str_size = _vn_u16_len;
					VAL(u64, &var_val.data.numeric_value) = (u64)_vn_u16;
					setProperty(app_context, props, "variable", 8, &var_val);
				}
				// If the bound variable already has a value (e.g., textfield placed after
				// the variable was set), initialize text from that current value.
				if (var_name[0] != '\0') {
					const char* _fi_dot = strchr(var_name, '.');
					if (_fi_dot != NULL) {
						// Path variable (e.g., "obj.theVar"): resolve container then read property
						const char* _fi_last_dot = _fi_dot;
						for (const char* _fi_p = _fi_dot + 1; *_fi_p; _fi_p++)
							if (*_fi_p == '.') _fi_last_dot = _fi_p;
						u32 _fi_clen = (u32)(_fi_last_dot - var_name);
						const char* _fi_prop = _fi_last_dot + 1;
						u32 _fi_plen = (u32)strlen(_fi_prop);
						PUSH_STR(var_name, _fi_clen);
						actionGetVariable(app_context);
						ActionVar _fi_cvar;
						peekVar(app_context, &_fi_cvar);
						POP();
						ASObject* _fi_obj = NULL;
						if (_fi_cvar.type == ACTION_STACK_VALUE_OBJECT)
							_fi_obj = (ASObject*) VAL(u64, &_fi_cvar.data.numeric_value);
						else if (_fi_cvar.type == ACTION_STACK_VALUE_MOVIECLIP) {
							MovieClip* _fi_mc = (MovieClip*) VAL(u64, &_fi_cvar.data.numeric_value);
							if (_fi_mc != NULL) _fi_obj = (ASObject*) _fi_mc->dynamic_props;
						}
						if (_fi_obj != NULL) {
							ActionVar* _fi_val = getProperty(_fi_obj, _fi_prop, _fi_plen);
							if (_fi_val != NULL && _fi_val->type != ACTION_STACK_VALUE_UNDEFINED)
								setProperty(app_context, props, "text", 4, _fi_val);
						}
					}
				}
				// autoSize (from DefineEditText AutoSize flag)
				ActionVar autosize_val = {0};
				autosize_val.type = ACTION_STACK_VALUE_STRING;
				if (tf_flags & 0x0100) {
					autosize_val.str_size = 4;
					VAL(u64, &autosize_val.data.numeric_value) = (u64)u16_left;
				} else {
					autosize_val.str_size = 4;
					VAL(u64, &autosize_val.data.numeric_value) = (u64)u16_none;
				}
				setProperty(app_context, props, "autoSize", 8, &autosize_val);
				// scroll (default 1)
				ActionVar one_val = {0};
				one_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &one_val.data.numeric_value) = 1.0;
				setProperty(app_context, props, "scroll", 6, &one_val);
				// maxscroll (default 1)
				setProperty(app_context, props, "maxscroll", 9, &one_val);
				// bottomScroll (default 1)
				setProperty(app_context, props, "bottomScroll", 12, &one_val);
				// hscroll (default 0)
				ActionVar zero_val = {0};
				zero_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &zero_val.data.numeric_value) = 0.0;
				setProperty(app_context, props, "hscroll", 7, &zero_val);
				// maxhscroll (default 0)
				setProperty(app_context, props, "maxhscroll", 10, &zero_val);
				// mouseWheelEnabled (default true)
				setProperty(app_context, props, "mouseWheelEnabled", 17, &true_val);
				// restrict (default null)
				ActionVar null_val = {0};
				null_val.type = ACTION_STACK_VALUE_NULL;
				setProperty(app_context, props, "restrict", 8, &null_val);
				// styleSheet (default null)
				setProperty(app_context, props, "styleSheet", 10, &null_val);
				// textWidth (default 0)
				setProperty(app_context, props, "textWidth", 9, &zero_val);
				// textHeight (default 0)
				setProperty(app_context, props, "textHeight", 10, &zero_val);
				// tabIndex (default undefined)
				ActionVar undef_val = {0};
				undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
				setProperty(app_context, props, "tabIndex", 8, &undef_val);
				// CSMTextSettings-derived properties (or defaults)
				extern int ng_getTextFieldCSMApplied(int idx);
				extern const char* ng_getTextFieldCSMAntiAliasType(int idx);
				extern const char* ng_getTextFieldCSMGridFitType(int idx);
				extern float ng_getTextFieldCSMThickness(int idx);
				extern float ng_getTextFieldCSMSharpness(int idx);
				int csm_applied = ng_getTextFieldCSMApplied(tf_idx);
				// antiAliasType
				ActionVar aat_val = {0};
				aat_val.type = ACTION_STACK_VALUE_STRING;
				if (csm_applied) {
					const char* aat = ng_getTextFieldCSMAntiAliasType(tf_idx);
					u32 _aat_u16_len;
					uint16_t* _aat_u16 = ascii_to_u16(app_context, aat, (int)strlen(aat), &_aat_u16_len);
					aat_val.str_size = _aat_u16_len;
					VAL(u64, &aat_val.data.numeric_value) = (u64)_aat_u16;
				} else {
					aat_val.str_size = 6;
					VAL(u64, &aat_val.data.numeric_value) = (u64)u16_normal;
				}
				setProperty(app_context, props, "antiAliasType", 13, &aat_val);
				// gridFitType
				ActionVar gft_val = {0};
				gft_val.type = ACTION_STACK_VALUE_STRING;
				if (csm_applied) {
					const char* gft = ng_getTextFieldCSMGridFitType(tf_idx);
					u32 _gft_u16_len;
					uint16_t* _gft_u16 = ascii_to_u16(app_context, gft, (int)strlen(gft), &_gft_u16_len);
					gft_val.str_size = _gft_u16_len;
					VAL(u64, &gft_val.data.numeric_value) = (u64)_gft_u16;
				} else {
					gft_val.str_size = 5;
					VAL(u64, &gft_val.data.numeric_value) = (u64)u16_pixel;
				}
				setProperty(app_context, props, "gridFitType", 11, &gft_val);
				// thickness
				if (csm_applied) {
					ActionVar thick_val = {0};
					thick_val.type = ACTION_STACK_VALUE_F64;
					VAL(double, &thick_val.data.numeric_value) = (double)ng_getTextFieldCSMThickness(tf_idx);
					setProperty(app_context, props, "thickness", 9, &thick_val);
				} else {
					setProperty(app_context, props, "thickness", 9, &zero_val);
				}
				// sharpness
				if (csm_applied) {
					ActionVar sharp_val = {0};
					sharp_val.type = ACTION_STACK_VALUE_F64;
					VAL(double, &sharp_val.data.numeric_value) = (double)ng_getTextFieldCSMSharpness(tf_idx);
					setProperty(app_context, props, "sharpness", 9, &sharp_val);
				} else {
					setProperty(app_context, props, "sharpness", 9, &zero_val);
				}
				// filters (default empty array)
				ASArray* filters_arr = allocArray(app_context, 0);
				filters_arr->length = 0;
				ActionVar filters_val = {0};
				filters_val.type = ACTION_STACK_VALUE_ARRAY;
				filters_val.data.numeric_value = (u64) filters_arr;
				setProperty(app_context, props, "filters", 7, &filters_val);
				// Set _width/_height from bounds
				s32 bxmin, bxmax, bymin, bymax;
				ng_getTextFieldBounds(tf_idx, &bxmin, &bxmax, &bymin, &bymax);
				mc->width = (float)(bxmax - bxmin) / 20.0f;
				mc->height = (float)(bymax - bymin) / 20.0f;

				// Variable binding: sync text from current variable value.
				// The variable was already created at placement time (tagPlaceObject2).
				// Here we read the variable's current value and use it as the text.
				if (var_name[0] != '\0') {
					ActionVar* existing = NULL;
					const uint16_t* text_from_var = NULL;
					u32 tfv_len = 0;

					if (strchr(var_name, '.') == NULL) {
						// Simple variable
						extern bool hasVariable(char* var_name, size_t key_size);
						size_t vlen = strlen(var_name);
						if (hasVariable((char*)var_name, vlen)) {
							extern ActionVar* getVariable(char* var_name, size_t key_size);
							existing = getVariable((char*)var_name, vlen);
						}
					} else {
						// Path variable (e.g., "_root.mc.theVar") — resolve via GetVariable
						const char* last_dot = var_name;
						for (const char* p = var_name; *p; p++) {
							if (*p == '.') last_dot = p;
						}
						u32 container_len = (u32)(last_dot - var_name);
						const char* final_prop = last_dot + 1;
						u32 final_prop_len = strlen(final_prop);
						PUSH_STR(var_name, container_len);
						actionGetVariable(app_context);
						ActionVar container_var;
						peekVar(app_context, &container_var);
						POP();
						if (container_var.type == ACTION_STACK_VALUE_MOVIECLIP) {
							MovieClip* target_mc = (MovieClip*) VAL(u64, &container_var.data.numeric_value);
							if (target_mc != NULL && target_mc->dynamic_props != NULL) {
								existing = getProperty((ASObject*)target_mc->dynamic_props, final_prop, final_prop_len);
							}
						} else if (container_var.type == ACTION_STACK_VALUE_OBJECT) {
							ASObject* target_obj = (ASObject*) VAL(u64, &container_var.data.numeric_value);
							if (target_obj != NULL) {
								existing = getProperty(target_obj, final_prop, final_prop_len);
							}
						}
					}

					if (existing != NULL && existing->type != ACTION_STACK_VALUE_UNDEFINED) {
						if (existing->type == ACTION_STACK_VALUE_STRING) {
							if (existing->str_size > 0) {
								text_from_var = varGetU16Ptr(existing);
								tfv_len = existing->str_size;
							}
						} else {
							char _tfv_conv[512];
							int n = varToStringBuf(app_context, existing, _tfv_conv, sizeof(_tfv_conv));
							if (n > 0) {
								u32 _tfv_u16_len;
								text_from_var = utf8_to_u16(app_context, _tfv_conv, (u32)n, &_tfv_u16_len);
								tfv_len = _tfv_u16_len;
							}
						}
					}

					if (text_from_var != NULL) {
						ActionVar tfv_val = {0};
						tfv_val.type = ACTION_STACK_VALUE_STRING;
						tfv_val.str_size = tfv_len;
						VAL(u64, &tfv_val.data.numeric_value) = (u64)text_from_var;
						setProperty(app_context, props, "text", 4, &tfv_val);
						ActionVar tfv_len_val = {0};
						tfv_len_val.type = ACTION_STACK_VALUE_F64;
						VAL(double, &tfv_len_val.data.numeric_value) = (double)tfv_len;
						setProperty(app_context, props, "length", 6, &tfv_len_val);
					}
				}
			}
		}
	}
#endif
	if (is_new && mc != NULL) {
		// Only add to cache if it's a brand new MC (not a re-init of cached one)
		int already_cached = 0;
		for (int i = 0; i < child_mc_count; i++) {
			if (child_mc_cache[i] == mc) { already_cached = 1; break; }
		}
		if (!already_cached && child_mc_count < MAX_CHILD_MOVIECLIPS) {
			child_mc_cache[child_mc_count++] = mc;
		}
	}
	return mc;
}

// Public wrapper for findOrCreateMovieClip (callable from tag_stubs.c and generated code)
MovieClip* actionFindOrCreateMovieClip(SWFAppContext* app_context, const char* instance_name, MovieClip* parent) {
	return findOrCreateMovieClip(app_context, instance_name, parent);
}

// Invalidate cached MovieClip when a display entry is removed (e.g., tagRemoveObject2).
// Clears dynamic_props so the MC starts fresh if re-placed with the same name.
void actionInvalidateCachedMovieClip(SWFAppContext* app_context, const char* name)
{
	for (int i = 0; i < child_mc_count; i++) {
		if (child_mc_cache[i] != NULL && strcmp(child_mc_cache[i]->name, name) == 0) {
			// Just clear the pointer — the ASObject will leak but avoids
			// double-free issues with shared __proto__ references
			child_mc_cache[i]->dynamic_props = NULL;
			child_mc_cache[i]->ng_textfield_idx = -1;
			break;
		}
	}
}

// Fire the AS-set onUnload handler on a MovieClip being removed from the display list.
// Called by ng_on_remove_object (tag_stubs.c) BEFORE actionInvalidateCachedMovieClip,
// so that dynamic_props is still intact when we look up the handler.
// This is SYNCHRONOUS — used for timeline clips removed by tagRemoveObject2.
void actionFireOnUnload(SWFAppContext* app_context, const char* instance_name)
{
	if (instance_name == NULL || instance_name[0] == '\0') return;
	if (g_execution_halted) return;

	// Find the MC by name in the cache
	MovieClip* target_mc = NULL;
	for (int i = 0; i < child_mc_count; i++) {
		if (child_mc_cache[i] != NULL && strcmp(child_mc_cache[i]->name, instance_name) == 0) {
			target_mc = child_mc_cache[i];
			break;
		}
	}
	if (target_mc == NULL || target_mc->dynamic_props == NULL) return;

	// Look up "onUnload" property on the MC's dynamic_props
	ActionVar* handler = getProperty((ASObject*)target_mc->dynamic_props, "onUnload", 8);
	if (handler == NULL || handler->type != ACTION_STACK_VALUE_FUNCTION) return;

	ASFunction* func = (ASFunction*) handler->data.numeric_value;
	if (func == NULL) return;

	// Set context to the MC and invoke the handler with no arguments
	MovieClip* saved_context = g_current_context;
	actionSetCurrentContext(target_mc);
	invokeSpecialFunction(app_context, func, NULL);
	actionSetCurrentContext(saved_context);
}

// --- Deferred onUnload queue ---
// When removeMovieClip/actionRemoveSprite removes a dynamic clip, the AS-set onUnload
// handler is queued here and fired at ShowFrame time (between frames), matching Flash.
#define MAX_PENDING_UNLOADS 64
typedef struct { ASFunction* func; MovieClip* mc; } PendingUnload;
static PendingUnload g_pending_unloads[MAX_PENDING_UNLOADS];
static int g_pending_unload_count = 0;

// Enqueue an onUnload handler to fire at next ShowFrame.
static void queueOnUnload(ASFunction* func, MovieClip* mc)
{
	if (g_pending_unload_count < MAX_PENDING_UNLOADS) {
		g_pending_unloads[g_pending_unload_count].func = func;
		g_pending_unloads[g_pending_unload_count].mc   = mc;
		g_pending_unload_count++;
	}
}

// Fire all queued onUnload handlers (called from tagShowFrame in tag.c).
void actionFirePendingUnloads(SWFAppContext* app_context)
{
	int count = g_pending_unload_count;
	g_pending_unload_count = 0;  // reset first (handlers may queue more)
	for (int i = 0; i < count; i++) {
		if (g_execution_halted) break;
		MovieClip* saved = g_current_context;
		actionSetCurrentContext(g_pending_unloads[i].mc);
		invokeSpecialFunction(app_context, g_pending_unloads[i].func, NULL);
		actionSetCurrentContext(saved);
	}
}

#ifdef NO_GRAPHICS
// Rename a MovieClip in the cache (called after tagSetInstanceName updates ng_display).
// Updates the MC's name and target path to reflect the new name.
void actionRenameMovieClip(const char* old_name, const char* new_name)
{
	for (int i = 0; i < child_mc_count; i++) {
		if (child_mc_cache[i] == NULL) continue;
		if (strcmp(child_mc_cache[i]->name, old_name) != 0) continue;
		MovieClip* mc = child_mc_cache[i];
		MovieClip* parent = mc->parent;
		strncpy(mc->name, new_name, sizeof(mc->name) - 1);
		mc->name[sizeof(mc->name) - 1] = '\0';
		// Rebuild target path
		if (parent == NULL) {
			strncpy(mc->target, new_name, sizeof(mc->target) - 1);
		} else {
			int parent_len = strlen(parent->target);
			if (parent_len == 1 && parent->target[0] == '/') {
				snprintf(mc->target, sizeof(mc->target), "/%s", new_name);
			} else {
				snprintf(mc->target, sizeof(mc->target), "%s/%s", parent->target, new_name);
			}
		}
		mc->target[sizeof(mc->target) - 1] = '\0';
		// Re-sync position from the display list. The display entry still has old_name
		// at this call point (tagSetInstanceName updates it after calling us), so
		// ng_findDisplayEntryByName(old_name) finds the correct entry.
		// This fixes MCs that were created during eager init while the display_list
		// was swapped (giving x=0), ensuring they get the correct SWF transform.
		{
			size_t depth = ng_findDisplayEntryByName(old_name);
			if (depth != SIZE_MAX) {
				mc->depth = (int)depth - 16384;
				if (!(mc->as_set_flags & 1) || !(mc->as_set_flags & 2)) {
					float init_x, init_y;
					if (ng_getTransformXY(depth, &init_x, &init_y)) {
						if (!(mc->as_set_flags & 1)) mc->x = init_x;
						if (!(mc->as_set_flags & 2)) mc->y = init_y;
					}
				}
				if (!(mc->as_set_flags & (4|8|16))) {
					float init_xs, init_ys, init_rot;
					if (ng_getTransformScaleRotation(depth, &init_xs, &init_ys, &init_rot)) {
						mc->xscale = init_xs;
						mc->yscale = init_ys;
						mc->rotation = init_rot;
					}
				}
				u32 tid;
				if (ng_getTransformId(depth, &tid)) {
					mc->last_transform_id = tid;
				}
			}
		}
		return;
	}
}
#endif

#ifdef NO_GRAPHICS
// ==================================================================
// TextField Variable Binding
// ==================================================================
// Bidirectional binding between a variable name and a text field's "text" property.
// When the variable changes, all bound text fields update. When text changes, the
// variable updates and other bound fields sync.

// Called from tag_stubs.c when a textfield is placed on the display list.
// Creates the variable with init_text if it doesn't exist.
// If it already exists, does nothing (the MC will pick up the value at creation time).
void actionInitTextFieldVariable(SWFAppContext* app_context, const char* var_name, const char* init_text)
{
	(void)app_context;
	if (var_name == NULL || var_name[0] == '\0') return;

	// Convert init_text to UTF-16 once for use throughout this function
	u32 _inittext_u16_len;
	uint16_t* _inittext_u16 = utf8_to_u16(app_context, init_text, (u32)strlen(init_text), &_inittext_u16_len);

	if (strchr(var_name, '.') != NULL) {
		// Path variable (e.g., "_root.mc.theVar") — resolve and set
		// Find the last dot to split container path and property name
		const char* last_dot = var_name;
		for (const char* p = var_name; *p; p++) {
			if (*p == '.') last_dot = p;
		}
		u32 container_len = (u32)(last_dot - var_name);
		const char* final_prop = last_dot + 1;
		u32 final_prop_len = strlen(final_prop);

		// Resolve container
		PUSH_STR(var_name, container_len);
		actionGetVariable(app_context);
		ActionVar container_var;
		peekVar(app_context, &container_var);
		POP();

		if (container_var.type == ACTION_STACK_VALUE_MOVIECLIP) {
			MovieClip* target_mc = (MovieClip*) VAL(u64, &container_var.data.numeric_value);
			if (target_mc != NULL) {
				ASObject* target_props = (ASObject*) target_mc->dynamic_props;
				if (target_props != NULL) {
					ActionVar* existing = getProperty(target_props, final_prop, final_prop_len);
					if (existing != NULL && existing->type != ACTION_STACK_VALUE_UNDEFINED)
						return;  // Already set, don't overwrite
				}
				if (target_props == NULL) {
					target_mc->dynamic_props = (void*) allocObject(app_context, 8);
					target_props = (ASObject*) target_mc->dynamic_props;
				}
				ActionVar init_val = {0};
				init_val.type = ACTION_STACK_VALUE_STRING;
				init_val.str_size = _inittext_u16_len;
				VAL(u64, &init_val.data.numeric_value) = (u64)_inittext_u16;
				setProperty(app_context, target_props, final_prop, final_prop_len, &init_val);
			}
		} else if (container_var.type == ACTION_STACK_VALUE_OBJECT) {
			ASObject* target_obj = (ASObject*) VAL(u64, &container_var.data.numeric_value);
			if (target_obj != NULL) {
				ActionVar* existing = getProperty(target_obj, final_prop, final_prop_len);
				if (existing != NULL && existing->type != ACTION_STACK_VALUE_UNDEFINED)
					return;  // Already set, don't overwrite
				ActionVar init_val = {0};
				init_val.type = ACTION_STACK_VALUE_STRING;
				init_val.str_size = _inittext_u16_len;
				VAL(u64, &init_val.data.numeric_value) = (u64)_inittext_u16;
				setProperty(app_context, target_obj, final_prop, final_prop_len, &init_val);
			}
		}
		return;
	}

	// Simple variable — create in global scope if not already defined
	extern bool hasVariable(char* var_name, size_t key_size);
	size_t vlen = strlen(var_name);
	if (!hasVariable((char*)var_name, vlen)) {
		// Only create if there's initial text (empty textfield doesn't set variable)
		if (init_text[0] != '\0') {
			ActionVar init_val = {0};
			init_val.type = ACTION_STACK_VALUE_STRING;
			init_val.str_size = _inittext_u16_len;
			VAL(u64, &init_val.data.numeric_value) = (u64)_inittext_u16;
			setVariableByName(var_name, &init_val);
		}
	}
}

// Sync variable → all text fields bound to var_name
// Called when a variable is set via SetVariable/DefineLocal/etc.
static void ng_syncVarToTextFields(SWFAppContext* app_context, const char* var_name, u32 var_name_len, ActionVar* value)
{
	(void)app_context;
	// Convert value to UTF-16 string for setting text
	const uint16_t* text_u16 = NULL;
	u32 text_len = 0;
	if (value->type == ACTION_STACK_VALUE_STRING) {
		text_u16 = varGetU16Ptr(value);
		text_len = value->str_size;
	} else if (value->type != ACTION_STACK_VALUE_UNDEFINED) {
		char _sv_buf[512];
		int n = varToStringBuf(app_context, value, _sv_buf, sizeof(_sv_buf));
		if (n > 0) {
			u32 _sv_u16_len;
			text_u16 = utf8_to_u16(app_context, _sv_buf, (u32)n, &_sv_u16_len);
			text_len = _sv_u16_len;
		}
	} else {
		return;  // undefined doesn't sync
	}

	for (int i = 0; i < child_mc_count; i++) {
		MovieClip* mc = child_mc_cache[i];
		if (mc == NULL || mc->ng_textfield_idx < 0) continue;
		ASObject* props = (ASObject*) mc->dynamic_props;
		if (props == NULL) continue;
		ActionVar* var_prop = getProperty(props, "variable", 8);
		if (var_prop == NULL || var_prop->type != ACTION_STACK_VALUE_STRING) continue;
		const uint16_t* _bound_u16 = varGetU16Ptr(var_prop);
		char _bound_buf[512];
		if (_bound_u16 && var_prop->str_size > 0)
			u16_to_utf8(_bound_u16, var_prop->str_size, _bound_buf, sizeof(_bound_buf));
		else
			_bound_buf[0] = '\0';
		const char* bound = _bound_buf;
		if (bound[0] == '\0') continue;
		// Compare (case-insensitive for SWF<=6)
		int match = (g_swf_version < 7) ? (strcasecmp(bound, var_name) == 0) : (strcmp(bound, var_name) == 0);
		if (match) {
			ActionVar text_val = {0};
			text_val.type = ACTION_STACK_VALUE_STRING;
			text_val.str_size = text_len;
			VAL(u64, &text_val.data.numeric_value) = (u64)text_u16;
			setProperty(app_context, props, "text", 4, &text_val);
			// Update length
			ActionVar len_val = {0};
			len_val.type = ACTION_STACK_VALUE_F64;
			VAL(double, &len_val.data.numeric_value) = (double)text_len;
			setProperty(app_context, props, "length", 6, &len_val);
		}
	}
}

// Sync text → variable, then variable → other bound text fields
// Called when "text" property is set on a textfield MovieClip.
static void ng_syncTextToVar(SWFAppContext* app_context, MovieClip* mc, ActionVar* text_value)
{
	if (mc == NULL || mc->ng_textfield_idx < 0) return;
	ASObject* props = (ASObject*) mc->dynamic_props;
	if (props == NULL) return;
	ActionVar* var_prop = getProperty(props, "variable", 8);
	if (var_prop == NULL || var_prop->type != ACTION_STACK_VALUE_STRING) return;
	const uint16_t* _vn_u16 = varGetU16Ptr(var_prop);
	char _vn_buf[512];
	if (_vn_u16 && var_prop->str_size > 0)
		u16_to_utf8(_vn_u16, var_prop->str_size, _vn_buf, sizeof(_vn_buf));
	else
		_vn_buf[0] = '\0';
	const char* var_name = _vn_buf;
	if (var_name[0] == '\0') return;

	// Handle dot-path variables (e.g., "obj.theVar")
	const char* dot = strchr(var_name, '.');
	if (dot != NULL) {
		// For path variables, resolve the path and set the property
		const char* last_dot = dot;
		for (const char* p = dot + 1; *p; p++) {
			if (*p == '.') last_dot = p;
		}
		u32 container_len = (u32)(last_dot - var_name);
		const char* final_prop = last_dot + 1;
		u32 final_prop_len = strlen(final_prop);
		// Resolve container
		PUSH_STR(var_name, container_len);
		actionGetVariable(app_context);
		ActionVar container_var;
		peekVar(app_context, &container_var);
		POP();
		int container_resolved = 0;
		if (container_var.type == ACTION_STACK_VALUE_MOVIECLIP) {
			MovieClip* target_mc = (MovieClip*) VAL(u64, &container_var.data.numeric_value);
			if (target_mc != NULL) {
				ASObject* target_props = (ASObject*) target_mc->dynamic_props;
				if (target_props == NULL) {
					target_mc->dynamic_props = (void*) allocObject(app_context, 8);
					target_props = (ASObject*) target_mc->dynamic_props;
				}
				setProperty(app_context, target_props, final_prop, final_prop_len, text_value);
				container_resolved = 1;
			}
		} else if (container_var.type == ACTION_STACK_VALUE_OBJECT) {
			ASObject* target_obj = (ASObject*) VAL(u64, &container_var.data.numeric_value);
			if (target_obj != NULL) {
				setProperty(app_context, target_obj, final_prop, final_prop_len, text_value);
				container_resolved = 1;
			}
		}
		// Also sync to other text fields with the same path variable binding
		// (only if the container was successfully resolved)
		if (!container_resolved) return;
		u32 full_var_len = strlen(var_name);
		for (int i = 0; i < child_mc_count; i++) {
			MovieClip* other = child_mc_cache[i];
			if (other == mc || other == NULL || other->ng_textfield_idx < 0) continue;
			ASObject* other_props = (ASObject*) other->dynamic_props;
			if (other_props == NULL) continue;
			ActionVar* other_var = getProperty(other_props, "variable", 8);
			if (other_var == NULL || other_var->type != ACTION_STACK_VALUE_STRING) continue;
			const uint16_t* _ob_u16 = varGetU16Ptr(other_var);
			char _ob_buf[512];
			if (_ob_u16 && other_var->str_size > 0)
				u16_to_utf8(_ob_u16, other_var->str_size, _ob_buf, sizeof(_ob_buf));
			else
				_ob_buf[0] = '\0';
			const char* other_bound = _ob_buf;
			if (other_bound[0] == '\0') continue;
			int match = (g_swf_version < 7)
			? (strcasecmp(other_bound, var_name) == 0)
			: (strncmp(other_bound, var_name, full_var_len) == 0 && other_bound[full_var_len] == '\0');
			if (match) {
				setProperty(app_context, other_props, "text", 4, text_value);
				ActionVar len_val = {0};
				len_val.type = ACTION_STACK_VALUE_F64;
				u32 _ts_len = (text_value->type == ACTION_STACK_VALUE_STRING) ?
					text_value->str_size : 0;
				VAL(double, &len_val.data.numeric_value) = (double)_ts_len;
				setProperty(app_context, other_props, "length", 6, &len_val);
			}
		}
		return;
	}

	// Simple variable name — update global variable
	setVariableByName(var_name, text_value);

	// Also sync to all other text fields with the same binding
	u32 var_name_len = strlen(var_name);
	for (int i = 0; i < child_mc_count; i++) {
		MovieClip* other = child_mc_cache[i];
		if (other == mc || other == NULL || other->ng_textfield_idx < 0) continue;
		ASObject* other_props = (ASObject*) other->dynamic_props;
		if (other_props == NULL) continue;
		ActionVar* other_var = getProperty(other_props, "variable", 8);
		if (other_var == NULL || other_var->type != ACTION_STACK_VALUE_STRING) continue;
		const uint16_t* _ob2_u16 = varGetU16Ptr(other_var);
		char _ob2_buf[512];
		if (_ob2_u16 && other_var->str_size > 0)
			u16_to_utf8(_ob2_u16, other_var->str_size, _ob2_buf, sizeof(_ob2_buf));
		else
			_ob2_buf[0] = '\0';
		const char* other_bound = _ob2_buf;
		if (other_bound[0] == '\0') continue;
		int match = (g_swf_version < 7) ? (strcasecmp(other_bound, var_name) == 0) : (strcmp(other_bound, var_name) == 0);
		if (match) {
			setProperty(app_context, other_props, "text", 4, text_value);
			ActionVar len_val = {0};
			len_val.type = ACTION_STACK_VALUE_F64;
			u32 _ts2_len = (text_value->type == ACTION_STACK_VALUE_STRING) ?
				text_value->str_size : 0;
			VAL(double, &len_val.data.numeric_value) = (double)_ts2_len;
			setProperty(app_context, other_props, "length", 6, &len_val);
		}
	}
}

// Flash normalizes _rotation to the range (-180, 180].
static float normalizeRotation(float r) {
	r = fmodf(r, 360.0f);
	if (r > 180.0f) r -= 360.0f;
	else if (r < -180.0f) r += 360.0f;
	return r;
}

// Re-sync x/y/xscale/yscale/rotation from transform_data if the display entry's transform_id
// has changed since the last sync, but only for properties not explicitly set by ActionScript.
// This handles PlaceObject2 updates (move/rotate/scale operations) without overwriting AS-set values.
// as_set_flags bits: 1=_x, 2=_y, 4=_xscale, 8=_yscale, 16=_rotation
static void syncTransformIfNeeded(MovieClip* mc) {
	if (mc == NULL || mc->name[0] == '\0') return;
	size_t depth = ng_findDisplayEntryByName(mc->name);
	if (depth == SIZE_MAX) return;
	u32 tid;
	if (!ng_getTransformId(depth, &tid)) return;
	if (tid == mc->last_transform_id) return;
	// Transform changed — sync properties that weren't set by AS
	float tx, ty;
	if (ng_getTransformXY(depth, &tx, &ty)) {
		if (!(mc->as_set_flags & 1)) mc->x = tx;
		if (!(mc->as_set_flags & 2)) mc->y = ty;
	}
	float xscale, yscale, rotation;
	if (ng_getTransformScaleRotation(depth, &xscale, &yscale, &rotation)) {
		if (!(mc->as_set_flags & 4))  mc->xscale = xscale;
		if (!(mc->as_set_flags & 8))  mc->yscale = yscale;
		if (!(mc->as_set_flags & 16)) mc->rotation = normalizeRotation(rotation);
	}
	mc->last_transform_id = tid;
}
#endif

static void mcGetEffectiveSize(MovieClip* mc, double* eff_w, double* eff_h)
{
	double scaled_w = (double)mc->width * mc->xscale / 100.0;
	double scaled_h = (double)mc->height * mc->yscale / 100.0;

#ifdef NO_GRAPHICS
	// If width/height not explicitly set, compute from display hierarchy bounds
	if (scaled_w == 0.0 && scaled_h == 0.0) {
		float gxmin, gxmax, gymin, gymax;
		size_t entry_idx;
		if (mc == &root_movieclip) {
			entry_idx = (size_t)-1;
		} else {
			entry_idx = ng_findDisplayEntryIdx(mc->name);
		}
		if (ng_getDisplayEntryBounds(entry_idx, &gxmin, &gxmax, &gymin, &gymax)) {
			double nat_w = (double)(gxmax - gxmin);
			double nat_h = (double)(gymax - gymin);
			scaled_w = nat_w * mc->xscale / 100.0;
			scaled_h = nat_h * mc->yscale / 100.0;
		}
	}
#endif

	double rot = mc->rotation;
	// _width/_height are always positive bounding-box dimensions (Flash convention)
	double abs_sw = fabs(scaled_w);
	double abs_sh = fabs(scaled_h);
	if (rot == 0.0) {
		*eff_w = abs_sw;
		*eff_h = abs_sh;
	} else {
		double rot_rad = rot * 3.14159265358979323846 / 180.0;
		double c = fabs(cos(rot_rad));
		double s = fabs(sin(rot_rad));
		double sw_twips = abs_sw * 20.0;
		double sh_twips = abs_sh * 20.0;
		*eff_w = (round(sw_twips * c) + round(sh_twips * s)) / 20.0;
		*eff_h = (round(sw_twips * s) + round(sh_twips * c)) / 20.0;
	}
}

// Set _width on a MovieClip by adjusting xscale to achieve the desired bounding width.
// In Flash, setting _width adjusts xscale; mc->width is not a persistent field.
static void mcSetEffectiveWidth(SWFAppContext* app_context, MovieClip* mc, double v)
{
#ifdef NO_GRAPHICS
	// TextFields store _width as a direct bounding-box dimension, not via xscale.
	if (mc != NULL && mc->ng_textfield_idx >= 0) {
		mc->width = (float)v;
		return;
	}
	if (mc != NULL && v >= 0.0) {
		size_t entry_idx;
		if (mc == &root_movieclip) {
			entry_idx = (size_t)-1;
		} else {
			entry_idx = ng_findDisplayEntryIdx(mc->name);
			if (entry_idx == (size_t)-1) {
				// MC not in the display list (e.g. programmatic createTextField).
				// Fall through to direct mc->width assignment.
				goto set_width_direct;
			}
		}
		float gxmin, gxmax, gymin, gymax;
		if (ng_getDisplayEntryBounds(entry_idx, &gxmin, &gxmax, &gymin, &gymax)) {
			double nat_w = (double)(gxmax - gxmin);
			if (nat_w > 0.01) {
				float sign = mc->xscale < 0.0f ? -1.0f : 1.0f;
				mc->xscale = (float)(v / nat_w * 100.0 * sign);
				mc->width = 0.0f;
				mc->as_set_flags |= 4;  // mark _xscale as AS-set
				return;
			}
		}
	}
	set_width_direct:;
#endif
	(void)app_context;
	if (mc) mc->width = (float)v;
}

// Set _height on a MovieClip by adjusting yscale to achieve the desired bounding height.
static void mcSetEffectiveHeight(SWFAppContext* app_context, MovieClip* mc, double v)
{
#ifdef NO_GRAPHICS
	// TextFields store _height as a direct bounding-box dimension, not via yscale.
	if (mc != NULL && mc->ng_textfield_idx >= 0) {
		mc->height = (float)v;
		return;
	}
	if (mc != NULL && v >= 0.0) {
		size_t entry_idx;
		if (mc == &root_movieclip) {
			entry_idx = (size_t)-1;
		} else {
			entry_idx = ng_findDisplayEntryIdx(mc->name);
			if (entry_idx == (size_t)-1) {
				// MC not in the display list (e.g. programmatic createTextField).
				// Fall through to direct mc->height assignment.
				goto set_height_direct;
			}
		}
		float gxmin, gxmax, gymin, gymax;
		if (ng_getDisplayEntryBounds(entry_idx, &gxmin, &gxmax, &gymin, &gymax)) {
			double nat_h = (double)(gymax - gymin);
			if (nat_h > 0.01) {
				float sign = mc->yscale < 0.0f ? -1.0f : 1.0f;
				mc->yscale = (float)(v / nat_h * 100.0 * sign);
				mc->height = 0.0f;
				mc->as_set_flags |= 8;  // mark _yscale as AS-set
				return;
			}
		}
	}
	set_height_direct:;
#endif
	(void)app_context;
	if (mc) mc->height = (float)v;
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
MovieClip* g_current_context = NULL;

// Set the current execution context
void actionSetCurrentContext(MovieClip* mc) {
	g_current_context = mc;
}
static void setCurrentContext(MovieClip* mc) {
	g_current_context = mc;
}

#ifdef NO_GRAPHICS
// Set when actionSetTarget() explicitly redirects to root ("_root" or "").
// Allows actionGotoFrame() to distinguish "goto root" (deferred) vs
// "goto sprite that has no instance name" (apply to sprite immediately).
// Reset by exec_sprite_frame() at sprite-frame entry so each sprite starts fresh.
int g_settarget_explicit_root = 0;
#endif

// Get the current execution context
static MovieClip* getCurrentContext(void) {
	return g_current_context ? g_current_context : &root_movieclip;
}

ActionStackValueType convertString(SWFAppContext* app_context, char* var_str)
{
	(void)var_str; // var_str is unused now; all paths produce UTF-16 directly
	switch (STACK_TOP_TYPE)
	{
		case ACTION_STACK_VALUE_F32:
		{
			float temp_val = VAL(float, &STACK_TOP_VALUE);
			if (isnan(temp_val)) { STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING; VAL(u64, &STACK_TOP_VALUE) = (u64) u16_NaN; STACK_TOP_N = 3; break; }
			if (isinf(temp_val)) {
				const uint16_t* s = temp_val < 0 ? u16_neg_Infinity : u16_Infinity;
				u32 len = temp_val < 0 ? 9 : 8;
				STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING; VAL(u64, &STACK_TOP_VALUE) = (u64) s; STACK_TOP_N = len; break;
			}
			char tmp[32];
			snprintf(tmp, sizeof(tmp), "%.15g", temp_val);
			u32 u16_len;
			uint16_t* u16 = ascii_to_u16(app_context, tmp, (int)strlen(tmp), &u16_len);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) u16;
			STACK_TOP_N = u16_len;
			break;
		}
		case ACTION_STACK_VALUE_F64:
		{
			double temp_val = VAL(double, &STACK_TOP_VALUE);
			if (isnan(temp_val)) { STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING; VAL(u64, &STACK_TOP_VALUE) = (u64) u16_NaN; STACK_TOP_N = 3; break; }
			if (isinf(temp_val)) {
				const uint16_t* s = temp_val < 0 ? u16_neg_Infinity : u16_Infinity;
				u32 len = temp_val < 0 ? 9 : 8;
				STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING; VAL(u64, &STACK_TOP_VALUE) = (u64) s; STACK_TOP_N = len; break;
			}
			char tmp[32];
			snprintf(tmp, sizeof(tmp), "%.15g", temp_val);
			u32 u16_len;
			uint16_t* u16 = ascii_to_u16(app_context, tmp, (int)strlen(tmp), &u16_len);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) u16;
			STACK_TOP_N = u16_len;
			break;
		}
		case ACTION_STACK_VALUE_BOOLEAN:
		{
			u64 val = STACK_TOP_VALUE;
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			if (EFFECTIVE_SWF_VERSION() < 5)
			{
				VAL(u64, &STACK_TOP_VALUE) = (u64)(val ? u16_one : u16_zero);
				STACK_TOP_N = 1;
			}
			else
			{
				VAL(u64, &STACK_TOP_VALUE) = (u64)(val ? u16_true : u16_false);
				STACK_TOP_N = val ? 4 : 5;
			}
			break;
		}
		case ACTION_STACK_VALUE_UNDEFINED:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			if (g_swf_version >= 7) {
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16_undefined;
				STACK_TOP_N = 9;
			} else {
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16_empty;
				STACK_TOP_N = 0;
			}
			break;
		}
		case ACTION_STACK_VALUE_NULL:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) u16_null;
			STACK_TOP_N = 4;
			break;
		}
		case ACTION_STACK_VALUE_FUNCTION:
		{
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			VAL(u64, &STACK_TOP_VALUE) = (u64) u16_type_Function;
			STACK_TOP_N = 15;
			break;
		}
		case ACTION_STACK_VALUE_MOVIECLIP:
		{
			MovieClip* mc = (MovieClip*) VAL(u64, &STACK_TOP_VALUE);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			extern MovieClip root_movieclip;
			if (mc != NULL && mc != &root_movieclip && mc->name[0] != '\0')
			{
				// Child MovieClip: use full dot-path "_level0.parent.child" from mc->target
				static char mc_path_buf[256];
				const char* tgt = mc->target;
				if (tgt[0] == '/' && tgt[1] == '\0') {
					strncpy(mc_path_buf, "_level0", sizeof(mc_path_buf));
				} else if (tgt[0] == '/') {
					char tmp[200];
					strncpy(tmp, tgt + 1, sizeof(tmp) - 1);
					tmp[sizeof(tmp) - 1] = '\0';
					for (char* p = tmp; *p; p++) { if (*p == '/') *p = '.'; }
					snprintf(mc_path_buf, sizeof(mc_path_buf), "_level0.%s", tmp);
				} else {
					snprintf(mc_path_buf, sizeof(mc_path_buf), "_level0.%s", mc->name);
				}
				u32 u16_len;
				uint16_t* u16 = ascii_to_u16(app_context, mc_path_buf, (int)strlen(mc_path_buf), &u16_len);
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16;
				STACK_TOP_N = u16_len;
			}
			else
			{
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16_level0;
				STACK_TOP_N = 7;
			}
			break;
		}
		case ACTION_STACK_VALUE_ARRAY:
		{
			ASArray* arr = (ASArray*) VAL(u64, &STACK_TOP_VALUE);
			if (arr != NULL && arr->length > 0)
			{
				// Join elements with commas (Flash Array.toString behavior)
				ActionVar comma_arg = {0};
				comma_arg.type = ACTION_STACK_VALUE_STRING;
				comma_arg.str_size = 1;
				VAL(u64, &comma_arg.data.numeric_value) = (u64) u16_comma;
				// callArrayMethod pushes result; POP the current array entry first
				POP();
				callArrayMethod(app_context, arr, "join", 4, &comma_arg, 1);
				// Result is now on stack top as a string
			}
			else
			{
				// Empty array -> empty string
				STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16_empty;
				STACK_TOP_N = 0;
			}
			break;
		}
		case ACTION_STACK_VALUE_OBJECT:
		{
			ActionVar _cs_obj;
			_cs_obj.type = ACTION_STACK_VALUE_OBJECT;
			_cs_obj.data.numeric_value = STACK_TOP_VALUE;
			int _cs_found = 0;
			ActionVar _cs_ts = objectCallToString(app_context, &_cs_obj, &_cs_found);
			STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
			if (_cs_found && _cs_ts.type == ACTION_STACK_VALUE_STRING) {
				VAL(u64, &STACK_TOP_VALUE) = _cs_ts.data.numeric_value;
				STACK_TOP_N = _cs_ts.str_size;
			} else {
				VAL(u64, &STACK_TOP_VALUE) = (u64) u16_object_Object;
				STACK_TOP_N = 15;
			}
			break;
		}
		default:
			// STRING already UTF-16; other types leave as-is
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
		{
			// UTF-16 string: truthy if non-empty
			return var->str_size > 0;
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
		{
			// Convert UTF-16 string to UTF-8 for numeric parsing
			char utf8_buf[256];
			const uint16_t* u16_str = (const uint16_t*) VAL(u64, &STACK_TOP_VALUE);
			u32 u16_len = STACK_TOP_N;
			char* str = NULL;
			if (u16_str != NULL && u16_len > 0)
			{
				int utf8_len = u16_to_utf8(u16_str, u16_len, utf8_buf, sizeof(utf8_buf));
				utf8_buf[utf8_len] = '\0';
				str = utf8_buf;
			}
			if (str != NULL && str[0] != '\0')
			{
				char* end;
				double temp;
				int parsed = 0;
				if (g_swf_version >= 6) {
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
				}
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
					if (EFFECTIVE_SWF_VERSION() < 5)
						temp = 0.0;
					else
						temp = NAN;
				}
				// If there are trailing non-whitespace characters, it's NaN
				// Exception: SWF < 5 uses parseFloat semantics (accepts partial parses)
				else if (!parsed)
				{
					if (EFFECTIVE_SWF_VERSION() >= 5) {
					while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
					if (*end != '\0') temp = NAN;
					}
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
			double temp = (g_swf_version >= 7) ? NAN : 0.0;
			STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
			VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
			return ACTION_STACK_VALUE_F64;
		}

		case ACTION_STACK_VALUE_UNDEFINED:
		{
			// SWF < 7: undefined converts to 0.0
			// SWF >= 7: undefined converts to NaN (ECMA-262)
			double temp = (g_swf_version < 7) ? 0.0 : NAN;
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
			double temp = (g_swf_version < 7) ? 0.0 : NAN;
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
			// Pointers are now uint16_t* (UTF-16)
			uint16_t* str_ptr = var->data.string_data.owns_memory ?
				var->data.string_data.heap_ptr :
				(uint16_t*) var->data.numeric_value;

			PUSH_U16_ID(str_ptr, var->str_size, var->string_id);

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
	if (SP >= INITIAL_STACK_SIZE)
	{
		var->type = ACTION_STACK_VALUE_UNDEFINED;
		var->str_size = 0;
		var->data.numeric_value = 0;
		var->string_id = 0;
		return;
	}
	var->type = STACK_TOP_TYPE;
	var->str_size = STACK_TOP_N;

	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
	{
		// String pointer is now uint16_t* (UTF-16); store in numeric_value, mark as not owning
		var->data.numeric_value = VAL(u64, &STACK_TOP_VALUE);
		var->data.string_data.owns_memory = false;
		var->string_id = VAL(u32, &STACK[SP + 12]);
	}
	else
	{
		var->data.numeric_value = VAL(u64, &STACK_TOP_VALUE);
		var->string_id = 0;
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

	if (STACK[second_sp] == ACTION_STACK_VALUE_STRING)
	{
		// String pointer is now uint16_t* (UTF-16); store in numeric_value, mark as not owning
		var->data.numeric_value = VAL(u64, &STACK[second_sp + 16]);
		var->data.string_data.owns_memory = false;
		var->string_id = VAL(u32, &STACK[second_sp + 12]);
	}
	else
	{
		var->data.numeric_value = VAL(u64, &STACK[second_sp + 16]);
		var->string_id = 0;
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

// Returns 1 if obj_var is a Date instance (has __proto__ == g_date_prototype) in SWF6+.
// Date objects use toString-first ToPrimitive for Add2 (ECMAScript Date [[DefaultValue]]).
static int isDateObjectSWF6(ActionVar* obj_var)
{
	if (g_swf_version < 6) return 0;
	if (obj_var->type != ACTION_STACK_VALUE_OBJECT) return 0;
	if (g_date_prototype == NULL) return 0;
	ASObject* obj = (ASObject*) obj_var->data.numeric_value;
	if (obj == NULL) return 0;
	ActionVar* proto_prop = getProperty(obj, "__proto__", 9);
	if (proto_prop == NULL) return 0;
	if (proto_prop->type != ACTION_STACK_VALUE_OBJECT) return 0;
	ASObject* proto = (ASObject*) proto_prop->data.numeric_value;
	return (proto == g_date_prototype);
}

void actionAdd2(SWFAppContext* app_context, char* str_buffer)
{
	// Flash Add2 algorithm:
	// 1. Pop both operands
	// 2. Call ToPrimitive on each object operand (right first for Flash evaluation order)
	//    - For regular objects: valueOf-first (number hint)
	//    - For Date objects in SWF6+: toString-first (string hint, ECMAScript Date spec)
	// 3. If either raw type or ToPrimitive result is a string → string concatenation
	//    - Objects with primitive ToPrimitive: convert that primitive to string
	//    - Objects with non-primitive ToPrimitive: call toString, fallback to "[type Object]"
	//    - Objects with no ToPrimitive: use convertString → "[type Object]"
	// 4. Else → numeric addition using original operands (convertFloat calls valueOf again)

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

	// Call ToPrimitive on object operands (right first for Flash evaluation order).
	// Date objects in SWF6+ use toString-first (string hint); others use valueOf-first.
	ActionVar a_vo = a_raw;
	int a_vo_found = 0;
	int a_vo_is_prim = !a_is_obj;  // non-objects are already primitive
	if (a_is_obj)
	{
		if (isDateObjectSWF6(&a_raw))
			a_vo = objectCallToString(app_context, &a_raw, &a_vo_found);
		else
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
		if (isDateObjectSWF6(&b_raw))
			b_vo = objectCallToString(app_context, &b_raw, &b_vo_found);
		else
			b_vo = objectCallValueOf(app_context, &b_raw, &b_vo_found);
		b_vo_is_prim = (b_vo.type != ACTION_STACK_VALUE_OBJECT &&
		                b_vo.type != ACTION_STACK_VALUE_ARRAY &&
		                b_vo.type != ACTION_STACK_VALUE_FUNCTION);
	}

	// Check if string path: either raw type or valueOf result is a string
	if (a_raw.type == ACTION_STACK_VALUE_STRING || b_raw.type == ACTION_STACK_VALUE_STRING ||
	    a_vo.type == ACTION_STACK_VALUE_STRING || b_vo.type == ACTION_STACK_VALUE_STRING)
	{
		// STRING CONCATENATION PATH (all strings are now UTF-16)
		char str_b_buf[17], str_a_buf[17];
		const uint16_t* u16_b = NULL;
		const uint16_t* u16_a = NULL;
		u32 len_b = 0, len_a = 0;

		// Helper macro: get UTF-16 from ActionVar after convertString+popVar
		#define GET_U16_FROM_VAR(var, ptr, len) do { \
			ptr = varGetU16Ptr(&(var)); \
			len = (var).str_size; \
			if (ptr == NULL) { ptr = u16_empty; len = 0; } \
		} while(0)

		// Get string for left operand (b)
		if (!b_is_obj)
		{
			pushVar(app_context, &b_raw);
			convertString(app_context, str_b_buf);
			ActionVar b_str; popVar(app_context, &b_str);
			GET_U16_FROM_VAR(b_str, u16_b, len_b);
		}
		else if (b_vo_is_prim)
		{
			pushVar(app_context, &b_vo);
			convertString(app_context, str_b_buf);
			ActionVar b_str; popVar(app_context, &b_str);
			GET_U16_FROM_VAR(b_str, u16_b, len_b);
		}
		else if (b_vo_found)
		{
			ActionVar ts = objectCallToString(app_context, &b_raw, NULL);
			if (ts.type == ACTION_STACK_VALUE_STRING)
				GET_U16_FROM_VAR(ts, u16_b, len_b);
			else
			{ u16_b = u16_type_Object; len_b = 13; }
		}
		else
		{
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &b_raw, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
				GET_U16_FROM_VAR(ts, u16_b, len_b);
			else if (ts_found)
			{ u16_b = u16_type_Object; len_b = 13; }
			else
			{
				pushVar(app_context, &b_raw);
				convertString(app_context, str_b_buf);
				ActionVar b_str; popVar(app_context, &b_str);
				GET_U16_FROM_VAR(b_str, u16_b, len_b);
			}
		}

		// Get string for right operand (a)
		if (!a_is_obj)
		{
			pushVar(app_context, &a_raw);
			convertString(app_context, str_a_buf);
			ActionVar a_str; popVar(app_context, &a_str);
			GET_U16_FROM_VAR(a_str, u16_a, len_a);
		}
		else if (a_vo_is_prim)
		{
			pushVar(app_context, &a_vo);
			convertString(app_context, str_a_buf);
			ActionVar a_str; popVar(app_context, &a_str);
			GET_U16_FROM_VAR(a_str, u16_a, len_a);
		}
		else if (a_vo_found)
		{
			ActionVar ts = objectCallToString(app_context, &a_raw, NULL);
			if (ts.type == ACTION_STACK_VALUE_STRING)
				GET_U16_FROM_VAR(ts, u16_a, len_a);
			else
			{ u16_a = u16_type_Object; len_a = 13; }
		}
		else
		{
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &a_raw, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
				GET_U16_FROM_VAR(ts, u16_a, len_a);
			else if (ts_found)
			{ u16_a = u16_type_Object; len_a = 13; }
			else
			{
				pushVar(app_context, &a_raw);
				convertString(app_context, str_a_buf);
				ActionVar a_str; popVar(app_context, &a_str);
				GET_U16_FROM_VAR(a_str, u16_a, len_a);
			}
		}

		#undef GET_U16_FROM_VAR

		// Concatenate (left + right = b + a)
		u32 result_len;
		uint16_t* result = u16_concat(app_context, u16_b, len_b, u16_a, len_a, &result_len);
		PUSH_U16(result, result_len);
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
		if (EFFECTIVE_SWF_VERSION() < 5)
		{
			// SWF4: divide by zero returns "#ERROR#"
			PUSH_STR("#ERROR#", 7);
		}
		else
		{
			// SWF5+: divide by zero returns Infinity/-Infinity/NaN
			double c = b_val / a_val;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}
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
		PUSH_STR("#ERROR#", 7);
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

	// Track which operands were objects
	int left_was_obj = (left.type == ACTION_STACK_VALUE_OBJECT || left.type == ACTION_STACK_VALUE_ARRAY);
	int right_was_obj = (right.type == ACTION_STACK_VALUE_OBJECT || right.type == ACTION_STACK_VALUE_ARRAY);

	// Convert objects to primitives (left first for correct valueOf evaluation order)
	// Distinguish "no valueOf found" (conversion failed → false) from
	// "valueOf returned undefined" (conversion succeeded → use undefined in comparison)
	if (left_was_obj)
	{
		int left_ok = 1;
		ActionVar prim = objectToPrimitive(app_context, &left, &left_ok);
		if (!left_ok)
		{
			// Left has no valueOf/toString at all — return false immediately
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
		}
		left = prim;
	}
	if (right_was_obj)
	{
		int right_ok = 1;
		ActionVar prim = objectToPrimitive(app_context, &right, &right_ok);
		if (!right_ok)
		{
			// Right has no valueOf/toString — return false
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
		}
		right = prim;
	}

	// If both are strings, lexicographic comparison
	int left_is_str = (left.type == ACTION_STACK_VALUE_STRING);
	int right_is_str = (right.type == ACTION_STACK_VALUE_STRING);

	if (left_is_str && right_is_str)
	{
		const uint16_t* l = varGetU16Ptr(&left);
		u32 l_len = left.str_size;
		const uint16_t* r = varGetU16Ptr(&right);
		u32 r_len = right.str_size;
		if (l == NULL) { l = u16_empty; l_len = 0; }
		if (r == NULL) { r = u16_empty; r_len = 0; }
		u64 bool_val = (u16_cmp(l, l_len, r, r_len) < 0) ? 1 : 0;
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
			// NaN comparison returns undefined in Flash (differs from ECMAScript)
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
	// Pop both, convert objects via objectToPrimitive, then compare.
	ActionVar right;
	popVar(app_context, &right);
	ActionVar left;
	popVar(app_context, &left);

	// Convert objects to primitives (with early bail if no valueOf/toString)
	int left_was_obj = (left.type == ACTION_STACK_VALUE_OBJECT || left.type == ACTION_STACK_VALUE_ARRAY);
	int right_was_obj = (right.type == ACTION_STACK_VALUE_OBJECT || right.type == ACTION_STACK_VALUE_ARRAY);

	if (left_was_obj)
	{
		int left_ok = 1;
		ActionVar prim = objectToPrimitive(app_context, &left, &left_ok);
		if (!left_ok)
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
		}
		left = prim;
	}
	if (right_was_obj)
	{
		int right_ok = 1;
		ActionVar prim = objectToPrimitive(app_context, &right, &right_ok);
		if (!right_ok)
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
		}
		right = prim;
	}

	// If both are strings, lexicographic comparison
	int left_is_str = (left.type == ACTION_STACK_VALUE_STRING);
	int right_is_str = (right.type == ACTION_STACK_VALUE_STRING);

	if (left_is_str && right_is_str)
	{
		const uint16_t* l = varGetU16Ptr(&left);
		u32 l_len = left.str_size;
		const uint16_t* r = varGetU16Ptr(&right);
		u32 r_len = right.str_size;
		if (l == NULL) { l = u16_empty; l_len = 0; }
		if (r == NULL) { r = u16_empty; r_len = 0; }
		u64 bool_val = (u16_cmp(l, l_len, r, r_len) > 0) ? 1 : 0;
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
			// NaN comparison returns undefined in Flash (differs from ECMAScript)
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
		{
			u32 slen = VAL(u32, &STACK[SP + 8]);
			is_truthy = (slen > 0);
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
			// Convert slash notation (mc->target) to dot notation for targetPath()
			// "/" -> "_level0", "/.clip" -> "_level0.clip"
			const char* path = mc->target;
			if (path[0] == '/' && path[1] == '\0') {
				// Root: "/" -> "_level0"
				strcpy(str_buffer, "_level0");
			} else if (path[0] == '/' && path[1] == '.') {
				// Child: "/.clip" -> "_level0.clip"
				snprintf(str_buffer, 256, "_level0%s", path + 1);
			} else {
				// Fallback: copy as-is
				strncpy(str_buffer, path, 256);
				str_buffer[255] = '\0';
			}
			int len = strlen(str_buffer);

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

// Callback for ng_enumerateChildren — pushes child instance name onto the ActionScript stack
#ifdef NO_GRAPHICS
static void enum_child_callback(const char* name, u32 name_len, void* user_data)
{
	SWFAppContext* app_context = (SWFAppContext*)user_data;
	PUSH_STR(name, name_len);
}
#endif

void actionEnumerate(SWFAppContext* app_context, char* str_buffer)
{
	// Step 1: Pop value from stack — must check type before reading as string
	u8 top_type = STACK[SP];

	char _en_buf[512];
	char* var_name = _en_buf;
	u32 var_name_len = 0;
	u32 string_id = 0;

	if (top_type == ACTION_STACK_VALUE_STRING)
	{
		// Normal case: pop string variable name
		string_id = VAL(u32, &STACK[SP + 12]);
		u32 _en_u16_len = VAL(u32, &STACK[SP + 8]);
		const uint16_t* u16_ptr = (const uint16_t*)VAL(u64, &STACK[SP + 16]);
		if (u16_ptr != NULL && _en_u16_len > 0)
			var_name_len = (u32)u16_to_utf8(u16_ptr, _en_u16_len, _en_buf, sizeof(_en_buf));
		POP();
	}
	else if (top_type == ACTION_STACK_VALUE_OBJECT)
	{
		// Flash's Enumerate opcode converts objects to "[object Object]"
		// regardless of SWF version (does NOT call toString()).
		POP();
		memcpy(_en_buf, "[object Object]", 15);
		_en_buf[15] = '\0';
		var_name_len = 15;
	}
	else
	{
		// Non-string on stack: convert to string, then use as variable name
		// Flash converts the value to a string and looks it up as a variable name
		convertString(app_context, str_buffer);
		// Now stack top is a string
		u32 _en_u16_len = VAL(u32, &STACK[SP + 8]);
		const uint16_t* u16_ptr = (const uint16_t*)VAL(u64, &STACK[SP + 16]);
		if (u16_ptr != NULL && _en_u16_len > 0)
			var_name_len = (u32)u16_to_utf8(u16_ptr, _en_u16_len, _en_buf, sizeof(_en_buf));
		POP();
	}

	// Step 2: Look up the variable
	ActionVar* var = NULL;
	ActionVar _en_dot_var;  // storage for dot-path or colon-path resolved value

	// Handle SWF4 colon-path syntax "target:variable" (e.g., "this:obj" means _root.obj)
	char* _en_colon = (var_name_len > 1) ? (char*)memchr(var_name, ':', var_name_len) : NULL;
	if (_en_colon != NULL)
	{
		u32 _en_target_len = (u32)(_en_colon - var_name);
		const char* _en_prop = _en_colon + 1;
		u32 _en_prop_len = var_name_len - _en_target_len - 1;
		if (_en_prop_len > 0)
		{
			extern MovieClip root_movieclip;
			MovieClip* _en_mc = NULL;
			if ((_en_target_len == 4 && strncmp(var_name, "this", 4) == 0) ||
			    (_en_target_len == 5 && strncmp(var_name, "_root", 5) == 0) ||
			    (_en_target_len == 7 && strncmp(var_name, "_level0", 7) == 0))
			{
				_en_mc = g_current_context ? g_current_context : &root_movieclip;
			}
			if (_en_mc != NULL && _en_mc->dynamic_props != NULL)
				var = getProperty((ASObject*)_en_mc->dynamic_props, _en_prop, _en_prop_len);
		}
	}

	// Handle dot-path syntax (e.g., "this.obj") — resolve via actionGetVariable
	// which already knows how to walk dot-separated paths
	if (var == NULL && var_name_len > 1 &&
	    memchr(var_name, '.', var_name_len) != NULL)
	{
		PUSH_STR(var_name, var_name_len);
		actionGetVariable(app_context);
		popVar(app_context, &_en_dot_var);
		if (_en_dot_var.type == ACTION_STACK_VALUE_OBJECT ||
		    _en_dot_var.type == ACTION_STACK_VALUE_ARRAY ||
		    _en_dot_var.type == ACTION_STACK_VALUE_MOVIECLIP ||
		    _en_dot_var.type == ACTION_STACK_VALUE_FUNCTION)
		{
			var = &_en_dot_var;
		}
	}

	if (var == NULL)
	{
		if (string_id > 0)
			var = getVariableById(string_id);
		else if (var_name_len > 0)
			var = getVariable(var_name, var_name_len);
	}

	// Step 2b: If global variable lookup returned uninitialized slot, also check
	// the current MC's dynamic properties (handles SetMember assignments on MC)
	if (var_name_len > 0 &&
	    (var == NULL || (var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0 &&
	                     var->data.string_data.heap_ptr == NULL)))
	{
		extern MovieClip root_movieclip;
		MovieClip* _en_ctx = g_current_context ? g_current_context : &root_movieclip;
		if (_en_ctx->dynamic_props != NULL)
		{
			ActionVar* _en_mc_prop = getProperty((ASObject*)_en_ctx->dynamic_props, var_name, var_name_len);
			if (_en_mc_prop != NULL)
				var = _en_mc_prop;
		}
	}

	// Step 3: Check if variable exists and is an enumerable type
	if (!var || (var->type != ACTION_STACK_VALUE_OBJECT &&
	             var->type != ACTION_STACK_VALUE_MOVIECLIP &&
	             var->type != ACTION_STACK_VALUE_ARRAY &&
	             var->type != ACTION_STACK_VALUE_FUNCTION))
	{
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

	// Step 4: Get the object from the variable
	ASObject* obj = NULL;
	MovieClip* mc = NULL;
	if (var->type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		mc = (MovieClip*) VAL(u64, &var->data.numeric_value);
		if (mc != NULL)
			obj = (ASObject*) mc->dynamic_props;
	}
	else if (var->type == ACTION_STACK_VALUE_OBJECT)
	{
		obj = (ASObject*) VAL(u64, &var->data.numeric_value);
	}
	else if (var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* func = (ASFunction*) VAL(u64, &var->data.numeric_value);
		if (func != NULL)
			obj = func->own_props;
	}
	else if (var->type == ACTION_STACK_VALUE_ARRAY)
	{
		// Array via actionEnumerate — delegate to Enumerate2 logic
		// Push the array back on stack and call actionEnumerate2
		ActionVar arr_var = *var;
		PUSH(arr_var.type, arr_var.data.numeric_value);
		// Remove the value we just pushed and call enumerate2 manually
		// Actually, just push undefined terminator and enumerate the array inline
		ASArray* arr = (ASArray*) VAL(u64, &var->data.numeric_value);
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		if (arr != NULL)
		{
			// Push set indices in ascending order
			int32_t signed_len = (int32_t) arr->length;
			u32 iter_limit = 0;
			if (signed_len > 0)
				iter_limit = (u32)signed_len < arr->capacity ? (u32)signed_len : arr->capacity;
			for (u32 i = 0; i < iter_limit; i++)
			{
				if (arr->elements[i].type == ACTION_STACK_VALUE_HOLE)
					continue;
				char idx_buf[16];
				snprintf(idx_buf, sizeof(idx_buf), "%u", i);
				u32 len = strlen(idx_buf);
				PUSH_STR(idx_buf, len);
			}
			// Push non-index properties
			if (arr->props != NULL && arr->props->num_used > 0)
			{
				for (u32 i = 0; i < arr->props->num_used; i++)
				{
					const char* pn = arr->props->properties[i].name;
					u32 pn_len = arr->props->properties[i].name_length;
					if (pn_len == 9 && strncmp(pn, "__proto__", 9) == 0)
						continue;
					if (!(arr->props->properties[i].flags & PROPERTY_FLAG_ENUMERABLE))
						continue;
					PUSH_STR(pn, pn_len);
				}
			}
		}
		return;
	}

	if (obj == NULL)
	{
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

	// Step 5: Push undefined terminator, then push properties directly in forward order.
	// Walking own object first, then prototype chain.
	// The LIFO stack naturally reverses: popping gives reverse-insertion-order,
	// with prototype properties iterated before own properties.
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);

	EnumeratedName* enumerated_head = NULL;

	// Walk the prototype chain
	ASObject* current_obj = obj;
	int chain_depth = 0;
	const int MAX_CHAIN_DEPTH = 100;

	while (current_obj != NULL && chain_depth < MAX_CHAIN_DEPTH)
	{
		chain_depth++;

		for (u32 i = 0; i < current_obj->num_used; i++)
		{
			const char* prop_name = current_obj->properties[i].name;
			u32 prop_name_len = current_obj->properties[i].name_length;
			u8 prop_flags = current_obj->properties[i].flags;

			if (!(prop_flags & PROPERTY_FLAG_ENUMERABLE))
				continue;
			if (isPropertyEnumerated(enumerated_head, prop_name, prop_name_len))
				continue;

			addEnumeratedName(&enumerated_head, prop_name, prop_name_len);
			PUSH_STR((char*)prop_name, prop_name_len);
		}

		// Move to prototype via __proto__
		ActionVar* proto_var = getProperty(current_obj, "__proto__", 9);
		if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
			current_obj = (ASObject*) proto_var->data.numeric_value;
		else
			current_obj = NULL;
	}

	freeEnumeratedNames(enumerated_head);

	// Enumerate child MovieClip instance names (pushed after own props = popped before)
#ifdef NO_GRAPHICS
	if (mc != NULL)
	{
		const char* parent_name = (mc == &root_movieclip) ? NULL : mc->name;
		ng_enumerateChildren(parent_name, enum_child_callback, app_context);
	}
#endif
}


int evaluateCondition(SWFAppContext* app_context)
{
	ActionStackValueType type = STACK_TOP_TYPE;
	u64 val = STACK_TOP_VALUE;
	u32 str_size = STACK_TOP_N;  // read before POP
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
		{
			return (str_size > 0);
		}
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_NULL:
			return 0;
		default:
			// Objects, arrays, functions are truthy
			return (val != 0);
	}
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
			a.str_size = ts_found ? 13 : 15;
			a.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
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
			b.str_size = ts_found ? 13 : 15;
			b.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
		}
	}

	// Convert non-string types to strings via the stack
	if (a.type != ACTION_STACK_VALUE_STRING)
	{
		pushVar(app_context, &a);
		convertString(app_context, a_str);
		popVar(app_context, &a);
	}
	if (b.type != ACTION_STACK_VALUE_STRING)
	{
		pushVar(app_context, &b);
		convertString(app_context, b_str);
		popVar(app_context, &b);
	}

	const uint16_t* sa = varGetU16Ptr(&a);
	u32 sa_len = a.str_size;
	const uint16_t* sb = varGetU16Ptr(&b);
	u32 sb_len = b.str_size;
	if (sa == NULL) { sa = u16_empty; sa_len = 0; }
	if (sb == NULL) { sb = u16_empty; sb_len = 0; }
	int cmp_result = u16_cmp(sa, sa_len, sb, sb_len);

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
	(void)str_buffer;
	// Pop count (number of code units to extract)
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);
	int count = varToInt32(&count_var);

	// Pop index (1-based position in Flash)
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int index = varToInt32(&index_var);

	// Pop string (UTF-16)
	char src_buffer[17];
	convertString(app_context, src_buffer);
	ActionVar src_var;
	popVar(app_context, &src_var);
	const uint16_t* src = varGetU16Ptr(&src_var);
	int src_len = (int)src_var.str_size;

	if (src == NULL || src_len == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Flash substring(): 1-based index, clamp to valid range
	if (index < 1) index = 1;
	index--; // convert to 0-based

	if (index >= src_len) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Negative count → rest of string; count 0 → empty
	if (count < 0) count = src_len - index;
	if (count == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}
	if (index + count > src_len) count = src_len - index;

	uint16_t* result = (uint16_t*)heap_alloc(app_context, count * sizeof(uint16_t));
	memcpy(result, src + index, count * sizeof(uint16_t));
	PUSH_U16(result, (u32)count);
}

void actionMbStringLength(SWFAppContext* app_context, char* v_str)
{
	// With UTF-16 storage, str_size is already the UTF-16 code unit count
	// which is what Flash's mbStringLength returns
	ActionVar v;
	convertString(app_context, v_str);
	popVar(app_context, &v);

	float str_size = (float) v.str_size;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &str_size));
}

void actionMbStringExtract(SWFAppContext* app_context, char* str_buffer)
{
	(void)str_buffer;
	// Pop count (number of code units to extract)
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);
	int count = varToInt32(&count_var);

	// Pop index (1-based position in Flash)
	convertFloat(app_context);
	ActionVar index_var;
	popVar(app_context, &index_var);
	int index = varToInt32(&index_var);

	// Pop string (UTF-16)
	char input_buffer[17];
	convertString(app_context, input_buffer);
	ActionVar src_var;
	popVar(app_context, &src_var);
	const uint16_t* src = varGetU16Ptr(&src_var);
	int src_len = (int)src_var.str_size;

	if (src == NULL || src_len == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Flash mbsubstring(): 1-based index, clamp to valid range
	if (index < 1) index = 1;
	index--; // convert to 0-based

	if (index >= src_len) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Negative count → rest of string; count 0 → empty
	if (count < 0) count = src_len - index;
	if (count == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}
	if (index + count > src_len) count = src_len - index;

	// Direct UTF-16 sub-array copy
	uint16_t* result = (uint16_t*)heap_alloc(app_context, count * sizeof(uint16_t));
	memcpy(result, src + index, count * sizeof(uint16_t));
	PUSH_U16(result, (u32)count);
}

void actionCharToAscii(SWFAppContext* app_context)
{
	// Convert top of stack to string
	char str_buffer[17];
	convertString(app_context, str_buffer);

	// Pop the string value
	ActionVar v;
	popVar(app_context, &v);

	// Get pointer to the UTF-16 string
	const uint16_t* str = varGetU16Ptr(&v);

	// Handle empty string edge case — Flash returns 0 (verified via Gnash tests)
	if (str == NULL || v.str_size == 0) {
		float result = 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Get UTF-16 code unit value of first character
	// Flash returns U+FFFD for surrogate code units (supplementary chars)
	uint16_t unit = str[0];
	float code = (unit >= 0xD800 && unit <= 0xDFFF) ? 65533.0f : (float)unit;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &code));
}

void actionStringAdd(SWFAppContext* app_context, char* a_str, char* b_str)
{
	// Convert both operands to string (now produces UTF-16 on stack)
	convertString(app_context, a_str);
	ActionVar a;
	popVar(app_context, &a);

	convertString(app_context, b_str);
	ActionVar b;
	popVar(app_context, &b);

	const uint16_t* a_u16 = varGetU16Ptr(&a);
	u32 a_len = a.str_size;
	const uint16_t* b_u16 = varGetU16Ptr(&b);
	u32 b_len = b.str_size;
	if (a_u16 == NULL) { a_u16 = u16_empty; a_len = 0; }
	if (b_u16 == NULL) { b_u16 = u16_empty; b_len = 0; }

	u32 result_len;
	uint16_t* result = u16_concat(app_context, b_u16, b_len, a_u16, a_len, &result_len);
	PUSH_U16(result, result_len);
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
#else
	if (ng_isInsideSprite()) { ng_playCurrentSprite(); return; }
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
#else
	if (ng_isInsideSprite()) { ng_stopCurrentSprite(); return; }
#endif
	is_playing = 0;
}

void actionTrace(SWFAppContext* app_context)
{
	if (g_execution_halted) { POP(); return; }

	// Stack underflow: treat as undefined (matches Flash Player behavior)
	if (SP >= INITIAL_STACK_SIZE)
	{
		printf("undefined\n");
		return;
	}

	ActionStackValueType type = STACK_TOP_TYPE;

	switch (type)
	{
		case ACTION_STACK_VALUE_STRING:
		{
			// Convert UTF-16 to UTF-8 for output
			const uint16_t* u16 = (const uint16_t*) STACK_TOP_VALUE;
			u32 u16_len = STACK_TOP_N;
			if (u16 != NULL && u16_len > 0)
			{
				char utf8_buf[4096];
				int utf8_len = u16_to_utf8(u16, u16_len, utf8_buf, sizeof(utf8_buf));
				fwrite(utf8_buf, 1, utf8_len, stdout);
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
			if (EFFECTIVE_SWF_VERSION() < 5)
				printf("%d\n", STACK_TOP_VALUE ? 1 : 0);
			else
				printf("%s\n", STACK_TOP_VALUE ? "true" : "false");
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
			// MovieClip traces as its full dot-path ("_level0", "_level0.a", "_level0.a.b")
			// mc->target holds slash-notation: "/", "/a", "/a/b" — convert to dot notation.
			MovieClip* mc = (MovieClip*) STACK_TOP_VALUE;
			extern MovieClip root_movieclip;
			if (mc == NULL || mc == &root_movieclip || mc->target[0] == '\0' ||
			    (mc->target[0] == '/' && mc->target[1] == '\0'))
			{
				printf("_level0\n");
			}
			else
			{
				// Convert "/a/b/c" → "_level0.a.b.c":
				// 1. Emit "_level0."
				// 2. Walk target+1, replacing '/' with '.'
				char dot_path[512];
				int pos = snprintf(dot_path, sizeof(dot_path), "_level0.");
				const char* p = mc->target + 1;  // skip leading '/'
				while (*p && pos < (int)sizeof(dot_path) - 1)
				{
					dot_path[pos++] = (*p == '/') ? '.' : *p;
					p++;
				}
				dot_path[pos] = '\0';
				printf("%s\n", dot_path);
			}
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
			// If __proto__ is an ARRAY, use array-like join (own-props only, no getters invoked)
			ASObject* _tr_obj = (ASObject*) obj_var.data.numeric_value;
			ActionVar* _tr_proto = (_tr_obj != NULL) ? getProperty(_tr_obj, "__proto__", 9) : NULL;
			if (_tr_proto != NULL && _tr_proto->type == ACTION_STACK_VALUE_ARRAY)
			{
				ActionVar* _tr_len_prop = getProperty(_tr_obj, "length", 6);
				u32 _tr_len = (_tr_len_prop != NULL) ? (u32)varToDouble(_tr_len_prop) : 0;
				for (u32 _tr_i = 0; _tr_i < _tr_len; _tr_i++)
				{
					if (_tr_i > 0) printf(",");
					char _tr_idx[32];
					snprintf(_tr_idx, sizeof(_tr_idx), "%u", _tr_i);
					ActionVar* _tr_elem = getProperty(_tr_obj, _tr_idx, (u32)strlen(_tr_idx));
					if (_tr_elem == NULL || _tr_elem->type == ACTION_STACK_VALUE_UNDEFINED ||
					    _tr_elem->type == ACTION_STACK_VALUE_HOLE)
						printf("undefined");
					else if (_tr_elem->type == ACTION_STACK_VALUE_NULL)
						printf("null");
					else if (_tr_elem->type == ACTION_STACK_VALUE_F64)
					{
						double _tr_d = varToDouble(_tr_elem);
						if (isnan(_tr_d)) printf("NaN");
						else if (isinf(_tr_d)) printf("%sInfinity", _tr_d < 0 ? "-" : "");
						else if (_tr_d == 0.0) printf("0");
						else printf("%.15g", _tr_d);
					}
					else if (_tr_elem->type == ACTION_STACK_VALUE_F32)
					{
						double _tr_d = varToDouble(_tr_elem);
						if (isnan(_tr_d)) printf("NaN");
						else if (isinf(_tr_d)) printf("%sInfinity", _tr_d < 0 ? "-" : "");
						else if (_tr_d == 0.0) printf("0");
						else printf("%.15g", _tr_d);
					}
					else if (_tr_elem->type == ACTION_STACK_VALUE_STRING)
					{
						const uint16_t* _tr_u16 = varGetU16Ptr(_tr_elem);
						if (_tr_u16 && _tr_elem->str_size > 0)
						{
							char _tr_utf8[4096];
							int _tr_utf8_len = u16_to_utf8(_tr_u16, _tr_elem->str_size, _tr_utf8, sizeof(_tr_utf8));
							fwrite(_tr_utf8, 1, _tr_utf8_len, stdout);
						}
					}
					else
						printf("undefined");
				}
				printf("\n");
				break;
			}
			int ts_found = 0;
			ActionVar ts = objectCallToString(app_context, &obj_var, &ts_found);
			if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
			{
				const uint16_t* u16 = varGetU16Ptr(&ts);
				if (u16 && ts.str_size > 0)
				{
					char utf8_buf[4096];
					int utf8_len = u16_to_utf8(u16, ts.str_size, utf8_buf, sizeof(utf8_buf));
					fwrite(utf8_buf, 1, utf8_len, stdout);
				}
				printf("\n");
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
				VAL(u64, &comma_arg.data.numeric_value) = (u64) u16_comma;
				callArrayMethod(app_context, arr, "join", 4, &comma_arg, 1);
				// The result is on the stack — print it
				if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
				{
					const uint16_t* u16 = (const uint16_t*) STACK_TOP_VALUE;
					u32 u16_len = STACK_TOP_N;
					if (u16 != NULL && u16_len > 0)
					{
						char utf8_buf[4096];
						int utf8_len = u16_to_utf8(u16, u16_len, utf8_buf, sizeof(utf8_buf));
						fwrite(utf8_buf, 1, utf8_len, stdout);
					}
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

// Old UTF-8 helper functions (utf8_utf16_length, utf8_decode_one, utf8_build_utf16_tables,
// byte_offset_to_utf16_index, utf16_unit_to_utf8) have been moved to the UTF-16 infrastructure
// section at the top of this file. String methods that still use UTF-8 tables will be updated
// to work directly with UTF-16 in a subsequent pass.

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
#else
	extern int g_settarget_explicit_root;
	if (ng_isInsideSprite()) {
		if (g_settarget_explicit_root) {
			// SetTarget("_root") was called — target is root.
			// Defer root frame navigation; don't execute inline while inside sprite script.
			extern size_t next_frame;
			extern int manual_next_frame;
			extern int is_playing;
			extern size_t g_frame_count;
			extern int goto_from_action;
			if (frame < g_frame_count) {
				goto_from_action = 1;
				next_frame = frame;
				manual_next_frame = 1;
				is_playing = 0;
				root_movieclip.currentframe = frame + 1;
			}
			return;
		}
		ng_gotoFrameCurrentSprite(frame);
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

#ifdef NO_GRAPHICS
	extern int goto_from_action;
	goto_from_action = 1;
#endif

	next_frame = frame;
	manual_next_frame = 1;
	is_playing = 0;

	// Update _currentframe immediately so scripts can read the new value
	root_movieclip.currentframe = frame + 1;  // 1-indexed

#ifdef NO_GRAPHICS
	// Execute goto catch-up inline so target frame tags are processed
	// before the calling script continues (Flash's goto is synchronous)
	extern void ng_executeGotoCatchUp(SWFAppContext* app_context);
	ng_executeGotoCatchUp(app_context);
#endif
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

#ifdef NO_GRAPHICS
		extern int goto_from_action;
		goto_from_action = 1;
		extern void ng_executeGotoCatchUp(SWFAppContext* app_context);
		ng_executeGotoCatchUp(app_context);
#endif
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
		char _gf2_buf[256];
		const uint16_t* _gf2_u16 = varGetU16Ptr(&frame_var);
		if (_gf2_u16 && frame_var.str_size > 0)
			u16_to_utf8(_gf2_u16, frame_var.str_size, _gf2_buf, sizeof(_gf2_buf));
		else
			_gf2_buf[0] = '\0';
		const char* frame_str = _gf2_buf;
		if (frame_str[0] == '\0') return;

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
#ifdef NO_GRAPHICS
		if (ng_isInsideSprite()) { ng_playCurrentSprite(); }
		else
#endif
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
	if (is_dragging) {
		is_dragging = 0;

#ifdef NO_GRAPHICS
		// Compute _droptarget: find the clip under the dragged hotspot (g_drag_virt_x/y),
		// skipping the dragged clip itself.  Use g_drag_target_name because dragged_target
		// may be wrong (GetVariable("this") returns root, not the clip's own name).
		char path[256];
		ng_compute_droptarget(g_drag_virt_x, g_drag_virt_y,
		    g_drag_target_name[0] ? g_drag_target_name : dragged_target,
		    path, sizeof(path));

		// Set droptarget on the current context MC (the dragged clip's MC,
		// set by dispatch_clip_event_release before calling this action).
		if (g_current_context)
			snprintf(g_current_context->droptarget, sizeof(g_current_context->droptarget),
			    "%s", path);
#endif

		if (dragged_target) {
			free(dragged_target);
			dragged_target = NULL;
		}
	}

	(void)app_context;
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

// ============================================================================
// Global stub constructors/objects for built-in ActionScript classes
// ============================================================================

// ============================================================================
// AsBroadcaster: addListener / removeListener / broadcastMessage
// These are installed on Mouse, Key, Stage, and Selection static objects.
// They use g_c_function_this_obj (set by actionCallMethod before the call)
// to identify which broadcaster object they operate on.
// ============================================================================

static ActionVar builtin_broadcaster_addListener(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)registers;
    ASObject* receiver = (ASObject*) this_obj;
    if (!receiver) receiver = g_c_function_this_obj;
    if (!receiver || arg_count < 1) {
        ActionVar r = {0}; r.type = ACTION_STACK_VALUE_BOOLEAN; VAL(u64, &r.data.numeric_value) = 1;
        return r;
    }

    // Get or create _listeners array on receiver
    ActionVar* listeners_prop = getPropertyWithPrototype(receiver, "_listeners", 10);
    ASArray* arr = NULL;
    if (listeners_prop && listeners_prop->type == ACTION_STACK_VALUE_ARRAY) {
        arr = (ASArray*) listeners_prop->data.numeric_value;
    }
    if (!arr) {
        arr = allocArray(app_context, 4);
        ActionVar av = {0};
        av.type = ACTION_STACK_VALUE_ARRAY;
        av.data.numeric_value = (u64)arr;
        setProperty(app_context, receiver, "_listeners", 10, &av);
    }

    // For non-null/undefined listeners, check for duplicates first
    ActionVar* new_listener = &args[0];
    if (new_listener->type != ACTION_STACK_VALUE_NULL &&
        new_listener->type != ACTION_STACK_VALUE_UNDEFINED) {
        for (u32 i = 0; i < arr->length; i++) {
            ActionVar* elem = getArrayElement(arr, i);
            if (elem && elem->type == new_listener->type &&
                elem->data.numeric_value == new_listener->data.numeric_value) {
                // Duplicate found - return true without re-adding
                ActionVar result = {0};
                result.type = ACTION_STACK_VALUE_BOOLEAN;
                VAL(u64, &result.data.numeric_value) = 1;
                return result;
            }
        }
    }

    // Add listener (null/undefined are added without duplicate check)
    u32 len = arr->length;
    setArrayElement(app_context, arr, len, new_listener);

    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_BOOLEAN;
    VAL(u64, &result.data.numeric_value) = 1;
    return result;
}


static ActionVar builtin_broadcaster_removeListener(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)registers;
    ASObject* receiver = (ASObject*) this_obj;
    if (!receiver) receiver = g_c_function_this_obj;
    if (!receiver || arg_count < 1) {
        ActionVar r = {0}; r.type = ACTION_STACK_VALUE_BOOLEAN; VAL(u64, &r.data.numeric_value) = 0;
        return r;
    }

    ActionVar* listeners_prop = getPropertyWithPrototype(receiver, "_listeners", 10);
    if (!listeners_prop || listeners_prop->type != ACTION_STACK_VALUE_ARRAY) {
        ActionVar r = {0}; r.type = ACTION_STACK_VALUE_BOOLEAN; VAL(u64, &r.data.numeric_value) = 0;
        return r;
    }
    ASArray* arr = (ASArray*) listeners_prop->data.numeric_value;
    if (!arr) {
        ActionVar r = {0}; r.type = ACTION_STACK_VALUE_BOOLEAN; VAL(u64, &r.data.numeric_value) = 0;
        return r;
    }

    // Find and remove listener (shift remaining elements)
    u64 target_addr = args[0].data.numeric_value;
    int found = 0;
    for (u32 i = 0; i < arr->length; i++) {
        ActionVar* elem = getArrayElement(arr, i);
        if (elem && elem->type == args[0].type && elem->data.numeric_value == target_addr) {
            // Shift elements down
            for (u32 j = i; j + 1 < arr->length; j++) {
                ActionVar* next = getArrayElement(arr, j + 1);
                if (next) setArrayElement(app_context, arr, j, next);
            }
            arr->length--;
            found = 1;
            break;
        }
    }

    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_BOOLEAN;
    VAL(u64, &result.data.numeric_value) = found ? 1 : 0;
    return result;
}

static ActionVar builtin_broadcaster_broadcastMessage(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)registers;
    ActionVar undef = {0};
    undef.type = ACTION_STACK_VALUE_UNDEFINED;

    ASObject* receiver = (ASObject*) this_obj;
    if (!receiver) receiver = g_c_function_this_obj;
    if (!receiver || arg_count < 1) return undef;

    // Convert method name (args[0]) from UTF-16 to UTF-8
    char method_name[256];
    method_name[0] = '\0';
    if (args[0].type == ACTION_STACK_VALUE_STRING) {
        const uint16_t* u16 = (const uint16_t*)(uintptr_t)args[0].data.numeric_value;
        u16_to_utf8(u16, args[0].str_size, method_name, sizeof(method_name));
    } else {
        return undef;  // method name must be a string
    }
    int method_name_len = (int)strlen(method_name);
    if (method_name_len == 0) return undef;

    // Get the _listeners array
    ActionVar* listeners_prop = getPropertyWithPrototype(receiver, "_listeners", 10);
    if (!listeners_prop || listeners_prop->type != ACTION_STACK_VALUE_ARRAY) return undef;
    ASArray* arr = (ASArray*)(uintptr_t)listeners_prop->data.numeric_value;
    if (!arr || arr->length == 0) return undef;

    // Extra args to pass to the method (args[1..])
    u32 extra_count = arg_count > 1 ? arg_count - 1 : 0;
    ActionVar* extra_args = extra_count > 0 ? &args[1] : NULL;

    // Call method on each listener
    for (u32 i = 0; i < arr->length; i++) {
        ActionVar* elem = getArrayElement(arr, i);
        if (!elem) continue;

        ASObject* listener_obj = NULL;
        if (elem->type == ACTION_STACK_VALUE_OBJECT) {
            listener_obj = (ASObject*)(uintptr_t)elem->data.numeric_value;
        } else if (elem->type == ACTION_STACK_VALUE_MOVIECLIP) {
            MovieClip* mc = (MovieClip*)(uintptr_t)elem->data.numeric_value;
            if (mc && mc->dynamic_props)
                listener_obj = (ASObject*) mc->dynamic_props;
        } else if (elem->type == ACTION_STACK_VALUE_FUNCTION) {
            // Function used as listener — look up method on its own_props
            ASFunction* f = lookupFunctionFromVar(elem);
            if (f && f->own_props)
                listener_obj = f->own_props;
        }
        if (!listener_obj) continue;

        ActionVar* method_prop = getPropertyWithPrototype(listener_obj, method_name, method_name_len);
        if (!method_prop || method_prop->type != ACTION_STACK_VALUE_FUNCTION) continue;
        ASFunction* func = lookupFunctionFromVar(method_prop);
        if (!func) continue;

        if (func->function_type == 2 && func->advanced_func != NULL) {
            ActionVar* regs = NULL;
            if (func->register_count > 0)
                regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
            func->advanced_func(app_context, extra_args, extra_count, regs, listener_obj);
            if (regs) FREE(regs);
        } else if (func->function_type == 1 && func->simple_func != NULL) {
            for (u32 j = 0; j < extra_count; j++)
                pushVar(app_context, &extra_args[j]);
            ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
        }
    }

    return undef;
}

// Static function objects for AsBroadcaster methods
static ASFunction g_ab_addListener_func;
static ASFunction g_ab_removeListener_func;
static ASFunction g_ab_broadcastMessage_func;
static int g_ab_funcs_init = 0;

static void initAsBroadcasterFuncs(SWFAppContext* app_context)
{
    if (g_ab_funcs_init) return;
    memset(&g_ab_addListener_func, 0, sizeof(ASFunction));
    strncpy(g_ab_addListener_func.name, "addListener", 255);
    g_ab_addListener_func.function_type = 2;
    g_ab_addListener_func.advanced_func = (Function2Ptr)builtin_broadcaster_addListener;

    memset(&g_ab_removeListener_func, 0, sizeof(ASFunction));
    strncpy(g_ab_removeListener_func.name, "removeListener", 255);
    g_ab_removeListener_func.function_type = 2;
    g_ab_removeListener_func.advanced_func = (Function2Ptr)builtin_broadcaster_removeListener;

    memset(&g_ab_broadcastMessage_func, 0, sizeof(ASFunction));
    strncpy(g_ab_broadcastMessage_func.name, "broadcastMessage", 255);
    g_ab_broadcastMessage_func.function_type = 2;
    g_ab_broadcastMessage_func.advanced_func = (Function2Ptr)builtin_broadcaster_broadcastMessage;

    g_ab_funcs_init = 1;
    (void)app_context;
}

// Forward declaration (defined later in ensureGlobalInit block)
static ASObject* g_key_obj;

// ============================================================================
// Key object methods: isDown, getCode, getAscii, isToggled
// ============================================================================

static ActionVar builtin_key_isDown(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)registers; (void)this_obj;
    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_BOOLEAN;
    if (arg_count < 1) { VAL(u64, &result.data.numeric_value) = 0; return result; }
    int code = (int)varToDoubleSimple(&args[0]);
    int down = (code >= 0 && code < 256) ? app_context->keys.down[code] : 0;
    VAL(u64, &result.data.numeric_value) = down ? 1 : 0;
    return result;
}

static ActionVar builtin_key_getCode(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)args; (void)arg_count; (void)registers; (void)this_obj;
    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_F64;
    VAL(double, &result.data.numeric_value) = (double)app_context->keys.last_key_down;
    return result;
}

static ActionVar builtin_key_getAscii(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)args; (void)arg_count; (void)registers; (void)this_obj;
    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_F64;
    VAL(double, &result.data.numeric_value) = (double)app_context->keys.last_key_ascii;
    return result;
}

static ActionVar builtin_key_isToggled(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    (void)registers; (void)this_obj;
    ActionVar result = {0};
    result.type = ACTION_STACK_VALUE_BOOLEAN;
    if (arg_count < 1) { VAL(u64, &result.data.numeric_value) = 0; return result; }
    int code = (int)varToDoubleSimple(&args[0]);
    int toggled = (code >= 0 && code < 256) ? app_context->keys.toggled[code] : 0;
    VAL(u64, &result.data.numeric_value) = toggled ? 1 : 0;
    return result;
}

static ASFunction g_key_isDown_func;
static ASFunction g_key_getCode_func;
static ASFunction g_key_getAscii_func;
static ASFunction g_key_isToggled_func;
static int g_key_methods_init = 0;

static void installKeyMethods(SWFAppContext* app_context, ASObject* key_obj)
{
    if (!g_key_methods_init) {
        memset(&g_key_isDown_func, 0, sizeof(ASFunction));
        strncpy(g_key_isDown_func.name, "isDown", 255);
        g_key_isDown_func.function_type = 2;
        g_key_isDown_func.advanced_func = (Function2Ptr)builtin_key_isDown;

        memset(&g_key_getCode_func, 0, sizeof(ASFunction));
        strncpy(g_key_getCode_func.name, "getCode", 255);
        g_key_getCode_func.function_type = 2;
        g_key_getCode_func.advanced_func = (Function2Ptr)builtin_key_getCode;

        memset(&g_key_getAscii_func, 0, sizeof(ASFunction));
        strncpy(g_key_getAscii_func.name, "getAscii", 255);
        g_key_getAscii_func.function_type = 2;
        g_key_getAscii_func.advanced_func = (Function2Ptr)builtin_key_getAscii;

        memset(&g_key_isToggled_func, 0, sizeof(ASFunction));
        strncpy(g_key_isToggled_func.name, "isToggled", 255);
        g_key_isToggled_func.function_type = 2;
        g_key_isToggled_func.advanced_func = (Function2Ptr)builtin_key_isToggled;

        g_key_methods_init = 1;
    }
    ActionVar fv = {0};
    fv.type = ACTION_STACK_VALUE_FUNCTION;

    fv.data.numeric_value = (u64)&g_key_isDown_func;
    setProperty(app_context, key_obj, "isDown", 6, &fv);

    fv.data.numeric_value = (u64)&g_key_getCode_func;
    setProperty(app_context, key_obj, "getCode", 7, &fv);

    fv.data.numeric_value = (u64)&g_key_getAscii_func;
    setProperty(app_context, key_obj, "getAscii", 8, &fv);

    fv.data.numeric_value = (u64)&g_key_isToggled_func;
    setProperty(app_context, key_obj, "isToggled", 9, &fv);
}

// Dispatch AS2 mc.onEnterFrame property handlers for all cached MovieClips.
// Called from tagShowFrame after sprite/button initialization. Iterates the
// MC cache in reverse creation order (most recently created = highest depth = front)
// to match Flash's front-to-back dispatch order.
void actionDispatchEnterFrameHandlers(SWFAppContext* app_context)
{
	// Dispatch to root MovieClip first (it's not in child_mc_cache)
	{
		extern MovieClip root_movieclip;
		ASObject* root_props = (ASObject*) root_movieclip.dynamic_props;
		if (root_props != NULL) {
			ActionVar* ef_prop = getProperty(root_props, "onEnterFrame", 12);
			if (ef_prop != NULL && ef_prop->type == ACTION_STACK_VALUE_FUNCTION) {
				ASFunction* func = (ASFunction*) ef_prop->data.numeric_value;
				if (func != NULL) {
					MovieClip* saved_ctx = g_current_context;
					// Dispatch with root as this
					ActionVar this_av = {0};
					this_av.type = ACTION_STACK_VALUE_MOVIECLIP;
					this_av.data.numeric_value = (u64)&root_movieclip;
					if (func->function_type == 2 && func->advanced_func != NULL) {
						ActionVar* regs = NULL;
						if (func->register_count > 0)
							regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
						func->advanced_func(app_context, NULL, 0, regs, (void*)&this_av);
						if (regs != NULL) FREE(regs);
					} else if (func->function_type == 1 && func->simple_func != NULL) {
						((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
					}
					actionSetCurrentContext(saved_ctx);
				}
			}
		}
	}

	for (int i = child_mc_count - 1; i >= 0; i--)
	{
		MovieClip* mc = child_mc_cache[i];
		if (mc == NULL || mc->dynamic_props == NULL) continue;
		if (mc->is_button_mc) continue;  // buttons don't fire onEnterFrame

		ASObject* props = (ASObject*) mc->dynamic_props;
		ActionVar* ef_prop = getProperty(props, "onEnterFrame", 12);
		if (ef_prop == NULL || ef_prop->type != ACTION_STACK_VALUE_FUNCTION) continue;

		ASFunction* func = (ASFunction*) ef_prop->data.numeric_value;
		if (func == NULL) continue;

		MovieClip* saved_ctx = g_current_context;
		actionSetCurrentContext(mc);

		// Pass ActionVar* with MOVIECLIP type as this_obj so generated
		// functions preload register 1 (this) as a MovieClip correctly.
		ActionVar this_av = {0};
		this_av.type = ACTION_STACK_VALUE_MOVIECLIP;
		this_av.data.numeric_value = (u64)mc;

		if (func->function_type == 2 && func->advanced_func != NULL)
		{
			ActionVar* regs = NULL;
			if (func->register_count > 0)
				regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
			func->advanced_func(app_context, NULL, 0, regs, (void*)&this_av);
			if (regs != NULL) FREE(regs);
		}
		else if (func->function_type == 1 && func->simple_func != NULL)
		{
			((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
		}

		actionSetCurrentContext(saved_ctx);
	}
}

// Dispatch root-timeline onEnterFrame stored in the global var_map
// (set via DefineFunction or SetVariable, NOT via SetMember on dynamic_props).
// Called from swf_core.c's past-frame-list else_if branch.
void actionDispatchRootVarMapEnterFrame(SWFAppContext* app_context)
{
	extern MovieClip root_movieclip;
	ActionVar* ef_var = getVariable("onEnterFrame", 12);
	if (ef_var == NULL || ef_var->type != ACTION_STACK_VALUE_FUNCTION)
		return;

	// Avoid double-firing when dynamic_props also has an onEnterFrame handler
	// (that case is already handled by actionDispatchEnterFrameHandlers).
	if (root_movieclip.dynamic_props != NULL)
	{
		ASObject* rp = (ASObject*) root_movieclip.dynamic_props;
		ActionVar* dp_ef = getProperty(rp, "onEnterFrame", 12);
		if (dp_ef != NULL && dp_ef->type == ACTION_STACK_VALUE_FUNCTION)
			return;
	}

	ASFunction* func = (ASFunction*) ef_var->data.numeric_value;
	if (func == NULL) return;

	MovieClip* saved_ctx = g_current_context;
	if (func->function_type == 2 && func->advanced_func != NULL)
	{
		ActionVar this_av = {0};
		this_av.type = ACTION_STACK_VALUE_MOVIECLIP;
		this_av.data.numeric_value = (u64)&root_movieclip;
		ActionVar* regs = NULL;
		if (func->register_count > 0)
			regs = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
		func->advanced_func(app_context, NULL, 0, regs, (void*)&this_av);
		if (regs != NULL) FREE(regs);
	}
	else if (func->function_type == 1 && func->simple_func != NULL)
	{
		((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
	}
	actionSetCurrentContext(saved_ctx);
}

// Dispatch onKeyDown/onKeyUp to all Key listeners.
// Called from swf_core.c after delivering a key event.
void actionDispatchKeyDown(SWFAppContext* app_context)
{
    if (!g_key_obj) return;
    // Call Key.broadcastMessage("onKeyDown")
    // Build args: [string "onKeyDown"]
    static const uint16_t onKeyDown_u16[] = {
        'o','n','K','e','y','D','o','w','n'
    };
    ActionVar method_name = {0};
    method_name.type = ACTION_STACK_VALUE_STRING;
    method_name.data.numeric_value = (u64)(uintptr_t)onKeyDown_u16;
    method_name.str_size = 9;
    builtin_broadcaster_broadcastMessage(app_context, &method_name, 1, NULL, (void*)g_key_obj);
}

void actionDispatchKeyUp(SWFAppContext* app_context)
{
    if (!g_key_obj) return;
    static const uint16_t onKeyUp_u16[] = {
        'o','n','K','e','y','U','p'
    };
    ActionVar method_name = {0};
    method_name.type = ACTION_STACK_VALUE_STRING;
    method_name.data.numeric_value = (u64)(uintptr_t)onKeyUp_u16;
    method_name.str_size = 7;
    builtin_broadcaster_broadcastMessage(app_context, &method_name, 1, NULL, (void*)g_key_obj);
}

static void installAsBroadcaster(SWFAppContext* app_context, ASObject* obj)
{
    initAsBroadcasterFuncs(app_context);

    // Install _listeners array
    ASArray* listeners = allocArray(app_context, 4);
    ActionVar lv = {0};
    lv.type = ACTION_STACK_VALUE_ARRAY;
    lv.data.numeric_value = (u64)listeners;
    setProperty(app_context, obj, "_listeners", 10, &lv);

    // Install methods
    ActionVar fv = {0};
    fv.type = ACTION_STACK_VALUE_FUNCTION;

    fv.data.numeric_value = (u64)&g_ab_addListener_func;
    setProperty(app_context, obj, "addListener", 11, &fv);

    fv.data.numeric_value = (u64)&g_ab_removeListener_func;
    setProperty(app_context, obj, "removeListener", 14, &fv);

    fv.data.numeric_value = (u64)&g_ab_broadcastMessage_func;
    setProperty(app_context, obj, "broadcastMessage", 16, &fv);
}

// Stub constructors: classes that need to exist as globals with a prototype
// Index mapping: 0=AsBroadcaster, 1=Button, 2=Camera, 3=Color,
// 4=ContextMenu, 5=ContextMenuItem, 6=LoadVars, 7=LocalConnection,
// 8=Microphone, 9=MovieClipLoader, 10=NetConnection, 11=NetStream,
// 12=PrintJob, 13=SharedObject, 14=Sound, 15=TextSnapshot, 16=Video, 17=XMLSocket
#define NUM_STUB_CTORS 18
static ASFunction g_stub_ctors[NUM_STUB_CTORS];

// Stub static objects (not constructors — typeof returns "object", no prototype)
static ASObject* g_accessibility_obj = NULL;
static ASObject* g_key_obj = NULL;
static ASObject* g_mouse_obj = NULL;
static ASObject* g_selection_obj = NULL;
static ASObject* g_stage_obj = NULL;

// Currently focused MovieClip (NULL = no focus)
static MovieClip* g_focused_mc = NULL;

// Clipboard buffer for SetClipboardText / TextControl operations
static char g_clipboard_text[1024] = {0};
static size_t g_clipboard_len = 0;
static int g_tf_select_all = 0;  // 1 = entire text field is selected

// Static function objects for Selection.setFocus / Selection.getFocus
static ASFunction g_selection_setFocus_func;
static ASFunction g_selection_getFocus_func;
#ifdef NO_GRAPHICS
// Forward declarations — implementations are in the NO_GRAPHICS block at end of file
static ActionVar builtin_selection_setFocus(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);
static ActionVar builtin_selection_getFocus(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);
#endif

static int g_global_init_done = 0;

// ---- Prototype initializers for stub classes ----

// PrintJob.prototype:
//   Numeric properties (ENUMERABLE, READ_ONLY, DONT_DELETE): orientation, pageWidth, pageHeight, paperWidth, paperHeight
//   Method stubs (DONT_ENUM, WRITABLE, DONT_DELETE) only on SWF7+: start, addPage, send
//
// Note: actionEnumerate2 uses LIFO stack, so properties are yielded in REVERSE insertion order.
// We insert numeric props in reverse of the desired for-in order to get correct enumeration.
static void initPrintJobPrototype(SWFAppContext* app_context, ASFunction* ctor)
{
	if (ctor->prototype_obj != NULL) return;
	ctor->prototype_obj = allocObject(app_context, 8);
	retainObject(ctor->prototype_obj);
	setObjectProto(app_context, ctor->prototype_obj);
	// constructor back-reference (DONT_ENUM — not enumerable in Flash)
	ActionVar ctor_var = {0};
	ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
	ctor_var.data.numeric_value = (u64) ctor;
	setPropertyWithFlags(app_context, ctor->prototype_obj, "constructor", 11, &ctor_var, PROPERTY_FLAGS_DONTENUM);

	// In SWF < 7, PrintJob instances trace as "[type Object]" (not "[object Object]").
	// Install a toString override on the prototype to produce this behavior.
	if (g_swf_version < 7) {
		memset(&g_type_object_toString_func, 0, sizeof(ASFunction));
		strncpy(g_type_object_toString_func.name, "toString", 255);
		g_type_object_toString_func.function_type = 1;
		g_type_object_toString_func.simple_func = (SimpleFunctionPtr) builtin_type_object_toString;
		if (function_count < MAX_FUNCTIONS)
			function_registry[function_count++] = &g_type_object_toString_func;
		ActionVar ts_var = {0};
		ts_var.type = ACTION_STACK_VALUE_FUNCTION;
		ts_var.data.numeric_value = (u64) &g_type_object_toString_func;
		setPropertyWithFlags(app_context, ctor->prototype_obj, "toString", 8, &ts_var, PROPERTY_FLAGS_DONTENUM);
	}

	// Numeric properties: ENUMERABLE only (READ_ONLY + DONT_DELETE = no WRITABLE, no CONFIGURABLE)
	// Inserted in REVERSE of desired for-in order (LIFO enumeration reverses insertion order):
	// Desired: orientation, pageWidth, pageHeight, paperWidth, paperHeight
	// Insert:  paperHeight, paperWidth, pageHeight, pageWidth, orientation
	ActionVar num_val = {0};
	num_val.type = ACTION_STACK_VALUE_F64;
	num_val.data.numeric_value = 0; // 0.0 as double
	setPropertyWithFlags(app_context, ctor->prototype_obj, "paperHeight", 11, &num_val, PROPERTY_FLAG_ENUMERABLE);
	setPropertyWithFlags(app_context, ctor->prototype_obj, "paperWidth", 10, &num_val, PROPERTY_FLAG_ENUMERABLE);
	setPropertyWithFlags(app_context, ctor->prototype_obj, "pageHeight", 10, &num_val, PROPERTY_FLAG_ENUMERABLE);
	setPropertyWithFlags(app_context, ctor->prototype_obj, "pageWidth", 9, &num_val, PROPERTY_FLAG_ENUMERABLE);
	setPropertyWithFlags(app_context, ctor->prototype_obj, "orientation", 11, &num_val, PROPERTY_FLAG_ENUMERABLE);

	// Method stubs: SWF7+ only (DONT_ENUM + DONT_DELETE = WRITABLE only)
	if (g_swf_version >= 7) {
		addStubMethodToProto(app_context, ctor->prototype_obj, "start", 5, PROPERTY_FLAG_WRITABLE);
		addStubMethodToProto(app_context, ctor->prototype_obj, "addPage", 7, PROPERTY_FLAG_WRITABLE);
		addStubMethodToProto(app_context, ctor->prototype_obj, "send", 4, PROPERTY_FLAG_WRITABLE);
	}
}

// Sound.prototype:
//   toString (always "[object Object]", DONT_ENUM + DONT_DELETE)
//   9 methods in SWF5+: getPan, getTransform, getVolume, setPan, setTransform, setVolume, stop, attachSound, start
//   7 additional in SWF6+: getDuration, setDuration, getPosition, setPosition, loadSound, getBytesLoaded, getBytesTotal
//   All methods: DONT_ENUM + DONT_DELETE (PROPERTY_FLAG_WRITABLE only)
static void initSoundPrototype(SWFAppContext* app_context, ASFunction* ctor)
{
	if (ctor->prototype_obj != NULL) return;
	ctor->prototype_obj = allocObject(app_context, 24);
	retainObject(ctor->prototype_obj);
	setObjectProto(app_context, ctor->prototype_obj);
	// constructor back-reference (DONT_ENUM)
	ActionVar ctor_var = {0};
	ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
	ctor_var.data.numeric_value = (u64) ctor;
	setPropertyWithFlags(app_context, ctor->prototype_obj, "constructor", 11, &ctor_var, PROPERTY_FLAGS_DONTENUM);

	// toString: always "[object Object]" (native object behavior)
	installNativeToString(app_context, ctor->prototype_obj);

	// Core methods (SWF5+)
	const u8 mflags = PROPERTY_FLAG_WRITABLE; // DONT_ENUM + DONT_DELETE
	addStubMethodToProto(app_context, ctor->prototype_obj, "getPan", 6, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "getTransform", 12, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "getVolume", 9, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "setPan", 6, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "setTransform", 12, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "setVolume", 9, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "stop", 4, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "attachSound", 11, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "start", 5, mflags);

	// Extended methods (SWF6+)
	if (g_swf_version >= 6) {
		addStubMethodToProto(app_context, ctor->prototype_obj, "getDuration", 11, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "setDuration", 11, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "getPosition", 11, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "setPosition", 11, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "loadSound", 9, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "getBytesLoaded", 14, mflags);
		addStubMethodToProto(app_context, ctor->prototype_obj, "getBytesTotal", 13, mflags);
	}
}

// LocalConnection.prototype:
//   domain, connect, close, send — DONT_ENUM + DONT_DELETE (PROPERTY_FLAG_WRITABLE only)
static void initLocalConnectionPrototype(SWFAppContext* app_context, ASFunction* ctor)
{
	if (ctor->prototype_obj != NULL) return;
	ctor->prototype_obj = allocObject(app_context, 8);
	retainObject(ctor->prototype_obj);
	setObjectProto(app_context, ctor->prototype_obj);
	// constructor back-reference (DONT_ENUM)
	ActionVar ctor_var = {0};
	ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
	ctor_var.data.numeric_value = (u64) ctor;
	setPropertyWithFlags(app_context, ctor->prototype_obj, "constructor", 11, &ctor_var, PROPERTY_FLAGS_DONTENUM);

	const u8 mflags = PROPERTY_FLAG_WRITABLE; // DONT_ENUM + DONT_DELETE
	addStubMethodToProto(app_context, ctor->prototype_obj, "domain", 6, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "connect", 7, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "close", 5, mflags);
	addStubMethodToProto(app_context, ctor->prototype_obj, "send", 4, mflags);
}

static void ensureGlobalInit(SWFAppContext* app_context)
{
	if (g_global_init_done) return;

	if (global_object == NULL)
	{
		global_object = allocObject(app_context, 64);
	}

	// ---- Existing built-in constructors (Object, Array, String, Number, Boolean, Function) ----
	// Function constructor is SWF6+ only
	static ASFunction g_ctors[6];
	memset(g_ctors, 0, sizeof(g_ctors));
	const char* ctor_names[] = {"Object", "Array", "String", "Number", "Boolean", "Function"};
	int ctor_name_lens[] = {6, 5, 6, 6, 7, 8};
	int num_ctors = (g_swf_version >= 6) ? 6 : 5;
	for (int ci = 0; ci < num_ctors; ci++)
	{
		strncpy(g_ctors[ci].name, ctor_names[ci], 255);
		g_ctors[ci].function_type = 1;
		ActionVar cv = {0};
		cv.type = ACTION_STACK_VALUE_FUNCTION;
		cv.data.numeric_value = (u64)&g_ctors[ci];
		setProperty(app_context, global_object, ctor_names[ci], ctor_name_lens[ci], &cv);
	}

	// ---- MovieClip ----
	initMovieClipPrototype(app_context);
	{
		ActionVar mc_cv = {0};
		mc_cv.type = ACTION_STACK_VALUE_FUNCTION;
		mc_cv.data.numeric_value = (u64)&g_movieclip_constructor;
		setProperty(app_context, global_object, "MovieClip", 9, &mc_cv);
	}

	// ---- TextField ----
	initTextFieldPrototype(app_context);
	{
		ActionVar tf_cv = {0};
		tf_cv.type = ACTION_STACK_VALUE_FUNCTION;
		tf_cv.data.numeric_value = (u64)&g_textfield_constructor;
		setProperty(app_context, global_object, "TextField", 9, &tf_cv);
	}

	// ---- TextFormat ----
	initTextFormatPrototype(app_context);
	{
		ActionVar tfmt_cv = {0};
		tfmt_cv.type = ACTION_STACK_VALUE_FUNCTION;
		tfmt_cv.data.numeric_value = (u64)&g_textformat_constructor;
		setProperty(app_context, global_object, "TextFormat", 10, &tfmt_cv);
	}

	// ---- XML and XMLNode ----
	initXMLPrototype(app_context);
	{
		ActionVar xml_cv = {0};
		xml_cv.type = ACTION_STACK_VALUE_FUNCTION;
		xml_cv.data.numeric_value = (u64)&g_xml_constructor;
		setProperty(app_context, global_object, "XML", 3, &xml_cv);
	}
	{
		ActionVar xmln_cv = {0};
		xmln_cv.type = ACTION_STACK_VALUE_FUNCTION;
		xmln_cv.data.numeric_value = (u64)&g_xmlnode_constructor;
		setProperty(app_context, global_object, "XMLNode", 7, &xmln_cv);
	}

	// ---- Math ----
	initMathObject(app_context);
	setObjectProto(app_context, g_math_object);
	{
		ActionVar math_cv = {0};
		math_cv.type = ACTION_STACK_VALUE_OBJECT;
		math_cv.data.numeric_value = (u64)g_math_object;
		setProperty(app_context, global_object, "Math", 4, &math_cv);
	}

	// ---- Date ----
	initDatePrototype(app_context);
	{
		ActionVar date_cv = {0};
		date_cv.type = ACTION_STACK_VALUE_FUNCTION;
		date_cv.data.numeric_value = (u64)&g_date_constructor;
		setProperty(app_context, global_object, "Date", 4, &date_cv);
	}

	// ---- Error ----
	{
		static ASFunction g_error_ctor;
		static int g_error_init = 0;
		if (!g_error_init)
		{
			memset(&g_error_ctor, 0, sizeof(ASFunction));
			strncpy(g_error_ctor.name, "Error", 255);
			g_error_ctor.function_type = 1;
			g_error_init = 1;
		}
		ActionVar ev = {0};
		ev.type = ACTION_STACK_VALUE_FUNCTION;
		ev.data.numeric_value = (u64)&g_error_ctor;
		setProperty(app_context, global_object, "Error", 5, &ev);
	}

	// ---- ASSetPropFlags (global function) ----
	{
		static ASFunction g_aspf_func;
		static int g_aspf_init = 0;
		if (!g_aspf_init)
		{
			memset(&g_aspf_func, 0, sizeof(ASFunction));
			strncpy(g_aspf_func.name, "ASSetPropFlags", 255);
			g_aspf_func.function_type = 1;
			g_aspf_init = 1;
		}
		ActionVar aspf_var = {0};
		aspf_var.type = ACTION_STACK_VALUE_FUNCTION;
		aspf_var.data.numeric_value = (u64)&g_aspf_func;
		setProperty(app_context, global_object, "ASSetPropFlags", 14, &aspf_var);
	}

	// ---- ASnative (global function) ----
	{
		static ASFunction g_asnative_func;
		static int g_asnative_init = 0;
		if (!g_asnative_init)
		{
			memset(&g_asnative_func, 0, sizeof(ASFunction));
			strncpy(g_asnative_func.name, "ASnative", 255);
			g_asnative_func.function_type = 2;
			g_asnative_func.advanced_func = (Function2Ptr)builtin_asnative;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_asnative_func;
			g_asnative_init = 1;
		}
		ActionVar an_var = {0};
		an_var.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &an_var.data.numeric_value) = (u64)&g_asnative_func;
		setProperty(app_context, global_object, "ASnative", 8, &an_var);
	}

	// ---- Stub constructors (function type with prototype) ----
	{
		static const char* stub_names[NUM_STUB_CTORS] = {
			"AsBroadcaster", "Button", "Camera", "Color",
			"ContextMenu", "ContextMenuItem", "LoadVars",
			"LocalConnection", "Microphone", "MovieClipLoader",
			"NetConnection", "NetStream", "PrintJob", "SharedObject",
			"Sound", "TextSnapshot", "Video", "XMLSocket"
		};
		static const int stub_name_lens[NUM_STUB_CTORS] = {
			13, 6, 6, 5,
			11, 15, 8,
			15, 10, 15,
			13, 9, 8, 12,
			5, 12, 5, 9
		};
		for (int i = 0; i < NUM_STUB_CTORS; i++)
		{
			memset(&g_stub_ctors[i], 0, sizeof(ASFunction));
			strncpy(g_stub_ctors[i].name, stub_names[i], 255);
			g_stub_ctors[i].function_type = 1;
			// prototype_obj is lazily created on first .prototype access
			ActionVar sv = {0};
			sv.type = ACTION_STACK_VALUE_FUNCTION;
			sv.data.numeric_value = (u64)&g_stub_ctors[i];
			setProperty(app_context, global_object, stub_names[i], stub_name_lens[i], &sv);
		}
	}

	// ---- Static global objects (typeof = "object", inherit Object.prototype) ----
	{
		g_accessibility_obj = allocObject(app_context, 4);
		g_key_obj = allocObject(app_context, 16);
		g_mouse_obj = allocObject(app_context, 16);
		g_selection_obj = allocObject(app_context, 16);
		g_stage_obj = allocObject(app_context, 16);

		struct { const char* name; int len; ASObject* obj; } objs[] = {
			{"Accessibility", 13, g_accessibility_obj},
			{"Key", 3, g_key_obj},
			{"Mouse", 5, g_mouse_obj},
			{"Selection", 9, g_selection_obj},
			{"Stage", 5, g_stage_obj},
		};
		for (int i = 0; i < 5; i++)
		{
			setObjectProto(app_context, objs[i].obj);
			ActionVar ov = {0};
			ov.type = ACTION_STACK_VALUE_OBJECT;
			ov.data.numeric_value = (u64)objs[i].obj;
			setProperty(app_context, global_object, objs[i].name, objs[i].len, &ov);
		}

		// Native static objects always trace as "[object Object]" regardless of SWF version
		installNativeToString(app_context, g_accessibility_obj);
		installNativeToString(app_context, g_key_obj);
		installNativeToString(app_context, g_mouse_obj);
		installNativeToString(app_context, g_selection_obj);
		installNativeToString(app_context, g_stage_obj);

		// Install AsBroadcaster methods on Mouse, Key, Stage, Selection
		installAsBroadcaster(app_context, g_mouse_obj);
		installAsBroadcaster(app_context, g_key_obj);
		installKeyMethods(app_context, g_key_obj);
		installAsBroadcaster(app_context, g_stage_obj);
		installAsBroadcaster(app_context, g_selection_obj);

		// Install Selection.setFocus and Selection.getFocus
#ifdef NO_GRAPHICS
		{
			static int sel_funcs_init = 0;
			if (!sel_funcs_init) {
				memset(&g_selection_setFocus_func, 0, sizeof(ASFunction));
				strncpy(g_selection_setFocus_func.name, "setFocus", 255);
				g_selection_setFocus_func.function_type = 2;
				g_selection_setFocus_func.advanced_func = (Function2Ptr)builtin_selection_setFocus;
				memset(&g_selection_getFocus_func, 0, sizeof(ASFunction));
				strncpy(g_selection_getFocus_func.name, "getFocus", 255);
				g_selection_getFocus_func.function_type = 2;
				g_selection_getFocus_func.advanced_func = (Function2Ptr)builtin_selection_getFocus;
				sel_funcs_init = 1;
			}
			ActionVar fv = {0};
			fv.type = ACTION_STACK_VALUE_FUNCTION;
			fv.data.numeric_value = (u64)&g_selection_setFocus_func;
			setProperty(app_context, g_selection_obj, "setFocus", 8, &fv);
			fv.data.numeric_value = (u64)&g_selection_getFocus_func;
			setProperty(app_context, g_selection_obj, "getFocus", 8, &fv);
		}
#endif

		// Also install addListener/removeListener/broadcastMessage on AsBroadcaster itself
		// and on MovieClipLoader.prototype (both are AsBroadcaster-initialized in Flash).
		// This ensures AsBroadcaster.addListener === Mouse.addListener (same func pointer).
		// Note: the test compares mcl.addListener (instance) vs ab.addListener (AsBroadcaster
		// constructor), so MCL methods go on prototype_obj while AB methods go on own_props.
		initAsBroadcasterFuncs(app_context);
		{
			ActionVar fv = {0};
			fv.type = ACTION_STACK_VALUE_FUNCTION;

			// AsBroadcaster (stub_ctors[0]) — install on own_props so AsBroadcaster.addListener works
			if (g_stub_ctors[0].own_props == NULL) {
				g_stub_ctors[0].own_props = allocObject(app_context, 4);
				retainObject(g_stub_ctors[0].own_props);
			}
			fv.data.numeric_value = (u64)&g_ab_addListener_func;
			setProperty(app_context, g_stub_ctors[0].own_props, "addListener", 11, &fv);
			fv.data.numeric_value = (u64)&g_ab_removeListener_func;
			setProperty(app_context, g_stub_ctors[0].own_props, "removeListener", 14, &fv);
			fv.data.numeric_value = (u64)&g_ab_broadcastMessage_func;
			setProperty(app_context, g_stub_ctors[0].own_props, "broadcastMessage", 16, &fv);

			// MovieClipLoader (stub_ctors[9]) — pre-create prototype and install methods there
			// so that MCL instances (var mcl = new MovieClipLoader()) inherit them.
			if (g_stub_ctors[9].prototype_obj == NULL) {
				g_stub_ctors[9].prototype_obj = allocObject(app_context, 8);
				retainObject(g_stub_ctors[9].prototype_obj);
				setObjectProto(app_context, g_stub_ctors[9].prototype_obj);
				ActionVar ctor_var = {0};
				ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
				ctor_var.data.numeric_value = (u64)&g_stub_ctors[9];
				setProperty(app_context, g_stub_ctors[9].prototype_obj, "constructor", 11, &ctor_var);
			}
			fv.data.numeric_value = (u64)&g_ab_addListener_func;
			setProperty(app_context, g_stub_ctors[9].prototype_obj, "addListener", 11, &fv);
			fv.data.numeric_value = (u64)&g_ab_removeListener_func;
			setProperty(app_context, g_stub_ctors[9].prototype_obj, "removeListener", 14, &fv);
			fv.data.numeric_value = (u64)&g_ab_broadcastMessage_func;
			setProperty(app_context, g_stub_ctors[9].prototype_obj, "broadcastMessage", 16, &fv);
		}
	}

	// ---- Prototype setup for stub classes ----
	// LocalConnection (stub_ctors[7]): domain, connect, close, send
	initLocalConnectionPrototype(app_context, &g_stub_ctors[7]);
	// PrintJob (stub_ctors[12]): numeric properties + SWF7 method stubs
	initPrintJobPrototype(app_context, &g_stub_ctors[12]);
	// Sound (stub_ctors[14]): toString + SWF5/6 method stubs
	initSoundPrototype(app_context, &g_stub_ctors[14]);

	// ---- valueOf on _global ----
	{
		ActionVar undef_val = {0};
		undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
		setProperty(app_context, global_object, "valueOf", 7, &undef_val);
	}

	g_global_init_done = 1;
}

void actionGetVariable(SWFAppContext* app_context)
{
	// Read variable name info from stack
	// Stack layout for strings: +0=type, +4=oldSP, +8=length, +12=string_id, +16=pointer
	u32 string_id = VAL(u32, &STACK[SP + 12]);
	char _gv_buf[512];
	u32 _gv_u16_len = VAL(u32, &STACK[SP + 8]);
	u32 var_name_len = (u32)u16_to_utf8((const uint16_t*)VAL(u64, &STACK[SP + 16]), _gv_u16_len, _gv_buf, sizeof(_gv_buf));
	char* var_name = _gv_buf;

	// Pop variable name
	POP();

	// Handle dot-path resolution (e.g., "a.b.c", "_root.x.y", "_global.x.y.z")
	{
		char* dot = (char*) memchr(var_name, '.', var_name_len);
		if (dot != NULL)
		{
			u32 first_len = (u32)(dot - var_name);

			// Resolve first segment by pushing it and recursing
			PUSH_STR(var_name, first_len);
			actionGetVariable(app_context);

			// Walk remaining segments via GetMember
			const char* rest = dot + 1;
			u32 rest_len = var_name_len - first_len - 1;
			while (rest_len > 0)
			{
				char* next_dot = (char*) memchr(rest, '.', rest_len);
				u32 seg_len = next_dot ? (u32)(next_dot - rest) : rest_len;

				// Push segment name on top, then GetMember pops (name, obj) → pushes result
				PUSH_STR(rest, seg_len);
				actionGetMember(app_context);

				if (next_dot) {
					rest = next_dot + 1;
					rest_len -= seg_len + 1;
				} else {
					rest_len = 0;
				}
			}

			// Fallback: if the path resolved to undefined, try starting from _global.
			// In Flash, GetVariable("a.b.c") tries each scope for "a" and walks the
			// remaining path; if the walk fails, it tries the next scope. The _global
			// object is the last scope checked. This handles cases where a local "a"
			// exists but doesn't have the full nested path, while _global.a does.
			if (STACK_TOP_TYPE == ACTION_STACK_VALUE_UNDEFINED)
			{
				extern ASObject* global_object;
				if (global_object != NULL)
				{
					ActionVar* gprop = getPropertyWithPrototype(global_object, var_name, first_len);
					if (gprop != NULL && gprop->type != ACTION_STACK_VALUE_UNDEFINED)
					{
						// Pop the undefined result from the first attempt
						POP();
						// Push the _global property value and walk the remaining path
						pushVar(app_context, gprop);
						rest = dot + 1;
						rest_len = var_name_len - first_len - 1;
						while (rest_len > 0)
						{
							char* next_dot2 = (char*) memchr(rest, '.', rest_len);
							u32 seg_len2 = next_dot2 ? (u32)(next_dot2 - rest) : rest_len;
							PUSH_STR(rest, seg_len2);
							actionGetMember(app_context);
							if (next_dot2) {
								rest = next_dot2 + 1;
								rest_len -= seg_len2 + 1;
							} else {
								rest_len = 0;
							}
						}
					}
				}
			}
			return;
		}
	}

	// First check scope chain (innermost to outermost)
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			// Check for addProperty getter in scope chain (with prototype traversal for with-scopes)
			ASProperty* prop_struct = scope_is_with[i]
				? findPropertyStructWithPrototype(scope_chain[i], var_name, var_name_len)
				: NULL;
			// For non-with scopes, check own properties only
			if (!scope_is_with[i])
			{
				for (u32 pi = 0; pi < scope_chain[i]->num_used; pi++)
				{
					if (scope_chain[i]->properties[pi].name_length == var_name_len &&
					    strncmp(scope_chain[i]->properties[pi].name, var_name, var_name_len) == 0)
					{
						prop_struct = &scope_chain[i]->properties[pi];
						break;
					}
				}
			}
			if (prop_struct != NULL)
			{
				if (prop_struct->getter != NULL)
				{
					ActionVar result = invokePropertyGetter(app_context, (ASFunction*)prop_struct->getter, (void*)scope_chain[i]);
					pushVar(app_context, &result);
				}
				else
				{
					pushVar(app_context, &prop_struct->value);
				}
				return;
			}
		}
		// If this scope entry is a MovieClip, also check built-in MC properties
		if (scope_mc[i] != NULL)
		{
			ActionVar mc_result = {0};
			int mc_found = getMCBuiltinProperty(scope_mc[i], var_name, var_name_len, &mc_result);
			if (mc_found == 1)
			{
				pushVar(app_context, &mc_result);
				return;
			}
			else if (mc_found == 2)  // _name
			{
				PUSH_STR(scope_mc[i]->name, strlen(scope_mc[i]->name));
				return;
			}
			else if (mc_found == 3)  // _target
			{
				PUSH_STR(scope_mc[i]->target, strlen(scope_mc[i]->target));
				return;
			}
			else if (var_name_len == 9 && strncmp(var_name, "transform", 9) == 0)
			{
				ASObject* tobj = createTransformObject(app_context, scope_mc[i]);
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64)tobj);
				return;
			}
		}
	}

	// Inside tellTarget (non-root context): use target clip's variable scope
	// instead of the global variable table (which holds root timeline vars)
	ActionVar* var = NULL;
	if (g_current_context != NULL && g_current_context != &root_movieclip)
	{
		// Check target clip's dynamic properties
		if (g_current_context->dynamic_props != NULL)
		{
			ASObject* clip_props = (ASObject*) g_current_context->dynamic_props;
			ActionVar* prop = getProperty(clip_props, var_name, var_name_len);
			if (prop != NULL)
			{
				PUSH_VAR(prop);
				return;
			}
		}
		// Not found on clip — var stays NULL, falls through to _global/special vars
	}
	else
	{
		// Root context: check global_object for addProperty getter before var table
		{
			extern ASObject* global_object;
			if (global_object != NULL)
			{
				ASProperty* gp = findPropertyStructWithPrototype(global_object, var_name, var_name_len);
				if (gp != NULL && gp->getter != NULL)
				{
					ActionVar result = invokePropertyGetter(app_context, (ASFunction*)gp->getter, (void*)global_object);
					pushVar(app_context, &result);
					return;
				}
			}
		}

		// Root context: check global variable table (normal behavior)
		if (string_id != 0)
		{
			// Constant string - use array (O(1))
			var = getVariableById(string_id);

			// Fall back to hashmap if array lookup doesn't find the variable
			// (This can happen for catch variables that are set by name but have a string ID)
			// Note: uninitialized slots have type=STRING(0), str_size=0, heap_ptr=NULL
			// Explicitly-set empty strings have heap_ptr=u16_empty (non-NULL)
			if (var == NULL || (var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0 && var->data.string_data.heap_ptr == NULL))
			{
				var = getVariable(var_name, var_name_len);
			}
		}
		else
		{
			// Dynamic string - use hashmap (O(n))
			var = getVariable(var_name, var_name_len);
		}
	}

	if (!var || (var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0 && var->data.string_data.heap_ptr == NULL))
	{
		// Check special variables (SWF5+ only — SWF4 has no built-in constants)
		// Note: inside functions in SWF4, use SWF5+ behavior (DefineFunction is SWF5 opcode)
		if (EFFECTIVE_SWF_VERSION() >= 5) {
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

		// "transform" — built-in MovieClip property for the current clip context
		// (scope_mc[i] is only set inside WITH blocks; root-frame scripts need this path)
		if (var_name_len == 9 && strncmp(var_name, "transform", 9) == 0)
		{
			extern MovieClip root_movieclip;
			MovieClip* mc = (g_current_context != NULL) ? g_current_context : &root_movieclip;
			ASObject* tobj = createTransformObject(app_context, mc);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)tobj);
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
		// Flash Player uses "o" as a temporary variable during global initialization
		// for symbol/class registration. It gets set to null (not deleted) when done,
		// so in every SWF, the global variable "o" resolves to null.
		else if (var_name_len == 1 && var_name[0] == 'o')
		{
			PUSH(ACTION_STACK_VALUE_NULL, 0);
			return;
		}
		else if (var_name_len == 7 && strncmp(var_name, "_global", 7) == 0)
		{
			ensureGlobalInit(app_context);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)global_object);
			return;
		}
		else if (var_name_len == 5 && strncmp(var_name, "Array", 5) == 0)
		{
			// Return the built-in Array constructor as a function
			static ASFunction g_array_constructor;
			static int g_array_constructor_init = 0;
			if (!g_array_constructor_init)
			{
				memset(&g_array_constructor, 0, sizeof(ASFunction));
				strncpy(g_array_constructor.name, "Array", 255);
				g_array_constructor.function_type = 1;
				g_array_constructor.param_count = 0;
				g_array_constructor_init = 1;
				// Initialize Array.prototype (shared singleton used by instanceof and arguments.__proto__)
				if (g_array_prototype == NULL)
				{
					g_array_prototype = allocObject(app_context, 4);
					retainObject(g_array_prototype);
					setObjectProto(app_context, g_array_prototype);
				}
				g_array_constructor.prototype_obj = g_array_prototype;
				// Register Array sort-flag constants on own_props
				g_array_constructor.own_props = allocObject(app_context, 8);
				if (g_array_constructor.own_props != NULL) {
					retainObject(g_array_constructor.own_props);
					static const char* const_names[] = {
						"CASEINSENSITIVE", "DESCENDING", "UNIQUESORT",
						"RETURNINDEXEDARRAY", "NUMERIC"
					};
					static const int const_values[] = { 1, 2, 4, 8, 16 };
					for (int _ci = 0; _ci < 5; _ci++) {
						ActionVar _cv = {0};
						_cv.type = ACTION_STACK_VALUE_F64;
						double _cvd = (double) const_values[_ci];
						VAL(double, &_cv.data.numeric_value) = _cvd;
						setProperty(app_context, g_array_constructor.own_props,
						            const_names[_ci], strlen(const_names[_ci]), &_cv);
					}
				}
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_array_constructor);
			return;
		}
		else if (var_name_len == 6 && strncmp(var_name, "Object", 6) == 0)
		{
			// Return the built-in Object constructor as a function
			static ASFunction g_object_constructor;
			static int g_object_constructor_init = 0;
			if (!g_object_constructor_init)
			{
				memset(&g_object_constructor, 0, sizeof(ASFunction));
				strncpy(g_object_constructor.name, "Object", 255);
				g_object_constructor.function_type = 1;
				g_object_constructor.param_count = 0;
				g_object_constructor.simple_func = (SimpleFunctionPtr) builtin_object_toString; // placeholder
				// Point prototype_obj at the REAL g_object_prototype so that
				// Object.prototype identity checks (isPrototypeOf etc.) work correctly
				g_object_constructor.prototype_obj = getObjectPrototype(app_context);
				g_object_constructor_init = 1;
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_object_constructor);
			return;
		}
		else if (var_name_len == 9 && strncmp(var_name, "MovieClip", 9) == 0)
		{
			// Return the built-in MovieClip constructor as a function
			initMovieClipPrototype(app_context);
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_movieclip_constructor);
			return;
		}
		else if (var_name_len == 9 && strncmp(var_name, "TextField", 9) == 0)
		{
			// Return the built-in TextField constructor as a function
			initTextFieldPrototype(app_context);
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_textfield_constructor);
			return;
		}
		else if (var_name_len == 10 && strncmp(var_name, "TextFormat", 10) == 0)
		{
			initTextFormatPrototype(app_context);
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_textformat_constructor);
			return;
		}
		else if (var_name_len == 6 && strncmp(var_name, "String", 6) == 0)
		{
			// Return the built-in String constructor as a function
			static ASFunction g_string_constructor;
			static int g_string_constructor_init = 0;
			if (!g_string_constructor_init)
			{
				memset(&g_string_constructor, 0, sizeof(ASFunction));
				strncpy(g_string_constructor.name, "String", 255);
				g_string_constructor.function_type = 1;
				g_string_constructor.param_count = 0;

				// Register String.fromCharCode as a static method
				g_string_constructor.own_props = allocObject(app_context, 4);
				retainObject(g_string_constructor.own_props);
				memset(&g_string_fromCharCode_func, 0, sizeof(ASFunction));
				strncpy(g_string_fromCharCode_func.name, "fromCharCode", 255);
				g_string_fromCharCode_func.function_type = 2;
				g_string_fromCharCode_func.param_count = 0;
				g_string_fromCharCode_func.advanced_func = (Function2Ptr) builtin_string_fromCharCode;
				if (function_count < MAX_FUNCTIONS)
					function_registry[function_count++] = &g_string_fromCharCode_func;
				ActionVar fcc_val = {0};
				fcc_val.type = ACTION_STACK_VALUE_FUNCTION;
				VAL(u64, &fcc_val.data.numeric_value) = (u64) &g_string_fromCharCode_func;
				setProperty(app_context, g_string_constructor.own_props, "fromCharCode", 12, &fcc_val);

				g_string_constructor_init = 1;
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_string_constructor);
			return;
		}
		else if (var_name_len == 6 && strncmp(var_name, "Number", 6) == 0)
		{
			// Return the built-in Number constructor as a function
			static ASFunction g_number_constructor;
			static int g_number_constructor_init = 0;
			if (!g_number_constructor_init)
			{
				memset(&g_number_constructor, 0, sizeof(ASFunction));
				strncpy(g_number_constructor.name, "Number", 255);
				g_number_constructor.function_type = 1;
				g_number_constructor.param_count = 0;

				// Register Number static constants as own_props
				g_number_constructor.own_props = allocObject(app_context, 8);
				retainObject(g_number_constructor.own_props);
				ActionVar _ncp_nan = makeF64(NAN);
				setProperty(app_context, g_number_constructor.own_props, "NaN", 3, &_ncp_nan);
				ActionVar _ncp_posinf = makeF64(INFINITY);
				setProperty(app_context, g_number_constructor.own_props, "POSITIVE_INFINITY", 17, &_ncp_posinf);
				ActionVar _ncp_neginf = makeF64(-INFINITY);
				setProperty(app_context, g_number_constructor.own_props, "NEGATIVE_INFINITY", 17, &_ncp_neginf);
				ActionVar _ncp_min = makeF64(5e-324);
				setProperty(app_context, g_number_constructor.own_props, "MIN_VALUE", 9, &_ncp_min);
				// Flash traces Number.MAX_VALUE as "1.79769313486231e+308" (truncates at 15 sig figs),
				// but %.15g on DBL_MAX rounds up to "1.79769313486232e+308".
				// The literal 1.7976931348623149e+308 is the nearest representable double
				// below the rounding boundary, producing the correct Flash output.
				ActionVar _ncp_max = makeF64(1.7976931348623149e+308);
				setProperty(app_context, g_number_constructor.own_props, "MAX_VALUE", 9, &_ncp_max);

				g_number_constructor_init = 1;
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_number_constructor);
			return;
		}
		else if (var_name_len == 7 && strncmp(var_name, "Boolean", 7) == 0)
		{
			// Return the built-in Boolean constructor as a function
			static ASFunction g_boolean_constructor;
			static int g_boolean_constructor_init = 0;
			if (!g_boolean_constructor_init)
			{
				memset(&g_boolean_constructor, 0, sizeof(ASFunction));
				strncpy(g_boolean_constructor.name, "Boolean", 255);
				g_boolean_constructor.function_type = 1;
				g_boolean_constructor.param_count = 0;
				g_boolean_constructor_init = 1;
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_boolean_constructor);
			return;
		}
		else if (var_name_len == 5 && strncmp(var_name, "Error", 5) == 0)
		{
			// Return the built-in Error constructor as a function
			static ASFunction g_error_constructor;
			static int g_error_constructor_init = 0;
			if (!g_error_constructor_init)
			{
				memset(&g_error_constructor, 0, sizeof(ASFunction));
				strncpy(g_error_constructor.name, "Error", 255);
				g_error_constructor.function_type = 1;
				g_error_constructor.param_count = 0;
				// Set up prototype with name and message properties
				g_error_constructor.prototype_obj = allocObject(app_context, 12);
				retainObject(g_error_constructor.prototype_obj);
				setObjectProto(app_context, g_error_constructor.prototype_obj);
				ActionVar name_val = {0};
				name_val.type = ACTION_STACK_VALUE_STRING;
				name_val.str_size = 5;
				VAL(u64, &name_val.data.numeric_value) = (u64)u16_Error;
				setProperty(app_context, g_error_constructor.prototype_obj, "name", 4, &name_val);
				ActionVar msg_val = {0};
				msg_val.type = ACTION_STACK_VALUE_STRING;
				msg_val.str_size = 5;
				VAL(u64, &msg_val.data.numeric_value) = (u64)u16_Error;
				setProperty(app_context, g_error_constructor.prototype_obj, "message", 7, &msg_val);

				// Set up toString method on Error.prototype
				memset(&g_error_toString_func, 0, sizeof(ASFunction));
				strncpy(g_error_toString_func.name, "toString", 255);
				g_error_toString_func.function_type = 2;
				g_error_toString_func.param_count = 0;
				g_error_toString_func.advanced_func = (Function2Ptr) builtin_error_toString;
				if (function_count < MAX_FUNCTIONS)
					function_registry[function_count++] = &g_error_toString_func;
				ActionVar ts_val = {0};
				ts_val.type = ACTION_STACK_VALUE_FUNCTION;
				VAL(u64, &ts_val.data.numeric_value) = (u64) &g_error_toString_func;
				setProperty(app_context, g_error_constructor.prototype_obj, "toString", 8, &ts_val);

				g_error_constructor_init = 1;
			}
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_error_constructor);
			return;
		}
		else if (var_name_len == 3 && strncmp(var_name, "XML", 3) == 0)
		{
			initXMLPrototype(app_context);
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_xml_constructor);
			return;
		}
		else if (var_name_len == 7 && strncmp(var_name, "XMLNode", 7) == 0)
		{
			initXMLPrototype(app_context);
			PUSH(ACTION_STACK_VALUE_FUNCTION, (u64)&g_xmlnode_constructor);
			return;
		}
		else if (var_name_len == 4 && strncmp(var_name, "Math", 4) == 0)
		{
			// Return the built-in Math object (singleton, not a constructor)
			initMathObject(app_context);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)g_math_object);
			return;
		}
				else if (var_name_len == 6 && strncmp(var_name, "System", 6) == 0)
		{
			// Lazily create System built-in object
			static ASObject* system_object = NULL;
			if (system_object == NULL)
			{
				system_object = allocObject(app_context, 4);
				setObjectProto(app_context, system_object);
				ASObject* security_obj = allocObject(app_context, 4);
				setObjectProto(app_context, security_obj);
				ActionVar sandbox_val = {0};
				sandbox_val.type = ACTION_STACK_VALUE_STRING;
				sandbox_val.str_size = 13;
				VAL(u64, &sandbox_val.data.numeric_value) = (u64)u16_localWithFile;
				setProperty(app_context, security_obj, "sandboxType", 11, &sandbox_val);
				ActionVar security_var = {0};
				security_var.type = ACTION_STACK_VALUE_OBJECT;
				VAL(u64, &security_var.data.numeric_value) = (u64)security_obj;
				setProperty(app_context, system_object, "security", 8, &security_var);

				// System.capabilities object
				ASObject* caps_obj = allocObject(app_context, 16);
				setObjectProto(app_context, caps_obj);
				ActionVar cap_val = {0};
				// screenResolutionX (default 1536 to match Ruffle test defaults)
				cap_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &cap_val.data.numeric_value) = 1536.0;
				setProperty(app_context, caps_obj, "screenResolutionX", 17, &cap_val);
				// screenResolutionY
				VAL(double, &cap_val.data.numeric_value) = 864.0;
				setProperty(app_context, caps_obj, "screenResolutionY", 17, &cap_val);
				// pixelAspectRatio
				VAL(double, &cap_val.data.numeric_value) = 1.0;
				setProperty(app_context, caps_obj, "pixelAspectRatio", 16, &cap_val);
				// screenDPI
				VAL(double, &cap_val.data.numeric_value) = 72.0;
				setProperty(app_context, caps_obj, "screenDPI", 9, &cap_val);
				// playerType (StandAlone)
				ActionVar pt_val = {0};
				pt_val.type = ACTION_STACK_VALUE_STRING;
				pt_val.str_size = 10;
				VAL(u64, &pt_val.data.numeric_value) = (u64)u16_StandAlone;
				setProperty(app_context, caps_obj, "playerType", 10, &pt_val);
				// version
				ActionVar ver_val = {0};
				ver_val.type = ACTION_STACK_VALUE_STRING;
				ver_val.str_size = 13;
				VAL(u64, &ver_val.data.numeric_value) = (u64)u16_WIN_ver;
				setProperty(app_context, caps_obj, "version", 7, &ver_val);
				// os
				ActionVar os_val = {0};
				os_val.type = ACTION_STACK_VALUE_STRING;
				os_val.str_size = 10;
				VAL(u64, &os_val.data.numeric_value) = (u64)u16_Windows_XP;
				setProperty(app_context, caps_obj, "os", 2, &os_val);
				// manufacturer
				ActionVar mfr_val = {0};
				mfr_val.type = ACTION_STACK_VALUE_STRING;
				mfr_val.str_size = 18;
				VAL(u64, &mfr_val.data.numeric_value) = (u64)u16_Macromedia_Windows;
				setProperty(app_context, caps_obj, "manufacturer", 12, &mfr_val);
				// language
				ActionVar lang_val = {0};
				lang_val.type = ACTION_STACK_VALUE_STRING;
				lang_val.str_size = 2;
				VAL(u64, &lang_val.data.numeric_value) = (u64)u16_en;
				setProperty(app_context, caps_obj, "language", 8, &lang_val);
				// isDebugger
				cap_val.type = ACTION_STACK_VALUE_BOOLEAN;
				VAL(u32, &cap_val.data.numeric_value) = 0;
				setProperty(app_context, caps_obj, "isDebugger", 10, &cap_val);
				// hasAudio
				cap_val.type = ACTION_STACK_VALUE_BOOLEAN;
				VAL(u32, &cap_val.data.numeric_value) = 1;
				setProperty(app_context, caps_obj, "hasAudio", 8, &cap_val);
				// hasVideoEncoder
				cap_val.type = ACTION_STACK_VALUE_BOOLEAN;
				VAL(u32, &cap_val.data.numeric_value) = 1;
				setProperty(app_context, caps_obj, "hasVideoEncoder", 15, &cap_val);
				ActionVar caps_var = {0};
				caps_var.type = ACTION_STACK_VALUE_OBJECT;
				VAL(u64, &caps_var.data.numeric_value) = (u64)caps_obj;
				setProperty(app_context, system_object, "capabilities", 12, &caps_var);

				// System.IME (AsBroadcaster-initialized object)
				ASObject* ime_obj = allocObject(app_context, 4);
				setObjectProto(app_context, ime_obj);
				installAsBroadcaster(app_context, ime_obj);
				ActionVar ime_var = {0};
				ime_var.type = ACTION_STACK_VALUE_OBJECT;
				VAL(u64, &ime_var.data.numeric_value) = (u64)ime_obj;
				setProperty(app_context, system_object, "IME", 3, &ime_var);

				// All System sub-objects are native — always trace as "[object Object]"
				installNativeToString(app_context, system_object);
				installNativeToString(app_context, security_obj);
				installNativeToString(app_context, caps_obj);
				installNativeToString(app_context, ime_obj);
			}
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)system_object);
			return;
		}
		// flash package (flash.display, flash.geom, etc.) - SWF8+ only
		else if (EFFECTIVE_SWF_VERSION() >= 8 && var_name_len == 5 && strncmp(var_name, "flash", 5) == 0)
		{
			static ASObject* flash_object = NULL;
			if (flash_object == NULL)
			{
				flash_object = allocObject(app_context, 8);
				setObjectProto(app_context, flash_object);

				// Helper: create a stub constructor ASFunction
				#define MAKE_STUB_CTOR(varname, namestr) \
					static ASFunction varname; \
					memset(&varname, 0, sizeof(ASFunction)); \
					strncpy(varname.name, namestr, 255); \
					varname.function_type = 1;
				#define SET_CTOR_PROP(parent, propname, proplen, ctorvar) \
					{ ActionVar _cv = {0}; _cv.type = ACTION_STACK_VALUE_FUNCTION; \
					  VAL(u64, &_cv.data.numeric_value) = (u64)&ctorvar; \
					  setProperty(app_context, parent, propname, proplen, &_cv); }
				#define MAKE_PKG(varname, parent, propname, proplen, capacity) \
					ASObject* varname = allocObject(app_context, capacity); \
					setObjectProto(app_context, varname); \
					{ ActionVar _pv = {0}; _pv.type = ACTION_STACK_VALUE_OBJECT; \
					  VAL(u64, &_pv.data.numeric_value) = (u64)varname; \
					  setProperty(app_context, parent, propname, proplen, &_pv); }

				// flash.display
				MAKE_PKG(display_obj, flash_object, "display", 7, 4);
				MAKE_STUB_CTOR(fc_BitmapData, "BitmapData");
				SET_CTOR_PROP(display_obj, "BitmapData", 10, fc_BitmapData);

				// flash.external
				MAKE_PKG(external_obj, flash_object, "external", 8, 4);
				MAKE_STUB_CTOR(fc_ExternalInterface, "ExternalInterface");
				SET_CTOR_PROP(external_obj, "ExternalInterface", 17, fc_ExternalInterface);

				// flash.filters (10 filter classes)
				MAKE_PKG(filters_obj, flash_object, "filters", 7, 12);
				MAKE_STUB_CTOR(fc_BevelFilter, "BevelFilter");
				SET_CTOR_PROP(filters_obj, "BevelFilter", 11, fc_BevelFilter);
				MAKE_STUB_CTOR(fc_BitmapFilter, "BitmapFilter");
				SET_CTOR_PROP(filters_obj, "BitmapFilter", 12, fc_BitmapFilter);
				MAKE_STUB_CTOR(fc_BlurFilter, "BlurFilter");
				SET_CTOR_PROP(filters_obj, "BlurFilter", 10, fc_BlurFilter);
				MAKE_STUB_CTOR(fc_ColorMatrixFilter, "ColorMatrixFilter");
				SET_CTOR_PROP(filters_obj, "ColorMatrixFilter", 17, fc_ColorMatrixFilter);
				MAKE_STUB_CTOR(fc_ConvolutionFilter, "ConvolutionFilter");
				SET_CTOR_PROP(filters_obj, "ConvolutionFilter", 17, fc_ConvolutionFilter);
				MAKE_STUB_CTOR(fc_DisplacementMapFilter, "DisplacementMapFilter");
				SET_CTOR_PROP(filters_obj, "DisplacementMapFilter", 21, fc_DisplacementMapFilter);
				MAKE_STUB_CTOR(fc_DropShadowFilter, "DropShadowFilter");
				SET_CTOR_PROP(filters_obj, "DropShadowFilter", 16, fc_DropShadowFilter);
				MAKE_STUB_CTOR(fc_GlowFilter, "GlowFilter");
				SET_CTOR_PROP(filters_obj, "GlowFilter", 10, fc_GlowFilter);
				MAKE_STUB_CTOR(fc_GradientBevelFilter, "GradientBevelFilter");
				SET_CTOR_PROP(filters_obj, "GradientBevelFilter", 19, fc_GradientBevelFilter);
				MAKE_STUB_CTOR(fc_GradientGlowFilter, "GradientGlowFilter");
				SET_CTOR_PROP(filters_obj, "GradientGlowFilter", 18, fc_GradientGlowFilter);

				// flash.geom (5 classes)
				MAKE_PKG(geom_obj, flash_object, "geom", 4, 8);
				// ColorTransform constructor with prototype
				initColorTransformPrototype(app_context);
				static ASFunction fc_ColorTransform;
				memset(&fc_ColorTransform, 0, sizeof(ASFunction));
				strncpy(fc_ColorTransform.name, "ColorTransform", 255);
				fc_ColorTransform.function_type = 2;
				fc_ColorTransform.advanced_func = (Function2Ptr)colorTransformConstructor;
				fc_ColorTransform.prototype_obj = g_color_transform_prototype;
				retainObject(g_color_transform_prototype);
				if (function_count < MAX_FUNCTIONS) function_registry[function_count++] = &fc_ColorTransform;
				SET_CTOR_PROP(geom_obj, "ColorTransform", 14, fc_ColorTransform);
				// Initialize geometry prototypes (Point, Matrix, Rectangle)
				initGeomPrototypes(app_context);

				// Point constructor with prototype and static methods
				static ASFunction fc_Point;
				memset(&fc_Point, 0, sizeof(ASFunction));
				strncpy(fc_Point.name, "Point", 255);
				fc_Point.function_type = 2;
				fc_Point.advanced_func = (Function2Ptr)pointConstructor;
				fc_Point.prototype_obj = g_point_prototype;
				retainObject(g_point_prototype);
				if (function_count < MAX_FUNCTIONS) function_registry[function_count++] = &fc_Point;
				// Static methods on Point constructor (own_props)
				fc_Point.own_props = allocObject(app_context, 4);
				retainObject(fc_Point.own_props);
				registerGeomMethod(&g_point_statics[0], "distance",    (Function2Ptr)pointDistance,    app_context, fc_Point.own_props);
				registerGeomMethod(&g_point_statics[1], "interpolate", (Function2Ptr)pointInterpolate, app_context, fc_Point.own_props);
				registerGeomMethod(&g_point_statics[2], "polar",       (Function2Ptr)pointPolar,       app_context, fc_Point.own_props);
				SET_CTOR_PROP(geom_obj, "Point", 5, fc_Point);

				// Matrix constructor with prototype
				static ASFunction fc_Matrix;
				memset(&fc_Matrix, 0, sizeof(ASFunction));
				strncpy(fc_Matrix.name, "Matrix", 255);
				fc_Matrix.function_type = 2;
				fc_Matrix.advanced_func = (Function2Ptr)matrixConstructor;
				fc_Matrix.prototype_obj = g_matrix_prototype;
				retainObject(g_matrix_prototype);
				if (function_count < MAX_FUNCTIONS) function_registry[function_count++] = &fc_Matrix;
				SET_CTOR_PROP(geom_obj, "Matrix", 6, fc_Matrix);

				// Rectangle constructor with prototype
				static ASFunction fc_Rectangle;
				memset(&fc_Rectangle, 0, sizeof(ASFunction));
				strncpy(fc_Rectangle.name, "Rectangle", 255);
				fc_Rectangle.function_type = 2;
				fc_Rectangle.advanced_func = (Function2Ptr)rectangleConstructor;
				fc_Rectangle.prototype_obj = g_rect_prototype;
				retainObject(g_rect_prototype);
				if (function_count < MAX_FUNCTIONS) function_registry[function_count++] = &fc_Rectangle;
				SET_CTOR_PROP(geom_obj, "Rectangle", 9, fc_Rectangle);
				MAKE_STUB_CTOR(fc_Transform, "Transform");
				SET_CTOR_PROP(geom_obj, "Transform", 9, fc_Transform);

				// flash.net
				MAKE_PKG(net_obj, flash_object, "net", 3, 4);
				MAKE_STUB_CTOR(fc_FileReference, "FileReference");
				SET_CTOR_PROP(net_obj, "FileReference", 13, fc_FileReference);
				MAKE_STUB_CTOR(fc_FileReferenceList, "FileReferenceList");
				SET_CTOR_PROP(net_obj, "FileReferenceList", 17, fc_FileReferenceList);

				// flash.text
				MAKE_PKG(text_obj, flash_object, "text", 4, 4);
				MAKE_STUB_CTOR(fc_TextRenderer, "TextRenderer");
				SET_CTOR_PROP(text_obj, "TextRenderer", 12, fc_TextRenderer);

				#undef MAKE_STUB_CTOR
				#undef SET_CTOR_PROP
				#undef MAKE_PKG
			}
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)flash_object);
			return;
		}
		} // end if (EFFECTIVE_SWF_VERSION() >= 5)

		// Check _global object properties as fallback
		{
			ensureGlobalInit(app_context);
			ActionVar* gprop = getPropertyWithPrototype(global_object, var_name, var_name_len);
			if (gprop != NULL)
			{
				PUSH_VAR(gprop);
				return;
			}
		}

		// Check MovieClip built-in properties via variable name (e.g., GetVariable("_x"))
		// In Flash, timeline variables and MC properties share the same namespace
		if (var_name_len > 0 && var_name[0] == '_')
		{
			extern MovieClip root_movieclip;
			MovieClip* mc = &root_movieclip;
			if (strcasecmp(var_name, "_x") == 0) { float v = mc->x; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_y") == 0) { float v = mc->y; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_xscale") == 0) { float v = mc->xscale; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_yscale") == 0) { float v = mc->yscale; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_rotation") == 0) { float v = mc->rotation; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_alpha") == 0) { float v = mc->alpha; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_visible") == 0) { u64 v = mc->visible ? 1 : 0; PUSH(ACTION_STACK_VALUE_BOOLEAN, v); return; }
			if (strcasecmp(var_name, "_width") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_ew)); return; }
			if (strcasecmp(var_name, "_height") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_eh)); return; }
			if (strcasecmp(var_name, "_currentframe") == 0) { float v = (float)mc->currentframe; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_totalframes") == 0) { float v = (float)mc->totalframes; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_framesloaded") == 0) { float v = (float)mc->framesloaded; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_name") == 0) { PUSH_STR(mc->name, strlen(mc->name)); return; }
			if (strcasecmp(var_name, "_target") == 0) { PUSH_STR(mc->target, strlen(mc->target)); return; }
			if (strcasecmp(var_name, "_url") == 0) { PUSH_STR(mc->url, strlen(mc->url)); return; }
			if (strcasecmp(var_name, "_droptarget") == 0) { PUSH_STR(mc->droptarget, strlen(mc->droptarget)); return; }
			if (strcasecmp(var_name, "_quality") == 0) { PUSH_STR(mc->quality, strlen(mc->quality)); return; }
			if (strcasecmp(var_name, "_xmouse") == 0) { float v = mc->xmouse; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(var_name, "_ymouse") == 0) { float v = mc->ymouse; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
		}

		// Check display list children by instance name (e.g., GetVariable("clip"))
		// In Flash, child movie clips are accessible as variables by their instance name
		{
			// First, check if name needs to be null-terminated
			char name_buf[64];
			if (var_name_len < 64)
			{
				memcpy(name_buf, var_name, var_name_len);
				name_buf[var_name_len] = '\0';
			}
			else
			{
				memcpy(name_buf, var_name, 63);
				name_buf[63] = '\0';
			}

#ifndef NO_GRAPHICS
			DisplayObject* dobj = findDisplayObjectByName(name_buf);
			if (dobj != NULL)
			{
				extern MovieClip root_movieclip;
				MovieClip* child_mc = findOrCreateMovieClip(app_context, name_buf, &root_movieclip);
				if (child_mc != NULL)
				{
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child_mc);
					return;
				}
			}
#else
			size_t child_depth = ng_findDisplayEntryByName(name_buf);
			if (child_depth != SIZE_MAX)
			{
				extern MovieClip root_movieclip;
				if (!ng_isScriptableAtDepth(child_depth)) {
					// Non-scriptable type (shape, statictext, morphshape, image) — resolves to parent MC
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)&root_movieclip);
					return;
				}
				MovieClip* child_mc = findOrCreateMovieClip(app_context, name_buf, &root_movieclip);
				if (child_mc != NULL)
				{
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child_mc);
					return;
				}
			}
#endif
		}

		// Variable not found
		if (g_swf_version >= 5) {
			// SWF5+: undefined variables return undefined
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		} else {
			// SWF4: undefined variables return empty string
			PUSH_STR("", 0);
		}
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

	char _sv_buf[512];
	u32 _sv_u16_len = VAL(u32, &STACK[var_name_sp + 8]);
	u32 var_name_len = (u32)u16_to_utf8((const uint16_t*)VAL(u64, &STACK[var_name_sp + 16]), _sv_u16_len, _sv_buf, sizeof(_sv_buf));
	char* var_name = _sv_buf;

	// Handle dot-path resolution for SetVariable (e.g., "a.b.c" → resolve a.b, then SetMember c)
	{
		char* dot = (char*) memchr(var_name, '.', var_name_len);
		if (dot != NULL)
		{
			// Find the LAST dot to split into container path and final property name
			char* last_dot = dot;
			for (char* p = dot + 1; p < var_name + var_name_len; p++)
			{
				if (*p == '.') last_dot = p;
			}

			u32 container_len = (u32)(last_dot - var_name);
			const char* final_prop = last_dot + 1;
			u32 final_prop_len = var_name_len - container_len - 1;

			// Save value from stack
			ActionVar value_var;
			peekVar(app_context, &value_var);
			POP_2();

			// Resolve container path via GetVariable (which handles dots recursively)
			PUSH_STR(var_name, container_len);
			actionGetVariable(app_context);

			// Now stack has: [container_obj]
			// Push final property name, then value for SetMember
			PUSH_STR(final_prop, final_prop_len);
			pushVar(app_context, &value_var);
			actionSetMember(app_context);
			return;
		}
	}

	// First check scope chain (innermost to outermost)
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			// Check for addProperty setter in scope chain
			ASProperty* prop_struct = scope_is_with[i]
				? findPropertyStructWithPrototype(scope_chain[i], var_name, var_name_len)
				: NULL;
			if (!scope_is_with[i])
			{
				for (u32 pi = 0; pi < scope_chain[i]->num_used; pi++)
				{
					if (scope_chain[i]->properties[pi].name_length == var_name_len &&
					    strncmp(scope_chain[i]->properties[pi].name, var_name, var_name_len) == 0)
					{
						prop_struct = &scope_chain[i]->properties[pi];
						break;
					}
				}
			}
			if (prop_struct != NULL)
			{
				if (prop_struct->setter != NULL)
				{
					// Virtual property — invoke setter
					ActionVar value_var;
					peekVar(app_context, &value_var);
					POP_2();
					invokePropertySetter(app_context, (ASFunction*)prop_struct->setter, (void*)scope_chain[i], &value_var);
					return;
				}
				// Regular property — set it on the direct scope object
				ActionVar value_var;
				peekVar(app_context, &value_var);
				setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var);
#ifdef NO_GRAPHICS
				ng_syncVarToTextFields(app_context, var_name, var_name_len, &value_var);
#endif

				// Pop both value and name
				POP_2();
				return;
			}
		}
		// If this scope entry is a MovieClip, also check built-in MC properties
		if (scope_mc[i] != NULL)
		{
			ActionVar value_var;
			peekVar(app_context, &value_var);
			if (setMCBuiltinProperty(app_context, scope_mc[i], var_name, var_name_len, &value_var))
			{
				POP_2();
				return;
			}
		}
	}

	// Inside tellTarget (non-root context): set on target clip's properties
	if (g_current_context != NULL && g_current_context != &root_movieclip)
	{
		// Ensure target clip has dynamic_props
		if (g_current_context->dynamic_props == NULL)
		{
			g_current_context->dynamic_props = (void*) allocObject(app_context, 8);
		}
		ASObject* clip_props = (ASObject*) g_current_context->dynamic_props;
		ActionVar value_var;
		peekVar(app_context, &value_var);
		setProperty(app_context, clip_props, var_name, var_name_len, &value_var);
		POP_2();
		return;
	}

	// Check MovieClip built-in properties via variable name (e.g., SetVariable("_x", 100))
	// In Flash, timeline variables and MC properties share the same namespace
	if (var_name_len > 0 && var_name[0] == '_')
	{
		extern MovieClip root_movieclip;
		MovieClip* mc = &root_movieclip;
		ActionVar value_var;
		peekVar(app_context, &value_var);
		double dval = varToDouble(&value_var);
		float fval = (float)dval;
		int handled = 0;
		if (strcasecmp(var_name, "_x") == 0) { mc->x = fval; handled = 1; }
		else if (strcasecmp(var_name, "_y") == 0) { mc->y = fval; handled = 1; }
		else if (strcasecmp(var_name, "_xscale") == 0) { mc->xscale = fval;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 4;
#endif
			handled = 1; }
		else if (strcasecmp(var_name, "_yscale") == 0) { mc->yscale = fval;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 8;
#endif
			handled = 1; }
		else if (strcasecmp(var_name, "_rotation") == 0) { mc->rotation = normalizeRotation(fval);
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 16;
#endif
			handled = 1; }
		else if (strcasecmp(var_name, "_alpha") == 0) { mc->alpha = fval; handled = 1; }
		else if (strcasecmp(var_name, "_visible") == 0) { mc->visible = (fval != 0.0f) ? 1 : 0; handled = 1; }
		else if (strcasecmp(var_name, "_width") == 0) { mcSetEffectiveWidth(app_context, mc, (double)fval); handled = 1; }
		else if (strcasecmp(var_name, "_height") == 0) { mcSetEffectiveHeight(app_context, mc, (double)fval); handled = 1; }
		else if (strcasecmp(var_name, "_quality") == 0)
		{
			char buf[16];
			int len = varToStringBuf(app_context, &value_var, buf, sizeof(buf));
			if (len > 0) { memcpy(mc->quality, buf, len); mc->quality[len] = '\0'; }
			handled = 1;
		}
		else if (strcasecmp(var_name, "_highquality") == 0) { mc->highquality = fval; handled = 1; }
		else if (strcasecmp(var_name, "_focusrect") == 0) { mc->focusrect = fval; handled = 1; }
		else if (strcasecmp(var_name, "_soundbuftime") == 0) { mc->soundbuftime = fval; handled = 1; }
		if (handled)
		{
			POP_2();
			return;
		}
	}

	// Not found in scope chain - check global_object for addProperty setter
	{
		extern ASObject* global_object;
		if (global_object != NULL)
		{
			ASProperty* gp = findPropertyStructWithPrototype(global_object, var_name, var_name_len);
			if (gp != NULL && gp->setter != NULL)
			{
				ActionVar value_var;
				peekVar(app_context, &value_var);
				POP_2();
				invokePropertySetter(app_context, (ASFunction*)gp->setter, (void*)global_object, &value_var);
				return;
			}
		}
	}

	// Set as global variable
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

	// --- Timeline variable watcher check ---
	// In Flash AVM1, watch() on a timeline variable fires when the variable is set.
	// The "clear first" behavior: variable is set to undefined before calling the watcher,
	// so if the watcher throws, the variable stays undefined (matches Flash behavior).
	if (g_watch_count > 0 && !g_execution_halted)
	{
		for (int _wi = 0; _wi < g_watch_count; _wi++)
		{
			WatchEntry* _we = &g_watch_table[_wi];
			MovieClip* _sv_ctx = g_current_context ? g_current_context : &root_movieclip;
			if (_we->obj == NULL && _we->mc == _sv_ctx &&
			    _we->prop_name_len == var_name_len &&
			    strncmp(_we->prop_name, var_name, var_name_len) == 0)
			{
				ASFunction* _wf = _we->watcher_func;
				if (_wf != NULL && _wf->function_type == 2 && _wf->advanced_func != NULL)
				{
					// Save old value (non-owning copy to avoid double-free)
					ActionVar _old_val = *var;
					// Detect "unset" state (type=STRING with NULL ptr = never initialized = undefined)
					if (_old_val.type == ACTION_STACK_VALUE_STRING && _old_val.data.string_data.heap_ptr == NULL)
						_old_val.type = ACTION_STACK_VALUE_UNDEFINED;
					else if (_old_val.type == ACTION_STACK_VALUE_STRING)
						_old_val.data.string_data.owns_memory = false;
					// Get intended new value from stack
					ActionVar _new_val;
					peekVar(app_context, &_new_val);
					// "Clear first": set variable to undefined before calling watcher
					// so that if the watcher throws, the variable remains undefined
					if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory)
						free(var->data.string_data.heap_ptr);
					var->type = ACTION_STACK_VALUE_UNDEFINED;
					var->data.numeric_value = 0;
					var->str_size = 0;
					// Build prop name as string ActionVar
					u32 _pname_u16_len;
					uint16_t* _pname_u16 = ascii_to_u16(app_context, var_name, (int)var_name_len, &_pname_u16_len);
					ActionVar _pname_arg = {0};
					_pname_arg.type = ACTION_STACK_VALUE_STRING;
					_pname_arg.str_size = _pname_u16_len;
					_pname_arg.data.string_data.heap_ptr = _pname_u16;
					_pname_arg.data.string_data.owns_memory = true;
					// Call watcher(propName, oldVal, newVal, userData)
					ActionVar _wargs[4] = { _pname_arg, _old_val, _new_val, _we->user_data };
					ActionVar* _wregs = NULL;
					if (_wf->register_count > 0)
						_wregs = (ActionVar*) HCALLOC(_wf->register_count, sizeof(ActionVar));
					ASObject* _wscope = allocObject(app_context, 4);
					if (scope_depth < MAX_SCOPE_DEPTH) {
						scope_is_with[scope_depth] = 0;
						scope_mc[scope_depth] = NULL;
						scope_chain[scope_depth++] = _wscope;
					}
					g_call_depth++;
					ActionVar _wret = _wf->advanced_func(app_context, _wargs, 4, _wregs, NULL);
					g_call_depth--;
					if (scope_depth > 0) scope_depth--;
					releaseObject(app_context, _wscope);
					if (_wregs != NULL) FREE(_wregs);
					FREE(_pname_u16);
					// If watcher returned non-undefined, use it; else use the intended new value
					ActionVar _actual_new = (_wret.type != ACTION_STACK_VALUE_UNDEFINED) ? _wret : _new_val;
					*var = _actual_new;
					// Sync to hashmap if string_id path was used
					if (string_id != 0) {
						extern hashmap* var_map;
						ActionVar* old_hash;
						if (hashmap_get(var_map, var_name, var_name_len, (uintptr_t*)&old_hash)) {
							if (old_hash != var) {
								if (old_hash->type == ACTION_STACK_VALUE_STRING && old_hash->data.string_data.owns_memory)
									free(old_hash->data.string_data.heap_ptr);
								free(old_hash);
							}
						}
						hashmap_set(var_map, var_name, var_name_len, (uintptr_t)var);
					}
					POP_2();
					return;
				}
				break;
			}
		}
	}
	// --- End timeline variable watcher check ---

	// Compiler barrier: same as actionDefineLocal (see comment there)
	__asm__ volatile("" ::: "memory");
	setVariableWithValue(var, STACK, value_sp);

	// If we used var_array (string_id path), also sync to hashmap so both
	// storage systems point to the same ActionVar. This is needed because
	// textfield variable binding uses the hashmap (setVariableByName/getVariable)
	// while generated scripts use var_array (getVariableById).
	if (string_id != 0) {
		extern hashmap* var_map;
		ActionVar* old_hash;
		if (hashmap_get(var_map, var_name, var_name_len, (uintptr_t*)&old_hash)) {
			if (old_hash != var) {
				// Free the old hashmap entry being replaced
				if (old_hash->type == ACTION_STACK_VALUE_STRING && old_hash->data.string_data.owns_memory)
					free(old_hash->data.string_data.heap_ptr);
				free(old_hash);
			}
		}
		hashmap_set(var_map, var_name, var_name_len, (uintptr_t)var);
	}

#ifdef NO_GRAPHICS
	// Sync variable → text fields
	{
		ActionVar sync_val;
		peekVar(app_context, &sync_val);
		ng_syncVarToTextFields(app_context, var_name, var_name_len, &sync_val);
	}
#endif

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
	char _dl_buf[512];
	u32 _dl_u16_len = VAL(u32, &STACK[var_name_sp + 8]);
	u32 var_name_len = (u32)u16_to_utf8((const uint16_t*)VAL(u64, &STACK[var_name_sp + 16]), _dl_u16_len, _dl_buf, sizeof(_dl_buf));
	char* var_name = _dl_buf;

	// DefineLocal: walk scope chain from innermost to outermost.
	// For 'with' scopes: if the object DIRECTLY owns the property, set it there.
	// For function scopes: always set there (create if needed).
	// If no scope found, fall back to global.

	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] == NULL) continue;

		if (scope_is_with[i])
		{
			// With scope: only set here if the object directly owns the property
			ActionVar* existing = getProperty(scope_chain[i], var_name, var_name_len);
			if (existing != NULL)
			{
				ActionVar value_var;
				peekVar(app_context, &value_var);
				setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var);
				POP_2();
				return;
			}
			// Property not directly on with object — continue to next scope
		}
		else
		{
			// Function scope: always define here
			ActionVar value_var;
			peekVar(app_context, &value_var);
			setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var);
			POP_2();
			return;
		}
	}

	// No function scope - fall back to global variable
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

	// Compiler barrier: GCC -O2 may cache stale stack data across the
	// getVariable/getVariableById calls above (which don't take app_context,
	// so GCC's alias analysis can conclude they don't modify the stack buffer).
	// Force a reload of stack contents before reading the value.
	__asm__ volatile("" ::: "memory");
	setVariableWithValue(var, STACK, value_sp);

	// If we used var_array (string_id path), also sync to hashmap so both
	// storage systems point to the same ActionVar.
	if (string_id != 0) {
		extern hashmap* var_map;
		ActionVar* old_hash;
		if (hashmap_get(var_map, var_name, var_name_len, (uintptr_t*)&old_hash)) {
			if (old_hash != var) {
				if (old_hash->type == ACTION_STACK_VALUE_STRING && old_hash->data.string_data.owns_memory)
					free(old_hash->data.string_data.heap_ptr);
				free(old_hash);
			}
			// Existing entry has a stable heap-allocated key — just update the value.
			hashmap_set(var_map, var_name, var_name_len, (uintptr_t)var);
		} else {
			// New entry: var_name points to a stack buffer (_dl_buf) that becomes
			// a dangling pointer after this function returns. Heap-allocate a copy
			// so the hashmap key remains valid for future lookups.
			char* hm_key = (char*) malloc(var_name_len + 1);
			if (hm_key) {
				memcpy(hm_key, var_name, var_name_len);
				hm_key[var_name_len] = '\0';
				hashmap_set(var_map, hm_key, var_name_len, (uintptr_t)var);
			}
		}
	}

#ifdef NO_GRAPHICS
	// Sync variable → text fields
	{
		ActionVar sync_val;
		peekVar(app_context, &sync_val);
		ng_syncVarToTextFields(app_context, var_name, var_name_len, &sync_val);
	}
#endif

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
	char _dcl_buf[512];
	u32 _dcl_u16_len = VAL(u32, &STACK[SP + 8]);
	u32 var_name_len = (u32)u16_to_utf8((const uint16_t*)VAL(u64, &STACK[SP + 16]), _dcl_u16_len, _dcl_buf, sizeof(_dcl_buf));
	char* var_name = _dcl_buf;

	// DeclareLocal: same logic as DefineLocal but with undefined value.
	// For with scopes: set if object directly owns property.
	// For function scopes: always set.
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] == NULL) continue;

		if (scope_is_with[i])
		{
			ActionVar* existing = getProperty(scope_chain[i], var_name, var_name_len);
			if (existing != NULL)
			{
				ActionVar undefined_var;
				undefined_var.type = ACTION_STACK_VALUE_UNDEFINED;
				undefined_var.str_size = 0;
				undefined_var.data.numeric_value = 0;
				setProperty(app_context, scope_chain[i], var_name, var_name_len, &undefined_var);
				POP();
				return;
			}
		}
		else
		{
			ActionVar undefined_var;
			undefined_var.type = ACTION_STACK_VALUE_UNDEFINED;
			undefined_var.str_size = 0;
			undefined_var.data.numeric_value = 0;
			setProperty(app_context, scope_chain[i], var_name, var_name_len, &undefined_var);
			POP();
			return;
		}
	}

	// Not in a function — Flash silently ignores DeclareLocal outside functions

	// Pop the name
	POP();
}

void actionSetTarget2(SWFAppContext* app_context)
{
	// If top of stack is a MovieClip, use it directly (avoids string round-trip)
	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_MOVIECLIP)
	{
		MovieClip* mc = (MovieClip*) VAL(u64, &STACK_TOP_VALUE);
		POP();
		if (mc != NULL)
			setCurrentContext(mc);
		else
			setCurrentContext(&root_movieclip);
		return;
	}

	// Convert top of stack to string if needed
	char str_buffer[17];
	convertString(app_context, str_buffer);

	// Get target path from stack (convert UTF-16 to char*)
	char _st2_buf[512];
	(void)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _st2_buf, sizeof(_st2_buf));
	const char* target_path = _st2_buf;

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

	// Check for NaN property index — Flash returns undefined
	{
		double d = 0.0;
		if (index_var.type == ACTION_STACK_VALUE_F64)
			d = VAL(double, &index_var.data.numeric_value);
		else if (index_var.type == ACTION_STACK_VALUE_F32)
			d = (double) VAL(float, &index_var.data.numeric_value);
		if (isnan(d))
		{
			// Pop target, push undefined
			convertString(app_context, NULL);
			POP();
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			return;
		}
	}

	int prop_index = varToInt32(&index_var);

	// Pop target path (convert UTF-16 to char* for MovieClip lookup)
	convertString(app_context, NULL);
	char _gp_buf[512];
	(void)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _gp_buf, sizeof(_gp_buf));
	const char* target = _gp_buf;
	POP();

	// Get the MovieClip object
	MovieClip* mc = getMovieClipByTarget(target);

	// Get property value based on index
	float value = 0.0f;
	const char* str_value = NULL;
	int is_string = 0;

	switch (prop_index) {
		case 0:  // _x
#ifdef NO_GRAPHICS
			if (mc) syncTransformIfNeeded(mc);
			if (mc && !(mc->as_set_flags & 1)) {
				size_t _dep = ng_findDisplayEntryByName(mc->name);
				if (_dep != SIZE_MAX) {
					double _dx;
					if (ng_getTransformXY_d(_dep, &_dx, NULL)) {
						PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_dx));
						return;
					}
				}
			}
#endif
			value = mc ? mc->x : 0.0f;
			break;
		case 1:  // _y
#ifdef NO_GRAPHICS
			if (mc) syncTransformIfNeeded(mc);
			if (mc && !(mc->as_set_flags & 2)) {
				size_t _dep = ng_findDisplayEntryByName(mc->name);
				if (_dep != SIZE_MAX) {
					double _dy;
					if (ng_getTransformXY_d(_dep, NULL, &_dy)) {
						PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_dy));
						return;
					}
				}
			}
#endif
			value = mc ? mc->y : 0.0f;
			break;
		case 2:  // _xscale
#ifdef NO_GRAPHICS
			if (mc) syncTransformIfNeeded(mc);
#endif
			value = mc ? mc->xscale : 100.0f;
			break;
		case 3:  // _yscale
#ifdef NO_GRAPHICS
			if (mc) syncTransformIfNeeded(mc);
#endif
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
		case 7:  // _visible — returns boolean, not float
			PUSH(ACTION_STACK_VALUE_BOOLEAN, mc ? (mc->visible ? 1ULL : 0ULL) : 1ULL);
			return;
		case 8:  // _width
			if (mc) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); value = (float)_ew; } else { value = 0.0f; }
			break;
		case 9:  // _height
			if (mc) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); value = (float)_eh; } else { value = 0.0f; }
			break;
		case 10: // _rotation
#ifdef NO_GRAPHICS
			if (mc) syncTransformIfNeeded(mc);
#endif
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
		case 19: // _quality (returns string: "LOW", "MEDIUM", "HIGH", "BEST")
			str_value = mc ? mc->quality : "HIGH";
			is_string = 1;
			break;
		case 20: // _xmouse (SWF 5+)
			value = mc ? mc->xmouse : 0.0f;
			break;
		case 21: // _ymouse (SWF 5+)
			value = mc ? mc->ymouse : 0.0f;
			break;
		default:
			// Unknown/out-of-range property index - push undefined (Flash behavior)
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			return;
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
	(void)str_buffer;
	// Convert top of stack to number
	convertFloat(app_context);

	// Pop the numeric value
	ActionVar a;
	popVar(app_context, &a);

	// Get integer code
	double d = varToDouble(&a);
	if (isnan(d) || isinf(d) || d == 0.0) {
		// chr(null), chr(true→1 but NaN from convertFloat? no), chr(NaN) → empty
		PUSH_U16(u16_empty, 0);
		return;
	}

	// SWF6+: chr() uses full UTF-16 code unit range (0-65535), same as mbchr()
	// Wrap to 16-bit unsigned: & 0xFFFF
	uint16_t code = (uint16_t)((unsigned int)varToInt32(&a) & 0xFFFF);

	// Code 0 → empty string
	if (code == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Surrogates → U+FFFD
	if (code >= 0xD800 && code <= 0xDFFF) code = 0xFFFD;

	uint16_t* result = (uint16_t*)heap_alloc(app_context, sizeof(uint16_t));
	result[0] = code;
	PUSH_U16(result, 1);
}

void actionMbCharToAscii(SWFAppContext* app_context, char* str_buffer)
{
	// Convert top of stack to string
	convertString(app_context, str_buffer);

	// Get UTF-16 string pointer from stack
	const uint16_t* str = (const uint16_t*) VAL(u64, &STACK_TOP_VALUE);
	u32 str_len = STACK_TOP_N;
	POP();

	// Handle empty string
	if (str == NULL || str_len == 0) {
		float result = 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
		return;
	}

	// Flash returns U+FFFD for surrogate code units (supplementary chars)
	uint16_t unit = str[0];
	float result = (unit >= 0xD800 && unit <= 0xDFFF) ? 65533.0f : (float)unit;
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
	(void)str_buffer;
	// Convert top of stack to number
	convertFloat(app_context);

	// Pop the numeric value
	ActionVar a;
	popVar(app_context, &a);

	double d = varToDouble(&a);
	if (isnan(d) || isinf(d) || d == 0.0) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// SWF6+: mbchr() wraps to 16-bit code unit range (& 0xFFFF), same as chr()
	uint16_t code = (uint16_t)((unsigned int)varToInt32(&a) & 0xFFFF);

	if (code == 0) {
		PUSH_U16(u16_empty, 0);
		return;
	}

	// Surrogates → U+FFFD
	if (code >= 0xD800 && code <= 0xDFFF) code = 0xFFFD;

	uint16_t* result = (uint16_t*)heap_alloc(app_context, sizeof(uint16_t));
	result[0] = code;
	PUSH_U16(result, 1);
}

void actionTypeof(SWFAppContext* app_context, char* str_buffer)
{
	// Peek at the type without modifying value
	u8 type = STACK_TOP_TYPE;
#ifdef NO_GRAPHICS
	u64 typeof_val = VAL(u64, &STACK_TOP_VALUE);
#endif

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
#ifdef NO_GRAPHICS
			// In Flash, text fields and buttons return "object" for typeof,
			// only actual sprites/movieclips return "movieclip"
			{
				MovieClip* mc = (MovieClip*) typeof_val;
				if (mc && mc->name[0] != '\0')
				{
					size_t d = ng_findDisplayEntryByName(mc->name);
					if (d != SIZE_MAX && !ng_isSpriteAtDepth(d))
					{
						type_str = "object";
						break;
					}
				}
			}
#endif
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
	u32 string_id = 0;

	// Get the variable name string
	char _d2_buf[512];
	if (name_type == ACTION_STACK_VALUE_STRING)
	{
		u32 _d2_u16_len = VAL(u32, &STACK[var_name_sp + 8]);
		var_name_len = (u32)u16_to_utf8((const uint16_t*)VAL(u64, &STACK[var_name_sp + 16]), _d2_u16_len, _d2_buf, sizeof(_d2_buf));
		var_name = _d2_buf;
		string_id = VAL(u32, &STACK[var_name_sp + 12]);
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
				PUSH(ACTION_STACK_VALUE_BOOLEAN, success ? 1ULL : 0ULL);
				return;
			}
		}
	}

	// Not found in scope chain - try global variables
	// Check both var_array (by string_id) and var_map (by name)
	{
		bool found = false;
		// Check var_array first (used by actionDefineLocal with constant strings)
		if (string_id != 0)
		{
			ActionVar* var = getVariableById(string_id);
			if (var && !(var->type == ACTION_STACK_VALUE_STRING && var->str_size == 0 && var->data.string_data.heap_ptr == NULL))
			{
				// Variable exists in var_array — set to undefined
				if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory)
				{
					free(var->data.string_data.heap_ptr);
					var->data.string_data.heap_ptr = NULL;
					var->data.string_data.owns_memory = false;
				}
				var->type = ACTION_STACK_VALUE_UNDEFINED;
				var->data.numeric_value = 0;
				var->str_size = 0;
				found = true;
			}
		}
		// Also check var_map
		if (!found && hasVariable(var_name, var_name_len))
		{
			ActionVar* var = getVariable(var_name, var_name_len);
			if (var)
			{
				if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory)
				{
					free(var->data.string_data.heap_ptr);
					var->data.string_data.heap_ptr = NULL;
					var->data.string_data.owns_memory = false;
				}
				var->type = ACTION_STACK_VALUE_UNDEFINED;
				var->data.numeric_value = 0;
				var->str_size = 0;
				found = true;
			}
		}
		success = true;  // Flash always returns true for Delete2
	}

	// Push result
	PUSH(ACTION_STACK_VALUE_BOOLEAN, success ? 1ULL : 0ULL);
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

	if (obj_var->data.numeric_value == 0 || ctor_var->data.numeric_value == 0)
	{
		return 0;
	}

	// Get the constructor's "prototype" — handle ASFunction vs ASObject
	ASObject* ctor_proto = NULL;
	if (ctor_var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* ctor_func = (ASFunction*) ctor_var->data.numeric_value;
		ctor_proto = ctor_func->prototype_obj;
	}
	else
	{
		ASObject* ctor = (ASObject*) ctor_var->data.numeric_value;
		ActionVar* ctor_proto_var = getProperty(ctor, "prototype", 9);
		if (ctor_proto_var != NULL && ctor_proto_var->type == ACTION_STACK_VALUE_OBJECT)
			ctor_proto = (ASObject*) ctor_proto_var->data.numeric_value;
	}

	if (ctor_proto == NULL)
	{
		return 0;
	}

	// Get the object for __proto__ chain walk — handle ASFunction vs ASObject vs ASArray
	ASObject* obj;
	if (obj_var->type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* obj_func = (ASFunction*) obj_var->data.numeric_value;
		obj = obj_func->own_props;
		if (obj == NULL) return 0;
	}
	else if (obj_var->type == ACTION_STACK_VALUE_ARRAY)
	{
		// ASArray has a different memory layout from ASObject — use arr->props
		ASArray* arr = (ASArray*) obj_var->data.numeric_value;
		if (arr == NULL || arr->props == NULL) return 0;
		obj = arr->props;
	}
	else
	{
		obj = (ASObject*) obj_var->data.numeric_value;
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

			// Check AS2 interface implementation (ImplementsOp stores interface prototypes here).
			// When MyObject implements MyInterface, MyObject.prototype->interfaces[] holds
			// MyInterface.prototype. If ctor_proto == MyInterface.prototype → match.
			for (u32 _iif = 0; _iif < current_proto->interface_count; _iif++)
			{
				if (current_proto->interfaces[_iif] == ctor_proto)
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
		const uint16_t* u16 = (const uint16_t*) VAL(u64, &STACK_TOP_VALUE);
		u32 len = STACK_TOP_N;  // Length is stored at offset +8 (UTF-16 code units)
		u32 id = VAL(u32, &STACK[SP + 12]);  // String ID is at offset +12

		// Push a copy of the string (shallow copy - same pointer, already UTF-16)
		PUSH_U16_ID(u16, len, id);
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

	// Push result as boolean
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result ? 1 : 0);
}

void actionEnumerate2(SWFAppContext* app_context, char* str_buffer)
{
	// Pop object reference from stack
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	// Push undefined as terminator — the for-in loop checks with Equals2 against null,
	// and undefined == null in Equals2. Test expects "undefined" when traced directly.
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);

	// Handle different types
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Object enumeration — push properties directly in forward insertion order.
		// The LIFO stack naturally reverses: for-in pops in reverse insertion order,
		// with prototype properties iterated before own properties (matching Flash).
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj != NULL)
		{
			EnumeratedName* enumerated_head = NULL;

			ASObject* current_obj = obj;
			int chain_depth = 0;
			const int MAX_CHAIN_DEPTH = 100;

			while (current_obj != NULL && chain_depth < MAX_CHAIN_DEPTH)
			{
				chain_depth++;

				for (u32 i = 0; i < current_obj->num_used; i++)
				{
					const char* prop_name = current_obj->properties[i].name;
					u32 prop_name_len = current_obj->properties[i].name_length;
					u8 prop_flags = current_obj->properties[i].flags;

					if (!(prop_flags & PROPERTY_FLAG_ENUMERABLE))
						continue;
					if (isPropertyEnumerated(enumerated_head, prop_name, prop_name_len))
						continue;

					addEnumeratedName(&enumerated_head, prop_name, prop_name_len);
					PUSH_STR((char*)prop_name, prop_name_len);
				}

				// Move to prototype via __proto__
				ActionVar* proto_var = getProperty(current_obj, "__proto__", 9);
				if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
					current_obj = (ASObject*) proto_var->data.numeric_value;
				else
					current_obj = NULL;
			}

			freeEnumeratedNames(enumerated_head);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_ARRAY)
	{
		// Array enumeration — use insertion-ordered enum_keys for Flash-compatible order.
		// Push in forward insertion order; LIFO stack reversal gives reverse-insertion-order iteration.
		ASArray* arr = (ASArray*) obj_var.data.numeric_value;

		if (arr != NULL)
		{
			if (arr->enum_keys != NULL && arr->enum_count > 0)
			{
				// Use tracked insertion order
				for (u32 i = 0; i < arr->enum_count; i++)
				{
					const char* key = arr->enum_keys[i];
					u32 key_len = (u32)strlen(key);

					// Skip __proto__
					if (key_len == 9 && strncmp(key, "__proto__", 9) == 0)
						continue;

					// Verify the key still has a value (not deleted).
					// Try numeric element first, then fall back to named props.
					int found = 0;

					// Check if it's a small numeric index in the elements array
					if (key_len > 0 && key_len <= 10 && key[0] >= '0' && key[0] <= '9')
					{
						int is_num = 1;
						u64 idx_val = 0;
						for (u32 j = 0; j < key_len; j++)
						{
							if (key[j] < '0' || key[j] > '9') { is_num = 0; break; }
							idx_val = idx_val * 10 + (key[j] - '0');
						}
						// Flash treats array length as signed for enumeration:
						// when bit 31 is set (negative signed), no numeric elements are valid.
						if (is_num && (int32_t)arr->length > 0 &&
						    idx_val < arr->length && idx_val < arr->capacity &&
						    arr->elements[(u32)idx_val].type != ACTION_STACK_VALUE_HOLE)
						{
							PUSH_STR((char*)key, key_len);
							found = 1;
						}
					}

					// Fall back to named properties (handles large indices, strings, etc.)
					if (!found && arr->props != NULL)
					{
						ActionVar* pv = getProperty(arr->props, key, key_len);
						if (pv != NULL)
						{
							PUSH_STR((char*)key, key_len);
							found = 1;
						}
					}
				}
			}
			else
			{
				// Fallback: no insertion tracking (e.g. array created without SetMember)
				// Push set array indices in ascending order
				int32_t signed_len = (int32_t) arr->length;
				u32 iter_limit = 0;
				if (signed_len > 0)
					iter_limit = (u32)signed_len < arr->capacity ? (u32)signed_len : arr->capacity;
				for (u32 i = 0; i < iter_limit; i++)
				{
					if (arr->elements[i].type == ACTION_STACK_VALUE_HOLE)
						continue;
					char idx_buf[16];
					snprintf(idx_buf, sizeof(idx_buf), "%u", i);
					u32 len = (u32)strlen(idx_buf);
					PUSH_STR(idx_buf, len);
				}

				// Push non-index properties
				if (arr->props != NULL && arr->props->num_used > 0)
				{
					for (u32 i = 0; i < arr->props->num_used; i++)
					{
						const char* pn = arr->props->properties[i].name;
						u32 pn_len = arr->props->properties[i].name_length;
						if (pn_len == 9 && strncmp(pn, "__proto__", 9) == 0)
							continue;
						if (!(arr->props->properties[i].flags & PROPERTY_FLAG_ENUMERABLE))
							continue;
						PUSH_STR(pn, pn_len);
					}
				}
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		// MovieClip enumeration — child instance names first (bottom of stack),
		// then dynamic_props (top of stack). LIFO pop means dynamic_props iterated first.
		MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;
		if (mc != NULL)
		{
			// Enumerate child MovieClip instance names first (pushed early = popped late)
#ifdef NO_GRAPHICS
			{
				const char* parent_name = (mc == &root_movieclip) ? NULL : mc->name;
				ng_enumerateChildren(parent_name, enum_child_callback, app_context);
			}
#endif

			if (mc->dynamic_props != NULL)
			{
				ASObject* obj = (ASObject*) mc->dynamic_props;
				EnumeratedName* enumerated_head = NULL;

				ASObject* current_obj = obj;
				int chain_depth = 0;
				const int MAX_CHAIN_DEPTH = 100;

				while (current_obj != NULL && chain_depth < MAX_CHAIN_DEPTH)
				{
					chain_depth++;

					for (u32 i = 0; i < current_obj->num_used; i++)
					{
						const char* prop_name = current_obj->properties[i].name;
						u32 prop_name_len = current_obj->properties[i].name_length;
						u8 prop_flags = current_obj->properties[i].flags;

						if (!(prop_flags & PROPERTY_FLAG_ENUMERABLE))
							continue;
						if (isPropertyEnumerated(enumerated_head, prop_name, prop_name_len))
							continue;

						addEnumeratedName(&enumerated_head, prop_name, prop_name_len);
						PUSH_STR((char*)prop_name, prop_name_len);
					}

					ActionVar* proto_var = getProperty(current_obj, "__proto__", 9);
					if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
						current_obj = (ASObject*) proto_var->data.numeric_value;
					else
						current_obj = NULL;
				}

				freeEnumeratedNames(enumerated_head);
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		// Function enumeration — enumerate own_props
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;
		if (func != NULL && func->own_props != NULL)
		{
			ASObject* obj = func->own_props;
			for (u32 i = 0; i < obj->num_used; i++)
			{
				if (!(obj->properties[i].flags & PROPERTY_FLAG_ENUMERABLE))
					continue;
				PUSH_STR((char*)obj->properties[i].name, obj->properties[i].name_length);
			}
		}
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
	double result = (g_swf_version == 8) ? (double)(int32_t)shifted : (double)shifted;
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
				const uint16_t* sa = varGetU16Ptr(&a);
				const uint16_t* sb = varGetU16Ptr(&b);
				result = (u16_cmp(sa, a.str_size, sb, b.str_size) == 0) ? 1.0f : 0.0f;
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
		if (g_swf_version < 6) {
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
		} else {
			// SWF6+: reference equality for object vs object
			u64 bool_val = (a.data.numeric_value == b.data.numeric_value) ? 1 : 0;
			PUSH(ACTION_STACK_VALUE_BOOLEAN, bool_val);
			return;
		}
	}
	else if (a_is_obj)
	{
		// Use out_success to distinguish ToPrimitive failure (valueOf returned `this`)
		// from success returning UNDEFINED (e.g. _global.valueOf = undefined).
		// In SWF8+, ToPrimitive failure + null/undefined comparison → false (CastOp typed catch).
		// In SWF5/6/7, failure falls through: UNDEFINED result → null==undefined → true.
		int a_ok = 1;
		a = objectToPrimitive(app_context, &a, &a_ok);
		if (!a_ok && g_swf_version >= 8 &&
		    (b.type == ACTION_STACK_VALUE_NULL || b.type == ACTION_STACK_VALUE_UNDEFINED))
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
		}
	}
	else if (b_is_obj)
	{
		int b_ok = 1;
		b = objectToPrimitive(app_context, &b, &b_ok);
		if (!b_ok && g_swf_version >= 8 &&
		    (a.type == ACTION_STACK_VALUE_NULL || a.type == ACTION_STACK_VALUE_UNDEFINED))
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
			return;
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
				double a_val = VAL(double, &a.data.numeric_value);
				double b_val = VAL(double, &b.data.numeric_value);
				if (isnan(a_val) || isnan(b_val)) {
					// NaN: raw bit comparison (Flash quirk: NaN == NaN if identical bit pattern)
					result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				} else {
					// Use double comparison so -0.0 == +0.0 (IEEE 754)
					result = (a_val == b_val) ? 1.0f : 0.0f;
				}
				break;
			}

			case ACTION_STACK_VALUE_STRING:
			{
				const uint16_t* sa = varGetU16Ptr(&a);
				const uint16_t* sb = varGetU16Ptr(&b);
				result = (u16_cmp(sa, a.str_size, sb, b.str_size) == 0) ? 1.0f : 0.0f;
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
		char _eq_buf[256];
		const uint16_t* _u16b = varGetU16Ptr(&b);
		if (_u16b && b.str_size > 0) u16_to_utf8(_u16b, b.str_size, _eq_buf, sizeof(_eq_buf));
		else _eq_buf[0] = '\0';
		double b_num = parseStringToNumber(_eq_buf);
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
		char _eq_buf[256];
		const uint16_t* _u16a = varGetU16Ptr(&a);
		if (_u16a && a.str_size > 0) u16_to_utf8(_u16a, a.str_size, _eq_buf, sizeof(_eq_buf));
		else _eq_buf[0] = '\0';
		double a_num = parseStringToNumber(_eq_buf);
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
			char _eq_buf[256];
			const uint16_t* _u16b = varGetU16Ptr(&b);
			if (_u16b && b.str_size > 0) u16_to_utf8(_u16b, b.str_size, _eq_buf, sizeof(_eq_buf));
			else _eq_buf[0] = '\0';
			double b_num2 = parseStringToNumber(_eq_buf);
			if (isnan(b_num2)) {
				result = 0.0f;
			} else {
				result = (a_num == b_num2) ? 1.0f : 0.0f;
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
			char _eq_buf[256];
			const uint16_t* _u16a = varGetU16Ptr(&a);
			if (_u16a && a.str_size > 0) u16_to_utf8(_u16a, a.str_size, _eq_buf, sizeof(_eq_buf));
			else _eq_buf[0] = '\0';
			double a_num2 = parseStringToNumber(_eq_buf);
			if (isnan(a_num2)) {
				result = 0.0f;
			} else {
				result = (a_num2 == b_num) ? 1.0f : 0.0f;
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
			a.str_size = ts_found ? 13 : 15;
			a.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
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
			b.str_size = ts_found ? 13 : 15;
			b.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
		}
	}

	// Convert non-string primitives to strings for comparison
	char buf_a[17], buf_b[17];
	if (a.type != ACTION_STACK_VALUE_STRING) { pushVar(app_context, &a); convertString(app_context, buf_a); popVar(app_context, &a); }
	if (b.type != ACTION_STACK_VALUE_STRING) { pushVar(app_context, &b); convertString(app_context, buf_b); popVar(app_context, &b); }

	const uint16_t* sa = varGetU16Ptr(&a);
	u32 sa_len = a.str_size;
	const uint16_t* sb = varGetU16Ptr(&b);
	u32 sb_len = b.str_size;
	if (sa == NULL) { sa = u16_empty; sa_len = 0; }
	if (sb == NULL) { sb = u16_empty; sb_len = 0; }

	// Compare: b > a
	u64 result = (u16_cmp(sb, sb_len, sa, sa_len) > 0) ? 1 : 0;
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

	if (superclass.data.numeric_value == 0 || subclass.data.numeric_value == 0)
	{
#ifdef DEBUG
		printf("[DEBUG] actionExtends: NULL constructor\n");
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

	// Get superclass prototype — handle ASFunction vs ASObject
	ASObject* super_proto = NULL;
	if (superclass.type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* super_func = (ASFunction*) superclass.data.numeric_value;
		// Lazily create prototype if needed (same pattern as actionGetMember)
		if (super_func->prototype_obj == NULL)
		{
			super_func->prototype_obj = allocObject(app_context, 4);
			retainObject(super_func->prototype_obj);
			setObjectProto(app_context, super_func->prototype_obj);
			ActionVar ctor_var;
			ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
			ctor_var.str_size = 0;
			ctor_var.data.numeric_value = (u64) super_func;
			setProperty(app_context, super_func->prototype_obj, "constructor", 11, &ctor_var);
		}
		super_proto = super_func->prototype_obj;
	}
	else
	{
		ASObject* super_obj = (ASObject*) superclass.data.numeric_value;
		ActionVar* super_proto_var = getProperty(super_obj, "prototype", 9);
		if (super_proto_var != NULL && (super_proto_var->type == ACTION_STACK_VALUE_OBJECT ||
		    super_proto_var->type == ACTION_STACK_VALUE_ARRAY))
		{
			super_proto = (ASObject*) super_proto_var->data.numeric_value;
		}
	}

	// Set __proto__ of new prototype to superclass prototype
	if (super_proto != NULL)
	{
		ActionVar proto_var;
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.str_size = 0;
		proto_var.data.numeric_value = (u64) super_proto;
		setProperty(app_context, new_proto, "__proto__", 9, &proto_var);
	}

	// Set constructor property to superclass
	setProperty(app_context, new_proto, "constructor", 11, &superclass);

#ifdef DEBUG
	printf("[DEBUG] actionExtends: Set constructor property - type=%d, ptr=%p\n",
		superclass.type, (void*)superclass.data.numeric_value);
#endif

	// Set subclass prototype to new object — handle ASFunction vs ASObject
	if (subclass.type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* sub_func = (ASFunction*) subclass.data.numeric_value;
		retainObject(new_proto);
		if (sub_func->prototype_obj != NULL)
			releaseObject(app_context, sub_func->prototype_obj);
		sub_func->prototype_obj = new_proto;
	}
	else
	{
		ActionVar new_proto_var;
		new_proto_var.type = ACTION_STACK_VALUE_OBJECT;
		new_proto_var.data.numeric_value = (u64) new_proto;
		new_proto_var.str_size = 0;
		setProperty(app_context, (ASObject*) subclass.data.numeric_value, "prototype", 9, &new_proto_var);
	}

	// Release our reference to new_proto
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
	pushVar(app_context, reg);
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
			a.type = ACTION_STACK_VALUE_STRING;
			a.str_size = ts_found ? 13 : 15;
			a.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
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
			b.str_size = ts_found ? 13 : 15;
			b.data.numeric_value = (u64)(ts_found ? u16_type_Object : u16_object_Object);
		}
	}

	// Convert non-string primitives to strings for comparison
	char buf_a[17], buf_b[17];
	if (a.type != ACTION_STACK_VALUE_STRING) { pushVar(app_context, &a); convertString(app_context, buf_a); popVar(app_context, &a); }
	if (b.type != ACTION_STACK_VALUE_STRING) { pushVar(app_context, &b); convertString(app_context, buf_b); popVar(app_context, &b); }

	const uint16_t* sa = varGetU16Ptr(&a);
	u32 sa_len = a.str_size;
	const uint16_t* sb = varGetU16Ptr(&b);
	u32 sb_len = b.str_size;
	if (sa == NULL) { sa = u16_empty; sa_len = 0; }
	if (sb == NULL) { sb = u16_empty; sb_len = 0; }

	// Compare: b < a
	u64 result = (u16_cmp(sb, sb_len, sa, sa_len) < 0) ? 1 : 0;
	PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
}

void actionImplementsOp(SWFAppContext* app_context)
{
	// ActionImplementsOp implements the ActionScript "implements" keyword
	// It specifies the interfaces that a class implements, for use by instanceof and CastOp

	// Step 1: Pop constructor function (the class) from stack
	ActionVar constructor_var;
	popVar(app_context, &constructor_var);

	// Get the constructor's prototype where the interface list will be stored.
	// The constructor is typically a FUNCTION (ASFunction); we store interfaces on its
	// prototype_obj so that instanceof can find them when walking the __proto__ chain.
	ASObject* constructor_proto = NULL;
	if (constructor_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* ctor_func = (ASFunction*) constructor_var.data.numeric_value;
		if (ctor_func != NULL)
		{
			if (ctor_func->prototype_obj == NULL)
			{
				ctor_func->prototype_obj = allocObject(app_context, 4);
				retainObject(ctor_func->prototype_obj);
				setObjectProto(app_context, ctor_func->prototype_obj);
			}
			constructor_proto = ctor_func->prototype_obj;
		}
	}
	else if (constructor_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* ctor_obj = (ASObject*) constructor_var.data.numeric_value;
		ActionVar* proto_var = getProperty(ctor_obj, "prototype", 9);
		if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
			constructor_proto = (ASObject*) proto_var->data.numeric_value;
	}
	else
	{
		fprintf(stderr, "ERROR: actionImplementsOp - constructor is not a function or object\n");
		return;
	}

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

		// Pop each interface constructor from stack and extract its prototype.
		// Interfaces are pushed in order, so we pop them in reverse.
		// We store prototype objects (not constructors) so instanceof can match by proto.
		for (u32 i = 0; i < interface_count; i++)
		{
			ActionVar iface_var;
			popVar(app_context, &iface_var);

			ASObject* iface_proto = NULL;
			if (iface_var.type == ACTION_STACK_VALUE_FUNCTION)
			{
				ASFunction* iface_func = (ASFunction*) iface_var.data.numeric_value;
				if (iface_func != NULL)
				{
					if (iface_func->prototype_obj == NULL)
					{
						iface_func->prototype_obj = allocObject(app_context, 4);
						retainObject(iface_func->prototype_obj);
						setObjectProto(app_context, iface_func->prototype_obj);
					}
					iface_proto = iface_func->prototype_obj;
				}
			}
			else if (iface_var.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* iface_obj = (ASObject*) iface_var.data.numeric_value;
				ActionVar* proto_var = getProperty(iface_obj, "prototype", 9);
				if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_OBJECT)
					iface_proto = (ASObject*) proto_var->data.numeric_value;
			}

			if (iface_proto == NULL)
			{
				fprintf(stderr, "ERROR: actionImplementsOp - interface %u has no prototype\n", i);
				for (u32 j = 0; j < i; j++)
					releaseObject(app_context, interfaces[j]);
				free(interfaces);
				return;
			}

			// Store in reverse order (last popped goes first)
			interfaces[interface_count - 1 - i] = iface_proto;
		}
	}

	// Step 4: Store interface prototype list on the constructor's prototype.
	// When instanceof walks obj.__proto__ chain, it finds this prototype and checks interfaces[].
	setInterfaceList(app_context, constructor_proto, interfaces, interface_count);

#ifdef DEBUG
	printf("[DEBUG] actionImplementsOp: constructor_proto=%p, interface_count=%u\n",
		(void*)constructor_proto, interface_count);
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
		char _ac_buf[256];
		const uint16_t* _ac_u16 = varGetU16Ptr(&frame_var);
		if (_ac_u16 && frame_var.str_size > 0)
			u16_to_utf8(_ac_u16, frame_var.str_size, _ac_buf, sizeof(_ac_buf));
		else
			_ac_buf[0] = '\0';
		const char* frame_str = _ac_buf;

		if (frame_str[0] == '\0') {
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

// Helper function to print a string value (UTF-16 → UTF-8 for output)
static void printStringValue(ActionVar* var)
{
	if (var->type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* u16 = varGetU16Ptr(var);
		if (u16 != NULL && var->str_size > 0) {
			char utf8_buf[4096];
			int utf8_len = u16_to_utf8(u16, var->str_size, utf8_buf, sizeof(utf8_buf));
			fwrite(utf8_buf, 1, utf8_len, stdout);
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

	// Handle FSCommand: protocol (e.g. fscommand("quit", ""))
	// The URL is "FSCommand:<command>"; handle silently without printing.
	if (url_var.type == ACTION_STACK_VALUE_STRING && url_var.str_size >= 10) {
		char url_utf8[512];
		const uint16_t* url_u16 = varGetU16Ptr(&url_var);
		u16_to_utf8(url_u16, url_var.str_size, url_utf8, sizeof(url_utf8));
		if (strncasecmp(url_utf8, "FSCommand:", 10) == 0) {
			const char* cmd = url_utf8 + 10;
			if (strcasecmp(cmd, "quit") == 0) {
				extern int quit_swf;
				quit_swf = 1;
			}
			return;
		}
	}

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

	// Check raw double value against stack before u32 conversion — Flash pushes undefined on overflow
	double raw_count = varToDouble(&count_var);
	u32 stack_entries = (INITIAL_STACK_SIZE - SP) / 24;
	if (raw_count < 0 || raw_count > (double) stack_entries)
	{
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

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
		static char _sm_buf[512];
		prop_name_len = (u32)u16_to_utf8((const uint16_t*)prop_name_var.data.numeric_value, prop_name_var.str_size, _sm_buf, sizeof(_sm_buf));
		prop_name = _sm_buf;
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
	else if (prop_name_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Object used as property name - coerce to string via toString
		ActionVar str_result = objectCallToString(app_context, &prop_name_var, NULL);
		if (str_result.type == ACTION_STACK_VALUE_STRING)
		{
			static char _sm_ts_buf[512];
			prop_name_len = (u32)u16_to_utf8((const uint16_t*)str_result.data.numeric_value, str_result.str_size, _sm_ts_buf, sizeof(_sm_ts_buf));
			prop_name = _sm_ts_buf;
		}
		else
		{
			// toString didn't return a string - fall back to "[type Object]"
			prop_name = "[type Object]";
			prop_name_len = 13;
		}
	}
	else if (prop_name_var.type == ACTION_STACK_VALUE_BOOLEAN)
	{
		prop_name = prop_name_var.data.numeric_value ? "true" : "false";
		prop_name_len = prop_name_var.data.numeric_value ? 4 : 5;
	}
	else if (prop_name_var.type == ACTION_STACK_VALUE_NULL)
	{
		prop_name = "null";
		prop_name_len = 4;
	}
	else if (prop_name_var.type == ACTION_STACK_VALUE_UNDEFINED)
	{
		if (EFFECTIVE_SWF_VERSION() >= 7) {
			prop_name = "undefined";
			prop_name_len = 9;
		} else {
			prop_name = "";
			prop_name_len = 0;
		}
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
			// Bare TextField instances (from new TextField()) reject sets on native properties
			if (isTextFieldInstance(obj) && isNativeTextFieldProperty(prop_name, prop_name_len))
			{
				return;
			}
			// TextFormat instances apply per-property coercion
			if (isTextFormatInstance(obj) && textFormatSetProperty(app_context, obj, prop_name, prop_name_len, &value_var))
			{
				return;
			}
			// Rectangle computed property setters
			if (g_rect_prototype != NULL) {
				ActionVar* __rp = getProperty(obj, "__proto__", 9);
				if (__rp && __rp->type == ACTION_STACK_VALUE_OBJECT &&
				    (ASObject*)__rp->data.numeric_value == g_rect_prototype) {
					int rect_handled = 0;
					if (prop_name_len == 4 && memcmp(prop_name, "left", 4) == 0) {
						// left setter: width = (x + width) - new_left; x = new_left
						double old_right = varToDoubleSimple(getProperty(obj, "x", 1)) +
						                   varToDoubleSimple(getProperty(obj, "width", 5));
						double new_left = varToDoubleSimple(&value_var);
						ActionVar nw = makeF64(old_right - new_left);
						setProperty(app_context, obj, "width", 5, &nw);
						setProperty(app_context, obj, "x", 1, &value_var);
						rect_handled = 1;
					} else if (prop_name_len == 3 && memcmp(prop_name, "top", 3) == 0) {
						double old_bottom = varToDoubleSimple(getProperty(obj, "y", 1)) +
						                    varToDoubleSimple(getProperty(obj, "height", 6));
						double new_top = varToDoubleSimple(&value_var);
						ActionVar nh = makeF64(old_bottom - new_top);
						setProperty(app_context, obj, "height", 6, &nh);
						setProperty(app_context, obj, "y", 1, &value_var);
						rect_handled = 1;
					} else if (prop_name_len == 5 && memcmp(prop_name, "right", 5) == 0) {
						double x = varToDoubleSimple(getProperty(obj, "x", 1));
						double new_right = varToDoubleSimple(&value_var);
						ActionVar nw = makeF64(new_right - x);
						setProperty(app_context, obj, "width", 5, &nw);
						rect_handled = 1;
					} else if (prop_name_len == 6 && memcmp(prop_name, "bottom", 6) == 0) {
						double y = varToDoubleSimple(getProperty(obj, "y", 1));
						double new_bottom = varToDoubleSimple(&value_var);
						ActionVar nh = makeF64(new_bottom - y);
						setProperty(app_context, obj, "height", 6, &nh);
						rect_handled = 1;
					} else if (prop_name_len == 7 && memcmp(prop_name, "topLeft", 7) == 0) {
						// topLeft setter: read pt.x, pt.y from value, then set left and top
						ActionVar* ptx = NULL; ActionVar* pty = NULL;
						if (value_var.type == ACTION_STACK_VALUE_OBJECT && value_var.data.numeric_value != 0) {
							ASObject* pt = (ASObject*)value_var.data.numeric_value;
							ptx = getProperty(pt, "x", 1);
							pty = getProperty(pt, "y", 1);
						}
						// Set left (adjusts width)
						double old_right = varToDoubleSimple(getProperty(obj, "x", 1)) +
						                   varToDoubleSimple(getProperty(obj, "width", 5));
						double new_left = ptx ? varToDoubleSimple(ptx) : NAN;
						ActionVar nw = makeF64(old_right - new_left);
						setProperty(app_context, obj, "width", 5, &nw);
						if (ptx) setProperty(app_context, obj, "x", 1, ptx);
						else { ActionVar uv = {0}; uv.type = ACTION_STACK_VALUE_UNDEFINED; setProperty(app_context, obj, "x", 1, &uv); }
						// Set top (adjusts height)
						double old_bottom = varToDoubleSimple(getProperty(obj, "y", 1)) +
						                    varToDoubleSimple(getProperty(obj, "height", 6));
						double new_top = pty ? varToDoubleSimple(pty) : NAN;
						ActionVar nh = makeF64(old_bottom - new_top);
						setProperty(app_context, obj, "height", 6, &nh);
						if (pty) setProperty(app_context, obj, "y", 1, pty);
						else { ActionVar uv = {0}; uv.type = ACTION_STACK_VALUE_UNDEFINED; setProperty(app_context, obj, "y", 1, &uv); }
						rect_handled = 1;
					} else if (prop_name_len == 11 && memcmp(prop_name, "bottomRight", 11) == 0) {
						ActionVar* ptx = NULL; ActionVar* pty = NULL;
						if (value_var.type == ACTION_STACK_VALUE_OBJECT && value_var.data.numeric_value != 0) {
							ASObject* pt = (ASObject*)value_var.data.numeric_value;
							ptx = getProperty(pt, "x", 1);
							pty = getProperty(pt, "y", 1);
						}
						// right = pt.x → width = pt.x - x
						double x = varToDoubleSimple(getProperty(obj, "x", 1));
						ActionVar nw = makeF64((ptx ? varToDoubleSimple(ptx) : NAN) - x);
						setProperty(app_context, obj, "width", 5, &nw);
						// bottom = pt.y → height = pt.y - y
						double y = varToDoubleSimple(getProperty(obj, "y", 1));
						ActionVar nh = makeF64((pty ? varToDoubleSimple(pty) : NAN) - y);
						setProperty(app_context, obj, "height", 6, &nh);
						rect_handled = 1;
					} else if (prop_name_len == 4 && memcmp(prop_name, "size", 4) == 0) {
						ActionVar* ptx = NULL; ActionVar* pty = NULL;
						if (value_var.type == ACTION_STACK_VALUE_OBJECT && value_var.data.numeric_value != 0) {
							ASObject* pt = (ASObject*)value_var.data.numeric_value;
							ptx = getProperty(pt, "x", 1);
							pty = getProperty(pt, "y", 1);
						}
						// width = pt.x, height = pt.y
						if (ptx) setProperty(app_context, obj, "width", 5, ptx);
						else { ActionVar uv = {0}; uv.type = ACTION_STACK_VALUE_UNDEFINED; setProperty(app_context, obj, "width", 5, &uv); }
						if (pty) setProperty(app_context, obj, "height", 6, pty);
						else { ActionVar uv = {0}; uv.type = ACTION_STACK_VALUE_UNDEFINED; setProperty(app_context, obj, "height", 6, &uv); }
						rect_handled = 1;
					}
					if (rect_handled) return;
				}
			}
			// Check watcher table before setting the property
			// IMPORTANT: prop_name points to a static buffer (_sm_buf) that recursive
			// actionSetMember calls (from inside the watcher callback) will clobber.
			// Copy it to a local stack buffer so the watcher invocation can't corrupt it.
			char _prop_copy[256];
			{
				u32 _prop_copy_len = prop_name_len < (u32)(sizeof(_prop_copy)-1) ? prop_name_len : (u32)(sizeof(_prop_copy)-1);
				memcpy(_prop_copy, prop_name, _prop_copy_len);
				_prop_copy[_prop_copy_len] = '\0';
				prop_name = _prop_copy;
				prop_name_len = _prop_copy_len;
			}
			if (g_watch_count > 0 && !g_execution_halted)
			{
				for (int _wi = 0; _wi < g_watch_count; _wi++)
				{
					if (g_watch_table[_wi].obj == obj &&
					    g_watch_table[_wi].prop_name_len == prop_name_len &&
					    strncmp(g_watch_table[_wi].prop_name, prop_name, prop_name_len) == 0)
					{
						ASFunction* _wf = g_watch_table[_wi].watcher_func;
						if (_wf != NULL)
						{
							if (_wf->function_type == 2 && _wf->advanced_func != NULL)
							{
								// Build prop_name string arg
								u32 _pname_u16_len;
								uint16_t* _pname_u16 = ascii_to_u16(app_context, prop_name, (int)prop_name_len, &_pname_u16_len);
								ActionVar _pname_arg = {0};
								_pname_arg.type = ACTION_STACK_VALUE_STRING;
								_pname_arg.str_size = _pname_u16_len;
								_pname_arg.data.string_data.heap_ptr = _pname_u16;
								_pname_arg.data.string_data.owns_memory = true;
								// Get old value via prototype chain (Flash includes inherited values)
								ActionVar _old_val = {0};
								_old_val.type = ACTION_STACK_VALUE_UNDEFINED;
								ActionVar* _old_ptr = getPropertyWithPrototype(obj, prop_name, prop_name_len);
								if (_old_ptr != NULL) _old_val = *_old_ptr;
								// Pass 4 args: (propName, oldVal, newVal, userData)
								ActionVar _wargs[4] = { _pname_arg, _old_val, value_var, g_watch_table[_wi].user_data };
								ActionVar* _wregs = NULL;
								if (_wf->register_count > 0)
									_wregs = (ActionVar*) HCALLOC(_wf->register_count, sizeof(ActionVar));
								ASObject* _wscope = allocObject(app_context, 4);
								if (scope_depth < MAX_SCOPE_DEPTH) {
									scope_is_with[scope_depth] = 0;
									scope_mc[scope_depth] = NULL;
									scope_chain[scope_depth++] = _wscope;
								}
								g_call_depth++;
								// Pass watched object as this_obj for correct this binding
								ActionVar _wret = _wf->advanced_func(app_context, _wargs, 4, _wregs, (void*)obj);
								g_call_depth--;
								if (scope_depth > 0) scope_depth--;
								releaseObject(app_context, _wscope);
								if (_wregs != NULL) FREE(_wregs);
								if (_pname_arg.data.string_data.owns_memory)
									FREE(_pname_arg.data.string_data.heap_ptr);
								if (_wret.type != ACTION_STACK_VALUE_UNDEFINED)
									value_var = _wret;
							}
							else if (_wf->function_type == 1 && _wf->simple_func != NULL)
							{
								// Type 1: call without args (args ignored by watcher body)
								g_call_depth++;
								ActionVar _wret = ((ActionVar(*)(SWFAppContext*))_wf->simple_func)(app_context);
								g_call_depth--;
								if (_wret.type != ACTION_STACK_VALUE_UNDEFINED)
									value_var = _wret;
							}
						}
						break;
					}
				}
			}
			// Check prototype chain for addProperty setter before creating own property
			{
				ASProperty* setter_prop = findPropertyStructWithPrototype(obj, prop_name, prop_name_len);
				if (setter_prop != NULL && (setter_prop->getter != NULL || setter_prop->setter != NULL))
				{
					// Virtual property (addProperty): has getter and/or setter
					if (setter_prop->setter != NULL)
					{
						// Invoke setter with this = original obj
						invokePropertySetter(app_context, (ASFunction*)setter_prop->setter, (void*)obj, &value_var);
					}
					// If no setter (read-only virtual property) — silently ignore the assignment
					return;
				}
			}
			// Check WRITABLE flag — if property exists on prototype chain but is read-only, skip
			{
				ASProperty* wp = findPropertyStructWithPrototype(obj, prop_name, prop_name_len);
				if (wp != NULL && !(wp->flags & PROPERTY_FLAG_WRITABLE))
				{
					return;  // Read-only property — silently ignore
				}
			}
			// XML nodeName: setting to non-string is a no-op (Flash behavior)
			if (prop_name_len == 8 && memcmp(prop_name, "nodeName", 8) == 0 &&
			    value_var.type != ACTION_STACK_VALUE_STRING)
			{
				ActionVar* nt = getProperty(obj, "nodeType", 8);
				if (nt != NULL)
					return;
			}
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
				// Flash AS2: length is stored as signed 32-bit
				double dval = 0;
				if (value_var.type == ACTION_STACK_VALUE_F32)
					dval = (double) VAL(float, &value_var.data.numeric_value);
				else if (value_var.type == ACTION_STACK_VALUE_F64)
					dval = VAL(double, &value_var.data.numeric_value);

				u32 new_len = (u32) ecmaToInt32(dval);

				// Truncation: mark elements beyond new_len as HOLE
				if (new_len < arr->length)
				{
					u32 cap_limit = new_len < arr->capacity ? arr->capacity : new_len;
					for (u32 i = new_len; i < cap_limit && i < arr->length; i++)
					{
						arr->elements[i].type = ACTION_STACK_VALUE_HOLE;
						arr->elements[i].data.numeric_value = 0;
						arr->elements[i].str_size = 0;
					}
				}

				// Extension: only allocate if new_len is reasonable (< 1M)
				// and greater than current capacity
				if (new_len > arr->capacity && (int32_t)new_len > 0 && new_len < 1048576)
				{
					u32 new_cap = new_len * 2;
					ActionVar* new_elems = (ActionVar*) realloc(arr->elements, sizeof(ActionVar) * new_cap);
					if (new_elems != NULL)
					{
						arr->elements = new_elems;
						for (u32 i = arr->capacity; i < new_cap; i++)
						{
							arr->elements[i].type = ACTION_STACK_VALUE_HOLE;
							arr->elements[i].data.numeric_value = 0;
							arr->elements[i].str_size = 0;
						}
						arr->capacity = new_cap;
					}
				}

				arr->length = new_len;
			}
			else
			{
				// Parse property name as numeric index
				char* endptr;
				errno = 0;
				long long index_ll = strtoll(prop_name, &endptr, 10);
				int strtoll_overflow = (errno == ERANGE);
				int is_standard_index = (*endptr == '\0' && !strtoll_overflow && index_ll >= 0 && index_ll <= 2147483647LL);

				// Determine u32 index via ecmaToUint32 for extended indices
				u32 idx_u32 = 0;
				int has_index = 0;

				if (is_standard_index)
				{
					idx_u32 = (u32) index_ll;
					has_index = 1;
				}
				else
				{
					// Try as double → ecmaToUint32
					double d = strtod(prop_name, &endptr);
					if (*endptr == '\0' && !isnan(d) && !isinf(d))
					{
						idx_u32 = ecmaToUint32(d);
						has_index = 1;
					}
				}

				// Store the value
				if (is_standard_index)
				{
					// Standard index: store in elements array or as string prop
					if (idx_u32 < 1048576 || idx_u32 < arr->capacity)
					{
						setArrayElement(app_context, arr, idx_u32, &value_var);
					}
					else
					{
						if (arr->props == NULL)
						{
							arr->props = allocObject(app_context, 4);
							retainObject(arr->props);
						}
						setProperty(app_context, arr->props, prop_name, prop_name_len, &value_var);
						arrayTrackKey(arr, prop_name, prop_name_len);
					}
				}
				else if (prop_name_len > 0)
				{
					// Extended/non-index: always store as string property
					if (arr->props == NULL)
					{
						arr->props = allocObject(app_context, 4);
						retainObject(arr->props);
					}
					setProperty(app_context, arr->props, prop_name, prop_name_len, &value_var);
					arrayTrackKey(arr, prop_name, prop_name_len);
				}

				// Update length
				// Flash AS2 array length semantics:
				// - When length <= INT_MAX: only standard indices (0..INT_MAX)
				//   update length, using unsigned comparison
				// - When length > INT_MAX (overflow region): all numeric indices
				//   update length, using signed i32 comparison
				// - When strtoll overflows (ERANGE): use ecmaToUint32 directly
				//   as new length (not +1), unsigned comparison
				if (has_index)
				{
					u32 new_len = idx_u32 + 1;  // u32 wrapping
					if (arr->length <= 2147483647u)
					{
						if (strtoll_overflow && idx_u32 > arr->length)
							arr->length = idx_u32;
						else if (idx_u32 <= 2147483647u && new_len > arr->length)
							arr->length = new_len;
					}
					else
					{
						// Overflow region: signed comparison for all indices
						if ((int32_t)new_len > (int32_t)arr->length)
							arr->length = new_len;
					}
				}
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;
		if (func != NULL && prop_name_len == 9 && strncmp(prop_name, "prototype", 9) == 0)
		{
			// Setting func.prototype = value
			if (value_var.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* new_proto = (ASObject*) value_var.data.numeric_value;
				if (new_proto != NULL)
				{
					retainObject(new_proto);
					// Release old prototype if any
					if (func->prototype_obj != NULL)
						releaseObject(app_context, func->prototype_obj);
					func->prototype_obj = new_proto;
				}
			}
		}
		else if (func != NULL)
		{
			// Store arbitrary properties on the function's own_props object
			if (func->own_props == NULL)
			{
				func->own_props = allocObject(app_context, 4);
				retainObject(func->own_props);
			}
			setProperty(app_context, func->own_props, prop_name, prop_name_len, &value_var);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;
		if (mc != NULL)
		{
			// Handle built-in writable properties
			if (prop_name_len > 0 && prop_name[0] == '_')
			{
				// Use proper numeric conversion (varToDoubleSimple handles string/boolean/null/undefined)
				double dval = varToDoubleSimple(&value_var);
				float fval = (float)dval;
				// For numeric MC properties: undefined/null/NaN → no-op (Flash ignores invalid values)
				int dval_invalid = isnan(dval) ||
				    value_var.type == ACTION_STACK_VALUE_NULL ||
				    value_var.type == ACTION_STACK_VALUE_UNDEFINED;
				if (strcasecmp(prop_name, "_x") == 0) {
					if (dval_invalid) return;
#ifdef NO_GRAPHICS
					mc->as_set_flags |= 1;
#endif
					mc->x = fval; return;
				}
				if (strcasecmp(prop_name, "_y") == 0) {
					if (dval_invalid) return;
#ifdef NO_GRAPHICS
					mc->as_set_flags |= 2;
#endif
					mc->y = fval; return;
				}
				if (strcasecmp(prop_name, "_xscale") == 0) {
					if (dval_invalid) return;
#ifdef NO_GRAPHICS
					mc->as_set_flags |= 4;
#endif
					mc->xscale = fval; return;
				}
				if (strcasecmp(prop_name, "_yscale") == 0) {
					if (dval_invalid) return;
#ifdef NO_GRAPHICS
					mc->as_set_flags |= 8;
#endif
					mc->yscale = fval; return;
				}
				if (strcasecmp(prop_name, "_rotation") == 0) {
					if (dval_invalid) return;
#ifdef NO_GRAPHICS
					mc->as_set_flags |= 16;
#endif
					mc->rotation = normalizeRotation(fval); return;
				}
				if (strcasecmp(prop_name, "_alpha") == 0) {
					if (dval_invalid) return;
					mc->alpha = fval; return;
				}
				if (strcasecmp(prop_name, "_visible") == 0) {
					// _visible conversion: use convertFloat (SWF-version-aware for null/undefined).
					// For objects: try valueOf; if valueOf returns OBJECT (not primitive) → treat as 0 (false).
					// This matches Flash Player AVM1 behavior.
					double vis_d;
					if (value_var.type == ACTION_STACK_VALUE_OBJECT ||
					    value_var.type == ACTION_STACK_VALUE_ARRAY) {
						ASObject* obj2 = (ASObject*)value_var.data.numeric_value;
						vis_d = 0.0;  // default: object with no primitive valueOf → false
						if (obj2 != NULL) {
							ActionVar* vof2 = getPropertyWithPrototype(obj2, "valueOf", 7);
							if (vof2 != NULL && vof2->type == ACTION_STACK_VALUE_FUNCTION) {
								ASFunction* func2 = lookupFunctionFromVar(vof2);
								if (func2 != NULL) {
									ActionVar* regs2 = (func2->register_count > 0) ?
									    (ActionVar*)HCALLOC(func2->register_count, sizeof(ActionVar)) : NULL;
									ActionVar vr;
									if (func2->function_type == 2 && func2->advanced_func != NULL)
										vr = func2->advanced_func(app_context, NULL, 0, regs2, obj2);
									else if (func2->function_type == 1 && func2->simple_func != NULL)
										vr = ((ActionVar(*)(SWFAppContext*))func2->simple_func)(app_context);
									else { vr.type = ACTION_STACK_VALUE_UNDEFINED; vr.data.numeric_value = 0; }
									if (regs2 != NULL) FREE(regs2);
									// If valueOf returned a non-object primitive → convert to number
									if (vr.type != ACTION_STACK_VALUE_OBJECT &&
									    vr.type != ACTION_STACK_VALUE_ARRAY &&
									    vr.type != ACTION_STACK_VALUE_FUNCTION) {
										pushVar(app_context, &vr);
										convertFloat(app_context);
										ActionVar cv; popVar(app_context, &cv);
										vis_d = VAL(double, &cv.data.numeric_value);
									}
									// else: valueOf returned OBJECT → vis_d stays 0.0 (false)
								}
							}
						}
					} else {
						// For all other types (undefined/null/NaN/string/boolean/F32/F64):
						// use convertFloat which is SWF-version-aware (null/undefined → NaN in SWF>=7)
						pushVar(app_context, &value_var);
						convertFloat(app_context);
						ActionVar cv; popVar(app_context, &cv);
						vis_d = VAL(double, &cv.data.numeric_value);
					}
					mc->visible = (vis_d != 0.0) ? 1 : 0;
					return;
				}
				if (strcasecmp(prop_name, "_width") == 0) { mcSetEffectiveWidth(app_context, mc, (double)fval); return; }
				if (strcasecmp(prop_name, "_height") == 0) { mcSetEffectiveHeight(app_context, mc, (double)fval); return; }
				if (strcasecmp(prop_name, "_quality") == 0)
				{
					char buf[16];
					int len = varToStringBuf(app_context, &value_var, buf, sizeof(buf));
					if (len > 0) { memcpy(mc->quality, buf, len); mc->quality[len] = '\0'; }
					return;
				}
				if (strcasecmp(prop_name, "_highquality") == 0) { mc->highquality = fval; return; }
				if (strcasecmp(prop_name, "_focusrect") == 0) {
					// null/undefined → sentinel -1.0f (null); otherwise store numeric
					if (value_var.type == ACTION_STACK_VALUE_NULL || value_var.type == ACTION_STACK_VALUE_UNDEFINED) {
						mc->focusrect = -1.0f;
					} else {
						mc->focusrect = fval;
					}
					return;
				}
				if (strcasecmp(prop_name, "_soundbuftime") == 0) { mc->soundbuftime = fval; return; }
				if (strcasecmp(prop_name, "_lockroot") == 0) {
					// Coerce to boolean: non-zero numbers, non-empty strings → true
					if (value_var.type == ACTION_STACK_VALUE_BOOLEAN) {
						mc->lockroot = value_var.data.numeric_value ? 1 : 0;
					} else if (value_var.type == ACTION_STACK_VALUE_NULL || value_var.type == ACTION_STACK_VALUE_UNDEFINED) {
						mc->lockroot = 0;
					} else if (value_var.type == ACTION_STACK_VALUE_STRING) {
						mc->lockroot = (value_var.str_size > 0) ? 1 : 0;
					} else {
						mc->lockroot = (!isnan(fval) && fval != 0.0f) ? 1 : 0;
					}
					return;
				}
				if (strcasecmp(prop_name, "_name") == 0)
				{
					char new_name[256];
					int len = varToStringBuf(app_context, &value_var, new_name, sizeof(new_name));
					if (len > 0)
					{
#ifdef NO_GRAPHICS
						extern void ng_renameDisplayEntry(const char* old_name, const char* new_name);
						ng_renameDisplayEntry(mc->name, new_name);
#endif
						strncpy(mc->name, new_name, sizeof(mc->name) - 1);
						mc->name[sizeof(mc->name) - 1] = '\0';
						if (mc->parent != NULL)
						{
							if (mc->parent->target[0] == '/' && mc->parent->target[1] == '\0')
								snprintf(mc->target, sizeof(mc->target), "/%s", new_name);
							else if (mc->parent->target[0] != '\0')
								snprintf(mc->target, sizeof(mc->target), "%s/%s", mc->parent->target, new_name);
							else
								snprintf(mc->target, sizeof(mc->target), "/%s", new_name);
						}
					}
					return;
				}
			}
			// blendMode setter: accepts string name or numeric index
			if (prop_name_len == 9 && strncmp(prop_name, "blendMode", 9) == 0)
			{
				static const char* blend_mode_names[] = {
					"normal", "layer", "multiply", "screen", "lighten",
					"darken", "difference", "add", "subtract", "invert",
					"alpha", "erase", "overlay", "hardlight"
				};
				if (value_var.type == ACTION_STACK_VALUE_NULL || value_var.type == ACTION_STACK_VALUE_UNDEFINED) {
					mc->blend_mode = 0; // "normal"
				} else if (value_var.type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _bm_u16 = varGetU16Ptr(&value_var);
					char _bm_buf[64];
					if (_bm_u16 && value_var.str_size > 0)
						u16_to_utf8(_bm_u16, value_var.str_size, _bm_buf, sizeof(_bm_buf));
					else
						_bm_buf[0] = '\0';
					const char* s = _bm_buf;
					if (s[0] != '\0') {
						int found = 0;
						for (int i = 0; i < 14; i++) {
							if (strcmp(s, blend_mode_names[i]) == 0) {
								mc->blend_mode = (u8)(i + 1);
								found = 1;
								break;
							}
						}
						// Invalid string: keep previous value (do nothing)
						(void)found;
					}
				} else if (value_var.type == ACTION_STACK_VALUE_F64 || value_var.type == ACTION_STACK_VALUE_F32) {
					// Numeric: truncate to byte, check valid range
					double d = varToDouble(&value_var);
					int idx = (int)d & 0xFF;
					if (idx >= 0 && idx <= 14) {
						mc->blend_mode = (u8)idx;
					}
					// Out of range after byte truncation: keep previous value
				}
				// All other types (boolean, object, movieclip, etc.): keep previous value
				return;
			}
			// _lockroot setter via non-underscore name (some tests use "lockroot" without underscore on dynamic_props)
			// TextField type setter: normalize to lowercase, reject invalid values
			if (prop_name_len == 4 && strncmp(prop_name, "type", 4) == 0
				&& mc->ng_textfield_idx >= 0)
			{
				if (value_var.type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _ty_u16 = varGetU16Ptr(&value_var);
					char _ty_buf[64];
					if (_ty_u16 && value_var.str_size > 0)
						u16_to_utf8(_ty_u16, value_var.str_size, _ty_buf, sizeof(_ty_buf));
					else
						_ty_buf[0] = '\0';
					if (_ty_buf[0] != '\0') {
						if (strcasecmp(_ty_buf, "dynamic") == 0) {
							value_var.data.numeric_value = (u64)u16_dynamic;
							value_var.data.string_data.owns_memory = false;
							value_var.str_size = 7;
						} else if (strcasecmp(_ty_buf, "input") == 0) {
							value_var.data.numeric_value = (u64)u16_input;
							value_var.data.string_data.owns_memory = false;
							value_var.str_size = 5;
						} else {
							// Invalid value: silently reject (keep previous)
							return;
						}
					}
				} else {
					// Non-string: reject
					return;
				}
			}
			// TextField antiAliasType setter: validate
			if (prop_name_len == 13 && strncmp(prop_name, "antiAliasType", 13) == 0
				&& mc->ng_textfield_idx >= 0)
			{
				if (value_var.type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _aa_u16 = varGetU16Ptr(&value_var);
					char _aa_buf[64];
					if (_aa_u16 && value_var.str_size > 0)
						u16_to_utf8(_aa_u16, value_var.str_size, _aa_buf, sizeof(_aa_buf));
					else
						_aa_buf[0] = '\0';
					if (_aa_buf[0] != '\0' && (strcmp(_aa_buf, "normal") == 0 || strcmp(_aa_buf, "advanced") == 0)) {
						// valid — allow through
					} else {
						return; // invalid: reject
					}
				} else {
					return; // non-string: reject
				}
			}
			// TextField gridFitType setter: validate
			if (prop_name_len == 11 && strncmp(prop_name, "gridFitType", 11) == 0
				&& mc->ng_textfield_idx >= 0)
			{
				if (value_var.type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _gf_u16 = varGetU16Ptr(&value_var);
					char _gf_buf[64];
					if (_gf_u16 && value_var.str_size > 0)
						u16_to_utf8(_gf_u16, value_var.str_size, _gf_buf, sizeof(_gf_buf));
					else
						_gf_buf[0] = '\0';
					if (_gf_buf[0] != '\0' && (strcmp(_gf_buf, "none") == 0 || strcmp(_gf_buf, "pixel") == 0 || strcmp(_gf_buf, "subpixel") == 0)) {
						// valid — allow through
					} else {
						return; // invalid: reject
					}
				} else {
					return; // non-string: reject
				}
			}
			// TextField sharpness/thickness setter: coerce to F64 with proper type conversion
			// In Flash, setting these to undefined/null becomes NaN, strings get parsed, etc.
			if ((prop_name_len == 9 && strncmp(prop_name, "sharpness", 9) == 0) ||
				(prop_name_len == 9 && strncmp(prop_name, "thickness", 9) == 0))
			{
				if (mc->ng_textfield_idx >= 0 || (mc->dynamic_props != NULL &&
					getPropertyWithPrototype((ASObject*)mc->dynamic_props, prop_name, prop_name_len) != NULL))
				{
					double d;
					switch (value_var.type) {
						case ACTION_STACK_VALUE_F64:
							d = VAL(double, &value_var.data.numeric_value); break;
						case ACTION_STACK_VALUE_F32:
							d = (double)VAL(float, &value_var.data.numeric_value); break;
						case ACTION_STACK_VALUE_BOOLEAN:
							d = value_var.data.numeric_value ? 1.0 : 0.0; break;
						case ACTION_STACK_VALUE_STRING: {
							const uint16_t* _st_u16 = varGetU16Ptr(&value_var);
							char _st_buf[256];
							if (_st_u16 && value_var.str_size > 0)
								u16_to_utf8(_st_u16, value_var.str_size, _st_buf, sizeof(_st_buf));
							else
								_st_buf[0] = '\0';
							if (_st_buf[0] != '\0') {
								char* end;
								d = strtod(_st_buf, &end);
								while (*end == ' ' || *end == '\t') end++;
								if (*end != '\0') d = NAN;
							} else {
								d = NAN;
							}
							break;
						}
						default:
							d = NAN; break;
					}
					value_var.type = ACTION_STACK_VALUE_F64;
					VAL(double, &value_var.data.numeric_value) = d;
				}
			}
			// TextField color properties: mask to 24-bit (0xFFFFFF)
			if (strcmp(prop_name, "backgroundColor") == 0 ||
				strcmp(prop_name, "borderColor") == 0 ||
				strcmp(prop_name, "textColor") == 0)
			{
				double dval = varToDouble(&value_var);
				int32_t ival = ecmaToInt32(dval);
				u32 masked = (u32)ival & 0x00FFFFFF;
				value_var.type = ACTION_STACK_VALUE_F64;
				VAL(double, &value_var.data.numeric_value) = (double)masked;
			}
			// TextField text: update length when text is set
			if (strcmp(prop_name, "text") == 0 && mc->dynamic_props != NULL)
			{
				// Update length property (str_size is UTF-16 code unit count)
				u32 _txt_len = 0;
				if (value_var.type == ACTION_STACK_VALUE_STRING)
					_txt_len = value_var.str_size;
				ASObject* props = (ASObject*) mc->dynamic_props;
				ActionVar len_val = {0};
				len_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &len_val.data.numeric_value) = (double)_txt_len;
				setProperty(app_context, props, "length", 6, &len_val);
#ifdef NO_GRAPHICS
				// Sync text → variable binding
				ng_syncTextToVar(app_context, mc, &value_var);
#endif
			}
			// TextField variable: changing binding breaks old, creates new
			if (strcmp(prop_name, "variable") == 0 && mc->ng_textfield_idx >= 0 && mc->dynamic_props != NULL)
			{
#ifdef NO_GRAPHICS
				// When variable binding changes: read new variable (or use initial text)
				// and reset the text field, then create the variable if needed.
				if (value_var.type == ACTION_STACK_VALUE_STRING && value_var.str_size > 0) {
					const uint16_t* _nv_u16 = varGetU16Ptr(&value_var);
					char _nv_buf[512];
					if (_nv_u16 && value_var.str_size > 0)
						u16_to_utf8(_nv_u16, value_var.str_size, _nv_buf, sizeof(_nv_buf));
					else
						_nv_buf[0] = '\0';
					const char* new_var = _nv_buf;
					if (new_var[0] != '\0') {
						ASObject* tf_props = (ASObject*) mc->dynamic_props;
						// Get initial text from DefineEditText definition (UTF-8)
						const char* def_init_text = ng_getTextFieldInitialTextByIdx(mc->ng_textfield_idx);
						// Convert to UTF-16 for ActionVar storage
						u32 _dit_u16_len;
						const uint16_t* use_text = utf8_to_u16(app_context, def_init_text, (u32)strlen(def_init_text), &_dit_u16_len);
						u32 use_len = _dit_u16_len;
						// Check if new variable exists
						extern bool hasVariable(char* var_name, size_t key_size);
						size_t nvlen = strlen(new_var);
						if (hasVariable((char*)new_var, nvlen)) {
							extern ActionVar* getVariable(char* var_name, size_t key_size);
							ActionVar* existing = getVariable((char*)new_var, nvlen);
							if (existing != NULL && existing->type == ACTION_STACK_VALUE_STRING && existing->str_size > 0) {
								use_text = varGetU16Ptr(existing);
								use_len = existing->str_size;
							}
						} else {
							// Create new variable with initial text
							ActionVar init_val = {0};
							init_val.type = ACTION_STACK_VALUE_STRING;
							init_val.str_size = use_len;
							VAL(u64, &init_val.data.numeric_value) = (u64)use_text;
							setVariableByName(new_var, &init_val);
						}
						// Update text field to variable value (or initial text)
						ActionVar text_val = {0};
						text_val.type = ACTION_STACK_VALUE_STRING;
						text_val.str_size = use_len;
						VAL(u64, &text_val.data.numeric_value) = (u64)use_text;
						setProperty(app_context, tf_props, "text", 4, &text_val);
						ActionVar len_val = {0};
						len_val.type = ACTION_STACK_VALUE_F64;
						VAL(double, &len_val.data.numeric_value) = (double)use_len;
						setProperty(app_context, tf_props, "length", 6, &len_val);
					}
				}
#endif
			}
			// TextField autoSize setter coercion
			if (prop_name_len == 8 && strncmp(prop_name, "autoSize", 8) == 0
				&& mc->ng_textfield_idx >= 0)
			{
				// Coerce value to one of: "left", "right", "center", "none" (as UTF-16)
				const uint16_t* _as_result = u16_none;
				u32 _as_result_len = 4;
				if (value_var.type == ACTION_STACK_VALUE_BOOLEAN)
				{
					if (value_var.data.numeric_value) { _as_result = u16_left; _as_result_len = 4; }
				}
				else if (value_var.type == ACTION_STACK_VALUE_STRING)
				{
					const uint16_t* _as_u16 = varGetU16Ptr(&value_var);
					char _as_buf[64];
					if (_as_u16 && value_var.str_size > 0)
						u16_to_utf8(_as_u16, value_var.str_size, _as_buf, sizeof(_as_buf));
					else
						_as_buf[0] = '\0';
					if (_as_buf[0] != '\0')
					{
						if (strcasecmp(_as_buf, "left") == 0) { _as_result = u16_left; _as_result_len = 4; }
						else if (strcasecmp(_as_buf, "right") == 0) { _as_result = u16_right; _as_result_len = 5; }
						else if (strcasecmp(_as_buf, "center") == 0) { _as_result = u16_center; _as_result_len = 6; }
					}
				}
				else if (value_var.type == ACTION_STACK_VALUE_OBJECT)
				{
					// Call toString on the object
					ActionVar str_result = objectCallToString(app_context, &value_var, NULL);
					if (str_result.type == ACTION_STACK_VALUE_STRING)
					{
						const uint16_t* _as2_u16 = varGetU16Ptr(&str_result);
						char _as2_buf[64];
						if (_as2_u16 && str_result.str_size > 0)
							u16_to_utf8(_as2_u16, str_result.str_size, _as2_buf, sizeof(_as2_buf));
						else
							_as2_buf[0] = '\0';
						if (_as2_buf[0] != '\0')
						{
							if (strcasecmp(_as2_buf, "left") == 0) { _as_result = u16_left; _as_result_len = 4; }
							else if (strcasecmp(_as2_buf, "right") == 0) { _as_result = u16_right; _as_result_len = 5; }
							else if (strcasecmp(_as2_buf, "center") == 0) { _as_result = u16_center; _as_result_len = 6; }
						}
					}
				}
				// Replace value_var with the coerced UTF-16 string
				value_var.type = ACTION_STACK_VALUE_STRING;
				value_var.str_size = _as_result_len;
				value_var.data.string_data.owns_memory = false;
				VAL(u64, &value_var.data.numeric_value) = (u64)_as_result;
			}
			// transform property: copy transform state from src MC to this MC
			if (prop_name_len == 9 && strncmp(prop_name, "transform", 9) == 0)
			{
				if (value_var.type == ACTION_STACK_VALUE_OBJECT && value_var.data.numeric_value != 0)
				{
					ASObject* src_tobj = (ASObject*) value_var.data.numeric_value;
					ActionVar* mc_ref = getProperty(src_tobj, "__mc__", 6);
					if (mc_ref && mc_ref->type == ACTION_STACK_VALUE_MOVIECLIP)
					{
						MovieClip* src_mc = (MovieClip*) mc_ref->data.numeric_value;
						if (src_mc)
						{
							mc->x = src_mc->x; mc->y = src_mc->y;
							mc->xscale = src_mc->xscale; mc->yscale = src_mc->yscale;
							mc->rotation = src_mc->rotation;
#ifdef NO_GRAPHICS
							mc->as_set_flags |= (1|2|4|8|16);
							s16 sra, sga, sba, saa, srb, sgb, sbb, sab;
							getLocalCTRaw(src_mc, &sra, &sga, &sba, &saa, &srb, &sgb, &sbb, &sab);
							setLocalCTRaw(mc, sra, sga, sba, saa, srb, sgb, sbb, sab);
#endif
						}
					}
				}
				return;
			}
			// User-defined property: store in dynamic_props and as global variable
			if (mc->dynamic_props == NULL)
			{
				mc->dynamic_props = (void*) allocObject(app_context, 4);
				retainObject((ASObject*) mc->dynamic_props);
			}
			setProperty(app_context, (ASObject*) mc->dynamic_props, prop_name, prop_name_len, &value_var);
			// Only propagate to global variable table for root movieclip
			// (timeline variables on root are also accessible as globals)
			// Child MC properties must NOT leak into global scope.
			extern MovieClip root_movieclip;
			if (mc == &root_movieclip)
				setVariableByName(prop_name, &value_var);
#ifdef NO_GRAPHICS
			// Sync path variable → text fields when setting a property on a MovieClip
			// E.g., mc.theVar = "Test1" should update textfields bound to "_root.mc.theVar"
			for (int tfi = 0; tfi < child_mc_count; tfi++) {
				MovieClip* tf_mc = child_mc_cache[tfi];
				if (tf_mc == NULL || tf_mc->ng_textfield_idx < 0) continue;
				ASObject* tf_props = (ASObject*) tf_mc->dynamic_props;
				if (tf_props == NULL) continue;
				ActionVar* var_prop = getProperty(tf_props, "variable", 8);
				if (var_prop == NULL || var_prop->type != ACTION_STACK_VALUE_STRING) continue;
				const uint16_t* _bd_u16 = varGetU16Ptr(var_prop);
				char _bd_buf[512];
				if (_bd_u16 && var_prop->str_size > 0)
					u16_to_utf8(_bd_u16, var_prop->str_size, _bd_buf, sizeof(_bd_buf));
				else
					_bd_buf[0] = '\0';
				const char* bound = _bd_buf;
				if (bound[0] == '\0' || strchr(bound, '.') == NULL) continue;
				// Check if binding ends with ".prop_name"
				const char* last_dot = strrchr(bound, '.');
				if (last_dot == NULL) continue;
				const char* final_name = last_dot + 1;
				if (strlen(final_name) != prop_name_len || strncmp(final_name, prop_name, prop_name_len) != 0) continue;
				// Resolve container of the binding
				u32 container_len = (u32)(last_dot - bound);
				PUSH_STR(bound, container_len);
				actionGetVariable(app_context);
				ActionVar cvar;
				peekVar(app_context, &cvar);
				POP();
				if (cvar.type == ACTION_STACK_VALUE_MOVIECLIP) {
					MovieClip* cmc = (MovieClip*) VAL(u64, &cvar.data.numeric_value);
					if (cmc == mc) {
						// Match: update this textfield's text
						setProperty(app_context, tf_props, "text", 4, &value_var);
						ActionVar len_val = {0};
						len_val.type = ACTION_STACK_VALUE_F64;
						if (value_var.type == ACTION_STACK_VALUE_STRING) {
							VAL(double, &len_val.data.numeric_value) = (double)value_var.str_size;
						}
						setProperty(app_context, tf_props, "length", 6, &len_val);
					}
				}
			}
#endif
		}
	}
	// If it's not an object, array, function, or movieclip type, we silently ignore the operation
	// (Flash behavior for setting properties on non-objects)
}

void actionInitObject(SWFAppContext* app_context)
{
	// Step 1: Pop property count from stack
	convertFloat(app_context);
	ActionVar count_var;
	popVar(app_context, &count_var);

	// Check raw double value against stack before u32 conversion — Flash pushes undefined on overflow
	// InitObject pops 2 values per property (name + value)
	double raw_count = varToDouble(&count_var);
	u32 stack_entries = (INITIAL_STACK_SIZE - SP) / 24;
	if (raw_count < 0 || raw_count * 2 > (double) stack_entries)
	{
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		return;
	}

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

		// Coerce property name to string (Flash spec: "The name of the property is converted to a string")
		char _io_buf[512];
		if (name_var.type == ACTION_STACK_VALUE_STRING)
		{
			name_length = (u32)u16_to_utf8((const uint16_t*)name_var.data.numeric_value, name_var.str_size, _io_buf, sizeof(_io_buf));
			name = _io_buf;
		}
		else if (name_var.type == ACTION_STACK_VALUE_F32 || name_var.type == ACTION_STACK_VALUE_F64)
		{
			if (name_var.type == ACTION_STACK_VALUE_F32)
			{
				float f = VAL(float, &name_var.data.numeric_value);
				snprintf(_io_buf, sizeof(_io_buf), "%.15g", f);
			}
			else
			{
				double d = VAL(double, &name_var.data.numeric_value);
				snprintf(_io_buf, sizeof(_io_buf), "%.15g", d);
			}
			name = _io_buf;
			name_length = strlen(_io_buf);
		}
		else if (name_var.type == ACTION_STACK_VALUE_BOOLEAN)
		{
			name = name_var.data.numeric_value ? "true" : "false";
			name_length = name_var.data.numeric_value ? 4 : 5;
		}
		else if (name_var.type == ACTION_STACK_VALUE_NULL)
		{
			name = "null";
			name_length = 4;
		}
		else if (name_var.type == ACTION_STACK_VALUE_UNDEFINED)
		{
			if (EFFECTIVE_SWF_VERSION() >= 7) {
				name = "undefined";
				name_length = 9;
			} else {
				name = "";
				name_length = 0;
			}
		}
		else
		{
			continue;
		}

#ifdef DEBUG
		printf("[DEBUG] actionInitObject: setting property '%.*s'\n", name_length, name);
#endif

		// Store property using the object API
		// This handles refcount management if value is an object
		setProperty(app_context, obj, name, name_length, &value);
	}

	// Set __proto__ to Object.prototype — but only if user didn't already set __proto__
	ActionVar* existing_proto = getProperty(obj, "__proto__", 9);
	if (existing_proto == NULL)
		setObjectProto(app_context, obj);
	else
	{
		// User set __proto__ manually — mark it as non-enumerable
		for (u32 i = 0; i < obj->num_used; i++)
		{
			if (obj->properties[i].name_length == 9 &&
			    strncmp(obj->properties[i].name, "__proto__", 9) == 0)
			{
				obj->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
				break;
			}
		}
	}

	// Step 4: Push object reference to stack
	// The object has refcount = 1 from allocation
	PUSH(ACTION_STACK_VALUE_OBJECT, (u64) obj);
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
	// 2. object (object reference)

	// Pop property name
	ActionVar prop_name_var;
	popVar(app_context, &prop_name_var);

	const char* prop_name = NULL;
	u32 prop_name_len = 0;

	char _del_buf[512];
	if (prop_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		prop_name_len = (u32)u16_to_utf8((const uint16_t*)prop_name_var.data.numeric_value, prop_name_var.str_size, _del_buf, sizeof(_del_buf));
		prop_name = _del_buf;
	}
	else
	{
		// Property name must be a string — pop object too and return true
		POP();
		PUSH(ACTION_STACK_VALUE_BOOLEAN, 1ULL);
		return;
	}

	// Pop object reference
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	ASObject* obj = NULL;

	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		obj = (ASObject*) obj_var.data.numeric_value;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// Fallback: if a string was pushed, look it up as a variable name
		char _del_obj_buf[512];
		u32 obj_name_len_tmp = (u32)u16_to_utf8((const uint16_t*)obj_var.data.numeric_value, obj_var.str_size, _del_obj_buf, sizeof(_del_obj_buf));
		const char* obj_name = _del_obj_buf;
		u32 obj_name_len = obj_name_len_tmp;
		ActionVar* looked_up = getVariable((char*)obj_name, obj_name_len);
		if (looked_up != NULL && looked_up->type == ACTION_STACK_VALUE_OBJECT)
		{
			obj = (ASObject*) looked_up->data.numeric_value;
		}
	}

	if (obj == NULL)
	{
		PUSH(ACTION_STACK_VALUE_BOOLEAN, 1ULL);
		return;
	}

	// Delete the property
	bool success = deleteProperty(app_context, obj, prop_name, prop_name_len);

	// Push result (true for success, false for failure)
	PUSH(ACTION_STACK_VALUE_BOOLEAN, success ? 1ULL : 0ULL);
}

void actionGetMember(SWFAppContext* app_context)
{
	// 1. Convert and pop property name (top of stack)
	char str_buffer[17];
	convertString(app_context, str_buffer);
	char _gm_buf[512];
	u32 prop_name_len = (u32)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _gm_buf, sizeof(_gm_buf));
	const char* prop_name = _gm_buf;
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

		// Flash AVM1: case-insensitive variants of "__proto__" (e.g., "__PROTO__", "__Proto__")
		// return the actual internal prototype chain, bypassing any user-set value.
		if (prop_name_len == 9 && memcmp(prop_name, "__proto__", 9) != 0 &&
		    strcasecmp(prop_name, "__proto__") == 0)
		{
			// Look for actual __proto__ (which may be Object.prototype, or missing if deleted)
			ActionVar* _iproto = getProperty(obj, "__proto__", 9);
			if (_iproto != NULL && _iproto->type == ACTION_STACK_VALUE_OBJECT)
			{
				pushVar(app_context, _iproto);
			}
			else
			{
				// __proto__ was deleted or isn't an object — return Object.prototype
				ASObject* _op = getObjectPrototype(app_context);
				if (_op != NULL) {
					ActionVar _opv = {0};
					_opv.type = ACTION_STACK_VALUE_OBJECT;
					_opv.data.numeric_value = (u64) _op;
					pushVar(app_context, &_opv);
				} else {
					pushUndefined(app_context);
				}
			}
			return;
		}

		// Look up property with prototype chain support (returns ASProperty* for getter check)
		ASProperty* prop_struct = findPropertyStructWithPrototype(obj, prop_name, prop_name_len);

		if (prop_struct != NULL)
		{
			if (prop_struct->getter != NULL)
			{
				// Virtual property (addProperty) — invoke getter with this = original obj
				ActionVar result = invokePropertyGetter(app_context, (ASFunction*)prop_struct->getter, (void*)obj);
				pushVar(app_context, &result);
			}
			else
			{
				// Regular property — push its value
				pushVar(app_context, &prop_struct->value);
			}
		}
		else
		{
			// For XML nodes, numeric index accesses childNodes[index]
			int is_xml = 0;
			if (prop_name_len > 0 && prop_name[0] >= '0' && prop_name[0] <= '9') {
				ActionVar* cn = getProperty(obj, "childNodes", 10);
				if (cn != NULL && cn->type == ACTION_STACK_VALUE_ARRAY) {
					ActionVar* nt = getProperty(obj, "nodeType", 8);
					if (nt != NULL) {
						is_xml = 1;
						ASArray* children = (ASArray*) cn->data.numeric_value;
						int idx = atoi(prop_name);
						if (children != NULL && idx >= 0 && (u32)idx < children->length) {
							pushVar(app_context, &children->elements[idx]);
						} else {
							pushUndefined(app_context);
						}
					}
				}
			}
			if (!is_xml) {
				// Geometry computed properties
				int geom_handled = 0;
				if (g_point_prototype != NULL || g_rect_prototype != NULL) {
					ActionVar* __proto_v = getProperty(obj, "__proto__", 9);
					if (__proto_v && __proto_v->type == ACTION_STACK_VALUE_OBJECT) {
						ASObject* proto = (ASObject*) __proto_v->data.numeric_value;
						if (proto == g_point_prototype && prop_name_len == 6 && memcmp(prop_name, "length", 6) == 0) {
							// Point.length getter
							double x = varToDoubleSimple(getProperty(obj, "x", 1));
							double y = varToDoubleSimple(getProperty(obj, "y", 1));
							double len = sqrt(x * x + y * y);
							ActionVar lv = makeF64(len);
							pushVar(app_context, &lv);
							geom_handled = 1;
						} else if (proto == g_rect_prototype) {
							// Rectangle computed getters
							double rx = varToDoubleSimple(getProperty(obj, "x", 1));
							double ry = varToDoubleSimple(getProperty(obj, "y", 1));
							double rw = varToDoubleSimple(getProperty(obj, "width", 5));
							double rh = varToDoubleSimple(getProperty(obj, "height", 6));
							if (prop_name_len == 4 && memcmp(prop_name, "left", 4) == 0) {
								ActionVar* xv = getProperty(obj, "x", 1);
								if (xv) pushVar(app_context, xv); else pushUndefined(app_context);
								geom_handled = 1;
							} else if (prop_name_len == 3 && memcmp(prop_name, "top", 3) == 0) {
								ActionVar* yv = getProperty(obj, "y", 1);
								if (yv) pushVar(app_context, yv); else pushUndefined(app_context);
								geom_handled = 1;
							} else if (prop_name_len == 5 && memcmp(prop_name, "right", 5) == 0) {
								ActionVar v = makeF64(rx + rw);
								pushVar(app_context, &v);
								geom_handled = 1;
							} else if (prop_name_len == 6 && memcmp(prop_name, "bottom", 6) == 0) {
								ActionVar v = makeF64(ry + rh);
								pushVar(app_context, &v);
								geom_handled = 1;
							} else if (prop_name_len == 7 && memcmp(prop_name, "topLeft", 7) == 0) {
								ActionVar* xxv = getProperty(obj, "x", 1);
								ActionVar* yyv = getProperty(obj, "y", 1);
								ASObject* pt = createPointObj(app_context, xxv, yyv);
								ActionVar pv = {0}; pv.type = ACTION_STACK_VALUE_OBJECT;
								pv.data.numeric_value = (u64)pt;
								pushVar(app_context, &pv);
								geom_handled = 1;
							} else if (prop_name_len == 11 && memcmp(prop_name, "bottomRight", 11) == 0) {
								ActionVar brx = makeF64(rx + rw);
								ActionVar bry = makeF64(ry + rh);
								ASObject* pt = createPointObj(app_context, &brx, &bry);
								ActionVar pv = {0}; pv.type = ACTION_STACK_VALUE_OBJECT;
								pv.data.numeric_value = (u64)pt;
								pushVar(app_context, &pv);
								geom_handled = 1;
							} else if (prop_name_len == 4 && memcmp(prop_name, "size", 4) == 0) {
								ActionVar* wv = getProperty(obj, "width", 5);
								ActionVar* hv = getProperty(obj, "height", 6);
								ASObject* pt = createPointObj(app_context, wv, hv);
								ActionVar pv = {0}; pv.type = ACTION_STACK_VALUE_OBJECT;
								pv.data.numeric_value = (u64)pt;
								pushVar(app_context, &pv);
								geom_handled = 1;
							}
						}
					}
				}
				if (!geom_handled) {
					// Check if __proto__ is ARRAY and key is numeric — look in proto array's elements
					int arr_proto_handled = 0;
					if (prop_name_len > 0 && prop_name[0] >= '0' && prop_name[0] <= '9') {
						ActionVar* proto_var = getProperty(obj, "__proto__", 9);
						if (proto_var != NULL && proto_var->type == ACTION_STACK_VALUE_ARRAY) {
							ASArray* proto_arr = (ASArray*) proto_var->data.numeric_value;
							char* endptr;
							long long idx = strtoll(prop_name, &endptr, 10);
							if (*endptr == '\0' && idx >= 0 && idx <= 2147483647LL) {
								arr_proto_handled = 1;
								ActionVar* elem = getArrayElement(proto_arr, (u32)idx);
								if (elem != NULL && elem->type != ACTION_STACK_VALUE_HOLE) {
									pushVar(app_context, elem);
								} else {
									pushUndefined(app_context);
								}
							}
						}
					}
					if (!arr_proto_handled) {
						pushUndefined(app_context);
					}
				}
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// Handle string properties
		if (strcmp(prop_name, "length") == 0)
		{
			// With UTF-16 storage, str_size IS the code unit count
			float len = (float) obj_var.str_size;
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
			// Push array length as signed i32 → double (Flash AS2 semantics)
			double len = (double) (int32_t) arr->length;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &len));
		}
		else
		{
			// Try to parse property name as an array index
			char* endptr;
			long long index = strtoll(prop_name, &endptr, 10);

			// Check if conversion was successful and entire string was consumed
			// Valid array indices are 0 to INT_MAX (2147483647)
			if (*endptr == '\0' && index >= 0 && index <= 2147483647LL)
			{
				// Valid numeric index — try elements array first
				ActionVar* elem = getArrayElement(arr, (u32)index);
				if (elem != NULL && elem->type != ACTION_STACK_VALUE_HOLE)
				{
					pushVar(app_context, elem);
				}
				else if (arr->props != NULL)
				{
					// Might be stored in props (large index)
					ActionVar* pv = getProperty(arr->props, prop_name, prop_name_len);
					if (pv != NULL)
						pushVar(app_context, pv);
					else
						pushUndefined(app_context);
				}
				else
				{
					pushUndefined(app_context);
				}
			}
			else
			{
				// Non-index property — check array's props object
				if (arr->props != NULL)
				{
					ActionVar* pv = getPropertyWithPrototype(arr->props, prop_name, prop_name_len);
					if (pv != NULL)
					{
						pushVar(app_context, pv);
					}
					else
					{
						pushUndefined(app_context);
					}
				}
				else
				{
					pushUndefined(app_context);
				}
			}
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		// Handle function properties (e.g., MyClass.prototype)
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;
		if (func != NULL && strcmp(prop_name, "prototype") == 0)
		{
			// In SWF5, AsBroadcaster and TextField have no prototype
			if (func->prototype_obj == NULL && g_swf_version < 6 &&
			    (func == &g_stub_ctors[0] || func == &g_textfield_constructor))
			{
				pushUndefined(app_context);
			}
			else
			{
				// Lazily create prototype object on first access
				if (func->prototype_obj == NULL)
				{
					func->prototype_obj = allocObject(app_context, 4);
					retainObject(func->prototype_obj);
					// Set Object.prototype as __proto__ for prototype chain
					setObjectProto(app_context, func->prototype_obj);
					// Set constructor property pointing back to the function
					ActionVar ctor_var;
					ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
					ctor_var.str_size = 0;
					ctor_var.data.numeric_value = (u64) func;
					setProperty(app_context, func->prototype_obj, "constructor", 11, &ctor_var);
				}
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64) func->prototype_obj);
			}
		}
		else if (func != NULL)
		{
			// Check own_props for arbitrary properties set on the function
			int found = 0;
			if (func->own_props != NULL)
			{
				ActionVar* pv = getPropertyWithPrototype(func->own_props, prop_name, prop_name_len);
				if (pv != NULL)
				{
					pushVar(app_context, pv);
					found = 1;
				}
			}
			if (!found)
				pushUndefined(app_context);
		}
		else
		{
			pushUndefined(app_context);
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		// MovieClip member access — check built-in properties, then MovieClip.prototype
		MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;

		// Check built-in MovieClip properties (case-insensitive for _ prefixed ones)
		if (mc != NULL && prop_name_len > 0 && prop_name[0] == '_')
		{
			// Case-insensitive comparison for built-in MC properties
			if (strcasecmp(prop_name, "_x") == 0) {
#ifdef NO_GRAPHICS
				syncTransformIfNeeded(mc);
				if (!(mc->as_set_flags & 1)) {
					size_t _dep = ng_findDisplayEntryByName(mc->name);
					if (_dep != SIZE_MAX) {
						double _dx;
						if (ng_getTransformXY_d(_dep, &_dx, NULL)) {
							PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_dx));
							return;
						}
					}
				}
#endif
				float v = mc->x; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_y") == 0) {
#ifdef NO_GRAPHICS
				syncTransformIfNeeded(mc);
				if (!(mc->as_set_flags & 2)) {
					size_t _dep = ng_findDisplayEntryByName(mc->name);
					if (_dep != SIZE_MAX) {
						double _dy;
						if (ng_getTransformXY_d(_dep, NULL, &_dy)) {
							PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_dy));
							return;
						}
					}
				}
#endif
				float v = mc->y; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_xscale") == 0) {
#ifdef NO_GRAPHICS
				syncTransformIfNeeded(mc);
#endif
				float v = mc->xscale; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_yscale") == 0) {
#ifdef NO_GRAPHICS
				syncTransformIfNeeded(mc);
#endif
				float v = mc->yscale; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_rotation") == 0) {
#ifdef NO_GRAPHICS
				syncTransformIfNeeded(mc);
#endif
				float v = mc->rotation; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_alpha") == 0) { float v = mc->alpha; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_visible") == 0) { u64 v = mc->visible ? 1 : 0; PUSH(ACTION_STACK_VALUE_BOOLEAN, v); return; }
			if (strcasecmp(prop_name, "_width") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_ew)); return; }
			if (strcasecmp(prop_name, "_height") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_eh)); return; }
			if (strcasecmp(prop_name, "_currentframe") == 0) { float v = (float)mc->currentframe; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_totalframes") == 0) { float v = (float)mc->totalframes; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_framesloaded") == 0) { float v = (float)mc->framesloaded; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_name") == 0) { PUSH_STR(mc->name, strlen(mc->name)); return; }
			if (strcasecmp(prop_name, "_target") == 0) { PUSH_STR(mc->target, strlen(mc->target)); return; }
			if (strcasecmp(prop_name, "_url") == 0) { PUSH_STR(mc->url, strlen(mc->url)); return; }
			if (strcasecmp(prop_name, "_droptarget") == 0) { PUSH_STR(mc->droptarget, strlen(mc->droptarget)); return; }
			if (strcasecmp(prop_name, "_quality") == 0) { PUSH_STR(mc->quality, strlen(mc->quality)); return; }
			if (strcasecmp(prop_name, "_xmouse") == 0) { float v = mc->xmouse; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_ymouse") == 0) { float v = mc->ymouse; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_highquality") == 0) { float v = mc->highquality; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_focusrect") == 0) {
				// _focusrect defaults to null in Flash (not a number)
				if (mc->focusrect < 0.0f) { PUSH(ACTION_STACK_VALUE_NULL, 0); }
				else { float v = mc->focusrect; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); }
				return;
			}
			if (strcasecmp(prop_name, "_soundbuftime") == 0) { float v = mc->soundbuftime; PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v)); return; }
			if (strcasecmp(prop_name, "_lockroot") == 0) { PUSH(ACTION_STACK_VALUE_BOOLEAN, (u64)mc->lockroot); return; }
			if (strcasecmp(prop_name, "_parent") == 0) {
				if (mc->parent != NULL) { PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)mc->parent); }
				else { pushUndefined(app_context); }
				return;
			}
		}

		// Check user-defined dynamic properties (walks __proto__ chain for TextField prototype)
		if (mc != NULL && mc->dynamic_props != NULL)
		{
			ActionVar* prop = getPropertyWithPrototype((ASObject*) mc->dynamic_props, prop_name, prop_name_len);
			if (prop != NULL)
			{
				pushVar(app_context, prop);
				return;
			}
		}

		// Check child instance names (in Flash, mc.childName resolves to child clips)
#ifdef NO_GRAPHICS
		if (mc != NULL)
		{
			char child_name_buf[64];
			if (prop_name_len < 64) {
				memcpy(child_name_buf, prop_name, prop_name_len);
				child_name_buf[prop_name_len] = '\0';
			} else {
				memcpy(child_name_buf, prop_name, 63);
				child_name_buf[63] = '\0';
			}
			// First try nested child lookup (for mc.childName inside mc's display list)
			size_t child_depth = SIZE_MAX;
			if (mc->name[0] != '\0') {
				child_depth = ng_findChildEntryDepth(mc->name, child_name_buf);
			}
			if (child_depth != SIZE_MAX) {
				// Found as nested child of mc -- create MC with parent=mc and correct depth
				MovieClip* child_mc = findOrCreateMovieClip(app_context, child_name_buf, mc);
				if (child_mc != NULL) {
					child_mc->depth = (int)child_depth - 16384;
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child_mc);
					return;
				}
			}
			// Fall back to root-level name search
			child_depth = ng_findDisplayEntryByName(child_name_buf);
			if (child_depth != SIZE_MAX) {
				MovieClip* child_mc = findOrCreateMovieClip(app_context, child_name_buf, mc);
				if (child_mc != NULL) {
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child_mc);
					return;
				}
			}
		}
#endif

		// Built-in defaults for non-underscore properties
		if (mc != NULL && prop_name_len == 13 && strncmp(prop_name, "useHandCursor", 13) == 0)
		{
			// useHandCursor defaults to true for both MovieClips and Buttons
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 1ULL);
			return;
		}
		if (mc != NULL && prop_name_len == 7 && strncmp(prop_name, "enabled", 7) == 0)
		{
			// enabled defaults to true
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 1ULL);
			return;
		}
		// blendMode: return string representation
		if (mc != NULL && prop_name_len == 9 && strncmp(prop_name, "blendMode", 9) == 0)
		{
			static const char* blend_mode_names[] = {
				"normal", "normal", "layer", "multiply", "screen", "lighten",
				"darken", "difference", "add", "subtract", "invert",
				"alpha", "erase", "overlay", "hardlight"
			};
			int bm = mc->blend_mode;
			const char* name = (bm >= 0 && bm <= 14) ? blend_mode_names[bm] : "normal";
			PUSH_STR((char*)name, strlen(name));
			return;
		}
		if (mc != NULL && prop_name_len == 13 && strncmp(prop_name, "cacheAsBitmap", 13) == 0)
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0ULL);
			return;
		}
		if (mc != NULL && prop_name_len == 7 && strncmp(prop_name, "filters", 7) == 0)
		{
			// filters defaults to empty array
			ASArray* arr = allocArray(app_context, 0);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64)arr);
			return;
		}
		if (mc != NULL && prop_name_len == 9 && strncmp(prop_name, "transform", 9) == 0)
		{
			ASObject* transform = createTransformObject(app_context, mc);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)transform);
			return;
		}

		// Fall back to global variable map (timeline variables are accessible as mc properties)
		// Only for root MovieClip — child MC properties should not leak into global scope
		{
			extern MovieClip root_movieclip;
			if (mc == &root_movieclip && hasVariable((char*)prop_name, prop_name_len))
			{
				ActionVar* var = getVariable((char*)prop_name, prop_name_len);
				if (var != NULL)
				{
					pushVar(app_context, var);
					return;
				}
			}
		}

		// Fall back to MovieClip.prototype chain
		extern ASFunction g_movieclip_constructor;
		extern int g_movieclip_constructor_init;
		if (g_movieclip_constructor_init && g_movieclip_constructor.prototype_obj != NULL)
		{
			ActionVar* prop = getPropertyWithPrototype(g_movieclip_constructor.prototype_obj, prop_name, prop_name_len);
			if (prop != NULL)
			{
				pushVar(app_context, prop);
				return;
			}
		}

		pushUndefined(app_context);
	}
	else
	{
		// Other primitive types (number, undefined, etc.) - push undefined
		pushUndefined(app_context);
	}
}

void actionNewObject(SWFAppContext* app_context)
{
	// Ensure globals (Object, Array, stub ctors, etc.) are initialized before any new X() call
	ensureGlobalInit(app_context);

	// 1. Pop constructor name (string)
	ActionVar ctor_name_var;
	popVar(app_context, &ctor_name_var);
	const char* ctor_name;
	u32 ctor_name_len;
	char _no_buf[512];
	if (ctor_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		ctor_name_len = (u32)u16_to_utf8((const uint16_t*)ctor_name_var.data.numeric_value, ctor_name_var.str_size, _no_buf, sizeof(_no_buf));
		ctor_name = _no_buf;
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
			// Flash stores length as u32 via ToInt32, negative values wrap (e.g. -1 → 0xFFFFFFFF)
			double length_d = (args[0].type == ACTION_STACK_VALUE_F32) ?
				(double) VAL(float, &args[0].data.numeric_value) :
				VAL(double, &args[0].data.numeric_value);
			u32 length = (u32) ecmaToInt32(length_d);
			int32_t signed_len = (int32_t) length;
			u32 alloc_size = 0;
			if (signed_len > 0)
				alloc_size = (u32)signed_len < 1000000 ? (u32)signed_len : 1000000;
			ASArray* arr = allocArray(app_context, alloc_size > 0 ? alloc_size : 4);
			// new Array(n): elements stay as HOLE (don't enumerate, but join as "undefined")
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
		if (num_args > 0)
		{
			// Object(x) with an argument — pass through objects/arrays, wrap primitives
			ActionVar* arg = &args[0];
			if (arg->type == ACTION_STACK_VALUE_OBJECT)
			{
				// Pass through existing object (same reference)
				retainObject((ASObject*) arg->data.numeric_value);
				PUSH(ACTION_STACK_VALUE_OBJECT, arg->data.numeric_value);
				return;
			}
			else if (arg->type == ACTION_STACK_VALUE_ARRAY)
			{
				// Pass through existing array
				retainArray((ASArray*) arg->data.numeric_value);
				PUSH(ACTION_STACK_VALUE_ARRAY, arg->data.numeric_value);
				return;
			}
			else if (arg->type == ACTION_STACK_VALUE_MOVIECLIP)
			{
				// Pass through movie clip
				PUSH(ACTION_STACK_VALUE_MOVIECLIP, arg->data.numeric_value);
				return;
			}
			else if (arg->type == ACTION_STACK_VALUE_NULL ||
			         arg->type == ACTION_STACK_VALUE_UNDEFINED)
			{
				// null/undefined → create new empty object (fall through)
			}
			else
			{
				// Primitive (number, string, boolean) → wrap in object
				// typeof returns "object" but trace still shows primitive value
				ASObject* wrapper = allocObject(app_context, 8);
				setObjectProto(app_context, wrapper);

				// Store the primitive value for valueOf/toString
				ActionVar prim_val;
				prim_val = *arg;
				setProperty(app_context, wrapper, "valueOf_value", 13, &prim_val);

				// Lazily init wrapper valueOf/toString functions
				if (!g_wrapper_funcs_init)
				{
					memset(&g_wrapper_valueOf_func, 0, sizeof(ASFunction));
					strncpy(g_wrapper_valueOf_func.name, "valueOf", 255);
					g_wrapper_valueOf_func.function_type = 2;
					g_wrapper_valueOf_func.param_count = 0;
					g_wrapper_valueOf_func.advanced_func = (Function2Ptr) builtin_wrapper_valueOf;
					if (function_count < MAX_FUNCTIONS)
						function_registry[function_count++] = &g_wrapper_valueOf_func;

					memset(&g_prim_wrapper_toString_func, 0, sizeof(ASFunction));
					strncpy(g_prim_wrapper_toString_func.name, "toString", 255);
					g_prim_wrapper_toString_func.function_type = 2;
					g_prim_wrapper_toString_func.param_count = 0;
					g_prim_wrapper_toString_func.advanced_func = (Function2Ptr) builtin_prim_wrapper_toString;
					if (function_count < MAX_FUNCTIONS)
						function_registry[function_count++] = &g_prim_wrapper_toString_func;

					g_wrapper_funcs_init = 1;
				}

				ActionVar vo_val = {0};
				vo_val.type = ACTION_STACK_VALUE_FUNCTION;
				VAL(u64, &vo_val.data.numeric_value) = (u64) &g_wrapper_valueOf_func;
				setProperty(app_context, wrapper, "valueOf", 7, &vo_val);

				ActionVar ts_val = {0};
				ts_val.type = ACTION_STACK_VALUE_FUNCTION;
				VAL(u64, &ts_val.data.numeric_value) = (u64) &g_prim_wrapper_toString_func;
				setProperty(app_context, wrapper, "toString", 8, &ts_val);

				new_obj = wrapper;
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
				return;
			}
		}
		// No args or null/undefined arg → create empty object
		ASObject* obj = allocObject(app_context, 8);
		setObjectProto(app_context, obj);
		new_obj = obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Error") == 0)
	{
		// Handle Error constructor — new Error([message])
		ASObject* err = allocObject(app_context, 8);
		// Set __proto__ to Error.prototype (via the Error constructor function)
		// Use GetVariable("Error") to find the constructor and its prototype
		// For simplicity, just set the message property
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			// Copy the UTF-16 string as-is
			setProperty(app_context, err, "message", 7, &args[0]);
		}
		else if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_NULL)
		{
			ActionVar msg_val = {0};
			msg_val.type = ACTION_STACK_VALUE_STRING;
			msg_val.str_size = 4;
			VAL(u64, &msg_val.data.numeric_value) = (u64) u16_null;
			setProperty(app_context, err, "message", 7, &msg_val);
		}
		// Set __proto__ to Error.prototype
		// Look up Error constructor's prototype
		PUSH_STR("Error", 5);
		actionGetVariable(app_context);
		if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* ctor = (ASFunction*) STACK_TOP_VALUE;
			if (ctor->prototype_obj != NULL)
			{
				ActionVar proto_var = {0};
				proto_var.type = ACTION_STACK_VALUE_OBJECT;
				proto_var.data.numeric_value = (u64) ctor->prototype_obj;
				setProperty(app_context, err, "__proto__", 9, &proto_var);
			}
		}
		POP();
		new_obj = err;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Date") == 0)
	{
		ASObject* date = date_construct(app_context, args, num_args);
		new_obj = date;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "String") == 0)
	{
		// Handle String constructor
		// new String() or new String(value)
		ASObject* str_obj = allocObject(app_context, 8);

		// Set __proto__ to String.prototype for instanceof support
		PUSH_STR("String", 6);
		actionGetVariable(app_context);
		if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* ctor = (ASFunction*) STACK_TOP_VALUE;
			if (ctor->prototype_obj == NULL)
			{
				ctor->prototype_obj = allocObject(app_context, 4);
				retainObject(ctor->prototype_obj);
				setObjectProto(app_context, ctor->prototype_obj);
			}
			ActionVar proto_var = {0};
			proto_var.type = ACTION_STACK_VALUE_OBJECT;
			proto_var.data.numeric_value = (u64) ctor->prototype_obj;
			setProperty(app_context, str_obj, "__proto__", 9, &proto_var);
		}
		else
		{
			setObjectProto(app_context, str_obj);
		}
		POP();

		// Store the string value for valueOf/toString support
		ActionVar value_var = {0};
		value_var.type = ACTION_STACK_VALUE_STRING;
		if (num_args > 0)
		{
			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				value_var = args[0];
			}
			else
			{
				char str_buffer[256];
				int len = varToStringBuf(app_context, &args[0], str_buffer, sizeof(str_buffer));
				u32 u16_len;
				uint16_t* u16 = ascii_to_u16(app_context, str_buffer, len, &u16_len);
				value_var.str_size = u16_len;
				value_var.data.string_data.heap_ptr = u16;
				value_var.data.string_data.owns_memory = true;
			}
		}
		// Store as "valueOf_value" (read by builtin_wrapper_valueOf/builtin_prim_wrapper_toString)
		setPropertyWithFlags(app_context, str_obj, "valueOf_value", 13, &value_var, PROPERTY_FLAGS_DONTENUM);
		// Also store as "value" for backward compatibility
		setPropertyWithFlags(app_context, str_obj, "value", 5, &value_var, PROPERTY_FLAGS_DONTENUM);
		// Set length property (DontEnum, like native String.length)
		{
			u32 slen = (value_var.type == ACTION_STACK_VALUE_STRING) ? value_var.str_size : 0;
			double slen_d = (double) slen;
			ActionVar len_var = {0};
			len_var.type = ACTION_STACK_VALUE_F64;
			VAL(double, &len_var.data.numeric_value) = slen_d;
			setPropertyWithFlags(app_context, str_obj, "length", 6, &len_var, PROPERTY_FLAG_WRITABLE);
		}

		// Set up valueOf and toString using the wrapper infrastructure
		if (!g_wrapper_funcs_init)
		{
			memset(&g_wrapper_valueOf_func, 0, sizeof(ASFunction));
			strncpy(g_wrapper_valueOf_func.name, "valueOf", 255);
			g_wrapper_valueOf_func.function_type = 2;
			g_wrapper_valueOf_func.param_count = 0;
			g_wrapper_valueOf_func.advanced_func = (Function2Ptr) builtin_wrapper_valueOf;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_wrapper_valueOf_func;

			memset(&g_prim_wrapper_toString_func, 0, sizeof(ASFunction));
			strncpy(g_prim_wrapper_toString_func.name, "toString", 255);
			g_prim_wrapper_toString_func.function_type = 2;
			g_prim_wrapper_toString_func.param_count = 0;
			g_prim_wrapper_toString_func.advanced_func = (Function2Ptr) builtin_prim_wrapper_toString;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_prim_wrapper_toString_func;

			g_wrapper_funcs_init = 1;
		}

		ActionVar vo_val = {0};
		vo_val.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &vo_val.data.numeric_value) = (u64) &g_wrapper_valueOf_func;
		setPropertyWithFlags(app_context, str_obj, "valueOf", 7, &vo_val, PROPERTY_FLAGS_DONTENUM);

		ActionVar ts_val = {0};
		ts_val.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &ts_val.data.numeric_value) = (u64) &g_prim_wrapper_toString_func;
		setPropertyWithFlags(app_context, str_obj, "toString", 8, &ts_val, PROPERTY_FLAGS_DONTENUM);

		new_obj = str_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Number") == 0)
	{
		// Handle Number constructor
		// new Number() or new Number(value)
		ASObject* num_obj = allocObject(app_context, 4);

		// Set __proto__ to Number.prototype for instanceof support
		PUSH_STR("Number", 6);
		actionGetVariable(app_context);
		if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* ctor = (ASFunction*) STACK_TOP_VALUE;
			if (ctor->prototype_obj == NULL)
			{
				ctor->prototype_obj = allocObject(app_context, 4);
				retainObject(ctor->prototype_obj);
				setObjectProto(app_context, ctor->prototype_obj);
			}
			ActionVar proto_var = {0};
			proto_var.type = ACTION_STACK_VALUE_OBJECT;
			proto_var.data.numeric_value = (u64) ctor->prototype_obj;
			setProperty(app_context, num_obj, "__proto__", 9, &proto_var);
		}
		else
		{
			setObjectProto(app_context, num_obj);
		}
		POP();

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
				char tmp[256];
				const uint16_t* u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(u16, args[0].str_size, tmp, sizeof(tmp));
				double num = atof(tmp);
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

		setPropertyWithFlags(app_context, num_obj, "valueOf_value", 13, &value_var, PROPERTY_FLAGS_DONTENUM);
		setPropertyWithFlags(app_context, num_obj, "value", 5, &value_var, PROPERTY_FLAGS_DONTENUM);

		// Set up valueOf and toString using the wrapper infrastructure
		if (!g_wrapper_funcs_init)
		{
			memset(&g_wrapper_valueOf_func, 0, sizeof(ASFunction));
			strncpy(g_wrapper_valueOf_func.name, "valueOf", 255);
			g_wrapper_valueOf_func.function_type = 2;
			g_wrapper_valueOf_func.param_count = 0;
			g_wrapper_valueOf_func.advanced_func = (Function2Ptr) builtin_wrapper_valueOf;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_wrapper_valueOf_func;
			memset(&g_prim_wrapper_toString_func, 0, sizeof(ASFunction));
			strncpy(g_prim_wrapper_toString_func.name, "toString", 255);
			g_prim_wrapper_toString_func.function_type = 2;
			g_prim_wrapper_toString_func.param_count = 0;
			g_prim_wrapper_toString_func.advanced_func = (Function2Ptr) builtin_prim_wrapper_toString;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_prim_wrapper_toString_func;
			g_wrapper_funcs_init = 1;
		}
		ActionVar _nvo = {0}; _nvo.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &_nvo.data.numeric_value) = (u64) &g_wrapper_valueOf_func;
		setPropertyWithFlags(app_context, num_obj, "valueOf", 7, &_nvo, PROPERTY_FLAGS_DONTENUM);
		ActionVar _nts = {0}; _nts.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &_nts.data.numeric_value) = (u64) &g_prim_wrapper_toString_func;
		setPropertyWithFlags(app_context, num_obj, "toString", 8, &_nts, PROPERTY_FLAGS_DONTENUM);

		new_obj = num_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "Boolean") == 0)
	{
		// Handle Boolean constructor
		// new Boolean() or new Boolean(value)
		ASObject* bool_obj = allocObject(app_context, 4);

		// Set __proto__ to Boolean.prototype for instanceof support
		PUSH_STR("Boolean", 7);
		actionGetVariable(app_context);
		if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
		{
			ASFunction* ctor = (ASFunction*) STACK_TOP_VALUE;
			if (ctor->prototype_obj == NULL)
			{
				ctor->prototype_obj = allocObject(app_context, 4);
				retainObject(ctor->prototype_obj);
				setObjectProto(app_context, ctor->prototype_obj);
			}
			ActionVar proto_var = {0};
			proto_var.type = ACTION_STACK_VALUE_OBJECT;
			proto_var.data.numeric_value = (u64) ctor->prototype_obj;
			setProperty(app_context, bool_obj, "__proto__", 9, &proto_var);
		}
		else
		{
			setObjectProto(app_context, bool_obj);
		}
		POP();

		// Store boolean value as property (use BOOLEAN type so toString shows "true"/"false")
		ActionVar value_var;
		value_var.type = ACTION_STACK_VALUE_BOOLEAN;
		value_var.data.numeric_value = 0;

		if (num_args > 0)
		{
			// Convert first argument to boolean
			u64 bool_val = 0;
			if (args[0].type == ACTION_STACK_VALUE_F32)
				bool_val = (VAL(float, &args[0].data.numeric_value) != 0.0f) ? 1 : 0;
			else if (args[0].type == ACTION_STACK_VALUE_F64)
				bool_val = (VAL(double, &args[0].data.numeric_value) != 0.0) ? 1 : 0;
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
				bool_val = (args[0].str_size > 0) ? 1 : 0;
			else if (args[0].type == ACTION_STACK_VALUE_BOOLEAN)
				bool_val = args[0].data.numeric_value ? 1 : 0;
			value_var.data.numeric_value = bool_val;
		}

		setPropertyWithFlags(app_context, bool_obj, "valueOf_value", 13, &value_var, PROPERTY_FLAGS_DONTENUM);
		setPropertyWithFlags(app_context, bool_obj, "value", 5, &value_var, PROPERTY_FLAGS_DONTENUM);

		// Set up valueOf and toString using the wrapper infrastructure
		if (!g_wrapper_funcs_init)
		{
			memset(&g_wrapper_valueOf_func, 0, sizeof(ASFunction));
			strncpy(g_wrapper_valueOf_func.name, "valueOf", 255);
			g_wrapper_valueOf_func.function_type = 2;
			g_wrapper_valueOf_func.param_count = 0;
			g_wrapper_valueOf_func.advanced_func = (Function2Ptr) builtin_wrapper_valueOf;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_wrapper_valueOf_func;
			memset(&g_prim_wrapper_toString_func, 0, sizeof(ASFunction));
			strncpy(g_prim_wrapper_toString_func.name, "toString", 255);
			g_prim_wrapper_toString_func.function_type = 2;
			g_prim_wrapper_toString_func.param_count = 0;
			g_prim_wrapper_toString_func.advanced_func = (Function2Ptr) builtin_prim_wrapper_toString;
			if (function_count < MAX_FUNCTIONS)
				function_registry[function_count++] = &g_prim_wrapper_toString_func;
			g_wrapper_funcs_init = 1;
		}
		ActionVar _bvo = {0}; _bvo.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &_bvo.data.numeric_value) = (u64) &g_wrapper_valueOf_func;
		setPropertyWithFlags(app_context, bool_obj, "valueOf", 7, &_bvo, PROPERTY_FLAGS_DONTENUM);
		ActionVar _bts = {0}; _bts.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &_bts.data.numeric_value) = (u64) &g_prim_wrapper_toString_func;
		setPropertyWithFlags(app_context, bool_obj, "toString", 8, &_bts, PROPERTY_FLAGS_DONTENUM);

		new_obj = bool_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "TextField") == 0)
	{
		// Handle TextField constructor — new TextField()
		// Creates an empty object with __proto__ set to TextField.prototype
		ASObject* tf_obj = allocObject(app_context, 4);
		initTextFieldPrototype(app_context);
		if (g_textfield_constructor.prototype_obj != NULL)
		{
			ActionVar proto_var = {0};
			proto_var.type = ACTION_STACK_VALUE_OBJECT;
			proto_var.data.numeric_value = (u64) g_textfield_constructor.prototype_obj;
			setProperty(app_context, tf_obj, "__proto__", 9, &proto_var);
			// Mark __proto__ as DontEnum
			for (u32 i = 0; i < tf_obj->num_used; i++) {
				if (strcmp(tf_obj->properties[i].name, "__proto__") == 0) {
					tf_obj->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
					break;
				}
			}
		}
		else
		{
			// SWF5: no TextField.prototype; use Object.prototype as __proto__
			setObjectProto(app_context, tf_obj);
			// In SWF5, new TextField() populates 35 properties as own enumerable
			// properties (since there's no TextField.prototype to inherit from).
			// Add in REVERSE insertion order so actionEnumerate2 (LIFO) yields
			// them in forward order: styleSheet first, gridFitType last.
			ActionVar undef_val = {0};
			undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
			static const char* swf5_tf_prop_names[] = {
				"styleSheet", "mouseWheelEnabled", "condenseWhite", "restrict",
				"textHeight", "textWidth", "bottomScroll", "length",
				"selectable", "multiline", "password", "wordWrap",
				"background", "border", "html", "embedFonts",
				"maxChars", "maxhscroll", "hscroll", "variable",
				"htmlText", "type", "text", "autoSize",
				"tabIndex", "textColor", "backgroundColor", "borderColor",
				"maxscroll", "scroll", "filters", "sharpness",
				"thickness", "antiAliasType", "gridFitType"
			};
			static const u32 swf5_tf_prop_lens[] = {
				10, 17, 13, 8,
				10, 9, 12, 6,
				10, 9, 8, 8,
				10, 6, 4, 10,
				8, 10, 7, 8,
				8, 4, 4, 8,
				8, 9, 15, 11,
				9, 6, 7, 9,
				9, 13, 11
			};
			for (int i = 34; i >= 0; i--)
			{
				// Properties 0-29 (styleSheet through scroll) are NOT writable in SWF5
				// (they are internal AVM1 properties that ignore SetMember).
				// Properties 30-34 (filters through gridFitType) ARE writable.
				u8 flags = (i >= 30) ? PROPERTY_FLAGS_DEFAULT :
				                       (PROPERTY_FLAG_ENUMERABLE | PROPERTY_FLAG_CONFIGURABLE);
				setPropertyWithFlags(app_context, tf_obj, swf5_tf_prop_names[i], swf5_tf_prop_lens[i], &undef_val, flags);
			}
		}
		new_obj = tf_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "TextFormat") == 0)
	{
		// Handle TextFormat constructor — new TextFormat(font?, size?, color?, bold?, italic?, underline?, align?, leftMargin?, rightMargin?, indent?, leading?)
		initTextFormatPrototype(app_context);
		ASObject* tf_obj = allocObject(app_context, 24);
		if (g_textformat_constructor.prototype_obj != NULL) {
			ActionVar proto_var = {0};
			proto_var.type = ACTION_STACK_VALUE_OBJECT;
			proto_var.data.numeric_value = (u64) g_textformat_constructor.prototype_obj;
			setProperty(app_context, tf_obj, "__proto__", 9, &proto_var);
			for (u32 i = 0; i < tf_obj->num_used; i++) {
				if (strcmp(tf_obj->properties[i].name, "__proto__") == 0) {
					tf_obj->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
					break;
				}
			}
		} else {
			setObjectProto(app_context, tf_obj);
		}
		// Initialize all properties to null, except display → "block"
		ActionVar null_val = {0};
		null_val.type = ACTION_STACK_VALUE_NULL;
		for (int i = 0; i < TF_PROP_COUNT; i++) {
			setProperty(app_context, tf_obj, tf_prop_names[i], tf_prop_lens[i], &null_val);
		}
		{
			ActionVar display_val = {0};
			display_val.type = ACTION_STACK_VALUE_STRING;
			display_val.data.numeric_value = (u64) u16_block;
			display_val.str_size = 5;
			setProperty(app_context, tf_obj, "display", 7, &display_val);
		}
		// Apply constructor arguments (0-13 args) with constructor-specific coercion:
		// Args: font, size, color, bold, italic, underline, url, target, align, leftMargin, rightMargin, indent, leading
		// - font: store raw value, truncate if string > 64 chars
		// - url/target: store raw value (no truncation)
		// - size/indent/leading/leftMargin/rightMargin: truncate toward zero (no banker's rounding, no non-neg clamp)
		// - color: uint32
		// - bold/italic/underline: boolean
		// - align: validate string
		static const char* ctor_arg_names[] = {
			"font", "size", "color", "bold", "italic", "underline",
			"url", "target", "align", "leftMargin", "rightMargin", "indent", "leading"
		};
		static const u32 ctor_arg_lens[] = { 4, 4, 5, 4, 6, 9, 3, 6, 5, 10, 11, 6, 7 };
		// Constructor coercion: 0=raw+truncate(font), 1=truncInt, 2=uint32, 3=bool, 4=align, 5=raw(url/target)
		static const int ctor_coerce[] = { 0, 1, 2, 3, 3, 3, 5, 5, 4, 1, 1, 1, 1 };
		for (u32 i = 0; i < num_args && i < 13; i++) {
			if (args[i].type == ACTION_STACK_VALUE_NULL || args[i].type == ACTION_STACK_VALUE_UNDEFINED) {
				// null/undefined → null (keep the initialized null)
				continue;
			}
			ActionVar coerced = args[i]; // default: store raw
			switch (ctor_coerce[i]) {
				case 0: // raw (font) — truncate if string and > 64 chars
					if (coerced.type == ACTION_STACK_VALUE_STRING && coerced.str_size > TF_FONT_MAX_LENGTH) {
						const uint16_t* _ctor_trunc_u16 = varGetU16Ptr(&coerced);
						uint16_t* truncated = (uint16_t*) malloc((TF_FONT_MAX_LENGTH + 1) * sizeof(uint16_t));
						memcpy(truncated, _ctor_trunc_u16, TF_FONT_MAX_LENGTH * sizeof(uint16_t));
						truncated[TF_FONT_MAX_LENGTH] = 0;
						coerced.data.numeric_value = (u64) truncated;
						coerced.str_size = TF_FONT_MAX_LENGTH;
					}
					break;
				case 5: // raw (url/target) — no truncation
					break;
				case 1: { // truncate toward zero (size, margins, indent, leading)
					double d = 0;
					if (args[i].type == ACTION_STACK_VALUE_F64)
						d = VAL(double, &args[i].data.numeric_value);
					else if (args[i].type == ACTION_STACK_VALUE_F32)
						d = (double) VAL(float, &args[i].data.numeric_value);
					else if (args[i].type == ACTION_STACK_VALUE_BOOLEAN)
						d = args[i].data.numeric_value ? 1.0 : 0.0;
					else if (args[i].type == ACTION_STACK_VALUE_STRING) {
						char _ctor_atof_buf[512];
						const uint16_t* _ctor_atof_u16 = varGetU16Ptr(&args[i]);
						u16_to_utf8(_ctor_atof_u16, args[i].str_size, _ctor_atof_buf, sizeof(_ctor_atof_buf));
						d = atof(_ctor_atof_buf);
					}
					else break; // non-numeric → store raw
					// Truncate toward zero
					if (d != d || d == (1.0/0.0) || d == -(1.0/0.0)) {
						// NaN/Inf → -2147483648
						double v = -2147483648.0;
						coerced.type = ACTION_STACK_VALUE_F64;
						coerced.data.numeric_value = VAL(u64, &v);
					} else {
						double v = (d >= 0) ? floor(d) : -floor(-d);
						coerced.type = ACTION_STACK_VALUE_F64;
						coerced.data.numeric_value = VAL(u64, &v);
					}
					break;
				}
				case 2: // uint32
					coerced = tfCoerceUnsigned(app_context, &args[i]);
					break;
				case 3: // boolean
					coerced = tfCoerceBoolean(app_context, &args[i]);
					break;
				case 4: // align
					coerced = tfCoerceAlign(app_context, &args[i], tf_obj);
					if (coerced.type == 255) continue; // invalid → keep null
					break;
			}
			setProperty(app_context, tf_obj, ctor_arg_names[i], ctor_arg_lens[i], &coerced);
		}
		new_obj = tf_obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		return;
	}
	else if (strcmp(ctor_name, "XML") == 0)
	{
		// Handle XML constructor — new XML(source?)
		initXMLPrototype(app_context);
		ASObject* xml_doc = xml_create_document(app_context);
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			char _xml_ctor_buf[4096];
			const uint16_t* _xml_ctor_u16 = varGetU16Ptr(&args[0]);
			u16_to_utf8(_xml_ctor_u16, args[0].str_size, _xml_ctor_buf, sizeof(_xml_ctor_buf));
			u32 src_len = (u32)strlen(_xml_ctor_buf);
			xml_parse_into(app_context, xml_doc, _xml_ctor_buf, src_len);
		}
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) xml_doc);
		return;
	}
	else if (strcmp(ctor_name, "XMLNode") == 0)
	{
		// Handle XMLNode constructor — new XMLNode(type, value)
		initXMLPrototype(app_context);
		int nodeType = 1; // default element
		const char* nodeValue = "";
		u32 nodeValueLen = 0;
		if (num_args > 0)
		{
			double d = varToDoubleSimple(&args[0]);
			nodeType = (int)d;
		}
		if (num_args > 1 && args[1].type == ACTION_STACK_VALUE_STRING)
		{
			{
				static char _xmlnode_val_buf[512];
				const uint16_t* _xmlnode_val_u16 = varGetU16Ptr(&args[1]);
				u16_to_utf8(_xmlnode_val_u16, args[1].str_size, _xmlnode_val_buf, sizeof(_xmlnode_val_buf));
				nodeValue = _xmlnode_val_buf;
				nodeValueLen = (u32)strlen(nodeValue);
			}
		}
		else if (num_args > 1)
		{
			// Convert non-string arg to string
			double d2 = varToDoubleSimple(&args[1]);
			static char nbuf[64];
			snprintf(nbuf, sizeof(nbuf), "%g", d2);
			nodeValue = nbuf;
			nodeValueLen = (u32)strlen(nbuf);
		}
		const char* nodeName = NULL;
		u32 nodeNameLen = 0;
		if (nodeType == 1)
		{
			// Element node: value is nodeName
			nodeName = nodeValue;
			nodeNameLen = nodeValueLen;
			nodeValue = NULL;
			nodeValueLen = 0;
		}
		ASObject* node = xml_create_node(app_context, nodeType, nodeName, nodeNameLen, nodeValue, nodeValueLen);
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64) node);
		return;
	}
	else if (strcmp(ctor_name, "Color") == 0)
	{
		// AVM1 Color object: new Color(mc)
		initColorPrototype(app_context);
		ASObject* color_obj = allocObject(app_context, 4);
		// Set __proto__ to Color.prototype
		ActionVar proto_var = {0};
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.data.numeric_value = (u64)g_color_prototype;
		setProperty(app_context, color_obj, "__proto__", 9, &proto_var);
		// Mark __proto__ as non-enumerable
		for (u32 _pi = 0; _pi < color_obj->num_used; _pi++)
		{
			if (color_obj->properties[_pi].name_length == 9 &&
			    strncmp(color_obj->properties[_pi].name, "__proto__", 9) == 0)
			{
				color_obj->properties[_pi].flags &= ~PROPERTY_FLAG_ENUMERABLE;
				break;
			}
		}
		retainObject(g_color_prototype);
		// Call constructor to initialize properties
		colorConstructor(app_context, args, num_args, NULL, color_obj);
		PUSH(ACTION_STACK_VALUE_OBJECT, (u64)color_obj);
		return;
	}
		else
	{
		// Try to find user-defined constructor function
		// First check function registry, then _global object properties, then global variable table
		ASFunction* ctor_func = lookupFunctionByName(ctor_name, ctor_name_len);
		if (ctor_func == NULL)
		{
			// Check _global object for constructor (MTASC classes store constructors here)
			extern ASObject* global_object;
			if (global_object != NULL)
			{
				ActionVar* gvar = getProperty(global_object, ctor_name, ctor_name_len);
				if (gvar != NULL && gvar->type == ACTION_STACK_VALUE_FUNCTION)
					ctor_func = (ASFunction*) gvar->data.numeric_value;
			}
		}
		if (ctor_func == NULL)
		{
			// Check global variable table (for functions stored via DefineLocal/SetVariable)
			// Try var_array first (O(1) by string_id), then hashmap fallback
			if (ctor_name_var.string_id != 0)
			{
				ActionVar* gvar = getVariableById(ctor_name_var.string_id);
				if (gvar != NULL && gvar->type == ACTION_STACK_VALUE_FUNCTION)
					ctor_func = (ASFunction*) gvar->data.numeric_value;
			}
			if (ctor_func == NULL)
			{
				ActionVar* gvar = getVariable(ctor_name, ctor_name_len);
				if (gvar != NULL && gvar->type == ACTION_STACK_VALUE_FUNCTION)
					ctor_func = (ASFunction*) gvar->data.numeric_value;
			}
		}

		if (ctor_func != NULL)
		{
			// User-defined constructor found
			// Create new object to serve as 'this'
			ASObject* obj = allocObject(app_context, 8);
			new_obj = obj;

			// Set __proto__ to constructor's prototype (for prototype chain inheritance)
			// Lazily create prototype if it doesn't exist yet
			if (ctor_func->prototype_obj == NULL)
			{
				ctor_func->prototype_obj = allocObject(app_context, 4);
				retainObject(ctor_func->prototype_obj);
				setObjectProto(app_context, ctor_func->prototype_obj);
				// Set constructor property pointing back to the function
				ActionVar ctor_var;
				ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
				ctor_var.str_size = 0;
				ctor_var.data.numeric_value = (u64) ctor_func;
				setProperty(app_context, ctor_func->prototype_obj, "constructor", 11, &ctor_var);
			}
			{
				ActionVar proto_var;
				proto_var.type = ACTION_STACK_VALUE_OBJECT;
				proto_var.str_size = 0;
				proto_var.data.numeric_value = (u64) ctor_func->prototype_obj;
				setProperty(app_context, obj, "__proto__", 9, &proto_var);
			}

			// SWF6 and below: set constructor directly on each instance
			if (g_swf_version < 7) {
				ActionVar ctor_inst_var;
				ctor_inst_var.type = ACTION_STACK_VALUE_FUNCTION;
				ctor_inst_var.str_size = 0;
				ctor_inst_var.data.numeric_value = (u64) ctor_func;
				setProperty(app_context, obj, "constructor", 11, &ctor_inst_var);
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
	g_scope_app_context = app_context;
	// Pop in order: method_name, object, num_args, then args

	// 1. Pop method name (string)
	char str_buffer[17];
	convertString(app_context, str_buffer);
	char _nm_buf[512];
	u32 method_name_len = (u32)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _nm_buf, sizeof(_nm_buf));
	const char* method_name = _nm_buf;
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

				// Set up prototype chain (new_obj.__proto__ = func.prototype)
				if (func->prototype_obj == NULL)
				{
					func->prototype_obj = allocObject(app_context, 4);
					retainObject(func->prototype_obj);
					setObjectProto(app_context, func->prototype_obj);
					ActionVar ctor_pv;
					ctor_pv.type = ACTION_STACK_VALUE_FUNCTION;
					ctor_pv.str_size = 0;
					ctor_pv.data.numeric_value = (u64) func;
					setProperty(app_context, func->prototype_obj, "constructor", 11, &ctor_pv);
				}
				{
					ActionVar proto_pv;
					proto_pv.type = ACTION_STACK_VALUE_OBJECT;
					proto_pv.str_size = 0;
					proto_pv.data.numeric_value = (u64) func->prototype_obj;
					setProperty(app_context, new_obj, "__proto__", 9, &proto_pv);
				}
				if (g_swf_version < 7) {
					ActionVar ctor_iv;
					ctor_iv.type = ACTION_STACK_VALUE_FUNCTION;
					ctor_iv.str_size = 0;
					ctor_iv.data.numeric_value = (u64) func;
					setProperty(app_context, new_obj, "constructor", 11, &ctor_iv);
				}

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
						scope_is_with[scope_depth] = 0;
						scope_mc[scope_depth] = NULL;
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
					static char ctor_name_buf[256];
					const uint16_t* u16 = varGetU16Ptr(method_prop);
					u16_to_utf8(u16, method_prop->str_size, ctor_name_buf, sizeof(ctor_name_buf));
					ctor_name = ctor_name_buf;
				}
				else if (method_prop->type == ACTION_STACK_VALUE_FUNCTION)
				{
					ASFunction* mfunc = (ASFunction*) method_prop->data.numeric_value;
					if (mfunc != NULL && mfunc->name[0] != '\0' && mfunc->simple_func == NULL && mfunc->advanced_func == NULL)
					{
						// Built-in constructor stub (registered on _global) — use name for dispatch
						ctor_name = mfunc->name;
					}
					else
					{
						// User-defined function - use it as constructor
						user_ctor_func = mfunc;
					}
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
			// Flash stores length as u32 via ToInt32, negative values wrap (e.g. -1 → 0xFFFFFFFF)
			double length_d = (args[0].type == ACTION_STACK_VALUE_F32) ?
				(double) VAL(float, &args[0].data.numeric_value) :
				VAL(double, &args[0].data.numeric_value);
			u32 length = (u32) ecmaToInt32(length_d);
			int32_t signed_len = (int32_t) length;
			u32 alloc_size = 0;
			if (signed_len > 0)
				alloc_size = (u32)signed_len < 1000000 ? (u32)signed_len : 1000000;
			ASArray* arr = allocArray(app_context, alloc_size > 0 ? alloc_size : 4);
			// new Array(n): elements stay as HOLE (don't enumerate, but join as "undefined")
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
		if (num_args > 0 && args[0].type != ACTION_STACK_VALUE_UNDEFINED && args[0].type != ACTION_STACK_VALUE_NULL)
		{
			// new Object(value) returns the value coerced to object
			// For strings/numbers, Flash returns the primitive itself
			pushVar(app_context, &args[0]);
		}
		else
		{
			ASObject* obj = allocObject(app_context, 8);
			new_obj = obj;
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
		}
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Date") == 0)
	{
		ASObject* date = date_construct(app_context, args, num_args);
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
			empty_str.data.numeric_value = (u64) u16_empty;
			setProperty(app_context, str_obj, "valueOf", 7, &empty_str);
		}

		// Set length property (DontEnum, DontDelete = writable only)
		{
			u32 slen = 0;
			if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
				slen = args[0].str_size;
			double slen_d = (double) slen;
			ActionVar len_var = {0};
			len_var.type = ACTION_STACK_VALUE_F64;
			VAL(double, &len_var.data.numeric_value) = slen_d;
			setPropertyWithFlags(app_context, str_obj, "length", 6, &len_var, PROPERTY_FLAG_WRITABLE);
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
					char tmp[256];
					const uint16_t* u16 = varGetU16Ptr(&num_value);
					u16_to_utf8(u16, num_value.str_size, tmp, sizeof(tmp));
					float fval = (float) atof(tmp);
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
				truthy = (args[0].str_size > 0);
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
	else if (ctor_name != NULL && strcmp(ctor_name, "BitmapData") == 0)
	{
		// Handle flash.display.BitmapData constructor
		// BitmapData(width, height) — validates dimensions, returns object or undefined
		if (num_args >= 2)
		{
			double w = varToDouble(&args[0]);
			double h = varToDouble(&args[1]);
			bool valid = false;
			if (g_swf_version >= 10)
				valid = (w >= 1 && w <= 8191 && h >= 1 && h <= 8191 && w * h <= 16777215);
			else
				valid = (w >= 1 && w <= 2880 && h >= 1 && h <= 2880);
			if (valid)
			{
				ASObject* bmp = allocObject(app_context, 4);
				setObjectProto(app_context, bmp);
				// Store width/height as properties
				ActionVar wv = {0}; wv.type = ACTION_STACK_VALUE_F64;
				VAL(double, &wv.data.numeric_value) = w;
				setProperty(app_context, bmp, "width", 5, &wv);
				VAL(double, &wv.data.numeric_value) = h;
				setProperty(app_context, bmp, "height", 6, &wv);
				new_obj = bmp;
				PUSH(ACTION_STACK_VALUE_OBJECT, (u64) new_obj);
			}
			else
			{
				pushUndefined(app_context);
			}
		}
		else
		{
			pushUndefined(app_context);
		}
	}
	else if (ctor_name != NULL && strcmp(ctor_name, "Transform") == 0)
	{
		// new flash.geom.Transform(mc): wraps a MovieClip in a Transform object
		if (num_args >= 1 && args[0].type == ACTION_STACK_VALUE_MOVIECLIP)
		{
			MovieClip* mc = (MovieClip*) args[0].data.numeric_value;
			ASObject* tobj = createTransformObject(app_context, mc);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)tobj);
		}
		else
		{
			pushUndefined(app_context);
		}
	}
	else if (user_ctor_func != NULL)
	{
		// User-defined constructor function from object property
		// Create new object for 'this' context
		ASObject* new_obj_inst = allocObject(app_context, 8);

		// Set up prototype chain (new_obj.__proto__ = func.prototype)
		if (user_ctor_func->prototype_obj == NULL)
		{
			user_ctor_func->prototype_obj = allocObject(app_context, 4);
			retainObject(user_ctor_func->prototype_obj);
			setObjectProto(app_context, user_ctor_func->prototype_obj);
			ActionVar ctor_v;
			ctor_v.type = ACTION_STACK_VALUE_FUNCTION;
			ctor_v.str_size = 0;
			ctor_v.data.numeric_value = (u64) user_ctor_func;
			setProperty(app_context, user_ctor_func->prototype_obj, "constructor", 11, &ctor_v);
		}
		{
			ActionVar proto_v;
			proto_v.type = ACTION_STACK_VALUE_OBJECT;
			proto_v.str_size = 0;
			proto_v.data.numeric_value = (u64) user_ctor_func->prototype_obj;
			setProperty(app_context, new_obj_inst, "__proto__", 9, &proto_v);
		}

		// SWF6 and below: set constructor directly on each instance
		if (g_swf_version < 7) {
			ActionVar ctor_inst_v;
			ctor_inst_v.type = ACTION_STACK_VALUE_FUNCTION;
			ctor_inst_v.str_size = 0;
			ctor_inst_v.data.numeric_value = (u64) user_ctor_func;
			setProperty(app_context, new_obj_inst, "constructor", 11, &ctor_inst_v);
		}

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
				scope_is_with[scope_depth] = 0;
				scope_mc[scope_depth] = NULL;
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

	// 3. Pop target path (convert UTF-16 to char* for MovieClip lookup)
	convertString(app_context, NULL);
	char _sp_buf[512];
	(void)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _sp_buf, sizeof(_sp_buf));
	const char* target = _sp_buf;
	POP();

	// 4. Get the MovieClip object
	MovieClip* mc = getMovieClipByTarget(target);
	if (!mc) return; // Invalid target

	// 5. Set property value based on index
	// Convert value to float for numeric properties
	float num_value = 0.0f;

	if (value_var.type == ACTION_STACK_VALUE_F32) {
		num_value = VAL(float, &value_var.data.numeric_value);
	} else if (value_var.type == ACTION_STACK_VALUE_F64) {
		num_value = (float) VAL(double, &value_var.data.numeric_value);
	} else if (value_var.type == ACTION_STACK_VALUE_BOOLEAN) {
		num_value = value_var.data.numeric_value ? 1.0f : 0.0f;
	} else if (value_var.type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* _u16 = varGetU16Ptr(&value_var);
		char _sp_val_buf[256];
		if (_u16 && value_var.str_size > 0)
			u16_to_utf8(_u16, value_var.str_size, _sp_val_buf, sizeof(_sp_val_buf));
		else
			_sp_val_buf[0] = '\0';
		num_value = (float) atof(_sp_val_buf);
	}

	switch (prop_index) {
		case 0:  // _x
			mc->x = num_value;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 1;
#endif
			break;
		case 1:  // _y
			mc->y = num_value;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 2;
#endif
			break;
		case 2:  // _xscale
			mc->xscale = num_value;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 4;
#endif
			break;
		case 3:  // _yscale
			mc->yscale = num_value;
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 8;
#endif
			break;
		case 6:  // _alpha
			mc->alpha = num_value;
			break;
		case 7:  // _visible
			mc->visible = (num_value != 0.0f);
			break;
		case 8:  // _width
			mcSetEffectiveWidth(app_context, mc, (double)num_value);
			break;
		case 9:  // _height
			mcSetEffectiveHeight(app_context, mc, (double)num_value);
			break;
		case 10: // _rotation
			mc->rotation = normalizeRotation(num_value);
#ifdef NO_GRAPHICS
			mc->as_set_flags |= 16;
#endif
			break;
		case 13: // _name
			if (value_var.type == ACTION_STACK_VALUE_STRING) {
				const uint16_t* _nm_u16 = varGetU16Ptr(&value_var);
				char _nm_buf[256];
				if (_nm_u16 && value_var.str_size > 0)
					u16_to_utf8(_nm_u16, value_var.str_size, _nm_buf, sizeof(_nm_buf));
				else
					_nm_buf[0] = '\0';
				strncpy(mc->name, _nm_buf, sizeof(mc->name) - 1);
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

	// Pop source sprite name (2nd pop = new clone's instance name)
	ActionVar source;
	popVar(app_context, &source);
	char _clone_src_buf[512];
	const char* source_name = "";
	if (source.type == ACTION_STACK_VALUE_STRING && source.str_size > 0) {
		const uint16_t* _clone_src_u16 = varGetU16Ptr(&source);
		u16_to_utf8(_clone_src_u16, source.str_size, _clone_src_buf, sizeof(_clone_src_buf));
		source_name = _clone_src_buf;
	} else if ((source.type == ACTION_STACK_VALUE_OBJECT ||
	            source.type == ACTION_STACK_VALUE_FUNCTION) && source.data.numeric_value != 0) {
		// Object with toString method — call it to get the clone name
		ActionVar ts = objectCallToString(app_context, &source, NULL);
		if (ts.type == ACTION_STACK_VALUE_STRING && ts.str_size > 0) {
			const uint16_t* _ts_u16 = varGetU16Ptr(&ts);
			u16_to_utf8(_ts_u16, ts.str_size, _clone_src_buf, sizeof(_clone_src_buf));
			source_name = _clone_src_buf;
		}
	}

	// Pop target sprite name
	ActionVar target;
	popVar(app_context, &target);
	char _clone_tgt_buf[512];
	const char* target_name = "";
	if (target.type == ACTION_STACK_VALUE_STRING && target.str_size > 0) {
		const uint16_t* _clone_tgt_u16 = varGetU16Ptr(&target);
		u16_to_utf8(_clone_tgt_u16, target.str_size, _clone_tgt_buf, sizeof(_clone_tgt_buf));
		target_name = _clone_tgt_buf;
	}

	#ifndef NO_GRAPHICS
	// Full implementation would:
	// 1. Find source MovieClip in display list
	// 2. Create deep copy of sprite and its children
	// 3. Add to display list at specified depth
	// 4. Assign new name
	cloneMovieClip(source_name, target_name, (int)VAL(float, &depth.data.numeric_value));
	#else
	{
		int depth_int = ecmaToInt32(VAL(double, &depth.data.numeric_value));
		// AVM1 stack naming is inverted from the SWF spec naming:
		//   source ActionVar (2nd pop) = new clone name (e.g., "clip1")
		//   target ActionVar (3rd pop) = existing clip to clone from (src MC or path string)
		const char* new_name = source_name;  // new clone's instance name
		// Strip path prefix from new name
		if (strncmp(new_name, "_root.", 6) == 0) new_name += 6;
		else if (strncmp(new_name, "_level0.", 8) == 0) new_name += 8;
		if (target.type == ACTION_STACK_VALUE_MOVIECLIP && target.data.numeric_value != 0) {
			// Source clip already resolved as MovieClip
			MovieClip* src_mc = (MovieClip*)(uintptr_t)target.data.numeric_value;
			ng_cloneSpriteFromMC(app_context, src_mc, new_name, depth_int);
		} else {
			// Source is a string path — look up in ng_display
			const char* src_path = target_name;
			if (strncmp(src_path, "_root.", 6) == 0) src_path += 6;
			else if (strncmp(src_path, "_level0.", 8) == 0) src_path += 8;
			ng_cloneSprite(app_context, src_path, new_name, depth_int);
		}
	}
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
	char _remove_tgt_buf[512];
	const char* target_name = "";
	if (target.type == ACTION_STACK_VALUE_STRING && target.str_size > 0) {
		const uint16_t* _remove_tgt_u16 = varGetU16Ptr(&target);
		u16_to_utf8(_remove_tgt_u16, target.str_size, _remove_tgt_buf, sizeof(_remove_tgt_buf));
		target_name = _remove_tgt_buf;
	} else if (target.type == ACTION_STACK_VALUE_MOVIECLIP && target.data.numeric_value != 0) {
		// MovieClip reference: use its name directly
		MovieClip* _rs_target_mc = (MovieClip*)(uintptr_t)target.data.numeric_value;
		target_name = _rs_target_mc->name;
	}

	// Handle null/empty gracefully
	if (target_name[0] == '\0') {
		return;
	}

	#ifndef NO_GRAPHICS
	#ifdef DEBUG
	printf("[RemoveSprite] Graphics mode stub: would remove %s\n", target_name);
	#endif
	#else
	// NO_GRAPHICS mode: find the clip by name and remove it if dynamically created
	{
		MovieClip* _rs_mc = NULL;
		for (int _rs_i = 0; _rs_i < child_mc_count; _rs_i++) {
			if (child_mc_cache[_rs_i] != NULL &&
			    strcmp(child_mc_cache[_rs_i]->name, target_name) == 0) {
				_rs_mc = child_mc_cache[_rs_i];
				break;
			}
		}
		// Only clips at removable AS depths [0, 2130690032) can be removed.
		#ifndef AVM_MAX_REMOVE_DEPTH
		#define AVM_MAX_REMOVE_DEPTH 2130690032
		#endif
		if (_rs_mc != NULL && _rs_mc->depth >= 0 && _rs_mc->depth < AVM_MAX_REMOVE_DEPTH) {
			// Queue AS-set onUnload handler for deferred firing at ShowFrame
			if (_rs_mc->dynamic_props != NULL) {
				ActionVar* _rs_handler = getProperty((ASObject*)_rs_mc->dynamic_props, "onUnload", 8);
				if (_rs_handler != NULL && _rs_handler->type == ACTION_STACK_VALUE_FUNCTION) {
					ASFunction* _rs_func = (ASFunction*) _rs_handler->data.numeric_value;
					if (_rs_func != NULL)
						queueOnUnload(_rs_func, _rs_mc);
				}
			}
			// Clear from parent's dynamic_props
			MovieClip* _rs_parent = _rs_mc->parent ? _rs_mc->parent : &root_movieclip;
			if (_rs_parent->dynamic_props != NULL && _rs_mc->name[0]) {
				ActionVar _rs_undef = {0};
				_rs_undef.type = ACTION_STACK_VALUE_UNDEFINED;
				setProperty(app_context, (ASObject*)_rs_parent->dynamic_props,
				            _rs_mc->name, strlen(_rs_mc->name), &_rs_undef);
			}
			// Also clear from root-level variable table (set by createEmptyMovieClip)
			if (_rs_mc->name[0]) {
				ActionVar _rs_undef = {0};
				_rs_undef.type = ACTION_STACK_VALUE_UNDEFINED;
				setVariableByName(_rs_mc->name, &_rs_undef);
			}
			// Mark as removed — keep dynamic_props intact until pending unload fires
			_rs_mc->depth = INT_MIN;
			for (int _rs_j = 0; _rs_j < child_mc_count; _rs_j++) {
				if (child_mc_cache[_rs_j] == _rs_mc) {
					child_mc_cache[_rs_j] = NULL;
					break;
				}
			}
		}
	}
	#endif
}

void actionSetTarget(SWFAppContext* app_context, const char* target_name)
{
#ifdef NO_GRAPHICS
	extern int g_settarget_explicit_root;
#endif
	// Empty string or NULL means return to main timeline
	if (!target_name || strlen(target_name) == 0) {
		setCurrentContext(&root_movieclip);
#ifdef NO_GRAPHICS
		g_settarget_explicit_root = 1;
#endif
#ifndef NO_GRAPHICS
		targeted_sprite = NULL;
#endif
		return;
	}

	// Check for _root
	if (strcmp(target_name, "_root") == 0 || strcmp(target_name, "/") == 0) {
		setCurrentContext(&root_movieclip);
#ifdef NO_GRAPHICS
		g_settarget_explicit_root = 1;
#endif
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
#ifdef NO_GRAPHICS
		g_settarget_explicit_root = 0;
#endif
		return;
	}

	// Try resolving as a child clip name (strip _level0. prefix if present)
	const char* child_name = target_name;
	if (strncmp(target_name, "_level0.", 8) == 0)
		child_name = target_name + 8;
	// Also strip leading slash for slash-path format (e.g., "/mc")
	if (child_name[0] == '/')
		child_name = child_name + 1;

#ifdef NO_GRAPHICS
	size_t child_depth = ng_findDisplayEntryByName(child_name);
	if (child_depth != SIZE_MAX) {
		MovieClip* child_mc = findOrCreateMovieClip(app_context, child_name, &root_movieclip);
		if (child_mc) {
			setCurrentContext(child_mc);
			g_settarget_explicit_root = 0;
			return;
		}
	}
#else
	{
		DisplayObject* dobj = findDisplayObjectByName(child_name);
		if (dobj != NULL) {
			MovieClip* child_mc = findOrCreateMovieClip(app_context, child_name, &root_movieclip);
			if (child_mc) {
				setCurrentContext(child_mc);
				targeted_sprite = dobj;
				return;
			}
		}
	}
#endif
}

// ==================================================================
// WITH Statement Implementation
// ==================================================================

// Helper: print a trace-style string directly (for error messages)
static void actionTrace_str(SWFAppContext* app_context, const char* msg)
{
	(void)app_context;
	fputs(msg, stdout);
}

// Helper: get a MovieClip built-in property by name into result.
// Returns 1 if property was found, 0 otherwise.
static int getMCBuiltinProperty(MovieClip* mc, const char* name, u32 name_len, ActionVar* result)
{
	if (name_len < 2 || name[0] != '_') return 0;

	result->str_size = 0;
	result->data.numeric_value = 0;

	if (strcasecmp(name, "_x") == 0) { float v = mc->x; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_y") == 0) { float v = mc->y; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_xscale") == 0) { float v = mc->xscale; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_yscale") == 0) { float v = mc->yscale; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_rotation") == 0) { float v = mc->rotation; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_alpha") == 0) { float v = mc->alpha; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_visible") == 0) { result->type = ACTION_STACK_VALUE_BOOLEAN; result->data.numeric_value = mc->visible ? 1 : 0; return 1; }
	if (strcasecmp(name, "_width") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); result->type = ACTION_STACK_VALUE_F64; memcpy(&result->data.numeric_value, &_ew, 8); return 1; }
	if (strcasecmp(name, "_height") == 0) { double _ew, _eh; mcGetEffectiveSize(mc, &_ew, &_eh); result->type = ACTION_STACK_VALUE_F64; memcpy(&result->data.numeric_value, &_eh, 8); return 1; }
	if (strcasecmp(name, "_currentframe") == 0) { float v = (float)mc->currentframe; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_totalframes") == 0) { float v = (float)mc->totalframes; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_framesloaded") == 0) { float v = (float)mc->framesloaded; result->type = ACTION_STACK_VALUE_F32; memcpy(&result->data.numeric_value, &v, 4); return 1; }
	if (strcasecmp(name, "_name") == 0) { result->type = ACTION_STACK_VALUE_STRING; /* caller must handle string push */ return 2; }
	if (strcasecmp(name, "_target") == 0) { result->type = ACTION_STACK_VALUE_STRING; return 3; }
	return 0;
}

// Helper: set a MovieClip built-in property by name.
// Returns 1 if property was handled, 0 otherwise.
static int setMCBuiltinProperty(SWFAppContext* app_context, MovieClip* mc, const char* name, u32 name_len, ActionVar* value)
{
	if (name_len < 2 || name[0] != '_') return 0;

	double dval = varToDoubleSimple(value);
	float fval = (float)dval;

	if (strcasecmp(name, "_x") == 0) {
#ifdef NO_GRAPHICS
		mc->as_set_flags |= 1;
#endif
		mc->x = fval; return 1;
	}
	if (strcasecmp(name, "_y") == 0) {
#ifdef NO_GRAPHICS
		mc->as_set_flags |= 2;
#endif
		mc->y = fval; return 1;
	}
	if (strcasecmp(name, "_xscale") == 0) {
#ifdef NO_GRAPHICS
		mc->as_set_flags |= 4;
#endif
		mc->xscale = fval; return 1;
	}
	if (strcasecmp(name, "_yscale") == 0) {
#ifdef NO_GRAPHICS
		mc->as_set_flags |= 8;
#endif
		mc->yscale = fval; return 1;
	}
	if (strcasecmp(name, "_rotation") == 0) {
#ifdef NO_GRAPHICS
		mc->as_set_flags |= 16;
#endif
		mc->rotation = normalizeRotation(fval); return 1;
	}
	if (strcasecmp(name, "_alpha") == 0) { mc->alpha = fval; return 1; }
	if (strcasecmp(name, "_visible") == 0) { mc->visible = (fval != 0.0f) ? 1 : 0; return 1; }
	if (strcasecmp(name, "_width") == 0) { mcSetEffectiveWidth(app_context, mc, (double)fval); return 1; }
	if (strcasecmp(name, "_height") == 0) { mcSetEffectiveHeight(app_context, mc, (double)fval); return 1; }
	return 0;
}

int actionWithStart(SWFAppContext* app_context)
{
	// Pop object from stack
	ActionVar obj_var;
	popVar(app_context, &obj_var);

	if (scope_depth >= MAX_SCOPE_DEPTH)
	{
		fprintf(stderr, "ERROR: Scope chain overflow (depth=%u, max=%u)\n", scope_depth, MAX_SCOPE_DEPTH);
		return 0;
	}

	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;
		if (obj != NULL)
		{
			scope_is_with[scope_depth] = 1;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = obj;
			return 1;
		}
		// NULL object pointer — skip body
		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = NULL;
		actionTrace_str(app_context, "Error: A 'with' action failed because the specified object did not exist.\n\n");
		return 0;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;
		if (mc != NULL)
		{
			// Ensure mc has dynamic_props allocated
			if (mc->dynamic_props == NULL)
			{
				mc->dynamic_props = (void*) allocObject(app_context, 8);
			}
			scope_is_with[scope_depth] = 1;
			scope_mc[scope_depth] = mc;
			scope_chain[scope_depth++] = (ASObject*) mc->dynamic_props;
			return 1;
		}
		// NULL MC pointer — skip body
		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = NULL;
		actionTrace_str(app_context, "Error: A 'with' action failed because the specified object did not exist.\n\n");
		return 0;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		// Functions are objects in Flash — push onto scope chain
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;
		if (func != NULL && func->own_props != NULL)
		{
			scope_is_with[scope_depth] = 1;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = func->own_props;
			return 1;
		}
		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = NULL;
		return 0;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_UNDEFINED || obj_var.type == ACTION_STACK_VALUE_NULL)
	{
		// undefined/null — skip body and print error
		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = NULL;
		actionTrace_str(app_context, "Error: A 'with' action failed because the specified object did not exist.\n\n");
		return 0;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// Wrap string primitive in a String object for WITH scope
		ASObject* str_obj = allocObject(app_context, 4);
		// Set valueOf so toString/valueOf can retrieve the string
		setPropertyWithFlags(app_context, str_obj, "valueOf", 7, &obj_var, PROPERTY_FLAGS_DONTENUM);
		// Set length property
		double slen = (double)obj_var.str_size;
		ActionVar len_var = {0};
		len_var.type = ACTION_STACK_VALUE_F64;
		VAL(double, &len_var.data.numeric_value) = slen;
		setPropertyWithFlags(app_context, str_obj, "length", 6, &len_var, PROPERTY_FLAG_WRITABLE);

		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = str_obj;
		return 1;
	}
	else
	{
		// Non-object type (number, boolean) — push null marker
		scope_is_with[scope_depth] = 1;
		scope_mc[scope_depth] = NULL;
		scope_chain[scope_depth++] = NULL;
		return 1;  // body still executes, just no scope object
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

#include <setjmp.h>

#define MAX_EXCEPTION_DEPTH 16

typedef struct {
	jmp_buf handler;
	int has_jmp_buf;
	u32 saved_scope_depth;
} ExceptionFrame;

typedef struct {
	ExceptionFrame frames[MAX_EXCEPTION_DEPTH];
	int depth;

	bool exception_thrown;
	ActionVar exception_value;

	bool return_pending;
	ActionVar return_value;
} ExceptionState;

static ExceptionState g_exception_state = {0};

static void uncaughtException(ActionVar* throw_value)
{
	printf("Warning: Uncaught exception, ");

	if (throw_value->type == ACTION_STACK_VALUE_STRING) {
		const uint16_t* u16 = varGetU16Ptr(throw_value);
		char _thr_buf[512];
		if (u16 && throw_value->str_size > 0)
			u16_to_utf8(u16, throw_value->str_size, _thr_buf, sizeof(_thr_buf));
		else
			_thr_buf[0] = '\0';
		printf("%s", _thr_buf);
	} else if (throw_value->type == ACTION_STACK_VALUE_F32) {
		float val = VAL(float, &throw_value->data.numeric_value);
		printf("%g", val);
	} else if (throw_value->type == ACTION_STACK_VALUE_F64) {
		double val = VAL(double, &throw_value->data.numeric_value);
		printf("%g", val);
	} else {
		printf("(type %d)", throw_value->type);
	}

	printf("\n");
	g_execution_halted = 1;
}

void actionThrow(SWFAppContext* app_context)
{
	ActionVar throw_value;
	popVar(app_context, &throw_value);

	g_exception_state.exception_thrown = true;
	g_exception_state.exception_value = throw_value;

	// Search handler stack top-down for an active handler
	for (int i = g_exception_state.depth - 1; i >= 0; i--) {
		if (g_exception_state.frames[i].has_jmp_buf) {
			// Set depth to this frame's level (skip intermediate frames)
			g_exception_state.depth = i + 1;
			longjmp(g_exception_state.frames[i].handler, 1);
		}
	}

	// No active handler found — uncaught exception
	uncaughtException(&throw_value);
}

void actionThrowPending(SWFAppContext* app_context)
{
	// Set exception as pending without longjmp — used for throw inside catch
	// when there's a finally block that needs to run first
	ActionVar throw_value;
	popVar(app_context, &throw_value);
	g_exception_state.exception_thrown = true;
	g_exception_state.exception_value = throw_value;
}

void actionTryBegin(SWFAppContext* app_context)
{
	if (g_exception_state.depth >= MAX_EXCEPTION_DEPTH) {
		fprintf(stderr, "ERROR: Exception handler stack overflow\n");
		return;
	}
	g_exception_state.frames[g_exception_state.depth].has_jmp_buf = 0;
	g_exception_state.frames[g_exception_state.depth].saved_scope_depth = scope_depth;
	g_exception_state.depth++;
}

jmp_buf* actionGetExceptionJmpBuf(SWFAppContext* app_context)
{
	int idx = g_exception_state.depth - 1;
	if (idx < 0) idx = 0;
	g_exception_state.frames[idx].has_jmp_buf = 1;
	return &g_exception_state.frames[idx].handler;
}

void actionCatchEnter(SWFAppContext* app_context)
{
	// Disable current handler so a throw inside catch propagates to parent
	int idx = g_exception_state.depth - 1;
	if (idx >= 0) {
		g_exception_state.frames[idx].has_jmp_buf = 0;
		// Restore scope_depth to what it was when the try block started.
		// longjmp() does not restore C global state, so any scope_chain pushes
		// that happened between setjmp and throw (e.g. from actionCallFunction
		// for a function that threw) leave scope_depth incorrect. Restoring here
		// prevents use-after-free when searching stale scope_chain entries.
		scope_depth = g_exception_state.frames[idx].saved_scope_depth;
	}
}

void actionCatchToVariable(SWFAppContext* app_context, const char* var_name)
{
	if (g_exception_state.exception_thrown)
	{
		setVariableByName(var_name, &g_exception_state.exception_value);
		g_exception_state.exception_thrown = false;
	}
}

void actionCatchToRegister(SWFAppContext* app_context, u8 reg_num)
{
	if (g_exception_state.exception_thrown)
	{
		if (reg_num >= MAX_REGISTERS) {
			fprintf(stderr, "ERROR: Invalid register number %d for catch\n", reg_num);
			g_exception_state.exception_thrown = false;
			return;
		}
		g_registers[reg_num] = g_exception_state.exception_value;
		g_exception_state.exception_thrown = false;
	}
}

void actionCatchGetException(SWFAppContext* app_context, ActionVar* out)
{
	if (g_exception_state.exception_thrown)
	{
		*out = g_exception_state.exception_value;
		g_exception_state.exception_thrown = false;
	}
	else
	{
		out->type = ACTION_STACK_VALUE_UNDEFINED;
		out->data.numeric_value = 0;
	}
}

void actionTryEnd(SWFAppContext* app_context)
{
	if (g_exception_state.depth > 0) {
		g_exception_state.depth--;
	}

	if (g_exception_state.exception_thrown) {
		// Exception still pending after finally — re-propagate to parent handler
		for (int i = g_exception_state.depth - 1; i >= 0; i--) {
			if (g_exception_state.frames[i].has_jmp_buf) {
				longjmp(g_exception_state.frames[i].handler, 1);
			}
		}
		// No parent handler — uncaught
		uncaughtException(&g_exception_state.exception_value);
	}
}

bool actionExceptionPending(SWFAppContext* app_context)
{
	return g_exception_state.exception_thrown;
}

void actionSetReturnPending(SWFAppContext* app_context, ActionVar* value)
{
	g_exception_state.return_pending = true;
	g_exception_state.return_value = *value;
}

bool actionReturnPending(SWFAppContext* app_context)
{
	return g_exception_state.return_pending;
}

ActionVar actionGetPendingReturn(SWFAppContext* app_context)
{
	g_exception_state.return_pending = false;
	return g_exception_state.return_value;
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
	as_func->own_props = NULL;

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
	as_func->own_props = NULL;
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
	g_scope_app_context = app_context;

	// 1. Pop function name (string) from stack
	char func_name_buffer[17];
	convertString(app_context, func_name_buffer);
	char _cf_buf[512];
	u32 func_name_len = (u32)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _cf_buf, sizeof(_cf_buf));
	const char* func_name = _cf_buf;
	u32 func_name_string_id = STACK_TOP_ID;  // Preserve string_id for var_array lookup
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

	// parseInt(string [, radix]) - Parse string to integer (Flash/ECMA-262 semantics)
	if (func_name_len == 8 && strncmp(func_name, "parseInt", 8) == 0)
	{
		if (num_args == 0)
		{
			// ECMA-262 violation: parseInt() returns undefined, not NaN
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			builtin_handled = 1;
		}
		else
		{
			// Convert first argument to string
			char _pi_buf[1024];
			const char* str_value = NULL;

			if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				const uint16_t* _pi_u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(_pi_u16, args[0].str_size, _pi_buf, sizeof(_pi_buf));
				str_value = _pi_buf;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F32)
			{
				float fval = VAL(float, &args[0].data.numeric_value);
				snprintf(_pi_buf, sizeof(_pi_buf), "%.15g", fval);
				str_value = _pi_buf;
			}
			else if (args[0].type == ACTION_STACK_VALUE_F64)
			{
				double dval = VAL(double, &args[0].data.numeric_value);
				snprintf(_pi_buf, sizeof(_pi_buf), "%.15g", dval);
				str_value = _pi_buf;
			}
			else if (args[0].type == ACTION_STACK_VALUE_BOOLEAN)
			{
				str_value = args[0].data.numeric_value ? "true" : "false";
			}
			else if (args[0].type == ACTION_STACK_VALUE_NULL)
			{
				str_value = "null";
			}
			else
			{
				str_value = "undefined";
			}

			// Determine radix
			int has_explicit_radix = (num_args >= 2);
			int radix = 0; // 0 = auto-detect
			int radix_valid = 1;
			if (has_explicit_radix)
			{
				double rv = 0.0;
				if (args[1].type == ACTION_STACK_VALUE_F32)
					rv = (double)VAL(float, &args[1].data.numeric_value);
				else if (args[1].type == ACTION_STACK_VALUE_F64)
					rv = VAL(double, &args[1].data.numeric_value);
				else if (args[1].type == ACTION_STACK_VALUE_BOOLEAN)
					rv = args[1].data.numeric_value ? 1.0 : 0.0;
				else
					rv = 0.0; // undefined, null, string, object → 0
				// Truncate to int32 (not round)
				if (rv != rv || rv == 0.0) // NaN or zero
					radix = 0;
				else
					radix = (int)rv;
				if (radix < 2 || radix > 36) radix_valid = 0;
			}

			double result = 0.0 / 0.0; // NaN
			if (radix_valid)
			{
				const char* s = str_value;
				int slen = (int)strlen(s);

				// Check for sign at position 0
				int has_sign = (slen > 0 && (s[0] == '+' || s[0] == '-'));
				int sign_off = has_sign ? 1 : 0;

				// Check for 0x/0X after optional sign
				int is_hex = 0;
				if (sign_off < slen && s[sign_off] == '0' &&
				    sign_off + 1 < slen && (s[sign_off + 1] == 'x' || s[sign_off + 1] == 'X'))
				{
					is_hex = 1;
				}

				int ignore_sign = 0;
				const char* parse_start = s;
				int parse_radix = radix ? radix : 10;

				if (is_hex)
				{
					if (has_sign)
					{
						// Sign before 0x: Flash-specific behavior
						if (!has_explicit_radix || parse_radix <= 33)
						{
							// No radix or radix <= 33 (where x is not a valid digit) → NaN
							goto parseInt_done;
						}
						else
						{
							// Radix >= 34: ignore sign, parse full string including 0x chars
							ignore_sign = 1;
							parse_start = s; // full string
						}
					}
					else
					{
						// No sign: strip 0x prefix
						parse_start = s + 2;
						if (!has_explicit_radix) parse_radix = 16;
					}
				}
				else if (!has_explicit_radix && sign_off < slen && s[sign_off] == '0')
				{
					// Check for octal: all remaining chars must be 0-7
					int all_octal = 1;
					for (int i = sign_off; i < slen; i++)
					{
						if (s[i] < '0' || s[i] > '7') { all_octal = 0; break; }
					}
					if (all_octal) parse_radix = 8;
				}

				// Trim leading whitespace from parse_start
				while (*parse_start == ' ' || *parse_start == '\t' ||
				       *parse_start == '\n' || *parse_start == '\r')
					parse_start++;

				// Handle sign at parse_start
				double sign = 1.0;
				if (*parse_start == '+' || *parse_start == '-')
				{
					if (!ignore_sign)
						sign = (*parse_start == '-') ? -1.0 : 1.0;
					parse_start++;
				}

				// Parse digits in parse_radix
				int found_digit = 0;
				result = 0.0;
				while (*parse_start)
				{
					int digit = -1;
					char c = *parse_start;
					if (c >= '0' && c <= '9') digit = c - '0';
					else if (c >= 'a' && c <= 'z') digit = 10 + (c - 'a');
					else if (c >= 'A' && c <= 'Z') digit = 10 + (c - 'A');
					if (digit < 0 || digit >= parse_radix) break;
					result = result * (double)parse_radix + (double)digit;
					found_digit = 1;
					parse_start++;
				}

				if (!found_digit)
					result = 0.0 / 0.0; // NaN
				else
					result = (sign < 0) ? -result : result;
			}

			parseInt_done:
			if (args != NULL) FREE(args);
			// Push as f64 to handle large values and Infinity
			if (result != result) // NaN
			{
				float nan_val = 0.0f / 0.0f;
				PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &nan_val));
			}
			else if (result == (double)(float)result && result < 1e18)
			{
				float fres = (float)result;
				PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &fres));
			}
			else
			{
				PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
			}
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
				char _parseFloat_buf[512];
				const uint16_t* _parseFloat_u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(_parseFloat_u16, args[0].str_size, _parseFloat_buf, sizeof(_parseFloat_buf));
				str_value = _parseFloat_buf;
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
	// isNaN(value) - Check if value is NaN (returns boolean)
	else if (func_name_len == 5 && strncmp(func_name, "isNaN", 5) == 0)
	{
		if (num_args > 0)
		{
			double val = 0.0 / 0.0; // default NaN
			if (args[0].type == ACTION_STACK_VALUE_F32)
				val = (double)VAL(float, &args[0].data.numeric_value);
			else if (args[0].type == ACTION_STACK_VALUE_F64)
				val = VAL(double, &args[0].data.numeric_value);
			else if (args[0].type == ACTION_STACK_VALUE_BOOLEAN)
				val = args[0].data.numeric_value ? 1.0 : 0.0;
			else if (args[0].type == ACTION_STACK_VALUE_NULL)
				val = 0.0 / 0.0;
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				char _isnan_buf[512];
				const uint16_t* _isnan_u16 = varGetU16Ptr(&args[0]);
				int _isnan_len = u16_to_utf8(_isnan_u16, args[0].str_size, _isnan_buf, sizeof(_isnan_buf) - 1);
				_isnan_buf[_isnan_len] = '\0';
				// Flash strict parsing: entire string must be a valid number
				if (_isnan_len == 0) { val = 0.0 / 0.0; }
				else {
					char* endp = NULL;
					val = strtod(_isnan_buf, &endp);
					// If not all chars consumed, it's NaN
					if (endp != _isnan_buf + _isnan_len) val = 0.0 / 0.0;
				}
			}
			else if (args[0].type == ACTION_STACK_VALUE_OBJECT)
			{
				// Call valueOf on the object
				int _vof_f = 0;
				ActionVar vo = objectCallValueOf(app_context, &args[0], &_vof_f);
				if (vo.type == ACTION_STACK_VALUE_F32)
					val = (double)VAL(float, &vo.data.numeric_value);
				else if (vo.type == ACTION_STACK_VALUE_F64)
					val = VAL(double, &vo.data.numeric_value);
				else
					val = 0.0 / 0.0;
			}
			else
				val = 0.0 / 0.0; // undefined → NaN

			int is_nan = (val != val);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, is_nan ? 1ULL : 0ULL);
			builtin_handled = 1;
		}
		else
		{
			// No arguments - isNaN(undefined) = true
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 1ULL);
			builtin_handled = 1;
		}
	}
	// isFinite(value) - Check if value is finite (returns boolean)
	else if (func_name_len == 8 && strncmp(func_name, "isFinite", 8) == 0)
	{
		if (num_args > 0)
		{
			double val = 0.0 / 0.0; // default NaN
			if (args[0].type == ACTION_STACK_VALUE_F32)
				val = (double)VAL(float, &args[0].data.numeric_value);
			else if (args[0].type == ACTION_STACK_VALUE_F64)
				val = VAL(double, &args[0].data.numeric_value);
			else if (args[0].type == ACTION_STACK_VALUE_BOOLEAN)
				val = args[0].data.numeric_value ? 1.0 : 0.0;
			else if (args[0].type == ACTION_STACK_VALUE_NULL)
				val = 0.0 / 0.0;
			else if (args[0].type == ACTION_STACK_VALUE_STRING)
			{
				char _isf_buf[512];
				const uint16_t* _isf_u16 = varGetU16Ptr(&args[0]);
				int _isf_len = u16_to_utf8(_isf_u16, args[0].str_size, _isf_buf, sizeof(_isf_buf) - 1);
				_isf_buf[_isf_len] = '\0';
				// Flash strict parsing: entire string must be a valid number
				if (_isf_len == 0) { val = 0.0 / 0.0; }
				else {
					char* endp = NULL;
					val = strtod(_isf_buf, &endp);
					// If not all chars consumed, it's NaN
					if (endp != _isf_buf + _isf_len) val = 0.0 / 0.0;
				}
			}
			else if (args[0].type == ACTION_STACK_VALUE_OBJECT)
			{
				// Call valueOf on the object
				int _vof_f = 0;
				ActionVar vo = objectCallValueOf(app_context, &args[0], &_vof_f);
				if (vo.type == ACTION_STACK_VALUE_F32)
					val = (double)VAL(float, &vo.data.numeric_value);
				else if (vo.type == ACTION_STACK_VALUE_F64)
					val = VAL(double, &vo.data.numeric_value);
				else
					val = 0.0 / 0.0;
			}
			else
				val = 0.0 / 0.0; // undefined → NaN

			int is_finite = (val == val && val != INFINITY && val != -INFINITY);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, is_finite ? 1ULL : 0ULL);
			builtin_handled = 1;
		}
		else
		{
			// No arguments - isFinite(undefined) = false
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0ULL);
			builtin_handled = 1;
		}
	}

	// escape(string) — URL-encode a string
	else if (func_name_len == 6 && strncmp(func_name, "escape", 6) == 0)
	{
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			// Convert UTF-16 to UTF-8 for byte-level escape
			char utf8_buf[4096];
			const uint16_t* u16 = varGetU16Ptr(&args[0]);
			int utf8_len = u16_to_utf8(u16, args[0].str_size, utf8_buf, sizeof(utf8_buf));
			// Allocate worst case: each byte → %XX (3 chars)
			char* buf = (char*) HALLOC(utf8_len * 3 + 1);
			u32 out = 0;
			for (int i = 0; i < utf8_len; i++)
			{
				unsigned char c = (unsigned char) utf8_buf[i];
				if (c == 0) break;
				if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
				    (c >= '0' && c <= '9'))
				{
					buf[out++] = c;
				}
				else
				{
					buf[out++] = '%';
					buf[out++] = "0123456789ABCDEF"[c >> 4];
					buf[out++] = "0123456789ABCDEF"[c & 0x0F];
				}
			}
			buf[out] = '\0';
			if (args != NULL) FREE(args);
			// Convert result back to UTF-16
			u32 u16_len;
			uint16_t* u16_result = ascii_to_u16(app_context, buf, out, &u16_len);
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_STRING;
			result.str_size = u16_len;
			result.data.string_data.heap_ptr = u16_result;
			result.data.string_data.owns_memory = true;
			pushVar(app_context, &result);
		}
		else
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
		builtin_handled = 1;
	}

	// unescape(string) — URL-decode a string
	else if (func_name_len == 8 && strncmp(func_name, "unescape", 8) == 0)
	{
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			// Convert UTF-16 to UTF-8 for byte-level unescape
			char utf8_buf[4096];
			const uint16_t* u16 = varGetU16Ptr(&args[0]);
			int utf8_len = u16_to_utf8(u16, args[0].str_size, utf8_buf, sizeof(utf8_buf));
			// Allocate same size (decoded is always <= encoded)
			char* buf = (char*) HALLOC(utf8_len + 1);
			u32 out = 0;
			for (int i = 0; i < utf8_len; )
			{
				if (utf8_buf[i] == '%')
				{
					// Check for %uXXXX (Unicode escape)
					if (i + 5 < utf8_len && utf8_buf[i+1] == 'u' &&
					    isxdigit((unsigned char)utf8_buf[i+2]) && isxdigit((unsigned char)utf8_buf[i+3]) &&
					    isxdigit((unsigned char)utf8_buf[i+4]) && isxdigit((unsigned char)utf8_buf[i+5]))
					{
						buf[out++] = utf8_buf[i+2];
						buf[out++] = utf8_buf[i+3];
						buf[out++] = utf8_buf[i+4];
						buf[out++] = utf8_buf[i+5];
						i += 6;
						continue;
					}
					// Regular %XX hex escape
					if (i + 2 < utf8_len &&
					    isxdigit((unsigned char)utf8_buf[i+1]) && isxdigit((unsigned char)utf8_buf[i+2]))
					{
						char hex[3] = { utf8_buf[i+1], utf8_buf[i+2], 0 };
						unsigned long val = strtoul(hex, NULL, 16);
						buf[out++] = (char) val;
						i += 3;
						continue;
					}
					i++;
					if (i < utf8_len)
					{
						int first_is_hex = isxdigit((unsigned char)utf8_buf[i]);
						i++;
						if (first_is_hex && i < utf8_len) i++;
					}
					continue;
				}
				if (utf8_buf[i] == '+')
				{
					buf[out++] = ' ';
					i++;
				}
				else
				{
					buf[out++] = utf8_buf[i++];
				}
			}
			buf[out] = '\0';
			// Convert result back to UTF-16
			u32 u16_len;
			uint16_t* u16_result = utf8_to_u16(app_context, buf, out, &u16_len);
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_STRING;
			result.str_size = u16_len;
			result.data.string_data.heap_ptr = u16_result;
			result.data.string_data.owns_memory = true;
			if (args != NULL) FREE(args);
			pushVar(app_context, &result);
		}
		else if (num_args > 0)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
		else
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
		builtin_handled = 1;
	}

	// Array() — called as function, same behavior as new Array()
	else if (func_name_len == 5 && strncmp(func_name, "Array", 5) == 0)
	{
		if (num_args == 0)
		{
			// Array() — empty array
			ASArray* arr = allocArray(app_context, 4);
			arr->length = 0;
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		}
		else if (num_args == 1 &&
		         (args[0].type == ACTION_STACK_VALUE_F32 ||
		          args[0].type == ACTION_STACK_VALUE_F64))
		{
			// Array(length)
			double length_d = (args[0].type == ACTION_STACK_VALUE_F32) ?
				(double) VAL(float, &args[0].data.numeric_value) :
				VAL(double, &args[0].data.numeric_value);
			u32 length = (u32) ecmaToInt32(length_d);
			int32_t signed_len = (int32_t) length;
			u32 alloc_size = 0;
			if (signed_len > 0)
				alloc_size = (u32)signed_len < 1000000 ? (u32)signed_len : 1000000;
			ASArray* arr = allocArray(app_context, alloc_size > 0 ? alloc_size : 4);
			arr->length = length;
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		}
		else
		{
			// Array(elem1, elem2, ...) — array with elements
			ASArray* arr = allocArray(app_context, num_args);
			arr->length = num_args;
			for (u32 i = 0; i < num_args; i++)
			{
				setArrayElement(app_context, arr, i, &args[i]);
			}
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		}
		builtin_handled = 1;
	}

	// Date() — called as function (without new), returns current date as string
	else if (func_name_len == 4 && strncmp(func_name, "Date", 4) == 0)
	{
		// Date() as function always returns current time as string, ignoring all arguments
		initDatePrototype(app_context);
		ASObject* temp_date = date_construct(app_context, NULL, 0);
		// Call toString on it
		ActionVar ts_result = builtin_date_toString(app_context, NULL, 0, NULL, (void*)temp_date);
		if (args != NULL) FREE(args);
		pushVar(app_context, &ts_result);
		builtin_handled = 1;
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
				// Object(primitive) returns a wrapper object with valueOf and toString
				if (!g_wrapper_toString_init)
				{
					memset(&g_wrapper_toString_func, 0, sizeof(ASFunction));
					strncpy(g_wrapper_toString_func.name, "toString", 255);
					g_wrapper_toString_func.function_type = 2;
					g_wrapper_toString_func.param_count = 0;
					g_wrapper_toString_func.register_count = 0;
					g_wrapper_toString_func.advanced_func = (Function2Ptr) builtin_wrapper_toString;
					if (function_count < MAX_FUNCTIONS)
						function_registry[function_count++] = &g_wrapper_toString_func;
					g_wrapper_toString_init = 1;
				}
				ASObject* wrapper = allocObject(app_context, 8);
				setObjectProto(app_context, wrapper);
				setProperty(app_context, wrapper, "valueOf", 7, arg);
				// Set toString function that returns the primitive's string form
				ActionVar ts_func_var;
				ts_func_var.type = ACTION_STACK_VALUE_FUNCTION;
				ts_func_var.str_size = 0;
				ts_func_var.data.numeric_value = (u64) &g_wrapper_toString_func;
				setProperty(app_context, wrapper, "toString", 8, &ts_func_var);
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

	// Number(value) — called as function (without new), returns primitive number
	else if (func_name_len == 6 && strncmp(func_name, "Number", 6) == 0)
	{
		double result = 0.0;
		if (num_args >= 1)
		{
			result = varToDouble(&args[0]);
		}
		// else Number() → 0
		if (args != NULL) FREE(args);
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
		builtin_handled = 1;
	}

	// Boolean(value) — called as function (without new), returns primitive boolean or undefined
	else if (func_name_len == 7 && strncmp(func_name, "Boolean", 7) == 0)
	{
		if (num_args == 0)
		{
			// Boolean() with no args → undefined (Flash behavior)
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
		}
		else
		{
			int truthy = isVarTruthy(&args[0]);
			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, truthy ? 1ULL : 0ULL);
		}
		builtin_handled = 1;
	}

	// String(value) — called as function (without new), returns primitive string
	else if (func_name_len == 6 && strncmp(func_name, "String", 6) == 0)
	{
		if (num_args == 0)
		{
			// String() → empty string
			if (args != NULL) FREE(args);
			ActionVar empty_result = {0};
			empty_result.type = ACTION_STACK_VALUE_STRING;
			empty_result.str_size = 0;
			VAL(u64, &empty_result.data.numeric_value) = (u64)u16_empty;
			pushVar(app_context, &empty_result);
		}
		else if (args[0].type == ACTION_STACK_VALUE_STRING)
		{
			// Already a string — return as-is
			ActionVar str_result = args[0];
			if (args != NULL) FREE(args);
			pushVar(app_context, &str_result);
		}
		else
		{
			// String(value) → convert to string primitive via UTF-8 buffer
			char _str_conv_buf[512];
			int _str_conv_len = varToStringBuf(app_context, &args[0], _str_conv_buf, sizeof(_str_conv_buf));
			if (args != NULL) FREE(args);
			u32 u16_len;
			uint16_t* u16_result = utf8_to_u16(app_context, _str_conv_buf, (u32)_str_conv_len, &u16_len);
			ActionVar str_result = {0};
			str_result.type = ACTION_STACK_VALUE_STRING;
			str_result.str_size = u16_len;
			str_result.data.string_data.heap_ptr = u16_result;
			str_result.data.string_data.owns_memory = true;
			pushVar(app_context, &str_result);
		}
		builtin_handled = 1;
	}

	// ASSetPropFlags(obj, props, setFlags, clearFlags)
	// Modifies property attribute flags (ECMA flags for enumerable/writable/configurable)
	// Flash flag bits: DontEnum=1, DontDelete=2, ReadOnly=4
	// Args: args[0]=obj, args[1]=props (string or null), args[2]=setFlags, args[3]=clearFlags
	else if (func_name_len == 14 && strncmp(func_name, "ASSetPropFlags", 14) == 0)
	{
		if (num_args >= 3 && args[0].type == ACTION_STACK_VALUE_OBJECT)
		{
			ASObject* obj = (ASObject*)(u64)args[0].data.numeric_value;
			s32 set_flags = (num_args >= 3) ? varToInt32(&args[2]) : 0;
			s32 clear_flags = (num_args >= 4) ? varToInt32(&args[3]) : 0;

			if (obj != NULL)
			{
				// Convert Flash flags to ECMA flag operations
				// set_flags = Flash flags to SET (restrict) → clear corresponding ECMA bits
				// clear_flags = Flash flags to CLEAR (unrestrict) → set corresponding ECMA bits
				u8 ecma_clear = 0;  // ECMA bits to clear
				u8 ecma_set = 0;    // ECMA bits to set
				if (set_flags & 1) ecma_clear |= PROPERTY_FLAG_ENUMERABLE;
				if (set_flags & 2) ecma_clear |= PROPERTY_FLAG_CONFIGURABLE;
				if (set_flags & 4) ecma_clear |= PROPERTY_FLAG_WRITABLE;
				if (clear_flags & 1) ecma_set |= PROPERTY_FLAG_ENUMERABLE;
				if (clear_flags & 2) ecma_set |= PROPERTY_FLAG_CONFIGURABLE;
				if (clear_flags & 4) ecma_set |= PROPERTY_FLAG_WRITABLE;

				// Check if props is null → apply to ALL properties
				int apply_all = (args[1].type == ACTION_STACK_VALUE_NULL);

				if (apply_all)
				{
					for (u32 i = 0; i < obj->num_used; i++)
					{
						obj->properties[i].flags = (obj->properties[i].flags | ecma_set) & ~ecma_clear;
						obj->properties[i].flash_flags = (u16)((obj->properties[i].flash_flags & ~clear_flags) | set_flags);
					}
				}
				else
				{
					// Coerce props argument to string
					char _spf_name_buf[512];
					const char* prop_str = NULL;
					if (args[1].type == ACTION_STACK_VALUE_STRING)
					{
						const uint16_t* _spf_name_u16 = varGetU16Ptr(&args[1]);
						u16_to_utf8(_spf_name_u16, args[1].str_size, _spf_name_buf, sizeof(_spf_name_buf));
						prop_str = _spf_name_buf;
					}
					else if (args[1].type == ACTION_STACK_VALUE_UNDEFINED)
					{
						// undefined coerces to "undefined" — applies to property named "undefined"
						strncpy(_spf_name_buf, "undefined", sizeof(_spf_name_buf));
						prop_str = _spf_name_buf;
					}
					else if (args[1].type == ACTION_STACK_VALUE_OBJECT || args[1].type == ACTION_STACK_VALUE_FUNCTION)
					{
						// Object — call toString to get property names string
						int len = varToStringBuf(app_context, &args[1], _spf_name_buf, sizeof(_spf_name_buf));
						if (len > 0) prop_str = _spf_name_buf;
					}
					else if (args[1].type == ACTION_STACK_VALUE_F32 || args[1].type == ACTION_STACK_VALUE_F64 || args[1].type == ACTION_STACK_VALUE_BOOLEAN)
					{
						int len = varToStringBuf(app_context, &args[1], _spf_name_buf, sizeof(_spf_name_buf));
						if (len > 0) prop_str = _spf_name_buf;
					}

					if (prop_str != NULL)
					{
						// Support comma-separated property names
						char* token = _spf_name_buf;
						while (*token)
						{
							// Skip leading whitespace
							while (*token == ' ' || *token == '\t') token++;
							if (*token == '\0') break;

							// Find end of token (comma or end)
							char* end = token;
							while (*end && *end != ',') end++;
							u32 tlen = (u32)(end - token);
							// Trim trailing whitespace
							while (tlen > 0 && (token[tlen-1] == ' ' || token[tlen-1] == '\t')) tlen--;

							if (tlen > 0)
							{
								for (u32 i = 0; i < obj->num_used; i++)
								{
									if (obj->properties[i].name_length == tlen &&
									    strncmp(obj->properties[i].name, token, tlen) == 0)
									{
										obj->properties[i].flags = (obj->properties[i].flags | ecma_set) & ~ecma_clear;
										obj->properties[i].flash_flags = (u16)((obj->properties[i].flash_flags & ~clear_flags) | set_flags);
										break;
									}
								}
							}

							if (*end == ',') end++;
							token = end;
						}
					}
				}
			}
		}
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
		builtin_handled = 1;
	}

	// addProperty(name, getter, setter) — registers virtual getter/setter on global object
	else if (func_name_len == 11 && strncmp(func_name, "addProperty", 11) == 0)
	{
		u64 result = 0;  // boolean false

		if (num_args >= 3 && args[0].type == ACTION_STACK_VALUE_STRING && global_object != NULL)
		{
			char _addprop_buf[512];
			const uint16_t* _addprop_u16 = varGetU16Ptr(&args[0]);
			u16_to_utf8(_addprop_u16, args[0].str_size, _addprop_buf, sizeof(_addprop_buf));
			const char* prop_name = _addprop_buf;
			u32 prop_name_len = (u32)strlen(prop_name);

			ASFunction* getter = NULL;
			if (args[1].type == ACTION_STACK_VALUE_FUNCTION)
				getter = (ASFunction*) args[1].data.numeric_value;

			ASFunction* setter = NULL;
			if (args[2].type == ACTION_STACK_VALUE_FUNCTION)
				setter = (ASFunction*) args[2].data.numeric_value;

			// Store getter/setter directly on the global object's property
			ASObject* target = global_object;
			ASProperty* prop = NULL;
			for (u32 i = 0; i < target->num_used; i++)
			{
				if (target->properties[i].name_length == prop_name_len &&
				    strncmp(target->properties[i].name, prop_name, prop_name_len) == 0)
				{
					prop = &target->properties[i];
					break;
				}
			}
			if (prop == NULL)
			{
				ActionVar marker = {0};
				marker.type = ACTION_STACK_VALUE_UNDEFINED;
				setProperty(app_context, target, prop_name, prop_name_len, &marker);
				for (u32 i = 0; i < target->num_used; i++)
				{
					if (target->properties[i].name_length == prop_name_len &&
					    strncmp(target->properties[i].name, prop_name, prop_name_len) == 0)
					{
						prop = &target->properties[i];
						break;
					}
				}
			}
			if (prop != NULL)
			{
				prop->getter = (void*)getter;
				prop->setter = (void*)setter;
				result = 1; // boolean true
			}
		}

		if (args != NULL) FREE(args);
		PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
		builtin_handled = 1;
	}

	// createTextField(name, depth, x, y, width, height) — MovieClip method called as CallFunction
	// In Flash, calling createTextField() as a free function acts on the current MovieClip scope (_root).
	else if (func_name_len == 15 && strncmp(func_name, "createTextField", 15) == 0)
	{
#ifdef NO_GRAPHICS
		if (num_args >= 6) {
			extern MovieClip root_movieclip;
			MovieClip* mc = &root_movieclip;
			char _ctf_name_buf[512];
			const char* inst_name = "";
			if (args[0].type == ACTION_STACK_VALUE_STRING) {
				const uint16_t* _ctf_name_u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(_ctf_name_u16, args[0].str_size, _ctf_name_buf, sizeof(_ctf_name_buf));
				inst_name = _ctf_name_buf;
			}
			int depth_val = (int) varToDouble(&args[1]);
			double x = varToDouble(&args[2]);
			double y = varToDouble(&args[3]);
			double w = varToDouble(&args[4]);
			double h = varToDouble(&args[5]);
			(void)depth_val;

			MovieClip* child = createMovieClip(inst_name, mc);
			child->x = (float) x;
			child->y = (float) y;
			child->width = (float) w;
			child->height = (float) h;
			child->ng_textfield_idx = -1;

			if (child->dynamic_props == NULL) {
				child->dynamic_props = (void*) allocObject(app_context, 32);
				retainObject((ASObject*) child->dynamic_props);
			}
			ASObject* props = (ASObject*) child->dynamic_props;

			initTextFieldPrototype(app_context);
			if (g_textfield_constructor.prototype_obj != NULL) {
				ActionVar proto_val = {0};
				proto_val.type = ACTION_STACK_VALUE_OBJECT;
				proto_val.data.numeric_value = (u64) g_textfield_constructor.prototype_obj;
				setProperty(app_context, props, "__proto__", 9, &proto_val);
				for (u32 pi = 0; pi < props->num_used; pi++) {
					if (strcmp(props->properties[pi].name, "__proto__") == 0) {
						props->properties[pi].flags &= ~PROPERTY_FLAG_ENUMERABLE;
						break;
					}
				}
			}

			// Set default properties for dynamic text fields
			ActionVar sval = {0};
			sval.type = ACTION_STACK_VALUE_STRING;
			sval.str_size = 0;
			VAL(u64, &sval.data.numeric_value) = (u64)u16_empty;
			setProperty(app_context, props, "text", 4, &sval);
			setProperty(app_context, props, "htmlText", 8, &sval);
			setProperty(app_context, props, "variable", 8, &sval);

			ActionVar fval = {0};
			fval.type = ACTION_STACK_VALUE_BOOLEAN;
			fval.data.numeric_value = 0;
			setProperty(app_context, props, "background", 10, &fval);
			setProperty(app_context, props, "border", 6, &fval);
			setProperty(app_context, props, "multiline", 9, &fval);
			setProperty(app_context, props, "wordWrap", 8, &fval);
			setProperty(app_context, props, "password", 8, &fval);
			setProperty(app_context, props, "html", 4, &fval);
			setProperty(app_context, props, "embedFonts", 10, &fval);
			setProperty(app_context, props, "condenseWhite", 13, &fval);

			ActionVar tval = {0};
			tval.type = ACTION_STACK_VALUE_BOOLEAN;
			tval.data.numeric_value = 1;
			setProperty(app_context, props, "selectable", 10, &tval);
			setProperty(app_context, props, "mouseWheelEnabled", 17, &tval);

			ActionVar type_val = {0};
			type_val.type = ACTION_STACK_VALUE_STRING;
			type_val.str_size = 7;
			VAL(u64, &type_val.data.numeric_value) = (u64)u16_dynamic;
			setProperty(app_context, props, "type", 4, &type_val);

			ActionVar dval = {0};
			dval.type = ACTION_STACK_VALUE_F64;
			VAL(double, &dval.data.numeric_value) = 0.0;
			setProperty(app_context, props, "length", 6, &dval);
			setProperty(app_context, props, "textWidth", 9, &dval);
			setProperty(app_context, props, "textHeight", 10, &dval);
			setProperty(app_context, props, "hscroll", 7, &dval);
			setProperty(app_context, props, "maxhscroll", 10, &dval);
			setProperty(app_context, props, "sharpness", 9, &dval);
			setProperty(app_context, props, "thickness", 9, &dval);

			ActionVar one_val = {0};
			one_val.type = ACTION_STACK_VALUE_F64;
			VAL(double, &one_val.data.numeric_value) = 1.0;
			setProperty(app_context, props, "scroll", 6, &one_val);
			setProperty(app_context, props, "maxscroll", 9, &one_val);
			setProperty(app_context, props, "bottomScroll", 12, &one_val);

			ActionVar null_val = {0};
			null_val.type = ACTION_STACK_VALUE_NULL;
			setProperty(app_context, props, "maxChars", 8, &null_val);
			setProperty(app_context, props, "restrict", 8, &null_val);
			setProperty(app_context, props, "styleSheet", 10, &null_val);

			ActionVar undef_val = {0};
			undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
			setProperty(app_context, props, "tabIndex", 8, &undef_val);

			ActionVar tc_val = {0};
			tc_val.type = ACTION_STACK_VALUE_F64;
			VAL(double, &tc_val.data.numeric_value) = 0.0;
			setProperty(app_context, props, "textColor", 9, &tc_val);
			VAL(double, &tc_val.data.numeric_value) = 16777215.0;
			setProperty(app_context, props, "backgroundColor", 15, &tc_val);
			VAL(double, &tc_val.data.numeric_value) = 0.0;
			setProperty(app_context, props, "borderColor", 11, &tc_val);

			ActionVar aat_val = {0};
			aat_val.type = ACTION_STACK_VALUE_STRING;
			aat_val.str_size = 6;
			VAL(u64, &aat_val.data.numeric_value) = (u64)u16_normal;
			setProperty(app_context, props, "antiAliasType", 13, &aat_val);

			ActionVar gft_val = {0};
			gft_val.type = ACTION_STACK_VALUE_STRING;
			gft_val.str_size = 5;
			VAL(u64, &gft_val.data.numeric_value) = (u64)u16_pixel;
			setProperty(app_context, props, "gridFitType", 11, &gft_val);

			ActionVar as_val = {0};
			as_val.type = ACTION_STACK_VALUE_STRING;
			as_val.str_size = 4;
			VAL(u64, &as_val.data.numeric_value) = (u64)u16_none;
			setProperty(app_context, props, "autoSize", 8, &as_val);

			ASArray* filters_arr = allocArray(app_context, 0);
			filters_arr->length = 0;
			ActionVar filters_val = {0};
			filters_val.type = ACTION_STACK_VALUE_ARRAY;
			filters_val.data.numeric_value = (u64) filters_arr;
			setProperty(app_context, props, "filters", 7, &filters_val);

			// Register child on parent MC's dynamic_props so mc.childName works via GetMember
			{
				if (mc->dynamic_props == NULL) {
					mc->dynamic_props = (void*) allocObject(app_context, 8);
					retainObject((ASObject*) mc->dynamic_props);
				}
				ActionVar mc_var = {0};
				mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
				mc_var.data.numeric_value = (u64)child;
				setProperty(app_context, (ASObject*) mc->dynamic_props, inst_name, strlen(inst_name), &mc_var);
				// Also set on global scope for GetVariable access
				size_t klen = strlen(inst_name);
				ActionVar* gvar = getVariable((char*)inst_name, klen);
				if (gvar != NULL) {
					gvar->type = mc_var.type;
					gvar->str_size = mc_var.str_size;
					gvar->data = mc_var.data;
				}
			}

			// Add to child_mc_cache so it persists across lookups
			if (child_mc_count < MAX_CHILD_MOVIECLIPS) {
				child_mc_cache[child_mc_count++] = child;
			}

			// Return target path
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_STRING;
			{
				u32 _tgt_u16_len;
				uint16_t* _tgt_u16 = ascii_to_u16(app_context, child->target, (int)strlen(child->target), &_tgt_u16_len);
				result.str_size = _tgt_u16_len;
				VAL(u64, &result.data.numeric_value) = (u64)_tgt_u16;
				if (args != NULL) FREE(args);
				pushVar(app_context, &result);
			}
		} else {
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
#else
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
#endif
		builtin_handled = 1;
	}
	// createEmptyMovieClip(name, depth) — MovieClip method called as CallFunction
	else if (func_name_len == 20 && strncmp(func_name, "createEmptyMovieClip", 20) == 0)
	{
#ifdef NO_GRAPHICS
		if (num_args >= 2) {
			extern MovieClip root_movieclip;
			MovieClip* mc = &root_movieclip;
			char _cemc_name_buf[512];
			const char* inst_name = "";
			if (args[0].type == ACTION_STACK_VALUE_STRING) {
				const uint16_t* _cemc_name_u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(_cemc_name_u16, args[0].str_size, _cemc_name_buf, sizeof(_cemc_name_buf));
				inst_name = _cemc_name_buf;
			}
			int depth_val = ecmaToInt32(varToDouble(&args[1]));

			// Remove existing clip at same depth (depth conflict resolution)
			for (int _di = 0; _di < child_mc_count; _di++) {
				if (child_mc_cache[_di] != NULL && child_mc_cache[_di]->parent == mc &&
				    child_mc_cache[_di]->depth == depth_val) {
					// Invalidate old clip
					child_mc_cache[_di]->depth = INT_MIN; // mark invalid
					// Remove from parent's dynamic_props if present
					if (mc->dynamic_props != NULL) {
						ActionVar undef_var = {0};
						undef_var.type = ACTION_STACK_VALUE_UNDEFINED;
						setProperty(app_context, (ASObject*)mc->dynamic_props,
							child_mc_cache[_di]->name, strlen(child_mc_cache[_di]->name), &undef_var);
					}
					child_mc_cache[_di] = NULL;
					break;
				}
			}

			MovieClip* child = createMovieClip(inst_name, mc);
			child->currentframe = 0;  // Empty clips have _currentframe = 0
			child->totalframes = 1;
			child->framesloaded = 1;
			child->depth = depth_val;
			strncpy(child->url, mc->url[0] ? mc->url : root_movieclip.url, sizeof(child->url) - 1);
			child->url[sizeof(child->url) - 1] = '\0';

			// Register child on parent MC's dynamic_props
			if (mc->dynamic_props == NULL) {
				mc->dynamic_props = (void*) allocObject(app_context, 8);
				retainObject((ASObject*) mc->dynamic_props);
			}
			ActionVar mc_var = {0};
			mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
			mc_var.data.numeric_value = (u64)child;
			setProperty(app_context, (ASObject*) mc->dynamic_props, inst_name, strlen(inst_name), &mc_var);
			setVariableByName(inst_name, &mc_var);

			// Find a free slot or append
			int _slot = -1;
			for (int _di = 0; _di < child_mc_count; _di++) {
				if (child_mc_cache[_di] == NULL) { _slot = _di; break; }
			}
			if (_slot >= 0) {
				child_mc_cache[_slot] = child;
			} else if (child_mc_count < MAX_CHILD_MOVIECLIPS) {
				child_mc_cache[child_mc_count++] = child;
			}

			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child);
		} else {
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
#else
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
#endif
		builtin_handled = 1;
	}
	// getNextHighestDepth() — as a global function, operates on root
	else if (func_name_len == 19 && strncmp(func_name, "getNextHighestDepth", 19) == 0)
	{
		if (args != NULL) FREE(args);
		extern MovieClip root_movieclip;
		MovieClip* parent_mc = &root_movieclip;
		int max_d = -1;
		for (int _i = 0; _i < child_mc_count; _i++) {
			MovieClip* _ch = child_mc_cache[_i];
			if (_ch != NULL && _ch->parent == parent_mc && _ch->depth > max_d)
				max_d = _ch->depth;
		}
		double v = (max_d < 0) ? 0.0 : (double)(max_d + 1);
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
		builtin_handled = 1;
	}

	// If not a built-in function, look up user-defined functions
	if (!builtin_handled)
	{
		ASFunction* func = lookupFunctionByName(func_name, func_name_len);

		// Try slash-path resolution: /:foo -> foo (Flash 4 root variable syntax)
		if (func == NULL && func_name_len > 2 && func_name[0] == '/' && func_name[1] == ':')
		{
			func = lookupFunctionByName(func_name + 2, func_name_len - 2);
		}

		// Try scope chain + global variable lookup (for functions stored via DefineLocal)
		if (func == NULL)
		{
			// Use preserved string_id so var_array path is taken when available,
			// avoiding hashmap key dangling-pointer issue from actionDefineLocal.
			push_str_id_fn(app_context, func_name, func_name_len, func_name_string_id);
			actionGetVariable(app_context);
			if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
			{
				func = (ASFunction*) STACK_TOP_VALUE;
				POP();
			}
			else
			{
				POP();
			}
		}

		// Try dot-path resolution: _root.foo -> resolve path to function variable
		if (func == NULL && memchr(func_name, '.', func_name_len) != NULL)
		{
			// Resolve the full path via GetVariable (handles dots recursively)
			PUSH_STR(func_name, func_name_len);
			actionGetVariable(app_context);
			// Check if the result is a function
			if (STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION)
			{
				ASFunction* resolved = (ASFunction*) STACK_TOP_VALUE;
				POP();
				func = resolved;
			}
			else
			{
				POP();
			}
		}

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
					scope_is_with[scope_depth] = 0;
					scope_mc[scope_depth] = NULL;
					scope_chain[scope_depth++] = local_scope;
				}

				// Track calling function for arguments.caller
				ASFunction* prev_executing_func = g_current_executing_func;

				// Populate scope with this/super/arguments when neither preload nor suppress is set
				{
					u16 f2flags = func->flags;
					int f2_preload_this  = (f2flags & 0x0001);
					int f2_suppress_this = (f2flags & 0x0002);
					int f2_preload_args  = (f2flags & 0x0004);
					int f2_suppress_args = (f2flags & 0x0008);
					int f2_preload_super = (f2flags & 0x0010);
					int f2_suppress_super= (f2flags & 0x0020);
					if (!f2_preload_this && !f2_suppress_this) {
						extern MovieClip root_movieclip;
						ActionVar this_var = {0};
						this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
						this_var.data.numeric_value = (u64)&root_movieclip;
						setProperty(app_context, local_scope, "this", 4, &this_var);
					}
					if (!f2_preload_args && !f2_suppress_args) {
						ASArray* arguments_arr = allocArray(app_context, num_args);
						for (u32 i = 0; i < num_args; i++)
							setArrayElement(app_context, arguments_arr, i, &args[i]);
						setupArgumentsProps(app_context, arguments_arr, func, prev_executing_func);
						ActionVar args_var = {0};
						args_var.type = ACTION_STACK_VALUE_ARRAY;
						args_var.data.numeric_value = (u64)arguments_arr;
						setProperty(app_context, local_scope, "arguments", 9, &args_var);
					}
					if (!f2_preload_super && !f2_suppress_super) {
						ASObject* super_obj = allocObject(app_context, 0);
						ActionVar super_var = {0};
						super_var.type = ACTION_STACK_VALUE_OBJECT;
						super_var.data.numeric_value = (u64)super_obj;
						setProperty(app_context, local_scope, "super", 5, &super_var);
					}
				}

				g_prev_executing_func = prev_executing_func;
				g_current_executing_func = func;
				ActionVar result = func->advanced_func(app_context, args, num_args, registers, NULL);
				g_current_executing_func = prev_executing_func;

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

				// Create local scope object for function-local variables
				ASObject* local_scope = allocObject(app_context, 8);

				// Track calling function for arguments.caller
				ASFunction* prev_executing_func_t1 = g_current_executing_func;

				// Create arguments array and set on local scope
				ASArray* arguments_arr = allocArray(app_context, num_args > 0 ? num_args : 1);
				for (u32 i = 0; i < num_args; i++)
				{
					setArrayElement(app_context, arguments_arr, i, &args[i]);
				}
				setupArgumentsProps(app_context, arguments_arr, func, prev_executing_func_t1);
				ActionVar args_var = {0};
				args_var.type = ACTION_STACK_VALUE_ARRAY;
				args_var.data.numeric_value = (u64) arguments_arr;
				setProperty(app_context, local_scope, "arguments", 9, &args_var);

				// Push local scope onto scope chain
				if (scope_depth < MAX_SCOPE_DEPTH) {
					scope_is_with[scope_depth] = 0;
					scope_mc[scope_depth] = NULL;
					scope_chain[scope_depth++] = local_scope;
				}

				// Push arguments onto stack in order (first to last)
				// The function will pop them and bind to parameter names
				for (u32 i = 0; i < num_args; i++)
				{
					pushVar(app_context, &args[i]);
				}
				// Pad with undefined if fewer args than parameters
				// (generated code always pops param_count values)
				for (u32 i = num_args; i < func->param_count; i++)
				{
					PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
				}

				if (func->simple_func == NULL)
				{
					// Built-in constructor called as plain function (no implementation)
					// Pop all items we pushed: num_args actual args + padding up to param_count
					u32 total_pushed = num_args > func->param_count ? num_args : func->param_count;
					for (u32 i = 0; i < total_pushed; i++) { POP(); }
					if (scope_depth > 0) { scope_depth--; }
					releaseObject(app_context, local_scope);

					// Check if this is a built-in converter function (called without new)
					const char* fname = func->name;
					if (strcmp(fname, "Number") == 0)
					{
						// Number() → primitive number: 0 if no args, else toNumber(arg)
						double _nc_result = 0.0;
						if (num_args >= 1 && args != NULL)
							_nc_result = varToDouble(&args[0]);
						if (args != NULL) FREE(args);
						PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_nc_result));
					}
					else if (strcmp(fname, "Boolean") == 0)
					{
						// Boolean() → undefined if no args, else boolean primitive
						if (num_args == 0)
						{
							if (args != NULL) FREE(args);
							PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
						}
						else
						{
							int _bc_truthy = isVarTruthy(&args[0]);
							if (args != NULL) FREE(args);
							PUSH(ACTION_STACK_VALUE_BOOLEAN, _bc_truthy ? 1ULL : 0ULL);
						}
					}
					else if (strcmp(fname, "String") == 0)
					{
						// String() → empty string if no args, else string primitive
						if (num_args == 0)
						{
							if (args != NULL) FREE(args);
							ActionVar _sc_empty = {0};
							_sc_empty.type = ACTION_STACK_VALUE_STRING;
							_sc_empty.str_size = 0;
							VAL(u64, &_sc_empty.data.numeric_value) = (u64)u16_empty;
							pushVar(app_context, &_sc_empty);
						}
						else if (args[0].type == ACTION_STACK_VALUE_STRING)
						{
							ActionVar _sc_str = args[0];
							if (args != NULL) FREE(args);
							pushVar(app_context, &_sc_str);
						}
						else
						{
							char _sc_buf[512];
							int _sc_len = varToStringBuf(app_context, &args[0], _sc_buf, sizeof(_sc_buf));
							if (args != NULL) FREE(args);
							u32 _sc_u16_len;
							uint16_t* _sc_u16 = utf8_to_u16(app_context, _sc_buf, (u32)_sc_len, &_sc_u16_len);
							ActionVar _sc_result = {0};
							_sc_result.type = ACTION_STACK_VALUE_STRING;
							_sc_result.str_size = _sc_u16_len;
							_sc_result.data.string_data.heap_ptr = _sc_u16;
							_sc_result.data.string_data.owns_memory = true;
							pushVar(app_context, &_sc_result);
						}
					}
					else
					{
						if (args != NULL) FREE(args);
						pushUndefined(app_context);
					}
				}
				else
				{
					// Free args array (already pushed to stack, no longer needed)
					if (args != NULL) FREE(args);

					// Call the simple function (cast to correct return type — generated functions return ActionVar)
					g_prev_executing_func = prev_executing_func_t1;
					g_current_executing_func = func;
					ActionVar func_result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
					g_current_executing_func = prev_executing_func_t1;

					// Pop local scope from scope chain
					if (scope_depth > 0) {
						scope_depth--;
					}
					releaseObject(app_context, local_scope);

					pushVar(app_context, &func_result);
				}
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
	if (v == NULL)
	{
		buf[0] = '\0';
		return 0;
	}
	if (v->type == ACTION_STACK_VALUE_UNDEFINED || v->type == ACTION_STACK_VALUE_HOLE)
		return snprintf(buf, buf_size, "undefined");
	if (v->type == ACTION_STACK_VALUE_NULL)
		return snprintf(buf, buf_size, "null");
	switch (v->type)
	{
		case ACTION_STACK_VALUE_STRING:
		{
			const uint16_t* u16 = varGetU16Ptr(v);
			if (u16 == NULL || v->str_size == 0) { buf[0] = '\0'; return 0; }
			int len = u16_to_utf8(u16, v->str_size, buf, buf_size);
			return len;
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
		{
			if (v->type == ACTION_STACK_VALUE_OBJECT && v->data.numeric_value != 0) {
				ASObject* obj = (ASObject*) v->data.numeric_value;
				if (isXMLNodeInstance(obj)) {
					int ts_found = 0;
					ActionVar ts = objectCallToString(app_context, v, &ts_found);
					if (ts_found && ts.type == ACTION_STACK_VALUE_STRING) {
						const uint16_t* u16 = varGetU16Ptr(&ts);
						if (u16) {
							int len = u16_to_utf8(u16, ts.str_size, buf, buf_size);
							return len;
						}
					}
				}
			}
			return snprintf(buf, buf_size, "[type Object]");
		}
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
			const uint16_t* u16 = varGetU16Ptr(v);
			if (u16 == NULL || v->str_size == 0) return 0.0;
			char tmp[256];
			u16_to_utf8(u16, v->str_size, tmp, sizeof(tmp));
			char* endptr;
			double d = strtod(tmp, &endptr);
			if (endptr == tmp) return NAN;
			return d;
		}
		case ACTION_STACK_VALUE_NULL: return 0.0;
		default: return NAN;
	}
}

// Helper: compare two ActionVars for sort/sortOn
// flags: CASEINSENSITIVE=1, DESCENDING=2, NUMERIC=16
// Returns negative if a < b, 0 if equal, positive if a > b
static int _sort_compare_vars(SWFAppContext* app_context, ActionVar* a, ActionVar* b, int flags)
{
	int result;

	/* NUMERIC: only when BOTH values are F64/F32 type */
	if ((flags & 16) &&
	    (a->type == ACTION_STACK_VALUE_F64 || a->type == ACTION_STACK_VALUE_F32) &&
	    (b->type == ACTION_STACK_VALUE_F64 || b->type == ACTION_STACK_VALUE_F32))
	{
		double da = varToDoubleSimple(a);
		double db = varToDoubleSimple(b);
		/* NaN always goes to end of sorted sequence (appears last in ascending) */
		int a_nan = isnan(da), b_nan = isnan(db);
		if (a_nan && b_nan) result = 0;
		else if (a_nan) result = 1;   /* a is NaN, put after b */
		else if (b_nan) result = -1;  /* b is NaN, put after a */
		else if (da < db) result = -1;
		else if (da > db) result = 1;
		else result = 0;
		/* DESCENDING flips everything (NaN ends up at start) */
		if (flags & 2) result = -result;
		return result;
	}

	/* String comparison: convert to UTF-8 then compare */
	{
		char buf_a[1024], buf_b[1024];
		varToStringBuf(app_context, a, buf_a, sizeof(buf_a));
		varToStringBuf(app_context, b, buf_b, sizeof(buf_b));
		if (flags & 1) /* CASEINSENSITIVE */
			result = strcasecmp(buf_a, buf_b);
		else
			result = strcmp(buf_a, buf_b);
	}

	if (flags & 2) /* DESCENDING */
		result = -result;
	return result;
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
		// Get separator as UTF-8 for building output
		char sep_utf8[256];
		const char* sep = ",";
		u32 sep_len = 1;
		if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* sep_u16 = varGetU16Ptr(&args[0]);
			if (sep_u16 == NULL) { sep = "null"; sep_len = 4; }
			else { sep_len = u16_to_utf8(sep_u16, args[0].str_size, sep_utf8, sizeof(sep_utf8)); sep = sep_utf8; }
		}
		else if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			sep = ",";
			sep_len = 1;
		}

		// Build joined string as UTF-8
		u32 buf_cap = 256;
		char* buf = (char*) HALLOC(buf_cap);
		u32 buf_len = 0;

		int32_t signed_join_len = (int32_t) arr->length;
		u32 join_limit = 0;
		if (signed_join_len > 0)
			join_limit = (u32)signed_join_len < arr->capacity ? (u32)signed_join_len : arr->capacity;
		for (u32 i = 0; i < join_limit; i++)
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
			ActionVar* elem = getArrayElement(arr, i);
			char elem_str[256];
			int elen = 0;
			// For objects, call toString via prototype chain (produces "[object Object]")
			if (elem != NULL && elem->type == ACTION_STACK_VALUE_OBJECT && elem->data.numeric_value != 0) {
				int ts_found = 0;
				ActionVar ts = objectCallToString(app_context, elem, &ts_found);
				if (ts_found && ts.type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* u16 = varGetU16Ptr(&ts);
					if (u16)
						elen = u16_to_utf8(u16, ts.str_size, elem_str, sizeof(elem_str));
				}
				if (elen == 0)
					elen = snprintf(elem_str, sizeof(elem_str), "[type Object]");
			} else {
				elen = varToStringBuf(app_context, elem, elem_str, sizeof(elem_str));
			}
			while (buf_len + elen + 1 > buf_cap)
			{
				buf_cap *= 2;
				buf = (char*) realloc(buf, buf_cap);
			}
			memcpy(buf + buf_len, elem_str, elen);
			buf_len += elen;
		}
		buf[buf_len] = '\0';

		// Convert result to UTF-16
		u32 u16_len;
		uint16_t* u16_result = utf8_to_u16(app_context, buf, buf_len, &u16_len);
		ActionVar result = {0};
		result.type = ACTION_STACK_VALUE_STRING;
		result.str_size = u16_len;
		result.data.string_data.heap_ptr = u16_result;
		result.data.string_data.owns_memory = true;
		pushVar(app_context, &result);
		return 1;
	}

	// toString() - same as join(",")
	if (method_name_len == 8 && strncmp(method_name, "toString", 8) == 0)
	{
		ActionVar comma_arg = {0};
		comma_arg.type = ACTION_STACK_VALUE_STRING;
		comma_arg.str_size = 1;
		VAL(u64, &comma_arg.data.numeric_value) = (u64) u16_comma;
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

	// hasOwnProperty(key) - check if array has own property at key
	if (method_name_len == 14 && strncmp(method_name, "hasOwnProperty", 14) == 0)
	{
		if (num_args > 0)
		{
			// Convert argument to string
			char key_buf[64];
			int key_len = varToStringBuf(app_context, &args[0], key_buf, sizeof(key_buf));

			// Try as numeric index
			char* endptr;
			long index = strtol(key_buf, &endptr, 10);
			if (*endptr == '\0' && index >= 0 && index <= 2147483647L)
			{
				// Check if array element is set (not a hole)
				ActionVar* elem = getArrayElement(arr, (u32)index);
				if (elem != NULL && elem->type != ACTION_STACK_VALUE_HOLE)
				{
					PUSH(ACTION_STACK_VALUE_BOOLEAN, 1);
				}
				else
				{
					PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
				}
			}
			else
			{
				// Check non-index props
				if (arr->props != NULL)
				{
					ActionVar* pv = getProperty(arr->props, key_buf, key_len);
					PUSH(ACTION_STACK_VALUE_BOOLEAN, pv != NULL ? 1 : 0);
				}
				else
				{
					PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
				}
			}
		}
		else
		{
			PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
		}
		return 1;
	}

	// -----------------------------------------------------------------------
	// Array sort flags (matching Flash AS2 constants)
	// -----------------------------------------------------------------------
	// CASEINSENSITIVE    = 1
	// DESCENDING         = 2
	// UNIQUESORT         = 4
	// RETURNINDEXEDARRAY = 8
	// NUMERIC            = 16

	// -----------------------------------------------------------------------
	// Helper: compare two ActionVars for sort (string or numeric)
	// Returns negative/zero/positive like strcmp.
	// flags: CASEINSENSITIVE=1, DESCENDING=2, NUMERIC=16
	// -----------------------------------------------------------------------
	#define SORT_COMPARE_VARS(_ctx_ac, _a, _b, _fl) _sort_compare_vars((_ctx_ac), (_a), (_b), (_fl))

	// -----------------------------------------------------------------------
	// Helper: stable merge-sort on ActionVar array
	// -----------------------------------------------------------------------
	// (Defined inline as macros/lambdas are not available in C89.
	// We use a file-scope helper declared static ahead of callArrayMethod.)

	// sort() - sort array with flags and optional custom comparator
	if (method_name_len == 4 && strncmp(method_name, "sort", 4) == 0)
	{
		// --- Parse arguments ---
		int flags = 0;
		ASFunction* comparator = NULL;
		int return_undefined = 0;

		if (num_args == 0)
		{
			flags = 0;
		}
		else
		{
			ActionVar* a0 = &args[0];

			if (a0->type == ACTION_STACK_VALUE_FUNCTION)
			{
				// sort(compareFn [, flags])
				comparator = lookupFunctionFromVar(a0);
				if (num_args >= 2)
				{
					ActionVar* a1 = &args[1];
					if (a1->type == ACTION_STACK_VALUE_F32 || a1->type == ACTION_STACK_VALUE_F64)
					{
						double d1 = varToDouble(a1);
						if (!isnan(d1)) flags = (int)d1;
					}
				}
			}
			else if (a0->type == ACTION_STACK_VALUE_F32 || a0->type == ACTION_STACK_VALUE_F64)
			{
				double d0 = varToDouble(a0);
				if (isnan(d0)) d0 = 0.0;
				flags = (int)d0;
				// Two-number case: sort(flags1, flags2) → second numeric arg wins
				if (num_args >= 2)
				{
					ActionVar* a1 = &args[1];
					if (a1->type == ACTION_STACK_VALUE_F32 || a1->type == ACTION_STACK_VALUE_F64)
					{
						double d1 = varToDouble(a1);
						if (!isnan(d1)) flags = (int)d1;
					}
				}
			}
			else if (a0->type == ACTION_STACK_VALUE_OBJECT || a0->type == ACTION_STACK_VALUE_ARRAY)
			{
				// OBJECT/ARRAY as first arg: return array unchanged (not sorted)
				PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
				return 1;
			}
			else
			{
				// BOOLEAN, NULL, UNDEFINED etc. → return undefined
				return_undefined = 1;
			}
		}

		if (return_undefined)
		{
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			return 1;
		}

		u32 n = arr->length;
		if (n <= 1)
		{
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
			return 1;
		}

		// --- UNIQUESORT: check for duplicates before sorting ---
		if (flags & 4)
		{
			for (u32 _ui = 0; _ui < n && !(flags & 4); _ui++) {}
			// Run the duplicate check using the same comparison method
			for (u32 _ui = 0; _ui < n; _ui++)
			{
				for (u32 _uj = _ui + 1; _uj < n; _uj++)
				{
					int _ucmp = 0;
					if (comparator != NULL)
					{
						ActionVar _uargs[2] = { arr->elements[_ui], arr->elements[_uj] };
						ActionVar _ures;
						g_call_depth++;
						if (comparator->function_type == 2)
							_ures = comparator->advanced_func(app_context, _uargs, 2, NULL, NULL);
						else
						{
							pushVar(app_context, &_uargs[1]);
							pushVar(app_context, &_uargs[0]);
							_ures = ((ActionVar(*)(SWFAppContext*))comparator->simple_func)(app_context);
						}
						g_call_depth--;
						double _ud = varToDouble(&_ures);
						_ucmp = (_ud < 0) ? -1 : (_ud > 0) ? 1 : 0;
					}
					else
					{
						_ucmp = _sort_compare_vars(app_context, &arr->elements[_ui], &arr->elements[_uj], flags & ~2);
					}
					if (_ucmp == 0)
					{
						double _zero = 0.0;
						PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_zero));
						return 1;
					}
				}
			}
		}

		// --- RETURNINDEXEDARRAY: sort a copy of indices, return index array ---
		if (flags & 8)
		{
			u32* _idx = (u32*) HALLOC(n * sizeof(u32));
			if (_idx == NULL) { PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr); return 1; }
			for (u32 _ii = 0; _ii < n; _ii++) _idx[_ii] = _ii;

			// --- RETURNINDEXEDARRAY: Flash QuickSort on index array ---
			{
				typedef struct { u32 low; u32 high; } _QI_Range;
				_QI_Range* _qi_stack = (_QI_Range*) HALLOC(n * sizeof(_QI_Range));
				if (_qi_stack != NULL)
				{
					int _qi_top = 0;
					int _qi_flags = flags & ~2;  // strip DESCENDING (reversed after sort)
					_qi_stack[_qi_top].low = 0;
					_qi_stack[_qi_top].high = n - 1;
					_qi_top++;

					while (_qi_top > 0 && !g_execution_halted)
					{
						_qi_top--;
						u32 _ql = _qi_stack[_qi_top].low;
						u32 _qh = _qi_stack[_qi_top].high;
						if (_ql >= _qh) continue;

						u32 _qpivot_idx = _idx[_ql];
						u32 _qleft = _ql + 1;
						u32 _qright = _qh;

						for (;;)
						{
							// Left scan: advance while compare(pivot, elem) > 0
							while (_qleft < _qright)
							{
								int _qcmp;
								if (comparator != NULL)
								{
									ActionVar _qargs[2] = { arr->elements[_qpivot_idx], arr->elements[_idx[_qleft]] };
									ActionVar _qres;
									g_call_depth++;
									if (comparator->function_type == 2)
										_qres = comparator->advanced_func(app_context, _qargs, 2, NULL, NULL);
									else {
										pushVar(app_context, &_qargs[1]);
										pushVar(app_context, &_qargs[0]);
										_qres = ((ActionVar(*)(SWFAppContext*))comparator->simple_func)(app_context);
									}
									g_call_depth--;
									if (g_execution_halted) break;
									double _qd = varToDouble(&_qres);
									_qcmp = (_qd < 0) ? -1 : (_qd > 0) ? 1 : 0;
								}
								else
								{
									_qcmp = _sort_compare_vars(app_context, &arr->elements[_qpivot_idx], &arr->elements[_idx[_qleft]], _qi_flags);
								}
								if (_qcmp <= 0) break;
								_qleft++;
							}
							if (g_execution_halted) break;
							// Right scan: advance while compare(pivot, elem) <= 0
							while (_qright > _ql)
							{
								int _qcmp;
								if (comparator != NULL)
								{
									ActionVar _qargs[2] = { arr->elements[_qpivot_idx], arr->elements[_idx[_qright]] };
									ActionVar _qres;
									g_call_depth++;
									if (comparator->function_type == 2)
										_qres = comparator->advanced_func(app_context, _qargs, 2, NULL, NULL);
									else {
										pushVar(app_context, &_qargs[1]);
										pushVar(app_context, &_qargs[0]);
										_qres = ((ActionVar(*)(SWFAppContext*))comparator->simple_func)(app_context);
									}
									g_call_depth--;
									if (g_execution_halted) break;
									double _qd = varToDouble(&_qres);
									_qcmp = (_qd < 0) ? -1 : (_qd > 0) ? 1 : 0;
								}
								else
								{
									_qcmp = _sort_compare_vars(app_context, &arr->elements[_qpivot_idx], &arr->elements[_idx[_qright]], _qi_flags);
								}
								if (_qcmp > 0) break;
								_qright--;
							}
							if (g_execution_halted) break;
							if (_qleft >= _qright) break;
							// Swap indices
							u32 _qtmp_idx = _idx[_qleft];
							_idx[_qleft] = _idx[_qright];
							_idx[_qright] = _qtmp_idx;
						}

						// Place pivot index at its final position
						_idx[_ql] = _idx[_qright];
						_idx[_qright] = _qpivot_idx;

						// Push right subarray first (LIFO -> left processed first)
						if (_qright + 1 <= _qh && _qi_top < (int)n)
						{
							_qi_stack[_qi_top].low = _qright + 1;
							_qi_stack[_qi_top].high = _qh;
							_qi_top++;
						}
						// Push left subarray second (processed first via LIFO)
						if (_qright > 0 && _ql < _qright && _qi_top < (int)n)
						{
							_qi_stack[_qi_top].low = _ql;
							_qi_stack[_qi_top].high = _qright - 1;
							_qi_top++;
						}
					}
					FREE(_qi_stack);
				}
				// DESCENDING: reverse index array after sort
				if (flags & 2)
				{
					u32 _qlo = 0, _qhi = n - 1;
					while (_qlo < _qhi)
					{
						u32 _qtmp_idx = _idx[_qlo];
						_idx[_qlo] = _idx[_qhi];
						_idx[_qhi] = _qtmp_idx;
						_qlo++; _qhi--;
					}
				}
			}

			// Build index result array
			ASArray* _ridx_arr = allocArray(app_context, n);
			if (_ridx_arr == NULL) { FREE(_idx); PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr); return 1; }
			_ridx_arr->length = n;
			for (u32 _ii = 0; _ii < n; _ii++)
			{
				_ridx_arr->elements[_ii].type = ACTION_STACK_VALUE_F64;
				double _dv = (double) _idx[_ii];
				VAL(double, &_ridx_arr->elements[_ii].data.numeric_value) = _dv;
			}
			FREE(_idx);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) _ridx_arr);
			return 1;
		}

		// --- Standard sort: Flash QuickSort (iterative, leftmost pivot) ---
		{
			typedef struct { u32 low; u32 high; } _QS_Range;
			_QS_Range* _qs_stack = (_QS_Range*) HALLOC(n * sizeof(_QS_Range));
			if (_qs_stack != NULL)
			{
				int _qs_top = 0;
				int _qs_flags = flags & ~2;  // strip DESCENDING (reversed after sort)
				_qs_stack[_qs_top].low = 0;
				_qs_stack[_qs_top].high = n - 1;
				_qs_top++;

				while (_qs_top > 0 && !g_execution_halted)
				{
					_qs_top--;
					u32 _ql = _qs_stack[_qs_top].low;
					u32 _qh = _qs_stack[_qs_top].high;
					if (_ql >= _qh) continue;

					ActionVar _qpivot = arr->elements[_ql];
					u32 _qleft = _ql + 1;
					u32 _qright = _qh;

					for (;;)
					{
						// Left scan: advance while compare(pivot, elem) > 0
						while (_qleft < _qright)
						{
							int _qcmp;
							if (comparator != NULL)
							{
								ActionVar _qargs[2] = { _qpivot, arr->elements[_qleft] };
								ActionVar _qres;
								g_call_depth++;
								if (comparator->function_type == 2)
									_qres = comparator->advanced_func(app_context, _qargs, 2, NULL, NULL);
								else {
									pushVar(app_context, &_qargs[1]);
									pushVar(app_context, &_qargs[0]);
									_qres = ((ActionVar(*)(SWFAppContext*))comparator->simple_func)(app_context);
								}
								g_call_depth--;
								if (g_execution_halted) break;
								double _qd = varToDouble(&_qres);
								_qcmp = (_qd < 0) ? -1 : (_qd > 0) ? 1 : 0;
							}
							else
							{
								_qcmp = _sort_compare_vars(app_context, &_qpivot, &arr->elements[_qleft], _qs_flags);
							}
							if (_qcmp <= 0) break;
							_qleft++;
						}
						if (g_execution_halted) break;
						// Right scan: advance while compare(pivot, elem) <= 0
						while (_qright > _ql)
						{
							int _qcmp;
							if (comparator != NULL)
							{
								ActionVar _qargs[2] = { _qpivot, arr->elements[_qright] };
								ActionVar _qres;
								g_call_depth++;
								if (comparator->function_type == 2)
									_qres = comparator->advanced_func(app_context, _qargs, 2, NULL, NULL);
								else {
									pushVar(app_context, &_qargs[1]);
									pushVar(app_context, &_qargs[0]);
									_qres = ((ActionVar(*)(SWFAppContext*))comparator->simple_func)(app_context);
								}
								g_call_depth--;
								if (g_execution_halted) break;
								double _qd = varToDouble(&_qres);
								_qcmp = (_qd < 0) ? -1 : (_qd > 0) ? 1 : 0;
							}
							else
							{
								_qcmp = _sort_compare_vars(app_context, &_qpivot, &arr->elements[_qright], _qs_flags);
							}
							if (_qcmp > 0) break;
							_qright--;
						}
						if (g_execution_halted) break;
						if (_qleft >= _qright) break;
						// Swap elements[_qleft] and elements[_qright]
						ActionVar _qtmp = arr->elements[_qleft];
						arr->elements[_qleft] = arr->elements[_qright];
						arr->elements[_qright] = _qtmp;
					}

					// Place pivot at its final position
					arr->elements[_ql] = arr->elements[_qright];
					arr->elements[_qright] = _qpivot;

					// Push right subarray first (LIFO -> left processed first)
					if (_qright + 1 <= _qh && _qs_top < (int)n)
					{
						_qs_stack[_qs_top].low = _qright + 1;
						_qs_stack[_qs_top].high = _qh;
						_qs_top++;
					}
					// Push left subarray second (processed first via LIFO)
					if (_qright > 0 && _ql < _qright && _qs_top < (int)n)
					{
						_qs_stack[_qs_top].low = _ql;
						_qs_stack[_qs_top].high = _qright - 1;
						_qs_top++;
					}
				}
				FREE(_qs_stack);
			}
			// DESCENDING: reverse array after sort (same as Ruffle)
			if (flags & 2)
			{
				u32 _qlo = 0, _qhi = n - 1;
				while (_qlo < _qhi)
				{
					ActionVar _qtmp = arr->elements[_qlo];
					arr->elements[_qlo] = arr->elements[_qhi];
					arr->elements[_qhi] = _qtmp;
					_qlo++; _qhi--;
				}
			}
		}

		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		return 1;
	}

	// sortOn(fieldName|[fieldNames] [, flags|[perKeyFlags]])
	if (method_name_len == 6 && strncmp(method_name, "sortOn", 6) == 0)
	{
		// 0 args → undefined
		if (num_args == 0)
		{
			PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
			return 1;
		}

		// Extract field names (string or array of strings)
		#define SORTON_MAX_KEYS 8
		char _so_fields[SORTON_MAX_KEYS][128];
		int  _so_flags[SORTON_MAX_KEYS];
		int  _so_nkeys = 0;
		memset(_so_fields, 0, sizeof(_so_fields));
		memset(_so_flags, 0, sizeof(_so_flags));

		ActionVar* field_arg = &args[0];
		if (field_arg->type == ACTION_STACK_VALUE_ARRAY)
		{
			ASArray* _fnarr = (ASArray*) field_arg->data.numeric_value;
			if (_fnarr != NULL)
			{
				_so_nkeys = (int)_fnarr->length;
				if (_so_nkeys > SORTON_MAX_KEYS) _so_nkeys = SORTON_MAX_KEYS;
				for (int _ki = 0; _ki < _so_nkeys; _ki++)
				{
					ActionVar* _fe = &_fnarr->elements[_ki];
					if (_fe->type == ACTION_STACK_VALUE_STRING)
					{
						const uint16_t* _fu16 = varGetU16Ptr(_fe);
						if (_fu16) u16_to_utf8(_fu16, _fe->str_size, _so_fields[_ki], 128);
					}
				}
			}
		}
		else if (field_arg->type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* _fu16 = varGetU16Ptr(field_arg);
			if (_fu16) u16_to_utf8(_fu16, field_arg->str_size, _so_fields[0], 128);
			_so_nkeys = 1;
		}
		else if (field_arg->type == ACTION_STACK_VALUE_UNDEFINED)
		{
			// undefined field name → just return array unchanged
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
			return 1;
		}
		else
		{
			// null, boolean, etc. — use empty field name
			_so_nkeys = 1;
		}

		// Extract flags (number or array of per-key numbers)
		if (num_args >= 2)
		{
			ActionVar* flags_arg = &args[1];
			if (flags_arg->type == ACTION_STACK_VALUE_ARRAY)
			{
				ASArray* _flarr = (ASArray*) flags_arg->data.numeric_value;
				if (_flarr != NULL)
				{
					for (int _ki = 0; _ki < _so_nkeys; _ki++)
					{
						if ((u32)_ki < _flarr->length)
						{
							ActionVar* _fe = &_flarr->elements[_ki];
							if (_fe->type == ACTION_STACK_VALUE_F64 || _fe->type == ACTION_STACK_VALUE_F32)
							{
								double _fv = varToDouble(_fe);
								if (!isnan(_fv)) _so_flags[_ki] = (int)_fv;
							}
						}
						// else _so_flags[_ki] = 0 (already zeroed)
					}
				}
			}
			else if (flags_arg->type == ACTION_STACK_VALUE_F64 || flags_arg->type == ACTION_STACK_VALUE_F32)
			{
				double _fv = varToDouble(flags_arg);
				int _fi = isnan(_fv) ? 0 : (int)_fv;
				for (int _ki = 0; _ki < _so_nkeys; _ki++)
					_so_flags[_ki] = _fi;
			}
			// else: invalid flags type → all flags remain 0
		}

		u32 n = arr->length;
		if (n <= 1 || _so_nkeys == 0)
		{
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
			return 1;
		}

		// Helper: get the value of field _fi from element _elem
		// Returns a copy of the property value (or UNDEFINED if not found)
		#define SORTON_GET_FIELD(_elem, _ki, _out_var) do { \
			(_out_var).type = ACTION_STACK_VALUE_UNDEFINED; \
			(_out_var).data.numeric_value = 0; \
			const char* _fn = _so_fields[(_ki)]; \
			u32 _fnl = (u32)strlen(_fn); \
			if ((_elem)->type == ACTION_STACK_VALUE_OBJECT && (_elem)->data.numeric_value != 0) { \
				ASObject* _o = (ASObject*)(_elem)->data.numeric_value; \
				/* Only own properties (no prototype chain), no getter invocation */ \
				for (u32 _sopi = 0; _sopi < _o->num_used; _sopi++) { \
					if (_o->properties[_sopi].name_length == _fnl && \
					    strncmp(_o->properties[_sopi].name, _fn, _fnl) == 0) { \
						if (_o->properties[_sopi].getter == NULL) \
							(_out_var) = _o->properties[_sopi].value; \
						break; \
					} \
				} \
			} else if ((_elem)->type != ACTION_STACK_VALUE_OBJECT) { \
				/* Non-object primitive: special-case "length" on strings, else compare element itself */ \
				if ((_elem)->type == ACTION_STACK_VALUE_STRING && _fnl == 6 && memcmp(_fn, "length", 6) == 0) { \
					(_out_var).type = ACTION_STACK_VALUE_F64; \
					double _slen = (double)(_elem)->str_size; \
					VAL(double, &(_out_var).data.numeric_value) = _slen; \
				} else { \
					(_out_var) = *(_elem); \
				} \
			} \
		} while(0)

		// Compare two elements across all keys; returns negative/zero/positive
		#define SORTON_COMPARE(_ea, _eb, _result) do { \
			(_result) = 0; \
			for (int _ki2 = 0; _ki2 < _so_nkeys && (_result) == 0; _ki2++) { \
				ActionVar _va2, _vb2; \
				SORTON_GET_FIELD((_ea), _ki2, _va2); \
				SORTON_GET_FIELD((_eb), _ki2, _vb2); \
				(_result) = _sort_compare_vars(app_context, &_va2, &_vb2, _so_flags[_ki2]); \
			} \
		} while(0)

		// Only the FIRST key's flags determine UNIQUESORT/RETURNINDEXEDARRAY behavior
		int _so_any_unique = (_so_flags[0] & 4) != 0;
		int _so_any_retidx = (_so_flags[0] & 8) != 0;

		// UNIQUESORT: check for duplicates first
		if (_so_any_unique)
		{
			for (u32 _ui = 0; _ui < n; _ui++)
			{
				for (u32 _uj = _ui + 1; _uj < n; _uj++)
				{
					int _ucmp; SORTON_COMPARE(&arr->elements[_ui], &arr->elements[_uj], _ucmp);
					if (_ucmp == 0)
					{
						double _zero = 0.0;
						PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &_zero));
						return 1;
					}
				}
			}
		}

		// Sort indices
		u32* _sidx = (u32*) HALLOC(n * sizeof(u32));
		if (_sidx == NULL) { PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr); return 1; }
		for (u32 _ii = 0; _ii < n; _ii++) _sidx[_ii] = _ii;

		if (_so_any_retidx || _so_any_unique)
		{
			// Stable insertion sort (preserve equal-element order for index arrays)
			for (u32 _ii = 1; _ii < n; _ii++)
			{
				u32 _key_sidx = _sidx[_ii];
				int _jj = (int)_ii - 1;
				while (_jj >= 0)
				{
					int _scmp;
					SORTON_COMPARE(&arr->elements[_sidx[_jj]], &arr->elements[_key_sidx], _scmp);
					if (_scmp <= 0) break;
					_sidx[_jj + 1] = _sidx[_jj];
					_jj--;
				}
				_sidx[_jj + 1] = _key_sidx;
			}
			// Build and return index array
			ASArray* _ridx_arr = allocArray(app_context, n);
			if (_ridx_arr == NULL) { FREE(_sidx); PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr); return 1; }
			_ridx_arr->length = n;
			for (u32 _ii = 0; _ii < n; _ii++)
			{
				_ridx_arr->elements[_ii].type = ACTION_STACK_VALUE_F64;
				double _dv = (double) _sidx[_ii];
				VAL(double, &_ridx_arr->elements[_ii].data.numeric_value) = _dv;
			}
			FREE(_sidx);
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64) _ridx_arr);
			return 1;
		}
		else
		{
			// Stable insertion sort for plain sortOn
			for (u32 _ii = 1; _ii < n; _ii++)
			{
				u32 _key_sidx = _sidx[_ii];
				int _jj = (int)_ii - 1;
				while (_jj >= 0)
				{
					int _scmp;
					SORTON_COMPARE(&arr->elements[_sidx[_jj]], &arr->elements[_key_sidx], _scmp);
					if (_scmp <= 0) break;
					_sidx[_jj + 1] = _sidx[_jj];
					_jj--;
				}
				_sidx[_jj + 1] = _key_sidx;
			}
			// Apply sort: rearrange arr->elements in sorted order
			ActionVar* _tmp_elems = (ActionVar*) HALLOC(n * sizeof(ActionVar));
			if (_tmp_elems == NULL) { FREE(_sidx); PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr); return 1; }
			for (u32 _ii = 0; _ii < n; _ii++)
				_tmp_elems[_ii] = arr->elements[_sidx[_ii]];
			for (u32 _ii = 0; _ii < n; _ii++)
				arr->elements[_ii] = _tmp_elems[_ii];
			FREE(_tmp_elems);
			FREE(_sidx);
		}

		#undef SORTON_MAX_KEYS
		#undef SORTON_GET_FIELD
		#undef SORTON_COMPARE

		PUSH(ACTION_STACK_VALUE_ARRAY, (u64) arr);
		return 1;
	}

	#undef SORT_COMPARE_VARS

	return 0;
}

// =====================================================================
// String method helpers
// =====================================================================

// Helper: coerce an ActionVar argument to a number for string method index args.
// Handles all types (f32, f64, boolean, null, undefined, string, etc.)
static double stringArgToNumber(SWFAppContext* app_context, ActionVar* v)
{
	switch (v->type)
	{
		case ACTION_STACK_VALUE_F32: return (double) VAL(float, &v->data.numeric_value);
		case ACTION_STACK_VALUE_F64: return VAL(double, &v->data.numeric_value);
		case ACTION_STACK_VALUE_BOOLEAN: return v->data.numeric_value ? 1.0 : 0.0;
		case ACTION_STACK_VALUE_NULL: return 0.0;
		case ACTION_STACK_VALUE_UNDEFINED: return NAN;
		case ACTION_STACK_VALUE_STRING:
		{
			const uint16_t* u16 = varGetU16Ptr(v);
			if (u16 == NULL || v->str_size == 0) return NAN;
			// Convert to UTF-8 for strtod
			char buf[256];
			int len = u16_to_utf8(u16, v->str_size, buf, sizeof(buf));
			if (len == 0) return NAN;
			char* endptr;
			double d = strtod(buf, &endptr);
			if (endptr == buf) return NAN;
			return d;
		}
		default: return NAN;
	}
}

// Helper: coerce arg to int32 for string index (NaN/Inf -> 0, then truncate)
static int32_t stringArgToInt32(SWFAppContext* app_context, ActionVar* v)
{
	double d = stringArgToNumber(app_context, v);
	if (isnan(d) || isinf(d)) return 0;
	// ECMA-262 ToInt32
	return (int32_t)(int64_t)d;
}

// Helper: coerce an ActionVar to a UTF-16 string for string method arguments.
// Returns a pointer to the UTF-16 data and sets *out_len to code unit count.
static const uint16_t* stringArgToU16(SWFAppContext* app_context, ActionVar* v, u32* out_len)
{
	if (v->type == ACTION_STACK_VALUE_STRING)
	{
		const uint16_t* u16 = varGetU16Ptr(v);
		*out_len = v->str_size;
		return u16 ? u16 : u16_empty;
	}
	// For objects, try calling toString() method first
	if (v->type == ACTION_STACK_VALUE_OBJECT && v->data.numeric_value != 0)
	{
		int ts_found = 0;
		ActionVar ts = objectCallToString(app_context, v, &ts_found);
		if (ts_found && ts.type == ACTION_STACK_VALUE_STRING)
		{
			const uint16_t* u16 = varGetU16Ptr(&ts);
			*out_len = ts.str_size;
			return u16 ? u16 : u16_empty;
		}
	}
	// For other types, convert via varToStringBuf then to UTF-16
	char buf[256];
	int len = varToStringBuf(app_context, v, buf, sizeof(buf));
	if (len <= 0) { *out_len = 0; return u16_empty; }
	u32 u16_len;
	uint16_t* u16 = utf8_to_u16(app_context, buf, (u32)len, &u16_len);
	*out_len = u16_len;
	return u16;
}

// Helper function to call built-in string methods (UTF-16 native)
// str_value is a uint16_t* array, str_len is the number of UTF-16 code units.
// Returns 1 if method was handled, 0 if not found
static int callStringPrimitiveMethod(SWFAppContext* app_context, char* str_buffer,
                                      const uint16_t* str_value, u32 str_len,
                                      const char* method_name, u32 method_name_len,
                                      ActionVar* args, u32 num_args)
{
	(void)str_buffer;
	int slen = (int)str_len; // UTF-16 code unit count

	// toUpperCase() - no arguments
	if (method_name_len == 11 && strncmp(method_name, "toUpperCase", 11) == 0)
	{
		uint16_t* result = (uint16_t*) HALLOC((str_len + 1) * sizeof(uint16_t));
		for (u32 i = 0; i < str_len; i++)
		{
			uint16_t c = str_value[i];
			if (c >= 'a' && c <= 'z') {
				result[i] = c - ('a' - 'A');
			} else if (c > 0x7F) {
				// Binary search in lower-to-upper table
				int lo = 0, hi = CASE_MAP_LOWER_TO_UPPER_COUNT - 1;
				uint16_t mapped = c;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if (case_map_lower_to_upper[mid][0] == c) { mapped = case_map_lower_to_upper[mid][1]; break; }
					if (case_map_lower_to_upper[mid][0] < c) lo = mid + 1; else hi = mid - 1;
				}
				result[i] = mapped;
			} else {
				result[i] = c;
			}
		}
		result[str_len] = 0;
		PUSH_U16(result, str_len);
		return 1;
	}

	// toLowerCase() - no arguments
	if (method_name_len == 11 && strncmp(method_name, "toLowerCase", 11) == 0)
	{
		uint16_t* result = (uint16_t*) HALLOC((str_len + 1) * sizeof(uint16_t));
		for (u32 i = 0; i < str_len; i++)
		{
			uint16_t c = str_value[i];
			if (c >= 'A' && c <= 'Z') {
				result[i] = c + ('a' - 'A');
			} else if (c > 0x7F) {
				// Binary search in upper-to-lower table
				int lo = 0, hi = CASE_MAP_UPPER_TO_LOWER_COUNT - 1;
				uint16_t mapped = c;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if (case_map_upper_to_lower[mid][0] == c) { mapped = case_map_upper_to_lower[mid][1]; break; }
					if (case_map_upper_to_lower[mid][0] < c) lo = mid + 1; else hi = mid - 1;
				}
				result[i] = mapped;
			} else {
				result[i] = c;
			}
		}
		result[str_len] = 0;
		PUSH_U16(result, str_len);
		return 1;
	}

	// charAt(index) - 1 argument
	if (method_name_len == 6 && strncmp(method_name, "charAt", 6) == 0)
	{
		int index = 0;
		if (num_args > 0)
			index = stringArgToInt32(app_context, &args[0]);

		// Bounds check using UTF-16 length
		if (index < 0 || index >= slen)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			uint16_t* ch = (uint16_t*) HALLOC(2 * sizeof(uint16_t));
			ch[0] = str_value[index];
			ch[1] = 0;
			PUSH_U16(ch, 1);
		}
		return 1;
	}

	// charCodeAt(index) - 1 argument
	if (method_name_len == 10 && strncmp(method_name, "charCodeAt", 10) == 0)
	{
		int index = 0;
		if (num_args > 0)
			index = stringArgToInt32(app_context, &args[0]);

		if (index < 0 || index >= slen)
		{
			// SWF5: positive out-of-range returns 0, negative returns NaN
			// SWF6+: all out-of-range returns NaN
			if (EFFECTIVE_SWF_VERSION() < 6 && index >= 0)
			{
				float zero = 0.0f;
				PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &zero));
			}
			else
			{
				float nan_val = NAN;
				PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &nan_val));
			}
		}
		else
		{
			// Return UTF-16 code unit value
			float code = (float)str_value[index];
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &code));
		}
		return 1;
	}

	// substr(start, length) - 0-2 arguments
	if (method_name_len == 6 && strncmp(method_name, "substr", 6) == 0)
	{
		// No args -> return undefined
		if (num_args == 0)
		{
			pushUndefined(app_context);
			return 1;
		}

		int has_length_arg = (num_args > 1 && args[1].type != ACTION_STACK_VALUE_UNDEFINED);
		int has_start_arg = (args[0].type != ACTION_STACK_VALUE_UNDEFINED);

		// Parse start
		int start;
		if (!has_start_arg || args[0].type == ACTION_STACK_VALUE_NULL)
			start = 0;
		else
			start = stringArgToInt32(app_context, &args[0]);

		// Handle negative start (count from end)
		if (start < 0)
		{
			start = slen + start;
			if (start < 0) start = 0;
		}

		// Parse length
		int length;
		if (!has_length_arg)
		{
				// No length arg or undefined -> rest of string
			length = slen - start;
		}
		else if (args[1].type == ACTION_STACK_VALUE_NULL)
		{
			length = 0;
		}
		else
		{
			length = stringArgToInt32(app_context, &args[1]);

			// Handle negative length: Flash semantics
			// Negative length means "stop |neg_len| chars before end of string"
			// effective_len = str.length + neg_len
			// If start + effective_len >= str.length, return ""
			if (length < 0)
			{
				int effective_len = slen + length;
				if (effective_len <= 0 || start + effective_len >= slen)
				{
					PUSH_U16(u16_empty, 0);
					return 1;
				}
				length = effective_len;
			}
		}

		// Bounds check
		if (start >= slen || length <= 0)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			if (start + length > slen)
				length = slen - start;
			uint16_t* result = (uint16_t*) HALLOC((length + 1) * sizeof(uint16_t));
			memcpy(result, str_value + start, length * sizeof(uint16_t));
			result[length] = 0;
			PUSH_U16(result, (u32)length);
		}
		return 1;
	}

	// substring(start, end) - 0-2 arguments (different from substr!)
	if (method_name_len == 9 && strncmp(method_name, "substring", 9) == 0)
	{
		if (num_args == 0)
		{
			pushUndefined(app_context);
			return 1;
		}

		// Parse start - undefined means default to full string
		int start;
		if (args[0].type == ACTION_STACK_VALUE_UNDEFINED)
			start = 0;
		else if (args[0].type == ACTION_STACK_VALUE_NULL)
			start = 0;
		else
			start = stringArgToInt32(app_context, &args[0]);

		// Parse end
		int end;
		if (num_args <= 1 || args[1].type == ACTION_STACK_VALUE_UNDEFINED)
			end = slen;
		else if (args[1].type == ACTION_STACK_VALUE_NULL)
			end = 0;
		else
			end = stringArgToInt32(app_context, &args[1]);

		// Clamp to valid range
		if (start < 0) start = 0;
		if (end < 0) end = 0;
		if (start > slen) start = slen;
		if (end > slen) end = slen;

		// Swap if start > end (substring swaps, unlike slice)
		if (start > end)
		{
			int temp = start;
			start = end;
			end = temp;
		}

		int length = end - start;
		if (length <= 0)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			uint16_t* result = (uint16_t*) HALLOC((length + 1) * sizeof(uint16_t));
			memcpy(result, str_value + start, length * sizeof(uint16_t));
			result[length] = 0;
			PUSH_U16(result, (u32)length);
		}
		return 1;
	}

	// slice(start, end) - 0-2 arguments
	if (method_name_len == 5 && strncmp(method_name, "slice", 5) == 0)
	{
		if (num_args == 0)
		{
			pushUndefined(app_context);
			return 1;
		}

		// Parse start
		int start;
		if (args[0].type == ACTION_STACK_VALUE_UNDEFINED)
			start = 0;
		else if (args[0].type == ACTION_STACK_VALUE_NULL)
			start = 0;
		else
			start = stringArgToInt32(app_context, &args[0]);

		// Parse end
		int end;
		if (num_args <= 1 || args[1].type == ACTION_STACK_VALUE_UNDEFINED)
			end = slen;
		else if (args[1].type == ACTION_STACK_VALUE_NULL)
			end = 0;
		else
			end = stringArgToInt32(app_context, &args[1]);

		// Handle negative indices (count from end)
		if (start < 0) start = slen + start;
		if (end < 0) end = slen + end;

		// Clamp
		if (start < 0) start = 0;
		if (end < 0) end = 0;
		if (start > slen) start = slen;
		if (end > slen) end = slen;

		// Unlike substring, slice does NOT swap (returns "" if start >= end)
		int length = end - start;
		if (length <= 0)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			uint16_t* result = (uint16_t*) HALLOC((length + 1) * sizeof(uint16_t));
			memcpy(result, str_value + start, length * sizeof(uint16_t));
			result[length] = 0;
			PUSH_U16(result, (u32)length);
		}
		return 1;
	}

	// concat(str1, str2, ...) - variable arguments
	if (method_name_len == 6 && strncmp(method_name, "concat", 6) == 0)
	{
		if (num_args == 0)
		{
			// concat() with no args -> return copy of this string
			if (str_len == 0)
			{
				PUSH_U16(u16_empty, 0);
			}
			else
			{
				uint16_t* result = (uint16_t*) HALLOC((str_len + 1) * sizeof(uint16_t));
				memcpy(result, str_value, str_len * sizeof(uint16_t));
				result[str_len] = 0;
				PUSH_U16(result, str_len);
			}
			return 1;
		}

		// First pass: collect all arg UTF-16 data and compute total length
		u32 total_len = str_len;
		const uint16_t* arg_u16s[16];
		u32 arg_lens[16];
		int effective_args = num_args > 16 ? 16 : (int)num_args;

		int swf_ver = EFFECTIVE_SWF_VERSION();
		for (int i = 0; i < effective_args; i++)
		{
			// SWF5: undefined in concat is "" (empty string)
			if (swf_ver < 6 && args[i].type == ACTION_STACK_VALUE_UNDEFINED)
			{
				arg_u16s[i] = u16_empty;
				arg_lens[i] = 0;
			}
			else
			{
				arg_u16s[i] = stringArgToU16(app_context, &args[i], &arg_lens[i]);
			}
			total_len += arg_lens[i];
		}

		// Allocate and build result
		uint16_t* result = (uint16_t*) HALLOC((total_len + 1) * sizeof(uint16_t));
		if (str_len > 0)
			memcpy(result, str_value, str_len * sizeof(uint16_t));
		u32 pos = str_len;
		for (int i = 0; i < effective_args; i++)
		{
			if (arg_lens[i] > 0)
				memcpy(result + pos, arg_u16s[i], arg_lens[i] * sizeof(uint16_t));
			pos += arg_lens[i];
		}
		result[pos] = 0;
		PUSH_U16(result, pos);
		return 1;
	}

	// indexOf(searchString, startIndex) - 0-2 arguments
	if (method_name_len == 7 && strncmp(method_name, "indexOf", 7) == 0)
	{
		// No args -> return undefined
		if (num_args == 0)
		{
			pushUndefined(app_context);
			return 1;
		}

		// Coerce search string from argument as UTF-16
		u32 search_len;
		const uint16_t* search_u16;
		// SWF5: undefined arg -> search for "" (empty string)
		if (EFFECTIVE_SWF_VERSION() < 6 && args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			search_u16 = u16_empty;
			search_len = 0;
		}
		else
		{
			search_u16 = stringArgToU16(app_context, &args[0], &search_len);
		}

		// Parse start index (in UTF-16 units)
		int start_index = 0;
		if (num_args > 1)
		{
			double sv = stringArgToNumber(app_context, &args[1]);
			if (!isnan(sv))
				start_index = (int32_t)(int64_t)sv;
			// Flash: negative start -> search from beginning
			if (start_index < 0) start_index = 0;
		}

		// Search for substring in UTF-16 array
		int found_index = -1;
		if (search_len == 0)
		{
			// Empty search string: return start_index if in range
			found_index = start_index <= slen ? start_index : -1;
		}
		else if ((int)search_len <= slen)
		{
			for (int i = start_index; i <= slen - (int)search_len; i++)
			{
				if (memcmp(str_value + i, search_u16, search_len * sizeof(uint16_t)) == 0)
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

	// lastIndexOf(searchString, endIndex) - 0-2 arguments
	if (method_name_len == 11 && strncmp(method_name, "lastIndexOf", 11) == 0)
	{
		// No args -> return undefined
		if (num_args == 0)
		{
			pushUndefined(app_context);
			return 1;
		}

		// Coerce search string from argument as UTF-16
		u32 search_len;
		const uint16_t* search_u16;
		// SWF5: undefined arg -> search for "" (empty string)
		if (EFFECTIVE_SWF_VERSION() < 6 && args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			search_u16 = u16_empty;
			search_len = 0;
		}
		else
		{
			search_u16 = stringArgToU16(app_context, &args[0], &search_len);
		}

		// Parse end index (position to start searching backwards from, in UTF-16 units)
		int end_index = slen; // default: search from end
		if (num_args > 1)
		{
			double ev = stringArgToNumber(app_context, &args[1]);
			if (!isnan(ev))
			{
				end_index = (int32_t)(int64_t)ev;
			}
			// else: undefined -> search from end (keep default)
		}

		// Search backwards
		int found_index = -1;
		if (search_len == 0)
		{
			// Empty search string: return min(end_index, slen)
			if (end_index < 0) found_index = -1;
			else found_index = end_index <= slen ? end_index : slen;
		}
		else if ((int)search_len <= slen)
		{
			// Start from min(end_index, slen - search_len) and go backwards
			int start_from = slen - (int)search_len;
			if (end_index < start_from) start_from = end_index;
			for (int i = start_from; i >= 0; i--)
			{
				if (memcmp(str_value + i, search_u16, search_len * sizeof(uint16_t)) == 0)
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

	// split(delimiter, limit) - 0-2 arguments
	if (method_name_len == 5 && strncmp(method_name, "split", 5) == 0)
	{
		// SWF version affects split behavior
		int swf_ver = EFFECTIVE_SWF_VERSION();

		// No args or undefined delimiter
		if (num_args == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			if (swf_ver < 6)
			{
				// SWF5: split() and split(undefined) use "," as delimiter
				// Fall through to normal split logic with "," delimiter
			}
			else
			{
				// SWF6+: split() and split(undefined) return whole string as 1 element
				ASArray* arr = allocArray(app_context, 1);
				ActionVar elem = {0};
				elem.type = ACTION_STACK_VALUE_STRING;
				elem.str_size = str_len;
				elem.data.numeric_value = (u64)str_value;
				setArrayElement(app_context, arr, 0, &elem);
				PUSH(ACTION_STACK_VALUE_ARRAY, (u64)arr);
				return 1;
			}
		}

		// Coerce delimiter to UTF-16
		u32 delim_len;
		const uint16_t* delim_u16;
		// SWF5: undefined/no-args fell through here with "," as delimiter
		if (num_args == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED)
		{
			delim_u16 = u16_comma;
			delim_len = 1;
		}
		else
		{
			delim_u16 = stringArgToU16(app_context, &args[0], &delim_len);
		}

		// Parse limit
		int limit = -1;
		if (num_args > 1)
		{
			if (args[1].type == ACTION_STACK_VALUE_UNDEFINED)
				limit = -1; // no limit
			else if (args[1].type == ACTION_STACK_VALUE_NULL)
				limit = 0;
			else
			{
				double lv = stringArgToNumber(app_context, &args[1]);
				if (!isnan(lv))
				{
					limit = (int)lv;
					if (limit < 0) limit = 0;
				}
			}
		}

		if (limit == 0)
		{
			PUSH(ACTION_STACK_VALUE_ARRAY, (u64)allocArray(app_context, 1));
			return 1;
		}

		ASArray* arr = allocArray(app_context, 4);
		u32 count = 0;

		if (delim_len == 0)
		{
			if (swf_ver < 6)
			{
				// SWF5: split("") returns array with whole string as one element
				ActionVar elem = {0};
				elem.type = ACTION_STACK_VALUE_STRING;
				elem.str_size = str_len;
				elem.data.numeric_value = (u64)str_value;
				setArrayElement(app_context, arr, 0, &elem);
			}
			else
			{
				// SWF6+: split each UTF-16 code unit into its own 1-element string
				for (int u = 0; u < slen; u++)
				{
					if (limit >= 0 && (int)count >= limit) break;
					uint16_t* ch = (uint16_t*) HALLOC(2 * sizeof(uint16_t));
					ch[0] = str_value[u];
					ch[1] = 0;
					ActionVar elem = {0};
					elem.type = ACTION_STACK_VALUE_STRING;
					elem.str_size = 1;
					elem.data.numeric_value = (u64)ch;
					setArrayElement(app_context, arr, count++, &elem);
				}
			}
		}
		else
		{
			int start = 0;
			for (int i = 0; i <= slen - (int)delim_len; i++)
			{
				if (limit >= 0 && (int)count >= limit) break;
				if (memcmp(str_value + i, delim_u16, delim_len * sizeof(uint16_t)) == 0)
				{
					int seg_len = i - start;
					uint16_t* seg;
					if (seg_len > 0)
					{
						seg = (uint16_t*) HALLOC((seg_len + 1) * sizeof(uint16_t));
						memcpy(seg, str_value + start, seg_len * sizeof(uint16_t));
						seg[seg_len] = 0;
					}
					else
					{
						seg = (uint16_t*) u16_empty;
					}
					ActionVar elem = {0};
					elem.type = ACTION_STACK_VALUE_STRING;
					elem.str_size = (u32)seg_len;
					elem.data.numeric_value = (u64)seg;
					setArrayElement(app_context, arr, count++, &elem);
					i += (int)delim_len - 1;
					start = i + 1;
				}
			}
			// Add remaining segment
			if (limit < 0 || (int)count < limit)
			{
				int seg_len = slen - start;
				uint16_t* seg;
				if (seg_len > 0)
				{
					seg = (uint16_t*) HALLOC((seg_len + 1) * sizeof(uint16_t));
					memcpy(seg, str_value + start, seg_len * sizeof(uint16_t));
					seg[seg_len] = 0;
				}
				else
				{
					seg = (uint16_t*) u16_empty;
				}
				ActionVar elem = {0};
				elem.type = ACTION_STACK_VALUE_STRING;
				elem.str_size = (u32)seg_len;
				elem.data.numeric_value = (u64)seg;
				setArrayElement(app_context, arr, count++, &elem);
			}
		}

		PUSH(ACTION_STACK_VALUE_ARRAY, (u64)arr);
		return 1;
	}

	// toString() - return the string itself
	if (method_name_len == 8 && strncmp(method_name, "toString", 8) == 0)
	{
		if (str_len == 0)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			uint16_t* result = (uint16_t*) HALLOC((str_len + 1) * sizeof(uint16_t));
			memcpy(result, str_value, str_len * sizeof(uint16_t));
			result[str_len] = 0;
			PUSH_U16(result, str_len);
		}
		return 1;
	}

	// valueOf() - return the string itself
	if (method_name_len == 7 && strncmp(method_name, "valueOf", 7) == 0)
	{
		if (str_len == 0)
		{
			PUSH_U16(u16_empty, 0);
		}
		else
		{
			uint16_t* result = (uint16_t*) HALLOC((str_len + 1) * sizeof(uint16_t));
			memcpy(result, str_value, str_len * sizeof(uint16_t));
			result[str_len] = 0;
			PUSH_U16(result, str_len);
		}
		return 1;
	}

	// Method not found
	return 0;
}

void actionCallMethod(SWFAppContext* app_context, char* str_buffer)
{
	if (g_execution_halted) return;
	g_scope_app_context = app_context;

	// 1. Pop method name from stack
	// Check for undefined BEFORE convertString — SWF >= 7 converts undefined
	// to the string "undefined" which would prevent the empty-name path from
	// triggering (needed for CallMethod on a function reference).
	// NULL is NOT included here: test[null]() should look up "null" property.
	int method_is_empty = (STACK_TOP_TYPE == ACTION_STACK_VALUE_UNDEFINED);
	char method_name_buffer[17];
	convertString(app_context, method_name_buffer);
	char _cm_buf[512];
	u32 method_name_len = method_is_empty ? 0 :
		(u32)u16_to_utf8((const uint16_t*)STACK_TOP_VALUE, STACK_TOP_N, _cm_buf, sizeof(_cm_buf));
	const char* method_name = _cm_buf;
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

		// Handle addProperty as built-in method
		if (method_name_len == 11 && strncmp(method_name, "addProperty", 11) == 0)
		{
			u64 result = 0; // boolean false
			if (num_args >= 3 && (args[0].type == ACTION_STACK_VALUE_STRING ||
			                      args[0].type == ACTION_STACK_VALUE_F64 ||
			                      args[0].type == ACTION_STACK_VALUE_F32))
			{
				char _addprop_buf[512];
				const char* prop_name;
				u32 prop_name_len;
				if (args[0].type == ACTION_STACK_VALUE_STRING)
				{
					const uint16_t* _addprop_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_addprop_u16, args[0].str_size, _addprop_buf, sizeof(_addprop_buf));
					prop_name = _addprop_buf;
					prop_name_len = (u32)strlen(prop_name);
				}
				else
				{
					double d = varToDouble(&args[0]);
					s64 as_int = (s64)d;
					if ((double)as_int == d)
						snprintf(_addprop_buf, sizeof(_addprop_buf), "%lld", (long long)as_int);
					else
						snprintf(_addprop_buf, sizeof(_addprop_buf), "%.15g", d);
					prop_name = _addprop_buf;
					prop_name_len = (u32)strlen(_addprop_buf);
				}

				ASFunction* getter = NULL;
				if (args[1].type == ACTION_STACK_VALUE_FUNCTION)
					getter = (ASFunction*) args[1].data.numeric_value;

				ASFunction* setter = NULL;
				if (args[2].type == ACTION_STACK_VALUE_FUNCTION)
					setter = (ASFunction*) args[2].data.numeric_value;

				// Store getter/setter directly on the target object's property
				// Find or create the property, then set its getter/setter pointers
				ASProperty* prop = NULL;
				for (u32 i = 0; i < obj->num_used; i++)
				{
					if (obj->properties[i].name_length == prop_name_len &&
					    strncmp(obj->properties[i].name, prop_name, prop_name_len) == 0)
					{
						prop = &obj->properties[i];
						break;
					}
				}
				if (prop == NULL)
				{
					// Create the property with UNDEFINED value
					ActionVar marker = {0};
					marker.type = ACTION_STACK_VALUE_UNDEFINED;
					setProperty(app_context, obj, prop_name, prop_name_len, &marker);
					// Find it again after setProperty (may have reallocated)
					for (u32 i = 0; i < obj->num_used; i++)
					{
						if (obj->properties[i].name_length == prop_name_len &&
						    strncmp(obj->properties[i].name, prop_name, prop_name_len) == 0)
						{
							prop = &obj->properties[i];
							break;
						}
					}
				}
				if (prop != NULL)
				{
					prop->getter = (void*)getter;
					prop->setter = (void*)setter;
					result = 1; // boolean true
				}
			}

			if (args != NULL) FREE(args);
			PUSH(ACTION_STACK_VALUE_BOOLEAN, result);
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
				// Invoke DefineFunction2 with 'this' binding.
				// Push a local scope so GetVariable("this"/"super"/"arguments") can
				// resolve them when neither preload nor suppress is set (flags == 0 bits).
				ASObject* local_scope = allocObject(app_context, 8);
				if (scope_depth < MAX_SCOPE_DEPTH) {
					scope_is_with[scope_depth] = 0;
					scope_mc[scope_depth] = NULL;
					scope_chain[scope_depth++] = local_scope;
				}

				u16 f2flags = func->flags;
				int f2_preload_this  = (f2flags & 0x0001);
				int f2_suppress_this = (f2flags & 0x0002);
				int f2_preload_args  = (f2flags & 0x0004);
				int f2_suppress_args = (f2flags & 0x0008);
				int f2_preload_super = (f2flags & 0x0010);
				int f2_suppress_super= (f2flags & 0x0020);

				// When neither preload nor suppress is set, the variable is accessible
				// by name inside the function body (scope-chain lookup).
				if (!f2_preload_this && !f2_suppress_this) {
					ActionVar this_var = {0};
					if (obj != NULL) {
						this_var.type = ACTION_STACK_VALUE_OBJECT;
						this_var.data.numeric_value = (u64)obj;
					} else {
						extern MovieClip root_movieclip;
						this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
						this_var.data.numeric_value = (u64)&root_movieclip;
					}
					setProperty(app_context, local_scope, "this", 4, &this_var);
				}
				// Track calling function for arguments.caller
				ASFunction* prev_executing_func_am2 = g_current_executing_func;

				if (!f2_preload_args && !f2_suppress_args) {
					ASArray* arguments_arr = allocArray(app_context, num_args);
					for (u32 i = 0; i < num_args; i++)
						setArrayElement(app_context, arguments_arr, i, &args[i]);
					setupArgumentsProps(app_context, arguments_arr, func, prev_executing_func_am2);
					ActionVar args_var = {0};
					args_var.type = ACTION_STACK_VALUE_ARRAY;
					args_var.data.numeric_value = (u64)arguments_arr;
					setProperty(app_context, local_scope, "arguments", 9, &args_var);
				}
				if (!f2_preload_super && !f2_suppress_super) {
					ASObject* super_obj = allocObject(app_context, 0);
					ActionVar super_var = {0};
					super_var.type = ACTION_STACK_VALUE_OBJECT;
					super_var.data.numeric_value = (u64)super_obj;
					setProperty(app_context, local_scope, "super", 5, &super_var);
				}

				ActionVar* registers = NULL;
				if (func->register_count > 0) {
					registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));
				}

				g_call_depth++;
				g_prev_executing_func = prev_executing_func_am2;
				g_current_executing_func = func;
				g_c_function_this_obj = obj;
				ActionVar result = func->advanced_func(app_context, args, num_args, registers, (void*) obj);
				g_c_function_this_obj = NULL;
				g_current_executing_func = prev_executing_func_am2;
				g_call_depth--;

				if (scope_depth > 0) scope_depth--;
				releaseObject(app_context, local_scope);
				if (registers != NULL) FREE(registers);
				if (args != NULL) FREE(args);

				pushVar(app_context, &result);
			}
			else if (func != NULL && func->function_type == 1 && func->simple_func != NULL)
			{
				// Invoke simple function (DefineFunction type 1) as method
				// Create local scope with arguments object for proper arguments.callee/caller
				ASFunction* prev_executing_func_am1 = g_current_executing_func;
				ASObject* local_scope_am1 = allocObject(app_context, 8);
				ASArray* arguments_arr_am1 = allocArray(app_context, num_args > 0 ? num_args : 1);
				for (u32 i = 0; i < num_args; i++)
				{
					setArrayElement(app_context, arguments_arr_am1, i, &args[i]);
					pushVar(app_context, &args[i]);
				}
				setupArgumentsProps(app_context, arguments_arr_am1, func, prev_executing_func_am1);
				ActionVar args_var_am1 = {0};
				args_var_am1.type = ACTION_STACK_VALUE_ARRAY;
				args_var_am1.data.numeric_value = (u64)arguments_arr_am1;
				setProperty(app_context, local_scope_am1, "arguments", 9, &args_var_am1);
				if (scope_depth < MAX_SCOPE_DEPTH) {
					scope_is_with[scope_depth] = 0;
					scope_mc[scope_depth] = NULL;
					scope_chain[scope_depth++] = local_scope_am1;
				}
				if (args != NULL) FREE(args);

				g_call_depth++;
				g_prev_executing_func = prev_executing_func_am1;
				g_current_executing_func = func;
				ActionVar result;
				result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
				g_current_executing_func = prev_executing_func_am1;
				g_call_depth--;

				if (scope_depth > 0) scope_depth--;
				releaseObject(app_context, local_scope_am1);

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
			// Array.valueOf() returns the array itself
			if (method_name_len == 7 && strncmp(method_name, "valueOf", 7) == 0)
			{
				pushVar(app_context, &obj_var);
			}
			else
			{
				pushUndefined(app_context);
			}
		}
		return;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_STRING)
	{
		// String primitive - call built-in string methods (UTF-16 native)
		const uint16_t* str_value = varGetU16Ptr(&obj_var);
		if (str_value == NULL) str_value = u16_empty;
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
	else if (obj_var.type == ACTION_STACK_VALUE_FUNCTION)
	{
		// Function object - handle toString, valueOf, call, apply
		ASFunction* func = (ASFunction*) obj_var.data.numeric_value;

		if (method_name_len == 4 && strncmp(method_name, "call", 4) == 0)
		{
			// Function.call(thisArg, arg1, arg2, ...)
			// Skip thisArg (args[0]), pass remaining args to the function
			if (func != NULL)
			{
				u32 call_args = num_args > 1 ? num_args - 1 : 0;
				// Push args in reverse order (actionCallFunction pops them back)
				for (int i = (int)num_args - 1; i >= 1; i--)
					pushVar(app_context, &args[i]);
				// Push arg count
				PUSH(ACTION_STACK_VALUE_F64, 0);
				VAL(double, &STACK_TOP_VALUE) = (double) call_args;
				// Push function name on top
				PUSH_STR(func->name, strlen(func->name));
				if (args != NULL) FREE(args);
				char buf[17];
				actionCallFunction(app_context, buf);
			}
			else
			{
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
			return;
		}

		if (method_name_len == 5 && strncmp(method_name, "apply", 5) == 0)
		{
			// Function.apply(thisArg, argsArray)
			if (func != NULL)
			{
				// Extract thisArg
				void* this_obj = NULL;
				if (num_args >= 1 && (args[0].type == ACTION_STACK_VALUE_OBJECT ||
				                      args[0].type == ACTION_STACK_VALUE_MOVIECLIP))
					this_obj = (void*)(uintptr_t) args[0].data.numeric_value;

				// Extract arguments from array
				ActionVar* apply_args = NULL;
				u32 apply_arg_count = 0;

				if (num_args >= 2 && args[1].type == ACTION_STACK_VALUE_ARRAY)
				{
					ASArray* arr = (ASArray*)(uintptr_t) args[1].data.numeric_value;
					if (arr != NULL)
					{
						apply_arg_count = arr->length;
						if (apply_arg_count > 0)
						{
							apply_args = (ActionVar*) HALLOC(sizeof(ActionVar) * apply_arg_count);
							for (u32 i = 0; i < apply_arg_count; i++)
							{
								ActionVar* elem = getArrayElement(arr, i);
								if (elem != NULL)
									apply_args[i] = *elem;
								else
								{
									apply_args[i].type = ACTION_STACK_VALUE_UNDEFINED;
									apply_args[i].data.numeric_value = 0;
								}
							}
						}
					}
				}

				if (g_call_depth >= g_max_call_depth - 1)
				{
					if (apply_args != NULL) FREE(apply_args);
					if (args != NULL) FREE(args);
					g_execution_halted = 1;
					pushUndefined(app_context);
				}
				else if (func->function_type == 2)
				{
					ActionVar* registers = NULL;
					if (func->register_count > 0)
						registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));

					ASFunction* prev_executing_func_ap2 = g_current_executing_func;
					g_call_depth++;
					g_prev_executing_func = prev_executing_func_ap2;
					g_current_executing_func = func;
					ActionVar result = func->advanced_func(app_context, apply_args, apply_arg_count, registers, this_obj);
					g_current_executing_func = prev_executing_func_ap2;
					g_call_depth--;

					if (registers != NULL) FREE(registers);
					if (apply_args != NULL) FREE(apply_args);
					if (args != NULL) FREE(args);
					pushVar(app_context, &result);
				}
				else if (func->function_type == 1 && func->simple_func != NULL)
				{
					// Create local scope + arguments object for apply() on simple functions
					ASFunction* prev_executing_func_ap = g_current_executing_func;
					ASObject* local_scope_ap = allocObject(app_context, 8);
					ASArray* arguments_arr_ap = allocArray(app_context, apply_arg_count > 0 ? apply_arg_count : 1);
					for (u32 i = 0; i < apply_arg_count; i++)
					{
						setArrayElement(app_context, arguments_arr_ap, i, &apply_args[i]);
						pushVar(app_context, &apply_args[i]);
					}
					setupArgumentsProps(app_context, arguments_arr_ap, func, prev_executing_func_ap);
					ActionVar args_var_ap = {0};
					args_var_ap.type = ACTION_STACK_VALUE_ARRAY;
					args_var_ap.data.numeric_value = (u64)arguments_arr_ap;
					setProperty(app_context, local_scope_ap, "arguments", 9, &args_var_ap);
					if (scope_depth < MAX_SCOPE_DEPTH) {
						scope_is_with[scope_depth] = 0;
						scope_mc[scope_depth] = NULL;
						scope_chain[scope_depth++] = local_scope_ap;
					}

					if (apply_args != NULL) FREE(apply_args);
					if (args != NULL) FREE(args);

					g_call_depth++;
					g_prev_executing_func = prev_executing_func_ap;
					g_current_executing_func = func;
					ActionVar result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
					g_current_executing_func = prev_executing_func_ap;
					g_call_depth--;

					if (scope_depth > 0) scope_depth--;
					releaseObject(app_context, local_scope_ap);

					pushVar(app_context, &result);
				}
				else if (func->function_type == 1 && func->simple_func == NULL && this_obj != NULL)
				{
					// Built-in MC method (e.g., removeMovieClip) applied to a target
					if (apply_args != NULL) FREE(apply_args);
					if (args != NULL) FREE(args);
#ifdef NO_GRAPHICS
					if (strcmp(func->name, "removeMovieClip") == 0) {
						MovieClip* _apply_mc = (MovieClip*)this_obj;
						#ifndef AVM_MAX_REMOVE_DEPTH
						#define AVM_MAX_REMOVE_DEPTH 2130690032
						#endif
						if (_apply_mc->depth >= 0 && _apply_mc->depth < AVM_MAX_REMOVE_DEPTH) {
							if (_apply_mc->dynamic_props != NULL) {
								ActionVar* _ah = getProperty((ASObject*)_apply_mc->dynamic_props, "onUnload", 8);
								if (_ah != NULL && _ah->type == ACTION_STACK_VALUE_FUNCTION) {
									ASFunction* _af = (ASFunction*) _ah->data.numeric_value;
									if (_af != NULL) queueOnUnload(_af, _apply_mc);
								}
							}
							MovieClip* _ap = _apply_mc->parent ? _apply_mc->parent : &root_movieclip;
							if (_ap->dynamic_props != NULL && _apply_mc->name[0]) {
								ActionVar _au = {0}; _au.type = ACTION_STACK_VALUE_UNDEFINED;
								setProperty(app_context, (ASObject*)_ap->dynamic_props,
								            _apply_mc->name, strlen(_apply_mc->name), &_au);
							}
							if (_apply_mc->name[0]) {
								ActionVar _au = {0}; _au.type = ACTION_STACK_VALUE_UNDEFINED;
								setVariableByName(_apply_mc->name, &_au);
							}
							_apply_mc->depth = INT_MIN;
							for (int _ai = 0; _ai < child_mc_count; _ai++) {
								if (child_mc_cache[_ai] == _apply_mc) { child_mc_cache[_ai] = NULL; break; }
							}
						}
					}
#endif
					pushUndefined(app_context);
				}
				else
				{
					if (apply_args != NULL) FREE(apply_args);
					if (args != NULL) FREE(args);
					pushUndefined(app_context);
				}
			}
			else
			{
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
			return;
		}

		if (method_name_len == 8 && strncmp(method_name, "toString", 8) == 0)
		{
			if (args != NULL) FREE(args);
			// Check if toString was overridden on this function's own_props
			if (func != NULL && func->own_props != NULL)
			{
				ActionVar* ts_prop = getProperty(func->own_props, "toString", 8);
				if (ts_prop != NULL)
				{
					// toString exists on own_props — if it's undefined, return undefined
					if (ts_prop->type == ACTION_STACK_VALUE_UNDEFINED)
					{
						pushUndefined(app_context);
						return;
					}
					// If it's a function, call it
					if (ts_prop->type == ACTION_STACK_VALUE_FUNCTION)
					{
						ASFunction* ts_func = lookupFunctionFromVar(ts_prop);
						if (ts_func != NULL && ts_func->function_type == 1 && ts_func->simple_func != NULL)
						{
							ActionVar result = ((ActionVar(*)(SWFAppContext*))ts_func->simple_func)(app_context);
							pushVar(app_context, &result);
							return;
						}
					}
				}
			}
			// Default: Function.toString() returns "[type Function]"
			ActionVar result;
			result.type = ACTION_STACK_VALUE_STRING;
			result.str_size = 15;
			result.data.numeric_value = (u64) u16_type_Function;
			pushVar(app_context, &result);
		}
		else if (method_name_len == 7 && strncmp(method_name, "valueOf", 7) == 0)
		{
			if (args != NULL) FREE(args);
			// Function.valueOf() returns the function itself
			pushVar(app_context, &obj_var);
		}
		else
		{
			// Look up arbitrary method on function's own_props (e.g., MyClass.staticMethod())
			ActionVar* method_prop = NULL;
			if (func != NULL && func->own_props != NULL)
				method_prop = getPropertyWithPrototype(func->own_props, method_name, method_name_len);

			if (method_prop != NULL && method_prop->type == ACTION_STACK_VALUE_FUNCTION)
			{
				ASFunction* mfunc = lookupFunctionFromVar(method_prop);

				if (mfunc != NULL && g_call_depth >= g_max_call_depth - 1)
				{
					if (args != NULL) FREE(args);
					g_execution_halted = 1;
					pushUndefined(app_context);
				}
				else if (mfunc != NULL && mfunc->function_type == 2)
				{
					ActionVar* registers = NULL;
					if (mfunc->register_count > 0)
						registers = (ActionVar*) HCALLOC(mfunc->register_count, sizeof(ActionVar));

					g_call_depth++;
					ActionVar result = mfunc->advanced_func(app_context, args, num_args, registers, (void*) func->own_props);
					g_call_depth--;

					if (registers != NULL) FREE(registers);
					if (args != NULL) FREE(args);
					pushVar(app_context, &result);
				}
				else if (mfunc != NULL && mfunc->function_type == 1 && mfunc->simple_func != NULL)
				{
					for (u32 i = 0; i < num_args; i++)
						pushVar(app_context, &args[i]);
					if (args != NULL) FREE(args);

					g_call_depth++;
					ActionVar result = ((ActionVar(*)(SWFAppContext*))mfunc->simple_func)(app_context);
					g_call_depth--;
					pushVar(app_context, &result);
				}
				else
				{
					if (args != NULL) FREE(args);
					pushUndefined(app_context);
				}
			}
			else
			{
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
		}
		return;
	}
	else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
	{
		MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;

		if (method_name_len == 11 && strncmp(method_name, "gotoAndStop", 11) == 0)
		{
			if (num_args >= 1)
			{
				s32 frame_num = -1;
				if (args[0].type == ACTION_STACK_VALUE_F64) {
					double d; memcpy(&d, &args[0].data.numeric_value, sizeof(double));
					frame_num = (s32)d;
				} else if (args[0].type == ACTION_STACK_VALUE_F32) {
					float f; memcpy(&f, &args[0].data.numeric_value, sizeof(float));
					frame_num = (s32)f;
				} else if (args[0].type == ACTION_STACK_VALUE_STRING) {
					char _gas_frame_buf[512];
					const uint16_t* _gas_frame_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_gas_frame_u16, args[0].str_size, _gas_frame_buf, sizeof(_gas_frame_buf));
					const char* frame_str = _gas_frame_buf;
					const char* frame_part = frame_str;
					const char* colon = strchr(frame_str, ':');
					if (colon != NULL) frame_part = colon + 1;
					char* endptr;
					long parsed = strtol(frame_part, &endptr, 10);
					if (endptr != frame_part && *endptr == '\0') frame_num = (s32)parsed;
				}
				if (frame_num > 0) {
					actionGotoFrame(app_context, (u16)(frame_num - 1));
				}
			}
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 11 && strncmp(method_name, "gotoAndPlay", 11) == 0)
		{
			if (num_args >= 1)
			{
				s32 frame_num = -1;
				if (args[0].type == ACTION_STACK_VALUE_F64) {
					double d; memcpy(&d, &args[0].data.numeric_value, sizeof(double));
					frame_num = (s32)d;
				} else if (args[0].type == ACTION_STACK_VALUE_F32) {
					float f; memcpy(&f, &args[0].data.numeric_value, sizeof(float));
					frame_num = (s32)f;
				} else if (args[0].type == ACTION_STACK_VALUE_STRING) {
					char _gap_frame_buf[512];
					const uint16_t* _gap_frame_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_gap_frame_u16, args[0].str_size, _gap_frame_buf, sizeof(_gap_frame_buf));
					const char* frame_str = _gap_frame_buf;
					const char* frame_part = frame_str;
					const char* colon = strchr(frame_str, ':');
					if (colon != NULL) frame_part = colon + 1;
					char* endptr;
					long parsed = strtol(frame_part, &endptr, 10);
					if (endptr != frame_part && *endptr == '\0') frame_num = (s32)parsed;
				}
				if (frame_num > 0) {
					actionGotoFrame(app_context, (u16)(frame_num - 1));
					is_playing = 1;
				}
			}
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 4 && strncmp(method_name, "play", 4) == 0)
		{
			actionPlay(app_context);
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 4 && strncmp(method_name, "stop", 4) == 0)
		{
			actionStop(app_context);
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 15 && strncmp(method_name, "removeTextField", 15) == 0)
		{
			// removeTextField(): remove a dynamically-created text field
#ifdef NO_GRAPHICS
			// Remove from child_mc_cache
			for (int i = 0; i < child_mc_count; i++) {
				if (child_mc_cache[i] == mc) {
					child_mc_cache[i] = NULL;
					break;
				}
			}
			// Set variable to undefined (so GetVariable returns undefined)
			ActionVar undef_var = {0};
			undef_var.type = ACTION_STACK_VALUE_UNDEFINED;
			setVariableByName(mc->name, &undef_var);
#endif
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 15 && strncmp(method_name, "createTextField", 15) == 0)
		{
			// createTextField(instanceName, depth, x, y, width, height)
			// Creates a new dynamic text field as a child of this movie clip
#ifdef NO_GRAPHICS
			if (num_args >= 6) {
				char _mctf_name_buf[512];
				const char* inst_name = "";
				if (args[0].type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _mctf_name_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_mctf_name_u16, args[0].str_size, _mctf_name_buf, sizeof(_mctf_name_buf));
					inst_name = _mctf_name_buf;
				}
				int depth_val = (int) varToDouble(&args[1]);
				double x = varToDouble(&args[2]);
				double y = varToDouble(&args[3]);
				double w = varToDouble(&args[4]);
				double h = varToDouble(&args[5]);
				(void)depth_val;

				// Create a child MovieClip for the text field
				MovieClip* child = createMovieClip(inst_name, mc);
				child->x = (float) x;
				child->y = (float) y;
				child->width = (float) w;
				child->height = (float) h;
				child->ng_textfield_idx = -1; // dynamically created, no static metadata

				// Set up dynamic_props with TextField defaults
				if (child->dynamic_props == NULL) {
					child->dynamic_props = (void*) allocObject(app_context, 32);
					retainObject((ASObject*) child->dynamic_props);
				}
				ASObject* props = (ASObject*) child->dynamic_props;

				// Set __proto__ to TextField.prototype
				initTextFieldPrototype(app_context);
				if (g_textfield_constructor.prototype_obj != NULL) {
					ActionVar proto_val = {0};
					proto_val.type = ACTION_STACK_VALUE_OBJECT;
					proto_val.data.numeric_value = (u64) g_textfield_constructor.prototype_obj;
					setProperty(app_context, props, "__proto__", 9, &proto_val);
					for (u32 pi = 0; pi < props->num_used; pi++) {
						if (strcmp(props->properties[pi].name, "__proto__") == 0) {
							props->properties[pi].flags &= ~PROPERTY_FLAG_ENUMERABLE;
							break;
						}
					}
				}

				// Set default properties for dynamic text fields
				ActionVar sval = {0};
				sval.type = ACTION_STACK_VALUE_STRING;
				sval.str_size = 0;
				VAL(u64, &sval.data.numeric_value) = (u64)u16_empty;
				setProperty(app_context, props, "text", 4, &sval);
				setProperty(app_context, props, "htmlText", 8, &sval);
				setProperty(app_context, props, "variable", 8, &sval);

				ActionVar fval = {0};
				fval.type = ACTION_STACK_VALUE_BOOLEAN;
				fval.data.numeric_value = 0;
				setProperty(app_context, props, "background", 10, &fval);
				setProperty(app_context, props, "border", 6, &fval);
				setProperty(app_context, props, "multiline", 9, &fval);
				setProperty(app_context, props, "wordWrap", 8, &fval);
				setProperty(app_context, props, "password", 8, &fval);
				setProperty(app_context, props, "html", 4, &fval);
				setProperty(app_context, props, "embedFonts", 10, &fval);
				setProperty(app_context, props, "condenseWhite", 13, &fval);

				ActionVar tval = {0};
				tval.type = ACTION_STACK_VALUE_BOOLEAN;
				tval.data.numeric_value = 1;
				setProperty(app_context, props, "selectable", 10, &tval);
				setProperty(app_context, props, "mouseWheelEnabled", 17, &tval);

				ActionVar type_val = {0};
				type_val.type = ACTION_STACK_VALUE_STRING;
				type_val.str_size = 7;
				VAL(u64, &type_val.data.numeric_value) = (u64)u16_dynamic;
				setProperty(app_context, props, "type", 4, &type_val);

				ActionVar dval = {0};
				dval.type = ACTION_STACK_VALUE_F64;
				VAL(double, &dval.data.numeric_value) = 0.0;
				setProperty(app_context, props, "length", 6, &dval);
				setProperty(app_context, props, "textColor", 9, &dval);
				setProperty(app_context, props, "hscroll", 7, &dval);
				setProperty(app_context, props, "maxhscroll", 10, &dval);
				setProperty(app_context, props, "textWidth", 9, &dval);
				setProperty(app_context, props, "textHeight", 10, &dval);
				setProperty(app_context, props, "sharpness", 9, &dval);
				setProperty(app_context, props, "thickness", 9, &dval);

				VAL(double, &dval.data.numeric_value) = 16777215.0;
				setProperty(app_context, props, "backgroundColor", 15, &dval);
				VAL(double, &dval.data.numeric_value) = 0.0;
				setProperty(app_context, props, "borderColor", 11, &dval);

				ActionVar one_val = {0};
				one_val.type = ACTION_STACK_VALUE_F64;
				VAL(double, &one_val.data.numeric_value) = 1.0;
				setProperty(app_context, props, "scroll", 6, &one_val);
				setProperty(app_context, props, "maxscroll", 9, &one_val);
				setProperty(app_context, props, "bottomScroll", 12, &one_val);

				ActionVar null_val = {0};
				null_val.type = ACTION_STACK_VALUE_NULL;
				setProperty(app_context, props, "maxChars", 8, &null_val);
				setProperty(app_context, props, "restrict", 8, &null_val);
				setProperty(app_context, props, "styleSheet", 10, &null_val);

				ActionVar undef_val = {0};
				undef_val.type = ACTION_STACK_VALUE_UNDEFINED;
				setProperty(app_context, props, "tabIndex", 8, &undef_val);

				ActionVar as_val = {0};
				as_val.type = ACTION_STACK_VALUE_STRING;
				as_val.str_size = 4;
				VAL(u64, &as_val.data.numeric_value) = (u64)u16_none;
				setProperty(app_context, props, "autoSize", 8, &as_val);

				ActionVar aat_val = {0};
				aat_val.type = ACTION_STACK_VALUE_STRING;
				aat_val.str_size = 6;
				VAL(u64, &aat_val.data.numeric_value) = (u64)u16_normal;
				setProperty(app_context, props, "antiAliasType", 13, &aat_val);

				ActionVar gft_val = {0};
				gft_val.type = ACTION_STACK_VALUE_STRING;
				gft_val.str_size = 5;
				VAL(u64, &gft_val.data.numeric_value) = (u64)u16_pixel;
				setProperty(app_context, props, "gridFitType", 11, &gft_val);

				ASArray* filters_arr = allocArray(app_context, 0);
				filters_arr->length = 0;
				ActionVar filters_val = {0};
				filters_val.type = ACTION_STACK_VALUE_ARRAY;
				filters_val.data.numeric_value = (u64) filters_arr;
				setProperty(app_context, props, "filters", 7, &filters_val);

				// Register child on parent MC's dynamic_props so mc.childName works via GetMember
				{
					if (mc->dynamic_props == NULL) {
						mc->dynamic_props = (void*) allocObject(app_context, 8);
						retainObject((ASObject*) mc->dynamic_props);
					}
					ActionVar mc_var = {0};
					mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
					mc_var.data.numeric_value = (u64)child;
					setProperty(app_context, (ASObject*) mc->dynamic_props, inst_name, strlen(inst_name), &mc_var);
					// Also set on global scope for GetVariable access
					size_t klen = strlen(inst_name);
					ActionVar* gvar = getVariable((char*)inst_name, klen);
					if (gvar != NULL) {
						gvar->type = mc_var.type;
						gvar->str_size = mc_var.str_size;
						gvar->data = mc_var.data;
					}
				}

				// Add to child_mc_cache so it persists across lookups
				if (child_mc_count < MAX_CHILD_MOVIECLIPS) {
					child_mc_cache[child_mc_count++] = child;
				}

				// Return the target path of the new text field
				if (args != NULL) FREE(args);
				ActionVar result = {0};
				result.type = ACTION_STACK_VALUE_STRING;
				{
					u32 _tgt_u16_len;
					uint16_t* _tgt_u16 = ascii_to_u16(app_context, child->target, (int)strlen(child->target), &_tgt_u16_len);
					result.str_size = _tgt_u16_len;
					VAL(u64, &result.data.numeric_value) = (u64)_tgt_u16;
					pushVar(app_context, &result);
				}
			} else {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 20 && strncmp(method_name, "createEmptyMovieClip", 20) == 0)
		{
			// createEmptyMovieClip(instanceName, depth)
			// Creates a new empty child MovieClip
#ifdef NO_GRAPHICS
			if (num_args >= 2) {
				char _mcemc_name_buf[512];
				const char* inst_name = "";
				if (args[0].type == ACTION_STACK_VALUE_STRING) {
					const uint16_t* _mcemc_name_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_mcemc_name_u16, args[0].str_size, _mcemc_name_buf, sizeof(_mcemc_name_buf));
					inst_name = _mcemc_name_buf;
				}
				int depth_val = ecmaToInt32(varToDouble(&args[1]));

				// Remove existing clip at same depth (depth conflict resolution)
				for (int _dci = 0; _dci < child_mc_count; _dci++) {
					if (child_mc_cache[_dci] != NULL && child_mc_cache[_dci]->parent == mc &&
					    child_mc_cache[_dci]->depth == depth_val) {
						if (mc->dynamic_props != NULL) {
							ActionVar _undef = {0};
							_undef.type = ACTION_STACK_VALUE_UNDEFINED;
							setProperty(app_context, (ASObject*)mc->dynamic_props,
								child_mc_cache[_dci]->name, strlen(child_mc_cache[_dci]->name), &_undef);
						}
						child_mc_cache[_dci]->depth = INT_MIN;
						child_mc_cache[_dci] = NULL;
						break;
					}
				}

				// Create a child MovieClip
				MovieClip* child = createMovieClip(inst_name, mc);
				child->currentframe = 0;  // Empty clips have _currentframe = 0
				child->totalframes = 1;
				child->framesloaded = 1;
				child->depth = depth_val;

				// Copy URL from parent
				strncpy(child->url, mc->url[0] ? mc->url : root_movieclip.url, sizeof(child->url) - 1);
				child->url[sizeof(child->url) - 1] = ' ';

				// Register child on parent MC's dynamic_props so mc.childName works via GetMember
				if (mc->dynamic_props == NULL) {
					mc->dynamic_props = (void*) allocObject(app_context, 8);
					retainObject((ASObject*) mc->dynamic_props);
				}
				ActionVar mc_var = {0};
				mc_var.type = ACTION_STACK_VALUE_MOVIECLIP;
				mc_var.data.numeric_value = (u64)child;
				setProperty(app_context, (ASObject*) mc->dynamic_props, inst_name, strlen(inst_name), &mc_var);
				// Also set on global scope for GetVariable access
				setVariableByName(inst_name, &mc_var);

				// Find free slot or append in child_mc_cache
				{
					int _sl = -1;
					for (int _di = 0; _di < child_mc_count; _di++) {
						if (child_mc_cache[_di] == NULL) { _sl = _di; break; }
					}
					if (_sl >= 0) child_mc_cache[_sl] = child;
					else if (child_mc_count < MAX_CHILD_MOVIECLIPS) child_mc_cache[child_mc_count++] = child;
				}

				// Return the created MovieClip
				if (args != NULL) FREE(args);
				PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)child);
			} else {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 18 && strncmp(method_name, "duplicateMovieClip", 18) == 0)
		{
			// duplicateMovieClip(target, depth [, initObject])
			// Clones this MC to a new name/depth, optionally applying initObject properties.
			// Returns the new MovieClip.
#ifdef NO_GRAPHICS
			if (num_args >= 2) {
				// Convert args[0] (target name) to string — may require toString() call on objects
				char _dmc_tgt_buf[512];
				const char* tgt_name = "";
				if (args[0].type == ACTION_STACK_VALUE_STRING && args[0].str_size > 0) {
					const uint16_t* _dmc_u16 = varGetU16Ptr(&args[0]);
					u16_to_utf8(_dmc_u16, args[0].str_size, _dmc_tgt_buf, sizeof(_dmc_tgt_buf));
					tgt_name = _dmc_tgt_buf;
				} else if ((args[0].type == ACTION_STACK_VALUE_OBJECT ||
				            args[0].type == ACTION_STACK_VALUE_FUNCTION) && args[0].data.numeric_value != 0) {
					ActionVar _dmc_ts = objectCallToString(app_context, &args[0], NULL);
					if (_dmc_ts.type == ACTION_STACK_VALUE_STRING && _dmc_ts.str_size > 0) {
						const uint16_t* _dmc_ts_u16 = varGetU16Ptr(&_dmc_ts);
						u16_to_utf8(_dmc_ts_u16, _dmc_ts.str_size, _dmc_tgt_buf, sizeof(_dmc_tgt_buf));
						tgt_name = _dmc_tgt_buf;
					}
				}

				// Convert args[1] (depth) to number — may require valueOf() call on objects
				double _dmc_depth_dbl;
				if ((args[1].type == ACTION_STACK_VALUE_OBJECT ||
				     args[1].type == ACTION_STACK_VALUE_FUNCTION) && args[1].data.numeric_value != 0) {
					int _dmc_vo_found = 0;
					ActionVar _dmc_vo = objectCallValueOf(app_context, &args[1], &_dmc_vo_found);
					_dmc_depth_dbl = _dmc_vo_found ? varToDouble(&_dmc_vo) : 0.0;
				} else {
					_dmc_depth_dbl = varToDouble(&args[1]);
				}
				int depth_val = ecmaToInt32(_dmc_depth_dbl);

				// Use ng_duplicateMovieClip: stores at SWF depth (depth+16384), no variable registration
				MovieClip* clone_mc = ng_duplicateMovieClip(app_context, mc->name, tgt_name, depth_val);
				if (clone_mc == NULL) {
					// Source not in ng_display (script-created MC): direct clone via MC
					clone_mc = ng_cloneSpriteFromMC(app_context, mc, tgt_name, depth_val);
				}

				// Apply initObject properties (args[2]) to the clone
				if (clone_mc != NULL && num_args >= 3 &&
				    args[2].type == ACTION_STACK_VALUE_OBJECT && args[2].data.numeric_value != 0) {
					ASObject* init_obj = (ASObject*)(uintptr_t)args[2].data.numeric_value;
					if (clone_mc->dynamic_props == NULL) {
						clone_mc->dynamic_props = (void*)allocObject(app_context, 8);
						retainObject((ASObject*)clone_mc->dynamic_props);
					}
					for (u32 _ip = 0; _ip < init_obj->num_used; _ip++) {
						ASProperty* _prop = &init_obj->properties[_ip];
						if (_prop->name && (_prop->flags & PROPERTY_FLAG_ENUMERABLE)) {
							setProperty(app_context, (ASObject*)clone_mc->dynamic_props,
							    _prop->name, _prop->name_length, &_prop->value);
						}
					}
				}

				if (args != NULL) FREE(args);
				if (clone_mc != NULL) {
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)clone_mc);
				} else {
					pushUndefined(app_context);
				}
			} else {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
			}
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "setTextFormat", 13) == 0)
		{
			// setTextFormat(fmt) / setTextFormat(begin, fmt) / setTextFormat(begin, end, fmt)
			// In Flash, setTextFormat does NOT change the textColor property
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 16 && strncmp(method_name, "setNewTextFormat", 16) == 0)
		{
#ifdef NO_GRAPHICS
			// setNewTextFormat(fmt): set the default format for newly-typed text
			// For now, apply color to textColor if the field has no text
			if (num_args >= 1 && args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
				ASObject* fmt_obj = (ASObject*) args[0].data.numeric_value;
				ActionVar* color_prop = getProperty(fmt_obj, "color", 5);
				if (color_prop != NULL && color_prop->type == ACTION_STACK_VALUE_F64 && mc->dynamic_props != NULL) {
					double c; memcpy(&c, &color_prop->data.numeric_value, sizeof(double));
					u32 color_u32 = (u32)ecmaToInt32(c) & 0x00FFFFFF;
					ActionVar cv = {0};
					cv.type = ACTION_STACK_VALUE_F64;
					VAL(double, &cv.data.numeric_value) = (double)color_u32;
					setProperty(app_context, (ASObject*)mc->dynamic_props, "textColor", 9, &cv);
				}
			}
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "getTextFormat", 13) == 0)
		{
#ifdef NO_GRAPHICS
			int tf_idx = mc->ng_textfield_idx;
			// getTextFormat(beginIndex, endIndex): if range is zero-length, return all-null
			int force_null = 0;
			if (num_args >= 2) {
				double begin_idx = varToDouble(&args[0]);
				double end_idx = varToDouble(&args[1]);
				if (begin_idx == end_idx) force_null = 1;
			}
			// Check if field has text
			const char* text = "";
			if (!force_null && mc->dynamic_props != NULL) {
				ActionVar* text_prop = getProperty((ASObject*) mc->dynamic_props, "text", 4);
				if (text_prop != NULL && text_prop->type == ACTION_STACK_VALUE_STRING) {
					// Check if text is non-empty via str_size (UTF-16 internal storage)
					if (text_prop->str_size > 0) text = "x"; // non-empty sentinel
				}
			}
			int has_text = force_null ? 0 : (text[0] != '\0');
			// Compute HTML-aware alignment override (SWF7/SWF8 behavior differ)
			int html_align_override = -1; // default: use tag-defined align
			if (tf_idx >= 0) {
				u16 tag_flags = ng_getTextFieldFlags(tf_idx);
				int tag_html = (tag_flags & 0x0040) != 0;
				int cur_html = tag_html; // default to tag init value
				if (mc->dynamic_props != NULL) {
					ActionVar* html_prop = getProperty((ASObject*) mc->dynamic_props, "html", 4);
					if (html_prop != NULL && html_prop->type == ACTION_STACK_VALUE_BOOLEAN)
						cur_html = html_prop->data.numeric_value ? 1 : 0;
				}
				if (g_swf_version <= 7) {
					// SWF7: HTML mode active (from tag or script) → left alignment
					if (cur_html || tag_html) html_align_override = 0; // left
				} else {
					// SWF8: only left when tag was HTML but script explicitly turned it off
					if (tag_html && !cur_html) html_align_override = 0; // left
				}
			}
			ASObject* tf = createTextFormatFromField(app_context, tf_idx, has_text, 0, html_align_override);
			// Override color with current textColor from dynamic_props
			if (has_text && mc->dynamic_props != NULL) {
				ActionVar* tc_prop = getProperty((ASObject*) mc->dynamic_props, "textColor", 9);
				if (tc_prop != NULL && tc_prop->type == ACTION_STACK_VALUE_F64) {
					setProperty(app_context, tf, "color", 5, tc_prop);
				}
			}
			if (args != NULL) FREE(args);
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_OBJECT;
			result.data.numeric_value = (u64) tf;
			pushVar(app_context, &result);
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 16 && strncmp(method_name, "getNewTextFormat", 16) == 0)
		{
#ifdef NO_GRAPHICS
			int tf_idx = mc->ng_textfield_idx;
			// Compute HTML-aware alignment override (SWF7/SWF8 behavior differ)
			int html_align_override_ntf = -1; // default: use tag-defined align
			if (tf_idx >= 0) {
				u16 tag_flags_ntf = ng_getTextFieldFlags(tf_idx);
				int tag_html_ntf = (tag_flags_ntf & 0x0040) != 0;
				int cur_html_ntf = tag_html_ntf;
				if (mc->dynamic_props != NULL) {
					ActionVar* html_prop_ntf = getProperty((ASObject*) mc->dynamic_props, "html", 4);
					if (html_prop_ntf != NULL && html_prop_ntf->type == ACTION_STACK_VALUE_BOOLEAN)
						cur_html_ntf = html_prop_ntf->data.numeric_value ? 1 : 0;
				}
				if (g_swf_version <= 7) {
					if (cur_html_ntf || tag_html_ntf) html_align_override_ntf = 0; // left
				} else {
					if (tag_html_ntf && !cur_html_ntf) html_align_override_ntf = 0; // left
				}
			}
			ASObject* tf = createTextFormatFromField(app_context, tf_idx, 1, 1, html_align_override_ntf);
			// Override color with current textColor from dynamic_props
			if (mc->dynamic_props != NULL) {
				ActionVar* tc_prop = getProperty((ASObject*) mc->dynamic_props, "textColor", 9);
				if (tc_prop != NULL && tc_prop->type == ACTION_STACK_VALUE_F64) {
					setProperty(app_context, tf, "color", 5, tc_prop);
				}
			}
			if (args != NULL) FREE(args);
			ActionVar result = {0};
			result.type = ACTION_STACK_VALUE_OBJECT;
			result.data.numeric_value = (u64) tf;
			pushVar(app_context, &result);
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "getSWFVersion", 13) == 0)
		{
			if (args != NULL) FREE(args);
			double v = (double)g_swf_version;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
			return;
		}
		else if (method_name_len == 14 && strncmp(method_name, "getBytesLoaded", 14) == 0)
		{
			// Empty/created MovieClips return 0 (SWF data not loaded)
			if (args != NULL) FREE(args);
			double v = 0.0;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "getBytesTotal", 13) == 0)
		{
			// Empty/created MovieClips return 0
			if (args != NULL) FREE(args);
			double v = 0.0;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
			return;
		}
		else if (method_name_len == 8 && strncmp(method_name, "getDepth", 8) == 0)
		{
			// Return the ActionScript depth of this clip
			if (args != NULL) FREE(args);
			double v = (double)mc->depth;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
			return;
		}
		else if (method_name_len == 19 && strncmp(method_name, "getNextHighestDepth", 19) == 0)
		{
			// Return the next available depth for this clip's children
			// = max(children's depths) + 1, or 0 if all children are at negative depths
			if (args != NULL) FREE(args);
			int _max_d = -1;
			for (int _i = 0; _i < child_mc_count; _i++) {
				MovieClip* _ch = child_mc_cache[_i];
				if (_ch != NULL && _ch->parent == mc && _ch->depth > _max_d)
					_max_d = _ch->depth;
			}
			double v = (_max_d < 0) ? 0.0 : (double)(_max_d + 1);
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
			return;
		}
		else if (method_name_len == 10 && strncmp(method_name, "swapDepths", 10) == 0)
		{
			// swapDepths(numericDepth) — move clip to new depth
			// swapDepths(clipRef) — exchange depths with another clip
			// swapDepths(pathString) — resolve path then exchange
			if (num_args == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED) {
				// no-op for undefined
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
			if (args[0].type == ACTION_STACK_VALUE_MOVIECLIP) {
				// Swap depths with target clip (same-parent only; cross-parent is no-op in Flash)
				MovieClip* _target = (MovieClip*) args[0].data.numeric_value;
				if (_target != NULL && _target != mc) {
					MovieClip* _mc_parent = mc->parent ? mc->parent : &root_movieclip;
					MovieClip* _tg_parent = _target->parent ? _target->parent : &root_movieclip;
					if (_mc_parent == _tg_parent) {
						int _tmp = mc->depth;
						mc->depth = _target->depth;
						_target->depth = _tmp;
#ifdef NO_GRAPHICS
						if (mc->name[0] && _target->name[0])
							ng_swapDisplayDepths(mc->name, _target->name);
#endif
					}
					// Cross-parent swap is a no-op (Flash ignores it)
				}
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
			if (args[0].type == ACTION_STACK_VALUE_STRING) {
				// Resolve path string to MovieClip, then swap depths (same-parent only)
				char _sd_path[512];
				const uint16_t* _sd_u16 = varGetU16Ptr(&args[0]);
				u16_to_utf8(_sd_u16, args[0].str_size, _sd_path, sizeof(_sd_path));
				if (args != NULL) FREE(args);
				// Simple path resolver: "../name" = sibling from parent
				MovieClip* _target_mc = NULL;
				if (_sd_path[0] == '.' && _sd_path[1] == '.' && _sd_path[2] == '/') {
					// "../sibling" — find sibling relative to parent
					const char* _sibling = _sd_path + 3;
					MovieClip* _parent_mc = mc->parent ? mc->parent : &root_movieclip;
					for (int _i = 0; _i < child_mc_count && !_target_mc; _i++) {
						MovieClip* _ch = child_mc_cache[_i];
						if (_ch != NULL && _ch->parent == _parent_mc &&
						    strcmp(_ch->name, _sibling) == 0)
							_target_mc = _ch;
					}
				} else if (_sd_path[0] != '\0') {
					// Plain name — find child of current mc
					for (int _i = 0; _i < child_mc_count && !_target_mc; _i++) {
						MovieClip* _ch = child_mc_cache[_i];
						if (_ch != NULL && _ch->parent == mc &&
						    strcmp(_ch->name, _sd_path) == 0)
							_target_mc = _ch;
					}
				}
				if (_target_mc != NULL && _target_mc != mc) {
					MovieClip* _mc_parent = mc->parent ? mc->parent : &root_movieclip;
					MovieClip* _tg_parent = _target_mc->parent ? _target_mc->parent : &root_movieclip;
					if (_mc_parent == _tg_parent) {
						int _tmp = mc->depth;
						mc->depth = _target_mc->depth;
						_target_mc->depth = _tmp;
#ifdef NO_GRAPHICS
						if (mc->name[0] && _target_mc->name[0])
							ng_swapDisplayDepths(mc->name, _target_mc->name);
#endif
					}
				}
				pushUndefined(app_context);
				return;
			}
			// Numeric depth
			double _dval = varToDouble(&args[0]);
			if (args != NULL) FREE(args);
			int32_t _new_depth;
			if (isnan(_dval)) {
				_new_depth = 0;
			} else {
				_new_depth = ecmaToInt32(_dval);
			}
			// Clamp to valid range [-16384, 2130690044]
			if (_new_depth < -16384) _new_depth = -16384;
			if (_new_depth > 2130690044) _new_depth = 2130690044;
			mc->depth = _new_depth;
#ifdef NO_GRAPHICS
			if (mc->name[0])
				ng_updateDisplayDepth(mc->name, _new_depth);
#endif
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 18 && strncmp(method_name, "getInstanceAtDepth", 18) == 0)
		{
			// Return the MovieClip at the given depth, or the parent MC for non-MC objects,
			// or undefined if no object at that depth.
#ifdef NO_GRAPHICS
			if (num_args == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED ||
			    args[0].type == ACTION_STACK_VALUE_NULL) {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
			int _target_depth = ecmaToInt32(varToDouble(&args[0]));
			if (args != NULL) FREE(args);
			// 1. Scan child_mc_cache for matching parent + depth
			for (int _i = 0; _i < child_mc_count; _i++) {
				MovieClip* _ch = child_mc_cache[_i];
				if (_ch != NULL && _ch->parent == mc && _ch->depth == _target_depth) {
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)_ch);
					return;
				}
			}
			// 2. Check display list via ng_findRootChildAtSWFDepth
			// (only handles root children for now; swf_depth = AS_depth + 16384)
			if (_target_depth >= -16384) {
				size_t _swf_depth = (size_t)(_target_depth + 16384);
				char _inst_name[64] = {0};
				int _found_type = ng_findRootChildAtSWFDepth(_swf_depth, _inst_name, sizeof(_inst_name));
				if ((_found_type == 2 || _found_type == 3) && _inst_name[0]) {
					// Sprite or textfield with auto-name — find or create its MovieClip
					MovieClip* _sprite_mc = findOrCreateMovieClip(app_context, _inst_name, mc);
					if (_sprite_mc) {
						_sprite_mc->depth = _target_depth;
						PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)_sprite_mc);
						return;
					}
				} else if (_found_type == 1) {
					// Non-sprite, non-textfield (shape, text) — return the parent MC
					PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)mc);
					return;
				}
			}
			pushUndefined(app_context);
#else
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
#endif
			return;
		}
		else if ((method_name_len == 9 && strncmp(method_name, "getBounds", 9) == 0) ||
		         (method_name_len == 7 && strncmp(method_name, "getRect", 7) == 0))
		{
			// getBounds(targetCoordSpace) / getRect(targetCoordSpace)
			// For empty clips, return sentinel "no bounds" values
			// getBounds(this) uses 6710886.4 (2^27/20), getBounds(otherMC) uses 6710886.35 ((2^27-1)/20)
			int target_is_self = 0;
			if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_MOVIECLIP) {
				MovieClip* target = (MovieClip*) args[0].data.numeric_value;
				target_is_self = (target == mc);
			}
			if (args != NULL) FREE(args);

			double sentinel = target_is_self ? (134217727.0 / 20.0) : (134217728.0 / 20.0);

			ASObject* bounds = allocObject(app_context, 8);
			ActionVar v = {0};
			v.type = ACTION_STACK_VALUE_F64;
			VAL(double, &v.data.numeric_value) = sentinel;
			setProperty(app_context, bounds, "xMin", 4, &v);
			setProperty(app_context, bounds, "xMax", 4, &v);
			setProperty(app_context, bounds, "yMin", 4, &v);
			setProperty(app_context, bounds, "yMax", 4, &v);
			PUSH(ACTION_STACK_VALUE_OBJECT, (u64)bounds);
			return;
		}
		else if (method_name_len == 6 && strncmp(method_name, "moveTo", 6) == 0)
		{
			// moveTo(x, y) — update drawing bounds for hit-testing
#ifdef NO_GRAPHICS
			if (num_args >= 2 && mc != NULL) {
				float x = (float)varToDouble(&args[0]);
				float y = (float)varToDouble(&args[1]);
				if (!mc->draw_has_bounds) {
					mc->draw_xmin = mc->draw_xmax = x;
					mc->draw_ymin = mc->draw_ymax = y;
					mc->draw_has_bounds = 1;
				} else {
					if (x < mc->draw_xmin) mc->draw_xmin = x;
					if (x > mc->draw_xmax) mc->draw_xmax = x;
					if (y < mc->draw_ymin) mc->draw_ymin = y;
					if (y > mc->draw_ymax) mc->draw_ymax = y;
				}
			}
#endif
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 6 && strncmp(method_name, "lineTo", 6) == 0)
		{
			// lineTo(x, y) — update drawing bounds for hit-testing
#ifdef NO_GRAPHICS
			if (num_args >= 2 && mc != NULL) {
				float x = (float)varToDouble(&args[0]);
				float y = (float)varToDouble(&args[1]);
				if (!mc->draw_has_bounds) {
					mc->draw_xmin = mc->draw_xmax = x;
					mc->draw_ymin = mc->draw_ymax = y;
					mc->draw_has_bounds = 1;
				} else {
					if (x < mc->draw_xmin) mc->draw_xmin = x;
					if (x > mc->draw_xmax) mc->draw_xmax = x;
					if (y < mc->draw_ymin) mc->draw_ymin = y;
					if (y > mc->draw_ymax) mc->draw_ymax = y;
				}
			}
#endif
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 9 && strncmp(method_name, "beginFill", 9) == 0)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 7 && strncmp(method_name, "endFill", 7) == 0)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "localToGlobal", 13) == 0)
		{
			// localToGlobal(pt): transform pt.x/pt.y from this MC's local coords to stage coords
			if (num_args < 1 || args[0].type != ACTION_STACK_VALUE_OBJECT) {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
			ASObject* _ltg_pt = (ASObject*) args[0].data.numeric_value;
			if (args != NULL) FREE(args);
			if (_ltg_pt == NULL) { pushUndefined(app_context); return; }
#ifdef NO_GRAPHICS
			{
				ActionVar* _ltg_xv = getProperty(_ltg_pt, "x", 1);
				ActionVar* _ltg_yv = getProperty(_ltg_pt, "y", 1);
				int _ltg_has_x = (_ltg_xv != NULL && (_ltg_xv->type == ACTION_STACK_VALUE_F64 ||
				                   _ltg_xv->type == ACTION_STACK_VALUE_F32));
				int _ltg_has_y = (_ltg_yv != NULL && (_ltg_yv->type == ACTION_STACK_VALUE_F64 ||
				                   _ltg_yv->type == ACTION_STACK_VALUE_F32));
				if (_ltg_has_x && _ltg_has_y) {
					double _ltg_px = varToDouble(_ltg_xv);
					double _ltg_py = varToDouble(_ltg_yv);
					// Match Ruffle: f32 for a/b/c/d, i32 twips for tx/ty
					float _ltg_a = 1, _ltg_b = 0, _ltg_c = 0, _ltg_d = 1;
					int32_t _ltg_tx = 0, _ltg_ty = 0;
					MovieClip* _ltg_chain[64];
					int _ltg_n = 0;
					for (MovieClip* _ltg_cur = mc; _ltg_cur != NULL && _ltg_n < 64; _ltg_cur = _ltg_cur->parent)
						_ltg_chain[_ltg_n++] = _ltg_cur;
					for (int _ltg_i = _ltg_n - 1; _ltg_i >= 0; _ltg_i--) {
						double _la, _lb, _lc, _ld, _ltx, _lty;
						getLocalMatrixForMC(_ltg_chain[_ltg_i], &_la, &_lb, &_lc, &_ld, &_ltx, &_lty);
						float _rla = (float)_la, _rlb = (float)_lb, _rlc = (float)_lc, _rld = (float)_ld;
						float _rltx = (float)(_ltx * 20.0), _rlty = (float)(_lty * 20.0);
						// Compose: self * rhs (Ruffle uses fma for a/b/c/d, round_to_i32 for tx/ty)
						float _na = fmaf(_ltg_a, _rla, _ltg_c * _rlb);
						float _nb = fmaf(_ltg_b, _rla, _ltg_d * _rlb);
						float _nc = fmaf(_ltg_a, _rlc, _ltg_c * _rld);
						float _nd = fmaf(_ltg_b, _rlc, _ltg_d * _rld);
						int32_t _ntx = (int32_t)rintf(fmaf(_ltg_a, _rltx, _ltg_c * _rlty)) + _ltg_tx;
						int32_t _nty = (int32_t)rintf(fmaf(_ltg_b, _rltx, _ltg_d * _rlty)) + _ltg_ty;
						_ltg_a = _na; _ltg_b = _nb; _ltg_c = _nc; _ltg_d = _nd;
						_ltg_tx = _ntx; _ltg_ty = _nty;
					}
					// Apply to point: convert pixels to twips (truncate), transform, convert back
					float _ptx = (float)((int32_t)(_ltg_px * 20.0));
					float _pty = (float)((int32_t)(_ltg_py * 20.0));
					int32_t _gx_tw = (int32_t)rintf(fmaf(_ltg_a, _ptx, _ltg_c * _pty)) + _ltg_tx;
					int32_t _gy_tw = (int32_t)rintf(fmaf(_ltg_b, _ptx, _ltg_d * _pty)) + _ltg_ty;
					double _gx = (double)_gx_tw / 20.0;
					double _gy = (double)_gy_tw / 20.0;
					ActionVar _ltg_rv = {0};
					_ltg_rv.type = ACTION_STACK_VALUE_F64;
					VAL(double, &_ltg_rv.data.numeric_value) = _gx;
					setProperty(app_context, _ltg_pt, "x", 1, &_ltg_rv);
					VAL(double, &_ltg_rv.data.numeric_value) = _gy;
					setProperty(app_context, _ltg_pt, "y", 1, &_ltg_rv);
				}
			}
#endif
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 13 && strncmp(method_name, "globalToLocal", 13) == 0)
		{
			// globalToLocal(pt): transform pt.x/pt.y from stage coords to this MC's local coords
			if (num_args < 1 || args[0].type != ACTION_STACK_VALUE_OBJECT) {
				if (args != NULL) FREE(args);
				pushUndefined(app_context);
				return;
			}
			ASObject* _gtl_pt = (ASObject*) args[0].data.numeric_value;
			if (args != NULL) FREE(args);
			if (_gtl_pt == NULL) { pushUndefined(app_context); return; }
#ifdef NO_GRAPHICS
			{
				ActionVar* _gtl_xv = getProperty(_gtl_pt, "x", 1);
				ActionVar* _gtl_yv = getProperty(_gtl_pt, "y", 1);
				int _gtl_has_x = (_gtl_xv != NULL && (_gtl_xv->type == ACTION_STACK_VALUE_F64 ||
				                   _gtl_xv->type == ACTION_STACK_VALUE_F32));
				int _gtl_has_y = (_gtl_yv != NULL && (_gtl_yv->type == ACTION_STACK_VALUE_F64 ||
				                   _gtl_yv->type == ACTION_STACK_VALUE_F32));
				if (_gtl_has_x && _gtl_has_y) {
					double _gtl_px = varToDouble(_gtl_xv);
					double _gtl_py = varToDouble(_gtl_yv);
					// Match Ruffle: f32 for a/b/c/d, i32 twips for tx/ty
					float _gtl_a = 1, _gtl_b = 0, _gtl_c = 0, _gtl_d = 1;
					int32_t _gtl_tx = 0, _gtl_ty = 0;
					MovieClip* _gtl_chain[64];
					int _gtl_n = 0;
					for (MovieClip* _gtl_cur = mc; _gtl_cur != NULL && _gtl_n < 64; _gtl_cur = _gtl_cur->parent)
						_gtl_chain[_gtl_n++] = _gtl_cur;
					for (int _gtl_i = _gtl_n - 1; _gtl_i >= 0; _gtl_i--) {
						double _la, _lb, _lc, _ld, _ltx, _lty;
						getLocalMatrixForMC(_gtl_chain[_gtl_i], &_la, &_lb, &_lc, &_ld, &_ltx, &_lty);
						float _rla = (float)_la, _rlb = (float)_lb, _rlc = (float)_lc, _rld = (float)_ld;
						float _rltx = (float)(_ltx * 20.0), _rlty = (float)(_lty * 20.0);
						float _na = fmaf(_gtl_a, _rla, _gtl_c * _rlb);
						float _nb = fmaf(_gtl_b, _rla, _gtl_d * _rlb);
						float _nc = fmaf(_gtl_a, _rlc, _gtl_c * _rld);
						float _nd = fmaf(_gtl_b, _rlc, _gtl_d * _rld);
						int32_t _ntx = (int32_t)rintf(fmaf(_gtl_a, _rltx, _gtl_c * _rlty)) + _gtl_tx;
						int32_t _nty = (int32_t)rintf(fmaf(_gtl_b, _rltx, _gtl_d * _rlty)) + _gtl_ty;
						_gtl_a = _na; _gtl_b = _nb; _gtl_c = _nc; _gtl_d = _nd;
						_gtl_tx = _ntx; _gtl_ty = _nty;
					}
					// Invert the composed matrix (Ruffle: f32 for a/b/c/d, round_to_i32 for tx/ty)
					float _det = _gtl_a * _gtl_d - _gtl_b * _gtl_c;
					if (_det > 1.1920929e-7f) { // f32 EPSILON
						float _ia =  _gtl_d / _det;
						float _ib =  _gtl_b / -_det;
						float _ic =  _gtl_c / -_det;
						float _id =  _gtl_a / _det;
						float _ftx = (float)_gtl_tx, _fty = (float)_gtl_ty;
						int32_t _itx = (int32_t)rintf((_gtl_d * _ftx - _gtl_c * _fty) / -_det);
						int32_t _ity = (int32_t)rintf((_gtl_b * _ftx - _gtl_a * _fty) / _det);
						// Apply inverse to point (convert pixels to twips, transform, convert back)
						float _ptx = (float)((int32_t)(_gtl_px * 20.0));
						float _pty = (float)((int32_t)(_gtl_py * 20.0));
						int32_t _lx_tw = (int32_t)rintf(fmaf(_ia, _ptx, _ic * _pty)) + _itx;
						int32_t _ly_tw = (int32_t)rintf(fmaf(_ib, _ptx, _id * _pty)) + _ity;
						double _lx = (double)_lx_tw / 20.0;
						double _ly = (double)_ly_tw / 20.0;
						ActionVar _gtl_rv = {0};
						_gtl_rv.type = ACTION_STACK_VALUE_F64;
						VAL(double, &_gtl_rv.data.numeric_value) = _lx;
						setProperty(app_context, _gtl_pt, "x", 1, &_gtl_rv);
						VAL(double, &_gtl_rv.data.numeric_value) = _ly;
						setProperty(app_context, _gtl_pt, "y", 1, &_gtl_rv);
					}
				}
			}
#endif
			pushUndefined(app_context);
			return;
		}
		else if (method_name_len == 15 && strncmp(method_name, "removeMovieClip", 15) == 0)
		{
			if (args != NULL) FREE(args);
#ifdef NO_GRAPHICS
			// Only dynamically-created clips at removable AS depths [0, 2130690032) can be removed.
			// Timeline-placed clips (negative depth) and reserved-range clips are immune.
			#define AVM_MAX_REMOVE_DEPTH 2130690032
			if (mc != NULL && mc->depth >= 0 && mc->depth < AVM_MAX_REMOVE_DEPTH) {
				// Queue onUnload handler for deferred firing at ShowFrame (matches Flash behavior)
				if (mc->dynamic_props != NULL) {
					ActionVar* _rmc_handler = getProperty((ASObject*)mc->dynamic_props, "onUnload", 8);
					if (_rmc_handler != NULL && _rmc_handler->type == ACTION_STACK_VALUE_FUNCTION) {
						ASFunction* _rmc_func = (ASFunction*) _rmc_handler->data.numeric_value;
						if (_rmc_func != NULL)
							queueOnUnload(_rmc_func, mc);
					}
				}
				// Clear the variable from parent's dynamic_props
				MovieClip* _rmc_parent = mc->parent ? mc->parent : &root_movieclip;
				if (_rmc_parent->dynamic_props != NULL && mc->name[0]) {
					ActionVar _rmc_undef = {0};
					_rmc_undef.type = ACTION_STACK_VALUE_UNDEFINED;
					setProperty(app_context, (ASObject*)_rmc_parent->dynamic_props,
					            mc->name, strlen(mc->name), &_rmc_undef);
				}
				// Also clear from root-level variable table (set by createEmptyMovieClip)
				if (mc->name[0]) {
					ActionVar _rmc_undef = {0};
					_rmc_undef.type = ACTION_STACK_VALUE_UNDEFINED;
					setVariableByName(mc->name, &_rmc_undef);
				}
				// Mark as removed — keep dynamic_props intact until pending unload fires
				mc->depth = INT_MIN;
				// Remove from child_mc_cache
				for (int _rmc_i = 0; _rmc_i < child_mc_count; _rmc_i++) {
					if (child_mc_cache[_rmc_i] == mc) {
						child_mc_cache[_rmc_i] = NULL;
						break;
					}
				}
			}
#endif
			pushUndefined(app_context);
			return;
		}
		else
		{
			// Check if user-defined method exists on dynamic_props
			if (mc != NULL && mc->dynamic_props != NULL) {
				ActionVar* method_var = getPropertyWithPrototype((ASObject*)mc->dynamic_props, method_name, method_name_len);
				if (method_var != NULL && method_var->type == ACTION_STACK_VALUE_FUNCTION) {
					// Call user-defined function with this = mc
					ASFunction* func = (ASFunction*) method_var->data.numeric_value;
					if (func != NULL && func->advanced_func != NULL) {
						ActionVar this_var = {0};
						this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
						this_var.data.numeric_value = (u64) mc;
						ActionVar result = func->advanced_func(app_context, args, num_args, NULL, (void*)&this_var);
						if (args != NULL) FREE(args);
						pushVar(app_context, &result);
						return;
					}
				}
			}
			// Unknown method on MovieClip — push undefined.
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
	}
	else if (obj_var.type == ACTION_STACK_VALUE_F64 ||
	         obj_var.type == ACTION_STACK_VALUE_F32 ||
	         obj_var.type == ACTION_STACK_VALUE_BOOLEAN)
	{
		// Number/Boolean primitive - handle toString() and valueOf()
		if (method_name_len == 8 && strncmp(method_name, "toString", 8) == 0)
		{
			if (obj_var.type == ACTION_STACK_VALUE_BOOLEAN)
			{
				if (args != NULL) FREE(args);
				const char* bs = obj_var.data.numeric_value ? "true" : "false";
				PUSH_STR(bs, strlen(bs));
			}
			else
			{
				// Number.prototype.toString([radix])
				int _nts_radix = 10;
				if (num_args >= 1 && args != NULL)
				{
					double rv = varToDouble(&args[0]);
					if (!isnan(rv) && rv >= 2.0 && rv <= 36.0)
						_nts_radix = (int)rv;
				}
				if (args != NULL) FREE(args);

				double dval = (obj_var.type == ACTION_STACK_VALUE_F64)
					? VAL(double, &obj_var.data.numeric_value)
					: (double)VAL(float, &obj_var.data.numeric_value);

				char _nts_buf[256];
				if (isnan(dval))
				{
					if (_nts_radix == 10)
					{
						PUSH_STR("NaN", 3);
					}
					else
					{
						// Flash quirk: NaN cast to int32 via x86 CVTTSD2SI gives INT32_MIN = -2147483648
						// Flash then formats in the given radix with inverted digit encoding: digit N -> char(48-N)
						// CR (char 13, digit 35) is normalized to LF to match expected output
						uint32_t _nts_uval = 2147483648U;
						char _nts_nan_tmp[128];
						int _nts_nan_pos = 0;
						uint32_t _nts_nan_n = _nts_uval;
						while (_nts_nan_n > 0 && _nts_nan_pos < 127)
						{
							int _nts_d = (int)(_nts_nan_n % (uint32_t)_nts_radix);
							char _nts_c = (char)(48 - _nts_d);
							if (_nts_c == '\r') _nts_c = '\n';
							_nts_nan_tmp[_nts_nan_pos++] = _nts_c;
							_nts_nan_n /= (uint32_t)_nts_radix;
						}
						int _nts_rpos = 0;
						_nts_buf[_nts_rpos++] = '-';
						for (int _nts_j = _nts_nan_pos - 1; _nts_j >= 0 && _nts_rpos < 255; _nts_j--)
							_nts_buf[_nts_rpos++] = _nts_nan_tmp[_nts_j];
						_nts_buf[_nts_rpos] = '\0';
						PUSH_STR(_nts_buf, (u32)_nts_rpos);
					}
				}
				else if (isinf(dval))
				{
					if (dval > 0) { PUSH_STR("Infinity", 8); }
					else          { PUSH_STR("-Infinity", 9); }
				}
				else if (_nts_radix == 10)
				{
					int _nts_len = snprintf(_nts_buf, sizeof(_nts_buf), "%.15g", dval);
					if (_nts_len < 0) _nts_len = 0;
					PUSH_STR(_nts_buf, (u32)_nts_len);
				}
				else
				{
					// Non-decimal radix: convert integer portion
					int negative = (dval < 0.0);
					double absval = negative ? -dval : dval;
					unsigned long long ival = (unsigned long long)absval;
					if (ival == 0)
					{
						PUSH_STR("0", 1);
					}
					else
					{
						const char* _nts_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
						char _nts_tmp[128];
						int _nts_pos = 0;
						unsigned long long n = ival;
						while (n > 0 && _nts_pos < 127)
						{
							_nts_tmp[_nts_pos++] = _nts_digits[n % _nts_radix];
							n /= _nts_radix;
						}
						int _nts_rpos = 0;
						if (negative) _nts_buf[_nts_rpos++] = '-';
						for (int _nts_j = _nts_pos - 1; _nts_j >= 0 && _nts_rpos < 255; _nts_j--)
							_nts_buf[_nts_rpos++] = _nts_tmp[_nts_j];
						_nts_buf[_nts_rpos] = '\0';
						PUSH_STR(_nts_buf, (u32)_nts_rpos);
					}
				}
			}
		}
		else if (method_name_len == 7 && strncmp(method_name, "valueOf", 7) == 0)
		{
			if (args != NULL) FREE(args);
			pushVar(app_context, &obj_var);
		}
		else
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
		}
		return;
	}
	else
	{
		// Not an object, array, function, string, number, or boolean - push undefined
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
	char target_name_buf[256];
	target_name_buf[0] = '\0';
	if (target.type == ACTION_STACK_VALUE_STRING)
	{
		const uint16_t* u16 = varGetU16Ptr(&target);
		if (u16) u16_to_utf8(u16, target.str_size, target_name_buf, sizeof(target_name_buf));
	}
	const char* target_name = target_name_buf;

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

	// Clear any existing drag (Flash only allows one sprite to be dragged at a time)
	if (is_dragging && dragged_target) {
		free(dragged_target);
	}

	is_dragging = 1;
	if (target_name && *target_name) {
		size_t len = strlen(target_name);
		dragged_target = (char*) malloc(len + 1);
		if (dragged_target) strcpy(dragged_target, target_name);
	} else {
		dragged_target = NULL;
	}

#ifdef NO_GRAPHICS
	// Initialize virtual drag position to current mouse position.
	// For lock_center=true, the clip center tracks the mouse exactly.
	g_drag_virt_x = app_context->mouse.stage_x;
	g_drag_virt_y = app_context->mouse.stage_y;

	// Remember which clip is being dragged (persists after stopDrag for PRESS hit-testing)
	if (target_name && *target_name)
		snprintf(g_drag_target_name, sizeof(g_drag_target_name), "%s", target_name);
#endif
	(void)lock_flag; (void)has_constraint; (void)x1; (void)y1; (void)x2; (void)y2;
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
	// Exceeded maximum number of frames (Flash caps at 16000 for WaitForFrame)
	if (frame > 16000)
		return false;

	// Get the current MovieClip
#ifndef NO_GRAPHICS
	if (targeted_sprite != NULL)
	{
		// Targeting a sprite without its own MovieClip struct:
		// consider frame as loaded (Ruffle: unwrap_or(true))
		return true;
	}
#endif
	MovieClip* mc = &root_movieclip;

	if (!mc)
		return true;  // No MovieClip -> consider loaded (Ruffle: unwrap_or(true))

	// For non-streaming SWFs, frames_loaded == totalframes.
	// Check: frames_loaded >= min(frame, header_frames)
	// The frame parameter is 0-based from bytecode.
	int32_t frames_loaded = (int32_t)mc->totalframes;
	u16 header_frames = (u16)mc->totalframes;
	u16 check_frame = frame < header_frames ? frame : header_frames;

	return frames_loaded >= (int32_t)check_frame;
}

bool actionWaitForFrame2(SWFAppContext* app_context)
{
	// Pop frame identifier from stack
	ActionVar frame_var;
	popVar(app_context, &frame_var);

	// Convert the popped value to a frame number following Flash/Ruffle semantics.
	// If the value is a number with no fractional part, use ECMAScript ToInt32 wrapping.
	// Otherwise, coerce to string and try parsing; non-integer results default to 0.
	int32_t frame_num = 0;

	if (frame_var.type == ACTION_STACK_VALUE_F64 || frame_var.type == ACTION_STACK_VALUE_F32)
	{
		double n = varToDouble(&frame_var);
		if (!isnan(n) && !isinf(n) && floor(n) == n)
		{
			// Integer number: use ECMAScript ToInt32 wrapping
			frame_num = (int32_t)varToUint32(&frame_var);
		}
		else
		{
			// NaN, Infinity, or fractional number: coerce to string and try parsing.
			// In practice, coercing NaN/Infinity/fractional to string and parsing back
			// will either fail or still be non-integer, so frame_num = 0 (always loaded).
			frame_num = 0;
		}
	}
	else if (frame_var.type == ACTION_STACK_VALUE_STRING)
	{
		// Try to parse the string as a number — convert UTF-16 to UTF-8 first
		const uint16_t* u16 = varGetU16Ptr(&frame_var);
		char str_buf[256];
		if (u16 != NULL && frame_var.str_size > 0)
		{
			u16_to_utf8(u16, frame_var.str_size, str_buf, sizeof(str_buf));
		} else {
			str_buf[0] = '\0';
		}
		const char* str = str_buf;
		if (str[0] != '\0')
		{
			char* end;
			double parsed = strtod(str, &end);
			// Skip trailing whitespace
			while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
			if (end != str && *end == '\0' && !isnan(parsed) && !isinf(parsed) && floor(parsed) == parsed)
			{
				// Successfully parsed an integer number from string
				// Use ECMAScript ToUint32 wrapping then cast to i32
				if (parsed == 0.0) frame_num = 0;
				else {
					double posInt = (parsed > 0 ? 1.0 : -1.0) * floor(fabs(parsed));
					double mod = fmod(posInt, 4294967296.0);
					if (mod < 0) mod += 4294967296.0;
					frame_num = (int32_t)(uint32_t)mod;
				}
			}
			else
			{
				frame_num = 0;
			}
		}
		else
		{
			frame_num = 0;
		}
	}
	else
	{
		// null, undefined, boolean, object, etc. -> frame_num = 0 (always loaded)
		frame_num = 0;
	}

	// Apply Flash's frame number adjustment:
	// wrapping_sub(1) then saturating_add(1)
	// This handles the off-by-one between 0-based and 1-based frame numbering.
	frame_num = (int32_t)((uint32_t)frame_num - 1u);  // wrapping subtract
	if (frame_num < INT32_MAX)
		frame_num = frame_num + 1;  // saturating add (won't overflow past INT32_MAX)

	// Exceeded maximum number of frames (off-by-one at 16001)
	if (frame_num > 16001)
		return false;

	// Get the current MovieClip (root or targeted sprite)
	MovieClip* mc = NULL;
#ifndef NO_GRAPHICS
	if (targeted_sprite != NULL)
	{
		// When targeting a sprite, if it's a valid MovieClip use it,
		// otherwise consider frame as loaded (Ruffle: unwrap_or(true))
		// For now, targeted sprites don't have their own MovieClip struct,
		// so we return true (all frames loaded for the target).
		return true;
	}
#endif
	mc = &root_movieclip;

	if (!mc)
		return true;  // No MovieClip -> consider loaded

	// For non-streaming SWFs, frames_loaded == totalframes.
	// Check: (frames_loaded + 1) >= min(frame_num as u16, header_frames)
	int32_t frames_loaded = (int32_t)mc->totalframes;
	uint16_t frame_u16 = (uint16_t)frame_num;
	uint16_t header_frames = (uint16_t)mc->totalframes;
	uint16_t check_frame = frame_u16 < header_frames ? frame_u16 : header_frames;

	return (frames_loaded + 1) >= (int32_t)check_frame;
}

// ===========================================================================
// AS2 MovieClip event dispatch (NO_GRAPHICS build)
// Handles onPress/onRelease/onReleaseOutside/onRollOver/onRollOut/onDragOver/onDragOut
// for dynamically-created MovieClips whose bounds come from Drawing API calls.
// ===========================================================================

#ifdef NO_GRAPHICS

// Compute pixel AABB for a dynamic MC using its drawing-API bounds.
// Returns 1 if bounds are available, 0 if not.
static int mc_get_pixel_aabb_ng(MovieClip* mc, float* x1, float* y1, float* x2, float* y2)
{
	if (mc == NULL || !mc->draw_has_bounds) return 0;
	float sx = mc->xscale / 100.0f;
	float sy = mc->yscale / 100.0f;
	*x1 = mc->x + mc->draw_xmin * sx;
	*y1 = mc->y + mc->draw_ymin * sy;
	*x2 = mc->x + mc->draw_xmax * sx;
	*y2 = mc->y + mc->draw_ymax * sy;
	if (*x1 > *x2) { float t = *x1; *x1 = *x2; *x2 = t; }
	if (*y1 > *y2) { float t = *y1; *y1 = *y2; *y2 = t; }
	return 1;
}

// Read the trackAsMenu property from mc->dynamic_props.
static int mc_get_track_as_menu_ng(MovieClip* mc)
{
	if (mc == NULL || mc->dynamic_props == NULL) return 0;
	ActionVar* v = getProperty((ASObject*)mc->dynamic_props, "trackAsMenu", 11);
	if (v == NULL) return 0;
	if (v->type == ACTION_STACK_VALUE_BOOLEAN)
		return (int)(v->data.numeric_value != 0);
	if (v->type == ACTION_STACK_VALUE_F32) {
		float f; memcpy(&f, &v->data.numeric_value, sizeof(float));
		return (f != 0.0f);
	}
	if (v->type == ACTION_STACK_VALUE_F64) {
		double d; memcpy(&d, &v->data.numeric_value, sizeof(double));
		return (d != 0.0);
	}
	return 0;
}

// Invoke a named AS2 event handler (onPress, onRelease, onDragOver, ...) stored
// in mc->dynamic_props, with `this` bound to mc.
static void mc_call_as2_handler_ng(SWFAppContext* app_context, MovieClip* mc,
                                    const char* name, u32 name_len)
{
	if (mc == NULL || mc->dynamic_props == NULL || g_execution_halted) return;
	ActionVar* handler_var = getProperty((ASObject*)mc->dynamic_props, name, name_len);
	if (handler_var == NULL || handler_var->type != ACTION_STACK_VALUE_FUNCTION) return;
	ASFunction* func = (ASFunction*)(uintptr_t)handler_var->data.numeric_value;
	if (func == NULL) return;

	if (g_call_depth >= g_max_call_depth - 1) {
		g_execution_halted = 1;
		return;
	}

	// Build this_var (MOVIECLIP) so actionCallMethod/GetVariable resolve "this" correctly.
	// NOTE: We intentionally do NOT call actionSetCurrentContext(mc) here.
	// Unqualified variable access (actionSetVariable/actionGetVariable) in AS2 MC event
	// handlers should use the root variable table so that variables set in one MC's handler
	// (e.g. left.onPress sets "isDown") are visible in another MC's handler (right.onDragOver).
	// The "this" binding is maintained via the local_scope entry in the scope chain below.
	ActionVar this_var = {0};
	this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
	this_var.data.numeric_value = (u64)(uintptr_t)mc;

	if (func->function_type == 2)
	{
		ActionVar* registers = NULL;
		if (func->register_count > 0)
			registers = (ActionVar*) HCALLOC(func->register_count, sizeof(ActionVar));

		ASObject* local_scope = allocObject(app_context, 8);
		// Expose "this" = mc so GetVariable("this") resolves inside the handler
		setProperty(app_context, local_scope, "this", 4, &this_var);
		if (scope_depth < MAX_SCOPE_DEPTH) {
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = mc;
			scope_chain[scope_depth++] = local_scope;
		}

		ASFunction* prev_func = g_current_executing_func;
		g_call_depth++;
		g_prev_executing_func = prev_func;
		g_current_executing_func = func;
		ActionVar result = func->advanced_func(app_context, NULL, 0, registers, (void*)&this_var);
		(void)result;
		g_current_executing_func = prev_func;
		g_call_depth--;

		if (scope_depth > 0) scope_depth--;
		releaseObject(app_context, local_scope);
		if (registers != NULL) FREE(registers);
	}
	else if (func->function_type == 1 && func->simple_func != NULL)
	{
		g_call_depth++;
		ActionVar result = ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context);
		(void)result;
		g_call_depth--;
	}
}

// Dispatch AS2 onPress to all dynamic MCs whose hit area contains the mouse.
// Called from swf_core.c on EV_MOUSE_DOWN_LEFT (after dispatch_clip_event_press).
void actionDispatchMCPress(SWFAppContext* app_context)
{
	float mx = app_context->mouse.stage_x / 20.0f;  // stage_x is in twips; convert to pixels
	float my = app_context->mouse.stage_y / 20.0f;

	for (int i = 0; i < child_mc_count; i++) {
		MovieClip* mc = child_mc_cache[i];
		if (mc == NULL || mc->dynamic_props == NULL) continue;

		float x1, y1, x2, y2;
		if (!mc_get_pixel_aabb_ng(mc, &x1, &y1, &x2, &y2)) continue;

		if (mx < x1 || mx > x2 || my < y1 || my > y2) continue;

		mc->mc_as_pressed = 1;
		mc->mc_mouse_inside = 1;
		mc_call_as2_handler_ng(app_context, mc, "onPress", 7);
	}
}

// Dispatch AS2 onRelease / onReleaseOutside to pressed MCs on mouse-up.
// Called from swf_core.c on EV_MOUSE_UP_LEFT (after dispatch_clip_event_release).
void actionDispatchMCRelease(SWFAppContext* app_context)
{
	float mx = app_context->mouse.stage_x / 20.0f;
	float my = app_context->mouse.stage_y / 20.0f;

	for (int i = 0; i < child_mc_count; i++) {
		MovieClip* mc = child_mc_cache[i];
		if (mc == NULL || !mc->mc_as_pressed) continue;

		float x1, y1, x2, y2;
		int have_bounds = mc_get_pixel_aabb_ng(mc, &x1, &y1, &x2, &y2);
		int inside = have_bounds && (mx >= x1 && mx <= x2 && my >= y1 && my <= y2);

		mc->mc_as_pressed = 0;

		if (inside)
			mc_call_as2_handler_ng(app_context, mc, "onRelease", 9);
		else
			mc_call_as2_handler_ng(app_context, mc, "onReleaseOutside", 16);
	}
}

// Dispatch AS2 onRollOver/onRollOut/onDragOver/onDragOut on mouse-move.
// Called from swf_core.c on EV_MOUSE_MOVE (after updating mouse state).
void actionDispatchMCMouseMove(SWFAppContext* app_context)
{
	float mx = app_context->mouse.stage_x / 20.0f;
	float my = app_context->mouse.stage_y / 20.0f;
	int btn_down = app_context->mouse.button_down;

	for (int i = 0; i < child_mc_count; i++) {
		MovieClip* mc = child_mc_cache[i];
		if (mc == NULL || mc->dynamic_props == NULL) continue;

		float x1, y1, x2, y2;
		if (!mc_get_pixel_aabb_ng(mc, &x1, &y1, &x2, &y2)) continue;

		int was_inside = mc->mc_mouse_inside;
		int now_inside = (mx >= x1 && mx <= x2 && my >= y1 && my <= y2);
		mc->mc_mouse_inside = (u8)now_inside;

		if (!was_inside && now_inside) {
			// Mouse entered this MC's hit area
			if (btn_down) {
				// onDragOver fires if trackAsMenu=true OR button was pressed inside this MC
				if (mc_get_track_as_menu_ng(mc) || mc->mc_as_pressed)
					mc_call_as2_handler_ng(app_context, mc, "onDragOver", 10);
			} else {
				mc_call_as2_handler_ng(app_context, mc, "onRollOver", 10);
			}
		} else if (was_inside && !now_inside) {
			// Mouse exited this MC's hit area
			if (btn_down) {
				if (mc_get_track_as_menu_ng(mc) || mc->mc_as_pressed)
					mc_call_as2_handler_ng(app_context, mc, "onDragOut", 9);
			} else {
				mc_call_as2_handler_ng(app_context, mc, "onRollOut", 9);
			}
		}
	}
}

// ====== Focus and Tab Navigation System ======

// Convert mc->target (Flash slash-path) to ActionScript dot-path format.
// "/" -> "_level0"
// "/clip1" -> "_level0.clip1"
// "/clip1/text" -> "_level0.clip1.text"
static void mc_get_dot_path(MovieClip* mc, char* buf, size_t buf_size)
{
	extern MovieClip root_movieclip;
	if (mc == NULL || mc == &root_movieclip) {
		snprintf(buf, buf_size, "_level0");
		return;
	}
	const char* path = mc->target;
	if (path[0] == '/' && path[1] == '\0') {
		snprintf(buf, buf_size, "_level0");
	} else if (path[0] == '/') {
		// "/clip1" -> "_level0.clip1"  or  "/clip1/text" -> "_level0.clip1.text"
		char tmp[256];
		strncpy(tmp, path + 1, sizeof(tmp) - 1);
		tmp[sizeof(tmp) - 1] = '\0';
		for (char* p = tmp; *p; p++) {
			if (*p == '/') *p = '.';
		}
		snprintf(buf, buf_size, "_level0.%s", tmp);
	} else {
		snprintf(buf, buf_size, "_level0.%s", mc->name);
	}
}

// Check if an MC can receive focus via Selection.setFocus().
// Text fields and buttons are always focusable.
// MovieClips are focusable only if they have an onSetFocus handler or focusEnabled == true.
static int mc_is_focusable_by_setfocus(MovieClip* mc)
{
	if (mc == NULL) return 0;
	if (mc->ng_textfield_idx >= 0) return 1;   // text field: always focusable
	if (mc->is_button_mc) return 1;             // button: always focusable
	if (mc->dynamic_props == NULL) return 0;
	// MC with onSetFocus handler: focusable
	ActionVar* h = getProperty((ASObject*)mc->dynamic_props, "onSetFocus", 10);
	if (h != NULL && h->type == ACTION_STACK_VALUE_FUNCTION) return 1;
	// MC with focusEnabled = true: focusable
	ActionVar* fe = getProperty((ASObject*)mc->dynamic_props, "focusEnabled", 12);
	if (fe != NULL) {
		if (fe->type == ACTION_STACK_VALUE_BOOLEAN) return (int)fe->data.numeric_value;
		if (fe->type == ACTION_STACK_VALUE_F64) {
			double d; memcpy(&d, &fe->data.numeric_value, 8);
			return (d != 0.0);
		}
	}
	return 0;
}

// Check if an MC is tabbable (appears in Tab key navigation order).
static int mc_is_tabbable(MovieClip* mc)
{
	if (mc == NULL || !mc->visible) return 0;
	// Check explicit tabEnabled override in dynamic_props
	if (mc->dynamic_props != NULL) {
		ActionVar* te = getProperty((ASObject*)mc->dynamic_props, "tabEnabled", 10);
		if (te != NULL && te->type != ACTION_STACK_VALUE_UNDEFINED) {
			if (te->type == ACTION_STACK_VALUE_BOOLEAN) return (int)te->data.numeric_value;
			if (te->type == ACTION_STACK_VALUE_NULL) return 0;
			if (te->type == ACTION_STACK_VALUE_F64) {
				double d; memcpy(&d, &te->data.numeric_value, 8);
				return (d != 0.0 && d == d);
			}
			return 0;
		}
	}
	// Default: buttons are tabbable
	if (mc->is_button_mc) return 1;
	// Default: input text fields (not ReadOnly flag 0x0008) are tabbable
	if (mc->ng_textfield_idx >= 0) {
		u16 flags = ng_getTextFieldFlags(mc->ng_textfield_idx);
		if (!(flags & 0x0008)) return 1;
	}
	return 0;
}

// Get explicit tabIndex for an MC. Returns INT_MIN if tabIndex is not set or is -1 (excluded).
// Flash stores tabIndex as a Number (double); to handle large values like 4294967293
// correctly as -3 (i32_vs_u32 test), we convert double→u32→int32 (signed wrapping).
// tabIndex=-1 means "excluded from tab order" (like HTML tabindex=-1): returns INT_MIN.
static int mc_get_explicit_tab_index(MovieClip* mc)
{
	if (mc == NULL || mc->dynamic_props == NULL) return INT_MIN;
	ActionVar* ti = getProperty((ASObject*)mc->dynamic_props, "tabIndex", 8);
	if (ti == NULL || ti->type == ACTION_STACK_VALUE_UNDEFINED) return INT_MIN;
	int idx = INT_MIN;
	if (ti->type == ACTION_STACK_VALUE_F64) {
		double d; memcpy(&d, &ti->data.numeric_value, 8);
		if (d != d) return INT_MIN;  // NaN → not set
		// Convert via u32 to get correct signed wrapping (e.g. 4294967293 → -3)
		u32 u = (u32)d;
		idx = (int)u;
	} else if (ti->type == ACTION_STACK_VALUE_F32) {
		float f; memcpy(&f, &ti->data.numeric_value, 4);
		u32 u = (u32)f;
		idx = (int)u;
	} else if (ti->type == ACTION_STACK_VALUE_BOOLEAN) {
		idx = (int)(u32)ti->data.numeric_value;
	} else {
		return INT_MIN;
	}
	// tabIndex=-1 means excluded from tab order
	if (idx == -1) return INT_MIN;
	return idx;
}

// Fire focus change events and update g_focused_mc.
// Fires: old_mc.onKillFocus(), new_mc.onSetFocus(), Selection.broadcastMessage("onSetFocus").
static void selection_do_focus_change(SWFAppContext* app_context, MovieClip* old_mc, MovieClip* new_mc)
{
	if (old_mc == new_mc) return;
	// 1. onKillFocus on old MC (no-op if handler not defined)
	mc_call_as2_handler_ng(app_context, old_mc, "onKillFocus", 11);
	// 2. onSetFocus on new MC (no-op if handler not defined)
	mc_call_as2_handler_ng(app_context, new_mc, "onSetFocus", 10);
	// 3. Update focused MC before broadcasting
	g_focused_mc = new_mc;
	// When a text field gains focus, select all text (matches Flash behavior)
	if (new_mc != NULL && new_mc->ng_textfield_idx >= 0)
		g_tf_select_all = 1;
	else
		g_tf_select_all = 0;
	// 4. Selection.broadcastMessage("onSetFocus", old_path, new_path)
	if (!g_selection_obj) return;
	static const uint16_t s_onSetFocus_u16[] = {
		'o','n','S','e','t','F','o','c','u','s'
	};
	ActionVar bcast_args[3];
	memset(bcast_args, 0, sizeof(bcast_args));
	bcast_args[0].type = ACTION_STACK_VALUE_STRING;
	bcast_args[0].data.numeric_value = (u64)(uintptr_t)s_onSetFocus_u16;
	bcast_args[0].str_size = 10;
	if (old_mc == NULL) {
		bcast_args[1].type = ACTION_STACK_VALUE_NULL;
	} else {
		bcast_args[1].type = ACTION_STACK_VALUE_MOVIECLIP;
		bcast_args[1].data.numeric_value = (u64)(uintptr_t)old_mc;
	}
	if (new_mc == NULL) {
		bcast_args[2].type = ACTION_STACK_VALUE_NULL;
	} else {
		bcast_args[2].type = ACTION_STACK_VALUE_MOVIECLIP;
		bcast_args[2].data.numeric_value = (u64)(uintptr_t)new_mc;
	}
	builtin_broadcaster_broadcastMessage(app_context, bcast_args, 3, NULL, (void*)g_selection_obj);
}

// Selection.setFocus(target) — move keyboard focus to a specific object.
static ActionVar builtin_selection_setFocus(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
	if (arg_count < 1) return undef;
	ActionVar* arg = &args[0];
	// setFocus(null or undefined) — clear focus
	if (arg->type == ACTION_STACK_VALUE_NULL || arg->type == ACTION_STACK_VALUE_UNDEFINED) {
		if (g_focused_mc != NULL)
			selection_do_focus_change(app_context, g_focused_mc, NULL);
		return undef;
	}
	MovieClip* new_mc = NULL;
	if (arg->type == ACTION_STACK_VALUE_MOVIECLIP)
		new_mc = (MovieClip*)(uintptr_t)arg->data.numeric_value;
	if (new_mc == NULL) return undef;
	if (!mc_is_focusable_by_setfocus(new_mc)) return undef;
	if (new_mc == g_focused_mc) return undef;
	selection_do_focus_change(app_context, g_focused_mc, new_mc);
	return undef;
}

// Selection.getFocus() — returns dot-path string of focused object, or null.
static ActionVar builtin_selection_getFocus(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)args; (void)arg_count; (void)registers; (void)this_obj;
	ActionVar result = {0};
	if (g_focused_mc == NULL) {
		result.type = ACTION_STACK_VALUE_NULL;
		return result;
	}
	char path_buf[320];
	mc_get_dot_path(g_focused_mc, path_buf, sizeof(path_buf));
	int plen = (int)strlen(path_buf);
	u32 u16_len;
	uint16_t* u16 = ascii_to_u16(app_context, path_buf, plen, &u16_len);
	result.type = ACTION_STACK_VALUE_STRING;
	result.data.numeric_value = (u64)(uintptr_t)u16;
	result.str_size = u16_len;
	return result;
}

// Check tabChildren property of an MC (default: true = recurse into children).
static int mc_get_tab_children(MovieClip* mc)
{
	if (mc == NULL || mc->dynamic_props == NULL) return 1;
	ActionVar* tc = getProperty((ASObject*)mc->dynamic_props, "tabChildren", 11);
	if (tc == NULL || tc->type == ACTION_STACK_VALUE_UNDEFINED) return 1;
	if (tc->type == ACTION_STACK_VALUE_BOOLEAN) return (int)tc->data.numeric_value;
	if (tc->type == ACTION_STACK_VALUE_NULL) return 0;
	if (tc->type == ACTION_STACK_VALUE_F64) {
		double d; memcpy(&d, &tc->data.numeric_value, 8);
		return (d != 0.0 && d == d) ? 1 : 0;
	}
	return 1;
}

// Compute the minimum visual position (y, x) of non-sprite items within a display list.
// This is used as the sort key for tabbable sprites in automatic tab order mode.
// Ruffle's automatic tab order sorts by the top-left corner of the highlight bounds
// (visual bounding box), using the formula 6*min_y + min_x.
// For sprites (containers), the highlight bounds come from their visual children
// recursively, not from the registration point.
static void compute_min_visual_pos(
	DisplayObject* dl, size_t dl_max,
	float parent_gx, float parent_gy,
	float* min_x, float* min_y)
{
	extern float transform_data[][16];
	for (size_t d = 1; d <= dl_max; d++) {
		if (dl[d].char_id == 0) continue;
		size_t cid = dl[d].char_id;
		float lx = transform_data[dl[d].transform_id][12] / 20.0f;
		float ly = transform_data[dl[d].transform_id][13] / 20.0f;
		float gx = parent_gx + lx;
		float gy = parent_gy + ly;
		if (dictionary[cid].type == CHAR_TYPE_SPRITE) {
			// Recurse into sprite children to find visual bounds
			if (dl[d].sprite_display_list != NULL && dl[d].sprite_max_depth > 0)
				compute_min_visual_pos(dl[d].sprite_display_list,
				    dl[d].sprite_max_depth, gx, gy, min_x, min_y);
		} else {
			// Text field, button, or shape — use its global position
			if (gy < *min_y || (gy == *min_y && gx < *min_x)) {
				*min_y = gy;
				*min_x = gx;
			}
		}
	}
}

// Recursive depth-first collection of tabbable MCs.
// Scans dl[1..dl_max] (a display list) in ascending depth order (natural iteration),
// creates MCs as needed, and collects tabbable ones.
// For each child, computes its sort position (for automatic mode):
//   - Text fields/buttons: global registration point
//   - Tabbable sprites: minimum visual position from compute_min_visual_pos
// Stores the sort position in mc->x/mc->y for the final sort step.
// tabChildren=true (default) means recurse into a sprite's children.
static void tab_collect_recursive(
	SWFAppContext* app_context,
	DisplayObject* dl, size_t dl_max,
	MovieClip* parent_mc,
	float parent_global_x, float parent_global_y,
	MovieClip** out, int* count, int max)
{
	extern float transform_data[][16];

	// Iterate in natural ascending depth order (d=1..dl_max)
	for (size_t d = 1; d <= dl_max; d++) {
		if (dl[d].char_id == 0) continue;
		size_t cid = dl[d].char_id;

		// Only process sprites, buttons, and text fields
		int is_sprite = (dictionary[cid].type == CHAR_TYPE_SPRITE);
		int is_button = (dictionary[cid].type == CHAR_TYPE_BUTTON);
		int is_tf    = (ng_getCharTextfieldIdx(cid) >= 0);
		if (!is_sprite && !is_button && !is_tf) continue;

		const char* name = dl[d].instance_name;
		if (!name || !name[0]) continue;

		// Compute GLOBAL position = parent global + local transform
		u32 tid = dl[d].transform_id;
		float local_x = transform_data[tid][12] / 20.0f;
		float local_y = transform_data[tid][13] / 20.0f;
		float global_x = parent_global_x + local_x;
		float global_y = parent_global_y + local_y;

		// Find or create the child MC
		MovieClip* mc = findOrCreateMovieClip(app_context, name, parent_mc);
		if (mc == NULL) continue;

		// Compute the SORT POSITION for this item:
		// - Text fields/buttons: their global registration point (top-left of bounds)
		// - Sprites: minimum visual position from their children (not registration point),
		//   because the focus highlight bounds come from visual content, not the sprite origin.
		//   This matches Ruffle's automatic tab ordering: sort by highlight bounds top-left.
		float sort_x = global_x;
		float sort_y = global_y;
		if (is_sprite && !is_button) {
			// Use visual bounding box min, not registration point
			float vis_min_x = 1e30f, vis_min_y = 1e30f;
			if (dl[d].sprite_display_list != NULL && dl[d].sprite_max_depth > 0) {
				compute_min_visual_pos(dl[d].sprite_display_list,
				    dl[d].sprite_max_depth,
				    global_x, global_y,
				    &vis_min_x, &vis_min_y);
			}
			if (vis_min_y < 1e29f) { sort_x = vis_min_x; sort_y = vis_min_y; }
		}
		mc->x = sort_x;
		mc->y = sort_y;

		// For nested text fields: set ng_textfield_idx if not already set
		if (mc->ng_textfield_idx < 0) {
			int tf_idx = ng_getCharTextfieldIdx(cid);
			if (tf_idx >= 0) mc->ng_textfield_idx = tf_idx;
		}

		// For nested buttons: mark is_button_mc if not already set
		if (!mc->is_button_mc && dictionary[cid].type == CHAR_TYPE_BUTTON) {
			mc->is_button_mc = 1;
		}

		// If tabbable, add to output (in natural depth-first depth order)
		if (mc_is_tabbable(mc) && *count < max)
			out[(*count)++] = mc;

		// Recurse into sprite children if tabChildren=true
		if (is_sprite &&
		    dl[d].sprite_display_list != NULL && dl[d].sprite_max_depth > 0) {
			if (mc_get_tab_children(mc)) {
				tab_collect_recursive(app_context,
				    dl[d].sprite_display_list, dl[d].sprite_max_depth,
				    mc, global_x, global_y, out, count, max);
			}
		}
	}
}

// Advance keyboard focus to the next tabbable MovieClip (called on Tab key press).
// reversed=1 for Shift+Tab (previous element), 0 for Tab (next element).
void actionAdvanceTabFocus(SWFAppContext* app_context, int reversed)
{
	extern DisplayObject* display_list;
	extern size_t max_depth;
	extern MovieClip root_movieclip;

	// If _root.tabChildren is false, Tab key does nothing at all
	if (!mc_get_tab_children(&root_movieclip)) return;

	// Pre-scan child_mc_cache to determine if any MC has explicit tabIndex.
	// MCs that have had tabIndex set by script will already be in child_mc_cache.
	int any_has_explicit = 0;
	for (int i = 0; i < child_mc_count; i++) {
		if (child_mc_cache[i] != NULL &&
		    mc_get_explicit_tab_index(child_mc_cache[i]) != INT_MIN) {
			any_has_explicit = 1;
			break;
		}
	}

	// Build flat list via depth-first hierarchical traversal in natural depth order.
	// Each MC's mc->x/mc->y is set to its GLOBAL pixel position during traversal.
	MovieClip* natural_order[MAX_CHILD_MOVIECLIPS];
	int natural_count = 0;
	tab_collect_recursive(app_context, display_list, max_depth,
	    &root_movieclip, 0.0f, 0.0f,
	    natural_order, &natural_count, MAX_CHILD_MOVIECLIPS);

	if (natural_count == 0) return;

	// Flash tab ordering rules:
	// EXPLICIT mode (any element has tabIndex): only elements with explicit tabIndex
	//   participate; natural depth-first-depth order is the tiebreaker for equal values;
	//   stable-sort by tabIndex.
	// AUTOMATIC mode (no explicit tabIndex): sort all collected elements by GLOBAL
	//   pixel position (y then x).

	MovieClip* tab_order[MAX_CHILD_MOVIECLIPS];
	int tab_count = 0;

	if (any_has_explicit) {
		// Filter: only elements with explicit tabIndex (tabIndex=-1 → INT_MIN → excluded)
		for (int i = 0; i < natural_count; i++) {
			if (mc_get_explicit_tab_index(natural_order[i]) != INT_MIN)
				tab_order[tab_count++] = natural_order[i];
		}
		// Stable insertion sort by tabIndex.
		// Tiebreaker (equal tabIndex): natural depth-first-depth order is preserved
		// because this is a stable sort and natural_order is already in depth order.
		for (int i = 1; i < tab_count; i++) {
			MovieClip* key = tab_order[i];
			int key_idx = mc_get_explicit_tab_index(key);
			int j = i - 1;
			while (j >= 0 && mc_get_explicit_tab_index(tab_order[j]) > key_idx) {
				tab_order[j+1] = tab_order[j];
				j--;
			}
			tab_order[j+1] = key;
		}
	} else {
		// Automatic mode: sort by Ruffle's highlight-bounds formula: 6*min_y + min_x
		// mc->x and mc->y were set to the sort position during traversal:
		//   - text fields/buttons: global registration point
		//   - sprites: minimum visual position of their children (highlight bounds)
		// For equal keys, the traversal order (natural depth-first ascending-depth) is
		// preserved (stable sort), with duplicates removed (first-found wins).
		for (int i = 0; i < natural_count; i++)
			tab_order[tab_count++] = natural_order[i];
		// Stable insertion sort by 6*y + x (ascending)
		for (int i = 1; i < tab_count; i++) {
			MovieClip* key = tab_order[i];
			float key_sort = 6.0f * key->y + key->x;
			int j = i - 1;
			while (j >= 0 && 6.0f * tab_order[j]->y + tab_order[j]->x > key_sort) {
				tab_order[j+1] = tab_order[j]; j--;
			}
			tab_order[j+1] = key;
		}
		// Remove duplicates: when two items have the same 6y+x, keep only the first
		// (which is the first found in depth-first-depth-order traversal).
		int dedup_count = 0;
		for (int i = 0; i < tab_count; i++) {
			if (dedup_count > 0) {
				float prev_sort = 6.0f * tab_order[dedup_count-1]->y + tab_order[dedup_count-1]->x;
				float this_sort = 6.0f * tab_order[i]->y + tab_order[i]->x;
				if (this_sort == prev_sort) continue; // Skip duplicate
			}
			tab_order[dedup_count++] = tab_order[i];
		}
		tab_count = dedup_count;
	}

	if (tab_count == 0) return;

	// Find current focused MC in tab order
	int cur_pos = -1;
	for (int i = 0; i < tab_count; i++) {
		if (tab_order[i] == g_focused_mc) { cur_pos = i; break; }
	}

	// Advance to next or previous (wrap around); no-op if only one element
	int next_pos;
	if (reversed) {
		// Shift+Tab: go backward; if not in list (cur_pos==-1), go to last element
		next_pos = (cur_pos <= 0) ? tab_count - 1 : cur_pos - 1;
	} else {
		// Tab: go forward; wraps from last to first
		next_pos = (cur_pos + 1) % tab_count;
	}
	MovieClip* new_mc = tab_order[next_pos];
	if (new_mc == g_focused_mc) return;
	selection_do_focus_change(app_context, g_focused_mc, new_mc);
}

// ---------------------------------------------------------------------------
// Clipboard + Text Control operations
// ---------------------------------------------------------------------------

void actionSetClipboardText(const char* text)
{
	if (text == NULL) {
		g_clipboard_text[0] = '\0';
		g_clipboard_len = 0;
		return;
	}
	size_t len = strlen(text);
	if (len >= sizeof(g_clipboard_text))
		len = sizeof(g_clipboard_text) - 1;
	memcpy(g_clipboard_text, text, len);
	g_clipboard_text[len] = '\0';
	g_clipboard_len = len;
}

void actionTextControlSelectAll(SWFAppContext* app_context)
{
	(void)app_context;
	g_tf_select_all = 1;
}

void actionTextControlCopy(SWFAppContext* app_context)
{
	(void)app_context;
	if (g_focused_mc == NULL || g_focused_mc->ng_textfield_idx < 0) return;
	ASObject* props = (ASObject*) g_focused_mc->dynamic_props;
	if (props == NULL) return;

	// Check password flag — password fields don't allow Copy
	ActionVar* pw_prop = getProperty(props, "password", 8);
	if (pw_prop != NULL && pw_prop->type == ACTION_STACK_VALUE_BOOLEAN && pw_prop->data.numeric_value != 0)
		return;

	// Read text property
	ActionVar* text_prop = getProperty(props, "text", 4);
	if (text_prop == NULL || text_prop->type != ACTION_STACK_VALUE_STRING) {
		g_clipboard_text[0] = '\0';
		g_clipboard_len = 0;
		return;
	}

	const uint16_t* u16 = varGetU16Ptr(text_prop);
	if (u16 == NULL || text_prop->str_size == 0) {
		g_clipboard_text[0] = '\0';
		g_clipboard_len = 0;
		return;
	}

	int written = u16_to_utf8(u16, text_prop->str_size, g_clipboard_text, (int)sizeof(g_clipboard_text));
	g_clipboard_len = (size_t)written;
}

void actionTextControlCut(SWFAppContext* app_context)
{
	if (g_focused_mc == NULL || g_focused_mc->ng_textfield_idx < 0) return;
	ASObject* props = (ASObject*) g_focused_mc->dynamic_props;
	if (props == NULL) return;

	// Check password flag — password fields: complete no-op (no copy, no delete)
	ActionVar* pw_prop = getProperty(props, "password", 8);
	if (pw_prop != NULL && pw_prop->type == ACTION_STACK_VALUE_BOOLEAN && pw_prop->data.numeric_value != 0)
		return;

	// Copy text to clipboard first
	actionTextControlCopy(app_context);

	// Clear the text field
	static const uint16_t empty_u16[] = {0};
	ActionVar empty_text = {0};
	empty_text.type = ACTION_STACK_VALUE_STRING;
	empty_text.data.numeric_value = (u64)(uintptr_t)empty_u16;
	empty_text.str_size = 0;
	setProperty(app_context, props, "text", 4, &empty_text);

	ActionVar len_val = {0};
	len_val.type = ACTION_STACK_VALUE_F64;
	VAL(double, &len_val.data.numeric_value) = 0.0;
	setProperty(app_context, props, "length", 6, &len_val);

	ng_syncTextToVar(app_context, g_focused_mc, &empty_text);
	g_tf_select_all = 0;
}

// Apply restrict filter: for each char in input, check against restrict string.
// If tolower(input_char) matches tolower(restrict_char), output the restrict_char.
// Returns number of bytes written to output (not including NUL).
static size_t apply_restrict_filter(const char* input, size_t input_len,
                                     const char* restrict_str, char* output, size_t max_out)
{
	size_t out_pos = 0;
	size_t restrict_len = strlen(restrict_str);

	for (size_t i = 0; i < input_len && out_pos < max_out - 1; i++) {
		unsigned char ic = (unsigned char)input[i];
		// For multi-byte UTF-8, pass through bytes that aren't ASCII
		if (ic >= 0x80) {
			output[out_pos++] = (char)ic;
			continue;
		}
		char ic_lower = (ic >= 'A' && ic <= 'Z') ? (char)(ic + 32) : (char)ic;
		int found = 0;
		for (size_t r = 0; r < restrict_len; r++) {
			unsigned char rc = (unsigned char)restrict_str[r];
			if (rc >= 0x80) continue;
			char rc_lower = (rc >= 'A' && rc <= 'Z') ? (char)(rc + 32) : (char)rc;
			if (ic_lower == rc_lower) {
				output[out_pos++] = (char)rc;
				found = 1;
				break;
			}
		}
		// If not found in restrict, the character is dropped
		(void)found;
	}
	output[out_pos] = '\0';
	return out_pos;
}

void actionTextControlPaste(SWFAppContext* app_context)
{
	// Empty clipboard → no-op
	if (g_clipboard_len == 0) return;

	if (g_focused_mc == NULL || g_focused_mc->ng_textfield_idx < 0) return;
	ASObject* props = (ASObject*) g_focused_mc->dynamic_props;
	if (props == NULL) return;

	// Start with clipboard text
	char filtered[1024];
	size_t filtered_len = g_clipboard_len;
	memcpy(filtered, g_clipboard_text, g_clipboard_len);
	filtered[g_clipboard_len] = '\0';

	// Apply restrict filter if set
	ActionVar* restrict_prop = getProperty(props, "restrict", 8);
	if (restrict_prop != NULL && restrict_prop->type == ACTION_STACK_VALUE_STRING
	    && restrict_prop->str_size > 0) {
		const uint16_t* r_u16 = varGetU16Ptr(restrict_prop);
		char restrict_utf8[256];
		if (r_u16 != NULL) {
			u16_to_utf8(r_u16, restrict_prop->str_size, restrict_utf8, (int)sizeof(restrict_utf8));
			char restricted[1024];
			filtered_len = apply_restrict_filter(filtered, filtered_len, restrict_utf8, restricted, sizeof(restricted));
			memcpy(filtered, restricted, filtered_len);
			filtered[filtered_len] = '\0';
		}
	}

	// If filtered result is empty, no-op
	if (filtered_len == 0) return;

	// Determine existing text
	char existing[2048] = {0};
	size_t existing_len = 0;
	if (!g_tf_select_all) {
		ActionVar* text_prop = getProperty(props, "text", 4);
		if (text_prop != NULL && text_prop->type == ACTION_STACK_VALUE_STRING && text_prop->str_size > 0) {
			const uint16_t* t_u16 = varGetU16Ptr(text_prop);
			if (t_u16 != NULL)
				existing_len = (size_t)u16_to_utf8(t_u16, text_prop->str_size, existing, (int)sizeof(existing));
		}
	}

	// Build result: existing + filtered (or just filtered if select_all)
	char result[2048];
	size_t result_len = 0;
	if (existing_len > 0) {
		memcpy(result, existing, existing_len);
		result_len = existing_len;
	}
	if (result_len + filtered_len < sizeof(result)) {
		memcpy(result + result_len, filtered, filtered_len);
		result_len += filtered_len;
	}
	result[result_len] = '\0';

	// Apply maxChars truncation (in characters, not bytes — count UTF-16 code units)
	ActionVar* maxc_prop = getProperty(props, "maxChars", 8);
	int max_chars = -1;
	if (maxc_prop != NULL && maxc_prop->type == ACTION_STACK_VALUE_F64) {
		double d; memcpy(&d, &maxc_prop->data.numeric_value, 8);
		if (d > 0 && d == d) max_chars = (int)d;
	}

	// Convert result to UTF-16
	u32 u16_len = 0;
	uint16_t* u16_result = utf8_to_u16(app_context, result, (u32)result_len, &u16_len);

	// Truncate to maxChars if needed
	if (max_chars > 0 && (int)u16_len > max_chars) {
		u16_len = (u32)max_chars;
		u16_result[u16_len] = 0;
	}

	// Set text property
	ActionVar new_text = {0};
	new_text.type = ACTION_STACK_VALUE_STRING;
	new_text.data.numeric_value = (u64)(uintptr_t)u16_result;
	new_text.str_size = u16_len;
	setProperty(app_context, props, "text", 4, &new_text);

	// Update length property
	ActionVar len_val = {0};
	len_val.type = ACTION_STACK_VALUE_F64;
	VAL(double, &len_val.data.numeric_value) = (double)u16_len;
	setProperty(app_context, props, "length", 6, &len_val);

	// Sync to variable binding
	ng_syncTextToVar(app_context, g_focused_mc, &new_text);
	g_tf_select_all = 0;
}

#endif // NO_GRAPHICS (AS2 MC event dispatch)
