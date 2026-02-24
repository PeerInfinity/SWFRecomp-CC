#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include <actionmodern/object.h>
#include <actionmodern/action.h>
#include <heap.h>
#include "unicode_case_tables.h"

// UTF-8 decode one codepoint, advance pointer
static uint32_t _obj_utf8_decode(const unsigned char** pp)
{
	const unsigned char* p = *pp;
	uint32_t c = *p;
	if (c < 0x80) { (*pp)++; return c; }
	if ((c & 0xE0) == 0xC0) {
		uint32_t r = (c & 0x1F) << 6;
		if ((p[1] & 0xC0) == 0x80) { r |= (p[1] & 0x3F); *pp += 2; return r; }
		(*pp)++; return 0xFFFD;
	}
	if ((c & 0xF0) == 0xE0) {
		uint32_t r = (c & 0x0F) << 12;
		if ((p[1] & 0xC0) == 0x80 && (p[2] & 0xC0) == 0x80) {
			r |= ((p[1] & 0x3F) << 6) | (p[2] & 0x3F); *pp += 3; return r;
		}
		(*pp)++; return 0xFFFD;
	}
	if ((c & 0xF8) == 0xF0) {
		uint32_t r = (c & 0x07) << 18;
		if ((p[1] & 0xC0) == 0x80 && (p[2] & 0xC0) == 0x80 && (p[3] & 0xC0) == 0x80) {
			r |= ((p[1] & 0x3F) << 12) | ((p[2] & 0x3F) << 6) | (p[3] & 0x3F); *pp += 4; return r;
		}
		(*pp)++; return 0xFFFD;
	}
	(*pp)++; return 0xFFFD;
}

// Fold codepoint to lowercase for case-insensitive comparison
static uint32_t _obj_fold_lower(uint32_t c)
{
	if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
	if (c > 0x7F && c <= 0xFFFF) {
		int lo = 0, hi = CASE_MAP_UPPER_TO_LOWER_COUNT - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (case_map_upper_to_lower[mid][0] == (uint16_t)c) return case_map_upper_to_lower[mid][1];
			if (case_map_upper_to_lower[mid][0] < (uint16_t)c) lo = mid + 1; else hi = mid - 1;
		}
	}
	return c;
}

// SWF version-aware property name comparison
// For SWF <= 6: Unicode case-insensitive comparison
// For SWF >= 7: byte-exact comparison (strncmp)
static int prop_name_match(const char* a, u32 alen, const char* b, u32 blen)
{
	if (g_swf_version >= 7) {
		return alen == blen && strncmp(a, b, alen) == 0;
	}
	// SWF <= 6: Unicode case-insensitive
	const unsigned char* pa = (const unsigned char*)a;
	const unsigned char* ea = pa + alen;
	const unsigned char* pb = (const unsigned char*)b;
	const unsigned char* eb = pb + blen;
	while (pa < ea && pb < eb) {
		uint32_t ca = _obj_fold_lower(_obj_utf8_decode(&pa));
		uint32_t cb = _obj_fold_lower(_obj_utf8_decode(&pb));
		if (ca != cb) return 0;
	}
	return (pa >= ea && pb >= eb);
}

// Null-terminated SWF version-aware name comparison (exposed for tag_stubs.c)
// Returns 1 if names match, 0 if they don't
int swf_name_match(const char* a, const char* b)
{
	if (g_swf_version >= 7) {
		return strcmp(a, b) == 0;
	}
	// SWF <= 6: Unicode case-insensitive
	const unsigned char* pa = (const unsigned char*)a;
	const unsigned char* pb = (const unsigned char*)b;
	while (*pa && *pb) {
		uint32_t ca = _obj_fold_lower(_obj_utf8_decode(&pa));
		uint32_t cb = _obj_fold_lower(_obj_utf8_decode(&pb));
		if (ca != cb) return 0;
	}
	return (*pa == 0 && *pb == 0);
}

// Version-based property hiding masks for ASSetPropFlags
// When (property->flash_flags & FLASH_HIDE_MASK) != 0, property is hidden from GetMember
static const u16 flash_hide_masks[] = {
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, // SWF 0-4
	0x7480, // SWF 5
	0x7500, // SWF 6
	0x7000, // SWF 7
	0x6000, // SWF 8
	0x4000, // SWF 9
	0x0000, // SWF 10+
};
#define FLASH_HIDE_MASK (g_swf_version <= 10 ? flash_hide_masks[g_swf_version] : 0)

