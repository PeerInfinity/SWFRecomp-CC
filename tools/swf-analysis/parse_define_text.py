import struct, sys, os

def read_swf(path):
    with open(path, 'rb') as f:
        return f.read()

def decompress(data):
    if data[:3] == b'CWS':
        import zlib
        return b'FWS' + data[3:8] + zlib.decompress(data[8:])
    if data[:3] == b'ZWS':
        raise SystemExit('lzma not supported')
    return data

def parse_rect(data, off):
    b = data[off]
    nbits = b >> 3
    total_bits = 5 + 4 * nbits
    return (total_bits + 7) // 8

def parse(path, want_id=32):
    raw = decompress(read_swf(path))
    # Skip header: FWS(3) + version(1) + filelen(4) = 8
    off = 8
    # Skip rect
    rect_bytes = parse_rect(raw, off)
    off += rect_bytes
    # Frame rate (2) + frame count (2)
    off += 4

    while off < len(raw):
        tag_hdr = struct.unpack('<H', raw[off:off+2])[0]
        off += 2
        tag_code = tag_hdr >> 6
        tag_len = tag_hdr & 0x3F
        if tag_len == 0x3F:
            tag_len = struct.unpack('<I', raw[off:off+4])[0]
            off += 4
        body = raw[off:off+tag_len]
        off += tag_len
        if tag_code == 0:
            break

        # DefineText = 11, DefineText2 = 33
        if tag_code in (11, 33):
            cid = struct.unpack('<H', body[:2])[0]
            if cid == want_id:
                print(f"DefineText{'2' if tag_code==33 else ''} char_id={cid}")
                p = 2
                # Bounds RECT
                b = body[p]; nbits = b >> 3
                rb = (5 + 4*nbits + 7) // 8
                p += rb
                # Matrix
                # NoScale + NoTranslate: complex parse
                m = body[p:p+12]
                # For simplicity skip matrix by examining bits manually
                # Easier: simulate bit reader
                class BR:
                    def __init__(self, data, byte_off):
                        self.data = data; self.byte_off = byte_off; self.bit_off = 0
                    def read_ub(self, n):
                        v = 0
                        for _ in range(n):
                            byte = self.data[self.byte_off]
                            bit = (byte >> (7 - self.bit_off)) & 1
                            v = (v << 1) | bit
                            self.bit_off += 1
                            if self.bit_off == 8:
                                self.bit_off = 0
                                self.byte_off += 1
                        return v
                    def read_sb(self, n):
                        if n == 0: return 0
                        v = self.read_ub(n)
                        if v & (1 << (n-1)):
                            v -= 1 << n
                        return v
                    def align(self):
                        if self.bit_off > 0:
                            self.bit_off = 0; self.byte_off += 1
                br = BR(body, p)
                # matrix
                has_scale = br.read_ub(1)
                if has_scale:
                    nb = br.read_ub(5); br.read_sb(nb); br.read_sb(nb)
                has_rot = br.read_ub(1)
                if has_rot:
                    nb = br.read_ub(5); br.read_sb(nb); br.read_sb(nb)
                ntb = br.read_ub(5); br.read_sb(ntb); br.read_sb(ntb)
                br.align()
                p = br.byte_off
                # GlyphBits, AdvanceBits (1 byte each)
                glyph_bits = body[p]; p+=1
                advance_bits = body[p]; p+=1
                rec_idx = 0
                while p < len(body):
                    flags = body[p]; p+=1
                    if flags == 0: break
                    has_font = (flags >> 3) & 1
                    has_color = (flags >> 2) & 1
                    has_y = (flags >> 1) & 1
                    has_x = flags & 1
                    info = []
                    info.append(f"flags={flags:02x}")
                    if has_font:
                        fid = struct.unpack('<H', body[p:p+2])[0]; p+=2
                        info.append(f"font={fid}")
                    if has_color:
                        if tag_code == 33:
                            p += 4  # RGBA
                        else:
                            p += 3  # RGB
                    if has_x:
                        xo = struct.unpack('<h', body[p:p+2])[0]; p+=2
                        info.append(f"x_off={xo}")
                    if has_y:
                        yo = struct.unpack('<h', body[p:p+2])[0]; p+=2
                        info.append(f"y_off={yo}")
                    if has_font:
                        ht = struct.unpack('<H', body[p:p+2])[0]; p+=2
                        info.append(f"height={ht}")
                    gc = body[p]; p+=1
                    info.append(f"glyph_count={gc}")
                    # Read glyphs (glyph_bits + advance_bits per glyph, packed)
                    br = BR(body, p)
                    glyphs = []
                    for _ in range(gc):
                        gi = br.read_ub(glyph_bits)
                        adv = br.read_sb(advance_bits)
                        glyphs.append((gi, adv))
                    br.align()
                    p = br.byte_off
                    print(f"  rec[{rec_idx}] {' '.join(info)}")
                    print(f"    glyphs (idx,adv): {glyphs}")
                    rec_idx += 1
                break
    return

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print('usage: parse_define_text.py <path/to/test.swf>', file=sys.stderr)
        sys.exit(1)
    parse(sys.argv[1])
