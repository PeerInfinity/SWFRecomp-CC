#!/bin/bash
# build_wasm_avm2.sh — Stage 13a/13b: emscripten browser-WASM build of a
# recompiled AVM2 (AS3) game (Seedling), the AVM2 analog of build_test.sh's
# `wasm --graphics` path.
#
# Unlike the AVM1 demos (whose RecompiledScripts/Tags live under a repo test
# dir), the AVM2 game is recompiled OUTSIDE the repo (the 7.7 MB Seedling
# teleport SWF -> ~21 MB of generated C). This script consumes that prebuilt
# recompiled tree directly.
#
# Usage:
#   build_wasm_avm2.sh <name> <recompiled_dir>
#     <name>            output basename (e.g. seedling) -> <name>.js/.wasm
#     <recompiled_dir>  dir containing RecompiledABC/ RecompiledScripts/
#                       RecompiledTags/ (default: ~/CC/seedling_teleport_build/recompiled)
#
# Env:
#   AVM2_OUT_DIR      build/output dir (default: SWFRecomp/build_wasm_avm2/<name>)
#   ABC_OPT           opt level for the giant RecompiledABC TUs (default -O1;
#                     -O0 compiles faster/bigger, -Oz smallest/slowest)
#   RT_OPT            opt level for runtime + other TUs (default -O2)
#   MOCK_DATE_TIME    deterministic clock ms (default 981152406000, Ruffle mode)
#   SWF_URL           value of loaderInfo.url / the SWF's own origin (default
#                     file:///test.swf). Games that gate boot on their origin
#                     need an http URL here: Robot Wants Fishy and Ice Cream
#                     check `new LocalConnection().domain` in their preloader
#                     and blank the stage when it is "localhost", which is what
#                     a file:// URL yields (see avm2-robot-wants-sequels plan).
#   FRESH             1 = wipe .o cache first (default: incremental)
#
# The build is INCREMENTAL: a .c is only recompiled if its .o is missing or
# older, so iterating on a runtime file re-links in seconds (the 13 MB
# abc0_methods.c dominates a cold build). This is the ccache substitute since
# emcc's default has none here.
set -euo pipefail

NAME="${1:-seedling}"
RECOMP_DIR="${2:-$HOME/CC/seedling_teleport_build/recompiled}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${REPO_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"

ABC_OPT="${ABC_OPT:--O1}"
RT_OPT="${RT_OPT:--O2}"
MOCK_DATE_TIME="${MOCK_DATE_TIME:-981152406000}"
SWF_URL="${SWF_URL:-file:///test.swf}"
OUT_DIR="${AVM2_OUT_DIR:-${SWFRECOMP_ROOT}/build_wasm_avm2/${NAME}}"
SRC_DIR="${OUT_DIR}/src"    # flat dir of .c we compile (keeps ccache-ish .o cache)
OBJ_DIR="${OUT_DIR}/obj"

[ -d "${RECOMP_DIR}/RecompiledABC" ] || { echo "ERROR: no RecompiledABC in ${RECOMP_DIR}" >&2; exit 1; }

# ---- ensure emcc ----
if ! command -v emcc >/dev/null 2>&1; then
    [ -f "${REPO_ROOT}/emsdk/emsdk_env.sh" ] && source "${REPO_ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || true
fi
command -v emcc >/dev/null 2>&1 || { echo "ERROR: emcc not found (source emsdk/emsdk_env.sh)" >&2; exit 1; }

if [ "${FRESH:-0}" = "1" ]; then rm -rf "${OUT_DIR}"; fi
mkdir -p "${SRC_DIR}" "${OBJ_DIR}"

echo "=== Staging sources -> ${SRC_DIR} ==="
# main wrapper
cp -p "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "${SRC_DIR}/"

# AVM1 runtime (linked as dead weight: swf.c owns RenderContext* context and
# swf_perf_report, which the AVM2 render walk + browser HUD drive; swf.c drags
# in the action.c runtime). Mirrors verify_output's AVM2-graphics source set.
RUNTIME_C=(
    actionmodern/action.c actionmodern/math.c actionmodern/date.c
    actionmodern/registered_class.c actionmodern/timer.c actionmodern/variables.c
    actionmodern/object.c actionmodern/action_queue.c actionmodern/sprite_frame_scripts.c
    actionmodern/image_decode.c actionmodern/video_codec.c
    utils.c
    libswf/swf.c libswf/tag.c libswf/tag_stubs.c libswf/shape_hit_test.c
    libswf/ng_shared.c libswf/hit_test.c libswf/graphics_stubs.c libswf/stb_image_impl.c
    audio/audio.c audio/audio_output_web.c
    rendering/render_webgpu.c
    memory/heap.c
)
for f in "${RUNTIME_C[@]}"; do cp -p "${SWFMODERN_SRC}/${f}" "${SRC_DIR}/"; done
cp -p "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${SRC_DIR}/"

