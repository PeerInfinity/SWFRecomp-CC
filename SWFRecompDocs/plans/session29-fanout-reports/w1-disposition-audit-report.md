# s29 w1-disposition-audit — NO_GO_REGISTER §4 trace items 1–8 + stale ACCEPTED rows

**New files:** this report; `w1-disposition-audit-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`,
5 files, +153/−8; sources reverted in the commit).
**Base:** `origin/master` `aa36d43aa` (code = `bfa47037b`). Upstream corpus downloaded 2026-11-26 (Ruffle master ≈ `b7ff32d93`,
my blobless clone made minutes later). Box: SETUP_STATUS all OK; every row run `--mode=graphics` (lavapipe), the 4 headline
rows also no-graphics. All "before" figures are the s29 baseline `results_graphics.json` (`014124ed5`), read per row.

## 0. Verdicts and priced flips (lead)

| # | row(s) | verdict | flip (measured, prototype) |
|---|---|---|---|
| 2 | `avm1/native_objects_swf6` | **FIX (S).** The ACCEPTED premise is refuted: golden = FP32, and the line is an SWF6 case-insensitive shadowing rule, not "Ruffle's test is inconsistent" | mm 114/115 → **pass** 115/115 |
| 5 | `avm1/globals_swf5` | **FIX (S). The trade does not exist.** The 3 gnash `-v5` goldens ARE FP32, and they still pass with the classes visible | mm 295/304 → **pass** 304/304; gnash `LocalConnection-v5`/`NetConnection-v5`/`Video-v5` stay pass |
| 7 | `avm1/tab_ordering_properties_tab_index_edge_case` | **FIX (S).** Not "conflicting": Flash has a sticky raw mode when the *first* tabIndex set is a string | **rm 1/4 → pass** 4/4; `tab_ordering_properties` stays pass 293/293 |
| 6 | `avm2/loader_applicationDomain`, `avm2/swz` | **FIX (M, landed in prototype) + 2 flash_fixes candidates.** Not an AOT ceiling: FP32 refuses any `digest` load with securityError #2046 | `loader_applicationDomain` output **== FP32 byte-exact** (pass once its golden is swapped); `swz` 0/2 → 1/3 vs FP32 (needs ABC debug-line info: lead L1) |
| 4 | `avm2/dependent_strings` | **flash_fixes candidate; no code.** We are already FP32-exact | mm 46/84 → **pass** once the golden is swapped (verified by local swap) |
| 8 | `movieclip_hittest_shapeflag` | **Re-disposition (premise stale), keep ACCEPTED Cat 8 at 6 lines.** We already print FP32's `false` on the 3 lines (35/37/39). One of the 6 is mislabelled | none (stays mm 332/338) |
| 1 | `global_proto_decls`, `_delete`, `global_instance_decls` (+ `argstest-v6/7/8`) | **Keep NO-GO (L), new premise and completion mechanism.** No subset flips a row. One S Flash-ward sub-fix measured and left out (below) | none |
| 3 | `avm2/bom` | **Keep NO-GO; RvF framing corrected.** Golden = FP32. Ruffle's hashbrown and FP32's avmplus order coincide here | none |
| prune | `netstream_play_flv` (avm1+avm2), `visual/video/deblocking` | **Prune.** Both pass on both axes (image 0 outliers) | already pass |
| prune | `visual/video/colorconversion/h263` | **Keep ACCEPTED, restate the numbers.** Now **3 outlier channels, max 1** (FAAN, `7b6a69124`). Still over `tolerance = 0`, `max_outliers = 0` | stays image fail |

**Priced flips:** +5 rows under the patch at baseline goldens: `native_objects_swf6`, `globals_swf5`,
`tab_ordering_properties_tab_index_edge_case` (rm→pass), plus `loader_applicationDomain` and `dependent_strings`, which
pass once the flash_fixes swap lands (no code needed for `dependent_strings`). `swz` stays failing but is 1 line closer to
Flash. **0 regressions measured** across a 66-row argued guard set (listed in §3). All 5 rows are on ignore lists, so the
filtered headline moves only if the ignore entries are pruned too (doc edits §4).

## 1. Per-item findings (mechanism, evidence)

