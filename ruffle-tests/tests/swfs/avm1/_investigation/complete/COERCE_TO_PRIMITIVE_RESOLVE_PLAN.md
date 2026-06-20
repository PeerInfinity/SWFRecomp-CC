# coerce_to_primitive_resolve — RESOLVED ✅

**Status:** FIXED 2026-06-19 — now passes (22/22). The initial "blocked"
diagnosis was wrong: it was based on a **stale `~/CC/ruffle` checkout** and a
WebFetch that only inspected `coerce_to_string`/`search_prototype`. After updating
the local Ruffle checkout, the real mechanism turned up in `action_trace` itself.

## The fix

Ruffle `activation.rs::action_trace`: when `coerce_to_string` returns `Err`, it
prints the fallback `"[type Object]"` to the trace log **and** propagates the
error:

```rust
match val.coerce_to_string(self) {
    Ok(s) => ...,
    Err(err) => { ctrl = Err(err); "[type Object]".into() } // print AND propagate
}
```

Our `actionTrace` OBJECT case coerced via `objectCallToString`, whose throwing
addProperty getter longjmps straight past `actionTrace` to the AS `catch` — so we
never printed the fallback (missing line 17). Fix: wrap the coercion in a local
`setjmp` frame (the established `g_exception_state` intercept idiom); on throw,
`printf("[type Object]\n")` then re-propagate via `pushVar` + `actionThrow`.
`action.c` OBJECT case in `actionTrace`. Verified: target 22/22; no regressions
across trace/toString/try-catch/addProperty/native-object spot-checks.

---

_Original (incorrect) blocked diagnosis kept below for the record:_

**Status:** ~~BLOCKED — needs unverifiable Flash-Player-specific behavior.~~
**Diagnosed:** 2026-06-19 (verified against current Ruffle master source via web).

## The gap is exactly one line

`output_mismatch`, 16/22 lines. The **entire** 6-line tail diff is caused by
**one missing line**: a bare `[type Object]` that Flash emits from
`trace(obj3)`, which shifts every following line by one. Fix that single line and
the test passes (it needs a full match — no `output.ruffle.txt`).

`Test.as` obj3 block (SWF v15, MTASC/Rascal):

```as
var obj3 = { __proto__: null };
Object.prototype.addProperty.call(obj3, "valueOf",  function(){ throw "error from valueOf!"; }, null);
Object.prototype.addProperty.call(obj3, "toString", function(){ throw "error from toString!"; }, null);
try { trace("obj3 as num: " + (0 + obj3)); } catch(e) { trace("obj3 as num: caught " + e); }
try { trace(obj3); }                         catch(e) { trace("obj3 as string: caught " + e); }
```

| line | expected (Flash) | ours (and Ruffle master) |
|------|------------------|--------------------------|
| 16 | `obj3 as num: caught error from valueOf!` | same ✓ |
| 17 | `[type Object]` | *(missing)* |
| 18 | `obj3 as string: caught error from toString!` | line 17 ✓ (shifted) |

So `trace(obj3)` (a single `ActionTrace`) must emit **two** results: the default
`[type Object]` **and** trigger the AS `catch` with the toString-getter throw.

## Why it's blocked

Verified the actual Ruffle implementation (current `master`, fetched 2026-06-19):

- `object.rs::search_prototype` — a virtual-property getter that throws returns
  `Err(Error::ThrownValue(e))` immediately (no swallow).
- `value.rs::coerce_to_string` — `object.call_method("toString", …, Special)?`
  propagates that error via `?`. It returns `[type Object]` **only when toString
  returns a non-string without throwing**.

So in Ruffle, `trace(obj3)` → toString getter throws → error propagates → the AS
`catch` fires → it emits **only** `obj3 as string: caught error from toString!`,
with **no** `[type Object]`. **That is byte-for-byte what we already produce.**

`test.toml` has **no `known_failure`** and the test has **no
`output.ruffle.txt`**, yet `output.txt` contains the `[type Object]` line that
Ruffle's own code cannot produce. Conclusion: `output.txt` is **real Flash
Player** output capturing a Player quirk — `trace` of an object whose `toString`
throws emits the default `[type Object]` to the log *and* still propagates the
throw — that **Ruffle itself does not reproduce** (this is likely a freshly added
test that Ruffle CI also fails, pending an upstream fix).

### Net

- No "match Ruffle" path: `ruffle_matched` is unreachable (no `output.ruffle.txt`)
  and Ruffle's actual output == ours, not the expected file.
- A full PASS requires replicating an odd Flash-Player coercion quirk with **no
  reference implementation to validate against** (Ruffle, our only oracle, gets
  it "wrong" the same way we do; we have no Flash Player).
- A naive fix ("when trace's toString throws, emit `[type Object]` first, then
  propagate") would be a guess on the shared `ActionTrace`/object→string coercion
  hot path and would wrongly inject `[type Object]` into every failed-toString
  trace. Not worth the regression risk for one test with no oracle.

**Revisit only if** upstream Ruffle later implements the quirk (an
`output.ruffle.txt` appears, or their `coerce_to_string`/trace path changes) —
then mirror their exact approach. Until then, leave as `output_mismatch`.

### Meta lesson

`~/CC/ruffle` is a **stale checkout** — its copy of this test still has the old
2-section form (old obj3 = "__resolve" → `NaN`/`[type Object]`). The fresh
`download_tests.sh` test added the throwing-getter obj3 and renamed old obj3 →
obj4. When local Ruffle source seems to contradict a downloaded test, suspect
drift and verify against `raw.githubusercontent.com/ruffle-rs/ruffle/master`.
