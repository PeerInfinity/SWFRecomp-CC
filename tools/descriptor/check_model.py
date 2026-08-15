#!/usr/bin/env python3
"""Grade the parsed playerglobal model against the all_classes expected files.

This is the arc's free acceptance test: it needs no runtime build, and any
mismatch it reports is a bug in the model (and therefore in the C tables the
generator would emit).

    python3 tools/descriptor/check_model.py [suite-dir] [package]
    python3 tools/descriptor/check_model.py --actual OURS.txt EXPECTED.txt

`suite-dir` defaults to `ruffle-tests/tests/swfs/avm2/all_classes/display`.

The `--actual` form is the second half of the loop: a STRUCTURAL diff of one of
our own `--save-actual` captures against the expected file, keyed on
`(kind, name)` inside each class block. Use it instead of the runner's
positional `matching_lines`, which reads as "structurally broken" (14/2936)
even when every `<type>` attribute and every `<extendsClass>` already match.
"""

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import as_model
import xml_model

RUFFLE = os.path.expanduser("~/CC/ruffle")


def fixture_classes(test_as):
    src = open(test_as, encoding="utf-8").read()
    m = re.search(r"CLASSES:Array\s*=\s*\[(.*?)\]", src, re.S)
    return [x.strip().strip('"') for x in m.group(1).split(",")]


def main_actual(ours, expected):
    act = xml_model.parse_expected(ours)
    exp = xml_model.parse_expected(expected)
    bad = 0
    for nm in sorted(exp):
        e, a = exp[nm], act.get(nm, "ABSENT")
        if e is None and a is None:
            continue
        if a == "ABSENT":
            print("%-28s CLASS ABSENT from ours" % nm)
            bad += 1
            continue
        if e is None:
            print("%-28s ours describes it, Flash says not accessible" % nm)
            bad += 1
            continue
        if a is None:
            print("%-28s ours says not accessible, Flash describes it" % nm)
            bad += 1
            continue
        for side in ("type", "factory"):
            want = set(_norm(x) for x in e[side])
            have = set(_norm(x) for x in a[side])
            for x in sorted(want - have):
                print("%-28s %-7s MISSING %s" % (nm, side, _fmt(x)))
                bad += 1
            for x in sorted(have - want):
                print("%-28s %-7s EXTRA   %s" % (nm, side, _fmt(x)))
                bad += 1
    print("TOTAL element diffs: %d" % bad)
    return 1 if bad else 0


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--actual":
        return main_actual(sys.argv[2], sys.argv[3])
    suite = sys.argv[1] if len(sys.argv) > 1 else \
        "ruffle-tests/tests/swfs/avm2/all_classes/display"
    pkg = sys.argv[2] if len(sys.argv) > 2 else "flash.display"
    classes = as_model.load_globals(
        os.path.join(RUFFLE, "core/src/avm2/globals"))
    res = xml_model.Resolver(classes)
    names = fixture_classes(os.path.join(
        RUFFLE, "tests/tests/swfs/avm2/all_classes",
        os.path.basename(suite.rstrip("/")), "Test.as"))

    total_bad = 0
    for ver_dir in sorted(os.listdir(suite)):
        if not ver_dir.startswith("swf"):
            continue
        ver = int(ver_dir[3:])
        exp = xml_model.parse_expected(os.path.join(suite, ver_dir,
                                                    "output.txt"))
        bad = 0
        for nm in names:
            k = classes.get("%s::%s" % (pkg, nm))
            want_present = (k is not None and k.min_swf != as_model.HIDE
                            and (k.min_swf == 0 or ver >= k.min_swf))
            got = exp.get(nm, "MISSING")
            if got == "MISSING":
                print("[%s] %s: absent from expected file entirely" %
                      (ver_dir, nm))
                bad += 1
                continue
            if got is None:                       # "not accessible"
                if want_present:
                    print("[%s] %s: model says visible, Flash says not "
                          "accessible (class api=%s)" % (ver_dir, nm,
                                                         k.min_swf))
                    bad += 1
                continue
            if not want_present:
                print("[%s] %s: model hides it (api=%s) but Flash describes it"
                      % (ver_dir, nm, None if k is None else k.min_swf))
                bad += 1
                continue
            model = xml_model.describe(res, k, ver)
            for side in ("type", "factory"):
                want = sorted(_norm(e) for e in model[side])
                have = sorted(_norm(e) for e in got[side])
                if want != have:
                    for line in _diff(nm, ver_dir, side, have, want):
                        print(line)
                        bad += 1
        print("== %s: %d element mismatches" % (ver_dir, bad))
        total_bad += bad
    print("TOTAL mismatches: %d" % total_bad)
    return 1 if total_bad else 0


def _norm(e):
    # normalizeXML() sorts children lexically, so <parameter index="10"/>
    # prints before index="2"; compare parameter sets order-independently.
    tag, attrs, params = e
    return (tag, tuple(attrs), tuple(sorted(params)))


def _diff(nm, ver_dir, side, have, want):
    hs, ws = set(have), set(want)
    for e in sorted(ws - hs):
        yield "[%s] %s/%s MODEL-ONLY  %s" % (ver_dir, nm, side, _fmt(e))
    for e in sorted(hs - ws):
        yield "[%s] %s/%s FLASH-ONLY  %s" % (ver_dir, nm, side, _fmt(e))


def _fmt(e):
    tag, attrs, params = e
    s = "<%s%s>" % (tag, "".join(' %s="%s"' % a for a in attrs))
    if params:
        s += " " + " ".join(params)
    return s


if __name__ == "__main__":
    sys.exit(main())
