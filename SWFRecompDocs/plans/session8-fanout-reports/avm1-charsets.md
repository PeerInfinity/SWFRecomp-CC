# B11 — AVM1 legacy charset decoding for `loadVariables` (form loader)

Diagnosis agent, session 8 polish sweep. Baseline HEAD `1c7c23761`, read-only.
Targets: `avm1/form_loader_encoding_2`, `avm1/form_loader_encoding_3`.

**Verdict: GO. +2, fully determined (no guessing — every graded byte is
accounted for below).**

---

## 1. Status at HEAD (re-run locally, sequential)

| test | SWF ver | baseline status | re-run at HEAD |
|---|---|---|---|
| `form_loader_encoding_1` | 6 | pass | (unchanged, not re-run) |
| `form_loader_encoding_2` | 5 | output_mismatch | **MISMATCH — 3/3 lines wrong** |
| `form_loader_encoding_3` | 6 | output_mismatch | **MISMATCH — 2/3 lines wrong (line 1 already correct)** |
| `form_loader_encoding_4` | 6 | ruffle_matched | (unchanged, not re-run) |

Full diffs:

```
--- form_loader_encoding_2 (expected vs actual) ---
-    1  UTF8: Ã„Ã–Ãœ ÃŸ - ç‰‡ä»®
+    1  UTF8: ÄÖÜ ß - 片仮
-    2  Iso Latin-1: ÄÖÜ ß
+    2  Iso Latin-1: Ėܠ�
-    3  Shift Jis: •Ð‰¼–¼
+    3  Shift Jis: Րɼּ

--- form_loader_encoding_3 (expected vs actual) ---
     1  UTF8: ÄÖÜ ß - 片仮名          (matches)
-    2  Iso Latin-1: ÄÖÜ ß
+    2  Iso Latin-1: Ėܠ�
-    3  Shift Jis: 片仮名
+    3  Shift Jis: Րɼּ
```

Note test 2's expected line 1 is *mojibake on purpose* — a UTF-8 file read
through windows-1252. Our "correct-looking" output is the bug there.

### Why `form_loader_encoding_1` passes

v6, no `useCodepage`, single UTF-8 payload. Ruffle's rule for that combination
is **pass the raw bytes through untouched** — which is exactly what we already
do. It passes by accident of the default path being right, not because any
charset logic exists.

### `form_loader_encoding_4` (known_failure → `ruffle_matched`)

v6, no `useCodepage`, deliberately invalid-UTF-8 payloads. `output.txt` is
*Flash's* weird recovery; `output.ruffle.txt` is Ruffle's U+FFFD soup.
`ruffle_matched` here means only "our diff **lines** ⊆ Ruffle's diff lines"
(verify_output.py:4095-4130) — it does **not** mean our bytes equal Ruffle's
(they don't: our lenient UTF-8 decoder produces `Ėܠ` where Ruffle produces
FFFDs). It stays `ruffle_matched` as long as lines 2 and 3 keep differing from
`output.txt`, which they will — this route does not touch the v6-no-codepage
path at all.

---

## 2. Exactly what is graded (byte level — all verified with Python)

Three fixtures, shared by tests 2/3/4 (test 2's `UTF8.txt` is truncated by 3
bytes: no 名).

| fixture | bytes after `key=` | |
|---|---|---|
| `UTF8.txt` | `55 54 46 38 3a 20 C3 84 C3 96 C3 9C 20 C3 9F 20 2D 20 E7 89 87 E4 BB AE [E5 90 8D]` | valid UTF-8 |
| `Iso.txt` | `49 73 6f … 3a 20 C4 D6 DC 20 DF` | ISO-8859-1 / cp1252 |
| `Shift Jis.txt` | `53 68 … 3a 20 95 D0 89 BC 96 BC` | Shift-JIS |

**Test 2 (v5) = pure windows-1252, verified byte-for-byte** against
`output.txt`'s UTF-8 bytes:

- `C3→Ã 84→„ C3→Ã 96→– C3→Ã 9C→œ 20 C3→Ã 9F→Ÿ … E7→ç 89→‰ 87→‡ E4→ä BB→» AE→®`
  reproduces expected line 1 exactly (all six 0x80–0x9F specials matter, so
  Latin-1 is **not** sufficient — it must be windows-1252).
- `C4 D6 DC 20 DF → ÄÖÜ ß` (line 2).
- `95 D0 89 BC 96 BC → •Ð‰¼–¼` (line 3).

**Test 3 (v6, `System.useCodepage = true`) = per-file detection:**

