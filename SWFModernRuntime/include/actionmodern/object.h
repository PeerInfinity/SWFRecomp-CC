#pragma once

#include <common.h>
#include <actionmodern/variables.h>

/**
 * ASObject - ActionScript Object with Reference Counting
 *
 * This structure implements compile-time reference counting for object/array opcodes.
 * The recompiler (SWFRecomp) emits inline refcount increment/decrement operations,
 * providing deterministic memory management without runtime GC.
 */

// Forward declaration for property structure
typedef struct ASProperty ASProperty;

typedef struct ASObject
{
	u32 refcount;           // Reference count (starts at 1 on allocation)
	u32 num_properties;     // Number of properties allocated
	u32 num_used;           // Number of properties actually used
	ASProperty* properties; // Dynamic array of properties

	// Interface support (for ActionScript 2.0 implements keyword)
	u32 interface_count;           // Number of interfaces this class implements
	struct ASObject** interfaces;  // Array of interface constructors
} ASObject;

struct ASProperty
{
	char* name;             // Property name (heap-allocated)
	u32 name_length;        // Length of property name
	ActionVar value;        // Property value (can be any type)
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
ASObject* allocObject(u32 initial_capacity);

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
void releaseObject(ASObject* obj);

/**
 * Property Management
 *
 * Functions for manipulating object properties.
 */

// Get property by name (returns NULL if not found)
ActionVar* getProperty(ASObject* obj, const char* name, u32 name_length);

// Set property by name (creates if not exists)
// Handles refcount management if value is an object
void setProperty(ASObject* obj, const char* name, u32 name_length, ActionVar* value);

// Delete property by name (returns true if deleted or not found, false if protected)
// Handles refcount management if value is an object
bool deleteProperty(ASObject* obj, const char* name, u32 name_length);

/**
 * Interface Management (ActionScript 2.0)
 *
 * Functions for implementing interface support via the implements keyword.
 */

// Set the list of interfaces that a constructor implements
// Used by ActionImplementsOp (0x2C)
// Takes ownership of the interfaces array
void setInterfaceList(ASObject* constructor, ASObject** interfaces, u32 count);

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
	u32 length;             // Number of elements in the array
	u32 capacity;           // Allocated capacity
	ActionVar* elements;    // Dynamic array of elements
} ASArray;

/**
 * Array Lifecycle Primitives
 */

// Allocate new array with initial capacity
// Returns array with refcount = 1
ASArray* allocArray(u32 initial_capacity);

// Increment reference count for array
void retainArray(ASArray* arr);

// Decrement reference count for array, free if zero
void releaseArray(ASArray* arr);

// Get element at index (returns NULL if out of bounds)
ActionVar* getArrayElement(ASArray* arr, u32 index);

// Set element at index (grows array if needed)
void setArrayElement(ASArray* arr, u32 index, ActionVar* value);

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
