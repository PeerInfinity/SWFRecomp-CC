# s28 wave 1 — `w1-leads` report (small leads: hitTest shapeflag, fixed-size queues, FileReference)

Cloud worker, branch `fanout/w1-leads`, base `origin/master` `d5f9726d` (code = baseline `7c3cfdcb7`). Box: SETUP_STATUS all OK
(apt, Pillow, Dawn). Corpus: `download_tests.sh avm1` on 2026-11-25 (upstream head `c2f7d24b7`, as cloned for source reading).
All runs `--mode=graphics` unless stated. `trace-provenance.md` had **not** landed on origin when I finished (checked at
`fbd1e0ce`), so item 1 works from `golden-provenance.md` round 2 alone.

**New files (all under `session28-fanout-reports/`):**
- `w1-leads-report.md` (this file)
- `w1-leads-prototype.patch`: queue growth, 4 queues; source is reverted on the branch
- `w1-leads-fixtures/avm1_hittest_root_stale_matrix/`: Flash probe for item 1, plus `hittest_model_switches.diag.patch`
  (the env-switch diagnostic I used; never land it)
- `w1-leads-fixtures/avm1_loadvars_ondata_overflow/`, `avm1_sprite_goto_script_overflow/`,
  `avm1_remove_unload_finalize_overflow/`, `avm1_unbound_textfield_overflow/`: overflow fixtures for item 2
- `w1-leads-fixtures/avm1_onunload_setvar_scope/`: a new lead found along the way (below)

Each fixture dir has `create_test_swf.py` (stdlib, imports the shared `avm1asm.py` copy), `test.swf`, `test.toml` and
`output.ours-*.txt`. **None has an oracle `output.txt` yet**; see LOCAL ORACLE REQUESTS.

---

## Verdicts

| # | Lead | Verdict | Priced flips |
|---|---|---|---|
| 1 | `avm1/movieclip_hittest_shapeflag` RvF / flash_fixes | **REFUTED as premised; HOLD for one Flash run.** The 3 Flash-`false` lines are **not** our ACCEPTED lines. On those 3 lines we print the golden's `true`, so we are ≠ FP32 there too. | **0.** Even after a flash_fix the row keeps ≥ 6 diff lines (our ACCEPTED Cat 8 set, which, per the "3 lines" count, also ≠ FP32). |
| 2 | Remaining fixed-size deferred queues | **GO (S), prototype measured.** 4 more silent-drop queues grown (`ng_table_grow`). 3 have overflow fixtures, each showing a before→after delta in both modes. Everything else is inventoried and priced. | **0 corpus flips** (no corpus row overflows any of them; 37-test A/B sweep status-identical). Value: robustness for real games. |
| 3 | FileReference `download()`/`upload()`/`postData` | **NO-GO (nothing to do).** AVM1 already has a full Ruffle-mirroring implementation. AVM2 `download`/`upload` are no-ops, and Ruffle's are `stub_method` too. All 23 corpus FileReference rows pass. | 0 |

---

## 1. `movieclip_hittest_shapeflag`: the premise is wrong, and the residual is a coordinate-model question

### Facts (measured at baseline code)

- Our graphics diff has exactly **6 lines**: 71, 171, 173, 175, 177 and 296. These are ACCEPTED_DIFFS Cat 8, and
  `ignored_tests.txt` lists the row.
- The golden-provenance lead (`session27-fanout-reports/golden-provenance.md:160`) says pinned FP32 prints `false` on
  `clip.hitTest(400, 500 / 500, 400 / 400, 300, true)` where the golden says `true`. Those three probes occur, in that
  order, only in the two **donut** blocks (lines 13/15/17 and 35/37/39). Line 296 is `hitTest(400, 300)` too, but the golden
  there is `false`, so it cannot be one of the 3.
- **On all of lines 13–41 we print exactly the golden.** So the brief's "Are those 3 our ACCEPTED lines?" is **no**. With a
  flash_fix applied, we would be ≠ FP32 on 3 + 6 = 9 lines instead of 6. The "only 3 lines differ" count also implies that
  FP32 agrees with the golden on our 6 ACCEPTED lines, so they are not Ruffle-vs-Flash either: Cat 8 stays ours.
