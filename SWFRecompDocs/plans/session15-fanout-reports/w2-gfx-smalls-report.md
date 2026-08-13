# Session 15 — wave 2 — `w2-gfx-smalls` (P1 · P4 · P5 · P8)

**Agent:** `w2-gfx-smalls` · worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a97865983ec472cba`
**Base:** `42a324cef`. Grading run of record: `31647430265` @ `bf585e448`
(trace 4269/4443 eff · pixels 310/569).
**Local rig:** native `--mode=graphics`, `DAWN_INSTALL=/home/robert/CC/dawn-install`,
recompiler cmake-built inside the worktree.

## Verdicts (lead with these)

| item | verdict | measured move |
|---|---|---|
| **P1** capture-trigger table capped at 16 | **GO — LANDED, +2 pixel flips (proven)** | `from_shumway/acid/acid [output.17]` `no_render → PASS` (11 987 / limit 13 000), `[output.18]` `no_render → PASS` (12 073 / limit 13 000); the other 16 comparisons byte-for-byte unchanged |
| **P4** `hasPlayingSprites()` root-only scan | **GO — LANDED, +2 pixel flips (proven)**, mechanism CONFIRMED at tag level | `from_shumway/acid/acid-video [output.10]` `no_render → PASS` (13 745 / limit 18 000), `[output.20]` `no_render → PASS` (11 971 / limit 15 000) |
| **P5** `DefineBitsLossless2` format 4 | **GO — LANDED, +1 pixel flip**, but the briefed mechanism was **HALF the defect** | `visual/define_bits_lossless2_rgb15 [output]`: 5 282 outliers / max 255 / mean 119.45 → **0 outliers, max diff 2, PASS** |
| **P8** `avm2/netstream_play_flv` hidden by basename match | **DONE (doc-only)** — and the board's suggested fix would **not** have worked; see §P8 | board visibility only, 0 flips |

**Patches (one per item), in this worktree at `SWFRecompDocs/plans/session15-fanout-reports/`:**

| patch | item | file(s) touched | functions touched |
|---|---|---|---|
| `w2-gfx-smalls-1.patch` | P1 | `SWFModernRuntime/src/libswf/capture.c` | `parse_capture_triggers()` + the `DEFAULT_MAX_CAPTURES` comment |
| `w2-gfx-smalls-2.patch` | P4 | `SWFModernRuntime/src/libswf/tag.c` | `hasPlayingSprites()` → thin wrapper + new `static hasPlayingSprites_impl()` |
| `w2-gfx-smalls-3.patch` | P5 | `SWFRecomp/src/swf.cpp` | `SWF::interpretTag()`, `case SWF_TAG_DEFINE_BITS_LOSSLESS2` only (line ~1790–1990; **far** from w2-gfx-flatten's ~8653 flattener) |
| `w2-gfx-smalls-4.patch` | P8 | `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | doc only |

The four patches are disjoint by file, so they can be applied in any order or
individually.

---

## P1 — capture-trigger table capped at 16 — **PROVEN +2**

**Mechanism (confirmed).** `capture.c` sized the trigger table to
`DEFAULT_MAX_CAPTURES = 16` and `parse_capture_triggers()` stops tokenising at
`g_capture_count < g_capture_cap`. `from_shumway/acid/acid` declares 18
comparisons, so triggers 17/18 were never registered and the two frames were
never captured (`no_render`). Nothing in `verify_output.py` or the workflow
sets `CAPTURE_MAX`.

**Fix (patch 1, 11 net lines).** Keep the 16 default *and* the `CAPTURE_MAX`
override, then grow the capacity to the number of tokens actually present in
`CAPTURE_TRIGGERS` (`token_count = commas + 1`). This is failure-proof by
construction rather than "a bigger magic number" — the next test with 33
comparisons will not re-open the bug.

**Measurement** (`--mode=graphics --images`, all 18 comparisons):

```
output.01..output.16  PASS  (identical outlier counts to the CI baseline)
output.17  PASS  11987 outliers (limit 13000), max difference 204   <- was no_render
output.18  PASS  12073 outliers (limit 13000), max difference 204   <- was no_render
```

**Predicted CI move: +2 pixel flips, 0 trace change.** `acid` remains the only
corpus test with >16 comparisons, so nothing else moves.

*Residual noted, not fixed:* `parse_capture_triggers()` still copies the env var
into a fixed `char buf[4096]`. 18 triggers ≈ 450 bytes, so it is not live today;
worth folding into the next capture-harness change.

