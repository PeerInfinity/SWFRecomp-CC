# s28 w1-drift: upstream Ruffle drift `efb612fd7..c2f7d24b7`

**New files (all under `session28-fanout-reports/`):**
- `w1-drift-report.md` (this file)
- `w1-drift-fixtures/create_test_swfs.py`: builds both fixtures (`python3 create_test_swfs.py <dir>`)
- `w1-drift-fixtures/avm1_root_onload_child_order/{test.swf,test.toml,ours_both_modes.txt}`
- `w1-drift-fixtures/avm1_root_onload_proto/{test.swf,test.toml,ours_both_modes.txt}`

There is no prototype patch and no source change.

Upstream SHA at download: **`c2f7d24b797be914538e20f810fc2aec21ac63e2`** (`git ls-remote` on 2026-11-25).
No commits landed after `c2f7d24b7`, so the range is the one the brief gave. Categories downloaded:
`avm1 from_gnash from_shumway` (788 + 404 + 229 installed). Graphics-mode grading ran on Dawn/lavapipe in the cloud.
Setup status: all OK.

## Verdicts (lead)

| Row | Upstream move | Ours before → after download | Verdict |
|---|---|---|---|
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | `known_failure` removed, `output.ruffle.txt` **deleted** | `ruffle_matched` → **`output_mismatch`** (GR and NG, both 4 diff lines) | **−1 effective: drift, not a regression.** The cause is the existing §27.4 NO-GO (per-clip sibling exec-list interleave). **NO-GO**; completion mechanism below |
| `avm1/root_onload_loaded_level` | **NEW row** (Rascal, 4 SWFs, 20 ticks) | absent → **PASS** (GR + NG) | **+1 new row**, already passing, nothing to do |
| `avm1/root_onload` | `known_failure` removed, empty `output.ruffle.txt` deleted | pass → **PASS** (GR + NG) | confirmed, no move |
| `from_gnash/misc-swfmill.all/trace-as2/root_onload` | `known_failure` removed, `output.ruffle.txt` deleted | pass → **PASS** (GR + NG) | confirmed, no move |
| `from_shumway/acid/acid-bitmap-fill-2` | image check 1 `max_outliers` 9000 → 10000 (zune-jpeg made Ruffle *worse* against the golden) | image PASS, 0 outliers / max_diff 0 → **PASS, 0 / 0** (GR) | no move. A loosened tolerance cannot fail a pass, and our IJG model is still bit-exact |

**Net trace drift: +1 row (`root_onload_loaded_level`, pass), −1 effective (`action_execution_order_test4`,
ruffle_matched → fail).** The effective count is unchanged, but the row total grows by 1 and the failing set grows by 1.
Book this as **upstream movement**, never as a regression or as yield. The coordinator should expect it in the next
CI read as `test4: ruffle_matched → output_mismatch` and `root_onload_loaded_level: new pass`.

**zune-jpeg (`c2f7d24b7`): no golden re-baked.** `git diff --stat efb612fd7 c2f7d24b7 -- tests/` touches **no
PNG**: its only image-side edit is the `acid-bitmap-fill-2` tolerance. So there is **no re-pricing** of
`acid-color-0` (baseline fail, 1138 outliers, max 255; RvF loss to our IJG model) or `bitmapdata-clone` (baseline
pass, 0/0, Flash-exact). Our decoder stays as it is. The `acid-bitmap-fill-2` loosening shows zune moving
Ruffle further from the golden, not closer: more evidence that we should not move toward zune.

**`apply_flash_fixes.py --check` after the download:** `MISSING 5` only, for the 5 PNG fixes in the
`visual/` and `avm2/` categories, which this slot did not download
(`visual/simple_shapes/strokes/scale`, `avm2/graphics_draw_path`, `avm2/bitmapdata_opaque`, `avm2/blend_scroll`,
`visual/definefont4`). **No STALE and no UPSTREAMED lines.** None of the 5 can be UPSTREAMED by this range,
because the range changes no PNG.

## Every upstream commit in the range

| Commit | Touches `tests/` | Behaviour we model | Rows |
|---|---|---|---|
| `45099f016` swf: parse only the tags needed in `decompress_swf` | no | No. It is a Ruffle loader refactor: `read_raw_tag` replaces `read_tag` for the FileAttributes/SetBackgroundColor peek. The one semantic edge: a malformed *known* first tag no longer stops the background-colour search. No corpus row exercises it, and our recompiler parses tags itself | none |
| `fa93ad79f` avm1: fire the root's load event after its first frame's actions | yes | Yes: root `onLoad` timing | the 4 onLoad rows above |
| `85eaaffb7` chore: selective `cargo update` | no | no | none |
| `0c015cb5e` chore: binaryen 133 | no | no | none |
| `c2f7d24b7` render: `jpeg-decoder` → `zune-jpeg` | toml only | We model IJG, not zune | `acid-bitmap-fill-2` tolerance |

## Mechanism: `action_execution_order_test4`

