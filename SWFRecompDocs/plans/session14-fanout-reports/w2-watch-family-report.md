# w2-watch-family — session 14 wave-2 (board T3)

**Agent:** wave-2 `watch-family` (implementation).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa3e873d56a472082`
(HEAD `0a99be1a9`; baseline CI run `31130292354` @ `fb36ba110`, trace 4237 effective).
**Patch:** `wave2/w2-watch-family.patch` (3 files, +163 / −41).
**Result: all four SWF7 targets flip `output_mismatch` → `pass`, byte-exact
(1042/1042 and 3118/3118 lines). Zero canary movement.** Board T3 estimated +4;
delivered 4 row flips, of which **+2 count toward session 14's yield** and
**+2 are drift rows** (§5).

---

## 1. The hypothesis, and what actually turned out to be true

The brief's hypothesis — "the swf6 variants all `ruffle_matched`, the swf7
variants all fail, therefore ONE version-gated defect in `watch` re-entry" — is
**half right and half wrong, and the wrong half is the useful part.**

- **Right:** it is one mechanism, and it does live in the re-entry model.
- **Wrong:** it is not version-gated. The version gate
  (`accessorReentryLimit()` = 1 at SWF6, 65 at SWF7+) was already correct and
  is untouched by this patch. The defect was *version-independent*; SWF6 merely
  hid it, because at limit 1 the wrong counter and the right counter block at
  the same moment for these programs. The swf6/swf7 split in the results table
  is a **visibility** split, not a mechanism split.

Two things had to be verified before writing code, and both were:

**(a) The four dirs are two tests.** `watch_special_recursion_*` are not new
upstream arrivals — they are the pre-rename duplicates that `download_tests.sh`
never cleans (the rename note is already in `ACCEPTED_DIFFS.md` Category 10).
`md5sum` says `test.swf`, `test.as` and `output.txt` are byte-identical between
every `watch_special_recursion_X` and its `watch_recursion_X` — all eight dirs,
swf6 and swf7. The only files that differ are the stale ones upstream has since
revised: `watch_special_recursion_double_swf7` still carries
`known_failure = true` (dropped in the new-name dir) plus an `output.ruffle.txt`
the new-name dir no longer ships, and `watch_special_recursion_double_swf6`
carries an older `output.ruffle.txt`. So the family is **2 distinct programs
(× 2 SWF versions) under 2 directory names each**, and one
fix necessarily moves all four. The wave-1 audit's §2.1 line "the 2 new failures
are new arrivals" is true about grading but misleading about content: they add
nothing to the corpus that was not already there under another name.

**(b) `known_failure` is gone from the swf7 `test.toml`s.** Both
`watch_recursion_swf7` and `watch_recursion_double_swf7` ship `output.txt` with
**no** `known_failure` flag — upstream now considers them matchable, and
`output.txt` is the Flash oracle. (Their *swf6* siblings are the ones carrying
`known_failure = true` now.) The disposition in `ignored_tests.txt` —
"full match is unreachable: `watch_recursion_swf7` ships no `output.ruffle.txt`
(no RM target)" — had the fact right and the conclusion backwards: with no
`known_failure`, `output.txt` itself is the reachable target.

**Dispositions checked before implementing** (per the `accepted-diffs-first`
rule): both swf7 names were in `ignored_tests.txt` and in `ACCEPTED_DIFFS.md`
Category 10 as accepted diffs; neither appears in `RUFFLE_VS_FLASH_DIFFERENCES.md`
or `RUFFLE_COMPAT_TWEAKS.md`. Both dispositions are now **refuted and rewritten**
(§4).

---

## 2. Mechanism

### 2.1 Flash keeps ONE special-access counter per property, not two

A property can carry an `addProperty` getter/setter **and** an `Object.watch`
handler at the same time (that is exactly what the `o2` half of each test sets
up). We ran two independent re-entry counters over it:

| counter | key | cap |
|---|---|---|
| `watch_firing_depth()` | (object \| MovieClip, property name) | `accessorReentryLimit()` |
| `countActiveAccessorEntry()` | `ASProperty::vprop_id` (the addProperty entry) | `accessorReentryLimit()` |

Flash keeps **one**. Watch-handler invocations and accessor invocations
increment the same per-property counter, and once it reaches the limit
(1 at SWF6, 65 at SWF7+) *all three* — getter, setter, watcher — are bypassed
and the access bottoms out at the property's underlying stored value
(`prop->value`).

The Flash oracle pins this with no slack. In `watch_recursion_swf7`, the diff
against `output.txt` was a **single hunk**, at the innermost (65th) watch
handler:

```
   o2.prop changed
 -   o2.prop: undefined            <- Flash: getter BLOCKED, raw read
 +  o2.prop getter                 <- us: getter fires, returns "e"
 +    p: undefined,undefined
 +    o2.prop: e
     p: prop,undefined,c,undefined
 + o2.prop setter                  <- us: setter fires with "c"
 +   p: c,undefined
   Set to c, returning d
 -   o2.prop: c                    <- Flash: raw read of the raw store
 +  o2.prop getter
 +    p: undefined,undefined
 +    o2.prop: e
