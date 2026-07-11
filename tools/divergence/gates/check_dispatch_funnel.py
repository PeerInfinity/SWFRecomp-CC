#!/usr/bin/env python3
"""Static funnel gate for the Function-Dispatch Consolidation (Stage 5).

Enforces three invariants over SWFModernRuntime/src/actionmodern/*.c after the
Stage 0-4 migrations funneled every surveyed dispatcher through
invokeFunctionValue():

1. RAW-DISPATCH ALLOWLIST. Every raw `->simple_func(...)` / `->advanced_func(...)`
   invocation must sit inside a function on the checked-in allowlist below.
   The allowlist is the post-Stage-4 steady state: the invokeFunctionValue
   core itself, invokeSpecialFunction (one caller left: lv_url_encode's
   _global.escape override), and the CONSTRUCTOR family (NewObject/NewMethod,
   registered-class ctors, boxing ctors, virtual setters and friends), which
   was never in the dispatcher survey. Adding a NEW raw call site fails this
   gate — route it through invokeFunctionValue (or extend the allowlist in
   the same commit as the design discussion that justifies it).

2. NO INV_BASE_CLIP | INV_VERSION_SWITCH PAIRING. The core's INV_BASE_CLIP
   gate reads g_swf_version AFTER INV_VERSION_SWITCH has installed the
   callee's version, so pairing them silently flips the base-clip gate to the
   callee's version (the MC arms' historical accident, unified away by
   normalization pass (b)). An arm that needs both must compute the base-clip
   switch itself, caller-gated, bracketing the core call (many precedents:
   watch Site B, onLoad/onConstruct, EI, LV/XML/sound, c_f_w_t).

3. NO RESURRECTING INV_LOCAL_SCOPE_UNDER_CAPTURED. The scope-order inversion
   was flipped by normalization pass (b) (locals are the innermost scope; the
   flag and its core branch were deleted). Any non-comment reference fails.

Usage:  python3 tools/divergence/gates/check_dispatch_funnel.py
Exit 0 + "GATE-GREEN" on pass; non-zero + reasons on fail.
"""
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent.parent
SRC_DIR = REPO / "SWFModernRuntime" / "src" / "actionmodern"

# (file, enclosing function) pairs allowed to invoke simple_func/advanced_func
# raw. Inventory taken at the Stage-5 gate introduction (post pass (b));
# everything here is either the core, the last invokeSpecialFunction caller,
# or the constructor/accessor-native family that the dispatcher survey never
# covered (each a candidate for its own future consolidation stage).
ALLOWLIST = {
    # The core itself.
    ("action.c", "invokeFunctionValue"),
    # The legacy special-function core — ONE caller left (lv_url_encode's
    # _global.escape override); migrating it deletes this entry.
    ("action.c", "invokeSpecialFunction"),
    # Primitive auto-boxing ctors (String/Number/Boolean wrappers).
    ("action.c", "tryAutoBoxPrimitive"),
    # The constructor family — never in the dispatcher survey; each is a
    # candidate for its own future consolidation stage.
    ("action.c", "actionNewObject"),
    ("action.c", "actionNewMethod"),
    ("action.c", "invokeNativeSuperConstructor"),
    ("registered_class.c", "actionInvokeRegisteredClassConstructor"),
    ("action.c", "bdRectangleGetter"),          # boundsObject lazy Rectangle ctor
    # Super-ctor / interface corners kept raw inside the two big opcode arms.
    ("action.c", "actionCallMethod"),
    ("action.c", "actionCallFunction"),
    # Native fast paths (virtual setters on registerClass'd MCs, TextField
    # StyleSheet transform, Date valueOf).
    ("action.c", "actionSetMember"),
    ("action.c", "applyInitObjectPropToMC"),
    ("action.c", "callStyleSheetTransform"),
    ("date.c", "date_arg_to_double"),
}

CALL_RE = re.compile(r"->\s*(simple_func|advanced_func)\s*\(|\)\s*\w*->(simple_func|advanced_func)\)\s*\(")
# Raw invocation forms in this codebase:
#   func->advanced_func(app_context, ...)
#   ((ActionVar(*)(SWFAppContext*))func->simple_func)(app_context)
RAW_RE = re.compile(
    r"(?:->\s*advanced_func\s*\(\s*app_context)|"
    r"(?:->\s*simple_func\s*\)\s*\(\s*app_context)|"
    r"(?:->\s*simple_func\s*\(\s*app_context)"
)

