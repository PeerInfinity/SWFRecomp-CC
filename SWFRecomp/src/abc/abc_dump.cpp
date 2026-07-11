#include <abc/abc_dump.hpp>
#include <abc/abc_verifier.hpp>

#include <cstdio>
#include <sstream>

using std::endl;
using std::ostream;
using std::string;
using std::to_string;

namespace SWFRecomp
{
namespace abc
{
	// Escapes and truncates a pool string for display.
	static string displayString(const string& s, size_t max_len = 80)
	{
		string out;
		out.reserve(s.size() + 2);
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (out.size() >= max_len)
			{
				out += "...";
				break;
			}
			char c = s[i];
			switch (c)
			{
				case '\n': out += "\\n"; break;
				case '\r': out += "\\r"; break;
				case '\t': out += "\\t"; break;
				case '"': out += "\\\""; break;
				case '\\': out += "\\\\"; break;
				default:
				{
					if ((unsigned char) c < 0x20)
					{
						char buf[8];
						snprintf(buf, sizeof(buf), "\\x%02x", (unsigned char) c);
						out += buf;
					}
					else
					{
						out += c;
					}
				}
			}
		}
		return out;
	}

	static string poolString(const AbcFile& abc, u32 index)
	{
		if (index >= abc.pool.strings.size())
		{
			return "<bad-string-" + to_string(index) + ">";
		}
		return displayString(abc.pool.strings[index]);
	}

	string namespaceToString(const AbcFile& abc, u32 ns_index)
	{
		if (ns_index == 0)
		{
			return "*";
		}
		if (ns_index >= abc.pool.namespaces.size())
		{
			return "<bad-ns-" + to_string(ns_index) + ">";
		}
		const AbcNamespace& ns = abc.pool.namespaces[ns_index];
		const char* kind;
		switch (ns.kind)
		{
			case NamespaceKind::Namespace: kind = "ns"; break;
			case NamespaceKind::Package: kind = "package"; break;
			case NamespaceKind::PackageInternal: kind = "internal"; break;
			case NamespaceKind::Protected: kind = "protected"; break;
			case NamespaceKind::Explicit: kind = "explicit"; break;
			case NamespaceKind::StaticProtected: kind = "static protected"; break;
			case NamespaceKind::Private: kind = "private"; break;
			default: kind = "?"; break;
		}
		string name = poolString(abc, ns.name);
		if (name.empty())
		{
			return string(kind);
		}
		return string(kind) + " \"" + name + "\"";
	}

	string multinameToString(const AbcFile& abc, u32 mn_index)
	{
		if (mn_index == 0)
		{
			return "*";
		}
		if (mn_index >= abc.pool.multinames.size())
		{
			return "<bad-multiname-" + to_string(mn_index) + ">";
		}
		const AbcMultiname& mn = abc.pool.multinames[mn_index];
		string attr = mn.isAttribute() ? "@" : "";
		switch (mn.kind)
		{
			case MultinameKind::QName:
			case MultinameKind::QNameA:
			{
				string ns;
				if (mn.ns != 0 && mn.ns < abc.pool.namespaces.size())
				{
					const AbcNamespace& n = abc.pool.namespaces[mn.ns];
					string ns_name = poolString(abc, n.name);
					if (!ns_name.empty())
					{
						ns = ns_name + "::";
					}
					else if (n.kind == NamespaceKind::Private)
					{
						ns = "private::";
					}
				}
				else if (mn.ns == 0)
				{
					ns = "*::";
				}
				return attr + ns + poolString(abc, mn.name);
			}
			case MultinameKind::RTQName:
			case MultinameKind::RTQNameA:
			{
				return attr + "{rt-ns}::" + poolString(abc, mn.name);
			}
			case MultinameKind::RTQNameL:
			case MultinameKind::RTQNameLA:
			{
				return attr + "{rt-ns}::{rt-name}";
			}
			case MultinameKind::Multiname:
			case MultinameKind::MultinameA:
			{
				return attr + "{ns-set " + to_string(mn.ns_set) + "}::"
				       + poolString(abc, mn.name);
			}
			case MultinameKind::MultinameL:
			case MultinameKind::MultinameLA:
			{
				return attr + "{ns-set " + to_string(mn.ns_set) + "}::{rt-name}";
			}
			case MultinameKind::TypeName:
			{
				string s = multinameToString(abc, mn.base_type) + ".<";
				for (size_t i = 0; i < mn.type_params.size(); ++i)
				{
					if (i > 0)
					{
						s += ",";
					}
					s += multinameToString(abc, mn.type_params[i]);
				}
				return s + ">";
			}
			default:
			{
				return "<unknown-multiname-kind>";
			}
		}
	}

