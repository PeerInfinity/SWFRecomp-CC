# Session 13 · wave-2 · `w2-trace-singles`

All **three** GO items from `wave1-trace-singles.md` landed. Three target tests
flip `output_mismatch` → `pass`; **72 canaries (75 tests run, 3 of them the
targets) are identical to their CI baseline** on both status and the
actual/expected/matching line triple. Zero regressions.

| # | Item | Target | Baseline | After | Files |
|---|---|---|---|---|---|
| 1 | `LoaderInfo.bytes` for the root movie | `avm2/loaderinfo_quine` | `output_mismatch` 2/1005/1 | **`pass`** 1005/1005/1005 | `verify_output.py`, `avm2_display.c` |
| 2 | ImportAssets preload fetch | `import_assets/avm1_non_swf_import` | `output_mismatch` 3/6/0 | **`pass`** 6/6/6 | `swf.cpp`, `action.c`, `action.h` |
| 3 | C3b naming bundle (4 rules) | `avm2/error_stack_trace` | `output_mismatch` 45/45/38 | **`pass`** 45/45/45 | `abc_emit.cpp`, `avm2_class.{c,h}`, `avm2_error.c` |

Patch: `w2-trace-singles.patch` (9 files, +204/−10, includes the harness change).
Nothing was committed. Built and run in the isolated worktree
`.claude/worktrees/agent-a1a553cd40c99172f` with a **fresh cmake build of
SWFRecomp** (never the main tree's `SWFRecomp/build`).

---

## Item 1 — `LoaderInfo.bytes` returns the root movie's decompressed image

Implemented exactly as the wave-1 brief scoped it, with one correction the
brief could not have predicted (below).

**`ruffle-tests/verify_output.py`** — new `generate_root_swf_bytes(test_dir,
build_dir)` next to `decompressed_swf_bytes()`, called from `compile_native()`
right after the `movie_self.c` / `movie_registry.c` block. It writes
`root_swf_bytes.c` into the build dir on **every** build (null/0 when the gate
says skip) so the generated source set has a constant shape.

*No source-list edit was needed*: both the no-graphics and graphics-native
builds share `compile_native`, whose source list is
`sorted(build_dir.glob("*.c"))` (`:2582`). The brief's "add it to both source
lists (~:2110, ~:2709)" is therefore moot — `:2709` is `compile_wasm`, a
different function, which is deliberately left alone (WASM builds fall back to
the weak null default, i.e. today's behaviour).

**The gate is in and is load-bearing**, per the brief: embed iff the
decompressed image contains ASCII `b"bytes"`, plus a hard 512 KB cap. Verified
on the target: `test.swf` 662 B CWS → 1003 B decompressed, `b"bytes"` present.

**`SWFModernRuntime/src/avm2/avm2_display.c`** — weak defaults above
`loaderinfo_new()`, and `ext->bytes` / `ext->bytes_len` set alongside the
existing `bytes_loaded`/`bytes_total` for `kind != LI_KIND_LOADER`.

### Finding the brief did not have: `const` + `weak` = silently folded

The brief's suggested declaration —

```c
__attribute__((weak)) const unsigned char* const g_root_swf_bytes = 0;
```

— **does not work at `-O2`**. A const-qualified weak *object* with an
initializer is constant-folded inside its own TU: `objdump -r avm2_display.o`
showed **zero relocations** against `g_root_swf_bytes`, so `loaderinfo_new`
read a hard-coded 0 even though the generated `root_swf_bytes.c` provided a
strong `D`-class definition that the linker did select. First run still printed
`length: 0`.

Fix (shipped, with the reason in a comment so it isn't "cleaned up" later): the
symbols are **not** const-qualified objects on either side —

```c
__attribute__((weak)) const unsigned char* g_root_swf_bytes = 0;
__attribute__((weak)) unsigned int         g_root_swf_bytes_len = 0;
```

This is why the tree's existing weak-override precedent (`shape_hit_test.c`'s
`float path_data[1][3]`) is non-const. **Generalisable rule: a weak default
that a generated TU overrides must never be a `const` object.**

Follow-up (unchanged from the brief, still NOT required for the flip): the
principled home is the recompiler, which owns the decompressed buffer and would
also fix `LoaderInfo.bytes` for `deploy_example.sh` / browser builds.

## Item 2 — ImportAssets fetch at preload time

`SWFRecomp/src/swf.cpp`, `SWF_TAG_IMPORT_ASSETS` / `_2` case: one
`tag_init <<` line **alongside** (not replacing) the existing
`current_frame_init_actions` emission, so the frame-1 `actionImportAssets`
call — load-bearing for imported-sprite bounds — is untouched.

`SWFModernRuntime/src/actionmodern/action.c`: new
`actionPreloadImportAssets(SWFAppContext*, const char*)` immediately above
`actionImportAssets` (~:34576, far from the `setMask` region at :70653),
with Ruffle's empty-URL guard and the `swf_log_fetch_queue` + `_flush`
idiom copied from `avm1_amf.c:1745`. Declared in
`include/actionmodern/action.h` next to `actionImportAssets`.

Result: `Navigator::fetch:` / `URL: dummy.png` / `Method: GET` now precede
`frame 1`, exactly as Ruffle's `MovieClip::preload` produces them.

### Build gotcha worth recording

`cmake --build` reported `Built target SWFRecomp` **without recompiling**
`swf.cpp`: a background build launched earlier had compiled the old
`swf.cpp` and then linked at a timestamp *newer* than my edit, so make
considered the binary up to date. The generated `tagMain.c` had no
`actionPreloadImportAssets` line and the test still failed — a false
"the emission doesn't work" signal. `touch`ing the source and rebuilding fixed
it. **Always verify a recompiler change reached the binary**
(`strings SWFRecomp/build/SWFRecomp | grep <new symbol>`) before believing a
negative test result.

## Item 3 — C3b naming bundle (all four rules; land-together-or-drop met)

All four rules implemented; `error_stack_trace` passes, so the bundle stays.

**Rule 2 (`MethodInfo-N`) — recompiler.** `abc_emit.cpp:3844` now emits `NULL`
for `method_info.name == 0` instead of `escapeCString(pool.strings[0])`, which
had collapsed "no name" and "name → empty string" into the same `""`.
`avm2_error.c`'s `md->is_function` branch prints `MethodInfo-%u` (the ABC
method index) only when **both** the method-table `debug_name` and the frame's
own `debug_name` are NULL. Every reader of `debug_name` in the runtime was
audited first — all were already NULL-safe (`avm2_class.c:693/1044/1528`,
`avm2_function.c:37-65/202`, `avm2_error.c:168/187/192/199/203`).

**Rule 1 (`Test$cinit`) — runtime.** Ruffle models the static side as a
separate c_class whose *instance* init is the cinit; we keep one `Avm2Class`,
so the class's static initializer ref is now remembered on it:
new `Avm2Class.class_init` (`avm2_class.h`), filled next to `instance_init` in
the ABC class-define path (`avm2_class.c:~1300`), and the existing local
`cinit_ref` at the NewClass call site now just reads it. `avm2_callstack_frame_name`
checks it before the `is_iinit` check. Every `Avm2Class` allocation in the tree
`memset`s to 0 (5 sites, all verified), and the check requires
`m->file != NULL`, so builtins can never false-positive.

**Rule 3 (`Test/uri::f`) — runtime.** Two halves:
* `avm2_vtable_add_traits`' trait-QName fallback now prefixes `uri::` when the
  trait key's namespace is ABC kind **0x08** (a user `namespace ns = "uri"`)
  with a non-empty URI. Package/package-internal/protected/private
  (0x16-0x1a, 0x05) keep the local name, matching Ruffle's
  `Namespace::is_namespace()`.
* The frame renderer's unconditional "strip after the last `:`" (which exists
  for mxmlc's single-colon package prefixes, `test_fla:MainTimeline/test_fla:frame1`)
  is now skipped when the name contains `::`. Single-colon mxmlc names are
  unaffected — verified by `tabstop_properties` and `stage_properties2` staying
  byte-identical.

**Rule 4 (`Test$/class_method`) — runtime.** New static helper
`frame_is_class_trait(cls, m)` scans `cls->class_object->vtable` (our analogue
of Ruffle's c_class traits) for an entry whose method/setter ref matches the
frame; a hit switches the format to `"%s$/%s()"`. Guarded on `m->file != NULL`
so native class-side frames (which use `avm2_callstack_rename_frame`) are
untouched.

### Independent corroboration of rules 1/3/4

`SWFRecomp/src/abc/abc_verifier.cpp:120-160` — the *recompile-time* namer used
for verify-error frames — **already** implements `Class$cinit()`, `Class$/m()`,
`Class/get m()` and `global$init()`. The runtime renderer was simply behind it.
That is also why `avm2/array_access_oob_interpreter` already prints
`at Test$cinit()` today (its trace comes from the verifier path). Runtime and
recompiler now agree; the wave-1 report's Ruffle citations and this second,
in-tree implementation independently derive the same four rules.

---

## Canary ledger

Every canary was re-run in this worktree with `--recompile` (mandatory: the
recompiler changed) and compared to the main tree's CI baseline
`_results/results_graphics.json` on **both** status and the
actual/expected/matching line triple. `<<<` marks the only changes.

### avm2 — brief's list + LoaderInfo/display (25 run)

| test | baseline → after |
|---|---|
| `loaderinfo_quine` | `output_mismatch` 2/1005/1 → **`pass`** 1005/1005/1005 `<<<` |
| `error_stack_trace` | `output_mismatch` 45/45/38 → **`pass`** 45/45/45 `<<<` |
| `loaderinfo_properties`, `stage_loaderinfo_properties`, `loaderinfo_more`, `loader_events`, `loader_bytes_unknown_content`, `loader_loadbytes_events`, `loader_reuse` | `pass` → `pass`, identical lines |
| `error_stack_trace_edge_cases`, `error_throwerror`, `error_geterrormessage`, `proxy_not_overridden`, `function_display_anonymous`, `tabstop_properties`, `stage_properties2`, `graphics_path`, `textline_throwerror`, `primitive_toString`, `primitive_valueOf` | `pass` → `pass`, identical lines |
| `graphics_draw_path`, `uncaught_errors_stringified`, `sprite_dropTarget`, `coerce_property` | `ruffle_matched` → `ruffle_matched`, identical lines |
| `number_convert_errors` | `output_mismatch` 685/871/40 → identical |

### avm2 — full stack-frame blast radius (35 run, extended beyond the brief)

I enumerated **every** corpus test whose `output.txt` or `output.ruffle.txt`
contains a `\tat ` frame (55 tests, `grep -rl` over all suites) — that set is
the complete blast radius of a frame-naming change — and ran the 35 avm2 ones
not already covered above, plus the two large-SWF compile smokes.

**35 tests, 0 changed** — every status and every line triple identical to
baseline:
`abstract_classes`, `accessibilityimplementation`, `array_access_oob_interpreter`,
`avm1movie_addcallback_call`, `bitmapdata_zero_size`, `bytearray_oom`,
`content_element_basic`, `context3d_creation`, `edittext_default_format_empty`,
`element_format_constructor_order`, `element_format_properties`,
`event_handler_exception`, `freestanding_superclass`, `loader_error_in_root_ctor`,
`loader_load`, `loader_method`, `pixelbender_{ceil,conditional,eof,no_out_param,sign}`,
`stage3d_agal_upload_errors`, `system_exit`, `text_element_basic`,
`textblock_{createline_errors,properties,recreateline}`, `textformat_display`,
`textline_validity`, `timer_invalid_delay`, `try_catch_typed`,
`uncaught_error_basic`, `xml_list_ctor_errors`,
plus the two **size/compile smokes** for item 1's gate:
`large_preload_from_bytes` (495 KB image → embedded, compile 31.5 s, no
timeout) and `stage3d_raytrace` (660 KB → skipped by the 512 KB cap, compile
114 s, `pass`, unchanged).

`array_access_oob_interpreter` is the second `$cinit`-bearing test in the
corpus and it stayed `ruffle_matched` with identical lines — its trace comes
from the recompile-time verifier namer, which already spelled the rule this
way.

### import_assets (3) / avm1 log_fetch smokes (2)

| test | baseline → after |
|---|---|
| `avm1_non_swf_import` | `output_mismatch` 3/6/0 → **`pass`** 6/6/6 `<<<` |
| `empty_url` | `pass` 2/2/2 → `pass` 2/2/2 (empty-URL guard holds) |
| `avm1_imports_avm1` | `output_mismatch` 7/6/0 → identical (no fetch line gained; it has no `log_fetch`) |
| `avm1/loadvariables`, `avm1/loadvariables2` | `pass` → `pass` |

### from_shumway/as3-loader (3) — LoaderInfo.bytes path

`LoaderTest` `ruffle_matched` 9/9/7, `LoaderLoadBytesTest` `output_mismatch`
3/4/1, `LoaderLoadBytesTest2` `pass` 3/3/3 — all identical to baseline.

### from_avmplus (7) — naming rules + `at`-frame set

`as3/Array/length_mods`, `as3/RegExp/replace`, `ecma3/Number/e15_7_4_7_1`
(the three `MethodInfo-N` corpus tests), `e4x/XML/bug_564468`,
`ecma3/JSON/Classes` — all `ruffle_matched`, identical lines.
`as3/Definitions/Variable/ConstVariables_custom1`,
`ecma3/Exceptions/exception_011_rt` — `pass`, identical lines.

**No regression anywhere**, including on the four `ruffle_matched` rows where a
silent flip to `pass`/`output_mismatch` would have been the trap
(`ruffle-matched-hides-regression`).

---

## Expected CI movement

**+3 effective pass** (4229 → 4232), all `output_mismatch` → `pass`:
`avm2/loaderinfo_quine`, `avm2/error_stack_trace`,
`import_assets/avm1_non_swf_import`.

Dispatch: **`mode=graphics`, `categories=full`, `images=false`.**
`categories=full` is required twice over —

1. `import_assets` is in the CI **misc** group, so item 2's flip is not graded
   under `categories=all` at all;
2. item 3 is an **ABC-emission** change, which per CLAUDE.md mandates `full`
   (from_avmplus is the largest population of `at`-frame tests).

Expect a **slow run**: two recompiler files changed (`swf.cpp`,
`abc_emit.cpp`), so the generated-table caches invalidate corpus-wide.

Trace-only surfaces are untouched (`swf_core.c`, `tag_stubs.c`), so the weekly
`no-graphics` canary covers that axis; no per-change `no-graphics` dispatch
needed. No `[[image_comparisons]]` behaviour changes — the only pixel-board
test in the blast radius is `import_assets/avm1_imports_avm1`, whose output is
byte-identical to baseline.

## Merge risks for the integrator

* **`SWFRecomp/src/swf.cpp`** — my hunk is a 9-line insert in the
  `SWF_TAG_IMPORT_ASSETS`/`_2` case (~:4855). The video sibling works at
  ~:3551 (`DefineVideoStream`); ~1300 lines apart, no overlap.
* **`SWFModernRuntime/src/actionmodern/action.c`** — a new function immediately
  above `actionImportAssets` (~:34576). The `setMask` sibling is at :70653.
* **`SWFModernRuntime/src/avm2/avm2_display.c`** — 17 lines around
  `loaderinfo_new` only. `avm2_globals.c` (the describeType sibling's file) is
  untouched.
* **`SWFRecomp/src/abc/abc_emit.cpp`** — mine alone this session.
* **`avm2_class.c` / `avm2_class.h` / `avm2_error.c`** — new territory this
  session; conflicts are only possible with an unannounced sibling. The
  `avm2_class.h` change adds one field **after** `instance_init` inside
  `struct Avm2Class`; nothing in the tree positionally initializes that struct
  (all five allocation sites `memset` + assign by name), so field order is safe.
* **`ruffle-tests/verify_output.py`** — one new function plus a one-line call.
  A sibling touching the harness would conflict textually but not semantically.

## Notes for the arc doc

* Strike C3b's "needs ABC debug_name modeling" blocker: it was a **two-line
  emitter change** (`name == 0` → `NULL`) plus ~60 lines of runtime naming.
  s12's "indistinguishable from any data the runtime holds" was a statement
  about the *emitted tables*, not the ABC — the wave-1 report's correction held
  up end-to-end.
* `abc_verifier.cpp` already knew all four naming rules. When a display rule
  looks unimplementable at runtime, **grep the recompiler for the same string
  shape first** — half the corpus's frame names come from there.
* A weak default that a generated TU overrides must not be a `const` object
  (gcc folds it at -O2, no relocation emitted, strong definition silently
  ignored). Same hazard class as the existing `shape_hit_test.c` precedent,
  which is non-const for exactly this reason.
