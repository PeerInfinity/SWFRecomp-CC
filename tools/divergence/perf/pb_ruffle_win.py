#!/usr/bin/env python3
# pb_ruffle.py - playability scoreboard driver, RUFFLE side.
# Derived from ti_rwk_ruffle.py (the corrected driver that found the title
# inversion), with one structural fix:
#   __rufflePerfTick/Render/Draws are ~600-entry arrays. A 30 s gameplay window
#   is SHORTER than that, so a single end-of-window read silently mixes in menu
#   frames (this is what made the smoke run's gameplay p50 read 5.3 ms).
#   We DRAIN-POLL instead: every POLL_S, read all three arrays atomically in one
#   evaluate() and truncate them to length 0. Complete coverage, no mixing.
#
# Usage: pb_ruffle.py <name> <out.json> <menu_s> <play_s> <spots>
import sys, time, json, os
from playwright.sync_api import sync_playwright

NAME   = sys.argv[1]
OUT    = sys.argv[2]
MENU_S = float(sys.argv[3])
PLAY_S = float(sys.argv[4])
SPOTS  = [tuple(float(v) for v in s.split(",")) for s in sys.argv[5].split(";") if s.strip()]
POLL_S = 2.0

URL   = "http://localhost:8010/examples/avm2/%s/" % NAME
FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
SHOT  = os.path.dirname(OUT)
os.makedirs(SHOT, exist_ok=True)
STEM = os.path.splitext(os.path.basename(OUT))[0]

# One task = atomic across the three arrays, so indices stay paired.
DRAIN_JS = r"""
() => { var t=window.__rufflePerfTick, r=window.__rufflePerfRender, d=window.__rufflePerfDraws;
  if(!t) return null;
  var out={tick:t.slice(), render:(r?r.slice():[]), draws:(d?d.slice():[])};
  t.length=0; if(r) r.length=0; if(d) d.length=0;
  return out; }
"""
# Non-destructive peek used for the click gate.
DRAWS_NOW = "()=>{var d=window.__rufflePerfDraws; if(!d||!d.length) return null;" \
            "var s=d.slice(-30),m=0; for(var i=0;i<s.length;i++) m+=s[i]; return m/s.length;}"

console_lines=[]; errors=[]

def drain(pg, bucket):
    d = pg.evaluate(DRAIN_JS)
    if not d: return
    bucket["tick"]   += d["tick"]
    bucket["render"] += d["render"]
    bucket["draws"]  += d["draws"]

with sync_playwright() as p:
    b  = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width":720,"height":760})
    pg.on("console", lambda m: console_lines.append(m.text[:200]) if len(console_lines)<400 else None)
    pg.on("pageerror", lambda e: errors.append(str(e)[:200]))
    result={"name":NAME,"engine":"ruffle","url":URL,"adapter":None,
            "menu":None,"gameplay":None,"draws_menu":None,"draws_after_click":None,
            "state_proven":False,"click":None,"spots":SPOTS,"errors":[],"notes":[]}
    try:
        pg.goto(URL, wait_until="load", timeout=45000)
    except Exception as e:
        result["errors"].append("goto:"+str(e)[:120])
        open(OUT,"w").write(json.dumps(result)); b.close(); sys.exit(2)
    try:
        result["adapter"]=pg.evaluate("""async()=>{ if(!navigator.gpu) return 'no-webgpu';
            const a=await navigator.gpu.requestAdapter(); if(!a) return 'no-adapter';
            const i=a.info||(a.requestAdapterInfo?await a.requestAdapterInfo():{});
            return (i.vendor||'?')+' / '+(i.architecture||i.description||i.device||'?'); }""")
    except Exception as e:
        result["adapter"]="err:"+str(e)[:80]
    print("ADAPTER:", result["adapter"], flush=True)
    pg.bring_to_front()

    t0=time.time(); loaded=False
    while time.time()-t0 < 20:
        pg.wait_for_timeout(500)
        loaded=pg.evaluate("()=>!!window.__ruffleLoaded")
        if loaded: break
    print("ruffle loaded=%s" % loaded, flush=True)
    pg.wait_for_timeout(6000)   # LogoState -> TitleState fade
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, STEM+"_menu.png"))
    except Exception as e: print("shot menu fail", e, flush=True)

    # ---- menu phase
    drain(pg, {"tick":[],"render":[],"draws":[]})
    menu={"tick":[],"render":[],"draws":[]}
    t0=time.time()
    while time.time()-t0 < MENU_S:
        pg.wait_for_timeout(int(POLL_S*1000)); drain(pg, menu)
    result["menu"]=menu
    result["draws_menu"]=pg.evaluate(DRAWS_NOW)
    print("MENU frames:", len(menu["tick"]), "draws:", result["draws_menu"], flush=True)

    # ---- click "Play Game": press and release on separate ticks (FlxButton)
    box=pg.locator("#c").bounding_box()
    print("canvas box:", box, flush=True)
    base = (sum(menu["draws"][-30:])/len(menu["draws"][-30:])) if menu["draws"] else 0
    print("draws baseline (menu):", base, flush=True)
    for (fx,fy) in SPOTS:
        px=box["x"]+box["width"]*fx; py=box["y"]+box["height"]*fy
        pg.mouse.move(px,py); time.sleep(0.15)
        pg.mouse.down(); time.sleep(0.15); pg.mouse.up(); time.sleep(1.6)
        now=pg.evaluate(DRAWS_NOW) or 0
        print("  click frac(%.3f,%.3f) css(%.0f,%.0f) draws %.1f -> %.1f"%(fx,fy,px,py,base,now), flush=True)
        if base and now > base*1.5:
            result["click"]={"frac":[fx,fy],"css":[px,py],"draws_before":base,"draws_after":now}
            result["state_proven"]=True
            break
    result["draws_after_click"]=pg.evaluate(DRAWS_NOW)
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, STEM+"_postclick.png"))
    except Exception: pass
    pg.wait_for_timeout(3000)   # state-switch fade

    # ---- gameplay phase
    drain(pg, {"tick":[],"render":[],"draws":[]})
    play={"tick":[],"render":[],"draws":[]}
    t0=time.time(); seq=["ArrowRight","x","ArrowLeft","ArrowUp","ArrowRight","x"]; i=0
    last=time.time()
    while time.time()-t0 < PLAY_S:
        k=seq[i%len(seq)]; i+=1
        pg.keyboard.down(k); time.sleep(0.35); pg.keyboard.up(k); time.sleep(0.25)
        if time.time()-last >= POLL_S:
            drain(pg, play); last=time.time()
    drain(pg, play)
    result["gameplay"]=play
    print("GAMEPLAY frames:", len(play["tick"]),
          "draws mean:", (sum(play["draws"])/len(play["draws"]) if play["draws"] else None), flush=True)
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, STEM+"_final.png"))
    except Exception: pass
    result["errors"]+=errors[:8]; result["console_tail"]=console_lines[-25:]
    open(OUT,"w").write(json.dumps(result)); print("WROTE", OUT, flush=True)
    b.close()
