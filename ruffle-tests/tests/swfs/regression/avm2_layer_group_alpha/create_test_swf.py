#!/usr/bin/env python3
"""Regenerate test.swf for avm2_layer_group_alpha (s25 w2-avm2-layer-groups).

Pins down: the AVM2 display walk (avm2_display.c avm2_render_node blend arm)
honours layer groups. A BlendMode.LAYER sprite isolates its subtree in an
offscreen; a BlendMode.ALPHA child inside it multiplies the group by its
alpha (dst *= src.a), ruffle render/wgpu/src/surface.rs
nearest_layer + shaders/blend/alpha.wgsl. Before the port the AVM2 arm dropped
every ALPHA/ERASE draw unconditionally and drew LAYER as NORMAL.

The SWF is upstream visual/blend_modes/layer_alpha/test.swf (a static timeline:
no DoAction, the blend bytes live in PlaceObject3) with FileAttributes'
ActionScript3 bit set and a minimal hand-assembled DoABC (one script whose
init is `getlocal0; pushscope; returnvoid`, no classes: the root stays a plain
MovieClip) inserted after SetBackgroundColor, so the recompiler takes the AVM2
entry point and the same placements reach the AVM2 timeline
(set_blend_mode_name -> blend_mode_id) instead of tag.c. mxmlc is not in the
cloud box; this is the oracle-free route. output.expected.png is upstream's
layer_alpha golden (Ruffle renders a script-free timeline identically under
AVM1 and AVM2; confirmation requested as a LOCAL ORACLE REQUEST in
SWFRecomp-CC-history:SWFRecompDocs/plans/session25-fanout-reports/w2-avm2-layer-groups-report.md).
"""
import pathlib, struct, zlib
HERE = pathlib.Path(__file__).resolve().parent
SRC = HERE.parent.parent / "visual/blend_modes/layer_alpha/test.swf"

def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body

# minor 16, major 46; empty constant pool (7 zero counts); 1 method_info
# (0 params, return *, no name, no flags); 0 metadata; 0 classes; 1 script
# (init = method 0, 0 traits); 1 body (stack 1, locals 1, scope 0..1,
# code getlocal0/pushscope/returnvoid, 0 exceptions, 0 traits).
ABC = (struct.pack("<HH", 16, 46) + bytes(7)
       + bytes([1, 0, 0, 0, 0]) + bytes([0]) + bytes([0])
       + bytes([1, 0, 0])
       + bytes([1, 0, 1, 1, 0, 1, 3, 0xD0, 0x30, 0x47, 0, 0]))
DOABC = tag(82, struct.pack("<I", 1) + b"\0" + ABC)  # kDoAbcLazyInitialize, name ""

def main():
    b = SRC.read_bytes()
    ver = b[3]
    body = bytearray(zlib.decompress(b[8:]) if b[:3] == b"CWS" else b[8:])
    nb = body[0] >> 3
    pos = (5 + 4 * nb + 7) // 8 + 4
    while pos < len(body):
        h = struct.unpack_from("<H", body, pos)[0]
        code, ln, hl = h >> 6, h & 0x3F, 2
        if ln == 0x3F:
            ln, hl = struct.unpack_from("<I", body, pos + 2)[0], 6
        assert code not in (12, 59), "source SWF has DoAction"
        if code == 69:
            body[pos + hl] |= 0x08          # FileAttributes.ActionScript3
        if code == 0:
            break
        pos += hl + ln
        if code == 9:                       # SetBackgroundColor
            body[pos:pos] = DOABC
            pos += len(DOABC)
    (HERE / "test.swf").write_bytes(b"FWS" + bytes([ver])
        + struct.pack("<I", 8 + len(body)) + bytes(body))

if __name__ == "__main__":
    main()
