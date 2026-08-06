# w2-triage-batch — wave-2 implementation report (session 11)

Worktree: `.claude/worktrees/agent-a51034a8e147a730f` at `b4c983ea4`.
Patch: `w2-triage-batch.patch` (7 files, +184/−6). No commits, no pushes.
Every result below is a local `verify_output.py --recompile` run in that
worktree (no-graphics; recompiler rebuilt in-worktree via cmake so the
`verify_output.py` change is exercised end to end).

## Ledger — 7 targets landed, 3 skipped

| Item | Test | before | after |
|---|---|---|---|
| B1 | `from_shumway/as3-loader/bug1157243/empty` | output_mismatch (gap 1) | **pass** |
| B1 | `from_shumway/as3-loader/bug1157243/invalid` | output_mismatch (gap 1) | **pass** |
| B3a | `from_avmplus/regress/bug_550958` | output_mismatch (gap 1) | **pass** |
| B3b | `avm2/constructsuper_null` | output_mismatch (gap 2) | **pass** |
| B3c | `avm2/system_exit` | output_mismatch (gap 3) | **pass** |
| B4 | `avm1/load_cancel_via_removemovieclip` | output_mismatch (gap 0, 4 extra) | **pass** |
| B5 | `avm2/cross_api_version_call_newer` | output_mismatch (gap 1) | **pass** |
| B2 | `avm2/method_association` | output_mismatch (gap 4) | **SKIPPED** (unreachable, see below) |
| B2 | `avm2/verify_method_info_duplicate` | output_mismatch (gap 1) | **SKIPPED** (oracle conflict, see below) |
| B6 | `from_shumway/acid/acid-morph` | output_mismatch (gap 2) | **SKIPPED / reverted** (diagnosed, see below) |

**+7 trace passes** (lower bound; sibling patches may interact).
B7/PerspectiveProjection untouched per the brief.

## What landed, per item

### B1 — malformed sibling `.swf` → IOError #2124
Exactly the report's shape, both halves.
- `ruffle-tests/verify_output.py`: new `generate_malformed_movie_file()` plus an
  `elif is_avm2:` arm on the child loop in `compile_native` — when
  `recompile_child_swf` fails, emit a byte-only `MovieEntry` shell (filename +
  `file_size` + `raw_bytes`, `frame_funcs`/`init_func` NULL) so
  `loader_resolve_url` finds it. **AVM2 parents only**, which is what keeps the
  AVM1 `findDataFile`/registry consumers out of it.
- `avm2_display.c loader_resolve_url`: the `MovieEntry` arm no longer hard-codes
  `LI_CT_SWF`. The discriminator is `m->frame_funcs == NULL` (only a shell has
  none — real children, image shells and self-loads all have them), and a shell
  sniffs its raw bytes: 0-byte and header-less files both come back
  `LI_CT_UNKNOWN` and take the existing `loader_deliver` #2124 arm.
  `loader_sniff(NULL, 0)` already returns UNKNOWN, which is what makes the
  0-byte `empty.swf` work with no raw array emitted at all.

Note the WASM build's twin child loop (`verify_output.py` ~:2700) was left
alone: it has no `is_avm2` and no `raw_bytes` plumbing, and browser builds do
not run this suite.

**Mandatory canary `avm1/movieclip_state_values`: PASS** (unchanged). It is an
AVM1 parent, so the `elif is_avm2` never fires for its two header-less
`no correct file (*).swf` children and `getBytesTotal()`/`getSWFVersion()` keep
returning −1.

### B3a — `<!DocType>` case-insensitivity
`avm2_e4x.c`: new `starts_with_ci()` next to `starts_with()`; the DOCTYPE arm
(was `"<!DOCTYPE" || "<!doctype"`) now uses it. `ps.pos += 9` unchanged. The
second parser (`avm2_xml.c:2906 XN_DOCTYPE`) turned out to be a bare enum
constant with no scanner behind it — nothing to change.

