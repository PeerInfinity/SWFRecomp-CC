#!/usr/bin/env python3
"""Assemble a release of the in-browser recompiler page for PeerInfinity/swfrecomp-browser.

The release repo holds one release: the page files (tracked here in docs/recompiler/) plus
the BUILT files (SWFRecomp.{js,wasm}, host/, bundle/, build_info.json), which
SWFRecomp/scripts/deploy_wasm_demo.sh generates from SWFRecomp/ and SWFModernRuntime/ only.

Two commits are recorded, and they may differ:
  source.commit       the commit whose BUILD INPUTS (SWFRecomp/, SWFModernRuntime/) produced
                      every built file. Archipelago-CC pins this against the default Seedling
                      wasm build's `source.recompiler`.
  source.page.commit  the commit the page files come from.

Page-only release (the default): the built files are carried over from the previous release
and must be byte-identical to it (sha256 of every built file). The build inputs may differ
between source.commit and source.page.commit only in the LITERAL paths of NOT_BUILD_INPUTS.
Anything else REFUSES. A release that needs new binaries is a rebuild (--rebuild), which
moves source.commit, and in Archipelago-CC that is a user-gated re-pin of the Seedling wasm.

usage:
  make_release.py --release-repo ~/CC/swfrecomp-browser [--page-commit HEAD]
                  [--rebuild --built-dir <docs/recompiler of a fresh deploy> --build-commit <sha>]
                  [--dry-run]
Run from anywhere; the SWFRecomp-CC repo is the one containing this script.
"""
import argparse, hashlib, json, os, re, shutil, subprocess, sys

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
BUILD_INPUT_PATHS = ["SWFRecomp", "SWFModernRuntime"]
PAGE_DIR = "docs/recompiler"

# Paths under BUILD_INPUT_PATHS that may change without changing a built file. LITERAL paths
# only (no globs, no prefixes), each with the reason it is not a build input. Extending this is
# a claim about the build; verify it before adding a line.
NOT_BUILD_INPUTS = {
    "SWFRecomp/assets/NotoSans-OFL.txt":
        "licence text; CMake embeds only assets/NotoSans.ttf (--embed-file of that one file)",
}

# Built files, relative to recompiler/ in the release (gitignored in docs/recompiler/ here).
def is_built(rel):
    return rel in ("SWFRecomp.js", "SWFRecomp.wasm", "build_info.json") or rel.startswith(("host/", "bundle/"))


def git(*args, binary=False):
    out = subprocess.run(["git", "-C", REPO, *args], check=True, capture_output=True)
    return out.stdout if binary else out.stdout.decode().strip()


def hashes(b):
    return {"bytes": len(b), "md5": hashlib.md5(b).hexdigest(), "sha256": hashlib.sha256(b).hexdigest()}


def walk(root):
    for dp, dns, fns in os.walk(root):
        dns[:] = sorted(d for d in dns if d != ".git")
        for fn in sorted(fns):
            p = os.path.join(dp, fn)
            yield os.path.relpath(p, root).replace(os.sep, "/"), p


