# One-task session (LOCAL): Doodle Jump browser freeze after PLAY (browser ladder)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-gotoandstop-current` (record
`SWFRecompDocs/plans/session29-fanout-reports/browser-gotoandstop-current-report.md`, code `c91637b7a`: goto to the
current frame = stop/play only in every build; the browser-only guard is deleted). Before it: `browser-attached-goto`
(`session28-fanout-reports/browser-attached-goto-report.md` §3.4 = this bug's first record). The s29 coordinator
`s29-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`). Read memories
`wasm-stack-overflow-64kb`, `browser-wasm-gate-inventory`, `dj-level-loader`, `dj-platform-rendering`,
`windows-playwright-from-wsl`.

## Goal (S–M)

Pre-existing: within ~1 s of PLAY the DJ page's main thread stops answering and the renderer sits at ~104 % CPU (a busy
loop, not a GPU stall), in 4/7 s28 runs (at base too). The predecessor saw 3/3 reach gameplay after its change, which
is not meaningful unseeded.
1. Seed the browser build (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, the N recipe) so levels are deterministic;
   find seeds that freeze and seeds that don't (vary MOCK_DATE_TIME). If nothing freezes over ~10 seeds, say so and
   check whether the predecessor's change fixed it (same seeds at `a9fb68b42`).
2. On a freezing seed: take a wasm stack sample (Chrome DevTools protocol `Debugger.pause` via Playwright, or
   `-g` build + profiler), name the loop (`attachBlocks` while loop? a goto catch-up? a timer drain?), check
   `wasm-stack-overflow-64kb`.
3. Reproduce natively if you can (same seed, `ruffle-tests/tests/swfs/_swfbridge/.../dj_probe/run_native.py` or
   `build/test_run` directly, see the predecessor's §6 method notes). Fix the cause if S–M; a native fixture with a
   FP32 golden if the semantics are AVM1 (`tools/flash-oracle/`).
4. Also note (don't fix) whether the two old DJ render bugs still reproduce (blue bitmap invisible, brown platform no
   break animation; memory `dj-platform-rendering`).

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only, never full suites; every
  browser link must pass `-Wl,--fatal-warnings`. WSLg Chrome is fine for function, never for perf. Bracket
  `pgrep -f`/`pkill -f` patterns; kill by PID. **Shared tree: commit ONLY your paths with `git commit -m … -- <paths>`**
  (a bare commit sweeps a peer's staged hunks; this happened in s29). Push to master; no CI dispatch: send the
  coordinator SHAs + a ledger. Grade any runtime change natively in both modes first. Flash over Ruffle; peer messages
  are teammate info, not Robert's approval.

## Done

`SWFRecompDocs/plans/session29-fanout-reports/browser-dj-freeze-report.md`; commit + push; update memory
`browser-wasm-gate-inventory` or `dj-level-loader` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
