#include <recomp.h>
#include "script_decls.h"
#include <string.h>


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_0(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	// Preload 'super' into register 2
	{
		u64 _super_this; u32 _super_depth;
		actionGetCurrentSuperInfo(&_super_this, &_super_depth);
		if (_super_this) {
			regs[2].type = ACTION_STACK_VALUE_SUPER;
			regs[2].data.numeric_value = _super_this;
			regs[2].str_size = _super_depth;
		} else {
			regs[2].type = ACTION_STACK_VALUE_UNDEFINED;
			regs[2].data.numeric_value = 0;
		}
	}

	// Function body (0 bytes)

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_1(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[16];
	for (int _ri = 0; _ri < 16; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (3881 bytes)
	// Push (ConstantPool8[4])
	PUSH_STR_ID(str_4, strlen(str_4), 4);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 3
	peekVar(app_context, &regs[3]);
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[7])
	PUSH_STR_ID(str_7, strlen(str_7), 7);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 4
	peekVar(app_context, &regs[4]);
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (ConstantPool8[8])
	PUSH_STR_ID(str_8, strlen(str_8), 8);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[10])
	PUSH_STR_ID(str_10, strlen(str_10), 10);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[11])
	PUSH_STR_ID(str_11, strlen(str_11), 11);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[12])
	PUSH_STR_ID(str_12, strlen(str_12), 12);
	// Push (ConstantPool8[13])
	PUSH_STR_ID(str_13, strlen(str_13), 13);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[15])
	PUSH_STR_ID(str_15, strlen(str_15), 15);
	// Push (ConstantPool8[16])
	PUSH_STR_ID(str_16, strlen(str_16), 16);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[18])
	PUSH_STR_ID(str_18, strlen(str_18), 18);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[20])
	PUSH_STR_ID(str_20, strlen(str_20), 20);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[21])
	PUSH_STR_ID(str_21, strlen(str_21), 21);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[23])
	PUSH_STR_ID(str_23, strlen(str_23), 23);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 5
	peekVar(app_context, &regs[5]);
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[24])
	PUSH_STR_ID(str_24, strlen(str_24), 24);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[25])
	PUSH_STR_ID(str_25, strlen(str_25), 25);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 6
	peekVar(app_context, &regs[6]);
	// Pop
	POP();
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (ConstantPool8[26])
	PUSH_STR_ID(str_26, strlen(str_26), 26);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[27])
	PUSH_STR_ID(str_27, strlen(str_27), 27);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[28])
	PUSH_STR_ID(str_28, strlen(str_28), 28);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[25])
	PUSH_STR_ID(str_25, strlen(str_25), 25);
	// GetMember
	actionGetMember(app_context);
	// StoreRegister 7
	peekVar(app_context, &regs[7]);
	// Pop
	POP();
	// Push (ConstantPool8[29])
	PUSH_STR_ID(str_29, strlen(str_29), 29);
	// Trace
	actionTrace(app_context);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (Register 7)
	pushVar(app_context, &regs[7]);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[31])
	PUSH_STR_ID(str_31, strlen(str_31), 31);
	// Trace
	actionTrace(app_context);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (Register 7)
	pushVar(app_context, &regs[7]);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[32])
	PUSH_STR_ID(str_32, strlen(str_32), 32);
	// Trace
	actionTrace(app_context);
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (Register 7)
	pushVar(app_context, &regs[7]);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF8000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 1000)
	PUSH(ACTION_STACK_VALUE_F64, 0x408F400000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1000)
	PUSH(ACTION_STACK_VALUE_F64, 0xC08F400000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 20)
	PUSH(ACTION_STACK_VALUE_F64, 0x4034000000000000ULL);
	// Push (integer: 19)
	PUSH(ACTION_STACK_VALUE_F64, 0x4033000000000000ULL);
	// Push (integer: 18)
	PUSH(ACTION_STACK_VALUE_F64, 0x4032000000000000ULL);
	// Push (integer: 17)
	PUSH(ACTION_STACK_VALUE_F64, 0x4031000000000000ULL);
	// Push (integer: 16)
	PUSH(ACTION_STACK_VALUE_F64, 0x4030000000000000ULL);
	// Push (integer: 15)
	PUSH(ACTION_STACK_VALUE_F64, 0x402E000000000000ULL);
	// Push (integer: 14)
	PUSH(ACTION_STACK_VALUE_F64, 0x402C000000000000ULL);
	// Push (integer: 13)
	PUSH(ACTION_STACK_VALUE_F64, 0x402A000000000000ULL);
	// Push (integer: 12)
	PUSH(ACTION_STACK_VALUE_F64, 0x4028000000000000ULL);
	// Push (integer: 11)
	PUSH(ACTION_STACK_VALUE_F64, 0x4026000000000000ULL);
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Push (integer: 9)
	PUSH(ACTION_STACK_VALUE_F64, 0x4022000000000000ULL);
	// Push (integer: 8)
	PUSH(ACTION_STACK_VALUE_F64, 0x4020000000000000ULL);
	// Push (integer: 7)
	PUSH(ACTION_STACK_VALUE_F64, 0x401C000000000000ULL);
	// Push (integer: 6)
	PUSH(ACTION_STACK_VALUE_F64, 0x4018000000000000ULL);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 21)
	PUSH(ACTION_STACK_VALUE_F64, 0x4035000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Push (ConstantPool8[35])
	PUSH_STR_ID(str_35, strlen(str_35), 35);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (boolean: false)
	PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
	// Push (boolean: true)
	PUSH(ACTION_STACK_VALUE_BOOLEAN, 1);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[36])
	PUSH_STR_ID(str_36, strlen(str_36), 36);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[37])
	PUSH_STR_ID(str_37, strlen(str_37), 37);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 8
	peekVar(app_context, &regs[8]);
	// Pop
	POP();
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (ConstantPool8[38])
	PUSH_STR_ID(str_38, strlen(str_38), 38);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[39])
	PUSH_STR_ID(str_39, strlen(str_39), 39);
	// Push (ConstantPool8[40])
	PUSH_STR_ID(str_40, strlen(str_40), 40);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059200000000000ULL);
	// Push (ConstantPool8[41])
	PUSH_STR_ID(str_41, strlen(str_41), 41);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xC059200000000000ULL);
	// Push (ConstantPool8[41])
	PUSH_STR_ID(str_41, strlen(str_41), 41);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059200000000000ULL);
	// Push (ConstantPool8[42])
	PUSH_STR_ID(str_42, strlen(str_42), 42);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xC059200000000000ULL);
	// Push (ConstantPool8[42])
	PUSH_STR_ID(str_42, strlen(str_42), 42);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[43])
	PUSH_STR_ID(str_43, strlen(str_43), 43);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[44])
	PUSH_STR_ID(str_44, strlen(str_44), 44);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (ConstantPool8[46])
	PUSH_STR_ID(str_46, strlen(str_46), 46);
	// Push (ConstantPool8[47])
	PUSH_STR_ID(str_47, strlen(str_47), 47);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// StoreRegister 9
	peekVar(app_context, &regs[9]);
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[48])
	PUSH_STR_ID(str_48, strlen(str_48), 48);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[49])
	PUSH_STR_ID(str_49, strlen(str_49), 49);
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xC08F440000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[47])
	PUSH_STR_ID(str_47, strlen(str_47), 47);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[46])
	PUSH_STR_ID(str_46, strlen(str_46), 46);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[36])
	PUSH_STR_ID(str_36, strlen(str_36), 36);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: 1234)
	PUSH(ACTION_STACK_VALUE_F64, 0x4093480000000000ULL);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: -5)
	PUSH(ACTION_STACK_VALUE_F64, 0xC014000000000000ULL);
	// Push (integer: -4)
	PUSH(ACTION_STACK_VALUE_F64, 0xC010000000000000ULL);
	// Push (integer: -3)
	PUSH(ACTION_STACK_VALUE_F64, 0xC008000000000000ULL);
	// Push (integer: -2)
	PUSH(ACTION_STACK_VALUE_F64, 0xC000000000000000ULL);
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x400C000000000000ULL);
	// Push (ConstantPool8[47])
	PUSH_STR_ID(str_47, strlen(str_47), 47);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4012000000000000ULL);
	// Push (ConstantPool8[46])
	PUSH_STR_ID(str_46, strlen(str_46), 46);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[50])
	PUSH_STR_ID(str_50, strlen(str_50), 50);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (ConstantPool8[51])
	PUSH_STR_ID(str_51, strlen(str_51), 51);
	// Push (ConstantPool8[52])
	PUSH_STR_ID(str_52, strlen(str_52), 52);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[33])
	PUSH_STR_ID(str_33, strlen(str_33), 33);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[53])
	PUSH_STR_ID(str_53, strlen(str_53), 53);
	// Trace
	actionTrace(app_context);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (ConstantPool8[47])
	PUSH_STR_ID(str_47, strlen(str_47), 47);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (ConstantPool8[46])
	PUSH_STR_ID(str_46, strlen(str_46), 46);
	// Push (integer: -100)
	PUSH(ACTION_STACK_VALUE_F64, 0xC059000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// GetMember
	actionGetMember(app_context);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[55])
	PUSH_STR_ID(str_55, strlen(str_55), 55);
	// Trace
	actionTrace(app_context);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (ConstantPool8[47])
	PUSH_STR_ID(str_47, strlen(str_47), 47);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (ConstantPool8[46])
	PUSH_STR_ID(str_46, strlen(str_46), 46);
	// Push (integer: 100)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 9)
	pushVar(app_context, &regs[9]);
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// GetMember
	actionGetMember(app_context);
	// Push (Register 8)
	pushVar(app_context, &regs[8]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[56])
	PUSH_STR_ID(str_56, strlen(str_56), 56);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 10
	peekVar(app_context, &regs[10]);
	// Pop
	POP();
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[39])
	PUSH_STR_ID(str_39, strlen(str_39), 39);
	// Push (ConstantPool8[40])
	PUSH_STR_ID(str_40, strlen(str_40), 40);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[57])
	PUSH_STR_ID(str_57, strlen(str_57), 57);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[58])
	PUSH_STR_ID(str_58, strlen(str_58), 58);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[59])
	PUSH_STR_ID(str_59, strlen(str_59), 59);
	// Push (integer: 123)
	PUSH(ACTION_STACK_VALUE_F64, 0x405EC00000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[59])
	PUSH_STR_ID(str_59, strlen(str_59), 59);
	// Push (ConstantPool8[58])
	PUSH_STR_ID(str_58, strlen(str_58), 58);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[60])
	PUSH_STR_ID(str_60, strlen(str_60), 60);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[58])
	PUSH_STR_ID(str_58, strlen(str_58), 58);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[59])
	PUSH_STR_ID(str_59, strlen(str_59), 59);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xC06D500000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[59])
	PUSH_STR_ID(str_59, strlen(str_59), 59);
	// Push (ConstantPool8[58])
	PUSH_STR_ID(str_58, strlen(str_58), 58);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[61])
	PUSH_STR_ID(str_61, strlen(str_61), 61);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xC06D500000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[64])
	PUSH_STR_ID(str_64, strlen(str_64), 64);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (integer: 65536)
	PUSH(ACTION_STACK_VALUE_F64, 0x40F0000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[65])
	PUSH_STR_ID(str_65, strlen(str_65), 65);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (integer: -65536)
	PUSH(ACTION_STACK_VALUE_F64, 0xC0F0000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[63])
	PUSH_STR_ID(str_63, strlen(str_63), 63);
	// Push (ConstantPool8[62])
	PUSH_STR_ID(str_62, strlen(str_62), 62);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[44])
	PUSH_STR_ID(str_44, strlen(str_44), 44);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[35])
	PUSH_STR_ID(str_35, strlen(str_35), 35);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[67])
	PUSH_STR_ID(str_67, strlen(str_67), 67);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[40])
	PUSH_STR_ID(str_40, strlen(str_40), 40);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[68])
	PUSH_STR_ID(str_68, strlen(str_68), 68);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[69])
	PUSH_STR_ID(str_69, strlen(str_69), 69);
	// Push (ConstantPool8[66])
	PUSH_STR_ID(str_66, strlen(str_66), 66);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[27])
	PUSH_STR_ID(str_27, strlen(str_27), 27);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[70])
	PUSH_STR_ID(str_70, strlen(str_70), 70);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[71])
	PUSH_STR_ID(str_71, strlen(str_71), 71);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 11
	peekVar(app_context, &regs[11]);
	// Pop
	POP();
	// Push (Register 11)
	pushVar(app_context, &regs[11]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[73])
	PUSH_STR_ID(str_73, strlen(str_73), 73);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// Push (Register 11)
	pushVar(app_context, &regs[11]);
	// SetMember
	actionSetMember(app_context);
	// Push (integer: -16776961)
	PUSH(ACTION_STACK_VALUE_F64, 0xC16FFFE020000000ULL);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (Register 11)
	pushVar(app_context, &regs[11]);
	// Push (ConstantPool8[74])
	PUSH_STR_ID(str_74, strlen(str_74), 74);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[75])
	PUSH_STR_ID(str_75, strlen(str_75), 75);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[76])
	PUSH_STR_ID(str_76, strlen(str_76), 76);
	// GetMember
	actionGetMember(app_context);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_138);
	// Push (ConstantPool8[77])
	PUSH_STR_ID(str_77, strlen(str_77), 77);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_139);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[78])
	PUSH_STR_ID(str_78, strlen(str_78), 78);
	// GetMember
	actionGetMember(app_context);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_140);
	// Push (ConstantPool8[79])
	PUSH_STR_ID(str_79, strlen(str_79), 79);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_141);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[80])
	PUSH_STR_ID(str_80, strlen(str_80), 80);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_142);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[81])
	PUSH_STR_ID(str_81, strlen(str_81), 81);
	// Trace
	actionTrace(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (Register 11)
	pushVar(app_context, &regs[11]);
	// Push (ConstantPool8[82])
	PUSH_STR_ID(str_82, strlen(str_82), 82);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[75])
	PUSH_STR_ID(str_75, strlen(str_75), 75);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[76])
	PUSH_STR_ID(str_76, strlen(str_76), 76);
	// GetMember
	actionGetMember(app_context);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_143);
	// Push (ConstantPool8[77])
	PUSH_STR_ID(str_77, strlen(str_77), 77);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_144);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[78])
	PUSH_STR_ID(str_78, strlen(str_78), 78);
	// GetMember
	actionGetMember(app_context);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_145);
	// Trace
	actionTrace(app_context);
	// Push (integer: 45)
	PUSH(ACTION_STACK_VALUE_F64, 0x4046800000000000ULL);
	// Push (ConstantPool8[72])
	PUSH_STR_ID(str_72, strlen(str_72), 72);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -4200)
	PUSH(ACTION_STACK_VALUE_F64, 0xC0B0680000000000ULL);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4029000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[27])
	PUSH_STR_ID(str_27, strlen(str_27), 27);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[83])
	PUSH_STR_ID(str_83, strlen(str_83), 83);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[84])
	PUSH_STR_ID(str_84, strlen(str_84), 84);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[86])
	PUSH_STR_ID(str_86, strlen(str_86), 86);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[86])
	PUSH_STR_ID(str_86, strlen(str_86), 86);
	// Push (integer: 65540)
	PUSH(ACTION_STACK_VALUE_F64, 0x40F0004000000000ULL);
	// Push (ConstantPool8[87])
	PUSH_STR_ID(str_87, strlen(str_87), 87);
	// Push (integer: -65540)
	PUSH(ACTION_STACK_VALUE_F64, 0xC0F0004000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[88])
	PUSH_STR_ID(str_88, strlen(str_88), 88);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// GetMember
	actionGetMember(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// GetMember
	actionGetMember(app_context);
	// Equals2
	actionEquals2(app_context);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[89])
	PUSH_STR_ID(str_89, strlen(str_89), 89);
	// Trace
	actionTrace(app_context);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[86])
	PUSH_STR_ID(str_86, strlen(str_86), 86);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[86])
	PUSH_STR_ID(str_86, strlen(str_86), 86);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_146);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[90])
	PUSH_STR_ID(str_90, strlen(str_90), 90);
	// Push (Register 10)
	pushVar(app_context, &regs[10]);
	// Push (ConstantPool8[85])
	PUSH_STR_ID(str_85, strlen(str_85), 85);
	// GetMember
	actionGetMember(app_context);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_147);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[91])
	PUSH_STR_ID(str_91, strlen(str_91), 91);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 12
	peekVar(app_context, &regs[12]);
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (ConstantPool8[92])
	PUSH_STR_ID(str_92, strlen(str_92), 92);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[11])
	PUSH_STR_ID(str_11, strlen(str_11), 11);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[10])
	PUSH_STR_ID(str_10, strlen(str_10), 10);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[39])
	PUSH_STR_ID(str_39, strlen(str_39), 39);
	// Push (ConstantPool8[40])
	PUSH_STR_ID(str_40, strlen(str_40), 40);
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[18])
	PUSH_STR_ID(str_18, strlen(str_18), 18);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[93])
	PUSH_STR_ID(str_93, strlen(str_93), 93);
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[21])
	PUSH_STR_ID(str_21, strlen(str_21), 21);
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[94])
	PUSH_STR_ID(str_94, strlen(str_94), 94);
	// Push (Register 12)
	pushVar(app_context, &regs[12]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[95])
	PUSH_STR_ID(str_95, strlen(str_95), 95);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 13
	peekVar(app_context, &regs[13]);
	// Pop
	POP();
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (ConstantPool8[96])
	PUSH_STR_ID(str_96, strlen(str_96), 96);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[39])
	PUSH_STR_ID(str_39, strlen(str_39), 39);
	// Push (ConstantPool8[40])
	PUSH_STR_ID(str_40, strlen(str_40), 40);
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[14])
	PUSH_STR_ID(str_14, strlen(str_14), 14);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[18])
	PUSH_STR_ID(str_18, strlen(str_18), 18);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[93])
	PUSH_STR_ID(str_93, strlen(str_93), 93);
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[21])
	PUSH_STR_ID(str_21, strlen(str_21), 21);
	// Push (Register 13)
	pushVar(app_context, &regs[13]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[97])
	PUSH_STR_ID(str_97, strlen(str_97), 97);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 14
	peekVar(app_context, &regs[14]);
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (ConstantPool8[98])
	PUSH_STR_ID(str_98, strlen(str_98), 98);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[11])
	PUSH_STR_ID(str_11, strlen(str_11), 11);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[10])
	PUSH_STR_ID(str_10, strlen(str_10), 10);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[99])
	PUSH_STR_ID(str_99, strlen(str_99), 99);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[18])
	PUSH_STR_ID(str_18, strlen(str_18), 18);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[21])
	PUSH_STR_ID(str_21, strlen(str_21), 21);
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 14)
	pushVar(app_context, &regs[14]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[20])
	PUSH_STR_ID(str_20, strlen(str_20), 20);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[100])
	PUSH_STR_ID(str_100, strlen(str_100), 100);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[5])
	PUSH_STR_ID(str_5, strlen(str_5), 5);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 15
	peekVar(app_context, &regs[15]);
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (ConstantPool8[101])
	PUSH_STR_ID(str_101, strlen(str_101), 101);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[9])
	PUSH_STR_ID(str_9, strlen(str_9), 9);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[11])
	PUSH_STR_ID(str_11, strlen(str_11), 11);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[10])
	PUSH_STR_ID(str_10, strlen(str_10), 10);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[99])
	PUSH_STR_ID(str_99, strlen(str_99), 99);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[19])
	PUSH_STR_ID(str_19, strlen(str_19), 19);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[17])
	PUSH_STR_ID(str_17, strlen(str_17), 17);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[18])
	PUSH_STR_ID(str_18, strlen(str_18), 18);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[21])
	PUSH_STR_ID(str_21, strlen(str_21), 21);
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[22])
	PUSH_STR_ID(str_22, strlen(str_22), 22);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 15)
	pushVar(app_context, &regs[15]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[20])
	PUSH_STR_ID(str_20, strlen(str_20), 20);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_2(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[5];
	for (int _ri = 0; _ri < 5; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (100 bytes)
	// Push (ConstantPool8[102])
	PUSH_STR_ID(str_102, strlen(str_102), 102);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_148);
	// Trace
	actionTrace(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (ConstantPool8[1])
	PUSH_STR_ID(str_1, strlen(str_1), 1);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[27])
	PUSH_STR_ID(str_27, strlen(str_27), 27);
	// GetMember
	actionGetMember(app_context);
	// Push (ConstantPool8[28])
	PUSH_STR_ID(str_28, strlen(str_28), 28);
	// GetMember
	actionGetMember(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// NewMethod
	actionNewMethod(app_context);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 3
	peekVar(app_context, &regs[3]);
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[103])
	PUSH_STR_ID(str_103, strlen(str_103), 103);
	// Trace
	actionTrace(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[104])
	PUSH_STR_ID(str_104, strlen(str_104), 104);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// StoreRegister 4
	peekVar(app_context, &regs[4]);
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Trace
	actionTrace(app_context);
	// Push (ConstantPool8[105])
	PUSH_STR_ID(str_105, strlen(str_105), 105);
	// Trace
	actionTrace(app_context);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Equals2
	actionEquals2(app_context);
	// Trace
	actionTrace(app_context);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Return
	{
		ActionVar ret_val;
		popVar(app_context, &ret_val);
		return ret_val;
	}

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_3(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[6];
	for (int _ri = 0; _ri < 6; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}
	if (1 < arg_count) {
		regs[3] = args[1];
	}
	if (2 < arg_count) {
		regs[4] = args[2];
	}

	// Function body (129 bytes)
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// GetMember
	actionGetMember(app_context);
	// StoreRegister 5
	peekVar(app_context, &regs[5]);
	// Pop
	POP();
	// Push (ConstantPool8[106])
	PUSH_STR_ID(str_106, strlen(str_106), 106);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_149);
	// Push (ConstantPool8[107])
	PUSH_STR_ID(str_107, strlen(str_107), 107);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_150);
	// Trace
	actionTrace(app_context);
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[28])
	PUSH_STR_ID(str_28, strlen(str_28), 28);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[106])
	PUSH_STR_ID(str_106, strlen(str_106), 106);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_151);
	// Push (ConstantPool8[108])
	PUSH_STR_ID(str_108, strlen(str_108), 108);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_152);
	// Trace
	actionTrace(app_context);
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[28])
	PUSH_STR_ID(str_28, strlen(str_28), 28);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[28])
	PUSH_STR_ID(str_28, strlen(str_28), 28);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[30])
	PUSH_STR_ID(str_30, strlen(str_30), 30);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_4(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (85 bytes)
	// Push (integer: 1000)
	PUSH(ACTION_STACK_VALUE_F64, 0x408F400000000000ULL);
	// Push (ConstantPool8[109])
	PUSH_STR_ID(str_109, strlen(str_109), 109);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4004000000000000ULL);
	// Push (ConstantPool8[109])
	PUSH_STR_ID(str_109, strlen(str_109), 109);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (ConstantPool8[109])
	PUSH_STR_ID(str_109, strlen(str_109), 109);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_5(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (108 bytes)
	// Push (integer: 360)
	PUSH(ACTION_STACK_VALUE_F64, 0x4076800000000000ULL);
	// Push (ConstantPool8[110])
	PUSH_STR_ID(str_110, strlen(str_110), 110);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 361)
	PUSH(ACTION_STACK_VALUE_F64, 0x4076900000000000ULL);
	// Push (ConstantPool8[110])
	PUSH_STR_ID(str_110, strlen(str_110), 110);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (ConstantPool8[110])
	PUSH_STR_ID(str_110, strlen(str_110), 110);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 366)
	PUSH(ACTION_STACK_VALUE_F64, 0x4076E00000000000ULL);
	// Push (ConstantPool8[110])
	PUSH_STR_ID(str_110, strlen(str_110), 110);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_6(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (202 bytes)
	// Push (ConstantPool8[111])
	PUSH_STR_ID(str_111, strlen(str_111), 111);
	// Trace
	actionTrace(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059200000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[114])
	PUSH_STR_ID(str_114, strlen(str_114), 114);
	// Trace
	actionTrace(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (ConstantPool8[115])
	PUSH_STR_ID(str_115, strlen(str_115), 115);
	// Trace
	actionTrace(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (integer: 256)
	PUSH(ACTION_STACK_VALUE_F64, 0x4070000000000000ULL);
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[113])
	PUSH_STR_ID(str_113, strlen(str_113), 113);
	// Push (ConstantPool8[112])
	PUSH_STR_ID(str_112, strlen(str_112), 112);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_7(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (85 bytes)
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4004000000000000ULL);
	// Push (ConstantPool8[116])
	PUSH_STR_ID(str_116, strlen(str_116), 116);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (ConstantPool8[116])
	PUSH_STR_ID(str_116, strlen(str_116), 116);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: 100)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059000000000000ULL);
	// Push (ConstantPool8[116])
	PUSH_STR_ID(str_116, strlen(str_116), 116);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_8(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (85 bytes)
	// Push (integer: 256)
	PUSH(ACTION_STACK_VALUE_F64, 0x4070000000000000ULL);
	// Push (ConstantPool8[117])
	PUSH_STR_ID(str_117, strlen(str_117), 117);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF8000000000000ULL);
	// Push (ConstantPool8[117])
	PUSH_STR_ID(str_117, strlen(str_117), 117);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (ConstantPool8[117])
	PUSH_STR_ID(str_117, strlen(str_117), 117);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_9(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[4];
	for (int _ri = 0; _ri < 4; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}
	if (1 < arg_count) {
		regs[3] = args[1];
	}

	// Function body (71 bytes)
	// Push (boolean: false)
	PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (boolean: true)
	PUSH(ACTION_STACK_VALUE_BOOLEAN, 1);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_10(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (105 bytes)
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (ConstantPool8[119])
	PUSH_STR_ID(str_119, strlen(str_119), 119);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[120])
	PUSH_STR_ID(str_120, strlen(str_120), 120);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (ConstantPool8[119])
	PUSH_STR_ID(str_119, strlen(str_119), 119);
	// SetMember
	actionSetMember(app_context);
	// Push (ConstantPool8[121])
	PUSH_STR_ID(str_121, strlen(str_121), 121);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (ConstantPool8[119])
	PUSH_STR_ID(str_119, strlen(str_119), 119);
	// SetMember
	actionSetMember(app_context);
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (ConstantPool8[118])
	PUSH_STR_ID(str_118, strlen(str_118), 118);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_11(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[6];
	for (int _ri = 0; _ri < 6; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}
	if (1 < arg_count) {
		regs[3] = args[1];
	}
	if (2 < arg_count) {
		regs[4] = args[2];
	}

	// Function body (182 bytes)
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// StoreRegister 5
	peekVar(app_context, &regs[5]);
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FE0000000000000ULL);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (integer: 16777471)
	PUSH(ACTION_STACK_VALUE_F64, 0x4170000FF0000000ULL);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF8000000000000ULL);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (integer: -305419896)
	PUSH(ACTION_STACK_VALUE_F64, 0xC1B2345678000000ULL);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (integer: -1)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFF0000000000000ULL);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_12(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[4];
	for (int _ri = 0; _ri < 4; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (460 bytes)
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// Push (ConstantPool8[122])
	PUSH_STR_ID(str_122, strlen(str_122), 122);
	// Push (ConstantPool8[123])
	PUSH_STR_ID(str_123, strlen(str_123), 123);
	// Push (ConstantPool8[124])
	PUSH_STR_ID(str_124, strlen(str_124), 124);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitObject
	actionInitObject(app_context);
	// StoreRegister 3
	peekVar(app_context, &regs[3]);
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[123])
	PUSH_STR_ID(str_123, strlen(str_123), 123);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Push (integer: -305419896)
	PUSH(ACTION_STACK_VALUE_F64, 0xC1B2345678000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[124])
	PUSH_STR_ID(str_124, strlen(str_124), 124);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 100)
	PUSH(ACTION_STACK_VALUE_F64, 0x4059000000000000ULL);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x4049400000000000ULL);
	// Push (integer: 500)
	PUSH(ACTION_STACK_VALUE_F64, 0x407F400000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[122])
	PUSH_STR_ID(str_122, strlen(str_122), 122);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[125])
	PUSH_STR_ID(str_125, strlen(str_125), 125);
	// Push (ConstantPool8[124])
	PUSH_STR_ID(str_124, strlen(str_124), 124);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Push (ConstantPool8[122])
	PUSH_STR_ID(str_122, strlen(str_122), 122);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0xBFE0000000000000ULL);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF8000000000000ULL);
	// Push (double)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FE0000000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[123])
	PUSH_STR_ID(str_123, strlen(str_123), 123);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 50)
	PUSH(ACTION_STACK_VALUE_F64, 0x4049000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[122])
	PUSH_STR_ID(str_122, strlen(str_122), 122);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// Push (ConstantPool8[124])
	PUSH_STR_ID(str_124, strlen(str_124), 124);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (integer: 17)
	PUSH(ACTION_STACK_VALUE_F64, 0x4031000000000000ULL);
	// Push (integer: 16)
	PUSH(ACTION_STACK_VALUE_F64, 0x4030000000000000ULL);
	// Push (integer: 15)
	PUSH(ACTION_STACK_VALUE_F64, 0x402E000000000000ULL);
	// Push (integer: 14)
	PUSH(ACTION_STACK_VALUE_F64, 0x402C000000000000ULL);
	// Push (integer: 13)
	PUSH(ACTION_STACK_VALUE_F64, 0x402A000000000000ULL);
	// Push (integer: 12)
	PUSH(ACTION_STACK_VALUE_F64, 0x4028000000000000ULL);
	// Push (integer: 11)
	PUSH(ACTION_STACK_VALUE_F64, 0x4026000000000000ULL);
	// Push (integer: 10)
	PUSH(ACTION_STACK_VALUE_F64, 0x4024000000000000ULL);
	// Push (integer: 9)
	PUSH(ACTION_STACK_VALUE_F64, 0x4022000000000000ULL);
	// Push (integer: 8)
	PUSH(ACTION_STACK_VALUE_F64, 0x4020000000000000ULL);
	// Push (integer: 7)
	PUSH(ACTION_STACK_VALUE_F64, 0x401C000000000000ULL);
	// Push (integer: 6)
	PUSH(ACTION_STACK_VALUE_F64, 0x4018000000000000ULL);
	// Push (integer: 5)
	PUSH(ACTION_STACK_VALUE_F64, 0x4014000000000000ULL);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (integer: 3)
	PUSH(ACTION_STACK_VALUE_F64, 0x4008000000000000ULL);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (integer: 17)
	PUSH(ACTION_STACK_VALUE_F64, 0x4031000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// Push (ConstantPool8[124])
	PUSH_STR_ID(str_124, strlen(str_124), 124);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 4)
	PUSH(ACTION_STACK_VALUE_F64, 0x4010000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[34])
	PUSH_STR_ID(str_34, strlen(str_34), 34);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_13(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[3];
	for (int _ri = 0; _ri < 3; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (42 bytes)
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (ConstantPool8[127])
	PUSH_STR_ID(str_127, strlen(str_127), 127);
	// GetVariable
	actionGetVariable(app_context);
	// InstanceOf
	actionInstanceOf(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_27;
	}
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_153);
	// Jump
	goto label_41;
label_27:
	// Push (ConstantPool8[128])
	PUSH_STR_ID(str_128, strlen(str_128), 128);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_154);
	// Push (ConstantPool8[129])
	PUSH_STR_ID(str_129, strlen(str_129), 129);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_155);
