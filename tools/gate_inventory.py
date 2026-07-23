#!/usr/bin/env python3
"""Mechanical inventory of build-mode preprocessor gates in the runtime.

The runtime compiles into three real execution configurations:

    no-graphics      NO_GRAPHICS                       (frame loop: swf_core.c)
    graphics-native  USE_WEBGPU OFFSCREEN_RENDER NDEBUG (frame loop: swf.c)
    browser-WASM     __EMSCRIPTEN__ USE_WEBGPU          (frame loop: swf.c)
                     (and NEITHER NO_GRAPHICS NOR OFFSCREEN_RENDER)

Historic bug pattern: shared code gated `#if defined(NO_GRAPHICS) ||
defined(OFFSCREEN_RENDER)` where the `#else` (= browser-WASM) is missing or
stale.  This script parses the preprocessor structure of the runtime sources,
evaluates every gate under all three configs with three-valued logic (macros
outside the config sets stay *unknown* instead of being guessed), and reports
the sites where browser-WASM receives no code at all.

Usage:
    python3 tools/gate_inventory.py --selftest
    python3 tools/gate_inventory.py                     # text summary
    python3 tools/gate_inventory.py --json out.json
    python3 tools/gate_inventory.py --markdown SWFRecompDocs/reference/browser-wasm-gate-inventory.md

Python 3 stdlib only.  Reads sources; never compiles or writes to them.
"""

import argparse
import json
import os
import re
import subprocess
import sys

# --------------------------------------------------------------------------
# Configuration model
# --------------------------------------------------------------------------

KEY_SYMBOLS = ("NO_GRAPHICS", "OFFSCREEN_RENDER", "__EMSCRIPTEN__")

# For each config: macros known to be defined, and macros known to be
# undefined.  Anything else evaluates to UNKNOWN (three-valued), so the site is
# reported as depends(<macro>) rather than guessed at.
CONFIGS = [
    ("no-graphics", {"NO_GRAPHICS"},
     {"OFFSCREEN_RENDER", "__EMSCRIPTEN__", "USE_WEBGPU",
      "HEADLESS_RENDER_ENABLED"}),
    ("graphics-native", {"USE_WEBGPU", "OFFSCREEN_RENDER", "NDEBUG"},
     {"NO_GRAPHICS", "__EMSCRIPTEN__"}),
    ("browser-WASM", {"__EMSCRIPTEN__", "USE_WEBGPU"},
     {"NO_GRAPHICS", "OFFSCREEN_RENDER"}),
]
CONFIG_NAMES = [c[0] for c in CONFIGS]

# Source roots, relative to the repo root.
INCLUDE_DIRS = [
    "SWFModernRuntime/src",
    "SWFModernRuntime/include",
    "SWFRecomp/wasm_wrappers",
]
EXCLUDE_PARTS = ("/lib/", "/vendor/", "/build/", "/node_modules/")

# --------------------------------------------------------------------------
# Three-valued logic
# --------------------------------------------------------------------------

TRUE, FALSE, UNKNOWN = True, False, None


def v_not(a):
    return UNKNOWN if a is UNKNOWN else (not a)


def v_and(a, b):
    if a is FALSE or b is FALSE:
        return FALSE
    if a is UNKNOWN or b is UNKNOWN:
        return UNKNOWN
    return TRUE


def v_or(a, b):
    if a is TRUE or b is TRUE:
        return TRUE
    if a is UNKNOWN or b is UNKNOWN:
        return UNKNOWN
    return FALSE


# --------------------------------------------------------------------------
# Comment / string stripping (line structure preserved)
# --------------------------------------------------------------------------

def strip_comments(text):
    """Replace comments with spaces, keeping every newline in place."""
    out = []
    i, n = 0, len(text)
    state = "code"  # code | line_comment | block_comment | string | char
    while i < n:
        c = text[i]
        nxt = text[i + 1] if i + 1 < n else ""
        if state == "code":
            if c == "/" and nxt == "/":
                state = "line_comment"
                out.append("  ")
                i += 2
                continue
            if c == "/" and nxt == "*":
                state = "block_comment"
                out.append("  ")
                i += 2
                continue
            if c == '"':
                state = "string"
            elif c == "'":
                state = "char"
            out.append(c)
            i += 1
        elif state == "line_comment":
            if c == "\n":
                state = "code"
                out.append("\n")
            elif c == "\\" and nxt == "\n":
                # continued line comment
                out.append("\n")
                i += 2
                continue
            else:
                out.append(" ")
            i += 1
        elif state == "block_comment":
            if c == "*" and nxt == "/":
                state = "code"
                out.append("  ")
                i += 2
                continue
            out.append("\n" if c == "\n" else " ")
            i += 1
        else:  # string or char literal
            if c == "\\" and nxt:
                out.append(c)
                out.append(nxt)
                i += 2
                continue
            if (state == "string" and c == '"') or (state == "char" and c == "'"):
                state = "code"
            elif c == "\n":  # unterminated literal; recover
                state = "code"
            out.append(c)
            i += 1
    return "".join(out)


# --------------------------------------------------------------------------
# Expression tokenizer + parser (three-valued evaluation)
# --------------------------------------------------------------------------

