#!/bin/bash
# build_native_browser_arm_asan.sh — compile the BROWSER-WASM graphics arm
# (!NO_GRAPHICS && !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS) natively with
# ASAN + HEAP_PASSTHROUGH, using render_stub.c instead of a real GPU.
#
# Why: the dlmalloc-corruption hang only reproduces in the browser-only code
# paths, which native ASAN (OFFSCREEN_RENDER) never compiles, and which
# o1heap hides from sanitizers. This harness makes every HALLOC/FREE a real
# malloc/free so ASAN pins the UAF/double-free with full stacks.
#
# Usage: ./build_native_browser_arm_asan.sh [test_name]
#   test_name defaults to flasharchive/Doodle_Jump_loader
#   (run the recompiler on the test's test.swf beforehand)
# Output: <test_dir>/build/native_browser_asan/<basename>
#
# GUARD=1: instead of ASAN+HEAP_PASSTHROUGH, build with the REAL o1heap and
# link-time --wrap=free/--wrap=realloc provenance guards (alloc_guard.c) that
# abort with a backtrace on any system free/realloc of an o1heap arena
# pointer — the cross-allocator class that passthrough mode masks.
# Output goes to build/native_browser_guard/ instead.
set -e

TEST_NAME=${1:-flasharchive/Doodle_Jump_loader}
SWFRECOMP_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../../../../../SWFRecomp" && pwd)"
SWFMODERN_ROOT="${SWFRECOMP_ROOT}/../SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"
TEST_DIR="${SWFRECOMP_ROOT}/tests/${TEST_NAME}"
HARNESS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
if [ "${GUARD:-0}" = "1" ]; then
    BUILD_DIR="${TEST_DIR}/build/native_browser_guard"
    # No -rdynamic: it would defeat -Wl,--gc-sections (which this build needs
    # to drop the NO_GRAPHICS-only goto-catchup refs, mirroring the wasm link).
    # Resolve guard backtraces with addr2line -e <binary> <addr> instead.
    SAN_FLAGS="-Wl,--wrap=free -Wl,--wrap=realloc"
else
    BUILD_DIR="${TEST_DIR}/build/native_browser_asan"
    SAN_FLAGS="-fsanitize=address -DHEAP_PASSTHROUGH"
fi
OUTPUT_NAME="$(basename "$TEST_NAME")"
DAWN_INSTALL="${DAWN_INSTALL:-$HOME/CC/dawn-install}"

[ -d "$TEST_DIR/RecompiledScripts" ] || { echo "Run the recompiler first ($TEST_DIR/RecompiledScripts missing)"; exit 1; }
[ -f "$DAWN_INSTALL/include/webgpu/webgpu.h" ] || { echo "webgpu.h not found at $DAWN_INSTALL/include"; exit 1; }

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

cp "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "$BUILD_DIR/"

# Same file set as build_test.sh's wasm --graphics branch, but native, with
# render_stub.c replacing render_webgpu.c and no audio_output_web EM_JS arm
# (audio_output_web.c has a native no-op fallback).
for f in actionmodern/action.c actionmodern/variables.c actionmodern/object.c \
         actionmodern/math.c actionmodern/date.c actionmodern/timer.c \
         actionmodern/registered_class.c actionmodern/action_queue.c \
         actionmodern/sprite_frame_scripts.c actionmodern/unicode_case_tables.h \
         utils.c \
         actionmodern/image_decode.c actionmodern/video_codec.c \
         libswf/swf.c libswf/tag.c libswf/tag_stubs.c libswf/ng_shared.c \
         libswf/hit_test.c libswf/shape_hit_test.c libswf/graphics_stubs.c \
         libswf/stb_image_impl.c \
         rendering/render_stub.c \
         audio/audio.c audio/audio_output_web.c; do
    cp "${SWFMODERN_SRC}/${f}" "$BUILD_DIR/"
done

cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "$BUILD_DIR/"
cp "${SWFMODERN_ROOT}/third_party/libtess2"/*.c "$BUILD_DIR/" 2>/dev/null || true
cp "${SWFMODERN_ROOT}/third_party/libtess2"/*.h "$BUILD_DIR/" 2>/dev/null || true
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "$BUILD_DIR/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "$BUILD_DIR/"
cp "${SWFMODERN_SRC}/memory/heap.c" "$BUILD_DIR/"
mkdir -p "$BUILD_DIR/memory"
cp "${SWFMODERN_INC}/memory/heap.h" "$BUILD_DIR/memory/"

if [ "${GUARD:-0}" = "1" ]; then
    cp "${HARNESS_DIR}/alloc_guard.c" "$BUILD_DIR/"
fi

cp "${TEST_DIR}/RecompiledScripts"/*.c "$BUILD_DIR/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledScripts"/*.h "$BUILD_DIR/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.c "$BUILD_DIR/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.h "$BUILD_DIR/" 2>/dev/null || true

cd "$BUILD_DIR"

gcc *.c \
    -DUSE_WEBGPU \
    ${SAN_FLAGS} \
    -D_POSIX_C_SOURCE=200809L \
    -fno-omit-frame-pointer \
    -g -O1 \
    -Wno-error=implicit-function-declaration \
    -I. \
    -I"${SWFMODERN_INC}" \
    -I"${SWFMODERN_INC}/actionmodern" \
    -I"${SWFMODERN_INC}/libswf" \
    -I"${SWFMODERN_INC}/memory" \
    -I"${SWFMODERN_INC}/rendering" \
    -I"${SWFMODERN_INC}/audio" \
    -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
    -I"${SWFMODERN_ROOT}/lib/stb" \
    -I"${DAWN_INSTALL}/include" \
    -std=gnu17 \
    -ffunction-sections -fdata-sections -Wl,--gc-sections \
    -o "$OUTPUT_NAME" \
    -lm

echo ""
echo "OK: $BUILD_DIR/$OUTPUT_NAME"
echo "Run: ASAN_OPTIONS=abort_on_error=1 timeout 120 $BUILD_DIR/$OUTPUT_NAME"
