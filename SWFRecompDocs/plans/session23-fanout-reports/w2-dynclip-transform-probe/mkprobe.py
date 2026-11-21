import struct,sys
def s(x): return b'\x00'+x.encode()+b'\x00'
def i(x): return b'\x07'+struct.pack('<i',x)
def push(*items):
    body=b''.join(items); return b'\x96'+struct.pack('<H',len(body))+body
GETVAR=b'\x1c'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; CALLM=b'\x52'; POP=b'\x17'
def path(names):
    # push object resolved from root: GetVariable first, GetMember rest
    out=push(s(names[0]))+GETVAR
    for n in names[1:]: out+=push(s(n))+GETMEM
    return out
def call(objpath,method,args):
    out=push(*[a for a in reversed(args)])+push(i(len(args)))
    out+=path(objpath)+push(s(method))+CALLM+POP
    return out
def setp(objpath,prop,val):
    return path(objpath)+push(s(prop),val)+SETMEM
def rect(p,x,y,w,h,color):
    o=call(p,'beginFill',[i(color),i(100)])
    o+=call(p,'moveTo',[i(x),i(y)])
    for (px,py) in [(x+w,y),(x+w,y+h),(x,y+h),(x,y)]: o+=call(p,'lineTo',[i(px),i(py)])
    o+=call(p,'endFill',[])
    return o
a=b''
# Case A: depth-3 chain, parent transforms set BEFORE children exist
a+=call(['_root'],'createEmptyMovieClip',[s('a'),i(1)])
a+=setp(['a'],'_x',i(50)); a+=setp(['a'],'_y',i(20)); a+=setp(['a'],'_xscale',i(200)); a+=setp(['a'],'_alpha',i(50))
a+=call(['a'],'createEmptyMovieClip',[s('b'),i(1)])
a+=setp(['a','b'],'_x',i(10)); a+=setp(['a','b'],'_y',i(10))
a+=call(['a','b'],'createEmptyMovieClip',[s('c'),i(1)])
a+=rect(['a','b','c'],0,0,50,50,0xFF0000)
# Case B: depth-2, parent props set AFTER the child is drawn
a+=call(['_root'],'createEmptyMovieClip',[s('d'),i(2)])
a+=call(['d'],'createEmptyMovieClip',[s('e'),i(1)])
a+=rect(['d','e'],0,0,100,40,0x0000FF)
a+=setp(['d'],'_x',i(300)); a+=setp(['d'],'_y',i(150)); a+=setp(['d'],'_yscale',i(50)); a+=setp(['d'],'_alpha',i(50))
# Case C: control, untransformed parent, transformed child (old path)
a+=call(['_root'],'createEmptyMovieClip',[s('f'),i(3)])
a+=call(['f'],'createEmptyMovieClip',[s('g'),i(1)])
a+=setp(['f','g'],'_x',i(400)); a+=setp(['f','g'],'_y',i(20))
a+=rect(['f','g'],0,0,30,30,0x00FF00)
# Case D: hairline stroke on a nested child under a 25%-scaled dynamic parent
a+=call(['_root'],'createEmptyMovieClip',[s('h'),i(4)])
a+=setp(['h'],'_x',i(100)); a+=setp(['h'],'_y',i(150)); a+=setp(['h'],'_xscale',i(25)); a+=setp(['h'],'_yscale',i(25))
a+=call(['h'],'createEmptyMovieClip',[s('k'),i(1)])
a+=call(['h','k'],'lineStyle',[i(0),i(0),i(100)])
a+=call(['h','k'],'moveTo',[i(0),i(0)])
for (px,py) in [(400,0),(400,200),(0,200),(0,0)]: a+=call(['h','k'],'lineTo',[i(px),i(py)])
a+=b'\x00'
def tag(code,body):
    if len(body)<63: return struct.pack('<H',(code<<6)|len(body))+body
    return struct.pack('<HI',(code<<6)|63,len(body))+body
# RECT 0,11000,0,5000 nbits=15
bits='01111'+''.join(format(v,'015b') for v in [0,11000,0,5000])
bits+='0'*((8-len(bits)%8)%8)
rectb=bytes(int(bits[k:k+8],2) for k in range(0,len(bits),8))
body=rectb+struct.pack('<HH',30<<8,1)
body+=tag(9,b'\xff\xff\xff')+tag(12,a)+tag(1,b'')+tag(0,b'')
swf=b'FWS'+bytes([8])+struct.pack('<I',8+len(body))+body
open(sys.argv[1],'wb').write(swf)
