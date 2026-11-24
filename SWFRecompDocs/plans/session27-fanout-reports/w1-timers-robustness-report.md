# s27 w1-timers-robustness: timer goto-skipped DoInitAction + robustness tail

**Slot:** `w1-timers-robustness` (wave 1, diagnosis + measured prototype). Branch `fanout/w1-timers-robustness`.
**Base:** `origin/master` `52b46d94c`. Baseline results `df7729df2` (the wave-0 run had not published when I started).
**Box:** cloud, `SETUP_STATUS` all OK. Corpus: `download_tests.sh from_gnash avm1` (+ `from_shumway timeline swf
import_assets mixed_avm text visual` for scans), upstream Ruffle master at 2026-11-24 ~01:10 UTC (the script prints no
SHA; my blobless Ruffle clone taken at the same time is at `1e604fa87`). Ruffle source read at `1e604fa87`.

## NEW FILES

- `SWFRecompDocs/plans/session27-fanout-reports/w1-timers-robustness-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w1-timers-robustness-prototype.patch`
  (`git diff origin/master -- SWFRecomp SWFModernRuntime`, 931 lines; source reverted in my commit)
- `SWFRecompDocs/plans/session27-fanout-reports/w1-timers-robustness-fixtures/` — fixture generators
  (`python3 <gen>.py out.swf [mode]`, run from that folder; they import the s26 `avm1asm.py` copy next to them) and
  `avm1dis.py` (a small AVM1 tag/bytecode disassembler, `python3 avm1dis.py test.swf`):
  `goto_skipped_init.py` (`script` | `timer`), `timer_method_form.py`, `timer_native_method.py` (`<method> [args]`),
  `timer_root_goto_stopped.py` (`nf` | `gs`), `caps_overflow.py` (`clone` | `timers` | `watch`),
  `func2_register_oob_read.py` (`<swf version>`).

## VERDICTS (priced)

| # | Item | Verdict | Trace flips (measured, graphics) |
|---|---|---|---|
| 1 | Goto-skipped DoInitAction | **GO (prototype).** Premise "timer path vs frame-script path" **REFUTED**: the frame-script goto skips them too. Owner is the recompiler gate. Two more Flash rules ride along (§1). | **`from_gnash/misc-ming.all/init_action/InitActionTest2` ruffle_matched → PASS.** `gotoFrameFromInterval` case 2 now `PASSED: x0xx1x234` (Flash), row stays ruffle_matched (case 1 is the exec-order NO-GO). `movieclip_destruction_test1` +3 Flash lines (still ruffle_matched). `action_execution_order_test12` line 19 changes value, still wrong, still ruffle_matched. |
| 2a | Method-form `num_args>=3` | **REFUTED as a gap.** With 2 args Ruffle also returns undefined (interval = `args[2]` = undefined). The real method-form gaps are different and confirmed: an **Array receiver** takes the function arm (returns undefined), and **native methods are never called** (`setInterval(mc, "play"/"nextFrame", ms)` silently does nothing). | 0 corpus rows (fixture) |
| 2b | `clearInterval` coercion | **GO (XS).** `(int)double` → ToInt32: `clearInterval(id + 2^32)` now clears `id` (Ruffle `coerce_to_i32`). | 0 (fixture) |
| 3 | func2 register reads ≥ RegisterCount | **REFUTED / NO-GO, price 0.** Ours already = Ruffle at its default `player_version` 32 (> 10) = Flash 11+: reads/writes fall back to the global register file. "undefined" is Ruffle's FP ≤ 10 branch only; we have no player-version concept, and only hand-made bytecode reaches it. | 0 |
| 4 | Fixed caps | **GO** for `TIMERS`, `WATCH`, `CLONE_DEPTH` (game-reachable, silent wrong behaviour, measured before/after). **NO-GO (not game-data-reachable)** for `PROTO_STUB_FUNCS` (builtin-only, measured high-water 123–126 / 192), `LAZY_PROTOS`, `EI_CALLBACKS`. `SCROLL_CROPS` / `TEXT_CULLED`: per-frame render tables, HOLD for a pixel fixture (§4). | 0 corpus rows; 3 fixtures |
| 5 | Dead `tagSetFilter*` | **Partly REFUTED.** `tagSetFilter` and `tagSetFilterHighlight` are live (recompiler `swf.cpp:5390,5409,6891,6909`). **Dead:** `tagSetFilterColorMatrix/Convolution/Gradient`, `getOrCreateExtFilter`, the ext table, and the only reader's branch in `actionGetMemberImpl` (always NULL). Removed in the prototype (−~150 lines), 0 movers. | 0 |

