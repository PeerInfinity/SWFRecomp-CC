# s28 w2-root-onload-proto: report (wave 2, implementation)

## NEW files (all on `fanout/w2-root-onload-proto`)

- `SWFRecompDocs/plans/session28-fanout-reports/w2-root-onload-proto-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-root-onload-proto.patch` (the deliverable, `git apply`-able on `origin/master`)
- `ruffle-tests/tests/swfs/regression/avm1_root_onload_proto/{test.swf,test.toml,output.txt,create_test_swf.py}`
- `ruffle-tests/tests/swfs/regression/avm1_root_onload_child_order/{test.swf,test.toml,output.txt,create_test_swf.py}`
- `SWFRecompDocs/plans/session28-fanout-reports/w2-root-onload-proto-fixtures/create_variant_swfs.py` + `v1..v6/{test.swf,test.toml,output.txt}`
  (Flash-request variants; `output.txt` there is a placeholder `x`, NOT a golden. Not in the patch.)

Modified: `SWFModernRuntime/src/actionmodern/action.c` (functions below), `ruffle-tests/tests/swfs/regression/README.md`
(2 rows appended at EOF). Both are in the patch. No recompiler change, no `verify_output.py` change, no
`render_canary_tests.txt` change.

Box: cloud, Dawn/lavapipe OK (`SETUP_STATUS` all OK). Categories downloaded: `avm1 from_gnash from_shumway` (upstream
master at download time = `c2f7d24b7`, same as w1-drift). Ruffle source read at `c2f7d24b7` (contains `fa93ad79f`).

## Verdict (lead)

**GO, +2 new regression rows, 0 corpus moves.**

| row | clean `origin/master` (GR / NG) | patch (GR / NG) |
|---|---|---|
| `regression/avm1_root_onload_proto` (NEW, Flash golden) | output_mismatch / output_mismatch | **PASS / PASS** |
| `regression/avm1_root_onload_child_order` (NEW, Flash golden) | PASS / PASS | PASS / PASS |

Both fixtures now equal the Flash 32 `--no-pin` captures in both modes. The patch changes behaviour only when a
function is reachable as `onLoad` from `MovieClip.prototype` (own or via `Object.prototype`) at the end of the root's
first frame; no corpus row does that (gate below), so the expected corpus delta is zero.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

Trace axis:
- `regression/avm1_root_onload_proto`: **new row, PASS** (graphics and no-graphics).
- `regression/avm1_root_onload_child_order`: **new row, PASS** (graphics and no-graphics).
- Everything else: **no move.** Upstream drift you will see in the same read and must not book against this patch
  (both from `w1-drift-report.md`): `from_gnash/misc-ming.all/action_order/action_execution_order_test4`
  ruffle_matched → output_mismatch, and `avm1/root_onload_loaded_level` new row, pass. Both reproduce here with and
  without the patch.

Pixel axis: **no move.** Neither new row has `[image_comparisons]`; the change is a trace-only event dispatch.

## Mechanism

### Line 2: `proto onLoad _level0` (understood; fixed)

`actionDispatchRootOnLoad` (`action.c`, called once at the end of the first `tagShowFrame`, `tag.c:11183`) delegated
to `actionDispatchMCOnLoad`. That looks up `onLoad` with `getPropertyWithPrototype` on `root_movieclip.dynamic_props`
and then on the root's timeline var map. The root's `dynamic_props` are allocated **lazily**: a root with no own
property has none, so there was no `__proto__` link to walk, and a frame-1 `MovieClip.prototype.onLoad = f` was never
seen. `actionDispatchMCOnConstruct` already has a fallback for this lazy slot (it reads
`getMovieClipPrototype(ver)` directly); the root onLoad had none.

Fix: `actionDispatchRootOnLoad` resolves the own handler first (dynamic_props chain, then the timeline var map, the
same order as before). If there is none, it calls the handler that `MovieClip.prototype` resolves. Own handlers still
win, and when there is no prototype handler the old path (`actionDispatchMCOnLoad`) runs unchanged.

### Line 1: `proto onLoad _global` (receiver NOT identified; modelled by what Flash prints)

