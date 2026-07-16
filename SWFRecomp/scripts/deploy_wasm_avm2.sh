#!/bin/bash
# deploy_wasm_avm2.sh — publish the browser-WASM AVM2 Seedling demo (Stage 13b)
# to docs2/examples/avm2/<name>/ AND stage a side-by-side Ruffle profiling page
# at docs2/examples/avm2/<name>_ruffle/ so a Windows-Chrome perf A/B is two URLs.
#
# docs2/examples/ is gitignored (non-OSS) — nothing here is committed.
#
# Usage: deploy_wasm_avm2.sh [name] [recompiled_dir]
set -euo pipefail

NAME="${1:-seedling}"
RECOMP_DIR="${2:-$HOME/CC/seedling_teleport_build/recompiled}"
TELEPORT_SWF="${TELEPORT_SWF:-$HOME/CC/seedling_teleport_build/Seedling_teleport.swf}"
RUFFLE_DIST="${RUFFLE_DIST:-$HOME/CC/ruffle/web/packages/selfhosted/dist}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm_avm2/${NAME}"
DOCS2="${REPO_ROOT}/docs2"

W="$(grep -oP '#define FRAME_WIDTH\s+\K[0-9]+' "${RECOMP_DIR}/RecompiledTags/constants.h" 2>/dev/null || echo 480)"
H="$(grep -oP '#define FRAME_HEIGHT\s+\K[0-9]+' "${RECOMP_DIR}/RecompiledTags/constants.h" 2>/dev/null || echo 480)"

[ -f "${BUILD_DIR}/${NAME}.wasm" ] || { echo "ERROR: no ${NAME}.wasm — run build_wasm_avm2.sh first" >&2; exit 1; }

# ---- ours: demo.html?test=avm2/<name> ----
OUR="${DOCS2}/examples/avm2/${NAME}"
mkdir -p "${OUR}"
cp "${BUILD_DIR}/${NAME}.js" "${BUILD_DIR}/${NAME}.wasm" "${OUR}/"
[ -f "${TELEPORT_SWF}" ] && cp "${TELEPORT_SWF}" "${OUR}/test.swf"
# AVM2 ExternalInterface page shim (window.__swfBridge gate + BridgeGeneric
# host surface). demo.html HEAD-probes and injects it; games without injected
# bridge AS3 never call EI, so staging it is behavior-neutral for plain demos.
cp "${SWFRECOMP_ROOT}/wasm_wrappers/swf_bridge_avm2.js" "${OUR}/"
echo "graphics" > "${OUR}/.demo_type"
cat > "${OUR}/test_info.json" <<JSON
{
  "metadata": {
    "description": "AVM2 (AS3) Seedling — teleport build, boots straight to OverWorld1 (Stage 13a browser-WASM).",
    "swf_version": 38,
    "fully_implemented": false,
    "width": ${W},
    "height": ${H}
  },
  "opcodes": { "tested": [], "supporting": [] }
}
JSON
cat > "${OUR}/index.html" <<HTML
<!DOCTYPE html>
<html><head>
<meta http-equiv="refresh" content="0;url=../../../demo.html?test=avm2/${NAME}&perfhud=1">
<script>window.location.replace('../../../demo.html?test=avm2/${NAME}&perfhud=1');</script>
</head><body>Redirecting...</body></html>
HTML

