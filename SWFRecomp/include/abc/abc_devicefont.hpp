#pragma once

// Device fonts declared by the Ruffle test harness (B9).
//
// Ruffle's test framework registers every `[fonts.KEY]` entry of a test.toml
// as a *device* face (tests/framework/src/test.rs:109-145) and every
// `[font_sorts.KEY]` entry as that family's per-glyph fallback chain. Both are
// player-level state, not SWF content, so nothing in the tag stream carries
// them: the recompiler reads the test.toml sitting next to the SWF (its own
// cwd) and bakes the faces into the generated tables, exactly like it bakes
// DefineFont2/3 faces.
//
// Deliberately standalone: emitDeviceFonts() only appends two additive arrays
// to the abc_timeline.c stream. With no `[fonts.*]` table the arrays are empty
// and every runtime lookup behaves as before.

#include <ostream>
#include <string>

namespace SWFRecomp
{
namespace abc
{
	// Emits `avm2_generated_device_fonts[]` + `avm2_generated_device_font_count`
	// (and their code/advance/kern/fallback side tables) into `out`, parsed
	// from `./test.toml`. Emits an empty table when the file is missing, is
	// not valid TOML, declares no `[fonts.*]`, or every declared TTF fails to
	// load — the runtime then keeps its baked-in Noto fallback.
	void emitDeviceFonts(std::ostream& out);

	// The TTF path Ruffle's test harness would render a device font `name`
	// with, resolved through `./test.toml`: a `[fonts.*]` family match, else
	// the `[default_fonts]` list of the DefaultFont the name maps to (ruffle
	// core/src/html/layout.rs:560-625). "" when nothing resolves, in which
	// case the caller keeps the bundled Noto Sans. Used by the AVM1
	// zero-glyph DefineFont2/3 synthesis (swf.cpp).
	std::string resolveTestDeviceFontPath(const std::string& name, bool bold, bool italic);
}
}
