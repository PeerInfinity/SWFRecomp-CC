# w2-trace-smalls — session 15, dual-axis fan-out #7 (WAVE 2, worktree)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a3ad5ff9a1a5f6338`
Base: `42a324cef`. Every flip/canary measured with `--mode=graphics` (the CI
mode). The bug_483783 diagnosis is allocator-level and mode-independent.

## 1. Verdicts

**+3 flips, 26/26 canaries green, zero regressions observed locally.**

| # | item | verdict | flip |
|---|---|---|---|
| 1 | `avm1/textfield_asbroadcaster` | **GO — LANDED** | `output_mismatch` → **pass** |
| 2 | `avm2/sub_super_same_field` | **GO — LANDED** | `output_mismatch` → **pass** |
| 3a | `avm2/number_convert_edge_cases` | **GO — LANDED** | `output_mismatch` → **pass** |
| 3b | `avm2/number_convert_errors` | **NO-GO this wave** (blocked on int/uint primitive dispatch — §4b) | 0 |
| 4 | `from_avmplus/regress/bug_483783` | **NO-GO — brief's premise REFUTED by measurement** | 0 |

Patches (in this worktree, `SWFRecompDocs/plans/session15-fanout-reports/`):

- `w2-smalls-textfield-asbroadcaster.patch` — `SWFModernRuntime/src/actionmodern/action.c` only
- `w2-smalls-sub-super-same-field.patch` — `SWFRecomp/include/abc/abc_typemodel.hpp` + `SWFRecomp/src/abc/abc_emit.cpp`
- `w2-smalls-number-convert-edge-cases.patch` — `SWFModernRuntime/src/avm2/avm2_number.c` only

The three patches are file-disjoint and can be landed independently. None
touches a file another wave-2 agent was assigned (no collisions found:
matrix3d/stage3d, watch/addProperty dispatch, `avm2_text.c`'s FTE region,
`avm2_globals.c`'s `dt_*` tables, AVM1 timeline placement/depth, and
`avm2_display.c`'s child-timeline path are all untouched).

---

## 2. Item 1 — `avm1/textfield_asbroadcaster` (+1, LANDED)

### Refutation of the wave-1 board's framing

The board (§1.5) says the fixture "plus the built-in `onChanged` /
`onScroller` / `onSetFocus` / `onKillFocus` broadcasts firing from
`tf.text = …`, `tf.scroll = …`, `Selection.setFocus(…)`". **It does not.**
The expected output between the `========================` marker and
`// Done` is EMPTY — Flash fires none of those on a programmatic write, and
`Selection.setFocus` broadcasts on `Selection`'s listener list, not the
field's. No broadcast-on-write work was needed, and adding any would have
made the test worse.

### Mechanism (two defects, both required)

1. **TextField instances were never AsBroadcaster-initialized.** Only
   `TextField.prototype` was (`initTextFieldPrototype` → `installAsBroadcaster`),
   so every field in the movie shared ONE zero-length `_listeners` array.
   Flash runs `AsBroadcaster.initialize` on each EditText's AVM1 object at
   post-instantiation and then installs the field ITSELF as listener 0 —
   that is what makes the field's own `on*` handlers run before any added
   listener's (Ruffle `core/src/display_object/edit_text.rs:2099`
   `initialize_as_broadcaster`, called from `post_instantiation` at :2175).
   Hence `tf._listeners.length == 1`, `tf._listeners[0] == tf`.
2. **The three AsBroadcaster builtins could not see a MovieClip receiver.**
   `builtin_broadcaster_{addListener,removeListener,broadcastMessage}` read
   the receiver from `this_obj` (falling back to `g_c_function_this_obj`).
   `actionCallMethod`'s MOVIECLIP arm passes `this_obj = NULL` and leaves
   `g_c_function_this_obj` NULL, communicating the receiver via
   `g_event_this_mc` instead (the convention `builtin_object_valueOf` at
   `action.c:4274` already documents). So with defect 1 fixed, `tf.addListener`
   still silently no-oped on a NULL receiver — the test went 4/14 → 4/14 on
   the first A/B leg and only flipped once both were fixed.

