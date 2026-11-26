#!/bin/bash
# one.sh WT OUT TEST
WT=$1; OUT=$2; t=$3; suite=${t%%/*}; rest=${t#*/}; key=${t//\//__}
cd $WT && DAWN_INSTALL=$HOME/CC/dawn-install CCACHE_NODIRECT=1 python3 ruffle-tests/verify_output.py --test="$rest" --tests-dir=ruffle-tests/tests/swfs/$suite --mode=graphics --verbose > $OUT/$key.log 2>&1
mkdir -p $OUT/$key; cp $WT/ruffle-tests/tests/swfs/$t/*.actual.png $OUT/$key/ 2>/dev/null
echo "$t $(grep -o 'PASS\|FAIL' $OUT/$key.log | head -1) imgfail=$(grep -c 'image:.*FAIL' $OUT/$key.log)"
