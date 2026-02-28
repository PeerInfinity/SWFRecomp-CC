#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>

#include <action.hpp>

#define VAL(type, x) *((type*) x)

using std::stringstream;
using std::to_string;
using std::endl;

namespace SWFRecomp
{
	// Struct for tracking try/catch/finally block boundaries during inline parsing
	struct TryBlockBoundary {
		char* catch_start;      // Start of catch body (nullptr if no catch)
		char* finally_start;    // Start of finally body (nullptr if no finally)
		char* after_end;        // First byte after the entire try-catch-finally construct
		bool has_catch;
		bool has_finally;
		bool catch_in_register;
		std::string catch_name;
		u8 catch_register;
		// State: 0=in try, 1=in catch, 2=in finally, 3=done
		int state;
	};

	// Escape a raw string for use inside C string literals
	// For SWF < 6 (Latin-1/Win-1252 encoding), convert bytes 0x80-0xFF to UTF-8
	static std::string escape_c_string(const char* str, int swf_version = 6)
	{
		std::string result;
		for (const char* p = str; *p; ++p)
		{
			unsigned char c = (unsigned char)*p;
			switch (c)
			{
				case '"':  result += "\\\""; break;
				case '\\': result += "\\\\"; break;
				case '\n': result += "\\n"; break;
				case '\r': result += "\\r"; break;
				case '\t': result += "\\t"; break;
				case '\0': result += "\\0"; break;
				default:
					if (c < 0x20 || c == 0x7f)
					{
						char buf[5];
						snprintf(buf, sizeof(buf), "\\x%02x", c);
						result += buf;
					}
					else if (c >= 0x80 && swf_version < 6)
					{
						// Latin-1/Win-1252 byte → UTF-8
						// For 0x80-0x9F (Win-1252 specific), use the standard mapping
						// For 0xA0-0xFF (shared Latin-1), direct conversion
						static const unsigned short win1252_map[32] = {
							0x20AC, 0x0081, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
							0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008D, 0x017D, 0x008F,
							0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
							0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x009D, 0x017E, 0x0178
						};
						unsigned int codepoint;
						if (c >= 0x80 && c <= 0x9F)
							codepoint = win1252_map[c - 0x80];
						else
							codepoint = c; // Latin-1: codepoint == byte value

						char buf[13];
						if (codepoint < 0x80) {
							snprintf(buf, sizeof(buf), "%c", (char)codepoint);
						} else if (codepoint < 0x800) {
							snprintf(buf, sizeof(buf), "\\x%02x\\x%02x",
								0xC0 | (codepoint >> 6),
								0x80 | (codepoint & 0x3F));
						} else {
							snprintf(buf, sizeof(buf), "\\x%02x\\x%02x\\x%02x",
								0xE0 | (codepoint >> 12),
								0x80 | ((codepoint >> 6) & 0x3F),
								0x80 | (codepoint & 0x3F));
						}
						result += buf;
					}
					else
					{
						result += (char)c;
					}
					break;
			}
		}
		return result;
	}

	// Sanitize a string to be a valid C identifier (replace non-alnum with '_')
	static std::string sanitize_identifier(const std::string& name)
	{
		std::string result;
		result.reserve(name.size());
		for (char c : name)
		{
			result += (isalnum(c) || c == '_') ? c : '_';
		}
		return result;
	}

	SWFAction::SWFAction() : next_str_i(0), parse_depth(0)
	{

	}
	
	void SWFAction::parseActions(Context& context, char*& action_buffer, ostream& out_script)
	{
		parse_depth++;

		// Save and clear constant pool at script boundary.
		// Nested parseActions calls (DefineFunction2, Try, With) will inherit the
		// parent's pool since we save it here and restore it after the call returns.
		std::vector<size_t> saved_pool = constant_pool;

		SWFActionType code = SWF_ACTION_CONSTANT_POOL;
		u16 length;

		char* action_buffer_start = action_buffer;

		std::set<char*> labels;

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
					labels.insert(action_buffer + length + ((s64) offset));
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
					labels.insert(skip_ptr);
					break;
				}

			case SWF_ACTION_TRY:
			{
				// Register finally_start and after_end as labels for goto targets
				// NOTE: Must use byte-by-byte reads here because action_buffer+1 etc.
				// are NOT aligned for u16 reads, and VAL macro's pointer cast causes
				// incorrect values due to strict aliasing / alignment UB.
				u8 try_flags = (u8)action_buffer[0];
				bool try_has_finally = (try_flags & 0x02) != 0;
				u16 p1_try_size = (u8)action_buffer[1] | ((u8)action_buffer[2] << 8);
				u16 p1_catch_size = (u8)action_buffer[3] | ((u8)action_buffer[4] << 8);
				u16 p1_finally_size = (u8)action_buffer[5] | ((u8)action_buffer[6] << 8);
				char* body_start = action_buffer + length;
				char* p1_finally_start = body_start + p1_try_size + p1_catch_size;
				char* p1_after_end = p1_finally_start + p1_finally_size;
				if (try_has_finally) {
					labels.insert(p1_finally_start);
				}
				labels.insert(p1_after_end);
				break;
			}

