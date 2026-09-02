#!/bin/bash
# Smoke-test the in-browser recompiler's downloadable build bundle end to end,
# without a browser: recompile one SWF with SWFRecomp.wasm under Node (the same
# module the page runs), assemble a bundle directory exactly the way
# pipeline.js zips it (generated C + docs/recompiler/bundle/ snapshot), and run
# the bundle's build.sh with Emscripten. Fails if any step fails or the
# expected outputs are missing.
#
# Runs in the deploy-pages workflows after deploy_wasm_demo.sh, and locally:
#   bash SWFRecomp/scripts/bundle_smoke.sh [swf] [name]
#     swf   default docs/examples/graphics/awful_shape_swf_4/test.swf (tracked)
#     name  default awful_shape_swf_4
# Env: SMOKE_DIR (work dir, default SWFRecomp/build_wasm/bundle_smoke),
#      RT_OPT (build.sh opt level, default -O1 here: the smoke is about linking,
#      not speed).
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
DEMO_DIR="${PROJECT_ROOT}/docs/recompiler"

SWF="${1:-${PROJECT_ROOT}/docs/examples/graphics/awful_shape_swf_4/test.swf}"
NAME="${2:-awful_shape_swf_4}"
WORK="${SMOKE_DIR:-${SWFRECOMP_ROOT}/build_wasm/bundle_smoke}"
export RT_OPT="${RT_OPT:--O1}"

for f in "${DEMO_DIR}/SWFRecomp.js" "${DEMO_DIR}/SWFRecomp.wasm" "${DEMO_DIR}/bundle/manifest.json"; do
    [ -f "$f" ] || { echo "ERROR: $f missing — run deploy_wasm_demo.sh first" >&2; exit 1; }
done
command -v node >/dev/null || { echo "ERROR: node not found" >&2; exit 1; }

rm -rf "${WORK}"
B="${WORK}/${NAME}"
mkdir -p "${B}"

echo "=== 1. Recompile with SWFRecomp.wasm under Node ==="
node "${SCRIPT_DIR}/test_wasm_recompiler.mjs" --module "${DEMO_DIR}/SWFRecomp.js" --out "${B}" "${SWF}"

echo "=== 2. Assemble bundle (as pipeline.js does) ==="
# Everything in the manifest, at the same relative paths, minus the manifest.
python3 - "${DEMO_DIR}/bundle" "${B}" <<'EOF'
import json, os, shutil, sys
src, dst = sys.argv[1], sys.argv[2]
n = 0
for e in json.load(open(os.path.join(src, "manifest.json"))):
    if e["path"] == "manifest.json":
        continue
    s = os.path.join(src, e["path"]); d = os.path.join(dst, e["path"])
    assert os.path.getsize(s) == e["size"], f"manifest size mismatch: {e['path']}"
    os.makedirs(os.path.dirname(d), exist_ok=True)
    shutil.copy2(s, d); n += 1
print(f"    {n} snapshot files copied")
EOF
cp "${SWF}" "${B}/${NAME}.swf"
printf '[input]\npath_to_swf = "input.swf"\noutput_tags_folder = "RecompiledTags"\noutput_scripts_folder = "RecompiledScripts"\n' > "${B}/config.toml"
echo "${NAME}" > "${B}/NAME"
chmod +x "${B}/build.sh"

echo "=== 3. build.sh (Emscripten) ==="
if ! command -v emcc >/dev/null 2>&1 && [ -f "${PROJECT_ROOT}/emsdk/emsdk_env.sh" ]; then
    # shellcheck disable=SC1091
    source "${PROJECT_ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1
fi
( cd "${B}" && ./build.sh )

echo "=== 4. Check outputs ==="
for f in "${B}/out/${NAME}.js" "${B}/out/${NAME}.wasm" "${B}/out/index.html"; do
    [ -s "$f" ] || { echo "ERROR: missing output $f" >&2; exit 1; }
done
grep -q "${NAME}.js" "${B}/out/index.html" || { echo "ERROR: index.html does not load ${NAME}.js" >&2; exit 1; }
grep -q '_runSWF' "${B}/out/${NAME}.js" || { echo "ERROR: runSWF export missing from ${NAME}.js" >&2; exit 1; }
echo "OK: bundle builds — $(stat --printf='%s' "${B}/out/${NAME}.wasm") bytes wasm, $(sed -n 's/.*<canvas id="canvas" width="\([0-9]*\)" height="\([0-9]*\)".*/\1x\2/p' "${B}/out/index.html") canvas"
