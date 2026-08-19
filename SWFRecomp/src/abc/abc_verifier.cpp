#include <abc/abc_verifier.hpp>
#include <abc/abc_typemodel.hpp>

#include <cstdio>
#include <unordered_set>
#include <vector>

using std::string;
using std::to_string;

namespace SWFRecomp
{
namespace abc
{
	// avmplus's text for the codes whose message carries no operands, so the
	// wording follows from the code alone. Sourced from the same table the
	// runtime generates from Ruffle's error_messages.rs (avm2_error.c).
	static const char* avmplusVerifyText(int code)
	{
		switch (code)
		{
			case 1017: return "Scope stack overflow occurred.";
			case 1018: return "Scope stack underflow occurred.";
			case 1020: return "Code cannot fall off the end of a method.";
			case 1021: return "At least one branch target was not on a valid "
			                  "instruction in the method.";
			case 1023: return "Stack overflow occurred.";
			case 1024: return "Stack underflow occurred.";
			case 1054: return "Illegal range or target offsets in exception handler.";
			case 1072: return "Disp_id 0 is illegal.";
			case 1107: return "The ABC data is corrupt, attempt to read out of bounds.";
			case 1113: return "OP_newactivation used in method without "
			                  "NEED_ACTIVATION flag.";
			case 1124: return "OP_hasnext2 requires object and index to be "
			                  "distinct registers.";
			default:   return nullptr;
		}
	}

	// The operand-free path: `detail` is ours, the message is avmplus's.
	static bool fail(VerifyError& err, int code, const string& detail)
	{
		err.code = code;
		err.detail = detail;
		const char* text = avmplusVerifyText(code);
		err.message = "Error #" + to_string(code) + ": "
		            + (text != nullptr ? string(text) : detail);
		return false;
	}

	// The operand-carrying path: the caller has already filled avmplus's
	// placeholders (`Cpool index %1 is out of range %2.` and friends).
	static bool failFilled(VerifyError& err, int code, const string& text,
	                       const string& detail)
	{
		err.code = code;
		err.detail = detail;
		err.message = "Error #" + to_string(code) + ": " + text;
		return false;
	}

	// #1032 "Cpool index %1 is out of range %2." — `limit` is the size of the
	// pool the index missed, which is what avmplus prints (as3/cpool tests
	// assert both numbers).
	static bool failCpool(VerifyError& err, u32 index, size_t limit,
	                      const string& what)
	{
		return failFilled(err, 1032,
		                  "Cpool index " + to_string(index) + " is out of range "
		                  + to_string(limit) + ".",
		                  what + " cpool index " + to_string(index)
		                  + " out of range " + to_string(limit));
	}

	// avmplus describeMethod: "Class/method()" for an instance method,
	// "Class()" for a constructor, "Class$/method()" for a static one,
	// "global$init()" for a script initializer. The class part is the
	// multiname rendered as "package::Local", so a package-less class (which
	// is what every verify_* test uses) prints as its bare local name.
	static string multinameDisplay(const AbcFile& abc, u32 mn_index)
	{
		const auto& MN = abc.pool.multinames;
		const auto& S = abc.pool.strings;
		const auto& NS = abc.pool.namespaces;
		if (mn_index == 0 || mn_index >= MN.size())
		{
			return string();
		}
		const AbcMultiname& mn = MN[mn_index];
		string ns_name;
		if (mn.ns != 0 && mn.ns < NS.size() && NS[mn.ns].name < S.size())
		{
			ns_name = S[NS[mn.ns].name];
		}
		string local = mn.name < S.size() ? S[mn.name] : string();
		return ns_name.empty() ? local : ns_name + "::" + local;
	}

	// The method half of describeMethod is the trait's LOCAL name only --
	// avmplus prints "Test/dxnsMethod()" even though the trait's QName sits
	// in the class's protected namespace ("Test:dxnsMethod").
	static string multinameLocal(const AbcFile& abc, u32 mn_index)
	{
		const auto& MN = abc.pool.multinames;
		const auto& S = abc.pool.strings;
		if (mn_index == 0 || mn_index >= MN.size())
		{
			return string();
		}
		u32 si = MN[mn_index].name;
		return si < S.size() ? S[si] : string();
	}

	static string methodDisplayName(const AbcFile& abc, u32 method_index)
	{
		for (const AbcInstance& inst : abc.instances)
		{
			string cls = multinameDisplay(abc, inst.name);
			if (inst.init_method == method_index)
			{
				return cls + "()";
			}
			for (const AbcTrait& t : inst.traits)
			{
				if (t.method_or_class != method_index)
				{
					continue;
				}
				if (t.kind == TraitKindType::Method || t.kind == TraitKindType::Function)
				{
					return cls + "/" + multinameLocal(abc, t.name) + "()";
				}
				if (t.kind == TraitKindType::Getter)
				{
					return cls + "/get " + multinameLocal(abc, t.name) + "()";
				}
				if (t.kind == TraitKindType::Setter)
				{
					return cls + "/set " + multinameLocal(abc, t.name) + "()";
				}
			}
		}
		for (size_t ci = 0; ci < abc.classes.size(); ++ci)
		{
			string cls = ci < abc.instances.size()
			           ? multinameDisplay(abc, abc.instances[ci].name) : string();
			if (abc.classes[ci].init_method == method_index)
			{
				return cls + "$cinit()";
			}
			for (const AbcTrait& t : abc.classes[ci].traits)
			{
				if (t.method_or_class == method_index
				    && (t.kind == TraitKindType::Method
				        || t.kind == TraitKindType::Function
				        || t.kind == TraitKindType::Getter
				        || t.kind == TraitKindType::Setter))
				{
					return cls + "$/" + multinameLocal(abc, t.name) + "()";
				}
			}
		}
		for (const AbcScript& script : abc.scripts)
		{
			if (script.init_method == method_index)
			{
				return "global$init()";
			}
			for (const AbcTrait& t : script.traits)
			{
				if (t.method_or_class == method_index
				    && (t.kind == TraitKindType::Method
				        || t.kind == TraitKindType::Function))
				{
					return multinameLocal(abc, t.name) + "()";
				}
			}
		}
		if (method_index < abc.methods.size())
		{
			u32 si = abc.methods[method_index].name;
			if (si != 0 && si < abc.pool.strings.size()
			    && !abc.pool.strings[si].empty())
			{
				return abc.pool.strings[si] + "()";
			}
		}
		return "MethodInfo-" + to_string(method_index) + "()";
	}

	// === whole-file cross-reference validation ===

	static bool checkDefaultValue(const AbcFile& abc, const DefaultValue& v,
	                              const char* what, VerifyError& err)
	{
		if (!v.present)
		{
			return true;
		}
		const ConstantPool& pool = abc.pool;
		size_t limit;
		switch (v.kind)
		{
			case DefaultValueKind::Int: limit = pool.ints.size(); break;
			case DefaultValueKind::Uint: limit = pool.uints.size(); break;
			case DefaultValueKind::Double: limit = pool.doubles.size(); break;
			case DefaultValueKind::String: limit = pool.strings.size(); break;
			case DefaultValueKind::PrivateNs:
			case DefaultValueKind::Namespace:
			case DefaultValueKind::PackageNs:
			case DefaultValueKind::PackageInternalNs:
			case DefaultValueKind::ProtectedNs:
			case DefaultValueKind::ExplicitNs:
			case DefaultValueKind::StaticProtectedNs:
				limit = pool.namespaces.size();
				break;
			default:
				return true;  // True/False/Null/Undefined carry no index
		}
		if (v.index >= limit)
		{
			return fail(err, 1032, string("cpool index out of range in ") + what
			            + " default value: " + to_string(v.index));
		}
		return true;
	}

	static bool checkTraits(const AbcFile& abc, const std::vector<AbcTrait>& traits,
	                        const char* owner, VerifyError& err)
	{
		const ConstantPool& pool = abc.pool;
		for (const AbcTrait& t : traits)
		{
			if (t.name == 0 || t.name >= pool.multinames.size())
			{
				return fail(err, 1032, string("trait name multiname out of range in ")
				            + owner + ": " + to_string(t.name));
			}
			switch (t.kind)
			{
				case TraitKindType::Slot:
				case TraitKindType::Const:
				{
					if (t.type_name >= pool.multinames.size())
					{
						return fail(err, 1032, string("slot trait type multiname out of range in ")
						            + owner + ": " + to_string(t.type_name));
					}
					if (!checkDefaultValue(abc, t.value, owner, err))
					{
						return false;
					}
					break;
				}
				case TraitKindType::Method:
				case TraitKindType::Getter:
				case TraitKindType::Setter:
				case TraitKindType::Function:
				{
					if (t.method_or_class >= abc.methods.size())
					{
						return fail(err, 1032, string("trait method index out of range in ")
						            + owner + ": " + to_string(t.method_or_class));
					}
					break;
				}
				case TraitKindType::Class:
				{
					if (t.method_or_class >= abc.classes.size())
					{
						return fail(err, 1032, string("trait class index out of range in ")
						            + owner + ": " + to_string(t.method_or_class));
					}
					break;
				}
			}
			for (u32 md : t.metadata)
			{
				if (md >= abc.metadata.size())
				{
					return fail(err, 1032, string("trait metadata index out of range in ")
					            + owner + ": " + to_string(md));
				}
			}
		}
		return true;
	}