- `UTF8.txt` → UTF-8 (already correct today).
- `Iso.txt` → windows-1252 → `ÄÖÜ ß`.
- `Shift Jis.txt` → Shift-JIS: `95D0=U+7247 片`, `89BC=U+4EEE 仮`,
  `96BC=U+540D 名`. **Only three double-byte code points are graded in the
  entire corpus.**

---

## 3. Ruffle oracle (`~/CC/ruffle/core/src/loader.rs:1004-1022`)

`load_form_into_object` — i.e. `loadVariables` / `loadVariablesNum` /
`MovieClip.loadVariables`, and **only** those:

```rust
let utf8_body = if activation.context.system.use_codepage {
    let encoding = response.text_encoding()            // HTTP charset (n/a for us)
        .unwrap_or_else(|| { let mut d = EncodingDetector::new();
                             d.feed(&body, true); d.guess(None, true) });   // chardetng
    utf8_string = encoding.decode(&body).0; utf8_string.as_bytes()
} else if activation.context.root_swf.version() <= 5 {
    utf8_string = WINDOWS_1252.decode(&body).0; utf8_string.as_bytes()
} else {
    &body                                               // verbatim; lossy UTF-8 later
};
for (k, v) in form_urlencoded::parse(utf8_body) { … }
```

Three things to carry over exactly:

1. **`useCodepage` wins over the version rule** (checked first).
2. The version is the **root** SWF's, not the calling clip's.
3. Decode happens **before** urlencoded parsing.

`chardetng` is a scoring detector; we only have to reproduce its verdict on
these three payloads (see §4.2).

Deliberately **not** codepage-aware in Ruffle, so leave alone:
- `load_form_into_load_vars` (`LoadVars.load`) — always `UTF_8.decode`
  (loader.rs:1098). Our impl at `action.c:38040-38105` already matches
  (and already strips the UTF-8 BOM).
- `load_stylesheet`, `load_xml_into_node` — always UTF-8.

---

## 4. Our side — where the fix goes

### 4.1 Ingestion path (one site)

`SWFModernRuntime/src/actionmodern/action.c:47513-47526`, inside
`actionGetURL2`'s `load_variables_flag` branch:

```c
DataFileEntry* data = findDataFile(url_utf8);
if (data != NULL && data->content != NULL && data->content_length > 0) {
    int _lv_len = data->content_length;
    if (_lv_len > 4096) _lv_len = 4096;
    char _lv_buf[4097];
    memcpy(_lv_buf, data->content, _lv_len);
    _lv_buf[_lv_len] = '\0';
    parseURLEncodedVars(app_context, _lv_buf, _lv_mc);   // ← bytes are handed
}                                                        //   over as if UTF-8
```

`parseURLEncodedVars` (action.c:33235) splits on `&`/`=`, `urlDecode`s, then
calls `utf8_to_u16(...)`. Our UTF-8 decoder (`action.c:171-191`) is *lenient*:
it never validates continuation bytes, so `C4 D6` becomes U+0116 and a
truncated lead byte becomes U+FFFD — that is the current mojibake, exactly
reproduced by hand above.

**This is the only reachable form-load site.** `MovieClip.loadVariables` is
registered as a *stub* (`action.c:15541`, `function_type = 1`, no
implementation anywhere in the tree) — which is why `avm1/loadvariables_method`
is `output_mismatch`. That is a separate (larger) bucket; do not touch it here.

### 4.2 Inputs available in C

| need | available as |
|---|---|
| root SWF version | `g_main_movie_swf_version` (`action.c:590`, set once from `SWF_VERSION` in `SWFRecomp/wasm_wrappers/main.c:96`, never mutated — unlike `g_swf_version`, which the call machinery rewrites per function; **must use the `main_movie` one**) |
| `System.useCodepage` | `g_system_object` is a file-static in the same TU (`action.c:4801`); the property is a plain writable boolean created at `action.c:38515`. Read with `getProperty(g_system_object, "useCodepage", 11)` → `ActionVar*`, coerce. |

### 4.3 Chosen route

**Route B — real decoders, no new build plumbing.**

Put the tables + decode entry points in **`SWFModernRuntime/src/utils.c`** and
declare them in **`SWFModernRuntime/include/utils.h`**. Both are already in
every build (`verify_output.py` `core_sources`, CMake, all 7 build scripts) —
so this costs **zero** build-file edits. A new `.h` next to
`unicode_case_tables.h` would instead force edits in 7 places
(`verify_output.py` ×2, `build_test.sh`, `build_graphics_host.sh`,
`build_wasm_test.sh`, `build_wasm_avm2.sh`, `deploy_wasm_demo.sh`,
`profile_game_native.sh`) — avoid that.

