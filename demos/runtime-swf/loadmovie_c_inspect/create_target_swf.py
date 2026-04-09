#!/usr/bin/env python3
"""
Create target.swf — a child SWF with various things for the parent to discover.

Contents:
- Timeline variables set via SetVariable
- Timeline function defined via DefineFunction
- _global contribution
- MovieClip.prototype addition
- Two frames
"""
import struct

# --- helpers ---

def push_string(s):
    data = s.encode('latin-1') + b'\x00'
    return struct.pack('<BHB', 0x96, len(data) + 1, 0) + data

def push_constant(idx):
    if idx < 256:
        return struct.pack('<BHB', 0x96, 2, 8) + bytes([idx])
    return struct.pack('<BHB', 0x96, 3, 9) + struct.pack('<H', idx)

def push_float(val):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', val)

def push_bool(val):
    return struct.pack('<BHB', 0x96, 2, 5) + bytes([1 if val else 0])

def constant_pool(strings):
    data = struct.pack('<H', len(strings))
    for s in strings:
        data += s.encode('latin-1') + b'\x00'
    return struct.pack('<BH', 0x88, len(data)) + data

def make_do_action(actions):
    data = actions + b'\x00'  # END
    if len(data) >= 63:
        return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(data)) + data
    return struct.pack('<H', (12 << 6) | len(data)) + data

SHOW_FRAME = struct.pack('<H', 1 << 6)
END_TAG = b'\x00\x00'

TRACE = b'\x26'
SET_VARIABLE = b'\x1D'
GET_VARIABLE = b'\x1C'
SET_MEMBER = b'\x4F'
GET_MEMBER = b'\x4E'
POP = b'\x17'
STOP = b'\x07'

# Constant pool indices:
# 0: "myVar"
# 1: "hello from child"
# 2: "_global"
# 3: "childGlobal"
# 4: "child was here"
# 5: "MovieClip"
# 6: "prototype"
# 7: "childMethod"
# 8: "childMethod called"
# 9: "myFunc"
# 10: "myFunc called"
# 11: "childNum"
# 12: "childBool"
# 13: "childObj"
# 14: "name"
# 15: "childObject"

CP_STRINGS = [
    "myVar", "hello from child", "_global", "childGlobal", "child was here",
    "MovieClip", "prototype", "childMethod", "childMethod called",
    "myFunc", "myFunc called", "childNum", "childBool", "childObj",
    "name", "childObject",
]

# --- Frame 1 bytecode ---
# NOTE: SetVariable pops value from top, name from second position.
#       So push NAME first (bottom), then VALUE (top).
frame1 = b''
frame1 += constant_pool(CP_STRINGS)

# myVar = "hello from child"
frame1 += push_constant(0)   # "myVar" (name) — pushed first = bottom
frame1 += push_constant(1)   # "hello from child" (value) — pushed second = top
frame1 += SET_VARIABLE

# childNum = 42
frame1 += push_constant(11)  # "childNum" (name)
frame1 += push_float(42.0)   # 42.0 (value)
frame1 += SET_VARIABLE

# childBool = true
frame1 += push_constant(12)  # "childBool" (name)
frame1 += push_bool(True)    # true (value)
frame1 += SET_VARIABLE

# childObj = {name: "childObject"}
# InitObject takes pairs from stack: name1, value1, name2, value2, ..., count
frame1 += push_constant(14)  # "name" (prop name)
frame1 += push_constant(15)  # "childObject" (prop value)
frame1 += push_float(1.0)    # 1 property
frame1 += b'\x43'            # InitObject → pushes object
# Now set: childObj = <object on stack>
# SetVariable needs name below, value on top — but value is already on top from InitObject
frame1 += push_constant(13)  # "childObj" (name)
# Oops, now name is on top and object is below — that's backward for SetVariable
# Actually, SetVariable in this runtime: value=SP(top), name=SP_SECOND_TOP(bottom)
# So the object (below) would be name and "childObj" (top) would be value — WRONG
# I need to swap: name must be deeper. Let me push name BEFORE InitObject.
# Restart this section...

