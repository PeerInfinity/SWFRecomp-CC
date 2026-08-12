# w2-host-io — session 14 wave-2: the avm2 host-I/O bucket, re-costed

**Agent:** wave-2 `host-io` (re-cost + implementation).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ae84d2b1a1bb40d8b`
(HEAD `0a99be1a9`; main tree read-only throughout, no `git stash` used).
**Board row:** T5 — "avm2 host-I/O bucket re-triage", est. up to **+5**, LOW-MED,
SMALL (`wave1-board-audit.md` §2.2 + §7).
**Baseline:** CI run `31130292354` at `fb36ba110`, trace 4237 effective; the five
targets' baseline rows read out of the merged
`ruffle-tests/tests/swfs/avm2/_results/results_graphics.json`.

**Result: +3 flips, 2 confirmed unwinnable.** The board's "+5, never re-costed"
framing is half right — three of the five were one missing detail each and are
now passing; the other two were already hard-dispositioned in a doc the board's
soft/hard split missed, and re-costing them only strengthened the ruling.

---

## 1. Per-test re-cost table

| test | baseline (e/a/m) | verdict | now |
|---|---|---|---|
| `avm2/netstream_flv_date` | 4 / 2 / 2 | **(a) TAKEABLE — landed** | **PASS** |
| `avm2/sound_rootless` | 7 / 5 / 5 | **(a) TAKEABLE — landed** | **PASS** |
| `avm2/sound_constructor_with_args` | 6 / 2 / 2 | **(a) TAKEABLE — landed** | **PASS** |
| `avm2/swz` | 2 / 0 / 0 | **(b) genuinely out of reach** — already dispositioned | unchanged |
| `avm2/loader_applicationDomain` | 4 / 0 / 0 | **(b) genuinely out of reach** — already dispositioned | unchanged |

Net predicted CI flips: **+3 effective** (three `output_mismatch` → `pass`),
stated net of the §2.1 corpus drift, which this work does not touch.

**Correction to the board.** §2.2 lists all five as *soft* ignores ("a
suite-local ignore entry with no doc backing"). Two of them —
`loader_applicationDomain` and `swz` — **are** doc-backed: `avm1/_investigation/
ACCEPTED_DIFFS.md` **Category 13 "AOT Ceiling — Runtime-Loaded ABC (Flex
`framework_*.swz`)"**, added 2026-08-06, and the ignore-file entry points at it
by name. The honest ceiling for T5 was **+3, not +5**, before any work started.
The "check the disposition docs first" rule (`accepted-diffs-first`) caught this
in the first ten minutes.

---

## 2. The three that were one detail each

### 2.1 `netstream_flv_date` — FLV script data is not media

**Diagnosis.** The test builds a `NetStream`, sets `client = {onMetaData:
function(data){ trace("running onMetaData"); trace(data["datedatedat"].valueOf()) }}`,
and calls `ns.play("result.flv")`. `NetStream.play` was `net2_noop`, so the two
constructor traces landed and nothing else did.

The premise the brief told me to attack — "gaps of 2-4 lines suggest one missing
detail, not a missing subsystem" — holds here, and the reason is worth writing
down because it is why bucket M mis-priced this row for two arcs:

> **An FLV's `onMetaData` tag is not media.** It is a plain AMF0 value sitting
> in a length-prefixed container. Reaching it needs a 30-line tag walk and the
> AMF0 reader we already ship (`avm2_amf0_read_value`, used by the
> NetConnection wire) — no demuxer, no decoder, no codec. `net-socket-arc.md`
> bucket M bundled it with `netstream_play_flv`/`netstream_seek_flv` (which
> genuinely need H.263/VP6 decode) purely because all four names start with
> `netstream_`. That is the `label-trap` / `bucket-by-owner` lesson again.

The `MOCK_DATE_TIME` lead in the brief was a decoy: the mock clock is not
involved. `datedatedat` is an AMF0 **Date** marker (`0x0B`) whose 8-byte payload
is `01 01 01 01 01 01 01 01` — a denormal ≈ 7.7e-304. Expected output `0` is
ECMA `TimeClip`'s `ToInteger` truncating it, which our `Date(Number)` ctor
already does. Nothing to fix there; the whole gap was the missing callback.

**Fix** (`avm2_net.c`, `avm2_display.c`, `avm2_globals.h`):

- `flv_find_metadata()` — walks `[PreviousTagSize u32][tag header 11][body]`
  from the header's own `DataOffset`, finds the first SCRIPTDATA tag (type 18)
  whose AMF0 short-string name is `onMetaData`, and returns the value that
  follows it. Truncation, a non-FLV, or no such tag all return NULL, which
  leaves `play()` exactly as silent as it was.
- `ns_play()` — resolves the name through `findDataFile` (bare name, then the
  relative path: the same two spellings `nc_resolve_response` uses), decodes the
  value with `avm2_amf0_read_value`, and **queues** the callback.
- `avm2_net_deliver_netstream_meta()` — per-tick drain called from
  `avm2_display_run_tick` right after `avm2_net_flush_connections`. Flash never
  delivers `onMetaData` inside the calling frame; the expected output pins that
  ordering (`starting`, `init finished`, *then* `running onMetaData`). The
  client is read at delivery time, and a client with no `onMetaData` property is
  silent (`avm2_has_public_property` guard) — Flash raises no error for a
  missing script-data handler.
- GC: the queued streams are roots (`gc_mark_roots_netstream`, wired into
  `avm2_gc_mark_roots_net`); the decoded value rides the ext, which the
  collector already scans conservatively.

```
before                          after
  starting                        starting
  init finished                   init finished
  <end of actual>                 running onMetaData
                                  0
