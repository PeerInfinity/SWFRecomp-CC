#include <actionmodern/action_queue.h>

#include <stdlib.h>
#include <string.h>

// Single dynamic-growth array. Drain scans for highest-priority non-empty
// bucket. For tens-of-entries scale (typical frame queue is <20 entries)
// this beats three separate ring buffers on simplicity with negligible cost.
// See ACTION_QUEUE_PLAN.md §"Data structure" for the rationale.

typedef struct {
	ActionQueueFn fn;
	void* user;
	MovieClip* clip;
	ActionQueuePriority priority;
	int is_unload;
	ActionQueueKind kind;
} ActionQueueEntry;

static ActionQueueEntry* g_aq = NULL;
static size_t g_aq_count = 0;
static size_t g_aq_cap = 0;

static int aq_grow(size_t needed)
{
	if (needed <= g_aq_cap) return 1;
	size_t new_cap = g_aq_cap ? g_aq_cap * 2 : 32;
	while (new_cap < needed) new_cap *= 2;
	ActionQueueEntry* p = (ActionQueueEntry*)realloc(g_aq, new_cap * sizeof(*p));
	if (!p) return 0;
	g_aq = p;
	g_aq_cap = new_cap;
	return 1;
}

void actionQueueCallbackEx(SWFAppContext* app_context,
                           ActionQueueFn fn,
                           void* user,
                           ActionQueuePriority priority,
                           MovieClip* clip,
                           int is_unload,
                           ActionQueueKind kind)
{
	(void)app_context;
	if (!fn) return;
	if (priority >= AQ_PRIORITY_COUNT) priority = AQ_PRIORITY_NORMAL;
	if (kind >= AQ_KIND_COUNT) kind = AQ_KIND_ONLOAD;
	if (!aq_grow(g_aq_count + 1)) return;
	ActionQueueEntry* e = &g_aq[g_aq_count++];
	e->fn = fn;
	e->user = user;
	e->clip = clip;
	e->priority = priority;
	e->is_unload = is_unload ? 1 : 0;
	e->kind = kind;
}

void actionQueueCallback(SWFAppContext* app_context,
                         ActionQueueFn fn,
                         void* user,
                         ActionQueuePriority priority,
                         MovieClip* clip,
                         int is_unload)
{
	actionQueueCallbackEx(app_context, fn, user, priority, clip,
	                      is_unload, AQ_KIND_ONLOAD);
}

// Drain predicate. kind_filter == -1 means "any kind"; is_unload_filter == -1
// means "any is_unload value".
typedef struct {
	int kind_filter;
	int is_unload_filter;
} DrainFilter;

static int aq_entry_matches(const ActionQueueEntry* e, const DrainFilter* f)
{
	if (f->kind_filter >= 0 && (int)e->kind != f->kind_filter) return 0;
	if (f->is_unload_filter >= 0 && e->is_unload != f->is_unload_filter) return 0;
	return 1;
}

static int aq_pop_index(int* out_index, const DrainFilter* f)
{
	// Ruffle drains highest priority first, FIFO within priority. Scan all
	// entries; track the earliest index at the highest priority seen,
	// restricted to entries matching the filter.
	int best = -1;
	int best_pri = -1;
	for (size_t i = 0; i < g_aq_count; i++) {
		if (!aq_entry_matches(&g_aq[i], f)) continue;
		int pri = (int)g_aq[i].priority;
		if (pri > best_pri) {
			best_pri = pri;
			best = (int)i;
		}
	}
	if (best < 0) return 0;
	*out_index = best;
	return 1;
}

static void aq_drain(SWFAppContext* app_context, const DrainFilter* f)
{
	// Loop until no matching entries remain. Re-entrant queues (dispatch
	// pushes more entries) are handled naturally: each iteration re-scans.
	for (;;) {
		int idx = 0;
		if (!aq_pop_index(&idx, f)) break;
		ActionQueueEntry entry = g_aq[idx];
		// Remove the entry by sliding tail down (preserves FIFO order within
		// each priority bucket).
		if ((size_t)idx + 1 < g_aq_count) {
			memmove(&g_aq[idx], &g_aq[idx + 1],
			        (g_aq_count - (size_t)idx - 1) * sizeof(*g_aq));
		}
		g_aq_count--;

		// is_unload gating: skip if clip was removed before this entry ran,
		// unless this entry is itself an unload event.
		if (!entry.is_unload && entry.clip) {
			if (entry.clip->avm1_removed || entry.clip->pending_removal) {
				continue;
			}
		}
		entry.fn(app_context, entry.user);
	}
}

void actionDrainActionQueue(SWFAppContext* app_context)
{
	DrainFilter f = { .kind_filter = -1, .is_unload_filter = -1 };
	aq_drain(app_context, &f);
}

void actionDrainActionQueueFiltered(SWFAppContext* app_context,
                                    int is_unload_filter)
{
	// Clamp defensively to {0,1}; any other value means "any is_unload".
	if (is_unload_filter != 0 && is_unload_filter != 1) is_unload_filter = -1;
	// Phase 1/2 semantics: only drain ONLOAD-kind entries. Other kinds
	// (LOAD, ATTACH_INIT, ROLL) are owned by their own drain sites.
	DrainFilter f = {
		.kind_filter = (int)AQ_KIND_ONLOAD,
		.is_unload_filter = is_unload_filter,
	};
	aq_drain(app_context, &f);
}

void actionDrainActionQueueByKind(SWFAppContext* app_context,
                                  ActionQueueKind kind_filter)
{
	if (kind_filter >= AQ_KIND_COUNT) return;
	DrainFilter f = {
		.kind_filter = (int)kind_filter,
		.is_unload_filter = -1,
	};
	aq_drain(app_context, &f);
}

void actionResetActionQueue(SWFAppContext* app_context)
{
	(void)app_context;
	g_aq_count = 0;
}

size_t actionActionQueuePending(void)
{
	return g_aq_count;
}

void* actionQueueFindUserByKind(ActionQueueKind kind,
                                int (*pred)(void* user, void* ctx),
                                void* ctx)
{
	if (pred == NULL) return NULL;
	if (kind >= AQ_KIND_COUNT) return NULL;
	for (size_t i = 0; i < g_aq_count; i++) {
		if (g_aq[i].kind != kind) continue;
		if (pred(g_aq[i].user, ctx)) return g_aq[i].user;
	}
	return NULL;
}

// Phase 6: AQ_KIND_SCRIPT dispatcher. The payload is just the function
// pointer boxed so the generic ActionQueueFn signature can carry it.
typedef struct {
	void (*fn)(SWFAppContext*);
} PendingScript;

static void aq_dispatch_script(SWFAppContext* app_context, void* user)
{
	PendingScript* p = (PendingScript*)user;
	if (p && p->fn) p->fn(app_context);
	free(p);
}

void actionQueueScript(SWFAppContext* app_context,
                       void (*fn)(SWFAppContext*))
{
	if (!fn) return;
	PendingScript* p = (PendingScript*)malloc(sizeof(*p));
	if (!p) return;
	p->fn = fn;
	actionQueueCallbackEx(app_context, aq_dispatch_script, p,
	                      AQ_PRIORITY_NORMAL, NULL, 0, AQ_KIND_SCRIPT);
}
