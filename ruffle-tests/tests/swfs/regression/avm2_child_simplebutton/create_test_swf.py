#!/usr/bin/env python3
"""Regenerate test.swf + child.swf for avm2_child_simplebutton.

Pins down: a DefineButton2 defined by a LOADED AS3 child resolves all four of
its states. `class_for_char` already answered SimpleButton for a child's button
character, but `button_data_for_char` (avm2_display.c) scanned
`avm2_generated_buttons` — the MAIN movie's table — only, so
`button_create_state` got a NULL ButtonData and every state came back null with
the button measuring 0x0. Fixed by the `g_child_movies` fall-through that
char_info / timeline_for_char / class_for_char already have.

mxmlc cannot author a DefineButton2, so the child's button characters are
tag-injected into the compiled child.swf: DefineShape 1 (20px red), DefineShape
2 (40px blue), DefineButton2 3 (up = 1, over = 1+2 — the multi-record wrapper
arm, down = 2, hit = 1), and a root PlaceObject2 of character 3.

output.txt is the Ruffle exporter's trace, byte for byte; see README.md for the
oracle recipe and the pre-fix row table.
"""
import pathlib, struct, subprocess, zlib
HERE = pathlib.Path(__file__).resolve().parent
MXMLC = pathlib.Path.home() / "CC/flex-sdk/bin/mxmlc"
COMMON = ["-omit-trace-statements=false", "-target-player=11.1",
          "-static-link-runtime-shared-libraries=true",
          "-default-size", "200", "150", "-default-frame-rate", "30"]
T_END, T_SHOWFRAME, T_PLACEOBJECT2, T_DEFINESPRITE, T_DEFINESHAPE, T_DEFINEBUTTON2 = 0, 1, 26, 39, 2, 34
T_DOABC = 82
def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body
class BW:
    def __init__(s): s.bits=[]
    def u(s, v, n):
        for i in range(n-1,-1,-1): s.bits.append((v>>i)&1)
    def sb(s, v, n): s.u(v & ((1<<n)-1), n)
    def bytes(s):
        b=s.bits+[0]*((-len(s.bits))%8)
        return bytes(int(''.join(map(str,b[i:i+8])),2) for i in range(0,len(b),8))
def rect(x0,x1,y0,y1,nb=11):
    w=BW(); w.u(nb,5)
    for v in (x0,x1,y0,y1): w.sb(v,nb)
    return w.bytes()
def shape(sid, size_tw, rgb):
    body = struct.pack("<H", sid) + rect(0,size_tw,0,size_tw,13)
    body += bytes([1, 0x00]) + bytes(rgb) + bytes([0])   # 1 solid fill, 0 lines
    w=BW(); w.u(1,4); w.u(0,4)
    # style change: moveTo(0,0), fillStyle1 = 1
    w.u(0,1); w.u(0,1); w.u(0,1); w.u(1,1); w.u(0,1); w.u(1,1)
    w.u(1,5); w.sb(0,1); w.sb(0,1)
    w.u(1,1)
    nb=13
    def edge(dx,dy):
        w.u(1,1); w.u(1,1); w.u(nb-2,4)
        if dy==0: w.u(0,1); w.u(0,1); w.sb(dx,nb)
        else: w.u(0,1); w.u(1,1); w.sb(dy,nb)
    edge(size_tw,0); edge(0,size_tw); edge(-size_tw,0); edge(0,-size_tw)
    w.u(0,6)
    body += w.bytes()
    return tag(T_DEFINESHAPE, body)
def brec(flags, cid, depth):
    return bytes([flags]) + struct.pack("<HH", cid, depth) + b"\x00" + b"\x00"
def button(bid):
    recs = brec(0x01, 1, 1)                        # up: shape 1 (20px)
    recs += brec(0x02, 1, 1) + brec(0x02, 2, 2)    # over: shapes 1+2 (multi arm)
    recs += brec(0x04, 2, 1)                       # down: shape 2 (40px)
    recs += brec(0x08, 1, 1)                       # hit: shape 1
    body = struct.pack("<H", bid) + b"\x00" + struct.pack("<H", 0) + recs + b"\x00"
    return tag(T_DEFINEBUTTON2, body)
def place(char_id, depth):
    return tag(T_PLACEOBJECT2, bytes([0x04 | 0x02]) + struct.pack("<HH", depth, char_id) + b"\x00")
def read_tags(data, pos):
    tags = []
    while pos < len(data):
        (hdr,) = struct.unpack_from("<H", data, pos)
        code, length, start = hdr >> 6, hdr & 0x3F, pos + 2
        if length == 0x3F:
            (length,) = struct.unpack_from("<I", data, start); start += 4
        tags.append((code, data[start:start + length])); pos = start + length
        if code == T_END: break
    return tags
def inject(path):
    raw = path.read_bytes(); sig, version = raw[:3], raw[3]
    body = zlib.decompress(raw[8:]) if sig == b"CWS" else raw[8:]
    nbits = body[0] >> 3; header_len = (5 + 4 * nbits + 7) // 8 + 4
    header, tags = body[:header_len], read_tags(body, header_len)
    out, dd, dp = b"", False, False
    for code, tb in tags:
        if code == T_DOABC and not dd:
            out += shape(1, 400, (255,0,0)) + shape(2, 800, (0,0,255)) + button(3); dd = True
        if code == T_SHOWFRAME and not dp:
            out += place(3, 1); dp = True
        out += tag(code, tb)
    assert dd and dp
    body = header + out
    path.write_bytes(b"FWS" + bytes([version]) + struct.pack("<I", 8 + len(body)) + body)
child = HERE / "child.swf"
subprocess.run([str(MXMLC), *COMMON, "-output", str(child), str(HERE / "Child.as")], check=True)
inject(child)
subprocess.run([str(MXMLC), *COMMON, "-output", str(HERE / "test.swf"), str(HERE / "Test.as")], check=True)
