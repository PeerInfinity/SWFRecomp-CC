#!/bin/bash
# SWFRecomp-CC cloud environment setup script.
# Source of truth for the "SWFRecomp fan-out" Claude Code cloud environment:
# paste into claude.ai/code → cloud icon → environment → "Setup script"
# whenever this file changes (the environment does not read it from the repo).
# Runs as root on Ubuntu 24.04 before Claude starts; result is cached.
# Needs network access "Trusted" or wider (Ubuntu archive, PyPI, GitHub).
#
# Installs what verify_output.py needs for no-graphics AND --mode=graphics
# runs, plus the prebuilt Dawn (WebGPU) that graphics mode links against.
# Always exits 0 so a failed optional step never breaks the environment;
# read /root/CC/SETUP_STATUS to see what succeeded.

set -u
DEST_ROOT="${SWF_SETUP_DEST_ROOT:-$HOME/CC}"
STATUS="$DEST_ROOT/SETUP_STATUS"
mkdir -p "$DEST_ROOT"
: > "$STATUS"
log() { echo "[swf-setup] $*"; echo "$*" >> "$STATUS"; }

# --- 1. apt packages -------------------------------------------------------
# build tools + ccache (per-test compiles), Vulkan/lavapipe + ffmpeg dev libs
# (graphics mode; same set as .github/actions/graphics-apt-deps).
PKGS="build-essential cmake ccache mesa-vulkan-drivers libvulkan1 vulkan-tools libavcodec-dev libavutil-dev libswscale-dev"
export DEBIAN_FRONTEND=noninteractive
# Some preinstalled PPAs 403 behind the proxy; that only produces warnings.
timeout 300 apt-get update -qq -o Acquire::Retries=3 >/dev/null 2>&1 || true
if timeout 600 apt-get install -y -qq $PKGS >/dev/null 2>&1; then
  log "apt: OK ($PKGS)"
else
  log "apt: FAILED"
fi

# --- 2. Python deps (image comparisons) ------------------------------------
if timeout 180 python3 -m pip install -q Pillow >/dev/null 2>&1; then
  log "pip Pillow: OK"
else
  log "pip Pillow: FAILED"
fi

# --- 3. Prebuilt Dawn -------------------------------------------------------
# Built from DAWN_REF in SWFRecomp-CC scripts/build_dawn.sh. Update URL + SHA
# together when that pin changes.
DAWN_URL="https://github.com/PeerInfinity/dawn-prebuilt/releases/download/dawn-620a520f/dawn-prebuilt-620a520f-ubuntu24.04-x64.tar.gz"
DAWN_SHA256="6a9f926ceb60b832598cd5f759a244897227cf5d4ebd26677152534879636a7e"
DAWN_DIR="$DEST_ROOT/dawn-install"
if [ -f "$DAWN_DIR/lib/libwebgpu_dawn.a" ] && grep -q "620a520f" "$DAWN_DIR/MANIFEST.txt" 2>/dev/null; then
  log "dawn: already installed at $DAWN_DIR"
else
  TMP="$(mktemp /tmp/dawn.XXXXXX.tgz)"
  if timeout 180 curl -fsSL --retry 3 -o "$TMP" "$DAWN_URL" \
     && echo "$DAWN_SHA256  $TMP" | sha256sum -c --quiet - ; then
    rm -rf "$DAWN_DIR"
    if tar xzf "$TMP" -C "$DEST_ROOT" && [ -f "$DAWN_DIR/lib/libwebgpu_dawn.a" ]; then
      log "dawn: OK ($DAWN_DIR)"
    else
      log "dawn: FAILED (extract)"
    fi
  else
    log "dawn: FAILED (download or sha256 mismatch)"
  fi
  rm -f "$TMP"
fi

# verify_output.py defaults DAWN_INSTALL to <repo parent>/dawn-install; the
# cloud clone lives at /home/user/SWFRecomp-CC while $HOME is /root.
[ -d /home/user ] && ln -sfn "$DAWN_DIR" /home/user/dawn-install && log "dawn: symlinked /home/user/dawn-install"

log "done"
exit 0
