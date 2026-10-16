#!/bin/bash
# $1 = label; runs no-graphics hit-test sweep with --recompile
cd /home/user/SWFRecomp-CC
for t in avm1/hittest_morph avm1/hittest_morph_input avm1/hittest_winding_rule avm1/movieclip_hittest avm1/hitarea_sweep avm1/movieclip_hittest_shapeflag avm2/displayobject_hittestpoint avm2/displayobject_hittestpoint_boundary avm2/hittest_morph avm2/button_hittest avm2/mouse_pick_avm1_root; do
  suite=${t%%/*}; name=${t#*/}
  out=$(python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/$suite --test=$name --recompile --diff --verbose 2>&1)
  st=$(echo "$out" | grep -oE "PASS|FAIL|RUFFLE_MATCHED|ruffle_matched|output_mismatch|runtime_error|compile_fail" | head -1)
  echo "$t $st $(echo "$out" | md5sum | cut -c1-8) $(echo "$out" | grep -iE 'lines|match' | tail -1)"
done
