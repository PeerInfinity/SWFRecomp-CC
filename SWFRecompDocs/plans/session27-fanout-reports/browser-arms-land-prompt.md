# One-task session (LOCAL): land the browser-WASM AVM1 no-op arm fixes, verified in a real browser build

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s27 fan-out coordinator `s27-coordinator`
(it will send a handshake: reply to it). This slot is LOCAL because it needs emsdk and a real browser-WASM build,
which cloud workers lack. Pull first (`git pull --no-rebase`).

## Inputs

- `SWFRecompDocs/plans/session27-fanout-reports/w1-browser-avm1-gaps-report.md` and `-prototype.patch` (+ `-fixtures/`):
  the `gate_inventory.py` `browser-stub`/`browser-thin` categories, the native `SWF_BROWSER_ARMS_TU=action.c` harness in
  `verify_output.py`, and fixes for 15+ browser no-op arms (`createTextField`, `getInstanceAtDepth`, `getRGB`, `getBounds`,
  `createEmptyMovieClip`, `duplicateMovieClip`, `setNewTextFormat`, `removeTextField`, `Color.setTransform`, `swapDepths`,
  `_width`/`_height` setters, `transform.concatenated*`/`pixelBounds`, and the `actionGetVariableImpl` browser name lookup).
- **The coordinator's real-browser probe of that patch** (`w1-local-oracles/w1-browser-avm1-gaps/browser_probe_run_{a,b}.txt`;
  `tools/browser-test/child_probe/`, fixed in `b8d3b736a` to carry `avm2_cpu_raster.c`). The 3 new fixtures,
  `transform` and `movieclip_create_text_field` match native. **Still failing in the real browser:**
  `movieclip_getbounds` (`undefined` where native has `50`/`164`) and `color` (`getTransform` all 0, `getRGB` undefined),
  and `duplicate_movie_clip` (`load:` order, the predicted HOLD). So the native harness does not reproduce every browser
  arm: find out why (`__EMSCRIPTEN__`-only arms? browser `tag.c`/`swf.c` arms the harness does not compile? a
  `display_obj` the browser frame loop never sets?), fix them, and teach the harness (or the gate inventory) about the
  gap.
- Exporter traces confirm the 3 fixtures except `avm1_browser_gated_textfield` line 7: Ruffle prints
  `tfA bounds undefined,...` (an AVM1 TextField has no getBounds). Check that against Flash
  (`tools/flash-oracle/run_trace.py <dir> --wrapped --diff`) and fix the fixture or the code to match Flash.

## Goals

1. Apply the prototype and make every probed row match native in the REAL browser build (child_probe harness). For each
   remaining row, either fix it or record its completion mechanism. Land the fixtures in `regression/` with goldens from
   Flash.
2. Prove the CI defines are unaffected: the worker's preprocess md5 check under the graphics/images/no-graphics define
   sets. Re-run it after your changes.
3. A browser smoke on a real game is optional but valuable (`flasharchive` builds; WSL Chrome is SwiftShader, function
   only).

## Constraints

- Every emcc / native build runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. `pgrep -f` patterns must be bracketed (`[b]rowser...`), or a wait loop matches itself (this
  happened to the coordinator today).
- The tree is SHARED with the coordinator (which lands cloud patches into `action.c`/`tag.c`) and the N session. Stage
  only your hunks (`git apply --cached` if a file has other edits). Message `s27-coordinator` before committing
  `action.c`/`tag.c` changes. Use the harness trailer on commits.
- Don't dispatch CI or Pages: send the coordinator your SHA. It folds the change into its grading run and the s27 Pages
  deploy.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/session27-fanout-reports/browser-arms-land-report.md`: per-row browser before → after, the
  harness gap explained, what is left with its completion mechanism.
- Commit and push (code + fixtures + report). Update memory `browser-wasm-gate-inventory` (don't duplicate it).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
