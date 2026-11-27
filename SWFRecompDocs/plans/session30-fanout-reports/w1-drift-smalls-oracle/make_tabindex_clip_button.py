#!/usr/bin/env python3
"""s30 w1-drift-smalls FLASH probe: tabIndex NEGATIVE / delete rules on a timeline clip `c`, a script clip `m`
and a real Button `b` (DefineButton2), SWF6 and SWF8. Text fields (tf_tabindex_null, FP32): -1 unsets,
-2147483648 reads 2147483648 (so the rule is the -1 sentinel, not "any negative"), delete is a no-op.
Per target T:  T.tabIndex=3; T.tabIndex=-1; trace    | T.tabIndex=3; T.tabIndex=-2; trace
               T.tabIndex=-2147483648; trace         | T.tabIndex=4; trace(delete T.tabIndex); trace(T.tabIndex)
Run: python3 make_tabindex_clip_button.py -> tabindex_clip_button/{v6,v8}/test.swf (+ test.toml)
"""
import os, struct, importlib.util
here = os.path.dirname(os.path.abspath(__file__))
src_path = os.path.join(here, '../../session29-fanout-reports/w2-disposition-land-oracle/tabindex/make_fixtures.py')
g = {}; exec(open(src_path).read().split("F = {}")[0], g)
push, GETVAR, SETMEM, GETMEM, TRACE, POP, CALLMETH, SETVAR = (g[k] for k in ('push','GETVAR','SETMEM','GETMEM','TRACE','POP','CALLMETH','SETVAR'))
tag, doaction, swf, sprite, s, rec = g['tag'], g['doaction'], g['swf'], g['sprite'], g['s'], g['rec']
DELETE = rec(0x3a)
def place(depth, cid, name): return tag(26, bytes([0x22]) + struct.pack('<HH', depth, cid) + s(name))
# DefineButton2 id 2: no TrackAsMenu, ActionOffset 0; one record (all 4 states) -> sprite 1, depth 1,
# empty MATRIX, empty CXFORMWITHALPHA; CharacterEndFlag.
button = tag(34, struct.pack('<HBH', 2, 0, 0) + bytes([0x0F]) + struct.pack('<HH', 1, 1) + b'\x00' + b'\x00' + b'\x00')
def T(name): return lambda: push(name) + GETVAR
def label(x): return push(x) + TRACE
def setv(t, v): return t() + push("tabIndex", v) + SETMEM
def get(t): return t() + push("tabIndex") + GETMEM + TRACE
body = push("m", 5, "m", 2, "this") + GETVAR + push("createEmptyMovieClip") + CALLMETH + SETVAR
for n in ("c", "m", "b"):
    t = T(n)
    body += label(n + " neg1") + setv(t, 3) + setv(t, -1) + get(t)
    body += label(n + " neg2") + setv(t, 3) + setv(t, -2) + get(t)
    body += label(n + " min") + setv(t, -2147483648) + get(t)
    body += label(n + " del") + setv(t, 4) + t() + push("tabIndex") + DELETE + TRACE + get(t)
body += label("done")
tags = [g['FILEATTR'], g['BG'], sprite(1, [g['SHOW']]), button, place(1, 1, "c"), place(2, 2, "b"), doaction(body), g['SHOW']]
for ver in (6, 8):
    d = os.path.join(here, 'tabindex_clip_button', 'v%d' % ver); os.makedirs(d, exist_ok=True)
    tl = tags if ver >= 8 else tags[1:]   # FileAttributes is SWF8+
    data = swf(tl, ver)
    open(os.path.join(d, 'test.swf'), 'wb').write(data)
    open(os.path.join(d, 'test.toml'), 'w').write('num_ticks = 2\n')
    print(ver, len(data))
