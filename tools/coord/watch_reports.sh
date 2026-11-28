#!/bin/bash
# Exits (printing slugs) once any fanout/<slug> (slug in $SP/slugs, not in $SP/delivered) carries its final report.
# (From the s25-s30 coordinators; promoted to tools/coord/ by repo-cleanup S1.)
#   SP=<scratch dir holding slugs + delivered>  REPORT_DIR=SWFRecompDocs/plans/sessionN-fanout-reports \
#     tools/coord/watch_reports.sh          # launch with run_in_background, re-launch after each delivery
# A report counts as final when <REPORT_DIR>/<slug>-report.md exists on the branch, its first 3 lines don't say
# "interim", it holds no __PLACEHOLDER__ tokens, and (w2*/w3* slots) <REPORT_DIR>/<slug>.patch exists too.
# REPORT_DIR is the path INSIDE the worker's branch; it mirrors the history-repo path the report is archived at.
case "${1:-}" in -h|--help) sed -n '2,8p' "$0"; exit 0;; esac
SP=${SP:?set SP to a scratch dir holding slugs + delivered}
RD=${REPORT_DIR:?set REPORT_DIR, e.g. SWFRecompDocs/plans/session31-fanout-reports}
cd "${REPO:-$(git rev-parse --show-toplevel)}"; touch $SP/delivered
while true; do
  out=""
  for s in $(grep -vFxf $SP/delivered $SP/slugs); do
    git ls-remote --exit-code origin refs/heads/fanout/$s >/dev/null 2>&1 || continue
    git fetch -q origin fanout/$s:refs/remotes/origin/fanout/$s 2>/dev/null
    R=origin/fanout/$s:$RD/$s-report.md
    git show $R 2>/dev/null | head -3 | sed "s/interim2//g; s/interim #[0-9]//g" | grep -qi "interim" && continue
    git cat-file -e $R 2>/dev/null || continue
    git show $R | grep -qE "__[A-Z_]{4,}__|_PLACEHOLDER" && continue
    case $s in w2*|w3*) git cat-file -e origin/fanout/$s:$RD/$s.patch 2>/dev/null || continue;; esac
    out="$out $s"
  done
  if [ -n "$out" ]; then for s in $out; do echo $s | tee -a $SP/delivered; done; exit 0; fi
  sleep 120
done
