// timer.c — setInterval / setTimeout / clearInterval / clearTimeout
// implementation + per-frame tick (processTimers).
//
// Carved out of action.c per
// SWFRecompDocs/plans/split-action-c-math-first.md (fourth subsystem,
// after Math / Date / registerClass). Needed in both graphics and
// non-graphics modes.

#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include <heap.h>

#include <actionmodern/action.h>            // processTimers/hasActiveTimers ABI, actionFlushPendingOnLoads, g_execution_halted
#include <actionmodern/action_internal.h>
#include <actionmodern/actiontimer.h>
// tag.c (s27 w1-timers-robustness, landed w2-timers-land): goto-skipped DoInitAction queue.
extern void tagGotoInitTimerPass(int enter);
extern void tagDrainGotoInitActions(SWFAppContext* app_context, int force);
// s27 w2-timers-land: swf.c / swf_core.c (one per build) — run a root goto a
// callback issued (method form, left for the frame loop) right after it.
extern void ng_runPendingRootGotoFromEvent(SWFAppContext* app_context);

// ==================================================================
// Timer state
// ==================================================================

#define MAX_TIMERS 64

typedef struct {
	int active;                // 0 = empty slot, 1 = active
	int id;                    // sequential ID (1, 2, 3, ...)
	int is_interval;           // 1 = repeating (setInterval), 0 = one-shot (setTimeout)
	// Clock model (s26 w2-timer-semantics): Ruffle core/src/timer.rs.
	// tick_us is the absolute due time on g_timer_cur_us (microseconds);
	// interval_us = max(int32 delay, TIMER_MIN_INTERVAL_MS) * 1000.
	uint64_t tick_us;
	uint64_t interval_us;

	// Callback — either function-form or method-form
	int is_method;             // 0 = function, 1 = method on object
	ActionVar func;            // function reference (function-form)
	ActionVar object;          // object reference (method-form)
	char method_name[256];     // method name string (method-form)

	// Extra arguments passed to callback
	ActionVar extra_args[8];   // inline array of extra args (max 8)
	int extra_arg_count;
} TimerEntry;

// s27 w1-timers-robustness (landed w2-timers-land): growable (was a fixed 64: the 65th
// live setInterval/setTimeout returned undefined and never fired). Starts on
// a static block of MAX_TIMERS; past that it doubles on the heap. A callback
// can create timers while processTimers / fireTimerCallback hold a pointer
// into the table (and pass t->extra_args to the callee), so a replaced block
// is never freed (bounded: the abandoned blocks sum to < the live one), and
// processTimers re-derives its entry by index after each callback.
static TimerEntry g_timers_static[MAX_TIMERS];
static TimerEntry* g_timers = g_timers_static;
static int g_timers_cap = MAX_TIMERS;

static int timerFreeSlot(void)
{
	for (int i = 0; i < g_timers_cap; i++)
		if (!g_timers[i].active) return i;
	int ncap = g_timers_cap * 2;
	TimerEntry* nt = (TimerEntry*) calloc((size_t) ncap, sizeof(TimerEntry));
	if (nt == NULL) return -1;
	memcpy(nt, g_timers, (size_t) g_timers_cap * sizeof(TimerEntry));
	int slot = g_timers_cap;
	g_timers = nt;            // old block deliberately kept (see above)
	g_timers_cap = ncap;
	return slot;
}
static int g_next_timer_id = 1;