label_41:
	// Return
	{
		ActionVar ret_val;
		popVar(app_context, &ret_val);
		return ret_val;
	}

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_14(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[6];
	for (int _ri = 0; _ri < 6; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}
	if (1 < arg_count) {
		regs[3] = args[1];
	}
	if (2 < arg_count) {
		regs[4] = args[2];
	}
	if (3 < arg_count) {
		regs[5] = args[3];
	}

	// Function body (132 bytes)
	// Push (ConstantPool8[130])
	PUSH_STR_ID(str_130, strlen(str_130), 130);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_156);
	// Push (ConstantPool8[131])
	PUSH_STR_ID(str_131, strlen(str_131), 131);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_157);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[126])
	PUSH_STR_ID(str_126, strlen(str_126), 126);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_158);
	// Trace
	actionTrace(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// SetMember
	actionSetMember(app_context);
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// GetMember
	actionGetMember(app_context);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// StrictEquals
	actionStrictEquals(app_context);
	// Not
	actionNot(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_104;
	}
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[132])
	PUSH_STR_ID(str_132, strlen(str_132), 132);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_159);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[126])
	PUSH_STR_ID(str_126, strlen(str_126), 126);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_160);
	// Trace
	actionTrace(app_context);
	// Jump
	goto label_132;
label_104:
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (ConstantPool8[45])
	PUSH_STR_ID(str_45, strlen(str_45), 45);
	// GetMember
	actionGetMember(app_context);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
