#!/usr/bin/env python3
# pb_ours.py - playability scoreboard driver, OURS side (docs2 demo.html + __swfPerf).
# Built on rw_ab.py's proven boot sequence (goto -> poll Module.calledRun -> runSwf()).
#
# Differences vs rw_ab.py, all aimed at the "prove the state" rule:
#   1. __swfPerf.cpu is a 120-slot CIRCULAR buffer (cap:120). A 30s window holds
#      more than 120 frames, so a single read at the end samples only the tail.
#      We instead DRAIN-POLL: every POLL_S we read {frames, i, cpu, bad} and
#      reconstruct chronologically, taking only the (frames - prev_frames) new
#      entries. Full gameplay coverage, zero menu contamination.
#   2. Per-title click spots (argv), menu screenshot + final screenshot, and a
#      menu-phase cpu sample so menu-vs-gameplay can be compared numerically.
#
# Usage: pb_ours.py <name> <out.json> <boot_s> <menu_s> <play_s> <spots>
#   spots = "0.25,0.631;0.5,0.5;..."   (fractions of the canvas bounding box)
import sys, time, json, os
from playwright.sync_api import sync_playwright

NAME   = sys.argv[1]
OUT    = sys.argv[2]
BOOT_S = float(sys.argv[3])
MENU_S = float(sys.argv[4])
PLAY_S = float(sys.argv[5])
SPOTS  = [tuple(float(v) for v in s.split(",")) for s in sys.argv[6].split(";") if s.strip()]
# Seedling boots straight into the overworld: there is no menu->play cost step
# to wait for, so waiting would just burn 30 s. Every other title has one.
WAIT_RISE = (len(sys.argv) < 8) or (sys.argv[7] != "0")
POLL_S = 1.0   # ring cap is 120; menu runs at 60 fps, so 2.0 s wrapped it

URL   = "http://localhost:8010/demo.html?test=avm2/%s&perfhud=1&perfbench=1" % NAME
FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
SHOT  = os.path.dirname(OUT)
os.makedirs(SHOT, exist_ok=True)
STEM = os.path.splitext(os.path.basename(OUT))[0]

# Return the ring in CHRONOLOGICAL order + the total frame counter, so the
# caller can slice exactly the frames that are new since the previous poll.
DRAIN_JS = r"""
() => { var S=window.__swfPerf; if(!S) return null;
  var n=S.cpu.length, full=(n>=S.cap);
  function chron(a){ if(!a||!a.length) return [];
    return full ? a.slice(S.i).concat(a.slice(0,S.i)) : a.slice(0,S.i); }
  return { frames:S.frames, cap:S.cap, i:S.i,
           cpu:chron(S.cpu), iv:chron(S.iv), bad:chron(S.bad) }; }
"""

console_lines=[]; errors=[]; wasm_info={}

def drain(pg, state, bucket):
    """Poll the ring; append only frames not seen before."""
    d = pg.evaluate(DRAIN_JS)
    if not d: return
    new = d["frames"] - state["frames"]
    if new <= 0:
        state["frames"] = d["frames"]; return
    take = min(new, len(d["cpu"]))
    if new > len(d["cpu"]):
        state["dropped"] += new - len(d["cpu"])   # poll too slow, ring wrapped
    if take:
        bucket["cpu"] += d["cpu"][-take:]
        bucket["iv"]  += d["iv"][-take:]
        bucket["bad"] += d["bad"][-take:]
    state["frames"] = d["frames"]

