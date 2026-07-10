/*
 * Test harness for ei_closure_scope_order (behavior lock, not a bug repro).
 *
 * The SWF registers five type-1 callbacks via ExternalInterface.addCallback:
 *   "shadow"   — defined inside with(w); its param `a` shares a name with w.a
 *   "writer"   — assigns the captured outer local `ov`
 *   "reader"   — traces the captured outer local `ov`
 *   "tagged"   — registered with thisObj = {tag:"T"}; traces this.tag
 *   "untagged" — registered with thisObj = null; traces typeof this
 *
 * We invoke them through actionEI_callInternalInterface and lock EI's current
 * dispatch quirks: local-scope-under-captured (shadow reads w.a, not the arg),
 * forced is_with on captured scopes (writer's assignment does not reach the
 * captured frame, so reader still sees the original), and the LIVE type-1
 * `this` bind (tagged reads T; untagged sees undefined).
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

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 1) return;

	{
		ActionVar args[1];
		args[0] = make_string_av(ctx, "ARG");
		actionEI_callInternalInterface(ctx, "shadow", args, 1);
	}
	actionEI_callInternalInterface(ctx, "writer", NULL, 0);
	actionEI_callInternalInterface(ctx, "reader", NULL, 0);
	actionEI_callInternalInterface(ctx, "tagged", NULL, 0);
	actionEI_callInternalInterface(ctx, "untagged", NULL, 0);
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	g_external_call_handler = mock_external_call;
	g_after_tick_handler = after_tick;
}