### Touched functions — `SWFModernRuntime/src/actionmodern/action.c`

- **new** `installTextFieldBroadcaster(app_context, MovieClip*)` (next to
  `installAsBroadcaster`; forward-declared above `initTextFieldPrototype`).
  SWF6+ only (matching the existing `__proto__` gates), idempotent (bails if
  `_listeners` is already an OWN property, so the clone/timeline re-entry
  paths cannot drop listeners the script added).
- **new** `broadcasterReceiver(void* this_obj)` — the `this_obj` →
  `g_c_function_this_obj` → `g_event_this_mc->dynamic_props` ladder.
- `builtin_broadcaster_addListener` / `…_removeListener` /
  `…_broadcastMessage` — receiver resolution now goes through the ladder
  (3 call sites, one line each).
- 4 EditText instantiation sites now call the installer (all the places that
  already set `props->native_type = NATIVE_TEXTFIELD` on a MovieClip):
  static field at a root depth, nested static field by char id,
  `actionInitDynTextFieldClone`, and `createTextField`. `new TextField()`
  (a bare ASObject, not an EditText) deliberately does NOT get it — Flash
  only broadcaster-initializes real display objects.

The self-reference is stored as an `ACTION_STACK_VALUE_MOVIECLIP` element, so
it takes no refcount (`setArrayElement` retains only OBJECT/ARRAY) and creates
no cycle.

### Before / after

```
textfield_asbroadcaster   output_mismatch (10 of 14 lines wrong) -> PASS
```

### Canaries (all `pass` at baseline `bf585e448`, all still `pass`)

`as_broadcaster`, `as_broadcaster_initialize`, `as_broadcaster_undef`,
`file_reference_list_asbroadcaster`, `mcl_as_broadcaster`, `mouse_listeners`,
`selection_asbroadcaster` — the whole AsBroadcaster family, plus the EditText
instantiation paths the 4 new call sites sit on:
`clone_sprite_edittext`, `clone_sprite_edittext_dynamic`,
`edittext_default_format`, `edittext_focus_selection`,
`edittext_html_roundtrip`, `edittext_input`. **13/13 green.**

---

## 3. Item 2 — `avm2/sub_super_same_field` (+1, LANDED)

### The board's mechanism claim is right; its location claim is wrong

Board §1.6 says "the change is in slot allocation (recompiler `abc_emit`
side) rather than lookup". **Slot allocation was already correct.** I dumped
the ABC (`SWFRecomp --dump-abc`): `LevelOne` declares
`pubSameName`/`internalSameName` with `slot_id 0` (auto), and `LevelTwo` /
`LevelThree` re-declare the SAME QNames — the manual edit repointed the
subclass traits' name multinames at `mn[4]`/`mn[6]` while leaving the now-dead
`"pubSameName_SUFFIX2"` strings in the pool. `avm2_vtable_add_traits`
(avm2_class.c) already gives a redeclared slot a NEW index and keeps the
parent's storage, so a `LevelThree` instance really does carry six distinct
slots (1,2 = LevelOne · 3,4 = LevelTwo · 5,6 = LevelThree) with all six trait
defaults populated. The values were all there; only the BINDING was wrong.

### Actual mechanism

Every read site is `GetLocal r0; GetPropertyStatic mn[4]` — a by-name lookup
on `this`. avmplus's verifier early-binds that against the *declaring class's*
traits table (a `getslot`), so `LevelOne.print` reads LevelOne's slot even
when `this` is a `LevelThree`. We resolved it dynamically against the
instance's vtable, which only ever holds the most-derived entry per QName —
so all six "In LevelOne:"/"In LevelTwo:" lines printed the most-derived value.

