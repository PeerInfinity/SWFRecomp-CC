#!/usr/bin/env python3
"""Regenerate test.swf for the avm2_embed_bytearray regression test.

Pins down: a Flex `[Embed(mimeType="application/octet-stream")]` binary asset,
compiled to a class extending mx.core.ByteArrayAsset -> flash.utils.ByteArray,
must construct as a POPULATED ByteArray (the DefineBinaryData bytes), not an
empty one. Before the fix, `new EmbeddedClass()` yielded a zero-length ByteArray
(runtime never seeded it from the SymbolClass-bound binary char), so every
FlashPunk `.oel` level load in Seedling saw width=0 and added zero tiles (the
world rendered ~99% black). Fixed by seeding the ByteArray from
avm2_generated_binaries in ba_native_init (avm2_bytearray.c).

Requires the Apache Flex SDK (mxmlc). Run from this directory:
    python3 create_test_swf.py
"""
import subprocess, pathlib
HERE = pathlib.Path(__file__).parent
MXMLC = pathlib.Path.home() / "CC/flex-sdk/bin/mxmlc"
(HERE / "payload.bin").write_bytes(b"SWFRecomp-BinaryData-OK")
subprocess.run([str(MXMLC), "-omit-trace-statements=false",
                "-target-player=11.1",
                "-static-link-runtime-shared-libraries=true",
                str(HERE / "Test.as"), "-output", str(HERE / "test.swf")],
               check=True)
print("wrote", HERE / "test.swf")
