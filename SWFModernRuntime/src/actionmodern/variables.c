#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <errno.h>
#include <string.h>

#include <map.h>
#include <common.h>
#include <variables.h>

#define VAL(type, x) *((type*) x)

hashmap* var_map = NULL;
ActionVar** var_array = NULL;
size_t var_array_size = 0;

void initMap()
{
	var_map = hashmap_create();
}

void initVarArray(size_t max_string_id)
{
	var_array_size = max_string_id;
	var_array = (ActionVar**) calloc(var_array_size, sizeof(ActionVar*));

	if (!var_array)
	{
		EXC("Failed to allocate variable array\n");
		exit(1);
	}
}

static int free_variable_callback(const void *key, size_t ksize, uintptr_t value, void *usr)
{
	ActionVar* var = (ActionVar*) value;

	// Skip entries that are shared with var_array (will be freed by var_array loop)
	for (size_t i = 0; i < var_array_size; i++) {
		if (var_array[i] == var) return 0;
	}

	// Free heap-allocated strings
	if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory)
	{
		free(var->data.string_data.heap_ptr);
	}

	free(var);
	return 0;
}

void freeMap()
{
	if (var_map)
	{
		hashmap_iterate(var_map, free_variable_callback, NULL);
		hashmap_free(var_map);
		var_map = NULL;
	}

	// Free array-based variables
	if (var_array)
	{
		for (size_t i = 0; i < var_array_size; i++)
		{
			if (var_array[i])
			{
				// Free heap-allocated strings
				if (var_array[i]->type == ACTION_STACK_VALUE_STRING &&
				    var_array[i]->data.string_data.owns_memory)
				{
					free(var_array[i]->data.string_data.heap_ptr);
				}
				free(var_array[i]);
			}
		}
		free(var_array);
		var_array = NULL;
		var_array_size = 0;
	}
}

ActionVar* getVariableById(u32 string_id)
{
	if (string_id == 0 || string_id >= var_array_size)
	{
		// Invalid ID or dynamic string (ID = 0)
		return NULL;
	}

	// Lazy allocation
	if (!var_array[string_id])
	{
		ActionVar* var = (ActionVar*) malloc(sizeof(ActionVar));
		if (!var)
		{
			EXC("Failed to allocate variable\n");
			return NULL;
		}

		// Initialize with unset type (empty string, UTF-16 NULL with 0 length)
		var->type = ACTION_STACK_VALUE_STRING;
		var->str_size = 0;
		var->string_id = 0;
		var->data.string_data.heap_ptr = NULL;
		var->data.string_data.owns_memory = false;
		var->data.numeric_value = 0;

		var_array[string_id] = var;
	}

	return var_array[string_id];
}

ActionVar* getVariable(char* var_name, size_t key_size)
{
	ActionVar* var;

	if (hashmap_get(var_map, var_name, key_size, (uintptr_t*) &var))
	{
		return var;
	}

	do
	{
		var = (ActionVar*) malloc(sizeof(ActionVar));
	} while (errno != 0);

	// Initialize with unset type (empty string, UTF-16 NULL with 0 length)
	var->type = ACTION_STACK_VALUE_STRING;
	var->str_size = 0;
	var->string_id = 0;
	var->data.string_data.heap_ptr = NULL;
	var->data.string_data.owns_memory = false;
	var->data.numeric_value = 0;

	hashmap_set(var_map, var_name, key_size, (uintptr_t) var);

	return var;
}

bool hasVariable(char* var_name, size_t key_size)
{
	ActionVar* var;
	return hashmap_get(var_map, var_name, key_size, (uintptr_t*) &var);
}

void setVariableByName(const char* var_name, ActionVar* value)
{
	// If inside a function scope, define on local scope (not global)
	// This prevents DefineFunction parameter binding from leaking to root scope
	extern bool setVariableOnLocalScope(const char* var_name, ActionVar* value);
	if (setVariableOnLocalScope(var_name, value))
		return;

	size_t key_size = strlen(var_name);
	ActionVar* var = getVariable((char*)var_name, key_size);

	if (var == NULL) {
		return;
	}

	// Free old data if it was a heap-allocated string
	if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory) {
		free(var->data.string_data.heap_ptr);
		var->data.string_data.heap_ptr = NULL;
		var->data.string_data.owns_memory = false;
	}

	// Copy the new value
	var->type = value->type;
	var->str_size = value->str_size;
	var->data = value->data;
}

void setVariableWithValue(ActionVar* var, char* stack, u32 sp)
{
	// Free old string if variable owns memory
	if (var->type == ACTION_STACK_VALUE_STRING && var->data.string_data.owns_memory)
	{
		free(var->data.string_data.heap_ptr);
		var->data.string_data.owns_memory = false;
	}

	ActionStackValueType type = stack[sp];

	if (type == ACTION_STACK_VALUE_STRING)
	{
		// Copy UTF-16 string data to heap (stack data is transient)
		u32 u16_len = VAL(u32, &stack[sp + 8]);  // code unit count
		const uint16_t* src = (const uint16_t*) VAL(u64, &stack[sp + 16]);

		var->type = ACTION_STACK_VALUE_STRING;
		var->string_id = VAL(u32, &stack[sp + 12]);

		if (u16_len > 0 && src != NULL)
		{
			uint16_t* heap_copy = (uint16_t*) malloc(u16_len * sizeof(uint16_t));
			if (!heap_copy)
			{
				var->str_size = 0;
				var->data.numeric_value = 0;
				return;
			}
			memcpy(heap_copy, src, u16_len * sizeof(uint16_t));
			var->str_size = u16_len;
			var->data.string_data.heap_ptr = heap_copy;
			var->data.string_data.owns_memory = true;
		}
		else
		{
			var->str_size = 0;
			var->data.numeric_value = 0;
		}
	}
	else
	{
		// Numeric types - store directly
		var->type = type;
		var->str_size = VAL(u32, &stack[sp + 8]);
		var->data.numeric_value = VAL(u64, &stack[sp + 16]);
	}
}