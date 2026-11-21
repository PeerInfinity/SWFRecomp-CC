# w2-avm2-small-errors: AVM2 small-errors grab-bag (slot S9 of w1-drift-avm2), session 23, wave 2

**New files:**

- `SWFRecompDocs/plans/session23-fanout-reports/w2-avm2-small-errors-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-avm2-small-errors.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. `git apply --check -R` passes against the branch tip.

There are no new source files, no new fixture dirs and no `render_canary_tests.txt` change. The patch touches only `SWFModernRuntime/src/avm2/avm2_amf.c` (+112/−2) and `SWFModernRuntime/src/avm2/avm2_display.c` (+50/−4). No `swf_core.c`, `tag_stubs.c`, `NO_GRAPHICS` arms or recompiler changes.

Base: `origin/master` `68c0808ad` (which carries `ca9c46595` and the other s23 landings). Upstream Ruffle corpus downloaded at **`aa9f62a70`** (2026-11-21). Box: cloud, Dawn OK (lavapipe). Every before-leg was run on clean `origin/master` on this box. My before numbers equal the CI row numbers quoted in the w1-drift-avm2 report (1/21, 3/7, 4/10, 4/12, 69/99).

## 0. Verdicts and flips

| Row | Verdict | Mechanism and fix (owner) | Result |
|---|---|---|---|
| `avm2/shared_object_get_local_error` | **GO, landed** | `avm2_amf.c` `so_get_local` never threw. New `static so_full_key()` is a port of Ruffle `core/src/shared_object.rs::local_shared_object_key`. It rejects invalid name chars (`~%&\;:"',<>?# `), an empty `localPath`, a `localPath` that is not a `/`-bounded prefix of the SWF path, `secure=true` from a non-https movie, and any `.`-leading segment. Failure throws `Error #2134: Cannot create SharedObject.` The instance cache is now keyed by the full `host/path/name` key. `getRemote` keeps the old name-keyed path (new `so_get_remote`; no RTMP, and nothing in the corpus calls it). | 1/21 → **pass** (both modes) |
| `avm2/loaderinfo_root_progress` | **GO, landed** | The root LoaderInfo now dispatches its final `ProgressEvent.PROGRESS(bytesTotal, bytesTotal)` between `init` and `complete`, as in Ruffle's `loaderinfo_object.rs::fire_init_and_complete_events` `loader.is_none()` arm. New `static loaderinfo_root_final_progress()` reports the on-disk SWF length (`root_swf_size()` = `SWF_ONDISK_SIZE`), which is Ruffle's `compressed_len()`. It is gated on `LI_KIND_ROOT`, so child loaders (which report from their fetch path) and the Stage LoaderInfo are untouched. | 3/7 → **pass** (both modes) |
| `avm2/loaderinfo_root_progress_goto` | **GO, landed** | Same fix. `complete_fired` was already set before dispatch, so the nested frame from `gotoAndStop` inside the progress handler does not re-fire. The ordering is now explicit and commented. | 4/10 → **pass** (both modes) |
| `avm2/amf_xmllist` | **GO, landed** | Flash serializes no members of an XMLList (avmplus `AvmSerializer.cpp:294`; Ruffle `amf.rs::serializes_dynamic_properties`). AMF3 `w3_object`: an XMLList is written as non-dynamic, giving `0a 03 <alias>` (alias or `""`). AMF0 `w0` object arm: an XMLList writes an empty body (`03 00 00 09`). | 4/12 → **pass** (both modes) |
| `avm2/hit_test_scroll_rect` | **GO, landed** | The bounds of an object with a *committed* scrollRect are the rect's size at the object's origin. We pushed that box through `display_l2g_matrix`, which also applies the object's own `-scrollRect.topLeft` translate, so the box was shifted by (−150, −120). Ruffle `world_bounds` uses `local_to_global_matrix_without_own_scroll_rect`. New `static ht_world_bounds_matrix()` is identical to `display_l2g_matrix` for any object without its own committed rect, and is used by (a) the `hitTestPoint` bounds arm, (b) `hitTestObject` (both operands), and (c) the container scrollRect gate in `hit_test_shape_obj`. New `static ht_leaf_in_scroll_rect_bounds()` adds Ruffle's leaf `world_bounds(Engine).contains` gate (graphic.rs / bitmap default `hit_test_shape`) for Shape/Bitmap leaves with their own committed rect. The "before render" half was already right: an uncommitted rect is ignored. | 69/99 → **pass** (both modes) |
| `from_shumway/as3-loader/events/loader-events` (kf) | **bonus flip** | Root `progress 1293` is now emitted (a Flash-correct line: `output.txt:7`), which makes our diff a subset of Ruffle's. The harness's `ruffle_subset_match` then promotes the row. Flash and Ruffle agree on this line. The remaining diff is frame-ordering and instance naming, which both Flash and Ruffle get differently from us. | output_mismatch 5/36 → **ruffle_matched** 16/36 (both modes) |

