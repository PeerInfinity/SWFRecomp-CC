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
GV=b'\x1c'; GM=b'\x4e'; SV=b'\x1d'; SM=b'\x4f'; TR=b'\x26'; CM=b'\x52'; NM=b'\x53'; IA=b'\x42'; TYPEOF=b'\x44'; ADD2=b'\x47'
def deffn(body): return b'\x9b'+struct.pack('<H',3+len(body)-len(body)+2+1)[:0]+struct.pack('<H',1+2+2)+b'\x00'+struct.pack('<H',0)+struct.pack('<H',len(body))+body
code=b''
# _root.filters = [new flash.filters.BlurFilter()]
code+=push('_root')+GV+push('filters')+push(0,'flash')+GV+push('filters')+GM+push('BlurFilter')+NM+push(1)+IA+SM
code+=push('backup')+push('_global')+GV+push('Array')+GM+SV
code+=push('_global')+GV+push('Array')+deffn(b'')+SM
for src in ['lit','filters']:
    code+=push('ch')
    if src=='lit': code+=push(2,1,2)+IA
    else: code+=push('_root')+GV+push('filters')+GM
    code+=SV
    code+=push(src+' typeof ch.toString before: ')+push('ch')+GV+push('toString')+GM+TYPEOF+ADD2+TR
    code+=push('ch')+GV+push('toString')+push('backup')+GV+push('prototype')+GM+push('toString')+GM+SM
    code+=push(src+' typeof ch.toString after: ')+push('ch')+GV+push('toString')+GM+TYPEOF+ADD2+TR
    code+=push(src+' call: ')+push(0,'ch')+GV+push('toString')+CM+ADD2+TR
    code+=push(src+' len: ')+push('ch')+GV+push('length')+GM+ADD2+TR
code+=push('_global')+GV+push('Array')+push('backup')+GV+SM
body=tag(69,struct.pack('<I',0))+tag(9,b'\xff\xff\xff')+tag(12,code+b'\0')+tag(1,b'')+tag(0,b'')
nb=13; bits='{:05b}'.format(nb)+''.join('{:013b}'.format(v) for v in (0,4000,0,3000)); bits+='0'*((8-len(bits)%8)%8)
rect=int(bits,2).to_bytes(len(bits)//8,'big'); hdr=rect+struct.pack('<HH',30<<8,1)
open(sys.argv[1],'wb').write(b'FWS'+bytes([8])+struct.pack('<I',8+len(hdr)+len(body))+hdr+body)
