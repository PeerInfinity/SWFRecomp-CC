#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <recomp.h>
#include <utils.h>
#include <actionmodern/object.h>

u32 start_time;

// ==================================================================
// Scope Chain for WITH statement
// ==================================================================

#define MAX_SCOPE_DEPTH 32
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u32 scope_depth = 0;

// ==================================================================
// Function Storage and Management
// ==================================================================

// Function pointer types
typedef void (*SimpleFunctionPtr)(char* stack, u32* sp);
typedef ActionVar (*Function2Ptr)(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);

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
} ASFunction;

// Function registry
#define MAX_FUNCTIONS 256
static ASFunction* function_registry[MAX_FUNCTIONS];
static u32 function_count = 0;

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

void initTime()
{
	start_time = get_elapsed_ms();
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

typedef struct {
	float x, y;
	float xscale, yscale;
	float rotation;
	float alpha;
	float width, height;
	int visible;
	int currentframe;
	int totalframes;
	char name[256];
	char target[256];
} MovieClip;

// Static _root MovieClip for simplified implementation
static MovieClip root_movieclip = {
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
	.totalframes = 1,
	.name = "_root",
	.target = "_root"
};

// Helper function to get MovieClip by target path
// Simplified: only supports "_root" or empty string
static MovieClip* getMovieClipByTarget(const char* target) {
	if (!target || strlen(target) == 0 || strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
		return &root_movieclip;
	}
	return NULL;  // Other paths not supported yet
}

ActionStackValueType convertString(char* stack, u32* sp, char* var_str)
{
	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_F32)
	{
		float temp_val = VAL(float, &STACK_TOP_VALUE);  // Save the float value first!
		STACK_TOP_TYPE = ACTION_STACK_VALUE_STRING;
		VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
		snprintf(var_str, 17, "%.15g", temp_val);  // Use the saved value
	}

	return ACTION_STACK_VALUE_STRING;
}

ActionStackValueType convertFloat(char* stack, u32* sp)
{
	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STRING)
	{
		double temp = atof((char*) VAL(u64, &STACK_TOP_VALUE));
		STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
		VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
		
		return ACTION_STACK_VALUE_F64;
	}
	
	return ACTION_STACK_VALUE_F32;
}

ActionStackValueType convertDouble(char* stack, u32* sp)
{
	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_F32)
	{
		double temp = VAL(double, &STACK_TOP_VALUE);
		STACK_TOP_TYPE = ACTION_STACK_VALUE_F64;
		VAL(u64, &STACK_TOP_VALUE) = VAL(u64, &temp);
	}
	
	return ACTION_STACK_VALUE_F64;
}

void pushVar(char* stack, u32* sp, ActionVar* var)
{
	switch (var->type)
	{
		case ACTION_STACK_VALUE_F32:
		case ACTION_STACK_VALUE_F64:
		case ACTION_STACK_VALUE_UNDEFINED:
		case ACTION_STACK_VALUE_OBJECT:
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

			PUSH_STR(str_ptr, var->str_size);

			break;
		}
	}
}

void peekVar(char* stack, u32* sp, ActionVar* var)
{
	var->type = STACK_TOP_TYPE;
	var->str_size = STACK_TOP_N;

	if (STACK_TOP_TYPE == ACTION_STACK_VALUE_STR_LIST)
	{
		var->data.numeric_value = (u64) &STACK_TOP_VALUE;
	}

	else
	{
		var->data.numeric_value = VAL(u64, &STACK_TOP_VALUE);
	}
}

void popVar(char* stack, u32* sp, ActionVar* var)
{
	peekVar(stack, sp, var);
	
	POP();
}

void actionAdd(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);
	
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);
	
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

void actionAdd2(char* stack, u32* sp, char* str_buffer)
{
	// Peek at types without popping
	u8 type_a = STACK_TOP_TYPE;

	// Move to second value
	u32 sp_second = VAL(u32, &(stack[*sp + 4]));  // Get previous_sp
	u8 type_b = stack[sp_second];  // Type of second value

	// Check if either operand is a string
	if (type_a == ACTION_STACK_VALUE_STRING || type_b == ACTION_STACK_VALUE_STRING) {
		// String concatenation path

		// Convert first operand to string (top of stack - right operand)
		char str_a[17];
		convertString(stack, sp, str_a);
		// Get the string pointer (either str_a if converted, or original if already string)
		const char* str_a_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();

		// Convert second operand to string (second on stack - left operand)
		char str_b[17];
		convertString(stack, sp, str_b);
		// Get the string pointer
		const char* str_b_ptr = (const char*) VAL(u64, &STACK_TOP_VALUE);
		POP();

		// Concatenate (left + right = b + a)
		snprintf(str_buffer, 17, "%s%s", str_b_ptr, str_a_ptr);

		// Push result
		PUSH_STR(str_buffer, strlen(str_buffer));
	} else {
		// Numeric addition path

		// Convert and pop first operand
		convertFloat(stack, sp);
		ActionVar a;
		popVar(stack, sp, &a);

		// Convert and pop second operand
		convertFloat(stack, sp);
		ActionVar b;
		popVar(stack, sp, &b);

		// Perform addition (same logic as actionAdd)
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
}

void actionSubtract(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);
	
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);
	
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

void actionMultiply(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);
	
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);
	
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

void actionDivide(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);
	
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);
	
	if (VAL(float, &a.data.numeric_value) == 0.0f)
	{
		// SWF 4:
		PUSH_STR("#ERROR#", 8);
		
		// SWF 5:
		//~ if (a->value == 0.0f)
		//~ {
			//~ float c = NAN;
		//~ }
		
		//~ else if (a->value > 0.0f)
		//~ {
			//~ float c = INFINITY;
		//~ }
		
		//~ else
		//~ {
			//~ float c = -INFINITY;
		//~ }
	}
	
	else
	{
		if (a.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = VAL(double, &a.data.numeric_value);
			double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
			
			double c = b_val/a_val;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}
		
		else if (b.type == ACTION_STACK_VALUE_F64)
		{
			double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
			double b_val = VAL(double, &b.data.numeric_value);
			
			double c = b_val/a_val;
			PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
		}
		
		else
		{
			float c = VAL(float, &b.data.numeric_value)/VAL(float, &a.data.numeric_value);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
		}
	}
}