// Timer clock (s26 w2-timer-semantics). A port of Ruffle's Timers
// (core/src/timer.rs), which is what the corpus goldens agree with:
// * the clock is an integer microsecond counter advanced once per
//   processTimers call by (u64)(frame_ms * 1000) (Timers::update_timers,
//   TIMER_SCALE = 1000);
// * a timer created at clock C with int32 delay d is due at
//   C + max(d, 10) * 1000 (add_timer, MIN_INTERVAL = 10 ms) — so a 0 /
//   negative / NaN delay is a 10 ms timer, and setInterval(f, 0) REPEATS
//   (it used to fire once and then deactivate);
// * a timer fires while its due time is STRICTLY before the clock, earliest
//   due time first; a repeating timer then moves its due time forward by one
//   interval (catch-up: several fires in one update are possible);
// * NO per-update fire cap (s27 w2b-timers-tail). Ruffle stops after
//   MAX_TICKS = 10 fires per update ("for sanity", timer.rs) and pulls the
//   clock back; Flash Player 32 does not: 70 one-shot setTimeout(fn, 10)
//   created in frame 1 had ALL fired before frame 2 at 10 fps
//   (session27-fanout-reports/w1-local-oracles/w1-timers-robustness/
//   caps_timers, regression/avm1_timer_overflow). Every timer due before the
//   clock fires, and a repeating one catches up (a 10 ms interval fires ~10x
//   per 100 ms frame, as Flash's real-time interval does). The loop is
//   finite without a cap (a timer created in a callback is due after the
//   advanced clock, and each interval is >= 10 ms); TIMER_SANITY_TICKS is a
//   hang guard only, with Ruffle's clock pull-back if it is ever reached;
// * a timer created inside a callback is due >= 10 ms after the CURRENT
//   clock, so it never fires in the update that created it.
// Ties on the due time fire in id (creation) order; Ruffle's BinaryHeap
// order for ties is a heap-layout accident (it alternates 1,2,2,1,... for
// two equal intervals), so creation order is the deliberate choice here.
#define TIMER_MIN_INTERVAL_MS 10
#define TIMER_SANITY_TICKS 1000000
static uint64_t g_timer_cur_us = 0;

static uint64_t timerIntervalUs(double delay_int32)
{
	int32_t d = (int32_t) delay_int32;
	if (d < TIMER_MIN_INTERVAL_MS) d = TIMER_MIN_INTERVAL_MS;
	return (uint64_t) d * 1000u;
}

// ASFunction globals for the 4 top-level timer builtins. Populated by
// initTimerFunctions() on first accessor use.
static ASFunction g_setInterval_func;
static ASFunction g_clearInterval_func;
static ASFunction g_setTimeout_func;
static ASFunction g_clearTimeout_func;
static int g_timer_funcs_init = 0;

// ==================================================================
// Helpers
// ==================================================================

// Coerce an ActionVar to double using the stack (handles valueOf on objects)
static double timerCoerceToNumber(SWFAppContext* app_context, ActionVar* v)
{
	if (v->type == ACTION_STACK_VALUE_UNDEFINED) return NAN;
	if (v->type == ACTION_STACK_VALUE_NULL) return 0.0;
	if (v->type == ACTION_STACK_VALUE_F32) return (double) VAL(float, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_F64) return VAL(double, &v->data.numeric_value);
	if (v->type == ACTION_STACK_VALUE_BOOLEAN) return v->data.numeric_value ? 1.0 : 0.0;
	// For objects (with valueOf), strings, etc. — use the stack-based convertFloat
	pushVar(app_context, v);
	convertFloat(app_context);
	ActionVar result;
	popVar(app_context, &result);
	if (result.type == ACTION_STACK_VALUE_F64) return VAL(double, &result.data.numeric_value);
	if (result.type == ACTION_STACK_VALUE_F32) return (double) VAL(float, &result.data.numeric_value);
	return NAN;
}

// The delay is an int32 millisecond count: Ruffle coerces it with
// coerce_to_i32 (avm1/globals.rs create_timer), i.e. ECMA ToInt32 — NaN/Inf
// -> 0, truncate toward zero, wrap mod 2^32. Keeping the raw double let a
// sub-millisecond delay (gnash misc-swfc gotoFrameFromInterval: 0.0001 ms)
// fire up to processTimers' 10000-iteration safety limit EVERY tick; that
// test's callback appends to a string each fire, so the run grew memory
// quadratically until the OOM killer took it (~17 s). As an int it is 0, i.e.
// a 10 ms timer under the clock model above (s26 w2-robustness-land; the
// zero-delay fire-once arm it originally fell into was replaced by
// s26 w2-timer-semantics).
static double timerDelayToInt32(double d)
{
	if (isnan(d) || isinf(d)) return 0.0;
	d = trunc(d);
	double m = fmod(d, 4294967296.0);
	if (m < 0) m += 4294967296.0;
	return (double) (int32_t) (uint32_t) m;
}

static int timerIsString(ActionVar* v)
{
	return v->type == ACTION_STACK_VALUE_STRING;
}

