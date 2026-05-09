#!/usr/bin/env python3
"""Generate docs/local_catalog.json from docs/examples/local_batch/.

Mirrors the per-entry schema used by docs/catalog.json's `tests` array:
each test gets id="local_batch/<name>", type="local_batch", path,
js_file/wasm_file, has_swf, plus metadata pulled from test_info.json.

Kept separate from the official catalog.json so build_swf_batch.sh /
clean_swf_batch.sh can manage local builds without touching the
upstream-tracked catalog. docs/index.html fetches both files.
"""
import json
import os
import sys
from datetime import datetime, timezone


def collect_tests(local_batch_dir):
    tests = []
    if not os.path.isdir(local_batch_dir):
        return tests
    for name in sorted(os.listdir(local_batch_dir)):
        test_dir = os.path.join(local_batch_dir, name)
        if not os.path.isdir(test_dir):
            continue
        # Only count entries with a real WASM artifact — skips half-built
        # scratch dirs from cancelled runs.
        wasm_files = [f for f in os.listdir(test_dir) if f.endswith(".wasm")]
        if not wasm_files:
            continue

        entry = {
            "id": f"local_batch/{name}",
            "name": name,
            "type": "local_batch",
            "path": f"examples/local_batch/{name}",
            "has_swf": os.path.exists(os.path.join(test_dir, "test.swf")),
            "wasm_file": wasm_files[0],
        }
        for f in os.listdir(test_dir):
            if f.endswith(".js") and not f.startswith("."):
                entry["js_file"] = f
                break

        info_path = os.path.join(test_dir, "test_info.json")
        if os.path.exists(info_path):
            with open(info_path) as f:
                info = json.load(f)
            meta = info.get("metadata", {})
            entry["description"] = meta.get("description", "")
            entry["swf_version"] = meta.get("swf_version")
            entry["fully_implemented"] = meta.get("fully_implemented", False)
            opcodes = info.get("opcodes", {})
            entry["opcodes_tested"] = opcodes.get("tested", [])
            entry["opcodes_supporting"] = opcodes.get("supporting", [])

        tests.append(entry)
    return tests


def main():
    if len(sys.argv) != 2:
        print("Usage: generate_local_catalog.py <docs_dir>", file=sys.stderr)
        sys.exit(1)
    docs_dir = sys.argv[1]
    local_batch_dir = os.path.join(docs_dir, "examples", "local_batch")
    out_path = os.path.join(docs_dir, "local_catalog.json")

    tests = collect_tests(local_batch_dir)
    catalog = {
        "generated": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "tests": tests,
    }
    with open(out_path, "w") as f:
        json.dump(catalog, f, indent=2)
    print(f"Wrote {out_path} with {len(tests)} local-batch tests")


if __name__ == "__main__":
    main()
