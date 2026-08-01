# Session 8 · Wave 2 · Cluster C1 — "E4X: the three parts of a name"

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5ded442df06952b6`
Patch: `scratchpad/wave2/e4x-names.patch` (runtime only — no recompiler rebuild)
Files touched: `SWFModernRuntime/src/avm2/avm2_ops.c`, `SWFModernRuntime/src/avm2/avm2_xml.c`
(deliberately NOT `avm2_e4x.c` / `avm2_nsqname.c` — the sibling name-validity
agent owns those; its patch was read and is textually + semantically disjoint
from this one.)

---

## 1. What changed — five edits, four mechanisms

### E1. `avm2_ops.c:44 e4x_name_from_rtns` — an empty explicit URI is the NO-namespace, not "any"

```c
-	if (n != NULL && n->uri != NULL && n->uri->len > 0)
+	if (n != NULL && n->uri != NULL && n->kind != 0)
```

The old gate said "a runtime `Namespace` qualifies the name only if its URI is
non-empty", so `new Namespace()` / `new Namespace("")` fell through to the
`any_ns` / `avm2_e4x_name_from_string` arms — matching **everything** (or
re-qualifying onto the current default xml namespace) instead of matching only
unqualified nodes.

The right discriminator is the namespace **kind**, not the URI length: only
kind 0 is the ANY namespace (`avm2_nsqname.c namespace_construct` mints it for
`Namespace(new QName(null, x))`); every other kind is an explicit qualifier,
empty URI included. The matcher at `avm2_e4x.c:645` already reads
`if (self_uri == NULL) return name->single_uri->len == 0;`, so nothing
downstream needed touching.

Verified: pool namespace index 0 in emitted ABC tables is `{ kind 22, name 0 }`
(Package, empty URI), i.e. an ordinary public namespace — so the kind test does
not accidentally reclassify the constant-pool public namespace as "any".

### E2. `avm2_ops.c` set/delete rtns paths — pass the attribute flag and the any-name

`avm2_op_getproperty_rtns{,_l}` already derived two facts from the multiname and
handed them to `e4x_name_from_rtns`: `mn_is_attribute_kind(...)` and
`name == 0 ? NULL : <string>`. `setproperty_rtns_common` and
`deleteproperty_rtns_common` hard-coded `0` and always built a string, and
`avm2_op_{set,delete}property_rtns_l` did `(void) mn_idx;`.

Both commons now take `int attr, int any_name` and all four op entry points
supply them. This is the same shape as session 6 §8.4's *"the lazy-multiname
arms existed for four ops and were missing for five"*.

### E3. `avm2_xml.c n_xml_replace` — SWF ≤ 9 runs a non-XML value through the XML constructor

The triage predicted a wildcard-name rule here. It is not: `n_xml_replace`
already handles `'*'` correctly and already returns `x`. The real rule is the
avmplus `XMLObject.cpp:1540` version gate that Ruffle mirrors in `xml.rs`
(`if root_swf.version() <= 9 { XML(value) }`) — at SWF ≤ 9 the string
`"<phone>1234567</phone>"` PARSES into an element; from v10 it stays a text
node. That is precisely why only the `/v9` variant fails and `/v10` passes.

### E4. `avm2_xml.c maybe_escape_child` — the `>= 21` detach reads the CALLER's movie version

Ruffle's `e4x.rs maybe_escape_child` uses `root_swf.version()` for the `<= 9`
arm and **`caller_movie_or_root().version()`** for the `>= 21` arm. We read the
global `ctx->swf_version` (the root movie) for both. `avm2/xml_appendchild_swf_v21`
is a **v20 root** that Loader-loads a **v21 child**, so the detach rule never
fired for the child's line.

Added `xml_caller_swf_version(act)`, the same walk `avm2_text.c:7848
font_caller_movie` already uses (native's own `act->file` is NULL → nearest
debug-callstack frame with an ABC file → `avm2_display_movie_for_abc`), and
switched the `>= 21` test to it. The `<= 9` arm still reads the root, per Ruffle.

### E5. `avm2_xml.c` two small natives

* `n_xml_add_namespace`: `argc < 1` now throws `ArgumentError #1063
  "Argument count mismatch on XML/addNamespace(). Expected 1, got 0."`.
  avmplus declares one **required** parameter; `addNamespace(null)` and
  `addNamespace(undefined)` stay legal no-ops (both are argc 1).
* `avm2_xml_delete_name`, XMLList index branch: after
  `avm2_e4x_remove_{child,attribute}` the removed node's `parent` is nulled, so
  `delete list[i]` detaches (`parent() → undefined`, `childIndex() → -1`).
  The name-keyed delete paths already null it via `avm2_e4x_remove_matching` /
  `avm2_e4x_delete_by_index`; only the index path did not. Done at the call site
  in `avm2_xml.c` rather than inside `avm2_e4x.c`'s helpers to keep the patch
  off the sibling agent's file.

---

## 2. Per-member ledger

| # | test | suite | before | after | taken? |
|---|---|---|---|---|---|
| 1 | `e4x/Regress/regress-263935` | from_avmplus | output_mismatch (gap 2) | **PASS** | E1 |
| 2 | `e4x/Expressions/e11_1_2` | from_avmplus | output_mismatch (gap 3) | **PASS** | E2 |
| 3 | `avm2/xml_appendchild_swf_v21` | avm2 | output_mismatch (gap 1) | **PASS** | E4 |
| 4 | `e4x/XML/e13_4_4_32/v9` | from_avmplus | output_mismatch (gap 1) | **PASS** | E3 |
| 5 | `avm2/xml_list_delete_clear_parent` | avm2 | output_mismatch (gap 5) | **PASS** | E5b |
| 6 | `e4x/XML/e13_4_4_17` | from_avmplus | output_mismatch (gap 1) | **PASS** | E5a |
| 7 | `e4x/Statements/e12_1` | from_avmplus | output_mismatch (gap 4) | mismatch, **gap 4 → 3** | **SKIPPED** |

**Rider found outside the near-pass window:**

| test | suite | before | after |
|---|---|---|---|
| `e4x/XML/e13_4_4_2` | from_avmplus | output_mismatch, **gap 11** | **PASS** |

`e13_4_4_2` grades the exact `#1063` string for zero-arg `addNamespace()`; it was
never a candidate (gap 11 > 5) and was found by content-grepping
`addNamespace()` across the corpus before making the change. It is the session's
illustration of [[shared-mechanism-fixes-overshoot-estimates]] — but note the
overshoot here is exactly ONE test, consistent with the triage's §6 warning that
a name-keyed cluster prices tightly.

