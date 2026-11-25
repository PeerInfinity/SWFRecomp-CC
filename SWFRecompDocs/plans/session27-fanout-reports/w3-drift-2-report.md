# s27 w3-drift-2: upstream drift round 2 `1e604fa87..efb612fd7` (wave 2, implementation)

**New files:** `w3-drift-2-report.md` (this file), `w3-drift-2.patch`. No new fixture dirs (every headline row is an
upstream corpus row with a Flash golden; no new behaviour without a corpus test).

**Patch scope** (`w3-drift-2.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime`):
- `SWFRecomp/src/action/action.cpp`: `SWFAction::parseActions` second pass, `SWF_ACTION_CONSTANT_POOL` arm and
  `SWF_ACTION_PUSH` arm (end of arm + the two pool-index sub-arms `case 8` / `case 9`); new file-static
  `CONSTANT_POOL_ZERO` at the top of `namespace SWFRecomp`.
- `SWFModernRuntime/src/avm2/avm2_display.c`: `mc_goto_frame_now`, `mc_goto_frame` (queued-goto store only),
  `mc_get_is_playing`, `mc_stop`, `mc_goto_with_args` (last lines), `mc_next_scene`, `mc_prev_scene`; new
  `#define MC_GOTO_PLAY_FLAG 2` + forward decl of `mc_set_programmatically_played`. No struct changes (reuses
  `programmatically_played` / `queued_goto_stop`). Touches no `action.c` / `tag.c` / `swf.c` / `ng_shared.c` /
  `swf_core.c` / `tag_stubs.c` code and no `#ifdef NO_GRAPHICS` arm. No sibling in `SIBLING_FILE_MAP.md` lists
  these functions.

Base `origin/master` `eee2e620`. Upstream downloaded at **`efb612fd7`** (2026-11-24; re-fetched at start: no newer
commits than the 5 below). Categories downloaded: `avm1 avm2` (task), plus `from_gnash from_shumway visual text fonts`
for the sweeps.

## Verdicts (lead)

| Row | Verdict | Before → after (graphics; no-graphics identical) |
|---|---|---|
| `avm1/malformed_actions/constant_pool_overlong` | **GO, landed** | output_mismatch → **pass** |
| `avm1/malformed_actions/constant_pool_overspill` (KF) | **GO, landed** | output_mismatch → **pass** (KF row: pass beats Ruffle) |
| `avm1/malformed_actions/push_overspill` | **GO, landed** | output_mismatch → **pass** |
| `avm2/goto_isplaying` (KF) | **GO, landed** | ruffle_matched → **pass** |
| `avm2/goto_framescript_queued_next_prev` (KF) | **GO, landed** | ruffle_matched → **pass** |
| `avm2/goto_scene_isplaying` (KF) | **GO, landed** | ruffle_matched → **pass** |
| `avm2/goto_framescript_queued/swf13` (KF, **old row, rider**) | **GO, landed** | ruffle_matched → **pass** |

Trace axis: **+3 effective** (the 3 malformed rows were real fails), and **+4 strict pass** on rows that were
already counted as effective (ruffle_matched → pass). Pixel axis: **no move** (static proof + measured canary below).

## 1. Drift name-status (`git -C ruffle diff --name-status 1e604fa87 efb612fd7`)

| commit | rows | pre-label |
|---|---|---|
| `9a8618af1` malformed AVM1 bytecode | A `avm1/malformed_actions/{constant_pool_overlong, constant_pool_overspill (KF, player_options.version=10, has output.ruffle.txt), push_overspill (player_options.version=10)}` | 3 new rows, output_mismatch on master → pass with this patch |
| `2c6d3c4fe` avm2/goto_isplaying | A `avm2/goto_isplaying` (KF, output.ruffle.txt) | new row, ruffle_matched on master → pass |
| `31d5a45e5` isPlaying after next/prevScene | A `avm2/goto_scene_isplaying` (KF) | new row, ruffle_matched → pass |
| `d607dca2e` isPlaying after queued next/prevFrame | A `avm2/goto_framescript_queued_next_prev` (KF) | new row, ruffle_matched → pass |
| `efb612fd7` bump `ahash` | `Cargo.lock`, `web/Cargo.toml` only | no rider |

Denominator: **+6 rows** (3 avm1, 3 avm2) vs any results commit that predates these downloads. No existing test's
expected output changed. Premise note: the brief says "the other malformed_actions rows pass": there are no other
rows; `malformed_actions/` holds exactly these 3.

## 2. Malformed AVM1 bytecode (recompiler)

