# local_swf_batch/

Default input directory for `SWFRecomp/scripts/build_swf_batch.sh`.

Drop `.swf` files in here and run:

    ./SWFRecomp/scripts/build_swf_batch.sh

Each SWF is recompiled with `--graphics` (WebGPU), deployed to
`docs/examples/local_batch/<name>/`, and shows up under a "Local Batch"
category on the demo page (`docs/index.html`). Each demo has Ruffle
side-by-side comparison enabled automatically.

To remove all generated artifacts:

    ./SWFRecomp/scripts/clean_swf_batch.sh

Files in this directory are left untouched by the cleanup script.

This directory exists for **local testing only**. The artifacts under
`docs/examples/local_batch/` and `SWFRecomp/tests/local_batch/` should
not be committed.
