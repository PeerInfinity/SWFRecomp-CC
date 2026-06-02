#!/bin/bash
# profile_game_native.sh — build a recompiled game natively with profiling flags
# and profile a fixed number of frames under callgrind.
#
# Phase 1 of SWFRecompDocs/plans/wasm-game-performance-profiling-plan.md.
#
# Why native + callgrind: the generated C is portable, so we profile the exact
# runtime code natively (deterministic instruction counts, real function names)
# and the findings transfer to WASM. The browser frame loop is frame-capped, so
# wall-clock FPS hides the engine's real cost — callgrind measures the per-frame
# CPU work directly.
#
# Usage:
#   ./scripts/profile_game_native.sh <test_name> [frames] [mode] [options]
#
#   test_name   Path under SWFRecomp/tests/ (e.g. local_batch/Doodle_Jump)
#   frames      MAX_FRAMES to run (default 500)
#   mode        no-graphics (default) | graphics
#                 no-graphics: swf_core.c, rendering stubbed — isolates the
#                              AVM1 interpreter + tag/queue/sprite cost.
#                 graphics:    swf.c + offscreen Dawn (OFFSCREEN_RENDER) — the
#                              real browser loop incl. the renderer. Needs Dawn
#                              at ~/CC/dawn-install (or $DAWN_INSTALL).
#
# Options:
#   --build-only      Stage + compile, skip the callgrind run.
#   --run-only        Skip staging/compile, just (re)run callgrind on existing binary.
#   --input=FILE      Input-event script passed as argv[1] (deterministic input).
#   --no-callgrind    Run the binary directly (timed) instead of under callgrind.
#
# Output (under <test_dir>/build/profile-<mode>/):
#   <name>             the profiling binary
#   callgrind.out      raw callgrind data
#   callgrind.txt      ranked callgrind_annotate report (the deliverable)
set -e

TEST_NAME=$1
MAX_FRAMES=${2:-500}
MODE=${3:-no-graphics}

# Re-scan args for flags (so they work in any position after the positionals)
BUILD_ONLY=false
RUN_ONLY=false
NO_CALLGRIND=false
INPUT_FILE=""
for arg in "$@"; do
    case "$arg" in
        --build-only)   BUILD_ONLY=true ;;
        --run-only)     RUN_ONLY=true ;;
        --no-callgrind) NO_CALLGRIND=true ;;
        --input=*)      INPUT_FILE="${arg#--input=}" ;;
    esac
done

if [ -z "$TEST_NAME" ]; then
    echo "Usage: $0 <test_name> [frames] [no-graphics|graphics] [--build-only|--run-only|--no-callgrind] [--input=FILE]"
    exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
TEST_DIR="${SWFRECOMP_ROOT}/tests/${TEST_NAME}"
SWFMODERN_ROOT="${SWFRECOMP_ROOT}/../SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"
BUILD_DIR="${TEST_DIR}/build/profile-${MODE}"
OUTPUT_NAME="$(basename "$TEST_NAME")"
MOCK_DATE_TIME=981152406000   # 2001-02-03 04:05:06 NPT — matches verify_output.py

if [ ! -d "$TEST_DIR" ]; then
    echo "Error: test directory not found: $TEST_DIR"
    exit 1
fi

# ---------------------------------------------------------------------------
# Recompile the SWF if needed (cached once RecompiledScripts exists).
# ---------------------------------------------------------------------------
if [ "$RUN_ONLY" != true ] && [ ! -d "${TEST_DIR}/RecompiledScripts" ]; then
    echo "Running SWFRecomp on ${TEST_NAME}..."
    (cd "${TEST_DIR}" && bash -c 'ulimit -v 4194304; ulimit -s unlimited; exec "$@"' \
        -- "${SWFRECOMP_ROOT}/build/SWFRecomp" config.toml)
fi

