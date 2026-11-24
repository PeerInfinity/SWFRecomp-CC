# s27 w2-allow-networking-subtests: allowNetworking subtests become graded rows

**New files:** `w2-allow-networking-subtests-report.md` (this file), `w2-allow-networking-subtests.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`,
455 lines, `git apply --check -R` OK against the branch tip). No new source files, no new fixture dirs, and no
`SWFRecomp/` (recompiler) change.

Base `origin/master` **`53540ff0`**. Upstream Ruffle at download: **`1e604fa87`** (`download_tests.sh avm2 avm1`, plus
`visual text` for the canary subset). Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe).

## Verdict (lead)

**GO. 8 NEW trace rows, all `pass` in both modes. The 4 existing rows are unchanged (pass → pass).**

The trace denominator grows by **+8 per mode** (avm2 +4, avm1 +4), and so does the effective count (+8). No pixel rows
are involved: none of the 4 tests has `[image_comparisons]`.

| Row (suite/name) | before¹ | after (graphics) | after (no-graphics) | Graded against |
|---|---|---|---|---|
| avm2/`allow_networking` (existing) | pass | pass | pass | `output.all.txt` |
| avm2/`allow_networking__internal` **NEW** | output_mismatch | **pass** | **pass** | `output.internal.txt` |
| avm2/`allow_networking__none` **NEW** | output_mismatch | **pass** | **pass** | `output.none.txt` (Flash; `known_failure` in Ruffle) |
| avm2/`local_connection_allow_networking` (existing) | pass | pass | pass | `output.all.txt` |
| avm2/`local_connection_allow_networking__internal` **NEW** | pass | **pass** | **pass** | `output.internal.txt` (= all) |
| avm2/`local_connection_allow_networking__none` **NEW** | output_mismatch | **pass** | **pass** | `output.none.txt` |
| avm1/`allow_networking_import_assets` (existing) | pass | pass | pass | `output.all.txt` |
| avm1/`allow_networking_import_assets__internal` **NEW** | pass | **pass** | **pass** | `output.internal.txt` (= all) |
| avm1/`allow_networking_import_assets__none` **NEW** | output_mismatch | **pass** | **pass** | `output.none.txt` (empty) |
| avm1/`allow_networking_import_assets2` (existing) | pass | pass | pass | `output.all.txt` |
| avm1/`allow_networking_import_assets2__internal` **NEW** | pass | **pass** | **pass** | `output.internal.txt` (= all) |
| avm1/`allow_networking_import_assets2__none` **NEW** | output_mismatch | **pass** | **pass** | `output.none.txt` (empty) |

¹ For the existing rows, "before" is clean `origin/master`, graphics mode, on this box. On clean master the NEW rows
do not exist, so their "before" is the harness half of this patch with the runtime half reverted: the define is
passed but nothing reads it. That is what each row would grade if only the harness landed.

**Premise correction vs the brief:** the brief names `avm2/allow_networking` and `local_connection_allow_networking`. The
corpus actually has **four** allow_networking subtest tests. The other two are AVM1: `avm1/allow_networking_import_assets{,2}`
(Ruffle gates `ImportAssets`/`ImportAssets2` under `none`, `movie_clip.rs:782`). Both are in this patch. There is no
`avm1/local_connection_allow_networking`.

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

**Trace axis, NEW rows (absent from every baseline; `corpus_status_diff.py` compares the intersection only, so these
show up only as a +8 rise in the per-suite totals, never as GAINS):**

- `avm2/allow_networking__internal`: NEW, pass
- `avm2/allow_networking__none`: NEW, pass
- `avm2/local_connection_allow_networking__internal`: NEW, pass
- `avm2/local_connection_allow_networking__none`: NEW, pass
- `avm1/allow_networking_import_assets__internal`: NEW, pass
- `avm1/allow_networking_import_assets__none`: NEW, pass
- `avm1/allow_networking_import_assets2__internal`: NEW, pass
- `avm1/allow_networking_import_assets2__none`: NEW, pass

The expected count is the same in both modes. A full-suite `categories=all` run includes avm1 and avm2. Result entries
for these rows carry an extra `"subtest": "<variant>"` field. That is an additive JSON field; the schema is otherwise
unchanged.

**Trace axis, existing rows:** no move expected anywhere. The 4 bare rows stay `pass` (keys unchanged). At the default
level every gate is `if (0 < min_level) return;`, so no other row can move.

**Pixel axis:** no move expected. No image comparisons are involved, and the canary subset is md5-identical (below).

**What would read as a regression and isn't:** shard membership shifts by up to 8 rows (sharding is by list index).
That is harmless, but a per-shard timing comparison will see it.

## Mechanism

### 1. Harness (`ruffle-tests/verify_output.py`, localized; no overlap with the `SWF_BROWSER_ARMS_TU` hook)

