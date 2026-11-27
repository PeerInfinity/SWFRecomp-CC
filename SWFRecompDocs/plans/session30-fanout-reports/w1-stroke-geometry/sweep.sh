#!/bin/bash
# sweep.sh SUITE/TEST LEGNAME "ENV=VAL ..."  -> /tmp/claude-0/sw/<safe>/<leg>/*.png + log
t=$1; leg=$2; envs=$3
suite=${t%%/*}; name=${t#*/}
safe=$(echo $t | tr '/' '_')
od=/tmp/claude-0/sw/$safe/$leg; rm -rf $od; mkdir -p $od
kb=/tmp/claude-0/sw/$safe/kb_$leg; rm -rf $kb
cd /home/user/SWFRecomp-CC
env $envs SWF_KEEP_BUILD_DIR=$kb SWFRECOMP_COMPILE_TIMEOUT=2400 python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/$suite --test=$name --mode=graphics --verbose > $od/log.txt 2>&1
cp $kb/*.png $od/ 2>/dev/null; rm -f $od/*difference*
rm -rf $kb
