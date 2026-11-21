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

## 5. Left open / next slice

1. **Attach-tick frame-1 tag order** (§1, s24 board).
2. **Perf A/B on Windows real-GPU Chrome** (per `CLAUDE.md`; WSL is SwiftShader) for N, which plays many 100-frame limb clips. It was not run: the pump does one 2-entry calloc plus an advance per playing attached clip per tick.
3. **Browser `advance_attached_clip_frames`** (bare in-script gotos on attached clips) still rebuilds intermediate frames from frame 0 on every nav. Correct now, but O(target).
4. **`regression/avm1_attached_clip_*`** have no `[image_comparisons]`. The probes have no visible shapes.
