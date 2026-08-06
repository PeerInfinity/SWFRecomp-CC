# w2-rider-pixel — session 13, wave 2 (pixel axis)

**Agent:** wave-2 rider, GRAPHICS / pixel axis.
**Board:** `SWFRecompDocs/plans/session13-fanout-reports/wave1-board-audit.md`,
leads **L3** (`avm2/error_stack_trace_release_swf17`) and
**L4** (`visual/drawing_api/cursor`).
**Base:** `10931d62e` (master), isolated worktree
`.claude/worktrees/agent-aacc614c6d270b658`. **Nothing was committed.**
**Deliverable:** `w2-rider-pixel.patch` (full `git diff`) + this report.

---

## 0. TL;DR

Both leads are **fixed**, and each local render is now **byte-identical to its
expected PNG** (`max channel diff 0`, `differing channels 0`, both at
`tolerance = 0`). Estimated CI movement: **+2 image comparisons, 0 trace flips.**

| lead | before | after | vs expected |
|---|---|---|---|
| L3 `avm2/error_stack_trace_release_swf17 [output]` | 10×10 stage 100 px **pure blue** `(0,0,255)` | 100 px **pure red** `(255,0,0)` | **0 differing channels** |
| L4 `visual/drawing_api/cursor [output]` | green vertical only (100 px, x=99, y=100–199); red diagonal **absent** | red diagonal `(255,0,0)` (0,0)→(99,99) **+** green vertical unchanged | **0 differing channels** |

**Neither lead's board hypothesis was the mechanism.** L4 in particular is
*not* a rasterizer / hairline / minimum-stroke-width problem — the diagonal
never reached the tessellator at all. `render_webgpu.c` was **not touched**, so
the `MSAA_SAMPLES` invariant is trivially preserved.

**No sibling collision.** `Error.getStackTrace` lives in
`SWFModernRuntime/src/avm2/avm2_error.c`, **not** `avm2_globals.c` — the
flagged describeType collision **does not exist**. Details and the exact hunk
locations in §4.

Files touched (3):

| file | lead | hunks |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_error.c` | L3 | 1 (new static helper + 4-line early return) |
| `ruffle-tests/verify_output.py` | L3 | 3 (one new parser, one define at each of the two build sites) |
| `SWFModernRuntime/src/actionmodern/action.c` | L4 | 7 (2 new statics + 4 call sites + 2 `lineStyle` bodies) |

---

## 1. L3 — `Error.getStackTrace()` in a release player

### 1.1 The rule, from Ruffle (not guessed, and not per-test)

`~/CC/ruffle/core/src/avm2/globals/error.rs::get_stack_trace`:

```rust
let stack_trace_enabled = if activation.context.player_version >= 18
    && activation.caller_movie_or_root().version() >= 18
{
    true                                              // FP 11.5+ and SWF>=18
} else {
    activation.context.player_mode == PlayerMode::Debug
};
if !stack_trace_enabled { return Ok(Value::Null); }
```

Two facts collapse this to a one-term gate for us:

* `DEFAULT_PLAYER_VERSION = 32` (`core/src/lib.rs:77`), and **no test in the
  corpus sets `player_options.version`** — so `player_version >= 18` is always
  true. We likewise always emulate a modern player.
* Therefore: **`enabled = (caller SWF version >= 18) || (player is the
  debugger)`**.

`PlayerMode` is the flashplayer / flashplayerdebugger split — a *player* knob,
**not an SWF header flag**. The important subtlety: Ruffle's **test framework**
defaults it to `Debug`
(`tests/framework/src/options/player.rs:42`,
`.with_player_mode(self.mode.unwrap_or(PlayerMode::Debug))`), which **inverts**
`ruffle_core`'s own `PlayerMode::default()` (= `Release`). So under the test
harness, Debug is the default and `[player_options] mode = "Release"` is the
opt-out.

### 1.2 Truth table over the whole family (all six verified locally)

`mode =` appears in exactly **4** `test.toml` files in the entire corpus
(`grep -rn --include=test.toml -E '^\s*mode\s*='`), all four in this family.
SWF versions read from byte 3 of each `test.swf`.

| test | `mode` | SWF | Ruffle enabled? | expected |
|---|---|---:|---|---|
| `error_stack_trace` | *(default Debug)* | 43 | yes (both terms) | 45 trace lines |
| `error_stack_trace_edge_cases` | *(default Debug)* | 20 | yes (both terms) | 6 trace lines |
| `error_stack_trace_debug_swf17` | Debug | 17 | yes (debug term) | blue |
| `error_stack_trace_debug_swf18` | Debug | 18 | yes (SWF term) | blue |
| **`error_stack_trace_release_swf17`** | **Release** | **17** | **NO — both terms fail** | **RED** |
| `error_stack_trace_release_swf18` | Release | 18 | yes (SWF term) | blue |

`release_swf17` is the **single** combination in which the trace must be
`null`. We returned a trace unconditionally, so the `else` branch of `Test.as`
ran and painted `0x0000FF`.

### 1.3 Implementation

**`SWFModernRuntime/src/avm2/avm2_error.c`** — one `#ifdef` pair, one new
static, one early return inside `error_get_stack_trace`:

```c
#ifdef SWF_PLAYER_MODE_RELEASE
#define AVM2_PLAYER_IS_DEBUG 0
#else
#define AVM2_PLAYER_IS_DEBUG 1
#endif

static uint8_t error_caller_swf_version(Avm2Activation* act); /* see patch */

static Avm2Value error_get_stack_trace(Avm2Activation* act)
{
    Avm2Context* ctx = act->ctx;
    if (!AVM2_PLAYER_IS_DEBUG && error_caller_swf_version(act) < 18)
    {
        return avm2_null();
    }
    ...unchanged...
```

`error_caller_swf_version` is the same walk as `avm2_xml.c`'s
`xml_caller_swf_version` — Ruffle's `caller_movie_or_root().version()`, i.e.
the SWF version of the movie whose code called the native, **not** the root's.
A native builtin's own `act->file` is `NULL`, so it walks down the debug
callstack to the nearest frame that has an ABC file and resolves that ABC to
its movie via `avm2_display_movie_for_abc` (already declared in
`avm2_globals.h`); no such frame falls back to `ctx->swf_version`. This matters
for a v17 AVM2 child loaded by a v20+ root, which the global
`ctx->swf_version` would get wrong.

**`ruffle-tests/verify_output.py`** — new `get_player_mode_is_release()`,
modelled exactly on the existing `get_runtime_is_air()`, plus
`-DSWF_PLAYER_MODE_RELEASE=1` appended at **both** build sites
(`compile_native`, which serves no-graphics *and* graphics, and
`compile_wasm`). Unit-checked against all six family members: `True` for
exactly the two `release_*` tests, `False` for the other four.

### 1.4 Structural evidence (local Dawn, `--mode=graphics`)

`error_stack_trace_release_swf17`, 10×10 stage:

```
before   colours: {(0,0,255): 100}          # pure blue  — the `else` branch
after    colours: {(255,0,0): 100}          # pure red   — the `st === null` branch
expected colours: {(255,0,0): 100}
max channel diff 0 · differing channels 0   (test.toml tolerance = 0)
```

Trace side: `Pass: 1 (100.0%)` (0 expected lines, unchanged).

### 1.5 Blast radius — provably nil outside two tests

The gate is `#ifdef`-guarded. For **every** test whose `test.toml` lacks
`mode = "Release"` the macro is undefined, `AVM2_PLAYER_IS_DEBUG` expands to
`1`, and the new branch compiles as `if (0 && …)` — literally dead code, no
behavioural surface at all. Only `error_stack_trace_release_swf17` and
`error_stack_trace_release_swf18` receive the define anywhere in the corpus.
Of those two, `release_swf18` is SWF 18, so the new gate is *exercised* and
must **not** fire — that is the one canary that carries real information for
this lead (§3).

