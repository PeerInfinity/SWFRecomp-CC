# w2-avclasses — session 12, wave 2 (trace axis)

Agent: `w2-avclasses`. Isolated worktree of HEAD `f166e424e`. No commits to
master, no push, no full-suite runs.

**Deliverables** (in this directory):

| file | contents | applies to |
|---|---|---|
| `w2-avclasses.patch` | the SAFE bundle: 5 targets, 5 files, +751/−5 | `f166e424e` (verified `git apply --check`) |
| `w2-avm1movie.patch` | the RISKY single: 1 target, 1 file, +114/−3 | `f166e424e` **and** on top of `w2-avclasses.patch` (both verified) |

The two patches are **fully independent** — `w2-avm1movie.patch` applies cleanly
to a bare `f166e424e` as well as on top of the safe bundle, so the coordinator
can merge, defer, or drop it without touching the other.

---

## 0. Headline

**+6 effective, 0 regressions.** Every one of the six targets was verified
FAILING in this worktree at HEAD before any edit, and PASSING (or
`ruffle_matched`, where that is the ceiling) after. 22 canary runs, zero status
regressions, zero `pass → *` or `ruffle_matched → fail` slides.

| patch | targets | predicted CI flips |
|---|---|---|
| `w2-avclasses` | `av_classes`, `flash_trace`, `currency_parse_result`, `netfilterevent`, `groupelement_text` | **+5 effective** (4 plain pass + 1 `ruffle_matched`) |
| `w2-avm1movie` | `avm1movie_addcallback_call` | **+1 pass** |

All six are in `ruffle-tests/tests/swfs/avm2/`. `groupelement_text` is
upstream-`known_failure`, so `ruffle_matched` is its ceiling and it was reached
exactly (see §2.5).

---

## 1. Per-test ledger

### Targets

| test | suite | before (this worktree, HEAD) | after | patch |
|---|---|---|---|---|
| `av_classes` | avm2 | `output_mismatch` 1/340, `#1065 AVABRParameters` | **pass** 340/340 | avclasses |
| `flash_trace` | avm2 | `output_mismatch` 0/17, `#1065 Trace` | **pass** 17/17 | avclasses |
| `currency_parse_result` | avm2 | `output_mismatch` 0/7, `#1065 CurrencyParseResult` | **pass** 7/7 | avclasses |
| `netfilterevent` | avm2 | `output_mismatch` 0/10, `#1065 NetFilterEvent` | **pass** 10/10 | avclasses |
| `groupelement_text` | avm2 | `output_mismatch` 0/156, `#1065 GraphicElement` | **`ruffle_matched`** (effective pass — ceiling) | avclasses |
| `avm1movie_addcallback_call` | avm2 | `output_mismatch` 0/14, `#2007` on `addChild(null)` | **pass** 14/14 | avm1movie |

Every "before" row was reproduced locally, not taken from the CI board. All six
error signatures matched `wave1-trace-upstream4.md` / `wave1-trace-shoulder.md`
byte-for-byte. **No refutations: none of the six was already green.**

### Canaries — `w2-avclasses`

| canary | why | before | after |
|---|---|---|---|
| `avm2/text_engine_groupelement` | reads `getElementAt(i).text` through the changed fold | pass | **pass** |
| `avm2/textblock_createline_fte` | builds a GroupElement of real TextElements | pass | **pass** |
| `avm2/content_element_basic` | `CustomContentElement` subclasses the changed base | pass | **pass** |
| `avm2/textblock_createline_errors` | FTE error surface | pass | **pass** |
| `avm2/text_element_basic` | `TextElement.text` (the other `ce_text_of` arm) | pass | **pass** |
| `avm2/textblock_properties` | TextBlock surface | pass | **pass** |
| `avm2/textblock_line_changes` | `createTextLine` consumer of `ce_text_of` | `output_mismatch` 166/282 | **byte-identical diff** (stash-verified) |
| `avm2/textblock_recreateline` | ditto | `output_mismatch` 40/98 | **byte-identical diff** (stash-verified) |
| `avm2/av_networking_params` | the `avm2_net.c:2029` initialiser fix | pass | **pass** |
| `avm2/av_tag_data` | the AVTagData idiom the AV family copies | pass | **pass** |
| `avm2/abstract_classes` | shares `register_platform_stubs` | pass | **pass** |

