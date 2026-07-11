// JSON builtin (ECMA-262 with avmplus quirks) — port of Ruffle
// core/src/avm2/globals/json.rs. Registration is SWF-version-gated by the
// caller (JSON exists from SWF11/FP10.3; json_version_gated).

#include <avm2/avm2_class.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>

void avm2_register_json(Avm2Context* ctx)
{
	(void) ctx;
}