	static string defaultValueToString(const AbcFile& abc, const DefaultValue& v)
	{
		if (!v.present)
		{
			return "<none>";
		}
		switch (v.kind)
		{
			case DefaultValueKind::Undefined: return "undefined";
			case DefaultValueKind::True: return "true";
			case DefaultValueKind::False: return "false";
			case DefaultValueKind::Null: return "null";
			case DefaultValueKind::Int:
			{
				if (v.index < abc.pool.ints.size())
				{
					return to_string(abc.pool.ints[v.index]);
				}
				return "<bad-int>";
			}
			case DefaultValueKind::Uint:
			{
				if (v.index < abc.pool.uints.size())
				{
					return to_string(abc.pool.uints[v.index]) + "u";
				}
				return "<bad-uint>";
			}
			case DefaultValueKind::Double:
			{
				if (v.index < abc.pool.doubles.size())
				{
					char buf[40];
					snprintf(buf, sizeof(buf), "%g", abc.pool.doubles[v.index]);
					return buf;
				}
				return "<bad-double>";
			}
			case DefaultValueKind::String:
			{
				return "\"" + poolString(abc, v.index) + "\"";
			}
			default:
			{
				return "namespace(" + namespaceToString(abc, v.index) + ")";
			}
		}
	}

	static string methodDisplayName(const AbcFile& abc, u32 method_index)
	{
		if (method_index >= abc.methods.size())
		{
			return "<bad-method-" + to_string(method_index) + ">";
		}
		string name = poolString(abc, abc.methods[method_index].name);
		if (name.empty())
		{
			name = "<anon>";
		}
		return name;
	}