### B3b — null-receiver `constructsuper` → #1009
`avm2_ops.c avm2_op_constructsuper`: a `value_is_null_like(recv)` guard that
throws via `avm2_throw_null_or_undefined` (so null → #1009, undefined → #1010),
placed **after** the `bound_class == NULL` script-initializer early return the
report flagged.

### B3c — `System.exit` → SecurityError #2017
`avm2_globals.c`: `system_exit` registered with
`avm2_builtin_add_static_method_n(..., 1)`, unconditionally throwing #2017.
The stack-frame half needed one thing the report did not predict: the native
static call ALREADY pushes a frame, and it renders `flash.system::System/exit()`
— `avm2_callstack_frame_name` cannot tell a static builtin frame from an
instance one. So `system_exit` **pops its own frame and pushes a synthetic
one** (`bound_class` NULL + `file` NULL ⇒ `debug_name` printed verbatim, the
`Error$/throwError` idiom) named `flash.system::System$/exit`. The pop is
guarded on the top frame actually being ours.

### B4 — `removeMovieClip` cancels a pending load
Two queues, not one — this is the one place the report's sketch was short.
- `action.c actionFirePendingLoadInits` (the MCL queue): the copy loop now drops
  entries whose target is dead, using the canonical trio
  `avm1_removed || pending_removal || depth == INT_MIN`. Dropping (not skipping
  the handler) is required: the child's init must not run either.
- `action.c actionFirePendingDirectLoads` (the plain-`loadMovie` queue): same
  guard. Without it the test still emitted one ` - this should not trace!`,
  which comes from the CHILD SWF's own frame script running under the
  `mc_loadMovie` half of the test — the parent SWF's string pool does not even
  contain that string.

### B5 — API-versioned `flash.events.Event` constants
`avm2_events.c`: `VIDEO_FRAME` / `CHANNEL_MESSAGE` / `CHANNEL_STATE` /
`WORKER_STATE` moved out of the unconditional `consts[]` table into a
`ctx->swf_version >= 17` block. **The gate version is 17, not the report's
guessed 18**, and it is now pinned rather than guessed: Ruffle's `Event.as`
tags all four `[API("682")]`, and avmplus api-versions are offset by 660
(682−660 = 22 = `ApiVersion::SWF_17`; the same arithmetic reproduces
`avm2_number.c`'s existing API-680 ⇒ `>= 16` gate). Root-vs-child was confirmed
from the SWF headers: `cross_api_version_call_older` is root v43 / child v12 and
expects `workerState` present; `cross_api_version_call_newer` is root v12 /
child v43 and expects `undefined`. `ctx->swf_version` is the root's.
`avm2/all_classes/events/swf{9,10,11,12}` independently confirm the boundary
(they list neither the four nor `SUSPEND`/`CLOSING`/`EXITING`; swf30 lists the
four). The AIR-only trio (`CLOSING`/`EXITING` API 661, `SUSPEND` API 681, all
of which map to `VM_INTERNAL` under FlashPlayer and so should be absent at
every version) was deliberately left alone — no test in the corpus references
them and all five `all_classes/events/*` rows fail for unrelated reasons.

**Canary `avm2/cross_api_version_call_older`: PASS** (was pass).

## Skipped, with findings

### B2 — ABC-verifier method_info association: SKIPPED, +0 either way
Both halves turned out to be unreachable; the recompiler was left untouched,
which also spares the batch a `categories=full` CI + broad `--recompile` sweep.

**`verify_method_info_duplicate` — hard oracle conflict with a PASSING sibling.**
The missing line is `ReferenceError: Error #1065: Variable Test is not defined.`,
i.e. the root `SymbolClass` binding failing to resolve after the ABC is rejected
at load. Implementing that in `avm2_display_build_stage` (the `bound == NULL`
arm, next to the existing #2023 printf) is a five-line change — but
**`avm2/verify_method_info_oob` currently PASSES and pins the opposite**: same
`SymbolClass 0 → Test`, same whole-ABC load rejection (both come out of the very
same `abc_parser.cpp` method-body loop, 8 lines apart: #1027 vs #1121), and its
`output.txt` is the VerifyError line ALONE. Its `output.ruffle.txt` is the
2-line version — so adding the #1065 flips `verify_method_info_duplicate`
mismatch→pass and `verify_method_info_oob` **pass→ruffle_matched, which is a
regression** (memory `ruffle-matched-trap`). Net 0 passes for a real regression.
The only way to take the +1 is to key the #1065 on load-error code == 1121,
which encodes an oracle inconsistency (both tests are `known_failure = true`
upstream) into the runtime. Recommendation: leave it, or dispose of one of the
two after deciding which FP capture is trustworthy.

**`method_association` — cannot reach a full pass; the 5th expected line has no
source in the SWF.** The report's rule set is right and I confirmed it from the
ABC, but the arithmetic does not close:
`output.txt` is 5 lines (`1107 / 1107 / 1034 / Passed / Passed`) while the SWF
contains exactly **4** probes. `Test/Test` (method[6]) has 4 `CallPropVoid
testN` sites (ops 10/34/58/82), 8 `trace` calls (one try + one catch per probe)
and — decisive, since it is read straight from the ABC, not inferred — a
**4-entry exception table** (ops 9..14, 33..38, 57..62, 81..86). Each probe can
print exactly one line. The SWF has one DoABC tag (verified by walking the tag
list: 69/9/82/76/1/0) and one class. So the best reachable result is 4/5 lines
(gap 4 → gap 1) — still `output_mismatch`. Implementing the three rules would
therefore have bought 0 passes while touching `abc_verifier.cpp` +
`abc_emit.cpp`, whose blast radius is the whole 1574-test `from_avmplus`
corpus. Skipped deliberately.
For whoever picks it up: the rules themselves are confirmed against
`~/CC/ruffle/core/src/avm2/method.rs` (`associate` ⇒ #1107 on a bound_class
mismatch, `check_classbound` ⇒ #1107 when unbound) and are statically decidable
from the ABC (a method is "class-bound" iff it appears as a class trait /
iinit / cinit): newfunction on a class-bound method_info ⇒ #1107 (test1);
callstatic on an unbound one ⇒ #1107 (test2); callstatic receiver coerces to the
declaring class ⇒ #1034 at runtime (test3). Resolving the 5th line needs a real
FP capture.

### B6 — MorphShape shape hit-test: SKIPPED (implemented, diagnosed, reverted)
The mechanism is confirmed and there are **two** lags, not one:
1. `has_pick_geometry` excludes morphs (`&& !ext->is_morph_shape`), so a morph
   falls back to the bounding box; and
2. `display_self_bounds` → `char_self_bounds(char_id)` returns the character's
   recorded (START) bounds, so even the AABB pre-reject in `point_in_self` lags
   the whole tween.

I implemented both (morph branch in `shape_contains_local` doing the
`avm2_render_morph` lerp — `floor(start*(1−r) + end*r + 0.5)` over
`shape_data` / `morph_end_shape_data` at `ext->ratio/65535` — and a
`morph_lerped_bounds()` used by `display_self_bounds`). Result: `acid-morph`
went 4/6 → **5/6** matching lines (line 3 fixed), but line 4 stayed wrong and
the test does not flip, so I **reverted both hunks** rather than ship a
corpus-wide change to morph `getBounds`/`width`/`height`/hit-testing for zero
measured gain.

Residual diagnosis for the next attempt (instrumented run, `MORPH_DBG`):
the two `hitTestPoint` calls map the (100,100) probe to the SAME local point
(−3420,−1980) twips, i.e. the clip's world matrix is identical at both calls, so
only the ratio differs (0 → 54237/65535 ≈ 0.827). The lerped outline's local
bbox is (−4900,−3440)…(−2180,−880) at r=0 and (372,837)…(1569,1588) at r=0.827,
which extrapolates to ≈(1475,1731)…(2352,2103) at r=1. The (300,300) probe lands
at local ≈(580,2020) — and **no ratio in [0,1] puts that point inside the
interpolated box** (x needs r ≤ 0.86, y needs r ≥ 0.97). So the geometry we hold
for this morph is incomplete, not merely mis-phased: `n = 27` vertices (9
triangles) and `avm2_render_morph`'s own comment says "Gradient / stroke morph is
deferred (skipped)" — this morph is stroked, and the missing stroke tessellation
is very likely what covers (300,300). That makes B6 a **recompiler-side
(morph stroke geometry) item**, not a runtime hit-test item — re-scope it before
re-staffing. It also carries `[[image_comparisons]]`, so the bounds half will
move the pixel board when it does land.

## Files touched

| File | Item(s) |
|---|---|
| `ruffle-tests/verify_output.py` | B1 (malformed child `MovieEntry` shell) |
| `SWFModernRuntime/src/avm2/avm2_display.c` | B1 (`loader_resolve_url` sniff) |
| `SWFModernRuntime/src/avm2/avm2_e4x.c` | B3a |
| `SWFModernRuntime/src/avm2/avm2_ops.c` | B3b |
| `SWFModernRuntime/src/avm2/avm2_globals.c` | B3c |
| `SWFModernRuntime/src/actionmodern/action.c` | B4 (two queues) |
| `SWFModernRuntime/src/avm2/avm2_events.c` | B5 |

No recompiler (`SWFRecomp/`) source was modified — so no `categories=full`
obligation from this patch, and no manual cmake step for whoever merges.

## Canaries (all green, all re-run in-worktree with `--recompile`)

**Mandatory (B1):** `avm1/movieclip_state_values` — **pass**.

**B4 / load-lifecycle (avm1, 16):** `load_cancel_via_unloadclip`
(ruffle_matched → ruffle_matched, unchanged), `load_cancel_via_unloadmovie`
(ruffle_matched → ruffle_matched, unchanged), `loadmovie`, `loadmovie_fail`,
`loadmovie_flashvars`, `loadmovie_method`, `loadmovie_registerclass`,
`loadmovie_replace_root`, `loadmovie_var_persistence`, `loadmovienum`,
`mcl_getprogress`, `mcl_loadclip`, `mcl_loadclip_properties`,
`mcl_mislabeled_target`, `mcl_target_png`, `mcl_unloadclip` — all **pass**
(all were pass).

**B1 / loader + B3b/B3c/B3a (avm2, 13):** `loader_events`,
`loader_unknown_content`, `loader_bytes_unknown_content`,
`loader_loadbytes_events`, `loaderinfo_events`, `loader_reuse`,
`loader_method`, `loader_image`, `loaderinfo_properties`, `super_get_call`,
`supercalls_weird`, `system_setclipboard_null`, `xml_abstract_equality`
— all **pass**.

**B3a (from_avmplus/e4x, 2):** `XML/e13_4_1`, `XML/bug157597` — **pass**.

**`regression` suite (6):** `avm2_loader_stub`, `xml_onload_type1_args`,
`onload_type1_args`, `avm2_tolerant_verify_quarantine`, `avm2_morph`,
`avm2_embed_bytearray` — all **pass**.

**B5:** `avm2/cross_api_version_call_older` — **pass**.

## Merge risks

1. **`verify_output.py` is shared harness code.** The B1 arm only fires when
   `recompile_child_swf` FAILS and the parent is AVM2 — a build that previously
   linked no child entry now links one. Corpus-wide this is only the two
   `bug1157243` tests (they are the only AVM2 parents in the corpus with an
   unrecompilable sibling `.swf`), but a sibling agent editing the same child
   loop will textually conflict; the hunk is a self-contained `elif` at the end
   of the loop.
2. **`loader_resolve_url` discriminator is `frame_funcs == NULL`.** If any other
   patch starts emitting `MovieEntry`s without frame funcs for a REAL SWF, those
   loads become #2124. Nothing in-tree does today.
3. **B5 removes four `Event` constants below SWF 17.** Any future test at
   SWF ≤ 16 that reads `Event.VIDEO_FRAME` etc. now sees `undefined` — which is
   Flash's behaviour, but it is a behaviour change beyond the one graded line.
4. **B4 drops queue entries.** Both drains now discard loads whose target went
   away; a patch that relies on a pending load surviving `removeMovieClip`
   (e.g. re-targeting a queued load) would conflict semantically. The 16
   MCL/loadMovie canaries cover the family.
5. **B3c pops the top call frame.** Guarded on `method.fn == system_exit`, so a
   future change to how native statics push frames degrades to "no pop" (an
   extra `System/exit()` line), never to a corrupt stack.
6. `avm2_display.c` was touched in ONE place (`loader_resolve_url`); the B6
   experiment in the same file was fully reverted and re-verified (both
   `bug1157243` tests re-run green after the revert).