`include/utils.h`:

```c
typedef enum { LEGACY_CS_UTF8 = 0, LEGACY_CS_WINDOWS_1252, LEGACY_CS_SHIFT_JIS } LegacyCharset;
LegacyCharset legacy_charset_detect(const unsigned char* body, int len);
/* malloc'd, NUL-terminated UTF-8; caller frees. UTF8 → verbatim copy. */
char* legacy_charset_to_utf8(const unsigned char* body, int len,
                             LegacyCharset cs, int* out_len);
```

**windows-1252** — 32-entry table, everything else identity:

```c
static const uint16_t cp1252_80_9f[32] = {
 0x20AC,0x0081,0x201A,0x0192,0x201E,0x2026,0x2020,0x2021,
 0x02C6,0x2030,0x0160,0x2039,0x0152,0x008D,0x017D,0x008F,
 0x0090,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,
 0x02DC,0x2122,0x0161,0x203A,0x0153,0x009D,0x017E,0x0178 };
/* b < 0x80 → b;  0x80..0x9F → table;  else → b (Latin-1 identity) */
```

**Shift-JIS** — WHATWG `index jis0208`, generated:
`ptr = (lead - (lead < 0xA0 ? 0x81 : 0xC1)) * 188 + (trail - (trail < 0x7F ? 0x40 : 0x41))`,
then `sjis_index[ptr]` (0 = unmapped → U+FFFD). Table is
`static const uint16_t sjis_index[11280]` = **22.5 KB binary, ~79 KB of C
source**, emitted between `/* BEGIN GENERATED */ … /* END GENERATED */`
markers by a new `scripts/generate_shift_jis_table.py` (precedent:
`scripts/generate_case_tables.py`). Python one-liner source of truth:
`bytes([lead,trail]).decode('cp932')` over `lead ∈ 0x81..0x9F ∪ 0xE0..0xFC`,
`trail ∈ 0x40..0xFC \ {0x7F}` — 9,604 real mappings; all three graded
code points confirmed (`95d0→U+7247`, `89bc→U+4EEE`, `96bc→U+540D`).
Single bytes are algorithmic: `< 0x80` → identity, `0x80` → U+0080,
`0xA1..0xDF` → `U+FF61 + (b - 0xA1)` (halfwidth katakana), `0xA0/0xFD..0xFF`
→ U+FFFD.

**Detector** (stands in for chardetng; only has to be right on these payloads):

```c
LegacyCharset legacy_charset_detect(const unsigned char* p, int n) {
    if (is_strict_utf8(p, n))         return LEGACY_CS_UTF8;
    if (looks_like_shift_jis(p, n))   return LEGACY_CS_SHIFT_JIS;
    return LEGACY_CS_WINDOWS_1252;
}
```
`looks_like_shift_jis` = single left-to-right scan; `< 0x80` ok, `0xA1..0xDF`
ok (single kana), a lead in `0x81..0x9F ∪ 0xE0..0xFC` must be followed by a
trail in `0x40..0x7E ∪ 0x80..0xFC` that maps to a non-zero index entry
(counter++), anything else ⇒ return 0. Verdict = `counter > 0` (i.e. **at
least one real double-byte sequence**, otherwise it is indistinguishable from
Latin-1 text and cp1252 must win).

Traced against the fixtures:
- `UTF8.txt` → strict-UTF-8 valid → UTF-8 ✓
- `Iso.txt` (`C4 D6 DC 20 DF`) → not UTF-8; every high byte is in 0xA1..0xDF
  (single kana), **zero** double-byte pairs → counter 0 → cp1252 ✓
- `Shift Jis.txt` (`95 D0 89 BC 96 BC`) → not UTF-8; three valid lead/trail
  pairs → SJIS ✓

Note `is_strict_utf8` must be a *new strict* validator — the existing
`utf8_decode_one` is deliberately lenient and would accept `C4 D6`.

### 4.4 Call-site patch sketch (action.c:47513)

```c
DataFileEntry* data = findDataFile(url_utf8);
if (data != NULL && data->content != NULL && data->content_length > 0) {
    int raw_len = data->content_length;
    if (raw_len > 4096) raw_len = 4096;

    LegacyCharset cs;
    if (avm1_system_use_codepage())            cs = legacy_charset_detect(
                                                       (const unsigned char*)data->content, raw_len);
    else if (g_main_movie_swf_version <= 5)    cs = LEGACY_CS_WINDOWS_1252;
    else                                       cs = LEGACY_CS_UTF8;   /* verbatim */

    int dec_len = 0;
    char* decoded = legacy_charset_to_utf8((const unsigned char*)data->content,
                                           raw_len, cs, &dec_len);
    if (decoded != NULL) {
        parseURLEncodedVars(app_context, decoded, _lv_mc);   /* mutates in place */
        free(decoded);
    }
}
```

