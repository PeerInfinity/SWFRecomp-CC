# wave1-trace-upstream4 — the 4 new upstream failures from session-11 corpus drift

Agent: `w1-trace-upstream4`, session 12. Read-only w.r.t. source. HEAD `f166e424e`.
Baseline run: avm2 `results_graphics.json` @ `6de650432`, 1226 tests, 30/30 shards.

---

## 0. Executive summary

| test | suite | root cause | fixable? | scope | flip |
|---|---|---|---|---|---|
| `av_classes` | `avm2/` | 13 of 15 `flash.media.AV*` classes not registered | **yes** | ~500 LOC, mechanical | +1 pass |
| `flash_trace` | `avm2/` | `flash.trace.Trace` not registered at all | **yes** | ~45 LOC | +1 pass |
| `groupelement_text` | `avm2/` | `flash.text.engine.GraphicElement` missing + `GroupElement.text` null-fold wrong | **yes** | ~90 LOC | +1 **effective** (`ruffle_matched`, not a plain pass — see §3.4) |
| `avm1movie_addcallback_call` | `avm2/` | Loader never mints an `AVM1Movie` for an AVM1 child ⇒ `loader.content` is null | **yes, but** | ~120 LOC across 2 subsystems | +1 pass |

**All four are genuinely failing at HEAD — no refutations.** I re-ran all four locally (sequentially, not under load) and reproduced each error signature exactly as CI reported it.

**Total available: +4 (3 plain pass, 1 effective).** None of the four is a Ruffle-only expectation; three are plain Flash-truth expectations, and the fourth (`groupelement_text`) is upstream-marked `known_failure = true` so the achievable ceiling there is `ruffle_matched`.

### Net corpus arithmetic — this drift was a **net −1**, not a net −4

`ab5115880 tests: Add test for AV classes` **deleted** `avm2/av_networking_params`
and `avm2/av_tag_data` in the same commit that added `av_classes`. Both were
**passing** at the previous baseline. So the drift is:

```
new:   av_classes, avm1movie_addcallback_call, flash_trace, groupelement_text   (4 fail)
gone:  av_networking_params, av_tag_data                                        (2 pass)
avm2 total: 1224 -> 1226
```

`av_classes` is a strict superset of the two deleted tests (it re-tests
`AVNetworkingParams` and `AVTagData` with far tighter assertions). Fixing
`av_classes` therefore recovers the lost coverage *and* nets +1 over the
pre-drift effective count.

---

## 1. Locating the tests — none were in the local mirror

All four are in **`ruffle-tests/tests/swfs/avm2/`** (no cross-suite name
ambiguity; `find` over every suite returns exactly one hit each, in avm2).

None of the four existed locally, and none existed in the local Ruffle clone
either — `~/CC/ruffle` was pinned at `437be1498` (2026-07-29). I ran
`git fetch origin` in `~/CC/ruffle` (now `e14db71e4 avm2: Add more AV
implementation`) and extracted the test trees from `origin/master` **without
checking out** (`git show origin/master:<path>`), so the user's working tree in
that repo is untouched.

I then installed the four test dirs into the local mirror at
`ruffle-tests/tests/swfs/avm2/{av_classes,avm1movie_addcallback_call,flash_trace,groupelement_text}/`.
`ruffle-tests/tests/swfs/avm2/*/` is **gitignored** (`.gitignore:137`), so this
adds nothing to the repo — but it means the local mirror is now ahead of the
last `download_tests.sh` run. **They are left in place** so the implementer does
not have to repeat the fetch. (The now-upstream-deleted `av_networking_params`
and `av_tag_data` are also still present locally; harmless, CI downloads fresh.)

Upstream provenance:

| test | added by |
|---|---|
| `av_classes` | `ab5115880` tests: Add test for AV classes (also deletes the 2 old ones) |
| `flash_trace` | `dcc32f9d9` avm2: Partially implement the rest of `flash.trace.Trace` |
| `groupelement_text` | `cb2f2196c` tests: Add test coverage for accessing `GroupElement.text` |
| `avm1movie_addcallback_call` | `433b399c3` avm2: Have `AVM1Movie.call`/`addCallback` throw error 2014 |

