#!/usr/bin/env python3
"""s30 w2b-native-residues FLASH probe (LOCAL ORACLE REQUEST 1).

One line each: the SWF6+ Object.prototype methods (hasOwnProperty, isPropertyEnumerable,
isPrototypeOf, addProperty, watch, unwatch) seen through five receiver kinds (function, plain
object, array, _root clip, string); the ASnative proto-less function (typeof of every
Function/Object.prototype member, a hasOwnProperty / toString call through it, instanceof);
`Object` constructor identity vs `_global.Object` (L2); `_global.hasOwnProperty` (L3).
Hand-assembled (regression/_lib/avm1asm.py), uncompressed.

Usage: mk_residue_probe.py <out.swf> <swf_version>
"""
import sys, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[4] / 'ruffle-tests/tests/swfs/regression/_lib'))
from avm1asm import *
G = lambda *p: get_path(*p)
INIT_ARRAY = bytes([0x42]); INIT_OBJECT = bytes([0x43]); INSTANCEOF = bytes([0x54]); NEW_OBJECT = bytes([0x40])
c = b''
c += set_var('fo', G('Array'))
c += set_var('oo', push(0) + INIT_OBJECT)
c += set_var('ao', push(0) + INIT_ARRAY)
c += set_var('so', push('str'))
c += set_member(get_var('oo'), 'x', push(1))
recv = [('function', get_var('fo')), ('object', get_var('oo')), ('array', get_var('ao')),
        ('clip', get_var('_root')), ('string', get_var('so'))]
meths = ['hasOwnProperty', 'isPropertyEnumerable', 'isPrototypeOf', 'addProperty', 'watch', 'unwatch']
for rn, rc in recv:
    pieces = [rn + ':']
    for m in meths:
        pieces += [' ' + m + '=', rc + push(m) + GET_MEMBER + TYPEOF]
    c += trace_expr(*pieces)
    c += trace_expr(rn + ' hOP(x) call: ', call_method(rc, 'hasOwnProperty', 'x', discard=False),
                    ' isPE(x) call: ', call_method(rc, 'isPropertyEnumerable', 'x', discard=False))
an = G('ASnative')
pieces = ['ASnative typeof:', an + TYPEOF]
for m in ['__proto__', 'constructor', 'prototype', 'call', 'apply', 'toString', 'valueOf', 'hasOwnProperty', 'addProperty']:
    pieces += [' ' + m + '=', an + push(m) + GET_MEMBER + TYPEOF]
c += trace_expr(*pieces)
c += trace_expr('ASnative hOP call: ', call_method(an, 'hasOwnProperty', 'x', discard=False),
                ' toString call: ', call_method(an, 'toString', discard=False),
                ' instanceof Function: ', an + G('Function') + INSTANCEOF,
                ' instanceof Object: ', an + G('Object') + INSTANCEOF)
c += trace_expr('ASnative(2,0) typeof: ', push(0, 2, 2, 'ASnative') + CALL_FUNCTION + TYPEOF)
# L2: Object identity
c += trace_expr('Object===_global.Object: ', G('Object') + G('_global', 'Object') + STRICT_EQUALS)
c += trace_expr('Key.constructor===_global.Object: ', G('Key', 'constructor') + G('_global', 'Object') + STRICT_EQUALS)
c += trace_expr('({}).constructor===_global.Object: ', push(0) + INIT_OBJECT + push('constructor') + GET_MEMBER + G('_global', 'Object') + STRICT_EQUALS)
c += trace_expr('Object.prototype===_global.Object.prototype: ', G('Object', 'prototype') + G('_global', 'Object', 'prototype') + STRICT_EQUALS)
c += trace_expr('new Object instanceof _global.Object: ', push(0, 'Object') + NEW_OBJECT + G('_global', 'Object') + INSTANCEOF)
c += trace_expr('Math.constructor===Object: ', G('Math', 'constructor') + G('Object') + STRICT_EQUALS,
                ' ===_global.Object: ', G('Math', 'constructor') + G('_global', 'Object') + STRICT_EQUALS)
c += trace_expr('typeof Object.registerClass: ', G('Object', 'registerClass') + TYPEOF,
                ' Object.__proto__===Function.prototype: ', G('Object', '__proto__') + G('Function', 'prototype') + STRICT_EQUALS,
                ' typeof Object.constructor: ', G('Object', 'constructor') + TYPEOF)
c += for_in_concat(G('Object'), 'k')
c += trace_expr('Object keys: ', get_var('k'))
c += set_member(G('Object'), 'prototype', push(5))
c += trace_expr('after Object.prototype=5: ', G('Object', 'prototype') + TYPEOF,
                ' ({}).constructor===Object: ', push(0) + INIT_OBJECT + push('constructor') + GET_MEMBER + G('Object') + STRICT_EQUALS)
# L3: _global.hasOwnProperty
c += trace_expr('typeof _global.hasOwnProperty: ', G('_global', 'hasOwnProperty') + TYPEOF,
                ' typeof _global.__proto__: ', G('_global', '__proto__') + TYPEOF,
                ' _global.hOP(Object): ', call_method(G('_global'), 'hasOwnProperty', 'Object', discard=False))
c += trace_str('Done')
swf_file(pathlib.Path(sys.argv[1]), [do_action(c)], version=int(sys.argv[2]))