static int timerIsCallable(ActionVar* v)
{
	return v->type == ACTION_STACK_VALUE_FUNCTION;
}

static int timerIsObject(ActionVar* v)
{
	// Ruffle create_timer: any non-function Object takes the method form —
	// an Array included (s27 w1-timers-robustness, landed w2-timers-land).
	return v->type == ACTION_STACK_VALUE_OBJECT ||
	       v->type == ACTION_STACK_VALUE_MOVIECLIP ||
	       v->type == ACTION_STACK_VALUE_ARRAY;
}

// ==================================================================
// setInterval / setTimeout registration
// ==================================================================

// Called from actionCallFunction dispatch. args[] are the function arguments.
// is_interval: 1 = setInterval (repeating), 0 = setTimeout (one-shot)
void actionTimerSetInterval(SWFAppContext* app_context, ActionVar* args, u32 num_args, int is_interval)
{
	// Validation: need at least 2 args
	if (num_args < 2)
	{
		if (args != NULL) FREE(args);
		pushUndefined(app_context);
		return;
	}

	// Detect calling convention:
	// Function-form: setInterval(func, delay, ...extraArgs)
	//   - args[0] is a function
	// Method-form: setInterval(obj, methodName, delay, ...extraArgs)
	//   - args[0] is an object/movieclip, args[1] is a string (or coercible to string)
	//   - Flash uses method-form when: num_args >= 3, args[0] is obj/mc, and args[0] is NOT callable
	int is_method = 0;

	if (num_args >= 3 && timerIsObject(&args[0]) && !timerIsCallable(&args[0]))
	{
		is_method = 1;
	}

	if (is_method)
	{
		// Method-form: setInterval(obj, methodName, delay, ...extraArgs)
		// Need at least 3 args
		if (num_args < 3)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		// Get method name — coerce args[1] to string via the stack
		char method_buf[256];
		method_buf[0] = '\0';
		if (timerIsString(&args[1]))
		{
			const uint16_t* u16_str = varGetU16Ptr(&args[1]);
			if (u16_str != NULL && args[1].str_size > 0)
			{
				int len = u16_to_utf8(u16_str, args[1].str_size, method_buf, sizeof(method_buf) - 1);
				method_buf[len] = '\0';
			}
		}
		else if (args[1].type != ACTION_STACK_VALUE_NULL && args[1].type != ACTION_STACK_VALUE_UNDEFINED)
		{
			// Coerce to string (handles objects with toString)
			pushVar(app_context, &args[1]);
			char _ts_buf[17];
			convertString(app_context, _ts_buf);
			const uint16_t* u16_str = (const uint16_t*)STACK_TOP_VALUE;
			u32 u16_len = STACK_TOP_N;
			if (u16_str != NULL && u16_len > 0)
			{
				int len = u16_to_utf8(u16_str, u16_len, method_buf, sizeof(method_buf) - 1);
				method_buf[len] = '\0';
			}
			POP();
		}
		else
		{
			// null or undefined method name — store "null" / "undefined"
			if (args[1].type == ACTION_STACK_VALUE_NULL)
				strcpy(method_buf, "null");
			else
				strcpy(method_buf, "undefined");
		}

		// Coerce delay (args[2]):
		// undefined delay → reject (return undefined), matching Flash behavior
		// Non-numeric string/object delays → coerce to 0 (Shumway/Ruffle behavior)
		if (args[2].type == ACTION_STACK_VALUE_UNDEFINED) {
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		double delay = timerDelayToInt32(timerCoerceToNumber(app_context, &args[2]));

		// Find empty slot
		int slot = timerFreeSlot();
		if (slot == -1)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		// Register timer
		TimerEntry* t = &g_timers[slot];
		memset(t, 0, sizeof(TimerEntry));
		t->active = 1;
		t->id = g_next_timer_id++;
		t->is_interval = is_interval;
		t->interval_us = timerIntervalUs(delay);
		t->tick_us = g_timer_cur_us + t->interval_us;
		t->is_method = 1;
		t->object = args[0]; // shallow copy (object pointer)
		strncpy(t->method_name, method_buf, sizeof(t->method_name) - 1);
		t->method_name[sizeof(t->method_name) - 1] = '\0';

		// Copy extra args (args[3], args[4], ...)
		t->extra_arg_count = 0;
		for (u32 i = 3; i < num_args && t->extra_arg_count < 8; i++)
		{
			t->extra_args[t->extra_arg_count++] = args[i];
		}

		// Push timer ID
		double id_val = (double)t->id;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &id_val));
		if (args != NULL) FREE(args);
	}
	else
	{
		// Function-form: setInterval(func, delay, ...extraArgs)
		// Validate: args[0] must be a callable function
		if (!timerIsCallable(&args[0]))
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		// Coerce delay (args[1]):
		// undefined delay → reject (return undefined), matching Flash behavior
		// Non-numeric string/object delays → coerce to 0 (Shumway/Ruffle behavior)
		if (args[1].type == ACTION_STACK_VALUE_UNDEFINED) {
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}
		double delay = timerDelayToInt32(timerCoerceToNumber(app_context, &args[1]));

		// Find empty slot
		int slot = timerFreeSlot();
		if (slot == -1)
		{
			if (args != NULL) FREE(args);
			pushUndefined(app_context);
			return;
		}

		// Register timer
		TimerEntry* t = &g_timers[slot];
		memset(t, 0, sizeof(TimerEntry));
		t->active = 1;
		t->id = g_next_timer_id++;
		t->is_interval = is_interval;
		t->interval_us = timerIntervalUs(delay);
		t->tick_us = g_timer_cur_us + t->interval_us;
		t->is_method = 0;
		t->func = args[0]; // shallow copy (function pointer)

		// Copy extra args (args[2], args[3], ...)
		t->extra_arg_count = 0;
		for (u32 i = 2; i < num_args && t->extra_arg_count < 8; i++)
		{
			t->extra_args[t->extra_arg_count++] = args[i];
		}

		// Push timer ID
		double id_val = (double)t->id;
		PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &id_val));
		if (args != NULL) FREE(args);
	}
}

