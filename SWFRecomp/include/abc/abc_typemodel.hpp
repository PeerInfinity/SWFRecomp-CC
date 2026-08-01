#pragma once

// Shared compile-time ABC type model.
//
// Both the verifier (abc_verifier.cpp) and the emitter (abc_emit.cpp) need the
// same three things, and used to carry private copies of each:
//
//   * `stackEffect` — the per-op operand-stack pop/push (and scope) delta.
//     The emitter's `irStackEffect` is now a thin wrapper that discards the
//     scope delta; `scoutStaticTypes` uses that wrapper too. One copy.
//   * `AbcTypeModel` — name->instance resolution (with an ambiguity count),
//     method->declaring-class mapping, subclass index, sealedness, cumulative
//     ivtable `slotCountOf` (numbered identically to avm2_class.c, -1 whenever
//     any ancestor leaves the ABC), and the ns-aware multiname/trait matcher.
//   * `TK`/`TV` — the coerce-elision static-type lattice.
//
// Promoted here per SWFRecompDocs/plans/abc-verifier-type-lattice-arc.md §1.1
// (Stage 0 step 1) so the verifier's type lattice can reuse `slotCountOf`'s
// conservative "-1 means we do not know" rule rather than growing a fourth
// copy of it.

#include <map>
#include <string>
#include <vector>

#include <abc/abc_ir.hpp>
#include <abc/abc_parser.hpp>

namespace SWFRecomp
{
namespace abc
{
	using std::string;

	// Compile-time static-type lattice for coerce elision (Step 4). A value's
	// static type is either a primitive builtin, a user ABC class instance, or
	// UNKNOWN (any / Object / a native class with no ABC layout we model).
	// TK_NULL = a null LITERAL (PushNull provenance): coercing null to any
	// class/interface or String target yields null unchanged (a value no-op),
	// but null → Number/int/uint/Boolean changes representation (0/false).
	enum TK { TK_UNK = 0, TK_INT, TK_UINT, TK_NUM, TK_BOOL, TK_STR, TK_INST,
	          TK_NULL };
	struct TV { TK k = TK_UNK; int inst = -1; };

	struct AbcTypeModel
	{
		const AbcFile& abc;
		std::map<string, int> nameToInst;   // user-class local name -> instance idx
		std::map<string, int> nameCount;    // local name -> #instances with it
		struct MI { int cls = -1; bool inst = true; };
		std::map<u32, MI> m2c;              // method index -> defining class + this-kind
		std::map<int, std::vector<int>> children;  // instance idx -> direct subclasses
		mutable std::map<int, int> slotCountMemo;

