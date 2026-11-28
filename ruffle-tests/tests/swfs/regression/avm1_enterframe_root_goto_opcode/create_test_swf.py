"""avm1_enterframe_root_goto_opcode: a bare GotoFrame OPCODE (gotoAndStop(3) in
a function defined on _root) issued from _root.onEnterFrame on a stopped root.

Pins: the root playhead moves INLINE inside the handler (`after cf=3`), and
frame 3's DoAction runs right after the handler returns (`f3 cf=3`), as in
Flash Player 32 (direct-mode capture, s28 browser-attached-goto goal 4:
SWFRecomp-CC-history:SWFRecompDocs/plans/session28-fanout-reports/browser-attached-goto-fixtures/
avm1_enterframe_root_goto_opcode/flash32.trace.txt; output.txt = its first 7
lines, the 5-tick span). Before the fix, actionGotoFrame returned early under
g_inside_enterframe_dispatch (Dejagnu-era rule, fc0f8e4fd5) and printed
`after cf=1`. Fixed by s28 w3-enterframe-root-goto (rule removed)."""
import struct, sys
def tag(code, data):
    if len(data) < 63: return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data
def s(x): return x.encode() + b'\0'
def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str): b += b'\x00' + s(it)
        elif isinstance(it, int): b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b
GETVAR=b'\x1c'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'; STOP=b'\x07'
def jif(off): return b'\x9d' + struct.pack('<Hh', 2, off)
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def doaction(a): return tag(12, a + b'\0')
SHOW = tag(1, b'')
def goto(fr): return b'\x81' + struct.pack('<HH', 2, fr)
cf = push('_root') + GETVAR + push('_currentframe') + GETMEM
rest = (push('_root') + GETVAR + push('done', 1) + SETMEM + goto(2)
        + push('after cf=') + cf + ADD2 + TRACE)
body_ = (push('ef cf=') + cf + ADD2 + TRACE
         + push('_root') + GETVAR + push('done') + GETMEM + jif(len(rest)) + rest)
f1 = doaction(push('_root') + GETVAR + push('onEnterFrame') + deffunc(body_) + SETMEM
              + push('f1') + TRACE + STOP)
f2 = doaction(push('f2') + TRACE)
f3 = doaction(push('f3 cf=') + cf + ADD2 + TRACE)
frames = [f1, f2, f3]
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + b''.join(f + SHOW for f in frames) + tag(0, b''))
bits = '{:05b}'.format(13) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 12 << 8, len(frames))
open('test.swf', 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(hdr_rest) + len(body)) + hdr_rest + body)
