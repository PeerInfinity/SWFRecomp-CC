#!/usr/bin/env python3
"""avm1_attach_clipevent_enterframe — onClipEvent(enterFrame) on a child placed
inside an attachMovie'd clip's timeline must fire every frame.

Pins down (session 21, w2-ef-attach): in both CI modes an exported symbol whose
frame 1 PlaceObject2s a child carrying onClipEvent(enterFrame) never fired that
handler once the symbol was instantiated with attachMovie (the same symbol placed
on the root timeline fired correctly). The attached clip's display object lives
in no display-list array, so the per-tick promotion (sprite_initialized 1->2),
the clip-event enterFrame walk and the keep-alive check never reached its
children. Fixed by walking every attachMovie'd clip's standalone child list
(tag.c collect_attached_standalone).

Rows:
  * `ef a`  — child of `_root.a` (ROOT attach, symbol `lib`)
  * `ef b`  — child of `_root.h.b` (NON-root attach into a createEmptyMovieClip
              holder, symbol `lib2`)
  * `a.removeMovieClip()` on frame 3 — `ef a` must stop from then on.
  * `f1`..`f5` frame scripts anchor the per-frame order (enterFrame before
    the frame's DoAction; the attach frame fires no enterFrame).
Expected output is the Ruffle exporter's trace log (5 frames), never ours.
Hand-assembled SWF 8 (MTASC cannot emit onClipEvent clip actions).
"""
import struct


def tag(code, body):
    if len(body) < 63:
        return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body


def push_str(s):
    d = b'\x00' + s.encode() + b'\x00'
    return b'\x96' + struct.pack('<H', len(d)) + d


def push_int(i):
    d = b'\x07' + struct.pack('<i', i)
    return b'\x96' + struct.pack('<H', len(d)) + d


TRACE = b'\x26'
GETVAR = b'\x1c'
CALLMETHOD = b'\x52'
POP = b'\x17'
STOP = b'\x07'


def rect():
    nb = 16
    vals = [0, 4000, 0, 4000]
    bits = format(nb, '05b') + ''.join(format(v, '0%db' % nb) for v in vals)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))


def clip_actions(ev_flag, actions):
    rec = struct.pack('<I', ev_flag) + struct.pack('<I', len(actions)) + actions
    return struct.pack('<H', 0) + struct.pack('<I', ev_flag) + rec + struct.pack('<I', 0)


def call_method(obj_expr, method, args):
    """obj.method(args...) with the result popped. Args pushed right-to-left."""
    out = b''
    for a in reversed(args):
        out += push_int(a) if isinstance(a, int) else push_str(a)
    out += push_int(len(args)) + push_str(obj_expr) + GETVAR + push_str(method) + CALLMETHOD + POP
    return out


def lib_sprite(sprite_id, label):
    ef = push_str('ef ' + label) + TRACE + b'\x00'
    # PlaceObject2 (HasClipActions|HasName|HasCharacter) depth 1, char 1, name "inner"
    po = bytes([0xA2]) + struct.pack('<HH', 1, 1) + b'inner\x00' + clip_actions(0x2, ef)  # 0x2 = EnterFrame
    return tag(39, struct.pack('<HH', sprite_id, 1) + tag(26, po) + tag(1, b'') + tag(0, b''))


def frame(actions):
    return tag(12, actions + b'\x00') + tag(1, b'')


def build():
    t = b''
    t += tag(69, struct.pack('<I', 0))          # FileAttributes
    t += tag(9, b'\xff\xff\xff')                # SetBackgroundColor
    t += tag(39, struct.pack('<HH', 1, 1) + tag(1, b'') + tag(0, b''))  # sprite 1: empty `inner`
    t += lib_sprite(2, 'a')
    t += lib_sprite(3, 'b')
    t += tag(56, struct.pack('<H', 2) + struct.pack('<H', 2) + b'lib\x00'
             + struct.pack('<H', 3) + b'lib2\x00')   # ExportAssets
    t += frame(push_str('f1') + TRACE
               + call_method('_root', 'attachMovie', ['lib', 'a', 1])
               + call_method('_root', 'createEmptyMovieClip', ['h', 5])
               + call_method('_root.h', 'attachMovie', ['lib2', 'b', 1]))
    t += frame(push_str('f2') + TRACE)
    t += frame(push_str('f3') + TRACE + call_method('_root.a', 'removeMovieClip', []))
    t += frame(push_str('f4') + TRACE)
    t += frame(push_str('f5') + TRACE + STOP)
    t += tag(0, b'')
    body = rect() + struct.pack('<HH', 30 << 8, 5) + t
    return b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    open('test.swf', 'wb').write(build())
