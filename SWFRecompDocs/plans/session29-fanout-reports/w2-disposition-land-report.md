# s29 w2-disposition-land: land the w1 disposition audit (items 2, 5, 6, L5) + 3 flash_fixes; item 7 HELD

**New files:**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-disposition-land-report.md` (this report)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-disposition-land.patch` (= `git diff --binary origin/master -- SWFRecomp
  SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/flash_fixes
  <the 2 new regression dirs>`; `flash_fixes` is included because the `loader_applicationDomain` / `dependent_strings`
  flips depend on it; the doc edits are in the branch commit only. `git apply --check -R` passes on the branch)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-disposition-land-oracle/tabindex/make_fixtures.py` + 13 fixture dirs
  `t00_corpus_replica` … `t12_frame2`, each with `test.swf`, `test.toml` and `README.txt` (the FLASH request in §7)
- `ruffle-tests/flash_fixes/avm2/{dependent_strings,loader_applicationDomain,swz}/output.txt`
- `ruffle-tests/tests/swfs/regression/avm1_textfield_ctor_shadow_swf6/{Test.as,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_textfield_ctor_shadow_swf7/{Test.as,test.swf,test.toml,output.txt}`

**Base:** `origin/master` `631ccdf4` (code = `bfa47037b`). Upstream corpus downloaded 2026-11-26/27, Ruffle master
`b7ff32d93` (avm1, avm2, from_gnash, visual, from_shumway, fonts, text). Box: SETUP_STATUS all OK (Dawn on lavapipe).
Every *before* figure is clean `origin/master` on this box, with the flash_fixes applied, so both legs grade against the
same goldens. The only difference between the legs is the 5 source files.

## 0. Verdicts and ledger (lead)

| item | verdict | rows |
|---|---|---|
| 2 `native_objects_swf6` (SWF ≤ 6 `textField` shadows `TextField`) | **LANDED** | mm 114/115 → **pass** 115/115 |
| 5 `globals_swf5` (un-hide LocalConnection/NetConnection/Video in SWF5) | **LANDED**. The `if (0)` block is **deleted**, not kept | mm 295/304 → **pass** 304/304; gnash `LocalConnection/NetConnection/Video-v5` stay pass 7/7 |
| 6 `URLRequest.digest` → securityError #2046 | **LANDED** (+ one GC-root fix to the prototype, §1) | `loader_applicationDomain` → **pass** 3/3; `swz` 0/3 → 1/3 (stays mm) |
| L5 `_global` builtins DONT_ENUM | **LANDED** (Flash-correct hygiene) | 0 status moves on the 28-row `_global` guard set; `global_proto_decls` stays mm, 50 → 62 matching lines |
| flash_fixes ×3 (`dependent_strings`, `loader_applicationDomain`, `swz`) | **ADDED** (fixes.json + README row + RvF) | `dependent_strings` mm 46/84 → **pass** 83/83 (no code) |
| 7 `tab_ordering_properties_tab_index_edge_case` | **HOLD.** The prototype rule is out of the patch | stays rm 1/4. A 13-fixture FLASH request isolates the discriminator (§3, §7) |
| `avm2/bom`, `avm2/loader_load` | **Re-dispositioned** as Flash-nondeterministic (ACCEPTED Cat 12, kept ignored); RvF corrected | unchanged (6/9, 126/128) |
| §4 doc edits | **APPLIED** (minus item 7, plus item 4's correction). `NO_GO_REGISTER.md` left to the coordinator (edits listed in §6) | n/a |

### EXPECTED-FLIP LEDGER (CI graphics, `categories=full`; no-graphics leg identical on these rows)

**Trace axis**, graded against the flash_fixes-swapped goldens:

| suite/test | baseline (`014124ed5`) | expected |
|---|---|---|
| `avm1/native_objects_swf6` | output_mismatch 114/115 | **pass** 115/115 |
| `avm1/globals_swf5` | output_mismatch 295/304 | **pass** 304/304 |
| `avm2/loader_applicationDomain` | output_mismatch 0/4 (Ruffle golden) | **pass** 3/3 (FP32 golden) |
| `avm2/dependent_strings` | output_mismatch 46/84 | **pass** 83/83 (golden swap only) |
| `avm2/swz` | output_mismatch 0/2 | output_mismatch **1/3** (expected total changes 2 → 3: golden swap, not drift) |
| `regression/avm1_textfield_ctor_shadow_swf6` | (new) | **pass** 2/2 |
| `regression/avm1_textfield_ctor_shadow_swf7` | (new) | **pass** 2/2 |
| `avm1/global_proto_decls` | output_mismatch | output_mismatch (matching lines 50 → 62; no status move) |

Nothing else moves. All 4 corpus flips are on ignore lists at baseline. Three of the entries (`native_objects_swf6`,
`globals_swf5`, avm2 `loader_applicationDomain` + `dependent_strings`) are pruned in this patch, so they now count
in the filtered headline.

**Pixel axis:** no expected moves. None of the ledger rows has an `[image_comparisons]` block, and no render code is
touched. The render canary result is in §4.

## 1. What the patch does (functions touched)

`SWFModernRuntime/src/actionmodern/action.c`:
- `ensureGlobalInit`:
  - **deleted** the SWF5 hide (the block after `#undef REG_OBJ` that set `flash_flags = 0x0080` on
    `LocalConnection`/`NetConnection`/`Video`), leaving a comment that says why.
  - **added**, just before `g_global_init_done = 1`: `PROPERTY_FLAG_ENUMERABLE` is cleared on every `_global`
    property (L5). Script-added globals are set after init, so they stay enumerable.
