# w1-drift-avm1: upstream drift pricing, AVM1 / gnash / shumway side (session 23, wave 1)

**New files on this branch:** this report, and `w1-drift-avm1-prototype.patch` (466 lines; `git diff origin/master -- SWFModernRuntime SWFRecomp`; touches 2 files, `action.c` and `avm1_amf.c`). No source changes are committed.

**Environment:**
- Cloud box; `SETUP_STATUS` is all OK (apt, Pillow, Dawn).
- Tests come from `download_tests.sh avm1 from_gnash from_shumway`. That script pulled upstream master `aa9f62a70`, which is one commit past `0ddd12b6a` (a VP6 visual test). That commit changes nothing under avm1, from_gnash or from_shumway (`git diff --stat` is empty), so these runs are equivalent to `0ddd12b6a`.
- Ruffle source is a blobless clone in `/root/ruffle`.
- Every run is a single test with `--mode=graphics --diff --verbose`, at most `-P 2`, unless it says otherwise.

---

## 0. Headline

- **The baseline labels are right. All 2 of my side's trace losses are upstream drift, and there are 0 code regressions.**
- **Prototype: +8 trace flips, every one measured.** That is 2 drift re-flips/repairs plus 6 new upstream tests, with **0 regressions** across ~125 neighbour rows (graphics), and the 8 headline rows also pass in no-graphics.
- **Priced but not prototyped: about +4 more.**
  - the Video.width/height slot: `NetStream-SquareTest` re-flips to `ruffle_matched`, plus `video_width_height` and `video_prototype_lazy(_swf6_child)` further out;
  - `xml_status_mismatched_tags`;
  - `shared_object_members_swf5`;
  - `file_reference_listeners_per_instance`.
- **`f0aa96e0c` (num_frames → num_ticks) cannot move any AVM1-side verdict.** It touches 1073 tomls on my side, each one a same-value swap with no other edit, and our harness reads the two keys with the same precedence Ruffle's framework does (§3).
- **Graded-row growth on my side is +32:** 31 new avm1 tests plus 1 regression fixture. Nothing in gnash or shumway is newly graded. **I cannot reproduce the coordinator's 4752** (§4).

---

## 1. Price table: every drift status move and new row on my side

**Legend.** Drift = the row's expected output, sidecar, SWF or toml changed upstream; "new" = the test was added upstream. "Proto" = flipped by `w1-drift-avm1-prototype.patch`, measured in graphics and no-graphics.

### 1a. Status moves in the intersection (`corpus_status_diff.py 8d83af7e2 origin/master`)

| Row | CI move | Label | Why | Re-flip |
|---|---|---|---|---|
| `avm1/netconnection_serialize_arrays` | pass → output_mismatch (5/6) | **DRIFT** | `5b29f2e73`/`6014f38c0`: `output.txt` and the SWF were rewritten, `known_failure` was removed and `output.ruffle.txt` deleted. The new test puts a function inside a strict array; Flash writes `06` (undefined), we write `03 00 00 09` (empty object). | **GO S, proto: PASS.** M1b below |
| `from_gnash/misc-ming.all/NetStream-SquareTest` | ruffle_matched → output_mismatch | **DRIFT** | `d900f711d` (Video.width/height) changed only `output.ruffle.txt`; Ruffle now passes 16 Video lines (c:316-330, 411-421). I recomputed the subset with `verify_output._diff_indices` on our live output: ours ⊆ the **old** sidecar (95 ⊆ 108), but 16 lines are outside the **new** one (92). Those 16 lines are exactly `Video.prototype.hasOwnProperty('width'/'height')` and `video.width/height == 0`. | **GO M → ruffle_matched**, slot V |

No other move on my side. Every other avm1/gnash/shumway row in the intersection keeps its status and line counts. That includes all 32 `from_gnash/actionscript.all` sidecar edits, `flash_net_classes`, `amf0_serde_suite`, `amf_array_serialization` and `placeobject_occupied_depth`; see §2.

### 1b. New graded rows (31 avm1; CI status = my local status for each)

