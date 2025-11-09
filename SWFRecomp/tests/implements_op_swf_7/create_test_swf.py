#!/usr/bin/env python3
"""
Comprehensive test for the ImplementsOp (0x2C) opcode.

This test covers:
1. Single interface implementation
2. Multiple interfaces implementation
3. Zero interfaces (edge case)
4. Verifies that ImplementsOp executes without crashing

Note: Full verification with instanceof will be added when instanceof is fully implemented.
For now, we verify that ImplementsOp completes successfully for various scenarios.
"""
import struct

def create_push_int(value):
    """Create PUSH action for an integer value."""
    return struct.pack('<BHB', 0x96, 5, 7) + struct.pack('<I', value)

def create_push_float(value):
    """Create PUSH action for a float value."""
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)

def create_push_string(string):
    """Create PUSH action for a string value."""
    string_bytes = string.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes

def create_trace(message):
    """Create a trace statement."""
    return create_push_string(message) + bytes([0x26])  # Trace opcode

# Create SWF7 file (ActionScript 2.0 support)
signature = b'FWS'  # Uncompressed SWF
version = 7

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode to test ImplementsOp
actions = b''

# TEST 1: Single interface
# ========================
# Create interface object
actions += create_push_float(0.0)  # No properties
actions += bytes([0x43])  # InitObject
# Stack: [interface1]

# Push interface count (1)
actions += create_push_float(1.0)
# Stack: [interface1, 1]

# Create constructor object
actions += create_push_float(0.0)  # No properties
actions += bytes([0x43])  # InitObject
# Stack: [interface1, 1, constructor]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 1: Single interface - OK")

# TEST 2: Multiple interfaces (3 interfaces)
# ===========================================
# Create interface objects
actions += create_push_float(0.0)
actions += bytes([0x43])  # interface1
actions += create_push_float(0.0)
actions += bytes([0x43])  # interface2
actions += create_push_float(0.0)
actions += bytes([0x43])  # interface3
# Stack: [interface1, interface2, interface3]

# Push interface count (3)
actions += create_push_float(3.0)
# Stack: [interface1, interface2, interface3, 3]

# Create constructor object
actions += create_push_float(0.0)
actions += bytes([0x43])  # InitObject
# Stack: [interface1, interface2, interface3, 3, constructor]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 2: Multiple interfaces - OK")

# TEST 3: Zero interfaces (edge case)
# ====================================
# Push interface count (0)
actions += create_push_float(0.0)
# Stack: [0]

# Create constructor object
actions += create_push_float(0.0)
actions += bytes([0x43])  # InitObject
# Stack: [0, constructor]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 3: Zero interfaces - OK")

# TEST 4: Two interfaces (different count)
# =========================================
# Create interface objects
actions += create_push_float(0.0)
actions += bytes([0x43])  # interface1
actions += create_push_float(0.0)
actions += bytes([0x43])  # interface2
# Stack: [interface1, interface2]

# Push interface count (2)
actions += create_push_float(2.0)
# Stack: [interface1, interface2, 2]

# Create constructor object
actions += create_push_float(0.0)
actions += bytes([0x43])  # InitObject
# Stack: [interface1, interface2, 2, constructor]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 4: Two interfaces - OK")

# Final success message
actions += create_trace("All ImplementsOp tests passed")

# End actions
actions += bytes([0x00])  # END

# DoAction tag (tag type 12)
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag (tag type 1)
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Comprehensive ImplementsOp test:")
print("  - Test 1: Single interface")
print("  - Test 2: Multiple interfaces (3)")
print("  - Test 3: Zero interfaces")
print("  - Test 4: Two interfaces")
print("")
print("Expected outputs:")
print("  Test 1: Single interface - OK")
print("  Test 2: Multiple interfaces - OK")
print("  Test 3: Zero interfaces - OK")
print("  Test 4: Two interfaces - OK")
print("  All ImplementsOp tests passed")
