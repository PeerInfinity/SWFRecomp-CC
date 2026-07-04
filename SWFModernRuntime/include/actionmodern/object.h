#pragma once

#include <common.h>
#include <actionmodern/variables.h>

// Forward declaration
typedef struct SWFAppContext SWFAppContext;

/**
 * ASObject - ActionScript Object with Reference Counting
 *
 * This structure implements compile-time reference counting for object/array opcodes.
 * The recompiler (SWFRecomp) emits inline refcount increment/decrement operations,
 * providing deterministic memory management without runtime GC.
 */

// Forward declaration for property structure
typedef struct ASProperty ASProperty;

/**
 * Property Attribute Flags (ECMA-262 compliant)
 *
 * These flags control property behavior during enumeration, deletion, and assignment.
 */
#define PROPERTY_FLAG_ENUMERABLE  0x01  // Property appears in for..in loops (default for user properties)
#define PROPERTY_FLAG_WRITABLE    0x02  // Property can be modified (default for user properties)
#define PROPERTY_FLAG_CONFIGURABLE 0x04 // Property can be deleted (default for user properties)

// Permanently non-writable — survives ASSetPropFlags clearing READ_ONLY.
// Used for NetConnection.__proto__ and similar deeply protected properties.
// ASSetPropFlags only touches bits 0x01-0x04, so this bit is never cleared by script.
#define PROPERTY_FLAG_PERM_READONLY 0x80

// Default flags for user-created properties (fully mutable and enumerable)
#define PROPERTY_FLAGS_DEFAULT (PROPERTY_FLAG_ENUMERABLE | PROPERTY_FLAG_WRITABLE | PROPERTY_FLAG_CONFIGURABLE)

// Flags for DontEnum properties (internal/built-in properties)
#define PROPERTY_FLAGS_DONTENUM (PROPERTY_FLAG_WRITABLE | PROPERTY_FLAG_CONFIGURABLE)

// Native backing type (for __initializeNative detection)
// Objects created by native constructors cannot be re-initialized as a different native type.
enum NativeType {
	NATIVE_NONE = 0,
	NATIVE_ARRAY = 1,
	NATIVE_STRING = 2,
	NATIVE_NUMBER = 3,
	NATIVE_BOOLEAN = 4,
	NATIVE_DATE = 5,
	NATIVE_SOUND = 6,
	NATIVE_XML = 7,
	NATIVE_XMLNODE = 8,
	NATIVE_TEXTFIELD = 9,
	NATIVE_TEXTFORMAT = 10,
	NATIVE_BITMAPDATA = 11,
	NATIVE_LOADVARS = 12,
	NATIVE_LOCALCONNECTION = 13,
	NATIVE_MOVIECLIPLOADER = 14,
	NATIVE_PRINTJOB = 15,
	NATIVE_BUTTON = 16,
	NATIVE_TEXTSNAPSHOT = 17,
	NATIVE_COLORTRANSFORM = 18,
	NATIVE_TRANSFORM = 19,
	NATIVE_FILTER = 20,
	NATIVE_STYLESHEET = 21,
	NATIVE_FILEREF = 22,
	NATIVE_RANDO = 23,  // Archipelago Rando client (see rando.c, WITH_AP)
};

typedef struct ASObject
{
	u32 refcount;           // Reference count (starts at 1 on allocation)
	u32 num_properties;     // Number of properties allocated
	u32 num_used;           // Number of properties actually used
	ASProperty* properties; // Dynamic array of properties

	// Optional open-addressing name_hash->slot index, built lazily once an
	// object grows large (see PROP_HASH_THRESHOLD in object.c). NULL/0 means
	// "use the linear scan" (the common case for small objects).
	u32* hash_index;        // table of slot indices, or NULL
	u32 hash_capacity;      // power-of-2 capacity of hash_index, or 0

	// Interface support (for ActionScript 2.0 implements keyword)
	u32 interface_count;           // Number of interfaces this class implements
	struct ASObject** interfaces;  // Array of interface constructors

	// Native backing type (0 = pure ActionScript object, >0 = native-backed)
	u8 native_type;

	// --- Memory-reclamation instrumentation (Stage 0 of
	// SWFRecompDocs/plans/memory-reclamation-plan.md). Also the sweep
	// infrastructure for the (measurement-gated) Stage 3 collector. ---
	u8 mt_kind;             // MT_KIND_* allocation-site tag (leak attribution)
	u8 mt_mark;             // scratch mark bit (report classifier / future sweep)
	struct ASObject* mt_prev;  // intrusive all-objects list (O(1) link/unlink)
	struct ASObject* mt_next;
} ASObject;