- `actionNewObject`, `TextField` arm: in SWF ≤ 6, `TextField` is resolved through `actionGetVariable`. If the result
  is not a function, undefined or null (that is, a case-insensitively matching `textField` instance or variable), the
  arm pushes `undefined`. This mirrors the existing SWF6 `Color` shadow arm.
- `actionSetMember`, `tabIndex` block: **untouched** (the prototype's raw-mode hunk was reverted).

`SWFModernRuntime/src/avm2/`, as in the w1 prototype:
- `avm2_globals.c`: trailing `Avm2UrlRequestExt.digest` field; `urlreq_ctor`; new `urlreq_get_digest` /
  `urlreq_set_digest`; `register_net` (the getter/setter was `net_get_null`/`net_noop`).
- `avm2_display.c`:
  - `Avm2PendingUrlLoad` gains trailing `sig_error` and `stack_tail` fields.
  - `ul_start_load`: a non-stream load whose request carries a string `digest` is marked `sig_error`, with the
    script stack snapshotted and our own `flash.net::URLLoader` frame dropped.
  - `ul_deliver`: a `sig_error` load dispatches `SecurityErrorEvent` #2046 and no open/progress/complete. If nothing
    listens for it, it first prints the #2044 report.
  - **`avm2_gc_mark_roots_display` (new in w2):** also marks `g_pending_url_loads[i].stack_tail`. The prototype left
    the snapshotted `Avm2String` unrooted between `load()` and the drain. A GC in that window would free the string,
    and then `ul_deliver` would read freed memory.
- `avm2_events.c`: `g_security_error_event_class`, new `avm2_security_error_event_new`, new
  `avm2_dispatcher_has_listener`.
- `avm2_error.c`: new `avm2_error_callstack_tail` (wraps `callstack_snapshot`).

No recompiler change, no `verify_output.py` change, no `render_canary_tests.txt` change.
`Avm2UrlRequestExt.digest` needs no explicit GC mark: the GC scans `native_ext` conservatively by `native_ext_size`
(`avm2_gc.c:494`).

## 2. Per-test before/after (same box; graphics unless noted)

| test | before (clean master + fixes) | after | no-graphics after |
|---|---|---|---|
| `avm1/native_objects_swf6` | mm 114/115 | **pass** 115/115 | pass 115/115 |
| `avm1/globals_swf5` | mm 295/304 | **pass** 304/304 | pass 304/304 |
| `avm1/tab_ordering_properties_tab_index_edge_case` | rm 1/4 | rm 1/4 (HELD) | rm 1/4 |
| `avm1/global_proto_decls` | mm 50/4562 | mm 62/4562 | mm 62/4562 |
| `avm2/loader_applicationDomain` | mm 0/3 | **pass** 3/3 | pass 3/3 |
| `avm2/dependent_strings` | pass 83/83 (golden swap only; mm 46/84 vs the Ruffle golden) | pass 83/83 | pass 83/83 |
| `avm2/swz` | mm 0/3 | mm 1/3 | mm 1/3 |
| `avm2/bom` | mm 6/9 | mm 6/9 | mm 6/9 |
| `avm2/loader_load` | mm 126/128 | mm 126/128 | mm 126/128 |
| `regression/avm1_textfield_ctor_shadow_swf6` | mm 1/2 | **pass** 2/2 | pass 2/2 |
| `regression/avm1_textfield_ctor_shadow_swf7` | pass 2/2 | pass 2/2 | pass 2/2 |
| gnash `LocalConnection-v5` / `NetConnection-v5` / `Video-v5` / `Global-v5` | pass 7 / 7 / 7 / 172 | same | same |

### Guard sets (graphics, A/B status + line counts, 104 rows)

Diffing before vs after over all 104 rows gives exactly the ledger lines above: `global_proto_decls` 50→62,
`globals_swf5`, `native_objects_swf6`, the swf6 regression fixture, `loader_applicationDomain` and `swz`.
**Every other row is identical in status and line count.** The rows:
- **avm1 (48):**
  - all 28 avm1 tests whose `.as` mentions `_global`: `amf0_serde_suite`, `array_constructor`, `as_broadcaster`,
    `as_setup_error`, `asnew`, `bitmap_data_thorough/constructor`, `bitmap_filters`, `coerce_to_object_monkeypatch`,
    `context_menu`, `context_menu_item`, `edittext_asfunction_case_insensitive`, `global_instance_decls`,
    `global_proto_decls`, `global_proto_decls_delete`, `global_swf5_6_7_8_9`, `global_swf6_7_8`, `globals_monkeypatch`,
    `instanceof_coercions`, `interface_implements_op`, `localconnection_xml_unavailable`, `math_swf6/7/8`,
    `movieclip_gettextsnapshot`, `property_invalid_base_clip`, `removed_clip_function_scope`, `swf4_vars`,
    `video_prototype_lazy_swf6_child`;
  - plus `globals_swf5/6/7/8`, `swf5/6/7_global_funcs`, `typeof_globals`, `enumerate`, `native_objects_swf6/7/8`,
    `textfield_props_swf5/6`, `equals2_swf5`, `lessthan2_swf5`, `as_set_prop_flags_version_swf5`,
    `shared_object_members_swf5`, `tab_ordering_properties`, `tab_ordering_properties_tab_index_edge_case`.
- **gnash actionscript.all (27):**
  - `Global-v5..v8` and `argstest-v5..v8`;
  - the `-v5` row of `ExternalInterface`, `getvariable`, `XMLNode`, `Number`, `String`, `MovieClip`, `System`,
    `delete`, `Object`, `Instance`, `Function`, `Transform`, `NetStream`, `LocalConnection`, `NetConnection`, `Video`
    and `TextField`;
  - `TextField-v6` and `toString_valueOf-v6`.
- **avm2 (10):** `loader_applicationDomain`, `dependent_strings`, `swz`, `bom`, `loader_load`, `urlrequest`,
  `url_loader`, `url_vars`, `loader_method`, `urlstream_basic`.
- **regression (19):** every row whose name matches `global|textfield|cross_swf_version|_swf5|v5`:
  - the `*_cross_swf_version` family (10 rows), which swaps `_global` groups;
  - `mc_method_v5_caller_gate`, `avm1_gnash_flash_probes_v5`, `avm1_place_occupied_depth_swf5`;
  - the textfield rows and the 2 new fixtures.
  All pass, unchanged except the swf6 fixture.

## 3. Item 7 (tabIndex): why it is HELD, and what decides it

- **Corpus SWF vs `L3b_tabindex_v8`, disassembled:**
  - Corpus `tab_ordering_properties_tab_index_edge_case/test.swf` (SWF8, 110 bytes compressed):
    `FileAttributes(0)`, then one root DoAction with a ConstantPool. The body is `Push "this"; GetVariable; Push
    "tabIndex"; Push "asdf"; SetMember` and so on, all in frame scope, with `this` as the target.
  - `L3b_tabindex_v8`: no FileAttributes; `DefineSprite` + `ExportAssets` + `DoInitAction` defining class `Test`. The
    static `main` is a **DefineFunction2** (6 registers) doing `GetVariable "_root"; StoreRegister 3`, then `Push r3
    "tabIndex" "s"; SetMember`. It is called from a frame-1 DoAction (`Test.main(this)`).
- **Candidate discriminators:** FileAttributes present or absent; `this` vs `_root`; a register vs the stack;
  function scope (DefineFunction2 or DefineFunction) vs frame scope; DoInitAction vs DoAction; SWF version; and,
  less likely, a read before the first set or frame 1 vs a later frame.
- **What we do today fits neither capture.** The `actionSetMember` tabIndex block coerces to i32 and *keeps the previous
  value on NaN*, so the corpus row prints `undefined, undefined, 5, 5`. FP32 prints `asdf, asdf2, 5, asdf3` for the
  corpus row and `-2147483648` (INT_MIN) for L3b. So whatever the discriminator turns out to be, the NaN-keeps-previous
  arm is wrong for one of the two shapes. A non-numeric string on an MC goes either raw (corpus) or INT_MIN (L3b), never
  "unchanged". `tab_ordering_properties` (pass) agrees: there, `'x'` after `0` gives INT_MIN.
  - The two FP32 results do not decide which of the 2 shapes the NaN arm belongs to. So I changed nothing: an INT_MIN
    rule alone would not flip the corpus row and is unproven for frame scope.
- **Fixtures built** (`w2-disposition-land-oracle/tabindex/`, generator `make_fixtures.py`, uncompressed SWF8,
  12 fps). Each changes ONE variable from a re-assembled corpus SWF:

  | fixture | change vs corpus |
  |---|---|
  | `t00_corpus_replica` | none (sanity: must reproduce the raw golden) |
  | `t01_no_fileattributes` | FileAttributes removed |
  | `t02_root_getvariable` | target `GetVariable "_root"` instead of `this` |
  | `t03_this_in_register` | `this` in global register 1 |
  | `t04_fn2_root` | t02's body inside a DefineFunction2 called from the frame |
  | `t05_fn1_root` | the same with a DefineFunction (v1) |
  | `t06_fn2_reg_root` | t04 with `_root` in a function register (the MTASC shape, minus the class) |
  | `t07_initaction_root` | t02's body in a DoInitAction of an exported sprite |
  | `t08_fresh_child_frame` | frame scope, fresh `createEmptyMovieClip("m",1)` child as the target |
  | `t09_corpus_v6`, `t10_corpus_v7` | SWF version 6 / 7 |
  | `t11_read_first` | `trace(this.tabIndex)` before the first set |
  | `t12_frame2` | the body on frame 2 |

  - All 13 run in our runtime: every one prints the same `undefined/undefined/5/5` as the corpus row, and t08 prints
    it for a fresh child too, so the SWFs are well-formed.
  - **Decision rule for the next wave:** the first fixture that flips from raw to INT_MIN names the discriminator.
    The fix then lives in `actionSetMember`'s tabIndex block (the raw arm vs the INT_MIN arm, replacing the NaN
    keep-previous arm). Each fixture whose FP32 output differs from ours becomes a `regression/` row.