## 1a. Dispositions checked FIRST

Grepped all four names against:
- `ruffle-tests/ignored_tests.txt`
- `ruffle-tests/tests/swfs/avm1/_investigation/*.md` (ACCEPTED_DIFFS,
  RUFFLE_VS_FLASH_DIFFERENCES, RUFFLE_COMPAT_TWEAKS, FLASH_BUGS_REPLICATED)
- `ruffle-tests/tests/swfs/avm2/_investigation/*.md`

**Zero hits.** No existing disposition covers any of them — they are all
brand-new arrivals with no prior adjudication.

---

## 2. `av_classes` — 13 missing `flash.media.AV*` classes

**Suite path:** `ruffle-tests/tests/swfs/avm2/av_classes/`
(`Test.as` 252 lines, `output.txt` 340 lines, `test.toml`: `num_ticks = 1`, ASC, swf_version 20)

### What it exercises
A single flat driver that, for 15 `flash.media.AV*` classes, calls
`testProp(o, name)` (trace the value + `typeof`, then attempt a write and trace
either "Successfully set ..." or the caught error) and `testConsts(cls, ...)`
(trace each static const + `typeof`). It is a pure surface/typing test — no
media is ever played.

### Actual vs expected at HEAD
```
     1  === Testing AVABRParameters
-    2  policy: hello string                                     (+338 more)
+    2  ReferenceError: Error #1065: Variable AVABRParameters is not defined.
+    3  	at Test()
```
`actual=3, expected=340`, `matching_lines=1`. Dies on the very first
`new AVABRParameters(...)`.

### Root cause
Only 2 of the 15 classes exist in our runtime:

- `flash.media.AVTagData` — `SWFModernRuntime/src/avm2/avm2_media.c:620-650`
  (ctor + 2 getters), registered at `avm2_media.c:730-741`.
- `flash.media.AVNetworkingParams` — `SWFModernRuntime/src/avm2/avm2_net.c:2002-2075`
  (ext struct + accessor macros), registered at `avm2_net.c:2703-2723`.

The other **13** (`AVABRParameters`, `AVABRProfileInfo`, `AVCaptionStyle`,
`AVCuePoint`, `AVInsertionResult`, `AVPeriodInfo`, `AVPlayState`, `AVResult`,
`AVSegmentedSource`, `AVSource`, `AVStream`, `AVTimeline`, `AVTrackInfo`) have
**no occurrence anywhere in `SWFModernRuntime/` or `SWFRecomp/src/`**. So the
first name lookup throws `#1065`.

### Every piece of required infrastructure already exists

| requirement | already present at |
|---|---|
| builtin class registration | `avm2_builtin_class()`, used ~everywhere in `avm2_media.c:656+` |
| read-only prop ⇒ `#1074` | getter-with-`NULL`-setter already raises it; `SWFModernRuntime/src/avm2/avm2_ops.c:1040,1080,1109`; message table `avm2_error.c:636` |
| **dotted** class name in `#1074` (`flash.media.AVABRProfileInfo`, not `::`) | `avm2_class_qname_buf()` — `SWFModernRuntime/src/avm2/avm2_class.c:19-32` emits `ns.name` |
| static consts | `avm2_builtin_add_static_const()` — `SWFModernRuntime/include/avm2/avm2_globals.h:153` |
| dont-enum backing fields, GC-traced for free | the `AVTagData` idiom, `avm2_media.c:635-637` |

So the patch is **purely additive registration** — no new mechanism.

### Semantics, fully derivable (two independent sources)
1. `output.txt` pins every value and `typeof`.
2. `~/CC/ruffle` `origin/master` ships a `.as` source for **all 15**:
   `core/src/avm2/globals/flash/media/AV{ABRParameters,ABRProfileInfo,CaptionStyle,CuePoint,InsertionResult,NetworkingParams,PeriodInfo,PlayState,Result,SegmentedSource,Source,Stream,TagData,Timeline,TrackInfo}.as`
   — read them with `git show origin/master:<path>`; they are the exact spec.

