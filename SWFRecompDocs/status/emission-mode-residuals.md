# Emission-mode residuals — status (2026-09-02)

Brief: `SWFRecompDocs/prompts/emission-mode-residuals-prompt.md`.
Baseline: `799f57092` (prompt commit `f162da7a6` on top).
Closes the two loose ends the three emission-option slices left behind —
`try_helper` (`avm2-try-helper-emission.md`), `tu_split`
(`avm2-tu-split-emission.md`), `skip_avm1_payload`
(`avm2-dead-payload-skip.md`). Neither was breaking anything today; both were
latent traps. No new option, no new mode, nothing on by default.

## Residual 1 — the `is_as3` gate is not "will run under AVM2"

### The seam, confirmed

`SWF::dropPayload()` was `skip_avm1_payload && is_as3`. `is_as3` is the
FileAttributes AS3 bit: it says the SWF's own code is AVM2, NOT that its
`tagInit` never runs. The AVM1 loader calls a loaded child's `init_func`
(= its `tagInit`) — `entry->init_func`, five sites in
`SWFModernRuntime/src/actionmodern/action.c` — so an AS3 SWF loaded as a child
by an AVM1 parent lost its AVM1-side bitmap/sound dictionary with the option
on. That configuration is also the one where the AVM2 copies of those bytes
are **not even linked**: `verify_output.py` compiles a child's `RecompiledABC`
only when the PARENT is an AVM2 test, so for an AVM1 parent the AVM1-side
dictionary is all a child has.

### The test (the deliverable half)

`ruffle-tests/tests/swfs/regression/avm1_parent_as3_child_payload/`
— generator + `Parent.as` shipped, per that suite's README.

- **child.swf** — hand-assembled: `FileAttributes` (AS3 bit) + `DefineSound`
  (8-bit mono, rate index 1, 2205 samples → exactly 200 ms) + `ExportAssets`
  (`childSound`) + `ShowFrame`. The AS3 bit alone is the exact predicate the
  option gates on, so it is the minimal trigger; a DoABC would change nothing
  (an AVM1 parent's build never compiles a child's ABC).
- **test.swf** — MTASC AVM1 (SWF8): `loadMovie("child.swf")` into a holder,
  then after three frames `new Sound().attachSound("childSound")` and
  `trace(s.getDuration())`.
- **Why that reads the dropped data and nothing else.** `tagRegisterExport`
  is NOT part of the payload, so `ng_lookupExport("childSound")` resolves
  either way; only `tagDefineSound` — and therefore
  `ng_registerSoundMetadata` / `ng_getSoundDuration` — is dropped. The
  observable is one line.

| | option OFF | `SWF_SKIP_AVM1_PAYLOAD=1` |
|---|---|---|
| before the fix | `dur:200` (pass) | **`dur:undefined` (FAIL)** |
| after the fix | `dur:200` (pass) | `dur:200` (pass) |

Both rows verified locally in `no-graphics` AND `--mode=graphics`.

### A harness bug the test found first

The test could not be written at all until two lines in `verify_output.py`'s
child-movie wrapper were fixed. `generate_child_movie_file` offsets a child's
character ids by `movie_id * 1000` and had a per-call regex list for it —
`tagDefineSprite`, `tagDefineShape`, `tagRegisterExport`, `tagPlaceObject2*`,
`tagDefineFont`, `tagDefineSoundMeta`, … — but **not `tagDefineSound` and not
`tagStartSound`**. So a child's sound registered its duration/rate metadata
under the RAW id while its export published the OFFSET id: `attachSound`
resolved the export, found no metadata, and `getDuration()` was `undefined`
for every AVM1-loaded child in the corpus, with no option involved. Both calls
are offset now, as a pair (before, both were raw and therefore accidentally
consistent for a child playing its own sound — moving only the define would
have broken that). One corpus test is in that shape,
`avm1/depth_replacement_audio_unloading`; it passes before and after, in both
modes.

### The fix, and what it costs

