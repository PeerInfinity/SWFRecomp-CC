#!/usr/bin/env python3
"""Build child.swf (AS3-flagged, carries an AVM1 sound payload) for
regression/avm1_parent_as3_child_payload, and drive MTASC for test.swf.

WHAT THIS PINS DOWN
-------------------
The dead-payload skip (`skip_avm1_payload`, SWFRecompDocs/status/
avm2-dead-payload-skip.md) drops draws.c's bitmap_data / sound_data /
video_data — and the tagInit calls that reference them — for any SWF whose
FileAttributes carries the AS3 bit. The option shipped gated on `is_as3`,
with a documented seam: `is_as3` is NOT the same predicate as "this SWF's
tagInit will never run". An AS3 SWF loaded as a CHILD by an AVM1 parent has
its `init_func` (= its tagInit) called by the AVM1 loader
(`entry->init_func` in SWFModernRuntime/src/actionmodern/action.c), so with
the option on such a child silently lost its AVM1-side sound/bitmap
dictionary. Fixed by making the drop additionally require that the recompile
is NOT a child recompile (`Config::child_movie` / `[input] child_movie`).

This test is that seam, made observable in a trace suite:

  parent test.swf (AVM1, SWF8, MTASC)   loadMovie("child.swf")
  child.swf       (AS3 bit set)         DefineSound + ExportAssets

The child's ExportAssets registration (`tagRegisterExport`) is NOT part of
the payload, so `ng_lookupExport("childSound")` resolves either way; only
`tagDefineSound` — hence `ng_getSoundDuration` — is dropped. So
`Sound.attachSound("childSound")` + `getDuration()` reads exactly the
dictionary entry the option removes:

  correct (payload kept):     dur:200
  seam   (payload dropped):   dur:undefined

Run it against the recompiler with the option forced on to see the flip:
  SWF_SKIP_AVM1_PAYLOAD=1 python3 ruffle-tests/verify_output.py \
      --test=avm1_parent_as3_child_payload --recompile --diff

WHY THE CHILD HAS NO DoABC
--------------------------
`is_as3` is set by the FileAttributes AS3 bit alone (SWFRecomp/src/swf.cpp,
SWF_TAG_FILE_ATTRIBUTES), which is precisely the predicate the option gates
on, so the bit alone is the minimal and exact trigger. Adding a DoABC would
change nothing about the gate: an AVM1 parent's build never compiles the
child's RecompiledABC (verify_output.py links an AVM2 child's tables only
when the PARENT is an AVM2 test), so the child's AS3 code would not run
either way — the AVM1-side dictionary this test reads is all that is left of
such a child, which is the whole point.

Sound numbers: 8-bit mono uncompressed at rate index 1 (11025 Hz) with
sample_count 2205 => 2205 * 1000 / 11025 = 200 ms exactly, so the expected
output holds no float formatting.
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

SOUND_CHAR_ID = 1
EXPORT_NAME = "childSound"
SAMPLE_RATE_INDEX = 1      # 11025 Hz
SAMPLE_COUNT = 2205        # -> 200 ms


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


def build_child(path):
    tags = b''

    # FileAttributes (69). Byte 0 bits, MSB first: reserved, UseDirectBlit,
    # UseGPU, HasMetadata, ActionScript3, reserved, reserved, UseNetwork.
    # 0x08 = ActionScript3 only -> SWF::is_as3.  MUST be the first tag.
    tags += tag(69, bytes([0x08, 0x00, 0x00, 0x00]))

    # DefineSound (14): SoundId UI16, flags UI8, SampleCount UI32, data.
    # flags = format<<4 | rate<<2 | sampleSize<<1 | stereo
    #       = 0 (uncompressed native-endian) | rate 1 | 8-bit | mono
    flags = (0 << 4) | (SAMPLE_RATE_INDEX << 2) | (0 << 1) | 0
    pcm = bytes(((i * 7) & 0xFF) for i in range(SAMPLE_COUNT))
    tags += tag(14, struct.pack('<HBI', SOUND_CHAR_ID, flags, SAMPLE_COUNT) + pcm)

    # ExportAssets (56): Count UI16, then Count * (CharId UI16 + name\0).
    tags += tag(56, struct.pack('<HH', 1, SOUND_CHAR_ID)
                + EXPORT_NAME.encode('ascii') + b'\x00')

    tags += tag(1, b'')                     # ShowFrame
    tags += struct.pack('<H', 0)            # End

    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 9, file_length) + body)
    print(f'Created {path} (SWF9, AS3 bit set, {file_length} bytes)')


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    cmd = [str(mtasc), '-cp', str(std), '-main', '-header', '200:150:30',
           'Parent.as', '-swf', path.name, '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)
    print(f'Created {path} ({path.stat().st_size} bytes)')


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