// Allocation-site tags for leak attribution (mt_kind)
#define MT_KIND_PLAIN  0   // ordinary script object
#define MT_KIND_DPROPS 1   // allocated as a MovieClip's dynamic_props

struct ASProperty
{
	char* name;             // Property name (heap-allocated)
	u32 name_length;        // Length of property name
	u32 name_hash;          // Case-folded hash of name (fast pre-filter for lookups; see name_fold_hash in object.c)
	u8 flags;               // Property attribute flags (PROPERTY_FLAG_*)
	u16 flash_flags;        // Flash property flags (for ASSetPropFlags version visibility)
	ActionVar value;        // Property value (can be any type)
	void* getter;           // ASFunction* or NULL (for addProperty virtual properties)
	void* setter;           // ASFunction* or NULL (for addProperty virtual properties)
	u32 vprop_id;           // Unique id of this addProperty registration (0 = unassigned;
	                        // lazily assigned on first accessor dispatch). Keys the SWF7+
	                        // getter/setter re-entry counter: delete + re-addProperty
	                        // creates a new zeroed slot and therefore a fresh counter.
};

/**
 * Global Objects
 *
 * Global singleton objects available in ActionScript.
 */

// Global object (_global in ActionScript)
// Initialized on first use via initTime()
extern ASObject* global_object;

/**
 * Object Lifecycle Primitives
 *
 * These functions are called by generated code to manage object lifetimes.
 */

// Allocate new object with initial capacity
// Returns object with refcount = 1
ASObject* allocObject(SWFAppContext* app_context, u32 initial_capacity);

// allocObject + tags the object MT_KIND_DPROPS for leak attribution.
// Use for every `mc->dynamic_props = ...` attach site (behavior-identical to
// allocObject otherwise).
ASObject* allocDynamicProps(SWFAppContext* app_context, u32 initial_capacity);

/**
 * Memory-reclamation instrumentation (Stage 0)
 *
 * Cheap always-on counters + intrusive live lists, maintained by
 * allocObject/allocArray and the two release-at-zero blocks. The report is
 * emitted at exit only when the SWF_MEM_REPORT env var is set (native), so
 * default builds/CI output is byte-identical.
 */

// Live counts (total allocs minus frees) — cheap enough for a per-frame HUD.
u32 swfMemLiveObjects(void);
u32 swfMemLiveArrays(void);

// Classified live-set summary to stderr (native; also callable manually).
void swfMemReport(void);

// swfMemReport if SWF_MEM_REPORT is set (native builds; no-op otherwise).
// Called by the frame loops just before heap_shutdown — must NOT run from
// atexit, because heap_shutdown unmaps the pool that MovieClips live in.
// (An env-gated atexit fallback covers abnormal exits while the pool is
// still mapped, e.g. heap_alloc OOM exit(1).)
void swfMemReportAtExitIfEnabled(void);

// Called by heap_shutdown: the MC pool is about to be unmapped, so the
// report's registry walk is no longer safe (disables the atexit fallback).
void swfMemMarkUnsafeToWalk(void);

// Increment reference count
// Should be called when:
// - Storing object in a variable
// - Adding object to an array/container
// - Assigning object to a property
// - Returning object from a function
void retainObject(ASObject* obj);

// Decrement reference count, free if zero
// Should be called when:
// - Popping object from stack (if not stored)
// - Overwriting a variable that held an object
// - Removing object from array
// - Function/scope cleanup
void releaseObject(SWFAppContext* app_context, ASObject* obj);

/**
 * Property Management
 *
 * Functions for manipulating object properties.
 */

// Get property by name (returns NULL if not found)
ActionVar* getProperty(ASObject* obj, const char* name, u32 name_length);

// Get property by name with prototype chain traversal (returns NULL if not found)
// Walks up the __proto__ chain to find inherited properties
ActionVar* getPropertyWithPrototype(ASObject* obj, const char* name, u32 name_length);

// Find property struct with prototype chain traversal (returns ASProperty* or NULL)
// Unlike getPropertyWithPrototype which returns just the value, this returns the full
// property struct including getter/setter for addProperty virtual properties.
ASProperty* findPropertyStructWithPrototype(ASObject* obj, const char* name, u32 name_length);

