#!/usr/bin/env python3
"""
Create a minimal SWF4 file that tests the Push opcode (0x96) with various data types.

Test cases:
1. Push Integer (as float): 42
2. Push String: "Hello"
3. Push Float: 3.14
4. Push Boolean (as float): 1 (true)

Expected output:
42
Hello
3.14
1
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

    # Test 1: Push Integer 42 (as float) and trace
    action_push_int = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float (IEEE 754 single precision)
        0x00, 0x00, 0x28, 0x42  # 42.0 in IEEE 754 format (little-endian)
    ])
    action_trace_1 = bytes([0x26])  # ActionTrace

    # Test 2: Push String "Hello" and trace
    action_push_string = bytes([
        0x96,  # ActionPush opcode
        0x07, 0x00,  # Length: 7 bytes (1 type byte + 5 chars + 1 null)
        0x00,  # Type 0: String
    ]) + b'Hello\x00'  # Null-terminated string
    action_trace_2 = bytes([0x26])  # ActionTrace

    # Test 3: Push Float 3.14 and trace
    # 3.14 in IEEE 754 single precision = 0x4048F5C3
    action_push_float = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float
        0xC3, 0xF5, 0x48, 0x40  # 3.14 in IEEE 754 format (little-endian)
    ])
    action_trace_3 = bytes([0x26])  # ActionTrace

    # Test 4: Push Boolean true (represented as 1.0) and trace
    action_push_bool = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float (booleans are often represented as floats in SWF4)
        0x00, 0x00, 0x80, 0x3F  # 1.0 in IEEE 754 format (little-endian)
    ])
    action_trace_4 = bytes([0x26])  # ActionTrace

    # ActionEnd: 0x00
    action_end = bytes([0x00])

    # Combine all actions
    actions = (action_push_int + action_trace_1 +
               action_push_string + action_trace_2 +
               action_push_float + action_trace_3 +
               action_push_bool + action_trace_4 +
               action_end)

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
    print("Tests: Push with different types")
    print("Expected output:")
    print("42")
    print("Hello")
    print("3.14")
    print("1")