// clearInterval / clearTimeout
void actionTimerClearInterval(SWFAppContext* app_context, ActionVar* args, u32 num_args)
{
	if (num_args == 0)
	{
		pushUndefined(app_context);
		return;
	}

	// Get timer ID from first arg
	// Ruffle clear_interval: coerce_to_i32 (ECMA ToInt32). `(int)double`
	// was UB for NaN / out-of-range ids (x86: INT_MIN), so
	// clearInterval(id + 4294967296) did not clear timer `id`
	// (s27 w1-timers-robustness, landed w2-timers-land).
	double id_d = timerDelayToInt32(timerCoerceToNumber(app_context, &args[0]));
	int id = (int)id_d;

	// Find and deactivate the timer
	for (int i = 0; i < g_timers_cap; i++)
	{
		if (g_timers[i].active && g_timers[i].id == id)
		{
			g_timers[i].active = 0;
			break;
		}
	}

	pushUndefined(app_context);
}

// ==================================================================
// Callback dispatch
// ==================================================================

// Fire a timer callback (function-form or method-form)
static void fireTimerCallback(SWFAppContext* app_context, TimerEntry* t)
{
	if (g_execution_halted) return;

	if (t->is_method)
	{
		// Method-form: look up method on object at fire time, call with this=obj
		ASObject* obj = NULL;
		MovieClip* mc = NULL;

		if (t->object.type == ACTION_STACK_VALUE_OBJECT)
			obj = (ASObject*)(uintptr_t)t->object.data.numeric_value;
		else if (t->object.type == ACTION_STACK_VALUE_MOVIECLIP)
			mc = (MovieClip*)(uintptr_t)t->object.data.numeric_value;

		// Look up the method
		ASFunction* method_func = NULL;
		if (obj != NULL)
		{
			ActionVar* mv = getPropertyWithPrototype(obj, t->method_name, strlen(t->method_name));
			if (mv != NULL && mv->type == ACTION_STACK_VALUE_FUNCTION)
				method_func = (ASFunction*)(uintptr_t)mv->data.numeric_value;
		}
		else if (mc != NULL)
		{
			// Look up on MC's dynamic_props
			ASObject* dprops = (ASObject*)mc->dynamic_props;
			if (dprops != NULL)
			{
				ActionVar* mv = getPropertyWithPrototype(dprops, t->method_name, strlen(t->method_name));
				if (mv != NULL && mv->type == ACTION_STACK_VALUE_FUNCTION)
					method_func = (ASFunction*)(uintptr_t)mv->data.numeric_value;
			}
		}

		if (method_func == NULL)
		{
			// s27 w1-timers-robustness (landed w2-timers-land): Ruffle's Avm1Method arm is
			// `this.call_method(name, params)` — a full member lookup, so a
			// native method (setInterval(mc, "nextFrame", ms), `play`, ...)
			// and a non-ASObject receiver (an Array) are called too. The
			// dynamic-property lookup above only sees user-assigned
			// functions; fall back to the CallMethod opcode path for the
			// rest (AVM1 stack layout: args last..first, count, obj, name).
			if (t->object.type != ACTION_STACK_VALUE_OBJECT &&
			    t->object.type != ACTION_STACK_VALUE_MOVIECLIP &&
			    t->object.type != ACTION_STACK_VALUE_ARRAY) return;
			if (t->object.data.numeric_value == 0) return;
			for (int i = t->extra_arg_count - 1; i >= 0; i--)
				pushVar(app_context, &t->extra_args[i]);
			ActionVar n_var = {0};
			n_var.type = ACTION_STACK_VALUE_F64;
			VAL(double, &n_var.data.numeric_value) = (double) t->extra_arg_count;
			pushVar(app_context, &n_var);
			pushVar(app_context, &t->object);
			PUSH_STR(t->method_name, strlen(t->method_name));
			char _tm_sb[17];
			g_call_depth++;
			actionCallMethod(app_context, _tm_sb);
			g_call_depth--;
			ActionVar _tm_r;
			popVar(app_context, &_tm_r);
			return;
		}

		// INV_VERSION_SWITCH: run the callback under its defining movie's SWF
		// version (and the matching version-group _global) — timers fire from
		// the host movie's frame loop, so a callback defined in a loaded child
		// SWF of a different version would otherwise get the host's semantics.
		// Safe inside the core for this form: neither arm ever switches base
		// clip, so there is no gate to compute against the switched version.
		//
		// this_var = &t->object: the core derives the same obj/mc ABI receiver
		// the arm used to compute by hand. INV_EVENT_THIS_MC is "set when the
		// receiver is an MC" (the old `if (mc != NULL)`); the type-2 arm now
		// sets it too, with INV_MC_THIS_NULL_PTR (see below). No local scope
		// frame on type-1 (type-2 gets one, below), no this-stack, no
		// exec-func swap (preserved by leaving those flags clear); depth
		// bracket stays out here because the path never had the g_max_call_depth halt check. The core additionally
		// clamps/pads type-1 args to param_count (the TYPE1_ARG_ORDER fix,
		// regression/timer_type1_args), bounds + copies scope_mc on the
		// captured-scope push (was stale), and NULL-checks the function
		// pointers (MovieClip.prototype stubs are type-1 with NULL pointers).
		u32 _tm_flags = (method_func->function_type == 2)
			? (INV_CAPTURED_SCOPE | INV_FORCE_CAPTURED_WITH | INV_VERSION_SWITCH)
			: (INV_EVENT_THIS_MC | INV_VERSION_SWITCH);
		// Type-2 method on a MOVIECLIP receiver (s25 w2-netstream-flv-screen).
		// A DefineFunction2 body's preload-this tags a non-NULL ABI this_obj as
		// ACTION_STACK_VALUE_OBJECT, so passing the raw MovieClip* made every
		// `this.x` read go through the ASObject path and come back undefined
		// (setInterval(this, "doAutoResize", ...) on an AS2 class instance
		// registered onto an attached clip: mx.video.VideoPlayer never saw its
		// own _autoResizeIntervalID, never dispatched "ready", and FLVPlayback
		// kept the player _visible=false — avm1/netstream_play_flv_screen
		// rendered blank). Use the same MC receiver convention as CallMethod
		// (action.c, _sc_flags): NULL ABI this + g_event_this_mc.
		if (method_func->function_type == 2 && mc != NULL)
			_tm_flags |= INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR;
		// A type-2 body that neither preloads nor suppresses `this` /
		// `arguments` reads them by name off its activation frame, which this
		// arm never built (GetVariable("this") / `arguments` were unbound in
		// a setInterval(obj, "m") callee). Same activation as the onLoad
		// dispatcher's type-2 arm: local frame + INV_ACT_THIS/ARGUMENTS
		// (both gated inside the core on the callee's own preload/suppress bits).
		u8 _tm_act = 0;
		if (method_func->function_type == 2)
		{
			_tm_flags |= INV_LOCAL_SCOPE;
			_tm_act = INV_ACT_THIS | INV_ACT_ARGUMENTS;
		}
		InvokeOpts _tm_opts = { .flags = _tm_flags, .act_flags = _tm_act };
		g_call_depth++;
		actionInvokeFunctionValue(app_context, method_func, &t->object,
			t->extra_arg_count > 0 ? t->extra_args : NULL,
			t->extra_arg_count, &_tm_opts);
		g_call_depth--;
		// Return value discarded.
	}
	else
	{
		// Function-form: call the function directly
		ASFunction* func = (ASFunction*)(uintptr_t)t->func.data.numeric_value;
		if (func == NULL) return;

		// Base clip stays in the arm (never pair INV_BASE_CLIP with
		// INV_VERSION_SWITCH). CALLER-gated since normalization pass (b)
		// item 3 (was the callee-version accident of statement order):
		// Ruffle's Avm1Function::call decides is_closure from the CALLER's
		// activation version; a v5 ambient at fire time is pre-closure and
		// keeps the caller's context (the core's INV_VERSION_SWITCH v5 branch
		// handles the version side the same way).
		MovieClip* old_context = g_current_context;
		if (g_swf_version >= 6 && func->base_clip != NULL)
			g_current_context = actionClosureBaseClip(app_context, func->base_clip, NULL);

		// this_var = NULL: the core passes NULL as the ABI receiver, as both
		// arms always did. Type-1 keeps no captured scopes (a type-1 closure
		// loses its defining chain here — a normalization candidate, not a
		// migration change). Same silent fixes as the method-form above
		// (clamp/pad, bounded scope push, scope_mc, NULL-checked dispatch).
		u32 _tf_flags = (func->function_type == 2)
			? (INV_CAPTURED_SCOPE | INV_FORCE_CAPTURED_WITH | INV_VERSION_SWITCH)
			: INV_VERSION_SWITCH;
		// s26 w1-avm1-dispatch-scope PROTOTYPE (item 2, s25 L3): a fresh local
		// activation for both types (Ruffle timer.rs Avm1Function -> func.call(
		// .., this = Undefined, params) -> Avm1Function::exec new_local_scope):
		// `var` stays local (it leaked onto the timeline), `arguments` and
		// `this` (= undefined) are bound by name.
		_tf_flags |= INV_LOCAL_SCOPE;
		if (func->function_type == 1) _tf_flags |= INV_BIND_THIS;
		u8 _tf_act = INV_ACT_THIS | INV_ACT_ARGUMENTS;
		ActionVar _tf_this = {0};
		_tf_this.type = ACTION_STACK_VALUE_UNDEFINED;
		InvokeOpts _tf_opts = { .flags = _tf_flags, .act_flags = _tf_act };
		g_call_depth++;
		actionInvokeFunctionValue(app_context, func, &_tf_this,
			t->extra_arg_count > 0 ? t->extra_args : NULL,
			t->extra_arg_count, &_tf_opts);
		g_call_depth--;

		g_current_context = old_context;
		// Return value discarded.
	}
}

