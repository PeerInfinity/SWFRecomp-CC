# SWFRecomp regression suite

Hand-written trace tests owned by this project. Nothing here comes from Ruffle,
Gnash, or Shumway, and `download_tests.sh` never touches this directory — so
every file is plainly git-tracked, including `test.swf`.

That is the whole reason the suite exists. The sibling `avm1/`, `from_gnash/`,
and `from_shumway/` trees are mirrors of upstream projects: `download_tests.sh`
re-syncs them from `ruffle-rs/ruffle` master on every run and `--clean` deletes
their contents outright. Custom tests parked in those trees had to be defended
with a `.gitignore` negation per test (including an explicit `!.../test.swf` to
un-ignore a binary) plus a `git checkout HEAD --` restore step inside the sync
script. Tests that live here need none of that.

## Running

```bash
# one test — `--test` finds the suite that owns the name, no --tests-dir needed
python3 ruffle-tests/verify_output.py --test=fn_call_type1_args --diff --verbose

# whole suite (a few seconds)
python3 ruffle-tests/verify_output.py -v --tests-dir=ruffle-tests/tests/swfs/regression
```

A bare `--test=NAME` searches every suite in `verify_output.py`'s `SUITE_DIRS`.
Names must all resolve to one suite; pass `--tests-dir` to disambiguate.

CI runs it as its own suite alongside `avm1` (gated on the same `RUN_AVM1`
condition), with results in `_results/` and the usual per-mode diff reports.

## Adding a test

Drop in a directory with `test.swf`, `output.txt`, and `test.toml`. Commit all
three — no `.gitignore` edit is needed. Ship the SWF's generator
(`create_test_swf.py`) next to it so the binary is reproducible, and open the
generator's docstring with what the test pins down and which commit fixed it.

Several of these SWFs are hand-assembled bytecode rather than compiler output,
because MTASC emits `DefineFunction2` for SWF6+ and the type-1 (`DefineFunction`)
arms cannot be reached any other way.

## Contents

