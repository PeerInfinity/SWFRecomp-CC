# TextField-vN Investigation Plan
<!-- TESTS: TextField-v6, TextField-v7, TextField-v8 -->

Last updated: 2026-05-21 (Phases 4, 6, 12 landed; Phase 1 partial —
prototype-level AsBroadcaster install done, per-instance self-register
still pending. Line match: v6 404→438/545, v7 413→447/570,
v8 416→449/571. No regressions; TextField-v5 still ruffle_matched.
All three still output_mismatch.)

<!-- PLAN_META
id: TEXTFIELD_VN_PLAN
status: in_progress
phases:
  - id: 1
    name: "TextField AsBroadcaster integration (addListener/removeListener/broadcastMessage/_listeners)"
    status: in_progress
  - id: 2
    name: "TextField.prototype.hasOwnProperty visibility for virtual properties"
    status: pending
  - id: 3
    name: "TextField.getFontList static method + Array-instance return"
    status: pending
  - id: 4
    name: "Boolean-setter coercion (background/embedFonts/multiline/selectable/password/border)"
    status: done
  - id: 5
    name: "null-typed properties (maxChars/variable/restrict) return string instead of null"
    status: pending
  - id: 6
    name: "MovieClip-only properties (_currentframe/_totalframes/_framesloaded) on TextField"
    status: done
  - id: 7
    name: "tf.type setter case-normalization (Input/INPUT → 'input')"
    status: pending
  - id: 8
    name: "tf.length reading text length vs stored value"
    status: pending
  - id: 9
    name: "tf.maxhscroll incorrect default value (70 vs 0)"
    status: pending
  - id: 10
    name: "tf._width / _height initial value (4 vs 500)"
    status: pending
  - id: 11
    name: "tf._parent setter (silent no-op vs apparent mutation)"
    status: pending
  - id: 12
    name: "tf.replaceText method existence + behaviour"
    status: done
  - id: 13
    name: "Container-MovieClip identity round-trip (storedthis === _root.tfmo)"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); TextField-v6/v7/v8 became visible at that point."
related:
  - id: TEXTFORMAT_V8_PLAN
    reason: "Phase 4 (boolean coercion) is conceptually parallel to TextFormat's int-coercion / INT_MIN clamping. Not shared code, but same kind of bug — coercion missing in property setter."
  - id: XML_XMLNODE_PLAN
    reason: "Phase 1 (AsBroadcaster on TextField) mirrors XMLNode-vN cluster A (own-vs-inherited prototype methods) — they may share the AsBroadcaster registration path."
blockers: []
status_note: |
  TextField-v6 is the smallest of the three (~545 assertions, ~140
  failures). v7/v8 add SWF-version-specific assertions but the
  failure clusters are essentially the same modulo `#if OUTPUT_VERSION
  > N` gates. Drive Phases 1-13 against v6 then re-run v7/v8 to
  confirm per-version deltas. Promotion plumbing in place via
  `known_failure = true` + `output.fpN.ruffle.txt`.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| TextField-v6 | 404/545 | 74.1% | output_mismatch |
| TextField-v7 | 413/570 | 72.5% | output_mismatch |
| TextField-v8 | 416/571 | 72.9% | output_mismatch |

After Phases 4/6/12 + Phase 1 (partial) — local, 2026-05-21:

| Test | Match | % | Status |
|------|-------|---|--------|
| TextField-v6 | 438/545 | 80.4% | output_mismatch |
| TextField-v7 | 447/570 | 78.4% | output_mismatch |
| TextField-v8 | 449/571 | 78.6% | output_mismatch |

### Progress log

**2026-05-21 — Phases 4, 6, 12 done; Phase 1 partial.** All in
`SWFModernRuntime/src/actionmodern/action.c`:

- **Phase 4 (boolean-setter coercion).** `actionSetMember` MOVIECLIP
  path now coerces the assigned value through `isVarTruthy` (ToBoolean)
  and stores a `BOOLEAN` ActionVar when the target is a TextField and
  the property is `background`/`border`/`multiline`/`password`/
  `selectable`/`embedFonts`/`html`/`wordWrap`. Objects are always
  truthy (so `tf.background = anObject` → true); numbers/strings use
  standard ToBoolean.
- **Phase 6 (MC-only frame props).** `_currentframe`/`_totalframes`/
  `_framesloaded` getters (both the `actionGetMember` MOVIECLIP arm and
  `getMCBuiltinProperty`) gated on `!MC_IS_TEXTFIELD(mc)` so they
  return undefined on a TextField. Also added a setter rejection in
  `actionSetMember` — writes to those three props on a TextField are a
  silent no-op (otherwise they'd land in `dynamic_props` and the
  now-undefined getter would read the stored value back).