| Row | CI status (lines) | Mechanism | Price | Verdict |
|---|---|---|---|---|
| `array_truncation_non_canonical_keys` | mismatch 29/37 | M1a: non-canonical array keys | S | **GO, proto PASS** |
| `sparse_array_truncation_non_canonical_keys` | mismatch 35/43 | M1a | S | **GO, proto PASS** |
| `amf_array_indices` | mismatch 23/32 | M1a + M1c (AMF0 reader) | S | **GO, proto PASS** |
| `localconnection_serialize_function_array_elements` | mismatch 14/20 | M1b: LocalConnection array rule | S | **GO, proto PASS** |
| `xml_stringify_utf16` | mismatch 1/4 | M2: lone surrogate → U+FFFD in XML | S | **GO, proto PASS** |
| `amf0_utf8_probe` | mismatch 13/14 | M2 (its one line is XML `toString`) | S | **GO, proto PASS** |
| `shared_object_secure` | mismatch 19/20 | M5: `getLocal(..., true)` must return null | S | **GO, proto PASS** |
| `amf0_array_matrix` | mismatch 39/50 | M1b fixes 10 of 11 lines (now 49/50). Left: `receivedMixed instanceof Array` is false for an LC-received ECMA array that has named keys | S-M | HOLD: one line; completion = the instanceof walk on an `ASArray` with `props` (`actionInstanceOf`, action.c:50054) |
| `localconnection_serialize_inherited_array_indices` | mismatch 11/12 | M1d: the LC strict writer must read a hole through the prototype (Flash sends the inherited `[0]`) | S | GO-S (not prototyped) |
| `localconnection_serialize_sparse_array_getters` | mismatch 23/26 | M1b fixes 2 of 3 lines. Left: `addProperty("2")` on an Array must be enumerable (array addProperty flags) | S | HOLD: the last line is array addProperty enumerability |
| `localconnection_reference_identity` | mismatch 2/5 | M1e: AMF0 reference table across LC args (`6a6222860`, "sibling reference semantics") | M | GO-M |
| `localconnection_xml_unavailable` | mismatch 9/23 | M1f: LC deserializes XML with the XML class gone; Flash gives a bare object with no proto/methods (`f6dd758c2`) | M | GO-M (one row) |
| `xml_status_mismatched_tags` | mismatch 40/63 | M3: XML parser status `-9`/`-10` plus stop-on-mismatch | S-M | GO-S/M |
| `shared_object_members_swf5` | mismatch 25/32 | M6: SharedObject methods are VERSION_6 (hidden from SWF5) | M | GO-M (needs a version-gate property bit) |
| `file_reference_listeners_per_instance` | mismatch | M7: AsBroadcaster `_listeners` per instance (`2036a2eb2`) | S-M | GO-S/M |
| `edittext_asfunction_case_insensitive` | mismatch 0/1 | M8: `asfunction:` prefix is case-insensitive (`bd401e66e`). `strncmp` at action.c:79565 needs `strncasecmp` (in the patch), **but that is not sufficient**: instrumenting showed `handle_asfunction` is never reached for this `createTextField` html field | S + debug | HOLD: the click → link dispatch never fires (action.c:79690-79735 `mc_get_pixel_aabb_ng`/char-index path) |
| `video_width_height` | mismatch | V + Video `_width/_height` from DefineVideoStream bounds (we give 0, Flash 160×120) + decoded size 320×233 | M | slot V |
| `video_prototype_lazy` | mismatch | V (the full lazy-per-proto semantics, and `v.__proto__` = the prototype at creation) | M-L | slot V, stretch |
| `video_prototype_lazy_swf6_child` | mismatch | V (the per-proto record is shared across SWF6 and SWF7 movies) | M-L | slot V, stretch |
| `external_interface_monkeypatch` (KF, sidecar) | mismatch | ExternalInterface methods are AS-level wrappers (`_initJS`, `_toJS`, `_evalJS`...) | L | NO-GO (would need an `ExternalInterface.as` port) |
| `asnative_instrument`, `asnative_sweep` (KF) | ruffle_matched | ASnative instrumentation and major-index sweep | L | NO-GO for pass; already effective |
| `textfield_get_text_format_args`, `textfield_set_text_format_args`, `textfield_set_text_format_text_change`, `edittext_set_text_same`, `edittext_set_text_same_after_edits` | mismatch | — | — | **owned by w2-tf-css, skipped** |
| `bitmapdata_hittest_default_threshold`, `localconnection_serialize_undefined_array_elements`, `localconnection_xml`, `netconnection_deserialize_strict_array_undefined` | pass | — | — | already passing |

