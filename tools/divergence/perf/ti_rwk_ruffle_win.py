#!/usr/bin/env python3
# ti_rwk_ruffle.py - CORRECTED Ruffle RWK driver (title-inversion diagnosis, 2026-07-20).
#
# Fixes vs rw_perf_ruffle.py, which produced the invalid 6.4 ms "gameplay" anchor:
#   1. It only centre-clicked (320,240) for focus - dead space. RWK's "Play Game"
#      button is at ~(160,303) in the 640x480 stage (Ruffle page pins CSS 1:1).
#   2. It used a single-turn mouse.click(); Flixel's FlxButton needs press and
#      release on separate ticks -> real down / hold / up.
#   3. Screenshots went to a hard-coded dir; now they sit next to OUT.
#   4. It never checked that the state changed. Now we gate on __rufflePerfDraws
#      (per-frame shape draw count) rising well above the title baseline, and
#      record it per phase as the in-frame quantity that attests the scene.
#
# Usage: ti_rwk_ruffle.py <name> <out.json> <menu_s> <play_s>
import sys, time, json, os
from playwright.sync_api import sync_playwright

NAME   = sys.argv[1] if len(sys.argv) > 1 else "rwk_ac_after_ruffle"
OUT    = sys.argv[2] if len(sys.argv) > 2 else r"C:\playwright\ti_2026-07-20\rwk_ruffle.json"
MENU_S = float(sys.argv[3]) if len(sys.argv) > 3 else 25.0
PLAY_S = float(sys.argv[4]) if len(sys.argv) > 4 else 30.0

URL   = "http://localhost:8010/examples/avm2/%s/" % NAME
FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
SHOT  = os.path.dirname(OUT)
os.makedirs(SHOT, exist_ok=True)

COLLECT_JS = r"""
() => { window.__raf={t:[],d:[]}; window.__rafLast=performance.now(); window.__rafOn=true;
  function loop(now){ if(!window.__rafOn) return; var d=now-window.__rafLast; window.__rafLast=now;
    if(window.__raf.d.length<500000){ window.__raf.d.push(+d.toFixed(2)); window.__raf.t.push(+now.toFixed(1)); }
    requestAnimationFrame(loop); }
  requestAnimationFrame(loop);
  window.__rafReset=function(){ window.__raf={t:[],d:[]}; window.__rafLast=performance.now(); }; }
"""
# Adds draws[] - the state attestation the old driver lacked.
RUFFLE_JS = r"""
() => { var t=window.__rufflePerfTick, r=window.__rufflePerfRender, dr=window.__rufflePerfDraws;
  if(!t||!t.length) return null;
  function stat(a){ var b=a.slice().sort(function(x,y){return x-y;}); var n=b.length,s=0;
    for(var i=0;i<n;i++) s+=b[i]; return {n:n,mean:n?s/n:0,p50:n?b[Math.floor(n*0.5)]:0,
      p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0,max:n?b[n-1]:0}; }
  var n=Math.min(t.length,(r&&r.length)||t.length);
  var tot=[]; for(var i=0;i<n;i++) tot.push(t[i]+((r&&r[i])||0));
  var out={frames:n, total:stat(tot), tick:stat(t.slice(0,n)), render:stat((r||[]).slice(0,n))};
  if(dr&&dr.length) out.draws=stat(dr.slice(-n));
  // raw rings so the phase window can be sliced offline: the ring holds 600
  // samples, which spans MORE than a short phase and silently mixes in menu
  // frames (this is what made the smoke run's gameplay p50 read 5.3 ms).
  out.tick_raw=t.slice(-600); out.render_raw=(r||[]).slice(-600);
  if(dr&&dr.length) out.draws_raw=dr.slice(-600);
  return out; }
"""
DRAWS_NOW = "()=>{var d=window.__rufflePerfDraws; if(!d||!d.length) return null; " \
            "var s=d.slice(-30),m=0; for(var i=0;i<s.length;i++) m+=s[i]; return m/s.length;}"