	static const char* irOpcodeName(IrOpcode op)
	{
		switch (op)
		{
			case IrOpcode::Add: return "Add";
			case IrOpcode::AddI: return "AddI";
			case IrOpcode::ApplyType: return "ApplyType";
			case IrOpcode::AsType: return "AsType";
			case IrOpcode::AsTypeLate: return "AsTypeLate";
			case IrOpcode::BitAnd: return "BitAnd";
			case IrOpcode::BitNot: return "BitNot";
			case IrOpcode::BitOr: return "BitOr";
			case IrOpcode::BitXor: return "BitXor";
			case IrOpcode::Bkpt: return "Bkpt";
			case IrOpcode::BkptLine: return "BkptLine";
			case IrOpcode::Call: return "Call";
			case IrOpcode::CallProperty: return "CallProperty";
			case IrOpcode::CallPropLex: return "CallPropLex";
			case IrOpcode::CallPropVoid: return "CallPropVoid";
			case IrOpcode::CallStatic: return "CallStatic";
			case IrOpcode::CallSuper: return "CallSuper";
			case IrOpcode::CheckFilter: return "CheckFilter";
			case IrOpcode::Coerce: return "Coerce";
			case IrOpcode::CoerceA: return "CoerceA";
			case IrOpcode::CoerceB: return "CoerceB";
			case IrOpcode::CoerceD: return "CoerceD";
			case IrOpcode::CoerceI: return "CoerceI";
			case IrOpcode::CoerceO: return "CoerceO";
			case IrOpcode::CoerceS: return "CoerceS";
			case IrOpcode::CoerceU: return "CoerceU";
			case IrOpcode::Construct: return "Construct";
			case IrOpcode::ConstructProp: return "ConstructProp";
			case IrOpcode::ConstructSuper: return "ConstructSuper";
			case IrOpcode::ConvertO: return "ConvertO";
			case IrOpcode::ConvertS: return "ConvertS";
			case IrOpcode::Debug: return "Debug";
			case IrOpcode::DebugFile: return "DebugFile";
			case IrOpcode::DebugLine: return "DebugLine";
			case IrOpcode::DecLocal: return "DecLocal";
			case IrOpcode::DecLocalI: return "DecLocalI";
			case IrOpcode::Decrement: return "Decrement";
			case IrOpcode::DecrementI: return "DecrementI";
			case IrOpcode::DeleteProperty: return "DeleteProperty";
			case IrOpcode::Divide: return "Divide";
			case IrOpcode::Dup: return "Dup";
			case IrOpcode::Dxns: return "Dxns";
			case IrOpcode::DxnsLate: return "DxnsLate";
			case IrOpcode::Equals: return "Equals";
			case IrOpcode::EscXAttr: return "EscXAttr";
			case IrOpcode::EscXElem: return "EscXElem";
			case IrOpcode::FindDef: return "FindDef";
			case IrOpcode::FindProperty: return "FindProperty";
			case IrOpcode::FindPropStrict: return "FindPropStrict";
			case IrOpcode::GetDescendants: return "GetDescendants";
			case IrOpcode::GetGlobalScope: return "GetGlobalScope";
			case IrOpcode::GetGlobalSlot: return "GetGlobalSlot";
			case IrOpcode::GetLocal: return "GetLocal";
			case IrOpcode::GetOuterScope: return "GetOuterScope";
			case IrOpcode::GetPropertyStatic: return "GetPropertyStatic";
			case IrOpcode::GetPropertyFast: return "GetPropertyFast";
			case IrOpcode::GetPropertySlow: return "GetPropertySlow";
			case IrOpcode::GetScopeObject: return "GetScopeObject";
			case IrOpcode::GetSlot: return "GetSlot";
			case IrOpcode::GetSuper: return "GetSuper";
			case IrOpcode::GreaterEquals: return "GreaterEquals";
			case IrOpcode::GreaterThan: return "GreaterThan";
			case IrOpcode::HasNext: return "HasNext";
			case IrOpcode::HasNext2: return "HasNext2";
			case IrOpcode::IfFalse: return "IfFalse";
			case IrOpcode::IfTrue: return "IfTrue";
			case IrOpcode::In: return "In";
			case IrOpcode::IncLocal: return "IncLocal";
			case IrOpcode::IncLocalI: return "IncLocalI";
			case IrOpcode::Increment: return "Increment";
			case IrOpcode::IncrementI: return "IncrementI";
			case IrOpcode::InitProperty: return "InitProperty";
			case IrOpcode::InstanceOf: return "InstanceOf";
			case IrOpcode::IsType: return "IsType";
			case IrOpcode::IsTypeLate: return "IsTypeLate";
			case IrOpcode::Jump: return "Jump";
			case IrOpcode::Kill: return "Kill";
			case IrOpcode::LessEquals: return "LessEquals";
			case IrOpcode::LessThan: return "LessThan";
			case IrOpcode::Lf32: return "Lf32";
			case IrOpcode::Lf64: return "Lf64";
			case IrOpcode::Li16: return "Li16";
			case IrOpcode::Li32: return "Li32";
			case IrOpcode::Li8: return "Li8";
			case IrOpcode::LookupSwitch: return "LookupSwitch";
			case IrOpcode::LShift: return "LShift";
			case IrOpcode::Modulo: return "Modulo";
			case IrOpcode::Multiply: return "Multiply";
			case IrOpcode::MultiplyI: return "MultiplyI";
			case IrOpcode::Negate: return "Negate";
			case IrOpcode::NegateI: return "NegateI";
			case IrOpcode::NewActivation: return "NewActivation";
			case IrOpcode::NewArray: return "NewArray";
			case IrOpcode::NewCatch: return "NewCatch";
			case IrOpcode::NewClass: return "NewClass";
			case IrOpcode::NewFunction: return "NewFunction";
			case IrOpcode::NewObject: return "NewObject";
			case IrOpcode::NextName: return "NextName";
			case IrOpcode::NextValue: return "NextValue";
			case IrOpcode::Nop: return "Nop";
			case IrOpcode::Not: return "Not";
			case IrOpcode::Pop: return "Pop";
			case IrOpcode::PopScope: return "PopScope";
			case IrOpcode::PushDouble: return "PushDouble";
			case IrOpcode::PushFalse: return "PushFalse";
			case IrOpcode::PushInt: return "PushInt";
			case IrOpcode::PushNamespace: return "PushNamespace";
			case IrOpcode::PushNaN: return "PushNaN";
			case IrOpcode::PushNull: return "PushNull";
			case IrOpcode::PushScope: return "PushScope";
			case IrOpcode::PushString: return "PushString";
			case IrOpcode::PushTrue: return "PushTrue";
			case IrOpcode::PushUint: return "PushUint";
			case IrOpcode::PushUndefined: return "PushUndefined";
			case IrOpcode::PushWith: return "PushWith";
			case IrOpcode::ReturnValue: return "ReturnValue";
			case IrOpcode::ReturnVoid: return "ReturnVoid";
			case IrOpcode::RShift: return "RShift";
			case IrOpcode::SetGlobalSlot: return "SetGlobalSlot";
			case IrOpcode::SetLocal: return "SetLocal";
			case IrOpcode::SetPropertyStatic: return "SetPropertyStatic";
			case IrOpcode::SetPropertyFast: return "SetPropertyFast";
			case IrOpcode::SetPropertySlow: return "SetPropertySlow";
			case IrOpcode::SetSlot: return "SetSlot";
			case IrOpcode::SetSuper: return "SetSuper";
			case IrOpcode::Sf32: return "Sf32";
			case IrOpcode::Sf64: return "Sf64";
			case IrOpcode::Si16: return "Si16";
			case IrOpcode::Si32: return "Si32";
			case IrOpcode::Si8: return "Si8";
			case IrOpcode::StrictEquals: return "StrictEquals";
			case IrOpcode::Subtract: return "Subtract";
			case IrOpcode::SubtractI: return "SubtractI";
			case IrOpcode::Swap: return "Swap";
			case IrOpcode::Sxi1: return "Sxi1";
			case IrOpcode::Sxi16: return "Sxi16";
			case IrOpcode::Sxi8: return "Sxi8";
			case IrOpcode::Throw: return "Throw";
			case IrOpcode::TypeOf: return "TypeOf";
			case IrOpcode::Timestamp: return "Timestamp";
			case IrOpcode::URShift: return "URShift";
			default: return "<unknown>";
		}
	}

