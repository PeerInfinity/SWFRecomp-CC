# w2-action-order — session 15 dual-axis fan-out #7 (wave 2)

**Verdict: NO-GO. No patch delivered. Zero source edits.**

Target arc: `action_order` (deferred from s14 with a full plan).
Diagnosis of record: `SWFRecompDocs/plans/session14-fanout-reports/wave1-avm1-tick.md`.
Baseline: HEAD `42a324cef`, worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ab3d33125b5424be7`.

Headline: the s14 plan's DEFER recommendation **survives re-audit**, and the
board's stated **"+2 ceiling" does not** — the pairing partner
(`action_execution_order_extend_test`) requires undoing a landed fix that is
currently holding `action_execution_order_test12` at `ruffle_matched`. Realistic
ceiling for the arc as scoped is **+1, with a named −1 risk attached to the
second half**.

---

## 1. Baseline re-verification (premises hold, byte-for-byte)

```
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all/action_order \
  --test=action_execution_order_test11 --diff --verbose --recompile
```

| Test | s14 report | HEAD `42a324cef` (this run) | CI baseline `results_graphics.json` |
|---|---|---|---|
| `misc-ming.all/action_order/action_execution_order_test11` | 26/32 `output_mismatch` | **26/32 `output_mismatch`, identical 6-line diff** | `output_mismatch` |
| `misc-ming.all/action_order/action_execution_order_extend_test` | 7/32 | not re-run (blocked, see §3) | `output_mismatch` |

Residual diff at HEAD — identical to the s14 transcript, same six lines:

```
     7  mc2 onEnterFrame called
-    8  mc21 onLoad called
+    8  mc1 onEnterFrame called
-    9  mc1 onEnterFrame called
+    9  mc21 onLoad called
    10  mc21 onEnterFrame called
...
-   28  PASSED: _root.doActionOrder  ==  '0+1+2+3+4+5+'
+   28  FAILED: expected: '0+1+2+3+4+5+' obtained: 0+2+1+3+4+5+
-   29  PASSED: _root.asOrder  ==  '0+1+2+3+4+5+6+3+8+4+10+6+3+4+14+15+25+10+26+6+27+3+28+4+29+20+21+22+23+24+'
+   29  FAILED: ... obtained: 0+1+2+3+4+5+6+3+4+8+10+6+3+4+14+26+25+27+15+10+6+3+4+28+29+20+21+22+23+24+
-   30  #passed: 5    +   30  #passed: 3
-   31  #failed: 0    +   31  #failed: 2
```

**s14's timeline-order work did not partially satisfy this plan.** The s14
`w2-fuzz-triage` commit (`4e03e6382`) re-gated `ASF_SORT_CAP` / `ANSF_SORT_CAP` /
`DEC_SORT_CAP` from `max_depth` (highest depth *index*) to the occupied-depth
*count*. test11 places at root depths 1–3 and nested depths 1–2, so the cap
branch was never taken for it in either direction — the fix is orthogonal by
construction, and the byte-identical diff confirms it empirically.

Structural facts re-confirmed at HEAD:
- `action_execution_order_test11/test.toml` is **`num_frames = 30` and nothing
  else** — no `known_failure`, no `output.ruffle.txt`. **All-or-nothing:
  31/32 scores exactly as much as 26/32.** Partial credit is unavailable.
- Not in `ruffle-tests/ignored_tests.txt`; not in any of the four AVM1
  disposition docs.

---

## 2. Mechanism audit — what the plan got right

**D2 (flat-global vs per-subtree LIFO) is confirmed to the digit, analytically.**
`advance_nested_sprite_frames` (`tag.c:1762-1868`) sorts *root-level* depths by
`place_seq` DESC, then for each root sprite swaps into its subtree and calls
`advance_sprite_frames`, which sorts *again* within that subtree
(`tag.c:1148-1189`). For test11's tree (mc1 @ root d2 with children mc11/mc12,
mc2 @ root d3 with child mc21; mc2 placed after mc1) that yields
`{mc2 subtree} then {mc1 subtree}` = `mc21, mc12, mc11` = ids `2+ 1+ 3+`.
Our observed `doActionOrder` is **`0+2+1+3+4+5+`** — exactly the prediction.
Ruffle's single flat `clip_exec_list` (`avm1/runtime.rs:517-568`, head insertion)
yields `mc12, mc21, mc11` = `1+ 2+ 3+` = the expected `0+1+2+3+4+5+`.
No experiment needed; the prediction and the observation match digit for digit.

**D1 (per-clip EF+advance adjacency) is confirmed by the `8+`/`4+` swap.**
Trace lines 8/9 and the `asOrder` fragment agree: expected has `…6+3+8+4+10+…`
(mc21's LOAD before mc1's enterFrame), we emit `…6+3+4+8+10+…`. That is the
`PendingClipLoad` deferral (`tag.c:389`, queued `:8353-8375`, dispatched
`:8307`) plus the global phase split, precisely as described.

**All eight §5 blast-radius mechanisms still exist at HEAD**, verified by grep:
`g_advance_defer_nested` (`swf.c:916-919`, `swf_core.c:1052-1055`, `:1182-1185`),
`presync_nested_sprite_currentframe` (`swf.c:937`, `swf_core.c:1073`, `:1197`),
`ng_advance_attached_clip_playheads` (`swf.c:927`, `swf_core.c:1063`, `:1191`),
`advance_nested_sprite_frames` (`swf.c:1083`, `swf_core.c:1137`, `:1212`),
`PendingClipLoad`, the `placed_at_tick == g_tick_count` skip (`tag.c:1824`),
`ClipEFRebaseFrame` (`tag.c:4595`), and goto-catchup suppression.
`tagFlushPendingEnterFrame` is still **recompiler-emitted** at three sites —
`SWFRecomp/src/swf.cpp:763`, `:1078`, `:1141` — so Track B still invalidates
every `Recompiled*` cache corpus-wide and needs both CI modes.

---

## 3. New findings (three, all pushing toward NO-GO)

### F1 — the "+2 ceiling" pairing is self-defeating: `extend_test`'s fix is the inverse of a landed fix currently holding `test12`

`polish-sweep-arc.md` §15.3 and the s14 report both price the arc as
"pair with `extend_test` for a +2 ceiling". `extend_test`'s Bug 1 is
*onLoad/onUnload **method**-handler dispatch for plain timeline-placed sprites*.
That dispatch is gated at **`tag.c:772-788`**, and the in-code comment names its
counter-test explicitly:

```c
// Gated on a class being actually registered (via Object.registerClass)
// for this character — ... A plain exported .sprite symbol (every swfc sprite
// gets an export name) is NOT a registerClass sprite: its `mc.onLoad = function`
// is assigned by a later DoAction, after the clip's LOAD already passed, so
// Flash never fires it (action_execution_order_test12 expects loadOrder to
// stay "0+").
if (_rc_export != NULL && child_mc != NULL
    && lookupRegisteredClassByCharId(obj->char_id, g_swf_version, NULL) != NULL)
    actionQueueMCOnLoad(child_mc);
