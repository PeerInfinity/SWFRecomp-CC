#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_bitmap.

WHAT THIS PINS DOWN
-------------------
The bitmap-metadata registry used to record *where in an array* a bitmap's
pixels live, but never *which array*:

    defineBitmap(offset, size, w, h, char_id)          # SWFModernRuntime/src/libswf/tag.c
      -> ng_registerBitmapMetadata(char_id, offset, ...)
    BitmapData.loadBitmap(name)                        # .../src/actionmodern/action.c
      -> ng_getBitmapMetadata(char_id, &offset, ...)
      -> GEN_EXTERN_BITMAP_DATA; (u32*)(bitmap_data + offset)

`offset` is a byte offset into the EMITTING movie's own `bitmap_data`, but the
reader always dereferenced the MAIN movie's `bitmap_data` global. A child SWF's
array is renamed `<prefix>_bitmap_data` by verify_output.py's
`generate_child_movie_file`, so a child's offset indexed the parent's pixels.

A second, independent defect sat in front of it: `defineBitmap` was missing
from that wrapper's per-call char-id offset list (memory note
`child-movie-charid-offset-per-callsite`; the same omission that broke
`tagDefineSound` until 2026-09-03). A child's bitmap registered its metadata
under the RAW char id while `tagRegisterExport` published the OFFSET id
(`movie_id * 1000`), so the lookup found nothing at all.

The two defects stack, so the test has three distinct states:

    master (both defects)          cpx:none        / csz:none
    char-id offset only            cpx:16711680    / csz:2x2   (the PARENT's red)
    fixed (this commit)            cpx:255         / csz:2x2   (the child's blue)

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC)   4x4 opaque RED   exported "parentBitmap"
                     loadMovie("child.swf")
    child.swf        (AVM1, hand-built)    2x2 opaque BLUE  exported "childBitmap"

Both bitmaps are the only bitmap in their own movie, so both sit at offset 0 of
their own `bitmap_data` — the exact collision that makes the wrong-array read
land on real, in-bounds, deterministic pixels instead of on garbage. The child
is 2x2 and the parent 4x4 so the wrong-array read (16 bytes) stays inside the
parent's 64-byte array: the failure is a wrong COLOR, not a crash.

The sizes also separate the two registries: `csz:` comes from the metadata
entry (char id -> w/h) and `cpx:` from the pixel array, so a future half-fix
that repairs one and not the other is still visible.

`bitmap_data` holds R,G,B,A bytes per pixel and `getPixel` returns 0xRRGGBB:
red = 16711680, blue = 255. Alpha is 255 everywhere so no premultiplication
rounding enters the expected output.

The parent's bitmap is SPLICED into MTASC's output rather than embedded,
because MTASC has no asset-embedding syntax; the splice is a plain tag-stream
rewrite (see splice_tags).
"""
import struct
import subprocess
import sys
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent

CHILD_CHAR_ID = 1
CHILD_EXPORT = "childBitmap"
CHILD_W, CHILD_H = 2, 2
CHILD_ARGB = (0xFF, 0x00, 0x00, 0xFF)   # opaque blue -> getPixel 255

PARENT_EXPORT = "parentBitmap"
PARENT_W, PARENT_H = 4, 4
PARENT_ARGB = (0xFF, 0xFF, 0x00, 0x00)  # opaque red -> getPixel 16711680


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


def lossless2(char_id, width, height, argb):
    """DefineBitsLossless2 (36), BitmapFormat 5 (32-bit ARGB), no color table.

    Pixel rows of a 32-bit image are already 4-byte aligned, so ALPHABITMAPDATA
    is just width*height 4-byte (A,R,G,B) records, zlib-deflated.
    """
    pixels = bytes(argb) * (width * height)
    body = (struct.pack('<HBHH', char_id, 5, width, height)
            + zlib.compress(pixels, 9))
    return tag(36, body)


def export_assets(char_id, name):
    return tag(56, struct.pack('<HH', 1, char_id) + name.encode('ascii') + b'\x00')


def build_child(path):
    tags = b''
    tags += lossless2(CHILD_CHAR_ID, CHILD_W, CHILD_H, CHILD_ARGB)
    tags += export_assets(CHILD_CHAR_ID, CHILD_EXPORT)
    tags += tag(1, b'')                     # ShowFrame
    tags += struct.pack('<H', 0)            # End

    # RECT nbits=15, 0..8000 twips x 0..8000 twips (200x400 px stage, unused).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, {CHILD_W}x{CHILD_H} bitmap, {file_length} bytes)')


def read_swf(path):
    """Return (signature_version, header_rect_and_rest_prefix, tag_bytes).

    Splits an uncompressed or zlib-compressed SWF into its header fields and
    the raw tag stream, so tags can be appended before the End tag.
    """
    raw = path.read_bytes()
    sig, version, _file_len = raw[:3], raw[3], struct.unpack('<I', raw[4:8])[0]
    body = raw[8:]
    if sig == b'CWS':
        body = zlib.decompress(body)
    elif sig != b'FWS':
        raise SystemExit(f'{path}: unsupported signature {sig!r}')
    # RECT: 5-bit nbits, then 4 fields of nbits.
    nbits = body[0] >> 3
    rect_bits = 5 + 4 * nbits
    rect_len = (rect_bits + 7) // 8
    prefix = body[:rect_len + 4]        # RECT + frame rate (UI16) + frame count (UI16)
    return version, prefix, body[rect_len + 4:]


def used_char_ids(tag_bytes):
    """Character ids already defined in a tag stream (Define* tags put the id
    first). Only used to pick a non-colliding id for the spliced bitmap."""
    ids = set()
    define_tags = {2, 4, 6, 7, 10, 11, 13, 14, 17, 19, 20, 21, 22, 32, 33, 35,
                   36, 37, 39, 46, 48, 60, 75, 78, 83, 84, 90}
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        pos += 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos:pos + 4])[0]
            pos += 4
        if code == 0:
            break
        if code in define_tags and length >= 2:
            ids.add(struct.unpack('<H', tag_bytes[pos:pos + 2])[0])
        pos += length
    return ids


def splice_tags(path, extra):
    """Insert `extra` immediately before the End tag and rewrite the file."""
    version, prefix, tag_bytes = read_swf(path)
    end = tag_bytes.rfind(b'\x00\x00')
    if end == -1 or end != len(tag_bytes) - 2:
        raise SystemExit(f'{path}: End tag is not the last two bytes')
    body = prefix + tag_bytes[:end] + extra + b'\x00\x00'
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', version, file_length) + body)
    return version, tag_bytes


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:150:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)

    _version, tag_bytes = read_swf(path)[0], read_swf(path)[2]
    taken = used_char_ids(tag_bytes)
    char_id = next(i for i in range(1, 1000) if i not in taken)
    extra = (lossless2(char_id, PARENT_W, PARENT_H, PARENT_ARGB)
             + export_assets(char_id, PARENT_EXPORT))
    splice_tags(path, extra)
    print(f'Created {path} ({path.stat().st_size} bytes, '
          f'{PARENT_W}x{PARENT_H} bitmap spliced in as char {char_id})')


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
