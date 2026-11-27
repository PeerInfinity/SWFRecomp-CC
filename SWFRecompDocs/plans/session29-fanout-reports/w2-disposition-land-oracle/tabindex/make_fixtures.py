#!/usr/bin/env python3
"""s29 w2-disposition-land: isolate the FP32 tabIndex raw-vs-coerce discriminator.

The corpus row avm1/tab_ordering_properties_tab_index_edge_case (SWF8, root frame DoAction,
`this.tabIndex = "asdf"`) reads back RAW in FP32; the MTASC fixture L3b_tabindex_v8 (DoInitAction
class, static main, `var r = _root; r.tabIndex = "s"`) COERCES. Each fixture below changes ONE
thing relative to the corpus SWF. Run: python3 make_fixtures.py  -> tNN_*/test.swf (+ test.toml).
"""
import os, struct

def s(x): return x.encode('latin1') + b'\0'
def rec(code, payload=b''):
    return bytes([code]) + (struct.pack('<H', len(payload)) + payload if code >= 0x80 else b'')
def push(*items):
    p = b''
    for it in items:
        if isinstance(it, str): p += b'\x00' + s(it)
        elif isinstance(it, int): p += b'\x07' + struct.pack('<i', it)
        elif isinstance(it, tuple) and it[0] == 'r': p += b'\x04' + bytes([it[1]])
        elif it is None: p += b'\x03'
    return rec(0x96, p)
GETVAR, SETVAR, GETMEM, SETMEM, TRACE, POP = (rec(0x1c), rec(0x1d), rec(0x4e), rec(0x4f), rec(0x26), rec(0x17))
CALLFN, CALLMETH = rec(0x3d), rec(0x52)
def storereg(n): return rec(0x87, bytes([n]))

VALUES = ["asdf", "asdf2", 5, "asdf3"]

def body_target(get_target):
    """set/trace sequence of the corpus row; get_target() yields bytes pushing the target object."""
    b = b''
    for v in VALUES:
        b += get_target() + push("tabIndex", v) + SETMEM
        b += get_target() + push("tabIndex") + GETMEM + TRACE
    return b

T_THIS = lambda: push("this") + GETVAR
T_ROOT = lambda: push("_root") + GETVAR
T_REG1 = lambda: push(('r', 1))

def deffn2(name, body, flags=0, regs=4):
    p = s(name) + struct.pack('<HBH', 0, regs, flags) + struct.pack('<H', len(body))
    return rec(0x8e, p) + body
def deffn1(name, body):
    p = s(name) + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return rec(0x9b, p) + body
def call0(name): return push(0, name) + CALLFN + POP

def tag(code, payload):
    if len(payload) < 63: return struct.pack('<H', (code << 6) | len(payload)) + payload
    return struct.pack('<HI', (code << 6) | 63, len(payload)) + payload
def doaction(actions): return tag(12, actions + b'\0')
FILEATTR = tag(69, b'\0\0\0\0')
BG = tag(9, b'\xff\xff\xff')
SHOW = tag(1, b'')
def swf(tags, version=8):
    rect = bytes([0x78, 0x00, 0x05, 0x5f, 0x00, 0x00, 0x0f, 0xa0, 0x00])  # 0..550 x 0..400 twips*20 (corpus RECT)
    b = rect + struct.pack('<HH', 12 << 8, 1) + b''.join(tags) + tag(0, b'')
    return b'FWS' + bytes([version]) + struct.pack('<I', 8 + len(b)) + b

def sprite(cid, tags):  # DefineSprite with 1 frame
    return tag(39, struct.pack('<HH', cid, 1) + b''.join(tags) + tag(0, b''))
def export(cid, name): return tag(56, struct.pack('<H', 1) + struct.pack('<H', cid) + s(name))
def initaction(cid, actions): return tag(59, struct.pack('<H', cid) + actions + b'\0')

F = {}
F['t00_corpus_replica'] = ("corpus bytecode re-assembled (sanity: must print the raw golden)",
    [FILEATTR, BG, doaction(body_target(T_THIS)), SHOW], 8)
F['t01_no_fileattributes'] = ("t00 minus the FileAttributes tag (L3b has none)",
    [BG, doaction(body_target(T_THIS)), SHOW], 8)
F['t02_root_getvariable'] = ("target = GetVariable _root instead of this (frame scope)",
    [FILEATTR, BG, doaction(body_target(T_ROOT)), SHOW], 8)
F['t03_this_in_register'] = ("target = this, stored in global register 1 (frame scope)",
    [FILEATTR, BG, doaction(T_THIS() + storereg(1) + POP + body_target(T_REG1)), SHOW], 8)
F['t04_fn2_root'] = ("t02 body inside a DefineFunction2 (flags 0) called from the frame",
    [FILEATTR, BG, doaction(deffn2("f", body_target(T_ROOT)) + call0("f")), SHOW], 8)
F['t05_fn1_root'] = ("t02 body inside a DefineFunction (v1) called from the frame",
    [FILEATTR, BG, doaction(deffn1("f", body_target(T_ROOT)) + call0("f")), SHOW], 8)
F['t06_fn2_reg_root'] = ("t04 with _root in a function register (MTASC shape: GetVariable _root; StoreRegister 1)",
    [FILEATTR, BG, doaction(deffn2("f", T_ROOT() + storereg(1) + POP + body_target(T_REG1)) + call0("f")), SHOW], 8)
F['t07_initaction_root'] = ("t02 body in a DoInitAction of an exported sprite (runs before frame 1 DoAction)",
    [FILEATTR, BG, sprite(1, [SHOW]), export(1, "__Packages.X"), initaction(1, body_target(T_ROOT)), SHOW], 8)
F['t08_fresh_child_frame'] = ("frame scope, fresh createEmptyMovieClip('m',1) child as target",
    [FILEATTR, BG, doaction(push(1, "m", 2, "this") + GETVAR + push("createEmptyMovieClip") + CALLMETH + POP
                            + body_target(lambda: push("m") + GETVAR)), SHOW], 8)
F['t09_corpus_v6'] = ("t00 with SWF version 6", [FILEATTR, BG, doaction(body_target(T_THIS)), SHOW], 6)
F['t10_corpus_v7'] = ("t00 with SWF version 7", [FILEATTR, BG, doaction(body_target(T_THIS)), SHOW], 7)
F['t11_read_first'] = ("t00 preceded by trace(this.tabIndex) (a read before the first set)",
    [FILEATTR, BG, doaction(T_THIS() + push("tabIndex") + GETMEM + TRACE + body_target(T_THIS)), SHOW], 8)
F['t12_frame2'] = ("t00 body on frame 2 instead of frame 1 (frame 1 empty)",
    [FILEATTR, BG, SHOW, doaction(body_target(T_THIS) + rec(0x07)), SHOW], 8)

here = os.path.dirname(os.path.abspath(__file__))
for name, (desc, tags, ver) in F.items():
    d = os.path.join(here, name); os.makedirs(d, exist_ok=True)
    frames = sum(1 for t in tags if t == SHOW)
    data = swf(tags, ver)
    if name != 't12_frame2':
        data = data[:8] + data[8:17] + struct.pack('<HH', 12 << 8, 1) + data[21:]
    else:
        data = data[:8] + data[8:17] + struct.pack('<HH', 12 << 8, 2) + data[21:]
    open(os.path.join(d, 'test.swf'), 'wb').write(data)
    open(os.path.join(d, 'test.toml'), 'w').write('num_ticks = %d\n' % (frames + 1))
    open(os.path.join(d, 'README.txt'), 'w').write(desc + '\n')
    print(name, len(data), desc)
