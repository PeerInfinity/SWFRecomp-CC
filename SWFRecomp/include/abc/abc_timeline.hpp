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
#include <vector>

namespace SWFRecomp
{
namespace abc
{
	// Per-DefineShape geometry pointer into the resident (draws.c) shape_data
	// vertex table, keyed by char_id. Recorded by SWF::interpretShape during
	// the AVM1-style tessellation pass and handed to the AVM2 char-table
	// emitter (which otherwise only re-reads RECT bounds, never geometry).
	// vert_offset/vert_count are in VERTICES (each vertex is 4*u32 in
	// shape_data), matching render_webgpu_draw_shape's (offset, num_verts).
	// renderable: 1 iff every triangle of this shape uses a fill class the AVM2
	// walk + WGSL shader can render — solid (T1), stroke (T2), gradient (T3).
	// Cleared only by a BITMAP fill (0x40-0x43), which stays deferred.
	struct Avm2ShapeGeomRec
	{
		uint16_t char_id;
		uint8_t  renderable;
		uint32_t vert_offset;
		uint32_t vert_count;
		uint32_t morph_end_offset;  // T6: start index into morph_end_shape_data
		uint8_t  is_morph = 0;      // T6: 1 => DefineMorphShape (ratio-lerp path)
	};

	struct TimelineEmitInfo
	{
		uint8_t swf_version;
		uint16_t header_frame_count;
		uint16_t frame_rate;  // 8.8 fixed
		int32_t stage_xmin, stage_xmax, stage_ymin, stage_ymax;  // twips
		// Shape geometry table (char_id -> shape_data vertex range). NULL when
		// the caller recorded none (e.g. a shapeless AS3 SWF).
		const std::vector<Avm2ShapeGeomRec>* shape_geom = nullptr;
	};

	// tags_start points at the first RECORDHEADER after the SWF header;
	// end at the end of the decompressed buffer.
	void emitAvm2Timeline(const uint8_t* tags_start, const uint8_t* end,
	                      const TimelineEmitInfo& info,
	                      const std::string& output_folder);
}
}
