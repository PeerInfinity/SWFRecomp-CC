#!/bin/bash
# Usage: ./scripts/build_test.sh <test_name> [native|wasm] [--clean] [--graphics] [--headless]
# Example: ./scripts/build_test.sh trace_swf_4 wasm
# Example: ./scripts/build_test.sh trace_swf_4 native --clean
# Example: ./scripts/build_test.sh graphics/three_boxes wasm --graphics
# Example: ./scripts/build_test.sh trace_swf_4 native --headless

set -e

# Parse arguments
TEST_NAME=$1
TARGET=${2:-wasm}              # Default: wasm
CLEAN_FLAG=false
GRAPHICS_FLAG=false
HEADLESS_FLAG=false

# Check for flags in any position
for arg in "$@"; do
    if [ "$arg" = "--clean" ]; then
        CLEAN_FLAG=true
    fi
    if [ "$arg" = "--graphics" ]; then
        GRAPHICS_FLAG=true
    fi
    if [ "$arg" = "--headless" ]; then
        HEADLESS_FLAG=true
    fi
done

# If TARGET is a flag, set it to default and enable the flag
if [ "$TARGET" = "--clean" ]; then
    TARGET="wasm"
    CLEAN_FLAG=true
elif [ "$TARGET" = "--graphics" ]; then
    TARGET="wasm"
    GRAPHICS_FLAG=true
elif [ "$TARGET" = "--headless" ]; then
    TARGET="native"
    HEADLESS_FLAG=true
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
TEST_DIR="${SWFRECOMP_ROOT}/tests/${TEST_NAME}"
BUILD_DIR="${TEST_DIR}/build/${TARGET}"
# Use basename for output filenames (handles paths like graphics/three_boxes)
OUTPUT_NAME="$(basename "$TEST_NAME")"

# Validate inputs
if [ -z "$TEST_NAME" ]; then
    echo "Error: Test name required"
    echo "Usage: $0 <test_name> [native|wasm] [--clean]"
    exit 1
fi

if [ ! -d "$TEST_DIR" ]; then
    echo "Error: Test directory not found: $TEST_DIR"
    exit 1
fi

# Regenerate test.swf if --clean is set and generation script exists
if [ "$CLEAN_FLAG" = true ]; then
    echo "Clean mode: checking for SWF generation script..."

    # Look for common SWF generation script names
    for script in create_test_swf.py generate_swf.py make_test.py create_swf.py; do
        if [ -f "${TEST_DIR}/${script}" ]; then
            echo "Found ${script}, regenerating test.swf..."
            cd "${TEST_DIR}"
            python3 "${script}"
            if [ -f "test.swf" ]; then
                echo "✅ test.swf regenerated successfully"
                break
            else
                echo "⚠️  Warning: ${script} ran but test.swf was not created"
            fi
        fi
    done
fi

# Generate test.swf if it doesn't exist
if [ ! -f "${TEST_DIR}/test.swf" ]; then
    echo "test.swf not found, checking for generation script..."

    # Look for common SWF generation script names
    for script in create_test_swf.py generate_swf.py make_test.py create_swf.py; do
        if [ -f "${TEST_DIR}/${script}" ]; then
            echo "Found ${script}, generating test.swf..."
            cd "${TEST_DIR}"
            python3 "${script}"
            if [ -f "test.swf" ]; then
                echo "✅ test.swf generated successfully"
                break
            else
                echo "⚠️  Warning: ${script} ran but test.swf was not created"
            fi
        fi
    done

    # Final check
    if [ ! -f "${TEST_DIR}/test.swf" ]; then
        echo "Error: test.swf not found and no generation script available"
        echo "Expected either:"
        echo "  - ${TEST_DIR}/test.swf (SWF file)"
        echo "  - ${TEST_DIR}/create_test_swf.py (generation script)"
        exit 1
    fi
fi

