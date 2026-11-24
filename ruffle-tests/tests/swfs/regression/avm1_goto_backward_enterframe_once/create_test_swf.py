import struct, sys
sys.path.insert(0, sys.argv[0].rsplit('/',1)[0])
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
GETVAR=b'\x1c'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'; INC=b'\x50'; LESS2=b'\x48'; NOT=b'\x12'
def jif(off): return b'\x9d' + struct.pack('<Hh', 2, off)
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def doaction(a): return tag(12, a + b'\0')
def initaction(cid, a): return tag(59, struct.pack('<H', cid) + a + b'\0')
def place(depth, cid, name): return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))
SHOW = tag(1, b'')
def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)
def gotoplay(fr): return b'\x81' + struct.pack('<HH', 2, fr) + b'\x06'   # GotoFrame(idx) + Play
V = sys.argv[2]
ef = push('_root') + GETVAR + push('onEnterFrame') + deffunc(push('onEnterFrame') + TRACE) + SETMEM
f1 = doaction(push('_root') + GETVAR + push('loops', 0) + SETMEM + ef)
f2 = b''
defs = b''
if 'sprite' in V:
    defs += sprite(3, [doaction(push('inner f1') + TRACE), doaction(push('inner f2') + TRACE)])
    f2 += place(1, 3, 'mc')
if 'init' in V:
    defs += sprite(4, [])
    f2 += initaction(4, push('init action') + TRACE)
f2 += doaction(push('Frame 2') + TRACE)
loop = push('_root') + GETVAR + push('loops') + GETMEM + push(3) + LESS2 + NOT
body_ = push('_root') + GETVAR + push('loops') + push('_root') + GETVAR + push('loops') + GETMEM + INC + SETMEM + gotoplay(1)
f3 = doaction(push('Frame 3') + TRACE + (gotoplay(1) if 'uncond' in V else loop + jif(len(body_)) + body_))
frames = [f1, f2, f3, doaction(push('Frame 4') + TRACE + b'\x07')]
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + defs + b''.join(f + SHOW for f in frames) + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 12 << 8, len(frames))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