# ---- Ruffle comparison page (local profiling bundle) ----
RUF="${DOCS2}/examples/avm2/${NAME}_ruffle"
if [ -d "${RUFFLE_DIST}" ] && [ -f "${TELEPORT_SWF}" ]; then
    mkdir -p "${RUF}"
    cp "${RUFFLE_DIST}"/*.js "${RUFFLE_DIST}"/*.wasm "${RUF}/" 2>/dev/null || true
    cp "${TELEPORT_SWF}" "${RUF}/test.swf"
    cat > "${RUF}/index.html" <<HTML
<!DOCTYPE html>
<html lang="en"><head><meta charset="UTF-8">
<title>Seedling — Ruffle (profiling build)</title>
<style>html,body{margin:0;background:#111;color:#7CFC00;font:12px monospace}
 #c{width:${W}px;height:${H}px;margin:8px auto;display:block}
 #hud{position:fixed;top:6px;left:6px;white-space:pre;background:rgba(0,0,0,.75);padding:6px 8px;border-radius:4px}</style>
</head><body>
<div id="hud">Ruffle perf HUD — loading…</div>
<div id="c"></div>
<script>
// Local profiling Ruffle bundle (CARGO_FEATURES=profiling) exposing per-frame CPU
// on window.__rufflePerfTick (AVM/sim ms) + __rufflePerfRender (cmd+GPU ms).
window.RufflePlayer = window.RufflePlayer || {};
var rs = document.createElement('script'); rs.src = 'ruffle.js';
rs.onload = function () {
  // No preferredRenderer: let Ruffle auto-pick (WebGPU first, WebGL2 fallback).
  // Forcing webgpu blank-fails where the swapchain image can't be created.
  window.RufflePlayer.config = { allowScriptAccess:true, autoplay:'on', unmuteOverlay:'hidden',
    splashScreen:false, warnOnUnsupportedContent:false, contextMenu:'off' };
  var ruffle = window.RufflePlayer.newest();
  var player = ruffle.createPlayer();
  player.style.width='${W}px'; player.style.height='${H}px';
  document.getElementById('c').appendChild(player);
  player.addEventListener('loadedmetadata', function(){ console.log('[harness] ruffle loadedmetadata'); });
  fetch('test.swf').then(r=>r.arrayBuffer()).then(function(buf){
    console.log('[harness] swf fetched ' + buf.byteLength + ' bytes; loading into Ruffle');
    player.load({data:buf, allowScriptAccess:true, autoplay:'on'})
      .then(function(){ window.__ruffleLoaded=true; console.log('[harness] ruffle load() resolved'); })
      .catch(function(e){ window.__ruffleErr=String(e); console.log('[harness] ruffle load() ERROR: ' + e); });
  }).catch(function(e){ console.log('[harness] swf fetch error: ' + e); });
};
rs.onerror = function(){ console.log('[harness] ERROR loading ruffle.js'); };
document.head.appendChild(rs);
// Steady-state HUD over the profiling globals (trimmed mean, warmup/throttle
// excluded) — mirrors our __swfPerf headline so the two are comparable.
(function(){
  var W=[]; var warm=30;
  function stat(a){ if(!a.length) return {m:0,p95:0}; var b=a.slice().sort((x,y)=>x-y);
    var s=0; for(var i=0;i<b.length;i++) s+=b[i]; return {m:s/b.length, p95:b[Math.floor(b.length*0.95)]}; }
  setInterval(function(){
    var t=window.__rufflePerfTick, r=window.__rufflePerfRender;
    var hud=document.getElementById('hud');
    if(!t||!t.length){ hud.textContent='Ruffle: waiting for frames…'; return; }
    var n=Math.min(t.length, (r&&r.length)||t.length);
    var tail=[]; for(var i=Math.max(warm,n-120);i<n;i++){ var tot=t[i]+((r&&r[i])||0);
      if(document.hidden) continue; tail.push(tot); }
    var ts=stat(t.slice(-120)), rSt=stat((r||[]).slice(-120)), all=stat(tail);
    hud.textContent='Ruffle (profiling)  '+ (${W}) +'x'+ (${H}) +'\n'
      +'frame CPU  mean '+all.m.toFixed(2)+'  p95 '+all.p95.toFixed(2)+' ms  (~'+(all.m>0?(1000/all.m).toFixed(0):'?')+' fps)\n'
      +'  tick(avm) '+ts.m.toFixed(2)+'   render '+rSt.m.toFixed(2)+' ms\n'
      +'frames '+n;
  }, 300);
})();
</script>
</body></html>
HTML
    echo "Ruffle A/B page: ${RUF}/index.html"
else
    echo "(skip Ruffle page — dist or teleport SWF missing)"
fi

echo ""
echo "✅ Deployed. Serve:  cd ${DOCS2} && python3 -m http.server 8000"
echo "   Ours   : http://localhost:8000/demo.html?test=avm2/${NAME}&perfhud=1"
echo "   Ruffle : http://localhost:8000/examples/avm2/${NAME}_ruffle/"
echo "   Wasm size: $(ls -lh "${OUR}/${NAME}.wasm" | awk '{print $5}')"
