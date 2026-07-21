# Session prompt — Elephant Quest bring-up investigation (corpus expansion)

**Objective (user, 2026-07-21):** begin corpus expansion beyond the five
hand-picked titles with an ambitious target:
`~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf` (jmtb02 / ArmorGames,
2011). **Ruffle cannot run this game** — it gets past "loading world map",
then fails to load some of the content. If our pipeline runs it, it is the
first title we run that Ruffle cannot *play* at all (rwf/rwic Ruffle merely
renders nothing). This is an **investigation session**: staged bring-up +
gap characterization. Do not expect to finish the game; expect to produce
the map of what it needs.

## Recon already done (2026-07-21, bake these in — don't re-derive)

- 3.7 MB CWS, SWF v10, **AS3** (single DoABC, 262 KB), 3 root frames.
- **All content embedded**: 495 DefineSprites, 30 sounds (2.5 MB), shapes +
  JPEG3 + one Lossless2; **no ImportAssets, no DefineBinaryData**. So the
  "fails to load content" is NOT missing level files — it is runtime
  behavior: network loads and/or an engine gap.
- **Not Flixel, not FlashPunk** (zero string hits) — a custom engine. The
  collision/arrayToCSV intrinsics will not transfer; perf is unknown until
  profiled and is NOT this session's concern.
- Runtime network surface: 3× `Loader`, 1× `URLRequest`, 1× `SharedObject`;
  external SWF refs `http://cache.armorgames.com/assets/agi/AGI.swf`
  (ArmorGames API shell), `tracker.swf` / `utils.swf`
  (`tracker.swfstats.com`), plus armorgames.com URLs and a
  `http://local-testing/` string (dev allowance — relevant to the `_secu`
  sitelock suspicion).

## §1 — First: make Ruffle's failure precise (it's the cheapest intelligence)

Before touching our pipeline, characterize what "fails to load some of the
content" concretely is, using local Ruffle (`~/CC/ruffle`, exporter +
desktop; `RUFFLE_MOVIE_URL` and `RUFFLE_INPUT_FILE` precedents exist):

1. Which load fails — `AGI.swf`? the trackers? something else — and with
   what event (IOError? SecurityError? silent hang awaiting COMPLETE?).
2. **Serve stubs**: local HTTP server with the SWF at an armorgames-shaped
   URL and stub responses for AGI.swf/trackers/crossdomain.xml. If stubbed
   Ruffle then runs the game, three things follow: the failure is
   environmental (network expectations), not an engine gap; **the Ruffle
   oracle is restored** for our whole bring-up; and we know our runtime
   needs only load-*stubbing*, not load-*implementation*.
3. If stubbed Ruffle still fails → find the actual API/engine gap it hits
   (Ruffle's log usually names the unimplemented call). That gap is a
   preview of what WE must implement or route around, and "we run what
   Ruffle can't" becomes a concrete claim about that feature.
4. Check the decompile (JPEXS → `~/CC/jpexs/output/elephantquest/`) for how
   the game handles API-load failure — ArmorGames titles usually continue
   without the API shell — and what the world-map loading screen actually
   awaits. Also identify the `_secu` sitelock mechanism (URL check? the
   `local-testing` allowance?) — the `SWF_URL` build-var precedent from
   rwf/rwic is the likely answer on our side.

## §2 — Our bring-up (the RW-sequels staged pattern)

Follow the staged bring-up that carried RWP/RWF/RWIC
([[avm2-rw-sequels-bringup]]): recompile → native boot → trace → frame
dumps, fixing cheap gaps inline and CATALOGING expensive ones instead of
disappearing into them.

- Recompile scratch first (~5 s) and triage recompiler/verifier errors —
  a 2011 non-Flixel codebase will exercise ABC surface the corpus hasn't.
- Known traps, all previously fatal: **boot-death scores PASS vs empty
  expected output — always dump frames**
  ([[avm2-localconnection-silent-blank-stage]]); `arg_present()` is TRUE
  for null args ([[avm2-optional-arg-null-vs-undefined-trap]]); staged wasm
  rots on runtime change (FRESH=1); browser wasm needs the sitelock answer
  from §1.4.
- The Loader-of-external-SWF calls will need a runtime answer: expected
  shape is **stub, don't implement** (dispatch the failure/complete event
  the game's own error path handles, per the §1.4 decompile evidence) —
  runtime SWF loading is out of scope unless §1 proves the game truly
  requires AGI.swf's contents to progress.
- `SharedObject` (save games): check what our AVM2 runtime has; a stub that
  returns an empty store is usually enough to boot.
- Get as far as: native frame dumps showing title → world map → (goal) a
  live level. Every phase state-proven by dump, never by trace silence.

## §3 — Deliverable

1. A per-game plan doc `SWFRecompDocs/plans/avm2-elephant-quest.md`
   (pattern: `avm2-robot-wants-kitty.md`): recon, Ruffle-failure diagnosis,
   our bring-up state (which stage reached, frame evidence), and the **gap
   list ranked cheap → expensive** (recompiler errors, missing builtins,
   stub needs), each with its fix-shape.
2. The oracle ruling: does stubbed Ruffle run the game (full oracle), run
   it partially (oracle to a boundary), or not at all (we fly instruments-
   only past that point — say which point).
3. Memory write: outcome + the engine identification + any new trap.
4. A prompt-ready recommendation for the next session (fix-the-gaps vs
   deeper diagnosis), honestly sized.
5. If runtime/recompiler code ships: pipeline per `.claude/pipeline-handoff.md`
   (no-graphics; graphics too if render paths were touched). A
   diagnosis-only session needs no CI.

## Method rules (binding)

- Single tests locally only; suites via CI. Frame dumps over trace absence.
- Don't fix what you can stub; don't stub what the game's own code path
  can't survive — the decompile decides which.
- New regression tests for any runtime gap fixed go in
  `ruffle-tests/tests/swfs/regression/` ([[custom-tests-live-in-regression-suite]]).
- Perf/footprint measurements are OUT OF SCOPE this session (no rig time);
  note anything alarming, measure later. The 512 MB arena is the default —
  if the game OOMs it natively, that's a finding, not a thing to fix today.
- Commit to master, stage by name, standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents: the JPEXS decompile survey, the stub-server +
Ruffle repro runs, recompile/error triage legwork, frame-dump runs. Fable:
the Ruffle-failure diagnosis call, stub-vs-implement rulings, the gap
ranking, and the next-session recommendation.
