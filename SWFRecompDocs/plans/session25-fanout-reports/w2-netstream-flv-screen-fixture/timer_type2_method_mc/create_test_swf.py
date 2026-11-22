#!/usr/bin/env python3
"""Probe: fireTimerCallback method-form, TYPE-2 (DefineFunction2) callee, MOVIECLIP receiver.

s25 w2-netstream-flv-screen. setTimeout(clip, "m", 1) with m a DefineFunction2
used to hand the raw MovieClip* to the recompiled body as its ABI this_obj; the
body's preload-this tags a non-NULL this_obj as an ASObject, so every this.x
read came back undefined (FLVPlayback's VideoPlayer.doAutoResize never ran,
avm1/netstream_play_flv_screen rendered blank). Fixed in timer.c by passing the
MC receiver the CallMethod way (INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR).

Rows (SWF7):
  p:  m_pre   — DefineFunction2, PreloadThis into r1, reads r1.v / r1._name
  g:  m_get   — DefineFunction2, no preload/suppress flags: reads
               GetVariable("this").v/_name and arguments.length/[0]
               (one extra setTimeout arg "x1")
  o:  m_pre on a plain Object receiver (the ASObject arm; was already right)
Expected output is Flash semantics (this == the receiver); CONFIRM with an
oracle before landing.
"""
import struct

def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str):
            b += b'\x00' + it.encode() + b'\x00'
        elif isinstance(it, tuple) and it[0] == 'r':
            b += b'\x04' + bytes([it[1]])
        else:
            b += b'\x07' + struct.pack('<i', it)
    return struct.pack('<BH', 0x96, len(b)) + b

GETVAR=b'\x1C'; SETVAR=b'\x1D'; GETMEM=b'\x4E'; SETMEM=b'\x4F'; CALLFN=b'\x3D'
CALLMETH=b'\x52'; NEWOBJ=b'\x40'; POP=b'\x17'; TRACE=b'\x26'; ADD2=b'\x47'; END=b'\x00'

def deffn2(name, flags, nregs, body):
    p = name.encode() + b'\x00' + struct.pack('<H', 0) + bytes([nregs]) + struct.pack('<H', flags)
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x8E, len(p)) + p + body

PRELOAD_THIS = 0x0001
# m_pre: trace(pfx + r1.v); trace(pfx + r1._name)  (pfx from r1.pfx)
def tr_member(reg_or_this, member, label):
    return push(label) + reg_or_this + push(member) + GETMEM + ADD2 + TRACE
R1 = push(('r', 1))
THIS = push('this') + GETVAR
m_pre = deffn2('', PRELOAD_THIS, 2, tr_member(R1, 'v', 'p:v=') + tr_member(R1, '_name', 'p:name='))
ARGS = push('arguments') + GETVAR
m_get = deffn2('', 0, 1, tr_member(THIS, 'v', 'g:v=') + tr_member(THIS, '_name', 'g:name=')
               + tr_member(ARGS, 'length', 'g:argc=') + tr_member(ARGS, '0', 'g:arg0='))

f = b''
# _root.createEmptyMovieClip("kid", 1)
f += push(1, 'kid', 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLMETH + POP
# kid.v = "kidv"; kid.mp = m_pre; kid.mg = m_get
f += push('kid') + GETVAR + push('v', 'kidv') + SETMEM
f += push('kid') + GETVAR + push('mp') + m_pre + SETMEM
f += push('kid') + GETVAR + push('mg') + m_get + SETMEM
# o = new Object(); o.v = "objv"; o.mp = m_pre
f += push('o', 0, 'Object') + NEWOBJ + SETVAR
f += push('o') + GETVAR + push('v', 'objv') + SETMEM
f += push('o') + GETVAR + push('mp') + m_pre + SETMEM
# setTimeout(kid, "mp", 1); setTimeout(kid, "mg", 1); setTimeout(o, "mp", 1)
for recv, meth, extra in (('kid', 'mp', None), ('kid', 'mg', 'x1'), ('o', 'mp', None)):
    if extra is None:
        f += push(1, meth) + push(recv) + GETVAR + push(3, 'setTimeout') + CALLFN + POP
    else:
        f += push(extra, 1, meth) + push(recv) + GETVAR + push(4, 'setTimeout') + CALLFN + POP
f += push('start') + TRACE + END
f4 = push('done') + TRACE + END

tags = struct.pack('<HI', (12 << 6) | 0x3F, len(f)) + f
tags += struct.pack('<H', 1 << 6) * 3
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(f4)) + f4
tags += struct.pack('<H', 1 << 6) + bytes([0, 0])
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 4) + tags)
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 7, 8 + len(body)) + body)
print('ok')