/**
 * Object Allocation
 *
 * Allocates a new ASObject with the specified initial capacity.
 * Returns object with refcount = 1 (caller owns the initial reference).
 */
ASObject* allocObject(SWFAppContext* app_context, u32 initial_capacity)
{
	ASObject* obj = (ASObject*) malloc(sizeof(ASObject));
	if (obj == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate ASObject\n");
		return NULL;
	}

	obj->refcount = 1;  // Initial reference owned by caller
	obj->num_properties = initial_capacity;
	obj->num_used = 0;

	// Initialize interface fields
	obj->interface_count = 0;
	obj->interfaces = NULL;

	// Allocate property array
	if (initial_capacity > 0)
	{
		obj->properties = (ASProperty*) malloc(sizeof(ASProperty) * initial_capacity);
		if (obj->properties == NULL)
		{
			fprintf(stderr, "ERROR: Failed to allocate property array\n");
			free(obj);
			return NULL;
		}

		// Initialize properties to zero
		memset(obj->properties, 0, sizeof(ASProperty) * initial_capacity);
	}
	else
	{
		obj->properties = NULL;
	}

#ifdef DEBUG
	printf("[DEBUG] allocObject: obj=%p, refcount=%u, capacity=%u\n",
		(void*)obj, obj->refcount, obj->num_properties);
#endif

	return obj;
}

/**
 * Retain Object
 *
 * Increments the reference count of an object.
 * Called when storing object in a variable, property, or array.
 */
void retainObject(ASObject* obj)
{
	if (obj == NULL)
	{
		return;
	}

	obj->refcount++;

#ifdef DEBUG
	printf("[DEBUG] retainObject: obj=%p, refcount=%u -> %u\n",
		(void*)obj, obj->refcount - 1, obj->refcount);
#endif
}

/**
 * Release Object
 *
 * Decrements the reference count of an object.
 * When refcount reaches 0, frees the object and all its properties.
 * Recursively releases any objects stored in properties.
 */
void releaseObject(SWFAppContext* app_context, ASObject* obj)
{
	if (obj == NULL)
	{
		return;
	}

#ifdef DEBUG
	printf("[DEBUG] releaseObject: obj=%p, refcount=%u -> %u\n",
		(void*)obj, obj->refcount, obj->refcount - 1);
#endif

	obj->refcount--;

	if (obj->refcount == 0)
	{
#ifdef DEBUG
		printf("[DEBUG] releaseObject: obj=%p reached refcount=0, freeing\n", (void*)obj);
#endif

		// Release all property values
		for (u32 i = 0; i < obj->num_used; i++)
		{
			// Free property name (always heap-allocated)
			if (obj->properties[i].name != NULL)
			{
				FREE(obj->properties[i].name);
			}

			// If property value is an object, release it recursively
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* child_obj = (ASObject*) obj->properties[i].value.data.numeric_value;
				releaseObject(app_context, child_obj);
			}
			// If property value is a string that owns memory, free it
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_STRING &&
			         obj->properties[i].value.data.string_data.owns_memory)
			{
				free(obj->properties[i].value.data.string_data.heap_ptr);
			}
		}

		// Free property array
		if (obj->properties != NULL)
		{
			free(obj->properties);
		}

		// Release interface objects
		if (obj->interfaces != NULL)
		{
			for (u32 i = 0; i < obj->interface_count; i++)
			{
				releaseObject(app_context, obj->interfaces[i]);
			}
			free(obj->interfaces);
		}

		// Free object itself
		free(obj);
	}
}

/**
 * Get Property
 *
 * Retrieves a property value by name.
 * Returns pointer to ActionVar, or NULL if property not found.
 */
// Find property struct by name (ignoring version hiding) - for ASSetPropFlags
ASProperty* findPropertyRaw(ASObject* obj, const char* name, u32 name_length)
{
	if (obj == NULL || name == NULL) return NULL;
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (prop_name_match(obj->properties[i].name, obj->properties[i].name_length, name, name_length))
		{
			return &obj->properties[i];
		}
	}
	return NULL;
}

