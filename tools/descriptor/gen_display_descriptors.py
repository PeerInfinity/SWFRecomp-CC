#!/usr/bin/env python3
"""Emit the `flash.display` describeType descriptor tables for the runtime.

    python3 tools/descriptor/gen_display_descriptors.py \
        [--actual <our-output.txt>] [-o <header>]

Reads Ruffle's playerglobal .as stubs (via `as_model`), derives the full
member/parameter/constructor/API-gate model (validated by `check_model.py`
against the six `avm2/all_classes/display/swf*` expected files), and writes
`SWFModernRuntime/src/avm2/avm2_desc_display.h`, which `avm2_globals.c`
includes inside its `dt_*` region.

`--actual` is one of OUR describeType outputs for the same fixture, captured
from a BASELINE build -- one whose generated block is empty (delete everything
between the two markers in avm2_globals.c and rebuild) or that predates this
arc.  It must be a baseline because the tables below already correct what it
records; feeding back a corrected output would erase the corrections.  A class
the capture predates falls back to its superclass's entry, which is exact for
the classes this arc adds (they inherit their whole instance surface).

It is used only to derive the per-described-class exception tables that cannot
come from playerglobal alone, because they describe where OUR class
registration disagrees with playerglobal about which class owns a member:

  * a `declaredBy` re-point (we register an override playerglobal does not, or
    playerglobal declares an override we inherit), and
  * a member hide (we register a member on a class playerglobal does not put
    it on at all -- `soundTransform` on InteractiveObject).

Re-run with a fresh `--actual` after changing the display class registration.
"""

import argparse
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import as_model
import xml_model

RUFFLE = os.path.expanduser("~/CC/ruffle")
PKG = "flash.display"
KIND_C = {"method": "DT_DESC_METHOD", "accessor": "DT_DESC_ACCESSOR",
          "variable": "DT_DESC_SLOT"}

# The generated tables are spliced straight into avm2_globals.c between these
# markers rather than living in their own header: verify_output.py builds by
# copying an explicit list of source files into a flat directory, so a new
# header would have to be added to that list, to CMakeLists and to the
# Emscripten build script, and a missed one is a link-time surprise (the
# session-15 incident of record). Everything here is `static`, so nothing
# leaks past this translation unit.
BEGIN = ("// >>> BEGIN GENERATED flash.display descriptors -- DO NOT EDIT.\n"
         "// Regenerate with:\n"
         "//   python3 tools/descriptor/gen_display_descriptors.py \\\n"
         "//       --actual <our all_classes/display/swf30 output>\n"
         "// Derived from Ruffle's playerglobal ActionScript stubs\n"
         "// (<ruffle>/core/src/avm2/globals/flash/display/*.as) and validated\n"
         "// element-for-element against the six\n"
         "// avm2/all_classes/display/swf*/output.txt oracles by\n"
         "// tools/descriptor/check_model.py.")
END = "// <<< END GENERATED flash.display descriptors"


def splice(path, block):
    src = open(path, encoding="utf-8").read()
    i = src.find(BEGIN.split("\n")[0])
    j = src.find(END)
    if i < 0 or j < 0:
        raise SystemExit("markers not found in %s -- add\n%s\n%s"
                         % (path, BEGIN, END))
    open(path, "w", encoding="utf-8").write(
        src[:i] + block + src[j + len(END):])


def fixture_classes(path):
    src = open(path, encoding="utf-8").read()
    m = re.search(r"CLASSES:Array\s*=\s*\[(.*?)\]", src, re.S)
    return [x.strip().strip('"') for x in m.group(1).split(",")]


class Emitter(object):
    def __init__(self):
        self.params = {}      # tuple -> symbol
        self.lines = []

    def param_sym(self, res, k, params):
        if not params:
            return "NULL", 0
        key = tuple((res.qname(k, t), bool(o)) for t, o in params)
        sym = self.params.get(key)
        if sym is None:
            sym = "dtd_p%d" % len(self.params)
            self.params[key] = sym
        return sym, len(key)

    def emit_params(self):
        out = []
        for key, sym in sorted(self.params.items(), key=lambda kv: kv[1]):
            body = ", ".join('{ "%s", %d }' % (t, 1 if o else 0)
                             for t, o in key)
            out.append("static const DtDescParam %s[] = { %s };" % (sym, body))
        return out


def owner_of(res, k, kind, name):
    """The class the model reports in `declaredBy` when describing `k`."""
    ch = xml_model.chain(res, k)
    if kind == "accessor":
        for c in ch:
            mem = c.members.get(("accessor", name, False))
            if mem is not None and mem.has_get:
                return c
        for c in ch:
            mem = c.members.get(("accessor", name, False))
            if mem is not None:
                return c
        return None
    for c in ch:
        if (kind, name, False) in c.members:
            return c
    return None


