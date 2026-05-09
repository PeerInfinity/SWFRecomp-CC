#!/usr/bin/env python3
"""Extract SWF metadata (version, width, height) and emit JSON to stdout.

Handles uncompressed (FWS), zlib (CWS), and LZMA (ZWS) SWFs.

Usage: extract_swf_metadata.py <path/to/file.swf>
Output: {"swf_version": N, "width": W, "height": H}
"""
import json
import sys
import zlib


def read_rect(payload):
    """Parse the RECT at the start of the post-header SWF body, return (xmax, ymax) in twips."""
    if not payload:
        return None
    nbits = payload[0] >> 3
    total_bits = 5 + nbits * 4
    total_bytes = (total_bits + 7) // 8
    if len(payload) < total_bytes:
        return None
    bitstream = 0
    for i in range(total_bytes):
        bitstream = (bitstream << 8) | payload[i]
    bitstream >>= (total_bytes * 8 - total_bits)

    def take(n, value, remaining):
        v = (value >> (remaining - n)) & ((1 << n) - 1)
        return v, remaining - n

    rem = total_bits
    _, rem = take(5, bitstream, rem)
    _xmin, rem = take(nbits, bitstream, rem)
    xmax, rem = take(nbits, bitstream, rem)
    _ymin, rem = take(nbits, bitstream, rem)
    ymax, rem = take(nbits, bitstream, rem)
    return xmax, ymax


def main():
    if len(sys.argv) != 2:
        print("Usage: extract_swf_metadata.py <file.swf>", file=sys.stderr)
        sys.exit(1)

    with open(sys.argv[1], "rb") as f:
        data = f.read()

    if len(data) < 8:
        print("Error: file too short", file=sys.stderr)
        sys.exit(1)

    sig = data[0:3]
    version = data[3]
    payload = data[8:]

    if sig == b"CWS":
        try:
            payload = zlib.decompress(payload)
        except zlib.error as e:
            print(f"Error: zlib decompress failed: {e}", file=sys.stderr)
            payload = b""
    elif sig == b"ZWS":
        # LZMA-compressed SWF: 4-byte uncompressed length, 5-byte LZMA props, then stream.
        try:
            import lzma
            uncompressed_size = int.from_bytes(payload[0:4], "little")
            props = payload[4:9]
            stream = payload[9:]
            # Reconstruct .lzma stream header for the standalone decompressor.
            header = props + uncompressed_size.to_bytes(8, "little")
            payload = lzma.decompress(header + stream, format=lzma.FORMAT_ALONE)
        except Exception as e:
            print(f"Error: lzma decompress failed: {e}", file=sys.stderr)
            payload = b""
    elif sig != b"FWS":
        print(f"Error: not a SWF file (sig={sig!r})", file=sys.stderr)
        sys.exit(1)

    rect = read_rect(payload)
    out = {"swf_version": int(version)}
    if rect:
        xmax, ymax = rect
        out["width"] = xmax // 20
        out["height"] = ymax // 20

    json.dump(out, sys.stdout)


if __name__ == "__main__":
    main()
