# Wave-1 — TRACE-axis board, regenerated (session 15, dual-axis fan-out #7)

**Agent:** `w1-trace-board`. Read-only in the main tree (no source edits, no
commits). Local verification: 13 individual tests re-run at `-P 3`
(`verify_output.py --test=…`), never a suite.

**Baseline CONFIRMED, exactly:** trace **4269 / 4443 effective** at `bf585e448`
(CI run `31647430265`), merged into master's per-suite `results_graphics.json`
at `b15b9cbdf`. Verified two ways:

```
scripts/corpus_status_diff.py 920b8860d WORKTREE --per-suite
  intersection 4427:  effective 4237 -> 4265 (+28), 29 gains, 1 "regression"
  (avm2/textblock_line_changes ruffle_matched->output_mismatch = the upstream
  282->481 test rewrite already booked in arc §15.2), histogram clean.
absolute (working tree, NESTED excluded): TOTAL 4443  EFFECTIVE 4269
  pass 4019 | ruffle_matched 250 | output_mismatch 173 | runtime_error 1
```

174 failing rows. Of those, **38 are named in a disposition doc or
`ignored_tests.txt`**; 136 have no disposition mention. Per-suite failures:
avm2 88, from_gnash 31, avm1 24, from_shumway 11, mixed_avm 7, from_avmplus 6,
audio 2, timeline 2, import_assets/text/visual 1 each.

---

## 1. Ranked, priced clusters (lead with these)

Pricing convention: **floor** = flips I have line-level evidence for; **real** =
expected with one session's work; **ceiling** = everything in the cluster.

