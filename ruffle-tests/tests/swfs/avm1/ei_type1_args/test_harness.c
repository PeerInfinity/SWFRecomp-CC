/*
 * Test harness for ei_type1_args.
 *
 * The SWF registers a type-1 (plain DefineFunction) callback
 * `f(a, b)` under the name "extfunc" via ExternalInterface.addCallback.
 * After frame 1 we invoke it through actionEI_callInternalInterface:
 *   1. with two args ("one", "two")  -> must bind a=one, b=two (forward order)
 *   2. with one arg  ("solo")        -> must pad: a=solo, b=undefined
 *      (the type-1 prologue pops EXACTLY param_count values; without padding
 *      it would swallow unrelated eval-stack slots)
 */

#include <stdio.h>
#include <string.h>
#include <swf.h>
#include <action.h>
#include <stackvalue.h>

static ActionVar mock_external_call(SWFAppContext* ctx, const char* name, ActionVar* args, int arg_count)
{
	(void)ctx; (void)name; (void)args; (void)arg_count;
	/* Only present so ExternalInterface.addCallback sees an available host. */
	ActionVar result = {0};
	result.type = ACTION_STACK_VALUE_NULL;
	return result;
}

static ActionVar make_string_av(SWFAppContext* ctx, const char* s)
{
	ActionVar v;
	push_str_id_fn(ctx, s, (u32)strlen(s), 0);
	popVar(ctx, &v);
	return v;
}

static void print_result(SWFAppContext* ctx, ActionVar* result)
{
	(void)ctx;
	if (result->type == ACTION_STACK_VALUE_STRING) {
		char buf[256];
		int len = ei_actionvar_to_utf8(result, buf, sizeof(buf));
		printf("result=%.*s\n", len, buf);
	} else {
		printf("result=(type %d)\n", (int)result->type);
	}
}

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 1) return;

	{
		ActionVar args[2];
		args[0] = make_string_av(ctx, "one");
		args[1] = make_string_av(ctx, "two");
		ActionVar result = actionEI_callInternalInterface(ctx, "extfunc", args, 2);
		print_result(ctx, &result);
	}

	{
		ActionVar args[1];
		args[0] = make_string_av(ctx, "solo");
		ActionVar result = actionEI_callInternalInterface(ctx, "extfunc", args, 1);
		print_result(ctx, &result);
	}
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	g_external_call_handler = mock_external_call;
	g_after_tick_handler = after_tick;
}
