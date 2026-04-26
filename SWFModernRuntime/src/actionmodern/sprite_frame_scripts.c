#include <sprite_frame_scripts.h>

static SpriteFrameScriptEntry* g_table = NULL;
static size_t g_count = 0;

void tagInitSpriteFrameScripts(SpriteFrameScriptEntry* table, size_t count)
{
	g_table = table;
	g_count = count;
}

SpriteFrameScriptFn actionGetSpriteFrameScript(size_t char_id, size_t frame_idx)
{
	if (g_table == NULL) return NULL;
	for (size_t i = 0; i < g_count; i++)
	{
		if (g_table[i].char_id == char_id && g_table[i].frame_idx == frame_idx)
			return g_table[i].fn;
	}
	return NULL;
}

// ---------------------------------------------------------------------------
// Phase B — deferred sprite-script queue
// ---------------------------------------------------------------------------

#define MAX_PENDING_SPRITE_SCRIPTS 16

static PendingSpriteScriptEntry g_pending[MAX_PENDING_SPRITE_SCRIPTS];
static size_t g_pending_count = 0;

int actionQueuePendingSpriteScript(size_t char_id, size_t frame_idx,
                                   SpriteFrameScriptFn fn)
{
	if (g_pending_count >= MAX_PENDING_SPRITE_SCRIPTS) return 0;
	g_pending[g_pending_count].fn = fn;
	g_pending[g_pending_count].char_id = char_id;
	g_pending[g_pending_count].frame_idx = frame_idx;
	g_pending_count++;
	return 1;
}

size_t actionPendingSpriteScriptCount(void) { return g_pending_count; }

const PendingSpriteScriptEntry* actionPendingSpriteScriptAt(size_t i)
{
	if (i >= g_pending_count) return NULL;
	return &g_pending[i];
}

void actionResetPendingSpriteScriptQueue(void) { g_pending_count = 0; }
