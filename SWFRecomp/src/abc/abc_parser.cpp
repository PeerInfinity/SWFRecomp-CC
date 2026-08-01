#include <abc/abc_parser.hpp>

#include <cstdio>
#include <cstring>

using std::string;

namespace SWFRecomp
{
namespace abc
{
	// === AbcReader ===

	u8 AbcReader::readU8()
	{
		if (pos_ >= len_)
		{
			throw AbcError("unexpected end of ABC data", true);
		}
		return data_[pos_++];
	}

	u16 AbcReader::readU16()
	{
		u16 lo = readU8();
		u16 hi = readU8();
		return (u16) (lo | (hi << 8));
	}

	u32 AbcReader::readU30()
	{
		u32 val = 0;
		for (int i = 0; i < 35; i += 7)
		{
			u32 byte = readU8();
			// At i == 28 the shift discards the byte's high 3 data bits,
			// keeping only the low 4 — matching Ruffle/avmplus.
			val |= (u32) ((byte & 0x7f) << i);
			if ((byte & 0x80) == 0)
			{
				break;
			}
		}
		return val;
	}

	s32 AbcReader::readS32()
	{
		// Same encoding as u30, reinterpreted. NOT sign-extended for short
		// encodings — negatives must occupy the full 5 bytes (read.rs tests).
		return (s32) readU30();
	}

	s32 AbcReader::readS24()
	{
		s32 b0 = readU8();
		s32 b1 = readU8();
		s32 b2 = (s32) (int8_t) readU8();  // sign-extend the top byte
		return b0 | (b1 << 8) | (b2 << 16);
	}

	double AbcReader::readD64()
	{
		if (pos_ + 8 > len_)
		{
			throw AbcError("unexpected end of ABC data in double", true);
		}
		double val;
		memcpy(&val, &data_[pos_], 8);
		pos_ += 8;
		return val;
	}

	string AbcReader::readString()
	{
		u32 len = readU30();
		if (pos_ + len > len_)
		{
			throw AbcError("unexpected end of ABC data in string", true);
		}
		string s((const char*) &data_[pos_], len);
		pos_ += len;
		return s;
	}

	void AbcReader::skip(size_t n)
	{
		if (pos_ + n > len_)
		{
			throw AbcError("unexpected end of ABC data in skip", true);
		}
		pos_ += n;
	}

	// === constant pool ===

	static AbcNamespace readNamespace(AbcReader& r)
	{
		u8 kind = r.readU8();
		u32 name = r.readU30();
		switch (kind)
		{
			case 0x05:
			case 0x08:
			case 0x16:
			case 0x17:
			case 0x18:
			case 0x19:
			case 0x1a:
			{
				AbcNamespace ns;
				ns.kind = (NamespaceKind) kind;
				ns.name = name;
				return ns;
			}
			default:
			{
				throw AbcError("invalid namespace kind " + std::to_string(kind));
			}
		}
	}

	static NamespaceSet readNamespaceSet(AbcReader& r)
	{
		u32 len = r.readU30();
		NamespaceSet set;
		set.reserve(len < 4096 ? len : 4096);
		for (u32 i = 0; i < len; ++i)
		{
			set.push_back(r.readU30());
		}
		return set;
	}

