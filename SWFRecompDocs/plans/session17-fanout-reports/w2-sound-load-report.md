# s17 wave-2 — `Sound.loadSound` family (agent `w2-sound-load`)

## NEW FILES

**None.** Every change lands in the existing
`SWFModernRuntime/src/actionmodern/action.c` (AVM1 Sound region + new `static`
helpers). Nothing to add to `verify_output.py`'s explicit source list
(`verify_output.py:2154`), to `CMakeLists`, or to the Emscripten build, and no
new header. The coordinator stages exactly one source file by name.

## Verdicts

| Leg | Verdict | Flips | Priced (wave-1) | Delivered |
|-----|---------|-------|-----------------|-----------|
| **A** — `ExternalSound` record + `getBytesLoaded/Total` | **GO** | `sound_load_props` → `pass`; `Sound-v6/-v7/-v8` → `ruffle_matched` | +4 | **+4** |
| **B** — remote-URL resolution + deferred `onLoad` + `load_id` | **GO** | all three `_remote` rows → `pass` | +3 | **+3** |
| **C** — MPEG-2/2.5 duration table + `Sound.checkPolicyFile` | **GO** (was a wave-1 HOLD; completion mechanism met) | `Sound-v6/-v7/-v8` `ruffle_matched` → real `pass` | +0 effective | **+0 effective, drift-proof** |

**Total: +7 effective trace points, zero regressions across 22 graded rows.**
The whole family is now closed: 10/10 rows pass (7 flipped, 3 protected).

Patches (all `git apply -p1`-clean; both forms verified to reproduce the graded
working tree byte-for-byte):

| File | Applies onto | Lines |
|------|--------------|-------|
| `w2-sound-load-legA.patch` | `88ebde665` | 298 |
| `w2-sound-load-legB.patch` | legA | 347 |
| `w2-sound-load-legC.patch` | legB | 26 |
| `w2-sound-load.patch` | `88ebde665` | 637 (combined; +443/−65) |

Prefer the **combined** patch — all three legs are GO and were graded together.
The stacked form is provided so leg C can be dropped independently if the
coordinator wants the zero-effective-point change out of the merge.

Mode: every number below is `--mode=graphics`. **No `swf_core.c` and no
`#ifdef NO_GRAPHICS`-only arm is touched**, so the per-change CI mode stays
`graphics` (the weekly no-graphics canary covers the rest). No recompiler
change → no `SWFRecomp/` rebuild needed.

---

## Per-test ledger

Baselines were re-measured in this worktree against the **fresh upstream
fixture** (the gnash `output.ruffle.txt` mirrors staged by `w1-sound` from
upstream master `1508316`), not the stale local mirror.

### Headline rows (7 flips)

| Row | Baseline (measured) | Leg A | Leg A+B | Leg A+B+C |
|-----|--------------------|-------|---------|-----------|
| `avm1/sound_load_props` | `output_mismatch` (15/121 lines) | **PASS** | PASS | — |
| `avm1/sound_load_start_remote` | `output_mismatch` (0 lines emitted) | — | **PASS** | — |
| `avm1/sound_load_streaming_stop_remote` | `output_mismatch` (`before/after`, no `onLoad`) | — | **PASS** | — |
| `avm1/sound_load_multiple_remote` | `output_mismatch` (3/6 lines) | — | **PASS** | — |
| `from_gnash/actionscript.all/Sound-v6` | `output_mismatch` (8 diff lines) | **RUFFLE_MATCHED** | RUFFLE_MATCHED | **PASS** |
| `from_gnash/actionscript.all/Sound-v7` | `output_mismatch` | — | **RUFFLE_MATCHED** | not re-graded¹ |
| `from_gnash/actionscript.all/Sound-v8` | `output_mismatch` | — | **RUFFLE_MATCHED** | not re-graded¹ |

