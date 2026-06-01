#!/usr/bin/env python3
"""Splice tracer bytecode into a target SWF, just before the first ShowFrame.

Port of the JS in docs/injector/ruffle_inject.html. Steps:
  1. Decompress CWS / ZWS to FWS.
  2. Bump SWF version to >= 8 if needed (ExternalInterface is not used by the
     tracer, but Ruffle / SWFRecomp behavior may differ at lower versions).
  3. Find first ShowFrame tag, splice tracer bytecode in front of it.
  4. Rewrite header file length.

Usage: python3 inject_tracer.py <input.swf> <output.swf> [--bytecode path]
"""
import argparse
import struct
import sys
import zlib
from pathlib import Path


HERE = Path(__file__).resolve().parent


def decompress_swf(data: bytes) -> bytes:
    sig = data[0:3]
    if sig == b'FWS':
        return data
    if sig == b'CWS':
        body = zlib.decompress(data[8:])
        return b'FWS' + data[3:8] + body
    if sig == b'ZWS':
        # LZMA-compressed (rare). Header: ZWS, version, size(4), props(5), lzma stream.
        try:
            import lzma
        except ImportError:
            raise RuntimeError("ZWS SWF requires Python lzma module")
        # 12-byte SWF-LZMA header: ZWS(3) + ver(1) + uncomp_size(4) + comp_size(4)
        props = data[12:17]
        stream = data[17:]
        # Rebuild a standard LZMA stream the decompressor accepts.
        uncompressed = lzma.decompress(props + struct.pack('<Q', 0xFFFFFFFFFFFFFFFF) + stream,
                                       format=lzma.FORMAT_ALONE)
        return b'FWS' + data[3:8] + uncompressed
    raise RuntimeError(f"Unknown SWF signature: {sig!r}")


def skip_rect(data: bytes, pos: int) -> int:
    nbits = (data[pos] >> 3) & 0x1F
    total_bits = 5 + nbits * 4
    return pos + (total_bits + 7) // 8


def find_first_showframe(data: bytes) -> int:
    """Return byte offset of the first ShowFrame tag header (insertion point)."""
    pos = 8  # 'FWS' + ver + length
    pos = skip_rect(data, pos)
    pos += 4  # frame rate(2) + frame count(2)

    while pos < len(data):
        tag_start = pos
        if pos + 2 > len(data):
            return -1
        code_and_length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        tag_type = (code_and_length >> 6) & 0x3FF
        length = code_and_length & 0x3F
        if length == 0x3F:
            if pos + 4 > len(data):
                return -1
            length = struct.unpack_from('<I', data, pos)[0]
            pos += 4
        pos += length

        if tag_type == 1:  # ShowFrame
            return tag_start
        if tag_type == 0:  # End
            return tag_start

    return -1


# ---------------------------------------------------------------------------
# SWF5 -> SWF6+ CLIPACTIONS rewrite.
#
# The tracer needs the SWF declared >= 6 (its onEnterFrame hook is a SWF6+
# feature), so inject() bumps the header version. But CLIPACTIONS event-flag
# fields are version-dependent in the SWF format: UI16 in SWF<=5, UI32 in
# SWF>=6 (SWF File Format Spec, CLIPEVENTFLAGS). Re-declaring a v5 SWF as v8
# without rewriting those fields makes any spec-correct parser (Ruffle AND
# SWFRecomp) read 2 extra bytes per flag field, desyncing the whole tag/action
# stream. So when we cross the v6 boundary we must widen every UI16 flag field
# to UI32. Zero-extension preserves the value: the SWF6 UI32 layout keeps the
# SWF5 low-16 event bits at the same positions and only adds new events in the
# upper bits, so a v5 flag widened to 32 bits means the same set of events.
#
# v5 SWFs cannot contain PlaceObject3 (SWF8+), so only PlaceObject2 (tag 26)
# carries clip actions, possibly nested inside DefineSprite (tag 39).