- **Completion mechanism:** the FLASH request in §7 (13 direct traces, 2 frames each, ~1 min). Price: S once the
  captures exist.

## 4. Render canary (graphics; `render_canary.py`, 844-line set, md5 A/B)

`capture --label before` on clean master and `--label after` with the patch, both `--jobs 3 --timeout 5400`, over the
standing `render_canary_tests.txt`: **195 tests / 260 comparisons, IDENTICAL 260, DIFFERS 0, APPEARED/VANISHED/NO_RENDER
0; trace-status changes none; image-status changes none.** The set needed no new member: no render code is touched, and
the ledger rows have no image comparisons.

## 5. Doc edits applied in this patch

- **`ruffle-tests/ignored_tests.txt`:**
  - Pruned `globals_swf5`, `native_objects_swf6` and `netstream_play_flv`, each leaving a one-line "removed" note.
  - Rewrote the `global_*_decls` comment (the golden IS Flash; NO-GO (L) with the FP32-table reopen criterion;
    `_global` DONT_ENUM is now done).
  - Restated the `movieclip_hittest_shapeflag` comment (4 glyph lines + line 71 'layers' + line 296 morph).
  - **Kept** `tab_ordering_properties_tab_index_edge_case` (item 7 HELD).
- **`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`:**
  - Pruned `loader_applicationDomain` and `dependent_strings`.
  - Kept `swz`, with the new comment.
  - Kept `bom` and `loader_load`, with their comment rewritten to Flash-nondeterministic (item 4).