- New helpers sit right after `resolve_expected_filename`: `ALLOW_NETWORKING_LEVELS`, `SUBTEST_VARIANT`,
  `networking_variants()`, `extra_variant_rows()`, `split_variant_row()` and `bare_row_networking_level()`.
- `discover_tests` adds one `<test>__<variant>` row per allow_networking variant, except the one the bare row already
  grades (the first, `all`, as `resolve_expected_filename` picks today). It does this only when no
  `expected_filename`/`--expected-suffix` override is in force.
  - The `__` join mirrors the image axis's `<subtest>__<cmp>` split. `split_variant_row` checks for a real directory
    first, so `avm1/__framework__` and any real `a__b` directory stay plain tests.
- Main loop: `split_variant_row` maps the row to its test dir and sets the global `SUBTEST_VARIANT` (the pattern of the
  existing `MSAA_OVERRIDE`). `resolve_expected_filename` then returns the variant's `output_path`, but only for that
  exact test dir (so child-dir probes are unaffected).
  - `_test_is_known_failure` therefore sees the variant's own `known_failure`, and the `output.none.ruffle.txt` oracle
    path works for `allow_networking__none` if it ever regresses.
- `compile_native` emits `-DALLOW_NETWORKING=<1|2>` next to `MOCK_PLATFORM` for a variant row. It also emits it for a
  bare row whose graded variant is not `all` (none today). Level 0 (`all`) emits nothing.
- `--test=<test>__<variant>` works with and without `--tests-dir` (the suite auto-resolve and the per-name dir check
  both go through `split_variant_row`).
- The WASM build path is untouched (not graded).

### 2. Runtime (`ALLOW_NETWORKING` compile define; default 0 = all = no behaviour change)

`include/avm2/avm2_error.h` gains `ALLOW_NETWORKING` (default 0), `AVM2_NET_INTERNAL`/`AVM2_NET_NONE`, and two helpers.
The helpers are implemented at the end of `src/avm2/avm2_error.c`:

- `avm2_networking_gate(ctx, min_level, api, n_frames, ...)` throws `SecurityError` #2146 when blocked.
  - The message comes from Ruffle `make_error_2146`, with `SWF_URL` as the URL (= `file:///test.swf`, which is what
    Flash's `output.none.txt` prints at every site).
  - It first pushes the playerglobal AS3 frames FP shows above the native one. For example, `new URLLoader(r)` gives
    `URLLoader/load()` over `URLLoader()`.
- `avm2_fscommand_gate(ctx)` throws #2149 (`… fscommand calls to  (allowScriptAccess is always).`) when blocked.

Gates, each placed where Ruffle checks:

| API (Ruffle owner) | blocked at | our site (`file` → function) | order detail kept |
|---|---|---|---|
| `navigateToURL` (net.rs) | internal+none | `avm2_globals.c` new `net_navigate_to_url_gated` wrapper | before arg read |
| `fscommand` (system.rs) | internal+none | `avm2_globals.c` `global_fscommand` | first |
| `sendToURL` (net.rs) | none | `avm2_globals.c` new `net_send_to_url` wrapper | first |
| `URLLoader` ctor / `load` (url_loader.rs, "URLStream.load") | none | `avm2_display.c` `url_loader_init` (+ `URLLoader/load` frame), `url_loader_load` | after non-null request |
| `URLStream.load` | none | `avm2_display.c` `url_stream_load` (+ `URLLoader/load` frame) | after non-null request |
| `Loader.load` (loader.rs) | none | `avm2_display.c` `loader_load` | after non-null request, before load state |
| `Sound` ctor / `load` (sound.rs) | none | `avm2_media.c` `sound_ctor` (+ `Sound/load` frame), `sound_load` | after state check and `load(null)` early-out |
| `Socket.connect` / XMLSocket (socket.rs) | none | `avm2_net.c` `socket_connect` | after the #2003 port check; XMLSocket's frames come from its real `connect` calls |
| `LocalConnection.send` (local_connection.rs) | none | `avm2_net.c` `lc_send` | first of all |
| `LocalConnection.connect` | none | `avm2_net.c` `lc_connect` | after null/empty name, before ':' |
| `SharedObject.getLocal` (`50f28249e`) | none | `avm2_amf.c` `so_get_local` | after args read, before key build |
| AVM1 `ImportAssets`/`ImportAssets2` (movie_clip.rs) | none | `action.c` `actionPreloadImportAssets` (no GET block) and `actionImportAssets` (no import) | the empty-URL rule is unchanged |

**Sibling-touched files:** `action.c` (only `actionPreloadImportAssets` and `actionImportAssets`, plus a
file-local `AVM1_IMPORT_ASSETS_BLOCKED` macro above them). Not touched: `tag.c`, `ng_shared.c`, `swf.c`. The
`tagImportCharacter` gate was not needed, because with no child init there is no export to resolve.

## Evidence

- **Headline:** the 12-row table above, run on this box in **both** `--mode=graphics` and no-graphics. The new rows'
  stack traces match Flash line for line, including the native and AS3-shim frames (`global/flash.net::navigateToURL()`,
  `flash.net::SharedObject$/getLocal()`, `flash.net::XMLSocket/connect()`, …).
- **Neighbour sweep, default mode** (graphics, after; these exercise every gated function with networking allowed):
  - **Pass (13):** avm2 `loader_loadbytes_url`, `loader_loaderurl`, `navigateToURL_target_normalize`,
    `net_navigateToURL`, `shared_object_get_local_error`, `shared_object_no_root`, `socket_close`, `socket_connect`,
    `socket_errors`, `sound_load_multiple`, `url_loader`, `urlstream_basic`, `xml_socket`.
  - **`loader_load`: output_mismatch on both clean master and the patch.** It is a baseline failure listed in
    `s27-baseline-trace-failing.txt` (URLVariables key order), unrelated to this patch.
  - `avm2/shared_object` has no expected file. It is not a discovered test and is not graded.
- **Regression suite** (graphics): `avm2_loader_stub`, `avm2_localconnection_domain`, `avm2_sharedobject_flushstatus`,
  `avm2_sound_bytes_and_group_format`: all pass.
  - No new regression fixture: the behaviour has corpus rows whose goldens are Flash's (`output.none.txt`, Ruffle
    `known_failure` only for its SWF URL), so the oracle is outside SWFRecomp.
