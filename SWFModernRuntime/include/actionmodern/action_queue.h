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

// Action kinds. Used by phased migration to disambiguate drain sites that
// historically had their own storage. Each drain site filters by kind so the
// pre-migration ordering is preserved. ONLOAD is the default kind (Phase 1 +
// Phase 2) and is drained by actionDrainActionQueueFiltered. New kinds
// introduced in Phase 3+ must drain via actionDrainActionQueueByKind.
typedef enum {
	AQ_KIND_ONLOAD      = 0, // Phase 1/2: pending_onloads + pending_unloads
	AQ_KIND_LOAD        = 1, // Phase 3: CLIP_EVENT_LOAD for duplicated clips
	AQ_KIND_ATTACH_INIT = 2, // Phase 3c: attachMovie frame-0 init
	AQ_KIND_ROLL        = 3, // Phase 3: deferred rollOver/rollOut from focus changes
	AQ_KIND_CLIP_INIT   = 4, // Phase 4: CLIP_EVENT_INITIALIZE from tagPlaceObject2
	AQ_KIND_COUNT       = 5,
} ActionQueueKind;

// Generic queue callback: user code provides the dispatch logic.
// When the entry drains, `fn(app_context, user)` is invoked.
typedef void (*ActionQueueFn)(SWFAppContext* app_context, void* user);

// Queue a generic callback with default kind (AQ_KIND_ONLOAD).
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

// Kind-aware enqueue. Callers that push non-ONLOAD kinds must use this so
// the entries drain at their own drain sites instead of leaking into the
// ONLOAD drain.
void actionQueueCallbackEx(SWFAppContext* app_context,
                           ActionQueueFn fn,
                           void* user,
                           ActionQueuePriority priority,
                           MovieClip* clip,
                           int is_unload,
                           ActionQueueKind kind);

// Drain the queue until empty. Pops highest-priority non-empty bucket first,
// FIFO within each priority. New entries queued during dispatch are picked up
// by subsequent iterations (matching Ruffle Player::run_actions).
void actionDrainActionQueue(SWFAppContext* app_context);

// Filtered drain for AQ_KIND_ONLOAD entries by is_unload. Pops only entries
// whose kind == AQ_KIND_ONLOAD AND whose `is_unload` matches `is_unload_filter`
// (0 or 1). Other kinds and non-matching is_unload stay queued. Phase 1/2
// uses this at the unload drain site (is_unload_filter=1) and the onload
// drain site (is_unload_filter=0) to preserve ordering.
void actionDrainActionQueueFiltered(SWFAppContext* app_context,
                                    int is_unload_filter);

// Kind-filtered drain. Pops entries whose kind matches `kind_filter`
// regardless of is_unload. Phase 3+ drain sites (pending_loads, deferred
// rolls, etc.) use this to drain only their own entries.
void actionDrainActionQueueByKind(SWFAppContext* app_context,
                                  ActionQueueKind kind_filter);

// Discard all queued entries without dispatching (e.g. catch-up resets).
void actionResetActionQueue(SWFAppContext* app_context);

// Non-zero if the queue has any pending entries (for loop-exit checks).
size_t actionActionQueuePending(void);

// Find the first queued entry of `kind` whose user payload satisfies `pred`
// (pred returns non-zero). Returns the user pointer, or NULL if no match.
// Used by coalescing enqueue sites that need to update an already-queued
// entry in place (e.g. attachMovie at the same swf_depth supersedes prior).
// The returned pointer remains owned by the queue and is freed by the
// dispatch callback when the entry drains; mutate its fields, do not free.
void* actionQueueFindUserByKind(ActionQueueKind kind,
                                int (*pred)(void* user, void* ctx),
                                void* ctx);