I deliberately did **not** implement Ruffle's *other* `PlayerMode` consumer
(`core/src/avm2.rs:696`: the release player does not `avm_trace` uncaught
errors). Both Release-mode tests expect zero trace lines and already pass on
the trace axis, so it would be unobservable change. Noted as a follow-up in §5.

---

## 2. L4 — `visual/drawing_api/cursor`: the diagonal never reached the tessellator

### 2.1 What the test actually does

The test has no `Test.as` (it is a `.fla`, SWF v15, AVM1). Decompiling the
single 195-byte `DoAction` tag gives, in full:

```actionscript
var mc = this.createEmptyMovieClip("mc", 0);
mc.lineStyle(1, 0xFF0000);
mc.lineTo(100, 100);
mc.lineStyle(1, 0x00FF00);
mc.lineTo(100, 200);
```

**There is no `moveTo` anywhere** — that is the whole point of the test, and
the reason it is named `cursor`. It asserts two separate Flash behaviours:

1. the drawing cursor starts at the clip's **origin**, so the first `lineTo`
   draws a segment from `(0,0)`;
2. `lineStyle` **ends** the current stroke and starts a new one at the cursor,
   so the two segments carry *different* colours.

The board's framing ("a hairline `lineStyle(0, …)` stroke … culled or
degenerating to zero coverage", "minimum-width handling") is off on both
counts: the strokes are `lineStyle(1, …)`, not hairlines, and nothing is
culled at raster time.

### 2.2 Two independent defects, both in the AVM1 command recorder

Neither is in `render_webgpu.c`, the stroke builder, or the tessellator.

**(a) `DrawingState.pen_set` starts at 0 — the cursor was "unset", not "origin".**
`lineTo` recorded a `LINE_TO` with no preceding `MOVE_TO`. `drawingFinalizePath`
then hits its fallback (`action.c`: *"LINE_TO: extend current contour (or start
one if first cmd is a LINE)"*) and opens the contour **at the `LINE_TO`'s
endpoint**. The segment `(0,0) → (100,100)` was therefore never in the polyline
that reaches `drawingBuildStroke`. Ruffle models the cursor as
`Drawing::cursor: Point::ZERO` (`core/src/drawing.rs`) and seeds every path it
opens with `MoveTo(self.cursor)`.

**(b) `lineStyle` only overwrote the style; it never closed the path.**
`ds->line_{w,r,g,b,a}` were mutated in place, so every segment recorded since
the last path boundary was finalized with the **last** style. Ruffle's
`Drawing::set_line_style` pushes `current_line` into `paths` and re-opens a
fresh `DrawingLine` seeded with `MoveTo(cursor)`.

Composed, the two defects produce exactly one path with exactly two vertices —
`(100,100) → (100,200)`, green — which is *precisely* the observed render. The
red diagonal was not mis-rasterized; it did not exist.

### 2.3 The fix

Two new statics in `action.c` next to the existing `drawingBeginNewFill`, wired
into **both** AVM1 drawing dispatch sites (the `actionCallMethod` handler and
the `with (mc) { … }` bare-name handler in `actionCallFunction`):

* `drawingEnsurePen(ds)` — if the pen is unset, set it to `(0,0)` and emit a
  `MOVE_TO` origin. Called from `lineTo` and `curveTo` at both sites.
* `drawingBeginNewLineStyle(ds, …)` — finalize the accumulated path with the
  **old** style, then re-seed a `MOVE_TO` at the cursor. Called from
  `lineStyle` at both sites, which is why both `lineStyle` bodies were
  restructured to resolve the new style into locals *before* mutating `ds`.

Two deliberate narrowings relative to Ruffle, both documented in the code:

1. **The split is skipped while a fill is open.** Ruffle defers the stroke into
   `pending_lines` and leaves the fill's command list unbroken; our `DrawPath`
   carries one fill *and* one line style, so splitting there would cut the fill
   polygon in half. Nothing in the corpus needs deferred strokes today.