**Ledger for the prototype (argued sweep, §6): 4 rows change bytes, 1 status flip (`InitActionTest2` → pass), 0
regressions.** Every other swept row is byte-identical before/after.

## 1. Goto-skipped DoInitAction (item 1)

### 1a. Premise attack

- **"Owner is the goto catch-up path when called from `processTimers` vs from a frame script" — REFUTED.** Measured with
  `goto_skipped_init.py` (frame 1 → `_root.gotoAndPlay(3)`, frames 2 and 3 each carry a DoInitAction). Clean master,
  graphics, both arms identical: `init2` never runs, from a frame script **and** from a timer.
  ```
  script: f1 / f1 after f3 / init3 f3 / f3          timer: f1 / cb / cb after f3 / init3 f3 / f3
  ```
  Owner: the recompiler emits every root-frame init call as
  `if (!catch_up_mode || g_tag_skip_mode) tagDoInitActionGuarded(...)` (`SWFRecomp/src/swf.cpp`, DoInitAction case,
  ~line 4137), and every forward-goto catch-up runs the skipped frames with `catch_up_mode = 1, g_tag_skip_mode = 0`
  (`swf.c` `ng_executeGotoCatchUp` / `ng_executeGotoTagsOnly` / main-loop retry loop, and the `swf_core.c` twins).
- **Ruffle is not an oracle here.** Ruffle runs every DoInitAction at **preload** (`movie_clip.rs` preload
  `TagCode::DoInitAction => self.do_init_action`), i.e. before frame 1, in tag order. That is why
  `gotoFrameFromInterval`'s `output.ruffle.txt` never clears its intervals and why the row is `known_failure`. A Ruffle
  runner golden for a goto-skipped init fixture would encode Ruffle's preload, not Flash. The Flash evidence is the gnash
  rows themselves (below).
- **s26 Lead 2 ("a timer goto is deferred, the playhead never reaches 10") does not reproduce on graphics master**: the
  timer probe lands immediately (`cb after f3`). On graphics the missing frame-10 line of `gotoFrameFromInterval` was
  entirely the endless intervals (init actions never ran → never cleared). See §1e for the no-graphics difference.