	static AbcMultiname readMultiname(AbcReader& r)
	{
		AbcMultiname mn;
		u8 kind = r.readU8();
		switch (kind)
		{
			case 0x07:  // QName
			case 0x0d:  // QNameA
			{
				mn.kind = (MultinameKind) kind;
				mn.ns = r.readU30();
				mn.name = r.readU30();
				break;
			}
			case 0x0f:  // RTQName
			case 0x10:  // RTQNameA
			{
				mn.kind = (MultinameKind) kind;
				mn.name = r.readU30();
				break;
			}
			case 0x11:  // RTQNameL
			case 0x12:  // RTQNameLA
			{
				mn.kind = (MultinameKind) kind;
				break;
			}
			case 0x09:  // Multiname
			case 0x0e:  // MultinameA
			{
				mn.kind = (MultinameKind) kind;
				mn.name = r.readU30();
				mn.ns_set = r.readU30();
				break;
			}
			case 0x1b:  // MultinameL
			case 0x1c:  // MultinameLA
			{
				mn.kind = (MultinameKind) kind;
				mn.ns_set = r.readU30();
				break;
			}
			case 0x1d:  // TypeName (e.g. Vector.<int>)
			{
				mn.kind = MultinameKind::TypeName;
				mn.base_type = r.readU30();
				u32 count = r.readU30();
				mn.type_params.reserve(count < 4096 ? count : 4096);
				for (u32 i = 0; i < count; ++i)
				{
					mn.type_params.push_back(r.readU30());
				}
				break;
			}
			default:
			{
				throw AbcError("invalid multiname kind " + std::to_string(kind));
			}
		}
		return mn;
	}

	// avmplus names a method in its verify errors as `Class/member()` (the
	// declaring trait, not the method_info's own name — ASC leaves those
	// empty). Static members read `Class$/member()`; a class/instance
	// initializer reads just `Class()`.
	static std::string qnameLocalName(const ConstantPool& pool, u32 mn_index)
	{
		if (mn_index == 0 || mn_index >= pool.multinames.size()) return "";
		u32 s_index = pool.multinames[mn_index].name;
		if (s_index == 0 || s_index >= pool.strings.size()) return "";
		return pool.strings[s_index];
	}

	static bool traitNamesMethod(const AbcTrait& t, u32 method_index)
	{
		return (t.kind == TraitKindType::Method || t.kind == TraitKindType::Getter
		        || t.kind == TraitKindType::Setter
		        || t.kind == TraitKindType::Function)
		    && t.method_or_class == method_index;
	}

	static std::string methodDisplayName(const AbcFile& out, u32 method_index)
	{
		for (size_t i = 0; i < out.instances.size(); ++i)
		{
			const AbcInstance& inst = out.instances[i];
			std::string cls = qnameLocalName(out.pool, inst.name);
			for (size_t ti = 0; ti < inst.traits.size(); ++ti)
			{
				if (traitNamesMethod(inst.traits[ti], method_index))
				{
					return cls + "/"
					     + qnameLocalName(out.pool, inst.traits[ti].name) + "()";
				}
			}
			if (inst.init_method == method_index) return cls + "()";
			if (i < out.classes.size())
			{
				const AbcClass& cd = out.classes[i];
				for (size_t ti = 0; ti < cd.traits.size(); ++ti)
				{
					if (traitNamesMethod(cd.traits[ti], method_index))
					{
						return cls + "$/"
						     + qnameLocalName(out.pool, cd.traits[ti].name) + "()";
					}
				}
				if (cd.init_method == method_index) return cls + "$()";
			}
		}
		return "method_info " + std::to_string(method_index);
	}

	static void readConstantPool(AbcReader& r, ConstantPool& pool)
	{
		// Each count includes the implicit entry 0; a count of 0 or 1 means
		// no explicit entries. We store a synthetic entry 0 so raw indices
		// address the vectors directly.
		u32 len;

		len = r.readU30();
		pool.ints.push_back(0);
		for (u32 i = 1; i < len; ++i)
		{
			pool.ints.push_back(r.readS32());
		}

		len = r.readU30();
		pool.uints.push_back(0);
		for (u32 i = 1; i < len; ++i)
		{
			pool.uints.push_back(r.readU30());
		}

		len = r.readU30();
		pool.doubles.push_back(0.0);
		for (u32 i = 1; i < len; ++i)
		{
			pool.doubles.push_back(r.readD64());
		}

		len = r.readU30();
		pool.strings.push_back(string());
		for (u32 i = 1; i < len; ++i)
		{
			pool.strings.push_back(r.readString());
		}

		len = r.readU30();
		pool.namespaces.push_back(AbcNamespace());  // entry 0 = "any"
		for (u32 i = 1; i < len; ++i)
		{
			pool.namespaces.push_back(readNamespace(r));
		}

		len = r.readU30();
		pool.ns_sets.push_back(NamespaceSet());
		for (u32 i = 1; i < len; ++i)
		{
			pool.ns_sets.push_back(readNamespaceSet(r));
		}

		len = r.readU30();
		pool.multinames.push_back(AbcMultiname());  // entry 0 = "any name"
		for (u32 i = 1; i < len; ++i)
		{
			pool.multinames.push_back(readMultiname(r));
		}
	}