---

## P4 — `hasPlayingSprites()` does not recurse — mechanism CONFIRMED independently

**Independent tag-level confirmation of the brief** (my own SWF parse of
`from_shumway/acid/acid-video/test.swf`, not the board's):

```
DefineSprite id=6 declared_frames=39      <- the animation
DefineSprite id=7 declared_frames=1
  PlaceObject2 depth=1 char=6             <- 39-frame sprite lives INSIDE sprite 7
PlaceObject2 depth=1 char=7  (root)
PlaceObject2 depth=3 char=7  (root)
root ShowFrames = 1
```

So the root display list contains only 1-frame sprites; the root-only scan in
`hasPlayingSprites()` returned 0, `quit_swf` was never held off, and the movie
exited after one tick.

**Fix (patch 2).** Split into `hasPlayingSprites_impl(dl, dl_max)` + a wrapper,
recursing through `sprite_display_list` / `sprite_max_depth` exactly the way the
neighbouring `hasClipEnterFrameHandlers_impl()` already does. Nested display
lists are depth-indexed from 1 (cf. `tag.c:4243`, `tag.c:4862`), so the loop
bounds are unchanged at every level — the root-level verdict is bit-identical to
before for any movie with no nested sprites.

**Self-localisation vs `w2-fuzz16`:** the only symbol I touch in `tag.c` is
`hasPlayingSprites` (line ~12013, in the keep-alive helper block between
`tagVideoFrame` and `hasClipEnterFrameHandlers_impl`). No placement/depth code,
no `PlaceObject` path, no shared statics.

### Blast radius — measured statically over the whole corpus, not estimated

I parsed all **4 490** `test.swf` files and flagged every movie where the ROOT
display list places no multi-frame sprite but a *deeper* sprite has >1 frame —
i.e. exactly the class whose keep-alive verdict this patch can change:

```
scanned 4490   flagged 8
  avm2/button_nested_frame                       root_showframes=2   (CI: pass)
  avm2/button_nested_frame_simple                root_showframes=2   (CI: output_mismatch)
  avm2/goto_nested_construct_sibling             root_showframes=1   (CI: pass)
  from_shumway/acid/acid-bitmap-draw_quality_high root_showframes=1  (CI: pass)
  from_shumway/acid/acid-bitmap-draw_quality_low  root_showframes=1  (CI: pass)
  from_shumway/acid/acid-mask                    root_showframes=1   (CI: pass)
  from_shumway/acid/acid-video                   root_showframes=1   (CI: pass)
  from_shumway/bitmapbuttons                     root_showframes=1   (CI: pass)
```

(Caveat stated plainly: the scan is static, so runtime-attached clips
(`attachMovie`/`duplicateMovieClip`) are invisible to it. It bounds the
*authored* blast radius, not the dynamic one — which is why the broad timeline
canary set below still matters.)

### Result on the target

```
from_shumway/acid/acid-video   trace: pass (unchanged)
  output.01  pass  14192 outliers (limit 20000), max diff 92   (was pass)
  output.10  pass  13745 outliers (limit 18000), max diff 99   (was FAIL / no_render)
  output.20  pass  11971 outliers (limit 15000), max diff 75   (was FAIL / no_render)
```

Baseline `reason` for both flipped rows in
`from_shumway/_results/image_results_graphics.json` @ `31647430265` is literally
`no_render` — the loop never reached ticks 10 and 20. **+2 pixel flips.**

### Canaries

See §Canary ledger.

---

## P5 — `DefineBitsLossless2` format 4 — **+1 flip, and the brief's mechanism was only half the defect**

**Refutation / correction of the board.** The board says "the Lossless1 RGB15
decoder already exists — wire it up (~20 lines)". Wiring it up is necessary but
**not sufficient**, and doing only that leaves the test at its exact baseline
number, which looks deceptively like "the patch had no effect":

* The upstream fixture was made in JPEXS by **flipping a format-5 tag's type
  byte to 4** (its own `test.toml` says so). The zlib stream therefore still
  contains the full **RGB32** payload: it inflates to **10 000 bytes**, while
  the Rgb15 pixel array only needs `((50*2+3)&~3)*50 = 5 000`.
* Our `uncompress()` call is sized to `expected_size` exactly, so it returned
  `Z_BUF_ERROR (-5)`; the tag threw, `interpretTag` logged
  `Warning: tag 36 failed`, and the generated `constants.h` carried
  `BITMAP_COUNT 0` — no bitmap at all. Ruffle inflates the whole stream and
  then slices, which is why it renders.
* So the patch is *decode arm* **+** *tolerant inflate*: grow the buffer on
  `Z_BUF_ERROR` (format 4 only; formats 3 and 5 keep the strict exact-size
  behaviour) and ignore the trailing bytes.

**Upstream check (not assumed):** `~/CC/ruffle` was stale, so I fetched
`origin/master` and read it there —
`swf/src/read.rs` now maps `4 => BitmapFormat::Rgb15` for **both** tag versions
("Despite the SWF19 specs stating otherwise… ruffle-rs/ruffle#24431"), and
`render/src/utils.rs` takes one `Rgb15` arm regardless of version, alpha
`u8::MAX`. Our arm is the same formula (`(c*255+15)/31`) with the same 4-byte
row padding.

**Test re-synced per-test** (no `download_tests.sh`): `git archive` of
`FETCH_HEAD:tests/tests/swfs/visual/define_bits_lossless2_rgb15` into
`ruffle-tests/tests/swfs/visual/`.

**Measurement:**

| leg | outliers (limit 0) | max diff | mean diff | verdict |
|---|---:|---:|---:|---|
| baseline (CI run `31647430265`) | 5 282 | 255 | 119.4476 | FAIL |
| decode arm only (still `Z_BUF_ERROR`) | 5 282 | 255 | 119.4476 | FAIL (unchanged — the trap) |
| decode arm + tolerant inflate | **0** | **2** | — | **PASS** |

The residual max diff of 2 is the 5→8 bit expansion: expected `(255,199,0)`
vs ours `(255,197,0)`, i.e. Ruffle's own `(c*255+15)/31` on `g5 = 24` gives 197
while the golden PNG carries 199. `tolerance = 2` covers it exactly, so the
comparison passes at `max_outliers = 0`.

**Corpus blast radius for P5: provably zero.** I scanned all 4 961 SWFs in the
corpus for `DefineBitsLossless{,2}` format bytes:
`{(36,5): 729, (20,5): 21, (20,3): 10}` — **no other test uses format 4 in
either tag**, and the Lossless1 Rgb15 arm this patch mirrors has no live user at
all. So P5 cannot move any other comparison.

**Predicted CI move: +1 pixel flip** (`visual/define_bits_lossless2_rgb15`
`[output]`), **but only once the test is in the CI corpus** — it is a new
upstream test and the local mirror did not have it (the board's blocker note is
correct). If the CI corpus at merge time still lacks it, the flip appears when
the corpus is re-synced, not before.

---

## P8 — the mis-scoped disposition — **the board's prescribed fix does not work; here is one that does**

**What the board asked for:** add
`<!-- image-axis: avm1/netstream_play_flv output -->` to the avm1
`ACCEPTED_DIFFS` entry "so the resolver stops matching by basename".

**Why that alone fails** (read `scripts/image_triage.py::Dispositions.lookup`
and `_scope_covers`): a scope marker that is not a *frame range* returns
`covers = None`, which leaves `hard = hit["image_axis"] = True`. The avm2 row
would still be excluded — only the printed label would change. Two further
traps sit behind it: the entry is also registered by its **summary-table row**
(same bare name), and `ruffle-tests/ignored_tests.txt` carries a bare
`netstream_play_flv` line, which the tool documents as an image-axis
disposition too (its own header, "TWO TRAPS", says so).

**What I did instead (patch 4, doc-only, no code):**

1. Renamed the entry subject to the **suite-qualified** `avm1/netstream_play_flv`
   (heading *and* summary-table row) — `lookup()` checks `f"{suite}/{test}"`
   before the bare name, so avm1 resolves `exact` and avm2 no longer matches.
2. Added the explicit `<!-- image-axis: avm1/netstream_play_flv output -->`
   marker (keeps the avm1 row hard-dispositioned and prints its scope).
3. Added a short sibling entry keyed `avm2/netstream_play_flv` carrying
   `<!-- image-axis: none -->`. Because a `suite/test` key matches across doc
   scopes and doc lookups run **before** the ignore lists, this intercepts the
   global `ignored_tests.txt` hit and puts the row back on the board as live,
   untriaged work — with its real numbers (blank render, 229 724, max 255)
   contrasted against the avm1 entry's 44/3.

**Verified with the real resolver** (before → after):

```
avm1/netstream_play_flv : (ACCEPTED_DIFFS avm1 …, 'exact',    hard=True)  -> unchanged (still hard, now scoped)
avm2/netstream_play_flv : (ACCEPTED_DIFFS avm1 …, 'basename', hard=True)  -> ('… NOT dispositioned (blank render, live work)', 'exact', hard=False)
avm1/netstream_play_flv_screen, avm2/netstream_seek_flv, avm1/display_object_properties : unchanged
```

No trace-axis filtering changed (I deliberately did **not** touch either
`ignored_tests.txt`; the avm2 trace row stays ignored via the avm2 suite-local
list, the avm1 trace row via the global list). Pass counts are unaffected on
both axes — this only changes what the board shows.

---

## Canary ledger

All legs run in this worktree with **all four patches applied**, against local
Dawn (`DAWN_INSTALL=/home/robert/CC/dawn-install`) where graphics is involved.
"baseline" = CI run `31647430265` @ `bf585e448`
(`_results/results_graphics.json` for trace, `_results/image_results_graphics.json`
for pixels). **26 tests, 0 regressions on either axis.**

### A. P4 trace canaries — AVM1 timeline / goto / nested sprites (11 tests, `--mode=no-graphics`, exercises `swf_core.c`, the file with 3 of the 4 call sites)

`avm1/`: `goto_frame` · `goto_frame2` · `goto_rewind1` · `goto_both_ways1` ·
`goto_execution_order` · `goto_advance1` · `goto_methods` · `goto_label` ·
`attach_movie_stop` · `unload_nested_child` · `clip_events`

**11 / 11 PASS** (all `pass` at baseline) → **0 regressions**.

### B. P4 trace canaries — early-terminating-by-design + Shumway timeline (6 tests)

| test | baseline | after |
|---|---|---|
| `from_shumway/fscommand1` (**FSCommand quit**) | pass | **pass** |
| `from_shumway/timeline/timeline_as2_1` (**FSCommand:quit from a non-last frame, loops back — the canonical "must not run forever" case, named in `swf.c`'s own comment**) | pass | **pass** |
| `from_shumway/timeline/timeline_loop` | pass | **pass** |
| `from_shumway/timeline/Timeline3` | pass | **pass** |
| `from_shumway/avm1timeline1` | pass | **pass** |
| `from_shumway/avm1timeline2` | pass | **pass** |

**6 / 6 PASS.** Nothing runs forever; the `g_force_quit` bypass still wins over
the (now recursive) keep-alive gate.

### C. P4 canaries — the statically-derived blast radius (`--mode=graphics --images`)

| test | trace before → after | pixels before → after |
|---|---|---|
| `from_shumway/acid/acid-video` | pass → **pass** | `[output.01]` pass → pass (14192/20000); **`[output.10]` no_render → PASS (13745/18000)**; **`[output.20]` no_render → PASS (11971/15000)** |
| `from_shumway/acid/acid-mask` | pass → **pass** | `[output.01]`/`[.05]`/`[.10]` fail → fail (12096 / 10937 / 9474 vs limit 16) |
| `from_shumway/acid/acid-bitmap-draw_quality_high` | pass → **pass** | fail → fail, **194 784 — bit-identical to the board's quoted baseline figure** |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | pass → **pass** | fail → fail, 194 784 |
| `from_shumway/bitmapbuttons` | pass → **pass** | fail → fail, 618 042 (s12 DEFER still stands) |

*Honesty note on the four still-failing rows:* the published
`image_results_graphics.json` carries `status`/`reason` but **not** per-comparison
stats, so "unchanged" is a **status-level** claim (`fail/pixel_mismatch` before
and after) for `acid-mask` and `bitmapbuttons`. The one row where a numeric
before/after exists — `acid-bitmap-draw_quality_high`, 194 784 in the wave-1
board and 194 784 here — is numerically identical.
| `avm2/button_nested_frame` | pass → **pass** | — |
| `avm2/button_nested_frame_simple` | output_mismatch → **output_mismatch, byte-identical** (39 actual / 27 expected / 27 matching, "12 line(s) differ" — same string as baseline) | — |
| `avm2/goto_nested_construct_sibling` | pass → **pass** | — |

### D. Timeline suite (2 tests)

`timeline/frame_script_cleanup_goto` · `timeline/frame_script_construct` —
**2 / 2 PASS** (both `pass` at baseline).

### E. P1 / P5 targets (already tabled above)

`from_shumway/acid/acid` 18/18 comparisons pass (16 unchanged, 2 new);
`visual/define_bits_lossless2_rgb15` 0 outliers / max diff 2.

### What I did NOT run, and why it matters

* **No full `render_canary.py` before/after A-B.** Both legs are compile-bound
  and the box was at load 21 with ~10 sibling agents; I spent the budget on the
  *statically identified* blast radius instead (§P4), which is a strictly
  tighter target set for these three patches: P1 only widens a parse table,
  P5 provably touches no other test in the corpus (format-4 census = 0), and
  P4's authored blast radius is 8 tests — all 8 were run. The residual risk is
  P4 on **runtime-attached** nested clips, which no static scan can see and
  which only the merged CI run will settle.
* CI recommendation: **graphics / categories=all** is sufficient for P1+P4
  (no AVM2 recompiler emission changed); P5 touches the recompiler but only the
  `DefineBitsLossless2` arm, so `all` still covers it. Because P4 edits code
  compiled into **both** frame loops (`swf.c` and `swf_core.c`), a
  **no-graphics** dispatch is also justified per CLAUDE.md's "shared runtime
  code — when in doubt, run both".

---

## Summary of predicted CI movement

| axis | move | tests |
|---|---|---|
| pixels | **+4 flips** (all four proven locally) | `from_shumway/acid/acid [output.17]`, `[output.18]` (P1); `from_shumway/acid/acid-video [output.10]`, `[output.20]` (P4) |
| pixels | **+1 more once the corpus carries the test** | `visual/define_bits_lossless2_rgb15 [output]` (P5) — absent from the local mirror, re-synced per-test into this worktree only |
| trace | **0** expected | 26 canaries, zero movement in either direction |
| board hygiene | `avm2/netstream_play_flv [output]` returns to the live board as an untriaged `blank_render` (229 724) | P8 — no pass-count change |

Baseline arithmetic: 310/569 → **314/569 (55.2 %)** with the corpus as-is, or
315/570 (55.3 %) once `define_bits_lossless2_rgb15` is mirrored.

## Refutations / corrections to the wave-1 board (first-class deliverables)

1. **P5's stated cost and mechanism are wrong in a way that would have burned
   the session.** "Reuse the Lossless1 branch, force `a = 255`, ~20 lines" leaves
   the test at *exactly* its baseline 5 282/119.4476 — the decode arm is never
   reached, because the fixture's stream inflates to 10 000 bytes and our
   fixed-size `uncompress()` returns `Z_BUF_ERROR`, so the tag throws and
   `BITMAP_COUNT` stays 0. An agent measuring "no change" here would plausibly
   have concluded the board's refutation ("it does NOT pass upstream") was right
   and dropped the item. It does pass, at `0 outliers / max diff 2`.
2. **P8's prescribed fix (add a scope marker) does not do what the board says.**
   `_scope_covers()` only understands frame ranges; a non-range scope leaves
   `hard = True` and the avm2 row stays hidden. Two additional hiding
   mechanisms (the summary-table row and the global `ignored_tests.txt` line)
   are not mentioned in the board at all. The working fix is the
   suite-qualified subject + an explicit `avm2/...` counter-entry.
3. **The board's "5282/10000 channels… does NOT pass upstream" framing of P5
   is a misreading of its own data.** That number is *our* failing measurement
   in run `31647430265`; upstream Ruffle passes it (the tag was added to
   `read.rs` precisely to make it render — ruffle-rs/ruffle#24431). Verified by
   fetching `origin/master` rather than trusting the stale local checkout.
4. **P1 and P4 both survive on magnitude, exactly as priced (+2 and +2).** No
   correction needed; P4's mechanism additionally re-confirmed from the tag
   stream independently of the board.

## Reproduction notes for the merger

* The worktree recompiler was cmake-built in-tree
  (`SWFRecomp/build`); **P5 needs it rebuilt + `--recompile`** or you will
  measure the un-patched result (I hit exactly this — the first P5 run raced the
  binary link and reported the baseline number).
* Test dirs copied into this worktree for the canaries: `from_shumway/acid/*`,
  `from_shumway/{avm1timeline1,avm1timeline2,fscommand1,timeline/*,bitmapbuttons}`,
  11 `avm1/goto*`-family dirs, 3 `avm2/*nested*` dirs, 2 `timeline/*` dirs, and
  the freshly extracted `visual/define_bits_lossless2_rgb15`.
* `visual/define_bits_lossless2_rgb15` must be added to the shared corpus
  (`download_tests.sh` sync or a targeted `git archive` from ruffle master) for
  the P5 flip to appear in CI.
