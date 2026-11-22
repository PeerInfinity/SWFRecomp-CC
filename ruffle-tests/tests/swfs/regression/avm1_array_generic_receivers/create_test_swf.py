#!/usr/bin/env python3
"""avm1_array_generic_receivers: Array.prototype.join / push on non-Array
receivers -- a plain Object, a Function and a MovieClip, each given
0:'a', 1:'b', length:2 -- both installed as an OWN method (`r.join('-')`)
and via `Array.prototype.join.call(r, '-')` (s25 lead L5).

NOTE the `str` rows: NM below is 0x53 = NewMethod, not NewObject (0x40), so
`str` is `new (1).String(...)` = undefined, NOT a String object. Those rows
therefore pin `Array.prototype.join.call(undefined, '-')` -> '' (thisArg
undefined binds _global, Ruffle function.rs `call`), and member writes on
undefined being no-ops. Kept as generated so the bytes match the oracle SWF.

Expected output: Ruffle exporter 0ddd12b6a --frames 1
(session25-fanout-reports/w0-local-oracles/array_generic_receivers.ruffle-0ddd12b6a.txt).
Generator: s24 w2-attach-order-v8 report (make_l1.py).

Usage: create_test_swf.py <out.swf>
"""
import struct,sys
def tag(code,data):
    return struct.pack('<H',(code<<6)|len(data))+data if len(data)<63 else struct.pack('<HI',(code<<6)|0x3f,len(data))+data
def s(x): return x.encode()+b'\0'
def push(*items):
    b=b''
    for it in items:
        if isinstance(it,str): b+=b'\x00'+s(it)
        elif isinstance(it,int): b+=b'\x07'+struct.pack('<i',it)
    return b'\x96'+struct.pack('<H',len(b))+b
GV=b'\x1c'; GM=b'\x4e'; SV=b'\x1d'; SM=b'\x4f'; TR=b'\x26'; CM=b'\x52'; NM=b'\x53'; IA=b'\x42'; IO=b'\x43'; ADD2=b'\x47'; POP=b'\x17'
def deffn(body): return b'\x9b'+struct.pack('<H',5)+b'\x00'+struct.pack('<H',0)+struct.pack('<H',len(body))+body
AP=lambda m: push('Array')+GV+push('prototype')+GM+push(m)+GM
code=b''
def setup(name, make):
    global code
    code+=push(name)+make+SV
    code+=push(name)+GV+push(0,'a')+SM
    code+=push(name)+GV+push(1,'b')+SM
    code+=push(name)+GV+push('length',2)+SM
    code+=push(name)+GV+push('join')+AP('join')+SM
    code+=push(name)+GV+push('push')+AP('push')+SM
recv={
 'obj': push(0)+IO,
 'fn': deffn(b''),
 'str': push('xy',1,'String')+NM,
}
# MovieClip receiver
code+=push('_root')+GV
code+=push(1,'mc',2)+push('_root')+GV+push('createEmptyMovieClip')+CM+POP
for k,v in recv.items(): setup(k,v)
# mc: set props via _root.mc
code+=push('mc')+GV+push(0,'a')+SM+push('mc')+GV+push(1,'b')+SM+push('mc')+GV+push('length',2)+SM
code+=push('mc')+GV+push('join')+AP('join')+SM+push('mc')+GV+push('push')+AP('push')+SM
for k in ['obj','fn','str','mc']:
    code+=push(k+' own join: ')+push('-',1,k)+GV+push('join')+CM+ADD2+TR
    code+=push(k+' call join: ')+push('-',k)+GV+push(2)+AP('join')+push('call')+CM+ADD2+TR
    code+=push(k+' own push: ')+push('c',1,k)+GV+push('push')+CM+ADD2+TR
    code+=push(k+' len: ')+push(k)+GV+push('length')+GM+ADD2+TR
body=tag(69,struct.pack('<I',0))+tag(9,b'\xff\xff\xff')+tag(12,code+b'\0')+tag(1,b'')+tag(0,b'')
nb=13; bits='{:05b}'.format(nb)+''.join('{:013b}'.format(v) for v in (0,4000,0,3000)); bits+='0'*((8-len(bits)%8)%8)
rect=int(bits,2).to_bytes(len(bits)//8,'big'); hdr=rect+struct.pack('<HH',30<<8,1)
open(sys.argv[1],'wb').write(b'FWS'+bytes([8])+struct.pack('<I',8+len(hdr)+len(body))+hdr+body)
