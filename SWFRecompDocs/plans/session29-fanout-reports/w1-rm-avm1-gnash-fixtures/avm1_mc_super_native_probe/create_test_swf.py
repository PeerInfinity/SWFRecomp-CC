#!/usr/bin/env python3
"""avm1_mc_super_native_probe: s29 w1-rm-avm1-gnash Flash-oracle probe.

Decides how far the prototype rules generalise (wave-2 scope):
  S  super() from a plain function called on a MovieClip, with
     this.__proto__.__constructor__ = Boolean / Number / String / a user
     function (gnash MovieClip.as:2585-2596 pins only Boolean, no arg).
  H  _height write after negative scales (gnash pins only _width).
  B  blendMode = 15 / 16 / 255 read-back (gnash pins 0, 14, 15).

Usage: create_test_swf.py <out.swf> [swf_version, default 8]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat


def setv(name, code):
    return push(name) + code + SETVAR


def setm(path, prop, valcode):
    return get(path) + push(prop) + valcode + SETMEM


def callm_code(target, meth, argcode, nargs, keep=False):
    code = argcode + push(nargs) + get(target) + push(meth) + CALLM
    return code if keep else code + POP


# dc2 = function(c, a) { this.__proto__.__constructor__ = c; super(a); }
dc2_body = (get('this.__proto__') + push('__constructor__') + get('c') + SETMEM
            + get('a') + push(1, 'super') + CALLF + POP)
code = deffunc1('dc2', ['c', 'a'], dc2_body)
# U = function(v) { this.u = v; }
code += deffunc1('U', ['v'], push('this') + GETVAR + push('u') + get('v') + SETMEM)

clips = [('m1', 'Boolean', False), ('m2', 'Boolean', True), ('m3', 'Number', 5),
         ('m4', 'String', 'str'), ('m5', 'U', 7)]
for depth, (m, ctor, arg) in enumerate(clips, start=1):
    code += callm('_root', 'createEmptyMovieClip', m, depth)
    code += setm(m, 'dc2', get('dc2'))
    code += callm_code(m, 'dc2', push(arg) + get(ctor), 2)
    for proto in ('Boolean', 'Number', 'String'):
        code += setm(m, 'ts' + proto[0], get(proto + '.prototype.toString'))
        code += setm(m, 'vo' + proto[0], get(proto + '.prototype.valueOf'))
    code += T('S ' + m + ' ' + ctor + '(' + str(arg) + '):',
              ' tsB=', callm(m, 'tsB', keep=True), ' voB=', callm(m, 'voB', keep=True),
              ' tsN=', callm(m, 'tsN', keep=True), ' voN=', callm(m, 'voN', keep=True),
              ' tsS=', callm(m, 'tsS', keep=True), ' voS=', callm(m, 'voS', keep=True),
              ' u=', get(m + '.u'), ' str=', get(m), ' typeof=', get(m) + TYPEOF,
              ' _x=', get(m + '._x'))
    code += setm('MovieClip.prototype', '__constructor__', push(UNDEF))

# H: _height after negative scales
code += callm('_root', 'createEmptyMovieClip', 'h', 20)
code += callm('h', 'beginFill', 0xff0000)
code += callm('h', 'moveTo', 0, 0) + callm('h', 'lineTo', 10, 0)
code += callm('h', 'lineTo', 10, 20) + callm('h', 'lineTo', 0, 20) + callm('h', 'endFill')
for xs, ys in ((-50, -50), (-50, 100), (100, -200)):
    code += setm('h', '_rotation', push(0)) + setm('h', '_xscale', push(xs)) + setm('h', '_yscale', push(ys))
    code += setm('h', '_height', push(10))
    code += T('H xs=' + str(xs) + ' ys=' + str(ys) + ' then _height=10: _xscale=', get('h._xscale'),
              ' _yscale=', get('h._yscale'), ' _width=', get('h._width'), ' _height=', get('h._height'))
    code += setm('h', '_xscale', push(xs)) + setm('h', '_yscale', push(ys))
    code += setm('h', '_width', push(5))
    code += T('H xs=' + str(xs) + ' ys=' + str(ys) + ' then _width=5: _xscale=', get('h._xscale'),
              ' _yscale=', get('h._yscale'), ' _width=', get('h._width'), ' _height=', get('h._height'))

# B: blendMode read-back
for v in (15, 16, 255, 0, 1, 14):
    code += setm('h', 'blendMode', push('multiply')) + setm('h', 'blendMode', push(v))
    code += T('B multiply then ' + str(v) + ': ', get('h.blendMode'), ' typeof=', get('h.blendMode') + TYPEOF)

code += push('done') + TRACE + STOP
ver = int(sys.argv[2]) if len(sys.argv) > 2 else 8
open(sys.argv[1], 'wb').write(swf(ver, b'', [doaction(code)], w=400, h=300))
