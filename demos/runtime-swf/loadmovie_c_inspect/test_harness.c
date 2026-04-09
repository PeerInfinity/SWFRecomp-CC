/*
 * Test harness for loadmovie_c_inspect — Demo 3.
 *
 * After tick 2 (child SWF loaded), walks runtime internals to discover
 * what is visible from C code vs what ActionScript can see.
 */

#include <stdio.h>
#include <string.h>
#include <swf.h>
#include <action.h>
#include <object.h>
#include <stackvalue.h>
#include <variables.h>

/* Format an ActionVar value as a short string */
static void format_value(ActionVar* v, char* buf, int buf_size)
{
	if (v == NULL) { snprintf(buf, buf_size, "(null)"); return; }
	switch (v->type) {
	case ACTION_STACK_VALUE_STRING: {
		const uint16_t* u16 = (const uint16_t*)(uintptr_t)v->data.numeric_value;
		if (u16 == NULL) { snprintf(buf, buf_size, "\"\""); return; }
		char tmp[128];
		int pos = 0;
		for (u32 i = 0; i < v->str_size && pos < 120; i++) {
			uint16_t ch = u16[i];
			tmp[pos++] = (ch < 0x80) ? (char)ch : '?';
		}
		tmp[pos] = '\0';
		snprintf(buf, buf_size, "\"%s\"", tmp);
		break;
	}
	case ACTION_STACK_VALUE_F32:
		snprintf(buf, buf_size, "%g", *(float*)&v->data.numeric_value);
		break;
	case ACTION_STACK_VALUE_F64:
		snprintf(buf, buf_size, "%g", *(double*)&v->data.numeric_value);
		break;
	case ACTION_STACK_VALUE_NULL: snprintf(buf, buf_size, "null"); break;
	case ACTION_STACK_VALUE_UNDEFINED: snprintf(buf, buf_size, "undefined"); break;
	case ACTION_STACK_VALUE_BOOLEAN:
		snprintf(buf, buf_size, "%s", v->data.numeric_value ? "true" : "false");
		break;
	case ACTION_STACK_VALUE_OBJECT: snprintf(buf, buf_size, "[object]"); break;
	case ACTION_STACK_VALUE_FUNCTION: snprintf(buf, buf_size, "[function]"); break;
	case ACTION_STACK_VALUE_ARRAY: snprintf(buf, buf_size, "[array]"); break;
	case ACTION_STACK_VALUE_MOVIECLIP: snprintf(buf, buf_size, "[movieclip]"); break;
	default: snprintf(buf, buf_size, "[type=%d]", v->type); break;
	}
}

static void dump_object_props(ASObject* obj, const char* label, int max_show)
{
	if (obj == NULL) { printf("  %s: (null)\n", label); return; }
	printf("  %s: %u used / %u allocated\n", label, obj->num_used, obj->num_properties);
	int shown = 0;
	for (u32 i = 0; i < obj->num_properties && shown < max_show; i++) {
		ASProperty* p = &obj->properties[i];
		if (p->name == NULL) continue;
		char val_buf[256];
		format_value(&p->value, val_buf, sizeof(val_buf));
		printf("    %s = %s\n", p->name, val_buf);
		shown++;
	}
	if (shown < (int)obj->num_used)
		printf("    ... and %d more\n", (int)obj->num_used - shown);
}

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 2) return;

	printf("=== C HARNESS: runtime inspection ===\n");

	/* 1. Holder MovieClip */
	MovieClip* holder = actionFindOrCreateMovieClip(ctx, "holder", NULL);
	printf("=== holder MovieClip ===\n");
	if (holder == NULL) { printf("  NOT FOUND\n"); return; }
	printf("  name: %s\n", holder->name);
	printf("  totalframes: %d\n", holder->totalframes);
	printf("  currentframe: %d\n", holder->currentframe);

	/* 2. holder dynamic_props */
	printf("=== holder.dynamic_props ===\n");
	ASObject* dprops = (ASObject*)holder->dynamic_props;
	dump_object_props(dprops, "props", 20);

	/* 3. _global (childGlobal check) */
	printf("=== _global check ===\n");
	extern ASObject* global_object;
	if (global_object) {
		ActionVar* cg = getProperty(global_object, "childGlobal", 11);
		printf("  _global.childGlobal: %s\n", cg ? "FOUND" : "not found");
		if (cg) {
			char buf[256];
			format_value(cg, buf, sizeof(buf));
			printf("  value: %s\n", buf);
		}
		/* Show a few _global properties to see what's there */
		printf("  _global property count: %u\n", global_object->num_used);
	}

	/* 4. var_array scan */
	printf("=== var_array (string-id variable storage) ===\n");
	extern ActionVar** var_array;
	extern size_t var_array_size;
	printf("  var_array_size: %zu\n", var_array_size);
	int populated = 0;
	for (size_t i = 0; i < var_array_size && i < 200; i++) {
		if (var_array[i] != NULL && var_array[i]->type != ACTION_STACK_VALUE_UNDEFINED) {
			char buf[256];
			format_value(var_array[i], buf, sizeof(buf));
			printf("  [%zu] = %s\n", i, buf);
			populated++;
		}
	}
	printf("  populated slots: %d\n", populated);

	/* 5. Display list */
	printf("=== display list ===\n");
	{
		extern DisplayObject* display_list;
		extern size_t max_depth;
		int found = 0;
		for (size_t d = 0; d <= max_depth && d < 100; d++) {
			if (display_list[d].char_id == 0 && display_list[d].instance_name == NULL) continue;
			printf("  depth %zu: char_id=%zu", d, display_list[d].char_id);
			if (display_list[d].instance_name)
				printf(" name=\"%s\"", display_list[d].instance_name);
			printf(" playing=%d frames=%zu\n",
				display_list[d].sprite_is_playing,
				display_list[d].sprite_current_frame);
			found++;
		}
		if (!found) printf("  (no entries)\n");
	}

	/* 6. Dictionary */
	printf("=== dictionary ===\n");
	{
		extern Character* dictionary;
		int found = 0;
		for (int i = 0; i < 2000 && found < 10; i++) {
			if (dictionary[i].type == CHAR_TYPE_SPRITE) {
				printf("  id %d: sprite\n", i);
				found++;
			}
		}
		if (!found) printf("  (no sprite entries)\n");
	}

	printf("=== C HARNESS: done ===\n");
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	extern void (*g_after_tick_handler)(SWFAppContext*, int);
	g_after_tick_handler = (void (*)(SWFAppContext*, int))after_tick;
}
