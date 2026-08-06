# Session 13 · wave-1 · `w1-trace-singles`

Read-only evidence pass on the four small trace leads carried on
`SWFRecompDocs/plans/polish-sweep-arc.md` §13.3, plus the requested glance at
`mixed_avm/avm2_loads_avm1_v9`. All targets re-run locally at HEAD `10931d62e`
(default no-graphics mode) before diagnosis.

**Headline: 2 GO, 1 GO-with-a-rewrite, 1 documentation-only — and three of the
four §13.3 premises are wrong.**

| # | Lead | §13.3 premise | Verdict at HEAD | Predicted | Effort | Confidence |
|---|---|---|---|---|---|---|
| 1 | `avm2/loaderinfo_quine` | "1004 lines, LoaderInfo.bytes" (implicitly arc-sized) | **GO** — the ByteArray plumbing already works; only the *data* is missing, and the exact bytes are already computed by an existing harness function | +1 (`output_mismatch` → `pass`, 1005 lines) | **S** (~30 lines, 2 files) | **HIGH** (byte-for-byte verified offline) |
| 2 | ImportAssets fetch-queue | "one-liner, `action.c:34563` `entry==NULL` early return" | **Refuted as a one-liner** — the log must be emitted at *preload* time, and the named site runs one frame too late. Still cheap, but it is a recompiler+runtime pair | +1 (`import_assets/avm1_non_swf_import`) | **S** (~15 lines, 3 files, incl. recompiler) | **HIGH** |
| 3 | C3b `MethodInfo-N` naming | "needs ABC debug_name modeling (recompiler item)" | **Premise CONFIRMED and the mechanism PINNED** — s12's "indistinguishable from any data the runtime holds" is refuted: the discriminator is `method_info.name == 0` vs `!= 0`, which our emitter destroys. Perfect 18/18 corpus separation | **0 on its own**; +1 only bundled with the other 3 naming rules | **S** for MethodInfo-N (~6 lines); **M** for the +1 bundle | **HIGH** on the mechanism, **MED** on the bundle |
| 4 | s11 hygiene (`loader_applicationDomain`, `swz`) | "ignore-list recs never applied" | **Partly refuted** — the *suite-local* ignores landed in s11 (`f166e424e`); what is missing is the ACCEPTED_DIFFS entries. Both tests re-verified failing for the documented reason | 0 (hygiene) | **XS** (doc-only) | **HIGH** |
| — | `mixed_avm/avm2_loads_avm1_v9` | "one line from pass, needs AVM1 child execution" | **Confirmed out of reach** — the missing line needs AVM1 child execution **plus** an in-process LocalConnection bridge | — | arc | **HIGH** |

Dispositions checked first for every target: `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt`, and every
suite-local `ignored_tests.txt`. Only `loader_applicationDomain` and `swz`
carry one (`avm2/ignored_tests.txt:94-95`, suite-local — trace-axis only, the
headline corpus figure is the **unfiltered** `effective_pass`, so they still
count as failures there). No other target is ignored or `known_failure`.

---

# Lead 1 — `avm2/loaderinfo_quine` — **GO**

## Verified at HEAD

`output_mismatch`, `expected_lines = 1005`, `matching_lines = 1`.
Run: `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=loaderinfo_quine --diff --verbose`

```
     1  //this.loaderInfo.bytes            (match)
-    2  //length: 1003
+    2  //length: 0
-    3  70   … (1003 byte lines)
+    3  <end of actual>
```

So we return an **empty ByteArray**, not null and not garbage. Everything
except the payload is already right.

## What `LoaderInfo.bytes` must return — settled exactly

The **decompressed** movie image: `"FWS"` + the original version+length bytes +
the inflated body. Not the on-disk file. Ruffle
`avm2/globals/flash/display/loader_info.rs:401 get_bytes` reads
`root.data()`, which is `SwfMovie`'s decompressed image.

Proved for this test offline (no build):

```python
raw = open('.../loaderinfo_quine/test.swf','rb').read()      # 662 bytes, CWS
dec = b"FWS" + raw[3:8] + zlib.decompress(raw[8:])           # 1003 bytes
list(dec) == [int(x) for x in output.txt lines 3..1005]       # -> True
```

**Byte-identical, all 1003.** `test.swf` is 662 bytes on disk; the header's
declared FileLength is already 1003, which is why line 2 wants 1003.

## Our infrastructure can supply it — most of it already exists