### Item 2 — `native_objects_swf6`, line 56 `new TextField(): non-object: undefined`
- TP (`session28-fanout-reports/trace-provenance.md:326`) has golden = FP32, with our diff at −1/+1. Our diff is exactly line 56.
- **Mechanism:** `test.as:106` runs `createTextField("textField", 11, …)` *before* `check("new TextField()", new TextField())`
  (`:107`). SWF ≤ 6 resolves names case-insensitively, so `NewObject "TextField"` finds the `textField` **instance** on
  `_root`, which is not a function, and Flash yields `undefined`. SWF7/8 (case-sensitive) print `native`, and their
  goldens agree (`native_objects_swf7/8 output.txt:56`). The ACCEPTED counter-evidence (`textfield_props_swf6`,
  gnash `toString_valueOf-v6`) creates no `textField` instance, so it never contradicted this.
- **Fix** (`action.c` `actionNewObject`, `TextField` arm, mirrors the existing SWF6 `Color` shadow arm): in SWF ≤ 6, resolve
  `TextField` through `actionGetVariable`. If the result is not a function and not undefined/null, push undefined.
- Before/after: `native_objects_swf6` mm 114/115 → **pass**. `textfield_props_swf6` pass 210/210 (unchanged),
  `toString_valueOf-v6` pass 155/155, `TextField-v5/v6` (pass / rm 530/545), `textfield_props_swf5`,
  `native_objects_swf7/8` pass, `globals_monkeypatch` mm 49/306: all unchanged.

### Item 5 — `globals_swf5`: the "costs 3 gnash passes" trade is void
- TP lists gnash `LocalConnection-v5`, `NetConnection-v5` and `Video-v5` among the 167 rows where pinned FP32 equals the
  golden (`trace-provenance.md:435`). So **both sides are Flash**. FP32 shows the 3 classes visible in SWF5
  (`globals_swf5`), *and* FP32 passes `check_equals(LocalConnection, undefined)`. Bytecode: `snd = new LocalConnection();`
  then `GetVariable LocalConnection; Push undefined; Equals2`.
- They reconcile through Equals2, not visibility: in SWF5 a function with no own `valueOf`/`toString` compares as
  undefined. That rule is **already implemented** (s28 B6, `action.c` `actionEquals2`, FP32-backed). The other gnash v5
  goldens show the same quirk (`Accessibility.as:32 accObj == undefined`, `Instance.as:31 o == undefined`).
- **Fix:** delete the SWF5 hide (`flash_flags = 0x0080` on the 3 `_global` constructors, `action.c` near the end of the
  global init, the block after `#undef REG_OBJ`). The prototype guards it with `if (0)`. The wave-2 patch should delete
  the block.
- Before/after: `globals_swf5` mm 295/304 → **pass 304/304**. Line 136 (`typeof TextField.prototype`), which the RvF entry
  calls a separate gap, already matches at baseline. The 3 gnash `-v5` rows stay pass 7/7.
- Guard: the 21-row SWF5 set below is identical to baseline in status and line counts.

### Item 7 — `tab_ordering_properties_tab_index_edge_case`
- FP32 == golden (TP `:115`): `asdf, asdf2, 5, asdf3`. Upstream's own commit `67a04dcc7` describes it: *"setting it to a string
  **at the start** returns this string instead of a numerical value"*. `tab_ordering_properties` (pass, 293 lines) sets
  `tabIndex = 0` first and then coerces (`'x'` → `-2147483648`), so the two tests do not conflict. Line 3→4
  (`5` then `"asdf3"` read back raw) shows the raw mode is **sticky**.
- **Fix** (`action.c`, MovieClip `SetMember` path, the `tabIndex` coercion block; this is in the function containing
  `// tabIndex coercion: all non-undefined values coerced to integer`). For a non-textfield, non-button MC, if the first set
  is a STRING while tabIndex is unset or undefined, record the MC in a static raw-mode set (32 slots) and store values
  verbatim from then on. Wave-2 may prefer a trailing MovieClip field to the static set.
- Before/after: edge case **rm 1/4 → pass 4/4**. All 17 other `avm1` tab rows are unchanged (all pass, line-identical).

### Item 6 — `swz` / `loader_applicationDomain`: the Flash target is a securityError path
- FP32 (`trace-provenance/avm2__{swz,loader_applicationDomain}.r1.txt`, Linux == Windows): `Error #2044: Unhandled
  securityError:. text=Error #2046: The loaded file did not have a valid signature.` followed by the 2-frame stack.
  `onC`/`init` never run, so the SWZ ABC is never needed. The "AOT ceiling" disposition is moot for FP32.
