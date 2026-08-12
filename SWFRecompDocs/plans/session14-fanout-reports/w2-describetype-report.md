# Session 14 · wave 2 · T7 `describeType` — P0 + P3 + P4-pilot implementation report

**Agent:** wave-2 worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a2f63695b17bd7caf`,
branched from `0a99be1a9` (master).
**Brief:** `SWFRecompDocs/plans/session14-fanout-reports/wave1-t7-describetype.md`
(§2.2 P0, §3 P3, §4/§6 P4 pilot).
**Deliverable:** `wave2/w2-describetype.patch` (four commits, not pushed).

---

## 0. Result

**All nine predicted target rows flip. +9 trace, exactly as the wave-1 brief
priced it, with no regression in any canary run.**

| target | brief prediction | measured |
|---|---|---|
| `avm2/describe_type_metadata` | +1 (P3) | **PASS** (byte-identical) |
| `avm2/describe_type_native` | +1 (P4 pilot) | **PASS** (byte-identical) |
| `avm2/all_classes/display3D/swf12` | +1 (P0 gate) | **PASS** (61/61 lines) |
| `avm2/all_classes/security/swf12` | +1 | **PASS** |
| `avm2/all_classes/security/swf13` | +1 | **PASS** |
| `avm2/all_classes/security/swf30` | +1 | **PASS** |
| `avm2/all_classes/errors/swf9` | +1 | **PASS** |
| `avm2/all_classes/errors/swf10` | +1 | **PASS** |
| `avm2/all_classes/errors/swf30` | +1 | **PASS** |

Graded by **diff against `output.txt`**, not the runner's positional
`matching_lines` metric (`results-diff-line-metrics-mislead`).

---

## 1. Commit ledger

The wave-1 brief's six-commit partitioning was collapsed to **three**
behavioural commits (plus one no-op tidy) that keep the same ordering and the
same "partial delivery is still mergeable" property. Brief commits 1 and 2
share every edit site in `dt_collect_ctor` and `avm2_stage3d.c` and cannot be
split without one of them being knowingly-broken in isolation — brief commit 2
depends on brief commit 1 by the brief's own §6 ordering rationale; brief
commits 4–6 are all rows in the same `static const` table.

Each commit is independently buildable and leaves the corpus no worse than the
one before it.

| # | sha | brief slice | content |
|---|---|---|---|
| 1 | `ba47bcad7` | brief commits 1 + 2 | describeType rule fixes (native-ctor default, `length` policy, Error-AS3 exclusion) + `avm2_builtin_class_api` + the 15 `flash.display3D` gates |
| 2 | `54c1a19b7` | brief commit 3 (P3) | ABC trait metadata: recompiler emission + runtime plumbing + both emitters |
| 3 | `b9a1f6c74` | brief commits 4 + 5 + 6 | descriptor table + `Event`/`Error`/`flash.errors`/`flash.security` rows, `EOFError extends IOError`, DRMManagerError gate, three new `flash.security` classes |
| 4 | `c750ed6bb` | — | no-op tidy: drop a dead counter in `emitTraitMetadata` |

---

## 2. Refutations of the wave-1 plan

### 2.1 "Put the tables in a NEW file `avm2_describe_desc.c`" — REFUTED (harness, not style) ★★

The brief's §4.3/§5 both call for two new source files. **The AVM2 source list
is not in `SWFModernRuntime/CMakeLists.txt`** — that file lists no `avm2_*.c`
at all. The list that actually builds every AVM2 test is hard-coded in
`ruffle-tests/verify_output.py:2196-2231` (plus its `verify_output_keep.py`
twin). Adding a source file therefore means editing the shared test harness,
which in a fan-out session is a far worse merge surface than adding ~250 lines
of `static const` tables to a file this agent already owns exclusively. Both
the descriptor tables and the `flash.security` registration went into
`avm2_globals.c`.

*(If the T10 arc grows the tables to the ~500+ lines the brief anticipates,
splitting them out is still right — but it should be booked as its own change
that also touches `verify_output.py`, `verify_output_keep.py` and any deploy
script, not smuggled in with a behavioural patch.)*

### 2.2 "`int` … already spelled out by name" — REFUTED ★★

§1.4-(1) says the native-constructor inversion is safe because "the only
natives any passing test describes with a constructor are `int` (`(*=)`) and
`flash.utils::Dictionary` (`(Boolean=)`), and both are already spelled out by
name." Only **Dictionary** was spelled out. `int` was relying on the generic
1-optional-`*` shell that the inversion removes, and
`describe_type_basic/output.txt:116-119` grades
`<constructor><parameter index="1" type="*" optional="true"/></constructor>` on
`int`. Inverting the default as written would have turned a **current PASS**
into a fail. `int` is now named explicitly (by `ctx->builtins.int_class`
identity, not by name-compare, so a user class called `int` cannot collide).

### 2.3 `register_security` already exists

`avm2_globals.c:3566` already defines a `static void register_security` for
`flash.system.Security`. The new certificate-class registration is
`register_security_certs`.

### 2.4 Metadata string pool: explicit file pointers, not implicit ones

The brief (§3.2-3) argued no new file pointer is needed because the pool is
reachable via `e->type_file` / `e->method.file` / `e->setter.file`.
`Avm2PropEntry` instead carries explicit `metadata_file` and
`setter_metadata_file`. A GETSET's two halves can be declared by different
classes and therefore by different ABC files (that is exactly why
`setter_defining_class` exists), so the implicit rule would resolve one half's
key/value indices against the other half's string pool. The explicit field
costs 8 bytes in a runtime-internal struct that is only ever built by
`memset` + field assignment.

---

## 3. Grading

Local, `--mode=no-graphics`, `--recompile` on first use of every copied test
dir (mandatory — the P3 recompiler change invalidates every `RecompiledABC`).
Graded by **diff of the saved actual against `output.txt`** with trailing
blank lines stripped from both sides, never by the runner's positional
`matching_lines`.

### 3.1 Targets — 9/9

```
avm2/describe_type_metadata          PASS   (was mismatch, 125 expected lines)
avm2/describe_type_native            PASS   (was mismatch, 23)
avm2/all_classes/display3D/swf12     PASS   (was mismatch, 109 actual vs 61 expected)
avm2/all_classes/security/swf12      PASS   (was mismatch, 19)
avm2/all_classes/security/swf13      PASS   (was mismatch, 53)
avm2/all_classes/security/swf30      PASS   (was mismatch, 53)
avm2/all_classes/errors/swf9         PASS   (was mismatch, 121)
avm2/all_classes/errors/swf10        PASS   (was mismatch, 140)
avm2/all_classes/errors/swf30        PASS   (was mismatch, 140)
```

`describe_type_metadata`'s actual is **byte-identical** to expected, which
also confirms the wave-1 brief's §1.1 claim that nothing but the `<metadata>`
children was ever missing.

### 3.2 The s13 wins — all held, `ruffle_matched` explicitly re-verified

```
avm2/describe_type_basic             PASS
avm2/describe_type_json              PASS
avm2/function_proto_created          PASS
from_avmplus/regress/bug_539328      RUFFLE_MATCHED   <-- re-verified explicitly
avm2/all_classes/security/swf11      PASS             <-- gate-from-below canary
```

`bug_539328` was diffed against **`output.ruffle.txt`**, not `output.txt`: it
still matches Ruffle's recorded output byte for byte, so its grade has not
drifted to plain `pass`/`fail` (`ruffle-matched-hides-regression`). It
describes an INTERFACE, so `dt_collect_ctor`'s early interface return keeps
it out of the native-constructor change entirely.

### 3.3 Canaries — every one green

**Rule-change canaries** (the `length` policy, the AS3-vs-public re-keying, the
class-object static surface):

```
avm2/static_length                                     PASS *
avm2/property_is_enumerable                            PASS
avm2/number_autoconv                                   PASS   <-- sharpest: pins int's
                                                                  HIDE_NSURI suppression