Trace: **+5 pass, +1 ruffle_matched = +6 effective**, measured, identical in graphics and no-graphics. Pixel: no change. None of the flip rows has `[image_comparisons]`, and the canary is 150/150 md5-identical.

## 1. EXPECTED-FLIP LEDGER (for CI)

| Test | Axis | CI before | Expected after |
|---|---|---|---|
| `avm2/shared_object_get_local_error` | trace | output_mismatch 1/21 | **pass** 21/21 |
| `avm2/loaderinfo_root_progress` | trace | output_mismatch 3/7 | **pass** 7/7 |
| `avm2/loaderinfo_root_progress_goto` | trace | output_mismatch 4/10 | **pass** 10/10 |
| `avm2/amf_xmllist` | trace | output_mismatch 4/12 | **pass** 12/12 |
| `avm2/hit_test_scroll_rect` | trace | output_mismatch 69/99 | **pass** 99/99 |
| `from_shumway/as3-loader/events/loader-events` | trace | output_mismatch 5/36 | **ruffle_matched** (16/36 vs Flash) |
| (pixel axis) | pixel | — | **no moves** |

Both modes are expected to be identical. Any other status move in CI is not mine.

## 2. Per-test before/after (same box; before = clean `origin/master`)

### 2.1 Headline rows

| Row | graphics before → after | no-graphics before → after |
|---|---|---|
| `shared_object_get_local_error` | mismatch 1/21 → pass 21/21 | mismatch 1/21 → pass 21/21 |
| `loaderinfo_root_progress` | mismatch 3/7 → pass 7/7 | mismatch 3/7 → pass 7/7 |
| `loaderinfo_root_progress_goto` | mismatch 4/10 → pass 10/10 | mismatch 4/10 → pass 10/10 |
| `amf_xmllist` | mismatch 4/12 → pass 12/12 | mismatch 4/12 → pass 12/12 |
| `hit_test_scroll_rect` | mismatch 69/99 → pass 99/99 | mismatch 69/99 → pass 99/99 |
| `from_shumway/.../loader-events` (kf) | mismatch 5/36 → ruffle_matched 16/36 | (CI no-graphics 5/36) → ruffle_matched |

### 2.2 Neighbour sweep (graphics, before → after; every row unchanged unless starred)

Sweep scope, chosen by grepping the corpus for the APIs I changed:

- **SharedObject:** every `shared_object*` row, `regression/avm2_sharedobject_flushstatus`, `avm2/abstract_classes` (mentions SharedObject), `from_shumway/flash_net_SharedObject`.
- **LoaderInfo / progress:** every `loaderinfo*` and `loader_*` row, `large_preload_*`, `url_loader`, `urlstream_basic`, `mixed_avm/avm2_loads_avm1_events`, every `from_shumway/as3-loader/*` row (including `loaderinfo/Preloader`, which listens for root progress), `flash_net_URLLoader`, `regression/avm2_loader_stub`.
- **AMF:** every `amf*` row, `bytearray_amf3_shared_references`, and the XMLList + ByteArray users `xml_ctor_from_tostring` and `error_1034_debug_string`.
- **Hit testing / scrollRect:** `hit_test*`, every `mouse_pick*` row (including the three `mouse_pick_scroll_rect*`), `displayobject_hittestpoint_{boundary,root}`, `displayobject_scrollrect`, `displayobjectcontainer_getobjectsunderpoint`, `edittext_autosize_lazy_bounds_{interactions,props}`, `hittest_morph`, `stage_overriden_setters`, `stage_properties2`, `visual/scroll_rect_culling`, `regression/avm2_parent_child_render`, `from_shumway/avm1movie`.

Result: **98 rows.**

- 6 starred moves: the 5 headline rows and `loader-events` above.
- Every other row is identical in status and matching lines, including all image verdicts.
- Unchanged non-passing rows, all matching CI:
  - `loader_applicationDomain` mismatch 0/4
  - `loader_load` mismatch 126/128
  - `loader_events_2` ruffle_matched 5/35
  - `error_1034_debug_string` ruffle_matched 11/30
  - `as3-loader/LoaderTest` ruffle_matched 7/9
  - `avm1movie` ruffle_matched 1/13
  - `flash_net_SharedObject` ruffle_matched 3/4
  - `avm2_loads_avm1_events` ruffle_matched 8/26
- `avm2/shared_object` is a harness `runtime_error` in both legs: the two-run `.sol` harness errors in path setup. It is not graded in CI.
- Notable passes, unchanged:
  - big rows: `loaderinfo_quine` 1005, `edittext_autosize_lazy_bounds_props` 490, `stage_properties2` 213, `loader_events` 92 + image
  - every `mouse_pick_*` row
  - `displayobject_scrollrect` 33 + image, `displayobject_hittestpoint_boundary` 65 + image
  - `large_preload_*` 51/27/25, `as3-loader/loaderinfo/Preloader`

