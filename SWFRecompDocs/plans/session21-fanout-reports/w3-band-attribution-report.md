# w3-band-attribution: four "worsened" fail->fail image bands (s21)

New files: `w3-band-attribution-report.md` (this), `w3-band-attribution-image-status-diff.patch`
(tool fix, optional; applies to `scripts/image_status_diff.py` at 42017e6f5; not committed).

## Verdict: premise refuted. No render moved. All four are (c) measurement artifacts.

| row | responsible commit | old headline check | new headline check | like-for-like excess (old check) | render stats (max_diff / diff_channels / mean_diff) | verdict |
|---|---|---|---|---|---|---|
| `avm2/blend_shader_luma_lighten` [output] | c61f6ebe5 (harness ALL-checks semantics) | tol 180, 1237/0 | tol 2, 40323/3300 | **1237 -> 1237** | 204 / 51539 / 3.9577 both runs | (c) |
| `from_shumway/acid/acid-morph` [output] | c61f6ebe5 | tol 64, 4311/2600 | tol 10, 32195/5600 | **1711 -> 1711** | 255 / 51017 / 1.4262 both runs | (c) |
| `avm2/graphics_direct_commands` [output] | c61f6ebe5 | tol 64, 587/300 | tol 32, 2503/1800 | **287 -> 287** | 255 / 6601 / 0.2995 both runs | (c) |
| `avm2/bitmapdata_draw` [output] | c61f6ebe5 | tol 128, 24578/600 | tol 64, 37079/1500 | **23978 -> 23978** | 255 / 39803 / 5.5653 both runs | (c) |

None of the candidate render or recompiler commits (86a1fa74f, a3e7d2858, 713c0ad3a, b57ecb2f3,
02df69d28, 8b4d8207e, 89ca1f667, 17cd6c784, e3ba02834) is responsible. There is nothing to
fix in the renderer and no flip or regression to book.

## Mechanism

c61f6ebe5 (w2-image-semantics) changed two things in `verify_output.compare_images`:

1. A multi-check comparison now needs ALL checks to pass (Ruffle semantics).
2. The flat `outliers / max_outliers / tolerance / excess_outliers` fields on a failing row now
   come from the check that is furthest past its own budget (`worst = max(failed, key=outliers -
   max_outliers)`). Before, they came from one fixed check: for these four rows, the loosest
   (highest-tolerance) check.

All four tests have 2 to 4 checks in `test.toml`. Every check fails on both sides. The old run
reported the loose check and the new run reports the tight one, so `excess_outliers` jumped even
though the render did not change. `image_status_diff.py` bins bands on `excess_outliers`, so it
printed these as worsened.

`image_status_diff.py` already flags the semantics change, but only for pass -> fail rows
(`[ANY->ALL, render unchanged]`). Fail -> fail band moves went through untagged, which is how
these four got to the coordinator as "worsened, unpredicted".

## Evidence (CI JSONs only; this is decisive without a local render)

- Old side: `fe094e464`, run 35423176371 at d6bcfa56c, no `checks` key. New side: HEAD, run
  36515003936 at 02df69d28, per-check `checks` list.
- For every row, the new run's own per-check stats at the old headline tolerance equal the old
  `outliers` exactly: 1237@180, 4311@64, 587@64, 24578@128. `max_diff`, `diff_channels`
  (= outliers at tol 0) and `mean_diff` (4 decimals) are also identical. So the diff histogram
  against the same expected PNG agrees at every threshold we can observe. A render change that
  kept all of these byte-equal is not plausible.
- I skipped the worktree render A/B the brief asked for. Its purpose was to find which commit
  moved the render, and CI's own numbers show that no commit did.
- Upstream drift: `git -C ~/CC/ruffle log f2aaf0703..0dacba55f` over the four test paths is
  empty, so there were no test.toml or expected-PNG changes. The per-check budgets above are the
  same test.toml read under two reporting rules.
- Recompiler nondeterminism (86a1fa74f): none of the four is in w1-recomp-nondet's complete,
  full-corpus-scanned affected set (6 nondeterministic SWFs plus acid-text). The baseline numbers
  were not a random draw, and the identical diff stats confirm it.

## Same artifact, other rows (outside the brief, reported so nobody re-chases them)

A full scan for fail -> fail rows whose headline tolerance changed:

- `avm2/displayobject_z` (205314 -> 206451)
- `from_shumway/acid/acid-bitmap-draw_quality_high` and `_low` (194784 -> 195044)

All three are below the 5% band floor, so the tool did not print them. Their like-for-like excess
is unchanged and their render stats are identical.

The one real mover is `from_shumway/avm1/text-bind`: `diff_channels` changed, and its
like-for-like excess went 1834 -> 1819, a small improvement. It is an unclaimed lead, not a
regression.

Caveat: the BAND HISTOGRAM in any old-vs-new diff that straddles c61f6ebe5 is also binned on the
switched headline. Part of its `d_moderate 43 -> 27` movement is re-binning, not rendering.

## Tool fix (prototype, not committed): `w3-band-attribution-image-status-diff.patch`

When the grading semantics differ, the patch adds `like_for_like(old, new)`. It takes the new
row's `checks` entry at the old row's headline tolerance and uses its excess for the fail -> fail
comparison. The label is then tagged `[ANY->ALL headline tol X->Y, excess N at new headline;
render unchanged]`.

Result on `fe094e464 HEAD`: BAND MOVES goes from "worsened 4" to "improved 23 / worsened 0".
The 23 improvements are unchanged, and every section above BAND MOVES is byte-identical to the
current tool's output. Band histogram re-binning is left as is (noted above). Scope: one helper
function plus about 12 lines in the fail -> fail branch of `main()`.

## New unclaimed leads

- `from_shumway/avm1/text-bind`: the render moved slightly for the better this session
  (like-for-like 1834 -> 1819). Unattributed and low value.
- Once the next images run is on the ALL semantics on both sides, the like-for-like shim becomes
  a no-op. The patch is only needed for diffs whose old side predates c61f6ebe5.
