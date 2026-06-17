#pragma once

#include <fstream>
#include <cstdint>
#include <set>
#include <sstream>

using std::string;
using std::ofstream;
using std::ostream;
using std::stringstream;

namespace SWFRecomp
{
	struct Context
	{
		string swf_path;
		string output_tags_folder;
		string output_scripts_folder;

		// tag_main is buffered in memory (stringstream) rather than written
		// directly to disk so the per-frame init prologue placeholder can
		// be replaced once each frame's DoInitAction / ImportAssets calls
		// are known. recompile() flushes the buffer to tagMain.c at the end
		// of parseAllTags.
		std::stringstream tag_main;
		ofstream constants;
		ofstream constants_header;
		ofstream out_script_header;
		ofstream out_script_defs;
		ofstream out_script_decls;
		ofstream out_draws;
		ofstream out_draws_header;

		// Track if we're inside a DefineFunction2 (for local register handling)
		bool inside_function2;

		// RegisterCount of the current DefineFunction2 (registers >= this bleed through to caller)
		int function2_register_count;

		// Track if we're inside any function body (for halt check return type)
		bool in_function_body;

		// SWF version (needed for string encoding: SWF<6 uses Latin-1/Win-1252)
		uint8_t swf_version;

		// Char IDs of DefineShape / DefineMorphShape definitions seen so far.
		// Used by DefineButton2 to prefer SHAPE-typed hit records over sprite/
		// button hit records (Ming sometimes adds non-shape characters with
		// HIT flag — those have no graphics so resolve_hit_shape returns NULL
		// and the button stops responding to hover/press transitions).
		std::set<uint16_t> shape_char_ids;

		// Subset of shape_char_ids whose SHAPE has at least one fill style.
		// DefineButton2 prefers a FILLED hit shape over a stroke-only one: a
		// button's StateHitTest region is the union of all HitTest records, and
		// the invisible filled rectangle (no line styles) is the real clickable
		// area. A stroke-only shape only hit-tests on its edges (interior misses
		// in both our hit test and Ruffle's shape_hit_test), so picking it as
		// the single hit char leaves the button face un-clickable.
		std::set<uint16_t> filled_shape_char_ids;

		Context() : inside_function2(false), function2_register_count(0), in_function_body(false), swf_version(0) {}
	};
};