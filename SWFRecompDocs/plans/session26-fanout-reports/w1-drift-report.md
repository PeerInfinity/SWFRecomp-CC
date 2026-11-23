# s26 wave 1 — `w1-drift` report (upstream drift `3ac8dcb07..3e98d9ba6`)

**New files:** `w1-drift-report.md` (this file), `w1-drift-prototype.patch` (source diff vs `origin/master` `ec07cc9e`; source tree reverted, the commit holds only these two files).

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Upstream SHA at download time: **`3e98d9ba6`** (`git ls-remote` = `3e98d9ba69b1…`, the same as the coordinator's wave-0 fetch: **no further upstream commits**). `download_tests.sh avm1 avm2 visual` (no `--clean`).

## Verdicts (lead)

| Row | Verdict | Priced flip |
|---|---|---|
| `avm1/file_reference_upload_request` | **GO: measured prototype, sweep-clean, CI-grade** | **+1 trace pass, both modes** (`output_mismatch` 5/158 → `pass` 158/158) |
| `avm2/pixelbender_conditional` (17f93dc84) | **No-op for us.** Only the two `.pbasm` *sources* changed; `.pbj` and `test.swf` are byte-unchanged (name-status lists M on the `.pbasm` only), and `Test.as` never references a `.pbasm`. Local graphics: `pass` | 0 |
| `visual/video/vp6_inter_frames` (3e98d9ba6) | **No-op for verdicts.** `test.toml` drops `known_failure = true` from `output.02..16` (15 comparisons) and the 15 `output.NN.ruffle.png` sidecars go. `output.NN.expected.png` (the Flash goldens) are unchanged. We already pass all 16 (baseline and local re-run: `max difference 1`, tolerance 1, 0 outliers) | 0 |

**Expected moves the next CI run will show from drift alone: none** (trace or pixel). Details in §1.

## 1. Drift inventory at the download SHA (`3e98d9ba6`)

Name-status `3ac8dcb07..3e98d9ba6` under `tests/tests/swfs`: avm1 6 paths, avm2 2, visual 16. Nothing in any other category. The full list is the coordinator's `wave0-upstream-drift-namestatus.txt` (re-checked: identical).

| Graded row | Change | What the next CI shows from drift alone |
|---|---|---|
| `avm1/file_reference_upload_request` | **NEW** (bc2211449): `test.as/swf/toml`, `output.txt` (158 lines), `README.md`, `server.py` | **Already in the s26 baseline** (`9277f3799`: `output_mismatch`, expected_lines 158, the same as today). No denominator move. The baseline download therefore already included `bc2211449`. |
| `avm2/pixelbender_conditional` | `.pbasm` x2 (sources only) | none (`pass` → `pass`) |
| `visual/video/vp6_inter_frames` | `test.toml` (known_failure removed on 02..16), 15 `.ruffle.png` deleted | Pixel: 16/16 `pass` → 16/16 `pass`; comparison count unchanged (16). Only the `known_failure` field in `image_results_graphics.json` flips `true → false` on output.02..16. The baseline JSON still shows `known_failure: true`, so **the baseline ran BEFORE `3e98d9ba6`**. The `ruffle_match` report-only bucket (`verify_output.py:4877`) only fires on a *failing* known_failure comparison with a sidecar, so it was never populated for this row. Losing the sidecars changes nothing. Trace `pass` unchanged. |

Local-vs-graded set check: every row graded at `9277f3799` in avm1/avm2/visual exists locally, and no new graded row appeared. The local-only directories (`avm1/__framework__`, `shared_object*`, avm2 `large_preload_*/…` children) predate `3ac8dcb07` and are child movies or non-graded directories, not drift.

**Ruffle-side semantics note (caf02173c).** The test navigator now logs `Navigator::fetch:` *before* it answers the `?debug-*` URLs, and logs multipart bodies as text with CR rendered as a literal `\r`. In our corpus only FileReference download/upload use debug URLs, and the only `log_fetch = true` row among them is the new upload test (checked: no other `log_fetch` test references `debug-`). So no existing expected output moved, and none could.

## 2. `file_reference_upload_request`: mechanism, prototype, measurement

### Baseline (reproduced locally, byte-identical to CI's `actual_output`)

```
// upload 0: http://localhost:8000/upload?debug-success&q=1
onSelect(test.txt)
upload() returned true
onOpen(test.txt)
onComplete(test.txt)          <- stops: 5 of 158 lines
```

Three gaps, all in the AVM1 FileReference upload path (`SWFModernRuntime/src/actionmodern/action.c`, FileReference section ~43400-44060 at `ec07cc9e`):
1. **No request log.** `filerefUploadResolve` (`action.c:~43895`) never calls `swf_log_fetch_queue`. The expected output has a `Navigator::fetch:` block per upload (URL, `Method: POST`, `Mime-Type: multipart/form-data; boundary=----------ruffleformboundaryei4ch2ei4gl6`, and the multipart body).
2. **No `onUploadCompleteData`.** Ruffle a1ca48f83 waits for the full response and broadcasts `onUploadCompleteData(file, body)` after `onComplete` when the body is non-empty. The script only advances to the next upload from that handler (or from `onComplete` for `debug-success-empty`), so we stalled after upload 0.
3. **`onHTTPError` without the status**, and no `?debug-error-statuscode=<n>` parsing (caf02173c). Expected: `onHTTPError(test.txt, 404)` / `500`.

The harness's network mock is the runtime itself: `verify_output.py:get_log_fetch` (`:2589`) turns `log_fetch = true` into `-DLOG_FETCH=1`. The log sink is `SWFModernRuntime/src/utils.c:swf_log_fetch_queue` (`:176`). The debug-URL classifier is `action.c:filerefClassifyUrl` (`:~43735`). `server.py`/`README.md` are only for the manual Flash/Ruffle comparison: `.py` is skipped by `find_data_files`, and `README.md` is bundled as an inert data file.

### Flash-over-Ruffle check (attacking the premise "`output.txt` is Flash's")

`output.txt` is **not purely Flash's output**. The `Navigator::fetch:` blocks are Ruffle's *test-harness* log, with Ruffle's fixed boundary (Flash's boundary is random). The **event lines** are the Flash-attested part (`test.as` header: "events and their arguments match Flash Player 32 for the same uploads to a real server"). The README says the body Flash sends matches Ruffle's apart from the boundary. Ruffle now matches Flash here, so there is no Flash/Ruffle conflict to adjudicate. The prototype reproduces Flash's multipart layout and Ruffle's harness log format. `test.toml` has no `known_failure`, and there is no `output.ruffle.txt`.