The recompiler already HAS this lever ("Lever A: `this.field`"), and it was
being switched off for exactly this shape by two guards, both of which encode
our own runtime's dynamic-lookup rule rather than avmplus's:

1. `AbcTypeModel::subclassRedeclares(cls, name)` — its own comment said it
   "Guards the sub/super same-field case (avm2 sub_super_same_field)". It is
   the wrong guard: a subclass that redeclares a name gets its OWN binding and
   its own slot index, so the ancestor site must keep reading the ancestor
   slot. Removed from both codegen levers (it survives for the env-gated
   `SWF_CENSUS_PROPREAD` diagnostics).
2. `AbcTypeModel::findUniqueSlot`'s `hits != 1` bail — ns-blind and
   deliberately conservative. It is what kept `LevelTwo.print` (which sees
   `pubSameName` twice up the chain) unbound.

### Touched functions

- `SWFRecomp/include/abc/abc_typemodel.hpp`
  - **new** `findBindingSlot(inst, name, site_mn)` — avmplus binding
    resolution: the MOST-DERIVED declaration at or above `inst` whose local
    name matches AND whose QName ns-matches the site multiname. Bails if that
    declaration is an accessor/method, or if one class declares the name twice
    under matching namespaces.
  - `findUniqueSlot(...)` — unchanged primary path; `findBindingSlot` runs
    only as a **fallback when the old path already bailed** and a site
    multiname is available. Existing specializations are bit-identical; the
    change can only ADD sites, never re-point one.
  - `instSlotForStore(cls, mn, recv_is_this=false)` — drops the
    `subclassRedeclares` bail for a `this` receiver only. A merely
    statically-typed receiver keeps the old bail, because the READ lever does
    not fire for those, and a store-without-matching-read would be a new
    read/write asymmetry.
  - `subclassRedeclares` — comment rewritten to say it is census-only and why.
- `SWFRecomp/src/abc/abc_emit.cpp`
  - `GetPropertyStatic` lever A: dropped `&& !M.subclassRedeclares(...)`.
  - `SetPropertyStatic`/`InitProperty` store lever: passes `recv.is_this`.

Blast radius is exactly the two `this.field` levers: `findUniqueSlot`'s other
two callers (`abc_emit.cpp:3248`, `:3311`) pass no `site_mn`, so they take the
unchanged path.

### Before / after

```
sub_super_same_field   output_mismatch (6 of 12 lines wrong) -> PASS
```

### Canaries

The whole slot/super family, all `pass` at baseline: `class_supercalls_errors`,
`class_supercalls_mismatched`, `get_slot_edge_cases`,
`slot_disp_id_shared_numbering`, `slots_force_autoassigned`, `super_get_call`,
`supercall_two_classobjects`, `supercalls_weird`,
`subclass_superclass_linked_symbol`, plus `number_toprecision`,
`number_tofixed`, `number_toexponential`, `number_constr`.
Result: see §6. (`avm2/supercalls_coerce` is `output_mismatch` at baseline and
was left alone.)

**CI note:** this is a recompiler-emission change → the merged run wants
`categories=full`.

---

## 4. Item 3 — the `Number$/_convert` pair: SPLIT

The board (§1.8) prices this pair as "+1 / +2 / +2, mechanical — every expected
throw carries two frames we do not emit". **The frame story is right for
`number_convert_errors` and irrelevant to `number_convert_edge_cases`, and the
two rows have completely different costs.**

### 4a. `avm2/number_convert_edge_cases` — GO, LANDED (+1)

Not a frame problem at all: this fixture traces no stack frames. 32 of 180
lines differ, in exactly **three value mechanisms**, all inside
`avm2_number.c`:

