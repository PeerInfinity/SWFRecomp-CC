#!/usr/bin/env python3
"""avm1_array_forin_proto: `for (k in <array>)` order when the array's
`__proto__` chain carries ENUMERABLE names (s30 w2-array-forin-proto).

Pins, for an Array, the interleave of own indices / own named props with
inherited enumerable names from Array.prototype and Object.prototype, the
order inside one prototype level, shadowing by an own name, ASSetPropFlags-
unhidden natives (Array.prototype.push, Object.prototype.toString), the own
slots an array exposes after ASSetPropFlags(a, null, 0, 1), a custom
`__proto__`, and a plain Object for comparison.

Hand-assembled (no MTASC in the cloud). Equivalent ActionScript:

    function dump(l, o) { var s = ""; for (var k in o) s += k + ","; trace(l + ": " + s); }
    a = new Array(); a[0] = "x"; a[1] = "y"; a.foo = "f";       dump("A0", a);
    Array.prototype.ap = 1; Array.prototype.aq = 2;              dump("A1", a);
    Object.prototype.op = 1;                                     dump("A2", a);
    b = [10, 20]; b.bar = 1;                                     dump("B", b);
    a.ap = 5;                                                    dump("C", a);
    ASSetPropFlags(Array.prototype, "push", 0, 1);               dump("D", a);
    ASSetPropFlags(Object.prototype, "toString", 0, 1);          dump("E", a);
    o = {}; o.z = 1;                                             dump("G", o);
    c = []; c[0] = 1; c.__proto__ = {pp: 1};                     dump("H", c);
    n = new Array(); ASSetPropFlags(n, null, 0, 1);              dump("F", n);
    l = {}; AsBroadcaster.initialize(l); ll = l._listeners;      dump("L0", ll);
    ASSetPropFlags(ll, null, 0, 1);                              dump("L1", ll);
    delete Array.prototype.ap; delete Array.prototype.aq; delete Object.prototype.op;
    ASSetPropFlags(Array.prototype, "push", 1, 0);
    ASSetPropFlags(Object.prototype, "toString", 1, 0);          dump("Z", a);

SWF 5 uses the legacy Enumerate (0x46) opcode; SWF 6+ uses Enumerate2.

Usage: create_test_swf.py <swf_version> <out.swf>   (5, 6, 8 shipped)
"""
import struct
import sys


def tag(code, data):
    if len(data) < 63:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data


def z(x):
    return x.encode() + b'\0'


NULL = object()


def push(*items):
    b = b''
    for it in items:
        if it is NULL:
            b += b'\x02'
        elif isinstance(it, tuple) and it[0] == 'reg':
            b += b'\x04' + bytes([it[1]])
        elif isinstance(it, str):
            b += b'\x00' + z(it)
        elif isinstance(it, int):
            b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b


GV = b'\x1c'; SV = b'\x1d'; GM = b'\x4e'; SM = b'\x4f'; TR = b'\x26'
ADD2 = b'\x47'; EQ2 = b'\x49'; NEWOBJ = b'\x40'; INITARR = b'\x42'
INITOBJ = b'\x43'; CALLF = b'\x3d'; POP = b'\x17'; DEL = b'\x3a'
ENUM2 = b'\x55'


def jump(op, off):
    return op + struct.pack('<Hh', 2, off)


def dump(label, var):
    code = push('s', '') + SV
    if VER <= 5:
        code += push(var) + b'\x46'          # legacy Enumerate (by name)
    else:
        code += push(var) + GV + ENUM2
    body = push('s', 's') + GV + push(('reg', 0)) + ADD2 + push(',') + ADD2 + SV
    head = b'\x87\x01\x00\x00' + push(NULL) + EQ2   # StoreRegister 0
    jmp_back_len = 5
    if_rec = jump(b'\x9d', len(body) + jmp_back_len)
    loop = head + if_rec + body
    loop += jump(b'\x99', -(len(loop) + jmp_back_len))
    code += loop
    code += push(label + ': ', 's') + GV + ADD2 + TR
    return code


def setm(objvar, name, val, path=None):
    c = push(objvar) + GV
    if path:
        c += push(path) + GM
    return c + push(name, val) + SM


def aspf(objvar, path, props, n, allow):
    c = push(allow, n, props)
    c += push(objvar) + GV
    if path:
        c += push(path) + GM
    return c + push(4, 'ASSetPropFlags') + CALLF + POP


def delm(objvar, path, name):
    return push(objvar) + GV + push(path) + GM + push(name) + DEL + POP


VER = int(sys.argv[1])
code = b''
code += push('a', 0, 'Array') + NEWOBJ + SV
code += setm('a', '0', 'x') + setm('a', '1', 'y') + setm('a', 'foo', 'f')
code += dump('A0', 'a')
code += setm('Array', 'ap', 1, 'prototype') + setm('Array', 'aq', 2, 'prototype')
code += dump('A1', 'a')
code += setm('Object', 'op', 1, 'prototype')
code += dump('A2', 'a')
code += push('b', 20, 10, 2) + INITARR + SV + setm('b', 'bar', 1)
code += dump('B', 'b')
code += setm('a', 'ap', 5)
code += dump('C', 'a')
code += aspf('Array', 'prototype', 'push', 0, 1)
code += dump('D', 'a')
code += aspf('Object', 'prototype', 'toString', 0, 1)
code += dump('E', 'a')
code += push('o', 0) + INITOBJ + SV + setm('o', 'z', 1)
code += dump('G', 'o')
code += push('c', 0) + INITARR + SV + setm('c', '0', 1)
code += push('c') + GV + push('__proto__', 'pp', 1, 1) + INITOBJ + SM
code += dump('H', 'c')
code += push('n', 0, 'Array') + NEWOBJ + SV
code += aspf('n', None, NULL, 0, 1)
code += dump('F', 'n')
code += push('l', 0) + INITOBJ + SV
code += push('l') + GV + push(1, 'AsBroadcaster') + GV + push('initialize') + b'\x52' + POP
code += push('ll', 'l') + GV + push('_listeners') + GM + SV
code += dump('L0', 'll')
code += aspf('ll', None, NULL, 0, 1)
code += dump('L1', 'll')
code += delm('Array', 'prototype', 'ap') + delm('Array', 'prototype', 'aq')
code += delm('Object', 'prototype', 'op')
code += aspf('Array', 'prototype', 'push', 1, 0)
code += aspf('Object', 'prototype', 'toString', 1, 0)
code += dump('Z', 'a')
code += push('done') + TR

ver = VER
body = tag(9, b'\xff\xff\xff') + tag(12, code + b'\0') + tag(1, b'') + tag(0, b'')
if ver >= 8:
    body = tag(69, struct.pack('<I', 0)) + body
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr = rect + struct.pack('<HH', 30 << 8, 1)
open(sys.argv[2], 'wb').write(b'FWS' + bytes([ver]) + struct.pack('<I', 8 + len(hdr) + len(body)) + hdr + body)
