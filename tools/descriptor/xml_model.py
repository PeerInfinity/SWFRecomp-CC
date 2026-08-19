#!/usr/bin/env python3
"""Render the parsed playerglobal model as the `describeType` element tree the
`avm2/all_classes/*` fixtures print, and parse those fixtures back.

Both halves produce the same structure, so `check_model.py` can diff them:

    {class-name: {"type": [elem, ...], "factory": [elem, ...]}}

where `elem` is `(tag, ((attr, value), ...), (param, ...))`.
"""

import os
import re

import as_model

VEC_NS = "__AS3__.vec"


# ---------------------------------------------------------------- resolution

class Resolver(object):
    def __init__(self, classes):
        self.classes = classes
        self.by_simple = {}
        for q, k in classes.items():
            self.by_simple.setdefault(k.name, []).append(q)

    def qname(self, k, simple):
        """Fully-qualify a type name as it appears inside class `k`."""
        if simple in ("*", "void", ""):
            return simple or "*"
        m = re.match(r"^Vector\.<(.+)>$", simple)
        if m:
            return "%s::Vector.<%s>" % (VEC_NS, self.qname(k, m.group(1)))
        if "." in simple and "::" not in simple:
            simple = simple.rsplit(".", 1)[-1]
        if simple in as_model.TOP_LEVEL:
            return simple
        imp = k.imports.get(simple) if k is not None else None
        if imp and "." in imp:
            return "%s::%s" % (imp.rsplit(".", 1)[0], simple)
        if k is not None and "%s::%s" % (k.ns, simple) in self.classes:
            return "%s::%s" % (k.ns, simple)
        cands = self.by_simple.get(simple)
        if cands and len(cands) == 1:
            return cands[0]
        if cands:
            # prefer the one in the same package
            for c in cands:
                if k is not None and c.startswith(k.ns + "::"):
                    return c
            return sorted(cands)[0]
        return simple

    def lookup(self, k, simple):
        q = self.qname(k, simple)
        return self.classes.get(q)


# --------------------------------------------------------------- model side

def chain(res, k):
    """[k, base, ..., Object] as Klass objects (Object is synthetic/None)."""
    out = []
    cur = k
    seen = set()
    while cur is not None and cur.qname not in seen:
        seen.add(cur.qname)
        out.append(cur)
        cur = res.lookup(cur, cur.base) if cur.base else None
    return out


def all_interfaces(res, k, min_swf_ok):
    out = []
    seen = set()

    def add(iface):
        if iface is None or iface.qname in seen:
            return
        seen.add(iface.qname)
        out.append(iface.qname)
        for nm in iface.interfaces:
            add(res.lookup(iface, nm))

    for c in chain(res, k):
        for nm in c.interfaces:
            add(res.lookup(c, nm))
    return out


def _param_elems(res, k, params):
    return tuple("<parameter index=\"%d\" type=\"%s\" optional=\"%s\"/>"
                 % (i + 1, res.qname(k, t), "true" if opt else "false")
                 for i, (t, opt) in enumerate(params))


def _uri_attr(owner):
    """The trailing `uri=` attribute describeType prints for a member that an
    INTERFACE declares.

    An interface's members live in that interface's own namespace, so Flash
    reports them with `uri="<package>:<Interface>"` (one colon, not the `::`
    of a qualified class name) after `returnType`/`declaredBy`.  Members of a
    CLASS that implements the interface are ordinary public members and carry
    no uri, so this keys on the declaring class only.  Graded by
    `all_classes/events` (flash.events::IEventDispatcher's five methods) and
    matched by the hand-written flash.accessibility rows in avm2_globals.c.
    """
    if owner is None or not owner.is_interface:
        return ()
    return (("uri", "%s:%s" % (owner.ns, owner.name)),)


def visible(mem, ver):
    return mem.min_swf == 0 or (mem.min_swf != as_model.HIDE
                                and ver >= mem.min_swf)