- **Prototype (M, 4 files, all self-localized):**
  - `avm2_globals.c`: `URLRequest.digest` is stored (trailing `Avm2UrlRequestExt.digest`, `urlreq_get/set_digest`). It
    was `net_get_null`/`net_noop`.
  - `avm2_display.c`:
    - `ul_start_load`: a non-stream load whose request carries a string `digest` is marked `sig_error`. It snapshots
      the call stack and drops our own top `flash.net::URLLoader/…` frame.
    - `ul_deliver`: a `sig_error` load dispatches `SecurityErrorEvent("securityError", …, 2046)` and no
      open/progress/complete. If the loader has no `securityError` listener, it prints the #2044 line plus the stack tail.
  - `avm2_events.c`: `avm2_security_error_event_new`, `avm2_dispatcher_has_listener`.
  - `avm2_error.c`: `avm2_error_callstack_tail` (exports `callstack_snapshot`).
- Only these 2 corpus tests set `digest` (grep of every `.as`).
- Before/after:
  - `loader_applicationDomain`: 0 lines → **3 lines == FP32 byte-exact** (graphics and no-graphics; local golden swap →
    pass 3/3).
  - `swz`: 0 lines → 3 lines. vs FP32: 1/3. The 2 stack lines lack FP's `[Test.as:12]` / `[…frame1:3]` debug-line
    suffixes (lead L1).
  - Guard: `urlrequest`, `url_loader`, `url_vars`, `loader_method`, `urlstream_basic` stay pass; `bom` unchanged.
- **Rule to confirm in wave 2:** FP's frame is `Test.as:12`, the `new URLLoader()` line, not `:16` (`load()`). So FP's
  report carries the stack captured at the **dispatcher's construction**. Our snapshot at `load()` gives the same frame
  names here. An unhandled-ErrorEvent report keyed on construction stacks is the general form (lead L2).

### Item 4 — `dependent_strings`
- Our actual output equals `trace-provenance/avm2__dependent_strings.r1.txt` except for FP32's trailing empty line, which
  `compare_output` strips on both sides. A local golden swap gives **pass 83/83**. No code change.
  `ruffle::isDependent()` is not a Flash API, and FP32 traces `""` for each call.

### Item 8 — `movieclip_hittest_shapeflag`
- The current golden is the s28 flash-fixed `output.txt` (== FP32 r1/r2/L1/win1 byte-for-byte; `np1` differs on 2 lines).
  It differs from `output.txt.upstream` only on lines 35/37/39, and **we already print FP32's `false` there**. The
  register's premise ("we print true ≠ FP32 on the 3 lines") is stale since s28 `w2-hittest-shape-stale`.
- Our 6 remaining lines vs FP32 are 71, 171, 173, 175, 177 and 296, the ACCEPTED Cat 8 set. **Correction:** line 71 is
  in the `// layers` section (`hitTest(300, 400, true)`: FP32 true, ours false), **not** text, so the "Noto Sans glyph"
  label covers only 171–177 (4 lines). Line 296 is the morph boundary. Line 71 is a shape-geometry miss worth one look
  (lead L4).

### Item 1 — `global_proto_decls*` / `global_instance_decls`: re-priced (keep NO-GO, L)
- The premise is refuted. The golden IS Flash: TP pinned FP32 is byte-identical for `global_proto_decls`, and `_delete` differs
  only on the host-dependent `System.capabilities.manufacturer` position. The ignore comment (`ignored_tests.txt:196–198`,
  "Ruffle's expected output has Object.prototype methods ENUMERABLE…") is wrong and must be rewritten (§4).
- Composition of our diff vs FP32, `global_proto_decls` (section-level script, 462 `Testing` sections). Expected 4562
  lines, ours 3865:
  - 142 sections exact; 257 differ in content; 54 Flash sections missing from ours; 9 extra in ours. **0 sections
    differ by order alone.**
  - **≈470 lines:** a per-native-function "has `.prototype`" mismatch. Top pattern (179): Flash
    `type=[function with prototype]` vs ours `[function]`, e.g. `flash.geom.ColorTransform.prototype.toString`. Inverse
    (60): `TextField.getFontList`.
  - **≈90 lines:** READ_ONLY flags we lack (`Math.E`, `Key.*`, `XMLNode.prototype.namespaceURI`, …).
  - **≈61 lines:** every builtin on `_global` is enumerable in our first `for..in` (Flash: DONT_ENUM).
  - **≈700 lines:** native members we lack (`Accessibility.updateProperties/sendEvent/isActive`, the `toLocaleString.prototype`
    sections, …).
