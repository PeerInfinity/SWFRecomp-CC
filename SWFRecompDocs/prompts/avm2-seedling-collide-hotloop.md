# AVM2 — Seedling's collide hot loop: diagnose the helper cost, ship the cheapest measured lever (slice `swfrecomp-seedling-hotloop-1`)

You are `swfrecomp-seedling-hotloop-1`, an Opus session in `~/CC/SWFRecomp-CC` (cwd), branch `master`. This repo's
`CLAUDE.md` governs: trunk-based, autonomous commit / push / CI per `.claude/pipeline-handoff.md` (an AVM2 runtime change ⇒
`categories=full`, `graphics` mode; when in doubt for shared runtime code run both modes). Your planner is
`seedling-headless-planning-5` (a Fable session in `~/CC/Archipelago-CC`); it launched you and will HANDSHAKE you — reply to
that message's `from` for every report. ⚖ user 2026-09-16: *"launch an Opus session in SWFRecomp-CC to work on the
recompiler hot loop issue."*

## The issue, already measured (read these FIRST)
- `SWFRecompDocs/BACKLOG.md` § "AVM2 — performance", first entry (commit `7a3358858`): Seedling's first `Game.update()`
  after the menu level loads takes ~10 s. The ALGORITHM is the game's (FlashPunk's `Tile.check()` makes four
  `Entity.collide("Tile", …)` linear walks over the whole Tile list: ~11.7 M AABB tests on L12); the COST is ours: ~800 ns
  per test, vs ~7.5 ns for the same loop as plain JS on V8. 77 % of the frame is generic AVM2 value helpers called from
  the compiled loop body (`abc0_m96` = `Entity.collide`, 575 lines): property gets through the inline cache 38.5 %
  (`avm2_op_getproperty_static_ic` `SWFModernRuntime/src/avm2/avm2_ops.c:798` 2.16 s, **`resolved_get` 1.59 s** — the
  slow path, so the IC is MISSING or not applying inside this loop; `avm2_value_vtable` `avm2_class.c:1640` 0.34 s), boxed
  numeric add/coerce 15.9 % (`avm2_op_add_values` `avm2_value.c:970`, `coerce_to_primitive`, `coerce_to_number`), type
  checks 12.8 % (`avm2_value_is_of_type` `avm2_class.c:1733`, `coerce_to_class`, `coerce_to_type_mn`); the compiled body
  itself 21.9 %; allocator + GC 1.5 %; E4X 0 %.
- Evidence: `tools/divergence/perf/seedling_c4_2026-09-14/` — `demo-load.cpuprofile` (the 10.5 s frame, sampled at
  ~205 µs), `p4d-boot.cpuprofile` (the bot build's 1.3 s boot frame: 58 % synchronous mp3 decode + 25 % the same collide
  pass on the 6× smaller L0), `results.txt` (the phase table), `phases.mjs` / `analyze.mjs` (how the phases were cut from
  the profile), `jitcontrol.mjs` (the V8 control). The write-up is Archipelago-CC's plan §23.1.3 (a gitignored file on
  this machine: `~/CC/Archipelago-CC/NewDocs/plans/seedling-headless-webgpu-plan.md`).
- Prior Seedling perf work in THIS repo, and the discipline it followed: `SWFRecompDocs/reference/performance-
  optimizations.md` §1 (the Seedling arc's levers — the getproperty IC `c608083d4`, slot specialization, coercion
  elision, the coerce-class memo — exist already; this loop defeats them, and WHY is the first question) and **§7
  Measurement rules (binding)**; `tools/divergence/perf/SEEDLING_AB_STATUS.md` (how an A/B is recorded: interleaved
  rounds, medians, a `-D…` toggle that gates exactly the lever, byte-identity as the correctness bar).

## Rules (each was paid for)
- **§7 is binding.** Wall-clock decides, Ir attributes; prove the phase (this frame is the first `Game.update` after
  `Splash.startMenu` — state-attest it: frame index, the `printItems` dump one frame earlier, a screenshot); byte-identity
  is the correctness bar (a `-DAVM2_*_VERIFY` dual-run build and/or the frame/trace oracle; full-suite CI in normal and
  verify modes); `FRESH=1` after any widely-included struct change; **§7 rule 6**: before touching an O(n²)-adjacent cost,
  instrument WHICH input — an env-gated counter that splits the candidates (IC hit / miss per site, boxed vs unboxed adds,
  which multinames miss and why) is cheap and decisive. The diagnosis comes BEFORE the lever.
- **The measured frame is CPU-bound** (C4: cpu ≈ period, present 0.4 ms, `__swfGpu` lost) — so headless logic-only
  Chromium is a valid instrument for THIS frame's wall, and the repo's own harness is right here:
  `tools/divergence/perf/cdp_profile.py` (CDP sampling profile, self-time by function) and `n_swfrecomp_perf.py` (reads
  `__swfPerf`), documented in `tools/divergence/perf/README.md`. For the A/B rounds, §7 rule 2 stands if you can drive
  real-GPU Windows Chrome (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); if you measure headless, say so and why it is valid here.
