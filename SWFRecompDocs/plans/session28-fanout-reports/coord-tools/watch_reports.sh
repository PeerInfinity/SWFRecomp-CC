#!/bin/bash
# exits (printing slugs) once any fanout/<slug> (slug in $SP/slugs, not in $SP/delivered) carries its report file
SP=${SP:?set SP to a scratch dir holding slugs + delivered}
cd "${REPO:-$(git rev-parse --show-toplevel)}"; touch $SP/delivered
while true; do
  out=""
  for s in $(grep -vFxf $SP/delivered $SP/slugs); do
    git ls-remote --exit-code origin refs/heads/fanout/$s >/dev/null 2>&1 || continue
    git fetch -q origin fanout/$s:refs/remotes/origin/fanout/$s 2>/dev/null
    git show origin/fanout/$s:SWFRecompDocs/plans/session28-fanout-reports/$s-report.md 2>/dev/null | head -3 | grep -qi "interim" && continue; git cat-file -e origin/fanout/$s:SWFRecompDocs/plans/session28-fanout-reports/$s-report.md 2>/dev/null || continue; case $s in w2*) git cat-file -e origin/fanout/$s:SWFRecompDocs/plans/session28-fanout-reports/$s.patch 2>/dev/null || continue;; esac; out="$out $s"
  done
  if [ -n "$out" ]; then for s in $out; do echo $s | tee -a $SP/delivered; done; exit 0; fi
  sleep 120
done
