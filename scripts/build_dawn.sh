#!/bin/bash
# Build a minimal Dawn (WebGPU) install for offscreen rendering.
#
# Used by:
#   - .github/workflows/build-dawn.yml (CI cache producer)
#   - Local dev (run once, install to ~/CC/dawn-install)
#
# Usage:
#   scripts/build_dawn.sh <install-prefix>
# Example:
#   scripts/build_dawn.sh ~/CC/dawn-install
#
# Output: libwebgpu_dawn.a + include/{dawn,webgpu}/ headers under <install-prefix>.
# Roughly 88 MB total. ~30 minutes on a fresh GitHub Actions runner.
#
# If your local Dawn install was built with different flags or against a
# different version, edit DAWN_REF below (and bump CACHE_SCHEMA in the
# build-dawn.yml workflow if you want CI to rebuild rather than use a stale
# cache hit).

set -euo pipefail

# Pinned Dawn commit. This SHA matches what was built locally for
# ~/CC/dawn-install on 2026-03-07 (from main: "Remove stale WebGPU Compat
# CTS expectations"). The renderer code in SWFModernRuntime/src/rendering/
# was tested against this version. Bump only when intentionally upgrading
# Dawn — changing this value invalidates the CI cache.
DAWN_REF="620a520f5029e14b57a0b58096c022e339b1857b"

INSTALL_PREFIX="${1:?Usage: $0 <install-prefix>}"
INSTALL_PREFIX="$(realpath -m "$INSTALL_PREFIX")"

WORK_DIR="$(mktemp -d)"
trap 'rm -rf "$WORK_DIR"' EXIT

echo "=== Building Dawn ($DAWN_REF) → $INSTALL_PREFIX ==="

# Shallow fetch by commit SHA. `git clone --branch` doesn't accept arbitrary
# SHAs, so we init + fetch + checkout instead.
cd "$WORK_DIR"
mkdir dawn-src
cd dawn-src
git init -q
git remote add origin https://dawn.googlesource.com/dawn
git fetch --depth 1 origin "$DAWN_REF"
git checkout -q FETCH_HEAD

# Dawn's dependency fetcher (replaces the older `gclient sync` flow).
python3 tools/fetch_dawn_dependencies.py

mkdir -p build
cd build

# Static library, no GUI deps (no GLFW / X11 / Wayland).
# DAWN_USE_BUILT_DXC is needed on Windows but a no-op on Linux.
cmake .. -GNinja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$INSTALL_PREFIX" \
    -DDAWN_BUILD_SAMPLES=OFF \
    -DDAWN_USE_GLFW=OFF \
    -DDAWN_USE_X11=OFF \
    -DDAWN_USE_WAYLAND=OFF \
    -DTINT_BUILD_SAMPLES=OFF \
    -DTINT_BUILD_DOCS=OFF \
    -DTINT_BUILD_TESTS=OFF \
    -DBUILD_SHARED_LIBS=OFF

ninja -j"$(nproc)" install

# Sanity-check the install layout matches what verify_output.py expects.
test -f "$INSTALL_PREFIX/lib/libwebgpu_dawn.a" \
    || { echo "ERROR: libwebgpu_dawn.a not produced — check Dawn build output" >&2; exit 1; }

echo "=== Done. Install at: $INSTALL_PREFIX ==="
ls -la "$INSTALL_PREFIX/lib/" | head -20
