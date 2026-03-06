/*
 * Test harness for external_interface test.
 *
 * Provides a mock ExternalInterface provider (matching Ruffle's
 * ExternalInterfaceTestProvider) and after-frame-1 callback injection.
 *
 * Mock methods:
 *   "ping"    -> traces "[ExternalInterface] ping", returns "Pong!"
 *   "trace"   -> traces "[ExternalInterface] trace: [args...]", returns "Traced!"
 *   "reentry" -> traces, calls registered "callWith" callback, returns result
 *
 * After frame 1, calls:
 *   call_internal_interface("parrot", ["Hello World!"])
 *   call_internal_interface("callWith", ["trace", {complex object}])
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <swf.h>
#include <action.h>
#include <object.h>
#include <stackvalue.h>

/* ------------------------------------------------------------------ */
/* ExternalValue Debug Formatting                                     */
/* Produces output matching Rust's #[derive(Debug)] for ExternalValue */
/* ------------------------------------------------------------------ */

static int ev_format(SWFAppContext* ctx, ActionVar* v, char* buf, int sz, int depth);

/* Format a double matching Rust's Debug: always includes at least one decimal digit */
static int fmt_f64(double d, char* buf, int sz)
{
	if (d != d) return snprintf(buf, sz, "NaN");
	if (d == 1.0/0.0) return snprintf(buf, sz, "inf");
	if (d == -1.0/0.0) return snprintf(buf, sz, "-inf");

	/* Try to print with default precision and see if it has a decimal point */
	int n = snprintf(buf, sz, "%g", d);
	/* Check if output contains '.' or 'e' (scientific notation) */
	int has_dot = 0;
	for (int i = 0; i < n && buf[i]; i++) {
		if (buf[i] == '.' || buf[i] == 'e' || buf[i] == 'E') { has_dot = 1; break; }
	}
	if (!has_dot && n < sz - 2) {
		buf[n++] = '.';
		buf[n++] = '0';
		buf[n] = '\0';
	}
	return n;
}

/* Sort helper for object property keys (alphabetical, like Rust BTreeMap) */
typedef struct { const char* key; int key_len; ActionVar* value; } KeyVal;
static int kv_cmp(const void* a, const void* b)
{
	return strcmp(((const KeyVal*)a)->key, ((const KeyVal*)b)->key);
}

