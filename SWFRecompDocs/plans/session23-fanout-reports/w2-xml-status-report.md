# w2-xml-status: AVM1 XML status codes + stop rule (M3), plus the AVM1 drift bundle (M1d, M1e, M6, M7, M8)

Session 23, wave 2 (implementation). Cloud worker, branch `fanout/w2-xml-status`.

**NEW files:** none in source. Deliverables only:
- `SWFRecompDocs/plans/session23-fanout-reports/w2-xml-status-report.md` (this file)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-xml-status.patch`

No new `.c`/`.h` files, no fixtures, no `render_canary_tests.txt` change.
Patch scope: `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/actionmodern/avm1_amf.c`, `SWFModernRuntime/src/libswf/ng_shared.c`, `SWFModernRuntime/include/libswf/tag.h`. There are no `SWFRecomp/` (recompiler) changes, so `--recompile` is not needed.

Base: origin/master `2f305eef`. Upstream tests were downloaded by `download_tests.sh` on 2026-11-21 at upstream master **`aa9f62a70`**, which is newer than the brief's `0ddd12b6a`. Categories: `avm1 from_gnash from_shumway text`. `$HOME/CC/SETUP_STATUS` was all OK (apt, Pillow, Dawn).

## 0. Verdicts: GO, +6 trace flips, 0 regressions

| Unit | Test | Verdict | Before (clean master) | After |
|---|---|---|---|---|
| M3 | `avm1/xml_status_mismatched_tags` | **GO, landed** | output_mismatch (brief: 40/63) | **PASS** |
| M7 | `avm1/file_reference_listeners_per_instance` | **GO, landed** | output_mismatch | **PASS** |
| M1d | `avm1/localconnection_serialize_inherited_array_indices` | **GO, landed** | output_mismatch (11/12) | **PASS** |
| M1e | `avm1/localconnection_reference_identity` | **GO, landed** | output_mismatch (2/5) | **PASS** |
| M6 | `avm1/shared_object_members_swf5` | **GO, landed** | output_mismatch (25/32) | **PASS** |
| M8 | `avm1/edittext_asfunction_case_insensitive` | **GO, landed**: the w1 HOLD is resolved, root cause below | output_mismatch (0/1) | **PASS** |

Every headline row is PASS in both `--mode=graphics` and no-graphics on the same box.

## EXPECTED-FLIP LEDGER (check CI against this)

**Trace axis, fail → pass (6):**
- `avm1/xml_status_mismatched_tags`
- `avm1/file_reference_listeners_per_instance`
- `avm1/localconnection_serialize_inherited_array_indices`
- `avm1/localconnection_reference_identity`
- `avm1/shared_object_members_swf5`
- `avm1/edittext_asfunction_case_insensitive`

**Trace axis, everything else:** no move. Must stay `ruffle_matched`:
- gnash `XML-v5..v8`, `XMLNode-v5..v8`, `NetConnection-v6..v8`;
- shumway `flash_net_SharedObject`;
- `avm1/asnative_instrument`.

**Pixel axis:** no move expected. No render code changed. The `ng_shared.c` edit is a pure refactor of the click hit-test, which is never on a render path.

Mode parity: per-test identical in graphics and no-graphics (§3).

## 1. Mechanisms (owner `file:line` on the patched tree)

### M3: XML parser status codes and the stop rule (`action.c` `xml_parse_into`, ≈19808)

- An end tag is now matched by name against the open element, case-sensitively, via the new static `xml_node_name_equals`.
  - On a match, the element is popped.
  - On a mismatch, the status is −9 when the name matches the open element's **parent** (Ruffle's `open_tags.rev().nth(1)` rule) and −10 otherwise. This includes an orphan close, where nothing is open.
  - Either way the parse **stops**. `text_start` is synced so the trailing-text flush does not run, and the tree built so far is kept, with open elements implicitly closed.
- EOF with elements still open gives −9.
- The status is written through the existing `xml_store_status` (the hidden `__xml_status` slot that the `status` accessor reads). It is written at the end of every parse, so `parseXML` on a reused doc resets it to 0, as Ruffle does.
- **The gnash `XML.as:1040` reconciliation.** The orphan-close branch used to set `parse_failed`, which discarded the whole document. That branch is gone.
  - The gnash input at :1040 is `</open><open>node with "</open>`. I extracted it from `XML-v6/test.swf`'s constant pool.
  - Its orphan close is the very FIRST token, so stop-and-keep yields an empty tree, and `toString() == ""` still holds.
  - `foo</a>` keeps `foo`, as Flash does, and so does `<a></a></a>` → `<a />`.
  - `parse_failed` stays, unchanged, for the unterminated-tag/attribute cases (:1027, :1030).
- Status for those `parse_failed` cases is left untouched. Flash and Ruffle give −8/−6 there, which is not modelled; no corpus row grades it. That is a new lead, below.

### M7: per-instance `_listeners` for FileReference(List) (`action.c`)