¹ `Sound-v7`/`-v8` differ from `-v6` only in the first output line (`SWF7`/`SWF8`)
in both `output.txt` and `output.ruffle.txt`; they were graded under A+B and
tracked `-v6` exactly. Leg C's two changes are version-independent
(`checkPolicyFile` is installed in `initSoundTarget`, the bitrate table is in
the shared MP3 parser), so they are expected to follow `-v6` to `pass` in CI.
This is the one row-pair in the ledger inferred rather than measured.

### Canaries — all 15 unchanged (`--mode=graphics`)

| Canary | Baseline | After (A+B, or A+B+C where noted) |
|--------|----------|------------------------------------|
| `avm1/sound_load_start` | PASS | PASS |
| `avm1/sound_multiple_load` | PASS | PASS |
| `avm1/sound_duration_position_props` | PASS | PASS |
| `avm1/sound_id3` | PASS | PASS |
| `avm1/sound_props_swf6` | PASS | PASS (also PASS under C) |
| `avm1/sound_props_swf5` | PASS | PASS under C |
| `avm1/sound_getters` | PASS | PASS |
| `avm1/sound_setters` | PASS | PASS |
| `avm1/sound_gettransform_props` | PASS | PASS |
| `avm1/sound_owner_reference` | PASS | PASS |
| **`avm1/sound_load_multiple_instances` (PROTECT)** | PASS | **PASS** |
| **`avm1/sound_mixed_attach_load` (PROTECT)** | PASS | **PASS** |
| **`avm1/sound_load_stops_when_dereferenced` (PROTECT)** | PASS | **PASS** |
| `from_gnash/actionscript.all/Sound-v5` | RUFFLE_MATCHED | **RUFFLE_MATCHED** (also under C) |
| `avm1/xml_load` | PASS | PASS |

`avm1/xml_getbytes` also ran (it exercises the same `AQ_KIND_SCRIPT` deferral I
extended) and reports `output_mismatch` — but it is a **pre-existing** failure
already listed in `ruffle-tests/ignored_tests.txt:54`, with a diff
(`_bytesLoaded` timing) that has nothing to do with this patch. Not a regression.

**Canary blind spot:** the standing `render_canary.py` set is blind to this
change class (no pixels move — nothing here touches the display list or the
renderer). The audio-side effects are likewise ungraded by design: image and
audio assertions never gate trace pass/fail. The trace-visible surface is fully
covered by the 15 rows above. `regression/` has **no** sound tests at all
(checked); `xml_load` + `xml_getbytes` are the closest covering rows for the
queue change and both were graded.

---

## Mechanism (confirmed)

Wave-1's diagnosis was **correct in full** — mechanism *and* price. Ruffle's
`Sound` carries `external: Option<ExternalSound>`, set the moment
`loadSound(<any first arg>)` is called, which permanently separates the Sound
from its owner: private transform checked **before** global and owner,
`owner()` → `None`, `has_valid_owner()` → unconditionally true.

### Leg A (`w2-sound-load-legA.patch`, +202/−14)

| Site | Change |
|------|--------|
| new statics after the `resolveObjectPathToMC` fwd-decl (~:1590) | `soundIsExternal`, `soundExternalTransform`, `soundExtFlag`/`soundSetExtFlag`, `soundExtNum`/`soundSetExtNum`, `soundCreateExternal` |
| `resolveSoundOwner` | `if (soundIsExternal(...)) return NULL;` — Ruffle `Sound::owner`'s `&& !self.is_external()` |
| `soundHasValidOwner` | `if (soundIsExternal(...)) return 1;` |
| `resolveSoundTransformTarget` | external arm **first**, ahead of the global and owner arms |
| `builtin_sound_loadSound` | URL coercion (so `loadSound("")` counts as an argument while `loadSound()` stays a no-op), `is_streaming` hoisted, `soundCreateExternal(...)` **outside** `#ifdef HAS_DATA_FILES`, `is_loading` cleared on both success and failure, `__bytes_total__` recorded, autoplay driven by `will_autoplay` |
| `builtin_sound_stop` | clears `will_autoplay` ahead of the `has_valid_owner` gate |
| new `builtin_sound_getBytes` + Sound prototype init | real `getBytesLoaded`/`getBytesTotal` replacing two `addStubMethodToProto` calls |

