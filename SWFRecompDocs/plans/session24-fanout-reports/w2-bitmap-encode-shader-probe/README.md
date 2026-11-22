# s24 w2-bitmap-encode-shader oracle probes (sources only)

No mxmlc in the cloud, so these are AS3 sources for the coordinator to compile
(`~/CC/flex-sdk/bin/mxmlc -omit-trace-statements=false -target-player=11.1
-static-link-runtime-shared-libraries=true Test.as -output test.swf`) and run
through the local Ruffle exporter (`output.txt` trace + `output.expected.png`,
last frame). Then move each directory to `ruffle-tests/tests/swfs/regression/`
as `avm2_shaderfilter_cache` / `avm2_bitmapdata_draw_cxform_blend`.

- `shaderfilter_cache/`: ShaderFilter on a Bitmap must follow later writes to
  its BitmapData (fillRect, setPixel, lock/setPixel32/unlock, draw, copyPixels)
  and a parameter change + `filters` reassignment. Reuses the corpus
  `tintype.pbj` (avm2/pixelbender_effect_tintype). `output.txt` here is the
  expected trace by construction; the PNG must come from Ruffle.
- `draw_cxform_blend/`: vector `draw()` with colorTransform + blendMode at
  default quality. `output.txt` must come from Ruffle (getPixel values).