**What Flash does** (test comments in `test.swfasm`, commit message of `9a8618af1`; Ruffle's
`swf/src/avm1/read.rs::read_action` also always resumes at `start + length`):
- Execution always resumes at the **declared action end**. Trailing bytes after the last pool string are ignored
  (`constant_pool_overlong`), and bytes a Push value spilled into are still executed (`push_overspill`).
- Push: a value that spills past the end is still read from the following bytes: the 4th i32 reads `04 00 26 26`
  = **640024580**. Then all four `Trace`s run (FP 9/10; FP11+ crashes, hence `player_options.version = 10`).
- ConstantPool: an entry whose NUL is not inside the action, **and every later entry**, is the **number 0**
  (`typeof` → `number`). Index ≥ declared count stays `undefined`. Ruffle reads past the end
  (`unterminated�`, `FSCommand:quit`), hence KF.

**Our bug** (`action.cpp::parseActions`, second pass): the ConstantPool arm advanced `action_buffer` by the strings it
read, not by `length`. Overlong → we parsed `de ad be ef` as opcodes; overspill → strings swallowed the following
actions. The Push arm advanced by `push_length`, which skips 2 bytes of `Trace` on a spill.

**Fix:**
- ConstantPool: bound each string with `memchr` against `body + length`. On the first out-of-bounds entry, fill it
  and every remaining entry with the `CONSTANT_POOL_ZERO` marker. Then `action_buffer = body + length`. The dead-code
  arm gets the same bounds.
- The 8-bit and 16-bit pool-index Push arms emit `PUSH(ACTION_STACK_VALUE_F64, 0)` for a marker slot.
- Push: `action_buffer += length` (was `+= push_length`). The spilled value is still read from the following bytes,
  exactly as Flash 9/10 reads it.

**Reach: static proof of no other change.** I built origin/master's SWFRecomp in a worktree. I ran old and new on
**every SWF of avm1, avm2, from_gnash, from_shumway, regression, visual, text and fonts: 3661 SWFs**. I then diffed
`RecompiledScripts` + `RecompiledTags` byte-for-byte:
- return codes are identical everywhere;
- the output differs for **exactly the 3 `malformed_actions` SWFs**.

So no other row in any of those suites can move from the recompiler change, in either mode. That covers every
render-canary member.

**ASan (malformed bytecode must never crash).** `--asan`, no-graphics, `ASAN_OPTIONS=detect_leaks=0`: all 3 rows
**PASS, no ASan error**. With leak detection on, LeakSanitizer reports 20–98 bytes of at-exit leaks and nothing else.
That is the harness's generic exit-leak profile, not a memory error. The SWFRecomp read in `push_overspill` stays
inside the tag buffer: the spill is 2 bytes, into the following actions.

## 3. AVM2 `isPlaying` (runtime)

`output.txt` is Flash's (all 3 new rows are `known_failure`; `output.ruffle.txt` = Ruffle's wrong output). We matched
Ruffle exactly. The verify subset rule shows our only diffs were `isPlaying:` values; frames already matched Flash.

**Flash rule** (the `goto_isplaying` header states it, and the 3 goldens confirm it):
- `isPlaying` is a **flag of its own**, not whether the clip is playing.
- `play()`, `gotoAndPlay()`, `nextScene()` and `prevScene()` set it. It is never set on a 1-frame clip.
- **Only `stop()` clears it.** `nextFrame`, `prevFrame` and `gotoAndStop` stop the clip but leave the flag.
- A goto **queued from a frame script** sets the flag only when the queue is flushed (`goto_scene_isplaying`:
  "frame1: after nextScene(): … false", then true in the next frame script). That also holds for a queued
  `gotoAndPlay`, which sets the flag even over an intervening `stop()`.

That last point was learned from the rider row: an early prototype that set the flag at call time regressed
`avm2/goto_framescript_queued/swf13` from ruffle_matched to mismatch. Its Flash golden reads "gotoAndPlay(2) →
false, stop() → false, frame 2 → **true**". Moving the flag set into the flush flipped it to **pass**.

**Implementation:**
- `mc_get_is_playing` returns `programmatically_played` alone. It used to require `&& playing`.
- `mc_stop` clears the flag.
- `gotoAndPlay`, `nextScene` and `prevScene` pass `MC_GOTO_PLAY_FLAG` (= 2) as `stop`. `mc_goto_frame` stores it in
  `queued_goto_stop` when queued, and `mc_goto_frame_now` sets the flag (via `mc_set_programmatically_played`, so the
  >1-frame rule still holds) before running the goto. The frame script that runs inside an immediate goto therefore
  sees `true`, as Flash does.
- `ext->playing` is unchanged for every caller: `(stop == 1) ? 0 : 1` is the same as the old `stop ? 0 : 1` for
  stop ∈ {0,1}, and 2 plays.

