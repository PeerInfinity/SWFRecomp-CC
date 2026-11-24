import sys, zlib, struct
d = open(sys.argv[1], 'rb').read()
if d[:3] == b'CWS': d = d[:8] + zlib.decompress(d[8:])
p = 8
nb = d[p] >> 3; p += (5 + nb * 4 + 7) // 8 + 4
NAMES = {0x04:'NextFrame',0x05:'PrevFrame',0x06:'Play',0x07:'Stop',0x0b:'Sub',0x0c:'Mul',0x12:'Not',0x17:'Pop',0x1c:'GetVariable',0x1d:'SetVariable',0x26:'Trace',0x3c:'DefineLocal',0x3d:'CallFunction',0x3e:'Return',0x40:'NewObject',0x47:'Add2',0x48:'Less2',0x49:'Equals2',0x4e:'GetMember',0x4f:'SetMember',0x52:'CallMethod',0x50:'Increment',0x96:'Push',0x99:'Jump',0x9d:'If',0x88:'ConstantPool',0x9b:'DefineFunction',0x8e:'DefineFunction2',0x81:'GotoFrame',0x9f:'GotoFrame2',0x8c:'GoToLabel',0x0a:'Add',0x3f:'Modulo',0x41:'DefineLocal2',0x44:'TypeOf',0x4c:'PushDuplicate',0x54:'InstanceOf',0x67:'Greater',0x66:'StrictEquals',0x96:'Push',0x87:'StoreRegister',0x94:'With',0x20:'SetTarget2',0x8b:'SetTarget',0x9a:'GetURL2',0x83:'GetURL',0x3a:'Delete',0x3b:'Delete2',0x21:'StringAdd',0x14:'StringLength'}
POOL=[[]]
def dis(code, ind='  '):
    q = 0; pool = POOL[0]
    while q < len(code):
        op = code[q]; q += 1
        if op == 0: print(ind+'End'); break
        L = 0
        if op >= 0x80: L = struct.unpack('<H', code[q:q+2])[0]; q += 2
        body = code[q:q+L]; q += L
        n = NAMES.get(op, hex(op))
        if op == 0x88:
            c = struct.unpack('<H', body[:2])[0]; pool = body[2:].split(b'\0')[:c]; POOL[0]=pool; print(ind+'ConstantPool', [x.decode('latin1') for x in pool]); continue
        if op == 0x96:
            r = []; i = 0
            while i < len(body):
                t = body[i]; i += 1
                if t == 0: s = body[i:body.index(b'\0', i)]; i += len(s)+1; r.append(repr(s.decode('latin1')))
                elif t == 1: r.append(struct.unpack('<f', body[i:i+4])[0]); i += 4
                elif t == 2: r.append('null')
                elif t == 3: r.append('undef')
                elif t == 4: r.append('r%d' % body[i]); i += 1
                elif t == 5: r.append(bool(body[i])); i += 1
                elif t == 6: r.append(struct.unpack('<d', body[i+4:i+8]+body[i:i+4])[0]); i += 8
                elif t == 7: r.append(struct.unpack('<i', body[i:i+4])[0]); i += 4
                elif t == 8: r.append('C:'+repr(pool[body[i]].decode('latin1'))); i += 1
                elif t == 9: r.append('C:'+repr(pool[struct.unpack('<H', body[i:i+2])[0]].decode('latin1'))); i += 2
            print(ind+'Push', ', '.join(map(str, r))); continue
        if op == 0x9b:
            nm = body[:body.index(b'\0')]; i = len(nm)+1; np = struct.unpack('<H', body[i:i+2])[0]; i += 2
            for _ in range(np): i = body.index(b'\0', i)+1
            sz = struct.unpack('<H', body[i:i+2])[0]
            print(ind+'DefineFunction', nm, np, 'size', sz)
            dis(code[q:q+sz], ind+'    '); q += sz; continue
        if op == 0x8e:
            nm = body[:body.index(b'\0')]; i = len(nm)+1; np, rc = struct.unpack('<HB', body[i:i+3]); i += 5
            for _ in range(np): i += 1; i = body.index(b'\0', i)+1
            sz = struct.unpack('<H', body[i:i+2])[0]
            print(ind+'DefineFunction2', nm, np, 'regs', rc, 'size', sz)
            dis(code[q:q+sz], ind+'    '); q += sz; continue
        extra = body.hex() if body else ''
        if op in (0x99, 0x9d): extra = struct.unpack('<h', body)[0]
        if op == 0x81: extra = struct.unpack('<H', body)[0]
        print(ind+n, extra)
def tags(d, p, end, ind=''):
    frame = 1
    while p < end:
        h = struct.unpack('<H', d[p:p+2])[0]; p += 2
        code, L = h >> 6, h & 63
        if L == 63: L = struct.unpack('<I', d[p:p+4])[0]; p += 4
        body = d[p:p+L]; p += L
        if code == 1: print(ind+'--- ShowFrame (end frame %d)' % frame); frame += 1
        elif code == 12: print(ind+'DoAction (frame %d)' % frame); dis(body, ind+'  ')
        elif code == 59: print(ind+'DoInitAction sprite %d (frame %d)' % (struct.unpack('<H', body[:2])[0], frame)); dis(body[2:], ind+'  ')
        elif code == 39:
            sid, fc = struct.unpack('<HH', body[:4]); print(ind+'DefineSprite %d frames %d' % (sid, fc)); tags(body, 4, len(body), ind+'    ')
        elif code == 0: print(ind+'End');
        else: print(ind+'tag %d len %d' % (code, L))
tags(d, p, len(d))