- **No Flash capture of this row is archived anywhere in the repo** (grep of all s2x report dirs and `w1-local-oracles`).
  I could not tell which donut block the 3 lines are in, or see the full Flash file.

### Which block? Geometry says the second (root-transformed) one

The script (`script_0.c`) runs block 1 untransformed. It then sets `_root._x = 400; _root._xscale = 50`, re-runs the same 9
probes (block 2) and resets the root **in the same frame** (`_x = 0`, `_xscale = 100`). The donut is a ring centred on
(400,400) in root space: I scanned our shape test (clip matrix `3,0,0,3,400,400`) and found hits for root-x 250–335 and
465–545 on y = 400. That is an inner radius of about 62 and an outer radius of about 150. Block 1 is plain geometry, and a
symmetric ring cannot make 3 of 4 symmetric points false. So the 3 lines are almost certainly 35/37/39 (block 2).

I tested three coordinate models in our runtime with an env switch (`hittest_model_switches.diag.patch`, the point-mapping
line in `actionCallMethod`'s `hitTest` arm, action.c ~80573):

| model | block-2 lines 35/37/39/41 | matches Flash's "3 false, `(300,400)` still true"? |
|---|---|---|
| Ruffle / ours: point is `_root`-local, mapped through `_root`'s matrix (`movie_clip.rs:243-246`) | T T T T | no (0 lines differ) |
| stage: point is stage-global | F F F F | no (4) |
| **"stale clip matrix"**: point mapped through `_root`'s NEW matrix, clip still tested at its pre-change world matrix (≡ applying `_root`'s matrix twice) | F F F F, but `(300,400)` lands **exactly** on the outer edge (root-local (550,400), r = 150.0) | **yes, if Flash's fill rule includes that boundary point**. It is the only model I found that is consistent with all 9 block-2 lines. |

The **stale-clip-matrix** model is classic Flash behaviour (concatenated matrices cached and refreshed at render), but I
could not confirm it. There is also a competing explanation. The s28 `w1-drift` capture (`c085bbc9`) found that the pinned
harness **replaces `_level0`** via the PinStub, and that this changes root behaviour (no frame-1 root onLoad). The 3-line
diff could therefore be a pinned-mode artifact. Note that the row's stage is 800×800 and its SWF version is 15.

### Probe for the Flash run: `w1-leads-fixtures/avm1_hittest_root_stale_matrix`

A 100×100 Drawing-API square `c` at (100,100), on a 640×520 stage (the projector's startup size, so even a `--no-pin` run is
not scaled). Phases: A identity; B same frame after `_root._x = 100`; C next frame; D same frame after `_root._x = 0`;
E next frame; F same frame after `c._x = 200`; G same frame after `_root._xscale = 50`. Each phase traces
`hitTest(150|250|50, 150, true/false)` and `c.localToGlobal(0,0)`. Phase B separates the models:

| phase B `hit(150)/hit(250)/hit(50)` | model |
|---|---|
| `true / false / false` | Ruffle (= ours, `output.ours-7c3cfdcb7.txt`) |
| `false / false / true` | stale clip matrix |
| `false / true / false` | stage-global |

Phases C/D/E show whether a render tick refreshes the matrix, and whether a stale matrix also survives a reset (D). G tests
the scale arm. `localToGlobal` shows whether the same staleness reaches other APIs.

### Pricing / completion mechanism

- **If Flash says "Ruffle" for the probe in both pinned and `--no-pin` runs:** the shapeflag 3-line diff is a harness
  artifact. Re-capture the row `--no-pin`. No code change, no RvF.
- **If Flash says "stale":** the fix is ours, in hitTest's point→clip path. Test against a per-clip "last rendered" world
  matrix, snapshotted per render tick, not against `getConcatMatrixForMC`. That is M, because the snapshot has to exist for
  every clip. Plus a flash_fix for the 3 golden lines, plus an RvF entry (Ruffle reads the live matrix). The row still fails
  on Cat 8's 6 lines, so this is **0 flips**: a Flash-correctness item only. Check every other hitTest row
  (`movieclip_hittest`, gnash `masks_test`, …) for same-frame root/parent transforms before landing.
