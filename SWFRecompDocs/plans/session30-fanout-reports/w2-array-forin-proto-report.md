# s30 w2-array-forin-proto: report

Slot `w2-array-forin-proto`, wave 2 (implementation). Base `origin/master` `6481e7c4` (code = s30 baseline
`2d40d3799` + docs). Corpus downloaded at upstream Ruffle `66f9073de` (avm1, from_gnash, from_shumway; visual/text/fonts
for the canary scan). Box: cloud, Dawn OK, lavapipe. All A/B legs on this box.

## NEW files

- `SWFRecompDocs/plans/session30-fanout-reports/w2-array-forin-proto-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-array-forin-proto.patch` (source patch; `action.c` only)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-array-forin-proto-fixture/create_test_swf.py` (FLASH request fixture
  generator, hand-assembled AVM1; no MTASC in the cloud)
- `.../w2-array-forin-proto-fixture/swf{5,6,8}/test.swf` (built fixtures), `ours_before.txt` / `ours_after.txt` (our
  output on clean master / with the patch)

The fixture is NOT in the patch and NOT in `regression/`: it has no oracle outside SWFRecomp yet (see LOCAL ORACLE
REQUESTS). Once the FP32 capture is archived, the coordinator can move `swf6` and `swf8` (and `swf5`) into
`ruffle-tests/tests/swfs/regression/avm1_array_forin_proto_swf{5,6,8}/` with `output.txt` set to the FP32 trace and
`test.toml` set to `num_ticks = 1`.

## Verdicts

| Item | Verdict |
|---|---|
| ARRAY `for…in` walks `__proto__` (`actionEnumerate2` ARRAY arm) | **GO, landed in the patch.** FP32 order is confirmed on the `global_proto_decls` golden (`Key/Mouse/Selection/Stage._listeners` list the 9 then-unhidden `Object.prototype` names in exactly our OBJECT-arm order, `toLocaleString … watch`). **0 trace status flips, 0 pixel moves.** |
| Same walk in the legacy `actionEnumerate` ARRAY arm (opcode 0x46, by-name `for…in`) | **GO, landed, with its own sub-switch.** Same Flash semantics. It is the arm the gnash `argstest-v6/7/8` walk uses. |
| Literal / InitArray indices lost once a named prop is added (`b=[10,20]; b.bar=1; for(k in b)` → `bar` only) | **Found here, fixed (S).** Pre-existing bug in the same arm: once `enum_keys` exists, untracked live indices were never listed. Corpus reach is 1 row (`text_format_get_text_extent_own`, pass → pass, output identical). |
| `global_proto_decls` (rm? no: `output_mismatch`, ignored) | **no flip.** On master: 2593 → **2505** diff lines (`_listeners` sections 524 → 228). On top of the w1-native-table prototype: 920 → **468**. |
| `global_proto_decls_delete` | **no flip.** On master: 2215 → **2171**. On top of the w1-native-table prototype: 781 → **305**. |
| gnash `argstest-v6/7/8` | **no flip (output_mismatch → output_mismatch).** Flash-ward in content (+90/+70/+70 golden lines matched), but raw diff count is worse (+396/+436/+436 lines). All of the growth is instance-layout residue owned by **w2-native-instance** (§3). Sub-switch `SWF_ARRAY_FORIN_PROTO_LEGACY=0` reverts only this effect. |
| Brief premise: gnash `array-v5..8` B20a (array.as:1628-1636) "likely the same mechanism" | **Refuted.** `traceProps(o)` there enumerates a plain Object (a "fake array" `Array.prototype.sort.call(o)`), not an ASArray (CURRENT_STATUS.md:330 already says so). The patch never fires on `array-v5..8` (log-proven) and their output is unchanged. |
| Brief premise: FP32 order is "own indices / own named props, then inherited" | **Refined.** In POP order (what `for…in` yields) FP32 lists the inherited names FIRST, then the own ones (`global_proto_decls` `X._listeners`: 9 inherited names, then own `constructor`). This is also how our OBJECT arm already orders things. The patch pushes inherited names last so the LIFO pop yields them first. |
| `_listeners` own `constructor` (FP32 shows `constructor, own` on every `_listeners`) | **HOLD (not my arm).** Ours has no own unhideable `constructor` on the AsBroadcaster-made array (fixture row L1). About 8 lines on `global_proto_decls`. Completion mechanism: `AsBroadcaster.initialize` (or `arrayResolveGlobalCtor`/`virt_ctor` materialisation under `ASSetPropFlags(arr, null, 0, 1)`) gives `_listeners` an own DONT_ENUM `constructor = Array`, once the FP32 fixture row L1 confirms the layout for a script `new Array()` (row F) vs the AsBroadcaster array. Owner: whoever owns AsBroadcaster / array instance layout (w2-native-instance is closest). |

## Expected-flip ledger (coordinator: check CI against this)

**Trace axis: no status change anywhere.** Line-count moves only, all on rows that stay `output_mismatch`:

| row | status before → after | diff lines (GNU `diff`, vs graded golden) before → after |
|---|---|---|
| `avm1/global_proto_decls` (ignored) | output_mismatch → output_mismatch | 2593 → 2505 |
| `avm1/global_proto_decls_delete` (ignored) | output_mismatch → output_mismatch | 2215 → 2171 |
| `from_gnash/actionscript.all/argstest-v6` | output_mismatch → output_mismatch | 2208 → 2604 (missing 878 → 788, extra 1330 → 1816) |
| `from_gnash/actionscript.all/argstest-v7` | output_mismatch → output_mismatch | 2209 → 2645 (missing 813 → 743, extra 1396 → 1902) |
| `from_gnash/actionscript.all/argstest-v8` | output_mismatch → output_mismatch | 2238 → 2674 (missing 833 → 763, extra 1405 → 1911) |

Every other row must be byte-identical. Any other trace move on CI is a defect of this patch.

**Pixel axis: no change.** The two canary rows that contain an Enumerate opcode (`avm1/movieclip_setmask`,
`avm1/netstream_play_flv_screen`) are md5-identical before/after. No other canary row contains one (scan below), so they
are unchanged by construction.

## 1. Mechanism and patch (owner `SWFModernRuntime/src/actionmodern/action.c`)

Functions added (all `static`, defined just above `actionEnumerate2`):
- `arrayForinProtoEnabled()`: kill switch `SWF_ARRAY_FORIN_PROTO=0` (both arms).
- `arrayForinOwnsName(arr, name, len)`: an own `arr->props` entry (any flags) or a live in-range index shadows an
  inherited name.
- `arrayForinPushUntrackedIndices(app_context, arr)`: kill switch `SWF_ARRAY_FORIN_UNTRACKED=0`. Called at the top of the
  `enum_keys` branch of the `actionEnumerate2` ARRAY arm. It pushes every live index that `enum_keys` does not hold, in
  ascending order, honouring a DONT_ENUM set through `ASSetPropFlags`. These keys are the oldest, so they pop last.
- `arrayForinPushInherited(app_context, arr)`: walks the array's prototype chain and pushes every ENUMERABLE name, at
  each level in insertion order, so the LIFO pop yields the deepest level first, reversed. This is the walk and order of
  the existing OBJECT arm. Inherited `constructor` and `__proto__` are skipped (as the OBJECT arm skips `constructor`),
  and so is `PROPERTY_FLAG_PERM_DONTENUM`. Names are de-duplicated across levels (case-insensitive at SWF ≤ 6, through
  the existing `isPropertyEnumerated`). The chain start is resolved WITHOUT side effects: own `__proto__` (an object, or
  an array's `props`), else `g_array_proto_legacy`/`_modern` for the version group, else `g_array_prototype`. I did not
  use `actionArrayProtoForAmf`, because its fallback lazily builds Array.prototype.

Call sites:
- `actionEnumerate2`, ARRAY arm: `arrayForinPushUntrackedIndices` at the top of the `enum_keys` branch;
  `arrayForinPushInherited` after both own-key branches.
- `actionEnumerate` (legacy 0x46), ARRAY arm: `arrayForinPushInherited` after the own keys, gated by
  `SWF_ARRAY_FORIN_PROTO_LEGACY=0`. A forward declaration was added above `actionEnumerate`.

No other function is touched. Nothing in native tables or `ensureGlobalInit` changes (that is sibling w2-native-table-land's
territory). There is no `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` code, so the change is mode-independent (checked
below).

Kill-switch proof: `SWF_ARRAY_FORIN_PROTO=0 SWF_ARRAY_FORIN_UNTRACKED=0` makes `global_proto_decls` byte-identical to
clean master.

## 2. Evidence

### 2.1 Golden fit (`avm1/global_proto_decls`, FP32 LNX)

FP32 `Testing _global.Key._listeners`: `toLocaleString, isPropertyEnumerable, isPrototypeOf, hasOwnProperty, toString,
valueOf, addProperty, unwatch, watch`, then `constructor, own`. On master our section was EMPTY. With the patch the 9
inherited names come out in exactly that order (the remaining differences in those lines are the `type=[function with
prototype]` column, which is a native-table fact). The recursion then walks `_listeners.watch` and the other members, as
FP32 does.

| `global_proto_decls` | master | + this patch |
|---|---|---|
| total diff lines | 2593 | **2505** |
| `_listeners` sections (section-level count, as w1 §3) | 524 | **228** |
| total, on top of `w1-native-table-prototype.patch` | 920 | **468** |
| `_delete` total, on master | 2215 | **2171** |
| `_delete` total, on top of `w1-native-table-prototype.patch` | 781 | **305** |

After the patch, the 228-line `_listeners` residue on master is all native-table facts: `toLocaleString`/`toString` `type=` (with/without prototype)
76+12, `X._listeners.toLocaleString.prototype` section missing 4 / `toString.prototype` extra 4 (+ their bodies), own
`constructor` 8. Stacked on the native-table prototype, the drop is larger (920 → 468), because there the types are
already right.

w2-native-table-land has not landed (master `6481e7c4`). I measured on top of `w1-native-table-prototype.patch` instead:
it applies cleanly with this patch, and the two do not overlap textually. The coordinator should re-measure after that
landing. Expect about −450 on `global_proto_decls` and about −475 on `_delete`.

### 2.2 Fixture (our output; the FP32 capture is requested)

Fixture rows (SWF 6 = SWF 8 for us; SWF 5 is the same except L0/L1 empty, because `AsBroadcaster` is absent at v5 in ours):

```
row  master                 patched
A0   foo,1,0,               foo,1,0,
A1   foo,1,0,               aq,ap,foo,1,0,               (Array.prototype.ap, .aq)
A2   foo,1,0,               op,aq,ap,foo,1,0,            (+ Object.prototype.op)
B    bar,                   op,aq,ap,bar,1,0,            (literal [10,20] + bar; v5: master already bar,1,0)
C    ap,foo,1,0,            op,aq,ap,foo,1,0,            (own a.ap shadows inherited ap)
D    ap,foo,1,0,            op,aq,push,ap,foo,1,0,       (ASSetPropFlags(Array.prototype,"push",0,1))
E    ap,foo,1,0,            op,toString,aq,push,ap,foo,1,0,
G    op,toString,z,         op,toString,z,               (plain Object: OBJECT arm, unchanged)
H    0,                     op,toString,pp,0,            (custom __proto__ {pp:1})
F    (empty)                op,toString,aq,ap,push,      (new Array + ASSetPropFlags(n,null,0,1))
L0/1 (empty)                op,toString,aq,ap,push,      (AsBroadcaster _listeners; no own constructor: HOLD above)
Z    ap,foo,1,0,            ap,foo,1,0,                  (after deletes / re-hide)
```

The model choices that the fixture puts to Flash are: (a) inherited names before own names in pop order (already
pinned by the golden); (b) Object.prototype (deepest) before Array.prototype; (c) reverse insertion within a level;
(d) shadowing by an own name; (e) literal indices pop last; (f) the own slots of `new Array()` after an unhide (FP32 may
add `constructor`/`__constructor__`, SWF 6 vs 8); (g) SWF 5 legacy Enumerate. If FP32 disagrees on (b)–(e), the fix is
local to `arrayForinPushInherited` / `arrayForinPushUntrackedIndices`.

### 2.3 Guard (brief item 2): the set, and how it was covered

**The set, argued.** The new helpers are reachable only from the two Enumerate opcodes. I scanned every `*.swf` under
`avm1`, `from_gnash`, `from_shumway`, `regression` (DoAction, DoInitAction, nested DefineSprite; parsing action records,
not grepping bytes) for `Enumerate2` (0x55) or `Enumerate` (0x46). **200 test dirs** (avm1 127, gnash 65, shumway 5,
regression 3) contain one. Any `for (… in <array>)` row is in that set, because the source-level construct compiles to
one of the two opcodes. Clip-event and button action blocks are not scanned, and there is no `test.as` for gnash, so the
opcode scan is the stronger argument.

**The run.** All 200, graphics, with a temporary log in `arrayForinPushInherited` and
`arrayForinPushUntrackedIndices` that recorded every key they pushed. A row with an empty log is byte-identical by
construction, because the patch only adds pushes. A second pass covered the 61 legacy-0x46 users after the legacy arm
was added. The logs were removed from the final patch.
- **Rows where the patch fires (7):** `avm1/global_proto_decls`, `avm1/global_proto_decls_delete` (proto walk),
  `avm1/text_format_get_text_extent_own` (untracked indices `0,1`), gnash `argstest-v6/7/8` (legacy arm),
  gnash `misc-ming.all/ButtonEventsTest` (an enumerable `Array.prototype.realLength`, but its output is identical).
- **Status vs the s30 CI baseline (`_results/results_graphics.json`)**: all 200 + 61 identical (0 moves).
- **Line-level A/B (clean master vs patch, same box) on the 7 firing rows**: see the ledger. `text_format_get_text_extent_own`
  and `ButtonEventsTest` produce byte-identical output.
- **Mode parity:** all 7 firing rows plus the 6 regression `*array*` rows, re-run on the FINAL code in `--mode=graphics`
  and `--mode=no-graphics`. Outputs are identical between modes and identical to the first after-leg.
- **Regression suite near the change:** `regression/array_element_type1_args`, `array_method_type1_args`,
  `avm1_array_generic_receivers`, `avm1_array_native_own_method`, `avm2_array_growth_bounded`, `avm2_embed_bytearray`:
  pass → pass, both modes. The 3 regression rows with an Enumerate opcode were in the 200 sweep (pass, no fire).
- **Render canary:** scanning `render_canary_tests.txt` (208 non-AVM2 entries; AVM2 rows cannot execute AVM1 opcodes)
  finds only `avm1/movieclip_setmask` and `avm1/netstream_play_flv_screen` with an Enumerate opcode. A
  `render_canary.py capture/compare` on both gives **2/2 IDENTICAL**, with no trace or image status change. I added no
  canary member: the change class is trace-only.

## 3. argstest-v6/7/8: why the diff count goes up, and why I kept it

FP32 (`output.fp32.txt`, the graded golden) DOES enumerate `_global.Stage._listeners`' inherited members:
`testing _global.Stage._listeners.toLocaleString(function)`, `Trying to construct …`, `Object was constructed`, and so on,
for all 9. On master those lines are all missing. With the patch, every one of them appears, matching Flash.

The growth comes after that point. For each member, the test constructs `new f()` and enumerates the instance. FP32
lists the full `Object.prototype` set for the first member only (`toLocaleString`), and only `__constructor__` for the
other 8. Ours lists the full set every time. That is the instance-layout mechanism already measured in w1-native-table §1.5
("extra `Testing <Object.prototype name>()` ≈ 99 each"), owned by **w2-native-instance**. By kind, the +506 extra lines
on v8 are 36 × each of the 11 `Testing <name>()` lines, +40 `testing X(undefined)`, +28 `Testing __constructor__()`,
+28 `Object was constructed`, and +9/+9 `testing X(function)` / `Trying to construct X` (the Flash-correct new lines).

The ruling (Flash over Ruffle; rows graded against FP32) says to keep the Flash-correct enumeration: it matches 70–90
more golden lines and loses no row. If the coordinator prefers to hold the diff count until w2-native-instance lands,
`SWF_ARRAY_FORIN_PROTO_LEGACY=0` disables only this arm. `global_proto_decls` uses Enumerate2 and keeps its gain.

## 4. Refutations / premise checks

- B20a (`array-v5..8` :1630/:1636) is an OBJECT enumeration, not an array one. It is out of this mechanism, and the
  patch does not fire there (log). The two `c.length`/`a.length` checks are also unrelated (`length` semantics).
- The 524-line `_listeners` price on master was mostly reachable: 296 of the 524 lines went. The 228 left are native-table type facts plus the
  own `constructor` (8). The w1 "+ ~160 on `_delete`" price was conservative: on top of the native-table prototype,
  `_delete` falls by 476.
- No other corpus row has an enumerable inherited name on an array in its `for…in` (200-row log sweep). So the
  "touches every for..in over an array" risk the w1 report priced is, in the corpus, 7 rows.

## Could not finish / completion mechanisms

- **FP32 order for the fixture rows (b)–(g).** Completion: the FLASH request below. Then move the fixture into
  `regression/` with the FP32 golden. If FP32 disagrees, adjust `arrayForinPushInherited` (level order) or
  `arrayForinPushUntrackedIndices`.
- **`_listeners` own `constructor`** (HOLD, ~8 lines): see Verdicts; needs fixture rows F/L1 from FP32 first.
- **Re-measure on top of w2-native-table-land** once it lands. I measured on top of the w1 prototype patch; the
  expected deltas are in §2.1.

## New unclaimed leads

- **L-a (S):** `arrayForinOwnsName` and the existing ARRAY-arm lookups use `findPropertyRaw` (case-sensitive). At SWF ≤ 6
  an own `AP` should shadow an inherited `ap`. There is no corpus row for it; a fixture row could pin it.
- **L-b (M, w2-native-instance):** instance enumeration of `new f()` for native functions (argstest: FP32 lists only
  `__constructor__` after the first member). With it, the argstest growth here goes away and the +70–90 matched lines
  remain.
- **L-c (S):** the legacy `actionEnumerate` ARRAY arm ignores DONT_ENUM on indices and does not use `enum_keys`
  insertion order (pushes indices ascending, then props). Enumerate2 has both. No corpus row was seen to diverge, so
  this needs a fixture first (the SWF 5 fixture rows give partial coverage).

## LOCAL ORACLE REQUESTS

- **FLASH: `SWFRecompDocs/plans/session30-fanout-reports/w2-array-forin-proto-fixture/swf6/test.swf`, trace, 1 frame,
  direct.** Also the same for `swf8/test.swf` and `swf5/test.swf` (3 captures). Compare each against `ours_after.txt` in
  the same directory. Rows A0–Z are described in `create_test_swf.py`'s docstring. The key questions are: the order of
  Object.prototype vs Array.prototype inherited names (A2), shadowing (C), literal index position (B), and the own slots
  after `ASSetPropFlags(arr, null, 0, 1)` for `new Array()` (F) and for the AsBroadcaster `_listeners` (L1). One
  capture each is enough: AVM1 for-in order is deterministic. (The FP32 AVM2 for-in nondeterminism does not apply here.)
  Build: `python3 create_test_swf.py <5|6|8> out.swf` (the built SWFs are committed).
