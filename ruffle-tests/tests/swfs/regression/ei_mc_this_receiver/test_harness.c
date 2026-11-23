/*
 * Test harness for ei_mc_this_receiver (s26 w2-avm1-text-resolve).
 *
 * The SWF registers two callbacks with a MovieClip receiver via
 * ExternalInterface.addCallback(name, m, fn): "t2" (DefineFunction2,
 * preload this) and "t1" (DefineFunction). After frame 1 we invoke both
 * through actionEI_callInternalInterface; each traces this.v / this._name /
 * typeof this, which must be the clip's (Ruffle external.rs Callback::Avm1).
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
	ActionVar r2 = actionEI_callInternalInterface(ctx, "t2", NULL, 0);
	print_result(ctx, &r2);
	ActionVar r1 = actionEI_callInternalInterface(ctx, "t1", NULL, 0);
	print_result(ctx, &r1);
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	g_external_call_handler = mock_external_call;
	g_after_tick_handler = after_tick;
}