2. **The split is skipped when the style is unchanged.** Ruffle splits
   unconditionally. Merging identical-style neighbours is rasterization-neutral
   and keeps a `lineStyle`-per-segment drawing under the **64-`DrawPath`-per-MC
   cap** in `actionIterateDrawings` (`DrawingRenderInfo infos[64]`), which
   `fillDrawingInfos` truncates **silently** — an unnecessary split there could
   *drop* geometry. This is the main merge risk the change had, and it is
   closed by construction.

### 2.4 Structural evidence (local Dawn, `--mode=graphics`, `quality = "low"` ⇒ `MSAA_SAMPLES == 1`)

Non-white pixels of the 550×400 stage:

```
before    (0,255,0) ×100  x=99, y=100..199          # green vertical only
          (255,0,0) ×0                              # red diagonal ABSENT

after     (255,0,0) ×100  (0,0),(1,1)…(98,98),(99,99)
          (0,255,0) ×100  x=99, y=100..199

expected  (255,0,0) ×100  (0,0),(1,1)…(98,98),(99,99)
          (0,255,0) ×100  x=99, y=100..199

max channel diff 0 · differing channels 0            (test.toml tolerance = 0)
```

The green vertical is **bit-for-bit unmoved** by the change — the fix adds the
missing path without perturbing the one that already rendered.

### 2.5 Independent corroboration: AVM2 already does this

`SWFModernRuntime/src/avm2/avm2_display.c` — the AVM2 `flash.display.Graphics`
implementation — **already has both behaviours**:

```c
static Avm2Value gfx_line_to(...)   { ... if (!g->pen_set) gfx_add_cmd(g, 0, 0, 0, 0, 0); ... }
static Avm2Value gfx_line_style(...) { ... gfx_finalize_path(g); ... }
```

So this change brings the AVM1 drawing API to parity with the AVM2 one that is
already in the tree and already shipping. `avm2_display.c` was **not** edited.

---

## 3. Canary ledger

Local Dawn is byte-deterministic; per the playbook, no local render is graded
against a repo golden. The two target verdicts above are reported as
*structural* facts (the red hairline exists; the stage is red not blue) that
happen to also be exact.

### 3.1 Static gates (no run needed — argued, not assumed)

| gate | status | why |
|---|---|---|
| L3 blast radius outside the 2 `release_*` tests | **CLOSED** | `#ifdef SWF_PLAYER_MODE_RELEASE` is undefined for every other test in the corpus; the branch is `if (0 && …)`. Verified by `grep -rn --include=test.toml -E '^\s*mode\s*='` returning exactly 4 files. |
| `avm2/error_stack_trace` (45/45/38, stated hard canary) | **CLOSED** | no `[player_options]`; SWF 43. Macro undefined ⇒ dead branch. Even if it *were* defined, SWF 43 ≥ 18 short-circuits. |
| `avm2/error_stack_trace_edge_cases` | **CLOSED** | same; SWF 20. |
| `avm2/error_stack_trace_debug_swf1{7,8}` | **CLOSED** | `mode = "Debug"` ⇒ macro undefined ⇒ dead branch. |
| `render_webgpu.c` / `MSAA_SAMPLES` invariant | **CLOSED** | file not touched. |
| AVM2 drawing / `avm2_display.c` | **CLOSED** | file not touched (and already correct — §2.5). |
| non-drawing-API renders (`DefineShape`, text, filters, blend, masks-of-static-shapes) | **CLOSED** | the change is confined to the AVM1 drawing-API *command recorder*; it is unreachable except through `mc.{lineTo,curveTo,lineStyle}` dispatch. |

### 3.2 L3 runs — the informative one is `release_swf18`

`error_stack_trace_release_swf18` is the **only** canary that carries real
information for L3: it *does* receive `-DSWF_PLAYER_MODE_RELEASE`, so the new
branch is live, and the `caller SWF >= 18` term must short-circuit it. If the
rule had been implemented as a per-test hack (or with the SWF term wrong), this
is where it would break.

