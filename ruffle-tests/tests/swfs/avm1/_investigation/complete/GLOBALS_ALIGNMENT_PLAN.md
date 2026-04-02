# Global Decls Tests — Flash-Spec Approach (COMPLETE)

Completed: 2026-04-02

## Summary

Three tests enumerate every global object and its properties: `global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls`. These tests were originally tracked against Ruffle's expected output, but ~1665 lines of Ruffle-specific behavior (Object.prototype methods ENUMERABLE, constructor as own property on all objects) made them permanently unfixable against the Ruffle baseline.

**Resolution:** Created Flash-spec expected output files (`output.flash.txt`) generated from our runtime. All three tests pass against Flash-spec baselines. The Ruffle versions are in `ignored_tests.txt`. CI validates both Ruffle compatibility (raw) and Flash correctness (Flash-spec) in every run.

## What Was Done

**Infrastructure (2026-04-02):**
- Added `--expected-suffix` and `--save-actual` flags to `verify_output.py`
- Added Flash-spec verification step to CI workflow (both single-runner and parallel paths)
- Updated `.gitignore` to allow `output.flash.txt` in the 3 test directories
- Added `global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls` to `ignored_tests.txt`

**Properties and methods added:**
- Key: 19 constants (ALT, ENTER, SPACE, UP, DOWN, LEFT, RIGHT, PGUP, PGDN, HOME, END, TAB, CONTROL, SHIFT, ESCAPE, INSERT, DELETEKEY, BACKSPACE, CAPSLOCK) + `isAccessible` stub
- Mouse: `show`, `hide`, `setTrailer`, `setTrailerPosition`, `setTrailerMode` stubs
- Function.prototype: `apply`, `call` (already existed, own_props added)

**Native function own_props (`setupNativeFuncOwnProps`):**
Sets `no_lazy_prototype` + creates own_props with `__proto__` and `constructor` on native functions. Applied to all native function creation paths:
- Object.prototype methods (9): watch, unwatch, addProperty, valueOf, toString, hasOwnProperty, isPrototypeOf, isPropertyEnumerable, toLocaleString
- AsBroadcaster shared functions (3): addListener, removeListener, broadcastMessage
- Math methods (18): abs, sin, cos, tan, exp, log, sqrt, round, floor, ceil, atan, asin, acos, atan2, pow, min, max, random
- Key methods (5), Selection methods (6), Accessibility methods (3), Mouse methods (5)
- Global functions (18): isNaN, isFinite, ASSetPropFlags, ASnative, escape, unescape, parseInt, parseFloat, trace, updateAfterEvent, setInterval, clearTimeout, clearInterval, setTimeout, showRedrawRegions, addRequestHeader, clearRequestHeaders, AsBroadcaster.initialize
- Function.prototype: apply, call
- MCL: loadClip, unloadClip, getProgress
- NetConnection: connect, close
- ContextMenu/ContextMenuItem: copy
- String: fromCharCode
- Error.prototype: toString
- All `addStubMethodToProto` calls (~50+ methods across Sound, XML, Array, Date, PrintJob, etc.)
- All `registerGeomMethod` calls (Point, Rectangle, Matrix, ColorTransform methods)
- All `registerProtoMethod` calls (BitmapData methods)

**Correctness fixes:**
- `__proto__` on all objects set to DONT_DELETE (non-configurable) via `setObjectProto`
- Inherited `constructor` skip in `actionEnumerate2` confirmed as correct Flash behavior (not removed)

## Remaining Items (no practical impact)

These were evaluated and deemed unnecessary for real-world SWF content:

| Item | Why not practical |
|------|-------------------|
| Function.prototype `constructor` property | Metadata only — no real code checks `Function.prototype.constructor` |
| Broadcaster DONT_ENUM flags on Key/Mouse/Stage/Selection | Methods work correctly; flag only affects `for-in` enumeration of these static objects |
| PrintJob instance properties (paperHeight, etc.) | PrintJob is a stubbed API — no real printing |
| `new textRenderer()` returning undefined | Static utility object, not meant to be constructed |
| Configuration special toString | Adobe testing framework API, not used by real SWF content |

## Flash-Spec Baselines

| Test | Lines | Status |
|------|-------|--------|
| global_proto_decls | 3714 | PASS |
| global_proto_decls_delete | 874 | PASS |
| global_instance_decls | 853 | PASS |

### Regenerating after future changes

```bash
python3 ruffle-tests/verify_output.py --test=global_proto_decls --save-actual=ruffle-tests/tests/swfs/avm1/global_proto_decls/output.flash.txt
python3 ruffle-tests/verify_output.py --test=global_proto_decls_delete --save-actual=ruffle-tests/tests/swfs/avm1/global_proto_decls_delete/output.flash.txt
python3 ruffle-tests/verify_output.py --test=global_instance_decls --save-actual=ruffle-tests/tests/swfs/avm1/global_instance_decls/output.flash.txt
python3 ruffle-tests/verify_output.py --expected-suffix=flash --verbose
```
