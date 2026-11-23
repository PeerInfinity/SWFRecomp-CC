# One-task session: N telemetry byte-identity + episode 0 levels 1–4 with enemy-engaging routes

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-exec-order` (record
`SWFRecompDocs/plans/n-exec-order-report.md`; ladder `n-play-game` → `n-gold-residue` → `n-tile-color-hud` →
`n-level-complete` → `n-pixel-pass` → `n-collector-uaf` → `n-exec-order`). The session-26 fan-out coordinator launched
you. Baseline: current origin/master. Pull first.

## Goals (in order)

1. **N telemetry byte-identity, the cheap path** (`n-exec-order-report.md` §3/§5.1): sample N's NF line from the
   FRAMELOCK root wrapper instead of the probe's own `__ndrive__` clip (an older sibling, which is why the per-clip
   sibling interleave still shows `h=` at t=56/58). Tooling only (`tools/divergence/game_drive/`, `n_drive`), then show
   the full telemetry byte-identical across the Ruffle exporter, native and browser. Do NOT attempt the exec-list
   rearchitecture (§2b, NO-GO; parked fixture `SWFRecompDocs/plans/n-exec-order-sibling-fixture/`) unless you first price
   it with that fixture and it is cheap.
2. **Episode 0 levels 1–4 with routes that complete them**, so thwumps, drones and other enemies interact with the player
   (`author.py` on the local exporter; hash `r.objects` / `game.objUIDList`, not the pooled GUI clips). Tick-exact against
   Ruffle; fix each divergence at its root cause, with a `regression/` fixture whose golden comes from the Ruffle exporter.
3. If `w2-attached-holder-render` has landed on master by then (check `git log --grep w2-attached-holder-render`): the
   native 1:1 pixel pass (recipe in `n-pixel-pass-report.md` §7).

Tooling notes: memory `n-play-game-click`; `inject_tracer.py --min-version 6` for N; native ASan N runs exceed
`run_native.py`'s 30 s cap — run `build/test_run` directly; the exporter never fires timers, renders HIGH quality only, and
cannot load child SWFs; WSL Chrome is SwiftShader (function only).

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm,
  native N gcc compiles, ASan builds, the recompiler build) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `EMCC_CORES=4`. The coordinator and the Archipelago side use the same lock. Never run full test suites locally.
- The working tree is SHARED with the coordinator. Check `git diff --cached` before every commit; stage only your own
  files by name (`git apply --cached` / a temp index if a file has someone else's edits). `git pull --rebase --autostash`
  is unsafe while others have unstaged edits — prefer `git pull --no-rebase`. Harness trailer on commits.
- **Before committing to `tag.c`/`action.c`/`ng_shared.c`/`swf.c`/the GC sources, message the launching session (the s26
  coordinator) with the function names.**
- CI: if a change is CI-observable, tell the coordinator and it folds your SHA into its next grading run. Don't dispatch
  your own. Pages: the coordinator deploys at closeout.
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-levels-report.md`: the telemetry byte-identity result, levels 1–4 routes and divergences,
  every fix with its fixture, and the next blocker.
- Update memory `n-play-game-click` (don't duplicate it).
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