FUNC_DEF_RE = re.compile(r"^(?:static\s+)?(?:inline\s+)?[A-Za-z_][A-Za-z0-9_]*[\s\*]+([A-Za-z_][A-Za-z0-9_]*)\s*\(")


def strip_comments(text: str) -> str:
    # Line-order-aware scanner: a `/*` inside a `//` comment must NOT open a
    # block (action.c has `bitmapdata_/*` glob text in a line comment that a
    # naive block-first regex treats as a comment spanning ~9k lines,
    # swallowing real dispatch sites). String literals are not tracked — the
    # sources keep comment tokens out of strings.
    out = []
    i, n = 0, len(text)
    in_block = in_line = False
    while i < n:
        c = text[i]
        two = text[i:i+2]
        if in_block:
            if two == "*/":
                in_block = False
                i += 2
                continue
            out.append("\n" if c == "\n" else " ")
            i += 1
        elif in_line:
            if c == "\n":
                in_line = False
                out.append("\n")
            i += 1
        else:
            if two == "/*":
                in_block = True
                i += 2
            elif two == "//":
                in_line = True
                i += 2
            else:
                out.append(c)
                i += 1
    return "".join(out)


def enclosing_function(lines, idx):
    for i in range(idx, -1, -1):
        m = FUNC_DEF_RE.match(lines[i])
        if m and not lines[i].rstrip().endswith(";"):
            return m.group(1)
    return "<unknown>"


def main() -> int:
    failures = []
    for path in sorted(SRC_DIR.glob("*.c")):
        raw = path.read_text(errors="replace")
        text = strip_comments(raw)
        lines = text.split("\n")

        for i, line in enumerate(lines):
            if RAW_RE.search(line):
                fn = enclosing_function(lines, i)
                if (path.name, fn) not in ALLOWLIST:
                    failures.append(
                        f"{path.name}:{i+1}: raw dispatch in `{fn}` not on the allowlist "
                        f"— route through invokeFunctionValue"
                    )

        # Rule 2: both flags in one statement. Join physical lines into
        # statements (split on ';' and '{') so multi-line flag expressions
        # are caught. ONE exemption: the core's opts==NULL default superset
        # ("u32 flags = opts ? opts->flags : ...") — that pairing IS the
        # accessor family's pinned pre-Stage-1 behavior (its base-clip gate
        # has always read the callee-installed version); every explicit
        # opts-passing arm must still keep the two apart.
        for stmt_i, stmt in enumerate(re.split(r"[;{]", text)):
            if "INV_BASE_CLIP" in stmt and "INV_VERSION_SWITCH" in stmt:
                if "opts ? opts->flags" in stmt:
                    continue  # the core's documented accessor-default superset
                snippet = " ".join(stmt.split())[:120]
                failures.append(
                    f"{path.name}: INV_BASE_CLIP paired with INV_VERSION_SWITCH in one "
                    f"statement — compute the base-clip switch in the arm, caller-gated "
                    f"(offending statement: `{snippet}...`)"
                )

        # Rule 3: the removed flag must stay removed.
        for i, line in enumerate(lines):
            if "INV_LOCAL_SCOPE_UNDER_CAPTURED" in line:
                failures.append(
                    f"{path.name}:{i+1}: INV_LOCAL_SCOPE_UNDER_CAPTURED was removed by "
                    f"normalization pass (b) — do not resurrect the scope-order inversion"
                )

    # Rule 3 also covers the header (the #define must not come back).
    hdr = REPO / "SWFModernRuntime" / "include" / "actionmodern" / "action_internal.h"
    hdr_text = strip_comments(hdr.read_text(errors="replace"))
    if "INV_LOCAL_SCOPE_UNDER_CAPTURED" in hdr_text:
        failures.append("action_internal.h: INV_LOCAL_SCOPE_UNDER_CAPTURED #define resurrected")

    if failures:
        print("GATE-RED: dispatch funnel violations:")
        for f in failures:
            print("  " + f)
        return 1
    print("GATE-GREEN: dispatch funnel intact "
          "(raw sites allowlisted; no INV_BASE_CLIP|INV_VERSION_SWITCH pairing; "
          "scope-order flag stays deleted)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
