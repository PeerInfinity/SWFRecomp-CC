# w2-errframes — session 12, wave 2 (trace axis, lead T1)

**Mission:** AVM2 error stack-trace frames (T1, 7 live tests, 912 mismatched
lines) + the overlapping stack-trace-rendering shoulder item (C3a/C3b).
**Worktree:** `.claude/worktrees/agent-aceb638278ab53206` at `f166e424e`.
**Deliverables:** `w2-errframes.patch` (this directory), this report.
Runtime-only — **no recompiler change**, so CI `mode=graphics`,
`categories=all`, `images=false` is sufficient.

---

## 1. Result in one line

**All 7 T1 targets pass, plus the C3a rider: +8 tests, 0 regressions across
the canary set.** C3b (`error_stack_trace`) is **refuted as implementable
from data we currently carry** — see §5.

---

## 2. Per-test ledger (all runs in MY worktree, `--recompile`, no-graphics)

### Targets — T1

| test | CI baseline (`6de650432`) | before (worktree) | after | Δ |
|---|---|---|---|---|
| `avm2/primitive_toString` | output_mismatch (gap 257) | FAIL | **pass** | ✅ |
| `avm2/primitive_valueOf` | output_mismatch (gap 260) | FAIL | **pass** | ✅ |
| `avm2/stage_properties2` | output_mismatch (gap 190) | FAIL | **pass** | ✅ |
| `avm2/error_throwerror` | output_mismatch (gap 97) | FAIL | **pass** | ✅ |
| `avm2/proxy_not_overridden` | output_mismatch (gap 50) | FAIL | **pass** | ✅ |
| `avm2/timer_invalid_delay` | output_mismatch (gap 29) | FAIL | **pass** | ✅ |
| `avm2/xml_list_ctor_errors` | output_mismatch (gap 29) | FAIL | **pass** | ✅ |

Every one was **re-verified failing in the worktree before implementing**
(baseline batch, 2026-08-06). None had gone stale.

### Riders

| test | baseline | before | after | note |
|---|---|---|---|---|
| `avm2/error_stack_trace_edge_cases` (C3a) | output_mismatch (gap 6) | FAIL | **pass** | ✅ `getStackTrace()` now makes a real `this.toString()` call |
| `avm2/error_stack_trace` (C3b) | output_mismatch (gap 7) | FAIL | FAIL | **not attempted — refuted, §5** |
| `avm2/accessibilityimplementation` | output_mismatch (gap 18) | FAIL | FAIL | not a frame problem: the whole `flash.accessibility::AccessibilityImplementation` class is missing (line 3 dies with `#1006 accDoDefaultAction is not a function`). Feature surface, not T1. |

### Canaries

| test | baseline | after | verdict |
|---|---|---|---|
| `avm2/system_exit` ★ | pass | **pass** | ✅ the critical one — its expected trace has **no** `Error$/throwError()` frame, and it still doesn't |
| `avm2/textline_throwerror` ★ | pass | **pass** | ✅ |
| `avm2/textblock_createline_errors` ★ | pass | **pass** | ✅ |
| `avm2/content_element_basic` ★ | pass | **pass** | ✅ |
| `avm2/graphics_path` ★ | pass | **pass** | ✅ |
| `avm2/graphics_draw_path` ★ | ruffle_matched | **ruffle_matched** | ✅ effective pass held (`ruffle-matched-trap` checked explicitly) |
| `avm2/error_geterrormessage` | pass | **pass** | ✅ |
| `avm2/coerce_property` | ruffle_matched | **ruffle_matched** | ✅ |
| `avm2/stage_overriden_setters` | pass | **pass** | ✅ the *other* Stage-setter oracle — `stage.scrollRect = null` still gets #2071 |
| `avm2/timer_setdelay` | pass | **pass** | ✅ |
| `avm2/timer_reset` | pass | **pass** | ✅ |
| `avm2/timer` | pass | **pass** | ✅ |
| `avm2/stage_properties` | pass | **pass** | ✅ |
| `avm2/function_call` | pass | **pass** | ✅ exercises `Function.prototype.call` |
| `avm2/object_prototype` | pass | **pass** | ✅ exercises the ES3 prototype shims |
| `avm2/proxy_getproperty` | pass | **pass** | ✅ overridden Proxy hooks |
| `avm2/xml_mismatched_tag` | pass | **pass** | ✅ the *other* E4X parse-error oracle (traces `e`, not `getStackTrace()`) |
| `avm2/xml_ctor_from_tostring` | pass | **pass** | ✅ |
| `avm2/uncaught_errors_stringified` | ruffle_matched | **ruffle_matched** | ✅ the only other consumer of the AS3-URI frame names |
| `avm2/error_stack_trace` | output_mismatch | output_mismatch (same 4 diffs) | ✅ unmoved |
| `avm2/displayobject_scrollrect` | output_mismatch | output_mismatch | ✅ unchanged (a pre-existing float/matrix diff; the `scrollRect` lines themselves match) |
| `avm2/loader_loadbytes_url` | pass | *not evaluable* | its dir holds no `test.swf` (harness-generated), so it `recomp_fail`s in any partial worktree. My change is runtime-only and cannot affect recompilation. |