```

### 2.2 + 2.3 `sound_rootless` and `sound_constructor_with_args` — one mechanism, two tests

**Diagnosis.** Both end on a `SOUND_COMPLETE` that never arrives, and
`sound_constructor_with_args` additionally wants `open`/`progress`/`complete` off
a `new Sound(new URLRequest("noise.mp3"))`. Two absences, one root cause:

- `Sound.load()` was a documented no-op ("external loading deferred"), and the
  ctor's URLRequest arm was a comment.
- `Event.SOUND_COMPLETE` is dispatched only by `avm2_media_poll`'s mixer sweep,
  and the file header says why that is trace-inert: *"channel positions only
  advance when an output sink pulls `audio_mix` (browser Web Audio) — never in
  the native test harness."* So in **both** native modes a played sound plays
  forever.

The precedent was already in the tree on the other VM: `action.c`'s
*"Sound playback simulation (for trace-only mode)"* — `g_playing_sounds`, a
duration estimated from the mp3's own CBR frame header, advanced one frame
budget per tick, firing `onSoundComplete`. This is that model ported to AVM2,
deliberately scoped so it cannot touch anything that already works.

**Mode-parity note (this is the part that constrains the design).** The
simulated clock is applied **only to URL-loaded sounds** — a sound with no
`DefineSound` char id, which therefore never reaches `audio_start_sound_ex` in
*any* build. Consequences:

- no-graphics and graphics native behave identically (neither has a mixer entry
  for such a sound) → mode parity holds by construction;
- embedded/SymbolClass sounds are untouched in both directions, so every
  currently-passing `sound*`/`soundchannel_*` row keeps its exact mixer
  behaviour;
- in the browser the same clock now ends an external sound that previously hung
  — a strict improvement, since the mixer never had the asset.

Doing it the other way round (a virtual clock for embedded sounds too) would
have fired `soundComplete` in no-graphics while the graphics mixer kept the
channel alive forever: a mode-parity break. Rejected for that reason.

**Fix** (`avm2_media.c` only):

- `mp3_duration_ms()` — ID3v2 skip + first-frame CBR header, the same estimate
  `action.c::builtin_sound_loadSound` uses (MPEG1 Layer II/III tables).
- `sound_start_url_load()` — reads `URLRequest.url`, resolves it with
  `findDataFile`, seeds `data_size` (so `bytesTotal`/`bytesLoaded` are live) and
  `ext_duration_ms`, and queues the events. The **bytes** resolve synchronously
  (they are linked into the binary); only the **events** are deferred — the same
  split `ul_start_load` uses.
- `sound_load()` / `sound_ctor()` — both route there; an embedded
  SymbolClass-bound sound still ignores the load, as before.
- `sound_play()` — an external sound registers a simulated channel
  (`sim_elapsed_ms`/`sim_duration_ms`); `sc_stop()` unregisters it without a
  `soundComplete`, matching the mixer arm's Flash semantics; `sc_get_position()`
  reports the simulated clock.
- `media_poll_simulated()` — called first from `avm2_media_poll`, delivers the
  queued `open`/`progress`/`complete`, then advances every simulated clock by
  `1000 / (avm2_generated_frame_rate / 256)` ms and dispatches `soundComplete`
  on drain (unregistering *before* dispatch, the same re-entrancy rule the mixer
  sweep uses).
- GC: simulated channels and load-pending Sounds are roots in
  `avm2_gc_mark_roots_media` — in both builds, where the mixer registry was
  `#ifndef NO_GRAPHICS`.

