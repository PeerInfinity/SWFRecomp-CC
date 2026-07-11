#pragma once

// Raw ABC (ActionScript Byte Code) data structures, produced by the parser in
// src/abc/abc_parser.cpp. Layout mirrors Ruffle's swf/src/avm2/types.rs (the
// binary-format ground truth for this module) with one deliberate difference:
// every constant-pool vector stores a synthetic default entry at index 0, so
// raw pool indices from the bytecode index the vectors directly. Index 0 means
// "any"/"no value" per the AVM2 spec.

#include <cstdint>
#include <string>
#include <vector>

namespace SWFRecomp
{
namespace abc
{
	typedef int16_t s16;
	typedef int32_t s32;
	typedef int64_t s64;
	typedef uint8_t u8;
	typedef uint16_t u16;
	typedef uint32_t u32;
	typedef uint64_t u64;

	enum class NamespaceKind : u8
	{
		Private = 0x05,
		Namespace = 0x08,
		Package = 0x16,
		PackageInternal = 0x17,
		Protected = 0x18,
		Explicit = 0x19,
		StaticProtected = 0x1a,
	};

	struct AbcNamespace
	{
		NamespaceKind kind = NamespaceKind::Package;
		u32 name = 0;  // string pool index

		// The AS3 "public" namespace: kind Namespace or Package with an empty
		// name (Ruffle folds both kinds into one; see namespace.rs is_public).
		bool isPublicKind() const
		{
			return kind == NamespaceKind::Namespace || kind == NamespaceKind::Package;
		}
	};

	typedef std::vector<u32> NamespaceSet;  // namespace pool indices

	enum class MultinameKind : u8
	{
		QName = 0x07,
		QNameA = 0x0d,
		RTQName = 0x0f,
		RTQNameA = 0x10,
		RTQNameL = 0x11,
		RTQNameLA = 0x12,
		Multiname = 0x09,
		MultinameA = 0x0e,
		MultinameL = 0x1b,
		MultinameLA = 0x1c,
		TypeName = 0x1d,
	};

	struct AbcMultiname
	{
		MultinameKind kind = MultinameKind::QName;
		u32 ns = 0;              // namespace pool index (QName/QNameA)
		u32 name = 0;            // string pool index (QName*, RTQName*, Multiname*)
		u32 ns_set = 0;          // ns-set pool index (Multiname*, MultinameL*)
		u32 base_type = 0;       // multiname pool index (TypeName)
		std::vector<u32> type_params;  // multiname pool indices (TypeName)

		// Name popped from the operand stack at runtime.
		bool hasLazyName() const
		{
			return kind == MultinameKind::RTQNameL || kind == MultinameKind::RTQNameLA
			    || kind == MultinameKind::MultinameL || kind == MultinameKind::MultinameLA;
		}

		// Namespace popped from the operand stack at runtime.
		bool hasLazyNs() const
		{
			return kind == MultinameKind::RTQName || kind == MultinameKind::RTQNameA
			    || kind == MultinameKind::RTQNameL || kind == MultinameKind::RTQNameLA;
		}

		bool hasLazyComponent() const
		{
			return hasLazyName() || hasLazyNs();
		}

		bool isAttribute() const
		{
			return kind == MultinameKind::QNameA || kind == MultinameKind::RTQNameA
			    || kind == MultinameKind::RTQNameLA || kind == MultinameKind::MultinameA
			    || kind == MultinameKind::MultinameLA;
		}
	};

	struct ConstantPool
	{
		// All vectors have a synthetic entry at index 0 ("any"/default), so
		// size() == pool count from the file (which itself counts entry 0).
		std::vector<s32> ints;
		std::vector<u32> uints;
		std::vector<double> doubles;
		std::vector<std::string> strings;
		std::vector<AbcNamespace> namespaces;
		std::vector<NamespaceSet> ns_sets;
		std::vector<AbcMultiname> multinames;
	};

	enum MethodFlags : u8
	{
		METHOD_NEED_ARGUMENTS = 1 << 0,
		METHOD_NEED_ACTIVATION = 1 << 1,
		METHOD_NEED_REST = 1 << 2,
		METHOD_HAS_OPTIONAL = 1 << 3,
		METHOD_IGNORE_REST = 1 << 4,
		METHOD_NATIVE = 1 << 5,
		METHOD_SET_DXNS = 1 << 6,
		METHOD_HAS_PARAM_NAMES = 1 << 7,
	};

