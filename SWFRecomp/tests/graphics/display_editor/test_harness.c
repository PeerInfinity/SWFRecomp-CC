/*
 * Test harness for display_editor demo.
 *
 * After tick 1, dumps the display list showing each visible object's
 * position, scale, rotation, and color transform data.
 */

#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <swf.h>
#include <action.h>

static void after_tick(SWFAppContext* ctx, int tick)
{
	if (tick != 1) return;

	extern DisplayObject* display_list;
	extern size_t max_depth;
	extern Character* dictionary;

	printf("=== display list after tick 1 ===\n");

	for (size_t d = 1; d <= max_depth; d++) {
		DisplayObject* obj = &display_list[d];
		if (obj->char_id == 0) continue;

		const char* type_name = "unknown";
		Character* ch = &dictionary[obj->char_id];
		switch (ch->type) {
		case CHAR_TYPE_SHAPE: type_name = "shape"; break;
		case CHAR_TYPE_MORPH_SHAPE: type_name = "morph"; break;
		case CHAR_TYPE_TEXT: type_name = "text"; break;
		case CHAR_TYPE_SPRITE: type_name = "sprite"; break;
		case CHAR_TYPE_BUTTON: type_name = "button"; break;
		}

		/* Read transform matrix */
		float* xform = (float*)ctx->transform_data + obj->transform_id * 16;
		float tx = xform[12] / 20.0f;   /* twips to pixels */
		float ty = xform[13] / 20.0f;
		float a = xform[0], b = xform[1], c = xform[4], dd = xform[5];
		float xscale = sqrtf(a * a + b * b) * 100.0f;
		float yscale = sqrtf(c * c + dd * dd) * 100.0f;
		float rotation = atan2f(b, a) * 180.0f / (float)M_PI;

		printf("depth %zu: char_id=%zu type=%s\n", d, obj->char_id, type_name);
		printf("  transform_id=%u\n", obj->transform_id);
		printf("  x=%.1f y=%.1f\n", tx, ty);
		printf("  xscale=%.1f yscale=%.1f\n", xscale, yscale);
		printf("  rotation=%.1f\n", rotation);

		if (obj->instance_name)
			printf("  name=%s\n", obj->instance_name);

		/* Color transform (only available in graphics mode) */
#ifndef NO_GRAPHICS
		if (obj->has_cxform) {
			float* cxf = (float*)ctx->cxform_data + obj->cxform_id * 20;
			printf("  cxform: ra=%.0f ga=%.0f ba=%.0f aa=%.0f\n",
				cxf[0] * 100, cxf[5] * 100, cxf[10] * 100, cxf[15] * 100);
		}
#endif
	}
	printf("=== end display list ===\n");
}

void test_harness_init(SWFAppContext* ctx)
{
	(void)ctx;
	extern void (*g_after_tick_handler)(SWFAppContext*, int);
	g_after_tick_handler = (void (*)(SWFAppContext*, int))after_tick;
}
