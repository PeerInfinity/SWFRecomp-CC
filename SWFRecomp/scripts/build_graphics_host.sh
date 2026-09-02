#!/bin/bash
# Build the graphics HOST module for the in-browser recompiler (stage 2).
#
# Emscripten build of the full SWFModernRuntime graphics runtime (WebGPU via
# emdawnwebgpu, ASYNCIFY frame loop) with NO per-SWF generated code, compiled
# with -DDYNAMIC_HOST (see SWFModernRuntime/include/libswf/generated_data.h and
# SWFRecomp/wasm_wrappers/host_main_graphics.c). The per-SWF guest is compiled
# in the browser and instantiated into this host's memory by pipeline.js.
#
# Key link choices (why they are what they are is in host_main_graphics.c):
#   JSPI (not ASYNCIFY)           the frame loop and the renderer wait mid-frame
#                                 (emscripten_sleep / wgpuInstanceWaitAny); with
#                                 ASYNCIFY an unwind through a non-instrumented
#                                 GUEST frame corrupts the stack. JSPI suspends the
#                                 whole wasm stack in the engine, guest frames included.
#   --table-base=HOST_TABLE_BASE  reserve low table slots for the guest's table
#   GLOBAL_BASE=GUEST_ARENA_END   host data/stack/heap above 101 MB; the guest is
#                                 linked at a fixed --global-base=64 KB below it
#   SHARED_MEMORY=1               the in-browser clang emits --shared-memory guests
#   EXPORTED_FUNCTIONS=<all>      every runtime symbol resolves guest imports
#
# Usage: build_graphics_host.sh [out_dir]   (default: SWFRecomp/build_graphics_host)
#   AVM2=1  build the AVM2 host variant (graphics_host_avm2.{js,wasm}): the
#           AVM2 runtime source set (src/avm2, quickjs-libregexp, lzma, zlib)
#           with -DSWF_AVM2; runSWF drives runSWF_avm2. Assessment:
#           SWFRecompDocs/plans/avm2-in-browser-assessment.md
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"
BUILD_DIR="${1:-${SWFRECOMP_ROOT}/build_graphics_host}"
HOST_TABLE_BASE="${HOST_TABLE_BASE:-262144}"
GUEST_ARENA_END="${GUEST_ARENA_END:-105906176}"   # 101 MB; host data/stack/heap live above this
AVM2="${AVM2:-0}"
HOST_NAME="graphics_host"; [ "${AVM2}" = "1" ] && HOST_NAME="graphics_host_avm2"

if ! command -v emcc >/dev/null 2>&1; then
    if [ -f "${PROJECT_ROOT}/emsdk/emsdk_env.sh" ]; then
        # shellcheck disable=SC1091
        source "${PROJECT_ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1
    elif [ -n "${EMSDK:-}" ] && [ -f "${EMSDK}/emsdk_env.sh" ]; then
        # shellcheck disable=SC1091
        source "${EMSDK}/emsdk_env.sh" >/dev/null 2>&1
    fi
fi
command -v emcc >/dev/null 2>&1 || { echo "ERROR: emcc not found" >&2; exit 1; }

rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}/src"
SRC="${BUILD_DIR}/src"

