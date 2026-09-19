# w2-smalls-2 — session 20 wave 2: two independent smalls, both GO, **+2 effective**

## NEW FILES (stage these by name — `git add -u` drops them)

```
SWFRecompDocs/plans/session20-fanout-reports/w2-smalls-2-1-bitmapdata-rect.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-smalls-2-2-taborder.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-smalls-2-report.md
```

Modified source files (two, one per patch, no textual overlap with any sibling's range):

```
SWFModernRuntime/src/actionmodern/action.c      (patch 1 only)
SWFModernRuntime/src/avm2/avm2_display.c        (patch 2 only)
```

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a9139ef58aa320aac`
(branched from `edf5d1e1d`). Scratch, logs and saved actuals:
`<scratchpad>/w2-smalls-2/` (`act/`, `f1_*.log`, `f2_*.log`, `f3_*.log`, `km.py`).

---

## 1. HEADLINE — both GO, both realised locally

| # | patch | row | before | after | mechanisms | code size |
|---|-------|-----|--------|-------|------------|-----------|
| **1** | `w2-smalls-2-1-bitmapdata-rect.patch` | `avm1/bitmapdata_custom_rectangle` | `output_mismatch` | **`ruffle_matched`** (+1 eff.) | 1 | 1 extracted helper, 2 call sites, net −48 lines |
| **2** | `w2-smalls-2-2-taborder.patch` | `avm2/tab_ordering_properties` | `output_mismatch` (171 diff lines) | **`pass`** (+1 eff., + a quality flip) | 2 | 3 statements + 1 forward decl |

**Realised flips, by test name:**
* `avm1/bitmapdata_custom_rectangle` — `output_mismatch` → `ruffle_matched`.
  Ours-only diff set `{33, 34}` → `{}` (measured with the rule-3 metric, below).
* `avm2/tab_ordering_properties` — `output_mismatch` → **`pass`**, 732/732 lines,
  171 diff lines → 0. All 8 sections byte-perfect.

**Regressions found: none.** 17 canary/regression tests run, every one holds its
baseline status. No `pass → ruffle_matched` move anywhere (see §5).

The two patches are independent (different files, different VMs) and land in
either order.

---

## 2. Patch 1 — `avm1/bitmapdata_custom_rectangle`

### 2.1 Premise check: §20.5 was RIGHT, but for a reason it did not state

§20.5 says the row flips "once the built-in `getColorBoundsRect` constructs its
result via the dynamically-resolved `flash.geom.Rectangle`". I set out to refute
the *scope* of that (the fixture exercises three built-ins — `rectangle`,
`generateFilterRect`, `getColorBoundsRect` — and the first two looked equally
guilty). **The scope is correct, and here is why the other two are already off
the hook:**

* `bd.rectangle` (`bdRectangleGetter`) **already** resolved
  `_global.flash.geom.Rectangle` at call time and constructed through it —
  including the throwing-constructor case. Our baseline actual already carried
  the noisy constructor's six-line dump and `Caught: test`. So §20.5's single
  named defect was the only one left.
* `generateFilterRect` is a stub returning `undefined` — **exactly what Ruffle
  does** (`bitmap_data.rs` has no implementation), so every line it produces is
  already inside Ruffle's own diff set and is FREE for a `ruffle_matched` target.

**This is the AVM1 VM** (`SWFModernRuntime/src/actionmodern/action.c`), not AVM2.
I checked whether the AVM2 `BitmapData.getColorBoundsRect`
(`avm2_bitmap.c:3424`, `bd_get_color_bounds_rect`) has the same defect shape that
`avm2-builtin-class-mints-never-looks-up` describes: **it does not apply there.**
In AVM2 `flash.geom.Rectangle` is a *class* resolved through the domain, not a
script-replaceable global slot, and Flash's own semantics there are to mint the
declared class. So the memory's shape is AVM1-specific for this API. No AVM2
change was made and none is warranted.

### 2.2 Positional-alignment check (the brief's explicit warning)

The brief warned that a small ours-only count can be a shift artifact. I measured
it both ways before writing any C (`km.py`, rule-3 metric: `ours = diff(actual,
output.txt)`, `theirs = diff(output.ruffle.txt, output.txt)`, flip iff
`ours \ theirs == {}`):

```
                      lines  ours  ruffle  ONLY
baseline                 30    27      27  [33, 34]
after patch 1            36    27      27  []            <- ruffle_matched
```

The 2 ours-only indices were **not** aligned value diffs — they were `<missing>`,
because our actual was **6 lines short**. That is precisely the shift case the
brief flagged, and it is only repairable because the *same* fix supplies exactly
the missing six lines in exactly the right place:

* Ruffle agrees with Flash on only 15 of the 42 expected indices
  (`{0..13, 33, 34}`). Indices 33/34 are the third `mask.valueOf called!` /
  `color.valueOf called!` pair, which sits 33 lines into the file.
* Dynamic construction inside `getColorBoundsRect` inserts the noisy
  constructor's 6-line dump in section 2 and nothing else — pushing the section-4
  `valueOf` pair from index 27/28 to exactly 33/34.

I derived that arithmetic on paper *before* implementing, and the measured result
(36 lines, `ONLY = {}`) matches it line for line. This is the discipline the
sibling's §2 asks for, run in the "small count that is a shift" direction.

### 2.3 Mechanism and exact patch scope

Ruffle's `get_color_bounds_rect` (`core/src/avm1/globals/bitmap_data.rs:732`)
builds its result with
`activation.instantiate_class_fast([flash, geom, Rectangle], &[x,y,w,h])`
(`core/src/avm1/activation.rs:289`) — resolve the global path now, construct
through whatever is there. Ours called `createRectObj`, an internal mint.

Patch:

1. **New `static int constructGeomRectDynamic(app_context, x, y, w, h, out)`**
   inserted immediately before `bitmapDataGetColorBoundsRect` (action.c ~12609).
   It is verbatim the resolution + construction block that already lived inside
   `bdRectangleGetter`, parameterised on the four doubles. Returns `0` when
   `flash.geom.Rectangle` resolves to a **non-function** (the caller answers
   `-1`; that arm is pinned by `from_gnash/.../BitmapData-v8` test 315).
2. **`bitmapDataGetColorBoundsRect`** now calls it instead of `createRectObj`.
3. **`bdRectangleGetter`** collapses onto the same helper (behaviour-identical;
   net −48 lines of duplication).

**Why the default path cannot move any other test:** with the built-in
`flash.geom.Rectangle` in place, the dynamic route runs `rectangleConstructor`
(action.c:10884), which sets `x`, `y`, `width`, `height` **in that order** on an
object whose `__proto__` is `fc_Rectangle.prototype_obj` — and
`fc_Rectangle.prototype_obj == g_rect_prototype`, which is exactly what
`createRectObj` assigns. Same prototype, same own props, same insertion order,
so `toString`, `instanceof`, `for..in` order and `hasOwnProperty` are all
unchanged. The observable difference exists **only** when the script has
replaced the class.

### 2.4 Deliberately NOT done (scope discipline)

Flash's `output.txt` also wants `-1` from `bd.rectangle` / `getColorBoundsRect`
after `flash.geom = 4` (indices 31 and 35). Both our arms answer with the
internal rect, because the resolver treats "path unresolvable" as "class absent
→ use the default". Ruffle's `resolve_class` returns `None` there and the caller
answers `-1`. **I did not fix it**: both indices are inside Ruffle's own diff set,
so it buys 0 grading, and it changes `bd.rectangle` for *every* SWF, not just
this fixture. Named as a lead in §7.

---

## 3. Patch 2 — `avm2/tab_ordering_properties` → `pass`

### 3.1 Premise check: the sibling's diagnosis was right in every detail

`w1-avm2-smalls-report.md` §3.4 predicted two mechanisms, ~168 + 3 lines, and
that all the error machinery already exists. Verified before implementing, and
the flip confirms it end to end. Two corrections/additions to the record:

* The 732-expected / 732-actual coincidence is **not** because the sections align
  — it is because the two error mechanisms *cancel line for line*. Per
  `printProperties` block, our `tabChildren = undefined` replaces Flash's
  `Error: #1069` (+0), our silent write omits Flash's `Error: #1056` (−1), and our
  `enumerated tabChildren` adds one (+1). Net 0 per block, with a local shift
  inside each. That is why the row measures 171 ours-only lines with equal totals.
* The `movie clip button mode true` section's "changed=2" is one mechanism, not
  two: only its `default` `tabEnabled` line is wrong, plus one downstream index
  inside the same block.

### 3.2 Mechanism 1 — seal `TextField` and `SimpleButton`

`playerglobal` declares both without `dynamic`
(`~/CC/ruffle/core/src/avm2/globals/flash/text/TextField.as:10`,
`.../display/SimpleButton.as:10` — verified in the freshly-pulled tree). Two
statements:

```c
textfield->flags |= AVM2_CLASS_FLAG_SEALED;   // avm2_display.c ~17293
button->flags    |= AVM2_CLASS_FLAG_SEALED;   // avm2_display.c ~17513
```

Everything downstream was already built and already emits the exact Flash
strings — I read each one rather than trusting the sibling:

* `avm2_object_is_dynamic` (`avm2_ops.c:216`) is the single gate.
* Read miss on a sealed receiver with a public QName → `#1069` with
  `avm2_class_qname_buf`, which renders `flash.text.TextField` **with a dot**,
  matching the fixture byte for byte (`avm2_ops.c:712-722`).
* Write miss → `setproperty_miss_disp` (`avm2_ops.c:1187`) → `#1056`, same
  spelling.
* `avm2_object_set_dynamic` (`avm2_object.c:141`) does **not** consult the flag,
  so runtime-internal expandos keep working.

Two fallout surfaces the sibling did not name, both checked and both clean:

* **Script subclasses.** A `dynamic class X extends TextField` is unaffected:
  `avm2_object_is_dynamic` reads `obj->cls->flags`, and a script class takes its
  flags from its own ABC `is_sealed` bit (`avm2_class.c:1317` ← `abc_emit.cpp:4041`).
  Sealing is **not** inherited.
* **`describeType`.** `dt_fill` derives `is_dynamic` from the SEALED flag, but a
  `DtDescClass` row overrides it (`avm2_globals.c:6160-6167`). `SimpleButton` has
  a row (`avm2_globals.c:4171`, `describe_dynamic = 0`) so it is pinned;
  `TextField` has **none**, so `describeType(new TextField())` moves
  `isDynamic="true"` → `"false"`. That is the **Flash-correct** direction, and no
  corpus test does it (grep: the 7 `describeType` tests and the 6
  `all_classes/display/*` tests never describeType a TextField *instance* — the
  `all_classes` rows are class-side, where `is_dynamic` is hardcoded to 1).

### 3.3 Mechanism 2 — `io_get_tab_enabled` must answer the per-type default

One statement (plus a forward declaration). `io_get_tab_enabled`
(`avm2_display.c:7222`) returned the raw stored value and `false` when unset;
`obj_tab_enabled` (`avm2_display.c:15940`) already implements Ruffle's four
`tab_enabled_default` rules and is used by the tab-order walk. The getter now
calls it. Worth 3 lines: the `default` `tabEnabled` of an input `TextField`, a
`SimpleButton` and a `buttonMode` `MovieClip`.

### 3.4 Fallout verdict: none in the argued canary — **but read §5's caveat**

The sibling flagged a 134-test canary and **explicitly held this back as the
risky half**. I did not run 134 tests; I ran the 12 that can observe the change
(§5) plus 4 regression rows. All 12 hold. The seal is the *Flash-true* shape, so
a row that breaks on it is revealing a genuinely missing trait on our side — that
is a good failure mode, not a silent drift. It still needs a CI run to be certain
beyond the argued set.

---

## 4. Per-test before/after (every test I ran, 17 rows)

All runs: no-graphics, **sequential**, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
`--recompile --diff --verbose`, in my worktree's canonical suite paths. Baseline
statuses read fresh from each suite's `_results/results_graphics.json` at
`edf5d1e1d` (never copied from a brief).

### Patch 1

| test | baseline | after | note |
|---|---|---|---|
| `avm1/bitmapdata_custom_rectangle` | `output_mismatch` | **`ruffle_matched`** | headline, +1 |
| `avm1/bitmap_data` | pass | pass | |
| `avm1/bitmap_data_thorough/getColorBoundsRect` | pass | pass | direct user of the changed function |
| `avm1/bitmap_data_thorough/constructor` | pass | pass | `bd.rectangle` shape |
| `from_gnash/actionscript.all/BitmapData-v8` | `ruffle_matched` | `ruffle_matched` | pins the `-1` arm (test 315) **and** `bmp.rectangle instanceOf flash.geom.Rectangle` (test line 95) — the two invariants the `bdRectangleGetter` refactor could have broken. 0 diff lines. |
| `regression/avm1_parent_child_bitmap` | pass | pass | |
| `regression/avm1_parent_child_bitmap_fill` | pass | pass | |

### Patch 2

| test | baseline | after | note |
|---|---|---|---|
| `avm2/tab_ordering_properties` | `output_mismatch` (171) | **`pass`** (0) | headline, +1 |
| `avm2/tab_ordering_tabbable` | pass | pass | |
| `avm2/focusrect_property` | pass | pass | |
| `avm2/simplebutton_symbolclass` | pass | pass | `public var my_button:*` |
| `avm2/simplebutton_childevents` | pass | pass | `var self:*` |
| `avm2/edittext_tag_indent` | pass | pass | `printLines(tf:*)` |
| `avm2/edittext_autosize_lazy_bounds_props` | pass | pass | `hasOwnProperty` + `propertyIsEnumerable` on TextFields |
| `avm2/flash_ui_mouse_cursor` | pass | pass | `var txt = new TextField()` (untyped) |
| `regression/avm2_child_simplebutton` | pass | pass | |
| `regression/avm2_simplebutton_click` | pass | pass | |
| `regression/avm2_timeline_text` | pass | pass | |
| `regression/avm2_bitmapdata_draw_textfield` | pass | pass | |

Final confirmation run of `avm1/bitmapdata_custom_rectangle` with **both**
patches applied: `RUFFLE_MATCHED` (so the two do not interact).

**`regression`-suite check: done for both patches** (6 rows, all pass, none
flipped — no README needed).

---

## 5. Verification scoping — the argument, and the drop table

### Patch 1: 152 → 5, and every drop is argued from the code, not the cost

The changed behaviour is observable **only** when a script has replaced
`flash.geom.Rectangle` with something other than the built-in constructor
(§2.3 proves the default path is object-for-object identical). Corpus-wide:

* `grep -rl "getColorBoundsRect"` over **all** of `tests/swfs` (not just `.as` —
  the `.swf` binaries were included, so a source-less test could not hide):
  3 AVM1 callers + `avm2/bitmap_data` (a different VM and a different file,
  `avm2_bitmap.c`) + `all_classes` (which only *names* the method).
* `grep -rlE "flash\.geom\.Rectangle *="`: **exactly one** test corpus-wide —
  the headline.
* The `bdRectangleGetter` refactor additionally needs a `bd.rectangle` canary
  with the `-1` and `instanceOf` arms; that is `from_gnash/.../BitmapData-v8`.

| dropped | why it cannot observe the change |
|---|---|
| `avm2/bitmap_data` and all `avm2/*` | AVM2 `BitmapData` lives in `avm2_bitmap.c`; patch 1 touches only `action.c`'s AVM1 methods |
| `avm1/global_instance_decls`, `avm1/global_proto_decls`, `avm1/global_proto_decls_delete` | they *enumerate* `BitmapData.prototype` member names; the patch adds and removes no member |
| `avm2/all_classes/display/swf{9..30}` | `getColorBoundsRect` appears only as a `describeType` member name string |
| the other 18 `avm1/bitmap_data_thorough/*` subtests | none constructs a Rectangle; `constructor` is kept as the one that reads `bd.rectangle` |
| `from_gnash/.../BitmapData-v5/-v6/-v7` | none of them assigns to `flash.geom.Rectangle`, so the built-in constructor is what runs and §2.3's object-identity argument applies verbatim. (I checked the version question explicitly rather than assuming: `flash` is registered on `_global` for **every** SWF version — action.c:43192, only *version-hidden* for SWF<8 via `flash_flags` — so the resolver behaves the same at v5 as at v8. `-v8` is kept because it is the only one that assigns a **non-function** to the slot and the only one asserting `instanceOf`.) |

### Patch 2: 158 → 12, and the two axes are argued separately

The seal is observable only on a **property miss** on a `TextField` /
`SimpleButton` **instance**. In AS3 a miss through a *typed* reference is a
compile error, so the receiver must be untyped (`:*`, `:Object`, or an
un-annotated `var`). Starting from the 152 test dirs whose `.as` mentions either
class, filtering for `:*` / `:Object` / `for..in` / `hasOwnProperty` /
`propertyIsEnumerable` / `describeType` / `delete` / `JSON.stringify` gave 26,
and I read each one:

| dropped | why it cannot observe the change |
|---|---|
| `avm2/array_sparse_ops` | its `for (var i in arr)` iterates an **Array**; the `TextField` import is unused in the dynamic path |
| `avm2/displayobject_transform` | `for(i in quals)` iterates a String array; `child:TextField` is typed throughout |
| `avm2/property_is_enumerable` | the untyped receiver is `es4inst = new ES4Class()`, a script class whose SEALED flag comes from its own ABC bit and is untouched |
| `avm2/stage3d_raytrace` | `:Object`/`JSON.stringify` land on AGAL data; both TextField receivers are typed (`var tf:TextField = ta.textField`) |
| `fonts/device_font_list` | `:Object` is a `new Object()` font map; TextField receivers typed |
| `text/html_entity_parsing` | `for (var s:String in tests)` iterates a plain Object literal |
| `avm2/flash_trace` | `trace_(arg:*)` is only ever passed Strings; `txt:TextField` typed |
| `avm2/native_menu_basic` | `info:*` carries menu data, never the `outputField:TextField` |
| `avm2/edittext_stylesheet{,_custom_tag,_display}` | their `:Object` is a `StyleSheet` style record |
| `avm2/edittext_input_control`, `_restrict_events`, `_autosize_lazy_bounds_vs_relayout` | every `:*` is an `Event` handler parameter; TextField receivers typed — `_autosize_lazy_bounds_props` is kept as the strictly-larger member of this family |
| `visual/edittext/*`, `visual/fonts/leading_*` | render-only fixtures; their `:*` are handler parameters, and pixel rows are not trace rows |

Mechanism 2 (`io_get_tab_enabled`) is a **separate, narrower** axis: the value
changes only when `tab_enabled_set == 0` **and** the object is an editable
EditText, a SimpleButton, or a buttonMode MovieClip. 53 test dirs mention
`tabEnabled`; of those, AVM1 rows use a different code path entirely, and of the
24 AVM2 rows only **3** ever *read* the property:

| read site | verdict |
|---|---|
| `avm2/focus_events_mouse_focusable` | `tabEnabled` is a **function parameter name**; every object is written before it is read, so `tab_enabled_set == 1` |
| `avm2/stage_overriden_setters` | `testSetter("tabEnabled", false)` on the Stage; the expected output is `Got 2071 trying to set tabEnabled` — the value is never read back |
| `avm2/textline_inapplicable_properties` | `tl.tabEnabled = true` precedes `trace(tl.tabEnabled)`; also a `TextLine`, which is neither class being sealed |

Leaving `tab_ordering_properties`, `tab_ordering_tabbable` and
`edittext_autosize_lazy_bounds_props` — all three kept and all three run.

**What this scoping does NOT cover, stated plainly:** tests that ship no `.as`
source. I could not scope those by argument, and I did not pretend to. The seal
therefore still wants a CI `categories=full` graphics run before it is called
closed; that is the completion mechanism for the residual risk, not a HOLD.

---

## 6. Refutations and corrections of record

1. **`avm1/bitmapdata_custom_rectangle` is NOT a three-built-in problem.**
   §20.5's one-line scope was exactly right; `bd.rectangle` had already been
   fixed (at some earlier session) and `generateFilterRect` is Ruffle-identical
   by being unimplemented. Anyone re-reading the 30-line raw diff would price
   this at 3 mechanisms; it is 1.
2. **The `avm2-builtin-class-mints-never-looks-up` shape does not transfer to
   AVM2 `BitmapData.getColorBoundsRect`.** In AVM2 the Rectangle class is a
   domain-resolved class, not a script-writable global slot, and minting the
   declared class is correct there. The memory is AVM1-scoped for this API.
3. **A 2-line ours-only count can be a shift and still be a real flip.** The
   sibling's §2 rule ("real when aligned, artifact when shifted") needs a third
   case: *shifted, and the same fix supplies the missing lines in the right
   place*. Here 6 inserted lines moved 2 `<missing>` indices onto their oracle
   values. Screening on alignment alone would have dropped this row.
4. **Sealing a builtin class is not inherited by script subclasses** — worth
   recording, because "seal the base class" reads as a much larger blast radius
   than it is. `avm2_object_is_dynamic` reads the receiver's **own** class flags.
5. **`describeType` is insulated from the SEALED flag by `dt_desc_find`** for
   every class that has a `DtDescClass` row. `TextField` has none, so its
   instance-side `isDynamic` moves `true → false` — correct-ward, and unobserved
   by the corpus. If a future row needs it pinned, add a row rather than
   un-sealing.

---

## 7. New unclaimed leads

1. **`bd.rectangle` / `getColorBoundsRect` should answer `-1` when the
   `flash.geom` PATH is unresolvable**, not just when `Rectangle` is a
   non-function. Ruffle's `resolve_class` returns `None` for
   `flash.geom = 4` and the caller answers `-1`
   (`bitmap_data.rs:224` and `:732`, both via `instantiate_class_fast`'s
   `rect.unwrap_or_else(|| (-1).into())`). We fall back to the internal rect. Worth
   indices 31 and 35 of `bitmapdata_custom_rectangle` — **0 grading on its own**
   (both are inside Ruffle's diff set), so it only matters as part of a `pass`
   push. Cost: one branch in `constructGeomRectDynamic`, but it changes
   `bd.rectangle` for every SWF, so it needs the `BitmapData-v*` quartet as a
   canary.
2. **`avm1/bitmapdata_custom_rectangle` → `pass` is one mechanism away**:
   implement `BitmapData.generateFilterRect` (AVM1) to expand the source rect by
   the filter and return it through `constructGeomRectDynamic`. With lead 1, that
   is the entire residual — the row would go `ruffle_matched → pass`. Note the
   expected output wants `(x=0, y=0, w=3, h=3)` for a default `BevelFilter` on a
   3×3 bitmap, i.e. Flash does **not** expand for this filter/size; read
   `operations.rs` before assuming a blur expansion.
3. **The rest of the AVM1 corpus mints Rectangles internally too.** There are **10**
   other `createRectObj` call sites in `action.c` (`MovieClip.getBounds`,
   `getRect`, `Transform.pixelBounds`, `TextField.getCharBoundaries`,
   `scrollRect`, …). Ruffle routes several of them through
   `instantiate_class_fast` as well, so the same "replaced class" fixture shape
   would catch them. No corpus row currently grades it — this is a
   *fixture-first* lead (write a `regression/` test with a Ruffle-exporter
   oracle), not a diff-line lead.
4. **Other builtin classes we leave dynamic that playerglobal seals.** The seal
   audit is now two classes deep; `Sprite`, `Shape`, `Bitmap`, `Loader`,
   `StaticText`, `MorphShape` and most of `flash.display` are non-`dynamic` in
   playerglobal and unsealed for us. Each is a `#1069`/`#1056` correctness gap
   with the same shape and the same (small, argued) canary method. No corpus row
   grades them today — worth a single sweep agent that seals the lot and takes
   one CI run, rather than one class per session.
5. **`w1-avm2-smalls-report.md` rows 5-7 remain unclaimed**
   (`simplebutton_childevents_multichild`, `textline_atom_index_at_char_index`,
   `sound_load_multiple`). Row 5's instance-name counter now has a *cheaper*
   canary story than the sibling assumed: `simplebutton_symbolclass` and
   `simplebutton_childevents` are both in my worktree, already compiled, and both
   pass — a future agent can A/B the counter against them without a fresh build.
