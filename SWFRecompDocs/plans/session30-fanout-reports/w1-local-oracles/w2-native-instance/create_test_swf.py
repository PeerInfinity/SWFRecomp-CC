"""avm1_native_instance_layout — s30 w2-native-instance (PROVISIONAL golden).

Pins the native-instance layout changes of s30 w2-native-instance:
  1. for..in of `new XML()` walks XMLNode.prototype getters + methods and
     XML.prototype (no own node slot, no idMap / contentType own copy);
  2. hasOwnProperty / delete / write of XML node fields on an instance;
  3. an ALIASED native ctor (`var C = XML; new C(src)`, `var G = GlowFilter`)
     builds a real native instance;
  4. ColorTransform member writes coerce to Number; filter members not own;
  5. `delete (new Object()).__proto__` fails; native-instance __proto__ /
     __constructor__ stay out of for..in after ASSetPropFlags(o, null, 0, 1).
Expected output must come from a FLASH capture (LOCAL ORACLE REQUEST in
w2-native-instance-report.md); `output.provisional.txt` is ours.
Usage: python3 create_test_swf.py   (writes test.swf next to this file)
"""
import sys, struct
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[4] / 'ruffle-tests/tests/swfs/regression/_lib'))
from avm1asm import *

NEW_OBJECT = bytes([0x40]); NEW_METHOD = bytes([0x53]); DELETE = bytes([0x3A])
CALL_FN = bytes([0x3D])
def new_object(name, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    return code + push(len(args), name) + NEW_OBJECT
def new_method(obj_code, method, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    return code + push(len(args)) + obj_code + push(method) + NEW_METHOD
def call_fn(name, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    return code + push(len(args), name) + CALL_FN

a = b''
a += set_var('x', new_object('XML'))
a += for_in_concat(get_var('x'), 's')
a += trace_expr('xml for-in: ', get_var('s'))
a += trace_expr('xml hOP nodeType: ', call_method(get_var('x'), 'hasOwnProperty', 'nodeType', discard=False))
a += trace_expr('xml hOP contentType: ', call_method(get_var('x'), 'hasOwnProperty', 'contentType', discard=False))
a += set_var('C', get_var('XML'))
a += set_var('y', new_object('C', "<a b='1'/>"))
a += trace_expr('alias firstChild: ', get_path('y', 'firstChild', 'nodeName'))
a += trace_expr('delete firstChild: ', get_var('y') + push('firstChild') + DELETE)
a += trace_expr('after delete: ', get_path('y', 'firstChild', 'nodeName'))
a += set_member(get_path('y', 'firstChild'), 'nodeType', 3)
a += trace_expr('nodeType write: ', get_path('y', 'firstChild', 'nodeType'))
a += set_var('G', get_path('flash', 'filters', 'GlowFilter'))
a += set_var('g', new_object('G'))
a += trace_expr('alias glow blurX: ', get_path('g', 'blurX'))
a += trace_expr('glow hOP blurX: ', call_method(get_var('g'), 'hasOwnProperty', 'blurX', discard=False))
a += set_var('ct', new_method(get_path('flash', 'geom'), 'ColorTransform'))
a += set_member(get_var('ct'), 'redMultiplier', 'x')
a += trace_expr('ct write typeof: ', get_path('ct', 'redMultiplier') + TYPEOF)
a += set_var('o', new_object('Object'))
a += trace_expr('delete new Object __proto__: ', get_var('o') + push('__proto__') + DELETE)
a += set_var('snd', new_object('Sound'))
a += call_fn('ASSetPropFlags', get_var('snd'), push(None), 0, 1) + POP
a += for_in_concat(get_var('snd'), 't')
a += trace_expr('sound for-in after unhide: [', get_var('t'), ']')

swf_file(HERE / 'test.swf', [do_action(a)], version=8)
