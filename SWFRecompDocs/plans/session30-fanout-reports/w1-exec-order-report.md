# s30 w1-exec-order (wave 2): per-clip enterFrame before the clip's own script, plus the clip-event merge

Slot `w1-exec-order`, branch `fanout/w1-exec-order`, base origin/master `f4edebdc`. Upstream Ruffle corpus at download: `66f9073de`.

**New files**
- `ruffle-tests/tests/swfs/regression/avm1_exec_order_sibling_interleave/`: `test.swf`, `output.txt`, `test.toml`, `create_test_swf.py`
- `SWFRecompDocs/plans/session30-fanout-reports/w1-exec-order-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w1-exec-order.patch`

Also edited, outside the patch: one README row in `ruffle-tests/tests/swfs/regression/README.md`.

## 1. Verdict: GO. Both reqs 1 and 3 landed in one mechanism, no losses

- **Req 1 lands.** Each child's enterFrame now fires immediately before that child's own queued frame script. This covers both onEnterFrame methods and `onClipEvent(enterFrame)`.
- **Req 3 lands.** The clip-event enterFrame walk is merged into the same exec order. Queued actions of an advancing clip also ride in its slot, for example a newly placed child's `onClipEvent(load)`.
- **Kill switch:** `SWF_EXEC_ORDER_EF=0` (browser build: `-DSWF_EXEC_ORDER_EF_OFF`). It is also off whenever `SWF_EXEC_ORDER_MERGED=0`.
- **Priced flips (trace, CI graphics and no-graphics):**
  - `from_gnash/misc-ming.all/action_order/action_execution_order_test11`: `output_mismatch` → **pass**. This was the probe. Its golden is Flash (s28 trace-provenance).
  - `from_gnash/misc-ming.all/action_order/action_execution_order_test4`: `output_mismatch` → **pass**. Golden = Flash (s28 trace-provenance; the harness re-run is byte-identical).
  - `regression/avm1_exec_order_sibling_interleave`: **new fixture**, red on master and green with the patch. The golden is the Ruffle exporter; an FP32 capture is requested below.
- **Flash-ward, status unchanged:**
  - `action_execution_order_extend_test`: fp10 diff 12 → 10 lines.
  - `PlaceAndRemove`, no-graphics only: 111 → 81 lines against fp10. Our whole 15-line output is now a prefix of the s28 FP32 capture `PlaceAndRemove.L1.txt` (before: 1 line). The spurious `moo N` / `FAILED: This MovieClip should never be constructed` lines are gone. This also **closes PlaceAndRemove's standing no-graphics vs graphics mode difference**: no-graphics output is now byte-identical to graphics, and graphics itself is unchanged.
- **Losses: none.** The A/B covered 126 rows × 2 modes (§4). The render canary was 225/225 md5-identical.

## 2. Mechanism

After the s29 merge, the per-tick advance queues every child's frame script as one block, sorted by place_seq descending (`actionAQOrderSortSince`). The enterFrames, however, all fired later at the pre-DoAction flush, so the tick ran every EF first and then every script.

Flash (test11) and Ruffle (`avm1/runtime.rs run_frame` → `movie_clip.rs run_frame_avm1`) instead do this per clip, newest first: the clip's enterFrame, then whatever its advance queued.

Fix, which only moves enterFrames later and never reorders the queue:
- **`action_queue.c`**
  - `ActionQueueEntry.exec_key`: a new trailing field. `actionAQOrderSortSince` keeps each block entry's key in it, the advancing clip's place_seq.
  - The early return now fires only for an empty block (`n == 0`, was `n < 2`). Before, a one-entry block never recorded its key, and that was exactly test11's `mc21 onLoad` tick.
  - New `actionAQExecEFEnabled`, `actionAQExecHasPending`, `actionAQRunExecNewer(bound)`.
  - `actionAQRunExecNewer` pops the entry the drain would pop next: the front-most highest-priority ONLOAD/SCRIPT entry, with the same skip and finalize rules (`aq_drain_one_onload_or_script`). It keeps popping while that entry's `exec_key > bound`.
  - Construction kinds (CLIP_INIT/CONSTRUCT/REGISTER_CTOR) drain first, as in `actionDrainAllInPriorityOrder`.
  - It runs outside the `g_inside_enterframe_dispatch` window, honours drain-suppress, and has a re-entrancy guard.