```

At that frame **no accessor is on the C stack at all** — the getter had already
returned 64 levels ago. Only the *watch* nesting is 65. So the accessor block
must be reading the watch depth. Symmetrically, the assignment inside that
handler stores raw and the read-back yields `"c"`, so the setter is blocked by
the same count.

The invocation counts confirm it arithmetically rather than by anecdote:

| | expected (Flash) | ours, before | ours, after |
|---|---:|---:|---:|
| `watch_recursion_swf7` — `o2.prop changed` | 65 | 65 | 65 |
| — `o2.prop getter` | **129** | 131 | **129** |
| — `o2.prop setter` | **65** | 66 | **65** |
| `watch_recursion_double_swf7` — `prop1` getter | **257** | (truncated) | **257** |
| — `prop2` getter | **259** | (truncated) | **259** |

129 = 65 handlers × 2 reads + 1 final read − 2 blocked reads in the frame where
the sum hits 65. The double variant's **−4 / −2 asymmetry** is the strongest
evidence: `prop1` loses two reads in frame k=129 (where `prop1`'s own watch depth
reaches 65 first, one frame before `prop2`'s) *and* two more in k=130, while
`prop2` only loses the pair in k=130. No "two independent counters" model
produces a 4-vs-2 split; the shared counter produces it exactly.

The same model reproduces **SWF6** with limit 1, which is why the swf6 siblings
also moved from partial to (whitespace-modulo) exact — see §3.3.

### 2.2 The `MAX_SPECIAL_DEPTH` cap was stale, and it truncated the double test

The second (independent) half. The watch guard carried a hard total-nesting cap
of `MAX_SPECIAL_DEPTH` (66), documented as a C-stack safety measure:
*"Flash's true depth there (130 each) would overflow our C stack"*. That stopped
being true on 2026-07-02, when the `RLIMIT_STACK` constructor raised the soft
limit to 64MB and the `virtual_property_recursion` family started recursing 130
deep through the *same* interpreter frames — but the watch guard was never
re-costed. It cut `watch_recursion_double_swf7` off at 1596 of 3118 lines
(gap 2709, the worst number on the board's T3 row).

Raised to `MAX_WATCH_NESTING` (200), comfortably above the legal 130 and below
`MAX_WATCH_FIRING` (256, the point at which pushes silently drop and the guard
would stop counting).

This is a small instance of a general trap worth naming: **a safety cap written
against a constraint that was later lifted keeps producing wrong output forever,
because nothing fails when the constraint goes away.** The 2026-07 stack fix
even *mentions* this family in its memory note and still left the cap in place.

---

## 3. Before / after

### 3.1 The four targets (all flip)

| test | before | after | lines (e/a/m) before → after |
|---|---|---|---|
| `avm1/watch_recursion_swf7` | `output_mismatch` | **pass** | 1042/1048/1036 → 1042/1042/1042 |
| `avm1/watch_recursion_double_swf7` | `output_mismatch` | **pass** | 3118/1596/409 → 3118/3118/3118 |
| `avm1/watch_special_recursion_swf7` | `output_mismatch` | **pass** | (identical program) → 1042/1042/1042 |
| `avm1/watch_special_recursion_double_swf7` | `output_mismatch` | **pass** | (identical program) → 3118/3118/3118 |

Byte-exact, not near-miss: `matching == actual == expected` on all four.

### 3.2 Canaries — 21-test avm1 family probe

`--tests-dir=ruffle-tests/tests/swfs/avm1`, 21 tests, sequential, no `--mode`
override (no-graphics; mode parity is complete).

```
BEFORE   pass 11   ruffle_matched 5   fail 5    (effective 16/21)
AFTER    pass 15   ruffle_matched 5   fail 1    (effective 20/21)
```

| test | before | after |
|---|---|---|
| `watch` | pass | pass |
| `watch_infinite_recursion` | pass | pass |
| `watch_proto_recursion` | pass | pass |
| `watch_textfield` | pass | pass |
| `watch_virtual_property_proto` | pass | pass |
| `watch_virtual_property` | `output_mismatch` (60/52/9) | `output_mismatch` (60/52/9) — **unchanged**, pre-existing, `known_failure` + ignore-listed |
| `add_property` | pass | pass |
| `infinite_recursion_virtual_property` | pass | pass |
| `virtual_property_recursion_swf6` | ruffle_matched (6/8/5) | ruffle_matched (6/8/5) |
| `virtual_property_recursion_swf7` | pass (262/262/262) | pass |
| `virtual_property_recursion_double_swf6` | pass | pass |
| `virtual_property_recursion_double_swf7` | pass (523/523/523) | pass |
| `virtual_property_recursion_scope` | pass | pass |

The `virtual_property_recursion` family — the population the
`virtual-property-reentry-per-entry-model` memory was derived from, and the
one most exposed to a change in `virtualAccessorBlocked()` — is **bit-identical
before and after**. That is structural, not luck: `watch_firing_depth_recv()`
returns 0 whenever no watch handler is executing, so the added term vanishes
outside watch dispatch.

### 3.3 The four swf6 siblings — explicit `ruffle_matched` re-verification

These were flagged as the most fragile canaries (their grade can move without
crossing pass/fail). **All four re-verified as `ruffle_matched` after the
change**, and every one of them moved *closer* to the Flash oracle:

| test | before | after |
|---|---|---|
| `watch_recursion_swf6` | **ruffle_matched** e=18 a=24 m=12 | **ruffle_matched** e=18 a=18 m=17 |
| `watch_recursion_double_swf6` | **ruffle_matched** e=46 a=60 m=18 | **ruffle_matched** e=46 a=46 m=42 |
| `watch_special_recursion_swf6` | **ruffle_matched** | **ruffle_matched** e=18 a=18 m=17 |
| `watch_special_recursion_double_swf6` | **ruffle_matched** | **ruffle_matched** e=46 a=46 m=42 |

Line counts are now exact (24→18, 60→46), and the **entire remaining residual is
trailing whitespace**:

```
-  o2.prop:
+  o2.prop: ␣
```

SWF6 stringifies `undefined` as `""`, so `trace("  o2.prop: " + o2.prop)` emits
the literal's own trailing space; the checked-in `output.txt` has it stripped.
Our SWF6 behaviour under the unified model is therefore **exactly Flash's** —
1 such line in `watch_recursion_swf6`, 4 in the double. I deliberately did **not**
chase these into a pass: making them pass means normalising trailing whitespace
in the comparator, which is a corpus-wide comparator change, not a watch fix, and
they already count as effective. Logged in `ACCEPTED_DIFFS.md` Category 10.

### 3.4 Regression suite

`--tests-dir=ruffle-tests/tests/swfs/regression`, all 71 tests.
Baseline for comparison is the merged CI result at `fb36ba110`
(`_results/results_graphics.json`: 71 total, **71 pass**, 0 fail).

```
AFTER    Total tests: 71    Pass: 71 (100.0%)    Fail: 0
Final diff vs previous results:  [diff] pass: 71/71  |  vs prev: no changes
```

**71/71, zero movement** — the runner's own per-test `vs prev` comparison
reported "no changes" on every one of the 71 tests, not just the same totals.

The six watch-specific regression tests (`watch_cross_swf_version`,
`watch_mc_reentrant_setmember`, `watch_mc_type1_args`,
`watch_setmember_type1_args`, `watch_timeline_named_params`,
`watch_timeline_reentrant`) cover all three dispatch sites this patch touches,
including the two MovieClip/timeline sites that the four target tests never
exercise.

---

## 4. Files edited

| file | change |
|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | the fix (below) |
| `ruffle-tests/ignored_tests.txt` | **de-listed** `watch_recursion_swf7`, `watch_recursion_double_swf7`; replaced the block comment with the resolution + a do-not-re-add note |
| `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | Category 10 marked **RESOLVED**, full mechanism written up, per-test table and the global summary-table rows corrected |

