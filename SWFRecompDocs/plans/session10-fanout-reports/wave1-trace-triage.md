# Wave-1 trace-axis triage — session 9 (regenerated at `feb8882b0`)

Read-only. No source edits, no git state changes.

Data: the 19 top-level leaf `results_graphics.json` (nested `_results` under
`from_avmplus/as3/Vector[/nonindexproperty]`, `from_gnash/misc-ming.all/
displaylist_depths`, `from_shumway/{avm1,timeline}` excluded — double-count
trap). All 19 carry `git_sha = feb8882b09e2…`, total **4424**, `pass 3932 +
ruffle_matched 244 = 4176 (94.4 %)` — exactly the stated baseline, so the
board below is the real current tree.

Scripts + raw dumps (scratchpad): `near_pass.py`, `near.json`,
`all_fail.json`, `near_diffs.txt`.

---

## (a) The board, and how it moved

| | s8 in | s9 in (now) |
|---|---|---|
| near-pass candidates (gap = expected−matching ≤ 5) | 78 | **59** |
| total non-`pass`/`ruffle_matched` | ~248 | 248 |
| status histogram | — | `output_mismatch 246`, **`runtime_error 1`**, **`recomp_fail 1`** |

78 → 59 = −19. Session 8 landed +23, of which 4 were outside the ≤5 window
(the `superinterface_instanceof`-style riders), so the well refilled by **≈ 0
rows**. Prior refills: s5–s7 5–10 rows, s8 exactly 1, s9 **zero**. *The
near-pass list is now a closed inventory, not a sample.* Every future
near-pass session is spending down a fixed 59, minus dispositions.

Per suite (59): avm2 23 · from_shumway 11 · from_avmplus 7 · avm1 6 ·
mixed_avm 6 · visual 2 · audio/fonts/text/`from_gnash/misc-swfc.all` 1 each.
Gap histogram `0:6 1:17 2:13 3:7 4:11 5:5`.

**Dispositioned out of the 59 (14 rows — do not target):**
`avm1/{geturl, native_objects_swf6, sandbox_type_remote}`,
`avm2/{sandbox_type_remote, bitmapdata_draw_alpha_erase, netstream_flv_date,
sound_constructor_with_args, sound_rootless}` (ignore lists),
`avm2/{bom, loader_load}` (RUFFLE_VS_FLASH, permanent ceilings),
`from_shumway/{esc, fuzz/f404…}`, `from_gnash/misc-swfc.all/sound` (ignore
lists), `from_avmplus/recursion/pcre_find_fixedlength` (documented ceiling,
§1). **Live pool = 45.**

Shoulder population, for rider picking: gap 6–10 = 38 tests, gap 11–20 = 32,
gap > 20 = 119. There is a real bump at gap 6 (20 tests) that contains
direct siblings of near-pass rows (`doabc_and_symbolclass_script_init_goto`,
`avm2_loads_avm1_v9`, `eforin_002`, `matrix3d/TransformBasics`).

---

## (b) The clustering key that pays this session

Confirmed dry again, do not re-mine: `error_signature` Counter (max group 1),
"expected #NNNN got: no error" (zero hits), namespace-half, runtime-name-half,
E4X ops layer. I also re-ran a **same-index error-code substitution census**
(`exp #A → act #B` per line) over all 248 failures — max group **1**. Dry.

The `runtime_error`/`recomp_fail` axis (cheapest, checked first) is down to
**exactly two rows** — but both turned out to be takeable, one of them
measured to a full PASS in this session (see B2, B9).

**The key that pays is a two-axis bucketing, not a string key:**