Slot-typing summary derived from `output.txt` (ctor args are coerced into the
declared slot type, which is why `2.2 -> 2` and `3.3 -> true`):

- **`AVABRParameters(policy:String, start:int, min:int, max:int)`** — the ONLY
  fully **writable** one besides `AVNetworkingParams`. Writing `123.45` to
  `policy` reads back `"123.45"` (String slot); to the int slots reads back `123`.
  3 String consts (`aggressive`/`conservative`/`moderate`).
- **`AVABRProfileInfo(bps:int, w:int, h:int)`** — read-only (`1/2/3`).
- **`AVCaptionStyle()`** — 11 **writable String** props, all defaulting to `""`
  **except `bottomInset` which defaults to the string `"0"`**. 38 String consts.
  Watch the two non-obvious const values: `LEFT_DROP_SHADOW = "drop_shadow_left"`,
  `RIGHT_DROP_SHADOW = "drop_shadow_right"`.
- **`AVCuePoint(dict:Object, localTime:Number)`** — read-only; `dict` keeps the
  object identity (`[object Dictionary]`) or `null`; `localTime` is a real
  Number (`2.2` survives).
- **`AVInsertionResult(result:int, periodIndex:int, insertedBeforeReadHead:Boolean)`**
  — **`extends AVResult`** (`o is AVResult: true`); read-only.
- **`AVPeriodInfo(...10 args)`** — mixed: 3 Numbers, 5 ints, 1 Boolean, 1 Number;
  read-only.
- **`AVPlayState(state:int)`** — read-only; 9 int consts 0..8.
- **`AVResult(result:int)`** — read-only; **~100 int consts**, `END_OF_PERIOD = -1`,
  then 0..91 contiguous, then a jump to 300..307 for the `CRYPTO_*` block.
- **`AVSource extends EventDispatcher`**, **`AVSegmentedSource extends AVSource`**;
  both script-constructible. 10 String consts on `AVSegmentedSource` (note the
  inconsistent casing upstream pins: `DASH = "DASH"`, `HLS = "HLS"`, but
  `AUDIO = "audio"`).
- **`AVStream(source:AVSource) extends EventDispatcher`**; 3 String consts —
  **`SOFTWARE = "sofware"` (upstream/FP typo, must be replicated verbatim)**.
- **`AVTimeline(type:String, ...7)`** / **`AVTrackInfo(...8)`** — read-only value
  objects; `AVTrackInfo.dataTrackInfoServiceType` is a **String** slot so `7.7`
  reads back as `"7.7"`, while `pid` is an int so `8.8` reads back `8`.
  3 String consts (`DTI608Captions`, `DTI708Captions`, `DTIWebVTTCaptions`).

### One real bug in existing code
`SWFModernRuntime/src/avm2/avm2_net.c:2028-2029`:
```c
	// appendRandomQueryParameter has no initializer, so it reads as null.
	e->query_param = avm2_null();
```
Upstream `AVNetworkingParams.as` declares
`private var _appendRandomQueryParameter:String = "";` and `av_classes` expects
`appendRandomQueryParameter:  string` (blank value, `typeof` = `"string"`).
Our `null` would trace `appendRandomQueryParameter: null object`.
**One-line fix:** initialise to an empty `Avm2String` instead of `avm2_null()`.
Affects 2 expected lines (both the default-params and provided-params blocks).
No existing test reads this property, so the change is regression-free.

### Verdict
**Fixable this session.** ~500 LOC of mechanical registration appended to
`avm2_media.c` (after `avtagdata_ctor`, registered inside `avm2_register_media`
at `avm2_media.c:656-741`), plus the 1-line `avm2_net.c:2029` fix.
Predicted flip: **+1 pass** (and it restores the coverage of the two
upstream-deleted tests).
**Regression risk: very low** — 13 brand-new class names that nothing else can
observe; the only shared-code touch is one initialiser value on a property no
other test reads.

