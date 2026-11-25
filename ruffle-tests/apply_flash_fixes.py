#!/usr/bin/env python3
"""Re-apply the stored Flash fixes to a freshly downloaded Ruffle test corpus.

Some Ruffle goldens are not what real Flash Player produces: Ruffle rendered them, or they come from a host we
can't reproduce. The project's target is Flash, not Ruffle (user ruling, 2026-09-29 / 2026-11-24). So where a
real Flash Player 32 capture proves a golden wrong, the fix lives in `ruffle-tests/flash_fixes/` (git-tracked)
and is copied over the downloaded file after every `download_tests.sh`. The downloaded original is kept next to
it as `<file>.upstream`.

Manifest: `flash_fixes/fixes.json`, a list of entries:
  test             suite-relative test dir, e.g. "avm2/blend_scroll"
  file             file inside the test dir to replace, e.g. "output.expected.png" or "output.txt"
  upstream_sha256  sha256 of the upstream file the fix was made against
  fix              path of the replacement, relative to flash_fixes/
  evidence, reason, rvf, added   provenance (Flash capture path, why, RUFFLE_VS_FLASH_DIFFERENCES anchor, date)

Per entry, depending on the file currently on disk:
  APPLIED     it was the recorded upstream file -> replaced by the fix
  ALREADY     it is already the fix (re-run without a re-download)
  UPSTREAMED  upstream now ships the fix byte for byte -> retire the entry
  STALE       upstream changed the file since the fix was made -> NOT applied; re-check against Flash
  MISSING     the test or file is absent (category not downloaded, or removed upstream)
A STALE or UPSTREAMED entry never fails the run. It is printed so the next session re-derives it.

Usage: apply_flash_fixes.py [--check] [--categories avm1 avm2 ...]
  --check  report only; change nothing
"""
import argparse, hashlib, json, os, shutil, sys

HERE = os.path.dirname(os.path.abspath(__file__))
FIXES = os.path.join(HERE, "flash_fixes")
SWFS = os.path.join(HERE, "tests", "swfs")


def sha(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 16), b""):
            h.update(chunk)
    return h.hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--categories", nargs="*")
    a = ap.parse_args()
    entries = json.load(open(os.path.join(FIXES, "fixes.json")))
    counts = {}
    for e in entries:
        cat = e["test"].split("/", 1)[0]
        if a.categories and cat not in a.categories:
            continue
        fix = os.path.join(FIXES, e["fix"])
        dest = os.path.join(SWFS, e["test"], e["file"])
        fix_sha = sha(fix)
        if not os.path.exists(dest):
            st = "MISSING"
        else:
            cur = sha(dest)
            if cur == fix_sha:
                up = dest + ".upstream"
                st = "ALREADY" if os.path.exists(up) and sha(up) == e["upstream_sha256"] else "UPSTREAMED"
            elif cur == e["upstream_sha256"]:
                st = "APPLIED"
                if not a.check:
                    shutil.copyfile(dest, dest + ".upstream")
                    shutil.copyfile(fix, dest)
            else:
                st = "STALE"
        counts[st] = counts.get(st, 0) + 1
        loud = st in ("STALE", "UPSTREAMED")
        print(f"flash-fix {st:10s} {e['test']}/{e['file']}" + ("   <-- re-check against Flash" if loud else ""))
    print("flash-fixes: " + ", ".join(f"{k} {v}" for k, v in sorted(counts.items())) + (" (check only)" if a.check else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
