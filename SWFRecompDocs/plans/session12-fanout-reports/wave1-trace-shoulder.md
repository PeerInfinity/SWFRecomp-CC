# Wave-1 trace-axis: the "gap 6–10 shoulder" — session 12

Read-only. No source edits, no git state changes, no CI. Scratch:
`scratchpad/{shoulder.py, allfail.json, classes.txt, jobs*.txt, out/*.txt}`.

Data: the 19 top-level leaf `results_graphics.json` (the 5 nested `_results`
excluded as double-counts). All 19 carry `git_sha = 6de65043250d…` — the s11
final **code** commit; `f166e424e` (HEAD) is the docs closeout and touches no
source, so the board below is HEAD. Unfiltered totals: 4427 rows,
`pass 3946 + ruffle_matched 249`, **223 non-`pass`/`ruffle_matched`**
(`output_mismatch 222`, `runtime_error 1`, `recomp_fail 0`).

**Every one of the 22 live shoulder rows was re-run locally at HEAD**
(`verify_output.py --test=… --diff --verbose`, no-graphics, `-P 2`). All 22
still fail, all with the line counts the CI board predicts. Three
out-of-band siblings were also run (`large_preload_from_url`,
`large_preload_from_bytes`) to test a cluster hypothesis.

---

## 1. The board

Gap = `expected_lines − matching_lines` from the merged results.

| band | count |
|---|---|
| ≤ 5 (the "near-pass well") | 38 |
| **6–10 (the shoulder)** | **36** |
| 11–20 | 32 |
| > 20 | 117 |