# AVM2 runtime tree
for f in "${SWFMODERN_SRC}"/avm2/*.c; do cp -p "${f}" "${SRC_DIR}/"; done

# QuickJS libregexp (vendored) backs the AVM2 RegExp builtin (avm2_regexp.c).
if [ -d "${SWFMODERN_ROOT}/third_party/quickjs-libregexp" ]; then
    cp -p "${SWFMODERN_ROOT}/third_party/quickjs-libregexp"/*.c "${SRC_DIR}/" 2>/dev/null || true
    cp -p "${SWFMODERN_ROOT}/third_party/quickjs-libregexp"/*.h "${SRC_DIR}/" 2>/dev/null || true
fi

# libtess2 + support libs
cp -p "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${SRC_DIR}/"
cp -p "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${SRC_DIR}/"
cp -p "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${SRC_DIR}/"
cp -p "${SWFMODERN_ROOT}/lib/c-hashmap/map.h" "${SRC_DIR}/" 2>/dev/null || true
if [ -d "${SWFMODERN_ROOT}/third_party/libtess2" ]; then
    cp -p "${SWFMODERN_ROOT}/third_party/libtess2"/*.c "${SRC_DIR}/" 2>/dev/null || true
    cp -p "${SWFMODERN_ROOT}/third_party/libtess2"/*.h "${SRC_DIR}/" 2>/dev/null || true
fi
cp -p "${SWFMODERN_ROOT}/lib/stb/stb_image.h" "${SRC_DIR}/" 2>/dev/null || true
mkdir -p "${SRC_DIR}/memory"
cp -p "${SWFMODERN_INC}/memory/heap.h" "${SRC_DIR}/memory/" 2>/dev/null || true

# Generated game C (huge). Kept in subdirs so basenames don't collide and so the
# recompiled headers resolve via -I.
cp -p "${RECOMP_DIR}/RecompiledABC"/*.c    "${SRC_DIR}/" 2>/dev/null || true
cp -p "${RECOMP_DIR}/RecompiledABC"/*.h    "${SRC_DIR}/" 2>/dev/null || true
cp -p "${RECOMP_DIR}/RecompiledScripts"/*.c "${SRC_DIR}/" 2>/dev/null || true
cp -p "${RECOMP_DIR}/RecompiledScripts"/*.h "${SRC_DIR}/" 2>/dev/null || true
cp -p "${RECOMP_DIR}/RecompiledTags"/*.c   "${SRC_DIR}/" 2>/dev/null || true
cp -p "${RECOMP_DIR}/RecompiledTags"/*.h   "${SRC_DIR}/" 2>/dev/null || true

# ---- SWF size defines (from the recompiled SWF) ----
SWF_FILE_SIZE=0; SWF_ONDISK_SIZE=0
if [ -f "${RECOMP_DIR}/test.swf" ]; then
    SWF_ONDISK_SIZE=$(stat -c%s "${RECOMP_DIR}/test.swf")
    SWF_FILE_SIZE=$(python3 - "$RECOMP_DIR/test.swf" <<'PY'
import struct,sys
with open(sys.argv[1],'rb') as f: h=f.read(8)
print(struct.unpack('<I',h[4:8])[0] if len(h)>=8 else len(h))
PY
)
fi

INCLUDES=(
    -I"${SRC_DIR}"
    -I"${SWFMODERN_INC}"
    -I"${SWFMODERN_INC}/actionmodern"
    -I"${SWFMODERN_INC}/libswf"
    -I"${SWFMODERN_INC}/memory"
    -I"${SWFMODERN_INC}/rendering"
    -I"${SWFMODERN_INC}/audio"
    -I"${SWFMODERN_INC}/avm2"
    -I"${SWFMODERN_ROOT}/lib/c-hashmap"
    -I"${SWFMODERN_ROOT}/lib/o1heap"
)
DEFINES=(
    -DUSE_WEBGPU
    -DSWF_AVM2
    -DMOCK_DATE_TIME=${MOCK_DATE_TIME}LL
    -DSWF_FILE_SIZE=${SWF_FILE_SIZE}
    -DSWF_ONDISK_SIZE=${SWF_ONDISK_SIZE}
    "-DSWF_URL=\"${SWF_URL}\""
)
# WASM SIMD (128-bit) — enables __wasm_simd128__ so the AVM2 bitmap blit
# (avm2_bitmap.c) uses its 4-pixel-wide byte-exact blend_over kernel on the hot
# FlashPunk Image.render software-blit path. Universally supported in the target
# browsers (baseline since ~2021). Scalar fallback compiles when this is absent.
SIMD_FLAGS=(-msimd128)
WARN=(
    -Wno-error=implicit-function-declaration
    -Wno-implicit-function-declaration
    -Wno-unused-variable -Wno-unused-but-set-variable
    -Wno-incompatible-pointer-types
)
# Extra compile flags (space-separated), e.g. EXTRA_CFLAGS="-DSWF_NO_BLIT_SIMD" for
# an A/B baseline or "-DAVM2_BLIT_VERIFY" for the SIMD-vs-scalar guard. NOTE: the
# .o cache keys on mtime, NOT on -D flags, so a flag change needs FRESH=1 (or touch
# the affected .c) or you'll link stale objects (the coerce-memo flag-staleness trap).
read -r -a EXTRA_CFLAGS_ARR <<< "${EXTRA_CFLAGS:-}"

# Pick per-TU opt level: the two giant generated ABC TUs get ABC_OPT.
opt_for() {
    case "$1" in
        abc0_methods.c|abc_timeline.c|abc0_tables.c) echo "${ABC_OPT}" ;;
        *) echo "${RT_OPT}" ;;
    esac
}

echo "=== Compiling (incremental; giant ABC TUs at ${ABC_OPT}, rest ${RT_OPT}) ==="
# Compile the small/runtime TUs FIRST and the giant generated ABC TUs LAST, so a
# syntax/type error in an edited runtime file surfaces in seconds rather than
# after the 13 MB abc0_methods.c compile.
mapfile -t ALL_SRC < <(ls "${SRC_DIR}"/*.c | grep -Ev '/(abc0_methods|abc_timeline|abc0_tables)\.c$'; ls "${SRC_DIR}"/{abc0_tables,abc_timeline,abc0_methods}.c 2>/dev/null)
OBJS=()
NCOMPILED=0
for src in "${ALL_SRC[@]}"; do
    base="$(basename "${src}" .c)"
    obj="${OBJ_DIR}/${base}.o"
    OBJS+=("${obj}")
    if [ -f "${obj}" ] && [ "${obj}" -nt "${src}" ]; then continue; fi
    o="$(opt_for "$(basename "${src}")")"
    printf '  %-28s %s\n' "$(basename "${src}")" "${o}"
    emcc "${DEFINES[@]}" "${SIMD_FLAGS[@]}" "${EXTRA_CFLAGS_ARR[@]}" --use-port=emdawnwebgpu "${INCLUDES[@]}" "${WARN[@]}" \
        "${o}" -c "${src}" -o "${obj}"
    NCOMPILED=$((NCOMPILED+1))
done
echo "  (${NCOMPILED} TUs (re)compiled)"

echo "=== Linking ${NAME}.js / ${NAME}.wasm ==="
# _avm2_ei_dispatch: the ExternalInterface addCallback dispatcher (host JS ->
# registered AS3 callback; avm2_external.c). _malloc/_free back its EM_ASM
# string marshaling (module-scope _malloc is only present when exported).
EXPORTED_FUNCS='["_main","_runSWF","_audio_fill_buffer","_avm2_ei_dispatch","_malloc","_free"]'
# INITIAL_MEMORY is committed + zero-filled RESIDENT at page load (before the
# user hits Start), so it is the pre-Start footprint. The o1heap arena (now
# 512 MB, memory/heap.c) lands lazily at Start via ALLOW_MEMORY_GROWTH, so
# INITIAL_MEMORY only needs the wasm base (~130 MB). Was 512 MB; 128 MB cuts
# the at-load commit ~4x, grown on demand. MAXIMUM_MEMORY stays 4GB — a
# harmless address-space cap; it can drop to ~1GB once the 512 MB arena is
# browser-validated (avm2-browser-footprint.md §6.3).
emcc "${OBJS[@]}" \
    --use-port=emdawnwebgpu \
    "${SIMD_FLAGS[@]}" \
    -o "${OUT_DIR}/${NAME}.js" \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS="${EXPORTED_FUNCS}" \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPF32","HEAPU8"]' \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s INITIAL_MEMORY=128MB \
    -s MAXIMUM_MEMORY=4GB \
    -s STACK_SIZE=8MB \
    -sUSE_ZLIB=1 \
    -sASYNCIFY \
    -sASYNCIFY_STACK_SIZE=65536 \
    ${RT_OPT}

echo ""
echo "✅ WASM build complete!"
ls -lh "${OUT_DIR}/${NAME}.wasm" "${OUT_DIR}/${NAME}.js"
echo "Output dir: ${OUT_DIR}"
