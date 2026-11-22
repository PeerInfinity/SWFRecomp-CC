**Upstream drift, AVM2** (`bcac30c19..3ac8dcb07` and whatever upstream master is when you run `download_tests.sh`; name-status in `../wave0-upstream-drift-namestatus.txt`). Categories: `avm2` (+ any other category the drift touches).

The s25 baseline grades two new upstream rows as failing: `avm2/pixelbender_shaderjob_output_channels` (upstream `b9929aaf3` 1/2-channel ShaderJob outputs for non-BitmapData targets, `9051addab` smpl coordinate size) and `avm2/textblock_recreate_text_line_width` (upstream `5d629cec4`, width applied to TextLines reused by `recreateTextLine`). A third, `avm2/local_connection_allow_networking` (upstream `562a59507`, allowNetworking check in LocalConnection), arrived after the baseline run and is ungraded. Each upstream test commit has the Ruffle source change next to it: read that diff in your blobless Ruffle clone and port the behaviour (Flash-over-Ruffle still applies; `output.txt` is Flash's).

1. Re-run `download_tests.sh avm2` and list EVERY upstream change since `bcac30c19` that touches a test we grade (new, changed expected, deleted). Name-status the drift at your download SHA.
2. For each new/changed row: baseline status, mechanism, priced flip, and a measured prototype (these are usually small). Check `allow_networking` handling in `verify_output.py` (s23 H1 grades `allow_networking` rows).
3. Rider sweep over the nearest neighbours (other `pixelbender_*`, `textblock_*`/`textline_*`, `localconnection*`/`local_connection*` rows).

A measured, sweep-clean prototype is landed directly by the coordinator (s23/s24 practice), so make it CI-grade: full before/after per row in both modes for anything touching shared code.
