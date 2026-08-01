# Wave-2 B11 — AVM1 legacy charset decoding for the form loader

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a916841919a4cf3cc`
Base: `1c7c23761` (master). Patch: `wave2/charsets.patch` (4 files, +1383 / -6).
Brief: `wave1/avm1-charsets.md`. Route B taken as recommended (real decoders,
full generated Shift-JIS table, zero build-file edits).

---

## 1. What changed

### `SWFModernRuntime/include/utils.h` (+35)

New public API, documented with the Ruffle oracle it mirrors:

```c
typedef enum { LEGACY_CS_UTF8 = 0, LEGACY_CS_WINDOWS_1252, LEGACY_CS_SHIFT_JIS } LegacyCharset;
LegacyCharset legacy_charset_detect(const unsigned char* body, int len);
char* legacy_charset_to_utf8(const unsigned char* body, int len,
                             LegacyCharset cs, int* out_len);
```

`utils.h` / `utils.c` were chosen precisely because both are already in every
build (`verify_output.py` `core_sources`, CMake, all 7 build scripts), so this
lands with **no build-file edits at all**.

### `SWFModernRuntime/src/utils.c` (+1170)

- `cp1252_80_9f[32]` — the only bytes where windows-1252 differs from
  Latin-1. Six of them (0x84 0x87 0x89 0x96 0x9C 0x9F) are graded by
  `form_loader_encoding_2`, which is why Latin-1 is not a substitute.
- `sjis_index[11280]` — generated, between
  `/* BEGIN GENERATED shift_jis_index */ … /* END GENERATED … */` markers.
  9604 mappings.
- `sjis_pointer()` — WHATWG Shift_JIS pointer arithmetic.
- `is_strict_utf8()` — a **new strict** validator. The runtime's existing
  `utf8_decode_one` (action.c:171) never checks continuation bytes and would
  accept `C4 D6`, so it could not be reused for detection.
- `looks_like_shift_jis()` — whole-stream validity **plus** at least one real
  double-byte pair.
- `legacy_charset_detect()` / `legacy_emit_utf8()` / `legacy_charset_to_utf8()`.

### `scripts/generate_shift_jis_table.py` (new, +132)

Modeled on `scripts/generate_case_tables.py`. Rewrites the marked block in
`utils.c` in place (idempotent, re-runnable), `--stdout` to preview. Asserts
the three corpus-graded code points (`95D0→U+7247`, `89BC→U+4EEE`,
`96BC→U+540D`) before writing.

Source of truth is CPython's `cp932`. Verified independently after emission:
re-parsed the 11280 emitted hex literals out of `utils.c` and compared every
one against `bytes([lead,trail]).decode('cp932')` — **9604 mapped, 0
mismatches**.

### `SWFModernRuntime/src/actionmodern/action.c` (+52 / -6)

1. `avm1_system_use_codepage()` — file-static next to `g_system_object`
   (line ~4809). Reads the AS property and coerces to truthiness.
2. The form-load site in `actionGetURL2` (line ~47535) now selects a charset
   before parsing, exactly in Ruffle's order:

```
useCodepage                    -> legacy_charset_detect(...)
else g_main_movie_swf_version<=5 -> LEGACY_CS_WINDOWS_1252
else                             -> LEGACY_CS_UTF8   (verbatim)
```

and decodes into a heap buffer that `parseURLEncodedVars` mutates and the
caller then `free()`s. `parseURLEncodedVars` copies into UTF-16 ActionVar
storage (action.c:33284), so nothing outlives the free.

**No other loader was touched.** `LoadVars.load` (action.c:38040, incl. its
BOM strip), `XML.load` (19489) and the stylesheet loader stay unconditionally
UTF-8, matching Ruffle (loader.rs:1098).

### The brief's three named risks

1. **Wrong version global** — used `g_main_movie_swf_version` (action.c:590,
   written once by `main.c`), *not* `g_swf_version` (rewritten per call frame
   at 14968/15223/23549/23690). Called out in a code comment at the site so it
   does not get "simplified" later.
2. **Buffer growth** — the 4097-byte stack buffer is gone. Decode allocates
   `len*3 + 1` (cp1252 and unmapped/halfwidth SJIS bytes are all 3-byte
   scalars, so 3x is the true worst case).
3. **Verbatim v6 path** — `LEGACY_CS_UTF8` is a straight `memcpy` + NUL, never
   validated or re-encoded, so `form_loader_encoding_1` (pass) and `_4`
   (`ruffle_matched`) ride byte-identical bytes. Confirmed by canary.

Risk 4 from the brief (detector over-firing on accented Latin, because
cp1252's 0xE0..0xEF is also an SJIS lead range) is documented in a comment
above `looks_like_shift_jis`, as the brief asked.

---

## 2. Per-test ledger

Baseline column = `results_graphics.json` at `1c7c23761`. Both targets were
re-verified locally at HEAD before any edit and reproduced the brief's diffs
byte for byte.

### Targets

| test | baseline | re-verified at HEAD | after |
|---|---|---|---|
| `avm1/form_loader_encoding_2` | output_mismatch | output_mismatch (3/3 lines wrong) | **pass** |
| `avm1/form_loader_encoding_3` | output_mismatch | output_mismatch (2/3 lines wrong) | **pass** |

### Canaries — 24/24 unchanged, zero moves

| test | suite | baseline | after |
|---|---|---|---|
| `form_loader_encoding_1` | avm1 | pass | pass |
| `form_loader_encoding_4` | avm1 | ruffle_matched | ruffle_matched |
| `loadvariables` | avm1 | pass | pass |
| `loadvariables2` | avm1 | pass | pass |
| `loadvariablesnum` | avm1 | pass | pass |
| `loadvariables_method` | avm1 | output_mismatch | output_mismatch |
| `globals_swf5` | avm1 | output_mismatch | output_mismatch |
| `swf5_encoding` | avm1 | pass | pass |
| `swf5_xml_event_handler_context` | avm1 | pass | pass |
| `globals_swf8` | avm1 | pass | pass |
| `native_objects_swf6` | avm1 | output_mismatch | output_mismatch |
| `native_objects_swf7` | avm1 | pass | pass |
| `native_objects_swf8` | avm1 | pass | pass |
| `loadvars_tostring` | avm1 | pass | pass |
| `global_instance_decls` | avm1 | output_mismatch | output_mismatch |
| `LoadVars-v5` | from_gnash | pass | pass |
| `MovieClip-v5` | from_gnash | ruffle_matched | ruffle_matched |
| `MovieClipLoader-v5` | from_gnash | pass | pass |
| `System-v5` | from_gnash | pass | pass |
| `System-v6` | from_gnash | pass | pass |
| `System-v7` | from_gnash | pass | pass |
| `System-v8` | from_gnash | pass | pass |
| `avm1/loadvariables/loadvariables` | from_shumway | pass | pass |
| `avm1/loadvariables/loadvars` | from_shumway | pass | pass |
| `lv_cross_swf_version` | regression | pass | pass |
| `lv_ondata_type1_args` | regression | pass | pass |

`form_loader_encoding_4` and `MovieClip-v5` are `ruffle_matched`, so a raw
local run reports them as mismatches against `output.txt` in **both** halves
of a stash-diff; both still report `RUFFLE_MATCHED`, i.e. their diff lines are
unchanged. That is the specific `ruffle-matched-trap` regression this route
could have caused, and it did not.

`LoadVars-v5` (gnash) is the strongest single canary: its `vars.txt` starts
with a UTF-8 BOM `EF BB BF`, which would surface as `ï»¿var1` the moment
`LoadVars.load` accidentally acquired the cp1252 branch. Still `pass`.
`lv_cross_swf_version` in the tracked regression suite exercises the v5/v6
boundary directly and is also unchanged.

Two local-only infrastructure artifacts, both resolved, neither
patch-related:

- `System-v6/v7/v8` first reported `compile_fail`
  (`tagMain.c:17: too few arguments to function 'tagPlaceObject2'`). That is
  the stale-`RecompiledTags` signature mismatch between the copied-in test
  dirs and the copied-in recompiler build; `--recompile` clears it and all
  three pass. Not a compile timeout — raising `SWFRECOMP_COMPILE_TIMEOUT`
  alone did not change it.
- `global_instance_decls` first reported `recomp_fail`
  (`SWF file 'test.swf' not found`) because `*.swf` is gitignored and absent
  from a fresh worktree. After copying the fixture in it reports
  `output_mismatch`, matching baseline.

---

## 3. Predicted CI delta

**+2** (`avm1/form_loader_encoding_2`, `avm1/form_loader_encoding_3`,
output_mismatch → pass). Corpus 4153 → 4155 / 4424.

No further upside: `form_loader_encoding_4` needs Flash's undocumented
invalid-UTF-8 recovery (Ruffle does not do it either), and per the brief's
exhaustive scan the changed branches are reachable by exactly two tests in the
whole corpus — `useCodepage` is mentioned by 5 tests (the target plus the four
gnash `System-v*`, which never form-load) and only one v5 test besides the
target does a form load with a payload.

Suggested CI dispatch: `mode=graphics`, `categories=all`, `images=false`
(runtime-only AVM1 change; no AVM2 emission touched).

---

## 4. Deviations from the brief

1. **Table provenance wording.** The brief called the table "WHATWG `index
   jis0208`". It is generated from CPython's `cp932`, which is the family
   WHATWG's index derives from — same Windows readings for the six contested
   punctuation points (0x8160 → U+FF5E, not U+301C), same NEC/IBM rows, and
   cp932's 0xF040.. PUA block lands on exactly the `U+E000 + (ptr - 8836)`
   values WHATWG computes algorithmically. They can still differ on a few
   cp932 duplicate IBM mappings, none corpus-reachable. The generator
   docstring and the emitted comment say cp932/Windows-31J rather than
   claiming byte-exactness with index-jis0208.
2. **`legacy_charset_to_utf8` takes `int* out_len`** as the brief specified,
   but the call site passes `NULL` — `parseURLEncodedVars` is
   NUL-terminated-string based. Kept in the signature because it costs
   nothing and a future binary-safe caller will want it.
3. **Extra canaries.** Beyond the brief's list I content-grepped
   `loadVariables|LoadVars` across the avm1 suite and added the six other
   hits (`globals_swf8`, `native_objects_swf{6,7,8}`, `loadvars_tostring`,
   `global_instance_decls`).
4. **Worktree test fixtures.** Upstream test dirs are gitignored/downloaded
   and absent from a fresh worktree; the canary dirs were copied in from the
   main tree. They are untracked and are not in the patch.
5. **Regression suite.** Ran only the two LoadVars-related tests
   (`lv_cross_swf_version`, `lv_ondata_type1_args`) rather than all 72, per
   the coordinator's instruction that the cross-patch sweep is theirs. A
   content grep of the suite for `loadVariables|LoadVars|useCodepage` finds
   no other hits.

## 4b. Note for the merging coordinator

Local runs used `SWFRECOMP_COMPILE_TIMEOUT=2400`; the default 300s is not
enough for `action.c` at `-O2` on a machine at load 20+. If a merged sweep
shows scattered `compile_fail`, check that before suspecting a patch.

---

## 5. Suggested commit message

```
avm1: decode legacy charsets in the loadVariables form loader

loadVariables/loadVariablesNum handed their payload straight to the
urlencoded parser as if it were UTF-8. Ruffle's load_form_into_object
(core/src/loader.rs:1004-1022) picks an encoding first:

  System.useCodepage      -> sniff the bytes (chardetng)
  else root SWF <= 5      -> windows-1252
  else                    -> verbatim

Add real decoders in utils.c/utils.h (already in every build, so no build
files change): a 32-entry windows-1252 specials table, a generated 11280-entry
Shift-JIS table with a new scripts/generate_shift_jis_table.py, a strict UTF-8
validator (the runtime's own decoder is deliberately lenient and would accept
Latin-1), and a detector that only calls Shift-JIS when the whole stream
decodes and holds at least one real double-byte pair.

Wire it into actionGetURL2's loadVariables branch only. LoadVars.load,
XML.load and the stylesheet loader stay UTF-8, matching Ruffle. The version
test uses g_main_movie_swf_version, not the per-call-frame g_swf_version, and
the decode buffer moves to the heap since decoding can triple the length.

Fixes avm1/form_loader_encoding_2 and _3.
```
