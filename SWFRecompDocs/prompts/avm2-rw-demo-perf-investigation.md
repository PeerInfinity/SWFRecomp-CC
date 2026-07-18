# Session prompt — Robot Wants demo performance investigation (all four "surprisingly bad")

User report (2026-07-19): all four Robot Wants docs2 demos (`rwk`, `rwp`,
`rwf`, `rwic`) **play, but performance is surprisingly bad** in the user's own
browser — and, crucially, **Seedling retested significantly BETTER than RWK
in the same browser**. That inverts the known cost order: Seedling is our
heaviest game (~32.6 ms/frame on the rig) and RWK measured **5.1 ms/frame
(~195 fps capacity, present 0.6 ms)** at RWK-3 — ~6x lighter. All deployed
demo wasms are the same 2026-07-18 vintage (seedling 11:35, rwk 13:53,
sequels 15:31–15:50), so the comparison is apples-to-apples on the runtime:
something the **RW family specifically** does is slow in a real browser, and
it largely rules out "user environment" as the primary cause. Your job:
quantify, attribute, and either fix or precisely hand off the cause. Do NOT
start optimizing anything until the decision tree below says which fork
you're in.

**Prime suspect given the Seedling-vs-RWK split: GC collect behavior under
Flixel's churn.** Seedling idles DEAD FLAT (~0 KB/tick, census 2.2k/1.4k —
collects essentially never fire), while RWK gameplay churns strings hard
(HUD sawtooth: 8k→125k live strings over ~60s, then a collect over an ~85k
object + 100k+ string census). If a collect pauses tens-to-hundreds of ms in
browser wasm, the RW family stutters rhythmically and Seedling doesn't. The
sequels churn even harder (heap peaks 1577/1770 MB vs RWK's ~1409). Frame-
time distribution (step 1.3) is the discriminator: collect hitches show as
clean p95/max spikes at regular intervals with a normal p50; sustained
per-frame cost shows as an elevated p50. A second suspect with the same
signature-split: total wasm memory footprint (RW family grows the heap far
larger than post-GC Seedling) — browser-side effects of a multi-GB
ArrayBuffer. The rig data will separate these.

Read first: CLAUDE.md "Browser Performance Measurement" (the Windows rig is
the ONLY valid perf instrument; WSL Chrome frame times are SwiftShader
artifacts), `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`, memories
`avm2-rwk3-browser-demo` (the 5.1 ms baseline + how it was measured),
`profile-game-native-n-is-noisy` (native totals swing 13% — NEVER naive A/B),
`browser-perf-is-writebuffer-not-avm1-walks` (prior browser-perf attribution
lesson), `avm2-hud-counters-are-real-sawtooth` (HUD counters are real now;
census sawtooths).

## Why a regression is plausible (the suspect window)

RWK-3's 5.1 ms measurement predates most of the GC arc. The deployed demos
now include, in landing order:

- `c0e0b3493` collectable strings (per-allocation census enroll; mark+sweep
  over ALL live strings each collect; conservative ext scan now also
  range-matches strings)
- `c9678c553` raw-alloc reclamation (et_relayout frees, per-call scratch
  frees, tombstone purge in sweep)
- `adec1e505` weak orphan registry (post-mark prune pass)
- `77f0d928b` real HUD counters (trivial getters — unlikely, but in window)
- `e3102fb29`/`ea77c3769` LocalConnection + SWF_URL (sequels session)

Two distinct degradation shapes to distinguish:
- **Sustained per-frame cost** (every frame slower): per-allocation overhead,
  or something environmental (software rendering, wrong adapter).
- **Periodic hitches** (stutter): collect pauses. A collect now walks ~85k
  objects + up to ~125k strings (the sawtooth peak) — if that costs tens of
  ms it reads as a rhythmic stutter, roughly once a minute for RWK idle,
  possibly much more often in the bigger sequel worlds (Fishy/IceCream heap
  peaks 1577/1770 MB imply far more churn → more frequent collects).

Also note: the deployed .wasm files may be a MIXED bag of build vintages
(check mtimes vs commit times — the staleness lesson). Rebuild all four from
HEAD before measuring anything.

## Step 0 — user context (ALREADY PROVIDED 2026-07-19)

The user confirms: **general slowdown AND a rhythmic pause** in RWK, and it
is **unplayably slow in BOTH Firefox and Chrome**. Consequences:
- Fork B (environment) is effectively dead — two engines, same result, and
  Seedling is fine in the same browsers.
- The rhythmic pause matches the collect-hitch signature; the *general*
  slowdown on top of it suggests collects fire often enough to also drag the
  average (or a second sustained cost exists — the distribution will say).
- "Unplayable" vs RWK-3's 5.1 ms is a ~10x+ effect — look for something
  pathological, not marginal.

**Sharpened hypothesis — check this FIRST (native, minutes):** the GC
watermark triggers on GROSS bytes allocated since last collect, not net
growth. Flixel churns enormously even at ~zero net (per-frame FlxText/HUD
string rebuilds; RWK-2 had to stopgap `arrayToCSV` at 4 GB because single
calls allocate MBs of strings — find who calls it and how often). If RWK
gameplay grosses several MB/sec against a ~4 MB watermark, collects fire
every 1–3 s, each now paying the post-`c0e0b3493` price (string census
snapshot rebuild + sort, byte-range marking, conservative ext scan against
the string census, orphan prune) over an ~85k-object / 100k+-string census.
That single mechanism produces BOTH observed shapes and the Seedling split
(Seedling's gross churn is tiny post-fixes). Measure: gross alloc rate
(bytes_since_collect growth), collect frequency, and per-collect duration
(TEMP env-gated timer) during native RWK gameplay. If confirmed, candidate
levers in rough order of cheapness: adaptive watermark (scale with live-set
size, e.g. `max(default, k × live_bytes)` — collect frequency then tracks
retention, not churn), cutting the dominant churn source at the runtime
level if it's ours (e.g. a scratch path still allocating census strings),
or making the collect itself cheaper (incremental/generational = a real
project, don't start it in this session). Any watermark change must re-run
the GC-correctness ladder AND re-verify the leak-arc soak targets (RWK +
Seedling KB/tick numbers must not regress — less frequent collects must not
reopen "browser OOMs after N minutes").

## Step 1 — objective measurement (Windows rig, rebuild first)

1. Rebuild + redeploy all four demo wasms from HEAD (incremental is fine).
2. On the Windows rig (`python.exe` + the `seedling_perf_win.py` pattern;
   scripts in `/mnt/c/playwright/`): for each of the four RW demos **plus
   Seedling as the control** (the user's report says it should measure
   markedly better — if the rig disagrees with that ordering, say so loudly,
   it changes everything), record the
   WebGPU adapter string (MUST be the real GPU — abort and fix the harness if
   SwiftShader appears), then steady-state ms/frame at the menu AND ~60s into
   gameplay where reachable (RWK gameplay is reachable via real clicks;
   sequels' menu buttons need a real press-release across ticks — a click at
   human speed works, the RW-sequels session's synthetic single-turn click
   does not).
3. Capture frame-time DISTRIBUTION, not just the mean (p50/p95/max) — that's
   what separates sustained cost from collect hitches.
4. Reference points: RWK today vs the 5.1 ms RWK-3 baseline; and one Ruffle
   run of the same SWF for scale.

## The decision tree

- **Fork A — RWK regressed on the rig** (today ≫ 5.1 ms or big p95 spikes):
  bisect the suspect window. Cheap native first pass before any wasm
  rebuilds: time ms/tick native (AVM2_MAX_TICKS bounded, state-identical
  runs) at HEAD under `AVM2_GC=0` / `AVM2_GC_STRINGS=0` / default — the env
  kill switches isolate the GC arc's steady cost in one build. Add a TEMP
  per-collect duration print (env-gated, alongside AVM2_GC_VERBOSE) to
  measure pause length directly. Then wasm-rebuild only the SHAs the native
  data implicates. Remember the 13%-noise rule: fixed tick counts,
  same-machine, repeated runs, compare distributions not single totals.
  Whatever the fix is, the GC-correctness bar applies: traces byte-identical
  normal/stress/GC=0, both CI modes, zero pass→fail.
- **Fork B — rig numbers are fine (~RWK-3-class), including distributions**:
  unlikely given the Seedling-vs-RWK split in the user's browser (same
  vintage, same host — a pure environment problem would hit Seedling
  hardest, not least), but if the rig is truly clean: measure Seedling on
  the rig too, and find what differs in the user's browser (adapter,
  power-save GPU, browser version). Either way, add the adapter string +
  live ms/frame to the demo page footer (tiny, permanent, makes every
  future "feels slow" report self-diagnosing). Report; don't optimize the
  runtime for a software-rendering path.
- **Fork C — RWK is fine but the sequels are slow**: per-game problem.
  Profile one slow sequel via CDP self-time (the Seedling-perf method:
  `EMCC_CFLAGS=--profiling-funcs`, symbolized flamegraph). Suspects, in
  order: collect frequency/pause scaling with their much larger churn (the
  1577/1770 MB heap peaks say allocation volume is ~5x RWK's), bigger
  tilemap blit volume (130×112/130×120 worlds vs RWK's 188×84 — check
  visible-tile counts), near-arena-capacity effects. Fix only what the
  profile names; the seedling-perf memories document how wrong guessed
  levers were last time.

## Rules

- No perf number from WSL Chrome, ever (CLAUDE.md). Functional checks only.
- Never A/B on single noisy totals; distributions, fixed workloads.
- Any runtime change: full GC-mode trace-identity verification + both CI
  modes + demo redeploy + Archipelago-CC restage if a staged .c changed.
- Temp instrumentation (per-collect timer) stays out of commits unless it
  earns permanent env-gated status in its own right.

## Budget note (delegation)

**Fable-led, delegating measurement legs to Opus** — this is the
attribution-risk profile where wrong conclusions cost days (see the
seedling-perf lever-map memory: the #1 guess was wrong even WITH a profile).
Opus subagents: rebuilds, rig runs, data collection, bisect builds. Fable:
reading the distributions, choosing the fork, naming the lever, and any GC
changes.

Finish per `.claude/pipeline-handoff.md`; write a session memory with the
fork taken, the numbers (before/after, all four games), and the fix or
handoff. Update the RW sequels plan doc §6 (the two unmeasured items —
in-browser PlayState for rwf/rwic — may get resolved for free by the rig's
real clicks; record it if so).
