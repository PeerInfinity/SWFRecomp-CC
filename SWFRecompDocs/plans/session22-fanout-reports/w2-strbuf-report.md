# w2-strbuf: AVM2 append-in-place string buffers (session 22, wave 2, slot B of w1-trace-tail §11)

**New files:**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-strbuf-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-strbuf.patch` (`git diff --binary origin/master` over the source and the fixture; `git apply --check -R` passes on the branch head)
- `ruffle-tests/tests/swfs/regression/avm2_strbuf_stale_prefix/` (`create_test_swf.py`, `test.swf`, `output.txt`, `test.toml`). This is a NEW regression fixture. `test.swf` is force-added because the root `.gitignore` ignores `*.swf`, like every other regression SWF.

**Modified files:**
- `SWFModernRuntime/include/avm2/avm2_value.h`
- `SWFModernRuntime/src/avm2/{avm2_value.c, avm2_gc.c, avm2_external.c, avm2_bitmap.c, avm2_array.c, avm2_display.c}`
- `ruffle-tests/tests/swfs/regression/README.md` (one table row)

There are no new `.c` or `.h` files, so no edits to the build lists are needed.

**Setup:**
- Cloud box. `SETUP_STATUS`: apt, Pillow and Dawn all OK.
- Base is `origin/master` `6af70057c`.
- Upstream corpus came from `download_tests.sh` (Ruffle master `653ef4f41` at download time). Categories: `from_avmplus avm2`, plus `avm1 fonts from_shumway text visual` for the canary.
- Every run used `--mode=graphics --verbose` unless it is marked no-graphics.

## 0. Verdict and priced flips

| verdict | flip | axis | cost |
|---|---|---|---|
| **GO: implemented** | `from_avmplus/regress/bug_483783`: **runtime_error → pass** (both modes) | trace | S (+93 lines in `avm2_value.c`, +27 in `avm2_gc.c`, +30 in the header, ~15 lines at the C-string sites) |

The w1 diagnosis holds as written: **no GC change beyond marking is needed**. The run fits with no mid-method collection: 395 MB RSS, against an arena exhaustion at 3.1 GB before.

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| test | trace axis | pixel axis |
|---|---|---|
| `from_avmplus/regress/bug_483783` | `runtime_error` → **`pass`** (graphics and no-graphics) | none (no image row) |
| `regression/avm2_strbuf_stale_prefix` | **NEW row → `pass`** (a new test, not a flip; it passes on the base too, see §3) | none |
| everything else | **no change** | **no change** (canary: 125/125 PNGs md5-identical) |

## 1. Mechanism and patch scope

**Before** (`avm2_value.c:142`, `avm2_string_concat`):
- Every `a + b` copied `a` into a fresh block.
- `for (j < 3000000) s += "a"` is therefore O(n²) bytes. The heap OOMs at about 76 k characters.

**After:**
- **The append path.** When the result is ≥ `AVM2_STRBUF_MIN_LEN` (4096 bytes), there is no WTF-8 surrogate seam join, and both sides are non-empty, `strbuf_append` takes over:
  - **`a` is the frontier of an append buffer** (`AVM2_STR_GC_DEP`, `a->len == buf->len`) and the buffer has room: `b` is written in place.
  - **`a` is a plain string, or a full frontier**: a new buffer is minted with capacity `2*total+1` (avmplus `String::append` doubling).
  - **`a` is a stale prefix of a buffer** (`a->len < buf->len`, i.e. a branch like `x = base + i`): `strbuf_append` returns NULL, and the old exact-size copy path runs. This means a second branch can never clobber the first branch's bytes, and a loop of branches does not mint a 2× buffer per iteration.
  - The result is always a **fresh** 32-byte `AVM2_STR_GC_DEP` header whose `utf8` is the start of the buffer's bytes. Older headers keep their own `len`, so values never change.
- **Where `cap` lives.** It sits in the BUF's inline bytes, as the brief preferred: the layout is `[Avm2String header][8-byte prefix: uint32 cap][bytes…]`.
  - `Avm2String` does **not** grow. It is still 32 B native and 16 B on wasm32. The w1 prototype's trailing field would have grown wasm32 headers by 4 bytes.
  - The owner is found by pointer arithmetic: `avm2_strbuf_owner(dep) = (Avm2String*)(dep->utf8 - 8) - 1`.
- **GC** (`avm2_gc.c`):
  - `avm2_gc_mark_string` marks a DEP header (or a by-value copy of one) **and** its BUF, in O(1).
  - `avm2_gc_mark_string_bytes` (the range lookup) now uses `str_alloc_end()`. That covers the BUF capacity prefix, and a DEP header's span is the header alone. When the lookup lands on a DEP header it also marks the BUF. This covers a conservative ext-scan word that holds a `const Avm2String*` to a DEP header.
  - `g_str_census_hi` uses the same span.
  - By-value copies, such as `Avm2DynProp.name`, reach the BUF through their `utf8` bytes as before.
  - Sweep is unchanged.
- **Census.** Set `AVM2_STRBUF_CENSUS=1` and the run prints this at exit: `[avm2-strbuf] appends= buffers= buffer_bytes= branch_copies= cstr_copies=`.

**Self-localization:**
- All new code is `static` in `avm2_value.c`, apart from `avm2_string_cstr` and the header's inline `avm2_strbuf_owner`.
- `avm2_gc.c` gets one new static helper.
- **Sibling overlap: `w2-ei-provider` owns `avm2_external.c`.** My edit there is 5 lines in `ei_add_callback` / `ei_call`, which now go through `avm2_string_cstr`. If w2-ei-provider lands first, re-apply those 5 sites by hand. Any new `name->utf8`-as-C-string use in its `test_harness.c` must also go through `avm2_string_cstr(ctx, name)`.

## 2. The NUL-invariant risk: what I did, site by site

**The hazard.** An older prefix header loses `utf8[len] == '\0'` once a later in-place append overwrites that byte.
- Reads never go out of bounds: the buffer is always NUL-terminated at its frontier, and `utf8[len]` is always inside it.
- A consumer that reads `utf8` as a C string would see the **longer** string.

**I did both**, and documented the contract in `avm2_value.h`:
1. **A full audit of `src/avm2`.** I read all 614 `utf8` references and all 236 libc string calls. Generated code never touches `->utf8`: `grep` finds no `utf8` in `SWFRecomp/src`, and no `Avm2String` use outside `src/avm2`.
2. **`avm2_string_cstr(ctx, s)`** returns `s->utf8` when `utf8[len] == 0`. Otherwise it returns a fresh `avm2_string_new` copy.
   - The copy lives at least until the next collection. Collection runs only between ticks (`avm2_main.c:786`, `:872`, "VM quiescent"), so the copy is safe for the whole native call.
   - I routed every true C-string consumer through it.

**Sites routed through `avm2_string_cstr`** (these are all of the real C-string consumers of `Avm2String` bytes):

| site | consumer |
|---|---|
| `avm2_external.c` `ei_add_callback` (×4: `ei_find_callback` / `strcmp`, `strdup`, `ei_notify_callback` ×2) | callback name as a C string |
| `avm2_external.c` `ei_call` | `ei_browser_call(name, …)` |
| `avm2_bitmap.c:2527` `BitmapData.draw` | `blendMode` `strcmp` chain (12 calls, one cstr) |
| `avm2_array.c:1178`, `:1201` | `"%s"` in the `#1005` RangeError message |
| `avm2_display.c:15541`, `:15888` | `'%s'` of `ext->name` in the `AVM2_MOUSE_DEBUG` / tree dump |