class _BitReader:
    """Big-endian bit reader over a bytes buffer, for MATRIX / CXFORM skip."""

    def __init__(self, data: bytes, byte_pos: int):
        self.data = data
        self.bytepos = byte_pos
        self.bitpos = 0

    def read_ub(self, n: int) -> int:
        v = 0
        for _ in range(n):
            bit = (self.data[self.bytepos] >> (7 - self.bitpos)) & 1
            v = (v << 1) | bit
            self.bitpos += 1
            if self.bitpos == 8:
                self.bitpos = 0
                self.bytepos += 1
        return v

    def align(self) -> int:
        if self.bitpos != 0:
            self.bitpos = 0
            self.bytepos += 1
        return self.bytepos


def _skip_matrix(data: bytes, pos: int) -> int:
    br = _BitReader(data, pos)
    if br.read_ub(1):  # HasScale
        nb = br.read_ub(5)
        br.read_ub(nb)
        br.read_ub(nb)
    if br.read_ub(1):  # HasRotate
        nb = br.read_ub(5)
        br.read_ub(nb)
        br.read_ub(nb)
    nb = br.read_ub(5)  # NTranslateBits
    br.read_ub(nb)
    br.read_ub(nb)
    return br.align()


def _skip_cxform_with_alpha(data: bytes, pos: int) -> int:
    br = _BitReader(data, pos)
    has_add = br.read_ub(1)
    has_mult = br.read_ub(1)
    nb = br.read_ub(4)
    if has_mult:
        for _ in range(4):
            br.read_ub(nb)
    if has_add:
        for _ in range(4):
            br.read_ub(nb)
    return br.align()


def _widen_clipactions_u16_to_u32(data: bytes, pos: int):
    """Rewrite a CLIPACTIONS block (data[pos:]) from UI16 to UI32 flag widths.

    Returns (new_clipactions_bytes, end_pos, records_widened).
    """
    out = bytearray()
    out += data[pos:pos + 2]  # Reserved UI16 (always UI16, unchanged)
    pos += 2
    all_flags = struct.unpack_from('<H', data, pos)[0]  # AllEventFlags UI16
    pos += 2
    out += struct.pack('<I', all_flags)
    widened = 1  # AllEventFlags
    while True:
        ev = struct.unpack_from('<H', data, pos)[0]  # EventFlags UI16
        pos += 2
        if ev == 0:  # ClipActionEndFlag
            out += struct.pack('<I', 0)
            widened += 1
            break
        out += struct.pack('<I', ev)
        widened += 1
        size = struct.unpack_from('<I', data, pos)[0]  # ActionRecordSize UI32
        pos += 4
        out += struct.pack('<I', size)
        out += data[pos:pos + size]  # KeyCode (if any) + action bytes
        pos += size
    return bytes(out), pos, widened


def _rewrite_place_object2(body: bytes):
    """Rewrite a PlaceObject2 tag body's clip actions (if present)."""
    flags = body[0]
    if not (flags & 0x80):  # HasClipActions
        return body, 0
    pos = 1
    pos += 2  # Depth
    if flags & 0x02:  # HasCharacter
        pos += 2
    if flags & 0x04:  # HasMatrix
        pos = _skip_matrix(body, pos)
    if flags & 0x08:  # HasColorTransform
        pos = _skip_cxform_with_alpha(body, pos)
    if flags & 0x10:  # HasRatio
        pos += 2
    if flags & 0x20:  # HasName
        while body[pos] != 0:
            pos += 1
        pos += 1
    if flags & 0x40:  # HasClipDepth
        pos += 2
    new_clip, end_pos, widened = _widen_clipactions_u16_to_u32(body, pos)
    return body[:pos] + new_clip + body[end_pos:], widened


def _emit_tag(tag_type: int, body: bytes) -> bytes:
    n = len(body)
    if n >= 0x3F:
        return struct.pack('<H', (tag_type << 6) | 0x3F) + struct.pack('<I', n) + body
    return struct.pack('<H', (tag_type << 6) | n) + body