		explicit AbcTypeModel(const AbcFile& a) : abc(a)
		{
			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				string nm = localName(abc.instances[i].name);
				if (nm.empty()) continue;
				if (!nameToInst.count(nm)) nameToInst[nm] = (int) i;
				nameCount[nm]++;
			}
			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				int sup = typeMnToInst(abc.instances[i].super_name);
				if (sup >= 0) children[sup].push_back((int) i);
			}
			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				const AbcInstance& in = abc.instances[i];
				m2c[in.init_method] = { (int) i, true };
				for (const AbcTrait& t : in.traits)
					if (t.kind == TraitKindType::Method || t.kind == TraitKindType::Getter
					    || t.kind == TraitKindType::Setter)
						m2c[t.method_or_class] = { (int) i, true };
				if (i < abc.classes.size())
				{
					m2c[abc.classes[i].init_method] = { (int) i, false };
					for (const AbcTrait& t : abc.classes[i].traits)
						if (t.kind == TraitKindType::Method || t.kind == TraitKindType::Getter
						    || t.kind == TraitKindType::Setter)
							m2c[t.method_or_class] = { (int) i, false };
				}
			}
		}
		string localName(u32 mn) const
		{
			const auto& S = abc.pool.strings; const auto& MN = abc.pool.multinames;
			if (mn == 0 || mn >= MN.size()) return "";
			u32 s = MN[mn].name; return s < S.size() ? S[s] : "";
		}
		int typeMnToInst(u32 mn) const
		{
			if (mn == 0) return -1;
			auto it = nameToInst.find(localName(mn));
			return it == nameToInst.end() ? -1 : it->second;
		}
		bool isSealed(int inst) const
		{
			return inst >= 0 && inst < (int) abc.instances.size()
			    && abc.instances[inst].is_sealed && !abc.instances[inst].is_interface;
		}
		static bool isSlotKind(TraitKindType k)
		{
			return k == TraitKindType::Slot || k == TraitKindType::Const
			    || k == TraitKindType::Class || k == TraitKindType::Function;
		}
		// The ivtable slot_count a class inherits from its superclass: 0 if it
		// extends Object (super_name 0, or a multiname naming the native root
		// Object — which has no instance slots), the super's cumulative count if
		// the super is ABC-defined, or -1 if the super is any OTHER native class
		// (Sprite/EventDispatcher/... — unknown slot base, so not specializable).
		int inheritedBase(u32 super_name) const
		{
			if (super_name == 0) return 0;
			int sup = typeMnToInst(super_name);
			if (sup >= 0) return slotCountOf(sup);
			return localName(super_name) == "Object" ? 0 : -1;
		}
		// Cumulative ivtable slot_count (own + all ABC ancestors), or -1 if any
		// ancestor is non-ABC (native base → unknown slot base) or the chain is
		// malformed/cyclic. Mirrors avm2_class.c: parent seed + per-trait bump.
		int slotCountOf(int inst) const
		{
			if (inst < 0 || inst >= (int) abc.instances.size()) return -1;
			auto it = slotCountMemo.find(inst);
			if (it != slotCountMemo.end()) return it->second;
			slotCountMemo[inst] = -1;  // cycle guard
			const AbcInstance& in = abc.instances[inst];
			int base = inheritedBase(in.super_name);
			if (base < 0) return -1;
			int sc = base;
			for (const AbcTrait& t : in.traits)
				if (isSlotKind(t.kind)) {
					u32 sid = t.slot_or_disp_id ? t.slot_or_disp_id : (u32)(sc + 1);
					if ((int) sid > sc) sc = (int) sid;
				}
			slotCountMemo[inst] = sc;
			return sc;
		}
		// A UNIQUE slot/const trait named `name` in inst's chain: returns the
		// declaring instance + trait index. found=false on no-match, ambiguity
		// (same local name appears more than once in the chain), or non-slot.
		struct Found { bool ok = false; int declInst = -1; int traitIdx = -1; };
		// `site_mn` (0 = skip) is the multiname of the READ/WRITE site: the
		// found trait must ns-match it, not merely share its local name.
		// Without that check a subclass's `this.privArray` binds to the
		// SUPERCLASS's `private var privArray` slot at compile time and the
		// runtime's #1069 never runs (as3/Definitions/Classes/Ext/
		// ExtPublicClassPriv). Local-name matching stays for the shadowing
		// (`hits`) bail, which must stay ns-blind to be conservative.
		Found findUniqueSlot(int inst, const string& name, u32 site_mn = 0) const
		{
			Found res; int hits = 0, cur = inst, guard = 0;
			while (cur >= 0 && cur < (int) abc.instances.size() && guard++ < 64)
			{
				const AbcInstance& in = abc.instances[cur];
				for (size_t ti = 0; ti < in.traits.size(); ti++)
					if (localName(in.traits[ti].name) == name)
					{
						hits++;
						TraitKindType k = in.traits[ti].kind;
						if (k == TraitKindType::Slot || k == TraitKindType::Const)
						{ res.ok = true; res.declInst = cur; res.traitIdx = (int) ti; }
						else res.ok = false;
					}
				if (in.super_name == 0) break;
				cur = typeMnToInst(in.super_name);
			}
			if (hits != 1) res.ok = false;  // ambiguous/shadowed → bail
			if (res.ok && site_mn != 0
			    && !mnMatchesQName(site_mn,
			                       abc.instances[res.declInst].traits[res.traitIdx].name))
			{
				res.ok = false;  // name matches, namespace does not
			}
			return res;
		}
		// Does any STRICT subclass of `cls` declare a trait with local name
		// `name`? If so, a subclass receiver would resolve the multiname to that
		// subclass's own (shadowing) slot — a different index than the ancestor
		// slot the compile-time pass would bake — so the site is NOT safely
		// specializable (`this` may be any subclass at runtime). Guards the
		// sub/super same-field case (avm2 sub_super_same_field).
		bool subclassRedeclares(int cls, const string& name) const
		{
			std::vector<int> stack;
			auto it = children.find(cls);
			if (it != children.end())
				for (int c : it->second) stack.push_back(c);
			int guard = 0;
			while (!stack.empty() && guard++ < 100000)
			{
				int c = stack.back(); stack.pop_back();
				for (const AbcTrait& t : abc.instances[c].traits)
					if (localName(t.name) == name) return true;
				auto cit = children.find(c);
				if (cit != children.end())
					for (int k : cit->second) stack.push_back(k);
			}
			return false;
		}
		// Runtime-matching slot index for the slot trait at traitIdx in declInst,
		// or -1 if the chain is not fully ABC-defined.
		int computeSlotIndex(int declInst, int traitIdx) const
		{
			if (declInst < 0) return -1;
			const AbcInstance& in = abc.instances[declInst];
			int base = inheritedBase(in.super_name);
			if (base < 0) return -1;
			int sc = base;
			for (size_t ti = 0; ti < in.traits.size(); ti++)
			{
				const AbcTrait& t = in.traits[ti];
				if (!isSlotKind(t.kind)) continue;
				u32 sid = t.slot_or_disp_id ? t.slot_or_disp_id : (u32)(sc + 1);
				if ((int) ti == traitIdx) return (int) sid;
				if ((int) sid > sc) sc = (int) sid;
			}
			return -1;
		}
		// The class (static) slot index for the static Slot/Const trait named
		// `name` on class `cls`, or -1. Class-object slots are numbered by the
		// runtime cvt (avm2_class.c ~1025: a FRESH vtable seeded from
		// slot_count 0 — statics are NOT inherited, so unlike instance slots
		// there is no super seed) over the class's OWN static traits, honoring
		// explicit slot_or_disp_id. Every slot-kind trait (Slot/Const/Class/
		// Function) consumes a slot id, so all are walked for numbering, but a
		// direct read is emitted only for Slot/Const (Class/Function statics and
		// getter/setter/method statics are not plain value slots we specialize).
		int computeStaticSlotIndex(int cls, const string& name) const
		{
			if (cls < 0 || cls >= (int) abc.classes.size()) return -1;
			const std::vector<AbcTrait>& traits = abc.classes[cls].traits;
			int sc = 0, hits = 0, result = -1;
			for (const AbcTrait& t : traits)
			{
				bool named = localName(t.name) == name;
				if (named) hits++;
				if (!isSlotKind(t.kind))
				{
					// A getter/setter/method static shadowing the name → not a
					// plain slot: bail (handled by the hits!=1 guard below too).
					continue;
				}
				u32 sid = t.slot_or_disp_id ? t.slot_or_disp_id : (u32)(sc + 1);
				if (named && (t.kind == TraitKindType::Slot
				              || t.kind == TraitKindType::Const))
				{
					result = (int) sid;
				}
				if ((int) sid > sc) sc = (int) sid;
			}
			return hits == 1 ? result : -1;   // ambiguous/accessor → bail
		}
		// Instance/class index for a class whose local name is UNIQUE across all
		// instances (so a compile-time getlex-name → class mapping is
		// unambiguous), else -1. Native classes (Math, flash.geom.*) are absent
		// from nameToInst → -1 → never specialized.
		int uniqueClassByName(const string& name) const
		{
			auto ci = nameCount.find(name);
			if (ci == nameCount.end() || ci->second != 1) return -1;
			auto it = nameToInst.find(name);
			return it == nameToInst.end() ? -1 : it->second;
		}

		// ---- Runtime-mirror multiname/trait ns matching (find→this lever) ---
		// Mirrors avm2_class.c exactly: ns folding (Namespace 0x08 unifies with
		// Package 0x16), public/AS3-builtin unification, uri string compare.
		// Trait names are QNames; a site multiname matches on its QName ns or
		// any ns in its set.
		// `priv` is the PrivateNamespace identity: ASC emits one Private pool
		// entry per class, ALL with the same (empty) name, and avmplus/Ruffle
		// compare private namespaces by entry identity, never by URI. Within
		// one ABC the pool index IS that identity (runtime mirror:
		// Avm2PropKey::ns_priv, the pool record's address). 0 = not private.
		struct NsKey { u8 folded = 0x16; string uri; u32 priv = 0; };
		NsKey nsKeyOf(u32 ns_idx) const
		{
			NsKey k;
			if (ns_idx < abc.pool.namespaces.size())
			{
				const AbcNamespace& ns = abc.pool.namespaces[ns_idx];
				u8 kind = (u8) ns.kind;
				k.folded = (kind == 0x08) ? 0x16 : kind;
				k.uri = ns.name < abc.pool.strings.size()
					? abc.pool.strings[ns.name] : "";
				if (kind == 0x05) k.priv = ns_idx;
			}
			return k;
		}
		static bool nsKeyPublic(const NsKey& k)
		{
			return k.folded == 0x16
			    && (k.uri.empty() || k.uri == "http://adobe.com/AS3/2006/builtin");
		}
		static bool nsKeysMatch(const NsKey& a, const NsKey& b)
		{
			bool pa = nsKeyPublic(a), pb = nsKeyPublic(b);
			if (pa || pb) return pa && pb;
			if (a.folded != b.folded) return false;
			if (a.folded == 0x05) return a.priv == b.priv;
			return a.uri == b.uri;
		}
		// Does the site multiname `mn` (QName 0x07/0x0d or static Multiname
		// 0x09/0x0e) match the trait QName `tname`? (avm2_mn_match mirror)
		bool mnMatchesQName(u32 mn, u32 tname) const
		{
			const auto& MNs = abc.pool.multinames;
			if (mn == 0 || mn >= MNs.size()) return false;
			if (tname == 0 || tname >= MNs.size()) return false;
			string nm = localName(mn);
			if (nm.empty() || nm != localName(tname)) return false;
			const AbcMultiname& m = MNs[mn];
			// Trait keys come from avm2_propkey_from_qname, which only
			// accepts QName kinds — mirror that (non-QName trait names are
			// never keyed by the runtime).
			u8 tk_kind = (u8) MNs[tname].kind;
			if (tk_kind != 0x07 && tk_kind != 0x0d) return false;
			NsKey tk = nsKeyOf(MNs[tname].ns);
			u8 mk = (u8) m.kind;
			if (mk == 0x07 || mk == 0x0d)
				return nsKeysMatch(nsKeyOf(m.ns), tk);
			if (mk == 0x09 || mk == 0x0e)
			{
				if (m.ns_set >= abc.pool.ns_sets.size()) return false;
				for (u32 nsi : abc.pool.ns_sets[m.ns_set])
					if (nsKeysMatch(nsKeyOf(nsi), tk)) return true;
			}
			return false;
		}
		// Any declared instance trait in inst's ABC-visible chain matching
		// `mn` (mirror of the runtime vtable probe scope_defines_mn uses).
		// Native ancestors' traits are invisible here, which can only
		// UNDER-approve (skip a valid substitution), never over-approve.
		bool chainDefinesMn(int inst, u32 mn) const
		{
			int cur = inst, guard = 0;
			while (cur >= 0 && cur < (int) abc.instances.size() && guard++ < 64)
			{
				for (const AbcTrait& t : abc.instances[cur].traits)
					if (mnMatchesQName(mn, t.name)) return true;
				if (abc.instances[cur].super_name == 0) break;
				cur = typeMnToInst(abc.instances[cur].super_name);
			}
			return false;
		}
		// The class (static) Slot/Const trait of `cls` matching the SITE
		// multiname `mn` (ns-aware via mnMatchesQName), with its runtime cvt
		// slot index (computeStaticSlotIndex numbering). Bails (ok=false) on
		// local-name ambiguity (mirroring computeStaticSlotIndex), non-slot
		// kinds, or a non-positive index — the find→own-class-static lever's
		// site qualifier.
		struct StaticSlot { bool ok = false; int K = -1; u32 type_mn = 0;
		                    bool is_const = false; };
		StaticSlot staticSlotForMn(int cls, u32 mn) const
		{
			StaticSlot res;
			if (cls < 0 || cls >= (int) abc.classes.size()) return res;
			const std::vector<AbcTrait>& traits = abc.classes[cls].traits;
			string nm = localName(mn);
			if (nm.empty()) return res;
			int sc = 0, hits = 0, mnhits = 0, K = -1;
			const AbcTrait* found = nullptr;
			for (const AbcTrait& t : traits)
			{
				if (localName(t.name) == nm) hits++;
				bool matches = mnMatchesQName(mn, t.name);
				if (matches) mnhits++;
				if (!isSlotKind(t.kind)) continue;
				u32 sid = t.slot_or_disp_id ? t.slot_or_disp_id : (u32)(sc + 1);
				if (matches && (t.kind == TraitKindType::Slot
				                || t.kind == TraitKindType::Const))
				{
					K = (int) sid;
					found = &t;
				}
				if ((int) sid > sc) sc = (int) sid;
			}
			if (hits != 1 || mnhits != 1 || K <= 0 || found == nullptr)
				return res;
			res.ok = true; res.K = K; res.type_mn = found->type_name;
			res.is_const = found->kind == TraitKindType::Const;
			return res;
		}
		// Instance-slot STORE qualifier (store-path lever): the GET-lever
		// gate list — sealed receiver class, unique slot in the ABC chain,
		// no subclass redeclares it, exact ABC slot index — PLUS the ns-aware
		// chainDefinesMn positive check (the site multiname must match the
		// declared trait the way avm2_mn_match would).
		struct InstSlot { bool ok = false; int K = -1; u32 type_mn = 0;
		                  bool is_const = false; };
		InstSlot instSlotForStore(int cls, u32 mn) const
		{
			InstSlot r;
			if (!isSealed(cls)) return r;
			if (!chainDefinesMn(cls, mn)) return r;
			string nm = localName(mn);
			if (subclassRedeclares(cls, nm)) return r;
			Found f = findUniqueSlot(cls, nm, mn);
			if (!f.ok) return r;
			int K = computeSlotIndex(f.declInst, f.traitIdx);
			if (K <= 0) return r;
			const AbcTrait& t = abc.instances[f.declInst].traits[f.traitIdx];
			r.ok = true; r.K = K; r.type_mn = t.type_name;
			r.is_const = t.kind == TraitKindType::Const;
			return r;
		}

		// ---- Static-type lattice (coerce elision, Step 4) -------------------
		// Resolve a TYPE multiname to the lattice: a user ABC class (INST), a
		// primitive builtin, or UNKNOWN (any/Object/native class with no ABC
		// slot layout). Native classes (Sprite/Point/...) are absent from
		// nameToInst and are NOT in the primitive set → UNKNOWN → never elided.
		TV typeOfMn(u32 mn) const
		{
			if (mn == 0) return TV{};             // "*" / any
			int c = typeMnToInst(mn);
			if (c >= 0) return TV{ TK_INST, c };
			string n = localName(mn);
			if (n == "int") return TV{ TK_INT };
			if (n == "uint") return TV{ TK_UINT };
			if (n == "Number") return TV{ TK_NUM };
			if (n == "Boolean") return TV{ TK_BOOL };
			if (n == "String") return TV{ TK_STR };
			return TV{};                          // Object / void / native
		}
		// sc is `tc` or a subclass of `tc` via the ABC instance super chain.
		bool isSubtypeOrEqual(int sc, int tc) const
		{
			int cur = sc, guard = 0;
			while (cur >= 0 && cur < (int) abc.instances.size() && guard++ < 64)
			{
				if (cur == tc) return true;
				if (abc.instances[cur].super_name == 0) break;
				cur = typeMnToInst(abc.instances[cur].super_name);
			}
			return false;
		}
		// Is coercing a value of static type S to target type T a value no-op?
		//   * T a user class/interface: S is that class or a subclass — the
		//     value is already an instance of T, and a null value coerces to
		//     null unchanged. Exact match also covers interface targets (a
		//     value statically typed as the interface already implements it).
		//   * T a primitive: S is EXACTLY the same primitive (int != Number:
		//     the runtime representation differs, so no subtyping across
		//     primitives).
		//   * T UNKNOWN (any/Object/native): no guarantee → never elide (e.g.
		//     coerce-to-Object turns undefined into null, not a no-op).
		bool coerceIsNoop(TV S, TV T) const
		{
			if (T.k == TK_INST)
				return S.k == TK_NULL
				    || (S.k == TK_INST && isSubtypeOrEqual(S.inst, T.inst));
			if (T.k == TK_UNK) return false;
			if (T.k == TK_STR) return S.k == TK_STR || S.k == TK_NULL;
			return S.k == T.k;
		}
		// Static type of the value produced by reading property `name` off a
		// receiver of instance type `inst`: a Slot/Const's declared type, a
		// Getter/Method's return type. The value the runtime yields is coerced
		// to this type (slot stores and param/return coercions guarantee it),
		// so it is a SOUND seed. UNKNOWN if not found or setter-only.
		TV memberReadType(int inst, const string& name) const
		{
			int cur = inst, guard = 0;
			while (cur >= 0 && cur < (int) abc.instances.size() && guard++ < 64)
			{
				for (const AbcTrait& t : abc.instances[cur].traits)
					if (localName(t.name) == name)
					{
						if (t.kind == TraitKindType::Slot
						    || t.kind == TraitKindType::Const)
							return typeOfMn(t.type_name);
						if ((t.kind == TraitKindType::Getter
						     || t.kind == TraitKindType::Method)
						    && t.method_or_class < abc.methods.size())
							return typeOfMn(abc.methods[t.method_or_class].return_type);
						return TV{};   // setter-only / class / function
					}
				if (abc.instances[cur].super_name == 0) break;
				cur = typeMnToInst(abc.instances[cur].super_name);
			}
			return TV{};
		}
	};

	// Per-op operand-stack effect on the resolved IR. `extra` multiname pops
	// (lazy name/ns) are included. `scope_delta` covers pushscope/pushwith/
	// popscope.
	inline void stackEffect(const IrOp& op, const AbcFile& abc,
	                        u32& pops, u32& pushes, s32& scope_delta)
	{
		pops = 0;
		pushes = 0;
		scope_delta = 0;

		u32 lazy = 0;
		switch (op.op)
		{
			case IrOpcode::CallProperty:
			case IrOpcode::CallPropLex:
			case IrOpcode::CallPropVoid:
			case IrOpcode::CallSuper:
			case IrOpcode::ConstructProp:
			case IrOpcode::GetPropertyStatic:
			case IrOpcode::GetPropertyFast:
			case IrOpcode::GetPropertySlow:
			case IrOpcode::SetPropertyStatic:
			case IrOpcode::SetPropertyFast:
			case IrOpcode::SetPropertySlow:
			case IrOpcode::InitProperty:
			case IrOpcode::DeleteProperty:
			case IrOpcode::GetSuper:
			case IrOpcode::SetSuper:
			case IrOpcode::GetDescendants:
			case IrOpcode::FindProperty:
			case IrOpcode::FindPropStrict:
			case IrOpcode::FindDef:
			{
				if (op.arg1 < abc.pool.multinames.size())
				{
					const AbcMultiname& mn = abc.pool.multinames[op.arg1];
					lazy = (mn.hasLazyName() ? 1u : 0u)
					     + (mn.hasLazyNs() ? 1u : 0u);
				}
				break;
			}
			default: break;
		}

		switch (op.op)
		{
			// pop 2, push 1
			case IrOpcode::Add: case IrOpcode::AddI:
			case IrOpcode::Subtract: case IrOpcode::SubtractI:
			case IrOpcode::Multiply: case IrOpcode::MultiplyI:
			case IrOpcode::Divide: case IrOpcode::Modulo:
			case IrOpcode::LShift: case IrOpcode::RShift: case IrOpcode::URShift:
			case IrOpcode::BitAnd: case IrOpcode::BitOr: case IrOpcode::BitXor:
			case IrOpcode::Equals: case IrOpcode::StrictEquals:
			case IrOpcode::LessThan: case IrOpcode::LessEquals:
			case IrOpcode::GreaterThan: case IrOpcode::GreaterEquals:
			case IrOpcode::In: case IrOpcode::InstanceOf:
			case IrOpcode::IsTypeLate: case IrOpcode::AsTypeLate:
			case IrOpcode::HasNext:
			case IrOpcode::NextName: case IrOpcode::NextValue:
			{
				pops = 2; pushes = 1;
				break;
			}

			// pop 1, push 1
			case IrOpcode::Negate: case IrOpcode::NegateI:
			case IrOpcode::BitNot: case IrOpcode::Not:
			case IrOpcode::Increment: case IrOpcode::IncrementI:
			case IrOpcode::Decrement: case IrOpcode::DecrementI:
			case IrOpcode::TypeOf:
			case IrOpcode::ConvertO: case IrOpcode::ConvertS:
			case IrOpcode::CoerceA: case IrOpcode::CoerceB: case IrOpcode::CoerceD:
			case IrOpcode::CoerceI: case IrOpcode::CoerceO: case IrOpcode::CoerceS:
			case IrOpcode::CoerceU: case IrOpcode::Coerce:
			case IrOpcode::AsType: case IrOpcode::IsType:
			case IrOpcode::CheckFilter:
			case IrOpcode::EscXAttr: case IrOpcode::EscXElem:
			case IrOpcode::Li8: case IrOpcode::Li16: case IrOpcode::Li32:
			case IrOpcode::Lf32: case IrOpcode::Lf64:
			case IrOpcode::Sxi1: case IrOpcode::Sxi8: case IrOpcode::Sxi16:
			case IrOpcode::NewClass:
			{
				pops = 1; pushes = 1;
				break;
			}

			// pure pushes
			case IrOpcode::PushInt: case IrOpcode::PushUint: case IrOpcode::PushDouble:
			case IrOpcode::PushString: case IrOpcode::PushNamespace:
			case IrOpcode::PushNaN: case IrOpcode::PushNull:
			case IrOpcode::PushUndefined: case IrOpcode::PushTrue: case IrOpcode::PushFalse:
			case IrOpcode::GetLocal:
			case IrOpcode::GetScopeObject: case IrOpcode::GetOuterScope:
			case IrOpcode::GetGlobalScope: case IrOpcode::GetGlobalSlot:
			case IrOpcode::NewFunction: case IrOpcode::NewCatch: case IrOpcode::NewActivation:
			case IrOpcode::HasNext2:
			{
				pushes = 1;
				break;
			}

			case IrOpcode::Dup: { pops = 1; pushes = 2; break; }
			case IrOpcode::Swap: { pops = 2; pushes = 2; break; }
			case IrOpcode::Pop: case IrOpcode::SetLocal:
			case IrOpcode::SetGlobalSlot: case IrOpcode::DxnsLate:
			case IrOpcode::IfTrue: case IrOpcode::IfFalse:
			case IrOpcode::LookupSwitch:
			case IrOpcode::ReturnValue: case IrOpcode::Throw:
			{
				pops = 1;
				break;
			}

			case IrOpcode::PushScope: case IrOpcode::PushWith:
			{
				pops = 1;
				scope_delta = 1;
				break;
			}
			case IrOpcode::PopScope:
			{
				scope_delta = -1;
				break;
			}

			case IrOpcode::GetSlot: { pops = 1; pushes = 1; break; }
			case IrOpcode::SetSlot: { pops = 2; break; }

			// property family (lazy pops included)
			case IrOpcode::GetPropertyStatic: case IrOpcode::GetPropertyFast:
			case IrOpcode::GetPropertySlow:
			case IrOpcode::GetSuper: case IrOpcode::DeleteProperty:
			case IrOpcode::GetDescendants:
			{
				pops = 1 + lazy; pushes = 1;
				break;
			}
			case IrOpcode::SetPropertyStatic: case IrOpcode::SetPropertyFast:
			case IrOpcode::SetPropertySlow:
			case IrOpcode::InitProperty: case IrOpcode::SetSuper:
			{
				pops = 2 + lazy;
				break;
			}
			case IrOpcode::FindProperty: case IrOpcode::FindPropStrict:
			case IrOpcode::FindDef:
			{
				pops = lazy; pushes = 1;
				break;
			}

			// calls
			case IrOpcode::Call: { pops = op.arg2 + 2; pushes = 1; break; }
			case IrOpcode::CallStatic: { pops = op.arg2 + 1; pushes = 1; break; }
			case IrOpcode::CallProperty: case IrOpcode::CallPropLex:
			case IrOpcode::CallSuper:
			{
				pops = op.arg2 + 1 + lazy; pushes = 1;
				break;
			}
			case IrOpcode::CallPropVoid:
			{
				pops = op.arg2 + 1 + lazy;
				break;
			}
			case IrOpcode::Construct: { pops = op.arg2 + 1; pushes = 1; break; }
			case IrOpcode::ConstructProp: { pops = op.arg2 + 1 + lazy; pushes = 1; break; }
			case IrOpcode::ConstructSuper: { pops = op.arg2 + 1; break; }

			// allocation
			case IrOpcode::NewObject: { pops = op.arg2 * 2; pushes = 1; break; }
			case IrOpcode::NewArray: { pops = op.arg2; pushes = 1; break; }
			case IrOpcode::ApplyType: { pops = op.arg2 + 1; pushes = 1; break; }

			// memory stores
			case IrOpcode::Si8: case IrOpcode::Si16: case IrOpcode::Si32:
			case IrOpcode::Sf32: case IrOpcode::Sf64:
			{
				pops = 2;
				break;
			}

			// everything else: no stack effect
			default: break;
		}
	}
}
}