TOKEN_RE = re.compile(r"""
      (?P<ident>[A-Za-z_][A-Za-z0-9_]*)
    | (?P<num>0[xX][0-9a-fA-F]+|\d+[uUlL]*)
    | (?P<op>&&|\|\||[!()]|<=|>=|==|!=|[<>+\-*/%&|^~?:,])
    | (?P<ws>\s+)
    | (?P<other>.)
""", re.VERBOSE)


def tokenize(expr):
    toks = []
    for m in TOKEN_RE.finditer(expr):
        kind = m.lastgroup
        if kind == "ws":
            continue
        toks.append((kind, m.group()))
    return toks


class Expr:
    """Parsed #if condition, evaluable under a (defined, undefined) config."""

    def __init__(self, text):
        self.text = text
        self.tokens = tokenize(text)
        self.macros = sorted({t for k, t in self.tokens
                              if k == "ident" and t != "defined"})

    def mentions_key_symbol(self):
        return any(m in KEY_SYMBOLS for m in self.macros)

    # -- evaluation ------------------------------------------------------
    def eval(self, defined, undefined):
        """Return (value, unknown_macros)."""
        self._d, self._u, self._unknown = defined, undefined, set()
        self._pos = 0
        try:
            val = self._parse_or()
            if self._pos != len(self.tokens):  # trailing junk -> be honest
                val = UNKNOWN
                self._unknown.add("<unparsed>")
        except _ParseGiveUp:
            val = UNKNOWN
            self._unknown.add("<unparsed>")
        return val, sorted(self._unknown)

    # -- recursive descent ----------------------------------------------
    def _peek(self):
        return self.tokens[self._pos] if self._pos < len(self.tokens) else (None, None)

    def _take(self):
        tok = self._peek()
        self._pos += 1
        return tok

    def _parse_or(self):
        val = self._parse_and()
        while self._peek()[1] == "||":
            self._take()
            val = v_or(val, self._parse_and())
        return val

    def _parse_and(self):
        val = self._parse_unary()
        while self._peek()[1] == "&&":
            self._take()
            val = v_and(val, self._parse_unary())
        return val

    def _parse_unary(self):
        kind, tok = self._peek()
        if tok == "!":
            self._take()
            return v_not(self._parse_unary())
        return self._parse_primary()

    def _parse_primary(self):
        kind, tok = self._take()
        if tok is None:
            raise _ParseGiveUp()
        if tok == "(":
            val = self._parse_or()
            if self._peek()[1] != ")":
                raise _ParseGiveUp()
            self._take()
            return self._maybe_relational(val)
        if kind == "ident" and tok == "defined":
            if self._peek()[1] == "(":
                self._take()
                k2, name = self._take()
                if k2 != "ident":
                    raise _ParseGiveUp()
                if self._peek()[1] != ")":
                    raise _ParseGiveUp()
                self._take()
            else:
                k2, name = self._take()
                if k2 != "ident":
                    raise _ParseGiveUp()
            return self._maybe_relational(self._defined(name))
        if kind == "ident":
            # Bare macro truthiness: a macro we know is undefined is 0 (false);
            # anything else (including known-defined, whose *value* we do not
            # model) is unknown.
            if tok in self._u:
                return self._maybe_relational(FALSE)
            self._unknown.add(tok)
            return self._maybe_relational(UNKNOWN)
        if kind == "num":
            lit = tok.rstrip("uUlL")
            val = int(lit, 0)
            return self._maybe_relational(TRUE if val != 0 else FALSE)
        raise _ParseGiveUp()

    def _maybe_relational(self, val):
        """Arithmetic/comparison operands are not modelled -> unknown."""
        kind, tok = self._peek()
        if tok in ("<", ">", "<=", ">=", "==", "!=", "+", "-", "*", "/", "%",
                   "&", "|", "^", "?", ":", ","):
            # Consume the rest of the expression conservatively.
            depth = 0
            while self._pos < len(self.tokens):
                k2, t2 = self._peek()
                if t2 == "(":
                    depth += 1
                elif t2 == ")":
                    if depth == 0:
                        break
                    depth -= 1
                elif t2 in ("&&", "||") and depth == 0:
                    break
                if k2 == "ident" and t2 != "defined":
                    self._unknown.add(t2)
                self._take()
            self._unknown.add("<arith>")
            return UNKNOWN
        return val

    def _defined(self, name):
        if name in self._d:
            return TRUE
        if name in self._u:
            return FALSE
        self._unknown.add(name)
        return UNKNOWN


class _ParseGiveUp(Exception):
    pass


# --------------------------------------------------------------------------
# File parsing -> tree of Code / Group nodes
# --------------------------------------------------------------------------

DIRECTIVE_RE = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$")


class Code:
    __slots__ = ("lines",)

    def __init__(self):
        self.lines = 0


class Arm:
    __slots__ = ("kind", "cond_text", "expr", "children", "start", "end")

    def __init__(self, kind, cond_text, start):
        self.kind = kind                  # 'if' | 'elif' | 'else'
        self.cond_text = cond_text
        self.expr = Expr(cond_text) if cond_text else None
        self.children = []
        self.start = start
        self.end = start


class Group:
    __slots__ = ("arms", "start", "end", "path")

    def __init__(self, path, start):
        self.arms = []
        self.start = start
        self.end = start
        self.path = path

    def mentions_key_symbol(self):
        return any(a.expr and a.expr.mentions_key_symbol() for a in self.arms)


