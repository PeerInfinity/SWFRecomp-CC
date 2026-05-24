#!/usr/bin/env python3
"""Extract DoInitAction/DoAction/ExportAssets/DefineSprite tag bytes from a
compiled tracer SWF and emit raw concatenated bytes.

Usage: python3 extract_bytecode.py tracer.swf tracer_bytecode.bin

Mirrors demos/ruffle-inject/extract_bytecode.py but writes raw bytes instead of
a JS Uint8Array literal, since inject_tracer.py reads the file directly.
"""
import struct
import sys


def parse_rect(data, pos):
    nbits = (data[pos] >> 3) & 0x1F
    total_bits = 5 + nbits * 4
    return pos + (total_bits + 7) // 8


def read_tags(data, pos):
    while pos < len(data):
        tag_start = pos
        if pos + 2 > len(data):
            break
        code_and_length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        tag_type = (code_and_length >> 6) & 0x3FF
        length = code_and_length & 0x3F
        if length == 0x3F:
            length = struct.unpack_from('<I', data, pos)[0]
            pos += 4
        full = data[tag_start:pos + length]
        pos += length
        yield tag_type, full
        if tag_type == 0:
            break


def main():
    if len(sys.argv) < 3:
        print("Usage: extract_bytecode.py <input.swf> <output.bin>", file=sys.stderr)
        sys.exit(2)
    src, dst = sys.argv[1], sys.argv[2]

    with open(src, 'rb') as f:
        data = f.read()

    sig = data[0:3].decode('ascii')
    if sig == 'CWS':
        import zlib
        data = b'FWS' + data[3:8] + zlib.decompress(data[8:])
    elif sig != 'FWS':
        print(f"Error: expected FWS or CWS, got {sig}", file=sys.stderr)
        sys.exit(1)

    pos = 8
    pos = parse_rect(data, pos)
    pos += 4  # frame rate + frame count

    keep = []
    counts = {}
    for tag_type, full in read_tags(data, pos):
        # DefineSprite(39), ExportAssets(56), DoInitAction(59), DoAction(12)
        if tag_type in (12, 39, 56, 59):
            keep.append(full)
            counts[tag_type] = counts.get(tag_type, 0) + 1

    if not keep:
        print("No tracer tags found in SWF", file=sys.stderr)
        sys.exit(1)

    blob = b''.join(keep)
    with open(dst, 'wb') as f:
        f.write(blob)

    print(f"Wrote {dst}: {len(blob)} bytes ({len(keep)} tags: {counts})", file=sys.stderr)


if __name__ == '__main__':
    main()