## Per-test before/after (clean origin/master vs patch, same box)

| test | mode | before | after |
|---|---|---|---|
| avm1/malformed_actions/constant_pool_overlong | graphics | output_mismatch (stops after line 1) | PASS |
| avm1/malformed_actions/constant_pool_overspill | graphics | output_mismatch (stops after line 1) | PASS |
| avm1/malformed_actions/push_overspill | graphics | output_mismatch (2/4 traces) | PASS |
| the 3 above | no-graphics (`--asan`) | — | PASS |
| avm2/goto_isplaying | graphics / no-graphics | ruffle_matched | PASS / PASS |
| avm2/goto_framescript_queued_next_prev | graphics / no-graphics | ruffle_matched | PASS / PASS |
| avm2/goto_scene_isplaying | graphics / no-graphics | ruffle_matched | PASS / PASS |
| avm2/goto_framescript_queued/swf13 | graphics / no-graphics | ruffle_matched | PASS / PASS |

**AVM2 sweep** (graphics, both legs): 40 avm2 rows whose source uses `isPlaying`, `nextScene`, `prevScene`,
`gotoAndStop`, `gotoAndPlay`, `nextFrame` or `prevFrame`, plus every row whose files mention `isPlaying`. Only the 4
rows above moved. `bounds_mode` and `swf_9_goto_in_construct_frame` stay ruffle_matched, as before. `versioned_isplaying`,
`movieclip_properties`, `movieclip_constr`, `movieclip_displayevents_stopped`, `goto_framescript_queued_same_frame`,
`goto_framescript_queued/swf9`, `swf10`, `orphan_*` and `all_classes/display/swf13`/`swf30` stay **PASS**. 4 `scripts/`
/ `com/ruffle` source subdirs are not test rows. No-graphics re-run of the 4 headline rows plus 4 neighbours: all PASS.

**Regression suite** (graphics, both legs, all PASS = PASS): `avm2_goto_catchup_scale`, `avm2_timeline_text`,
`avm1_attached_clip_goto_play`, `avm1_root_identity_and_playhead`, `avm1_goto_backward_enterframe_once`; plus
`from_shumway/timeline/scene/Scene_7_NextPrevScene` (the only other corpus row calling next/prevScene), PASS = PASS.

**Render canary.**
- **Static:** every one of the 189 members is covered by the identical-C proof above. I decompressed every member's
  SWF: none contains the string `isPlaying`. The only remaining runtime effect is the `queued_goto_stop` value 2, which
  plays exactly like 0. So no member can move.
- **Measured:** `render_canary.py capture/compare` over the 36 `avm2/` members, both legs. Result: **37/37 comparisons IDENTICAL**, 0 DIFFERS, no trace or image status change.

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

Trace axis (both modes):
- `avm1/malformed_actions/constant_pool_overlong`: output_mismatch → **pass**
- `avm1/malformed_actions/constant_pool_overspill`: output_mismatch → **pass**
- `avm1/malformed_actions/push_overspill`: output_mismatch → **pass**
- `avm2/goto_isplaying`: ruffle_matched → **pass**
- `avm2/goto_framescript_queued_next_prev`: ruffle_matched → **pass**
- `avm2/goto_scene_isplaying`: ruffle_matched → **pass**
- `avm2/goto_framescript_queued/swf13`: ruffle_matched → **pass**

Pixel axis: **none**. Any pixel move is a regression to report. Any other trace move is either drift, if the row is
absent from the baseline results, or a regression.

If CI's download predates `9a8618af1..d607dca2e`, the 6 new rows are absent: that is drift, not yield.

## Could not finish / holds

Nothing held. The 4 KF rows now pass. CI's `ignored_tests.txt` handling is unchanged, and none of the 7 rows is
listed there (checked).

## New unclaimed leads

- The recompiler's other length-carrying arms (`GetURL`, `GotoLabel`, `SetTarget`, `DefineFunction` header,
  `StoreRegister`, …) still advance by their parsed contents, not `length`. No corpus row exercises a mismatch there.
  Ruffle's `read_action` and Flash both resume at `start + length`. One generic `action_buffer = body + length` after
  the switch, for non-sub-block opcodes, would close the class. Price: S, gated on the same 3661-SWF identical-C sweep
  used here (`recdiff.sh`: build origin/master SWFRecomp in a worktree, run both on each SWF, `diff -rq`). That sweep
  takes ~2 min on 4 CPUs and is a cheap reusable no-op proof for any recompiler change.

## LOCAL ORACLE REQUESTS

none (all 7 rows carry Flash goldens in the corpus).