---

## 2. Modified tests: what moved and why

**Rows whose verdicts held:**

- **`global_proto_decls` (KF):** still fails. Matching fell 803 → 59 because the test was rewritten (`41dfd100c`): it now starts its walk at `_global` and tags each function `[function]` vs `[function with prototype]`. So did **`global_instance_decls` (KF)**, 26 → 19.
  - The new axis is "a native method has no `prototype` property". Ours mostly do (they get one from `setupNativeFuncOwnProps`), and the `__proto__` DONT_DELETE flag is also new.
  - This is a cross-cutting lead (see §6), but neither row is near a flip. **NO-GO.**
- **`globals_monkeypatch` (KF):** test rewritten; 41/246 → 43/306. Still fails. `w1-trace-tail` already ruled it NO-GO as drift.
- **`global_proto_decls_delete`:** only `output.ruffle.txt` changed. It fails on both sides with identical counts.
- **`placeobject_occupied_depth`:** the SWF was regenerated from a new `.swfasm`. Still passes 6/6.

**Rows with `known_failure` removed and `output.ruffle.txt` deleted:** `amf0_serde_suite`, `amf_array_serialization`, `from_shumway/flash_net_classes`.
- All three pass, so nothing moves today.
- From now on, any regression on them grades as a plain fail, never `ruffle_matched`.

**`netconnection_serialize_arrays`:** the same KF removal and sidecar deletion, plus a new `output.txt`. That is why it lost (§1a).

**The 32 `from_gnash/actionscript.all` files:**
- All are `output*.ruffle.txt` sidecar edits (Function-v6/7/8 `fp*`, Inheritance, Object `fp*`, argstest `fp*`, ExternalInterface-v8).
- Every row keeps its exact status and line counts. The `ruffle_matched` rows still pass the subset test against the new sidecars.

**`misc-ming.all`:**
- `NetStream-SquareTest`: see §1a.
- `Video-EmbedSquareTest`:
  - `known_failure` was added, `with_renderer` changed from low to high, and the PNG was re-goldened with a new `output.ruffle.png`.
  - The trace stays pass. The pixel row stays fail, 12 → 1794 outliers; that one belongs to `w1-glyph-precision`/pixel.
  - Because of the KF flag, a pixel pass would be Flash-correct.

**Shumway:**
- `as3-loader/events/loader-events`: sidecar change only; still fails 5/36.
- `acid/acid-mask`: `max_outliers` raised 16 → 20 on 3 comparisons. All three are still far over (≥9447 outliers), so no image move.

**Other toml edits:** `avm1/edittext_stylesheet` gained `max_outliers = 6`; its image still passes with 0 outliers.

**`known_failure` added on new tests:** `asnative_instrument`, `asnative_sweep`, `edittext_set_text_same_after_edits`, `external_interface_monkeypatch`. For these, a future `pass → ruffle_matched` move would be a regression.

---

## 3. `f0aa96e0c` (num_frames → num_ticks): no verdict can move

- **The commit is purely mechanical on my side.** Its diff on `avm1`/`from_gnash`/`from_shumway` covers 1073 `test.toml` files. In each, `-num_frames = N` becomes `+num_ticks = N` with the same N, and no other line changes. I checked this per file with awk.
- **Our harness:** `verify_output.py:1033 get_num_frames` takes `num_frames` if present, else `num_ticks`, else 1. It then applies the `wait_count` floor.
- **Ruffle's framework:**
  - Iteration count: `tests/framework/src/runner.rs:139` uses `num_frames.or(num_ticks)`, the same precedence.
  - Iteration mode: `runner.rs:237` runs `tick()` when `num_ticks` is set and `run_frame()` otherwise. Upstream asserts the two are equivalent for exactly these tests ("where running them with ticks executes the same code"). We have a single iteration model, so the count is the only input we read, and it is unchanged.
