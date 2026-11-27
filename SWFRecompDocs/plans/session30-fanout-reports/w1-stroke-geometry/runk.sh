#!/bin/bash
# runk.sh BUILD_DIR OUT.png CMPNAMES [ENV=VAL...]
kb=$1; out=$2; cmp=$3; shift 3
trig=$(echo $cmp | tr ',' '\n' | sed 's/$/:last_frame/' | paste -sd,)
cd $kb && rm -f $kb/*.png && env "$@" TZ=NPT-5:45 CAPTURE_TRIGGERS=$trig CAPTURE_OUTPUT_DIR=$kb ./test_run >/dev/null 2>&1
first=$(echo $cmp | cut -d, -f1); cp $kb/$first.png $out
