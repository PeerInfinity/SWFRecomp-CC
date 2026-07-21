#!/usr/bin/env python3
"""Hex-patch one AVM2 method body to the undefined opcode 0xf4.

Usage: create_test_swf.py <clean.swf> <out.swf>

`build_swf.sh` compiles Test.as with mxmlc, then runs this to corrupt exactly
one method body — the one that traces the marker "DECOY SHOULD NEVER RUN"
(decoyBody). Its first bytecode op is overwritten with 0xf4, the undefined AVM2
opcode that the `betz` obfuscator hides in Elephant Quest's dead body 1309
(real AVM2 debug ops stop at 0xf3).

We OVERWRITE one existing opcode byte rather than INSERT a byte: code_length,
the DoABC tag length and the SWF file length all stay unchanged, so the byte
stream never desyncs — and the verifier's decode of 0xf4 fails identically
either way (unknown opcode -> that body only is quarantined). The input SWF is
decompressed (mxmlc emits CWS/zlib) and re-emitted as uncompressed FWS, which
the recompiler reads directly.

The body is located by its traced marker string, NOT by a method/pool index, so
edits to Test.as that shuffle the constant pool don't break the patch.
"""
import sys
import struct
import zlib

MARKER = b"DECOY SHOULD NEVER RUN"
UNDEFINED_OPCODE = 0xF4
TAG_DO_ABC = 82

# ---- SWF container -------------------------------------------------------

def read_swf(path):
    raw = open(path, "rb").read()
    sig = raw[:3]
    version = raw[3]
    # bytes 4..8 = file length (uncompressed)
    body = raw[8:]
    if sig == b"CWS":
        body = zlib.decompress(body)
    elif sig == b"FWS":
        pass
    else:
        raise SystemExit("unsupported SWF signature %r (need FWS/CWS)" % sig)
    return version, body


def rect_size_bits(body, bitpos):
    # RECT: UB[5] nbits, then 4 * UB[nbits]. Return total bit length.
    nbits = 0
    for i in range(5):
        nbits = (nbits << 1) | ((body[bitpos >> 3] >> (7 - (bitpos & 7))) & 1)
        bitpos += 1
    return 5 + 4 * nbits


def find_do_abc(body):
    """Return (abc_offset, abc_bytes) of the first DoABC tag's ABC payload."""
    # header: RECT, frame rate u16, frame count u16, then tags
    bits = rect_size_bits(body, 0)
    pos = (bits + 7) // 8  # byte-align past RECT
    pos += 2 + 2           # frame rate + frame count
    while pos < len(body):
        tag_hdr = struct.unpack_from("<H", body, pos)[0]
        pos += 2
        code = tag_hdr >> 6
        length = tag_hdr & 0x3F
        if length == 0x3F:
            length = struct.unpack_from("<I", body, pos)[0]
            pos += 4
        tag_body = pos
        if code == TAG_DO_ABC:
            # DoABC: u32 flags, null-terminated name, then ABC
            p = tag_body + 4
            while body[p] != 0:
                p += 1
            p += 1  # NUL
            return p, body[p:tag_body + length]
        pos += length
    raise SystemExit("no DoABC tag found")


# ---- ABC parse (mirrors SWFRecomp/src/abc/abc_parser.cpp) ----------------

class R:
    def __init__(self, data):
        self.d = data
        self.p = 0

    def u8(self):
        v = self.d[self.p]
        self.p += 1
        return v

    def u16(self):
        v = struct.unpack_from("<H", self.d, self.p)[0]
        self.p += 2
        return v

    def u30(self):
        val = 0
        for i in range(0, 35, 7):
            b = self.u8()
            val |= (b & 0x7F) << i
            if not (b & 0x80):
                break
        return val & 0xFFFFFFFF

    def s24(self):
        b0, b1, b2 = self.u8(), self.u8(), self.u8()
        v = b0 | (b1 << 8) | (b2 << 16)
        if v & 0x800000:
            v -= 1 << 24
        return v

    def d64(self):
        v = struct.unpack_from("<d", self.d, self.p)[0]
        self.p += 8
        return v

    def string(self):
        n = self.u30()
        s = self.d[self.p:self.p + n]
        self.p += n
        return s


