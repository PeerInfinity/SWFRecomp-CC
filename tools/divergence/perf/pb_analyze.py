#!/usr/bin/env python3
# analyze.py - playability stats over the per-round JSONs.
# Objective is 30 fps = 33 ms/frame, so the headline metric is the SHARE of
# gameplay frames over 33 ms, not the mean.
import json, glob, os, sys
D = "/mnt/c/playwright/pb_2026-07-20"
TITLES = ["seedling","rwk","rwp","rwf","rwic"]

def stats(v):
    if not v: return None
    b=sorted(v); n=len(b)
    return {"n":n, "mean":sum(b)/n, "p50":b[n//2], "p95":b[min(n-1,int(n*0.95))],
            "max":b[-1], "over33":100.0*sum(1 for x in v if x>33.0)/n,
            "stalls":sum(1 for x in v if x>250.0)}

def cut_transition(v):
    """Safety net: if the window still straddles the menu->level transition,
    drop everything up to and including it. The transition is a >200 ms
    level-generation stall followed by a step change in frame cost; we only cut
    when both hold, so an ordinary in-game GC spike is never mistaken for it.
    RWIC and RWF stage through TWO cheap intermediate states before the level is
    live, so we take the LAST qualifying transition, not the first."""
    best=None
    for i,x in enumerate(v):
        if x <= 200.0: continue
        before, after = v[:i], v[i+1:]
        if len(before) < 30 or len(after) < 60: continue
        pb=sorted(before)[len(before)//2]; pa=sorted(after)[len(after)//2]
        if pa > pb*2.0:
            best={"cut_at":i, "p50_before":pb, "p50_after":pa, "stall":x}
    return (v[best["cut_at"]+1:] if best else v), best

def frames_of(path):
    d=json.load(open(path)); g=d.get("gameplay")
    if not g: return None,d
    if d["engine"]=="ours":
        cpu,bad=g["cpu"],g.get("bad") or []
        # ORDER MATTERS. __swfPerf marks the level-generation stall frames "bad"
        # (they are throttled), so filtering bad first deletes the very marker
        # the transition cut looks for and leaves the menu frames in the window.
        # Cut on the raw series, then drop bad frames from what survives.
        if not (bad and len(bad)==len(cpu)): bad=[0]*len(cpu)
        idx = list(range(len(cpu)))
        cut_v, cut = cut_transition(cpu)
        if cut:
            keep = idx[cut["cut_at"]+1:]
        else:
            keep = idx
        pairs=[(cpu[i],bad[i]) for i in keep]
        if not all(b for _,b in pairs):
            pairs=[(c,b) for c,b in pairs if not b]
        d["_cut"]=cut
        return [c for c,_ in pairs],d
    n=min(len(g["tick"]),len(g["render"])) if g["render"] else len(g["tick"])
    return [g["tick"][i]+(g["render"][i] if g["render"] else 0) for i in range(n)],d

out={}
for t in TITLES:
    for eng in ["ours","ruffle"]:
        rounds=[]; allf=[]; proven=[]
        for p in sorted(glob.glob(os.path.join(D,"%s_%s_r*.json"%(eng,t)))):
            f,d=frames_of(p)
            if not f: continue
            rounds.append(stats(f)); allf+=f
            proven.append(d.get("state_proven"))
        if allf:
            s=stats(allf); s["rounds"]=len(rounds)
            s["mean_spread"]=(min(r["mean"] for r in rounds),max(r["mean"] for r in rounds))
            s["p50_spread"] =(min(r["p50"]  for r in rounds),max(r["p50"]  for r in rounds))
            s["over33_spread"]=(min(r["over33"] for r in rounds),max(r["over33"] for r in rounds))
            s["proven"]=proven
            out["%s_%s"%(eng,t)]=s

for t in TITLES:
    print("\n=== %s ===" % t.upper())
    for eng in ["ours","ruffle"]:
        s=out.get("%s_%s"%(eng,t))
        if not s: print("  %-6s NO DATA" % eng); continue
        print("  %-6s n=%-5d rounds=%d  mean %6.1f  p50 %6.1f  p95 %6.1f  max %7.1f  >33ms %5.1f%%  stalls %d"
              % (eng,s["n"],s["rounds"],s["mean"],s["p50"],s["p95"],s["max"],s["over33"],s["stalls"]))
        print("         spread: mean %.1f-%.1f  p50 %.1f-%.1f  >33%% %.1f-%.1f"
              % (s["mean_spread"]+s["p50_spread"]+s["over33_spread"]))

print("\n\n| title | ours mean | ours p50 | ours %>33ms | ours stalls | Ruffle mean | Ruffle p50 | Ruffle %>33ms | playable at 30fps? |")
print("|---|---|---|---|---|---|---|---|---|")
for t in TITLES:
    o=out.get("ours_%s"%t); r=out.get("ruffle_%s"%t)
    def c(s,k,f="%.1f"): return (f % s[k]) if s else "—"
    verdict = "—"
    if o:
        verdict = "**YES**" if o["over33"]<10 else ("marginal" if o["over33"]<50 else "**NO**")
    print("| %s | %s | %s | %s%% | %s | %s | %s | %s |  %s |" % (
        t, c(o,"mean"), c(o,"p50"), c(o,"over33"), (str(o["stalls"]) if o else "—"),
        c(r,"mean"), c(r,"p50"), (c(r,"over33")+"%") if r else "—", verdict))
