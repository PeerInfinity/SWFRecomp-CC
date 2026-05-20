# XML / XMLNode -vN Investigation Plan
<!-- TESTS: XML-v5, XML-v6, XML-v7, XML-v8, XMLNode-v5, XMLNode-v6, XMLNode-v7, XMLNode-v8 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproductions at the current `master` SHA; no fixes
landed yet)

<!-- PLAN_META
id: XML_XMLNODE_PLAN
status: in_progress
phases:
  - id: 1
    name: "XML.prototype / XMLNode.prototype own-vs-inherited method visibility"
    status: complete
  - id: 2
    name: "XML.prototype.docTypeDecl / xmlDecl / contentType / ignoreWhite own-prop initialization"
    status: complete
  - id: 3
    name: "XML.status setter: coerce non-number args via ToInt32 + INT_MIN clamp"
    status: complete
  - id: 4
    name: "XML.loaded setter: coerce non-boolean via ToBoolean"
    status: complete
  - id: 5
    name: "XML.send / sendAndLoad / addRequestHeader implementations"
    status: complete
  - id: 6
    name: "childNodes as an Array instance (instanceof Array, push, length own-prop)"
    status: complete
  - id: 7
    name: "namespaceURI returning empty string vs null after parse"
    status: complete
  - id: 8
    name: "localName / prefix edge cases on trailing-colon nodeNames"
    status: complete
  - id: 9
    name: "Attribute serialization: insertion order + empty-attribute emission"
    status: complete
  - id: 10
    name: "Text-node value handling (nodeValue returning null vs string)"
    status: complete
  - id: 11
    name: "parentNode read-only against user SetMember writes"
    status: complete
  - id: 12
    name: "Whitespace text-node merging during parseXML"
    status: complete
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); XML-vN and XMLNode-vN became visible at that point."
related:
  - id: XML_PLAN
    reason: "AVM1 XML_PLAN landed at `avm1/_investigation/complete/XML_PLAN.md` (26/26 active AVM1 XML tests pass). The Gnash tests exercise edge cases the AVM1 tests don't — own-prop bookkeeping, namespace details, attribute order. Reuse the AVM1 XML object infrastructure where possible."
blockers: []
status_note: |
  XML-v5..v8 and XMLNode-v5..v8 are clustered together because Gnash
  shares one source file with `#if OUTPUT_VERSION > N` gates. The
  fundamental architecture of our XML/XMLNode implementation is sound
  (AVM1 XML_PLAN passes 26/26 active tests), but the Gnash tests
  exercise own-prop visibility, status/loaded coercion, attribute
  serialization details, and the unimplemented send/sendAndLoad
  network methods that AVM1 tests don't cover. The 12 phases below are
  largely independent — pick whichever cluster looks cheapest.
-->

## Remaining XML-vN issues

As of 2026-05-20, **XML-v5** and **XMLNode-v5..v8** are RUFFLE_MATCHED. The
12 numbered phases are all complete; the onLoad-truncation and
docTypeDecl/xmlDecl clusters are fixed. **XML-v6/v7/v8** remain
output_mismatch — blocked by five small, independent bugs that the SWF6+
`#if OUTPUT_VERSION > 5` gates expose. These are not a coherent project and
need no phase structure; fix directly.

