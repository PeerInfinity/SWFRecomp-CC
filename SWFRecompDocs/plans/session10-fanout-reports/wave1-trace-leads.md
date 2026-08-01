# Wave-1 "trace-leads" — evidence-finish of polish-sweep-arc §10.4

Baseline read: per-suite `_results/results_graphics.json`, all stamped
`git_sha = feb8882b09e238e91ab6444099d6cca237e3a4f9` (= `feb8882b0`).
Corpus recomputed from those files: **effective_pass 4176 / total 4424** —
i.e. the headline is the **UNFILTERED** `effective_pass` (`pass +
ruffle_matched`) summed over top-level suite result files. This matters for
lead 2.

Disposition sweep (per the §10.2 brief rule) — `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt`:

| target | dispositioned? |
|---|---|
| `avm2/loader_duplicate_class` | no |
| `from_avmplus/e4x/Statements/e12_1` | no |
| `avm2/verify_method_info_{duplicate,oob}` | no |
| `avm2/scope_optimizations` | no |
| `avm2/url_vars` | **named** in RUFFLE_VS_FLASH_DIFFERENCES.md §"loader_load" — but only as *evidence about `loader_load`*; the doc explicitly says it is "**not** added to `ignored_tests.txt`". Not a disposition on `url_vars` itself. Safe target. |
| `avm2/url_loader`, `avm2/urlrequest` | no |

No lead is a dispositioned-test trap.

---

## Lead 1 — `avm2/loader_duplicate_class`

**VERDICT: DEFER** (as a yield target). Fix A alone is a legitimate
zero-yield correctness rider; fixes A+B together still yield 0.

### Current state
`avm2` suite, `output_mismatch`, `actual=49 / expected=48 / matching=23`.
The apparent "missing leading blank line" is a **non-issue**:
`verify_output.py:3195-3200` strips leading/trailing blank lines from BOTH
sides before comparing (hence expected=48 not 49). Align actual line *n*
with expected line *n+1* when reading `output.txt`.

### Mechanism — three independent causes, all confirmed

**Cause A — script-`new`'d child non-root class gets no timeline.**
`display_native_init` resolves a script-created display object's symbol
with the fast arm:

* `SWFModernRuntime/src/avm2/avm2_display.c:10812` —
  `uint16_t char_id = char_for_class(obj->cls);`

`char_for_class` (:241) scans only `g_symbol_map`, which holds the main
movie's bindings plus child **root** bindings. A child's *non-root* class
is absent → `char_id == 0` → no timeline → childless clip. The correct
slow arm **already exists and already disambiguates the test's three
distinct `DuplicateClass` classes**: `avm2_display_child_char_for_class`
(`avm2_display.c:296`), which walks the super chain, maps each ancestor's
ABC file to its movie via `avm2_display_movie_for_abc` (:335) and matches
by qualified name inside *that* movie's `symbol_classes`. It has no caller
on the display path today (only `avm2_text.c:7767/:7912`).

*Fix:* one line at `avm2_display.c:10812` →
`avm2_display_child_char_for_class(ctx, obj->cls)`. Cost is nil when
`g_child_movie_count == 0`. (Line number moved from the s8 report's
`:10767` — re-verified against HEAD.)

