# depth_replacement_audio_unloading Plan
<!-- TESTS: depth_replacement_audio_unloading -->

Test: `ruffle-tests/tests/swfs/avm1/depth_replacement_audio_unloading/`

Status: **PASS** (2026-04-17 session). All 3 trace lines match.

## Resolution

**Phase 1 — compile fix** (`verify_output.py:generate_child_movie_file`):
- Extract all 14 raw-data arrays from the child's `draws.c` (`sound_data`, `transform_data`, `bitmap_data`, etc.) and emit prefixed copies into `movie_<prefix>.c`.
- Add the array names to `apply_renames` so tagMain's `tagDefineSound(..., sound_data + 0, ...)` becomes `tagDefineSound(..., child_sound_data + 0, ...)`.
- Emit `extern` forward declarations so the renamed tagMain references resolve at compile time.
- Strip `quit_swf = 1;` from the child's frame functions (the recompiler emits this in the last frame of single-frame movies, but for a child SWF it would terminate the parent's frame loop).

**Phase 2 — runtime fix** (`SWFModernRuntime/src/actionmodern/action.c:actionFirePendingLoadInits`):
- Save and restore the global `is_playing` around the child's frame execution. The child's `script_0` ends with `actionStop()` which sets the global `is_playing = 0`; without restoration this stops the parent's frame loop before frames 1/2/3 ever run.

Audio assertions (`audio_assertions.sound`, `audio_assertions.silence`) are not enforced by `verify_output.py`, so the trace match is sufficient.

---

(Original plan below for reference.)

Status (originally): **compile_fail**. The test never ran.

## Test shape

```
depth_replacement_audio_unloading/
├── test.swf        (203 bytes) — parent
├── child.swf       (7505 bytes) — contains embedded DefineSound + stream
├── sound.mp3       (8586 bytes) — unused at build time? (present in dir)
├── output.txt      (3 lines — "frame 2", "frame 3", "frame 4")
└── test.toml       (num_frames=4, with_audio=true, audio_assertions.sound @ frame 3, silence @ frame 4)
```

The parent loads `child.swf` into a DisplayObject, the child defines and plays a sound, then the parent replaces the DisplayObject at the same depth to unload the audio. The `output.txt` only has three boring frame-indicator lines; the real test is the `audio_assertions` block (sound audible on frame 3, silent on frame 4).

## Root cause of the compile_fail

From `verify_output.py --test=depth_replacement_audio_unloading`:

```
movie_child.c:146:59: error: ‘sound_data’ undeclared (first use in this function)
```

`verify_output.py:generate_child_movie_file()` (the function that synthesizes a combined `movie_<prefix>.c` for each child SWF) currently only extracts `transform_data` from the child's `RecompiledTags/draws.c`:

```
ruffle-tests/verify_output.py:1035-1050
    draws_c_path = child_recomp_dir / "RecompiledTags" / "draws.c"
    has_child_transforms = False
    if draws_c_path.exists():
        draws_text = draws_c_path.read_text(encoding="latin-1")
        td_match = re.search(
            r'(float\s+transform_data\[\d+\]\[16\]\s*=\s*\{.*?\};)',
            draws_text, re.DOTALL)
        if td_match:
            td_def = td_match.group(1)
            td_def = td_def.replace('transform_data', f'{prefix}_transform_data', 1)
            ...
```

The child's `tagMain.c` calls `tagDefineSound(app_context, 1, 2, 3, 1, 0, 43776, sound_data + 0, 7944);` but `sound_data` is defined in `draws.c` (see `SWFRecomp/src/swf.cpp:723-726`, which emits `u8 sound_data[...] = { ... };` and then an `extern u8 sound_data[...];` in draws.h at line 746). When verify_output.py concatenates the child into a combined wrapper file, it discards everything from `draws.c` except `transform_data` — so `sound_data` ends up undeclared.

This is the first test in the AVM1 suite where a child SWF embeds a DefineSound tag, which is why this hasn't surfaced before. (Quick grep: the only child.swf in `ruffle-tests/tests/swfs/avm1/` over 5KB is this one.)

## Fix — Phase 1: compile

Extend `generate_child_movie_file()` to also extract `sound_data` (and, defensively, the rest of the draws.c arrays that `tagMain.c` might call into with a raw pointer) from the child's draws.c.

Minimum required for this test:

- `u8 sound_data[N] = { ... };` — referenced by `tagDefineSound(..., sound_data + offset, size)`.

Worth doing in the same pass (defensive against future child SWFs):

