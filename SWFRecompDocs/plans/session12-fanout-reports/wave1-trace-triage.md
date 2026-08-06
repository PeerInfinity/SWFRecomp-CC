# Wave-1 trace-axis triage — session 12 (regenerated at `f166e424e`)

Read-only. No source edits, no git-state changes. Scratch:
`scratchpad/{board.py, all_fail.json, live.json, runjob.sh, jobs/*.txt}`.

Data: the 19 top-level leaf `results_graphics.json` (the five nested
`_results` — `from_avmplus/as3/Vector[/nonindexproperty]`,
`from_gnash/misc-ming.all/displaylist_depths`, `from_shumway/{avm1,timeline}` —
excluded as double-counts, per `corpus-denominator-double-counts-nested`).
All 19 carry `git_sha = 6de650432`, timestamp `2026-08-06T06:23Z` (CI run
`31075033086`), total **4427**, `pass 3956 + ruffle_matched 248 = 4204`.
That is the stated 4203 baseline + the corpus drift (see §0), so the board
below is the real current tree.

Every target in §3 was **re-verified failing locally at HEAD on 2026-08-06**
by an individual `verify_output.py --test=… --diff` run (no-graphics; mode
parity is complete). Line counts matched the graphics baseline in every case.

---

## 0. The board, and how it moved

| | s10 in | s11 in | **s12 in (now)** |
|---|---|---|---|
| corpus total | 4424 | 4424 | **4427** |
| pass + ruffle_matched | — | 4188 | **4204** |
| total non-`pass`/`ruffle_matched` | 248 | 236 | **223** |
| near-pass (gap = expected−matching ≤ 5) | 59 | 49 | **38** |
| status histogram | `om 246, rt_err 1, recomp_fail 1` | `om 235, rt_err 1` | **`om 222, rt_err 1, recomp_fail 0`** |

Gap histogram: `0:3 1:11 2:10 3:4 4:6 5:4` (=38) · `6–10: 36` ·
`11–20: 32` · `>20: 117`. No failure lacks line counts.
Live failing rows by suite (after dispositions): avm2 82 · from_gnash
misc-ming.all 13 · avm1 10 · from_shumway 9 · from_avmplus 8 ·
from_gnash actionscript.all 9 · mixed_avm 7 · misc-swfc.all 3 ·
audio/import_assets/text/timeline/visual 2 each.

### Exact snapshot diff `64d1f266b` → HEAD

**17 flips, 0 status regressions, +5 tests, −2 tests.** Matches the s11
closeout ledger exactly.

```
avm1/load_cancel_via_removemovieclip            om 0  -> pass
avm2/constructsuper_null                        om 2  -> pass
avm2/cross_api_version_call_newer               om 1  -> pass
avm2/doabc_and_symbolclass_script_init_goto     om 6  -> pass
avm2/doabc_and_symbolclass_script_init_normal   om 5  -> pass
avm2/graphic_linkage                            om 2  -> pass
avm2/system_exit                                om 3  -> pass
fonts/device_font_glyph_fallback                om 7  -> pass
fonts/device_font_kerning                       om 4  -> pass
fonts/device_font_list                          om 58 -> pass
from_avmplus/regress/bug_550958                 om 1  -> pass
from_shumway/as3-loader/bug1157243/empty        om 1  -> pass
from_shumway/as3-loader/bug1157243/invalid      om 1  -> pass
from_shumway/.../PerspectiveProjectionClass     om 4  -> pass
visual/edittext/edittext_device_transform_basic om 12 -> pass
visual/edittext/edittext_device_transform_metrics om 20 -> ruffle_matched
visual/edittext/edittext_device_transform_negative om 60 -> ruffle_matched
ADDED:   avm2/{av_classes, avm1movie_addcallback_call, flash_trace,
         groupelement_text}, regression/mask_sibling_union
REMOVED: avm2/{av_networking_params, av_tag_data}
```

### ⚠ NEWLY EXPOSED — a silent worsening under a "0 regressions" run

Gap moves among rows that were *already* failing (so CI's pass→fail
regression check could not see them):

| test | gap before | gap now |
|---|---|---|
| **`avm2/textblock_line_changes`** | **33** | **116** ⬆ **+83 worse** |
| `avm2/edittext_device_transform_layout` | 128 | 52 ⬇ |
| `avm2/perspective_projection` | 75 | 15 ⬇ |
| `avm2/delayed_symbolclass` | 12 | 8 ⬇ |
| `avm2/geom_transform` | 54 | 53 ⬇ |

