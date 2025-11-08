#!/usr/bin/env python3
"""
Creates a SWF file to test the DefineLocal opcode (0x3C).

This comprehensive test covers:
1. Basic local variable definition with numeric value
2. Local variable redefinition (updating existing variable)
3. String value assignment
4. Different numeric values (including 0, negative)
5. Verification that variables retain their values

Note: Without full function infrastructure, DefineLocal behaves like SetVariable
in global scope, which is acceptable for basic testing.

Expected output:
42
100
Hello
0
-5
100
"""

import struct
import zlib

def push_string(s):
    """Helper to create a PUSH action for a string"""
    s_bytes = (s + '\x00').encode('latin1')
    return struct.pack('<BHB', 0x96, len(s_bytes) + 1, 0) + s_bytes

def push_float(f):
    """Helper to create a PUSH action for a float"""
    return struct.pack('<BHBf', 0x96, 5, 1, f)

def create_swf():
    # ===== ActionScript bytecode =====
    # Test 1: Basic definition - var x = 42; trace(x);
    actions = b''

    # DefineLocal: x = 42
    actions += push_string('x')
    actions += push_float(42.0)
    actions += bytes([0x3C])  # DefineLocal

    # GetVariable and Trace x
    actions += push_string('x')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # Test 2: Redefinition - x = 100; trace(x);
    actions += push_string('x')
    actions += push_float(100.0)
    actions += bytes([0x3C])  # DefineLocal (redefines x)

    actions += push_string('x')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # Test 3: String variable - var name = "Hello"; trace(name);
    actions += push_string('name')
    actions += push_string('Hello')
    actions += bytes([0x3C])  # DefineLocal

    actions += push_string('name')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # Test 4: Zero value - var zero = 0; trace(zero);
    actions += push_string('zero')
    actions += push_float(0.0)
    actions += bytes([0x3C])  # DefineLocal

    actions += push_string('zero')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # Test 5: Negative value - var neg = -5; trace(neg);
    actions += push_string('neg')
    actions += push_float(-5.0)
    actions += bytes([0x3C])  # DefineLocal

    actions += push_string('neg')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # Test 6: Verify x is still 100 (persistence)
    actions += push_string('x')
    actions += bytes([0x1C])  # GetVariable
    actions += bytes([0x26])  # Trace

    # End of actions
    actions += bytes([0x00])

    # ===== DoAction tag =====
    action_length = len(actions)
    tag_type = 12  # DoAction
    tag_header = ((tag_type << 6) | 0x3F).to_bytes(2, 'little')  # Long header
    tag_length = action_length.to_bytes(4, 'little')
    doaction_tag = tag_header + tag_length + actions

    # ===== SetBackgroundColor tag =====
    # RGB: white (255, 255, 255)
    bgcolor_data = bytes([0xFF, 0xFF, 0xFF])
    tag_type = 9  # SetBackgroundColor
    tag_header = ((tag_type << 6) | len(bgcolor_data)).to_bytes(2, 'little')
    bgcolor_tag = tag_header + bgcolor_data

    # ===== ShowFrame tag =====
    tag_type = 1  # ShowFrame
    showframe_tag = ((tag_type << 6) | 0).to_bytes(2, 'little')

    # ===== End tag =====
    end_tag = bytes([0x00, 0x00])

    # ===== Combine all tags =====
    tags = bgcolor_tag + doaction_tag + showframe_tag + end_tag

    # ===== SWF Header =====
    # Signature: "FWS" (uncompressed)
    signature = b'FWS'

    # Version: 5 (DefineLocal is available in SWF 5+)
    version = bytes([5])

    # File length (will be calculated)
    # Header (8 bytes) + RECT (9 bytes for 0,0,550x400) + frame rate (2) + frame count (2) + tags
    rect_nbits = 15  # Bits needed to represent 550
    rect_bits = rect_nbits.to_bytes(1, 'little')[0] >> 3  # 5 bits for nBits field

    # Create RECT manually: nBits=15, Xmin=0, Xmax=550 (in twips: 11000), Ymin=0, Ymax=400 (in twips: 8000)
    # Using 15 bits per value: nBits(5) + Xmin(15) + Xmax(15) + Ymin(15) + Ymax(15) = 65 bits = 9 bytes
    # nBits = 15 = 0b01111
    # Build bit string: 01111 | 000000000000000 | 010101011101000 | 000000000000000 | 001111101000000
    # = 0111100000000000000010101011101000000000000000000001111101000000
    # Split into bytes:
    rect = bytes([
        0b01111000,  # nBits=15, Xmin[14:10]=00000
        0b00000000,  # Xmin[9:2]=00000000
        0b00010101,  # Xmin[1:0]=00, Xmax[14:9]=010101
        0b01110100,  # Xmax[8:1]=01110100
        0b00000000,  # Xmax[0]=0, Ymin[14:8]=0000000
        0b00000000,  # Ymin[7:0]=00000000
        0b00011111,  # Ymin (padding), Ymax[14:10]=01111
        0b01000000,  # Ymax[9:2]=01000000
        0b00000000   # Ymax[1:0]=00, padding=000000
    ])

    # Frame rate: 30 fps (16.16 fixed point)
    frame_rate = struct.pack('<H', 30 << 8)

    # Frame count: 1
    frame_count = struct.pack('<H', 1)

    # Calculate file length
    header_size = 8  # Signature (3) + Version (1) + FileLength (4)
    file_length = header_size + len(rect) + len(frame_rate) + len(frame_count) + len(tags)
    file_length_bytes = struct.pack('<I', file_length)

    # ===== Assemble SWF =====
    swf = signature + version + file_length_bytes + rect + frame_rate + frame_count + tags

    # Write to file
    with open('test.swf', 'wb') as f:
        f.write(swf)

    print(f"Created test.swf ({len(swf)} bytes)")
    print(f"  - DefineLocal opcode: 0x3C")
    print(f"  - Tests: basic definition, redefinition, strings, zero, negative, persistence")
    print(f"  - Expected output: 42, 100, Hello, 0, -5, 100")

if __name__ == '__main__':
    create_swf()