/* Recursive formatter: converts ActionVar to Rust ExternalValue Debug string */
static int ev_format(SWFAppContext* ctx, ActionVar* v, char* buf, int sz, int depth)
{
	if (depth > 10 || sz < 2) { buf[0] = '\0'; return 0; }
	if (v == NULL) return snprintf(buf, sz, "Undefined");

	int pos = 0;
#define APPEND(...) do { pos += snprintf(buf + pos, sz - pos, __VA_ARGS__); } while(0)

	switch (v->type)
	{
	case ACTION_STACK_VALUE_UNDEFINED:
		APPEND("Undefined");
		break;

	case ACTION_STACK_VALUE_NULL:
		APPEND("Null");
		break;

	case ACTION_STACK_VALUE_BOOLEAN:
		APPEND("Bool(%s)", v->data.numeric_value ? "true" : "false");
		break;

	case ACTION_STACK_VALUE_F32:
	{
		float f;
		memcpy(&f, &v->data.numeric_value, 4);
		APPEND("Number(");
		pos += fmt_f64((double)f, buf + pos, sz - pos);
		APPEND(")");
		break;
	}

	case ACTION_STACK_VALUE_F64:
	{
		double d;
		memcpy(&d, &v->data.numeric_value, 8);
		APPEND("Number(");
		pos += fmt_f64(d, buf + pos, sz - pos);
		APPEND(")");
		break;
	}

	case ACTION_STACK_VALUE_STRING:
	{
		char str_buf[2048];
		int len = ei_actionvar_to_utf8(v, str_buf, sizeof(str_buf));
		APPEND("String(\"%.*s\")", len, str_buf);
		break;
	}

	case ACTION_STACK_VALUE_FUNCTION:
		APPEND("Null");
		break;

	case ACTION_STACK_VALUE_MOVIECLIP:
		APPEND("Null");
		break;

	case ACTION_STACK_VALUE_ARRAY:
	{
		/* Array → List([elem1, elem2, ...]) */
		ASArray* arr = (ASArray*)(uintptr_t)v->data.numeric_value;
		if (arr == NULL) { APPEND("Null"); break; }
		APPEND("List([");
		for (u32 i = 0; i < arr->length; i++)
		{
			if (i > 0) APPEND(", ");
			ActionVar* elem = getArrayElement(arr, i);
			ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
			pos += ev_format(ctx, elem ? elem : &undef, buf + pos, sz - pos, depth + 1);
		}
		APPEND("])");
		break;
	}

	case ACTION_STACK_VALUE_OBJECT:
	{
		ASObject* obj = (ASObject*)(uintptr_t)v->data.numeric_value;
		if (obj == NULL) { APPEND("Null"); break; }

		/* Check if this is an array-like object (has .length as a number) */
		ActionVar* len_prop = getProperty(obj, "length", 6);
		if (len_prop != NULL && (len_prop->type == ACTION_STACK_VALUE_F64 ||
		                         len_prop->type == ACTION_STACK_VALUE_F32))
		{
			/* Treat as array → List */
			double dlen;
			if (len_prop->type == ACTION_STACK_VALUE_F64)
				memcpy(&dlen, &len_prop->data.numeric_value, 8);
			else {
				float flen; memcpy(&flen, &len_prop->data.numeric_value, 4);
				dlen = (double)flen;
			}
			int alen = (int)dlen;
			APPEND("List([");
			for (int i = 0; i < alen; i++)
			{
				if (i > 0) APPEND(", ");
				char idx[16];
				int idx_len = snprintf(idx, sizeof(idx), "%d", i);
				ActionVar* elem = getProperty(obj, idx, idx_len);
				ActionVar undef = {0}; undef.type = ACTION_STACK_VALUE_UNDEFINED;
				pos += ev_format(ctx, elem ? elem : &undef, buf + pos, sz - pos, depth + 1);
			}
			APPEND("])");
			break;
		}

		/* Collect enumerable properties, sort by key */
		KeyVal kvs[128];
		int kv_count = 0;
		for (u32 i = 0; i < obj->num_used && kv_count < 128; i++)
		{
			if (!(obj->properties[i].flags & 0x01)) continue; /* skip non-enumerable */
			char name_buf[256];
			int nlen = obj->properties[i].name_length;
			if (nlen > 255) nlen = 255;
			memcpy(name_buf, obj->properties[i].name, nlen);
			name_buf[nlen] = '\0';
			kvs[kv_count].key = obj->properties[i].name;
			kvs[kv_count].key_len = nlen;
			kvs[kv_count].value = &obj->properties[i].value;
			kv_count++;
		}
		qsort(kvs, kv_count, sizeof(KeyVal), kv_cmp);

		APPEND("Object({");
		for (int i = 0; i < kv_count; i++)
		{
			if (i > 0) APPEND(", ");
			APPEND("\"%.*s\": ", kvs[i].key_len, kvs[i].key);
			pos += ev_format(ctx, kvs[i].value, buf + pos, sz - pos, depth + 1);
		}
		APPEND("})");
		break;
	}

	default:
		APPEND("Undefined");
		break;
	}

#undef APPEND
	return pos;
}

/* Format an args array as a Rust Debug slice: [Value1, Value2, ...] */
static int ev_format_args(SWFAppContext* ctx, ActionVar* args, int count, char* buf, int sz)
{
	int pos = 0;
	pos += snprintf(buf + pos, sz - pos, "[");
	for (int i = 0; i < count; i++)
	{
		if (i > 0) pos += snprintf(buf + pos, sz - pos, ", ");
		pos += ev_format(ctx, &args[i], buf + pos, sz - pos, 0);
	}
	pos += snprintf(buf + pos, sz - pos, "]");
	return pos;
}

/* ------------------------------------------------------------------ */
/* Mock External Call Handler                                         */
/* ------------------------------------------------------------------ */

static ActionVar mock_external_call(SWFAppContext* ctx, const char* name, ActionVar* args, int arg_count)
{
	ActionVar result = {0};

	if (strcmp(name, "ping") == 0)
	{
		printf("[ExternalInterface] ping\n");
		/* Return "Pong!" */
		result.type = ACTION_STACK_VALUE_STRING;
		result.str_size = 0; /* will be set by push_str path */
		/* Use pushVar/popVar to create a proper string ActionVar */
		push_str_id_fn(ctx, "Pong!", 5, 0);
		popVar(ctx, &result);
		return result;
	}

	if (strcmp(name, "trace") == 0)
	{
		char fmt_buf[4096];
		ev_format_args(ctx, args, arg_count, fmt_buf, sizeof(fmt_buf));
		printf("[ExternalInterface] trace: %s\n", fmt_buf);
		/* Return "Traced!" */
		push_str_id_fn(ctx, "Traced!", 7, 0);
		popVar(ctx, &result);
		return result;
	}

	if (strcmp(name, "reentry") == 0)
	{
		printf("[ExternalInterface] starting reentry\n");
		/* Call registered "callWith" callback with ("trace", "successful reentry!") */
		ActionVar cb_args[2];
		push_str_id_fn(ctx, "trace", 5, 0);
		popVar(ctx, &cb_args[0]);
		push_str_id_fn(ctx, "successful reentry!", 19, 0);
		popVar(ctx, &cb_args[1]);
		return actionEI_callInternalInterface(ctx, "callWith", cb_args, 2);
	}

	/* Unknown method → null */
	result.type = ACTION_STACK_VALUE_NULL;
	return result;
}