What the evidence rules out (cloud reasoning; `v4_this_probe` below is the Flash request that settles it):
- **It is not the `_global` object.** Flash's `_global` has no `toString`/`valueOf` (gnash `Global.as:72`:
  `typeof(_global.toString) == 'undefined'`, a Flash golden), and our runtime models that: `"g " + _global` traces
  `g undefined` here, and `trace(_global)` traces `[type Object]`. Flash's `_global` also has no `__proto__`
  (`Global.as:71`), so a lookup on it can never reach `MovieClip.prototype.onLoad`.
- **It is not a second load dispatch on `_level0`.** `avm1/root_onload` (own `this.onLoad`, Flash golden, re-captured
  `--no-pin` by the coordinator) prints its handler exactly once. If Flash dispatched the root's load twice, an own
  handler would fire twice.
- **What fits all data:** a second receiver that inherits `MovieClip.prototype` (so it finds the prototype handler but
  not `_level0`'s own handler), stringifies as `_global` (MovieClip-style target-path stringification), and gets a load
  event just before `_level0`'s at the initial root's load. The plain timeline clips `a`/`b` get nothing, which agrees
  with Flash's "no clip events / no class → no onLoad" rule that we already model. My best guess is a hidden
  player-level clip, perhaps something that only the projector has. That is **a guess, not a finding.**

Implementation (`rootOnLoadProtoPseudoReceiver`, new `static` in `action.c`): if `MovieClip.prototype` resolves an
`onLoad` function at the root's load event, call it once **before** the root's own dispatch, with `this` = the
**string** `"_global"`. Type-1 handlers get it through the this-stack and the local `this` binding. Type-2 handlers
get it through `g_override_this` (`INV_OVERRIDE_THIS`), the route `Function.call/apply` already use for a primitive
thisArg, so a DefineFunction2 preload-this sees it too (`v6`). The flags otherwise mirror the onLoad dispatcher
(captured scope, local scope, version switch, caller-gated base-clip switch). This reproduces every line Flash
printed. It will be **wrong on `typeof this`** (`string`; Flash probably says `movieclip`) and on property reads
(`this._name` etc.). The v4 Flash request measures exactly those, and the completion mechanism is to swap the string
for whatever v4 shows.

### Functions touched (all in `SWFModernRuntime/src/actionmodern/action.c`)

- `actionDispatchRootOnLoad`: rewritten as described above (`g_root_onload_fired` once-guard unchanged).
- `actionDispatchMCOnLoad`: its invoke half was split out, unchanged, into the new `static void
  actionInvokeMCOnLoadFunc(app_context, mc, func)`, with a forward declaration above it. The lookup half and every
  other caller (`aq_dispatch_mc_onload` for attachMovie/createEmptyMovieClip, the RegisterClass sprites) behave as
  before: the body is byte-identical apart from the split.
- `rootOnLoadProtoPseudoReceiver`: new `static`.

No `swf_core.c`/`tag_stubs.c`/`#ifdef NO_GRAPHICS` code was touched. Mode parity was checked on both fixtures and
the 19-row regression check anyway.

## Evidence

### Headline (same box; before = clean `origin/master` via `git apply -R`)

`avm1_root_onload_proto`, before (GR == NG):
```
f1 of _level0.a / root f1 / f1 of _level0.b / root f2 / root f3 stop
```
After (GR == NG) = the Flash golden:
```
f1 of _level0.a / root f1 / proto onLoad _global / proto onLoad _level0 / f1 of _level0.b / root f2 / root f3 stop
```

### Regression-suite check (19 rows near the change, graphics AND no-graphics, before and after)

`avm1_attach_from_stopped_root_enterframe, avm1_closure_base_clip_root_frame, avm1_loaded_bare_goto_seq,
avm1_loaded_shell_consumers_seq, avm1_loaded_shell_root_lookup, avm1_loaded_timeline_holder,
avm1_loaded_unload_deferred, avm1_mcl_holder_totalframes, avm1_mcl_load_tick, avm1_root_identity_and_playhead,
avm1_root_onload_child_order, avm1_root_onload_proto, onconstruct_cross_swf_version, onconstruct_type1_args,
onload_type1_args, onunload_type1_args, onunload_type1_local_frame, root_enterframe_cross_swf_version,
xml_onload_type1_args`

- before: 18/19 in each mode (only `avm1_root_onload_proto` fails)
- after: **19/19 in each mode**

### onLoad corpus gate (graphics, the CI mode)

**Scope argument:** the new code runs only when `MovieClip.prototype` resolves `onLoad`, so a row can move only if
its SWF writes an `onLoad` onto a prototype. I byte-scanned every non-AS3 SWF in avm1 + from_gnash + from_shumway +
regression (zlib-inflated) for `onLoad` AND (`prototype` OR `__proto__`). That gives 54 test dirs, and I added the 4
rows the brief names (`avm1/root_onload`, `avm1/root_onload_loaded_level`, gnash
`misc-swfmill.all/trace-as2/root_onload`, `action_execution_order_test4`, which was already a hit), for **57 rows** (shumway had no hit). This
is a superset of the brief's "pass-now onLoad/MCL rows that could be affected".

| suite | rows | after-patch status | vs `origin/master` committed CI results |
|---|---|---|---|
| avm1 | 21 | 21 pass | 0 moves (+ `root_onload_loaded_level` new upstream row, pass: drift) |
| from_gnash | 34 | 9 pass, 18 ruffle_matched, 7 output_mismatch | 0 moves except `action_execution_order_test4` ruffle_matched → mismatch (**upstream drift**, w1-drift) |
| regression | 2 | 2 pass | 0 moves |

The 7 gnash mismatches are all baseline failures: `ActionOrderTest3/4/5`, `action_execution_order_extend_test`,
`test11`, `test4` (the §27.4 interleave family) and `RegisterClassTest4`. For those 7 I ran clean `origin/master`
and the patch with `--diff`: the diff text is **byte-identical** (`IDENTICAL_DIFFS`).

### Graphics canary: not run (argued)

The standing set has 813 members and needs categories this slot did not download. The change is an AVM1 event
dispatch that fires only when a prototype `onLoad` exists at root load. No canary member is in the 57-row gate set
(intersection empty), so on any canary row the new code is dead and the old `actionDispatchMCOnLoad` path runs
byte-identically. CI's graphics run is the backstop. I appended no canary member, because the change has no render
side.

## Refutations / premise checks

- **Brief premise "`proto onLoad _global` is a second call whose `this` stringifies as `_global`": accepted, but the
  receiver is not `_global`** (see Mechanism, line 1). Of the brief's candidates, "second load dispatch with
  no/wrong `this`" and "root Load firing on a non-clip" are refuted by `avm1/root_onload`'s single call and by
  `_global`'s missing `__proto__`/`toString`. "The `_global`-bound activation of a prototype function" is refuted by
  stringification: our model of Flash gives `undefined` for `"" + _global`.
- **w1-drift's "Ruffle may also fire it for `b`".** Flash does not: no `_level0.a`/`_level0.b` line. We already
  matched that.
- **The default pinned harness cannot grade these rows.** The test.toml of each new row says so (as the brief
  requires).

## RvF entry: DRAFT (append to `RUFFLE_VS_FLASH_DIFFERENCES.md` once the Ruffle run below confirms it)

> ### `regression/avm1_root_onload_proto`: `MovieClip.prototype.onLoad` at the initial root's load event
> **Flash 32 (direct, `--no-pin`):** `f1 of _level0.a / root f1 / proto onLoad _global / proto onLoad _level0 /
> f1 of _level0.b / root f2 / root f3 stop`.
> **Ruffle (`fa93ad79f`+, reasoned from source, unverified):** `run_frame_avm1` dispatches `ClipEvent::Load` on the
> initial root after `run_frame_internal`, and `event_dispatch` queues `ActionType::Method{onLoad}`, which resolves
> through the prototype at execution time, so `proto onLoad _level0` prints. Ruffle has no `_global`-stringifying
> receiver, so the `proto onLoad _global` line is missing. Ruffle also dispatches `Load` + `Method onLoad` for every
> AVM1 clip with no clip-event/class gate (`should_fire_event_handlers` gates only on SWF version < 6 and key events).
> So `b` (placed in f2, after the prototype exists) most likely prints `proto onLoad _level0.b`. `a`'s queued method
> most likely runs before the root's f1 DoAction defines the prototype, and prints nothing.
> **Decision:** match Flash (golden = Flash capture; the row is ours, not upstream).

## Not finished / completion mechanisms

1. **The identity of the `_global` receiver.** It is modelled as the string `"_global"`. Completion: the coordinator
   runs FLASH request v4 (and v1/v3/v6) below. If v4 shows `typeof this = movieclip` with real `_name`/`_target`/
   `_parent` values, replace the string in `rootOnLoadProtoPseudoReceiver` with a matching object. If v1 shows the
   `_global` line absent when the root has an own handler, gate the extra call on `own_fn == NULL`. That is a
   one-line move of the call below the own-handler lookup.
2. **Ruffle's real output for the fixture.** The RvF entry above is reasoned only. Completion: a Ruffle exporter or
   runner at ≥ `fa93ad79f` (request R1).

## New unclaimed leads

- **Our `"x" + _global` gives `x undefined`, and `trace(_global)` gives `[type Object]`.** These are consistent with
  Flash's missing `toString`/`valueOf`, but no Flash golden traces `_global` directly. It is cheap to add to a Flash
  batch (one line in the v4 SWF already covers `this == _global`). No row depends on it today.
- **`actionDispatchMCOnLoad` has the same lazy-`dynamic_props` blind spot for attachMovie'd/created clips.** A clip
  with no own property misses a `MovieClip.prototype.onLoad`. Whether Flash fires a prototype onLoad for those is a
  separate Flash question (Flash's "no clip events / no class → no onLoad" rule may already make it a non-issue for
  timeline clips, but attachMovie'd clips do get onLoad). No corpus row today. Size S once Flash answers.

## LOCAL ORACLE REQUESTS

All variants are SWF8 (v5 is SWF6), 3 frames, `num_ticks = 4`. Build them with
`python3 SWFRecompDocs/plans/session28-fanout-reports/w2-root-onload-proto-fixtures/create_variant_swfs.py <out>`
(deterministic; the built SWFs are also committed next to it, md5 below). **All FLASH runs: `run_trace.py --no-pin`
(test = first root), direct, never pinned, never `--wrapped`.** Ignore lines past `root f3 stop`.

| id | fixture | md5 | question | ours (patch) |
|---|---|---|---|---|
| F-v4 | `v4_this_probe` | `fd912d4c…` | **the key one.** For the `_global` call: `typeof this`, `this == _global`, `this == _level0`, `this._name/_target/_parent/_url`, `this.__proto__ == MovieClip.prototype` | `string,false,false,undefined×4,false` |
| F-v1 | `v1_own_and_proto` | `de193e16…` | root has own `this.onLoad` AND the proto handler: does `proto onLoad _global` still print (hidden-clip model) or not (only-when-root-resolves-via-proto model)? | `proto onLoad _global`, `own onLoad _level0` |
| F-v3 | `v3_global_onload` | `49f8ef15…` | `_global.onLoad` only: does anything print? | nothing |
| F-v2 | `v2_proto_in_f2` | `1e25491e…` | proto defined in root f2 (after the root load): any `proto onLoad` line (for `b`, or a late `_global`)? | nothing |
| F-v5 | `v5_swf6` | `08ae61c8…` | same as the landed proto fixture at SWF6: is the `_global` call version-gated? | same 7 lines as SWF8 |
| F-v6 | `v6_define_function2` | `9f7b6814…` | DefineFunction2 handler (preload this → r1): same two lines? | same 7 lines |
| R1 | `regression/avm1_root_onload_proto/test.swf` | `74783bb8…` | RUFFLE exporter/runner at ≥ `fa93ad79f` (the coordinator's exporter `0ddd12b6a` is pre-change): confirm or refute the RvF draft above | n/a |