**21 canaries evaluated, 0 regressions.** (Plus `avm2/displayobject_getrect`,
`textblock_recreateline` and `avm1movie_addcallback_call` — all three
`output_mismatch` before and after, unchanged; see §7.)
★ = the six named must-not-move canaries from the wave-1 brief.

---

## 3. What was implemented, file by file

All changes are **per-site opt-in** — nothing was moved inside
`avm2_throw_error`, exactly as the wave-1 hard constraint required.

### `SWFModernRuntime/include/avm2/avm2_error.h` (+18)
Three new contracts, each documenting its per-site rule:
- `avm2_callstack_push_throwerror(ctx)` — the synthetic `Error$/throwError()`
  frame FP's **AS3-implemented** playerglobal contributes. The header says in
  so many words that `avm2/system_exit` proves this must never move into
  `avm2_throw_error`.
- `avm2_callstack_push_unnamed(ctx)` — a native frame FP has *no* name for.
  It still occupies a line in the trace, but an **empty** one (no `\tat`).
- `avm2_callstack_rename_frame(ctx, own_fn, name)` — swap the innermost frame
  for a synthetic named one (the class-side `Class$/m()` spelling the generic
  renderer cannot derive from a vtable entry). Generalises the idiom
  `system_exit` had open-coded.

### `SWFModernRuntime/src/avm2/avm2_error.c` (+151/-6)
- The three helpers above (`:112-143`).
- `avm2_callstack_frame_name` (`:163-192`): **native** debug_names are now
  printed verbatim in the `bound_class != NULL` branch — the mxmlc
  `a:b/c:d` stripping is gated on `m->file != NULL`. That is what lets a
  builtin registered in a non-public namespace carry its URI. Also: an empty
  native debug_name renders as the empty string (the unnamed-frame marker).
- `callstack_snapshot` (`:242-244`): an empty frame name emits `"\n"` alone
  instead of `"\n\tat "`.
- `error_get_stack_trace` (`:597-604`): calls `this.toString()` as a real
  property call and coerces the result, instead of invoking the built-in
  `error_proto_to_string` directly. **This is C3a.**