### 1b. Flash rules the gnash corpus pins (scan: every SWF in `avm1 from_gnash regression from_shumway timeline swf
import_assets mixed_avm text visual` with a root DoInitAction on frame ≥ 2 — only 12 gnash SWFs)

1. **A forward goto runs the DoInitActions of the frames it skips.** `InitActionTest2` (frame 8 `GotoFrame 9`+`Play`
   over frame 9's init → Flash traces `mc6`, `val6 == 'mc6'`), `movieclip_destruction_test1` (`initaction mc3 in root
   frame4`, goto from `mc1`'s frame 2), `gotoFrameFromInterval` (`234`).
2. **They run after the script that issued the goto, before the target frame's scripts** — and in a timer pass, after
   the timers due at the same instant (`gotoFrameFromInterval`: `x0xx1x` then `234`; with them run synchronously our
   output was `x0123x`). Not fully pinned: `action_execution_order_test12` expects `0+1+2+3+4+` where `3+` is the
   init and `1+ 2+ 4+` are the issuing script (`2+` inside a function it calls). Neither "synchronous in the goto"
   (`0+3+1+2+4+`) nor "after the issuing script" (`0+1+2+4+3+`) gives it; Flash apparently flushes pending init
   actions at a function-call return inside the issuing script. Both models fail that one line; the timer row
   contradicts a "flush at every call return" model (`x0x` would result), so I kept "after the issuing script".
3. **A DoInitAction whose sprite is not yet defined is ignored** (until the playhead has passed the DefineSprite).
   `InitActionTest2`: frame-1 init for sprite 4 (DefineSprite 4 follows it) never runs (`val4` stays undefined until
   frame 6's init sets `mc4a`); bogus id 25 never runs; frame-11 inits for sprites 7/8 (defined in frame 12) are
   skipped on the first pass (`init7 == undefined` at frame 14) and **run when a backward goto revisits frame 11**
   (`Going back` → `init7`, `init8`). Scan: `InitActionTest2` is the only corpus SWF with an init before its def.
4. (Not prototyped — lead 1) **Same-frame init actions run after the frame's placements**: `movieclip_destruction_test1`
   frame 12's init for sprite 8 checks `mc6` (placed earlier in the frame) and `mc7` (placed after the init tag) and
   Flash sees both. We hoist the init prologue to the top of the frame body ("mirrors Ruffle's preload"), before
   placements → 8 remaining lines of that row.

### 1c. Prototype (in `w1-timers-robustness-prototype.patch`)

- **Recompiler** `SWFRecomp/src/swf.cpp` (DoInitAction case of `SWF::interpretTag`; DefineSprite case; `SWF::parseAllTags`
  tail): emit `tagDoInitActionFrame(app_context, CHARID(n), script_k);` with no gate; if the sprite is not yet in
  `defined_chars`, emit `tagDoInitActionFrameLate(..., SWFRECOMP_INITDEF_<n>)` and `#define` that in `out.h` as the
  0-based root frame of the sprite's DefineSprite (`((size_t)-1)` if never defined). Two file-static tables
  (`s27_sprite_def_frame`, `s27_late_init_ids`). Sprite-internal init emission (`swf.cpp:~7146`) untouched.
- **`tag.c`**: new `tagDoInitActionFrame` (old gate moved here; while a root goto catch-up is capturing, an init not yet
  done is queued instead of dropped), `tagDoInitActionFrameLate` (runs only once `g_s27_root_frames_shown > def_frame`),
  `tagDrainGotoInitActions` (end of goto: one `AQ_KIND_SCRIPT` / `AQ_PRIORITY_INITIALIZE` queue entry so it runs after
  the issuing script and before the target frame's DoAction; `force=1`: run now under the root context with SetTarget
  state saved/cleared like `aq_dispatch_sprite_script` — without that the init ran in the removed `mc1` context in
  `movieclip_destruction_test1` and its `_root.Dejagnu.check_equals` calls vanished), `tagGotoInitCapture`,
  `tagGotoInitTimerPass`; **`tagShowFrame`**: one block at the top records the highest root frame shown
  (`g_s27_root_frames_shown`, movie 0 only). `tagDoInitActionGuarded` unchanged (once-per-(movie,id) bitmap still the
  dedupe; the queue also dedupes).
- **`swf.c` / `swf_core.c`**: `ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`, and the main-loop goto retry loop in
  `swfStart` (both files): `tagGotoInitCapture(1/0)` around the catch-up frames, `tagDrainGotoInitActions(app, 0)` after
  them (before the main loop runs the target frame).
- **`timer.c`** `processTimers`: `tagGotoInitTimerPass(1/0)`; before firing a timer whose due time differs from the
  current batch's, drain pending init actions (`force=1`) and re-pick; drain at the end of the pass. A no-op unless a
  callback goto queued init actions.

### 1d. Per-test before → after (graphics, `--recompile`)