bool hasPropertyRaw(ASObject* obj, const char* name, u32 name_length)
{
	return findPropertyRaw(obj, name, name_length) != NULL;
}

ActionVar* getProperty(ASObject* obj, const char* name, u32 name_length)
{
	if (obj == NULL || name == NULL)
	{
		return NULL;
	}

	// Linear search through properties
	// For production, consider hash table for large objects
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (prop_name_match(obj->properties[i].name, obj->properties[i].name_length, name, name_length))
		{
			// Check version-based hiding (ASSetPropFlags)
			if (FLASH_HIDE_MASK && (obj->properties[i].flash_flags & FLASH_HIDE_MASK))
			{
				return NULL;  // Property hidden by version flags
			}
			return &obj->properties[i].value;
		}
	}

	return NULL;  // Property not found
}

/**
 * Get Property With Prototype Chain
 *
 * Retrieves a property value by name, searching up the prototype chain via __proto__.
 * Returns pointer to ActionVar, or NULL if property not found in entire chain.
 *
 * This implements proper prototype-based inheritance for ActionScript.
 */
ActionVar* getPropertyWithPrototype(ASObject* obj, const char* name, u32 name_length)
{
	if (obj == NULL || name == NULL)
	{
		return NULL;
	}

	ASObject* current = obj;
	int max_depth = 256;  // Prevent infinite loops in deep prototype chains
	int depth = 0;

	while (current != NULL && depth < max_depth)
	{
		depth++;

		// Search own properties first
		ActionVar* prop = getProperty(current, name, name_length);
		if (prop != NULL)
		{
			return prop;
		}

		// Property not found on this object - walk up to __proto__
		ActionVar* proto_var = getProperty(current, "__proto__", 9);
		if (proto_var == NULL || proto_var->type != ACTION_STACK_VALUE_OBJECT)
		{
			// No __proto__ property or not an object - end of chain
			break;
		}

		// Move to next object in prototype chain
		ASObject* next = (ASObject*) proto_var->data.numeric_value;

		// Cycle detection: if we'd revisit the original object, it's circular
		if (next == obj)
		{
			g_execution_halted = 1;
			return NULL;
		}

		current = next;
	}

	// Depth limit exceeded — treat as recursion limit error (halt execution)
	if (depth >= max_depth)
	{
		g_execution_halted = 1;
	}

	return NULL;  // Property not found in entire prototype chain
}

/**
 * Find Property Struct With Prototype Chain
 *
 * Like getPropertyWithPrototype but returns the ASProperty struct instead of just the value.
 * This is needed to check for getter/setter (addProperty virtual properties).
 * Does NOT apply flash_flags hiding — that's handled by the caller.
 */
ASProperty* findPropertyStructWithPrototype(ASObject* obj, const char* name, u32 name_length)
{
	if (obj == NULL || name == NULL) return NULL;

	ASObject* current = obj;
	int max_depth = 256;
	int depth = 0;

	while (current != NULL && depth < max_depth)
	{
		depth++;

		// Search own properties
		ASProperty* prop = findPropertyRaw(current, name, name_length);
		if (prop != NULL)
		{
			// Check version-based hiding
			if (FLASH_HIDE_MASK && (prop->flash_flags & FLASH_HIDE_MASK))
				return NULL;
			return prop;
		}

		// Walk up __proto__
		ActionVar* proto_var = getProperty(current, "__proto__", 9);
		if (proto_var == NULL || proto_var->type != ACTION_STACK_VALUE_OBJECT)
			break;

		ASObject* next = (ASObject*) proto_var->data.numeric_value;
		if (next == obj)
		{
			g_execution_halted = 1;
			return NULL;
		}
		current = next;
	}

	if (depth >= max_depth) g_execution_halted = 1;
	return NULL;
}

/**
 * Set Property
 *
 * Sets a property value by name. Creates property if it doesn't exist.
 * Handles reference counting if value is an object.
 */
void setProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length, ActionVar* value)
{
	if (obj == NULL || name == NULL || value == NULL || name_length == 0)
	{
		return;
	}

	// Check if property already exists
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (prop_name_match(obj->properties[i].name, obj->properties[i].name_length, name, name_length))
		{
			// Property exists - update value

			// Release old value if it was an object
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* old_obj = (ASObject*) obj->properties[i].value.data.numeric_value;
				releaseObject(app_context, old_obj);
			}
			// Free old string if it owned memory
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_STRING &&
			         obj->properties[i].value.data.string_data.owns_memory)
			{
				free(obj->properties[i].value.data.string_data.heap_ptr);
			}

			// Set new value and clear version-based hiding flags
			// (In Flash, setting a property via SetMember clears ASSetPropFlags visibility)
			obj->properties[i].value = *value;
			obj->properties[i].flash_flags = 0;

			// Retain new value if it's an object
			if (value->type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* new_obj = (ASObject*) value->data.numeric_value;
				retainObject(new_obj);
			}

#ifdef DEBUG
			printf("[DEBUG] setProperty: obj=%p, updated property '%.*s'\n",
				(void*)obj, name_length, name);
#endif

			return;
		}
	}

	// Property doesn't exist - create new one

	// Check if we need to grow the property array
	if (obj->num_used >= obj->num_properties)
	{
		// Grow by 50% or at least 4 slots, ensuring at least +1
		u32 grow = (obj->num_properties * 3) / 2;
		u32 new_capacity = grow > obj->num_properties + 1 ? grow : obj->num_properties + 4;
		ASProperty* new_props = (ASProperty*) realloc(obj->properties,
		                                               sizeof(ASProperty) * new_capacity);
		if (new_props == NULL)
		{
			fprintf(stderr, "ERROR: Failed to grow property array\n");
			return;
		}

		obj->properties = new_props;
		obj->num_properties = new_capacity;

		// Zero out new slots
		memset(&obj->properties[obj->num_used], 0,
		       sizeof(ASProperty) * (new_capacity - obj->num_used));
	}

	// Add new property
	u32 index = obj->num_used;
	obj->num_used++;

	// Allocate and copy property name
	obj->properties[index].name = (char*) HALLOC(name_length + 1);
	if (obj->properties[index].name == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate property name\n");
		obj->num_used--;
		return;
	}
	memcpy(obj->properties[index].name, name, name_length);
	obj->properties[index].name[name_length] = '\0';
	obj->properties[index].name_length = name_length;

	// Set default property flags (enumerable, writable, configurable)
	obj->properties[index].flags = PROPERTY_FLAGS_DEFAULT;

	// __proto__ and constructor are DontEnum (not enumerable in for-in)
	if ((name_length == 9 && strncmp(name, "__proto__", 9) == 0) ||
	    (name_length == 11 && strncmp(name, "constructor", 11) == 0))
	{
		obj->properties[index].flags &= ~PROPERTY_FLAG_ENUMERABLE;
	}

	// Initialize getter/setter to NULL (no virtual property)
	obj->properties[index].getter = NULL;
	obj->properties[index].setter = NULL;

	// Set value
	obj->properties[index].value = *value;

	// Retain if value is an object
	if (value->type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* new_obj = (ASObject*) value->data.numeric_value;
		retainObject(new_obj);
	}

#ifdef DEBUG
	printf("[DEBUG] setProperty: obj=%p, created property '%.*s', num_used=%u\n",
		(void*)obj, name_length, name, obj->num_used);
#endif
}

/**
 * Set Property With Flags
 *
 * Like setProperty but allows specifying explicit property flags on creation.
 * If the property already exists, updates the value (does NOT change flags).
 */
void setPropertyWithFlags(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length, ActionVar* value, u8 flags)
{
	if (obj == NULL || name == NULL || value == NULL || name_length == 0) return;

	// If property already exists, just update the value
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (prop_name_match(obj->properties[i].name, obj->properties[i].name_length, name, name_length))
		{
			// Release old value
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
				releaseObject(app_context, (ASObject*) obj->properties[i].value.data.numeric_value);
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_STRING &&
			         obj->properties[i].value.data.string_data.owns_memory)
				free(obj->properties[i].value.data.string_data.heap_ptr);

			obj->properties[i].value = *value;
			obj->properties[i].flash_flags = 0;

			if (value->type == ACTION_STACK_VALUE_OBJECT)
				retainObject((ASObject*) value->data.numeric_value);
			return;
		}
	}

	// Property doesn't exist — use setProperty to create it, then override flags
	setProperty(app_context, obj, name, name_length, value);

	// Override flags on the newly created property (last in array)
	if (obj->num_used > 0)
	{
		ASProperty* new_prop = &obj->properties[obj->num_used - 1];
		if (prop_name_match(new_prop->name, new_prop->name_length, name, name_length))
		{
			new_prop->flags = flags;
		}
	}
}

