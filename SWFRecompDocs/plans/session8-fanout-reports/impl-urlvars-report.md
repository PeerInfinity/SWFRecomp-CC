# Wave-2 — `flash.utils.escapeMultiByte`/`unescapeMultiByte` + `flash.net.URLVariables(str)`/`decode()`

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a278ee4498f6c0f80`
Base: `1c7c23761`. Runtime-only change (no recompiler rebuild needed).
Patch: `.../scratchpad/wave2/urlvars.patch` (3 files, +272 / -23).

## Result

| Test | Before | After |
|---|---|---|
| `avm2/escape_multi_byte` | `output_mismatch` 1/45 (`ReferenceError #1065: Variable escapeMultiByte is not defined`) | **`pass` 45/45** |
| `avm2/url_vars` | `output_mismatch` 3/27 (`TypeError #1006: decode is not a function`) | **`pass` 27/27** |

**Predicted CI delta: +2 unfiltered / +1 filtered** (avm2 suite,
`mode=graphics`, `categories=all`).

> ⚠️ **`url_vars` is in `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`**
> (line 121, in the seeded `url_loader` / `url_vars` / `urlrequest` /
> `urlstream_basic` bucket from 2026-07-10, written "before any AVM2
> implementation exists"). So it counts in the unfiltered numbers
> (`results_graphics.json`: avm2 `pass` 1068 → **1070**) but not the filtered
> ones (`results_graphics_filtered.json`: 893 → **894**, `url_vars` ABSENT).
> `escape_multi_byte` is not ignored and counts in both.
>
> That bucket is stale — `url_loader` and `urlrequest` are both **already
> passing** while still listed. Pruning it is a coordinator call, not something
> I changed; if `url_vars` is dropped from the list the filtered delta becomes
> +2 as well.

---

## What changed

### 1. `SWFModernRuntime/src/avm2/avm2_globals.c`

**New shared block after `global_unescape` (~150 lines):**

| Symbol | Role |
|---|---|
| `mb_utf8_next` | Flash's *lenient* UTF-8 decode, a port of `ruffle_wstr` `utils.rs::DecodeAvmUtf8`. Malformed/truncated → the **lead byte as a Latin-1 code point**, consuming exactly 1 byte; surrogate-range sequences are kept as-is; a 4-byte lead reads only 3 continuation bytes. |
| `mb_append_cp` | Appends a code point in **canonical WTF-8**, folding a high+low surrogate pair back into the single 4-byte astral form (Ruffle accumulates UTF-16 units, where that pair simply *is* one character). Same rule as `avm_utf8_lenient` in `avm2_bytearray.c`. |
| `mb_escape` | `escapeMultiByte`. `to_utf8_lossy` first (**an unpaired surrogate becomes U+FFFD**), then every byte that is not `[0-9A-Za-z]` becomes `%XX`, stopping at the first NUL. |
| `mb_percent_pair` | One `%XX` body; **consumes what it looked at even when it fails**, mirroring Ruffle's `handle_percent` driving the same char iterator. |
| `mb_unescape` | `unescapeMultiByte`. Literals pass through (stop at NUL); a **run** of consecutive `%XX` escapes is collected into ONE byte group and then decoded with `mb_utf8_next`. |
| `global_escape_multi_byte` / `global_unescape_multi_byte` | The two natives; both use the existing `uri_arg_string` argument rule. |

**Deleted** the private `urlvars_escape` helper; its two call sites in
`urlvars_to_string` now call `mb_escape`. Behaviour is identical except that
`mb_escape` adds the lossy-surrogate step, which is what `escape_multi_byte`
line 6 grades.

**New URLVariables surface (~90 lines):** `urlvars_decode_string`,
`urlvars_ctor`, `urlvars_decode`, plus a cached `g_urlvariables_class` and the
accessor `avm2_url_variables_class()`.

`register_net` now sets `instance_init` on the class and registers
`decode` (arity 1) alongside the existing `toString`.

`avm2_register_toplevel` registers `flash.utils::escapeMultiByte` and
`flash.utils::unescapeMultiByte` via the existing `builtin_add_global_fn_ns`.

### 2. `SWFModernRuntime/include/avm2/avm2_globals.h` (+3)

Declares `Avm2Class* avm2_url_variables_class(void);` next to the two
`avm2_display_wire_url_*` prototypes.

### 3. `SWFModernRuntime/src/avm2/avm2_display.c` (+13 / −3)

`ul_set_data`: `dataFormat="variables"` now constructs a `URLVariables` off the
(BOM-stripped) body string, matching Ruffle's `set_data`
(`classes().urlvariables.construct(&[strip_bom(body)])`). This closes cause 4
from the wave-1 brief §A. The edit is **appended after** the existing final
`ext->data = ...` statement precisely so the sibling BOM agent's rewrite of the
lines above it merges cleanly — see "Merge note" below.

---

## Semantics pinned (and where each came from)

Oracle: `~/CC/ruffle/core/src/avm2/globals/flash/utils.rs` (`escape_multi_byte`,
`unescape_multi_byte`, `handle_percent`),
`~/CC/ruffle/core/src/avm2/globals/flash/net/URLVariables.as`,
`~/CC/ruffle/wstr/src/utils.rs` (`DecodeAvmUtf8`) and `wstr/src/buf.rs`
(`push_utf8_bytes`).

**escapeMultiByte**
* Unreserved set is `[0-9A-Za-z]` **only** — `_`, `-`, `.` are escaped, unlike
  `escape()`. Pinned by the `0x01–0x7f` line (`%5F`, `%2D`, `%2E` all present).
* Stops at the first NUL byte (`P\0P` → `P`).
* Lossy: `String(<ED B0 80>)` is a lone surrogate in our WTF-8, and
  `escapeMultiByte` of it is `%EF%BF%BD`, not `%ED%B0%80`.

**unescapeMultiByte** — the eight degenerate cases in the test are all explained
by "handle_percent consumes what it read":

| input | output | why |
|---|---|---|
| `%` / `%A` / `%AG` / `%%` / `%A%` | *(empty)* | the whole malformed escape is swallowed |
| `%GA` | `A` | the first char after `%` is not hex, so only `%G` is swallowed |
| `%G%` | *(empty)* | `%G` swallowed, then a trailing lone `%` |

* Grouping is load-bearing: `%F0%9F%91%BE` is **one** astral char
  (`escape` → `%uD83D%uDC7E`), `%ED%B0%80` is a **lone surrogate**
  (`%uDC00`), and `%F0%9F%91` is **three Latin-1 chars** (`%F0%9F%91`).
* Stops at a literal NUL, but a NUL **after** a `%` is just a bad hex digit —
  `%\0H` → `H`.

**URLVariables.decode** — three details straight from the AS source:
1. `splitIndex` is taken **before** the `+` substitution;
2. `pair.AS3::replace("+", " ")` with a *string* pattern replaces only the
   **first** occurrence, in the whole pair — so a `+` in the name consumes the
   substitution and a later one in the value survives literally;
3. accumulation is `null`/`undefined` (loose `==`) → overwrite, existing Array →
   push, anything else (including `""`) → two-element Array.

`URLVariables(str)` guards with `if (str)`, so a missing / null / **empty**
argument leaves the bag empty rather than decoding `""` (which would be a
`#2101`, since `"".split("&")` is `[""]`).

`#2101` is thrown as a plain `Error` with the message already in
`avm2_error.c:803`. It is **not** exercised by either test.

### Enumeration order is not a blocker here
`url_vars` sorts every multi-key `toString` (`.split("&").sort()`, with a source
comment naming Ruffle's own hash-order problem), so the insertion-order
divergence documented for `loader_load` never bites. Verified: every unsorted
`trace(variables)` in the test has exactly one key.

### Verification method
Beyond the two end-to-end runs, the three algorithms were transcribed verbatim
into a standalone harness
(`.../scratchpad/wave2/sim.c`, `gcc -o sim sim.c && ./sim`) and checked against
**30 expectations** read line-by-line off `escape_multi_byte/output.txt` and
`url_vars/output.txt` — including the ByteArray-sourced cases, which are routed
through a copy of `avm_utf8_lenient`. `ALL OK (0 failures)` before the first
real build.

---

## Canaries (all run locally at `-P 2`, `--tests-dir=…/avm2`)

**12 / 12 canaries: zero status changes.**

| Test | Baseline (`results_graphics.json`) | With patch | Verdict |
|---|---|---|---|
| `bom` | `output_mismatch` | `MISMATCH` (still 4/9) | unchanged — see below |
| `loader_load` | `output_mismatch` | `MISMATCH` | unchanged — the same 2 lines, both pure enumeration order (`cccc=true&aaa=bbb` vs `aaa=bbb&cccc=true`) |
| `escape` | pass | `PASS` | ok |
| `unescape` | pass | `PASS` | ok |
| `decode_uri` | pass | `PASS` | ok |
| `bytearray_tostring` | pass | `PASS` | ok |
| `bytearray_utf16` | pass | `PASS` | ok |
| `net_navigateToURL` | pass | `PASS` | ok (the other URLVariables consumer) |
| `loader_method` | pass | `PASS` | ok |
| `url_loader` | pass | `PASS` | ok |
| `error_geterrormessage` | pass | `PASS` | ok (prints the `#2101` message table) |
| `get_definition_by_name` | pass | `PASS` | ok (two new domain entries are invisible) |

Selection rationale: the two must-not-worsen mismatches named in the brief, the
four global-escaping / lenient-UTF-8 neighbours of the new code (`escape`,
`unescape`, `decode_uri`, plus the two `bytearray_*` decoders that share the
CESU-8 folding rule), and every remaining test that content-greps
`URLVariables` / `dataFormat`.

### `avm2/bom` detail (must-not-worsen, and it doesn't)
Still `output_mismatch`, still **4/9** matching (lines 1–4). Lines 7/8/9 were
already mismatched before this patch:
* line 7 is unchanged (`lastName=Jones&firstName=Tom`) — the permanent
  enumeration-order cause 3;
* lines 8/9 change from raw UTF-16 garbage
  (`��lastName=Jo"nes&firstName=Tom`) to the URLVariables round-trip of that
  same garbage (`%EF%BF%BD%EF%BF%BDl=&=`). They become correct-modulo-order
  once the sibling agent's UTF-16 `strip_bom` lands.

No `#2101` is thrown on that garbage (both halves of both pairs contain `=`), so
there is no new fatal path.

---

## Blast-radius audit

* Content-grep of the whole corpus: `escapeMultiByte` appears in **exactly one**
  test (`avm2/escape_multi_byte`) — no passing test asserts the name is absent
  (the `air_hidden_lookup` check).
* `URLVariables` appears in 5 `.as` files (`url_vars`, `loader_load`,
  `loader_method`, `net_navigateToURL`, `url_loader`) and in one `output.txt`
  (`error_geterrormessage`, which only prints the `#2101` message table).
* `dataFormat="variables"` is used by **exactly one** test, `avm2/bom`. Every
  other `dataFormat` user sets `"binary"`.
* `getQualifiedDefinitionNames` tests list script-defined names only, so the two
  new domain entries are invisible to them.

## Merge note for the coordinator

`avm2_display.c` `ul_set_data` is also being edited by the wave-2 BOM agent
(lifting a shared `avm2_strip_bom` out of `avm2_bytearray.c`). My hunk is
deliberately **appended after** the final `ext->data = …;` and only reads
`ext->data`, so the resolution is: keep their replacement of the BOM-strip +
string construction, then keep my `if (ul_format_is(ext, "variables")) { … }`
block immediately after it. Nothing else in that function is touched.

No other file overlaps: my `avm2_globals.c` edits are in the URI-escaping block,
the flash.net block, and `avm2_register_toplevel`.

## Deviations from the brief

* The brief estimated ~120 lines; the real patch is ~250 added lines in
  `avm2_globals.c`. The extra is the lenient-UTF-8 decoder + WTF-8 append
  helper, which the brief's "`urlvars_escape` already implements the exact
  escapeMultiByte rule" assumption did not account for — `urlvars_escape` was
  missing the `to_utf8_lossy` step, and `unescapeMultiByte` needs a full
  Flash-lenient decoder for its `%XX`-run grouping.
* I did **not** duplicate `avm_utf8_lenient` out of `avm2_bytearray.c` by
  exporting it, deliberately: the sibling BOM agent is restructuring that file's
  neighbourhood, and a shared-symbol edit there would collide. If the two
  patches land together, folding `mb_utf8_next` + `mb_append_cp` and
  `avm_utf8_lenient` into one helper is a clean follow-up (0 behaviour change).

## Suggested commit message

```
avm2: escapeMultiByte/unescapeMultiByte + URLVariables(str)/decode()

flash.utils.escapeMultiByte and unescapeMultiByte were never registered,
and flash.net.URLVariables had only toString — no source-string ctor and
no decode(). That alone accounted for two failing tests: escape_multi_byte
died on ReferenceError #1065 at its first line, url_vars on
TypeError #1006 "decode is not a function" at line 4 of 27.

Port the pair from Ruffle (core/src/avm2/globals/flash/utils.rs). They are
not escape/unescape: the unreserved set is [0-9A-Za-z] only, they work on
UTF-8 BYTES, and both stop at the first NUL. Two subtleties are graded:
escapeMultiByte runs to_utf8_lossy first, so an unpaired surrogate escapes
as %EF%BF%BD; and unescapeMultiByte collects a RUN of consecutive %XX into
one byte group before decoding it with Flash's lenient UTF-8 rules
(ruffle_wstr DecodeAvmUtf8), which is why %F0%9F%91%BE is one astral
character while %F0%9F%91 is three Latin-1 ones. Its malformed-escape
behaviour ("%GA" -> "A" but "%AG" -> "") falls out of handle_percent
consuming what it read.

URLVariables gains the ctor and decode() from URLVariables.as, including
the three load-bearing details: the split index is taken before the "+"
substitution, String.replace with a string pattern replaces only the FIRST
occurrence in the whole pair, and a repeated name accumulates into an Array.
The private urlvars_escape helper is gone, folded into the shared mb_escape.

Finally, URLLoader's dataFormat="variables" now constructs a URLVariables
off the response body instead of leaving it a plain string, matching
Ruffle's set_data. avm2/bom is the only test that exercises that path; it
stays output_mismatch at 4/9 (its remaining diff is Ruffle's hash-order
property enumeration, which is permanent).

avm2/escape_multi_byte 1/45 -> pass, avm2/url_vars 3/27 -> pass.
```
