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

void actionQueueCallback(SWFAppContext* app_context,
                         ActionQueueFn fn,
                         void* user,
                         ActionQueuePriority priority,
                         MovieClip* clip,
                         int is_unload)
{
	(void)app_context;
	if (!fn) return;
	if (priority >= AQ_PRIORITY_COUNT) priority = AQ_PRIORITY_NORMAL;
	if (!aq_grow(g_aq_count + 1)) return;
	ActionQueueEntry* e = &g_aq[g_aq_count++];
	e->fn = fn;
	e->user = user;
	e->clip = clip;
	e->priority = priority;
	e->is_unload = is_unload ? 1 : 0;
}

void actionQueueCallbackEx(SWFAppContext* app_context,
                           ActionQueueFn fn,
                           void* user,
                           ActionQueuePriority priority,
                           MovieClip* clip,
                           int is_unload,
                           ActionQueueKind kind)
{
	(void)kind;
	actionQueueCallback(app_context, fn, user, priority, clip, is_unload);
}

static int aq_pop_index(int* out_index, int is_unload_filter)
{
	// Ruffle drains highest priority first, FIFO within priority. Scan all
	// entries; track the earliest index at the highest priority seen.
	// When is_unload_filter >= 0, only entries with matching is_unload are
	// considered.
	int best = -1;
	int best_pri = -1;
	for (size_t i = 0; i < g_aq_count; i++) {
		if (is_unload_filter >= 0 && g_aq[i].is_unload != is_unload_filter)
			continue;
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

static void aq_drain(SWFAppContext* app_context, int is_unload_filter)
{
	// Loop until no matching entries remain. Re-entrant queues (dispatch
	// pushes more entries) are handled naturally: each iteration re-scans.
	for (;;) {
		int idx = 0;
		if (!aq_pop_index(&idx, is_unload_filter)) break;
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
	aq_drain(app_context, -1);
}

void actionDrainActionQueueFiltered(SWFAppContext* app_context,
                                    int is_unload_filter)
{
	// Clamp defensively to the documented {0,1} domain. Pass -1 for "drain all".
	if (is_unload_filter != 0 && is_unload_filter != 1) is_unload_filter = -1;
	aq_drain(app_context, is_unload_filter);
}

void actionDrainActionQueueByKind(SWFAppContext* app_context,
                                  ActionQueueKind kind_filter)
{
	(void)app_context;
	(void)kind_filter;
	// Phase 3b: no callers push non-default kinds yet.
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