/**
 * Delete Property
 *
 * Deletes a property by name. Returns true if deleted or not found (Flash behavior).
 * Handles reference counting if value is an object/array.
 */
bool deleteProperty(SWFAppContext* app_context, ASObject* obj, const char* name, u32 name_length)
{
	if (obj == NULL || name == NULL)
	{
		return true;  // Flash behavior: delete on null returns true
	}

	// Find property by name
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (prop_name_match(obj->properties[i].name, obj->properties[i].name_length, name, name_length))
		{
			// Check if property is configurable (deletable)
			if (!(obj->properties[i].flags & PROPERTY_FLAG_CONFIGURABLE))
			{
				return false;  // Cannot delete non-configurable property
			}

			// Property found - delete it

			// 1. Release the property value if it's an object/array
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* child_obj = (ASObject*) obj->properties[i].value.data.numeric_value;
				releaseObject(app_context, child_obj);
			}
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_ARRAY)
			{
				ASArray* child_arr = (ASArray*) obj->properties[i].value.data.numeric_value;
				releaseArray(app_context, child_arr);
			}
			// Free string if it owns memory
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_STRING &&
			         obj->properties[i].value.data.string_data.owns_memory)
			{
				free(obj->properties[i].value.data.string_data.heap_ptr);
			}

			// 2. Free the property name
			if (obj->properties[i].name != NULL)
			{
				FREE(obj->properties[i].name);
			}

			// 3. Shift remaining properties down to fill the gap
			for (u32 j = i; j < obj->num_used - 1; j++)
			{
				obj->properties[j] = obj->properties[j + 1];
			}

			// 4. Decrement the number of used slots
			obj->num_used--;

			// 5. Zero out the last slot
			memset(&obj->properties[obj->num_used], 0, sizeof(ASProperty));

#ifdef DEBUG
			printf("[DEBUG] deleteProperty: obj=%p, deleted property '%.*s', num_used=%u\n",
				(void*)obj, name_length, name, obj->num_used);
#endif

			return true;
		}
	}

	// Property not found - Flash AS2 returns false for non-existent properties
#ifdef DEBUG
	printf("[DEBUG] deleteProperty: obj=%p, property '%.*s' not found (returning false)\n",
		(void*)obj, name_length, name);
#endif

	return false;
}

/**
 * Interface Management (ActionScript 2.0)
 */

/**
 * Set Interface List
 *
 * Sets the list of interfaces that a constructor implements.
 * Takes ownership of the interfaces array.
 * Called by ActionImplementsOp (0x2C).
 */
void setInterfaceList(SWFAppContext* app_context, ASObject* constructor, ASObject** interfaces, u32 count)
{
	if (constructor == NULL)
	{
		// Free interfaces array if constructor is NULL
		if (interfaces != NULL)
		{
			for (u32 i = 0; i < count; i++)
			{
				releaseObject(app_context, interfaces[i]);
			}
			free(interfaces);
		}
		return;
	}

	// Release old interfaces if they exist
	if (constructor->interfaces != NULL)
	{
		for (u32 i = 0; i < constructor->interface_count; i++)
		{
			releaseObject(app_context, constructor->interfaces[i]);
		}
		free(constructor->interfaces);
	}

	// Set new interfaces
	constructor->interfaces = interfaces;
	constructor->interface_count = count;

	// Retain each interface object
	if (interfaces != NULL)
	{
		for (u32 i = 0; i < count; i++)
		{
			retainObject(interfaces[i]);
		}
	}

#ifdef DEBUG
	printf("[DEBUG] setInterfaceList: constructor=%p, interface_count=%u\n",
		(void*)constructor, count);
#endif
}

/**
 * Implements Interface
 *
 * Check if an object implements a specific interface.
 * Returns 1 if the object's constructor implements the interface, 0 otherwise.
 * Performs recursive check for interface inheritance.
 */