- **`action.c` `actionDispatchEnterFrameHandlers`** (outermost pass only, `g_ef_clip_interleave`):
  - New `ef_build_method_bounds` builds `g_ef_mbound[i]`, the newest place_seq of any onEnterFrame method still to fire at cache slot ≤ i (live clips and snapshot entries).
  - It runs only on ticks where `actionAQExecHasPending()` is true, so other ticks pay nothing.
  - Before each method EF at place_seq p, it calls `actionAQRunExecNewer(max(p, bound below i))`, then re-checks that the clip is still in the cache and still live.
  - `ef_fire_removed_snapshot_slot` gets the same hook.
  - New accessor `actionEFPendingMethodBound()` for tag.c.
- **`tag.c` `tagClipEFFireNewerOrEqual`** (CI modes): before each pending clip-event EF at place_seq p, it calls `actionAQRunExecNewer(max(p, actionEFPendingMethodBound()))`.
- The bound is what makes this safe. A queued action never runs ahead of a NEWER clip's enterFrame, even where the cache-index walk and place_seq disagree. Any entry the bound blocks just stays queued for the normal drain, which is exactly the old behaviour.

**Builds**
- swf_core.c (no-graphics) and swf.c (OFFSCREEN): both get reqs 1 and 3. The playing branch and the past-last-frame branch of swf_core.c both pass through the same dispatchers after their exec mark/sort, so **no edits to `swf.c` or `swf_core.c` were needed**.
- Browser: req 1 applies to onEnterFrame methods, since the method-arm hook is unconditional code. Req 3 does not apply there: the browser still fires all clip-event EFs before the method pass, because `tagClipEFFireNewerOrEqual` is a stub there. Browser clip-event order is therefore unchanged from master.
- Not compiled with emcc (there is no emsdk in the cloud). The touched code has no new `#if` arms, and the browser build compiles the same action.c/action_queue.c text. See the BROWSER request below.

**Functions touched:**
- `action_queue.c`: `actionQueueCallbackEx` (sets `exec_key = 0`), `actionAQOrderSortSince`, new `actionAQExecEFEnabled` / `actionAQExecHasPending` / `actionAQRunExecNewer`
- `action_queue.h`: 3 prototypes
- `action.c`: `ef_fire_removed_snapshot_slot`, `actionDispatchEnterFrameHandlers`, new static `ef_build_method_bounds` / `ef_mbound_below` / globals, new `actionEFPendingMethodBound`
- `tag.c`: `tagClipEFFireNewerOrEqual`
- **Not touched: `tag_stubs.c`, `swf.c`, `swf_core.c`, `advance_sprite_frames`.** There is no overlap with the browser ladder's `ng_attachMovie` block.

## 3. Headline before/after (clean origin/master vs patch, same box; diff lines vs golden; fp10 golden where subtests)

| test | master no-gfx | patch no-gfx | master graphics | patch graphics |
|---|---|---|---|---|
| gnash `action_order/action_execution_order_test11` | MISMATCH (8) | **PASS** | MISMATCH (8) | **PASS** |
| gnash `action_order/action_execution_order_test4` | MISMATCH (10) | **PASS** | MISMATCH (10) | **PASS** |
| gnash `action_order/action_execution_order_extend_test` | MISMATCH (12) | MISMATCH (10) | MISMATCH (12) | MISMATCH (10) |
| gnash `action_order/PlaceAndRemove` | MISMATCH (111) | MISMATCH (81) | MISMATCH (81) | MISMATCH (81) |
| gnash `action_order/ActionOrderTest3` / `4` / `5` | MISMATCH (97/84/51) | same, byte-identical | same | same |
| gnash `action_order/action_execution_order_test` (rm) | RM | RM, byte-identical | RM | RM |
| gnash `action_order/action_execution_order_test6` (rm) | RM | RM, byte-identical | RM | RM |
| gnash `misc-swfc.all/action_execution_order_test10` (rm) | RM | RM, byte-identical | RM | RM |
| gnash `loop/loop_test10` (rm) | RM | RM, byte-identical | RM | RM |
| regression `avm1_exec_order_sibling_interleave` (new) | MISMATCH (8) | **PASS** | MISMATCH (8) | **PASS** |
| regression `avm1_exec_order_attached_selfremove` | PASS | PASS | PASS | PASS |
| regression `avm1_attach_timeline_frame_order` | PASS | PASS | PASS | PASS |