| Row | Before (`origin/master`) | After |
|---|---|---|
| `misc-ming.all/init_action/InitActionTest2` | ruffle_matched (11 failed checks) | **PASS** (21/21) |
| `misc-swfc.all/gotoFrameFromInterval` | ruffle_matched; case 2 never prints (endless intervals) | ruffle_matched; `PASSED: _root.asOrder == x0xx1x234`, `Total tests run: 3`; only case 1 (exec-order: placed clips' frame-1 actions before the root's next DoAction — the action_order NO-GO; Ruffle fails it identically) remains |
| `misc-swfc.all/movieclip_destruction_test1` | ruffle_matched | ruffle_matched; +`initaction mc3 in root frame4` + its 2 PASSED checks (Flash lines 10–12); rule 4 owns the rest |
| `misc-swfc.all/action_execution_order_test12` (fp10) | ruffle_matched, `obtained: "0+1+2+4+"` | ruffle_matched, `obtained: "0+1+2+4+3+"` (same diff index) |
| the other 8 frame-≥2-init rows (`InitActionTest`, `registerClassTest2`, `action_execution_order_test10`, `registerclass_test3`, `tags_after_last_showframe`, `ActionOrderTest3/4/5`) + `gotoFrameFromInterval2` | — | byte-identical |

No-graphics: the 9 gnash init rows above are byte-identical to graphics except `gotoFrameFromInterval` (§1e).

### 1e. No-graphics divergence (pre-existing, not caused by the patch)