The two already-failing FTE tests were checked with the **stash-diff sweep**
(capture `--diff` output → `git stash` the source edits → rebuild → re-capture →
`diff` the two): both are **byte-identical** before and after. That is the
strongest available statement that `ce_text_of`'s new GraphicElement arm and the
rewritten `group_text_of` are invisible to everything that does not actually use
a GroupElement or a GraphicElement.

### Canaries — `w2-avm1movie` (the two MANDATORY ones first)

| canary | why | before | after |
|---|---|---|---|
| **`avm2/abstract_classes`** | asserts script `new AVM1Movie()` is `#2012` | pass | **pass** OK |
| **`from_shumway/avm1movie`** | `ruffle_matched` on the same null-`content` bug | `ruffle_matched` 5/13 | **`ruffle_matched`** OK (promotion holds) |
| `from_shumway/as3-loader/bug1157243/empty` | malformed byte-shell → `#2124`, the arm my guard must not steal | pass | **pass** |
| `from_shumway/as3-loader/bug1157243/invalid` | ditto | pass | **pass** |
| `from_shumway/as3-loader/LoaderTest` | AVM2 child, deferred init/complete | `ruffle_matched` | **`ruffle_matched`** |
| `from_shumway/as3-loader/LoaderLoadBytesTest2` | loadBytes arm | pass | **pass** |
| `from_shumway/as3-loader/bug1093712/loader` | loader | pass | **pass** |
| `from_shumway/as3-loader/loaderinfo/Preloader` | loaderinfo | pass | **pass** |
| `avm2/loader_events` | the 92-line AVM2-child event-order pin | pass | **pass** |
| `avm2/loader_method` | loader surface | pass | **pass** |
| `avm2/loader_reuse` | re-`load()` on one Loader | pass | **pass** |
| `avm2/loader_unknown_content` | non-SWF content types | pass | **pass** |

Already-failing AVM1-child tests (status cannot regress; checked for crashes and
for *direction*):

| test | before | after | direction |
|---|---|---|---|
| `mixed_avm/avm2_loads_avm1_v9` | `output_mismatch` **2**/8 | `output_mismatch` **7**/8 | **large improvement** — only the AVM1 child's own trace is still missing |
| `mixed_avm/avm2_loads_avm1_v10` | `output_mismatch` 3/8 | `output_mismatch` 6/8 | improvement |
| `mixed_avm/avm2_loads_avm1` | `output_mismatch` 1/14 | `output_mismatch` | now emits `[object AVM1Movie]`, `[object ApplicationDomain]`, `Load complete!`; still positionally misaligned because the child's own traces are absent |
| `avm2/avm1_root` | `output_mismatch` 0/58 | `output_mismatch` 0/58 | strictly better: `ctr.getChildAt(0)` now returns `[object AVM1Movie]` (the expected value) instead of `#2006` |
| `avm2/mouse_pick_loader_avm1` | `output_mismatch` 5/42 | **byte-identical** (stash-verified) | no change |
| `mixed_avm/avm2_loads_avm1_loads_into_root` | `output_mismatch` 1/2 | unchanged | — |
| `mixed_avm/avm2_loads_avm1_doabc` | `output_mismatch` 1/4 | unchanged | — |

`avm2_loads_avm1_v9` was named in `wave1-trace-shoulder.md` §C6 as a gap-6
shoulder row blocked on exactly this. It is now **one line** from passing — that
last line needs the AVM1 child's timeline to actually execute (the declared
dual-VM arc), which is out of this charter.

---

## 2. What changed, and why it is shaped that way

### 2.1 `flash_trace` — `SWFModernRuntime/src/avm2/avm2_globals.c` (+~40)

Three tiny statics + a table inside `register_platform_stubs`, at the
`flash.crypto` anchor. Because `setLevel`/`setListener` are no-ops in the
**release** player (which is the behaviour `test.toml` says this test captures),
all four methods are pure constants: `getLevel → 0`, `getListener → null`, the
two setters `→ undefined`. The only non-trivial requirement is that
`Function.length` report the **declared** arity including optional params
(1/0/2/1), which `avm2_builtin_add_static_method_n` already does.