// ==================================================================
// Frame-loop hooks (declared in <actionmodern/action.h>)
// ==================================================================

// Process all active timers. Called from swf_core.c after each frame tick.
// frame_duration_ms = 1000.0 / fps
void processTimers(SWFAppContext* app_context, double frame_duration_ms)
{
	// Ruffle Timers::update_timers: advance the clock first (also when no
	// timer is active, so a later timer is scheduled against the real time).
	g_timer_cur_us += (uint64_t) (frame_duration_ms * 1000.0);

	// Method-form timers whose target clip was removed can never fire
	// again (Ruffle cancels them when they come due, below); drop them now
	// as before so they do not keep hasActiveTimers() — the headless exit
	// condition — true until their due time.
	for (int i = 0; i < g_timers_cap; i++)
	{
		if (!g_timers[i].active || !g_timers[i].is_method ||
		    g_timers[i].object.type != ACTION_STACK_VALUE_MOVIECLIP) continue;
		MovieClip* tmc = (MovieClip*)(uintptr_t)g_timers[i].object.data.numeric_value;
		if (tmc == NULL || tmc->depth == INT_MIN) g_timers[i].active = 0;
	}

	int tick_count = 0;
	// s27 w1-timers-robustness (landed w2-timers-land): init actions queued by a goto in a
	// callback run after the batch of timers due at the same instant
	// (tagDrainGotoInitActions; gnash gotoFrameFromInterval `x0xx1x234`).
	tagGotoInitTimerPass(1);
	int have_batch = 0;
	uint64_t batch_tick = 0;
	for (;;)
	{
		// Earliest due active timer (ties: lowest id = creation order).
		int best = -1;
		for (int i = 0; i < g_timers_cap; i++)
		{
			if (!g_timers[i].active) continue;
			if (best < 0 || g_timers[i].tick_us < g_timers[best].tick_us ||
			    (g_timers[i].tick_us == g_timers[best].tick_us && g_timers[i].id < g_timers[best].id))
				best = i;
		}
		if (best < 0 || !(g_timers[best].tick_us < g_timer_cur_us)) break;

		TimerEntry* t = &g_timers[best];
		if (have_batch && t->tick_us != batch_tick)
		{
			tagDrainGotoInitActions(app_context, 1);
			ng_runPendingRootGotoFromEvent(app_context);
			have_batch = 0;
			continue; // the init actions / target frame may have cleared or created timers
		}
		if (++tick_count > TIMER_SANITY_TICKS)
		{
			g_timer_cur_us = t->tick_us - 100;
			break;
		}

		// A method-form timer whose target clip was removed is cancelled at
		// fire time without a call (Ruffle: avm1_removed() -> cancel_timer).
		int cancel = 0;
		if (t->is_method && t->object.type == ACTION_STACK_VALUE_MOVIECLIP)
		{
			MovieClip* tmc = (MovieClip*)(uintptr_t)t->object.data.numeric_value;
			if (tmc == NULL || tmc->depth == INT_MIN) cancel = 1;
		}

		int expected_id = t->id;
		if (!have_batch) { have_batch = 1; batch_tick = t->tick_us; }
		if (!cancel)
		{
			fireTimerCallback(app_context, t);

			// Ruffle runs Player::run_actions after every callback.
			// Fire deferred onChanged from replaceSel (if any)
			actionFlushPendingOnChanged(app_context);
			// Flush pending onLoads queued by attachMovie during this timer callback
			actionFlushPendingOnLoads(app_context);
		}

		// The callback may have cleared this timer (or cleared it and a new
		// one reused the slot): only reschedule the entry it fired. Re-derive
		// the pointer: the callback may have grown (moved) the table.
		t = &g_timers[best];
		if (t->active && t->id == expected_id)
		{
			if (!t->is_interval || cancel)
				t->active = 0;
			else
				t->tick_us += t->interval_us;
		}
		if (g_execution_halted) break;
	}
	tagGotoInitTimerPass(0);
	tagDrainGotoInitActions(app_context, 1);
	ng_runPendingRootGotoFromEvent(app_context);
}