*Rows it owns:* expected 11, 12, 37, 45/48 content + suppresses the
spurious `RangeError #2006` and its 3 stack lines (actual 9-12), and
un-aborts the framescript so expected row 13 ("Framescript
loader_domain_child: clip = …") reappears. ≈6 rows.

**Cause B — `class_for_char`'s child arm resolves in the ROOT domain
scope.** (The §10.3 finding; confirmed at HEAD.)

* `avm2_display.c:1511-1513` — `class_for_dotted_name()` is hard-wired to
  `avm2_domain_root_scope(ctx)`.
* `avm2_display.c:1516-1569` — `class_for_char`: the child-movie loop
  (:1531-1543) calls that root-scoped helper.
* `avm2_display.c:1575-1600` — `nondisplay_class_for_char`: same bug in
  its child loop (:1587-1598).

A child loaded into a *fresh* `ApplicationDomain` has its classes outside
the root scope, so the name lookup fails and the placed character falls
through to the char-kind default (plain `MovieClip`) — which is why the
child SWF's own **timeline-placed** `DuplicateClass` never runs its
constructor.

*Ingredients for the fix already exist*: `class_for_dotted_name_in(ctx,
scope, dotted)` at `avm2_display.c:1465`, and `Avm2AbcFileRt.scope` at
`SWFModernRuntime/include/avm2/avm2_abc.h:613`. Missing piece = a
movie→scope accessor: given `const Avm2MovieTables* t` (definition
`avm2_abc.h:570`, field `abc_files` at :572), scan `ctx->files[i]` for
`files[i]->data == t->abc_files[0]` and return `files[i]->scope`. ~20-25
lines total (accessor + 2 call sites).

*Rows it owns:* expected 5, 6, 20, and the content of 30; suppresses the
spurious `TypeError #1034` ("cannot convert flash.display::MovieClip to
DuplicateClass" — a placed child that stayed a plain MovieClip being
assigned to a typed public var). ≈5 rows.

*Caveat for the implementer:* the "repeated child domain load" section
re-loads `loader_domain_child.swf`; per memory `avm2-child-movie-tables`
gotcha 3 the ABC file object is REUSED and only the script init state is
re-armed, so `file->scope` is the **latest** domain. Expected rows 42-49
show Flash resolving the re-loaded child's `DuplicateClass` to
`"from loader_same_domain"`, so a naive "use the file's current scope"
may accidentally be right here — verify, don't assume.

**Cause C — frame-script / constructor ordering across the load.**
After A and B, ~6 rows in the last two sections are pure ordering
(placed-instance ctor vs `callMe` script-init vs framescript vs the `INIT`
event). Compare expected 29→33 with actual 28→32, and expected 40→49 with
actual 39→49. **No mechanism identified**; this is the residual and it is
the one that decides whether the test flips.

### Yield / effort
* Fix A: 1 line. Fix B: ~25 lines. Fix C: unknown, likely a dedicated arc.
* **Predicted yield of A alone: 0. Of A+B: 0. Of A+B+C: +1.**
* **Not shared with any other failing test.** I checked every failing test
  whose name contains loader/domain/symbolclass/child (248 failing tests
  corpus-wide). The nearest neighbours have unrelated mechanisms:
  `loader_applicationDomain` (0 actual lines — silent, Flex
  `PropertyChangeEvent`/`ByteArrayAsset` surface), `appdomain_lookup_edge_cases`
  (aborts at `ApplicationDomain.getDefinition("<integerValue>")` — #1065
  thrown where Flash prints `error: 1107`),
  `from_shumway/as3-loader/*`. None is unblocked by A or B.
* Canaries if taken (all baseline `pass`): `avm2/instantiate_root_character`,
  `loader_events`, `loader_child_getdefinition`, `loader_loadbytes_url`,
  `loader_reuse`, `loaderinfo_root`, `loader_error_in_root_ctor`,
  `loader_loadbytes_events`, `loader_duplicate_coerce`,
  `away3d_advanced_shallow_water_demo` (0/0 silence assertion — flips on
  ANY new stderr line), `font_enumeratefonts_order`, `get_definition_by_name`,
  `regression/avm2_loader_stub`.

### Cross-lead interaction
None. Touches `avm2_display.c` only; no other lead does.

---

## Lead 2 — stale `avm2/ignored_tests.txt` prune

**VERDICT: TAKE — but it is REPORT HYGIENE, not yield. Graded delta = 0.**

### What a prune actually moves (measured, not assumed)
* Ignored tests **are run and are already in `results_graphics.json`** —
  the list only feeds `filter_results.py`, which writes the `*_filtered.*`
  copies, plus `scripts/generate_ruffle_comparison.py` and
  `generate_failing_by_feature.py`.
* The **headline 4176/4424 is the UNFILTERED sum**, verified arithmetically
  (avm1 690 + avm2 1107 + from_avmplus 1560 + gnash 371 + shumway 197 +
  the nine small categories = 4176; totals sum to 4424).
* Therefore **pruning moves neither the numerator nor the denominator of
  the graded number.** It moves only the filtered report:
  avm2 filtered goes **907/997 (91.0%) → 1080/1170 (92.3%)**.

### Complete stale enumeration (223 avm2 entries, **173 stale**)
"Stale" = listed as ignored, currently `pass` (full match against the
Flash-expected `output.txt`).

| bucket | entries | **stale (pass)** | ruffle_matched | still failing |
|---|---|---|---|---|
| GPU / shader / AIR | 63 | **63 (all)** | 0 | 0 |
| Host I/O (net/audio/video/camera) | 50 | **38** | 2 | 10 |
| Image-comparison tests | 76 | **68** | 2 | 6 |
| Upstream `known_failure = true` | 32 | **3** | 20 | 9 |
| upstream `ignore = true` in test.toml | 2 | **1** | 0 | 1 |
| **total** | **223** | **173** | **24** | **26** |

**Exact prune, by bucket:**

1. **GPU / shader / AIR — delete the whole bucket (63 lines).** Every
   entry passes on the trace axis; the header claim "permanently out of
   scope for this runner" is now factually wrong. (`agal_compiler`,
   `air_*` ×3, `pixelbender_*` ×31, `stage3d_*` ×28.)