- **Doc fix regardless (doc-only):** ACCEPTED_DIFFS Cat 8's intro says the 6 lines are where "our implementation disagrees
  with Ruffle's". Per the golden-provenance count they also disagree with FP32. Wording only, for the coordinator.

---

## 2. Fixed-size queues: inventory, 4 grown, fixtures

Prototype: `w1-leads-prototype.patch` (+67/−16; action.c, sprite_frame_scripts.c, tag.c). It reuses `ng_table_grow`
exactly as s27 `w2b-timers-tail` did, so the old `MAX_*` constant becomes the initial capacity.

### Grown in the prototype

| queue (owner) | overflow before | change | fixture: origin/master → prototype (graphics = no-graphics) |
|---|---|---|---|
| `MAX_PENDING_FORM_DATA` 16. action.c `avm1QueueFormDataEvent` / drain `avm1FireFormDataEvents` | 17th loadVariables completed in a tick: **onData silently lost** | growable table. The drain's stack copy becomes heap when count > 16 | `avm1_loadvars_ondata_overflow`: **16/20** `onData` → **20/20** |
| `MAX_PENDING_SPRITE_SCRIPTS` 16. sprite_frame_scripts.c `actionQueuePendingSpriteScript` | more than 16 sprite **self**-gotos before a flush: **target-frame scripts dropped** | growable. The flush only enqueues (runs no script), so no realloc under a walk | `avm1_sprite_goto_script_overflow`: self-goto wave **16/20** `L2/L3` lines → **20/20**. Root-issued `tellTarget`/method gotos (40 lines) do not use this queue and were already 40/40 |
| `NG_PENDING_FINALIZE_CAP` 256. **tag.c** `queue_pending_finalize_mc`, `run_pending_finalize` (NO_GRAPHICS‖OFFSCREEN arm) | 257th removal (timeline RemoveObject) of a clip with an unload handler in one tick: **never finalized, so a ghost clip** | growable, and `run_pending_finalize` now takes ownership of the table before walking it. That also fixes a latent bug: an enqueue during the walk used to overwrite entries `[0..)` that were being walked | `avm1_remove_unload_finalize_overflow`: `alive=44` (= 300 − 256) → `alive=0`. All 300 onUnloads fire in both |
| `MAX_DELIVERED_THIS_TICK` 16 ring. action.c `actionLoadedMovieDeliveredThisTick` + new `actionNoteLoadedMovieDelivered`, called from `actionFirePendingDirectLoadsImpl` | the 17th direct-load delivery in one tick **overwrote** the 1st, whose loaded shell then got clip enterFrame on its delivery tick | epoch-keyed growable list, reset lazily when `g_direct_load_epoch` moves | **no fixture** (needs more than 16 holder `loadMovie`s delivered in one tick plus an enterFrame observer in the child SWF). Semantics are identical below 16 |

A/B safety: a 37-test graphics sweep near the changed paths (avm1 goto*/load*/unload*/remove*, plus regression
`avm1_loaded_*`, `avm1_mcl_load_tick`, `avm1_exec_order_attached_selfremove`, `onunload_type1_*`, …) is **status-identical to
the baseline** (35 pass, 2 baseline `ruffle_matched`: `goto_rewind_movieclip_replace`, `load_cancel_via_unloadmovie`). The
four fixtures are byte-identical across graphics and no-graphics. **tag.c functions touched:** `queue_pending_finalize_mc`,
`run_pending_finalize` (plus the static table). No other sibling-owned function.

Wave-2 landing scope: apply the patch. Promote the 3 fixtures to `regression/` once an outside oracle confirms the
"after" output (requests below). The ordering of the onData lines and the self-goto L2/L3 sequence are the parts that need
the oracle, not the counts.

### Not grown (priced)