def parse_pool(r):
    strings = [b""]
    # ints
    n = r.u30()
    for _ in range(1, n):
        r.u30()  # s32 same encoding
    n = r.u30()
    for _ in range(1, n):
        r.u30()
    n = r.u30()
    for _ in range(1, n):
        r.d64()
    n = r.u30()
    for _ in range(1, n):
        strings.append(r.string())
    # namespaces
    n = r.u30()
    for _ in range(1, n):
        r.u8(); r.u30()
    # ns sets
    n = r.u30()
    for _ in range(1, n):
        cnt = r.u30()
        for _ in range(cnt):
            r.u30()
    # multinames
    n = r.u30()
    for _ in range(1, n):
        kind = r.u8()
        if kind in (0x07, 0x0d):
            r.u30(); r.u30()
        elif kind in (0x0f, 0x10):
            r.u30()
        elif kind in (0x11, 0x12):
            pass
        elif kind in (0x09, 0x0e):
            r.u30(); r.u30()
        elif kind in (0x1b, 0x1c):
            r.u30()
        elif kind == 0x1d:
            r.u30()
            cnt = r.u30()
            for _ in range(cnt):
                r.u30()
        else:
            raise SystemExit("bad multiname kind %d" % kind)
    return strings


def parse_default_value(r):
    r.u30()  # index
    r.u8()   # kind (always present here)


def parse_method(r):
    num_params = r.u30()
    r.u30()  # return type
    for _ in range(num_params):
        r.u30()
    r.u30()  # name
    flags = r.u8()
    if flags & 0x08:  # HAS_OPTIONAL
        num_opt = r.u30()
        for _ in range(num_opt):
            parse_default_value(r)
    if flags & 0x80:  # HAS_PARAM_NAMES
        for _ in range(num_params):
            r.u30()


def parse_metadata(r):
    r.u30()  # name
    n = r.u30()
    for _ in range(n * 2):
        r.u30()


def parse_traits(r):
    n = r.u30()
    for _ in range(n):
        r.u30()  # name
        flags = r.u8()
        kind = flags & 0x0F
        if kind in (0, 6):       # Slot / Const
            r.u30(); r.u30()
            idx = r.u30()
            if idx != 0:
                r.u8()
        elif kind in (1, 2, 3, 4, 5):  # Method/Getter/Setter/Class/Function
            r.u30(); r.u30()
        else:
            raise SystemExit("bad trait kind %d" % kind)
        if flags & 0x40:  # ATTR_Metadata
            m = r.u30()
            for _ in range(m):
                r.u30()


def parse_instance(r):
    r.u30(); r.u30()  # name, super
    flags = r.u8()
    if flags & 0x08:
        r.u30()  # protected ns
    ni = r.u30()
    for _ in range(ni):
        r.u30()
    r.u30()  # iinit
    parse_traits(r)


def find_decoy_body_code_off(abc, strings_marker_idx):
    """Return (abs code offset within abc, code_len, first_byte) for the body
    whose code contains PushString(marker)."""
    r = R(abc)
    r.u16(); r.u16()  # minor, major
    # re-parse pool but we already have strings; just skip it identically
    # (parse_pool consumed pool during string collection in caller). Instead
    # caller passes us a fresh reader positioned after the pool. See main().
    raise RuntimeError("unused")


