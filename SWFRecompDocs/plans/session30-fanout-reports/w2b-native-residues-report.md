# s30 w2b-native-residues — AVM1 native-object residues pinned by FP32

Slot `w2b-native-residues`, wave 2 (implementation). Box: SETUP_STATUS all OK (apt, Pillow, Dawn).
Corpus: `download_tests.sh avm1 from_gnash` on 2026-11-27 (Ruffle master, the s30 upstream `66f9073de`).

**BASE: `origin/master` `0224aaf2` + the sibling `w2-native-instance.patch` (not landed yet when I finished).**
The brief said w2-native-instance lands next, and one hunk of mine (Sound for..in hide) edits a function that
patch adds. So this branch has two commits: `7b60d049` (base: w2-native-instance's patch applied verbatim,
not mine) and my commit on top. **`w2b-native-residues.patch` = `git diff 7b60d049` (my changes only). It applies
cleanly on master + w2-native-instance.patch, and NOT on bare master** (the `avm1EnumHideMask` hunk fails there).
I checked both cases with `git apply --check` in a scratch worktree. Land w2-native-instance first.

**New files (all on this branch):**
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-native-residues-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-native-residues.patch`
- `ruffle-tests/tests/swfs/regression/avm1_native_instance_layout/{create_test_swf.py,test.swf,test.toml,output.txt}`.
  This is the w2-native-instance fixture moved in from `w1-local-oracles/w2-native-instance/`. Golden = `fp32.lnx.txt`.
  The regenerated SWF is byte-identical to the captured one. I left the archive copy in place as provenance.
- `ruffle-tests/tests/swfs/regression/avm1_native_identity_probe_swf{5,6,7,8}/{create_test_swf.py,test.swf,test.toml,output.txt}`.
  These are the w2-native-table-land identity probe. Golden = FP32 `w1-local-oracles/w2-native-table-land/v{5..8}.lnx.txt`,
  and each regenerated SWF is byte-identical to the captured one. **All 4 now pass. All 4 failed before.**
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-native-residues-fixtures/`: `mk_residue_probe.py`,
  `residue_probe.v{5,6,8}.swf`, `residue_probe.v{5,6,8}.ours_{before,after}.txt` (LOCAL ORACLE REQUEST 1).
  Also `sweep_list.txt` (396 rows), `sweep_{graphics,nographics}_after.tsv` and `headline_status_{master,base}.tsv`.

No new `.c`/`.h`, no recompiler change, no `verify_output.py` change, no canary-list change.

**Functions touched.**
- `action.c`, new `static`: `avm1FuncHasNoProto` (+ `g_avm1_noproto_fn`), `avm1ObjProtoMethodHiddenV5`,
  `g_object_ctor_ref`.