| table | overflow behaviour | reachable? | price / mechanism |
|---|---|---|---|
| `UNBOUND_TF_MAX` 64 (action.c `unbound_tf_push`) | 65th unresolved timeline `variable` field is not queued for retry | **not observable through `.text`**: fixture `avm1_unbound_textfield_overflow` (70 timeline DefineEditText) binds **70/70 at baseline**, because the fields resolve on read | S to grow if a write-back/onChanged fixture ever shows it; left alone |
| `MAX_LC_MESSAGES` 64 (action.c `builtin_lc_send`) / avm2 `LC_MAX_QUEUE` 64 (avm2_net.c) | `send()` **returns true** and drops the message | 65+ sends in one frame; no corpus row | S, same pattern (the drain at action.c ~4037 copies onto the stack, so it needs a heap copy as in form-data) |
| `DRAW_INLINE_MAX` 256 (action.c `actionRenderMCDrawingsInline`) | past 256 Drawing-API clips per frame, inline (under-children) drawing is refused, so those clips go back to the global pass: **pixel z-order wrong** | plausible in games with many vector-drawn clips; pixels only | S, but render-path: needs canary md5 identity |
| `MAX_AVM1_UNDER_AVM2` 8 (action.c `actionBootAvm1ChildUnderAvm2`) | returns NULL, so the 9th AVM1 child under an AVM2 Loader is not hosted | no corpus row | S |
| `MAX_PENDING_DIALOGS` 16 (utils.c), `MAX_FILEREF_OPS` 8 | queue full: the dialog is dropped and the FileRef op leaks `in_use`; ops full: `download()` returns false | Flash allows one file dialog at a time, so unreachable in practice | NO-GO |
| `SWF_LOG_FETCH_MAX_QUEUED` 64 (utils.c) | navigator fetch-log lines dropped | test-harness log only; more than 64 fetches per flush | NO-GO until a row needs it |
| `MAX_LEVEL_ADVANCE` 128, `MAX_DEFERRED_SHELL_CLEARS` 64 | **not silent**: evicts a parked playhead / clears immediately (timing only) | more than 128 / 64 loaded movies | NO-GO |
| `WORKER_PENDING_MAX` 64, `MAX_WATCH_FIRING` 256 (recursion guard by design), `MAX_SOUND_CHANNELS` 32 (= Flash's own limit), `MAX_PLAYING_SOUNDS` 16, `MAX_ACTIVE_NETSTREAMS` 8 | resource caps, not deferred queues | — | NO-GO |
| already growable | `MAX_TIMERS`, `MAX_PENDING_MCL_LOADS`, `MAX_DEFERRED_UNLOADS`, `MAX_DEFERRED_FAILED_LOADS`, `MAX_PENDING_DIRECT_LOADS`, `MAX_PENDING_LV_LOADS`, clone-depth, cxform overrides, filter lists, registries | — | done |

---

## 3. FileReference

- **AVM1** (action.c ~45478–46180, registered at ~48711): `browse`, `download`, `upload` and `postData` are a **full port**
  of Ruffle's `file_reference.rs` + `loader.rs::{download_file_dialog, upload_file}`. That includes the event order
  (onSelect → onOpen → onProgress → onComplete / onIOError / onHTTPError / onUploadCompleteData), the multipart body with
  per-`postData` parts, the fetch log, the debug status URLs and the boundary-collision cancel. The prototype shape is
  Flash's (no `postData` accessor); `postData` is read as a plain property.
- **AVM2** (avm2_net.c:3529-3530): `download` and `upload` are `net2_noop`. **Ruffle's AVM2 `download`/`upload`/
  `uploadUnencoded` are `stub_method`** (`FileReference.as:41-88`), so we already match Ruffle.
- **Corpus:** 14 avm1 `file_reference_*` rows + 9 avm2 `filereference*` rows, **all `pass`** in the s28 baseline. No row
  calls AVM2 download/upload, and none is failing or `ruffle_matched`.
- **Flash-documented behaviour we don't model:** FP10+ only allows `download()`/`browse()`/`upload()` dialogs from a
  user-input event. AVM2 throws `Error #2176`; I believe AVM1 returns `false`, but that is unverified. The corpus goldens are
  Ruffle's (no gesture rule), and the Flash oracle cannot click or answer dialogs. So there is no oracle path, and adopting
  the rule would turn 14 passing AVM1 rows into Flash-vs-Ruffle questions.
- **NO-GO.** Completion mechanism: an AVM2 port of the AVM1 resolve logic onto flash.events would take Event.SELECT /
  OPEN / ProgressEvent / COMPLETE / IOErrorEvent / HTTPStatusEvent / DataEvent.UPLOAD_COMPLETE_DATA. That is M
  (~300 lines), with no grader until upstream adds AVM2 download/upload tests or a Flash capture of the gesture rule exists.

---

## Refutations (premises attacked)

1. "If our output == FP32 on every line, it's a flash_fixes candidate + RvF": our output is ≠ FP32 on at least 9 lines (the
   3 Flash lines plus our 6). The 3 lines are not our ACCEPTED lines. Not a flash_fix-and-flip.
2. "Grow the remaining queues": most remaining `MAX_*` tables are not silent-drop deferred queues. They are resource caps,
   eviction policies or recursion guards. One that is silent (`UNBOUND_TF_MAX`) is not observable through the obvious API.
   Only 4 needed growth, and 1 of them (`MAX_DELIVERED_THIS_TICK`) was a ring that overwrote rather than dropped.
3. "FileReference download()/postData need work": AVM1 is complete and every corpus row passes. The AVM2 gap is shared
   with Ruffle.

## New unclaimed leads

1. **onUnload handler scope** (fixture `avm1_onunload_setvar_scope`, measured): a function defined in `_root`'s frame
   script does an unqualified `n = n + 1`. As a **method** (`b.bump()`) it updates `_root.n` (correct). As a timeline
   clip's **onUnload** it resolves `n` on the dying clip (`this.n = NaN`) and `_root.n` stays 1. Flash and Ruffle resolve
   through the function's captured scope chain (`_root`), so I expect `_root.n = 2` after the remove. Owner: the onUnload
   dispatch `actionFireOnUnload` (action.c) probably runs the handler with the clip as scope/target instead of the
   function's captured chain. Likely S. Grade with the Flash request below. Check `onunload_type1_*` regression rows, which
   pass today.
2. **AS-assigned `TextField.variable` to a not-yet-existing path never binds** (measured with a first,
   AS-only version of `avm1_unbound_textfield_overflow`: `createTextField` + `tf.variable = "holder.vN"`, holder created a
   frame later, bound **0/70**; the shipped fixture switched to timeline DefineEditText, and its script comment records
   this). This matches Ruffle (`set_variable` does not push to
   `unbound_text_fields`). Flash's lazy per-frame binding may differ, so it is an RvF candidate. Needs a Flash run (an AS
   variant of that fixture is 5 lines).