| # | cluster | rows | floor / real / ceiling | verdict |
|---|---|---|---|---|
| 1 | Matrix3D non-null parameter (#2007) + 2 riders | 9 | **+4 / +7 / +9** | **GO — take first** |
| 2 | FTE TextBlock/TextLine line model | 5 | +2 / +4 / +5 | **GO** |
| 3 | T10 `all_classes`, cheapest package first | 18 | +3 / +3 / +5 | **GO (scoped)** |
| 4 | AVM1 child under an AVM2 parent (dual-VM) | 14 | +1 / +3 / +14 | **GO (pilot only)** |
| 5 | `avm1/textfield_asbroadcaster` | 1 | +1 / +1 / +1 | **GO** |
| 6 | `avm2/sub_super_same_field` slot identity | 1 | +1 / +1 / +1 | **GO** |
| 7 | `avm1/watch_virtual_property` (board lead) | 1 | +1 / +1 / +1 | **GO** |
| 8 | fuzz `e152812e2cfc…` (board lead) | 1 | +1 / +1 / +1 | **GO** |
| 9 | `Number$/_convert` frames + NaN/Infinity | 2 | +1 / +2 / +2 | **GO (small)** |
| 10 | `from_avmplus/regress/bug_483783` (only crash row) | 1 | 0 / +1 / +1 | GO, careful |
| 11 | `from_shumway/as3-loader/LoaderTest2` | 1 | 0 / +1 / +1 | GO (small) |
| 12 | double→string shortest-round-trip probe | 2+ | 0 / 0 / 0 direct | PROBE only |
| — | gnash `array-v6/7/8`, `MovieClip-v6/7/8` | 6 | — | **NO-GO** (4–6 mechanisms each) |
| — | `eforin_001/002` avmplus hash order | 2 | — | **NO-GO** (regression risk) |
| — | action_order arc | 7 | — | **DEFER** (s14 ruling stands) |

Summing the GO rows' "real" column: **+22** available before anyone touches the
dual-VM arc's ceiling.

---

### 1.1 Matrix3D non-null parameters — the cheapest large cluster in the corpus

**GO. Floor +4, real +7. One file, one mechanism, ~60 lines.**

All nine `matrix3d_*` rows are new-in-drift (absent at `920b8860d`). I ran six
of them locally at HEAD. **Three of them differ ONLY in the missing null-argument
check — every numeric line already matches byte-for-byte:**

```
matrix3d_append   expected: Caught error: TypeError: Error #2007: Parameter lhs must be non-null.
                            \tat flash.geom::Matrix3D/append() … (6 lines)
                  actual:   Didn't throw
                  → the other 10 lines are IDENTICAL.
matrix3d_prepend  same, parameter `rhs`.
matrix3d_copy_row same, parameter `vector3D`, ×4 sites; every value line matches.
```

`matrix3d_copy_column` is the same defect plus an **ordering** bug: expected
throws #2007 for the null vector *before* validating the index, we throw
`ArgumentError #2004` first.

Exact sites — `SWFModernRuntime/src/avm2/avm2_stage3d.c`:

- `matrix3d_append` (line ~1492) / `matrix3d_prepend` (~1500): both do
  `matrix3d_ext_of(s3d_arg_object(act, 0))` and silently `return` when NULL.
- `matrix3d_copy_vec_to` (~1985) and its `…_from` twin: index `#2004` check
  runs *before* `s3d_arg_object(act, 1)`. Swap the order.
- `matrix3d_transform_vector_common` (~1669): `if (e == NULL || v == NULL)
  return avm2_null();` → must throw #2007 `vector`.
- **Latent bug worth fixing in the same patch:** `s3d_throw_2007` (line 85)
  raises `ctx->builtins.argument_error_class`, but every graded expectation
  says **`TypeError`**. `matrix3d_transform_vectors` (~1950) hand-rolls the
  correct `type_error_class` inline — the helper is the odd one out.

Two adjacent one-liners that convert three more rows from "close" to passing:

- `matrix3d_transform_vector` drops the **4th (w) component**: expected
  `(38, 44, 50, 56)`, ours `(38, 44, 50, 0)`. The rule from the fixture is
  `ow = m[3]x + m[7]y + m[11]z` (+`m[15]` for the non-delta form) — verified
  against the 1..16 matrix (4+16+36 = 56; 56+16 = 72). Pass 4 args to the
  `Vector3D` constructor instead of 3. **This plus the null check flips
  `matrix3d_transform_vector`.**
- `matrix3d_append_rotation`: zero-length axis must still produce the rotation
  (`180°` → `-1,0,0,…,-1,…`) and `NaN`/`Infinity` degrees with a zero axis must
  produce all-NaN; we return identity. Small, self-contained.

Harder half of the cluster (do NOT price into a wave-2): `copy_raw_data_to/from`
also need the fixed-`Vector` error taxonomy (**expected `#1126` "Cannot change
the length of a fixed Vector"; we emit `#1125` "index out of range"**, and the
target vector must be left UNMODIFIED on throw), and `recompose_edge_cases`
needs `recompose()` to return `false` and leave the matrix untouched on a
degenerate component (we write `1e-15` scales in).

Riders on the same #2007 mechanism, worth 5 minutes each once the helper is
right: `avm2/displayobject_getrect` and `from_shumway/acid/acid-shapes` both
carry `error_signature = TypeError: Error #2007: Parameter targetCoordinateSpace
must be non-null.`; `avm2/textblock_releaselines` needs #2007 on
`firstLine`/`lastLine` (see cluster 2).

### 1.2 FTE TextBlock/TextLine line model

**GO. Floor +2, real +4.** Rows: `avm2/textblock_line_changes`,
`avm2/textblock_releaselines`, `avm2/textline_raw_text_length`,
`visual/definefont4`, (+`avm2/textblock_recreateline`, separate defect).

Four sub-defects, all in `SWFModernRuntime/src/avm2/avm2_text.c` around the
documented layout core at line 7273:

1. **`lastLine` is wrong.** Both `textblock_line_changes` and
   `textblock_releaselines` open with `Last line in block: line-0` where
   expected is `line-4` / `line-5`. `tb_do_create_text_line` maintains
   `tb->first_line` and a `block_chain`, but the last-line accessor is reading
   the head.
2. **`rawTextLength` is per-line, not whole-block.** The code sets
   `tl->raw_text_length = text->len;   // the WHOLE block text` and a comment
   above says so deliberately. The new upstream test
   `textline_raw_text_length` **refutes that model**: expected
   `line 0: rawTextLength=3 … line 1: rawTextLength=2`, ours prints 5 and 5.
3. **`'\r'` and `"\r\n"` must break lines.** The same comment block asserts
   "`'\r'` is not a break". The fixture has explicit "Carriage Return" and
   "Carriage Return + Line Feed" sections expecting two lines each (with
   `rawTextLength` 3/2 and 4/2); we produce one line. `next_line_break()`
   (line ~7286) only scans for `'\n'`.
4. **`releaseLines(null, …)` must throw #2007** on `firstLine` / `lastLine`
   (same helper family as cluster 1), and a released line must get
   `textBlock = null` / `validity` transitions right.

**`visual/definefont4` belongs to this cluster** and is a free rider: its
expected output is EMPTY, and we emit a 24-line uncaught
`TypeError #1009 … (accessing field: getEffectiveLineHeight)` thrown from
`flashx.textLayout.compose::TextFlowLine/getLineLeading` — i.e. the TLF library
inside the SWF got a null back from our FTE surface. Any fix that stops
`createTextLine` returning null for this content silences the whole trace.

**Operational trap for the wave-2 agent:** `avm2/textblock_releaselines` and
`avm2/textline_raw_text_length` (and `avm2/automation_classes`,
`avm2/external_interface`) are graded in CI but **do not exist on local disk** —
run `ruffle-tests/download_tests.sh` before starting, or you will "confirm" a
test you cannot see. Those 4 are the only such rows out of 174.

### 1.3 T10 `all_classes` — the board's row count is wrong, and there is a cheap slice

**GO, but scoped.** §15.3 says "13 `all_classes` rows". **It is 18**
(accessibility 3, display 6, display3D 2, events 5, xml 2). s14's describeType
patch already took `display3D/swf12`, `errors/swf{9,10,30}`,
`security/swf{12,13,30}`.

Cost is wildly uneven, and the arc doc's single "~16.5k lines" figure hides it:

| package | rows | expected lines/row | missing lines/row (s14 measurement) |
|---|---|---|---|
| accessibility | 3 | 73–88 | **47–64** |
| xml | 2 | 116 | 91 |
| display3D | 2 | 326 / 412 | 170 / 196 |
| events | 5 | 1030–2353 | 489–1811 |
| display | 6 | 1959–2936 | 1600–2388 |

**Take `accessibility` (+3) as the T10 pilot**: it is two classes
(`Accessibility` with `sendEvent`/`updateProperties` + a `Boolean`-typed
`active` accessor, and `AccessibilityImplementation` with 12 methods), and the
`swf9` vs `swf10/30` split is a version gate we already have machinery for.
`avm2/accessibilityimplementation` (`TypeError #1006: accDoDefaultAction is not
a function`) is the **same missing class surface**, so the pilot is really +4.
`xml` (+2) is the natural second.

**Refutation — the "match Ruffle instead" shortcut does not exist.** The five
`all_classes/events` rows are upstream `known_failure = true`, so a
`ruffle_matched` would count as effective. I diffed the fixtures: `output.ruffle.txt`
is 1033 / 1646 / 1758 / 1822 / 2361 lines against expected 1030 / 1638 / 1750 /
1814 / 2353 — Ruffle's output is within 8 lines of Flash's. There is no cheap
path; those five cost the same as the real descriptors.

### 1.4 AVM1 child under an AVM2 parent — the biggest cluster on the board, and it is NOT on the board

**GO for a pilot only.** 14 rows, none named in §15.3:

```
mixed_avm/avm2_loads_avm1              mixed_avm/avm2_loads_avm1_v9
mixed_avm/avm2_loads_avm1_doabc        mixed_avm/avm2_loads_avm1_v10
mixed_avm/avm2_loads_avm1_loads_avm2_doabc
mixed_avm/avm2_loads_avm1_loads_into_root
mixed_avm/avm1_loads_avm2   (the reverse direction)
avm2/avm1_root                 avm2/mouse_pick_avm1_root
avm2/mouse_pick_loader_avm1    avm2/loader_try_click_root
avm2/focus_events_mixed_avm_edittext   avm2/selection_onsetfocus_mixed_avm
import_assets/avm1_imports_avm1
```

**Mechanism, stated by the runtime itself** —
`SWFModernRuntime/src/avm2/avm2_display.c:5703-5710`:

```c
else if (pl->content_type == LI_CT_SWF && pl->avm1_child)
{
    // An AVM1 child has no AVM2 root to boot, … We do not execute the child's
    // AVM1 timeline yet, so the wrapper is a live but empty DisplayObject
```

Everything upstream of that line already exists: `verify_output.py`
(`recompile_child_swf`, ~line 2282) recompiles **every** child SWF including
AVM1 ones and links its `RecompiledScripts`/`RecompiledTags` with an offset
`string_id`; the AVM1 runtime is in `core_sources` for AVM2 parents too
(`is_avm2` only *adds* the avm2 tree). What is missing is the AVM1 analogue of
`loader_boot_child_swf` (`avm2_display.c:5453`): build the child's AVM1 root
under the `AVM1Movie` wrapper minted at 5711, run its frame-1 DoAction, and tick
it with the parent.

Cheapest pilot rows (whole diff is "the child's script never ran"):
`avm2_loads_avm1_doabc` (3 missing lines), `avm2_loads_avm1_loads_into_root`
(1 line), `avm2_loads_avm1_v9` (1 line), `avm2_loads_avm1_loads_avm2_doabc`
(2 lines). Note `avm2_loads_avm1_v10` additionally expects `addChild` of an
`AVM1Movie` to throw **error 2180** (we allow it) — that half is a 5-line fix
independent of the arc and worth grabbing regardless.

`mixed_avm/avm1_loads_avm2` is the mirror case and is explicitly ruled out for
now by the harness comment at 2331 ("an AVM1 parent does not compile src/avm2 at
all … that is `mixed_avm/avm1_loads_avm2`, and it belongs to the dual-VM arc").

### 1.5 `avm1/textfield_asbroadcaster` — +1, small and self-contained

TextField instances are never AsBroadcaster-initialized. Fixture
(`ruffle-tests/tests/swfs/avm1/textfield_asbroadcaster/test.as`) requires:
`tf._listeners` exists at creation with **the TextField itself at index 0**
(`_listeners.length == 1`, `_listeners[0] == tf`, `_listeners[0].name` works),
plus `addListener` / `removeListener` / `broadcastMessage(name, …args)`, and the
built-in `onChanged` / `onScroller` / `onSetFocus` / `onKillFocus` broadcasts
firing from `tf.text = …`, `tf.scroll = …`, `Selection.setFocus(…)`. We print
`0 / (empty) / undefined / false / 0` for the first five lines — nothing exists.

### 1.6 `avm2/sub_super_same_field` — +1, one AVM2 slot rule

Re-run at HEAD: 6 of 12 lines differ, **all one mechanism**. `LevelTwo`/
`LevelThree` declare slot traits with the *same* QName as `LevelOne`'s
(`pubSameName`, `internal internalSameName` — the fixture says the SWF was hand
edited to make the names collide). In AVM2 a subclass slot trait with the same
name does **not** override the parent slot: each declaring class gets its own
slot, and code compiled in class *N* early-binds to *N*'s slot. We resolve by
name at runtime, so `LevelOne.print()` on a `LevelTwo` instance reads LevelTwo's
value. Same family as the `vtable-override-is-not-append` note; the change is in
slot allocation (recompiler `abc_emit` side) rather than lookup.

### 1.7 `avm1/watch_virtual_property` — board lead CONFIRMED, mechanism refined

Still failing at HEAD (60-line fixture, we produce 52 and diverge from line 5).
§15.3's framing — "watch must precede the virtual-setter walk" — is **directionally
right but understates it**: the `plusOne:` watcher callback does not fire *at
all* for an `addProperty`-backed property. Every expected
`plusOne: variable changed from X to Y` line is absent; the getter/setter traces
are all present and correct. So it is "watch never runs on virtual props", and
ordering is the second half. s14's watch-family patch (unified re-entry counter,
Cat 10) did not touch this path.

### 1.8 `Number$/_convert` — +2, mechanical

`avm2/number_convert_errors` (831 diff lines, but ONE mechanism): every expected
throw carries two frames we do not emit —

```
expected:  at Number$/_convert()
           at Number/http://adobe.com/AS3/2006/builtin::toPrecision()
           (+ at int/http://…::toPrecision()  for the int/uint forwarders)
ours:      at Number/toPrecision()
```

i.e. the range check must throw from a shared `_convert` frame, the builtin
namespace must be spelled out, and `int`/`uint` must show their own forwarding
frame. `avm2/number_convert_edge_cases` (32 diff lines) is the value half of the
same API: `NaN`/`Infinity` must short-circuit **before** the range check
(`NaN.toPrecision(null)` → `NaN`, not a `RangeError`; `NaN.toPrecision(1)` →
`NaN`, not `NaNe+1`).

`avm2/number_tostring` (radix 3/6/7/9/11/12 digits diverge in the tail:
`…100222000000` vs `…1002220002210`) is a **separate** big-integer radix
conversion defect — do not bundle it.

### 1.9 `from_avmplus/regress/bug_483783` — the corpus's only `runtime_error`

```
$ verify_output.py --tests-dir=…/from_avmplus/regress --test=bug_483783
  RUNTIME_ERROR  stderr: ERROR: heap_alloc(76396) failed - out of memory
  expected (1 line): Verify large string is created PASSED!
```

`heap_alloc` in `SWFModernRuntime/src/memory/heap.c:265` `exit(1)`s when o1heap
returns NULL, on a **76 KB** request inside a 4 GB native arena — so this is
o1heap fragmentation/binning under the test's repeated large-string doubling,
not a real OOM. +1 and it removes the only crash-class row in the corpus. Handle
with the standing `avm2-gc-cannot-run-mid-method` caution (never GC on
allocation failure).

### 1.10 `from_shumway/as3-loader/LoaderTest2` — +1, one line

`testSymbol present: false` vs `true` — a symbol exported by the loaded child
SWF is not visible in the loader's applicationDomain. Everything else in the
7-line fixture matches. Sibling `LoaderLoadBytesTest` (3 lines) needs the
loadee's own trace to fire *before* its `initialized` line, and `loader-events`
needs progress/ordering — treat those two as separate.

---

## 2. Refutations and corrections to arc doc §15.3

| §15.3 claim | verdict |
|---|---|
| "T10 … 13 `all_classes` rows, ~16.5k lines" | **WRONG COUNT — 18 rows.** And the cost is not uniform: `accessibility` needs 47–64 lines/row, `display` needs 1600–2388. Take accessibility+xml (+5) as a scoped slice; the arc framing is right for `display`/`events`. |
| "`textblock_line_changes` re-triage vs the new 481-line fixture … likely one FTE mechanism" | **Mechanism claim CONFIRMED and enlarged.** It is 4 sub-defects, not one, but they are all in `avm2_text.c`'s line core, and the cluster is 4–5 rows (add `visual/definefont4`). Two of the rows are missing from local disk. |
| "matrix3d batch (9 failing rows, one class — biggest new cluster)" | **CONFIRMED and now priced.** Not the biggest cluster (the dual-VM one is 14 rows) but by far the cheapest: 3 rows differ *only* in a missing null check. |
| "`watch_virtual_property` (+1, watch must precede the virtual-setter walk)" | **Half right.** The watcher never fires at all on `addProperty` props; ordering is secondary. Pricing (+1) holds. |
| "fuzz 16th row `e152812e2cfc…` (+1, self-contained)" | **CONFIRMED open**, unchanged since baseline. |
| "action_order arc DEFERRED … pair with `extend_test` for +2 ceiling" | **DEFER stands.** I re-checked the 7 rows: they are not siblings. `ActionOrderTest3/4/5` show a *different* signature from `test11` — we emit 2–3 extra `onEnterFrame` lines per cycle and run past `<end of expected>`; s14's `wave1-avm1-tick.md` §"not siblings" already says `ActionOrderTest4` is the registerClass `ctor/static load/dynamic load` axis. Do not let a wave-2 brief bundle them. |
| (implicit) "the events rows are known_failure, so Ruffle-matching is cheap" | **REFUTED.** `output.ruffle.txt` is within 3–8 lines of the expected file for all five. |
| s14 §15.2's on-disk-ungraded lesson | **RE-CONFIRMED, and generalised** — see §3. |

Additional NO-GO rulings (each is a lead someone will otherwise re-price):

- **`from_gnash/actionscript.all/array-v6/v7/v8`** (v5 is dispositioned): I ran
  `array-v6` in full — 18 failed assertions in **6 independent mechanisms**
  (sparse-array `delete`+`hasOwnProperty`, `sort` leaving `length == 0`,
  `c.length` after string-keyed writes, a length setter case, for-in order after
  mutation, and 8 assertions about `__proto__`/`constructor` being assignable to
  primitives). All-or-nothing scoring → NO-GO for one session.
- **`from_gnash/actionscript.all/MovieClip-v6/v7/v8`**: full local run gives 21
  FAILED lines in **4 groups** — (a) `_yscale` sign + `getBounds` y inversion
  after a drawing op (`MovieClip.as:1520,1528,1529`), (b) `_root.meth`
  (`:2097,2100`), (c) 13 lines all "expected N obtained 0" at `:2191,2257–2305`
  (one mechanism), (d) `[object Object]` vs `undefined` at `:2590,2596`. A fix
  for (c) alone flips nothing. If someone wants the 3-row payoff, brief it as
  "fix all four groups", not "fix the `_yscale` sign".
- **`from_avmplus/ecma3/Statements/eforin_001` + `eforin_002`**: the expected
  order is avmplus's *hash-table probe order* (`toString, value, toNumber,
  toBoolean, valueOf` for insertion order `value, valueOf, toString, toNumber,
  toBoolean`), not insertion order. Replicating it means replicating avmplus's
  string hash and table growth, and every currently-passing for-in test depends
  on our insertion order. High regression risk for +2. Research-only.
- **`avm1/looping_child_swf5` / `swf9` / `swf32`**: byte-identical diffs → one
  mechanism (nested-sprite frame advance order, 207 actual vs 141 expected), but
  it is deep timeline ordering (same family as the deferred action_order arc).
  MED-large, +3 if taken; do not brief it alongside another timeline patch.
- **host-I/O / netstream / audio bucket**: closed by s14's re-cost (+3 taken,
  `swz` + `loader_applicationDomain` doc-backed in ACCEPTED_DIFFS Cat 13). The
  remaining `netstream_play_flv` / `_seek_flv` / `_play_stop_replay`,
  `audio/aac`, `audio/g711`, `audio_computespectrum`, `sound_load_multiple`,
  `id3_info`, `soundmixer_soundtransform` need real media decode. NO-GO.

**A shared sub-defect worth one probe (cluster 12):** our double→string is not
shortest-round-trip. `avm2/matrix` prints `1.836970198721029e-16` where Flash
prints `1.8369701987210297e-16`; `avm2/bounds_mode` prints `3.076923076923077`
vs `3.0769230769230775`. It flips neither test on its own (`matrix` also needs
`copyRowTo`/`copyColumnTo` on **flash.geom.Matrix**, per its
`error_signature`; `bounds_mode` also has a `pixelBounds` `-0.75` origin bug),
but it is a corpus-wide formatting rule and probably shows up in rows I did not
open. Cheap to measure, unclear yield — probe, don't brief as a flip.

---

## 3. Drift audit (name-set diff, not a count diff)

`920b8860d` → `HEAD`, `results_graphics`, NESTED excluded:

```
baseline 4427   current 4443   NEW 16   REMOVED 0
NEW (effective 4 / 16):
  EFF  avm2/matrix3d_position, avm2/matrix3d_transpose,
       regression/mask_nested_intersect, visual/define_bits_lossless2_rgb15
  FAIL avm2/automation_classes, avm2/textblock_releaselines,
       avm2/textline_raw_text_length,
       avm2/matrix3d_{append, append_rotation, copy_column, copy_raw_data_from,
                       copy_raw_data_to, copy_row, prepend,
                       recompose_edge_cases, transform_vector}
```

This reproduces arc §15.2 exactly (+16 tests, +4 effective, denominator
4427→4443) and confirms the correction it made to the s14 audit. **The entire
s15 opening cluster (matrix3d ×9, FTE ×2) arrived as drift** — the two biggest
new GO items on this board are last session's drift, which is worth saying out
loud in the s15 closeout.

**Trap re-confirmed, with a general rule.** There are 12 directories on local
disk that carry a `test.toml` but no graded row:
`avm2/{av_networking_params, av_tag_data, property_priority_scope_cache_order}`,
`avm1/{watch,virtual_property}_special_recursion[_double]_swf{6,7}` (8),
`from_avmplus/as3/Vector/initializer_large_vector`,
`from_gnash/misc-swfc.all/gotoFrameFromInterval`. **None of them is pending
drift.** `git log -S` on the results files shows each was graded once and then
*removed* (`av_*` at `34c0bd012`, `property_priority…` at `a2a1a8042`,
`watch_special_recursion_swf6` at `4ce87ccc6`) — they are upstream deletions
whose local directories were never cleaned. This is the same shape as the s14
"+9 free drift on 11 on-disk ungraded tests" error. **Rule for future audits:
an on-disk-but-ungraded dir is a REMOVAL artifact until `git log -S<name>` on
the suite's results file proves otherwise. Never book it as drift.**

Also note: `ruffle-tests/tests/swfs/from_avmplus/as3/Vector/_results/` and
`.../nonindexproperty/_results/` exist on disk with stale (2026-07-25) results
and are **not** tracked in `HEAD`, so they do not double-count — but they are
two more nested `_results` dirs that would need adding to
`scripts/corpus_status_diff.py:NESTED` if they ever get committed.

---

## 4. Method notes for the wave-2 briefs

- **Error-signature histogram is a floor, and a thin one here**: only 23 of 174
  failing rows carry an `error_signature` at all. The productive axis this
  session was the *first-diff-line + line-gap* histogram (11 rows differ by
  exactly 1 line, 16 by 2–3, 28 by 4–10, 53 by 11–50, 66 by >50) crossed with
  family name. Scripts left in the scratchpad:
  `…/scratchpad/{corpus.py, sig.py, show.py}` — `show.py PATTERN…` prints the
  stored actual/expected unified diff for any failing row without running it.
- **`results.json` truncates outputs at ~51 lines**, so a stored diff that ends
  in `... (N lines after) ...` cannot be used to count defect groups. Every
  NO-GO ruling in §2 that rests on a defect count (`array-v6`, `MovieClip-v6`)
  came from a real local run, not from the stored output.
- **Disposition check first** caught 38 of 174 rows. Cross-suite name collisions
  are real: the avm1 docs textually contain "matrix", "swz", "bom", so a naive
  grep tags avm2 rows as dispositioned when they are not — verify the hit is
  about the right suite before believing it.
- Local tree is behind CI on test content (4 graded rows have no local
  directory; `matrix3d_*` only appeared locally today). Any wave-2 agent working
  clusters 2 or 3 must sync first.