2. **Host I/O — delete 38 lines:** `filereference_*` ×7,
   `filereferencelist_*` ×2, `localconnection_send`, `netconnection_close`,
   `netconnection_properties`, `netconnection_send_remote`,
   `netconnection_serialize_arrays`, `netstream_client`, `netstream_connect`,
   `socket_*` ×9, `sound_embeddedprops`, `sound_play`, `sound_valueof`,
   `soundchannel_soundtransform`, `soundchannel_soundtransform_exists`,
   `soundchannel_stop`, `soundmixer_buffertime`, `soundmixer_stopall`,
   `soundtransform`, **`url_loader`, `url_vars`, `urlrequest`,
   `urlstream_basic`**. KEEP the 10 still-failing + the 2 `ruffle_matched`
   (`soundchannel_position`, `soundchannel_soundcomplete`).
3. **Image-comparison — delete 68 lines** (all `bitmapdata_*`, `blend_*`,
   `graphics_*`, `edittext_*` visual, `focus*`, `loader_image/jpegxr/events`,
   `error_stack_trace_*`, `mouse_pick_*`, `mask_reapply`,
   `sprite_with_frames`, `symbol_class_conflict`,
   `away3d_advanced_shallow_water_demo`, …). **Safe for the pixel axis**:
   `scripts/image_triage.py:610` classifies a suite-local ignore as
   "TRACE-axis triage, **kept on the board**", so the image board is
   unaffected either way. KEEP the 6 still-failing + 2 `ruffle_matched`.
4. **Upstream `known_failure` — delete 3 lines**: `amf_array_serialization`,
   `simplebutton_childevents_sprite`,
   `tab_ordering_stage_tab_children_remove_root`. These are wins being
   hidden (we match Flash where Ruffle does not). KEEP all 20
   `ruffle_matched` + 9 failing.
5. **upstream `ignore = true`** — `bytearray_oom` passes, but the entry
   records an UPSTREAM decision (test disabled in its own `test.toml`).
   Recommend KEEP, with a comment.

