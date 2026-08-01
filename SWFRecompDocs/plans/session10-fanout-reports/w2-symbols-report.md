# w2-symbols — wave-2 report (B5 + B8)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aba7a60cb2901bc75`
Base: `b007ee50d` (master). No commits, no pushes.

Deliverables (all in this directory):
* `w2-symbols.patch` — combined, both hunks.
* `w2-symbols-B5.patch` — `SWFRecomp/src/swf.cpp` only (applies standalone).
* `w2-symbols-B8a.patch` — `SWFModernRuntime/src/avm2/avm2_main.c` only
  (applies standalone).

The two hunks are in **different files** and are fully independent: either can
be landed without the other.

Recompiler was built **in-worktree** (`cmake -S SWFRecomp -B SWFRecomp/build
-DCMAKE_BUILD_TYPE=Release && cmake --build SWFRecomp/build -j4`); every test
below was run with `--recompile`.

---

## Per-hunk ledger

| Hunk | Files | Target(s) | Baseline | After | Verdict |
|---|---|---|---|---|---|
| **B5** — AS3 SWF's AVM1 tags are inert | `SWFRecomp/src/swf.cpp` (4 sites) | `mixed_avm/avm1_loads_avm2_doaction` | `output_mismatch` (gap 0, 2 extra lines) | **PASS** | **TAKE (+1)** |
| **B8a** — never-placed SymbolClass rows must not self-construct | `SWFModernRuntime/src/avm2/avm2_main.c` | `avm2/subclass_superclass_linked_symbol` | `output_mismatch` (gap 4) | **PASS** | **TAKE (+1)** |
| **B8a (2nd test)** — `avm2/graphic_linkage` | — | `avm2/graphic_linkage` | `output_mismatch` (gap 2) | still gap 2 | **NOT TAKEN** — see below |
| **B8b** — lazy DoABC script init | — | `doabc_and_symbolclass_script_init_{normal,goto}` | `output_mismatch` | unchanged | **NOT TAKEN** — see below |

Net measured yield: **+2** (both re-verified from `output_mismatch` baselines
in `results_graphics.json` @ `feb8882b0`, then measured to PASS locally).

---

## B5 — an AS3 SWF's AVM1 tags are inert