from_avmplus/ecma3/ObjectObjects/hasOwnProperty        PASS
from_avmplus/ecma3/ObjectObjects/propertyIsEnumerable  PASS
```

**Error-slice canaries** (the `EOFError extends IOError` and `getStackTrace`
namespace changes both reach outside describeType — the brief rated this slice
MEDIUM confidence):

```
avm2/error_prototype             PASS   (also a DRMManagerError user, SWF 17)
avm2/error_tostring_more         PASS   (constructs all 8 flash.errors classes, SWF 30)
avm2/error_tostring              PASS
avm2/error_stack_trace           PASS
avm2/error_stack_trace_edge_cases PASS
avm2/error_throwerror            PASS
avm2/bytearray_errors            PASS   (EOFError/IOError instances)
avm2/bytearray                   PASS
avm2/json_errors                 PASS
```

**API-gate canaries** (the classes hidden below their `[API(N)]` version):

```
avm2/stage3d_bitmap              PASS *  <-- SWF 13, the LOWEST-version Stage3D
                                            test in the corpus; below the
                                            SWF-17/19/22 gates
avm2/stage3d_x_y                 PASS    <-- SWF 15, likewise
avm2/stage3d_errors              PASS
avm2/stage3d_errors_swf_29       PASS
avm2/context3d_creation          PASS
avm2/stage3d_triangle            PASS
avm2/agal_compiler               PASS
avm2/abstract_classes            PASS    <-- register_abstract_gates over display3D
avm2/json_version_gated          PASS    <-- the pre-existing version gate
avm2/cross_api_version_call_older PASS
avm2/cross_api_version_call_newer PASS
avm2/air_hidden_lookup           PASS
avm2/all_classes/security/swf11  PASS    <-- gate FROM BELOW: all three new
                                             flash.security classes correctly
                                             absent at SWF 11
