# w2-fuzz-triage — session 14 wave-2: `from_shumway/fuzz`, the 16 un-triaged rows

**Agent:** wave-2 `fuzz-triage` (triage + implementation, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a796312c4cd7f7f36`).
**Base:** `0a99be1a9`. **Baseline audited:** CI run `31130292354` at `fb36ba110`
(trace 4237 effective). **Board item:** wave1-board-audit §3.1 (T1, "up to +16,
the biggest un-owned block in the corpus").

**Result: +15 effective (15 of 16 flip to `pass` — exact Flash match, not
`ruffle_matched`), 0 regressions. The fuzz suite goes 14/30 → 29/30 effective.**

---

## 0. TL;DR

- **The brief's framing is refuted, and that is the whole finding.** These are
  *not* invalid-opcode / stack-underflow / truncated-tag error-recovery tests.
  Every one of the 744 `DoAction` bodies in the entire 30-test corpus is the
  identical 6-instruction script `trace(this._currentframe)`; the only other
  action is one `getURL("FSCommand:quit")` per file. There is not a single
  malformed *bytecode* stream, not a single over-long tag length, and
  `declared_len == actual_len` for all 30 files. **`from_shumway/fuzz` is a
  pure AVM1 timeline-execution-order suite** — randomly generated sprite
  nesting, placement depths and frame counts, tracing which clip is on which
  frame in which order (§1).
- **Two mechanisms, both shared across all 16 rows, both cheap** (§2, §3):
  1. **`ASF_SORT_CAP` gated on the wrong variable.** The runtime already
     implements Ruffle's reverse-instantiation `clip_exec_list` order, but
     falls back to depth-descending when `max_depth >= 512` — testing the
     highest depth *index* instead of the *count* of occupied depths. Fuzz
     SWFs place a handful of clips at sparse random depths up to 1024, so the
     correct ordering was silently abandoned. **All 16 failing rows have
     `max_depth >= 512`; the correlation is perfect.**
  2. **A `DefineSprite` whose body has no terminating `End` record must not
     loop.** Flash/Ruffle park such a clip on its last frame
     (`determine_next_frame` → `NextFrame::Same` → `stop()`; Ruffle's own field
     doc: *"Clips without an End tag should not loop, even if they have
     multiple frames"*). **143 of 143 sprites in the fuzz corpus omit the End
     record** — *that* is the malformation the suite is actually testing, and
     it is exactly the "where Flash stops recovering" the brief predicted, one
     level up from where the brief looked for it.
- **A 60-line Python simulator of the AVM1 tick reproduces `output.ruffle.txt`
  byte-exactly on 16 of the 17 rows that ship one** (§2.1). That is what turned
  this from guesswork into a spec: the simulator *is* the oracle, and diffing
  our engine against it named both mechanisms before a line of C was written.
- **One row is diagnosed and deliberately not taken** (§5): `e152812e2cfc` is
  now short by exactly **one line** — the string
  `Warning: Failed to place object at depth 1015.`. Placement *behaviour*
  already matches; only the diagnostic is missing, and emitting it safely needs
  its own canary sweep (§5.1). Gap 20 → 1.
- **Canaries: zero regressions** across all 30 fuzz tests, the avm1
  execution-order/depth family, and the from_shumway avm1 family (§4). The two
  previously-`ruffle_matched` fuzz rows *upgraded* to full `pass`.

---

## 1. What these tests actually are

Disassembling all 30 SWFs (scratchpad `swfdump.py`, a full tag + AVM1 action
disassembler written for this task):

| property | value across all 30 tests |
|---|---|
| distinct `DoAction` bodies | **2** |
| — `Push 'this'; GetVariable; Push '_currentframe'; GetMember; Trace` | 744 occurrences |
| — `GetURL "FSCommand:quit"` | 30 (exactly one per file, on the last main frame) |
| truncated / overrunning tags | **0** |
| `declared_len != uncompressed_len` | **0** |
| tag set | `ShowFrame`, `DoAction`, `PlaceObject2`, `DefineSprite`, `FileAttributes`, `End` |
| nested `PlaceObject2` inside a sprite | none — the sprite tree is flat |
| `RemoveObject` of any form | none |
| sprite `declared frame count != ShowFrame count` | **0** |

So each test is: a main timeline of N frames that places some sprites at random
depths; every sprite frame and some main frames trace the tracing clip's own
`_currentframe`; the last main frame quits. **The expected output is a pure
record of AVM1 frame-execution order and playhead position.** Nothing recovers
from anything.

This also means the cluster is the *same mechanism family* as the
`from_gnash/misc-ming.all/action_order/` 7-row arc named in §14.3 — the two
should be read together by whoever takes that arc next.

## 2. Deriving the spec: the simulator

Because the action body is trivial and constant, the entire expected output is a
function of the timeline model alone. I extracted a JSON model per SWF
(`extract.py`) and wrote a parametrised simulator of the AVM1 tick (`sim.py`),
then fitted its parameters against the 30 `output.txt` files.

The winning model — confirmed independently against Ruffle's source — is:

- **One flat global execution list in reverse-instantiation order** (newest clip
  first, `_level0` **last**), *not* a display-tree walk and *not* depth order.
  Ruffle: `Avm1::run_frame` over `clip_exec_list`, which `add_to_exec_list`
  **prepends** to (`core/src/avm1/runtime.rs:519-568`).
- **A newly placed child runs its frame 1 inline, at the point of the
  `PlaceObject2` tag**, and is not visited again that tick
  (`instantiate_child` → `child.run_frame_avm1(context)`,
  `core/src/display_object/movie_clip.rs:1554-1564`). So the parent's own
  `DoAction` — queued earlier in the same tag stream — runs *before* the new
  child's frame-1 script, while on every later tick the child runs *before* the
  parent.
- **One FIFO action queue, drained once at the end of the tick**, never during
  the advance (`Player::run_actions`, `core/src/player.rs:2377`).
- **A sprite without an `End` record does not loop** (mechanism M2, §3.2).

### 2.1 The simulator is the oracle

With those rules the simulator reproduces **`output.ruffle.txt` byte-exactly on
16 of the 17** fuzz tests that ship one (the 17th, `356bf4ddf127`, differs at 3
of 65 lines). It also reproduces Flash's `output.txt` exactly on 12 of 30.

That dual agreement is what made the diagnosis safe: any place our engine's
output diverged from the simulator was a real engine bug, and the simulator told
me *which tick and which clip* diverged without a single instrumented build.

## 3. The two mechanisms

### 3.1 M1 — `ASF_SORT_CAP` tested against `max_depth` instead of the occupied count

`advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c`) already implements
the reverse-instantiation order, explicitly citing Ruffle's `clip_exec_list`.
But it gated it on:

```c
int use_sorted = (max_depth < ASF_SORT_CAP);   /* ASF_SORT_CAP == 512 */
```

`max_depth` is the highest occupied depth **index**, not how many entries the
sort needs to hold. `PlaceObject2` depth is a `u16`, so any SWF that places even
two clips at, say, depth 600 and 900 exceeded the cap and silently fell back to
**depth-descending** — a different, wrong order.

**Every one of the 16 failing rows has `max_depth >= 512`** (836…1024). The
correlation is perfect and was the first hard evidence for M1.

Fixed at three sites that share the identical shape — `advance_sprite_frames`,
`advance_nested_sprite_frames`, and
`dispatch_enterframe_clip_actions_recursive` — by building the array first with
a bounds check and falling back only if the *occupied count* overflows:

```c
int use_sorted = 1;
for (size_t d = 1; d <= max_depth; d++) {
    if (display_list[d].char_id == 0) continue;
    if (n_sorted >= ASF_SORT_CAP) { use_sorted = 0; n_sorted = 0; break; }
    ...
}
```

**M1 alone flipped exactly 1 row** (`f40458686ee6`, the row the board audit
singled out as "an ordering difference, not over-production" — precisely right).
It changes no line *counts*, only order, which is why it needed M2 to pay out.

### 3.2 M2 — a `DefineSprite` with no `End` record does not loop

Ruffle, `core/src/display_object/movie_clip.rs`:

```rust
} else if self.frames_loaded() <= 1 || !mc.preload_progress.has_end_tag.get() {
    NextFrame::Same          // -> run_frame_internal answers with self.stop(context)
}
```

with the field doc *"Clips without an End tag should not loop, even if they have
multiple frames."* The clip is only **stopped**, not removed: it keeps its
display-list slot, still receives `ENTER_FRAME`, and its children keep
advancing.

**All 143 sprites across all 30 fuzz SWFs omit the terminating `End` record.**
Our engine wrapped them (`(frame + 1) % sprite_frame_count`), so every sprite
restarted and re-traced forever — which is exactly the 1.1×–2.4× over-production
the board audit measured, and why `42f71d860e22` emitted 173 lines for 71.

Implemented as:

- `Character.sprite_has_end_tag` (new `u8` in the DefineSprite union arm),
  written unconditionally in `tagDefineSpriteEx` — the struct is a union, so a
  stale byte from another character type would be read otherwise. Default **1**
  (loops), so nothing changes unless the recompiler positively saw a missing
  `End`.
- `tagSetSpriteNoEndTag(app_context, char_id)` — a new runtime setter emitted by
  the recompiler **only** in the malformed case. Generated output for
  well-formed SWFs is byte-identical, which keeps the corpus-wide
  `Recompiled*` caches and diffs stable.
- Recompiler (`SWFRecomp/src/swf.cpp`): the sprite sub-tag loop already
  distinguished "exited by boundary" from "saw `SWF_TAG_END_TAG`"; that existing
  condition now also emits the setter.
- Runtime: at the single shared wrap site in `advance_sprite_frames`
  (`advance_nested_sprite_frames` funnels through it), a wrap on a sprite with
  `!sprite_has_end_tag` calls `ng_sprite_park_no_end_tag(obj)`, which sets
  `sprite_is_playing = 0` — the existing `!sprite_is_playing` branch already
  does the right thing (park the playhead, keep recursing into children).

**Blast radius is nil for real content**: every authoring tool emits the `End`
record, so `sprite_has_end_tag` is 1 for every real-world sprite and the new
branch is unreachable.

## 4. Results

### 4.1 The 16 rows — triage table

`maxd` = highest placement depth; `before`/`after` = our line count; `exp` =
expected. All 16 share both mechanisms; none needed a per-test hack.

| test | maxd | mechanism | before | after | exp | before → after | verdict |
|---|---:|---|---:|---:|---:|---|---|
| `0cde3acaa511` | 987 | M1+M2 | 92 | 48 | 48 | mismatch → **pass** | takeable ✅ |
| `33c31f96f8d0` | 1012 | M1+M2 | 96 | 70 | 70 | mismatch → **pass** | takeable ✅ |
| `356bf4ddf127` | 978 | M1+M2 | 75 | 57 | 57 | mismatch → **pass** | takeable ✅ |
| `42f71d860e22` | 984 | M1+M2 | 173 | 71 | 71 | mismatch → **pass** | takeable ✅ |
| `438789f3e93d` | 880 | M1+M2 | 18 | 16 | 16 | mismatch → **pass** | takeable ✅ |
| `5d828b99311b` | 1024 | M1+M2 | 75 | 50 | 50 | mismatch → **pass** | takeable ✅ |
| `65f0c0a49528` | 1010 | M1+M2 | 108 | 67 | 67 | mismatch → **pass** | takeable ✅ |
| `731834416119` | 1024 | M1+M2 | 32 | 26 | 26 | mismatch → **pass** | takeable ✅ |
| `ac649dcf2857` | 836 | M1+M2 | 28 | 25 | 25 | mismatch → **pass** | takeable ✅ |
| `b29624af5fa3` | 874 | M1+M2 | 36 | 29 | 29 | mismatch → **pass** | takeable ✅ |
| `c24e6e559fd6` | 917 | M1+M2 | 41 | 35 | 35 | mismatch → **pass** | takeable ✅ |
| `cf67270dbe53` | 1004 | M1+M2 | 63 | 37 | 37 | mismatch → **pass** | takeable ✅ |
| `e5b0ab65b5f1` | 1022 | M1+M2 | 32 | 22 | 22 | mismatch → **pass** | takeable ✅ |
| `f40458686ee6` | 932 | **M1 only** | 19 | 19 | 19 | mismatch → **pass** | takeable ✅ |
| `f5398dd73a3a` | 1010 | M1+M2 | 26 | 24 | 24 | mismatch → **pass** | takeable ✅ |
| `e152812e2cfc` | 1015 | M1+M2 **+ M3** | 63 | 42 | 43 | mismatch → mismatch, **gap 20 → 1** | diagnosed, §5 |

**15 flips, all to exact `pass`.** Not one landed on the `ruffle_matched`
fallback — the engine now matches *Flash*, which is strictly better than the
route the brief flagged as the likely one.

### 4.2 Whole-suite before/after (all 30 fuzz tests, re-run locally)

| | pass | ruffle_matched | mismatch | **effective** |
|---|---:|---:|---:|---:|
| before (CI `31130292354`) | 12 | 2 | 16 | **14 / 30** |
| after | **29** | 0 | 1 | **29 / 30** |

The two previously-`ruffle_matched` rows (`4949de464f54`, `887c02ab98db`)
upgraded to full `pass` — no headline change, but they are no longer resting on
a `known_failure` oracle.

### 4.3 Canaries

All run locally in the worktree with `--recompile` (the recompiler changed).
**Zero regressions anywhere.**

| canary set | tests | result |
|---|---:|---|
| **all 30 `from_shumway/fuzz`** (the 12 pass + 2 ruffle_matched that had to stay green) | 30 | **29 pass, 1 mismatch** — all 14 previously-green rows still green; the 2 `ruffle_matched` upgraded to `pass` |
| `avm1` execution-order + depth family | 11 | **11/11 pass** |
| `from_shumway/avm1` family | 12 | **11 pass + 1 ruffle_matched** (`hitarea` — unchanged from baseline) |
| `from_shumway/avm1` leaf tests under the 3 sub-suite dirs | 9 | **9/9 pass** |
| **`regression` suite (full)** | 71 | **71/71 pass**, runner reports `vs prev: no changes` |

The two highest-risk rows for M1 both pass: `avm1/placeobject_occupied_depth`
and `avm1/rewind_depth`. `avm1/execution_order1-4` and `goto_execution_order1-2`
— the tests that *define* the ordering M1 touches — all pass. For M2 the
targeted rows are `from_shumway/avm1/duplicateMovieClip/samedepth` and
`avm1/depth_replacement_audio_unloading`, both pass.

(Three names in my first `from_shumway` batch — `avm1/doactionorder`,
`avm1/duplicateMovieClip`, `avm1/propertycase` — reported `RECOMP_FAIL /
SWF file 'test.swf' not found`. Those are **sub-suite directories, not leaf
tests**; the 9 real leaves underneath them were re-run separately and all pass.
Not a regression.)

**Blast-radius reasoning.** M1 changes behaviour only for a movie whose highest
occupied depth is ≥ 512 while holding < 512 objects — previously depth-descending,
now reverse-instantiation, which is the order the surrounding code already
documented as correct. Real content does reach depth ≥ 512 (`attachMovie` at
10000+ is idiomatic), so this is *not* a fuzz-only change and deserves the full
CI sweep. M2 is unreachable for any SWF whose `DefineSprite` bodies are
terminated properly, i.e. all well-formed content.

## 5. `e152812e2cfc` — diagnosed, not taken

After M1+M2 this row produces 42 lines against 43 expected, and the **only**
difference is a missing line 31:

```
-   31  Warning: Failed to place object at depth 1015.
```

Everything after it matches with a one-line shift. So our *placement behaviour*
is already right; only the diagnostic is absent.

**Mechanism (M3).** The SWF places char 1 at depth 1015 twice — main frame 8 and
main frame 18, both with `move = 0`, i.e. two genuine `PlaceObjectAction::Place`
actions. Ruffle's `instantiate_child`
(`core/src/display_object/movie_clip.rs:1494-1497`):

```rust
if self.has_child_at_depth(depth) {
    context.avm_warning(&format!("Failed to place object at depth {depth}."));
    return None;
}
```

warns whenever the depth is occupied — **regardless of character identity and
regardless of when the first placement happened**.

We already emit this exact string at three sites in `tag.c`, but the check is
narrower in two ways: it fires only when `display_list[depth].char_id != char_id`
(a *different* character), and only within one placement generation
(`display_list[depth].place_gen == g_place_gen`). Here the character is the
*same* and the generations differ (frames 8 vs 18), so neither guard admits it.

### 5.1 Why it is not takeable in this slot

Widening the guard is warning-only in principle, but the generation model exists
precisely to make **frame-func re-runs idempotent** — goto catch-up, root
loop-back, and sprite rewind all re-execute `PlaceObject2` at already-occupied
depths on purpose. A warning that fires one time too many is not a silent
failure: it injects a line into `stdout`, which is the graded artefact, so it
would regress every test that re-places anything. The correct discriminator
(Flash frees the depth on `run_goto` before re-placing, so those re-places are
*not* against an occupied depth) needs modelling before the guard moves.

That is a self-contained follow-up worth **+1**, and it should be taken with its
own sweep over the re-placement family (`avm1/placeobject_occupied_depth`,
`from_shumway/avm1/duplicateMovieClip/samedepth`, the gnash
`place_object_test` row named in the existing `tag.c` comment).

## 6. Files edited (merge ordering)

All four are independent of the other wave-2 patches as far as I can tell; M1
and M2 are separable if the merger wants them split.

| file | change | mechanism |
|---|---|---|
| `SWFModernRuntime/src/libswf/tag.c` | 3× cap gated on occupied count, not `max_depth`; `ng_sprite_park_no_end_tag` helper; wrap site consults `sprite_has_end_tag`; `tagSetSpriteNoEndTag` | M1 + M2 |
| `SWFModernRuntime/include/libswf/swf.h` | `u8 sprite_has_end_tag` in the DefineSprite union arm | M2 |
| `SWFModernRuntime/include/libswf/tag.h` | declare `tagSetSpriteNoEndTag` | M2 |
| `SWFRecomp/src/swf.cpp` | emit `tagSetSpriteNoEndTag` when the sprite body had no `End` record | M2 |

**Recompiler changed → the corpus-wide `Recompiled*` caches are invalidated.**
Generated output for well-formed SWFs is byte-identical (the new call is emitted
only for malformed sprites), but a full CI run still needs `--recompile`
semantics, i.e. a normal clean CI dispatch.

Suggested CI: `mode=graphics`, `categories=all`. The change is shared AVM1
timeline runtime, not `NO_GRAPHICS`-only, so the per-change graphics default
covers it; the weekly no-graphics canary covers the other arm.

## 7. What this says about the board

- **§3.1's headline number was right (+16 available) and its mechanism guess was
  wrong.** The row count came from clustering; the mechanism came from reading
  the SWFs. Worth remembering that "16 rows, one directory, never triaged" was a
  correct *priority* signal even though every word of the accompanying
  hypothesis ("invalid opcodes, out-of-bounds branch targets, stack underflow
  policy") was off.
- **Both bugs were latent in code that already cited the right Ruffle source.**
  M1 sat directly under a comment correctly describing Ruffle's
  `clip_exec_list`; the implementation was right and the *guard* was wrong. A
  cap expressed in terms of the wrong variable is invisible to code review and
  to every test whose depths happen to be small — which is every hand-written
  test in the corpus.
- **The `ruffle_matched` route was never needed.** The brief reasonably expected
  it to be the realistic ceiling for 11 of the 16. Fixing the actual mechanism
  reached exact Flash agreement on 15. When a whole cluster shares one
  mechanism, aim at Flash, not at the fallback oracle.
- **Cheap oracle worth reusing:** for any suite whose action bodies are trivial
  and whose expected output is pure ordering, a throwaway Python tick-simulator
  fitted against `output.ruffle.txt` is far faster than instrumented builds, and
  it doubles as a regression spec. `sim.py` + `extract.py` reproduce Ruffle on
  16/17 in ~60 lines.