Nothing else in the tree was modified. (Test directories were copied into the
worktree from the main tree for grading and are untracked; they are not in the
patch. `ruffle-tests/tests/swfs/regression/_results/results_previous.json` is
touched by the runner as a side effect and is excluded from the patch.)

### The code change, in four pieces (`action.c`)

1. **`watch_firing_depth_recv(recv, prop, len)`** (new, next to
   `watch_firing_depth`) — receiver-keyed variant matching on *either* the
   object or the MovieClip slot, because an accessor dispatch holds one opaque
   `void* this_obj` and does not know which kind it is. Returns 0 for a NULL
   receiver so a NULL `this_obj` can never alias the mc-keyed rows.
2. **`#define MAX_WATCH_NESTING 200`** (new) replacing `MAX_SPECIAL_DEPTH` (66)
   as the watch total-nesting backstop (§2.2).
3. **`watchReentryBlocked(obj, mc, prop, len)`** (new) — the shared guard now
   used by all three watch dispatch sites, replacing three copies of
   `watch_firing_depth(...) >= accessorReentryLimit() || g_watch_firing_count >= MAX_SPECIAL_DEPTH`.
   Adds the accessor half of the shared counter.
4. **`virtualAccessorBlocked()`** — adds `watch_firing_depth_recv(...)` to both
   the SWF6 (per receiver/name/kind) and SWF7+ (per vprop entry) arms. This is
   the term that produces every one of the flipped lines.

