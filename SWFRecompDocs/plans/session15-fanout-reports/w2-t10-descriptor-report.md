# Session 15 · wave 2 · T10 `playerglobal-descriptor` — implementation report

**Agent:** `w2-t10-descriptor`, worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac40f187a7e1a0d31`
(branched from `42a324cef`).
**Brief:** `SESSION15/wave1-t10-descriptor.md` §3, slices 1–5.
**Deliverable patch:** `w2-t10-descriptor.patch` (worktree root).
**Nothing committed, nothing pushed.**

---

## 0. Result — **8/8 priced rows flip. +8 trace, exactly as priced.**

| # | slice | target row(s) | before | after |
|---|---|---|---|---|
| 1 | `display3D` descriptor data | `all_classes/display3D/swf30` | output_mismatch (267/412) | **PASS** |
| 2 | per-member / per-const API gate | `all_classes/display3D/swf13` | output_mismatch (211/326) | **PASS** |
| 3 | `flash.accessibility` real registration + synthetics | `all_classes/accessibility/swf9` | output_mismatch (27/73) | **PASS** |
| 3 | (rider) | `avm2/accessibilityimplementation` | output_mismatch (4/18) | **PASS** |
| 4 | two gated interfaces | `all_classes/accessibility/swf10` | output_mismatch (27/88) | **PASS** |
| 4 | | `all_classes/accessibility/swf30` | output_mismatch (27/88) | **PASS** |
| 5 | const-type override + `flash.xml` tables | `all_classes/xml/swf9` | output_mismatch (61/116) | **PASS** |
| 5 | | `all_classes/xml/swf30` | output_mismatch (61/116) | **PASS** |

`all_classes/display` was **not** attempted (explicit NO-GO).

Every row is graded by the runner's own verdict against `output.txt`, with the
saved actual diffed byte-for-byte, never by the positional `matching_lines`
metric (`results-diff-line-metrics-mislead`).

---

## 1. Wave-1 premise audit — every load-bearing claim held

| wave-1 claim | verdict |
|---|---|
| `display3D/swf30` is pure data, ours-extra = missing = 0 | **CONFIRMED.** The complete baseline diff is 51 `type="*"`/`returnType="*"` members and their absent `<parameter>` children. Nothing added, nothing removed. |
| member insertion order is free (fixtures `sort()`) | **CONFIRMED.** Synthetic members are appended after the vtable pass in arbitrary order and every fixture still matches byte-for-byte. |
| `SWF = 12 + (N − 672) / 2` | **CONFIRMED** on nine annotations across two files (676→14, 682→17, 686→19, 688→20, 690→21, 692→22, 698→25, 700→26, 706→29). All fourteen gated `display3D` members appear at swf30 and vanish at swf13 exactly as the fixtures demand. |
| our value model has no UINT kind, so `XMLNodeType`'s `uint` needs a table | **CONFIRMED.** The constants are stored with `avm2_uint_value()` and reported `int` at baseline. |
| a global "unsigned ⇒ uint" rule would be wrong | **CONFIRMED.** `Context3DClearMask`'s constants are stored the same way and Flash reports them `int`; `display3D/swf12` (which grades them) is still PASS with the per-const table in place. |
| the `EventDispatcher` descriptor row has zero blast radius on passing tests | **CONFIRMED** by canary — `describe_type_{basic,json,native,metadata}`, `function_proto_created`, `number_autoconv` and `bug_539328` all unmoved. |
| nothing here invalidates `RecompiledABC` | **CONFIRMED.** No recompiler file touched; `--recompile` was needed only on first use of each copied test dir. |

**One correction to the wave-1 plan (mechanism, not magnitude):**

> §3.5 proposes fixing `XMLDocument.toString`'s `declaredBy` with either a real
> `avm2_builtin_add_method` or "a describe-only `declared_by` override field on
> `DtDescMember`".

**Both as written are wrong.** `avm2_vtable_append` does not de-duplicate and a
builtin subclass's `ivtable` is *flattened at creation* (it already carries
XMLNode's `toString`), so `avm2_builtin_add_method(ctx, doc, "toString", …)`
would emit **two** `<method name="toString">` elements. And a `declared_by`
field on `DtDescMember` cannot work either: the descriptor is looked up by the
member's **defining** class, so the row that would carry the override is
XMLNode's — the same row that must keep reporting `flash.xml::XMLNode` for
`XMLNode`'s own `toString`. The landed fix re-points the *copied* entry's
`defining_class` to `XMLDocument` (the same shape as the pre-existing
`attributes` GETSET patch four lines above it), which is also the faithful
model — playerglobal really does declare `override public function toString()`
on `XMLDocument`.

---

## 2. Mechanisms added (all in the `dt_*` region)

| gap | landed as | LOC |
|---|---|---|
| **C** per-member / per-const API gate | `DtDescMember.min_swf`, `DtDescConst.min_swf`, `dt_desc_member_hidden()`, one `continue` in `dt_collect_vtable`, one in `dt_collect_static_consts` | ~35 |
| **D** per-const TYPE override | `DtDescConst{name,type,min_swf}` + `DtDescClass.consts` + `dt_desc_const()` + one branch in `dt_collect_static_consts` | ~25 |
| **E** describe-only synthetic members | `DtDescMember.{synthetic,is_static,access,uri}` + `dt_members_has()` + `dt_collect_synthetic()`, called once per side in `dt_describe` | ~85 |

The gate is **describe-side only** by design (the wave-1 §2.2 ruling): Flash
also hides a gated member from *lookup*, but no graded test calls one on an
under-versioned SWF, and a real hide would need a per-entry availability check
on the hot property path.

Every new `DtDescMember`/`DtDescClass` field is **appended**, so the twelve
session-14 rows that stop at `params` keep their meaning by zero-fill and were
not touched.

### Data added

* `flash.display3D::{Context3D, IndexBuffer3D, VertexBuffer3D, Program3D}` and
  `flash.events::EventDispatcher` — 51 members / 110 parameters, machine-
  generated from `all_classes/display3D/swf30`'s **expected output** (the
  ground truth) and cross-checked against Ruffle's `.as` declarations, so the
  table is exact by construction rather than by transcription. Ten `min_swf`
  marks on `Context3D`, four gated constants on `Context3DTextureFormat`.
* `flash.accessibility::{Accessibility, AccessibilityImplementation,
  AccessibilityProperties, ISearchableText, ISimpleTextSelection}`.
* `flash.xml::{XMLNode, XMLDocument, XMLNodeType}` incl. both constructor
  signatures and the seven `uint` const overrides.

### Real registration (not describe-only)

`flash.accessibility::AccessibilityImplementation` was an **empty stub**
(`avm2_text.c:9142`). It is now a faithful port of Ruffle's
`AccessibilityImplementation.as`: `errno`/`stub` set by the constructor, ten
methods returning `null`/`0`/`false`, and `get_accRole`/`get_accState` raising
2143/2144 through `avm2_callstack_push_throwerror` + `avm2_throw_error`. That
is what buys the previously-unpriced rider.

**The rider's stack-trace risk did not materialise.** Wave-1 §3.3 flagged that
the expected `getStackTrace()` wants

```
	at Error$/throwError()
	at flash.accessibility::AccessibilityImplementation/get_accRole()
	at Test()