// Check if any timers are active
int hasActiveTimers(void)
{
	for (int i = 0; i < g_timers_cap; i++)
	{
		if (g_timers[i].active) return 1;
	}
	return 0;
}

// ==================================================================
// Top-level builtin wrappers + ASFunction globals
// ==================================================================

// Builtin setTimeout/setInterval that work when aliased (var f = setTimeout; f(...))
// Must copy args since actionTimerSetInterval frees them, but caller also frees the originals.
static ActionVar builtin_setTimeout_impl(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	ActionVar* args_copy = NULL;
	if (arg_count > 0) {
		args_copy = (ActionVar*)HALLOC(sizeof(ActionVar) * arg_count);
		for (u32 i = 0; i < arg_count; i++) args_copy[i] = args[i];
	}
	actionTimerSetInterval(app_context, args_copy, arg_count, 0);
	ActionVar r; popVar(app_context, &r); return r;
}

static ActionVar builtin_setInterval_impl(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	ActionVar* args_copy = NULL;
	if (arg_count > 0) {
		args_copy = (ActionVar*)HALLOC(sizeof(ActionVar) * arg_count);
		for (u32 i = 0; i < arg_count; i++) args_copy[i] = args[i];
	}
	actionTimerSetInterval(app_context, args_copy, arg_count, 1);
	ActionVar r; popVar(app_context, &r); return r;
}