# Operand shapes for linear body decode (byte -> list of ops to skip).
def skip_op(r):
    """Read one op at r.p; return (opcode, pushstring_index_or_None)."""
    op = r.u8()
    ps_idx = None
    # no-operand ops: everything not listed below
    one_u30 = {
        0x04, 0x05, 0x06, 0x40, 0x41, 0x42, 0x53, 0x55, 0x56, 0x58, 0x59,
        0x5a, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
        0x67, 0x68, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x80, 0x83, 0x86,
        0x87, 0x92, 0x94, 0xb2, 0xc2, 0xc3, 0xd4, 0x08, 0x09, 0x2d, 0x2e,
        0x2f, 0x31, 0x32, 0xf0, 0xf1,
    }
    two_u30 = {0x43, 0x44, 0x45, 0x46, 0x4c, 0x4e, 0x4f, 0x54, 0x1f}
    s24_branch = {0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14,
                  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a}
    if op == 0x2c:  # PushString
        ps_idx = r.u30()
    elif op in one_u30:
        r.u30()
    elif op in two_u30:
        r.u30(); r.u30()
    elif op in s24_branch:
        r.s24()
    elif op == 0x1b:  # LookupSwitch
        r.s24()
        n = r.u30() + 1
        for _ in range(n):
            r.s24()
    elif op == 0x24:  # PushByte
        r.u8()
    elif op == 0x25:  # PushShort
        r.u30()
    elif op == 0x65:  # GetScopeObject u8 (already in one_u30? no) -> handled
        r.u8()
    elif op == 0xef:  # Debug
        r.u8(); r.u30(); r.u8(); r.u30()
    # else: zero-operand op
    return op, ps_idx


def main():
    if len(sys.argv) != 3:
        raise SystemExit(__doc__)
    in_path, out_path = sys.argv[1], sys.argv[2]
    version, body = read_swf(in_path)
    abc_off, abc = find_do_abc(body)

    # Parse the ABC up to the method_bodies section, tracking string pool.
    r = R(abc)
    r.u16(); r.u16()
    strings = parse_pool(r)
    try:
        marker_idx = strings.index(MARKER)
    except ValueError:
        raise SystemExit("marker string %r not found in ABC pool" % MARKER)

    n = r.u30()  # methods
    for _ in range(n):
        parse_method(r)
    n = r.u30()  # metadata
    for _ in range(n):
        parse_metadata(r)
    n = r.u30()  # instances + classes share count
    for _ in range(n):
        parse_instance(r)
    for _ in range(n):
        r.u30()  # class cinit
        parse_traits(r)
    n = r.u30()  # scripts
    for _ in range(n):
        r.u30()
        parse_traits(r)

    nbodies = r.u30()
    target_code_abs = None
    target_len = None
    for _ in range(nbodies):
        r.u30()  # method
        r.u30()  # max_stack
        r.u30()  # num_locals
        r.u30()  # init_scope
        r.u30()  # max_scope
        code_len = r.u30()
        code_start = r.p
        code = abc[code_start:code_start + code_len]
        # linear-decode to find PushString(marker)
        cr = R(code)
        hit = False
        try:
            while cr.p < code_len:
                _, ps = skip_op(cr)
                if ps == marker_idx:
                    hit = True
        except (IndexError, struct.error):
            hit = False
        r.p = code_start + code_len
        # exceptions
        ne = r.u30()
        for _ in range(ne):
            r.u30(); r.u30(); r.u30(); r.u30(); r.u30()
        parse_traits(r)
        if hit and target_code_abs is None:
            target_code_abs = code_start
            target_len = code_len

    if target_code_abs is None:
        raise SystemExit("no body traced the marker %r" % MARKER)

    first = abc[target_code_abs]
    print("decoy body: abc_off=%d code_len=%d first_op=0x%02x -> 0x%02x"
          % (target_code_abs, target_len, first, UNDEFINED_OPCODE))

    # Patch within the decompressed body buffer.
    file_off = abc_off + target_code_abs
    patched = bytearray(body)
    assert patched[file_off] == first
    patched[file_off] = UNDEFINED_OPCODE

    # Re-emit as uncompressed FWS with a corrected file-length header.
    out = bytearray(b"FWS")
    out.append(version)
    total = 8 + len(patched)
    out += struct.pack("<I", total)
    out += patched
    open(out_path, "wb").write(out)
    print("wrote %s (%d bytes, FWS)" % (out_path, len(out)))


if __name__ == "__main__":
    main()
