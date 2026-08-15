#!/usr/bin/env python3
"""Parse Ruffle's playerglobal ActionScript stubs into a describeType model.

The .as files under `<ruffle>/core/src/avm2/globals/` are Ruffle's transcription
of Adobe's playerglobal.swc: they carry the full public signature of every
builtin class (parameter types, defaults, return types) plus the `[API("N")]`
annotations that gate a member/class to a minimum player version.  That makes
them the natural source for the `describeType` descriptor tables the runtime
needs (`SWFModernRuntime/src/avm2/avm2_globals.c`, the `dt_*` region), and it
means those tables can be DERIVED rather than hand-transcribed from the
expected outputs of the `avm2/all_classes/*` tests.

This module is the parser + model half; `gen_display_descriptors.py` is the C
emitter and `check_model.py` grades the model against the expected files.
"""

import os
import re
import sys

# --------------------------------------------------------------------------
# [API("N")] -> minimum SWF file version.
#
# Ruffle's `core/src/avm2/api_version.rs` numbers the versions with
# `ordinal = N - 660`.  The table is NOT uniformly strided below ordinal 12,
# and every AIR_* version maps to `VM_INTERNAL` under a Flash Player runtime,
# i.e. the member is hidden at EVERY SWF version rather than rounded up to the
# next one.  Verified empirically against the six all_classes/display expected
# files (see session16-fanout-reports/wave1-all-classes-display.md 2.4).
HIDE = 255  # AIR-only: never visible to a Flash Player runtime

_ORD_BELOW_12 = {
    0: 0,     # ALL_VERSIONS
    2: 10,    # FP_10_0
    5: 10,    # FP_10_0_32
    7: 10,    # FP_10_1
    10: 11,   # FP_10_2  (SWF file version stepped 10 -> 11 at FP 10.2)
}


def api_min_swf(n):
    """Map an [API("N")] annotation to the first SWF version that shows it."""
    ordinal = int(n) - 660
    if ordinal < 12:
        return _ORD_BELOW_12.get(ordinal, HIDE)
    if ordinal % 2 == 1:
        return HIDE                      # AIR_*
    return 12 + (ordinal - 12) // 2


# --------------------------------------------------------------------------

# Names that describeType prints unqualified (the top-level package).
TOP_LEVEL = {
    "void", "*", "Object", "Class", "Function", "Boolean", "Number", "int",
    "uint", "String", "Array", "Error", "Date", "RegExp", "XML", "XMLList",
    "Namespace", "QName", "Math", "JSON", "ArgumentError", "DefinitionError",
    "EvalError", "RangeError", "ReferenceError", "SecurityError",
    "SyntaxError", "TypeError", "URIError", "VerifyError",
    "UninitializedError",
}


class Member(object):
    __slots__ = ("kind", "name", "type", "params", "min_swf", "is_static",
                 "has_get", "has_set", "override", "uri", "value",
                 "get_min_swf", "set_min_swf")

    def __init__(self, kind, name):
        self.kind = kind          # "method" | "accessor" | "variable"
        self.name = name
        self.type = "*"
        self.params = []          # list of (type, optional)
        self.min_swf = 0
        self.is_static = False
        self.has_get = False
        self.has_set = False
        self.override = False
        self.uri = None
        self.value = None
        self.get_min_swf = None
        self.set_min_swf = None


class Klass(object):
    __slots__ = ("ns", "name", "base", "interfaces", "is_interface", "final",
                 "dynamic", "min_swf", "members", "ctor_params", "has_ctor",
                 "imports")

    def __init__(self, ns, name):
        self.ns = ns
        self.name = name
        self.base = None
        self.interfaces = []
        self.is_interface = False
        self.final = False
        self.dynamic = False
        self.min_swf = 0
        self.members = {}         # (kind, name, is_static) -> Member
        self.ctor_params = []
        self.has_ctor = False
        self.imports = {}

    @property
    def qname(self):
        return "%s::%s" % (self.ns, self.name) if self.ns else self.name


