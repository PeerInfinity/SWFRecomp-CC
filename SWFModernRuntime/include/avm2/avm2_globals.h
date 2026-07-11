#ifndef AVM2_GLOBALS_H
#define AVM2_GLOBALS_H

// Builtin stubs for Stage 2 (avm2-support-plan §4.5): Object, Class,
// Function, `trace`, and the flash.display chain
// EventDispatcher → DisplayObject → InteractiveObject →
// DisplayObjectContainer → Sprite → MovieClip (with addFrameScript).
// Stubs are constructible with correct super links; no display-list
// behavior. Registered through the same vtable mechanism as SWF classes so
// the binding surface stays playerglobal-shaped.
//
// Also owns the "domain": the FindPropStrict last-resort lookup from a
// definition name to the globals object defining it (Ruffle Domain
// equivalent), including lazy script initialization.

#include <avm2/avm2_class.h>

typedef struct Avm2Context Avm2Context;

typedef struct Avm2DomainEntry
{
	Avm2PropKey key;
	Avm2AbcFileRt* file;    // NULL = builtin
	uint32_t script_index;  // valid when file != NULL
} Avm2DomainEntry;

typedef struct Avm2Domain
{
	uint32_t count;
	uint32_t cap;
	Avm2DomainEntry* entries;
} Avm2Domain;

// Creates builtin classes + the builtin globals object and seeds the domain.
void avm2_globals_init(Avm2Context* ctx);

// Domain registration (called during ABC load for every script trait).
void avm2_domain_add(Avm2Context* ctx, const Avm2PropKey* key,
                     Avm2AbcFileRt* file, uint32_t script_index);

// Domain lookup: returns the globals object defining `key` (running the
// defining script's initializer lazily if needed), or NULL if undefined.
Avm2Object* avm2_domain_find(Avm2Context* ctx, const Avm2PropKey* key);

// Runs a script's initializer if it has not run yet (lazy or eager init).
void avm2_script_ensure_init(Avm2AbcFileRt* file, uint32_t script_index);

// MovieClip stub instance state (Avm2Object.native_ext).
typedef struct Avm2MovieClipExt
{
	uint32_t frame_script_cap;
	Avm2Value* frame_scripts;  // indexed by 0-based frame; unset = undefined kind
} Avm2MovieClipExt;

// Builtin class handles the runtime needs by identity.
typedef struct Avm2Builtins
{
	Avm2Class* object_class;
	Avm2Class* class_class;
	Avm2Class* function_class;
	Avm2Class* movieclip_class;
} Avm2Builtins;

#endif // AVM2_GLOBALS_H
