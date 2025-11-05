#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include <actionmodern/object.h>

/**
 * Object Allocation
 *
 * Allocates a new ASObject with the specified initial capacity.
 * Returns object with refcount = 1 (caller owns the initial reference).
 */
ASObject* allocObject(u32 initial_capacity)
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
void releaseObject(ASObject* obj)
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
				free(obj->properties[i].name);
			}

			// If property value is an object, release it recursively
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* child_obj = (ASObject*) obj->properties[i].value.data.numeric_value;
				releaseObject(child_obj);
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
		if (obj->properties[i].name_length == name_length &&
		    strncmp(obj->properties[i].name, name, name_length) == 0)
		{
			return &obj->properties[i].value;
		}
	}

	return NULL;  // Property not found
}

/**
 * Set Property
 *
 * Sets a property value by name. Creates property if it doesn't exist.
 * Handles reference counting if value is an object.
 */
void setProperty(ASObject* obj, const char* name, u32 name_length, ActionVar* value)
{
	if (obj == NULL || name == NULL || value == NULL)
	{
		return;
	}

	// Check if property already exists
	for (u32 i = 0; i < obj->num_used; i++)
	{
		if (obj->properties[i].name_length == name_length &&
		    strncmp(obj->properties[i].name, name, name_length) == 0)
		{
			// Property exists - update value

			// Release old value if it was an object
			if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT)
			{
				ASObject* old_obj = (ASObject*) obj->properties[i].value.data.numeric_value;
				releaseObject(old_obj);
			}
			// Free old string if it owned memory
			else if (obj->properties[i].value.type == ACTION_STACK_VALUE_STRING &&
			         obj->properties[i].value.data.string_data.owns_memory)
			{
				free(obj->properties[i].value.data.string_data.heap_ptr);
			}

			// Set new value
			obj->properties[i].value = *value;

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
		// Grow by 50% or at least 4 slots
		u32 new_capacity = obj->num_properties == 0 ? 4 : (obj->num_properties * 3) / 2;
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
	obj->properties[index].name = (char*) malloc(name_length + 1);
	if (obj->properties[index].name == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate property name\n");
		obj->num_used--;
		return;
	}
	memcpy(obj->properties[index].name, name, name_length);
	obj->properties[index].name[name_length] = '\0';
	obj->properties[index].name_length = name_length;

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
#endif
