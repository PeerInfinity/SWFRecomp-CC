// AVM2 C emitter — see abc_emit.hpp. Output layout (RecompiledABC/):
//
//   abc_gen.h        extern decls for every emitted tag's data
//   abc<i>_tables.c  interned strings, int/uint/double pools, namespaces/
//                    ns-sets, multinames, class/script/trait registry,
//                    Avm2AbcFileData
//   abc<i>_methods.c one C function per verified method body + the
//                    Avm2AbcMethodData table (fn ptrs, signatures,
//                    activation traits, exception data)
//   abc_registry.c   file list + SymbolClass bindings (finalize())
//
// Method bodies compile the verified IR (abc_ir.hpp) against the runtime
// contract in SWFModernRuntime/include/avm2/{avm2_abc.h,avm2_ops.h}: the
// operand stack is a C local array sized by computed_max_stack (dynamic sp
// within a static bound), locals are a C array, the local scope stack a C
// array of Avm2ScopeEntry. Stage 3: bodies are emitted IN FULL — every op
// that is a branch/switch/exception target gets an `op_N:` label, branch
// ops become gotos, and unsupported ops emit an inline (noreturn) abort
// WITHOUT truncating the remainder, so partially-supported bodies with
// branches still compile correctly.
//
// Bodies with an active exception table push an Avm2TryFrame in their
// prologue; avm2_throw longjmps back into the setjmp there, which
// dispatches to the matching handler's op label with the thrown value as
// the sole stack entry (Ruffle activation.rs handle_err semantics). `sp`
// and `scope_n` are declared volatile in such bodies (they are assigned
// before use after the longjmp, but volatile also silences -Wclobbered);
// the value arrays are address-taken and therefore memory-resident.

#include <cinttypes>
#include <cstdio>
#include <fstream>
#include <set>
#include <sstream>
#include <sys/stat.h>

#include <abc/abc_dump.hpp>
#include <abc/abc_emit.hpp>

using std::endl;
using std::ofstream;
using std::string;
using std::to_string;

namespace SWFRecomp
{
namespace abc
{
	// Escapes raw bytes for a C string literal. Octal escapes are always
	// 3 digits so a following digit can't extend them.
	static string escapeCString(const string& s)
	{
		string out;
		out.reserve(s.size() + 8);
		char buf[8];
		for (unsigned char c : s)
		{
			switch (c)
			{
				case '"': out += "\\\""; break;
				case '\\': out += "\\\\"; break;
				case '\n': out += "\\n"; break;
				case '\r': out += "\\r"; break;
				case '\t': out += "\\t"; break;
				default:
					if (c >= 0x20 && c < 0x7f)
					{
						out += (char) c;
					}
					else
					{
						snprintf(buf, sizeof(buf), "\\%03o", c);
						out += buf;
					}
			}
		}
		return out;
	}

	// Makes text safe inside a // comment: single line, and never ending
	// in a backslash (which would splice the next source line into the
	// comment via line continuation).
	static string sanitizeComment(const string& s)
	{
		string out = s;
		for (char& c : out)
		{
			if (c == '\n' || c == '\r') c = ' ';
		}
		if (!out.empty() && out.back() == '\\') out += ' ';
		return out;
	}

	// A C double literal that round-trips the exact IEEE value.
	static string doubleLiteral(double d)
	{
		if (d != d) return "__builtin_nan(\"\")";
		if (d > 1.7976931348623157e308) return "__builtin_inf()";
		if (d < -1.7976931348623157e308) return "-__builtin_inf()";
		char buf[64];
		snprintf(buf, sizeof(buf), "%.17g", d);
		// Ensure it parses as a double (contains '.', 'e', or inf/nan).
		string s = buf;
		if (s.find_first_of(".eE") == string::npos) s += ".0";
		return s;
	}

	AbcEmitter::AbcEmitter(string output_folder)
		: folder_(std::move(output_folder))
	{
	}

	void AbcEmitter::ensureDir()
	{
		if (!dir_created_)
		{
			mkdir(folder_.c_str(), 0755);
			dir_created_ = true;
		}
	}

	static void emitDefault(std::ostringstream& o, const DefaultValue& v)
	{
		o << "{ " << (v.present ? 1 : 0) << ", " << (unsigned) v.kind << ", "
		  << v.index << " }";
	}

	static void emitTraitArray(ofstream& out, const string& sym,
	                           const std::vector<AbcTrait>& traits)
	{
		if (traits.empty()) return;
		out << "static const Avm2AbcTrait " << sym << "[] =" << endl << "{" << endl;
		for (const AbcTrait& t : traits)
		{
			std::ostringstream dv;
			emitDefault(dv, t.value);
			out << "\t{ " << (unsigned) t.kind << ", " << t.name << ", "
			    << t.slot_or_disp_id << ", " << t.type_name << ", "
			    << t.method_or_class << ", " << dv.str() << " }," << endl;
		}
		out << "};" << endl << endl;
	}

	static string traitArrayRef(const string& sym, size_t count)
	{
		if (count == 0) return "0, NULL";
		return to_string(count) + ", " + sym;
	}

	// ------------------------------------------------------------------
	// Method-body emission
	// ------------------------------------------------------------------

	struct BodyCtx
	{
		const AbcFile* abc;
		u32 method_index;
		bool has_exc;  // any active exception entry (try frame pushed)
		// Class/script initializer: avmplus runs these in "interpreter
		// mode", whose index fast path ignores the ns set.
		bool interp_mode;
	};

	static bool mnLazyName(const AbcFile& abc, u32 mn)
	{
		return abc.pool.multinames[mn].hasLazyName();
	}

	static bool mnLazyNs(const AbcFile& abc, u32 mn)
	{
		return abc.pool.multinames[mn].hasLazyNs();
	}