- **Neither or both keys:** I scanned every `test.toml` under avm1, from_gnash, from_shumway and regression. None has both keys, none has neither, and none repeats a key.
  - With neither, Ruffle errors (`runner.rs:71`) while we default to 1. No file on my side is in that state.
  - Our regex is unanchored, so a key inside a `[subtests.*]` table would also match. No file on my side has that.

---

## 4. Graded-row accounting (the 4563 → 4752 question)

These counts are read from `origin/master` `*/_results/results_graphics.json`; `results.json` gives the same totals.

- 4689 rows across 20 files.
  - `corpus_status_diff.py` skips `from_shumway/avm1` (47 rows) as NESTED: those are duplicates of `from_shumway` rows.
  - That leaves **4642 unique graded rows**. 4563 of them are shared with s22 (nothing disappeared), and **79 are new tests**.
- The 79 new tests by suite: avm1 31, avm2 42, regression 1 (`avm2_activation_vtable_bounded`, from `c1fa89bc2`), stage3d 1, text 1, visual 3. My half is the **32** avm1 + regression rows.
- No suite or subtest is newly graded on my side:
  - The 2 new avm1 subtest tests, `allow_networking_import_assets` and `allow_networking_import_assets2`, have only `output.{none,internal,all}.txt` and no `output.txt`, so they are **not graded at all**. That is a harness-semantics question for `w1-drift-avm2`.
  - `from_gnash` and `from_shumway` gained no tests.
- **I cannot reconstruct 4752** from any results file at `origin/master`. 4752 − 4689 = 63, and 4752 − 4642 = 110; the coordinator's effective counts show the same 110 gap. Possibly it summed `image_results` or another stem. My unique-row total is **4642 graded / 4515 effective**.

---

## 5. Mechanisms (wave-2 units) and the prototype

### M1: AVM1 array keys and per-transport AMF0 array rules (`5b29f2e73`, `cdbc2f268`, `6014f38c0`, `6a6222860`). Prototype: +5.

**M1a (action.c): a non-canonical index string is a named property, but it still bumps `length`.**
- Flash and Ruffle (`object.rs parse_canonical_array_index`, `script_object.rs:1110 parse_array_index`):
  - Only `"0"` or `[1-9][0-9]*` is an element.
  - `"05"`, `" 5"`, `"+5"` and `"-0"` are stored verbatim. Truncation never deletes them.
  - They still extend `length` through a lenient parse: trim leading ASCII whitespace, accept a `+`/`-` sign, and require the rest to be digits.
- Ours: every Array string-key site uses `strtoll`, which accepts all of those keys. The sites are action.c:53488 (SetMember), :55707 (delete), :56920 (GetMember), :66528 and :67253 (both `hasOwnProperty` paths).
- Patch: add `isCanonicalIndexStr()`, gate the 5 sites on it, and widen the length-bump scanner at :53523 to skip leading whitespace and accept `+`.

**M1b (avm1_amf.c `w0_array_view`, :525): the strict-array rule depends on the transport.**
- NetConnection: a function element writes `06`; it occupies its index.
- LocalConnection: StrictArray only when the array is genuinely dense:
  - every key is canonical, `#keys == length`, and no element is undefined, a function or a display object;
  - otherwise it is an ECMAArray with verbatim keys and functions omitted;
  - its declared length is `max(length, maxcanon+1)`.
- SharedObject: unchanged; always ECMA.
- Patch: add an `lc_mode` on `Amf0Wr`, set only by `avm1AmfSerializeArg`, which is the LC path (action.c:3828).

**M1c (avm1_amf.c reader):**
- `rd0_pairs_into_array` (:1003) must keep non-canonical keys as named properties.
- The ECMA declared length must act as a floor (Ruffle runs `new Array(declared)`, :1116).
- Also, `setObjectProto` on `arr->props` (:1014) is inconsistent with every script-side `arr->props` allocation. I dropped it; no measured change.

**M1d, M1e, M1f:** inherited-hole reads, the LC reference table, and XML with its class unavailable. See the table.