| test | trace | render vs expected | verdict |
|---|---|---|---|
| `error_stack_trace_release_swf17` **(target)** | `Pass: 1 (100.0%)` | `{(255,0,0): 100}` vs `{(255,0,0): 100}` — **0 differing channels** | **FIXED** (was pure blue) |
| `error_stack_trace_release_swf18` **(gate exercised)** | `Pass: 1 (100.0%)` | `{(0,0,255): 100}` vs `{(0,0,255): 100}` — **0 differing channels** | **unmoved** ✓ |
| `error_stack_trace` (stated hard canary, 45/45/38) | `Fail: 1` — **7 mismatched lines, 38/45 matching** | n/a (no image comparison) | **exactly at baseline** ✓ (see note) |

**Note on `error_stack_trace`.** The task brief called it a "hard canary that
must stay passing", but it **was already failing at HEAD** — the wave-1 audit
records it as `45/45/38`, and its own §L3 states the real bar: *"must not get
worse"*. It is unchanged: 45 expected, 45 actual, **7 mismatched lines ⇒ 38
matching**, identical to the audited baseline. All 7 are frame-**naming**
residue from the s12 stack-frame formatting work — `at Test$cinit()` vs
`at Test/<anonymous>()`, `at MethodInfo-1()` vs `at Function/<anonymous>()`,
`at Test$/class_method()` vs `at Test/class_method()` — and are orthogonal to a
debug/release gate. The decisive observation is that the trace is **still
produced in full** (45 actual lines): had the gate misfired here it would have
returned `null` and the output would be empty.

### 3.3 L4 runs — render canary A/B (md5, local Dawn, `--mode=graphics`)

Before leg captured at HEAD with the edits reverted (verified directly: the
before leg's copied `_build/action.c` contains **zero** occurrences of
`drawingEnsurePen`). *Caveat for the reader:* `manifest.json`'s `dirty_files`
lists the three edited files, but that field is sampled when the manifest is
written, which was after I had restored the working tree — it does not describe
the leg's sources.