- `error_throw_error` (`:1359-1434`) — a real `Error.throwError` static,
  registered at `:1470`. Takes `getErrorMessage(index)`, substitutes
  `%1..%9` in a **single pass** (so a replacement that is itself `"%1"`
  stays literal), and throws `new type(message, index)` with the index as a
  **Number** (`CustomError`'s `arg.constructor` trace pins `[class Number]`).

### `SWFModernRuntime/src/avm2/avm2_globals.c` (+27/-1)
- `avm2_builtin_set_debug_name` (`:430-449`) — rename an already-registered
  public instance method's frame **without touching its key**, so dispatch is
  unaffected. Placed with the other `avm2_builtin_add_*` helpers at ~430,
  well clear of the ~2560 table region `w2-avclasses` owns.
- `avm2_proto_add_function_n` (`:557-562`) — ES3 prototype shims now carry
  the debug_name `"Function/<anonymous>"`.

### `SWFModernRuntime/src/avm2/avm2_function.c` (+9)
`Function`'s `call`/`apply` traits get the AS3-namespace frame spelling
`http://adobe.com/AS3/2006/builtin::call` / `::apply` via the new helper.

### `SWFModernRuntime/src/avm2/avm2_proxy.c` (+13/-1)
- `proxy_unimplemented` pushes the throwError frame.
- `proxy_add_ns_method` builds the frame name as `<PROXY_NS>::<name>` at
  registration, so the trace reads
  `flash.utils::Proxy/http://www.adobe.com/2006/actionscript/flash/proxy::getProperty()`.

### `SWFModernRuntime/src/avm2/avm2_number.c` (+44/-11)
- `number_proto_receiver_check` pushes the throwError frame.
- `numeric_receiver_ok(v, strict)` + a widened `DEFINE_NUMBER_PROTO_SHIMS`
  macro. See §4(a) — the non-obvious half of `primitive_*`.

### `SWFModernRuntime/src/avm2/avm2_string.c` (+3)
`string_proto_receiver`'s #1004 pushes the throwError frame.

### `SWFModernRuntime/src/avm2/avm2_e4x.c` (+5)
`parse_error` pushes the **unnamed** frame — that is the whole of
`xml_list_ctor_errors`.

### `SWFModernRuntime/src/avm2/avm2_display.c` (+90/-3)
- `timer_check_delay` pushes the throwError frame; `timer_set_delay` now
  range-checks the **incoming** value (matching Ruffle's `Timer.as` and FP;
  the old comment claiming FP validates the *old* delay was wrong — §6).
- `stage_throw_2071` pushes the throwError frame.
- `disp_accessor_debug_name` + the in-place branch of the file-local
  `add_getset` now spell accessor frames `get x` / `set x`. The **append**
  path already did (via `avm2_builtin_add_getset`); only the
  replace-in-place path — which is exactly what the Stage overrides use —
  dropped it.
- Stage override table: `mouseEnabled` **added** (it does throw #2071);
  `scrollRect` moved to its own setter; `colorCorrection` added as a real
  accessor pair.
- `stage_set_scroll_rect` — coerces to `flash.geom.Rectangle` **first**, and
  pops its own frame before the #1034, so the trace has no
  `Stage/set scrollRect()` line (FP coerces a setter argument before
  entering the body). A well-typed value still falls through to #2071, which
  is what keeps `stage_overriden_setters` green.
- `stage_get/set_color_correction` — `= null` raises #2007 with **no**
  throwError frame (a core coercion error, not an AS3 raise).

---

## 4. The two findings worth carrying forward

### (a) `int`/`uint` prototype receiver strictness is asymmetric — and it is not a typo

`primitive_toString` and `primitive_valueOf` together pin every cell of this
table with `Cls.prototype.m.call(v)` over `{1.5, uint(2), -2}`:

| | `Number` | `int` | `uint` |
|---|---|---|---|
| `toString` | any numeric | integral only | **any numeric** |
| `valueOf` | any numeric | integral only | **uint-exact** |

`uint.prototype.toString.call(1.5)` returns `"1.5"`; `uint.prototype.valueOf
.call(1.5)` throws #1004; `uint.prototype.valueOf.call(-2)` throws #1004 but
`uint.prototype.toString.call(-2)` returns `"-2"`. Both tests show it, for
both signs, so it is a real avmplus asymmetry between the two halves of
`uint`'s prototype, not a stray expectation. Encoded as the
`NUM_RECV_{ANY,INT,UINT}` knob on `DEFINE_NUMBER_PROTO_SHIMS`.
**T1 as briefed was frame-naming only; these two tests — the two biggest on
the whole trace board — would not have passed on frames alone.**

### (b) `Error.throwError` takes six OPTIONAL arguments, not a rest parameter

`throwError(Error, 3723, "a".."j")` substitutes `%1..%6` and leaves `%7`/`%8`
**empty** — FP's expected text is `stage bounds are (e,f,,)`. Capped by
`AVM2_THROWERROR_MAX_ARGS 6`.

Also pinned by that test: the substitution runs inside `String.replace` with a
closure replacer, so an argument whose `toString()` throws surfaces with the
intermediate frames `Function/<anonymous>()` → `String$/_replace()` on the
stack. That is **Flash's** shape; Ruffle's `output.ruffle.txt` has a different
four-frame chain (`Function/<anonymous>` → `String/…::replace` →
`Function/<anonymous>`). We match Flash and take the full `pass` rather than
`ruffle_matched`.

---

## 5. REFUTED — C3b (`avm2/error_stack_trace`) is not implementable today

The four naming rules are `Test$cinit()`, `MethodInfo-N()`, `Test/uri::f()`,
`Test$/class_method()`, and the +1 needs **all four**. Rule 2 kills it.

`error_stack_trace` (a Flash-IDE `test_fla` SWF) wants `MethodInfo-1()` /
`MethodInfo-2()` for two script-level closures. `proxy_not_overridden`
(mxmlc) wants `Function/<anonymous>()` for a class-nested closure. Both are
`newfunction` targets, so `is_function` cannot separate them — and the
generated method tables settle it:

```
error_stack_trace/RecompiledABC/abc0_methods.c:603:   { abc0_m0, "", 0, 0, 0, ... }
proxy_not_overridden/RecompiledABC/abc0_methods.c:732: { abc0_m0, "", 0, 0, 0, ... }
```

**Every method in both ABCs carries an empty `debug_name`.** The recompiler
does emit `abc.pool.strings[m.name]` (`SWFRecomp/src/abc/abc_emit.cpp:3844`);
the pool entries really are empty in both SWFs. So the two cases are
indistinguishable from any data the runtime holds. Whatever avmplus keys on
(most plausibly the closure's declaring traits) is simply not in our ABC
model, and adding it is a recompiler-side change — out of scope for a
runtime-only wave.

**Recommendation: re-file C3b as a small recompiler/ABC-model item, not a
runtime polish item, and stop re-costing it as +1/M on the trace board.**

Also refuted as a T1 rider: `avm2/accessibilityimplementation` is blocked on a
missing class, not on frames (line 3 of 18 already dies with #1006). It should
move out of T1's rider list and into the AIR/accessibility feature bucket
where the wave-1 §T9 row already puts `native_menu_basic`.

---

## 6. Risk notes

1. **`timer_set_delay` semantics changed.** The old code validated the *old*
   delay and never range-checked the incoming one, with a comment attributing
   that to Ruffle. Ruffle's `Timer.as`
   (`core/src/avm2/globals/flash/utils/Timer.as`, `set delay`) checks
   `!isFinite(value) || value < 0` on the **incoming** value, and FP agrees.
   Covered by canaries `timer`, `timer_setdelay` (sets 500), `timer_reset`.
2. **`avm2_proto_add_function_n` renames every ES3 prototype shim's frame.**
   Verified safe by census: `grep -hoP '^\tat .*$'` over all 19 suites'
   `output.txt` yields **no** bare lowercase method-name frame anywhere in the
   corpus, so nothing expected the old spelling. The only other reader of that
   `debug_name` is the #1064 "cannot call method %s as constructor" message,
   which requires `fn_bound_class != NULL` — prototype shims have none.
3. **Verbatim native debug_names** (the `m->file != NULL` gate). Audited every
   `debug_name = "…"` literal under `src/avm2`: the only one containing `/` is
   `avm2_flixel.c:1140`'s `"FlxQuadTree/ctor$native"`, and that is an
   `instance_init`, which takes the `is_iinit` branch and never reaches the
   changed code.
4. **`Function/call` + `Function/apply` renaming.** No expected output in the
   corpus contains `at Function/call()` or `at Function/apply()`; four tests
   contain the URI form (`primitive_toString`, `primitive_valueOf`,
   `error_throwerror`, `uncaught_errors_stringified` — the last is
   `ruffle_matched` at baseline and is on the canary list).
5. **Stage `scrollRect`.** Two oracles disagree in shape, not substance:
   `stage_overriden_setters` sets it to `null` and wants #2071;
   `stage_properties2` sets it to `2` and wants #1034 *with no setter frame*.
   Both are satisfied because the coercion runs first and pops its own frame.
6. **E4X unnamed frame** is pushed on every parse error, including ones that
   are caught and retried. Safe: `avm2_throw` restores
   `call_depth = tf->saved_call_depth` at every exit, so the un-popped frame
   cannot leak.
7. **Sibling collision check.** `avm2_display.c` edits are at ~3236,
   ~11020-11140, ~11399-11433 and ~14018-14042 — clear of every sibling
   region in the file map (`w2-avclasses` ~5650, `w2-singles` ~11764-11825,
   `w2-gfx-bitmapmax` ~14505/~15224, `w2-gfx-autosize` ~14868/~15055).
   `avm2_error.c`, `avm2_proxy.c`, `avm2_number.c`, `avm2_string.c`,
   `avm2_e4x.c`, `avm2_function.c` are mine alone this wave. The
   `avm2_globals.c` addition sits at ~430, not the ~2560 table.

---

## 7. Predicted CI flips

**+8 confident** (each verified passing locally):
`avm2/{primitive_toString, primitive_valueOf, stage_properties2,
error_throwerror, proxy_not_overridden, timer_invalid_delay,
xml_list_ctor_errors, error_stack_trace_edge_cases}`.

**No extra credit — I checked the two candidates and both are refuted as T1
riders:**
- `avm2/textblock_recreateline` (gap 58): still fails after the frame fix. Its
  live diffs are the T4 `TextBlock` line-list rules (`First line in block:
  line-0` vs `line-4`, and a `1200`/`18` vs `1000`/`115` metrics block). The
  throwError frame it also wants is now correct, but it is not the blocker.
- `avm2/avm1movie_addcallback_call` (gap 14): still fails, and not on frames —
  it dies at line 1 with `#2007 Parameter child must be non-null` where FP
  wants `#1063 Argument count mismatch on flash.display::AVM1Movie/call()`.
  That is the missing `AVM1Movie` class plus native arity checking; genuinely
  sibling-owned, and it should be removed from T1's rider list.

So the T1 rider list in the wave-1 brief was 4 names, of which **1 was real**
(`error_stack_trace_edge_cases`) and 3 are other mechanisms
(`accessibilityimplementation`, `avm1movie_addcallback_call`,
`textblock_recreateline`). Worth recording: *"expects the `Error$/throwError()`
frame"* is a weak co-occurrence key — 14 corpus tests match it, but frames were
the binding constraint in only 8 of them. It named symptoms, not owners
(memory `label-trap`).


`avm2/number_convert_*` are **untouched** — I deliberately did not rename the
`Number|int|uint/…::toFixed/toPrecision/toExponential` frames, because those
tests are adjacent to a sibling-owned number→string arc (wave-1 §T9 says to
coordinate first). That rename is a ready-made follow-up: the mechanism now
exists (`avm2_builtin_set_debug_name`), it is one line per method, and 127
expected frame lines in the corpus want it.

**Regressions: none found** across the canary set in §2.

---

## 8. Process note for the next fan-out

Test dirs `cp -r`'d into a fresh worktree link-fail as `compile_fail` unless
the **first** run passes `--recompile` — and the failure surfaces only as
`collect2: error: ld returned 1 exit status`, which reads exactly like a
source break. I burned two rounds on it. The wave brief's warning is right but
understated: make `--recompile` unconditional in any batch script, not just
the first invocation, because a run that is interrupted mid-copy leaves the
cache half-written again.