def resolved_access(res, k, kind, name, mem):
    """The access string describeType prints for `k`.`name`.

    An accessor's halves can be split across the chain: playerglobal declares
    `Stage.alpha` as a SETTER-only override of DisplayObject's readwrite pair,
    and Flash still reports `readwrite` (with declaredBy=DisplayObject). So the
    access has to be resolved over the whole chain, not read off the row's own
    class -- that is also what keeps the genuinely setter-only members
    (DisplayObject.blendShader, Shader.byteCode) reported as `writeonly`.
    """
    if kind == "variable":
        return "readonly" if mem.has_get else "readwrite"
    if kind != "accessor":
        return None
    g = st = False
    for c in xml_model.chain(res, k):
        m = c.members.get(("accessor", name, mem.is_static))
        if m is None:
            continue
        g = g or m.has_get
        st = st or m.has_set
    return "readwrite" if g and st else "readonly" if g else "writeonly"


def build(actual_path, out_path):
    classes = as_model.load_globals(
        os.path.join(RUFFLE, "core/src/avm2/globals"))
    res = xml_model.Resolver(classes)
    names = fixture_classes(os.path.join(
        RUFFLE, "tests/tests/swfs/avm2/all_classes/display/Test.as"))
    em = Emitter()
    body = []
    rows = []
    stats = dict(members=0, params=0, ctors=0, consts=0, redecl=0, hide=0,
                 shadow=0)

    actual = xml_model.parse_expected(actual_path) if actual_path else {}

    # --- pass 1: one member row per member each class DECLARES --------------
    mem_rows = {}      # class name -> {(kind, name, static): row tuple}
    const_rows = {}
    for nm in names:
        k = classes.get("%s::%s" % (PKG, nm))
        if k is None:
            print("WARN: no .as for %s" % nm, file=sys.stderr)
            continue
        mem_rows[nm] = {}
        const_rows[nm] = []
        for (kind, name, is_static), mem in sorted(k.members.items()):
            typ = res.qname(k, mem.type)
            if kind == "variable" and is_static and mem.has_get:
                # `public static const` -- our runtime carries these as
                # read-only dynamic props on the class object when it knows
                # them; the DtDescConst row supplies the reported TYPE (uint
                # is not one of our value kinds) and the API gate.
                const_rows[nm].append('\t{ "%s", "%s", %d },'
                                      % (name, typ, mem.min_swf))
                stats["consts"] += 1
            psym, pn = em.param_sym(res, k, mem.params)
            access = resolved_access(res, k, kind, name, mem)
            own = owner_of(res, k, kind, name) if not is_static else k
            mem_rows[nm][(kind, name, is_static)] = (
                name, KIND_C[kind], typ, pn, psym, mem.min_swf,
                1 if own is k else 0, 1 if is_static else 0, access)
            stats["members"] += 1

    # --- pass 2: exceptions + shadow rows, from OUR output ------------------
    redecl = {}
    for nm in names:
        k = classes.get("%s::%s" % (PKG, nm))
        if k is None:
            continue
        # A class the baseline capture predates (one this patch creates)
        # inherits its whole instance surface, so its SUPERCLASS's entry is a
        # faithful stand-in for what our vtable pass would have produced. The
        # class side is not inherited, so it is dropped in that case.
        got = actual.get(nm)
        inherited = False
        for anc in xml_model.chain(res, k)[1:]:
            if got:
                break
            got = actual.get(anc.name)
            inherited = True
        if not got:
            continue
        model = xml_model.describe(res, k, 99)
        rl = []
        for side, static in ((("factory", 0),) if inherited
                             else (("factory", 0), ("type", 1))):
            want = {}
            for tag, attrs, _p in model[side]:
                a = dict(attrs)
                if tag in ("accessor", "method"):
                    want[(tag, a["name"])] = a["declaredBy"]
                elif tag in ("variable", "constant"):
                    want[("variable", a["name"])] = None
            for tag, attrs, _p in got[side]:
                a = dict(attrs)
                if tag not in ("accessor", "method", "variable", "constant"):
                    continue
                kind = tag if tag in ("accessor", "method") else "variable"
                key = (kind, a["name"])
                if static and key == ("accessor", "prototype"):
                    continue
                if key not in want:
                    rl.append('\t{ "%s", %s, %d, NULL },'
                              % (a["name"], KIND_C[kind], static))
                    stats["hide"] += 1
                    continue
                if want[key] is not None and a.get("declaredBy") != want[key]:
                    rl.append('\t{ "%s", %s, %d, "%s" },'
                              % (a["name"], KIND_C[kind], static, want[key]))
                    stats["redecl"] += 1
                # A SHADOW row: our vtable declares the member on a class
                # playerglobal does not, so the descriptor lookup (which keys
                # on OUR declaring class and then walks UP) finds nothing and
                # the member keeps its `*` fallback type. `soundTransform` is
                # the standing case -- we register it once on InteractiveObject
                # where playerglobal declares it twice, on Sprite and on
                # SimpleButton. Park a non-synthetic row on our declaring class
                # so the DATA resolves; declaredBy is still corrected per
                # described class above, and the classes playerglobal does not
                # give it to carry a hide.
                if (a.get("type") or a.get("returnType")) != "*":
                    continue
                dcl = (a.get("declaredBy") or "").split("::")[-1]
                mk = (kind, a["name"], bool(static))
                if dcl not in mem_rows or mk in mem_rows[dcl]:
                    continue
                own = owner_of(res, k, kind, a["name"])
                if own is None or mk not in own.members:
                    continue
                mem = own.members[mk]
                psym, pn = em.param_sym(res, own, mem.params)
                mem_rows[dcl][mk] = (
                    a["name"], KIND_C[kind], res.qname(own, mem.type), pn,
                    psym, mem.min_swf, 0, 1 if static else 0,
                    resolved_access(res, k, kind, a["name"], mem))
                stats["shadow"] += 1
        if rl:
            redecl[nm] = sorted(set(rl))

    # --- emit ---------------------------------------------------------------
    for nm in names:
        if nm not in mem_rows:
            continue
        k = classes["%s::%s" % (PKG, nm)]
        msym = csym = rsym = "NULL"
        if mem_rows[nm]:
            msym = "dtd_m_%s" % nm
            body.append("static const DtDescMember %s[] = {" % msym)
            for key in sorted(mem_rows[nm]):
                r = mem_rows[nm][key]
                body.append(
                    '\t{ "%s", %s, "%s", %d, %s, %d, %d, %d, %s, NULL },'
                    % (r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7],
                       ('"%s"' % r[8]) if r[8] else "NULL"))
            body.append("\t{ NULL, 0, NULL, 0, NULL, 0, 0, 0, NULL, NULL },")
            body.append("};")
        if const_rows[nm]:
            csym = "dtd_c_%s" % nm
            body.append("static const DtDescConst %s[] = {" % csym)
            body.extend(const_rows[nm])
            body.append("\t{ NULL, NULL, 0 },")
            body.append("};")
        if nm in redecl:
            rsym = "dtd_r_%s" % nm
            body.append("static const DtDescRedecl %s[] = {" % rsym)
            body.extend(redecl[nm])
            body.append("\t{ NULL, 0, 0, NULL },")
            body.append("};")
        ctor_sym, ctor_n = em.param_sym(res, k, k.ctor_params)
        if ctor_n:
            stats["ctors"] += 1
        rows.append('\t{ "%s", "%s", 0, %d, %s, %s, %s, 1, %s }, \\'
                    % (PKG, nm, ctor_n, ctor_sym, msym, csym, rsym))

    stats["params"] = len(em.params)
    out = []
    out.append(BEGIN)
    out.append("//")
    out.append("// Derived from Ruffle's playerglobal ActionScript stubs")
    out.append("// (<ruffle>/core/src/avm2/globals/flash/display/*.as) and")
    out.append("// validated element-for-element against the six")
    out.append("// avm2/all_classes/display/swf*/output.txt oracles by")
    out.append("// tools/descriptor/check_model.py.  Included from")
    out.append("// avm2_globals.c inside the dt_* descriptor region, so it")
    out.append("// sees DtDescParam/DtDescMember/DtDescConst/DtDescRedecl.")
    out.append("//")
    out.append("// %d members / %d distinct parameter lists / %d constructors"
               " / %d constants" % (stats["members"], stats["params"],
                                    stats["ctors"], stats["consts"]))
    out.append("// %d declaredBy re-points / %d per-class hides."
               % (stats["redecl"], stats["hide"]))
    out.append("")
    out.extend(em.emit_params())
    out.append("")
    out.extend(body)
    out.append("")
    out.append("#define DT_DESC_DISPLAY_ROWS \\")
    out.extend(rows)
    out.append("\t/* end of DT_DESC_DISPLAY_ROWS */")
    out.append(END)
    block = "\n".join(out) + "\n"
    if out_path.endswith(".c") or out_path.endswith(".h"):
        splice(out_path, block)
    else:
        open(out_path, "w", encoding="utf-8").write(block)
    print("wrote %s: %s" % (out_path, stats), file=sys.stderr)

    # A checklist for the hand-written half (avm2_display.c).
    print("\n== class API gates (avm2_builtin_class_api min_swf) ==")
    for nm in names:
        k = classes.get("%s::%s" % (PKG, nm))
        if k is not None and k.min_swf:
            print("  %-28s %d" % (nm, k.min_swf))
    print("\n== interfaces each class must declare ==")
    for nm in names:
        k = classes.get("%s::%s" % (PKG, nm))
        if k is not None and k.interfaces:
            print("  %-28s %s" % (nm, ", ".join(
                res.qname(k, i) for i in k.interfaces)))


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--actual", default=None)
    ap.add_argument("-o", "--out",
                    default="SWFModernRuntime/src/avm2/avm2_globals.c")
    a = ap.parse_args()
    build(a.actual, a.out)