	string formatIrOp(const AbcFile& abc, const IrOp& op)
	{
		string s = irOpcodeName(op.op);
		switch (op.op)
		{
			// multiname operand
			case IrOpcode::AsType: case IrOpcode::Coerce: case IrOpcode::IsType:
			case IrOpcode::DeleteProperty: case IrOpcode::FindDef:
			case IrOpcode::FindProperty: case IrOpcode::FindPropStrict:
			case IrOpcode::GetDescendants:
			case IrOpcode::GetPropertyStatic: case IrOpcode::GetPropertyFast:
			case IrOpcode::GetPropertySlow:
			case IrOpcode::SetPropertyStatic: case IrOpcode::SetPropertyFast:
			case IrOpcode::SetPropertySlow:
			case IrOpcode::InitProperty:
			case IrOpcode::GetSuper: case IrOpcode::SetSuper:
			{
				s += " mn[" + to_string(op.arg1) + "] " + multinameToString(abc, op.arg1);
				break;
			}

			// multiname + num_args
			case IrOpcode::CallProperty: case IrOpcode::CallPropLex:
			case IrOpcode::CallPropVoid: case IrOpcode::CallSuper:
			case IrOpcode::ConstructProp:
			{
				s += " mn[" + to_string(op.arg1) + "] " + multinameToString(abc, op.arg1)
				     + ", args=" + to_string(op.arg2);
				break;
			}

			case IrOpcode::CallStatic:
			{
				s += " method[" + to_string(op.arg1) + "] \""
				     + methodDisplayName(abc, op.arg1) + "\", args=" + to_string(op.arg2);
				break;
			}
			case IrOpcode::Call: case IrOpcode::Construct:
			case IrOpcode::ConstructSuper: case IrOpcode::NewArray:
			{
				s += " args=" + to_string(op.arg2);
				break;
			}
			case IrOpcode::NewObject:
			{
				s += " pairs=" + to_string(op.arg2);
				break;
			}
			case IrOpcode::ApplyType:
			{
				s += " types=" + to_string(op.arg2);
				break;
			}

			case IrOpcode::PushInt:
			{
				s += " " + to_string(op.imm);
				break;
			}
			case IrOpcode::PushUint:
			{
				s += " uint[" + to_string(op.arg1) + "]";
				if (op.arg1 < abc.pool.uints.size())
				{
					s += " " + to_string(abc.pool.uints[op.arg1]);
				}
				break;
			}
			case IrOpcode::PushDouble:
			{
				s += " dbl[" + to_string(op.arg1) + "]";
				if (op.arg1 < abc.pool.doubles.size())
				{
					char buf[40];
					snprintf(buf, sizeof(buf), " %g", abc.pool.doubles[op.arg1]);
					s += buf;
				}
				break;
			}
			case IrOpcode::PushString:
			{
				s += " str[" + to_string(op.arg1) + "] \"" + poolString(abc, op.arg1) + "\"";
				break;
			}
			case IrOpcode::PushNamespace:
			{
				s += " ns[" + to_string(op.arg1) + "] " + namespaceToString(abc, op.arg1);
				break;
			}

			case IrOpcode::GetLocal: case IrOpcode::SetLocal: case IrOpcode::Kill:
			case IrOpcode::IncLocal: case IrOpcode::IncLocalI:
			case IrOpcode::DecLocal: case IrOpcode::DecLocalI:
			{
				s += " r" + to_string(op.arg1);
				break;
			}
			case IrOpcode::HasNext2:
			{
				s += " obj=r" + to_string(op.arg1) + " idx=r" + to_string(op.arg2);
				break;
			}

			case IrOpcode::Jump: case IrOpcode::IfTrue: case IrOpcode::IfFalse:
			{
				s += " -> " + to_string(op.target);
				break;
			}
			case IrOpcode::LookupSwitch:
			{
				s += " default -> " + to_string(op.target) + ", cases -> [";
				for (size_t i = 0; i < op.switch_targets.size(); ++i)
				{
					if (i > 0)
					{
						s += ", ";
					}
					s += to_string(op.switch_targets[i]);
				}
				s += "]";
				break;
			}

			case IrOpcode::GetSlot: case IrOpcode::SetSlot:
			case IrOpcode::GetGlobalSlot: case IrOpcode::SetGlobalSlot:
			{
				s += " slot=" + to_string(op.arg1);
				break;
			}
			case IrOpcode::GetScopeObject: case IrOpcode::GetOuterScope:
			{
				s += " " + to_string(op.arg1);
				break;
			}

			case IrOpcode::NewFunction:
			{
				s += " method[" + to_string(op.arg1) + "] \""
				     + methodDisplayName(abc, op.arg1) + "\"";
				break;
			}
			case IrOpcode::NewClass:
			{
				s += " class[" + to_string(op.arg1) + "]";
				if (op.arg1 < abc.instances.size())
				{
					s += " " + multinameToString(abc, abc.instances[op.arg1].name);
				}
				break;
			}
			case IrOpcode::NewCatch:
			{
				s += " exception[" + to_string(op.arg1) + "]";
				break;
			}

			case IrOpcode::Debug:
			{
				s += string(" is_local=") + (op.bool_arg ? "1" : "0")
				     + " name=\"" + poolString(abc, op.arg1)
				     + "\" reg=" + to_string(op.byte_arg);
				break;
			}
			case IrOpcode::DebugFile:
			{
				s += " \"" + poolString(abc, op.arg1) + "\"";
				break;
			}
			case IrOpcode::DebugLine: case IrOpcode::BkptLine:
			{
				s += " line=" + to_string(op.arg1);
				break;
			}
			case IrOpcode::Dxns:
			{
				s += " \"" + poolString(abc, op.arg1) + "\"";
				break;
			}

			default: break;
		}
		return s;
	}