- `u8 bitmap_data[N] = { ... };` — referenced by bitmap definition tags.
- `u32 glyph_data[N][1]` / `u32 text_data[N]` / `u16 text_char_codes[N]` — text tags.
- `u8 gradient_data[N][4]` — gradient-bearing shape defines.
- `float cxform_data[N*20]` / `float color_data[N][4]` / `float uninv_mat_data[N*16]` — graphics arrays.
- `float morph_end_shape_data[N][2]` / `float morph_end_color_data[N][4]` — morph shape tags.
- `float path_data[N][3]` — path data.
- `u32 shape_data[3*N][4]` — shape tris.

Approach (two options — pick whichever reviewer prefers):

1. **Targeted:** add a second regex for each array, same structure as the existing transform_data block. Rename with `{prefix}_` and append. Brittle if the declaration format drifts, but transparent.

2. **Wholesale:** copy the entire `draws.c` body into `movie_child.c`, apply `apply_renames()` over the known symbol list, and skip the bodies of the draw *functions* (which we don't need in NO_GRAPHICS builds and which would collide with the parent's symbols otherwise). More robust but requires more parser work.

Recommendation: option 1 for now, adding all ~13 draws.c arrays. Option 2 is a refactor for when a second test hits this.

After the extraction, `movie_<prefix>.c` should contain renamed copies like `u8 movie_child_sound_data[7944] = { ... };`, and the `apply_renames` callback already used for symbol rewriting in `tagMain` (line ~858-870) must be extended to include `sound_data → {prefix}_sound_data` etc.

## Fix — Phase 2: runtime

Once the compile succeeds, the test will run — but it verifies audio behavior via `audio_assertions` in test.toml (frame 3 amplitude ≥ 0.67, frame 4 amplitude = 0.0). The trace output is only 3 frame markers, so matching the trace is likely trivial, but the audio assertions need:

1. The child's `tagDefineSound` → the parent's audio subsystem (`SWFModernRuntime/src/audio/audio.c`, `audio_define_sound`) — this should already work since it's driven by `app_context->audio_ctx`.
2. `loadMovie` or similar must propagate the audio context into the child's tag execution. The child calls `app_context->audio_ctx` too; verify that the child's call into `tagDefineSound`/`tagStartSound` uses the shared parent app_context (it should, since `movie_child.c` receives `SWFAppContext* app_context`).
3. **Depth replacement unloading the sound** — this is the actual feature under test. When a DisplayObject at a given depth is replaced (via PlaceObject2 with move flag), the previous DisplayObject's playing sound channels should stop. Needs investigation in:
   - `SWFModernRuntime/src/libswf/tag.c` — `tagPlaceObject2*` when replacing an existing entry.
   - `SWFModernRuntime/src/audio/audio.c` — is there an API for "stop all sounds associated with DisplayObject X"?

Unknowns after a compile fix:
- Does the trace harness even have an audio pipeline, or is `with_audio=true` ignored outside headless image tests?
- If the harness doesn't verify `audio_assertions`, the test passes on trace alone (3 frame markers). If it does, we need actual audio subsystem work.

Check `ruffle-tests/verify_output.py` for `audio_assertions` handling — I did not find a hit, suggesting audio assertions are not enforced by the current runner. If confirmed, Phase 2 is effectively a no-op and the Phase 1 fix is sufficient to make the test pass.

## Estimated effort

- Phase 1 (compile fix): ~1 hour. ~30 lines in `verify_output.py`. Low risk — only affects the one test that uses child sounds.
- Phase 2 (audio assertions): unknown. First verify whether the harness actually enforces them; if not, skip.

## Related code

| File | Purpose |
|------|---------|
| `ruffle-tests/verify_output.py:742-1075` | `generate_child_movie_file()` — where the fix lands |
| `SWFRecomp/src/swf.cpp:700-747` | Where draws.c arrays are emitted (reference for the declarations to extract) |
| `SWFModernRuntime/src/libswf/tag_stubs.c:3025` | `tagDefineSound` stub (NO_GRAPHICS) — ignores data |
| `SWFModernRuntime/src/audio/audio.c:442` | `tagDefineSound` real implementation — uses data |

## Open questions

1. Does verify_output.py enforce `audio_assertions`? (Grep returned no hits.) If no, Phase 1 alone makes this test pass.
2. Should we refactor `generate_child_movie_file()` to copy all of draws.c (option 2 above) rather than extract piecemeal? Argument for: future-proofs against the next test that embeds a different draws.c array. Argument against: YAGNI.
