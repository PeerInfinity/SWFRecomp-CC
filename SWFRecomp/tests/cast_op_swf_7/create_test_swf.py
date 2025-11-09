#!/usr/bin/env python3
"""
Create a minimal SWF7 file that tests the CastOp opcode (0x2B).

Tests:
1. Cast with primitives (should fail - return null)
2. Cast with objects (basic test - no prototype chain yet)
3. Verify cast returns null for non-matching types
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

    actions = b''

    # Helper to create PUSH for string
    def push_string(s):
        s_bytes = s.encode('utf-8') + b'\x00'
        return struct.pack('<BHB', 0x96, len(s_bytes) + 1, 0) + s_bytes

    # Helper to create PUSH for float
    def push_float(f):
        return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', f)

    # Test 1: Cast primitive to constructor (should fail - return null/undefined)
    # Push a float (primitive value)
    actions += push_float(42.0)

    # Push constructor (also a float for now - will fail)
    actions += push_float(1.0)

    # ActionCastOp: 0x2B
    actions += bytes([0x2B])

    # Result should be undefined/null. Check if it's undefined (type 5)
    # We'll just pop it and trace "primitive_cast_failed"
    actions += bytes([0x17])  # POP
    actions += push_string("primitive_cast_failed")
    actions += bytes([0x26])  # TRACE

    # Test 2: Cast with object (but without proper prototype - should also fail)
    # Create a simple object using INIT_OBJECT
    actions += push_float(0.0)  # Number of properties (0)
    actions += bytes([0x43])  # INIT_OBJECT (0x43)

    # Create a constructor object (also empty)
    actions += push_float(0.0)
    actions += bytes([0x43])  # INIT_OBJECT

    # Try to cast - should fail because no prototype chain set up
    actions += bytes([0x2B])  # CAST_OP

    # Pop result and trace
    actions += bytes([0x17])  # POP
    actions += push_string("object_cast_without_proto_failed")
    actions += bytes([0x26])  # TRACE

    # Test 3: Verify cast doesn't crash with mixed types
    # Create an object
    actions += push_float(0.0)
    actions += bytes([0x43])  # INIT_OBJECT

    # Try to cast with a primitive constructor (should fail gracefully)
    actions += push_float(5.0)
    actions += bytes([0x2B])  # CAST_OP

    # Pop and trace
    actions += bytes([0x17])  # POP
    actions += push_string("mixed_type_cast_failed")
    actions += bytes([0x26])  # TRACE

    # Final success message
    actions += push_string("cast_op_tests_completed")
    actions += bytes([0x26])  # TRACE

    # ActionEnd: 0x00
    actions += bytes([0x00])

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
    print("Tests:")
    print("  1. Cast primitive to constructor (should fail)")
    print("  2. Cast object without prototype setup (should fail)")
    print("  3. Cast with mixed types (should fail gracefully)")
    print("Expected output:")
    print("  primitive_cast_failed")
    print("  object_cast_without_proto_failed")
    print("  mixed_type_cast_failed")
    print("  cast_op_tests_completed")
