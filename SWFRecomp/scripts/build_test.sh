#!/bin/bash
# Usage: ./scripts/build_test.sh <test_name> [native|wasm] [--clean] [--graphics]
# Example: ./scripts/build_test.sh trace_swf_4 wasm
# Example: ./scripts/build_test.sh trace_swf_4 native --clean
# Example: ./scripts/build_test.sh graphics/three_boxes wasm --graphics

set -e

# Parse arguments
TEST_NAME=$1
TARGET=${2:-wasm}              # Default: wasm
CLEAN_FLAG=false
GRAPHICS_FLAG=false

# Check for flags in any position
for arg in "$@"; do
    if [ "$arg" = "--clean" ]; then
        CLEAN_FLAG=true
    fi
    if [ "$arg" = "--graphics" ]; then
        GRAPHICS_FLAG=true
    fi
done

# If TARGET is a flag, set it to default and enable the flag
if [ "$TARGET" = "--clean" ]; then
    TARGET="wasm"
    CLEAN_FLAG=true
elif [ "$TARGET" = "--graphics" ]; then
    TARGET="wasm"
    GRAPHICS_FLAG=true
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
    "${SWFRECOMP_ROOT}/build/SWFRecomp" config.toml
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
    # Copy HTML template for WASM builds
    if [ "$GRAPHICS_FLAG" = true ]; then
        cp "${SWFRECOMP_ROOT}/wasm_wrappers/index_template_graphics.html" "${BUILD_DIR}/index.html"
    else
        cp "${SWFRECOMP_ROOT}/wasm_wrappers/index_template.html" "${BUILD_DIR}/index.html"
    fi
    # Customize HTML with output name (basename, no path separators)
    sed -i "s/{{TEST_NAME}}/${OUTPUT_NAME}/g" "${BUILD_DIR}/index.html"
fi

# Copy SWFModernRuntime source files
echo "Copying SWFModernRuntime sources..."
cp "${SWFMODERN_SRC}/actionmodern/action.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/variables.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/object.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/utils.c" "${BUILD_DIR}/"

if [ "$GRAPHICS_FLAG" = true ]; then
    echo "Using GRAPHICS mode (WebGPU) for ${TARGET} build..."
    cp "${SWFMODERN_SRC}/libswf/swf.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/rendering/render_webgpu.c" "${BUILD_DIR}/"
else
    echo "Using NO_GRAPHICS mode for ${TARGET} build..."
    cp "${SWFMODERN_SRC}/libswf/swf_core.c" "${BUILD_DIR}/"
    cp "${SWFMODERN_SRC}/libswf/tag_stubs.c" "${BUILD_DIR}/"
fi

# Copy hashmap library (required for variable storage)
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${BUILD_DIR}/"

# Copy o1heap library (required for memory management)
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${BUILD_DIR}/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${BUILD_DIR}/"

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

# Build
if [ "$TARGET" == "wasm" ]; then
    echo "Building WASM with SWFModernRuntime..."

    # Check if emcc is available
    if ! command -v emcc &> /dev/null; then
        echo "Error: Emscripten (emcc) not found!"
        echo "Run: source ~/tools/emsdk/emsdk_env.sh"
        exit 1
    fi

    cd "${BUILD_DIR}"

    if [ "$GRAPHICS_FLAG" = true ]; then
        emcc \
            *.c \
            -DUSE_WEBGPU \
            --use-port=emdawnwebgpu \
            -I. \
            -I"${SWFMODERN_INC}" \
            -I"${SWFMODERN_INC}/actionmodern" \
            -I"${SWFMODERN_INC}/libswf" \
            -I"${SWFMODERN_INC}/memory" \
            -I"${SWFMODERN_INC}/rendering" \
            -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
            -o "${OUTPUT_NAME}.js" \
            -s WASM=1 \
            -s EXPORTED_FUNCTIONS='["_main","_runSWF"]' \
            -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
            -s ALLOW_MEMORY_GROWTH=1 \
            -s INITIAL_MEMORY=64MB \
            -sASYNCIFY \
            -sASYNCIFY_STACK_SIZE=65536 \
            -O2
    else
        emcc \
            *.c \
            -DNO_GRAPHICS \
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
    if [ "$GRAPHICS_FLAG" = true ]; then
        NATIVE_GRAPHICS_FLAGS="-DUSE_WEBGPU -I${SWFMODERN_INC}/rendering"
    else
        NATIVE_GRAPHICS_FLAGS="-DNO_GRAPHICS"
    fi

    gcc \
        *.c \
        $NATIVE_GRAPHICS_FLAGS \
        -D_POSIX_C_SOURCE=199309L \
        -I. \
        -I"${SWFMODERN_INC}" \
        -I"${SWFMODERN_INC}/actionmodern" \
        -I"${SWFMODERN_INC}/libswf" \
        -I"${SWFMODERN_INC}/memory" \
        -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
        -Wall \
        -Wno-unused-variable \
        -std=c17 \
        -o "${OUTPUT_NAME}" \
        -lm

    echo ""
    echo "✅ Native build complete!"
    echo "Output: ${BUILD_DIR}/${OUTPUT_NAME}"
    echo ""
    echo "To run:"
    echo "  ${BUILD_DIR}/${TEST_NAME}"
fi