# Same runtime source set as the downloadable bundle's build.sh (AVM1 graphics
# branch of build_test.sh), minus generated code, plus the host main.
RUNTIME_C=(
    actionmodern/action.c actionmodern/math.c actionmodern/date.c
    actionmodern/registered_class.c actionmodern/timer.c actionmodern/variables.c
    actionmodern/avm1_amf.c actionmodern/object.c actionmodern/action_queue.c
    actionmodern/sprite_frame_scripts.c actionmodern/image_decode.c
    actionmodern/video_codec.c
    utils.c amf_packet.c
    libswf/swf.c libswf/tag.c libswf/tag_stubs.c libswf/shape_hit_test.c
    libswf/ng_shared.c libswf/hit_test.c libswf/graphics_stubs.c
    libswf/stb_image_impl.c
    audio/audio.c audio/audio_output_web.c
    rendering/render_webgpu.c
    memory/heap.c
)
for f in "${RUNTIME_C[@]}"; do cp -p "${SWFMODERN_SRC}/${f}" "${SRC}/"; done
cp -p "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${SRC}/"
cp -p "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${SWFMODERN_ROOT}/lib/c-hashmap/map.h" "${SRC}/"
cp -p "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${SRC}/"
cp -p "${SWFMODERN_ROOT}/lib/stb/stb_image.h" "${SRC}/"
cp -p "${SWFMODERN_ROOT}/third_party/libtess2"/*.c "${SWFMODERN_ROOT}/third_party/libtess2"/*.h "${SRC}/"
cp -p "${SWFRECOMP_ROOT}/wasm_wrappers/host_main_graphics.c" "${SRC}/"
if [ "${AVM2}" = "1" ]; then
    cp -p "${SWFMODERN_SRC}"/avm2/*.c "${SRC}/"
    cp -p "${SWFMODERN_ROOT}/third_party/quickjs-libregexp"/*.c "${SWFMODERN_ROOT}/third_party/quickjs-libregexp"/*.h "${SRC}/"
    cp -p "${SWFMODERN_ROOT}/third_party/lzma"/*.c "${SWFMODERN_ROOT}/third_party/lzma"/*.h "${SRC}/"
fi

EMCC_FLAGS=(
    -DUSE_WEBGPU -DDYNAMIC_HOST "-DHOST_TABLE_BASE=${HOST_TABLE_BASE}" "-DGUEST_ARENA_END=${GUEST_ARENA_END}u"
    -sSHARED_MEMORY=1   # objects must carry atomics/bulk-memory for the shared-memory link
    -sSUPPORT_LONGJMP=wasm   # no JS invoke_* trampolines: JSPI cannot suspend across JS frames
    --use-port=emdawnwebgpu
    -Wno-error=implicit-function-declaration -Wno-implicit-function-declaration
    -Wno-unused-variable -Wno-unused-but-set-variable -Wno-incompatible-pointer-types
    -I"${SRC}"
    -I"${SWFMODERN_INC}" -I"${SWFMODERN_INC}/actionmodern" -I"${SWFMODERN_INC}/libswf"
    -I"${SWFMODERN_INC}/memory" -I"${SWFMODERN_INC}/rendering" -I"${SWFMODERN_INC}/audio"
    -I"${SWFMODERN_ROOT}/lib/c-hashmap" -I"${SWFMODERN_ROOT}/lib/o1heap" -I"${SWFMODERN_ROOT}/lib/stb"
    -I"${SWFMODERN_ROOT}/third_party/libtess2"
    -O2
)
LINK_EXTRA=()
if [ "${AVM2}" = "1" ]; then
    # Same defines as the downloadable bundle's AVM2 arm (SWF_URL/SWF_*_SIZE are
    # compile-time there; a host variant would have to make them runtime-set).
    EMCC_FLAGS+=(-DSWF_AVM2 -DMOCK_DATE_TIME=981152406000LL -msimd128 -I"${SWFMODERN_INC}/avm2" -sUSE_ZLIB=1)
    LINK_EXTRA=(-sUSE_ZLIB=1 -msimd128)
fi

echo "=== Compiling host objects ==="
OBJS=()
for src in "${SRC}"/*.c; do
    obj="${BUILD_DIR}/$(basename "${src}" .c).o"
    emcc "${EMCC_FLAGS[@]}" -c "${src}" -o "${obj}"
    OBJS+=("${obj}")
done

# Export every defined function/data symbol so guest imports resolve by name.
echo "=== Building export list ==="
NM="$(dirname "$(command -v emcc)")/../bin/llvm-nm"
[ -x "${NM}" ] || NM="$(command -v llvm-nm)"
{
    for obj in "${OBJS[@]}"; do
        # Skip internal/EM_JS bookkeeping symbols (__em_js__*, __wasm_*...).
        "${NM}" "${obj}" 2>/dev/null | awk '($2 == "T" || $2 == "D" || $2 == "B") && $3 !~ /^__/ { print "\"_" $3 "\"" }'
    done
    printf '"_main"\n"_malloc"\n"_free"\n'
} | sort -u > "${BUILD_DIR}/exports.txt"
echo "[$(tr '\n' ',' < "${BUILD_DIR}/exports.txt" | sed 's/,$//')]" > "${BUILD_DIR}/exports.json"
echo "  $(wc -l < "${BUILD_DIR}/exports.txt") symbols exported"

echo "=== Linking graphics_host.js / graphics_host.wasm ==="
emcc "${OBJS[@]}" --use-port=emdawnwebgpu "${LINK_EXTRA[@]}" \
    -o "${BUILD_DIR}/${HOST_NAME}.js" \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS=@"${BUILD_DIR}/exports.json" \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","wasmMemory","wasmTable","wasmExports","HEAPU8","HEAPU32"]' \
    -s ALLOW_TABLE_GROWTH=1 \
    -s SHARED_MEMORY=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s INITIAL_MEMORY=335544320 \
    -s MAXIMUM_MEMORY=2147483648 \
    -s STACK_SIZE=8MB \
    -s MODULARIZE=1 -s EXPORT_NAME=createGraphicsHost \
    -s ENVIRONMENT=web \
    -sJSPI -sJSPI_EXPORTS='["runSWF"]' -sSUPPORT_LONGJMP=wasm \
    "-Wl,--table-base=${HOST_TABLE_BASE}" \
    "-sGLOBAL_BASE=${GUEST_ARENA_END}" \
    --profiling-funcs \
    -O2

echo
echo "Built:"
ls -lh "${BUILD_DIR}/${HOST_NAME}.js" "${BUILD_DIR}/${HOST_NAME}.wasm"