label_132:

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_15(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[8]; // Fixed: was [7], but StoreRegister 7 needs index 7
	for (int _ri = 0; _ri < 8; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}
	if (1 < arg_count) {
		regs[3] = args[1];
	}

	// Function body (174 bytes)
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Equals2
	actionEquals2(app_context);
	// Not
	actionNot(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_24;
	}
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Trace
	actionTrace(app_context);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Return
	{
		ActionVar ret_val;
		popVar(app_context, &ret_val);
		return ret_val;
	}
label_24:
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// StoreRegister 4
	peekVar(app_context, &regs[4]);
	// Pop
	POP();
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// StoreRegister 5
	peekVar(app_context, &regs[5]);
	// Pop
	POP();
	// Jump
	goto label_63;
label_52:
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Increment
	actionIncrement(app_context);
	// StoreRegister 5
	peekVar(app_context, &regs[5]);
	// Pop
	POP();
label_63:
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[49])
	PUSH_STR_ID(str_49, strlen(str_49), 49);
	// GetMember
	actionGetMember(app_context);
	// Less2
	actionLess2(app_context);
	// Not
	actionNot(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_168;
	}
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 5)
	pushVar(app_context, &regs[5]);
	// GetMember
	actionGetMember(app_context);
	// StoreRegister 6
	peekVar(app_context, &regs[6]);
	// Pop
	POP();
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (ConstantPool8[6])
	PUSH_STR_ID(str_6, strlen(str_6), 6);
	// Equals2
	actionEquals2(app_context);
	// Not
	actionNot(app_context);
	// Not
	actionNot(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_121;
	}
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (ConstantPool8[133])
	PUSH_STR_ID(str_133, strlen(str_133), 133);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_161);
	// StoreRegister 4
	peekVar(app_context, &regs[4]);
	// Pop
	POP();