**Depth risk of raising the cap.** Watch nesting can now reach 130 native
frames where it previously stopped at 66. This is the same
`actionSetMember`/`actionGetMember` frame shape that
`virtual_property_recursion_double_swf7` already recurses 130 deep through and
that the 2026-07 `RLIMIT_STACK` (64MB) constructor was written for, and
`g_call_depth`/`g_max_call_depth` (256, script death) remains the real backstop
above it — `MAX_WATCH_NESTING` is only the non-fatal drop-the-call guard.
Emscripten builds rely on `-sSTACK_SIZE` for the same headroom (the
`wasm-stack-overflow-64kb` note), and are unchanged in kind, only in degree.

The two halves of the shared counter are keyed slightly differently by
necessity: the accessor side keys on `vprop_id` (a proto entry shared by several
receivers shares one counter — the `virtual_property_recursion_scope` rule),
while the watch dispatch sites only hold a receiver, so the accessor half read
there is keyed by (receiver, name). The keys can only diverge when one
`addProperty` entry on a prototype is watched through several receivers; a
watcher is registered per receiver, so no test in the corpus distinguishes them.
Noted rather than papered over.

---

## 5. Yield accounting — which flips are session-14 yield and which are drift

Per the wave-1 audit §2.1 the next CI run gains **+9 effective from upstream
drift** regardless of session 14's work, and any yield claim must be stated net
of it. Splitting this patch's four flips accordingly:

| row | in the `fb36ba110` baseline? | counts as |
|---|---|---|
| `avm1/watch_recursion_swf7` | yes (graded, `output_mismatch`) | **s14 yield: +1** |
| `avm1/watch_recursion_double_swf7` | yes (graded, `output_mismatch`) | **s14 yield: +1** |
| `avm1/watch_special_recursion_swf7` | no (on disk, ungraded) | **drift row** |
| `avm1/watch_special_recursion_double_swf7` | no (on disk, ungraded) | **drift row** |

**Session 14 yield from this brief: +2 effective.** The other two are drift rows
whose *arrival* is upstream's and whose *pass* is this patch's — the audit
projected them to land as 2 new **failures** (4246 effective / 4438 with 2 new
failures); with this patch they land as 2 new **passes** instead. So the
projected post-merge baseline becomes **4248 effective / 4438**, of which
+9 is drift-as-audited, +2 is this patch on drift rows, and +2 is this patch on
baseline rows.