**Audited as safe (length-bounded); no change needed:**
- **Property and multiname paths.** All of these take `(ptr, len)` and `memcmp`: `avm2_public_key`, `getproperty_common` / `setproperty_*` / `callproperty_common` / `deleteproperty_common`, `key_from_ns_value`, `key_from_qname_ext` (`ns_uri` + `ns_len`), `avm2_object_{set,find}_dynamic`, `avm2_get/set/init_public_property`, `avm2_has_public_property`, `reflect_find`.
- **Number and date parsing.**
  - `avm2_string_to_f64` and `avm2_string_to_int` take `(ptr, len)`. Their `strtod` runs on a private `tmp[]` copy.
  - `parse_full_date(ptr, len)` takes a length; `dt_sndup` copies with a length.
- **JSON.** `JParser { text->utf8, text->len }`, `js_map_value` / `js_obj_entry` / `sb_json_string` all take `(ptr, len)`.
- **RegExp.**
  - `re_preprocess` copies the source into a NUL-terminated `avm2_alloc` buffer before `lre_compile`, which needs NUL.
  - `lre_exec` runs on the UTF-16 conversion.
  - The replacement scan is bounded by `len`.
- **E4X and XML.**
  - The parser holds `ps.p` + `ps.len`, and every peek is bounded by `pos < len`.
  - `starts_with` checks `len`.
  - The `avm2_xml.c` index/colon scans loop `i < len`.
