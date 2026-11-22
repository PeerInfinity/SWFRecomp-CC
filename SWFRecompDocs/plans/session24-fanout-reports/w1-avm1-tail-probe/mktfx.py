import struct, sys
def s(x): return b'\x00' + x.encode() + b'\x00'
def i(x): return b'\x07' + struct.pack('<i', x)
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
GETVAR=b'\x1c'; SETVAR=b'\x1d'; GETMEM=b'\x4e'; CALLM=b'\x52'; NEWO=b'\x40'; TRACE=b'\x26'; ADD2=b'\x47'; TYPEOF=b'\x44'; EQ=b'\x49'
def path(names):
    out = push(s(names[0])) + GETVAR
    for n in names[1:]: out += push(s(n)) + GETMEM
    return out
def callm(objcode, m, args):
    return push(*reversed(args)) + push(i(len(args))) + objcode + push(s(m)) + CALLM
def tr(label, code): return push(s(label)) + code + ADD2 + TRACE
a = b''
a += push(s('a')) + push(i(0)) + push(s('TextFormat')) + NEWO + SETVAR
a += tr('proto.hOP typeof: ', path(['TextFormat','prototype','hasOwnProperty']) + TYPEOF)
a += tr('proto.__proto__==Object.prototype: ', path(['TextFormat','prototype','__proto__']) + path(['Object','prototype']) + EQ)
a += tr('proto.hOP(font): ', callm(path(['TextFormat','prototype']), 'hasOwnProperty', [s('font')]))
a += tr('proto.hOP(gte): ', callm(path(['TextFormat','prototype']), 'hasOwnProperty', [s('getTextExtent')]))
a += tr('a.hOP typeof: ', path(['a','hasOwnProperty']) + TYPEOF)
a += tr('a.hOP(font): ', callm(path(['a']), 'hasOwnProperty', [s('font')]))
a += tr('a.hOP(gte): ', callm(path(['a']), 'hasOwnProperty', [s('getTextExtent')]))
a += tr('a.hOP(zzz): ', callm(path(['a']), 'hasOwnProperty', [s('zzz')]))
a += tr('a.isPE(gte): ', callm(path(['a']), 'isPropertyEnumerable', [s('getTextExtent')]))
a += b'\x00'
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
rect = bytes([0x50, 0x00, 0x02, 0x26, 0x00, 0x00, 0x02, 0x26, 0x00])  # nbits=10 approx
body = b'\x78\x00\x05\x5f\x00\x00\x0f\xa0\x00' + struct.pack('<HH', 30 << 8, 1)
body += tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + tag(12, a) + tag(1, b'') + tag(0, b'')
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