---

## 3. `flash_trace` — `flash.trace.Trace` does not exist

**Suite path:** `ruffle-tests/tests/swfs/avm2/flash_trace/`
(`Test.as` 46 lines, `output.txt` 17 lines, `test.toml`: `num_frames = 1`, swf_version 9)

The `test.toml` carries a useful note: this test deliberately captures
**release**-player behaviour (all the setters are no-ops there), so it can't be
regenerated with the Flash debugger.

### What it exercises
Reads the 7 static consts, reads `.length` off the 4 static methods (i.e. reads
each static method **as a Function value**), then calls `getLevel`/`getListener`,
calls `setListener`/`setLevel` three times, and re-reads — asserting the setters
changed nothing.

### Actual vs expected at HEAD (local re-run, confirmed)
```
-    1  OFF: 0                          (…all 17 lines)
+    1  ReferenceError: Error #1065: Variable Trace is not defined.
+    2  	at Test()
```
`actual=2, expected=17`, `matching_lines=0`.

### Root cause
`grep -rn "flash.trace"` over `SWFModernRuntime/` returns **nothing**. The
package and class are simply not registered.

### Semantics (upstream `core/src/avm2/globals/flash/trace/Trace.as`, verbatim)
```as3
public class Trace {
    public static const OFF:int = 0;
    public static const METHODS:int = 1;
    public static const METHODS_WITH_ARGS:int = 2;
    public static const METHODS_AND_LINES:int = 3;
    public static const METHODS_AND_LINES_WITH_ARGS:int = 4;
    public static const FILE = 1;        // untyped, still typeof "number"
    public static const LISTENER = 2;
    public static function getLevel(target:int = LISTENER):int  { /* always 0 */ }
    public static function getListener():Function               { /* always null */ }
    public static function setLevel(level:int, target:int = LISTENER) {}  // no-op
    public static function setListener(func:Function) {}                  // no-op
}
```
Because both level fields stay 0 and the listener stays null, **all four methods
can be pure constants** in our runtime: `getLevel -> 0`, `getListener -> null`,
`setLevel`/`setListener` -> `undefined`.

The only non-trivial requirement is `Function.length` reporting the **declared**
arity (1/0/2/1), including optional params. That is already supported:
`avm2_builtin_add_static_method_n(ctx, cls, name, fn, param_count)` —
`SWFModernRuntime/include/avm2/avm2_globals.h:151-152` — and `fn_get_length`
reports exactly that `param_count` (`SWFModernRuntime/src/avm2/avm2_function.c:399-405`,
whose comment already documents this being pinned by the avmplus suite).

### Verdict
**Fixable this session — cheapest of the four.** ~45 LOC dropped into
`register_platform_stubs()` at `SWFModernRuntime/src/avm2/avm2_globals.c:2560-2620`
(the established home for small `flash.*` classes: `Accessibility`, `IME`,
`Worker`, `GameInput`, …), using `avm2_builtin_add_static_const` +
`avm2_builtin_add_static_method_n`.
Predicted flip: **+1 pass**.
**Regression risk: essentially zero** — a brand-new package/class name;
`flash.trace` appears in exactly one test in the whole corpus.

---

## 4. `groupelement_text` — missing `GraphicElement` + wrong `GroupElement.text` fold

**Suite path:** `ruffle-tests/tests/swfs/avm2/groupelement_text/`
(`Test.as` 66 lines, `cases.as` **0 bytes** and unreferenced by `test.toml`,
`output.txt` 156 lines, `output.ruffle.txt` 156 lines,
`test.toml`: `num_frames = 1`, **`known_failure = true`**, swf_version 30)

### What it exercises
26 element vectors are run twice — once through
`element.replaceElements(0, 1, v)` on a group pre-seeded with one bare
`TextElement()`, once through `element.setElements(v)` on a fresh group — tracing
`element.text` (with an explicit `=== null` discriminator so `null` and `""` are
distinguishable) and `element.elementCount`.