- **Text and HTML.**
  - `tf_parse_html` takes `p` + `n`.
  - `name_eq_ci` and the stylesheet `strncasecmp` are preceded by a length-equality check.
  - Font-family values are `memcmp` with `vlen`.
  - The `utf8_next(&p, end)` scanners are bounded.
  - The `fwrite(utf8, 1, len)` trace sink takes a length.
- **AMF, net, loader.**
  - `w3_str` / `w0_short_str` / `buf_put` take `(ptr, len)`.
  - The SharedObject cache does `strncmp(name, utf8, len)` and then checks `name[len] == '\0'`, which is correct.
  - URL, header and param logging use `(ptr, len)` everywhere (`swf_log_fetch_queue`, `swf_log_navigate`).
  - `%.*s` is used in `avm2_net.c`, `avm2_ops.c`, `avm2_vector.c`, `avm2_error.c`, `avm2_regexp.c`.
- **ByteArray.**
  - `iconv` takes `in_left = len`.
  - `writeMultiByte` takes `n = len`.
  - `readUTFBytes` scans up to `len`.
- **The remaining 236 libc calls** (`strcmp` / `strstr` / `strtol` / `atoi` / …) all operate on:
  - static tables (class/trait names from the ABC pool, which are recompiler literals and always terminated),
  - environment variables,
  - private `char[]` copies, or
  - harness input lines.
  I traced each indirect caller: `blend_mode_id_from_name`, `label_to_frame_cstr`, `font_name_ci_cmp`, `nc_resolve_response`, `lc_domain_from_url` and the stage3d gates all receive literals or private buffers.

**Exposure, measured.** `cstr_copies = 0` on all 78 rows I ran (42 sample rows + 36 AVM2 regression rows). The 4096-byte threshold and the frontier rule keep stale prefixes rare. When one does reach a C consumer, it gets a correct copy.

## 3. Per-test before/after (clean `origin/master` vs the patch, same box, `--mode=graphics`)

The 10 canary string rows named in w1 §2 are marked ★. The census sample is argued below.