int implementsInterface(ASObject* obj, ASObject* interface_ctor)
{
	if (obj == NULL || interface_ctor == NULL)
	{
		return 0;
	}

	// Get the object's constructor
	ASObject* obj_ctor = getConstructor(obj);
	if (obj_ctor == NULL)
	{
		return 0;
	}

	// Check if constructor implements the interface
	for (u32 i = 0; i < obj_ctor->interface_count; i++)
	{
		// Direct match
		if (obj_ctor->interfaces[i] == interface_ctor)
		{
			return 1;
		}

		// Recursive check for interface inheritance
		// (interfaces can extend other interfaces)
		if (implementsInterface(obj_ctor->interfaces[i], interface_ctor))
		{
			return 1;
		}
	}

	return 0;
}

/**
 * Get Constructor
 *
 * Get the constructor function for an object.
 * Returns the "constructor" property if it exists, NULL otherwise.
 */
ASObject* getConstructor(ASObject* obj)
{
	if (obj == NULL)
	{
		return NULL;
	}

	// Look for "constructor" property
	static const char* constructor_name = "constructor";
	ActionVar* constructor_var = getProperty(obj, constructor_name, strlen(constructor_name));

	if (constructor_var != NULL && constructor_var->type == ACTION_STACK_VALUE_OBJECT)
	{
		return (ASObject*) constructor_var->data.numeric_value;
	}

	return NULL;
}

/**
 * Debug Functions
 */

#ifdef DEBUG
void assertRefcount(ASObject* obj, u32 expected)
{
	if (obj == NULL)
	{
		fprintf(stderr, "ERROR: assertRefcount called with NULL object\n");
		assert(0);
	}

	if (obj->refcount != expected)
	{
		fprintf(stderr, "ERROR: refcount assertion failed: expected %u, got %u\n",
			expected, obj->refcount);
		assert(0);
	}

	printf("[DEBUG] assertRefcount: obj=%p, refcount=%u (OK)\n", (void*)obj, expected);
}

void printObject(ASObject* obj)
{
	if (obj == NULL)
	{
		printf("Object: NULL\n");
		return;
	}

	printf("Object: %p\n", (void*)obj);
	printf("  refcount: %u\n", obj->refcount);
	printf("  num_properties: %u\n", obj->num_properties);
	printf("  num_used: %u\n", obj->num_used);
	printf("  properties:\n");

	for (u32 i = 0; i < obj->num_used; i++)
	{
		printf("    [%u] '%.*s' = ",
			i, obj->properties[i].name_length, obj->properties[i].name);

		switch (obj->properties[i].value.type)
		{
			case ACTION_STACK_VALUE_F32:
				printf("%.15g (F32)\n", *((float*)&obj->properties[i].value.data.numeric_value));
				break;

			case ACTION_STACK_VALUE_F64:
				printf("%.15g (F64)\n", *((double*)&obj->properties[i].value.data.numeric_value));
				break;

			case ACTION_STACK_VALUE_STRING:
			{
				const char* str = obj->properties[i].value.data.string_data.owns_memory ?
					obj->properties[i].value.data.string_data.heap_ptr :
					(const char*)obj->properties[i].value.data.numeric_value;
				printf("'%.*s' (STRING)\n", obj->properties[i].value.str_size, str);
				break;
			}

			case ACTION_STACK_VALUE_OBJECT:
				printf("%p (OBJECT)\n", (void*)obj->properties[i].value.data.numeric_value);
				break;

			default:
				printf("(unknown type %d)\n", obj->properties[i].value.type);
				break;
		}
	}
}

