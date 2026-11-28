# N L2/L4 native pixel pass: console tabs, f32 `_xscale`, and attached-clip self-gotos (2026-11-23)

One-task session after `n-ragdoll-strokes` (`n-ragdoll-strokes-report.md` §7), launched by `s27-coordinator`.
Brief: `SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/n-l2l4-pixel-pass-prompt.md`.

**Summary**
- **Goal 1, L2/L4 frame-locked native vs exporter (§1–§3).** Telemetry (`NF`/`ND`, incl. `h=`/`o=`) is
  byte-identical on both routes over the common span. Three pixel classes are ours, all fixed, and the real Flash
  Player decided each one:
  1. **Console tabs (2.5k–4.8k px/frame on every menu / level-load screen).** N's loading console prefixes lines
     with `"\t"`. The AVM1 EditText painter skipped the tab (no glyph), so every line was flush left. Flash's
     default tab stops are **not** Ruffle's: Flash = multiples of `2·(ascent+descent)` from the field edge, Ruffle =
     `2.7·size` from the text origin. Implemented Flash's rule in `tag.c`. Fixture `regression/avm1_edittext_tab_render`
     (Flash golden).
  2. **HUD timer text 1 px right, one frame late, every 12 frames (60–80 px spikes).** N does
     `txtbox._x = Math.floor(bar._xscale) + 1`. `MovieClip.xscale/yscale` were `float`, so an AS-set `82.99999999`
     read back `83`. Flash and Ruffle keep the double. Now `double`. Fixture `regression/avm1_xscale_double_readback`
     (Flash trace = Ruffle trace).
  3. (Goal 2, found on the way) see below.
- **What's left on L2/L4 is not ours (§3):** the fps counter (wall clock), and 1–2 px per mine/tile edge. On those
  edge pixels ours matches Flash where Ruffle doesn't about as often as the reverse; they are MSAA vs Flash's
  analytic AA, the same floor as level 0.
- **Goal 2, goto-rebuild `_root` fallback (§4): reproduced, and worse than the brief said.** When an attachMovie'd
  clip's own frame script calls `gotoAndPlay`/`gotoAndStop`, `_currentframe` stayed on the issuing frame forever
  and the target frame's children were unreachable (`h.kid` undefined). Both are fixed in
  `ng_apply_pending_sprite_self_gotos`. Fixture `regression/avm1_attached_clip_selfgoto_child_parent` (Flash trace +
  image = Ruffle).
- Goal 3 (FRAMELOCK slack): not done.

- **Latent bug found by the sweep (§5):** after the `double` change, `avm1/netstream_play_flv_screen` (green in
  the baseline) segfaulted. Cause: `actionSetMember`'s MovieClip `addProperty`-setter arm called a type-2 setter
  with a `MovieClip*` as its `ASObject*` `this`. The ASObject/MovieClip confusion only survived because the old
  struct layout put sane-looking bytes at `properties`. Now routed through `invokeFunctionValue` with a MOVIECLIP
  `this`. No other `advanced_func(..., (void*)mc)` site exists.

## 1. Recipe (L2 and L4)

- Probes: `n_drive/build.sh` with `START_LEVEL=2|4 AUTOKILL=true OBJHASH=true FREEZE=""`, scripts from
  `routes_ep0.txt`. L2 = 3 attempts (200 / 1163 / 60 ticks), L4 = 3 attempts (533 / 519 / 60 ticks).
- Exporter: `WGPU_BACKEND=vulkan exporter -s -f 2050|1750 --trace-log`. Native: `run_native.py --frames 2060|1760`,
  then `build/test_run` with `CAPTURE_TRIGGERS` every 4th frame.
- Comparison: native `F(k)` vs exporter `k-2..k` (best), counting pixels with max channel delta > 24 (the level-0
  recipe).
- **Flash spot checks:** `tools/flash-oracle/run_image.py` on the injected N SWF itself works (792×600 capture,
  FRAMELOCK keeps it frame-aligned). Ticks 20, 136, 300 and 800 were used. N reaches about tick 1000 before the
  harness's `max_duration`.
- **Harness trap:** `capture.c` copies `CAPTURE_TRIGGERS` into a 4096-byte buffer, so about 206 `Fnnnn:iteration:n`
  tokens is the cap; the rest are silently dropped. Run `test_run` once per ≤150-trigger chunk.

## 2. Telemetry

`NF`/`ND` lines (`h=`, `o=`) are byte-identical exporter = native over the common span on both routes. Native's
extra lines are the frames past the exporter's last one. No game-state divergence.

## 3. Pixel classes

