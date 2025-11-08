#!/usr/bin/env python3
"""
Generate test.swf for constant pool large pool test.

Tests the ConstantPool opcode (0x88) with a large pool (>255 strings).
This verifies push type 9 (16-bit index) works correctly.
"""

import struct

def create_swf():
    """Create a minimal SWF file with a large constant pool."""

    # SWF Header
    swf_version = 5

    # Create a constant pool with 300 strings (requires 16-bit indices)
    # Format: "str_000", "str_001", ..., "str_299"
    constant_pool_strings = [f"str_{i:03d}".encode('ascii') for i in range(300)]

    # Build ConstantPool action (0x88)
    constant_pool_data = struct.pack('<H', len(constant_pool_strings))  # count
    for s in constant_pool_strings:
        constant_pool_data += s + b'\0'

    action_constant_pool = bytes([0x88])  # opcode
    action_constant_pool += struct.pack('<H', len(constant_pool_data))  # length
    action_constant_pool += constant_pool_data

    # Push index 0 using type 9 (16-bit) - "str_000"
    action_push_0 = bytes([0x96])
    action_push_0 += struct.pack('<H', 3)  # length (type + 2-byte index)
    action_push_0 += bytes([9])  # type 9 = 16-bit index
    action_push_0 += struct.pack('<H', 0)  # index 0
    action_trace1 = bytes([0x26])

    # Push index 255 using type 9 (16-bit) - "str_255"
    action_push_255 = bytes([0x96])
    action_push_255 += struct.pack('<H', 3)
    action_push_255 += bytes([9])
    action_push_255 += struct.pack('<H', 255)  # index 255
    action_trace2 = bytes([0x26])

    # Push index 256 using type 9 (16-bit) - "str_256" (first index requiring 16-bit)
    action_push_256 = bytes([0x96])
    action_push_256 += struct.pack('<H', 3)
    action_push_256 += bytes([9])
    action_push_256 += struct.pack('<H', 256)  # index 256
    action_trace3 = bytes([0x26])

    # Push index 299 using type 9 (16-bit) - "str_299"
    action_push_299 = bytes([0x96])
    action_push_299 += struct.pack('<H', 3)
    action_push_299 += bytes([9])
    action_push_299 += struct.pack('<H', 299)  # index 299
    action_trace4 = bytes([0x26])

    # End
    action_end = bytes([0x00])

    # Combine all actions
    actions = (action_constant_pool +
               action_push_0 + action_trace1 +
               action_push_255 + action_trace2 +
               action_push_256 + action_trace3 +
               action_push_299 + action_trace4 +
               action_end)

    # DoAction tag (use long form because action_length > 63)
    tag_type = 12
    action_length = len(actions)

    tag_header = struct.pack('<H', (tag_type << 6) | 0x3F)
    tag_header += struct.pack('<I', action_length)

    doaction_tag = tag_header + actions

    # SetBackgroundColor tag
    bgcolor_tag = struct.pack('<H', (9 << 6) | 3)
    bgcolor_tag += bytes([255, 255, 255])

    # ShowFrame tag
    showframe_tag = struct.pack('<H', 1 << 6)

    # End tag
    end_tag = struct.pack('<H', 0)

    # Combine all tags
    tags = bgcolor_tag + doaction_tag + showframe_tag + end_tag

    # Calculate frame size (in twips)
    xmin, xmax = 0, 550 * 20
    ymin, ymax = 0, 400 * 20

    # RECT format
    nbits = 16
    rect_bits = format(nbits, '05b')
    rect_bits += format(xmin, '016b')
    rect_bits += format(xmax, '016b')
    rect_bits += format(ymin, '016b')
    rect_bits += format(ymax, '016b')

    while len(rect_bits) % 8 != 0:
        rect_bits += '0'

    rect_bytes = bytes([int(rect_bits[i:i+8], 2) for i in range(0, len(rect_bits), 8)])

    # Frame rate: 30 fps
    frame_rate = struct.pack('<H', 30 << 8)

    # Frame count
    frame_count = struct.pack('<H', 1)

    # Build SWF body
    swf_body = rect_bytes + frame_rate + frame_count + tags

    # File length
    file_length = 8 + len(swf_body)

    # Build header
    header = b'FWS'
    header += bytes([swf_version])
    header += struct.pack('<I', file_length)

    # Complete SWF
    swf_data = header + swf_body

    return swf_data


if __name__ == '__main__':
    swf = create_swf()

    with open('test.swf', 'wb') as f:
        f.write(swf)

    print(f"Created test.swf ({len(swf)} bytes)")
    print("Expected output:")
    print("str_000")
    print("str_255")
    print("str_256")
    print("str_299")
