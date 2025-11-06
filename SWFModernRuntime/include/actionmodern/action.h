#pragma once

#include <variables.h>
#include <stackvalue.h>

#define PUSH(t, v) \
	do { \
		u32 oldSP = *sp; \
		*sp -= 4 + 4 + 8 + 8; \
		*sp &= ~7; \
		stack[*sp] = t; \
		VAL(u32, &stack[*sp + 4]) = oldSP; \
		VAL(u64, &stack[*sp + 16]) = v; \
	} while(0)

// Push string with ID (for constant strings from compiler)
#define PUSH_STR_ID(v, n, id) \
	do { \
		u32 oldSP = *sp; \
		*sp -= 4 + 4 + 8 + 8; \
		*sp &= ~7; \
		stack[*sp] = ACTION_STACK_VALUE_STRING; \
		VAL(u32, &stack[*sp + 4]) = oldSP; \
		VAL(u32, &stack[*sp + 8]) = n; \
		VAL(u32, &stack[*sp + 12]) = id; \
		VAL(char*, &stack[*sp + 16]) = v; \
	} while(0)

// Push string without ID (for dynamic strings, ID = 0)
#define PUSH_STR(v, n) PUSH_STR_ID(v, n, 0)

#define PUSH_STR_LIST(n, size) \
	do { \
		u32 oldSP = VAL(u32, &stack[SP_SECOND_TOP + 4]); \
		*sp -= (u32) (4 + 4 + 8 + size); \
		*sp &= ~7; \
		stack[*sp] = ACTION_STACK_VALUE_STR_LIST; \
		VAL(u32, &stack[*sp + 4]) = oldSP; \
		VAL(u32, &stack[*sp + 8]) = n; \
	} while(0)

#define PUSH_VAR(p) pushVar(stack, sp, p);

#define POP() \
	*sp = VAL(u32, &stack[*sp + 4]); \

#define POP_2() \
	POP(); \
	POP(); \

#define STACK_TOP_TYPE stack[*sp]
#define STACK_TOP_N VAL(u32, &stack[*sp + 8])
#define STACK_TOP_VALUE VAL(u64, &stack[*sp + 16])

#define SP_SECOND_TOP VAL(u32, &stack[*sp + 4])
#define STACK_SECOND_TOP_TYPE stack[SP_SECOND_TOP]
#define STACK_SECOND_TOP_N VAL(u32, &stack[SP_SECOND_TOP + 8])
#define STACK_SECOND_TOP_VALUE VAL(u64, &stack[SP_SECOND_TOP + 16])

#define SET_VAR(p, t, n, v) setVariableWithValue(p, stack, *sp)

#define VAL(type, x) *((type*) x)

#define INITIAL_STACK_SIZE 8388608  // 8 MB
#define INITIAL_SP INITIAL_STACK_SIZE

extern ActionVar* temp_val;

void initTime();

void pushVar(char* stack, u32* sp, ActionVar* p);

void actionAdd(char* stack, u32* sp);
void actionAdd2(char* stack, u32* sp, char* str_buffer);
void actionSubtract(char* stack, u32* sp);
void actionMultiply(char* stack, u32* sp);
void actionDivide(char* stack, u32* sp);
void actionModulo(char* stack, u32* sp);
void actionEquals(char* stack, u32* sp);
void actionLess(char* stack, u32* sp);
void actionLess2(char* stack, u32* sp);
void actionAnd(char* stack, u32* sp);
void actionOr(char* stack, u32* sp);
void actionNot(char* stack, u32* sp);
void actionToInteger(char* stack, u32* sp);
void actionToNumber(char* stack, u32* sp);
void actionToString(char* stack, u32* sp, char* str_buffer);
void actionStackSwap(char* stack, u32* sp);
void actionTargetPath(char* stack, u32* sp, char* str_buffer);

void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str);
void actionStringLength(char* stack, u32* sp, char* v_str);
void actionStringExtract(char* stack, u32* sp, char* str_buffer);
void actionMbStringLength(char* stack, u32* sp, char* v_str);
void actionStringAdd(char* stack, u32* sp, char* a_str, char* b_str);
void actionStringLess(char* stack, u32* sp);
void actionCharToAscii(char* stack, u32* sp);

void actionGetVariable(char* stack, u32* sp);
void actionSetVariable(char* stack, u32* sp);

void actionTrace(char* stack, u32* sp);
void actionRandomNumber(char* stack, u32* sp);
void actionAsciiToChar(char* stack, u32* sp, char* str_buffer);
void actionMbCharToAscii(char* stack, u32* sp, char* str_buffer);
void actionGetTime(char* stack, u32* sp);
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer);
void actionTypeof(char* stack, u32* sp, char* str_buffer);
void actionDuplicate(char* stack, u32* sp);
void actionIncrement(char* stack, u32* sp);
void actionDecrement(char* stack, u32* sp);
void actionBitAnd(char* stack, u32* sp);
void actionBitOr(char* stack, u32* sp);
void actionBitXor(char* stack, u32* sp);
void actionBitLShift(char* stack, u32* sp);
void actionBitRShift(char* stack, u32* sp);
void actionBitURShift(char* stack, u32* sp);
void actionStrictEquals(char* stack, u32* sp);
void actionGreater(char* stack, u32* sp);
void actionStringGreater(char* stack, u32* sp);
void actionNewObject(char* stack, u32* sp);