- **`ACCEPTED_DIFFS.md`:**
  - Deleted the `native_objects_swf6` section, the `visual/video/deblocking`, `avm1/netstream_play_flv` and
    `avm2/netstream_play_flv` sections (with a short prune note in their place), the Category 13
    `loader_applicationDomain` subsection, and their summary rows.
  - `h263`: heading restated to 3 channels, max 1 (FAAN), with the restatement as the first body line; its summary
    row is restated too.
  - Category 13: heading and intro rewritten; `swz` subsection restated; summary row → `2 of 3 | open (ABC debug lines)`.
  - Category 8: intro wording changed; glyph subsection retitled to 4 lines (171–177) with the line 71 correction; the
    summary row splits into glyph (4) and 'layers' (1, open lead L4).
  - **Item 4:** new Category 12 subsection `avm2/bom` + `avm2/loader_load` (FP32 order nondeterministic, citing the
    two coordinator runs); 2 summary rows.
  - **Item 7:** an "s29 HOLD" note on the tabIndex entry (FP32 contradicts both rules; fixtures pending); summary row
    restated. The entry is not deleted.
- **`RUFFLE_VS_FLASH_DIFFERENCES.md`:** an EOF entry (dependent_strings; swz/loader_applicationDomain #2046; the
  bom/loader_load CORRECTION restated as "FP32 order is nondeterministic; the golden is one run"; SWF5 visibility
  RESOLVED; native_objects_swf6 explained). The `## SWF5 Constructor Visibility` header is marked
  `(RESOLVED s29: see EOF)`. Nothing else in the file was edited.