```

That gate **is** the 2026-05-19 `ACTION_EXECUTION_ORDER_TEST12_PLAN` fix
(`from_gnash/_investigation/CURRENT_STATUS.md:186`: *"timeline-sprite onLoad
gated on an actually-registered class (was queued for every exported
`.sprite`)"*), and `misc-swfc.all/action_execution_order_test12` is
**`ruffle_matched` at baseline** because of it. Widening the gate to satisfy
`extend_test` is the same edit rolled back.
This is the `rider-already-passing-is-regression-risk` pattern: the pairing
partner's fix has a *named live dependent*. **The arc's ceiling is +1, not +2**,
unless a session first pins the exact Flash fire/no-fire rule that separates the
two tests — which `ACTION_EXECUTION_ORDER_EXTEND_PLAN.md` says needs the Gnash
C source (`action_execution_order_extend.c`), not present in this repo.

### F2 — `extend_test` needs three mechanisms, not one, and exact-match requires replicating a Flash quirk Ruffle lacks

Reading `output.fp10.txt` vs `output.fp10.ruffle.txt` at HEAD:
- Flash **fires** `mc_red.onLoad` (line 8) but **not** `mc_blu.onLoad`
  (line 27 `y4 == undefined` is an *expected PASS*); Ruffle fires both.
- Flash emits an **extra** `mc_blu enterFrame executed` at line 17 that Ruffle
  does not.
- Flash's line 28 is itself a **`FAILED:`** line (`y5` obtained
  `'mc_blu onEnterFrame called'`); Ruffle *passes* that assertion.

So promoting `extend_test` needs (a) onLoad **method** dispatch for timeline
sprites under an unpinned rule, (b) onUnload **method** dispatch likewise,
(c) the D1 per-clip EF/frame-script interleave — and exact pass additionally
needs a Flash quirk that diverges from Ruffle. `ruffle_matched` promotion
(our diff ⊆ Ruffle's ~4-line diff) is the only realistic path and still needs
(a)+(b)+(c). The s14 report called this a "conditional +1"; it is more
accurately a **three-mechanism +1 with a −1 attached (F1)**.

### F3 — Track B must fuse **four** enterFrame dispatchers across **two different index spaces** (not in the s14 §5 list)

`tagFlushPendingEnterFrame` (`tag.c:4903-4954`) fans out to four dispatchers:

| dispatcher | file:line | ordering key |
|---|---|---|
| `dispatch_enterframe_clip_actions` | `tag.c:4727` | flat gather over display lists, `place_seq` DESC |
| `actionDispatchEnterFrameHandlers` | `action.c:35718` | **`child_mc_cache` reverse index** (MC creation LIFO) |
| `actionDispatchRootVarMapEnterFrame` | `action.c:35892` | root var_map order |
| `dispatch_attached_clip_enterframe` | `tag.c:4829` (browser-wasm arm) | attached-clip registry |

test11's passing `enterFrameOrder` assertion is produced by the **second** one —
`for (int i = child_mc_count - 1; i >= 0; i--)` over `child_mc_cache`
(`action.c:35723`) — i.e. AS2 `onEnterFrame` ordering already *is* flat-global
LIFO, while the advance ordering is per-subtree LIFO over `DisplayObject`
display lists. Track B's per-clip `{EF; advance}` adjacency therefore is not
"sort the advance passes the same way": it requires **fusing a `MovieClip*`
creation-index walk with a `DisplayObject*` display-list walk into one
iteration**, with the display-list context swap threaded through the middle of
what is today a pure MC-cache loop, and the two other dispatchers folded in.
The s14 §5 list (8 mechanisms) undercounts; this is a ninth, and it is the one
that makes Track B structurally hard rather than merely wide.

*Silver lining, unverified:* because `actionDispatchEnterFrameHandlers` already
walks the exact ordering `doActionOrder` demands, a future Track A could
plausibly be driven off `child_mc_cache` reverse order instead of building a new
flat gather with its own `ClipEFRebaseFrame` realloc protection. Whether MC
creation index and `place_seq` agree in general is **not verified** — flag as a
lead, not a plan.

---

## 4. Cost evidence (why this cannot be a wave-2 slot)

Measured on this shared machine at the s15 concurrency level:

| run | wall clock (`r`=recompile, `c`=gcc, `x`=exec) |
|---|---|
| `action_execution_order_test11` (`--recompile`) | `r=0.05s` **`c=168.07s`** `x=0.01s` |
| `action_execution_order_test5` (`--recompile`) | `r=0.03s` **`c=72.11s`** `x=0.01s` |
| `action_execution_order_test1` (`--recompile`) | same band |

Every test compiles the full runtime (`action.c` alone is ~50 k lines), so the
per-test floor is **~1.5–3 min**, and gcc is ~99.9 % of it. The s14 report's *mandatory* canary set is
~120 local tests (73-test `regression` suite + ~25 gnash misc-ming + 4 misc-swfc
+ 30 avm1 lifecycle + shumway `duplicateMovieClip`/timeline), and the brief caps
parallelism at `-P 2`. That is **~2–3 h of pure canary wall clock at best**, for a
change whose *fully successful* outcome is +1 test — and Track B additionally
requires a full corpus `Recompiled*` invalidation plus **both** CI modes
(`graphics` and `no-graphics`, since the recompiler emission moves).

Sibling-overlap adds to this: `w2-fuzz16`'s territory is the placement/depth path
in exactly these functions (`advance_sprite_frames` / `advance_nested_sprite_frames`,
where `ASF_SORT_CAP` lives). Track A's only sane edit site is the same two
functions. Even the narrow half of this arc collides with a live sibling.

---

## 5. Recommendation

1. **Keep the arc deferred.** Do not land Track A alone — it flips zero tests
   (test11 is all-or-nothing) while reordering every nested sprite frame script
   in the corpus.
2. **Re-price the board.** `polish-sweep-arc.md` §15.3 should read
   *"action_order arc DEFERRED, ceiling +1 (not +2) — the extend_test pairing is
   blocked by the test12 onLoad gate at `tag.c:772-788`; see
   session15-fanout-reports/w2-action-order-report.md §3"*. (Not edited by this
   agent — wave-2 agents don't touch shared docs mid-session; hand to whoever
   writes the s15 closeout.)
3. **If ever picked up**, the session shape is: a full dedicated day, games
   divergence harness in the loop (N / Tetris / Doodle Jump / Minesweeper),
   Track B behind a runtime A/B flag, and step 0 = obtain the Gnash
   `action_execution_order_extend.c` source to pin the onLoad fire/no-fire rule
   *before* touching the gate at `tag.c:772-788`. Without that source the
   pairing is net-zero at best.

---

## 6. Deliverables

- **Patch: none.** `git diff` in the worktree is empty; no source file was
  modified. (The worktree contains only two non-source additions made for
  measurement: a copy of `SWFRecomp/build` and a copy of the
  `from_gnash/misc-ming.all/action_order` test directory, both gitignored.)
- **Tests run (before/after are identical — no code change):**

| test | baseline | after | note |
|---|---|---|---|
| `action_order/action_execution_order_test11` | 26/32 `output_mismatch` | 26/32 `output_mismatch` | target, unchanged |
| `action_order/action_execution_order_test1` | pass | pass | canary/timing probe |
| `action_order/action_execution_order_test5` | pass | pass | canary/timing probe; also re-confirms the stale-doc correction (`SPRITE_EXEC_LIST_LIFO_PLAN` header) |

  The full ~120-test canary battery was **not** run: with no code change there is
  nothing to canary, and §4 documents why it is not affordable in a fan-out slot.
- **Docs that should be updated by the closeout agent:** `polish-sweep-arc.md`
  §15.3 (re-price +2 → +1, per §5.2); optionally add a pointer from
  `from_gnash/_investigation/blocked/ACTION_EXECUTION_ORDER_EXTEND_PLAN.md` to
  F1 (the plan lists the fire/no-fire subtlety but does not name `test12`'s
  `ruffle_matched` status as the concrete live dependent).