FUNC_RE = re.compile(
    r"^[A-Za-z_][A-Za-z0-9_ \t\*&]*?\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
NON_FUNC_KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof",
                     "typedef", "else", "do", "case"}


def function_index(text):
    """[(lineno, name)] for top-level function definitions (best-effort).

    A locator hint for the triage pass, not a parser: column-0 lines that look
    like `type name(...)` and are not declarations (`;`) or control flow.
    """
    out = []
    for lineno, line in enumerate(text.split("\n"), 1):
        if not line or line[0] in " \t#}/*)":
            continue
        stripped = line.rstrip()
        if stripped.endswith(";") or stripped.endswith(","):
            continue
        m = FUNC_RE.match(line)
        if not m or m.group(1) in NON_FUNC_KEYWORDS:
            continue
        if line.split("(")[0].strip().split()[0] in NON_FUNC_KEYWORDS:
            continue
        out.append((lineno, m.group(1)))
    return out


def function_at(index, lineno):
    name = ""
    for start, fn in index:
        if start > lineno:
            break
        name = fn
    return name


def logical_lines(text):
    """Yield (lineno, joined_text) with backslash-continuations merged."""
    raw = text.split("\n")
    i = 0
    while i < len(raw):
        start = i + 1
        buf = raw[i]
        while buf.endswith("\\") and i + 1 < len(raw):
            buf = buf[:-1] + " " + raw[i + 1]
            i += 1
        yield start, buf
        i += 1


def parse_file(path, text):
    """Return the top-level children list for a file."""
    root = []
    stack = [(None, root)]   # (group, current children list)
    for lineno, line in logical_lines(text):
        m = DIRECTIVE_RE.match(line)
        if not m:
            if line.strip():
                children = stack[-1][1]
                if not children or not isinstance(children[-1], Code):
                    children.append(Code())
                children[-1].lines += 1
            continue
        kind, rest = m.group(1), m.group(2).strip()
        if kind in ("if", "ifdef", "ifndef"):
            if kind == "ifdef":
                cond = "defined(%s)" % rest.split()[0] if rest.split() else "0"
            elif kind == "ifndef":
                cond = "!defined(%s)" % rest.split()[0] if rest.split() else "0"
            else:
                cond = rest
            g = Group(path, lineno)
            arm = Arm("if", cond, lineno)
            g.arms.append(arm)
            stack[-1][1].append(g)
            stack.append((g, arm.children))
        elif kind in ("elif", "else"):
            if len(stack) < 2:
                continue  # unbalanced; ignore
            g = stack[-1][0]
            g.arms[-1].end = lineno
            stack.pop()
            if kind == "elif":
                arm = Arm("elif", rest, lineno)
            else:
                arm = Arm("else", "", lineno)
            g.arms.append(arm)
            stack.append((g, arm.children))
        else:  # endif
            if len(stack) < 2:
                continue
            g = stack[-1][0]
            g.arms[-1].end = lineno
            g.end = lineno
            stack.pop()
    return root


# --------------------------------------------------------------------------
# Evaluation over the tree
# --------------------------------------------------------------------------

def arm_selected(group, index, defined, undefined):
    """Three-valued: is arm `index` the selected one under this config?"""
    unknown = set()
    val = TRUE
    for j, arm in enumerate(group.arms):
        if arm.kind == "else":
            cond = TRUE
        else:
            cond, unk = arm.expr.eval(defined, undefined)
            unknown.update(unk)
        if j == index:
            val = v_and(val, cond)
            break
        val = v_and(val, v_not(cond))
        if val is FALSE:
            break
    return val, unknown


def lines_seen(children, defined, undefined):
    """(code lines this config compiles, unknown, unknown_macros)."""
    total, unknown_flag, macros = 0, False, set()
    for node in children:
        if isinstance(node, Code):
            total += node.lines
            continue
        for i, arm in enumerate(node.arms):
            sel, unk = arm_selected(node, i, defined, undefined)
            macros.update(unk)
            if sel is FALSE:
                continue
            sub, sub_unknown, sub_macros = lines_seen(arm.children, defined,
                                                      undefined)
            macros.update(sub_macros)
            if sel is UNKNOWN:
                unknown_flag = unknown_flag or sub > 0
                # count nothing: we do not know whether this arm is taken
            else:
                total += sub
                unknown_flag = unknown_flag or sub_unknown
    return total, unknown_flag, macros


def walk_sites(children, path, stack, out):
    """Collect gate sites (groups whose own condition names a key symbol)."""
    for node in children:
        if isinstance(node, Code):
            continue
        is_site = node.mentions_key_symbol()
        if is_site:
            out.append((node, list(stack)))
        # enclosing stack for descendants: (group, arm index)
        for i, arm in enumerate(node.arms):
            walk_sites(arm.children, path, stack + [(node, i)], out)


def enclosing_condition(stack, defined, undefined):
    """Three-valued value of the enclosing gate stack, plus its text."""
    val, macros, texts = TRUE, set(), []
    for group, idx in stack:
        sel, unk = arm_selected(group, idx, defined, undefined)
        macros.update(unk)
        val = v_and(val, sel)
        arm = group.arms[idx]
        texts.append(arm.cond_text if arm.kind != "else"
                     else "else of %s:%d" % (os.path.basename(group.path),
                                             group.start))
    return val, macros, texts


