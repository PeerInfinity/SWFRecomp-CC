#!/bin/bash
# Build a browser-WASM (graphics / WebGPU) page from a regression fixture that
# loads a CHILD SWF, and serve-able output under $OUT_ROOT/<test>/.
#
# Why this exists: SWFRecomp/scripts/build_test.sh is the sanctioned
# browser-graphics demo path but has NO child-SWF support (it recompiles one
# `test.swf` and never defines HAS_CHILD_MOVIES), while verify_output.py knows
# how to recompile a parent plus every child with the right per-child
# `char_id_base` but only builds NO_GRAPHICS (`swf_core.c`) WASM. This script
# joins the two: verify_output.py's generated C + build_test.sh's
# `wasm --graphics` link recipe.
#
#   Usage: build_child_probe.sh <fixture-name> [tests-dir]
#   Env:   OUT_ROOT (default /tmp/swf_child_probe)
#
# See tools/browser-test/child_probe/README.md.
set -euo pipefail
TEST="$1"
TESTS_DIR="${2:-ruffle-tests/tests/swfs/regression}"
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
OUT_ROOT="${OUT_ROOT:-/tmp/swf_child_probe}"
RT="${ROOT}/SWFModernRuntime"; SRC="${RT}/src"; INC="${RT}/include"
GEN="${OUT_ROOT}/gen_${TEST}"; OUT="${OUT_ROOT}/web/${TEST}"

# 1. Generated C: the recompiler's output for the parent AND every child.
#    verify_output.py owns the child walk (find_child_swfs, the
#    child_movie_id * CHILD_CHAR_ID_STRIDE offset, the string-id rebasing), so
#    borrow it rather than reimplementing any of that here.
if [ ! -d "$GEN" ]; then
    mkdir -p "$GEN"
    SWF_KEEP_BUILD_DIR="$GEN" python3 "${ROOT}/ruffle-tests/verify_output.py" \
        --test="${TEST}" --tests-dir="${TESTS_DIR}" --recompile >/dev/null
fi

rm -rf "$OUT"; mkdir -p "$OUT/memory"
for f in constants.c constants.h data_registry.c draws.c draws.h \
         root_swf_bytes.c script_defs.c tagMain.c out.h script_decls.h; do
    [ -f "$GEN/$f" ] && cp "$GEN/$f" "$OUT/"
done
cp "$GEN"/script_*.c "$OUT/" 2>/dev/null || true
cp "$GEN"/movie_*.c  "$OUT/" 2>/dev/null || true   # movie_registry.c + movie_<child>.c

# 2. Graphics runtime source set — build_test.sh's `--graphics` list, plus the
#    image/video decoders the bundle build carries (a child can embed a bitmap).
cp "${SRC}"/actionmodern/{action.c,variables.c,object.c,math.c,date.c,timer.c,registered_class.c,avm1_amf.c,unicode_case_tables.h,action_queue.c,sprite_frame_scripts.c} "$OUT/"
cp "${SRC}"/{utils.c,amf_packet.c} "$OUT/"
cp "${SRC}"/libswf/{swf.c,tag.c,tag_stubs.c,ng_shared.c,hit_test.c,shape_hit_test.c,graphics_stubs.c} "$OUT/"
cp "${SRC}"/actionmodern/{image_decode.c,video_codec.c} "$OUT/"
cp "${SRC}"/libswf/stb_image_impl.c "$OUT/"; cp "${RT}"/lib/stb/stb_image.h "$OUT/"
cp "${SRC}"/rendering/render_webgpu.c "$OUT/"
cp "${SRC}"/audio/{audio.c,audio_output_web.c} "$OUT/"
cp "${SRC}"/memory/heap.c "$OUT/"; cp "${INC}"/memory/heap.h "$OUT/memory/"
cp "${RT}"/lib/c-hashmap/map.c "$OUT/"
cp "${RT}"/lib/o1heap/{o1heap.c,o1heap.h} "$OUT/"
cp "${RT}"/third_party/libtess2/*.c "${RT}"/third_party/libtess2/*.h "$OUT/"
# display_bridge.c brings dbgSetFrameCapMs + the dbgCapture* GPU readback, which
# run_child_probe.py needs: a short test movie is over before a Playwright
# screenshot can fire, and a DOM screenshot of the WebGPU canvas comes back
# blank under WSLg regardless.
cp "${ROOT}"/SWFRecomp/wasm_wrappers/{main.c,display_bridge.c} "$OUT/"
sed "s/{{TEST_NAME}}/${TEST}/g" \
    "${ROOT}/SWFRecomp/wasm_wrappers/index_template_graphics.html" > "$OUT/index.html"

# 3. Link. Flags are build_test.sh's graphics-wasm recipe plus the defines
#    verify_output.py passes and build_test.sh does not. HAS_CHILD_MOVIES is
#    the load-bearing one: without it swf.c compiles NULL-returning stubs for
#    findMovieEntry/getMovieEntryAt and the generated movie_registry.c collides
#    with them at link time.
source "${ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1
cd "$OUT"
SWF_SIZE=$(python3 -c "import struct,sys;print(struct.unpack('<I',open(sys.argv[1],'rb').read(8)[4:8])[0])" \
           "${ROOT}/${TESTS_DIR}/${TEST}/test.swf")
# HAS_CHILD_MOVIES only when the child walk actually emitted a registry: a
# childless fixture (a plain root-side probe) generates no movie_registry.c, and
# defining it anyway leaves findMovieEntry/getMovieEntryAt undefined at link.
EXTRA="-DHAS_DISPLAY_BRIDGE -DMOCK_DATE_TIME=981152406000LL"
[ -f "$OUT/movie_registry.c" ] && EXTRA="-DHAS_CHILD_MOVIES $EXTRA"
EXTRA="$EXTRA -DSWF_FILE_SIZE=${SWF_SIZE} -DSWF_ONDISK_SIZE=${SWF_SIZE} -DSWF_URL=\"file:///test.swf\""
[ -f "$OUT/data_registry.c" ] && EXTRA="$EXTRA -DHAS_DATA_FILES"
emcc *.c -DUSE_WEBGPU ${EXTRA} --use-port=emdawnwebgpu \
    -Wno-error=implicit-function-declaration \
    -I. -I"${INC}" -I"${INC}/actionmodern" -I"${INC}/libswf" -I"${INC}/memory" \
    -I"${INC}/rendering" -I"${INC}/audio" -I"${RT}/lib/c-hashmap" \
    -o "${TEST}.js" \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS='["_main","_runSWF","_audio_fill_buffer","_getDisplayListJSON","_getSpriteChildrenJSON","_setObjectTransform","_dbgCapturePNG","_dbgCaptureReady","_dbgCaptureData","_dbgCaptureWidth","_dbgCaptureHeight","_dbgSetFrameCapMs","_swf_ei_call_internal","_ng_ime_compose_set","_ng_ime_commit_set"]' \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPF32","HEAPU8"]' \
    -s ALLOW_MEMORY_GROWTH=1 -s INITIAL_MEMORY=256MB -s STACK_SIZE=8MB \
    -sASYNCIFY -sASYNCIFY_STACK_SIZE=65536 -sUSE_ZLIB=1 -O2
echo "BUILT ${OUT}/${TEST}.js"
