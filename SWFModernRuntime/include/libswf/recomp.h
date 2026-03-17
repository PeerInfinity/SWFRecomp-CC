#pragma once

#include <common.h>

// libswf
#include <swf.h>
#include <tag.h>

// actionmodern
#include <action.h>
#include <variables.h>
#include <object.h>

// Goto catch-up mode flag.
// When set, generated frame functions skip their script_N() calls
// while tag functions (PlaceObject, RemoveObject, etc.) still execute.
// Defined in swf_core.c (NO_GRAPHICS), swf_headless.c (HEADLESS), swf.c (GRAPHICS).
//
// In DYNAMIC_GUEST mode (in-browser compiled guest module), these are
// redirected to pointer dereferences via -D flags so the guest accesses
// the host module's globals through shared memory.
#ifndef DYNAMIC_GUEST
extern int catch_up_mode;
// When set, tag functions are no-ops but scripts still run.
// Used for deferred goto script execution (tags already processed inline).
extern int g_tag_skip_mode;
#endif