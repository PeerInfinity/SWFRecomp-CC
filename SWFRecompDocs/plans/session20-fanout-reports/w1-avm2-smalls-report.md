# w1-avm2-smalls — session 20 wave 1: the unpriced `avm2` tail (16 rows + 3 riders)

Read-only diagnosis. **No source edits, no commits.** Every one of the 19 rows was re-run at
HEAD `4b05de6ef`, no-graphics, **sequentially** (`-P 1`), `SWFRECOMP_COMPILE_TIMEOUT=2400`,
`--diff --verbose --save-actual`. Scratch (actuals, per-test JSON, logs, the rule-3 measuring
script `km.py`, `summary.txt`):
`<scratchpad>/w1-avm2-smalls/` (`act/`, `log/`).

---

## 1. HEADLINE — cost-per-flip ranking, and the slot I nominate

**Four `+1 effective` flips are available in this family and none of them was on the board.**
Three of the four are *in-place value corrections* (no line insertion), so I could **simulate the
fix** against `verify_output.py`'s own `ruffle_subset_match` and prove the flip before writing a
line of C. All four simulations return `ruffle_matched = True`.

| # | row | flip | mechanisms | owner file · function | size | canary cost |
|---|---|---|---|---|---|---|
| **1** | `avm2/textblock_recreateline` | `output_mismatch` → **`ruffle_matched`** | **1** (two field resets) | `avm2_text.c:7580` `tb_recreate_text_line` | **XS ~4 lines** | ~15 FTE rows |
| **2** | `avm2/number_to_string` | `output_mismatch` → **`ruffle_matched`** | **1** (ECMA notation boundary) | `avm2_value.c:703-708` | **S ~10 lines** | broad numeric (~40 rows) |
| **3** | `avm2/avm1_root` | `output_mismatch` → **`ruffle_matched`** | **1** (`_level0` under an AVM2 root) | `action.c:21614` | **S 1-3 lines** | `mixed_avm/*`, avm1 target-path rows |
| **4** | `avm2/tab_ordering_properties` | `output_mismatch` → **`pass`** | **2** (tabEnabled default; seal 2 classes) | `avm2_display.c:7222` + 2 class flags | **S code / M canary** | **134 rows** (111 TextField + 23 SimpleButton) |
| 5 | `avm2/simplebutton_childevents_multichild` | → `ruffle_matched` | 1 (instance-name counter) | `avm2_display.c` `button_construct_states` | M | button + name-tracing rows |
| 6 | `avm2/textline_atom_index_at_char_index` | → `ruffle_matched` | 2 (`getAtomIndexAtCharIndex`; a spurious `#2175`) | `avm2_text.c` FTE | M | FTE rows |
| 7 | `avm2/sound_load_multiple` | → `pass` | 2-3 (method + `#2037`/`#2084` sequencing) | `avm2_media.c` Sound | M/L | audio rows |

### Nomination — ONE wave-2 slot, `w2-avm2-smalls`, taking rows 1 + 2 + 3 = **+3 effective**

They are three independent patches in **three different files** (`avm2_text.c`, `avm2_value.c`,
`actionmodern/action.c`), each provably sufficient on its own, and none of the three files is
claimed by a listed wave-2 sibling (`w2-coerce` owns only `propertyCoerceToNumber` in `action.c`,
~24 000 lines away from `action.c:21614`; `w2-evenodd` / `w2-gfx-text-smalls` own `avm2_display.c`,
which rows 1-3 do not touch). **Row 1 alone is the single cheapest flip I found anywhere in this
family: two field resets in one function.** If the slot gets only one hour, it should be row 1,
then row 3, then row 2.

Row 4 (`tab_ordering_properties`) is a **separate** nomination: its code is small but it needs a
134-test canary sweep, which is most of a session by itself. Do not bundle it with 1-3.

---

## 2. The method finding the coordinator should carry forward

**The raw inventory diff-line counts overstate the real defect set by up to 70× in this family**,
and the rule-3 `ours-only` metric is what predicts a flip. Measured for all 19 rows
(`ours` = `_diff_indices(actual, output.txt)`; `theirs` = the same against `output.ruffle.txt`;
`ONLY` = `ours \ theirs`, which must reach **0** for `ruffle_matched`):