# Clean generated files if --clean flag is set
if [ "$CLEAN_FLAG" = true ]; then
    echo "Cleaning generated files..."
    rm -rf "${TEST_DIR}/RecompiledScripts"
    rm -rf "${TEST_DIR}/RecompiledTags"
fi

# Run SWFRecomp if needed
if [ ! -d "${TEST_DIR}/RecompiledScripts" ]; then
    echo "Running SWFRecomp..."
    cd "${TEST_DIR}"
    # Run with memory limit (4GB) to prevent runaway recompilation from crashing WSL.
    # Stack unlimited because interpretShape's johnson cycle walker is recursive
    # and SWFs with very deep paths (e.g. Duck Life 3) blow the default 8 MB stack.
    bash -c 'ulimit -v 4194304; ulimit -s unlimited; exec "$@"' -- "${SWFRECOMP_ROOT}/build/SWFRecomp" config.toml
fi

# Setup build directory
echo "Setting up build directory..."
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"

# Setup paths to SWFModernRuntime (sibling directory)
SWFMODERN_ROOT="${SWFRECOMP_ROOT}/../SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"

# Verify SWFModernRuntime exists
if [ ! -d "$SWFMODERN_ROOT" ]; then
    echo "Error: SWFModernRuntime not found at: $SWFMODERN_ROOT"
    echo "Expected directory structure:"
    echo "  /path/to/projects/SWFRecomp/"
    echo "  /path/to/projects/SWFModernRuntime/"
    exit 1
fi

# Copy main.c wrapper (works for both WASM and native NO_GRAPHICS builds)
cp "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "${BUILD_DIR}/"

if [ "$TARGET" == "wasm" ]; then
    # Generate redirect stub that points to the dynamic demo page
    # Relative path depends on nesting depth: trace = ../../, graphics = ../../../
    if [ "$GRAPHICS_FLAG" = true ]; then
        DEMO_REL="../../../demo.html?test=${TEST_NAME}"
    else
        DEMO_REL="../../demo.html?test=${TEST_NAME}"
    fi
    cat > "${BUILD_DIR}/index.html" <<REDIRECT_EOF
<!DOCTYPE html>
<html><head>
<meta http-equiv="refresh" content="0;url=${DEMO_REL}">
<script>window.location.replace('${DEMO_REL}');</script>
</head><body>Redirecting...</body></html>
REDIRECT_EOF
fi

# Copy SWFModernRuntime source files
echo "Copying SWFModernRuntime sources..."
cp "${SWFMODERN_SRC}/actionmodern/action.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/variables.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/object.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/math.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/date.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/timer.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/registered_class.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/utils.c" "${BUILD_DIR}/"

# Archipelago Rando class (opt-in via WITH_AP=1). rando.c is a no-op stub
# unless compiled with -DWITH_AP. The backend impl differs by target:
#   native → rando_ap.cpp     (C++ shim over APCpp; g++-compiled in the link step)
#   wasm   → rando_ap_wasm.c  (EM_JS → archipelago.js; compiled by emcc *.c)
# Exactly one is copied so the rando_ap.h symbols aren't doubly defined. See
# SWFRecompDocs/plans/archipelago-randomizer-integration.md (+ phase2 doc).
if [ "${WITH_AP:-}" = "1" ] || [ "${WITH_AP:-}" = "true" ]; then
    cp "${SWFMODERN_SRC}/actionmodern/rando.c" "${BUILD_DIR}/"
    if [ "$TARGET" == "wasm" ]; then
        cp "${SWFMODERN_SRC}/actionmodern/rando_ap_wasm.c" "${BUILD_DIR}/"
    else
        cp "${SWFMODERN_SRC}/actionmodern/rando_ap.cpp" "${BUILD_DIR}/"
    fi
fi

if [ "$HEADLESS_FLAG" = true ]; then
    echo "Using HEADLESS_GRAPHICS mode (offscreen WebGPU + trace) for ${TARGET} build..."
    cp "${SWFMODERN_SRC}/libswf/swf_headless.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag_stubs.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/shape_hit_test.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/ng_shared.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/hit_test.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/rendering/render_webgpu.c" "${BUILD_DIR}/"
