#!/bin/bash
# Deploy the in-browser SWF recompiler page to docs/recompiler/.
#
# The page recompiles a dropped SWF to C entirely in the browser
# (SWFRecomp.wasm) and offers a zip "build bundle": the generated C plus a
# snapshot of the runtime sources and a build.sh that produces a WebGPU WASM
# page locally with Emscripten. This script refreshes both halves from the
# current tree so they always match:
#   1. SWFRecomp.js/.wasm  (from build_wasm_recompiler.sh; pass --build to rebuild)
#   2. docs/recompiler/bundle/  (runtime snapshot + build.sh + manifest.json)
# and writes build_info.json (commit + timestamp shown on the page).
#
# Usage: deploy_wasm_demo.sh [--build]
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"
WRAPPERS="${SWFRECOMP_ROOT}/wasm_wrappers"

DEMO_DIR="${PROJECT_ROOT}/docs/recompiler"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"
BUNDLE_DIR="${DEMO_DIR}/bundle"

if [ "${1:-}" = "--build" ] || [ ! -f "${BUILD_DIR}/SWFRecomp.wasm" ]; then
    echo "Building SWFRecomp.wasm..."
    bash "${SCRIPT_DIR}/build_wasm_recompiler.sh"
fi

echo "Deploying in-browser recompiler to ${DEMO_DIR}..."
mkdir -p "${DEMO_DIR}"

# --- 1. Recompiler wasm ---
echo "  Copying SWFRecomp.js / SWFRecomp.wasm..."
cp "${BUILD_DIR}/SWFRecomp.js" "${DEMO_DIR}/SWFRecomp.js"
cp "${BUILD_DIR}/SWFRecomp.wasm" "${DEMO_DIR}/SWFRecomp.wasm"

# Trace mode (in-browser clang + WASI) was removed 2026-09; drop its artifacts
# if a previous deploy left them behind.
rm -f "${DEMO_DIR}/libswfruntime.a" "${DEMO_DIR}/wasi_shim.js"
rm -rf "${DEMO_DIR}/runtime_src"

# --- 2. Build bundle: runtime snapshot + build script ---
echo "  Assembling build bundle snapshot..."
rm -rf "${BUNDLE_DIR}"
RT="${BUNDLE_DIR}/runtime"
mkdir -p "${RT}/src" "${RT}/lib/c-hashmap" "${RT}/lib/o1heap" "${RT}/lib/stb" "${RT}/third_party"

cp "${WRAPPERS}/bundle/build.sh" "${WRAPPERS}/bundle/README.md" "${BUNDLE_DIR}/"
chmod +x "${BUNDLE_DIR}/build.sh"
cp "${WRAPPERS}/main.c" "${WRAPPERS}/display_bridge.c" "${WRAPPERS}/swf_bridge.js" \
   "${WRAPPERS}/index_template_graphics.html" "${RT}/"

# Runtime sources: the union of build_test.sh (wasm --graphics) and
# build_wasm_avm2.sh source lists. build.sh picks the subset per SWF.
RUNTIME_C=(
    actionmodern/action.c actionmodern/math.c actionmodern/date.c
    actionmodern/registered_class.c actionmodern/timer.c actionmodern/variables.c
    actionmodern/avm1_amf.c actionmodern/object.c actionmodern/action_queue.c
    actionmodern/sprite_frame_scripts.c actionmodern/image_decode.c
    actionmodern/video_codec.c actionmodern/unicode_case_tables.h
    utils.c amf_packet.c
    libswf/swf.c libswf/tag.c libswf/tag_stubs.c libswf/shape_hit_test.c
    libswf/ng_shared.c libswf/hit_test.c libswf/graphics_stubs.c
    libswf/stb_image_impl.c
    audio/audio.c audio/audio_output_web.c
    rendering/render_webgpu.c
    memory/heap.c
)
for f in "${RUNTIME_C[@]}"; do
    mkdir -p "${RT}/src/$(dirname "${f}")"
    cp "${SWFMODERN_SRC}/${f}" "${RT}/src/${f}"
done
mkdir -p "${RT}/src/avm2"
cp "${SWFMODERN_SRC}/avm2"/*.c "${RT}/src/avm2/"
cp -r "${SWFMODERN_INC}" "${RT}/include"
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${SWFMODERN_ROOT}/lib/c-hashmap/map.h" "${RT}/lib/c-hashmap/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${RT}/lib/o1heap/"
cp "${SWFMODERN_ROOT}/lib/stb/stb_image.h" "${RT}/lib/stb/"
for tp in libtess2 quickjs-libregexp lzma; do
    mkdir -p "${RT}/third_party/${tp}"
    cp "${SWFMODERN_ROOT}/third_party/${tp}"/*.c "${SWFMODERN_ROOT}/third_party/${tp}"/*.h "${RT}/third_party/${tp}/" 2>/dev/null || true
done

# manifest.json: every bundle file with its size (the page fetches these and
# zips them together with the generated C).
python3 - "${BUNDLE_DIR}" <<'EOF'
import json, os, sys
root = sys.argv[1]
entries = []
for dp, _, fns in os.walk(root):
    for fn in sorted(fns):
        p = os.path.join(dp, fn)
        rel = os.path.relpath(p, root).replace(os.sep, "/")
        entries.append({"path": rel, "size": os.path.getsize(p)})
entries.sort(key=lambda e: e["path"])
with open(os.path.join(root, "manifest.json"), "w") as f:
    json.dump(entries, f, indent=0)
total = sum(e["size"] for e in entries)
print(f"    {len(entries)} files, {total/1024/1024:.1f} MB")
EOF

# --- 3. Build info (shown in the page footer, embedded in each bundle) ---
COMMIT="$(git -C "${PROJECT_ROOT}" rev-parse --short HEAD 2>/dev/null || echo unknown)"
cat > "${DEMO_DIR}/build_info.json" <<ENDJSON
{
  "built_at": "$(date -u +%Y-%m-%dT%H:%M:%SZ)",
  "commit": "${COMMIT}",
  "recompiler_wasm_bytes": $(stat --printf='%s' "${DEMO_DIR}/SWFRecomp.wasm")
}
ENDJSON

echo ""
echo "Deployed. Test locally with:"
echo "  (cd ${PROJECT_ROOT}/docs && python3 -m http.server 8010)   # http://localhost:8010/recompiler/"
echo "Then commit docs/recompiler/ and dispatch the 'Deploy GitHub Pages' workflow."
