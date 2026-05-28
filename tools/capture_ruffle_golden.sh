#!/bin/bash
# Capture a Ruffle reference render for one or all WASM probes.
#
# Writes <probe>/golden_ruffle.png from ~/CC/ruffle/target/release/exporter
# at the probe's intrinsic canvas size (read from test_info.json's
# metadata.width/height). Probe.toml's golden_source should be "ruffle" on
# any probe whose golden_ruffle.png is checked in (typically B-group
# known-red gap probes).
#
# Usage:
#   ./tools/capture_ruffle_golden.sh                       # all probes
#   ./tools/capture_ruffle_golden.sh case_insensitive_settarget_swf5
#   RUFFLE_EXPORTER=/path/to/exporter ./tools/capture_ruffle_golden.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROBES_DIR="${REPO_ROOT}/SWFRecomp/tests/wasm_probes"

RUFFLE_EXPORTER="${RUFFLE_EXPORTER:-$HOME/CC/ruffle/target/release/exporter}"
if [ ! -x "${RUFFLE_EXPORTER}" ]; then
    echo "Error: Ruffle exporter not found at ${RUFFLE_EXPORTER}" >&2
    echo "  Build: cd ~/CC/ruffle && cargo build --release -p exporter" >&2
    exit 1
fi

SINGLE_SLUG=""
if [ -n "$1" ]; then
    SINGLE_SLUG="$1"
fi

PROBE_DIRS=()
if [ -n "$SINGLE_SLUG" ]; then
    if [ ! -d "${PROBES_DIR}/${SINGLE_SLUG}" ]; then
        echo "Error: probe '${SINGLE_SLUG}' not found at ${PROBES_DIR}/${SINGLE_SLUG}" >&2
        exit 1
    fi
    PROBE_DIRS=("${PROBES_DIR}/${SINGLE_SLUG}")
else
    for d in "${PROBES_DIR}"/*/; do
        [ -d "$d" ] || continue
        PROBE_DIRS+=("${d%/}")
    done
fi

read_dim() {
    # Extract metadata.<key> from test_info.json (integer). Falls back to default.
    local file="$1" key="$2" default="$3"
    if [ -f "$file" ]; then
        python3 -c "import json,sys
try:
    print(json.load(open('$file')).get('metadata',{}).get('$key', $default))
except Exception:
    print($default)" 2>/dev/null || echo "$default"
    else
        echo "$default"
    fi
}

for probe_dir in "${PROBE_DIRS[@]}"; do
    slug="$(basename "$probe_dir")"
    swf="${probe_dir}/test.swf"
    if [ ! -f "$swf" ]; then
        echo "[skip ] ${slug}: no test.swf (run build_wasm_probes.sh first)"
        continue
    fi
    width=$(read_dim "${probe_dir}/test_info.json" width 320)
    height=$(read_dim "${probe_dir}/test_info.json" height 240)
    out="${probe_dir}/golden_ruffle.png"
    echo "[ruffle] ${slug} (${width}x${height})"
    "${RUFFLE_EXPORTER}" --silent --width "${width}" --height "${height}" \
        "${swf}" "${out}"
done
