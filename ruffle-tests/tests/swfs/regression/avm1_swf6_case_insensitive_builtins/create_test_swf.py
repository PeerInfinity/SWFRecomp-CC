#!/usr/bin/env python3
"""avm1_swf6_case_insensitive_builtins: in a SWF6 movie identifiers are
case-insensitive (Ruffle: Activation::is_case_sensitive() = swf_version > 6),
so a builtin spelled in another case must still resolve: bare CallFunction
globals and MovieClip methods, CallMethod on builtin objects / primitives /
clips, GetVariable of builtin classes, and timeline event handler names.

s27 w1-avm1-leftovers item 6 (census of case-sensitive builtin name arms; s26
fixed only the CallFunction nav arm, gnash `sound` = `gotoandPlay`).
Each row: `<label>: <typeof result> <result>`. Rows whose CANONICAL spelling
also disagrees with Ruffle (version-7 MovieClip methods in SWF6, getVersion,
hasOwnProperty) are left out: see the s27 report's leads.

Golden: Flash Player 32 DIRECT-mode trace, cut at num_frames (== the
Ruffle-source prediction). The `--wrapped` capture reads getDepth -77824 for
`_root` only because the SWF is then a loaded child of the AS3 host.

Usage: create_test_swf.py <out.swf> [version]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
VER = int(sys.argv[2]) if len(sys.argv) > 2 else 6
CANON_MODE = len(sys.argv) > 3 and sys.argv[3] == 'canon'   # control twin: canonical spellings
CANON = {n.lower(): n for n in '''parseInt parseFloat isNaN isFinite escape unescape String Number Boolean Array
Object getVersion setInterval ASnative getDepth getBytesTotal getNextHighestDepth createEmptyMovieClip
getInstanceAtDepth createTextField getSWFVersion hitTest getBounds swapDepths floor Math toUpperCase charAt
indexOf join fromCharCode toString hasOwnProperty isDown getTextFormat replaceSel PI _x _name text width
onEnterFrame'''.split()}


def C(name):
    return CANON.get(name.lower(), name) if CANON_MODE else name


def args_code(args):
    return b''.join(a if isinstance(a, bytes) else push(a) for a in reversed(args))


def cf(name, *args):
    """bare name(args), value left on the stack"""
    return args_code(args) + push(len(args), C(name)) + CALLF


def cm(objcode, meth, *args):
    return args_code(args) + push(len(args)) + objcode + push(C(meth)) + CALLM


def row(label, code):
    # trace(label + ": " + typeof(v) + " " + v) with v evaluated twice? no:
    # store in a register-free temp var
    return (push('_v') + code + SETVAR
            + T(label + ': ', get('_v') + TYPEOF, ' ', get('_v')))


def lit(v):
    return push(v)


rows = [
    # --- bare CallFunction: globals
    ('cf parseint', cf('parseint', '12')),
    ('cf PARSEFLOAT', cf('PARSEFLOAT', '1.5')),
    ('cf isnan', cf('isnan', 1)),
    ('cf isFINITE', cf('isFINITE', 1)),
    ('cf ESCAPE', cf('ESCAPE', 'a b')),
    ('cf unescape', cf('unescape', 'a%20b')),
    ('cf string', cf('string', 5)),
    ('cf NUMBER', cf('NUMBER', '3')),
    ('cf boolean', cf('boolean', 1)),
    ('cf array.length', cf('array', 4, 5, 6) + push('length') + GETMEM),
    ('cf OBJECT', cf('OBJECT') + TYPEOF),
    ('cf asnative', cf('asnative', 200, 0) + TYPEOF),
    # --- bare CallFunction: MovieClip methods on _root
    ('cf getdepth', cf('getdepth')),
    ('cf GETBYTESTOTAL', cf('GETBYTESTOTAL') + TYPEOF),
    ('cf createemptymovieclip', cf('createemptymovieclip', 'c1', 5) + POP + get('c1') + TYPEOF),
    ('cf createtextfield', cf('createtextfield', 't1', 6, 0, 0, 50, 20) + POP + get('t1') + TYPEOF),
    ('cf getswfversion', cf('getswfversion')),
    ('cf swapdepths', cm(get('c1'), 'swapdepths', 9) + POP + cm(get('c1'), 'getDepth')),
    # --- CallMethod on builtins / primitives
    ('cm Math.FLOOR', cm(get('Math'), 'FLOOR', 1.5)),
    ('cm math.floor', cm(get('math'), 'floor', 2.5)),
    ('cm str.TOUPPERCASE', cm(lit('abc'), 'TOUPPERCASE')),
    ('cm str.charat', cm(lit('abc'), 'charat', 1)),
    ('cm str.INDEXOF', cm(lit('abc'), 'INDEXOF', 'c')),
    ('cm arr.JOIN', cm(cf('Array', 1, 2), 'JOIN', '-')),
    ('cm String.FROMCHARCODE', cm(get('String'), 'FROMCHARCODE', 65)),
    ('cm num.TOSTRING', cm(lit(10), 'TOSTRING', 16)),
    ('cm Key.ISDOWN', cm(get('Key'), 'ISDOWN', 65)),
    ('cm _root.GETDEPTH', cm(get('_root'), 'GETDEPTH')),
    ('cm c1.getdepth', cm(get('c1'), 'getdepth')),
    ('cm _root.CREATEEMPTYMOVIECLIP', cm(get('_root'), 'CREATEEMPTYMOVIECLIP', 'c2', 7) + POP + get('c2') + TYPEOF),
    ('cm t1.GETTEXTFORMAT', cm(get('t1'), 'GETTEXTFORMAT') + TYPEOF),
    ('cm t1.REPLACESEL', cm(get('t1'), 'REPLACESEL', 'q') + TYPEOF),
    # --- GetMember / GetVariable on builtins
    ('gm Math.pi', get('Math') + push(C('pi')) + GETMEM),
    ('gv MATH', get(C('MATH')) + TYPEOF),
    ('gm _root._X', get('_root') + push(C('_X')) + GETMEM),
    ('gm c1._NAME', get('c1') + push(C('_NAME')) + GETMEM),
    ('gm t1.TEXT', get('t1') + push(C('TEXT')) + GETMEM),
    ('gm Stage.WIDTH', get('Stage') + push(C('WIDTH')) + GETMEM),
]

f1 = b''.join(row(l, c) for l, c in rows)
# event handler name case: onenterframe on a clip (fires each frame)
onef = deffunc2('', [], T('c1.onenterframe ', get('_root.n')) + push('n') + get('n') + op(0x50) + SETVAR, nregs=1, flags=0, first_param_reg=0)
f1 += push('n', 0) + SETVAR + get('c1') + push(C('onenterframe')) + onef + SETMEM
f2 = T('f2 n=', get('n'))
f3 = T('f3 n=', get('n')) + STOP
open(sys.argv[1], 'wb').write(swf(VER, b'', [doaction(f1), doaction(f2), doaction(f3)]))
