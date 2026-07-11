#pragma once

// Standalone ABC inspection modes for the SWFRecomp binary:
//   SWFRecomp --dump-abc <file.swf>       full readable dump (pool, classes,
//                                         per-method verified IR)
//   SWFRecomp --check-abc <file.swf>...   one machine-readable ABC-CHECK line
//                                         per SWF (corpus sweep driver)
//
// Exit code: 0 = all OK, nonzero = at least one failure (see abc_tool.cpp).

namespace SWFRecomp
{
namespace abc
{
	int abcToolMain(int argc, char** argv);
}
}
