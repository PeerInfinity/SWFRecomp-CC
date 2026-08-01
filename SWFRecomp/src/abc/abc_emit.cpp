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
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <sys/stat.h>

#include <abc/abc_dump.hpp>
#include <abc/abc_emit.hpp>
#include <abc/abc_parser.hpp>
#include <abc/abc_typemodel.hpp>

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

	// ------------------------------------------------------------------
	// Pool-normalized class fingerprints
	//
	// ABC bodies embed constant-pool *indices*, which differ between two
	// SWFs compiled from identical AS3 source (different pool layout). A
	// fingerprint that is stable across titles must therefore hash the
	// *resolved pool content* — qualified names, string bytes, numeric
	// values — never the raw index. Everything that is not a pool index
	// (registers, arg counts, branch offsets) is hashed raw.
	//
	// A fingerprint of 0 means "unhashable" and must never be treated as a
	// match by any consumer (fail safe).
	// ------------------------------------------------------------------

	static const u64 FNV_OFFSET = 14695981039346656037ull;
	static const u64 FNV_PRIME = 1099511628211ull;

	static inline u64 hashBytes(u64 h, const void* data, size_t n)
	{
		const unsigned char* p = (const unsigned char*) data;
		for (size_t i = 0; i < n; i++)
		{
			h ^= (u64) p[i];
			h *= FNV_PRIME;
		}
		return h;
	}

	static inline u64 hashU32(u64 h, u32 v)
	{
		return hashBytes(h, &v, sizeof(v));
	}

	// Length-delimited so "ab"+"c" and "a"+"bc" hash differently.
	static inline u64 hashStr(u64 h, const string& s)
	{
		h = hashU32(h, (u32) s.size());
		return hashBytes(h, s.data(), s.size());
	}

	// "org.flixel::FlxQuadTree" — package namespace name + "::" + local name.
	// NOTE: this is NOT the protected-namespace string (which for that class
	// is "org.flixel:FlxQuadTree", a single colon).
	static string qualifiedName(const AbcFile& abc, u32 mn_index)
	{
		const auto& MN = abc.pool.multinames;
		const auto& S = abc.pool.strings;
		const auto& NS = abc.pool.namespaces;
		if (mn_index == 0 || mn_index >= MN.size()) return "";
		const AbcMultiname& mn = MN[mn_index];
		string ns_name;
		if (mn.ns != 0 && mn.ns < NS.size())
		{
			u32 si = NS[mn.ns].name;
			if (si < S.size()) ns_name = S[si];
		}
		string local;
		if (mn.name < S.size()) local = S[mn.name];
		return ns_name + "::" + local;
	}

	static u64 hashPoolString(u64 h, const AbcFile& abc, u32 idx)
	{
		const auto& S = abc.pool.strings;
		return hashStr(h, idx < S.size() ? S[idx] : string());
	}

	static u64 hashPoolInt(u64 h, const AbcFile& abc, u32 idx)
	{
		s32 v = idx < abc.pool.ints.size() ? abc.pool.ints[idx] : 0;
		return hashBytes(h, &v, sizeof(v));
	}

	static u64 hashPoolUint(u64 h, const AbcFile& abc, u32 idx)
	{
		u32 v = idx < abc.pool.uints.size() ? abc.pool.uints[idx] : 0;
		return hashBytes(h, &v, sizeof(v));
	}

	static u64 hashPoolDouble(u64 h, const AbcFile& abc, u32 idx)
	{
		double v = idx < abc.pool.doubles.size() ? abc.pool.doubles[idx] : 0.0;
		return hashBytes(h, &v, sizeof(v));
	}

	static u64 hashPoolNamespace(u64 h, const AbcFile& abc, u32 idx)
	{
		const auto& NS = abc.pool.namespaces;
		if (idx == 0 || idx >= NS.size()) return hashStr(h, "");
		h = hashBytes(h, &NS[idx].kind, 1);
		return hashPoolString(h, abc, NS[idx].name);
	}

	// ------------------------------------------------------------------
	// Fingerprint hashing context — one instance per class fingerprint.
	//
	// Carries the two pieces of cross-body state the normalized hash needs.
	// Because it is a local of classFingerprint it is naturally reset between
	// classes: two classes never share ordinal or recursion state.
	//   * ns_ordinals  — opaque-namespace canonicalization (hole 1). See
	//                     hashPoolMultiname.
	//   * methods_in_progress / depth — closure-body recursion guard (hole 2).
	//                     See hashMethodRef.
	//   * poisoned      — sticky fail-safe flag; any bodyless / undecodable
	//                     referenced closure sets it and the whole fingerprint
	//                     collapses to 0 (never-match).
	// ------------------------------------------------------------------
	struct FpCtx
	{
		const AbcFile& abc;
		// Opaque-namespace (private/protected/static-protected) canonical
		// ordinals, keyed by (kind, label). Duplicate pool entries with
		// identical content collapse to one ordinal; distinct labels of the
		// same kind get distinct ordinals. Assigned in hash-stream encounter
		// order, which is deterministic across builds.
		std::map<std::pair<u8, string>, u32> ns_ordinals;
		// Method indices whose body is currently on the hash stack.
		std::set<u32> methods_in_progress;
		int depth = 0;
		bool poisoned = false;

		explicit FpCtx(const AbcFile& a) : abc(a) {}
	};

	// Recursion depth cap for NewFunction/CallStatic closure hashing. Real
	// Flixel closures nest at most a couple deep; 8 is far above that and
	// bounds pathological / adversarial inputs deterministically. Reaching it
	// mixes a fixed marker (safe, deterministic) rather than poisoning — the
	// only residual caveat this fix leaves (see the writeup).
	static const int FP_MAX_METHOD_DEPTH = 8;

	static u64 hashMethodBody(FpCtx& ctx, const AbcMethodBody& body);

	// Namespace-label canonicalization (hole 1 CLOSED).
	//
	// Private / Protected / StaticProtected namespace NAME strings are opaque
	// compiler-minted labels, not source-level identity. Two builds of
	// byte-identical AS3 disagree on them: RWK names FlxQuadTree's protected
	// namespace "org.flixel:FlxQuadTree" while RWP names it "20" (and FlxGame's
	// is ","). Hashing the label directly would split the two builds.
	//
	// But dropping the label entirely (the old behavior) let two members with
	// the same local name in two DIFFERENT namespaces of the same kind collide.
	// So instead we replace the unstable label with a dense ORDINAL assigned in
	// encounter order within the class fingerprint: the first distinct opaque
	// namespace seen is 0, the next distinct one 1, and so on. Encounter order
	// is deterministic (the normalized instruction stream is), so the ordinals
	// line up across builds even though the underlying labels do not — while two
	// genuinely different namespaces still fingerprint differently.
	//
	// Keyed by (kind, label): duplicate pool entries with identical content
	// collapse to one ordinal (obfuscators may duplicate pool entries), while
	// distinct labels of the same kind stay distinct — that distinction is the
	// whole fix. (Keying by pool index instead would fail the duplicate rule.)
	//
	// PackageInternalNs (0x17) and ExplicitNamespace (0x19) are deliberately
	// still hashed BY NAME: those names are the package path / a user-declared
	// namespace URI, stable across builds and semantically load-bearing.
	static u64 hashPoolMultiname(u64 h, FpCtx& ctx, u32 idx)
	{
		const AbcFile& abc = ctx.abc;
		const auto& MN = abc.pool.multinames;
		const auto& S = abc.pool.strings;
		const auto& NS = abc.pool.namespaces;
		if (idx != 0 && idx < MN.size())
		{
			const AbcMultiname& mn = MN[idx];
			if (mn.ns != 0 && mn.ns < NS.size())
			{
				u8 k = (u8) NS[mn.ns].kind;
				if (k == 0x05 || k == 0x18 || k == 0x1a)
				{
					string label;
					if (NS[mn.ns].name < S.size()) label = S[NS[mn.ns].name];
					auto key = std::make_pair(k, label);
					auto it = ctx.ns_ordinals.find(key);
					u32 ord;
					if (it != ctx.ns_ordinals.end())
					{
						ord = it->second;
					}
					else
					{
						ord = (u32) ctx.ns_ordinals.size();
						ctx.ns_ordinals.emplace(key, ord);
					}
					string local;
					if (mn.name < S.size()) local = S[mn.name];
					h = hashBytes(h, &k, 1);
					h = hashU32(h, ord);
					return hashStr(h, "\x04opaque::" + local);
				}
			}
		}
		return hashStr(h, qualifiedName(abc, idx));
	}

	// Method operand (NewFunction / CallStatic): hole 2 CLOSED.
	//
	// Hashes the referenced method's SIGNATURE (param count, param types,
	// return type as resolved multinames) and its NORMALIZED BODY — reusing the
	// exact same walk as the primary body. A closure whose behavior differs now
	// changes the outer class fingerprint even when the callee's debug name is
	// blanked (obfuscators routinely blank it), which the old debug-name-only
	// hash could not detect.
	//
	// Recursion is bounded two ways: an in-progress set (a method whose body is
	// already being hashed — a cycle) and a fixed depth cap. Either mixes a
	// deterministic marker instead of recursing, so the hash stays stable
	// across builds. A bodyless or undecodable referenced method poisons the
	// fingerprint to 0 (fail safe) — the same rule the primary body follows.
	static u64 hashMethodRef(u64 h, FpCtx& ctx, u32 idx)
	{
		const AbcFile& abc = ctx.abc;
		h = hashStr(h, "\x01mref");
		if (idx >= abc.methods.size())
		{
			ctx.poisoned = true;  // dangling method ref → never match
			return hashStr(h, "\x05mref-bad");
		}
		const AbcMethod& m = abc.methods[idx];

		// Signature: resolved, constant-pool-layout independent.
		h = hashU32(h, (u32) m.params.size());
		for (const MethodParam& p : m.params)
			h = hashPoolMultiname(h, ctx, p.type);
		h = hashPoolMultiname(h, ctx, m.return_type);

		// Body: recurse, guarded against cycles and runaway depth.
		if (ctx.methods_in_progress.count(idx) || ctx.depth >= FP_MAX_METHOD_DEPTH)
		{
			return hashStr(h, "\x06mref-recur");  // deterministic marker, no recurse
		}
		if (m.body < 0 || (size_t) m.body >= abc.method_bodies.size())
		{
			ctx.poisoned = true;  // NewFunction/CallStatic to a bodyless method is malformed
			return hashStr(h, "\x07mref-nobody");
		}
		ctx.methods_in_progress.insert(idx);
		ctx.depth++;
		u64 bh = hashMethodBody(ctx, abc.method_bodies[m.body]);
		ctx.depth--;
		ctx.methods_in_progress.erase(idx);
		if (bh == 0) ctx.poisoned = true;  // referenced body was undecodable
		return hashBytes(h, &bh, sizeof(bh));
	}

	// Class operand (NewClass): the qualified name of the instance.
	static u64 hashClassRef(u64 h, const AbcFile& abc, u32 idx)
	{
		h = hashStr(h, "\x02cref");
		if (idx >= abc.instances.size()) return hashStr(h, "");
		return hashStr(h, qualifiedName(abc, abc.instances[idx].name));
	}

	// SWFRECOMP_FP_DISASM=1 (with a verbose fingerprint selection): a
	// pool-resolved listing of each hashed body, for diffing two titles.
	static void disasmBody(const AbcFile& abc, const AbcMethodBody& body,
	                       const char* label)
	{
		fprintf(stderr, "FPD ==== %s (len=%zu) ====\n", label, body.code.size());
		AbcReader r(body.code.data(), body.code.size());
		try
		{
			while (r.pos() < body.code.size())
			{
				size_t at = r.pos();
				RawOp op = readOp(r);
				string extra;
				switch (op.opcode)
				{
					case AbcOpcode::GetSuper: case AbcOpcode::SetSuper:
					case AbcOpcode::GetDescendants: case AbcOpcode::FindPropStrict:
					case AbcOpcode::FindProperty: case AbcOpcode::GetLex:
					case AbcOpcode::SetProperty: case AbcOpcode::GetProperty:
					case AbcOpcode::InitProperty: case AbcOpcode::DeleteProperty:
					case AbcOpcode::Coerce: case AbcOpcode::AsType:
					case AbcOpcode::IsType:
						extra = " mn=" + qualifiedName(abc, op.arg1);
						break;
					case AbcOpcode::CallSuper: case AbcOpcode::CallProperty:
					case AbcOpcode::ConstructProp: case AbcOpcode::CallPropLex:
					case AbcOpcode::CallSuperVoid: case AbcOpcode::CallPropVoid:
						extra = " mn=" + qualifiedName(abc, op.arg1)
						        + " argc=" + to_string(op.arg2);
						break;
					case AbcOpcode::PushString:
						extra = " str=" + (op.arg1 < abc.pool.strings.size()
						                   ? abc.pool.strings[op.arg1] : string());
						break;
					case AbcOpcode::PushDouble:
						extra = " d=" + to_string(op.arg1 < abc.pool.doubles.size()
						                          ? abc.pool.doubles[op.arg1] : 0.0);
						break;
					case AbcOpcode::PushInt:
						extra = " i=" + to_string(op.arg1 < abc.pool.ints.size()
						                          ? abc.pool.ints[op.arg1] : 0);
						break;
					default:
						extra = " a1=" + to_string(op.arg1) + " a2=" + to_string(op.arg2)
						        + " off=" + to_string((long) op.offset)
						        + " b=" + to_string((int) op.byte_arg);
						break;
				}
				fprintf(stderr, "FPD %4zu op=%02x%s\n", at, (unsigned) (u8) op.opcode,
				        extra.c_str());
			}
		}
		catch (const AbcError&) { fprintf(stderr, "FPD <parse error>\n"); }
	}

	// Normalized hash of a method body. Returns 0 (= unhashable) if the
	// linear walk throws, does not land exactly on the end of the code, or
	// contains a branch / exception-range boundary that does not fall on a
	// decoded instruction boundary.
	//
	// Branch targets are hashed as INSTRUCTION-INDEX DELTAS, never as byte
	// offsets. Two builds of identical AS3 disagree on byte offsets purely
	// because their constant pools differ in size, so the same operand encodes
	// to a different number of U30 varint bytes and every branch distance
	// shifts. The instruction-index delta cancels exactly that artifact and
	// nothing else: branch TOPOLOGY is preserved bit-for-bit, so a swapped
	// branch target still changes the fingerprint.
	//
	// Offset conventions (must match abc_verifier): plain branches are
	// relative to the byte AFTER the instruction; LookupSwitch's default and
	// case offsets are relative to the START of the LookupSwitch.
	static u64 hashMethodBody(FpCtx& ctx, const AbcMethodBody& body)
	{
		const AbcFile& abc = ctx.abc;
		if (ctx.poisoned) return 0;  // a sibling/closure already failed safe
		u64 h = FNV_OFFSET;
		h = hashU32(h, body.max_stack);
		h = hashU32(h, body.num_locals);
		h = hashU32(h, body.init_scope_depth);
		h = hashU32(h, body.max_scope_depth);

		if (body.code.empty())
		{
			// No code to index into: an exception table here is malformed.
			h = hashU32(h, (u32) body.exceptions.size());
			return body.exceptions.empty() ? (h ? h : 1) : 0;
		}

		// --- pass 1: byte offset -> instruction index -------------------
		// One-past-the-end maps to the instruction count, so a branch to the
		// end of the code is representable.
		std::vector<s32> byte_to_idx(body.code.size() + 1, -1);
		u32 op_count = 0;
		{
			AbcReader pre(body.code.data(), body.code.size());
			try
			{
				while (pre.pos() < body.code.size())
				{
					byte_to_idx[pre.pos()] = (s32) op_count++;
					readOp(pre);
				}
			}
			catch (const AbcError&)
			{
				return 0;
			}
			if (pre.pos() != body.code.size()) return 0;
		}
		byte_to_idx[body.code.size()] = (s32) op_count;

		// Resolves an absolute byte position to an instruction index.
		// Sets `ok` false if it is not an instruction boundary.
		bool ok = true;
		auto idx_at = [&](s64 byte_pos) -> s32
		{
			if (byte_pos < 0 || byte_pos > (s64) body.code.size()) { ok = false; return 0; }
			s32 idx = byte_to_idx[(size_t) byte_pos];
			if (idx < 0) { ok = false; return 0; }
			return idx;
		};

		// --- exception table (contents, as instruction indices) ---------
		h = hashU32(h, (u32) body.exceptions.size());
		for (const AbcException& exc : body.exceptions)
		{
			h = hashU32(h, (u32) idx_at((s64) exc.from_offset));
			h = hashU32(h, (u32) idx_at((s64) exc.to_offset));
			h = hashU32(h, (u32) idx_at((s64) exc.target_offset));
			h = hashPoolMultiname(h, ctx, exc.type_name);
			h = hashPoolMultiname(h, ctx, exc.variable_name);
			if (!ok) return 0;
		}

		// --- pass 2: hash ----------------------------------------------
		AbcReader r(body.code.data(), body.code.size());
		try
		{
			u32 cur_idx = 0;
			while (r.pos() < body.code.size())
			{
				size_t op_start = r.pos();
				RawOp op = readOp(r);
				size_t op_end = r.pos();
				s32 here = (s32) cur_idx++;
				u8 oc = (u8) op.opcode;
				h = hashBytes(h, &oc, 1);

				switch (op.opcode)
				{
					// --- multiname operand in arg1 ---
					case AbcOpcode::GetSuper:
					case AbcOpcode::SetSuper:
					case AbcOpcode::GetDescendants:
					case AbcOpcode::FindPropStrict:
					case AbcOpcode::FindProperty:
					case AbcOpcode::GetLex:
					case AbcOpcode::SetProperty:
					case AbcOpcode::GetProperty:
					case AbcOpcode::InitProperty:
					case AbcOpcode::DeleteProperty:
					case AbcOpcode::Coerce:
					case AbcOpcode::AsType:
					case AbcOpcode::IsType:
					{
						h = hashPoolMultiname(h, ctx, op.arg1);
						break;
					}

					// --- multiname in arg1, raw arg count in arg2 ---
					case AbcOpcode::CallSuper:
					case AbcOpcode::CallProperty:
					case AbcOpcode::ConstructProp:
					case AbcOpcode::CallPropLex:
					case AbcOpcode::CallSuperVoid:
					case AbcOpcode::CallPropVoid:
					{
						h = hashPoolMultiname(h, ctx, op.arg1);
						h = hashU32(h, op.arg2);
						break;
					}

					// --- string pool operand ---
					case AbcOpcode::PushString:
					case AbcOpcode::Dxns:
					case AbcOpcode::DebugFile:
					{
						h = hashPoolString(h, abc, op.arg1);
						break;
					}

					// --- numeric pools ---
					case AbcOpcode::PushInt:    h = hashPoolInt(h, abc, op.arg1); break;
					case AbcOpcode::PushUint:   h = hashPoolUint(h, abc, op.arg1); break;
					case AbcOpcode::PushDouble: h = hashPoolDouble(h, abc, op.arg1); break;

					// --- namespace pool ---
					case AbcOpcode::PushNamespace:
					{
						h = hashPoolNamespace(h, abc, op.arg1);
						break;
					}

					// --- method index ---
					case AbcOpcode::NewFunction:
					{
						h = hashMethodRef(h, ctx, op.arg1);
						break;
					}
					case AbcOpcode::CallStatic:
					{
						h = hashMethodRef(h, ctx, op.arg1);
						h = hashU32(h, op.arg2);  // arg count
						break;
					}

					// --- class index ---
					case AbcOpcode::NewClass:
					{
						h = hashClassRef(h, abc, op.arg1);
						break;
					}

					// --- Debug: arg1 is the register-name string index ---
					case AbcOpcode::Debug:
					{
						h = hashU32(h, op.bool_arg ? 1u : 0u);
						h = hashPoolString(h, abc, op.arg1);
						h = hashBytes(h, &op.byte_arg, 1);
						break;
					}

					// --- branches: instruction-index delta, not bytes ---
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
						// s24 is relative to the byte AFTER the instruction.
						s32 tgt = idx_at((s64) op_end + op.offset);
						if (!ok) return 0;
						h = hashU32(h, (u32) (tgt - here));
						break;
					}

					// --- lookupswitch: default + every case, as deltas ---
					case AbcOpcode::LookupSwitch:
					{
						// All LookupSwitch offsets are relative to the START of
						// the instruction.
						s32 dflt = idx_at((s64) op_start + op.offset);
						if (!ok) return 0;
						h = hashU32(h, (u32) (dflt - here));
						h = hashU32(h, (u32) op.case_offsets.size());
						for (s32 co : op.case_offsets)
						{
							s32 ct = idx_at((s64) op_start + co);
							if (!ok) return 0;
							h = hashU32(h, (u32) (ct - here));
						}
						break;
					}

					// --- everything else: raw operands ---
					//
					// Registers (Kill/GetLocal/SetLocal/IncLocal/DecLocal/
					// IncLocalI/DecLocalI/HasNext2), arg counts (Call/
					// Construct/ConstructSuper/ApplyType/NewObject/NewArray),
					// CallMethod's disp_id + arg count, slot ids (GetSlot/
					// SetSlot/GetGlobalSlot/SetGlobalSlot), NewCatch's
					// exception-table index, PushShort's literal value,
					// PushByte, GetScopeObject, and DebugLine's line number.
					//
					// Branch and LookupSwitch offsets do NOT reach here — they
					// have dedicated arms above that hash instruction-index
					// deltas.
					//
					// UNVERIFIED: FindDef (0x5f), GetOuterScope (0x67),
					// Bkpt (0x01), BkptLine (0xf2), Timestamp (0xf3) — see
					// the report; hashed raw on purpose (fail safe).
					default:
					{
						h = hashU32(h, op.arg1);
						h = hashU32(h, op.arg2);
						h = hashBytes(h, &op.byte_arg, 1);
						h = hashU32(h, op.bool_arg ? 1u : 0u);
						break;
					}
				}
			}
		}
		catch (const AbcError&)
		{
			return 0;
		}

		if (r.pos() != body.code.size()) return 0;  // did not land on the end
		if (ctx.poisoned) return 0;  // a referenced closure failed safe mid-walk
		return h ? h : 1;  // never report a real hash as "unhashable"
	}

	// ------------------------------------------------------------------
	// Known-intrinsic fingerprint table.
	//
	// A class is substituted with a native implementation ONLY on an exact
	// match here. Every other class — including a near-miss, a different
	// point release, or an obfuscated variant — keeps its own compiled
	// bodies. That fallback is the whole safety story: a silent substitution
	// with different semantics would poison the "just works" premise, so the
	// gate is deliberately biased to refuse.
	//
	// Fingerprints are pool-normalized (resolved multiname/string/numeric
	// content, instruction-index branch deltas, opaque-namespace ordinals,
	// recursively-hashed closure bodies), so one entry covers every build of
	// the same source regardless of constant-pool layout or namespace
	// obfuscation.
	//
	// ids must match avm2_flixel.h: 1 = FlxQuadTree, 2 = FlxList.
	struct IntrinsicEntry { u64 fp; unsigned id; const char* what; };
	static const IntrinsicEntry INTRINSIC_TABLE[] =
	{
		// Flixel 2.21 collision classes. Verified identical opcode-for-opcode
		// (1069 instructions) across Robot Wants Kitty and Robot Wants Puppy;
		// the two SWFs differ only in constant-pool layout and obfuscated
		// private/protected namespace labels, both of which normalize out.
		{ 0x2c1994f2e30e0642ull, 1, "org.flixel::FlxQuadTree (Flixel 2.21)" },
		{ 0x6e5f899d35ae5140ull, 2, "org.flixel.data::FlxList (Flixel 2.21)" },

		// Flixel 2.35 collision classes — Robot Wants Fishy / Ice Cream. These
		// carry PER-TITLE control-flow obfuscation (opaque predicates + jump
		// threading), so each title's FlxQuadTree AND FlxList fingerprint
		// differently from 2.21 and from each other — hence one baked constant
		// per (title, class). The obfuscation is NOT normalized away (a
		// normalizer that cancels control flow would match wrong code); instead
		// every method was verified semantically equivalent to clean upstream
		// Flixel 2.35 by opaque-predicate folding on the raw AVM2 p-code (see
		// tools/divergence/perf/RWK_AB_STATUS.md, the 2.35-extension §1 table).
		//
		// FlxList source is BYTE-IDENTICAL between upstream 2.21 and 2.35, so id
		// 2 (native FlxList C struct) serves all four titles; only the
		// obfuscation differs. FlxQuadTree 2.35 differs from 2.21 in exactly one
		// spot — the ctor replaced the fixed `MIN=48` const with a computed
		// static `_min = (width+height)/(2*FlxU.quadTreeDivisions)` — so 2.35
		// uses id 3 (the dynamic-_min native variant in avm2_flixel.c). Both
		// titles leave FlxU.quadTreeDivisions at its default 3.
		{ 0xd2cd8bafd2ca5111ull, 3, "org.flixel::FlxQuadTree (Flixel 2.35, RWF)" },
		{ 0xc15fc34addfdc947ull, 3, "org.flixel::FlxQuadTree (Flixel 2.35, RWIC)" },
		{ 0x83ed6120348d3ae2ull, 2, "org.flixel.data::FlxList (Flixel 2.35, RWF)" },
		{ 0xa76edf059e8264caull, 2, "org.flixel.data::FlxList (Flixel 2.35, RWIC)" },
	};

	static unsigned intrinsicIdForFingerprint(u64 fp)
	{
		if (fp == 0) return 0;   // unhashable body — never match
		for (const IntrinsicEntry& e : INTRINSIC_TABLE)
		{
			if (e.fp != 0 && e.fp == fp) return e.id;
		}
		return 0;
	}

	// Known-arrayToCSV method fingerprints (org.flixel::FlxTilemap.arrayToCSV).
	//
	// Unlike the FlxQuadTree/FlxList gate (which hashes the WHOLE class), this
	// is a METHOD-level gate: the fingerprint is the normalized body hash of
	// the single static method `arrayToCSV`, decoupled from the rest of the
	// large FlxTilemap class (draw/loadMap/updateTile/... carry per-title
	// obfuscation and game tweaks that would poison a whole-class hash). Only
	// the CSV builder itself matters — it is a pure, stateless
	// (Array, int)->String function — so substituting it is safe on a body
	// match regardless of what else FlxTilemap contains.
	//
	// The transient this kills: arrayToCSV builds a tilemap CSV by O(n^2)
	// string `+=` concatenation, three layers per PlayState.create — measured
	// at ~1.7 GB of single-tick garbage on RWIC (see
	// SWFRecompDocs/plans/avm2-browser-footprint.md §2). The native builder
	// (avm2_flixel.c, id 4) writes ONE grow-realloc byte buffer — O(n).
	//
	// id must match avm2_flixel.h: 4 = FlxTilemap.arrayToCSV.
	// The 2.21 titles (RWK/RWP) share a clean identical body; the 2.35 titles
	// (RWF/RWIC) each carry their own opaque-predicate control-flow obfuscation
	// (§§push/§§goto in the decompile) and fingerprint distinctly — one baked
	// constant per obfuscated variant, verified byte-identical output.
	static const IntrinsicEntry ARRAYTOCSV_TABLE[] =
	{
		// Flixel 2.21 — RWK and RWP share ONE constant: the clean upstream
		// body (the `while` loops + `_loc5_ += ...` concat, verified against
		// jpexs output org/flixel/FlxTilemap.as) is byte-identical between the
		// two titles; only the constant pool differs and normalizes out.
		{ 0x1340f1fcfea0a94dull, 4, "org.flixel::FlxTilemap.arrayToCSV (Flixel 2.21, RWK+RWP)" },
		// Flixel 2.35 — RWF and RWIC each carry their own opaque-predicate
		// control-flow obfuscation (the §§push(false)/§§goto jump-threaded
		// decompile), so each fingerprints distinctly. Both were traced to the
		// same clean CSV semantics by opaque-predicate folding (the always-true
		// `_loc7_`/always-false `_loc8_` guards collapse to the 2.21 loop nest);
		// the native builder's output is verified byte-identical per title.
		{ 0x0067a14b337b8c8bull, 4, "org.flixel::FlxTilemap.arrayToCSV (Flixel 2.35, RWF)" },
		{ 0x56e9fc6d17820266ull, 4, "org.flixel::FlxTilemap.arrayToCSV (Flixel 2.35, RWIC)" },
	};

	static unsigned arrayToCSVIdForFingerprint(u64 fp)
	{
		if (fp == 0) return 0;   // unhashable body — never match
		for (const IntrinsicEntry& e : ARRAYTOCSV_TABLE)
		{
			if (e.fp != 0 && e.fp == fp) return e.id;
		}
		return 0;
	}

	// Fingerprint of one class (instance + static halves). 0 = unhashable:
	// any referenced body that failed to hash poisons the whole class.
	static u64 classFingerprint(const AbcFile& abc, size_t class_index,
	                            const std::vector<int>& method_body,
	                            bool verbose = false)
	{
		if (class_index >= abc.instances.size()) return 0;
		const AbcInstance& inst = abc.instances[class_index];

#define FPV(...) do { if (verbose) fprintf(stderr, "FPV " __VA_ARGS__); } while (0)

		u64 h = FNV_OFFSET;
		h = hashStr(h, qualifiedName(abc, inst.name));
		FPV("name=%s h=%016llx\n", qualifiedName(abc, inst.name).c_str(), (unsigned long long) h);
		h = hashStr(h, qualifiedName(abc, inst.super_name));
		FPV("super=%s h=%016llx\n", qualifiedName(abc, inst.super_name).c_str(), (unsigned long long) h);

		u8 flags = 0;
		if (inst.is_sealed) flags |= 1;
		if (inst.is_final) flags |= 2;
		if (inst.is_interface) flags |= 4;
		if (inst.has_protected_ns) flags |= 8;
		h = hashBytes(h, &flags, 1);
		FPV("flags=%u h=%016llx\n", (unsigned) flags, (unsigned long long) h);
		if (verbose && inst.protected_ns < abc.pool.namespaces.size())
		{
			const AbcNamespace& pns = abc.pool.namespaces[inst.protected_ns];
			fprintf(stderr, "FPV protected_ns idx=%u kind=0x%02x name='%s'\n",
			        inst.protected_ns, (unsigned) pns.kind,
			        pns.name < abc.pool.strings.size()
			            ? abc.pool.strings[pns.name].c_str() : "?");
		}
		h = hashU32(h, (u32) inst.interfaces.size());
		for (u32 iface : inst.interfaces)
		{
			h = hashStr(h, qualifiedName(abc, iface));
			FPV("iface=%s h=%016llx\n", qualifiedName(abc, iface).c_str(), (unsigned long long) h);
		}

		// Shared hashing context across every body of THIS class: opaque-ns
		// ordinals and the closure-recursion guard must persist across the
		// instance/static/iinit/cinit bodies (so the same namespace maps to
		// one ordinal class-wide) but never leak between classes.
		FpCtx ctx(abc);
		bool ok = true;
		auto fold_body = [&](u32 method_index)
		{
			if (method_index >= method_body.size() || method_body[method_index] < 0)
			{
				// No body (native/interface method): hash a marker.
				h = hashStr(h, "\x03nobody");
				FPV("  body=NONE h=%016llx\n", (unsigned long long) h);
				return;
			}
			u64 bh = hashMethodBody(ctx, abc.method_bodies[method_body[method_index]]);
			if (bh == 0) ok = false;
			h = hashBytes(h, &bh, sizeof(bh));
			const AbcMethodBody& b = abc.method_bodies[method_body[method_index]];
			if (verbose && getenv("SWFRECOMP_FP_DISASM"))
			{
				string mname;
				if (method_index < abc.methods.size()
				    && abc.methods[method_index].name < abc.pool.strings.size())
					mname = abc.pool.strings[abc.methods[method_index].name];
				disasmBody(abc, b, mname.c_str());
			}
			FPV("  body=%016llx codelen=%zu maxstack=%u nlocals=%u isd=%u msd=%u exc=%zu h=%016llx\n",
			    (unsigned long long) bh, b.code.size(), b.max_stack, b.num_locals,
			    b.init_scope_depth, b.max_scope_depth, b.exceptions.size(),
			    (unsigned long long) h);
		};

		auto fold_traits = [&](const std::vector<AbcTrait>& traits)
		{
			h = hashU32(h, (u32) traits.size());
			FPV("traitcount=%zu h=%016llx\n", traits.size(), (unsigned long long) h);
			for (const AbcTrait& t : traits)
			{
				u8 k = (u8) t.kind;
				h = hashBytes(h, &k, 1);
				// Trait names are QNames; the local name is what source-level
				// identity turns on.
				const auto& MN = abc.pool.multinames;
				const auto& S = abc.pool.strings;
				string local;
				if (t.name != 0 && t.name < MN.size() && MN[t.name].name < S.size())
					local = S[MN[t.name].name];
				h = hashStr(h, local);
				h = hashU32(h, t.slot_or_disp_id);
				h = hashStr(h, qualifiedName(abc, t.type_name));
				FPV("trait kind=%u name=%s qname=%s slot_or_disp=%u type=%s h=%016llx\n",
				    (unsigned) k, local.c_str(), qualifiedName(abc, t.name).c_str(),
				    t.slot_or_disp_id, qualifiedName(abc, t.type_name).c_str(),
				    (unsigned long long) h);
				if (t.kind == TraitKindType::Method || t.kind == TraitKindType::Getter
				    || t.kind == TraitKindType::Setter)
				{
					fold_body(t.method_or_class);
				}
			}
		};

		FPV("--- instance traits ---\n");
		fold_traits(inst.traits);
		if (class_index < abc.classes.size())
		{
			FPV("--- static traits ---\n");
			fold_traits(abc.classes[class_index].traits);
		}

		FPV("--- iinit ---\n");
		fold_body(inst.init_method);
		if (class_index < abc.classes.size())
		{
			FPV("--- cinit ---\n");
			fold_body(abc.classes[class_index].init_method);
		}
#undef FPV

		if (!ok) return 0;
		return h ? h : 1;
	}

	// Method-level fingerprint of a class's static `arrayToCSV` method (the
	// FlxTilemap CSV builder). Returns the normalized body hash of that method,
	// or 0 if the class has no static method named "arrayToCSV" or its body is
	// unhashable (fail safe -> never match). A fresh FpCtx is used, exactly as
	// a standalone method hash: opaque-ns ordinals and the closure guard are
	// scoped to this one body, deterministically across builds.
	static u64 arrayToCSVFingerprint(const AbcFile& abc, size_t class_index,
	                                 const std::vector<int>& method_body)
	{
		if (class_index >= abc.classes.size()) return 0;
		const auto& MN = abc.pool.multinames;
		const auto& S = abc.pool.strings;
		for (const AbcTrait& t : abc.classes[class_index].traits)
		{
			if (t.kind != TraitKindType::Method) continue;
			string local;
			if (t.name != 0 && t.name < MN.size() && MN[t.name].name < S.size())
				local = S[MN[t.name].name];
			if (local != "arrayToCSV") continue;
			u32 method_index = t.method_or_class;
			if (method_index >= method_body.size() || method_body[method_index] < 0)
				return 0;
			FpCtx ctx(abc);
			u64 bh = hashMethodBody(ctx, abc.method_bodies[method_body[method_index]]);
			if (ctx.poisoned) return 0;
			return bh;
		}
		return 0;
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

	AbcEmitter::AbcEmitter(string output_folder, string symbol_prefix,
	                       u32 char_id_base)
		: folder_(std::move(output_folder)),
		  prefix_(std::move(symbol_prefix)),
		  char_id_base_(char_id_base)
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
		// The body has no PushWith → every scope lookup is trait/vtable-based,
		// so a FindProperty scope walk's hit/miss is invariant across
		// activations at a fixed call site (lets the domain inline cache skip
		// the scope walk on a cached hit). See avm2_op_findpropstrict_ic.
		bool scope_stable;
		// SWF_NO_FIND_IC=1 A/B baseline: emit the plain (pre-lever-A) find ops.
		bool find_ic;
	};

	static bool mnLazyName(const AbcFile& abc, u32 mn)
	{
		return abc.pool.multinames[mn].hasLazyName();
	}

	static bool mnLazyNs(const AbcFile& abc, u32 mn)
	{
		return abc.pool.multinames[mn].hasLazyNs();
	}

	// Per-op outputs of the type-specialization pass (analyzeSlotSpec),
	// threaded into emitOp. Defaults = no specialization.
	struct OpSpec
	{
		int slot = -1;            // GetPropertyStatic: bare this.field slot read
		bool elide = false;       // coerce op proven a value no-op
		bool find_this = false;   // find→this substitution
		bool find_skip = false;   // find fused into the next op: emit nothing
		int fused_cls = -1;       // GetPropertyStatic: fused getlex-ownstatic
		int fused_slot = -1;      //   (class index + static cvt slot)
		int findstatic_cls = -1;  // standalone guarded own-static find
		int store_slot = -1;      // Set/InitProperty: compile-time slot store
		u32 store_coerce_mn = 0;  //   declared-type coerce mn (0 = elided)
		// Compare→branch fusion (computed in emitMethodBody): on the COMPARE op,
		// 1 = an IfTrue follows, 2 = an IfFalse follows, with cmp_target the
		// branch's destination. On the fused IfTrue/IfFalse itself, op_skip.
		int cmp_branch = 0;
		u32 cmp_target = 0;
		bool op_skip = false;
	};

	// The `*_test` inline for a comparison opcode (returns a plain int rather
	// than a boxed Avm2Value), or nullptr if the opcode has no fused form.
	static const char* cmpTestHelper(IrOpcode o)
	{
		switch (o)
		{
			case IrOpcode::Equals:        return "avm2_op_equals_test";
			case IrOpcode::StrictEquals:  return "avm2_op_strictequals_test";
			case IrOpcode::LessThan:      return "avm2_op_lessthan_test";
			case IrOpcode::LessEquals:    return "avm2_op_lessequals_test";
			case IrOpcode::GreaterThan:   return "avm2_op_greaterthan_test";
			case IrOpcode::GreaterEquals: return "avm2_op_greaterequals_test";
			default: return nullptr;
		}
	}

	// Compile-time slot store (store-path lever): bare slot write when the
	// declared-type coerce is proven a no-op, else the coercing variant with
	// the declared type's multiname baked in.
	static void emitStoreSlot(ofstream& out, u32 mn, const OpSpec& os, int is_init)
	{
		if (os.store_coerce_mn == 0)
		{
			out << "\tsp -= 2; avm2_op_setproperty_slot(act, stk[sp], "
			    << os.store_slot << ", " << mn << ", stk[sp + 1], "
			    << is_init << ");" << endl;
		}
		else
		{
			out << "\tsp -= 2; avm2_op_setproperty_slot_c(act, stk[sp], "
			    << os.store_slot << ", " << mn << ", " << os.store_coerce_mn
			    << ", stk[sp + 1], " << is_init << ");" << endl;
		}
	}

	// Emits one op's C. Returns false if the op is unsupported (caller
	// emits an inline abort and continues with the next op). `os` carries the
	// type-specialization results for this op (see OpSpec).
	static bool emitOp(ofstream& out, const BodyCtx& bc, const IrOp& op,
	                   const OpSpec& os = OpSpec())
	{
		const AbcFile& abc = *bc.abc;
		const int slotSpec = os.slot;
		const bool elideCoerce = os.elide;
		const bool findThis = os.find_this;
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
			// A branch whose condition came from an immediately preceding
			// comparison was already emitted as part of that compare (see
			// the fusion pass in emitMethodBody); the compare consumed both operands and
			// branched directly, so there is nothing left to do here.
			case IrOpcode::IfTrue:
				if (os.op_skip) return true;
				out << "\tsp--; if (avm2_to_boolean_fast(stk[sp])) goto op_"
				    << op.target << ";" << endl;
				return true;
			case IrOpcode::IfFalse:
				if (os.op_skip) return true;
				out << "\tsp--; if (!avm2_to_boolean_fast(stk[sp])) goto op_"
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
				if (os.find_skip)
				{
					// Fused into the following same-mn GetPropertyStatic
					// (avm2_op_getlex_ownstatic) — that op does the find+read
					// in one guarded step, so nothing is emitted here.
					return true;
				}
				if (os.findstatic_cls >= 0)
				{
					// Own-class-static find with a non-adjacent consumer:
					// guarded class-object fetch with exact FindPropStrict
					// fallback semantics (avm2_ops.h).
					out << "\t{ static Avm2StaticFindCache __sfc; stk[sp++] = "
					       "avm2_object_value(avm2_op_findprop_ownstatic(act, "
					       "lscope, scope_n, " << op.arg1 << ", "
					    << os.findstatic_cls << ", &__sfc)); }" << endl;
					return true;
				}
				if (findThis)
				{
					// Compile-time-resolved: the scope walk provably hits
					// `this` (avm2_op_findprop_this is an identity move of
					// loc[0] outside -DAVM2_FIND_VERIFY builds).
					out << "\tstk[sp++] = avm2_op_findprop_this(act, loc[0], "
					       "lscope, scope_n, " << op.arg1 << ");" << endl;
					return true;
				}
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
				else if (bc.find_ic)
				{
					// Per-call-site domain inline cache (getlex-global lever):
					// a block-scoped static gives each find site its own cache.
					// `scope_stable` lets a cached domain hit skip the scope walk.
					out << "\t{ static Avm2FindCache __fc; stk[sp++] = "
					       "avm2_object_value(avm2_op_findpropstrict_ic(act, lscope, "
					       "scope_n, " << op.arg1 << ", " << strict << ", "
					    << (bc.scope_stable ? 1 : 0) << ", &__fc)); }" << endl;
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
				if (os.fused_cls >= 0)
				{
					// Fused FindPropStrict+GetPropertyStatic of an own-class
					// static slot (the preceding find emitted nothing): one
					// guarded cache probe + static slot read, full-walk
					// fallback inside the op.
					out << "\t{ static Avm2StaticFindCache __sfc; stk[sp++] = "
					       "avm2_op_getlex_ownstatic(act, lscope, scope_n, "
					    << op.arg1 << ", " << os.fused_cls << ", "
					    << os.fused_slot << ", &__sfc); }" << endl;
					return true;
				}
				if (slotSpec >= 0)
				{
					// Type-specialized: receiver is provably `this` and the name
					// is a slot trait at compile-time index slotSpec → bare load.
					out << "\tstk[sp - 1] = avm2_op_getproperty_slot(act, "
					       "stk[sp - 1], " << slotSpec << ", " << op.arg1 << ");"
					    << endl;
					return true;
				}
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
				if (os.store_slot >= 0)
				{
					emitStoreSlot(out, op.arg1, os, /*is_init=*/0);
					return true;
				}
				// Per-call-site monomorphic inline cache (avm2_ops.h), same as
				// GetPropertyStatic: a block-scoped static gives each site a slot.
				out << "\t{ static Avm2InlineCache __ic; sp -= 2; "
				       "avm2_op_setproperty_static_ic(act, stk[sp], " << op.arg1
				    << ", stk[sp + 1], &__ic); }" << endl;
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
				if (mnLazyNs(abc, op.arg1)) return false;
				if (mnLazyName(abc, op.arg1))
				{
					// MultinameL: [obj, name, value]. Init semantics (a const
					// slot is writable) are the only difference from
					// SetPropertySlow's lazy-name arm.
					out << "\tsp -= 3; avm2_op_initproperty_dyn(act, stk[sp], "
					    << op.arg1 << ", stk[sp + 1], stk[sp + 2], "
					    << (bc.interp_mode ? 1 : 0) << ");" << endl;
					return true;
				}
				if (os.store_slot >= 0)
				{
					emitStoreSlot(out, op.arg1, os, /*is_init=*/1);
					return true;
				}
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
					// Per-call-site monomorphic inline cache (avm2_ops.h), same
					// as GetPropertyStatic: block-scoped static per site.
					out << "\t{ static Avm2InlineCache __ic; sp -= " << (op.arg2 + 1)
					    << "; " << (is_void ? "" : "stk[sp] = ")
					    << "avm2_op_callproperty_ic(act, stk[sp], " << op.arg1
					    << ", &stk[sp + 1], " << op.arg2 << ", &__ic);"
					    << (is_void ? "" : " sp++;") << " }" << endl;
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
				if (mnLazyNs(abc, op.arg1)) return false;
				if (mnLazyName(abc, op.arg1))
				{
					// `super[expr]`: [obj, name]
					out << "\tsp -= 2; stk[sp] = avm2_op_getsuper_dyn(act, stk[sp], "
					    << op.arg1 << ", stk[sp + 1]); sp++;" << endl;
					return true;
				}
				out << "\tstk[sp - 1] = avm2_op_getsuper(act, stk[sp - 1], "
				    << op.arg1 << ");" << endl;
				return true;
			case IrOpcode::SetSuper:
				if (mnLazyNs(abc, op.arg1)) return false;
				if (mnLazyName(abc, op.arg1))
				{
					// `super[expr] = v`: [obj, name, value]
					out << "\tsp -= 3; avm2_op_setsuper_dyn(act, stk[sp], " << op.arg1
					    << ", stk[sp + 1], stk[sp + 2]);" << endl;
					return true;
				}
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
			// Comparisons feeding an adjacent branch skip the boxed
			// Avm2Value round-trip entirely: the `_test` inline returns a
			// plain int and the branch is emitted right here.
			case IrOpcode::Equals: case IrOpcode::StrictEquals:
			case IrOpcode::LessThan: case IrOpcode::LessEquals:
			case IrOpcode::GreaterThan: case IrOpcode::GreaterEquals:
				if (os.cmp_branch != 0)
				{
					out << "\tsp -= 2; if ("
					    << (os.cmp_branch == 2 ? "!" : "") << cmpTestHelper(op.op)
					    << "(act, stk[sp], stk[sp + 1])) goto op_"
					    << os.cmp_target << ";" << endl;
					return true;
				}
				out << "\tsp--; stk[sp - 1] = avm2_bool("
				    << cmpTestHelper(op.op) << "(act, stk[sp - 1], stk[sp]));"
				    << endl;
				return true;

#define BINOP(irname, helper) \
			case IrOpcode::irname: \
				out << "\tsp--; stk[sp - 1] = " helper "(act, stk[sp - 1], stk[sp]);" << endl; \
				return true;
			// `add` keeps the generic op — it may concatenate strings or run
			// valueOf, so there is no unconditionally-equivalent fast arm.
			BINOP(Add, "avm2_op_add")
			BINOP(Subtract, "avm2_op_subtract_fast")
			BINOP(Multiply, "avm2_op_multiply_fast")
			BINOP(Divide, "avm2_op_divide_fast")
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
			UNOP(Not, "avm2_op_not_fast")
			UNOP(BitNot, "avm2_op_bitnot")
			UNOP(Increment, "avm2_op_increment_fast")
			UNOP(Decrement, "avm2_op_decrement_fast")
			UNOP(IncrementI, "avm2_op_increment_i")
			UNOP(DecrementI, "avm2_op_decrement_i")
			UNOP(TypeOf, "avm2_op_typeof")
			UNOP(ConvertS, "avm2_op_convert_s")
			UNOP(CoerceO, "avm2_op_coerce_o")
			UNOP(ConvertO, "avm2_op_convert_o")
			UNOP(EscXAttr, "avm2_op_esc_xattr")
			UNOP(EscXElem, "avm2_op_esc_xelem")
#undef UNOP

			// --- Alchemy/CrossBridge memory opcodes (avm2_mops.c) ---
			// Loads and the sign-extends replace the top of stack in
			// place. Stores pop two: the value was pushed first and the
			// address second (ASC compiles SI8(v, addr) in that order),
			// so the address is stk[sp + 1] after the decrement.
#define MOPS_LOAD(irname, helper) \
			case IrOpcode::irname: \
				out << "\tstk[sp - 1] = " helper "(act, stk[sp - 1]);" << endl; \
				return true;
#define MOPS_STORE(irname, helper) \
			case IrOpcode::irname: \
				out << "\tsp -= 2; " helper "(act, stk[sp], stk[sp + 1]);" << endl; \
				return true;
			MOPS_LOAD(Li8, "avm2_op_li8")
			MOPS_LOAD(Li16, "avm2_op_li16")
			MOPS_LOAD(Li32, "avm2_op_li32")
			MOPS_LOAD(Lf32, "avm2_op_lf32")
			MOPS_LOAD(Lf64, "avm2_op_lf64")
			MOPS_LOAD(Sxi1, "avm2_op_sxi1")
			MOPS_LOAD(Sxi8, "avm2_op_sxi8")
			MOPS_LOAD(Sxi16, "avm2_op_sxi16")
			MOPS_STORE(Si8, "avm2_op_si8")
			MOPS_STORE(Si16, "avm2_op_si16")
			MOPS_STORE(Si32, "avm2_op_si32")
			MOPS_STORE(Sf32, "avm2_op_sf32")
			MOPS_STORE(Sf64, "avm2_op_sf64")
#undef MOPS_LOAD
#undef MOPS_STORE

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
			// Each elidable coerce, when the type pass proved it a value no-op,
			// emits a verify hook: a no-op the optimizer removes in the normal
			// build, a real coerce+abort-on-change under -DAVM2_COERCE_VERIFY.
			case IrOpcode::CoerceB:
				out << (elideCoerce
					? "\tstk[sp - 1] = avm2_coerce_verify_b(act, stk[sp - 1]);"
					: "\tstk[sp - 1] = avm2_bool(avm2_coerce_to_boolean(stk[sp - 1]));")
				    << endl;
				return true;
			case IrOpcode::CoerceD:
				out << (elideCoerce
					? "\tstk[sp - 1] = avm2_coerce_verify_d(act, stk[sp - 1]);"
					: "\tstk[sp - 1] = avm2_number(avm2_coerce_to_number(act->ctx, stk[sp - 1]));")
				    << endl;
				return true;
			case IrOpcode::CoerceI:
				out << (elideCoerce
					? "\tstk[sp - 1] = avm2_coerce_verify_i(act, stk[sp - 1]);"
					: "\tstk[sp - 1] = avm2_integer(avm2_coerce_to_i32(act->ctx, stk[sp - 1]));")
				    << endl;
				return true;
			case IrOpcode::CoerceU:
				out << (elideCoerce
					? "\tstk[sp - 1] = avm2_coerce_verify_u(act, stk[sp - 1]);"
					: "\tstk[sp - 1] = avm2_uint_value(avm2_coerce_to_u32(act->ctx, stk[sp - 1]));")
				    << endl;
				return true;
			case IrOpcode::CoerceS:
				if (elideCoerce)
					out << "\tstk[sp - 1] = avm2_coerce_verify_s(act, stk[sp - 1]);" << endl;
				else
					out << "\tstk[sp - 1] = avm2_op_coerce_s(act, stk[sp - 1]);" << endl;
				return true;
			case IrOpcode::Coerce:
				if (elideCoerce)
					out << "\tstk[sp - 1] = avm2_coerce_verify_mn(act, stk[sp - 1], "
					    << op.arg1 << ");" << endl;
				else
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

	// =====================================================================
	// Compile-time type-specialization model (Step 2: emit direct slot reads
	// where the receiver is provably `this`, an instance of a sealed ABC class
	// whose full chain to Object is ABC-defined, and the name is a slot trait).
	// The compile-time slot index is numbered IDENTICALLY to avm2_class.c's
	// ivtable assignment (parent slot_count seed + sequential auto-assign) so
	// `slots[K]` matches the runtime; -DAVM2_SLOT_VERIFY cross-checks every read.
	// =====================================================================

	// Operand-stack pop/push counts, mirroring abc_verifier.cpp stackEffect
	// (scope delta omitted — irrelevant to value-stack depth alignment).
	static void irStackEffect(const IrOp& op, const AbcFile& abc, u32& pops, u32& pushes)
	{
		s32 scope_delta;
		stackEffect(op, abc, pops, pushes, scope_delta);
	}


	// Per-body: for each op index, the compile-time slot index K if the
	// GetPropertyStatic there is a specializable direct slot read (a bare
	// `recv.u.obj->slots[K]` load), else -1. TWO levers, one forward
	// abstract-interpretation over the operand stack (each slot tagged with its
	// compile-time provenance; a store into any local can't leak a tag because
	// tags live only on the stack, and `this`/a Class object is invariant on
	// every path):
	//   (A) this.field  — receiver is `this` (local 0 of a sealed instance
	//       method that never writes local 0), name resolves uniquely to a
	//       slot/const trait, no subclass redeclares it (Step 2).
	//   (B) Class.staticField — receiver is a compile-time-known Class object (a
	//       `getlex ClassName` result = FindPropStrict(mn)+GetPropertyStatic(mn)
	//       of a UNIQUE user-class name), name is a static Slot/Const trait; the
	//       class object is a singleton and statics aren't inherited/overridden,
	//       so the static slot index is exact (Step 3 lever B).
	// Additionally (Step 4) the SAME pass tracks a STATIC TYPE per stack slot /
	// local and marks each coerce_* / coerce_return site whose operand already
	// has the target static type as `elide` — the coercion is a proven value
	// no-op the emitter drops (verified end-to-end by -DAVM2_COERCE_VERIFY).
	struct SlotSpecResult
	{
		std::vector<int> slot;    // GetPropertyStatic direct-slot index, or -1
		std::vector<char> elide;  // coerce/coerce_return proven redundant here
		// FindPropStrict/FindProperty proven to resolve to `this` (the
		// find→this lever): emit a loc[0] push instead of the scope walk.
		std::vector<char> find_this;
		// find→own-class-static lever: at a find index, find_skip means the
		// find is FUSED into the next op (emit nothing); at the following
		// GetPropertyStatic index, fused_cls/fused_slot carry the enclosing
		// class index + static cvt slot for avm2_op_getlex_ownstatic. For
		// own-static finds with a non-adjacent consumer, findstatic_cls at
		// the find index emits the standalone guarded find
		// (avm2_op_findprop_ownstatic — exact FindPropStrict semantics).
		std::vector<char> find_skip;
		std::vector<int> fused_cls;
		std::vector<int> fused_slot;
		std::vector<int> findstatic_cls;
		// Store-path lever: at a SetPropertyStatic/InitProperty index,
		// store_slot >= 0 emits the compile-time slot store; store_coerce_mn
		// carries the declared-type multiname for the kept coerce, or 0 when
		// the coerce is proven a value no-op (or the slot is untyped).
		std::vector<int> store_slot;
		std::vector<u32> store_coerce_mn;
	};
	// --- Step-0 census for the typed-value levers (temp tool, env-gated:
	// SWF_CENSUS_TYPEDOPS=<csv path>). Read-only: it reports the static operand
	// types the lattice ALREADY computes at every branch / compare / arithmetic
	// site, so each lever's build decision is a hot-weighted coverage number
	// rather than a site count. Mirrors the SWF_CENSUS_PROPREAD pattern.
	// Columns: method,op_index,opcode,left_type,right_type
	static const char* tkName(TK k)
	{
		switch (k)
		{
			case TK_INT:  return "int";
			case TK_UINT: return "uint";
			case TK_NUM:  return "Number";
			case TK_BOOL: return "Boolean";
			case TK_STR:  return "String";
			case TK_INST: return "inst";
			case TK_NULL: return "null";
			default:      return "unk";
		}
	}
	// Census-relevant opcodes and their operand count (0 = not of interest).
	static const char* typedOpName(IrOpcode o, int& arity)
	{
		arity = 2;
		switch (o)
		{
			case IrOpcode::Equals:        return "equals";
			case IrOpcode::StrictEquals:  return "strictequals";
			case IrOpcode::LessThan:      return "lessthan";
			case IrOpcode::LessEquals:    return "lessequals";
			case IrOpcode::GreaterThan:   return "greaterthan";
			case IrOpcode::GreaterEquals: return "greaterequals";
			case IrOpcode::Add:           return "add";
			case IrOpcode::Subtract:      return "subtract";
			case IrOpcode::Multiply:      return "multiply";
			case IrOpcode::Divide:        return "divide";
			case IrOpcode::Modulo:        return "modulo";
			default: break;
		}
		arity = 1;
		switch (o)
		{
			case IrOpcode::IfTrue:    return "iftrue";
			case IrOpcode::IfFalse:   return "iffalse";
			case IrOpcode::Not:       return "not";
			case IrOpcode::Increment: return "increment";
			case IrOpcode::Decrement: return "decrement";
			case IrOpcode::Negate:    return "negate";
			default: break;
		}
		arity = 0;
		return nullptr;
	}
	static ofstream* typedOpCensus()
	{
		static ofstream* out = [] () -> ofstream* {
			const char* p = getenv("SWF_CENSUS_TYPEDOPS");
			if (p == nullptr) return nullptr;
			ofstream* f = new ofstream(p, std::ios::app);
			return f->good() ? f : nullptr;
		} ();
		return out;
	}

	static SlotSpecResult analyzeSlotSpec(const AbcTypeModel& M, const AbcFile& abc,
	                                      const EmitBody& body)
	{
		SlotSpecResult R;
		R.slot.assign(body.ir.ops.size(), -1);
		R.elide.assign(body.ir.ops.size(), 0);
		R.find_this.assign(body.ir.ops.size(), 0);
		R.find_skip.assign(body.ir.ops.size(), 0);
		R.fused_cls.assign(body.ir.ops.size(), -1);
		R.fused_slot.assign(body.ir.ops.size(), -1);
		R.findstatic_cls.assign(body.ir.ops.size(), -1);
		R.store_slot.assign(body.ir.ops.size(), -1);
		R.store_coerce_mn.assign(body.ir.ops.size(), 0);
		std::vector<int>& spec = R.slot;
		if (!body.verified) return R;
		// A/B baseline toggles (interleaved before/after measurement):
		//   SWF_NO_SLOT_SPEC     disables BOTH slot levers (pre-slot build).
		//   SWF_NO_STATIC_SLOT   disables lever B only (lever-A/this-field base).
		//   SWF_NO_COERCE_ELIDE  disables coerce elision only (Step-4 baseline).
		//   SWF_NO_FIND_THIS     disables the find→this substitution only.
		//   SWF_NO_FIND_STATIC   disables the find→own-class-static lever only.
		//   SWF_NO_SET_SLOT      disables the store-path slot lever only.
		static const bool slot_all_disabled = getenv("SWF_NO_SLOT_SPEC") != nullptr;
		static const bool staticB_disabled = getenv("SWF_NO_STATIC_SLOT") != nullptr;
		static const bool coerce_disabled = getenv("SWF_NO_COERCE_ELIDE") != nullptr;
		static const bool findthis_disabled = getenv("SWF_NO_FIND_THIS") != nullptr;
		static const bool findstatic_disabled = getenv("SWF_NO_FIND_STATIC") != nullptr;
		static const bool setslot_disabled = getenv("SWF_NO_SET_SLOT") != nullptr;
		const bool coerce_enabled = !coerce_disabled;

		// Defining class + this-kind (needed for BOTH slot lever A and the
		// coerce `this`/param type seeds).
		auto mit = M.m2c.find(body.ir.method_index);
		bool instMethod = mit != M.m2c.end() && mit->second.inst && mit->second.cls >= 0;
		int thisCls = instMethod ? mit->second.cls : -1;

		// Shared body scans: local-0 rewrites, scope-op shape, activation.
		bool local0_written = false, only_preamble_scope = true, has_act = false;
		for (size_t oi = 0; oi < body.ir.ops.size(); oi++)
		{
			const IrOp& op = body.ir.ops[oi];
			switch (op.op) {
				case IrOpcode::SetLocal: case IrOpcode::Kill:
				case IrOpcode::IncLocal: case IrOpcode::DecLocal:
				case IrOpcode::IncLocalI: case IrOpcode::DecLocalI:
					if (op.arg1 == 0) local0_written = true; break;
				case IrOpcode::HasNext2:
					if (op.arg1 == 0 || op.arg2 == 0) local0_written = true; break;
				case IrOpcode::PushScope:
					if (oi != 1) only_preamble_scope = false; break;
				case IrOpcode::PushWith: case IrOpcode::PopScope:
					only_preamble_scope = false; break;
				case IrOpcode::NewActivation: has_act = true; break;
				default: break;
			}
		}

		// Lever A (this.field slot) gating — enables the is_this SLOT tag only.
		// (`this`'s TYPE is seeded independently below and survives local-0
		// writes via the branch-target reset, so it needs no such gate.)
		bool this_lever = !slot_all_disabled && instMethod && M.isSealed(thisCls)
		               && !local0_written;
		bool staticB_lever = !slot_all_disabled && !staticB_disabled;

		// find→this gate (see avm2_op_findprop_this in avm2_ops.h for the full
		// soundness argument): canonical GetLocal0+PushScope preamble as the
		// body's ONLY scope ops, no with/activation, no active exceptions,
		// local 0 never rewritten. Branch targets into the preamble are
		// excluded below (after targets are collected). Sites additionally
		// require the multiname to match a declared instance trait of the
		// enclosing class (chainDefinesMn, ns-aware).
		bool active_exc = false;
		for (const IrException& e : body.ir.exceptions)
			if (e.active) active_exc = true;
		bool preamble_gate = instMethod
			&& !local0_written && only_preamble_scope && !has_act && !active_exc
			&& body.ir.ops.size() >= 2
			&& body.ir.ops[0].op == IrOpcode::GetLocal
			&& body.ir.ops[0].arg1 == 0
			&& body.ir.ops[1].op == IrOpcode::PushScope;
		bool findthis_gate = preamble_gate && !findthis_disabled;
		// find→own-class-static (same walk-order proof as find→this; the
		// runtime op is additionally self-guarding, so this gate only limits
		// emission to sites where the fast path is provably the common case).
		bool findstatic_gate = preamble_gate && !findstatic_disabled;
		bool setslot_lever = !setslot_disabled;

		if (!this_lever && !staticB_lever && !coerce_enabled && !findthis_gate
		    && !findstatic_gate && !setslot_lever)
			return R;

		// Per-stack-slot value: compile-time provenance (is_this/fp_mn/cls, all
		// path-invariant by construction) plus a static TYPE (NOT path-invariant
		// — reset at branch-target merges below).
		struct SV { bool is_this = false; int fp_mn = -1; int cls = -1; TV type; };
		std::vector<SV> st;
		auto pop = [&]() -> SV { if (st.empty()) return SV{}; SV v = st.back(); st.pop_back(); return v; };
		auto push = [&](SV v) { st.push_back(v); };
		auto peek = [&](u32 depthFromTop) -> SV {
			return depthFromTop < st.size() ? st[st.size() - 1 - depthFromTop] : SV{};
		};

		// Local static types, seeded from `this` and the declared param types
		// (params are coerced to their declared type on method entry — a sound
		// seed). A local that is ever written is not path-invariant, so its
		// type is cleared at every branch-target merge (join = unknown).
		u32 bi = body.ir.body_index;
		u32 num_locals = (bi < abc.method_bodies.size() && abc.method_bodies[bi].num_locals > 0)
			? abc.method_bodies[bi].num_locals : 1;
		std::vector<TV> localTy(num_locals);
		std::vector<char> localWritten(num_locals, 0);
		if (instMethod && num_locals > 0) localTy[0] = TV{ TK_INST, thisCls };
		const AbcMethod& meth = abc.methods[body.ir.method_index];
		for (size_t k = 0; k < meth.params.size() && (k + 1) < num_locals; k++)
			localTy[k + 1] = M.typeOfMn(meth.params[k].type);
		auto markWritten = [&](u32 l) { if (l < localWritten.size()) localWritten[l] = 1; };
		for (const IrOp& op : body.ir.ops)
			switch (op.op) {
				case IrOpcode::SetLocal: case IrOpcode::Kill: case IrOpcode::IncLocal:
				case IrOpcode::DecLocal: case IrOpcode::IncLocalI: case IrOpcode::DecLocalI:
					markWritten(op.arg1); break;
				case IrOpcode::HasNext2: markWritten(op.arg1); markWritten(op.arg2); break;
				default: break;
			}

		// Branch/switch/exception targets — at each, the operand stack and any
		// written local carry the JOIN of predecessors, which the linear pass
		// cannot compute, so their static types are reset to UNKNOWN.
		std::set<u32> targets;
		for (const IrOp& op : body.ir.ops)
			switch (op.op) {
				case IrOpcode::Jump: case IrOpcode::IfTrue: case IrOpcode::IfFalse:
					targets.insert(op.target); break;
				case IrOpcode::LookupSwitch:
					targets.insert(op.target);
					for (u32 t : op.switch_targets) targets.insert(t);
					break;
				default: break;
			}
		for (const IrException& e : body.ir.exceptions)
			if (e.active) targets.insert(e.target_op);

		// A branch back into the preamble would re-run GetLocal0+PushScope and
		// grow the scope stack — the [this]-only scope shape is no longer
		// proven, so the find→this and find→own-class-static gates close.
		if (targets.count(0u) || targets.count(1u))
		{
			findthis_gate = false;
			findstatic_gate = false;
		}

		// Static type produced by a generic (depth-preserving) op that pushes a
		// value. Only sound, path-independent results.
		auto resultTypeGeneric = [&](const IrOp& op) -> TV {
			switch (op.op) {
				case IrOpcode::PushNull: return TV{ TK_NULL };
				case IrOpcode::PushInt: return TV{ TK_INT };
				case IrOpcode::PushUint: return TV{ TK_UINT };
				case IrOpcode::PushDouble: case IrOpcode::PushNaN: return TV{ TK_NUM };
				case IrOpcode::PushString: return TV{ TK_STR };
				case IrOpcode::PushTrue: case IrOpcode::PushFalse: return TV{ TK_BOOL };
				case IrOpcode::AddI: case IrOpcode::SubtractI: case IrOpcode::MultiplyI:
				case IrOpcode::IncrementI: case IrOpcode::DecrementI: case IrOpcode::NegateI:
				case IrOpcode::BitNot: case IrOpcode::BitAnd: case IrOpcode::BitOr:
				case IrOpcode::BitXor: case IrOpcode::LShift: case IrOpcode::RShift:
					return TV{ TK_INT };
				case IrOpcode::URShift: return TV{ TK_UINT };
				case IrOpcode::Subtract: case IrOpcode::Multiply: case IrOpcode::Divide:
				case IrOpcode::Modulo: case IrOpcode::Negate: case IrOpcode::Increment:
				case IrOpcode::Decrement:
					return TV{ TK_NUM };
				case IrOpcode::Not: case IrOpcode::Equals: case IrOpcode::StrictEquals:
				case IrOpcode::LessThan: case IrOpcode::LessEquals: case IrOpcode::GreaterThan:
				case IrOpcode::GreaterEquals: case IrOpcode::In: case IrOpcode::InstanceOf:
				case IrOpcode::IsType: case IrOpcode::IsTypeLate:
					return TV{ TK_BOOL };
				case IrOpcode::TypeOf: case IrOpcode::ConvertS: return TV{ TK_STR };
				case IrOpcode::ConstructProp: return M.typeOfMn(op.arg1);
				default: return TV{};
			}
		};

		for (size_t i = 0; i < body.ir.ops.size(); i++)
		{
			const IrOp& op = body.ir.ops[i];
			if (targets.count((u32) i))
			{
				for (SV& s : st) s.type = TV{};
				for (u32 l = 0; l < localTy.size(); l++)
					if (localWritten[l]) localTy[l] = TV{};
			}
			// Step-0 census: record operand static types BEFORE the op pops
			// them (the branch-target reset above has already been applied, so
			// these are exactly the types a lever would see at this site).
			if (ofstream* cens = typedOpCensus())
			{
				int arity = 0;
				if (const char* nm = typedOpName(op.op, arity))
				{
					// peek(0) is the stack top = the RIGHT operand.
					const char* rhs = tkName(peek(0).type.k);
					const char* lhs = arity == 2 ? tkName(peek(1).type.k) : "-";
					if (arity == 1) { lhs = rhs; rhs = "-"; }
					*cens << body.ir.method_index << ',' << i << ',' << nm
					      << ',' << lhs << ',' << rhs << '\n';
				}
			}
			if (op.op == IrOpcode::GetLocal)
			{
				SV v; v.is_this = this_lever && op.arg1 == 0;
				if (op.arg1 < localTy.size()) v.type = localTy[op.arg1];
				push(v); continue;
			}
			if (op.op == IrOpcode::SetLocal)
			{
				SV v = pop();
				if (op.arg1 < localTy.size()) localTy[op.arg1] = v.type;
				continue;
			}
			if (op.op == IrOpcode::Dup) { push(st.empty() ? SV{} : st.back()); continue; }
			// FindPropStrict/FindProperty of a static (non-lazy) multiname:
			// when the find→this gate holds and the multiname matches a
			// declared instance trait of the enclosing class, the walk
			// provably resolves to `this` — mark the site for substitution
			// and tag the result as `this` (typed), so a following
			// GetPropertyStatic slot-specializes through the lever-A path.
			// Otherwise tag the result with the multiname so a following
			// GetPropertyStatic of the same mn (the getlex pattern) is
			// recognized as a class load.
			if ((op.op == IrOpcode::FindPropStrict || op.op == IrOpcode::FindProperty)
			    && !mnLazyNs(abc, op.arg1) && !mnLazyName(abc, op.arg1))
			{
				if (findthis_gate && i >= 2 && M.chainDefinesMn(thisCls, op.arg1))
				{
					R.find_this[i] = 1;
					SV v; v.is_this = this_lever;
					v.type = TV{ TK_INST, thisCls };
					push(v); continue;
				}
				// find→own-class-static: the multiname does NOT match the
				// instance chain (the walk's `this` probe misses in the ABC
				// view; the runtime cache guards re-verify) and resolves to
				// a static Slot/Const of the enclosing class (ns-aware, cvt
				// slot index computable) — the walk provably hits the class
				// object at the top of the outer chain. An immediately
				// following same-mn GetPropertyStatic fuses into one slot
				// read; any other consumer gets the standalone guarded find.
				if (findstatic_gate && i >= 2
				    && !M.chainDefinesMn(thisCls, op.arg1))
				{
					AbcTypeModel::StaticSlot ss =
						M.staticSlotForMn(thisCls, op.arg1);
					if (ss.ok)
					{
						bool adj = i + 1 < body.ir.ops.size()
							&& body.ir.ops[i + 1].op == IrOpcode::GetPropertyStatic
							&& body.ir.ops[i + 1].arg1 == op.arg1
							&& !targets.count((u32) (i + 1));
						if (adj)
						{
							R.find_skip[i] = 1;
							R.fused_cls[i + 1] = thisCls;
							R.fused_slot[i + 1] = ss.K;
						}
						else
						{
							R.findstatic_cls[i] = thisCls;
						}
						SV v; v.fp_mn = (int) op.arg1; push(v); continue;
					}
				}
				SV v; v.fp_mn = (int) op.arg1; push(v); continue;
			}
			if (op.op == IrOpcode::GetPropertyStatic)
			{
				if (R.fused_cls[i] >= 0)
				{
					// Fused getlex-ownstatic read: type the result as the
					// static slot's declared type (feeds coerce elision).
					pop();
					AbcTypeModel::StaticSlot ss =
						M.staticSlotForMn(thisCls, op.arg1);
					SV res;
					if (ss.ok) res.type = M.typeOfMn(ss.type_mn);
					push(res);
					continue;
				}
				SV recv = pop();
				SV res;   // provenance + type of the produced value
				if (recv.is_this)
				{
					// Lever A: this.field.
					string name = M.localName(op.arg1);
					AbcTypeModel::Found fnd = M.findUniqueSlot(thisCls, name, op.arg1);
					int K = (fnd.ok && !M.subclassRedeclares(thisCls, name))
						? M.computeSlotIndex(fnd.declInst, fnd.traitIdx) : -1;
					if (K > 0) spec[i] = K;
				}
				else if (recv.fp_mn == (int) op.arg1)
				{
					// getlex ClassName: FindPropStrict(mn)+GetPropertyStatic(mn).
					// The read itself is NOT a slot access (it reads the class off
					// the global); tag the RESULT as the known Class object.
					int c = staticB_lever
						? M.uniqueClassByName(M.localName(op.arg1)) : -1;
					if (c >= 0) res.cls = c;
				}
				else if (recv.cls >= 0)
				{
					// Lever B: Class.staticField on a compile-time-known class.
					int K = M.computeStaticSlotIndex(recv.cls, M.localName(op.arg1));
					if (K > 0) spec[i] = K;
				}
				// Static type of the read value (any receiver whose static type
				// is a known instance) → seeds coerce elision on `return this.x`.
				if (recv.type.k == TK_INST)
					res.type = M.memberReadType(recv.type.inst, M.localName(op.arg1));
				push(res);
				continue;
			}
			// Coerce sites: elide when the operand already has the target type.
			if (op.op == IrOpcode::Coerce || op.op == IrOpcode::CoerceD
			    || op.op == IrOpcode::CoerceI || op.op == IrOpcode::CoerceU
			    || op.op == IrOpcode::CoerceB || op.op == IrOpcode::CoerceS)
			{
				TV S = peek(0).type;
				TV T = op.op == IrOpcode::Coerce ? M.typeOfMn(op.arg1)
				     : op.op == IrOpcode::CoerceD ? TV{ TK_NUM }
				     : op.op == IrOpcode::CoerceI ? TV{ TK_INT }
				     : op.op == IrOpcode::CoerceU ? TV{ TK_UINT }
				     : op.op == IrOpcode::CoerceB ? TV{ TK_BOOL }
				     : TV{ TK_STR };
				if (coerce_enabled && M.coerceIsNoop(S, T)) R.elide[i] = 1;
				pop(); SV r; r.type = T; push(r);
				continue;
			}
			// CallProperty: type the result as the callee's declared return type
			// (enables `return this.foo()` elision).
			if (op.op == IrOpcode::CallProperty && !mnLazyNs(abc, op.arg1)
			    && !mnLazyName(abc, op.arg1))
			{
				SV recv = peek(op.arg2);   // receiver sits below the args
				u32 pops, pushes; irStackEffect(op, abc, pops, pushes);
				for (u32 k = 0; k < pops; k++) pop();
				SV r;
				if (recv.type.k == TK_INST)
					r.type = M.memberReadType(recv.type.inst, M.localName(op.arg1));
				for (u32 k = 0; k < pushes; k++) push(k + 1 == pushes ? r : SV{});
				continue;
			}
			if (op.op == IrOpcode::ReturnValue)
			{
				TV S = peek(0).type;
				if (coerce_enabled
				    && M.coerceIsNoop(S, M.typeOfMn(meth.return_type)))
					R.elide[i] = 1;
				pop();
				continue;
			}
			// Store-path slot specialization: receiver is `this` (directly or
			// via a find→this-substituted find, both carry is_this under the
			// lever-A gates) or a statically-typed ABC instance; the name
			// resolves to a unique slot under the GET-lever gate list. The
			// declared-type coerce is kept (compile-time type mn) unless the
			// operand's static type proves it a value no-op.
			if ((op.op == IrOpcode::SetPropertyStatic
			     || op.op == IrOpcode::InitProperty)
			    && !mnLazyNs(abc, op.arg1) && !mnLazyName(abc, op.arg1))
			{
				SV val = pop();
				SV recv = pop();
				if (setslot_lever)
				{
					int C = recv.is_this ? thisCls
					      : (recv.type.k == TK_INST ? recv.type.inst : -1);
					if (C >= 0)
					{
						AbcTypeModel::InstSlot isl =
							M.instSlotForStore(C, op.arg1);
						if (isl.ok
						    && !(isl.is_const
						         && op.op == IrOpcode::SetPropertyStatic))
						{
							R.store_slot[i] = isl.K;
							TV declT = M.typeOfMn(isl.type_mn);
							bool elide = isl.type_mn == 0
								|| M.coerceIsNoop(val.type, declT);
							R.store_coerce_mn[i] = elide ? 0 : isl.type_mn;
						}
					}
				}
				continue;
			}
			// Add is Number ONLY when both operands are numeric (else it may be
			// string concatenation); typing it lets the redundant `coerce
			// Number` the ABC compiler leaves after numeric `a + b` elide.
			if (op.op == IrOpcode::Add)
			{
				auto numeric = [](TK k) { return k == TK_INT || k == TK_UINT || k == TK_NUM; };
				bool both = numeric(peek(0).type.k) && numeric(peek(1).type.k);
				pop(); pop(); SV r; if (both) r.type = TV{ TK_NUM }; push(r);
				continue;
			}
			u32 pops, pushes; irStackEffect(op, abc, pops, pushes);
			for (u32 k = 0; k < pops; k++) pop();
			TV rt = pushes ? resultTypeGeneric(op) : TV{};
			for (u32 k = 0; k < pushes; k++)
			{
				SV r; if (k + 1 == pushes) r.type = rt; push(r);
			}
		}
		return R;
	}

	static void emitMethodBody(ofstream& out, const AbcFile& abc, const EmitBody& body,
	                           const string& fn_name, u32 method_index,
	                           const string& exc_sym, const AbcTypeModel* typeModel)
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
		// A/B baseline toggle for lever A (getlex-global domain inline cache).
		static const bool find_ic_disabled = getenv("SWF_NO_FIND_IC") != nullptr;
		bc.find_ic = !find_ic_disabled;
		// with-free ⟹ every scope lookup is trait/vtable-based ⟹ the find
		// scope walk is invariant per site, so a cached domain hit may skip it.
		bc.scope_stable = true;
		for (const IrOp& op : body.ir.ops)
		{
			if (op.op == IrOpcode::PushWith) { bc.scope_stable = false; break; }
		}
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

		// Compile-time slot indices for specializable reads + coerce-elision
		// flags for proven-redundant coerce_* / coerce_return sites.
		SlotSpecResult spec;
		if (typeModel) spec = analyzeSlotSpec(*typeModel, abc, body);
		else { spec.slot.assign(body.ir.ops.size(), -1);
		       spec.elide.assign(body.ir.ops.size(), 0);
		       spec.find_this.assign(body.ir.ops.size(), 0);
		       spec.find_skip.assign(body.ir.ops.size(), 0);
		       spec.fused_cls.assign(body.ir.ops.size(), -1);
		       spec.fused_slot.assign(body.ir.ops.size(), -1);
		       spec.findstatic_cls.assign(body.ir.ops.size(), -1);
		       spec.store_slot.assign(body.ir.ops.size(), -1);
		       spec.store_coerce_mn.assign(body.ir.ops.size(), 0); }

		// Compare→branch fusion (structural — independent of the type
		// lattice). The ABC verifier splits every compare-and-branch bytecode
		// (iflt/ifnlt/ifeq/...) into a comparison op immediately followed by
		// IfTrue/IfFalse, so the pair is the dominant branch shape. Fusing
		// them removes the avm2_bool() boxing of the comparison result and
		// the avm2_coerce_to_boolean() that would read it straight back.
		// Not fused when the branch is itself a branch target (something else
		// jumps to it, so the compare's operands would not be on the stack)
		// or when exception bookkeeping needs a per-op index for the branch.
		std::vector<int> cmp_branch(body.ir.ops.size(), 0);
		std::vector<u32> cmp_target(body.ir.ops.size(), 0);
		std::vector<char> op_skip(body.ir.ops.size(), 0);
		if (!bc.has_exc)
		{
			for (size_t i = 0; i + 1 < body.ir.ops.size(); i++)
			{
				if (cmpTestHelper(body.ir.ops[i].op) == nullptr) continue;
				const IrOp& nx = body.ir.ops[i + 1];
				if (nx.op != IrOpcode::IfTrue && nx.op != IrOpcode::IfFalse) continue;
				if (targets.count((u32) (i + 1))) continue;
				cmp_branch[i] = nx.op == IrOpcode::IfTrue ? 1 : 2;
				cmp_target[i] = nx.target;
				op_skip[i + 1] = 1;
			}
		}

		// Big-literal collapse. An AS3 array/vector literal emits one
		// `Dup / PushInt <index> / PushInt <value> / SetProperty` quad per
		// element. as3/Vector/initializer_large_vector has 250,000 of them,
		// which expands to a 2-million-line C function that makes gcc ICE
		// (cc1 segfault) even at -O0 — there is no compiler-flag workaround.
		// A run of consecutive-index writes of int constants through one
		// multiname collapses to a static table plus a loop: same semantics,
		// same order, ~1/60th the code. Generic AOT hygiene, not test-only —
		// any content with a big literal table hits the same wall.
		// DebugLine ops interleave inside the run and are skipped (they emit
		// nothing). Bodies with an exception table are left alone: they need
		// a per-op `_tf.op_index`, which a collapsed loop cannot carry.
		struct LitRun { u32 mn; s32 base; size_t end; std::vector<s32> vals; };
		std::map<size_t, LitRun> lit_runs;
		std::vector<char> lit_skip(body.ir.ops.size(), 0);
		if (!bc.has_exc)
		{
			const size_t kMinRun = 64;
			const size_t n_ops = body.ir.ops.size();
			auto nextReal = [&](size_t k)
			{
				while (k < n_ops && (body.ir.ops[k].op == IrOpcode::DebugLine
				                     || body.ir.ops[k].op == IrOpcode::Nop))
				{
					k++;
				}
				return k;
			};
			size_t i = 0;
			while (i < n_ops)
			{
				if (body.ir.ops[i].op != IrOpcode::Dup) { i++; continue; }
				std::vector<s32> vals;
				u32 mn = 0;
				s32 base = 0;
				size_t last_end = 0;
				size_t p = i;
				while (p < n_ops)
				{
					if (!vals.empty() && targets.count((u32) p)) break;
					if (body.ir.ops[p].op != IrOpcode::Dup) break;
					size_t q = nextReal(p + 1);
					if (q >= n_ops || body.ir.ops[q].op != IrOpcode::PushInt) break;
					size_t r = nextReal(q + 1);
					if (r >= n_ops || body.ir.ops[r].op != IrOpcode::PushInt) break;
					size_t s = nextReal(r + 1);
					if (s >= n_ops) break;
					const IrOp& so = body.ir.ops[s];
					if (so.op != IrOpcode::SetPropertyFast
					    && so.op != IrOpcode::SetPropertySlow) break;
					if (mnLazyNs(abc, so.arg1)) break;
					if (vals.empty()) { mn = so.arg1; base = body.ir.ops[q].imm; }
					else if (so.arg1 != mn) break;
					if (body.ir.ops[q].imm != base + (s32) vals.size()) break;
					bool tgt = false;
					for (size_t k = p + 1; k <= s; k++)
					{
						if (targets.count((u32) k)) { tgt = true; break; }
					}
					if (tgt) break;
					vals.push_back(body.ir.ops[r].imm);
					last_end = s;
					p = nextReal(s + 1);
				}
				if (vals.size() >= kMinRun)
				{
					LitRun run;
					run.mn = mn;
					run.base = base;
					run.end = last_end;
					run.vals = vals;
					lit_runs[i] = run;
					for (size_t k = i + 1; k <= last_end; k++) lit_skip[k] = 1;
					i = last_end + 1;
					continue;
				}
				i++;
			}
		}

		for (size_t i = 0; i < body.ir.ops.size(); i++)
		{
			if (lit_skip[i]) continue;
			const IrOp& op = body.ir.ops[i];
			if (targets.count((u32) i))
			{
				out << "op_" << i << ":;" << endl;
			}
			{
				std::map<size_t, LitRun>::const_iterator lr = lit_runs.find(i);
				if (lr != lit_runs.end())
				{
					const LitRun& run = lr->second;
					const string sym = "__vlit" + to_string(method_index) + "_"
					                   + to_string(i);
					out << "\t// " << i << ".." << run.end << ": "
					    << run.vals.size() << " consecutive index writes "
					    << "(base " << run.base << ") collapsed into a table"
					    << endl;
					out << "\tstatic const int32_t " << sym << "[] = {";
					for (size_t k = 0; k < run.vals.size(); k++)
					{
						if (k % 16 == 0) out << endl << "\t\t";
						out << run.vals[k] << ",";
					}
					out << endl << "\t};" << endl
					    << "\tfor (uint32_t __li = 0; __li < " << run.vals.size()
					    << "u; __li++)" << endl
					    << "\t{" << endl
					    << "\t\tavm2_op_setproperty_dyn(act, stk[sp - 1], "
					    << run.mn << ", avm2_integer(" << run.base
					    << " + (int32_t) __li), avm2_integer(" << sym
					    << "[__li]), " << (bc.interp_mode ? 1 : 0) << ");" << endl
					    << "\t}" << endl;
					continue;
				}
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
					// Elided when the returned value's static type already equals
					// the return type — the verify hook is a no-op normally and
					// a real coerce+abort-on-change under -DAVM2_COERCE_VERIFY.
					const char* rc = spec.elide[i]
						? "avm2_coerce_verify_return" : "avm2_op_coerce_return";
					out << " _rv = " << rc << "(act, " << mi_str << ", _rv);";
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

			OpSpec os;
			os.slot = spec.slot[i];
			os.elide = spec.elide[i] != 0;
			os.find_this = spec.find_this[i] != 0;
			os.find_skip = spec.find_skip[i] != 0;
			os.fused_cls = spec.fused_cls[i];
			os.fused_slot = spec.fused_slot[i];
			os.findstatic_cls = spec.findstatic_cls[i];
			os.store_slot = spec.store_slot[i];
			os.store_coerce_mn = spec.store_coerce_mn[i];
			os.cmp_branch = cmp_branch[i];
			os.cmp_target = cmp_target[i];
			os.op_skip = op_skip[i] != 0;
			if (!emitOp(out, bc, op, os))
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

	// =====================================================================
	// READ-ONLY SCOUT (Step 1, compile-time type-specialization gate).
	// Env-gated: set SWF_SCOUT_TYPES=<csv path>. Runs a lightweight forward
	// abstract-interpretation over each verified method body, tracking a
	// STATIC type per operand-stack slot / local, and at every static
	// property op (GetPropertyStatic / SetPropertyStatic / CallProperty /
	// CallPropVoid) classifies the receiver: is its static type a known user
	// class, is that class sealed (non-dynamic), and does the accessed name
	// resolve to a SLOT/CONST trait (the direct-slot lever) vs a
	// getter/setter/method/dynamic. Emits one CSV row per site occurrence.
	// Does NOT change emission — purely diagnostic.
	// =====================================================================
	namespace {
		enum AVKind { AV_UNK = 0, AV_INST = 1, AV_CLS = 2, AV_SCOPE = 3 };
		struct AV { u8 k = AV_UNK; int c = -1; u32 mn = 0; };

		static void scoutStaticTypes(const AbcFile& abc,
		                             const std::vector<EmitBody>& bodies,
		                             const char* path)
		{
			const auto& S = abc.pool.strings;
			const auto& MN = abc.pool.multinames;
			auto mnLocalName = [&](u32 mi) -> string {
				if (mi == 0 || mi >= MN.size()) return "";
				u32 s = MN[mi].name;
				return (s < S.size()) ? S[s] : "";
			};
			// user-class-name -> instance index (first wins)
			std::map<string, int> nameToInst;
			for (size_t i = 0; i < abc.instances.size(); i++)
			{
				string nm = mnLocalName(abc.instances[i].name);
				if (!nm.empty() && nameToInst.find(nm) == nameToInst.end())
					nameToInst[nm] = (int) i;
			}
			auto typeMnToInst = [&](u32 mi) -> int {
				if (mi == 0) return -1;             // "*" / any
				auto it = nameToInst.find(mnLocalName(mi));
				return it == nameToInst.end() ? -1 : it->second;
			};
			// method index -> defining class + whether `this` is an instance
			struct MInfo { int cls = -1; bool inst = true; };
			std::map<u32, MInfo> m2c;
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
			// walk instance + superclass chain for a trait by local name
			struct TR { bool found = false; TraitKindType kind = TraitKindType::Slot; u32 typeMn = 0; bool isFinal = false; };
			auto findTrait = [&](int inst, const string& name) -> TR {
				int cur = inst, guard = 0;
				while (cur >= 0 && cur < (int) abc.instances.size() && guard++ < 64)
				{
					for (const AbcTrait& t : abc.instances[cur].traits)
						if (mnLocalName(t.name) == name)
							return { true, t.kind, t.type_name, t.is_final };
					cur = typeMnToInst(abc.instances[cur].super_name);
				}
				return {};
			};
			auto isSealed = [&](int inst) -> bool {
				return inst >= 0 && inst < (int) abc.instances.size()
				    && abc.instances[inst].is_sealed && !abc.instances[inst].is_interface;
			};

			FILE* f = fopen(path, "w");
			if (!f) { fprintf(stderr, "scout: cannot open %s\n", path); return; }
			fprintf(f, "method,op,category,recv_class,prop\n");

			for (const EmitBody& body : bodies)
			{
				if (!body.verified) continue;
				u32 method_index = body.ir.method_index;
				u32 bi = body.ir.body_index;
				if (bi >= abc.method_bodies.size()) continue;
				u32 num_locals = abc.method_bodies[bi].num_locals;
				if (num_locals < 1) num_locals = 1;

				std::vector<AV> locals(num_locals);
				MInfo mi = m2c.count(method_index) ? m2c[method_index] : MInfo{ -1, true };
				if (mi.cls >= 0) locals[0] = { (u8)(mi.inst ? AV_INST : AV_CLS), mi.cls, 0 };
				const AbcMethod& meth = abc.methods[method_index];
				for (size_t k = 0; k < meth.params.size() && (k + 1) < num_locals; k++)
				{
					int pc = typeMnToInst(meth.params[k].type);
					if (pc >= 0) locals[k + 1] = { AV_INST, pc, 0 };
				}

				std::vector<AV> st;
				auto push = [&](AV v) { st.push_back(v); };
				auto pop = [&]() -> AV { if (st.empty()) return AV{}; AV v = st.back(); st.pop_back(); return v; };

				auto classify = [&](const char* opn, const AV& recv, u32 mnIdx, bool isCall) {
					string name = mnLocalName(mnIdx);
					string cls = (recv.k == AV_INST && recv.c >= 0) ? mnLocalName(abc.instances[recv.c].name) : "";
					const char* cat;
					if (recv.k == AV_INST && recv.c >= 0)
					{
						TR tr = findTrait(recv.c, name);
						bool sealed = isSealed(recv.c);
						if (!tr.found) cat = "not_found";
						else if (isCall)
						{
							if (tr.kind == TraitKindType::Method)
								cat = sealed ? (tr.isFinal || abc.instances[recv.c].is_final
								                ? "call_method_mono" : "call_method_virtual")
								             : "call_method_dynclass";
							else if (tr.kind == TraitKindType::Getter || tr.kind == TraitKindType::Setter)
								cat = "call_accessor";
							else cat = "call_slot_closure";
						}
						else
						{
							if (tr.kind == TraitKindType::Slot || tr.kind == TraitKindType::Const)
								cat = sealed ? "slot_sealed" : "slot_dynclass";   // slot_sealed = ELIGIBLE
							else if (tr.kind == TraitKindType::Getter || tr.kind == TraitKindType::Setter)
								cat = "accessor";
							else if (tr.kind == TraitKindType::Method)
								cat = "method_as_prop";
							else cat = "other";
						}
					}
					else if (recv.k == AV_CLS) cat = "recv_classobj";
					else if (recv.k == AV_SCOPE) cat = "recv_scope";
					else cat = "recv_unknown";
					fprintf(f, "%u,%s,%s,%s,%s\n", method_index, opn, cat,
					        cls.c_str(), name.c_str());
				};

				for (const IrOp& op : body.ir.ops)
				{
					u32 pops = 0, pushes = 0; s32 sd = 0;
					// replicate the verifier's stack effect for depth alignment
					u32 lazy = 0;
					switch (op.op) {
						case IrOpcode::CallProperty: case IrOpcode::CallPropLex:
						case IrOpcode::CallPropVoid: case IrOpcode::CallSuper:
						case IrOpcode::ConstructProp: case IrOpcode::GetPropertyStatic:
						case IrOpcode::GetPropertyFast: case IrOpcode::GetPropertySlow:
						case IrOpcode::SetPropertyStatic: case IrOpcode::SetPropertyFast:
						case IrOpcode::SetPropertySlow: case IrOpcode::InitProperty:
						case IrOpcode::DeleteProperty: case IrOpcode::GetSuper:
						case IrOpcode::SetSuper: case IrOpcode::GetDescendants:
						case IrOpcode::FindProperty: case IrOpcode::FindPropStrict:
						case IrOpcode::FindDef: {
							if (op.arg1 < MN.size()) {
								const AbcMultiname& m = MN[op.arg1];
								lazy = (m.hasLazyName() ? 1u : 0u) + (m.hasLazyNs() ? 1u : 0u);
							}
							break;
						}
						default: break;
					}

					// ops we model for TYPE tracking (and their exact stack effect)
					switch (op.op)
					{
						case IrOpcode::GetLocal:
							push(op.arg1 < locals.size() ? locals[op.arg1] : AV{});
							continue;
						case IrOpcode::SetLocal: {
							AV v = pop();
							if (op.arg1 < locals.size()) locals[op.arg1] = v;
							continue;
						}
						case IrOpcode::Dup: {
							AV v = st.empty() ? AV{} : st.back(); push(v); continue;
						}
						case IrOpcode::Coerce: {
							pop(); int c = typeMnToInst(op.arg1);
							push(c >= 0 ? AV{ AV_INST, c, 0 } : AV{}); continue;
						}
						case IrOpcode::FindPropStrict: case IrOpcode::FindProperty: {
							for (u32 i = 0; i < lazy; i++) pop();
							push(AV{ AV_SCOPE, -1, op.arg1 }); continue;
						}
						case IrOpcode::GetPropertyStatic: {
							AV recv = pop();
							classify("get", recv, op.arg1, false);
							// result type
							AV res{};
							if (recv.k == AV_SCOPE) {
								int c = typeMnToInst(op.arg1);
								if (c >= 0) res = AV{ AV_CLS, c, 0 };
							} else if (recv.k == AV_INST && recv.c >= 0) {
								TR tr = findTrait(recv.c, mnLocalName(op.arg1));
								if (tr.found && (tr.kind == TraitKindType::Slot
								    || tr.kind == TraitKindType::Const
								    || tr.kind == TraitKindType::Getter)) {
									int c = typeMnToInst(tr.typeMn);
									if (c >= 0) res = AV{ AV_INST, c, 0 };
								}
							}
							push(res); continue;
						}
						case IrOpcode::SetPropertyStatic: {
							AV val = pop(); (void) val; AV recv = pop();
							classify("set", recv, op.arg1, false);
							continue;
						}
						case IrOpcode::CallProperty: case IrOpcode::CallPropVoid: {
							for (u32 i = 0; i < op.arg2 + lazy; i++) pop();
							AV recv = pop();
							classify("call", recv, op.arg1, true);
							if (op.op == IrOpcode::CallProperty) {
								AV res{};
								if (recv.k == AV_INST && recv.c >= 0) {
									TR tr = findTrait(recv.c, mnLocalName(op.arg1));
									if (tr.found && tr.kind == TraitKindType::Method) {
										int c = typeMnToInst(abc.methods[tr.typeMn].return_type);
										// tr.typeMn is not a method idx; skip return typing
										(void) c;
									}
								}
								push(res);
							}
							continue;
						}
						case IrOpcode::ConstructProp: {
							for (u32 i = 0; i < op.arg2 + lazy; i++) pop();
							pop(); // ctor receiver/scope
							int c = typeMnToInst(op.arg1);
							push(c >= 0 ? AV{ AV_INST, c, 0 } : AV{});
							continue;
						}
						default: break;
					}

					// generic depth-preserving effect for everything else
					switch (op.op) {
						case IrOpcode::Add: case IrOpcode::AddI: case IrOpcode::Subtract:
						case IrOpcode::SubtractI: case IrOpcode::Multiply: case IrOpcode::MultiplyI:
						case IrOpcode::Divide: case IrOpcode::Modulo: case IrOpcode::LShift:
						case IrOpcode::RShift: case IrOpcode::URShift: case IrOpcode::BitAnd:
						case IrOpcode::BitOr: case IrOpcode::BitXor: case IrOpcode::Equals:
						case IrOpcode::StrictEquals: case IrOpcode::LessThan: case IrOpcode::LessEquals:
						case IrOpcode::GreaterThan: case IrOpcode::GreaterEquals: case IrOpcode::In:
						case IrOpcode::InstanceOf: case IrOpcode::IsTypeLate: case IrOpcode::AsTypeLate:
						case IrOpcode::HasNext: case IrOpcode::NextName: case IrOpcode::NextValue:
							pops = 2; pushes = 1; break;
						case IrOpcode::Negate: case IrOpcode::NegateI: case IrOpcode::BitNot:
						case IrOpcode::Not: case IrOpcode::Increment: case IrOpcode::IncrementI:
						case IrOpcode::Decrement: case IrOpcode::DecrementI: case IrOpcode::TypeOf:
						case IrOpcode::ConvertO: case IrOpcode::ConvertS: case IrOpcode::CoerceA:
						case IrOpcode::CoerceB: case IrOpcode::CoerceD: case IrOpcode::CoerceI:
						case IrOpcode::CoerceO: case IrOpcode::CoerceS: case IrOpcode::CoerceU:
						case IrOpcode::AsType: case IrOpcode::IsType: case IrOpcode::CheckFilter:
						case IrOpcode::EscXAttr: case IrOpcode::EscXElem: case IrOpcode::Li8:
						case IrOpcode::Li16: case IrOpcode::Li32: case IrOpcode::Lf32:
						case IrOpcode::Lf64: case IrOpcode::Sxi1: case IrOpcode::Sxi8:
						case IrOpcode::Sxi16: case IrOpcode::NewClass:
							pops = 1; pushes = 1; break;
						case IrOpcode::PushInt: case IrOpcode::PushUint: case IrOpcode::PushDouble:
						case IrOpcode::PushString: case IrOpcode::PushNamespace: case IrOpcode::PushNaN:
						case IrOpcode::PushNull: case IrOpcode::PushUndefined: case IrOpcode::PushTrue:
						case IrOpcode::PushFalse: case IrOpcode::GetScopeObject:
						case IrOpcode::GetOuterScope: case IrOpcode::GetGlobalScope:
						case IrOpcode::GetGlobalSlot: case IrOpcode::NewFunction:
						case IrOpcode::NewCatch: case IrOpcode::NewActivation: case IrOpcode::HasNext2:
							pushes = 1; break;
						case IrOpcode::Swap: pops = 2; pushes = 2; break;
						case IrOpcode::Pop: case IrOpcode::SetGlobalSlot: case IrOpcode::DxnsLate:
						case IrOpcode::IfTrue: case IrOpcode::IfFalse: case IrOpcode::LookupSwitch:
						case IrOpcode::ReturnValue: case IrOpcode::Throw:
							pops = 1; break;
						case IrOpcode::PushScope: case IrOpcode::PushWith: pops = 1; break;
						case IrOpcode::GetSlot: pops = 1; pushes = 1; break;
						case IrOpcode::SetSlot: pops = 2; break;
						case IrOpcode::GetPropertyFast: case IrOpcode::GetPropertySlow:
						case IrOpcode::GetSuper: case IrOpcode::DeleteProperty:
						case IrOpcode::GetDescendants:
							pops = 1 + lazy; pushes = 1; break;
						case IrOpcode::SetPropertyFast: case IrOpcode::SetPropertySlow:
						case IrOpcode::InitProperty: case IrOpcode::SetSuper:
							pops = 2 + lazy; break;
						case IrOpcode::FindDef: pushes = 1; break;
						case IrOpcode::Call: pops = op.arg2 + 2; pushes = 1; break;
						case IrOpcode::CallStatic: pops = op.arg2 + 1; pushes = 1; break;
						case IrOpcode::CallPropLex: case IrOpcode::CallSuper:
							pops = op.arg2 + 1 + lazy; pushes = 1; break;
						case IrOpcode::Construct: pops = op.arg2 + 1; pushes = 1; break;
						case IrOpcode::ConstructSuper: pops = op.arg2 + 1; break;
						case IrOpcode::NewObject: pops = op.arg2 * 2; pushes = 1; break;
						case IrOpcode::NewArray: pops = op.arg2; pushes = 1; break;
						case IrOpcode::ApplyType: pops = op.arg2 + 1; pushes = 1; break;
						case IrOpcode::Si8: case IrOpcode::Si16: case IrOpcode::Si32:
						case IrOpcode::Sf32: case IrOpcode::Sf64: pops = 2; break;
						default: break;
					}
					for (u32 i = 0; i < pops; i++) pop();
					for (u32 i = 0; i < pushes; i++) push(AV{});
				}
			}
			fclose(f);
			fprintf(stderr, "scout: wrote %s\n", path);
		}

		// =================================================================
		// TEMP Step-0 census (RWK property-read endgame + store-path lever).
		// Env-gated: SWF_CENSUS_PROPREAD=<csv path>. Read-only — mirrors
		// analyzeSlotSpec's provenance interp and reports, per site:
		//  * GetPropertyStatic on a `this` receiver: specialized, or WHY not
		//    (body gate: not-instance/not-sealed/local0-written; trait: not
		//    found / ambiguous / accessor / method / subclass-redeclares /
		//    non-ABC slot chain).
		//  * FindPropStrict/FindProperty static-mn sites: does the multiname
		//    resolve to an instance trait of the ENCLOSING class (slot /
		//    accessor / method), a static trait of the enclosing class or an
		//    ancestor class, a unique global class name (getlex), or other.
		//  * find→consumer pattern rows (find_get / find_call / find_set)
		//    when the find result is consumed by a same-mn property op.
		//    own_class_static find_get rows carry ":adj"/":nonadj" (consumer
		//    immediately follows the find), ":k1"/":k0" (static slot index
		//    computable), ":ft1"/":ft0" (find→this-style preamble gate holds)
		//    — the lever-A (fused getlex-ownstatic) qualification bits.
		//  * STORE rows (op = set / init) for every static-mn
		//    SetPropertyStatic / InitProperty: receiver kind (this / typed /
		//    klass / find / unk), slot resolution with the GET-lever gate
		//    list (sealed, no subclass redeclare, exact ABC slot index,
		//    accessor/ambiguous/const exclusions), and whether the declared
		//    slot type's store coerce is provably a no-op for the operand's
		//    static type (":c0" elidable / ":cN" needed / ":c?" no slot type).
		// CSV: method,op,category,cls,prop,scope_stable,has_activation
		// =================================================================
		static void censusPropRead(const AbcFile& abc,
		                           const std::vector<EmitBody>& bodies,
		                           const char* path)
		{
			AbcTypeModel M(abc);
			FILE* f = fopen(path, "w");
			if (!f) { fprintf(stderr, "census: cannot open %s\n", path); return; }
			fprintf(f, "method,op,category,cls,prop,scope_stable,has_activation\n");

			for (const EmitBody& body : bodies)
			{
				if (!body.verified) continue;
				u32 method_index = body.ir.method_index;
				auto mit = M.m2c.find(method_index);
				bool instMethod = mit != M.m2c.end() && mit->second.inst
				               && mit->second.cls >= 0;
				int thisCls = instMethod ? mit->second.cls : -1;
				string clsName = thisCls >= 0
					? M.localName(abc.instances[thisCls].name) : "";

				bool sealedCls = instMethod && M.isSealed(thisCls);
				bool local0w = false, scope_stable = true, has_act = false;
				bool only_preamble_scope = true;
				for (size_t oi = 0; oi < body.ir.ops.size(); oi++)
				{
					const IrOp& op = body.ir.ops[oi];
					switch (op.op) {
						case IrOpcode::SetLocal: case IrOpcode::Kill:
						case IrOpcode::IncLocal: case IrOpcode::DecLocal:
						case IrOpcode::IncLocalI: case IrOpcode::DecLocalI:
							if (op.arg1 == 0) local0w = true; break;
						case IrOpcode::HasNext2:
							if (op.arg1 == 0 || op.arg2 == 0) local0w = true; break;
						case IrOpcode::PushScope:
							if (oi != 1) only_preamble_scope = false; break;
						case IrOpcode::PushWith:
							scope_stable = false; only_preamble_scope = false; break;
						case IrOpcode::PopScope: only_preamble_scope = false; break;
						case IrOpcode::NewActivation: has_act = true; break;
						default: break;
					}
				}
				bool active_exc = false;
				for (const IrException& e : body.ir.exceptions)
					if (e.active) active_exc = true;

				// Branch/switch/exception targets (type-merge resets + the
				// preamble-reentry exclusion + fused-pair adjacency check).
				std::set<u32> targets;
				for (const IrOp& op : body.ir.ops)
					switch (op.op) {
						case IrOpcode::Jump: case IrOpcode::IfTrue: case IrOpcode::IfFalse:
							targets.insert(op.target); break;
						case IrOpcode::LookupSwitch:
							targets.insert(op.target);
							for (u32 t : op.switch_targets) targets.insert(t);
							break;
						default: break;
					}
				for (const IrException& e : body.ir.exceptions)
					if (e.active) targets.insert(e.target_op);

				// find→this-style preamble gate (mirrors analyzeSlotSpec's
				// findthis_gate: the scope shape that makes the walk's probe
				// order provable at every site in the body).
				bool ft_gate = instMethod && !local0w && only_preamble_scope
					&& !has_act && !active_exc
					&& body.ir.ops.size() >= 2
					&& body.ir.ops[0].op == IrOpcode::GetLocal
					&& body.ir.ops[0].arg1 == 0
					&& body.ir.ops[1].op == IrOpcode::PushScope
					&& !targets.count(0u) && !targets.count(1u);

				// Local static types (seeds: `this` + declared param types),
				// reset at branch-target merges like analyzeSlotSpec.
				u32 bi = body.ir.body_index;
				u32 num_locals = (bi < abc.method_bodies.size()
				                  && abc.method_bodies[bi].num_locals > 0)
					? abc.method_bodies[bi].num_locals : 1;
				std::vector<TV> localTy(num_locals);
				std::vector<char> localWritten(num_locals, 0);
				if (instMethod && num_locals > 0) localTy[0] = TV{ TK_INST, thisCls };
				const AbcMethod& meth = abc.methods[method_index];
				for (size_t k = 0; k < meth.params.size() && (k + 1) < num_locals; k++)
					localTy[k + 1] = M.typeOfMn(meth.params[k].type);
				for (const IrOp& op : body.ir.ops)
					switch (op.op) {
						case IrOpcode::SetLocal: case IrOpcode::Kill:
						case IrOpcode::IncLocal: case IrOpcode::DecLocal:
						case IrOpcode::IncLocalI: case IrOpcode::DecLocalI:
							if (op.arg1 < localWritten.size()) localWritten[op.arg1] = 1;
							break;
						case IrOpcode::HasNext2:
							if (op.arg1 < localWritten.size()) localWritten[op.arg1] = 1;
							if (op.arg2 < localWritten.size()) localWritten[op.arg2] = 1;
							break;
						default: break;
					}

				// Classify a property name against the enclosing class.
				// Instance chain first (slot/accessor/method + specializable
				// detail), then own/ancestor CLASS (static) traits, then a
				// unique global class name, else other.
				auto classifyOwn = [&](const string& name) -> string {
					if (!instMethod) {
						// class (static) method: `this` is the class object.
						if (thisCls >= 0
						    && M.computeStaticSlotIndex(thisCls, name) > 0)
							return "cm_own_static_slot";
						if (M.uniqueClassByName(name) >= 0) return "global_class";
						return "cm_other";
					}
					// instance-trait walk with kind detail
					int cur = thisCls, guard = 0, hits = 0;
					TraitKindType kind = TraitKindType::Slot;
					while (cur >= 0 && cur < (int) abc.instances.size()
					       && guard++ < 64)
					{
						for (const AbcTrait& t : abc.instances[cur].traits)
							if (M.localName(t.name) == name)
							{ hits++; kind = t.kind; }
						if (abc.instances[cur].super_name == 0) break;
						cur = M.typeMnToInst(abc.instances[cur].super_name);
					}
					if (hits >= 1)
					{
						if (hits > 1) return "own_inst_ambig";
						if (kind == TraitKindType::Slot
						    || kind == TraitKindType::Const)
						{
							if (!sealedCls) return "own_slot_notsealed";
							if (local0w) return "own_slot_local0w";
							if (M.subclassRedeclares(thisCls, name))
								return "own_slot_subredecl";
							AbcTypeModel::Found fnd = M.findUniqueSlot(thisCls, name);
							int K = fnd.ok
								? M.computeSlotIndex(fnd.declInst, fnd.traitIdx) : -1;
							return K > 0 ? "own_slot_ok" : "own_slot_nonabc";
						}
						if (kind == TraitKindType::Getter
						    || kind == TraitKindType::Setter)
							return "own_accessor";
						if (kind == TraitKindType::Method) return "own_method";
						return "own_other_kind";
					}
					// static trait of enclosing class or an ancestor class?
					cur = thisCls; guard = 0;
					while (cur >= 0 && cur < (int) abc.classes.size()
					       && guard++ < 64)
					{
						for (const AbcTrait& t : abc.classes[cur].traits)
							if (M.localName(t.name) == name)
								return cur == thisCls ? "own_class_static"
								                      : "ancestor_class_static";
						if (abc.instances[cur].super_name == 0) break;
						cur = M.typeMnToInst(abc.instances[cur].super_name);
					}
					if (M.uniqueClassByName(name) >= 0) return "global_class";
					return "other";
				};

				auto emitRow = [&](const char* opn, const string& cat,
				                   const string& prop) {
					fprintf(f, "%u,%s,%s,%s,%s,%d,%d\n", method_index, opn,
					        cat.c_str(), clsName.c_str(), prop.c_str(),
					        scope_stable ? 1 : 0, has_act ? 1 : 0);
				};

				// Instance-trait resolution with the GET-lever gate list, for
				// a store to `name` on a receiver of static class `recvCls`.
				// `isSet` adds the const exclusion (setproperty throws #1074
				// on const; initproperty is allowed to store).
				auto classifyStoreSlot = [&](int recvCls, const string& name,
				                             bool isSet, TV valTy) -> string {
					// kind walk (detect accessor/method/ambiguous/not-found)
					int cur = recvCls, guard = 0, hits = 0;
					TraitKindType kind = TraitKindType::Slot;
					const AbcTrait* slotTrait = nullptr;
					while (cur >= 0 && cur < (int) abc.instances.size()
					       && guard++ < 64)
					{
						for (const AbcTrait& t : abc.instances[cur].traits)
							if (M.localName(t.name) == name)
							{ hits++; kind = t.kind; slotTrait = &t; }
						if (abc.instances[cur].super_name == 0) break;
						cur = M.typeMnToInst(abc.instances[cur].super_name);
					}
					if (hits == 0) return "notfound";
					if (hits > 1) return "ambig";
					if (kind == TraitKindType::Getter
					    || kind == TraitKindType::Setter) return "accessor";
					if (kind == TraitKindType::Method) return "method";
					if (kind != TraitKindType::Slot
					    && kind != TraitKindType::Const) return "otherkind";
					if (kind == TraitKindType::Const && isSet) return "const_set";
					if (!M.isSealed(recvCls)) return "notsealed";
					if (M.subclassRedeclares(recvCls, name)) return "subredecl";
					AbcTypeModel::Found fnd = M.findUniqueSlot(recvCls, name);
					int K = fnd.ok
						? M.computeSlotIndex(fnd.declInst, fnd.traitIdx) : -1;
					if (K <= 0) return "nonabc";
					// slot found + gated OK → coerce-elision detail
					TV declT = M.typeOfMn(slotTrait->type_name);
					if (slotTrait->type_name == 0) return "slot_ok:c0";
					if (declT.k == TK_UNK) return "slot_ok:c?";
					return M.coerceIsNoop(valTy, declT)
						? "slot_ok:c0" : "slot_ok:cN";
				};

				// provenance interp (mirror of analyzeSlotSpec, gate-independent
				// is_l0 so gate rejections are countable) + static TYPE per slot
				struct CV { bool is_l0 = false; int fp_mn = -1; int fp_at = -1;
				            int cls = -1; TV type; };
				std::vector<CV> st;
				auto pop = [&]() -> CV {
					if (st.empty()) return CV{};
					CV v = st.back(); st.pop_back(); return v; };
				auto push = [&](CV v) { st.push_back(v); };
				auto peek = [&](u32 d) -> CV {
					return d < st.size() ? st[st.size() - 1 - d] : CV{}; };
				auto genericType = [&](const IrOp& op) -> TV {
					switch (op.op) {
						case IrOpcode::PushNull: return TV{ TK_NULL };
						case IrOpcode::PushInt: return TV{ TK_INT };
						case IrOpcode::PushUint: return TV{ TK_UINT };
						case IrOpcode::PushDouble: case IrOpcode::PushNaN: return TV{ TK_NUM };
						case IrOpcode::PushString: return TV{ TK_STR };
						case IrOpcode::PushTrue: case IrOpcode::PushFalse: return TV{ TK_BOOL };
						case IrOpcode::AddI: case IrOpcode::SubtractI: case IrOpcode::MultiplyI:
						case IrOpcode::IncrementI: case IrOpcode::DecrementI: case IrOpcode::NegateI:
						case IrOpcode::BitNot: case IrOpcode::BitAnd: case IrOpcode::BitOr:
						case IrOpcode::BitXor: case IrOpcode::LShift: case IrOpcode::RShift:
							return TV{ TK_INT };
						case IrOpcode::URShift: return TV{ TK_UINT };
						case IrOpcode::Subtract: case IrOpcode::Multiply: case IrOpcode::Divide:
						case IrOpcode::Modulo: case IrOpcode::Negate: case IrOpcode::Increment:
						case IrOpcode::Decrement:
							return TV{ TK_NUM };
						case IrOpcode::Not: case IrOpcode::Equals: case IrOpcode::StrictEquals:
						case IrOpcode::LessThan: case IrOpcode::LessEquals: case IrOpcode::GreaterThan:
						case IrOpcode::GreaterEquals: case IrOpcode::In: case IrOpcode::InstanceOf:
						case IrOpcode::IsType: case IrOpcode::IsTypeLate:
							return TV{ TK_BOOL };
						case IrOpcode::TypeOf: case IrOpcode::ConvertS: return TV{ TK_STR };
						case IrOpcode::ConstructProp: return M.typeOfMn(op.arg1);
						default: return TV{};
					}
				};

				for (size_t i = 0; i < body.ir.ops.size(); i++)
				{
					const IrOp& op = body.ir.ops[i];
					if (targets.count((u32) i))
					{
						for (CV& s : st) s.type = TV{};
						for (u32 l = 0; l < localTy.size(); l++)
							if (localWritten[l]) localTy[l] = TV{};
					}
					if (op.op == IrOpcode::GetLocal)
					{
						CV v; v.is_l0 = (op.arg1 == 0);
						if (op.arg1 < localTy.size()) v.type = localTy[op.arg1];
						push(v); continue;
					}
					if (op.op == IrOpcode::SetLocal)
					{
						CV v = pop();
						if (op.arg1 < localTy.size()) localTy[op.arg1] = v.type;
						continue;
					}
					if (op.op == IrOpcode::Dup)
					{ push(st.empty() ? CV{} : st.back()); continue; }
					if (op.op == IrOpcode::Coerce || op.op == IrOpcode::CoerceD
					    || op.op == IrOpcode::CoerceI || op.op == IrOpcode::CoerceU
					    || op.op == IrOpcode::CoerceB || op.op == IrOpcode::CoerceS)
					{
						TV T = op.op == IrOpcode::Coerce ? M.typeOfMn(op.arg1)
						     : op.op == IrOpcode::CoerceD ? TV{ TK_NUM }
						     : op.op == IrOpcode::CoerceI ? TV{ TK_INT }
						     : op.op == IrOpcode::CoerceU ? TV{ TK_UINT }
						     : op.op == IrOpcode::CoerceB ? TV{ TK_BOOL }
						     : TV{ TK_STR };
						pop(); CV r; r.type = T; push(r);
						continue;
					}
					if ((op.op == IrOpcode::FindPropStrict
					     || op.op == IrOpcode::FindProperty)
					    && !mnLazyNs(abc, op.arg1) && !mnLazyName(abc, op.arg1))
					{
						string name = M.localName(op.arg1);
						emitRow("find", classifyOwn(name), name);
						CV v; v.fp_mn = (int) op.arg1; v.fp_at = (int) i;
						push(v); continue;
					}
					if (op.op == IrOpcode::GetPropertyStatic)
					{
						CV recv = pop();
						string name = M.localName(op.arg1);
						if (recv.is_l0)
						{
							string cat;
							if (!instMethod) cat = "this_notinst";
							else cat = classifyOwn(name);
							emitRow("get_this", cat, name);
						}
						else if (recv.fp_mn == (int) op.arg1)
						{
							string cat = classifyOwn(name);
							if (cat == "own_class_static")
							{
								// lever-A (fused getlex-ownstatic) bits:
								// adjacency, static slot index, preamble gate
								bool adj = recv.fp_at == (int) i - 1
									&& !targets.count((u32) i);
								int K = M.computeStaticSlotIndex(thisCls, name);
								cat += adj ? ":adj" : ":nonadj";
								cat += K > 0 ? ":k1" : ":k0";
								cat += ft_gate ? ":ft1" : ":ft0";
							}
							emitRow("find_get", cat, name);
						}
						else if (recv.cls >= 0)
						{
							int K = M.computeStaticSlotIndex(recv.cls, name);
							emitRow("get_static",
							        K > 0 ? "static_slot_ok" : "static_rej", name);
						}
						else emitRow("get_other", "unknown_recv", name);
						CV res;
						if (recv.fp_mn == (int) op.arg1)
						{
							int c = M.uniqueClassByName(name);
							if (c >= 0) res.cls = c;
						}
						if (recv.type.k == TK_INST)
							res.type = M.memberReadType(recv.type.inst, name);
						else if (recv.is_l0 && instMethod)
							res.type = M.memberReadType(thisCls, name);
						push(res);
						continue;
					}
					if (op.op == IrOpcode::SetPropertyStatic
					    || op.op == IrOpcode::InitProperty)
					{
						const char* opn =
							op.op == IrOpcode::InitProperty ? "init" : "set";
						bool isSet = op.op == IrOpcode::SetPropertyStatic;
						if (mnLazyNs(abc, op.arg1) || mnLazyName(abc, op.arg1))
						{
							pop(); pop();
							emitRow(opn, "lazy_mn", "");
							continue;
						}
						CV val = pop();
						CV recv = pop();
						string name = M.localName(op.arg1);
						string cat;
						if (recv.is_l0 && instMethod)
							cat = "this_" + classifyStoreSlot(thisCls, name,
							                                  isSet, val.type);
						else if (recv.is_l0)
							cat = "this_notinst";
						else if (recv.type.k == TK_INST)
							cat = "typed_" + classifyStoreSlot(recv.type.inst,
							                                   name, isSet,
							                                   val.type);
						else if (recv.cls >= 0)
						{
							int K = M.computeStaticSlotIndex(recv.cls, name);
							cat = K > 0 ? "klass_slot_ok" : "klass_rej";
						}
						else if (recv.fp_mn == (int) op.arg1)
						{
							// find-substituted receiver: after the find→this
							// lever the receiver IS `this` at runtime when the
							// mn matches the enclosing instance chain — give
							// those the full store-gate detail.
							string oc = classifyOwn(name);
							if (instMethod && oc.rfind("own_slot", 0) == 0)
								cat = "findthis_" + classifyStoreSlot(
									thisCls, name, isSet, val.type);
							else
								cat = "find_" + oc;
						}
						else
							cat = "unk_recv";
						emitRow(opn, cat, name);
						continue;
					}
					if ((op.op == IrOpcode::CallProperty
					     || op.op == IrOpcode::CallPropVoid)
					    && !mnLazyNs(abc, op.arg1) && !mnLazyName(abc, op.arg1))
					{
						CV recv = peek(op.arg2);
						string name = M.localName(op.arg1);
						if (recv.fp_mn == (int) op.arg1)
							emitRow("find_call", classifyOwn(name), name);
						else if (recv.is_l0 && instMethod)
							emitRow("call_this", classifyOwn(name), name);
						u32 pops, pushes; irStackEffect(op, abc, pops, pushes);
						for (u32 k = 0; k < pops; k++) pop();
						CV r;
						if (op.op == IrOpcode::CallProperty)
						{
							if (recv.type.k == TK_INST)
								r.type = M.memberReadType(recv.type.inst, name);
							else if (recv.is_l0 && instMethod)
								r.type = M.memberReadType(thisCls, name);
						}
						for (u32 k = 0; k < pushes; k++)
							push(k + 1 == pushes ? r : CV{});
						continue;
					}
					u32 pops, pushes; irStackEffect(op, abc, pops, pushes);
					for (u32 k = 0; k < pops; k++) pop();
					TV rt = pushes ? genericType(op) : TV{};
					for (u32 k = 0; k < pushes; k++)
					{
						CV r; if (k + 1 == pushes) r.type = rt; push(r);
					}
				}
			}
			fclose(f);
			fprintf(stderr, "census: wrote %s\n", path);
		}
	}  // namespace

	void AbcEmitter::emitAbcTag(const AbcFile& abc, const std::vector<EmitBody>& bodies)
	{
		if (const char* sp = getenv("SWF_SCOUT_TYPES"))
			scoutStaticTypes(abc, bodies,
			                 (string(sp) + "." + to_string(next_tag_index_)).c_str());
		if (const char* cp = getenv("SWF_CENSUS_PROPREAD"))
			censusPropRead(abc, bodies,
			               (string(cp) + "." + to_string(next_tag_index_) + ".csv").c_str());
		ensureDir();
		int tag = next_tag_index_++;
		// prefix_ is empty for the main movie, so `p` (which names both the
		// emitted files and every symbol in them) is unchanged there.
		string p = prefix_ + "abc" + to_string(tag);

		// body index per method (-1 = none). Used by both the tables block
		// (class fingerprints) and the methods block.
		std::vector<int> method_body(abc.methods.size(), -1);
		for (size_t bi = 0; bi < abc.method_bodies.size(); bi++)
		{
			if (abc.method_bodies[bi].method < method_body.size())
				method_body[abc.method_bodies[bi].method] = (int) bi;
		}

		const bool dump_fp = getenv("SWFRECOMP_DUMP_FINGERPRINTS") != NULL;

		// ------------------------------------------------------------------
		// abc<tag>_tables.c
		// ------------------------------------------------------------------
		{
			ofstream out(folder_ + "/" + p + "_tables.c");
			out << "// Generated by SWFRecomp (abc_emit.cpp) — static ABC data "
			    << "for DoABC tag " << tag << ". Do not edit." << endl
			    << "#include \"" << prefix_ << "abc_gen.h\"" << endl << endl;

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

				// Fingerprint gate: stamp an intrinsic marker only on an EXACT
				// match of the normalized method bodies + trait layout. Any
				// mismatch (including an unhashable body, which yields 0) leaves
				// the marker at 0 and the game's own compiled code runs.
				u64 fp = classFingerprint(abc, i, method_body, false);
				unsigned intrinsic_id = intrinsicIdForFingerprint(fp);
				// Method-level gate (independent of the whole-class hash above):
				// substitute the native FlxTilemap.arrayToCSV builder (id 4) on a
				// match of just that static method's body. A class matches at most
				// one of {FlxQuadTree/FlxList, FlxTilemap.arrayToCSV}.
				u64 actocsv_fp = 0;
				if (intrinsic_id == 0)
				{
					actocsv_fp = arrayToCSVFingerprint(abc, i, method_body);
					intrinsic_id = arrayToCSVIdForFingerprint(actocsv_fp);
				}
				out << "\t{ " << inst.name << ", " << inst.super_name << ", "
				    << flags << ", " << (inst.has_protected_ns ? 1 : 0) << ", "
				    << inst.protected_ns << ", " << ifaces << ", "
				    << inst.init_method << ", "
				    << abc.classes[i].init_method << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_it", inst.traits.size())
				    << ", "
				    << traitArrayRef(p + "_c" + to_string(i) + "_ct", abc.classes[i].traits.size())
				    << ", " << intrinsic_id << " }," << endl;

				if (dump_fp)
				{
					// SWFRECOMP_DUMP_FINGERPRINTS=2 (or a class name) turns on a
					// per-component breakdown for the matching class.
					const char* fpv_env = getenv("SWFRECOMP_DUMP_FINGERPRINTS");
					string qn = qualifiedName(abc, inst.name);
					bool verbose = fpv_env
					               && (string(fpv_env) == "2" || qn == fpv_env);
					if (verbose)
					{
						fprintf(stderr, "FPV ===== %s =====\n", qn.c_str());
						classFingerprint(abc, i, method_body, true);
					}
					fprintf(stderr, "FP %s %016llx traits=%zu/%zu intrinsic=%u\n",
					        qn.c_str(), (unsigned long long) fp,
					        inst.traits.size(), abc.classes[i].traits.size(),
					        intrinsic_id);
					// Always report the arrayToCSV method fingerprint when the
					// class has one, so its baked constant can be read even before
					// the class-level fp matches anything (bake workflow).
					u64 acsv = (actocsv_fp != 0)
					           ? actocsv_fp
					           : arrayToCSVFingerprint(abc, i, method_body);
					if (acsv != 0)
						fprintf(stderr, "FP-ARRAYTOCSV %s %016llx\n",
						        qn.c_str(), (unsigned long long) acsv);
				}
			}
			if (abc.instances.empty())
			{
				out << "\t{ 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, NULL, 0, NULL, 0 }," << endl;
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
			    << "#include \"" << prefix_ << "abc_gen.h\"" << endl << endl;

			// Type model for the compile-time slot-specialization pass.
			AbcTypeModel typeModel(abc);

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

				emitMethodBody(out, abc, body, p + "_m" + to_string(mi), mi, exc_sym,
				               &typeModel);
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
			ofstream out(folder_ + "/" + prefix_ + "abc_gen.h");
			out << "// Generated by SWFRecomp (abc_emit.cpp). Do not edit." << endl
			    << "#pragma once" << endl << endl
			    << "#include <avm2/avm2_abc.h>" << endl
			    << "#include <avm2/avm2_class.h>" << endl
			    << "#include <avm2/avm2_error.h>" << endl
			    << "#include <avm2/avm2_ops.h>" << endl
			    << "#include <avm2/avm2_value.h>" << endl << endl;
			for (int i = 0; i < next_tag_index_; i++)
			{
				out << "extern const Avm2AbcMethodData " << prefix_ << "abc" << i
				    << "_methods[];" << endl
				    << "extern const Avm2AbcFileData " << prefix_ << "abc" << i
				    << "_data;" << endl;
			}
		}

		{
			ofstream out(folder_ + "/" + prefix_ + "abc_registry.c");
			out << "// Generated by SWFRecomp (abc_emit.cpp). Do not edit." << endl
			    << "#include \"" << prefix_ << "abc_gen.h\"" << endl << endl;
			out << "const Avm2AbcFileData* const " << prefix_
			    << "avm2_generated_abc_files[] =" << endl
			    << "{" << endl;
			for (int i = 0; i < next_tag_index_; i++)
			{
				out << "\t&" << prefix_ << "abc" << i << "_data," << endl;
			}
			out << "};" << endl
			    << "const uint32_t " << prefix_ << "avm2_generated_abc_file_count = "
			    << next_tag_index_ << ";" << endl << endl;

			out << "const Avm2SymbolClassBinding " << prefix_
			    << "avm2_generated_symbol_classes[] =" << endl
			    << "{" << endl;
			for (const auto& b : symbol_bindings)
			{
				out << "\t{ " << (u32) (b.first + char_id_base_) << ", \""
				    << escapeCString(b.second)
				    << "\" }," << endl;
			}
			if (symbol_bindings.empty())
			{
				out << "\t{ " << char_id_base_
				    << ", NULL },  // placeholder (no SymbolClass tags)" << endl;
			}
			out << "};" << endl
			    << "const uint32_t " << prefix_
			    << "avm2_generated_symbol_class_count = "
			    << symbol_bindings.size() << ";" << endl
			    << "const uint8_t " << prefix_ << "avm2_generated_swf_version = "
			    << (unsigned) swf_version << ";" << endl;
		}
	}
}
}
