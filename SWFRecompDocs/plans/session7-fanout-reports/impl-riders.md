# Polish session 7 — Batch D riders (implementation)

Worktree: `.claude/worktrees/agent-a48073904cb3db96f`, base `46dcf3a06`
(session-6 closeout — the same SHA the triage snapshot used).
Patch: `scratchpad/patches/riders.patch` (2 files, +79/−17).
Nothing committed, nothing pushed.

**Result: 3 of 4 riders landed (+3 tests), 1 skipped as already-settled.**

| rider | test | before | after |
|---|---|---|---|
| 1 System.setClipboard #2007 | `avm2/system_setclipboard_null` | `output_mismatch` (1/1 line) | **pass** |
| 2 Video width/height clamp | `avm2/flash_media_video_setter` | `output_mismatch` (4 real rows) | **pass** |
| 3 URLVariables ordering | `avm2/loader_load`, `avm2/bom` | — | **SKIPPED** (already a settled RUFFLE_VS_FLASH divergence) |
| 4 root-character children | `avm2/instantiate_root_character` | `output_mismatch` (1/4 lines) | **pass** |

Build note: the recompiler binary in the *main* checkout is newer than that
checkout's uncommitted `abc_emit.cpp`, i.e. it contains recompiler changes that
are not in `master`. Copying it would have contaminated the baseline, so the
worktree's `SWFRecomp/build` was **configured and built from the worktree's own
clean master source** (`cmake -S SWFRecomp -B SWFRecomp/build
-DCMAKE_BUILD_TYPE=Release && cmake --build … -j6`). No recompiler source was
changed — all three fixes are runtime-only.

Harness trap worth recording: `verify_output.py` skips recompilation when the
test's `RecompiledScripts/` mtime is newer than the recompiler binary
(`verify_output.py:1878-1881`). Copying test directories out of the main
checkout therefore *reuses that checkout's generated C* and links it against
worktree runtime sources — three canaries came back `compile_fail`
(`ld returned 1`) purely from this. Deleting every copied `Recompiled*` dir
made all of them pass. Any future worktree-based test run must delete
`Recompiled*` after copying a test dir.

---

## Rider 1 — `System.setClipboard(null)` must throw #2007

**Cause (confirmed):** `grep setClipboard` over `SWFModernRuntime/src/avm2/`
returned 0 hits. `register_system` (`avm2_globals.c:1966`) only registered
`gc` and `pauseForGCIfCollectionImminent`, so `System.setClipboard(null)`
resolved to nothing and the call threw TypeError **#1006** ("value is not a
function") instead of **#2007**.

`test.toml` is `num_frames = 1` — **no `known_failure`**, and there is no
`output.ruffle.txt`, so Ruffle passes this and `output.txt` (`2007`) is the
oracle for both players.

**Oracle:** Ruffle `core/src/avm2/globals/flash/system/System.as` declares
`public static native function setClipboard(string:String):void`, and
`system.rs::set_clipboard` reads the argument with
`args.get_string_non_null(activation, 0, "text")` — the null check fires
*before* the UI backend is touched.

**Fix** (`avm2_globals.c`, +21): a `system_set_clipboard` native that throws
`TypeError Error #2007: Parameter text must be non-null.` for a missing /
null / undefined argument (undefined is what the `:String` coercion turns
into null), otherwise coerces to string and returns undefined. There is no
host clipboard in a headless/native run, so the write itself stays a no-op.

**Diff before → after:** `- 2007 / + 1006` → clean pass.

---

## Rider 2 — `Video.width`/`height` clamp at scale 32768

**Triage's re-size was right.** The 41-line diff is a pure *display* artifact:
`output.txt` opens with a blank line (the first `section()` does `trace("")`),
`filter_output()` strips leading blanks from the ACTUAL output only, so the
`--diff` renderer shows every line shifted by one. `compare_output()`
(`verify_output.py:3186-3190`) strips leading blanks from **both** sides, so
pass/fail was never affected by it. The real gap was exactly **4 rows**:

