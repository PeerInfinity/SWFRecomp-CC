"""Tiny AVM1 / SWF assembler shared by the s26 w1-avm1-dispatch-scope fixtures.

Every helper returns raw bytes. Stdlib only. Names follow the SWF spec.
"""
import struct


def tag(code, data):
    if len(data) < 63 and code not in (20, 21, 35, 36):
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data


def s(x):
    return x.encode('utf-8') + b'\0'


class Reg:
    def __init__(self, n):
        self.n = n


UNDEF = object()
NULL = object()


def push(*items):
    b = b''
    for it in items:
        if isinstance(it, Reg):
            b += b'\x04' + bytes([it.n])
        elif it is UNDEF:
            b += b'\x03'
        elif it is NULL:
            b += b'\x02'
        elif isinstance(it, bool):
            b += b'\x05' + bytes([1 if it else 0])
        elif isinstance(it, str):
            b += b'\x00' + s(it)
        elif isinstance(it, int):
            b += b'\x07' + struct.pack('<i', it)
        elif isinstance(it, float):
            b += b'\x06' + struct.pack('<d', it)[4:] + struct.pack('<d', it)[:4]
        else:
            raise TypeError(it)
    return b'\x96' + struct.pack('<H', len(b)) + b


def op(code, payload=b''):
    if code >= 0x80:
        return bytes([code]) + struct.pack('<H', len(payload)) + payload
    return bytes([code])


GETVAR = op(0x1c)
SETVAR = op(0x1d)
GETMEM = op(0x4e)
SETMEM = op(0x4f)
ADD2 = op(0x47)
TRACE = op(0x26)
STOP = op(0x07)
POP = op(0x17)
CALLM = op(0x52)
CALLF = op(0x3d)
TYPEOF = op(0x44)
INITOBJ = op(0x43)
DEFLOCAL = op(0x3c)
RETURN = op(0x3e)
NEWOBJ = op(0x40)
EQ2 = op(0x49)


def settarget(name):
    return op(0x8b, s(name))


def with_block(body):
    return op(0x94, struct.pack('<H', len(body))) + body


PRELOAD_THIS = 0x0001
SUPPRESS_THIS = 0x0002
PRELOAD_ARGUMENTS = 0x0004


def deffunc2(name, params, body, nregs=4, flags=0, first_param_reg=1):
    """DefineFunction2; params in registers first_param_reg.. (0 = by name).
    flags: PRELOAD_THIS puts this in r1, so pass first_param_reg=2."""
    p = s(name) + struct.pack('<HBH', len(params), nregs, flags)
    for i, pn in enumerate(params):
        p += bytes([(i + first_param_reg) if first_param_reg else 0]) + s(pn)
    p += struct.pack('<H', len(body))
    return op(0x8e, p) + body


def deffunc1(name, params, body):
    p = s(name) + struct.pack('<H', len(params))
    for pn in params:
        p += s(pn)
    p += struct.pack('<H', len(body))
    return op(0x9b, p) + body


def get(path):
    """Push the value at a dotted path: a.b.c -> GetVariable a, GetMember b, c."""
    parts = path.split('.')
    code = push(parts[0]) + GETVAR
    for q in parts[1:]:
        code += push(q) + GETMEM
    return code


def callm(target, meth, *args, keep=False):
    """target.meth(args) via CallMethod; pops the result unless keep."""
    code = push(*reversed(args)) if args else b''
    code += push(len(args)) + get(target) + push(meth) + CALLM
    return code if keep else code + POP


def callf(name, *args, keep=False):
    """bare name(args) via CallFunction; pops the result unless keep."""
    code = push(*reversed(args)) if args else b''
    code += push(len(args), name) + CALLF
    return code if keep else code + POP


def trace_concat(*parts):
    """trace(p0 + p1 + ...): str parts are literals, bytes parts are code that
    leaves one value on the stack."""
    code = b''
    first = True
    for p in parts:
        code += push(p) if isinstance(p, str) else p
        if not first:
            code += ADD2
        first = False
    return code + TRACE


def typeof_(path):
    return get(path) + TYPEOF


def doaction(a):
    return tag(12, a + b'\0')


def place(depth, cid, name, x=0, y=0):
    flags = 0x02 | 0x20
    data = struct.pack('<HH', depth, cid)
    if x or y:
        flags |= 0x04
        data += matrix_translate(x, y)
    return tag(26, bytes([flags]) + data + s(name))


def matrix_translate(x, y):
    tx, ty = int(x * 20), int(y * 20)
    nb = max(abs(tx).bit_length(), abs(ty).bit_length()) + 1
    bits = '0' + '0' + '{:05b}'.format(nb)
    for v in (tx, ty):
        bits += format(v & ((1 << nb) - 1), '0{}b'.format(nb))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


def export(cid, name):
    return tag(56, struct.pack('<HH', 1, cid) + s(name))


def rect(xmin, xmax, ymin, ymax):
    vals = (xmin, xmax, ymin, ymax)
    nb = max(max(abs(v).bit_length() for v in vals) + 1, 1)
    bits = '{:05b}'.format(nb) + ''.join(format(v & ((1 << nb) - 1), '0{}b'.format(nb)) for v in vals)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')


def swf(version, defs, root_frames, w=400, h=300, fps=30, as3=False):
    body = (tag(69, struct.pack('<I', 0x08 if as3 else 0)) + tag(9, b'\xff\xff\xff') + defs
            + b''.join(f + SHOW for f in root_frames) + tag(0, b''))
    hdr_rest = rect(0, w * 20, 0, h * 20) + struct.pack('<HH', fps << 8, len(root_frames))
    total = 8 + len(hdr_rest) + len(body)
    return b'FWS' + bytes([version]) + struct.pack('<I', total) + hdr_rest + body