void printArray(ASArray* arr)
{
	if (arr == NULL)
	{
		printf("Array: NULL\n");
		return;
	}

	printf("Array: %p\n", (void*)arr);
	printf("  refcount: %u\n", arr->refcount);
	printf("  length: %u\n", arr->length);
	printf("  capacity: %u\n", arr->capacity);
	printf("  elements:\n");

	for (u32 i = 0; i < arr->length; i++)
	{
		printf("    [%u] = ", i);

		switch (arr->elements[i].type)
		{
			case ACTION_STACK_VALUE_F32:
				printf("%.15g (F32)\n", *((float*)&arr->elements[i].data.numeric_value));
				break;

			case ACTION_STACK_VALUE_F64:
				printf("%.15g (F64)\n", *((double*)&arr->elements[i].data.numeric_value));
				break;

			case ACTION_STACK_VALUE_STRING:
			{
				const char* str = arr->elements[i].data.string_data.owns_memory ?
					arr->elements[i].data.string_data.heap_ptr :
					(const char*)arr->elements[i].data.numeric_value;
				printf("'%.*s' (STRING)\n", arr->elements[i].str_size, str);
				break;
			}

			case ACTION_STACK_VALUE_OBJECT:
				printf("%p (OBJECT)\n", (void*)arr->elements[i].data.numeric_value);
				break;

			case ACTION_STACK_VALUE_ARRAY:
				printf("%p (ARRAY)\n", (void*)arr->elements[i].data.numeric_value);
				break;

			default:
				printf("(unknown type %d)\n", arr->elements[i].type);
				break;
		}
	}
}
#endif

/**
 * Array Implementation
 */

// Track key insertion order for Flash-compatible for-in enumeration.
// Only adds the key if it's not already in the list (first-write wins).
void arrayTrackKey(ASArray* arr, const char* key, u32 key_len)
{
	// Check if already tracked
	for (u32 i = 0; i < arr->enum_count; i++)
	{
		if (strlen(arr->enum_keys[i]) == key_len &&
		    memcmp(arr->enum_keys[i], key, key_len) == 0)
			return;  // Already tracked
	}

	// Grow if needed
	if (arr->enum_count >= arr->enum_capacity)
	{
		u32 new_cap = arr->enum_capacity == 0 ? 8 : arr->enum_capacity * 2;
		char** new_keys = (char**) realloc(arr->enum_keys, sizeof(char*) * new_cap);
		if (new_keys == NULL) return;
		arr->enum_keys = new_keys;
		arr->enum_capacity = new_cap;
	}

	// Store copy of key
	char* key_copy = (char*) malloc(key_len + 1);
	if (key_copy == NULL) return;
	memcpy(key_copy, key, key_len);
	key_copy[key_len] = '\0';
	arr->enum_keys[arr->enum_count++] = key_copy;
}

ASArray* allocArray(SWFAppContext* app_context, u32 initial_capacity)
{
	ASArray* arr = (ASArray*) malloc(sizeof(ASArray));
	if (arr == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate ASArray\n");
		return NULL;
	}

	arr->refcount = 1;  // Initial reference owned by caller
	arr->length = 0;
	arr->capacity = initial_capacity > 0 ? initial_capacity : 4;

	// Allocate element array
	arr->elements = (ActionVar*) malloc(sizeof(ActionVar) * arr->capacity);
	if (arr->elements == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate array elements\n");
		free(arr);
		return NULL;
	}

	// Initialize elements to HOLE (unset sentinel)
	for (u32 i = 0; i < arr->capacity; i++)
	{
		arr->elements[i].type = ACTION_STACK_VALUE_HOLE;
		arr->elements[i].str_size = 0;
		arr->elements[i].data.numeric_value = 0;
	}

	arr->props = NULL;  // Lazily allocated for non-index properties
	arr->enum_keys = NULL;
	arr->enum_count = 0;
	arr->enum_capacity = 0;

#ifdef DEBUG
	printf("[DEBUG] allocArray: arr=%p, refcount=%u, capacity=%u\n",
		(void*)arr, arr->refcount, arr->capacity);
#endif

	return arr;
}

void retainArray(ASArray* arr)
{
	if (arr == NULL)
	{
		return;
	}

	arr->refcount++;

#ifdef DEBUG
	printf("[DEBUG] retainArray: arr=%p, refcount=%u -> %u\n",
		(void*)arr, arr->refcount - 1, arr->refcount);
#endif
}

