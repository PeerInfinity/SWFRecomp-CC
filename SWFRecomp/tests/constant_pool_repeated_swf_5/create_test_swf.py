#!/usr/bin/env python3
"""
Generate test.swf for constant pool repeated references test.

Tests the ConstantPool opcode (0x88) with repeated references to the same index.
This verifies that the same string can be pushed multiple times from the pool.
"""

import struct

def create_swf():
    """Create a minimal SWF file with constant pool and repeated index references."""

    # SWF Header
    swf_version = 5

    # Define the constant pool with a single string
    constant_pool_strings = [b"message"]

    # Build ConstantPool action (0x88)
    constant_pool_data = struct.pack('<H', len(constant_pool_strings))  # count
    for s in constant_pool_strings:
        constant_pool_data += s + b'\0'

    action_constant_pool = bytes([0x88])  # opcode
    action_constant_pool += struct.pack('<H', len(constant_pool_data))  # length
    action_constant_pool += constant_pool_data

    # Push constant pool index 0 ("message") - first time
    action_push_0_first = bytes([0x96])
    action_push_0_first += struct.pack('<H', 2)
    action_push_0_first += bytes([8, 0])  # type 8, index 0

    # Trace
    action_trace1 = bytes([0x26])

    # Push constant pool index 0 ("message") - second time
    action_push_0_second = bytes([0x96])
    action_push_0_second += struct.pack('<H', 2)
    action_push_0_second += bytes([8, 0])  # type 8, index 0

    # Trace
    action_trace2 = bytes([0x26])

    # Push constant pool index 0 ("message") - third time
    action_push_0_third = bytes([0x96])
    action_push_0_third += struct.pack('<H', 2)
    action_push_0_third += bytes([8, 0])  # type 8, index 0

    # Trace
    action_trace3 = bytes([0x26])

    # End
    action_end = bytes([0x00])

    # Combine all actions
    actions = (action_constant_pool +
               action_push_0_first + action_trace1 +
               action_push_0_second + action_trace2 +
               action_push_0_third + action_trace3 +
               action_end)

    # DoAction tag
    tag_type = 12
    action_length = len(actions)

    if action_length >= 63:
        tag_header = struct.pack('<H', (tag_type << 6) | 0x3F)
        tag_header += struct.pack('<I', action_length)
    else:
        tag_header = struct.pack('<H', (tag_type << 6) | action_length)

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

    # Build rect bitstream
    rect_bits = format(nbits, '05b')
    rect_bits += format(xmin, '016b')
    rect_bits += format(xmax, '016b')
    rect_bits += format(ymin, '016b')
    rect_bits += format(ymax, '016b')

    # Pad to byte boundary
    while len(rect_bits) % 8 != 0:
        rect_bits += '0'

    # Convert to bytes
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
    print("message")
    print("message")
    print("message")
