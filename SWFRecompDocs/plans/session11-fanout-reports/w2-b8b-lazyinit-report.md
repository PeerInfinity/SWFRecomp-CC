# w2-b8b-lazyinit — implementation report (session 11, wave 2)

Agent: `w2-b8b-lazyinit`. Base HEAD `b4c983ea4`. Worktree
`.claude/worktrees/agent-ae51a2eac6739ee14`. **No commits, no pushes.**
Patch: `w2-b8b-lazyinit.patch` (419 lines, 7 files).

Spec: `wave1-trace-b8b-b9.md` §"Lead B8b", SAFE SLICE only.

---

## Result

**+2 trace flips, 0 regressions.** Predicted range was +1 … +3; landed in the
middle. The third target (`avm2/delayed_symbolclass`) is **REFUTED for the safe
slice** — it improved from 16 to 2 wrong lines but cannot flip without
honouring `LAZY_INITIALIZE` for frame-1 content, which the charter explicitly
excludes. Root cause pinned exactly (below) — a clean follow-up, not a mystery.

### Per-test ledger (all re-measured in this worktree, `--recompile`, no-graphics)

| Test | before | after | verdict |
|---|---|---|---|
| `avm2/doabc_and_symbolclass_script_init_normal` | output_mismatch, 6/6 lines wrong | **PASS** | **FLIP +1** |
| `avm2/doabc_and_symbolclass_script_init_goto` | output_mismatch (1/7 per w1 census) | **PASS** | **FLIP +1** |
| `avm2/delayed_symbolclass` | output_mismatch 16/28 | output_mismatch **2/28** | improved, no flip |

`_normal`'s "before" was re-measured at HEAD in this worktree, not taken from
the census: expected `New / New constructor / #1065 / C / Z / B`, actual
`New / Z / C / B / New constructor / #1065`. After the change the six lines come
out in the expected order, exactly as w1's mechanism replay predicted.

`_goto` flipped whole — the spurious `Test` line and the
`#1065: Variable e is not defined` inside the catch handler were both downstream
of loading `abc1` at boot, as w1 predicted. No residual diff.

### Canaries — all mandatory ones PASS

| Canary | why it was on the list | after |
|---|---|---|
| `avm2/goto_in_scene_last_frame` | **the** canary: the only frame-2 EAGER DoABC in the corpus | **PASS** |
| `avm2/displayobject_name` | frame-2 SymbolClass rows (2) | **PASS** |
| `avm2/displayobject_parent` | frame-2 SymbolClass rows (2) | **PASS** |
| `avm2/displayobject_root` | frame-2 SymbolClass rows (2) | **PASS** |
| `avm2/displayobject_visible` | frame-2 SymbolClass rows (2) | **PASS** |
| `from_shumway/timeline/timeline_loop` | frame-2 SymbolClass row | **PASS** |
| `avm2/subclass_superclass_linked_symbol` | B8a's regression set (symbol resolution) | **PASS** |
| `avm2/symbol_class_conflict` | B8a's regression set | **PASS** |
| `avm2/doabc_is_eager` | extra: grades the eager/lazy DoABC contract head-on | **PASS** |
| `avm2/loader_loadbytes_url` | extra: child-movie `ctx->files` growth + no-char-0 root binding | **PASS** |

That covers the complete 9-SWF blast-radius population (3 targets + 6 passing
multi-frame SWFs) plus 2 extra adjacent tests.

---

## What was implemented

Ruffle's per-frame contract (`core/src/display_object/movie_clip.rs`
`run_abc_and_symbol_tags`, :4263-4395), applied to frames **≥ 2 only**:

