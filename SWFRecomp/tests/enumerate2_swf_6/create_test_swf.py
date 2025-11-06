#\!/usr/bin/env python3
import struct

# Create a minimal SWF6 file that tests ENUMERATE2 opcode
# This creates an object {a: 1, b: 2, c: 3} and enumerates its properties

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 6  # SWF 6 (required for ENUMERATE2)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode to test ENUMERATE2
# Stack order for InitObject: value1, name1, value2, name2, value3, name3, count

actions = b''

# Push property values and names for InitObject (in correct order: value, name pairs)
# Property 1: a: 1
actions += struct.pack('<BHB', 0x96, 4 + 1, 1) + struct.pack('<f', 1.0)  # PUSH float 1.0 (value)
actions += struct.pack('<BHB', 0x96, 1 + 1, 0)  # PUSH string "a" (name)
actions += b'a\x00'

# Property 2: b: 2
actions += struct.pack('<BHB', 0x96, 4 + 1, 1) + struct.pack('<f', 2.0)  # PUSH float 2.0 (value)
actions += struct.pack('<BHB', 0x96, 1 + 1, 0)  # PUSH string "b" (name)
actions += b'b\x00'

# Property 3: c: 3
actions += struct.pack('<BHB', 0x96, 4 + 1, 1) + struct.pack('<f', 3.0)  # PUSH float 3.0 (value)
actions += struct.pack('<BHB', 0x96, 1 + 1, 0)  # PUSH string "c" (name)
actions += b'c\x00'

# Push number of properties (3)
actions += struct.pack('<BHB', 0x96, 4 + 1, 1) + struct.pack('<f', 3.0)  # PUSH float 3.0

# InitObject (0x43) - creates object from stack
actions += bytes([0x43])

# Now the object is on the stack
# Call ENUMERATE2 (0x55) to enumerate properties
actions += bytes([0x55])

# At this point, stack contains (from top to bottom):
# - property names (in reverse order: c, b, a)
# - undefined terminator

# Now we need to pop and trace each property name until we hit undefined
# We'll use a simple approach: pop 4 times (undefined + 3 properties)

# Pop and trace property 1 (should be "c")
actions += bytes([0x26])  # TRACE (pops and traces top of stack)

# Pop and trace property 2 (should be "b")
actions += bytes([0x26])  # TRACE

# Pop and trace property 3 (should be "a")
actions += bytes([0x26])  # TRACE

# Pop and trace undefined (should print "undefined" or nothing)
actions += bytes([0x26])  # TRACE

# Trace completion message
actions += struct.pack('<BHB', 0x96, len(b'Done\x00') + 1, 0)
actions += b'Done\x00'
actions += bytes([0x26])  # TRACE

# END action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

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
