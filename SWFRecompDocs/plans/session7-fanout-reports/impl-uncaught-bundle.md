# Uncaught-error tracing re-land — BUNDLE, measured

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a1536b76dc3405d7c`
Base: `46dcf3a06`. **Nothing committed, nothing pushed.**
Patch: `…/scratchpad/patches/uncaught-bundle.patch` (315 lines, 7 files, **runtime-only**).
Raw per-test output: `<worktree>/.agentlogs/` and `.agentlogs2/`.
Mode: default (NO_GRAPHICS). Mode parity is complete, so this is comparable to
the `results_graphics.json` baseline.

## VERDICT: **LAND** — measured **+6 / −2 = net +4**, zero unexplained regressions.

---

## 1. What is in the bundle

| # | change | files | why |
|---|---|---|---|
| 0 | `git revert -n ac2325c6f` (= re-land `1ca0ab117`) | `avm2_error.c`, `avm2_function.c` | `print_uncaught` writes the coerced error + its `__stacktrace_tail` to stdout; `avm2_setup_locals` pops the callee frame around parameter coercion so a `#1034` is attributed to the CALLER |
| a | native accessor stack frames print `get x()` / `set x()` | `avm2_globals.c` | `avm2_builtin_add_getter` (getter-only) and `avm2_builtin_add_static_getset` were the two registration helpers that never prefixed `debug_name`; `avm2_builtin_add_getset` already did. Factored into one `accessor_debug_name()` helper. |
| b | verifier-raised errors carry NO stack tail | `avm2_main.h`, `avm2_error.c`, `avm2_ops.c` | New `Avm2Context.suppress_stack_snapshot`, set by `avm2_verify_error_body` and consumed+cleared by `error_init`. FP verifies a method *before* its frame is pushed, so a VerifyError's `getStackTrace()` is empty; our verify body is emitted *inside* the rejected method. |
| c | a thrown non-Error value falls back to the CURRENT call stack | `avm2_error.c` | `print_uncaught` runs before the longjmp unwinds, so `callstack_snapshot(ctx)` is the throw site's stack. Note an empty (verifier) tail is a zero-length string, not NULL, so (b) and (c) do not fight. |
| 1 | **`flash.events.ContextMenuEvent` implemented** | `avm2_globals.h`, `avm2_events.c` | ported from Ruffle's `ContextMenuEvent.as`: `MENU_ITEM_SELECT`/`MENU_SELECT`, 5-arg ctor, `mouseTarget` / `contextMenuOwner` / `isMouseTargetInaccessible` accessors, real `clone()` and `formatToString`-based `toString()`. `mouseTarget` reuses the ext's `related_object` slot; `contextMenuOwner` got a new one. |

**Absent-name audit** (per `avm2-builtin-class-mints-never-looks-up`): the only
corpus tests naming `ContextMenuEvent` are `avm2/all_classes/events/swf{9,10,11,12,30}`
— all five are `output_mismatch` at 184 actual vs 1030–2353 expected, and all five
*expect the class to exist* (`<type name="flash.events::ContextMenuEvent" …>`).
No passing test asserts its absence, and no version gate is needed (it is present
from swf9). `avm2_builtin_class` mints a NEW class, and `ContextMenuEvent` did not
previously exist anywhere in the tree, so nothing is replaced.

**Accessor-rename audit**: every `\tat …` frame in the whole expected corpus that
names a native accessor already spells it `get x()` / `set x()` — never bare.
`debug_name`'s only other consumers are the `#1001` "not implemented" message
(the three tests expecting `#1001` all name ABC methods, not native accessors)
and the `#1064` "cannot call method as constructor" message. Zero exposure.

---

## 2. LEDGER

### 2.1 Gains — **+6**

| test | baseline (`results_graphics.json` @ `46dcf3a06`) | with bundle | owed to |
|---|---|---|---|
| `avm2/uncaught_error_basic` | output_mismatch 0/2 | **PASS** | re-land |
| `avm2/loader_method` | output_mismatch 83/85 | **PASS** | re-land (coercion frame pop) |
| `avm2/bitmapdata_zero_size` | output_mismatch 5/8 | **PASS (8/8)** | fix (a) |
| `avm2/verify_illegal_opcode` | output_mismatch 0/1 | **PASS** | fix (b) |
| `from_avmplus/ecma3/Exceptions/exception_011_rt` | output_mismatch 1/3 | **PASS** | fix (c) |
| `avm2/uncaught_errors_stringified` | output_mismatch 1/18 | **ruffle_matched** (effective pass) | (c) + re-land |

Two of these beat the scoping's prediction:

* `bitmapdata_zero_size` was priced at **7/8** (fonts-and-uncaught §B.3 fix 1).
  It goes to a **full 8/8** — the accessor prefix was the *only* remaining row;
  the report's "investigate the last row" is answered: there wasn't one.
* `uncaught_errors_stringified` was written off in §B.2 as "gains lines but
  cannot flip" (1/18). It flips to **ruffle_matched**, i.e. an effective pass.
  It is `known_failure = true` with an `output.ruffle.txt`, so this is a
  legitimate effective gain, not a `pass → ruffle_matched` demotion.