/* ------------------------------------------------------------------ */
/* Helper: create ActionVar values for the test harness                */
/* ------------------------------------------------------------------ */

static ActionVar make_string_av(SWFAppContext* ctx, const char* s)
{
	ActionVar v;
	push_str_id_fn(ctx, s, (u32)strlen(s), 0);
	popVar(ctx, &v);
	return v;
}

static ActionVar make_f64_av(double d)
{
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_F64;
	memcpy(&v.data.numeric_value, &d, sizeof(double));
	return v;
}

static ActionVar make_bool_av(int b)
{
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_BOOLEAN;
	v.data.numeric_value = b ? 1 : 0;
	return v;
}

static ActionVar make_null_av(void)
{
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_NULL;
	return v;
}

static ActionVar make_object_av(ASObject* obj)
{
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_OBJECT;
	*((u64*)&v.data.numeric_value) = (u64)(uintptr_t)obj;
	return v;
}

/* ------------------------------------------------------------------ */
/* After-Tick Hook: simulate external calls after frame 1              */
/* ------------------------------------------------------------------ */

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 1) return;

	/* 1. Call "parrot" with ["Hello World!"] */
	{
		ActionVar args[1];
		args[0] = make_string_av(ctx, "Hello World!");
		ActionVar result = actionEI_callInternalInterface(ctx, "parrot", args, 1);
		/* Format result as Rust Debug and trace */
		char fmt_buf[1024];
		ev_format(ctx, &result, fmt_buf, sizeof(fmt_buf), 0);
		printf("After calling `parrot` with a string: %s\n", fmt_buf);
	}

	/* 2. Call "callWith" with ["trace", {complex object}] */
	{
		/* Build: { false: false, nested: { list: ["string", 100, false, {}] },
		            null: null, number: -500.1, string: "A string!", true: true } */

		/* Inner: list = ["string", 100, false, {}] */
		ASObject* empty_obj = allocObject(ctx, 4);
		retainObject(empty_obj);
		ei_set_object_proto(ctx, empty_obj);
		/* We need an array-like object with length property */
		ASObject* list_obj = allocObject(ctx, 8);
		retainObject(list_obj);
		{
			ActionVar elem;
			elem = make_string_av(ctx, "string");
			setProperty(ctx, list_obj, "0", 1, &elem);
			elem = make_f64_av(100.0);
			setProperty(ctx, list_obj, "1", 1, &elem);
			elem = make_bool_av(0);
			setProperty(ctx, list_obj, "2", 1, &elem);
			elem = make_object_av(empty_obj);
			setProperty(ctx, list_obj, "3", 1, &elem);
			/* Set length = 4 */
			elem = make_f64_av(4.0);
			setProperty(ctx, list_obj, "length", 6, &elem);
		}

		/* nested = { list: <list_obj> } */
		ASObject* nested_obj = allocObject(ctx, 4);
		retainObject(nested_obj);
		ei_set_object_proto(ctx, nested_obj);
		{
			ActionVar elem = make_object_av(list_obj);
			setProperty(ctx, nested_obj, "list", 4, &elem);
		}

		/* root object */
		ASObject* root_obj = allocObject(ctx, 8);
		retainObject(root_obj);
		ei_set_object_proto(ctx, root_obj);
		{
			ActionVar elem;
			elem = make_f64_av(-500.1);
			setProperty(ctx, root_obj, "number", 6, &elem);
			elem = make_string_av(ctx, "A string!");
			setProperty(ctx, root_obj, "string", 6, &elem);
			elem = make_bool_av(1);
			setProperty(ctx, root_obj, "true", 4, &elem);
			elem = make_bool_av(0);
			setProperty(ctx, root_obj, "false", 5, &elem);
			elem = make_null_av();
			setProperty(ctx, root_obj, "null", 4, &elem);
			elem = make_object_av(nested_obj);
			setProperty(ctx, root_obj, "nested", 6, &elem);
		}

		ActionVar args[2];
		args[0] = make_string_av(ctx, "trace");
		args[1] = make_object_av(root_obj);
		ActionVar result = actionEI_callInternalInterface(ctx, "callWith", args, 2);
		char fmt_buf[1024];
		ev_format(ctx, &result, fmt_buf, sizeof(fmt_buf), 0);
		printf("After calling `callWith` with a complex payload: %s\n", fmt_buf);
	}
}

/* ------------------------------------------------------------------ */
/* Initialization                                                      */
/* ------------------------------------------------------------------ */

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	g_external_call_handler = mock_external_call;
	g_after_tick_handler = after_tick;
}
