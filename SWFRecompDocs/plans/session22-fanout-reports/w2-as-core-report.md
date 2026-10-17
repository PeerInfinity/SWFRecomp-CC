# s22 wave 2 — `w2-as-core`: AS-semantics helper layer + AsBroadcaster / ContextMenu / ContextMenuItem / AsSetupError ports + M5

**New files in this commit:**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-as-core-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-as-core.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; one file touched, `SWFModernRuntime/src/actionmodern/action.c`; proven with `git apply --check -R`)

No new source files, no new fixtures, no recompiler change, no `render_canary_tests.txt` change.

**Setup:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Base `origin/master` = `b492a86e`.
`download_tests.sh avm1 from_gnash` (+ `avm2 fonts from_shumway text visual` for the canary), upstream
Ruffle master at download time; Ruffle clone at **`45366370e`**. All A/B rows below are on this box,
clean `origin/master` vs this patch, `--mode=graphics` (lavapipe) unless marked no-graphics.

## TL;DR — GO, 7 trace flips now + 1 more when `w2-array-global` lands

| verdict | tests |
|---|---|
| **flips to pass (this patch alone)** | `avm1/as_setup_error`, `avm1/context_menu`, `avm1/context_menu_item`, `avm1/context_menu_swf6`, gnash `AsBroadcaster-v6`, `-v7`, `-v8` |
| **311/312, flips with sibling `w2-array-global` (M3)** | `avm1/as_broadcaster`. The single remaining line is output.txt:107 (`// … with Array replaced` → `true`: `[]` must take `_global.Array.prototype`), which is exactly M3. **Yes: it passes with that one line excepted.** |
| pixel axis | **no movement** (none of these tests has image comparisons; canary 102/102 PNGs md5-identical) |

`as_setup_error` is a full **pass**, not ruffle_matched: `Error` resolves through the caller's
scope chain, so the Flash-only `new _root.Error()` row (the one Ruffle misses; test is `known_failure`
with `output.ruffle.txt`) matches. A KF test moving to `pass` is the Flash-correct outcome, not a
`pass → ruffle_matched` regression.

## Per-test before/after (same box)

| test | before (clean master) | after, graphics | after, no-graphics |
|---|---|---|---|
| avm1/as_broadcaster | fail 106/312 | fail **311/312** (only line 107 = M3) | fail 311/312 |
| avm1/as_setup_error | fail 11/52 | **pass 52/52** | pass 52/52 |
| avm1/context_menu | fail 49/128 | **pass 128/128** | pass 128/128 |
| avm1/context_menu_item | fail 61/96 | **pass 96/96** | pass 96/96 |
| avm1/context_menu_swf6 | fail 11/14 | **pass 14/14** | pass 14/14 |
| gnash AsBroadcaster-v5 | pass 11/11 | pass 11/11 | pass 11/11 |
| gnash AsBroadcaster-v6 | fail 114/121 | **pass 121/121** | pass 121/121 |
| gnash AsBroadcaster-v7 | fail 114/121 | **pass 121/121** | pass 121/121 |
| gnash AsBroadcaster-v8 | fail 114/121 | **pass 121/121** | pass 121/121 |
| gnash ContextMenu-v5 / v6 / v7 / v8 | pass 7 / 7 / 131 / 131 | pass (same) | pass (same) |
| gnash Function-v5 | ruffle_matched 148/158 | ruffle_matched 148/158 | ruffle_matched 148/158 |
| gnash Function-v6 / v7 / v8 | pass 271 / 272 / 272 | pass (same) | pass (same) |

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

Trace axis (both modes):
- `avm1/as_setup_error`: absent from the 10-03 graphics results (new test) / fail 11/52 on the 10-11 weekly → **pass**.
- `avm1/context_menu`: CI graphics file still shows the OLD 39-line test as pass; on the rewritten
  128-line test it is fail 49/128 → **pass**. (Pass → fail → pass across drift; net vs the s21 baseline: 0, vs the current corpus: +1.)
- `avm1/context_menu_item`: same story, fail 61/96 → **pass**.
- `avm1/context_menu_swf6`: new test, fail 11/14 → **pass**.
- gnash `actionscript.all/AsBroadcaster-v6`, `-v7`, `-v8`: ruffle_matched 114/121 in the 10-03 file
  (old corpus, `known_failure` since removed upstream; on the current corpus fail 114/121) → **pass**.
