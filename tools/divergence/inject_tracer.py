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


def inject(swf_bytes: bytes, bytecode: bytes, min_version: int = 8) -> bytes:
    fws = bytearray(decompress_swf(swf_bytes))

    insert_pos = find_first_showframe(fws)
    if insert_pos < 0:
        raise RuntimeError("No ShowFrame tag found")

    if fws[3] < min_version:
        fws[3] = min_version

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
    print(f"  input:  {len(swf_in)} bytes ({swf_in[:3].decode()})", file=sys.stderr)
    print(f"  output: {len(result)} bytes (FWS) -> {args.output}", file=sys.stderr)


if __name__ == '__main__':
    main()