	// Constant-value kinds shared by optional-parameter defaults and slot
	// trait initializers. The index field's pool depends on the kind.
	enum class DefaultValueKind : u8
	{
		Undefined = 0x00,
		String = 0x01,
		Int = 0x03,
		Uint = 0x04,
		PrivateNs = 0x05,
		Double = 0x06,
		Namespace = 0x08,
		False = 0x0a,
		True = 0x0b,
		Null = 0x0c,
		PackageNs = 0x16,
		PackageInternalNs = 0x17,
		ProtectedNs = 0x18,
		ExplicitNs = 0x19,
		StaticProtectedNs = 0x1a,
	};

	struct DefaultValue
	{
		bool present = false;
		DefaultValueKind kind = DefaultValueKind::Undefined;
		u32 index = 0;
	};

	struct MethodParam
	{
		u32 type = 0;          // multiname pool index
		u32 name = 0;          // string pool index (only if HAS_PARAM_NAMES)
		DefaultValue default_value;
	};

	struct AbcMethod
	{
		u32 name = 0;          // string pool index
		u32 return_type = 0;   // multiname pool index
		u8 flags = 0;
		std::vector<MethodParam> params;
		s32 body = -1;         // method_bodies index, bound while parsing bodies; -1 = none
	};

	struct AbcException
	{
		u32 from_offset = 0;
		u32 to_offset = 0;
		u32 target_offset = 0;
		// Both are multiname pool indices despite the AVM2 overview calling
		// them string indices (matches Ruffle types.rs).
		u32 type_name = 0;
		u32 variable_name = 0;
	};

	enum class TraitKindType : u8
	{
		Slot = 0,
		Method = 1,
		Getter = 2,
		Setter = 3,
		Class = 4,
		Function = 5,
		Const = 6,
	};

	struct AbcTrait
	{
		u32 name = 0;  // multiname pool index (must be a QName)
		TraitKindType kind = TraitKindType::Slot;
		bool is_final = false;
		bool is_override = false;
		u32 slot_or_disp_id = 0;  // slot_id (Slot/Const/Class/Function) or disp_id (Method/Getter/Setter)
		u32 type_name = 0;        // multiname pool index (Slot/Const)
		DefaultValue value;       // (Slot/Const)
		u32 method_or_class = 0;  // method index (Method/Getter/Setter/Function) or class index (Class)
		std::vector<u32> metadata;  // metadata table indices
	};

	struct AbcInstance
	{
		u32 name = 0;        // multiname pool index (QName)
		u32 super_name = 0;  // multiname pool index (0 = no superclass, i.e. Object/interface)
		bool is_sealed = false;
		bool is_final = false;
		bool is_interface = false;
		bool has_protected_ns = false;
		u32 protected_ns = 0;  // namespace pool index
		std::vector<u32> interfaces;  // multiname pool indices
		u32 init_method = 0;   // method table index
		std::vector<AbcTrait> traits;
	};

	struct AbcClass
	{
		u32 init_method = 0;   // static initializer, method table index
		std::vector<AbcTrait> traits;
	};

	struct AbcScript
	{
		u32 init_method = 0;   // method table index
		std::vector<AbcTrait> traits;
	};

	struct AbcMethodBody
	{
		u32 method = 0;        // method table index
		u32 max_stack = 0;
		u32 num_locals = 0;
		u32 init_scope_depth = 0;
		u32 max_scope_depth = 0;
		std::vector<u8> code;
		std::vector<AbcException> exceptions;
		std::vector<AbcTrait> traits;
	};

	struct MetadataItem
	{
		u32 key = 0;    // string pool index
		u32 value = 0;  // string pool index
	};

	struct AbcMetadata
	{
		u32 name = 0;   // string pool index
		std::vector<MetadataItem> items;
	};

	struct AbcFile
	{
		u16 minor_version = 0;
		u16 major_version = 0;
		ConstantPool pool;
		std::vector<AbcMethod> methods;
		std::vector<AbcMetadata> metadata;
		std::vector<AbcInstance> instances;
		std::vector<AbcClass> classes;   // parallel to instances (same count)
		std::vector<AbcScript> scripts;
		std::vector<AbcMethodBody> method_bodies;
	};

	// SymbolClass (tag 76) bindings: character id -> AS3 class name.
	// char_id 0 binds the class of the main timeline (root).
	struct SymbolClassBinding
	{
		u16 char_id = 0;
		std::string class_name;
	};
}
}