### Actual vs expected at HEAD (local re-run, confirmed)
```
-    1  Testing replaceElements to null            (…all 156 lines)
+    1  ReferenceError: Error #1065: Variable GraphicElement is not defined.
+    2  	at Test/doTest()
+    3  	at Test()
```
Dies while *building* the case array, at `new GraphicElement()`.

### Root cause A — `GraphicElement` is not registered
`grep -rn GraphicElement SWFModernRuntime/src SWFModernRuntime/include` (minus
`hasGraphicElement`) returns **nothing**. The FTE family registered at
`SWFModernRuntime/src/avm2/avm2_text.c:7448-7496` covers `ContentElement`,
`TextElement`, `GroupElement` — but not `GraphicElement`.

Upstream `core/src/avm2/globals/flash/text/engine/GraphicElement.as`:
`[API("662")] public final class GraphicElement extends ContentElement`, ctor
`(graphic:DisplayObject = null, elementWidth:Number = 15.0,
elementHeight:Number = 15.0, elementFormat:ElementFormat = null,
eventMirror:EventDispatcher = null, textRotation:String = "rotate0")`, with
`graphic` / `elementWidth` / `elementHeight` accessors (all stubs upstream).
For this test only the class's existence, its `ContentElement` base (so
`Vector.<ContentElement>` coercion accepts it), and its `text` behaviour matter.

### Root cause B — `GroupElement.text` uses the wrong fold
`SWFModernRuntime/src/avm2/avm2_text.c:6126-6148`:
```c
static const Avm2String* group_text_of(Avm2Context* ctx, Avm2Object* o)
{
	...
	for (uint32_t i = 0; v != NULL && i < v->length; i++)
	{
		const Avm2String* t = ...ce_text_of(ctx, e.u.obj)...;
		if (t != NULL) sb_bytes(ctx, &sb, t->utf8, t->len);   // nulls SKIPPED
	}
	return avm2_string_new(ctx, sb.buf != NULL ? sb.buf : "", sb.len);  // NEVER null
}
```
Ours **never returns null** and silently drops null children. FP's rule (ported
verbatim in upstream `core/src/avm2/object/content_element_object.rs::text()`,
lines 145-177) is a null-propagating fold:

```
result = None
for each child:
    new = child.text            // TextElement -> stored text (may be None)
                                // GraphicElement -> Some("")
                                // GroupElement  -> recurse
                                // bare/invalid ContentElement -> None
    if new is Some:
        result = Some(result.unwrap_or("") ++ new)      // concat, or adopt
    else if result == Some("") :
        result = None                                   // an empty result is
                                                        // POISONED by a null child
    // else: result unchanged (a non-empty result is immune to nulls)
return result
```

I hand-checked this fold against **every** case in `output.txt` and it reproduces
all of them, including the counter-intuitive asymmetries the test is built to
catch:

| elements | expected | why |
|---|---|---|
| `[GraphicElement(), GroupElement()]` | `null` | `Some("")` then poisoned by `None` |
| `[GroupElement(), GraphicElement()]` | `""` | `None` stays `None`, then adopts `Some("")` |
| `[TextElement(""), GroupElement()]` | `null` | same poisoning |
| `[GroupElement(), TextElement("")]` | `""` | same asymmetry |
| `[GroupElement(), TextElement("Hello")]` | `"Hello"` | `None` adopts |

### The `known_failure` ceiling — this is a Flash quirk we should NOT chase
`diff output.txt output.ruffle.txt` is exactly **2 lines**:
```
2c2,5c5
<     element.text is now ""      (Flash)
>     element.text is now null    (Ruffle)
```
— the `replaceElements(0, 1, null)` and `replaceElements(0, 1, [])` cases. Flash
reports `""` there but `null` for the *identical* end state reached via
`setElements(null)` / `setElements([])` (lines 78 and 81 of `output.txt` both say
`null`). That is a residual-state artifact of FP's `replaceElements` path, not a
derivable rule; Ruffle declined to replicate it and marked the test
`known_failure`.

