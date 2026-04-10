/*
 * Display Bridge — JS-callable functions for reading/writing the display list.
 * Compiled when -DHAS_DISPLAY_BRIDGE is defined.
 */

#ifdef HAS_DISPLAY_BRIDGE

#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <swf.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#ifndef USE_WEBGPU
/* Without WebGPU there is no renderer to sync to — stubs only. */
#endif

#ifdef USE_WEBGPU
#include <renderer.h>
#endif

/* Externs from the runtime */
extern DisplayObject* display_list;
extern size_t max_depth;
extern Character* dictionary;
extern SWFAppContext app_context;

#ifdef USE_WEBGPU
/* RenderContext* is a file-scope global in swf.c */
extern RenderContext* context;
#endif

static char json_buf[8192];

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
const char* getDisplayListJSON(void)
{
    int pos = 0;
    pos += snprintf(json_buf + pos, sizeof(json_buf) - pos,
                    "{\"displayList\":[");

    int first = 1;
    for (size_t d = 1; d <= max_depth; d++) {
        DisplayObject* obj = &display_list[d];
        if (obj->char_id == 0) continue;

        const char* type_name = "unknown";
        Character* ch = &dictionary[obj->char_id];
        switch (ch->type) {
        case CHAR_TYPE_SHAPE:      type_name = "shape"; break;
        case CHAR_TYPE_MORPH_SHAPE: type_name = "morph"; break;
        case CHAR_TYPE_TEXT:        type_name = "text"; break;
        case CHAR_TYPE_SPRITE:     type_name = "sprite"; break;
        case CHAR_TYPE_BUTTON:     type_name = "button"; break;
        }

        /* Read transform matrix (16 floats per slot) */
        float* slot = (float*)app_context.transform_data + obj->transform_id * 16;
        float x = slot[12] / 20.0f;
        float y = slot[13] / 20.0f;
        float xscale = sqrtf(slot[0]*slot[0] + slot[1]*slot[1]) * 100.0f;
        float yscale = sqrtf(slot[4]*slot[4] + slot[5]*slot[5]) * 100.0f;
        float rotation = atan2f(slot[1], slot[0]) * 180.0f / (float)M_PI;

        if (!first) {
            pos += snprintf(json_buf + pos, sizeof(json_buf) - pos, ",");
        }
        first = 0;

        pos += snprintf(json_buf + pos, sizeof(json_buf) - pos,
            "{\"depth\":%zu,\"charId\":%zu,\"charType\":\"%s\","
            "\"transformId\":%u,"
            "\"x\":%.1f,\"y\":%.1f,"
            "\"xscale\":%.1f,\"yscale\":%.1f,"
            "\"rotation\":%.1f}",
            d, obj->char_id, type_name,
            obj->transform_id,
            x, y, xscale, yscale, rotation);

        if (pos >= (int)sizeof(json_buf) - 100) break; /* safety margin */
    }

    pos += snprintf(json_buf + pos, sizeof(json_buf) - pos, "]}");
    return json_buf;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void setObjectTransform(int depth, float x, float y,
                        float xscale, float yscale, float rotation)
{
    if (depth < 1 || (size_t)depth > max_depth) return;

    DisplayObject* obj = &display_list[depth];
    if (obj->char_id == 0) return;

    float* slot = (float*)app_context.transform_data + obj->transform_id * 16;

    float sx = xscale / 100.0f;
    float sy = yscale / 100.0f;
    float rad = rotation * (float)M_PI / 180.0f;
    float c = cosf(rad), s = sinf(rad);

    slot[0]  = sx * c;
    slot[1]  = sx * s;
    slot[4]  = -sy * s;
    slot[5]  = sy * c;
    slot[12] = roundf(x * 20.0f);
    slot[13] = roundf(y * 20.0f);

#ifdef USE_WEBGPU
    if (context) {
        renderer_write_transform(context, obj->transform_id, slot);
    }
#endif
}

#endif /* HAS_DISPLAY_BRIDGE */
