#!/bin/bash
# usage: sweep.sh LABEL  -> per-row status line + actual-png md5s, -P 2
cd /home/user/SWFRecomp-CC
S=/tmp/claude-0/-home-user-SWFRecomp-CC/31934d60-317c-5e7c-a89e-0e87c5d2dee5/scratchpad
LIST="regression:avm1_runtime_filters_cm_bitmap regression:avm1_nested_po3_filters visual:filters/blur_scales_with_screen visual:cache_as_bitmap/contains_grown_filter avm2:filter_rewind from_shumway:bitmapbuttons
regression:avm1_runtime_filters regression:avm1_parent_child_bitmap_fill regression:avm1_parent_child_render regression:avm1_parent_child_text
visual:filters/empty_child_filter_bounds visual:filters/color_matrix visual:filters/glow visual:filters/drop_shadow visual:filters/bevel_full
visual:filters/glow_without_composite_source visual:filters/avm1_convolution_initialization visual:cache_as_bitmap/cab_mask_filters
visual:cache_as_bitmap/color_transform visual:cache_as_bitmap/nested_color_transform visual:edittext/edittext_border_filters
from_shumway:acid/acid-filter-2 from_shumway:avm1/filters avm1:bitmap_filters avm1:bitmapdata_applyfilter_colormatrix
from_gnash:actionscript.all/MovieClip-v8 from_gnash:actionscript.all/MovieClip-v7 avm1:movieclip_state_values avm1:native_objects_swf8"
one() {
  t=$1; L=$2; MODE=$3; suite=${t%%:*}; name=${t#*:}
  d=ruffle-tests/tests/swfs/$suite/$name
  MARG=""; [ "$MODE" = g ] && MARG="--mode=graphics"; rm -f $d/*.actual.png
  out=$(python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/$suite --test=$name $MARG --recompile --diff --verbose 2>&1)
  st=$(echo "$out" | grep -E "image:|PASS|FAIL|MISMATCH|ruffle_matched|ERROR" | grep -v "^Pass:\|^Fail:" | tr '\n' ' ' | cut -c1-220)
  m=""; for p in $d/*.actual.png; do [ -f "$p" ] && m="$m $(md5sum < $p | cut -c1-8)"; done
  tx=$(echo "$out" | grep -cE "^\s*[-+]\s+[0-9]+")
  echo "$L/$MODE | $suite/$name | difflines=$tx | md5:$m | $st"
}
export -f one
( for m in g n; do echo $LIST | tr ' ' '\n' | sed "s/$/ $1 $m/"; done ) | xargs -P 2 -L1 bash -c 'one "$@"' _ | sort -t'|' -k2