`legacy_charset_to_utf8` must **heap**-allocate (cp1252→UTF-8 is up to 3×,
SJIS→UTF-8 up to 1.5×; the current 4097-byte stack buffer would overflow).
`LEGACY_CS_UTF8` must be a *verbatim* `memcpy` — do **not** round-trip it
through a validator/re-encoder, or test 1's pass and test 4's `ruffle_matched`
could move.

`avm1_system_use_codepage()` (file-static in action.c, next to the other
`g_system_object` helpers):

```c
static int avm1_system_use_codepage(void) {
    if (g_system_object == NULL) return 0;
    ActionVar* v = getProperty(g_system_object, "useCodepage", 11);
    if (v == NULL) return 0;
    switch (v->type) {
      case ACTION_STACK_VALUE_BOOLEAN: return v->data.numeric_value != 0;
      case ACTION_STACK_VALUE_F32:     return VAL(float,  &v->data.numeric_value) != 0.0f;
      case ACTION_STACK_VALUE_F64:     return VAL(double, &v->data.numeric_value) != 0.0;
      case ACTION_STACK_VALUE_STRING:  return v->str_size != 0;
      case ACTION_STACK_VALUE_NULL:
      case ACTION_STACK_VALUE_UNDEFINED: return 0;
      default: return 1;
    }
}
```

Timing is fine: our `loadVariablesNum` load is synchronous inside
`actionGetURL2`, and test 3 sets `System.useCodepage = true` on the line
before the three loads.

### Fallback (only if the reviewer balks at 79 KB of generated table)

**Route A**: identical windows-1252 work, but replace `sjis_index` with a
3-entry lookup (`0x95D0→0x7247, 0x89BC→0x4EEE, 0x96BC→0x540D`, else U+FFFD).
Same +2, ~1/4 the diff — but it is a decoder-shaped lie that will silently
mangle any real Japanese content, and the full table is machine-generated
anyway. Recommend against.

---

## 5. Predicted yield

**+2** (`form_loader_encoding_2`, `form_loader_encoding_3`), both
output_mismatch → pass. Every graded byte is derived above; there is no
residual uncertainty in either test.

