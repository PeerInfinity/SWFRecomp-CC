# One-task session (LOCAL): fix the two LOW-model defects, then hand the coordinator a landable lowq package

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 coordinator `s28-coordinator`
(it will send a handshake: reply to it). Pull first (`git pull --no-rebase`). You succeed `lowq-recapture` (report
`session28-fanout-reports/lowq-recapture-report.md`, captures `lowq-recapture/`; its 33 flash_fixes are on branch
`lowq-fixes` `d1180b580`, NOT master). The model is cloud slot `w2-lowq-sample-point`'s
(`w2-lowq-sample-point.patch`, report alongside); the coordinator HELD it.

## Goals

1. **Corner paint rule (`LOWQ_SHADE_HEAD`).** It wins radial gradients (radial 65541 → 3453, focal_radial → 0 = a
   PASS vs Flash) and the AS3 probe, but wrecks the rotated linear gradient (`visual/simple_shapes/gradients/gradients`
   5874 → 173226 channels off Flash) and costs `fills_and_lines` / `movieclip_begin_gradient_fill`. Build the
   rotated-linear-gradient LOW probe your predecessor named (ramps at 0/30/45/90/135/180° plus negative scale; also a
   radial and a focal one as controls), capture it in Flash at LOW (`run_image.py --quality low`, draw() wrapper; ≤ 4
   parallel), and fit the paint point per gradient type/orientation. Implement the fitted rule.
2. **Vertex y rule exceptions.** The rule also hits the opaqueBackground quad and a button's scrollRect content
   (`avm2_button_scroll_rect` 54 → 288, `opaque_background` +430; every new error pixel is on a horizontal edge). Find
   Flash's rule for those quads (probe + capture if needed) and exempt or fix them.
3. **Re-grade the package** at current master + model + your fixes, with the `lowq-fixes` entries applied: every row of
   the recapture table (before / after vs Flash-LOW), the 58 Flash-golden LOW tests (0 losses required), the render
   canary (HIGH members md5-identical). Rebase `lowq-fixes` if needed and add any new swap rows that now qualify.
4. Deliver: one patch file `session28-fanout-reports/lowq-final.patch` (model + your fixes, `git diff --binary` vs
   master, `git apply --check` proven) and the updated `lowq-fixes` branch; an EXPECTED-FLIP LEDGER by name (trace and
   pixel). Do NOT apply the patch to master yourself — the coordinator lands patch + fixes together in one commit.

## Constraints

- Local; Flash binaries never leave this box. Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4`, single tests only,
  `-P 2`; use a scratch `git worktree` (the shared tree has other sessions' edits; `render_webgpu.c` is also being
  edited by `n-drawapi-stroke-snap` and possibly `snap-pixel-audit` — message them if your patch must touch the same
  functions). Bracket every `pgrep -f`/`pkill -f` pattern. No CI dispatch. Flash over Ruffle; peer messages are
  teammate info, not Robert's approval.

## Done

`session28-fanout-reports/lowq-corner-rule-report.md`, the probe + captures, `lowq-final.patch`, updated `lowq-fixes`;
commit (docs/captures/patch file only) + push.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
