#pragma once

// Human-readable ABC dump: constant pool, classes/traits, per-method
// verified IR listing. Used by `SWFRecomp --dump-abc <file.swf>`.

#include <ostream>
#include <vector>

#include <abc/abc_types.hpp>
#include <abc/abc_ir.hpp>

namespace SWFRecomp
{
namespace abc
{
	// Qualified-name formatting helpers (shared with error reporting).
	std::string namespaceToString(const AbcFile& abc, u32 ns_index);
	std::string multinameToString(const AbcFile& abc, u32 mn_index);

	// Formats one resolved IR op ("PushString str[3]=\"hi\"", "Jump -> 12", ...).
	std::string formatIrOp(const AbcFile& abc, const IrOp& op);

	// Dumps the whole ABC file. Verifies every method body along the way and
	// prints either its IR listing or the verify error. Returns the number of
	// bodies that failed verification.
	int dumpAbc(const AbcFile& abc, std::ostream& out);
}
}
