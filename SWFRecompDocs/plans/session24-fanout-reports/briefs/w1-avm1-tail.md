**AVM1 + gnash/shumway trace tail** (rows still failing on the s24 baseline; board `polish-sweep-arc.md` §24.4). Categories to download: `avm1 from_gnash from_shumway` (only what you need).

Triage EVERY row below in one cheap run each, classify it as (a) standing NO-GO / ACCEPTED (name the entry, and say if the run still shows the recorded diff shape), (b) network/harness-limited, or (c) LIVE lead, then go deep only on (c):
- avm1: `edittext_set_text_same`, `edittext_set_text_same_after_edits` (plain-text per-character format model, L), `amf0_array_matrix` (instanceof on an LC-received ECMA array), `localconnection_serialize_sparse_array_getters` (array addProperty enumerability), `localconnection_xml_unavailable`, `text_format_get_text_extent_own` (NEW upstream `0ddd12b6a..bcac30c19`), `movieclip_hittest_shapeflag`, `set_property_values/swf4`, `bitmap_data_thorough/pixelDissolve`, `date`, `stylesheet_load`, `load_vars`, `external_interface_monkeypatch`, `globals_monkeypatch`, `sandbox_type_remote`.
- from_gnash: `TextField-v6/v7/v8`, `argstest-v6/v7/v8`, `misc-ming.all/DrawingApiTest`, `register_class/RegisterClassTest4`, `misc-swfc.all/matrix_accuracy_test1`, `misc-swfc.all/sound`. (`GradientFillTest` and `MovieClip-v8` are owned elsewhere/NO-GO: skip.)
- from_shumway: `esc`, `bitmapdata/getpixel-from-embedded`.
- Lead **L1** (post-s23 runtime filters): the AVM1 `filters` GETTER for PlaceObject3-authored filters only resolves root-depth entries (`ng_objRootDepth`), so a filtered clip nested in a sprite reads back `[]`. Prove or refute with a hand-assembled probe (see `session23-fanout-reports/avm1-runtime-filters-probe/mkprobe.py` for an assembler); it needs a LOCAL ORACLE REQUEST for the expected trace.

For each LIVE lead: mechanism (`file:line`), priced flips, a measured prototype where cheap, and the rider sweep. Deliver a ranked GO list for wave 2.

Siblings: `w1-native-proto` owns `global_*`, `globals_swf5`, `native_objects_swf6`, `*_prototype_lazy*`, `lazy_prototype_shared`; `w1-attach-order` owns `action_order/*` and `MovieClip-v8`.