| route | frames | px (before) | class | verdict |
|---|---|---|---|---|
| L2, L4 | menu + level load (4–140 on both; L2 1668–1756) | 1.6k–4.8k | console lines flush left | **ours, fixed** (tabs) |
| L2 | every 12th frame 776…1660 | +60–80 on a ~100 floor | HUD timer text 1 px right for 1 frame | **ours, fixed** (f32 `_xscale`) |
| L2 | gameplay | ~100 | 1–2 px per mine / tile edge | AA floor: vs Flash, ours-only ≈ Ruffle-only |
| L4 | gameplay | 11–55 | fps counter + edge px | floor (fps = wall clock) |

**Console tabs.**
- N's `console.AddLine` prepends `this.tabs` × `"\t"`. It sets no `tabStops`.
- Flash, measured with `regression/avm1_edittext_tab_render` plus two font-metric variants (space advance 256;
  ascent/descent 1500/500):
  - Default stops are multiples of `T = 2·(⌊asc·size/em⌋ + ⌊desc·size/em⌋)` twips (21.4 px for a 1100/1024 font at
    10 px; 38.9 px for 2000/1024). They are counted from the **field's left edge** (text cursor + 2 px gutter).
  - The space advance plays no part.
  - A centred line is laid out left, then shifted as a whole (A at 67.25 px, predicted 67.24).
- Ruffle (`layout.rs` `tab()`): `2.7·size` from the text origin. N's console shows the difference: Flash indents
  66/88, Ruffle 67/89. The exporter is therefore NOT a golden for tabs.
- Fix: `tag.c` `tf_default_tab_stop` + the measure and draw loops of `textfield_glyph_render_cb`.
- N after the fix, console box vs **Flash**: tick 20 3054 → **0 px**; tick 136 1349 → 327. The remaining px at 136
  are load-progress dots, not tab positions.
- Fixture `regression/avm1_edittext_tab_render`, golden = Flash (trace + image). Ours lands every glyph within
  0.25 px of Flash (tolerance 64 for sub-pixel edge AA). Before the fix, glyphs were 20–80 px off.
- Not done (painter gaps, documented in the fixture):
  - explicit `TextFormat.tabStops` in the painter (Flash: from the TEXT origin; no advance past the last stop);
  - tabs inside word-wrapped fields (`tf_soft_wrap_breaks` uses fixed per-char advances);
  - the `textWidth` metric (`ng_shared.c` still uses Ruffle's `2.7·size`; Flash `d=45 b=93 c=24` vs ours = Ruffle
    `59/64/39`). Changing that moves trace rows, so it is a separate slice.

**HUD timer.**
- N: `txtbox._x = Math.floor(timeMC.bar._xscale) + 1`. The bar's own pixels were identical every frame. Only the
  text stepped a frame late (Ruffle moved at 776, ours at 777; 788/789; …).
- `MovieClip.xscale/yscale` were `float`. Flash Player 32 and Ruffle return `82.99999999` exactly (floor 82); ours
  returned 83.
- Fix: `double xscale, yscale` (and the `exact_m_xs/ys` snapshots) in `action.h`. All AS setters store the double;
  all four getters (`GetVariable` special var, `GetProperty`, `actionGetMemberImpl`, `getMCBuiltinProperty`) push
  F64. Timeline clips are unchanged (their scale still comes from the float matrix decompose).
- N L2 frames 776/788/800: 150/163/181 → 98/108/114 px, i.e. at the floor.
- Fixture `regression/avm1_xscale_double_readback` (trace golden: Flash = Ruffle).

## 4. Goal 2: attached clip self-goto (`ng_apply_pending_sprite_self_gotos`)

Reproducer `regression/avm1_attached_clip_selfgoto_child_parent`:
- Exported "holder": frame 2 runs `gotoAndPlay(4)`; frame 4 places `kid` and `bone` and stops.
- Root attaches it, then traces at frame 6.