- **S sub-fix measured, NOT shipped (loud):** clearing ENUMERABLE on every `_global` property at the end of global init
  takes the `_global` section from −67/+66 to −6/+5. Positional matching goes 50 → 62. It flips no row.
- Guard for that sub-fix (28 `_global` rows: every `avm1/*global*`, gnash `Global-v5..8`, `argstest-v5..8`): 0 moves.
  It is Flash-correct (a SWF doing `for (k in _global)` today lists builtins), but it yields nothing on the board, so it
  stays out of the patch. Wave-2 may take it as a 3-line hygiene change.
- **Completion mechanism (new reopen criterion):** generate the native-object table (per object: member list in FP
  enumeration order, own/DONT_ENUM/READ_ONLY, `function with prototype` vs `function`) **from the FP32 golden itself**.
  `global_proto_decls/output.txt` is a complete FP32 dump of the AVM1 native graph. Then drive `setupNativeFuncOwnProps`
  / registration order from that table. Price: L (≈1300 facts + order + ~60 missing members). Payoff: 3 KF rows, and
  likely `argstest-v6/7/8`, which print `_global`-derived content. Re-measure those three after the table lands.
- `global_instance_decls`: TP has it untestable only because of 1 host-timezone Date line plus 1 trailing-whitespace
  line. Otherwise it equals Flash, so it is in the same arc.

### Item 3 — `avm2/bom`
- The 3 lines are `URLVariables.toString()` over a decoded `lastName=Jones&firstName=Tom`. FP32 (= golden, TP `:329`)
  prints `firstName=Tom&lastName=Jones`, and we print insertion order. `loader_load:81` (`aaa` then `cccc` →
  `cccc=true&aaa=bbb`) shows the same 2-key reversal; that golden is not FP32-testable (network).
- The FP mechanism is the avmplus `InlineHashtable` slot order for `for..in` over the dynamic URLVariables. URLVariables.as
  `toString` is a plain `for..in`. A URLVariables-only "reverse" rule would be a fit, not a mechanism, and a global
  reverse rule risks every AVM2 `for..in` row.
- **Keep NO-GO.** Reopen with a FLASH capture of the fixture in §LOCAL ORACLE REQUESTS, which fixes the avmplus order
  for 2–6 keys on URLVariables vs Object. If FP32 is plain reverse-insertion for small tables, it becomes an S fix for
  both rows.

### Prune rows
- `avm1/netstream_play_flv`: trace pass 21/21, image pass (0 outliers, tol 1). `avm2/netstream_play_flv`: trace pass, image
  pass. `visual/video/deblocking`: image pass, 0 channels (tol 0). They were fixed by the FAAN IDCT (`7b6a69124`,
  playbook line 1286). Their ACCEPTED entries and the bare `netstream_play_flv` line in `ignored_tests.txt:248` are stale.
