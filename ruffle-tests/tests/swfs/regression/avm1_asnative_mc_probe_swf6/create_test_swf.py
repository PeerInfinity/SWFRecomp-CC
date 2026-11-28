#!/usr/bin/env python3
"""avm1_asnative_mc_probe_swf6 (regression fixture, built as `create_test_swf.py test.swf 6`):
pins ASnative(900/901, n) = the MovieClip.prototype natives (s30 w1-rm-avm1-gnash R1),
the SWF6+ fresh-object-per-call identity (section D)
(s30 w2-rm-avm1-gnash-land). Golden = FP32 LNX direct pinned
(session30-fanout-reports/w1-local-oracles/w1-rm-avm1-gnash/avm1_asnative_mc_probe/swf6.lnx.txt).

Original probe docstring: avm1_asnative_mc_probe: s30 w1-rm-avm1-gnash. ASnative(900/901, n) =
MovieClip.prototype natives, called bare / as a method / after assignment to
MovieClip.prototype, in SWF5 and SWF6+ (gnash setProperty.as:30, Sound.as:240).

Usage: create_test_swf.py <out.swf> [swf_version, default 6]
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa
T = trace_concat
def setv(name, code): return push(name) + code + SETVAR
def asn(a, b): return push(b, a, 2, 'ASnative') + CALLF

code = b''
# A: bare call of a variable holding ASnative(901, 0)
code += setv('cs', asn(901, 0))
code += T('A typeof cs=', get('cs') + TYPEOF)
code += callf('cs', 'a1', 10)
code += T('A typeof a1=', get('a1') + TYPEOF, ' a1=', get('a1'), ' depth=', callm('a1', 'getDepth', keep=True))
# B: assigned onto MovieClip.prototype then bare-called (Sound.as:240)
code += get('MovieClip.prototype') + push('createEmptyMovieClip') + asn(901, 0) + SETMEM
code += callf('createEmptyMovieClip', 'a2', 11)
code += T('B typeof a2=', get('a2') + TYPEOF, ' a2=', get('a2'))
# C: method call through an own property of _root
code += get('_root') + push('mk') + asn(901, 0) + SETMEM
code += callm('_root', 'mk', 'a3', 12)
code += T('C typeof a3=', get('a3') + TYPEOF, ' a3=', get('a3'))
# D: identity with the prototype member and between two ASnative calls
code += T('D same-as-proto=', asn(901, 0) + get('MovieClip.prototype.createEmptyMovieClip') + op(0x49),
          ' two-calls-equal=', asn(901, 0) + asn(901, 0) + op(0x49))
# E: a 900 entry, getDepth via ASnative(900, 10) borrowed onto a3
code += get('a3') + push('gd') + asn(900, 10) + SETMEM
code += T('E a3.gd()=', callm('a3', 'gd', keep=True))
# F: bare call inside a function invoked as a method of a3 (this = a3)
code += get('a3') + push('f') + deffunc1('', [], callf('cs', 'inner', 1)) + SETMEM
code += callm('a3', 'f')
code += T('F typeof a3.inner=', get('a3.inner') + TYPEOF, ' typeof _root.inner=', get('_root.inner') + TYPEOF)
code += push('done') + TRACE + STOP
ver = int(sys.argv[2]) if len(sys.argv) > 2 else 6
open(sys.argv[1], 'wb').write(swf(ver, b'', [doaction(code)], w=200, h=150))
