**JPEG decode fidelity to Flash** (w1-drift lead 1). Categories: `avm2`, `from_shumway`, `visual`, `avm1`, `regression`.

Two rows now have **Flash Player goldens** with JPEG content. `avm2/pixelbender_dithering` passes at 9413 / 32500 since s27 `d3b6d71b8` (nearest-sampling ties go up). `from_shumway/.../bitmapdata-clone` passes at max_diff 77 = tolerance 77, with **zero headroom**. We decode with stb_image. w1-drift measured stb vs libjpeg-turbo at up to 3 levels on 7 % of channels, and libjpeg-turbo about 4 % closer to Flash on the dithering image (`session27-fanout-reports/w1-drift-report.md` §1–2).

1. Determine Flash's decoder behaviour: IJG ISLOW IDCT? fancy (triangle) h2v2 upsampling? which YCbCr→RGB tables? DefineBitsJPEG2/3 vs JPEG4 deblocking? Use the two Flash goldens as measures (decode the embedded JPEGs with candidate decoders in Python, render the row's math, score against the Flash PNG).
2. If a decoder configuration is measurably closer to Flash on both rows, prototype it in `image_decode.c` (keep stb as fallback; no new heavy dependency without saying so; libjpeg-turbo is in the cloud apt set only if the CI images have it: check `ruffle-tests.yml`/setup before choosing it) and run an A/B over EVERY JPEG-bearing image row (static scan of DefineBitsJPEG*), md5 + status. Ruffle-golden JPEG rows that move away from Ruffle while the Flash rows improve are priced losses to disposition.
3. Also re-check the GPU nearest sampler's tie rule (`render_webgpu.c`, on-stage 0x43 fills): build a fixture SWF with a non-smoothed bitmap fill at y scale exactly 1.5 drawn ON STAGE, and put it under LOCAL ORACLE REQUESTS (FLASH image); predict both tie rules' outputs.

Deliver a measured GO/NO-GO. Insurance work, so 0 flips is an acceptable verdict if the headroom grows.