label_121:
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// Push (ConstantPool8[132])
	PUSH_STR_ID(str_132, strlen(str_132), 132);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_162);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (Register 6)
	pushVar(app_context, &regs[6]);
	// GetMember
	actionGetMember(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[126])
	PUSH_STR_ID(str_126, strlen(str_126), 126);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_163);
	// Add2 (Type-Aware Addition)
	actionAdd2(app_context, str_164);
	// StoreRegister 4
	peekVar(app_context, &regs[4]);
	// Pop
	POP();
	// Jump
	goto label_52;
label_168:
	// Push (Register 4)
	pushVar(app_context, &regs[4]);
	// Trace
	actionTrace(app_context);

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}


// DefineFunction2: (anonymous)
ActionVar func2_anonymous_16(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	char str_buffer[17];
	ActionVar regs[4];
	for (int _ri = 0; _ri < 4; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }
	extern ActionVar g_override_this;
	extern int g_override_this_set;
	int _ot_flag = g_override_this_set; g_override_this_set = 0;
	ActionVar _ot_val; if (_ot_flag) _ot_val = g_override_this;
	// Preload 'this' into register 1
	if (_ot_flag) {
		regs[1] = _ot_val;
	} else if (this_obj != NULL) {
		regs[1].type = ACTION_STACK_VALUE_OBJECT;
		regs[1].data.numeric_value = (u64)this_obj;
	} else {
		extern MovieClip root_movieclip;
		extern MovieClip* g_event_this_mc;
		if (g_event_this_mc != NULL) {
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)g_event_this_mc;
			g_event_this_mc = NULL;
		} else {
			extern MovieClip* g_current_context;
			regs[1].type = ACTION_STACK_VALUE_MOVIECLIP;
			regs[1].data.numeric_value = (u64)(g_current_context ? g_current_context : &root_movieclip);
		}
	}
	if (0 < arg_count) {
		regs[2] = args[0];
	}

	// Function body (127 bytes)
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Equals2
	actionEquals2(app_context);
	// Not
	actionNot(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_24;
	}
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Trace
	actionTrace(app_context);
	// Push (undefined)
	PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
	// Return
	{
		ActionVar ret_val;
		popVar(app_context, &ret_val);
		return ret_val;
	}