`SWFRecomp/src/swf.cpp` already skipped `DoABC` when `!is_as3` (the comment
there cites Ruffle's `movie.is_action_script_3()`). The symmetric half was
missing. Added `if (is_as3) skip` at all four AVM1-bytecode sites:

* top-level `SWF_TAG_DO_ACTION` (was :3248) — plain `break`; the main tag
  loop always advances `cur_pos` to `tag_data_end` (swf.cpp:747).
* top-level `SWF_TAG_DO_INIT_ACTION` (was :3304) — same.
* DefineSprite-nested `SWF_TAG_DO_ACTION` (was :5918) — `cur_pos +=
  sub_tag.length; break;`. The sprite sub-tag loop does **not** auto-advance
  `cur_pos`; each case advances it itself (see its `default:` arm).
* DefineSprite-nested `SWF_TAG_DO_INIT_ACTION` (was :6022) — same.

`is_as3` is already the parse-context flag set from FileAttributes
(swf.hpp:306, set at swf.cpp:4711); FileAttributes is required by spec to be
the first tag, so it is always known before any DoAction tag.

### Blast radius — measured statically over the whole corpus

`scratchpad/w2sym_scan_swf.py` (new, read-only; handles FWS/CWS/ZWS) walked
all 4943 `*.swf` under `ruffle-tests/tests/swfs`. 4939 parsed (the 4 misses
are the deliberate decoys: `avm1/movieclip_state_values/no correct file
(text|image).swf`, `from_shumway/as3-loader/bug1157243/{empty,invalid}`).

**Exactly 3 SWFs in the corpus are FileAttributes-AS3 *and* carry
DoAction/DoInitAction tags** — all three in `mixed_avm`:

```
mixed_avm/avm2_doaction/test.swf                        DoAction=1
mixed_avm/avm1_loads_avm2_doaction/avm2.swf             DoAction=1 spriteAVM1=1
mixed_avm/avm2_loads_avm1_loads_avm2_doabc/avm2-inner.swf  DoAction=1
```

For every other SWF in the corpus the new gate is provably dead code
(`is_as3 == false` ⇒ byte-identical emission). That makes `mixed_avm` the
complete canary, not a sample.

### Canary sweep — B5

Ran the **whole `mixed_avm` suite** (11/11) plus a 21-test AVM1-side sample
(`avm1` ×9, `import_assets` ×3, `from_gnash/misc-ming.all` ×4,
`from_gnash/actionscript.all` ×4, plus `avm1_sprite_sc_ignored`), all with
`--recompile`, `-P 2`. Baseline column is `results_graphics.json` @
`feb8882b0`.

| Test | Baseline | After |
|---|---|---|
| mixed_avm/avm1_doabc | pass | PASS |
| mixed_avm/avm1_loads_avm2 | output_mismatch | output_mismatch |
| **mixed_avm/avm1_loads_avm2_doaction** | output_mismatch | **PASS** ← the win |
| mixed_avm/avm1_sprite_sc_ignored | pass | PASS¹ |
| mixed_avm/avm2_doaction | pass | PASS |
| mixed_avm/avm2_loads_avm1 | output_mismatch | output_mismatch |
| mixed_avm/avm2_loads_avm1_doabc | output_mismatch | output_mismatch |
| mixed_avm/avm2_loads_avm1_loads_avm2_doabc | output_mismatch | output_mismatch |
| mixed_avm/avm2_loads_avm1_loads_into_root | output_mismatch | output_mismatch |
| mixed_avm/avm2_loads_avm1_v10 | output_mismatch | output_mismatch |
| mixed_avm/avm2_loads_avm1_v9 | output_mismatch | output_mismatch |
| avm1/{clip_events, clip_event_propagation_order, execution_order1, execution_order3, goto_execution_order, goto_frame, register_class, as2_oop, attach_movie} | pass ×9 | PASS ×9 |
| import_assets/empty_url | pass | PASS |
| import_assets/{avm1_imports_avm1, avm1_non_swf_import} | output_mismatch ×2 | output_mismatch ×2 |
| from_gnash/misc-ming.all/{PlaceObject2Test, DefineEditTextTest, DepthLimitsTest} | pass ×3 | PASS ×3 |
| from_gnash/misc-ming.all/ButtonEventsTest | ruffle_matched | ruffle_matched |
| from_gnash/actionscript.all/{Object-v6, Object-v8} | ruffle_matched ×2 | ruffle_matched ×2 |
| from_gnash/actionscript.all/{MovieClip-v6, MovieClip-v8} | output_mismatch ×2 | output_mismatch ×2² |

**Zero regressions. Exactly one status change: the target, `output_mismatch`
→ `PASS` (+1).**

¹ `avm1_sprite_sc_ignored` scored `compile_fail` inside the `-P 2` sweep and
**PASS** on a sequential re-run (`r=0.05s c=245.84s`) — a gcc timeout under
an 8-agent-loaded machine, the documented false-failure mode of parallel
batching, not a regression.

² `MovieClip-v6` / `MovieClip-v8` also scored `compile_fail` — both at
`c≈303s`, i.e. dead on `verify_output.py`'s 300 s per-file gcc cap. Re-run
sequentially with `SWFRECOMP_COMPILE_TIMEOUT=1200` they compile in 460.79 s /
594.10 s and land on **MISMATCH = their `output_mismatch` baseline**. Same
harness artifact; also structurally impossible for these two to be affected
(they are not FileAttributes-AS3, so B5's gate never fires, and being AVM1
they never compile `avm2_main.c`).

---

## B8a — a never-placed SymbolClass row must not construct an instance

`avm2/subclass_superclass_linked_symbol` baseline (measured, not inferred):

```
-  1  SubClass before super(): this.target_from_subclass = null this.target_from_superclass=null
+  1  SuperClass before super(): this.target_from_superclass=null
+  2  SuperClass after  super(): this.target_from_superclass=null
+  3  SubClass before super(): ...
+  4  SuperClass before super(): ...      <- these 4 are the CORRECT chain
+  5  SuperClass after  super(): ...
+  6  SubClass after  super(): ... [object TargetClip] ...
```

i.e. our last four lines already equal the four expected lines exactly; the
whole failure is an **extra SuperClass ctor pair emitted first**.

**Mechanism (confirmed from the generated registry, not guessed).**
`RecompiledABC/abc_registry.c` for this test has **no char-0 binding**:

```
{ 7, "Container" }, { 5, "SubClass" }, { 4, "SuperClass" }, { 3, "TargetClip" }
```

so `runSWF_avm2` takes the `root_class == NULL` else-branch (avm2_main.c
:493), whose loop constructs every bound character that is **never placed on
any timeline/button**. Flash-authored SWFs export a base class's symbol
alongside the subclass that extends it, so `SuperClass` (char 4) is a library
artifact that is never placed — and we ran its constructor standalone.

Ruffle never constructs anything from a SymbolClass row
(`movie_clip.rs preload_symbol_class` only *registers* the class); that loop
is a compatibility crutch for single-frame test movies whose one bound
character is defined but never placed.

**Fix (narrowest that keeps the crutch):** compute `any_placed` over all
bindings first and run the construct-never-placed loop **only when the movie
places none of its bound characters**. A movie that places at least one bound
character is a real display-list movie and its remaining bindings are library
artifacts. Extracted the placed-scan into `symbol_char_is_placed()` so both
passes share it.

### Blast radius — measured statically

`scratchpad/w2sym_scan_bindings.py` (new, read-only) read every cached
`RecompiledABC/abc_registry.c`: **16 of 2438 recompiled movies have no char-0
binding**, i.e. only those 16 can reach the changed branch at all. Every other
movie is untouched by this hunk. All 16 (plus the mandated
`avm2/symbol_class_conflict`) were `pass` at baseline and were all re-run:

```
PASS  avm2/goto_nested_construct_sibling      (7 bindings — the richest case)
PASS  avm2/place_object_same_depth_frame      (2 bindings)
PASS  avm2/symbol_class_root_not_zero
PASS  avm2/symbol_class_conflict              (spec-mandated canary)
PASS  avm2/mouse_pick_button_mode
PASS  avm2/bitmapdata_constructor_from_timeline
PASS  avm2/negative_volume_panned
PASS  avm2/loader_loadbytes_url               (the "binding to an undefined
                                               char becomes the root" case)
PASS  avm2/amf_setter_error
PASS  avm2/array_vector_null_callback
PASS  avm2/error_prototype
PASS  avm2/event_target_set
PASS  avm2/pixelbender_parse_errors
PASS  avm2/verify_typecheck
PASS  from_shumway/acid/acid-big
PASS  from_shumway/bitmapbuttons
PASS  avm2/subclass_superclass_linked_symbol  (the target: was output_mismatch)
```

All 16 canaries were `pass` in `results_graphics.json` @ `feb8882b0`, so any
non-PASS row would be a regression. **Zero regressions; +1 on the target.**

---

## `avm2/graphic_linkage` — investigated, NOT taken

Measured diff after the B8a fix (unchanged from baseline, gap 2):

```
   5  constructing child:
   6  MyText constructor
   7  my shape:
-  8  0            +  8  40.35
-  9  0            +  9  40.35
```

The first (timeline-placed) `MyText` is already correct at `40.35`. Only the
script-constructed `new MyText()` inside `Main`'s ctor is wrong: its linked
child must not be instantiated yet, so `this.width` must read `0`.

This is **not** the same mechanism as `subclass_superclass_linked_symbol`:
`graphic_linkage` *does* have a char-0 binding (`{0,"Main"},{22,"MyText"}`),
so it never enters the branch B8a changed. The site is
`avm2_display.c::display_native_init`'s script-`new` arm (~:10804), which
sets `ext->playing = (ext->timeline != NULL)` and then runs
`enter_frame_obj` + `construct_frame_obj` — that is what places MyText's
frame-1 child before the ctor body reads `width`.

Reason not taken: that arm is Ruffle's `initialize_for_allocator`
(display_object.rs:32-54), which genuinely *does* call `enter_frame` +
`construct_frame`, and Ruffle passes this test — so the discriminator is
somewhere in Ruffle's `MovieClip::enter_frame` /
`run_frame_internal` / `determine_next_frame` preload gating that I could not
pin down from source alone within budget. Changing `display_native_init`'s
script-`new` arm is the highest-traffic path in the AVM2 display layer
(hundreds of tests) and is not a change to make on an unproven hypothesis.
**Recommend re-scoping as its own batch with a Ruffle-side trace, not as a
polish single.**

---

## B8b — lazy DoABC script init: NOT taken (explicit)

Findings that bound the work:

1. We are **already partly lazy**. `avm2_main.c` step 3 eager-inits only each
   ABC file's **last** script; all other scripts init on first
   `avm2_domain_find` hit (`avm2_globals.c:133 avm2_script_ensure_init`, the
   `AVM2_SCRIPT_UNINITIALIZED` state machine). So the triage's "we run Z, C,
   B eagerly" is really "we eager-init the last script of each of the 2 ABC
   files, at load time".
2. `doabc_and_symbolclass_script_init_normal` has **2 ABC files** (abc0: 1
   script; abc1: 5 scripts) and 3 SymbolClass rows (`{0,"New"},{1,"C"},
   {2,"B"}`). The expected trace puts `C, Z, B` **after** the root ctor and
   after the frame-1 script's `#1065` line — i.e. the last-script eager init
   must be **deferred past root construction and the first frame script**,
   not merely made lazy.
3. That is a reordering of the whole `runSWF_avm2` step-3/step-4 contract, and
   the triage itself flags `avm2/symbol_class_conflict` + the whole
   `from_avmplus` driver population as pinning the current order (memory
   `avmplus-driver-eager-init-blanks-tests`: a prior eager/lazy change blanked
   tests).

Per the batch instruction ("if a clean lazy model doesn't fall out, take (a)
alone and report why") — **B8b is not attempted.** It is a real batch on its
own (est. M–L, needs a `categories=full` CI run of its own to grade), not a
rider on B8a.

---

## Merge risks / instructions for the coordinator

1. **Recompiler change.** `SWFRecomp/src/swf.cpp` is touched, so every merged
   test run must recompile: a stale `Recompiled*` cache yields false compile
   failures. CI recompiles from scratch, so this only affects local re-runs.
2. **`categories=full` is REQUIRED** for the merged wave. B8a changes
   `runSWF_avm2`'s SymbolClass handling; the `from_avmplus` driver population
   is exactly the constituency a script-init/symbol ordering change can blank
   (memory `avmplus-driver-eager-init-blanks-tests`). Also standing policy:
   the change touches AVM2 runtime + recompiler emission.
3. **Mode:** `graphics` (default). Neither hunk is inside a
   `NO_GRAPHICS`-only arm; `avm2_main.c` is shared runtime, `swf.cpp` is
   mode-independent.
4. **Conflicts:** `SWFRecomp/src/swf.cpp` — I was told I am the only wave-2
   agent authorized to touch the recompiler, so no conflict expected.
   `SWFModernRuntime/src/avm2/avm2_main.c` is a low-traffic file; the edit is
   confined to `runSWF_avm2`'s `root_class == NULL` else-branch plus one new
   static helper above `runSWF_avm2`.
5. **No disposition-doc updates needed** — neither target is in
   `ACCEPTED_DIFFS` / `RUFFLE_VS_FLASH_DIFFERENCES` / `RUFFLE_COMPAT_TWEAKS` /
   `FLASH_BUGS_REPLICATED` or any `ignored_tests.txt` (re-checked).
6. Two new read-only analysis scripts live in the scratchpad only
   (`w2sym_scan_swf.py`, `w2sym_scan_bindings.py`); nothing was added to the
   repo.