# ---------------------------------------------------------------------------
# Stage runtime sources. Source lists mirror ruffle-tests/verify_output.py
# (compile_native, ~lines 1561-1596) — keep in sync if that list changes.
# ---------------------------------------------------------------------------
if [ "$RUN_ONLY" != true ]; then
    echo "Staging sources into ${BUILD_DIR} (mode=${MODE})..."
    rm -rf "${BUILD_DIR}"
    mkdir -p "${BUILD_DIR}/memory"

    COMMON_SRCS=(
        actionmodern/action.c actionmodern/math.c actionmodern/date.c
        actionmodern/registered_class.c actionmodern/timer.c
        actionmodern/variables.c actionmodern/object.c
        actionmodern/action_queue.c actionmodern/sprite_frame_scripts.c
        actionmodern/image_decode.c actionmodern/video_codec.c
        utils.c
        libswf/tag.c libswf/tag_stubs.c libswf/shape_hit_test.c
        libswf/ng_shared.c libswf/hit_test.c libswf/stb_image_impl.c
        memory/heap.c
    )
    for s in "${COMMON_SRCS[@]}"; do cp "${SWFMODERN_SRC}/${s}" "${BUILD_DIR}/"; done
    # Runtime-local header included by action.c with quotes.
    cp "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${BUILD_DIR}/"

    if [ "$MODE" = "graphics" ]; then
        for s in libswf/swf.c libswf/capture.c libswf/graphics_stubs.c \
                 libswf/input_events.c audio/audio.c audio/audio_output_web.c \
                 rendering/render_webgpu.c; do
            cp "${SWFMODERN_SRC}/${s}" "${BUILD_DIR}/"
        done
    else
        cp "${SWFMODERN_SRC}/libswf/swf_core.c" "${BUILD_DIR}/"
    fi

    # Libraries + headers
    cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${BUILD_DIR}/"
    cp "${SWFMODERN_ROOT}/lib/stb/stb_image.h" "${BUILD_DIR}/"
    cp "${SWFMODERN_INC}/memory/heap.h" "${BUILD_DIR}/memory/"
    if [ -d "${SWFMODERN_ROOT}/third_party/libtess2" ]; then
        cp "${SWFMODERN_ROOT}/third_party/libtess2/"*.c "${BUILD_DIR}/" 2>/dev/null || true
        cp "${SWFMODERN_ROOT}/third_party/libtess2/"*.h "${BUILD_DIR}/" 2>/dev/null || true
    fi

    # Wrapper + generated game code
    cp "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "${BUILD_DIR}/"
    cp "${TEST_DIR}/RecompiledScripts/"*.c "${TEST_DIR}/RecompiledScripts/"*.h "${BUILD_DIR}/" 2>/dev/null || true
    cp "${TEST_DIR}/RecompiledTags/"*.c "${TEST_DIR}/RecompiledTags/"*.h "${BUILD_DIR}/" 2>/dev/null || true

    # ---------------------------------------------------------------------------
    # Compile. Profiling flags: -O2 (representative of release) + -g (symbols for
    # callgrind) + -fno-omit-frame-pointer. Per-file compile so ccache caches the
    # expensive action.c (~50s cold, ~instant warm).
    # ---------------------------------------------------------------------------
    SWF_FILE_SIZE=$( [ -f "${TEST_DIR}/test.swf" ] && stat -c%s "${TEST_DIR}/test.swf" || echo 0 )

    MODE_DEFINES=()
    MODE_INCLUDES=()
    MODE_LIBS=(-lm -lz)
    if [ "$MODE" = "graphics" ]; then
        DAWN_INSTALL="${DAWN_INSTALL:-$HOME/CC/dawn-install}"
        if [ ! -f "${DAWN_INSTALL}/lib/libwebgpu_dawn.a" ]; then
            echo "Error: graphics mode needs Dawn at ${DAWN_INSTALL}/lib/libwebgpu_dawn.a"
            exit 1
        fi
        MODE_DEFINES=(-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG)
        MODE_INCLUDES=(-I"${SWFMODERN_INC}/rendering" -I"${SWFRECOMP_ROOT}/lib/stb" -I"${DAWN_INSTALL}/include")
        MODE_LIBS=("${DAWN_INSTALL}/lib/libwebgpu_dawn.a" -lstdc++ -lpthread -ldl -lm -lz)
    else
        MODE_DEFINES=(-DNO_GRAPHICS)
    fi

    COMMON_FLAGS=(
        "${MODE_DEFINES[@]}"
        -DMAX_FRAMES="${MAX_FRAMES}"
        -DMOCK_DATE_TIME="${MOCK_DATE_TIME}LL"
        -DSWF_FILE_SIZE="${SWF_FILE_SIZE}"
        '-DSWF_URL="file:///test.swf"'
        -D_POSIX_C_SOURCE=200809L
        -I. -I"${SWFMODERN_INC}" -I"${SWFMODERN_INC}/actionmodern"
        -I"${SWFMODERN_INC}/libswf" -I"${SWFMODERN_INC}/memory"
        -I"${SWFMODERN_ROOT}/lib/c-hashmap"
        "${MODE_INCLUDES[@]}"
        -w -std=c17 -O2 -g -fno-omit-frame-pointer
    )

    CC=(gcc)
    if command -v ccache >/dev/null 2>&1; then CC=(ccache gcc); fi

    echo "Compiling (this can take ~1min cold for action.c)..."
    cd "${BUILD_DIR}"
    OBJS=()
    for src in *.c; do
        obj="${src%.c}.o"
        "${CC[@]}" -c "$src" "${COMMON_FLAGS[@]}" -o "$obj"
        OBJS+=("$obj")
    done
    gcc "${OBJS[@]}" -o "${OUTPUT_NAME}" "${MODE_LIBS[@]}"
    echo "✅ Built ${BUILD_DIR}/${OUTPUT_NAME}"
fi

if [ "$BUILD_ONLY" = true ]; then exit 0; fi

# ---------------------------------------------------------------------------
# Run.
# ---------------------------------------------------------------------------
cd "${BUILD_DIR}"
RUN_ARGS=()
[ -n "$INPUT_FILE" ] && RUN_ARGS+=("$INPUT_FILE")

if [ "$NO_CALLGRIND" = true ]; then
    echo "Running ${OUTPUT_NAME} (${MAX_FRAMES} frames, no profiler)..."
    /usr/bin/time -v "./${OUTPUT_NAME}" "${RUN_ARGS[@]}" >/dev/null 2>run_time.txt || true
    grep -E "Elapsed|Maximum resident" run_time.txt || cat run_time.txt
    exit 0
fi

echo "Running under callgrind (${MAX_FRAMES} frames; ~50x slower)..."
valgrind --tool=callgrind \
    --callgrind-out-file=callgrind.out \
    --dump-line=yes --collect-jumps=no \
    "./${OUTPUT_NAME}" "${RUN_ARGS[@]}" >callgrind_stdout.txt 2>callgrind_run.log || true

echo "Generating ranked report → callgrind.txt"
callgrind_annotate --threshold=98 --auto=no callgrind.out > callgrind.txt 2>/dev/null || \
    callgrind_annotate callgrind.out > callgrind.txt 2>/dev/null
echo "✅ Report: ${BUILD_DIR}/callgrind.txt"
echo ""
echo "=== Top self-cost functions ==="
sed -n '/Ir  *file:function/,/^$/p' callgrind.txt | head -40