**Ledger: 6 of 7 members + 1 rider = +7.** (Triage predicted +4, stretch +6.)

### Why `e12_1` was skipped

The triage's three causes were confirmed by running it post-patch:

* **case 8** (`ns = new Namespace(""); x1.b.ns::c`) — **fixed** by E1, as predicted.
  This was the two-for-one.
* **case 4** — a method whose body contains a `default xml namespace` statement
  must start with DXNS `""`, not the caller's. The carrier is the ABC
  `SETS_DXNS` (0x40) method flag, which the runtime never sees: making it work
  means having **SWFRecomp emit a DXNS reset at the top of such methods**. That
  is a recompiler change (needs `cmake --build SWFRecomp/build`), out of scope
  for a runtime-only worktree and a merge hazard for the parallel agents.
* **cases 13/14** — single-argument `new QName("a")` must capture the default xml
  namespace of its construction site. Ruffle does **not** do this
  (`globals/q_name.rs q_name_constructor` uses `find_public_namespace()` for the
  1-arg form), so this is an avmplus-vs-Ruffle divergence needing its own oracle
  ruling, not a one-liner.

Two of three causes are real projects and the test needs all three, so it stays
on the board at gap 3.

---

## 3. Canaries

Confirmed green **after** the patch (each was `pass`/`ruffle_matched` at HEAD):

