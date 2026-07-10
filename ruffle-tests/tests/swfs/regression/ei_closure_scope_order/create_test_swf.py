#!/usr/bin/env python3
"""Build test.swf for ei_closure_scope_order.

BEHAVIOR LOCK, not a bug repro (nc_onstatus_closure precedent): every line is
expected to pass both before and after migrating actionEI_callInternalInterface
onto invokeFunctionValue. It pins the three EI dispatch quirks that the
migration must preserve, so that normalizing any of them later is a deliberate,
test-flipping change:

1. SCOPE ORDER (INV_LOCAL_SCOPE_UNDER_CAPTURED). EI pushes the callee's fresh
   local frame FIRST and the captured closure scopes ON TOP — the inverse of
   every other dispatcher. Parameter binds still land on the local frame
   (getCurrentLocalScope skips is_with frames), but actionGetVariable walks the
   whole chain top-down, so a captured scope SHADOWS the callee's own params.
   `shadow` is defined inside `with (w)` where `w.a` exists and the callback's
   sole parameter is also named `a`: called through EI with "ARG" it must trace
   w's value, not the argument. Direct analog of resolve_type1_args section 2.

2. FORCED is_with=1 ON CAPTURED SCOPES (INV_FORCE_CAPTURED_WITH). `writer` and
   `reader` are defined inside the type-1 function `outer`, capturing outer's
   local frame (genuinely is_with=0 — but EI forces 1 at dispatch). Two rows:

   - `ov=CHANGED`: a plain SetVariable of the captured `ov` writes THROUGH the
     forced-with frame (SetVariable assigns wherever the property already
     exists, with-frame or not), so writer's assignment persists and reader
     sees it. This row does NOT discriminate forced-vs-copied; it locks the
     write-through itself. (The dossier's §7 prediction that forced-with makes
     the write skip the captured frame was wrong — verified empirically.)
   - `lv=undefined`: writer also runs `var lv = "LEAK"` (DefineLocal), which
     binds via getCurrentLocalScope — and THAT skips is_with frames. Under
     today's forced-with the topmost non-with frame is the callee's own
     (discarded) local frame, so `lv` never reaches the captured frame and
     reader sees undefined. If EI ever copied is_with (0 for a captured local
     frame) the captured frame would be the topmost non-with frame under the
     inversion, `lv` would land there and persist, and reader would trace
     LEAK. This is the row that pins INV_FORCE_CAPTURED_WITH.

3. TYPE-1 `this` BIND (INV_BIND_THIS) — LIVE here, unlike the migrated arms
   where the standing rule declared it dead: EI pushes no g_this_stack entry
   and host-driven calls run at g_this_depth == 0, where GetVariable("this")
   falls through the early this-cell path into the scope walk and finds the
   bind on the local frame. `tagged` (thisObj = {tag:"T"}) must read
   this.tag == "T"; `untagged` (thisObj = null) must see typeof this ==
   "undefined" (the bind is written either way, with an UNDEFINED value).

DefineFunction is emitted by hand because MTASC emits DefineFunction2 for
SWF6+ and the type-1 arm cannot be reached any other way. The per-test
test_harness.c invokes the callbacks through actionEI_callInternalInterface.
"""
import struct

# ---- action helpers ----------------------------------------------------

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

def push_null():
    return struct.pack('<BH', 0x96, 1) + b'\x02'

GET_VARIABLE = bytes([0x1C])
SET_VARIABLE = bytes([0x1D])
DEFINE_LOCAL = bytes([0x3C])
CALL_FUNCTION = bytes([0x3D])
GET_MEMBER   = bytes([0x4E])
SET_MEMBER   = bytes([0x4F])
INIT_OBJECT  = bytes([0x43])
TYPE_OF      = bytes([0x44])
CALL_METHOD  = bytes([0x52])
POP          = bytes([0x17])
TRACE        = bytes([0x26])
ADD2         = bytes([0x47])
END          = bytes([0x00])

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