No credible upside beyond +2 — `form_loader_encoding_4` needs Flash's
undocumented invalid-UTF-8 recovery (a genuinely different, unsolved thing;
Ruffle doesn't do it either, hence `known_failure`), and nothing else in the
corpus reaches the changed branches (§6).

---

## 6. Blast radius

The patch changes behaviour **only** when
`useCodepage == true` **or** `root SWF version <= 5`, **and** the action is
`GetURL2`-with-loadVariables **and** `findDataFile` hits. Exhaustive corpus
scan (all 24 suites, every `test.swf` header byte 3 + every sibling fixture):

**Population A — tests mentioning `useCodepage` anywhere (SWF or .as):** 5.
- `avm1/form_loader_encoding_3` — the target.
- `from_gnash/actionscript.all/System-v5 / -v6 / -v7 / -v8` — all **pass**;
  they only read/write the property (no data files, no form loads). Unaffected.

**Population B — SWF version ≤ 5 with a form load and a payload:** 1.
- `avm1/form_loader_encoding_2` — the target.

Everything else that *looked* like a neighbour, and why it can't move:

| test | suite | status | why safe |
|---|---|---|---|
| `LoadVars-v5` | from_gnash | pass | `LoadVars.load` path (`action.c:38040`), not the form loader; Ruffle keeps it UTF-8 too. Its `vars.txt` **starts with a UTF-8 BOM `EF BB BF`** — would become `ï»¿var1` under cp1252, so it *must* stay off this path. |
| `MovieClip-v5` | from_gnash | ruffle_matched | uses `mc.loadVariables("vars.txt")`, but our `MovieClip.loadVariables` is a **stub** — never reaches `findDataFile`. Same BOM'd `vars.txt`. Also: the graded lines only assert `typeof(_root.var1) == 'undefined'`, never enumerate mc's vars. |
| `MovieClipLoader-v5` | from_gnash | pass | MCL content-load path. |
| `globals_swf5` | avm1 | output_mismatch | v5 + loadVariables but **no data file** → `findDataFile` returns NULL. |
| `swf5_encoding` | avm1 | pass | v5, no form load at all. |
| `swf5_xml_event_handler_context` | avm1 | pass | `XML.load` path (`action.c:19489`) — untouched. |
| `loadvariables`, `loadvariables2`, `loadvariablesnum` | avm1 | pass | v8 + pure-ASCII fixtures → verbatim branch, byte-identical. |
| `from_shumway/avm1/loadvariables/{loadvariables,loadvars}` | from_shumway | pass | v8, ASCII. |
| `loadvariables_method` | avm1 | output_mismatch | stub method; unrelated bucket. |
| `form_loader_encoding_1`, `_4` | avm1 | pass / ruffle_matched | v6 + no codepage → verbatim branch, byte-identical. |

### Risks

1. **Wrong version global.** Using `g_swf_version` instead of
   `g_main_movie_swf_version` would silently reinterpret payloads whenever the
   call machinery has temporarily lowered the version (it does this constantly:
   `action.c:14968`, `15223`, `23549`, `23690`). Highest-consequence, easiest
   mistake in the change.
2. **Buffer growth.** Decoding expands; keeping the 4097-byte stack buffer is a
   stack smash on any payload with many high bytes.
3. **Touching the UTF-8 branch.** Re-encoding rather than `memcpy`-ing the v6
   verbatim path can move `form_loader_encoding_1` (pass) and `_4`
   (ruffle_matched, per the `ruffle-matched-trap` lesson a known_failure test
   sliding out of `ruffle_matched` is a real regression).
4. **Detector over-firing.** The `0xE0..0xEF` cp1252 accented-vowel range is
   also a SJIS lead range, so accented Latin text like `café ` could be
   mis-detected as SJIS. Zero corpus exposure (only one test reaches the
   detector), but worth a comment in the code; requiring the *whole* stream to
   be valid SJIS (as sketched) already suppresses most of it.
5. **BOM.** We do not strip a UTF-8 BOM on the form-loader path today, and
   Ruffle doesn't either — keep it that way (only `LoadVars.load` strips).

### Canary set for the local stash-diff sweep

```
avm1: form_loader_encoding_1 form_loader_encoding_2 form_loader_encoding_3
      form_loader_encoding_4 loadvariables loadvariables2 loadvariablesnum
      loadvariables_method globals_swf5 swf5_encoding
      swf5_xml_event_handler_context
from_gnash/actionscript.all: LoadVars-v5 MovieClip-v5 MovieClipLoader-v5
      System-v5 System-v6 System-v7 System-v8
from_shumway: avm1/loadvariables/loadvariables avm1/loadvariables/loadvars
regression: (whole suite, per project policy)
```

Compare against *stash-diff actual output*, not `results_graphics.json` —
`ruffle_matched` reads as a fail in a raw run (`MovieClip-v5`,
`form_loader_encoding_4` will both show as mismatches in both halves; what
matters is that they are unchanged).

---

## 7. File/line index

| what | where |
|---|---|
| form-load ingestion (the patch site) | `SWFModernRuntime/src/actionmodern/action.c:47513-47526` |
| `parseURLEncodedVars` / `urlDecode` | `SWFModernRuntime/src/actionmodern/action.c:33208-33272` |
| lenient UTF-8 decode (must not be reused for validation) | `SWFModernRuntime/src/actionmodern/action.c:155-218` |
| `g_main_movie_swf_version` / `g_swf_version` | `SWFModernRuntime/src/actionmodern/action.c:589-590`; set in `SWFRecomp/wasm_wrappers/main.c:94-97` |
| `g_system_object`, `useCodepage` property | `SWFModernRuntime/src/actionmodern/action.c:4801`, `38515-38519` |
| `LoadVars.load` (leave alone; BOM strip lives here) | `SWFModernRuntime/src/actionmodern/action.c:38040-38105` |
| `XML.load` (leave alone) | `SWFModernRuntime/src/actionmodern/action.c:19480-19520` |
| `MovieClip.loadVariables` stub registration | `SWFModernRuntime/src/actionmodern/action.c:15541` |
| new decoder home (already plumbed everywhere) | `SWFModernRuntime/src/utils.c`, `SWFModernRuntime/include/utils.h` |
| generator precedent | `/home/robert/CC/SWFRecomp-CC/scripts/generate_case_tables.py` |
| data-file embedding (raw bytes + length, byte-exact) | `ruffle-tests/verify_output.py:1800-1872` (`generate_data_registry`) |
| Ruffle oracle | `~/CC/ruffle/core/src/loader.rs:1004-1022` (form), `:1098` (LoadVars) |
| test dirs | `/home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/avm1/form_loader_encoding_{1,2,3,4}/` |