| # | mechanism | rows |
|---|---|---|
| M1 | `null` precision is ABSENT, not 0. `NaN.toPrecision(null)` → `"NaN"`, while `NaN.toPrecision(0)` is still `#1002`. | 6 |
| M2 | `print_with_precision` is a Ruffle port that rounds then prints with the SHORTEST round-trip formatter, so every trailing zero the precision asked for is dropped and zero always prints `"0"`. | 18 |
| M3 | `(-0).toFixed(k)` printed `"-0.00"`. ECMA emits `"-"` only for `x < 0`, and `-0` is not `< 0`; C's `%f` prints the sign bit. | 8 |

M2's replacement rule (`e` = decimal exponent of the value already rounded to
`p` significant digits, read back out of `%.*e` so printf owns the
`9.99 → 1e+1` rounding):

```
non-finite   -> "NaN" / "±Infinity"   (AFTER the range check)
zero         -> "%.*f" of 0.0 with p fraction digits  ("0." + p zeros)
p <= e       -> exponential, p-1 fraction digits, exponent spelled "e%+d"
otherwise    -> FIXED, p-1-e fraction digits
```

Note the last arm has **no ECMA "e < -6 → exponential" escape**: FP prints
`(1.2315e-8).toPrecision(1)` as `"0.00000001"`, not `"1e-8"`. That is pinned
by `avm2/number_toprecision`, which is a currently-PASSING test — the rule was
derived from its fixture, not guessed. I unit-tested the new formula against
18 cases drawn from both fixtures (`…/scratchpad/tp.c`); 18/18 match, including
every `number_toprecision` value.

Touched functions (`SWFModernRuntime/src/avm2/avm2_number.c` only):
`print_with_precision` (rewritten), `number_to_precision` (null arm),
`number_to_fixed` (negative-zero normalization).

`number_toprecision` is graded with `[approximations] bare_numbers = true,
max_relative = 0.001`, so it was never sensitive to the missing trailing
zeros — which is why an obviously wrong formatter survived in a green test.

### 4b. `avm2/number_convert_errors` — NO-GO this wave, re-priced

The 186-line gap (685 actual vs 871 expected) IS entirely frames, and it
decomposes exactly: 108 throws × 1 missing `at Number$/_convert()`, plus 72
int/uint calls × 1 missing forwarder frame, plus 6 in `testCoercionErrors`.
Two of the three sub-fixes are trivial and provably zero-risk (I grepped the
whole corpus: `number_convert_errors/output.txt` is the ONLY expected file
anywhere that pins an `at Number/…` frame):

- **F1** — push a `Number$/_convert` frame in `throw_1002`, same one-liner
  shape as the existing `avm2_callstack_push_throwerror`.
- **F2** — `avm2_builtin_set_debug_name(..., "toPrecision",
  "http://adobe.com/AS3/2006/builtin::toPrecision")` (and toFixed /
  toExponential) so the frame reads
  `Number/http://adobe.com/AS3/2006/builtin::toPrecision()`. The helper
  already exists for exactly this and does not touch the vtable key.

**F3 is the blocker and it is structural.** The expected trace wants a
*separate* `int/…::toPrecision()` frame under Number's. Our runtime cannot
produce it: primitive receivers dispatch off the **Number** class ivtable by
design (`avm2_number.c` header comment), and `avm2_uint_value` stores a uint as
`AVM2_VALUE_INTEGER` when it fits — so at the point of the call an
`int(x)` receiver, a `uint(x)` receiver and a whole-valued `Number(x)` receiver
are the same value with the same kind. Recovering "which of the three
classes did the call site name" needs the verifier's static type, i.e. a
recompiler-side early-bind of `callproperty` on a primitive — not a
wave-2 patch, and much closer in size to the AVM2 dispatch arcs than to a
"small certain win".

Since F1+F2 without F3 flip nothing, I did **not** land them; they are logged
here so the next agent can take them together with an int/uint dispatch change.
Re-priced: this row is **+1 only as part of a primitive-dispatch item**, not
`+1` on its own.

