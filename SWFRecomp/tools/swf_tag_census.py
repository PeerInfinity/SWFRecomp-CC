import sys, zlib, struct
data = open(sys.argv[1],'rb').read()
sig = data[:3]
if sig == b'CWS':
    body = zlib.decompress(data[8:])
elif sig == b'FWS':
    body = data[8:]
else:
    print("unsupported sig", sig); sys.exit(1)
# skip RECT
nbits = body[0] >> 3
rect_bits = 5 + 4*nbits
rect_bytes = (rect_bits + 7)//8
p = rect_bytes + 4  # + framerate(2) + framecount(2)
NAMES = {10:'DefineFont',11:'DefineText',33:'DefineText2',37:'DefineEditText',
         48:'DefineFont2',75:'DefineFont3',62:'DefineFontInfo2',13:'DefineFontInfo',
         88:'DefineFontName',73:'DefineFontAlignZones',
         6:'DefineBits',20:'DefineBitsLossless',36:'DefineBitsLossless2',
         2:'DefineShape',22:'DefineShape2',32:'DefineShape3',83:'DefineShape4',
         39:'DefineSprite',26:'PlaceObject2',70:'PlaceObject3',82:'DoABC',72:'DoABC(short)',
         76:'SymbolClass',7:'DefineButton',34:'DefineButton2'}
from collections import Counter
c = Counter()
while p < len(body):
    if p+2 > len(body): break
    th = struct.unpack_from('<H', body, p)[0]; p+=2
    code = th>>6; ln = th & 0x3F
    if ln == 0x3F:
        ln = struct.unpack_from('<I', body, p)[0]; p+=4
    c[code]+=1
    p += ln
    if code == 0: break
for code,n in sorted(c.items()):
    print(f"  tag {code:3d} x{n:5d}  {NAMES.get(code,'')}")
print("=== TEXT-RELATED ===")
for code in (10,11,13,33,37,48,62,75,88):
    if c[code]: print(f"  {NAMES.get(code):18s} x{c[code]}")
