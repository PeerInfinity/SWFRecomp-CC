# One child char-id stride, owned by the recompiler

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 2
**Baseline:** `eeea09ca3` · **Brief:** `SWFRecompDocs/prompts/child-charid-stride-unify-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-movie-charid-wrapper.md`

## The problem

Two different strides re-based the same loaded child, and they disagreed.

- `ruffle-tests/verify_output.py` handed the recompiler
  `char_id_base = movie_id * 10000`, which the recompiler applied **only** to
  the ABC/AVM2 emissions — the SymbolClass registry (`abc/abc_emit.cpp`) and
  the AVM2 timeline tables (`abc/abc_timeline.cpp`).
- The tag side of that same child was then re-based by the harness at
  `movie_id * 1000`, via the `CHARID()` substitution the previous slice
  installed.

So an AS3 child's `SymbolClass` binding named character 10001 while its
`tagDefineSprite` defined 1001. `SWFRecomp/include/config.hpp` documented
`char_id_base` as "added to every character id in the emitted tables" — which
was simply not true of the code.

## What this slice did

`charId()` (`SWFRecomp/src/swf.cpp`) adds a process-wide `g_char_id_base`,
set from `Config::char_id_base` in the `SWF` constructor, to every character id
the **tag pipeline** writes — the same config value the ABC emitters already
took. The harness's substitution is deleted. `Context::avm2_char_id_base` is
renamed `char_id_base`, because it is no longer AVM2-only.

`CHARID()` is still emitted. It looks redundant once the recompiler bakes in
the base and it is not: `scripts/check_charid_wrapping.py`, the completeness
oracle, keys on it, and `generate_child_movie_file` still hard-fails on any
char-id position holding a bare integer literal. Deleting the wrapper would
delete the arc's only mechanical guard. The *substitution* went away; the
*wrapper* stayed.

## The stride ruling: 1000, unifying DOWNWARD

The two candidates are not interchangeable, and the dictionary decides.

`INITIAL_DICTIONARY_CAPACITY` is **8192**
(`SWFModernRuntime/include/libswf/swf.h:40`, whose comment already says
"Increased to support per-movie char_id offsetting (1000 per child SWF)"). A
10000 stride puts the **first** child's characters at 10001+, past that number.

The brief's premise — `tag.c` grows the array and checks the growable
`dictionary_capacity`, `tag_stubs.c` checks the constant — **holds, and
understates the problem**. Read from the source, not from grep:

| site | check | build modes |
|---|---|---|
| `tag.c` `ENSURE_SIZE(dictionary, char_id, dictionary_capacity, …)` ×8 | grows | graphics |
| `tag.c:4232, :6072, :9411, :10089, :11724, :11743` | `dictionary_capacity` (growable) | graphics |
| `tag.c:9628, :9647, :10190, :10204` | **constant** | browser-WASM arms only (`!NO_GRAPHICS && !OFFSCREEN_RENDER`) |
| `tag_stubs.c:414, :883, :1511` | **constant** | NO_GRAPHICS / HEADLESS |
| `tag_stubs.c:1509` `dictionary[cid]` | **none at all** | NO_GRAPHICS / HEADLESS |
| `action.c:54533, :55121, :55189` (button-MC probes) | **constant** | **every mode** |

