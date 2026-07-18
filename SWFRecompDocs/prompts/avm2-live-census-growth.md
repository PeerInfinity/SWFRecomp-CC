# Session prompt — AVM2 live-census growth (Seedling residual ~9.5 KB/tick)

> **STATUS: COMPLETE 2026-07-18.** Verdict: over-retain in our runtime — the
> orphan display registry was a strong GC root (Ruffle's is weak). Fixed by
> weak-orphan pruning; Seedling-teleport idle 9.5 → ~0 KB/tick, menu 2.0 → ~0,
> RWK unchanged. See memory `avm2-weak-orphan-registry` and the avm2 suite
> `CURRENT_STATUS.md` entry.

You are finding the **retention path behind the last AVM2 Seedling leak**. After
collectable strings (`c0e0b3493`) and raw-alloc scratch reclamation
(`c9678c553`), RWK gameplay is essentially flat (~1 KB/tick, accepted), but
**Seedling-teleport overworld idle still grows ~9.5 KB/tick and the growth is
LIVE CENSUS GROWTH, not scratch churn**: over 300→2400 ticks, live objects go
15.2k→19.5k and live strings 8.6k→21.3k — roughly **2 objects + 6 strings per
tick stay reachable**. The stock Seedling **menu** grows ~2.2 KB/tick with the
same signature. This is a *retention* problem: something keeps marking these
allocations live. The deliverable is the retention-path verdict — legitimate
game state, an over-retain in our GC/runtime, or a conservative-scan artifact —
and a fix only where it's genuinely ours to fix.

Read first: memories `avm2-raw-alloc-reclamation` (baseline numbers, ownership
rules, the fn_scope aliasing proof), `avm2-collectable-strings` (escape-surface
map — the root/pin list is the census of *who can mark strings*),
`avm2-stage11-gc` (sweep semantics), `seedling-teleport-gameplay` (the teleport
SWF build recipe), and
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`.

## Measured baseline (2026-07-17, commit `c9678c553`)

Seedling-teleport native, overworld idle (no input events, deterministic via
MOCK_DATE_TIME; boots straight into OverWorld1 gameplay — FlashPunk per-frame
bd.draw + HUD):
- allocated grows ~9.5 KB/tick steady-state
- `AVM2_GC_VERBOSE=1` collect lines (`[avm2-gc] #N live=... strings live=...`,
  avm2_gc.c:588): live objects 15.2k→19.5k, live strings 8.6k→21.3k over
  300→2400 ticks. THE CENSUSES ARE NOT FLAT — that's what distinguishes this
  from the previous session's scratch-churn leak.
- Stock Seedling menu: ~2.2 KB/tick, same live-growth signature. The menu is
  the **simpler scenario** (no gameplay loop) — if it shows the same growing
  classes/strings, debug there first.
- RWK gameplay ~1 KB/tick residual = fn_scope over-retain, ACCEPTED — do not
  chase it, and **do NOT free fn_scope chains: PROVEN aliased**
  (`avm2_op_newactivation` stores the running closure's fn_scope as
  `method_scope` in activation vtable entries; freeing at closure sweep is a
  UAF). Refcounting stays deferred.

## Reproduction

Ready builds likely survive from the prior session at
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/d660fcf2-f6ad-4dff-b80d-9c873e957aa0/scratchpad/`:
`seedtp_build/test_run` (teleport, at `c9678c553`), `seedling_build/` (stock
menu), plus the prior APROF outputs `aprof_300.txt`/`aprof_2400.txt`. Reuse if
no runtime change has landed since; /tmp does not survive reboots — rebuild
recipe:

```bash
SCR=<your scratchpad>
# Teleport SWF (prebuilt): ~/CC/seedling_teleport_build/Seedling_teleport.swf
# Stock menu SWF:          ~/CC/newgrounds/598977_Seedling.swf
mkdir -p $SCR/games/seedtp && cp ~/CC/seedling_teleport_build/Seedling_teleport.swf $SCR/games/seedtp/test.swf
echo -n > $SCR/games/seedtp/output.txt && echo 'num_frames = 1' > $SCR/games/seedtp/test.toml
# Single-DoABC teleport SWF needs -O0 + a longer compile timeout (13 MB TU):
SWFRECOMP_OPT_LEVEL=-O0 SWFRECOMP_COMPILE_TIMEOUT=900 \
  KEEP_BUILD_DIR=$SCR/seedtp_build python3 ruffle-tests/verify_output_keep.py --test=seedtp --tests-dir=$SCR/games