### 2.2 Measured, no flip — **0**

| test | baseline | with bundle | why it does not flip |
|---|---|---|---|
| `avm2/loader_load` | output_mismatch 124/128 | output_mismatch **126**/128 | both uncaught-error lines now match; the 2 survivors are the **URLVariables emission order** (`cccc=true&aaa=bbb` vs our `aaa=bbb&cccc=true`) — s7-triage Batch D |
| `avm2/system_exit` | output_mismatch 0/3 | output_mismatch 0/3 | needs `System.exit` + `#2017` to exist at all; we still trace `#1006 exit is not a function` |
| `avm2/verify_method_info_oob` | output_mismatch 0/1 | output_mismatch 0/1 | the recompiler's ABC **parser** rejects the file (no `RecompiledABC/` is produced), so no runtime `#1027` is ever emitted. Recompiler work, not runtime. |
| `avm2/verify_method_info_duplicate` | output_mismatch 0/2 | output_mismatch 0/2 | same (`#1121` is an `abc_parser.cpp` bail-out, not a `verify_error_body`) |
| `avm2/event_handler_exception` | output_mismatch 1/11 | output_mismatch | needs `[…Test.as:10]` source-line suffixes |

### 2.3 Regressions — **−2** (both `expected_lines == 0`, both understood)

**`avm2/away3d_advanced_shallow_water_demo`** — pass (0-byte expected) → output_mismatch, 6 spurious lines.
**Blocker 1 is KILLED**: `#1065 ContextMenuEvent is not defined` is gone. The chain
advanced one link, exactly as the worklist warned it would:

```
TypeError: Error #1009: Cannot access a property or method of a null object reference. (accessing field: width)
	at away3d.textures::BitmapCubeTexture/testSize()
	at away3d.textures::BitmapCubeTexture()
	at Advanced_ShallowWaterDemo/initMaterials()
	at Advanced_ShallowWaterDemo/init()
	at Advanced_ShallowWaterDemo()
```

`initMaterials` is six consecutive `Cast.bitmapData(EnvPosX … EnvNegZ)` calls
(`abc0_methods.c` ops 3–33 of the method) feeding a 6-arg `BitmapCubeTexture`.
`Cast.bitmapData(cls)` instantiates the `[Embed]`-generated asset class and returns
its `.bitmapData`; ours comes back **null**, so `testSize(value).width` throws.
That is the **embedded Flex `BitmapAsset`** gap, not an event/class gap — a
different owner from this bundle.

**`visual/definefont4`** — pass (0-byte expected) → output_mismatch, 24 spurious lines. See §3.

### 2.4 `ruffle_matched` risk set — **7 / 7 preserved, zero moves**

`coerce_property`, `array_access_oob_interpreter`, `sprite_dropTarget`,
`from_avmplus/as3/RegExp/replace`, `from_avmplus/e4x/XML/bug_564468`,
`from_avmplus/ecma3/JSON/Classes`, `from_shumway/avm1movie` — every one still
`ruffle_matched`, for worklist §4.5's reason (Ruffle traces the same line, so its
reference output already contains it).

**`pass → ruffle_matched` trap check** (s7-triage §5 Batch C): the two named
risk tests both carry `known_failure = true` in `test.toml`
(`coerce_property`, `array_access_oob_interpreter`), so `ruffle_matched` is
their *baseline* status and is unchanged — no demotion is hiding here.

### 2.5 Canaries — all held

| canary | why it is in the net | result |
|---|---|---|
| `avm2/loader_error_in_root_ctor` | the re-land's own double-print bug (`silent` catch-all) | PASS |
| `avm2/remove_child_clear_field` | the re-land's own split getter/setter try frames | PASS |
| `avm2/bytearray_oom` (`ByteArray/set length()`) | expects a native accessor frame | PASS |
| `avm2/textformat_display` (`TextFormat/set display()`) | ditto | PASS |
| `avm2/graphics_path` (`GraphicsPath/set winding()`) | ditto | PASS |
| `avm2/pixelbender_eof`, `avm2/pixelbender_no_out_param` (`Shader/set byteCode()`) | ditto | PASS |
| `avm2/edittext_default_format_empty` | ditto (`TextField/getTextFormat()`) | PASS ¹ |
| `avm2/graphics_draw_path` | ditto, `ruffle_matched` at baseline | ruffle_matched |
| `regression/avm2_contextmenu_stub` | the `flash.ui.ContextMenu*` stubs sit next to the new class | PASS |
| `regression/avm2_tolerant_verify_quarantine` | pins `avm2_verify_error_body` — which fix (b) edits | PASS |
| `regression/avm2_findprop_this_resolution` | the only other regression-suite README matching error/stack | PASS |