- **Phase 12 (replaceText).** `initTextFieldPrototype` now installs
  `replaceText` as an own, DontEnum, undefined-valued property on
  `TextField.prototype` under SWF6 (it was only present as a function
  under SWF7+). `hasOwnProperty('replaceText')` is now true on v6.
- **Phase 1 (partial).** `initTextFieldPrototype` calls
  `installAsBroadcaster(proto)`, giving `TextField.prototype` own
  `addListener`/`removeListener`/`broadcastMessage` + an empty
  `_listeners` Array (TextField.as:78-84, 143-144 fixed). **Still
  pending:** per-instance self-registration — each TextField instance
  should get its own `_listeners` Array containing itself
  (`tf.hasOwnProperty('_listeners')`, `tf._listeners[0] == tf`,
  lines 166-168). Needs hooking the createTextField / DefineEditText
  init path.

## Test source

Gnash testsuite/actionscript.all/TextField.as (~1300 lines). Exercises:

- TextField.prototype method/property visibility
- AsBroadcaster on TextField (addListener/removeListener/_listeners)
- All ~25 TextField virtual properties (background, autoSize,
  border, borderColor, embedFonts, html, htmlText, length, maxChars,
  hscroll, scroll, maxhscroll, maxscroll, multiline, password,
  restrict, selectable, text, textColor, textHeight, textWidth, type,
  variable, wordWrap, etc.)
- TextField static methods (getFontList)
- TextField getters/setters with various type coercions
- Identity preservation across the TextField/MovieClip wrapper
  (`_root.tfmo === storedthis`)

## Failure clusters

### A. AsBroadcaster integration (Phase 1)

Lines: 78, 79, 80, 81, 82, 83, 84, 143, 144, 166, 167, 168.

```
- PASSED: typeof(TextField.prototype.addListener) == 'function' [./TextField.as:78]
+ FAILED: expected: 'function' obtained: undefined
- PASSED: TextField.prototype.hasOwnProperty("_listeners") [./TextField.as:81]
+ FAILED: TextField.prototype.hasOwnProperty("_listeners")
- PASSED: TextField.prototype._listeners instanceof Array [./TextField.as:83]
+ FAILED: TextField.prototype._listeners instanceof Array
```

TextField is an AsBroadcaster — its prototype should have own
`addListener`, `removeListener`, `broadcastMessage` methods, plus a
zero-length `_listeners` Array. The constructor should auto-register
each TextField instance as its own listener (`tf._listeners[0] == tf`
at line 168). We have none of this hooked up. Fix: call
`asBroadcasterInstall(TextField.prototype)` (or equivalent) during
TextField init, then add the auto-self-register in the TextField
constructor.

### B. TextField.prototype.hasOwnProperty visibility (Phase 2)

Lines: 87-112 (every `!TextField.prototype.hasOwnProperty('X')` from
'background' through 'wordWrap'), 127.

```
- PASSED: !TextField.prototype.hasOwnProperty('background') [./TextField.as:87]
+ FAILED: !TextField.prototype.hasOwnProperty('background')
```

The TextField *instance* properties (background, autoSize, etc.) are
virtual addProperty getters/setters that should live as own props on
**TextField instances**, NOT on `TextField.prototype`. We are
installing them on the prototype itself, so `hasOwnProperty` reports
true where the test expects false. Fix: move the addProperty
registrations into the TextField constructor (per-instance) rather
than the prototype, or use a backing-object scheme that proxies the
prototype lookups without exposing them as own.

Note: `replaceText` is the inverse (line 127, expected TRUE) — it
should be an own prop on the prototype.

### C. TextField.getFontList static + Array return (Phase 3)

Lines: 115, 121, 122, 123, 124, 125.

```
- PASSED: typeof(TextField.getFontList) == 'function' [./TextField.as:115]
+ FAILED: expected: 'function' obtained: undefined
- PASSED: TextField.getFontList() instanceof Array == true [./TextField.as:121]
+ FAILED: expected: true obtained: false
```

`TextField.getFontList()` is a static (constructor-level, not
prototype) method returning the device font list as an `Array`
instance. We don't have it implemented. Stub returning an empty
ASArray would PASS lines 115/121; populating it with the actual font
names is a follow-up. Verify behaviour with `null`/`undefined` `this`
(lines 124/125 explicitly check `.call(null)` / `.call(undefined)`).

### D. Boolean-setter coercion (Phase 4)