`textblock_line_changes` got materially worse during s11's text/font work.
It is a **regression in everything but the status field**, and it is the only
one. This is the second sighting of the `transition-diff-hides-new-crashes`
class of trap: *diff the gap histogram, not just the status column.* See T4.

---

## 1. Premise verdicts (refutations first — they are yield)

| Premise | Verdict | Evidence |
|---|---|---|
| "The near-pass (≤5) well is a CLOSED inventory" | **CONFIRMED — and now essentially EMPTY** | 38 rows in the window; **34 are dispositioned, arc-blocked, sibling-owned, or already-refuted**. The genuinely live, non-arc pool is **4 low-confidence rows** (`button_nested_frame_simple`, `remove_different_level`, `scope_optimizations`, `getpixel-from-embedded`). Fourth consecutive session of zero refill from the shoulder. **Stop mining this window.** |
| "runtime_error is the cheapest triage axis" | **CONFIRMED but still EXHAUSTED** | One `runtime_error` corpus-wide (`from_avmplus/regress/bug_483783`), arc-scoped to the dependent-string work. `recomp_fail` bucket empty. Zero segfault/timeout/compile_fail. |
| "the `from_shumway/fuzz/*` family (15 tests, gaps 5–56) is one decoder-tolerance mechanism worth ~15 flips" | **REFUTED — all 15 are already in `from_shumway/ignored_tests.txt`** | The single largest-looking cluster on the raw board is 100% dispositioned. Do not scope it. |
| "`from_gnash/actionscript.all/argstest-v{6,7,8}` (3 × ~2000-line gaps) are a huge single-divergence win" | **REFUTED — all three suite-ignored** | Same for `array-v5`, `RegisterClassTest4`, `matrix_accuracy_test1`. |
| "`avm2/all_classes/*` is a 26-test cluster" | **PARTIALLY REFUTED** | The 6 `all_classes/events/*` rows are suite-ignored. The other **20** (`display`×6, `display3D`×3, `errors`×3, `accessibility`×3, `xml`×2, `security`×3) are live — but they are a *feature arc*, not polish (see T7). |
| "the big AVM1 census tests (`global_proto_decls*`, `global_instance_decls`, `watch_*`, `set_property_values/swf4`) are takeable" | **REFUTED — globally ignored** | `ruffle-tests/ignored_tests.txt`. `set_property_values/swf5` is the only non-ignored member and is the documented float blocker. |
| s11 §12.3: "B2 verifier `method_info` is a hard oracle conflict — leave" | **CONFIRMED, and it also disposes `verify_method_info_duplicate`** | Both remain gap 4 / gap 1. Recording it here so the next board stops re-costing them; neither is in an ignore list. **Recommend adding both to `avm2/ignored_tests.txt` with a disposition note.** |
| s11 §(f): `avm2/{loader_applicationDomain, swz}` are undeclared won't-do | **CONFIRMED, still undeclared→ now declared** | Both are now in `avm2/ignored_tests.txt`. Good — one less re-cost. |
| "the gap 6–10 shoulder is where the next session should aim" (s11 §g) | **PARTIALLY REFUTED** | The shoulder is 36 rows, but 14 are dispositioned; only **22 are live**, and 5 of those are riders of T1 or T4 below. The much better aim is **T1**, which sits almost entirely at gap 29–260 and was invisible to a gap-ranked board. **Ranking by gap size actively hid the best target on this board.** |
| "big gaps = big effort" | **REFUTED, emphatically** | The three cheapest targets found this session have gaps 257, 190 and 114 and are each *one* mechanism. Gap size measures *blast*, not *cost*. |

---

## 2. Keys run over the 223 failures

1. **Disposition cross-check FIRST** (`accepted-diffs-first`). Ran every row
   against `ruffle-tests/ignored_tests.txt`, the 7 per-suite
   `ignored_tests.txt`, and the four AVM1 disposition docs. **80 of 223 rows
   (36%) are dispositioned**; 72 hard (ignore-list), 8 fuzzy doc hits.
   This alone removed the two biggest-looking clusters on the board.
2. **`runtime_error` / `recomp_fail` axis** — 1 row, arc-scoped. Dry.
3. **Diff-SHAPE key on the live rows** — the shape that paid this session is
   *"actual is a positionally shifted copy of expected"*: `matching_lines`
   is computed positionally, so **one inserted/omitted line poisons every
   line after it**. Five of the top seven targets below are exactly this.