On `swf_core.c`, a root goto issued **from a timer callback** never runs the target frame's DoAction (`goto_skipped_init.py
timer`, clean master NG: `f1 / cb / cb after f3` — no `f3`; graphics prints `f3`). So NG `gotoFrameFromInterval` still
never reaches frame 10 after the patch (graphics does). Not a CI row change (graphics grades); lead 3.

## 2. Small timer gaps (item 2)

Ruffle `avm1/globals.rs create_timer`: `args[0]` a function → function form; **any other Object** → method form with
`method_name = args[1].coerce_to_string`, interval `args[2]` (undefined → return undefined), params `args[3..]`; fire =
`this.call_method(name, params)` (`timer.rs`), a full member lookup. `clear_interval`: `coerce_to_i32`.

`timer_method_form.py` (graphics; NG identical):

| Probe | Before | After (prototype) | Ruffle (source) |
|---|---|---|---|
| `setInterval(arr, "m", 10)` on an `Array` with an own `m` | `ia=undefined`, never fires | `ia=1`, `arr m len=7` | method form, fires |
| `setInterval(_root, "nextFrame", 10)` | id returned, nothing happens | same — see lead 2 | `nextFrame` called |
| `setInterval(_root, "play", 10)` (`timer_native_method.py play`) | nothing | `f2 cf=2` | `play` called |
| `clearInterval(id + 4294967296)` | not cleared (25 fires) | cleared | cleared (`coerce_to_i32`) |

Prototype (`timer.c`): `timerIsObject` + `ACTION_STACK_VALUE_ARRAY`; `fireTimerCallback` method arm — when the
dynamic-property lookup finds no function (native method, Array receiver), fall back to the CallMethod opcode path
(`pushVar` args last..first, count, object, `PUSH_STR` name, `actionCallMethod`, pop) instead of returning silently; the
existing typed paths (type-2 MC receiver convention, version switch) are untouched. `actionTimerClearInterval`:
`timerDelayToInt32` (ToInt32) on the id.

## 3. func2 register reads past RegisterCount (item 3)

Ruffle `activation.rs current_register`: local register if `id < local_registers.len()`; else **if locals are
non-empty and `player_version <= 10` → undefined**; else the 4 global registers. Writes mirror it
(`set_current_register`). Ruffle's test runner uses `DEFAULT_PLAYER_VERSION = 32` (`core/src/lib.rs`), so its corpus
behaviour is the global fallback. `func2_register_oob_read.py 8` (graphics = NG):
```
in f: r1=undefined          (RegisterCount 2: r1 is local)
in f: r3=G3                 (past count -> global r3, set at top level)
in f after store: r3=L3     (write past count -> global)
top: r3=L3
in g: r1=G1                 (RegisterCount 0 -> always global)
top: r1=L1
```
That is exactly Ruffle at FP 32 / Flash 11+. **No change.** Completion mechanism if ever wanted: a player-version
switch (none exists in this runtime) gating `actionPushRegister`/`StoreRegister` for func2 bodies with RegisterCount > 0.
Note for the coordinator: s26's `avm1_func2_param_register_oob` premise ("Ruffle ignores the write") is right for
**parameters** (`function.rs` binds them with `set_local_register`, no global fallback), not for body writes.

## 4. Remaining fixed caps (item 4)

Measured with `caps_overflow.py` (graphics; NG identical) before → after the prototype:

| Cap | Where | At the cap today | Game-reachable? | Before → after | Verdict |
|---|---|---|---|---|---|
| `MAX_TIMERS` 64 | `timer.c` | 65th `setInterval`/`setTimeout` returns `undefined`, never fires | yes (per-enemy intervals) | `id64=undefined id69=undefined`, fires stop at `n=64` → `id64=65 id69=70`, `n=70` | **GO**: static 64 block, then doubling heap blocks; old blocks never freed (a callback may grow the table while `fireTimerCallback` holds `t` and passes `t->extra_args`); `processTimers` re-derives `t = &g_timers[best]` after each callback. New static `timerFreeSlot`. |
| `MAX_WATCH_ENTRIES` 64 | `action.c` | 65th live `watch()` returns `false`, handler never runs | yes (binding-heavy UIs) | `r64=false`, `wc=64` → `r64=true`, `wc=70` | **GO**: same static+doubling, never-freed scheme (handlers are invoked with `&g_watch_table[i].user_data` and may call `watch()`); new static `watch_table_room()` replaces the two `g_watch_count < MAX_WATCH_ENTRIES` guards (`builtin_object_watch` and the MovieClip `watch` arm in `actionCallMethod`). |
| `MAX_CLONE_DEPTH_ENTRIES` 128 | `tag_stubs.c` | table only shrinks on same-depth eviction, so after 128 clones at fresh depths new clones are unregistered: a later clone at an occupied depth does **not** evict the old name; backward-goto survival (`actionRewindCleanup`) loses them | yes (bullets/particles at rising depths) | `typeof c135 = movieclip` after `z135` took its depth → `undefined` (Ruffle: replaced) | **GO**: `ng_table_grow` (indexed only, realloc-safe) in `clone_depth_register`. Lead: the table never drops removed clones (unbounded with growth; was silently saturated before). |
| `MAX_PROTO_STUB_FUNCS` 192 | `action.c` | later builtin stub/native methods missing | **no** — builtin-only, filled once per process by class init, not by game data | high-water (instrumented, reverted) 123 (`netstream_play_flv_screen`, `bitmap_filters`, `native_subclasses`, `extends_native_type`) / 126 (`global_swf6_7_8`) + a few uncounted inline sites | NO-GO; if a new class init lands, raise the static size (entries must stay pointer-stable: properties hold `ASFunction*`). |
| `MAX_LAZY_PROTOS` 128 | `action.c` `lazyProtoMarkInitialized` | 129th distinct prototype gets no lazy TextFormat/Video props | only via ≥ 129 distinct prototypes that construct a TextFormat/Video | not built | NO-GO (S if wanted: `ng_table_grow`, entries are retained pointers, indexed only). |
| `MAX_EI_CALLBACKS` 32 | `action.c` `actionEI_addCallback` | 33rd distinct name silently dropped, still returns `true` | browser hosts only (needs an external call handler; the trace harness has none, so no fixture) | not built | NO-GO (S: `ng_table_grow`; also return `false` at the cap meanwhile). |
| `MAX_SCROLL_CROPS` 64 | `tag.c` `scroll_crops_push` | 65th scrolled text field in a frame draws uncropped | possible (long scrolled lists); per-frame, render-only | not built | HOLD: needs a pixel fixture + exporter PNG. S (indexed, reset per frame). |
| `MAX_TEXT_CULLED` 64 | `tag.c` `compose_root_text_instance` | 65th off-stage root DefineText not culled (only visible when its glyphs reach the stage while its TextBounds do not) | rare | not built | HOLD, same mechanism. |

## 5. Dead `tagSetFilter*` (item 5)

`grep` over `SWFRecomp/src`, the runtime, `docs/recompiler`, scripts and every generated `Recompiled*` dir in the
downloaded corpus: no caller of `tagSetFilterColorMatrix`, `tagSetFilterConvolution`, `tagSetFilterGradient` (so
`getOrCreateExtFilter` and `g_ext_filters` are never written). The only reader, `ng_getExtFilterDataByDepth`, is called
from `actionGetMemberImpl`'s `filters` fallback and always returns NULL; ColorMatrix/Convolution/Gradient SWF filters
reach the `filters` getter through the multi-filter list (`FilterListData`) instead. Prototype removes: `tag.c` (the ext
table, `getOrCreateExtFilter`, the three setters, `ng_getExtFilterDataByDepth`), `tag.h` (decls + `ExtFilterData`),
`action.c` `actionGetMemberImpl` (the 98-line `efd` branch). **`tagSetFilter` / `tagSetFilterHighlight` are live and
stay.** 0 movers in the sweep (all filter rows below).

## 6. Argued sweep (prototype vs clean `origin/master`, same box, graphics, `--recompile`, saved actual bytes)

Argument for scope: the recompiler change only alters behaviour for (a) a root init on a frame a goto skips — only the
12 gnash SWFs with a root DoInitAction on frame ≥ 2 (scan above) — and (b) late-defined inits (only `InitActionTest2`);
frame-1 inits are done before any goto can capture them (the bitmap then dedupes). Timer batching is a no-op unless (a)
happens inside a callback. Caps change only past the old cap. Filter removal is dead code.

- **Final 53-row sweep** (both legs): avm1 `bitmap_filters bitmapdata_applyfilter_colormatrix duplicate_movie_clip
  duplicate_movie_clip_drawing set_interval string_paths_timer timeout timer_run_actions watch watch_infinite_recursion
  watch_proto_recursion watch_recursion_double_swf6 watch_recursion_swf7 watch_textfield watch_virtual_property
  watch_virtual_property_proto netstream_play_flv_screen loadmovie_replace_root movieclip_lockroot string_paths_eval2`;
  regression `avm1_filter_list_overflow avm1_func2_param_register_oob avm1_nested_po3_filters avm1_runtime_filters
  avm1_runtime_filters_cm_bitmap avm1_timer_clock_model avm1_timer_function_form_activation timer_cross_swf_version
  timer_type1_args watch_cross_swf_version watch_mc_reentrant_setmember watch_mc_type1_args watch_setmember_type1_args
  watch_timeline_named_params watch_timeline_reentrant`; from_gnash `misc-ming.all/duplicate_movie_clip_test(2)
  actionscript.all/Global-v6 Inheritance-v6 MovieClip-v6` + the 9 init rows of §1d; from_shumway `avm1/setinterval
  avm1/settimeout ZeroClipboardTest avm1/lookup`.
  Before: 39 PASS + 14 ruffle_matched. After: **40 PASS + 13 ruffle_matched. Bytes moved: exactly the 4 rows of §1d.**
- **Init/loader sweep** (after leg of the init part, 57 rows, all PASS): every `regression` loaded-child fixture
  (`avm1_parent_child_*`, `avm1_child_timeline_*`, `avm1_mcl_*`, …), avm1 `do_init_action do_init_action_child
  register_and_init_order init_object_order mcl_loadclip_properties mcl_loadclip_replace_root global_swf6_7_8
  loadmovie_registerclass resolve_different_root interface_implements_op loadmovienum_cross_version_prototype
  movieclip_invalid_get_bounds_6 as2_oop clip_constructors extends_chain issue_2084 coerce_to_object_monkeypatch
  on_construct …`, from_shumway `avm1timeline2 doubleAndRegister timeline/timeline_as2_4 avm1/doactionorder/symbolclass`.
  All baseline PASS rows (PASS is byte-exact).
- Not done: render canary (wave 2: init timing can move placements in the 12 gnash rows only; none is a canary
  member), WASM/emcc builds (no emsdk). New runtime symbols live in existing TUs (`tag.c`, `timer.c`); generated code
  now calls `tagDoInitActionFrame`/`tagDoInitActionFrameLate`, both in `tag.c`, which every build links.

## 7. EXPECTED-FLIP LEDGER (if the prototype lands)

**Trace (graphics, CI):** `from_gnash/misc-ming.all/init_action/InitActionTest2` **ruffle_matched → pass** (+1 pass,
effective-pass unchanged). `gotoFrameFromInterval`, `movieclip_destruction_test1`, `action_execution_order_test12`:
bytes move toward Flash, status stays ruffle_matched. Nothing else. **Pixel:** none expected.
Mode parity: no-graphics identical for those rows except `gotoFrameFromInterval` (pre-existing NG gap, §1e).
**Wave-2 scope:** recompiler change ⇒ every SWF with a DoInitAction regenerates (`--recompile`).

## HOLDs / NO-GOs and their completion mechanisms

- `gotoFrameFromInterval` → pass: blocked by case 1 (exec-order: a placed clip's frame-1 DoAction must run before the
  root's next DoAction in the same frame). Completion = the flat, instantiation-ordered exec list (arc §27.4 Exec
  order NO-GO), not this slot.
- `action_execution_order_test12` line 19: needs Flash's exact flush point for goto-queued init actions (§1b rule 2).
  Completion: a Flash Player capture of `goto_skipped_init.py script` plus a variant that calls a function after the
  goto (LOCAL ORACLE REQUEST 1).
- `movieclip_destruction_test1` remaining 8 lines: rule 4 (lead 1).
- func2 FP≤10 register semantics: needs a player-version concept (§3).
- `SCROLL_CROPS` / `TEXT_CULLED`: pixel fixture + exporter PNG.

## New unclaimed leads

1. **Same-frame DoInitAction must run after the frame's placements, before its DoActions** (Flash, §1b rule 4). Owner:
   the recompiler's init prologue placement (`SWF::writeFrameInitMarker` / `flushFrameInitPrologue`, top of the frame
   body). Price: `movieclip_destruction_test1` up to → pass (8 lines; then its `initActionExecuted` total line also
   needs §1). Risk: `#initclip registerClass` + same-frame placed instance (constructor must see the class) — needs the
   init to run between placement and the clip's construct/init queue drain. M; overlaps `w1-exec-order`.