### 2.2 `currency_parse_result` — `avm2_globals.c` (+~60)

`flash.globalization`'s first class. Two read-only getters over dont-enum
dynamic backing props. Deliberately **no `CurrencyFormatter`**: nothing in the
corpus parses a currency, the test only constructs four instances and reads the
two fields.

### 2.3 `netfilterevent` — `avm2_events.c` (+86)

Drops into `register_net_events` next to `NetStatusEvent`. Three points worth
keeping:

* `header`/`data` are public **vars** upstream, not read-only props (the
  `wave1-trace-shoulder.md` sketch said read-only) — registered as get/set.
* They are held **by identity**, which `clone.header === a: true` grades, so
  `nfe_clone` passes the stored object references straight into the ctor rather
  than re-wrapping.
* `toString()` renders the class as **`NetTransformEvent`**, not
  `NetFilterEvent`. That is FP's own naming leftover; upstream replicates it and
  the test pins it verbatim.

The `ByteArray.toString()` parity risk the shoulder report flagged as the reason
to call this "+2 guaranteed, +3 likely" **did not materialise** — an empty
ByteArray already renders as `""` through `formatToString`, so this landed as a
plain pass with no extra work.

### 2.4 `av_classes` — `avm2_media.c` (+479) and `avm2_net.c` (+8/−5)

13 classes. The mechanical bulk was compressed by noticing that the family has
exactly **one shape**: a constructor that coerces its arguments into declared
slot types, then getter-only (twice: get/set) access. So:

* backing store = a fixed set of dont-enum dynamic props `_av0`.."_av10"
  (the AVTagData idiom → GC-traced for free, no `native_ext`, no mark hook);
* **one accessor per slot INDEX** serves every class — 11 getters, 11 String
  setters, 3 int setters, and that is the entire accessor surface for 50
  properties;
* a constructor body **is** its declared parameter-type string:
  `av_ctor(act, "SNNIIIIB")` is the whole of `AVTimeline`.

That is what keeps a 15-class API surface at ~480 lines with no per-property C.

Slot typing is most of what the test grades, and the type string encodes it
directly: `AVABRParameters("hello", 2.2, 3.3, 4.4)` reads back `2/3/4` because
`"SIII"`; `AVTrackInfo`'s `7.7` reads back as the **string** `"7.7"` while its
`8.8` reads back as the int `8` because `"SSBBBBSI"`.

Non-obvious values, all replicated verbatim and commented at the site:

* `AVStream.SOFTWARE = "sofware"` — FP's typo.
* `AVCaptionStyle.LEFT_DROP_SHADOW = "drop_shadow_left"` (side last).
* `AVCaptionStyle.bottomInset` defaults to the string `"0"`; the other ten
  default to `""`.
* `AVSegmentedSource` casing is inconsistent upstream: `DASH`/`HLS` upper-case,
  every content kind lower-case.
* `AVResult`'s consts are NOT contiguous — `-1`, then `0..91`, then a jump to
  `300..307` for the crypto block.
* `AVInsertionResult extends AVResult` but writes its inherited `result` slot
  itself, because `avm2_class_construct` calls only the **most-derived**
  `instance_init` (builtin inits are never chained — `IOErrorEvent` re-setting
  `error_event_init` is the existing evidence).

**Plus one real bug fixed** (`avm2_net.c:2029`): `AVNetworkingParams`'s
`appendRandomQueryParameter` was initialised to `avm2_null()` on the stated
grounds that it "has no initializer". It does — upstream declares
`private var _appendRandomQueryParameter:String = "";` — so it must read back as
the empty string. Two expected lines depend on it. `av_networking_params` (the
only other reader, and now upstream-deleted) still passes.

### 2.5 `groupelement_text` — `avm2_text.c` (+81/−22)

Three parts:

1. **`GraphicElement`** registered next to `GroupElement`: `ContentElement`
   base, `SEALED|FINAL`, ctor delegating to `ce_init(act, arg 3)` (its
   `super(elementFormat, eventMirror, textRotation)` call), three stub accessors
   (`null`/`15.0`/`15.0`).
