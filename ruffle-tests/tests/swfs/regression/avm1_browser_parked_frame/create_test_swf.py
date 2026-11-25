#!/usr/bin/env python3
"""avm1_browser_parked_frame — a stopped root's frame tags run ONCE, when the
playhead enters the frame, never again while the root stays parked on it.

Pins down s27 browser-parked-frame: browser-WASM re-ran
frame_funcs[current_frame] every tick while the root was stopped (root DoAction
suppressed, but every PlaceObject/RemoveObject of the parked frame re-executed),
where the CI modes and Flash gate the frame on is_playing. The CI modes always
passed this; tools/browser-test/child_probe is the browser oracle.

Timeline:
  root f1: place `a` (depth 1, x=10) and `b` (depth 2); trace.
  root f2: RemoveObject depth 2 (`b`); place `c` (depth 3, onClipEvent(load));
           place the ticker sprite `t` (depth 10); trace; stop().
  ticker `t` frames, one per tick while the root is parked:
    t1: report; a._x = 50; c.swapDepths(100) (vacates timeline depth 3);
        createEmptyMovieClip("e", -16382) (the depth b vacated).
    t2: report; a.swapDepths(200) (vacates timeline depth 1);
        c.removeMovieClip().
    t3, t4: report; t4 stops.
A parked re-run of root f2 re-places `c` at depth 3 (a second `c load`),
removes `e` (RemoveObject depth 2) and, with the re-run's PlaceObject of the
ticker, nothing else; root f1's `a` is not on the parked frame. Rows report
what sits at each timeline depth after the script moved things away.
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


def push_int(n):
    d = b'\x07' + struct.pack('<i', n)
    return b'\x96' + struct.pack('<H', len(d)) + d


TRACE = b'\x26'
GETVAR = b'\x1c'
GETMEMBER = b'\x4e'
SETMEMBER = b'\x4f'
CALLMETHOD = b'\x52'
POP = b'\x17'
TYPEOF = b'\x44'
ADD2 = b'\x47'
STOP = b'\x07'


def rect():
    nb = 16
    vals = [0, 4000, 0, 4000]
    bits = format(nb, '05b') + ''.join(format(v, '0%db' % nb) for v in vals)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))


def matrix_translate(x, y):
    nb = max(abs(x).bit_length(), abs(y).bit_length()) + 1
    bits = '0' + '0' + format(nb, '05b')
    for v in (x, y):
        bits += format(v & ((1 << nb) - 1), '0%db' % nb)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))


def get(path):
    parts = path.split('.')
    out = push_str(parts[0]) + GETVAR
    for p in parts[1:]:
        out += push_str(p) + GETMEMBER
    return out


def call(path, method, *args):
    """path.method(args) with the result popped. args: int or str."""
    out = b''
    for a in reversed(args):
        out += push_int(a) if isinstance(a, int) else push_str(a)
    out += push_int(len(args)) + get(path) + push_str(method) + CALLMETHOD
    return out


def callv(path, method, *args):
    """path.method(args), result left on the stack."""
    return call(path, method, *args)


def concat(*pieces):
    out = b''
    for i, p in enumerate(pieces):
        if isinstance(p, str):
            out += push_str(p)
        elif p[0] == 'typeof':
            out += get(p[1]) + TYPEOF
        elif p[0] == 'call':
            out += callv(*p[1:])
        elif p[0] == 'typeofcall':
            out += callv(*p[1:]) + TYPEOF
        else:
            out += get(p[1])
        if i:
            out += ADD2
    return out


def trace(*pieces):
    return concat(*pieces) + TRACE


def setm(path, member, n):
    return get(path) + push_str(member) + push_int(n) + SETMEMBER


def clip_actions(ev_flag, actions):
    rec = struct.pack('<I', ev_flag) + struct.pack('<I', len(actions)) + actions
    return struct.pack('<H', 0) + struct.pack('<I', ev_flag) + rec + struct.pack('<I', 0)


def doaction(actions):
    return tag(12, actions + b'\x00')


SHOW = tag(1, b'')


def report(label):
    # what sits at each timeline depth (AS depth = depth - 16384), plus a/c/e
    return trace(label,
                 ' d1=', ('typeofcall', '_root', 'getInstanceAtDepth', -16383),
                 ' d2=', ('typeofcall', '_root', 'getInstanceAtDepth', -16382),
                 ' d3=', ('typeofcall', '_root', 'getInstanceAtDepth', -16381),
                 ' a=', ('typeof', '_root.a'), ' ax=', ('get', '_root.a._x'),
                 ' b=', ('typeof', '_root.b'),
                 ' c=', ('typeof', '_root.c'), ' e=', ('typeof', '_root.e'))


def build():
    t = b''
    t += tag(69, struct.pack('<I', 0))          # FileAttributes
    t += tag(9, b'\xff\xff\xff')                # SetBackgroundColor
    t += tag(39, struct.pack('<HH', 1, 1) + SHOW + tag(0, b''))   # sprite 1: empty box
    ticker = (doaction(report('t1') + setm('_root.a', '_x', 50)
                       + call('_root.c', 'swapDepths', 100)
                       + call('_root', 'createEmptyMovieClip', 'e', -16382)) + SHOW
              + doaction(report('t2') + call('_root.a', 'swapDepths', 200)
                         + call('_root.c', 'removeMovieClip')) + SHOW
              + doaction(report('t3')) + SHOW
              + doaction(report('t4') + STOP) + SHOW + tag(0, b''))
    t += tag(39, struct.pack('<HH', 2, 4) + ticker)
    # root f1
    t += tag(26, bytes([0x26]) + struct.pack('<HH', 1, 1) + matrix_translate(200, 0) + b'a\x00')
    t += tag(26, bytes([0x22]) + struct.pack('<HH', 2, 1) + b'b\x00')
    t += doaction(report('root f1')) + SHOW
    # root f2
    t += tag(28, struct.pack('<H', 2))          # RemoveObject2 depth 2
    load = trace('c load') + b'\x00'
    t += tag(26, bytes([0xA2]) + struct.pack('<HH', 3, 1) + b'c\x00' + clip_actions(0x1, load))
    t += tag(26, bytes([0x22]) + struct.pack('<HH', 10, 2) + b't\x00')
    t += doaction(report('root f2') + STOP) + SHOW
    t += tag(0, b'')
    body = rect() + struct.pack('<HH', 30 << 8, 2) + t
    return b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    open('test.swf', 'wb').write(build())
