#!/usr/bin/env python3
"""Extract DoAction tag bytes from a compiled SWF and emit as a JS constant.

Usage: python3 extract_bytecode.py bridge_inject.swf > bridge_bytecode.js
"""
import struct
import sys

def parse_rect(data, pos):
    """Skip past a RECT record, return new position."""
    nbits = (data[pos] >> 3) & 0x1F
    total_bits = 5 + nbits * 4
    total_bytes = (total_bits + 7) // 8
    return pos + total_bytes

def read_tags(data, pos):
    """Yield (tag_type, tag_body_bytes, full_tag_bytes) for each tag."""
    while pos < len(data):
        tag_start = pos
        if pos + 2 > len(data):
            break
        code_and_length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        tag_type = (code_and_length >> 6) & 0x3FF
        length = code_and_length & 0x3F
        if length == 0x3F:
            if pos + 4 > len(data):
                break
            length = struct.unpack_from('<I', data, pos)[0]
            pos += 4
        body = data[pos:pos + length]
        full = data[tag_start:pos + length]
        pos += length
        yield tag_type, body, full
        if tag_type == 0:  # End tag
            break

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 extract_bytecode.py <swf_file>", file=sys.stderr)
        sys.exit(1)

    with open(sys.argv[1], 'rb') as f:
        data = f.read()

    # Parse header — decompress if CWS
    sig = data[0:3].decode('ascii')
    if sig == 'CWS':
        import zlib
        decompressed = zlib.decompress(data[8:])
        data = b'FWS' + data[3:8] + decompressed
    elif sig != 'FWS':
        print(f"Error: expected FWS or CWS, got {sig}", file=sys.stderr)
        sys.exit(1)

    # Skip header (8 bytes) + RECT + frame rate (2) + frame count (2)
    pos = 8
    pos = parse_rect(data, pos)
    pos += 4  # frame rate + frame count

    # Collect all tags needed for the bridge:
    # DefineSprite (39), ExportAssets (56), DoInitAction (59), DoAction (12)
    # Skip SetBackgroundColor (9), ShowFrame (1), End (0)
    bridge_tags = []
    for tag_type, body, full in read_tags(data, pos):
        if tag_type in (39, 56, 59, 12):  # DefineSprite, ExportAssets, DoInitAction, DoAction
            bridge_tags.append(full)

    if not bridge_tags:
        print("No bridge tags found!", file=sys.stderr)
        sys.exit(1)

    # Concatenate all bridge tags
    combined = b''.join(bridge_tags)

    # Emit as JS
    hex_str = ','.join(f'0x{b:02x}' for b in combined)
    print(f"// Auto-generated from {sys.argv[1]}")
    print(f"// {len(bridge_tags)} tag(s), {len(combined)} bytes total")
    print(f"var BRIDGE_BYTECODE = new Uint8Array([{hex_str}]);")

if __name__ == '__main__':
    main()