- **`ruffle-tests/flash_fixes/`:** 3 `fixes.json` entries (appended, `indent=2`; the diff is +33 lines, no reformat),
  3 fix files (= the s28 TP `r1` captures, verbatim), and 1 README table row.
  - Upstream sha256 values were verified against this box's fresh download, and all 3 equal the w1 report's:
    - `dependent_strings` `8a560703…4948`
    - `loader_applicationDomain` `fea57d93…ddd3`
    - `swz` `2e9e8cae…9846`
  - `apply_flash_fixes.py --check` reported: `APPLIED 3` (the new entries), `ALREADY 35`, `MISSING 29`. The
    MISSING entries are categories not downloaded at that point. After the full download, all applied.
- **`regression/README.md`:** 2 rows for the new fixtures.

## 6. `NO_GO_REGISTER.md` edits for the coordinator (not applied)

- §1a row `native_objects_swf6` (line 35): move to §2 ("overturned").
  `FIXED s29 w2-disposition-land: SWF ≤ 6 textField instance shadows TextField (FP32); pass 115/115.`
- §1a row `globals_swf5` (line 44): move to §2.
  `FIXED s29: un-hidden; the gnash -v5 rows assert Equals2 and stay pass; pass 304/304.`
- §1a row `avm2/swz`, `avm2/loader_applicationDomain` (line 49):
  - move `loader_applicationDomain` to §2 (`FP32 #2046 path + flash_fix; pass`);
  - restate `swz` as `open (S–M): ABC debugline [file:line] suffixes; 1/3 vs FP32`.