def describe(res, k, ver):
    """Element lists for `describeType(<class object>)` at SWF version `ver`."""
    tp = [("accessor", (("name", "prototype"), ("access", "readonly"),
                        ("type", "*"), ("declaredBy", "Class")), ()),
          ("extendsClass", (("type", "Class"),), ()),
          ("extendsClass", (("type", "Object"),), ())]
    for (kind, name, is_static), mem in sorted(k.members.items()):
        if not is_static or not visible(mem, ver):
            continue
        if kind == "variable":
            tag = "constant" if mem.has_get else "variable"
            tp.append((tag, (("name", name),
                             ("type", res.qname(k, mem.type))), ()))
        elif kind == "method":
            tp.append(("method", (("name", name), ("declaredBy", k.qname),
                                  ("returnType", res.qname(k, mem.type))),
                       _param_elems(res, k, mem.params)))
        else:
            acc = ("readwrite" if mem.has_get and mem.has_set
                   else "readonly" if mem.has_get else "writeonly")
            tp.append(("accessor", (("name", name), ("access", acc),
                                    ("type", res.qname(k, mem.type)),
                                    ("declaredBy", k.qname)), ()))

    fac = []
    ch = chain(res, k)
    for c in ch[1:]:
        fac.append(("extendsClass", (("type", c.qname),), ()))
    if not k.is_interface:
        fac.append(("extendsClass", (("type", "Object"),), ()))
    for q in all_interfaces(res, k, ver):
        fac.append(("implementsInterface", (("type", q),), ()))
    if k.is_interface:
        for nm in k.interfaces:
            pass  # already covered by all_interfaces

    # instance members: most-derived declaration wins, declaredBy follows the
    # getter half for accessors and the overriding class for methods.
    seen = {}
    for c in ch:
        for (kind, name, is_static), mem in c.members.items():
            if is_static:
                continue
            key = (kind, name)
            prev = seen.get(key)
            if prev is None:
                seen[key] = [c, mem, dict(get=None, set=None)]
                prev = seen[key]
                if kind == "accessor":
                    if mem.has_get:
                        prev[2]["get"] = (c, mem)
                    if mem.has_set:
                        prev[2]["set"] = (c, mem)
            else:
                if kind == "accessor":
                    if prev[2]["get"] is None and mem.has_get:
                        prev[2]["get"] = (c, mem)
                    if prev[2]["set"] is None and mem.has_set:
                        prev[2]["set"] = (c, mem)
    for (kind, name), (c, mem, halves) in sorted(seen.items()):
        if kind == "accessor":
            gc, gm = halves["get"] if halves["get"] else (None, None)
            sc, sm = halves["set"] if halves["set"] else (None, None)
            gates = [m.min_swf for m in (gm, sm) if m is not None]
            gate = min(gates) if gates else 0
            if gate == as_model.HIDE or (gate and ver < gate):
                continue
            acc = ("readwrite" if gm is not None and sm is not None
                   else "readonly" if gm is not None else "writeonly")
            owner = gc if gc is not None else sc
            src = gm if gm is not None else sm
            fac.append(("accessor", (("name", name), ("access", acc),
                                     ("type", res.qname(owner, src.type)),
                                     ("declaredBy", owner.qname))
                        + _uri_attr(owner), ()))
        elif kind == "method":
            if not visible(mem, ver):
                continue
            fac.append(("method", (("name", name), ("declaredBy", c.qname),
                                   ("returnType", res.qname(c, mem.type)))
                        + _uri_attr(c),
                        _param_elems(res, c, mem.params)))
        else:
            if not visible(mem, ver):
                continue
            tag = "constant" if mem.has_get else "variable"
            fac.append((tag, (("name", name),
                              ("type", res.qname(c, mem.type))), ()))
    if k.ctor_params:
        fac.append(("constructor", (), _param_elems(res, k, k.ctor_params)))
    return {"type": tp, "factory": fac}


# ------------------------------------------------------------ fixture side

_SELF = re.compile(r"^<(\w+)((?:\s+\w+=\"[^\"]*\")*)\s*/>$")
_OPEN = re.compile(r"^<(\w+)((?:\s+\w+=\"[^\"]*\")*)\s*>$")
_ATTR = re.compile(r"(\w+)=\"([^\"]*)\"")


def parse_expected(path):
    """{class-name: {"type": [...], "factory": [...]}} from an output.txt."""
    out = {}
    cur = None
    stack = []
    pending = None      # (tag, attrs, [params]) awaiting its closer
    for raw in open(path, encoding="utf-8"):
        line = raw.strip()
        if not line:
            continue
        if line.endswith("not accessible"):
            out.setdefault(line.rsplit(" not accessible", 1)[0].split("::")[-1],
                           None)
            continue
        if line.startswith("</"):
            tag = line[2:-1]
            if pending is not None and pending[0] == tag:
                cur[stack[-1]].append((pending[0], pending[1],
                                       tuple(pending[2])))
                pending = None
            elif tag == "factory":
                stack.pop()
            elif tag == "type":
                stack.pop()
                cur = None
            continue
        m = _SELF.match(line)
        if m:
            tag, attrs = m.group(1), tuple(_ATTR.findall(m.group(2)))
            if tag == "parameter" and pending is not None:
                pending[2].append(line)
            elif tag == "factory":
                pass          # empty factory: `<factory type="..."/>`
            elif cur is not None:
                cur[stack[-1]].append((tag, attrs, ()))
            continue
        m = _OPEN.match(line)
        if m:
            tag, attrs = m.group(1), tuple(_ATTR.findall(m.group(2)))
            if tag == "type":
                name = dict(attrs)["name"]
                cur = {"type": [], "factory": [], "_attrs": attrs}
                out[name.split("::")[-1]] = cur
                stack = ["type"]
            elif tag == "factory":
                stack.append("factory")
            else:
                pending = (tag, attrs, [])
            continue
    return out
