#!/usr/bin/env bash
# run_so_hook_test.sh — browser (wasm) test of the AVM2 SharedObject host-hook
# contract. Builds test.swf -> recompiled C -> sohook.wasm under $WORK, serves
# harness.html + the build, and drives it with so_hook_test.js.
#   HEADLESS=1   headless SwiftShader (Vulkan flags) instead of headed WSLg
#   WORK=dir     build dir (default: mktemp)
set -euo pipefail
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
WORK="${WORK:-$(mktemp -d)}"
PORT="${HTTP_PORT:-8093}"
NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-$HOME/CC/Archipelago-CC/node_modules}"
mkdir -p "${WORK}/recomp" "${WORK}/serve"
[ -f "${HERE}/test.swf" ] || "${HERE}/build_swf.sh"   # test.swf is gitignored
cp "${HERE}/test.swf" "${WORK}/recomp/"
( cd "${WORK}/recomp" && "${ROOT}/SWFRecomp/build/SWFRecomp" "${ROOT}/ruffle-tests/_shared/config.toml" >/dev/null )
AVM2_OUT_DIR="${WORK}/wasm" "${ROOT}/SWFRecomp/scripts/build_wasm_avm2.sh" sohook "${WORK}/recomp" >"${WORK}/build.log" 2>&1 \
    || { tail -30 "${WORK}/build.log"; exit 2; }
cp "${WORK}/wasm/sohook.js" "${WORK}/wasm/sohook.wasm" "${HERE}/harness.html" "${WORK}/serve/"
( cd "${WORK}/serve" && exec python3 -m http.server "${PORT}" --bind 127.0.0.1 >/dev/null 2>&1 ) &
HTTP_PID=$!
trap 'kill ${HTTP_PID} 2>/dev/null || true' EXIT
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${PORT}") 2>/dev/null && break; sleep 0.25; done
HARNESS_BASE="http://127.0.0.1:${PORT}" NODE_PATH="${NODE_MODULES}" node "${HERE}/so_hook_test.js"