`ruffle-tests/verify_output.py:4213-4245` promotes a test to **`ruffle_matched`**
when it is `known_failure` and our diff set is within Ruffle's. Implementing the
fold above therefore lands us at `ruffle_matched` = **effective pass**, which is
the correct target. Chasing the 2 extra lines would mean inventing a
`replaceElements`-specific poisoned-empty state; **do not**.

### Verdict
**Fixable this session.** ~90 LOC:
1. Register `GraphicElement` next to `GroupElement` at `avm2_text.c:7484-7496`
   (`ContentElement` base, `SEALED|FINAL`, ctor storing nothing we need, three
   stub accessors returning `null`/`15.0`/`15.0`).
2. Teach `ce_text_of` (`avm2_text.c:6143-6148`) to return the interned empty
   string for a `GraphicElement`.
3. Rewrite `group_text_of` (`avm2_text.c:6126-6141`) as the null-propagating fold.

Predicted flip: **+1 effective** (`output_mismatch -> ruffle_matched`).

**Regression risk: low, and bounded.** `ce_text_of` has exactly two callers
(`avm2_text.c:6155` and `:7226`):
- `:7226` is `TextBlock.createTextLine`, and the very next line
  (`avm2_text.c:7227`) already does `if (text == NULL) text = empty_string(ctx);`
  — so a newly-null group text degrades to today's behaviour there.
- Corpus-wide, only **three** tests mention `GroupElement`:
  `groupelement_text` (the target), `text_engine_groupelement` (**pass** — reads
  only `getElementAt(i).text`, never `group.text`), and `textblock_createline_fte`
  (**pass** — builds a group of real non-empty `TextElement`s, where the fold is
  identical to today's concatenation).

---

## 5. `avm1movie_addcallback_call` — Loader never mints an `AVM1Movie`

**Suite path:** `ruffle-tests/tests/swfs/avm2/avm1movie_addcallback_call/`
(`Test.as` 42 lines, `child.swf` (AVM1), `output.txt` 14 lines,
`test.toml`: `num_ticks = 3`, swf_version 9)

### What it exercises
`Loader.load("child.swf")` (an AVM1 SWF); on `complete`,
`loader.content as AVM1Movie` is added to the stage, then `call`/`addCallback`
are invoked five times with varying arity, each inside a `try` that traces
`e.getStackTrace()`. **The AVM1 child is never executed** — the test only needs
`content` to be a live `AVM1Movie` instance.

### Actual vs expected at HEAD
```
+ TypeError: Error #2007: Parameter child must be non-null.
+ 	at flash.display::DisplayObjectContainer/addChild()
+ 	at Test/onLoaded()
```
`actual=3, expected=14`, `matching_lines=0`.

Note what the actual output **proves**: `onLoaded` is on the stack, so the fetch
resolved, `child.swf` was found in the movie registry, and `complete` fired
correctly. The *only* thing missing is `content`.

### Root cause — the loader's content gate is AVM2-only
`SWFModernRuntime/src/avm2/avm2_display.c:5650-5654`:
```c
	if (pl->content_type == LI_CT_SWF && pl->tables != NULL)
	{
		if (from_bytes) lx->pending_boot = pl->tables;
		else loader_boot_child_swf(ctx, li, lx, pl->tables);
	}
```
`loader_boot_child_swf` is the only path that assigns `lext->content` for a SWF
(`avm2_display.c:5507`). `pl->tables` is `m->avm2_tables`, and
`avm2_display.c:5811-5814` states plainly that it **"stay[s] NULL for an AVM1
child or an image shell"**. So for an AVM1 child, `lx->content` /
`lext->content` are never set, `Loader.content` returns
`avm2_null()` (`avm2_display.c:4612`), and `addChild(null)` raises `#2007`.

The class shell is already there but is explicitly a dead end —
`SWFModernRuntime/src/avm2/avm2_display.c:13705-13712`:
```c
	// flash.display.AVM1Movie — the DisplayObject wrapper an AVM2 movie sees
	// around a loaded AVM1 child. We do not execute cross-VM children yet, so
	// nothing ever mints one; the class exists to resolve.
	{
		Avm2Class* avm1movie = avm2_builtin_class(ctx, "flash.display",
		                                          "AVM1Movie", dobj);
		avm1movie->native_init = display_native_init_abstract;
	}
```
It has **no methods at all** — no `call`, no `addCallback`.

### What the fix needs (three parts)
1. **Mint the wrapper.** In `loader_deliver`, add an else-arm to the
   `avm2_display.c:5650` gate: for `LI_CT_SWF` with `pl->tables == NULL`,
   construct an `AVM1Movie`, assign it to `lx->content` and `lext->content`, and
   `insert_at_index(ctx, lx->loader, mov, 0)` — mirroring the image arm at
   `avm2_display.c:5600-5612`.
   **Gotcha:** `AVM1Movie` is `[Ruffle(Abstract)]` and `abstract_classes`
   (**currently passing**) asserts that a script `new AVM1Movie()` throws
   `#2012`. Today the shell hangs the *unconditional*
   `display_native_init_abstract` (`avm2_display.c:11179-11191`) on it, which
   would also refuse the runtime's own mint. Swap it for a **conditional** gate,
   the established `script-new-vs-internal-mint` split. Two existing shapes to
   copy from:
   - `morphshape_native_init` (`avm2_display.c:11231-11245`), used by
     `MorphShape`/`StaticText` at `avm2_display.c:13696-13703` — throws unless a
     module-level flag (`g_timeline_instantiation`) says the runtime is doing the
     minting. An `AVM1Movie` needs the same shape but keyed on a
     loader-delivery flag, since its mint comes from `loader_deliver`, not
     timeline instantiation.
   - the generic `avm2_builtin_set_abstract_script_only()`
     (`SWFModernRuntime/include/avm2/avm2_globals.h:161`), which the comment
     documents as being "for a class the runtime itself still mints (Graphics,
     Stage, the Stage3D resource family)" — check whether its bypass condition
     is reachable from the loader path before reusing it.