- New static `filerefDefineOwnListeners`, next to `filerefInstallBroadcaster`. It defines a fresh, plain (enumerable, deletable) `_listeners` Array on the instance, matching Ruffle `2036a2eb2` `define_listeners(..., Attribute::empty())`.
- It is called from `actionNewMethod`'s native-ctor chain for `FileReference` and `FileReferenceList`, and from the `FileReference` super() handler.
- The prototype's `_listeners` keeps its DONT_ENUM|DONT_DELETE shape, so `global_proto_decls*` is unchanged. Deleting the own copy falls back to it, which the test grades.

### M1d: arrays enumerate inherited keys when AMF-written (`avm1_amf.c` `av_add_inherited`; accessor `action.c` `actionArrayProtoForAmf`)

- `w0_object_pairs` already walked the `__proto__` chain for objects (AVM1 for-in order); arrays did not.
- Now both array views (the `ASArray` view and the `NATIVE_ARRAY` ASObject view) append inherited enumerable keys:
  - nearest prototype first;
  - names already present are skipped;
  - `constructor`, `length` and `__proto__` are skipped.
- So an own HOLE whose index `Array.prototype` defines is written with the inherited value. This matches Ruffle's `serialize_array`, where `get_keys` walks the chain.
- I applied it to every transport, because Ruffle and our own object writer do the same; it is not LC-only. Inherited keys feed the existing shape decision, so a non-index inherited key demotes to an ECMAArray, as in Ruffle.

### M1e: LocalConnection reference table, sibling rule (`avm1_amf.c` reader)

- `Amf0Rd` gains a trailing `lc_refs` field. It is set ONLY by `avm1AmfDeserializeArg`, which is the LC delivery path. `avm1AmfReadValue` (NetConnection response bodies) keeps the old "table never populated" behaviour.
- With `lc_refs` on, `rd_ref_claim` really populates the table:
  - a DAG or cycle inside one top-level property resolves;
  - after each top-level property (depth 1) is read, the slots it claimed are hidden (set to undefined) from the later siblings;
  - the root, slot 0, stays visible.
- This is exactly Ruffle `6a6222860`'s `deserialize_local_connection_value`, which builds `local_connection_reference_cache(root, references_before_property)` with placeholders.
- `amf0_serde_suite` (the `ref_strict_is_exact: false` row the old comment cited) still PASSES.

### M6: SharedObject instance methods are VERSION_6 (`action.c` `initSharedObjectPrototype` tail, ≈41085)

- No new mechanism was needed. The version-gate bit already exists: `ASProperty.flash_flags` 0x0080 plus `isPropertyHiddenAtVersion`, the same bit `ASSetPropFlags(..., 128)` clears.
- After `avm1AmfInitSharedObject`, the seven prototype methods (`connect send flush close getSize setFps clear`) get `flash_flags |= 0x0080`. This follows Ruffle's `shared_object.rs` decls.
- Statics are untouched.

### M8: asfunction link click on a `createTextField` field (`action.c` `actionTextFieldDragEnd` Path 2; `ng_shared.c` `ng_getCharIndexAtPointFont`)

- **Root cause.** I instrumented the click. `actionTextFieldDragEnd` is reached, with `g_tf_drag_active=0`.
  - Path 1 (focused) is skipped because the drag-select setup only arms for static fields.
  - Path 2 filtered `mc->ng_textfield_idx < 0`, but a `createTextField` field is `-2` (`MC_IS_TEXTFIELD`, action.c ≈29143).
  - So the hit loop never examined the field, and `handle_asfunction` was never called.
  - `strncasecmp` was already on master.
- **Fix:**
  - Path 2 admits `-2` fields.
  - For them, the char index comes from the field's own format via the existing `extractTextFieldParams`, passed to a new `ng_getCharIndexAtPointFont(font_id, font_height, leading, left_margin, ...)`.
  - `ng_getCharIndexAtPoint(tf_idx, ...)` is now a thin wrapper over that core, with byte-identical behaviour for static fields.
  - Static fields take the unchanged code path.

## 2. Evidence: per-test before/after (same box, clean origin/master vs patch)

### Headline rows (graphics; no-graphics after = identical)

| Test | before | after (graphics) | after (no-graphics) |
|---|---|---|---|
| `avm1/xml_status_mismatched_tags` | MISMATCH | PASS | PASS |
| `avm1/file_reference_listeners_per_instance` | MISMATCH | PASS | PASS |
| `avm1/localconnection_serialize_inherited_array_indices` | MISMATCH | PASS | PASS |
| `avm1/localconnection_reference_identity` | MISMATCH | PASS | PASS |
| `avm1/shared_object_members_swf5` | MISMATCH | PASS | PASS |
| `avm1/edittext_asfunction_case_insensitive` | MISMATCH | PASS | PASS |

### Argued sweep: 213 rows, graphics before vs after, plus no-graphics after