**Sweep (graphics), 0 regressions:**
- every avm1 `array*`, `*sparse*`, `amf*`, `localconnection*`, `netconnection*`, `shared_object*` row;
- gnash `array-v5..v8`, `LocalConnection-v5..v8`, `XML*`, `XMLNode*`, `XMLSocket*` (`-v5..v8`);
- shumway `flash_net_*`, `localconnection`;
- 14 regression rows (array, LC, XML, SO, string).

Every row keeps its baseline status.

### M2: lone surrogates in XML (`4ed7a3865`/`aa1deca65`). Prototype: +2.

- The XML node tree is UTF-8 internally.
- `u16_to_utf8` (action.c:275) maps a lone surrogate to U+FFFD by design. That is correct for trace output, so I did not change it globally.
- Patch:
  - a static `u16_to_wtf8` writes a lone surrogate as its own 3-byte sequence;
  - its 16 call sites are confined to the XML block (action.c ≈19000-21500);
  - `utf8_to_u16` already decodes such a sequence back to the original unit.
- Sweep: 41 avm1 XML rows plus the 12 gnash XML rows, all unchanged.

### M3: XML parser status codes (`4a8d39661`, Flash 32-recorded; Ruffle passes it)

- Flash's rules:
  - an end tag that matches the **parent** of the current element gives status −9 and stops the parse;
  - any other mismatch, or an orphan end tag, gives −10 and stops;
  - EOF with elements still open gives −9.
  - In every case the tree built so far is kept, with open elements auto-closed.
- Ours:
  - `xml_parse_into` (action.c:19784) never writes a nonzero status;
  - a mismatched close just pops one element and carries on (:19858);
  - an orphan close sets `parse_failed`, which **discards the whole document**. The comment there cites gnash `XML.as:1040`.
- The orphan rule has to be reconciled with the gnash XML-v* rows: Flash keeps `foo` for `foo</a>`. That is the S→M risk.
- Flips: `xml_status_mismatched_tags` (+1).

### V: Video.width/height and lazy prototype properties (`d900f711d`, `c8a03ccd3`)

- Flash's behaviour:
  - creating a Video **display object** (`new Video()` does not count) defines read-only `width`/`height` accessors on that Video's prototype;
  - this happens at most once per prototype object, recorded across all movies;
  - the accessors return the decoded frame size, or 0 before any frame is decoded.
- Ours:
  - `initVideoPrototype` (action.c:40878) defines only `attachVideo` and `clear`;
  - a timeline Video is a MovieClip wrapper (`mcIsTimelineVideo` :16159) that falls back to `Video.prototype` only for member lookup (:58574);
  - `v.__proto__` is not the Video prototype, and `_width`/`_height` come out as 0.
- Minimum for `NetStream-SquareTest`: on timeline placement of a video character, define getter properties on the current `_global.Video.prototype` once per proto, with the getter returning the `g_video_frames` decoded size or 0. `setAddPropertyWithFlags` (:12393) is the helper.
- The hook point is the placement path in both `tag.c` (graphics) and the no-graphics placement path. That is why this is M, and it needs a mode-parity check.
- Stretch work for the lazy tests: `__proto__` captured at creation; and Video `_width/_height` from the DefineVideoStream bounds (`ng_getVideoDimensions`).

### M5, M6, M7, M8: small singletons

- **M5:** `getLocal`'s secure argument, strictly boolean `true` → null. Prototyped: +1.
- **M6:** a version-gate property bit for VERSION_6 builtins.
- **M7:** a per-instance `_listeners` array for FileReference(List).
- **M8:** `asfunction:` case-insensitivity plus the click dispatch that never fires.

---

## 6. Wave-2 slots I would fund

Each slot includes a `regression/` fixture check and graphics + no-graphics runs.

