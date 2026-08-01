#pragma once

// ABC byte-stream reader + file parser. Ported from Ruffle's
// swf/src/avm2/read.rs, which is the binary-format ground truth
// (preferred over the Adobe AVM2 Overview where they disagree).

#include <cstddef>
#include <stdexcept>

#include <abc/abc_types.hpp>

namespace SWFRecomp
{
namespace abc
{
	// Thrown by AbcReader / parse functions. `eof` distinguishes "ran off the
	// end of the buffer" (verify error 1020 when it happens mid-method-body)
	// from structurally invalid data (verify error 1011 for bad opcodes).
	class AbcError : public std::runtime_error
	{
	public:
		bool eof;

		// avmplus's own spelling of the same rejection, when we know it:
		// `player_code` is the Error #NNNN and `player_text` the filled
		// message body. Left 0/"" for failures we have no spelling for.
		int player_code = 0;
		std::string player_text;

		explicit AbcError(const std::string& msg, bool is_eof = false)
			: std::runtime_error(msg), eof(is_eof) {}

		AbcError(const std::string& msg, int code, const std::string& text)
			: std::runtime_error(msg), eof(false), player_code(code),
			  player_text(text) {}
	};

	// A load failure as the PLAYER reports it: avmplus raises a catchable
	// VerifyError for a malformed ABC instead of ignoring the tag. `code` 0
	// means we have no avmplus spelling for this failure, and the caller
	// substitutes the generic #1107 "ABC data is corrupt" text.
	struct AbcLoadError
	{
		int code = 0;
		std::string message;  // "Error #NNNN: ..." (the traced form)
	};

	class AbcReader
	{
	public:
		AbcReader(const u8* data, size_t len) : data_(data), len_(len), pos_(0) {}

		size_t pos() const { return pos_; }
		size_t size() const { return len_; }
		void seek(size_t pos) { pos_ = pos; }
		bool atEnd() const { return pos_ >= len_; }

		u8 readU8();
		u16 readU16();  // little-endian (ABC version fields)
		u32 readU30();  // variable-length, 1-5 bytes, 7 bits each (5th byte: low 4 bits)
		s32 readS32();  // same encoding as u30, cast (NOT sign-extended; see read.rs tests)
		s32 readS24();  // 3 bytes little-endian, sign-extended
		double readD64();  // little-endian IEEE 754
		std::string readString();  // u30 length + bytes (UTF-8, may embed NULs)
		void skip(size_t n);

	private:
		const u8* data_;
		size_t len_;
		size_t pos_;
	};

