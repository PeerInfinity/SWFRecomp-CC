#!/bin/bash
# Archive a fanout branch's report files into the history repo (D3: reports never land in the main repo).
usage() {
  cat <<'EOF'
usage: tools/coord/archive_branch.sh [-n] <branch> <report dir>
  <branch>      e.g. origin/fanout/w2-foo (fetch it first)
  <report dir>  the session dir inside the branch, e.g. SWFRecompDocs/plans/session31-fanout-reports
  -n            dry run: list what would be copied, copy nothing
Run from the SWFRecomp-CC main tree. HISTORY (default: <main tree>/../SWFRecomp-CC-history) is the history-repo
checkout. Every blob under <report dir> on the branch is compared with the same path in HISTORY:
  NEW      missing in HISTORY        -> copied
  CHANGED  differs from HISTORY      -> copied (the branch is newer: workers re-push final reports)
  same     byte-identical            -> skipped
Nothing is staged or committed; review with `git -C $HISTORY status`, then stage by name and commit there.
Use it at every delivery AND before pruning fanout/* at closeout (it is the "cmp every blob" check: a prune is safe
when a run prints 0 NEW and 0 CHANGED).
EOF
}
DRY=0; [ "${1:-}" = -n ] && { DRY=1; shift; }
case "${1:-}" in -h|--help|"") usage; [ -n "${1:-}" ]; exit $?;; esac
[ $# -eq 2 ] || { usage >&2; exit 2; }
set -eu; B=$1; RD=${2%/}
TOP=$(git rev-parse --show-toplevel); H=${HISTORY:-$TOP/../SWFRecomp-CC-history}
[ -d "$H/.git" ] || { echo "history checkout not found: $H (git clone https://github.com/PeerInfinity/SWFRecomp-CC-history)" >&2; exit 2; }
git rev-parse --verify -q "$B^{commit}" >/dev/null || { echo "no such branch/commit: $B" >&2; exit 2; }
new=0; chg=0; same=0
while IFS=$'\t' read -r meta path; do
  blob=$(echo "$meta" | awk '{print $3}'); mode=$(echo "$meta" | awk '{print $1}')
  dst="$H/$path"
  if [ -e "$dst" ]; then
    [ "$(git hash-object "$dst")" = "$blob" ] && { same=$((same+1)); continue; }
    tag=CHANGED; chg=$((chg+1))
  else tag=NEW; new=$((new+1)); fi
  echo "$tag $path"
  [ $DRY = 1 ] && continue
  mkdir -p "$(dirname "$dst")"; git cat-file blob "$blob" > "$dst"
  [ "$mode" = 100755 ] && chmod +x "$dst"
done < <(git ls-tree -r "$B" -- "$RD")
echo "NEW $new  CHANGED $chg  same $same  (history checkout: $H$([ $DRY = 1 ] && echo ', dry run'))"