- The kill switch (`SWF_EXEC_ORDER_EF=0`) output is byte-identical to clean master on every headline row.
- **test11's tick structure** (asOrder ids: load 1/2/5/8/14, EF mc1=4 mc2=3 mc11=6 mc21=10 mc12=15, frame scripts 25–29):
  - Flash R3 is `6 3 8 4`: mc11 EF, mc2 EF, **mc21 onLoad**, mc1 EF. mc21 is placed by mc2's advance, so its load rides in mc2's slot.
  - Flash R5 is `15 25 10 26 6 27 3 28 4 29`: each clip's EF, then its own frame script.
  - Master ran `… 4 8` on R3 and `15 10 6 3 4 25 26 27 28 29` on R5.

**Unmoved family members and their mechanisms (HOLD, each outside this slot):**
- `ActionOrderTest3/4/5`: dynamic load/unload and static unload ordering around a replaced clip (`static unload` / `dynamic load` blocks out of place). These are ctor/load-event timing, not exec order.
  - Completion: diagnose the dynamic-clip load-event slot against the FP32 goldens (s28 provenance = Flash).
- `_test6`: `onClipEvent` order inside a goto catch-up sweep (`4+5+x` vs `4+x+5`). Goto-sweep queueing, not natural advance.
- misc-swfc `_test10`: `mc4` placed by a goto is undefined, and the registerClass `onConstruct` never runs. This is goto placement and registerClass construction.
- `loop_test10`: clips are not re-initialised (no `initialized` / `unloaded`) on the root loop-back. This is loop-back re-placement (`survives_rewind`).
- `action_execution_order_test`: a one-line rm residual, untouched.

## 4. A/B sweep (kill switch off/on, ACTUAL outputs diffed, both modes)

**Candidates (126 rows):**
- Every AVM1 `test.swf` in avm1, from_gnash, from_shumway, regression, timeline, import_assets and visual that has an enterFrame handler. That means either the `onEnterFrame` string in the decompressed SWF, or any PlaceObject with clip actions. Each must also have a sprite DoAction, clip-event placements or `attachMovie`.
- Plus all 17 gnash `action_order` rows, the 11 gnash `loop` rows, both misc-swfc `action_execution_order_*` rows, and every `regression/avm1_attach*` / `*exec_order*` / `*enterframe*` row.
- 39 regression rows in total.

**Rows outside the list are provably unchanged.** The only new behaviour runs inside the enterFrame dispatchers, on a tick with exec-block entries pending. A row with no enterFrame handler never reaches the hook.

**No-graphics, 126 rows: 4 outputs change, all Flash-ward:**
- test11: FAIL → PASS
- test4: FAIL → PASS
- extend_test: 12 → 10
- PlaceAndRemove: 111 → 81
- All other 122 rows are byte-identical.

**Graphics, 126 rows: 3 outputs change:**
- test11 and test4: FAIL → PASS
- extend_test: 12 → 10
- PlaceAndRemove is unchanged under graphics. It already printed the new no-graphics output.
- No image verdict moved on any row. The only image FAIL in the set is `misc-ming.all/shape_test`, identical in both legs and pre-existing.

**Mode parity:** after the patch, no-graphics and graphics outputs are byte-identical on all 126 rows. Before the patch, PlaceAndRemove was the one mode difference.

