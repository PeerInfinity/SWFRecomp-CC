#!/usr/bin/env python3
"""qtbucket.py — attribute a CDP .cpuprofile to the Flixel quadtree subsystem.

Buckets every sample by call-tree ANCESTRY (not function-name guessing):

  build     tree construction — FlxQuadTree ctor/add/addObject/addToList and
            FlxList ctor. This is what pooling could attack (alloc + ctor),
            though NOT the list-copy loop inside the ctor.
  traverse  FlxQuadTree.overlap / overlapNode own logic. Pooling does NOT
            remove any of this.
  callback  the game's own collision response, reached via overlapNode's _oc
            callback (FlxU.solveXCollision / FlxTilemap.preCollide / ...).
            Real game work; it exists regardless of how the tree is built.
  outside   everything else in the frame.

Usage: qtbucket.py <profile.json> <abcmap.tsv>
"""
import json, sys, collections

prof_path, map_path = sys.argv[1], sys.argv[2]
NAME = dict(L.rstrip("\n").split("\t") for L in open(map_path))

# ABC method indices resolved by abcmap.py against the RWK SWF's own ABC, so
# they are stable across our rebuilds (they index the SWF, not our output).
QT_BUILD = {"abc0_m482", "abc0_m483", "abc0_m484", "abc0_m485", "abc0_m593"}
QT_TRAV = {"abc0_m486", "abc0_m487"}

p = json.load(open(prof_path))
p = p.get("profile", p)
byid = {n["id"]: n for n in p["nodes"]}
parent = {}
for n in p["nodes"]:
    for c in n.get("children", []):
        parent[c] = n["id"]

self = collections.Counter()
for s, dt in zip(p["samples"], p["timeDeltas"]):
    self[s] += max(dt, 0)
total = sum(self.values())
fn = lambda i: byid[i]["callFrame"]["functionName"] or "(anon)"


def chain(nid):
    out, cur, seen = [], nid, set()
    while cur in byid and cur not in seen:
        seen.add(cur)
        out.append(fn(cur))
        cur = parent.get(cur)
    return out


buckets = collections.Counter()
inner = collections.defaultdict(collections.Counter)
for nid, t in self.items():
    ch = chain(nid)  # leaf -> root
    hasB = any(f in QT_BUILD for f in ch)
    hasT = any(f in QT_TRAV for f in ch)
    # Inside the collision callback iff a NON-quadtree game method sits between
    # the leaf and the nearest enclosing quadtree frame.
    cb = False
    if hasT:
        for f in ch:
            if f in QT_TRAV or f in QT_BUILD:
                break
            if f.startswith("abc0_m"):
                cb = True
                break
    if hasB and not hasT:
        k = "build"
    elif hasT and cb:
        k = "callback"
    elif hasT:
        k = "traverse"
    elif hasB:
        k = "build-under-traverse"
    else:
        k = "outside"
    buckets[k] += t
    inner[k][ch[0]] += t

print("samples total: %.1f ms   (%s)" % (total / 1000.0, prof_path))
qt = sum(v for k, v in buckets.items() if k != "outside" and k != "callback")
print("QUADTREE SUBSYSTEM (build+traverse, callback excluded): %.2f%%" % (100.0 * qt / total))
for k, t in buckets.most_common():
    print("\n=== %-24s %6.2f%%" % (k, 100.0 * t / total))
    for f, v in inner[k].most_common(12):
        print("     %6.2f%%  %s" % (100.0 * v / total, NAME.get(f, f)))
