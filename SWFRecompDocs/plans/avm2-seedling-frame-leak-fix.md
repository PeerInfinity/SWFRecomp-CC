# Per-call activation vtables leaked ~78 KB per frame in Seedling (2026-10-19)

Session `swfrecomp-seedling-frame-leak`. Brief:
`~/CC/Archipelago-CC/NewDocs/plans/swfrecomp-seedling-frame-leak-prompt.md`. Evidence it built on:
`~/CC/Archipelago-CC/NewDocs/plans/seedling-js-wasm-oom-evidence/` (Archipelago slice `seedling-js-wasm-oom`).
The fix before this one: `avm2-seedling-leak-fix.md`.

## The symptom

On Archipelago's live `seedling_playthrough` panel page, the recompiled Seedling (build p4f, SWFRecomp-CC
`4c450f076`) leaked about 70–78 KB of o1heap per runtime frame. That filled the 512 MiB arena after
~5,100–5,900 frames (~3 min at 30 fps). The rate was the same with the game frozen (`botHold`), with the host
bridge calls cut 7×, and with the item pushes dropped. The live AVM2 object/array census after each GC was flat.

## The cause

`avm2_op_newactivation` builds a fresh vtable for every call of a method that needs an activation object. Those
vtables are `no_index`: one object owns each, and the GC frees them with it (`free_innards`). Building one runs
`avm2_vtable_add_traits`. That grows `entries` (through `avm2_vtable_append`) and `metas` (through
`vtable_set_slot_meta`) from a first capacity of 8. **Growth allocated the bigger array and dropped the old one.**
For shared class vtables that is deliberate: ICs and bound-method nodes hold `Avm2PropEntry*` into them. For
per-call vtables it leaked 1–2.5 KB per call. The object census never sees it, because the arrays are raw heap.

Who calls it per frame: the injected `BridgeGeneric` (the Archipelago bridge ABC, `abc1`). All its instance
methods open with `newactivation`, because ASC gives try/catch methods an activation. Once the panel configures it,
`onEnterFrame` runs `resolvePath` once for each of the 21 `path_reads` in `games/seedling.json`, every frame. The
standalone page never configures the bridge, so its `onEnterFrame` returns early. That is why p4f's standalone
idle control ("I", floor 60.09 MB flat) did not see this leak: it is panel-only.

## The fix

`SWFModernRuntime/src/avm2/avm2_class.c`: on growth, free the superseded `entries`/`metas` array when the vtable
is `no_index`.

This is safe for three reasons:
- the IC sites (`avm2_ops.c` getproperty/setproperty/callproperty) already refuse to cache `no_index` vtables;
- nothing holds an entry pointer across an append while the vtable is built (`vtable_find_mut` results are used
  before the next append);
- activation and catch scopes are sealed, so nothing appends to their vtables after construction.

Shared class vtables keep the old behaviour.

## How it was found

The allocation-site tracker from the previous fix (`-DHEAP_TRACK_SITES`, `EXTRA_LDFLAGS=--profiling-funcs`):
- The pinned p4f's own object files from `~/CC/SWFRecomp-CC-rebuild` (`4c450f076`) were copied, and only
  `heap.c`/`avm2_external.c` were recompiled with the tracker. So the instrumented build is p4f plus the tracker.
- It was served from a throwaway Archipelago worktree, using its own `python3 -m http.server` and with every
  submodule initialised.
  - ⚠ The shared `:8000` dev server serves some other tree. Use `--host=`.
  - ⚠ A build directory not named in `builds.json` never gets a delivered level set ("AP load finished" times
    out), so swap the wasm into the `seedling_bot_ap_p4f` directory instead.
- A local-only probe patch ran the window inside `hold-l0`: 20 s settle, then 10 s tracked (tracking is slow:
  ~17 frames), then 60 s (~1,750 frames, several GCs), then `avm2_ei_track_report`.

| build | tracker window (17 frames) | outstanding after ~1,750 more frames |
|---|---|---|
| p4f | frames 513–530 | **945 allocations, 685 KB, 2 stacks**: `avm2_alloc < avm2_vtable_add_traits < avm2_op_newactivation` (630 × metas, 315 × 1 KB entries) |
| p4f + fix | frames 465–482 | **0 allocations, 0 bytes** |