4. **Stack-frame key (new, and it paid biggest)** — grep expected outputs for
   `\tat `: 48 tests; for `Error$/throwError()`: 14 tests, of which **5 already
   pass** — i.e. the mechanism already exists in-tree and just isn't wired at
   enough sites. That is T1.
5. **Family key** (same directory / same name stem across SWF versions) —
   surfaced `looping_child_swf{5,9,32}`, `textblock_*`, `describe_type_*`,
   `all_classes/*`, `action_order/*`.
6. Confirmed dry again: error-code substitution census, namespace-half,
   runtime-name-half.

---

## 3. Ranked wave-2 target list

Ranked by yield ÷ effort × confidence.

---

### T1 — AVM2 error stack-trace frames ★★ TOP PICK BY A LARGE MARGIN

- **Tests (7 live):**

  | suite/test | gap | verified failing at HEAD |
  |---|---|---|
  | `avm2/primitive_valueOf` | 260 | ✅ 2026-08-06 |
  | `avm2/primitive_toString` | 257 | ✅ 2026-08-06 |
  | `avm2/stage_properties2` | 190 | ✅ 2026-08-06 |
  | `avm2/error_throwerror` | 97 | ✅ 2026-08-06 |
  | `avm2/proxy_not_overridden` | 50 | ✅ 2026-08-06 |
  | `avm2/timer_invalid_delay` | 29 | ✅ 2026-08-06 |
  | `avm2/xml_list_ctor_errors` | 29 | ✅ 2026-08-06 |

  **912 mismatched lines — 41% of every mismatched line in the live pool.**
  Riders not counted above: `avm2/accessibilityimplementation` (gap 18, also
  expects the frame), `avm2/error_stack_trace` (7) and
  `avm2/error_stack_trace_edge_cases` (6) in the sibling-owned shoulder,
  and `avm2/avm1movie_addcallback_call` (14, sibling-owned new upstream).

- **Diagnosed end to end. `primitive_toString` is 100% frame lines** — I
  filtered the diff for any non-`\tat` line and got zero. Same for
  `primitive_valueOf`. Every one of those 517 lines is positional shift
  caused by frames.

