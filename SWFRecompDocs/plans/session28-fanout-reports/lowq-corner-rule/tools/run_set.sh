#!/bin/bash
WT=$1; LIST=$2; OUT=$3; mkdir -p $OUT
SP=$(dirname $0)
flock /tmp/swfrecomp-cpu.lock bash -c "grep -v '^#' $LIST | grep . | xargs -P 2 -I{} $SP/one.sh $WT $OUT {}"
