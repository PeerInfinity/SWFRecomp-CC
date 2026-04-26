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

#endif
