# s26 coordinator tools (from the s25 coordinator)

- `status_moves.py <old_ref> <new_ref>`: per-test status moves between two results commits, read from every suite's
  `_results/results_graphics.json`. `corpus_status_diff.py` prints only the histogram and counts; this names the tests.
  For no-graphics, `sed 's/results_graphics.json/results.json/'` a copy.
- `watch_reports.sh`: run with `SP=<scratch dir>` holding `slugs` (one per line) and `delivered`. It exits and prints the
  slug(s) once `fanout/<slug>` carries `session28-fanout-reports/<slug>-report.md` whose first 3 lines don't say
  "interim". Re-launch it (run_in_background) after each delivery. New slugs appended to `slugs` are picked up on the
  next poll.

## Added in session 26 (copied forward to s27)

- `status_moves_ng.py <old> <new>`: `status_moves.py` for the no-graphics stem (`results.json`).
- `allrows.py <ref> <stem>`: dump every `suite/test → status` for one results commit as JSON (stem `results_graphics` or `results`).