# --------------------------------------------------------------------------
# Site analysis
# --------------------------------------------------------------------------

class Site:
    def __init__(self, path, group, stack):
        self.path = path
        self.group = group
        self.start = group.start
        self.end = group.end
        self.stack_text = []
        self.arms = []              # per-arm: dict(kind, cond, start, end)
        self.per_config = {}        # config -> dict(lines, state, macros)
        self.function = ""          # enclosing C function (best-effort)

    def to_row(self):
        return {
            "file": self.path,
            "function": self.function,
            "start": self.start,
            "end": self.end,
            "condition": self.arms[0]["cond"] if self.arms else "",
            "arms": self.arms,
            "enclosing": self.stack_text,
            "configs": self.per_config,
            "category": self.category,
            "reachable": self.reachable,
        }


def analyse_site(path, group, stack):
    site = Site(path, group, stack)
    for i, arm in enumerate(group.arms):
        entry = {
            "kind": arm.kind,
            "cond": arm.cond_text,
            "start": arm.start,
            "end": arm.end,
            "lines": {},        # code lines *inside* this arm, per config
            "selected": [],     # configs that definitely take this arm
            "maybe": [],        # configs where selection is undecidable
        }
        for name, d, u in CONFIGS:
            n, unk, macros = lines_seen(arm.children, d, u)
            entry["lines"][name] = n
            encl_val, _, _ = enclosing_condition(stack, d, u)
            if encl_val is FALSE:
                continue
            sel, _ = arm_selected(group, i, d, u)
            if sel is TRUE and encl_val is TRUE:
                entry["selected"].append(name)
            elif sel is not FALSE:
                entry["maybe"].append(name)
        site.arms.append(entry)

    reachable = {}
    for name, d, u in CONFIGS:
        encl_val, encl_macros, texts = enclosing_condition(stack, d, u)
        if not site.stack_text:
            site.stack_text = texts
        if encl_val is FALSE:
            site.per_config[name] = {"lines": 0, "state": "unreachable",
                                     "partial_unknown": False,
                                     "macros": [], "arms": []}
            reachable[name] = False
            continue
        reachable[name] = True
        lines, unknown, macros = lines_seen([group], d, u)
        taken = []
        for i, arm in enumerate(group.arms):
            sel, unk = arm_selected(group, i, d, u)
            if sel is TRUE:
                taken.append(i)
            elif sel is UNKNOWN:
                taken.append(i)
                unknown = True
                macros.update(unk)
        if encl_val is UNKNOWN:
            unknown = True
            macros.update(encl_macros)
        # `lines` counts only what the config *definitely* compiles.  So
        # lines > 0 means "definitely gets code" even if some nested region is
        # undecidable; `depends` is reserved for the genuinely undetermined
        # case, where the config may get nothing at all.
        if lines > 0:
            state = "code"
        elif unknown:
            state = "depends"
        else:
            state = "none"
        site.per_config[name] = {
            "lines": lines,
            "state": state,
            "partial_unknown": bool(unknown and lines > 0),
            "macros": sorted(m for m in macros if not m.startswith("<")),
            "arms": taken,
        }
    site.reachable = reachable
    site.category = categorise(site)
    return site


def categorise(site):
    """Classify a site by which *reachable* configs receive code.

    A config whose enclosing gate stack excludes it is `unreachable` here and
    takes no part in the classification — e.g. an `__EMSCRIPTEN__` split nested
    inside `#ifndef NO_GRAPHICS` is not a no-graphics asymmetry.
    """
    ng, gn, bw = CONFIG_NAMES
    st = {n: site.per_config[n]["state"] for n in CONFIG_NAMES}
    ln = {n: site.per_config[n]["lines"] for n in CONFIG_NAMES}
    if st[bw] == "unreachable":
        return "browser-unreachable"
    natives = [n for n in (ng, gn) if st[n] != "unreachable"]
    if any(st[n] == "depends" for n in natives + [bw]):
        return "depends"
    with_code = [n for n in natives if ln[n] > 0]
    if st[bw] == "none" and with_code:
        return "browser-none" if len(with_code) == len(natives) == 2 \
            else "browser-none-partial"
    if ln[bw] > 0 and natives and not with_code:
        return "browser-only"
    if len(natives) == 2 and (ln[ng] > 0) != (ln[gn] > 0):
        return "native-asym"
    return "all-configs"


CATEGORY_ORDER = ["browser-none", "browser-none-partial", "browser-only",
                  "native-asym", "depends", "browser-unreachable",
                  "all-configs"]

CATEGORY_DESC = {
    "browser-none": "browser-WASM gets **zero** code; both native configs get code",
    "browser-none-partial": "browser-WASM gets zero code; exactly one native config gets code (the other gets none, or cannot reach the site)",
    "browser-only": "only browser-WASM gets code (reachable native configs get none)",
    "native-asym": "no-graphics vs graphics-native disagree; browser-WASM gets code",
    "depends": "result hinges on a macro outside the three config sets",
    "browser-unreachable": "the enclosing gate stack excludes browser-WASM entirely",
    "all-configs": "every reachable config receives code (arms may still differ)",
}


# --------------------------------------------------------------------------
# Driver
# --------------------------------------------------------------------------

