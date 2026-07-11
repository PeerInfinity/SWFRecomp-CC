// AVM2 C emitter — see abc_emit.hpp. Output layout (RecompiledABC/):
//
//   abc_gen.h        extern decls for every emitted tag's data
//   abc<i>_tables.c  interned strings, namespaces/ns-sets, multinames,
//                    class/script/trait registry, Avm2AbcFileData
//   abc<i>_methods.c one C function per verified method body + the
//                    Avm2AbcMethodData table (fn ptrs, exception data)
//   abc_registry.c   file list + SymbolClass bindings (finalize())
//
// Method bodies compile the verified IR (abc_ir.hpp) against the runtime
// contract in SWFModernRuntime/include/avm2/{avm2_abc.h,avm2_ops.h}: the
// operand stack is a C local array sized by computed_max_stack (dynamic sp
// within a static bound; per-slot scalarization is a Stage-3 optimization),
// locals are a C array, the local scope stack a C array of object pointers.
// Branch targets would become op-index labels; no branch op is in the
// Stage-2 surface, so bodies are strictly linear until the first
// unsupported op, which emits avm2_unimplemented_op() and truncates the
// remainder (unreachable without branches).

#include <cstdio>
#include <fstream>
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

	static void emitTraitArray(ofstream& out, const string& sym,
	                           const std::vector<AbcTrait>& traits)
	{
		if (traits.empty()) return;
		out << "static const Avm2AbcTrait " << sym << "[] =" << endl << "{" << endl;
		for (const AbcTrait& t : traits)
		{
			out << "\t{ " << (unsigned) t.kind << ", " << t.name << ", "
			    << t.slot_or_disp_id << ", " << t.type_name << ", "
			    << t.method_or_class << " }," << endl;
		}
		out << "};" << endl << endl;
	}

	static string traitArrayRef(const string& sym, size_t count)
	{
		if (count == 0) return "0, NULL";
		return to_string(count) + ", " + sym;
	}

	// The Stage-2 opcode surface (hello_world's 21 ops). Returns false if
	// the op is unsupported (caller emits the abort and truncates).
	static bool emitOp(ofstream& out, const IrOp& op)
	{
		switch (op.op)
		{
			case IrOpcode::GetLocal:
				out << "\tstk[sp++] = loc[" << op.arg1 << "];" << endl;
				return true;
			case IrOpcode::SetLocal:
				out << "\tloc[" << op.arg1 << "] = stk[--sp];" << endl;
				return true;
			case IrOpcode::PushString:
				out << "\tstk[sp++] = avm2_string(&act->file->data->strings["
				    << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::PushInt:
				out << "\tstk[sp++] = avm2_integer(" << op.imm << ");" << endl;
				return true;
			case IrOpcode::PushScope:
				out << "\tlscope[scope_n++] = avm2_op_pushscope(act, stk[--sp]);" << endl;
				return true;
			case IrOpcode::PopScope:
				out << "\tscope_n--;" << endl;
				return true;
			case IrOpcode::GetScopeObject:
				out << "\tstk[sp++] = avm2_object_value(lscope[" << op.arg1 << "]);" << endl;
				return true;
			case IrOpcode::FindPropStrict:
				out << "\tstk[sp++] = avm2_object_value(avm2_op_findpropstrict(act, "
				    << "lscope, scope_n, " << op.arg1 << "));" << endl;
				return true;
			case IrOpcode::GetPropertyStatic:
				out << "\tstk[sp - 1] = avm2_op_getproperty_static(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::InitProperty:
				out << "\tsp -= 2; avm2_op_initproperty(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1]);" << endl;
				return true;
			case IrOpcode::CallProperty:
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_callproperty(act, "
				    << "stk[sp], " << op.arg1 << ", &stk[sp + 1], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::CallPropVoid:
				out << "\tsp -= " << (op.arg2 + 1) << "; avm2_op_callproperty(act, "
				    << "stk[sp], " << op.arg1 << ", &stk[sp + 1], " << op.arg2
				    << ");" << endl;
				return true;
			case IrOpcode::ConstructProp:
				out << "\tsp -= " << (op.arg2 + 1) << "; stk[sp] = avm2_op_constructprop(act, "
				    << "stk[sp], " << op.arg1 << ", &stk[sp + 1], " << op.arg2
				    << "); sp++;" << endl;
				return true;
			case IrOpcode::ConstructSuper:
				out << "\tsp -= " << (op.arg2 + 1) << "; avm2_op_constructsuper(act, "
				    << "stk[sp], &stk[sp + 1], " << op.arg2 << ");" << endl;
				return true;
			case IrOpcode::NewClass:
				out << "\tstk[sp - 1] = avm2_op_newclass(act, " << op.arg1
				    << ", stk[sp - 1], lscope, scope_n);" << endl;
				return true;
			case IrOpcode::Pop:
				out << "\tsp--;" << endl;
				return true;
			case IrOpcode::ReturnValue:
				out << "\treturn stk[--sp];" << endl;
				return true;
			case IrOpcode::ReturnVoid:
				out << "\treturn avm2_undefined();" << endl;
				return true;
			// Comment-only ops (the // <op> line above suffices).
			case IrOpcode::CoerceA:
			case IrOpcode::DebugFile:
			case IrOpcode::DebugLine:
			case IrOpcode::Nop:
				return true;
			default:
				return false;
		}
	}

	static void emitMethodBody(ofstream& out, const AbcFile& abc, const EmitBody& body,
	                           const string& fn_name, u32 method_index)
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

		out << "\tAvm2Value loc[" << num_locals << "];" << endl
		    << "\tAvm2Value stk[" << max_stack << "];" << endl
		    << "\tuint32_t sp = 0;" << endl
		    << "\tAvm2Object* lscope[" << max_scope << "];" << endl
		    << "\tuint32_t scope_n = 0;" << endl
		    << "\tavm2_setup_locals(loc, " << num_locals << ", act);" << endl
		    << "\t(void) sp; (void) scope_n; (void) stk; (void) lscope; (void) loc;"
		    << endl << endl;

		for (size_t i = 0; i < body.ir.ops.size(); i++)
		{
			const IrOp& op = body.ir.ops[i];
			string desc = sanitizeComment(formatIrOp(abc, op));
			out << "\t// " << i << ": " << desc << endl;
			if (!emitOp(out, op))
			{
				out << "\tavm2_unimplemented_op(act, \"" << escapeCString(desc)
				    << "\", " << i << ");" << endl;
				size_t remaining = body.ir.ops.size() - i - 1;
				if (remaining > 0)
				{
					out << "\t// " << remaining << " further op(s) omitted: "
					    << "unreachable (no supported branch ops)" << endl;
				}
				out << "}" << endl << endl;
				return;
			}
		}

		// The verifier guarantees code cannot fall off the end (1020); keep
		// the C well-formed when the last op wasn't already a return.
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

			out << "static const Avm2AbcMultiname " << p << "_multinames[] =" << endl
			    << "{" << endl;
			for (const AbcMultiname& mn : abc.pool.multinames)
			{
				out << "\t{ " << (unsigned) mn.kind << ", " << mn.ns << ", "
				    << mn.name << ", " << mn.ns_set << " }," << endl;
			}
			out << "};" << endl << endl;

			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				emitTraitArray(out, p + "_c" + to_string(i) + "_it", abc.instances[i].traits);
				emitTraitArray(out, p + "_c" + to_string(i) + "_ct", abc.classes[i].traits);
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
				out << "\t{ " << inst.name << ", " << inst.super_name << ", "
				    << flags << ", " << inst.init_method << ", "
				    << abc.classes[i].init_method << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_it", inst.traits.size())
				    << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_ct", abc.classes[i].traits.size())
				    << " }," << endl;
			}
			if (abc.instances.empty()) out << "\t{ 0, 0, 0, 0, 0, 0, NULL, 0, NULL }," << endl;
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

			// body index per method (-1 = none), and exception data.
			std::vector<int> method_body(abc.methods.size(), -1);
			for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
			{
				method_body[abc.method_bodies[bi].method] = (int) bi;
			}

			for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
			{
				const EmitBody& body = bodies[bi];
				u32 mi = abc.method_bodies[bi].method;
				emitMethodBody(out, abc, body, p + "_m" + to_string(mi), mi);
				if (body.verified && !body.ir.exceptions.empty())
				{
					out << "static const Avm2AbcException " << p << "_m" << mi
					    << "_exc[] =" << endl << "{" << endl;
					for (const IrException& e : body.ir.exceptions)
					{
						out << "\t{ " << e.from_op << ", " << e.to_op << ", "
						    << e.target_op << ", " << e.type_name << ", "
						    << e.variable_name << ", " << (e.active ? 1 : 0)
						    << " }," << endl;
					}
					out << "};" << endl << endl;
				}
			}

			out << "const Avm2AbcMethodData " << p << "_methods[] =" << endl
			    << "{" << endl;
			for (size_t mi = 0; mi < abc.methods.size(); mi++)
			{
				const AbcMethod& m = abc.methods[mi];
				int bi = method_body[mi];
				bool has_exc = bi >= 0 && bodies[bi].verified
				               && !bodies[bi].ir.exceptions.empty();
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
				    << m.params.size() << ", ";
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
			if (abc.methods.empty()) out << "\t{ NULL, \"\", 0, 0, NULL }," << endl;
			out << "};" << endl;
		}
	}

	void AbcEmitter::finalize(const std::vector<std::pair<u16, string>>& symbol_bindings)
	{
		if (next_tag_index_ == 0) return;
		ensureDir();

		{
			ofstream out(folder_ + "/abc_gen.h");
			out << "// Generated by SWFRecomp (abc_emit.cpp). Do not edit." << endl
			    << "#pragma once" << endl << endl
			    << "#include <avm2/avm2_abc.h>" << endl
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
			    << symbol_bindings.size() << ";" << endl;
		}
	}
}
}
