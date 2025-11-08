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
void popVar(char* stack, u32* sp, ActionVar* var);
void setVariableByName(const char* var_name, ActionVar* value);

void actionPrevFrame(char* stack, u32* sp);
void actionToggleQuality(char* stack, u32* sp);

void actionAdd(char* stack, u32* sp);
void actionAdd2(char* stack, u32* sp, char* str_buffer);
void actionSubtract(char* stack, u32* sp);
void actionMultiply(char* stack, u32* sp);
void actionDivide(char* stack, u32* sp);
void actionModulo(char* stack, u32* sp);
void actionEquals(char* stack, u32* sp);
void actionLess(char* stack, u32* sp);
void actionLess2(char* stack, u32* sp);
void actionEquals2(char* stack, u32* sp);
void actionAnd(char* stack, u32* sp);
void actionOr(char* stack, u32* sp);
void actionNot(char* stack, u32* sp);
void actionToInteger(char* stack, u32* sp);
void actionToNumber(char* stack, u32* sp);
void actionToString(char* stack, u32* sp, char* str_buffer);
void actionStackSwap(char* stack, u32* sp);
void actionDuplicate(char* stack, u32* sp);
void actionGetMember(char* stack, u32* sp);
void actionTargetPath(char* stack, u32* sp, char* str_buffer);
void actionEnumerate(char* stack, u32* sp, char* str_buffer);

// Movie control
void actionGoToLabel(char* stack, u32* sp, const char* label);
void actionGotoFrame2(char* stack, u32* sp, u8 play_flag, u16 scene_bias);

void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str);
void actionStringLength(char* stack, u32* sp, char* v_str);
void actionStringExtract(char* stack, u32* sp, char* str_buffer);
void actionMbStringLength(char* stack, u32* sp, char* v_str);
void actionStringAdd(char* stack, u32* sp, char* a_str, char* b_str);
void actionStringLess(char* stack, u32* sp);
void actionImplementsOp(char* stack, u32* sp);
void actionCharToAscii(char* stack, u32* sp);

void actionGetVariable(char* stack, u32* sp);
void actionSetVariable(char* stack, u32* sp);
void actionSetTarget2(char* stack, u32* sp);
void actionDefineLocal(char* stack, u32* sp);
void actionDeclareLocal(char* stack, u32* sp);
void actionGetProperty(char* stack, u32* sp);
void actionSetProperty(char* stack, u32* sp);
void actionCloneSprite(char* stack, u32* sp);
void actionRemoveSprite(char* stack, u32* sp);
void actionSetTarget(char* stack, u32* sp, const char* target_name);

void actionNextFrame();
void actionPlay();
void actionGotoFrame(char* stack, u32* sp, u16 frame);
void actionTrace(char* stack, u32* sp);
void actionStartDrag(char* stack, u32* sp);
void actionEndDrag(char* stack, u32* sp);
void actionStopSounds(char* stack, u32* sp);
void actionGetURL(char* stack, u32* sp, const char* url, const char* target);
void actionRandomNumber(char* stack, u32* sp);
void actionAsciiToChar(char* stack, u32* sp, char* str_buffer);
void actionMbCharToAscii(char* stack, u32* sp, char* str_buffer);
void actionGetTime(char* stack, u32* sp);
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer);
void actionTypeof(char* stack, u32* sp, char* str_buffer);
void actionCastOp(char* stack, u32* sp);
void actionCallFunction(char* stack, u32* sp, char* str_buffer);
void actionReturn(char* stack, u32* sp);
void actionInitArray(char* stack, u32* sp);
void actionInitObject(char* stack, u32* sp);
void actionIncrement(char* stack, u32* sp);
void actionDecrement(char* stack, u32* sp);
void actionInstanceOf(char* stack, u32* sp);
void actionEnumerate2(char* stack, u32* sp, char* str_buffer);
void actionDelete(char* stack, u32* sp);
void actionDelete2(char* stack, u32* sp, char* str_buffer);
void actionBitAnd(char* stack, u32* sp);
void actionBitOr(char* stack, u32* sp);
void actionBitXor(char* stack, u32* sp);
void actionBitLShift(char* stack, u32* sp);
void actionBitRShift(char* stack, u32* sp);
void actionBitURShift(char* stack, u32* sp);
void actionStrictEquals(char* stack, u32* sp);
void actionGreater(char* stack, u32* sp);
void actionStringGreater(char* stack, u32* sp);
void actionExtends(char* stack, u32* sp);
void actionStoreRegister(char* stack, u32* sp, u8 register_num);
void actionPushRegister(char* stack, u32* sp, u8 register_num);
void actionDefineFunction(char* stack, u32* sp, const char* name, void (*func)(char*, u32*), u32 param_count);
void actionCall(char* stack, u32* sp);
void actionCallMethod(char* stack, u32* sp, char* str_buffer);
void actionGetURL2(char* stack, u32* sp, u8 send_vars_method, u8 load_target_flag, u8 load_variables_flag);
void actionInitObject(char* stack, u32* sp);
void actionGetMember(char* stack, u32* sp);
void actionSetMember(char* stack, u32* sp);
void actionNewObject(char* stack, u32* sp);
void actionNewMethod(char* stack, u32* sp);

// Function pointer type for DefineFunction2
typedef ActionVar (*Function2Ptr)(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);

void actionDefineFunction2(char* stack, u32* sp, const char* name, Function2Ptr func, u32 param_count, u8 register_count, u16 flags);
void actionWithStart(char* stack, u32* sp);
void actionWithEnd(char* stack, u32* sp);

// Exception handling (try-catch-finally)
void actionThrow(char* stack, u32* sp);
void actionTryBegin(char* stack, u32* sp);
bool actionTryExecute(char* stack, u32* sp);
void actionCatchToVariable(char* stack, u32* sp, const char* var_name);
void actionCatchToRegister(char* stack, u32* sp, u8 reg_num);
void actionTryEnd(char* stack, u32* sp);

// Control flow
bool actionWaitForFrame(char* stack, u32* sp, u16 frame);
bool actionWaitForFrame2(char* stack, u32* sp);
