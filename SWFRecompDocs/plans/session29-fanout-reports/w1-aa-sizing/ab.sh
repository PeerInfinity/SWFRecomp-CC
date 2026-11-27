#!/bin/bash
# usage: ab.sh LEG listfile   (LEG = before | after | after2 ...)
S=/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad
LEG=$1; LIST=$2
cd /home/user/SWFRecomp-CC
export SWFRECOMP_COMPILE_TIMEOUT=2400
while read t; do
  [ -z "$t" ] && continue
  suite=$(dirname "$t"); name=$(basename "$t")
  # suites nested (from_gnash/misc-ming.all, from_shumway/acid, visual/...): find tests-dir = dir holding the test
  slug=$(echo "$t" | tr / _)
  [ -f $S/res/$LEG/$slug.json ] && continue
  mkdir -p $S/res/$LEG $S/png/$LEG/$slug
  bd=$S/b/$LEG-$slug; rm -rf $bd; mkdir -p $bd
  case $LEG in
    before) EXTRA=""; N=0;;
    after)  EXTRA="-DSSAA_PROBE"; N=4;;
    n1)     EXTRA="-DSSAA_PROBE"; N=1;;
    n2)     EXTRA="-DSSAA_PROBE"; N=2;;
    v*) EXTRA="-DSSAA_PROBE"; N=4;;
    sq*)    EXTRA="-DSSAA_PROBE -DSSAA_VSNAP"; N=-1;;
    sc*)    EXTRA="-DSSAA_PROBE"; N=-1;;
    fl)     EXTRA="-DSSAA_PROBE"; N=4; export SSAA_X0=0.5 SSAA_Y0=0 SSAA_FLOOR=1;;
    z4)     EXTRA="-DSSAA_PROBE"; N=4; export SSAA_POS8=1;;
    m4s)    EXTRA="-DSSAA_PROBE -DSSAA_HW4"; N=0; export SSAA_OFS=0.125,0.125;;
    m4q)    EXTRA="-DSSAA_PROBE -DSSAA_HW4 -DSSAA_VSNAP"; N=0; export SSAA_OFS=0,0;;
    m4z)    EXTRA="-DSSAA_PROBE -DSSAA_HW4"; N=0; export SSAA_OFS=0,0;;
    pos8)   EXTRA="-DSSAA_PROBE"; N=8; export SSAA_POS8=1 SSAA_KEEP=$S/frames/$slug;;
  esac
  SWF_KEEP_BUILD_DIR=$bd SWFRECOMP_EXTRA_DEFINES="$EXTRA" SSAA_N=$N timeout 3000 \
    python3 $S/tools/$([ "$N" = -1 ] && echo scan_run.py || echo ssaa_run.py) --tests-dir=ruffle-tests/tests/swfs/$suite --test=$name \
      --mode=graphics --images --json $S/res/$LEG/$slug.json --verbose > $S/res/$LEG/$slug.log 2>&1
  cp $bd/*.png $S/png/$LEG/$slug/ 2>/dev/null
  rm -rf $bd
  echo "$LEG $t $(grep -c . $S/res/$LEG/$slug.log)"
done < $LIST