Lines: 247, 249, 250, 253, 256, 257, 259, 260 (`tf.background`);
301, 302, 304, 305 (`tf.embedFonts`); 422 (`tf.multiline`);
500, 505, 508, 513, 516 (`tf.password`); 604 (`tf.selectable`).

```
- PASSED: typeof(tf.background) == 'boolean' [./TextField.as:247]
+ FAILED: expected: 'boolean' obtained: number
- PASSED: tf.background == true [./TextField.as:250]
+ FAILED: expected: true obtained: 54.3
- PASSED: tf.background == true [./TextField.as:253]
+ FAILED: expected: true obtained: 255
```

The boolean-typed TextField properties (background, embedFonts,
multiline, selectable, password) must coerce their setter input
via ToBoolean before storing, then return a boolean from the getter.
We store the raw value (`54.3` ends up as `54.3`, `"a string"` ends
up as `"a string"`). Fix: in each setter, route through `convertBoolean`
or its inline equivalent.

### E. null-typed properties return string instead of null (Phase 5)

Lines: 388, 393 (`tf.maxChars`); 550, 551 (`tf.restrict`); 736, 739,
741, 744 (`tf.variable`).

```
- PASSED: typeof(tf.maxChars) == "null" [./TextField.as:388]
+ FAILED: expected: "null" obtained: string
- PASSED: tf.restrict == "" [./TextField.as:550]
+ FAILED: expected: "" obtained: null
- PASSED: typeof(tf.variable) == 'null' [./TextField.as:739]
+ FAILED: expected: 'null' obtained: undefined
```

Several TextField properties have a tri-state: null (cleared),
string (value), undefined (never set). We are returning the wrong
state in various cases:

- `tf.maxChars` after setting a string '5' should still return
  number 5 + typeof "null" when cleared (assignment to undefined
  resets).
- `tf.restrict` after setting "" should return "" + typeof string
  — we return null.
- `tf.variable` after clearing should return null-type — we return
  undefined.

Three independent setter/getter bugs but symptomatic of the same
"missing dedicated null state" design issue. Fix: each property
needs an explicit "is-cleared" flag distinct from "value is empty
string."

### F. MovieClip-only frame properties on TextField (Phase 6)

Lines: 615, 617, 619, 621, 623, 625.

```
- PASSED: typeof(tf._currentframe) == 'undefined' [./TextField.as:615]
+ FAILED: expected: 'undefined' obtained: number
- PASSED: tf._currentframe == undefined [./TextField.as:617]
+ FAILED: expected: undefined obtained: 1
```

TextField is not a MovieClip — `_currentframe`, `_totalframes`,
`_framesloaded` should return undefined on a TextField. We return
1 (probably falling through to the MovieClip getter on the parent
TextField/MovieClip wrapper). Fix: gate these getters on
`!is_textfield` in the dispatch path.

### G. tf.type setter case-normalization (Phase 7)

Lines: 709, 710, 712, 714, 717.

```
- PASSED: tf.type == 'input' [./TextField.as:710]
+ FAILED: expected: 'input' obtained:
- PASSED: tf.type == 'input' [./TextField.as:717]
+ FAILED: expected: 'input' obtained: Input
```

`tf.type = 'Input'` should normalize to lowercase `'input'` for valid
values, and leave the field unchanged for invalid ones. We are
storing values verbatim or rejecting some that should succeed.

### H. tf.length reading text length (Phase 8)

Lines: 372.

```
- PASSED: tf.length == 0 [./TextField.as:372]
+ FAILED: expected: 0 obtained: 10
```

