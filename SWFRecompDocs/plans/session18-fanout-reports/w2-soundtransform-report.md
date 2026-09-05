# w2-soundtransform — wave-2 report (session 18)

**Verdict: GO, delivered. +2 flips, both confirmed in `--mode=graphics` (the CI grading
mode) and in no-graphics.** Brief's premise (w1 §1 G4) survived intact on mechanism, on
magnitude, and on file ownership — with one correction to a *different* document (the
`ignored_tests.txt` entry's own diagnosis was wrong about the owner class).

## NEW files (coordinator stages these by name)

- `SWFRecompDocs/plans/session18-fanout-reports/w2-soundtransform.patch`
- `SWFRecompDocs/plans/session18-fanout-reports/w2-soundtransform-report.md` (this file)

No new source files, no new `.h` (the one new declaration goes into the existing
`avm2_globals.h`), so nothing to add to `verify_output.py`'s source list, CMakeLists or
the Emscripten build.

## Patch scope (4 files, +44/−16)

| file | change |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c` | REMOVE the single `soundTransform` registration on `InteractiveObject` (~:15914); ADD the per-object pair (`do_get/set_sound_transform`) on **Sprite**, immediately after the `graphics` getter in the Sprite block; ADD one call `avm2_media_register_mixer_transform(ctx, button)` at the end of the **SimpleButton** block (after `trackAsMenu`). |
| `SWFModernRuntime/src/avm2/avm2_media.c` | NEW exported one-liner `avm2_media_register_mixer_transform()` directly after `sm_set_sound_transform`, registering the existing static `sm_get/sm_set_sound_transform` pair as an *instance* accessor on a given class. |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | declaration for the above, next to the existing `avm2_media_*` bridge declarations. |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | remove the `soundmixer_soundtransform` entry; its comment block is rewritten as a `PRUNED 2026-09-04` note that also records what the old diagnosis got wrong. |

**Self-localization.** All three source edits sit in the builtin **class-registration**
region of `avm2_display.c` (Sprite block / SimpleButton block) plus one removal in the
`InteractiveObject` block — textually disjoint from every sibling's region per
`SIBLING_FILE_MAP.md`: w2-avm2-stage (Stage block, which begins *after* my SimpleButton
line), w2-avm2-timeline / w2-avm2-new-smalls (`addFrameScript`, Mouse, MovieClip),
w2-matrix3d (Vector3D), the gfx agents (render walk / drawing). `avm2_media.c` has no
other claimant this wave. **Note for the coordinator:** the brief and the file map say
"`avm2_display.c`/`avm2_sound.c`" — **there is no `avm2_sound.c`**; the flash.media family
lives in `avm2_media.c` (the w1 diagnosis had this right).

## Mechanism (confirmed, not assumed)

Flash declares `soundTransform` on **Sprite** and on **SimpleButton** only — never on
`InteractiveObject`/`DisplayObjectContainer`. Sprite's is a per-object transform
(`~/CC/ruffle/core/src/avm2/globals/flash/display/sprite.rs:119-147`); SimpleButton's is
literally the mixer's — `display/simple_button.rs:13` re-exports
`sound_mixer::{get_sound_transform, set_sound_transform}`, and
`flash/media/sound_mixer.rs:15-19` documents the double duty in a comment.

We had one registration on `InteractiveObject` using the per-object pair, so **every**
InteractiveObject (SimpleButton and TextField included) got a private transform and the
button↔mixer identity was lost in both directions. That single wrong owner produced both
board rows, which are the *same* fixture (49 frames, one `noise.mp3` + one `silence.mp3`,
two DefineButton players) mutated from opposite ends:

- `simplebutton_soundtransform` writes `silence_player.soundTransform` / 
  `noise_player.soundTransform` and reads back `SoundMixer.soundTransform` and the other
  button → 58 lines missing the global.
- `soundmixer_soundtransform` writes `SoundMixer.soundTransform` and reads back the two
  buttons → 12 lines missing the propagation.

Direct evidence that the players are SimpleButtons (this is the load-bearing fact, and it
is the one the old ignore-list entry got wrong) —
`ruffle-tests/tests/swfs/avm2/soundmixer_soundtransform/RecompiledTags/tagMain.c:13-15`:

```c
tagDefineButton(app_context, CHARID(4), button_4_state_funcs, CHARID(1), 5, NULL, 0);
tagSetInstanceName(app_context, 3, "silence_player");
```

`pan` needed nothing: it is derived inside `st_from_core`, and every expected `pan`
(0.9936 / 0.9856 / 0.9744) fell out correctly once the source values were right.

## Per-test before → after

Local runs at worktree HEAD (`8f68a5fea` + this patch), `SWFRECOMP_COMPILE_TIMEOUT=2400`,
never more than 2 test processes at a time.

| test | mode | before | after |
|---|---|---|---|
| `avm2/simplebutton_soundtransform` | no-graphics | `output_mismatch` 829/887 | **PASS 887/887** |
| `avm2/soundmixer_soundtransform` | no-graphics | `output_mismatch` 888/900 | **PASS 900/900** |
| `avm2/simplebutton_soundtransform` | **graphics** | `output_mismatch` (CI baseline `f00041501`) | **PASS** |
| `avm2/soundmixer_soundtransform` | **graphics** | `output_mismatch` (CI baseline `f00041501`) | **PASS** |

Both "before" no-graphics runs were executed here (logs
`<scratch>/w2-soundtransform/base_sb.log`, `.../tasks/bqjwpz720.output`) and show exactly
the 58- and 12-line shapes the w1 report priced — the pricing was exact, not approximate.

**Corpus effect: +2 graded, and +1 more on the *effective* number** because
`soundmixer_soundtransform` was in `avm2/ignored_tests.txt` (so it was excluded from the
filtered rate). After this patch it is graded *and* passing.

## Canary ledger — 15 tests, zero movement

All run in the worktree with `--recompile` on first use of each copied dir; every result
identical to the graphics CI baseline (`_results/results_graphics.json`, run `33902348100`).

| canary | baseline | after | why it was chosen |
|---|---|---|---|
| `avm2/movieclip_soundtransform` | pass 831/831 | **pass** | the per-object arm — proves Sprite/MovieClip kept a private transform |
| `avm2/soundchannel_soundtransform` | pass 835/835 | **pass** | SoundChannel's own pair (untouched) |
| `avm2/soundtransform` | pass 442/442 | **pass** | the SoundTransform value class |
| `avm2/soundmixer_buffertime` | pass 5/5 | **pass** | SoundMixer statics |
| `avm2/soundmixer_stopall` | pass 6/6 | **pass** | SoundMixer statics |
| `avm2/sound_play` | pass 19/19 | **pass** | Sound playback path |
| `avm2/simplebutton_childprops` | pass 144/144 | **pass** | SimpleButton property surface |
| `avm2/simplebutton_structure` | pass 27/27 | **pass** | SimpleButton property surface |
| `avm2/interactiveobject_enabled` | pass 25/25 | **pass** | the class I removed a member from |
| `avm2/describe_type_basic` | pass 152/152 | **pass** | reflection |
| `avm2/describe_type_json` | pass 301/301 | **pass** | reflection |
| `avm2/describe_type_native` | pass 23/23 | **pass** | reflection |
| `avm2/describe_type_metadata` | pass 125/125 | **pass** | reflection |
| `avm2/sprite_dropTarget` | ruffle_matched 6/19 | **ruffle_matched** | Sprite surface; unchanged status (not a `pass → ruffle_matched` drift — it was already `ruffle_matched`) |
| `regression/avm2_simplebutton_click` | pass | **pass** | mandatory regression-suite check, closest test to the change |

Canaries not run, with reason: `from_shumway/*sound*` — **none exist** (`find` over
`from_shumway` for `*sound*` returns nothing); regression-suite AVM2 sound tests — **none
exist** (`grep -rli 'soundTransform|SoundMixer'` over `tests/swfs/regression/*/` returns
nothing), so `avm2_simplebutton_click` is the nearest regression row and it was run.
`avm2/sprite_*` has only two members corpus-wide (`sprite_dropTarget`,
`sprite_with_frames`, the latter graded 0/0); the brief's "sample 5" is not available.
Canaries were run in no-graphics (trace parity holds everywhere except
`from_gnash/misc-swfc.all/gotoFrameFromInterval2`); the two headline rows were run in
BOTH modes.

## Refutations / corrections

1. **REFUTED — the `ignored_tests.txt` entry's diagnosis named the wrong owner.** It read:
   *"a WRITE to `SoundMixer.soundTransform` is not reflected in the per-`SoundChannel`
   `soundTransform` readback"*. There is no SoundChannel in the readback at all —
   `silence_player` and `noise_player` are `tagDefineButton` characters, i.e. SimpleButtons,
   and `soundchannel_soundtransform` was already passing 835/835 the whole time. Had the
   entry been believed, the work would have gone into `avm2_media.c`'s SoundChannel path
   and changed nothing. The rewritten PRUNED note in the file now records this.
2. **REFUTED (harmless half of the w1 claim) — the `describeType` bonus does not exist.**
   w1 §G4 says the change "also stops TextField from exposing a `soundTransform` Flash does
   not give it". True of the *live property surface*, but `describeType` output never came
   from the live vtable: it is table-driven (`dtd_m_InteractiveObject` declares the member,
   `dtd_r_{AVLoader,DisplayObjectContainer,InteractiveObject,Loader,Stage}` hide it,
   `dtd_r_{Sprite,MovieClip,SimpleButton}` re-declare it), and `avm2_globals.c:2640` says so
   explicitly. So `describeType` was already correct and is **unchanged** — confirmed by all
   four `describe_type_*` canaries. The `declared_by == NULL` hide rows are now dead weight
   (see unclaimed leads).
3. **CONFIRMED — pricing was exact.** w1 priced 58 + 12 diff lines and +2 flips; the
   measured baselines are 887−829 = 58 and 900−888 = 12, and both rows flipped whole. No
   row was limited by a second mechanism.
4. **CONFIRMED — one change, two flips.** The two rows are one fixture; a single owner move
   fixed both directions with no per-test special-casing.
5. **File-map correction:** `avm2_sound.c` does not exist (see Patch scope).

## New unclaimed leads

- **Dead `describeType` hide rows (faithfulness, zero test yield).** With `soundTransform`
  no longer registered on `InteractiveObject`, the member row `dtd_m_InteractiveObject`
  (`avm2_globals.c:3555`) and the four `declared_by == NULL` hide rows (`:3184` AVLoader,
  `:3415` DisplayObjectContainer, `:3562` InteractiveObject, `:3633` Loader, `:4006` Stage)
  describe a registration that is gone. They are *correct* output today only because the
  tables are self-contained. Moving the member row to `dtd_m_Sprite`/`dtd_m_SimpleButton`
  (both of which already carry their own row) and deleting the hide rows would make the
  tables model reality — but it is pure churn with a real chance of perturbing
  `describe_type_json`'s 301 lines, so it should be a deliberate, separately A/B'd cleanup.
  Note the comment block at `avm2_globals.c:2640-2643` explicitly documents the old
  "register once on InteractiveObject" arrangement and would need updating with it.
- **`Sprite.soundTransform` has no audio effect.** `do_set_sound_transform` only stores
  into `Avm2DisplayObjectExt.sound_transform` — nothing reads it back at mix time (grep for
  `sound_transform_set` finds only the getter/setter). The SimpleButton/mixer half *does*
  reach the mixer (`audio_set_master_volume`). Per-object volume/pan for a Sprite's child
  sounds is unimplemented; no corpus row grades it today, so this is a game-facing lead
  (a Sprite that dims its own sounds will play at full volume), not a corpus lead.
- **`SoundMixer` pan cross-gains are still unwired** at mix time (only `volume` reaches
  `audio_set_master_volume`; the comment at `avm2_media.c` says so). Trace-graded output is
  unaffected — the getters read back the stored i32×100 core — so this is audio-fidelity
  only.

## Reproduce

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400
export DAWN_INSTALL="$HOME/CC/dawn-install"   # worktrees resolve dawn-install one dir up
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
    --test=simplebutton_soundtransform --test=soundmixer_soundtransform \
    --mode=graphics --diff --verbose
```

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac6d56a55c07b70cc`.
Logs: `<scratchpad>/w2-soundtransform/`.