| row | before | after | census (after) |
|---|---|---|---|
| ★ `from_avmplus/regress/bug_483783` | **runtime_error** (`heap_alloc(76392) failed`) | **PASS** | appends=2 995 895, buffers=10, buffer_bytes=8.4 MB |
| ★ `from_avmplus/regress/bug_703238` | pass | pass | no hit |
| `from_avmplus/regress/bug_707133` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_4_12_4` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_4_11_4` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_4_5_5` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_4_7_1` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_4_11_6` | pass | pass | no hit |
| ★ `ecma3/String/e15_5_3_2_3` | pass | pass | no hit |
| ★ `ecma3/String/toLocaleUpperCase3` | pass | pass | no hit |
| ★ `ecma3/String/concat` | pass | pass | no hit |
| `ecma3/String/e15_5_4_5_6_rt` | pass | pass | no hit |
| `ecma3/String/Split` | pass | pass | no hit |
| `ecma3/String/esplit_001` | pass | pass | no hit |
| `ecma3/String/ereplace_001` | pass | pass | no hit |
| `ecma3/String/ematch_001` | pass | pass | no hit |
| `ecma3/JSON/LargeString` | pass | pass | **appends=157, buffers=4** |
| `ecma3/JSON/adhoc` | ruffle_matched | ruffle_matched | no hit |
| `ecma3/JSON/e15_12_1` | pass | pass | no hit |
| `ecma3/JSON/e15_12_2` | pass | pass | no hit |
| `ecma3/JSON/e15_12_3` | pass | pass | no hit |
| `ecma3/JSON/Strings` | pass | pass | no hit |
| `ecma3/GlobalObject/e15_1_2_4` (escape) | pass | pass | no hit |
| `ecma3/GlobalObject/e15_1_2_5_1` (unescape) | pass | pass | no hit |
| `ecma3/Unicode/u0000_BasicLatin` | pass | pass | no hit |
| `ecma3/Unicode/u0400_Cyrillic` | pass | pass | no hit |
| `ecma3/Unicode/u0E00_Thai` | pass | pass | no hit |
| `as3/ByteArray/ByteArrayLzma` | pass | pass | **appends=2, buffers=3** |
| `e4x/XML/e13_4_4_39` | pass | pass | no hit |
| `e4x/XML/e13_4_4_21` | pass | pass | no hit |
| `avm2/dependent_strings` | output_mismatch (IGN: Ruffle-only `isDependent()`) | output_mismatch, identical | no hit |
| `avm2/string_concat_fromcharcode` | pass | pass | no hit |
| `avm2/json_stringify` | pass | pass | no hit |
| `avm2/json_parse` | pass | pass | no hit |
| `avm2/regexp_exec` | pass | pass | no hit |
| `avm2/string_split` | pass | pass | no hit |
| `avm2/string_replace` | pass | pass | no hit |
| `avm2/xml_tostring_namespace` | pass | pass | no hit |
| `regression/avm2_gc_string_concat_reclaim` | pass | pass | appends=915, buffers=4 |
| `regression/avm2_gc_string_survives_collect` | pass | pass | appends=592, buffers=4 |
| `regression/avm2_json_roundtrip_bounded` | pass | pass | no hit |
| `regression/avm2_e4x_parse_bounded` | pass | pass | appends=79 332, buffers=1202 (one `build()` per XML level) |

**How I chose the sample.**
- The w1 canaries.
- Every `from_avmplus` row whose `.as` has a string `+=` inside a loop bounded by ≥3 digits or by `.length`. That grep yields `ByteArrayLzma`, `GlobalObject/e15_1_2_4/5_x`, `JSON/LargeString`, `adhoc`, `e15_12_1/2`, `String/e15_5_4_5_5/5_6_rt`, `bug_483783` and `bug_707133`.
- The ecma3 String regex/split/replace rows, ecma3 Unicode block tables, E4X `XML` serialisation, and the `avm2` string/json/regexp/xml rows.
- The three GC-string regression fixtures.

**Census result:**
- **3 of the 30 corpus rows** in the sample hit the buffer path: `bug_483783`, `JSON/LargeString` and `ByteArrayLzma`.
- **4 of the 36 regression rows** hit it: the three GC-string fixtures plus `avm2_gc_dynprop_tombstone_purge`, and also the new fixture.
- `branch_copies = 0` on every corpus row; the fixture has 2, by design.
- `cstr_copies = 0` everywhere.

**GC-stress leg** (`AVM2_GC_STRESS=1`, the CI `avm2_gc=1` input, which collects before every tick):
- All 6 hitting rows pass.
- Collections are verified to run and to sweep strings (`AVM2_GC_VERBOSE`). For example, `e4x_parse_bounded` ran 122 collections and swept 35 872 strings, and `gc_string_concat_reclaim` ran 6 collections.

**Mode parity:** `bug_483783` also passes no-graphics. No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm was touched.

### The new fixture, `regression/avm2_strbuf_stale_prefix`

What it does:
- Builds a 5000-character `s` (via the buffer), saves `p = s`, then does `s += "XYZ"`.
- Reads the stale `p` through 9 consumers: length, `==`, indexOf/lastIndexOf, slice, charAt, split, RegExp match, and property keys.
- Then reads `q` (4999 spaces + "7") after `d = q + "5"`, using `Number` and `parseInt`.
- Tests two branches off stale `p` (`x1` / `x2`).
- Tests a prefix left behind while the frontier grows by another 5000 in place.

Results:
- It is a **behavior lock**: the output is byte-identical on the base (21/21 lines). It passes in graphics and in no-graphics.
- The census shows appends=6809, buffers=3, branch_copies=2. So the fixture really does exercise the in-place path, the stale-prefix path and the branch path.
- **Mutation check.** A consumer that read `utf8` as a C string would print `Number(q)=75`.

Provenance:
- The SWF is a hand-assembled ABC from `create_test_swf.py`, because there is no mxmlc in the cloud. It holds a single eager DoABC script with top-level code.
- The expected output is derived row by row from ECMA-262 semantics. It **needs Ruffle confirmation** (see LOCAL ORACLE REQUESTS) before it is relied on as an oracle.

### Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`, all 36 `avm2_*` rows, after)

