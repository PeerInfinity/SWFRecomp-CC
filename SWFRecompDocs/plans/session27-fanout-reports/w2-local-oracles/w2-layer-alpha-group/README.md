Flash Player 32 (run_image.py --screen, num_ticks 1, quality high) on w2-layer-alpha-group's grouping probes, pixel (80,50):
| probe | Flash draw() | Flash screen | verdict |
|---|---|---|---|
| n3g_normal | (128,64,191) | same | per child (control) |
| n3g_layer_inner | (128,128,255) | same | GROUPED: ancestor alpha above a LAYER groups (patch right) |
| n3g_filter_cm | (128,128,255) | same | GROUPED: a filtered clip with alpha is a group (patch leaves per-child: follow-up) |
| n3g_cab | (128,65,192) | same | per child: cacheAsBitmap does NOT group alpha |
| n3g_multiply | (128,128,255) | same | GROUPED: non-LAYER blend + alpha is a group (follow-up) |
| n3g_layer_aadd | (128,128,254) | same | GROUPED: alpha offset on LAYER (follow-up) |