			case SWF_ACTION_DEFINE_FUNCTION:   // 0x9B
			case SWF_ACTION_DEFINE_FUNCTION2:  // 0x8E
			{
				// The 'length' field covers the function header (name, params, code_size).
				// code_size is always the last 2 bytes of the header.
				// The function BODY is code_size additional bytes AFTER the header
				// that we must skip so Phase 1 doesn't try to scan them as top-level actions.
				u16 code_size = (u8)action_buffer[length - 2] | ((u8)action_buffer[length - 1] << 8);
				action_buffer += code_size;  // skip body; generic += length below skips header
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
				labels.insert(skip_ptr);
				break;
			}
			}
			
			action_buffer += length;
		}
		
		action_buffer = action_buffer_start;
		code = SWF_ACTION_CONSTANT_POOL;

		// Stack of active try/catch/finally block boundaries for inline parsing
		std::vector<TryBlockBoundary> try_boundaries;
		// Labels pre-emitted by boundary handler (skip in generic label code)
		std::set<char*> emitted_labels;
		
		while (code != SWF_ACTION_END_OF_ACTIONS)
		{
			// Check try/catch/finally block boundaries before processing next action
			while (!try_boundaries.empty())
			{
				TryBlockBoundary& tb = try_boundaries.back();
				if (tb.state == 0 && tb.has_catch && action_buffer >= tb.catch_start)
				{
					// Transition from try body to catch body
					out_script << "\t" << "} else {" << endl;
					out_script << "\t\t" << "// Catch block" << endl;
					out_script << "\t\t" << "actionCatchEnter(app_context);" << endl;
					if (tb.catch_in_register)
					{
						if (context.inside_function2 && (int)tb.catch_register < context.function2_register_count)
						{
							// DefineFunction2, local register — get exception value directly
							out_script << "\t\t" << "actionCatchGetException(app_context, &regs[" << (int)tb.catch_register << "]);" << endl;
						}
						else
						{
							out_script << "\t\t" << "actionCatchToRegister(app_context, " << (int)tb.catch_register << ");" << endl;
						}
					}
					else
					{
						out_script << "\t\t" << "actionCatchToVariable(app_context, \"" << tb.catch_name << "\");" << endl;
					}
					tb.state = 1;
				}
				else if ((tb.state == 0 || tb.state == 1) && tb.has_finally && action_buffer >= tb.finally_start)
				{
					// Transition to finally body
					if (tb.state == 0)
					{
						// try-only -> finally (no catch block)
						out_script << "\t" << "}" << endl;
					}
					else
					{
						// catch -> finally
						out_script << "\t" << "}" << endl;
					}
					out_script << "\t" << "// Finally block" << endl;
					tb.state = 2;
				}
				else if (tb.state <= 2 && action_buffer >= tb.after_end)
				{
					// End of entire try-catch-finally construct
					if (tb.state == 0 || tb.state == 1)
					{
						// Close the if or else block
						out_script << "\t" << "}" << endl;
					}
					// For try-catch without finally: emit the after_end label BEFORE
					// actionTryEnd so goto from try body doesn't skip cleanup
					if (!tb.has_finally && labels.count(tb.after_end))
					{
						out_script << "label_" << to_string((s16)(tb.after_end - action_buffer_start)) << ":" << endl;
						emitted_labels.insert(tb.after_end);
					}
					out_script << "\t" << "actionTryEnd(app_context);" << endl;
					if (tb.has_finally)
					{
						out_script << "\t" << "if (actionReturnPending(app_context)) {" << endl;
						out_script << "\t\t" << "return actionGetPendingReturn(app_context);" << endl;
						out_script << "\t" << "}" << endl;
					}
					tb.state = 3;
					try_boundaries.pop_back();
					continue; // Check next boundary in stack
				}
				else
				{
					break; // No boundary reached
				}
			}

			for (const char* ptr : labels)
			{
				if (action_buffer == ptr && emitted_labels.count(const_cast<char*>(ptr)) == 0)
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
							   << "\t" << "actionNextFrame(app_context);" << endl;

					break;
				}

				case SWF_ACTION_PREV_FRAME:
				{
					out_script << "\t" << "// Prev Frame" << endl
							   << "\t" << "actionPrevFrame(app_context);" << endl;

					break;
				}

				case SWF_ACTION_PLAY:
				{
					out_script << "\t" << "// Play" << endl
							   << "\t" << "actionPlay(app_context);" << endl;

					break;
				}

				case SWF_ACTION_STOP:
				{
					out_script << "\t" << "// Stop" << endl
							   << "\t" << "actionStop(app_context);" << endl;

					break;
				}

				case SWF_ACTION_TOGGLE_QUALITY:
				{
					out_script << "\t" << "// Toggle Quality" << endl
							   << "\t" << "actionToggleQuality(app_context);" << endl;

					break;
				}

				case SWF_ACTION_STOP_SOUNDS:
				{
					out_script << "\t" << "// Stop Sounds" << endl
							   << "\t" << "actionStopSounds(app_context);" << endl;

					break;
				}

				case SWF_ACTION_ADD:
				{
					out_script << "\t" << "// Add" << endl
							   << "\t" << "actionAdd(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_SUBTRACT:
				{
					out_script << "\t" << "// Subtract" << endl
							   << "\t" << "actionSubtract(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_MULTIPLY:
				{
					out_script << "\t" << "// Multiply" << endl
							   << "\t" << "actionMultiply(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_DIVIDE:
				{
					out_script << "\t" << "// Divide" << endl
							   << "\t" << "actionDivide(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_EQUALS:
				{
					out_script << "\t" << "// Equals" << endl
							   << "\t" << "actionEquals(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_LESS:
				{
					out_script << "\t" << "// Less" << endl
							   << "\t" << "actionLess(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_AND:
				{
					out_script << "\t" << "// And" << endl
							   << "\t" << "actionAnd(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_OR:
				{
					out_script << "\t" << "// Or" << endl
							   << "\t" << "actionOr(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_NOT:
				{
					out_script << "\t" << "// Not" << endl
							   << "\t" << "actionNot(app_context);" << endl;
					
					break;
				}
				
				case SWF_ACTION_STRING_EQUALS:
				{
					declareEmptyString(context, 17);
					declareEmptyString(context, 17);
					
					out_script << "\t" << "// StringEquals" << endl
							   << "\t" << "actionStringEquals(app_context, "
							   << "str_" << to_string(next_str_i - 2) << ", "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;
					
					break;
				}
				
				case SWF_ACTION_STRING_LENGTH:
				{
					declareEmptyString(context, 17);
					
					out_script << "\t" << "// StringLength" << endl
							   << "\t" << "actionStringLength(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;
					
					break;
				}
				

			case SWF_ACTION_STRING_EXTRACT:
			{
				declareEmptyString(context, 17);

				out_script << "\t" << "// StringExtract" << endl
						   << "\t" << "actionStringExtract(app_context, str_"
						   << to_string(next_str_i - 1) << ");" << endl;

				break;
			}
				case SWF_ACTION_STRING_ADD:
				{
					declareEmptyString(context, 17);
					declareEmptyString(context, 17);

					out_script << "\t" << "// StringAdd" << endl
							   << "\t" << "actionStringAdd(app_context, "
							   << "str_" << to_string(next_str_i - 2) << ", "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_GET_PROPERTY:
				{
					out_script << "\t" << "// GetProperty" << endl
							   << "\t" << "actionGetProperty(app_context);" << endl;

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
							   << "\t" << "actionToInteger(app_context);" << endl;

					break;
				}

				case SWF_ACTION_GET_VARIABLE:
				{
					out_script << "\t" << "// GetVariable" << endl
							   << "\t" << "actionGetVariable(app_context);" << endl;

					break;
				}

				case SWF_ACTION_SET_VARIABLE:
				{
					out_script << "\t" << "// SetVariable" << endl
							   << "\t" << "actionSetVariable(app_context);" << endl;

					break;
				}

				case SWF_ACTION_SET_TARGET2:
				{
					out_script << "\t" << "// SetTarget2" << endl
							   << "\t" << "actionSetTarget2(app_context);" << endl;

					break;
				}

				case SWF_ACTION_SET_PROPERTY:
				{
					out_script << "\t" << "// SetProperty" << endl
							   << "\t" << "actionSetProperty(app_context);" << endl;

					break;
				}

				case SWF_ACTION_CLONE_SPRITE:
				{
					out_script << "\t" << "// CloneSprite" << endl
							   << "\t" << "actionCloneSprite(app_context);" << endl;

					break;
				}

				case SWF_ACTION_REMOVE_SPRITE:
				{
					out_script << "\t" << "// RemoveSprite" << endl
						   << "\t" << "actionRemoveSprite(app_context);" << endl;

					break;
				}

				case SWF_ACTION_TRACE:
				{
					out_script << "\t" << "// Trace" << endl
							   << "\t" << "actionTrace(app_context);" << endl;

				break;
				}

				case SWF_ACTION_START_DRAG:
				{
					out_script << "\t" << "// StartDrag" << endl
							   << "\t" << "actionStartDrag(app_context);" << endl;

					break;
				}

				case SWF_ACTION_END_DRAG:
				{
					out_script << "\t" << "// End Drag" << endl
							   << "\t" << "actionEndDrag(app_context);" << endl;

					break;
				}

				case SWF_ACTION_CAST_OP:
				{
					out_script << "\t" << "// CastOp" << endl
							   << "\t" << "actionCastOp(app_context);" << endl;

					break;
				}

				case SWF_ACTION_STRING_LESS:
				{
					out_script << "\t" << "// StringLess" << endl
							   << "\t" << "actionStringLess(app_context);" << endl;

					break;
				}

				case SWF_ACTION_THROW:
				{
					// Check if inside a catch block with a finally clause
					bool in_catch_with_finally = false;
					char* throw_finally_ptr = nullptr;
					for (int i = (int)try_boundaries.size() - 1; i >= 0; i--) {
						if (try_boundaries[i].state == 1 && try_boundaries[i].has_finally) {
							in_catch_with_finally = true;
							throw_finally_ptr = try_boundaries[i].finally_start;
							break;
						}
					}

					if (in_catch_with_finally && throw_finally_ptr) {
						out_script << "\t" << "// Throw (deferred to finally)" << endl
								   << "\t" << "actionThrowPending(app_context);" << endl
								   << "\t" << "goto label_" << to_string((s16)(throw_finally_ptr - action_buffer_start)) << ";" << endl;
					} else {
						out_script << "\t" << "// Throw" << endl
								   << "\t" << "actionThrow(app_context);" << endl;
					}

					break;
				}

				case SWF_ACTION_IMPLEMENTS_OP:
				{
					out_script << "\t" << "// ImplementsOp" << endl
							   << "\t" << "actionImplementsOp(app_context);" << endl;

					break;
				}

				case SWF_ACTION_RANDOM_NUMBER:
				{
					out_script << "\t" << "// Random Number" << endl
							   << "\t" << "actionRandomNumber(app_context);" << endl;

					break;
				}

				case SWF_ACTION_CHAR_TO_ASCII:
				{
					out_script << "\t" << "// CharToAscii" << endl
							   << "\t" << "actionCharToAscii(app_context);" << endl;

					break;
				}

				case SWF_ACTION_ASCII_TO_CHAR:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// AsciiToChar" << endl
							   << "\t" << "actionAsciiToChar(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_MB_CHAR_TO_ASCII:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// MbCharToAscii" << endl
							   << "\t" << "actionMbCharToAscii(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_GET_TIME:
				{
					out_script << "\t" << "// GetTime" << endl
							   << "\t" << "actionGetTime(app_context);" << endl;

					break;
				}

				case SWF_ACTION_MB_STRING_LENGTH:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// MbStringLength" << endl
							   << "\t" << "actionMbStringLength(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_MB_STRING_EXTRACT:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// MbStringExtract" << endl
							   << "\t" << "actionMbStringExtract(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_MB_ASCII_TO_CHAR:
				{
					declareEmptyString(context, 5);  // Max 4 bytes for UTF-8 + null terminator

					out_script << "\t" << "// MbAsciiToChar" << endl
							   << "\t" << "actionMbAsciiToChar(app_context, "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DELETE:
				{
					out_script << "\t" << "// Delete" << endl
							   << "\t" << "actionDelete(app_context);" << endl;

					break;
				}

				case SWF_ACTION_DELETE2:
				{
					declareEmptyString(context, 256);  // Buffer for variable name operations

					out_script << "\t" << "// Delete2" << endl
							   << "\t" << "actionDelete2(app_context, "
							   << "str_" << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DEFINE_LOCAL:
				{
					out_script << "\t" << "// DefineLocal" << endl
							   << "\t" << "actionDefineLocal(app_context);" << endl;

					break;
				}

				case SWF_ACTION_TYPEOF:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Typeof" << endl
							   << "\t" << "actionTypeof(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_DUPLICATE:
				{
					out_script << "\t" << "// Duplicate" << endl
							   << "\t" << "actionDuplicate(app_context);" << endl;

					break;
				}

				case SWF_ACTION_RETURN:
				{
					// Check if inside a try/catch block with a finally clause
					bool in_try_with_finally = false;
					char* ret_finally_ptr = nullptr;
					for (int i = (int)try_boundaries.size() - 1; i >= 0; i--) {
						if (try_boundaries[i].has_finally && try_boundaries[i].state <= 1) {
							in_try_with_finally = true;
							ret_finally_ptr = try_boundaries[i].finally_start;
							break;
						}
					}

					if (in_try_with_finally && ret_finally_ptr) {
						out_script << "\t" << "// Return (deferred to finally)" << endl
								   << "\t" << "{" << endl
								   << "\t\t" << "ActionVar ret_val;" << endl
								   << "\t\t" << "popVar(app_context, &ret_val);" << endl
								   << "\t\t" << "actionSetReturnPending(app_context, &ret_val);" << endl
								   << "\t\t" << "goto label_" << to_string((s16)(ret_finally_ptr - action_buffer_start)) << ";" << endl
								   << "\t" << "}" << endl;
					} else {
						out_script << "\t" << "// Return" << endl
								   << "\t" << "{" << endl
								   << "\t\t" << "ActionVar ret_val;" << endl
								   << "\t\t" << "popVar(app_context, &ret_val);" << endl
								   << "\t\t" << "return ret_val;" << endl
								   << "\t" << "}" << endl;
					}

					break;
				}

				case SWF_ACTION_MODULO:
				{
					out_script << "\t" << "// Modulo" << endl
							   << "\t" << "actionModulo(app_context);" << endl;

					break;
				}

			case SWF_ACTION_NEW_OBJECT:
			{
				out_script << "\t" << "// NewObject" << endl
						   << "\t" << "actionNewObject(app_context);" << endl;

				break;
			}

			case SWF_ACTION_NEW_METHOD:
			{
				out_script << "\t" << "// NewMethod" << endl
						   << "\t" << "actionNewMethod(app_context);" << endl;

				break;
			}

			case SWF_ACTION_DECLARE_LOCAL:
			{
				out_script << "\t" << "// DeclareLocal" << endl
						   << "\t" << "actionDeclareLocal(app_context);" << endl;

				break;
			}

			case SWF_ACTION_INIT_ARRAY:
			{
				out_script << "\t" << "// InitArray" << endl
						   << "\t" << "actionInitArray(app_context);" << endl;

				break;
			}

			case SWF_ACTION_INIT_OBJECT:
			{
				out_script << "\t" << "// InitObject" << endl
						   << "\t" << "actionInitObject(app_context);" << endl;

				break;
			}

				case SWF_ACTION_TARGET_PATH:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// TargetPath" << endl
							   << "\t" << "actionTargetPath(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}


				case SWF_ACTION_ENUMERATE:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Enumerate" << endl
							   << "\t" << "actionEnumerate(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_ADD2:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Add2 (Type-Aware Addition)" << endl
							   << "\t" << "actionAdd2(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_LESS2:
				{
					out_script << "\t" << "// Less2" << endl
							   << "\t" << "actionLess2(app_context);" << endl;

					break;
				}

				case SWF_ACTION_EQUALS2:
				{
					out_script << "\t" << "// Equals2" << endl
							   << "\t" << "actionEquals2(app_context);" << endl;

					break;
				}

				case SWF_ACTION_TO_NUMBER:
				{
					out_script << "\t" << "// ToNumber" << endl
							   << "\t" << "actionToNumber(app_context);" << endl;

					break;
				}

				case SWF_ACTION_TO_STRING:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// ToString" << endl
							   << "\t" << "actionToString(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_STACK_SWAP:
				{
					out_script << "\t" << "// Stack Swap" << endl
							   << "\t" << "actionStackSwap(app_context);" << endl;

					break;
				}

				case SWF_ACTION_GET_MEMBER:
				{
					out_script << "\t" << "// GetMember" << endl
							   << "\t" << "actionGetMember(app_context);" << endl;

					break;
				}

				case SWF_ACTION_SET_MEMBER:
				{
					out_script << "\t" << "// SetMember" << endl
							   << "\t" << "actionSetMember(app_context);" << endl;

					break;
				}

				case SWF_ACTION_INCREMENT:
				{
					out_script << "\t" << "// Increment" << endl
							   << "\t" << "actionIncrement(app_context);" << endl;

					break;
				}

				case SWF_ACTION_DECREMENT:
				{
					out_script << "\t" << "// Decrement" << endl
							   << "\t" << "actionDecrement(app_context);" << endl;

					break;
				}

				case SWF_ACTION_INSTANCEOF:
				{
					out_script << "\t" << "// InstanceOf" << endl
							   << "\t" << "actionInstanceOf(app_context);" << endl;

					break;
				}

				case SWF_ACTION_ENUMERATE2:
				{
					declareEmptyString(context, 17);

					out_script << "\t" << "// Enumerate2" << endl
							   << "\t" << "actionEnumerate2(app_context, str_"
							   << to_string(next_str_i - 1) << ");" << endl;

					break;
				}

				case SWF_ACTION_BIT_AND:
				{
					out_script << "\t" << "// Bit And" << endl
							   << "\t" << "actionBitAnd(app_context);" << endl;

					break;
				}

				case SWF_ACTION_BIT_OR:
				{
					out_script << "\t" << "// Bit Or" << endl
							   << "\t" << "actionBitOr(app_context);" << endl;

					break;
				}

				case SWF_ACTION_BIT_XOR:
				{
					out_script << "\t" << "// BitXor" << endl
							   << "\t" << "actionBitXor(app_context);" << endl;

					break;
				}

				case SWF_ACTION_BIT_LSHIFT:
				{
					out_script << "\t" << "// BitLShift" << endl
							   << "\t" << "actionBitLShift(app_context);" << endl;

					break;
				}

				case SWF_ACTION_BIT_RSHIFT:
				{
					out_script << "\t" << "// BitRShift" << endl
							   << "\t" << "actionBitRShift(app_context);" << endl;

					break;
				}

				case SWF_ACTION_BIT_URSHIFT:
				{
					out_script << "\t" << "// BitURShift" << endl
							   << "\t" << "actionBitURShift(app_context);" << endl;

					break;
				}

				case SWF_ACTION_STRICT_EQUALS:
				{
					out_script << "\t" << "// StrictEquals" << endl
							   << "\t" << "actionStrictEquals(app_context);" << endl;

					break;
				}

				case SWF_ACTION_GREATER:
				{
					out_script << "\t" << "// Greater" << endl
							   << "\t" << "actionGreater(app_context);" << endl;

					break;
				}

				case SWF_ACTION_STRING_GREATER:
				{
					out_script << "\t" << "// StringGreater" << endl
							   << "\t" << "actionStringGreater(app_context);" << endl;

					break;
				}

				case SWF_ACTION_EXTENDS:
				{
					out_script << "\t" << "// Extends - Set up prototype chain for inheritance" << endl
							   << "\t" << "actionExtends(app_context);" << endl;

					break;
				}

				case SWF_ACTION_GOTO_FRAME:
				{
					// Read the frame index from the action record
					u16 frame_index = VAL(u16, action_buffer);

					out_script << "	" << "// GotoFrame: " << frame_index << endl
							   << "	" << "actionGotoFrame(app_context, " << frame_index << ");" << endl;

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
						   << "\t" << "actionGetURL(app_context, "
						   << "\"" << url_string << "\", "
						   << "\"" << target_string << "\");" << endl;

				break;
			}

				case SWF_ACTION_STORE_REGISTER:
				{
					// Read register number from bytecode
					u8 register_num = (u8) action_buffer[0];

					out_script << "\t" << "// StoreRegister " << (int)register_num << endl;

					if (context.inside_function2)
					{
						if ((int)register_num < context.function2_register_count)
						{
							// Inside DefineFunction2, register is local: store to local registers array
							out_script << "\t" << "peekVar(app_context, &regs[" << (int)register_num << "]);" << endl;
						}
						else
						{
							// Inside DefineFunction2, register bleeds through to caller: use global
							out_script << "\t" << "actionStoreRegister(app_context, " << (int)register_num << ");" << endl;
						}
					}
					else
					{
						// Outside functions: store to global registers
						out_script << "\t" << "actionStoreRegister(app_context, " << (int)register_num << ");" << endl;
					}

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
							   << "\t" << "if (!actionWaitForFrame(app_context, " << frame << "))" << endl
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
							   << "\t" << "actionSetTarget(app_context, \"" << escaped_target << "\");" << endl;

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
							   << "\t" << "actionGoToLabel(app_context, \"" << label << "\");" << endl;

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
						   << "\t" << "if (!actionWaitForFrame2(app_context)) {" << endl
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
				std::string func_id = std::string("func2_") + (name_len > 0 ? sanitize_identifier(func_name) : "anonymous") + "_" + std::to_string(func2_counter++);

			// Add function declaration to header (uses app_context)
			context.out_script_decls << endl << "ActionVar " << func_id << "(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj);" << endl;

				// Buffer entire function definition in a stringstream so that
				// nested function definitions (written to context.out_script_defs)
				// appear BEFORE this function in the output file.
				stringstream func_def;

				// Generate function definition
				func_def << endl << endl
					<< "// DefineFunction2: " << (name_len > 0 ? func_name : "(anonymous)") << endl
					<< "ActionVar " << func_id << "(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)" << endl
					<< "{" << endl
					<< "\tchar str_buffer[17];" << endl;

				// Parse flags (SWF spec bit layout)
				bool preload_this       = (flags & 0x0001); // Bit 0
				bool suppress_this      = (flags & 0x0002); // Bit 1
				bool preload_arguments  = (flags & 0x0004); // Bit 2
				bool suppress_arguments = (flags & 0x0008); // Bit 3
				bool preload_super      = (flags & 0x0010); // Bit 4
				bool suppress_super     = (flags & 0x0020); // Bit 5
				bool preload_root       = (flags & 0x0040); // Bit 6
				bool preload_parent     = (flags & 0x0080); // Bit 7
				bool preload_global     = (flags & 0x0100); // Bit 8

				// Scan function body for maximum register index used
				int max_body_reg = 0;
				{
					char* scan = action_buffer;
					char* scan_end = action_buffer + code_size;
					while (scan < scan_end)
					{
						u8 op = (u8)*scan;
						if (op < 0x80)
						{
							// No-data action
							scan++;
						}
						else
						{
							// Action with length
							if (scan + 3 > scan_end) break;
							u16 act_len = VAL(u16, (scan + 1));
							char* act_data = scan + 3;
							if (op == 0x87 && act_len >= 1) // StoreRegister
							{
								int reg = (u8)act_data[0];
								if (reg > max_body_reg) max_body_reg = reg;
							}
							else if (op == 0x96) // Push
							{
								// Scan push data for register type (type byte = 4)
								char* p = act_data;
								char* p_end = act_data + act_len;
								while (p < p_end)
								{
									u8 ptype = (u8)*p; p++;
									if (ptype == 0) { while (p < p_end && *p) p++; p++; } // String
									else if (ptype == 1) { p += 4; } // Float
									else if (ptype == 2) { } // Null
									else if (ptype == 3) { } // Undefined
									else if (ptype == 4) { if (p < p_end) { int reg = (u8)*p; if (reg > max_body_reg) max_body_reg = reg; } p++; } // Register
									else if (ptype == 5) { p++; } // Boolean
									else if (ptype == 6) { p += 8; } // Double
									else if (ptype == 7) { p += 4; } // Integer
									else if (ptype == 8) { p++; } // ConstantPool8
									else if (ptype == 9) { p += 2; } // ConstantPool16
									else break;
								}
							}
							scan += 3 + act_len;
						}
					}
				}

				// Calculate actual register count needed
				int next_reg = 1; // Register 0 is reserved
				if (preload_this) next_reg++;
				if (preload_arguments) next_reg++;
				if (preload_super) next_reg++;
				if (preload_root) next_reg++;
				if (preload_global) next_reg++;
				if (preload_parent) next_reg++;
				int actual_reg_count = next_reg > (int)register_count ? next_reg : (int)register_count;
				// Ensure array is large enough for all registers used in the body
				if (max_body_reg + 1 > actual_reg_count) actual_reg_count = max_body_reg + 1;

				// Initialize local registers to undefined
				if (actual_reg_count > 0)
				{
					func_def << "\tActionVar regs[" << actual_reg_count << "];" << endl;
					func_def << "\tfor (int _ri = 0; _ri < " << actual_reg_count << "; _ri++) { regs[_ri].type = ACTION_STACK_VALUE_UNDEFINED; regs[_ri].data.numeric_value = 0; regs[_ri].str_size = 0; }" << endl;
				}

				// Preload special variables into registers
				next_reg = 1; // Reset for actual emission

				if (preload_this)
				{
					if (!suppress_this)
					{
						func_def << "\t// Preload 'this' into register " << next_reg << endl;
						func_def << "\tif (this_obj != NULL) {" << endl;
						func_def << "\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_OBJECT;" << endl;
						func_def << "\t\tregs[" << next_reg << "].data.numeric_value = (u64)this_obj;" << endl;
						func_def << "\t} else {" << endl;
						func_def << "\t\textern MovieClip root_movieclip;" << endl;
						func_def << "\t\textern MovieClip* g_event_this_mc;" << endl;
						func_def << "\t\tif (g_event_this_mc != NULL) {" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_MOVIECLIP;" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].data.numeric_value = (u64)g_event_this_mc;" << endl;
						func_def << "\t\t\tg_event_this_mc = NULL;" << endl;
						func_def << "\t\t} else {" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_MOVIECLIP;" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].data.numeric_value = (u64)&root_movieclip;" << endl;
						func_def << "\t\t}" << endl;
						func_def << "\t}" << endl;
					}
					next_reg++;
				}

				if (preload_arguments)
				{
					func_def << "\t// Preload 'arguments' into register " << next_reg << endl;
					func_def << "\t// Create arguments array object" << endl;
					func_def << "\tASArray* arguments_array = allocArray(app_context, arg_count);" << endl;
					func_def << "\tfor (u32 i = 0; i < arg_count; i++) {" << endl;
					func_def << "\t\tsetArrayElement(app_context, arguments_array, i, &args[i]);" << endl;
					func_def << "\t}" << endl;
					func_def << "\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_ARRAY;" << endl;
					func_def << "\tregs[" << next_reg << "].data.numeric_value = (u64)arguments_array;" << endl;
					func_def << "\tswf_setup_arguments_props(app_context, arguments_array);" << endl;
					next_reg++;
				}

				if (preload_super)
				{
					if (!suppress_super)
					{
						func_def << "\t// Preload 'super' into register " << next_reg << endl;
						func_def << "\t{" << endl;
						func_def << "\t\tu64 _super_this; u32 _super_depth;" << endl;
						func_def << "\t\tactionGetCurrentSuperInfo(&_super_this, &_super_depth);" << endl;
						func_def << "\t\tif (_super_this) {" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_SUPER;" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].data.numeric_value = _super_this;" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].str_size = _super_depth;" << endl;
						func_def << "\t\t} else {" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
						func_def << "\t\t\tregs[" << next_reg << "].data.numeric_value = 0;" << endl;
						func_def << "\t\t}" << endl;
						func_def << "\t}" << endl;
					}
					next_reg++;
				}

				if (preload_root)
				{
					func_def << "\t// Preload '_root' into register " << next_reg << endl;
					func_def << "\textern MovieClip root_movieclip;" << endl;
					func_def << "\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_MOVIECLIP;" << endl;
					func_def << "\tregs[" << next_reg << "].data.numeric_value = (u64)&root_movieclip;" << endl;
					next_reg++;
				}

				// _parent and _global use runtime register assignment because
				// Flash Player skips _parent preload when parent is NULL,
				// causing _global to shift into _parent's register slot
				if (preload_parent && preload_global)
				{
					func_def << "\t// Preload '_parent' and '_global' (runtime register assignment)" << endl;
					func_def << "\t{" << endl;
					func_def << "\t\textern MovieClip* g_current_context;" << endl;
					func_def << "\t\textern MovieClip root_movieclip;" << endl;
					func_def << "\t\textern ASObject* global_object;" << endl;
					func_def << "\t\tMovieClip* _ctx = g_current_context ? g_current_context : &root_movieclip;" << endl;
					func_def << "\t\tint _pr = " << next_reg << ";" << endl;
					func_def << "\t\tif (_ctx->parent != NULL) {" << endl;
					func_def << "\t\t\tregs[_pr].type = ACTION_STACK_VALUE_MOVIECLIP;" << endl;
					func_def << "\t\t\tregs[_pr].data.numeric_value = (u64)_ctx->parent;" << endl;
					func_def << "\t\t\t_pr++;" << endl;
					func_def << "\t\t}" << endl;
					func_def << "\t\tregs[_pr].type = ACTION_STACK_VALUE_OBJECT;" << endl;
					func_def << "\t\tregs[_pr].data.numeric_value = (u64)global_object;" << endl;
					func_def << "\t}" << endl;
					next_reg += 2;
				}
				else if (preload_parent)
				{
					func_def << "\t// Preload '_parent' into register " << next_reg << endl;
					func_def << "\t{" << endl;
					func_def << "\t\textern MovieClip* g_current_context;" << endl;
					func_def << "\t\textern MovieClip root_movieclip;" << endl;
					func_def << "\t\tMovieClip* _ctx = g_current_context ? g_current_context : &root_movieclip;" << endl;
					func_def << "\t\tif (_ctx->parent != NULL) {" << endl;
					func_def << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_MOVIECLIP;" << endl;
					func_def << "\t\t\tregs[" << next_reg << "].data.numeric_value = (u64)_ctx->parent;" << endl;
					func_def << "\t\t}" << endl;
					func_def << "\t}" << endl;
					next_reg++;
				}
				else if (preload_global)
				{
					func_def << "\t// Preload '_global' into register " << next_reg << endl;
					func_def << "\textern ASObject* global_object;" << endl;
					func_def << "\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_OBJECT;" << endl;
					func_def << "\tregs[" << next_reg << "].data.numeric_value = (u64)global_object;" << endl;
					next_reg++;
				}

				// Bind parameters to registers or variables
				for (size_t i = 0; i < params.size(); i++)
				{
					if (params[i].first == 0)
					{
						// Variable parameter
						func_def << "\tif (" << i << " < arg_count) {" << endl;
						func_def << "\t\tsetVariableByName(\"" << params[i].second << "\", &args[" << i << "]);" << endl;
						func_def << "\t}" << endl;
					}
					else
					{
						// Register parameter
						func_def << "\tif (" << i << " < arg_count) {" << endl;
						func_def << "\t\tregs[" << (int)params[i].first << "] = args[" << i << "];" << endl;
						func_def << "\t}" << endl;
					}
				}

				// Parse function body recursively into func_def so that
				// nested function definitions go to context.out_script_defs (before us)
				// while our body opcodes stay in the correct function scope.
				func_def << endl << "\t// Function body (" << code_size << " bytes)" << endl;

				// Save the function body boundaries
				char* func_body_start = action_buffer;
				char* func_body_end = action_buffer + code_size;

				// Create a temporary buffer for the function body that ends with END_OF_ACTIONS
				// This ensures parseActions stops at the right place
				char* temp_buffer = (char*)malloc(code_size + 1);
				memcpy(temp_buffer, func_body_start, code_size);
				temp_buffer[code_size] = 0x00; // Add END_OF_ACTIONS marker

				// Set flag to indicate we're inside a DefineFunction2 (for local register handling)
				bool prev_inside_function2 = context.inside_function2;
				int prev_function2_register_count = context.function2_register_count;
				context.inside_function2 = true;
				context.function2_register_count = (int)register_count;

				char* temp_ptr = temp_buffer;
				parseActions(context, temp_ptr, func_def);
				free(temp_buffer);

				// Restore previous state
				context.inside_function2 = prev_inside_function2;
				context.function2_register_count = prev_function2_register_count;

				// Advance the actual buffer past the function body
				action_buffer = func_body_end;

				func_def << endl << "\t// Return undefined if no explicit return" << endl;
				func_def << "\tActionVar ret;" << endl;
				func_def << "\tret.type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
				func_def << "\tret.data.numeric_value = 0;" << endl;
				func_def << "\treturn ret;" << endl;
				func_def << "}" << endl;

				// Flush the complete function definition to out_script_defs.
				// Nested function defs have already been written there by recursive calls,
				// so this function appears AFTER its dependencies.
				context.out_script_defs << func_def.str();

				// Generate runtime call to register function
				out_script << "\t// DefineFunction2: " << (name_len > 0 ? func_name : "(anonymous)") << endl;
				out_script << "\tactionDefineFunction2(app_context, \"" << (name_len > 0 ? func_name : "") << "\", "
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

				// Always read catch name or register (field is present regardless of has_catch)
				std::string catch_name;
				u8 catch_register = 0;
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

				// Compute block boundary addresses
				char* try_body = action_buffer;
				char* catch_body = try_body + try_size;
				char* finally_body = catch_body + catch_size;
				char* after_try = finally_body + finally_size;

				// Push boundary info for inline parsing (no temp buffers)
				TryBlockBoundary boundary;
				boundary.catch_start = has_catch ? catch_body : nullptr;
				boundary.finally_start = has_finally ? finally_body : nullptr;
				boundary.after_end = after_try;
				boundary.has_catch = has_catch;
				boundary.has_finally = has_finally;
				boundary.catch_in_register = catch_in_register;
				boundary.catch_name = catch_name;
				boundary.catch_register = catch_register;
				boundary.state = 0; // Starting in try body
				try_boundaries.push_back(boundary);

				// Emit try block header
				out_script << "\t" << "// Try-Catch-Finally" << endl;
				out_script << "\t" << "actionTryBegin(app_context);" << endl;
				out_script << "\t" << "if (ACTION_TRY_SETJMP(app_context) == 0) {" << endl;
				out_script << "\t\t" << "// Try block" << endl;

				// action_buffer now points to try_body start
				// The main loop will continue parsing try body actions inline
				// Boundary transitions (catch/finally/end) are handled at the top of the loop
				break;
			}

				case SWF_ACTION_WITH:
				{
					// Read block size from bytecode
					u16 block_size = VAL(u16, action_buffer);

					// Calculate where the WITH block ends
					// block_end = current position + 2 (block_size field) + block_size (actions)
					// But we need to account for the fact that 'length' already includes everything
					// So block_end should just be: action_buffer + length
					char* block_end = action_buffer + length;

					// Now advance past the block_size field to the start of the actions
					action_buffer += 2;

					// Emit actionWithStart to push object onto scope chain
					// Returns 1 if body should execute, 0 to skip (null/undefined)
					out_script << "\t" << "// WITH block (size=" << block_size << ")" << endl;
					out_script << "\t" << "if (actionWithStart(app_context)) {" << endl;

					// Copy the WITH block content and add END marker for parseActions
					// This is necessary because parseActions parses until it hits END (0x00)
					char* temp_buffer = (char*) malloc(block_size + 1);
					memcpy(temp_buffer, action_buffer, block_size);
					temp_buffer[block_size] = 0x00; // Add END_OF_ACTIONS marker

					char* temp_ptr = temp_buffer;
					parseActions(context, temp_ptr, out_script);
					free(temp_buffer);

					// Emit actionWithEnd to pop object from scope chain
					out_script << "\t" << "}" << endl;
					out_script << "\t" << "actionWithEnd(app_context);" << endl;

					// Move action_buffer past the WITH body.
					// Length only covers the 2-byte Size field (not the body),
					// so block_end = data_start + 2 = start of body.
					// We need to skip past the body too.
					action_buffer = block_end + block_size;

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
								           << "strlen(str_" << to_string(str_id) << "), " << str_id << ");" << endl;

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

							case ACTION_STACK_VALUE_F64:
							{
								out_script << "(double)" << endl;

								// SWF stores doubles in middle-endian (word-swapped) format:
								// the two 32-bit halves are stored high-word first, then low-word
								u64 raw = VAL(u64, &action_buffer[push_length]);
								push_length += 8;
								// Swap the two 32-bit halves to get correct IEEE 754 double
								u32 lo = (u32)(raw & 0xFFFFFFFF);
								u32 hi = (u32)((raw >> 32) & 0xFFFFFFFF);
								raw = ((u64)lo << 32) | (u64)hi;

								char hex_double[19];
								snprintf(hex_double, 19, "0x%016llX", (unsigned long long) raw);

								out_script << "\t" << "PUSH(ACTION_STACK_VALUE_F64, " << hex_double << "ULL);" << endl;

								break;
							}

							case ACTION_STACK_VALUE_I32:
							{
								s32 int_value = VAL(s32, &action_buffer[push_length]);
								push_length += 4;

								out_script << "(integer: " << int_value << ")" << endl;

								// Push as F64 via bit-cast of the double value
								double d = (double) int_value;
								u64 raw;
								memcpy(&raw, &d, sizeof(raw));

								char hex_double[19];
								snprintf(hex_double, 19, "0x%016llX", (unsigned long long) raw);

								out_script << "\t" << "PUSH(ACTION_STACK_VALUE_F64, " << hex_double << "ULL);" << endl;

								break;
							}

						case ACTION_STACK_VALUE_REGISTER:
						{
							u8 register_num = (u8) action_buffer[push_length];
							push_length += 1;

							out_script << "(Register " << (int)register_num << ")" << endl;

							if (context.inside_function2)
							{
								if ((int)register_num < context.function2_register_count)
								{
									// Inside DefineFunction2, register is local: use local registers array
									out_script << "\t" << "pushVar(app_context, &regs[" << (int)register_num << "]);" << endl;
								}
								else
								{
									// Inside DefineFunction2, register bleeds through to caller: use global
									out_script << "\t" << "actionPushRegister(app_context, " << (int)register_num << ");" << endl;
								}
							}
							else
							{
								// Outside functions: use global registers
								out_script << "\t" << "actionPushRegister(app_context, " << (int)register_num << ");" << endl;
							}

							break;
						}

						case ACTION_STACK_VALUE_NULL:
						{
							out_script << "(null)" << endl;
							out_script << "\t" << "PUSH(ACTION_STACK_VALUE_NULL, 0);" << endl;

							break;
						}

						case ACTION_STACK_VALUE_UNDEFINED:
						{
							out_script << "(undefined)" << endl;
							out_script << "\t" << "PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);" << endl;

							break;
						}

						case ACTION_STACK_VALUE_BOOLEAN:
						{
							u8 bool_value = (u8) action_buffer[push_length];
							push_length += 1;

							out_script << "(boolean: " << (bool_value ? "true" : "false") << ")" << endl;
							out_script << "\t" << "PUSH(ACTION_STACK_VALUE_BOOLEAN, " << (int)bool_value << ");" << endl;

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
								fprintf(stderr, "Undefined push type: %d\n", push_type);
								out_script << "\t" << "// Undefined push type: " << (int)push_type << endl;
								// Skip remaining push data since we don't know the size
								push_length = length;
								break;
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
							   << "\t" << "if (evaluateCondition(app_context))" << endl
							   << "\t" << "{" << endl
							   << "\t" << "\t" << "goto label_" << to_string((s16) (action_buffer + length - action_buffer_start + offset)) << ";" << endl
							   << "\t" << "}" << endl;

					action_buffer += length;

					break;
				}

				case SWF_ACTION_CALL:
				{
					out_script << "\t" << "// Call" << endl
							   << "\t" << "actionCall(app_context);" << endl;

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
						// Read scene_bias byte-by-byte to avoid potential alignment issues
						scene_bias = (u8)action_buffer[1] | ((u16)(u8)action_buffer[2] << 8);
					}

					out_script << "\t" << "// GotoFrame2 (play=" << (int)play_flag
							   << ", sceneBias=" << scene_bias << ")" << endl
							   << "\t" << "actionGotoFrame2(app_context, "
							   << (int)play_flag << ", " << scene_bias << ");" << endl;

					action_buffer += length;

					break;
				}

				case SWF_ACTION_GET_URL2:
				{
					// Read flags byte
					u8 flags = VAL(u8, action_buffer);

					u8 send_vars_method = (flags & 0x03);        // Bits 0-1
					u8 load_target_flag = (flags & 0x40) >> 6;   // Bit 6
					u8 load_variables_flag = (flags & 0x80) >> 7; // Bit 7

					const char* method_str = "NONE";
					if (send_vars_method == 1) method_str = "GET";
					else if (send_vars_method == 2) method_str = "POST";

					out_script << "\t" << "// GetURL2: method=" << method_str
							   << ", loadTarget=" << (int)load_target_flag
							   << ", loadVars=" << (int)load_variables_flag << endl
							   << "\t" << "actionGetURL2(app_context, "
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
				std::string func_id = std::string("func_") + (name_len > 0 ? sanitize_identifier(func_name) : "anonymous") + "_" + std::to_string(func_counter++);

				// Add function declaration to header (uses app_context)
				context.out_script_decls << endl << "ActionVar " << func_id << "(SWFAppContext* app_context);" << endl;

				// Buffer entire function definition in a stringstream so that
				// nested function definitions appear BEFORE this function in the output.
				stringstream func_def;

				// Generate function definition (returns ActionVar for consistency with DefineFunction2)
				func_def << endl << endl
					<< "// DefineFunction: " << (name_len > 0 ? func_name : "(anonymous)") << endl
					<< "ActionVar " << func_id << "(SWFAppContext* app_context)" << endl
					<< "{" << endl
					<< "\tchar str_buffer[17];" << endl;

				// Bind parameters (simple DefineFunction uses variables, not registers)
				// Parameters are pushed onto the stack by actionCallFunction in order
				// Pop them in reverse order and set as local variables
				if (params.size() > 0)
				{
					func_def << "\t// Bind " << params.size() << " parameter(s) from stack" << endl;
					func_def << "\t{" << endl;
					for (int i = (int)params.size() - 1; i >= 0; i--)
					{
						func_def << "\t\tActionVar _param_" << i << ";" << endl;
						func_def << "\t\tpopVar(app_context, &_param_" << i << ");" << endl;
						func_def << "\t\tsetVariableByName(\"" << params[i] << "\", &_param_" << i << ");" << endl;
					}
					func_def << "\t}" << endl;
				}

				// Parse function body recursively into func_def so that
				// nested function definitions go to context.out_script_defs (before us)
				// while our body opcodes stay in the correct function scope.
				func_def << endl << "\t// Function body (" << code_size << " bytes)" << endl;

				char* func_body_start = action_buffer;
				char* func_body_end = action_buffer + code_size;

				// Create temporary buffer with END_OF_ACTIONS marker
				char* temp_buffer = (char*)malloc(code_size + 1);
				memcpy(temp_buffer, func_body_start, code_size);
				temp_buffer[code_size] = 0x00;

				char* temp_ptr = temp_buffer;
				parseActions(context, temp_ptr, func_def);
				free(temp_buffer);

				action_buffer = func_body_end;

				// Default return for functions without explicit Return action
				func_def << "\tActionVar _default_ret = {0};" << endl;
				func_def << "\t_default_ret.type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
				func_def << "\treturn _default_ret;" << endl;
				func_def << "}" << endl;

				// Flush the complete function definition to out_script_defs.
				// Nested function defs have already been written there by recursive calls.
				context.out_script_defs << func_def.str();

				// Generate runtime call to register function
				out_script << "\t// DefineFunction: " << (name_len > 0 ? func_name : "(anonymous)") << endl;
				out_script << "\tactionDefineFunction(app_context, \"" << (name_len > 0 ? func_name : "") << "\", "
						   << "(void(*)(SWFAppContext*))" << func_id << ", " << num_params << ");" << endl;

				break;
			}

			case SWF_ACTION_CALL_FUNCTION:
			{
				out_script << "\t" << "// CallFunction" << endl
						   << "\t" << "actionCallFunction(app_context, str_buffer);" << endl;

				break;
			}

			case SWF_ACTION_CALL_METHOD:
			{
				out_script << "\t" << "// CallMethod" << endl
						   << "\t" << "actionCallMethod(app_context, str_buffer);" << endl;

				break;
			}

				default:
				{
					fprintf(stderr, "Unimplemented action 0x%02X\n", code);
					out_script << "\t" << "// Unimplemented action 0x"
							   << std::hex << (int)code << std::dec << endl;

					break;
				}
			}
		}

		parse_depth--;

		// Only emit string definitions and MAX_STRING_ID at the outermost level
		// (not inside recursive calls from DefineFunction/DefineFunction2/Try)
		if (parse_depth == 0)
		{
			// Flush pending string definitions at file scope
			std::string defs = pending_string_defs.str();
			if (!defs.empty())
			{
				context.out_script_defs << defs;
				pending_string_defs.str("");
				pending_string_defs.clear();
			}

			// Generate MAX_STRING_ID constant for runtime initialization
			context.out_script_defs << endl << endl
			                        << "// Maximum string ID for variable array allocation" << endl
			                        << "#define MAX_STRING_ID " << next_str_i << endl;
			context.out_script_decls << endl
			                         << "#define MAX_STRING_ID " << next_str_i << endl;
		}

		// Restore parent's constant pool (so recursive calls from
		// DefineFunction2/Try/With don't destroy the caller's pool)
		constant_pool = saved_pool;
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
		pending_string_defs << endl << "char* str_" << next_str_i << " = \"" << escape_c_string(str, context.swf_version) << "\";";
		context.out_script_decls << endl << "extern char* str_" << next_str_i << ";";
		next_str_i += 1;
	}
	
	void SWFAction::declareEmptyString(Context& context, size_t size)
	{
		pending_string_defs << endl << "char str_" << next_str_i << "[" << to_string(size) << "];";
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