After `tf.text = ""` the test expects `tf.length == 0`. We return 10
(probably the previous text's length). Likely the `text` setter isn't
clearing the cached length, or `length` is reading from the wrong
field. Note: tf.length is a derived getter; can't be set directly.

### I. tf.maxhscroll incorrect default (Phase 9)

Lines: 401, 403.

```
- PASSED: tf.maxhscroll == 0 [./TextField.as:401]
+ FAILED: expected: 0 obtained: 70
```

`maxhscroll` on a default-sized empty TextField should be 0. We
return 70 (probably the default field width in pixels — a TF that's
70px wide has 0 horizontal scroll because the text fits). Likely the
maxhscroll computation isn't running and we're returning a stale
field-width default.

### J. tf._width / tf._height (Phase 10)

Lines: 166, 323, 578, 581, 584.

```
- PASSED: tf._height == 500 [./TextField.as:323]
+ FAILED: expected: 500 obtained: 4
```

The test creates a TextField via `createTextField('tf', 1, 10, 10,
500, 500)` (a 500×500 field) and then verifies `tf._width == 500 &&
tf._height == 500`. We return 4 (likely the device-font default line
height in pixels). Indicates `createTextField` isn't properly setting
the bounds, or `_width`/`_height` getters are returning the text-
extent instead of the field dimensions.

This is the single most-impactful cluster by line count likely —
many other tests in the file depend on the field being 500×500 to
make subsequent assertions valid.

### K. tf._parent silent-no-op semantics (Phase 11)

Lines: 476.

```
- PASSED: tf._parent == 23 [./TextField.as:476]
+ FAILED: expected: 23 obtained: _level0
```

Reading the test source: presumably the test does `tf._parent = 23`
then expects `_parent` to still equal 23 (Flash's `_parent` setter
silently accepts any value — it just doesn't actually re-parent;
the value is stored but the MC tree is unchanged). We are likely
rejecting the assignment and returning the still-correct parent ref.

This is a Flash quirk — needs verification against Ruffle's
`output.fpN.ruffle.txt`. Could be ACCEPTED_DIFFS or RUFFLE_VS_FLASH
candidate if Ruffle matches us.

### L. tf.replaceText (Phase 12)

Lines: 127, 131.

```
- PASSED: TextField.prototype.hasOwnProperty('replaceText') [./TextField.as:127]
+ FAILED: TextField.prototype.hasOwnProperty('replaceText')
  PASSED: typeof(TextField.prototype.replaceText) == 'undefined' [./TextField.as:131]
```

Flash quirk: `replaceText` exists as an own property on
TextField.prototype but is undefined (no function value). We don't
register the prop at all. Cheap fix.

### M. Container-MC identity round-trip (Phase 13)

Lines: 1238, 1244, 1245, 1247, 1248.

```
- PASSED: _root.tfmo == storedthis [./TextField.as:1244]
+ FAILED: expected: storedthis obtained: _level0.tfmo
- PASSED: _root.tfmo.bo == "stringo" [./TextField.as:1247]
+ FAILED: expected: "stringo" obtained: undefined
```

After capturing `var storedthis = this;` inside a handler attached to
`_root.tfmo` (a TextField), the test verifies `storedthis ===
_root.tfmo`. Identity should be preserved through the TextField
MovieClip wrapper. We are creating a different value for `this`
inside the handler than the one exposed via `_root.tfmo`. Likely the
TextField MC wrapper allocates a transient ASObject for the handler
context instead of using the canonical one.

The `storedthis.bo = "stringo"` write afterward doesn't survive to
`_root.tfmo.bo` either, confirming the two are different objects
in our impl.

## Recommended fix order

1. **Phase 10 (tf._width/_height initial value)** — single biggest
   line-impact cluster; many later assertions depend on it.
   Estimate: 1-2 hours.
2. **Phase 1 (AsBroadcaster integration)** — large, mostly mechanical
   if we already have an `asBroadcasterInstall` helper. Estimate:
   1-2 hours.
3. **Phase 4 (boolean-setter coercion)** — small fix per property,
   ~5-7 properties to touch. Estimate: 1-2 hours.
4. **Phase 6 (MC-only frame properties)** — gate in dispatch.
   Estimate: 30 min.
5. **Phase 5 (null-state for maxChars/restrict/variable)** —
   three independent fixes, each touching the property's storage
   model. Estimate: 2-3 hours.
6. **Phase 2 (prototype-vs-instance own-prop layout)** — high
   architectural risk, needs care to not regress AVM1 textfield
   tests. Estimate: 3-4 hours.
7. **Phase 3 (getFontList stub)** — cheap if a stub suffices.
   Estimate: 30 min.
8. **Phase 7 (tf.type case-normalize)** — small. Estimate: 30 min.
9. **Phase 9 (tf.maxhscroll)** — diagnose, probably 1 hour.
10. **Phase 8 (tf.length)** — small but interacts with the text
    setter cache. Estimate: 1 hour.
11. **Phase 13 (container-MC identity)** — invasive; touches the
    TextField/MovieClip wrapper allocation. Estimate: 2-3 hours.
12. **Phase 11 (tf._parent)** — verify against Ruffle first; may
    be ACCEPTED_DIFFS. Estimate: 1 hour.
13. **Phase 12 (replaceText)** — cheap. Estimate: 30 min.

Total estimate: 14-20 hours, 4-6 sessions.

## Promotion plumbing

All three tests have `known_failure = true` + `output.fpN.ruffle.txt`
sidecars. Given the ~73% line-match rates, several phases will need
to land before any test promotes; closest to threshold is v6 at 404
of 545 (~74%).
