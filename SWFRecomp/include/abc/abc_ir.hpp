#pragma once

// Resolved internal IR, modeled on Ruffle's core/src/avm2/op.rs with one
// structural difference required for AOT compilation: where Ruffle's Op holds
// GC references to runtime Multiname/Class/Method objects, our IR holds
// STATIC TABLE INDICES into the owning AbcFile (constant pool, method table,
// class table). Codegen (Stage 2) emits those tables as static C data.
//
// Translation rules mirrored from Ruffle's verify.rs translate_op:
//  - PushByte/PushShort fold to PushInt with a resolved immediate.
//  - GetLocal0-3 / SetLocal0-3 fold to GetLocal/SetLocal { index }.
//  - Convert{B,D,I,U} merge into Coerce{B,D,I,U} (identical semantics).
//  - Label becomes Nop (targets are op indices after verification).
//  - GetLex splits into FindPropStrict + GetPropertyStatic.
//  - CallSuperVoid splits into CallSuper + Pop.
//  - GetGlobalSlot splits into GetGlobalScope + GetSlot.
//  - Compare-branches (IfEq..IfStrictNe, IfLt..IfNge) split into the compare
//    op + IfTrue/IfFalse.
//  - GetProperty/SetProperty specialize to Static/Fast/Slow on multiname
//    laziness (Fast: lazy name, static ns set containing the public
//    namespace, not an attribute).
//  - GetSlot/SetSlot/SetGlobalSlot indices become 0-based.
//  - Branch offsets become absolute op indices (`target`).
//
// Deliberate divergences from Ruffle (documented so Stage 2 knows):
//  - GetGlobalScope stays a distinct op. Ruffle lowers it to GetScopeObject 0
//    or GetOuterScope 0 using the *runtime* outer-scope stack; an AOT pass
//    can only do that with per-callsite context, so we defer to codegen.
//  - PushNaN stays a distinct op (Ruffle rewrites to PushDouble { NAN };
//    our PushDouble carries a doubles-pool index and NaN has no pool entry).
//  - Coerce/AsType/IsType keep a multiname index (Ruffle resolves to a Class
//    at verify time; class resolution is a Stage 2+ concern).

#include <cstdint>
#include <string>
#include <vector>

#include <abc/abc_types.hpp>

namespace SWFRecomp
{
namespace abc
{
	enum class IrOpcode : u16
	{
		Add,            // pop2 push1
		AddI,
		ApplyType,      // arg2 = num_types
		AsType,         // arg1 = multiname index (static)
		AsTypeLate,
		BitAnd,
		BitNot,
		BitOr,
		BitXor,
		Bkpt,
		BkptLine,       // arg1 = line
		Call,           // arg2 = num_args
		CallProperty,   // arg1 = multiname index, arg2 = num_args
		CallPropLex,    // arg1 = multiname index, arg2 = num_args
		CallPropVoid,   // arg1 = multiname index, arg2 = num_args
		CallStatic,     // arg1 = method index, arg2 = num_args
		CallSuper,      // arg1 = multiname index, arg2 = num_args
		CheckFilter,
		Coerce,         // arg1 = multiname index (static)
		CoerceA,
		CoerceB,
		CoerceD,
		CoerceI,
		CoerceO,
		CoerceS,
		CoerceU,
		Construct,      // arg2 = num_args
		ConstructProp,  // arg1 = multiname index, arg2 = num_args
		ConstructSuper, // arg2 = num_args
		ConvertO,
		ConvertS,
		Debug,          // arg1 = register-name string index, byte_arg = register, bool_arg = is_local
		DebugFile,      // arg1 = string index
		DebugLine,      // arg1 = line
		DecLocal,       // arg1 = local index
		DecLocalI,
		Decrement,
		DecrementI,
		DeleteProperty, // arg1 = multiname index
		Divide,
		Dup,
		Dxns,           // arg1 = string index
		DxnsLate,
		Equals,
		EscXAttr,
		EscXElem,
		FindDef,        // arg1 = multiname index (static)
		FindProperty,   // arg1 = multiname index
		FindPropStrict, // arg1 = multiname index
		GetDescendants, // arg1 = multiname index
		GetGlobalScope, // see divergence note above
		GetGlobalSlot,  // arg1 = slot index (0-based); only from SetGlobalSlot-adjacent paths
		GetLocal,       // arg1 = local index
		GetOuterScope,  // arg1 = scope index
		GetPropertyStatic,  // arg1 = multiname index
		GetPropertyFast,    // arg1 = multiname index
		GetPropertySlow,    // arg1 = multiname index
		GetScopeObject, // arg1 = scope index
		GetSlot,        // arg1 = slot index (0-based)
		GetSuper,       // arg1 = multiname index
		GreaterEquals,
		GreaterThan,
		HasNext,
		HasNext2,       // arg1 = object register, arg2 = index register
		IfFalse,        // target = op index
		IfTrue,         // target = op index
		In,
		IncLocal,       // arg1 = local index
		IncLocalI,
		Increment,
		IncrementI,
		InitProperty,   // arg1 = multiname index
		InstanceOf,
		IsType,         // arg1 = multiname index (static)
		IsTypeLate,
		Jump,           // target = op index
		Kill,           // arg1 = local index
		LessEquals,
		LessThan,
		Lf32,
		Lf64,
		Li16,
		Li32,
		Li8,
		LookupSwitch,   // target = default op index, switch_targets = case op indices
		LShift,
		Modulo,
		Multiply,
		MultiplyI,
		Negate,
		NegateI,
		NewActivation,
		NewArray,       // arg2 = num_args
		NewCatch,       // arg1 = exception index
		NewClass,       // arg1 = class table index
		NewFunction,    // arg1 = method table index
		NewObject,      // arg2 = num_args (pairs)
		NextName,
		NextValue,
		Nop,
		Not,
		Pop,
		PopScope,
		PushDouble,     // arg1 = doubles pool index
		PushFalse,
		PushInt,        // imm = resolved value (from PushByte/PushShort/int pool)
		PushNamespace,  // arg1 = namespace pool index
		PushNaN,        // see divergence note above
		PushNull,
		PushScope,
		PushString,     // arg1 = string pool index
		PushTrue,
		PushUint,       // arg1 = uint pool index
		PushUndefined,
		PushWith,
		ReturnValue,
		ReturnVoid,
		RShift,
		SetGlobalSlot,  // arg1 = slot index (0-based)
		SetLocal,       // arg1 = local index
		SetPropertyStatic,  // arg1 = multiname index
		SetPropertyFast,    // arg1 = multiname index
		SetPropertySlow,    // arg1 = multiname index
		SetSlot,        // arg1 = slot index (0-based)
		SetSuper,       // arg1 = multiname index
		Sf32,
		Sf64,
		Si16,
		Si32,
		Si8,
		StrictEquals,
		Subtract,
		SubtractI,
		Swap,
		Sxi1,
		Sxi16,
		Sxi8,
		Throw,
		TypeOf,
		Timestamp,
		URShift,
	};