```

Our existing frame machinery produces both lines unchanged: the per-site
`avm2_callstack_push_throwerror` gives the first, and
`avm2_callstack_frame_name`'s `bound_class` path already renders a native
method as `<QName>/<debug_name>()`. No naming work was needed.

`AccessibilityProperties`' six vars, `XMLNode`'s eight and `XMLDocument`'s four
stayed **synthetic** on purpose — every one of them is a dynamic property in
our runtime (`xn_set`/`xn_get`), and promoting them to real slots would change
`for..in` enumerability and lookup order under eight currently-passing xml
tests for zero graded gain.

`ISearchableText` / `ISimpleTextSelection` are registered as real (empty)
interface classes gated at SWF 10 via session-14's `avm2_builtin_class_api`;
their accessors are synthetic rows carrying the interface `@uri`.

---

## 3. Canaries — **45 green, zero pass→fail, zero grade drift**

All re-run at the FINAL code state (every slice applied), local
`--mode=no-graphics`.

**describeType consumers** — the complete graded set (`grep -rn describeType
--include=*.as ruffle-tests/tests/swfs`), so the `EventDispatcher` row's blast
radius is measured, not argued:

```
describe_type_basic              PASS      describe_type_native    PASS
describe_type_json               PASS      describe_type_metadata  PASS
function_proto_created           PASS      number_autoconv         PASS
static_length                    PASS
from_avmplus/regress/bug_539328  RUFFLE_MATCHED   <-- still ruffle_matched,
                                                      no drift to pass/fail
                                                      (ruffle-matched-hides-regression)