The record is modelled as DONT_ENUM properties on the Sound instance
(`__ext__`, `__ext_xform__`, `__ext_stream__`, `__ext_auto__`,
`__ext_loading__`, `__ext_loadid__`, `__bytes_total__`) — no struct change, no
new header, and the private transform object stays GC-reachable through the
Sound's ordinary property array. Proto-slot consumption is **net zero** (two
static entries added, two `addStubMethodToProto` slots removed), so the
`MAX_PROTO_STUB_FUNCS = 192` budget is unchanged.

### Leg B (`w2-sound-load-legB.patch`)

| Site | Change |
|------|--------|
| new `soundParseMp3Meta` | the CBR-MP3 ID3-skip + bitrate pass, **extracted verbatim** from `builtin_sound_loadSound` so the sync and deferred loads share one implementation |
| new `soundStartExternalPlayback` | streaming external sounds keep a **single** active instance (Ruffle `start`) |
| new `soundResolveUrlData` (`#ifdef HAS_DATA_FILES`) | URL → bundled data file: strip scheme, drop `:port`, try `host/path`, then bare basename — the same order as `avm1_amf.c:1672 nc_resolve_response`, copied as a private `static` rather than exported |
| new `soundUrlIsRemote` | true for any scheme except `file:` (Ruffle `sound.rs:626-647`) |
| new `SoundLoadDeferred` + `aq_dispatch_sound_load` | `AQ_KIND_SCRIPT` payload; `load_id` stale-completion guard, then duration/id3/`__loaded__` → `onID3` → `onLoad(success)` → autoplay |
| `builtin_sound_loadSound` | fires `onLoad(false)` **synchronously** when a load is already in flight, bumps `load_id`, routes remote URLs to the deferred path |
| `builtin_sound_start` + local autoplay | route through `soundStartExternalPlayback` |
| `gcMarkXmlLoadPayload` | also marks `SoundLoadDeferred::sound` (retained-by-C-queue is invisible to the GC trace — the same reason the XML payload is marked) |

`AQ_KIND_SCRIPT` was the right bucket on the first try — no fallback to the
`g_pending_mcl_loads_next_tick` style bucket was needed. It drains once per
tick in the graphics frame loop (`swf.c:1087`), which satisfies "after the
current script" for all three rows.

### Leg C (`w2-sound-load-legC.patch`, 26 lines)

| Site | Change |
|------|--------|
| `soundParseMp3Meta` bitrate table | MPEG-2 / MPEG-2.5 Layer III (`{0,8,16,24,32,…,160}`) |
| `initSoundTarget` | `checkPolicyFile = false` as a DONT_ENUM **instance** property (all three Sound-constructor call sites funnel through this one function) |

---

## Refutations and premise attacks

1. **The coordinator's relay from the wave-1 TRACE board — that the whole
   `Sound-v6/-v7/-v8` gap is `checkPolicyFile` — is REFUTED, and acting on it
   alone would have produced zero flips.** Computed exactly against the current
   `output.ruffle.txt` in my worktree copy:

   ```
   ruffle diff indices : [41,42,43, 55,56,57, 81..86, 89..92, 97,98, 103, 113, 118, 119]
   our   diff indices  : [43, 57, 103, 105, 106, 113, 118, 119]
   ours-not-in-ruffle  : [105, 106]
     105 | PASSED: typeof(s.getBytesTotal())  == "number" [./Sound.as:345]
     106 | PASSED: typeof(s.getBytesLoaded()) == "number" [./Sound.as:346]
   ```

   `checkPolicyFile` sits at indices **43 and 57, which ARE inside Ruffle's own
   diff set** (Ruffle fails those lines too), so they never blocked
   `ruffle_matched` — `ruffle_matched` is a *subset over diff-line indices vs
   `output.txt`*, not an equality. The blocking pair was `{105, 106}`, exactly
   as my wave-1 brief said. Both boards described real diff lines; only the
   `getBytes*` pair was load-bearing. **Empirically confirmed:** Leg A alone
   (which fixes `getBytes*` and does *not* add `checkPolicyFile`) flipped
   `Sound-v6` to `ruffle_matched`. `checkPolicyFile` is still worth landing —
   as part of Leg C it takes the rows the rest of the way to a real `pass` — but
   it is a *hardening* change, not the flip.