**Board correction:** cluster 9's "+1 / +2 / +2" should read **+1 / +1 / +2**,
and the two rows should not be briefed together — they share an API surface
and nothing else.

---

## 5. Item 4 — `from_avmplus/regress/bug_483783`: NO-GO, and the brief's
premise is refuted

### The premise

The brief (and board §1.9) reads: "a 76 KB `heap_alloc` failing inside a 4 GB
o1heap arena … so this is o1heap fragmentation/binning under the test's
repeated large-string doubling, not a real OOM."

### The measurement

I rebuilt the test's kept build dir with `o1heapGetDiagnostics` printed at the
failure point:

```
ERROR: heap_alloc(76396) failed - out of memory
[HEAPDIAG] capacity=4294966720 allocated=4294883968 peak_allocated=4294883968
           peak_req=110592 oom=1
```

`allocated / capacity = 4,294,883,968 / 4,294,966,720 = 99.998 %`. **The arena
is genuinely full.** It is not fragmentation, not bin geometry, not alignment
— there is 82,752 bytes of headroom left and the request rounds to a 131,072-byte
fragment. Any binning fix would buy one more iteration.

### Why it fills

`avm2_string_concat` (avm2_value.c:141) allocates `sizeof(Avm2String) + total + 1`
per concat with **no capacity slack**, and o1heap rounds that to the next power
of two. `myString += "a"` therefore costs ~1.5·j bytes at iteration j and the
result is only reclaimable by the GC. The failure lands at
j ≈ (76396 − 33) ≈ **76,363 of 3,000,000** iterations, which matches
Σ pow2ceil(j+33) ≈ 0.75·N² = 4.29 GB at N ≈ 75.6 k. Retaining every
intermediate for the full loop would need Σ(1…3e6) ≈ **4.5 TB**, so no arena
size fixes this — confirming the session-10 finding recorded in project memory
(`avm2-gc-cannot-run-mid-method`).

### Why the obvious fix is forbidden

The collector may only run between ticks: recompiled method bodies hold
`Avm2Value loc[N]; Avm2Value stk[M];` as plain C locals that
`avm2_gc_mark_roots_*` cannot see. A collect triggered from inside a failing
`heap_alloc` would sweep the accumulating string and the caller would `memcpy`
freed memory — a *passing-looking wrong answer*, not a crash. This row was
already ruled out on exactly that basis in session 10
(`SWFRecompDocs/plans/session10-fanout-reports/w2-taxonomy-report.md` §B7).

### NO-GO, with a third design worth adding to the arc

The two designs already priced in the s10 arc are both GC-timing changes
(precise shadow stack; conservative C-stack scan). My diagnosis surfaces a
third that avoids the collector entirely and is the one avmplus itself uses
for this exact Tamarin regression — **dependent strings**:

- split `Avm2String` from its byte buffer, give the buffer a
  `{capacity, used}` header and grow it by doubling;
- `avm2_string_concat(a, b)` where `a` is the buffer's current tip
  (`a->len == buf->used`) and `b` fits in the slack writes `b` at
  `buf->used` and returns a NEW 32-byte `Avm2String` header pointing at the
  same buffer with the larger length. Strings stay immutable — `a` still sees
  its own prefix — so the aliasing hazard that blocks naive in-place append
  does not arise.