Symbolize with `llvm-objdump -t <wasm> | awk '$3=="F"{print $1,$5,$6}'`. The tracker's PCs are code-section
offsets and match the symbol table directly.

## Measurements: the panel page, frozen L0 (`hold-l0`), headless logic-only

Post-GC floor (o1heap `allocated` right after each drop):

| build | floor over the hold | slope |
|---|---|---|
| p4f + tracker | 106.9 → 156.8 → 214.2 → 259.5 MB, frames 444 → 2,392 | **78 KB/frame** |
| p4f + fix + tracker | 69.2, 67.0, 63.4, 69.2, 64.6 MB, frames 447 → 2,226 | flat; it oscillates with the census |
| p4f + fix (release, md5 `16eabc97…`), 240 s hold | 13 collections, frames 422 → 5,665: 65.84, 65.82, 71.19, 66.13, 64.58, 63.64, 64.81, 66.11, 66.82, 65.04, 63.91, 66.46, 62.37 MB | **flat**: the old rate would have added ~410 MB; no OOM through frame 6,139, past the old death at ~5,100 |

## Regression test

`ruffle-tests/tests/swfs/regression/avm2_activation_vtable_bounded` runs in a 32 MB arena (`test_env.json`). It has
two methods:
- one whose closure captures 12 locals: 12 activation slots, past the capacity of 8;
- one with a typed catch.

The test calls both 400 times a frame for 120 frames.
- Without the fix it dies before tick 40 (arena exhausted).
- With the fix it passes. The expected sums are closed-form arithmetic.

## Verification

- Local ASAN with `-DHEAP_PASSTHROUGH` and `AVM2_GC_STRESS=1`: **6/6 pass, 0 sanitizer reports.**
  - `ASAN_OPTIONS=detect_leaks=0` is needed: LSan's exit-time report fails every build, because the runtime frees
    nothing at exit.
  - The six tests: `avm2_activation_vtable_bounded` and avm2 `activation_class`, `catch_scope_slot`, `closures`,
    `newactivation_in_script_init`, `try_catch`.

- CI on the fix `c1fa89bc2`, graphics `categories=full`, run 39311823678 (published as `3f901de31`, merged into
  master):
  - `corpus_status_diff.py` from `0cb5464e5`: **0 regressions, 0 status moves**, effective 4503 of 4563 in the
    intersection;
  - the new regression test passes.
- Graphics full with `avm2_gc=1` (stress), run 39311840733: **identical to the published run on all 4,625 tests**.

## For the Archipelago rebuild

Things for the Archipelago rebuild to know:
- The fix only frees memory, but it does change o1heap addresses after the first activation growth. Pointer-keyed
  order could move, so the tapes' byte-identity is for the Archipelago gates to measure, not to assume.
- The user chose to rebuild from LATEST master + this fix, not from a fix-only patch on `4c450f076`. A fix-only p4f
  was built as the control for the long hold: local commit `3dba9ba19` on `4c450f076`, never pushed, only
  `avm2_class.o` differing, wasm md5 `16eabc979fc2c3e95fd7e97a1fb551f3`.
- Master between `4c450f076` and the fix touches Seedling's paths in these commits:
  - `5367e2b33`: append-in-place string buffers;
  - `f5de34ce8`: ExternalInterface provider and dispatcher (`avm2_external.c`);
  - `38cf9b1a0`: BitmapData larger than the stage, and CPU `draw()` AA;
  - `e62daeb6f`: minimum device stroke width;
  - `9821a086a` / `801451eb5`: embedded font registry and default fonts;
  - `1edcde2e1`: PlaceObject3 Visible and filter chains;
  - `d192a4778`: stage `scaleMode`/`align`;
  - `e412dd55f` / `5edcc1a5d`: drawing API and sub-twip vertices;
  - `f0f8986ac`: glyph precision;
  - `b78134bd1`: goto sweep CLIP_CONSTRUCT and libregexp u16 captures;
  - `e783f14e5`: invalid goto inside a frame script.

  Full list: `git log 4c450f076..<fix> -- SWFModernRuntime/src/avm2 SWFModernRuntime/src/rendering SWFRecomp/src`.
