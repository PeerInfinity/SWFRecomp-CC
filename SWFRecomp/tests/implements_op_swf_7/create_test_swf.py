#!/usr/bin/env python3
"""
Create a minimal SWF7 file to test the ImplementsOp (0x2C) opcode.

This test creates:
1. A constructor object (representing a class)
2. An interface object (representing an interface)
3. Calls ImplementsOp to set the interface on the constructor
4. Traces a success message

Note: This is a smoke test to verify the opcode doesn't crash.
Full testing with instanceof will be added when instanceof is implemented.
"""
import struct

# Create SWF7 file (ActionScript 2.0 support)
signature = b'FWS'  # Uncompressed SWF
version = 7

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode to test ImplementsOp
actions = b''

# Create an interface object using InitObject (0x43)
# Stack: [] -> [interfaceObj]
actions += struct.pack('<BHB', 0x96, 5, 7)  # PUSH (0x96), length=5, type=7 (integer)
actions += struct.pack('<I', 0)  # Push 0 (no properties)
actions += bytes([0x43])  # InitObject (0x43)

# Create a constructor object using InitObject
# Stack: [interfaceObj] -> [interfaceObj, constructorObj]
actions += struct.pack('<BHB', 0x96, 5, 7)  # PUSH, length=5, type=7 (integer)
actions += struct.pack('<I', 0)  # Push 0 (no properties)
actions += bytes([0x43])  # InitObject

# Now we have:
# Stack: [interfaceObj, constructorObj]
# We need to set up for ImplementsOp which expects:
# Stack (top to bottom): constructorObj, interfaceCount, interface1, interface2, ...

# Duplicate constructor (since ImplementsOp will pop it)
# Stack: [interfaceObj, constructorObj] -> [interfaceObj, constructorObj, constructorObj]
actions += bytes([0x4C])  # Duplicate (0x4C)

# Swap to get: [interfaceObj, constructorObj, constructorObj] -> [constructorObj, interfaceObj, constructorObj]
# Actually, we need to reorganize the stack. Let me rethink this...

# Clear current actions and restart with proper stack order
actions = b''

# For ImplementsOp, the stack order (bottom to top) should be:
# interface1, interface2, ..., interfaceN, interfaceCount, constructorObj

# Step 1: Create interface object
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH type=1 (float)
actions += struct.pack('<f', 0.0)  # Push 0.0 (no properties)
actions += bytes([0x43])  # InitObject - creates interface object
# Stack: [interfaceObj]

# Step 2: Push interface count (1)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH type=1 (float)
actions += struct.pack('<f', 1.0)  # Push 1.0 (one interface)
# Stack: [interfaceObj, 1]

# Step 3: Create constructor object
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH type=1 (float)
actions += struct.pack('<f', 0.0)  # Push 0.0 (no properties)
actions += bytes([0x43])  # InitObject - creates constructor object
# Stack: [interfaceObj, 1, constructorObj]

# Step 4: Call ImplementsOp
# This will pop constructorObj, pop 1, then pop 1 interface
actions += bytes([0x2C])  # ImplementsOp (0x2C)
# Stack: [] (ImplementsOp returns nothing)

# Step 5: Trace success message
success_msg = b'ImplementsOp executed\x00'
actions += struct.pack('<BHB', 0x96, len(success_msg) + 1, 0)  # PUSH type=0 (string)
actions += success_msg
actions += bytes([0x26])  # Trace (0x26)

# End actions
actions += bytes([0x00])  # END (0x00)

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
print("Test: ImplementsOp sets interface list on constructor")
print("Expected output: 'ImplementsOp executed'")
