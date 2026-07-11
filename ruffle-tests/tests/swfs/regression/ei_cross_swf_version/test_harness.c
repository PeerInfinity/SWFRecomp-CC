/*
 * Test harness for ei_cross_swf_version.
 *
 * The SWF (v8) registers a v8-DEFINED callback `f()` under "extfunc" via
 * ExternalInterface.addCallback. After frame 1 we simulate a host-driven
 * call arriving while a DIFFERENT (older) movie's version is ambient: set
 * g_swf_version = 6 (what a v6 sibling movie's bytecode would have
 * installed), invoke through actionEI_callInternalInterface, restore.
 *
 * Flash/Ruffle run a function at its DEFINING movie's SWF version, so the
 * callback must trace "cb:[undefined]" (v8 coercion) — without a version
 * switch on the EI dispatch path it runs at the injected ambient v6 and
 * traces "cb:[]". (Polarity inverted vs the other *_cross_swf_version
 * repros because ExternalInterface itself is version-hidden below SWF8.)
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

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 1) return;

	int saved_ver = g_swf_version;
	g_swf_version = 6;  /* ambient version of a v6 sibling movie */
	(void) actionEI_callInternalInterface(ctx, "extfunc", NULL, 0);
	g_swf_version = saved_ver;
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	g_external_call_handler = mock_external_call;
	g_after_tick_handler = after_tick;
}