1. load that frame's DoABC tags (no script initializer runs);
2. resolve that frame's SymbolClass rows in tag order — the domain lookup
   triggers the lazy init of the defining script; look-up only, never construct
   (B8a's rule);
3. then run the held-back eager final-script initializers of that frame's
   non-`LAZY_INITIALIZE` ABCs.

Both Ruffle call sites are mirrored: the normal frame pass
(`movie_clip.rs:1438`) and the **goto frame walk** (`movie_clip.rs:1749` —
skipped frames still run their abc/symbol tags).

**Frame 1 is untouched, by construction.** Its ABCs still load at boot, its
eager last scripts still run regardless of the LAZY bit, and its SymbolClass
rows are still resolved inside `avm2_display_build_stage`. For the 4934 corpus
SWFs whose AVM2 tags all live in frame 1, the emitted frame arrays are all-zero
and `g_has_deferred_tags` short-circuits the whole runtime path to one branch.

### Files touched (7)

**Recompiler**

* `SWFRecomp/include/swf.hpp` — two new `SWF` members: `symbol_class_frames`
  (parallel to `symbol_class_bindings`) and `abc_tag_frames`
  (`{frame, lazy}` per emitted ABC tag).
* `SWFRecomp/src/swf.cpp` — three edits:
  * `SWF_TAG_SYMBOL_CLASS`: record `next_frame_i - 1` per row.
  * `SWF_TAG_DO_ABC`/`_DEFINE`: read the DoABC2 `Flags` bit 0
    (`kDoAbcLazyInitializeFlag`; tag 72 carries no flags and is always eager,
    matching Ruffle's `DoAbc2Flag::empty()`), and after the emit paths pad
    `abc_tag_frames` up to `abc_emitter->tagCount()`. Padding by tagCount covers
    all three emit paths (parse error / verify error / normal) without
    duplicating the record at each.
  * `finalizeAbcEmit()`: pass the two vectors through.

  *Note:* the w1 report suggested `abc/abc_timeline.cpp` as the recording site.
  It is not viable — `abc_timeline.cpp`'s `scanStream` never sees tag 82/72/76
  (they fall through to `defineTag`, which has no case for them), and the ABC
  tag **index** that `avm2_generated_abc_files[]` is keyed by lives only in
  `AbcEmitter::next_tag_index_`. `swf.cpp` has both the frame counter
  (`next_frame_i - 1`, same convention as `SWF_TAG_FRAME_LABEL`) and the tag
  index, so it is the only site where the two can be joined. Consequence:
  **B9 and B8b do not collide in `abc_timeline.cpp`** — see merge risks.
* `SWFRecomp/include/abc/abc_emit.hpp` + `src/abc/abc_emit.cpp` —
  `AbcEmitter::finalize` takes two new **defaulted** parameters and emits three
  additive arrays into `abc_registry.c`: `avm2_generated_abc_frames[]`,
  `avm2_generated_abc_lazy[]`, `avm2_generated_symbol_class_frames[]`.
  Missing/short input emits frame 0 / eager, i.e. today's behaviour. Nothing
  existing in the registry changed.

**Runtime**

* `SWFModernRuntime/include/avm2/avm2_abc.h` — externs for the three arrays plus
  the `avm2_run_frame_tags` prototype.
* `SWFModernRuntime/src/avm2/avm2_main.c` — new
  `avm2_run_frame_tags(ctx, frame_idx)` (steps a/b/c above; idempotent via two
  lazily-allocated per-ABC / per-row done flags; early-out via
  `g_has_deferred_tags`). `runSWF_avm2` step 1 loads **frame-0 ABCs only** (later
  slots stay `NULL`; every `ctx->files` walker already NULL-checks —
  `avm2_gc_mark_roots_main`), step 3 NULL-guards.
* `SWFModernRuntime/src/avm2/avm2_display.c` — three localized edits:
  * new `avm2_display_resolve_frame_symbols()` next to `class_for_dotted_name`
    (step b; wrapped in a catch-all try frame like every other boot-time
    resolution);
  * `avm2_display_build_stage`'s symbol-map loop now skips rows with
    `frame != 0`. **This loop, not `avm2_main.c` step 3, was the actual
    boot-time initializer of `delayed_symbolclass`'s frame-2/4 classes** — w1
    attributed it to step 3;
  * one-line call to `avm2_run_frame_tags` in `run_frame_internal` (right after
    `frame_idx` is computed, before the queued places/removes drain) and in the
    `run_goto` frame walk, both gated on `obj == ctx->root` (a sprite's tag
    stream carries neither tag class).

~60 lines recompiler + ~120 lines runtime, vs the ~100/~150 sketch.

---

## `delayed_symbolclass` — precise refutation

w1 predicted "same mechanism, same fix". It is the same *symptom* with a
different owner. After the change its diff is 2 lines:

```
expected 1  In constructor                          actual 1  In SecondFrameChild class initializer
expected 2  Finished constructor                    actual 2  In SecondFrameChild script initializer
expected 7  In SecondFrameChild class initializer
expected 8  In SecondFrameChild script initializer
```

Lines 9-28 match exactly, and `FourthFrameChild` (SymbolClass row at frame 4) is
now correct — the deferral itself works. What remains:

* `delayed_symbolclass` has **one** ABC, at frame 1, with **`LAZY_INITIALIZE`
  set** (verified in the emitted `avm2_generated_abc_lazy[] = { 1 }`). Ruffle
  therefore runs **no** eager script for it at load; `Main` is reached only
  through the char-0 SymbolClass row.
* We eager-init the **last** script of every frame-1 ABC unconditionally, and in
  this ABC the last of the 3 scripts is `SecondFrameChild`'s — so its class +
  script initializers fire at boot.
* Fixing it means honouring `LAZY_INITIALIZE` for **frame-1** content, which the
  charter forbids: 2863 of the 3075 ABC-carrying corpus SWFs are all-lazy, 1546
  of them lazy **and** multi-script, so it would change which script runs at
  boot for a four-figure population.

Recorded as a fully-specified follow-up rather than a partial implementation:
the frame arrays this batch adds already carry the LAZY bit, so the follow-up is
essentially a one-condition change (`if (avm2_generated_abc_lazy[i]) continue;`
in `runSWF_avm2` step 3, plus Ruffle's "resolve frame-1 SymbolClass rows before
the eager script" reorder) and a `categories=full` CI run to measure the
fallout. That is the "maximal fix" w1 already sized and deferred.

---

## Merge risks

* **`avm2_display.c` / `avm2_main.c` are shared with sibling wave-2 agents.** My
  edits are deliberately small and far apart. `avm2_display.c`: one new function
  inserted immediately before `class_for_char` (~line 1524), one `continue`
  added to the `build_stage` symbol-map loop (~line 3533), two one-line call
  sites (`run_frame_internal` ~line 1977, `run_goto` ~line 2780).
  `avm2_main.c`: one new block immediately before `runSWF_avm2`, plus two small
  edits inside steps 1 and 3. No existing function was moved or reindented.
* **`abc_timeline.cpp` is NOT touched** — contrary to the w1 dispatch table. The
  B9 agent owns that file alone, so the two batches are fully disjoint.
* `AbcEmitter::finalize` gained two **defaulted** parameters — any other caller
  keeps compiling and keeps today's emission.
* Generated-cache safety: `verify_output.py::recompile_swf` auto-invalidates a
  cached `RecompiledABC/` whenever the `SWFRecomp` binary is newer, so CI
  regenerates every registry; no stale cache can reach the linker missing the
  new arrays. Locally, `--recompile` everywhere.
* `avm2_generated_*` frame arrays are also emitted (prefixed, unreferenced) for
  child movies; harmless, and the child-movie load path
  (`avm2_register_child_movie_tables`) is unchanged — `loader_loadbytes_url`
  confirms.
* AVM1 SWFs are unaffected: `verify_output.py` only compiles `avm2_main.c` when
  `RecompiledABC/` exists, and that directory always carries the new arrays.

## CI recommendation

`mode=graphics`, `categories=full`, `images=false` (AVM2 runtime + recompiler
emission — standing policy). The recompiler is touched, so the run must build it
fresh; it will, and the cache invalidation above handles the rest. No
`NO_GRAPHICS`-only code was touched, so the weekly canary covers no-graphics.