void actionModulo(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);

	if (VAL(float, &a.data.numeric_value) == 0.0f)
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

void actionEquals(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);
	
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);
	
	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
		
		float c = b_val == a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
	
	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);
		
		float c = b_val == a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
	
	else
	{
		float c = VAL(float, &b.data.numeric_value) == VAL(float, &a.data.numeric_value) ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionLess(char* stack, u32* sp)
{
	ActionVar a;
	convertFloat(stack, sp);
	popVar(stack, sp, &a);

	ActionVar b;
	convertFloat(stack, sp);
	popVar(stack, sp, &b);

	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);

		float c = b_val < a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);

		float c = b_val < a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else
	{
		float c = VAL(float, &b.data.numeric_value) < VAL(float, &a.data.numeric_value) ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionLess2(char* stack, u32* sp)
{
	ActionVar a;
	convertFloat(stack, sp);
	popVar(stack, sp, &a);

	ActionVar b;
	convertFloat(stack, sp);
	popVar(stack, sp, &b);

	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);

		float c = b_val < a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);

		float c = b_val < a_val ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}

	else
	{
		float c = VAL(float, &b.data.numeric_value) < VAL(float, &a.data.numeric_value) ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionAnd(char* stack, u32* sp)
{
	ActionVar a;
	convertFloat(stack, sp);
	popVar(stack, sp, &a);
	
	ActionVar b;
	convertFloat(stack, sp);
	popVar(stack, sp, &b);
	
	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
		
		float c = b_val != 0.0 && a_val != 0.0 ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);
		
		float c = b_val != 0.0 && a_val != 0.0 ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else
	{
		float c = VAL(float, &b.data.numeric_value) != 0.0f && VAL(float, &a.data.numeric_value) != 0.0f ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionOr(char* stack, u32* sp)
{
	ActionVar a;
	convertFloat(stack, sp);
	popVar(stack, sp, &a);
	
	ActionVar b;
	convertFloat(stack, sp);
	popVar(stack, sp, &b);
	
	if (a.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = VAL(double, &a.data.numeric_value);
		double b_val = b.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &b.data.numeric_value) : VAL(double, &b.data.numeric_value);
		
		float c = b_val != 0.0 || a_val != 0.0 ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else if (b.type == ACTION_STACK_VALUE_F64)
	{
		double a_val = a.type == ACTION_STACK_VALUE_F32 ? (double) VAL(float, &a.data.numeric_value) : VAL(double, &a.data.numeric_value);
		double b_val = VAL(double, &b.data.numeric_value);
		
		float c = b_val != 0.0 || a_val != 0.0 ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &c));
	}
	
	else
	{
		float c = VAL(float, &b.data.numeric_value) != 0.0f || VAL(float, &a.data.numeric_value) != 0.0f ? 1.0f : 0.0f;
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
	}
}

void actionNot(char* stack, u32* sp)
{
	ActionVar v;
	convertFloat(stack, sp);
	popVar(stack, sp, &v);

	float result = v.data.numeric_value == 0.0f ? 1.0f : 0.0f;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u64, &result));
}

void actionToInteger(char* stack, u32* sp)
{
	ActionVar v;
	convertFloat(stack, sp);
	popVar(stack, sp, &v);

	float f = VAL(float, &v.data.numeric_value);

	// Handle special values: NaN and Infinity -> 0
	if (isnan(f) || isinf(f)) {
		f = 0.0f;
	} else {
		// Convert to 32-bit signed integer (truncate toward zero)
		int32_t int_value = (int32_t)f;
		// Convert back to float for pushing
		f = (float)int_value;
	}

	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &f));
}

void actionToNumber(char* stack, u32* sp)
{
	// Convert top of stack to number
	// convertFloat() handles all type conversions:
	// - Number: return as-is
	// - String: parse as number (empty→0, invalid→NaN)
	// - Boolean: true→1, false→0
	// - Null/undefined: NaN
	convertFloat(stack, sp);
	// Value is already converted on stack in-place
}

void actionToString(char* stack, u32* sp, char* str_buffer)
{
	// Convert top of stack to string
	// If already string, this does nothing
	// If float, converts using snprintf with %.15g format
	convertString(stack, sp, str_buffer);
}

void actionStackSwap(char* stack, u32* sp)
{
	// Pop top value (value1)
	ActionVar val1;
	popVar(stack, sp, &val1);

	// Pop second value (value2)
	ActionVar val2;
	popVar(stack, sp, &val2);

	// Push value1 (was on top, now goes to second position)
	pushVar(stack, sp, &val1);

	// Push value2 (was second, now goes to top)
	pushVar(stack, sp, &val2);
}

void actionTargetPath(char* stack, u32* sp, char* str_buffer)
{
	// Get type of value on stack
	u8 type = STACK_TOP_TYPE;

	// Pop value from stack
	ActionVar val;
	popVar(stack, sp, &val);

	// Check if value is an Object (treating as MovieClip placeholder)
	// NOTE: This is a simplified implementation since full MovieClip
	// infrastructure is not yet available. See SWFRecompDocs/prompts/opcode-target-path-0x45.md
	if (type == ACTION_STACK_VALUE_OBJECT) {
		// For Object type, return "_root" as placeholder
		const char* path = "_root";
		int len = 5; // length of "_root"
		strncpy(str_buffer, path, 16);
		str_buffer[len] = '\0';
		PUSH_STR(str_buffer, len);
	} else {
		// Not a valid target, return empty string
		str_buffer[0] = '\0';
		PUSH_STR(str_buffer, 0);
	}
}

int evaluateCondition(char* stack, u32* sp)
{
	ActionVar v;
	convertFloat(stack, sp);
	popVar(stack, sp, &v);

	return v.data.numeric_value != 0.0f;
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

void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str)
{
	ActionVar a;
	convertString(stack, sp, a_str);
	popVar(stack, sp, &a);
	
	ActionVar b;
	convertString(stack, sp, b_str);
	popVar(stack, sp, &b);
	
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
		cmp_result = strcmp((char*) a.data.numeric_value, (char*) b.data.numeric_value);
	}
	
	float result = cmp_result == 0 ? 1.0f : 0.0f;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionStringLength(char* stack, u32* sp, char* v_str)
{
	ActionVar v;
	convertString(stack, sp, v_str);
	popVar(stack, sp, &v);

	float str_size = (float) v.str_size;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &str_size));
}

