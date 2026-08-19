# Session 17 · wave 2 · T4 `all_classes/events` — implementation report

**Agent:** `w2-all-classes-events` (worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a0fd280ab98c26b00`).
**Base:** `88ebde665`. **Briefs of record:** `wave1-trace-board.md` §T4 +
`wave1-trace-board.leads.json` `T4-all-classes-events`; method of record =
`session16-fanout-reports/w2-all-classes-display-report.md`.
**Patch:** `w2-all-classes-events.patch` (same directory), **2,018 diff lines**,
of which **1,420 are the generated `flash.events` descriptor block**.

---

## 0. NEW FILES — **NONE.**

The patch modifies six existing files and creates none. `git apply --stat`
lists exactly:

```
 SWFModernRuntime/include/avm2/avm2_globals.h |    3 +
 SWFModernRuntime/src/avm2/avm2_events.c      |   19 +-
 SWFModernRuntime/src/avm2/avm2_globals.c     | 1598 +++++++++++++++++++++++++-
 tools/descriptor/as_model.py                 |   47 +-
 tools/descriptor/gen_display_descriptors.py  |   87 +-
 tools/descriptor/xml_model.py                |   23 +-
```

No new header, no new `.c`, no new generator script, no new test fixture. The
1,420-line generated block lives **inside `avm2_globals.c`** between a second
marker pair, for the same reason session 16 put the `flash.display` block
there (`verify_output.py:2154` copies an explicit source list, so a new header
is invisible to the harness). Everything in the block is `static`.

---

## 1. VERDICT — **GO. +5 / +5. §17.4's "0 flips" is REFUTED, and so is the
board's own "real +3": the ceiling landed.**

| row | before (CI `31877239992`) | after | expected lines | our lines after |
|---|---|---|---|---|
| `avm2/all_classes/events/swf9`  | output_mismatch (731/1030, 10 matching) | **pass** | 1030 | 1030 |
| `avm2/all_classes/events/swf10` | output_mismatch (731/1638, 15 matching) | **pass** | 1638 | 1638 |
| `avm2/all_classes/events/swf11` | output_mismatch (731/1750, 15 matching) | **pass** | 1750 | 1750 |
| `avm2/all_classes/events/swf12` | output_mismatch (731/1814, 15 matching) | **pass** | 1814 | 1814 |
| `avm2/all_classes/events/swf30` | output_mismatch (735/2353, 25 matching) | **pass** | 2353 | 2353 |

**All five flipped on the FIRST build carrying the patch** (swf30 first, then
the other four with no further change) — the same one-build-cycle outcome the
`flash.display` arc had, and for the same reason: the free, build-less oracle
(`check_model.py`) was driven to **0 element mismatches before a single line of
C was compiled**.

`all_classes` is now **100 % green: 7 packages / 26 rows, zero failures.**

Effect on the tracked metric: **+5 effective** (all five are `output_mismatch`
today, and `scripts/corpus_status_diff.py` counts `pass + ruffle_matched` over
the whole corpus). They are also listed in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:99-103`, so they do **not**
move the *filtered* rate — the coordinator may want to prune those five lines
now that they pass (I did not touch the ignore list; `w2-tooling-hygiene` owns
it).

---

## 2. What the 95 model mismatches actually were (board §T4 audited)

The board priced "~1 mechanism + ~6 adjudications". Measured exactly, at HEAD:

| defect | mismatches | disposition |
|---|---:|---|
| `IEventDispatcher`'s 5 methods need `uri="flash.events:IEventDispatcher"` | 50 (10 × 5 versions) | **mechanism** — `xml_model._uri_attr` |
| `KeyboardEvent` ctor: 2 AIR-only trailing params | 10 | adjudication |
| `FocusEvent` ctor: 1 AIR-only trailing param (`direction`) | 10 | adjudication |
| `GestureEvent` ctor: 2 AIR-only trailing params | 8 | adjudication |
| `PressAndTapGestureEvent` ctor: 1 | 8 | adjudication |
| `TransformGestureEvent` ctor: 2 | 8 | adjudication |
| `AVLoadInfoEvent.AV_LOAD_INFO` absent from the model | 1 | **parser bug**, not an adjudication |
| **total** | **95** | |

Two board/s16 claims are corrected here:

* **`MouseEvent` and `TouchEvent` do NOT diverge.** The s16 rider (§8 of the
  display report) named them alongside the five real cases; their `.as`
  signatures match the oracles exactly at every version. The adjudication
  table therefore has **5 entries, not 7**, and it says so in a comment.
* **The 6th "adjudication" is a parser bug.** `AVLoadInfoEvent` declares
  `public static const AV_LOAD_INFO = "avLoadInfo"` with **no type
  annotation**; `as_model._VAR` required `:type`, so the constant was dropped
  from the model entirely. Flash reports `type="*"` — the *declaration*, not
  the value, decides. Making the annotation optional is a 3-line regex change;
  a corpus-wide scan found only four untyped declarations in all of
  playerglobal (`Toplevel.as::undefined`, `flash.trace.Trace`'s two,
  and this one), **none in `flash.display`**, so the shipped display block is
  unaffected — re-graded at 0 to prove it.

The AIR-only-tail rule cannot be derived: `[API("N")]` annotates
declarations, never individual parameters, and Ruffle's `.as` writes one
(AIR) signature. It is therefore an explicit, documented table
(`as_model.AIR_ONLY_CTOR_TAIL`, 5 entries) keyed by class, cross-checked
against 4–5 independent version oracles each.

### The free oracle, before and after

```
$ python3 tools/descriptor/check_model.py <suite>/events  flash.events
   swf9 14  swf10 20  swf11 20  swf12 20  swf30 21   TOTAL 95     # at HEAD
   TOTAL mismatches: 0                                            # with this patch
$ python3 tools/descriptor/check_model.py <suite>/display flash.display
   TOTAL mismatches: 0    # unchanged — the parser/uri changes are display-neutral
```
`errors`, `security`, `display3D`, `xml` also re-graded at **0**;
`accessibility` reports its 2 pre-existing "absent from expected file"
rows (a fixture quirk at swf9, present before this patch).

---

## 3. Why the FLOOR was 0, and what closed it

The board set the floor at 0 because the runtime was **pinned at 731 / 731 /
731 / 731 / 735 actual lines** — "the emitter does not describe the events
classes at all yet". That diagnosis is right and it was the bulk of the work.
Measured against `swf9`, our baseline capture describes **21 classes where
Flash describes 28**, and structurally differs in **221 elements**
(`check_model.py --actual`). Four distinct causes, in descending size:

1. **45 flash.events classes did not exist.** `avm2_events.c` registers 21 of
   the 67 the fixture walks. `flash.display`'s arc needed 14 new shells; this
   one needs 45. They are registered from a table in `avm2_globals.c`
   (`register_events_shell_classes`) with the correct base and the correct
   `[API("N")]` gate, and their whole describeType surface comes from the
   generated rows.
2. **Every accessor / method we DID register reported `type="*"`** — no
   descriptor rows existed for the package beyond a hand-written `Event` and
   `EventDispatcher` pair. 483 generated member rows fix that.
3. **`declaredBy` pointed at the wrong class for `clone`/`toString`** on
   almost every subclass (we register them once on `Event`; playerglobal
   overrides them per class). 65 generated `DtDescRedecl` re-points, derived
   mechanically from a BASELINE capture, fix that; 14 hide rows drop the
   members we carry that playerglobal does not
   (`FocusEvent.direction`, `ContextMenuEvent.isMouseTargetInaccessible`,
   `MouseEvent.commandKey`, `Event.CLOSING/EXITING/SUSPEND`, …).
4. **Two real runtime bugs** (§4).

---

## 4. Two runtime bugs this fixture exposed (not test accommodations)

**(a) `EventDispatcher` described its five interface methods TWICE.**
`avm2_events.c` builds five interface-namespace *alias* vtable entries so
`IEventDispatcher`-typed dispatch works, but — unlike the ABC-side aliases at
`avm2_class.c:1263` — never set `alias.is_iface_alias = 1`, the flag
`dt_collect_vtable` (`avm2_globals.c:4277`) uses to skip dispatch machinery.
Every subclass hid the duplicate by accident: `HIDE_NSURI_METHODS` suppresses
a namespace the **superclass** already declares, and every subclass of
EventDispatcher inherits it. `EventDispatcher` itself, whose superclass is
`Object`, is the one class the shadow rule cannot cover — and
`all_classes/events` is the first fixture that describes it. One line.

**(b) `TouchEvent` was exposed at SWF 9.** Ruffle's `TouchEvent.as` carries
`[API("667")]` = SWF 10, and `all_classes/events/swf9` lists it as "not
accessible"; we registered it with the ungated `avm2_builtin_class`. Changed
to `avm2_builtin_class_api(..., 10)`.

---

## 5. Files changed

| file | what |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_globals.c` | the **1,420-line generated `flash.events` block** between a new marker pair; `DT_DESC_EVENTS_ROWS` spliced into `dt_desc_classes`; the two hand-written `flash.events` rows + their `dt_m_event` / `dt_m_eventdispatcher` / param tables **removed** (`dt_desc_find` takes the first match, so a hand row left above would shadow the generated one); `register_events_shell_classes` (45 classes, ~75 LOC) + its call after `register_security_certs`. |
| `SWFModernRuntime/src/avm2/avm2_events.c` | `alias.is_iface_alias = 1` (§4a); `TouchEvent` → `avm2_builtin_class_api(..., 10)` (§4b); `b->error_event_class = er`. |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | one field: `Avm2Class* error_event_class` (four shells extend `ErrorEvent`, which was the only base not already cached). |
| `tools/descriptor/as_model.py` | optional type annotation on `var`/`const`; `AIR_ONLY_CTOR_TAIL` (5 entries) applied in `load_globals`. |
| `tools/descriptor/xml_model.py` | `_uri_attr` — a member an INTERFACE declares reports `uri="<pkg>:<Interface>"`. |
| `tools/descriptor/gen_display_descriptors.py` | package-parameterised: `--pkg`, a `Pkg` object owning the marker pair / symbol prefix / ROWS macro name. `--pkg flash.display` still emits `dtd_*` and `DT_DESC_DISPLAY_ROWS` byte-compatibly; `flash.events` emits `dtev_*` and `DT_DESC_EVENTS_ROWS`. **The shipped display block is not regenerated by this patch and is byte-identical.** |

**Sibling-overlap.** Per `SIBLING_FILE_MAP.md` I own `tools/descriptor/*` and
the `avm2_globals.c` generated block. Two notes:

* **`FullScreenEvent` — coordinate with `w2-matrix3d-classes` (T7).** My shell
  table registers it (`extends ActivityEvent`, ungated), because
  `all_classes/events/swf9..swf30` all describe it. If that agent also adds a
  `FullScreenEvent` registration, **drop theirs and keep mine** (mine also
  carries the 8 descriptor rows the fixture grades); `NativeMenuItem` /
  `NativeMenu` / `AutomationAction` are untouched by me. `avm2_stage3d.c` is
  not in my diff.
* `avm2_events.c` and `avm2_globals.h` are in no other agent's column in the
  map; my edits there are 3 sites totalling 19 and 3 lines.

---

## 6. Class layer: 45 shells, and the gate blast radius is ZERO

45 `flash.events` classes registered (28 of them API-gated: 12 at SWF 10, 4 at
11, 2 at 12, 1 at 13, 2 at 14, 6 at 20, 2 at 21, 3 at 22, 1 at 38, 1 hidden at
every version — `DRMAuthenticateEvent`, `[API]` odd ordinal = AIR-only), plus
the `TouchEvent` gate at 10.

`gaterisk.py` (scratch, s16's method) cross-joined every gated or newly-visible
class name against every test in the **entire corpus** whose sources mention it
and whose `test.swf` header version sits below the gate:

```
== at-risk (gated class referenced from an under-versioned SWF) ==
  total: 0
== tests naming a NEWLY-REGISTERED (ungated) class ==
  avm2/stage_display_state    FullScreenEvent    swf43
  total: 1
```

So no test anywhere can lose a name to the new gates, and exactly one test
gains one — `stage_display_state`, which is `output_mismatch` at baseline and
is graded below.

**Deliberately not done:** the shells carry their constants
*describe-only* (from `DtDescConst` / synthetic rows), not as real class
properties, so `ActivityEvent.ACTIVITY` still reads `undefined` at runtime.
That is exactly the trade the 14 `flash.display` shells make, no graded test
reads one, and promoting all 199 to real `avm2_builtin_add_static_const` calls
is a mechanical follow-on the generator already has the values for. Shells DO
inherit their base's constructor (`cls->instance_init.fn = base->...`), so
`new SyncEvent("sync")` and `new UncaughtErrorEvents()` behave, which the
`flash.display` shells do not bother with.

---

## 7. Canary results

**44 canary rows graded** (`--mode=graphics`, `-P 2`, `--recompile` on first use of
every copied directory, `SWFRECOMP_COMPILE_TIMEOUT=2400`; baseline read from the
graded CI run `31877239992` at `c7b284034`, i.e.
`ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`).

### **ZERO REGRESSIONS. All 44 rows landed on EXACTLY their baseline status.**

| tier | rows | baseline | after |
|---|---|---|---|
| 1 — **the `flash.display` block must not move** | `all_classes/display/swf{9,10,11,12,13,30}` | 6 × pass | **6 × pass** |
| 1 — the other five `all_classes` packages | `accessibility/swf{9,10,30}`, `display3D/swf{12,13,30}`, `errors/swf{9,10,30}`, `security/swf{11,12,13,30}`, `xml/swf{9,30}` | 15 × pass | **15 × pass** |
| 2 — `describeType` consumers | `describe_type_basic`, `describe_type_json`, `describe_type_metadata`, `describe_type_native` | 4 × pass | **4 × pass** |
| 2 — `getQualifiedClassName` family | `get_qualified_class_name`, `get_qualified_super_class_name` | 2 × pass | **2 × pass** |
| 3 — `flash.events` behaviour (the `is_iface_alias` blast radius) | `event_clone`, `event_formattostring`, `event_valueof_tostring`, `eventdispatcher_dispatchevent`, `eventdispatcher_interface_invoke`, `eventdispatcher_tostring`, `eventdispatcher_willtrigger`, `mouseevent_constr`, `mouseevent_valueof_tostring`, `timer_events`, `uncaught_error_basic` | 11 × pass | **11 × pass** |
| 3 — the `ruffle_matched` pins (per `ruffle-matched-hides-regression`) | `avm2/uncaught_errors_stringified`, `from_avmplus/regress/bug_539328` (the interface-describeType pin) | 2 × ruffle_matched | **2 × ruffle_matched** (no drift) |
| 4 — class-registration blast radius | `abstract_classes` | pass | **pass** |
| 4 — the one test that names a newly-registered class | `stage_display_state` | output_mismatch | **output_mismatch** (unchanged; see below) |
| 5 — AVM2 general | `from_avmplus/as3/Definitions/Classes/ClassDef/DefaultClass`, `from_avmplus/ecma3/Types/e8_2` | 2 × pass | **2 × pass** |

`eventdispatcher_interface_invoke` is the tier-3 row that would have caught
`is_iface_alias = 1` breaking dispatch (it calls the five methods through an
`IEventDispatcher`-typed reference); `bug_539328` is the one that would have
caught the `uri` change leaking into an implementing class's report. Both green.

**`stage_display_state` (the `w2-matrix3d-classes` T7 target), re-measured
after this patch:** still `output_mismatch`, still **zero actual lines** — the
6 expected lines are `FullScreenEvent.fullScreen - unimplemented` /
`.interactive - unimplemented` / `OnFullScreen displayState = …`. So
registering the class did **not** unblock it: what it still needs is
`FullScreenEvent.FULL_SCREEN` as a *real* constant (my shells carry constants
describe-only, §6) and a `stage.displayState` setter that dispatches. That is
useful negative information for T7 — the `#1065` on the class name was not the
only blocker.

**Canary blind spot.** This patch is trace-only: it touches no renderer path
and has zero pixel-axis effect, so the standing `render_canary.py` set does not
exercise it and was not run. Tiers 1–3 above are the covering grade.

**All five headline rows were re-verified on the FINAL tree** (after a
type-scope cleanup that moved `struct EventShell` inside its function), run
sequentially with `--recompile`: **5/5 PASS.**

---

## 7b. Residual mechanisms (all outside the graded axis, each with a completion mechanism)

| residual | why it is out of scope here | completion mechanism |
|---|---|---|
| The 45 shells carry their **199 constants describe-only** — `ActivityEvent.ACTIVITY` is `undefined` at runtime | the fixtures grade `describeType`, not property reads; the 14 `flash.display` shells make the same trade and no corpus test reads one (`gaterisk.py` sweep) | the generator already parses `mem.value`; emit a `{name, value}` table and call `avm2_builtin_add_static_const` in the shell loop. Worth **0 graded flips** until a test reads one — do it when one appears, not speculatively. |
| The 45 shells have **no behaviour** beyond their base's constructor (no per-class `clone`/`toString` override, no accessors backed by storage) | Flash's `SyncEvent.toString()` prints its own field list; nothing in the corpus dispatches one | a real class body per shell, i.e. the `avm2_events.c` treatment. Trigger: a graded row that constructs one and prints it. |
| `all_classes/accessibility/swf9` still reports **2 model "mismatches"** in `check_model.py` (`ISearchableText` / `ISimpleTextSelection` "absent from expected file entirely") | pre-existing, and it is a FIXTURE property: the swf9 oracle omits two classes the shared `Test.as` walks. The row `pass`es. | none needed; it is not a model defect. Do not chase it. |
| The five rows sit in `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:99-103` | they were ignore-listed while failing; they pass now, so the *filtered* rate does not move | prune those five lines (owner: `w2-tooling-hygiene`). |

## 8. Reproduction

```bash
cd <worktree>
export DAWN_INSTALL=$HOME/CC/dawn-install
export SWFRECOMP_COMPILE_TIMEOUT=2400

# free acceptance test, no build:
python3 tools/descriptor/check_model.py \
    ruffle-tests/tests/swfs/avm2/all_classes/events flash.events   # -> 0
python3 tools/descriptor/check_model.py \
    ruffle-tests/tests/swfs/avm2/all_classes/display flash.display # -> 0

# regenerate the block (needs a BASELINE capture — one taken with the block
# between the markers emptied, or predating this patch):
python3 tools/descriptor/gen_display_descriptors.py --pkg flash.events \
    --actual <a baseline all_classes/events/swf30 --save-actual capture>

# a row:
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
    --test=all_classes/events/swf30 --mode=graphics --recompile --verbose
```

Scratch (not committed):
`/tmp/claude-1000/.../scratchpad/w2events/{gaterisk.py,mkreg.py,vis.py,baseline.py,run_canaries.sh,canaries.txt}`.

---

## 9. Board update for `polish-sweep-arc.md` §17.4

> **`all_classes/events`: DONE, +5 (s17 w2). §17.4's "0 flips" and the s17
> board's own "real +3" are both REFUTED — the ceiling landed.** All five rows
> pass; `all_classes` is now 26/26 across seven packages. Derived, not
> transcribed, by the same `tools/descriptor/` generator that landed
> `flash.display` in s16, now **package-parameterised** (`--pkg`, one marker
> pair + symbol prefix + ROWS macro per package). The 95 element mismatches
> the s17 board measured were 1 mechanism (interface members carry
> `uri="<pkg>:<Interface>"`), 5 adjudications (AIR-only trailing constructor
> parameters on `KeyboardEvent`/`FocusEvent`/`GestureEvent`/
> `PressAndTapGestureEvent`/`TransformGestureEvent` — `MouseEvent` and
> `TouchEvent` were named by s16 and do NOT diverge) and 1 parser bug (an
> untyped `public static const` was dropped; Flash reports `type="*"`). The
> 731-line pin was 45 missing classes, 483 missing member rows, 65 wrong
> `declaredBy`s and two real runtime bugs: `EventDispatcher` reported its five
> interface methods twice (the manual alias loop never set `is_iface_alias`,
> and `HIDE_NSURI_METHODS` hid the duplicate on every subclass but not on the
> one class whose superclass is `Object`), and `TouchEvent` was exposed at
> SWF 9 against `[API("667")]`. Class gates are proven harmless corpus-wide:
> **0 at-risk (test, class) pairs**. Residual: the 45 shells report their 199
> constants describe-only, so `ActivityEvent.ACTIVITY` is still `undefined` at
> runtime — a mechanical follow-on, worth 0 graded flips today.