- `visual/video/colorconversion/h263`: **3 outlier channels, max 1** (image_results_graphics.json), with tolerance 0 and
  max_outliers 0 upstream. It is not within tolerance. It is exactly the FAAN arm the entry predicted ("a single pixel,
  (447,289)"), and the golden is untestable in FP32 (video draw). Keep it ACCEPTED with the restated numbers.

## 2. Refutations of the brief / register premises
1. "golden ≠ Flash" (`global_proto_decls*` ignore premise): refuted (TP).
2. "we match Flash" (`native_objects_swf6`): refuted. FP32 says `undefined`, and the cause is SWF6 case-insensitive shadowing.
3. "costs 3 gnash passes" (`globals_swf5`): refuted. The gnash rows assert Equals2 behaviour, not visibility, and pass
   either way.
4. "conflicting expectations" (`tab_…_edge_case`): refuted. Both are consistent under the first-set-string raw mode.
5. "AOT ceiling" (`swz`, `loader_applicationDomain`): refuted for FP32. The load is refused before any ABC is needed.
6. "we print `true` ≠ FP32 on 3 lines" (`movieclip_hittest_shapeflag`): stale. We print `false` there now.
   ACCEPTED line 71's "glyph" label is also wrong.
7. "RvF: insertion order is Flash's" (`bom`): refuted. FP32 differs from insertion order.

## 3. Guard sets run (graphics; status + line counts vs baseline; all identical unless named above)
- SWF5 set (21): `as_set_prop_flags_version_swf5`, `equals2_swf5`, `lessthan2_swf5`, `shared_object_members_swf5`,
  `typeof_globals`, `enumerate`, gnash `Global/ExternalInterface/getvariable/XMLNode/Number/String/MovieClip/System/delete/
  argstest/Object/Instance/Function/Transform/NetStream-v5`.
- `_global` set (28): every `avm1/*global*` row, gnash `Global-v5..8`, `argstest-v5..8`.
- Tab set (18): every `avm1/*tab*` row.
- TextField set (8): `textfield_props_swf5/6`, `native_objects_swf7/8`, `globals_monkeypatch`, gnash `TextField-v5/v6`,
  `toString_valueOf-v6`.
- URL set (6): `urlrequest`, `url_loader`, `url_vars`, `loader_method`, `urlstream_basic`, `bom`.
- No-graphics: the 4 headline rows were re-run in no-graphics with identical results. `loader_applicationDomain` == FP32.
- No `regression`-suite row exercises these paths. Wave-2 needs the regression fixtures named in L3.

## 4. Doc edits (exact text; the coordinator applies them with the patch)

**`ruffle-tests/ignored_tests.txt`**
- Delete lines 192–195 (`# globals_swf5: …` comment + `globals_swf5`).
- Delete `native_objects_swf6` (line 212) and `tab_ordering_properties_tab_index_edge_case` (line 213).
- Delete line 248 `netstream_play_flv` and its comment block (lines 238–247).
- Replace lines 196–198 with:
  ```
  # Global decls tests: the goldens ARE Flash (s28 trace-provenance: pinned FP32 byte-identical for
  # global_proto_decls; _delete differs only on the host-dependent System.capabilities.manufacturer
  # position; global_instance_decls only on 1 host-timezone Date line). Real gaps, NO-GO (L) of record:
  # per-native-function `.prototype` presence (~470 lines), READ_ONLY flags (~90), _global DONT_ENUM
  # (~61), missing native members (~700). Reopen: build the native-object table from the FP32 golden
  # (s29 w1-disposition-audit §1 item 1).
  ```
- `movieclip_hittest_shapeflag` comment (lines 221–224): replace the second sentence with `# 4 lines at Noto Sans glyph
  boundaries (171–177), 1 'layers' shape-geometry miss (71: FP32 true, ours false; open lead), 1 morph boundary (296).`

**`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`**
- Delete `loader_applicationDomain` (225) and `dependent_strings` (260) once the flash_fixes land. **Keep** `swz` (226)
  with the comment `# swz: FP32 = securityError #2046 (3 lines); we print it without the [file:line] debug suffixes (needs
  ABC debugfile/debugline at runtime). s29 w1-disposition-audit.` Keep `bom` and `loader_load`.

**`ACCEPTED_DIFFS.md`**
- Delete the `native_objects_swf6` section (`### native_objects_swf6 — new TextField() typeof check`, lines 82–112) and the
  summary row (1305).
- Delete the `tab_ordering_properties_tab_index_edge_case` section (lines 382–404) and the summary row (1311).
- Delete the `avm1/netstream_play_flv` section (`### avm1/netstream_play_flv — Sorenson Spark pixel parity`), the
  `visual/video/deblocking` section and their summary rows (1316, 1317). Keep the `avm2/netstream_play_flv` resolver stub
  only if `image_triage.py` still needs it; it is not an accepted diff.
- `h263` section heading → `### visual/video/colorconversion/h263 — Spark IDCT precision (3 outlier channels, max 1; FAAN)`.
  Add as the first body line: `**s29 restatement:** the FAAN IDCT (7b6a69124) landed; the residue is the single pixel
  (447,289) the FAAN arm predicted, 3 channels at max 1 vs tolerance 0 / max_outliers 0.` Summary row 1318 →
  `3 image outlier channels, max 1`.
- Category 13 (lines 1154–…): replace the intro paragraph with `FP32 refuses both loads before any SWZ ABC is needed
  (URLRequest.digest set → securityError #2046, unhandled → #2044 + stack; captures s28 trace-provenance). The AOT-ceiling
  framing applies only to Ruffle's goldens. loader_applicationDomain now matches FP32 byte-exact (s29 patch + flash_fix);
  swz misses only the [file:line] stack suffixes.` Delete the `loader_applicationDomain` subsection and summary row 1327,
  and restate 1328 as `swz | FP32 #2046 path landed; [file:line] stack suffixes missing | 2 of 3 | open (ABC debug lines)`.
- Category 8 intro: replace `(lines 71, 171–177 and 296 …)` wording with `(71 'layers' shape geometry, 171–177 Noto glyph
  boundaries, 296 morph boundary)`, and rename the glyph subsection to `(4 diff lines: 171, 173, 175, 177)`.

**`RUFFLE_VS_FLASH_DIFFERENCES.md`** (append at EOF):
```
## s29 w1-disposition-audit: corrections and new Ruffle≠Flash entries (2026-11-26)
- avm2/dependent_strings: FP32 has no ruffle::isDependent(); each call traces "" (capture
  session28-fanout-reports/trace-provenance/avm2__dependent_strings.r1.txt). We match FP32 exactly; flash_fixes swap → pass.
- avm2/swz, avm2/loader_applicationDomain: FP32 refuses a URLLoader fetch whose URLRequest.digest is set:
  "Error #2044: Unhandled securityError:. text=Error #2046: The loaded file did not have a valid signature." + stack
  (Linux == Windows). Ruffle loads the SWZ and lists its classes. flash_fixes swap for both.
- avm2/bom, avm2/loader_load: CORRECTION to "AVM2 dynamic-property enumeration order": the bom golden IS FP32 (s28 TP).
  Flash does not enumerate URLVariables in insertion order; Ruffle's hashbrown order coincides with FP32's avmplus
  order on these 2-key cases. Our insertion order is the gap. Status unchanged (NO-GO pending a FLASH order capture).
- SWF5 Constructor Visibility (globals_swf5): CORRECTION: FP32 shows LocalConnection/NetConnection/Video visible in SWF5
  AND passes gnash `X == undefined` (SWF5 Equals2 function rule). We now show them (s29 patch); this was never a
  Ruffle-vs-Flash difference. Mark the old entry RESOLVED.
```
Also mark the `## SWF5 Constructor Visibility` section header `(RESOLVED s29: see EOF)`.

**flash_fixes candidates (coordinator adds; evidence = s28 TP captures, Linux == Windows):**

| test | file | upstream_sha256 | fix = | effect |
|---|---|---|---|---|
| `avm2/dependent_strings` | `output.txt` | `8a560703303501c347fec258addb1711cd8f3a3119069c2be191c74f4c414948` | `trace-provenance/avm2__dependent_strings.r1.txt` | mm → **pass** (no code) |
| `avm2/loader_applicationDomain` | `output.txt` | `fea57d93a65052f6a50ea4cd4b83b4b4bd7b75f50487158085d5240d0deeddd3` | `trace-provenance/avm2__loader_applicationDomain.r1.txt` | mm 0/4 → **pass** with the patch (mm 0/3 without) |
| `avm2/swz` | `output.txt` | `2e9e8caecb1d7ae1a610e5b2035e8b5a72989fcb6e80bf87c23f86152f449846` | `trace-provenance/avm2__swz.r1.txt` | mm 0/2 → mm 1/3 with the patch |

Land the `loader_applicationDomain`/`swz` swaps **with** the patch. Without it, both still fail, just against Flash.

**`NO_GO_REGISTER.md`:** close §4 items 2, 4, 5, 6, 7 and 8 (pointer to this report). Rewrite item 1 (premise refuted,
L with the "native table from the FP32 golden" mechanism) and item 3 (premise refuted, FLASH-order capture pending). Move
`native_objects_swf6`, `globals_swf5`, `tab_…_edge_case`, `loader_applicationDomain` and `dependent_strings` to §2
("overturned").

## 5. Wave-2 patch scope (if taken)
`w1-disposition-audit-prototype.patch`, as is. Functions touched:
- `action.c`: `actionNewObject` (TextField arm); the global-init tail after `#undef REG_OBJ` (delete the `if (0)` block
  rather than keep it); the MovieClip property-set function's `tabIndex` block.
- `avm2_display.c`: `Avm2PendingUrlLoad`, `ul_start_load`, `ul_deliver`.
- `avm2_events.c`: 2 new exported helpers plus `g_security_error_event_class`.
- `avm2_error.c`: `avm2_error_callstack_tail`.
- `avm2_globals.c`: `Avm2UrlRequestExt.digest`, `urlreq_ctor`, `register_net`.

No recompiler change. CI: graphics, `categories=full` (AVM2 runtime). Add the flash_fixes swaps and ignore prunes in the
same landing. Optionally take the 3-line `_global` DONT_ENUM hygiene change from §1 item 1.

## New unclaimed leads
- **L1 (M–L): ABC debug-line stack suffixes.** FP's debug player prints `at X()[file:line]` when the SWF carries
  `debugfile`/`debugline`. We drop both opcodes (`abc_verifier.cpp:1210`), so we print `at X()` only. It blocks `swz`
  (2 lines). Probably also `event_handler_exception` (rm, 3 lines, `[Z:\…\Test.as:10]`, golden = Flash per TP `:135`) and
  any uncaught-error golden from a debug-compiled SWF. Mechanism: emit the current debugline into the call frame.
- **L2 (M): general unhandled-ErrorEvent report.** FP prints `Error #2044: Unhandled <IOErrorEvent|securityError>:.
  text=…` (plus the dispatcher's construction stack when a script created it) for an ErrorEvent with no listener. We
  print nothing. `avm2/html_text_img_parsing` (rm 505/600, golden = Windows FP32, TP `:140`) is missing exactly 95 such
  lines for `<img>` loads in HTML text. The prototype's `ul_deliver` print is the first instance; generalize it at
  `avm2_dispatch_event` for ErrorEvent subclasses.
- **L3: regression fixtures for wave 2.** (a) An SWF6 `createTextField("textField")` then `new TextField()`, vs SWF7.
  (b) A MovieClip `tabIndex` first-string / first-number sequence. (c) SWF5 `typeof LocalConnection` + `LocalConnection ==
  undefined`. Each needs an FP32 golden (FLASH requests below), and MTASC is not in the cloud.
- **L4 (S–M): `movieclip_hittest_shapeflag` line 71** (`// layers`, `hitTest(300,400,true)`: FP32 true, ours false). A
  shape-geometry miss, not a font one. Dump the layers clip's shape records at that point.
- **L5 (S, no flip): `_global` builtins enumerable.** Measured in §1 item 1.

## LOCAL ORACLE REQUESTS
1. **FLASH: AS3 for-in order fixture, trace, direct, 1 frame (reopens `bom` / `loader_load`).** Needs the coordinator's
   AS3 compiler (no ASC/Flex in the cloud). Source:
   ```as3
   package { import flash.display.Sprite; import flash.net.URLVariables;
   public class Test extends Sprite { public function Test() {
     var orders:Array = [["a","b"],["b","a"],["lastName","firstName"],["aaa","cccc"],["k1","k2","k3"],["k3","k2","k1"],
                         ["x","y","z","w","v","u"]];
     for each (var ks:Array in orders) {
       var o:Object = {}; var u:URLVariables = new URLVariables();
       for each (var k:String in ks) { o[k] = 1; u[k] = 1; }
       var a:Array = []; for (var n:String in o) a.push(n);
       trace("Object " + ks.join(",") + " -> " + a.join(","));
       trace("URLVariables " + ks.join(",") + " -> " + u.toString());
       var d:URLVariables = new URLVariables(ks.join("=1&") + "=1");
       trace("decoded " + ks.join(",") + " -> " + d.toString());
     } } } }
   ```
   Compare: whether FP32 order is reverse-insertion, sorted or hash-scattered, Object vs URLVariables. Ask for 2 runs
   (address-hash nondeterminism check).
2. **FLASH (only if wave 2 wants regression fixtures, L3):** AVM1 direct traces of three tiny SWFs. MTASC on the
   coordinator box: `-version 6` / `-version 7` / `-version 5` builds of
   (a) `createTextField("textField",1,0,0,10,10); trace(typeof new TextField());`
   (b) `this.tabIndex="s"; trace(this.tabIndex); this.tabIndex=5; this.tabIndex="t"; trace(this.tabIndex);
   createEmptyMovieClip("m",2); m.tabIndex=0; m.tabIndex="t"; trace(m.tabIndex);`
   (c) `trace(typeof LocalConnection); trace(LocalConnection == undefined); trace(Camera == undefined);`
