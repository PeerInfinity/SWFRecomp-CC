# Session prompt — AVM2: the E4X/XML engine

You are implementing the **E4X/XML engine** for the AVM2 runtime — the
deferred plan named in `SWFRecompDocs/plans/avm2-support-plan.md` §5
("Later / separate plans"). Stage 4 is COMPLETE (tranches 1-3); this is
the largest remaining coherent unlock on the trace-test metric. Read the
plan first (§4 architecture, §5 stage notes), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then the
memories `avm2-stage4-tranche3` / `avm2-stage4-tranche2` /
`avm2-stage3-tranche1` (gotcha lists), then skim the code you are
extending:

- `SWFRecomp/src/abc/abc_emit.cpp` — you add **GetDescendants,
  CheckFilter, Dxns, DxnsLate** emission and stop bailing on
  **attribute multinames** (`mn->isAttribute()` currently forces the
  slow/abort paths; grep `isAttribute`).
- `SWFModernRuntime/{src,include}/avm2/` — 19-file runtime. You replace
  the XML/XMLList stubs (avm2_globals.c) with a real tree + property
  engine hooks, in new module(s) (suggested: `avm2_e4x.c` for the node
  tree/parser, `avm2_xml.c` for the classes; add both to
  verify_output.py's avm2 list — the one allowed edit there).

Tranche 3 landed at `7655bb69b`..`b355ae701`. CI baseline: **avm2
411/1200 (34.2%)**, run 29158224391; zero regressions anywhere;
wasm-link-smoke green. Census ceiling 1155/1163 with 124 ops
(`_investigation/TRANCHE3_OPS.txt`) — the ONLY remaining blocking ops
are GetDescendants (3 tests), CheckFilter (3), DxnsLate (1), all E4X.

## Goal

The E4X engine: XML/XMLList classes backed by a real node tree, the E4X
property semantics (child/attribute/descendant access through the
property engine), the four remaining ops, and the XML-adjacent leftovers.
Candidate list (55 names, statuses as of `b355ae701`):
`ruffle-tests/tests/swfs/avm2/_investigation/E4X_CANDIDATES.txt`
(xml_* 51, plus amf_xml, qname_as_lazy_name_attribute_multiname,
function_proto_created + number_autoconv — the last two need
describeType's XML output, so do describeType AFTER the XML core works).

Exit: **≥40 of the 55 candidates passing in CI; every miss triaged**;
zero pass→fail regressions anywhere (the avm2 411 baseline must stay
green). Known likely-triage members: xml_socket (XMLSocket networking),
xmldocument/xmlnode (legacy flash.xml.XMLDocument/XMLNode API — separate
class family; implement only if cheap on top of the tree),
xml_notification_bubbling (undocumented notification API — read the test
before writing it off).

## Prepared data — use it to sequence the work

- **Ruffle reference (local at ~/CC/ruffle), ~6.4k lines total**:
  `core/src/avm2/e4x.rs` (1819 — the node tree, parser bridge,
  is_xml_name, escaping, toXMLString with prettyPrinting),
  `object/xml_object.rs` (767) + `object/xml_list_object.rs` (1099 —
  the property-engine overrides: get/set/delete_property_local,
  has_property_via_in, call on lists, enumeration),
  `globals/xml.rs` (1367) + `globals/xml_list.rs` (659) +
  `globals/XML.as` (416) + `globals/XMLList.as` (299) (the method
  surface + AS3-side settings/prettyPrinting statics).
- **Ruffle parses with quick-xml** (`e4x.rs::parse`,
  `NsReader::from_str`). Hand-write a small C parser for the E4X subset
  instead (elements/attributes/text/CDATA/comments/PIs, the five
  standard entities + character refs, `ignoreWhitespace` /
  `ignoreComments` / `ignoreProcessingInstructions` settings semantics,
  error 1088 for mismatched tags — xml_mismatched_tag,
  xml_ignore_white, xml_weird_ignores test exactly this layer).
- **The property-engine hook pattern is already established**: tranche 3
  added Proxy/Dictionary interception via the `Resolved` struct in
  avm2_ops.c (resolve_mn/resolve_key mark special receivers; the
  get/set/call/delete paths dispatch). XML/XMLList receivers slot into
  the same seam. XML get falls back CHILD-ELEMENT lookup; attribute
  multinames (`@attr`) read attributes; `..name` is GetDescendants;
  `.*`/`@*` are any-name forms — the QName machinery from tranche 3
  (avm2_nsqname.c) already models any-ns/any-name, but
  **Avm2QNameExt has no is_attribute flag yet** — add one (the Proxy
  isAttribute stub in avm2_proxy.c returns false and must start
  honoring it; qname_as_lazy_name_attribute_multiname passes an
  attribute QName as a lazy name).
- **Namespaces**: avm2_nsqname.c's Avm2NamespaceExt (uri/prefix/kind) is
  the value type E4X needs everywhere (namespace()/inScopeNamespaces/
  setNamespace, xml_tostring_namespace). Dxns/DxnsLate set the METHOD
  BODY's default XML namespace — a per-activation value (emit as a local
  the body writes; DxnsLate pops the value at runtime).
- **AMF hook-up**: amf_xml expects writeObject(xml) → marker 0x0B
  XmlString with `toXMLString()` bytes (prettyPrinting respected) and
  readObject → XML.construct(string); avm2_amf.c's reader already
  constructs via xml_class — the writer's generic-object arm must gain
  an XML branch (see Ruffle amf.rs `as_xml_object` arm).
- **Equality**: xml_abstract_equality / xml_equals_namespace_check —
  abstract_eq gains XML/XMLList arms (deep tree compare; Ruffle
  value.rs + e4x.rs equals). xml_class_call: XML(x)/XMLList(x) call
  conversions (Ruffle CallHandler semantics).

## Deliverables (suggested order — commit at each observable checkpoint)

1. **Node tree + parser + toString/toXMLString** (xml_basic, xml_text,
   xml_tostring, xml_ignore_white, xml_mismatched_tag, xml_unescaping,
   xml_simple_complex_content, xml_nodekind): E4XNode {kind
   element/text/cdata/comment/PI/attribute, name (uri+local), attributes,
   children, parent}, XML.settings statics (prettyPrinting,
   prettyIndent, ignore* — xml_settings/xml_methods_settings),
   constructor from string/XML/null/undefined, toString (simple vs
   complex content) vs toXMLString.
2. **Property engine hooks + core navigation** (xml_child, xml_children,
   xml_attribute[_name], xml_as_attribute, xml_length, xml_parent,
   xml_elements, xml_wildcard, xml_list_*): child/attribute get-set-
   delete through resolve paths, XMLList as the result type of every
   query, list auto-conversion rules (1-element lists coerce like their
   element — xml_list_as_attribute), enumeration (for/for-each),
   hasOwnProperty/`in` (xml_hasownproperty, xml_has_property_via_in;
   note the XML/XMLList special case in Ruffle value.rs get_property —
   PUBLIC-ns method-trait hits on XML objects route through
   get_property_local first, that's the avmplus Toplevel.cpp quirk).
3. **Ops**: GetDescendants (+ lazy variants) → `..`, CheckFilter +
   the filter-expression body shape (`list.(cond)` compiles to a
   CheckFilter + per-item with-scope loop — look at a --dump-abc of
   xml_advanced), Dxns/DxnsLate + default-namespace resolution
   (xml_explicit_use_namespace, xml_namespace*, xml_no_namespace).
4. **Mutation + the method surface** (xml_appendchild[_swf_v21],
   xml_set_children, xml_set_name, xml_copy, xml_normalize, xml_delete,
   xml_child_index, xml_contains, xml_namespace_methods): appendChild/
   setChildren/setName/setNamespace/copy/normalize/replace/insertChild*,
   namespace()/namespaceDeclarations/inScopeNamespaces/addNamespace/
   removeNamespace, contains (== semantics), childIndex.
5. **Integration leftovers**: abstract equality arms, XML class call
   conversions, AMF writer XML arm (amf_xml), attribute-QName lazy names
   (qname_as_lazy_name_attribute_multiname), then **describeType**
   (function_proto_created + number_autoconv expect avmplus-shell
   describeType XML — build it on toXMLString once the tree exists).

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode); confirm
  zero pass→fail across ALL suites (incl. the avm2 411 baseline) and
  wasm-link-smoke green.
- **Conflict boundary**: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`, `RecompiledABC/` paths. Do NOT
  touch `SWFModernRuntime/src/actionmodern/action.c`. New src/avm2/*.c
  files go into verify_output.py `compile_native`'s avm2 list (the one
  allowed edit there). wasm-link-smoke builds AVM1 demos only — no
  workflow edit needed.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. The census tool and
  `--dump-abc` are local-safe.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Tranche-3 gotchas you must not trip over (see the memory for more)

- **Local iteration**: loop verify_output.py per test (~4 s warm via
  ccache); a batch loop greping `^Pass:` over the candidate list works.
- The recompiler must be REBUILT after abc_emit.cpp changes
  (`cd SWFRecomp/build && make -j8`) — verify_output only recompiles the
  runtime side; a stale SWFRecomp binary shows up as "unimplemented op"
  aborts for ops you just emitted.
- Fast/slow property-op split: our verifier marks Fast only when the ns
  set contains public; interpreter-mode bodies get fast SEMANTICS via
  the `interp` flag at runtime. Side-path checks (Dictionary object
  keys, XML lazy names if you add them) must honor that split — see
  dictionary_access_no_pubns for the probe pattern.
- Script-init bodies are interpreter-mode: loose test statements land
  there; class bodies (mxmlc `class {}` in frame scripts) don't.
- Before chasing an ordering diff, read the test's output.txt header —
  some expectations are hand-edited to Ruffle's HashMap iteration order
  and are unmatchable (json_stringify precedent) → triage.
- Expando names that parse as u32 enumerate as NUMBERS; deleted expandos
  tombstone (avm2_object.c) — don't "fix" either while adding XML
  enumeration.
- The `p.*` / `*::name` any-forms: multiname name index 0 = any name,
  ns index 0 = any namespace (mn_qname_parts in avm2_ops.c handles this
  for QName building — reuse it).
- GC: AVM2 allocations remain census-invisible/immortal; the XML tree
  should follow the same rule.

## End-of-session bookkeeping

- E4X landing note in `avm2-support-plan.md` §5 (new "E4X engine" bullet
  under Later/separate plans, or promote it to a stage entry).
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline; op
  set gains GetDescendants/CheckFilter/Dxns/DxnsLate — write a new
  E4X_OPS.txt = TRANCHE3_OPS + the four, and re-census; the ceiling
  should reach 1162-1163/1163).
- Update the `avm2-stage4-tranche3` / direction memories (E4X status;
  what's next — likely Stage 5 frame lifecycle + display basics, which
  unlocks the movieclip_*/displayobject_* families).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2/3/tranche-2/3
  convention).
