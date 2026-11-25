#!/usr/bin/env python3
"""avm1_unbound_textfield_overflow: 70 TextFields whose `variable` names a
path inside a clip that does not exist yet ("holder.vN"). The clip and the
variables appear one frame later; every field must then pick its value up
(Ruffle: unbound_text_fields retried each frame; Flash binds lazily). s28
w1-leads item 2: our retry queue (action.c unbound_tf_push, UNBOUND_TF_MAX =
64) silently dropped the 65th+ field, which then never bound.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

N = 70
T = trace_concat
# Timeline DefineEditText (tag 37) per field: no flags, just a variable name.
# (An AS-assigned `tf.variable` is NOT retried by Ruffle's set_variable, and
# not by us either, so only timeline placements reach the retry queue.)
defs = b''
for i in range(N):
    defs += tag(37, struct.pack('<H', 2 + i) + rect(0, 2000, 0, 400) + b'\0\0' + s('holder.v%d' % i))
places = b''.join(place(i + 1, 2 + i, 't%d' % i) for i in range(N))
f1 = places + doaction(T('frame 1 fields placed'))
f2 = callm('this', 'createEmptyMovieClip', 'holder', 500)
for i in range(N):
    f2 += get('holder') + push('v%d' % i, 'val%d' % i) + SETMEM
f2 += T('frame 2 holder vars set')
f3 = push('ok', 0) + SETVAR
for i in range(N):
    f3 += push('ok') + get('ok') + get('t%d.text' % i) + push('val%d' % i) + EQ2 + ADD2 + SETVAR
f3 += T('frame 3 bound=', get('ok'))
for i in (0, 63, 64, 69):
    f3 += T('t%d.text=' % i, get('t%d.text' % i))
f3 += STOP
open(sys.argv[1], 'wb').write(swf(8, defs, [f1, doaction(f2), doaction(f3)]))
