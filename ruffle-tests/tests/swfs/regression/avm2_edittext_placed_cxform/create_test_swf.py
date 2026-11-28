#!/usr/bin/env python3
"""avm2_edittext_placed_cxform: AVM2 twin of ../avm1_edittext_placed_cxform.

Pins (s27 w1-text-glyph-fidelity, playbook s25 "AVM2 avm2_render_textbox cx
twin"): Ruffle EditText::draw_text_box / draw_device_text_box multiply the
background and border colours by `transform.color_transform`
(core/src/display_object/edit_text.rs:2887/2895/2970/2975). Our AVM2 walk
(avm2_display.c avm2_render_textbox) drew both through cxform slot 0 with the
group alpha only, so a tinted timeline TextField kept its untinted box.

Same display list as the AVM1 fixture (three bordered embedded-font fields
under PlaceObject cxforms, see its generator for the exact colours), with
FileAttributes' ActionScript3 bit set and a minimal hand-assembled DoABC
(script init `getlocal0; pushscope; returnvoid`, no classes) inserted after
SetBackgroundColor, so the recompiler takes the AVM2 entry point and the
placements reach the AVM2 timeline (the avm2_layer_group_alpha recipe; mxmlc
is not in the cloud box). Ruffle renders a script-free timeline identically
under AVM1 and AVM2, so output.expected.png is the AVM1 fixture's Ruffle
0ddd12b6a golden (confirmation requested as a LOCAL ORACLE REQUEST in
SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/w1-text-glyph-fidelity-report.md).
"""
import pathlib, struct, sys, zlib
HERE = pathlib.Path(__file__).resolve().parent
SRC = HERE.parent / (sys.argv[1] if len(sys.argv) > 1 else "avm1_edittext_placed_cxform") / "test.swf"
OUT = HERE / (sys.argv[2] if len(sys.argv) > 2 else "test.swf")

def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body

ABC = (struct.pack("<HH", 16, 46) + bytes(7)
       + bytes([1, 0, 0, 0, 0]) + bytes([0]) + bytes([0])
       + bytes([1, 0, 0])
       + bytes([1, 0, 1, 1, 0, 1, 3, 0xD0, 0x30, 0x47, 0, 0]))
DOABC = tag(82, struct.pack("<I", 1) + b"\0" + ABC)
FILEATTR = tag(69, struct.pack("<I", 0x08))

def main():
    b = SRC.read_bytes()
    ver = max(b[3], 9)
    body = bytearray(zlib.decompress(b[8:]) if b[:3] == b"CWS" else b[8:])
    nb = body[0] >> 3
    pos = (5 + 4 * nb + 7) // 8 + 4
    first = pos
    have_fa = False
    while pos < len(body):
        h = struct.unpack_from("<H", body, pos)[0]
        code, ln, hl = h >> 6, h & 0x3F, 2
        if ln == 0x3F:
            ln, hl = struct.unpack_from("<I", body, pos + 2)[0], 6
        assert code not in (12, 59), "source SWF has DoAction"
        if code == 69:
            body[pos + hl] |= 0x08
            have_fa = True
        if code == 0:
            break
        pos += hl + ln
        if code == 9:
            body[pos:pos] = DOABC
            pos += len(DOABC)
    if not have_fa:
        body[first:first] = FILEATTR
    OUT.write_bytes(b"FWS" + bytes([ver]) + struct.pack("<I", 8 + len(body)) + bytes(body))

if __name__ == "__main__":
    main()