	struct IrOp
	{
		IrOpcode op = IrOpcode::Nop;
		u32 arg1 = 0;      // primary operand — see per-opcode comments
		u32 arg2 = 0;      // secondary operand (num_args / index register)
		s32 imm = 0;       // resolved immediate (PushInt)
		u32 target = 0;    // branch target as an op index (IfTrue/IfFalse/Jump/LookupSwitch default)
		u8 byte_arg = 0;
		bool bool_arg = false;
		std::vector<u32> switch_targets;  // LookupSwitch case targets (op indices)
	};

	// Exception table entry with offsets resolved to op indices.
	struct IrException
	{
		u32 from_op = 0;
		u32 to_op = 0;
		u32 target_op = 0;
		u32 type_name = 0;      // multiname pool index (0 = catch-all)
		u32 variable_name = 0;  // multiname pool index (0 = unnamed)
		// False when no reachable throwing op is covered by this entry: kept
		// (NewCatch can still reference it) but offsets are dummies.
		bool active = false;
	};

	struct IrMethod
	{
		u32 method_index = 0;  // AbcFile method table index
		u32 body_index = 0;    // AbcFile method body table index
		std::vector<IrOp> ops;
		std::vector<IrException> exceptions;
		// Results of the static stack/scope-depth checks.
		u32 computed_max_stack = 0;
		u32 computed_max_scope = 0;   // local scope pushes (relative to init_scope_depth)
	};

	// A verification failure. `code` is the avmplus VerifyError number
	// (1011 invalid opcode, 1020 code falls off end, 1021 bad jump target,
	// 1023/1024 stack overflow/underflow, 1025 bad local register,
	// 1026 bad slot, 1030 stack depth unbalanced, 1031 scope depth
	// unbalanced, 1043 invalid code length, 1054 bad exception range,
	// 1072/1051 callmethod, 1078 illegal early binding, 1107 broken data,
	// 1113 newactivation without flag, 1114 dxns without flag,
	// 1124 hasnext2 register conflict, 1032 cpool index out of range).
	struct VerifyError
	{
		int code = 0;
		// avmplus's own wording, always "Error #<code>: <text>". Both
		// Error.toString() and the errorID getter are derived from this exact
		// string at runtime (avm2_error.c parses the "Error #NNNN: " prefix
		// back out), so scripts that catch a VerifyError see it verbatim.
		std::string message;
		// Our internal diagnostic wording, for stderr only. avmplus collapses
		// whole families of distinct faults onto one message (every branch
		// problem is #1021, every handler-range problem is #1054), so this is
		// what you actually want when debugging the recompiler.
		std::string detail;
	};
}
}
