#!/usr/bin/env python3
"""avm1_native_identity_probe_swf5 — s30 w2-native-table-land probe, SWF5.

Golden = FP32 LNX 32,0,0,465 direct pinned capture (coordinator, 2026-11-27,
session30-fanout-reports/w1-local-oracles/w2-native-table-land/v5.lnx.txt).
The last residues (ASnative has no __proto__/constructor, SWF5 hasOwnProperty is
absent on function receivers, SWF5 RemoteLSOUsage.getURLPageSupport) closed by
s30 w2b-native-residues.


Prints, one line each: Array / String constructor identity (`Array === _global.Array`,
`_global.Array.NUMERIC`, `_global.String.fromCharCode`, `[].constructor`), the own `toString`
of Key/Mouse/Stage/Selection/Math/Accessibility/Sound.prototype and their string coercion,
Accessibility method presence, `_global.o`, ASnative / ASSetNative own props, the singletons'
own `constructor`, the inert stubs (AssetCache, RemoteLSOUsage, Sound.prototype.checkPolicyFile),
and the for..in key list of Key / Accessibility / Math / ASnative / ASSetNative after
ASSetPropFlags(o, null, 0, 1). Hand-assembled (regression/_lib/avm1asm.py), uncompressed.

Usage: python3 create_test_swf.py   (writes test.swf next to this file)
"""
import sys, pathlib
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *
INIT_ARRAY = bytes([0x42])
G = lambda *p: get_path(*p)
def has_own(objc, name): return call_method(objc, 'hasOwnProperty', name, discard=False)
c = b''
c += trace_expr('Array===_global.Array: ', G('Array') + G('_global', 'Array') + STRICT_EQUALS)
c += trace_expr('_global.Array.NUMERIC: ', G('_global', 'Array', 'NUMERIC'))
c += trace_expr('Array.NUMERIC: ', G('Array', 'NUMERIC'))
c += trace_expr('Array.CASEINSENSITIVE: ', G('Array', 'CASEINSENSITIVE'))
c += trace_expr('String===_global.String: ', G('String') + G('_global', 'String') + STRICT_EQUALS)
c += trace_expr('typeof _global.String.fromCharCode: ', G('_global', 'String', 'fromCharCode') + TYPEOF)
c += trace_expr('typeof String.fromCharCode: ', G('String', 'fromCharCode') + TYPEOF)
c += trace_expr('[].constructor===Array: ', push(0) + INIT_ARRAY + push('constructor') + GET_MEMBER + G('Array') + STRICT_EQUALS)
c += trace_expr('[].constructor===_global.Array: ', push(0) + INIT_ARRAY + push('constructor') + GET_MEMBER + G('_global', 'Array') + STRICT_EQUALS)
c += trace_expr('Array.prototype===_global.Array.prototype: ', G('Array', 'prototype') + G('_global', 'Array', 'prototype') + STRICT_EQUALS)
c += trace_expr('new Array instanceof _global.Array: ', push(0, 'Array') + bytes([0x40]) + G('_global', 'Array') + bytes([0x54]))
c += trace_expr('Array.hasOwnProperty(NUMERIC): ', has_own(G('Array'), 'NUMERIC'))
c += trace_expr('String.hasOwnProperty(fromCharCode): ', has_own(G('String'), 'fromCharCode'))
for o in ['Key', 'Mouse', 'Stage', 'Selection', 'Math', 'Accessibility']:
    c += trace_expr(o + ' own toString: ', has_own(G(o), 'toString'), ' str: ', G(o), ' toString(): ', call_method(G(o), 'toString', discard=False))
c += trace_expr('Sound.prototype own toString: ', has_own(G('Sound', 'prototype'), 'toString'), ' str: ', G('Sound', 'prototype'))
c += trace_expr('new Sound str: ', push(0, 'Sound') + bytes([0x40]))
c += trace_expr('typeof Accessibility.isActive: ', G('Accessibility', 'isActive') + TYPEOF)
c += trace_expr('typeof Accessibility.updateProperties: ', G('Accessibility', 'updateProperties') + TYPEOF)
c += trace_expr('_global own o: ', has_own(G('_global'), 'o'), ' o=', G('o'))
for f in ['ASnative', 'ASSetNative', 'ASSetNativeAccessor']:
    c += trace_expr(f + ' own __proto__: ', has_own(G(f), '__proto__'), ' own constructor: ', has_own(G(f), 'constructor'))
c += trace_expr('Key.constructor===Object: ', G('Key', 'constructor') + G('Object') + STRICT_EQUALS)
c += trace_expr('typeof Sound.prototype.checkPolicyFile: ', G('Sound', 'prototype', 'checkPolicyFile') + TYPEOF)
c += trace_expr('typeof Sound.prototype.areSoundsInaccessible: ', G('Sound', 'prototype', 'areSoundsInaccessible') + TYPEOF)
c += trace_expr('typeof AssetCache: ', G('AssetCache') + TYPEOF, ' RemoteLSOUsage: ', G('RemoteLSOUsage') + TYPEOF, ' AsSetupError: ', G('AsSetupError') + TYPEOF)
c += trace_expr('({}).constructor===Object: ', push(0) + bytes([0x43]) + push('constructor') + GET_MEMBER + G('Object') + STRICT_EQUALS)
c += trace_expr('"".constructor===String: ', push('') + push('constructor') + GET_MEMBER + G('String') + STRICT_EQUALS)
c += trace_expr('typeof Key.constructor: ', G('Key', 'constructor') + TYPEOF)
c += trace_expr('String.fromCharCode(72,105): ', call_method(G('String'), 'fromCharCode', 105, 72, discard=False) if False else call_method(G('String'), 'fromCharCode', 72, 105, discard=False))
c += trace_expr('typeof ASnative.call: ', G('ASnative', 'call') + TYPEOF, ' ASnative.__proto__: ', G('ASnative', '__proto__') + TYPEOF)
c += trace_expr('typeof AssetCache.getDiskUsage: ', G('AssetCache', 'getDiskUsage') + TYPEOF, ' RemoteLSOUsage.getURLPageSupport: ', G('RemoteLSOUsage', 'getURLPageSupport') + TYPEOF)
CALL_FUNCTION_ = bytes([0x3D])
for o in ['Key', 'Accessibility', 'Math', 'ASnative', 'ASSetNative']:
    c += push(1, 0, None) + G(o) + push(4, 'ASSetPropFlags') + CALL_FUNCTION_ + POP
    c += for_in_concat(G(o), 'k')
    c += trace_expr(o + ' keys after unhide: ', get_var('k'))
c += trace_str('Done')
swf_file(HERE / 'test.swf', [do_action(c)], version=5)
