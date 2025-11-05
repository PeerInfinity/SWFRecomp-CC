#!/usr/bin/env python3
import struct

# Create a comprehensive test for TO_INTEGER with multiple test cases
# Test cases:
# 1. toInteger(12.7) = 12 (positive truncation)
# 2. toInteger(-12.7) = -12 (negative truncation)
# 3. toInteger(42) = 42 (already integer)
# 4. toInteger(0.5) = 0 (small positive)
# 5. toInteger(-0.5) = 0 (small negative)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Build actions for all test cases
actions = b''

test_cases = [
    (12.7, "12.7 → 12"),
    (-12.7, "-12.7 → -12"),
    (42.0, "42.0 → 42"),
    (0.5, "0.5 → 0"),
    (-0.5, "-0.5 → 0"),
]

for value, description in test_cases:
    # Push float value
    float_bytes = struct.pack('<f', value)
    actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
    actions += float_bytes

    # ToInteger (0x18)
    actions += bytes([0x18])

    # Trace (0x26)
    actions += bytes([0x26])

# END action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_comprehensive.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_comprehensive.swf ({len(swf_data)} bytes)")
print("\nTest cases:")
for value, description in test_cases:
    print(f"  - {description}")
print("\nExpected output:")
print("12")
print("-12")
print("42")
print("0")
print("0")
