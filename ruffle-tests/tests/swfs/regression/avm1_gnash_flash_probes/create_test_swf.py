#!/usr/bin/env python3
"""avm1_gnash_flash_probes: s28 w1b-rm-gnash Flash-oracle probes for the
mechanisms behind gnash `ruffle_matched` rows. One SWF per version.

Landed s28 w2b-gnash-holds as regression/avm1_gnash_flash_probes (SWF8),
_v6 and _v5 (same generator, version arg). Every output.txt is a real
Flash Player 32 (LNX, direct pinned) trace captured by the coordinator
(SWFRecomp-CC-history:SWFRecompDocs/plans/session28-fanout-reports/w1-local-oracles/w1b-rm-gnash/). Pins: XMLNode
name/value exclusivity (P1, B1), the `with` nesting cap at frame level and
inside DefineFunction/DefineFunction2 per SWF version (P2, B2),
Selection.setFocus select-all + setSelection arg-count rule (P3, B10), NaN
atom identity in == (P4, B11), "" ordering in Less2 (P5), and
String.prototype.valueOf on non-String receivers (P6, B4).

  P1 XML   nodeName/nodeValue exclusivity + nodeType after the write
           (XMLNode.as:79-83, XML.as:381/494; prototype models "writing one
           nulls the other", nodeType unchanged).
  P2 WITH  nesting limit at frame level and inside a function (with.as:625
           says 13 at frame level; is it 13 inside a function too?).
  P3 SEL   Selection.setSelection arg-count rule (Selection.as:253-296 vs
           avm1/selection's setSelection(0) from "no selection").
  P4 NAN   pairwise == over NaN producers (ops.as:82/102-104/766/794).
  P5 LESS  "" < "0" and friends (ops.as:174-177).
  P6 SVO   String.prototype.valueOf on non-String receivers.

Usage: create_test_swf.py <out.swf> [swf_version, default 8]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
DIV = op(0x0D)
MUL = op(0x0C)
LESS2 = op(0x48)
DEC = op(0x51)


def callm_code(target, meth, argcode, nargs, keep=False):
    """target.meth(<values pushed by argcode, already reversed>)"""
    code = argcode + push(nargs) + get(target) + push(meth) + CALLM
    return code if keep else code + POP


def setv(name, code):
    return push(name) + code + SETVAR


def setm(path, prop, valcode):
    return get(path) + push(prop) + valcode + SETMEM


def new(cls, *args):
    return (push(*reversed(args)) if args else b'') + push(len(args), cls) + NEWOBJ


# ---- P1 XML ----
p1 = (
    setv('x', new('XML'))
    + setv('t', push('v') + push(1) + get('x') + push('createTextNode') + CALLM)
    + T('P1 text init name=', get('t.nodeName'), ' value=', get('t.nodeValue'), ' type=', get('t.nodeType'))
    + setm('t', 'nodeName', push('foo'))
    + T('P1 text after nodeName=foo: name=', get('t.nodeName'), ' value=', get('t.nodeValue'), ' type=', get('t.nodeType'), ' str=', callm('t', 'toString', keep=True))
    + setm('t', 'nodeValue', push('bar'))
    + T('P1 text after nodeValue=bar: name=', get('t.nodeName'), ' value=', get('t.nodeValue'), ' type=', get('t.nodeType'), ' str=', callm('t', 'toString', keep=True))
    + setv('e', push('e') + push(1) + get('x') + push('createElement') + CALLM)
    + setm('e.attributes', 'a', push('1'))
    + setm('e', 'nodeValue', push(4))
    + T('P1 elem after nodeValue=4: name=', get('e.nodeName'), ' value=', get('e.nodeValue'), ' type=', get('e.nodeType'), ' str=', callm('e', 'toString', keep=True))
    + setm('e', 'nodeName', push('f'))
    + T('P1 elem after nodeName=f: name=', get('e.nodeName'), ' value=', get('e.nodeValue'), ' type=', get('e.nodeType'), ' str=', callm('e', 'toString', keep=True))
)

# ---- P2 WITH ----
def nest(n, tag_):
    body = b''
    for i in reversed(range(n)):
        body = with_block(T(tag_ + str(i + 1)) + body)
        body = get('wo') + body
    return body


p2 = (
    setv('wo', push(0) + INITOBJ)
    + nest(16, 'P2 frame depth ')
    + deffunc1('wfn', [], nest(16, 'P2 func depth '))
    + callf('wfn')
    + deffunc2('wfn2', [], nest(16, 'P2 func2 depth '), nregs=2)
    + callf('wfn2')
)

# ---- P3 SEL ----
def sel(label):
    return T('P3 ' + label + ': b=', callm('Selection', 'getBeginIndex', keep=True),
             ' e=', callm('Selection', 'getEndIndex', keep=True),
             ' c=', callm('Selection', 'getCaretIndex', keep=True))


p3 = (
    callm('this', 'createTextField', 'tf', 10, 0, 0, 200, 20)
    + setm('tf', 'type', push('input'))
    + setm('tf', 'text', push('abcdefghi'))
    + callm('this', 'createTextField', 'tg', 11, 0, 30, 200, 20)
    + setm('tg', 'type', push('input'))
    + setm('tg', 'text', push('abcdefghi'))
    + callm_code('Selection', 'setFocus', get('tf'), 1)
    + sel('after setFocus(tf)')
    + callm('Selection', 'setSelection', 3) + sel('setSelection(3) fresh')
    + callm('Selection', 'setSelection', 2, 6) + sel('setSelection(2,6)')
    + callm('Selection', 'setSelection', 3) + sel('setSelection(3)')
    + callm('Selection', 'setSelection', 1, 2, 3) + sel('setSelection(1,2,3)')
    + callm('Selection', 'setSelection', 0) + sel('setSelection(0)')
    + callm_code('Selection', 'setFocus', get('tg'), 1)
    + sel('after setFocus(tg)')
    + callm('Selection', 'setSelection', 0) + sel('tg setSelection(0) fresh')
)

# ---- P4 NAN ----
names = ['glob', 'lit', 'div', 'mul', 'num', 'sqrt', 'pint', 'box', 'dec', 'undef', 'glob2']
p4 = (
    setv('n_glob', get('NaN'))
    + setv('n_lit', push(float('nan')))
    + setv('n_div', push(0, 0) + DIV)
    + setv('n_mul', push('abc', 0) + MUL)
    + setv('n_num', callf('Number', 'a', keep=True))
    + setv('n_sqrt', callm('Math', 'sqrt', -1, keep=True))
    + setv('n_pint', callf('parseInt', 'x', keep=True))
    + setv('n_box', get('NaN') + push(1, 'Number') + NEWOBJ + push(1, 'Number') + CALLF)
    + setv('n_dec', push('a') + DEC)
    + setv('n_undef', push(UNDEF, 1) + ADD2)
    + setv('n_glob2', get('NaN'))
)
for i, a in enumerate(names):
    row = b''
    parts = ['P4 ' + a + ':']
    for b in names:
        parts += [' ' + b + '=', get('n_' + a) + get('n_' + b) + EQ2]
    p4 += T(*parts)

# ---- P5 LESS ----
p5 = b''
for a, b in (('', '0'), ('', 'a'), ('0', ''), ('a', 'b'), ('', ''), ('', ' ')):
    p5 += T('P5 "' + a + '"<"' + b + '"=', push(a, b) + LESS2)

# ---- P6 SVO ----
p6 = (
    setv('svo', get('String.prototype.valueOf'))
    + setv('on', new('Number', 5)) + setm('on', 'vo', get('svo'))
    + setv('ob', new('Boolean', False)) + setm('ob', 'vo', get('svo'))
    + setv('oo', push(0) + INITOBJ) + setm('oo', 'vo', get('svo'))
    + setv('os', new('String', 'str')) + setm('os', 'vo', get('svo'))
    + setv('fn', get('svo')) + setm('fn', 'vo', get('svo'))
    + setm('_root', 'vo', get('svo'))
    + T('P6 Number(5).vo=', callm('on', 'vo', keep=True), ' typeof=', callm('on', 'vo', keep=True) + TYPEOF)
    + T('P6 Boolean(false).vo=', callm('ob', 'vo', keep=True), ' typeof=', callm('ob', 'vo', keep=True) + TYPEOF)
    + T('P6 {}.vo=', callm('oo', 'vo', keep=True))
    + T('P6 String(str).vo=', callm('os', 'vo', keep=True))
    + T('P6 function.vo=', callm('fn', 'vo', keep=True))
    + T('P6 _root.vo=', callm('_root', 'vo', keep=True))
    + T('P6 svo()=', callf('svo', keep=True))
    + T('P6 String.prototype.valueOf()=', callm('String.prototype', 'valueOf', keep=True), ' typeof=', callm('String.prototype', 'valueOf', keep=True) + TYPEOF)
)

ver = int(sys.argv[2]) if len(sys.argv) > 2 else 8
open(sys.argv[1], 'wb').write(swf(ver, b'', [doaction(p1 + p2 + p3 + p4 + p5 + p6 + STOP)], w=400, h=300))