- `avm1/as_broadcaster`: CI graphics file shows the OLD 41-line test as pass; current corpus fail
  106/312 → still **fail 311/312** with this patch; **pass** once `w2-array-global` (M3) is also in.

Expected NON-moves that will still look like moves in CI (upstream drift, not this patch):
- gnash `array-v6`, `array-v8` (and `-v7`): `ruffle_matched → output_mismatch` with **identical
  matched lines on both legs** (629/644, 640/654) — upstream `dd4e73d59` rewrote their `.fp*.ruffle.txt`.
  Confirmed on clean master on this box. Owner: `w2-array-global` (S2).

Pixel axis: **none**.

## What the patch does (`action.c`, all inside existing functions or new `static` symbols)

### 1. The AS-semantics helper layer (`action.c:2884-3173`, one delimited block)

A `static` layer of thin wrappers over the VM's own stack ops, with a header comment documenting each
contract for `w2-geom-port` to reuse:
`as_undef/as_num/as_bool/as_str`, `as_is_object`, `as_this(this_obj)`,
`as_get` / `as_get_index` / `as_set` (ActionGetMember/SetMember: getters, setters, `__resolve`,
watchers fire), `as_call_method` (ActionCallMethod: dispatch through the object, primitives boxed),
`as_get_global`, `as_new_global` (`new _global[name]()` on the CURRENT global via NewMethod, re-resolved
per call), `as_new_value` (`new ctor()` via blank-name NewMethod), `as_new_scoped` (Flash-order
lookup: scope entries innermost-first → current timeline → current `_global`, then construct the value),
`as_equals` (Equals2), `as_less` (Less2), `as_add` (Add2; unused here, kept for geom), `as_set_prop_flags`.
Everything pushes with `pushVar` (no inline `PUSH` of the count — see the GCC-reordering note at the
String arm). Defined early (before the geom natives at ~10.4k) so the geom port needs no forward decls.

Contract caveat for reusers (documented in the block): `as_this` trusts `g_call_this_type` to mean
"this_obj is an ASArray"; the script dispatch arms set it for a native callee, but a builtin also
called directly from C with an ASObject must not use `as_this` (that is why broadcastMessage has
two entries, below).

### 2. AsBroadcaster (port of `AsBroadcaster.as`)
- `addListener` (`:37339`): `this.removeListener(l)`; `this._listeners.push(l)`; `return true` — both dispatched.
- `removeListener` (`:37358`): `length` re-read each iteration via Less2, elements via GetMember,
  `==` via Equals2, `listeners.splice(i, 1)` dispatched.
- `initialize` (`:39686`): sets `broadcastMessage` (a **fresh** native per call), then
  `AsBroadcaster.addListener` / `.removeListener` (re-read from the current `_global` each time), then
  `_listeners = []` (built by `actionInitArray`, so M3 applies automatically when S2 lands), then
  `ASSetPropFlags(…, 3)`. Keeps the stale-MovieClip rebinding (gnash AsBroadcaster.as:173).
- `broadcastMessage` (`broadcastMessageCore`, `:37438`) = `ASnative(101,12)`: `this._listeners` via a
  real get; non-object → undefined; listeners **snapshotted up front** from own data props (`length` and
  indices, no getters/proto — Ruffle `get_data`), so self/later removal mid-broadcast still calls them;
  null/undefined skipped and not counted; primitives boxed through the primitive CallMethod arms;
  returns `true` iff any non-null listener, else undefined. The per-listener invocation block (super
  context, version switch, MC listeners) is unchanged.
  Two entries: `builtin_broadcaster_broadcastMessage` (the runtime's own C callers: Key/Mouse/Selection/
  MCL/TextField/FileReference dispatch — OBJECT receiver, never consults `g_call_this_type`) and
  `builtin_broadcaster_broadcastMessage_as` (script-visible function objects).
- `ASnative(101, 12)` now returns a fresh broadcastMessage native (`newBroadcastMessageFunc`, `:7651`).

### 3. ContextMenu / ContextMenuItem (ports of `ContextMenu.as`, `ContextMenuItem.as`)
- The stub ctors `g_stub_ctors[4]/[5]` become type-2 with real bodies (`:3228`, `:3247`), so they run
  under `new` (NewObject and NewMethod) **and** when called as functions (`ContextMenuItem.call(obj,…)`).
  The old post-construction arms in `actionNewObject` are removed.