def source_files(root):
    files = []
    for base in INCLUDE_DIRS:
        abs_base = os.path.join(root, base)
        for dirpath, dirnames, filenames in os.walk(abs_base):
            dirnames.sort()
            rel_dir = "/" + os.path.relpath(dirpath, root).replace(os.sep, "/") + "/"
            if any(part in rel_dir for part in EXCLUDE_PARTS):
                dirnames[:] = []
                continue
            for fn in sorted(filenames):
                if not fn.endswith((".c", ".h")):
                    continue
                rel = os.path.relpath(os.path.join(dirpath, fn), root)
                files.append(rel.replace(os.sep, "/"))
    return sorted(set(files))


def collect(root):
    sites = []
    for rel in source_files(root):
        with open(os.path.join(root, rel), "r", encoding="utf-8",
                  errors="replace") as fh:
            text = fh.read()
        if not any(sym in text for sym in KEY_SYMBOLS):
            continue
        stripped = strip_comments(text)
        tree = parse_file(rel, stripped)
        fn_index = function_index(stripped)
        found = []
        walk_sites(tree, rel, [], found)
        for group, stack in found:
            site = analyse_site(rel, group, stack)
            site.function = function_at(fn_index, site.start)
            sites.append(site)
    sites.sort(key=lambda s: (s.path, s.start))
    return sites


def git_head(root):
    try:
        sha = subprocess.run(["git", "-C", root, "rev-parse", "--short", "HEAD"],
                             capture_output=True, text=True, check=True
                             ).stdout.strip()
        date = subprocess.run(["git", "-C", root, "log", "-1", "--format=%cs"],
                              capture_output=True, text=True, check=True
                              ).stdout.strip()
        return sha, date
    except Exception:
        return "unknown", "unknown"


# --------------------------------------------------------------------------
# Reporting
# --------------------------------------------------------------------------

def text_report(sites, stream=sys.stdout):
    by_cat = {}
    for s in sites:
        by_cat.setdefault(s.category, []).append(s)
    stream.write("gate sites: %d\n" % len(sites))
    for cat in CATEGORY_ORDER:
        if cat in by_cat:
            stream.write("  %-22s %4d\n" % (cat, len(by_cat[cat])))
    stream.write("\nflagged (browser-WASM gets no code):\n")
    for cat in ("browser-none", "browser-none-partial"):
        for s in by_cat.get(cat, []):
            stream.write("  %s:%d-%d  [%s]  %s\n" % (
                s.path, s.start, s.end, cat, s.arms[0]["cond"][:70]))


def md_escape(text):
    return text.replace("|", "\\|").replace("\n", " ")


SHORT = {"no-graphics": "ng", "graphics-native": "gn", "browser-WASM": "bw"}


def arm_summary(site):
    """Per-arm: condition, size, and which configs take it."""
    bits = []
    for a in site.arms:
        cond = a["cond"] if a["kind"] != "else" else "(else)"
        counts = [a["lines"][n] for n in CONFIG_NAMES]
        size = str(counts[0]) if len(set(counts)) == 1 else \
            "/".join(str(c) for c in counts)
        who = [SHORT[n] for n in a["selected"]]
        who += ["%s?" % SHORT[n] for n in a["maybe"]]
        bits.append("`%s` %sL → %s" % (cond, size, ",".join(who) or "nobody"))
    return "; ".join(bits)


TREND_MARKER = "<!-- BEGIN HAND-WRITTEN SECTIONS (preserved on regeneration) -->"


