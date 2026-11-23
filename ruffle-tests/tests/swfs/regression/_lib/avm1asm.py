"""Tiny AVM1 SWF assembler shared by the s26 loaded-shell regression fixtures.

Not a test directory (no test.swf): verify_output.py's discovery skips it.
Every generator that imports this does `sys.path.insert(0, HERE.parent / '_lib')`.

Only what the fixtures need: uncompressed SWF, sprites, PlaceObject2 (with
optional onClipEvent records), RemoveObject2, DoAction, and the action records
for push / variables / members / method calls / trace / string concat / goto.
"""
import struct


# ---------------------------------------------------------------- tags
def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


class Bits:
    def __init__(self):
        self.bits = []

    def u(self, value, n):
        for i in range(n - 1, -1, -1):
            self.bits.append((value >> i) & 1)
        return self

    def s(self, value, n):
        return self.u(value & ((1 << n) - 1), n)

    def bytes(self):
        out = bytearray()
        for i in range(0, len(self.bits), 8):
            chunk = self.bits[i:i + 8]
            byte = 0
            for b in chunk:
                byte = (byte << 1) | b
            byte <<= (8 - len(chunk))
            out.append(byte)
        return bytes(out)


def matrix_translate(tx, ty):
    nbits = max(tx.bit_length(), ty.bit_length(), 1) + 1
    return Bits().u(0, 1).u(0, 1).u(nbits, 5).s(tx, nbits).s(ty, nbits).bytes()


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, frames_bodies):
    """frames_bodies: list of per-frame tag bytes (ShowFrame appended)."""
    body = b''.join(fb + show_frame() for fb in frames_bodies) + end_tag()
    return tag(39, struct.pack('<HH', char_id, len(frames_bodies)) + body)


def define_shape_rect(char_id, w_px, h_px, rgb=(255, 0, 0)):
    """DefineShape (code 2): one solid-filled rectangle (0,0)-(w,h)."""
    w, h = w_px * 20, h_px * 20
    nb = max(w.bit_length(), h.bit_length()) + 1
    rect = Bits().u(nb, 5).s(0, nb).s(w, nb).s(0, nb).s(h, nb).bytes()
    fills = bytes([1, 0x00]) + bytes(rgb)          # 1 solid fill
    lines = bytes([0])                              # no line styles
    b = Bits().u(1, 4).u(0, 4)                      # NumFillBits=1, NumLineBits=0
    # StyleChange: MoveTo + FillStyle0 (flags: StateMoveTo=1, StateFillStyle0=1)
    mb = nb
    b.u(0, 1).u(0, 1).u(0, 1).u(0, 1).u(1, 1).u(1, 1)
    b.u(mb, 5).s(0, mb).s(0, mb)
    b.u(1, 1)                                       # FillStyle0 = 1
    def straight(dx, dy):
        n = max(abs(dx).bit_length(), abs(dy).bit_length()) + 1
        b.u(1, 1).u(1, 1).u(n - 2, 4)
        if dx != 0 and dy != 0:
            b.u(1, 1).s(dx, n).s(dy, n)
        elif dx != 0:
            b.u(0, 1).u(0, 1).s(dx, n)
        else:
            b.u(0, 1).u(1, 1).s(dy, n)
    straight(w, 0)
    straight(0, h)
    straight(-w, 0)
    straight(0, -h)
    b.u(0, 1).u(0, 5)                               # EndShapeRecord
    return tag(2, struct.pack('<H', char_id) + rect + fills + lines + b.bytes())


# PlaceObject2 clip-event flags (SWF6+ 32-bit form).
EV_LOAD = 0x00000001
EV_ENTER_FRAME = 0x00000002
EV_UNLOAD = 0x00000004


def place_object2(depth, char_id=None, name=None, tx=None, ty=None,
                  move=False, clip_actions=None, swf_version=8):
    """clip_actions: list of (event_flags, action_bytes_without_end)."""
    flags = 0
    if move:
        flags |= 0x01
    if char_id is not None:
        flags |= 0x02
    if tx is not None:
        flags |= 0x04
    if name is not None:
        flags |= 0x20
    if clip_actions:
        flags |= 0x80
    data = struct.pack('<BH', flags, depth)
    if char_id is not None:
        data += struct.pack('<H', char_id)
    if tx is not None:
        data += matrix_translate(tx, ty)
    if name is not None:
        data += name.encode('ascii') + b'\x00'
    if clip_actions:
        assert swf_version >= 6
        all_flags = 0
        for f, _ in clip_actions:
            all_flags |= f
        data += struct.pack('<HI', 0, all_flags)
        for f, body in clip_actions:
            body = body + b'\x00'
            data += struct.pack('<II', f, len(body)) + body
        data += struct.pack('<I', 0)
    return tag(26, data)


def remove_object2(depth):
    return tag(28, struct.pack('<H', depth))


def do_action(body):
    return tag(12, body + b'\x00')