label_24:
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// InitArray
	actionInitArray(app_context);
	// StoreRegister 3
	peekVar(app_context, &regs[3]);
	// Pop
	POP();
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Enumerate2
	actionEnumerate2(app_context, str_165);
label_44:
	// StoreRegister 0
	peekVar(app_context, &regs[0]);
	// Push (null)
	PUSH(ACTION_STACK_VALUE_NULL, 0);
	// Equals2
	actionEquals2(app_context);
	// If
	if (evaluateCondition(app_context))
	{
		goto label_91;
	}
	// Push (ConstantPool8[134])
	PUSH_STR_ID(str_134, strlen(str_134), 134);
	// Push (Register 0)
	pushVar(app_context, &regs[0]);
	// DefineLocal
	actionDefineLocal(app_context);
	// Push (ConstantPool8[134])
	PUSH_STR_ID(str_134, strlen(str_134), 134);
	// GetVariable
	actionGetVariable(app_context);
	// Push (integer: 1)
	PUSH(ACTION_STACK_VALUE_F64, 0x3FF0000000000000ULL);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[135])
	PUSH_STR_ID(str_135, strlen(str_135), 135);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Jump
	goto label_44;
label_91:
	// Push (integer: 0)
	PUSH(ACTION_STACK_VALUE_F64, 0x0000000000000000ULL);
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (ConstantPool8[136])
	PUSH_STR_ID(str_136, strlen(str_136), 136);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();
	// Push (Register 3)
	pushVar(app_context, &regs[3]);
	// Push (Register 2)
	pushVar(app_context, &regs[2]);
	// Push (integer: 2)
	PUSH(ACTION_STACK_VALUE_F64, 0x4000000000000000ULL);
	// Push (ConstantPool8[0])
	PUSH_STR_ID(str_0, strlen(str_0), 0);
	// GetVariable
	actionGetVariable(app_context);
	// Push (ConstantPool8[54])
	PUSH_STR_ID(str_54, strlen(str_54), 54);
	// CallMethod
	actionCallMethod(app_context, str_buffer);
	if (actionBaseClipRemoved()) { ActionVar _hr = {0}; _hr.type = ACTION_STACK_VALUE_UNDEFINED; return _hr; }
	// Pop
	POP();

	// Return undefined if no explicit return
	ActionVar ret;
	ret.type = ACTION_STACK_VALUE_UNDEFINED;
	ret.data.numeric_value = 0;
	return ret;
}