3. LocalConnection `send()` returns true while silently dropping past 64 queued messages (S, above).
4. `DRAW_INLINE_MAX` 256: z-order falls back past 256 drawing clips per frame (pixel; S + canary).
5. ACCEPTED_DIFFS Cat 8 wording ("disagrees with Ruffle's"): per FP32, also disagrees with Flash (doc only).

## LOCAL ORACLE REQUESTS

1. **FLASH: `w1-leads-fixtures/avm1_hittest_root_stale_matrix`, trace, 3 frames, run BOTH direct-pinned AND `--no-pin`**
   (the stage is 640×520 = the startup window, so unpinned is unscaled). Compare phase B against the table in §1. This
   decides item 1.
2. **FLASH: `avm1/movieclip_hittest_shapeflag`, trace, `num_ticks = 13`, both pinned and `--no-pin`; ARCHIVE the full
   output** (it was never archived in s27). Say which donut block's lines 35/37/39 (or 13/15/17) differ, and whether lines
   71, 171–177 and 296 equal the golden.
3. **FLASH: `w1-leads-fixtures/avm1_onunload_setvar_scope`, trace, 3 frames, direct-pinned** (no root onLoad
   involved). Expected per my reading: frame 2 `_root.n=2`.
4. **FLASH (or Ruffle exporter fallback): `avm1_loadvars_ondata_overflow` (3 frames; serves `vars.txt`),
   `avm1_sprite_goto_script_overflow` (3 frames), `avm1_remove_unload_finalize_overflow` (3 frames), trace, direct.**
   These would become the regression goldens for the wave-2 queue landing. The counts are the point; the line ORDER (onData
   order, interleaving of L2/L3 with the f2/f3 waves, the frame-2 `unloads=` value) is what needs the oracle.