- ContextMenu: `onSelect` raw; `builtInItems` literal (never calls `_global.Object`); `customItems = new Array()` via the global.
- ContextMenuItem: caption/onSelect raw; `x == null ? default : x` for the 3 booleans.
- `copy()` (both) constructs through the global ctor, reads/writes every property through getters/setters
  in AS order, dispatches `customItems.push` and each `item.copy()`; `hideBuiltInItems` assigns through setters.
- Prototype flags `ASSetPropFlags(proto, "copy[,hideBuiltInItems]", 1027)` (hidden below SWF7 — all 3
  context_menu_swf6 lines). Applied to the method names only, not `constructor`/`__proto__` (Ruffle's
  `null` would hide those too; no test row distinguishes it, and hiding `__proto__` in our runtime risks
  breaking proto walks).

### 4. AsSetupError (`:5591`, port of Error.as)
`names.split(",")` dispatched; `length`/index through getters; `new Error()` per name via
`as_new_scoped` (caller's chain, so `_root.Error` wins; a replaced `_global.Error` is re-resolved each
iteration); `name` then `message`. Function becomes type 2 so the body runs.

### 5. M5 — closures keep their captured scope (the brief's two sites + four sibling arms)
Brief sites, as in the w1 prototype: `INV_CAPTURED_SCOPE` on `actionCallMethod`'s object-method arm
(`:69962`), `INV_CAPTURED_SCOPE|INV_LOCAL_SCOPE` on `objectToPrimitive`'s valueOf (`:15843`). Stale
"never done"/"load-bearing asymmetry" comments updated. **No `CF_RESET_SCOPE`.**

Attacking the brief's premise that two sites suffice: the headline rows needed the **same bug fixed in
four more invocation arms**, each proven by a specific line (all were dropping the callee's captured
scopes, so the test harness's `tracingMethod`/`tracingConstructor` closures printed `undefined.removeListener`
/ `new undefined()` by resolving `name`/`method` against the caller's globals):
- String-primitive user-method arm (`:70447`) and `primNumBoolCallProtoMethod` (`:68878`) — as_broadcaster 277-282 (`call String/Number/Boolean.prototype.event1()`).
- Array user-method arm (`:70255`, type-2 only) — as_broadcaster 127 (`call listeners.push`).
- Both `actionNewMethod` type-2 constructor paths (`:60113`, `:60733`) — context_menu 47/103-104 (`new Array()` via a replaced `_global.Array`).

### 6. Array CallMethod dispatch (needed by as_broadcaster 127, context_menu 93/98)
In `actionCallMethod`'s Array arm (`:70177`): an **own** function property (`arr.push = fn`) or a
**script-defined** function on the array's prototype chain (`Array.prototype.push = fn`; natives carry
`swf_version == 0`) now wins over the native fast path, as for any object in Flash. In that arm a type-2
script callee gets `INV_OVERRIDE_THIS` so a preloaded `this` keeps the ARRAY tag (pre-existing bug: the
prologue wrapped the raw `ASArray*` as OBJECT, which crashed `original.apply(this, arguments)` in
`objectToTempArray`); a native callee gets `g_call_this_type = ARRAY` instead (no override flag, which
would leak into a nested callback such as a sort comparator).

## Regression / sweep evidence

