#!/usr/bin/env python3
"""
Generate test.swf for constant pool test.

Tests the ConstantPool opcode (0x88) with Push type 8 (constant pool index).
"""

import struct
import zlib

def create_swf():
    """Create a minimal SWF file with constant pool and trace actions."""

    # SWF Header
    swf_version = 5  # ConstantPool requires SWF 5+

    # Define the constant pool strings
    constant_pool_strings = [b"hello", b"world", b"test"]

    # Build ConstantPool action (0x88)
    # Format: 0x88 <length:u16> <count:u16> <string1\0> <string2\0> ...
    constant_pool_data = struct.pack('<H', len(constant_pool_strings))  # count
    for s in constant_pool_strings:
        constant_pool_data += s + b'\0'

    action_constant_pool = bytes([0x88])  # opcode
    action_constant_pool += struct.pack('<H', len(constant_pool_data))  # length
    action_constant_pool += constant_pool_data

    # Push constant pool index 0 ("hello")
    # Format: 0x96 <length:u16> <type:u8=8> <index:u8>
    action_push_0 = bytes([0x96])  # PUSH opcode
    action_push_0 += struct.pack('<H', 2)  # length (type byte + index byte)
    action_push_0 += bytes([8])  # type 8 = constant pool index (8-bit)
    action_push_0 += bytes([0])  # index 0

    # Trace
    action_trace = bytes([0x26])  # TRACE opcode (no length field)

    # Push constant pool index 1 ("world")
    action_push_1 = bytes([0x96])
    action_push_1 += struct.pack('<H', 2)
    action_push_1 += bytes([8, 1])  # type 8, index 1

    # Trace
    action_trace2 = bytes([0x26])

    # Push constant pool index 2 ("test")
    action_push_2 = bytes([0x96])
    action_push_2 += struct.pack('<H', 2)
    action_push_2 += bytes([8, 2])  # type 8, index 2

    # Trace
    action_trace3 = bytes([0x26])

    # End
    action_end = bytes([0x00])

    # Combine all actions
    actions = (action_constant_pool +
               action_push_0 + action_trace +
               action_push_1 + action_trace2 +
               action_push_2 + action_trace3 +
               action_end)

    # DoAction tag
    # Tag type 12 (DoAction) = 0x3F << 6 = 0x0FC0 (but we use short form)
    # Actually DoAction is tag 12, so (12 << 6) | length_flag
    tag_type = 12
    action_length = len(actions)

    # Long form: tag_and_length = (tag_type << 6) | 0x3F, then length as u32
    if action_length >= 63:
        tag_header = struct.pack('<H', (tag_type << 6) | 0x3F)
        tag_header += struct.pack('<I', action_length)
    else:
        tag_header = struct.pack('<H', (tag_type << 6) | action_length)

    doaction_tag = tag_header + actions

    # SetBackgroundColor tag (tag 9)
    # RGB = white (255, 255, 255)
    bgcolor_tag = struct.pack('<H', (9 << 6) | 3)  # tag 9, length 3
    bgcolor_tag += bytes([255, 255, 255])

    # ShowFrame tag (tag 1, no data)
    showframe_tag = struct.pack('<H', 1 << 6)  # tag 1, length 0

    # End tag (tag 0)
    end_tag = struct.pack('<H', 0)

    # Combine all tags
    tags = bgcolor_tag + doaction_tag + showframe_tag + end_tag

    # Calculate frame size (in twips, 1 pixel = 20 twips)
    # Simple 550x400 pixel stage
    xmin, xmax = 0, 550 * 20
    ymin, ymax = 0, 400 * 20

    # RECT format (variable bit-length)
    # We'll use 16 bits per coordinate (sufficient for our values)
    nbits = 16

    # Build rect bitstream
    rect_bits = format(nbits, '05b')  # 5 bits for nbits
    rect_bits += format(xmin, '016b')
    rect_bits += format(xmax, '016b')
    rect_bits += format(ymin, '016b')
    rect_bits += format(ymax, '016b')

    # Pad to byte boundary
    while len(rect_bits) % 8 != 0:
        rect_bits += '0'

    # Convert to bytes
    rect_bytes = bytes([int(rect_bits[i:i+8], 2) for i in range(0, len(rect_bits), 8)])

    # Frame rate: 30 fps (fixed point 8.8)
    frame_rate = struct.pack('<H', 30 << 8)

    # Frame count
    frame_count = struct.pack('<H', 1)

    # Build SWF body
    swf_body = rect_bytes + frame_rate + frame_count + tags

    # File length (header + body)
    file_length = 8 + len(swf_body)  # 8 bytes for uncompressed header

    # Build header
    header = b'FWS'  # Uncompressed SWF
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
    print("hello")
    print("world")
    print("test")