Flash Player 32 = Ruffle: `h frame: 4`, `h.kid` is a movieclip at `/h/kid`, `_root.kid` undefined. Ours, before:
- `_currentframe` stayed **2 forever** (an attached root's `mc->currentframe` is written only by
  `ng_attached_run_tree`'s natural advance);
- `h.kid` was **undefined**: the children were initialised with parent = the name lookup, which falls back to
  `_root` for an unnamed attached entry; neither `_root.kid` nor `h.kid` resolved.

`gotoAndStop` was worse: it was never applied at all. `ng_attached_run_tree` returns on a pending manual nav, and
the deferred top-of-loop path only walks timeline lists. Fix:
- bind the clip by `display_obj` (`att_mc`);
- parent the init to it (else `ng_mc_for_sprite_obj`, else `_root`);
- sync `att_mc->currentframe`;
- apply an attached root's `gotoAndStop` in the same pass.

Result: trace + image pass in both modes. The image golden is the exporter's frame 5, equal to Flash's tick 6 at
0 px.

Not changed, pre-existing and general: a self-goto issued by a clip's frame script is visible to the ROOT's frame
script of the SAME tick in Flash (`cf=4` at tick 2), but ours applies it after the drain (`cf=2` at tick 2). A
timeline-placed clip shows the same 1-tick lag, so it is not attached-specific. Candidate slice.

## 5. Sweep and pricing (local, both modes)

- **Rows:**
  - 119 rows whose SWF names `_xscale`/`_yscale`/`_width`/`_height` or SetProperty indices 2/3/8/9 (byte scan over
    avm1, from_gnash, from_shumway, regression, visual), including `set_property_values/swf4..7` and gnash
    `matrix_test`;
  - 59 rows that use `addProperty`, plus `avm1/matrix`, `avm1/transform` and the three new fixtures.
- **Graded against** the fresh `results_graphics.json` / `results.json` at `origin/ruffle-test-results` `a0e485e5f`.
- **Moves:**
  - `avm1/netstream_play_flv_screen`: pass → segfault after the `double` change. Root-caused and fixed (latent
    MovieClip-as-ASObject setter `this`, §Summary). Pass in both modes.
  - `avm1/external_interface_monkeypatch` and `avm1/globals_monkeypatch`: fail → pass in both modes in the SHARED
    tree. Attribution: **not this change.** On HEAD + only
    this session's hunks (a detached worktree), `external_interface_monkeypatch` still fails exactly as in the
    baseline (135 lines). The coordinator's uncommitted `actionEI_addCallback` hunk is the likely source.
    `globals_monkeypatch` could not be built on HEAD + mine: the shared recompiler build carries a peer's
    uncommitted `swf.cpp`, so it fails to link. Its baseline failure is `Object`/prototype monkey-patching, which none
    of these hunks touch. CI grades both with the coordinator's patches.
  - Everything else is unchanged. `set_property_values/swf4` and `movieclip_hittest_shapeflag` fail exactly as in
    the baseline (same line counts).
- The `double` change moved **no** corpus row by itself: no corpus trace row prints a non-f32-representable AS-set
  scale.

## 6. CI grading

Per the brief, `ruffle-tests.yml` was not dispatched from this session. The SHA, change class and expected moves
went to `s27-coordinator`.

Expected moves:
- **trace:** the 3 new regression fixtures are new rows (pass in both modes locally). No corpus row moves from
  these hunks: the 178 swept rows are unchanged vs the baseline, after the setter fix.
- **images:** `regression/avm1_edittext_tab_render` and `regression/avm1_attached_clip_selfgoto_child_parent` are
  new `[output] pass` rows. AVM1 EditText fields containing a TAB now advance to Flash's stops. A corpus image row
  with a tab-bearing field could move; none appeared in the swept rows.
- **no-graphics:** same as trace.
- **browser:** the painter and the `double` scale are shared code, so they are browser-visible (Pages deploy is the
  coordinator's).

*CI result: f5565dcf9 landed after interim #2 was dispatched (at cceb5133a), so it is graded in **interim #3**
(graphics + images + no-graphics). The by-name result is recorded in the s27 arc doc, not here. Successor:
`n-levels-5plus` (levels 5+, then the textWidth tab metric).*

## 7. Next blocker / next slice

1. **L2/L4 native are at their floor** (fps counter, edge AA). Next N value: the browser on L2/L4, or episode 0
   levels 5+.
2. **Text tab follow-ups:**
   - the `textWidth` metric to Flash's tab rule (it moves trace rows: price it first);
   - explicit `tabStops` in the painter;
   - tabs in wrapped fields.
3. **Same-tick visibility of a clip's own self-goto** to later scripts in that tick (§4, 1-tick lag, general).
4. **Harness:** raise `capture.c`'s 4096-byte `CAPTURE_TRIGGERS` buffer (silent truncation at ~206 triggers).
5. FRAMELOCK slack (carried, not done).

## 8. Tooling / traps

- **The real Flash oracle runs N itself:** `run_image.py <dir with test.swf = injected n_drive> --ticks a,b`. Use it
  to decide every N pixel class before believing the exporter.
- **Price a runtime change on HEAD + own hunks only** when the shared tree holds peers' uncommitted work:
  - `git worktree add --detach <wt> HEAD`, then `git apply` your filtered diff;
  - symlink `SWFRecomp/build` into the worktree;
  - run the worktree's `verify_output.py` with `--tests-dir` pointing at the main tree's (untracked) suites.
- A struct-layout change can expose type confusion elsewhere (ASObject vs MovieClip). An ASan build pinpoints it in
  one run (`run_native.py --asan`).
