#!/usr/bin/env python3
"""Detect whether a SWF file targets AVM2 (ActionScript 3) rather than AVM1.

Used by download_tests.sh to skip AVM2 tests from Ruffle's test suite.

Usage:
    python3 swf_is_avm2.py path/to/test.swf
        → exits 0 if AVM1, 1 if AVM2, 2 on parse error.

The SWF format check walks the tag stream looking for FileAttributes (ID 69).
If present, its `HasActionScript3` bit (0x08) determines the AVM. If absent
(SWF <8), the file is AVM1 by definition.

Fallback: if FileAttributes is missing or unparseable, we also scan for any
DoABC (ID 72) or DoABCDefine (ID 82) tag — presence of either indicates AVM2.
"""

import struct
import sys
import zlib
from pathlib import Path


def _decompress_body(sig: bytes, file_len: int, compressed: bytes) -> bytes:
    if sig == b"FWS":
        return compressed
    if sig == b"CWS":
        return zlib.decompress(compressed)
    if sig == b"ZWS":
        try:
            import lzma
        except ImportError as e:
            raise RuntimeError("lzma module required for ZWS SWFs") from e
        # LZMA SWF: 4 bytes compressed length, 5 bytes LZMA props, then LZMA data.
        # Use lzma.LZMADecompressor with FORMAT_ALONE-style header.
        props = compressed[4:9]
        data = compressed[9:]
        # Reconstruct a .lzma file header: props + uncompressed size (little-endian u64)
        uncompressed_size = file_len - 8
        header = props + struct.pack("<Q", uncompressed_size)
        return lzma.decompress(header + data, format=lzma.FORMAT_ALONE)
    raise ValueError(f"Unknown SWF signature: {sig!r}")


def _rect_byte_length(body: bytes) -> int:
    """Return the byte length of the RECT structure at the start of the body."""
    nbits = body[0] >> 3
    total_bits = 5 + 4 * nbits
    return (total_bits + 7) // 8


def is_avm2(swf_path: Path) -> bool:
    """Return True if the SWF at `swf_path` targets AVM2 (ActionScript 3)."""
    raw = swf_path.read_bytes()
    if len(raw) < 8:
        raise ValueError("SWF too short")
    sig = raw[:3]
    # version = raw[3]  # unused
    file_len = struct.unpack("<I", raw[4:8])[0]

    try:
        body = _decompress_body(sig, file_len, raw[8:])
    except Exception as e:
        raise ValueError(f"decompression failed: {e}")

    # Skip RECT, frame_rate (2), frame_count (2)
    off = _rect_byte_length(body) + 4
    if off > len(body):
        raise ValueError("truncated header")

    # Walk tags
    while off + 2 <= len(body):
        tag_header = struct.unpack_from("<H", body, off)[0]
        off += 2
        tag_id = tag_header >> 6
        tag_len = tag_header & 0x3F
        if tag_len == 0x3F:
            if off + 4 > len(body):
                break
            tag_len = struct.unpack_from("<I", body, off)[0]
            off += 4
        if tag_id == 0:  # End tag
            break
        tag_end = off + tag_len
        if tag_end > len(body):
            break
        if tag_id == 69 and tag_len >= 1:  # FileAttributes
            flags = body[off]
            return bool(flags & 0x08)  # HasActionScript3
        if tag_id in (72, 82):  # DoABC / DoABCDefine (AVM2-only)
            return True
        off = tag_end

    # No FileAttributes, no DoABC → AVM1
    return False


def _classify_one(swf_path: Path) -> str:
    if not swf_path.is_file():
        return "err"
    try:
        return "avm2" if is_avm2(swf_path) else "avm1"
    except Exception:
        return "err"


def main() -> int:
    argv = sys.argv[1:]
    if not argv:
        print(f"Usage: {sys.argv[0]} [--filter-avm1] path/to/test.swf ...", file=sys.stderr)
        print(f"       {sys.argv[0]} --filter-avm1 < paths.txt", file=sys.stderr)
        return 2

    if argv[0] == "--filter-avm1":
        # Batch mode: read SWF paths from argv[1:] (if any) and stdin (if no TTY).
        # Print only the paths whose SWFs are AVM1. Silent on AVM2 / errors.
        paths = [Path(p) for p in argv[1:]]
        if not paths:
            paths = [Path(line.strip()) for line in sys.stdin if line.strip()]
        for p in paths:
            if _classify_one(p) == "avm1":
                print(p)
        return 0

    # Single-path mode: exit 0 for AVM1, 1 for AVM2, 2 on parse error.
    if len(argv) != 1:
        print(f"Usage: {sys.argv[0]} path/to/test.swf", file=sys.stderr)
        return 2
    swf_path = Path(argv[0])
    if not swf_path.is_file():
        print(f"Not a file: {swf_path}", file=sys.stderr)
        return 2
    try:
        return 1 if is_avm2(swf_path) else 0
    except Exception as e:
        print(f"parse error for {swf_path}: {e}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