elif [ "$GRAPHICS_FLAG" = true ]; then
    echo "Using GRAPHICS mode (WebGPU) for ${TARGET} build..."
    cp "${SWFMODERN_SRC}/actionmodern/action_queue.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/actionmodern/sprite_frame_scripts.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/swf.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag_stubs.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/ng_shared.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/hit_test.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/shape_hit_test.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/graphics_stubs.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/rendering/render_webgpu.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/audio/audio.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/audio/audio_output_web.c" "${BUILD_DIR}/"
else
    echo "Using NO_GRAPHICS mode for ${TARGET} build..."
    cp "${SWFMODERN_SRC}/libswf/swf_core.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag_stubs.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/shape_hit_test.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/ng_shared.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/hit_test.c" "${BUILD_DIR}/"
fi

# Copy hashmap library (required for variable storage)
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${BUILD_DIR}/"

# Copy o1heap library (required for memory management)
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${BUILD_DIR}/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${BUILD_DIR}/"

# Copy libtess2 tessellation library (required by action.c)
LIBTESS2_DIR="${SWFMODERN_ROOT}/third_party/libtess2"
if [ -d "${LIBTESS2_DIR}" ]; then
    cp "${LIBTESS2_DIR}"/*.c "${BUILD_DIR}/" 2>/dev/null || true
    cp "${LIBTESS2_DIR}"/*.h "${BUILD_DIR}/" 2>/dev/null || true
fi

# Copy heap memory manager
cp "${SWFMODERN_SRC}/memory/heap.c" "${BUILD_DIR}/"
mkdir -p "${BUILD_DIR}/memory"
cp "${SWFMODERN_INC}/memory/heap.h" "${BUILD_DIR}/memory/"

# Copy generated files from SWFRecomp
echo "Copying generated files..."
cp "${TEST_DIR}/RecompiledScripts"/*.c "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledScripts"/*.h "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.c "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.h "${BUILD_DIR}/" 2>/dev/null || true

# Copy test harness if present (per-test custom C code)
EXTRA_DEFINES=""
if [ -f "${TEST_DIR}/test_harness.c" ]; then
    cp "${TEST_DIR}/test_harness.c" "${BUILD_DIR}/"
    EXTRA_DEFINES="-DHAS_TEST_HARNESS"
    echo "Found test_harness.c"
fi

# Archipelago (WITH_AP): define WITH_AP for both targets; for wasm, stage the
# JS bridge + vendored archipelago.js next to the build output so the demo page
# can load them. See SWFRecompDocs/plans/archipelago-phase2-wasm-bridge.md.
if [ "${WITH_AP:-}" = "1" ] || [ "${WITH_AP:-}" = "true" ]; then
    EXTRA_DEFINES="${EXTRA_DEFINES} -DWITH_AP"
    if [ "$TARGET" == "wasm" ]; then
        cp "${SWFRECOMP_ROOT}/wasm_wrappers/rando/archipelago.js" "${BUILD_DIR}/"
        cp "${SWFRECOMP_ROOT}/wasm_wrappers/rando/rando_bridge.js" "${BUILD_DIR}/"
    fi
fi

# Copy display bridge if present in test dir or wasm_wrappers
DISPLAY_BRIDGE=false
if [ -f "${TEST_DIR}/display_bridge.c" ]; then
    cp "${TEST_DIR}/display_bridge.c" "${BUILD_DIR}/"
    EXTRA_DEFINES="${EXTRA_DEFINES} -DHAS_DISPLAY_BRIDGE"
    DISPLAY_BRIDGE=true
    echo "Found display_bridge.c (test dir)"
elif [ -f "${SWFRECOMP_ROOT}/wasm_wrappers/display_bridge.c" ]; then
    cp "${SWFRECOMP_ROOT}/wasm_wrappers/display_bridge.c" "${BUILD_DIR}/"
    EXTRA_DEFINES="${EXTRA_DEFINES} -DHAS_DISPLAY_BRIDGE"
    DISPLAY_BRIDGE=true
    echo "Found display_bridge.c (wasm_wrappers)"
fi

# Build
if [ "$TARGET" == "wasm" ]; then
    echo "Building WASM with SWFModernRuntime..."

    # Check if emcc is available
    if ! command -v emcc &> /dev/null; then
        echo "Error: Emscripten (emcc) not found!"
        echo "Run: source scripts/setup_build_env.sh"
        echo "  or: source emsdk/emsdk_env.sh"
        exit 1
    fi

    cd "${BUILD_DIR}"

    # Build exported functions list
    # ng_ime_compose_set / ng_ime_commit_set are called from JS-side
    # composition listeners registered by ng_register_ime_listeners.
    EXPORTED_FUNCS='["_main","_runSWF","_audio_fill_buffer","_ng_ime_compose_set","_ng_ime_commit_set"]'
    if [ "$DISPLAY_BRIDGE" = true ]; then
        EXPORTED_FUNCS='["_main","_runSWF","_audio_fill_buffer","_getDisplayListJSON","_getSpriteChildrenJSON","_setObjectTransform","_ng_ime_compose_set","_ng_ime_commit_set"]'
    fi

    if [ "$GRAPHICS_FLAG" = true ]; then
        emcc \
            *.c \
            -DUSE_WEBGPU \
            ${EXTRA_DEFINES} \
            --use-port=emdawnwebgpu \
            -Wno-error=implicit-function-declaration \
            -I. \
            -I"${SWFMODERN_INC}" \
            -I"${SWFMODERN_INC}/actionmodern" \
            -I"${SWFMODERN_INC}/libswf" \
            -I"${SWFMODERN_INC}/memory" \
            -I"${SWFMODERN_INC}/rendering" \
            -I"${SWFMODERN_INC}/audio" \
            -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
            -o "${OUTPUT_NAME}.js" \
            -s WASM=1 \
            -s EXPORTED_FUNCTIONS="${EXPORTED_FUNCS}" \
            -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPF32"]' \
            -s ALLOW_MEMORY_GROWTH=1 \
            -s INITIAL_MEMORY=256MB \
            -sASYNCIFY \
            -sASYNCIFY_STACK_SIZE=65536 \
            -O2
    else
        emcc \
            *.c \
            -DNO_GRAPHICS \
            ${EXTRA_DEFINES} \
            -I. \
            -I"${SWFMODERN_INC}" \
            -I"${SWFMODERN_INC}/actionmodern" \
            -I"${SWFMODERN_INC}/libswf" \
            -I"${SWFMODERN_INC}/memory" \
            -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
            -o "${OUTPUT_NAME}.js" \
            -s WASM=1 \
            -s EXPORTED_FUNCTIONS='["_main","_runSWF"]' \
            -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
            -s ALLOW_MEMORY_GROWTH=1 \
            -s INITIAL_MEMORY=16MB \
            -O2
    fi

    echo ""
    echo "✅ WASM build complete!"
    echo "Output: ${BUILD_DIR}/${OUTPUT_NAME}.wasm"
    echo ""
    echo "To test:"
    echo "  cd ${BUILD_DIR}"
    echo "  python3 -m http.server 8000"
    echo "  Open http://localhost:8000/index.html"

else
    echo "Building native with SWFModernRuntime..."
    cd "${BUILD_DIR}"

    NATIVE_GRAPHICS_FLAGS=""
    NATIVE_EXTRA_INCLUDES=""
    NATIVE_EXTRA_LIBS=""
    if [ "$HEADLESS_FLAG" = true ]; then
        DAWN_INSTALL="${SWFRECOMP_ROOT}/../../dawn-install"
        if [ ! -f "${DAWN_INSTALL}/lib/libwebgpu_dawn.a" ]; then
            echo "Error: Dawn not found at ${DAWN_INSTALL}"
            echo "Build Dawn first: see SWFModernRuntime/CMakeLists.txt comments"
            exit 1
        fi
        NATIVE_GRAPHICS_FLAGS="-DNO_GRAPHICS -DHEADLESS_GRAPHICS -DUSE_WEBGPU"
        NATIVE_EXTRA_INCLUDES="-I${SWFMODERN_INC}/rendering -I${SWFRECOMP_ROOT}/lib/stb -I${DAWN_INSTALL}/include"
        NATIVE_EXTRA_LIBS="${DAWN_INSTALL}/lib/libwebgpu_dawn.a -lstdc++ -lpthread -ldl"
    elif [ "$GRAPHICS_FLAG" = true ]; then
        NATIVE_GRAPHICS_FLAGS="-DUSE_WEBGPU -I${SWFMODERN_INC}/rendering -I${SWFMODERN_INC}/audio"
    else
        NATIVE_GRAPHICS_FLAGS="-DNO_GRAPHICS"
    fi

    # Archipelago (opt-in via WITH_AP=1): pre-compile the C++ shim with g++ and
    # link the prebuilt APCpp static libs. See the archipelago plan doc.
    AP_OBJS=""
    if [ "${WITH_AP:-}" = "1" ] || [ "${WITH_AP:-}" = "true" ]; then
        AP_ROOT="${AP_ROOT:-$HOME/CC/APCpp}"
        AP_BUILD="${AP_ROOT}/build"
        if [ ! -f "${AP_BUILD}/libAPCpp-static.a" ]; then
            echo "Error: APCpp not built at ${AP_BUILD}"
            echo "Build it: cmake -S ${AP_ROOT} -B ${AP_BUILD} -DCMAKE_BUILD_TYPE=Release && cmake --build ${AP_BUILD} -j"
            exit 1
        fi
        echo "Compiling APCpp shim (rando_ap.cpp) with g++..."
        g++ -c rando_ap.cpp \
            -std=c++11 -DWITH_AP \
            -I"${AP_ROOT}" \
            -I"${AP_ROOT}/jsoncpp/include" \
            -I"${SWFMODERN_INC}" \
            -I"${SWFMODERN_INC}/actionmodern" \
            -I"${SWFMODERN_INC}/memory" \
            -o rando_ap.o
        AP_OBJS="rando_ap.o"
        NATIVE_GRAPHICS_FLAGS="$NATIVE_GRAPHICS_FLAGS -DWITH_AP -I${AP_ROOT}"
        NATIVE_EXTRA_LIBS="$NATIVE_EXTRA_LIBS \
            ${AP_BUILD}/libAPCpp-static.a \
            ${AP_BUILD}/IXWebSocket/libixwebsocket.a \
            ${AP_BUILD}/lib/libjsoncpp.a \
            -lz -lssl -lcrypto -lpthread -lstdc++"
    fi

    gcc \
        *.c $AP_OBJS \
        $NATIVE_GRAPHICS_FLAGS \
        -D_POSIX_C_SOURCE=199309L \
        -I. \
        -I"${SWFMODERN_INC}" \
        -I"${SWFMODERN_INC}/actionmodern" \
        -I"${SWFMODERN_INC}/libswf" \
        -I"${SWFMODERN_INC}/memory" \
        -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
        $NATIVE_EXTRA_INCLUDES \
        -Wall \
        -Wno-unused-variable \
        -std=c17 \
        -o "${OUTPUT_NAME}" \
        -lm $NATIVE_EXTRA_LIBS

    echo ""
    echo "✅ Native build complete!"
    echo "Output: ${BUILD_DIR}/${OUTPUT_NAME}"
    echo ""
    echo "To run:"
    echo "  ${BUILD_DIR}/${TEST_NAME}"
fi
