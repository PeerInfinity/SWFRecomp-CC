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
