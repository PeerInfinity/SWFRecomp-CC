# w2-hitarea-2 — regression fix: `avm2/mouse_pick_avm1_root`

Follow-up to `w2-hitarea-report.md` / commit `8072df940`. Branched from **CURRENT master
`304bb4df4`** (which contains `8072df940` plus the unrelated SWF4 coercion gate `abb3faee3`
and the merged results). Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a56288bb3a7a1f23a`. No commits, no pushes.
Logs: `<scratchpad>/w2-hitarea/*2_*.log`, saved raw outputs in `<scratchpad>/w2-hitarea/a2_*/`.

## NEW files (coordinator stages by name)

- `SWFRecompDocs/plans/session19-fanout-reports/w2-hitarea-2-avm1root.patch`
- `SWFRecompDocs/plans/session19-fanout-reports/w2-hitarea-2-avm1root-report.md` (this file)

One source file, **one field**: `SWFModernRuntime/src/actionmodern/action.c`,
`getOrCreateLevel()`. Runtime only, shared code, no `#ifdef` arm → **CI mode `graphics`**.
The repro lives in the `avm2` suite and the neighbours in `mixed_avm`, so dispatch
**`categories=full`**: `categories=all` would not have graded `mixed_avm`, and it is
`categories=full` that caught this one.

---

## 0. Verdict

**Owned, reproduced, root-caused, fixed. The regression is mine; the gate does NOT have to
stay as-is, because the gate was not actually wrong — the data it read was.**