**Render canary:** `render_canary.py` over the 167 avm1/gnash/shumway/regression/visual members of `render_canary_tests.txt`, captured with `SWF_EXEC_ORDER_EF=0` then `=1`.
- Result: 162 tests / 225 comparisons IDENTICAL; 0 differs; no trace or image status changes.
- The avm2/fonts/text members were not captured: those categories were not downloaded, and the hook is AVM1-only.
- `render_canary_tests.txt` is not changed. The change class is trace order, which the canary's trace axis already records, and no pixel can move without a trace-visible order change.

## 5. EXPECTED-FLIP LEDGER (CI)

| row | trace, graphics | trace, no-graphics | pixels |
|---|---|---|---|
| `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | output_mismatch → **pass** | output_mismatch → **pass** | no comparison |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | output_mismatch → **pass** | output_mismatch → **pass** | no comparison |
| `regression/avm1_exec_order_sibling_interleave` (new row) | **pass** | **pass** | none |
| `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` | output_mismatch, unchanged (diff smaller) | same | — |
| `from_gnash/misc-ming.all/action_order/PlaceAndRemove` | unchanged | output_mismatch, unchanged (output now == graphics) | — |

- **Net: +2 effective trace rows on the corpus in both modes, plus 1 new regression row.** Pixels: 0 flips.
- Any other flip is a defect of this patch. The suspect would be a tick where a clip's queued action now runs before an older clip's enterFrame.

## 6. Not finished / completion mechanisms

- **Browser clip-event merge (req 3 in the browser):** the browser still fires clip-event EFs in a separate pass before the methods.
  - Completion: port the s28 pend interleave (`tagClipEFCollectRootPass` gather + `tagClipEFFireNewerOrEqual`) to the browser root pass. `dispatch_attached_clip_enterframe` would need to join the same pend list. Then the hook applies unchanged.
  - Grade with the BROWSER request below.
- **Dynamic clips with no `display_obj` (createEmptyMovieClip):** they have no place_seq, so they take no hook. They keep the master order (their EF fires before any queued script).
  - Completion: give dynamic MCs an instantiation serial from `g_place_seq` at creation, then treat them like display clips in `ef_build_method_bounds` and the method arm.
- The family members in §3 are out of scope, with the mechanisms named there.

## 7. New unclaimed leads

- `PlaceAndRemove`: with the patch, both modes print 15 `Done` lines against the golden's 96. The FP32 capture keeps printing past the cap (s28: "untestable", long run). The remaining gap is the run length (`num_ticks = 30`, plus the known_failure goto panic note), not the order.

## LOCAL ORACLE REQUESTS

1. **FLASH: `ruffle-tests/tests/swfs/regression/avm1_exec_order_sibling_interleave`**: trace, direct (pinned), 8 frames. The SWF is shipped in the fixture dir; `create_test_swf.py` regenerates it byte-identically. Compare against the shipped Ruffle-exporter `output.txt`.
   - If FP32 differs, replace the golden with the FP32 capture and re-grade the patch: the fixture locks req 1 for onEnterFrame methods across timeline and attached clips.
   - Mark the ticks by `root fN` lines.
2. **BROWSER child_probe:** run `build_child_probe.sh <fixture> ruffle-tests/tests/swfs/regression` and `run_child_probe.py <fixture>` for:
   - `avm1_exec_order_sibling_interleave`: expect the golden order (req 1, methods).
   - `avm1_attach_timeline_frame_order`: the s29 order must be unchanged, apart from the two known pre-existing browser-only differences (s29 report §5).
   - `avm1_exec_order_attached_selfremove`: must be unchanged.

   Then A/B each one with `EMCC_CFLAGS=-DSWF_EXEC_ORDER_EF_OFF`: only the sibling fixture may change.
   - The gnash test11/test4 SWFs exercise browser req 3, which is NOT implemented in the browser (§6). Expect their clip-event order to equal the kill-switch build.
   - Doodle Jump / N smoke as in s29 §5 (enterFrame-heavy): `dj_alive.py click` and the N ND/NF telemetry.
