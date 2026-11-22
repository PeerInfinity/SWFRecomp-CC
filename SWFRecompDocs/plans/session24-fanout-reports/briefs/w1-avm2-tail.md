**AVM2 trace tail** (rows still failing on the s24 baseline; board `polish-sweep-arc.md` §24.4). Categories to download: `avm2 from_avmplus mixed_avm audio` (only what you need).

Triage every row in one cheap run each, classify it as (a) standing NO-GO / ACCEPTED (name the entry, and confirm the recorded diff shape still holds), (b) harness-limited, or (c) LIVE lead, then go deep on (c):
- `primitive_bound_methods`, `weird_number_bound_methods` (bound-method cache identity), `worker_terminate`, `textline_metrics` (recompiler DefineFont4 typo metrics), `soundchannel_position_after_end` (NEW upstream `0ddd12b6a..bcac30c19`), `audio_computespectrum`, `netstream_play_flv`, `netstream_play_stop_replay`, `netstream_seek_flv`, `verify_method_info_duplicate`, `dependent_strings`, `avm1_root`, `bitmapdata_encode` (trace side of the JPEG encoder; the pixel side is `w1-pixel-bitmap`'s: coordinate, do not both implement it).
- Re-confirm only (one run each): `bom`, `swz`, `loader_load`, `loader_applicationDomain`, `number_tostring`, `sandbox_type_remote`, `from_avmplus/ecma3/Statements/eforin_001/002`, `mixed_avm/avm1_loads_avm2`. Attack one only if its diff shape differs from the record.

For each LIVE lead: mechanism (`file:line`), priced flips, a measured prototype where cheap (AVM2 runtime/recompiler changes need a `categories=full`-shaped rider sweep: argue it, ≤ 40 rows), and GO/NO-GO for wave 2. s23 reports of record: `w2-avm2-small-errors`, `w2-netstream-audio`, `w2-video-props`, `w2-qname-dict`, `w2-stack-trace-names`.

Siblings: `w1-pixel-bitmap` owns the JPEG encoder implementation; nobody else edits AVM2 sound/netstream.
