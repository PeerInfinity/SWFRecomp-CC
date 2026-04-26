#ifndef SPRITE_FRAME_SCRIPTS_H
#define SPRITE_FRAME_SCRIPTS_H

#include <stddef.h>

struct SWFAppContext;

typedef void (*SpriteFrameScriptFn)(struct SWFAppContext*);

typedef struct {
	size_t char_id;
	size_t frame_idx;
	SpriteFrameScriptFn fn;
} SpriteFrameScriptEntry;

void tagInitSpriteFrameScripts(SpriteFrameScriptEntry* table, size_t count);

SpriteFrameScriptFn actionGetSpriteFrameScript(size_t char_id, size_t frame_idx);

// ---------------------------------------------------------------------------
// Phase B (GOTO_FIFO_UNIFICATION_INCREMENTAL): deferred sprite-script queue.
//
// ng_gotoFrameCurrentSprite resolves the target frame's script via
// actionGetSpriteFrameScript and pushes onto this bounded queue. Phase B
// is infrastructure only — nothing drains the queue yet. Phase C adds a
// drain hook gated behind g_unify_sprite_drain.
//
// Queue is bounded (MAX_PENDING_SPRITE_SCRIPTS=16). On overflow, the new
// entry is dropped silently. actionFlushPendingSpriteScripts is called
// once per tick to clear stale entries (Phase B no-drain path) and will
// be repurposed in Phase C to dispatch them.
// ---------------------------------------------------------------------------

typedef struct {
	SpriteFrameScriptFn fn;
	size_t char_id;
	size_t frame_idx;
} PendingSpriteScriptEntry;

// Push a deferred sprite-script entry. fn may be NULL (entry is still
// recorded for later sequencing). Returns 1 on success, 0 if dropped
// (queue full).
int actionQueuePendingSpriteScript(size_t char_id, size_t frame_idx,
                                   SpriteFrameScriptFn fn);

// Number of currently-queued entries.
size_t actionPendingSpriteScriptCount(void);

// Read the i-th pending entry without removing it (i < count). Returns
// NULL if i is out of range.
const PendingSpriteScriptEntry* actionPendingSpriteScriptAt(size_t i);

// Drop all queued entries without dispatching. Phase B calls this at
// end of tick to prevent leaks.
void actionResetPendingSpriteScriptQueue(void);

#endif