2. **`group_text_of` rewritten as the null-propagating fold**, ported from
   Ruffle `content_element_object.rs::text()`. The old version skipped null
   children and never returned null; the real rule is asymmetric —

   * a non-null child is concatenated, or **adopted** when the result is null;
   * a null child **poisons an EMPTY result back to null**;
   * a null child leaves a **non-empty** result completely alone;
   * a null child does nothing to an already-null result.

   Implemented as an `SB` plus a `have` flag, where "concat" and "adopt" are the
   same operation on an empty buffer. That asymmetry is the entire point of the
   test: `[GraphicElement, GroupElement]` reads `null` while the identical set
   reversed reads `""`.
3. `ce_text_of` gains a GraphicElement arm returning the interned empty string —
   `Some("")`, never null, which is load-bearing for the fold.

**Ceiling reached exactly, and not exceeded.** `diff output.txt
output.ruffle.txt` is 2 lines (the `replaceElements(0,1,null)` and
`replaceElements(0,1,[])` cases, where FP reports `""` for a state that
`setElements(null)` reports as `null`). That is an unmodellable FP
residual-state artifact; upstream declined to replicate it and marked the test
`known_failure`. As briefed, **I did not chase those two lines** — the result is
`ruffle_matched`, which is the correct target.

### 2.6 `avm1movie_addcallback_call` — `avm2_display.c` (+114/−3), SEPARATE PATCH

Five hunks, all narrow:

1. `Avm2PendingLoad` gains `uint8_t avm1_child` (+ a forward decl of the mint).
2. The registry lookup sets it: `m->frame_funcs != NULL && m->avm2_tables == NULL`.
3. `loader_deliver` gains an **else-arm** to the existing `LI_CT_SWF && tables`
   gate that mints the wrapper, sets `content` + `expose_content`, and
   `insert_at_index(..., 0)` — mirroring the image arm.
4. `avm1movie_native_init` + `avm1movie_mint` + the two methods, placed after
   `morphshape_native_init`.
5. The class registration at `~13705` swaps `display_native_init_abstract` for
   the conditional gate and adds the two methods.

Three decisions worth recording:

* **The `#2012` gate stays**, as a *conditional* hook on the TextLine model
  (`g_avm1movie_mint_ok` armed only across `avm1movie_mint`). It cannot reuse
  MorphShape's `g_timeline_instantiation` flag — this mint comes from the
  loader, not from timeline placement. `abstract_classes` verifies it.
* **The guard is `avm1_child`, not `tables == NULL`.** The brief and the wave-1
  report both suggested `content_type == LI_CT_SWF && pl->tables == NULL`. That
  is **too wide**: a *bundled data file* whose bytes begin `FWS`/`CWS` also
  sniffs as `LI_CT_SWF` with no tables (`loader_sniff`, `avm2_display.c:4913`),
  and would have been handed a bogus AVM1Movie. The new flag is set only on the
  movie-registry path and only when `frame_funcs != NULL`, which simultaneously
  keeps the malformed byte-shell `#2124` route intact — verified by
  `bug1157243/{empty,invalid}` staying green.
* **`#1063` and `#2014` sit at different stack depths**, which is what the
  expected output actually grades. `#1063` is conceptually raised by the
  *caller*, so `avm1movie_throw_1063` pops the callee frame before throwing —
  exactly what `throw_1063` (`avm2_function.c:78-84`) does for script methods.
  `#2014` is raised from *inside* the method, through a synthetic
  `Error$/throwError` frame pushed above it (the `gfx_throw_2008_via_throwerror`
  idiom). No new `#1063`-for-builtins mechanism was needed.

---

## 3. Files and line counts

```
w2-avclasses.patch
  SWFModernRuntime/src/avm2/avm2_media.c    +479      AV* family + register_av_classes()
  SWFModernRuntime/src/avm2/avm2_globals.c  +102      flash.trace.Trace, CurrencyParseResult
  SWFModernRuntime/src/avm2/avm2_events.c    +86      NetFilterEvent
  SWFModernRuntime/src/avm2/avm2_text.c   +81/-22     GraphicElement + null-propagating fold
  SWFModernRuntime/src/avm2/avm2_net.c      +8/-5     appendRandomQueryParameter = ""

w2-avm1movie.patch
  SWFModernRuntime/src/avm2/avm2_display.c +114/-3    5 hunks (see §2.6)
```