_COMMENT_BLOCK = re.compile(r"/\*.*?\*/", re.S)
_COMMENT_LINE = re.compile(r"//[^\n]*")
_API = re.compile(r'\[\s*API\s*\(\s*"(\d+)"\s*\)\s*\]')
_CLASS = re.compile(
    r"\b(class|interface)\s+([A-Za-z0-9_$]+)"
    r"(?:\s+extends\s+([A-Za-z0-9_$.,\s]+?))?"
    r"(?:\s+implements\s+([^{]+?))?\s*\{")


def _strip_comments(src):
    src = _COMMENT_BLOCK.sub("", src)
    src = _COMMENT_LINE.sub("", src)
    return src


def _split_commas(text):
    """Split on top-level commas."""
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [p.strip() for p in out if p.strip()]


def _match_paren(src, i):
    """`src[i]` is '('; return the index just past the matching ')'."""
    depth = 0
    while i < len(src):
        if src[i] == "(":
            depth += 1
        elif src[i] == ")":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return i


def parse_file(path):
    """Return the list of Klass declared in one .as file (usually one)."""
    src = _strip_comments(open(path, encoding="utf-8").read())
    m = re.search(r"\bpackage\s+([A-Za-z0-9_.]*)\s*\{", src)
    ns = m.group(1) if m else ""
    imports = {}
    for imp in re.findall(r"\bimport\s+([A-Za-z0-9_.$]+)\s*;", src):
        imports[imp.rsplit(".", 1)[-1]] = imp
    out = []
    for cm in _CLASS.finditer(src):
        head = src[max(0, cm.start() - 400):cm.start()]
        brace = max(head.rfind("}"), head.rfind(";"))
        head = head[brace + 1:]
        api = _API.findall(head)
        k = Klass(ns, cm.group(2))
        k.is_interface = cm.group(1) == "interface"
        k.dynamic = re.search(r"\bdynamic\b", head) is not None
        k.final = re.search(r"\bfinal\b", head) is not None
        k.min_swf = api_min_swf(api[-1]) if api else 0
        ext = (cm.group(3) or "").strip()
        if k.is_interface:
            k.interfaces = [x.strip().rsplit(".", 1)[-1]
                            for x in _split_commas(ext)] if ext else []
        elif ext:
            k.base = ext.rsplit(".", 1)[-1]
        if cm.group(4):
            k.interfaces = [x.strip().rsplit(".", 1)[-1]
                            for x in _split_commas(cm.group(4))]
        k.imports = imports
        _parse_body(src, cm.end(), k)
        out.append(k)
    return out


def _body_end(src, start):
    depth = 1
    i = start
    while i < len(src) and depth:
        if src[i] == "{":
            depth += 1
        elif src[i] == "}":
            depth -= 1
        i += 1
    return i


_FUNC = re.compile(
    r"(?P<mods>(?:\b(?:public|private|protected|internal|static|native|"
    r"override|final|AS3)\b[ \t\r\n]+)*)"
    r"function\s+(?:(?P<acc>get|set)\s+)?(?P<name>[A-Za-z0-9_$]+)\s*\(")
_VAR = re.compile(
    r"(?P<mods>(?:\b(?:public|private|protected|internal|static)\b\s+)*)"
    r"\b(?P<vk>var|const)\s+(?P<name>[A-Za-z0-9_$]+)\s*:"
    r"\s*(?P<type>[A-Za-z0-9_$.<>*]+)\s*(?:=\s*(?P<val>[^;]+))?;")