- `action.c`, edited: `ensureObjectConstructor`, `ensureGlobalInit` (2 spots: ASnative bag, Object merge after the
  g_ctors[0] reorder), `avm1NativeStubsInstall`, `initSoundPrototype` (tail), `avm1EnumHideMask` /
  `avm1EnumHidesOwnSlot` (w2-native-instance's, one bit added), `actionGetMember` (FUNCTION arm), `actionCallMethod`
  (FUNCTION arm ×2, MovieClip arm after `mcArmVersionHidden`), `callArrayMethod` (hasOwnProperty head),
  `checkInstanceOf`, `instanceOfCoercing`, `actionNewObject` (`BitmapData` arm).
- `date.c`: `date_ensure_tza`, `date_utc_to_local`, `date_local_to_utc`, `builtin_date_toString`,
  `builtin_date_getTimezoneOffset`; new `static` `date_c_offset_ms_at`, `date_dst_ta`, `date_offset_ms_at_utc`.
- Nothing in `swf_core.c`, `tag_stubs.c`, `tag.c`, `swf.c`, `action_queue.c`, and no `#ifdef NO_GRAPHICS` arm.
- No `builtin_asnative` id 900/901 change and no R1–R6 function (sibling w2-rm-avm1-gnash-land).

## 0. Verdicts and EXPECTED-FLIP LEDGER

| item | verdict |
|---|---|
| 1. `ASnative` has no `__proto__` / `constructor` | **GO, landed.** It is now a real proto-less function. `ASnative.__proto__/.constructor/.call/.apply/.toString/.hasOwnProperty` are undefined, `ASnative.x()` for any non-own method is undefined, and `ASnative instanceof Function/Object` is false. Probe v6/v7/v8 lines 25 and 36 now equal FP32. |
| 2. SWF5 `hasOwnProperty` & co. | **GO, landed; premise narrowed.** Object, string and (already) `Key`-style object receivers were correct before. The leak was the **hard-coded CallMethod arms** for function, array and clip receivers. They answered `hasOwnProperty` (and on clips `isPropertyEnumerable`) at SWF5. Now all six SWF6+ Object.prototype members (`hasOwnProperty isPropertyEnumerable isPrototypeOf watch unwatch addProperty`) are undefined through those arms at SWF5. They read the live `flash_flags`, so an ASSetPropFlags unhide still works. GetMember was already correct. Probe v5 lines 12/13/25–27 now equal FP32. |
| 3. SWF5 `RemoteLSOUsage.getURLPageSupport` | **GO, landed** (installed before the SWF6 gate; `AssetCache.*` stays SWF6+). Probe v5 line 37 now equals FP32. |
| 4. `Sound.prototype.checkPolicyFile` / `areSoundsInaccessible` | **GO, landed.** Both are now own on Sound.prototype, DONT_ENUM + DONT_DELETE + READ_ONLY. `checkPolicyFile` is undefined. `areSoundsInaccessible` is undefined at SWF ≤ 8 (FP32 v6/v7/v8 dumps) and a stub function at SWF ≥ 9 (the SWF15 golden; SWF9–14 not measured). The instance's own boolean `checkPolicyFile` (gnash `Sound.as:112`) is now invisible to for..in on a Sound, even after an unhide. **The native-instance fixture is now a regression row, and it passes.** |
| 5a. L2 `Object` ctor identity | **GO, landed: a real bug.** At SWF6+, `Object === _global.Object` was **false**, and so were `Key.constructor === _global.Object` and `({}).constructor === _global.Object`. `GetVariable("Object")` returned the lazy `g_object_constructor_static`, while `_global.Object` is `g_ctors[0]`. Merged with the Array/String pattern: after ensureGlobalInit builds g_ctors[0], `ensureObjectConstructor` returns it, and Object.prototype.constructor is repointed if the static had claimed it. A side effect: `for (k in Object)` now lists `__proto__,constructor`, not `registerClass`. That matches FP32: the v8 dump lists `registerClass` DONT_ENUM and `__proto__`/`constructor` without DONT_ENUM. Corpus: 0 rows move. FP32 capture for the probe lines: LOCAL ORACLE REQUEST 1. |
| 5b. L3 `_global.hasOwnProperty(k)` → undefined | **REFUTED as a residue: ours already equals FP32.** The FP32 v8 probe prints `_global own o: undefined`, because `_global` has no `__proto__` in Flash. Nothing to do. |
| 6. `global_instance_decls` nondeterminism | **GO, fixed; root cause is not an uninitialised read.** `new flash.display.BitmapData("100","100")` goes to the `actionNewObject` `BitmapData` arm. That arm read width/height with `varToDouble`, a raw F32/F64 bit read, so for a STRING arg it reinterpreted the **string pointer's** bits as a float, and ASLR decided validity. The arm now uses `tsArgToDouble_ctx` (ToNumber), as the CallMethod-blank arm already did. Before the fix, 1 run in 6 differed. After it, **8/8 plain runs and 5/5 `--asan` runs (`detect_leaks=0`) are byte-identical**, with 0 ASan errors, and they print the golden's `[object Object]` block (+29 matching lines). |
| 7. `global_instance_decls` TZ line | **GO in code, needs a coordinator flash_fixes entry.** `mock_timezone` exists (`verify_output.py:get_mock_timezone`), but AVM1 `date.c` used ONE offset sampled at the *wall-clock* `time(NULL)`, so no DST rule could ever apply. It also made a DST zone's output depend on the date of the run. Ported avm2_date.c's s29 per-instant DST model: LocalTZA = min(Jan, Jul) offset around `MOCK_DATE_TIME`, plus DaylightSavingTA(t). Under the default NPT-5:45 pin (no DST) nothing changes: 0 of 396 sweep rows move. With `mock_timezone = "CET-1CEST,M3.5.0,M10.5.0/3"` in the test.toml, the line prints `Sat Apr 4 00:00:00 GMT+0200 2020` (= golden). Before the port it printed GMT+0100. Measured with a temporary toml edit, then reverted. **flash_fixes candidate below.** Even with it, the row stays output_mismatch (161 other lines). |

### EXPECTED-FLIP LEDGER (vs master + w2-native-instance; identical in graphics and no-graphics)
- **Trace axis, both modes, status moves:**
  - `regression/avm1_native_instance_layout`: NEW → **pass** (fails on master+ni: line 12).
  - `regression/avm1_native_identity_probe_swf5`: NEW → **pass** (fails before: 12 diff lines).
  - `regression/avm1_native_identity_probe_swf6`: NEW → **pass** (fails before: 4 diff lines).
  - `regression/avm1_native_identity_probe_swf7`: NEW → **pass** (fails before: 4 diff lines).
  - `regression/avm1_native_identity_probe_swf8`: NEW → **pass** (fails before: 4 diff lines).
- **Content moves, status unchanged** (diff lines vs golden; `argstest` is graded on `output.fp32.txt`):
  `avm1/global_instance_decls` mm, `avm1/global_proto_decls` **stays ruffle_matched**,
  `avm1/global_proto_decls_delete` mm, gnash `argstest-v6/v7/v8` mm. All are Flash-ward (§1).
- **Everything else in the 396-row sweep: byte-identical output before/after, in both modes.** That is the whole
  w2-native-table-land `sweep_list.txt` (143) + the w2-native-instance sweep (180) + 156 extra rows: avm1 tests that
  use Date / BitmapData / registerClass / hasOwnProperty / instanceof, every gnash `*-v5`, gnash
  Date/Object/Function/ASnative rows, and 47 regression rows that touch those APIs. 0 losses.
- **Pixel axis:** none expected. No render code is touched (§3).

## 1. Per-test before/after (same box, `--mode=graphics`; no-graphics byte-identical)

Diff lines = `diff <golden> <ours> | grep -c '^[<>]'`. Legs: clean `origin/master` → master + w2-native-instance
(base) → base + this patch.

| row | status (master → base → after) | diff lines master → base → after |
|---|---|---|
| `regression/avm1_native_instance_layout` (FP32) | mm → mm → **pass** | 18 → 2 → **0** |
| `regression/avm1_native_identity_probe_swf5` (FP32) | mm → mm → **pass** | 12 → 12 → **0** |
| `regression/avm1_native_identity_probe_swf6` (FP32) | mm → mm → **pass** | 4 → 4 → **0** |
| `regression/avm1_native_identity_probe_swf7` (FP32) | mm → mm → **pass** | 4 → 4 → **0** |
| `regression/avm1_native_identity_probe_swf8` (FP32) | mm → mm → **pass** | 4 → 4 → **0** |
| `avm1/global_instance_decls` | mm → mm → mm | 767 → 192* → **161** |
| `avm1/global_proto_decls` | rm → rm → **rm** | 226 → 204 → **202** |
| `avm1/global_proto_decls_delete` | mm → mm → mm | 81 → 81 → **79** |
| gnash `argstest-v6` (fp32) | mm → mm → mm | 2205 → 2169 → **2166** |
| gnash `argstest-v7` (fp32) | mm → mm → mm | 2306 → 2276 → **2273** |
| gnash `argstest-v8` (fp32) | mm → mm → mm | 2337 → 2341 → **2338** |

\* `global_instance_decls` before the fix is nondeterministic. The base run happened to draw the bad
`[undefined]` BitmapData variant. The whole −31 is the BitmapData determinism fix, and it is the golden's block.
The gpd/gpd_delete/argstest −2/−3 are the two Sound.prototype members: now present, and in FP32 order.

(These counts are against the corpus `output.txt` on this box. The w2-native-instance report counts larger
totals for the same rows with a different golden and diff method. Only the deltas matter here.)

### Residue probe (`w2b-native-residues-fixtures/residue_probe.v*.ours_{before,after}.txt`)
- v5 (before → after): `function/array/clip hOP(x) call: false` → `` (empty). Also clip `isPE` `false` → ``, and
  ASnative `constructor=function` → `undefined`.
- v6/v8: ASnative `__proto__=object call=function apply=function toString=function … instanceof Function: true` →
  every one `undefined` / `false`. `Object===_global.Object`, `Key.constructor===_global.Object`,
  `({}).constructor===_global.Object`, `Math.constructor===_global.Object`: `false` → `true`. `Object keys:
  registerClass,` → `__proto__,constructor,`.
- Unchanged: `typeof _global.hasOwnProperty: undefined` (L3 refuted), `Object.prototype = 5` is ignored, and
  `Object.registerClass` stays a function.

## 2. Mechanism notes
- **ASnative.** `g_asnative_func` already had an empty own bag and `no_lazy_prototype`. But three paths synthesised a
  virtual `Function.prototype` for any function without an own `__proto__`: `actionGetMember`'s FUNCTION-arm fallback,
  the hard-coded `call/apply/hasOwnProperty/toString` arms of `actionCallMethod`, and the instanceof walkers. All of
  them now skip it for `avm1FuncHasNoProto(f)`. Only ASnative is flagged. `ASnative(a,b)` results
  (`g_asnative_dead` and the real natives) are untouched.
- **Object merge.** `ensureObjectConstructor` was the only door to the static. Its callers (`GetVariable("Object")`,
  `__constructor__` on new objects, the singletons' own `constructor`, `actionNewObject` at two sites) all now get
  `g_ctors[0]` once global init has run. The static is still built only if something asks for it before then.
- **Date.** Same algebra as `avm2_date.c` (`c_offset_ms_at` via `localtime_r`, no `timegm`). Under a no-DST zone it
  is algebraically the old fixed offset. There is one behaviour change for builds without `MOCK_DATE_TIME` (the
  browser/WASM build): LocalTZA is still sampled from "now", but standard time is now separated from DST, so DST is
  applied per date. That is the Flash behaviour.

## 3. Regression suite, guard sweep, canary
- **Regression suite:** 62 rows by name (the 5 new + 57 that touch these APIs). All pass in both modes except the
  pre-existing graphics-only `SKIP` of 3 `avm2_*` regression rows. That skip is the same in both legs.
- **Guard sweep:** 396 rows × {graphics, no-graphics} × {before, after}. Only the 11 rows of §1 change output, and
  graphics after == no-graphics after byte-for-byte on all 396. Status column per row (after):
  `w2b-native-residues-fixtures/sweep_{graphics,nographics}_after.tsv`. The before legs' status column was lost to a
  parser bug in my script; their saved outputs are what I compared (identical output ⇒ identical status). For the 11
  moving rows I re-ran the before statuses: `headline_status_{master,base}.tsv`.
  Two list entries are not tests: `avm1/bitmap_data_thorough` is a subtest parent dir and shows COMPILE_FAIL in both
  legs, and `avm1/__framework__`. Ignore both.
- **Render canary: NOT RUN.** Priced: two 880-line captures cost about 1.5 h on 4 CPUs, and the patch touches no
  render code. The only pixel-reachable change is `new BitmapData(<string>, <string>)`, which now builds a bitmap where
  it used to return undefined (ASLR-dependent). No canary member is known to do that. Completion mechanism: the
  coordinator's CI pixel axis (`images=false` still grades pixels via the canary, or the next images run). Expected:
  0 moves.

## 4. Not done / HOLD (each with its completion mechanism)
- **`global_instance_decls` TZ line:** needs the flash_fixes test.toml entry below (coordinator-owned).
- **`areSoundsInaccessible` at SWF9–14:** unmeasured. I chose function-from-9. Completion: an FP32 v9 or v10 capture
  of the gpd probe, if a corpus row ever depends on it (none does today).
- **Instance `checkPolicyFile` hasOwnProperty/delete:** FP32 unmeasured. The slot stays own for hOP. Only for..in
  hides it, which is the measured behaviour.

## flash_fixes candidate
- `avm1/global_instance_decls/test.toml`: add `mock_timezone = "CET-1CEST,M3.5.0,M10.5.0/3"` (POSIX rule spelling of
  Europe/Berlin, as the README requires). Evidence: the golden's only zone-dependent line is
  `Sat Apr 4 00:00:00 GMT+0200 2020` for `new Date(2020, 3, 4)`. With this patch plus that toml line, ours prints it
  exactly. Caveat (w2-native-instance's): any +2 zone fits one date, and CEST is the likeliest capture host.

## RvF / dispositions
None new. Every change is Flash-ward against an FP32 capture, or a determinism fix, and no Ruffle-golden row loses.

## New unclaimed leads
- **`varToDouble` on possibly-STRING ctor args elsewhere** (S). The same pointer-bits bug class as item 6. Grep
  `varToDouble(&args[` in the `actionNewObject` arms: in the `BitmapData` arm, `transparent`/`fillColor` still use
  `varToDoubleSimple`, and other native ctors may do the same. Each is a latent ASLR nondeterminism for a string arg.
- **`Function === _global.Function`** (S): probe it the way L2 was probed. The Function constructor has the same
  two-copy shape (`g_function_constructor` vs `g_ctors[5]`).
- **`for (k in Object)` order and contents at SWF5:** the merge changed it at every version (`__proto__,constructor`).
  FP32 v5 is unmeasured, so it is included in LOCAL ORACLE REQUEST 1.

## LOCAL ORACLE REQUESTS
1. **FLASH: `w2b-native-residues-fixtures/residue_probe.v{5,6,8}.swf`, trace, 1 frame, direct pinned.** Compare with
   `residue_probe.v*.ours_after.txt`. It checks: the SWF5 receiver matrix (6 methods × function/object/array/clip/
   string), ASnative's full member list plus `instanceof`, the L2 identity lines, `for (k in Object)`,
   `Object.prototype = 5`, and `_global.hasOwnProperty`. Generator: `mk_residue_probe.py <out.swf> <ver>`. If FP32
   equals ours, the coordinator can promote them to `regression/avm1_native_residue_probe_swf{5,6,8}`.