### Sibling-collision surface

| file | my anchors | siblings named in the brief |
|---|---|---|
| `avm2_globals.c` | inside `register_platform_stubs` at the `flash.crypto` line, plus statics just above `crypto_generate_random_bytes` | `w2-errframes` may register at a **different** anchor — no overlap |
| `avm2_text.c` | `ce_text_of`/`group_text_of` (~6126) and the `GroupElement` registration tail (~7496); one 1-line static decl at 5505 | `w2-singles` ~8142, `w2-textblock` (TextBlock region), `w2-gfx-autosize` ~3892 — all disjoint |
| `avm2_media.c`, `avm2_events.c`, `avm2_net.c` | sole owner as far as the brief lists | — |
| `avm2_display.c` | 5 hunks, **confined to `w2-avm1movie.patch`** | four siblings edit this file; keeping it in the separate patch means a conflict there costs only this one test |

No reformatting of existing code anywhere; every hunk is additive except the
`group_text_of` body, the `avm2_net.c` initialiser, and the two-line AVM1Movie
registration swap.

### Verified co-application with the sibling patches

I applied every wave-2 patch present in this directory into one scratch tree, in
this order, with plain `git apply -p1`:

```
OK  w2-avclasses      OK  w2-avm1movie   OK  w2-errframes   OK  w2-xs
OK  w2-textblock      OK  w2-gfx-bitmapmax
```

**Zero conflicts, mine first.** That covers the three real overlaps —
`avm2_text.c` (mine + `w2-textblock` + `w2-xs`), `avm2_globals.c` (mine +
`w2-errframes` + `w2-xs`), and `avm2_display.c` (my avm1movie hunks +
`w2-errframes` + `w2-gfx-bitmapmax`). `w2-gfx-filters` touches only
`render_webgpu.c` and cannot collide. If later agents land more patches, mine
are the ones safest to apply first: they are almost entirely append-at-anchor.

---

## 4. Risks

1. **`avm2_display.c` merge pressure** (avm1movie only). Four siblings edit this
   file. Mitigated by isolation: the patch applies standalone to `f166e424e`, so
   dropping it is free.
2. **`all_classes/*` `describeType` dumps will move.** Nine new registered
   classes appear in `avm2/all_classes/{events,display}/swf*`. Every one of
   those is currently `output_mismatch` at 1-3 matching lines out of 1030-2936 —
   they **cannot change status**, only line counts, and adding real classes can
   only move them toward the oracle. Confirmed from the baseline board.
3. **New dynamic props on event objects.** `NetFilterEvent` stores `_header` /
   `_data` as dont-enum dynamic props on an `Event` instance rather than
   widening the shared `Avm2EventExt`. That keeps every other event free of the
   two extra fields, and dont-enum keeps them out of `for..in`. If a future
   `describeType`-of-an-Event test appears, note that these are dynamic props,
   not traits, so they should not surface.
4. **`avm1_child` and future non-registry SWF sources.** If a later change ever
   routes a real AVM1 child through the `DataFileEntry` path instead of the
   movie registry, the flag will read 0 and `content` will be null again. The
   flag is set in exactly one place and is commented to that effect.
5. **Not a risk, but worth stating:** the AVM1Movie wrapper is a live but
   **empty** DisplayObject — the child's AVM1 timeline still does not execute.
   `from_shumway/avm1movie` therefore keeps reporting `bounds: (0,0,0,0)`
   instead of `220x100`, which is precisely why its `ruffle_matched` promotion
   (diff-subset) continues to hold rather than turning into a pass.

---

## 5. Refutations and corrections to the wave-1 reports

1. **`wave1-trace-shoulder.md` §C1 called `NetFilterEvent`'s `header`/`data`
   "two read-only props".** They are public **vars** (writable) upstream. Only
   the getter side is graded, so the outcome is the same, but the registration
   differs.