// Set property by name (creates if not exists)
// Handles refcount management if value is an object
void setProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length, ActionVar* value);

// Set property with explicit flags (creates if not exists, sets flags on creation)
void setPropertyWithFlags(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length, ActionVar* value, u8 flags);

// Check if property exists ignoring flash_flags visibility (for hasOwnProperty)
bool hasPropertyRaw(ASObject* obj, const char* name, u32 name_length);
ASProperty* findPropertyRaw(ASObject* obj, const char* name, u32 name_length);

// Rebuild the property lookup index after directly reordering/removing entries
// in obj->properties[] outside object.c (no-op if the object has no index).
void objectRehashIndex(ASObject* obj);

// Check if a property with given flash_flags is hidden at the current SWF version
int isPropertyHiddenAtVersion(u16 flash_flags);

// Delete property by name (returns true if deleted or not found, false if protected)
// Handles refcount management if value is an object
bool deleteProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length);

// SWF version-aware name comparison (case-insensitive for SWF <= 6 with Unicode case folding)
int swf_name_match(const char* a, const char* b);

/**
 * Interface Management (ActionScript 2.0)
 *
 * Functions for implementing interface support via the implements keyword.
 */

// Set the list of interfaces that a constructor implements
// Used by ActionImplementsOp (0x2C)
// Takes ownership of the interfaces array
void setInterfaceList(SWFAppContext* app_context, ASObject* constructor, ASObject** interfaces, u32 count);

// Check if an object implements a specific interface
// Returns 1 if the object's constructor implements the interface, 0 otherwise
// Performs recursive check for interface inheritance
int implementsInterface(ASObject* obj, ASObject* interface_ctor);

// Get the constructor function for an object
// Returns the constructor property if it exists, NULL otherwise
ASObject* getConstructor(ASObject* obj);

/**
 * ASArray - ActionScript Array with Reference Counting
 *
 * Arrays store elements in a dynamic array with automatic growth.
 * Like objects, arrays use reference counting for memory management.
 */

typedef struct ASArray
{
	u32 refcount;           // Reference count (starts at 1 on allocation)
	u32 length;             // Logical length (stored as u32, displayed as i32)
	u32 capacity;           // Allocated capacity
	ActionVar* elements;    // Dynamic array of elements
	ASObject* props;        // Non-index string properties (lazily allocated)
	char** enum_keys;       // Insertion-ordered key names for enumeration (NULL until first set)
	u32 enum_count;         // Number of entries in enum_keys
	u32 enum_capacity;      // Allocated capacity of enum_keys

	// Memory-reclamation instrumentation (see ASObject counterparts)
	u8 mt_mark;             // scratch mark bit (report classifier / future sweep)
	struct ASArray* mt_prev;   // intrusive all-arrays list (O(1) link/unlink)
	struct ASArray* mt_next;
} ASArray;

/**
 * Array Lifecycle Primitives
 */

// Allocate new array with initial capacity
// Returns array with refcount = 1
ASArray* allocArray(SWFAppContext* app_context, u32 initial_capacity);

// Increment reference count for array
void retainArray(ASArray* arr);

// Decrement reference count for array, free if zero
void releaseArray(SWFAppContext* app_context, ASArray* arr);

// Get element at index (returns NULL if out of bounds)
ActionVar* getArrayElement(ASArray* arr, u32 index);

// Set element at index (grows array if needed)
void setArrayElement(SWFAppContext* app_context, ASArray* arr, u32 index, ActionVar* value);

// Track key insertion order for Flash-compatible for-in enumeration
void arrayTrackKey(ASArray* arr, const char* key, u32 key_len);
// Remove a key from the enumeration order (compacts the list).
void arrayUntrackKey(ASArray* arr, const char* key, u32 key_len);
// Move a key to the end of the enumeration order (Flash re-insert on assign).
void arrayReinsertKey(ASArray* arr, const char* key, u32 key_len);

/**
 * Debug/Testing Functions
 */

#ifdef DEBUG
// Verify object refcount matches expected value (assertion)
void assertRefcount(ASObject* obj, u32 expected);

// Print object state for debugging
void printObject(ASObject* obj);

// Print array state for debugging
void printArray(ASArray* arr);
#endif