```cpp
bool isChildRecompile() const
{
    return child_movie || !abc_symbol_prefix.empty() || abc_char_id_base != 0;
}
bool dropPayload() const
{
    return skip_avm1_payload && is_as3 && !isChildRecompile();
}
```

`Config::child_movie` ← `[input] child_movie = true`, plumbed
Config → Context → SWF like the other three options. `recompile_child_swf`
writes it for **every** child, prefixed or not.

**The brief's cheapest candidate would not have worked.** "Require
`avm2_symbol_prefix.empty()`" assumes every child recompile carries a prefix;
an AVM1 parent's children are recompiled with none (`verify_output.py`, the
AVM1 branch calls `recompile_child_swf(child_swf, child_recomp_dir)` bare),
and that is exactly the failing configuration. The prefix and `char_id_base`
are kept in `isChildRecompile()` as belt-and-braces for any other caller that
sets them, but `child_movie` is what closes the seam.

**Cost:** a child movie keeps its AVM1 payload bytes even with the option on.
Children are rare and small — one AS3 child in the whole Ruffle corpus carries
a payload — and the mode's win is a root-movie win (the in-browser page
recompiles exactly one SWF). **Guarantee:** the payload is dropped only for a
SWF that is the movie its binary starts in, i.e. the one case where nothing can
call its `tagInit`.

### Verification