- **Build inputs are the pins' inputs, and the pins are NOT yours.** The SWFs: `~/CC/seedling_original_build/
  Seedling_original_r1.swf` (md5 `a543c03a36996debb57d8abaa3312b44`, 7,835,438 B) and `~/CC/seedling_bot_build/
  Seedling_bot_ap_r1.swf` (`da451bfb4deecd5d16aad96b187b39d6`, 9,743,894 B); R3's recompiled C: `~/CC/seedling_original_
  build/recompiled_orig_r3` and `~/CC/seedling_bot_build/recompiled_r3` (from the recompiler at `bdf734c46`, this repo's
  parent of `7a3358858`); the build script `SWFRecomp/scripts/build_wasm_avm2.sh`. A runtime-only lever relinks those
  objects; a recompiler-emission lever re-recompiles from the SWFs. ⛔ Archipelago-CC's pinned wasm builds
  (`frontend/modules/flashPanel/wasm`, a submodule of `PeerInfinity/seedling-wasm`) stay untouched: a re-pin is the
  planner's separate ask (a moved tape there is a STOP, ⚖ 49). Your deliverable is a lever on `master` with its A/B.
- **Stage BY PATH; commit per step; the repo's trailer.** Docs: a row in `performance-optimizations.md` §1 (or §6 if the
  lever is rejected — a rejected lever with numbers is a result) and an entry in `SEEDLING_AB_STATUS.md` in its shape.
  This repo's memory directory is its own (`~/.claude/projects/-home-robert-CC-SWFRecomp-CC/memory/`) — update it per
  its conventions.
- **Scope:** the collide-loop helper cost only. The synchronous mp3 decode (the backlog's second entry) is NOT this slice.
  One lever, measured, or a measured verdict that the cheapest lever is not worth shipping — not a rewrite.

## W0 — measure before any change
Reproduce the profile on this tree's build of the demo (relink with `--profiling-funcs` from the R3 objects as C4 did
— names stripped = the pinned bytes, prove it by md5 `1d3fac3e143e6edd3676d3826dff63ba`); the phase table matches
`results.txt` within noise. Then the §7-rule-6 counters: per IC site in `abc0_m96`, hit / miss counts and the miss
reason (vtable identity? count guard? a receiver whose class is not the IC's? a `Tile` subclass mix?); per `add` site,
boxed vs integer/double fast path; per `is_of_type` / `coerce_to_class` site, the class asked for and whether it is
compile-time known. The counters are the diagnosis; write them down before choosing the lever.

## Tasks
1. **Diagnosis** (the counters above) → which ONE mechanism dominates and why the existing IC / slot / coercion levers
   miss it. A short doc section (a `SWFRecompDocs/status/…` file in the repo's shape) with the numbers.
2. **The lever**: the cheapest change that addresses that mechanism (candidates the profile suggests, unmeasured: a
   monomorphic fast path the IC takes on a sealed-class receiver in this loop's shape; keeping unboxed Numbers through
   `add` on the loop's locals; hoisting the repeated `is_of_type` check out of the per-element path) — behind a `-D`
   toggle that gates EXACTLY it (SEEDLING_AB_STATUS's rule), with a verify build. Byte-identity: the demo's
   `AVM2_CPU_DUMP` oracle or trace across the load + the first 600 frames, ON vs OFF.
3. **The A/B**: ≥5 interleaved rounds ON/OFF on the demo's k=544 frame and on p4d's k=1 boot frame, medians; the whole
   per-frame table around them unchanged elsewhere (no regression on the steady-state frames).
4. **CI**: push; `ruffle-tests.yml` `categories=full` in `graphics` (and `no-graphics` if shared runtime code moved);
   regressions by name; the results branch merged per the pipeline handoff.
5. **Docs + status + memory** per the rules above.

## Report back (to the planner's address, deltas only, then idle)
ONE message to the planner: start HEAD → pushed HEAD (which commits), the diagnosis in two sentences (the dominant
mechanism and why the existing levers missed it), the lever and its toggle, the A/B medians (k=544 ON/OFF, p4d k=1
ON/OFF), byte-identity evidence, CI run ids and verdicts, what this brief got wrong, and whether a re-pin of
Archipelago-CC's builds is warranted (the planner asks the user). Your planner ends this session after verifying your
report; leave nothing running (servers stopped by PID, no scratch builds left in the tree).

REPORT BACK (after the durable records — never instead of them): reply to the handshake message from the session that
launched you (copy its `from` attribute as your SendMessage `to`); if no handshake arrived, run ListAgents and look for
`seedling-headless-planning-5`; if unreachable, skip silently — the status doc is the record.
