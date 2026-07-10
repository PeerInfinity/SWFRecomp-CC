#!/usr/bin/env python3
"""Probe: fireTimerCallback, type-1 callee, BOTH forms (function + method).

setTimeout/setInterval callbacks dispatch through fireTimerCallback (timer.c).
Before Stage 4 both of its type-1 arms pushed the extra args forward (correct
order) but with NO clamp to param_count and NO pad — the two arms are separate
code paths, so this repro pins both with distinct trace prefixes:

  - function-form  setTimeout(f, 1, ...)       -> "f:a=.." / "f:b=.."
  - method-form    setTimeout(o, "m", 1, ...)  -> "m:a=.." / "m:b=.."

Three shapes each against a two-param DefineFunction (0x9B, type-1):
  ("one","two")   arg-order lock (passed before the fix — deliberate lock rows)
  ("solo")        PAD: before the fix the prologue popped the empty
                  between-frames stack into `a` and misbound b="solo";
                  expected a=solo, b=undefined ("" under SWF6 concat)
  ("x1","x2","x3") CLAMP: before the fix a=x2, b=x3 with x1 stranded on the
                  AVM1 stack across the callback; expected a=x1, b=x2

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode
(setInterval is Flash 6+). One-shot setTimeout timers all become eligible on the
first frame tick (~41.7 ms >= 1 ms) and fire in creation order. Fixed by
migrating fireTimerCallback onto invokeFunctionValue in dispatch Stage 4.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D]); SET_MEMBER = bytes([0x4F])
CALL_FUNCTION = bytes([0x3D]); NEW_OBJECT = bytes([0x40]); POP = bytes([0x17])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def tc(prefix, var):
    return push_string(prefix) + push_string(var) + GET_VARIABLE + ADD2 + TRACE

def call_function(name, arg_pushes):
    # Stack (bottom->top): args[N-1..0], num_args, function name. CallFunction
    # pops name, num_args, then args[0..] (args[0] = top of the region), so
    # push the arg list in reverse.
    out = b''
    for a in reversed(arg_pushes):
        out += a
    out += push_float(float(len(arg_pushes)))
    out += push_string(name)
    return out + CALL_FUNCTION + POP  # discard the timer id

def set_timeout_func(extras):
    # setTimeout(f, 1, ...extras)
    args = [push_string('f') + GET_VARIABLE, push_float(1.0)]
    args += [push_string(x) for x in extras]
    return call_function('setTimeout', args)

def set_timeout_method(extras):
    # setTimeout(o, "m", 1, ...extras)
    args = [push_string('o') + GET_VARIABLE, push_string('m'), push_float(1.0)]
    args += [push_string(x) for x in extras]
    return call_function('setTimeout', args)

frame1 = b''
# The two type-1 callees, two declared params each, distinct prefixes.
frame1 += define_function('f', ['a', 'b'], tc('f:a=', 'a') + tc('f:b=', 'b'))
frame1 += define_function('m', ['a', 'b'], tc('m:a=', 'a') + tc('m:b=', 'b'))

# o = new Object(); o.m = m;
frame1 += push_string('o') + push_float(0.0) + push_string('Object') + NEW_OBJECT + SET_VARIABLE
frame1 += (push_string('o') + GET_VARIABLE + push_string('m')
           + push_string('m') + GET_VARIABLE + SET_MEMBER)

# Function-form: order lock, pad, clamp.
frame1 += set_timeout_func(['one', 'two'])
frame1 += set_timeout_func(['solo'])
frame1 += set_timeout_func(['x1', 'x2', 'x3'])
# Method-form (separate arm): same three shapes.
frame1 += set_timeout_method(['one', 'two'])
frame1 += set_timeout_method(['solo'])
frame1 += set_timeout_method(['x1', 'x2', 'x3'])

# Timers fire after this marker (processTimers runs after the frame tick).
frame1 += push_string('start') + TRACE + END

# Ordering marker in the last frame; also surfaces stranded-operand corruption.
frame4 = push_string('done') + TRACE + END

tags = b''
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(frame1)) + frame1
tags += struct.pack('<H', 1 << 6)      # ShowFrame 1
tags += struct.pack('<H', 1 << 6)      # ShowFrame 2 (idle)
tags += struct.pack('<H', 1 << 6)      # ShowFrame 3 (idle)
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(frame4)) + frame4
tags += struct.pack('<H', 1 << 6)      # ShowFrame 4
tags += bytes([0, 0])                  # End

body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 4) + tags)
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
