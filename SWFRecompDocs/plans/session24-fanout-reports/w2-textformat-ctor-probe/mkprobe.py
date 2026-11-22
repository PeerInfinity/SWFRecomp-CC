import struct, sys, os
def s(x): return b'\x00' + x.encode() + b'\x00'
def i(x): return b'\x07' + struct.pack('<i', x)
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
GETVAR=b'\x1c'; GETMEM=b'\x4e'; CALLM=b'\x52'; TRACE=b'\x26'; ADD2=b'\x47'; TYPEOF=b'\x44'
def path(names):
    out = push(s(names[0])) + GETVAR
    for n in names[1:]: out += push(s(n)) + GETMEM
    return out
def callm(objcode, m, args):
    return push(*reversed(args)) + push(i(len(args))) + objcode + push(s(m)) + CALLM
def tr(label, code): return push(s(label)) + code + ADD2 + TRACE
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
def make(fn, p):
    a = tr(p[-1]+'.prototype hOP typeof: ', path(p+['prototype','hasOwnProperty']) + TYPEOF)
    a += tr(p[-1]+'.prototype.hOP(zz): ', callm(path(p+['prototype']), 'hasOwnProperty', [s('zz')]))
    a += b'\x00'
    body = b'\x78\x00\x05\x5f\x00\x00\x0f\xa0\x00' + struct.pack('<HH', 30 << 8, 1)
    body += tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + tag(12, a) + tag(1, b'') + tag(0, b'')
    open(fn, 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
out=sys.argv[1]
for p in [['TextFormat'],['XMLNode'],['XML'],['Date'],['Sound'],['Color'],['TextField','StyleSheet'],['LoadVars'],['TextField'],['MovieClip']]:
    n='probe_'+p[-1]; d=os.path.join(out,n); os.makedirs(d,exist_ok=True)
    make(os.path.join(d,'test.swf'),p)
    open(os.path.join(d,'output.txt'),'w').write(p[-1]+'.prototype hOP typeof: function\n'+p[-1]+'.prototype.hOP(zz): false\n')
    open(os.path.join(d,'test.toml'),'w').write('num_ticks = 1\n')