* the two tests the C1.1 code comment names as pinning the old behaviour —
  `e4x/Expressions/e11_1_1` (`y1.@ns::*`) and `avm2/xml_explicit_use_namespace`;
* `e4x/XML/e13_4_4_32/v10` — the sibling of the version-gated `replace` fix, the
  one that proves the `<= 9` gate and not a wildcard rule;
* `e4x/XML/e13_4_4_24` — the other corpus user of `addNamespace(null)`;
* the sessions 5–6 wildcard/attribute set (`e13_4_4_36`, `e13_4_4_28`,
  `e13_5_4_17`, `regress-524214`) plus ~17 more `from_avmplus/e4x/**` spanning
  attribute read/write/delete, `setNamespace`/`addNamespace`,
  `Namespace`/`QName` construction, and notification;
* 29 `avm2/xml_*` tests covering the rtns/rtname, attribute, delete, wildcard,
  namespace and appendChild/prependChild/insertChild paths.

(Sweep results are in `scratchpad/wave2/c1-avmplus.{log,json}` and
`c1-avm2.{log,json}`; see §5 for the outcome.)

Blast-radius greps done before coding:

* `grep -rn "addNamespace()"` over every suite's `.as` → exactly 3 files
  (`e13_4_4_17`, `e13_4_4_2`, and a **commented-out** line in `e13_4_4_24`);
* `grep -rli "e4x|namespace|XML"` over `ruffle-tests/tests/swfs/regression/*/README.md`
  → **no** hand-written test pins any E4X or namespace behaviour (the only
  `regression` Test.as mentioning XML is `avm2_gc_string_survives_collect`, which
  uses it as GC ballast).

---

## 4. Predicted CI delta

**+7** (`graphics`, `categories=full` — the change is AVM2 runtime, so `full` is
required to see the six `from_avmplus` rows at all):

* from_avmplus: `e4x/Regress/regress-263935`, `e4x/Expressions/e11_1_2`,
  `e4x/XML/e13_4_4_32/v9`, `e4x/XML/e13_4_4_17`, `e4x/XML/e13_4_4_2` → **+5**
* avm2: `xml_appendchild_swf_v21`, `xml_list_delete_clear_parent` → **+2**

Also improved but not flipped: `from_avmplus/e4x/Statements/e12_1`, gap 4 → 3.

Risk notes for the merge:

* E1 changes the *classification* of an empty-URI runtime namespace corpus-wide.
  The only way to reach it is an RTQName (`expr::name`) whose namespace object
  has an empty URI and a non-zero kind — i.e. literally `new Namespace()` /
  `new Namespace("")`. Static `*::name` and `public::name` go through
  `avm2_e4x_name_from_mn`, which is untouched.
* E4 changes which movie's version the `>= 21` detach reads. For a single-movie
  program `avm2_display_movie_for_abc` returns NULL and the function falls back
  to `ctx->swf_version`, so behaviour is byte-identical unless a child SWF is
  loaded.
* E5a is the one edit that can make previously-silent code **throw**. The
  content-grep bounds it to two graded call sites, both of which want the throw.

---

## 5. Canary sweep outcome — 50 tests, 0 moved