	// === methods / metadata / classes / scripts / bodies ===

	static DefaultValue readConstantValue(AbcReader& r)
	{
		// Used for optional-parameter defaults: index and kind are both
		// always present (unlike trait slot values).
		DefaultValue v;
		v.present = true;
		v.index = r.readU30();
		u8 kind = r.readU8();
		switch (kind)
		{
			case 0x00: case 0x01: case 0x03: case 0x04: case 0x05:
			case 0x06: case 0x08: case 0x0a: case 0x0b: case 0x0c:
			case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
			{
				v.kind = (DefaultValueKind) kind;
				break;
			}
			default:
			{
				throw AbcError("invalid default value kind " + std::to_string(kind));
			}
		}
		return v;
	}

	static DefaultValue readOptionalValue(AbcReader& r)
	{
		// Used for trait slot/const values: if the index is 0, the kind byte
		// is NOT present in the stream.
		DefaultValue v;
		v.index = r.readU30();
		if (v.index == 0)
		{
			return v;
		}
		v.present = true;
		u8 kind = r.readU8();
		switch (kind)
		{
			case 0x00: case 0x01: case 0x03: case 0x04: case 0x05:
			case 0x06: case 0x08: case 0x0a: case 0x0b: case 0x0c:
			case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
			{
				v.kind = (DefaultValueKind) kind;
				break;
			}
			default:
			{
				throw AbcError("invalid slot value kind " + std::to_string(kind));
			}
		}
		return v;
	}

	static AbcMethod readMethod(AbcReader& r)
	{
		AbcMethod m;
		u32 num_params = r.readU30();
		m.return_type = r.readU30();
		m.params.reserve(num_params < 4096 ? num_params : 4096);
		for (u32 i = 0; i < num_params; ++i)
		{
			MethodParam p;
			p.type = r.readU30();
			m.params.push_back(p);
		}
		m.name = r.readU30();
		m.flags = r.readU8();

		if (m.flags & METHOD_HAS_OPTIONAL)
		{
			u32 num_optional = r.readU30();
			if (num_optional > m.params.size())
			{
				throw AbcError("too many optional parameters");
			}
			for (size_t i = m.params.size() - num_optional; i < m.params.size(); ++i)
			{
				m.params[i].default_value = readConstantValue(r);
			}
		}

		if (m.flags & METHOD_HAS_PARAM_NAMES)
		{
			for (size_t i = 0; i < m.params.size(); ++i)
			{
				m.params[i].name = r.readU30();
			}
		}

		return m;
	}

	static AbcMetadata readMetadata(AbcReader& r)
	{
		AbcMetadata md;
		md.name = r.readU30();
		u32 num_items = r.readU30();
		// The stream stores all keys, then all values.
		std::vector<u32> kv;
		kv.reserve(num_items < 4096 ? num_items * 2 : 8192);
		for (u32 i = 0; i < num_items * 2; ++i)
		{
			kv.push_back(r.readU30());
		}
		md.items.reserve(num_items < 4096 ? num_items : 4096);
		for (u32 i = 0; i < num_items; ++i)
		{
			MetadataItem item;
			item.key = kv[i];
			item.value = kv[num_items + i];
			md.items.push_back(item);
		}
		return md;
	}

