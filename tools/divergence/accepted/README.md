# Divergence harness — per-game accepted-diff manifests

This directory is the divergence harness's analogue of the AVM1 suite's
`ACCEPTED_DIFFS.md` + `ignored_tests.txt`. A manifest `<swf_stem>.txt` lists
**narrow, documented artifact patterns** that the harness should treat as
accepted — a known observer/tooling artifact, **not** a real runtime divergence —
so a game that is otherwise byte-identical to Ruffle reports as *converged modulo
documented artifact* instead of being false-flagged forever.

This is **opt-in per game**: with no manifest file, the harness behaves exactly
as before. Manifests are loaded by `accepted_diffs.load_manifest(stem)` and wired
into `divergence_test.py`'s trace diff (after `filter_trace`, before the
first-divergence report). They affect **only** the game they are named for and do
**not** touch the runtime, the recompiler, or the generic numeric tolerance.

## Format

One rule per line (`#`-prefixed lines are comments):

```
<path_regex> | <field> | <ruffle_value> | <swfrecomp_value> | <tag>
```

A rule absorbs a diverging `(ruffle_line, swfrecomp_line)` PAIR **only when all
three hold**:

1. some whitespace-token of the lines matches `path_regex`;
2. the two lines are identical in their non-field prefix (frame + path) and in
   **every** `key=value` field **except exactly** `field`;
3. that field's value is `ruffle_value` on the Ruffle side and `swfrecomp_value`
   on the SWFRecomp side (exact string match).

This triple constraint is what keeps a rule from masking a real bug: a line where
a *second* field also differs, or where the field's values are not the exact
documented pair, or whose path doesn't match, falls through and is flagged
normally. A rule is pinned to **one specific documented artifact shape**, never a
blanket "ignore this clip's `_cf`".

## When to add a rule

Only after a divergence is **root-caused as a harness/observer artifact with the
runtime proven correct** — the same bar as adding to the AVM1 `ACCEPTED_DIFFS.md`.
Document the why in the manifest header and cross-reference `PROGRESS.md`. If the
divergence is a real runtime bug, fix the runtime; do **not** add a rule.

## Current manifests

- **`Pacman.txt`** — `#10b` observer / instantiation-order reporting artifact.
  `Pac`/`CPac` `_cf` reads the goto-SOURCE frame (5) where Ruffle reads the
  post-goto frame (1), only on goto-boundary frames F5/F9/F13; everything else
  matches (242==242 lines, playhead correct). See `PROGRESS.md` #10b and
  `gates/README.md` → `nested_sprite_inframe_goto`.
