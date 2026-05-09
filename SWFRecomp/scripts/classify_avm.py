#!/usr/bin/env python3
"""Classify SWFs as AVM1, AVM2, or hybrid by scanning their tag stream.

AVM2 bytecode lives in DoABC (tag 72) / DoABC2 (tag 82) tags.
AVM1 bytecode lives in DoAction (tag 12) / DoInitAction (tag 59) tags.
FileAttributes (tag 69, SWF v8+) has an ActionScript3 flag in bit 3 of payload byte 0.
"""
import lzma
import sys
import zlib
from pathlib import Path

TAG_DOACTION = 12
TAG_DOINITACTION = 59
TAG_FILEATTRIBUTES = 69
TAG_DOABC = 72
TAG_DOABC2 = 82


def decompress(data: bytes) -> tuple[bytes, int, str]:
    sig = data[0:3]
    version = data[3]
    body = data[8:]
    if sig == b"FWS":
        return body, version, "FWS"
    if sig == b"CWS":
        return zlib.decompress(body), version, "CWS"
    if sig == b"ZWS":
        usize = int.from_bytes(body[0:4], "little")
        props = body[4:9]
        stream = body[9:]
        header = props + usize.to_bytes(8, "little")
        return lzma.decompress(header + stream, format=lzma.FORMAT_ALONE), version, "ZWS"
    raise ValueError(f"Not a SWF (sig={sig!r})")


def skip_rect(buf: bytes, off: int) -> int:
    nbits = buf[off] >> 3
    total_bits = 5 + nbits * 4
    return off + (total_bits + 7) // 8


def classify(path: Path) -> dict:
    body, version, sig = decompress(path.read_bytes())
    off = skip_rect(body, 0)
    off += 4  # framerate (2) + framecount (2)

    has_avm1 = False
    has_avm2 = False
    fa_as3 = None

    while off + 2 <= len(body):
        tag_hdr = int.from_bytes(body[off:off + 2], "little")
        tag_code = tag_hdr >> 6
        length = tag_hdr & 0x3F
        off += 2
        if length == 0x3F:
            length = int.from_bytes(body[off:off + 4], "little")
            off += 4
        if tag_code == 0:
            break
        payload_end = off + length
        if tag_code == TAG_FILEATTRIBUTES and length >= 1:
            fa_as3 = bool(body[off] & 0x08)
        elif tag_code in (TAG_DOABC, TAG_DOABC2):
            has_avm2 = True
        elif tag_code in (TAG_DOACTION, TAG_DOINITACTION):
            has_avm1 = True
        off = payload_end

    if has_avm2 and has_avm1:
        verdict = "hybrid"
    elif has_avm2:
        verdict = "AVM2"
    elif has_avm1:
        verdict = "AVM1"
    else:
        verdict = "no-script"

    return {
        "name": path.name,
        "version": version,
        "sig": sig,
        "verdict": verdict,
        "fa_as3": fa_as3,
        "size": path.stat().st_size,
    }


def main():
    if len(sys.argv) < 2:
        print("Usage: classify_avm.py <dir-or-files...>", file=sys.stderr)
        sys.exit(1)

    paths = []
    for arg in sys.argv[1:]:
        p = Path(arg)
        if p.is_dir():
            paths.extend(sorted(p.glob("*.swf")))
        else:
            paths.append(p)

    rows = []
    for p in paths:
        try:
            rows.append(classify(p))
        except Exception as e:
            rows.append({"name": p.name, "verdict": f"ERROR: {e}", "version": "?", "sig": "?", "fa_as3": None, "size": 0})

    rows.sort(key=lambda r: (r["verdict"], r["name"].lower()))
    name_w = max(len(r["name"]) for r in rows)
    print(f"{'verdict':<10} {'v':>3} {'sig':<3} {'fa_as3':<6} {'size':>10}  name")
    print("-" * (33 + name_w))
    for r in rows:
        as3 = "-" if r["fa_as3"] is None else ("yes" if r["fa_as3"] else "no")
        print(f"{r['verdict']:<10} {str(r['version']):>3} {r['sig']:<3} {as3:<6} {r['size']:>10}  {r['name']}")

    counts = {}
    for r in rows:
        counts[r["verdict"]] = counts.get(r["verdict"], 0) + 1
    print()
    for k, v in sorted(counts.items()):
        print(f"  {k}: {v}")


if __name__ == "__main__":
    main()