Three of the four pieces are already in the tree:

1. **The exact transform**: `ruffle-tests/verify_output.py:1139
   `decompressed_swf_bytes(swf_path)` — handles FWS/CWS/ZWS and returns
   `b"FWS" + raw[3:8] + body`. Its own docstring states the `LoaderInfo.bytes`
   contract. Used today at `:2290` (child SWFs) and `:2357` (self-load).
2. **The C emission pattern**: `verify_output.py:2357-2389` already writes a
   `static const u8 self_swf_bytes[] = {…}` block into `movie_self.c`.
3. **The runtime consumer**: `avm2_display.c:4741 li_get_bytes()` already
   builds a ByteArray from `ext->bytes` / `ext->bytes_len` and pins
   `position = 0`. `Avm2LoaderInfoExt.bytes` is populated for *Loader* streams
   (`:5620-5623`, `:5863`, `:5994`) from `MovieEntry.swf_bytes`
   (`include/libswf/swf.h:418`, "DECOMPRESSED movie image").

**The only gap**: the root/stage LoaderInfo never gets `bytes`.
`loaderinfo_new()` (`avm2_display.c:4492-4514`) sets `expose_content`,
`bytes_loaded`/`bytes_total` (from the `-DSWF_ONDISK_SIZE` define at
`verify_output.py:2466`) and `content_type`, but nothing sets `ext->bytes` for
`LI_KIND_ROOT` / `LI_KIND_STAGE` — there is no generated symbol carrying the
root movie's own image. `movie_self.c` is emitted only when
`get_self_load(test_dir)` is truthy, and `loaderinfo_quine` does not self-load.

## Proposed wave-2 scope — ~30 lines, 2 files, **no recompiler change**

**(a) `ruffle-tests/verify_output.py`** — always generate `root_swf_bytes.c`
into the build dir and always add it to **both** source lists (no-graphics
`~:2110`, graphics-native `~:2709`), next to where `movie_self.c` /
`movie_registry.c` are handled (`~:2315-2395`):

```c
// generated: root movie image for LoaderInfo.bytes
static const unsigned char root_swf_bytes_data[] = { … };
const unsigned char* const g_root_swf_bytes = root_swf_bytes_data;
const unsigned int      g_root_swf_bytes_len = 1003;
```

…and when the gate below says "skip", emit the same file with
`g_root_swf_bytes = 0; g_root_swf_bytes_len = 0;` so the source list never
changes shape.

**(b) `SWFModernRuntime/src/avm2/avm2_display.c`** — weak defaults + one
assignment in `loaderinfo_new()`:

```c
__attribute__((weak)) const unsigned char* const g_root_swf_bytes = 0;
__attribute__((weak)) const unsigned int        g_root_swf_bytes_len = 0;
…
if (kind != LI_KIND_LOADER)
{
    ext->expose_content = 1;
    ext->bytes_loaded = ext->bytes_total = root_swf_size();
    ext->bytes     = g_root_swf_bytes;          // NEW
    ext->bytes_len = g_root_swf_bytes_len;      // NEW
}
```

Weak-symbol precedent already exists in the tree and is proven to work in the
browser/wasm build: `libswf/shape_hit_test.c:67`
(`__attribute__((weak)) float path_data[1][3]`, overridden by generated
`draws.c`) and `actionmodern/action.c:1206` (`extern u16 __attribute__((weak))
text_char_codes[]`).

### The gate is load-bearing — do NOT embed unconditionally

Measured over the whole corpus: **4478 `test.swf` files, 70.4 MB decompressed**
(median 4066 B, max 3.3 MB). Emitting every one as a C initializer list is
~280 MB of generated source. Restricting to the 2468 tests that have a
`RecompiledABC` dir is still 27.2 MB.

**Recommended gate: embed iff the decompressed image contains the ASCII
substring `b"bytes"`.** Measured: **61 of 2468 AVM2 tests, 1.8 MB total**
(≈7 MB of generated C corpus-wide). It is a strict superset of the real need
(any ABC that names the `bytes` property has it in its string pool), and a
false negative degrades to today's behaviour rather than breaking anything.
A hard size cap (e.g. skip > 512 KB) on top costs nothing — the only two
`bytes`-bearing SWFs over that size are `avm2/stage3d_raytrace` (660 KB) and
`avm2/large_preload_from_bytes` (495 KB), neither of which reads the *root*
`bytes`.

### Blast radius — enumerated, and it is exactly one test

Corpus-wide, only **23** tests contain both `bytes` and `loaderInfo`/
`LoaderInfo` in their decompressed image. Of those, the ones that touch a
**root/stage** LoaderInfo are `loaderinfo_properties`,
`stage_loaderinfo_properties`, `loaderinfo_more`, `displayobject_early_init` —
and none of them reads `.bytes`; they read `bytesLoaded`/`bytesTotal`/
`bytesAvailable` only (checked in their `output.txt` and `.as` sources).
A grep of every AVM2 `output.txt` for `.bytes` (excluding
`bytesLoaded|bytesTotal|bytesAvailable`) returns **only** `loaderinfo_quine`
plus seven `contentLoaderInfo.bytes` lines that belong to the Loader path this
patch does not touch.

### Canary list (mode=graphics, categories=all, images=false)

Target: `avm2/loaderinfo_quine`.
Must stay `pass`: `avm2/loaderinfo_properties`,
`avm2/stage_loaderinfo_properties`, `avm2/loaderinfo_more`,
`avm2/loader_events`, `avm2/loader_bytes_unknown_content`,
`avm2/loader_loadbytes_events`, `avm2/loader_reuse`,
`from_shumway/as3-loader/{LoaderTest,LoaderLoadBytesTest,LoaderLoadBytesTest2}`.
Cheap size/compile smoke (largest `bytes`-bearing SWFs, must not time out):
`avm2/stage3d_raytrace`, `from_shumway/esc`.

### Follow-up, explicitly NOT required for the flip

The principled home for this is the **recompiler** (`SWFRecomp` already holds
the decompressed buffer, and only that path fixes `LoaderInfo.bytes` for
`deploy_example.sh` / browser builds). Gate it there on "the ABC string pool
contains `bytes`", which the recompiler can evaluate exactly. Doing it in the
harness first is strictly cheaper (no cmake, no generated-table ABI churn) and
banks the same +1.

---

# Lead 2 — ImportAssets fetch-queue — **GO, but the §13.3 one-liner is wrong**

## Verified at HEAD

Test is `import_assets/avm1_non_swf_import` (the only ImportAssets test with
`log_fetch = true` that expects a fetch; `empty_url` also sets `log_fetch` and
expects **none**).

```
--- avm1_non_swf_import (expected vs actual) ---
-    1  Navigator::fetch:          +    1  frame 1
-    2    URL: dummy.png           +    2  frame 2
-    3    Method: GET              +    3  frame 3
-    4  frame 1                    +    4  <end of actual>
```

True edit distance **3** (the whole fetch block, prepended). Our three trace
lines are already correct.

## The named site is real but one frame too late — REFUTED as a one-liner

`action.c:34580` (§13.3 says 34563; the line has drifted at HEAD) is indeed
`if (entry == NULL) return;` inside `actionImportAssets`. But queueing the
fetch there emits it in the **wrong place**:

* The tag stream (parsed offline) is
  `frame0: DoAction, ShowFrame | frame1: **ImportAssets2(57)**, DoAction, ShowFrame | frame2: DoAction, ShowFrame`.
  The generated `RecompiledTags/tagMain.c:19` puts
  `actionImportAssets(app_context, "dummy.png")` at the top of `frame_1`,
  i.e. **after** `script_0` has already traced `frame 1`.
* Ruffle emits it before everything because it handles `TagCode::ImportAssets2`
  inside **`MovieClip::preload`** (`movie_clip.rs:481 fn preload`, dispatch at
  `:567-572`, body at `:753`), which scans the whole tag stream at load time —
  before frame 1's DoAction runs.

So a queue-at-the-call-site fix produces `frame 1 / Navigator::fetch… / frame 2
/ frame 3` and the test still fails.

## Ruffle's exact rule (to replicate)

`movie_clip.rs:753-796 fn import_assets`:

```rust
let asset_url = url.to_string_lossy(UTF_8);
// FP does not attempt to load the url if it is empty
if asset_url.is_empty() { return Ok(()); }
… register_import(name, id) for each asset …
let request = Request::get(asset_url);       // <- the logged GET
```

Note the empty-URL guard: that is what keeps `import_assets/empty_url`
(currently **pass**, `actionImportAssets(app_context, "")`) fetch-free.
Ruffle issues the request for *every* non-empty URL — including one that
resolves to a recompiled child SWF; `avm1_imports_avm1` simply has no
`log_fetch` in its `test.toml`, so nothing is graded there.

## Proposed wave-2 scope — ~15 lines, 3 files

**(1) `SWFRecomp/src/swf.cpp`**, in the `SWF_TAG_IMPORT_ASSETS` /
`SWF_TAG_IMPORT_ASSETS_2` case (~4838-4872), add one line **alongside** the
existing per-frame emission (do not move it — the frame-1 `actionImportAssets`
call is load-bearing for imported-sprite bounds). `tag_init` is already in
scope in that switch (the adjacent `DoExportAssets` case writes to it at
`:4823`):

```cpp
tag_init << endl << "\tactionPreloadImportAssets(app_context, \""
         << import_url << "\");";
