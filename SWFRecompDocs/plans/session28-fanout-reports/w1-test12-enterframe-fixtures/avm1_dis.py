import sys, zlib, struct
d=open(sys.argv[1],'rb').read()
if d[:3]==b'CWS': d=d[:8]+zlib.decompress(d[8:])
p=8; nb=d[p]>>3; p+= (5+4*nb+7)//8 + 4
NAMES={0x04:'NextFrame',0x05:'PrevFrame',0x06:'Play',0x07:'Stop',0x0a:'Add',0x0b:'Sub',0x0c:'Mul',0x0d:'Div',0x0e:'Equals',0x0f:'Less',0x10:'And',0x11:'Or',0x12:'Not',0x13:'StrEq',0x17:'Pop',0x18:'ToInt',0x1c:'GetVar',0x1d:'SetVar',0x20:'SetTarget2',0x21:'StrAdd',0x22:'GetProp',0x23:'SetProp',0x24:'CloneSprite',0x25:'RemoveSprite',0x26:'Trace',0x34:'GetTime',0x3a:'Delete',0x3b:'Delete2',0x3c:'DefineLocal',0x3d:'CallFunction',0x3e:'Return',0x40:'NewObject',0x41:'DefineLocal2',0x42:'InitArray',0x43:'InitObject',0x44:'TypeOf',0x46:'Enumerate',0x47:'Add2',0x48:'Less2',0x49:'Equals2',0x4c:'PushDup',0x4d:'Swap',0x4e:'GetMember',0x4f:'SetMember',0x50:'Inc',0x51:'Dec',0x52:'CallMethod',0x53:'NewMethod',0x54:'InstanceOf',0x60:'BitAnd',0x67:'Greater',0x81:'GotoFrame',0x83:'GetURL',0x87:'StoreReg',0x88:'ConstantPool',0x8b:'SetTarget',0x8c:'GotoLabel',0x94:'With',0x96:'Push',0x99:'Jump',0x9d:'If',0x9e:'Call',0x9f:'GotoFrame2',0x9b:'DefineFunction',0x8e:'DefineFunction2'}
def dis(b,ind='  '):
    i=0; pool=[]; out=[]
    while i<len(b):
        op=b[i]; i+=1
        if op==0: out.append(ind+'End'); break
        ln=0; data=b''
        if op>=0x80: ln=struct.unpack('<H',b[i:i+2])[0]; i+=2; data=b[i:i+ln]; i+=ln
        n=NAMES.get(op,hex(op)); s=n
        if op==0x88:
            c=struct.unpack('<H',data[:2])[0]; pool=data[2:].split(b'\0')[:c]; s+=' (%d)'%c; pool=[x.decode('latin1') for x in pool]
        elif op==0x96:
            j=0; vals=[]
            while j<len(data):
                t=data[j]; j+=1
                if t==0: e=data.index(b'\0',j); vals.append(repr(data[j:e].decode('latin1'))); j=e+1
                elif t==1: vals.append(str(struct.unpack('<f',data[j:j+4])[0])); j+=4
                elif t==2: vals.append('null')
                elif t==3: vals.append('undef')
                elif t==4: vals.append('r%d'%data[j]); j+=1
                elif t==5: vals.append(str(bool(data[j]))); j+=1
                elif t==6: v=data[j:j+8]; vals.append(str(struct.unpack('<d',v[4:]+v[:4])[0])); j+=8
                elif t==7: vals.append(str(struct.unpack('<i',data[j:j+4])[0])); j+=4
                elif t==8: vals.append(repr(pool[data[j]])); j+=1
                elif t==9: vals.append(repr(pool[struct.unpack('<H',data[j:j+2])[0]])); j+=2
            s+=' '+', '.join(vals)
        elif op in (0x9b,0x8e):
            e=data.index(b'\0'); s+=' '+data[:e].decode()+' (body follows)'
        elif op in (0x99,0x9d): s+=' %d'%struct.unpack('<h',data)[0]
        elif op==0x81: s+=' %d'%struct.unpack('<H',data)[0]
        elif op==0x8c or op==0x8b: s+=' '+data.rstrip(b'\0').decode()
        elif op==0x9f: s+=' '+data.hex()
        out.append(ind+s)
    return '\n'.join(out)
def tags(b,p,end,ind=''):
    fr=0
    while p<end:
        h=struct.unpack('<H',b[p:p+2])[0]; p+=2; t=h>>6; l=h&63
        if l==63: l=struct.unpack('<I',b[p:p+4])[0]; p+=4
        body=b[p:p+l]; p+=l
        if t==1: print(ind+'--- ShowFrame (end frame %d)'%fr); fr+=1
        elif t==12: print(ind+'DoAction:'); print(dis(body,ind+'  '))
        elif t==59: print(ind+'DoInitAction sprite %d:'%struct.unpack('<H',body[:2])); print(dis(body[2:],ind+'  '))
        elif t==39:
            sid,fc=struct.unpack('<HH',body[:4]); print(ind+'DefineSprite %d frames %d'%(sid,fc)); tags(body,4,len(body),ind+'    ')
        elif t==26:
            fl=body[0]; dep=struct.unpack('<H',body[1:3])[0]; q=3; s='PlaceObject2 depth %d flags %x'%(dep,fl)
            if fl&2: s+=' char %d'%struct.unpack('<H',body[q:q+2]); q+=2
            if fl&1: s+=' MOVE'
            if fl&0x20: e=body.index(b'\0',q+0); 
            if fl&0x80: s+=' HAS_CLIPACTIONS'
            print(ind+s)
            if fl&0x20:
                # find name
                pass
        elif t==28: print(ind+'RemoveObject2 depth %d'%struct.unpack('<H',body[:2]))
        elif t==0: print(ind+'End'); 
        else: print(ind+'tag %d len %d'%(t,l))
    return p
tags(d,p,len(d))
