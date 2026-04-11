#!/usr/bin/env python3
"""Extract DoABC tag bytes from a compiled AS3 SWF and emit as a JS constant.

Usage: python3 extract_bytecode_as3.py bridge.swf > bridge_bytecode_as3.js
"""
import struct
import sys
import zlib

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
            if pos + 4 > len(data):
                break
            length = struct.unpack_from('<I', data, pos)[0]
            pos += 4
        body = data[pos:pos + length]
        full = data[tag_start:pos + length]
        pos += length
        yield tag_type, body, full
        if tag_type == 0:
            break

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 extract_bytecode_as3.py <swf_file>", file=sys.stderr)
        sys.exit(1)

    with open(sys.argv[1], 'rb') as f:
        data = f.read()

    sig = data[0:3].decode('ascii')
    if sig == 'CWS':
        data = b'FWS' + data[3:8] + zlib.decompress(data[8:])
    elif sig != 'FWS':
        print(f"Error: expected FWS or CWS, got {sig}", file=sys.stderr)
        sys.exit(1)

    pos = 8
    pos = parse_rect(data, pos)
    pos += 4

    # Collect DoABC (82) tags — patch flags to 0 (eager init)
    # so script initializers run immediately when the tag is processed
    bridge_tags = []
    for tag_type, body, full in read_tags(data, pos):
        if tag_type == 82:  # DoABC
            flags = struct.unpack_from('<I', body, 0)[0]
            name_end = body.index(0, 4)
            abc_name = body[4:name_end].decode('ascii', errors='replace')
            abc_len = len(body) - (name_end - 0 + 1)
            print(f"// DoABC: flags={flags} name=\"{abc_name}\" abc_bytes={abc_len}",
                  file=sys.stderr)

            # Patch flags to 0 (eager init) if lazy
            if flags == 1:
                full = bytearray(full)
                # Find flags offset: after tag header (2 or 6 bytes)
                hdr = struct.unpack_from('<H', full, 0)[0]
                hdr_len = 6 if (hdr & 0x3F) == 0x3F else 2
                struct.pack_into('<I', full, hdr_len, 0)
                full = bytes(full)
                print(f"// Patched flags from 1 to 0 (eager init)", file=sys.stderr)

            bridge_tags.append(full)

    if not bridge_tags:
        print("No DoABC tags found!", file=sys.stderr)
        sys.exit(1)

    # Build supporting tags to get our class instantiated on stage:
    # 1. DefineSprite (tag 39) — empty sprite, character ID 65000
    # 2. SymbolClass (tag 76) — maps our class name to sprite ID
    # 3. PlaceObject2 (tag 26) — places sprite at depth 65000
    SPRITE_ID = 65000
    DEPTH = 65000

    def make_tag(tag_type, body):
        length = len(body)
        if length < 63:
            header = struct.pack('<H', (tag_type << 6) | length)
        else:
            header = struct.pack('<H', (tag_type << 6) | 0x3F)
            header += struct.pack('<I', length)
        return header + body

    # DefineSprite: spriteId(UI16) + frameCount(UI16) + End tag(UI16)
    define_sprite = make_tag(39,
        struct.pack('<HH', SPRITE_ID, 1) +  # id, frame count
        struct.pack('<H', (1 << 6) | 0) +   # ShowFrame tag
        struct.pack('<H', 0))                # End tag

    # SymbolClass: count(UI16) + [id(UI16) + name(null-terminated string)]
    # Find the class name from the DoABC
    class_name = b'BridgeInjectAS3'  # default
    for tag_type, body, full in read_tags(data, pos):
        if tag_type == 76:  # SymbolClass in source SWF
            count = struct.unpack_from('<H', body, 0)[0]
            off = 2
            for i in range(count):
                sid = struct.unpack_from('<H', body, off)[0]
                off += 2
                name_end = body.index(0, off)
                name = body[off:name_end]
                off = name_end + 1 - 0
                if sid != 0:  # skip document class (id=0)
                    class_name = name
                    break

    symbol_class = make_tag(76,
        struct.pack('<H', 1) +              # count = 1
        struct.pack('<H', SPRITE_ID) +      # character id
        class_name + b'\x00')               # class name (null terminated)

    # PlaceObject2: flags(UI8) + depth(UI16) + characterId(UI16)
    # flags: 0x02 = hasCharacter
    place_object = make_tag(26,
        struct.pack('<BHH', 0x02, DEPTH, SPRITE_ID))

    # Combine: DoABC tags + DefineSprite + SymbolClass + PlaceObject2
    combined = b''.join(bridge_tags) + define_sprite + symbol_class + place_object

    hex_str = ','.join(f'0x{b:02x}' for b in combined)
    print(f"// Auto-generated from {sys.argv[1]}")
    print(f"// {len(bridge_tags)} DoABC tag(s) + DefineSprite + SymbolClass + PlaceObject2")
    print(f"// {len(combined)} bytes total")
    print(f"var BRIDGE_BYTECODE_AS3 = new Uint8Array([{hex_str}]);")

if __name__ == '__main__':
    main()