2. **Add the two methods** with declared arity, matching upstream
   `core/src/avm2/globals/flash/display/AVM1Movie.as`:
   `call(functionName:String, ...rest)` → arity **1**;
   `addCallback(name:String, fn:Function)` → arity **2**. Both bodies
   `Error.throwError(Error, 2014)`.
3. **`#1063` for a builtin method.** `throw_1063`
   (`SWFModernRuntime/src/avm2/avm2_function.c:71-90`) covers **script** methods
   only; builtins today check arity ad hoc per class
   (`avm2_vector.c:1002`, `avm2_number.c:496`, `avm2_string.c:401`). Simplest is
   an ad-hoc check in each of the two methods emitting
   `"Error #1063: Argument count mismatch on flash.display::AVM1Movie/%s(). Expected %u, got %u."`
   (colon-qualified here — use `avm2_class_qname_colons_buf`,
   `avm2_class.c:34`).

### All the stack-trace machinery already works
The expected output needs a synthetic `at Error$/throwError()` frame *above* a
`at flash.display::AVM1Movie/addCallback()` frame. Both exist:
- The `throwError` idiom: `SWFModernRuntime/src/avm2/avm2_display.c:8414-8419`
  (`static const Avm2MethodRef throwerror = { NULL, NULL, "Error$/throwError", 0 };
  avm2_callstack_push(ctx, &throwerror, NULL);`), also used at
  `avm2_text.c:5655, 6729, 7185`.
- Qualified builtin-method frames: `textline_throwerror` **passes** today with
  `at flash.text.engine::TextLine/set contextMenu()` in its expected output, so
  builtin dispatch already pushes properly-qualified frames
  (`avm2_class.c:1079`).
- `#2014`'s message text is already in the table: `avm2_error.c:726`.

### Verdict
**Fixable this session, but it is the largest and riskiest of the four** —
~120 LOC touching the loader delivery path (`avm2_display.c:5650`) as well as the
class registration (`avm2_display.c:13705`). It is the only one of the four that
modifies shared, heavily-exercised machinery.

