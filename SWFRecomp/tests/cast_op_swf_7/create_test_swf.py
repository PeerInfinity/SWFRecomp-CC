#!/usr/bin/env python3
"""
Create a minimal SWF7 file that tests the CastOp opcode (0x2B).
Test: push float (object), push float (constructor), cast, pop result, trace success
Note: Since proper object support isn't implemented yet, we use floats which will
result in undefined from the cast operation (cast fails for non-objects).
"""

import struct

def create_swf():
    # SWF Header (uncompressed, version 7 for ActionScript 2.0 features)
    signature = b'FWS'
    version = struct.pack('<B', 7)  # SWF version 7

    # Frame size (RECT): 0 to 8000 twips (400 pixels)
    rect = bytes([0x78, 0x00, 0x05, 0x5F, 0x00, 0x00, 0x0F, 0xA0, 0x00])

    # Frame rate: 24 fps (fixed 8.8 format)
    frame_rate = struct.pack('<H', 24 << 8)

    # Frame count: 1 frame
    frame_count = struct.pack('<H', 1)

    # DoAction tag with our test bytecode
    # Push a float value (representing object to cast)
    # Since we don't have proper object support yet, we'll push a float
    # The CastOp implementation will return undefined for non-object types
    action_push_obj = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float
        0x00, 0x00, 0x00, 0x00  # 0.0 in IEEE 754 format
    ])

    # Push another float (representing constructor function)
    action_push_ctor = bytes([
        0x96,  # ActionPush opcode
        0x05, 0x00,  # Length: 5 bytes
        0x01,  # Type 1: Float
        0x00, 0x00, 0x80, 0x3F  # 1.0 in IEEE 754 format
    ])

    # ActionCastOp: 0x2B
    # This will pop both values and push undefined (since cast fails for non-objects)
    action_cast = bytes([0x2B])

    # Pop the result to clean up the stack
    action_pop = bytes([0x17])

    # Push a string constant to trace
    # "cast_test_passed"
    test_msg = b"cast_test_passed"
    action_push_str = bytes([
        0x96,  # ActionPush opcode
        len(test_msg) + 2, 0x00,  # Length: string length + 2
        0x00,  # Type 0: String
    ]) + test_msg + bytes([0x00])  # Null-terminated string

    # ActionTrace: 0x26
    action_trace = bytes([0x26])

    # ActionEnd: 0x00
    action_end = bytes([0x00])

    # Combine actions
    actions = (action_push_obj + action_push_ctor + action_cast +
               action_pop + action_push_str + action_trace + action_end)

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
    print("Test: push float, push float, cast, pop, trace success message")
    print("Expected output: cast_test_passed")
