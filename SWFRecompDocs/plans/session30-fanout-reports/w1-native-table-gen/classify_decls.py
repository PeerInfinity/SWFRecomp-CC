#!/usr/bin/env python3
"""Classify differences between two decls-dump outputs (global_proto_decls format).

Sections start with 'Testing NAME'; members are '  key, own, DONT_ENUM, READ_ONLY, type=[t]'.
Usage: classify.py expected actual [--detail N]
"""
import sys, re, collections, difflib

def parse(path):
    secs = collections.OrderedDict()
    other = []
    cur = None
    order = []
    for line in open(path, encoding='utf-8', errors='replace').read().split('\n'):
        if line.startswith('Testing '):
            name = line[8:]
            # sections can repeat (recursion visits same name twice?) -> suffix
            k = name; i = 2
            while k in secs:
                k = f"{name}#{i}"; i += 1
            cur = k; secs[cur] = []; order.append(cur)
        elif line.startswith('  ') and cur is not None:
            m = re.match(r'  (.*?)((?:, own)?(?:, DONT_ENUM)?(?:, READ_ONLY)?), type=\[(.*)\]$', line)
            if m:
                key = m.group(1); fl = m.group(2); t = m.group(3)
                secs[cur].append((key, fl, t))
            else:
                other.append(line)
        else:
            if line.strip():
                other.append(line)
            cur = cur if line.strip() == '' else None
    return secs, other

def main():
    exp, oth_e = parse(sys.argv[1])
    act, oth_a = parse(sys.argv[2])
    detail = int(sys.argv[sys.argv.index('--detail') + 1]) if '--detail' in sys.argv else 0
    H = collections.Counter()
    ex = collections.defaultdict(list)
    def note(cat, s):
        H[cat] += 1
        if len(ex[cat]) < 2000: ex[cat].append(s)
    for name in exp:
        if name not in act:
            note('section_missing', name)
            H['lines:section_missing'] += 1 + len(exp[name])
            continue
        e = exp[name]; a = act[name]
        ed = {k: (f, t) for k, f, t in e}; ad = {k: (f, t) for k, f, t in a}
        for k, f, t in e:
            if k not in ad:
                note('member_missing', f"{name}.{k} [{t}]")
            else:
                af, at = ad[k]
                if af != f:
                    for flag in ('own', 'DONT_ENUM', 'READ_ONLY'):
                        ein = (', ' + flag) in f; ain = (', ' + flag) in af
                        if ein != ain:
                            note(f"flag_{flag}_{'missing' if ein else 'extra'}", f"{name}.{k}")
                if at != t:
                    note(f"type:{t}<-{at}", f"{name}.{k}")
        for k, f, t in a:
            if k not in ed:
                note('member_extra', f"{name}.{k} [{t}]")
        # order among common keys
        ek = [k for k, _, _ in e if k in ad]
        ak = [k for k, _, _ in a if k in ed]
        if ek != ak:
            sm = difflib.SequenceMatcher(None, ek, ak, autojunk=False)
            lcs = sum(b.size for b in sm.get_matching_blocks())
            moved = len(ek) - lcs
            H['order_moved_members'] += moved
            note('order_section', f"{name} ({moved} moved of {len(ek)})")
    for name in act:
        if name not in exp:
            note('section_extra', name)
            H['lines:section_extra'] += 1 + len(act[name])
    if oth_e != oth_a:
        note('other_lines_differ', f"exp {oth_e[:3]} act {oth_a[:3]}")
    for k, v in sorted(H.items(), key=lambda x: -x[1]):
        print(f"{v:6d}  {k}")
    if detail:
        for k in ex:
            print(f"--- {k}")
            for s in ex[k][:detail]:
                print("   ", s)

if __name__ == '__main__':
    main()
