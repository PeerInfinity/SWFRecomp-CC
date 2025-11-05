#!/usr/bin/env python3
"""
Create a minimal SWF4 file that tests the Decrement opcode (0x51).
Test: push 10.0, decrement, trace (expected output: 9)
"""

import struct

def create_swf():
    # SWF Header (uncompressed, version 4)
    signature = b'FWS'
    version = struct.pack('<B', 4)  # SWF version 4

    # Frame size (RECT): 0 to 8000 twips (400 pixels)
    rect = bytes([0x78, 0x00, 0x05, 0x5F, 0x00, 0x00, 0x0F, 0xA0, 0x00])

    # Frame rate: 24 fps (fixed 8.8 format)
    frame_rate = struct.pack('<H', 24 << 8)

    # Frame count: 1 frame
    frame_count = struct.pack('<H', 1)

    # DoAction tag with our test bytecode
    # ActionPush: Push 10.0 (float)
    action_push = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float (IEEE 754 single precision, little-endian)
        0x00, 0x00, 0x20, 0x41  # 10.0 in IEEE 754 format (little-endian)
    ])

    # ActionDecrement: 0x51
    action_decrement = bytes([0x51])

    # ActionTrace: 0x26
    action_trace = bytes([0x26])

    # ActionEnd: 0x00
    action_end = bytes([0x00])

    # Combine actions
    actions = action_push + action_decrement + action_trace + action_end

    # DoAction tag
    tag_code = 12  # DoAction
    tag_length = len(actions)
    tag_header = struct.pack('<H', (tag_code << 6) | 0x3F)  # Long header
    tag_length_bytes = struct.pack('<I', tag_length)
    doaction_tag = tag_header + tag_length_bytes + actions

    # ShowFrame tag (code 1, length 0)
    showframe_tag = struct.pack('<H', 1 << 6)

    # End tag (code 0, length 0)
    end_tag = struct.pack('<H', 0)

    # Combine all tags
    tags = doaction_tag + showframe_tag + end_tag

    # Calculate file length (header + tags)
    file_length = 8 + len(rect) + len(frame_rate) + len(frame_count) + len(tags)
    file_length_bytes = struct.pack('<I', file_length)

    # Combine everything
    swf_data = signature + version + file_length_bytes + rect + frame_rate + frame_count + tags

    return swf_data

if __name__ == '__main__':
    swf_data = create_swf()
    with open('test.swf', 'wb') as f:
        f.write(swf_data)
    print(f"Created test.swf ({len(swf_data)} bytes)")
    print("Test: push 10.0, decrement, trace")
    print("Expected output: 9")