def markdown_report(sites, root, existing_path=None):
    _harvest_triage(existing_path)
    sha, date = git_head(root)
    by_cat = {}
    by_file = {}
    for s in sites:
        by_cat.setdefault(s.category, []).append(s)
        by_file.setdefault(s.path, []).append(s)

    out = []
    w = out.append
    w("# Browser-WASM gate inventory")
    w("")
    w("**Generated** by `tools/gate_inventory.py` — do not hand-edit the")
    w("generated sections. Regenerate with:")
    w("")
    w("```bash")
    w("python3 tools/gate_inventory.py --markdown \\")
    w("    SWFRecompDocs/reference/browser-wasm-gate-inventory.md")
    w("```")
    w("")
    w("Source commit: `%s` (%s). Sites are ordered by path then line, so" % (sha, date))
    w("regenerated inventories diff cleanly.")
    w("")
    w("## Config model")
    w("")
    w("| Config | Known defined | Known undefined | Frame loop |")
    w("|---|---|---|---|")
    loops = {"no-graphics": "`swf_core.c`", "graphics-native": "`swf.c`",
             "browser-WASM": "`swf.c`"}
    for name, d, u in CONFIGS:
        w("| %s | %s | %s | %s |" % (
            name, ", ".join("`%s`" % x for x in sorted(d)),
            ", ".join("`%s`" % x for x in sorted(u)), loops[name]))
    w("")
    w("Every other macro (`WITH_AP`, `SWF_HAVE_LIBAVCODEC`, `HEADLESS_RENDER_ENABLED`")
    w("in the graphics configs, `NDEBUG` outside graphics-native, platform macros,")
    w("…) is **unknown**: the evaluator uses three-valued logic and reports the site")
    w("as `depends` rather than guessing.")
    w("")
    w("## What counts as a site")
    w("")
    w("A *site* is one `#if`/`#elif`/`#else`/`#endif` group whose own arm conditions")
    w("name `NO_GRAPHICS`, `OFFSCREEN_RENDER`, or `__EMSCRIPTEN__`. Nested groups")
    w("count twice, deliberately: their lines roll up into the enclosing site's")
    w("per-config totals, and if the nested condition itself names a key symbol it is")
    w("also a site of its own, evaluated *with its enclosing gate stack applied*. A")
    w("config the enclosing stack excludes is reported `unreachable` and takes no")
    w("part in that site's classification — which is why an `__EMSCRIPTEN__` split")
    w("inside `#ifndef NO_GRAPHICS` is not counted as a no-graphics asymmetry, and")
    w("why almost everything in `swf.c` lands in `*-partial` (no-graphics never")
    w("compiles that file).")
    w("")
    w("Line counts are non-blank, non-comment lines the config actually compiles,")
    w("counted recursively through nested gates.")
    w("")
    w("## Summary")
    w("")
    w("Total gate sites: **%d** across %d files." % (len(sites), len(by_file)))
    w("")
    w("| Category | Sites | Meaning |")
    w("|---|---:|---|")
    for cat in CATEGORY_ORDER:
        if cat in by_cat:
            w("| `%s` | %d | %s |" % (cat, len(by_cat[cat]), CATEGORY_DESC[cat]))
    w("")
    w("### By file")
    w("")
    w("| File | Sites | " + " | ".join("`%s`" % c for c in CATEGORY_ORDER) + " |")
    w("|---|---:|" + "---:|" * len(CATEGORY_ORDER))
    for path in sorted(by_file):
        row = by_file[path]
        counts = [sum(1 for s in row if s.category == c) for c in CATEGORY_ORDER]
        w("| `%s` | %d | %s |" % (path, len(row),
                                  " | ".join(str(c) for c in counts)))
    w("")

    # ---- flagged tables --------------------------------------------------
    w("## Flagged: browser-WASM receives no code")
    w("")
    w("The deliverable. `triage` is intentionally empty — a follow-up session with")
    w("deep runtime context fills it with `intentional` / `suspicious` / `bug`.")
    w("Absence of an `#else` **is** the signal: a site counts even when the missing")
    w("arm is next to a shared fallthrough.")
    w("")
    w("Line columns are `no-graphics / graphics-native / browser-WASM` code lines")
    w("(`–` = the config cannot reach the site at all). The arms column gives each")
    w("arm's size and which configs take it (`ng`/`gn`/`bw`; a trailing `?` means the")
    w("selection depends on a macro outside the config sets).")
    w("")
    for cat in ("browser-none", "browser-none-partial"):
        rows = by_cat.get(cat, [])
        w("### `%s` — %d sites" % (cat, len(rows)))
        w("")
        w("%s." % CATEGORY_DESC[cat].replace("**", ""))
        w("")
        if not rows:
            w("_None._")
            w("")
            continue
        _emit_site_table(w, rows)
    w("## Secondary: browser-WASM-only arms")
    w("")
    w("Sites where only browser-WASM compiles code — the mirror image; useful for")
    w("spotting web paths with no native equivalent (and therefore no test coverage")
    w("in either native mode).")
    w("")
    rows = by_cat.get("browser-only", [])
    w("### `browser-only` — %d sites" % len(rows))
    w("")
    if rows:
        _emit_site_table(w, rows)
    else:
        w("_None._")
        w("")
    w("## Secondary: graphics-native vs no-graphics asymmetry")
    w("")
    w("Browser-WASM gets code, but the two native configs disagree. Mostly benign")
    w("(`NO_GRAPHICS` stubs vs real renderer), listed for completeness — this is the")
    w("population the graphics-per-change CI policy already covers.")
    w("")
    rows = by_cat.get("native-asym", [])
    w("### `native-asym` — %d sites" % len(rows))
    w("")
    if rows:
        _emit_site_table(w, rows, split_by_file=True)
    else:
        w("_None._")
        w("")
    w("## Sites whose outcome depends on non-config macros")
    w("")
    w("Reported honestly rather than guessed. The `depends` column names the macros")
    w("that decide the site.")
    w("")
    rows = by_cat.get("depends", [])
    w("### `depends` — %d sites" % len(rows))
    w("")
    if rows:
        _emit_site_table(w, rows, depends_col=True)
    else:
        w("_None._")
        w("")

    w(TREND_MARKER)
    w("")
    preserved = _read_preserved(existing_path)
    if preserved:
        out.extend(preserved)
    else:
        w("## Trend: browser-WASM fix rate")
        w("")
        w("_(hand-written; fill in with `git log --grep` counts per month)_")
        w("")
    return "\n".join(out) + "\n"


def _emit_site_table(w, rows, split_by_file=False, depends_col=False):
    if split_by_file:
        by_file = {}
        for s in rows:
            by_file.setdefault(s.path, []).append(s)
        for path in sorted(by_file):
            w("#### `%s` — %d" % (path, len(by_file[path])))
            w("")
            _emit_table_body(w, by_file[path], depends_col)
    else:
        _emit_table_body(w, rows, depends_col)