def swf_file(path, frames, version=8, frame_rate=30, w=200, h=200, prefix=b''):
    """frames: list of per-frame tag bytes. `prefix` goes before frame 1
    (definitions). Writes an uncompressed SWF."""
    W, H = w * 20, h * 20
    nb = max(W.bit_length(), H.bit_length()) + 1
    rect = Bits().u(nb, 5).s(0, nb).s(W, nb).s(0, nb).s(H, nb).bytes()
    tags = tag(9, bytes([255, 255, 255]))           # SetBackgroundColor
    tags += prefix
    tags += b''.join(f + show_frame() for f in frames) + end_tag()
    body = rect + struct.pack('<H', frame_rate << 8) + struct.pack('<H', len(frames)) + tags
    length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', version, length) + body)
    print(f'Created {path} (SWF{version}, {len(frames)} frames, {length} bytes)')


# ------------------------------------------------------------- actions
def _rec(code, payload=b''):
    if code < 0x80:
        return bytes([code])
    return bytes([code]) + struct.pack('<H', len(payload)) + payload


def push(*vals):
    """Push strings, ints, floats, True/False, None (=null) in order."""
    p = b''
    for v in vals:
        if v is None:
            p += b'\x02'
        elif v is True or v is False:
            p += b'\x05' + bytes([1 if v else 0])
        elif isinstance(v, int):
            p += b'\x07' + struct.pack('<i', v)
        elif isinstance(v, float):
            p += b'\x06' + struct.pack('<d', v)[4:] + struct.pack('<d', v)[:4]
        else:
            p += b'\x00' + v.encode('latin-1') + b'\x00'
    return _rec(0x96, p)


POP = _rec(0x17)
TRACE = _rec(0x26)
ADD2 = _rec(0x47)
GET_VARIABLE = _rec(0x1C)
SET_VARIABLE = _rec(0x1D)
GET_MEMBER = _rec(0x4E)
SET_MEMBER = _rec(0x4F)
CALL_METHOD = _rec(0x52)
CALL_FUNCTION = _rec(0x3D)
TYPEOF = _rec(0x44)
EQUALS2 = _rec(0x49)
STRICT_EQUALS = _rec(0x66)
STOP = _rec(0x07)
PLAY = _rec(0x06)
NEXT_FRAME = _rec(0x04)
PREV_FRAME = _rec(0x05)
ENUMERATE2 = _rec(0x55)
TARGET_PATH = _rec(0x45)


def goto_frame(frame0):
    """ActionGotoFrame (0x81): bare gotoAndStop(frame0+1) is GotoFrame+Stop."""
    return _rec(0x81, struct.pack('<H', frame0))


def trace_str(s):
    return push(s) + TRACE


def get_var(name):
    return push(name) + GET_VARIABLE


def get_path(*parts):
    """get_path('h', '_currentframe') => h._currentframe via GetVariable+GetMember."""
    code = get_var(parts[0])
    for p in parts[1:]:
        code += push(p) + GET_MEMBER
    return code


def concat(*pieces):
    """Each piece: a literal str, or bytes (code leaving one value on the stack).
    Emits left-to-right Add2 (string + anything)."""
    code = b''
    for i, pc in enumerate(pieces):
        code += push(pc) if isinstance(pc, str) else pc
        if i > 0:
            code += ADD2
    return code


def trace_expr(*pieces):
    return concat(*pieces) + TRACE


def call_method(obj_code, method, *args_code, discard=True):
    """obj.method(args...). args_code: bytes or literal values."""
    code = b''
    for a in reversed(args_code):
        code += a if isinstance(a, bytes) else push(a)
    code += push(len(args_code)) + obj_code + push(method) + CALL_METHOD
    if discard:
        code += POP
    return code


def set_member(obj_code, name, value_code):
    return obj_code + push(name) + (value_code if isinstance(value_code, bytes) else push(value_code)) + SET_MEMBER


def set_var(name, value_code):
    return push(name) + (value_code if isinstance(value_code, bytes) else push(value_code)) + SET_VARIABLE


# ------------------------------------------------------- branches / regs
def store_register(r):
    return _rec(0x87, bytes([r]))


def push_register(r):
    return _rec(0x96, b'\x04' + bytes([r]))


def _jump_like(code, offset):
    return _rec(code, struct.pack('<h', offset))


def if_(offset):
    return _jump_like(0x9D, offset)


def jump(offset):
    return _jump_like(0x99, offset)


def for_in_concat(obj_code, var_name, sep=','):
    """var_name = ''; for (k in obj) var_name = var_name + k + sep;"""
    head = set_var(var_name, '') + obj_code + ENUMERATE2
    # loop body (after the If): var_name = var_name + r0 + sep
    body = push(var_name) + get_var(var_name) + push_register(0) + ADD2 + push(sep) + ADD2 + SET_VARIABLE
    test = store_register(0) + push(None) + EQUALS2
    # If jumps over body + the back jump (5 bytes)
    loop = test + if_(len(body) + 5) + body
    back = jump(-(len(loop) + 5))
    return head + loop + back
