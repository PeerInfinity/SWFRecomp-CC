#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <recomp.h>
#include <utils.h>

u32 start_time;

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
	}
	
	fflush(stdout);

	POP();
}

void actionGetVariable(char* stack, u32* sp)
{

	// Read variable name info from stack
	u32 string_id = VAL(u32, &stack[*sp + 4]);
	char* var_name = (char*) VAL(u64, &stack[*sp + 16]);
	u32 var_name_len = VAL(u32, &stack[*sp + 8]);

	// Pop variable name
	POP();

	// Get variable (fast path for constant strings)
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

	// Read variable name info
	u32 string_id = VAL(u32, &stack[var_name_sp + 4]);
	char* var_name = (char*) VAL(u64, &stack[var_name_sp + 16]);
	u32 var_name_len = VAL(u32, &stack[var_name_sp + 8]);

	// Get variable (fast path for constant strings)
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

// MovieClip structure for GET_PROPERTY opcode
typedef struct {
	float x, y;
	float xscale, yscale;
	float rotation;
	float alpha;
	float width, height;
	int visible;
	int currentframe;
	int totalframes;
	const char* name;
	const char* target;
} MovieClip;

// Get MovieClip by target path (simplified implementation)
static MovieClip* getMovieClipByTarget(const char* target) {
	// For initial implementation, return a default _root MovieClip
	static MovieClip root = {
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
		.name = "",
		.target = ""
	};

	if (strcmp(target, "") == 0 || strcmp(target, "_root") == 0 || strcmp(target, "/") == 0) {
		return &root;
	}
	return NULL;
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