def _emit_table_body(w, rows, depends_col=False):
    cols = ["site", "function", "condition", "enclosing", "lines ng/gn/bw",
            "arms (size → configs)"]
    if depends_col:
        cols.append("depends")
    cols.append("triage")
    w("| " + " | ".join(cols) + " |")
    w("|" + "---|" * len(cols))
    for s in rows:
        lines = "/".join(
            "–" if s.per_config[n]["state"] == "unreachable"
            else str(s.per_config[n]["lines"]) for n in CONFIG_NAMES)
        encl = " ⊃ ".join(md_escape(t) for t in s.stack_text) or "—"
        cells = ["`%s`:%d-%d" % (s.path, s.start, s.end),
                 ("`%s`" % s.function) if s.function else "—",
                 "`%s`" % md_escape(s.arms[0]["cond"]),
                 encl if encl == "—" else "`%s`" % encl,
                 lines,
                 md_escape(arm_summary(s))]
        if depends_col:
            macros = sorted({m for n in CONFIG_NAMES
                             for m in s.per_config[n]["macros"]})
            cells.append(", ".join("`%s`" % m for m in macros) or "—")
        cells.append(_TRIAGE.get("%s:%d-%d" % (s.path, s.start, s.end), ""))
        w("| " + " | ".join(cells) + " |")
    w("")


def _read_preserved(path):
    if not path or not os.path.exists(path):
        return None
    with open(path, "r", encoding="utf-8") as fh:
        text = fh.read()
    if TREND_MARKER not in text:
        return None
    tail = text.split(TREND_MARKER, 1)[1]
    return tail.strip("\n").split("\n")


# Triage values previously filled into the flagged tables. Harvested from the
# existing report before regeneration so a regen never wipes the triage pass.
# Keyed by the site cell ("path:start-end"). Line numbers shift when sources
# change, so a stale key simply drops back to empty — the authoritative
# cluster rulings live in the hand-written tail, which is always preserved.
_TRIAGE = {}


def _harvest_triage(path):
    if not path or not os.path.exists(path):
        return
    with open(path, "r", encoding="utf-8") as fh:
        for line in fh:
            if not line.startswith("| `"):
                continue
            cells = [c.strip() for c in line.strip().strip("|").split("|")]
            if len(cells) < 3 or not cells[-1]:
                continue
            key = cells[0].replace("`", "")
            _TRIAGE[key] = cells[-1]


# --------------------------------------------------------------------------
# Self-test
# --------------------------------------------------------------------------

FIXTURE = r"""
int shared_before;
#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)
    int native_only_a;
    int native_only_b;
#endif
/* comment with #ifdef NO_GRAPHICS inside, must be ignored */
const char *s = "#ifdef OFFSCREEN_RENDER in a string";
#ifdef NO_GRAPHICS
    int ng_arm;
#elif defined(OFFSCREEN_RENDER)
    int gn_arm;
    #ifdef HEADLESS_RENDER_ENABLED
        int headless_extra;
    #endif
#else
    int browser_arm;
#endif
#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)
    int browser_only_1;
#endif
#if defined(WITH_AP) && !defined(__EMSCRIPTEN__)
    int depends_on_with_ap;
#endif
#ifndef NO_GRAPHICS
    int not_ng;
    #ifdef __EMSCRIPTEN__
        int nested_browser;
    #else
        int nested_native_graphics;
    #endif
#endif
"""


def selftest():
    tree = parse_file("fixture.c", strip_comments(FIXTURE))
    found = []
    walk_sites(tree, "fixture.c", [], found)
    sites = [analyse_site("fixture.c", g, st) for g, st in found]
    sites.sort(key=lambda s: s.start)
    got = [(s.start, s.category,
            tuple(s.per_config[n]["lines"] for n in CONFIG_NAMES),
            tuple(s.per_config[n]["state"] for n in CONFIG_NAMES))
           for s in sites]
    expect = [
        # `#if NO_GRAPHICS || OFFSCREEN_RENDER` with no #else -> the classic.
        (3, "browser-none", (2, 2, 0), ("code", "code", "none")),
        # three-way if/elif/else: every config gets its own arm.  The nested
        # HEADLESS_RENDER_ENABLED region is undecidable, but graphics-native
        # already has 1 definite line, so it is `code`, not `depends`.
        (9, "all-configs", (1, 1, 1), ("code", "code", "code")),
        # !NG && !OR -> browser only.
        (19, "browser-only", (0, 0, 1), ("none", "none", "code")),
        # WITH_AP is outside the config sets -> depends for the native pair;
        # !defined(__EMSCRIPTEN__) is false under browser, so browser is
        # decided (no code) while the others hinge on WITH_AP.
        (22, "depends", (0, 0, 0), ("depends", "depends", "none")),
        # #ifndef NO_GRAPHICS: nested gate lines roll up into this site.
        (25, "native-asym", (0, 2, 2), ("none", "code", "code")),
        # ...and the nested __EMSCRIPTEN__ split is *also* a site of its own,
        # with no-graphics excluded by the enclosing stack (so it is not
        # mis-flagged as a native asymmetry).
        (27, "all-configs", (0, 1, 1), ("unreachable", "code", "code")),
    ]
    ok = True
    if got != expect:
        ok = False
        print("selftest FAILED")
        print("  got:    %r" % (got,))
        print("  expect: %r" % (expect,))

    # nested rollup: the #ifndef NO_GRAPHICS arm must include the lines of the
    # nested __EMSCRIPTEN__ gate that the config actually takes.
    nested = [s for s in sites if s.start == 25][0]
    if nested.arms[0]["lines"]["graphics-native"] != 2:
        ok = False
        print("selftest FAILED: nested rollup wrong: %r" % (nested.arms,))
    # ...and the nested site must carry its enclosing condition.
    inner = [s for s in sites if s.start == 27][0]
    if not inner.stack_text or "NO_GRAPHICS" not in inner.stack_text[0]:
        ok = False
        print("selftest FAILED: enclosing stack missing: %r" % (inner.stack_text,))

    # expression evaluator spot checks
    checks = [
        ("defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)",
         {"NO_GRAPHICS"}, {"OFFSCREEN_RENDER"}, TRUE),
        ("!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)",
         {"__EMSCRIPTEN__"}, {"NO_GRAPHICS", "OFFSCREEN_RENDER"}, TRUE),
        ("defined(WITH_AP) && defined(NO_GRAPHICS)",
         {"NO_GRAPHICS"}, set(), UNKNOWN),
        ("defined(WITH_AP) && defined(NO_GRAPHICS)",
         set(), {"NO_GRAPHICS"}, FALSE),
        ("MAX_FRAMES > 0", set(), set(), UNKNOWN),
        ("!(defined(A) || defined(B))", set(), {"A", "B"}, TRUE),
        ("defined A", {"A"}, set(), TRUE),
        ("0", set(), set(), FALSE),
        ("1", set(), set(), TRUE),
    ]
    for text, d, u, want in checks:
        val, _ = Expr(text).eval(d, u)
        if val is not want:
            ok = False
            print("selftest FAILED: %r -> %r (want %r)" % (text, val, want))

    # comment/string stripping must not create phantom directives
    stripped = strip_comments(FIXTURE)
    if "#ifdef NO_GRAPHICS inside" in stripped:
        ok = False
        print("selftest FAILED: block comment not stripped")
    if stripped.count("\n") != FIXTURE.count("\n"):
        ok = False
        print("selftest FAILED: line count changed by comment stripping")

    print("selftest %s (%d fixture sites)" % ("OK" if ok else "FAILED", len(sites)))
    return 0 if ok else 1