console_lines=[]; errors=[]
with sync_playwright() as p:
    b=p.chromium.launch(headless=False, args=FLAGS)
    pg=b.new_page(viewport={"width":720,"height":760})
    pg.on("console", lambda m: console_lines.append(m.text[:200]) if len(console_lines)<400 else None)
    pg.on("pageerror", lambda e: errors.append(str(e)[:200]))
    result={"name":NAME,"url":URL,"driver":"ti_rwk_ruffle.py","adapter":None,
            "menu":None,"gameplay":None,"ruffleperf_menu":None,"ruffleperf_gameplay":None,
            "draws_menu":None,"draws_after_click":None,"state_proven":False,
            "click":None,"errors":[],"notes":[]}
    try:
        pg.goto(URL, wait_until="load", timeout=45000)
    except Exception as e:
        print("GOTO_FAIL:",e,flush=True); result["errors"].append("goto:"+str(e)[:120])
        open(OUT,"w").write(json.dumps(result)); b.close(); sys.exit(2)
    try:
        adapter=pg.evaluate("""async()=>{ if(!navigator.gpu) return 'no-webgpu';
            const a=await navigator.gpu.requestAdapter(); if(!a) return 'no-adapter';
            const info=a.info||(a.requestAdapterInfo?await a.requestAdapterInfo():{});
            return (info.vendor||'?')+' / '+(info.architecture||info.description||info.device||'?'); }""")
    except Exception as e:
        adapter="err:"+str(e)[:80]
    result["adapter"]=adapter; print("ADAPTER:",adapter,flush=True)
    pg.evaluate(COLLECT_JS); pg.bring_to_front()

    t0=time.time(); loaded=False
    while time.time()-t0 < 16:
        pg.wait_for_timeout(500)
        loaded=pg.evaluate("()=>!!window.__ruffleLoaded")
        if loaded: break
    print("ruffle loaded=%s" % loaded, flush=True)
    # RWK shows LogoState then TitleState; give the fade time to settle.
    pg.wait_for_timeout(6000)
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, NAME+"_menu.png"))
    except Exception as e: print("shot menu fail",e,flush=True)

    # ---- menu phase
    pg.evaluate("()=>window.__rafReset()")
    t0=time.time()
    while time.time()-t0 < MENU_S: pg.wait_for_timeout(500)
    result["menu"]=pg.evaluate("()=>window.__raf")
    result["ruffleperf_menu"]=pg.evaluate(RUFFLE_JS)
    result["draws_menu"]=pg.evaluate(DRAWS_NOW)
    print("MENU frames:",len(result["menu"]["d"]), "draws:",result["draws_menu"],flush=True)

    # ---- click "Play Game": real press/hold/release at the button, not the centre
    box=pg.locator("#c").bounding_box()
    print("canvas box:",box,flush=True)
    # Ruffle page pins the player to 640x480 CSS -> fractions map 1:1 to stage px.
    # "Play Game" centre ~ (160,303) of 640x480 = (0.25, 0.631).
    spots=[(0.25,0.631),(0.25,0.60),(0.25,0.66),(0.20,0.631),(0.30,0.631)]
    base=result["draws_menu"] or 0
    for (fx,fy) in spots:
        px=box["x"]+box["width"]*fx; py=box["y"]+box["height"]*fy
        pg.mouse.move(px,py); time.sleep(0.15)
        pg.mouse.down(); time.sleep(0.15); pg.mouse.up(); time.sleep(1.6)
        now=pg.evaluate(DRAWS_NOW) or 0
        print("  click frac(%.3f,%.3f) css(%.0f,%.0f) draws %.1f -> %.1f" % (fx,fy,px,py,base,now),flush=True)
        if base and now > base*1.5:
            result["click"]={"frac":[fx,fy],"css":[px,py],"draws_before":base,"draws_after":now}
            result["state_proven"]=True
            break
    result["draws_after_click"]=pg.evaluate(DRAWS_NOW)
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, NAME+"_postclick.png"))
    except Exception: pass
    # let the state-switch fade finish before measuring
    pg.wait_for_timeout(3000)

    # ---- gameplay phase
    pg.evaluate("()=>window.__rafReset()")
    t0=time.time(); seq=["ArrowRight","x","ArrowLeft","ArrowUp","ArrowRight","x"]; i=0
    while time.time()-t0 < PLAY_S:
        k=seq[i%len(seq)]; i+=1
        pg.keyboard.down(k); time.sleep(0.35); pg.keyboard.up(k); time.sleep(0.25)
    result["gameplay"]=pg.evaluate("()=>window.__raf")
    result["ruffleperf_gameplay"]=pg.evaluate(RUFFLE_JS)
    print("GAMEPLAY frames:",len(result["gameplay"]["d"]),
          "draws:",result["ruffleperf_gameplay"].get("draws"),flush=True)
    try: pg.locator("#c").screenshot(path=os.path.join(SHOT, NAME+"_final.png"))
    except Exception: pass
    result["errors"]+=errors[:8]; result["console_tail"]=console_lines[-30:]
    open(OUT,"w").write(json.dumps(result)); print("WROTE",OUT,flush=True)
    b.close()