```

`bug_539328` is the interface-describeType pin and matters twice here, because
slice 4 adds two new interface classes.

**API-gate canaries** (slice 2's per-member gate rides the same axis as s14's
class gate; `stage3d_bitmap` at SWF 13 is the sharpest, sitting below every one
of the ten new `Context3D` marks):

```
stage3d_bitmap  PASS   stage3d_x_y     PASS   stage3d_errors      PASS
stage3d_errors_swf_29 PASS   context3d_creation PASS  stage3d_triangle PASS
agal_compiler   PASS   abstract_classes PASS  json_version_gated   PASS
cross_api_version_call_older PASS  cross_api_version_call_newer PASS
air_hidden_lookup PASS
all_classes/display3D/swf12  PASS   <-- also the Context3DClearMask `int` pin
all_classes/security/swf11   PASS   <-- gate FROM BELOW
```

**Session-14 rows that must hold** (the descriptor table they own grew by 20×):

```
all_classes/security/swf12  PASS   all_classes/errors/swf9   PASS
all_classes/security/swf13  PASS   all_classes/errors/swf10  PASS
all_classes/security/swf30  PASS   all_classes/errors/swf30  PASS
```

**Error / stack-trace canaries** (the rider adds two new `throwError` sites):

```
error_stack_trace PASS  error_stack_trace_edge_cases PASS  error_throwerror PASS
error_tostring    PASS  error_tostring_more          PASS  error_prototype  PASS
```

**XML canaries** (slice 5 re-points `XMLDocument`'s `toString` entry — the only
non-describe-only change in the patch, so these are the sharpest rows here):

```
flash_xml  PASS  flash_xml_cloneNode PASS  flash_xml_namespace PASS
flash_xml_removeNode PASS  xml_ignore_white PASS  xml_namespace_methods PASS
xmldocument PASS  xmlnode PASS
```

**Accessibility:** `avm2/accessibility` PASS.

**`known_failure` rows — unchanged, no drift** (these are
`avm2/ignored_tests.txt:54-58`; a move to `pass`/`ruffle_matched` here would be
the regression the brief warned about):

```
all_classes/events/swf9   output_mismatch  (output_mismatch at baseline)
all_classes/events/swf30  output_mismatch  (output_mismatch at baseline)
```

### Two false failures, both resolved

`all_classes/security/swf11` and `all_classes/events/swf9` first came back
`compile_fail` — the documented `stale-recompiledabc` mode, not a result: their
`RecompiledABC` was copied into this worktree while the main tree was mid-write.
Re-run with `--recompile` they are `PASS` and `output_mismatch` respectively,
i.e. exactly their baseline grades. Machine load averaged 12–16 throughout
(≈10 sibling agents); all parallel batching stayed at the `-P 2` cap.

---

## 4. Exact patch scope (for the serial merge)

Three files, no header, no recompiler, no test harness, no `CMakeLists.txt`.

| file | function / region (post-patch line numbers) |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `DtDescMember` + new `DtDescConst` + `DtDescClass` (`:2454-2506`); new descriptor tables appended after `dt_m_x509` (`:2589-2934`); `dt_desc_classes[]` (`:2935-2977`, 15 rows added); `dt_desc_const` + `dt_desc_member_hidden` (`:3001-3032`); one `continue` in `dt_collect_vtable` (`:3076-3082`); const gate + type override in `dt_collect_static_consts` (`:3177-3213`); `dt_members_has` + `dt_collect_synthetic` (`:3225-3318`); two call sites in `dt_describe` (`:3453`, `:3458`) |
| `SWFModernRuntime/src/avm2/avm2_text.c` | six new `static` `acc_impl_*` natives inserted immediately **before** `avm2_register_text` (`:9052-9114`); the `flash.accessibility` registration block inside `avm2_register_text` (`:9203-9247`) |
| `SWFModernRuntime/src/avm2/avm2_xml.c` | `avm2_register_xml_legacy`, the `XMLDocument` `toString` re-point (`:3630-3647`) |

**Sibling-conflict check vs `w2-textblock`** (coordinator update mid-task): that
agent works in `avm2_text.c`'s TextBlock/TextLine lifecycle + line-breaking
region and adds one trailing struct field in `avm2_globals.h`. This patch
touches **`avm2_globals.h` not at all**, and its only `avm2_text.c` edits are at
`:9052-9114` (new statics, appended just above `avm2_register_text`) and
`:9203-9247` (inside the pre-existing `flash.accessibility` block) — both far
from TextBlock/TextLine, both self-localized (`static` symbols, an append-style
insertion, no reformatting of surrounding code).

No other session-15 agent touches `avm2_globals.c` or `avm2_xml.c`.

---

## 5. CI dispatch

`mode=graphics`, `categories=full`, `images=false`.

`full` is required — `all_classes` and `from_avmplus/regress/bug_539328` both
live outside the classic five. **No `RecompiledABC` regeneration**: nothing
here touches the recompiler or the generated ABI, so this run should be
ordinary length (unlike session 14's P3).

Expected movement: **+8 in the `avm2` suite**, +0 everywhere else, zero pixel-
axis effect (no render code touched).

---

## 6. What `all_classes/display` needs next session

Unchanged from the wave-1 §4 accounting, minus everything this patch built.
`display` now needs, on top of the (large) descriptor table:

1. 18 class-level gates + 3 new classes (`ActionScriptVersion`,
   `IBitmapDrawable`, `SWFVersion`);
2. ~129 per-member gates — **mechanism now exists** (`min_swf`), pure data;
3. `Stage`'s describe-side re-declaration of inherited members
   (`declaredBy="flash.display::Stage"` on `addChild`, `dispatchEvent`, …) —
   the one mechanism still missing. **Note the correction in §1:** a
   `declared_by` field on `DtDescMember` will not work, because the row is
   found by the member's *defining* class. `Stage` needs either the
   `defining_class` re-point used here for `XMLDocument.toString`, or a
   descriptor lookup that consults the **described** class before the defining
   one;
4. members of two classes we do not implement — **mechanism now exists**
   (`synthetic`), pure data.

The generator used for slice 1
(`scratchpad/w2t10/gen.py`, ~90 lines, parses an `all_classes` expected
`output.txt` and emits the C table text) is the seed: pointed at
`all_classes/display/swf30/output.txt` it emits the whole `display` table
directly, and its output for `display3D` was correct on the first run.