```
test                                       exp  act   raw   ruf  ONLY   KF
avm2/textblock_recreateline                180  181   141   140     2   KF+RTXT   <- 70x
avm2/avm1_root                              58   34    46    53     1   KF+RTXT   <- 46x
avm2/number_to_string                      353  353   116   104    12   KF+RTXT   <- 10x
avm2/simplebutton_childevents_multichild   152  132   119   101    18   KF+RTXT   <- 6.6x
avm2/textline_atom_index_at_char_index      40   37    19     3    16   KF+RTXT
from_shumway/.../events/loader-events       36   35    31    24     7   KF+RTXT   (artifact, see 4.2)
mixed_avm/avm2_loads_avm1_events            26   26    21    18     4   KF+RTXT   (artifact, see 4.1)
avm2/verify_method_info_duplicate            2    1     1     1     1   KF+RTXT
avm2/tab_ordering_properties               732  732   171     0   171   -          <- 171 -> 2 mechanisms
avm2/focus_events_mixed_avm_edittext        49   23    49     0    49   -
avm2/dependent_strings                      84   83    38     0    38   -
avm2/mouse_pick_loader_avm1                 42   40    26     0    26   -
avm2/sound_load_multiple                    19    7    16     0    16   -
avm2/selection_onsetfocus_mixed_avm          5    0     5     0     5   -
avm2/loader_applicationDomain                4    0     4     0     4   -
avm2/bom                                     9    9     3     0     3   -
avm2/from_shumway/.../LoaderLoadBytesTest    4    3     3     0     3   -
avm2/swz                                     2    0     2     0     2   -
avm2/loader_load                           128  128     2     0     2   -
```

**But `ours-only` is itself sometimes an alignment artifact, and I refuted two of my own
re-pricings that way** (§4.1, §4.2). The discipline that separates the two cases:

* **Real** when our actual and the expectation are *aligned* at those indices and the differences
  are pure VALUES (rows 1, 2, 3, 5). Then substituting the expected text in place and re-running
  `ruffle_subset_match` is a faithful simulation — I ran exactly that for all four and all four
  returned `True`.
* **Artifact** when our actual is *shifted* relative to the expectation and Ruffle happens to
  coincide with Flash in the shifted window (`avm2_loads_avm1_events`, `loader-events`). There the
  `ONLY` count is meaningless; the honest metric is `unified_diff(ruffle, ours)`, which for those
  two rows is 8 and 15 lines across 2-3 independent mechanisms.

`raw / ONLY` is a screening ratio, not a verdict. Screen with it, then check alignment.

---

## 3. GO verdicts, per mechanism

### 3.1 GO (XS) — `avm2/textblock_recreateline`: `recreateTextLine` must reset `userData` and `y`

**The standing verdict of record is REFUTED.** s12 adjudicated this row "unflippable"; s15
(`wave1-textblock.md`, `w2-textblock-report.md`) re-confirmed "+1..2 correct lines, NOT a
regression, no flip"; s16's board said it "cannot be reproduced locally at all". Measured today:
**141 raw diff lines, exactly 2 ours-only**, both aligned value diffs, and both oracles agree.

```
[36] Test.as:77  trace(line2.userData)   EXP 'null'  RUFFLE 'null'  OURS 'hello world!'
[54] Test.as:97  trace(line2.y)          EXP '0'     RUFFLE '0'     OURS '60'
```

`tb_recreate_text_line` (`SWFModernRuntime/src/avm2/avm2_text.c:7580`) resets `validity`,
`text_block`, `hide_block_from_script`, `specified_width`, `previous_line`, `next_line` — and
nothing else. Ruffle's `TextLine::reset_properties`
(`~/CC/ruffle/core/src/display_object/text_line.rs:92`) additionally does `set_x(ZERO)` /
`set_y(ZERO)`; `userData` is null in Ruffle for its own reason, but **Flash's `output.txt` also
says `null`**, so resetting it is Flash-correct, not a Ruffle chase.

