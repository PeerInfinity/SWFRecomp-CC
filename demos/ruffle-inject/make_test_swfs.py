#!/usr/bin/env python3
"""Create minimal test SWFs for injection testing."""
import struct
import os

def make_tag(tag_type, body):
    """Build a SWF tag with proper header."""
    length = len(body)
    if length < 63:
        header = struct.pack('<H', (tag_type << 6) | length)
    else:
        header = struct.pack('<H', (tag_type << 6) | 0x3F) + struct.pack('<I', length)
    return header + body

def make_do_action(bytecode):
    """Build a DoAction tag (type 12) from raw AVM1 bytecode."""
    return make_tag(12, bytecode)

def make_push_string_trace(msg):
    """AVM1 bytecode: Push(string) → Trace → End."""
    msg_bytes = msg.encode('ascii') + b'\x00'
    push = b'\x96' + struct.pack('<H', 1 + len(msg_bytes)) + b'\x00' + msg_bytes
    return push + b'\x26' + b'\x00'  # Trace + End

def make_rect(width_twips, height_twips):
    """Build a RECT record for the SWF header."""
    # Simple case: Xmin=0, Xmax=width, Ymin=0, Ymax=height
    # Find nbits needed
    max_val = max(width_twips, height_twips)
    nbits = max_val.bit_length() + 1  # +1 for sign bit

    # Pack bits: nbits(5), Xmin(nbits), Xmax(nbits), Ymin(nbits), Ymax(nbits)
    bits = []
    for bit in range(4, -1, -1):
        bits.append((nbits >> bit) & 1)
    for val in [0, width_twips, 0, height_twips]:
        for bit in range(nbits - 1, -1, -1):
            bits.append((val >> bit) & 1)

    # Pad to byte boundary
    while len(bits) % 8 != 0:
        bits.append(0)

    result = bytearray()
    for i in range(0, len(bits), 8):
        byte = 0
        for j in range(8):
            byte = (byte << 1) | bits[i + j]
        result.append(byte)
    return bytes(result)

def make_swf(tags, width=200, height=200, fps=12, version=7):
    """Build a complete SWF file from a list of tag bytes."""
    rect = make_rect(width * 20, height * 20)
    frame_rate = struct.pack('<BB', 0, fps)  # 8.8 fixed point
    frame_count = struct.pack('<H', 1)

    body = rect + frame_rate + frame_count + b''.join(tags)
    header = b'FWS' + struct.pack('<B', version) + struct.pack('<I', 8 + len(body))
    return header + body

# --- Test SWFs ---

out_dir = os.path.dirname(os.path.abspath(__file__))
deploy_dir = os.path.join(out_dir, '..', '..', 'docs', 'injector', 'ruffle_inject')
os.makedirs(deploy_dir, exist_ok=True)

# 1. Minimal SWF with just a trace — baseline test
trace_swf = make_swf([
    make_tag(9, b'\xff\xff\xff'),  # SetBackgroundColor white
    make_do_action(make_push_string_trace("BASELINE_TRACE_WORKS")),
    make_tag(1, b''),  # ShowFrame
    make_tag(0, b''),  # End
])
for path in [os.path.join(out_dir, 'test_baseline.swf'),
             os.path.join(deploy_dir, 'test_baseline.swf')]:
    with open(path, 'wb') as f:
        f.write(trace_swf)
print(f"test_baseline.swf: {len(trace_swf)} bytes")

# 2. Minimal SWF with TWO DoAction tags — tests if Ruffle runs both
two_traces = make_swf([
    make_tag(9, b'\xff\xff\xff'),
    make_do_action(make_push_string_trace("FIRST_DOACTION")),
    make_do_action(make_push_string_trace("SECOND_DOACTION")),
    make_tag(1, b''),
    make_tag(0, b''),
])
for path in [os.path.join(out_dir, 'test_two_actions.swf'),
             os.path.join(deploy_dir, 'test_two_actions.swf')]:
    with open(path, 'wb') as f:
        f.write(two_traces)
print(f"test_two_actions.swf: {len(two_traces)} bytes")

# 3. Minimal SWF with ExternalInterface.addCallback for wireCheck
# AVM1 bytecode for:
#   push "flash.external.ExternalInterface"
#   getVariable
#   push "wireCheck", null, function() { push "ok"; return; }
#   push 3
#   callMethod "addCallback"
ei_bytecode = bytearray()
# Push "flash.external.ExternalInterface"
s = b'flash.external.ExternalInterface\x00'
ei_bytecode += b'\x96' + struct.pack('<H', 1 + len(s)) + b'\x00' + s
# GetVariable
ei_bytecode += b'\x1c'
# Push function, null, "wireCheck"
# First define the function inline using DefineFunction (0x9B)
func_body = make_push_string_trace("wireCheck called")  # just trace for now
# Actually we need to return "ok": Push "ok" → Return
func_body = b'\x96\x04\x00\x00ok\x00\x3e\x00'  # Push("ok"), Return, End
# DefineFunction: name="" (anonymous), 0 params, body
func_name = b'\x00'  # empty string = anonymous
func_params = struct.pack('<H', 0)
func_body_len = struct.pack('<H', len(func_body) - 1)  # -1 to exclude trailing 0x00
func_def = b'\x9b' + struct.pack('<H', len(func_name) + 2 + 2) + func_name + func_params + func_body_len
ei_bytecode += func_def
ei_bytecode += func_body[:-1]  # func body without trailing End (it's part of outer stream)
# Push null
ei_bytecode += b'\x96\x01\x00\x02'  # Push null
# Push "wireCheck"
s2 = b'wireCheck\x00'
ei_bytecode += b'\x96' + struct.pack('<H', 1 + len(s2)) + b'\x00' + s2
# Push 3 (arg count)
ei_bytecode += b'\x96\x05\x00\x07\x03\x00\x00\x00'  # Push int 3
# CallMethod "addCallback"
s3 = b'addCallback\x00'
ei_bytecode += b'\x96' + struct.pack('<H', 1 + len(s3)) + b'\x00' + s3
ei_bytecode += b'\x52'  # CallMethod
ei_bytecode += b'\x17'  # Pop (discard return value)
# Also trace to confirm this code ran
ei_bytecode += make_push_string_trace("EI_BRIDGE_REGISTERED")

ei_swf = make_swf([
    make_tag(9, b'\xff\xff\xff'),
    make_do_action(bytes(ei_bytecode)),
    make_tag(1, b''),
    make_tag(0, b''),
])
for path in [os.path.join(out_dir, 'test_ei.swf'),
             os.path.join(deploy_dir, 'test_ei.swf')]:
    with open(path, 'wb') as f:
        f.write(ei_swf)
print(f"test_ei.swf: {len(ei_swf)} bytes")

print("\nAll test SWFs created.")