char* str_0 = "Test";
char* str_1 = "_global";
char* str_2 = "prototype";
char* str_3 = "main";
char* str_4 = "BitmapFilter";
char* str_5 = "constructAndTestClone";
char* str_6 = "";
char* str_7 = "BevelFilter";
char* str_8 = "bevelMC";
char* str_9 = "testMovieClipFilterSetter";
char* str_10 = "testAngleSetter";
char* str_11 = "testDistanceSetter";
char* str_12 = "highlightAlpha";
char* str_13 = "highlightColor";
char* str_14 = "testColorAndAlphaSetters";
char* str_15 = "shadowAlpha";
char* str_16 = "shadowColor";
char* str_17 = "testQualitySetter";
char* str_18 = "testStrengthSetter";
char* str_19 = "testBlurSetters";
char* str_20 = "testTypeSetter";
char* str_21 = "knockout";
char* str_22 = "testBooleanSetter";
char* str_23 = "BlurFilter";
char* str_24 = "blurMC";
char* str_25 = "ColorMatrixFilter";
char* str_26 = "colorMatrixMC";
char* str_27 = "flash";
char* str_28 = "filters";
char* str_29 = "// new ColorMatrixFilter(null)";
char* str_30 = "traceAllProps";
char* str_31 = "// new ColorMatrixFilter(undefined)";
char* str_32 = "// new ColorMatrixFilter(-1)";
char* str_33 = "matrix";
char* str_34 = "setAndTraceProp";
char* str_35 = "test";
char* str_36 = "ASDASDASD";
char* str_37 = "ConvolutionFilter";
char* str_38 = "convolutionMC";
char* str_39 = "alpha";
char* str_40 = "color";
char* str_41 = "bias";
char* str_42 = "divisor";
char* str_43 = "preserveAlpha";
char* str_44 = "clamp";
char* str_45 = "trace";
char* str_46 = "matrixY";
char* str_47 = "matrixX";
char* str_48 = "ASDASD";
char* str_49 = "length";
char* str_50 = "ASD";
char* str_51 = "2";
char* str_52 = "1aaa";
char* str_53 = "// f.matrixX = f.matrixY = -100";
char* str_54 = "traceProps";
char* str_55 = "// f.matrixX = f.matrixY = 100";
char* str_56 = "DisplacementMapFilter";
char* str_57 = "// f.componentX = f.componentY = 123";
char* str_58 = "componentX";
char* str_59 = "componentY";
char* str_60 = "// f.componentX = f.componentY = -234.5";
char* str_61 = "// f.scaleX = f.scaleY = -234.5";
char* str_62 = "scaleX";
char* str_63 = "scaleY";
char* str_64 = "// f.scaleX = f.scaleY = 65536";
char* str_65 = "// f.scaleX = f.scaleY = -65536";
char* str_66 = "mode";
char* str_67 = "ignore";
char* str_68 = "wrap";
char* str_69 = "Color";
char* str_70 = "display";
char* str_71 = "BitmapData";
char* str_72 = "mapBitmap";
char* str_73 = "// f.mapBitmap.setPixel32(0, 0, 0xFF0000FF)";
char* str_74 = "setPixel";
char* str_75 = "width = ";
char* str_76 = "width";
char* str_77 = ", height = ";
char* str_78 = "height";
char* str_79 = ", getPixel(0, 0) = ";
char* str_80 = "getPixel32";
char* str_81 = "// f.mapBitmap.dispose()";
char* str_82 = "dispose";
char* str_83 = "geom";
char* str_84 = "Point";
char* str_85 = "mapPoint";
char* str_86 = "x";
char* str_87 = "y";
char* str_88 = "// f.mapPoint == f.mapPoint";
char* str_89 = "// f.mapPoint.x += 10";
char* str_90 = "mapPoint=";
char* str_91 = "DropShadowFilter";
char* str_92 = "dropShadowMC";
char* str_93 = "inner";
char* str_94 = "hideObject";
char* str_95 = "GlowFilter";
char* str_96 = "glowMC";
char* str_97 = "GradientBevelFilter";
char* str_98 = "gradientBevelMC";
char* str_99 = "testGradientArraySetters";
char* str_100 = "GradientGlowFilter";
char* str_101 = "gradientGlowMC";
char* str_102 = "// new ";
char* str_103 = "// f.clone()";
char* str_104 = "clone";
char* str_105 = "// f == f.clone()";
char* str_106 = "// ";
char* str_107 = ".filters[0]";
char* str_108 = ".filters = [f]";
char* str_109 = "distance";
char* str_110 = "angle";
char* str_111 = "// f.blurX = f.blurY = 100.5";
char* str_112 = "blurX";
char* str_113 = "blurY";
char* str_114 = "// f.blurX = f.blurY = -1";
char* str_115 = "// f.blurX = f.blurY = 256";
char* str_116 = "quality";
char* str_117 = "strength";
char* str_118 = "type";
char* str_119 = "outer";
char* str_120 = "invalid";
char* str_121 = "INNER";
char* str_122 = "ratios";
char* str_123 = "alphas";
char* str_124 = "colors";
char* str_125 = "ASDF";
char* str_126 = "valueToString";
char* str_127 = "Array";
char* str_128 = "[";
char* str_129 = "]";
char* str_130 = "// f.";
char* str_131 = " = ";
char* str_132 = "=";
char* str_133 = ", ";
char* str_134 = "prop";
char* str_135 = "push";
char* str_136 = "reverse";
char* str_137 = "ASSetPropFlags";
char str_138[17];
char str_139[17];
char str_140[17];
char str_141[17];
char str_142[17];
char str_143[17];
char str_144[17];
char str_145[17];
char str_146[17];
char str_147[17];
char str_148[17];
char str_149[17];
char str_150[17];
char str_151[17];
char str_152[17];
char str_153[17];
char str_154[17];
char str_155[17];
char str_156[17];
char str_157[17];
char str_158[17];
char str_159[17];
char str_160[17];
char str_161[17];
char str_162[17];
char str_163[17];
char str_164[17];
char str_165[17];

// Maximum string ID for variable array allocation
#define MAX_STRING_ID 166

char* str_166 = "MTASC_MAIN";
char* str_167 = "this";

// Maximum string ID for variable array allocation
#define MAX_STRING_ID 168