### 2.3 Regression suite

`regression/avm2_loader_stub`, `avm2_parent_child_render` (image pass, max diff 0) and `avm2_sharedobject_flushstatus` pass before and after, in both modes. No new fixture: every changed behaviour already has an upstream corpus row graded against Flash's `output.txt`.

### 2.4 Render canary (`render_canary.py`, md5)

Full standing set: 95 tests and 150 comparisons, `before` (clean master) vs `after` (patch). Result: **150 IDENTICAL, 0 DIFFERS, 0 APPEARED/VANISHED, no trace or image status changes.** No covering member was appended, because the change class is not visible in renders: hit tests, AMF bytes and event dispatch draw nothing. I did not do the fidelity check against CI PNGs, because no absolute pixel verdict is claimed.

## 3. Refutations and pricing self-attack

- **"`hitTestPoint` ignores scrollRect clipping."** Partly refuted. The clip was already there: the container gate and `pk_in_scroll_rect` exist, and a committed rect already replaced the bounds. The bug was the **offset**: our box was moved by the object's own scroll translate, so it sat at (−50..−20, −70..−50) instead of (100..130, 50..70). That one matrix explains all 30 failing lines: `false true` at (105, 55), `true true` at (−45, −65), and hitTestObject. The Shape/Bitmap leaf gate is the only real "missing clip". It covers the `shapeFlag=true` lines at (131, 55) and (255, 175) for leaves, which had no container gate.
- **"Before render" lines.** These were already right: Flash ignores a scrollRect assigned before the first render, and our `sr_committed` latch models that. I kept every change behind `sr_committed`, so objects with no committed rect take byte-identical paths (`ht_world_bounds_matrix` == `display_l2g_matrix`).
- **Root progress risk.** Any row with a root-LoaderInfo `progress` listener gains one event. A corpus grep found exactly these:
  - the two headline rows
  - `as3-loader/loaderinfo/Preloader` (still pass)
  - `loader-events` (improved)
  - the `large_preload_*` / `loader_*` rows, which listen on child `contentLoaderInfo` and are unchanged

  `loaderinfo_events` (root init/complete ordering) is unchanged at 7/7.
- **SharedObject URL.** The key uses the build's `SWF_URL` (`file:///test.swf` in the harness; `GAME_SWF_URL` for games). That reproduces Ruffle's harness behaviour, `/nonexistent` is not a prefix of `test.swf`. Games served over http that call `getLocal(name, "/")` still work. `secure=true` from a non-https origin now throws, as Flash does.
- **Flash over Ruffle.** None of the 5 headline rows is `known_failure`; all 5 are Flash-exact passes. `loader-events` is kf, and its ruffle_matched move comes from adding a line Flash and Ruffle both print.

## 4. Not finished / HOLD

- Branches of `so_full_key` not exercised by any corpus row: https + `secure`, a name containing `/` (`#` prefix), a `.`-leading segment, and a Windows drive letter. These are a line-by-line port of Ruffle, but no oracle in the cloud checked them. **Completion mechanism:** a `regression/avm2_sharedobject_key` fixture graded by the Ruffle exporter (request below), if the coordinator wants coverage. It is not needed for the ledger.
- `avm2/shared_object` (the two-run `.sol` test) is still an ungraded harness error, and that is out of scope.

## New unclaimed leads

- `from_shumway/as3-loader/events/loader-events` residual (kf, 16/36 after): Flash orders `enterFrame 2 / run frame 2 / exitFrame 2` before child 1's `open`, and names timeline children `instance2/3/4`. We print `construct null` / `run frame 1 in null` for the child movie's timeline instances (Ruffle prints `instanceN`), which is a child-SWF instance-naming gap. Our diff is now a subset of Ruffle's; naming the child's timeline instances would take more lines.
- `avm2/loader_load` 126/128 and `loader_applicationDomain` 0/4 are untouched loader rows, both stable at CI numbers. Not triaged.
- Other `display_l2g_matrix` + `bounds_with_transform` pairs (getBounds/getRect with a committed own scrollRect) may carry the same offset bug as `hitTestPoint`. No failing corpus row was found in this sweep. Worth a grep by a later display slot.

## LOCAL ORACLE REQUESTS

Optional, low priority: a Ruffle exporter (or Flash) trace of a small AS3 SWF that calls `SharedObject.getLocal` with names `"a/b"`, `"..x"` and `".hidden"`, `localPath` `"/"`, `"test.swf"`, `"test.swf/"` and `"tes"`, and `secure=true`, from `file:///test.swf`, tracing success or `#2134` for each. It would become `regression/avm2_sharedobject_key`. Not blocking.
