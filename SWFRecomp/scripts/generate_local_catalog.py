#!/usr/bin/env python3
"""Generate <docs_dir>/<catalog_name> from <docs_dir>/examples/<namespace>/.

Mirrors the per-entry schema used by docs/catalog.json's `tests` array:
each test gets id="<namespace>/<name>", type=<type>, path,
js_file/wasm_file, has_swf, plus metadata pulled from test_info.json.

Kept separate from the official catalog.json so build_swf_batch.sh /
clean_swf_batch.sh can manage local builds without touching the
upstream-tracked catalog. docs/index.html fetches both files.

Defaults preserve the original behavior:
    namespace    = local_batch
    catalog_name = local_catalog.json
    type         = local_batch
"""
import argparse
import json
import os
from datetime import datetime, timezone


def collect_tests(local_batch_dir, namespace, demo_type):
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
            "id": f"{namespace}/{name}",
            "name": name,
            "type": demo_type,
            "path": f"examples/{namespace}/{name}",
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
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("docs_dir", help="Path to docs (or docs2) directory")
    ap.add_argument("--namespace", default="local_batch",
                    help="Subdir name under <docs_dir>/examples/ to scan, also "
                         "the id prefix (default: local_batch)")
    ap.add_argument("--catalog-name", default="local_catalog.json",
                    help="Output filename written under <docs_dir> "
                         "(default: local_catalog.json)")
    ap.add_argument("--type", default=None,
                    help="Value for each entry's 'type' field "
                         "(default: same as --namespace)")
    args = ap.parse_args()

    demo_type = args.type if args.type is not None else args.namespace
    local_batch_dir = os.path.join(args.docs_dir, "examples", args.namespace)
    out_path = os.path.join(args.docs_dir, args.catalog_name)

    tests = collect_tests(local_batch_dir, args.namespace, demo_type)
    catalog = {
        "generated": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "tests": tests,
    }
    with open(out_path, "w") as f:
        json.dump(catalog, f, indent=2)
    print(f"Wrote {out_path} with {len(tests)} {demo_type} tests")


if __name__ == "__main__":
    main()