1. **w2-avm1-array-amf** (S; land the M1 + M2 + M5 prototype as is, then extend to M1d/M1f)
   - **Expected +8:** `array_truncation_non_canonical_keys`, `sparse_array_truncation_non_canonical_keys`, `amf_array_indices`, `netconnection_serialize_arrays` (drift re-flip), `localconnection_serialize_function_array_elements`, `xml_stringify_utf16`, `amf0_utf8_probe`, `shared_object_secure`.
   - **Stretch +1-2:** `localconnection_serialize_inherited_array_indices` (M1d), `amf0_array_matrix` (instanceof).
   - Regression fixtures need an outside oracle; see LOCAL ORACLE REQUESTS.
2. **w2-video-props** (M)
   - Lazy `width`/`height` on the Video prototype at display-object creation, plus decoded size.
   - **Expected:** `from_gnash/misc-ming.all/NetStream-SquareTest` back to `ruffle_matched` (the drift re-flip).
   - **Stretch:** `video_width_height` (also needs `_width`/`_height` from the DefineVideoStream bounds), `video_prototype_lazy`, `video_prototype_lazy_swf6_child`.
3. **w2-xml-status** (S-M)
   - Parser status −9/−10 and the stop rule; reconcile with gnash `XML.as:1040`.
   - **Expected +1:** `xml_status_mismatched_tags`.
   - Must keep gnash `XML-v5..v8` and `XMLNode-v5..v8` `ruffle_matched`.
4. **Bundle (optional, S-M each)**
   - `file_reference_listeners_per_instance` (per-instance `_listeners`);
   - `localconnection_reference_identity` (LC AMF0 reference table);
   - `shared_object_members_swf5` (version-gated properties);
   - `edittext_asfunction_case_insensitive` (`strncasecmp` + debug why the link click on a `createTextField` html field never reaches `handle_asfunction`).

**NO-GO:**
- `external_interface_monkeypatch` (needs an ExternalInterface.as port);
- `asnative_*` (already `ruffle_matched`);
- `global_proto_decls`, `global_instance_decls`, `globals_monkeypatch` (rewritten upstream; far from a flip).

Completion mechanism: the "native methods carry no `prototype`" axis, which would be a corpus-wide change to `setupNativeFuncOwnProps`. Price it as its own wave-1 slot before anyone touches it.

---

## 7. Refutations / brief premises attacked

- **"There should be no code regressions":** confirmed for my side. Both moves are drift with a named commit, and every other row keeps byte-identical line counts.
- **"`NetStream-SquareTest`: sidecar changed or deleted":** it was changed, not deleted. It is re-flippable to `ruffle_matched` only by implementing Video.width/height. No other line blocks it; I checked the subset exactly.
- **The AMF series looks like one mechanism, but is three:** the writer transport rule, the reader key/length rules, and the script-side key canonicality. The script-side one lives in `action.c`, not the AMF codec, and is what flips the two `*_truncation_*` rows.
  - An important nuance I learned by measuring: Flash keeps `"02"` as a **named** key but still bumps `length` to 3. Canonicalizing without the lenient length bump costs `amf_array_indices` lines.
- **A diff-line lead is not a flip lead, for `edittext_asfunction_case_insensitive`:** the one-word upstream fix (`bd401e66e`) is necessary but does **not** flip our row, because our click never reaches the link handler.

## New unclaimed leads

- Native builtin methods expose a `prototype` (the `global_*_decls` `[function with prototype]` lines). This is cross-cutting.
- `actionInstanceOf` returns false for an `ASArray` that carries named `props` after an LC round-trip (`amf0_array_matrix`, 1 line).
- `addProperty` on an Array index is not enumerable (`localconnection_serialize_sparse_array_getters`, 1 line).
- `avm1/shared_object` and `avm1/shared_object_self_ref` are two-phase tests (`output1/2.txt`) that crash `verify_output.py` (`PosixPath / NoneType`) and are ungraded. This is pre-existing, not drift.

## LOCAL ORACLE REQUESTS

- For wave-2 regression fixtures only:
  - a Ruffle-exporter trace of a tiny AS2 fixture covering `a["02"]=1; a[" 3"]=1; a["+5"]=1; a.length` and `hasOwnProperty("2")`;
  - LocalConnection round-trips of `[f, "x"]` (a function element) and of a sparse `[0,,,3]`.
- These pin M1a/M1b outside the corpus. Not blocking: the upstream rows are already Flash-recorded.
