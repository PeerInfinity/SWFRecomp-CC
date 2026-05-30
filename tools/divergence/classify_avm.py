#!/usr/bin/env python3
"""Classify SWF(s) as AVM1 vs AVM2 by scanning the main-timeline tag stream.

The SWF *version* byte is NOT a reliable discriminator — AVM1 content is
routinely published as SWF v9+ (e.g. Age of War is v9 AVM1). The authoritative
signal is which ActionScript tags the file carries:

    DoABC (82) / DoABCDefine (72)  -> AVM2 (AS3 bytecode)
    DoAction (12) / DoInitAction (59) -> AVM1
    FileAttributes (69) ActionScript3 bit -> AS3 hint (cross-check)

The SWFRecomp recompiler and the divergence tracer are AVM1-only; AVM2 SWFs
should be excluded from the divergence corpus.

Usage:
    python3 tools/divergence/classify_avm.py <file.swf> [<file.swf> ...]
    python3 tools/divergence/classify_avm.py ~/CC/flasharchive/*.swf
    python3 tools/divergence/classify_avm.py --avm1-only ~/CC/glaiel/swfs/*.swf
        # print just the AVM1 basenames (no extension), one per line

Exit code: 0 if every input is AVM1, 1 otherwise.
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from inject_tracer import decompress_swf  # shared CWS/ZWS/FWS handling


def classify(path: Path):
    try:
        data = decompress_swf(path.read_bytes())
    except Exception as e:  # noqa: BLE001
        return "ERR", str(e)[:40]
    pos = 8
    nbits = (data[pos] >> 3) & 0x1F
    pos += (5 + nbits * 4 + 7) // 8  # skip frame-size RECT
    pos += 4                          # frame rate (2) + frame count (2)
    has_abc = has_avm1 = False
    as3_flag = None
    while pos + 2 <= len(data):
        code_and_len = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        ttype = (code_and_len >> 6) & 0x3FF
        length = code_and_len & 0x3F
        if length == 0x3F:
            length = struct.unpack_from('<I', data, pos)[0]
            pos += 4
        if ttype in (82, 72):
            has_abc = True
        elif ttype in (12, 59):
            has_avm1 = True
        elif ttype == 69 and length >= 1:
            as3_flag = bool(data[pos] & 0x08)
        pos += length
        if ttype == 0:  # End
            break
    if has_abc:
        kind = "AVM2"
    elif has_avm1:
        kind = "AVM1"
    elif as3_flag:
        kind = "AVM2?"   # AS3 flag set, no AVM1 actions found -> treat as AVM2
    else:
        kind = "none?"
    return kind, f"abc={int(has_abc)} avm1={int(has_avm1)} as3flag={as3_flag}"


def main():
    args = sys.argv[1:]
    avm1_only = False
    if args and args[0] == "--avm1-only":
        avm1_only = True
        args = args[1:]
    if not args:
        print(__doc__)
        sys.exit(2)
    all_avm1 = True
    for a in args:
        p = Path(a)
        kind, detail = classify(p)
        if kind != "AVM1":
            all_avm1 = False
        if avm1_only:
            if kind == "AVM1":
                print(p.stem)
        else:
            print(f"{kind:6} {p.name}   ({detail})")
    sys.exit(0 if all_avm1 else 1)


if __name__ == "__main__":
    main()