2. **Root `gotoAndStop` / `nextFrame` from a timer callback never runs the target frame's DoAction (graphics too)**:
   `timer_root_goto_stopped.py gs|nf` on clean master: `_currentframe` updates (`after cf=3`) but `f3 cf=` never
   prints, so the interval is never cleared (repeats forever). `gotoAndPlay` works (the next tick plays the frame). Also
   what defeats `setInterval(_root, "nextFrame", 10)` in §2. Ruffle: goto runs immediately, the target DoAction is
   queued and run after the callback. Owner: `action.c` root goto arms (`actionGotoFrame`/`actionNextFrame` outside
   the frame loop) + where the queued target script would drain while stopped; adding an AQ drain after each callback in
   `processTimers` (tried) does **not** fix it, so the script is not on the action queue. Game-visible (menus, slideshows,
   "setTimeout → gotoAndStop"). M.
3. **No-graphics: a root goto from a timer never runs the target frame's DoAction** (`swf_core.c`; graphics does run
   it, §1e). Mode-parity bug; no CI row today.
4. `actionEI_addCallback` returns `true` when it drops a callback at the cap (S, with the cap fix).
5. Clone-depth table never forgets removed clones (`tag_stubs.c`; with growth it is unbounded): drop entries in the
   `removeMovieClip` path. S.
