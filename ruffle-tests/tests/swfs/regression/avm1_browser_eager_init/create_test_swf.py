#!/usr/bin/env python3
"""avm1_browser_eager_init — a sprite placed on frame N is fully built
(children placed, frame-1 script queued) before frame N's own DoAction runs,
and is not advanced again on its placement tick.

Pins down s27 browser-eager-init: browser-WASM built sprite children LAZILY
(inside tagShowFrame's advance_sprite_frames, after the frame's scripts), so a
frame-N script saw no children of a frame-N sprite and onClipEvent(load) was
deferred to a browser-only AQ_KIND_LOAD drain. The CI modes always built them
eagerly; this fixture is graded in CI (where it already passed) and is the
browser oracle in tools/browser-test/child_probe (where it did not).

Rows:
  * `load ...`      — onClipEvent(load) on `outer` sees its frame-1 child.
  * `outer f1 ...`  — the sprite's own frame-1 script sees its child.
  * `inner f1`      — the nested sprite's frame-1 script, same tick.
  * `root f1 ...`   — the root frame-1 script sees outer.inner and both
                      playheads at 1.
  * `root f2/f3 ...`, `outer f2/f3` — the next ticks: every timeline
    advances exactly once per tick (a double advance on the placement tick
    would show outer at 2 in `root f1`, or `outer f2` early). The browser
    still fails `root f2`/`root f3`: it advances timeline sprites inside
    tagShowFrame, AFTER the root DoAction, so the root reads last tick's
    playheads (Flash: outer f2 before root f2). That per-tick order is the
    next browser slice (s27 browser-eager-init report).

Not traced on purpose: a nested sprite's own frame-2 script. Flash/Ruffle run
it BEFORE its parent's (`inner f2, outer f2, root f2`); both CI modes run it
after the root (`outer f2, root f2, inner f2`, Phase-3 nested advance). That is
a separate CI exec-order lead (same report), kept out so this row stays green.
Expected output is the Flash 32 projector trace, never ours.
Hand-assembled SWF 8 (MTASC cannot emit timeline sprites or clip actions).
"""
import struct


def tag(code, body):
    if len(body) < 63:
        return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body


def push_str(s):
    d = b'\x00' + s.encode() + b'\x00'
    return b'\x96' + struct.pack('<H', len(d)) + d


TRACE = b'\x26'
GETVAR = b'\x1c'
GETMEMBER = b'\x4e'
TYPEOF = b'\x44'
ADD2 = b'\x47'
STOP = b'\x07'


def rect():
    nb = 16
    vals = [0, 4000, 0, 4000]
    bits = format(nb, '05b') + ''.join(format(v, '0%db' % nb) for v in vals)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))


def get(path):
    """Push the value of a dotted path: first name via GetVariable, rest via GetMember."""
    parts = path.split('.')
    out = push_str(parts[0]) + GETVAR
    for p in parts[1:]:
        out += push_str(p) + GETMEMBER
    return out


def concat(*pieces):
    """pieces: str literal, or ('typeof', path) / ('get', path). Joined with Add2."""
    out = b''
    for i, p in enumerate(pieces):
        if isinstance(p, str):
            out += push_str(p)
        elif p[0] == 'typeof':
            out += get(p[1]) + TYPEOF
        else:
            out += get(p[1])
        if i:
            out += ADD2
    return out


def trace(*pieces):
    return concat(*pieces) + TRACE


def clip_actions(ev_flag, actions):
    rec = struct.pack('<I', ev_flag) + struct.pack('<I', len(actions)) + actions
    return struct.pack('<H', 0) + struct.pack('<I', ev_flag) + rec + struct.pack('<I', 0)


def doaction(actions):
    return tag(12, actions + b'\x00')


SHOW = tag(1, b'')


def build():
    t = b''
    t += tag(69, struct.pack('<I', 0))          # FileAttributes
    t += tag(9, b'\xff\xff\xff')                # SetBackgroundColor
    # sprite 1 `inner`: frame 1 traces, frame 2 stops (bounded trace). Frame 2 has
    # no trace on purpose: see the docstring's note on nested frame-script order.
    inner = (doaction(trace('inner f1')) + SHOW
             + doaction(STOP) + SHOW + tag(0, b''))
    t += tag(39, struct.pack('<HH', 1, 2) + inner)
    # sprite 2 `outer`: frame 1 places `inner` then traces what it sees; 3 frames, stops on 3.
    po_inner = bytes([0x22]) + struct.pack('<HH', 1, 1) + b'inner\x00'   # HasName|HasCharacter
    outer = (tag(26, po_inner)
             + doaction(trace('outer f1 ', ('typeof', 'this.inner'), ' ', ('get', 'this.inner._currentframe'))) + SHOW
             + doaction(trace('outer f2')) + SHOW
             + doaction(trace('outer f3') + STOP) + SHOW + tag(0, b''))
    t += tag(39, struct.pack('<HH', 2, 3) + outer)
    # Root frame 1: place `outer` with onClipEvent(load), then the frame script.
    load = trace('load ', ('typeof', 'this.inner'), ' ', ('get', 'this.inner._currentframe')) + b'\x00'
    po_outer = bytes([0xA2]) + struct.pack('<HH', 1, 2) + b'outer\x00' + clip_actions(0x1, load)  # 0x1 = Load
    t += tag(26, po_outer)
    t += doaction(trace('root f1 ', ('typeof', 'outer.inner'), ' ', ('get', 'outer._currentframe'),
                        ' ', ('get', 'outer.inner._currentframe'))) + SHOW
    for f in (2, 3):
        t += doaction(trace('root f%d ' % f, ('get', 'outer._currentframe'), ' ',
                            ('get', 'outer.inner._currentframe'))) + SHOW
    t += doaction(trace('root f4') + STOP) + SHOW
    t += tag(0, b'')
    body = rect() + struct.pack('<HH', 30 << 8, 4) + t
    return b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    open('test.swf', 'wb').write(build())
