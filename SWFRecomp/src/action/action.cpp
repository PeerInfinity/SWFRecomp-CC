#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#include <action.hpp>

#define VAL(type, x) *((type*) x)

using std::stringstream;
using std::to_string;
using std::endl;

namespace SWFRecomp
{
	SWFAction::SWFAction() : next_str_i(0)
	{
		
	}
	
	void SWFAction::parseActions(Context& context, char*& action_buffer, ofstream& out_script)
	{
		SWFActionType code = SWF_ACTION_CONSTANT_POOL;
		u16 length;
		
		char* action_buffer_start = action_buffer;
		
		std::vector<char*> labels;
		
		// Parse action bytes once to mark labels
		while (code != SWF_ACTION_END_OF_ACTIONS)
		{
			code = (SWFActionType) (u8) action_buffer[0];
			action_buffer += 1;
			length = 0;
			
			if ((code & 0b10000000) != 0)
			{
				length = VAL(u16, action_buffer);
				action_buffer += 2;
			}
			
			switch (code)
			{
				case SWF_ACTION_JUMP:
				case SWF_ACTION_IF:
				{
					s16 offset = VAL(s16, action_buffer);
					labels.push_back(action_buffer + length + ((s64) offset));
					break;
				}
			}
			
			action_buffer += length;
		}
		
		action_buffer = action_buffer_start;
		code = SWF_ACTION_CONSTANT_POOL;
		
		while (code != SWF_ACTION_END_OF_ACTIONS)
		{
			for (const char* ptr : labels)
			{
				if (action_buffer == ptr)
				{
					out_script << "label_" << to_string((s16) (ptr - action_buffer_start)) << ":" << endl;
				}
			}
			
			code = (SWFActionType) (u8) action_buffer[0];
			action_buffer += 1;
			length = 0;
			
			if ((code & 0b10000000) != 0)
			{
				length = VAL(u16, action_buffer);
				action_buffer += 2;
			}
			
			switch (code)
			{
				case SWF_ACTION_END_OF_ACTIONS:
				{
					break;
				}
				
				case SWF_ACTION_STOP:
				{
					out_script << "\t" << "// Stop" << endl
							   << "\t" << "quit_swf = 1;" << endl;
					
					break;
				}
				
				case SWF_ACTION_ADD:
				{
					out_script << "\t" << "// Add" << endl
							   << "\t" << "actionAdd(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_SUBTRACT:
				{
					out_script << "\t" << "// Subtract" << endl
							   << "\t" << "actionSubtract(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_MULTIPLY:
				{
					out_script << "\t" << "// Multiply" << endl
							   << "\t" << "actionMultiply(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_DIVIDE:
				{
					out_script << "\t" << "// Divide" << endl
							   << "\t" << "actionDivide(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_EQUALS:
				{
					out_script << "\t" << "// Equals" << endl
							   << "\t" << "actionEquals(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_LESS:
				{
					out_script << "\t" << "// Less" << endl
							   << "\t" << "actionLess(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_AND:
				{
					out_script << "\t" << "// And" << endl
							   << "\t" << "actionAnd(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_OR:
				{
					out_script << "\t" << "// Or" << endl
							   << "\t" << "actionOr(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_NOT:
				{
					out_script << "\t" << "// Not" << endl
							   << "\t" << "actionNot(stack, sp);" << endl;
					
					break;
				}
				
				case SWF_ACTION_STRING_EQUALS:
				{
					declareEmptyString(context, 17);
					declareEmptyString(context, 17);
					
					out_script << "\t" << "// StringEquals" << endl
							   << "\t" << "actionStringEquals(stack, sp, "
							   << "str_" << to_string(next_str_i - 2) << ", "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;
					
					break;
				}
				
				case SWF_ACTION_STRING_LENGTH:
				{
					declareEmptyString(context, 17);
					
					out_script << "\t" << "// StringLength" << endl
							   << "\t" << "actionStringLength(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;
					
					break;
				}
				

			case SWF_ACTION_STRING_EXTRACT:
			{
				declareEmptyString(context, 17);

				out_script << "\t" << "// StringExtract" << endl
						   << "\t" << "actionStringExtract(stack, sp, str_"
						   << to_string(next_str_i - 1) << ");" << endl;

				break;
			}
				case SWF_ACTION_STRING_ADD:
				{
					declareEmptyString(context, 17);
					declareEmptyString(context, 17);
					
					out_script << "\t" << "// StringAdd" << endl
							   << "\t" << "actionStringAdd(stack, sp, "
							   << "str_" << to_string(next_str_i - 2) << ", "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;
					
					break;
				}
				
				case SWF_ACTION_POP:
				{
					out_script << "\t" << "// Pop" << endl
							   << "\t" << "POP();" << endl;

					break;
				}

				case SWF_ACTION_TO_INTEGER:
				{
					out_script << "\t" << "// ToInteger" << endl
							   << "\t" << "actionToInteger(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_GET_VARIABLE:
				{
					out_script << "\t" << "// GetVariable" << endl
							   << "\t" << "actionGetVariable(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_SET_VARIABLE:
				{
					out_script << "\t" << "// SetVariable" << endl
							   << "\t" << "actionSetVariable(stack, sp);" << endl;

					break;
				}
				
				case SWF_ACTION_TRACE:
				{
					out_script << "\t" << "// Trace" << endl
							   << "\t" << "actionTrace(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_STRING_LESS:
				{
					out_script << "\t" << "// StringLess" << endl
							   << "\t" << "actionStringLess(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_RANDOM_NUMBER:
				{
					out_script << "\t" << "// Random Number" << endl
							   << "\t" << "actionRandomNumber(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_CHAR_TO_ASCII:
				{
					out_script << "\t" << "// CharToAscii" << endl
							   << "\t" << "actionCharToAscii(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_ASCII_TO_CHAR:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// AsciiToChar" << endl
							   << "\t" << "actionAsciiToChar(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_MB_CHAR_TO_ASCII:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// MbCharToAscii" << endl
							   << "\t" << "actionMbCharToAscii(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_GET_TIME:
				{
					out_script << "\t" << "// GetTime" << endl
							   << "\t" << "actionGetTime(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_MB_STRING_LENGTH:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// MbStringLength" << endl
							   << "\t" << "actionMbStringLength(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_MB_ASCII_TO_CHAR:
				{
					declareEmptyString(context, 5);  // Max 4 bytes for UTF-8 + null terminator

					out_script << "\t" << "// MbAsciiToChar" << endl
							   << "\t" << "actionMbAsciiToChar(stack, sp, "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DUPLICATE:
				{
					out_script << "\t" << "// Duplicate" << endl
							   << "\t" << "actionDuplicate(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_MODULO:
				{
					out_script << "\t" << "// Modulo" << endl
							   << "\t" << "actionModulo(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_TARGET_PATH:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// TargetPath" << endl
							   << "\t" << "actionTargetPath(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_ADD2:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Add2 (Type-Aware Addition)" << endl
							   << "\t" << "actionAdd2(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_LESS2:
				{
					out_script << "\t" << "// Less2" << endl
							   << "\t" << "actionLess2(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_TO_NUMBER:
				{
					out_script << "\t" << "// ToNumber" << endl
							   << "\t" << "actionToNumber(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_TO_STRING:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// ToString" << endl
							   << "\t" << "actionToString(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_STACK_SWAP:
				{
					out_script << "\t" << "// Stack Swap" << endl
							   << "\t" << "actionStackSwap(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_INCREMENT:
				{
					out_script << "\t" << "// Increment" << endl
							   << "\t" << "actionIncrement(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_DECREMENT:
				{
					out_script << "\t" << "// Decrement" << endl
							   << "\t" << "actionDecrement(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_AND:
				{
					out_script << "\t" << "// Bit And" << endl
							   << "\t" << "actionBitAnd(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_OR:
				{
					out_script << "\t" << "// Bit Or" << endl
							   << "\t" << "actionBitOr(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_XOR:
				{
					out_script << "\t" << "// BitXor" << endl
							   << "\t" << "actionBitXor(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_LSHIFT:
				{
					out_script << "\t" << "// BitLShift" << endl
							   << "\t" << "actionBitLShift(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_RSHIFT:
				{
					out_script << "\t" << "// BitRShift" << endl
							   << "\t" << "actionBitRShift(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_BIT_URSHIFT:
				{
					out_script << "\t" << "// BitURShift" << endl
							   << "\t" << "actionBitURShift(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_STRICT_EQUALS:
				{
					out_script << "\t" << "// StrictEquals" << endl
							   << "\t" << "actionStrictEquals(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_STRING_GREATER:
				{
					out_script << "\t" << "// StringGreater" << endl
							   << "\t" << "actionStringGreater(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_CONSTANT_POOL:
				{
					action_buffer += length;
					
					break;
				}
				
				case SWF_ACTION_PUSH:
				{
					u64 push_value;
					size_t push_length = 0;
					
					while (push_length < length)
					{
						ActionStackValueType push_type = (ActionStackValueType) action_buffer[push_length];
						push_length += 1;
						
						out_script << "\t" << "// Push ";
						
						switch (push_type)
						{
							case ACTION_STACK_VALUE_STRING:
							{
								out_script << "(String)" << endl;

								push_value = (u64) &action_buffer[push_length];
								declareString(context, (char*) push_value);
								size_t push_str_len = strlen((char*) push_value);
								push_length += push_str_len + 1;

								// Get the actual string ID (handles deduplication)
								size_t str_id = getStringId((char*) push_value);

								out_script << "\t" << "PUSH_STR_ID(str_" << to_string(str_id) << ", "
								           << push_str_len << ", " << str_id << ");" << endl;

								break;
							}
							
							case ACTION_STACK_VALUE_F32:
							{
								out_script << "(float)" << endl;
								
								push_value = (u64) VAL(u32, &action_buffer[push_length]);
								push_length += 4;
								
								char hex_float[11];
								snprintf(hex_float, 11, "0x%08X", (u32) push_value);
								
								out_script << "\t" << "PUSH(ACTION_STACK_VALUE_F32, " << hex_float << ");" << endl;
								
								break;
							}
							
							default:
							{
								EXC_ARG("Undefined push type: %d\n", push_type);
							}
						}
					}
					
					action_buffer += push_length;
					
					break;
				}
				
				case SWF_ACTION_JUMP:
				{
					s16 offset = VAL(s16, action_buffer);
					
					out_script << "\t" << "// Jump" << endl
							   << "\t" << "goto label_" << to_string((s16) (action_buffer + length - action_buffer_start + offset)) << ";" << endl;
					
					action_buffer += length;
					
					break;
				}
				
				case SWF_ACTION_IF:
				{
					s16 offset = VAL(s16, action_buffer);
					
					out_script << "\t" << "// If" << endl
							   << "\t" << "if (evaluateCondition(stack, sp))" << endl
							   << "\t" << "{" << endl
							   << "\t" << "\t" << "goto label_" << to_string((s16) (action_buffer + length - action_buffer_start + offset)) << ";" << endl
							   << "\t" << "}" << endl;
					
					action_buffer += length;
					
					break;
				}
				
				default:
				{
					EXC_ARG("Unimplemented action 0x%02X\n", code);

					break;
				}
			}
		}

		// Generate MAX_STRING_ID constant for runtime initialization
		context.out_script_defs << endl << endl
		                        << "// Maximum string ID for variable array allocation" << endl
		                        << "#define MAX_STRING_ID " << next_str_i << endl;
		context.out_script_decls << endl
		                         << "#define MAX_STRING_ID " << next_str_i << endl;
	}

	void SWFAction::declareVariable(Context& context, char* var_name)
	{
		context.out_script_defs << endl << "#ifndef DEF_VAR_" << var_name << endl
								<< "#define DEF_VAR_" << var_name << endl
								<< "var " << var_name << ";" << endl
								<< "#endif";
		
		context.out_script_decls << endl << "extern var " << var_name << ";";
	}
	
	void SWFAction::declareString(Context& context, char* str)
	{
		// Check if this string was already declared (deduplication)
		auto it = string_to_id.find(str);
		if (it != string_to_id.end())
		{
			// String already exists - don't create duplicate
			return;
		}

		// New string - assign ID and declare
		string_to_id[str] = next_str_i;
		context.out_script_defs << endl << "char* str_" << next_str_i << " = \"" << str << "\";";
		context.out_script_decls << endl << "extern char* str_" << next_str_i << ";";
		next_str_i += 1;
	}
	
	void SWFAction::declareEmptyString(Context& context, size_t size)
	{
		context.out_script_defs << endl << "char str_" << next_str_i << "[" << to_string(size) << "];";
		context.out_script_decls << endl << "extern char str_" << next_str_i << "[];";
		next_str_i += 1;
	}

	size_t SWFAction::getStringId(const char* str)
	{
		auto it = string_to_id.find(str);
		if (it != string_to_id.end())
		{
			return it->second;
		}

		// This shouldn't happen if declareString was called first
		// Return 0 for "no ID" (dynamic strings)
		return 0;
	}

	char SWFAction::actionCodeLookAhead(char* action_buffer, int lookAhead)
	{
		return action_buffer[actionCodeLookAheadIndex(action_buffer, lookAhead)];
	}
	
	size_t SWFAction::actionCodeLookAheadIndex(char* action_buffer, int lookAhead)
	{
		size_t action_buffer_i = 0;
		
		for (int i = 0; i < lookAhead; ++i)
		{
			if ((action_buffer[action_buffer_i] & 0b10000000) != 0)
			{
				action_buffer_i += 1;
				action_buffer_i += VAL(u16, &action_buffer[action_buffer_i]);
				action_buffer_i += 2;
			}
			
			else
			{
				action_buffer_i += 1;
			}
		}
		
		return action_buffer_i;
	}
};