with sync_playwright() as p:
    b  = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width":720,"height":760})
    pg.on("console", lambda m: console_lines.append(m.text[:200]) if len(console_lines)<400 else None)
    pg.on("pageerror", lambda e: errors.append(str(e)[:200]))
    def on_resp(r):
        try:
            if r.url.endswith(".wasm"):
                wasm_info["url"]=r.url.split("/")[-1]; wasm_info["status"]=r.status
                wasm_info["bytes"]=r.headers.get("content-length") or "?"
        except Exception: pass
    pg.on("response", on_resp)

    result={"name":NAME,"engine":"ours","url":URL,"adapter":None,
            "menu":None,"gameplay":None,"clicks":[],"spots":SPOTS,
            "click":None,"state_proven":False,"menu_p50":None,
            "frames_menu":0,"frames_gameplay":0,"errors":[],"notes":[],"wasm":wasm_info}

    pg.goto(URL, wait_until="load", timeout=45000)
    try:
        result["adapter"]=pg.evaluate("""async()=>{ if(!navigator.gpu) return 'no-webgpu';
            const a=await navigator.gpu.requestAdapter(); if(!a) return 'no-adapter';
            const i=a.info||(a.requestAdapterInfo?await a.requestAdapterInfo():{});
            return (i.vendor||'?')+' / '+(i.architecture||i.description||i.device||'?'); }""")
    except Exception as e:
        result["adapter"]="err:"+str(e)[:80]
    print("ADAPTER:", result["adapter"], flush=True)

    ready=False
    for i in range(240):
        try:
            if pg.evaluate("() => !!(window.Module && window.Module.calledRun)"):
                ready=True; print("runtime ready at %.1fs"%(i*0.25), flush=True); break
        except Exception: pass
        time.sleep(0.25)
    if not ready:
        print("RUNTIME NEVER READY", flush=True); result["errors"].append("runtime-not-ready")
    pg.evaluate("() => { if (window.runSwf) window.runSwf(); }")
    print("runSwf() invoked", flush=True)

    t0=time.time()
    while time.time()-t0 < BOOT_S: time.sleep(0.5)
    try: fr=pg.evaluate("() => (window.__swfPerf ? window.__swfPerf.frames : 0)")
    except Exception: fr=0
    print("booted; frames=%s" % fr, flush=True)
    try: pg.locator("#canvas").screenshot(path=os.path.join(SHOT, STEM+"_menu.png"))
    except Exception as e: print("shot menu fail", e, flush=True)

    # ---- menu phase (drained, so it is a clean menu-only population)
    st={"frames":fr,"dropped":0}; menu={"cpu":[],"iv":[],"bad":[]}
    t0=time.time()
    while time.time()-t0 < MENU_S:
        time.sleep(POLL_S); drain(pg, st, menu)
    result["menu"]=menu; result["frames_menu"]=len(menu["cpu"])
    print("MENU frames:", len(menu["cpu"]), flush=True)

    # ---- click to gameplay: press and release on SEPARATE ticks (FlxButton)
    # Ours has no draw counter, so the in-frame state attestation is the
    # frame-cost step: these menus idle at ~2-3 ms, every PlayState here is far
    # heavier. Measuring that step right after the click does NOT work - RWIC and
    # RWF spend seconds generating the level, so an early probe still sees menu
    # frames. So: click every spot, then WAIT for the cost to rise, and only then
    # open the measurement window. Without this the window's left tail is menu
    # frames (the tell in round 1 was mean 11.4 < p50 14.4 on rwic).
    mb = sorted(menu["cpu"]); menu_p50 = mb[len(mb)//2] if mb else 0
    result["menu_p50"]=menu_p50
    print("menu cpu p50: %.1f" % menu_p50, flush=True)
    box=pg.locator("#canvas").bounding_box()
    print("canvas box:", box, flush=True)
    for (fx,fy) in SPOTS:
        px=box["x"]+box["width"]*fx; py=box["y"]+box["height"]*fy
        pg.mouse.move(px,py); time.sleep(0.15)
        pg.mouse.down(); time.sleep(0.15); pg.mouse.up(); time.sleep(1.2)
        result["clicks"].append({"frac":[fx,fy],"css":[px,py]})
        print("  click frac(%.3f,%.3f)"%(fx,fy), flush=True)

    if WAIT_RISE:
        # RWIC/RWF take ~45 s to leave the menu and they announce it with a
        # 1.5-1.8 s level-generation stall. So watch for EITHER marker, for up to
        # 90 s: a single >200 ms frame (the generation hitch) or a sustained 3x
        # cost rise. 30 s was too short and silently left the menu in the window.
        t0=time.time()
        while time.time()-t0 < 90:
            probe={"cpu":[],"iv":[],"bad":[]}
            drain(pg, st, probe); time.sleep(1.0); drain(pg, st, probe)
            if not probe["cpu"]: continue
            pb=sorted(probe["cpu"]); now=pb[len(pb)//2]
            stall=max(probe["cpu"])
            if stall > 200.0:
                result["state_proven"]=True
                result["click"]={"marker":"transition-stall","stall_ms":stall,
                                 "rise_after_s":round(time.time()-t0,1)}
                print("  STATE CHANGED: %.0f ms transition stall after %.1fs"
                      % (stall, time.time()-t0), flush=True)
                time.sleep(2.0)   # let the new state settle past the hitch
                break
            if menu_p50 and now > menu_p50*3.0:
                result["state_proven"]=True
                result["click"]={"marker":"cost-rise","p50_before":menu_p50,
                                 "p50_after":now,"rise_after_s":round(time.time()-t0,1)}
                print("  STATE CHANGED: p50 %.1f -> %.1f after %.1fs"
                      % (menu_p50, now, time.time()-t0), flush=True)
                break
        if not result["state_proven"]:
            print("  WARNING: no state change in 90s", flush=True)
            result["notes"].append("no-state-change")
    else:
        result["notes"].append("no-transition-expected (boots straight to gameplay)")
    time.sleep(2.0)
    try: pg.locator("#canvas").screenshot(path=os.path.join(SHOT, STEM+"_postclick.png"))
    except Exception: pass

    # ---- gameplay phase
    drain(pg, st, {"cpu":[],"iv":[],"bad":[]})   # discard click-transition frames
    st["dropped"]=0                               # count drops for gameplay only
    play={"cpu":[],"iv":[],"bad":[]}
    t0=time.time(); seq=["ArrowRight","x","ArrowLeft","ArrowUp","z","ArrowRight"]; i=0
    while time.time()-t0 < PLAY_S:
        k=seq[i%len(seq)]; i+=1
        # drain every iteration (~0.65 s): at 60 fps that is ~39 frames, well
        # under the 120-slot ring, so no gameplay frame is ever lost to a wrap.
        pg.keyboard.down(k); time.sleep(0.35); drain(pg, st, play)
        pg.keyboard.up(k);   time.sleep(0.3);  drain(pg, st, play)
    result["gameplay"]=play; result["frames_gameplay"]=len(play["cpu"])
    result["dropped"]=st["dropped"]
    print("GAMEPLAY frames:", len(play["cpu"]), "dropped:", st["dropped"], flush=True)

    try: pg.locator("#canvas").screenshot(path=os.path.join(SHOT, STEM+"_final.png"))
    except Exception: pass
    result["errors"]+=errors[:8]; result["console_tail"]=console_lines[-25:]
    result["wasm"]=wasm_info
    open(OUT,"w").write(json.dumps(result))
    print("WROTE", OUT, flush=True)
    b.close()
