# w2-soundtransform — wave 2: `SimpleButton.soundTransform` IS the global SoundMixer transform (+2)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-numerics-report.md` §1 G4. Isolated worktree; no commits.

## Scope
`avm2/simplebutton_soundtransform` 829/887 → pass and `avm2/soundmixer_soundtransform` 888/900 →
pass. Mechanism: we register `soundTransform` on InteractiveObject; per Ruffle (`sound_mixer.rs:17`,
`simple_button.rs:13` in `~/CC/ruffle/core/src/...`) it belongs on Sprite (per-object transform)
and on SimpleButton, where it IS the global SoundMixer transform. Also remove
`soundmixer_soundtransform` from `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` (and any
global-list entry) so it counts — read the entry's comment first and say what it claimed.

## Verification
Headline: the 2 tests. Canaries: `avm2/sound_*`, `avm2/soundmixer_*`, `avm2/soundtransform*`,
`avm2/simplebutton_*` (all passing ones), `avm2/sprite_*` (sample 5), `avm2/interactiveobject*`,
`from_shumway/*sound*`, and the `regression` suite's AVM2 sound tests. Byte-identical `--diff`
before/after. Run 2 in `--mode=graphics`. `-P 2`, compile timeout 2400, `--recompile` on first use.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-soundtransform.patch` + `w2-soundtransform-report.md`
(NEW files first; ledger; refutations; unclaimed leads). Copy to the main tree if allowed.
Runtime-only → copying `SWFRecomp/build` is valid.
