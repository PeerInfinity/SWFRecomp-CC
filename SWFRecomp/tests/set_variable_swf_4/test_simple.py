#\!/usr/bin/env python3
import struct

# Simplest possible test: just push 42 and trace it
signature = b'FWS'
version = 4

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Push 42.0
action_push = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 42.0)
# Trace
action_trace = bytes([0x26])
# End
action_end = bytes([0x00])

actions = action_push + action_trace + action_end

do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_header += struct.pack('<I', len(actions))
do_action_tag = do_action_header + actions

show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_simple.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_simple.swf - should just print 42")