static ActionVar builtin_clearInterval_impl(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
	(void)registers; (void)this_obj;
	actionTimerClearInterval(app_context, args, arg_count);
	ActionVar r = {0}; r.type = ACTION_STACK_VALUE_UNDEFINED; return r;
}

void initTimerFunctions(void)
{
	if (g_timer_funcs_init) return;
	struct { ASFunction* func; const char* name; Function2Ptr impl; } entries[] = {
		{&g_setInterval_func,   "setInterval",   (Function2Ptr)builtin_setInterval_impl},
		{&g_clearInterval_func, "clearInterval", (Function2Ptr)builtin_clearInterval_impl},
		{&g_setTimeout_func,    "setTimeout",    (Function2Ptr)builtin_setTimeout_impl},
		// clearTimeout shares the clearInterval impl — same semantics
		{&g_clearTimeout_func,  "clearTimeout",  (Function2Ptr)builtin_clearInterval_impl},
	};
	for (int i = 0; i < (int)(sizeof(entries)/sizeof(entries[0])); i++) {
		memset(entries[i].func, 0, sizeof(ASFunction));
		strncpy(entries[i].func->name, entries[i].name, 255);
		entries[i].func->function_type = 2;
		entries[i].func->advanced_func = entries[i].impl;
	}
	g_timer_funcs_init = 1;
}