The row was `ruffle_matched` only because `verify_output.py:5127-5163` promotes a mismatch whose diff lines are a
subset of `output.ruffle.txt`'s diff lines, and only when `known_failure = true`. Upstream removed both, so the
promotion cannot fire. The Flash golden was not edited (`git diff` shows only the toml and `output.ruffle.txt`).

The root-onLoad part of the row is **already correct for us**:
- Line 1 `_root onLoad called` matches.
- `PASSED: _root.x2 == 'as_start+as_end+load_called+'` matches.

Those were exactly the lines Ruffle's old `output.ruffle.txt` got wrong. Our remaining 4 diff lines, identical in GR
and NG:

```
 Flash (output.txt)             ours
 mc3 EnterFrame called          mc3 EnterFrame called
 actions in 2nd frame of mc3    mc2 EnterFrame called
 mc2 EnterFrame called          mc1 EnterFrame called
 actions in 2nd frame of mc2    actions in 2nd frame of mc3
 mc1 EnterFrame called          actions in 2nd frame of mc2
 actions in 2nd frame of mc1    actions in 2nd frame of mc1
 ... x1 == '1+…+7+8+9+10+11+…'  x1 obtained '1+…+7+9+11+8+10+…'
```

SWF structure (from a tag dump): `mc1`/`mc2`/`mc3` are **siblings**, placed in root frame 2 at depths 10/12/11 with
PlaceObject2 clip actions (flags `0xa6`). Each is a 2-frame sprite. In Flash (and Ruffle's `run_frame_avm1`), each
clip's EnterFrame clip event is followed by its own frame advance, walking the exec list newest first. We run one
pass that dispatches every clip's ENTER_FRAME (`tagFlushPendingEnterFrame`, `tag.c:7443`, armed at
`swf.c:1096-1106`), then a second pass that advances the nested/child sprites (Phase 3 `advance_nested_sprite_frames`,
`swf.c:1277+`).

This is the board item in `polish-sweep-arc.md` §27.4: *"The per-clip sibling exec-list interleave is a NO-GO until
the exec list becomes flat and instantiation-ordered."* `test4` now joins `ActionOrderTest3/4/5`, `_extend_test`
and `test11` in that family. It is a clean single-mechanism member: only the interleave differs, with no
ctor/load-order residue.

- **NO-GO. Completion mechanism:** a flat, instantiation-ordered AVM1 exec list in which each clip's ENTER_FRAME
  clip event and its own frame advance (frame DoActions) are queued together, per clip, newest first, replacing
  the two global passes. Size M-L. It touches the `swf.c` main-loop phase order and `tag.c`
  `tagFlushPendingEnterFrame`, which belong to the parallel N/browser ladders. **`test4` is the cheapest acceptance
  row for that rewrite** (4 lines, siblings only, no nesting).
- No RvF, ACCEPTED_DIFFS or ignore entry: Flash and Ruffle agree, and the golden is a Gnash recording of Flash.

## Root load event ordering: corpus sweep

**Question:** does any other row's golden depend on when the root's onLoad fires relative to the frame-1 actions,
and does our order differ from Ruffle's new order?

1. **Ruffle side, closed by construction.** Ruffle's runner (`tests/framework/src/runner/trace.rs:25-70`)
   checks every `known_failure = true` row byte-for-byte against its `output.ruffle.txt`, and checks every passing
   row against `output.txt`. Upstream CI accepted `fa93ad79f` after touching only `root_onload`, `trace-as2/root_onload`
   and `test4` (plus adding `root_onload_loaded_level`). So **no other avm1/gnash/shumway row changed Ruffle output.**
   The only rows exempt from that check are the 6 with `known_failure.ruffle_check = false`
   (gnash `ASnative-v5..v8`, `GradientFillTest`, shumway `getpixel-from-embedded`). None of those SWFs contains the
   string `onLoad`.
2. **Our side.** A byte scan of every non-AS3 SWF in avm1 + gnash + shumway + regression for `onLoad` finds 119
   files (mostly LoadVars/XML/MCL/Sound `onLoad`; the scan is reproducible with a zlib-decompress plus a `b"onLoad" in body` check). Of these, the non-passing baseline rows are:
   - gnash `ActionOrderTest3/4/5`, `action_execution_order_extend_test`, `test11`: the same §27.4 interleave family,
     unchanged here.
   - `RegisterClassTest4`, swfc `action_execution_order_test12`, `avm1/sandbox_type_remote`.
   - A set of `ruffle_matched` rows whose toml and `output.ruffle.txt` did not move.

   None of them changes status, because no golden or toml moved outside the 4 rows above. Every row that sets
   `_root.onLoad`/`this.onLoad` in frame 1 passes (`root_onload` ×2). `test4`'s onLoad lines also match, so **our
   order already equals Ruffle's new order on every corpus row.**
