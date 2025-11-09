#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with MB_ASCII_TO_CHAR edge case tests
# Tests various edge cases for proper handling

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4  # SWF 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Test edge cases
test_cases = [
    (-1.0, "negative"),           # Negative number
    (0.0, "zero"),                # Zero
    (127.0, "max_1byte"),         # Maximum 1-byte UTF-8
    (128.0, "min_2byte"),         # Minimum 2-byte UTF-8
    (2047.0, "max_2byte"),        # Maximum 2-byte UTF-8
    (2048.0, "min_3byte"),        # Minimum 3-byte UTF-8
    (0xD7FF, "before_surrogate"), # Just before surrogate range
    (0xD800, "surrogate_start"),  # Start of surrogate range (invalid)
    (0xDFFF, "surrogate_end"),    # End of surrogate range (invalid)
    (0xE000, "after_surrogate"),  # Just after surrogate range
    (65535.0, "max_3byte"),       # Maximum 3-byte UTF-8
    (65536.0, "min_4byte"),       # Minimum 4-byte UTF-8
    (0x10FFFF, "max_unicode"),    # Maximum valid Unicode
    (0x110000, "beyond_unicode"), # Just beyond valid Unicode
]

# Build ActionScript bytecode
actions = b''

for value, label in test_cases:
    # Push the value
    action_push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
    action_push += struct.pack('<f', value)
    actions += action_push

    # MB_ASCII_TO_CHAR operation (0x37)
    action_mb_ascii_to_char = bytes([0x37])
    actions += action_mb_ascii_to_char

    # Push label
    label_bytes = label.encode('utf-8')
    action_push_label = struct.pack('<BHB', 0x96, 1 + len(label_bytes) + 1, 0)  # type 0 = string
    action_push_label += label_bytes + b'\x00'
    actions += action_push_label

    # String add to concatenate
    action_string_add = bytes([0x21])
    actions += action_string_add

    # Trace action
    action_trace = bytes([0x26])
    actions += action_trace

# End action
action_end = bytes([0x00])
actions += action_end

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

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print(f"Edge case tests:")
for value, label in test_cases:
    print(f"  mbchr({value}) - {label}")