Board T3 estimated **+4** and the patch delivers 4 row flips — but the honest
headline contribution is **+2**, because two of the four rows are the same two
programs counted under their pre-rename directory names. If the coordinator
wants the corpus to stop double-counting this family, the cheap fix is
`download_tests.sh --clean` (or deleting the four `watch_special_recursion_*`
and four `virtual_property_special_recursion_*` dirs), which would remove 8
rows from the denominator, 8 from effective, and leave the ratio unchanged.

---

## 6. Doc corrections this work forces

1. **`ignored_tests.txt` / `ACCEPTED_DIFFS.md` Category 10** — done in this
   patch. The accepted-diff ruling was wrong on both counts it asserted
   ("no RM target ⇒ unreachable" and "130-deep would overflow our C stack").
2. **Memory `virtual-property-reentry-per-entry-model`** (not editable from
   this worktree; flagged for the coordinator): its closing line
   *"watch_recursion_swf7/double_swf7 stay accepted diffs (watch-vs-getter
   firing-order gap, not the stack)"* is now false, and its model statement is
   **incomplete rather than wrong** — the 65-per-entry rule is right, but the
   entry counter is shared with the property's `watch` handler. Suggested
   amendment: *"the counter is per property ENTRY and counts watch-handler
   invocations alongside getter+setter; at the limit all three are bypassed."*
3. **Board `polish-sweep-arc.md` §14.3 / the T3 row** — resolvable; note that
   the family is 2 programs under 4 names.

---

## 7. Follow-on lead found while grading (NOT fixed here)

`avm1/watch_virtual_property` (60/52/9, `known_failure`, globally ignore-listed)
is the one still-failing row in the probe, unchanged by this patch — and its
diff says it is a **different and probably cheap** defect in the same family:

```
-  plusOne: variable changed from undefined to undefined with userdata undefined
-  plusOne: variable changed from NaN to 10 with userdata undefined
-  plusOne: variable changed from 11 to 4 with userdata undefined
```

Every `plusOne:` line is missing from our output: **the watcher is never invoked
at all when the watched name is a timeline variable that also has an
`addProperty` getter/setter.** The virtual-property branch takes the assignment
before the watch table is consulted, so the handler is skipped entirely (not
blocked by any re-entry rule — the counters are at 0 here). A second, smaller
tell in the same test: `unwatch("variable")` returns `true` where Flash returns
`false`.

That is a *dispatch-ordering* bug (watch must run before the virtual setter, the
order Ruffle's `set_internal` uses — `call_watcher` precedes the proto-chain
virtual-setter walk), not a re-entry bug, so it is out of scope for this brief.
It is worth **+1 effective** and sits in code this patch has already warmed up.
Recommended as a small standalone wave-2/3 item.

## 8. Reproduction

```bash
W=/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa3e873d56a472082
cd $W && (cd SWFRecomp/build && cmake .. && make -j4)

# the four targets + 17 canaries (sequential; machine is shared)
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm1 \
  --test=watch_recursion_swf7 --test=watch_recursion_double_swf7 \
  --test=watch_special_recursion_swf7 --test=watch_special_recursion_double_swf7 \
  --test=watch_recursion_swf6 --test=watch_recursion_double_swf6 \
  --test=watch_special_recursion_swf6 --test=watch_special_recursion_double_swf6 \
  --test=watch --test=watch_infinite_recursion --test=watch_proto_recursion \
  --test=watch_virtual_property --test=watch_virtual_property_proto \
  --test=watch_textfield --test=add_property \
  --test=infinite_recursion_virtual_property \
  --test=virtual_property_recursion_swf6 --test=virtual_property_recursion_swf7 \
  --test=virtual_property_recursion_double_swf6 \
  --test=virtual_property_recursion_double_swf7 \
  --test=virtual_property_recursion_scope -v --recompile

python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/regression -v

# A/B (never `git stash` — shared across worktrees)
git apply -R wave2/w2-watch-family.patch   # back to baseline
git apply    wave2/w2-watch-family.patch   # forward again
```

Test directories were copied from the main tree into the worktree's canonical
paths (`ruffle-tests/tests/swfs/avm1/`); the main tree was never written to and
no full suite was run locally.