- **36/36 pass**: the 35 baseline rows plus the new one.
- The image sub-checks are unchanged:
  - `avm2_parent_child_render`: 0 outliers.
  - `avm2_timeline_gradients` / `_stroke_gradient`: max diff 1, 0 outliers.
- The baseline `_results/results_graphics.json` has no non-pass `avm2_*` row.

### Graphics canary (`render_canary.py`, `render_canary_tests.txt` as is, `--timeout 5400`)

- **70 tests / 125 PNGs: IDENTICAL 125, DIFFERS 0, APPEARED/VANISHED/NO_RENDER 0.**
- No trace status changes and no image status changes.
- I did not append a member to `render_canary_tests.txt`. The change class is the trace axis (string bytes), not rendering. Its coverage is the new regression fixture plus `bug_483783` itself.

## 4. Memory and performance (native graphics build, same box, median of 3)

| row | before RSS / wall | after RSS / wall |
|---|---|---|
| `from_avmplus/regress/bug_483783` | **3110 MB, OOM exit 1** (~2.5 s to die) | **395 MB, 0.85 s, pass** |
| `regression/avm2_e4x_parse_bounded` (game-like: per-tick XML level builds via `s +=`, GC between ticks) | 190 MB / 1.17 s | 185 MB / 1.04 s |
| `regression/avm2_gc_string_concat_reclaim` (multi-tick accumulator) | 184.6 MB / 0.25 s | 173.3 MB / 0.28 s |
| `ecma3/JSON/LargeString` | 173.8 MB / 0.28 s | 171.4 MB / 0.26 s |

The floor of about 170 MB is the Dawn/graphics runtime.

`bug_483783`'s 395 MB comes from:
- about 3 M DEP headers (32 B each, plus allocator overhead);
- about 8.4 MB of buffers (10 doublings).

None of it is collected, because the loop runs in one script-init. That matches w1's ~150 MB estimate plus the per-allocation overhead.

## 5. Refutations and attacks on the premise

