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
};

typedef struct ASObject
{
	u32 refcount;           // Reference count (starts at 1 on allocation)
	u32 num_properties;     // Number of properties allocated
	u32 num_used;           // Number of properties actually used
	ASProperty* properties; // Dynamic array of properties

	// Interface support (for ActionScript 2.0 implements keyword)
	u32 interface_count;           // Number of interfaces this class implements
	struct ASObject** interfaces;  // Array of interface constructors

	// Native backing type (0 = pure ActionScript object, >0 = native-backed)
	u8 native_type;
} ASObject;

struct ASProperty
{
	char* name;             // Property name (heap-allocated)
	u32 name_length;        // Length of property name
	u8 flags;               // Property attribute flags (PROPERTY_FLAG_*)
	u16 flash_flags;        // Flash property flags (for ASSetPropFlags version visibility)
	ActionVar value;        // Property value (can be any type)
	void* getter;           // ASFunction* or NULL (for addProperty virtual properties)
	void* setter;           // ASFunction* or NULL (for addProperty virtual properties)
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