	static AbcTrait readTrait(AbcReader& r)
	{
		AbcTrait t;
		t.name = r.readU30();
		u8 flags = r.readU8();
		u8 kind = flags & 0x0f;
		t.is_final = (flags & 0x10) != 0;
		t.is_override = (flags & 0x20) != 0;

		switch (kind)
		{
			case 0:  // Slot
			case 6:  // Const
			{
				t.kind = (kind == 0) ? TraitKindType::Slot : TraitKindType::Const;
				t.slot_or_disp_id = r.readU30();
				t.type_name = r.readU30();
				t.value = readOptionalValue(r);
				break;
			}
			case 1:  // Method
			case 2:  // Getter
			case 3:  // Setter
			{
				t.kind = (TraitKindType) kind;
				t.slot_or_disp_id = r.readU30();
				t.method_or_class = r.readU30();
				break;
			}
			case 4:  // Class
			{
				t.kind = TraitKindType::Class;
				t.slot_or_disp_id = r.readU30();
				t.method_or_class = r.readU30();
				break;
			}
			case 5:  // Function
			{
				t.kind = TraitKindType::Function;
				t.slot_or_disp_id = r.readU30();
				t.method_or_class = r.readU30();
				break;
			}
			default:
			{
				throw AbcError("invalid trait kind " + std::to_string(kind));
			}
		}

		if (flags & 0x40)  // ATTR_Metadata
		{
			u32 num_metadata = r.readU30();
			t.metadata.reserve(num_metadata < 4096 ? num_metadata : 4096);
			for (u32 i = 0; i < num_metadata; ++i)
			{
				t.metadata.push_back(r.readU30());
			}
		}

		return t;
	}

	static void readTraits(AbcReader& r, std::vector<AbcTrait>& out)
	{
		u32 num_traits = r.readU30();
		out.reserve(num_traits < 4096 ? num_traits : 4096);
		for (u32 i = 0; i < num_traits; ++i)
		{
			out.push_back(readTrait(r));
		}
	}

	static AbcInstance readInstance(AbcReader& r)
	{
		AbcInstance inst;
		inst.name = r.readU30();
		inst.super_name = r.readU30();
		u8 flags = r.readU8();
		inst.is_sealed = (flags & 0x01) != 0;
		inst.is_final = (flags & 0x02) != 0;
		inst.is_interface = (flags & 0x04) != 0;

		if (flags & 0x08)  // ClassProtectedNs
		{
			inst.has_protected_ns = true;
			inst.protected_ns = r.readU30();
		}

		u32 num_interfaces = r.readU30();
		inst.interfaces.reserve(num_interfaces < 4096 ? num_interfaces : 4096);
		for (u32 i = 0; i < num_interfaces; ++i)
		{
			inst.interfaces.push_back(r.readU30());
		}

		inst.init_method = r.readU30();
		readTraits(r, inst.traits);
		return inst;
	}

	static AbcMethodBody readMethodBody(AbcReader& r)
	{
		AbcMethodBody body;
		body.method = r.readU30();
		body.max_stack = r.readU30();
		body.num_locals = r.readU30();
		body.init_scope_depth = r.readU30();
		body.max_scope_depth = r.readU30();

		u32 code_len = r.readU30();
		if (r.pos() + code_len > r.size())
		{
			throw AbcError("unexpected end of ABC data in method body code", true);
		}
		body.code.resize(code_len);
		for (u32 i = 0; i < code_len; ++i)
		{
			body.code[i] = r.readU8();
		}

		u32 num_exceptions = r.readU30();
		body.exceptions.reserve(num_exceptions < 4096 ? num_exceptions : 4096);
		for (u32 i = 0; i < num_exceptions; ++i)
		{
			AbcException e;
			e.from_offset = r.readU30();
			e.to_offset = r.readU30();
			e.target_offset = r.readU30();
			e.type_name = r.readU30();
			e.variable_name = r.readU30();
			body.exceptions.push_back(e);
		}

		readTraits(r, body.traits);
		return body;
	}

	void parseAbcFile(AbcReader& r, AbcFile& out)
	{
		out.minor_version = r.readU16();
		out.major_version = r.readU16();
		readConstantPool(r, out.pool);

		u32 len = r.readU30();
		out.methods.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			out.methods.push_back(readMethod(r));
		}