void actionStringExtract(char* stack, u32* sp, char* str_buffer)
{
	// Pop length
	convertFloat(stack, sp);
	ActionVar length_var;
	popVar(stack, sp, &length_var);
	int length = (int)VAL(float, &length_var.data.numeric_value);

	// Pop index
	convertFloat(stack, sp);
	ActionVar index_var;
	popVar(stack, sp, &index_var);
	int index = (int)VAL(float, &index_var.data.numeric_value);

	// Pop string
	char src_buffer[17];
	convertString(stack, sp, src_buffer);
	ActionVar src_var;
	popVar(stack, sp, &src_var);
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

void actionMbStringLength(char* stack, u32* sp, char* v_str)
{
	// Convert top of stack to string (if it's a number, converts it to string in v_str)
	convertString(stack, sp, v_str);

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

void actionCharToAscii(char* stack, u32* sp)
{
	// Convert top of stack to string
	char str_buffer[17];
	convertString(stack, sp, str_buffer);

	// Pop the string value
	ActionVar v;
	popVar(stack, sp, &v);

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

void actionStringAdd(char* stack, u32* sp, char* a_str, char* b_str)
{
	ActionVar a;
	convertString(stack, sp, a_str);
	peekVar(stack, sp, &a);
	
	ActionVar b;
	convertString(stack, sp, b_str);
	peekVar(stack, &SP_SECOND_TOP, &b);
	
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

void actionNextFrame()
{
	// Advance to the next frame
	extern size_t current_frame;
	extern size_t next_frame;
	extern int manual_next_frame;

	next_frame = current_frame + 1;
	manual_next_frame = 1;
}

void actionTrace(char* stack, u32* sp)
{
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
			printf("%.15g\n", VAL(float, &STACK_TOP_VALUE));
			break;
		}

		case ACTION_STACK_VALUE_F64:
		{
			printf("%.15g\n", VAL(double, &STACK_TOP_VALUE));
			break;
		}

		case ACTION_STACK_VALUE_UNDEFINED:
		{
			printf("undefined\n");
			break;
		}
	}

	fflush(stdout);

	POP();
}

void actionGotoFrame(char* stack, u32* sp, u16 frame)
{
	// Simplified: just log the frame change
	printf("// GotoFrame: %d\n", frame);
	fflush(stdout);

	// TODO: Implement actual frame navigation
	// This requires:
	// - MovieClip structure
	// - Frame management
	// - Timeline playback control
}

void actionEndDrag(char* stack, u32* sp)
{
	#ifndef NO_GRAPHICS
	// Full implementation would:
	// 1. Clear dragging state
	// 2. Stop updating sprite position with mouse
	// if (ctx->dragged_sprite) {
	//     ctx->dragged_sprite = NULL;
	// }
	#else
	// NO_GRAPHICS mode: just log
	#ifdef DEBUG
	printf("[EndDrag]\n");
	#endif
	#endif

	// No stack operations - END_DRAG has no parameters
	(void)stack;  // Suppress unused parameter warning
	(void)sp;     // Suppress unused parameter warning
}

void actionGetURL(char* stack, u32* sp, const char* url, const char* target)
{
	// Simplified implementation: just log the URL request
	printf("// GetURL: %s -> %s\n",
		   url ? url : "(null)",
		   target ? target : "(null)");

	// TODO: Implement actual URL loading
	// This requires:
	// - Browser integration or HTTP client
	// - SWF loader (for _level targets)
	// - Frame/window management
}

void actionGetVariable(char* stack, u32* sp)
{

	// Read variable name info from stack
	u32 string_id = VAL(u32, &stack[*sp + 4]);
	char* var_name = (char*) VAL(u64, &stack[*sp + 16]);
	u32 var_name_len = VAL(u32, &stack[*sp + 8]);

	// Pop variable name
	POP();

	// First check scope chain (innermost to outermost)
	printf("[DEBUG GET_VAR] scope_depth=%u, looking for '%.*s'\n", scope_depth, var_name_len, var_name);
	for (int i = scope_depth - 1; i >= 0; i--)
	{
		if (scope_chain[i] != NULL)
		{
			printf("[DEBUG GET_VAR] Checking scope object %p\n", (void*)scope_chain[i]);
			// Try to find property in this scope object
			ActionVar* prop = getProperty(scope_chain[i], var_name, var_name_len);
			if (prop != NULL)
			{
				// Found in scope chain - push its value
				printf("[DEBUG GET_VAR] Found! type=%d\n", prop->type);
				PUSH_VAR(prop);
				return;
			}
			else
			{
				printf("[DEBUG GET_VAR] Not found in this object\n");
			}
		}
	}

	// Not found in scope chain - check global variables
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
		// Variable not found - push empty string
		PUSH_STR("", 0);
		return;
	}

	// Push variable value to stack
	PUSH_VAR(var);
}

void actionSetVariable(char* stack, u32* sp)
{
	// Stack layout: [value] [name] <- sp
	// We need value at top, name at second

	u32 value_sp = *sp;
	u32 var_name_sp = SP_SECOND_TOP;

	// Debug: check what's on stack
	ActionStackValueType value_type = stack[value_sp];
	printf("[DEBUG SET_VAR] Setting variable, value type=%d\n", value_type);

	// Read variable name info
	u32 string_id = VAL(u32, &stack[var_name_sp + 4]);
	char* var_name = (char*) VAL(u64, &stack[var_name_sp + 16]);
	u32 var_name_len = VAL(u32, &stack[var_name_sp + 8]);

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
				// We need to convert the value at value_sp to an ActionVar
				ActionVar value_var;
				peekVar(stack, sp, &value_var);
				setProperty(scope_chain[i], var_name, var_name_len, &value_var);

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
	setVariableWithValue(var, stack, value_sp);

	// Pop both value and name
	POP_2();
}

void actionGetProperty(char* stack, u32* sp)
{
	// Pop property index
	convertFloat(stack, sp);
	ActionVar index_var;
	popVar(stack, sp, &index_var);
	int prop_index = (int) VAL(float, &index_var.data.numeric_value);

	// Pop target path
	convertString(stack, sp, NULL);
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
		case 13: // _name
			str_value = mc ? mc->name : "";
			is_string = 1;
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

void actionRandomNumber(char* stack, u32* sp)
{
	// Pop maximum value
	convertFloat(stack, sp);
	ActionVar max_var;
	popVar(stack, sp, &max_var);
	int max = (int) VAL(float, &max_var.data.numeric_value);

	// Generate random number using avmplus-compatible RNG
	// This matches Flash Player's exact behavior for speedrunners
	int random_val = Random(max, &global_random_state);

	// Push result as float
	float result = (float) random_val;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionAsciiToChar(char* stack, u32* sp, char* str_buffer)
{
	// Convert top of stack to number
	convertFloat(stack, sp);

	// Pop the numeric value
	ActionVar a;
	popVar(stack, sp, &a);

	// Get integer code (truncate decimal)
	float val = VAL(float, &a.data.numeric_value);
	int code = (int)val;

	// Handle out-of-range values (wrap to 0-255)
	code = code & 0xFF;

	// Create single-character string
	str_buffer[0] = (char)code;
	str_buffer[1] = '\0';

	// Push result string
	PUSH_STR(str_buffer, 1);
}

void actionMbCharToAscii(char* stack, u32* sp, char* str_buffer)
{
	// Convert top of stack to string
	convertString(stack, sp, str_buffer);

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

void actionGetTime(char* stack, u32* sp)
{
	u32 delta_ms = get_elapsed_ms() - start_time;
	float delta_ms_f32 = (float) delta_ms;

	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &delta_ms_f32));
}

void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer)
{
	// Convert top of stack to number
	convertFloat(stack, sp);

	// Pop the numeric value
	ActionVar a;
	popVar(stack, sp, &a);

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

void actionTypeof(char* stack, u32* sp, char* str_buffer)
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

		case ACTION_STACK_VALUE_OBJECT:
			type_str = "object";
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

void actionCastOp(char* stack, u32* sp)
{
	// CastOp implementation (ActionScript 2.0 cast operator)
	// Pops object to cast, pops constructor, checks if object is instance of constructor
	// Returns object if cast succeeds, undefined/null if it fails

	// Pop object to cast
	u8 obj_type = STACK_TOP_TYPE;
	u64 obj_value = STACK_TOP_VALUE;
	POP();

	// Pop constructor function
	u8 ctor_type = STACK_TOP_TYPE;
	u64 ctor_value = STACK_TOP_VALUE;
	POP();

	// SIMPLIFIED IMPLEMENTATION:
	// Since prototype chain and instanceof infrastructure is not yet implemented,
	// this is a basic version that only checks if the object is an object type.
	// TODO: Implement full instanceof checking with prototype chain walking
	//       and interface implementation checking when that infrastructure is available.

	// For now: if object is an OBJECT type and non-null, assume cast succeeds
	// This will need to be enhanced with actual instanceof logic later
	if (obj_type == ACTION_STACK_VALUE_OBJECT && obj_value != 0)
	{
		// Cast succeeds - push the object back
		PUSH(ACTION_STACK_VALUE_OBJECT, obj_value);
	}
	else
	{
		// Cast fails - push undefined (represents null in ActionScript)
		PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	}
}

void actionDuplicate(char* stack, u32* sp)
{
	// Get the type of the top stack entry
	u8 type = STACK_TOP_TYPE;

	// Handle different types appropriately
	if (type == ACTION_STACK_VALUE_STRING)
	{
		// For strings, we need to copy both the pointer and the length
		const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
		u32 len = STACK_TOP_N;  // Length is stored at offset +8
		u32 id = VAL(u32, &stack[*sp + 12]);  // String ID is at offset +12

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

void actionReturn(char* stack, u32* sp)
{
	// The return value is already at the top of the stack.
	// The generated C code includes a "return;" statement that exits
	// the function, leaving the value on the stack for the caller.
	// No operation needed here - the translation layer handles
	// the actual return via C return statement.
}

void actionIncrement(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

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

void actionDecrement(char* stack, u32* sp)
{
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

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

void actionBitAnd(char* stack, u32* sp)
{

	// Convert and pop second operand (a)
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

	// Convert and pop first operand (b)
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);

	// Convert to 32-bit signed integers (truncate, don't round)
	int32_t a_int = (int32_t)VAL(float, &a.data.numeric_value);
	int32_t b_int = (int32_t)VAL(float, &b.data.numeric_value);

	// Perform bitwise AND
	int32_t result = b_int & a_int;

	// Push result as float (ActionScript stores all numbers as float)
	float result_f = (float)result;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}

void actionBitOr(char* stack, u32* sp)
{

	// Convert and pop second operand (a)
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

	// Convert and pop first operand (b)
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);

	// Convert to 32-bit signed integers (truncate, don't round)
	int32_t a_int = (int32_t)VAL(float, &a.data.numeric_value);
	int32_t b_int = (int32_t)VAL(float, &b.data.numeric_value);

	// Perform bitwise OR
	int32_t result = b_int | a_int;

	// Push result as float (ActionScript stores all numbers as float)
	float result_f = (float)result;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}

void actionBitXor(char* stack, u32* sp)
{

	// Convert and pop second operand (a)
	convertFloat(stack, sp);
	ActionVar a;
	popVar(stack, sp, &a);

	// Convert and pop first operand (b)
	convertFloat(stack, sp);
	ActionVar b;
	popVar(stack, sp, &b);

	// Convert to 32-bit signed integers (truncate, don't round)
	int32_t a_int = (int32_t)VAL(float, &a.data.numeric_value);
	int32_t b_int = (int32_t)VAL(float, &b.data.numeric_value);

	// Perform bitwise XOR
	int32_t result = b_int ^ a_int;

	// Push result as float (ActionScript stores all numbers as float)
	float result_f = (float)result;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}

void actionBitLShift(char* stack, u32* sp)
{

	// Pop shift count (first argument)
	convertFloat(stack, sp);
	ActionVar shift_count_var;
	popVar(stack, sp, &shift_count_var);

	// Pop value to shift (second argument)
	convertFloat(stack, sp);
	ActionVar value_var;
	popVar(stack, sp, &value_var);

	// Convert to 32-bit signed integers (truncate, don't round)
	int32_t shift_count = (int32_t)VAL(float, &shift_count_var.data.numeric_value);
	int32_t value = (int32_t)VAL(float, &value_var.data.numeric_value);

	// Mask shift count to 5 bits (0-31 range)
	shift_count = shift_count & 0x1F;

	// Perform left shift
	int32_t result = value << shift_count;

	// Push result as float (ActionScript stores all numbers as float)
	float result_f = (float)result;
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}

void actionBitRShift(char* stack, u32* sp)
{

	// Pop shift count (first argument)
	convertFloat(stack, sp);
	ActionVar shift_count_var;
	popVar(stack, sp, &shift_count_var);

	// Pop value to shift (second argument)
	convertFloat(stack, sp);
	ActionVar value_var;
	popVar(stack, sp, &value_var);

	// Convert to 32-bit signed integers
	int32_t shift_count = (int32_t)VAL(float, &shift_count_var.data.numeric_value);
	int32_t value = (int32_t)VAL(float, &value_var.data.numeric_value);

	// Mask shift count to 5 bits (0-31 range)
	shift_count = shift_count & 0x1F;

	// Perform arithmetic right shift (sign-extending)
	// In C, >> on signed int is arithmetic shift
	int32_t result = value >> shift_count;

	// Convert result back to float for stack
	float result_f = (float)result;

	// Push result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}

void actionBitURShift(char* stack, u32* sp)
{

	// Pop shift count (first argument)
	convertFloat(stack, sp);
	ActionVar shift_count_var;
	popVar(stack, sp, &shift_count_var);

	// Pop value to shift (second argument)
	convertFloat(stack, sp);
	ActionVar value_var;
	popVar(stack, sp, &value_var);

	// Convert to integers
	int32_t shift_count = (int32_t)VAL(float, &shift_count_var.data.numeric_value);

	// IMPORTANT: Use UNSIGNED for logical shift
	uint32_t value = (uint32_t)((int32_t)VAL(float, &value_var.data.numeric_value));

	// Mask shift count to 5 bits (0-31 range)
	shift_count = shift_count & 0x1F;

	// Perform logical (unsigned) right shift
	// In C, >> on unsigned int is logical shift (zero-fill)
	uint32_t result = value >> shift_count;

	// Convert result back to float for stack
	// Cast through double to preserve full 32-bit unsigned value
	float result_float = (float)((double)result);

	// Push result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}

void actionStrictEquals(char* stack, u32* sp)
{
	// Pop first argument (no type conversion - strict equality!)
	ActionVar a;
	popVar(stack, sp, &a);

	// Pop second argument (no type conversion - strict equality!)
	ActionVar b;
	popVar(stack, sp, &b);

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
				double a_val = VAL(double, &a.data.numeric_value);
				double b_val = VAL(double, &b.data.numeric_value);
				result = (a_val == b_val) ? 1.0f : 0.0f;
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
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
		}
	}
	// else: different types, result remains 0.0f (false)

	// Push boolean result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionEquals2(char* stack, u32* sp)
{
	// Pop first argument (arg1)
	ActionVar a;
	popVar(stack, sp, &a);

	// Pop second argument (arg2)
	ActionVar b;
	popVar(stack, sp, &b);

	float result = 0.0f;

	// ECMA-262 equality algorithm
	// 1. If types are the same, use strict equality
	if (a.type == b.type)
	{
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
				double a_val = VAL(double, &a.data.numeric_value);
				double b_val = VAL(double, &b.data.numeric_value);
				result = (a_val == b_val) ? 1.0f : 0.0f;
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

			case ACTION_STACK_VALUE_UNDEFINED:
			{
				// undefined == undefined is true
				result = 1.0f;
				break;
			}

			default:
				// For other types (OBJECT, etc.), compare raw values
				result = (a.data.numeric_value == b.data.numeric_value) ? 1.0f : 0.0f;
				break;
		}
	}
	// 2. Number vs String: convert string to number
	else if ((a.type == ACTION_STACK_VALUE_F32 || a.type == ACTION_STACK_VALUE_F64) &&
	         b.type == ACTION_STACK_VALUE_STRING)
	{
		const char* str_b = (const char*) b.data.numeric_value;
		float b_num = (str_b != NULL) ? (float)atof(str_b) : 0.0f;
		float a_val = (a.type == ACTION_STACK_VALUE_F32) ?
		              VAL(float, &a.data.numeric_value) :
		              (float)VAL(double, &a.data.numeric_value);
		result = (a_val == b_num) ? 1.0f : 0.0f;
	}
	else if (a.type == ACTION_STACK_VALUE_STRING &&
	         (b.type == ACTION_STACK_VALUE_F32 || b.type == ACTION_STACK_VALUE_F64))
	{
		const char* str_a = (const char*) a.data.numeric_value;
		float a_num = (str_a != NULL) ? (float)atof(str_a) : 0.0f;
		float b_val = (b.type == ACTION_STACK_VALUE_F32) ?
		              VAL(float, &b.data.numeric_value) :
		              (float)VAL(double, &b.data.numeric_value);
		result = (a_num == b_val) ? 1.0f : 0.0f;
	}
	// 3. Different types not covered above: false
	// (This handles cases like object vs number, etc.)

	// Push boolean result (1.0 = true, 0.0 = false)
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionStringGreater(char* stack, u32* sp)
{

	// Get first string (arg1)
	ActionVar a;
	popVar(stack, sp, &a);
	const char* str_a = (const char*) a.data.numeric_value;

	// Get second string (arg2)
	ActionVar b;
	popVar(stack, sp, &b);
	const char* str_b = (const char*) b.data.numeric_value;

	// Compare: b > a (using strcmp)
	// strcmp returns positive if str_b > str_a
	float result = (strcmp(str_b, str_a) > 0) ? 1.0f : 0.0f;

	// Push boolean result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

// ==================================================================
// Inheritance (EXTENDS opcode)
// ==================================================================

void actionExtends(char* stack, u32* sp)
{
	// Pop superclass constructor from stack
	ActionVar superclass;
	popVar(stack, sp, &superclass);

	// Pop subclass constructor from stack
	ActionVar subclass;
	popVar(stack, sp, &subclass);

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
	ASObject* new_proto = allocObject(0);
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
		setProperty(new_proto, "__proto__", 9, super_proto_var);
	}

	// Set constructor property to superclass
	setProperty(new_proto, "constructor", 11, &superclass);

	// Set subclass prototype to new object
	ActionVar new_proto_var;
	new_proto_var.type = ACTION_STACK_VALUE_OBJECT;
	new_proto_var.data.numeric_value = (u64) new_proto;
	new_proto_var.str_size = 0;

	setProperty(sub_func, "prototype", 9, &new_proto_var);

	// Release our reference to new_proto
	// (setProperty retained it when setting as prototype)
	releaseObject(new_proto);

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

void actionStoreRegister(char* stack, u32* sp, u8 register_num)
{
	// Validate register number
	if (register_num >= MAX_REGISTERS) {
		return;
	}

	// Peek the top of stack (don't pop!)
	ActionVar value;
	peekVar(stack, sp, &value);

	// Store value in register
	g_registers[register_num] = value;
}

void actionPushRegister(char* stack, u32* sp, u8 register_num)
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

void actionStringLess(char* stack, u32* sp)
{
	// Get first string (arg1)
	ActionVar a;
	popVar(stack, sp, &a);
	const char* str_a = (const char*) a.data.numeric_value;

	// Get second string (arg2)
	ActionVar b;
	popVar(stack, sp, &b);
	const char* str_b = (const char*) b.data.numeric_value;

	// Compare: b < a (using strcmp)
	// strcmp returns negative if str_b < str_a
	float result = (strcmp(str_b, str_a) < 0) ? 1.0f : 0.0f;

	// Push boolean result
	PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}

void actionImplementsOp(char* stack, u32* sp)
{
	// ActionImplementsOp implements the ActionScript "implements" keyword
	// It specifies the interfaces that a class implements, for use by instanceof and CastOp

	// Step 1: Pop constructor function (the class) from stack
	ActionVar constructor_var;
	popVar(stack, sp, &constructor_var);

	// Validate that it's an object
	if (constructor_var.type != ACTION_STACK_VALUE_OBJECT)
	{
		fprintf(stderr, "ERROR: actionImplementsOp - constructor is not an object\n");
		return;
	}

	ASObject* constructor = (ASObject*) constructor_var.data.numeric_value;

	// Step 2: Pop count of interfaces from stack
	ActionVar count_var;
	popVar(stack, sp, &count_var);

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
			popVar(stack, sp, &iface_var);

			if (iface_var.type != ACTION_STACK_VALUE_OBJECT)
			{
				fprintf(stderr, "ERROR: actionImplementsOp - interface %u is not an object\n", i);
				// Clean up allocated interfaces
				for (u32 j = 0; j < i; j++)
				{
					releaseObject(interfaces[j]);
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
	setInterfaceList(constructor, interfaces, interface_count);

#ifdef DEBUG
	printf("[DEBUG] actionImplementsOp: constructor=%p, interface_count=%u\n",
		(void*)constructor, interface_count);
#endif

	// Note: No values pushed back on stack (ImplementsOp has no return value)
}

void actionCall(char* stack, u32* sp)
{
	// Pop frame identifier (string or number)
	ActionVar frame_var;
	popVar(stack, sp, &frame_var);

	// Simplified implementation: log the call
	// TODO: Actually execute frame actions when frame infrastructure is ready

	int frame_num = -1;
	const char* frame_id = NULL;

	// Try to interpret as frame number or string
	if (frame_var.type == ACTION_STACK_VALUE_F32) {
		frame_num = (int) frame_var.data.numeric_value;
		printf("// Call frame %d\n", frame_num);
	} else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
		frame_id = (const char*) frame_var.data.numeric_value;
		// Try to parse as number
		char* endptr;
		long num = strtol(frame_id, &endptr, 10);
		if (*endptr == '\0') {
			// It's a numeric string
			frame_num = (int) num;
			printf("// Call frame %d\n", frame_num);
		} else {
			// It's a frame label
			printf("// Call frame label: %s\n", frame_id);
		}
	}

	// In a full implementation, this would:
	// 1. Look up the frame by number or label
	// 2. Execute the frame's actions
	// 3. Return to the current frame when done
}

void actionGetURL2(char* stack, u32* sp, u8 send_vars_method, u8 load_target_flag, u8 load_variables_flag)
{
	// Pop target from stack
	char target_str[17];
	ActionVar target_var;
	convertString(stack, sp, target_str);
	popVar(stack, sp, &target_var);
	const char* target = (target_var.type == ACTION_STACK_VALUE_STRING) ?
						 (const char*)target_var.data.numeric_value : "";

	// Pop URL from stack
	char url_str[17];
	ActionVar url_var;
	convertString(stack, sp, url_str);
	popVar(stack, sp, &url_var);
	const char* url = (url_var.type == ACTION_STACK_VALUE_STRING) ?
					  (const char*)url_var.data.numeric_value : "";

	// Determine HTTP method
	const char* method = "NONE";
	if (send_vars_method == 1) method = "GET";
	else if (send_vars_method == 2) method = "POST";

	// Determine operation type
	bool is_sprite = (load_target_flag == 1);
	bool load_vars = (load_variables_flag == 1);

	// Log the operation (simplified implementation)
	if (is_sprite) {
		// Load into sprite/movieclip
		if (load_vars) {
			// Load variables into sprite
			printf("// LoadVariables: %s -> %s (method: %s)\n", url, target, method);
		} else {
			// Load SWF into sprite
			printf("// LoadMovie: %s -> %s\n", url, target);
		}
	} else {
		// Load into browser window
		if (load_vars) {
			// Load variables into timeline
			printf("// LoadVariables: %s (method: %s)\n", url, method);
		} else {
			// Open URL in browser
			printf("// OpenURL: %s (target: %s", url, target);
			if (send_vars_method != 0) {
				printf(", method: %s", method);
			}
			printf(")\n");
		}
	}

	// TODO: Implement actual URL loading functionality
	// - For browser windows: platform-specific browser launch
	// - For variables: HTTP request + parse response
	// - For movies: download and load SWF file
}

void actionInitArray(char* stack, u32* sp)
{
	// 1. Pop array element count
	convertFloat(stack, sp);
	ActionVar count_var;
	popVar(stack, sp, &count_var);
	u32 num_elements = (u32) VAL(float, &count_var.data.numeric_value);

	// 2. Allocate array
	ASArray* arr = allocArray(num_elements);
	if (!arr) {
		// Handle allocation failure - push empty array or null
		PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &(float){0.0f}));
		return;
	}
	arr->length = num_elements;

	// 3. Pop elements in reverse order and populate array
	// Elements are on stack in reverse order: [..., elem_N, elem_N-1, ..., elem_1]
	// We need to pop them and store in array as: [elem_1, elem_2, ..., elem_N]
	for (int i = (int)num_elements - 1; i >= 0; i--) {
		ActionVar elem;
		popVar(stack, sp, &elem);
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

void actionSetMember(char* stack, u32* sp)
{
	// Stack layout (from top to bottom):
	// 1. value (the value to assign)
	// 2. property_name (the name of the property)
	// 3. object (the object to set the property on)

	// Pop the value to assign
	ActionVar value_var;
	popVar(stack, sp, &value_var);

	// Pop the property name
	// The property name should be a string on the stack
	ActionVar prop_name_var;
	popVar(stack, sp, &prop_name_var);

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
	popVar(stack, sp, &obj_var);

	// Check if the object is actually an object type
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;
		if (obj != NULL)
		{
			// Set the property on the object
			setProperty(obj, prop_name, prop_name_len, &value_var);
		}
	}
	// If it's not an object type, we silently ignore the operation
	// (Flash behavior for setting properties on non-objects)
}

void actionInitObject(char* stack, u32* sp)
{
	// Step 1: Pop property count from stack
	convertFloat(stack, sp);
	ActionVar count_var;
	popVar(stack, sp, &count_var);
	u32 num_props = (u32) VAL(float, &count_var.data.numeric_value);

#ifdef DEBUG
	printf("[DEBUG] actionInitObject: creating object with %u properties\n", num_props);
#endif

	// Step 2: Allocate object with the specified number of properties
	ASObject* obj = allocObject(num_props);
	if (obj == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate object in actionInitObject\n");
		// Push null/undefined object on error
		PUSH(ACTION_STACK_VALUE_OBJECT, 0);
		return;
	}

	// Step 3: Pop property name/value pairs from stack
	// Properties are in reverse order: rightmost property is on top of stack
	// Stack order is: [..., value1, name1, ..., valueN, nameN, count]
	// So after popping count, top of stack is nameN
	for (u32 i = 0; i < num_props; i++)
	{
		// Pop property name first (it's on top)
		ActionVar name_var;
		popVar(stack, sp, &name_var);

		// Pop property value (it's below the name)
		ActionVar value;
		popVar(stack, sp, &value);
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
		setProperty(obj, name, name_length, &value);
	}

	// Step 4: Push object reference to stack
	// The object has refcount = 1 from allocation
	PUSH(ACTION_STACK_VALUE_OBJECT, (u64) obj);

#ifdef DEBUG
	printf("[DEBUG] actionInitObject: pushed object %p to stack\n", (void*)obj);
#endif
}

// Helper function to push undefined value
static void pushUndefined(char* stack, u32* sp)
{
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
}

void actionGetMember(char* stack, u32* sp)
{
	// 1. Convert and pop property name (top of stack)
	char str_buffer[17];
	convertString(stack, sp, str_buffer);
	const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 prop_name_len = STACK_TOP_N;
	POP();

	// 2. Pop object (second on stack)
	ActionVar obj_var;
	popVar(stack, sp, &obj_var);

	// 3. Handle different object types
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		// Handle AS object
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj == NULL)
		{
			pushUndefined(stack, sp);
			return;
		}

		// Look up property
		ActionVar* prop = getProperty(obj, prop_name, prop_name_len);

		if (prop != NULL)
		{
			// Property found - push its value
			pushVar(stack, sp, prop);
		}
		else
		{
			// Property not found - push undefined
			pushUndefined(stack, sp);
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

			// Push length as float
			float len = (float) strlen(str);
			PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &len));
		}
		else
		{
			// Other properties don't exist on strings
			pushUndefined(stack, sp);
		}
	}
	else
	{
		// Other primitive types (number, undefined, etc.) - push undefined
		pushUndefined(stack, sp);
	}
}

void actionNewObject(char* stack, u32* sp)
{
	// 1. Pop constructor name (string)
	ActionVar ctor_name_var;
	popVar(stack, sp, &ctor_name_var);
	const char* ctor_name;
	if (ctor_name_var.type == ACTION_STACK_VALUE_STRING)
	{
		ctor_name = ctor_name_var.data.string_data.owns_memory ?
			ctor_name_var.data.string_data.heap_ptr :
			(const char*) ctor_name_var.data.numeric_value;
	}
	else
	{
		// Fallback if not a string (shouldn't happen in normal cases)
		ctor_name = "Object";
	}

	// 2. Pop number of arguments
	convertFloat(stack, sp);
	ActionVar num_args_var;
	popVar(stack, sp, &num_args_var);
	u32 num_args = (u32) VAL(float, &num_args_var.data.numeric_value);

	// 3. Pop arguments from stack (store them temporarily)
	// Limit to 16 arguments for simplicity
	ActionVar args[16];
	if (num_args > 16)
	{
		num_args = 16;
	}

	// Pop arguments in reverse order (first arg is deepest on stack)
	for (int i = (int)num_args - 1; i >= 0; i--)
	{
		popVar(stack, sp, &args[i]);
	}

	// 4. Create new object based on constructor name
	void* new_obj = NULL;

	if (strcmp(ctor_name, "Array") == 0)
	{
		// Handle Array constructor
		if (num_args == 0)
		{
			// new Array() - empty array
			ASArray* arr = allocArray(4);
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
			ASArray* arr = allocArray(length > 0 ? length : 4);
			arr->length = length;
			new_obj = arr;
		}
		else
		{
			// new Array(elem1, elem2, ...) - array with elements
			ASArray* arr = allocArray(num_args);
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
		PUSH(ACTION_STACK_VALUE_ARRAY, VAL(u64, new_obj));
	}
	else if (strcmp(ctor_name, "Object") == 0)
	{
		// Handle Object constructor
		// Create empty object with initial capacity
		ASObject* obj = allocObject(8);
		new_obj = obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
	else if (strcmp(ctor_name, "Date") == 0)
	{
		// Handle Date constructor (simplified)
		// In a full implementation, this would parse date arguments
		// For now, just create an empty object
		ASObject* date = allocObject(4);
		new_obj = date;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
	else
	{
		// Unknown constructor - create generic object
		// In a full implementation, this would try to call user-defined constructor
		ASObject* obj = allocObject(8);
		new_obj = obj;
		PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
	}
}

void actionSetProperty(char* stack, u32* sp)
{
	// Stack layout: [target_path] [property_index] [value] <- sp
	// Pop in reverse order: value, index, target

	// 1. Pop value
	ActionVar value_var;
	popVar(stack, sp, &value_var);

	// 2. Pop property index
	convertFloat(stack, sp);
	ActionVar index_var;
	popVar(stack, sp, &index_var);
	int prop_index = (int) VAL(float, &index_var.data.numeric_value);

	// 3. Pop target path
	convertString(stack, sp, NULL);
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

void actionCloneSprite(char* stack, u32* sp)
{
	// Stack layout: [target_name] [source_name] [depth] <- sp
	// Pop in reverse order: depth, source, target

	// Pop depth
	convertFloat(stack, sp);
	ActionVar depth;
	popVar(stack, sp, &depth);

	// Pop source sprite name
	ActionVar source;
	popVar(stack, sp, &source);
	const char* source_name = (const char*) source.data.numeric_value;

	// Pop target sprite name
	ActionVar target;
	popVar(stack, sp, &target);
	const char* target_name = (const char*) target.data.numeric_value;

	#ifndef NO_GRAPHICS
	// Full implementation would:
	// 1. Find source MovieClip in display list
	// 2. Create deep copy of sprite and its children
	// 3. Add to display list at specified depth
	// 4. Assign new name
	cloneMovieClip(source_name, target_name, (int)VAL(float, &depth.data.numeric_value));
	#else
	// NO_GRAPHICS mode: just log the operation
	#ifdef DEBUG
	printf("[CloneSprite] %s -> %s (depth %d)\n",
	       source_name, target_name, (int)VAL(float, &depth.data.numeric_value));
	#endif
	#endif
}

// ==================================================================
// WITH Statement Implementation
// ==================================================================

void actionWithStart(char* stack, u32* sp)
{
	// Pop object from stack
	ActionVar obj_var;
	popVar(stack, sp, &obj_var);

	printf("[DEBUG] actionWithStart: popped type=%d\n", obj_var.type);

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

void actionWithEnd(char* stack, u32* sp)
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

void actionDefineFunction(char* stack, u32* sp, const char* name, void (*func)(char*, u32*), u32 param_count)
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

void actionDefineFunction2(char* stack, u32* sp, const char* name, Function2Ptr func, u32 param_count, u8 register_count, u16 flags)
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

void actionCallFunction(char* stack, u32* sp, char* str_buffer)
{
	// 1. Pop function name (string) from stack
	char func_name_buffer[17];
	convertString(stack, sp, func_name_buffer);
	const char* func_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 func_name_len = STACK_TOP_N;
	POP();

	// 2. Pop number of arguments
	ActionVar num_args_var;
	popVar(stack, sp, &num_args_var);
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
		args = (ActionVar*) malloc(sizeof(ActionVar) * num_args);
		for (u32 i = 0; i < num_args; i++)
		{
			popVar(stack, sp, &args[num_args - 1 - i]);
		}
	}

	// 4. Look up and invoke the function
	ASFunction* func = lookupFunctionByName(func_name, func_name_len);

	if (func != NULL)
	{
		if (func->function_type == 2)
		{
			// DefineFunction2 with registers and this context
			ActionVar* registers = NULL;
			if (func->register_count > 0) {
				registers = (ActionVar*) calloc(func->register_count, sizeof(ActionVar));
			}

			ActionVar result = func->advanced_func(stack, sp, args, num_args, registers, NULL);

			if (registers != NULL) free(registers);
			if (args != NULL) free(args);

			pushVar(stack, sp, &result);
		}
		else
		{
			// Simple DefineFunction - not yet supported for invocation
			// Would need to handle differently since simple_func doesn't return a value
			if (args != NULL) free(args);
			pushUndefined(stack, sp);
		}
	}
	else
	{
		// Function not found - push undefined
		if (args != NULL) free(args);
		pushUndefined(stack, sp);
	}
}

void actionCallMethod(char* stack, u32* sp, char* str_buffer)
{
	// 1. Pop method name (string) from stack
	char method_name_buffer[17];
	convertString(stack, sp, method_name_buffer);
	const char* method_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
	u32 method_name_len = STACK_TOP_N;
	POP();

	// 2. Pop object (receiver/this) from stack
	ActionVar obj_var;
	popVar(stack, sp, &obj_var);

	// 3. Pop number of arguments
	ActionVar num_args_var;
	popVar(stack, sp, &num_args_var);
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
		args = (ActionVar*) malloc(sizeof(ActionVar) * num_args);
		for (u32 i = 0; i < num_args; i++)
		{
			popVar(stack, sp, &args[num_args - 1 - i]);
		}
	}

	// 5. Look up the method on the object and invoke it
	if (obj_var.type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* obj = (ASObject*) obj_var.data.numeric_value;

		if (obj == NULL)
		{
			// Null object - push undefined
			if (args != NULL) free(args);
			pushUndefined(stack, sp);
			return;
		}

		// Look up the method property
		ActionVar* method_prop = getProperty(obj, method_name, method_name_len);

		if (method_prop != NULL && method_prop->type == ACTION_STACK_VALUE_FUNCTION)
		{
			// Get function object
			ASFunction* func = lookupFunctionFromVar(method_prop);

			if (func != NULL && func->function_type == 2)
			{
				// Invoke DefineFunction2 with 'this' binding
				ActionVar* registers = NULL;
				if (func->register_count > 0) {
					registers = (ActionVar*) calloc(func->register_count, sizeof(ActionVar));
				}

				ActionVar result = func->advanced_func(stack, sp, args, num_args, registers, (void*) obj);

				if (registers != NULL) free(registers);
				if (args != NULL) free(args);

				pushVar(stack, sp, &result);
			}
			else
			{
				// Simple function or invalid - push undefined
				if (args != NULL) free(args);
				pushUndefined(stack, sp);
			}
		}
		else
		{
			// Method not found or not a function - push undefined
			if (args != NULL) free(args);
			pushUndefined(stack, sp);
			return;
		}
	}
	else
	{
		// Not an object - push undefined
		if (args != NULL) free(args);
		pushUndefined(stack, sp);
		return;
	}
}
