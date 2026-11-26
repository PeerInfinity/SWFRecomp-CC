#!/bin/bash
# usage: abatch.sh VARIANT [extra verify args]  — runs all tests.txt, one verify per suite
S=/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/3e338f5d-1618-4e7c-909f-a5f9a3c33cfd/scratchpad
V=$1; shift
cd $S/wt
export DAWN_INSTALL=$HOME/CC/dawn-install
env=()
[ $V = snapoff ] && env+=(SWF_STROKE_SNAP=0)
[ $V = glyphoff ] && env+=(SWFRECOMP_EXTRA_DEFINES=-DTF_GLYPH_NO_QSNAP)
[ $V = exp ] && env+=(SWF_EXP_QLOW=1)
[ $V = widthoff ] && env+=(SWF_STROKE_FLASH_WIDTH=0)
for suite in $(cut -d/ -f1 ${TESTS:-$S/tests.txt} | sort -u); do
  args=(); for t in $(grep "^$suite/" ${TESTS:-$S/tests.txt}); do args+=(--test=${t#*/}); rm -f ruffle-tests/tests/swfs/$t/*.actual.png; done
  mkdir -p $S/ab/$V
  flock /tmp/swfrecomp-cpu.lock env "${env[@]}" python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/$suite "${args[@]}" --mode=graphics --images -v "$@" --json=$S/ab/$V/$suite.json > $S/ab/$V/$suite.log 2>&1
  for t in $(grep "^$suite/" ${TESTS:-$S/tests.txt}); do mkdir -p $S/ab/$V/$t; cp ruffle-tests/tests/swfs/$t/*.actual.png $S/ab/$V/$t/ 2>/dev/null; done
  echo "$V $suite done"
done