6. Other fixed caps not in the brief (inventory, unassessed): `MAX_PLAYING_SOUNDS` 16 (`action.c:85270`; Flash mixes
   32), `MAX_PENDING_MCL_LOADS` 16, `MAX_PENDING_DIRECT_LOADS` 16, `MAX_DEFERRED_FAILED_LOADS` 16,
   `MAX_PENDING_LV_LOADS` 32, `MAX_DEFERRED_UNLOADS` 32, `MAX_NS_NATIVE_STATES` 32, `MAX_XMLSOCK_STATES` 32,
   `MAX_LC_CHANNELS` 32 / `MAX_LC_MESSAGES` 64, `MAX_ACTIVE_NETSTREAMS` 8, `MAX_SPRITE_PLACEMENT_ENTRIES` 1024 (`tag.c`).
   The load queues (16) are the likeliest game hits (asset-heavy loaders).
7. Watch entries keep `prop_name[64]` but compare `prop_name_len` bytes: a watched name ≥ 64 chars never matches
   (watcher never fires). XS.

## Functions touched (for siblings / the N session)

- `action.c`: watch-table declaration block (new static `watch_table_room`), `builtin_object_watch`, `actionCallMethod`
  (MovieClip `watch` arm guard only), `actionGetMemberImpl` (removed the dead `efd` branch).