### Prototype (`w1-drift-prototype.patch`, 3 files, +~250 lines)

All of it is self-localized `static` code in action.c's FileReference block plus one additive branch in utils.c:

- `action.c` **new statics** (after `filerefClassifyUrl`):
  - `filerefUrlStatus`: `?debug-error-statuscode=<u16>`. Like Rust's `parse::<u16>()`, trailing junk or a bare form gives 0.
  - `FrBuf`/`frbufPut`/`frbufLit`.
  - `frContainsBoundary`.
  - `frPutEscapedName` (`"`→`%22`, CR→`%0D`, LF→`%0A`).
  - `frAddField` (one part).
  - `frAddPostData` (`form_urlencoded::parse`: `&`-split, empties skipped, first `=`, `+`/`%XX` via the existing `urlDecode` at `:38571`).
  - `#define FR_FORM_BOUNDARY`.
- `struct FileRefOp`: trailing fields `body`, `body_len`, `status`, `cancelled`.
- `builtin_fileref_upload` builds the body when `upload()` is called, as Ruffle does in `upload_file`:
  - the parts, in order: `Filename`, one part per postData variable, the file part, `Upload=Submit Query`, and a closing boundary, with every line ending in CRLF;
  - the file part uses the field name from args[1], with undefined, null or absent meaning `Filedata`;
  - `postData` is read via `getPropertyWithPrototype(obj,"postData")`, because our prototype shape (Flash's, graded by `global_proto_decls`) has no postData accessor. Setting it creates a plain property;
  - the file name comes from the selection's `name`, or `"file"`.
- `filerefUploadResolve` now:
  - (Ruffle `Error::Cancelled` when a part contains the boundary) logs nothing and fires no events;
  - otherwise queues and flushes the fetch log, so it lands after the calling script and before `onOpen`;
  - on OK: `onProgress`, `onComplete`, then `onUploadCompleteData(file, "Hello, World!")` unless the URL is `?debug-success-empty`;
  - on STATUS: `onProgress`, then `onHTTPError(file, status)`.
- `utils.c:swf_log_fetch_queue`: `body_is_form == 2` = multipart text with each CR emitted as a literal `\r`. Existing callers pass 0/1 only, so they are unaffected. `utils.h` comment updated.

Functions touched in shared files:
- `action.c`: `builtin_fileref_upload`, `filerefUploadResolve`, `struct FileRefOp`, plus the new statics above.
- `utils.c`: `swf_log_fetch_queue`, only in the `SWF_LOG_FETCH_ENABLED` arm.
- Neither `swf.c`, `swf_core.c`, `tag.c` nor any `#ifdef NO_GRAPHICS` arm is touched, so there is no overlap with `n-pixel-pass` beyond `action.c`'s FileReference block.

Out of scope, deliberately: `download()` still does not log its GET under `LOG_FETCH`. No graded download row sets `log_fetch`, so it is invisible to the corpus. Note it for completeness if someone adds one.

### Measurement: A/B, both modes, md5 of the saved actual output

Before = clean `ec07cc9e`; after = prototype. 30 rows, run singly (`--tests-dir=<suite> --test=NAME [--mode=graphics] --verbose --save-actual`):

| Row | before (gfx / ng) | after (gfx / ng) | actual md5 |
|---|---|---|---|
| **avm1/file_reference_upload_request** | MISMATCH / MISMATCH | **PASS / PASS** | `6b1d99f4` → `f2af5ebc` (identical across modes) |
| avm1 `file_reference_{browse_cancel, download_cancel, download_httperror_dns_error, download_httperror_status_code, download_success, list_asbroadcaster, list_browse_cancel, list_browse_invalid_filters, list_browse_select, listeners_per_instance, upload_httperror_dns_error, upload_httperror_status_code, upload_success}` (13) | PASS / PASS | PASS / PASS | **identical** |
| avm1 `load_vars`, `loadvars_tostring`, `loadvariables_method`, `netconnection_send_remote`, `geturl`, `amf0_serde_suite`, `xml_socket_connect_null` (`log_fetch` / net-POST neighbours) | PASS / PASS | PASS / PASS | **identical** |
| avm2 `filereference_{browse_cancel, browse_select, load, save, save_and_browse, save_and_load, uninitialized}`, `filereferencelist_{browse_cancel, browse_select}` (9) | PASS / PASS | PASS / PASS | **identical** |

After the final cleanup edit (removing an unused local), `file_reference_upload_request` and `file_reference_upload_httperror_status_code` were re-run in both modes: PASS ×4. `upload_httperror_status_code` uses a bare `?debug-error-statuscode`, so the status argument is 0. Its output is byte-identical, so it does not trace the second argument.

No `regression`-suite row covers FileReference or `log_fetch` (grepped). The corpus row is the oracle-backed test. Paths with **no corpus coverage**:
- the boundary-containment cancel;
- a status code with trailing junk;
- `postData` installed as an `addProperty` getter (we read the raw slot without invoking a getter);
- a `%00` in postData, which truncates in C strings.

They need no fixture to land this, but they are listed under oracle requests if wanted.

Rider-sweep scope note: no `xml_send*` / `load_vars*` rows other than the ones listed exist in avm1. `pixelbender_*` and `video/*` pixel rows were not re-rendered. The prototype touches no render path (only the AVM1 FileReference upload and a `LOG_FETCH`-only log branch), and the drift touched none of them other than the two rows above. Their baseline statuses (e.g. `pixelbender_dithering`, `video/colorconversion/h263`) are unaffected by construction.

**Landing:** CI mode `graphics` per-change. The patch does not touch no-graphics-only code, and the no-graphics leg is already measured identical here. `categories=all` suffices (AVM1 runtime only, no AVM2/recompiler change).

## Refutations / premise attacks

- "`output.txt` is Flash's": partly false. The fetch-log lines are Ruffle harness output. Only the event lines are Flash-attested. No conflict, because Ruffle matches Flash on this row (§2).
- "pixelbender_conditional changed": refuted as a graded change. Only the sources changed, and the compiled `.pbj` and `test.swf` did not.
- "vp6_inter_frames drift moves our pixel grade": refuted. Zero verdict or denominator change. The `known_failure` flip is JSON metadata only, and we were already passing all 16 against the unchanged Flash goldens.
- Baseline SHA: the baseline CI contained `bc2211449` but **not** `3e98d9ba6` (vp6 `known_failure: true` in the baseline JSON). So the next CI is the first to carry the vp6 `test.toml`, and it produces only the metadata flip described above.

## New unclaimed leads

- `FileReference.download()` under `log_fetch`: Ruffle (since caf02173c) would log a `Navigator::fetch:` GET for it. We don't, and no corpus row grades it. Cost S, if a future upstream test adds it.
- AVM1 `FileReference.prototype.postData` accessor: Ruffle declares one (DONT_ENUM getter/setter that coerces on set). Our proto shape follows `global_proto_decls` (Flash), which lacks it. Not graded anywhere. Leave it unless a test reads `postData` back after a non-string assignment.

## LOCAL ORACLE REQUESTS

None required to land. Optional, only if the coordinator wants fixtures for the untested edges: a Ruffle exporter `--trace-log` run with `log_fetch` of an AVM1 SWF that sets `postData` with `+`, an empty piece (`a=1&&b`) and a key with no `=`, then uploads to `?debug-error-statuscode=404&x`. That confirms the empty-piece, no-`=` and `status 0` paths.