	// Emits one op's C. Returns false if the op is unsupported (caller
	// emits an inline abort and continues with the next op).
	static bool emitOp(ofstream& out, const BodyCtx& bc, const IrOp& op)
	{
		const AbcFile& abc = *bc.abc;
		switch (op.op)
		{
			// --- locals / pure stack ---
			case IrOpcode::GetLocal:
				out << "\tstk[sp++] = loc[" << op.arg1 << "];" << endl;
				return true;
			case IrOpcode::SetLocal:
				out << "\tloc[" << op.arg1 << "] = stk[--sp];" << endl;
				return true;
			case IrOpcode::Kill:
				out << "\tloc[" << op.arg1 << "] = avm2_undefined();" << endl;
				return true;
			case IrOpcode::Dup:
				out << "\tstk[sp] = stk[sp - 1]; sp++;" << endl;
				return true;
			case IrOpcode::Swap:
				out << "\t{ Avm2Value _t = stk[sp - 1]; stk[sp - 1] = stk[sp - 2]; "
				    << "stk[sp - 2] = _t; }" << endl;
				return true;
			case IrOpcode::Pop:
				out << "\tsp--;" << endl;
				return true;

			// --- pushes ---
			case IrOpcode::PushString:
				out << "\tstk[sp++] = avm2_string(&act->file->data->strings["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::PushInt:
				out << "\tstk[sp++] = avm2_integer(" << op.imm << ");" << endl;
				return true;
			case IrOpcode::PushDouble:
				out << "\tstk[sp++] = avm2_number(act->file->data->doubles["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::PushUint:
				out << "\tstk[sp++] = avm2_uint_value(act->file->data->uints["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::PushNaN:
				out << "\tstk[sp++] = avm2_number(__builtin_nan(\"\"));" << endl;
				return true;
			case IrOpcode::PushTrue:
				out << "\tstk[sp++] = avm2_bool(true);" << endl;
				return true;
			case IrOpcode::PushFalse:
				out << "\tstk[sp++] = avm2_bool(false);" << endl;
				return true;
			case IrOpcode::PushNull:
				out << "\tstk[sp++] = avm2_null();" << endl;
				return true;
			case IrOpcode::PushUndefined:
				out << "\tstk[sp++] = avm2_undefined();" << endl;
				return true;
			case IrOpcode::PushNamespace:
				out << "\tstk[sp++] = avm2_op_pushnamespace(act, " << op.arg1
				    << ");" << endl;
				return true;

			// --- control flow ---
			case IrOpcode::Jump:
				out << "\tgoto op_" << op.target << ";" << endl;
				return true;
			case IrOpcode::IfTrue:
				out << "\tif (avm2_coerce_to_boolean(stk[--sp])) goto op_"
				    << op.target << ";" << endl;
				return true;
			case IrOpcode::IfFalse:
				out << "\tif (!avm2_coerce_to_boolean(stk[--sp])) goto op_"
				    << op.target << ";" << endl;
				return true;
			case IrOpcode::LookupSwitch:
				out << "\tswitch (avm2_coerce_to_i32(act->ctx, stk[--sp]))" << endl
				    << "\t{" << endl;
				for (size_t c = 0; c < op.switch_targets.size(); c++)
				{
					out << "\t\tcase " << c << ": goto op_"
					    << op.switch_targets[c] << ";" << endl;
				}
				out << "\t\tdefault: goto op_" << op.target << ";" << endl
				    << "\t}" << endl;
				return true;

			// --- scopes ---
			case IrOpcode::PushScope:
				out << "\tsp--; lscope[scope_n].obj = avm2_op_pushscope(act, stk[sp]); "
				    << "lscope[scope_n].is_with = 0; scope_n++;" << endl;
				return true;
			case IrOpcode::PushWith:
				out << "\tsp--; lscope[scope_n].obj = avm2_op_pushscope(act, stk[sp]); "
				    << "lscope[scope_n].is_with = 1; scope_n++;" << endl;
				return true;
			case IrOpcode::PopScope:
				out << "\tscope_n--;" << endl;
				return true;
			case IrOpcode::GetScopeObject:
				out << "\tstk[sp++] = avm2_object_value(lscope[" << op.arg1
				    << "].obj);" << endl;
				return true;
			case IrOpcode::GetOuterScope:
				out << "\tstk[sp++] = avm2_object_value(avm2_op_getouterscope(act, "
				    << op.arg1 << "));" << endl;
				return true;
			case IrOpcode::GetGlobalScope:
				out << "\tstk[sp++] = avm2_object_value(avm2_op_getglobalscope(act, "
				    << "lscope, scope_n));" << endl;
				return true;

			// --- name lookup ---
			case IrOpcode::FindPropStrict:
			case IrOpcode::FindProperty:
			{
				const char* strict = (op.op == IrOpcode::FindPropStrict) ? "1" : "0";
				if (mnLazyNs(abc, op.arg1))
				{
					// RTQName pops [ns]; RTQNameL pops [ns, name].
					if (mnLazyName(abc, op.arg1))
					{
						out << "\tsp -= 2; stk[sp] = avm2_object_value("
						    << "avm2_op_findproperty_rtns_l(act, lscope, scope_n, "
						    << op.arg1 << ", stk[sp], stk[sp + 1], " << strict
						    << ")); sp++;" << endl;
					}
					else
					{
						out << "\tsp--; stk[sp] = avm2_object_value("
						    << "avm2_op_findproperty_rtns(act, lscope, scope_n, "
						    << op.arg1 << ", stk[sp], " << strict << ")); sp++;" << endl;
					}
					return true;
				}
				if (mnLazyName(abc, op.arg1))
				{
					out << "\tsp--; stk[sp] = avm2_object_value(avm2_op_findproperty_dyn(act, "
					    << "lscope, scope_n, " << op.arg1 << ", stk[sp], " << strict
					    << ")); sp++;" << endl;
				}
				else
				{
					out << "\tstk[sp++] = avm2_object_value(avm2_op_findproperty(act, "
					    << "lscope, scope_n, " << op.arg1 << ", " << strict << "));" << endl;
				}
				return true;
			}
			case IrOpcode::FindDef:
				out << "\tstk[sp++] = avm2_object_value(avm2_op_finddef(act, "
				    << op.arg1 << "));" << endl;
				return true;

			// --- properties ---
			case IrOpcode::GetPropertyStatic:
				// Per-call-site monomorphic inline cache: a block-scoped static
				// gives each getproperty its own cache slot (avm2_ops.h).
				out << "\t{ static Avm2InlineCache __ic; stk[sp - 1] = "
				       "avm2_op_getproperty_static_ic(act, stk[sp - 1], "
				    << op.arg1 << ", &__ic); }" << endl;
				return true;
			case IrOpcode::GetPropertyFast:
			case IrOpcode::GetPropertySlow:
				if (mnLazyNs(abc, op.arg1))
				{
					if (mnLazyName(abc, op.arg1))
					{
						// RTQNameL: [obj, ns, name]
						out << "\tsp -= 3; stk[sp] = avm2_op_getproperty_rtns_l(act, "
						    << "stk[sp], " << op.arg1
						    << ", stk[sp + 1], stk[sp + 2]); sp++;" << endl;
					}
					else
					{
						// RTQName: [obj, ns]
						out << "\tsp -= 2; stk[sp] = avm2_op_getproperty_rtns(act, "
						    << "stk[sp], " << op.arg1 << ", stk[sp + 1]); sp++;" << endl;
					}
					return true;
				}
				out << "\tsp -= 2; stk[sp] = avm2_op_getproperty_dyn(act, stk[sp], "
				    << op.arg1 << ", stk[sp + 1], " << (bc.interp_mode ? 1 : 0)
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::SetPropertyStatic:
				out << "\tsp -= 2; avm2_op_setproperty_static(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1]);" << endl;
				return true;
			case IrOpcode::SetPropertyFast:
			case IrOpcode::SetPropertySlow:
				if (mnLazyNs(abc, op.arg1))
				{
					if (mnLazyName(abc, op.arg1))
					{
						// RTQNameL: [obj, ns, name, value]
						out << "\tsp -= 4; avm2_op_setproperty_rtns_l(act, stk[sp], "
						    << op.arg1 << ", stk[sp + 1], stk[sp + 2], stk[sp + 3]);"
						    << endl;
					}
					else
					{
						// RTQName: [obj, ns, value]
						out << "\tsp -= 3; avm2_op_setproperty_rtns(act, stk[sp], "
						    << op.arg1 << ", stk[sp + 1], stk[sp + 2]);" << endl;
					}
					return true;
				}
				out << "\tsp -= 3; avm2_op_setproperty_dyn(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1], stk[sp + 2], " << (bc.interp_mode ? 1 : 0)
				    << ");" << endl;
				return true;
			case IrOpcode::InitProperty:
				if (mnLazyName(abc, op.arg1) || mnLazyNs(abc, op.arg1)) return false;
				out << "\tsp -= 2; avm2_op_initproperty(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1]);" << endl;
				return true;
			case IrOpcode::DeleteProperty:
				if (mnLazyNs(abc, op.arg1))
				{
					if (mnLazyName(abc, op.arg1))
					{
						out << "\tsp -= 3; stk[sp] = avm2_op_deleteproperty_rtns_l(act, "
						    << "stk[sp], " << op.arg1
						    << ", stk[sp + 1], stk[sp + 2]); sp++;" << endl;
					}
					else
					{
						out << "\tsp -= 2; stk[sp] = avm2_op_deleteproperty_rtns(act, "
						    << "stk[sp], " << op.arg1 << ", stk[sp + 1]); sp++;" << endl;
					}
					return true;
				}
				if (mnLazyName(abc, op.arg1))
				{
					out << "\tsp--; stk[sp - 1] = avm2_op_deleteproperty_dyn(act, "
					    << "stk[sp - 1], " << op.arg1 << ", stk[sp]);" << endl;
				}
				else
				{
					out << "\tstk[sp - 1] = avm2_op_deleteproperty(act, stk[sp - 1], "
					    << op.arg1 << ");" << endl;
				}
				return true;

			// --- slots ---
			case IrOpcode::GetSlot:
				out << "\tstk[sp - 1] = avm2_op_getslot(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::SetSlot:
				out << "\tsp -= 2; avm2_op_setslot(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1]);" << endl;
				return true;
			case IrOpcode::GetGlobalSlot:
				out << "\tstk[sp++] = avm2_op_getslot(act, avm2_object_value("
				    << "avm2_op_getglobalscope(act, lscope, scope_n)), "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::SetGlobalSlot:
				out << "\tavm2_op_setslot(act, avm2_object_value("
				    << "avm2_op_getglobalscope(act, lscope, scope_n)), "
				    << op.arg1 << ", stk[--sp]);" << endl;
				return true;

			// --- calls ---
			case IrOpcode::CallProperty:
			case IrOpcode::CallPropVoid:
			{
				bool is_void = (op.op == IrOpcode::CallPropVoid);
				if (mnLazyNs(abc, op.arg1))
				{
					if (mnLazyName(abc, op.arg1))
					{
						// RTQNameL: [obj, ns, name, args...]
						out << "\tsp -= " << (op.arg2 + 3) << "; "
						    << (is_void ? "" : "stk[sp] = ")
						    << "avm2_op_callproperty_rtns_l(act, stk[sp], " << op.arg1
						    << ", stk[sp + 1], stk[sp + 2], &stk[sp + 3], " << op.arg2
						    << ");" << (is_void ? "" : " sp++;") << endl;
					}
					else
					{
						// RTQName: [obj, ns, args...]
						out << "\tsp -= " << (op.arg2 + 2) << "; "
						    << (is_void ? "" : "stk[sp] = ")
						    << "avm2_op_callproperty_rtns(act, stk[sp], " << op.arg1
						    << ", stk[sp + 1], &stk[sp + 2], " << op.arg2 << ");"
						    << (is_void ? "" : " sp++;") << endl;
					}
					return true;
				}
				if (mnLazyName(abc, op.arg1))
				{
					out << "\tsp -= " << (op.arg2 + 2) << "; "
					    << (is_void ? "" : "stk[sp] = ")
					    << "avm2_op_callproperty_dyn(act, stk[sp], " << op.arg1
					    << ", stk[sp + 1], &stk[sp + 2], " << op.arg2 << ");"
					    << (is_void ? "" : " sp++;") << endl;
				}
				else
				{
					out << "\tsp -= " << (op.arg2 + 1) << "; "
					    << (is_void ? "" : "stk[sp] = ")
					    << "avm2_op_callproperty(act, stk[sp], " << op.arg1
					    << ", &stk[sp + 1], " << op.arg2 << ");"
					    << (is_void ? "" : " sp++;") << endl;
				}
				return true;
			}
			case IrOpcode::CallPropLex:
				if (mnLazyName(abc, op.arg1) || mnLazyNs(abc, op.arg1)) return false;
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_callproplex(act, "
				    << "stk[sp], " << op.arg1 << ", &stk[sp + 1], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::Call:
				out << "\tsp -= " << (op.arg2 + 2) << "; stk[sp] = avm2_op_call(act, "
				    << "stk[sp], stk[sp + 1], &stk[sp + 2], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::CallStatic:
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_callstatic(act, "
				    << op.arg1 << ", stk[sp], &stk[sp + 1], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::CallSuper:
				if (mnLazyName(abc, op.arg1) || mnLazyNs(abc, op.arg1)) return false;
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_callsuper(act, "
				    << "stk[sp], " << op.arg1 << ", &stk[sp + 1], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::GetSuper:
				if (mnLazyName(abc, op.arg1) || mnLazyNs(abc, op.arg1)) return false;
				out << "\tstk[sp - 1] = avm2_op_getsuper(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::SetSuper:
				if (mnLazyName(abc, op.arg1) || mnLazyNs(abc, op.arg1)) return false;
				out << "\tsp -= 2; avm2_op_setsuper(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1]);" << endl;
				return true;

			case IrOpcode::ApplyType:
				out << "\tsp -= " << op.arg2 << "; stk[sp - 1] = avm2_op_applytype(act, "
				    << "stk[sp - 1], &stk[sp], " << op.arg2 << ");" << endl;
				return true;

			// --- construction ---
			case IrOpcode::Construct:
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_construct(act, "
				    << "stk[sp], &stk[sp + 1], " << op.arg2 << "); sp++;" << endl;
				return true;
			case IrOpcode::ConstructProp:
				if (mnLazyNs(abc, op.arg1)) return false;
				if (mnLazyName(abc, op.arg1))
				{
					out << "\tsp -= " << (op.arg2 + 2) << "; stk[sp] = "
					    << "avm2_op_constructprop_dyn(act, stk[sp], " << op.arg1
					    << ", stk[sp + 1], &stk[sp + 2], " << op.arg2 << "); sp++;" << endl;
				}
				else
				{
					out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = "
					    << "avm2_op_constructprop(act, stk[sp], " << op.arg1
					    << ", &stk[sp + 1], " << op.arg2 << "); sp++;" << endl;
				}
				return true;
			case IrOpcode::ConstructSuper:
				out << "\tsp -= " << (op.arg2 + 1) << "; avm2_op_constructsuper(act, "
				    << "stk[sp], &stk[sp + 1], " << op.arg2 << ");" << endl;
				return true;

			// --- object model ---
			case IrOpcode::NewClass:
				out << "\tstk[sp - 1] = avm2_op_newclass(act, " << op.arg1
				    << ", stk[sp - 1], lscope, scope_n);" << endl;
				return true;
			case IrOpcode::NewFunction:
				out << "\tstk[sp++] = avm2_op_newfunction(act, " << op.arg1
				    << ", lscope, scope_n);" << endl;
				return true;
			case IrOpcode::NewActivation:
				out << "\tstk[sp++] = avm2_op_newactivation(act, "
				    << bc.method_index << ");" << endl;
				return true;
			case IrOpcode::NewCatch:
				out << "\tstk[sp++] = avm2_op_newcatch(act, " << bc.method_index
				    << ", " << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::NewObject:
				out << "\tsp -= " << (op.arg2 * 2) << "; stk[sp] = avm2_op_newobject(act, "
				    << "&stk[sp], " << op.arg2 << "); sp++;" << endl;
				return true;
			case IrOpcode::NewArray:
				out << "\tsp -= " << op.arg2 << "; stk[sp] = avm2_op_newarray(act, "
				    << "&stk[sp], " << op.arg2 << "); sp++;" << endl;
				return true;

			// --- operators (binary) ---
#define BINOP(irname, helper) \
			case IrOpcode::irname: \
				out << "\tsp--; stk[sp - 1] = " helper "(act, stk[sp - 1], stk[sp]);" << endl; \
				return true;
			BINOP(Add, "avm2_op_add")
			BINOP(Subtract, "avm2_op_subtract")
			BINOP(Multiply, "avm2_op_multiply")
			BINOP(Divide, "avm2_op_divide")
			BINOP(Modulo, "avm2_op_modulo")
			BINOP(AddI, "avm2_op_add_i")
			BINOP(SubtractI, "avm2_op_subtract_i")
			BINOP(MultiplyI, "avm2_op_multiply_i")
			BINOP(BitAnd, "avm2_op_bitand")
			BINOP(BitOr, "avm2_op_bitor")
			BINOP(BitXor, "avm2_op_bitxor")
			BINOP(LShift, "avm2_op_lshift")
			BINOP(RShift, "avm2_op_rshift")
			BINOP(URShift, "avm2_op_urshift")
			BINOP(Equals, "avm2_op_equals")
			BINOP(StrictEquals, "avm2_op_strictequals")
			BINOP(LessThan, "avm2_op_lessthan")
			BINOP(LessEquals, "avm2_op_lessequals")
			BINOP(GreaterThan, "avm2_op_greaterthan")
			BINOP(GreaterEquals, "avm2_op_greaterequals")
			BINOP(In, "avm2_op_in")
			BINOP(InstanceOf, "avm2_op_instanceof")
			BINOP(IsTypeLate, "avm2_op_istypelate")
			BINOP(AsTypeLate, "avm2_op_astypelate")
			BINOP(HasNext, "avm2_op_hasnext")
			BINOP(NextName, "avm2_op_nextname")
			BINOP(NextValue, "avm2_op_nextvalue")
#undef BINOP

			// --- operators (unary) ---
#define UNOP(irname, helper) \
			case IrOpcode::irname: \
				out << "\tstk[sp - 1] = " helper "(act, stk[sp - 1]);" << endl; \
				return true;
			UNOP(Negate, "avm2_op_negate")
			UNOP(NegateI, "avm2_op_negate_i")
			UNOP(Not, "avm2_op_not")
			UNOP(BitNot, "avm2_op_bitnot")
			UNOP(Increment, "avm2_op_increment")
			UNOP(Decrement, "avm2_op_decrement")
			UNOP(IncrementI, "avm2_op_increment_i")
			UNOP(DecrementI, "avm2_op_decrement_i")
			UNOP(TypeOf, "avm2_op_typeof")
			UNOP(CoerceS, "avm2_op_coerce_s")
			UNOP(ConvertS, "avm2_op_convert_s")
			UNOP(CoerceO, "avm2_op_coerce_o")
			UNOP(ConvertO, "avm2_op_convert_o")
			UNOP(EscXAttr, "avm2_op_esc_xattr")
			UNOP(EscXElem, "avm2_op_esc_xelem")
#undef UNOP

			case IrOpcode::IncLocal:
				out << "\tloc[" << op.arg1 << "] = avm2_op_increment(act, loc["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::DecLocal:
				out << "\tloc[" << op.arg1 << "] = avm2_op_decrement(act, loc["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::IncLocalI:
				out << "\tloc[" << op.arg1 << "] = avm2_op_increment_i(act, loc["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::DecLocalI:
				out << "\tloc[" << op.arg1 << "] = avm2_op_decrement_i(act, loc["
				    << op.arg1 << "]);" << endl;
				return true;

			// --- coercions / type ops ---
			case IrOpcode::CoerceB:
				out << "\tstk[sp - 1] = avm2_bool(avm2_coerce_to_boolean(stk[sp - 1]));" << endl;
				return true;
			case IrOpcode::CoerceD:
				out << "\tstk[sp - 1] = avm2_number(avm2_coerce_to_number(act->ctx, "
				    << "stk[sp - 1]));" << endl;
				return true;
			case IrOpcode::CoerceI:
				out << "\tstk[sp - 1] = avm2_integer(avm2_coerce_to_i32(act->ctx, "
				    << "stk[sp - 1]));" << endl;
				return true;
			case IrOpcode::CoerceU:
				out << "\tstk[sp - 1] = avm2_uint_value(avm2_coerce_to_u32(act->ctx, "
				    << "stk[sp - 1]));" << endl;
				return true;
			case IrOpcode::Coerce:
				out << "\tstk[sp - 1] = avm2_op_coerce(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::IsType:
				out << "\tstk[sp - 1] = avm2_op_istype(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::AsType:
				out << "\tstk[sp - 1] = avm2_op_astype(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;

			// --- E4X ---
			case IrOpcode::GetDescendants:
				if (mnLazyNs(abc, op.arg1))
				{
					if (mnLazyName(abc, op.arg1))
					{
						// RTQNameL: [obj, ns, name]
						out << "\tsp -= 2; stk[sp - 1] = avm2_op_getdescendants_rtns_l("
						    << "act, stk[sp - 1], " << op.arg1
						    << ", stk[sp], stk[sp + 1]);" << endl;
					}
					else
					{
						// RTQName: [obj, ns]
						out << "\tsp--; stk[sp - 1] = avm2_op_getdescendants_rtns(act, "
						    << "stk[sp - 1], " << op.arg1 << ", stk[sp]);" << endl;
					}
					return true;
				}
				if (mnLazyName(abc, op.arg1))
				{
					out << "\tsp--; stk[sp - 1] = avm2_op_getdescendants_dyn(act, "
					    << "stk[sp - 1], " << op.arg1 << ", stk[sp]);" << endl;
				}
				else
				{
					out << "\tstk[sp - 1] = avm2_op_getdescendants(act, stk[sp - 1], "
					    << op.arg1 << ");" << endl;
				}
				return true;
			case IrOpcode::CheckFilter:
				out << "\tstk[sp - 1] = avm2_op_checkfilter(act, stk[sp - 1]);" << endl;
				return true;
			case IrOpcode::Dxns:
				out << "\tavm2_op_dxns(act, " << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::DxnsLate:
				out << "\tavm2_op_dxnslate(act, stk[--sp]);" << endl;
				return true;

			// --- enumeration ---
			case IrOpcode::HasNext2:
				out << "\tstk[sp++] = avm2_op_hasnext2(act, &loc[" << op.arg1
				    << "], &loc[" << op.arg2 << "]);" << endl;
				return true;

			// --- exceptions ---
			case IrOpcode::Throw:
				out << "\tavm2_op_throw(act, stk[--sp]);" << endl;
				return true;

			// --- returns are handled by the caller (try-frame pop) ---

			// Comment-only ops (the // <op> line above suffices).
			case IrOpcode::CoerceA:
			case IrOpcode::Debug:
			case IrOpcode::DebugFile:
			case IrOpcode::DebugLine:
			case IrOpcode::Bkpt:
			case IrOpcode::BkptLine:
			case IrOpcode::Timestamp:
			case IrOpcode::Nop:
				return true;

			default:
				return false;
		}
	}

	static void emitMethodBody(ofstream& out, const AbcFile& abc, const EmitBody& body,
	                           const string& fn_name, u32 method_index,
	                           const string& exc_sym)
	{
		const string& mname = abc.pool.strings[abc.methods[method_index].name];
		out << "// method[" << method_index << "] \"" << sanitizeComment(mname)
		    << "\" (body " << body.ir.body_index << ")" << endl;
		out << "static Avm2Value " << fn_name << "(Avm2Activation* act)" << endl
		    << "{" << endl;

		if (!body.verified)
		{
			out << "\tavm2_verify_error_body(act, \""
			    << escapeCString(body.verify_error) << "\");" << endl
			    << "}" << endl << endl;
			return;
		}

		const AbcMethodBody& raw_body = abc.method_bodies[body.ir.body_index];
		u32 num_locals = raw_body.num_locals > 0 ? raw_body.num_locals : 1;
		u32 max_stack = body.ir.computed_max_stack > 0 ? body.ir.computed_max_stack : 1;
		u32 max_scope = body.ir.computed_max_scope > 0 ? body.ir.computed_max_scope : 1;

		BodyCtx bc;
		bc.abc = &abc;
		bc.method_index = method_index;
		bc.has_exc = false;
		bc.interp_mode = false;
		for (const AbcClass& c : abc.classes)
		{
			if (c.init_method == method_index) bc.interp_mode = true;
		}
		for (const AbcScript& s : abc.scripts)
		{
			if (s.init_method == method_index) bc.interp_mode = true;
		}
		for (const IrException& e : body.ir.exceptions)
		{
			if (e.active) bc.has_exc = true;
		}

		// Branch/switch/exception targets need op labels.
		std::set<u32> targets;
		for (const IrOp& op : body.ir.ops)
		{
			switch (op.op)
			{
				case IrOpcode::Jump:
				case IrOpcode::IfTrue:
				case IrOpcode::IfFalse:
					targets.insert(op.target);
					break;
				case IrOpcode::LookupSwitch:
					targets.insert(op.target);
					for (u32 t : op.switch_targets) targets.insert(t);
					break;
				default:
					break;
			}
		}
		for (const IrException& e : body.ir.exceptions)
		{
			if (e.active) targets.insert(e.target_op);
		}

		// sp/scope_n are volatile in exception bodies (see file header).
		const char* idx_qual = bc.has_exc ? "volatile uint32_t" : "uint32_t";
		out << "\tAvm2Value loc[" << num_locals << "];" << endl
		    << "\tAvm2Value stk[" << max_stack << "];" << endl
		    << "\t" << idx_qual << " sp = 0;" << endl
		    << "\tAvm2ScopeEntry lscope[" << max_scope << "];" << endl
		    << "\t" << idx_qual << " scope_n = 0;" << endl
		    << "\tavm2_setup_locals(loc, " << num_locals << ", act, "
		    << method_index << ");" << endl
		    << "\t(void) sp; (void) scope_n; (void) stk; (void) lscope; (void) loc;"
		    << endl;

		if (bc.has_exc)
		{
			out << "\tAvm2TryFrame _tf;" << endl
			    << "\tavm2_try_push_frame(act->ctx, &_tf, " << exc_sym << ", "
			    << body.ir.exceptions.size() << ", act->file);" << endl
			    << "\tif (setjmp(_tf.jb))" << endl
			    << "\t{" << endl
			    << "\t\tsp = 0; scope_n = 0;" << endl
			    << "\t\tstk[sp++] = _tf.exc;" << endl
			    << "\t\tswitch (_tf.handler_target)" << endl
			    << "\t\t{" << endl;
			std::set<u32> handler_targets;
			for (const IrException& e : body.ir.exceptions)
			{
				if (e.active) handler_targets.insert(e.target_op);
			}
			for (u32 t : handler_targets)
			{
				out << "\t\t\tcase " << t << ": goto op_" << t << ";" << endl;
			}
			out << "\t\t\tdefault: avm2_fatal(\"bad exception handler target\");" << endl
			    << "\t\t}" << endl
			    << "\t}" << endl;
		}
		out << endl;

		const string mi_str = to_string(method_index);
		bool ret_coerce = abc.methods[method_index].return_type != 0;

		for (size_t i = 0; i < body.ir.ops.size(); i++)
		{
			const IrOp& op = body.ir.ops[i];
			if (targets.count((u32) i))
			{
				out << "op_" << i << ":;" << endl;
			}
			string desc = sanitizeComment(formatIrOp(abc, op));
			out << "\t// " << i << ": " << desc << endl;
			if (bc.has_exc)
			{
				out << "\t_tf.op_index = " << i << ";" << endl;
			}

			if (op.op == IrOpcode::ReturnValue)
			{
				out << "\t{ Avm2Value _rv = stk[--sp];";
				if (ret_coerce)
				{
					out << " _rv = avm2_op_coerce_return(act, " << mi_str << ", _rv);";
				}
				if (bc.has_exc)
				{
					out << " avm2_try_pop_frame(&_tf);";
				}
				out << " return _rv; }" << endl;
				continue;
			}
			if (op.op == IrOpcode::ReturnVoid)
			{
				if (bc.has_exc)
				{
					out << "\tavm2_try_pop_frame(&_tf);" << endl;
				}
				// ReturnVoid yields the return type's default value
				// (undefined coerced to the type: int → 0, Boolean → false).
				if (ret_coerce)
				{
					out << "\treturn avm2_op_coerce_return(act, " << mi_str
					    << ", avm2_undefined());" << endl;
				}
				else
				{
					out << "\treturn avm2_undefined();" << endl;
				}
				continue;
			}

			if (!emitOp(out, bc, op))
			{
				out << "\tavm2_unimplemented_op(act, \"" << escapeCString(desc)
				    << "\", " << i << ");" << endl;
			}
		}

		// The verifier guarantees code cannot fall off the end (1020); keep
		// the C well-formed when the last op wasn't already a return/branch.
		IrOpcode last = body.ir.ops.empty() ? IrOpcode::Nop : body.ir.ops.back().op;
		if (last != IrOpcode::ReturnValue && last != IrOpcode::ReturnVoid)
		{
			out << "\treturn avm2_undefined();" << endl;
		}
		out << "}" << endl << endl;
	}

	void AbcEmitter::emitAbcTag(const AbcFile& abc, const std::vector<EmitBody>& bodies)
	{
		ensureDir();
		int tag = next_tag_index_++;
		string p = "abc" + to_string(tag);

		// ------------------------------------------------------------------
		// abc<tag>_tables.c
		// ------------------------------------------------------------------
		{
			ofstream out(folder_ + "/" + p + "_tables.c");
			out << "// Generated by SWFRecomp (abc_emit.cpp) — static ABC data "
			    << "for DoABC tag " << tag << ". Do not edit." << endl
			    << "#include \"abc_gen.h\"" << endl << endl;

			out << "static const int32_t " << p << "_ints[] =" << endl << "{" << endl;
			for (s32 v : abc.pool.ints)
			{
				out << "\t" << v << "," << endl;
			}
			out << "};" << endl << endl;

			out << "static const uint32_t " << p << "_uints[] =" << endl << "{" << endl;
			for (u32 v : abc.pool.uints)
			{
				out << "\t" << v << "u," << endl;
			}
			out << "};" << endl << endl;

			out << "static const double " << p << "_doubles[] =" << endl << "{" << endl;
			for (double v : abc.pool.doubles)
			{
				out << "\t" << doubleLiteral(v) << "," << endl;
			}
			out << "};" << endl << endl;

			out << "static const Avm2String " << p << "_strings[] =" << endl << "{" << endl;
			for (const string& s : abc.pool.strings)
			{
				out << "\t{ " << s.size() << ", \"" << escapeCString(s) << "\" }," << endl;
			}
			out << "};" << endl << endl;

			out << "static const Avm2AbcNamespace " << p << "_namespaces[] =" << endl
			    << "{" << endl;
			for (const AbcNamespace& ns : abc.pool.namespaces)
			{
				out << "\t{ " << (unsigned) ns.kind << ", " << ns.name << " }," << endl;
			}
			out << "};" << endl << endl;

			for (size_t i = 0; i < abc.pool.ns_sets.size(); i++)
			{
				if (abc.pool.ns_sets[i].empty()) continue;
				out << "static const uint32_t " << p << "_nsset_" << i << "[] = { ";
				for (size_t j = 0; j < abc.pool.ns_sets[i].size(); j++)
				{
					if (j > 0) out << ", ";
					out << abc.pool.ns_sets[i][j];
				}
				out << " };" << endl;
			}
			out << "static const Avm2AbcNsSet " << p << "_ns_sets[] =" << endl
			    << "{" << endl;
			for (size_t i = 0; i < abc.pool.ns_sets.size(); i++)
			{
				if (abc.pool.ns_sets[i].empty())
				{
					out << "\t{ 0, NULL }," << endl;
				}
				else
				{
					out << "\t{ " << abc.pool.ns_sets[i].size() << ", "
					    << p << "_nsset_" << i << " }," << endl;
				}
			}
			out << "};" << endl << endl;

			for (size_t i = 0; i < abc.pool.multinames.size(); i++)
			{
				if (abc.pool.multinames[i].type_params.empty()) continue;
				out << "static const uint32_t " << p << "_mntp_" << i << "[] = { ";
				for (size_t j = 0; j < abc.pool.multinames[i].type_params.size(); j++)
				{
					if (j > 0) out << ", ";
					out << abc.pool.multinames[i].type_params[j];
				}
				out << " };" << endl;
			}
			out << "static const Avm2AbcMultiname " << p << "_multinames[] =" << endl
			    << "{" << endl;
			for (size_t i = 0; i < abc.pool.multinames.size(); i++)
			{
				const AbcMultiname& mn = abc.pool.multinames[i];
				string tp = mn.type_params.empty()
					? "0, NULL"
					: to_string(mn.type_params.size()) + ", " + p + "_mntp_" + to_string(i);
				out << "\t{ " << (unsigned) mn.kind << ", " << mn.ns << ", "
				    << mn.name << ", " << mn.ns_set << ", " << mn.base_type << ", "
				    << tp << " }," << endl;
			}
			out << "};" << endl << endl;

			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				emitTraitArray(out, p + "_c" + to_string(i) + "_it", abc.instances[i].traits);
				emitTraitArray(out, p + "_c" + to_string(i) + "_ct", abc.classes[i].traits);
				if (!abc.instances[i].interfaces.empty())
				{
					out << "static const uint32_t " << p << "_c" << i << "_if[] = { ";
					for (size_t j = 0; j < abc.instances[i].interfaces.size(); j++)
					{
						if (j > 0) out << ", ";
						out << abc.instances[i].interfaces[j];
					}
					out << " };" << endl << endl;
				}
			}
			out << "static const Avm2AbcClassData " << p << "_classes[] =" << endl
			    << "{" << endl;
			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				const AbcInstance& inst = abc.instances[i];
				unsigned flags = 0;
				if (inst.is_sealed) flags |= 1;      // AVM2_CLASS_FLAG_SEALED
				if (inst.is_final) flags |= 2;       // AVM2_CLASS_FLAG_FINAL
				if (inst.is_interface) flags |= 4;   // AVM2_CLASS_FLAG_INTERFACE
				string ifaces = inst.interfaces.empty()
					? "0, NULL"
					: to_string(inst.interfaces.size()) + ", " + p + "_c" + to_string(i) + "_if";
				out << "\t{ " << inst.name << ", " << inst.super_name << ", "
				    << flags << ", " << (inst.has_protected_ns ? 1 : 0) << ", "
				    << inst.protected_ns << ", " << ifaces << ", "
				    << inst.init_method << ", "
				    << abc.classes[i].init_method << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_it", inst.traits.size())
				    << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_ct", abc.classes[i].traits.size())
				    << " }," << endl;
			}
			if (abc.instances.empty())
			{
				out << "\t{ 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, NULL, 0, NULL }," << endl;
			}
			out << "};" << endl << endl;

			for (size_t i = 0; i < abc.scripts.size(); i++)
			{
				emitTraitArray(out, p + "_s" + to_string(i) + "_t", abc.scripts[i].traits);
			}
			out << "static const Avm2AbcScriptData " << p << "_scripts[] =" << endl
			    << "{" << endl;
			for (size_t i = 0; i < abc.scripts.size(); i++)
			{
				out << "\t{ " << abc.scripts[i].init_method << ", "
				    << traitArrayRef(p + "_s" + to_string(i) + "_t", abc.scripts[i].traits.size())
				    << " }," << endl;
			}
			if (abc.scripts.empty()) out << "\t{ 0, 0, NULL }," << endl;
			out << "};" << endl << endl;

			out << "const Avm2AbcFileData " << p << "_data =" << endl << "{" << endl
			    << "\t" << abc.pool.ints.size() << ", " << p << "_ints," << endl
			    << "\t" << abc.pool.uints.size() << ", " << p << "_uints," << endl
			    << "\t" << abc.pool.doubles.size() << ", " << p << "_doubles," << endl
			    << "\t" << abc.pool.strings.size() << ", " << p << "_strings," << endl
			    << "\t" << abc.pool.namespaces.size() << ", " << p << "_namespaces," << endl
			    << "\t" << abc.pool.ns_sets.size() << ", " << p << "_ns_sets," << endl
			    << "\t" << abc.pool.multinames.size() << ", " << p << "_multinames," << endl
			    << "\t" << abc.methods.size() << ", " << p << "_methods," << endl
			    << "\t" << abc.instances.size() << ", " << p << "_classes," << endl
			    << "\t" << abc.scripts.size() << ", " << p << "_scripts," << endl
			    << "};" << endl;
		}

		// ------------------------------------------------------------------
		// abc<tag>_methods.c
		// ------------------------------------------------------------------
		{
			ofstream out(folder_ + "/" + p + "_methods.c");
			out << "// Generated by SWFRecomp (abc_emit.cpp) — method bodies for "
			    << "DoABC tag " << tag << ". Do not edit." << endl
			    << "#include \"abc_gen.h\"" << endl << endl;

			// body index per method (-1 = none).
			std::vector<int> method_body(abc.methods.size(), -1);
			for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
			{
				method_body[abc.method_bodies[bi].method] = (int) bi;
			}

			// Methods realized as function closures (NewFunction ops or
			// Function traits) — Ruffle's Method::is_function.
			std::vector<bool> is_function(abc.methods.size(), false);
			for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
			{
				if (!bodies[bi].verified) continue;
				for (const IrOp& op : bodies[bi].ir.ops)
				{
					if (op.op == IrOpcode::NewFunction && op.arg1 < is_function.size())
					{
						is_function[op.arg1] = true;
					}
				}
			}
			auto mark_function_traits = [&](const std::vector<AbcTrait>& traits)
			{
				for (const AbcTrait& t : traits)
				{
					if (t.kind == TraitKindType::Function
					    && t.method_or_class < is_function.size())
					{
						is_function[t.method_or_class] = true;
					}
				}
			};
			for (const AbcScript& s : abc.scripts) mark_function_traits(s.traits);
			for (const AbcInstance& inst : abc.instances) mark_function_traits(inst.traits);
			for (const AbcClass& c : abc.classes) mark_function_traits(c.traits);
			for (const AbcMethodBody& b : abc.method_bodies) mark_function_traits(b.traits);

			for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
			{
				const EmitBody& body = bodies[bi];
				u32 mi = abc.method_bodies[bi].method;
				string exc_sym = p + "_m" + to_string(mi) + "_exc";

				// Exception data precedes the body (its prologue refers to it).
				if (body.verified && !body.ir.exceptions.empty())
				{
					out << "static const Avm2AbcException " << exc_sym
					    << "[] =" << endl << "{" << endl;
					for (const IrException& e : body.ir.exceptions)
					{
						out << "\t{ " << e.from_op << ", " << e.to_op << ", "
						    << e.target_op << ", " << e.type_name << ", "
						    << e.variable_name << ", " << (e.active ? 1 : 0)
						    << " }," << endl;
					}
					out << "};" << endl << endl;
				}

				// Activation-object traits (NewActivation / NewCatch).
				emitTraitArray(out, p + "_m" + to_string(mi) + "_bt",
				               abc.method_bodies[bi].traits);

				emitMethodBody(out, abc, body, p + "_m" + to_string(mi), mi, exc_sym);
			}

			// Per-method signature arrays (param types + optionals).
			for (size_t mi = 0; mi < abc.methods.size(); mi++)
			{
				const AbcMethod& m = abc.methods[mi];
				if (m.params.empty()) continue;
				out << "static const uint32_t " << p << "_m" << mi << "_pt[] = { ";
				for (size_t j = 0; j < m.params.size(); j++)
				{
					if (j > 0) out << ", ";
					out << m.params[j].type;
				}
				out << " };" << endl;
				bool any_default = false;
				for (const MethodParam& mp : m.params)
				{
					if (mp.default_value.present) any_default = true;
				}
				if (any_default)
				{
					out << "static const Avm2AbcDefault " << p << "_m" << mi
					    << "_po[] = { ";
					for (size_t j = 0; j < m.params.size(); j++)
					{
						if (j > 0) out << ", ";
						std::ostringstream dv;
						emitDefault(dv, m.params[j].default_value);
						out << dv.str();
					}
					out << " };" << endl;
				}
			}
			out << endl;

			out << "const Avm2AbcMethodData " << p << "_methods[] =" << endl
			    << "{" << endl;
			for (size_t mi = 0; mi < abc.methods.size(); mi++)
			{
				const AbcMethod& m = abc.methods[mi];
				int bi = method_body[mi];
				bool has_exc = bi >= 0 && bodies[bi].verified
				               && !bodies[bi].ir.exceptions.empty();
				bool any_default = false;
				for (const MethodParam& mp : m.params)
				{
					if (mp.default_value.present) any_default = true;
				}
				bool has_bt = bi >= 0 && !abc.method_bodies[bi].traits.empty();
				out << "\t{ ";
				if (bi >= 0)
				{
					out << p << "_m" << mi;
				}
				else
				{
					out << "NULL";
				}
				out << ", \"" << escapeCString(abc.pool.strings[m.name]) << "\", "
				    << (unsigned) m.flags << ", "
				    << (is_function[mi] ? 1 : 0) << ", "
				    << m.params.size() << ", "
				    << (m.params.empty() ? string("NULL") : p + "_m" + to_string(mi) + "_pt")
				    << ", "
				    << (any_default ? p + "_m" + to_string(mi) + "_po" : string("NULL"))
				    << ", "
				    << m.return_type << ", ";
				if (has_bt)
				{
					out << abc.method_bodies[bi].traits.size() << ", "
					    << p << "_m" << mi << "_bt";
				}
				else
				{
					out << "0, NULL";
				}
				out << ", ";
				if (has_exc)
				{
					out << bodies[bi].ir.exceptions.size() << ", "
					    << p << "_m" << mi << "_exc";
				}
				else
				{
					out << "0, NULL";
				}
				out << " }," << endl;
			}
			if (abc.methods.empty())
			{
				out << "\t{ NULL, \"\", 0, 0, 0, NULL, NULL, 0, 0, NULL, 0, NULL }," << endl;
			}
			out << "};" << endl;
		}
	}

	void AbcEmitter::finalize(const std::vector<std::pair<u16, string>>& symbol_bindings,
	                          u8 swf_version)
	{
		if (next_tag_index_ == 0) return;
		ensureDir();

		{
			ofstream out(folder_ + "/abc_gen.h");
			out << "// Generated by SWFRecomp (abc_emit.cpp). Do not edit." << endl
			    << "#pragma once" << endl << endl
			    << "#include <avm2/avm2_abc.h>" << endl
			    << "#include <avm2/avm2_class.h>" << endl
			    << "#include <avm2/avm2_error.h>" << endl
			    << "#include <avm2/avm2_ops.h>" << endl
			    << "#include <avm2/avm2_value.h>" << endl << endl;
			for (int i = 0; i < next_tag_index_; i++)
			{
				out << "extern const Avm2AbcMethodData abc" << i << "_methods[];" << endl
				    << "extern const Avm2AbcFileData abc" << i << "_data;" << endl;
			}
		}

		{
			ofstream out(folder_ + "/abc_registry.c");
			out << "// Generated by SWFRecomp (abc_emit.cpp). Do not edit." << endl
			    << "#include \"abc_gen.h\"" << endl << endl;
			out << "const Avm2AbcFileData* const avm2_generated_abc_files[] =" << endl
			    << "{" << endl;
			for (int i = 0; i < next_tag_index_; i++)
			{
				out << "\t&abc" << i << "_data," << endl;
			}
			out << "};" << endl
			    << "const uint32_t avm2_generated_abc_file_count = "
			    << next_tag_index_ << ";" << endl << endl;

			out << "const Avm2SymbolClassBinding avm2_generated_symbol_classes[] =" << endl
			    << "{" << endl;
			for (const auto& b : symbol_bindings)
			{
				out << "\t{ " << b.first << ", \"" << escapeCString(b.second)
				    << "\" }," << endl;
			}
			if (symbol_bindings.empty())
			{
				out << "\t{ 0, NULL },  // placeholder (no SymbolClass tags)" << endl;
			}
			out << "};" << endl
			    << "const uint32_t avm2_generated_symbol_class_count = "
			    << symbol_bindings.size() << ";" << endl
			    << "const uint8_t avm2_generated_swf_version = "
			    << (unsigned) swf_version << ";" << endl;
		}
	}
}
}
