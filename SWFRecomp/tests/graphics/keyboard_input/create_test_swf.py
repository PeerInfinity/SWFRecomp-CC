#!/usr/bin/env python3
"""Generate test.swf for keyboard input demo.

A green square on a dark background. Arrow keys move it.
Tests: Key.isDown(), onEnterFrame, GetMember/SetMember on _x/_y.

SWF version 6, 320x320 @ 24fps.
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _build_matrix_bits,
)


# --- AVM1 bytecode helpers ---

def push_string(s):
    """ActionPush a string value."""
    encoded = s.encode('ascii') + b'\x00'
    return struct.pack('<BHB', 0x96, 1 + len(encoded), 0x00) + encoded

def push_int(n):
    """ActionPush an integer (type 7 = UI32)."""
    return struct.pack('<BHB', 0x96, 5, 0x07) + struct.pack('<I', n)

def push_float64(f):
    """ActionPush a double (type 6 = F64).

    SWF stores doubles with the two 32-bit halves swapped:
    bytes [4:8] come first, then bytes [0:4].
    """
    le = struct.pack('<d', f)
    swapped = le[4:8] + le[0:4]
    return struct.pack('<BHB', 0x96, 9, 0x06) + swapped

# Simple action opcodes (no data)
ACTION_GET_VARIABLE = bytes([0x1C])
ACTION_GET_MEMBER = bytes([0x4E])
ACTION_SET_MEMBER = bytes([0x4F])
ACTION_CALL_METHOD = bytes([0x52])
ACTION_ADD2 = bytes([0x47])
ACTION_NOT = bytes([0x12])
ACTION_STOP = bytes([0x07])
ACTION_END = bytes([0x00])

def action_if(offset):
    """ActionIf: branch by signed 16-bit offset if top of stack is true."""
    return struct.pack('<BHh', 0x9D, 2, offset)

def action_define_function2(name, num_params, register_count, flags,
                            params, body_bytes):
    """ActionDefineFunction2 (0x8E).

    params: list of (register, name) tuples
    flags: preload flags (UI16)
    """
    name_bytes = name.encode('ascii') + b'\x00'
    header = bytearray()
    header += name_bytes
    header += struct.pack('<H', num_params)
    header.append(register_count)
    header += struct.pack('<H', flags)
    for reg, pname in params:
        header.append(reg)
        header += pname.encode('ascii') + b'\x00'
    header += struct.pack('<H', len(body_bytes))  # codeSize

    return struct.pack('<BH', 0x8E, len(header)) + bytes(header) + body_bytes


def build_key_check_and_move(prop_name, key_code, delta):
    """Build bytecode for: if (Key.isDown(keyCode)) { square[prop] += delta; }

    SetMember expects stack (bottom to top): object, name, value.
    So we push object and name first, then compute the new value on top.
    """
    body = bytearray()
    # Key.isDown(keyCode) → boolean on stack
    # AVM1 CallMethod stack (bottom to top): args, numArgs, object, methodName
    body += push_int(key_code)          # arg1
    body += push_int(1)                 # numArgs
    body += push_string("Key")
    body += ACTION_GET_VARIABLE         # object
    body += push_string("isDown")       # methodName
    body += ACTION_CALL_METHOD

    # Build the "then" block to measure its size for the branch offset
    then_block = bytearray()
    # Push object and prop name first (they stay on stack under the value)
    then_block += push_string("square")
    then_block += ACTION_GET_VARIABLE       # stack: [obj]
    then_block += push_string(prop_name)    # stack: [obj, name]
    # Compute new value: square[prop] + delta
    then_block += push_string("square")
    then_block += ACTION_GET_VARIABLE
    then_block += push_string(prop_name)
    then_block += ACTION_GET_MEMBER         # stack: [obj, name, current_val]
    then_block += push_float64(delta)       # stack: [obj, name, current_val, delta]
    then_block += ACTION_ADD2               # stack: [obj, name, new_val]
    then_block += ACTION_SET_MEMBER         # pops all three

    # NOT + If: skip then_block when key is NOT down
    body += ACTION_NOT
    body += action_if(len(then_block))
    body += then_block

    return bytes(body)


def build_do_action_body():
    """Build the DoAction bytecode for frame 1.

    ActionScript equivalent:
      this.onEnterFrame = function() {
          if (Key.isDown(37)) { square._x -= 5; }  // LEFT
          if (Key.isDown(39)) { square._x += 5; }  // RIGHT
          if (Key.isDown(38)) { square._y -= 5; }  // UP
          if (Key.isDown(40)) { square._y += 5; }  // DOWN
      };
      stop();
    """
    # Build the function body
    func_body = bytearray()
    func_body += build_key_check_and_move("_x", 37, -5.0)  # LEFT
    func_body += build_key_check_and_move("_x", 39, 5.0)   # RIGHT
    func_body += build_key_check_and_move("_y", 38, -5.0)  # UP
    func_body += build_key_check_and_move("_y", 40, 5.0)   # DOWN
    func_body += ACTION_END

    # Build the full DoAction:
    #   this.onEnterFrame = function() { ... };
    #   stop();
    actions = bytearray()

    # SetMember needs stack: obj, name, value
    actions += push_string("this")
    actions += ACTION_GET_VARIABLE
    actions += push_string("onEnterFrame")

    # DefineFunction2 pushes the function value on stack
    actions += action_define_function2(
        name="",            # anonymous
        num_params=0,
        register_count=1,
        flags=0x0000,       # no preloads needed
        params=[],
        body_bytes=bytes(func_body),
    )

    actions += ACTION_SET_MEMBER
    actions += ACTION_STOP
    actions += ACTION_END

    return bytes(actions)


def build_place_object2_with_name(char_id, depth, trans_x, trans_y, name):
    """Build raw PlaceObject2 (tag 26) body with an instance name."""
    # Flags: HasCharacter(0x02) | HasMatrix(0x04) | HasName(0x20)
    flags = 0x02 | 0x04 | 0x20

    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += _build_matrix_bits({"transX": trans_x, "transY": trans_y})
    body += name.encode('ascii') + b'\x00'

    return bytes(body)


# --- Build the SWF ---

swf = SWFMLBuilder(width=320, height=320, fps=24, version=6)
swf.set_background(32, 32, 48)  # dark blue-gray background

# Define a green square shape (object 1), 30x30 pixels = 600x600 twips
SIZE = 600  # 30 pixels in twips
shape = swf.define_shape(object_id=1, bounds=(0, SIZE, 0, SIZE))
shape.add_fill(SolidFill(0, 200, 80))  # green
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(SIZE, 0),
    LineTo(0, SIZE),
    LineTo(-SIZE, 0),
    LineTo(0, -SIZE),
])

# Define sprite (object 2) wrapping the shape - gives it _x/_y properties
sprite = swf.define_sprite(object_id=2, frame_count=1)
sprite.place_object(object_id=1, depth=1)
sprite.show_frame()

# Place the sprite with instance name "square" at center of stage
# 320/2 = 160 pixels, minus 15 (half of 30px square) = 145 pixels = 2900 twips
CENTER = 2900
place_body = build_place_object2_with_name(
    char_id=2, depth=1,
    trans_x=CENTER, trans_y=CENTER,
    name="square",
)
swf.add_raw_tag(0x1A, place_body)  # PlaceObject2 = tag 26 = 0x1A

# DoAction on frame 1: set up onEnterFrame handler + stop
do_action_bytes = build_do_action_body()
swf.add_raw_tag(0x0C, do_action_bytes)  # DoAction = tag 12 = 0x0C

swf.show_frame()

# Save
output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
