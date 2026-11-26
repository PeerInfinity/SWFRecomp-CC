**Disposition audit: the 12 UNSURE items of `SWFRecompDocs/plans/NO_GO_REGISTER.md` §4 (trace side 1–8) + stale
ACCEPTED rows (S per item; write it up AND fix what turns cheap).**

These are dispositions that s28's own FP32 evidence contradicts. Most FP32 outputs already exist on master under
`session28-fanout-reports/trace-provenance/` (named `<suite>__<test>.<variant>.txt`) and its table in
`trace-provenance.md`: read them before asking for a new capture. Items (register numbering):
1. `global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls`: ignore premise "golden ≠ Flash" vs TP
   "golden = Flash" (pinned new-stub capture byte-identical to the golden). Re-price the native-object enumeration
   model they share with `argstest-v6/7/8` and `native_objects_swf6` (order of native props on `_global`/prototypes).
   Is there a cheap subset? (It is an L NO-GO of record: attack it, do not assume it.)
2. `native_objects_swf6`: ACCEPTED "we match Flash" vs TP "golden = Flash, we differ by 1 line". Find the line.
3. `avm2/bom`: RvF framing wrong (TP: golden = Flash, -3/+3). What are the 3 lines? Fix if S.
4. `avm2/dependent_strings`: FP32 prints empty lines where Ruffle prints `ruffle::isDependent()` results. Are we already
   FP32-exact (then: flash_fixes candidate with the capture, RvF entry) or a cheap fix away?
5. `globals_swf5`: "costs 3 gnash passes" — under Flash-over-Ruffle, check whether those 3 gnash goldens are Flash
   (TP table) and whether the trade inverts. Price both sides by name.
6. `avm2/swz`, `avm2/loader_applicationDomain`: FP32 refuses the unsigned .swz with `Error #2044: Unhandled
   securityError … #2046` (3 lines, Linux == Windows; captures in trace-provenance/). The "AOT ceiling" disposition is the
   wrong target. Implement the Flash behaviour (signature check → securityError event / unhandled-error trace) if S–M,
   and make the two rows flash_fixes candidates (golden → FP32 output).
7. `tab_ordering_properties_tab_index_edge_case`: ACCEPTED "conflicting expectations", TP says golden = Flash. Decide by
   the captures and fix (w1b-rm-avm1-misc priced it S once decided).
8. `movieclip_hittest_shapeflag`: still output_mismatch after its flash_fix. FP32 returns `false` for 3 shapeFlag
   hitTests; check those 3 lines against our ACCEPTED_DIFFS lines for this test and against our output. Fix or
   re-disposition.
Also prune stale ACCEPTED_DIFFS / ignored_tests rows that now pass (`netstream_play_flv`, `deblocking`; `h263` is at 3
outliers — check whether it is within tolerance now). For every item deliver: verdict (fix / RvF / flash_fixes
candidate / keep NO-GO with new reopen criterion), the evidence path, and the doc edit (exact text). Implement the S fixes
in your patch with per-test before/after. FLASH requests only where no capture exists.
Siblings: w1-rm-avm1-gnash owns the other rm buckets; avoid native-object enumeration code edits unless you find an S
subset (then say so loudly in the report).