* **Patch sketch**: in `tb_recreate_text_line`, after the existing reset block, add `x = 0`,
  `y = 0` on the line's display-object ext and clear the TextLine's `user_data` to null.
  (`x` already reads 0 for us; set it anyway to match Ruffle's reset list.)
* **Why nothing else moves**: `dumpInfo` (the source of every other line in this 180-line
  fixture) prints only `validity` / `textBlock` / `previousLine` / `nextLine`. The script
  re-assigns `line2.y = 60` explicitly after each later recreate. Verified by simulation:
  substituting indices 36 and 54 gives `ruffle_matched` (ours 139 ⊆ ruffle 140).
* **Canary**: `avm2/textblock_*`, `avm2/textline_*`, `avm2/text_engine*`, plus `regression`.

### 3.2 GO (S) — `avm2/number_to_string`: the ECMA-262 §7.1.12.1 notation boundary

**s18's explicit pricing is REFUTED.** `w2-avmplus-numerics-report.md` §7 left this open as
"w1's H1(a) — `floor(log10(d))` notation boundary in `avm2_value.c:706` … **buys 12 of
`number_to_string`'s 116 lines and 0 flips on its own**; the other 104 need the subnormal Dragon4
arm." Those 12 lines **are exactly the ours-only set**: the other 104 are indices where Ruffle is
also wrong, so they are free. **H1(a) alone is a +1 effective flip.** s18 counted raw diff lines
against Flash's `output.txt` and never ran the ruffle-subset check.

The 12 lines are one mechanism in two directions:

```
[23-27,47-51]  EXP '9.999999999999997e-7'   OURS '0.0000009999999999999997'   (10 lines)
[32,56]        EXP '999999999999999900000'  OURS '9.99999999999999e+20'       (2 lines)
```

`avm2_value.c:703-708` decides notation with

```c
const double MIN_DIGITS = -6.0, MAX_DIGITS = 21.0;
double digits = floor(log10(d));
if (digits < MIN_DIGITS || digits >= MAX_DIGITS) { /* exponential */ }
```

ECMA-262 does not use `log10`. It uses the decimal exponent **`n` of the shortest
round-tripping representation** and takes exponential form iff `n < -5 || n > 21`. Both failures
are the gap between the two: `log10(9.999999999999997e-7)` rounds to exactly `-6.0` in double
precision (so we take the fixed branch where ECMA takes exponential), and `9.999999999999999e20`
has `n = 21` (so ECMA takes the fixed branch where our `>= 21` takes exponential).

* **Patch sketch**: the function *already* calls `shortest_digits(d, digs, &e10)` inside the
  exponential branch. Hoist that call above the branch and test
  `if (e10 < -6 || e10 > 20)` (ECMA `n == e10 + 1`) instead of the `log10` test. ~10 lines,
  one function, no new helper.
* **Open risk the wave-2 agent must check first**: `format_plain` has never been asked to emit a
  21-digit integer-valued double (`999999999999999900000`), because we have always taken the
  exponential branch there. Verify it before trusting the flip.
* **Blast radius**: `avm2_value.c` is AVM2-only (AVM1 number formatting is elsewhere), but every
  AVM2 number→string goes through this. **Canary**: `avm2/number_*`, `avm2/int_*`, `avm2/uint_*`,
  `avm2/matrix3d_precision` (s18 records that this function's last rewrite was driven by it),
  `from_avmplus/ecma3/Number/*`, `from_avmplus/as3/Number/*`, `regression`.

### 3.3 GO (S) — `avm2/avm1_root`: `_level0` must be `undefined` when level 0 is an AVM2 movie

**The standing NO-GO is REFUTED as stated.** s15 (`w2-avm1-child-report.md` row 8), s16
(`wave1-avm1-child.md` lead H) and s17 (`w2-crossvm-legE-report.md`) all record
"**NO-GO**, ceiling is `ruffle_matched`, needs session-sized cross-VM target-path machinery", and
`RUFFLE_VS_FLASH_DIFFERENCES.md:462` repeats it. The ceiling claim is right; the *cost* claim is
wrong. Measured: 46 raw diff lines, **exactly 1 ours-only**, and it is not cross-VM path
resolution at all:

```
[2]  EXP '_level0: undefined'   RUFFLE '_level0: undefined'   OURS '_level0: _level0'
```

Both oracles agree. The root movie of this test is AVM2; there is no AVM1 movie on level 0, so
an AVM1 child cannot see one. We resolve `_level0` unconditionally to `&root_movieclip`
(`SWFModernRuntime/src/actionmodern/action.c:21614`, inside the `parse_level` arm:
`if (lid == 0) { mc = &root_movieclip; }`; the sibling arm at `:36975` does the same).

* **Patch sketch**: gate both `lid == 0` arms on `g_avm1_under_avm2_ready`
  (`action.c:24945`, set by `avm1UnderAvm2Substrate` only when an AVM1 child boots under an AVM2
  root) and `return NULL` / resolve to undefined when it is set. 1-3 lines.
* **Simulated with full propagation, not just the one line.** Making `_level0` undefined also
  changes three *other* lines of our actual (`_level0: _level0` in the second child,
  `_level0.level0Clip: …`, `typeof _level0.level0Clip: movieclip`). I re-ran the subset test with
  **all four** lines changed: still `ruffle_matched` (ours 45 ⊆ ruffle 53), because those three
  indices are ones where Ruffle also disagrees with Flash.
* **Blast radius is tiny and enumerable**: the only corpus files that mention `_level0` under an
  AVM2 root are `avm2/avm1_root/{avm1_child.as,other_child.as}` and one graded line,
  `mixed_avm/avm2_loads_avm1/output.txt:8` `_root == _level0: false` — which stays `false` with
  `_level0` undefined (that test currently **passes**; it is the mandatory canary).
* Rule 3 is satisfied twice over: the target status is `ruffle_matched` on a `known_failure` row
  **and** the value we adopt is Flash's, so this is not a drift onto Ruffle.

### 3.4 GO (S code, M canary) — `avm2/tab_ordering_properties`: two mechanisms, 171 → **pass**

This is the row the brief was right about: **nobody had ever costed it**, it is not
`known_failure`, it has no `output.ruffle.txt`, and it is **not in any ignore list** (only the
unrelated sibling `tab_ordering_properties_tab_index_edge_case` is). Target is `pass`.

732 expected / 732 actual — **same length, no misalignment at all**. Splitting by the fixture's
own `===== section =====` markers, 4 of the 8 sections are already byte-perfect:

```
stage        103/103  changed=0      movie clip                84/84  changed=0
text          95/95   changed=46     movie clip button mode     84/84  changed=2
text type in  95/95   changed=48     movie clip with index      84/84  changed=0
button        95/95   changed=48     sprite                     84/84  changed=0
```

**M1 — `tabChildren` must not exist on `TextField` / `SimpleButton` (≈168 of 171 lines).**
`tabChildren` is declared on `DisplayObjectContainer`; `TextField` and `SimpleButton` extend
`InteractiveObject` and are **sealed** classes in both Flash and Ruffle
(`~/CC/ruffle/core/src/avm2/globals/flash/text/TextField.as:11`,
`.../display/SimpleButton.as:10` — neither is `dynamic`). So reading `obj.tabChildren` raises
`ReferenceError #1069` and writing it raises `ReferenceError #1056`; `for..in` never sees it.
We answer `undefined` on the read and **create an enumerable expando** on the write (hence our
extra `enumerated tabChildren` lines).

We already have the whole sealed-object machinery — `avm2_object_is_dynamic`
(`avm2_ops.c:216`) keys off `AVM2_CLASS_FLAG_SEALED`, and `avm2_throw_1069`
(`avm2_error.c:536`) / the `#1056` raise (`avm2_ops.c:1194`) emit **exactly** the two message
strings this fixture expects. The fix is therefore two `cls->flags |= AVM2_CLASS_FLAG_SEALED;`
lines on the `TextField` and `SimpleButton` builtin classes, in the same shape as the ~30
existing uses. Internal `avm2_object_set_dynamic` calls bypass the check
(`avm2_object.c:141`), so runtime-internal expandos such as `__blendMode` keep working.

**M2 — `tabEnabled`'s default is per-type, and the getter ignores it (3 lines).** Ruffle
`InteractiveObject::tab_enabled_default` is `false` in general, `is_editable()` for EditText
(`edit_text.rs:3184`), `true` for an AVM2 button (`avm2_button.rs:807`), and `is_button_mode()`
for a MovieClip (`movie_clip.rs:3318`). **We already implement all four rules** — in
`obj_tab_enabled` (`avm2_display.c:15821`), used by the tab-order walk. The *public getter*
`io_get_tab_enabled` (`avm2_display.c:7222`) does not call it and returns the raw
`tab_enabled_set ? tab_enabled_val : false`. Fix = make the getter call `obj_tab_enabled`
(plus a forward declaration). **One line.**

* **Cost is the canary, not the code**: 111 `avm2` tests mention `TextField` and 23 mention
  `SimpleButton`; all of them must be re-run, because sealing a class that has been dynamic since
  the runtime was written can surface unrelated latent expando use. No expected output in the
  corpus except this fixture's currently asserts `#1056`/`#1069` on either class, so the
  *expectation* surface is clean; the *behaviour* surface is not.
* Cheaper fallback if the sweep blows up: register a throwing `tabChildren` trait on the two
  classes instead of sealing them. It buys the same 168 lines with a 2-test canary, but it hides
  a real, Flash-true bug — take it only as a last resort and write it up in
  `RUFFLE_COMPAT_TWEAKS.md`.

### 3.5 GO (M, uncertain) — `simplebutton_childevents_multichild`: the default instance-name counter

119 raw diff lines, **18 ours-only, all one mechanism**: the `instanceN` default name. Flash and
Ruffle agree on `instance9/10/8/7/16/15` where we say `instance6/7/5/4/10/9`. The counter drifts
by 3 across the first `SimpleButton` state construction and by 6 by the end, i.e. Flash allocates
3 more names per pass than we do. In-place substitution simulates to `ruffle_matched` (101 ⊆ 101).

Owner: `avm2_display.c` `button_create_state` / `button_construct_states` (~12 810-12 895).
Our wrapper `Sprite` is named **once, after all four states exist**
(`set_default_instance_name` inside `button_construct_states`, with a comment citing
`simplebutton_symbolclass`); Ruffle names it in `post_instantiation` during
`fire_state_events`. The exact allocation order must be read off
`~/CC/ruffle/core/src/display_object/avm2_button.rs`, not guessed.

**Why it is ranked 5th and not 1st despite being one mechanism**: (a) `ctx->instance_counter` is
global, so a mis-step renumbers every test that traces a default name; (b) the existing code path
carries a comment pinning the current order to a *passing* sibling
(`simplebutton_symbolclass`), which is a `rider-already-green` regression risk; (c) I could not
establish whether the fix is "name 3 more existing objects" or "create 3 objects we never
create" — only the first is a safe in-place substitution, and my simulation assumes it.
**Shared mechanism**: the same counter is one of three defects in
`from_shumway/as3-loader/events/loader-events` (§4.2), which is the second row it would move.

### 3.6 GO (M) — `avm2/textline_atom_index_at_char_index`

19 raw / **16 ours-only**, aligned, two mechanisms, and Ruffle is nearly exact here (only 3 diffs),
so `ruffle_matched` demands near-perfection:

1. `TextLine.getAtomIndexAtCharIndex` always returns `-1` (9 lines). Not implemented.
2. The final `TextBlock.createTextLine` throws a spurious `Error #2175: One or more elements of
   the content of the TextBlock has a null ElementFormat` (7 lines, the tail of the file). Both
   oracles create the line.

Owner: `avm2_text.c` FTE. Real work, but bounded and self-contained.

### 3.7 GO (M/L) — `avm2/sound_load_multiple`

Re-tested per rule 2: the ignore-list entry is an accurate open-bug note, not an accepted diff.
3/19 at HEAD, dying at case 3 on `TypeError #1006: loadCompressedDataFromByteArray is not a
function`. The fixture grades Flash's **error sequencing** across 9 cases
(`#2037 Functions called in incorrect sequence` for 5, `#2084 AMF encoding … cannot exceed 40K`
for the last) — no audio decoding is required, but the method, a per-`Sound` load state machine
and the 40 K argument check are all needed and cannot be scored piecemeal. Owner:
`SWFModernRuntime/src/avm2/avm2_media.c`. Target `pass` (no `output.ruffle.txt`).

---

## 4. HOLD — with the completion mechanism each one needs

### 4.1 `mixed_avm/avm2_loads_avm1_events` — HOLD. **I refuted my own re-pricing here.**

The screening ratio looked excellent (21 raw → 4 ours-only) and the 4 lines look like "one
missing `open` event". **It is an alignment artifact.** Printed against Ruffle's own trace, our
output *is* Ruffle's sequence with two defects, and Ruffle happens to coincide with Flash exactly
in the window our shift lands on:

```
        RUFFLE                    OURS
 [6]    frame 1                   child          <- (a) child's frame 1 runs before the root's enterFrame
 [7]    child                     frame 1
 [8]    frame 2                   init           <- (b) init/httpStatus/complete land a frame early
```

`unified_diff(ruffle, ours)` = 8 lines. **s19 `w1-loaders-report.md` §3.3 is exactly right and
still current**: three mechanisms were named, `unload` landed in s19 (`w2-loaders` patch 1), and
the remaining two are (a) route an AVM1 child load through the same `pending_boot` → next-drain
rotation `avm2_loader_run_exit_frame` uses for AS3 children, and (b) boot the AVM1 level after
the tick's `enterFrame` broadcast. **Completion mechanism: the cross-VM load-tick rotation —
session-sized, and it is `w2-loaders`' arc, not a smalls item.** Do not re-derive it.

### 4.2 `from_shumway/as3-loader/events/loader-events` — HOLD, 3 mechanisms, diff-line only

31 raw / 7 ours-only, again a shift artifact. Against Ruffle, three independent defects:
(1) a missing `root loader: httpStatus 1293`; (2) the loaded root's default instance name is
**`null`** for us where both oracles say `instance3`/`instance5` (the shared counter of §3.5 —
`loader_boot_child_swf` never calls `set_default_instance_name` on a loaded root); (3) the same
frame-vs-load ordering as §4.1. s19 §3.4 named all three; nothing has moved.
**Completion mechanism: §3.5's counter work plus §4.1's rotation.** `known_failure`, so the
ceiling is `ruffle_matched` and all three are required.

---

## 5. NO-GO — re-verified at HEAD, do not re-cost

Every one of these was re-run today and sits **exactly** at its documented ceiling.

| row | measured today | disposition | verdict |
|---|---|---|---|
| `avm2/bom` | 3 diffs, all `dataFormat=variables` | `RUFFLE_VS_FLASH_DIFFERENCES.md` "URLVariables.toString"; `avm2/ignored_tests.txt` | **NO-GO permanently.** No `output.ruffle.txt` and not `known_failure`, so neither `pass` nor `ruffle_matched` exists. Ceiling 6/9 — confirmed. |
| `avm2/loader_load` | 2 diffs: `aaa=bbb&cccc=true` vs `cccc=true&aaa=bbb` (lines 81, 99) | same doc, same list | **NO-GO.** Ruffle hashbrown bucket order. Ceiling 126/128 — confirmed. |
| `avm2/swz` | 0/2 | `ACCEPTED_DIFFS.md` Cat 13 (AOT ceiling, Flex `framework_*.swz`) | **NO-GO.** |
| `avm2/loader_applicationDomain` | 0/4 | `ACCEPTED_DIFFS.md` Cat 13 | **NO-GO.** |
| `avm2/dependent_strings` | 38 diffs, every one a `true`/`false` vs a blank line | `RUFFLE_VS_FLASH_DIFFERENCES.md` "ruffle::isDependent" | **NO-GO.** The graded `output.txt` is Ruffle describing its own rope-string internals; Flash would print what we print. |
| `avm2/verify_method_info_duplicate` | 1 diff: the trailing `#1065` | `ACCEPTED_DIFFS.md:114` Cat 2 | **NO-GO stands**, and the doc is complete and correct (see §7 note 3). |
| `avm2/focus_events_mixed_avm_edittext` | **0/49**; we emit 23 lines, 11 of them `mouseFocusChange: [object Loader]` — we never reach the AVM1 content and never broadcast AVM1 `Selection` | s16 leg F, s17 `w2-crossvm-legE` | **NO-GO.** Needs the AVM2 focus manager crossing into an AVM1 child + AVM1 `Selection`. Session-sized. |
| `avm2/selection_onsetfocus_mixed_avm` | **0 lines emitted**, 5 expected | s16/s17 leg F | **NO-GO** for a smalls slot. It is the cheapest *probe* of leg F (5 lines, all one mechanism) but it is still the whole cross-VM focus model. |
| `avm2/mouse_pick_loader_avm1` | 26 diffs (was 27 at s17) | s17 `w2-crossvm-legE` improved it, no flip | **NO-GO.** Remainder is leg F + AVM1 button dispatch under AVM2. |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | 1 missing line, `from loadee: loaded` | s17 `w2-trace-smalls` §Row 5, s18 N2, s19 | **NO-GO.** `DefineBinaryData` → SWF recompile arc. |

---

## 6. Bucket verdicts — **3 of the brief's 5 buckets are refuted**

The brief asked me to correct its bucketing. It does not survive measurement:

* **"String/encoding" (`bom`, `dependent_strings`, `number_to_string`, `swz`) — REFUTED, no
  bucket exists.** Three are permanent NO-GOs with three *different* causes (hashbrown
  enumeration order; a Ruffle-only debug hook; the AOT/`swz` ceiling). The fourth,
  `number_to_string`, is not a string/encoding row at all — it is **numeric formatting**, owner
  `avm2_value.c`, and it is the only live row of the four. **Do not fund a wave-2 "strings" slot.**
* **"Text engine (FTE)" — CONFIRMED**, and it is the family's best bucket: 2 rows, both live,
  both in `avm2_text.c`, +2 effective. But their costs are XS and M, so split them rather than
  slotting them together.
* **"Focus/tab/selection" — REFUTED as a bucket, and it hid the family's biggest win.**
  `tab_ordering_properties` is **not** a focus-model row: it never focuses anything, it probes
  class shape (sealedness) and a property default. Its owners are the AVM2 class-flag table and
  `avm2_display.c`'s `InteractiveObject` getter. The other two rows are the genuine cross-VM
  focus NO-GO. Grouping them is exactly the `worklist-labels-name-symptoms-not-owners` trap.
* **"Loader / mixed-AVM" — mostly correct but already owned.** 4 NO-GO + 2 HOLD, all of them
  either dispositioned or s19 `w2-loaders` material. The one live row in the group,
  `avm1_root`, is **not a loader row**: it is AVM1 `_levelN` resolution in `action.c`.
* **"Verifier / buttons" — REFUTED as a bucket.** `verify_method_info_duplicate` is a NO-GO
  ABC-parser row; `simplebutton_childevents_multichild` is an instance-name-counter row that
  shares its mechanism with `loader-events`, which the brief put in the *loader* bucket.

**The real bucketing** is: (A) FTE `avm2_text.c` — 2 flips; (B) AVM2 numeric formatting
`avm2_value.c` — 1 flip; (C) AVM1 level resolution `action.c` — 1 flip; (D) AVM2 class shape
`avm2_display.c` + class flags — 1 flip; (E) the default instance-name counter — 1 flip + 1
diff-line row; (F) cross-VM focus / load-tick — 5 rows, all NO-GO/HOLD, session-sized, already
owned; (G) permanent dispositions — 6 rows.

---

## 7. Refutations, listed

1. **My brief's premise — "nobody has costed these recently" — is HALF WRONG, and the wrong half
   was the expensive half.** 10 of the 19 rows carry an explicit, still-accurate NO-GO of record
   (§5); re-costing them was cheap only because I checked the dispositions first. But 4 rows
   carry a *stale* verdict, and all 4 turned out to be flips (§3.1-3.4). The distinguishing
   feature is not recency — it is that every stale verdict was priced in **raw diff lines against
   `output.txt`** before anyone ran the ruffle-subset check.
2. **s18 `w2-avmplus-numerics-report.md` §7: "buys 12 of `number_to_string`'s 116 lines and
   0 flips on its own" — REFUTED.** Those 12 lines are the entire ours-only set; the fix is
   +1 effective (§3.2).
3. **s12/s15/s16 on `textblock_recreateline` ("adjudicated unflippable", "+1..2 correct lines",
   "cannot be reproduced locally") — REFUTED.** It reproduces locally, and it is 2 field resets
   from `ruffle_matched` (§3.1).
4. **s15/s16/s17 + `RUFFLE_VS_FLASH_DIFFERENCES.md:462` on `avm1_root` ("session-sized cross-VM
   target-path machinery") — REFUTED as a cost claim.** The ceiling claim (`ruffle_matched`, not
   `pass`) is correct and I am not disputing it; the *route* to that ceiling is one gate on
   `_level0`, not the cross-VM path walk (§3.3). The RVF doc should be amended.
5. **My own first reading of `mixed_avm/avm2_loads_avm1_events` (21 raw → 4 ours-only ⇒ "one
   missing `open` event") — REFUTED BY ME** (§4.1). Same for `loader-events` (§4.2). This is the
   `ours-only` metric's failure mode and it is worth more than either row: **screen with
   `raw/ONLY`, then verify alignment before believing it.**
6. **`avm2/ignored_tests.txt`'s "net 0" arithmetic for `verify_method_info_duplicate` is loose.**
   Emitting the `#1065` flips `_duplicate` `output_mismatch → pass` (+1 effective) while demoting
   `_oob` `pass → ruffle_matched` (0 effective, since `ruffle_matched` counts). So the headline
   arithmetic is **+1**, not 0 — which is precisely why it is dangerous, and
   `ACCEPTED_DIFFS.md:114` already says so in full ("the headline would read '+1, zero
   regressions' while a Flash-matching test had silently been made Flash-wrong"). The **decision
   is unchanged and correct**; only the one-line summary in the ignore file understates the trap.

---

## 8. New unclaimed leads

* **`TextField` and `SimpleButton` are dynamic in our runtime and sealed in Flash.** Beyond
  §3.4's 168 lines this is a latent divergence on every sealed-class observable —
  `hasOwnProperty`, `delete`, `for..in`, `#1056`/`#1069` — for the two most-used AS3 display
  classes. Nothing else in the corpus grades it today (I grepped every `output*.txt`: the only
  `#1056`/`#1069`-on-TextField expectation in the whole corpus is `tab_ordering_properties`'s),
  so it is latent rather than a scoreboard item. **A `regression/` fixture is warranted** once
  §3.4 lands, with the Ruffle exporter as the oracle.
* **`format_plain` in `avm2_value.c` has never emitted a 21-digit value**, because the
  `>= 1e21` boundary bug always routed those to exponential first. Whoever takes §3.2 is the
  first caller.
* **The default instance-name counter under-consumes in at least two places** — the
  `SimpleButton` multi-child state wrappers (§3.5) and loaded roots, which get `null` instead of
  a name (§4.2). Both are the same `set_default_instance_name` / `ctx->instance_counter` pair.
  A single "audit every Ruffle `post_instantiation` site against ours" pass would close both,
  and it is the only mechanism in this family that moves **two** rows.
* **`avm2/selection_onsetfocus_mixed_avm` is the cheapest probe of cross-VM focus (leg F)**: 5
  expected lines, we emit **zero**, one mechanism. It is still NO-GO for a smalls slot, but if
  leg F is ever funded, this is the row to drive it with — s17 `w2-crossvm-legE` §262 said the
  same and it is still true.
* **`obj_tab_enabled` vs `io_get_tab_enabled` is a pattern, not a one-off.** A correct internal
  per-type rule exists next to a public getter that ignores it. Worth one grep for other
  `io_get_*` getters in `avm2_display.c` that read a raw ext field where a sibling
  `obj_*(ctx, obj)` helper already implements the Ruffle default.

---

## 9. Reproduction

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
    --test=textblock_recreateline --diff --verbose \
    --save-actual=<scratch>/act/avm2_textblock_recreateline.txt
```

The rule-3 measurement (`<scratchpad>/w1-avm2-smalls/km.py`) loads `verify_output.py` as a module
and reuses **its own** `_diff_indices` / `ruffle_subset_match`, so the numbers above are the
grader's, not a re-implementation. `summary.txt` in the same directory is the §2 table.
