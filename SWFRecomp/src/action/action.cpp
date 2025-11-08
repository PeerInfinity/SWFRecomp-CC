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
		// Clear constant pool at script boundary (per SWF spec)
		constant_pool.clear();

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

				case SWF_ACTION_WAIT_FOR_FRAME:
				{
					// Skip past frame (u16) and skip_count (u8)
					u16 frame = VAL(u16, action_buffer);
					u8 skip_count = VAL(u8, action_buffer + 2);

					// Calculate skip target by parsing ahead through skip_count actions
					char* skip_ptr = action_buffer + length;
					for (u8 i = 0; i < skip_count && *skip_ptr != SWF_ACTION_END_OF_ACTIONS; i++)
					{
						u8 next_code = *skip_ptr;
						skip_ptr += 1;

						if ((next_code & 0b10000000) != 0)
						{
							u16 next_length = VAL(u16, skip_ptr);
							skip_ptr += 2;
							skip_ptr += next_length;
						}
					}

					// Add skip target as a label
					labels.push_back(skip_ptr);
					break;
				}

			case SWF_ACTION_WAIT_FOR_FRAME2:
			{
				// Calculate skip target by parsing ahead skip_count actions
				u8 skip_count = (u8) action_buffer[0];

				// Parse ahead to find where we'd land after skipping
				char* skip_ptr = action_buffer + length;
				for (u8 i = 0; i < skip_count && skip_ptr < action_buffer_start + 65536; i++)
				{
					SWFActionType skip_code = (SWFActionType) (u8) skip_ptr[0];
					skip_ptr += 1;

					u16 skip_length = 0;
					if ((skip_code & 0b10000000) != 0)
					{
						skip_length = VAL(u16, skip_ptr);
						skip_ptr += 2;
					}

					skip_ptr += skip_length;
				}

				// Mark the skip target as a label
				labels.push_back(skip_ptr);
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

				case SWF_ACTION_NEXT_FRAME:
				{
					out_script << "\t" << "// NextFrame" << endl
							   << "\t" << "actionNextFrame();" << endl;

					break;
				}

				case SWF_ACTION_PREV_FRAME:
				{
					out_script << "\t" << "// Prev Frame" << endl
							   << "\t" << "actionPrevFrame(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_PLAY:
				{
					out_script << "\t" << "// Play" << endl
							   << "\t" << "actionPlay();" << endl;

					break;
				}

				case SWF_ACTION_STOP:
				{
					out_script << "\t" << "// Stop" << endl
							   << "\t" << "is_playing = 0;" << endl;

					break;
				}

				case SWF_ACTION_TOGGLE_QUALITY:
				{
					out_script << "\t" << "// Toggle Quality" << endl
							   << "\t" << "actionToggleQuality(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_STOP_SOUNDS:
				{
					out_script << "\t" << "// Stop Sounds" << endl
							   << "\t" << "actionStopSounds(stack, sp);" << endl;

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

				case SWF_ACTION_GET_PROPERTY:
				{
					out_script << "\t" << "// GetProperty" << endl
							   << "\t" << "actionGetProperty(stack, sp);" << endl;

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

				case SWF_ACTION_SET_TARGET2:
				{
					out_script << "\t" << "// SetTarget2" << endl
							   << "\t" << "actionSetTarget2(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_SET_PROPERTY:
				{
					out_script << "\t" << "// SetProperty" << endl
							   << "\t" << "actionSetProperty(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_CLONE_SPRITE:
				{
					out_script << "\t" << "// CloneSprite" << endl
							   << "\t" << "actionCloneSprite(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_REMOVE_SPRITE:
				{
					out_script << "\t" << "// RemoveSprite" << endl
						   << "\t" << "actionRemoveSprite(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_TRACE:
				{
					out_script << "\t" << "// Trace" << endl
							   << "\t" << "actionTrace(stack, sp);" << endl;

				break;
				}

				case SWF_ACTION_START_DRAG:
				{
					out_script << "\t" << "// StartDrag" << endl
							   << "\t" << "actionStartDrag(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_END_DRAG:
				{
					out_script << "\t" << "// End Drag" << endl
							   << "\t" << "actionEndDrag(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_CAST_OP:
				{
					out_script << "\t" << "// CastOp" << endl
							   << "\t" << "actionCastOp(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_STRING_LESS:
				{
					out_script << "\t" << "// StringLess" << endl
							   << "\t" << "actionStringLess(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_THROW:
				{
					out_script << "\t" << "// Throw" << endl
							   << "\t" << "actionThrow(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_IMPLEMENTS_OP:
				{
					out_script << "\t" << "// ImplementsOp" << endl
							   << "\t" << "actionImplementsOp(stack, sp);" << endl;

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

				case SWF_ACTION_DELETE:
				{
					out_script << "\t" << "// Delete" << endl
							   << "\t" << "actionDelete(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_DELETE2:
				{
					declareEmptyString(context, 256);  // Buffer for variable name operations

					out_script << "\t" << "// Delete2" << endl
							   << "\t" << "actionDelete2(stack, sp, "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DEFINE_LOCAL:
				{
					out_script << "\t" << "// DefineLocal" << endl
							   << "\t" << "actionDefineLocal(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_TYPEOF:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Typeof" << endl
							   << "\t" << "actionTypeof(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DUPLICATE:
				{
					out_script << "\t" << "// Duplicate" << endl
							   << "\t" << "actionDuplicate(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_RETURN:
				{
					out_script << "\t" << "// Return" << endl
							   << "\t" << "{" << endl
							   << "\t\t" << "ActionVar ret_val;" << endl
							   << "\t\t" << "popVar(stack, sp, &ret_val);" << endl
							   << "\t\t" << "return ret_val;" << endl
							   << "\t" << "}" << endl;

					break;
				}

				case SWF_ACTION_MODULO:
				{
					out_script << "\t" << "// Modulo" << endl
							   << "\t" << "actionModulo(stack, sp);" << endl;

					break;
				}

			case SWF_ACTION_NEW_OBJECT:
			{
				out_script << "\t" << "// NewObject" << endl
						   << "\t" << "actionNewObject(stack, sp);" << endl;

				break;
			}

			case SWF_ACTION_INIT_ARRAY:
			{
				out_script << "\t" << "// InitArray" << endl
						   << "\t" << "actionInitArray(stack, sp);" << endl;

				break;
			}

			case SWF_ACTION_INIT_OBJECT:
			{
				out_script << "\t" << "// InitObject" << endl
						   << "\t" << "actionInitObject(stack, sp);" << endl;

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

				case SWF_ACTION_EQUALS2:
				{
					out_script << "\t" << "// Equals2" << endl
							   << "\t" << "actionEquals2(stack, sp);" << endl;

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

				case SWF_ACTION_GET_MEMBER:
				{
					out_script << "\t" << "// GetMember" << endl
							   << "\t" << "actionGetMember(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_SET_MEMBER:
				{
					out_script << "\t" << "// SetMember" << endl
							   << "\t" << "actionSetMember(stack, sp);" << endl;

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

				case SWF_ACTION_INSTANCEOF:
				{
					out_script << "\t" << "// InstanceOf" << endl
							   << "\t" << "actionInstanceOf(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_ENUMERATE2:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Enumerate2" << endl
							   << "\t" << "actionEnumerate2(stack, sp, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

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

				case SWF_ACTION_EXTENDS:
				{
					out_script << "\t" << "// Extends - Set up prototype chain for inheritance" << endl
							   << "\t" << "actionExtends(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_GOTO_FRAME:
				{
					// Read the frame index from the action record
					u16 frame_index = VAL(u16, action_buffer);

					out_script << "	" << "// GotoFrame: " << frame_index << endl
							   << "	" << "actionGotoFrame(stack, sp, " << frame_index << ");" << endl;

					action_buffer += length;
					break;
				}

			case SWF_ACTION_GET_URL:
			{
				// Read UrlString (null-terminated)
				char* url_string = action_buffer;
				size_t url_len = strlen(url_string);
				action_buffer += url_len + 1;

				// Read TargetString (null-terminated)
				char* target_string = action_buffer;
				size_t target_len = strlen(target_string);
				action_buffer += target_len + 1;

				out_script << "\t" << "// GetURL: \"" << url_string
						   << "\" -> \"" << target_string << "\"" << endl
						   << "\t" << "actionGetURL(stack, sp, "
						   << "\"" << url_string << "\", "
						   << "\"" << target_string << "\");" << endl;

				break;
			}

				case SWF_ACTION_STORE_REGISTER:
				{
					// Read register number from bytecode
					u8 register_num = (u8) action_buffer[0];

					out_script << "\t" << "// StoreRegister " << (int)register_num << endl
							   << "\t" << "actionStoreRegister(stack, sp, " << (int)register_num << ");" << endl;

					action_buffer += length;
					break;
				}

				case SWF_ACTION_CONSTANT_POOL:
				{
					// Read count of strings (16-bit)
					u16 count = VAL(u16, action_buffer);
					action_buffer += 2;

					out_script << "\t" << "// ConstantPool (" << count << " strings)" << endl;

					// Read each null-terminated string
					for (u16 i = 0; i < count; i++)
					{
						char* str = action_buffer;
						size_t str_len = strlen(str);

						// Declare the string
						declareString(context, str);
						size_t str_id = getStringId(str);

						// Add to constant pool
						constant_pool.push_back(str_id);

						// Advance past string and null terminator
						action_buffer += str_len + 1;
					}

					break;
				}

				case SWF_ACTION_WAIT_FOR_FRAME:
				{
					// Read frame number (u16) and skip count (u8)
					u16 frame = VAL(u16, action_buffer);
					u8 skip_count = VAL(u8, action_buffer + 2);

					// Calculate skip target (same logic as first pass)
					char* skip_ptr = action_buffer + length;
					for (u8 i = 0; i < skip_count && *skip_ptr != SWF_ACTION_END_OF_ACTIONS; i++)
					{
						u8 next_code = *skip_ptr;
						skip_ptr += 1;

						if ((next_code & 0b10000000) != 0)
						{
							u16 next_length = VAL(u16, skip_ptr);
							skip_ptr += 2;
							skip_ptr += next_length;
						}
					}

					s16 skip_label = (s16)(skip_ptr - action_buffer_start);

					out_script << "\t" << "// WaitForFrame: frame=" << frame
							   << ", skip=" << (int)skip_count << " actions" << endl
							   << "\t" << "if (!actionWaitForFrame(stack, sp, " << frame << "))" << endl
							   << "\t" << "{" << endl
							   << "\t" << "\t" << "goto label_" << skip_label << ";" << endl
							   << "\t" << "}" << endl;

					action_buffer += length;

					break;
				}

				case SWF_ACTION_SET_TARGET:
				{
					// Read TargetName (null-terminated string)
					std::string target_name;
					char ch;
					while ((ch = *action_buffer++) != '\0') {
						target_name += ch;
					}

					// Escape quotes in target name for C string
					std::string escaped_target = "";
					for (char c : target_name) {
						if (c == '"' || c == '\\') {
							escaped_target += '\\';
						}
						escaped_target += c;
					}

					out_script << "\t" << "// SetTarget: \"" << escaped_target << "\"" << endl
							   << "\t" << "actionSetTarget(stack, sp, \"" << escaped_target << "\");" << endl;

					break;
				}

				case SWF_ACTION_GOTO_LABEL:
				{
					// Read Label (null-terminated string)
					std::string label;
					char ch;
					char* label_ptr = action_buffer;
					while ((ch = *label_ptr++) != '\0') {
						label += ch;
					}

					out_script << "\t" << "// GoToLabel: \"" << label << "\"" << endl
							   << "\t" << "actionGoToLabel(stack, sp, \"" << label << "\");" << endl;

					action_buffer += length;
					break;
				}

			case SWF_ACTION_WAIT_FOR_FRAME2:
			{
				// Read skip count parameter
				u8 skip_count = (u8) action_buffer[0];

				// Calculate skip target by parsing ahead skip_count actions
				char* skip_ptr = action_buffer + length;
				for (u8 i = 0; i < skip_count && skip_ptr < action_buffer_start + 65536; i++)
				{
					SWFActionType skip_code = (SWFActionType) (u8) skip_ptr[0];
					skip_ptr += 1;

					u16 skip_length = 0;
					if ((skip_code & 0b10000000) != 0)
					{
						skip_length = VAL(u16, skip_ptr);
						skip_ptr += 2;
					}

					skip_ptr += skip_length;
				}

				out_script << "\t" << "// WaitForFrame2: skip=" << (int)skip_count << endl
						   << "\t" << "if (!actionWaitForFrame2(stack, sp)) {" << endl
						   << "\t\t" << "// Frame not loaded, skip next " << (int)skip_count << " action(s)" << endl
						   << "\t\t" << "goto label_" << to_string((s16) (skip_ptr - action_buffer_start)) << ";" << endl
						   << "\t" << "}" << endl;

				action_buffer += length;
				break;
			}

			case SWF_ACTION_DEFINE_FUNCTION2:
			{
				// Parse function metadata
				char* func_name = action_buffer;
				size_t name_len = strlen(func_name);
				action_buffer += name_len + 1;

				u16 num_params = VAL(u16, action_buffer);
				action_buffer += 2;

				u8 register_count = VAL(u8, action_buffer);
				action_buffer += 1;

				u16 flags = VAL(u16, action_buffer);
				action_buffer += 2;

				// Parse parameters
				std::vector<std::pair<u8, std::string>> params;
				for (u16 i = 0; i < num_params; i++)
				{
					u8 reg = VAL(u8, action_buffer);
					action_buffer += 1;

					char* param_name = action_buffer;
					size_t param_len = strlen(param_name);
					action_buffer += param_len + 1;

					params.push_back(std::make_pair(reg, std::string(param_name)));
				}

				u16 code_size = VAL(u16, action_buffer);
				action_buffer += 2;

				// Generate unique function ID
				static int func2_counter = 0;
				std::string func_id = std::string("func2_") + (name_len > 0 ? std::string(func_name) : "anonymous") + "_" + std::to_string(func2_counter++);

			// Add function declaration to header
			context.out_script_decls << endl << "ActionVar " << func_id << "(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);" << endl;
				// Generate function definition in out_script_defs
				context.out_script_defs << endl << endl
					<< "// DefineFunction2: " << (name_len > 0 ? func_name : "(anonymous)") << endl
					<< "ActionVar " << func_id << "(char* stack, u32* sp, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)" << endl
					<< "{" << endl;

				// Initialize local registers
				if (register_count > 0)
				{
					context.out_script_defs << "\tActionVar regs[" << (int)register_count << "];" << endl;
					context.out_script_defs << "\tmemset(regs, 0, sizeof(regs));" << endl;
				}

				// Parse flags
				bool preload_this = (flags & 0x0001);
				bool preload_arguments = (flags & 0x0002);
				bool preload_super = (flags & 0x0004);
				bool preload_root = (flags & 0x0008);
				bool preload_parent = (flags & 0x0010);
				bool preload_global = (flags & 0x0020);
				bool suppress_this = (flags & 0x0080);
				bool suppress_arguments = (flags & 0x0100);
				bool suppress_super = (flags & 0x0200);

				// Preload special variables into registers
				int next_reg = 1; // Register 0 is reserved

				if (preload_this && !suppress_this)
				{
					context.out_script_defs << "\t// Preload 'this' into register " << next_reg << endl;
					context.out_script_defs << "\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_OBJECT;" << endl;
					context.out_script_defs << "\tregs[" << next_reg << "].data.numeric_value = (u64)this_obj;" << endl;
					next_reg++;
				}

				if (preload_arguments && !suppress_arguments)
				{
					context.out_script_defs << "\t// Preload 'arguments' into register " << next_reg << endl;
					context.out_script_defs << "\t// TODO: Create arguments object" << endl;
					next_reg++;
				}

				if (preload_super && !suppress_super)
				{
					context.out_script_defs << "\t// Preload 'super' into register " << next_reg << endl;
					context.out_script_defs << "\t// TODO: Create super reference" << endl;
					next_reg++;
				}

				// Bind parameters to registers or variables
				for (size_t i = 0; i < params.size(); i++)
				{
					if (params[i].first == 0)
					{
						// Variable parameter
						context.out_script_defs << "\tif (" << i << " < arg_count) {" << endl;
						context.out_script_defs << "\t\tsetVariableByName(\"" << params[i].second << "\", &args[" << i << "]);" << endl;
						context.out_script_defs << "\t}" << endl;
					}
					else
					{
						// Register parameter
						context.out_script_defs << "\tif (" << i << " < arg_count) {" << endl;
						context.out_script_defs << "\t\tregs[" << (int)params[i].first << "] = args[" << i << "];" << endl;
						context.out_script_defs << "\t}" << endl;
					}
				}

				// Parse function body recursively
				context.out_script_defs << endl << "\t// Function body (" << code_size << " bytes)" << endl;

				// Save the function body boundaries
				char* func_body_start = action_buffer;
				char* func_body_end = action_buffer + code_size;

				// Create a temporary buffer for the function body that ends with END_OF_ACTIONS
				// This ensures parseActions stops at the right place
				char* temp_buffer = (char*)malloc(code_size + 1);
				memcpy(temp_buffer, func_body_start, code_size);
				temp_buffer[code_size] = 0x00; // Add END_OF_ACTIONS marker

				char* temp_ptr = temp_buffer;
				parseActions(context, temp_ptr, context.out_script_defs);
				free(temp_buffer);

				// Advance the actual buffer past the function body
				action_buffer = func_body_end;

				context.out_script_defs << endl << "\t// Return undefined if no explicit return" << endl;
				context.out_script_defs << "\tActionVar ret;" << endl;
				context.out_script_defs << "\tret.type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
				context.out_script_defs << "\tret.data.numeric_value = 0;" << endl;
				context.out_script_defs << "\treturn ret;" << endl;
				context.out_script_defs << "}" << endl;

				// Generate runtime call to register function
				out_script << "\t// DefineFunction2: " << (name_len > 0 ? func_name : "(anonymous)") << endl;
				out_script << "\tactionDefineFunction2(stack, sp, \"" << (name_len > 0 ? func_name : "") << "\", "
						   << func_id << ", " << num_params << ", " << (int)register_count << ", " << flags << ");" << endl;

				// action_buffer has already been advanced by parseActions
				break;
			}

			case SWF_ACTION_TRY:
			{
				// Read flags byte
				u8 flags = VAL(u8, action_buffer);
				action_buffer += 1;

				bool catch_in_register = (flags & 0x04) != 0;
				bool has_finally = (flags & 0x02) != 0;
				bool has_catch = (flags & 0x01) != 0;

				// Read block sizes
				u16 try_size = VAL(u16, action_buffer);
				action_buffer += 2;
				u16 catch_size = VAL(u16, action_buffer);
				action_buffer += 2;
				u16 finally_size = VAL(u16, action_buffer);
				action_buffer += 2;

				// Read catch name or register
				std::string catch_name;
				u8 catch_register = 0;
				if (has_catch)
				{
					if (catch_in_register)
					{
						catch_register = VAL(u8, action_buffer);
						action_buffer += 1;
					}
					else
					{
						catch_name = std::string(action_buffer);
						action_buffer += catch_name.length() + 1; // +1 for null terminator
					}
				}

				// Store positions for each block
				char* try_body = action_buffer;
				char* catch_body = try_body + try_size;
				char* finally_body = catch_body + catch_size;
				char* after_try = finally_body + finally_size;

				// Generate try-catch-finally structure
				out_script << "\t" << "// Try-Catch-Finally" << endl;
				out_script << "\t" << "actionTryBegin(stack, sp);" << endl;
				out_script << "\t" << "if (actionTryExecute(stack, sp)) {" << endl;

				// Translate try block
				out_script << "\t\t" << "// Try block" << endl;
				if (try_size > 0)
				{
					char* temp_buffer = (char*)malloc(try_size + 1);
					memcpy(temp_buffer, try_body, try_size);
					temp_buffer[try_size] = 0x00; // Add END_OF_ACTIONS marker
					char* temp_ptr = temp_buffer;

					// Temporarily increase indentation for nested block
					std::string indent_backup = "\t";
					parseActions(context, temp_ptr, out_script);
					free(temp_buffer);
				}

				if (has_catch)
				{
					out_script << "\t" << "} else {" << endl;
					out_script << "\t\t" << "// Catch block" << endl;

					if (catch_in_register)
					{
						out_script << "\t\t" << "actionCatchToRegister(stack, sp, " << (int)catch_register << ");" << endl;
					}
					else
					{
						out_script << "\t\t" << "actionCatchToVariable(stack, sp, \"" << catch_name << "\");" << endl;
					}

					// Translate catch block
					if (catch_size > 0)
					{
						char* temp_buffer = (char*)malloc(catch_size + 1);
						memcpy(temp_buffer, catch_body, catch_size);
						temp_buffer[catch_size] = 0x00; // Add END_OF_ACTIONS marker
						char* temp_ptr = temp_buffer;
						parseActions(context, temp_ptr, out_script);
						free(temp_buffer);
					}
				}

				out_script << "\t" << "}" << endl;

				if (has_finally)
				{
					out_script << "\t" << "// Finally block" << endl;

					// Translate finally block
					if (finally_size > 0)
					{
						char* temp_buffer = (char*)malloc(finally_size + 1);
						memcpy(temp_buffer, finally_body, finally_size);
						temp_buffer[finally_size] = 0x00; // Add END_OF_ACTIONS marker
						char* temp_ptr = temp_buffer;
						parseActions(context, temp_ptr, out_script);
						free(temp_buffer);
					}
				}

				out_script << "\t" << "actionTryEnd(stack, sp);" << endl;

				// Advance action_buffer past all try-catch-finally blocks
				action_buffer = after_try;

				break;
			}

				case SWF_ACTION_WITH:
				{
					// Read block size from bytecode
					u16 block_size = VAL(u16, action_buffer);
					action_buffer += 2;

					// Store the end position of the with block
					char* block_end = action_buffer + block_size;

					// Emit actionWithStart to push object onto scope chain
					out_script << "\t" << "// WITH block (size=" << block_size << ")" << endl;
					out_script << "\t" << "actionWithStart(stack, sp);" << endl;
					out_script << "\t" << "{" << endl; // C scope for clarity

					// Recursively parse the actions within the with block
					parseActions(context, action_buffer, out_script);

					// Emit actionWithEnd to pop object from scope chain
					out_script << "\t" << "}" << endl;
					out_script << "\t" << "actionWithEnd(stack, sp);" << endl;

					// Move action_buffer to the end of the block
					action_buffer = block_end;

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
							

						case ACTION_STACK_VALUE_REGISTER:
						{
							u8 register_num = (u8) action_buffer[push_length];
							push_length += 1;

							out_script << "(Register " << (int)register_num << ")" << endl;
							out_script << "\t" << "actionPushRegister(stack, sp, " << (int)register_num << ");" << endl;

							break;
						}

						case 8:  // Constant pool index (8-bit)
						{
							u8 pool_index = (u8) action_buffer[push_length];
							push_length += 1;

							if (pool_index >= constant_pool.size())
							{
								fprintf(stderr, "Constant pool index %d out of range (pool size: %zu)\n",
									pool_index, constant_pool.size());
								throw std::exception();
							}

							size_t str_id = constant_pool[pool_index];

							out_script << "(ConstantPool8[" << (int)pool_index << "])" << endl;
							out_script << "\t" << "PUSH_STR_ID(str_" << to_string(str_id) << ", "
									   << "strlen(str_" << to_string(str_id) << "), " << str_id << ");" << endl;

							break;
						}

						case 9:  // Constant pool index (16-bit)
						{
							u16 pool_index = VAL(u16, &action_buffer[push_length]);
							push_length += 2;

							if (pool_index >= constant_pool.size())
							{
								fprintf(stderr, "Constant pool index %d out of range (pool size: %zu)\n",
									pool_index, constant_pool.size());
								throw std::exception();
							}

							size_t str_id = constant_pool[pool_index];

							out_script << "(ConstantPool16[" << (int)pool_index << "])" << endl;
							out_script << "\t" << "PUSH_STR_ID(str_" << to_string(str_id) << ", "
									   << "strlen(str_" << to_string(str_id) << "), " << str_id << ");" << endl;

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

				case SWF_ACTION_CALL:
				{
					out_script << "\t" << "// Call" << endl
							   << "\t" << "actionCall(stack, sp);" << endl;

					break;
				}

				case SWF_ACTION_GOTO_FRAME2:
				{
					// Parse opcode data byte
					u8 flags = VAL(u8, action_buffer);

					u8 play_flag = flags & 0x01;
					u8 scene_bias_flag = (flags >> 1) & 0x01;

					u16 scene_bias = 0;
					if (scene_bias_flag) {
						scene_bias = VAL(u16, action_buffer + 1);
					}

					out_script << "\t" << "// GotoFrame2 (play=" << (int)play_flag
							   << ", sceneBias=" << scene_bias << ")" << endl
							   << "\t" << "actionGotoFrame2(stack, sp, "
							   << (int)play_flag << ", " << scene_bias << ");" << endl;

					action_buffer += length;

					break;
				}

				case SWF_ACTION_GET_URL2:
				{
					// Read flags byte
					u8 flags = VAL(u8, action_buffer);

					u8 send_vars_method = (flags & 0xC0) >> 6;  // Top 2 bits (6-7)
					u8 load_target_flag = (flags & 0x02) >> 1;   // Bit 1
					u8 load_variables_flag = (flags & 0x01);     // Bit 0

					const char* method_str = "NONE";
					if (send_vars_method == 1) method_str = "GET";
					else if (send_vars_method == 2) method_str = "POST";

					out_script << "\t" << "// GetURL2: method=" << method_str
							   << ", loadTarget=" << (int)load_target_flag
							   << ", loadVars=" << (int)load_variables_flag << endl
							   << "\t" << "actionGetURL2(stack, sp, "
							   << (int)send_vars_method << ", "
							   << (int)load_target_flag << ", "
							   << (int)load_variables_flag << ");" << endl;

					action_buffer += length;

					break;
				}

			case SWF_ACTION_DEFINE_FUNCTION:
			{
				// Parse function metadata
				char* func_name = action_buffer;
				size_t name_len = strlen(func_name);
				action_buffer += name_len + 1;

				u16 num_params = VAL(u16, action_buffer);
				action_buffer += 2;

				// Parse parameter names
				std::vector<std::string> params;
				for (u16 i = 0; i < num_params; i++)
				{
					char* param_name = action_buffer;
					size_t param_len = strlen(param_name);
					action_buffer += param_len + 1;
					params.push_back(std::string(param_name));
				}

				u16 code_size = VAL(u16, action_buffer);
				action_buffer += 2;

				// Generate unique function ID
				static int func_counter = 0;
				std::string func_id = std::string("func_") + (name_len > 0 ? std::string(func_name) : "anonymous") + "_" + std::to_string(func_counter++);

				// Add function declaration to header
				context.out_script_decls << endl << "void " << func_id << "(char* stack, u32* sp);" << endl;

				// Generate function definition
				context.out_script_defs << endl << endl
					<< "// DefineFunction: " << (name_len > 0 ? func_name : "(anonymous)") << endl
					<< "void " << func_id << "(char* stack, u32* sp)" << endl
					<< "{" << endl;

				// Bind parameters (simple DefineFunction uses variables, not registers)
				for (size_t i = 0; i < params.size(); i++)
				{
					context.out_script_defs << "\t// TODO: Bind parameter '" << params[i] << "' from arguments" << endl;
				}

				// Parse function body recursively
				context.out_script_defs << endl << "\t// Function body (" << code_size << " bytes)" << endl;

				char* func_body_start = action_buffer;
				char* func_body_end = action_buffer + code_size;

				// Create temporary buffer with END_OF_ACTIONS marker
				char* temp_buffer = (char*)malloc(code_size + 1);
				memcpy(temp_buffer, func_body_start, code_size);
				temp_buffer[code_size] = 0x00;

				char* temp_ptr = temp_buffer;
				parseActions(context, temp_ptr, context.out_script_defs);
				free(temp_buffer);

				action_buffer = func_body_end;

				context.out_script_defs << "}" << endl;

				// Generate runtime call to register function
				out_script << "\t// DefineFunction: " << (name_len > 0 ? func_name : "(anonymous)") << endl;
				out_script << "\tactionDefineFunction(stack, sp, \"" << (name_len > 0 ? func_name : "") << "\", "
						   << func_id << ", " << num_params << ");" << endl;

				break;
			}

			case SWF_ACTION_CALL_FUNCTION:
			{
				out_script << "\t" << "// CallFunction" << endl
						   << "\t" << "actionCallFunction(stack, sp, str_buffer);" << endl;

				break;
			}

			case SWF_ACTION_CALL_METHOD:
			{
				out_script << "\t" << "// CallMethod" << endl
						   << "\t" << "actionCallMethod(stack, sp, str_buffer);" << endl;

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
