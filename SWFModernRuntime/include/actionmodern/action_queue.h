#pragma once

#include <libswf/swf.h>
#include <actionmodern/action.h>

// Action queue priorities (match Ruffle's ActionQueue / context.rs).
// Higher number = higher priority. Drain scans highest-first, FIFO within.
typedef enum {
	AQ_PRIORITY_NORMAL     = 0,
	AQ_PRIORITY_CONSTRUCT  = 1,
	AQ_PRIORITY_INITIALIZE = 2,
	AQ_PRIORITY_COUNT      = 3,
} ActionQueuePriority;

// Generic queue callback: user code provides the dispatch logic.
// When the entry drains, `fn(app_context, user)` is invoked.
typedef void (*ActionQueueFn)(SWFAppContext* app_context, void* user);

// Queue a generic callback.
//   clip       — MovieClip this action is bound to (NULL = unbound). Used by
//                is_unload gating: if clip is removed (avm1_removed or
//                pending_removal) and is_unload==0, the callback is skipped.
//   is_unload  — 1 if this action is an unload event that must fire even when
//                the clip is gone.
//   user       — opaque pointer passed to fn. The queue does not take
//                ownership; caller owns lifetime until drain.
void actionQueueCallback(SWFAppContext* app_context,
                         ActionQueueFn fn,
                         void* user,
                         ActionQueuePriority priority,
                         MovieClip* clip,
                         int is_unload);

// Drain the queue until empty. Pops highest-priority non-empty bucket first,
// FIFO within each priority. New entries queued during dispatch are picked up
// by subsequent iterations (matching Ruffle Player::run_actions).
void actionDrainActionQueue(SWFAppContext* app_context);

// Filtered drain: pops only entries whose `is_unload` matches `is_unload_filter`
// (0 or 1). Non-matching entries stay queued. Use during phased migration to
// preserve call-site-specific semantics (e.g. unload drain point at
// tag.c:actionFirePendingUnloads fires only unload events, leaving onloads
// for the later actionFlushPendingOnLoads drain).
void actionDrainActionQueueFiltered(SWFAppContext* app_context,
                                    int is_unload_filter);

// Discard all queued entries without dispatching (e.g. catch-up resets).
void actionResetActionQueue(SWFAppContext* app_context);

// Non-zero if the queue has any pending entries (for loop-exit checks).
size_t actionActionQueuePending(void);