		len = r.readU30();
		out.metadata.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			out.metadata.push_back(readMetadata(r));
		}

		// One count covers both the instance and class arrays.
		len = r.readU30();
		out.instances.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			out.instances.push_back(readInstance(r));
		}
		out.classes.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			AbcClass cls;
			cls.init_method = r.readU30();
			readTraits(r, cls.traits);
			out.classes.push_back(cls);
		}

		len = r.readU30();
		out.scripts.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			AbcScript script;
			script.init_method = r.readU30();
			readTraits(r, script.traits);
			out.scripts.push_back(script);
		}

		len = r.readU30();
		out.method_bodies.reserve(len < 65536 ? len : 65536);
		for (u32 i = 0; i < len; ++i)
		{
			AbcMethodBody body = readMethodBody(r);
			if (body.method >= out.methods.size())
			{
				// FP rejects the whole ABC with a catchable #1027 at load.
				throw AbcError("method body references out-of-range method "
				               + std::to_string(body.method),
				               1027,
				               "Method_info " + std::to_string(body.method)
				               + " exceeds method_count="
				               + std::to_string(out.methods.size()) + ".");
			}
			if (out.methods[body.method].body >= 0)
			{
				// FP throws error 1121 here.
				throw AbcError("duplicate method body for method "
				               + std::to_string(body.method),
				               1121,
				               "Method " + methodDisplayName(out, body.method)
				               + " has a duplicate method body.");
			}
			out.methods[body.method].body = (s32) i;
			out.method_bodies.push_back(body);
		}
	}

	bool parseAbc(const u8* data, size_t len, AbcFile& out, string& error,
	              AbcLoadError* player)
	{
		try
		{
			AbcReader r(data, len);
			parseAbcFile(r, out);
			return true;
		}
		catch (const AbcError& e)
		{
			error = e.what();
			if (player != nullptr)
			{
				// avmplus's blanket answer for an ABC it cannot read.
				player->code = e.player_code != 0 ? e.player_code : 1107;
				player->message = "Error #" + std::to_string(player->code) + ": "
				                + (e.player_code != 0
				                   ? e.player_text
				                   : string("The ABC data is corrupt, attempt to "
				                            "read out of bounds."));
			}
			return false;
		}
	}

	// === raw op reader ===

	RawOp readOp(AbcReader& r)
	{
		RawOp op;
		op.code_offset = (u32) r.pos();
		u8 byte = r.readU8();
		op.opcode = (AbcOpcode) byte;

		switch (op.opcode)
		{
			// No operands
			case AbcOpcode::Bkpt:
			case AbcOpcode::Nop:
			case AbcOpcode::Throw:
			case AbcOpcode::DxnsLate:
			case AbcOpcode::Label:
			case AbcOpcode::PushWith:
			case AbcOpcode::PopScope:
			case AbcOpcode::NextName:
			case AbcOpcode::HasNext:
			case AbcOpcode::PushNull:
			case AbcOpcode::PushUndefined:
			case AbcOpcode::NextValue:
			case AbcOpcode::PushTrue:
			case AbcOpcode::PushFalse:
			case AbcOpcode::PushNaN:
			case AbcOpcode::Pop:
			case AbcOpcode::Dup:
			case AbcOpcode::Swap:
			case AbcOpcode::PushScope:
			case AbcOpcode::Li8:
			case AbcOpcode::Li16:
			case AbcOpcode::Li32:
			case AbcOpcode::Lf32:
			case AbcOpcode::Lf64:
			case AbcOpcode::Si8:
			case AbcOpcode::Si16:
			case AbcOpcode::Si32:
			case AbcOpcode::Sf32:
			case AbcOpcode::Sf64:
			case AbcOpcode::ReturnVoid:
			case AbcOpcode::ReturnValue:
			case AbcOpcode::Sxi1:
			case AbcOpcode::Sxi8:
			case AbcOpcode::Sxi16:
			case AbcOpcode::NewActivation:
			case AbcOpcode::GetGlobalScope:
			case AbcOpcode::ConvertS:
			case AbcOpcode::EscXElem:
			case AbcOpcode::EscXAttr:
			case AbcOpcode::ConvertI:
			case AbcOpcode::ConvertU:
			case AbcOpcode::ConvertD:
			case AbcOpcode::ConvertB:
			case AbcOpcode::ConvertO:
			case AbcOpcode::CheckFilter:
			case AbcOpcode::CoerceB:
			case AbcOpcode::CoerceA:
			case AbcOpcode::CoerceI:
			case AbcOpcode::CoerceD:
			case AbcOpcode::CoerceS:
			case AbcOpcode::AsTypeLate:
			case AbcOpcode::CoerceU:
			case AbcOpcode::CoerceO:
			case AbcOpcode::Negate:
			case AbcOpcode::Increment:
			case AbcOpcode::Decrement:
			case AbcOpcode::TypeOf:
			case AbcOpcode::Not:
			case AbcOpcode::BitNot:
			case AbcOpcode::Add:
			case AbcOpcode::Subtract:
			case AbcOpcode::Multiply:
			case AbcOpcode::Divide:
			case AbcOpcode::Modulo:
			case AbcOpcode::LShift:
			case AbcOpcode::RShift:
			case AbcOpcode::URShift:
			case AbcOpcode::BitAnd:
			case AbcOpcode::BitOr:
			case AbcOpcode::BitXor:
			case AbcOpcode::Equals:
			case AbcOpcode::StrictEquals:
			case AbcOpcode::LessThan:
			case AbcOpcode::LessEquals:
			case AbcOpcode::GreaterThan:
			case AbcOpcode::GreaterEquals:
			case AbcOpcode::InstanceOf:
			case AbcOpcode::IsTypeLate:
			case AbcOpcode::In:
			case AbcOpcode::IncrementI:
			case AbcOpcode::DecrementI:
			case AbcOpcode::NegateI:
			case AbcOpcode::AddI:
			case AbcOpcode::SubtractI:
			case AbcOpcode::MultiplyI:
			case AbcOpcode::GetLocal0:
			case AbcOpcode::GetLocal1:
			case AbcOpcode::GetLocal2:
			case AbcOpcode::GetLocal3:
			case AbcOpcode::SetLocal0:
			case AbcOpcode::SetLocal1:
			case AbcOpcode::SetLocal2:
			case AbcOpcode::SetLocal3:
			case AbcOpcode::Timestamp:
			{
				break;
			}

			// One u30 operand
			case AbcOpcode::GetSuper:
			case AbcOpcode::SetSuper:
			case AbcOpcode::Dxns:
			case AbcOpcode::Kill:
			case AbcOpcode::PushString:
			case AbcOpcode::PushInt:
			case AbcOpcode::PushUint:
			case AbcOpcode::PushDouble:
			case AbcOpcode::PushNamespace:
			case AbcOpcode::NewFunction:
			case AbcOpcode::Call:
			case AbcOpcode::Construct:
			case AbcOpcode::ConstructSuper:
			case AbcOpcode::ApplyType:
			case AbcOpcode::NewObject:
			case AbcOpcode::NewArray:
			case AbcOpcode::NewClass:
			case AbcOpcode::GetDescendants:
			case AbcOpcode::NewCatch:
			case AbcOpcode::FindPropStrict:
			case AbcOpcode::FindProperty:
			case AbcOpcode::FindDef:
			case AbcOpcode::GetLex:
			case AbcOpcode::SetProperty:
			case AbcOpcode::GetLocal:
			case AbcOpcode::SetLocal:
			case AbcOpcode::GetProperty:
			case AbcOpcode::GetOuterScope:
			case AbcOpcode::InitProperty:
			case AbcOpcode::DeleteProperty:
			case AbcOpcode::GetSlot:
			case AbcOpcode::SetSlot:
			case AbcOpcode::GetGlobalSlot:
			case AbcOpcode::SetGlobalSlot:
			case AbcOpcode::Coerce:
			case AbcOpcode::AsType:
			case AbcOpcode::IncLocal:
			case AbcOpcode::DecLocal:
			case AbcOpcode::IsType:
			case AbcOpcode::IncLocalI:
			case AbcOpcode::DecLocalI:
			case AbcOpcode::DebugLine:
			case AbcOpcode::DebugFile:
			case AbcOpcode::BkptLine:
			{
				op.arg1 = r.readU30();
				break;
			}

			// Two u30 operands
			case AbcOpcode::CallMethod:
			case AbcOpcode::CallStatic:
			case AbcOpcode::CallSuper:
			case AbcOpcode::CallProperty:
			case AbcOpcode::ConstructProp:
			case AbcOpcode::CallPropLex:
			case AbcOpcode::CallSuperVoid:
			case AbcOpcode::CallPropVoid:
			case AbcOpcode::HasNext2:
			{
				op.arg1 = r.readU30();
				op.arg2 = r.readU30();
				break;
			}

			// Branches: one s24 offset
			case AbcOpcode::IfNlt:
			case AbcOpcode::IfNle:
			case AbcOpcode::IfNgt:
			case AbcOpcode::IfNge:
			case AbcOpcode::Jump:
			case AbcOpcode::IfTrue:
			case AbcOpcode::IfFalse:
			case AbcOpcode::IfEq:
			case AbcOpcode::IfNe:
			case AbcOpcode::IfLt:
			case AbcOpcode::IfLe:
			case AbcOpcode::IfGt:
			case AbcOpcode::IfGe:
			case AbcOpcode::IfStrictEq:
			case AbcOpcode::IfStrictNe:
			{
				op.offset = r.readS24();
				break;
			}

			case AbcOpcode::LookupSwitch:
			{
				op.offset = r.readS24();  // default offset
				u32 num_cases = r.readU30() + 1;
				op.case_offsets.reserve(num_cases < 65536 ? num_cases : 65536);
				for (u32 i = 0; i < num_cases; ++i)
				{
					op.case_offsets.push_back(r.readS24());
				}
				break;
			}

			case AbcOpcode::PushByte:
			{
				op.byte_arg = r.readU8();
				break;
			}

			case AbcOpcode::PushShort:
			{
				op.arg1 = r.readU30();
				break;
			}

			case AbcOpcode::GetScopeObject:
			{
				op.byte_arg = r.readU8();
				break;
			}

			case AbcOpcode::Debug:
			{
				op.bool_arg = r.readU8() != 0;
				op.arg1 = r.readU30();  // register name (string pool index)
				op.byte_arg = r.readU8();
				r.readU30();  // unused extra operand
				break;
			}

			default:
			{
				char buf[40];
				snprintf(buf, sizeof(buf), "unknown ABC opcode 0x%02x", byte);
				throw AbcError(buf);
			}
		}

		// Fold the shorthand local ops into GetLocal/SetLocal { index },
		// like Ruffle's read_op does.
		switch (op.opcode)
		{
			case AbcOpcode::GetLocal0: op.opcode = AbcOpcode::GetLocal; op.arg1 = 0; break;
			case AbcOpcode::GetLocal1: op.opcode = AbcOpcode::GetLocal; op.arg1 = 1; break;
			case AbcOpcode::GetLocal2: op.opcode = AbcOpcode::GetLocal; op.arg1 = 2; break;
			case AbcOpcode::GetLocal3: op.opcode = AbcOpcode::GetLocal; op.arg1 = 3; break;
			case AbcOpcode::SetLocal0: op.opcode = AbcOpcode::SetLocal; op.arg1 = 0; break;
			case AbcOpcode::SetLocal1: op.opcode = AbcOpcode::SetLocal; op.arg1 = 1; break;
			case AbcOpcode::SetLocal2: op.opcode = AbcOpcode::SetLocal; op.arg1 = 2; break;
			case AbcOpcode::SetLocal3: op.opcode = AbcOpcode::SetLocal; op.arg1 = 3; break;
			default: break;
		}

		return op;
	}
}
}