2. **Same section priced C1 as "+2 guaranteed, +3 likely"** on the theory that
   `NetFilterEvent` might need `ByteArray.toString()` parity work. It did not —
   `formatToString` already renders an empty ByteArray as `""`. C1 landed at a
   clean **+3**.
3. **`wave1-trace-upstream4.md` §5 proposed guarding the new loader arm on
   `pl->content_type == LI_CT_SWF && pl->tables == NULL`** (plus a
   `frame_funcs` check "so malformed children keep routing to `#2124`"). The
   first half of that condition is genuinely too wide — `loader_sniff` returns
   `LI_CT_SWF` for any bundled **data file** beginning `FWS`/`CWS`, which has no
   tables either. The `frame_funcs` test has to be plumbed through the pending
   load as its own flag, not merely asserted at the delivery site, because
   `MovieEntry` is not reachable from `Avm2PendingLoad`.
4. **Same section warned that "builtins today check arity ad hoc per class" and
   suggested the `#1063` message would need hand-rolling.** True, but the harder
   half — getting `#1063` to appear WITHOUT the callee frame while `#2014`
   appears WITH it — is already solved twice in the tree (`throw_1063`'s
   `avm2_callstack_pop`, and `gfx_throw_2008_via_throwerror`'s synthetic push).
   Composing those two existing idioms is the whole fix; no new mechanism.
5. **`wave1-trace-upstream4.md` §2 estimated `av_classes` at "~500 LOC of
   mechanical registration".** Accurate in total, but the *mechanical* framing
   undersells the compression available: 50 properties across 13 classes need
   only 25 accessor functions and 10 one-line constructors once the family is
   keyed by slot index rather than by property name. Worth reusing if another
   value-object family shows up.
6. **No refutations on the targets themselves.** All six were genuinely failing
   at HEAD in this worktree; none was already green; none is covered by an
   existing disposition.

---

## 6. Dispositions

**None to write.** Consistent with `wave1-trace-upstream4.md` §7: all six are
implementable and none belongs in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, or any `ignored_tests.txt`. (Checked all four docs
and both ignore lists for all six names before starting — zero hits.)

One optional follow-up the coordinator may want: a one-line note in
`avm2/_investigation/` recording that `groupelement_text`'s residual 2 lines
(`replaceElements(0,1,null)` reporting `""` where the identical `setElements`
end state reports `null`) are an FP residual-state artifact that upstream itself
declined to model, so a future session does not re-litigate them. Since the test
is upstream-`known_failure` and our harness scores it `ruffle_matched`, it needs
no ignore-list entry.

---

## 7. Reproduction

Test dirs used (all gitignored under `ruffle-tests/tests/swfs/avm2/`; copied
into the worktree from the main tree, where wave-1 installed the four new
upstream ones):

```
targets   av_classes  flash_trace  currency_parse_result  netfilterevent
          groupelement_text  avm1movie_addcallback_call
canaries  abstract_classes  text_engine_groupelement  textblock_createline_fte
          content_element_basic  textblock_createline_errors  text_element_basic
          textblock_properties  textblock_line_changes  textblock_recreateline
          av_networking_params  av_tag_data  avm1_root  mouse_pick_loader_avm1
          loader_events  loader_method  loader_reuse  loader_unknown_content
          from_shumway/avm1movie  from_shumway/as3-loader/**  mixed_avm/**
```

```bash
python3 ruffle-tests/verify_output.py --test=NAME --diff [--recompile]
# nested suites need the suite root explicitly:
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway \
  --test=as3-loader/bug1157243/empty --diff
```

Runtime-only change: the recompiler build was copied from the main tree
(`SWFRecomp/build`), no cmake rebuild needed. Everything was run sequentially or
at most 2-up; no float or timeout artifacts observed, and every reported result
is from a clean run.

### Recommended CI dispatch

Both patches touch AVM2 runtime/emission surface, so per project policy:
`mode=graphics`, **`categories=full`**, `images=false`. The safe bundle and the
AVM1Movie patch can share one dispatch if merged together; if the coordinator
prefers to sequence them, the AVM1Movie patch is the one that deserves its own
run.
