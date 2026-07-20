#!/usr/bin/env python3
"""abcmap.py — map generated abc<N>_m<M> method symbols to Class.method names.

Parses the recompiler's emitted abc<N>_tables.c (strings, multinames, classes,
instance/class trait arrays) and prints  method_index -> Qualified.name.

Usage: abcmap.py <RecompiledABC dir> [abc_index]
"""
import re, sys, os

d = sys.argv[1]
idx = sys.argv[2] if len(sys.argv) > 2 else "0"
src = open(os.path.join(d, "abc%s_tables.c" % idx)).read()


def rows(arrname):
    """Return list of raw '{...}' row bodies for `static const T <arrname>[] = {...};`"""
    m = re.search(r"\b%s\[\]\s*=\s*\{" % re.escape(arrname), src)
    if not m:
        return []
    i = m.end()
    depth = 1
    out = []
    cur = None
    while i < len(src) and depth > 0:
        c = src[i]
        if c == '{':
            depth += 1
            if depth == 2:
                cur = i + 1
        elif c == '}':
            depth -= 1
            if depth == 1 and cur is not None:
                out.append(src[cur:i])
                cur = None
        i += 1
    return out


def toplevel_split(s):
    """Split a row body on commas not nested in braces."""
    parts, depth, cur = [], 0, ""
    for c in s:
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
        if c == ',' and depth == 0:
            parts.append(cur.strip()); cur = ""
        else:
            cur += c
    if cur.strip():
        parts.append(cur.strip())
    return parts


# --- strings: { len, "text" }
# tables already emit their index-0 sentinel row
strings = []
for r in rows("abc%s_strings" % idx):
    m = re.search(r'"((?:[^"\\]|\\.)*)"', r)
    strings.append(m.group(1) if m else "?")

# --- namespaces: { kind, name_string_index }
namespaces = []
for r in rows("abc%s_namespaces" % idx):
    p = toplevel_split(r)
    namespaces.append((int(p[0]), int(p[1])))

# --- multinames: { kind, ns, name, ns_set, base, npar, params }
multinames = []
for r in rows("abc%s_multinames" % idx):
    p = toplevel_split(r)
    multinames.append((int(p[0]), int(p[1]), int(p[2])))


def mn_name(i):
    if i <= 0 or i >= len(multinames):
        return "?mn%d" % i
    _, ns, nm = multinames[i]
    base = strings[nm] if nm < len(strings) else "?s%d" % nm
    if ns and ns < len(namespaces):
        nsname = strings[namespaces[ns][1]] if namespaces[ns][1] < len(strings) else ""
        if nsname:
            return "%s::%s" % (nsname, base)
    return base


KIND = {0: "slot", 1: "method", 2: "getter", 3: "setter", 4: "class", 5: "function", 6: "const"}

# --- classes: name_mn, super_mn, flags, has_pns, pns, ifc_n, ifc, iinit,
#              cinit, it_n, it, ct_n, ct
method_owner = {}
for r in rows("abc%s_classes" % idx):
    p = toplevel_split(r)
    cname = mn_name(int(p[0]))
    iinit, cinit = int(p[7]), int(p[8])
    method_owner[iinit] = "%s/ctor" % cname
    if cinit:
        method_owner[cinit] = "%s/cinit" % cname
    for tarr, scope in ((p[10], "inst"), (p[12], "static")):
        if tarr == "NULL":
            continue
        for tr in rows(tarr):
            tp = toplevel_split(tr)
            kind, nmn, meth = int(tp[0]), int(tp[1]), int(tp[4])
            if kind in (1, 2, 3, 5):
                tag = "" if kind == 1 else "/" + KIND[kind]
                method_owner[meth] = "%s.%s%s%s" % (
                    cname, mn_name(nmn), tag, "" if scope == "inst" else " [static]")

# --- scripts: init_method, trait_count, traits
for r in rows("abc%s_scripts" % idx):
    p = toplevel_split(r)
    method_owner.setdefault(int(p[0]), "<script init>")
    if p[2] != "NULL":
        for tr in rows(p[2]):
            tp = toplevel_split(tr)
            if int(tp[0]) in (1, 2, 3, 5):
                method_owner[int(tp[4])] = "<global>.%s" % mn_name(int(tp[1]))

for m in sorted(method_owner):
    print("abc%s_m%d\t%s" % (idx, m, method_owner[m]))
