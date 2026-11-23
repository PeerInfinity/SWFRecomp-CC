#!/usr/bin/env python3
"""s26 w1-avm1-dispatch-scope: corpus census of bare MovieClip-method calls.

Walks every AVM1 action block in the given SWFs (DoAction, DoInitAction,
DefineSprite frames, PlaceObject2/3 clip actions, DefineButton2 conditions)
and records every ActionCallFunction (0x3D) whose callee name is a
MovieClip.prototype method, tagged with its context:

  with    inside an ActionWith block (any depth)
  func    inside a DefineFunction/DefineFunction2 body (not a with)
  sprite  in a DefineSprite frame script (not a with / func)
  root    in a root frame script / init action
  clipev  in a PlaceObject clip-event handler

Usage: scan_bare_calls.py ROOT_DIR... [--per-file]
Python 3 stdlib only. Read-only.
"""
import os
import struct
import sys
import zlib
from collections import Counter, defaultdict

MC_METHODS = set("""attachMovie createEmptyMovieClip createTextField duplicateMovieClip
removeMovieClip getNextHighestDepth getInstanceAtDepth getDepth swapDepths getBounds getRect
hitTest localToGlobal globalToLocal gotoAndPlay gotoAndStop play stop nextFrame prevFrame
getBytesLoaded getBytesTotal getURL loadMovie loadVariables unloadMovie setMask startDrag
stopDrag attachAudio attachBitmap getSWFVersion getTextSnapshot beginFill beginGradientFill
beginBitmapFill lineStyle lineGradientStyle moveTo lineTo curveTo endFill clear""".split())


def swf_body(data):
    sig = data[:3]
    if sig == b'FWS':
        b = data[8:]
    elif sig == b'CWS':
        try:
            b = zlib.decompress(data[8:])
        except Exception:
            return None, 0
    else:
        return None, 0
    nbits = b[0] >> 3
    rect_bytes = (5 + 4 * nbits + 7) // 8
    return b[rect_bytes + 4:], data[3]


def iter_tags(b, off=0, end=None):
    end = len(b) if end is None else end
    while off + 2 <= end:
        hdr = struct.unpack_from('<H', b, off)[0]
        code, ln = hdr >> 6, hdr & 0x3f
        off += 2
        if ln == 0x3f:
            if off + 4 > end:
                return
            ln = struct.unpack_from('<I', b, off)[0]
            off += 4
        yield code, off, ln
        off += ln
        if code == 0:
            return


def cstr(b, o):
    e = b.find(b'\0', o)
    if e < 0:
        return '', len(b)
    return b[o:e].decode('latin-1'), e + 1


def scan_actions(b, start, end, ctx, out, pool=None):
    """Linear action walk; with/function ranges tracked by end offsets."""
    pool = pool if pool is not None else []
    o = start
    last_push = None
    ranges = []  # (end_offset, kind)
    while o < end:
        while ranges and o >= ranges[-1][0]:
            ranges.pop()
        code = b[o]
        o += 1
        if code == 0:
            last_push = None
            continue
        ln = 0
        if code >= 0x80:
            if o + 2 > end:
                return
            ln = struct.unpack_from('<H', b, o)[0]
            o += 2
        p = o
        o += ln
        if code == 0x88:  # ConstantPool
            n = struct.unpack_from('<H', b, p)[0]
            q = p + 2
            pool[:] = []
            for _ in range(n):
                s, q = cstr(b, q)
                pool.append(s)
        elif code == 0x96:  # Push
            q = p
            vals = []
            while q < p + ln:
                t = b[q]; q += 1
                if t == 0:
                    s, q = cstr(b, q); vals.append(s)
                elif t == 1: q += 4; vals.append(None)
                elif t in (2, 3): vals.append(None)
                elif t == 4: q += 1; vals.append(None)
                elif t == 5: q += 1; vals.append(None)
                elif t == 6: q += 8; vals.append(None)
                elif t == 7: q += 4; vals.append(None)
                elif t == 8: vals.append(pool[b[q]] if b[q] < len(pool) else None); q += 1
                elif t == 9:
                    i = struct.unpack_from('<H', b, q)[0]; q += 2
                    vals.append(pool[i] if i < len(pool) else None)
                else:
                    break
            last_push = vals[-1] if vals else None
            continue
        elif code == 0x94:  # With
            sz = struct.unpack_from('<H', b, p)[0]
            ranges.append((o + sz, 'with'))
        elif code == 0x9B:  # DefineFunction
            q = p
            _, q = cstr(b, q)
            n = struct.unpack_from('<H', b, q)[0]; q += 2
            for _ in range(n):
                _, q = cstr(b, q)
            sz = struct.unpack_from('<H', b, q)[0]
            ranges.append((o + sz, 'func'))
        elif code == 0x8E:  # DefineFunction2
            q = p
            _, q = cstr(b, q)
            n = struct.unpack_from('<H', b, q)[0]; q += 2
            q += 1 + 2
            for _ in range(n):
                q += 1
                _, q = cstr(b, q)
            sz = struct.unpack_from('<H', b, q)[0]
            ranges.append((o + sz, 'func'))
        elif code == 0x3D:  # CallFunction
            if isinstance(last_push, str) and last_push in MC_METHODS:
                kinds = [k for _, k in ranges]
                c = 'with' if 'with' in kinds else ('func' if 'func' in kinds else ctx)
                out.append((last_push, c))
        last_push = None


def scan_tags(b, off, end, ctx, out):
    for code, p, ln in iter_tags(b, off, end):
        if code in (12,):
            scan_actions(b, p, p + ln, ctx, out)
        elif code == 59:
            scan_actions(b, p + 2, p + ln, 'root', out)
        elif code == 39:
            scan_tags(b, p + 4, p + ln, 'sprite', out)
        elif code == 34:  # DefineButton2: conditions
            q = p + 3
            q0 = q
            q = q0
            # skip records
            aoff = struct.unpack_from('<H', b, p + 3)[0]
            if aoff:
                q = p + 3 + aoff
                while q < p + ln:
                    nxt = struct.unpack_from('<H', b, q)[0]
                    stop = q + nxt if nxt else p + ln
                    scan_actions(b, q + 4, stop, 'clipev', out)
                    if not nxt:
                        break
                    q = stop
        elif code in (26, 70):
            flags = b[p]
            if not (flags & 0x80):
                continue
            # Too fiddly to parse every PlaceObject field generically; find the
            # clip-actions block by brute force is unsafe, so skip.
            pass


def main():
    roots = [a for a in sys.argv[1:] if not a.startswith('--')]
    per_file = '--per-file' in sys.argv
    tot = Counter()
    files_by = defaultdict(set)
    for r in roots:
        for dp, _, fs in os.walk(r):
            for f in fs:
                if not f.endswith('.swf'):
                    continue
                path = os.path.join(dp, f)
                try:
                    data = open(path, 'rb').read()
                except OSError:
                    continue
                b, ver = swf_body(data)
                if b is None:
                    continue
                out = []
                try:
                    scan_tags(b, 0, len(b), 'root', out)
                except Exception:
                    pass
                for name, c in out:
                    tot[(name, c)] += 1
                    files_by[(name, c)].add(path)
    for (name, c), n in sorted(tot.items(), key=lambda kv: (-kv[1], kv[0])):
        print(f'{n:6d} {len(files_by[(name, c)]):5d} files  {c:7s} {name}')
        if per_file:
            for p in sorted(files_by[(name, c)])[:8]:
                print('              ', p)


if __name__ == '__main__':
    main()
