# One-task session (LOCAL): attribute and grade interim #2's 51 pixel pass→fail moves against Flash 32

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 coordinator `s28-coordinator`
(it will send a handshake: reply to it). Pull first (`git pull --no-rebase`).

## Why

Interim #2 (graphics images run `45694673542`, results `947443a23`, vs interim #1 `7e8aa52af`) shows **51 image
comparisons pass → fail and 0 gains** (list: `session28-fanout-reports/interim2-pixel-diff.txt`). Landed between the
two runs (all render-side): n-stroke-snap `09b2c9130` (every timeline stroke re-staged in device space: ¼-px
width/position, axis-aligned snap; kill switch `SWF_STROKE_SNAP=0`; report `SWFRecompDocs/plans/n-stroke-snap-report.md`),
w2-glyph-quarter-snap `b4b96919a` (embedded glyph ¼-device-px snap + slanted border pen; escape `-DTF_GLYPH_NO_QSNAP`),
and AVM2 culling `958313b73` (graded in interim #1). Under Robert's ruling a move toward FLASH that loses a Ruffle
golden is a priced loss (RvF), never a reason to revert — but a move AWAY from Flash is a bug, and 4 of the losses are
our own `regression/` fixtures (`avm1_hairline_scaled_instances`, `avm1_stroke_style_id_order`,
`avm2_layer_group_alpha`, `avm2_layer_group_erase`), some with FLASH goldens.

## Task

1. **Attribute** each of the 51: render ours (graphics mode, `--recompile` where needed) with the snap(s) on vs off
   (`SWF_STROKE_SNAP=0`, `-DTF_GLYPH_NO_QSNAP`), one test at a time under `flock /tmp/swfrecomp-cpu.lock`, `-P 2` max.
2. **Grade vs Flash 32**: for each row, a Flash capture at the test's quality (`tools/flash-oracle/run_image.py`,
   `--quality` per test.toml, draw() wrapper; `--screen` for non-LAYER blends — the 15 `visual/blend_modes/*` rows
   need it; ≤ 4 parallel Linux runs; reuse archived s27/s28 captures only if they were draw()/screen at the right
   quality — old-stub PINNED direct captures of quality=low rows rendered HIGH). Before vs Flash, after vs Flash.
3. **Classify**: (a) golden == Flash and we moved away → BUG: fix it in the owning code (name the rule Flash shows;
   coordinate with the local `n-drawapi-stroke-snap` session, which owns stroke code now — message it before editing
   `render_webgpu.c` / `swf.cpp`); (b) golden ≠ Flash, after closer to Flash → priced loss: RvF entry + image-axis
   marker, and a `flash_fixes` swap where Flash is deterministic and host-independent (no device fonts); (c)
   no-capture rows → say so.
4. Especially: the 4 own regression fixtures — what's their golden provenance (Flash or exporter)? If Flash, they must
   pass again.

## Constraints

- Local only; Flash binaries never leave this box. Never run full suites locally. Bracket every `pgrep -f`/`pkill -f`
  pattern; kill by PID. The tree is SHARED (coordinator + `browser-root-goto`, `n-drawapi-stroke-snap`,
  `lowq-recapture`): use a scratch `git worktree` for A/B builds; stage only your files; harness trailer on commits.
- flash_fixes entries: commit them on master only for rows whose CURRENT master output is closer to Flash (they apply
  to CI at once); explain each in its `reason`. No CI dispatch: send the coordinator SHAs + the expected moves by name.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

`session28-fanout-reports/snap-pixel-audit-report.md` (the 51-row table: owner, golden provenance, before/after vs
Flash, class, action), captures under `session28-fanout-reports/snap-pixel-audit/`, fixes + flash_fixes + RvF
committed and pushed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