3. **Where our model differs from Ruffle's new code (no corpus row).** We fire the root onLoad once at the end of the
   first `tagShowFrame` (`actionDispatchRootOnLoad`, `action.c:43383`, called at `tag.c:11183`). It looks up
   `onLoad` with `getPropertyWithPrototype` on `root_movieclip.dynamic_props`, then falls back to the global var map
   (`actionDispatchMCOnLoad`, `action.c:43108`). Two fixtures probe the cases no corpus row covers. They were built
   with the raw-bytes builder in the s27 exec-order style; ours is identical in GR and NG:
   - **`avm1_root_onload_child_order`**: root f1 places `kid` (onClipEvent construct/load/enterFrame) and then
     defines `this.onLoad`. Ours: `kid construct, kid load, kid f1, root f1, root onLoad, kid enterFrame, kid f2,
     root f2, …`. Reading Ruffle's new code, the root Load is queued right after the root's own `run_frame_internal`,
     and the kid's events are queued during placement before the root DoAction, so Ruffle should agree. Not
     verified: there is no current Ruffle oracle, and the coordinator's exporter is at `0ddd12b6a`, before the change.
   - **`avm1_root_onload_proto`**: root f1 defines **`MovieClip.prototype.onLoad`** (no own root onLoad). `a` is
     placed in f1 and `b` in f2. Ours prints **no** `proto onLoad` line at all. In Ruffle's new code, the root's
     Load dispatch follows the frame-1 actions, so its method lookup should now find the prototype handler and
     print `proto onLoad _level0`. Ruffle may also fire it for `b` (placed after the prototype exists). Flash's
     plain-timeline-clip onLoad rule ("no clip events / no class → no onLoad") makes `b` uncertain.
   - **HOLD on both, pending FLASH** (requests below). If Flash prints `proto onLoad _level0`, the fix is S: make
     `actionDispatchRootOnLoad` resolve `onLoad` through `MovieClip.prototype` when the root's `dynamic_props` has no
     own handler or no `__proto__` link. Function: `actionDispatchMCOnLoad`/`actionDispatchRootOnLoad` in
     `action.c`. Land it with the fixture as a `regression/` row carrying the Flash golden. If Flash moves
     `root onLoad` in variant A, that is a new order bug for the coordinator to board.

## Refutations / premise checks

- **Premise: "the drift is S; we already pass both `root_onload` rows".** True for those two. But the brief
  **missed 3 of the 5 test-touching items**: the new `root_onload_loaded_level` row, the `test4` toml and
  `output.ruffle.txt` deletion, and the `acid-bitmap-fill-2` tolerance edit. The `test4` deletion is the only real
  status move in the range, and it is a −1 effective.
- **Premise: "zune-jpeg, no golden re-baked yet".** Confirmed: no PNG moved. The one zune-side test edit
  loosens Ruffle's own tolerance and leaves us unaffected (still 0/0).
- **`test4` is not a root-onLoad problem for us.** Its root-onLoad lines already pass. Fixing the drift loss needs
  the exec-list interleave, not onLoad work.

## New unclaimed leads

- **`MovieClip.prototype.onLoad` on `_root`** (fixture `avm1_root_onload_proto`). It is Flash-gated, S if Flash
  confirms, and has no corpus row today.
- **`test4` as the acceptance row for the §27.4 interleave rewrite.** It is the smallest member: siblings only, 4
  lines, identical GR/NG.

## LOCAL ORACLE REQUESTS

Both SWFs are SWF8, built by `w1-drift-fixtures/create_test_swfs.py` (deterministic: md5 `9333ad93…` and
`74783bb8…`).

**Use `run_trace.py --no-pin` (the test as the projector's FIRST root) for all three runs below.** The pinned
direct mode starts `PinStub.swf` and then `getURL(test.swf, "_level0")`, so the test becomes a *replaced* `_level0`
(`tools/flash-oracle/README.md` §"Direct-mode window pin"). Per upstream's new `root_onload_loaded_level` (and
`fa93ad79f`'s message), Flash never fires frame-1 `onLoad` for a movie loaded over `_level0`, so a pinned run would
answer the wrong question. The fixtures trace only strings (no Stage or size reads), so the unpinned window-size
race cannot affect them. Never use `--wrapped` here.

0. **Control: FLASH `avm1/root_onload` (corpus), trace, `--no-pin`.** It must print `onLoad` (its golden). As a free
   extra, also run it **pinned**: if the pinned run prints nothing, that is a Flash confirmation of the
   "replaced `_level0` gets no frame-1 onLoad" rule, measured on our own harness.
1. **FLASH: `w1-drift-fixtures/avm1_root_onload_child_order/test.swf`, trace, 4 frames, `--no-pin`.** Compare
   against `ours_both_modes.txt`. Question: where does `root onLoad` sit relative to `kid construct / kid load /
   kid f1 / root f1`? (Ignore trailing `kid enterFrame` lines past frame 4: direct mode overruns `num_frames`.)
2. **FLASH: `w1-drift-fixtures/avm1_root_onload_proto/test.swf`, trace, 4 frames, `--no-pin`.** Compare against
   `ours_both_modes.txt`. Questions:
   - Does `proto onLoad _level0` print (root load event finding `MovieClip.prototype.onLoad` defined in frame 1)?
   - Does `proto onLoad _level0.b` print for the clip placed in f2?
   - Where do those lines sit?

Both goldens would be grown into `regression/` rows by the wave-2 worker only if Flash shows a difference from ours.