- **Render canary: an 8-test subset, not the full 738-row list.** Members: `avm1/color`, `avm1/bitmap_data_fillrect`,
  `avm1/movieclip_setmask`, `avm2/loader_jpegxr_alpha`, `avm2/loader_events`, `avm2/edittext_autosize_height_dynamic`,
  `text/auto_size/width`, `visual/edittext/edittext_border_transform`.
  - Result, before (clean) vs after: **13/13 PNGs IDENTICAL**, no trace or image status changes.
  - The full list measures about 16 s/test here, roughly 1.6 h per leg at `-P 2`, and the change has no render path:
    every gate is a constant-false branch at level 0.
  - I did not append a canary member: no render class is touched.

## Refutations / notes

- The w1-drift report priced this at "M, for 2 rows". The real count is **4 tests → 8 new rows**: the two AVM1
  ImportAssets tests were invisible for the same reason.
- `allow_networking__none` is `known_failure` in Ruffle (its `output.none.ruffle.txt` prints `file:///` for the
  ctor-routed sites). We match **Flash** (`file:///test.swf` everywhere), which is the right side per the user ruling.
- `internal` really changes only navigateToURL and fscommand in these tests. `local_connection` and the two
  `import_assets` `internal` goldens equal `all`, which is consistent with Ruffle's `== None` gates.

## Not done (with completion mechanism)

- **ExternalInterface, and AVM1 `getURL`/`loadMovie`/`loadVariables`/`XML.load`/`LoadVars`/`XMLSocket`/`LocalConnection`
  under internal/none.** Flash's documentation lists some of these. Ruffle gates none of them, and no corpus row
  exercises them, so a gate would be an ungraded guess.
  - **Completion mechanism:** a Flash-oracle fixture per API family (AVM1 SWF 8: try each call under
    `allow_networking = "internal"`/`"none"` via `[subtests]`) in `regression/`. The harness change here grades such a
    fixture automatically. The fixture would be listed under LOCAL ORACLE REQUESTS, except that Flash's
    `allowNetworking` is an HTML embed parameter the standalone projector oracle likely cannot set. Check
    `tools/flash-oracle` for an embed or `mm.cfg` knob first.
- **Full render canary:** substituted by the subset above (reason given there). If the coordinator wants it anyway,
  run `ruffle-tests/render_canary.py capture/compare` over the standing list; the expected result is all IDENTICAL.

## New unclaimed leads

1. `scripts/corpus_status_diff.py` reports only the intersection. A run that **adds** rows (this one, or any future
   subtest split) shows no "NEW" section, so new rows are invisible unless someone reads the totals. A
   `NEW (absent from baseline)` list with statuses would make denominator growth auditable. Price: S. I left it out of
   scope (`scripts/` is outside my patch scope).
2. The same `<test>__<variant>` row mechanism could grade the other two version-less `[subtests]` tests on the trace
   axis (`avm2/edittext_device_transform_layout`, `avm2/bitmapdata_drawwithquality`; currently image-only splits).
   That only matters if their variants' trace outputs differ. Not checked.

## LOCAL ORACLE REQUESTS

None required for this patch: the goldens are Flash's, shipped upstream. Optional: see "Not done" for an
allowNetworking embed knob in the Flash oracle.