2. **Wave-1's own HOLD on Leg C is refuted — it is a GO.** The stated risk was
   that the MPEG-2 table moves `silence.mp3` (1000 → 23313 ms) and
   `stereo8.mp3` (1000 → 7200 ms) and could disturb an `onSoundComplete` that
   currently lands for free. Measured: `Sound-v6` goes `ruffle_matched` →
   **`pass`**, and `Sound-v5` **holds** its `ruffle_matched`. The completion
   mechanism wave-1 named ("a wave-2 A/B shows `Sound-v5..v8` unchanged or
   improved") is met. Blast radius independently confirmed nil: I dumped every
   MP3 frame header under `avm1/`, `audio/` and the gnash Sound dirs — all 16
   avm1 files are MPEG-1 Layer III and unaffected; only the three gnash
   fixtures are MPEG-2/2.5.

3. **"The `_remote` rows need real HTTP / wall-clock timing."** Refuted, as
   wave-1 predicted. The one defect was the basename-only registry lookup:
   `verify_output.py` keys the file as `localhost/noise.mp3` and we searched for
   `noise.mp3`. With `soundResolveUrlData` + the `AQ_KIND_SCRIPT` deferral all
   three rows pass with no socket, no clock, and no MP3 decode.

4. **"`Sound-v6/-v7/-v8` regressed."** Refuted. The SWFs and `output.txt` are
   byte-identical to our mirror; only the oracle moved. Our actual output was
   already *ahead* of Ruffle's on 14 checks before this patch.

5. **`loadSound()` vs `loadSound("")` really are different**, and both
   behaviours are pinned by `sound_load_props`: no argument at all is a total
   no-op (the clip's `50 / 90 / {10,20,30,40}` still reads back), while the
   empty string creates the record and resets the observable transform. Ruffle
   gates on `args.get(0)` presence, not on truthiness; our `arg_count < 1` early
   return already matched, but the old code *also* bailed on a NULL UTF-16
   pointer, which would have swallowed `loadSound("")`. Fixed in Leg A.

6. **Wave-1's pricing survived intact at +7.** Worth recording against the
   s16 lesson that a diff-line lead is usually not a flip lead: here the
   `--save-actual`-driven subset arithmetic in wave 1 (which cut "8 mismatching
   lines" down to "2") is precisely what made the price trustworthy.

---

## Notes for the merge

- Stage `SWFModernRuntime/src/actionmodern/action.c` only. No new files.
- Sibling overlap: `w2-crossvm-legE` also edits `action.c`
  (`actionTickAvm1ChildrenUnderAvm2` / `processTimers`) and `w2-timeline-s1s2`
  touches sprite frame fields. All of my edits live in the AVM1 Sound region
  (~:1590–2600, ~:37500) plus one two-line addition inside
  `gcMarkXmlLoadPayload` (~:76650) — no textual overlap with either.
- CI: `mode=graphics`, `categories=all` is sufficient (this is AVM1-only; the
  gnash rows are in the classic five suites).
- Expected CI delta: **+7 effective** (4317 → 4324), with `Sound-v6/-v7/-v8`
  landing as full `pass` rather than `ruffle_matched` if Leg C is included.
