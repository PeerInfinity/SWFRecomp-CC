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

struct Avm2Context
{
	SWFAppContext* app;   // for heap_alloc/heap_calloc
	Avm2Domain domain;
	Avm2Object* builtin_globals;
	Avm2Builtins builtins;
	Avm2AbcFileRt** files;
	uint32_t file_count;
	Avm2Object* root;     // SymbolClass char-0 instance
};

void runSWF_avm2(SWFAppContext* app_context);

// Heap helpers bound to the shared o1heap allocator.
void* avm2_alloc(Avm2Context* ctx, uint32_t size);

#endif // AVM2_MAIN_H