ASFunction* actionTimerGetSetInterval(void)   { initTimerFunctions(); return &g_setInterval_func; }
ASFunction* actionTimerGetClearInterval(void) { initTimerFunctions(); return &g_clearInterval_func; }
ASFunction* actionTimerGetSetTimeout(void)    { initTimerFunctions(); return &g_setTimeout_func; }
ASFunction* actionTimerGetClearTimeout(void)  { initTimerFunctions(); return &g_clearTimeout_func; }

// Stage 3 collector root marker: active timer entries hold borrowed
// func/object/extra_args references invisible to the object graph.
// The 4 timer builtin ASFunctions' own_props are marked too (they are
// static but not necessarily in function_registry).
void timerGcMarkRoots(void)
{
	for (int i = 0; i < g_timers_cap; i++) {
		if (!g_timers[i].active) continue;
		swfGcMarkVar(&g_timers[i].func);
		swfGcMarkVar(&g_timers[i].object);
		for (int j = 0; j < g_timers[i].extra_arg_count && j < 8; j++)
			swfGcMarkVar(&g_timers[i].extra_args[j]);
	}
	if (g_timer_funcs_init) {
		swfGcMarkFunctionPtr(&g_setInterval_func);
		swfGcMarkFunctionPtr(&g_clearInterval_func);
		swfGcMarkFunctionPtr(&g_setTimeout_func);
		swfGcMarkFunctionPtr(&g_clearTimeout_func);
	}
}

// Scrub-on-free (collector on only): clear timer-held borrowed refs to the
// freed object. A timer whose callback object died was a latent UAF at fire
// time before; firing with UNDEFINED is a deterministic no-op instead.
void timerGcScrubStashes(const void* p)
{
	for (int i = 0; i < g_timers_cap; i++) {
		if (!g_timers[i].active) continue;
		ActionVar* vars[10];
		int n = 0;
		vars[n++] = &g_timers[i].func;
		vars[n++] = &g_timers[i].object;
		for (int j = 0; j < g_timers[i].extra_arg_count && j < 8; j++)
			vars[n++] = &g_timers[i].extra_args[j];
		for (int k = 0; k < n; k++) {
			ActionVar* v = vars[k];
			if ((v->type == ACTION_STACK_VALUE_OBJECT || v->type == ACTION_STACK_VALUE_ARRAY) &&
			    (void*)(uintptr_t)v->data.numeric_value == p)
			{
				v->type = ACTION_STACK_VALUE_UNDEFINED;
				v->data.numeric_value = 0;
				v->str_size = 0;
			}
		}
	}
}
