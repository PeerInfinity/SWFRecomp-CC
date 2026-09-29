import struct
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code<<6)|len(body)) + body
    return struct.pack('<HI', (code<<6)|63, len(body)) + body
def push_str(s): d=b'\x00'+s.encode()+b'\x00'; return b'\x96'+struct.pack('<H',len(d))+d
def push_int(i): d=b'\x07'+struct.pack('<i',i); return b'\x96'+struct.pack('<H',len(d))+d
TRACE=b'\x26'
def rect():
    # nbits=16: xmin 0, xmax 4000, ymin 0, ymax 4000
    nb=16; vals=[0,4000,0,4000]; bits=format(nb,'05b')+''.join(format(v,'0%db'%nb) for v in vals)
    bits+= '0'*((8-len(bits)%8)%8); return bytes(int(bits[i:i+8],2) for i in range(0,len(bits),8))
def clip_actions(ev_flag, actions):
    rec=struct.pack('<I',ev_flag)+struct.pack('<I',len(actions))+actions
    return struct.pack('<H',0)+struct.pack('<I',ev_flag)+rec+struct.pack('<I',0)
def build(variant):
    t=b''
    t+=tag(69, struct.pack('<I',0))
    t+=tag(9, b'\xff\xff\xff')
    # sprite 1: empty inner
    t+=tag(39, struct.pack('<HH',1,1)+tag(1,b'')+tag(0,b''))
    ef = push_str('ef ' + variant) + TRACE + b'\x00'
    po = bytes([0xA2]) + struct.pack('<HH',1,1) + b'inner\x00' + clip_actions(0x2, ef)
    t+=tag(39, struct.pack('<HH',2,1)+tag(26,po)+tag(1,b'')+tag(0,b''))
    t+=tag(56, struct.pack('<HH',1,2)+b'lib\x00')
    if variant=='attach':
        act = push_str('start')+TRACE + push_int(1)+push_str('a')+push_str('lib')+push_int(3)+push_str('_root')+b'\x1c'+push_str('attachMovie')+b'\x52'+b'\x17' + b'\x00'
        t+=tag(12, act)
    else:  # timeline placement control: place sprite 2 on root
        t+=tag(12, push_str('start')+TRACE+b'\x00')
        t+=tag(26, bytes([0x22])+struct.pack('<HH',1,2)+b'a\x00')
    t+=tag(1,b'')+tag(0,b'')
    body = rect()+struct.pack('<HH',30<<8,1)+t
    return b'FWS'+bytes([8])+struct.pack('<I',8+len(body))+body
for v in ('attach','timeline'):
    open('ef_%s.swf'%v,'wb').write(build(v))
