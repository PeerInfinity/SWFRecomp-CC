# One-task session (LOCAL): eager placement init in the browser frame loop

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s27 fan-out coordinator `s27-coordinator`
(it will send a handshake: reply to it). This slot is LOCAL because it needs emsdk and a real browser-WASM build,
which cloud workers lack. Pull first (`git pull --no-rebase`).

## Inputs

- `SWFRecompDocs/pl## Inputs

- Your predecessor's record: `SWFRecompDocs/plans/session27-fanout-reports/browser-arms-land-report.md` (code `91418ebbe`).
  Root cause it measured: **the browser builds sprite children LAZILY**. They exist only after `tagShowFrame`'s
  `advance_sprite_frames`. Eager init (`process_sprite_needs_init` / `ng_on_place_object2`, `tag.c:527-999`) is
  `NO_GRAPHICS || OFFSCREEN_RENDER`-only, so a frame-N script sees no children of a frame-N sprite. That owns
  `movieclip_getbounds` (every clip query returns the sentinel), `transform` (`clip.clip.transform` reads the outer
  clip), and `duplicate_movie_clip`; the browser-only `AQ_KIND_LOAD` deferral in `actionCloneSprite` compensates for it.
- Probe harness `tools/browser-test/child_probe/`. **Don't pipe the run script through `tail`**: that truncation made the
  coordinator misread two rows.

## Goals

1. Port eager placement init to the browser frame loop: the browser `tagPlaceObject2` / `tagSetClipActions` arms →
   `ng_on_place_object2` + the INIT/CONSTRUCT/LOAD queue + `process_sprite_needs_init`. Then drop the `AQ_KIND_LOAD`
   deferral. Priced M–L.
2. Oracle: those 3 rows in child_probe (real browser) must match native, plus the browser-gated fixtures and a real-game
   browser smoke: Doodle Jump and Pacman builds (memory `wasm-game-debugging`; WSL Chrome is SwiftShader, function only).
   The N browser routes are the strongest regression check (memory `n-play-game-click`: seeded browser builds,
   tick-exact against native).
3. Prove the CI define sets are untouched (preprocess md5 under graphics / images / no-graphics), or, if your change is
   shared, run the affected rows in both CI modes.

 native build runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. `pgrep -f` patterns must be bracketed (`[b]rowser...`), or a wait loop matches itself (this
  happened to the coordinator today).
- The tree is SHARED with the coordinator (which lands cloud patches into `action.c`/`tag.c`) and the N session. Stage
  only your hunks (`git apply --cached` if a file has other edits). Message `s27-coordinator` before committing
  `action.c`/`tag.c` changes. Use the harness trailer on commits.
- Don't dispatch CI or Pages: send the coordinator your SHA. It folds the change into its grading run and the s27 Pages
  deploy.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/session27-fanout-reports/browser-eager-init-report.md`: per-row browser before → after, the
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