```

**describeType / reflection consumers:**

```
avm2/null_void_types                        PASS
avm2/displayobject_name_from_timeline       PASS
avm2/font_enumeratefonts                    PASS
avm2/catch_scope_slot                       PASS
avm2/supercall_two_classobjects             PASS
avm2/vector_object_final                    PASS
avm2/av_classes                             PASS
avm2/get_definition_by_name                 PASS
avm2/get_qualified_class_name               PASS
avm2/get_qualified_super_class_name         PASS
avm2/applicationdomain_getqualifieddefinitionnames  PASS
avm2/property_priority_definition_names_order       PASS
```

**Regression suite** (the AVM2 half is the canary for P3's generated-ABI move):

```
regression/avm2_typed_value_ops             PASS
regression/avm2_slot_default_template       PASS
regression/avm2_static_and_store_slots      PASS
regression/avm2_tolerant_verify_quarantine  PASS
regression/avm2_findprop_this_resolution    PASS
regression/avm2_embed_bytearray             PASS
regression/avm2_agi_shell                   PASS
regression/avm2_gc_dynprop_tombstone_purge  PASS
regression/avm2_goto_catchup_scale          PASS
regression/avm2_simplebutton_click          PASS
```

`*` = graded by the runner's own verdict rather than a saved-actual diff.
`stage3d_bitmap` and `stage3d_triangle` have an EMPTY `output.txt` (they are
image tests), so there is nothing to diff — but that is exactly the right
shape for a gate canary: a `1065 ReferenceError` from a hidden `Context3D*`
name would appear as unexpected trace output and fail them. `static_length`
came back with no saved actual on a contended run and was re-run sequentially.

**Totals across every row graded this session: 58 PASS, 1 RUFFLE_MATCHED,
18 MISMATCH — and all 18 mismatches are the known-failing `all_classes` rows
of §3.4 (16 `accessibility`/`xml`/`display`/`events` + `display3D/swf13,swf30`).
Zero unexpected mismatches, zero pass→fail.**

### 3.4 The remaining `all_classes` rows — measured non-worsening

Also graded here (they are directly touched by the gate, and belong to the
T10 arc rather than this pilot):

```
all_classes/display3D/swf13  MISMATCH  ours-extra=55 missing=170  ctor-or-length=0
all_classes/display3D/swf30  MISMATCH  ours-extra=51 missing=196  ctor-or-length=0
```

`display3D/swf13` now emits **exactly the five** `not accessible` lines its
expected file names (`Context3DBufferUsage`, `Context3DMipFilter`,
`Context3DProfile`, `Context3DTextureFilter`, `Context3DWrapMode`) — the gate
is right at SWF 13 as well as SWF 12, and `swf30` correctly hides nothing.
Both rows now fail only for the `Context3D`/`Program3D`/buffer member
descriptors, which is T10 work.


None of these can flip this session (they need the T10 member-registration
work) and none of them worsens. The only content this patch ever REMOVES from
an `all_classes` row is:

1. spurious `<constructor>` blocks on native classes — and the corpus-wide
   grep shows every expected `<factory>` in `display3D`, `security` and
   `accessibility` is constructor-less, so those are strictly closer; in
   `xml`/`display`/`events` the expected constructors are real signatures
   (`(String=)`, `(uint, String)`, …) that our `(*=)` shell never matched, so
   dropping it changes wrong-lines-present into wrong-lines-absent — neutral;
2. `length` on packaged classes — `grep -c 'name="length"'` over every
   `all_classes/*/*/output.txt` is **0**, so strictly closer.

Everything else the patch does is additive or corrective.

**Measured on all sixteen remaining rows** (`wave2/direction.sh`): of every
line we emit that the expected file does not contain, **zero** are a
`<constructor>`/`<parameter>` or a `name="length"`. The two removals are
therefore complete and took nothing correct with them; every remaining
mismatch is a missing member or a `type="*"` where a real type is wanted, i.e.
the T10 descriptor gap.

```
row                              ours-extra  missing  of ours: ctor-or-length
all_classes/accessibility/swf9        1        47              0
all_classes/accessibility/swf10       3        64              0
all_classes/accessibility/swf30       3        64              0
all_classes/xml/swf9                 36        91              0
all_classes/xml/swf30                36        91              0
all_classes/display/swf9           1138      1600              0
all_classes/display/swf10           966      2038              0
all_classes/display/swf11           966      2062              0
all_classes/display/swf12           966      2062              0
all_classes/display/swf13           956      2130              0
all_classes/display/swf30           949      2388              0
all_classes/events/swf9             158       489              0   (ignore-listed)
all_classes/events/swf10            150      1089              0   (ignore-listed)
all_classes/events/swf11            152      1203              0   (ignore-listed)
all_classes/events/swf12            154      1269              0   (ignore-listed)
all_classes/events/swf30            161      1811              0   (ignore-listed)
```

The five `all_classes/events` rows are reported separately here, as asked:
they are `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:54-58` under upstream
`known_failure = true`, so they move the headline row count but not the
effective-pass number. None of them moves either way.

---

## 4. Files edited

| file | what |
|---|---|
| `SWFRecomp/src/abc/abc_emit.cpp` | `emitTraitMetadata` (new) + `emitTraitArray` takes `const AbcFile&` and emits the two extra trait members; 4 call sites |
| `SWFModernRuntime/include/avm2/avm2_abc.h` | `Avm2AbcMetadataItem` / `Avm2AbcMetadata` (new); `Avm2AbcTrait` grows two appended members |
| `SWFModernRuntime/include/avm2/avm2_class.h` | `Avm2PropEntry` grows six appended members (two metadata halves) |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | `avm2_builtin_class_api` declaration |
| `SWFModernRuntime/src/avm2/avm2_class.c` | `avm2_vtable_add_traits`: metadata copy + both accessor-merge paths |
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `builtin_class_impl`/`avm2_builtin_class_api`; the three rule fixes; `DtMeta`/`DtMetaArg` + collection + both emitters; the `DtDescClass` table and its four consumption points; `register_security_certs` |
| `SWFModernRuntime/src/avm2/avm2_error.c` | `EOFError extends IOError`; `DRMManagerError` API gate |
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | `s3d_api_min_swf` gate table + `s3d_class` helper; 15 gated registrations |

No render code, no `avm2_ops.c`, no test-harness file, no `CMakeLists.txt`.

---

## 5. Expected CI movement

**Dispatch: `mode=graphics`, `categories=full`, `images=false`.**
`full` is required — the change touches both the AVM2 runtime *and* recompiler
emission. Expect a longer-than-usual run: `Avm2AbcTrait` grew two members, so
**every `RecompiledABC` in the corpus regenerates**.

* **+9, all in the `avm2` suite** — `describe_type_metadata`,
  `describe_type_native`, `all_classes/display3D/swf12`,
  `all_classes/security/{swf12,swf13,swf30}`,
  `all_classes/errors/{swf9,swf10,swf30}`.
* **+0 elsewhere.** `from_avmplus/regress/bug_539328` was already banked in
  s13 and stays `ruffle_matched`.
* **Net +9 effective passes → 4246** from the 4237 baseline, if nothing else
  moves.
* No pixel-axis effect — no render code is touched, and image comparisons
  never gate trace pass/fail.

The `T7` family drops from **22 graded-and-failing rows to 13**: the six
`all_classes/display` rows, three `accessibility`, two `xml`, and
`display3D/swf13`+`swf30`. Those are the `T10-playerglobal-descriptor` arc and
were deliberately not opened.

---

## 6. What the T10 arc can build on

* **`DtDescClass` is the target shape for the generator.** Twelve rows,
  hand-written from the expected files and Ruffle's `.as` declarations, now
  reproduce four whole test rows byte-for-byte. A generator over
  `~/CC/ruffle/core/src/avm2/globals/flash/**/*.as` has a validated
  reference implementation to diff against, and the four consumption points
  in `avm2_globals.c` do not change as the table grows.
* **`avm2_builtin_class_api` is the whole API-version axis.** Adding a gate is
  now one argument at one registration site. The `[API("N")] → N-660` mapping
  is written out in `avm2_stage3d.c`'s `s3d_api_min_swf` comment, verified
  against every `all_classes` expected file.
* **The gate must skip only the two EXPOSURE calls.** `Stage3D.requestContext3D`
  mints a `Context3D` at every SWF version through the stored class pointer;
  hiding the *name* is correct, destroying the *class* is not. Pinned by
  `avm2/stage3d_bitmap` (SWF 13, the lowest-version Stage3D test in the
  corpus) and `avm2/stage3d_x_y` (SWF 15) — both below the SWF-17/19/22 gates
  and both green.
* **`register_abstract_gates` silently no-ops on a hidden class**, because
  `builtin_class_lookup` goes through `avm2_domain_find`. That is harmless
  today (a hidden name cannot be `new`'d from script) but is a trap for the
  next gate: if a gated class ever needs its abstract gate at a version where
  its name is hidden, that lookup has to become a direct pointer.
* **Untouched and still open for T10:** the ~1,300 typed members of
  `all_classes/display`, `XMLNode`'s 12 real `public var` slots, and
  `AccessibilityImplementation`'s 14 methods. Every remaining diff line in
  those rows is a `>` (a member we do not register at all) or a `type="*"`
  where a real type is wanted.

---

## 7. Housekeeping

* Test dirs were copied from the main tree into this worktree's canonical
  suite paths; the main tree's dirs were never targeted. `--recompile` on
  first use of every copy (mandatory here, not just hygiene: the P3 change
  moves the generated-ABI, so a stale `RecompiledABC` is a guaranteed
  `stale-recompiledabc` false COMPILE_FAIL).
* `SWFRecomp/build` was configured and built **fresh in this worktree** —
  `abc_emit.cpp` is in the patch, so the main tree's binary would have emitted
  the old tables.
* No `git stash` was used anywhere (shared across worktrees).
* Nothing was pushed. Three commits sit on this worktree's branch;
  `wave2/w2-describetype.patch` is `git diff 0a99be1a9..HEAD` restricted to
  `SWFRecomp/src`, `SWFModernRuntime/src` and `SWFModernRuntime/include`, so
  it excludes the copied test dirs, the build tree and the `wave2/` scratch.
* Machine was heavily contended by sibling agents throughout (load average
  20-25). Two runs came back with empty output mid-batch; both were re-run
  sequentially and passed (`avm2/static_length`,
  `avm2/all_classes/display3D/swf12`) — the documented false-failure-under-load
  mode, not a real result.
