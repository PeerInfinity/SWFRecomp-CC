**AVM1 native builtin surface: prototypes and lazy prototypes** (trace; board `polish-sweep-arc.md` §24.4). Categories to download: `avm1` (plus `from_gnash` only if a rider needs it).

Rows (all failing on the s24 baseline): `avm1/global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls`, `globals_swf5`, `native_objects_swf6`, and the NEW upstream rows `lazy_prototype_shared`, `text_format_prototype_lazy` (both added in `0ddd12b6a..bcac30c19`), plus `video_prototype_lazy`, `video_prototype_lazy_swf6_child` (20/21, 4/8 at s23).

The board says: native builtin methods expose a `prototype`, which is cross-cutting, so price it as its own slot before anyone touches `setupNativeFuncOwnProps`. Deliver:
1. For each row, the diff shape and the owning mechanism (`file:line`). Is it ONE mechanism (native functions get no `prototype` / a lazily created, shared one) or several? Read the new upstream `test.as` sources and Ruffle's implementation (`core/src/avm1/function.rs`, `property_decl.rs`, the lazy-prototype commits in `0ddd12b6a..bcac30c19`) and say exactly what Flash does.
2. A measured prototype if the mechanism is cheap. RIDER RISK is the main cost here: every AVM1 row that enumerates, `hasOwnProperty`s or `delete`s a builtin is a rider. Run an argued sweep (≤ 40 rows: `globals_*`, `native_*`, `*_prototype*`, `assetnativeaccessor_ids`, `movieclip_default_state`, `textfield_props_swf*`, gnash `Function`/`Object`/`MovieClip` v6..8 known_failure rows; `pass → ruffle_matched` on a known_failure row is a REGRESSION) and report it per row, before/after.
3. GO/NO-GO with a priced flip list, and the exact scope of a wave-2 patch.

Siblings: `w1-avm1-tail` owns the other AVM1 rows; `w1-attach-order` owns timeline ordering. Nobody else edits the native-function setup.
