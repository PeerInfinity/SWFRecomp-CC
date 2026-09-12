# w1-avm1-builtins: wave-1 diagnosis of AVM1 builtin-object trace failures (gnash actionscript.all, avm1)

Read `BRIEFS_COMMON.md` first. This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-avm1-builtins-report.md`. Scratch dir: `<scratchpad>/w1-avm1-builtins/`.

## Your board (numbers from the wave-0 inventory; re-run before believing them)
**Not KF, undispositioned:**
- `avm1/new_class_prototype_getter`: 1/6, we emit 5.
- `avm1/set_property_values/swf5`: 1620/1743. **swf6/swf7 have the same count and are ACCEPTED;
  swf5 is not.** Is swf5 the same float blocker, missing only from the doc and ignore list (a
  disposition fix, 0 flips), or a real different gap? Read
  `avm1/_investigation/blocked/SET_PROPERTY_VALUES_PLAN.md` and memory `set-property-values-float-blocker`.
  `swf4` 349/1571 is KF.

**KF upstream** (Ruffle fails these too; `output.txt` is Flash's). Price exact-pass or
`ruffle_matched` reachability, and name the residual line families:
- `from_gnash/actionscript.all/MovieClip-v6` 901/936, `-v7` 934/969, `-v8` 1020/1087. These were
  "multi-phase plans" at s18. Find any single-mechanism subset.
- `from_gnash/actionscript.all/array-v6` 623/644, `-v7` 604/654, `-v8` 604/654 (v5 is IGN).
- `from_gnash/actionscript.all/TextField-v6/v7/v8` ~470/545-571, flagged ACC. What does the
  ACCEPTED entry cover, and is there residual beyond it?
- `avm1/globals_monkeypatch` 39/228 (RTXT): an arc at s18. Re-size it.
- `from_gnash/misc-ming.all/DrawingApiTest` 81/93 (RVF, KF, RTXT); `GradientFillTest` 123/278
  (APX, not KF; s17 `w2-gfx-smalls-report.md` touched it); `NetStream-SquareTest` 91/216 (KF, RTXT).

Look for shared mechanisms across the gnash files first: a fix that moves lines in 3 version
variants at once is the pattern that paid in s18 (Function-v6/7/8).

Siblings: w1-avm1-display (hitArea, action_order, destruction, masks_test, missing_frame_scripts,
text), w1-loaders, w1-avm2, w1-drift (owns `avm1/bitmapdata_custom_rectangle`), w1-gfx-*.
