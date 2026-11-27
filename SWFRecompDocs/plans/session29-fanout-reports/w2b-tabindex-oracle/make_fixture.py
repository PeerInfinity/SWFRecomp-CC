#!/usr/bin/env python3
"""s29 w2b-tabindex follow-up FLASH fixture (optional): timeline-placed child raw mode, numeric string, null.
Frame 1: PlaceObject2 sprite 1 as "c" at depth 1, then DoAction:
  c.tabIndex="x"; trace(c.tabIndex);              // timeline child, first op on c: raw or coerce?
  m=this.createEmptyMovieClip("m",5); m.tabIndex="5"; trace(m.tabIndex);  // numeric string: 5 or INT_MIN?
  m.tabIndex=null; trace(m.tabIndex);             // null: unset (undefined) or 0?
Run: python3 make_fixture.py -> t_child_numstr_null/test.swf
"""
import os, struct, importlib.util
here = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location('mf', os.path.join(here, '../w2-disposition-land-oracle/tabindex/make_fixtures.py'))
# reuse only the helpers: exec the top of make_fixtures.py up to the fixture table
src = open(spec.origin).read().split("F = {}")[0]
g = {}; exec(src, g)
push, GETVAR, SETMEM, GETMEM, TRACE, POP, CALLMETH, SETVAR = (g[k] for k in ('push','GETVAR','SETMEM','GETMEM','TRACE','POP','CALLMETH','SETVAR'))
tag, doaction, swf, sprite, s, rec = g['tag'], g['doaction'], g['swf'], g['sprite'], g['s'], g['rec']
place = tag(26, bytes([0x22]) + struct.pack('<HH', 1, 1) + s('c'))  # PlaceObject2: HasName|HasCharacter, depth 1, char 1
def setget(target, val):
    return target() + push("tabIndex", val) + SETMEM + target() + push("tabIndex") + GETMEM + TRACE
C = lambda: push("c") + GETVAR
M = lambda: push("m") + GETVAR
body = setget(C, "x")
body += push("m", 5, "m", 2, "this") + GETVAR + push("createEmptyMovieClip") + CALLMETH + SETVAR
body += setget(M, "5") + setget(M, None)[:0]
body += M() + push("tabIndex") + rec(0x96, b'\x02') + SETMEM + M() + push("tabIndex") + GETMEM + TRACE
tags = [g['FILEATTR'], g['BG'], sprite(1, [g['SHOW']]), place, doaction(body), g['SHOW']]
d = os.path.join(here, 't_child_numstr_null'); os.makedirs(d, exist_ok=True)
data = swf(tags, 8)
data = data[:8] + data[8:17] + struct.pack('<HH', 12 << 8, 1) + data[21:]
open(os.path.join(d, 'test.swf'), 'wb').write(data)
open(os.path.join(d, 'test.toml'), 'w').write('num_ticks = 2\n')
print(len(data))