def _parse_body(src, start, k):
    end = _body_end(src, start)
    body = src[start:end - 1]
    for m in _FUNC.finditer(body):
        mods = m.group("mods")
        if re.search(r"\b(private|protected|internal)\b", mods):
            continue
        if "public" not in mods and not k.is_interface:
            continue
        name = m.group("name")
        popen = m.end() - 1
        pclose = _match_paren(body, popen)
        params_txt = body[popen + 1:pclose - 1]
        rest = body[pclose:pclose + 200]
        rt = re.match(r"\s*:\s*([A-Za-z0-9_$.<>*]+)", rest)
        ret = rt.group(1) if rt else "*"
        api = _api_before(body, m.start())
        is_static = "static" in mods
        acc = m.group("acc")
        if name == k.name and not acc:
            k.has_ctor = True
            k.ctor_params = _params(params_txt)
            continue
        if acc:
            key = ("accessor", name, is_static)
            mem = k.members.get(key)
            if mem is None:
                mem = Member("accessor", name)
                mem.is_static = is_static
                k.members[key] = mem
            if acc == "get":
                mem.has_get = True
                mem.type = ret
                mem.get_min_swf = api
            else:
                mem.has_set = True
                ps = _params(params_txt)
                if not mem.has_get and ps:
                    mem.type = ps[0][0]
                mem.set_min_swf = api
            if "override" in mods:
                mem.override = True
        else:
            mem = Member("method", name)
            mem.is_static = is_static
            mem.type = ret
            mem.params = _params(params_txt)
            mem.min_swf = api
            mem.override = "override" in mods
            k.members[("method", name, is_static)] = mem
    for m in _VAR.finditer(body):
        mods = m.group("mods")
        if re.search(r"\b(private|protected|internal)\b", mods):
            continue
        if "public" not in mods:
            continue
        is_static = "static" in mods
        mem = Member("variable", m.group("name"))
        mem.is_static = is_static
        mem.type = m.group("type")
        mem.min_swf = _api_before(body, m.start())
        mem.value = (m.group("val") or "").strip()
        mem.has_get = m.group("vk") == "const"   # has_get doubles as is_const
        k.members[("variable", m.group("name"), is_static)] = mem
    # An accessor's visibility gate follows the half that exists; when both
    # halves carry one, the lower wins (the member appears as soon as either
    # half does, reported with the getter's type).
    for mem in k.members.values():
        if mem.kind != "accessor":
            continue
        gates = [g for g in (mem.get_min_swf, mem.set_min_swf) if g is not None]
        mem.min_swf = min(gates) if gates else 0


def _api_before(body, pos):
    """The [API("N")] annotation attached to the declaration starting at pos."""
    head = body[max(0, pos - 300):pos]
    cut = max(head.rfind(";"), head.rfind("}"), head.rfind("{"))
    head = head[cut + 1:]
    found = _API.findall(head)
    return api_min_swf(found[-1]) if found else 0


def _params(text):
    out = []
    for p in _split_commas(text):
        if p.startswith("..."):
            continue
        mm = re.match(r"([A-Za-z0-9_$]+)\s*:\s*([A-Za-z0-9_$.<>*]+)"
                      r"(?:\s*=\s*(.+))?$", p.strip(), re.S)
        if mm is None:
            out.append(("*", False))
            continue
        out.append((mm.group(2), mm.group(3) is not None))
    return out


def load_globals(root):
    """Parse every .as under `root`; return {qname: Klass}."""
    classes = {}
    for dirpath, _dirs, files in os.walk(root):
        for f in sorted(files):
            if not f.endswith(".as"):
                continue
            for k in parse_file(os.path.join(dirpath, f)):
                classes.setdefault(k.qname, k)
    return classes


if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else \
        os.path.expanduser("~/CC/ruffle/core/src/avm2/globals")
    cs = load_globals(root)
    sys.stderr.write("parsed %d classes\n" % len(cs))
    for q in sorted(cs):
        if q.startswith("flash.display::"):
            k = cs[q]
            print("%-46s base=%-22s api=%-3s iface=%-24s members=%3d ctor=%d%s"
                  % (q, k.base, k.min_swf, ",".join(k.interfaces),
                     len(k.members), len(k.ctor_params),
                     " FINAL" if k.final else ""))