- **`regression/` suite** (graphics): all **38** dispatch/closure/scope/method/coerce/type1/broadcast/
  array/ctor members (every name matching `closure|scope|method|coerce|type1|broadcast|caller|valueof|listener|context|asnative|array_|apply|call|ctor|new`, which includes the w1 report's 13): **38/38 pass**, on the final tree.
- **Argued corpus sweep, 53 rows** (graphics; families sharing the touched arms): avm1 `array_*`(6),
  `call_method_empty_name`, `closure_scope`, `constructor_function`, `custom_clip_methods`,
  `*_asbroadcaster`(4), `mouse_listeners`, `key_isToggled`, `new_method_wrap`, `new_object_wrap`,
  `new_class_prototype_getter`, `mutable_this`, `string_methods`, `swf5_no_closure`, `this_scoping`,
  `this_swf6`, `super_edge_cases`, `as2_super_and_this_v8`, `removed_clip_function_scope`, `error`,
  `movieclip_prototype_extension`, `get_variable_in_scope`, `with_variable_scopes`, `button_key_events`,
  `stage_object_properties`, `selection_handlers`; gnash `array-v6/v8`, `Key-v6`, `Mouse-v6`,
  `MovieClipLoader-v7`, `Selection-v7`, `Stage-v7`, `TextField-v7`, `Error-v7`, `Object-v7`,
  `Inheritance-v7`, `String-v7`, `Number-v7`, `Boolean-v7`, `with-v7`, `getvariable-v7`, `ops-v7`,
  `delete-v7`, `Function-v5`. **Every row identical (status and matched/expected lines) to the CI
  graphics results files**, except the ledger rows and the array-v6/v8 drift above. Re-run on the final
  tree: identical.
- **Globals sweep, 18 rows, A/B on this box** (function-type and prototype-flag changes could show in
  enumeration tests): `asnative`, `global_instance_decls`, `global_proto_decls(_delete)`,
  `globals_monkeypatch`, `globals_swf5..8`, `global_swf6_7_8`, `global_swf5_6_7_8_9`, `typeof(_globals)`,
  `swf5/6/7_global_funcs`, `as_set_prop_flags`, `global_array`: **identical before/after** (the 5 IGN fails keep exactly their matched counts).
- **gnash `Function-v5..v8`**: unchanged (above).
- **No-graphics** headline pass: identical to graphics (table above).
- **Graphics canary** (`render_canary.py`, 60 tests / 102 PNGs over `render_canary_tests.txt`):
  **IDENTICAL 102, DIFFERS 0**, no trace or image status changes. Captured before the last edit, which
  only narrows the Array arm's `INV_OVERRIDE_THIS` to script callees (no render path); the headline set,
  the 6 `array_*` rows and 4 array/sort regression members were re-run after it, unchanged.

CI recommendation (brief): `categories=full`, both modes — M5 touches every closure invoked as a method.

## Not done / HOLD (with completion mechanism)

- **`CF_RESET_SCOPE`** on the method arms (hide the caller's chain under the captured frames, as Flash
  does): left out per brief. Completion: follow-up slot, measured separately with `categories=full`.
- **`AsBroadcaster` object flags 131**: the AsBroadcaster function's own `broadcastMessage/addListener/removeListener` stay DONT_ENUM|DONT_DELETE with only `initialize` SWF6-gated (pre-existing). No test row distinguishes it (globals_swf5 is IGN). Completion: fold into whoever next touches globals_swf5.
- **Built-in broadcasters share one `broadcastMessage` function object** (Key/Mouse/Stage/…): Flash
  runs `AsBroadcaster.initialize` on each, giving distinct natives. No test checks identity among them.
- **`as_new_scoped` and with-objects**: it reads scope entries with a full get, so a `with` object's
  `__resolve` would answer. Flash's scope lookup checks `has_property` first. No row exercises it.

## Refutations / premise checks
- "M5 = two sites": refuted, see §5 (four more arms, each pinned by a headline line).
- "AsBroadcaster needs only the port": also needed the Array arm's own-method/proto-override dispatch and
  its ARRAY-tagged `this` (§6) — a latent crash (`arr.push = wrapper; wrapper → original.apply(this, …)`)
  any game with an Array method wrapper could hit.
- "AsSetupError: matching Flash needs the caller's chain": confirmed, and `ActionNewObject`/`ActionGetVariable` are unusable for it (both short-circuit `Error` to a native, see leads).

## New unclaimed leads
1. **`ActionGetVariable("Error")` ignores a replaced `_global.Error`**: it returns a fast-path static
   (`action.c` ~46680, `_CMP_BUILTIN_NAME(var_name, "Error")`) that is not even the same object as the
   initial `_global.Error` (`g_error_ctor`); only a timeline binding beats it. `actionNewObject("Error")`
   short-circuits the same way (~58712). User code `_global.Error = F; new Error()` / `var e = Error`
   likely misbehaves; other builtin names in that block may too. Not exercised by a failing row I know of.
2. **`actionNewMethod`'s user-constructor paths** (`new obj.Ctor()`) also skip the g_this_stack push and
   the "constructor returned an object" override that `actionNewObject` has (seen while adding M5).
3. **Array arm still calls natives first for arrays whose `__proto__` lacks the method** (e.g.
   `arr.__proto__ = Object.prototype; arr.push(1)` should be a no-op in Flash).

## LOCAL ORACLE REQUESTS
1. (Optional, same as w1 request 2) Ruffle-exporter output for a closure-as-method `regression/` fixture
   (`function mk(n){ var o={}; o.f=function(){ trace(n); }; o.valueOf=function(){ trace("v"+n); return 1; }; return o; } var a=mk("A"); a.f(); trace(a==1);`, expected `A`, `vA`, `true`). Not needed for grading: every M5/§6 change is already pinned by a corpus row (as_broadcaster 127/187/277-282, context_menu 47/93/98/103-104).
