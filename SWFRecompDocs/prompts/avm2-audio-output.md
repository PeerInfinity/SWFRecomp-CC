# Session prompt — AVM2 real audio output (browser-WASM Seedling)

You are wiring **real audio output** for the AVM2 runtime. Stage 10
(`avm2-stage10-audio` memory, prompt `avm2-stage10-audio.md`) built the full
flash.media surface — Sound / SoundChannel / SoundTransform / SoundMixer in
`SWFModernRuntime/src/avm2/avm2_media.c` — but **trace-graded only**: nothing
ever reaches a speaker. The browser-WASM Seedling demo (Stage 13, live keyboard
done 2026-07-15) is currently silent. This session makes it audible.

Read first: `avm2/_investigation/CURRENT_STATUS.md`, memories
`avm2-stage10-audio` (SoundTransform i32×100 core, data_size semantics,
deferred list), `web-audio-emscripten` (HEAPF32 export, init order,
AudioContext resume), `avm2-stage13-browser-13a` (browser entry + deploy),
`audio_start_sound_dedup` (AVM1 browser StartSound behavior — do not break).

Baseline: master `d62debae3`; avm2 suite 846 effective / 1206 (70.1%),
filtered 74.4%. Zero pass→fail regressions expected in BOTH CI modes.

## The exact gap (verified 2026-07-16)

- `SWFModernRuntime/src/audio/audio.c` is a complete AVM1 mixer: minimp3
  decode, `audio_init` / `audio_define_sound` / `audio_start_sound` /
  `audio_stop_all_sounds` / `audio_mix`, 32 channels, MP3 + uncompressed
  formats, all `#ifndef NO_GRAPHICS`. `audio_output_web.c` is the Web Audio
  sink (`audio_output_init`).
- `SWFRecomp/scripts/build_wasm_avm2.sh:74` **already compiles both files into
  the AVM2 WASM build** — but nothing in `src/avm2/` or the AVM2 entry path
  calls `audio_output_init` or feeds the mixer. Linked, never used.
- `Avm2SoundData` (`include/avm2/avm2_abc.h:387`) is **metadata-only** — no
  payload pointer. The recompiler (`SWFRecomp/src/abc/abc_timeline.cpp`) must
  additionally emit DefineSound payload bytes. MP3 is already compressed —
  emit raw, no zlib needed (this is NOT the 46 MB RGBA situation; Seedling's
  88 sounds are small). NOTE: `data_size` today means *bytesTotal* (excludes
  the 2-byte MP3 seek prefix, Ruffle SoundInstance.size) and trace tests grade
  it — keep that field's semantics; add a separate payload ptr/len for the
  full decodable bytes. Table format change ⇒ REBUILD the recompiler and run
  BOTH CI modes (Stage-10 precedent).

## Tasks (suggested order)

1. **Payload emission**: `abc_timeline.cpp` emits DefineSound bytes; extend
   `Avm2SoundData` (keeping `data_size`/bytesTotal untouched); regenerate +
   recompiler rebuild; Seedling recompile smoke (binary size sanity).
2. **Mixer bridge**: at AVM2 boot register each `avm2_generated_sounds` entry
   via `audio_define_sound`; `SoundChannel.play` → `audio_start_sound`
   (startTime, loops — play() semantics like startTime>length→null already
   exist in avm2_media.c, don't re-derive); `SoundChannel.stop` +
   `SoundMixer.stopAll` → mixer stops; apply SoundTransform volume/pan at mix
   time (channel volume from the i32×100 core store ÷100; extend the mixer's
   per-channel state if AVM1's SOUNDINFO envelope path doesn't already fit).
3. **Browser init**: call `audio_output_init` in the AVM2 browser-WASM entry
   BEFORE renderer init (the `web-audio-emscripten` gotchas are real: HEAPF32
   in EXPORTED_RUNTIME_METHODS, renderer's emscripten_sleep eats the autoplay
   gesture, register resume listeners). Mirror however the AVM1 browser entry
   sequences it.
4. **Position + SOUND_COMPLETE** (stretch): SoundChannel.position from the
   mixer playback clock; dispatch Event.SOUND_COMPLETE when a channel drains.
   `soundchannel_position` / `soundchannel_soundcomplete` are upstream
   known_failure (ignored) — try them, but they do NOT gate the session.

## Exit criteria

- **Seedling browser demo plays music + SFX** (deploy via
  `SWFRecomp/scripts/deploy_wasm_avm2.sh`; docs2 redeploy per the
  `docs2-demo-redeploy-catalog-type` memory). Keyboard/gameplay unchanged.
- **Zero trace-output change**: audio must be inert in trace grading. BOTH CI
  modes zero pass→fail (shared runtime + recompiler table change ⇒ both
  modes per CLAUDE.md); wasm-link-smoke green.
- Native no-graphics build untouched behaviorally (`audio.c` is already
  `#ifndef NO_GRAPHICS`-gated — keep it that way).

## Boundaries

- Do NOT touch `action.c` or AVM1 `tagStartSound` behavior (dedup semantics in
  the `audio_start_sound_dedup` memory must survive).
- Do NOT reopen `bd_draw` / render code.
- Still deferred (do not chase): SoundMixer cross-frame accumulation tests,
  Sound.load network tests, the shared_object two-run .sol harness.

Finish with the full pipeline per `.claude/pipeline-handoff.md`: commit to
master, push, dispatch `ruffle-tests.yml` in **both** modes, watch, merge
results, report regressions by name. Update CURRENT_STATUS.md + write a memory.