The brief said ~37; it is **36** at HEAD (s11's count was 37 at `c4496a4c8`).

**14 of the 36 are already dispositioned** and drop out under the ignore
lists (verified by recomputing the band from `results_graphics_filtered.json`,
which is the authoritative filter):

`avm1/{load_vars, movieclip_hittest_shapeflag, watch_recursion_swf7,
loadvariables_method, xml_getbytes, globals_swf5}` ·
`avm2/{stage_scale_factor, netstream_play_stop_replay}` ·
`from_avmplus/ecma3/Statements/eforin_002` ·
`from_gnash/actionscript.all/array-v5` ·
`from_gnash/misc-swfc.all/matrix_accuracy_test1` ·
`from_shumway/fuzz/{438789f3…, e5b0ab65…, 7318344161…}`

→ **live shoulder pool = 22.** By suite: avm2 11 · from_avmplus 4 ·
import_assets 2 · from_shumway 1 · mixed_avm 1 · timeline 1 · visual 1 ·
`from_gnash/misc-ming.all` 1. By VM: **AVM2 17, AVM1 3, dual-VM 2.**

### The 22, with the real (locally re-run) diff shape

| gap | test | one-line mechanism |
|---|---|---|
| 6 | `avm2/error_stack_trace_edge_cases` | `getStackTrace()` must render the **overridden** `Error.prototype.toString` |
| 7 | `avm2/error_stack_trace` | 4 stack-frame **naming** rules (`$cinit`, `MethodInfo-N`, `ns::`, `Class$/`) |
| 6 | `avm2/event_handler_exception` | stack frames need `[file:line]` + a `dispatchEventFunction` frame |
| 6 | `avm2/stage_display_state` | `flash.events.FullScreenEvent` missing → #1065 |
| 7 | `avm2/currency_parse_result` | `flash.globalization.CurrencyParseResult` missing → #1065 |
| 10 | `avm2/netfilterevent` | `flash.events.NetFilterEvent` missing → #1065 |
| 8 | `avm2/id3_info` | `flash.media.ID3Info` + `Sound.id3` + ID3v2 parse |
| 6 | `avm2/large_preload_image_from_bytes` | loader `numChildren` visible one event early + init/complete one frame early |
| 6 | `avm2/sub_super_same_field` | duplicate-name slot traits must be **per-declaring-class** |
| 7 | `avm2/supercalls_coerce` | every `super` probe must land on #1034; we give 5 different codes |
| 8 | `avm2/delayed_symbolclass` | s11 b8b-lazyinit, **already owned + blocked** on frame-1 LAZY |
| 6 | `from_avmplus/ecma3/Expressions/e11_6_1_3` | `Date` default ToPrimitive hint must be **String** |
| 6 | `from_avmplus/ecma3/String/e15_5_4_8_2` | `split(undefined)` must split on the literal `"undefined"` |
| 6 | `from_avmplus/as3/String/localeCompare_585791/v9` | SWF9 `localeCompare(null)` quirk (v12 sibling passes) |
| 8 | `from_avmplus/regress/bug_539328` | `describeType` of an interface's **Class** object |
| 6 | `from_gnash/misc-ming.all/action_order/…_test11` | AVM1 doAction ordering across nested clips |
| 8 | `from_shumway/avm2/…/matrix3d/TransformBasics` | `transform.matrix3D` + `getRelativeMatrix3D` (**`known_failure = true`**) |
| 6 | `import_assets/avm1_imports_avm1` | donor SWF's own frame script must NOT run |
| 6 | `import_assets/avm1_non_swf_import` | non-SWF import must issue + `log_fetch` a GET |
| 6 | `mixed_avm/avm2_loads_avm1_v9` | AVM1Movie content — declared dual-VM arc |
| 10 | `timeline/missing_frame_scripts` | a clip past its last frame keeps re-running frame scripts |
| 6 | `visual/define_bits_jpeg2_huge` | **`uint16_t` truncation of embedded bitmap dimensions** |

---

## 2. PREMISE ATTACK — "gap 6–10" is not a mechanism band ★★

`compare_output` (`ruffle-tests/verify_output.py:3303-3331`) computes

```python
matching = sum(1 for i in range(max_lines)
               if _lines_approx_equal(actual_lines[i], expected_lines[i], …))
```

— a **positional** comparison, not an LCS/edit distance. One inserted or
deleted line near the top therefore drives `matching` toward 0 and inflates
`gap` toward `expected_lines`. The band is an artifact of alignment, not of
semantic distance. Concretely, from the local re-runs:

| test | positional gap | **actual edit distance** |
|---|---|---|
| `import_assets/avm1_imports_avm1` | 6 | **1** (one extra leading line; the 6 expected lines all appear, in order) |
| `avm2/large_preload_image_from_bytes` | 6 | **2** (one wrong `numChildren`, one block moved a frame) |
| `avm2/delayed_symbolclass` | 8 | **2** (two lines emitted 6 lines too early) |
| `import_assets/avm1_non_swf_import` | 6 | **3** (three missing leading `Navigator::fetch` lines) |
| `avm2/event_handler_exception` | 6 | **4** |

Three consequences, all of which matter beyond this board:

1. **The "closed near-pass inventory" is closed only with respect to the
   positional metric.** At least 4 of 22 shoulder rows (18 %) are
   semantically ≤ 3-line diffs that the ≤ 5 window structurally cannot see.
   The s9/s10/s11 "zero refill" invariant is real but it measures a metric,
   not the corpus.
2. **Every future board should carry a second, LCS-based gap column.** It is
   ~10 lines of `difflib.SequenceMatcher` over the saved actual/expected and
   would have surfaced `avm1_imports_avm1` (a 1-line diff) three sessions ago.
3. The inverse also holds — nothing in the shoulder is *cheaper than it
   looks* by more than that; no row in the band turned out to be a
   `> 10`-line mechanism in disguise.

**Second premise, REFUTED: "runtime_error is the cheapest triage axis."**
Confirmed dry for a fourth session — the whole corpus has **one**
`runtime_error` and it is GC-arc-owned. But the axis that replaced it is
extremely cheap and paid immediately here: **stderr `#1065 Variable X is not
defined`** partitions 4 of the 22 in a single pass, and a corpus-wide census
of unresolved `flash.*` imports across all 223 failures (scratch
`classes.txt` vs `avm2_builtin_class(ctx, …)` registrations) closes the
bucket at 7 classes corpus-wide. Recommend this as the s13 step-1 axis.

---

## 3. Clusters

### C1 — Unregistered pure-value / static builtin classes ★ **GO, top pick**

**Members (shoulder):** `avm2/netfilterevent` (gap 10, 10 lines),
`avm2/currency_parse_result` (gap 7, 8 lines).
**Rider (outside the band, same mechanism):** `avm2/flash_trace` (gap 17,
17 lines — one of the 4 new upstream tests from s11 §12.2).
**Same signature but NOT this cluster:** `avm2/id3_info`,
`avm2/stage_display_state` (see §4).

**Mechanism, diagnosed end to end.** All three abort at the first reference
with `ReferenceError: Error #1065: Variable <X> is not defined.` because the
class is simply not in the builtin registry. Each is a *pure* class — no
engine integration:

- `flash.events.NetFilterEvent` — `Test.as` only constructs it directly:
  ctor `(type, bubbles, cancelable, header:ByteArray, data:ByteArray)`, two
  read-only props, `clone()` that must copy the two references by identity
  (`clone.header === a: true`), and a `toString()` that must print the Flash
  quirk `[NetTransformEvent type=… header=… data=…]` — note the class name
  in the string is **NetTransformEvent**, not NetFilterEvent. The existing
  registration idiom is a 25-line block: see
  `SWFModernRuntime/src/avm2/avm2_events.c:1531` `register_net_events`, e.g.
  the `HTTPStatusEvent` block at `:1584-1594` (`avm2_builtin_class` +
  `avm2_builtin_add_getter` + `event_override_method(…, "toString", …)` +
  `sconst`). `formatToString` is already the shared toString helper
  (`:1508-1518`).
- `flash.globalization.CurrencyParseResult` — ctor `(value:Number,
  currencyString:String)` and two read-only props. **No `CurrencyFormatter`
  is needed** — the test never parses anything, it constructs four instances
  and traces the two fields. There is no `flash.globalization` package
  registered at all today (grep: zero hits), so this adds the package's first
  class.
- `flash.trace.Trace` — all-static: 7 consts (`OFF/METHODS/
  METHODS_WITH_ARGS/METHODS_AND_LINES/METHODS_AND_LINES_WITH_ARGS/FILE/
  LISTENER` = 0,1,2,3,4,1,2) and 4 static methods whose `.length` values are
  pinned (1,0,2,1) and whose behavior in the **release** player is a no-op
  (`getLevel()` always 0, `getListener()` always null even after
  `setListener`/`setLevel`). `test.toml` documents this explicitly. It is
  literally a table.

**Patch scope:** ~30 lines each, three localized additions. `NetFilterEvent`
drops straight into `register_net_events`; the other two need a new
one-function registration each, following the same pattern.

**Flip count: +3** (all three are all-or-nothing — the entire expected output
is currently absent, so registering the class either flips the test or
doesn't move it at all). Realistic risk is that `NetFilterEvent`'s
`data=`/`header=` empty-ByteArray rendering needs `ByteArray.toString()`
parity; call it +2 guaranteed, +3 likely.

**Regression risk: near zero, and measured.** Oracle grep for the three
names across every `output.txt`/`output.ruffle.txt`: the only other consumers
are `avm2/all_classes/{events,display}/swf*`, which are `describeType` dumps
of the whole builtin surface and currently sit at 190/1638 … 357/2936 lines —
they can only improve. No test asserts these classes are absent. None of the
three has `known_failure`. No entry in any of the four disposition docs or
any `ignored_tests.txt`. **Blast radius: the AVM2 builtin registry table
only** — no existing class, method, or dispatch path is modified.

**GO. Effort S. Confidence HIGH.**

---

### C2 — Three XS singles with exact one-line pins ★ **GO** (an s11-B3-shaped bundle)

Unrelated mechanisms, bundled only by size. One commit each.

**C2a — Embedded bitmap dimensions truncate at 16 bits. ★ HIGHEST
confidence-per-line on the whole board.**
`visual/define_bits_jpeg2_huge` (gap 6). Expected width `524288`, we trace
`0`; `524288 & 0xFFFF == 0` exactly. The recompiler is **correct** — the
emitted `RecompiledTags/constants.h` in that test's tree already says
`#define BITMAP_HIGHEST_W 524288`, and `swf.cpp:1298` decodes into `int w, h`.
The loss is on the runtime side of the generated table:

```c
// SWFModernRuntime/include/avm2/avm2_abc.h:517-521
typedef struct Avm2BitmapData
{
	uint16_t char_id;
	uint16_t width;    // <-- 524288 -> 0
	uint16_t height;
```

consumed by `SWFModernRuntime/src/avm2/avm2_bitmap.c:753` (`bd_seed_embedded`:
`bd->width = emb->width;`). Widen both fields to `uint32_t`. The two sibling
images in the same test that are 65000 px (fits in u16) **already pass** —
that is the control. Expected flips: lines 3, 5, 6, 9, 10, 11 → full pass.
**Yield +1. Effort XS (2 fields + a struct-layout recompile). Confidence
HIGH.** Blast radius: the generated-table ABI changes, so every test
recompiles — mechanical, and CI covers it. Canary: any embedded-bitmap test
(`visual/*`, `avm2/bitmapdata_*`).

**C2b — `Date`'s default ToPrimitive hint must be String.**
`from_avmplus/ecma3/Expressions/e11_6_1_3` (gap 6). `DATE1 + DATE1` must
concatenate two date strings; we produce `0`. The pin carries its own stale
TODO:

```c
// SWFModernRuntime/src/avm2/avm2_value.c:648-658
Avm2Value avm2_coerce_to_primitive(Avm2Context* ctx, Avm2Value v, int hint)
{
	…
	if (hint == 0)
	{
		// Default hint: Number (Date would be String; no Date yet).
		hint = 1;
	}
```

`avm2_date.c` has existed for a long time. The only `hint == 0` call site is
`avm2_value.c:884-885` (the `add` operator), so the change is contained to
`+`. **Yield +1. Effort XS. Confidence HIGH.** Canary: all **153**
`from_avmplus/ecma3/Date/*` currently pass (137 `pass` + 16
`ruffle_matched`), plus siblings `e11_6_1_1` / `e11_6_1_2` which pass — an
unusually strong pre-existing canary set.

**C2c — `split(undefined)` must be distinguished from `split()`.**
`from_avmplus/ecma3/String/e15_5_4_8_2` (gap 6). ES3/avmplus `ToString` the
separator, so `"…".split(void 0)` splits on the literal `"undefined"`; only
a **missing** argument returns the whole string. Pin:

```c
// SWFModernRuntime/src/avm2/avm2_string.c:434, 446-450
Avm2Value delim_v = act->argc > 0 ? act->args[0] : avm2_undefined();
…
if (delim_v.kind == AVM2_VALUE_UNDEFINED)   // fires for BOTH cases
{ avm2_array_push(ctx, arr, avm2_string(s)); return …; }
```

Gate that branch on `act->argc == 0`. **Yield +1. Effort XS. Confidence
HIGH.** Canary: the 6 currently-passing `*split*` tests, notably
`ecma3/String/e15_5_4_8_1_rt` and `_3`.

**Optional 4th (lower confidence): C2d — SWF9 `localeCompare(null)` quirk.**
`from_avmplus/as3/String/localeCompare_585791/v9` (gap 6). The `v12` sibling
**passes**, so our implementation is already correct for modern SWFs; only
the SWF9 arm is wrong. avmplus bug 585791: in SWF9, `localeCompare` with a
null/undefined argument returns 0 for a non-empty receiver and 1 for the
empty string (the test pins exactly those six cases). Pin:
`SWFModernRuntime/src/avm2/avm2_string.c:391 string_locale_compare` — add a
`ctx->swf_version <= 9` arm before the coercion at `:406`. The version-gate
idiom already exists (memory `version-gate-new-api-surface`;
`avm2_number.c:636`). **Yield +1. Effort XS. Confidence MED** — the rule for
receivers outside the six probes is a guess. Canary: `v12`,
`ecma3/String/localeCompare_rt` (both pass).

**GO on C2a–C2c (+3, all XS, all with a file:line pin and a named canary).
C2d optional.**

---

### C3 — AVM2 error stack-trace rendering — **GO on two thirds, NO-GO on the third**

Three tests, and the cluster **splits cleanly into three sub-mechanisms of
very different price**. This is the one cluster where the "shared mechanism"
framing is half right.

**C3a — `getStackTrace()` must call the overridden `toString`. GO.**
`avm2/error_stack_trace_edge_cases` (gap 6). `Test.as` replaces
`Error.prototype.toString` twice and traces `err.getStackTrace()`. Expected:
the trace side-effect line fires, then the **returned** string is the first
line of the stack trace (`from toString`, then literally `null` when the
override returns null). We emit the hard-coded built-in header `Error` and
never call the override at all — which is why the `toString called (N)`
side-effect lines are missing too. One rule: `getStackTrace()` = a real
`this.toString()` call + `"\n"` + the frames. **+1, S, HIGH.**

**C3b — Stack-frame naming rules. GO.**
`avm2/error_stack_trace` (gap 7). Four independent naming rules, all in the
same frame renderer, all needed together for the +1:

| expected | ours |
|---|---|
| `at Test$cinit()` | `at Test/<anonymous>()` (class initializer) |
| `at MethodInfo-1()` / `MethodInfo-2()` | `at Function/<anonymous>()` (free script-level methods → their method_info index) |
| `at Test/uri::f()` | `at Test/f()` (namespaced method must print its namespace) |
| `at Test$/class_method()` ×3 | `at Test/class_method()` (statics take a `$` on the class) |

Self-consistent, no interpretation needed, no oracle conflict (a corpus grep
for these forms hits only this test). **+1, M, MED-HIGH.**
C3a and C3b touch the same file and should be one agent, one or two commits.

**C3c — Source positions in stack frames. NO-GO — REFUTED as a cheap win.**
`avm2/event_handler_exception` (gap 6) wants
`at Function/<anonymous>()[Z:\tests\tests\swfs\avm2\event_handler_exception\Test.as:10]`.
This is **not** unreproducible-oracle noise: I decompressed the CWS and the
ABC really does carry `debugfile "Z:\tests\tests\swfs\avm2\
event_handler_exception;;Test.as"`, so `OP_debugfile`/`OP_debugline` would
reconstruct it exactly. It is still a no-go:
- **Yield is effectively +1, not +2.** The only other consumer,
  `avm2/coerce_property`, is *already* `ruffle_matched` (33/36, the 3 missing
  lines are exactly these), so fixing it produces no effective-pass gain
  (memory `ruffle-matched-trap`, inverted).
- **Cost lands on the hot path.** Every frame needs a live current-line
  field updated at each `debugline` — in an AOT runtime whose stated purpose
  is beating Ruffle on speed (memory `purpose`).
- **`event_handler_exception` also has a second, conflicting defect.** We are
  missing an inner dispatch frame entirely. `output.txt` (Flash) calls it
  `flash.events::EventDispatcher/dispatchEventFunction()`;
  `output.ruffle.txt` calls it `dispatchEventInternal()`. `pass` needs the
  first *plus* source positions; `ruffle_matched` needs the second *and* no
  source positions. The two oracles are mutually exclusive, so this test
  cannot be moved by a partial fix.
Recommend recording C3c in `RUFFLE_VS_FLASH_DIFFERENCES.md` (the
`dispatchEventFunction`/`dispatchEventInternal` split) rather than scheduling
it.

---

### C4 — The ImportAssets pair — **CONDITIONAL GO**

`import_assets/avm1_imports_avm1` (gap 6, **true edit distance 1**) and
`import_assets/avm1_non_swf_import` (gap 6, true distance 3). Two thirds of
the entire `import_assets` suite (3 tests, 1 passing). One owner, two
sub-mechanisms:

- **Donor scripts must not execute.** We emit one extra leading line,
  `Hello from right_eye.swf`. `actionImportAssets`
  (`SWFModernRuntime/src/actionmodern/action.c:34559`) deliberately runs the
  donor's `frame_funcs[0]` after `init_func` to register character
  definitions (the comment at `:34594` explains why: otherwise `attachMovie`
  of an imported sprite has no bounds). It swaps in a scratch display list
  and sets `catch_up_mode = 1`, but the donor's inline `DoAction` still runs
  and traces. Needs a trace/DoAction suppression gate over that replay
  window, distinct from the existing script-drain suppression.
- **A non-SWF import must issue a logged GET.** `test.toml` sets
  `log_fetch = true`; the whole `swf_log_fetch_*` machinery already exists
  (`SWFModernRuntime/src/utils.c:176-221`, used by 24 other tests). The
  recompiler emits `actionImportAssets(app_context, "<url>")`
  (`SWFRecomp/src/swf.cpp:4852`) and the runtime bails at
  `action.c:34563` (`if (entry == NULL) return;`) when the URL is not a
  recompiled child SWF — silently. Queue the fetch on that early-return path.
  (This is the AVM1/ImportAssets twin of s11's B1 malformed-sibling fix.)

**Yield +2. Effort S–M. Confidence MED-HIGH** on the second half, **MED** on
the first. **Blast radius: the ImportAssets path is used by this 3-test suite
and nothing else in the corpus** (grep), but the frame-0 replay is load-
bearing for imported-sprite bounds — canary `import_assets/empty_url`
(passing) and any `attachMovie`-of-imported test. Note `avm1_imports_avm1`
also carries `[image_comparisons]`, so it is on the pixel board too.

---

### C5 — Loader completion timing — **NO-GO this session (arc-owned), but the shoulder member is real**

`avm2/large_preload_image_from_bytes` (gap 6, true distance 2) has exactly
two defects: `loader.numChildren` reads 1 at the final `ProgressEvent`
(must be 0 — the child is added too early), and `init`/`complete` fire one
`exitFrame` too early. That is the executor-drain question
(memory `loader-timing-is-executor-drain`), and it is narrow.

**I ran the two siblings to test whether this is a 3-test cluster. It is
not — refuted.** `avm2/large_preload_from_url` (gap 11) emits **nothing**
after the constructor: no `open`, no `progress`, no child. `large_preload_
from_bytes` (gap 33) crashes with #1009 on `loaderInfo` and never runs the
loadee's `LargeSWF` class. Both are the declared **loader-arc tranche-6**
child-SWF-execution blocker (s11 §(f) DO-NOT-TAKE), not an event-ordering
bug. The shoulder member is the *only* one of the three where the load
actually works. Fixing it alone is +1 for M effort against a fix path whose
blast radius is the whole (largely already-failing) loader family. **Defer to
the loader arc.**

---

### C6 — Singles that do NOT cluster (each priced, all NO-GO for wave 2)

- `avm2/sub_super_same_field` (gap 6) — a hand-edited SWF gives `LevelTwo`/
  `LevelThree` slot traits with the **same** name+namespace as `LevelOne`'s.
  avmplus keeps them as separate per-class slots and binds each method's
  `this.pubSameName` to its own declaring class's slot; we merge them into
  one property, so `LevelOne.print()` reads `LevelTwo`'s value. The
  *condition* (a subclass redeclaring an inherited trait) is unreachable from
  a normal AS3 compiler, so a gated fix would have almost no blast radius —
  but the fix itself is early-binding typed property access to the declaring
  class, which is core slot machinery for +1 test. **NO-GO; log as a known
  AVM2 slot-identity gap** next to memory `private-ns-identity`.
- `avm2/supercalls_coerce` (gap 7) — expected `1034 ×6` then `1009`; we
  return `1063 / 1077 / 1037 / 1070 / 1010` and let two probes succeed. Five
  different wrong codes = five different missing coercions, not one
  mechanism. No `.as` source ships; needs an ABC dump first. **NO-GO, needs
  scoping.**
- `timeline/missing_frame_scripts` (gap 10, true distance ~7) — a clip that
  has run past its last frame keeps re-running frame scripts every loop and
  emits its own `stopped`. Real timeline mechanism, single test. **NO-GO.**
- `from_shumway/…/matrix3d/TransformBasics` (gap 8) — `transform.matrix3D`
  setter and `Transform.getRelativeMatrix3D` do not exist. Feature work.
  Carries `known_failure = true`, i.e. **Ruffle fails it too**; per memory
  `t2` that means the oracle is Flash, not Ruffle, and a fix scores a full
  pass — but it is Matrix3D feature work. **NO-GO.**
- `avm2/id3_info` (gap 8) — same `#1065` signature as C1 but needs
  `Sound.id3` plus real ID3v2 parsing of the shipped `test_audio.mp3`. **M+.
  NO-GO** (do not let the shared signature pull it into C1).
- `avm2/stage_display_state` (gap 6) — same signature; needs
  `FullScreenEvent` **and** `Stage.displayState` + a fullscreen transition to
  dispatch it. **M. NO-GO** (same warning).
- `from_avmplus/regress/bug_539328` (gap 8) — `describeType` on an
  interface's `Class` object; our output stops after 8 of 15 lines. Belongs
  with the `describe_type_*` family (gaps 151/125/23), not with the shoulder.
- `from_gnash/misc-ming.all/action_order/…_test11` (gap 6, true distance ~4)
  — AVM1 `doActionOrder` and `asOrder` strings differ on nested-clip
  interleaving. The other 4 assertions in the same test already pass. Sole
  AVM1 member of the live pool; the ordering model is the one from memory
  `tracer-order`. **NO-GO** — high-traffic AVM1 execution order for +1.
- `avm2/delayed_symbolclass` (gap 8) — **already owned**: s11's
  `w2-b8b-lazyinit` took it from 16/28 to 2/28 and stopped, blocked on
  frame-1 LAZY script init and explicitly declared out of charter. Do not
  re-scope.
- `mixed_avm/avm2_loads_avm1_v9` (gap 6) — declared dual-VM /
  child-frame-execution arc (s11 §(f)). `Loader.content` must become an
  `AVM1Movie`; we throw #2007 on `addChild`. **NO-GO, arc-owned.**

---

## 4. Refutations (yield, per the brief)

1. **The band itself.** "gap 6–10" is a positional-metric artifact, not a
   mechanism band — §2. At least 4 of 22 are semantically ≤ 3-line diffs.
   **The single most valuable output of this board is the recommendation to
   add an LCS gap column to the standard triage script.**
2. **The `#1065` cluster does not hold at 4.** It holds at 2 (+1 rider). The
   error signature is a *triage* axis, not a *cost* axis: `netfilterevent` and
   `currency_parse_result` are table entries; `id3_info` and
   `stage_display_state` are feature arcs behind the identical stderr line.
   Generalization: **bucketing by error signature over-clusters — always
   re-price each member against its `Test.as`.** (Consistent with memory
   `label-trap` and `fixes-overshoot`.)
3. **The `large_preload` "family" is not a family** — §C5. Two of three are
   loader-arc child-execution blockers with no shared fix.
4. **`event_handler_exception` is not an unreproducible-oracle test** (the
   `Z:\…` path is genuinely in the ABC's `debugfile`) — but it *is* a no-go
   for a different, stronger reason: an internal Flash-vs-Ruffle oracle
   conflict on the dispatch frame name, plus zero effective yield from its
   only sibling. §C3c.
5. **`runtime_error` as "cheapest triage axis" is exhausted** for a 4th
   session (1 row, arc-owned). Its successor is the `#1065` /
   unresolved-import census — cheap, and it closed a whole bucket here in one
   pass.

---

## 5. Recommended wave-2 batch

| # | batch | tests | yield | effort | conf. | blast radius |
|---|---|---|---|---|---|---|
| **A** | C1 builtin value-class registration (`NetFilterEvent`, `CurrencyParseResult`, + `flash.trace.Trace` rider) | 3 | **+3** (+2 floor) | S | HIGH | AVM2 builtin registry only; `all_classes/*` can only improve |
| **B1** | C2a `Avm2BitmapData` u16 → u32 | 1 | +1 | XS | HIGH | generated-table ABI ⇒ full recompile; canary any embedded-bitmap test |
| **B2** | C2b `Date` default ToPrimitive hint = String | 1 | +1 | XS | HIGH | `+` operator only; canary 153 passing `ecma3/Date/*` |
| **B3** | C2c `split(undefined)` vs `split()` | 1 | +1 | XS | HIGH | canary 6 passing `*split*` tests |
| **C** | C3a+C3b `getStackTrace` toString + frame naming | 2 | +2 | M | MED-HIGH | AVM2 stack renderer; canary `error_geterrormessage`, `coerce_property` |
| **D** | C4 ImportAssets pair (optional) | 2 | +2 | S–M | MED | `import_assets` suite (3 tests) + imported-sprite bounds |
| — | C2d SWF9 `localeCompare` (optional) | 1 | +1 | XS | MED | version-gated; canary `v12`, `localeCompare_rt` |

**Predicted total: +8 (A+B1..B3+C), +10 with the two optionals.** A and
B1–B3 are four independent commits with no shared files and can go to one
agent as a single batch; C wants its own agent.

Every recommended test was verified failing at HEAD by a local run today.
None appears in `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`, or any
`ignored_tests.txt`; none carries `known_failure`.

### Hygiene follow-ups (not wave-2 work)

- Add an LCS/edit-distance gap column to the board script (§2).
- s11 §(c) recommended adding `avm2/loader_applicationDomain` and `avm2/swz`
  to `avm2/ignored_tests.txt`; **still not done** — both still count as live
  failures on this board.
- Consider recording the `dispatchEventFunction` vs `dispatchEventInternal`
  split (§C3c) in `RUFFLE_VS_FLASH_DIFFERENCES.md`.