The sweep covered these rows:
- **XML:** every avm1 `*xml*` row (42); gnash `XML`, `XMLNode` and `XMLSocket` `-v5..v8`; shumway `avm1/xml/{xmlbuild,xmlload,xmlstring}`.
- **FileReference:** every avm1 row whose SWF references `FileReference` (25), including `global_instance_decls`, `globals_*`, `native_objects_*` and `native_subclasses`.
- **AMF and transports:** every avm1 `amf*`, `localconnection*`, `netconnection*`, `shared_object*` and `external_interface*` row; gnash `LocalConnection-v5..v8` and `NetConnection-v5..v8`; shumway `flash_net_*` and `localconnection`.
- **SharedObject:** every avm1, gnash and shumway SWF that references `SharedObject` (26).
- **Links:** every input-driven row whose SWF carries `href`/`asfunction`/`htmlText`/`createTextField`, in avm1 and in `text/` (includes `text/links_in_scrolled_text`).
- **regression:** **all 68 non-AVM2 `regression/` rows**.

Results:
- **Graphics before→after:** exactly the 6 ledger rows move; nothing else changes status. Rows that stayed failing (`global_instance_decls`, `globals_monkeypatch`, `globals_swf5`, `native_objects_swf6`, `amf0_array_matrix`, `localconnection_serialize_sparse_array_getters`, `localconnection_xml_unavailable`, `external_interface_monkeypatch`) keep identical diff line counts.
- **One bogus row:** `regression/_results` is not a test (it is the results dir). It flips between RECOMP_FAIL and COMPILE_FAIL, which is noise.
- **Graphics after vs no-graphics after:** identical on every trace status. The only textual differences are 11 image-comparison rows, where my status scraper read blank in graphics mode because the `[image:…]` line comes first. Spot-check: `regression/mask_sibling_union` is a graphics PASS at 0 outliers. Those rows are A/B'd on pixels by the canary below.

### Render canary (A/B, md5)

- **Set:** the 40-row subset of `render_canary_tests.txt` whose suite I had downloaded (`avm1`, `from_shumway`, `regression`, `text`), plus the 11 image rows from the sweep.
- Nothing in this patch is on a render path, so no standing member could see it; I added no new member.
- **Result:** `render_canary.py compare before after` (each leg `capture --tests <subset> --timeout 5400 -P 2`) gave **40 tests / 75 comparisons: IDENTICAL 75, DIFFERS 0, APPEARED 0, VANISHED 0, NO_RENDER 0**, with no trace or image status changes. The md5 bar is met.
- **Not run:** the standing members in `avm2/`, `visual/` and `fonts/` (~57 rows). Their categories were not downloaded.

## 3. Refutations / premises attacked

- **"The orphan rule must be reconciled with gnash `XML.as:1040`; that is the S→M risk": REFUTED as a risk.**
  - The :1040 input starts with the orphan close, so Ruffle's and Flash's stop-and-keep rule already gives `""`.
  - The old whole-document discard and the new rule agree on every graded gnash row.
  - All 8 gnash XML/XMLNode rows stayed `ruffle_matched`.
- **"M8 is HOLD: the click → link dispatch never fires": REFUTED; the cause is a one-line filter plus a missing char-index source.** It was not the `mc_get_pixel_aabb_ng` char-index path the w1 report suspected: Path 2's `ng_textfield_idx < 0` filter dropped every `createTextField` field before the AABB test.
- **"M6 needs a version-gate property bit": the bit already exists** (`flash_flags` 0x0080, used by Object/String/Array VERSION_6 members). M6 was a 10-line tag.
- **"M1d: the LC strict writer reads holes through the prototype": broadened.** This is not an LC-strict rule. Arrays enumerate the prototype chain on every transport, which is what both Ruffle and our own object writer do. The LC strict/ECMA decision then falls out of the existing rule.

## 4. Not finished / HOLD

- **Full render canary (avm2/visual/fonts members).**
  - Completion mechanism: the coordinator's CI images run.
  - Expected: zero pixel moves, since no render-path code changed.

## New unclaimed leads

- **XML status for unterminated tags/attributes.** Flash and Ruffle give −8 for an unterminated attribute and −6 for a malformed element. We leave `status` unchanged on the `parse_failed` path (`xml_parse_into` tail). No corpus row grades it today.
- **`XML_STACK_MAX` = 64 nesting limit in `xml_parse_into`.** Deeper documents no longer push past 63, so their matching close tags now read as a mismatch and stop the parse with −10. Before this patch they silently mis-nested. This is pre-existing fragility with a new symptom. Make the stack dynamic if a real document ever nests that deep.
- **`avm1/global_instance_decls`: FileReferenceList/FileReference instance rows lack `_listeners`.**
  - Flash lists `_listeners, own, DONT_ENUM` for the FileReferenceList instance (line 47), while `file_reference_listeners_per_instance` says `isPropertyEnumerable("_listeners")` is true. Ruffle uses `Attribute::empty()`.
  - That test's construction path also does not seem to reach the `actionNewMethod` native-ctor chain: its instance rows show none of the hooks' properties.
  - The row is far from a flip (20/787 shown), so I left it alone.
- **The w1 report's leads are still open:** `amf0_array_matrix` (instanceof after an LC round-trip) and `localconnection_serialize_sparse_array_getters` (addProperty index enumerability).

## LOCAL ORACLE REQUESTS

none
