# browser-attached-timeline: browser-WASM attached clips run their natural timeline (session 24, one-task slice)

Follow-up to `w2-attached-timeline-report.md` §4 (commit `3cdde8be0` fixed attachMovie'd clips in the CI modes only).
Local session (needs emsdk + headed WSLg Chrome). Base `1475d847b`.

**Result:** browser-WASM now shares the CI-mode pump (`ng_advance_attached_clip_playheads` / `ng_attached_run_tree`).
On every probe, the browser trace equals the native graphics trace, and both equal the Ruffle exporter oracle for ticks ≥ 2.
The work found three more browser blockers and two CI-mode bugs in the shared pump; all are fixed here.

---

## 1. What the brief got wrong (by §)

- **§Background ("attached clips still don't animate / run later frame scripts"):** an understatement. In the shipping browser build:
  1. **`_root.attachMovie` was a no-op.** `action.c` had a browser-only guard in both the CallMethod and CallFunction arms, added by `3ff709191` (2026-05-26). Its premise was that root frame funcs re-run every tick. `8588bb163` removed that premise two days later (root DoAction now runs once per frame *entry*), but the guard stayed. Every root attach in a shipped browser game was silently dropped, which made the root probe print only `root f2`.
  2. **An attached clip's own frame-1 script never ran.** The CI modes run it through the `AQ_KIND_ATTACH_INIT` re-run (`aq_dispatch_pending_attach_init`). That re-run needs the script-only / attach-init gate accessors, and `graphics_stubs.c` stubs all of them to 0 in the browser. Nothing in the browser build ever drained `AQ_KIND_ATTACH_INIT` either: both drain sites are in CI-only blocks. The queue grew by one entry per attach, with a linear dedup scan on every attach.
  3. Nothing advanced past frame 1, except gotoAndPlay'd clips, which got placement tags only, as the brief said.
- **w2 §1.1 "converts the root's playhead between shown and next frame": this is a CI bug.** `ng_gotoFrameByMC` and `action.c`'s gotoAndStop guard store *next* in an attached root's `sprite_current_frame`; only the pump read it as *shown*.
  - **Symptom:** after `a.gotoAndPlay(4)` (5-frame clip) the next tick ran **f1** (wrap); after `gotoAndPlay(2)` it skipped f3. Ruffle runs f5 and f3.
  - **Fix:** attached roots use *next* semantics throughout. `ng_record_attached_playable` starts them at 1 and the pump drops the conversion.
  - **Test:** `regression/avm1_attached_clip_goto_play{,_nonroot}`. Both modes failed it before the fix.
- **Second CI bug: non-root attached clips double-advanced their children.**
  - **Cause:** `ng_attachMovie` (CI modes) registers a non-root attached clip in its parent's `sprite_display_list[as_depth + 16384]` as a lookup/render alias that shares the clip's child-list buffer. The parent's timeline walk (`advance_sprite_frames` / `advance_nested_sprite_frames`) then advanced the alias's children a second time per tick (`kid anim f1 → f3`).
  - **Fix:** a new `DisplayObject::attach_registration` flag. It is set on the alias and cleared by both PlaceObject paths. The three timeline walks skip the alias (advance, nested advance, `presync_nested_cf_recurse`). After each pump run, `ng_sync_attach_registration` re-copies the clip's list fields into the alias, so the parent's render recursion doesn't iterate a stale `max_depth`.
  - **Test:** `regression/avm1_attached_clip_natural_timeline_nonroot`.
- **AGENT_LAUNCH_ORDER's attach-tick note ("Ruffle runs the child's frame 1 BEFORE its parent") is refined.** Ruffle runs attach-tick frame-1 actions in **tag order**.
  - **Oracle check:** I moved `stopper`'s DoAction before its PlaceObject; Ruffle then prints `s stopper f1` before `kid2 anim f1`.
  - **Ours:** both paths always run the clip's own DoAction first. A correct fix has to instantiate the child at its PlaceObject inside the attach replay, which isn't cheap. The item stays on the s24 board (`polish-sweep-arc.md` §24.4, updated).

## 2. Proof of the defect (before = HEAD `1475d847b`, browser harness)

| Probe | Browser before | Native graphics (before) | Ruffle |
|---|---|---|---|
| `attach_probe` (root) | `root f2` only: the attach is a no-op | attach-tick order diff only | oracle |
| `attach_probe` nonroot (new `make_probe_swf.py <out> nonroot`) | `kid/kid2/kid3 anim f1`, `root f2`, then nothing. The clips' own frame-1 scripts never ran and nothing advanced | kids double-advanced (`f1 → f3`) | identical to root variant |
| goto probe (root / nonroot; now `regression/avm1_attached_clip_goto_play*`) | (root attach no-op) | `a f4, a f1` / `a f2, a f4` | `a f4, a f5` / `a f2, a f3` |

## 3. Changes

- **`tag.c`**
  - **Pump un-gated for every build:** `ng_stamp_attach_seq`, `ng_record_attached_playable`, `ng_promote_attached_playheads`, `ng_attached_run_tree` and `ng_advance_attached_clip_playheads`.
  - **Next-frame semantics** for attached roots.
  - **The pump skips `natural_oneshot` clips.** N's `pfx*` morph particles keep their countdown path because of the morph-ratio limit.
  - **Alias handling:** `ng_sync_attach_registration`, plus the `attach_registration` skips in the three walks.
  - **`advance_attached_clip_natural` is now pfx-only.** The `goto_play_active` field is gone; the pump covers gotoAndPlay'd clips.
  - **`advance_attached_clip_frames`** (the browser manual-nav pass) runs the *target* frame's DoAction (queued) and leaves next = target + 1.
  - **`hasPlayingSprites()` now counts playing attached clips.** Before, no-graphics quit when the root stopped on its last frame while attached clips still played; graphics kept going.
  - **The browser nested loop-back no longer prints `Failed to place object`** when it refuses a surviving same-char child (new `g_nested_loopback_quiet`, always 0 in CI).
- **`swf.c`**
  - The browser (`#else` of OFFSCREEN) calls the pump in the same Phase-1 slot as OFFSCREEN: before the root frame func, so attached scripts drain ahead of the root DoAction, as in Ruffle.
  - It promotes after the end-of-tick orphan drain.
- **`tag_stubs.c`**
  - **Browser `ng_attachMovie`** runs frame 0 *live* (`catch_up_mode = 0`, clip as context / base / sprite obj). The frame-1 DoAction is queued and drains after the attaching script, and frame-1 sounds play, as in Flash.
  - **The browser no longer queues `AQ_KIND_ATTACH_INIT`.**
  - **CI registration alias** gets `attach_registration = 1`.
- **`action.c`**
  - Removed the browser root-attach no-op guards (both arms).
  - **gotoAndStop guard (browser):** `gotoAndStop(N)` on a clip already showing N skips the rebuild but now **stops** the clip. Without this, N's `tileMC` (attach then `gotoAndStop(1)`) played its 34 tile frames.
  - **Hidden ancestors hide text fields** (`tf_ancestor_hidden`, both text passes, all builds). Without this, N's root-attached `inputBox` (`_visible = false` straight after the attach) drew two white panels over the menu.
- **`swf.h`:** `goto_play_active` replaced by `attach_registration`.

## 4. Verification

- **Probes, browser vs native vs Ruffle:**
  - root `attach_probe`: browser = native (34 lines), browser ticks ≥ 2 = Ruffle.
  - nonroot: browser = native.
  - Both goto probes: browser = Ruffle byte-for-byte.
- **New regression rows (4):** pass in graphics and no-graphics.
- **Headline rows:** `from_gnash/misc-swfc.all/movieclip_destruction_test3`, `_test4`: pass (graphics).
- **Sweep, before vs after:** HEAD baseline tree vs working tree; actual `--diff` output, byte-compared.
  - **Rows (87):** every avm1 / from_gnash / from_shumway / timeline / regression row whose decompressed SWF contains `attachMovie`, plus avm1/gnash rows named unload/remove/destruct, plus regression `avm1_child_timeline_*`, `avm1_parent_child_*`, `onunload_type1_*`, `avm1_attach*`.
  - **Graphics:** 87/87 identical, including after the `hasPlayingSprites` change.
  - **No-graphics:** 87/87 identical.
  - **Failures predating this change** (identical on HEAD): `globals_monkeypatch` (upstream drift), `movieclip_hittest_shapeflag`, `misc-ming.all/action_order/PlaceAndRemove`.
- **Games, browser before/after.** Same SWF; builds via `build_test.sh` from a HEAD-runtime mirror and the working tree. GPU readback captures (`dbgCapturePNG`).
  - **Pacman:** gameplay identical except the attached `Power` pellets (11 frames). The bright-pixel count in the top-left pellet is constant 72 before and pulses `24 52 72 72 52 40 24 40 52 64` after. No errors.
  - **Doodle Jump:** the game the root-attach guard was written for. The menu still animates after 18 s (no hang). Gameplay spawns platforms; platform clips (`cloud`, 4 frames) stay on their gotoAndStop'd type. No errors.
  - **N:** two regressions found and fixed (§3: tileMC gotoAndStop, hidden inputBox fields). The menu matches the Ruffle exporter frames, and the demo levels cycle. No `bar` / 4096-cap explosion, the v1 hazard.

- **CI** at `161ecf124`, `categories=all`:
  - graphics `44960857582` and no-graphics `44960860384`: both `success`, WASM link-smoke included.
  - `corpus_status_diff` over the 4646-row intersection: **0 gains, 0 regressions, 0 status moves** in both modes. Graphics effective 4584; no-graphics 4583 (the `audio/aac` mode gap).
  - The 4 new `regression/avm1_attached_clip_*` rows pass in both modes (regression 108/108).

## 5. Left open / next slice

1. **Attach-tick frame-1 tag order** (§1, s24 board).
2. **Perf A/B on Windows real-GPU Chrome** (per `CLAUDE.md`; WSL is SwiftShader) for N, which plays many 100-frame limb clips. It was not run: the pump does one 2-entry calloc plus an advance per playing attached clip per tick.
3. **Browser `advance_attached_clip_frames`** (bare in-script gotos on attached clips) still rebuilds intermediate frames from frame 0 on every nav. Correct now, but O(target).
4. **`regression/avm1_attached_clip_*`** have no `[image_comparisons]`. The probes have no visible shapes.

---

## 6. Real-GPU perf A/B (N) — s24 one-task follow-up to §5.2

**Answer: yes.** `161ecf124` cost N about **1.5 ms per frame** (+35–40% frame CPU). Delivered fps fell from ~113 to ~97 against N's declared 120 fps. Almost all of it was a **quadratic insertion sort** in the pump's root collection, not the per-clip calloc the brief suspected. It is now fixed, and the fixed build is at parity with the pre-`161ecf124` build.

### Method

- **Rig:** Windows Chrome (Playwright 1.61 via `python.exe` from WSL). Every run printed WebGPU adapter `intel / xe-3lpg`, `fallback=false` (real GPU).
- **Driver:** `tools/divergence/perf/n_ab_win.py`. It drains every `__swfPerf` sample (Ruffle: `__rufflePerf*`), drops tainted frames (the HUD's warmup/throttle flags), and reports the 10–90 s window after Run.
  - **Scene:** N's main menu over its attract-mode demo: real-physics levels with the ninja running (the limb clips) and ~900 attached `tileMC`s. Levels cycle about every 20 s.
  - **Real gameplay is unreachable by automation in both of our builds.** A click on "play game" does nothing in BEFORE or AFTER, while Ruffle opens "select episode". This is a separate input gap, not from this change.
- **Builds:** all `build_test.sh flasharchive/N wasm --graphics` with `EMCC_CFLAGS=--profiling-funcs`, deployed side by side under `docs2/examples/flasharchive/N_*` (gitignored).
  - **BEFORE** = `bed2dfc0e`, built in a separate worktree.
  - **AFTER** = `952fd6ce5` (origin/master at session start).
  - **FIX** = later master + this fix. The other runtime commits in between were `77545c5ac` (filters) and a small `action.c` lazy-prototype change.
  - The recompiler is unchanged across the range, so all builds use the same generated code.
- **Ordering:** runs were interleaved B/A/x ×3 per series.
- **"Frame CPU"** = `__swfPerf.cpu` (whole tick incl. render submit) per SWF frame. **Duty** = CPU ms per wall second.
- **Machine drift:** series 3–4 ran ~13% slower overall (BEFORE itself moved), so compare within a series.

### Results (10–90 s window, mean frame CPU ms / delivered fps; 3 runs each)

| Series | BEFORE `bed2dfc0e` | AFTER `952fd6ce5` | fix variant | Ruffle (profiling build) |
|---|---|---|---|---|
| s1 | 3.94 / 115.0 · 4.07 / 113.5 · 4.17 / 111.4 | 5.52 / 97.3 · 5.48 / 97.4 · 5.74 / 94.6 | — | 5.94 / 117.0 · 6.03 / 116.5 · 6.25 / 115.6 |
| s2 | 4.24 / 111.4 · 4.05 / 113.7 · 4.00 / 113.9 | 5.67 / 95.7 · 5.37 / 98.8 · 5.49 / 97.5 | FIX-a (qsort): 4.53 / 107.6 · 4.42 / 108.8 · 4.46 / 108.1 | |
| s3 | 4.71 / 105.4 · 4.63 / 106.2 · 4.61 / 106.3 | 6.42 / 89.3 · 6.52 / 88.4 · 6.52 / 88.5 | FIX-b (qsort + inert-child skip): 5.23 / 99.7 · 5.14 / 100.8 · 5.21 / 99.8 | |
| **s4** | **4.62 / 106.5 · 4.73 / 105.0 · 4.72 / 105.1** | **6.56 / 88.0 · 6.47 / 89.0 · 6.61 / 87.5** | **FINAL (insertion sort on cached keys + inert-child skip): 4.61 / 106.0 · 4.60 / 106.5 · 4.60 / 106.2** | |

- **Spread:** within a series, a build's run-to-run spread is ≤ 0.25 ms. The AFTER − BEFORE gap is 1.4–1.9 ms in every series. FINAL − BEFORE is −0.08 ms (parity).
- **p95** in s4: BEFORE 6.6–7.0, AFTER 8.9–9.3, FINAL 6.7–6.8.
- **Duty** in s4: BEFORE 492–496 ms/s, AFTER 576–578, FINAL 489–490.
- **Ruffle comparison is not like-for-like.** Ruffle samples once per RAF (tick + render), so compare duty instead: Ruffle 696–722 ms/s vs our 453–464 (BEFORE, s1).
- **Delivered fps:** Ruffle ~116 fps; BEFORE and FINAL ~106–114; AFTER ~88–97.

### Attribution

CDP inclusive/self profile (`n_cdp_win.py`, 25 s, 200 µs sampling), checked with a temporary timer build (not committed):

- **AFTER:** `runSWF` self time was **25.5%** of busy CPU (BEFORE: 0.8%). Binaryen inlines the single-call-site `ng_advance_attached_clip_playheads` into `tagMain` → `runSWF`, so its cost shows up there.
- **Timer build per tick:** `child_mc_count` ≈ 1030, **~900 eligible attached roots**.
  - The collect + sort phase took **1.6–1.8 ms**.
  - Running the trees took 0.41–0.47 ms: ~960 nodes, ~50 child-MC name lookups, ~10 real advances (the calloc path).
- **Cause:** the collect loop insertion-sorted roots newest-`place_seq`-first. `child_mc_cache` holds them oldest-first, so every insert shifted the whole array (~400k shifts per tick). Each step also dereferenced `roots[k-1]->display_obj->place_seq`.
- **FIX-a** (cache the key, `qsort`): `runSWF` self dropped to 1.5%. musl's smoothsort (`wrapper_cmp` / `sift` / `trinkle`) then cost ~6% on this nearly reverse-sorted input.
- **FINAL:** reverse the collected array, then insertion-sort on the cached `(seq desc, scan-index asc)` key. That is a total order, so the result is identical to the old stable sort. No sort frames remain in the profile.
  - Residual pump cost: `ng_attached_run_tree` 8.9% inclusive. Of that, 5.1% is `advance_sprite_frames`, the clips' actual timeline work.
- **Inert-child skip** (also landed): `ng_attached_run_tree` now skips a child with no child list whose own playhead won't move before the O(`child_mc_count`) `ng_attached_child_mc` lookup. The recursive call would have returned with no effect, and the lookup is pure, so this is behaviour-preserving by construction. It had no measurable effect on N (s3 vs s2 gap fraction).
- **Offsetting saving:** `161ecf124`'s hidden-ancestor text fix removed N's invisible `inputBox` glyph rendering (`textfield_glyph_render_cb` 7.3% → ~0 in the profile). That is why FINAL lands at BEFORE parity despite the new timeline work.

### Verification

- **Regression rows:** `regression/avm1_attached_clip_{goto_play,goto_play_nonroot,natural_timeline,natural_timeline_nonroot}` pass in graphics and no-graphics.
- **Headline rows:** `from_gnash/misc-swfc.all/movieclip_destruction_test3`, `_test4` pass in both modes.
- **N browser smoke:** FINAL screenshots at 10/30/50/70/90 s show the menu over cycling demo levels, with the ninja and limbs animating. No page errors in any run.
- **CI:** see the commit.

### Next slice

The remaining per-tick pump overhead on N is ~0.2 ms:
- two O(`child_mc_count`) scans (collect + promote);
- an `ng_attached_run_tree` call on each of ~900 stopped leaf `tileMC` roots.

A registry of attached-playable clips (add at `ng_record_attached_playable`, prune on `avm1_removed` / `depth == INT_MIN`) would make both O(active). That only pays for games with thousands of attached clips. Not needed for N, which is at parity.