- Cost for this test: ~3 M headers (≈192 MB after o1heap's pow2 rounding) plus
  ~8 MB of doubling churn, i.e. ~200 MB against a 4 GB arena, and O(n) instead
  of O(n²).
- Cost elsewhere: the buffer needs its own lifetime (the GC currently frees
  header+bytes as one block), which is the structural part. Not a wave-2
  patch.

**Contained fix: none. Deliverable = diagnosis + NO-GO.** Nothing in this
item was changed in the tree; the instrumented `heap.c` lives only in the
throwaway build dir
(`…/scratchpad/bd483783/heap.c`), NOT in `SWFModernRuntime`.

---

## 6. Ledger — every test run, `--mode=graphics`

Baselines are the merged per-suite `results_graphics.json` at `bf585e448`.

### Flips (3)

| test | suite | baseline | after |
|---|---|---|---|
| `textfield_asbroadcaster` | avm1 | `output_mismatch` | **pass** |
| `sub_super_same_field` | avm2 | `output_mismatch` | **pass** |
| `number_convert_edge_cases` | avm2 | `output_mismatch` | **pass** |

### Canaries — 26 runs, all `pass` at baseline, all `pass` after (0 regressions)

AsBroadcaster family (avm1): `as_broadcaster`, `as_broadcaster_initialize`,
`as_broadcaster_undef`, `file_reference_list_asbroadcaster`,
`mcl_as_broadcaster`, `mouse_listeners`, `selection_asbroadcaster`.

EditText instantiation paths (avm1): `clone_sprite_edittext`,
`clone_sprite_edittext_dynamic`, `edittext_default_format`,
`edittext_focus_selection`, `edittext_html_roundtrip`, `edittext_input`.

Slot / super family (avm2): `class_supercalls_errors`,
`class_supercalls_mismatched`, `get_slot_edge_cases`,
`slot_disp_id_shared_numbering`, `slots_force_autoassigned`, `super_get_call`,
`supercall_two_classobjects`, `supercalls_weird`,
`subclass_superclass_linked_symbol`.

Number surface (avm2): `number_toprecision`, `number_tofixed`,
`number_toexponential`, `number_constr` — run TWICE, once against the
recompiler change alone and again against the `avm2_number.c` change, both
green. `sub_super_same_field` was likewise re-verified against the final
recompiler binary after the `instSlotForStore` narrowing.

Deliberately untouched (already failing at baseline, not in scope):
`avm2/supercalls_coerce`, `avm2/number_tostring` (separate big-integer radix
defect — board §1.8 is right to say do not bundle it),
`avm2/number_convert_errors` (see §4b).

### CI guidance for the merge

- The recompiler patch changes AVM2 emission → dispatch `categories=full`.
- Mode: `graphics` (default). Nothing here touches a no-graphics-only arm.
- `images=false`.

## 7. Board corrections (for arc §15.3 / the s15 closeout)

1. **§1.5 `textfield_asbroadcaster`** — the "built-in `onChanged`/`onScroller`/
   `onSetFocus`/`onKillFocus` broadcasts firing from `tf.text = …`,
   `tf.scroll = …`, `Selection.setFocus(…)`" half of the diagnosis is wrong;
   the fixture expects NO output from any of those. The real second half was
   the MOVIECLIP-receiver convention in the AsBroadcaster builtins.
2. **§1.6 `sub_super_same_field`** — "the change is in slot allocation
   (recompiler `abc_emit` side) rather than lookup" is half right: it IS a
   recompiler change, but slot ALLOCATION was already correct in both the
   recompiler and the runtime. What was wrong was the compile-time BINDING —
   two guards (`subclassRedeclares`, and `findUniqueSlot`'s ns-blind
   `hits != 1` bail) that encode our own dynamic-lookup rule instead of
   avmplus's static early-bind.
3. **§1.8 `Number$/_convert`** — re-price to **+1 / +1 / +2** and split the
   pair. `number_convert_edge_cases` has nothing to do with frames (three
   value mechanisms, landed); `number_convert_errors` is blocked on
   int/uint primitive dispatch, which is not a small win.
4. **§1.9 `bug_483783`** — the "o1heap fragmentation/binning, not a real OOM"
   premise is **refuted by measurement**: `allocated/capacity = 99.998 %`.
   The row is a genuine arena exhaustion at iteration ~76,363 of 3,000,000 and
   belongs to the "GC during long-running script loops" arc, exactly as
   session 10 ruled. Suggest striking it from future small-wins boards and
   adding the dependent-string design (§5) as a third option in that arc.