# Measure (TZ=NPT-5:45 for determinism parity with prior numbers):
AVM2_MAX_TICKS=300  AVM2_HEAP_STATS=1 AVM2_GC_VERBOSE=1 ./test_run 2>gc300.log
AVM2_MAX_TICKS=2400 AVM2_HEAP_STATS=1 AVM2_GC_VERBOSE=1 ./test_run 2>gc2400.log
# delta(Allocated)/2100 = KB/tick; compare live=/strings live= trajectories
```

Knobs: `AVM2_GC_VERBOSE`, `AVM2_HEAP_STATS`, `AVM2_MAX_TICKS`, `AVM2_GC_STRESS`
(collect every tick), `AVM2_GC=0` (off), `AVM2_GC_STRINGS=0`,
`AVM2_GC_WATERMARK`.

## Tooling — attribute the growth by CONTENT, not just by site

The leak is census-visible this time, so the census itself is the best probe.
All instrumentation below is TEMP (env-gated, kept out of commits):

1. **Census class histogram diff** (primary): at collect time (env-gated, e.g.
   `AVM2_GC_CENSUS_DUMP=1`), walk the object census and print a per-class live
   count (`obj->vtable->cls` name), and for strings print each live string's
   address + first ~40 bytes. Diff tick-300 vs tick-2400 dumps: the growing
   classes appear immediately, and **growing string CONTENT usually names the
   culprit outright** (event type names, level keys, number-formatted text…).
   6 strings/tick over 2100 ticks ≈ 12k new live strings — a `sort | uniq -c`
   of contents will collapse them to a handful of shapes.
2. **Retention-path probe**: once you know WHAT grows, find WHO marks it.
   Instrument the mark path (mark_value / precise ext tracers / conservative
   ext scan / root markers from the collectable-strings escape-surface list)
   to log the marker for a sampled address. Distinguish:
   - real object graph reachability (game state or our runtime's stashes),
   - root markers (E4X all-nodes registry, display statics, alias tables),
   - **conservative ext-scan false positives** (byte-range matching can pin
     dead strings via stale words — if the growth stops under a precise-only
     experiment, that's the story).
3. **Alloc-site PC histogram** (secondary, from last session — worked well):
   ~20-line temp patch to `avm2_alloc`: histogram keyed by
   `__builtin_return_address(0)`, print `APROF-BASE <known symbol addr>` once
   plus `APROF <ret> <bytes> <count>` lines at exit; symbolize with
   `addr2line -e test_run` after subtracting the slide. Prior outputs for the
   teleport scenario survive as `aprof_300.txt`/`aprof_2400.txt` in the old
   scratchpad — diffing those two may already rank the growing sites.

## Suspects (from the raw-alloc session, unverified — attribute before fixing)

1. **E4X immortal all-nodes registry** — `avm2_e4x_node_new` enrolls every
   node forever and `avm2_gc_mark_roots_e4x` marks each node's strings +
   `obj`/`notify` edges every cycle → **any repeated XML parse roots its whole
   tree + strings permanently**. Seedling parses `.oel` levels via `new XML()`.
   If anything re-parses XML periodically (or per menu tick), this is the
   leak. If confirmed: making E4X nodes collectable was deliberately deferred
   as its own project — measure the share, do the *minimal safe* reclamation
   only if it's clean (e.g. free a tree whose root object is swept and
   unreferenced), otherwise write up the case and let the user green-light the
   dedicated session.
2. **fn_scope entry captures** — activations captured as scope entries of
   live closures keep whole frames (and everything they reference) alive. If
   something registers a fresh closure per tick (enterFrame listener churn,
   Flixel/FlashPunk callbacks), each closure's chain retains its frame. The
   fix would be at the *registration* leak (listeners never removed), NOT at
   fn_scope freeing.
3. **A growing Array/Dictionary** — FlashPunk/FlxG world lists, event listener
   lists, broadcast buckets, recycle pools. Growth here may be LEGITIMATE
   (entity recycle pools are by-design caches, usually bounded) — check
   whether it plateaus.
4. **Our own runtime stashes** — anything appending per-tick to a rooted
   structure (timer args, EI callbacks, SoCache, display statics, broadcast
   lists). The collectable-strings escape-surface list is the checklist.

## Method

1. Reproduce the baseline numbers first (both scenarios if cheap).
2. Class-histogram + string-content diff → name the growing types.
3. Trace the retention path for one representative instance. Don't fix blind.
4. Verdict per growing type: **game state** (document in the session memory,
   accept), **over-retain in our runtime** (fix, with a single-owner /
   unreachability proof per free — over-retain, never dangle), or
   **conservative-scan artifact** (fix the scan or document the bound).
5. Remeasure after each fix; record per-fix attribution. Soak target:
   Seedling-teleport idle live counts and allocated delta ≈ flat over
   300→2400 (< ~1 KB/tick); menu flat; **RWK numbers unchanged** (don't
   regress its 1.03 KB/tick or its byte-identical traces).

## Grading (same bar as the last two memory sessions)

- Traces byte-identical normal / `AVM2_GC_STRESS=1` / `AVM2_GC=0` on the
  measured scenarios + the `avm2_gc_*` regression tests (3 GC modes). ASAN +
  `-DHEAP_PASSTHROUGH` if anything smells.
- Sample ~10 avm2 suite tests locally (single tests only — NEVER the full
  suite locally) covering e4x/xml, events, closures, text: default == stress.
- **BOTH CI modes + a no-graphics `avm2_gc=1` stress dispatch, zero
  pass→fail** (pipeline per `.claude/pipeline-handoff.md`).
- If runtime .c changed: incremental wasm rebuild + redeploy the three demos
  (rwk, seedling, seedling_teleport_ap) + restage Archipelago-CC's staged wasm
  (staleness lesson in `avm2-flashpunk-text-font-name-resolve`). FRESH=1 only
  if a struct layout changed.
- Browser sanity: Seedling-teleport demo memory over a few minutes of idle
  should now be ~flat.

## Budget note (delegation)

Fable session, but delegate the mechanical legs to **Opus subagents**
(`model: "opus"`): rebuilds, running the tick sweeps, collecting/symbolizing
APROF + census dumps, sampling suite tests, CI babysitting. Keep on Fable: the
retention-path analysis, each free-site safety proof, and the
game-state-vs-over-retain verdicts.

## Boundaries

- Core runtime only (`SWFModernRuntime/src/avm2/`); do NOT touch AVM1.
- Do NOT free fn_scope chains (aliased — see above). Do NOT regress stage-11 /
  collectable-strings semantics (collect between ticks; over-retain on
  mark-OOM; string census invariants; enumeration order).
- Full E4X collectability is out of scope unless it's proven dominant AND has
  a minimal safe fix; otherwise document and defer.
- Temp instrumentation (census dump, APROF, mark-path logging) stays out of
  commits — unless a probe proves broadly useful, in which case propose it as
  a permanent env-gated diagnostic in its own commit.

Finish per `.claude/pipeline-handoff.md`; update the avm2 suite
`CURRENT_STATUS.md`; write a session memory with the per-type retention
verdicts, per-fix attribution, and final KB/tick + live-count numbers.
