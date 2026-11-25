#!/bin/bash
# run.sh NAME... : build spec via sweeps.py, probe SWF, Flash capture, analyze
D=$(dirname "$0")
for n in "$@"; do
  python3 $D/sweeps.py $n > $D/$n.spec.json && python3 $D/probe.py $D/$n.spec.json $D/$n && \
  python3 $D/../../../tools/flash-oracle/run_image.py $D/$n -o $D/$n/flash.png 2>&1 | tail -1
done