```
sound_rootless                         sound_constructor_with_args
  ...                                    Loaded sound
  [object SoundChannel]                  Playing sound
- <end of actual>                      - <end of actual>
+ Finished playback                    + Callback: Open
+ Attached root                        + Callback: Progress - 4180 / 4180
                                       + Callback: Complete - 4180 / 4180
                                       + Callback: Finished playback
```

---

## 3. The two that are genuinely out of reach

Both were already ruled unwinnable in `ACCEPTED_DIFFS.md` Category 13 before
this session. I re-attacked the ruling rather than taking it on faith, and it
survives — with one factual sharpening worth folding into the doc.

**`avm2/swz` (2 lines) and `avm2/loader_applicationDomain` (4 lines).** Both
`URLLoader` the 325 305-byte `framework_4.5.0.20967.swz` as BINARY, `loadBytes()`
it, and read `mx.*` definitions back out of an ApplicationDomain.

1. **The container is not even a SWF.** `framework_4.5.0.20967.swz` begins
   `30 83 04 f6 b4 06 09 2a 86 48 86 f7 0d 01 07 02` — a DER `SEQUENCE` carrying
   OID `1.2.840.113549.1.7.2` (PKCS#7 *signedData*). Using it means unwrapping
   PKCS#7 **before** you even reach a compressed SWF. The Category 13 text says
   "runtime-loaded ABC"; it is a layer worse than that.
2. **Then it is still runtime-loaded ABC.** Even unwrapped, the payload's
   thousands of `mx.*` classes exist only as bytecode. SWFRecomp translates ABC
   to C at build time and ships no interpreter — this is the AOT design, not a
   gap in it.
3. **No partial credit exists.** I checked whether any of the four expected
   lines is reachable without the SWZ: in `loader_applicationDomain` the two
   `[class Test]` lines (which *would* resolve — `Test` is the movie's own
   class) are traced inside the child `LoaderInfo`'s `init` handler, which only
   runs if the `loadBytes` produced a movie. Firing `init` for an unrecognised
   blob to harvest them would be a lie about `loadBytes` with live regression
   risk (`loader_bytes_unknown_content`, the #2124 arm) and would still leave
   the test failing. Not done.
4. Neither is `known_failure` upstream (Ruffle passes both — it has an
   interpreter and unwraps SWZ), so `ruffle_matched` is not a route either.

**Disposition recommendation: keep both, no new entry needed.** They are already
in `ACCEPTED_DIFFS.md` Category 13 and in `avm2/ignored_tests.txt` with the
right (suite-local) scope. Suggested one-line sharpening to Category 13's
preamble, for whoever next re-costs the bucket:

> The `.swz` is not a bare SWF: it is a PKCS#7 signedData container
> (`30 83 … 06 09 2a 86 48 86 f7 0d 01 07 02`) wrapping one. Unwrapping it is a
> prerequisite to the ABC problem, not an alternative to it.

**Ignore-list edit (included in the patch).** `netstream_flv_date`,
`sound_rootless` and `sound_constructor_with_args` are **removed** from
`avm2/ignored_tests.txt`'s "Host I/O" bucket by that file's own 2026-08-01
prune criterion — an entry whose status is `pass` is hiding a win. The
surviving nine entries get a header note saying they were *not* re-costed, so
the next pass does not read the bucket as audited. This moves no graded number
(the headline is the unfiltered `effective_pass`); it fixes the *filtered*
report. `loader_applicationDomain` and `swz` stay exactly where they are.

---

## 4. Canaries

**Zero regressions.** 23 `avm2` rows chosen by *content* (every test that
touches `Sound`, `SoundChannel`, `SoundMixer`, `NetStream`, the URL fetch
pipeline, or `Date`) plus a 10-row `regression`-suite AVM2 slice for the tick
loop and the GC roots. Every status matches its `results_graphics.json`
baseline at `fb36ba110`; the three `output_mismatch` rows that are near the
changed mechanism were checked line-for-line, not just by status.

| canary | baseline | after | |
|---|---|---|---|
| `av_classes` | pass | **pass** | ok |
| `netstream_client` | pass | **pass** | ok |
| `netstream_connect` | pass | **pass** | ok |
| `sound_embeddedprops` | pass | **pass** | ok |
| `sound_play` | pass | **pass** | ok |
| `sound_valueof` | pass | **pass** | ok |
| `soundchannel_soundtransform` | pass | **pass** | ok |
| `soundchannel_soundtransform_exists` | pass | **pass** | ok |
| `soundchannel_stop` | pass | **pass** | ok |
| `soundmixer_buffertime` | pass | **pass** | ok |
| `soundmixer_stopall` | pass | **pass** | ok |
| `soundtransform` | pass | **pass** | ok |
| `url_loader` | pass | **pass** | ok |
| `urlstream_basic` | pass | **pass** | ok |
| `date` | pass | **pass** | ok |
| `soundchannel_position` | ruffle_matched | **ruffle_matched** | ok (the `ruffle_matched`-is-a-regression trap: checked, unmoved) |
| `soundchannel_soundcomplete` | ruffle_matched | **ruffle_matched** | ok, same |
| `soundmixer_soundtransform` | mismatch 888/900 | **mismatch, 12 diff lines** | identical |
| `sound_load_multiple` | mismatch 3/19 (actual 7) | **mismatch 3/19 (actual 7)** | identical |
| `audio_computespectrum` | mismatch 0/118 | **mismatch 0/118** | identical (still `computeSpectrum is not a function`) |
| `netstream_play_stop_replay` | mismatch 1/11 | **mismatch 1/11** | identical |
| `netstream_play_flv` | mismatch 0/16 (actual 0) | **mismatch 0/16 (actual 1)** | ↑ one line, 0 matched either way |
| `netstream_seek_flv` | mismatch 0/49 (actual 0) | **mismatch 0/49 (actual 1)** | ↑ one line, 0 matched either way |

The last two are the only rows whose *output* moved: both now emit their
`onMetaData` trace (`netStatusOnMetaData`, which is genuinely expected output —
line 7 of each `output.txt`), but in isolation, with none of the surrounding
`netStatus` playback events. Status and matched-line count are unchanged, so
neither is a regression, and both are now one mechanism closer.

**`regression` suite (AVM2 slice, 10 rows):** see below — `avm2_gc_*` ×3,
`avm2_loader_stub`, `avm2_localconnection_domain`, `avm2_embed_bytearray`,
`avm2_agi_shell`, `avm2_timeline_solid`, `avm2_static_and_store_slots`,
`avm2_typed_value_ops`. The AVM1 half of the suite was **not** run and does not
need to be: all four edited files are AVM2-only, and no AVM1 translation unit
sees any of them.

All ten were `pass` at `fb36ba110` and all ten are **`pass`** here:
`avm2_gc_dynprop_tombstone_purge`, `avm2_gc_string_concat_reclaim`,
`avm2_gc_string_survives_collect`, `avm2_loader_stub`,
`avm2_localconnection_domain`, `avm2_embed_bytearray`, `avm2_agi_shell`,
`avm2_timeline_solid`, `avm2_static_and_store_slots`, `avm2_typed_value_ops`.
The three GC rows are the load-bearing ones: this patch adds two new root sets
(`gc_mark_roots_netstream`, and the simulated-channel / pending-load pair in
`avm2_gc_mark_roots_media`), and adding roots can only over-retain, never
under-retain — the rows confirm it.

**Two traps hit while running these, both worth the next agent's time:**

1. **`--recompile` is not optional when you copy a test dir between trees.**
   The `RecompiledABC/` copied from the main tree predates
   `avm2_generated_symbol_class_frames` and `avm2_generated_device_fonts`, so
   the first canary batch reported **5 × `compile_fail`** — all of them link
   errors (`undefined reference`), all of them FALSE. The
   `stale-recompiledabc` memory note is exactly right and the failure looks
   like a real regression until you dig the linker output out of a truncated
   200-char `detail` field.
2. **A 300 s compile timeout is not enough on a shared box.** With several
   sibling agents compiling, `SWFRECOMP_COMPILE_TIMEOUT=2400` was needed; the
   env var is the documented lever (`verify_output.py:2683`).

---

## 5. Riders and leads this uncovered (not implemented)

- **`sound_load_multiple` (3/19, gap 16).** Its whole subject is Flash throwing
  `Error #2037: Functions called in incorrect sequence` on a **second**
  `load()`/`loadCompressedDataFromByteArray()`/`loadPCMFromByteArray()` on one
  `Sound`. Four of its nine cases are #2037 rows. Now that `load()` actually has
  state to guard, the throw is a small addition — but the test also needs
  `loadCompressedDataFromByteArray`, `loadPCMFromByteArray` and an AMF 40K
  `ArgumentError #2084`, so it is a *multi-detail* row, not a one-liner. Worth
  a re-cost, not a blind fix.
- **`netstream_play_stop_replay` (1/11)** and the two FLV playback rows now get
  their `onMetaData` for free; they still need real playback state
  (`play`/`stop`/`time`) and, for two of them, a decoded frame. Unchanged
  verdict — bucket M is right about *those* three.
- **The rest of the "Host I/O" ignore bucket has never been re-costed either.**
  `localconnection`, `soundchannel_position`, `soundchannel_soundcomplete`,
  `soundmixer_soundtransform`, `audio_computespectrum`, `sound_load_multiple`
  are nine rows seeded by the same 2026-07 directory-prefix rule. Two of them
  (`soundchannel_soundcomplete` at 6/16, `soundchannel_position` at 66/140) sit
  directly on the mechanism this patch just built and are the obvious next
  probe.

---

## 6. Files edited

Four files, all AVM2 runtime. **None of them is on the `describetype` agent's
priority list** (`avm2_globals.c`, `avm2_class.{c,h}`, `avm2_abc.h`,
`avm2_error.c`, `avm2_stage3d.c`, `abc_emit.cpp`) — the one header I touch is
`avm2_globals.**h**`, not `avm2_globals.c`, and the edit is a pure append of one
4-line declaration block next to the two existing `avm2_net_*` declarations, so
it cannot collide with a member-collection rewrite.

| file | change | shape |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_net.c` | NetStream FLV script-data path | +1 forward decl, +2 ext fields, +1 root call, ~135 new lines in the NetStream section; one registration line `net2_noop` → `ns_play` |
| `SWFModernRuntime/src/avm2/avm2_media.c` | URL-loaded Sound + simulated playback | +3 ext fields on Sound, +3 on SoundChannel, ~200 new lines; `#include <libswf/swf.h>` made unconditional |
| `SWFModernRuntime/src/avm2/avm2_display.c` | one call in the per-tick drain | +5 lines (4 comment) after `avm2_net_flush_connections` |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | declaration for the new drain | +4 lines, append-only |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | 3 entries removed + bucket note | data file, no code |

Patch: `wave2/w2-host-io.patch` (`git diff` of the five files above;
`git apply --check --reverse` verified against this worktree).

**Merge note for the coordinator.** Nothing here collides with the
`describetype` agent: the only shared *name* is `avm2_globals`, and I touch the
**header**, not `avm2_globals.c`. `avm2_display.c` is touched at exactly one
point (five lines inside `avm2_display_run_tick`'s drain sequence, no reflow).
`avm2_net.c` and `avm2_media.c` should be conflict-free for anyone else this
session — no other wave-2 brief names them. Merge order is unconstrained from
my side.