# --------------------------------------------------------------------------
# Cross-check against the real C preprocessor
# --------------------------------------------------------------------------

CPP_DEFS = {
    "no-graphics": ["-DNO_GRAPHICS"],
    "graphics-native": ["-DUSE_WEBGPU", "-DOFFSCREEN_RENDER", "-DNDEBUG"],
    "browser-WASM": ["-DUSE_WEBGPU", "-D__EMSCRIPTEN__"],
}


def verify_cpp(sites, root, stream=sys.stdout):
    """Feed each site's own text to `cpp` and compare surviving line counts.

    Only sites with no unknown macros are compared: `cpp` treats an undefined
    macro as false, while this tool deliberately reports `depends`, so the two
    legitimately disagree there.  Fragments containing `#include`/`#define`/
    `#pragma` are skipped (cpp consumes or expands them).
    """
    checked = mismatches = skipped = 0
    for site in sites:
        text = open(os.path.join(root, site.path), encoding="utf-8",
                    errors="replace").read().split("\n")
        frag = "\n".join(text[site.start - 1:site.end])
        if re.search(r"^\s*#\s*(include|define|undef|pragma)\b", frag, re.M):
            skipped += 1
            continue
        if any(site.per_config[n]["macros"] or
               site.per_config[n]["partial_unknown"]
               for n in CONFIG_NAMES if site.per_config[n]["state"] != "unreachable"):
            skipped += 1
            continue
        for name in CONFIG_NAMES:
            if site.per_config[name]["state"] == "unreachable":
                continue
            proc = subprocess.run(["cpp", "-P", "-nostdinc", "-x", "c"] +
                                  CPP_DEFS[name] + ["-"], input=frag,
                                  capture_output=True, text=True)
            if proc.returncode != 0:
                continue
            got = len([l for l in proc.stdout.split("\n") if l.strip()])
            want = site.per_config[name]["lines"]
            checked += 1
            if got != want:
                mismatches += 1
                stream.write("MISMATCH %s:%d [%s] tool=%d cpp=%d\n" % (
                    site.path, site.start, name, want, got))
    stream.write("cpp cross-check: %d (site,config) pairs, %d sites skipped, "
                 "%d mismatches\n" % (checked, skipped, mismatches))
    return 1 if mismatches else 0


# --------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--root", default=None, help="repo root (default: auto)")
    ap.add_argument("--json", metavar="PATH", help="write the full inventory as JSON")
    ap.add_argument("--markdown", metavar="PATH",
                    help="write the markdown report (preserves hand-written tail)")
    ap.add_argument("--selftest", action="store_true", help="run the embedded fixture test")
    ap.add_argument("--verify-cpp", action="store_true",
                    help="cross-check per-config line counts against `cpp`")
    args = ap.parse_args()

    if args.selftest:
        return selftest()

    root = args.root or os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    sites = collect(root)

    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump([s.to_row() for s in sites], fh, indent=1, sort_keys=True)
            fh.write("\n")
    if args.markdown:
        text = markdown_report(sites, root, existing_path=args.markdown)
        with open(args.markdown, "w", encoding="utf-8") as fh:
            fh.write(text)
        print("wrote %s (%d sites)" % (args.markdown, len(sites)))
    if args.verify_cpp:
        return verify_cpp(sites, root)
    if not args.json and not args.markdown:
        text_report(sites)
    return 0


if __name__ == "__main__":
    sys.exit(main())
