# N: collector use-after-free on retry, browser EditText −2,−2 in attached clips (2026-11-22)

This one-task session follows `n-pixel-pass` (`n-pixel-pass-report.md` §9). It was launched by the s26 fan-out coordinator.
Baseline: master `b10973eba`. Landed: `440ecf35b` (collector UAF), `63d13990e` (browser EditText). The `action.c` half of
the EditText fix rode along in the coordinator's `9fa68316e`; the shared tree was committed whole there.

**Summary**
- **Goal 1, collector UAF: fixed at the root cause.**
  - Removing a clip took it out of the MovieClip registry (`child_mc_cache`, the collector's only MC-dprops root) but left `mc->dynamic_props` set.
  - The next `gcCollect` swept the object while the dead MC still pointed at it.
  - Minimized to a 30-line fixture, `regression/avm1_removed_clip_dprops_gc`: segfault → pass in both modes.
  - N level 1 with two retry resets under ASan is clean, and the player telemetry is identical to the Ruffle exporter.
- **Goal 2, browser EditText −2,−2: fixed, with a probe that went red → green.**
  - The real gap was bigger than the offset: in the browser, an EditText inside an attachMovie'd clip was **not drawn at all** until AS touched the field.
  - When something did create its wrapper early, the wrapper's `x/y` was seeded 0 instead of the placement, so a Flash-IDE field (bounds min −2,−2, placed at +2,+2) drew exactly 2 px up-left.
  - Probe: `wasm_probes/edittext_attached_origin`.
- Goal 3 (exec-order lead) not started; see §5.

## 1. Collector UAF (brief §4 A of `n-pixel-pass-report.md`)

**Repro on N** (recipe from the brief):
- Build: `START_LEVEL=1 OBJHASH=true AUTOKILL=true FREEZE="" n_drive/build.sh "100:-/100:R"`, then `run_native.py --asan`.
- Before the fix: heap-use-after-free READ in `actionEnumerate2` (the probe's `for (b in _root[a])`).
  - Freed by `gcCollect` ← `swfGcMaybeCollect` ← `tagMain`.
  - The crash comes right after the first retry reset.
- Note: `run_native.py` caps the run at 30 s, which is too short for ASan N past ~700 frames. Run `build/test_run` directly (`ASAN_OPTIONS=detect_leaks=0`).

**Minimized:** `ruffle-tests/tests/swfs/regression/avm1_removed_clip_dprops_gc/` (`Test.as`, `create_test_swf.sh`; golden = Ruffle exporter).
1. Create a clip with props and keep it in `_root.keep` and in an object slot.
2. `removeMovieClip()` it.
3. Enumerate it every 20 frames. The default collector runs at tick 60.

Results:
- Ours before the fix: `n=2` (the dead clip's props were still enumerable), then SIGSEGV after tick 60.
- Ruffle: `n=0` throughout.
- It also covers self-removal inside the clip's own `onEnterFrame`. Ruffle reads `this.tag` as undefined and enumerates nothing **in the same tick**, so detaching at removal time is the Ruffle-correct semantic, not just memory safety.
- The previous session's guessed repro "create, remove, recreate same name, enumerate" missed it because the recreate made `mcResolveSoftRef` rebind to the live clip. The dead clip was never read.

**Root cause.**
- `actionGcMarkRoots` marks MC `dynamic_props` only through `child_mc_cache` (memory `memory-reclamation-stage3-collector` rule 1).
- Every path that kills a clip and NULLs its cache slot without `actionDeferDpropsRelease` leaves an unrooted owning field:
  - `removeMovieClip`'s immediate (no-`onUnload`) branch, in both copies: `actionRemoveSprite` and the `actionCallMethod` arm, plus `actionRemoveSprite`'s descendant loop
  - `removeTextField`
  - the four replace-at-depth sites (`createEmptyMovieClip`, `attachMovie`, `createTextField`)
  - the `_apply_mc` removal
  - `tag_stubs.c clone_depth_evict`
  - `actionReclaimDeadChildMCSlots`
- Their comment "keep dynamic_props intact until pending unload fires" was stale. The `onUnload` (deferred) branch keeps the clip **in** the cache, and `actionFinalizePendingRemovals` already detaches it.

**Fix (`440ecf35b`).** Every registry exit calls `actionDeferDpropsRelease` first. The field is NULLed now and the free is deferred to the tick boundary, so the locals-borrow rule still holds.

**Verification:**
- Fixture passes in no-graphics and graphics.
- Local sweep of 44 avm1 remove/unload/duplicate/depth/replace/enumerate tests: unchanged. The 5 non-passes are `ruffle_matched` in the CI baseline and still `ruffle_matched`.
- N under ASan, 1400 frames: two full death → retry → reset cycles, zero ASan errors.
- Telemetry vs `exporter -f 1400`: 728/728 NF/ND lines. The only diffs are the known §4 B particle ticks (`h=` at t=56/58: ours keeps a pfx one tick longer).

## 2. Browser EditText in attached clips (brief §3 / §6.1)

**Probe:** `SWFRecomp/tests/wasm_probes/edittext_attached_origin/`.
- Built from `Probe.as` (MTASC) with a DejaVu-Sans "Hg" DefineFont2 and the EditText/sprite blocks spliced into `test.xml`.
- One Flash-IDE-style field (bounds min −2,−2, placed +2,+2), attached 12 ways:
  - into a buffer and onto `_root`
  - two buffers deep
  - touched or untouched from AS
  - `variableName`-bound
  - N's exact `timeIndicator` → `txtbox` → unnamed `variableName="txt"` field shape, with and without AS moving `txtbox`

| build | result |
|---|---|
| Ruffle exporter (golden) | all 12 boxes at their attach points |
| native graphics | all 12 correct (Phase B wrappers at placement) |
| browser, before | **only the 3 fields AS touched are drawn** (at the correct origin). The 9 untouched / var-bound fields, N's shape included, are missing: 2870 px, delta 255 |
| browser, eager wrappers only | all drawn, the 9 eager ones **exactly −2,−2**: 6772 px. This is N's bug |
| browser, both halves of the fix | 0 px over threshold (AA ≤ 64), trace exact → **pass** |

**Root cause.**
- (a) Browser-WASM skips `ng_on_place_object2`, whose Phase B creates every placed EditText's AVM1 wrapper. Without a wrapper, `actionIterateTextFieldGlyphs` never draws the field. `actionIterateOrphanTextFields` only walks the root display list, and in the browser attached clips are in no display list.
- (b) When a wrapper is minted before any AS transform sync, `findOrCreateMovieClip`'s nested-EditText `x/y` seed looks the parent up **by name in the root display list**. That fails for attached parents, so `x/y` stays 0 and the +2,+2 placement is lost. A later `.text`/`_x` access hid this through `syncTransformFromDisplayObj`, which is why touched fields looked right.
- The diagnostic run (enumerate every wrapper's `_x/_y/_parent`) showed the browser's AS-visible wrapper state was already identical to native. Only *when* wrappers were created differed.

**Fix.**
- `tag_stubs.c ng_attachMovie`, browser arm only: after the frame-0 build, `ng_eager_attached_textfield_wrappers` walks the attached subtree and find-or-creates each EditText wrapper, recursing through placed sprites. This is the browser twin of Phase B.
- `action.c findOrCreateMovieClip`: when the parent isn't in the root display list by name, the seed falls back to `parent->display_obj`'s own sprite list. This runs in every mode. Native already had `x=2` for these fields through Phase B's swapped globals.

Local sweep, unchanged against the CI baseline:
- 108 avm1 edittext/textfield/attach/tab/focus tests (4 `ruffle_matched`, as in the baseline)
- 25 regression attach/text/removed tests in graphics

**N itself:** see §3.

## 3. N browser re-check

Setup:
- Rebuilt `flasharchive/N_drive` (the same `n_drive.swf` as the previous pixel pass) for the browser at `63d13990e` + `9fa68316e`.
- Ran `n_drive_compare.py ours` and `n_drive_compare.py ruffle` (Ruffle web, frame-locked freeze shots).
- Binarised the glyph pixels and searched the best shift over ±4 px.

| shot | HUD timer (Ruffle px, XOR at best shift) | level name |
|---|---|---|
| a1t409 | 61 px, XOR **0** at (1,0) | 254 px, XOR **0** at (1,0) |
| a1t520 | 57, **0** at (1,0) | 254, **0** at (1,0) |
| a2t60 | 48, 3 at (1,0) | 204, **0** at (1,0) |
| a0t250 | 50, 26 at (1,0) | 254, **0** at (1,0) |

- (1,0) is the known 1-px horizontal canvas offset in the page (previous report §3, `ox=1`). The field offset itself is now **0,0**; it was −2,−2.
- The two non-zero timer XORs are digit differences of N's eased HUD timer between the players' shot frames, not position.

**N's HUD text is now pixel-exact with Ruffle in the browser.**

## 4. Side findings (not fixed)

- **TextField `_x` of a Flash-IDE field.** The probe's own trace shows `fld._x` = **2** in ours (native and browser) and **0** in Ruffle. The field is placed at tx=+2 with bounds xmin −2. Ruffle folds the bounds min into `_x`. Trace-visible. Check Flash before acting (`flash-over-ruffle` ruling); not in this probe's trace on purpose.
- `for (k in _root)` order differs from Ruffle (also noted in the previous report). Ruffle lists newest-attached first.
- Native ASan N runs exceed `run_native.py`'s 30 s run cap at ~1400 frames. Run `build/test_run` directly.

## 5. Next slice's line

1. The exec-order lead (previous report §4 B): attached clips that self-remove on their last frame vanish one tick late. It shows up as the only remaining N telemetry diff (`h=` at t=56/58 each attempt). Price it with a fixture first; land only with a broad argued sweep.
2. TextField `_x` = tx + bounds.xmin (§4): check Flash, then fixture.
3. After w2-attached-holder-render: the native 1:1 pixel pass.
4. Episode 0 levels 1–4 with routes that complete them, so thwumps and drones interact with the player.

## CI / Pages

- CI-observable: `440ecf35b`, and the `action.c` seed hunk in `9fa68316e`. Both were handed to the s26 coordinator for its grading run. No own dispatch.
- `63d13990e`'s `tag_stubs.c` half is browser-only.
- Pages: the coordinator deploys at closeout. N's HUD fix reaches the live demo only with that redeploy.
