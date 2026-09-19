# w1-avm1-globals — session 20 wave-1 (READ-ONLY) report

**Agent:** `w1-avm1-globals` · **Scope:** the 6 `avm1` globals/prototype-declaration rows
· **Mode:** no-graphics (mode parity holds — every per-test line triple I measured reproduces
the wave-0 graphics inventory exactly) · **Source edits made: none.**

---

## 0. Verdicts and priced flips (read this first)

| # | Test | Verdict | Priced flip | Cost / blocker |
|---|---|---|---|---|
| **G1** | `avm1/global_instance_decls` → **`ruffle_matched`** | **GO (medium-large), conditional** | **+1 effective** | **One dominant lever (§3.B) covers ~60 of the ~90 surplus/missing lines**, plus a 1-line flag fix (§3.A) and **8 residual blocks** (§3.C). 80 blocks, 41 with a line-count delta. Realistically a full wave-2 session for +1. The *only* row in this family where the ours-only indices resolve into a closed, enumerable defect set. |
| **H1** | `avm1/global_proto_decls_delete` → `ruffle_matched` | **HOLD (one mechanism, large surface)** | 0 now, +1 later | 20 ours-only indices, **all 20 desync artifacts** of one real gap: `__proto__`, `constructor` and the 9 `Object.prototype` methods lack `DONT_DELETE` — **1 088 of 1 302** property-level diffs. Mechanism A + the `Object.prototype` flag stamp (§4). Must land *whole* plus H2's ordering before the file re-aligns. |
| **H2** | `avm1/global_proto_decls` → `ruffle_matched` | **HOLD (three mechanisms, ordering-bound)** | 0 now | 23 ours-only indices, again all desync. Real gaps: (i) **array `for-in` never walks the `__proto__` chain** (529 expected lines, 11.8 %), (ii) own `toString` on broadcaster singletons Flash inherits, (iii) **own-property enumeration order**. (iii) is the completion blocker and is not mechanical. |
| **N1** | `avm1/globals_swf5` | **NO-GO — verdict survives, the stated reason does not** | 0 (would be +1 at the cost of **3 Flash-correct `pass` regressions**) | 9 of 10 diff lines are the deliberate SWF5 hiding of `LocalConnection`/`NetConnection`/`Video`. Upstream ships **two contradictory Flash captures** (§5.1). Chasing it demotes `from_gnash/actionscript.all/{LocalConnection,NetConnection,Video}-v5` from `pass` — a rule-3 regression. |
| **N2** | `avm1/native_objects_swf6` | **NO-GO — disposition confirmed intact** | 0 | Exactly **1** diff line = the `ACCEPTED_DIFFS.md` `new TextField()` entry. `ruffle_matched` unreachable (Ruffle's 20 diff indices do not contain ours), and adopting Ruffle's `undefined` breaks `textfield_props_swf6` + `toString_valueOf-v6`. |
| **N3** | `avm1/globals_monkeypatch` | **NO-GO (arc) — re-confirmed, drifted AGAIN** | 0 | s19 §N3 stands. Expected grew **100 (s18) → 228 (s19) → 246 (s20)**; we emit 158, 39 match, **198 ours-only**. A `_global`-indirection arc, **not** part of this cluster. |

**Priced wave-2 yield from this family: +1 effective, and it costs a full session.** If the
coordinator has a cheaper board elsewhere, take that instead; the durable value here is §3.A
and §5, which are correctness/documentation debt rather than flips.

---

## 1. The brief's premise, measured

> *"…one shared surface: what properties exist on `_global` and on each built-in's prototype…
> mechanical, high-line-count, and exactly the sort of thing one wave-2 agent can close."*

**Half true; the mechanical half is much smaller than the name stem suggests, and "one wave-2
agent, one session" holds for at most one row.**

- There **is** one genuinely shared surface, and it is a **flag**, not an inventory:
  **`DONT_DELETE` (= `PROPERTY_FLAG_CONFIGURABLE` cleared) is missing on `__proto__`,
  `constructor`, and built-in prototype methods.** It drives `global_instance_decls`
  (25 of 80 blocks differ by *exactly* that one line) and `global_proto_decls_delete`
  (1 088 of 1 302 property diffs).
- `global_proto_decls` **does not report `DONT_DELETE` at all** — its `testDecls` reports only
  `own` / `DONT_ENUM` / `READ_ONLY`. Its residual is **prototype-chain enumeration + ordering**,
  a different mechanism from its own name-stem sibling. The cluster head does not cover it.
- `globals_monkeypatch` is **re-assignment / `_global` indirection** (`Object = 5`,
  `delete Object`, `flash.geom.*` resolved through user getters). Zero overlap — the brief's
  suspicion that it is a different mechanism is **correct**.
- `globals_swf5` is a **version-gate** question with a contradictory oracle, not an inventory one.
- `native_objects_swf6`: memory `native-objects-swf6-asarray-super` records a **segfault fixed
  2026-05-29**, not the live residual. The live residual is the 1-line `ACCEPTED_DIFFS.md` entry.

So the cluster is **2 rows**, not 5 or 6.

---

## 2. The re-pricing that matters — and the trap inside it

The wave-0 inventory prices this family at ~10 500 differing lines. That number is
**positional** (`verify_output.py::_diff_indices` compares line index *i* to index *i*), so one
extra or missing line poisons the whole tail.

All six rows are `known_failure = true` **with** an `output.ruffle.txt`, so the reachable grade
is `ruffle_matched`, awarded when **our** differing-index set is a **subset** of **Ruffle's**
(`verify_output.py:3506-3514`). Measured (`<scratchpad>/w1-avm1-globals/idx.py`, which imports
verify_output's own functions):

| test | our diff idx | Ruffle diff idx | **ours-only** | subset? |
|---|---|---|---|---|
| `global_instance_decls` | 760 | 767 | **27** | no |
| `global_proto_decls_delete` | 3 697 | 4 103 | **20** | no |
| `global_proto_decls` | 3 694 | 4 347 | **23** | no |
| `native_objects_swf6` | 1 | 20 | **1** | no |
| `globals_swf5` | 10 | 2 | **9** | no |
| `globals_monkeypatch` | 207 | 9 | **198** | no |

**Refuting my own re-pricing — read this before quoting the table.** I inspected the *content*
at every ours-only index (`<scratchpad>/w1-avm1-globals/show.py`). For
`global_proto_decls_delete` **all 20** and for `global_proto_decls` **all 23** are
**coincidental alignments**: Ruffle happens to match Flash at a `__proto__, own` /
`constructor, own` line and our output happens to be desynced there. They are not 20/23
independent bugs and cannot be picked off one at a time.

`global_instance_decls` is only *better*, not *free*: of its 27, four (indices 1, 725, 728, 731)
are the literal `__proto__ … DONT_DELETE` defect at positions where alignment survives; the
other 23 are also offset artifacts. What makes it the one GO is that its **block structure is
already aligned** — 80 `_global.X` blocks on both sides, same names, same order, none missing —
so the offsets are produced by a *closed, enumerable* set of 41 per-block line-count deltas
(§3), not by an open-ended walk divergence.

Every fix below moves us **toward `output.txt` (Flash)**, never toward `output.ruffle.txt`. No
`pass → ruffle_matched` move is proposed anywhere (rule 3).

---

## 3. G1 — `global_instance_decls`: cold-start plan

Baseline `26/758 matched, 786 actual`. 80 blocks each side, same order. 4 blocks byte-identical,
**25 differ by exactly the string `, DONT_DELETE`**, 41 have a line-count delta. Cumulative
offset walks +0 → +25 → −19 → +28 (full table:
`<scratchpad>/w1-avm1-globals/` re-run of the block-delta snippet in §6).

### A. `__proto__` is deletable everywhere — the 1-line flag fix

```
EXP:   __proto__, own, DONT_DELETE, type=[object]
OURS:  __proto__, own, type=[object]
```
25 blocks have this and nothing else wrong: `TextSnapshot`,
`flash.automation.ActionGenerator`, `flash.external.ExternalInterface`, `flash.geom.Matrix`,
`flash.geom.Point`, `flash.geom.Rectangle`, `flash.filters.BitmapFilter`,
`System.security.PolicyFileResolver`, `System.security.__constructor__`, `Video`,
`clearRequestHeaders`, `addRequestHeader`, `RemoteLSOUsage`, `AssetCache`, `AsSetupError`,
`ContextMenu`, `ContextMenuItem`, `SharedObject`, `Microphone`, `Camera`, `NetStream`,
`AsBroadcaster`, `MovieClip`, `Function`, `Object`. **It changes no line counts**, so it is
offset-neutral and safe to land first.

**Where.** `__proto__` is written from ~40 sites (`grep -n '"__proto__"'
SWFModernRuntime/src/actionmodern/action.c` → 217 hits), mostly plain `setProperty(...)`, some
`PROPERTY_FLAGS_DONTENUM` — **both include `PROPERTY_FLAG_CONFIGURABLE`**, i.e. deletable. Do
not patch call sites. There is already a name-keyed choke point:

`SWFModernRuntime/src/actionmodern/object.c:1075-1084`
```c
	obj->properties[index].flags = PROPERTY_FLAGS_DEFAULT;

	// __proto__ and constructor are DontEnum (not enumerable in for-in)
	if ((name_length == 9 && strncmp(name, "__proto__", 9) == 0) ||
	    (name_length == 11 && strncmp(name, "constructor", 11) == 0))
	{
		obj->properties[index].flags &= ~PROPERTY_FLAG_ENUMERABLE;
	}
```
Add `&= ~PROPERTY_FLAG_CONFIGURABLE` in that arm. Flash marks **both** names `DONT_DELETE` —
`global_proto_decls_delete/output.txt` reports `__proto__, DONT_DELETE` 158× and
`constructor, DONT_DELETE` 192×.

⚠ **One line is not enough.** `setPropertyWithFlags` (`object.c:1150-1162`) creates the
property via `setProperty` and then **overwrites** `new_prop->flags = flags`, so every
`setPropertyWithFlags(..., "__proto__", ...)` caller would undo the choke point. The patch is
**two** places: `object.c:1080` *and* a guard on that override. `deleteProperty`
(`object.c:1184`) already honours the flag, and `ASSetPropFlags` maps Flash bit 2 ↔
`PROPERTY_FLAG_CONFIGURABLE` in both directions (`action.c:5444-5447`), so script can still
clear it — which is correct.

**Risk:** universal path. `makeProtoReadOnly` (`action.c:8255`) and `fixBuiltinPrototypeFlags`
(`action.c:8277`) already do exactly this for singletons and built-in prototypes, so the change
widens an existing convention rather than inventing one. Sweep avm1 + from_gnash + `regression`
for anything relying on `delete x.__proto__` succeeding.

### B. The dominant lever — 32 blocks expose an own `__proto__`/`__constructor__` Flash does not

Measured: **32 blocks** where our body contains an own `__proto__` and the Flash capture
contains none at all; **28** likewise for `__constructor__`. Examples:

```
EXP  _global.flash.filters.BlurFilter : blurX … | blurY … | quality … | clone …
OURS _global.flash.filters.BlurFilter : __proto__, own | __constructor__, own | blurX … | …

EXP  _global.MovieClipLoader          : (empty — the instance enumerates nothing)
OURS _global.MovieClipLoader          : __proto__, own | __constructor__, own | _listeners, own, DONT_ENUM
```

That is **+2 lines in ~20 blocks** (`MovieClipLoader`, `LocalConnection`, `textRenderer`,
`StageCapture`, `flash.geom.Transform`, `ColorTransform`, all 9 concrete `flash.filters.*`,
`TextRenderer`, `Sound`, `Array`, `String`, `Boolean`, `Number`, `LoadVars`, `NetConnection`…)
and is the single largest term in the offset budget — ~60 of the ~90 mis-placed lines.

Note the tension with §3.A, which a wave-2 agent **must** resolve before coding: 25 *other*
classes (`TextSnapshot`, `Matrix`, `Point`, `Rectangle`, `ContextMenu`, `MovieClip`, `Object`,
`Function`, …) **do** show `__proto__, own, DONT_DELETE`. So the rule is per-class, not global.
The empirical split: classes whose expected body reports `DONT_DELETE` on *prototype-level*
props (`ColorTransform`, the filters, `BitmapData`) or reports nothing at all are exactly the
ones with no own `__proto__`. Working hypothesis (**unverified — verify before implementing**):
for those classes Flash's instance `__proto__`/`__constructor__` are internal slots rather than
properties, so `ASSetPropFlags(instance, null, 0, 1)` cannot unhide them. The oracle to settle
it is `~/CC/ruffle/core/src/avm1/globals/` per class (which of them define `__proto__` via
`Object::set_proto` vs. as a declared property).

### C. The residual 8 blocks (everything else with a nonzero delta)

| block | Δ | what |
|---|---|---|
| `_global.Date` | **+40** | Flash's `new Date()` instance enumerates **nothing**; we emit 40 prototype methods. Largest single delta. |
| `_global.flash.display.BitmapData` (2nd) | **−28** | `new BitmapData()` (no args) returns `undefined` for us; Flash returns a live object with 28 props. |
| `_global.XMLNode` (1st) / `_global.XML` (1st) | −13 / −17 | missing instance properties on the no-arg constructions. |
| `_global.Button` | +10 | 10 surplus lines. |
| `_global.flash.net.FileReference` / `…List` | −6 / −2 | `name/type/size/modificationDate/creationDate/creator/postData/_listeners` never installed. |
| `_global.PrintJob` | −3 | `paperHeight/paperWidth/pageHeight/pageWidth/orientation` never installed. |
| `_global.Error` | −3 | `new Error()` must `toString()` as `Error`; ours is `[object Object]`. |
| `System.Product`, `TextFormat`, `TextField`, `Color`, `XMLSocket`, `NetConnection` | ±1–2 | one-liners. |

Also present but **not** an ours-only index and therefore not a blocker for `ruffle_matched`:
`_global.Date, instance=[… GMT-0700 …]` vs our `GMT+0545` (the Flash capture machine's timezone
vs our `MOCK_DATE_TIME` NPT — belongs in `ACCEPTED_DIFFS.md` beside the existing
`native_subclasses` Date-timezone entry if anyone ever chases an exact `pass`), and Flash's
own-property enumeration order on `Matrix` instances, which is **`d, a, c, b, ty, tx`** — not
insertion order, and we emit `a, b, c, d, tx, ty`.

**Retracted.** An earlier draft of this report claimed "no-arg `new flash.geom.Matrix()` creates
6 own fields Flash does not, producing the 19-index run 99…117". That is **wrong** — I checked
`matrixConstructor` (`action.c:10523-10549`) and the expected text: the Matrix blocks are
structurally identical and the 19-index run is a cumulative-offset artifact from the
`ColorTransform`/`Transform` blocks before it. Mechanism B above replaces it.

**Sites for C:** `action.c:10523` (`matrixConstructor`), `action.c:42150-42200`
(`flash.geom`/`flash.filters` registration, incl. `fc_Matrix`), `action.c:42389-42480` (filter
property block — note `fp->properties[j].flags |= PROPERTY_FLAG_CONFIGURABLE` at 42477 is
actively *granting* deletability), `action.c:57688` (Error), `57725/57738` (String), `57812`
(Number), `57869` (Boolean), `date.c:687`.

---

## 4. H1 / H2 — why the big siblings are HOLDs, and what completes them

### H1 `global_proto_decls_delete` — one mechanism, must land whole

`test.as` is a pure **delete-semantics** probe: `ASSetPropFlags(obj, null, 0, 1)`, then for each
key `delete obj[key]` and re-enumerate; survivors print `  <name>, DONT_DELETE`. The file is
nothing but a `DONT_DELETE` census, and 2 371 vs 4 158 lines is one number: how many properties
we let script delete that Flash does not.

Census over the 189 common blocks (`setcmp.py global_proto_decls_delete`):

| missing `DONT_DELETE` on | count |
|---|---|
| `constructor` | 192 |
| `__proto__` | 158 |
| each of `watch`, `unwatch`, `addProperty`, `valueOf`, `toString`, `hasOwnProperty`, `isPrototypeOf`, `isPropertyEnumerable`, `toLocaleString` | 82 each (**738**) |
| `prototype` | 14 |
| tail (`_listeners`, `registerClass`, `getDepth`, TextField methods, `System.*`…) | ~60 |

**1 088 of 1 302** are the first three rows. §3.A covers `constructor` + `__proto__` (350). The
738 are the **`Object.prototype` builtin methods**, and their stamp site is exact:

`SWFModernRuntime/src/actionmodern/action.c:8217-8219`
```c
		// Mark all built-in Object.prototype properties as non-enumerable (DontEnum)
		for (u32 i = 0; i < g_object_prototype->num_used; i++)
			g_object_prototype->properties[i].flags &= ~PROPERTY_FLAG_ENUMERABLE;
```
Adding `& ~PROPERTY_FLAG_CONFIGURABLE` to that same loop is the whole second half.

**Completion mechanism / why HOLD:** even with all 1 088, we go 2 371 → ~3 459 against 4 158,
and the grade is positional, so the remaining ~700 (ordering, plus the `_listeners`
prototype-chain walk of H2 — **529 of this file's lines** are inside `_listeners`-rooted blocks)
must land too. Treat as a **2-slice arc**: slice 1 = §3.A + the `action.c:8217` loop (safe,
mechanical, and it is a prerequisite of G1 anyway); slice 2 = H2's mechanisms. Do **not** hand a
wave-2 agent H1 as a flip.

### H2 `global_proto_decls` — three mechanisms, ordering is the blocker

455 expected headers, 410 ours, 400 common, **324 of the 400 common blocks byte-identical**.

**(i) Array `for-in` never walks the prototype chain — 529 expected lines (11.8 %).**
`_global.Stage._listeners` is an `ASArray`; Flash enumerates the 9 `Object.prototype` methods
(unhidden earlier in the same walk) plus an own `constructor`, then recurses into each. We emit
an empty block and skip all 10 sub-blocks. Same for `Key`, `Mouse`, `Selection`, `System.IME` —
**45 missing headers**.
**Exact site:** the array arm of the `for-in` walker,
`SWFModernRuntime/src/actionmodern/action.c:49000-49025` — it iterates `arr` elements and
`arr->props` own slots, explicitly `continue`s on `__proto__` (49006-49007), and never follows
it. The `ActionEnumerate` twin is at `action.c:33980-33995`.
**Risk: very high blast radius** — this changes `for-in` over *every* array. Usually invisible
(`Array.prototype`/`Object.prototype` members are `DONT_ENUM`), but the `arguments` object is an
`ASArray` protected by `PROPERTY_FLAG_PERM_DONTENUM` (`object.h:42`, gnash
`Function.as:487-500`), and that protection lives on `arr->props` slots — it would **not** cover
inherited slots reached through a new chain walk.

**(ii) Broadcaster singletons carry an own `toString` Flash inherits** (12 `FLAGS:toString`).
Expected `_global.Stage` lists `toString, type=[function]` inside the inherited
`Object.prototype` run; ours lists `toString, own, …` at the end. Sites: the
`AsBroadcaster`/singleton initialisers near `action.c:38749` and `42797` (`STAGE_RO`). Removing
the own slot also removes our 6 bogus `_global.X.toString.prototype` blocks.

**(iii) Own-property registration ORDER.** Expected `_global.Stage`:
`_listeners, removeListener, addListener, broadcastMessage, wmodeGPU, fullScreenWidth,
fullScreenHeight, fullScreenSourceRect, displayState, showMenu, width, height, scaleMode,
align, __proto__, constructor`. Ours: `fullScreenSourceRect, wmodeGPU, fullScreenWidth,
fullScreenHeight, showMenu, displayState, width, height, scaleMode, align, broadcastMessage,
removeListener, addListener, _listeners, toString, __proto__`. Same set, different insertion
order; 17 blocks are same-set-different-order, and the `Matrix` instance order noted in §3.C
(`d, a, c, b, ty, tx`) shows Flash's order is not always insertion order at all.
**This is the completion blocker**: per-class, invisible to every other test, and because the
grade is positional, (i) and (ii) without (iii) buy nothing.

**Completion mechanism for H2:** a dedicated `_global` surface-ordering pass, sequenced after
H1 slice 1. Not a wave-2 slice this session.

---

## 5. Refutations (the deliverable the brief asked for)

**5.1 "`globals_swf5` is a settled Ruffle-vs-Flash difference confirmed by the Gnash tests."**
*Refuted as stated; the NO-GO survives, the reasoning does not.* Upstream ships **two
contradictory Flash captures** for the same question:

- `avm1/globals_swf5/output.txt` expects `LocalConnection` = `[type Function]` in SWF5, and
  `output.ruffle.txt` differs from it at **only 2** indices (15 and 135) — so **Ruffle matches
  Flash here**, and the "Ruffle exposes them, Flash hides them" framing in
  `ruffle-tests/ignored_tests.txt:186` and `RUFFLE_VS_FLASH_DIFFERENCES.md:154-175` is backwards
  *for this file*.
- `from_gnash/actionscript.all/{LocalConnection,NetConnection,Video}-v5/output.txt` expects
  `PASSED: … == undefined`, and their `output.ruffle.txt` records Ruffle **FAILING** with
  `obtained: [type Function]`. All three are **`pass`** for us today
  (`from_gnash/actionscript.all/_results/results_graphics.json` @ `2973513c4`).

Upstream `tests/README.md:50-66` is explicit that `output.txt` is the expected/Flash output and
`output.ruffle.txt` is Ruffle's own snapshot for known-failures — so this is an **upstream
oracle conflict**, most plausibly two different Flash Player builds. **Decision unchanged
(NO-GO)**: chasing `globals_swf5` costs 3 Flash-correct `pass` rows for +1. But the RVF entry
and the ignore-list comment should be rewritten to say *"two upstream Flash captures disagree;
we follow the Gnash one because it is the one we can pass"* rather than *"Ruffle is wrong"*.
**Separable and free of the conflict:** `globals_swf5` line 136 — `TextField.prototype` must be
`undefined` in SWF5 (expected `undefined`, Ruffle `object`, ours `object`). Flash-correct, flips
nothing alone.

**5.2 "The `global_*_decls` tests are validated against Flash-correct output via
`--expected-suffix=flash` instead."** (`ruffle-tests/ignored_tests.txt:190`) — **false today.**
`ruffle-tests/tests/swfs/avm1/_results/results_flash.json` (run at `317ac43cf`, 2026-09-17) is
**0 pass / 3 fail**: `global_instance_decls` 442/853, `global_proto_decls` 1400/3714,
`global_proto_decls_delete` 338/874. The three `output.flash.txt` files are hand-made and last
touched **2026-04-13**; `global_proto_decls_delete/output.flash.txt` is 874 lines against
upstream's 4 158. The side-channel is not a safety net and must not be cited as one. (It *is*
still wired into CI — `.github/workflows/ruffle-tests.yml:1247-1255`.)

**5.3 "`RUFFLE_VS_FLASH_DIFFERENCES.md` §'Object.prototype Methods ENUMERABLE by Default'
explains ~3 700 lines of `global_proto_decls` and ~3 870 of `global_proto_decls_delete`."** —
**not a blocker, and its polarity is questionable.** Both tests call
`ASSetPropFlags(object, null, 0, 1)` *before* enumerating, which clears `DONT_ENUM`; the
`DONT_ENUM` label is derived from a **pre-clear** enumeration. Because the recursive walk visits
`_global.Object.prototype` early and clears its flags process-wide, later blocks legitimately
show those 9 methods as enumerable in **Flash's own capture** — that is not a Ruffle artefact.
More decisively, the entry is irrelevant to the reachable grade: Ruffle diverges from Flash at
4 347 / 4 103 indices in these files, so none of those positions constrains `ruffle_matched`.
The blockers are the 20/23 ours-only indices and the mechanisms behind them. The entry should be
down-scoped to a note, not left standing as a ~7 500-line "permanent difference".

**5.4 "`native_objects_swf6`'s live mechanism is memory `native-objects-swf6-asarray-super`."**
— **stale.** That note records a graphics-mode segfault (ASArray-as-ASObject confusion in
`super()` over an array receiver), fixed 2026-05-29. The live residual is exactly **1** line —
the `ACCEPTED_DIFFS.md` `new TextField()` entry — and the row is 114/115. Nothing has moved.

**5.5 "27 / 20 / 23 ours-only lines means three cheap flips."** — **self-refuted, deliberately**
(§2). Only `global_instance_decls` resolves into real defects, and even there only 4 of 27 are
direct; the rest are offset artifacts closed by §3.B/§3.C. A wave-2 agent that reads only the
ours-only counts will burn a session for nothing.

**5.6 Upstream drift (rule 13), not regression.** `globals_monkeypatch` expected lines went
**100 (s18) → 228 (s19) → 246 (s20)** while our actual went 96 → 144 → 158 — three successive
upstream expansions of the same test. The other five rows' expected totals are unchanged since
s18 (`global_proto_decls` 4497, `global_instance_decls` 758). Do not book any of this as
movement.

---

## 6. Evidence — what I ran

No-graphics, sequential (`-P 1`), `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose`, `--test=NAME`
against the default `avm1` dir. Every line triple reproduces the wave-0 graphics inventory
exactly, so no mode-parity or drift question arises in this family.

| test | result | matched / expected / actual | inventory |
|---|---|---|---|
| `globals_swf5` | MISMATCH | 294 / 304 / 304 | ✓ |
| `native_objects_swf6` | MISMATCH | 114 / 115 / 115 | ✓ |
| `globals_monkeypatch` | MISMATCH | 39 / 246 / 158 | ✓ |
| `global_instance_decls` | MISMATCH | 26 / 758 / 786 | ✓ |
| `global_proto_decls_delete` | MISMATCH | 461 / 4158 / 2371 | ✓ |
| `global_proto_decls` | MISMATCH | 803 / 4497 / 3863 | ✓ |

Scripts + saved actual outputs (read-only scratch, agent-namespaced):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/2a334c23-46d3-40fc-a8f1-a77489de0fb1/scratchpad/w1-avm1-globals/`
— `idx.py` (ours-vs-Ruffle diff-index sets via verify_output's own
`_diff_indices`/`ruffle_subset_match`), `show.py` (content at each ours-only index),
`setcmp.py` / `setcmp2.py` (block- and class-keyed property census), `b1.py` (the
`DONT_DELETE`-only block isolation), `blockdiff.py`, `run.sh`/`run2.sh`, `*.actual.txt`.

Disposition check (rule 2) — grepped all four docs and both ignore lists for all six names:
- `ruffle-tests/ignored_tests.txt`: `globals_swf5` (186-188); `global_proto_decls`,
  `global_proto_decls_delete`, `global_instance_decls` (190-194); `native_objects_swf6` (207).
  **`globals_monkeypatch` is NOT ignored.** There is no per-suite `avm1/ignored_tests.txt`.
- `ACCEPTED_DIFFS.md:82-112` + summary row 1255 — `native_objects_swf6`, 1 line, still valid.
- `RUFFLE_VS_FLASH_DIFFERENCES.md:29-42`, `:125-152`, `:154-175` — see §5.1 and §5.3.
- `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`: no hits for any of the six.

Prior work honoured: s19 `w1-avm1-builtins-report.md` §N3 (`globals_monkeypatch`) — not re-run
beyond confirming drift; `net-socket-arc.md:329, 764, 786, 990` (the `global_instance_decls`
`__proto__`/`PrintJob` observation) — superseded here by the full 80-block census and a located
choke point.

---

## 7. Cross-agent warning

`net-socket-arc.md` records that `global_proto_decls{,_delete}` and `global_instance_decls`
**enumerate** `LocalConnection`, `NetConnection`, `XMLSocket`, `SharedObject`,
`flash.net.FileReference(List)`, `flash.geom.*`, `flash.filters.*` and `System.*`. Any wave-2
agent touching those prototypes moves these three rows' line counts as a side effect, and
because the rows are graded positionally such a change can flip an ours-only index either way
**without touching the mechanism**. Anyone landing a net/socket/geom/filter surface change this
session should re-run these three tests and quote the new ours-only counts, not just pass/fail.

Files a G1/H1 wave-2 agent would touch: `SWFModernRuntime/src/actionmodern/object.c`
(~1080 **and** ~1150) and `SWFModernRuntime/src/actionmodern/action.c`
(~8217, ~10523, ~42150-42200, ~42389-42480, ~57688-57880), plus
`SWFModernRuntime/src/actionmodern/date.c:687`. `object.c:1080` and `object.c:1150` are
**universal** property paths — coordinate before editing them.

---

## 8. New unclaimed leads

1. **`__proto__`/`constructor` are deletable on every object we mint** (§3.A). Beyond these
   tests this is a real semantic gap — `delete o.__proto__` should return `false` and leave the
   chain intact. No `regression/` fixture covers it; a 3-line fixture (oracle: the Ruffle
   exporter) would be cheap and would protect the choke point.
2. **`ASArray` `for-in` does not walk the prototype chain** (`action.c:49000-49025`,
   `33980-33995`). A standalone AVM1 correctness bug larger than this family: any script that
   puts an enumerable property on `Array.prototype` and iterates an array with `for-in` sees
   nothing. Deserves its own investigation + fixture before anyone attempts H2.
3. **`flash.filters.*` no-arg constructors leave every field `undefined`** where Flash installs
   documented defaults (`distance=4, angle=45, alpha=1, blurX=blurY=4, quality=1, strength=1`…).
   ~110 lines here, and likely observable in real content that reads a filter field before
   setting it.
4. **`new String()` / `new Number()` / `new Boolean()` / `new Error()` with no arguments** give
   `undefined`-valued wrappers (`[]`, `0`, `false`, `Error` expected). Small and self-contained.
5. **`new flash.display.BitmapData()` (no args) returns `undefined`** where Flash returns a live
   object with 28 properties (28 lines here).
6. **`new Date()`'s instance enumerates 40 prototype methods for us and nothing for Flash**
   (+40, the largest single block delta in `global_instance_decls`). Suggests our `Date`
   instances carry own copies of the prototype methods, or our `hasOwnProperty`/enumeration
   treats the Date prototype as own. Worth a 10-minute probe regardless of the flip.
7. **The stale `--expected-suffix=flash` channel** (§5.2). Three `output.flash.txt` files from
   2026-04-13 grade 0/3 and are cited in `ignored_tests.txt` as a safety net. Either regenerate
   them from the current upstream `output.txt` minus documented divergences, or retire the
   channel and the CI step at `.github/workflows/ruffle-tests.yml:1247-1255`. Not my call.
8. **`globals_swf5` line 136** — `TextField.prototype` must be `undefined` in SWF5 (§5.1).