void releaseArray(SWFAppContext* app_context, ASArray* arr)
{
	if (arr == NULL)
	{
		return;
	}

#ifdef DEBUG
	printf("[DEBUG] releaseArray: arr=%p, refcount=%u -> %u\n",
		(void*)arr, arr->refcount, arr->refcount - 1);
#endif

	arr->refcount--;

	if (arr->refcount == 0)
	{
#ifdef DEBUG
		printf("[DEBUG] releaseArray: arr=%p reached refcount=0, freeing\n", (void*)arr);
#endif

		// Release all element values
		for (u32 i = 0; i < arr->length; i++)
		{
			// If element is an object, release it recursively
			if (arr->elements[i].type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* child_obj = (ASObject*) arr->elements[i].data.numeric_value;
				releaseObject(app_context, child_obj);
			}
			// If element is an array, release it recursively
			else if (arr->elements[i].type == ACTION_STACK_VALUE_ARRAY)
			{
				ASArray* child_arr = (ASArray*) arr->elements[i].data.numeric_value;
				releaseArray(app_context, child_arr);
			}
			// If element is a string that owns memory, free it
			else if (arr->elements[i].type == ACTION_STACK_VALUE_STRING &&
			         arr->elements[i].data.string_data.owns_memory)
			{
				free(arr->elements[i].data.string_data.heap_ptr);
			}
		}

		// Free element array
		if (arr->elements != NULL)
		{
			free(arr->elements);
		}

		// Free non-index properties object
		if (arr->props != NULL)
		{
			releaseObject(app_context, arr->props);
		}

		// Free enumeration key tracking
		if (arr->enum_keys != NULL)
		{
			for (u32 i = 0; i < arr->enum_count; i++)
				free(arr->enum_keys[i]);
			free(arr->enum_keys);
		}

		// Free array itself
		free(arr);
	}
}

ActionVar* getArrayElement(ASArray* arr, u32 index)
{
	if (arr == NULL || index >= arr->length)
	{
		return NULL;
	}

	return &arr->elements[index];
}

void setArrayElement(SWFAppContext* app_context, ASArray* arr, u32 index, ActionVar* value)
{
	if (arr == NULL || value == NULL)
	{
		return;
	}

	// Grow array if needed
	if (index >= arr->capacity)
	{
		u32 new_capacity = (index + 1) * 2;  // Grow to accommodate index
		ActionVar* new_elements = (ActionVar*) realloc(arr->elements,
		                                                sizeof(ActionVar) * new_capacity);
		if (new_elements == NULL)
		{
			fprintf(stderr, "ERROR: Failed to grow array\n");
			return;
		}

		arr->elements = new_elements;

		// Initialize new slots to HOLE (unset)
		for (u32 i = arr->capacity; i < new_capacity; i++)
		{
			arr->elements[i].type = ACTION_STACK_VALUE_HOLE;
			arr->elements[i].str_size = 0;
			arr->elements[i].data.numeric_value = 0;
		}

		arr->capacity = new_capacity;
	}

	// Release old value if it exists and is an object/array
	if (index < arr->length)
	{
		if (arr->elements[index].type == ACTION_STACK_VALUE_OBJECT)
		{
			ASObject* old_obj = (ASObject*) arr->elements[index].data.numeric_value;
			releaseObject(app_context, old_obj);
		}
		else if (arr->elements[index].type == ACTION_STACK_VALUE_ARRAY)
		{
			ASArray* old_arr = (ASArray*) arr->elements[index].data.numeric_value;
			releaseArray(app_context, old_arr);
		}
		else if (arr->elements[index].type == ACTION_STACK_VALUE_STRING &&
		         arr->elements[index].data.string_data.owns_memory)
		{
			free(arr->elements[index].data.string_data.heap_ptr);
		}
	}

	// Set new value
	arr->elements[index] = *value;

	// Track insertion order for enumeration
	{
		char idx_buf[12];
		int len = snprintf(idx_buf, sizeof(idx_buf), "%u", index);
		arrayTrackKey(arr, idx_buf, (u32)len);
	}

	// Update length if needed
	if (index >= arr->length)
	{
		arr->length = index + 1;
	}

	// Retain new value if it's an object or array
	if (value->type == ACTION_STACK_VALUE_OBJECT)
	{
		ASObject* new_obj = (ASObject*) value->data.numeric_value;
		retainObject(new_obj);
	}
	else if (value->type == ACTION_STACK_VALUE_ARRAY)
	{
		ASArray* new_arr = (ASArray*) value->data.numeric_value;
		retainArray(new_arr);
	}

#ifdef DEBUG
	printf("[DEBUG] setArrayElement: arr=%p, index=%u, length=%u\n",
		(void*)arr, index, arr->length);
#endif
}