| Test | Guards |
|---|---|
| `ei_type1_args` | `actionEI_callInternalInterface`'s type-1 arm: forward arg order + pad to `param_count` (fixed `d8abc5c0a`) |
| `ei_closure_scope_order` | `actionEI_callInternalInterface`'s three dispatch quirks — a behavior lock, not a bug repro: local-scope-under-captured (a captured `with(w)` scope shadows the callee's same-named param on lookup), forced `is_with=1` on captured scopes (a `var` in the callee never lands on a captured local frame — the discriminating row; note a plain SetVariable writes THROUGH a with-frame where the property exists, so that row locks write-through, not the force), and the LIVE type-1 `this` bind (`thisObj` readable as `this` at `g_this_depth==0`; `typeof this` is `undefined` when registered with null). Normalizing any of these must flip this test deliberately |
| `mc_event_type1_args` | `mc_call_as2_handler_ng`'s type-1 arm passes the event's arguments at all (fixed `9a8c6dce3`) |
| `timer_cross_swf_version` | `fireTimerCallback` switches to the callback's own SWF version and `_global` group (fixed `60070d96a`) |
| `mc_event_cross_swf_version` | `mc_call_as2_handler_ng` switches to the handler's own SWF version and `_global` group (normalization pass (b): a v6-defined `onSetFocus` handler fired from v7 host bytecode via `Selection.setFocus` ran with v7 undefined-coercion, tracing `cb:[undefined]` instead of `cb:[]`). Two-SWF test (SWF7 host + SWF6 child); the handler crosses movies via `_level0.cb` because per-version `_global` groups are exactly what the switch swaps |
| `broadcast_cross_swf_version` | `builtin_broadcaster_broadcastMessage` switches to each listener's own SWF version (normalization pass (b): a v6-defined listener fired via `broadcastMessage` from v7 host bytecode ran with v7 undefined-coercion). Same two-SWF `_level0.cb` handoff as `mc_event_cross_swf_version` |
| `watch_cross_swf_version` | all THREE watch arms switch to the watcher's own SWF version (normalization pass (b)): Site A (timeline `_root.watch` + SetVariable), Site B (OBJECT `o.watch` + SetMember — its base-clip switch moved into the arm, caller-version gated, to avoid the forbidden `INV_BASE_CLIP\|INV_VERSION_SWITCH` pairing), Site C (MOVIECLIP `m.watch` + SetMember). One v6 DefineFunction2 watcher (Site A fires type-2 only), three rows `va:`/`pb:`/`qc:`; same two-SWF `_level0.cb` handoff |
| `mc_method_v5_caller_gate` | the callee-vs-caller version-gate unification (normalization pass (b) item 3): the MOVIECLIP method arms (+ fireTimerCallback's function form, the enterFrame children arm) now gate their closure behavior on the CALLER's version, per Ruffle's `is_closure = activation.swf_version() >= 6`. A v5 host calls a v7-defined function as `_root.f()` — pre-closure, so it runs at the RECEIVER's (v5) version in the receiver's timeline (`cb:[]`; the old callee gate installed v7 → `cb:[undefined]`). Two-SWF via `loadMovieNum(_level1)` (a v5 host has no createEmptyMovieClip, and a dot-path target root-replaces) |
| `lv_cross_swf_version` | the async-load dispatch family switches to the handler's own SWF version (normalization pass (b)): `fireLoadVarsCallback` (LoadVars.onData row) + `soundFireCallback` (the shared Sound/XML dispatcher — XML.onLoad row); both base-clip switches moved into the arms, caller-version gated. Both drains fire from the frame loop under the ROOT (v7) ambient; same two-SWF `_level0` handoff |
| `ei_cross_swf_version` | `actionEI_callInternalInterface` switches to the callback's own SWF version (normalization pass (b); its base-clip switch moved into the arm, caller-version gated). Single-SWF + harness: a v8-defined callback fired under a harness-injected v6 ambient must keep v8 coercion (`cb:[undefined]`) — polarity INVERTED vs the other cross-version repros because ExternalInterface is version-hidden below SWF8 |
| `coerce_cross_swf_version` | the coercion dispatch paths that lacked a version switch run valueOf/toString at the function's own SWF version (normalization pass (b)): `objectToPrimitive` both legs (Less2 row), `convertFloat` both branches (Subtract row), the oCVO/oCTS getter sub-branches and `call_function_with_this` (same class, no suite-reachable trigger — c_f_w_t's t2 base-clip switch moved into the arm, caller-gated). The oCVO/oCTS MAIN branches already switched and are unchanged. Same two-SWF `_level0` handoff |
| `onconstruct_cross_swf_version` | the onConstruct/onLoad lifecycle dispatcher family switches to the handler's own SWF version (normalization pass (b); both arms' base-clip switches moved into the arm, caller-version gated). The repro row fires `actionDispatchMCOnConstruct` mid-script via `createEmptyMovieClip`; the handler must live on `m0.__proto__` (the REAL prototype — the host's `MovieClip.prototype` names a DIFFERENT object in the loaded-child environment, a pre-existing identity bug). onLoad gets the identical change but has no buildable cross-version trigger (attachMovie-only queue; hand-assembled DefineSprite attachMovie doesn't instantiate here) — its unchanged same-version behavior stays locked by `onload_type1_args` |
| `nc_onstatus_closure` | `nc_dispatch_onStatus` restores the handler's captured scope chain — a behavior lock, not a bug fix |
| `fn_call_type1_args` | `actionCallMethod`'s `.call`/`.apply`-via-GetMember arm: forward arg order + pad (fixed in dispatch Stage 3b) |
| `lc_method_type1_args` | `lc_dispatch_method`'s type-1 arm: forward arg order + clamp/pad (instance ten; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `lc_onstatus_type1_args` | `lc_dispatch_onStatus`'s type-1 arm: clamp/pad the event-object arg to `param_count` (instance eleven; fixed migrating the onStatus family onto `invokeFunctionValue` in dispatch Stage 4) |
| `nc_onstatus_type1_args` | `nc_dispatch_onStatus`'s type-1 arm: clamp/pad the info-object arg to `param_count` (instance twelve; fixed in the same onStatus-family migration) |
| `lv_ondata_type1_args` | `fireLoadVarsCallback`'s type-1 arm: forward arg order + clamp/pad (instance thirteen; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `xml_onload_type1_args` | `soundFireCallback`'s type-1 arm (the shared Sound/XML event dispatcher): forward arg order + clamp/pad (instance fourteen; fixed in the same migration batch) |
| `sort_comparator_type1_args` | `_invoke_sort_comparator`'s type-1 arm: clamp/pad to `param_count` (instance fifteen — a 1-param comparator misbound `b` and leaked a stack slot per comparison into the NEXT sort's comparator; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `timer_type1_args` | `fireTimerCallback`'s two type-1 arms (function-form `setTimeout(f, …)` AND method-form `setTimeout(o, "m", …)` are separate paths): clamp/pad to `param_count` (instance seventeen — the arms pushed forward but a clamped row stranded an operand on the AVM1 stack that corrupted the NEXT callback's pad pop; fixed migrating `fireTimerCallback` onto `invokeFunctionValue` via the exported `actionInvokeFunctionValue` in dispatch Stage 4). The 2-arg rows are deliberate order locks (passed before the fix) |
| `watch_setmember_type1_args` | `actionSetMember`'s OBJECT-receiver watch arm (Site B), type-1 callee: clamp/pad to `param_count` (instance eighteen — the canonical 3-param watcher `function(prop, oldV, newV)` got 4 pushed, binding every arg off by one AND stranding the name string on the caller's eval stack; a 5-param watcher's 5th param popped the caller's SENTINEL). Also pins return-value-becomes-new-value through a defined return; the undefined-return fold (D1) is deliberately NOT asserted |
| `watch_mc_type1_args` | `actionSetMember`'s MOVIECLIP-receiver watch arm (Site C), type-1 callee: clamp/pad (instance eighteen's sibling arm — a 4-param watcher's first param popped a stale caller slot). Locks the preserved userData DROP (the `ud` param pads to undefined, NOT the registered value — flipping that to `UD` is the D6 normalization commit) and return-becomes-value on the MC arm |
| `watch_mc_reentrant_setmember` | the MOVIECLIP watch arm (Site C) read `prop_name` off actionSetMember's static `_sm_buf` AFTER the watcher call — a SetMember inside the watcher clobbered it, storing the assignment under the wrong name (a `this.side="S"` watcher made `m.p="x"` store under `"s"`, leaving `m.p` undefined). Fixed by copying the name to an arm-level buffer before invoking (the OBJECT arm's existing discipline) |
| `watch_timeline_named_params` | the timeline watch arm (Site A) passed the property-name arg OWNING and freed it unconditionally — a NAMED-param (non-register-preloaded) DefineFunction2 watcher's prologue pointer-shares args into its local frame, whose release freed the string first: double-free, glibc abort mid-frame. Fixed by adopting the OBJECT arm's non-owning + never-freed (leak-over-dangle) discipline; the `stash=tv` line pins the no-dangle side |
| `enterframe_type1_args` | the enterFrame dispatch family's type-1 arms (children + root) — a behavior lock, not a bug repro: the missing type-1 pad is INERT here (frame-loop dispatch runs on an empty eval stack whose guarded pop already synthesized undefined — A/B-verified identical, typeof included). Locks undefined params (value + typeof), one deterministic fire per handler, children-before-root order, and explicit-path self-disable. NOTE a type-1 handler has NO `this` channel on these arms — `this` falls back through base_clip to `_root` (the first draft of this test killed the root handler that way) |
| `coerce_type1_args` | the coercion paths' (`objectCallValueOf` / `objectToPrimitive` / `convertFloat` / `objectCallToString`) type-1 arms: pad to `param_count` (instance sixteen, one instance for the family — all four sites pushed nothing, so a 2-param valueOf's prologue popped the caller's live stack, including the operand under conversion in `convertFloat`; fixed migrating the family onto `invokeFunctionValue` in dispatch Stage 4) |
| `onconstruct_type1_args` | `actionDispatchMCOnConstruct`'s type-1 arm: pad to `param_count` (instance nineteen — unlike its onLoad sibling this dispatcher fires MID-SCRIPT from inside `createEmptyMovieClip`, so a param'd type-1 `MovieClip.prototype.onConstruct` handler's prologue popped the caller's in-progress expression operands: `trace("X: " + createEmptyMovieClip(...))` had its `"X: "` swallowed into the handler's last param and the outer concat corrupted to `NaN`; fixed migrating onLoad+onConstruct onto `invokeFunctionValue` in dispatch Stage 4) |
| `onload_type1_args` | `actionDispatchMCOnLoad`'s type-1 ritual — a behavior lock, not a bug repro: the missing pad is INERT here (queue-drain / after-first-frame dispatch runs on an empty eval stack whose guarded pop already synthesized undefined — A/B-verified identical). Locks undefined params (value + typeof), single fire, and that a type-1 onLoad handler DOES have a `this` channel (`this=_level0` via the arm's this-stack push — richer than the enterFrame arms, which have none) |
| `onunload_type1_args` | the synchronous `mc.unloadMovie()` onUnload site's type-1 callee: pad to `param_count` (instance twenty — six of the EIGHT onUnload firing sites run MID-SCRIPT, and the handler's prologue popped the caller's in-flight expression operands; the theft is invisible in the param rows because `invokeSpecialFunction`'s type-1 path pushes no local frame so the binds land ambiently — the discriminator is the OUTER expression, `0` before vs `X: ` after; fixed migrating all eight sites onto `invokeFunctionValue` via the shared `invokeUnloadHandler` adapter in dispatch Stage 4) |
| `broadcast_type1_args` | `builtin_broadcaster_broadcastMessage`'s type-1 listener arm: CLAMP to `param_count` (instance twenty-one — the arm pushed forward and padded but did NOT clamp, so a 3-extra broadcast to a 2-param listener bound `a=x2 b=x3` and stranded `x1` on the caller's value stack, surfacing as `x1true` in the surrounding expression; multi-arg broadcasts are real in-tree: Selection 2 extras, Stage onFullScreen 1, MCL onLoadProgress/onLoadError 2; fixed migrating the listener loop onto `invokeFunctionValue` + the `super_bind` core extension in dispatch Stage 4). bc1/bc2 rows are order/pad locks (passed before the fix); the type-1 super shadow is separately pinned by gnash `AsBroadcaster-v6` (byte-diffed old-vs-new across the migration) |