And `tag_stubs.c` contains **no `ENSURE_SIZE` on `dictionary` at all** — its
allocation is `swf_core.c:860`'s one-shot `HCALLOC(INITIAL_DICTIONARY_CAPACITY,
…)`, never grown. So under a 10000 stride the no-graphics build would not
merely return NULL at the three guarded sites; the unguarded index at
`tag_stubs.c:1509` reads off the end of the array.

Two more reasons 1000 is the right call:

- it moves only **AVM2 child** ids (10001 → 1001). The AVM1 tag side does not
  move at all, which is why the generated C for an unchanged child is
  byte-identical (verified below). Unifying upward would have moved every
  child's tag-side id instead, into exactly the range the checks above break in.
- nothing currently reads across the boundary, so the downward move is
  observationally free.

**The cost, stated plainly:** a child movie is capped at 999 characters, and a
corpus SWF with more would silently collide with the next child. The corpus has
at most two children and none is anywhere near that. Raising the stride means
fixing the constant-vs-variable divergence first — filed as its own BACKLOG
entry, so it is a work item and not a trap.

## No repro exists, and that is the finding

The brief asked for a failing test first and warned to be honest about whether
the disagreement is observable. It is not, and the reason is structural:

- **AVM2 never reads the AVM1 dictionary.** `grep 'dictionary\[' src/avm2/*.c`
  returns nothing. The AVM2 side has its own char-keyed tables
  (`char_info`, `timeline_for_char`, the per-movie `Avm2MovieTables`), and
  every one of them is consistent with the SymbolClass rows because both are
  offset by the same `char_id_base` at emission.
- **An AVM1 parent never compiles an AVM2 child's ABC at all.** The brief's
  suggested shape — "an AS3 child of an AVM1 parent whose SymbolClass-bound
  character is also placed by a tag" — cannot work: `verify_output.py` links a
  child's `RecompiledABC` only when the **parent** is an AVM2 test
  (`if is_avm2 and child_abc.exists()`), because an AVM1 parent's build does
  not compile `src/avm2` at all. In that configuration the 10001 half of the
  disagreement is not even present in the binary.
- **The AVM1 half does not move.** Unifying downward leaves every tag-side id
  exactly where it was, so no AVM1-visible behaviour can change.

The disagreement was real and worth ending; it was never observable. Both new
tests are **locks**, and both say so.

## The tests

### `regression/avm2_parent_child_symbol_stride` — a lock, with a positive control

Two AVM2 SWFs (mxmlc): the parent `Loader.load`s a 3-frame child that carries
an embedded PNG, so the child has a second, non-zero character with its own
SymbolClass row.

| row | reads | baseline | after |
|---|---|---|---|
| `child:tf3` | the child root's `declared_frames`, out of `child_avm2_generated_timelines` keyed by char id. The "no timeline row" fallback is **1** (`avm2_display.c` `total_frames`), so `3` can only be a hit | `tf3` | `tf3` |
| `child:…:Child_Pix` | the embedded PNG's class — proves `char_id_base + 0` is not the only id in the movie | ok | ok |
| `root:Child` | `loader_boot_child_swf` finds the root class by matching a SymbolClass row's `char_id` against `tables->char_id_base` | `Child` | `Child` |

Both rows pass at the baseline: **locks, not repros.** They do discriminate,
though. Positive control — emitting the tables aggregate's base as
`info.char_id_base + 1` (`abc/abc_timeline.cpp`), a one-off desync between the
base and the rows built from it:

```
-  child:tf3:Child_Pix
+  TypeError: Error #2023: Class Child_Pix$ must inherit from Sprite to link to the root.
-  root:Child
+  root:flash.display::MovieClip
```

The child is built with `-frames.frame` specifically so `totalFrames` is not 1:
a 1-frame child could not tell a table hit from the fallback.

### `regression/avm1_parent_child_modify_place` — a lock that does NOT discriminate

Character id 0 is the sentinel `charId()` must skip, and the brief called
reintroducing that "the single most likely way to break this slice". It had
**no test coverage at all**, and still effectively has none — measured, not
assumed.

Sabotage: `return "CHARID(" + std::to_string(id + g_char_id_base) + ")";`,
rebuilt. Result: `avm1_parent_child_sprite_meta`, `avm1_parent_child_bitmap`,
`avm1_parent_as3_child_payload` **all still pass**. Their children's only
char-id-0 emissions are the 0-filled sentinel ROWS of empty `FramePlacement` /
`SpriteFrameScriptEntry` arrays, which nothing reads.

So the new test gives a child a real Modify — `PlaceObject2` with `Move` set
and `HasCharacter` clear, at an occupied depth — and gives the **parent** a
decoy sprite defined at char id 1000, the exact value a re-based sentinel would
produce, so the offset id names a real character in the shared dictionary
rather than nothing. It still does not flip. Three independent reasons, each
checked by hand:

1. A `tagPlaceObject2` of any character at an already-occupied depth with
   `is_replace == 0` — what the recompiler emits for a Move tag — is a no-op.
   The decoy never displaces `mc`.
2. The Modify's own effect is unreadable: `_root.holder.mc._x` on a child
   movie's **tag-placed** clip returns uninitialized memory (8197.8125,
   -1.92062288988382e-6, -1.48600998484698e+20 across three runs). It
   reproduces with the Modify tag removed entirely, so it is the placement
   path, not the Modify path — a separate defect, filed.
3. `PlaceObject2 Move|HasName` (a rename Modify) is also a no-op, so the name
   cannot carry the signal either.

Shipped anyway, and labelled: it is the only child in the suite whose generated
C carries `CHARID(0)` in a **live** `tagPlaceObject2` argument. The moment
reason 1 changes, it starts discriminating with the decoy already in place.
This is what the previous slice's "it never reached a graded test" actually
means, now with a mechanism behind it.

## Defects found on the way (neither fixed here)

- **`embedded_bitmap_for_char` never consults child movies.**
  `avm2_bitmap.c:757` scans only the main movie's `avm2_generated_bitmaps`,
  unlike `char_info` and `timeline_for_char` in `avm2_display.c`, which both
  fall through to `g_child_movies`. A loaded AVM2 child's `[Embed]`ed image
  instantiates as a `BitmapData` subclass reporting **0x0**; the same SWF run
  as the main movie reports `4x3`. Independent of the stride — it reproduces
  at 10000 and at 1000. This is a third instance of the child-bitmap family
  already in the BACKLOG, and the fix is the same six-line loop.
- **`_x` on a loaded child's tag-placed clip is uninitialized** (above).
  `_name` and `typeof` on the same object read correctly.

## Where the brief was wrong

- **§2's dictionary reading holds but understates it.** The divergence is not
  "tag.c growable vs tag_stubs.c constant": `action.c`'s three button-MC probes
  compare against the constant in **every** build mode, `tag_stubs.c` has an
  **unguarded** `dictionary[cid]` at :1509, and `swf_core.c` never grows the
  array in the no-graphics build at all. A 10000 stride would have been worse
  than mode-dependent silence.
- **§4's suggested test shape cannot exist.** "An AS3 child of an AVM1 parent
  whose SymbolClass-bound character is also placed by a tag" reads a row that
  is never compiled — `verify_output.py` links a child's ABC only for AVM2
  parents. The observable configuration is an AVM2 parent, which is what the
  test became.
- **The brief did not mention `compile_wasm`, which the change would have
  broken.** `compile_wasm` (`verify_output.py:2790`) recompiled children with
  `recompile_child_swf(child_swf, child_recomp_dir)` — no `char_id_base`, no
  symbol prefix — and depended entirely on the harness substitution for the
  offset. Moving the offset into the recompiler without passing the base there
  would have left every WASM-built child's dictionary colliding with its
  parent's. It now passes the base.

## Verification

1. **Byte-identity.** Generated `movie_child.c`, `movie_registry.c` and
   `tagMain.c` of `avm1_parent_child_sprite_meta` are **identical** to the
   baseline build's, diffed file by file (baseline restored with
   `git apply -R` on a patch file — `git stash` is shared across this repo's
   worktrees). Which is the expected result: the AVM1 stride did not move, and
   at `char_id_base == 0` `charId()` is arithmetically what it was.
2. **The AVM2 ids did move**, from the same run's build dir:
   `child_abc_timeline.c` rows `{1000, 3, 3, …}` / `{1001, …}` and
   `child_abc_registry.c` `{1001, "Child_Pix"}` / `{1000, "Child"}`, all 10001
   before. `movie_child.c` carries `CHARID(1001)` and `CHARID(0)` — the
   sentinel preserved.
3. **Oracle, both modes.**
   - `--emitter`: *clean — every char-id call SWFRecomp/src/swf.cpp emits goes
     through charId(*
   - generated-C over the three multi-SWF build dirs: *clean over 95 / 42 / 42
     file(s)*
4. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over
   `movie_child.c` / `tagMain.c` / `draws.c` / `constants.c` (and the child's
   `child_abc_timeline.c` / `child_abc_registry.c`) of all three build dirs:
   no errors, and only the two pre-existing warnings the previous slice
   recorded — `-Wmissing-braces` on the transform arrays and the
   `MAX_STRING_ID` redefinition note. `verify_output.py` compiles with `-w`
   and shows neither.
5. **Corpus oracle sweep, as CHILDREN.** 311 corpus SWFs recompiled with
   `char_id_base = 1000` and `child_movie = true` — so every character id
   actually moves — across `regression`, `avm1`, `avm2`, `from_gnash`,
   `from_shumway` and five misc categories: *recompiled 311 SWFs (0 would not
   recompile), checked 1497 generated files · CHARID oracle: CLEAN*.
6. **The 0 sentinel, checked mechanically rather than by test.** Because the
   sweep's base is 1000, `CHARID(1000)` in a child's generated C can ONLY
   come from a re-based 0. Over 220 corpus SWFs recompiled that way: **264
   `CHARID(0)` occurrences preserved, 0 `CHARID(1000)`**. That is the
   guarantee the (non-discriminating) Modify test could not give, and it is
   the check to re-run if `charId()` is ever touched.
7. **Regression suite: 77/77**, `--recompile`, no changes vs previous.
8. **CI.** See below.

## CI

### `mode=graphics`, `categories=full`, `images=false` — run `33790559670`

At `50fcc7f8b`, conclusion **success**, all 30 shards present, results merged
(`f1df5142e`).

`scripts/corpus_status_diff.py --stem results_graphics eeea09ca3 WORKTREE`
(baseline = this slice's own base commit, carrying the previous slice's merged
results):

```
=== intersection: 4485 tests (eeea09ca3 -> WORKTREE, results_graphics) ===

STATUS HISTOGRAM
  output_mismatch    124 ->   124 (+0)
  pass              4125 ->  4125 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4360 ->  4360 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

Every bucket unmoved — not just the pass/fail line. That is what an emission
change touching every SWF's generated C should look like when the AVM1 stride
does not move and no AVM2 test reads a child id it did not also emit.

The suites that actually exercise loaded children:

- `regression` **77/77**, all five multi-SWF tests green:
  `avm2_parent_child_symbol_stride` (new), `avm1_parent_child_modify_place`
  (new), `avm1_parent_child_sprite_meta`, `avm1_parent_child_bitmap`,
  `avm1_parent_as3_child_payload`.
- `avm2` 1180 pass / 33 `ruffle_matched` / 48 fail — the suite that carries
  the `loader_*` / `instantiate_root_character` /
  `subclass_superclass_linked_symbol` tests, i.e. every AVM2 child whose ids
  this slice moved from 10001 to 1001. Unchanged.
- `mixed_avm` 10 pass / 2 `output_mismatch` — unchanged.
- `import_assets` 3/3 — the suite exercising `tagImportCharacter`.
- `avm1` 689 pass / 23 `output_mismatch` / 18 `ruffle_matched` — unchanged.

The +2 tests versus the previous slice's 4485-graded baseline are this slice's
two new regression tests.

### `mode=no-graphics`, `categories=full`, `images=false` — run `33790602469`

Dispatched because the dictionary bound check differs between `tag.c` and
`tag_stubs.c` — CLAUDE.md's "when in doubt for shared runtime code, run both",
and here it was not doubt but the exact axis the stride ruling turns on. At
`50fcc7f8b`, conclusion **success**, 30/30 shards.

`scripts/corpus_status_diff.py --stem results eeea09ca3 WORKTREE`:

```
=== intersection: 4484 tests (eeea09ca3 -> WORKTREE, results) ===

STATUS HISTOGRAM
  output_mismatch    123 ->   123 (+0)
  pass              4124 ->  4124 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4360 ->  4360 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

`regression` 77/77 here too, with all five multi-SWF tests green. The
no-graphics histogram differs from the graphics one by one test moving between
`output_mismatch` and `ruffle_matched` — a pre-existing, unrelated
mode difference present on both sides of the diff, not something this slice
introduced (both modes read `+0` in every bucket against their own baseline).

Merging the no-graphics publish conflicted on
`regression/_results/results.json`, because this slice's commit carried a
locally-generated copy from its `--recompile` suite run. Resolved
`--theirs`: CI's is the authoritative one.

## What is left of the arc

The mechanism half is closed. `char_id_base` is one number, applied in one
place, checked by an oracle that runs in two independent modes.

Still open, all independent of each other and of this slice:

- **The renderer's per-movie static-bitmap range** — a loaded child's bitmaps
  still never reach the renderer (BACKLOG §Multi-SWF, unchanged).
- **`flashbang_upload_bitmap`'s fix is unverified** (BACKLOG, unchanged).
- **`embedded_bitmap_for_char` ignores child movies** — new, found here.
- **`_x` on a child's tag-placed clip is uninitialized** — new, found here.
- **The constant-vs-`dictionary_capacity` divergence** — new, and the
  prerequisite for ever raising the stride above 1000.
