# w2-avm1-child — AVM1-child-under-AVM2, slots 1 + 2 (session 16, wave 2)

**Agent:** `w2-avm1-child` (wave-2).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-adfa0869c0c8fb974`
**Base:** `cd04f80b9`; baseline statuses from run `31748059158` @ `3db858cbc`.
**Mode:** `--mode=graphics`, `-P 2`.

---

## 0. New files: NONE

All three patches touch existing files only — nothing to `git add` beyond these:

| patch | files touched |
|---|---|
| `w2-avm1-child.patch` (slot 1) | `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_display.c` |
| `w2-avm1-child-lc.patch` (slot 2) | `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_display.c`, `SWFModernRuntime/src/avm2/avm2_net.c` |
| `w2-avm1-child-docs.patch` | `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` |

**Stacking order: slot 1 → slot 2 (→ docs, independent).** Slot 2 rewrites two of
slot 1's own hunks — it factors the child-context swap out of the mouse bridge
into `avm1UnderAvm2EnterChild`/`LeaveChild` and reuses it for the LocalConnection
delivery and the tick drain — so `w2-avm1-child-lc.patch` will NOT apply to a
tree that lacks slot 1. **Verified mechanically**: `HEAD(cd04f80b9)` + slot 1 +
slot 2, applied in that order with `patch -p1` to pristine `git show HEAD:` copies,
is byte-identical to the worktree every number in section 2 was measured from
(all three files).

## 1. Verdicts and flips

| slot | mechanism | verdict | flips (all measured, `--mode=graphics`) |
|---|---|---|---|
| **1** | AVM1 root depth `-77824` (leg A) + `addChild(AVM1Movie)` → #2180 (leg B) + AVM1 mouse-broadcast bridge (leg C) | **GO** | **`mixed_avm/avm2_loads_avm1` output_mismatch → PASS** (and `_v10` 3 differing lines → 1) |
| **2** | cross-VM LocalConnection registry bridge (leg D) **+ `AVM1Movie` position mirror (leg D2, new)** | **GO** | **`mixed_avm/avm2_loads_avm1_v9` → PASS**, **`mixed_avm/avm2_loads_avm1_v10` → PASS**, **`avm2/localconnection` → PASS** |
| docs | `avm2/avm1_root` is a RUFFLE_VS_FLASH row | written | 0 |

**Total: +4 trace flips, zero regressions across 27 graded rows.**

`avm2/localconnection` (890 expected lines) was **not** priced by wave 1 — the
`avm2_net.c` comment claimed it "needs more besides" the AVM1 registry. It does
not: the AVM1 half was the only missing piece, and the row now matches
byte-for-byte, including its last 325 lines, which are AVM2→AVM1 sends with
0-, 1- and 7-argument AMF0 payloads, a callee that throws, and the sender-side
`StatusEvent` for each. That row is a far higher-resolution oracle for the bridge
than the two `mixed_avm` rows it was built for.

With `mixed_avm/avm2_loads_avm1{,_v9,_v10}` green on top of s15's `_doabc`,
`_loads_avm2_doabc` and `_loads_into_root`, the **only** `mixed_avm` row left is
`avm1_loads_avm2`, which is the harness/build arc (wave-1 leg G, unchanged).

## 2. Ledger

Baseline column = `results_graphics.json` @ `3db858cbc`. "slot 1" = slot-1 patch
alone; "1+2" = both patches (the shipping configuration).

| test | baseline | slot 1 | 1+2 (shipping) |
|---|---|---|---|
| `mixed_avm/avm2_loads_avm1` | output_mismatch (5 lines) | **pass** | **pass** |
| `mixed_avm/avm2_loads_avm1_v9` | output_mismatch (1) | output_mismatch (1) | **pass** |
| `mixed_avm/avm2_loads_avm1_v10` | output_mismatch (3) | output_mismatch (1) | **pass** |
| `avm2/localconnection` | output_mismatch | — | **pass** |
| `mixed_avm/avm2_loads_avm1_doabc` | pass | (timeout) | pass |
| `mixed_avm/avm2_loads_avm1_loads_avm2_doabc` | pass | pass | — |
| `mixed_avm/avm2_loads_avm1_loads_into_root` | pass | pass | — |
| `mixed_avm/avm1_loads_avm2_doaction` | pass | (timeout) | pass |
| `from_shumway/avm1movie` | ruffle_matched | (timeout) | **ruffle_matched** |
| `avm1/localconnection` | pass | — | pass |
| `avm1/localconnection_properties` | pass | — | pass |
| `avm1/localconnection_top_level` | pass | — | pass |
| `avm2/localconnection_send` | pass | — | pass |
| `from_shumway/localconnection` | pass | — | pass |
| `regression/avm2_localconnection_domain` | pass | — | pass |
| `regression/lc_method_type1_args` | pass | — | pass |
| `regression/lc_onstatus_type1_args` | pass | — | pass |
| `avm2/avm1movie_addcallback_call` | pass | (timeout) | pass |
| `avm2/loader_events` | pass | (timeout) | pass |
| `avm2/loader_load` | output_mismatch | (timeout) | output_mismatch — same 2 lines (`URLVariables` key order, unrelated) |
| `avm2/mouse_click_events` | pass | (timeout) | pass |
| `avm2/mouse_pick_avm1_root` | output_mismatch (1) | (timeout) | output_mismatch (same 1 line: `avm1 child clicked` absent) |
| `avm2/selection_onsetfocus_mixed_avm` | output_mismatch (5) | output_mismatch (5) | — |
| `avm2/mouse_children` | pass | pass | — |
| `avm1/mouse_events` | pass | pass | — |
| `avm1/mouse_listeners` | pass | pass | — |
| `avm1/mouse_pos` | pass | pass | — |

**27 rows graded, 4 flips, zero regressions.**

**"(timeout)" is not a result.** Eight slot-1 rows returned `compile_fail` during
the first batch; `--verbose` showed the detail as `compilation timed out` — the
300 s per-file gcc cap, hit because the shared box was at load average 34 with
~20 concurrent `action.c` compiles and 0 GB free RAM. Every one of them was
re-measured in the second batch with `SWFRECOMP_COMPILE_TIMEOUT=2400`. Anyone
re-running this work under load should export that variable from the start.

**Canary blind spot:** none of this arc has a pixel effect, so the render canary
does not cover it. The covering graded rows are the six `mixed_avm/avm2_loads_avm1*`
rows, `from_shumway/avm1movie` (the `ruffle_matched` regression canary named by
wave 1 — held), the seven LocalConnection rows, and the mouse/Loader rows above.

## 3. Slot 1 — what changed from the wave-1 probe

Same three legs, same measured behaviour; the diff grew 86 → 127 lines, all of it
comment and naming:

* both `WAVE-1 PROBE` markers gone;
* `actionMouseAvm1ChildrenUnderAvm2` has a real doc comment stating (a) that the
  bridge is a **broadcast**, not a hit test — `Mouse.onMouseX` / `mc.onMouseX`
  fire regardless of pointer position, which is the whole of what the fixtures
  grade — and (b) that `onPress`/`onRelease` do hit-test, but in the AVM1 child's
  own coordinate space, so a Loader transform between the AVM2 stage and the AVM1
  root is explicitly out of scope;
* the raw `0/1/2` event kind is now `AVM1_CHILD_MOUSE_{MOVE,DOWN,UP}`, defined on
  both sides of the (deliberately header-free) seam with a cross-reference, like
  the existing boot/tick hooks;
* the `_saved_*` locals lost their underscores; the `g_avm1u2[0]` swap carries the
  justification for being done once (the AVM1 dispatchers walk process-global
  registries — `child_mc_cache` and the single `g_mouse_obj` broadcaster — so
  re-entering per child would fire every handler N times);
* `static Avm2Class* g_avm1movie_class;  // tentative def; real one below` now
  says which C rule it is leaning on (C11 6.9.2) and why `validate_add` needs it;