	bool validateAbcFile(const AbcFile& abc, VerifyError& err)
	{
		// Both drivers call this exactly once per AbcFile, immediately before
		// their per-body verify loop — the one place that can safely drop the
		// type-lattice's cached AbcTypeModel (AbcFile is a stack local in both,
		// so its ADDRESS is recycled between DoABC tags and is not an identity).
		resetVerifierTypeModel();

		const ConstantPool& pool = abc.pool;

		for (size_t i = 1; i < pool.namespaces.size(); ++i)
		{
			if (pool.namespaces[i].name >= pool.strings.size())
			{
				return fail(err, 1032, "namespace name string out of range: ns "
				            + to_string(i));
			}
		}

		for (size_t i = 1; i < pool.ns_sets.size(); ++i)
		{
			for (u32 ns : pool.ns_sets[i])
			{
				if (ns >= pool.namespaces.size())
				{
					return fail(err, 1032, "ns-set entry out of range: set "
					            + to_string(i));
				}
			}
		}

		for (size_t i = 1; i < pool.multinames.size(); ++i)
		{
			const AbcMultiname& mn = pool.multinames[i];
			if (mn.ns >= pool.namespaces.size()
			    || mn.name >= pool.strings.size()
			    || mn.ns_set >= pool.ns_sets.size()
			    || mn.base_type >= pool.multinames.size())
			{
				return fail(err, 1032, "multiname internal index out of range: multiname "
				            + to_string(i));
			}
			for (u32 p : mn.type_params)
			{
				if (p >= pool.multinames.size())
				{
					return fail(err, 1032, "TypeName parameter out of range: multiname "
					            + to_string(i));
				}
			}
		}

		for (size_t i = 0; i < abc.methods.size(); ++i)
		{
			const AbcMethod& m = abc.methods[i];
			if (m.name >= pool.strings.size() || m.return_type >= pool.multinames.size())
			{
				return fail(err, 1032, "method name/return type out of range: method "
				            + to_string(i));
			}
			for (const MethodParam& p : m.params)
			{
				if (p.type >= pool.multinames.size() || p.name >= pool.strings.size())
				{
					return fail(err, 1032, "method param index out of range: method "
					            + to_string(i));
				}
				if (!checkDefaultValue(abc, p.default_value, "method param", err))
				{
					return false;
				}
			}
		}

		for (size_t i = 0; i < abc.metadata.size(); ++i)
		{
			const AbcMetadata& md = abc.metadata[i];
			if (md.name >= pool.strings.size())
			{
				return fail(err, 1032, "metadata name out of range: metadata " + to_string(i));
			}
			for (const MetadataItem& item : md.items)
			{
				if (item.key >= pool.strings.size() || item.value >= pool.strings.size())
				{
					return fail(err, 1032, "metadata item out of range: metadata "
					            + to_string(i));
				}
			}
		}

		for (size_t i = 0; i < abc.instances.size(); ++i)
		{
			const AbcInstance& inst = abc.instances[i];
			if (inst.name == 0 || inst.name >= pool.multinames.size()
			    || inst.super_name >= pool.multinames.size()
			    || inst.init_method >= abc.methods.size()
			    || (inst.has_protected_ns && inst.protected_ns >= pool.namespaces.size()))
			{
				return fail(err, 1032, "instance reference out of range: instance "
				            + to_string(i));
			}
			for (u32 iface : inst.interfaces)
			{
				if (iface >= pool.multinames.size())
				{
					return fail(err, 1032, "interface multiname out of range: instance "
					            + to_string(i));
				}
			}
			if (!checkTraits(abc, inst.traits, "instance", err))
			{
				return false;
			}
		}

		for (size_t i = 0; i < abc.classes.size(); ++i)
		{
			if (abc.classes[i].init_method >= abc.methods.size())
			{
				return fail(err, 1032, "class init method out of range: class " + to_string(i));
			}
			if (!checkTraits(abc, abc.classes[i].traits, "class", err))
			{
				return false;
			}
		}

		for (size_t i = 0; i < abc.scripts.size(); ++i)
		{
			if (abc.scripts[i].init_method >= abc.methods.size())
			{
				return fail(err, 1032, "script init method out of range: script " + to_string(i));
			}
			if (!checkTraits(abc, abc.scripts[i].traits, "script", err))
			{
				return false;
			}
		}

		for (size_t i = 0; i < abc.method_bodies.size(); ++i)
		{
			const AbcMethodBody& body = abc.method_bodies[i];
			for (const AbcException& e : body.exceptions)
			{
				if (e.type_name >= pool.multinames.size()
				    || e.variable_name >= pool.multinames.size())
				{
					return fail(err, 1032, "exception multiname out of range: body "
					            + to_string(i));
				}
			}
			if (!checkTraits(abc, body.traits, "method body", err))
			{
				return false;
			}
		}

		return true;
	}

	// === per-op helpers ===

	// Ops that can NOT throw (avmplus opcodes.tbl via Ruffle op_can_throw_error).
	static bool opCanThrowError(AbcOpcode op)
	{
		switch (op)
		{
			case AbcOpcode::Bkpt:
			case AbcOpcode::BkptLine:
			case AbcOpcode::Timestamp:
			case AbcOpcode::PushByte:
			case AbcOpcode::PushDouble:
			case AbcOpcode::PushFalse:
			case AbcOpcode::PushInt:
			case AbcOpcode::PushNamespace:
			case AbcOpcode::PushNaN:
			case AbcOpcode::PushNull:
			case AbcOpcode::PushShort:
			case AbcOpcode::PushString:
			case AbcOpcode::PushTrue:
			case AbcOpcode::PushUint:
			case AbcOpcode::PushUndefined:
			case AbcOpcode::Dup:
			case AbcOpcode::Swap:
			case AbcOpcode::Pop:
			case AbcOpcode::TypeOf:
			case AbcOpcode::GetGlobalScope:
			case AbcOpcode::GetScopeObject:
			case AbcOpcode::GetOuterScope:
			case AbcOpcode::GetGlobalSlot:
			case AbcOpcode::GetLocal:
			case AbcOpcode::SetLocal:
			case AbcOpcode::Kill:
			case AbcOpcode::Label:
			case AbcOpcode::Jump:
			case AbcOpcode::IfTrue:
			case AbcOpcode::IfFalse:
			case AbcOpcode::IfStrictEq:
			case AbcOpcode::IfStrictNe:
			case AbcOpcode::LookupSwitch:
			case AbcOpcode::Nop:
			case AbcOpcode::Not:
			case AbcOpcode::PopScope:
			case AbcOpcode::ReturnVoid:
			{
				return false;
			}
			default:
			{
				return true;
			}
		}
	}

	static bool getMultiname(const AbcFile& abc, u32 index,
	                         const AbcMultiname*& out, VerifyError& err)
	{
		if (index == 0 || index >= abc.pool.multinames.size())
		{
			failCpool(err, index, abc.pool.multinames.size(), "multiname");
			return false;
		}
		out = &abc.pool.multinames[index];
		return true;
	}

	// True if the multiname's static namespace set contains the AS3 public
	// namespace (kind Namespace/Package with an empty name).
	static bool nsSetContainsPublic(const AbcFile& abc, const AbcMultiname& mn)
	{
		if (mn.ns_set == 0 || mn.ns_set >= abc.pool.ns_sets.size())
		{
			return false;
		}
		for (u32 ns_index : abc.pool.ns_sets[mn.ns_set])
		{
			if (ns_index == 0 || ns_index >= abc.pool.namespaces.size())
			{
				continue;
			}
			const AbcNamespace& ns = abc.pool.namespaces[ns_index];
			if (ns.isPublicKind() && abc.pool.strings[ns.name].empty())
			{
				return true;
			}
		}
		return false;
	}

	struct TranslatedOp
	{
		IrOp first;
		bool has_second = false;
		IrOp second;
	};