| test | before (master `304bb4df4`) | after | 
|---|---|---|
| `avm2/mouse_pick_avm1_root` | `output_mismatch` (1/2, AVM1 child's click missing) | **PASS** |
| `avm1/hitarea_sweep` | pass | **pass** (kept) |

Also verified in `--mode=graphics` (the CI grading mode): `avm2/mouse_pick_avm1_root` **PASS**.

---

## 1. Root cause — a pre-existing uninitialized field, not the gate

`ng_mc_pick_visible` walks the clip's parent chain and rejects the pick if any link has
`visible == 0`. Instrumented run (`HITDBG` build, `<scratchpad>/w2-hitarea/dbg1.log`):

```
[HITDBG] clip chain[0] p=0x62efbd4c3bf0 name='clip'    visible=1 isroot=0
[HITDBG] clip chain[1] p=0x7fa68a5626a0 name='_level1' visible=0 isroot=0
```

The AVM1 child in this test lives under `_level1` — the synthetic level root minted for the
`avm1.swf` that the AVM2 `Loader` pulled in. **`_level1.visible` is 0, and always has been.**

There are exactly two places in the whole runtime that allocate a `MovieClip`:

| site | allocator | sets `visible` |
|---|---|---|
| `createMovieClip` (action.c:21888) | `calloc` | **yes**, `mc->visible = 1` |
| `getOrCreateLevel` (action.c:22022) | `HCALLOC` | **no** |

`getOrCreateLevel` zero-initializes and then explicitly repairs only a handful of fields.
It already carries a comment about *this exact bug class* — a previous session had to add
`xscale = yscale = 100` there because the zeroed scale made the level's matrix
determinant 0 and broke drop-target hit tests for every level-rooted descendant. `visible`
is the same omission, one field over.

So `_levelN._visible` has been reading back as `false` in every movie that loads a level,
since long before this session. It was simply inert: nothing consulted it until AVM1 picking
grew Ruffle's `if self.visible()` gate (`mouse_pick_avm1`, `movie_clip.rs:2995`), which walks
the parent chain — at which point every clip under a loaded level stopped receiving mouse
events.

**Fix** (whole patch):

```c
     mc->xscale = 100;
     mc->yscale = 100;
+    // Same class of bug as the xscale/yscale zero above: HCALLOC leaves
+    // `visible` at 0, so a freshly minted level root reads back as HIDDEN.
+    ...
+    mc->visible = 1;
     g_levels[level_num] = mc;
```

### On the coordinator's hypothesis

> "a NULL/absent owner is being treated as 'not visible' instead of 'no gate'"

Close, but not quite: the owner is neither NULL nor absent. `_level1` is a perfectly real,
registered `MovieClip` in `child_mc_cache` — it just carries a wrong value. That distinction
matters for the fix: a "no gate when the owner looks synthetic" band-aid would have papered
over a genuine data bug and left `_level1._visible` reporting `false` to script. Fixing the
initializer is both smaller (one field) and strictly more correct.

### What I did NOT fix, deliberately

`getOrCreateLevel` leaves several *other* `createMovieClip` defaults at zero:
`alpha` (0 instead of 100), `currentframe`/`totalframes`/`framesloaded` (0 instead of 1),
`highquality`, `focusrect` (0 instead of the −1 "null" sentinel), `soundbuftime`, `quality`.
Each is a latent readback bug of the same family, but none is load-bearing today and each
could move a `_levelN` property row in the gnash/level tests. Repairing them is a separate,
separately-measured change — listed as a lead in §4, not smuggled into a regression fix.

---

## 2. Attribution — `mouse_pick_avm1_root` was the ONLY row my patch broke

Read from the CI results the coordinator merged, comparing the run at `d8da5a18c` (post-patch)
against `results_graphics_previous.json` at `521a53782` (pre-patch):

| test | `521a53782` (pre-patch) | `d8da5a18c` (post-patch) | mine? |
|---|---|---|---|
| `avm2/mouse_pick_avm1_root` | **pass** | **output_mismatch** | **YES — fixed here** |
| `avm2/avm1_root` | output_mismatch | output_mismatch | no, pre-existing |
| `avm2/mouse_pick_loader_avm1` | output_mismatch | output_mismatch | no, pre-existing |
| `mixed_avm/avm1_loads_avm2` | output_mismatch | output_mismatch | no, pre-existing |
| `mixed_avm/avm2_loads_avm1_events` | output_mismatch | output_mismatch | no, pre-existing |
| `avm1/hitarea_sweep` | output_mismatch | **pass** | the intended flip |

Both runs are `categories=full`, so `mixed_avm` really was graded on both sides — those four
cross-VM rows are genuinely older failures, not collateral.

---

## 3. Ledger — the cross-VM / level-root family the first sweep missed

The coordinator's diagnosis of the process gap is correct and worth recording: my first sweep
was selected by *feature* (hitArea, picking, drag, accessors) and by *suite* (avm1,
from_shumway, from_gnash). The change actually cut along a different axis — **"any AVM1 clip
whose parent chain passes through a loaded level or an AVM2 root"** — and that axis has its
rows in `avm2` and `mixed_avm`. Covered now.

Baselines read fresh from `_results/results_graphics.json` at `d8da5a18c` (i.e. the current,
regressed master), so "before" below is the state the coordinator is looking at.

### 3.1 Headline

| test | suite | before | after |
|---|---|---|---|
| `mouse_pick_avm1_root` | avm2 | `output_mismatch` | **PASS** |
| `hitarea_sweep` | avm1 | pass | **pass** |
| `hitarea_lazy_getter` | avm1 | pass | **pass** |
| `hitarea_remove_sibling` | avm1 | pass | **pass** |
| `hitarea` | from_shumway/avm1 | pass | **pass** |

### 3.2 The cross-VM picking family (`avm2` suite, grepped for `mouse_pick*` + `avm1_root`)

| test | before | after |
|---|---|---|
| `mouse_pick_avm1_root` | output_mismatch | **PASS** |
| `mouse_pick_button_mode` | pass | **pass** |
| `mouse_pick_dobj_mask` | pass | **pass** |
| `mouse_pick_masking` | pass | **pass** |
| `mouse_pick_non_interactive_bitmap_mask` | pass | **pass** |
| `mouse_pick_non_interactive_dobj_mask` | pass | **pass** |
| `mouse_pick_text` | pass | **pass** |
| `mouse_pick_loader_avm1` | output_mismatch | output_mismatch, **byte-identical** |
| `avm1_root` | output_mismatch | output_mismatch, **byte-identical** |

### 3.3 `mixed_avm` — the whole 8-test category

`avm2_loads_avm1`, `avm2_loads_avm1_doabc`, `avm2_loads_avm1_v9`, `avm2_loads_avm1_v10`,
`avm2_loads_avm1_loads_into_root`, `avm2_loads_avm1_loads_avm2_doabc`: **6 pass → 6 pass**.
`avm1_loads_avm2`, `avm2_loads_avm1_events`: output_mismatch → output_mismatch,
**byte-identical** (both pre-existing, §2).

### 3.4 Level-root consumers (the field I changed)

`loadmovienum`, `loadmovienum_cross_version_prototype`, `remove_different_level`,
`unloadmovienum`, `loadmovie`, `loadmovie_replace_root`, `mcl_loadclip`,
`mcl_loadclip_replace_root`, `unloadmovie`, `localconnection_top_level` — **10 pass → 10 pass**.
`mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6` — `ruffle_matched` both legs,
**byte-identical**. `from_shumway/avm1/levels`, `loadevent`, `moviecliploader` —
**3 pass → 3 pass** (`levels` also byte-compared).

### 3.5 Mouse/hitArea canaries kept from the first sweep

`avm1/drag_drop`, `avm1/mouse_events`, `avm1/button_children`,
`from_shumway/avm1/{mouse-transparency, nested-button, rollover}` — **6 pass → 6 pass**.
`avm1/hitarea_remove_owner_drag` — output_mismatch → output_mismatch, **byte-identical**
(still the single-mechanism G5 lead from the first report's R3).

### 3.6 A/B method

Status parity can hide a line change (the `ruffle-matched-trap`), so every non-`pass` row
above was run on **pristine master** and again **with the fix**, saving raw output with
`--save-actual` and comparing with `cmp`. All eight came back `IDENTICAL`:
`avm1_root`, `mouse_pick_loader_avm1`, `avm1_loads_avm2`, `avm2_loads_avm1_events`,
`hitarea_remove_owner_drag`, `mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6`,
`levels`.

### 3.7 `regression` suite

**95/95 pass**, `[diff] pass: 95/95 | vs prev: no changes` — unchanged from the first
report's run.

---

## 4. New unclaimed leads

1. **`getOrCreateLevel`'s other zeroed defaults** (§1): `alpha`, `currentframe`,
   `totalframes`, `framesloaded`, `highquality`, `focusrect`, `soundbuftime`, `quality`.
   `_levelN._alpha` reads 0 and `_levelN._currentframe` reads 0 today. Completion mechanism:
   factor the non-zero-default block out of `createMovieClip` into one helper and call it from
   both allocation sites, so the next field added cannot diverge again. Wants its own
   measurement pass over the level/gnash rows — this is the third time this one function has
   been patched one field at a time (`xscale`/`yscale`, `ng_textfield_idx`, now `visible`).
2. **A `regression/` fixture for "AVM1 clip under a loaded level receives mouse events"**
   would have caught this locally. `avm2/mouse_pick_avm1_root` covers it upstream, but the
   project's own suite has no level-rooted picking row.
3. `avm2/avm1_root`, `avm2/mouse_pick_loader_avm1`, `mixed_avm/avm1_loads_avm2`,
   `mixed_avm/avm2_loads_avm1_events` remain `output_mismatch` from before this session —
   unclaimed, and now known to be untouched by the hitArea work.