1. **Default emission byte-identical.** `git diff -- SWFRecomp > p.patch;
   git apply -R p.patch`, rebuild, recompile, restore, rebuild, recompile,
   `diff -r` (NOT `git stash` — shared across this repo's worktrees). Ten SWFs
   (`avm1/{try_catch_finally, sound_start_stop, bitmap_data_colortransform}`,
   `avm2/{sound_play, hello_world, try_catch, soundmixer_stopall}`,
   `visual/cache_as_bitmap/cab_mask_alpha`,
   `from_shumway/acid/acid-bitmap-fill-2`, this test's parent) plus the new
   child under four configurations:

   | configuration | old vs new |
   |---|---|
   | option OFF, root config | **identical** |
   | option ON, root config | **identical** (the win is untouched) |
   | option OFF, `child_movie = true` | **identical** |
   | option ON, `child_movie = true` | `draws.c` / `draws.h` / `tagMain.c` differ — the payload is back |
   | option ON, `symbol_prefix` + `char_id_base` | same difference |

   i.e. the change's entire footprint is "a child with the option on".
2. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over every
   generated `.c` of all of the above — **212 files, zero errors**, only the
   pre-existing `-Wmissing-braces` on `draws.c`. (`verify_output.py` compiles
   with `-w` and would not see a malformed declaration.)
3. **Local sweep** of 15 child-loading corpus tests
   (`mcl_*`, `loadmovie*`, `register_class*`, `do_init_action_child`,
   `cross_movie_root`, `depth_replacement_audio_unloading`, …): all pass.
   `avm2/loader_duplicate_class` and `mixed_avm/avm1_loads_avm2` still
   `output_mismatch` — both are `output_mismatch` at the published baseline
   too, unchanged.

## Residual 2 — the publish guard is now computed, not enumerated

### What was wrong

```
if: always() && inputs.extra_defines == '' && inputs.single_test == ''
    && inputs.try_helper == '' && inputs.tu_split == '' && inputs.skip_avm1_payload == ''
```

duplicated across two steps. Three slices in a row each appended a clause,
each after being bitten (memory `ci-verify-run-results-clobber`). The chain is
**fail-open**: forget it and the run publishes its incomparable numbers over
`{STEM}.json`, which is what the NEXT run fetches as `{STEM}_previous.json`.

### What landed

`scripts/ci/publish_gate.py`, run once in `combine-results` as step
`publish_gate`; both publish steps (results, and failing images) are gated on
`steps.publish_gate.outputs.publish == 'true'` and on nothing else. The rule:

> an input whose value differs from the default **declared in
> `ruffle-tests.yml` itself** blocks publishing, unless its name is in
> `PUBLISH_SAFE`.

`PUBLISH_SAFE` is four names — `mode` (it picks the stem, so each mode has its
own baseline), `categories` (a suite subset publishes only what it ran; the
others are inherited untouched — the documented cheap validation), `parallel`
(shards), `images` (an instrument; image comparisons never gate trace
pass/fail). Everything else blocks by not being there, **including an input
that does not exist yet**: a new option must be declared in the workflow to be
dispatchable, and the moment it is declared a run that sets it stops
publishing. That is the design constraint the brief asked for — forgetting is
no longer possible, and the fail direction is "publishes nothing", never
"publishes garbage".

The script parses `workflow_dispatch.inputs` and `workflow_call.inputs` and
**requires the two blocks to declare the same default** for a shared name
(they do); a divergence is an error, not a silent choice. Unparseable workflow,
unparseable inputs, missing output → `publish=false` AND a non-zero exit, so a
broken gate is loud and closed.

Two defects it closes beyond the brief:

- **`limit=N` used to publish a TRUNCATED results tree** over the baseline —
  a documented trap (memory `ci-cheap-validation-is-categories-not-limit`)
  that the `&&` chain never covered. It blocks now.
- **`swf_gc` / `avm2_gc` change what the binaries do and used to publish.**
  Same family as `extra_defines`; never guarded. They block now.

### Why not the `.recomp_mode` stamp

The brief floated gating on `verify_output.py`'s `.recomp_mode` stamp, since a
new emission option must be added there or its recompile caching breaks.
Rejected, for two reasons that are worth writing down:

1. **It is not reachable where the decision is made.** The stamp is written per
   test directory on the shard runners; the publish runs in `combine-results`,
   which has neither. It would need lifting to a job output or an artifact —
   real plumbing, with its own failure mode (a missing artifact must then be
   interpreted, and "missing" is ambiguous between "shard died" and "nothing
   to say").
2. **It covers only the recompiler's emission modes.** `extra_defines`,
   `single_test`, `swf_gc`, `avm2_gc` and `limit` never touch it, so the stamp
   could not be the whole gate — the `&&` chain would have survived alongside
   it, which is precisely the thing being removed.

The workflow's own input declarations are the better single source: every one
of those knobs is already there, by construction, because that is how they are
dispatched.

### Verification

- `python3 scripts/ci/publish_gate.py --self-test` — 14 cases against the real
  workflow file (defaults publish; `mode`/`categories`/`parallel`/`images`
  publish; `extra_defines`, `single_test`, `try_helper`, `tu_split`,
  `skip_avm1_payload`, `swf_gc`, `avm2_gc`, `limit` block; an **undeclared**
  input blocks). Also exercised against the two real callers'
  input sets (`all-tests.yml` with `parallel: '10'`, the weekly canary with
  `mode: no-graphics, categories: full`): both publish, as they must.
- Empty / `null` inputs (a bare `schedule:` trigger) → publish, correctly: no
  input is non-default. Malformed inputs → blocked, exit 1.
- CI: the default run below published; the forced-on run below did not (see
  "CI").
- `.claude/pipeline-handoff.md` gained a section stating the rule, and the
  guard site itself carries the note for a future option author.

## CI

_(filled in below once the runs land — see the commit for the numbers.)_

## Residuals of the residuals

- **Bitmaps in an AVM1-loaded child are still broken**, independently of any of
  this: `defineBitmap` records an offset into the emitted `bitmap_data`, and
  `BitmapData.loadBitmap` reads the MAIN movie's `bitmap_data` global, while a
  child's array is renamed `<prefix>_bitmap_data` by the wrapper. So a child's
  bitmap offsets index the parent's array. Nothing in the corpus exercises it;
  fixing it means giving the bitmap-metadata registry a per-movie data pointer.
  Sound has no such problem — its metadata is rate + sample count, no pointer —
  which is why the new regression test uses sound.
- `child_movie` is only ever set by `verify_output.py`. `docs/recompiler`'s
  `pipeline.js` recompiles exactly one SWF as the root movie, which is the
  correct default; a future in-page multi-SWF path must set it for children.
