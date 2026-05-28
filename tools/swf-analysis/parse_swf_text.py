import zlib, struct, sys, io

def read_swf(path):
    with open(path, 'rb') as f:
        data = f.read()
    sig = data[:3]
    if sig == b'CWS':
        body = zlib.decompress(data[8:])
        return data[:8] + body
    return data

def read_ub(stream, nbits):
    val = 0
    for _ in range(nbits):
        val = (val << 1) | stream.read_bit()
    return val

def read_sb(stream, nbits):
    if nbits == 0: return 0
    val = read_ub(stream, nbits)
    if val >> (nbits-1):
        val -= (1 << nbits)
    return val

class BitStream:
    def __init__(self, data):
        self.data = data
        self.pos = 0
        self.bit_pos = 0
    def read_bit(self):
        if self.pos >= len(self.data): return 0
        b = (self.data[self.pos] >> (7 - self.bit_pos)) & 1
        self.bit_pos += 1
        if self.bit_pos == 8: self.bit_pos = 0; self.pos += 1
        return b
    def align(self):
        if self.bit_pos != 0: self.bit_pos = 0; self.pos += 1
    def read_byte(self): self.align(); v = self.data[self.pos]; self.pos += 1; return v
    def read_u16(self): self.align(); v = struct.unpack('<H', self.data[self.pos:self.pos+2])[0]; self.pos += 2; return v
    def read_s16(self): self.align(); v = struct.unpack('<h', self.data[self.pos:self.pos+2])[0]; self.pos += 2; return v
    def read_u32(self): self.align(); v = struct.unpack('<I', self.data[self.pos:self.pos+4])[0]; self.pos += 4; return v

def parse_rect(stream):
    stream.align()
    nbits = read_ub(stream, 5)
    xmin = read_sb(stream, nbits)
    xmax = read_sb(stream, nbits)
    ymin = read_sb(stream, nbits)
    ymax = read_sb(stream, nbits)
    return (xmin, xmax, ymin, ymax)

def parse_matrix(stream):
    stream.align()
    has_scale = stream.read_bit()
    sx = sy = 0x10000
    if has_scale:
        nbits = read_ub(stream, 5)
        sx = read_sb(stream, nbits)
        sy = read_sb(stream, nbits)
    has_rotate = stream.read_bit()
    rs0 = rs1 = 0
    if has_rotate:
        nbits = read_ub(stream, 5)
        rs0 = read_sb(stream, nbits)
        rs1 = read_sb(stream, nbits)
    nbits = read_ub(stream, 5)
    tx = read_sb(stream, nbits)
    ty = read_sb(stream, nbits)
    return (sx, sy, rs0, rs1, tx, ty)

data = read_swf(sys.argv[1])
# Header: 8 + FrameSize + FrameRate(2) + FrameCount(2)
hdr = BitStream(data[8:])
parse_rect(hdr)  # FrameSize
hdr.read_u16()  # FrameRate (actually s16)
hdr.read_u16()  # FrameCount

# Tag stream starts after header. data[8:] is body. Find current pos.
body_pos = 8 + hdr.pos

def read_tag(buf, pos):
    hdr = struct.unpack('<H', buf[pos:pos+2])[0]; pos += 2
    tag_code = hdr >> 6
    length = hdr & 0x3F
    if length == 0x3F:
        length = struct.unpack('<I', buf[pos:pos+4])[0]; pos += 4
    body = buf[pos:pos+length]
    return tag_code, body, pos+length

pos = body_pos
target_char = int(sys.argv[2])
while pos < len(data):
    tag_code, body, pos = read_tag(data, pos)
    if tag_code == 0: break  # End
    if tag_code in (11, 33):  # DefineText / DefineText2
        s = BitStream(body)
        char_id = s.read_u16()
        if char_id != target_char: continue
        bounds = parse_rect(s)
        matrix = parse_matrix(s)
        print(f"DefineText char_id={char_id} bounds={bounds} matrix={matrix}")
        s.align()
        glyph_bits = s.read_byte()
        advance_bits = s.read_byte()
        print(f"  glyph_bits={glyph_bits} advance_bits={advance_bits}")
        # Text records
        rec_idx = 0
        while True:
            s.align()
            flags = s.read_byte()
            if flags == 0: break
            has_font = flags & 0x08
            has_color = flags & 0x04
            has_y = flags & 0x02
            has_x = flags & 0x01
            font_id = None
            color = None
            x_off = None
            y_off = None
            text_height = None
            if has_font: font_id = s.read_u16()
            if has_color:
                # Assume DefineText2 = RGBA, DefineText = RGB
                if tag_code == 33:
                    color = (s.read_byte(), s.read_byte(), s.read_byte(), s.read_byte())
                else:
                    color = (s.read_byte(), s.read_byte(), s.read_byte())
            if has_x: x_off = s.read_s16()
            if has_y: y_off = s.read_s16()
            if has_font: text_height = s.read_u16()
            glyph_count = s.read_byte()
            print(f"  rec[{rec_idx}] font={font_id} color={color} x_off={x_off} y_off={y_off} height={text_height} glyph_count={glyph_count}")
            # Skip glyph data (bit-packed)
            total_bits = glyph_count * (glyph_bits + advance_bits)
            total_bytes = (total_bits + 7) // 8
            # Read individual glyphs to advance the stream correctly
            for _ in range(glyph_count):
                read_ub(s, glyph_bits)
                read_sb(s, advance_bits)
            rec_idx += 1
        break