def _rewrite_tag_stream(body: bytes) -> "tuple[bytes, int]":
    """Walk a tag stream (top-level or DefineSprite body), widening clip actions.

    Returns (rewritten_bytes, total_records_widened).
    """
    out = bytearray()
    pos = 0
    widened_total = 0
    while pos < len(body):
        if pos + 2 > len(body):
            out += body[pos:]
            break
        cl = struct.unpack_from('<H', body, pos)[0]
        tag_type = cl >> 6
        length = cl & 0x3F
        hdr_end = pos + 2
        if length == 0x3F:
            length = struct.unpack_from('<I', body, hdr_end)[0]
            hdr_end += 4
        tag_body = body[hdr_end:hdr_end + length]
        new_body = tag_body
        if tag_type == 26:  # PlaceObject2
            new_body, w = _rewrite_place_object2(tag_body)
            widened_total += w
        elif tag_type == 39:  # DefineSprite: SpriteID(2)+FrameCount(2)+subtags
            sub, w = _rewrite_tag_stream(tag_body[4:])
            new_body = tag_body[:4] + sub
            widened_total += w
        out += _emit_tag(tag_type, new_body)
        pos = hdr_end + length
        if tag_type == 0:  # End — copy any trailing bytes verbatim
            out += body[pos:]
            break
    return bytes(out), widened_total


def upgrade_clipactions_to_v6(fws: bytearray) -> int:
    """In place: rewrite all CLIPACTIONS flag fields from UI16 to UI32.

    Returns the number of flag fields widened (0 if none / nothing to do).
    """
    tag_start = skip_rect(fws, 8)
    tag_start += 4  # frame rate(2) + frame count(2)
    rewritten, widened = _rewrite_tag_stream(bytes(fws[tag_start:]))
    if widened:
        fws[tag_start:] = rewritten
        struct.pack_into('<I', fws, 4, len(fws))  # fix header file length
    return widened


def inject(swf_bytes: bytes, bytecode: bytes, min_version: int = 8) -> bytes:
    fws = bytearray(decompress_swf(swf_bytes))

    orig_version = fws[3]
    target_version = max(orig_version, min_version)
    # Crossing the v6 boundary changes CLIPACTIONS flag widths (UI16 -> UI32);
    # rewrite the existing clip actions before bumping so the SWF stays valid.
    widened = 0
    if orig_version < 6 <= target_version:
        widened = upgrade_clipactions_to_v6(fws)

    insert_pos = find_first_showframe(fws)
    if insert_pos < 0:
        raise RuntimeError("No ShowFrame tag found")

    if fws[3] < min_version:
        fws[3] = min_version

    inject._last_clipactions_widened = widened

    new_bytes = bytearray(len(fws) + len(bytecode))
    new_bytes[:insert_pos] = fws[:insert_pos]
    new_bytes[insert_pos:insert_pos + len(bytecode)] = bytecode
    new_bytes[insert_pos + len(bytecode):] = fws[insert_pos:]

    # Rewrite file length (bytes 4-7, little-endian u32).
    struct.pack_into('<I', new_bytes, 4, len(new_bytes))

    return bytes(new_bytes)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input", type=Path)
    ap.add_argument("output", type=Path)
    ap.add_argument("--bytecode", type=Path,
                    default=HERE / "tracer_bytecode.bin",
                    help="Path to tracer_bytecode.bin (default: alongside script)")
    ap.add_argument("--min-version", type=int, default=8)
    args = ap.parse_args()

    if not args.bytecode.exists():
        print(f"Tracer bytecode not found: {args.bytecode}", file=sys.stderr)
        print("Run build_tracer.sh first.", file=sys.stderr)
        sys.exit(1)

    swf_in = args.input.read_bytes()
    bytecode = args.bytecode.read_bytes()
    result = inject(swf_in, bytecode, min_version=args.min_version)
    args.output.write_bytes(result)

    print(f"Injected {len(bytecode)} bytes of tracer into {args.input.name}",
          file=sys.stderr)
    widened = getattr(inject, "_last_clipactions_widened", 0)
    if widened:
        print(f"  upgraded {widened} CLIPACTIONS flag field(s) UI16->UI32 "
              f"(SWF v{swf_in[3]} -> v{args.min_version})", file=sys.stderr)
    print(f"  input:  {len(swf_in)} bytes ({swf_in[:3].decode()})", file=sys.stderr)
    print(f"  output: {len(result)} bytes (FWS) -> {args.output}", file=sys.stderr)


if __name__ == '__main__':
    main()