- §1a row `avm2/dependent_strings` (line 42): move to §2 (`flash_fix swap; we were already FP32-exact; pass`).
- §1a row `avm2/bom`, `avm2/loader_load` (line 41): replace the UNSURE text with
  `NO-GO (Flash-nondeterministic): FP32 for-in order is hash-scattered and differs between runs (s29 forin_order r1 vs
  r2); golden = one run. ACCEPTED Cat 12.`
- §1a row `global_proto_decls*` (line 34): replace the UNSURE text with
  `NO-GO (L), premise refuted (golden = FP32). Reopen: build the native-object table from the FP32 golden (s29 w1 §1
  item 1). _global DONT_ENUM landed s29 (50 → 62 lines, no flip).`
- §1a row `movieclip_hittest_shapeflag` (line 55):
  `Premise stale: we print FP32's false on 35/37/39. 6 ACCEPTED lines = 4 glyph + 1 'layers' (71, open lead L4) +
  1 morph.`
- §1a "Open HOLDs" row (line 63), tab edge case: `HOLD (s29): FP32 raw for the corpus frame-script shape, INT_MIN for
  the MTASC L3b shape; 13-fixture FLASH request in w2-disposition-land-oracle/tabindex/.`
- §3 (lines 179/184): drop `native_objects_swf6` and `loader_applicationDomain` from the active-row list; add
  `bom`/`loader_load` (Cat 12); the video image rows go from 3 to 1 (`h263` only).
- §4 items 1–8 (lines 192–199): close 2, 4, 5, 6 (`loader_applicationDomain`) and 8, each pointing at this report.
  Item 3: Flash-nondeterministic. Item 7: HOLD (as above). Item 1: rewritten (as above).

## 7. Could not finish / completion mechanisms

- **Item 7.** HELD on the FLASH request below. Mechanism: §3's decision rule.
- **`swz` 1/3.** Needs the ABC `debugline` suffixes (lead L1). Sibling `w1-rm-avm2` owns the overlapping AVM2
  debug-line bucket P, so L1 was not implemented, per the brief.
- **NO_GO_REGISTER.** Coordinator (§6).

## New unclaimed leads

- **L-tab (S, after the FLASH run):** replace the `actionSetMember` tabIndex NaN-keeps-previous arm. It is wrong in
  both FP32 shapes measured (§3).
- Carried from w1, unchanged:
  - L1: ABC debug-line suffixes (`swz`, `event_handler_exception`).
  - L2: a general unhandled-ErrorEvent #2044 report (`html_text_img_parsing`, 95 lines). The new `ul_deliver` print is
    the first instance.
  - L4: `movieclip_hittest_shapeflag` line 71.

## LOCAL ORACLE REQUESTS

1. **FLASH: `SWFRecompDocs/plans/session29-fanout-reports/w2-disposition-land-oracle/tabindex/t00…t12`, trace,
   direct pinned (NOT `--wrapped`), frames = each `test.toml` `num_ticks` (2, or 3 for `t12_frame2`).**
   - SWFs are prebuilt; `python3 make_fixtures.py` regenerates them byte-identically.
   - Compare each capture to `asdf / asdf2 / 5 / asdf3` (raw) vs `-2147483648 / -2147483648 / 5 / -2147483648`
     (coerce). `t11` has one extra leading line: the pre-set read.
   - `t00` must equal the corpus golden. If it does not, the re-assembly (inline strings instead of a ConstantPool,
     uncompressed) is itself the discriminator, so please report it either way.
   - One run each is enough; ask for a second run of `t00` and of the first fixture that coerces.