**Secondary finding (out of the brief's scope, do NOT prune blind):** the
GLOBAL `ruffle-tests/ignored_tests.txt` (43 entries) also suppresses 4
tests in the avm2 suite: `date` (avm2 **pass**, avm1 `output_mismatch` —
the entry is genuinely about the avm1 test, but the global list hides the
avm2 one), `string_relational_compare` (**pass in both** suites),
`xml_socket` (**pass in both**), `sandbox_type_remote` (fails, correctly
ignored). `date` and `string_relational_compare` have live ACCEPTED_DIFFS /
RUFFLE_VS_FLASH entries, so any global prune must edit those docs in the
same commit — file as a separate hygiene item.

### Yield / effort
Graded **+0**. Effort ~15 min (delete 173 lines, add a dated comment
explaining the re-triage). Risk: zero — pruned tests are already run and
already counted.

### Cross-lead interaction
None.

---

## Lead 3 — C3.3, trailing #1065 after a file-level VerifyError

**VERDICT: SKIP the blind version.** The doc's "net 0" pricing is **wrong**
— it is headline **+1 with a hidden correctness regression**, which is
worse than net 0. A *discriminated* variant is +1 clean but rests on n=2
evidence; see below.

### Evidence
| test | expected (`output.txt`, Flash) | our actual | status |
|---|---|---|---|
| `verify_method_info_duplicate` | `#1121` **+ `ReferenceError #1065`** | `#1121` only | `output_mismatch` (1/2) |
| `verify_method_info_oob` | `#1027` only | `#1027` only | **pass** |

**The finding the earlier pricing missed:** `verify_method_info_oob` HAS an
`output.ruffle.txt`, and it reads `#1027` **+ `#1065`**. Both tests are
`known_failure = true`. So a blanket "emit the trailing #1065 after any
file-level VerifyError" gives:

* `_duplicate` → matches `output.txt` → **pass** (+1 effective_pass)
* `_oob` → matches `output.ruffle.txt` → **`ruffle_matched`** — which
  still counts in `effective_pass` (avm2: 1080 pass + 27 rm = 1107).

Headline therefore reads **+1, zero regressions**, while the change has
actually demoted `_oob` from Flash-correct to Ruffle-only-correct. This is
exactly the `ruffle-matched-hides-regression` trap (memory ★★). **One line
of evidence: `ruffle-tests/tests/swfs/avm2/verify_method_info_oob/output.ruffle.txt`
already contains the trailing `ReferenceError: Error #1065`.**

### Why a principled discriminator does not exist in our tree
Both errors are thrown from the **same loop**, four lines apart:
`SWFRecomp/src/abc/abc_parser.cpp:614` (#1027) and `:624` (#1121), inside
`readMethodBody`. There is no parse-stage distinction to key on. The two
SWFs differ only in the patched byte (`patch.r2`: `wx 02 @ 0x221` vs
`wx 07 @ 0x271`) and in `hello()` being `public` vs `private`. Across the
whole `verify_*` family only these two are file-level, so the evidence for
"why does Flash continue to the SymbolClass tag for #1121 but not #1027" is
n=2.

The emit path, if anyone takes the narrow variant: `SWFRecomp/src/swf.cpp:6217-6252`
(`emitAbcLoadError` for parse and validate failures) and
`SWFRecomp/src/abc/abc_emit.cpp:3882` (the stub-ABC builder). The trailing
#1065 would come from letting the SymbolClass binding still run after a
file-level error.

**Narrow variant (optional, not recommended as-is):** gate the trailing
#1065 on error code 1121 (continue) vs 1027/1107 (abort the tag stream).
~5 lines, **+1 test, no regression**, but it is a 2-point curve fit and
must be filed in `RUFFLE_COMPAT_TWEAKS.md` if taken.

### Cross-lead interaction
Only lead touching the recompiler ABC front end. No conflicts.

---

## Lead 4 — `from_avmplus/e4x/Statements/e12_1`

**VERDICT: TAKE. +1 test, ~15 lines, TWO runtime sites, NO recompiler work.**

### Two corrections to §10.4's framing

1. **"needs recompiler `SETS_DXNS` support" is stale.** The flag already
   flows end-to-end:
   * parsed raw — `abc_parser.cpp:375` (`m.flags = r.readU8()`),
     `METHOD_SET_DXNS = 1 << 6` at `SWFRecomp/include/abc/abc_types.hpp:124`;
   * verified — `abc_verifier.cpp:1149-1175` (`dxns`/`dxnslate` without the
     flag → VerifyError; `avm2/verify_dxns_without_flag` passes);
   * **emitted raw** — `abc_emit.cpp:3845` writes `(unsigned) m.flags` into
     `Avm2AbcMethodData.flags`. Measured on the test's own generated table
     (`e12_1/RecompiledABC/abc0_methods.c`): flags histogram
     `35×0, 1×2, 1×4, 3×64` — the three `0x40` rows are exactly the script
     init, `scopeTest` and `f`;
   * consumed — `avm2_class.c:1071-1083` already does save / reset-if-
     `(flags & (1u<<6))` / restore around `avm2_call_method_ref`.
   The only missing piece in the runtime enum is a name for bit 6
   (`avm2_abc.h:88-97` stops at `AVM2_METHOD_NATIVE = 1 << 5`; :1076 uses
   a bare `(1u << 6)`).

2. **The oracle question is already answered by the graded expected
   output.** `output.txt` (avmplus) has all 17 lines `PASSED`, including
   13 and 14; `output.ruffle.txt` fails 8 and 14. **Grade against
   `output.txt` = implement ECMA-357 §13.3.2 (single-arg `QName` captures
   the default XML namespace), i.e. the avmplus rule, not Ruffle's.**
   Do NOT chase `ruffle_matched` here — reaching it would require
   *breaking* line 8, which we currently pass.

### The two real fix sites

**Fix 4a — `avm2_call_function_obj` has no dxns handling at all.**
`SWFModernRuntime/src/avm2/avm2_class.c:1102-1141`. It is the *other* of
the only two `Avm2Activation act;` construction sites in the runtime
(grep confirms exactly two: `:1061` and `:1129`). Script-level `function`
declarations — which is what `scopeTest()` and `f()` are in this test —
are invoked through it, so `SET_DXNS` is never honoured and dxns leaks out
of the callee. Copy `:1073-1083` verbatim around `:1137` (using
`fnobj->fn_method`). ~6 lines.
*Wins line 4* (`myGetNamespace(x1).uri` inside `scopeTest` must be `""`
because the method's own `default xml namespace` statement makes its entry
value the unnamed namespace — Ruffle `activation.rs:422-424`, same rule).

**Fix 4b — single-arg `QName` must capture the DXNS.**
`SWFModernRuntime/src/avm2/avm2_nsqname.c`, `qname_construct`, the
`argc < 2` branch — the line `uri = empty;  // public namespace` (≈:296).
Replace with `const Avm2String* d = avm2_dxns_uri(ctx); uri = (d != NULL) ? d : empty;`,
keeping the existing `"*"` → any-namespace arm (ECMA-357 §13.3.2 step 4a).
`qname_construct` already takes `Avm2Context*` and `avm2_dxns_uri` is
declared in `avm2_e4x.h:204`, so no plumbing. ~5 lines.
*Wins lines 13 and 14*: `q = new QName("a")` is built while
`default xml namespace = ns` ("http://someuri") is in effect, so `q` must
be `ns::a`; line 14 then writes through `q` after DXNS has been reset to
`""`. Our current 13 = `""` / 14 = `"foo"` is exactly the public-`a`
signature.
*Residual risk*: line 13 is near-certain; line 14 additionally requires
our `setproperty`-by-QName path to honour the QName's uri (it should —
line 12, the string-key equivalent, already passes). If 14 alone survives,
the test stays `output_mismatch` and the yield is 0.

The current comment at `avm2_main.h:53-57` claims dxns "is restored on
exception unwinds via the try-frame snapshot" — **there is no such
snapshot** (`grep dxns` over the runtime finds no reference in
`avm2_error.c`). Out of scope, but worth a comment correction.

### Yield / effort / canaries
* **Predicted: +1** (`e4x/Statements/e12_1` `output_mismatch` 14/17 → `pass`).
* Effort: ~15 lines across 2 files, no recompiler rebuild needed.
* Canaries — the 18 other corpus tests that construct a single-arg
  `QName`, **all currently `pass`**: `avm2/qname_constr`, `qname_indexing`,
  `qname_enumeration`, `qname_tostring`, `qname_valueof`,
  `qname_as_lazy_name_attribute_multiname`,
  `from_avmplus/e4x/{Expressions/e11_1_1, Expressions/e11_5_1,
  QName/e13_3_1, QName/e13_3_2, QName/e13_3_4_2, QName/e13_3_5,
  XML/e13_4_4_4, XML/e13_4_4_22, XML/e13_4_4_28, XML/e13_4_4_34,
  XML/e13_4_4_35, XMLList/e13_5_4_17}`. None of the 18 uses
  `default xml namespace`, so 4b is inert for them.
* DXNS canaries for 4a (all currently `pass`):
  `from_avmplus/e4x/Expressions/e11_3_1`, `from_avmplus/e4x/Types/e9_1_1_9`,
  `avm2/verify_dxns_without_flag`, `avm2/xml_descendants`,
  `avm2/flash_xml_namespace`, `avm2/error_geterrormessage`.

### Cross-lead interaction
Fix 4a edits `avm2_class.c:1102-1141`, ~20 lines below the block lead 1
does *not* touch. No conflicts with leads 1/2/3/5.

---

## Lead 5 — `avm2/scope_optimizations` (verifier lattice Stage 3)

**VERDICT: DEFER — confirmed "separate arc". Scope-sized only, as briefed.**

* Current: `output_mismatch`, `actual=4 / expected=4 / matching=3`. Sole
  bad line: `With coerce:` traces `0`, expected `[class field]`.
* Tests it would win: **exactly 1.** The lattice arc doc
  (`SWFRecompDocs/plans/abc-verifier-type-lattice-arc.md` §3.3, §6) already
  ran the corpus-wide scan for the sibling signatures and found no other
  candidate; §6's yield table lists `scope_optimizations` as the *only*
  Stage-3 row and scores it `0` for Stages 0-2 (which landed in `a835b09fb`,
  session 8, +2). I ran no new census — it would need `--dump-abc` over the
  whole corpus for a 1-test lead.
* Work: it is **not** a verify-time check, it is verify-time **early
  binding** — `FindPropStrict` must be statically lowered to
  `GetGlobalScope`/`FindDef` when the typed scope entry provably lacks the
  name (test IR: `ConstructProp Subclass; Coerce Superclass; PushScope;
  FindPropStrict field` must MISS the scope object because the *static*
  type is `Superclass`). That changes **emitted code at every
  `findpropstrict` site**, not just error paths. Prerequisites: lattice
  Stage 2 (real merges, `this`/parameter seeding, scope-stack typing —
  doc §"Stage 2", explicitly "only worth doing if Stage 3 is on the
  board"), then Stage 3.
* Blast radius, from the doc's own census (§5): scope-object-based slot
  access is 99.1% of 57,850 `GetSlot` sites; `findpropstrict` is the same
  order of magnitude. Any mistake silently changes which object a name
  resolves to in **every AVM2 title we run** (Elephant Quest, Snailiad,
  RWK, seedling …), not just tests.
* **Effort: multi-session arc (own scoping doc + risk analysis + a
  game-level canary set) for +1 test.** Lowest ROI on the board. Only
  revisit if an unrelated need for static early binding appears (e.g. a
  perf lever — it is a plausible `findprop` IC accelerator, which is a
  different justification than corpus yield).

### Cross-lead interaction
Would sit on top of lead 3's file (`abc_verifier.cpp` / `abc_emit.cpp`) if
both were ever taken — but neither is recommended this session.

---

## Summary table

| lead | verdict | yield | effort | files |
|---|---|---|---|---|
| 1 `loader_duplicate_class` | **DEFER** | +1 only if all 3 causes land; A+B = 0 | 1 line + ~25 lines + unknown | `avm2_display.c:10812`, `:1511`, `:1531`, `:1587` |
| 2 avm2 ignore-list prune | **TAKE** (hygiene) | graded **+0**; filtered 907/997 → 1080/1170 | ~15 min, 173 lines deleted | `avm2/ignored_tests.txt` |
| 3 C3.3 trailing #1065 | **SKIP** | blind = +1 headline / −1 correctness; narrow = +1 | 5 lines (narrow) | `swf.cpp:6217-6252`, `abc_emit.cpp:3882` |
| 4 `e12_1` | **TAKE** | **+1** | ~15 lines, 2 sites, no recompiler | `avm2_class.c:1102-1141`, `avm2_nsqname.c` (`qname_construct`) |
| 5 `scope_optimizations` | **DEFER** | +1 | multi-session arc | verifier + emitter, corpus-wide |