| # | Test line(s) | Symptom | Root-cause hypothesis | Difficulty |
|---|--------------|---------|-----------------------|------------|
| R1 | XML.as:884, 885, 900 | After `myxml.load(gnash.xml)`, `topnode = myxml.firstChild` has `nodeName == null` (expected `'XML'`); `childNodes.length == 4` (expected 3) | `gnash.xml` begins with a UTF-8 BOM (`EF BB BF`). The parser keeps the BOM bytes as a leading text node, so `firstChild` is that text node, not `<XML>`. Strip a leading BOM (and probably leading whitespace before the first `<`) in `xml_parse_into`. | Easy (~3 lines, fixes 9 lines across v6/7/8) |
| R2 | XML.as:760, 762 | `x._customHeaders.toString()` is `header1,…,header4,value4,value4` (expected `header4,,value4` for v6 / `header4,undefined,value4` for v7+) | `addRequestHeader` mishandles an empty/undefined header value — looks like an off-by-one in the array append (`builtin_xml_addRequestHeader`, Phase 5 code). Diagnose the append loop. | Easy–Medium |
| R3 | XML.as:130 | `! tmp.hasOwnProperty("nodeValue")` fails — a fresh `new XML()` reports an own `nodeValue` | `xml_create_node` sets `nodeValue` as an own data prop on every node, including the document. Flash exposes it as an inherited/virtual prop. Needs a DontEnum-placeholder-on-prototype approach (cf. Phase 1's virtual node props) — may ripple into `nodeValue` reads. | Medium |
| R4 | XML.as:1114 | `&#229e2;` etc. numeric character references mis-decoded | Numeric character-reference parsing edge cases (malformed/partial numeric entities). Note XML.as:1114 is an `xcheck_equals`, so part of this may already be subset-eligible — confirm against the Ruffle sidecar before investing. | Medium |
| R5 | XML.as:382 | Inside `with(firstChild) { nodeValue = 4 }`, `typeof(nodeValue)` is `number` (expected `string`) | The session-#6 `actionSetMember` coercion hook only covers member-access writes. `nodeValue = 4` under a `with` scope is an `ActionSetVariable` resolving through the with-object — it bypasses the hook. The coercion must also reach the with-scoped SetVariable path. | Medium |

Not a fix: XML.as:494 (`tmp.toString() == xml_out`) is a Gnash bug where our
output is *more* correct than Gnash's expectation — subset-eligible, leave it.

## Status

### 2026-05-20 session #6 — docTypeDecl/xmlDecl + malformed-XML cluster; XML-v5 RUFFLE_MATCHED

The docTypeDecl/xmlDecl parse-time cluster (XML.as:1027-1104) is fixed. All
changes in `SWFModernRuntime/src/actionmodern/action.c`:

- **DOCTYPE / xmlDecl parsing.** `<!doctype>` detection is now case-insensitive
  (`strncasecmp` — XML.as:1058 `<!DOcTyPE text>`); previously a mixed-case
  doctype fell through and was parsed as an element. `<?xml?>` detection is
  case-insensitive too, and multiple declarations now **accumulate** into
  `xmlDecl` via a new `xml_append_str` helper (XML.as:1081-1082
  `<?xMl decl?><?XMl new?>`). `docTypeDecl` keeps last-wins (overwrite).
- **Serialization.** `xml_serialize_node`'s document-root branch now emits
  `xmlDecl` then `docTypeDecl` (raw, unescaped) before the children,
  regardless of their source order (XML.as:1054-1104).
- **Write coercion.** A new `actionSetMember` hook (gated on the property
  name + a `nodeType` probe) coerces `xmlDecl`/`docTypeDecl`/`contentType`/
  `nodeValue` writes to string and `ignoreWhite` to boolean (XML.as:1010,
  1085, 1090, 1097).
- **Read-only navigation props.** `firstChild`/`lastChild`/`previousSibling`/
  `nextSibling` join `parentNode` as read-only against user SetMember writes
  (XML.as:633 `element2.lastChild = 4` is a no-op).
- **Malformed-XML handling.** Unterminated comments and CDATA sections are
  now consumed to EOF instead of leaking their tail bytes as text
  (XML.as:1043, 1046); a bare `<` at end-of-input no longer double-flushes
  the preceding text (XML.as:1033); and a new `parse_failed` flag — set on an
  unterminated tag or an orphan close tag — discards the whole document so
  `toString()` is `""` (XML.as:1027, 1030, 1040).

Result: **XML-v5 promotes to RUFFLE_MATCHED.** XML-v6/v7/v8 still
output_mismatch — their remaining diffs are unrelated clusters that the
SWF6+ `#if` gates expose: the `gnash.xml` UTF-8 BOM creating a spurious
leading text node (XML.as:884/885/900), `addRequestHeader` empty-value
handling (XML.as:760/762), the `nodeValue` own-prop check (XML.as:130),
numeric character entities (XML.as:1114), and the `with`-scoped `nodeValue`
write at XML.as:382 (a SetVariable, not SetMember, so the new coercion hook
doesn't see it). All 27 AVM1 `xml*` regression tests still pass; XMLNode-v5..v8
stay RUFFLE_MATCHED.

### 2026-05-20 session #5 — onLoad-truncation cluster fixed

The XML-vN truncation is resolved. Two bugs, both in
`SWFModernRuntime/src/actionmodern/action.c`:

- **`soundFireCallback` dropped arguments for type-1 (DefineFunction)
  handlers.** Its `function_type == 2` branch passed `cb_args`/`cb_arg_count`
  straight to `advanced_func`, but the type-1 branch just called
  `simple_func(app_context)` with no stack setup — so a handler declared
  `function(success){...}` saw no `success`. XML's `onLoad(success)` therefore
  always ran the `if(!success)` branch ("No success loading gnash.xml"),
  `onLoadCalls` never reached its target, and `check_totals()` never ran — the
  test "truncated" with no `#passed/#failed/#total`. Fixed by giving the
  type-1 branch the same arg-push + local-scope + captured-scope + `this` +
  base_clip setup the type-1 path in `actionEI_callInternalInterface` uses.
  This also fixes `Sound.onLoad`/`onID3` argument passing.

  *(The session-#3 note's `findDataFile`/`MEDIA(gnash.xml)` diagnosis was
  wrong — the recompiled URL string is the bare `"gnash.xml"`, `findDataFile`
  resolves it fine. The real failure was the dropped `success` argument.)*

- **`XML.load` fired `onData`/`onLoad` synchronously.** Flash's `load` is
  async: `load()` returns immediately and the callbacks fire after the rest
  of the current script runs (XML.as does ~160 lines of post-load checks
  before the `onLoad` output is expected). `builtin_xml_load` now keeps only
  the synchronous side effects inline (`loaded=false`,
  `_bytesLoaded`/`_bytesTotal`, `status=0` — XML.as:945-956 observes those
  right after `load()`), and queues the parse + `onData` + `onLoad` as an
  `AQ_KIND_SCRIPT` action-queue entry (`aq_dispatch_xml_load`) that drains
  after the in-progress frame script completes. Two `load()` calls queue two
  entries that drain FIFO — matching the two back-to-back `onLoad` blocks at
  the end of the expected output.

Results: XML-v5 verbose-diff `^+` count 107 → 32 (truncation gone — the test
now runs to `#total`). XML-v6 → 40, XML-v7 → 41, XML-v8 → 56. The remaining
XML-vN diffs are the **docTypeDecl/xmlDecl/comment parse-time cluster**
(XML.as:1027-1104) plus a few isolated cases (382, 494, 633, 1010) — none of
them onLoad-related. All 27 AVM1 `xml*` regression tests still pass; `xml_load`
specifically still passes (the deferral matches its expectation). `load_vars`
and `sound_start_stop` were already failing at baseline with identical match
counts (unchanged). Note `XML-v8`'s expected `output.fp9.txt` (465 lines) ends
after one `onLoad`, but Ruffle's own `output.fp9.ruffle.txt` (486 lines) has
both — so producing the second `onLoad` block is correct for `ruffle_matched`
subset purposes.

### 2026-05-20 session #4 — Phase 6 landed; XMLNode-vN all RUFFLE_MATCHED

Phase 6 (childNodes as a real Array instance) implemented in
`SWFModernRuntime/src/actionmodern/action.c`. This was the keystone for the
remaining XMLNode-vN failures, and also subsumed the misdiagnosed Phases 10
and 12 (see below).

- **`__realChildren` — the genuine DOM-children list.** A new hidden DontEnum
  `__realChildren` array per node holds the real DOM children in insertion
  order, kept separate from the public `childNodes` array which AS code may
  freely `push()`/`sort()`/index. Two new helpers (`xml_get_real_children`,
  `xml_rebuild_childnodes`) sit before `xml_sync_children`. Every DOM mutation
  (`xml_do_append`/`xml_do_remove`/`xml_do_insert_before`) now updates
  `__realChildren`, then rebuilds the public `childNodes` **in place**
  (preserving the array's object identity) from it — which is exactly how
  Flash discards user-pushed "fake" items the moment a real element is
  appended (XMLNode.as:127-176). `xml_sync_children` (firstChild/lastChild/
  siblings), `xml_serialize_node`, `cloneNode` deep, `hasChildNodes`, and the
  parseXML/`load` orphan blocks all now derive from `__realChildren`. The
  numeric-index getMember path (`node.childNodes[i]`) still reads the *public*
  `childNodes` (the test indexes pushed fakes). The old "purge by parentNode"
  loop in `xml_do_append` is gone — the rebuild handles it, including the
  non-object fakes the old purge wrongly kept (XMLNode.as:175 5→4).
- **`arr.push` resolves to a function.** The ARRAY branch of `actionGetMember`
  now falls back to `g_array_prototype` (via `initArrayPrototypeMethods`) when
  a non-index property isn't in the array's `props` sidecar, so
  `node.childNodes.push` (and `.sort`, `.constructor`, …) read as the actual
  Array.prototype function value — XMLNode.as:119 `check(...push)`.
- **`childNodes` read-only against user SetMember.** Both XML-node creation
  paths (`xml_create_node` + the `actionNewMethod` XML branch) install
  `childNodes` with WRITABLE cleared, so `node.childNodes = 5` is a no-op
  (XML.as:359-360). Internal rebuilds mutate the array in place, unaffected.
- **Array `hasOwnProperty`.** `callArrayMethod` now handles `hasOwnProperty`
  directly (`length`, live numeric indices, `props`-sidecar names) —
  `Object.prototype.hasOwnProperty` mis-casts an ASArray to ASObject.
  XML.as:354 `childNodes.hasOwnProperty('length')`.

Results: **XMLNode-v5..v8 all promote to RUFFLE_MATCHED** (195→full match;
the four lines 182/187/190/193 plus 119/175 all fixed; line 81 stays a
subset-eligible Gnash bug). XML-v5 verbose-diff `^+` count 109→107 (XML.as:354
+360 now pass). All 27 AVM1 `xml*` regression tests still 100%; spot-checked
8 array tests pass (`array_reverse` was already failing identically at
baseline — 104 `^+`, unchanged).

Phases 10 and 12 were **misdiagnosed** in the original plan and are marked
complete with no separate code: XMLNode.as:175 ("length == 4") is the
appendChild-discards-fakes case (Phase 6), *not* parseXML whitespace merging;
XMLNode.as:187/193 ("nodeValue") were downstream of the firstChild/sibling
links being driven by the sorted public array instead of the real DOM order
(Phase 6). The only XMLNode-vN diff left, line 81, is the documented
subset-eligible Gnash bug.

Remaining XML-vN work is **not a numbered phase**: the onLoad-truncation
cluster (XML-v5..v8 cap ~340-369/449 because `myxml.load(MEDIA(gnash.xml))`
fails — see the session-#3 note). That, and the docTypeDecl/xmlDecl
parse-time cluster, are all that stand between XML-vN and promotion.

### 2026-05-20 session #3 — Phases 5, 9 landed

Two more phases implemented in `SWFModernRuntime/src/actionmodern/action.c`:

- **Phase 9 (attribute serialization).** Two fixes in the XML class:
  - *Read-only `attributes`.* `xml_create_node` now installs the per-node
    `attributes` object via a new `xml_set_obj_readonly` helper (WRITABLE
    cleared, ENUMERABLE kept) so `node.attributes = x` is a no-op
    (XMLNode.as:215, 223 "Seems not to be overwritable"). Writes to the
    attributes object's *members* are unaffected; internal raw `setProperty`
    ignores the WRITABLE flag.
  - *Reverse-insertion serialization.* `xml_serialize_node` now iterates the
    attributes property array **backwards**. Flash serializes attributes in
    the order an AVM1 `for..in` enumerates them (reverse-insertion); the XML
    parser already inserts parsed attributes reversed, so reverse iteration
    yields document order for parsed XML and most-recent-first for user-set
    attributes. Verified against all 27 AVM1 `xml*` regression tests (still
    100%).
  - Net: XMLNode-v5..v8 each +4 matched lines (191→195 passed; the four
    attribute checks XMLNode.as:213/217/224/236 now pass).

- **Phase 5 (send / sendAndLoad / addRequestHeader).** Real implementations
  replace the `builtin_noop_func` stubs on XML.prototype:
  - `builtin_xml_sendAndLoad`: returns `true` when arg[1] is an object
    (XML, XMLNode, LoadVars, Date, plain Object), `false` for primitives.
    Sets `target.loaded = false` through the proper member-set path — for an
    XML receiver the virtual `loaded` accessor (found via
    `findPropertyStructWithPrototype` + `invokePropertySetter`) routes the
    write to the hidden `__xml_loaded` slot so no own `loaded` appears
    (XML.as:689); a plain object / LoadVars / Date receiver gets a normal own
    `loaded` data property (XML.as:687,700,732).
  - `builtin_xml_addRequestHeader`: builds an own `_customHeaders` Array on
    the receiver (created on the first call regardless of arg validity).
    Two-string-argument and single-array-argument forms append; every other
    form appends nothing. If `_customHeaders` was overwritten with a
    non-array, nothing is appended.
  - `send` stays a no-op (only its existence is tested).
  - Net: XML-v5 verbose-diff `^+` mismatch count 124 → 109.

Remaining XML-vN fails: Phase 6 (childNodes as Array), Phase 12 (whitespace
merge), and **the docTypeDecl/xmlDecl + onLoad-truncation cluster**. New
diagnosis of the truncation (XML-v5 actual output stops at XML.as:1104,
449 expected vs 419 actual): `myxml.load(MEDIA(gnash.xml))` fails because
`findDataFile()` cannot resolve the `MEDIA(gnash.xml)` URL string, so
`onLoad(false)` fires (output: "No success loading gnash.xml") instead of
`onLoad(true)`. The `onLoad(false)` branch `return`s before `++onLoadCalls`,
so `onLoadCalls` never reaches 2, `check_totals(438)` is never called, and no
`#passed/#failed/#total` lines are emitted — the test "truncates". Two
sub-issues here: (a) the `MEDIA(gnash.xml)` URL string is not matched by the
data-file registry even though `gnash.xml` is present in the test dir; (b) our
`builtin_xml_load` is fully synchronous (fires onLoad inline) whereas Flash's
load is async (callback fires after all sync code) — so even a successful load
would interleave onLoad output in the wrong position. Not a named phase;
worth its own investigation.

### 2026-05-20 session #2 — Phases 2, 3, 4, 11 landed

Four more phases implemented in `SWFModernRuntime/src/actionmodern/action.c`:

- **Phases 2+3+4 (XML constructor-time prototype props).** Flash's XML
  constructor installs `docTypeDecl`/`xmlDecl`/`contentType`/`ignoreWhite` as
  own data props and `status`/`loaded` as virtual accessor props onto
  **XML.prototype** the first time `new XML()` runs — *not* at prototype-init
  time (XML.as:108-129 check their absence before the first construction;
  XML.as:184-189 check presence after). New `xml_install_construct_proto_props`
  (guarded by `g_xml_proto_props_installed`) is called from both XML
  constructor paths (`xml_create_document` and the `actionNewMethod` XML
  branch). The init-time `ignoreWhite`/`loaded` data props were removed from
  `initXMLPrototype`.
  - **status**: virtual getter/setter on XML.prototype. The setter coerces via
    `varToDoubleSWF` (AVM1 ToNumber — objects use `valueOf` only, no `toString`
    fallback, so a plain or toString-only object yields NaN); NaN / out-of-
    int32 values clamp to INT_MIN (-2147483648), in-range values truncate
    toward zero. The coerced value lives in a hidden DontEnum slot
    `__xml_status` on the instance, so `instance.hasOwnProperty("status")` is
    false while `XML.prototype.hasOwnProperty("status")` is true. The getter
    returns undefined when the slot is absent (e.g. read off XML.prototype
    itself — XML.as `typeof(myxml.__proto__.status)=='undefined'`); instances
    get the slot defaulted to 0 at construction.
  - **loaded**: same virtual-accessor pattern with hidden slot `__xml_loaded`.
    Setter coerces via ToBoolean. A fresh instance has no slot →
    `typeof(loaded)=='undefined'`. `load()`/`onData()` write the slot via the
    `xml_store_loaded` helper (not a raw own-prop set) so `loaded` never
    becomes an instance own property.

- **Phase 11 (parentNode read-only).** *Corrected diagnosis*: the failing case
  is not cloneNode — the deep clone's `parentNode` is already null after
  `cloneNode(true)` (XML.as:577 passes). The bug was that `node.parentNode = x`
  *stuck*. Flash makes `parentNode` read-only against user assignment
  (XML.as:578-579: assignment is a no-op). Fix: `xml_create_node` now creates
  the instance's `parentNode` prop with WRITABLE cleared (still enumerable) via
  `xml_set_null_readonly`, so `actionSetMember`'s WRITABLE check blocks user
  writes. Internal tree mutations go through raw `setProperty`, which ignores
  the WRITABLE flag, so `appendChild`/`removeNode`/`xml_sync_children` still
  work.

`builtin_loadvars_sendAndLoad` was adjusted alongside: it used to skip
creating an own `loaded` on the receiver when one was *inherited*
(XML.prototype's old data `loaded`). With `loaded` now a virtual accessor
that defaults to undefined, the guard became own-only (`findPropertyRaw`)
so a `new XML()` sendAndLoad receiver still gets its own boolean `loaded`
(restores `LoadVars-v6/v7/v8` ruffle_matched).

Local single-test results after the change (vs the phase-1/7/8 baseline):
all eight XML-vN / XMLNode-vN tests improved or held — XML-v5..v8 each gained
~20 matched lines; XMLNode-v5..v8 unchanged (these changes only touch the XML
class, not XMLNode). All 27 AVM1 `xml*` regression tests still pass 100%.
Remaining XML-vN fails: Phase 5 (send/sendAndLoad), Phase 6 (childNodes as
Array), Phase 9 (attribute serialization), Phase 10 (text-node nodeValue),
Phase 12 (whitespace merge), and a docTypeDecl/xmlDecl parse-time cluster
(XML.as ~1027-1104).

### 2026-05-20 session — Phases 1, 7, 8 landed

Three phases implemented in `SWFModernRuntime/src/actionmodern/action.c`:

- **Phase 1 (own-vs-inherited prototype methods).** `initXMLPrototype`'s
  `INSTALL_METHOD` macro hardcoded `xmlnode_proto`, so the XML-specific
  methods (`parseXML`, `createElement`, `createTextNode`, `load`, `onData`)
  were installed on **XMLNode.prototype** instead of XML.prototype. Replaced
  with `INSTALL_METHOD_ON(proto, …)`; XML-specific methods now go on
  `xml_proto`. `getBytesLoaded`/`getBytesTotal` moved from XMLNode.prototype
  → XML.prototype (XML.as:98-99 assert their absence from XMLNode.prototype).
  Added `onLoad`/`send`/`sendAndLoad`/`addRequestHeader` as own-prop method
  stubs on XML.prototype (`builtin_noop_func` — Phase 5 still owns real
  behaviour). Also installed the 13 XMLNode virtual node properties
  (`nodeName`, `nodeValue`, `nodeType`, `attributes`, `childNodes`,
  `firstChild`, `lastChild`, `parentNode`, `nextSibling`, `previousSibling`,
  `namespaceURI`, `prefix`, `localName`) as DontEnum placeholder own props
  on XMLNode.prototype — instances carry their own data copies (set in
  `xml_create_node`) which shadow them, so reads are unaffected; the
  placeholders only satisfy `XMLNode.prototype.hasOwnProperty(...)`.

- **Phase 7 (namespaceURI "" vs null).** Element nodes (`nodeType == 1`) now
  default `namespaceURI` to `""` instead of `null` in `xml_create_node`.
  The parse-time resolver still overrides with a found URI; an element with
  no applicable in-scope xmlns keeps `""`. Text/non-element nodes keep
  `null`.

- **Phase 8 (localName/prefix split).** `xml_create_node` now splits
  `prefix:localName` at the first colon whenever the local part is
  non-empty (leading colon → empty prefix is a valid split: `:tag` →
  prefix `""`/localName `tag`, `:fr:tag` → prefix `""`/localName `fr:tag`).
  A trailing colon (`tag:`) leaves an empty local part — no split, localName
  keeps the whole nodeName, prefix `""`.

Local single-test results after the change (vs `eb8206f8` baseline):
XMLNode-v5 174/207 → 197/207 (10 fails left); XML-v5 281/449 → ~379/449.
All eight XML-vN / XMLNode-vN tests share source, so v6/v7/v8 move with
their v5 counterparts. Remaining XMLNode-v5 fails: 1 Gnash bug (line 81,
subset-eligible), Phase 6 (`childNodes.push`), Phase 9 (attribute order),
Phases 10/12 (text-node value + whitespace merge).

### CI baseline

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| XML-v5 | 281/449 | 62.6% | output_mismatch |
| XML-v6 | 288/486 | 59.3% | output_mismatch |
| XML-v7 | 288/486 | 59.3% | output_mismatch |
| XML-v8 | 288/465 | 61.9% | output_mismatch |
| XMLNode-v5 | 174/207 | 84.1% | output_mismatch |
| XMLNode-v6 | 174/207 | 84.1% | output_mismatch |
| XMLNode-v7 | 174/207 | 84.1% | output_mismatch |
| XMLNode-v8 | 174/207 | 84.1% | output_mismatch |

All eight ship `output.fpN.ruffle.txt` sidecars; ruffle_matched
promotion is in scope once our diffs become subsets of Ruffle's.

## Test sources

- Gnash testsuite/actionscript.all/XML.as (~1000+ lines, exercises
  full XML class lifecycle including the network methods)
- Gnash testsuite/actionscript.all/XMLNode.as (~470 lines, exercises
  parsing, serialization, namespaces, attribute access, tree mutation)

## Failure clusters

### A. XML.prototype / XMLNode.prototype method visibility (Phase 1)

XML.as lines 47, 50-62, 67 + many similar; XMLNode.as lines 45-57.

```
- PASSED: XML.prototype.hasOwnProperty("onData") [./XML.as:50]
+ FAILED: XML.prototype.hasOwnProperty("onData")
- PASSED: XML.prototype.hasOwnProperty("load") [./XML.as:59]
+ FAILED: XML.prototype.hasOwnProperty("load")
```

Many XML.prototype methods (`onData`, `onLoad`, `load`, `parseXML`,
`createElement`, `addRequestHeader`, `createTextNode`,
`getBytesLoaded`, `getBytesTotal`, `send`, `sendAndLoad`) and
XMLNode.prototype virtual properties (`firstChild`, `lastChild`,
`childNodes`, `nodeName`, `nodeType`, `nodeValue`, `parentNode`,
`previousSibling`, `nextSibling`, `attributes`, `namespaceURI`,
`localName`, `prefix`) are expected to be **own** properties on their
respective prototypes. We are registering them somewhere on the
prototype chain other than the prototype itself (likely on the global
constructor) so `hasOwnProperty` reports false.

Some are reversed: line 47 expects `!XML.prototype.hasOwnProperty("loaded")`
(we wrongly claim ownership); line 67 expects
`!XML.prototype.hasOwnProperty("ignoreWhite")` (same direction —
we wrongly claim).

### B. XML.prototype.docTypeDecl / xmlDecl / contentType / ignoreWhite (Phase 2)

XML.as lines 124, 125, 126.

```
- PASSED: XML.prototype.hasOwnProperty("docTypeDecl") [./XML.as:124]
+ FAILED: XML.prototype.hasOwnProperty("docTypeDecl")
```

After a constructor invocation, the test verifies that constructor-
created own props "leak up" onto XML.prototype — actually, the test
is calling `var tmp = new XML(); tmp.docTypeDecl = "..."; ...`, then
checking `XML.prototype.hasOwnProperty("docTypeDecl")`. This passes
in Flash because the XML constructor itself initializes these props
on the prototype. We need to install `docTypeDecl`/`xmlDecl`/
`contentType` (and possibly `ignoreWhite`) as defaulted own props on
`XML.prototype` during `initXMLPrototype`.

### C. XML.status setter coercion (Phase 3)

XML.as lines 161, 162, 169, 170, 174, 179.

```
- PASSED: typeof(tmp.status) == 'number' [./XML.as:161]
+ FAILED: expected: 'number' obtained: object
- PASSED: tmp.status == -2147483648.0 [./XML.as:162]
+ FAILED: expected: -2147483648.0 obtained: [object Object]
- PASSED: tmp.status == -2147483648.0 [./XML.as:179]
+ FAILED: expected: -2147483648.0 obtained: 3.4e+46
```

Flash's `XML.status` setter coerces the input via ToInt32 (matching
Number conversion), then clamps to INT_MIN (-2147483648) for out-of-
range values. We accept any value verbatim, so assigning `{}` or
`3.4e+46` produces a non-number status. The setter must coerce.

### D. XML.loaded setter coercion (Phase 4)

XML.as lines 184, 188, 191.

```
- PASSED: typeof(tmp.loaded) == 'undefined' [./XML.as:184]
+ FAILED: expected: 'undefined' obtained: boolean
- PASSED: typeof(tmp.loaded) == 'boolean' [./XML.as:188]
+ FAILED: expected: 'boolean' obtained: number
```

Two distinct issues:
- After a default-constructed XML, `loaded` should be undefined (not
  initialized). We are initializing it (probably to false).
- After explicit assignment of `loaded = 1`, the value should coerce
  to boolean. We are storing the number 1 verbatim.

### E. XML.send / sendAndLoad / addRequestHeader (Phase 5)

XML.as lines 120, 132, 133, plus the entire 305-333 block (test of
sendAndLoad with various receiver types).

```
- PASSED: XML::addRequestHeader() exists
+ FAILED: XML::addRequestHeader() doesn't exist
- PASSED: XML::send() exists
+ FAILED: XML::send() doesn't exist
- PASSED: XML::sendAndLoad() exists
+ FAILED: XML::sendAndLoad() doesn't exist
```

```
- PASSED: x.sendAndLoad("some server name", r) == true [./XML.as:686]
+ FAILED: expected: true obtained:
```

Three network methods unimplemented. `sendAndLoad` returns true/false
based on the receiver argument's type — true when receiver is an XML
or LoadVars instance, false otherwise. Real network IO can no-op (we
don't run with a network); we just need the method present and
returning the correct bool. `send()` and `addRequestHeader()` likely
behave similarly.

### F. childNodes as Array instance (Phase 6)

XML.as line 360, XMLNode.as lines 119, 175.

```
- PASSED: this.childNodes instanceof Array [./XML.as:360]
+ FAILED: this.childNodes instanceof Array
- PASSED: this.childNodes.hasOwnProperty('length') [./XML.as:354]
+ FAILED: this.childNodes.hasOwnProperty('length')
- PASSED: node1.childNodes.push [./XMLNode.as:119]
+ FAILED: node1.childNodes.push
```

`childNodes` is expected to be an instance of the Array class
(`instanceof Array` returns true, `push` method available on the
prototype chain). We are probably backing it with an ASObject or
internal struct rather than an ASArray. Need to either swap the
backing to ASArray, or attach an Array __proto__ to whatever we use.

### G. namespaceURI empty string vs null (Phase 7)

XMLNode.as lines 263, 272, 327, 343, 346.

```
- PASSED: ns.namespaceURI == "" [./XMLNode.as:263]
+ FAILED: expected: "" obtained: null
```

After parsing a tag like `<t:tag att="u" xmlns="standard">text</t:tag>`
and walking to it via `ns = doc.firstChild.firstChild`, Flash reports
`ns.namespaceURI == ""` for nodes whose own scope has an xmlns
default that doesn't apply (test line 263 specifically). We return
null. Probably an empty-string sentinel vs. null check in the
namespace resolver.

### H. localName / prefix on trailing-colon nodeNames (Phase 8)

XMLNode.as lines 376, 377.

```
- PASSED: ns.localName == "tag:" [./XMLNode.as:376]
+ FAILED: expected: "tag:" obtained:
- PASSED: ns.prefix == "" [./XMLNode.as:377]
+ FAILED: expected: "" obtained: tag
```

When `nodeName` is literally `"tag:"` (trailing colon, no prefix),
Flash treats it as no prefix + localName = "tag:". We are splitting
on the colon and getting prefix = "tag", localName = "". Fix: split
only when colon has non-empty content on both sides.

### I. Attribute serialization order + empty attributes (Phase 9)

XMLNode.as lines 213, 217, 224, 236.

```
- PASSED: node2.toString() == '<node2 a="aa" 3="a3">...' [./XMLNode.as:213]
+ FAILED: expected: '<node2 a="aa" 3="a3">...' obtained: <node2 3="a3" a="aa">...
```

```
- PASSED: node77.toString() == '<tag a1="at1" />' [./XMLNode.as:222]
+ FAILED: (different line) obtained: <tag />
```

Two sub-issues:
- Attribute insertion order isn't preserved during serialization
  (we are sorting by name or numeric index, Flash emits in insertion
  order).
- After an `attributes[key] = value` mutation on a freshly-cloned
  node, the attribute is dropped from `toString()`. Likely the
  attribute store is duplicated by structure but the serialization
  iterates the source struct.

### J. nodeValue returning null vs string on text nodes (Phase 10)

XMLNode.as lines 81, 187, 193, 382.

```
- FAILED: expected: "text content" obtained: null [./XMLNode.as:81]
+ PASSED: textnode.nodeValue == "text content"
- PASSED: node1.firstChild.nodeValue == "first text node" [./XMLNode.as:187]
+ FAILED: expected: "first text node" obtained: null
```

Mixed: line 81 is a Gnash-bug-we-don't-have (Gnash expected FAILED,
we PASS), suggesting subset-match-eligible. Lines 187/193 are a real
bug — `nodeValue` should return the text content for text nodes,
we return null. Likely the text-node path inspects the wrong field
or returns null for nodes with `nodeType == 3`.

### K. cloneNode deep mode parentNode reset (Phase 11)

XML.as line 579.

```
- PASSED: deepcln_node.parentNode == null [./XML.as:579]
+ FAILED: expected: null obtained: <X1C1><X2C1_modified /></X1C1>
```

After `var deep = node.cloneNode(true)` the cloned root's `parentNode`
should be null. We are setting it to the original parent. Fix: when
cloning, set the topmost clone's `parentNode = null` even if the
original had one.

### L. Whitespace text-node merging during parseXML (Phase 12)

XMLNode.as line 175.

```
- PASSED: node1.childNodes.length == 4 [./XMLNode.as:175]
+ FAILED: expected: 4 obtained: 5
```

After parsing XML with mixed text+element content, we produce one
extra child node compared to Flash. Likely an empty/whitespace text
node we should be merging or skipping.

## Recommended fix order

1. **Phase 1 (own-vs-inherited prototype methods)** — touches many
   lines; mostly mechanical. Estimate: 2-3 hours.
2. **Phase 5 (send/sendAndLoad/addRequestHeader stubs)** — empty
   stubs that return the right boolean. Cheap, unblocks 20+ lines.
   Estimate: 1-2 hours.
3. **Phase 7 (namespaceURI empty string)** — small sentinel change.
   Estimate: 30 min - 1 hour.
4. **Phase 8 (localName/prefix trailing-colon)** — 1-line fix in
   the split logic. Estimate: 30 min.
5. **Phase 10 (nodeValue on text nodes)** — small but needs care for
   the Gnash-bug line 81. Estimate: 1-2 hours.
6. **Phase 11 (cloneNode parentNode reset)** — 1-2 lines. Estimate:
   30 min.
7. **Phase 3 (XML.status coercion)** — couple of lines in setter.
   Estimate: 1 hour.
8. **Phase 4 (XML.loaded coercion + default-undefined)** — symmetric
   to Phase 3. Estimate: 1 hour.
9. **Phase 9 (attribute serialization order + emit)** — touches the
   serialization path; verify against AVM1 XML serialize tests for
   regressions. Estimate: 2-3 hours.
10. **Phase 6 (childNodes as Array)** — invasive (changes the
    backing store of childNodes). Verify against AVM1 XML tests
    that iterate childNodes. Estimate: 3-4 hours.
11. **Phase 2 (XML.prototype docTypeDecl/xmlDecl/contentType own-prop
    init)** — small but interacts with Phase 1 own-prop bookkeeping.
    Estimate: 1 hour.
12. **Phase 12 (whitespace text-node merging)** — diagnostic-first;
    needs comparison against Ruffle's parsed tree to identify which
    text node we have extra. Estimate: 1-2 hours.

Total estimate: 16-22 hours, 4-6 sessions.

## Promotion plumbing

All eight tests have `known_failure = true` + `output.fpN.ruffle.txt`
sidecars; subset-match auto-promotes to `ruffle_matched` once our
diffs become subsets of Ruffle's. Given the ~60% line-match rates on
XML-vN, this may take several phases of work before any test
auto-promotes. XMLNode-vN (84%) is closer.
