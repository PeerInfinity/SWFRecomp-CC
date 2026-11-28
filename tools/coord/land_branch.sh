#!/bin/bash
# 3-way land a fanout branch's non-doc changes into the shared tree (index + working tree).
# (From the s29 coordinator; promoted to tools/coord/ by repo-cleanup S1.)
usage() {
  cat <<'EOF'
usage: tools/coord/land_branch.sh <branch> <scratch dir>
Run from the SWFRecomp-CC main tree. Lands the branch's changes under
SWFModernRuntime/ SWFRecomp/ ruffle-tests/ (reports are NOT landed: archive them to
the history repo with tools/coord/archive_branch.sh).
  - text files: git merge-file (ours=HEAD, base=merge-base, theirs=branch);
    conflicts left marked in <scratch>/m.*, listed at the end
  - fixes.json: JSON union by (test,file), indent=2
  - binary: theirs (never through merge-file)
A file with uncommitted peer edits is refused and listed (route it through
`git apply --cached`; memory shared-index-commit-sweeps-peer-hunks).
Outputs in <scratch> (wiped first): files, deleted, conflicts, dirty, m.<path_with_underscores>.
EOF
}
case "${1:-}" in -h|--help|"") usage; [ -n "${1:-}" ]; exit $?;; esac
[ $# -eq 2 ] || { usage >&2; exit 2; }
set -u; B=$1; SP=$2
git rev-parse --verify -q "$B^{commit}" >/dev/null || { echo "no such branch/commit: $B" >&2; exit 2; }
case "$SP" in ""|/|.|..|"$HOME") echo "refusing scratch dir '$SP'" >&2; exit 2;; esac
rm -rf "$SP"; mkdir -p "$SP"
MB=$(git merge-base "$B" HEAD); git diff --name-only --diff-filter=AMR "$MB" "$B" -- SWFModernRuntime SWFRecomp ruffle-tests > "$SP/files"
git diff --name-only --diff-filter=D "$MB" "$B" -- SWFModernRuntime SWFRecomp ruffle-tests > "$SP/deleted"
: > "$SP/conflicts"; : > "$SP/dirty"
while read f; do k=$(echo "$f" | tr / _)
  if ! git diff --quiet -- "$f" 2>/dev/null; then echo "$f" >> "$SP/dirty"; continue; fi
  git show "HEAD:$f" > "$SP/o.$k" 2>/dev/null || : > "$SP/o.$k"
  git show "$MB:$f" > "$SP/b.$k" 2>/dev/null || : > "$SP/b.$k"
  git show "$B:$f" > "$SP/t.$k"
  case "$f" in
    *fixes.json) python3 - "$SP/o.$k" "$SP/t.$k" "$SP/m.$k" <<'PY'
import json,sys
o=json.load(open(sys.argv[1])); t=json.load(open(sys.argv[2])); keys={(e['test'],e['file']) for e in o}
add=[e for e in t if (e['test'],e['file']) not in keys]; print('fixes.json: +',len(add))
open(sys.argv[3],'w').write(json.dumps(o+add,indent=2,ensure_ascii=False)+'\n')
PY
    ;;
    *) if grep -qI . "$SP/t.$k" 2>/dev/null || [ ! -s "$SP/t.$k" ]; then git merge-file -p "$SP/o.$k" "$SP/b.$k" "$SP/t.$k" > "$SP/m.$k" || echo "$f" >> "$SP/conflicts"
       else cp "$SP/t.$k" "$SP/m.$k"; fi;;
  esac
done < "$SP/files"
echo "files: $(wc -l < "$SP/files")  conflicts: $(wc -l < "$SP/conflicts")  peer-dirty: $(wc -l < "$SP/dirty")  deleted: $(wc -l < "$SP/deleted")"
cat "$SP/conflicts" "$SP/dirty"