	static void dumpTraits(const AbcFile& abc, const std::vector<AbcTrait>& traits,
	                       const string& indent, ostream& out)
	{
		for (const AbcTrait& t : traits)
		{
			out << indent;
			switch (t.kind)
			{
				case TraitKindType::Slot:
				case TraitKindType::Const:
				{
					out << (t.kind == TraitKindType::Slot ? "slot " : "const ")
					    << multinameToString(abc, t.name)
					    << " : " << multinameToString(abc, t.type_name)
					    << " (slot_id " << t.slot_or_disp_id << ")";
					if (t.value.present)
					{
						out << " = " << defaultValueToString(abc, t.value);
					}
					break;
				}
				case TraitKindType::Method:
				case TraitKindType::Getter:
				case TraitKindType::Setter:
				{
					const char* kind = t.kind == TraitKindType::Method ? "method"
					                 : t.kind == TraitKindType::Getter ? "getter" : "setter";
					out << kind << " " << multinameToString(abc, t.name)
					    << " -> method[" << t.method_or_class << "]"
					    << " (disp_id " << t.slot_or_disp_id << ")";
					break;
				}
				case TraitKindType::Class:
				{
					out << "class " << multinameToString(abc, t.name)
					    << " -> class[" << t.method_or_class << "]"
					    << " (slot_id " << t.slot_or_disp_id << ")";
					break;
				}
				case TraitKindType::Function:
				{
					out << "function " << multinameToString(abc, t.name)
					    << " -> method[" << t.method_or_class << "]"
					    << " (slot_id " << t.slot_or_disp_id << ")";
					break;
				}
			}
			if (t.is_final)
			{
				out << " final";
			}
			if (t.is_override)
			{
				out << " override";
			}
			if (!t.metadata.empty())
			{
				out << " [metadata:";
				for (u32 md : t.metadata)
				{
					if (md < abc.metadata.size())
					{
						out << " " << poolString(abc, abc.metadata[md].name);
					}
				}
				out << "]";
			}
			out << endl;
		}
	}