	// Raw (unresolved) bytecode op, one per AVM2 opcode. Operand meaning
	// depends on the opcode; unused fields are zero.
	enum class AbcOpcode : u8
	{
		Bkpt = 0x01,
		Nop = 0x02,
		Throw = 0x03,
		GetSuper = 0x04,
		SetSuper = 0x05,
		Dxns = 0x06,
		DxnsLate = 0x07,
		Kill = 0x08,
		Label = 0x09,
		IfNlt = 0x0c,
		IfNle = 0x0d,
		IfNgt = 0x0e,
		IfNge = 0x0f,
		Jump = 0x10,
		IfTrue = 0x11,
		IfFalse = 0x12,
		IfEq = 0x13,
		IfNe = 0x14,
		IfLt = 0x15,
		IfLe = 0x16,
		IfGt = 0x17,
		IfGe = 0x18,
		IfStrictEq = 0x19,
		IfStrictNe = 0x1a,
		LookupSwitch = 0x1b,
		PushWith = 0x1c,
		PopScope = 0x1d,
		NextName = 0x1e,
		HasNext = 0x1f,
		PushNull = 0x20,
		PushUndefined = 0x21,
		NextValue = 0x23,
		PushByte = 0x24,
		PushShort = 0x25,
		PushTrue = 0x26,
		PushFalse = 0x27,
		PushNaN = 0x28,
		Pop = 0x29,
		Dup = 0x2a,
		Swap = 0x2b,
		PushString = 0x2c,
		PushInt = 0x2d,
		PushUint = 0x2e,
		PushDouble = 0x2f,
		PushScope = 0x30,
		PushNamespace = 0x31,
		HasNext2 = 0x32,
		Li8 = 0x35,
		Li16 = 0x36,
		Li32 = 0x37,
		Lf32 = 0x38,
		Lf64 = 0x39,
		Si8 = 0x3a,
		Si16 = 0x3b,
		Si32 = 0x3c,
		Sf32 = 0x3d,
		Sf64 = 0x3e,
		NewFunction = 0x40,
		Call = 0x41,
		Construct = 0x42,
		CallMethod = 0x43,
		CallStatic = 0x44,
		CallSuper = 0x45,
		CallProperty = 0x46,
		ReturnVoid = 0x47,
		ReturnValue = 0x48,
		ConstructSuper = 0x49,
		ConstructProp = 0x4a,
		CallPropLex = 0x4c,
		CallSuperVoid = 0x4e,
		CallPropVoid = 0x4f,
		Sxi1 = 0x50,
		Sxi8 = 0x51,
		Sxi16 = 0x52,
		ApplyType = 0x53,
		NewObject = 0x55,
		NewArray = 0x56,
		NewActivation = 0x57,
		NewClass = 0x58,
		GetDescendants = 0x59,
		NewCatch = 0x5a,
		FindPropStrict = 0x5d,
		FindProperty = 0x5e,
		FindDef = 0x5f,
		GetLex = 0x60,
		SetProperty = 0x61,
		GetLocal = 0x62,
		SetLocal = 0x63,
		GetGlobalScope = 0x64,
		GetScopeObject = 0x65,
		GetProperty = 0x66,
		GetOuterScope = 0x67,
		InitProperty = 0x68,
		DeleteProperty = 0x6a,
		GetSlot = 0x6c,
		SetSlot = 0x6d,
		GetGlobalSlot = 0x6e,
		SetGlobalSlot = 0x6f,
		ConvertS = 0x70,
		EscXElem = 0x71,
		EscXAttr = 0x72,
		ConvertI = 0x73,
		ConvertU = 0x74,
		ConvertD = 0x75,
		ConvertB = 0x76,
		ConvertO = 0x77,
		CheckFilter = 0x78,
		Coerce = 0x80,
		CoerceB = 0x81,
		CoerceA = 0x82,
		CoerceI = 0x83,
		CoerceD = 0x84,
		CoerceS = 0x85,
		AsType = 0x86,
		AsTypeLate = 0x87,
		CoerceU = 0x88,
		CoerceO = 0x89,
		Negate = 0x90,
		Increment = 0x91,
		IncLocal = 0x92,
		Decrement = 0x93,
		DecLocal = 0x94,
		TypeOf = 0x95,
		Not = 0x96,
		BitNot = 0x97,
		Add = 0xa0,
		Subtract = 0xa1,
		Multiply = 0xa2,
		Divide = 0xa3,
		Modulo = 0xa4,
		LShift = 0xa5,
		RShift = 0xa6,
		URShift = 0xa7,
		BitAnd = 0xa8,
		BitOr = 0xa9,
		BitXor = 0xaa,
		Equals = 0xab,
		StrictEquals = 0xac,
		LessThan = 0xad,
		LessEquals = 0xae,
		GreaterThan = 0xaf,
		GreaterEquals = 0xb0,  // Listed incorrectly in the AVM2 overview
		InstanceOf = 0xb1,
		IsType = 0xb2,
		IsTypeLate = 0xb3,
		In = 0xb4,
		IncrementI = 0xc0,
		DecrementI = 0xc1,
		IncLocalI = 0xc2,
		DecLocalI = 0xc3,
		NegateI = 0xc4,
		AddI = 0xc5,
		SubtractI = 0xc6,
		MultiplyI = 0xc7,
		GetLocal0 = 0xd0,
		GetLocal1 = 0xd1,
		GetLocal2 = 0xd2,
		GetLocal3 = 0xd3,
		SetLocal0 = 0xd4,
		SetLocal1 = 0xd5,
		SetLocal2 = 0xd6,
		SetLocal3 = 0xd7,
		Debug = 0xef,
		DebugLine = 0xf0,
		DebugFile = 0xf1,
		BkptLine = 0xf2,
		Timestamp = 0xf3,
	};

	struct RawOp
	{
		AbcOpcode opcode = AbcOpcode::Nop;
		u32 arg1 = 0;      // first u30 operand (index / register / num_args / line)
		u32 arg2 = 0;      // second u30 operand (num_args / index_register)
		s32 offset = 0;    // s24 branch offset / LookupSwitch default offset
		u32 code_offset = 0;  // byte offset of this op within the method body
		u8 byte_arg = 0;   // GetScopeObject index / Debug register / PushByte value
		bool bool_arg = false;              // Debug is_local_register
		std::vector<s32> case_offsets;      // LookupSwitch cases (count = case_count field + 1)
	};

	// Reads one op at the reader's position. Throws AbcError on unknown
	// opcode (eof=false) or truncated operands (eof=true).
	RawOp readOp(AbcReader& reader);

	// Parses a complete ABC block. Throws AbcError on malformed data.
	void parseAbcFile(AbcReader& reader, AbcFile& out);

	// Non-throwing wrapper: returns false and fills `error` on failure.
	// When `player` is given it also receives the error the PLAYER reports
	// for this file: avmplus rejects a malformed ABC with a catchable
	// VerifyError at load rather than ignoring the tag, so the recompiler
	// emits a throwing stub instead of dropping the DoABC (swf.cpp).
	bool parseAbc(const u8* data, size_t len, AbcFile& out, std::string& error,
	              AbcLoadError* player = nullptr);
}
}