def refuse(msg):
    sys.exit(f"REFUSED: {msg}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--release-repo", required=True)
    ap.add_argument("--page-commit", default="HEAD")
    ap.add_argument("--rebuild", action="store_true", help="new built files: needs --built-dir and --build-commit")
    ap.add_argument("--built-dir")
    ap.add_argument("--build-commit")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    rel_repo = os.path.abspath(os.path.expanduser(a.release_repo))
    prev = json.load(open(os.path.join(rel_repo, "release.json")))
    page_commit = git("rev-parse", a.page_commit + "^{commit}")
    rec_dir = os.path.join(rel_repo, "recompiler")

    # --- the built files and the commit that built them ---
    if a.rebuild:
        if not (a.built_dir and a.build_commit):
            refuse("--rebuild needs --built-dir and --build-commit")
        build_commit = git("rev-parse", a.build_commit + "^{commit}")
        built_src = os.path.abspath(a.built_dir)
    else:
        build_commit = prev["source"]["commit"]
        built_src = rec_dir
    built = {rel: open(p, "rb").read() for rel, p in walk(built_src) if is_built(rel)}
    modes = {rel: os.stat(p).st_mode & 0o777 for rel, p in walk(built_src) if is_built(rel)}   # kept as found
    if not built:
        refuse(f"no built files under {built_src}")

    # Page-only: every built file byte-identical to the previous release's.
    baseline = None
    if not a.rebuild:
        prev_built = (prev.get("build") or {}).get("files")
        if prev_built:   # release 2 onwards: sha256 recorded
            want = {f["path"]: f["sha256"] for f in prev_built}
            basis = "release.json build.files[].sha256"
        else:            # release 1 recorded md5 per file; hash the committed blobs instead
            head = subprocess.run(["git", "-C", rel_repo, "rev-parse", "HEAD"], check=True, capture_output=True, text=True).stdout.strip()
            want = {}
            for f in prev["files"]:
                if f["path"].startswith("recompiler/") and is_built(f["path"][len("recompiler/"):]):
                    blob = subprocess.run(["git", "-C", rel_repo, "show", f"{head}:{f['path']}"], check=True, capture_output=True).stdout
                    if hashlib.md5(blob).hexdigest() != f["md5"]:
                        refuse(f"{f['path']}: the committed blob does not match the previous release.json md5")
                    want[f["path"][len("recompiler/"):]] = hashlib.sha256(blob).hexdigest()
            basis = f"the previous release's committed blobs at {head} (md5-checked against its release.json)"
        got = {k: hashlib.sha256(v).hexdigest() for k, v in built.items()}
        diff = sorted(set(want) ^ set(got)) + sorted(k for k in set(want) & set(got) if want[k] != got[k])
        if diff:
            refuse(f"page-only release but {len(diff)} built file(s) differ from the previous release: {diff[:10]}. "
                   "New binaries are a --rebuild, which moves source.commit (in Archipelago-CC: a user-gated re-pin).")
        baseline = {"equal": True, "files": len(got), "basis": basis}

    # Build inputs between the build commit and the page commit: only NOT_BUILD_INPUTS may differ.
    changed = [p for p in git("diff", "--name-only", build_commit, page_commit, "--", *BUILD_INPUT_PATHS).splitlines() if p]
    bad = [p for p in changed if p not in NOT_BUILD_INPUTS]
    if bad:
        refuse(f"build inputs changed between {build_commit[:10]} and {page_commit[:10]}: {bad[:10]}. "
               "The built files would not be what this commit builds: rebuild (a user-gated re-pin in Archipelago-CC).")

    # --- page files at the page commit ---
    page, page_modes = {}, {}
    for line in git("ls-tree", "-r", page_commit, "--", PAGE_DIR).splitlines():
        meta, path = line.split("\t", 1)
        rel = path[len(PAGE_DIR) + 1:]
        page[rel] = git("show", f"{page_commit}:{path}", binary=True)
        page_modes[rel] = 0o755 if meta.split()[0] == "100755" else 0o644
    clash = [p for p in page if is_built(p)]
    if clash:
        refuse(f"tracked page files overlap the built set: {clash}")

    if a.dry_run:
        print(f"OK (dry run): build {build_commit[:10]}, page {page_commit[:10]}, {len(built)} built + {len(page)} page files; "
              f"build-input diff {changed or 'none'}")
        return

    # --- write recompiler/ = built + page; nothing else survives ---
    staged = {**built, **page}
    staged_modes = {**modes, **page_modes}
    if os.path.isdir(rec_dir):
        shutil.rmtree(rec_dir)
    for rel, b in staged.items():
        p = os.path.join(rec_dir, rel)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, "wb").write(b)
        os.chmod(p, staged_modes[rel])

    trees = {p: git("rev-parse", f"{build_commit}:{p}") for p in BUILD_INPUT_PATHS}
    build_info = json.loads(built["build_info.json"])
    walk_v = None
    if "walk_api.js" in page:
        src = page["walk_api.js"].decode()
        m = re.search(r"PROTOCOL_VERSION\s*=\s*(\d+)", src)
        walk_v = int(m.group(1)) if m else None

    files = []
    for rel, p in walk(rel_repo):
        if rel == "release.json":
            continue
        files.append({"path": rel, **hashes(open(p, "rb").read())})
    built_rec = [{"path": k, **{x: y for x, y in hashes(v).items() if x != "md5"}} for k, v in sorted(built.items())]

    out = {
        "$comment": "The release manifest. This repository carries ONE release of the in-browser recompiler page of PeerInfinity/SWFRecomp-CC. "
                    "`source.commit` is the commit whose build inputs (SWFRecomp/, SWFModernRuntime/) produced every BUILT file (`build.files`, sha256 each); "
                    "`source.page.commit` is the commit the page files (docs/recompiler/) come from. `source.buildInputsUnchanged` is the measured "
                    "`git diff --name-only` of the build inputs between the two, which may name only paths that are not build inputs. "
                    "Written by SWFRecomp-CC tools/browser-release/make_release.py; nothing here is hand-edited except README.md, LICENSE, licenses/, catalog.json and examples/. "
                    "`runtime` names what the page fetches at run time; those bytes are NOT in this repository.",
        "source": {
            "repo": "PeerInfinity/SWFRecomp-CC",
            "commit": build_commit,
            "trees": trees,
            "page": {
                "commit": page_commit,
                "tree": git("rev-parse", f"{page_commit}:{PAGE_DIR}"),
                "files": sorted(page),
            },
            "buildInputsUnchanged": {
                "from": build_commit,
                "to": page_commit,
                "paths": BUILD_INPUT_PATHS,
                "diff": changed,
                "allowlist": [{"path": k, "reason": v} for k, v in NOT_BUILD_INPUTS.items()],
            },
            "recipe": "built files: git archive <source.commit> SWFRecomp SWFModernRuntime docs/recompiler | tar -x; bash SWFRecomp/scripts/deploy_wasm_demo.sh --build (emsdk 5.0.0); "
                      "build_info.json `commit` set to the short SHA (the archive has no .git). Release: tools/browser-release/make_release.py at source.page.commit.",
            "licence": prev["source"].get("licence"),
            "toolchain": {"emsdk": "5.0.0"},
            "builtAt": build_info.get("built_at"),
        },
        "page": "recompiler/index.html",
        "walkApi": {"protocol": "swfrecomp-walk", "version": walk_v, "module": "recompiler/walk_api.js", "defaultChannel": "swfrecomp-walk"} if walk_v else None,
        "build": {
            "commit": build_commit,
            "files": built_rec,
            "sameAsPreviousRelease": baseline,
        },
        "runtime": {
            "requires": "Chrome/Chromium 137+ (WebAssembly JSPI), WebGPU, SharedArrayBuffer (cross-origin isolation via recompiler/coi-serviceworker.js; "
                        "in an iframe, via its Document-Isolation-Policy where the browser honours it)",
            "vendored": [
                {"what": "@wasmer/sdk", "version": "0.8.0-beta.1", "license": "MIT", "path": "recompiler/vendor/wasmer-sdk/",
                 "npmTarballSha256": "3955c4c0a5d65fc016aadb9040121e0866cec3843dda1bd272f1ff5e18127907"},
                {"what": "fflate", "version": "0.8.2", "license": "MIT", "path": "recompiler/vendor/fflate/", "usedFor": "the zip downloads",
                 "npmTarballSha256": "61fd5061e2fc8e5e3e3129f7f2fec7bd78a313e1bf4becbf1cc1cc9998d141dc"},
            ],
            "fetches": [
                {"what": "clang/clang (wasmer registry package)", "version": "0.160000.1",
                 "url": "https://cdn.wasmer.io/webcimages/c127b7bfc0041d02c94045f40be7fb4b3eeb98cede25fad96261b7b90a82f405.webc",
                 "sha256": "c127b7bfc0041d02c94045f40be7fb4b3eeb98cede25fad96261b7b90a82f405", "bytes": 110713421,
                 "pinned": True, "verified": "the page checks the sha256 before use; `?clangWebc=<url>` fetches it elsewhere (same check)",
                 "license": "not declared in the registry (contents: LLVM/clang 16 + lld, Apache-2.0 WITH LLVM-exception; a WASIX libc sysroot)"},
            ],
        },
        "files": files,
        "totalBytes": sum(f["bytes"] for f in files),
    }
    if out["walkApi"] is None:
        del out["walkApi"]
    with open(os.path.join(rel_repo, "release.json"), "w") as f:
        json.dump(out, f, indent=1, ensure_ascii=False)
        f.write("\n")
    print(f"release.json: build {build_commit[:10]}, page {page_commit[:10]}, {len(files)} files, {out['totalBytes']} bytes; "
          f"built files {'identical to the previous release' if baseline else 'from ' + built_src}; build-input diff {changed or 'none'}")


if __name__ == "__main__":
    main()