* the `#2180` message text was checked against Ruffle
  `core/src/avm2/error_messages.rs:326` — exact match, including the trailing
  period.

No debug prints anywhere in either patch.

## 4. Slot 2 — mechanism, and a correction to BOTH prior diagnoses

### 4.1 The bridge

Flash's LocalConnection registry belongs to the **player**, not to a VM. Our two
halves (`action.c` ~:2790, `avm2_net.c` :1428) keep separate channel maps and
separate AMF0 codecs, so they are **bridged, not merged**: each half exports a
`has_channel` + `deliver` pair, and consults the other only when its own map has
no listener.

* `action.c` → `actionAvm1LocalConnectionHasChannel` / `actionAvm1LocalConnectionDeliver`
* `avm2_net.c` → `avm2_net_local_connection_has_channel` / `avm2_net_local_connection_deliver_from_avm1`

Both directions are wired (the reverse was cheap, and `avm2/localconnection`
exercises it). Three details the fixtures pin:

1. **`send()` decides "is there a listener" twice**, and both decisions now span
   both VMs — the send-time test (`m->failure` / `had_receiver`) and the
   delivery-time lookup.
2. **The sender's status event fires before the callee runs**, on the sending VM,
   in the cross-VM path exactly as in the same-VM path.
3. **The AMF0 buffers cross untouched.** `avm2_amf0_write_value` and
   `avm1AmfDeserializeArg` (and the reverse pair) are both bare single-value AMF0
   with per-value reference tables; the two key builders (`lc_connect_key`/
   `lc_send_key` vs `lc_build_key`) already emit the same `superdomain:name`
   lowercased string. `avm2/localconnection`'s 7-argument send is the proof.

`processLocalConnectionMessages` is now drained from
`actionTickAvm1ChildrenUnderAvm2` (wrapped in the child-context swap), which an
AVM1 child under an AVM2 Loader otherwise never gets.

### 4.2 Leg D2 — the `AVM1Movie` position mirror (NOT in the wave-1 brief)

With the bridge alone, `_v9` traced `(inner swf) x set, new value: **0**` instead
of `99` — i.e. the message crossed and the AVM1 method ran, but the value was
wrong. Disassembling `avm1.swf`'s DoAction settles what the callee actually does:

```
DefineFunction2 name="" numParams=0 regCount=2 flags=0x006a   ; 0x40 = preloadRoot
  Push "(inner swf) x set, new value: "
  Push reg1        ; = _root  (preloadRoot, NOT a parameter)
  Push "_x"
  GetMember
  Add2
  Trace
```

The handler takes **no arguments**. It traces `_root._x`. So the row needs the
LocalConnection ping *and* `content.x = 99` on the AVM2 side to be visible as
`_root._x` on the AVM1 side.

In Ruffle those are the same object: `loader.rs` marks the loaded MovieClip
itself as an AVM1 movie (`mc.set_avm1movie(uc)`) and hands that very display
object to AS3 as `Loader.content`. Our model keeps an AVM2 wrapper beside the
AVM1 `MovieClip`, so leg D2 mirrors the write across: `do_set_x`/`do_set_y` call
`avm1movie_sync_position`, which (gated on `g_avm1_child_levels != 0` **and**
`class_is_a(obj->cls, g_avm1movie_class)`) writes `mc->x`/`mc->y` on the child
root and sets the same `as_set_flags`/`markTransformedByScript` bookkeeping the
AVM1 `_x`/`_y` setters do. 19 lines. Position only — scale/rotation/alpha would
each need their own setter hook and nothing in the corpus writes them on an
`AVM1Movie`.

**This corrects both prior reports.** s15 priced these rows as "`AVM1Movie`
transform accessors → the AVM1 root's `_x`" and was told it was wrong; wave 1
refuted that and priced them as pure LocalConnection. The fixture says **both**
are required, and neither flips the row alone: s15 had the right second half and
the wrong trigger, wave 1 had the right trigger and dropped the second half.
(Wave 1's narrower claim — that no `AVM1Movie`→`MovieClip*` field on
`Avm2DisplayObjectExt` is needed — does survive: the mirror goes through
`g_avm1u2[0]`, no new struct field.)

## 5. NO-GO record (completion mechanisms)

Confirmed inert under the shipped patches; each needs its own session.

* **E — cross-VM hit test.** `avm2/mouse_pick_avm1_root` (1 line) and
  `avm2/mouse_pick_loader_avm1` (37). Three requirements, none cheap:
  (i) the AVM2 pick walk must descend into an AVM1 child's display list and
  attribute the hit to the wrapping `Loader`; (ii) a click landing on AVM1
  content must NOT also produce an AVM2 `click` on the Stage; (iii) **AVM1 timers
  must run under AVM2** — `mouse_pick_avm1_root` assigns `clip.onRelease` only
  from inside a `setInterval` callback, and `actionTickAvm1ChildrenUnderAvm2`
  deliberately excludes `processTimers` (`action.c` ~:24067: it "wants a frame
  budget this loop has no honest value for"). **Flip condition:** a defensible
  per-tick time budget for the dual-VM loop (the AVM2 frame loop has a real
  frame duration — hand it to `processTimers`), plus the pick-walk descent. The
  LocalConnection drain added in slot 2 is the precedent for adding a second
  AVM1 phase to that tick, so the timer arm is now a small edit gated on the
  budget question, not on plumbing.
* **F — cross-VM focus / Tab / `Selection` broadcast.**
  `avm2/selection_onsetfocus_mixed_avm` (5 lines, we emit **zero** of them) and
  `avm2/focus_events_mixed_avm_edittext` (48). All five lines of the smaller row
  need all three of: AVM2 focus changes broadcasting into AVM1's `Selection`
  listener list with `null` for AVM2 objects; the AVM1 child's TextFields present
  in the AVM2 tab order; AVM1 `onSetFocus`/`onKillFocus` dispatch. No cheap
  slice. **Flip condition:** all three, together.
* **G — `mixed_avm/avm1_loads_avm2`.** `verify_output.py:2339` gates the AVM2
  child's table linkage on the *parent's* VM. Build-system arc. Unchanged.
* **H — `avm2/avm1_root`.** Ceiling is `ruffle_matched`, not `pass`; see the docs
  patch. Deliberately left alone.

## 6. Ownership / conflict notes

* `avm2_display.c`: my edits are `input_deliver`'s three mouse call sites,
  `validate_add`'s #2180 arm, the `g_avm1movie_class` tentative definition, a new
  static `avm1_child_mouse`, and (slot 2) a new static `avm1movie_sync_position`
  plus one call each in `do_set_x`/`do_set_y` (~:3690/:3720). The class
  descriptor tables that `w2-all-classes-display` owns are ~10 000 lines away;
  the only shared region to watch on merge is the DisplayObject property surface
  if that agent also touched `do_set_x`/`do_set_y`.
* `action.c`: everything is inside the existing `#ifdef SWF_AVM2` dual-VM block
  (:23900-24260) except three small hunks in the AVM1 LocalConnection
  implementation (:2790-3160), all of them themselves `#ifdef SWF_AVM2`.
* `avm2_net.c`: LocalConnection section only.
* Both files compile clean (`gcc -fsyntax-only`) **with and without** `SWF_AVM2`,
  so AVM1-only builds are unaffected by construction.
