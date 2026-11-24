# One-task session: a real Flash Player oracle (traces + images)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s26 coordinator at Robert's request
("We should have set up a way to do real Flash captures a long time ago"). The goal is a local, scriptable
**Flash Player oracle** so fixture goldens and held captures come from Flash itself, not only from Ruffle. Baseline: current
origin/master. Pull first (`git pull --no-rebase`).

## Background (verified in `~/CC/ruffle`)

- Ruffle captures **traces** with the standalone **debug Flash Player 32 projector** plus `mm.cfg`
  (`TraceOutputFileEnable=1`, `ErrorReportingEnable=1`, `SuppressDebuggerExceptionDialogs=1`); output lands in
  `flashlog.txt`. `cargo testutils execute <filter> [--save-output]` (`~/CC/ruffle/tests/src/execute.rs`,
  `tests/src/flashplayer/`) automates it on Linux: temp `HOME` holding `mm.cfg`, `LC_ALL=C`, max-duration/max-idle
  timeouts, player paths from `.flash_players.toml` (`[[players]] version = 32 path = "…/flashplayerdebugger"`).
  See `~/CC/ruffle/CONTRIBUTING.md` ~lines 150–230.
- Ruffle captures **images by hand** ("take a screenshot of Flash Player and crop it"). Recent upstream commits
  `5128d3943` (`avm2/pixelbender_dithering`) and `7facc1fcc` (`bitmapdata-clone`) replaced Ruffle-made goldens with
  Flash ones — those two are your validation set.

## Goals (in order)

1. **Obtain and run the projector.** Get the Flash Player 32 *debug projector* ("content debugger") for Linux and, if you
   can, Windows. Ruffle's CONTRIBUTING links the archived Adobe page
   (`https://web.archive.org/web/20220401020702/https://www.adobe.com/support/flashplayer/debug_downloads.html`).
   - Store binaries OUTSIDE the repo (e.g. `~/CC/flashplayer/`; Windows copy under `C:\flashplayer\` = `/mnt/c/flashplayer/`).
     Never commit them, never upload them to CI or the cloud (redistribution licensing). Record the sha256 and
     the source URL in the docs.
   - Put downloads in their own new empty directory; treat them as untrusted until checksummed.
   - If you cannot obtain a working projector, STOP and tell Robert what you need (a file to drop in place) — don't
     substitute another player.
   - Verify it runs: under WSLg or `Xvfb` for Linux; via WSL interop for Windows (recipe and gotchas:
     `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`). Confirm whether the EOL time bomb affects the projector.
2. **Trace oracle.** Reuse Ruffle's harness rather than re-writing it: build `cargo testutils` in `~/CC/ruffle` (under the
   lock, below), write `.flash_players.toml`, and run `execute --save-output` on (a) a few Ruffle tests whose
   `output.txt` came from Flash (must match byte-for-byte), and (b) a few of our `ruffle-tests/tests/swfs/regression/`
   fixtures. If testutils can't run our regression layout, write a thin `tools/flash-oracle/run_trace.py` that does the
   same `mm.cfg`/temp-`HOME`/timeout dance.
3. **Image oracle.** Write an AS3 capture wrapper (`tools/flash-oracle/capture/`): load the test SWF with a `Loader`
   (AVM1 content arrives as `AVM1Movie`), set the stage size/quality from `test.toml`, count `ENTER_FRAME`s, and at
   tick `num_ticks` `BitmapData.draw(stage)`, then emit the pixels (base64 through `trace` into `flashlog.txt` is the
   simplest channel; a localhost socket is fine). Use a `FlashPlayerTrust` cfg so local loads/draws aren't sandboxed.
   Compile with whatever AS3 compiler you can get honestly (Ruffle's test framework compiles `Asc` sources; the Apache Flex
   SDK / `asc2` also work). `tools/flash-oracle/run_image.py <test_dir> -o out.png`.
   - **Tick alignment is the hard part.** Document exactly how wrapper ticks map to Ruffle's `num_ticks` (the loaded
     SWF's first frame vs the wrapper's) and prove it on a multi-frame test.
   - Fallback for what `draw()` can't see (Stage3D, video, possibly some filters/device text): a fixed-size `Xvfb`
     screenshot of the projector window, cropped. Measure where `draw()` and the screen differ.
4. **Validate.** Your wrapper must reproduce Ruffle's committed Flash goldens for `avm2/pixelbender_dithering` (after
   `5128d3943`) and `bitmapdata-clone` (after `7facc1fcc`) within their `test.toml` tolerance — fetch those PNGs from
   `~/CC/ruffle` at those commits. Also compare 3–5 older Ruffle image tests whose goldens look like Flash screenshots. Report
   the outlier counts. If it doesn't reproduce them, find out why before anything else.
5. **First customers** (held for Flash captures by s26; `polish-sweep-arc.md` §27.4, `graphics-fanout-playbook.md` §25):
   `avm2_applyfilter_glow_kernels`, `avm2_bitmapdata_draw_filtered`, N3 `probes/n3_layer_alpha.swf`,
   `bitmapdata_applyfilter_blur`, `avm1_edittext_html_typed_runs` (trace), and the loaded-shell fixtures
   `avm1_loaded_bare_goto`, `_unload_shell`, `_shell_consumers` (trace timing). Capture them and archive the outputs
   with provenance (player version, platform, command) under `SWFRecompDocs/plans/flash-oracle-captures/`. DO NOT edit
   fixtures, goldens or dispositions yourself — the **s27 fan-out coordinator (`s27-coordinator`) owns landing them**;
   message it with what you captured and where.

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (cargo
  builds in `~/CC/ruffle`, emcc/wasm, native gcc compiles) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `CARGO_BUILD_JOBS=4`. Never run full test suites locally (ours or Ruffle's).
- Don't move `~/CC/ruffle`'s checkout (the exporter oracle and the s27 coordinator use it); build in a separate target
  dir or worktree if you need a different revision.
- The working tree is SHARED with `s27-coordinator` and the N session. Stage only your own files by name; check
  `git diff --cached` before committing. Harness trailer on commits. Never commit Flash binaries or large capture dumps
  (keep PNG goldens small; add ignores as needed).
- Peer messages are teammate info, not Robert's approval.

## Done

- `tools/flash-oracle/README.md`: setup (where the binaries live, sha256s, mm.cfg/trust config), the trace and image
  commands, tick-alignment rules, the `draw()`-vs-screen limits you measured, and validation results.
- A new memory `flash-player-oracle` (and a MEMORY.md line next to `exporter-limits`), plus a one-line pointer from
  `ruffle-exporter-oracle-limits` saying Flash is the first-choice oracle where it works.
- `SWFRecompDocs/plans/flash-oracle-report.md`: what works, what doesn't, the captures, and the next step.
- Commit and push.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