¹ **False positive, twice.** `edittext_default_format_empty` reported
`compile_fail` on two separate runs, *including a sequential one*. It is not a
slow-compile timeout: the link failed with `undefined reference to
avm2_generated_shape_geom_count / avm2_generated_binaries / swf_lzma_alone_*`.
Cause: the `RecompiledABC/abc_timeline.c` I copied into this fresh worktree
predates those symbols, and the auto-invalidation did not fire for this test.
`--recompile` → **PASS**. Worth recording: *a `compile_fail` in a fresh worktree
with copied-in fixtures can be a STALE `RecompiledABC`, not a timeout and not
your patch — check for `undefined reference to avm2_generated_*` before
believing it.*

### 2.6 Net

| | count |
|---|---|
| gains | **+6** |
| regressions | **−2** |
| `ruffle_matched` moves | 0 |
| canary breaks | 0 |
| **NET** | **+4** |

s7-triage predicted Batch C at "+3 net (+4/−1)". Actual **+4 net (+6/−2)** —
the gain side ran two ahead of prediction, and `ContextMenuEvent` did *not* buy
back the away3d regression because that demo is a chain.

---

## 3. Blocker 2 — `visual/definefont4` `#1009 getEffectiveLineHeight`: DIAGNOSED, not fixed

Full 24-frame stack, now visible for the first time (this is what the re-land buys):

```
TypeError: Error #1009: … (accessing field: getEffectiveLineHeight)
	at flashx.textLayout.compose::TextFlowLine/getLineLeading()
	at flashx.textLayout.compose::BaseCompose/calculateLeadingParameters()
	at flashx.textLayout.compose::BaseCompose/finishComposeLine()
	at flashx.textLayout.compose::BaseCompose/fitLineToParcel()
	at flashx.textLayout.compose::SimpleCompose/composeNextLine()
	… 14 more TLF frames …
	at fl.timeline::TimelineManager/addInstance()
	at definefont4_fla::MainTimeline()
```

Decoded from `RecompiledABC/abc0_methods.c` (methods `m1508` = `finishComposeLine`,
`m1509` = `calculateLeadingParameters`, `m2717` = `TextFlowLine.getLineLeading`):

```as3
// finishComposeLine (m1508 ops 59-79)
var curLeaf:FlowLeafElement = this._textFlow.findLeaf(this._curLine.absoluteStart);
var leafStart:int = curLeaf.getAbsoluteStart();          // op 67 — SUCCEEDS
this.calculateLeadingParameters(curLeaf, leafStart, TextFlowLine.findNumberLine(...));

// calculateLeadingParameters (m1509 op 58-66)
this._curLineLeading = this._curLine.getLineLeading(this._blockProgression, curLeaf, leafStart);

// TextFlowLine.getLineLeading (m2717)
var lineEnd:int = this._absoluteStart + this._textLength;   // ops 4-10
var pos:int = leafStart;  var maxLeading:Number = 0;
while (true) {
    h = curLeaf.getEffectiveLineHeight(blockProgression);   // op 18  <-- THROWS
    …
    pos += curLeaf.textLength;                              // ops 51-56
    if (pos >= lineEnd) break;                              // ops 57-61
    curLeaf = curLeaf.getNextLeaf(this._para);              // ops 62-67
}
```

**The null is `curLeaf`, and it is null on a LATER iteration, not on entry** —
proved by op 67 of `finishComposeLine`, which calls `curLeaf.getAbsoluteStart()`
with no null check and does *not* throw. So `findLeaf` returned a real leaf, and
the loop then ran off the end: `getNextLeaf(this._para)` returned `null` while
`pos` was still below `this._absoluteStart + this._textLength`.

That means **the composed `TextFlowLine` claims more text than its paragraph's
leaf chain contains** (either `TextFlowLine._textLength` is too large or some
leaf's `textLength` is 0). It is an invariant violated upstream in TLF's own
compose pipeline — most plausibly because `TextBlock.createTextLine` hands back a
line whose text length is wrong for a font we cannot rasterize (the SWF's only
font is the DefineFont4/CFF that neither recompiler parses).

**This is NOT a missing null guard.** Adding one to `getLineLeading` would
silence the trace but leave the leading wrong, and the next TLF frame would fail
instead. It belongs to whoever picks up the TLF arc (worklist §3, unchanged),
together with the DefineFont4 parsing work scoped in `fonts-and-uncaught.md` §A.3
Step 3. Not fixed here.

---

## 4. Landing notes

* **CI dispatch: `mode=graphics`, `categories=full`** (AVM2 runtime; the risk set
  spans `from_avmplus` and `from_shumway`).
* The two regressions are both `expected_lines == 0` tests whose *image* is the
  real grade; image comparisons never gate trace pass/fail, and both movies died
  mid-frame before this change too — the bundle only makes the death visible.
* Suggested commit split: **one commit**. All five pieces are inside the
  re-land's blast radius, and three of the six gains are unreachable without it.
* Docs to update on landing: `SWFRecompDocs/plans/uncaught-error-worklist.md`
  (§7 → §8: re-landed, +6/−2, away3d's blocker is now `Cast.bitmapData` →
  embedded Flex `BitmapAsset`, definefont4's is §3 above) and
  `SWFRecompDocs/plans/polish-sweep-arc.md` (Batch C actual vs predicted).
