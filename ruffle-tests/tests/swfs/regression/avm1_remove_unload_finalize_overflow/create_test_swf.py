#!/usr/bin/env python3
"""avm1_remove_unload_finalize_overflow: 300 timeline sprites that each have an
onUnload handler are removed by 300 RemoveObject2 tags in ONE frame. Every
onUnload must fire once and every clip must be gone afterwards. s28 w1-leads
item 2: the post-drain finalize queue (tag.c queue_pending_finalize_mc,
NG_PENDING_FINALIZE_CAP = 256) silently dropped the 257th+ removal, leaving a
ghost clip that is never cleared.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

N = 300
T = trace_concat
defs = sprite(1, [doaction(STOP)])
places = b''.join(place(i + 1, 1, 's%d' % i) for i in range(N))
onun = deffunc1('', [], get('_root') + push('unloads') + get('_root.unloads') + push(1) + ADD2 + SETMEM)
r1 = push('unloads', 0) + SETVAR
for i in range(N):
    r1 += get('s%d' % i) + push('onUnload') + onun + SETMEM
r1 += T('frame 1 handlers set')
removes = b''.join(tag(28, struct.pack('<H', i + 1)) for i in range(N))
r2 = T('frame 2 unloads=', get('unloads'))
# frame 3: count survivors by name
r3 = push('alive', 0) + SETVAR
for i in range(N):
    r3 += (push('alive') + get('alive') + typeof_('s%d' % i) + push('movieclip') + EQ2
           + ADD2 + SETVAR)
r3 += T('frame 3 unloads=', get('unloads'), ' alive=', get('alive'))
r3 += T('frame 3 depth 300 instance=', callm('_root', 'getInstanceAtDepth', N, keep=True))
r3 += STOP
f1 = places + doaction(r1)
f2 = removes + doaction(r2)
f3 = doaction(r3)
open(sys.argv[1], 'wb').write(swf(8, defs, [f1, f2, f3]))