	int dumpAbc(const AbcFile& abc, ostream& out)
	{
		const ConstantPool& pool = abc.pool;

		out << "ABC version " << abc.major_version << "." << abc.minor_version << endl;
		out << "Constant pool: "
		    << pool.ints.size() - 1 << " ints, "
		    << pool.uints.size() - 1 << " uints, "
		    << pool.doubles.size() - 1 << " doubles, "
		    << pool.strings.size() - 1 << " strings, "
		    << pool.namespaces.size() - 1 << " namespaces, "
		    << pool.ns_sets.size() - 1 << " ns-sets, "
		    << pool.multinames.size() - 1 << " multinames" << endl;

		for (size_t i = 1; i < pool.ints.size(); ++i)
		{
			out << "  int[" << i << "] = " << pool.ints[i] << endl;
		}
		for (size_t i = 1; i < pool.uints.size(); ++i)
		{
			out << "  uint[" << i << "] = " << pool.uints[i] << endl;
		}
		for (size_t i = 1; i < pool.doubles.size(); ++i)
		{
			char buf[40];
			snprintf(buf, sizeof(buf), "%g", pool.doubles[i]);
			out << "  double[" << i << "] = " << buf << endl;
		}
		for (size_t i = 1; i < pool.strings.size(); ++i)
		{
			out << "  string[" << i << "] = \"" << displayString(pool.strings[i]) << "\"" << endl;
		}
		for (size_t i = 1; i < pool.namespaces.size(); ++i)
		{
			out << "  namespace[" << i << "] = " << namespaceToString(abc, (u32) i) << endl;
		}
		for (size_t i = 1; i < pool.ns_sets.size(); ++i)
		{
			out << "  ns-set[" << i << "] = {";
			for (size_t k = 0; k < pool.ns_sets[i].size(); ++k)
			{
				if (k > 0)
				{
					out << ", ";
				}
				out << namespaceToString(abc, pool.ns_sets[i][k]);
			}
			out << "}" << endl;
		}
		for (size_t i = 1; i < pool.multinames.size(); ++i)
		{
			out << "  multiname[" << i << "] = " << multinameToString(abc, (u32) i) << endl;
		}

		out << endl << "Classes (" << abc.instances.size() << "):" << endl;
		for (size_t i = 0; i < abc.instances.size(); ++i)
		{
			const AbcInstance& inst = abc.instances[i];
			out << "  class[" << i << "] " << multinameToString(abc, inst.name);
			if (inst.super_name != 0)
			{
				out << " extends " << multinameToString(abc, inst.super_name);
			}
			if (inst.is_interface)
			{
				out << " (interface)";
			}
			if (inst.is_sealed)
			{
				out << " sealed";
			}
			if (inst.is_final)
			{
				out << " final";
			}
			out << endl;
			if (!inst.interfaces.empty())
			{
				out << "    implements:";
				for (u32 iface : inst.interfaces)
				{
					out << " " << multinameToString(abc, iface);
				}
				out << endl;
			}
			out << "    instance init: method[" << inst.init_method << "]"
			    << ", class init: method[" << abc.classes[i].init_method << "]" << endl;
			if (!inst.traits.empty())
			{
				out << "    instance traits:" << endl;
				dumpTraits(abc, inst.traits, "      ", out);
			}
			if (!abc.classes[i].traits.empty())
			{
				out << "    class traits:" << endl;
				dumpTraits(abc, abc.classes[i].traits, "      ", out);
			}
		}

		out << endl << "Scripts (" << abc.scripts.size() << "):" << endl;
		for (size_t i = 0; i < abc.scripts.size(); ++i)
		{
			out << "  script[" << i << "] init: method[" << abc.scripts[i].init_method << "]" << endl;
			dumpTraits(abc, abc.scripts[i].traits, "    ", out);
		}

		out << endl << "Methods (" << abc.methods.size() << ", "
		    << abc.method_bodies.size() << " bodies):" << endl;

		int verify_failures = 0;
		for (size_t i = 0; i < abc.methods.size(); ++i)
		{
			const AbcMethod& m = abc.methods[i];
			out << "  method[" << i << "] \"" << methodDisplayName(abc, (u32) i) << "\"(";
			for (size_t p = 0; p < m.params.size(); ++p)
			{
				if (p > 0)
				{
					out << ", ";
				}
				out << multinameToString(abc, m.params[p].type);
				if (m.params[p].default_value.present)
				{
					out << " = " << defaultValueToString(abc, m.params[p].default_value);
				}
			}
			out << ") : " << multinameToString(abc, m.return_type);
			if (m.flags & METHOD_NEED_ARGUMENTS) out << " need_arguments";
			if (m.flags & METHOD_NEED_ACTIVATION) out << " need_activation";
			if (m.flags & METHOD_NEED_REST) out << " need_rest";
			if (m.flags & METHOD_NATIVE) out << " native";
			if (m.flags & METHOD_SET_DXNS) out << " set_dxns";
			out << endl;

			if (m.body < 0)
			{
				out << "    (no body)" << endl;
				continue;
			}

			const AbcMethodBody& body = abc.method_bodies[m.body];
			out << "    body[" << m.body << "]: max_stack=" << body.max_stack
			    << " locals=" << body.num_locals
			    << " scope=" << body.init_scope_depth << ".." << body.max_scope_depth
			    << " code_len=" << body.code.size() << endl;
			if (!body.traits.empty())
			{
				out << "    activation traits:" << endl;
				dumpTraits(abc, body.traits, "      ", out);
			}

			IrMethod ir;
			VerifyError err;
			if (!verifyMethodBody(abc, (u32) m.body, ir, err))
			{
				out << "    VERIFY ERROR " << err.code << ": " << err.message << endl;
				verify_failures += 1;
				// Ops translated before the failure point (if any) still help
				// debugging — print whatever was built.
				if (!ir.ops.empty())
				{
					out << "    partial IR (" << ir.ops.size() << " ops):" << endl;
					for (size_t k = 0; k < ir.ops.size(); ++k)
					{
						out << "      " << k << ": " << formatIrOp(abc, ir.ops[k]) << endl;
					}
					for (size_t k = 0; k < ir.exceptions.size(); ++k)
					{
						const IrException& e = ir.exceptions[k];
						out << "      exc[" << k << "] ";
						if (e.active)
						{
							out << "ops " << e.from_op << ".." << e.to_op
							    << " -> " << e.target_op;
						}
						else
						{
							out << "(inactive)";
						}
						out << endl;
					}
				}
				continue;
			}

			out << "    IR (" << ir.ops.size() << " ops, computed max stack "
			    << ir.computed_max_stack << ", max local scope "
			    << ir.computed_max_scope << "):" << endl;
			for (size_t k = 0; k < ir.ops.size(); ++k)
			{
				out << "      " << k << ": " << formatIrOp(abc, ir.ops[k]) << endl;
			}
			if (!ir.exceptions.empty())
			{
				out << "    exceptions:" << endl;
				for (size_t k = 0; k < ir.exceptions.size(); ++k)
				{
					const IrException& e = ir.exceptions[k];
					out << "      [" << k << "] ";
					if (e.active)
					{
						out << "ops " << e.from_op << ".." << e.to_op
						    << " -> " << e.target_op;
					}
					else
					{
						out << "(inactive)";
					}
					out << " type=" << multinameToString(abc, e.type_name)
					    << " var=" << multinameToString(abc, e.variable_name) << endl;
				}
			}
		}

		return verify_failures;
	}
}
}