```
RENDER CANARY  before=before  after=after   5 tests / 5 comparisons

  IDENTICAL     5
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

| test | why it is in the set | md5 before → after | verdict |
|---|---|---|---|
| `avm1/mask_with_drawing` | tier-1, CI-**passing**, AVM1 drawing API + mask | `c19e92c7…` → `c19e92c7…` | **IDENTICAL** |
| `avm1/color` | tier-1, CI-passing, solid fill + colour transform | `44a2ebac…` → `44a2ebac…` | **IDENTICAL** |
| `visual/drawing_api/drawing_order` | drawing-API sibling | `bdecd34c…` → `bdecd34c…` | **IDENTICAL** |
| `visual/drawing_api/fills_and_lines` | drawing-API sibling — `lineStyle` **with an open fill**, the guarded case | `88014227…` → `88014227…` | **IDENTICAL** |
| `visual/drawing_api/gradient_focal_point` | drawing-API sibling — gradient fill | `069c587e…` → `069c587e…` | **IDENTICAL** |
| `visual/drawing_api/cursor` **(target)** | the fix | (before) green-only → (after) matches expected | **DIFFERS — intended, and now exact** |

So the **entire `visual/drawing_api` family is md5-identical except `cursor`**,
which is the sibling gate the brief asked for, and the two CI-passing tier-1
AVM1 canaries are unmoved.

**Why the set is scoped this way.** The change is confined to the AVM1
drawing-API *command recorder*; it is unreachable except through
`mc.{lineTo,curveTo,lineStyle}` dispatch. Members of the standing canary list
that render `DefineShape` geometry, text, filters, blend modes or AVM2 drawing
(`visual/simple_shapes/*`, `from_shumway/*`, `regression/avm2_*`,
`visual/filters/*`, `visual/blend_modes/*`, `visual/cache_as_bitmap/*`) cannot
reach it at all, and each costs ~90–220 s to build on a machine currently
shared with ~8 agents at load ~25. I substituted the *whole* `drawing_api`
family — which the standing list does **not** contain — for those inert
members, which is strictly more informative for this change.

Predictions were made **before** the runs and all held:
`fills_and_lines` (every `lineStyle` either precedes any command or has a fill
open), `gradient_focal_point` (has an explicit `moveTo`), and `drawing_order`
(its root-level *bare-name* `lineStyle`/`lineTo` never reach the drawing
dispatch — that requires a `with`-scope MC, `action.c:59084-59088` — so its
missing root diagonal is a separate, pre-existing gap I did not touch).

---

## 4. Sibling-collision assessment

| sibling (per the task brief) | file | collides? |
|---|---|---|
| describeType P0–P2 | `avm2_globals.c` | **NO.** `Error.getStackTrace` is registered and implemented in `avm2_error.c` (`avm2_builtin_add_method(ctx, cls, "getStackTrace", error_get_stack_trace)` at ~line 1467, body at ~line 590). `avm2_globals.c` was **not opened**. The brief's flagged collision does not exist. |
| s12 stack-trace **frame formatting** | `avm2_error.c` | **Adjacent, not overlapping.** My hunk is a 4-line early return at the *top* of `error_get_stack_trace` plus a new static above it. The frame-formatting body (the `toString()` call and the `__stacktrace_tail` concat) is untouched, and the `avm2_error_stack_string` uncaught-error path is untouched. `error_stack_trace` stays a valid canary and is statically unaffected (§3.1). |
| setMask / video / action-order | `tag.c`, `action.c` | **`action.c` is shared.** My hunks are in the **drawing-API** region only: two new statics at ~`28400` (beside `drawingBeginNewFill`), and call sites at ~`59122` / `59144` / `59159` (the `with`-scope dispatch) and ~`70303` / `70328` / `70476` (the `actionCallMethod` dispatch). The action-order sibling works the frame-action queue / display-list walk — no overlap, but expect `action.c` to need a merge if both land. |
| video + `tag_init` | `swf.cpp` | **NO** — not touched. |
| mask defect C | `avm2_render_node` | **NO** — not touched. |
| — | `ruffle-tests/verify_output.py` | Low risk: one new function appended after `get_runtime_is_air`, and one two-line insert immediately after each of the two existing `SWF_RUNTIME_AIR` appends. Textual conflict only if a sibling edits the same two `extra_defines` blocks. |

---

## 5. Expected CI movement, and follow-ups

**Expected:** `+2 image comparisons` (286/567 → **288/567**, 50.4% → 50.8%),
**0 trace flips**, 0 regressions. Both targets are `tolerance = 0` and both now
match their expected PNG exactly on local Dawn; `release_swf17` is a flat-colour
10×10 and `cursor` is a hard-edged, unantialiased 1-sample render, so neither
is at risk from the local-Dawn-vs-CI-lavapipe gap.

Dispatch note: this touches AVM2 runtime code (`avm2_error.c`), so per CLAUDE.md
the run should be `mode=graphics categories=full`; `images=true` is required for
the two target comparisons to be *observed*, but per the standing policy that is
a deliberate baseline run, not the per-change default — the trace axis of this
change is provably inert either way.

**Follow-ups, not done here:**

1. **Deferred strokes with an open fill.** Ruffle's `pending_lines` path
   (`set_line_style` while `current_fill.is_some()`) is still unmodelled — a
   `beginFill; lineStyle(a); …; lineStyle(b); …; endFill` renders the whole
   stroke in style `b`. No comparison in the corpus needs it today; modelling it
   requires `DrawPath` to carry a list of strokes rather than one.
2. **`PlayerMode` and uncaught-error tracing** (`ruffle core/src/avm2.rs:696`):
   the release player does not `avm_trace` uncaught errors. Unobservable in the
   corpus today (both Release tests expect zero lines); the
   `SWF_PLAYER_MODE_RELEASE` define is now in place should a test ever need it.
3. The **64-`DrawPath`-per-MC silent truncation** in `actionIterateDrawings`
   (`DrawingRenderInfo infos[64]`, `fillDrawingInfos` drops the overflow with no
   diagnostic) is a real latent cliff for drawing-heavy content. Worked around
   here; worth a bounded-growth fix or at least a debug assert.