def with_block(body):
    """ActionWith: payload is just the UI16 body size; the body follows after."""
    return struct.pack('<BHH', 0x94, 2, len(body)) + body

def trace_concat(prefix, var_name):
    return (push_string(prefix) + push_string(var_name) + GET_VARIABLE
            + ADD2 + TRACE)

def add_callback(name, this_bytes, func_var):
    """flash.external.ExternalInterface.addCallback(name, this, func).
    CallMethod stack (bottom->top): arg3 func, arg2 this, arg1 name, num_args,
    object, method name."""
    out = b''
    out += push_string(func_var) + GET_VARIABLE   # arg3 = func (deepest)
    out += this_bytes                              # arg2 = thisObj
    out += push_string(name)                       # arg1 = name (top of args)
    out += push_float(3.0)
    out += push_string('flash') + GET_VARIABLE
    out += push_string('external') + GET_MEMBER
    out += push_string('ExternalInterface') + GET_MEMBER
    out += push_string('addCallback')
    out += CALL_METHOD + POP
    return out

actions = b''

# ---- quirk 1: captured with-scope shadows the parameter -------------------

# w = {}; w.a = "W_A"
actions += push_string('w') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += (push_string('w') + GET_VARIABLE
            + push_string('a') + push_string('W_A')
            + SET_MEMBER)

# with (w) { function shadow(a) { trace("shadow a=" + a) } }
# Defined inside the with-scope, so shadow captures [w] (is_with). The name is
# stored globally (setVariableByName skips is_with frames, finds no local).
actions += push_string('w') + GET_VARIABLE
actions += with_block(define_function('shadow', ['a'],
                                      trace_concat('shadow a=', 'a')))
actions += add_callback('shadow', push_null(), 'shadow')

# ---- quirk 2: forced is_with on a captured (non-with) local frame ---------

# function outer() {
#   var ov = "ORIG";
#   function writer() { ov = "CHANGED"; var lv = "LEAK"; trace("wr ran"); }
#   function reader() { trace("ov=" + ov); trace("lv=" + lv); }
#   addCallback("writer", null, writer); addCallback("reader", null, reader);
# }
# outer();
outer_body = b''
outer_body += push_string('ov') + push_string('ORIG') + DEFINE_LOCAL
outer_body += define_function('writer', [],
                              push_string('ov') + push_string('CHANGED') + SET_VARIABLE
                              + push_string('lv') + push_string('LEAK') + DEFINE_LOCAL
                              + push_string('wr ran') + TRACE)
outer_body += define_function('reader', [],
                              trace_concat('ov=', 'ov') + trace_concat('lv=', 'lv'))
outer_body += add_callback('writer', push_null(), 'writer')
outer_body += add_callback('reader', push_null(), 'reader')
actions += define_function('outer', [], outer_body)
actions += push_float(0.0) + push_string('outer') + CALL_FUNCTION + POP

# ---- quirk 3: the type-1 `this` bind is live -------------------------------

# function tagged() { trace("this.tag=" + this.tag); }
actions += define_function('tagged', [],
                           push_string('this.tag=')
                           + push_string('this') + GET_VARIABLE
                           + push_string('tag') + GET_MEMBER
                           + ADD2 + TRACE)
# addCallback("tagged", {tag:"T"}, tagged)
tag_obj = push_string('tag') + push_string('T') + push_float(1.0) + INIT_OBJECT
actions += add_callback('tagged', tag_obj, 'tagged')

# function untagged() { trace("typeof this=" + typeof this); }
actions += define_function('untagged', [],
                           push_string('typeof this=')
                           + push_string('this') + GET_VARIABLE + TYPE_OF
                           + ADD2 + TRACE)
actions += add_callback('untagged', push_null(), 'untagged')

actions += push_string('registered') + TRACE
actions += END

# ---- SWF wrapper ---------------------------------------------------------

do_action_tag = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

tags = do_action_tag + show_frame_tag + end_tag
tag_body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(tag_body)

with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, file_length) + tag_body)

print(f'Created test.swf ({file_length} bytes)')