# Actually, let me check: for SetVariable, which position is name vs value?
# From the recompiled code of existing tests:
#   PUSH_STR_ID(str_0, ...) → "Loading movie"
#   actionTrace()           → pops and traces top = "Loading movie"
# For SetVariable in the existing loadmovie test, there's no SetVariable.
# Let me look at the AVM1 convention as implemented in the runtime.
# actionSetVariable(): value_sp = SP (top), var_name_sp = SP_SECOND_TOP (second)
# So NAME is deeper (pushed first), VALUE is on top (pushed second).
# My push order above (name first, value second) IS correct for this runtime.

# OK so for childObj: I need name "childObj" pushed BEFORE the value.
# But the value comes from InitObject which puts it on the stack.
# Solution: push name first, then do InitObject, then SetVariable.

# Redo childObj:
# (undo the above lines by restarting frame1 from after childBool)

frame1 = b''
frame1 += constant_pool(CP_STRINGS)

# myVar = "hello from child"
frame1 += push_constant(0)   # "myVar" (name)
frame1 += push_constant(1)   # "hello from child" (value)
frame1 += SET_VARIABLE

# childNum = 42
frame1 += push_constant(11)  # "childNum" (name)
frame1 += push_float(42.0)   # 42.0 (value)
frame1 += SET_VARIABLE

# childBool = true
frame1 += push_constant(12)  # "childBool" (name)
frame1 += push_bool(True)    # true (value)
frame1 += SET_VARIABLE

# childObj = {name: "childObject"}
# Push name for SetVariable first, then build object on top
frame1 += push_constant(13)  # "childObj" (name) — will be at SP_SECOND_TOP
frame1 += push_constant(14)  # "name" (prop name for InitObject)
frame1 += push_constant(15)  # "childObject" (prop value for InitObject)
frame1 += push_float(1.0)    # 1 property count
frame1 += b'\x43'            # InitObject → pops 3, pushes object (now on top)
frame1 += SET_VARIABLE        # name="childObj"(second), value=object(top)

# _global.childGlobal = "child was here"
frame1 += push_constant(2)   # "_global"
frame1 += GET_VARIABLE        # get _global object (on stack)
frame1 += push_constant(3)   # "childGlobal" (property name)
frame1 += push_constant(4)   # "child was here" (value)
frame1 += SET_MEMBER          # _global.childGlobal = "child was here"

# MovieClip.prototype.childMethod = function() { trace("childMethod called"); }
func_body = push_constant(8) + TRACE + b'\x00'  # END
func_name = b'\x00'  # anonymous
func_def = struct.pack('<BH', 0x9B, len(func_name) + 2 + 2 + len(func_body))
func_def += func_name
func_def += struct.pack('<H', 0)  # 0 params
func_def += struct.pack('<H', len(func_body))
func_def += func_body

frame1 += push_constant(5)   # "MovieClip"
frame1 += GET_VARIABLE        # MovieClip constructor
frame1 += push_constant(6)   # "prototype"
frame1 += GET_MEMBER          # MovieClip.prototype
frame1 += push_constant(7)   # "childMethod" (property name)
frame1 += func_def            # push anonymous function (value)
frame1 += SET_MEMBER

# DefineFunction myFunc() { trace("myFunc called"); }
myfunc_body = push_constant(10) + TRACE + b'\x00'  # END
myfunc_name = b'myFunc\x00'
myfunc_def = struct.pack('<BH', 0x9B, len(myfunc_name) + 2 + 2 + len(myfunc_body))
myfunc_def += myfunc_name
myfunc_def += struct.pack('<H', 0)
myfunc_def += struct.pack('<H', len(myfunc_body))
myfunc_def += myfunc_body
frame1 += myfunc_def

frame1 += push_string("child frame 1 executed")
frame1 += TRACE
# NOTE: no stop() here — stop() in a child loaded via deferred loadMovie
# incorrectly stops the ROOT timeline (g_current_sprite_obj not set).

# --- Frame 2 ---
frame2 = b''
frame2 += push_string("child frame 2 executed")
frame2 += TRACE

# --- Assemble SWF ---
signature = b'FWS'
version = 7
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 2)

tags = b''
tags += make_do_action(frame1)
tags += SHOW_FRAME
tags += make_do_action(frame2)
tags += SHOW_FRAME
tags += END_TAG

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('target.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created target.swf ({len(swf_data)} bytes)")