> **Axis 1 — capability gap.** For each candidate ask *what capability must
> the tree gain*, not *what string do the diffs share*. At 94.4 % the
> residue is no longer semantics bugs (those are what s4–s8 harvested); it
> is **absent API surface** and **absent cross-movie execution**. String
> keys can't see this because each missing capability produces a different
> string.
>
> **Axis 2 — oracle conflict.** For each candidate, check whether some
> *other* already-green or near-green test pins the **opposite** value.
> This is the generalisation of §10.2's lesson: `ACCEPTED_DIFFS` /
> `ignored_tests` catch *declared* traps; axis 2 catches *undeclared* ones.
> It found **2 new traps** in the 45-row live pool that read as clean
> 4-line wins.

### Axis-1 cluster table (45 live rows)

| Cluster | Tests (near) | Riders (gap 6+) | Lines | Capability missing |
|---|---|---|---|---|
| **Cross-VM / child-SWF execution** (`mixed_avm`, AVM1Movie, cross-VM focus/pick) | 10 | +2 (`avm2_loads_avm1_v9`, `import_assets/avm1_*`) | 29 | dual-VM arc — declared out of scope, `loader-arc.md:793` |
| **Loader / applicationDomain / getDefinition** | 6 | — | 11 | child-domain resolution (= larger half of `loader_duplicate_class`, §10.4 — **overlap, another agent**) |
| **Absent builtin API surface** (`SoundMixer.computeSpectrum`, `System.exit`, `FullScreenEvent`, `NetFilterEvent`, `Transform.getRelativeMatrix3D`, `StaticText.text`) | 3 | +6 | 60+ | class/method stubs + one real DSP feature |
| **Device-font metrics from `test.toml` TTFs** | 1 | +5 | 161 | harness/recompiler must honour `[fonts.*]`/`[font_sorts]` |
| **Sealed-receiver property error taxonomy** (#1056, #1081) | 2 | — | 5 | one discriminator in `getproperty`/`setproperty` miss paths |
| **SymbolClass instantiation & DoABC script-init timing** | 3 | +1 | 11 | run the class chain once; lazy script init |
| **CSS `StyleSheet` value parsing** | 2 | — | 7 | `parseInt(s,16)` prefix semantics; `display` reject → null |
| **Hit-test / `getObjectsUnderPoint`** | 2 | — | 4 | `hitTestState` child must not be reported |
| **Text/link geometry** (`links_in_scrolled_text`) | 1 | — | 1 | link hit-test must offset by `TextField.scroll` |
| **Memory / GC** (`bug_483783`) | 1 | — | 1 | intermediate strings never reclaimed |
| **Harness** (`heavy_tesselation`) | 1 | — | 1 | 30 s recompile timeout |
| singles with no cluster | 13 | — | 26 | — |

### Axis-2: NEW undeclared traps found (do NOT let wave 2 chase these)

1. **`from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`**
   (gap 4). Two of its four lines want `focalLength = 480.2455317428`
   (Flash double). `avm2_display.c:9729 pp_focal_length` deliberately does
   `(double)(float)…` because **`avm2/perspective_projection` pins
   `480.24554443359375` in 10 separate lines** (and is itself near-green at
   1368/1443). The two expectations are mutually exclusive; taking the
   Shumway one costs the Ruffle one. → **ACCEPTED_DIFFS candidate.** Only
   the other 2 lines (`returns a clone`, root `projectionCenter`/setter
   persistence) are real, and they cannot flip the test alone.
2. **`from_avmplus/ecma3/Statements/eforin_001` (gap 4) + `eforin_002`
   (gap 10, sibling).** `for…in` order over `{length:4, company:…,
   year:2000, 0:"zero"}`. Three different orders exist: `output.txt`
   (avmplus hashtable) `0,company,year,length`; `output.ruffle.txt`
   `year,company,length,0`; ours `0,year,company,length`. Insertion order is
   `length,company,year,0` — i.e. **none** of the three is insertion order.
   This is hash-order UB in both oracles. → **ACCEPTED_DIFFS candidate**
   (14 lines that look like a clean enumeration-order fix and are not).

Axis-2 also produced one *positive*: **`from_shumway/hittesting/hittesting`
is worth MORE than it looks** — Ruffle itself gets line 17 wrong, so fixing
our 2 lines scores a full `pass`, not `ruffle_matched`.

### 3-way `ruffle_matched` reachability (run over all 59)

Only 7 candidates have an `output.ruffle.txt` at all; of those,
`from_avmplus/ecma3/Number/toLocaleString_rt` is the money one: its 4th
diff line (`1.2345000000000002e-7`) **already matches Ruffle byte-for-byte**,
so fixing only the 3 error-code lines flips it to `ruffle_matched`. Measured
by direct `diff output.txt output.ruffle.txt`.

---

## (c) Ranked wave-2 batch proposals

Ranked by yield ÷ effort × confidence. Predicted yields are **lower bounds**
(§9: cross-patch synergy on a merged wave).

---

### B1 — Harness recompile timeout (**measured to PASS in this session**)
- **Tests:** `visual/simple_shapes/heavy_tesselation` (the corpus's only
  `recomp_fail`).
- **Mechanism — MEASURED, not suspected.** The SWF recompiles in **54.5 s**;
  `verify_output.py:1907` hard-codes a 30 s recompile timeout
  (`SWFRECOMP_RECOMPILE_TIMEOUT` overrides it and nothing in `.github/` sets
  it). With `SWFRECOMP_RECOMPILE_TIMEOUT=600 … --recompile` the test scores
  **PASS** locally (`r=54.47s c=105.14s`). It is not a correctness bug.
- **Files:** `ruffle-tests/verify_output.py` (~1905–1930); optionally a
  per-test `recompile_timeout` key in `test.toml` instead of raising the
  global default.
- **Yield:** +1, and the `recomp_fail` bucket disappears from the histogram.
- **Effort:** XS (≤10 lines). **Confidence: VERY HIGH** (end-to-end measured).
- **CI cost:** one test × ~25 extra seconds. Prefer a per-test override or a
  default of 120 s; do not remove the timeout.
- **Checked against dispositions:** not in `ignored_tests.txt` (any suite),
  not in ACCEPTED_DIFFS / RUFFLE_VS_FLASH / RUFFLE_COMPAT_TWEAKS /
  FLASH_BUGS_REPLICATED. No oracle conflict (no other test constrains
  recompile wall-clock).

---

### B2 — CSS `StyleSheet` value parsing
- **Tests:** `avm2/stylesheet_parse_color` (gap 4), `avm2/stylesheet_transform`
  (gap 3). This is session-1's **B10, never taken**.
- **Mechanism — diagnosed.** `avm2_text.c:4422 style_transform` gates the
  `#rrggbb` path on `cs->len <= 7` and requires *every* remaining char to be
  a hex digit. The failing CSS values are `#ff0000 ` / `#ff0000\t ` (the
  declaration is `color: #ff0000 0;`), so the gate fails and the colour
  collapses to 0. Flash's `innerParseColor` does
  `parseInt(color.substring(1), 16)` — **parseInt semantics: consume the
  leading hex-digit run, stop at the first invalid char**, no length cap.
  Second half: an unrecognised `display` value (`"invalid"`) must clear the
  field to null; we leave `format_default()`'s `display = block` present
  (`avm2_text.c:4448-4457`). Third, smaller: `styleSheet.transform(null)`
  must throw #1069 (`! 1069`), we return `null`.
- **Files:** `SWFModernRuntime/src/avm2/avm2_text.c` (single function,
  ~4415–4460). AVM1's copy is `action.c:16157 stylesheetTransform` — same
  bug, no failing AVM1 test; fix both or note it.
- **Yield:** +2. **Effort:** S. **Confidence: HIGH.**
- **Checked against dispositions:** neither test appears in any of the four
  disposition docs nor in `ruffle-tests/ignored_tests.txt`,
  `avm2/ignored_tests.txt`, `from_shumway/ignored_tests.txt`. No oracle
  conflict: grepped every `output.txt` for `parsed color:` — only these two
  tests constrain it.

---

### B3 — `StaticText.text`
- **Tests:** `avm2/statictext_text` (gap 8 — outside the window, rider by
  mechanism), `from_shumway/acid/acid-text-2` (gap 1).
- **Mechanism — diagnosed.** `flash.text.StaticText` is registered
  (`avm2_display.c:13239`) but has **no `text` getter**, so all 8 reads
  return `undefined` (expected `AB` / `CGDA` / `null` / `AXTD R` / `null`).
  Everything needed is already emitted at recompile time:
  `Avm2StaticTextData{char_id, glyph_start, glyph_count}` →
  `avm2_generated_static_glyphs[]` (`Avm2StaticGlyph{font_id, glyph, …}`)
  and `Avm2FontData.codes` is exactly *glyph index → character code*
  (`avm2_abc.h:415-452`). The getter is a walk + code lookup;
  `codes == NULL` (device-fallback font, no code table) is the `null` case
  the expectations already contain. `statictext_for(char_id)` already
  exists at `avm2_display.c:426`.
- **Files:** `SWFModernRuntime/src/avm2/avm2_display.c` (getter +
  registration near 13239), read-only use of `avm2_abc.h` tables.
- **Yield:** +2. **Effort:** S–M. **Confidence: HIGH.**
- **Checked against dispositions:** neither in any disposition doc nor in
  any `ignored_tests.txt`. No oracle conflict — no other `output.txt`
  constrains a StaticText `text` read.

---

### B4 — Sealed-receiver property-error taxonomy (#1056 / #1081)
- **Tests:** `from_avmplus/ecma3/Number/toLocaleString_rt` (gap 4 →
  **`ruffle_matched`**), `from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs`
  (gap 1; session-1 **B6**, one prior attempt reverted).
- **Mechanism — half diagnosed, half new evidence.**
  - *`toLocaleString_rt` (3 lines):* `s = Number.prototype.toLocaleString;
    o = new Number(); o.toLocaleString = s;` must throw **#1056** ("cannot
    create property on a sealed class"); we throw **#1037** ("cannot assign
    to a method"). The write misses the instance's traits and finds the name
    only on the *prototype* — a prototype method must not route to #1037.
    The 4th diff line is a double-formatting difference **Ruffle also
    fails identically**, so fixing the 3 error lines makes our output equal
    `output.ruffle.txt` → `ruffle_matched` (verified by direct diff).
  - *`Error1081ReadSealedErrorNs` (1 line):* the previous attempt widened
    `getproperty_common`'s condition to `!mn_public` and lost
    `avm2/catch_class` + `AccStatPropViaSubClass` to win this one — the
    comment at `avm2_ops.c:668-682` records the revert and says the right
    site is unidentified. **New evidence from `--dump-abc`:** the failing
    site is `9: GetPropertyStatic mn[101] {ns-set 10}::name`, where
    `ns-set[10] = {ns "IClass"}` — a **multiname (ns-set) form carrying a
    single NON-public namespace**, whereas both casualties read through a
    **QName**. So the discriminator is the **multiname KIND**, not
    `mn_public`: ns-set multiname with no public namespace → #1081; QName →
    #1069. avmplus's `isAttr() || !containsAnyPublicNamespace()` and
    Ruffle's `!valid_dynamic_name()` (`script_object.rs:416`) are both
    consistent with this.
- **Files:** `SWFModernRuntime/src/avm2/avm2_ops.c` (`getproperty_common`
  ~651-694; the setproperty miss path near 860 / 3591); `avm2_error.c` for
  the #1056 message.
- **Yield:** +2. **Effort:** S–M. **Confidence: MED-HIGH** on
  `toLocaleString_rt`, **MED** on the #1081 discriminator.
- **MANDATORY canary:** `avm2/catch_class`,
  `from_avmplus/as3/Definitions/Classes/Ext/AccStatPropViaSubClass`,
  `from_avmplus/as3/Vector/bug_678952`, `avm2/dictionary_access_no_pubns` —
  these are the four tests the code comments name as pinning the current
  split. Do not land without all four green.
- **Checked against dispositions:** neither target appears in any of the four
  disposition docs or any `ignored_tests.txt`. The oracle conflict here is
  *internal* (the four canaries above) and is handled by the canary rule.

---

### B5 — An AS3 SWF's AVM1 tags are inert
- **Tests:** `mixed_avm/avm1_loads_avm2_doaction` (gap **0** — all 2 expected
  lines already match; we emit 2 *extra* lines).
- **Mechanism — diagnosed.** The child `avm2.swf` has the FileAttributes AS3
  bit set and also carries `DoAction`/`DoInitAction` tags; Flash ignores
  those tags entirely in an AS3 movie. We execute them, printing
  `Hello from inner SWF (DoInitAction) - this shouldn't print` /
  `Hello from inner SWF - this shouldn't print`. The **exact symmetric gate
  already exists** for the opposite direction: `SWFRecomp/src/swf.cpp:6191`
  skips `DoABC` when `!is_as3`, with a comment citing Ruffle's
  `movie.is_action_script_3()`. The missing half is `if (is_as3) skip` at the
  `SWF_TAG_DO_ACTION` (3248) / `SWF_TAG_DO_INIT_ACTION` (3304) cases, plus
  the DefineSprite-nested copies (5918 / 6022).
- **Files:** `SWFRecomp/src/swf.cpp` only. `is_as3` already lives on the
  parse context (`swf.hpp:305`).
- **Yield:** +1. **Effort:** XS–S. **Confidence: MED-HIGH.**
- **Blast radius:** any SWF in the corpus with FileAttributes-AS3 *and*
  DoAction tags. Recompiler change ⇒ manual cmake rebuild + a broad local
  sweep of `avm1`, `mixed_avm`, `import_assets`, `from_gnash` before CI.
- **Checked against dispositions:** not in any disposition doc; `mixed_avm`
  has no ignore list. NOTE: the wider `mixed_avm` family is the declared
  dual-VM arc (`loader-arc.md:793`) — this batch is **only the suppression
  half** and must not grow into that arc.

---

### B6 — `getObjectsUnderPoint` must ignore `hitTestState`
- **Tests:** `from_shumway/hittesting/hittesting` (gap 2).
- **Mechanism — suspected, well-localised.** Two lines assert
  `hitTestState doesn't affect getObjectsUnderPoint: true`; we return
  `false`, i.e. a `SimpleButton`'s `hitTestState` child is being reported by
  `getObjectsUnderPoint`. Site: `avm2_display.c:11687
  doc_get_objects_under_point`; the button state fields are at 13439.
- **Upside:** Ruffle *fails* one of these lines (`output.ruffle.txt` differs
  from `output.txt` at line 17 only), so a correct fix scores a full **pass**,
  strictly better than `ruffle_matched`.
- **Yield:** +1. **Effort:** S. **Confidence: MED-HIGH.**
- **Checked against dispositions:** `hittesting/hittesting` is not in
  `from_shumway/ignored_tests.txt` (which does list `hitTestStyleChange` —
  different test) and appears in no disposition doc. Canary the rest of the
  `mouse_pick_*` and `simplebutton_*` families, which constrain the same
  picking path.

---

### B7 — The only `runtime_error`: string temporaries are never reclaimed
- **Tests:** `from_avmplus/regress/bug_483783` (gap 1, corpus's only
  `runtime_error`).
- **Mechanism — MEASURED this session.** The test does
  `for (j = 0; j < 3000000; j++) myString += "a";`. We die with
  `ERROR: heap_alloc(76398) failed - out of memory` — i.e. we fall over at
  iteration ≈ 76 400, where Σ(1…76398) ≈ 2.9 GB, right at the harness's
  `ulimit -v 4194304` (`verify_output.py:1921`). Every intermediate concat
  result is retained. Two candidate fixes: (a) make concat temporaries
  actually collectable and/or (b) run a GC pass and retry on `heap_alloc`
  failure before declaring OOM. (b) is the cheap probe and tells you
  immediately whether (a) is already true.
- **Files:** `SWFModernRuntime/src/avm2/avm2_value.c` (`avm2_string_concat`),
  `avm2_gc.c`, the `heap_alloc` failure path. See memory
  `avm2-collectable-strings`, `avm2-raw-alloc-reclamation`.
- **Yield:** +1, and the `runtime_error` bucket goes to **zero** for the
  first time. Real-game value beyond the test.
- **Effort:** M (unknown until (b) is probed). **Confidence: MED.**
- **Checked against dispositions:** not in any disposition doc; `from_avmplus`
  has no ignore list. No oracle conflict.

---

### B8 — SymbolClass instantiation & DoABC script-init timing
Two related but *separable* mechanisms; give them to one agent, land as two
commits.
- **B8a — the linked-symbol class chain runs once, in order.**
  `avm2/subclass_superclass_linked_symbol` (gap 4, +2 extra lines),
  `avm2/graphic_linkage` (gap 2). Expected for 8a is
  `SubClass before super() → SuperClass before → SuperClass after →
  SubClass after` with `target_from_subclass` bound to `[object TargetClip]`
  *after* `super()`; we emit a whole extra `SuperClass before/after` pair
  **before** SubClass's ctor — the superclass ctor is being invoked a second
  time by the character-instantiation path instead of only via
  `constructsuper`. `graphic_linkage` wants a *script*-constructed
  `new MyText()` to report `my shape: 0 / 0` (its linked **Graphic** child is
  not instantiated) while the timeline-placed one reports `40.35`.
- **B8b — DoABC script inits are LAZY.**
  `avm2/doabc_and_symbolclass_script_init_normal` (gap 5) + rider
  `…_script_init_goto` (gap 6). We run all script initializers eagerly and in
  file order (`Z, C, B` right after `New`); expected runs them **later** and
  in `C, Z, B` order — i.e. each script's init fires when a definition it
  provides is first referenced (avmplus lazy-init; the `_goto` variant also
  expects `Test` to still be *inaccessible* at that point, #1065). See
  memory `avmplus-driver-eager-init-blanks-tests`.
- **Files:** `SWFModernRuntime/src/avm2/avm2_class.c`,
  `registered_class.c`, `abc_registry`-side emission in
  `SWFRecomp/src/abc/`.
- **Yield:** +2 (B8a) … +4 (both). **Effort:** M each. **Confidence: MED.**
- **Checked against dispositions:** none of the four tests is in any
  disposition doc or ignore list. Oracle check: script-init ordering is also
  constrained by `avm2/symbol_class_conflict` and the `from_avmplus` driver
  tests — canary the whole `from_avmplus` `categories=full` set (this batch
  is a reason to dispatch `categories=full`).

---

### B9 — Device fonts declared in `test.toml` (**SCOPE FIRST, don't implement blind**)
- **Tests:** `fonts/device_font_kerning` (gap 4), `fonts/device_font_glyph_fallback`
  (gap 7), `fonts/device_font_list` (gap 58); *possible* riders
  `visual/edittext/edittext_device_transform_{basic,metrics,negative}`
  (gap 12 / 20 / 60).
- **Mechanism — suspected.** These tests ship their own TTFs and declare them
  in `test.toml` (`[fonts.a] family="TestFont" path="TestFont.ttf"`,
  `[font_sorts.a] sort=["a","b"]`). Nothing in `verify_output.py` or the
  recompiler reads those keys, so every measurement falls back to our built-in
  device font — hence `LM width: 23` vs expected `50`. The recompiler already
  **has a TTF reader** for the device fallback
  (`SWFRecomp/src/swf.cpp:72-87`, `assets/NotoSans.ttf`, ASCII 32–126 pre-seed
  at 2355), so this is "point the existing loader at the test's TTFs and
  register them as named families", not new font tech.
- **Yield:** +2 (fonts only) … +5 (with the `edittext_device_transform` trio,
  IF they turn out to be font-metric and not transform bugs — **that is the
  scoping question**). 161 lines is the largest single line-count on the board.
- **Effort:** M–L. **Confidence: MED** on the fonts trio, **LOW** on the
  edittext riders until scoped.
- **Checked against dispositions:** none of the six is in any disposition doc;
  `fonts` and `visual` have no ignore lists. `avm2/ignored_tests.txt` does
  list `edittext_getcharboundaries_missing_embedded_font` — different test,
  and it is **currently passing** (see the prune note below), so it is not a
  constraint. No oracle conflict found.

---

## Explicit DO-NOT-TAKE list for wave 2

| Test(s) | Why |
|---|---|
| `from_shumway/.../PerspectiveProjectionClass` | focalLength double conflicts with `avm2/perspective_projection`'s 10 pinned f32 values → **new ACCEPTED_DIFFS entry wanted** |
| `from_avmplus/ecma3/Statements/eforin_001`, `eforin_002` | `for…in` hash-order UB; avmplus, Ruffle and we all differ → **new ACCEPTED_DIFFS entry wanted** |
| `avm1/native_objects_swf6` | already dispositioned; this is the exact §10.2 trap that cost 7 tests |
| `avm2/bom`, `avm2/loader_load` | RUFFLE_VS_FLASH, measured permanent ceilings |
| `from_avmplus/recursion/pcre_find_fixedlength` | documented libregexp ceiling (§1) |
| the 10 `mixed_avm`/cross-VM rows (except B5's suppression half) | declared dual-VM arc, `loader-arc.md:793` |
| `audio/g711`, `audio/aac`, `avm2/audio_computespectrum` | `SoundMixer.computeSpectrum` = real FFT over mixed audio; 3 tests / 137 lines, but it is a **feature arc**, not polish. Worth its own scoping doc. |

## Overlaps with the §10.4 board (another agent owns these — noted, not worked)

- `avm2/scope_optimizations` (gap 1) — lattice Stage 3.
- `from_avmplus/e4x/Statements/e12_1` (gap 3).
- `avm2/verify_method_info_duplicate` (gap 1) — C3.3.
- `avm2/loader_applicationDomain` (gap 4) + `avm2/swz` (gap 2) — both emit
  **zero** lines while expecting `[class ByteArrayAsset]` / `[class BitmapAsset]`
  / `[class PropertyChangeEvent]`; this is the embedded-Flex-asset +
  child-domain resolution half of `loader_duplicate_class`. Same for
  `from_shumway/as3-loader/{LoaderTest2, LoaderLoadBytesTest,
  bug1157243/empty, bug1157243/invalid}` (4 more, 6 lines).
- **`ignored_tests.txt` prune — much larger than §10.4 implies.** Measured
  against current results: **avm2 197 of 223 ignored entries now pass**,
  avm1 24 of 43, from_shumway 28 of 46 = **249 stale entries**. Also
  `ruffle-tests/ignored_tests.txt` lists 2 tests that no longer exist in
  results (`shared_object`, `shared_object_self_ref`). This does not move the
  unfiltered 4176/4424, but it makes every *filtered* number meaningless.

## Predicted wave-2 total

B1 +1 · B2 +2 · B3 +2 · B4 +2 · B5 +1 · B6 +1 · B7 +1 · B8 +2…4 · B9 +2…5
= **+14 conservative, +19 optimistic**, from a live pool of 45. Per §9 this
is a lower bound on a merged wave.
