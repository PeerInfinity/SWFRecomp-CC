#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with SetMember action
# Simpler test: InitObject with one property, then set another property
# Expected output: 42

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode sequence:
# Create object with 1 property {a: 10}
# Then use SET_MEMBER to add property b=42
# Then use GET_MEMBER to read property b
# Trace it

actions = bytearray()

# Step 1: Create object with 1 property {a: 10}
# Push value 10
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, type=1 (float)
actions += struct.pack('<f', 10.0)

# Push property name "a"
prop_a = b'a'
actions += struct.pack('<BHB', 0x96, 1 + len(prop_a), 0)  # PUSH "a"
actions += prop_a + b'\x00'

# Push count 1 (number of properties)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH 1
actions += struct.pack('<f', 1.0)

# InitObject (0x43) - creates object {a: 10}
actions += bytes([0x43])

# At this point, object is on top of stack

# Step 2: Duplicate the object so we have it for later
actions += bytes([0x4C])  # Duplicate (0x4C)

# Step 3: Set property b=42 using SET_MEMBER
# Stack now has: [obj, obj]
# We need: [obj, "b", 42]

# Push property name "b"
prop_b = b'b'
actions += struct.pack('<BHB', 0x96, 1 + len(prop_b), 0)  # PUSH "b"
actions += prop_b + b'\x00'

# Push value 42
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH 42
actions += struct.pack('<f', 42.0)

# SetMember (0x4F) - sets obj.b = 42
# Pops value (42), name ("b"), object
actions += bytes([0x4F])

# Step 4: Get property b using GET_MEMBER
# Stack now has: [obj] (the duplicate from step 2)

# Push property name "b"
actions += struct.pack('<BHB', 0x96, 1 + len(prop_b), 0)  # PUSH "b"
actions += prop_b + b'\x00'

# GetMember (0x4E) - pops name and object, pushes obj.b
actions += bytes([0x4E])

# Step 5: Trace the value
actions += bytes([0x26])

# END action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + bytes(actions)

# ShowFrame tag
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
print("Test case: obj = {a: 10}; obj.b = 42; trace(obj.b)")
print("Expected output: 42")