Predicted flip: **+1 pass**.

**Regression risk: moderate — this is the one to sequence last / behind its own
CI run.** Two named exposures:
- `avm2/abstract_classes` (**pass**) lists `AVM1Movie` among the classes whose
  script `new` must throw `#2012`. A careless un-abstracting flips it. Use the
  script-only gate.
- `from_shumway/avm1movie` (**`ruffle_matched`**, currently dying with
  `#1009 … (accessing field: getBounds)` on the same null `loader.content`) will
  change output. Its promotion rule is `ours_diff_count(8) ⊆ ruffle_diff_count(12)`
  — Ruffle only emits 4 of the 13 expected lines there, so it differs on nearly
  everything, and our newly-emitted-but-still-wrong lines (an empty `AVM1Movie`
  reports `bounds: (x=0, y=0, w=0, h=0)`, not the expected `220x100`, because we
  still don't render AVM1 children) should stay inside that set. **Verify
  explicitly** — per the `ruffle-matched-trap` rule, a `ruffle_matched -> fail`
  slide on a `known_failure` test is a real regression and is easy to miss.
- Every other loader test is AVM2-child or image and takes the unchanged arm of
  the gate, but the `LI_CT_SWF && tables == NULL` condition is also what a
  **malformed / byte-shell** child hits (`avm2_display.c:5800-5810`). Guard the
  new arm on `m->frame_funcs != NULL` (a real SWF) so
  `from_shumway/as3-loader/bug1157243/{empty,invalid}` keep routing to the
  `#2124` ioError path.

---

## 6. Recommended sequencing

| order | test | why |
|---|---|---|
| 1 | `flash_trace` | ~45 LOC, zero-risk, isolated new namespace |
| 2 | `av_classes` | ~500 LOC but purely additive; only shared touch is `avm2_net.c:2029` |
| 3 | `groupelement_text` | ~90 LOC; bounded blast radius, but does change a shared FTE fold — re-run `text_engine_groupelement`, `textblock_createline_fte`, `content_element_basic`, `textblock_createline_errors` locally |
| 4 | `avm1movie_addcallback_call` | ~120 LOC in the loader; land last and check `abstract_classes` + `from_shumway/avm1movie` explicitly |

Items 1-3 can share one CI dispatch. Item 4 deserves its own, and because
`av_classes`/`flash_trace`/`groupelement_text` all touch AVM2 runtime emission
surface, the run should use **`categories=full`** per the project CI policy.

## 7. Dispositions to write

**None.** All four are implementable; none belongs in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, or `ignored_tests.txt`.

The one judgement call worth recording *after* the fix lands is
`groupelement_text`: its 2-line residual (`replaceElements(0,1,null)` reporting
`""` where the identical `setElements(null)` end state reports `null`) is an
unreplicable FP state artifact that upstream itself declined to model. Since the
test is upstream-`known_failure` and our harness scores it `ruffle_matched`, it
needs no local doc entry — but a one-line note in
`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (or the avm2 equivalent)
would stop a future session from re-litigating those two lines.

## 8. Reproduction notes

```bash
# refresh the ruffle mirror (read-only; extracts without checkout)
cd ~/CC/ruffle && git fetch origin          # origin/master = e14db71e4
git show origin/master:tests/tests/swfs/avm2/<test>/<file>

# the 4 test dirs are ALREADY installed under
#   ruffle-tests/tests/swfs/avm2/{av_classes,avm1movie_addcallback_call,
#                                 flash_trace,groupelement_text}/
# (gitignored via .gitignore:137 — nothing to commit)

python3 ruffle-tests/verify_output.py --test=flash_trace --diff --verbose
python3 ruffle-tests/verify_output.py --test=groupelement_text --diff --verbose
python3 ruffle-tests/verify_output.py --test=av_classes --diff --verbose
python3 ruffle-tests/verify_output.py --test=avm1movie_addcallback_call --diff --verbose
```
All four were re-run locally at HEAD and reproduce the CI error signatures
byte-for-byte. No float or timeout artifacts were observed.
