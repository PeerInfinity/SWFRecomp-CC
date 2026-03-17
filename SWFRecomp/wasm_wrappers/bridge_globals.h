// Bridge globals for dynamic guest modules.
// These pointers are initialized by bridge_init() to point into the host
// module's memory, allowing the guest to read/write shared globals.

#pragma once

#include <stdint.h>

extern int* _bridge_catch_up_mode;
extern int* _bridge_g_tag_skip_mode;
extern int* _bridge_quit_swf;
extern void* _bridge_g_override_this;     // ActionVar*
extern int* _bridge_g_override_this_set;

void bridge_init(int* catch_up_mode_ptr, int* g_tag_skip_mode_ptr,
                 int* quit_swf_ptr, void* g_override_this_ptr,
                 int* g_override_this_set_ptr);
