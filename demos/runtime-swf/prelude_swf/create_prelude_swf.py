#!/usr/bin/env python3
"""
Create prelude_runtime.swf — a prelude SWF that sets up runtime APIs.

This SWF runs before the main SWF's first frame, in the same scope.
It sets up:
- _global.runtimeVersion = "1.0"
- _global.runtimeReady = true
- MovieClip.prototype.greet = function() { trace("hello from runtime"); }
- _global.Greeter = function(name) { this.name = name; }
- Greeter.prototype.sayHi = function() { trace("Hi, I'm " + this.name); }
"""
import struct

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

def push_register(reg):
    return struct.pack('<BHB', 0x96, 2, 4) + bytes([reg])

def constant_pool(strings):
    data = struct.pack('<H', len(strings))
    for s in strings:
        data += s.encode('latin-1') + b'\x00'
    return struct.pack('<BH', 0x88, len(data)) + data

def make_do_action(actions):
    data = actions + b'\x00'
    if len(data) >= 63:
        return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(data)) + data
    return struct.pack('<H', (12 << 6) | len(data)) + data

SHOW_FRAME = struct.pack('<H', 1 << 6)
END_TAG = b'\x00\x00'
TRACE = b'\x26'
GET_VARIABLE = b'\x1C'
SET_MEMBER = b'\x4F'
GET_MEMBER = b'\x4E'
POP = b'\x17'
ADD2 = b'\x47'

CP = [
    "_global",          # 0
    "runtimeVersion",   # 1
    "1.0",              # 2
    "runtimeReady",     # 3
    "MovieClip",        # 4
    "prototype",        # 5
    "greet",            # 6
    "hello from runtime",  # 7
    "Greeter",          # 8
    "name",             # 9
    "sayHi",            # 10
    "Hi, I'm ",         # 11
    "this",             # 12
    "prelude init complete",  # 13
]

frame1 = b''
frame1 += constant_pool(CP)

# _global.runtimeVersion = "1.0"
frame1 += push_constant(0)   # "_global"
frame1 += GET_VARIABLE
frame1 += push_constant(1)   # "runtimeVersion"
frame1 += push_constant(2)   # "1.0"
frame1 += SET_MEMBER

# _global.runtimeReady = true
frame1 += push_constant(0)
frame1 += GET_VARIABLE
frame1 += push_constant(3)   # "runtimeReady"
frame1 += push_bool(True)
frame1 += SET_MEMBER

# MovieClip.prototype.greet = function() { trace("hello from runtime"); }
greet_body = push_constant(7) + TRACE + b'\x00'
greet_func = struct.pack('<BH', 0x9B, 1 + 2 + 2 + len(greet_body))
greet_func += b'\x00'  # anonymous
greet_func += struct.pack('<H', 0)
greet_func += struct.pack('<H', len(greet_body))
greet_func += greet_body

frame1 += push_constant(4)   # "MovieClip"
frame1 += GET_VARIABLE
frame1 += push_constant(5)   # "prototype"
frame1 += GET_MEMBER
frame1 += push_constant(6)   # "greet"
frame1 += greet_func
frame1 += SET_MEMBER

# DefineFunction Greeter(name) { this.name = name; }
# Use DefineFunction2 with preload_this (register 1) and param "name" in register 2
greeter_body = b''
# this.name = name  →  push register1(this), push "name", push register2(name), SetMember
greeter_body += push_register(1)   # this
greeter_body += push_constant(9)   # "name"
greeter_body += push_register(2)   # name param
greeter_body += SET_MEMBER
greeter_body += b'\x00'  # END

func_name = b'Greeter\x00'
num_params = struct.pack('<H', 1)    # 1 param
register_count = struct.pack('B', 3) # registers 0-2
# flags: preloadThis=bit0, suppressThis=0, preloadArgs=0, suppressArgs=0,
#         preloadSuper=0, suppressSuper=0, preloadRoot=0, preloadParent=0, preloadGlobal=0
flags = struct.pack('<H', 0x0001)    # preloadThis only
code_size = struct.pack('<H', len(greeter_body))

# Param: register 2, name "name"
param_reg = bytes([2])
param_name = b'name\x00'

greeter_def = struct.pack('<BH', 0x8E,
    len(func_name) + len(num_params) + 1 + len(flags) + len(code_size)
    + len(param_reg) + len(param_name) + len(greeter_body))
greeter_def += func_name + num_params + register_count + flags
greeter_def += param_reg + param_name
greeter_def += code_size + greeter_body

frame1 += greeter_def  # defines Greeter as a named function

# _global.Greeter = Greeter (already defined as timeline function, but also set on _global)
# Actually, DefineFunction with a name automatically sets it as a variable.
# But we also want it on _global explicitly for cross-scope access.
frame1 += push_constant(0)   # "_global"
frame1 += GET_VARIABLE
frame1 += push_constant(8)   # "Greeter"
frame1 += push_constant(8)   # "Greeter"
frame1 += GET_VARIABLE        # get the Greeter function
frame1 += SET_MEMBER          # _global.Greeter = Greeter

# Greeter.prototype = new Object()
# InitObject with 0 props → creates empty object
frame1 += push_float(0.0)
frame1 += b'\x43'            # InitObject → pushes empty object

# Store in register 0 for reuse
frame1 += struct.pack('<BHB', 0x87, 1, 0)  # StoreRegister(0)

# Greeter.prototype = <object>
frame1 += push_constant(8)   # "Greeter"
frame1 += GET_VARIABLE        # Greeter func
frame1 += push_constant(5)   # "prototype"
frame1 += push_register(0)   # the new object
frame1 += SET_MEMBER

# Greeter.prototype.sayHi = function() { trace("Hi, I'm " + this.name); }
sayhi_body = b''
sayhi_body += push_constant(11)   # "Hi, I'm "
sayhi_body += push_register(1)    # this (preloaded)
sayhi_body += push_constant(9)    # "name"
sayhi_body += GET_MEMBER          # this.name
sayhi_body += ADD2                # "Hi, I'm " + this.name
sayhi_body += TRACE
sayhi_body += b'\x00'

# DefineFunction2 anonymous with preloadThis
sayhi_fname = b'\x00'  # anonymous
sayhi_nparams = struct.pack('<H', 0)
sayhi_regcount = struct.pack('B', 2)  # registers 0-1
sayhi_flags = struct.pack('<H', 0x0001)  # preloadThis
sayhi_codesize = struct.pack('<H', len(sayhi_body))

sayhi_def = struct.pack('<BH', 0x8E,
    len(sayhi_fname) + len(sayhi_nparams) + 1 + len(sayhi_flags)
    + len(sayhi_codesize) + len(sayhi_body))
sayhi_def += sayhi_fname + sayhi_nparams + sayhi_regcount + sayhi_flags
sayhi_def += sayhi_codesize + sayhi_body

# Greeter.prototype.sayHi = func
frame1 += push_register(0)   # Greeter.prototype (saved in register 0)
frame1 += push_constant(10)  # "sayHi"
frame1 += sayhi_def           # push function
frame1 += SET_MEMBER

# trace("prelude init complete")
frame1 += push_constant(13)
frame1 += TRACE

# Assemble SWF — same version as main SWF (7)
signature = b'FWS'
version = 7
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

tags = make_do_action(frame1) + SHOW_FRAME + END_TAG

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('prelude_runtime.swf', 'wb') as f:
    f.write(swf_data)
print(f"Created prelude_runtime.swf ({len(swf_data)} bytes)")
