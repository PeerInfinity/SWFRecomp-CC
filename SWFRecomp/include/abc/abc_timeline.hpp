#pragma once

// AVM2 static timeline tables (Stage 5): an independent second pass over
// the decompressed SWF tag stream that emits RecompiledABC/abc_timeline.c
// (per-timeline place/remove ops, frame labels, scenes, character
// dictionary with bounds, button records, stage parameters).
//
// Deliberately standalone: it re-reads raw tag bytes and never touches the
// AVM1 recompilation state machine in swf.cpp, so it cannot perturb AVM1
// output. Only invoked for AS3 SWFs (from SWF::finalizeAbcEmit, i.e. when
// a DoABC tag created the emitter).

#include <cstdint>
#include <string>

namespace SWFRecomp
{
namespace abc
{
	struct TimelineEmitInfo
	{
		uint8_t swf_version;
		uint16_t header_frame_count;
		uint16_t frame_rate;  // 8.8 fixed
		int32_t stage_xmin, stage_xmax, stage_ymin, stage_ymax;  // twips
	};

	// tags_start points at the first RECORDHEADER after the SWF header;
	// end at the end of the decompressed buffer.
	void emitAvm2Timeline(const uint8_t* tags_start, const uint8_t* end,
	                      const TimelineEmitInfo& info,
	                      const std::string& output_folder);
}
}