```
v.width  = 10485761  expected w=10485760.00   we gave 10485761.60
v.width  = 16777215  expected w=10485760.00   we gave 16777214.40
v.height = 10485760  expected h=7864320.00    we gave 10485760.00
v.height = 10485761  expected h=7864320.00    we gave 10485761.60
```

**Cause (confirmed):** Ruffle/SWF store a display object's matrix a/b/c/d as
`swf::Fixed16` (16.16 fixed point, `swf/src/types/matrix.rs`), and
`Fixed16::from_f64` is a **saturating** i32 cast
(`swf/src/types/fixed.rs:73`). So the matrix scale tops out at
`i32::MAX / 65536 = 32767.999984741211`, and the width getter — which
transforms the intrinsic bounds by that capped matrix — saturates at
`320 × 32768 = 10485760` px (`240 × 32768 = 7864320` for height).
`scaleX`/`scaleY` are a **separate cached double** that never round-trips the
matrix, which is why the same rows still report `sx=52428.80` /
`sy=43690.67` uncapped. Our `Avm2DisplayObjectExt.mtx_*` are plain `float`
with no saturation, so we reported the uncapped product.

**Fix** (`avm2_display.c`, ~15 lines): a `clamp_fixed16()` helper
(`[-32768, 32767.999984741211]`, NaN → 0 as in Rust's float→int cast) applied
to the four matrix writes in `set_scale_x_internal`, `set_scale_y_internal`
and `set_rotation_internal`. `set_width_height` funnels through those two
scale setters, so the width/height path is covered without touching it.

Deliberately **saturation only, not the 1/65536 quantization** — our `mtx_*`
fields are floats and quantizing them would perturb every rotated matrix in
the corpus. Scales below 32768 are bit-identical to before (verified: the
`v.width = 10485759 -> w=10485758.40` row, which our f32 bounds-corner
rounding already reproduced exactly, is unchanged).

---

## Rider 3 — URLVariables ordering — **SKIPPED (diagnosis superseded)**

The triage flagged this as "URLVariables emission order is reversed —
`avm2_net.c`" and told the implementer to settle the RUFFLE_VS_FLASH question
first. It is **already settled, against changing it**:

- `avm2_globals.c:2614-2623` (`urlvars_to_string`) carries the full rationale
  in a source comment.
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
  §"AVM2 dynamic-property enumeration order: `URLVariables.toString`" has the
  entry and the explicit **"Decision: keep insertion order. `loader_load`
  cannot pass on any amount of Loader work."**

The mechanism is also not a "reversal": Ruffle's `URLVariables.toString`
(`globals/flash/net/URLVariables.as`) joins in `for (p in this)` order, and
Ruffle's AVM2 dynamic properties live in an FNV-hashed `hashbrown` table
(`core/src/avm2/dynamic_map.rs`), so the expectation is a **bucket-order
artifact**. Ruffle's own `avm2/url_vars` test works around it with
`.toString().split("&").sort()` and a comment ("Ruffle's property iteration
order is not consistent with Flash's (yet)"); `loader_load` simply forgot to.
Matching it would mean emulating FNV-1a plus hashbrown's SIMD bucket layout —
far past a rider, and self-invalidating the moment either crate changes.

Confirmed unchanged by this patch: `loader_load` still shows its same 4 diffs
(2 URLVariables-order rows + 2 uncaught-error rows). It remains an
**enabler-only** line item for whoever lands the uncaught-error re-land — and
even then it will still fail on the two ordering rows.

---

## Rider 4 — root character instantiated from AS must expose its children

**Cause (confirmed by dumping the fixture):** `loadable.swf` carries exactly
one `SymbolClass` entry, `178 → LoadableMain`, and defines characters 1
(shape) and 2 (sprite) only — 178 names nothing, which is the *root-class*
binding. Our emitter writes it as `10178` (child `char_id_base` 10000).

`g_symbol_map` (the class → character table `char_for_class()` reads, which is
what `display_native_init` uses to attach a timeline to a script-`new`'d
object) is built **only from the main movie's** `avm2_generated_symbol_classes`
in `avm2_display_build_stage`. `loader_boot_child_swf` resolves a child's root
class but never registers it. So `new getDefinition("LoadableMain")()`
produced a bare, childless MovieClip and `instance.myChild` read `null`.

**Oracle:** Ruffle `core/src/display_object/movie_clip.rs`, the `None =>` arm
of the SymbolClass loop (~line 4349): when the id names no character it does
*two* things, not one — sets the clip's AVM2 class **and** registers the root
clip itself as that character ("We also need to register this MovieClip as a
character now", `library.register_character(id, Character::MovieClip(...))`),
so `sprite_allocator`'s later `class_symbol()` lookup instantiates a fresh
copy of the root **timeline**, children and all.

**Fix** (`avm2_display.c`, ~25 lines):
- factored the symbol-map insert into `symbol_map_add(cls, char_id)`
  (first-binding-wins, capacity-guarded), and grew the map's allocation by
  `AVM2_MAX_CHILD_MOVIES` so children can add to it after stage build;
- in `loader_boot_child_swf`, once the child's root class resolves and passes
  the #2023 Sprite gate, register `root_cls → root_char` (the child's
  `char_id_base + 0`, i.e. its root timeline — the same object Ruffle
  registers, keyed by the id we actually have a timeline for).

**Scope kept deliberately narrow.** Two things were *not* done:
- the **main** movie's root binding is still not self-registered. Ruffle does
  register it, but our `build_stage` skips `char_id == 0` and the main root
  binding is id 0 in nearly every corpus SWF; mapping `Test → char 0` would
  make `new Test()` instantiate the main timeline across the whole avmplus
  suite. Out of proportion for a rider; no test in the candidate list asks
  for it.
- a child's **non-root** symbol bindings still aren't added to `g_symbol_map`
  either (timeline placement resolves those through the separate
  `class_for_char` child-movie path, so only the script-`new` direction is
  affected). Same reasoning; flagged here as the obvious follow-up if a
  future test needs `new <childNonRootClass>()`.

**Diff before → after:** `instance.myChild: null` → `[object MovieClip]`,
clean pass.

---

## Canaries

All baseline-**passing** per
`ruffle-tests/tests/swfs/{avm2,regression}/_results/results_graphics.json`
(the graphics baseline, per `ci-baseline-is-results-graphics-not-results`).
Run locally at `-P 2`, all `Pass: 1`:

**Rider 2 (highest blast radius — every scaleX/scaleY/rotation write):**
`nan_scale`, `displayobject_width`, `displayobject_height`,
`displayobject_rotation`, `displayobject_invalid_floats`,
`displayobject_set_matrix_nested`, `edittext_bounds_scale`,
`flash_media_video_constructor`, `flash_media_video_rotation_probe` — 9/9 pass.

**Rider 1 (flash.system surface):** `capabilities_resolution` — pass.
(The suite has only two other `system_*` tests; `system_exit` is a baseline
failure, so it is not a valid canary.)

**Rider 4 (Loader / symbol map):** `loader_events`,
`loader_child_getdefinition`, `loader_loadbytes_url`, `loader_reuse`,
`loaderinfo_root`, `loader_error_in_root_ctor`, `loader_loadbytes_events`,
`loader_duplicate_coerce` — 8/8 pass.

**`regression` suite** (mandatory per `local-regression-sweep-stash-diff`):
`avm2_goto_catchup_scale`, `avm2_loader_stub`, `avm2_simplebutton_click`,
`avm2_agi_shell`, `avm2_morph`, `avm2_timeline_solid`, `avm2_static_text`,
`avm2_contextmenu_stub` — 8/8 pass.

**Unchanged-as-expected:** `avm2/loader_load` still 124/128 with the identical
4 diffs.

Total: **26 canaries, 0 regressions.** `git status` shows only the two
modified runtime sources; no `_results` file was clobbered.

---

## Recommended CI dispatch

`mode=graphics`, `categories=full`, `images=false` — the change is AVM2
runtime (display + globals), so `full` is the right category per the project's
CI policy. Expect **+3** (`system_setclipboard_null`,
`flash_media_video_setter`, `instantiate_root_character`); watch the
`from_avmplus` display/geometry rows for any Fixed16-saturation surprise, and
the `loader_*` / `mixed_avm` rows for the symbol-map change.