- `tag.c`: new `tagDoInitActionFrame`, `tagDoInitActionFrameLate`, `tagDrainGotoInitActions`, static
  `tagDrainGotoInitActionsAQ`, `tagGotoInitCapture`, `tagGotoInitTimerPass`; `tagShowFrame` (one block at the top);
  removed `getOrCreateExtFilter`, `tagSetFilterColorMatrix`, `tagSetFilterConvolution`, `tagSetFilterGradient`,
  `ng_getExtFilterDataByDepth`. `tagDoInitActionGuarded` unchanged.
- `swf.c`, `swf_core.c`: `ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`, `swfStart` (goto retry loop).
- `tag_stubs.c`: clone-depth table declaration, `clone_depth_register`.
- `timer.c`: timer table declaration (new static `timerFreeSlot`), `timerIsObject`, `actionTimerSetInterval`,
  `actionTimerClearInterval`, `fireTimerCallback`, `processTimers`, loops in `hasActiveTimers`/GC hooks.
- `SWFRecomp/src/swf.cpp`: `SWF::interpretTag` (DoInitAction, DefineSprite cases), `SWF::parseAllTags` (out.h tail).
- `ng_shared.c`: not touched.

## LOCAL ORACLE REQUESTS

1. **Flash Player (not Ruffle) capture, if the coordinator has a projector/debugger**: `goto_skipped_init.py script` and
   `timer` SWFs (fixtures dir; `python3 goto_skipped_init.py out.swf script|timer`), 6 frames. Ruffle's exporter/runner
   is NOT a valid oracle for these: it runs every DoInitAction at preload. If no Flash is available, the gnash rows of
   §1b are the oracle of record and no regression fixture should be committed for item 1.
2. **Ruffle test runner** (timer-firing) on `timer_method_form.py`, `timer_native_method.py play`,
   `timer_root_goto_stopped.py gs`, and `caps_overflow.py timers` — goldens for the wave-2 `avm1_timer_*` fixtures.
   Predicted from Ruffle source: method form `ia=1`, `arr m len=7`, `f2 reached via timer nextFrame`, t2 cleared;
   `gs`: `f1`, `after cf=3`, `f3 cf=3` once; caps timers: `id64=65 id69=70`, `n=10…70`, `end n=70`.
3. **Ruffle exporter** (frame scripts only, no timers needed): `caps_overflow.py clone` (predicted last line
   `typeof c135 = undefined z=movieclip`) and `caps_overflow.py watch` (predicted `r64=true r69=true`, `wc=70`), 1 frame
   each — goldens for `avm1_clone_depth_overflow` / `avm1_watch_overflow` fixtures.
