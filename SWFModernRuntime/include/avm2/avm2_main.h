#ifndef AVM2_MAIN_H
#define AVM2_MAIN_H

// AVM2 entry point + context. runSWF_avm2() mirrors swf_core.c::runSWF's
// tick cadence and exit conditions (MAX_FRAMES) but dispatches the AVM2
// load ordering (avm2-support-plan §4.4 / Ruffle movie_clip.rs:4246-4255):
// load all ABC (no script inits) → process SymbolClass → eager-init each
// ABC's LAST script → construct the root class → per-tick frame scripts.
//
// swf_core.c is never edited to reference this module: AVM1 builds link
// swf_core.c without src/avm2/*.c. The shared wasm_wrappers/main.c calls
// runSWF_avm2() only under -DSWF_AVM2 (defined by verify_output.py when
// the recompiler produced RecompiledABC/).

#include <avm2/avm2_abc.h>
#include <avm2/avm2_globals.h>

typedef struct SWFAppContext SWFAppContext;

// One entry of the debug call stack (getStackTrace / error 1063 naming).
typedef struct Avm2CallFrame
{
	Avm2MethodRef method;
	Avm2Class* bound_class;
} Avm2CallFrame;

struct Avm2Context
{
	SWFAppContext* app;   // for heap_alloc/heap_calloc
	Avm2Domain domain;
	Avm2Object* builtin_globals;
	Avm2Builtins builtins;
	Avm2AbcFileRt** files;
	uint32_t file_count;
	Avm2Object* root;     // SymbolClass char-0 instance
	Avm2Object* stage;    // flash.display.Stage singleton (avm2_display.c)
	// Frame lifecycle (Ruffle frame_lifecycle.rs FramePhase):
	// 0 Idle, 1 Enter, 2 Construct, 3 FrameScripts, 4 Exit.
	uint8_t frame_phase;
	uint32_t instance_counter;  // auto instance names ("instanceN")
	struct Avm2TryFrame* try_top;  // innermost exception frame (avm2_error.h)
	uint8_t swf_version;  // for string_to_f64 bug compatibility
	uint8_t bytearray_default_encoding;  // ByteArray.defaultObjectEncoding
	// The default XML namespace URI (Dxns/DxnsLate), or NULL. Dynamically
	// scoped: avm2_call_method_ref saves/restores it around every call and
	// resets it for methods with the SET_DXNS flag (Ruffle activation.rs
	// default_xml_namespace propagation).
	const Avm2String* dxns;
	// Debug call stack (FP debug-player getStackTrace).
	Avm2CallFrame* call_frames;
	uint32_t call_depth;
	uint32_t call_cap;
};

void runSWF_avm2(SWFAppContext* app_context);

// The (single) runtime context.
Avm2Context* avm2_get_context(void);

// Heap helpers bound to the shared o1heap allocator.
void* avm2_alloc(Avm2Context* ctx, uint32_t size);

#endif // AVM2_MAIN_H
