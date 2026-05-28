import zlib, struct, sys

def read_swf(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:3] == b'CWS':
        return data[:8] + zlib.decompress(data[8:])
    return data

class BitStream:
    def __init__(self, data):
        self.data = data; self.pos = 0; self.bit_pos = 0
    def read_bit(self):
        b = (self.data[self.pos] >> (7 - self.bit_pos)) & 1
        self.bit_pos += 1
        if self.bit_pos == 8: self.bit_pos = 0; self.pos += 1
        return b
    def align(self):
        if self.bit_pos: self.bit_pos = 0; self.pos += 1
    def read_byte(self): self.align(); v = self.data[self.pos]; self.pos += 1; return v
    def read_u16(self): self.align(); v = struct.unpack('<H', self.data[self.pos:self.pos+2])[0]; self.pos += 2; return v
    def read_s16(self): self.align(); v = struct.unpack('<h', self.data[self.pos:self.pos+2])[0]; self.pos += 2; return v

def read_ub(s, n):
    val = 0
    for _ in range(n): val = (val << 1) | s.read_bit()
    return val

def read_sb(s, n):
    if n == 0: return 0
    v = read_ub(s, n)
    if v >> (n-1): v -= (1 << n)
    return v

def parse_rect(s):
    s.align(); n = read_ub(s, 5)
    return tuple(read_sb(s, n) for _ in range(4))

data = read_swf(sys.argv[1])
hdr = BitStream(data[8:]); parse_rect(hdr); hdr.read_u16(); hdr.read_u16()
pos = 8 + hdr.pos

def read_tag(buf, pos):
    h = struct.unpack('<H', buf[pos:pos+2])[0]; pos += 2
    code = h >> 6; length = h & 0x3F
    if length == 0x3F: length = struct.unpack('<I', buf[pos:pos+4])[0]; pos += 4
    return code, buf[pos:pos+length], pos+length

target_char = int(sys.argv[2])
while pos < len(data):
    code, body, pos = read_tag(data, pos)
    if code == 0: break
    if code in (11, 33):
        s = BitStream(body)
        cid = s.read_u16()
        if cid != target_char: continue
        b = parse_rect(s)
        print(f"DefineText char_id={cid}, code={code} bounds={b}")
        # Skip text matrix
        s.align()
        has_scale = s.read_bit()
        if has_scale:
            n = read_ub(s, 5); read_sb(s, n); read_sb(s, n)
        has_rot = s.read_bit()
        if has_rot:
            n = read_ub(s, 5); read_sb(s, n); read_sb(s, n)
        n = read_ub(s, 5); read_sb(s, n); read_sb(s, n)
        s.align()
        gbits = s.read_byte(); abits = s.read_byte()
        # First text record flag byte
        flag = s.read_byte()
        print(f"  glyph_bits={gbits} advance_bits={abits} first_flag=0x{flag:02x} = {flag:08b}")
        print(f"  bit 3 (HasFont)    = {(flag>>3)&1}")
        print(f"  bit 2 (HasColor)   = {(flag>>2)&1}")
        print(f"  bit 1 (HasYOffset) = {(flag>>1)&1}")
        print(f"  bit 0 (HasXOffset) = {(flag)&1}")
        break
