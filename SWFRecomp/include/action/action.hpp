#pragma once

#include <fstream>
#include <map>

#include <common.h>
#include <stackvalue.hpp>

using std::string;
using std::ofstream;
using std::ostream;

namespace SWFRecomp
{
	enum SWFActionType
	{
		SWF_ACTION_END_OF_ACTIONS = 0x00,
		SWF_ACTION_STOP = 0x07,
		SWF_ACTION_ADD = 0x0A,
		SWF_ACTION_SUBTRACT = 0x0B,
		SWF_ACTION_MULTIPLY = 0x0C,
		SWF_ACTION_DIVIDE = 0x0D,
		SWF_ACTION_EQUALS = 0x0E,
		SWF_ACTION_LESS = 0x0F,
		SWF_ACTION_AND = 0x10,
		SWF_ACTION_OR = 0x11,
		SWF_ACTION_NOT = 0x12,
		SWF_ACTION_STRING_EQUALS = 0x13,
		SWF_ACTION_STRING_LENGTH = 0x14,
		SWF_ACTION_STRING_EXTRACT = 0x15,
		SWF_ACTION_POP = 0x17,
		SWF_ACTION_TO_INTEGER = 0x18,
		SWF_ACTION_GET_VARIABLE = 0x1C,
		SWF_ACTION_SET_VARIABLE = 0x1D,
		SWF_ACTION_STRING_ADD = 0x21,
		SWF_ACTION_TRACE = 0x26,
		SWF_ACTION_STRING_LESS = 0x29,
		SWF_ACTION_RANDOM_NUMBER = 0x30,
		SWF_ACTION_CHAR_TO_ASCII = 0x31,
		SWF_ACTION_ASCII_TO_CHAR = 0x32,
		SWF_ACTION_MB_CHAR_TO_ASCII = 0x33,
		SWF_ACTION_GET_TIME = 0x34,
		SWF_ACTION_MB_STRING_LENGTH = 0x35,
		SWF_ACTION_MB_ASCII_TO_CHAR = 0x36,
		SWF_ACTION_TYPEOF = 0x3C,
		SWF_ACTION_DUPLICATE = 0x3D,
		SWF_ACTION_MODULO = 0x3F,
		SWF_ACTION_INIT_ARRAY = 0x42,
		SWF_ACTION_INIT_OBJECT = 0x43,
		SWF_ACTION_TARGET_PATH = 0x45,
		SWF_ACTION_ADD2 = 0x47,
		SWF_ACTION_LESS2 = 0x48,
		SWF_ACTION_TO_NUMBER = 0x4A,
		SWF_ACTION_TO_STRING = 0x4B,
		SWF_ACTION_STACK_SWAP = 0x4C,
		SWF_ACTION_INCREMENT = 0x50,
		SWF_ACTION_DECREMENT = 0x51,
		SWF_ACTION_BIT_AND = 0x60,
		SWF_ACTION_BIT_OR = 0x61,
		SWF_ACTION_BIT_XOR = 0x62,
		SWF_ACTION_BIT_LSHIFT = 0x63,
		SWF_ACTION_BIT_RSHIFT = 0x64,
		SWF_ACTION_BIT_URSHIFT = 0x65,
		SWF_ACTION_STRICT_EQUALS = 0x66,
		SWF_ACTION_GREATER = 0x67,
		SWF_ACTION_STRING_GREATER = 0x68,
		SWF_ACTION_CONSTANT_POOL = 0x88,
		SWF_ACTION_PUSH = 0x96,
		SWF_ACTION_JUMP = 0x99,
		SWF_ACTION_IF = 0x9D
	};
	
	class SWFAction
	{
	public:
		size_t next_str_i;
		std::map<std::string, size_t> string_to_id;  // Track declared strings for deduplication

		SWFAction();

		void parseActions(Context& context, char*& action_buffer, ofstream& out_script);
		void declareVariable(Context& context, char* var_name);
		void declareString(Context& context, char* str);
		void declareEmptyString(Context& context, size_t size);
		size_t getStringId(const char* str);  // Get ID for a previously declared string
		char actionCodeLookAhead(char* action_buffer, int lookAhead);
		size_t actionCodeLookAheadIndex(char* action_buffer, int lookAhead);
	};
};