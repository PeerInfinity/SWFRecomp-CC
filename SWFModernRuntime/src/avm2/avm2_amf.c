// AMF3/AMF0 serialization (ByteArray.readObject/writeObject,
// flash.net.registerClassAlias) — port of the flash-lso crate's wire
// format (amf3/write.rs, read.rs, amf0/*) with Ruffle's AVM2 bridge
// semantics (core/src/avm2/amf.rs). Implemented in tranche 3.5; the
// entry points below abort honestly until then.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

Avm2Value avm2_amf_read_object(Avm2Activation* act)
{
	(void) act;
	avm2_fatal("ByteArray.readObject: AMF not yet implemented (tranche 3.5)");
}

Avm2Value avm2_amf_write_object(Avm2Activation* act)
{
	(void) act;
	avm2_fatal("ByteArray.writeObject: AMF not yet implemented (tranche 3.5)");
}