	// Translates one raw op into IR (Ruffle verify.rs translate_op).
	// Branch offsets are stashed in IrOp::imm until the offset->op-index
	// rewrite pass. Returns false with a verify error on invalid ops.
	static bool translateOp(const AbcFile& abc, const AbcMethod& method,
	                        const AbcMethodBody& body, const RawOp& raw,
	                        TranslatedOp& out, VerifyError& err)
	{
		const ConstantPool& pool = abc.pool;
		u32 max_locals = body.num_locals;
		IrOp& op = out.first;

		auto localCheck = [&](u32 index) -> bool
		{
			if (index >= max_locals)
			{
				return failFilled(err, 1025,
				                  "An invalid register " + to_string(index)
				                  + " was accessed.",
				                  "access of out-of-range local register "
				                  + to_string(index));
			}
			return true;
		};

		auto simple = [&](IrOpcode o)
		{
			op.op = o;
		};

		auto withMultiname = [&](IrOpcode o) -> bool
		{
			const AbcMultiname* mn;
			if (!getMultiname(abc, raw.arg1, mn, err))
			{
				return false;
			}
			op.op = o;
			op.arg1 = raw.arg1;
			op.arg2 = raw.arg2;
			return true;
		};

		// Multiname must be fully static (no runtime parts).
		auto withStaticMultiname = [&](IrOpcode o, int lazy_error) -> bool
		{
			const AbcMultiname* mn;
			if (!getMultiname(abc, raw.arg1, mn, err))
			{
				return false;
			}
			if (mn->hasLazyComponent())
			{
				return fail(err, lazy_error, "multiname with runtime components not allowed here: "
				            + to_string(raw.arg1));
			}
			op.op = o;
			op.arg1 = raw.arg1;
			op.arg2 = raw.arg2;
			return true;
		};

		// GetProperty/SetProperty specialization (see op.rs comments).
		auto propertySpecialize = [&](IrOpcode stat, IrOpcode fast, IrOpcode slow) -> bool
		{
			const AbcMultiname* mn;
			if (!getMultiname(abc, raw.arg1, mn, err))
			{
				return false;
			}
			IrOpcode o;
			if (!mn->hasLazyComponent())
			{
				o = stat;
			}
			else if (mn->hasLazyName() && !mn->hasLazyNs()
			         && nsSetContainsPublic(abc, *mn) && !mn->isAttribute())
			{
				o = fast;
			}
			else
			{
				o = slow;
			}
			op.op = o;
			op.arg1 = raw.arg1;
			return true;
		};

		switch (raw.opcode)
		{
			// --- pushes ---
			case AbcOpcode::PushByte:
			{
				op.op = IrOpcode::PushInt;
				op.imm = (s32) (int8_t) raw.byte_arg;
				break;
			}
			case AbcOpcode::PushShort:
			{
				op.op = IrOpcode::PushInt;
				op.imm = (s32) (s16) (u16) raw.arg1;
				break;
			}
			case AbcOpcode::PushInt:
			{
				if (raw.arg1 == 0 || raw.arg1 >= pool.ints.size())
				{
					return failCpool(err, raw.arg1, pool.ints.size(), "int");
				}
				op.op = IrOpcode::PushInt;
				op.imm = pool.ints[raw.arg1];
				break;
			}
			case AbcOpcode::PushUint:
			{
				if (raw.arg1 == 0 || raw.arg1 >= pool.uints.size())
				{
					return failCpool(err, raw.arg1, pool.uints.size(), "uint");
				}
				op.op = IrOpcode::PushUint;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::PushDouble:
			{
				if (raw.arg1 == 0 || raw.arg1 >= pool.doubles.size())
				{
					return failCpool(err, raw.arg1, pool.doubles.size(), "double");
				}
				op.op = IrOpcode::PushDouble;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::PushString:
			{
				if (raw.arg1 == 0 || raw.arg1 >= pool.strings.size())
				{
					return failCpool(err, raw.arg1, pool.strings.size(), "string");
				}
				op.op = IrOpcode::PushString;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::PushNamespace:
			{
				if (raw.arg1 == 0 || raw.arg1 >= pool.namespaces.size())
				{
					return failCpool(err, raw.arg1, pool.namespaces.size(), "namespace");
				}
				op.op = IrOpcode::PushNamespace;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::PushNaN: simple(IrOpcode::PushNaN); break;
			case AbcOpcode::PushNull: simple(IrOpcode::PushNull); break;
			case AbcOpcode::PushUndefined: simple(IrOpcode::PushUndefined); break;
			case AbcOpcode::PushTrue: simple(IrOpcode::PushTrue); break;
			case AbcOpcode::PushFalse: simple(IrOpcode::PushFalse); break;

			// --- locals ---
			case AbcOpcode::GetLocal:
			{
				if (!localCheck(raw.arg1)) return false;
				op.op = IrOpcode::GetLocal;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::SetLocal:
			{
				if (!localCheck(raw.arg1)) return false;
				op.op = IrOpcode::SetLocal;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::Kill:
			{
				if (!localCheck(raw.arg1)) return false;
				op.op = IrOpcode::Kill;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::IncLocal:
			case AbcOpcode::IncLocalI:
			case AbcOpcode::DecLocal:
			case AbcOpcode::DecLocalI:
			{
				if (!localCheck(raw.arg1)) return false;
				switch (raw.opcode)
				{
					case AbcOpcode::IncLocal: op.op = IrOpcode::IncLocal; break;
					case AbcOpcode::IncLocalI: op.op = IrOpcode::IncLocalI; break;
					case AbcOpcode::DecLocal: op.op = IrOpcode::DecLocal; break;
					default: op.op = IrOpcode::DecLocalI; break;
				}
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::HasNext2:
			{
				// Order matters: object register first, then index register.
				if (raw.arg1 >= max_locals)
				{
					return failFilled(err, 1025,
					                  "An invalid register " + to_string(raw.arg1)
					                  + " was accessed.",
					                  "access of out-of-range local register "
					                  + to_string(raw.arg1));
				}
				if (raw.arg2 >= max_locals)
				{
					return failFilled(err, 1025,
					                  "An invalid register " + to_string(raw.arg2)
					                  + " was accessed.",
					                  "access of out-of-range local register "
					                  + to_string(raw.arg2));
				}
				if (raw.arg1 == raw.arg2)
				{
					return fail(err, 1124, "hasnext2 object and index registers must differ");
				}
				op.op = IrOpcode::HasNext2;
				op.arg1 = raw.arg1;
				op.arg2 = raw.arg2;
				break;
			}

			// --- calls ---
			case AbcOpcode::Call:
			{
				op.op = IrOpcode::Call;
				op.arg2 = raw.arg1;  // num_args
				break;
			}
			case AbcOpcode::CallMethod:
			{
				// Not allowed from ABC bytecode (avmplus/Ruffle behavior).
				if (raw.arg1 == 0)
				{
					return fail(err, 1072, "disp_id 0 is illegal");
				}
				return failFilled(err, 1051,
					                  "Illegal early binding access to "
					                  + methodDisplayName(abc, body.method) + ".",
					                  "illegal early binding access");
			}
			case AbcOpcode::CallProperty: return withMultiname(IrOpcode::CallProperty);
			case AbcOpcode::CallPropLex: return withMultiname(IrOpcode::CallPropLex);
			case AbcOpcode::CallPropVoid: return withMultiname(IrOpcode::CallPropVoid);
			case AbcOpcode::CallSuper: return withMultiname(IrOpcode::CallSuper);
			case AbcOpcode::CallSuperVoid:
			{
				if (!withMultiname(IrOpcode::CallSuper))
				{
					return false;
				}
				out.has_second = true;
				out.second.op = IrOpcode::Pop;
				break;
			}
			case AbcOpcode::CallStatic:
			{
				if (raw.arg1 >= abc.methods.size())
				{
					return failFilled(err, 1027,
					                  "Method_info " + to_string(raw.arg1)
					                  + " exceeds method_count=" + to_string(abc.methods.size())
					                  + ".",
					                  "method index out of range: " + to_string(raw.arg1));
				}
				op.op = IrOpcode::CallStatic;
				op.arg1 = raw.arg1;
				op.arg2 = raw.arg2;
				break;
			}
			case AbcOpcode::Construct:
			{
				op.op = IrOpcode::Construct;
				op.arg2 = raw.arg1;
				break;
			}
			case AbcOpcode::ConstructProp: return withMultiname(IrOpcode::ConstructProp);
			case AbcOpcode::ConstructSuper:
			{
				op.op = IrOpcode::ConstructSuper;
				op.arg2 = raw.arg1;
				break;
			}
			case AbcOpcode::ReturnValue: simple(IrOpcode::ReturnValue); break;
			case AbcOpcode::ReturnVoid: simple(IrOpcode::ReturnVoid); break;

			// --- properties ---
			case AbcOpcode::GetProperty:
			{
				return propertySpecialize(IrOpcode::GetPropertyStatic,
				                          IrOpcode::GetPropertyFast,
				                          IrOpcode::GetPropertySlow);
			}
			case AbcOpcode::SetProperty:
			{
				return propertySpecialize(IrOpcode::SetPropertyStatic,
				                          IrOpcode::SetPropertyFast,
				                          IrOpcode::SetPropertySlow);
			}
			case AbcOpcode::InitProperty: return withMultiname(IrOpcode::InitProperty);
			case AbcOpcode::DeleteProperty: return withMultiname(IrOpcode::DeleteProperty);
			case AbcOpcode::GetSuper: return withMultiname(IrOpcode::GetSuper);
			case AbcOpcode::SetSuper: return withMultiname(IrOpcode::SetSuper);
			case AbcOpcode::GetDescendants: return withMultiname(IrOpcode::GetDescendants);
			case AbcOpcode::FindProperty: return withMultiname(IrOpcode::FindProperty);
			case AbcOpcode::FindPropStrict: return withMultiname(IrOpcode::FindPropStrict);
			case AbcOpcode::FindDef:
			{
				return withStaticMultiname(IrOpcode::FindDef, 1078);
			}
			case AbcOpcode::GetLex:
			{
				if (!withStaticMultiname(IrOpcode::FindPropStrict, 1078))
				{
					return false;
				}
				out.has_second = true;
				out.second.op = IrOpcode::GetPropertyStatic;
				out.second.arg1 = raw.arg1;
				break;
			}

			// --- slots ---
			case AbcOpcode::GetSlot:
			case AbcOpcode::SetSlot:
			case AbcOpcode::SetGlobalSlot:
			{
				if (raw.arg1 == 0)
				{
					return failFilled(err, 1026,
					                  "Slot 0 exceeds slotCount=0 of "
					                  + methodDisplayName(abc, body.method) + ".",
					                  "slot 0 exceeds slot count");
				}
				switch (raw.opcode)
				{
					case AbcOpcode::GetSlot: op.op = IrOpcode::GetSlot; break;
					case AbcOpcode::SetSlot: op.op = IrOpcode::SetSlot; break;
					default: op.op = IrOpcode::SetGlobalSlot; break;
				}
				op.arg1 = raw.arg1 - 1;  // 1-based -> 0-based
				break;
			}
			case AbcOpcode::GetGlobalSlot:
			{
				if (raw.arg1 == 0)
				{
					return failFilled(err, 1026,
					                  "Slot 0 exceeds slotCount=0 of "
					                  + methodDisplayName(abc, body.method) + ".",
					                  "slot 0 exceeds slot count");
				}
				// Split like Ruffle, but with GetGlobalScope in place of the
				// runtime-dependent GetScopeObject/GetOuterScope choice.
				op.op = IrOpcode::GetGlobalScope;
				out.has_second = true;
				out.second.op = IrOpcode::GetSlot;
				out.second.arg1 = raw.arg1 - 1;
				break;
			}

			// --- scopes ---
			case AbcOpcode::PushScope: simple(IrOpcode::PushScope); break;
			case AbcOpcode::PushWith: simple(IrOpcode::PushWith); break;
			case AbcOpcode::PopScope: simple(IrOpcode::PopScope); break;
			case AbcOpcode::GetScopeObject:
			{
				op.op = IrOpcode::GetScopeObject;
				op.arg1 = raw.byte_arg;
				break;
			}
			case AbcOpcode::GetOuterScope:
			{
				// Ruffle validates the index against the runtime outer-scope
				// stack (error 1019); that context does not exist AOT.
				op.op = IrOpcode::GetOuterScope;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::GetGlobalScope: simple(IrOpcode::GetGlobalScope); break;

			// --- allocation ---
			case AbcOpcode::NewActivation:
			{
				if (!(method.flags & METHOD_NEED_ACTIVATION))
				{
					return fail(err, 1113, "newactivation used in method without NEED_ACTIVATION flag");
				}
				simple(IrOpcode::NewActivation);
				break;
			}
			case AbcOpcode::NewObject:
			{
				op.op = IrOpcode::NewObject;
				op.arg2 = raw.arg1;
				break;
			}
			case AbcOpcode::NewArray:
			{
				op.op = IrOpcode::NewArray;
				op.arg2 = raw.arg1;
				break;
			}
			case AbcOpcode::NewFunction:
			{
				if (raw.arg1 >= abc.methods.size())
				{
					return failFilled(err, 1027,
					                  "Method_info " + to_string(raw.arg1)
					                  + " exceeds method_count=" + to_string(abc.methods.size())
					                  + ".",
					                  "method index out of range: " + to_string(raw.arg1));
				}
				op.op = IrOpcode::NewFunction;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::NewClass:
			{
				if (raw.arg1 >= abc.classes.size())
				{
					return failFilled(err, 1060,
					                  "ClassInfo " + to_string(raw.arg1)
					                  + " exceeds class_count=" + to_string(abc.classes.size())
					                  + ".",
					                  "class index out of range: " + to_string(raw.arg1));
				}
				op.op = IrOpcode::NewClass;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::NewCatch:
			{
				if (raw.arg1 >= body.exceptions.size())
				{
					return failCpool(err, raw.arg1, body.exceptions.size(), "exception");
				}
				op.op = IrOpcode::NewCatch;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::ApplyType:
			{
				op.op = IrOpcode::ApplyType;
				op.arg2 = raw.arg1;  // num_types
				break;
			}

			// --- coercion ---
			case AbcOpcode::CoerceA: simple(IrOpcode::CoerceA); break;
			case AbcOpcode::CoerceO: simple(IrOpcode::CoerceO); break;
			case AbcOpcode::CoerceS: simple(IrOpcode::CoerceS); break;
			case AbcOpcode::CoerceB:
			case AbcOpcode::ConvertB: simple(IrOpcode::CoerceB); break;
			case AbcOpcode::CoerceD:
			case AbcOpcode::ConvertD: simple(IrOpcode::CoerceD); break;
			case AbcOpcode::CoerceI:
			case AbcOpcode::ConvertI: simple(IrOpcode::CoerceI); break;
			case AbcOpcode::CoerceU:
			case AbcOpcode::ConvertU: simple(IrOpcode::CoerceU); break;
			case AbcOpcode::ConvertO: simple(IrOpcode::ConvertO); break;
			case AbcOpcode::ConvertS: simple(IrOpcode::ConvertS); break;
			case AbcOpcode::Coerce:
			{
				// Ruffle resolves the class here (error 1014 on lazy/missing);
				// we keep the multiname index and only enforce staticness.
				return withStaticMultiname(IrOpcode::Coerce, 1014);
			}
			case AbcOpcode::AsType:
			{
				return withStaticMultiname(IrOpcode::AsType, 1014);
			}
			case AbcOpcode::IsType:
			{
				return withStaticMultiname(IrOpcode::IsType, 1014);
			}
			case AbcOpcode::AsTypeLate: simple(IrOpcode::AsTypeLate); break;
			case AbcOpcode::IsTypeLate: simple(IrOpcode::IsTypeLate); break;
			case AbcOpcode::InstanceOf: simple(IrOpcode::InstanceOf); break;

			// --- arithmetic / logic ---
			case AbcOpcode::Add: simple(IrOpcode::Add); break;
			case AbcOpcode::AddI: simple(IrOpcode::AddI); break;
			case AbcOpcode::Subtract: simple(IrOpcode::Subtract); break;
			case AbcOpcode::SubtractI: simple(IrOpcode::SubtractI); break;
			case AbcOpcode::Multiply: simple(IrOpcode::Multiply); break;
			case AbcOpcode::MultiplyI: simple(IrOpcode::MultiplyI); break;
			case AbcOpcode::Divide: simple(IrOpcode::Divide); break;
			case AbcOpcode::Modulo: simple(IrOpcode::Modulo); break;
			case AbcOpcode::LShift: simple(IrOpcode::LShift); break;
			case AbcOpcode::RShift: simple(IrOpcode::RShift); break;
			case AbcOpcode::URShift: simple(IrOpcode::URShift); break;
			case AbcOpcode::BitAnd: simple(IrOpcode::BitAnd); break;
			case AbcOpcode::BitOr: simple(IrOpcode::BitOr); break;
			case AbcOpcode::BitXor: simple(IrOpcode::BitXor); break;
			case AbcOpcode::BitNot: simple(IrOpcode::BitNot); break;
			case AbcOpcode::Negate: simple(IrOpcode::Negate); break;
			case AbcOpcode::NegateI: simple(IrOpcode::NegateI); break;
			case AbcOpcode::Increment: simple(IrOpcode::Increment); break;
			case AbcOpcode::IncrementI: simple(IrOpcode::IncrementI); break;
			case AbcOpcode::Decrement: simple(IrOpcode::Decrement); break;
			case AbcOpcode::DecrementI: simple(IrOpcode::DecrementI); break;
			case AbcOpcode::Not: simple(IrOpcode::Not); break;
			case AbcOpcode::Equals: simple(IrOpcode::Equals); break;
			case AbcOpcode::StrictEquals: simple(IrOpcode::StrictEquals); break;
			case AbcOpcode::LessThan: simple(IrOpcode::LessThan); break;
			case AbcOpcode::LessEquals: simple(IrOpcode::LessEquals); break;
			case AbcOpcode::GreaterThan: simple(IrOpcode::GreaterThan); break;
			case AbcOpcode::GreaterEquals: simple(IrOpcode::GreaterEquals); break;
			case AbcOpcode::TypeOf: simple(IrOpcode::TypeOf); break;
			case AbcOpcode::In: simple(IrOpcode::In); break;

			// --- stack manipulation ---
			case AbcOpcode::Pop: simple(IrOpcode::Pop); break;
			case AbcOpcode::Dup: simple(IrOpcode::Dup); break;
			case AbcOpcode::Swap: simple(IrOpcode::Swap); break;

			// --- control flow ---
			case AbcOpcode::Jump:
			{
				op.op = IrOpcode::Jump;
				op.imm = raw.offset;
				break;
			}
			case AbcOpcode::IfTrue:
			{
				op.op = IrOpcode::IfTrue;
				op.imm = raw.offset;
				break;
			}
			case AbcOpcode::IfFalse:
			{
				op.op = IrOpcode::IfFalse;
				op.imm = raw.offset;
				break;
			}
			case AbcOpcode::IfEq:
			case AbcOpcode::IfNe:
			case AbcOpcode::IfStrictEq:
			case AbcOpcode::IfStrictNe:
			case AbcOpcode::IfLt:
			case AbcOpcode::IfLe:
			case AbcOpcode::IfGt:
			case AbcOpcode::IfGe:
			case AbcOpcode::IfNlt:
			case AbcOpcode::IfNle:
			case AbcOpcode::IfNgt:
			case AbcOpcode::IfNge:
			{
				// Split compare-and-branch into compare + IfTrue/IfFalse.
				// The second op sits at byte start+1; its stored offset is
				// (offset - 1) so the uniform "+4 bytes" jump adjustment
				// lands on the same target (see verify.rs).
				bool branch_if_true;
				IrOpcode cmp;
				switch (raw.opcode)
				{
					case AbcOpcode::IfEq: cmp = IrOpcode::Equals; branch_if_true = true; break;
					case AbcOpcode::IfNe: cmp = IrOpcode::Equals; branch_if_true = false; break;
					case AbcOpcode::IfStrictEq: cmp = IrOpcode::StrictEquals; branch_if_true = true; break;
					case AbcOpcode::IfStrictNe: cmp = IrOpcode::StrictEquals; branch_if_true = false; break;
					case AbcOpcode::IfLt: cmp = IrOpcode::LessThan; branch_if_true = true; break;
					case AbcOpcode::IfLe: cmp = IrOpcode::LessEquals; branch_if_true = true; break;
					case AbcOpcode::IfGt: cmp = IrOpcode::GreaterThan; branch_if_true = true; break;
					case AbcOpcode::IfGe: cmp = IrOpcode::GreaterEquals; branch_if_true = true; break;
					case AbcOpcode::IfNlt: cmp = IrOpcode::LessThan; branch_if_true = false; break;
					case AbcOpcode::IfNle: cmp = IrOpcode::LessEquals; branch_if_true = false; break;
					case AbcOpcode::IfNgt: cmp = IrOpcode::GreaterThan; branch_if_true = false; break;
					default: cmp = IrOpcode::GreaterEquals; branch_if_true = false; break;  // IfNge
				}
				op.op = cmp;
				out.has_second = true;
				out.second.op = branch_if_true ? IrOpcode::IfTrue : IrOpcode::IfFalse;
				out.second.imm = raw.offset - 1;
				break;
			}
			case AbcOpcode::LookupSwitch:
			{
				op.op = IrOpcode::LookupSwitch;
				op.imm = raw.offset;  // default offset (raw)
				op.switch_targets.reserve(raw.case_offsets.size());
				for (s32 c : raw.case_offsets)
				{
					op.switch_targets.push_back((u32) c);  // raw offsets, adjusted later
				}
				break;
			}
			case AbcOpcode::Label: simple(IrOpcode::Nop); break;
			case AbcOpcode::Nop: simple(IrOpcode::Nop); break;

			// --- iteration ---
			case AbcOpcode::HasNext: simple(IrOpcode::HasNext); break;
			case AbcOpcode::NextName: simple(IrOpcode::NextName); break;
			case AbcOpcode::NextValue: simple(IrOpcode::NextValue); break;

			// --- exceptions ---
			case AbcOpcode::Throw: simple(IrOpcode::Throw); break;

			// --- XML / default namespace ---
			case AbcOpcode::Dxns:
			{
				if (!(method.flags & METHOD_SET_DXNS))
				{
					return failFilled(err, 1015,
					                  "Method " + methodDisplayName(abc, body.method)
					                  + " cannot set default xml namespace",
					                  "dxns used in method without SET_DXNS flag");
				}
				if (raw.arg1 == 0 || raw.arg1 >= pool.strings.size())
				{
					return failCpool(err, raw.arg1, pool.strings.size(), "string");
				}
				op.op = IrOpcode::Dxns;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::DxnsLate:
			{
				if (!(method.flags & METHOD_SET_DXNS))
				{
					return failFilled(err, 1015,
					                  "Method " + methodDisplayName(abc, body.method)
					                  + " cannot set default xml namespace",
					                  "dxnslate used in method without SET_DXNS flag");
				}
				simple(IrOpcode::DxnsLate);
				break;
			}
			case AbcOpcode::EscXAttr: simple(IrOpcode::EscXAttr); break;
			case AbcOpcode::EscXElem: simple(IrOpcode::EscXElem); break;
			case AbcOpcode::CheckFilter: simple(IrOpcode::CheckFilter); break;

			// --- alchemy / domain memory ---
			case AbcOpcode::Li8: simple(IrOpcode::Li8); break;
			case AbcOpcode::Li16: simple(IrOpcode::Li16); break;
			case AbcOpcode::Li32: simple(IrOpcode::Li32); break;
			case AbcOpcode::Lf32: simple(IrOpcode::Lf32); break;
			case AbcOpcode::Lf64: simple(IrOpcode::Lf64); break;
			case AbcOpcode::Si8: simple(IrOpcode::Si8); break;
			case AbcOpcode::Si16: simple(IrOpcode::Si16); break;
			case AbcOpcode::Si32: simple(IrOpcode::Si32); break;
			case AbcOpcode::Sf32: simple(IrOpcode::Sf32); break;
			case AbcOpcode::Sf64: simple(IrOpcode::Sf64); break;
			case AbcOpcode::Sxi1: simple(IrOpcode::Sxi1); break;
			case AbcOpcode::Sxi8: simple(IrOpcode::Sxi8); break;
			case AbcOpcode::Sxi16: simple(IrOpcode::Sxi16); break;

			// --- debug ---
			case AbcOpcode::Debug:
			{
				if (raw.arg1 >= pool.strings.size())
				{
					return failCpool(err, raw.arg1, pool.strings.size(), "string");
				}
				op.op = IrOpcode::Debug;
				op.arg1 = raw.arg1;
				op.byte_arg = raw.byte_arg;
				op.bool_arg = raw.bool_arg;
				break;
			}
			case AbcOpcode::DebugFile:
			{
				if (raw.arg1 >= pool.strings.size())
				{
					return failCpool(err, raw.arg1, pool.strings.size(), "string");
				}
				op.op = IrOpcode::DebugFile;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::DebugLine:
			{
				op.op = IrOpcode::DebugLine;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::Bkpt: simple(IrOpcode::Bkpt); break;
			case AbcOpcode::BkptLine:
			{
				op.op = IrOpcode::BkptLine;
				op.arg1 = raw.arg1;
				break;
			}
			case AbcOpcode::Timestamp: simple(IrOpcode::Timestamp); break;

			default:
			{
				// readOp folds GetLocal0-3/SetLocal0-3, so every remaining
				// opcode is handled above; this is unreachable for valid ops.
				return failFilled(err, 1011,
				                  "Method " + methodDisplayName(abc, body.method)
				                  + " contained illegal opcode "
				                  + to_string((unsigned) raw.opcode)
				                  + " at offset " + to_string(raw.code_offset) + ".",
				                  "unhandled opcode in translation");
			}
		}

		return true;
	}

	// =====================================================================
	// Static operand TYPE lattice (SWFRecompDocs/plans/
	// abc-verifier-type-lattice-arc.md). A second, read-only linear walk over
	// the resolved IR that raises the four avmplus type errors the depth pass
	// cannot see: #1058 (lookupswitch discriminant / RTQName namespace
	// operand), #1051 (early-bound slot access through `*`) and #1026 (slot
	// index past the class's slotCount).
	//
	// THE CONSERVATIVE DIRECTION IS THE WHOLE DESIGN. avmplus throws whenever
	// an operand is "not provably typed", which is safe for avmplus only
	// because its lattice models every op — for avmplus, "we didn't infer it"
	// and "the program says `*`" are the same set. Ours models a few dozen ops
	// out of ~160, so those two sets are wildly different, and conflating them
	// would report a property of THIS FILE as a property of the program. A
	// false positive here is not a wrong trace line: abc_emit.cpp lowers an
	// unverified body to avm2_verify_error_body(), i.e. it DELETES the method.
	//
	// Hence: four values, `Unknown` NEVER throws, and we throw only on an
	// affirmatively-known-wrong type.
	//
	//   Unknown  — our inference does not model this. Bottom for decisions.
	//   Any      — affirmatively the `*` type (CoerceA of an AFFIRMATIVE input
	//              only, so Unknown can never launder itself into a throw).
	//   Class(C) — affirmatively an instance of C (an ABC instance index, or
	//              one of ten builtin names resolved only when no ABC class
	//              shadows the name).
	//   ClassOf(C) — affirmatively the class OBJECT for C; exists purely so
	//              `construct` can produce Class(C). Never throws.
	//
	// Merge rule: there isn't one. At every branch target, switch target and
	// exception handler target the entire stack and all locals reset to
	// Unknown — the same "join = unknown" bail abc_emit.cpp's shipping TK/TV
	// coerce-elision lattice already uses. No fixpoint, no worklist re-entry,
	// no termination argument, and it cannot be unsound in the throwing
	// direction. It is also what makes this safe on real code: ASC's switch
	// idiom lands its discriminant at a merge point, so all 641 corpus
	// lookupswitch sites but one are Unknown, and 99.1% of getslot bases are
	// GetScopeObject/GetGlobalScope, which we never type.
	//
	// SWF_VERIFY_TYPES=<csv> turns the whole pass report-only: every predicate
	// hit is appended to the CSV and verification still SUCCEEDS. That is the
	// Stage-0 audit harness — sweep the corpus, and any row naming a test
	// other than the two this arc targets is a lattice bug to be fixed by
	// weakening inference, never by an exception list.
	// =====================================================================

	// Builtin class names we resolve, and only ever on a public-namespace
	// QName whose local name NO ABC class in this file declares.
	enum LatBuiltin : u8
	{
		LB_NONE = 0, LB_OBJECT, LB_INT, LB_UINT, LB_NUMBER, LB_STRING,
		LB_BOOLEAN, LB_NAMESPACE, LB_FUNCTION, LB_ARRAY, LB_CLASS
	};

	static const char* latBuiltinName(u8 b)
	{
		switch (b)
		{
			case LB_OBJECT:    return "Object";
			case LB_INT:       return "int";
			case LB_UINT:      return "uint";
			case LB_NUMBER:    return "Number";
			case LB_STRING:    return "String";
			case LB_BOOLEAN:   return "Boolean";
			case LB_NAMESPACE: return "Namespace";
			case LB_FUNCTION:  return "Function";
			case LB_ARRAY:     return "Array";
			case LB_CLASS:     return "Class";
			default:           return "*";
		}
	}

	static u8 latBuiltinOf(const string& n)
	{
		if (n == "Object")    return LB_OBJECT;
		if (n == "int")       return LB_INT;
		if (n == "uint")      return LB_UINT;
		if (n == "Number")    return LB_NUMBER;
		if (n == "String")    return LB_STRING;
		if (n == "Boolean")   return LB_BOOLEAN;
		if (n == "Namespace") return LB_NAMESPACE;
		if (n == "Function")  return LB_FUNCTION;
		if (n == "Array")     return LB_ARRAY;
		if (n == "Class")     return LB_CLASS;
		return LB_NONE;
	}

	enum class LatKind : u8 { Unknown = 0, Any, Class, ClassOf };

	struct LatValue
	{
		LatKind k = LatKind::Unknown;
		int inst = -1;    // ABC instance index, or -1 when `bi` names a builtin
		u8 bi = LB_NONE;  // builtin id, or LB_NONE when `inst` is the class
	};

	static LatValue latClassInst(int inst)
	{
		LatValue v; v.k = LatKind::Class; v.inst = inst; return v;
	}
	static LatValue latClassBuiltin(u8 b)
	{
		LatValue v; v.k = LatKind::Class; v.bi = b; return v;
	}
	static LatValue latAny()
	{
		LatValue v; v.k = LatKind::Any; return v;
	}

	// Display name of an affirmative value, for the avmplus message operand.
	static string latName(const AbcTypeModel& M, const LatValue& v)
	{
		if (v.k == LatKind::Any) return "*";
		if (v.inst >= 0 && v.inst < (int) M.abc.instances.size())
		{
			string n = M.localName(M.abc.instances[v.inst].name);
			return n.empty() ? "*" : n;
		}
		return latBuiltinName(v.bi);
	}

	// Resolve a TYPE multiname to the lattice. ABC classes win, and only when
	// the local name is UNAMBIGUOUS across the file (nameCount == 1); a
	// builtin resolves only when NO ABC class claims the name (nameCount == 0)
	// and the multiname is a public-namespace QName — so a user class named
	// `Namespace` resolves to neither the builtin nor (if it is one of several)
	// itself. Anything else is Unknown.
	static LatValue latResolveTypeMn(const AbcTypeModel& M, const AbcFile& abc, u32 mn)
	{
		if (mn == 0 || mn >= abc.pool.multinames.size()) return LatValue{};
		string n = M.localName(mn);
		if (n.empty()) return LatValue{};
		auto it = M.nameCount.find(n);
		int cnt = (it == M.nameCount.end()) ? 0 : it->second;
		if (cnt > 1) return LatValue{};
		if (cnt == 1)
		{
			int inst = M.typeMnToInst(mn);
			return inst >= 0 ? latClassInst(inst) : LatValue{};
		}
		u8 b = latBuiltinOf(n);
		if (b == LB_NONE) return LatValue{};
		const AbcMultiname& m = abc.pool.multinames[mn];
		u8 kind = (u8) m.kind;
		if (kind != 0x07 && kind != 0x0d) return LatValue{};   // QName / QNameA
		if (!AbcTypeModel::nsKeyPublic(M.nsKeyOf(m.ns))) return LatValue{};
		return latClassBuiltin(b);
	}

	// Is this value affirmatively "a Namespace"? A user class that happens to
	// be named Namespace counts as one for the purposes of NOT throwing: we
	// cannot tell it apart from the builtin, so we decline to decide.
	static bool latIsNamespace(const AbcTypeModel& M, const LatValue& v)
	{
		if (v.bi == LB_NAMESPACE) return true;
		if (v.inst >= 0) return latName(M, v) == "Namespace";
		return false;
	}

	// One predicate hit: everything the Stage-0 CSV and the armed failure both
	// need.
	struct LatHit
	{
		u32 op_index = 0;
		int code = 0;
		string message;    // avmplus wording, verbatim, for the thrown error
		string detail;     // our diagnostic wording, stderr only
		string inferred;   // the inferred operand type, for the CSV
	};

	// Per-AbcFile AbcTypeModel cache. Building the model is O(classes*traits);
	// a large SWF has ~96k bodies, so it must not be rebuilt per body. The
	// cache is invalidated by validateAbcFile(), which BOTH drivers (swf.cpp
	// and abc_tool.cpp) call exactly once per AbcFile immediately before their
	// body loop — so a recycled stack address can never serve a stale model.
	static const AbcFile* g_lat_model_abc = nullptr;
	static AbcTypeModel* g_lat_model = nullptr;

	// Class-bound method_info set for the #1107 method-association pass; same
	// pointer-identity caching discipline (and the same reset) as g_lat_model.
	static const AbcFile* g_bound_methods_abc = nullptr;
	static std::unordered_set<u32>* g_bound_methods = nullptr;

	void resetVerifierTypeModel()
	{
		delete g_lat_model;
		g_lat_model = nullptr;
		g_lat_model_abc = nullptr;
		delete g_bound_methods;
		g_bound_methods = nullptr;
		g_bound_methods_abc = nullptr;
	}

	static const AbcTypeModel& latModelFor(const AbcFile& abc)
	{
		if (g_lat_model == nullptr || g_lat_model_abc != &abc)
		{
			delete g_lat_model;
			g_lat_model = new AbcTypeModel(abc);
			g_lat_model_abc = &abc;
		}
		return *g_lat_model;
	}

	// =====================================================================
	// METHOD ASSOCIATION (#1107)
	//
	// avmplus gives every method_info exactly ONE MethodEnv, created by its
	// FIRST binding, and the verifier rejects any later use that contradicts
	// it. Ruffle models this as `Method::associate` / `check_classbound`
	// (core/src/avm2/method.rs:405-441), driven from
	// optimizer/type_aware.rs:
	//
	//     Op::NewFunction { method } =>
	//         method.associate(activation, MethodAssociation::freestanding())?
	//     Op::CallStatic { method, .. } =>
	//         method.check_classbound(activation)?
	//
	// Both raise VerifyError #1107 on failure. The class-bound associations
	// are all installed before any body is verified:
	//
	//   * class_object.rs:306-319 — every Method/Getter/Setter trait of the
	//     i_class and the c_class, plus both initializers (iinit / cinit);
	//   * script.rs:631-636 — the script's own init method, plus every
	//     Method/Getter/Setter trait of the synthetic `global` class.
	//
	// So the set is computable statically from the AbcFile, which is what
	// `classBoundMethodsFor` builds. `TraitKindType::Function` is deliberately
	// NOT in it: Ruffle's `Trait::as_method()` returns None for it
	// (traits.rs:228), so a function trait's method stays freestanding and may
	// legally be the operand of NewFunction.
	//
	// THE CONSERVATIVE DIRECTION, as everywhere else in this file: a false
	// positive DELETES a method (abc_emit.cpp lowers an unverified body to
	// avm2_verify_error_body). Both predicates are therefore stated on
	// affirmative membership of a set built only from bindings we can see in
	// this ABC — never on "we could not prove it is bound".
	// =====================================================================
	static void collectTraitMethods(const std::vector<AbcTrait>& traits,
	                                std::unordered_set<u32>& out)
	{
		for (const AbcTrait& t : traits)
		{
			if (t.kind == TraitKindType::Method || t.kind == TraitKindType::Getter
			    || t.kind == TraitKindType::Setter)
			{
				out.insert(t.method_or_class);
			}
		}
	}

	static const std::unordered_set<u32>& classBoundMethodsFor(const AbcFile& abc)
	{
		if (g_bound_methods == nullptr || g_bound_methods_abc != &abc)
		{
			delete g_bound_methods;
			g_bound_methods = new std::unordered_set<u32>();
			g_bound_methods_abc = &abc;
			std::unordered_set<u32>& S = *g_bound_methods;
			for (const AbcInstance& inst : abc.instances)
			{
				S.insert(inst.init_method);          // iinit
				collectTraitMethods(inst.traits, S); // i_class traits
			}
			for (const AbcClass& c : abc.classes)
			{
				S.insert(c.init_method);             // cinit
				collectTraitMethods(c.traits, S);    // c_class traits
			}
			for (const AbcScript& s : abc.scripts)
			{
				S.insert(s.init_method);             // script init -> global_class
				collectTraitMethods(s.traits, S);    // global_class traits
			}
		}
		return *g_bound_methods;
	}

	// SWF_ASSOC_AUDIT=<csv> makes this pass REPORT-ONLY, exactly like
	// SWF_VERIFY_TYPES does for the type lattice: every hit is appended to the
	// CSV and verification still SUCCEEDS. That is the corpus sweep harness —
	// it turns "which tests might this predicate touch" into an exact list
	// without needing a second recompiler binary to diff generated C against.
	static void assocWriteCsv(const char* path, const AbcFile& abc,
	                          const IrMethod& out, u32 op_index, u32 method_info,
	                          const char* what);

	// Returns false (and fills `err`) on the first offending op.
	static bool checkMethodAssociation(const AbcFile& abc, const IrMethod& out,
	                                   VerifyError& err)
	{
		const char* audit = getenv("SWF_ASSOC_AUDIT");
		const std::unordered_set<u32>* S = nullptr;
		for (size_t i = 0; i < out.ops.size(); ++i)
		{
			const IrOp& op = out.ops[i];
			bool is_new_fn = op.op == IrOpcode::NewFunction;
			bool is_static = op.op == IrOpcode::CallStatic;
			if (!is_new_fn && !is_static) continue;
			if (op.arg1 >= abc.methods.size()) continue;  // #1032 territory
			if (S == nullptr) S = &classBoundMethodsFor(abc);
			bool bound = S->count(op.arg1) != 0;
			if (!(is_new_fn && bound) && !(is_static && !bound)) continue;
			const char* what = is_new_fn ? "newfunction-bound" : "callstatic-unbound";
			if (audit != nullptr)
			{
				assocWriteCsv(audit, abc, out, (u32) i, op.arg1, what);
				continue;
			}
			return fail(err, 1107,
			            string(what) + " method_info " + to_string(op.arg1));
		}
		return true;
	}

	// Does this body contain any op a predicate could fire on? Building the
	// type model and running the walk is pure waste otherwise, and the vast
	// majority of bodies qualify for the skip.
	static bool latBodyHasCandidate(const AbcFile& abc, const IrMethod& out)
	{
		for (const IrOp& op : out.ops)
		{
			switch (op.op)
			{
				case IrOpcode::LookupSwitch:
				case IrOpcode::GetSlot:
				case IrOpcode::SetSlot:
					return true;
				case IrOpcode::CallProperty: case IrOpcode::CallPropLex:
				case IrOpcode::CallPropVoid: case IrOpcode::CallSuper:
				case IrOpcode::ConstructProp:
				case IrOpcode::GetPropertyStatic: case IrOpcode::GetPropertyFast:
				case IrOpcode::GetPropertySlow:
				case IrOpcode::SetPropertyStatic: case IrOpcode::SetPropertyFast:
				case IrOpcode::SetPropertySlow:
				case IrOpcode::InitProperty: case IrOpcode::DeleteProperty:
				case IrOpcode::GetSuper: case IrOpcode::SetSuper:
				case IrOpcode::GetDescendants:
				case IrOpcode::FindProperty: case IrOpcode::FindPropStrict:
				case IrOpcode::FindDef:
				{
					if (op.arg1 < abc.pool.multinames.size()
					    && abc.pool.multinames[op.arg1].hasLazyNs())
					{
						return true;
					}
					break;
				}
				default: break;
			}
		}
		return false;
	}

	// The linear walk. `stack_at` is the depth pass's per-op result: negative
	// means unreachable, otherwise the (unique, already-agreed) operand depth
	// on entry. Read-only over `out`; appends every hit, lowest op index
	// first.
	static void runTypeLattice(const AbcFile& abc, const AbcTypeModel& M,
	                           const AbcMethodBody& body, const IrMethod& out,
	                           const std::vector<s32>& stack_at,
	                           std::vector<LatHit>& hits)
	{
		const size_t n = out.ops.size();
		if (n == 0) return;

		// Every op whose incoming state must be discarded: op 0, every branch
		// / switch / exception-handler target, and every op that does not
		// physically follow its predecessor in the flow.
		std::vector<char> reset(n, 0);
		reset[0] = 1;
		for (size_t i = 0; i < n; i++)
		{
			const IrOp& op = out.ops[i];
			bool terminator = false;
			switch (op.op)
			{
				case IrOpcode::Jump:
					if (op.target < n) reset[op.target] = 1;
					terminator = true;
					break;
				case IrOpcode::IfTrue:
				case IrOpcode::IfFalse:
					if (op.target < n) reset[op.target] = 1;
					break;
				case IrOpcode::LookupSwitch:
					if (op.target < n) reset[op.target] = 1;
					for (u32 t : op.switch_targets)
					{
						if (t < n) reset[t] = 1;
					}
					terminator = true;
					break;
				case IrOpcode::ReturnValue:
				case IrOpcode::ReturnVoid:
				case IrOpcode::Throw:
					terminator = true;
					break;
				default: break;
			}
			if (terminator && i + 1 < n) reset[i + 1] = 1;
		}
		for (const IrException& e : out.exceptions)
		{
			if (e.active && e.target_op < n) reset[e.target_op] = 1;
		}

		std::vector<LatValue> locals(body.num_locals);
		std::vector<LatValue> stk;
		bool broken = true;   // forces a reset at the first modelled op

		for (size_t i = 0; i < n; i++)
		{
			if (stack_at[i] < 0)
			{
				broken = true;   // unreachable: the next op does not follow us
				continue;
			}
			if (broken || reset[i] || (s32) stk.size() != stack_at[i])
			{
				stk.assign((size_t) stack_at[i], LatValue{});
				std::fill(locals.begin(), locals.end(), LatValue{});
				broken = false;
			}

			const IrOp& op = out.ops[i];
			u32 pops = 0, pushes = 0;
			s32 scope_delta = 0;
			stackEffect(op, abc, pops, pushes, scope_delta);
			if (stk.size() < pops)
			{
				broken = true;   // cannot happen post-depth-check; bail anyway
				continue;
			}

			// peek(d) = the operand d slots below the top, pre-pop.
			auto peek = [&](u32 d) -> LatValue
			{
				return (d < stk.size()) ? stk[stk.size() - 1 - d] : LatValue{};
			};

			// ---- predicates -------------------------------------------
			if (op.op == IrOpcode::LookupSwitch)
			{
				LatValue v = peek(0);
				if (v.k == LatKind::Class && v.bi != LB_INT)
				{
					LatHit h;
					h.op_index = (u32) i;
					h.code = 1058;
					h.inferred = latName(M, v);
					h.message = "Error #1058: Illegal operand type: "
					          + h.inferred + " must be int.";
					h.detail = "lookupswitch index is statically " + h.inferred
					         + " at op " + to_string(i);
					hits.push_back(h);
				}
			}

			// RTQName / RTQNameL: the runtime namespace operand must be a
			// Namespace. Operand layout (see abc_emit.cpp's rtns lowering) is
			// [obj, ns, name] for the get/call/construct-prop family and
			// [obj, ns, name, value] for the set family, i.e. the ns always
			// sits exactly one slot above the object => depth `pops - 2`.
			// find* has no object operand, so the ns is the deepest of its
			// own pops => depth `pops - 1`.
			if (op.arg1 < abc.pool.multinames.size()
			    && abc.pool.multinames[op.arg1].hasLazyNs())
			{
				bool is_find = op.op == IrOpcode::FindProperty
				            || op.op == IrOpcode::FindPropStrict
				            || op.op == IrOpcode::FindDef;
				s32 depth = (s32) pops - (is_find ? 1 : 2);
				if (depth >= 0 && depth < (s32) stk.size())
				{
					LatValue v = peek((u32) depth);
					bool wrong = (v.k == LatKind::Any)
					          || (v.k == LatKind::Class && !latIsNamespace(M, v));
					if (wrong)
					{
						LatHit h;
						h.op_index = (u32) i;
						h.code = 1058;
						h.inferred = latName(M, v);
						h.message = "Error #1058: Illegal operand type: "
						          + h.inferred + " must be Namespace.";
						h.detail = "runtime namespace operand is statically "
						         + h.inferred + " at op " + to_string(i);
						hits.push_back(h);
					}
				}
			}

			if (op.op == IrOpcode::GetSlot || op.op == IrOpcode::SetSlot)
			{
				// getslot pops the base; setslot pops the value THEN the base.
				LatValue base = peek(op.op == IrOpcode::SetSlot ? 1 : 0);
				if (base.k == LatKind::Any)
				{
					LatHit h;
					h.op_index = (u32) i;
					h.code = 1051;
					h.inferred = "*";
					h.message = "Error #1051: Illegal early binding access to *.";
					h.detail = "early-bound slot access through `*` at op "
					         + to_string(i);
					hits.push_back(h);
				}
				else if (base.k == LatKind::Class && base.inst >= 0
				         && M.isSealed(base.inst))
				{
					// slotCountOf is -1 whenever any ancestor leaves the ABC
					// (native base => unknown slot origin), which is exactly
					// the "do not claim" rule this predicate needs.
					int sc = M.slotCountOf(base.inst);
					string cn = latName(M, base);
					auto nit = M.nameCount.find(cn);
					bool unique = nit != M.nameCount.end() && nit->second == 1;
					if (sc >= 0 && unique && (s32) op.arg1 >= sc)
					{
						LatHit h;
						h.op_index = (u32) i;
						h.code = 1026;
						h.inferred = cn;
						h.message = "Error #1026: Slot " + to_string(op.arg1 + 1)
						          + " exceeds slotCount=" + to_string(sc)
						          + " of " + cn + ".";
						h.detail = "slot " + to_string(op.arg1 + 1)
						         + " exceeds slotCount=" + to_string(sc)
						         + " of " + cn + " at op " + to_string(i);
						hits.push_back(h);
					}
				}
			}

			// ---- transfer ---------------------------------------------
			// Ops with their own stack shuffling are handled first; the rest
			// pop `pops` and push `pushes` copies of one computed result.
			if (op.op == IrOpcode::Dup)
			{
				LatValue v = peek(0);
				stk.push_back(v);
				continue;
			}
			if (op.op == IrOpcode::Swap)
			{
				LatValue a = peek(0), b = peek(1);
				stk[stk.size() - 1] = b;
				stk[stk.size() - 2] = a;
				continue;
			}
			if (op.op == IrOpcode::SetLocal)
			{
				if (op.arg1 < locals.size()) locals[op.arg1] = peek(0);
				stk.pop_back();
				continue;
			}
			if (op.op == IrOpcode::Kill || op.op == IrOpcode::IncLocal
			    || op.op == IrOpcode::IncLocalI || op.op == IrOpcode::DecLocal
			    || op.op == IrOpcode::DecLocalI)
			{
				if (op.arg1 < locals.size()) locals[op.arg1] = LatValue{};
				continue;   // no stack effect
			}
			if (op.op == IrOpcode::HasNext2)
			{
				// Writes both register operands; the pushed Boolean is not
				// worth modelling next to that.
				if (op.arg1 < locals.size()) locals[op.arg1] = LatValue{};
				if (op.arg2 < locals.size()) locals[op.arg2] = LatValue{};
				stk.push_back(LatValue{});
				continue;
			}

			LatValue result;
			switch (op.op)
			{
				case IrOpcode::PushInt:   result = latClassBuiltin(LB_INT); break;
				case IrOpcode::PushUint:  result = latClassBuiltin(LB_UINT); break;
				case IrOpcode::PushDouble:
				case IrOpcode::PushNaN:   result = latClassBuiltin(LB_NUMBER); break;
				case IrOpcode::PushString:
				case IrOpcode::ConvertS:
				case IrOpcode::CoerceS:   result = latClassBuiltin(LB_STRING); break;
				case IrOpcode::PushTrue:
				case IrOpcode::PushFalse:
				case IrOpcode::CoerceB:   result = latClassBuiltin(LB_BOOLEAN); break;
				case IrOpcode::PushNamespace:
					result = latClassBuiltin(LB_NAMESPACE); break;
				case IrOpcode::NewObject: result = latClassBuiltin(LB_OBJECT); break;
				case IrOpcode::NewArray:  result = latClassBuiltin(LB_ARRAY); break;
				case IrOpcode::NewFunction:
					result = latClassBuiltin(LB_FUNCTION); break;
				case IrOpcode::CoerceI:   result = latClassBuiltin(LB_INT); break;
				case IrOpcode::CoerceU:   result = latClassBuiltin(LB_UINT); break;
				case IrOpcode::CoerceD:   result = latClassBuiltin(LB_NUMBER); break;
				case IrOpcode::Coerce:
					result = latResolveTypeMn(M, abc, op.arg1); break;
				case IrOpcode::ConstructProp:
					result = latResolveTypeMn(M, abc, op.arg1); break;
				case IrOpcode::CoerceA:
				{
					// `Any` ONLY from an affirmative input. Unknown in,
					// Unknown out — otherwise every unmodelled value would
					// launder itself into a throwing #1051 through a coerce_a.
					result = (peek(0).k != LatKind::Unknown) ? latAny() : LatValue{};
					break;
				}
				case IrOpcode::Construct:
				{
					LatValue callee = peek(op.arg2);
					if (callee.k == LatKind::ClassOf)
					{
						result = callee;
						result.k = LatKind::Class;
					}
					break;
				}
				case IrOpcode::GetLocal:
					result = (op.arg1 < locals.size()) ? locals[op.arg1] : LatValue{};
					break;
				case IrOpcode::GetPropertyStatic:
				{
					// The getlex idiom only: FindPropStrict(mn) immediately
					// followed by GetPropertyStatic(mn) naming an ABC class
					// yields that class's class OBJECT. Deliberately NOT a
					// general "read a property off a typed receiver" rule —
					// FindPropStrict itself stays Unknown.
					if (peek(0).k == LatKind::Unknown && i > 0
					    && out.ops[i - 1].op == IrOpcode::FindPropStrict
					    && out.ops[i - 1].arg1 == op.arg1)
					{
						LatValue t = latResolveTypeMn(M, abc, op.arg1);
						if (t.k == LatKind::Class && t.inst >= 0)
						{
							result = t;
							result.k = LatKind::ClassOf;
						}
					}
					break;
				}
				default: break;   // Unknown
			}

			for (u32 p = 0; p < pops; p++) stk.pop_back();
			for (u32 p = 0; p < pushes; p++) stk.push_back(result);
		}
	}

	// Method kind, for the Stage-0 CSV (R9: a hit on an init in a passing test
	// is a hard stop, so the sweep has to be able to see them).
	static const char* latMethodKind(const AbcFile& abc, u32 method_index)
	{
		for (const AbcScript& s : abc.scripts)
		{
			if (s.init_method == method_index) return "script_init";
		}
		for (const AbcClass& c : abc.classes)
		{
			if (c.init_method == method_index) return "class_init";
		}
		for (const AbcInstance& in : abc.instances)
		{
			if (in.init_method == method_index) return "ctor";
		}
		return "method";
	}

	// Report-only label for the CSV's first column (the SWF being verified).
	// abc_tool.cpp sets it per input file; empty everywhere else.
	static string g_lat_source_label;

	void setVerifierSourceLabel(const string& label)
	{
		g_lat_source_label = label;
	}

	static void latWriteCsv(const char* path, const AbcFile& abc,
	                        const AbcMethodBody& body, const IrMethod& out,
	                        const std::vector<LatHit>& hits)
	{
		FILE* f = fopen(path, "a");
		if (f == nullptr) return;
		u32 mi = out.method_index;
		string mname = "?";
		if (mi < abc.methods.size() && abc.methods[mi].name < abc.pool.strings.size()
		    && abc.methods[mi].name != 0)
		{
			mname = abc.pool.strings[abc.methods[mi].name];
		}
		for (const LatHit& h : hits)
		{
			fprintf(f, "%s,%s,%s,%u,%u,%d,%s,\"%s\"\n",
			        g_lat_source_label.c_str(), mname.c_str(),
			        latMethodKind(abc, mi), out.body_index, h.op_index,
			        h.code, h.inferred.c_str(), h.detail.c_str());
		}
		(void) body;
		fclose(f);
	}

	// Report-only row for the #1107 method-association pass (SWF_ASSOC_AUDIT).
	// Columns: swf, method name, body index, op index, method_info, predicate.
	static void assocWriteCsv(const char* path, const AbcFile& abc,
	                          const IrMethod& out, u32 op_index, u32 method_info,
	                          const char* what)
	{
		FILE* f = fopen(path, "a");
		if (f == nullptr) return;
		string mname = "?";
		u32 mi = out.method_index;
		if (mi < abc.methods.size() && abc.methods[mi].name != 0
		    && abc.methods[mi].name < abc.pool.strings.size())
		{
			mname = abc.pool.strings[abc.methods[mi].name];
		}
		fprintf(f, "%s,%s,%u,%u,%u,%s\n", g_lat_source_label.c_str(),
		        mname.c_str(), out.body_index, op_index, method_info, what);
		fclose(f);
	}

	// === main entry ===

	enum class ByteState : u8
	{
		NotYetReached,
		OpContinue,
		OpStart,
		OpStartNonJumpable,
	};

	bool verifyMethodBody(const AbcFile& abc, u32 body_index, IrMethod& out, VerifyError& err)
	{
		if (body_index >= abc.method_bodies.size())
		{
			return failCpool(err, body_index, abc.method_bodies.size(), "method body");
		}
		const AbcMethodBody& body = abc.method_bodies[body_index];
		const AbcMethod& method = abc.methods[body.method];
		out.method_index = body.method;
		out.body_index = body_index;

		size_t param_count = method.params.size();
		u32 max_locals = body.num_locals;

		if ((size_t) max_locals < 1 + param_count)
		{
			return fail(err, 1107, "not enough local registers for parameters");
		}
		bool is_variadic = (method.flags & (METHOD_NEED_ARGUMENTS | METHOD_NEED_REST)) != 0;
		if ((size_t) max_locals < 1 + param_count + (is_variadic ? 1 : 0))
		{
			return failFilled(err, 1025,
			                  "An invalid register " + to_string(1 + param_count)
			                  + " was accessed.",
			                  "access of out-of-range local register "
			                  + to_string(1 + param_count));
		}
		if (body.code.empty())
		{
			return failFilled(err, 1043, "Invalid code_length=0.",
				                  "invalid code length 0");
		}

		size_t code_len = body.code.size();
		std::vector<ByteState> states(code_len, ByteState::NotYetReached);
		std::vector<IrOp> op_at(code_len);

		std::vector<u32> worklist;
		worklist.push_back(0);
		std::unordered_set<s64> seen_targets;
		std::unordered_set<u32> seen_exception_indices;

		AbcReader reader(body.code.data(), code_len);

		while (!worklist.empty())
		{
			u32 start = worklist.back();
			worklist.pop_back();
			reader.seek(start);

			while (true)
			{
				s64 prev_pos = (s64) reader.pos();

				// Already verified from here — don't redo the chunk.
				if (prev_pos < (s64) code_len
				    && states[prev_pos] == ByteState::OpStart)
				{
					break;
				}

				RawOp raw;
				try
				{
					raw = readOp(reader);
				}
				catch (const AbcError& e)
				{
					if (e.eof)
					{
						// Code flow continued past the end of the method.
						return fail(err, 1020, "code cannot fall off the end of a method");
					}
					// The unknown byte is still sitting at the op's start;
					// avmplus reports it in decimal with its code offset.
					unsigned bad = prev_pos >= 0 && prev_pos < (s64) code_len
					             ? (unsigned) body.code[(size_t) prev_pos] : 0u;
					return failFilled(err, 1011,
					                  "Method " + methodDisplayName(abc, body.method)
					                  + " contained illegal opcode " + to_string(bad)
					                  + " at offset " + to_string(prev_pos) + ".",
					                  e.what());
				}

				if (opCanThrowError(raw.opcode))
				{
					for (size_t ei = 0; ei < body.exceptions.size(); ++ei)
					{
						const AbcException& exc = body.exceptions[ei];
						if ((s64) exc.from_offset <= prev_pos
						    && prev_pos < (s64) exc.to_offset)
						{
							if (!seen_targets.count((s64) exc.target_offset))
							{
								worklist.push_back(exc.target_offset);
								seen_targets.insert((s64) exc.target_offset);
							}
							seen_exception_indices.insert((u32) ei);
						}
					}
				}

				s64 new_pos = (s64) reader.pos();

				auto check_target = [&](s32 offs, bool is_jump) -> bool
				{
					s64 target = (s64) offs + (is_jump ? new_pos : prev_pos);

					if (target >= 0 && target < (s64) code_len)
					{
						ByteState st = states[target];
						if (st == ByteState::OpContinue
						    || st == ByteState::OpStartNonJumpable)
						{
							return fail(err, 1021, "branch target into the middle of an instruction");
						}
					}

					if (target < 0 || target >= (s64) code_len)
					{
						return fail(err, 1021, "branch target out of bounds");
					}

					// Backwards jumps to not-yet-visited code must target a
					// `label` op.
					if (!seen_targets.count(target) && offs < 0)
					{
						size_t save = reader.pos();
						reader.seek((size_t) target);
						bool is_label = false;
						try
						{
							RawOp t = readOp(reader);
							is_label = (t.opcode == AbcOpcode::Label);
						}
						catch (const AbcError&)
						{
							is_label = false;
						}
						reader.seek(save);
						if (!is_label)
						{
							return fail(err, 1021, "backward branch target is not a label");
						}
					}

					return true;
				};

				switch (raw.opcode)
				{
					case AbcOpcode::IfEq: case AbcOpcode::IfNe:
					case AbcOpcode::IfStrictEq: case AbcOpcode::IfStrictNe:
					case AbcOpcode::IfLt: case AbcOpcode::IfLe:
					case AbcOpcode::IfGt: case AbcOpcode::IfGe:
					case AbcOpcode::IfNlt: case AbcOpcode::IfNle:
					case AbcOpcode::IfNgt: case AbcOpcode::IfNge:
					case AbcOpcode::IfTrue: case AbcOpcode::IfFalse:
					case AbcOpcode::Jump:
					{
						if (!check_target(raw.offset, true))
						{
							return false;
						}
						s64 target = (s64) raw.offset + new_pos;
						if (!seen_targets.count(target))
						{
							worklist.push_back((u32) target);
							seen_targets.insert(target);
						}
						break;
					}

					case AbcOpcode::LookupSwitch:
					{
						if (!check_target(raw.offset, false))
						{
							return false;
						}
						s64 default_target = (s64) raw.offset + prev_pos;
						if (!seen_targets.count(default_target))
						{
							seen_targets.insert(default_target);
							worklist.push_back((u32) default_target);
						}

						for (s32 case_offset : raw.case_offsets)
						{
							if (!check_target(case_offset, false))
							{
								return false;
							}
							s64 case_target = (s64) case_offset + prev_pos;
							if (!seen_targets.count(case_target))
							{
								seen_targets.insert(case_target);
								worklist.push_back((u32) case_target);
							}
						}
						break;
					}

					default: break;
				}

				bool is_terminator = raw.opcode == AbcOpcode::Jump
				                  || raw.opcode == AbcOpcode::LookupSwitch
				                  || raw.opcode == AbcOpcode::Throw
				                  || raw.opcode == AbcOpcode::ReturnValue
				                  || raw.opcode == AbcOpcode::ReturnVoid;

				TranslatedOp translated;
				if (!translateOp(abc, method, body, raw, translated, err))
				{
					return false;
				}

				s64 bytes_read = new_pos - prev_pos;
				for (s64 j = 0; j < bytes_read; ++j)
				{
					states[prev_pos + j] = ByteState::OpContinue;
				}
				states[prev_pos] = ByteState::OpStart;
				op_at[prev_pos] = translated.first;
				if (translated.has_second)
				{
					// Split ops register a non-jumpable second op at the next
					// byte (all splittable ops occupy >= 2 bytes).
					states[prev_pos + 1] = ByteState::OpStartNonJumpable;
					op_at[prev_pos + 1] = translated.second;
				}

				if (is_terminator)
				{
					break;
				}
			}
		}

		// Compact reached ops into the final list; build offset maps.
		std::vector<s32> byte_to_idx(code_len, -1);
		std::vector<u32> idx_to_byte;
		out.ops.clear();
		for (size_t i = 0; i < code_len; ++i)
		{
			if (states[i] == ByteState::OpStart || states[i] == ByteState::OpStartNonJumpable)
			{
				byte_to_idx[i] = (s32) out.ops.size();
				out.ops.push_back(op_at[i]);
				idx_to_byte.push_back((u32) i);
			}
		}

		// Resolve the exception table to op-index ranges.
		out.exceptions.clear();
		for (size_t ei = 0; ei < body.exceptions.size(); ++ei)
		{
			const AbcException& exc = body.exceptions[ei];

			IrException ir_exc;
			ir_exc.type_name = exc.type_name;
			ir_exc.variable_name = exc.variable_name;

			if (exc.type_name != 0)
			{
				const AbcMultiname& mn = abc.pool.multinames[exc.type_name];
				if (mn.hasLazyComponent())
				{
					return failFilled(err, 1014,
					                  "Class " + multinameDisplay(abc, exc.type_name)
					                  + " could not be found.",
					                  "exception type multiname has runtime components");
				}
			}
			if (exc.variable_name != 0)
			{
				const AbcMultiname& mn = abc.pool.multinames[exc.variable_name];
				if (mn.hasLazyComponent() || mn.isAttribute() || mn.name == 0)
				{
					return fail(err, 1107, "invalid exception variable name");
				}
				// avmplus reads the first namespace of the set and segfaults
				// on an empty one; we report a clean error instead.
				if ((mn.kind == MultinameKind::Multiname || mn.kind == MultinameKind::MultinameA)
				    && abc.pool.ns_sets[mn.ns_set].empty())
				{
					return fail(err, 1107, "exception variable name has empty namespace set");
				}
			}

			if (!seen_exception_indices.count((u32) ei))
			{
				// No reachable throwing op is covered: keep a dummy entry
				// (newcatch may still reference it) with inactive offsets.
				out.exceptions.push_back(ir_exc);
				continue;
			}

			// avmplus permits from/to offsets that aren't on an op boundary;
			// step forward byte-by-byte to the next op (Ruffle does the same).
			s32 from_op = -1;
			for (u32 offs = 0; ; ++offs)
			{
				u32 pos = exc.from_offset + offs;
				if (pos < code_len && byte_to_idx[pos] >= 0)
				{
					from_op = byte_to_idx[pos];
					break;
				}
				if ((u64) exc.from_offset + offs + 1 >= code_len)
				{
					return fail(err, 1054, "illegal exception handler range (from)");
				}
			}

			s32 to_op = -1;
			for (u32 offs = 0; ; ++offs)
			{
				u32 pos = exc.to_offset + offs;
				if (pos < code_len && byte_to_idx[pos] >= 0)
				{
					to_op = byte_to_idx[pos];
					break;
				}
				if ((u64) exc.to_offset + offs + 1 >= code_len)
				{
					return fail(err, 1054, "illegal exception handler range (to)");
				}
			}

			if (to_op < from_op)
			{
				return fail(err, 1054, "illegal exception handler range (to < from)");
			}

			s32 target_op = 0;
			if (exc.target_offset < code_len && byte_to_idx[exc.target_offset] >= 0)
			{
				target_op = byte_to_idx[exc.target_offset];
			}

			if (exc.target_offset < exc.to_offset)
			{
				return fail(err, 1054, "exception target inside protected range");
			}
			if ((size_t) target_op >= out.ops.size())
			{
				return fail(err, 1054, "exception target out of range");
			}

			ir_exc.from_op = (u32) from_op;
			ir_exc.to_op = (u32) to_op;
			ir_exc.target_op = (u32) target_op;
			ir_exc.active = true;
			out.exceptions.push_back(ir_exc);
		}

		// Rewrite branch offsets (byte-relative) into absolute op indices.
		const s64 JUMP_INSTRUCTION_LENGTH = 4;
		auto adjust_jump_to_idx = [&](size_t i, s32 offset, bool is_jump, u32& out_idx) -> bool
		{
			s64 byte_offset = idx_to_byte[i];
			if (is_jump)
			{
				byte_offset += JUMP_INSTRUCTION_LENGTH;
			}
			s64 new_byte_offset = byte_offset + offset;
			if (new_byte_offset < 0 || new_byte_offset >= (s64) code_len
			    || byte_to_idx[new_byte_offset] < 0)
			{
				return fail(err, 1021, "branch target is not on an instruction boundary");
			}
			out_idx = (u32) byte_to_idx[new_byte_offset];
			return true;
		};

		for (size_t i = 0; i < out.ops.size(); ++i)
		{
			IrOp& op = out.ops[i];
			switch (op.op)
			{
				case IrOpcode::IfTrue:
				case IrOpcode::IfFalse:
				case IrOpcode::Jump:
				{
					if (!adjust_jump_to_idx(i, op.imm, true, op.target))
					{
						return false;
					}
					op.imm = 0;
					break;
				}
				case IrOpcode::LookupSwitch:
				{
					if (!adjust_jump_to_idx(i, op.imm, false, op.target))
					{
						return false;
					}
					op.imm = 0;
					for (size_t k = 0; k < op.switch_targets.size(); ++k)
					{
						u32 adjusted;
						if (!adjust_jump_to_idx(i, (s32) op.switch_targets[k], false, adjusted))
						{
							return false;
						}
						op.switch_targets[k] = adjusted;
					}
					break;
				}
				default: break;
			}
		}

		// Static stack/scope-depth checking (max_stack / max_scope_depth
		// validation). Depths at every op are computed over the CFG and must
		// agree on every path (avmplus errors 1030/1031 on mismatch).
		// `stack_at` outlives the block: the static TYPE pass below reuses it
		// both as the reachability map and as the authoritative depth at each
		// op (a mismatch against its own model is a hard reset — see
		// runTypeLattice).
		std::vector<s32> stack_at(out.ops.size(), -1);
		{
			s64 local_scope_max = (s64) body.max_scope_depth - (s64) body.init_scope_depth;

			struct SimEntry
			{
				u32 idx;
				s32 stack;
				s32 scope;
			};
			std::vector<s32> scope_at(out.ops.size(), -1);
			std::vector<char> simulated(out.ops.size(), 0);
			std::vector<SimEntry> sim_list;
			std::vector<SimEntry> handler_list;

			// A catch target's entry state is KNOWN before any code runs, so
			// avmplus (which verifies in offset order) has it on record by the
			// time normal control flow branches there — a disagreement is then
			// #1030/#1031, not whatever the handler body would have hit on its
			// own. Record those states up front and simulate the handler
			// bodies only after the normal flow is exhausted; otherwise a
			// LIFO walk simulates the handler first and reports its downstream
			// #1024 instead (avm2/verify_exception_target_two_jumps).
			for (const IrException& e : out.exceptions)
			{
				if (!e.active) continue;
				if (e.target_op >= out.ops.size())
				{
					return fail(err, 1020, "code cannot fall off the end of a method");
				}
				// Catch entry: operand stack holds only the thrown value;
				// the local scope stack is cleared.
				if (stack_at[e.target_op] < 0)
				{
					stack_at[e.target_op] = 1;
					scope_at[e.target_op] = 0;
				}
				handler_list.push_back({ e.target_op, 1, 0 });
			}
			sim_list.push_back({ 0, 0, 0 });

			while (!sim_list.empty() || !handler_list.empty())
			{
				SimEntry entry;
				if (!sim_list.empty())
				{
					entry = sim_list.back();
					sim_list.pop_back();
				}
				else
				{
					entry = handler_list.back();
					handler_list.pop_back();
				}

				if (entry.idx >= out.ops.size())
				{
					return fail(err, 1020, "code cannot fall off the end of a method");
				}

				if (stack_at[entry.idx] >= 0)
				{
					if (stack_at[entry.idx] != entry.stack)
					{
						return failFilled(err, 1030,
						                  "Stack depth is unbalanced. "
						                  + to_string(stack_at[entry.idx]) + " != "
						                  + to_string(entry.stack) + ".",
						                  "stack depth unbalanced at op "
						                  + to_string(entry.idx));
					}
					if (scope_at[entry.idx] != entry.scope)
					{
						return failFilled(err, 1031,
						                  "Scope depth is unbalanced. "
						                  + to_string(scope_at[entry.idx]) + " != "
						                  + to_string(entry.scope) + ".",
						                  "scope depth unbalanced at op "
						                  + to_string(entry.idx));
					}
					if (simulated[entry.idx]) continue;
				}
				stack_at[entry.idx] = entry.stack;
				scope_at[entry.idx] = entry.scope;
				simulated[entry.idx] = 1;

				const IrOp& op = out.ops[entry.idx];
				u32 pops, pushes;
				s32 scope_delta;
				stackEffect(op, abc, pops, pushes, scope_delta);

				if (entry.stack < (s32) pops)
				{
					return fail(err, 1024, "stack underflow at op " + to_string(entry.idx));
				}
				s32 new_stack = entry.stack - (s32) pops + (s32) pushes;
				if (new_stack > (s32) body.max_stack)
				{
					return fail(err, 1023, "stack overflow at op " + to_string(entry.idx)
					            + " (depth " + to_string(new_stack) + " > max_stack "
					            + to_string(body.max_stack) + ")");
				}
				s32 new_scope = entry.scope + scope_delta;
				if (new_scope < 0)
				{
					return fail(err, 1018, "scope stack underflow at op " + to_string(entry.idx));
				}
				if ((s64) new_scope > local_scope_max)
				{
					return fail(err, 1017, "scope stack overflow at op " + to_string(entry.idx));
				}

				if (op.op == IrOpcode::GetScopeObject && (s32) op.arg1 >= entry.scope)
				{
					return failFilled(err, 1019,
					                  "Getscopeobject " + to_string(op.arg1)
					                  + " is out of bounds.",
					                  "getscopeobject " + to_string(op.arg1)
					                  + " is out of bounds at op "
					                  + to_string(entry.idx));
				}

				if (new_stack > (s32) out.computed_max_stack)
				{
					out.computed_max_stack = (u32) new_stack;
				}
				if (new_scope > (s32) out.computed_max_scope)
				{
					out.computed_max_scope = (u32) new_scope;
				}

				switch (op.op)
				{
					case IrOpcode::Jump:
					{
						sim_list.push_back({ op.target, new_stack, new_scope });
						break;
					}
					case IrOpcode::IfTrue:
					case IrOpcode::IfFalse:
					{
						sim_list.push_back({ op.target, new_stack, new_scope });
						sim_list.push_back({ entry.idx + 1, new_stack, new_scope });
						break;
					}
					case IrOpcode::LookupSwitch:
					{
						sim_list.push_back({ op.target, new_stack, new_scope });
						for (u32 t : op.switch_targets)
						{
							sim_list.push_back({ t, new_stack, new_scope });
						}
						break;
					}
					case IrOpcode::ReturnValue:
					case IrOpcode::ReturnVoid:
					case IrOpcode::Throw:
					{
						break;
					}
					default:
					{
						sim_list.push_back({ entry.idx + 1, new_stack, new_scope });
						break;
					}
				}
			}
		}

		// Static operand TYPE pass. Runs only after the depth pass has
		// SUCCEEDED, as a separate read-only walk, so every body without a
		// type error behaves bit-identically to before and a body with both a
		// depth and a type problem still reports the depth one (avmplus order).
		if (latBodyHasCandidate(abc, out))
		{
			std::vector<LatHit> hits;
			runTypeLattice(abc, latModelFor(abc), body, out, stack_at, hits);
			if (!hits.empty())
			{
				const char* csv = getenv("SWF_VERIFY_TYPES");
				if (csv != nullptr)
				{
					// Report-only audit mode: record and pass.
					latWriteCsv(csv, abc, body, out, hits);
				}
				else
				{
					// Lowest op index wins (hits are appended in walk order).
					err.code = hits[0].code;
					err.message = hits[0].message;
					err.detail = hits[0].detail;
					return false;
				}
			}
		}

		// Method-association pass (#1107). Last, like the type pass, so a body
		// with any other verify problem still reports that one first.
		if (!checkMethodAssociation(abc, out, err))
		{
			return false;
		}

		return true;
	}
}
}