`scratchpad/wave2/c1_canaries.sh` (two `verify_output.py` invocations, one per
suite, each with the full `--test=` list; `-P 2` per the brief's cap) plus 7
one-off runs. Compared against each suite's HEAD `results_graphics.json` by
`scratchpad/wave2/c1_check.py`:

```
[from_avmplus] 21 run, 21 unchanged-green, 0 moved
[avm2]         29 run, 29 unchanged-green, 0 moved
```

Individually-run canaries, all still green:
`from_avmplus/e4x/Expressions/e11_1_1`, `avm2/xml_explicit_use_namespace`,
`from_avmplus/e4x/XML/e13_4_4_32/v10`, `from_avmplus/e4x/XML/e13_4_4_24`,
`from_avmplus/e4x/Types/e9_1_1_4` (the fifth XMLList delete-by-index user in the
corpus, added after grepping `delete .*\[…\]`).

**Total: 57 tests exercised locally, 8 flips (all pass-ward), 0 regressions.**

Raw: `scratchpad/wave2/c1-avmplus.{log,json}`, `c1-avm2.{log,json}`,
`scratchpad/wave2/logs/*.txt` (per-test `--diff --verbose`, `b_*` = before,
`a_*` = after, `c_*`/`k*` = canary, `r_*` = rider).

### Method notes for whoever merges this

* Test data is gitignored, so a fresh worktree has no `tests/swfs/**` payload.
  `cp -a` of `from_avmplus/e4x` + `avm2/xml_*` from the main tree was enough
  (38 MB + ~5 MB) and preserves mtimes, which keeps the `RecompiledScripts`
  cache warm.
* Nested-suite tests need the **full relative path** as the `--test` value
  (`--test=e4x/Regress/regress-263935`, not `--test=regress-263935`) — the bare
  stem errors with "test directory not found".
* `verify_output.py` takes **repeated `--test=`** flags in one invocation; a
  50-test sweep as two processes is far cheaper than 50 processes.
* Do not edit runtime sources while a run is in flight — `compile_native` copies
  `SWFModernRuntime/src/**` into the build dir at compile time, so a mid-flight
  edit shows up as a bogus `compile_fail` in a *baseline* run. Two of the seven
  baselines were lost that way and had to be re-taken.

---

## 6. Suggested commit message

```
avm2/e4x: an E4X name's namespace, attribute flag and arity

Six near-pass E4X failures were one structure — an E4X name is a
(namespace, local-name, is-attribute) triple and each part was being
dropped somewhere.

- e4x_name_from_rtns keyed "is this an explicit namespace?" off the URI
  LENGTH, so `new Namespace()` / `new Namespace("")` was treated as the
  ANY namespace instead of the NO-namespace. Key it off the namespace
  KIND instead (only kind 0 is any). Fixes `none::*` matching every
  child, and stops an empty explicit namespace being re-qualified onto
  the current default xml namespace.
- The attribute flag and the any-name were derived from the multiname on
  the getproperty_rtns READ paths and hard-coded to 0 / non-NULL on the
  setproperty and deleteproperty ones, so `x1.@ns::['v'] = '555'` created
  an element child instead of setting the attribute. Thread both facts
  through setproperty_rtns_common / deleteproperty_rtns_common.
- XML.replace(): at ROOT SWF <= 9 a non-XML value goes through the XML
  constructor first (avmplus XMLObject.cpp:1540), so markup parses.
- maybe_escape_child()'s ">= 21 detaches from the old parent" arm reads
  the CALLER movie's version, not the root's (Ruffle
  caller_movie_or_root) — a v20 root can Loader-load a v21 child.
- XML.addNamespace() has one REQUIRED parameter: zero args is
  ArgumentError #1063, not a call with undefined.
- `delete xmlList[i]` detaches the removed node, so parent() reads
  undefined and childIndex() -1 (the name-keyed delete paths already did).

Ruffle-tests: +7 (from_avmplus e4x/Regress/regress-263935,
e4x/Expressions/e11_1_2, e4x/XML/e13_4_4_32/v9, e4x/XML/e13_4_4_17,
e4x/XML/e13_4_4_2; avm2 xml_appendchild_swf_v21,
xml_list_delete_clear_parent). e4x/Statements/e12_1 improves 4 -> 3
lines; its two remaining causes (the ABC SETS_DXNS method flag, and
single-arg `new QName(n)` capturing the construction site's default xml
namespace) are recompiler / oracle work.
```