```

`tag_init` is flushed into `tagInit()` at `swf.cpp:876`, and `tagInit` is
called before frame 0 (`libswf/swf_core.c:882`, `libswf/swf.c:1689`) — exactly
Ruffle's preload window.

**(2) `SWFModernRuntime/src/actionmodern/action.c`**, next to
`actionImportAssets` (~:34576):

```c
// Ruffle issues the ImportAssets GET during preload (movie_clip.rs::preload),
// i.e. before ANY frame script runs — hence tagInit, not the frame body.
void actionPreloadImportAssets(SWFAppContext* app_context, const char* url)
{
	(void) app_context;
#if SWF_LOG_FETCH_ENABLED
	if (url == NULL || url[0] == '\0') return;   // FP skips an empty URL
	swf_log_fetch_queue(url, strlen(url), "GET", 3,
	                    NULL, 0, NULL, 0, NULL, 0, 0, 0);
	swf_log_fetch_flush();
#else
	(void) url;
#endif
}
```

Signature and queue/flush-immediately idiom copied verbatim from the AVM1
precedent at `actionmodern/avm1_amf.c:1745-1752`
(`SWF_LOG_FETCH_ENABLED` is defined at `include/utils.h:40/42`;
`swf_log_fetch_queue`/`_flush` at `src/utils.c:176-231`).

**(3)** Declare `actionPreloadImportAssets` in whichever runtime header the
generated `tagMain.c` already sees (the same one that declares
`actionImportAssets`, reached via `recomp.h`).

## Predicted flips

`import_assets/avm1_non_swf_import`: `output_mismatch` → **`pass`**, **+1**.
Nothing else — the whole ImportAssets path is used by exactly three tests
(`avm1_imports_avm1`, `avm1_non_swf_import`, `empty_url`) and by nothing else
in the corpus.

**Do NOT bundle the donor-script-suppression half** (`avm1_imports_avm1`'s
extra `Hello from right_eye.swf` line). That is an AVM1 execution-path change
inside the load-bearing frame-0 replay; s12's `w2-xs` agent declined it for
good reason and this patch does not touch it.

## Canary list

`import_assets/{avm1_non_swf_import, empty_url, avm1_imports_avm1}` — all
three, every time. `empty_url` is the guard on the empty-URL branch;
`avm1_imports_avm1` must not gain a fetch line (it has no `log_fetch`, so it
must stay byte-identical) and it carries `[image_comparisons]`, so it is on the
pixel board too. Plus two `log_fetch` smoke tests from the 24 existing users of
`swf_log_fetch_*` (e.g. `avm1/loadvariables*`).

**CI note for the integrator: this is a recompiler change.** Wave 2 must
rebuild `SWFRecomp` with cmake and pass `--recompile`; CI will invalidate the
generated-table caches corpus-wide, so expect a slow run. Mode `graphics`,
categories `all` (no ABC emission change).

---

# Lead 3 — C3b `MethodInfo-N` naming — mechanism PINNED, s12's refutation overturned

## Verified at HEAD

`avm2/error_stack_trace`: `output_mismatch`, 45 expected / 38 matching — the
gap is exactly **7 lines**, in **four** distinct naming rules:

```
-    2  	at Test$cinit()          +   at Test/<anonymous>()      (rule 1: class initializer)
-    6  	at MethodInfo-1()        +   at Function/<anonymous>()  (rule 2)
-    7  	at MethodInfo-2()        +   at Function/<anonymous>()  (rule 2)
-   21  	at Test/uri::f()         +   at Test/f()                (rule 3: namespaced trait name)
-   29  	at Test$/class_method()  +   at Test/class_method()     (rule 4: static method)
-   38  	at Test$/class_method()  +   at Test/class_method()     (rule 4)
-   43  	at Test$/class_method()  +   at Test/class_method()     (rule 4)
```

The +1 needs **all four**. No `output.ruffle.txt` exists, so `ruffle_matched`
is not available — it is `pass` or nothing.

## s12's refutation is overturned: the discriminator IS in the ABC

`session12-fanout-reports/w2-errframes-report.md:205-231` declared C3b
unimplementable because `error_stack_trace` and `proxy_not_overridden` both
show `debug_name = ""` in their generated method tables, so "the two cases are
indistinguishable from any data the runtime holds".

That is true of the *emitted* tables and false of the *ABC*. Ruffle's rule
(`core/src/avm2/function.rs:359-372` + `method.rs:336-351`):

```rust
} else if method.is_function() && let Some(method_name) = method.method_name() {
    output.push_utf8("Function/");
    if !method_name.is_empty() { … } else { output.push_utf8("<anonymous>"); }
} else {
    output.push_utf8("MethodInfo-");
    output.push_utf8(&method.abc_method_index().to_string());
}
```

```rust
pub fn method_name(&self) -> Option<Cow<'_, str>> {
    let name_index = self.method().name.0 as usize;
    if name_index == 0 { return None; }        // <-- THE DISCRIMINATOR
    … strings[name_index - 1] …
}
```

`method_info.name == 0` (the ABC "no name" index) → `None` → **`MethodInfo-N`**.
`name != 0` pointing at the empty string → `Some("")` → **`Function/<anonymous>`**.

Our emitter collapses both to `""`. `SWFRecomp/src/abc/abc_emit.cpp:3844`:

```cpp
out << ", \"" << escapeCString(abc.pool.strings[m.name]) << "\", "
```

`AbcMethod::name` (`SWFRecomp/include/abc/abc_types.hpp:165`) is the raw string
pool index, so index 0 and "index → empty string" become the same C literal.
**§13.3's "needs ABC debug_name modeling (recompiler item)" label is exactly
right** — and it is a two-line emitter change, not a modelling project.

### The corpus separation is perfect — 18/18, zero counterexamples

I wrote a standalone ABC parser (constant pool → `method_info.name`) and ran it
over every corpus test whose `output.txt` **or** `output.ruffle.txt` contains
`at Function/<anonymous>()` or `at MethodInfo-N()`
(script kept at `<scratchpad>/abcscan.py`):

| expects | tests | `name_idx == 0` methods | `name_idx != 0` methods |
|---|---|---|---|
| `MethodInfo-N` | `avm2/error_stack_trace`, `avm2/sprite_dropTarget`, `from_avmplus/as3/Array/length_mods`, `from_avmplus/as3/RegExp/replace`, `from_avmplus/ecma3/Number/e15_7_4_7_1` | **all** (14 / 6 / 68 / 30 / 32) | **0** |
| `Function/<anonymous>` | `avm2/{error_throwerror, event_handler_exception, function_display_anonymous, graphics_draw_path, graphics_path, number_convert_errors, primitive_toString, primitive_valueOf, proxy_not_overridden, stage_properties2, tabstop_properties, textline_throwerror, uncaught_errors_stringified}` | **0** | **all** |

Every `MethodInfo-N` test is a Flash-IDE (`test_fla`) SWF whose ASC emits
`name = 0` for all 14/68/… methods; every `Function/<anonymous>` test is an
mxmlc/ASC `Test.as$1` build whose methods all carry `name = 2` → `""`.

**Two hypotheses I tested and refuted along the way** (both fit the two-test
sample in the s12 report and both are wrong corpus-wide):
* *"return type / untyped signature"* — `error_stack_trace` m1/m2 are
  `(pc=0, ret_mn=0)` and `proxy`'s are `(pc=0, ret_mn=3 /* void */)`, which
  looks decisive until `tabstop_properties` (**pass**, expects
  `Function/<anonymous>`) turns out to have 37 closures at `(pc=0, ret_mn=0)` —
  byte-identical `Avm2AbcMethodData` rows to `error_stack_trace`'s.
* *"the ABC has real per-method debug names we are dropping"* — no. Every
  method in every one of these SWFs resolves to the empty string. The
  information is the *presence of the index*, not its contents.

## Proposed wave-2 scope

### Rule 2 alone — ~6 lines, but worth **0 flips on its own**

Recompiler, `SWFRecomp/src/abc/abc_emit.cpp:3844`:

```cpp
out << ", ";
if (m.name == 0) out << "NULL";                      // ABC "no name" index
else out << "\"" << escapeCString(abc.pool.strings[m.name]) << "\"";
out << ", ";
```

Runtime, `SWFModernRuntime/src/avm2/avm2_error.c:196-202`
(`avm2_callstack_frame_name`, the `md->is_function` branch) — everything else
it needs is already there (`m->method_index`, `m->file->data->methods[]`):

```c
const Avm2AbcMethodData* md = &m->file->data->methods[m->method_index];
if (md->is_function && md->debug_name != NULL) { …existing Function/… }
if (md->is_function) { snprintf(buf, size, "MethodInfo-%u()", m->method_index); return; }
```

**Blast radius: zero regression candidates.** Every corpus test that prints
`Function/<anonymous>` has `name_idx != 0` on all methods, so none of them
changes. The four `MethodInfo-N` tests other than the target are all
**`ruffle_matched`** today (`avm2/sprite_dropTarget`,
`from_avmplus/as3/Array/length_mods`, `from_avmplus/as3/RegExp/replace`,
`from_avmplus/ecma3/Number/e15_7_4_7_1`); the change moves them *toward*
`output.ruffle.txt`, so it is neutral-to-positive there. Audit the other
readers of `md->debug_name` / `Avm2MethodRef.debug_name` for NULL-safety before
shipping — the emitter change makes a previously always-non-NULL field
nullable, which is the one real hazard in this patch.

### The +1 bundle — rules 1, 3, 4 must ship with it

All three are runtime-side in the same function (`avm2_error.c:144-209`), all
against data we already emit:

* **Rule 1 — `Test$cinit()`**: Ruffle `function.rs:317-325` — when the frame's
  method is the bound class's *class* initializer and the class is a c_class,
  print `<QName>$cinit`. `Avm2AbcClassData.class_init`
  (`include/avm2/avm2_abc.h`) is emitted; our `is_iinit` check at
  `avm2_error.c:153-156` only compares `instance_init`.
* **Rule 3 — `Test/uri::f()`**: Ruffle `function.rs:345-348` — if the trait
  name's namespace `is_namespace()`, print the qualified name. Our
  `m->file != NULL` branch (`avm2_error.c:171-175`) actively *strips* after the
  last `/` and `:`, which is what deletes `uri::`. Needs the strip to be
  namespace-aware rather than unconditional.
* **Rule 4 — `Test$/class_method()`**: a *static* (class-trait) method must be
  prefixed with the **c_class** name (`Test$`), not the instance class name.
  Requires knowing the frame's bound class is the c_class half.

**Effort M (~60-80 lines across `abc_emit.cpp` + `avm2_error.c`), one agent,
one commit — land-together-or-drop**, because 6 of the 7 lines come from rules
1/3/4 and none of them alone moves the test.

Canaries (all currently `pass`/`ruffle_matched`, all frame-name printers):
`avm2/{error_stack_trace_edge_cases, error_throwerror, error_geterrormessage,
proxy_not_overridden, function_display_anonymous, tabstop_properties,
stage_properties2, graphics_path, graphics_draw_path, textline_throwerror,
primitive_toString, primitive_valueOf, uncaught_errors_stringified,
number_convert_errors, sprite_dropTarget, coerce_property}` +
`from_avmplus/{as3/Array/length_mods, as3/RegExp/replace,
ecma3/Number/e15_7_4_7_1}`.

**CI: recompiler change → cmake rebuild, `--recompile`, corpus-wide cache
invalidation. Mode `graphics`, categories `full`** (this *is* an ABC-emission
change).

### GO / NO-GO

**GO on the mechanism, GO on rules 1/3/4 as one M-sized bundle, NO-GO on
shipping rule 2 alone** (0 flips, and it costs a full recompile). If wave 2
has room for exactly one M item, this is a clean +1 with a proven-empty blast
radius. Strike "needs ABC debug_name modeling" as a *blocker* from §13.3 and
re-file it as "the emitter must preserve `name == 0` as NULL".

---

# Lead 4 — s11 hygiene: `avm2/loader_applicationDomain`, `avm2/swz`

## What is actually missing (the §13.3 premise is half wrong)

The **suite-local** ignores DID land, in the s11 closeout `f166e424e`
(`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:92-95`). What never happened
is the ACCEPTED_DIFFS entry that CLAUDE.md requires alongside them.

**Recommendation on the global list: do NOT add these two to
`ruffle-tests/ignored_tests.txt`.** That file's own header (lines 15-21)
records that a global entry is *also an image-axis disposition*
(`scripts/image_triage.py` returns `image_axis=True` for a global entry, and
`image_axis=False`, "kept on the board", for suite-local ones). Neither test
carries `[[image_comparisons]]`, so a global entry buys nothing and mislabels
the pixel board. The suite-local entries are the correct disposition; only the
prose is owed.

## Both re-verified failing for the documented reason

| test | run at HEAD | expected | actual |
|---|---|---|---|
| `avm2/loader_applicationDomain` | `output_mismatch`, 4 expected / **0** matching | `[class PropertyChangeEvent]` / `[class ByteArrayAsset]` / `[class Test]` / `[class Test]` | one empty line, then nothing |
| `avm2/swz` | `output_mismatch`, 2 expected / **0** matching | `[class ByteArrayAsset]` / `[class BitmapAsset]` | one empty line, then nothing |

Both `Test.as` files were read: each `URLLoader.load()`s
`framework_4.5.0.20967.swz` (a real 325 305-byte Adobe Flex framework SWZ
shipped in the test directory, with a SHA-256 `digest` pin), then
`Loader.loadBytes()` it and reads `mx.*` classes out of the resulting
ApplicationDomain. Nothing is traced until those classes resolve, hence 0
matching lines. Under AOT recompilation there is no runtime ABC
interpreter/JIT, so a SWZ fetched at runtime can never define classes.
Reference: `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md:476`
("Won't-do: `loader_applicationDomain` (needs the real Flex framework SWZ)")
and the loader-arc tranche-6 scoreboard.

## Draft entries — ACCEPTED_DIFFS.md (do not apply this session)

They belong in `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`
— despite the path, that is the corpus-wide doc (it already carries
`from_avmplus/*` and `from_shumway/*` entries). There is no avm2-local
ACCEPTED_DIFFS.md; do **not** create one.

New category, appended after Category 12:

```markdown
## Category 13: AOT Ceiling — Runtime-Loaded ABC (Flex `framework_*.swz`)

SWFRecomp is an ahead-of-time recompiler: every ABC in the corpus is
translated to C at build time. A SWF fetched *at runtime* and handed to
`Loader.loadBytes()` therefore cannot define classes — there is no bytecode
interpreter in the runtime to execute it. Two avm2 tests load the real
325 305-byte Adobe Flex `framework_4.5.0.20967.swz` (shipped in the test
directory, pinned by a SHA-256 `URLRequest.digest`) and then read `mx.*`
definitions back out of an ApplicationDomain. Both are permanent won't-dos.

This is a *ceiling*, not a bug: closing it would mean shipping an AVM2
interpreter alongside the recompiled code, which is the opposite of the
project's AOT design (`swfrecomp-purpose-beat-ruffle-perf`).

### `avm2/loader_applicationDomain` — Flex framework SWZ (4 diff lines of 4)

`Test.as` `URLLoader`s `framework_4.5.0.20967.swz` as BINARY, `loadBytes()`s
it into `ApplicationDomain.currentDomain`, and traces
`getDefinitionByName("mx.events.PropertyChangeEvent")`,
`getDefinitionByName("mx.core.ByteArrayAsset")` and `getDefinitionByName("Test")`
twice (once through the shared domain, once through a domain-less child
Loader).

```
expected:                          actual:
[class PropertyChangeEvent]        (no output)
[class ByteArrayAsset]
[class Test]
[class Test]
```

Every traced value depends on `mx.*` classes that exist only inside the SWZ's
ABC. Nothing is traced before them, so the test produces 0 matching lines.

**Decision: accept permanently.** Listed in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`. Suite-local, deliberately —
the test has no `[[image_comparisons]]`, so a global entry would wrongly
disposition a pixel-axis row (see that file's header, traps 1-2).
See `avm2/_investigation/CURRENT_STATUS.md:476` and the loader-arc tranche-6
scoreboard.

### `avm2/swz` — Flex framework SWZ, domain-relative lookup (2 diff lines of 2)

Same SWZ, same fetch, but reads the definitions off the *child* Loader's
`contentLoaderInfo.applicationDomain`:

```
expected:                          actual:
[class ByteArrayAsset]             (no output)
[class BitmapAsset]
```

Identical mechanism and identical ceiling.

**Decision: accept permanently.** Listed in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` (suite-local, same rationale).
```

Summary-table rows to append:

```markdown
| `avm2/loader_applicationDomain` | AOT ceiling: runtime-loaded Flex `framework_*.swz` ABC (Category 13) | 4 of 4 | Accept; would require shipping an AVM2 interpreter |
| `avm2/swz` | AOT ceiling: runtime-loaded Flex `framework_*.swz` ABC (Category 13) | 2 of 2 | Accept; same mechanism as `loader_applicationDomain` |
```

## Ignore-list lines

Already present, verbatim, at
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:92-95`:

```
# 2026-08-05 s11 wave-1 triage: recorded won't-dos (need the real Flex
# framework_*.swz executed under AOT — impossible; see avm2
# CURRENT_STATUS.md:476 and loader-arc tranche-6 scoreboard).
loader_applicationDomain
swz
```

Recommended amendment when the ACCEPTED_DIFFS entries land — append one line so
the two files cross-reference:

```
# Documented in avm1/_investigation/ACCEPTED_DIFFS.md Category 13 (2026-08-06).
```

**No global `ruffle-tests/ignored_tests.txt` lines are recommended** — see
above.

---

# Glance — `mixed_avm/avm2_loads_avm1_v9` — **confirmed out of reach**

Verified at HEAD: `output_mismatch`, 7 of 8 lines match. The single missing
line is the last one, `(inner swf) x set, new value: 99`.

The §13.3 label ("needs AVM1 child execution") **understates** it. Dumping the
179-byte `avm1.swf`'s string pool gives:

```
b'connection', b'LocalConnection', b'mixed_avm_v9-connection', b'connect',
b'setX', b'(inner swf) x set, new value: '
```

So producing that line needs **both**:
1. the AVM1 child SWF's frame script to actually execute inside an AVM2 host
   (the declared multi-SWF child-frame-execution blocker — polish-sweep-arc
   §1 "Deferred", `mixed_avm/*` row), **and**
2. an in-process **LocalConnection** bridge between the AVM2 root and the AVM1
   child, so the AVM2 `content.x = 99` write reaches the child's `setX`
   handler. Standing memory `avm2-localconnection-silent-blank-stage` records
   LocalConnection as its own unfinished surface.

Two independent arc-sized subsystems for one line. **Refute "one line from
pass" as a staffing signal** — it is one line from pass *and* two arcs from
implementable. Not a wave-2 item; leave it in the dual-VM arc and do not scope
it.

---

# Cross-cutting notes for the arc doc

* **Three of four §13.3 parentheticals were wrong, in both directions.** The
  ImportAssets "one-liner" is not one (the site is a frame too late); the s11
  hygiene "never applied" was half-applied; `loaderinfo_quine` was implicitly
  arc-sized and is S. The one that was *right* — "C3b needs ABC debug_name
  modeling" — is the one a previous wave-2 agent had declared **impossible**.
  Consistent with `worklist-labels-name-symptoms-not-owners`, and a new
  corollary: a §13.x line is also not a *refutation*; re-derive both directions.
* **`Option<T>` vs `""` is a real semantic axis our tables flatten.** The C3b
  discriminator was invisible for a full session because
  `abc.pool.strings[0]` and a pool entry that happens to be empty emit the same
  C literal. Worth a sweep: any other place `abc_emit.cpp` writes
  `pool.strings[idx]` without distinguishing `idx == 0` has the same latent
  bug.
* **Parsing the raw ABC beats reading the generated tables** when the question
  is "is the data there?". s12's B6 refutation used the generated tables to
  prove data *was* present; this session needed a 60-line standalone ABC parser
  to prove data was *lost in emission*. Both are build-free; keep both in the
  toolkit. Script: `<scratchpad>/abcscan.py`.
* **Corpus-scale sanity-check any "embed the SWF" idea.** 4478 test SWFs =
  70.4 MB decompressed; a substring gate on the payload cut the
  `loaderinfo_quine` fix from 280 MB of generated C to ~7 MB. Measure before
  designing the gate.

## Verification commands used (all single-test, ≤2 concurrent)

```
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=loaderinfo_quine --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/import_assets --test=avm1_non_swf_import --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=loader_applicationDomain --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=swz --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=error_stack_trace --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/mixed_avm --test=avm2_loads_avm1_v9 --diff --verbose
```