- **The five sub-rules, each pinned:**

  **(a) The synthetic `Error$/throwError()` frame.** avmplus's *AS3-implemented*
  playerglobal raises through `Error.throwError`, which shows as an extra
  frame atop the trace; the *C++-implemented* core does not.
  ```
  exp:  TypeError: Error #1004: Method Boolean.prototype.toString was invoked …
        	at Error$/throwError()          <-- WE OMIT THIS
        	at Function/<anonymous>()
        	at Function/http://adobe.com/AS3/2006/builtin::call()
        	at global$init()
  ```
  **The idiom already exists in-tree and is already documented**:
  `SWFModernRuntime/src/avm2/avm2_display.c:8414` (`gfx_throw_2008_via_throwerror`)
  and `SWFModernRuntime/src/avm2/avm2_text.c:5655` / `:6729` / `:7185`:
  ```c
  static const Avm2MethodRef throwerror = { NULL, NULL, "Error$/throwError", 0 };
  avm2_callstack_push(ctx, &throwerror, NULL);
  avm2_throw_error(ctx, …);
  ```
  (The push needs no pop: the longjmp unwinds `call_depth`.) Wave 2 replicates
  this two-line idiom at the sites the tests exercise: `Timer` ctor + `set delay`
  (#2066), `Stage` property setters (#2071), `Proxy` (#2088/#2089), primitive
  prototype methods (#1004), `DisplayObject.getBounds` (#2007),
  `ExternalInterface.addCallback` (#2067).

  **(b) Native accessor frames must render `Class/set prop()`.**
  `timer_invalid_delay` wants `flash.utils::Timer/set delay()`;
  `stage_properties2` wants `flash.display::Stage/set height()`; we print
  `flash.utils::Timer()` and `flash.display::Stage/height()`. The mechanism
  also already exists: `fte_ctor_set` at `SWFModernRuntime/src/avm2/avm2_text.c:5638`
  pushes a synthetic named frame around a native setter.

  **(c) Builtin methods in a non-public namespace must print the URI.**
  `Function/http://adobe.com/AS3/2006/builtin::call()` (we print
  `Function/call()`);
  `flash.utils::Proxy/http://www.adobe.com/2006/actionscript/flash/proxy::getProperty()`
  (we print `flash.utils::Proxy/getProperty()`). This is a **registration-string
  change only** — `avm2_callstack_frame_name` prints native `debug_name`
  verbatim at `SWFModernRuntime/src/avm2/avm2_error.c:142-148`.

  **(d) An ES3 prototype function reached through `.call` renders
  `Function/<anonymous>()`,** not its own name. We print `toString()`.
  Same `debug_name` lever (`avm2_error.c:142-148`); note `avm2_error.c:150-156`
  already has the `Function/%s()` shape for ABC function-methods.

  **(e) `Error.throwError` must exist as a real static.** `error_throwerror`
  currently dies with `TypeError: Error #1010: … (accessing field: apply)` —
  the property is simply absent. Expected: `Error.throwError.apply(null,[cls,id,…])`
  throws `Error: Error #12` etc. and shows both the `Error$/throwError()` and
  `Function/http://adobe.com/AS3/2006/builtin::apply()` frames.

  **(f) `xml_list_ctor_errors` wants a genuinely EMPTY line** between the
  message and the frames. `Test.as:21` is
  `trace("    Error (expected): " + e.getStackTrace())`, and the expected
  bytes are `…</xml>".$` / `$` / `^Iat Test/test()$`. So Flash's
  `getStackTrace()` for an XML-parse-thrown TypeError carries an extra
  empty-named frame. Lowest confidence of the seven; treat as a rider.

- **File pointers:** `SWFModernRuntime/src/avm2/avm2_error.c:112-163`
  (`avm2_callstack_frame_name` — rules b/c/d),
  `avm2_error.c:176-198` (`callstack_snapshot`),
  `avm2_display.c:8402-8419` + `avm2_text.c:5638-5660` (the two working
  reference implementations to copy).

- **ORACLE: SAFE — no conflict.** `primitive_toString` ships an
  `output.ruffle.txt` that agrees with Flash on **every frame line**; the only
  Ruffle↔Flash delta is a `[TU=]` suffix on `global$init()`. Ruffle and Flash
  agree that all four frames are present. Same for `primitive_valueOf` and
  `error_throwerror`.

- **Blast radius: SMALL and fully enumerable.** Only **48 tests** have `\tat `
  in expected output; only **14** mention `Error$/throwError()`.
  **Mandatory canaries — these 6 pass TODAY and must not move:**
  `avm2/{textblock_createline_errors, content_element_basic, graphics_draw_path,
  graphics_path, textline_throwerror, system_exit}`. `system_exit` is the
  important one: its expected trace has **no** `Error$/throwError()` frame, so
  rule (a) must stay a per-site opt-in and must NOT become a blanket change
  inside `avm2_throw_error`.

- **Yield: +5 … +7** (7 live tests; +2 more if the shoulder riders come along).
  **Effort: M** (mostly replication of an existing idiom + registration
  strings). **Confidence: HIGH** on (a)(b)(c)(d), MED on (e), MED-LOW on (f).
- **Patch scope:** `avm2_error.c`, plus the throw sites in `avm2_globals.c` /
  `avm2_display.c` / `avm2_text.c` / the Timer + Proxy + ExternalInterface
  implementations. Runtime-only — **no recompiler change, no `categories=full`
  requirement**.
- **Dispositions:** none of the 7 is in any ignore list or disposition doc.
- **Suggested split if two agents:** agent A takes (a)+(b) →
  `stage_properties2`, `timer_invalid_delay`, `proxy_not_overridden`;
  agent B takes (c)+(d)+(e) → `primitive_toString`, `primitive_valueOf`,
  `error_throwerror`. They touch disjoint call sites; both touch
  `avm2_error.c:112-163`, so serialize that hunk.

---

### T2 — Class objects are missing `Object`'s ES3 methods
- **Test:** `avm2/property_is_enumerable` (gap 89, exp 114, act 27).
  Verified failing at HEAD 2026-08-06.
- **Diff:** the first 25 lines match. Line 26 dies with
  `TypeError: Error #1006: propertyIsEnumerable is not a function.` /
  `\tat global$init()`, on the transition from
  `es4inst.propertyIsEnumerable(…)` (instance — works) to
  `ES4Class.propertyIsEnumerable(…)` (**the class object** — absent).
  Everything after is `<end of actual>`.
- **Mechanism:** an `AVM2_OBJ_CLASS` object does not inherit Object's ES3
  prototype surface. `describe_type_basic` independently confirms this shape
  (we emit `hasOwnProperty` / `isPrototypeOf` / `propertyIsEnumerable` for
  `Object` instances but the class-object `<type>` element carries none).
  See memory `es3-surface` and `builtin-class-mints`.
- **Expected values after the unblock are all `false`** (89 remaining lines
  alternate `//ES4Class.propertyIsEnumerable('…')` comment echoes with
  `false`), so the comment lines match for free — a full pass is realistic.
- **Yield +1 (89 lines). Effort S. Confidence MED-HIGH.** No `output.ruffle.txt`
  → must be a full pass.
- **Risk:** giving class objects a prototype chain to `Object` can leak
  `hasOwnProperty`/`isPrototypeOf` into places that currently correctly report
  `#1006`. Canary: `avm2/{describe_type_basic, static_length,
  object_prototype*, class_call}` and the whole `from_avmplus/ecma3/Object` dir.

---

### T3 — `text/html_entity_parsing`: one missing leading blank line
- **Test:** `text/html_entity_parsing` (gap 114, exp 213, act 217).
  Verified failing at HEAD 2026-08-06.
- **Diff:** expected line 1 is **empty**; ours starts at expected's line 2.
  The entire body is then off by one and every subsequent line "mismatches"
  positionally while being textually identical (`Source: …` / `Parsed: …` /
  blank, repeating). This is the single clearest instance of the
  positional-shift shape on the board.
- **Mechanism:** the test emits a leading blank trace (an empty `htmlText`
  round-trip, or a frame-0 `trace("")`) that we swallow. Also 4 extra actual
  lines to account for at the tail, so it is not *purely* the shift.
- **Yield +1 (114 lines, most of them free). Effort S** once the leading
  blank is located — the whole job is finding which trace we drop.
  **Confidence MED.**
- **Dispositions:** none; not in any ignore list.

---

### T4 — TextBlock line-list bookkeeping (and the s11 worsening)
- **Tests:** `avm2/textblock_line_changes` (gap **116**, was 33 — see §0) and
  `avm2/textblock_recreateline` (gap 58). Both verified failing at HEAD
  2026-08-06.
- **Diff (`textblock_line_changes`) — only 34 distinct mismatched lines**,
  in four rules:

  | count | expected | ours |
  |---|---|---|
  | 6 | `First line in block: line-0` | `line-4` |
  | 7 | `line.validity: invalid` | (valid) |
  | 6 | `line.textBlock: null` | (non-null) |
  | 10 | `previousLine` / `nextLine` links | wrong |
  | 1 | `Calling recreateTextLine returns the same line: true` | — |

  So `TextBlock.firstLine` returns the **last** line, released lines keep
  `validity`/`textBlock`, and the prev/next chain is not repaired on
  recreate/release.
- **`textblock_recreateline` is in the `Error$/throwError()` set too**, so
  part of its 58 is T1.
- **Yield +2. Effort M. Confidence MED-HIGH** (the four rules are explicit
  and the subsystem is contained).
- **Priority note:** this is the only *worsening* in the tree. Even if it is
  not fixed, wave 2 should establish whether s11's font/text work caused it —
  a `git bisect` over the 9 s11 commits with this one test is ~10 min.
- **Dispositions:** none. Both ship `output.ruffle.txt` (ruffle_matched is a
  fallback).

---

### T5 — XS/S singles bundle (give all four to one agent; ~2–3 h total)

**T5a — Error-class constructors must report `.length == 1`.**
`avm2/static_length` (gap 13, exp 24). Verified at HEAD 2026-08-06.
12 of 24 lines wrong, all one shape: `ReferenceError.length is: undefined`
(and `DefinitionError, ArgumentError, SyntaxError, VerifyError, SecurityError,
EvalError, RangeError, TypeError, URIError, Error, UninitializedError`) must
all be `1`; plus `RegExp.length is: 2` must be `1`. `Object/String/XMLList/
Number/Boolean/XML/Function/Array/uint/Date/Namespace` already correct — so
the `length` static exists and just isn't set on the Error family or RegExp.
**Yield +1. Effort XS. Confidence HIGH.** No `output.ruffle.txt` → full pass.

**T5b — `JSON.stringify` must not serialize Function values.**
`avm2/json_stringify_function` (gap 12, exp 12, act 12, match **0**).
Verified at HEAD 2026-08-06. Expected/actual are a permutation:
| | expected | ours |
|---|---|---|
| top level | `{"length":1,"prototype":{}}` then `null`, `null` | `{}` then the length/prototype form twice |
| in object | `{"a":{…}}` then `{}`, `{}` | `{"a":{}}` then `{"a":{…}}` twice |
| in array | `[1,{…},3]` then `[1,null,3]`, `[1,null,3]` | `[1,{},3]` then `[1,{…},3]` twice |
So two rules: (i) a Function's *own* `length`/`prototype` must serialize on
the first (no-replacer) path — we emit `{}`; (ii) on the other two paths a
Function value is non-serializable → **omitted** as an object property and
**`null`** in an array. `output.ruffle.txt` agrees on all semantics and
differs only in key order (`{"prototype":{},"length":1}`), so a wrong key
order still scores `ruffle_matched` — **+1 either way**.
**Yield +1. Effort S. Confidence HIGH.**

**T5c — `DisplayObject.getBounds(morphShape)` must not throw #2007.**
`avm2/displayobject_getrect` (gap 14, exp 16, act 5). Verified at HEAD
2026-08-06. Lines 1–2 (`[object Shape]`, `[object MorphShape]`) match; line 3
dies with `TypeError: Error #2007: Parameter targetCoordinateSpace must be
non-null.` / `\tat flash.display::DisplayObject/getBounds()` where Flash
returns `(x=33.25, y=25.7, w=67.15, h=75.95)`. A `MorphShape` passed as the
coordinate space is being seen as null by the arg coercion. Note the frame
here also wants T1 rule (a).
**Yield +1. Effort S. Confidence MED.**

**T5d — `concatenatedMatrix` must track `Stage.quality` / grid-fit size.**
`avm2/displayobject_transform` (gap 22, exp 89). Verified at HEAD 2026-08-06.
Lines 1–5 match (`best`, `high` → scale 5). Lines 6–17 want
`16x16 → 1.25`, `8x8 → 2.5`, `low → 20`, `medium → 10`; we report a constant
`5` for all. So the device-space scale is hard-coded at the `best` value.
**Yield +1. Effort M. Confidence MED.** Overlaps the fonts/edittext device-
transform work that s11 touched — coordinate with whoever owns that.

---

### T6 — `LoaderInfo.bytes` returns an empty ByteArray
- **Test:** `avm2/loaderinfo_quine` (gap **1004**, exp 1005, act 2). Verified
  at HEAD 2026-08-06.
- **Diff:** line 1 `//this.loaderInfo.bytes` matches; line 2 expects
  `//length: 1003`, we say `//length: 0`; the remaining 1003 lines are the
  SWF's own bytes, which we never emit.
- **Mechanism:** `LoaderInfo.bytes` for the **root** movie must hand back the
  raw SWF. s11's B1 work already introduced `raw_bytes` on `MovieEntry`
  (`verify_output.py:2184` / `avm2_display.c:5731-5754`) for *child* SWFs; the
  root has no equivalent. The harness would need to embed the root SWF's bytes
  the same way.
- **Yield +1 (1004 lines). Effort M** — the byte plumbing is mechanical but
  spans `verify_output.py` (harness) and the runtime.
  **Confidence MED-HIGH** on mechanism, MED on the exact 1003-byte match
  (it must be the *uncompressed-as-stored* image, byte for byte).
- **Risk:** touching `verify_output.py`'s embedding affects every test. Keep
  it additive and gated.

---

### T7 — `describeType` trait enumeration ★ ARC, NOT POLISH — scope only
- **Tests (24 live, ~6800 lines):** `avm2/describe_type_{basic (151),
  metadata (125), native (23), json (300)}` + the 20 live `avm2/all_classes/*`
  rows (`display`×6 gaps 1958–2935, `display3D`×3, `errors`×3,
  `accessibility`×3, `xml`×2, `security`×3). The 6 `all_classes/events/*`
  rows are suite-ignored; `avm2/av_classes` (339) is sibling-owned.
- **This is the single largest mechanism cluster in the corpus.** It is also
  explicitly out of scope for a polish wave — the runtime says so itself:
  `SWFModernRuntime/src/avm2/avm2_globals.c:1737`:
  > "Trait enumeration for arbitrary classes is **not modeled yet**."
- **Verified diffs at HEAD 2026-08-06.** `describe_type_native` on
  `flash.events::Event`: we emit `isDynamic="true"` (should be `false`), a
  generic `<parameter index="1" type="*" optional="true"/>` constructor, and
  **zero** accessors or methods; Flash wants 6 accessors + 8 methods with real
  `type`/`returnType`/`declaredBy`. `describe_type_basic` additionally shows we
  emit no `<factory>` wrapper, no `base="Class"` on class objects, no
  `<implementsInterface>`, no `<variable>`.
  `all_classes/security/swf12` shows a **second, independent** requirement:
  version-gated class availability (at SWF12 Flash reports
  `CertificateStatus not accessible`, we resolve it; at SWF9
  `all_classes/errors` wants `DRMManagerError not accessible`, we resolve it).
- **Recommendation for wave 2: DO NOT TAKE.** Recommend instead that someone
  writes a one-page arc scoping doc splitting it into
  **Phase A** (user-defined classes — traits already exist in
  `Avm2AbcTrait` / the vtables, so `describe_type_basic` + `_json` are
  reachable without any new data) and **Phase B** (native builtins — needs a
  generated reflection table for the whole API surface, plus per-SWF-version
  availability gates). Phase A alone is plausibly 2 tests; Phase B is 22 and
  is a multi-session data-generation job.
- **Estimated arc size: 2–4 sessions for up to +24.** Best long-run ROI on
  the trace axis, worst short-run ROI.

---

### T8 — `avm1/looping_child_swf{5,9,32}`: nested-sprite frame-2 execution
- **Tests:** three tests, **identical** gap 112 / exp 141 / act 375. One
  mechanism, +3. Verified `swf5` at HEAD 2026-08-06.
- **Diff:** lines 1–26 match. From line 27 we start skipping sprites —
  expected `22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11` at `frame 2`,
  we emit `21, 20, 18, 17, 14, 13` then jump to `sprite 9, frame 1`. So a
  subset of nested sprites never runs its second frame, and we then emit 234
  extra lines (act 375 vs exp 141) re-running frame 1.
- **Mechanism (suspected):** nested-sprite advance order in the AVM1 frame
  loop; related to memory `current-frame` / `goto-catchup-placed-clip-no-advance`.
- **Yield +3. Effort M-L. Confidence MED-LOW** — the divergence is structural,
  not a substitution.
- **Dispositions:** none of the three is in any ignore list.

---

### T9 — Sized-but-not-recommended (documented so nobody re-costs them)

| Test(s) | gap | Why not wave 2 |
|---|---|---|
| `avm2/appdomain_lookup_edge_cases` | 25 | `ApplicationDomain.getDefinition("<integerValue>")` must raise **#1107**, not #1065; plus a `hasDefinition` true/false flip. Verifier-adjacent → recompiler → `categories=full`. MED. |
| `avm2/displayobject_early_init` | 53 | One missing throw (`ArgumentError: Error #2015: Invalid BitmapData.` when a `Bitmap` is constructed before `super()`); the remaining ~51 lines then align. Looks like +1 for one throw, but "before super()" object state is the risky part. Worth a second look if T1 finishes early. |
| `avm2/external_interface` | 102 | `ExternalInterface.available` must be `true` and `addCallback` must register in the test container. Memory `external-interface` says the browser path is DONE; this is the headless-harness half. MED-L, and it needs harness cooperation. |
| `avm2/native_menu_basic` (19), `avm2/accessibilityimplementation` (18) | | Missing AIR/accessibility classes (`NativeMenuItem`, `AccessibilityImplementation`). Feature surface, not polish. `accessibilityimplementation` is a T1 rider. |
| `from_gnash/misc-ming.all/action_order/*` (7 live rows, gaps 12–81) | | Largest gnash family left. One arc (AVM1 action execution order across PlaceObject/sprite/frame boundaries), but every member diverges structurally. Needs its own scoping pass. |
| `from_gnash/actionscript.all/{TextField,MovieClip,array}-v{6,7,8}` (9 rows) | | Property-surface census tests; long tails of individual API gaps, no shared mechanism. Grind, not polish. |
| `avm2/{number_convert_edge_cases (32), number_convert_errors (831)}` | | Number formatting — adjacent to the sibling-owned number→string tie-break. Coordinate before touching. |
| `from_shumway/acid/acid-shapes{,-testing}` (120, 84) | | Render/tessellation census; belongs to the pixel axis. |
| `avm2/orphan_removeobject` | 296 | Only ~2 distinct diffs sampled (`currentFrame = 2` vs our `3` on `timelineGrandchild`), but spread across 636 lines with many matching runs. Could be cheap; needs a full-diff census before costing. **Flagged as the best un-costed lead.** |
| `avm2/{method_association, verify_method_info_duplicate}` | 4, 1 | s11 §12.3 oracle conflict — CONFIRMED. **Add to `avm2/ignored_tests.txt`.** |
| `mixed_avm/*` (7), `avm1/shared_stack`, `avm2/{mouse_pick_avm1_root, selection_onsetfocus_mixed_avm, mouse_pick_loader_avm1, focus_events_mixed_avm_edittext}` | | Declared dual-VM / multi-SWF child-execution arc. 11 rows. Not polish. |
| `from_shumway/as3-loader/{LoaderTest2, LoaderLoadBytesTest, loaderinfo/loaded-content-properties, events/loader-events}` | | loader-arc tranche 6. |
| `visual/definefont4` | 0 | Uniterable on this machine (>25 min gcc, hard compile_fail). Pixel-axis item. |
| `avm2/button_nested_frame_simple` | 0 | s11 sized this MED-LARGE (3 extra enterFrame cycles); gap 0 is misleading. |

---

## 4. Predicted wave-2 total (trace axis)

| Target | Tests | Lines | Yield | Effort | Confidence |
|---|---|---|---|---|---|
| **T1** error stack-trace frames | **7** | **912** | **+5 … +7** | M | HIGH |
| T2 class-object ES3 surface | 1 | 89 | +1 | S | MED-HIGH |
| T3 html_entity_parsing blank line | 1 | 114 | +1 | S | MED |
| T4 TextBlock line bookkeeping | 2 | 174 | +2 | M | MED-HIGH |
| T5a Error `.length` = 1 | 1 | 13 | +1 | XS | HIGH |
| T5b JSON.stringify function | 1 | 12 | +1 | S | HIGH |
| T5c getBounds(morphShape) | 1 | 14 | +1 | S | MED |
| T5d concatenatedMatrix × quality | 1 | 22 | +1 | M | MED |
| T6 LoaderInfo.bytes | 1 | 1004 | +1 | M | MED |
| T8 looping_child ×3 | 3 | 336 | +3 | M-L | MED-LOW |
| **Total** | **19** | **2690** | **+17 … +19** | | |

**+17 conservative**, versus s11's +17 and a *near-pass window that is now
empty*. The whole of this yield sits at gap ≥ 11 — a gap-ranked board would
have shown none of it.

Live-pool accounting (129 live rows outside the sibling-owned 6–10 shoulder):
19 proposed above · 24 in the describeType arc (T7) · ~30 in declared arcs
(dual-VM 11, loader t6 4, gnash action_order 7, gnash census 9) ·
~20 feature-surface (AIR classes, netstream, audio, FTE, external_interface) ·
~15 pixel-axis or uniterable · ~20 uncosted tail.

---

## 5. Recommended wave-2 roster for the trace axis

Staff **T1 with two agents** — it is 41% of every mismatched line in the live
pool, the fix idiom already exists in-tree at four call sites, Ruffle and Flash
agree on every disputed line so there is no oracle risk, and the blast radius
is a fully enumerated 48-test canary set with six named must-not-move passes
(`system_exit` above all, because its expected trace proves rule (a) must stay
a per-site opt-in rather than a change inside `avm2_throw_error`). Split it as
agent A = the synthetic-frame + accessor-frame half (`stage_properties2`,
`timer_invalid_delay`, `proxy_not_overridden`) and agent B = the frame-naming +
`Error.throwError` half (`primitive_toString`, `primitive_valueOf`,
`error_throwerror`), serializing the shared `avm2_error.c:112-163` hunk. Give a
**third agent the T5 bundle plus T2** — five independent XS/S singles
(`static_length`, `json_stringify_function`, `displayobject_getrect`,
`displayobject_transform`, `property_is_enumerable`) worth +5 for roughly one
agent-session, each a separate commit. Give a **fourth agent T4 + T3**: T4
starts with a 10-minute bisect over s11's nine commits to explain the
`textblock_line_changes` 33→116 worsening — the only true regression in the
tree and one CI's status-only check cannot see — then fixes the four named
`TextBlock` line-list rules; T3 is the same agent's second commit because it is
a hunt for one dropped blank trace. Hold T6, T8 and T9 as overflow, and **do
not** open T7 (describeType) as an implementation task this session — commission
a one-page arc scoping doc for it instead, because at 24 live tests and ~6800
lines it is the largest remaining trace mechanism and deserves a plan before a
patch. Two board-hygiene chores worth ten minutes: add
`avm2/{method_association, verify_method_info_duplicate}` to
`avm2/ignored_tests.txt` with the s11 §12.3 oracle-conflict rationale, and add
a line to the pipeline handoff telling the next session to diff the **gap
histogram**, not just the status column.