- **"The GC half is needed" (s16/s21).** Refuted again, by measurement: the row passes with no mid-method collection.
- **The w1 prototype's mark-only GC change was incomplete.**
  - The prototype marked the BUF from `avm2_gc_mark_string`, but **not** from the range lookup. A conservative ext-scan word pointing at a DEP header would therefore have kept the header and freed its bytes.
  - It also kept the old span formula, `sizeof(hdr)+len+1`. For a bare DEP header that over-reaches into neighbouring allocations. That is harmless, but it is wrong, and it also set `hi` wrong.
  - Both are fixed with `str_alloc_end()`.
- **The prototype always minted a 2× buffer for any non-frontier `a`**, including branches off a stale prefix. A `x = base + i` loop over a long `base` would allocate `2*len` per iteration. Branches now copy exactly.
- **The prototype's trailing `cap` field.** It is free on 64-bit, because it fits the padding after `gc_flags`. On wasm32, though, it grows every string header from 16 to 20 B. It is now inline in the BUF.
- **Overflow.** The prototype's `total * 2u + 1u` could wrap a uint32. The patch guards `total < 2^31` and `hdr + prefix + cap ≤ 0xFFFFFFF0`, and falls back to the old path otherwise.

## 6. What I could not finish, with completion mechanisms

- **The Ruffle oracle for the new fixture.** See LOCAL ORACLE REQUESTS. Until it is run, `output.txt` is ECMA-derived. Every row is elementary, so I expect Ruffle to match.
- **A census over `categories=full` in CI** (w1's suggestion).
  - I did not touch the workflow: `AVM2_STRBUF_CENSUS` writes to stderr, and stderr is not aggregated by `verify_output.py`.
  - **Mechanism:** a coordinator CI run with `AVM2_STRBUF_CENSUS=1` exported in the job env, then grep the per-test stderr captures. Or accept the 42-row argued sample above: 3/30 corpus hits, 0 C-string copies.

## New unclaimed leads

1. **`avm2_string_to_f64` truncates digit strings at 380 characters, leading zeros included** (`avm2_value.c`, the `char tmp[400]` / `if (ti < 380)` block).
   - Example: `Number("0"×4999 + "7")` gives **0**. ECMA gives 7.
   - A >380-digit integer loses magnitude: `"1"` followed by 399 zeros gives 1e379 instead of Infinity.
   - Fix: skip leading zeros, and add the count of dropped integer digits as an `e+N` suffix before `strtod`.
   - It is pre-existing; I found it while building the fixture, and the fixture deliberately avoids it. I found no corpus row priced for it yet.
2. **Buffer slack on one-off long concatenations.** A non-buffer `a` with `a+b ≥ 4096` now reserves `2*total+1` bytes, which avmplus also does. All measured RSS went down, but a wasm game that builds many distinct 4–64 KB strings once each would hold up to 2× of those bytes until collection.
   - Cheap tuning if it ever shows: reserve `total + total/2` on the first mint.
3. **`avm2/dependent_strings`** (IGN, RVF). It calls Ruffle's private `isDependent()`. We now have real dependent strings, so a `ruffle.isDependent` shim could report `(gc_flags & AVM2_STR_GC_DEP)`.
   - The row is Ruffle-only by design, so this is not a flip unless the ignore entry is revisited.
   - Ruffle's dependence semantics also differ: it treats substrings as dependent too.

## LOCAL ORACLE REQUESTS

1. **`ruffle-tests/tests/swfs/regression/avm2_strbuf_stale_prefix/test.swf`.** Run it through the Ruffle exporter (trace only, 1 frame) and diff against the committed `output.txt` (21 lines).
   - If Ruffle agrees, the fixture stands as is.
   - If any row differs, keep Ruffle's line, and tell the w2-strbuf follow-up which row differs. Our output matches the committed file on both base and patch, so a difference would be a pre-existing runtime bug, not a regression from this patch.
   - Secondary sanity check: the SWF is a hand-assembled eager DoABC with no SymbolClass. Ruffle should run its script init at load.
