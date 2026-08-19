# w2-trace-smalls — session 17 wave-2 — lead T6 "AVM2/loader near-pass smalls #3"

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a9e59760edff28726`
Baseline: HEAD `88ebde665`, graded run `31877239992` (graphics / categories=full).
All grading below is `--mode=graphics`, `SWFRECOMP_COMPILE_TIMEOUT=2400`.

## NEW FILES

**None.** Every edit is to an existing tracked file. `git apply --stat` on the
combined patch lists exactly eight paths, all pre-existing:

```
 SWFModernRuntime/include/avm2/avm2_globals.h |   4 +
 SWFModernRuntime/src/avm2/avm2_bitmap.c      |  15 +
 SWFModernRuntime/src/avm2/avm2_display.c     | 156 +++++++++++---
 SWFModernRuntime/src/avm2/avm2_events.c      |  18 +
 SWFModernRuntime/src/avm2/avm2_globals.c     | 172 ++++++++++++----
 SWFModernRuntime/src/avm2/avm2_json.c        |   5 +-
 SWFModernRuntime/src/avm2/avm2_text.c        |  13 +
 ruffle-tests/verify_output.py                |  27 ++-
```

(The copied test directories under `ruffle-tests/tests/swfs/` are gitignored and
do not appear in the diff.)

## Verdicts — headline

| row | board price | verdict | before → after |
|---|---|---|---|
| `avm2/displayobject_early_init` | 53 → "really 3" | **GO** | `output_mismatch` (53) → **PASS** |
| `avm2/textfield_input_events` | 16 | **GO** (mechanism REFUTED) | `output_mismatch` (16) → **PASS** |
| `avm2/large_preload_image_from_bytes` | 6 | **GO** | `output_mismatch` (6) → **PASS** |
| `from_shumway/as3-loader/loaderinfo/loaded-content-properties` | 12 | **GO** (13, not 12) | `output_mismatch` → **PASS** |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | 3 | **NO-GO** (premise REFUTED) | `output_mismatch` (3) → unchanged |
| `avm2/appdomain_lookup_edge_cases` | 25, MED | **GO** | `output_mismatch` (25) → **PASS** |
| rider `avm2/large_preload_from_url` | 11 | **GO** (classification REFUTED) | `output_mismatch` (11) → **PASS** |
| rider `avm2/large_preload_from_bytes` | 33 | **NO-GO** | `output_mismatch` (33) → `output_mismatch` (~16) |
| rider `from_shumway/as3-loader/events/loader-events` | 27 | **NOT TAKEN** | unchanged |

**Net: +6 flips** against a board floor of +3 / real +4 / ceiling +9.
No row needs `categories=full` to grade: five are in `avm2`, two in
`from_shumway`, both in the classic-five `all` set.

---

## Row 1 — `avm2/displayobject_early_init` → PASS

The board priced "the real defect is 3" (three missing
`Caught error: ArgumentError: Error #2015: Invalid BitmapData.` lines). That was
correct but **incomplete**: fixing it exposed a second, 2-line ordering defect
that the 1-line-offset cascade had been hiding. Both are fixed.

**(a) BitmapData is born disposed.** Ruffle's `bitmap_data_allocator`
(`avm2/object/bitmapdata_object.rs:15-31`) seeds every fresh BitmapData with
`BitmapData::dummy()`, whose `disposed` flag is `true`
(`bitmap/bitmap_data.rs:474-492`); the real buffer is only installed by
`BitmapData.init`. So a subclass constructor that touches `this.width` **before**
`super()` sees an invalid BitmapData and `check_valid` raises #2015. We
zero-initialise the ext, so `disposed` was 0 and the getter answered `0`.
Fix: a `native_init` hook on the BitmapData class that sets `disposed = 1`;
`bd_alloc` / `bd_seed_embedded` already clear it. `native_init` is inherited by
subclasses (`avm2_class.c:1405`), which is what makes `MyImage`,
`UnlinkedBitmapData` and the timeline-placed instance all throw.
File: `SWFModernRuntime/src/avm2/avm2_bitmap.c`.

**(b) SimpleButton states are created at ALLOCATION, not in `super()`.** With (a)
in, the only remaining diff was `Constructed OverButtonState ×2` landing between
`MyButton before super()` and `MyButton after super()` instead of ahead of the
ctor. Ruffle's `Avm2Button::construct_frame`
(`display_object/avm2_button.rs:446-540`) creates the four states whenever
`needs_frame_construction` is set — including the `construct_frame` that
`initialize_for_allocator` runs (`globals/flash/display/display_object.rs:45`),
i.e. before the script `new MyButton()` constructor body; only the AS3 ctor call
is skipped there (`needs_avm2_construction` is false once the allocator installed
the object). Our `display_native_init` already sets `ext->constructed = 1` before
calling `construct_frame_obj`, so `construct_frame_obj`'s own button arm was a
no-op and the states were created later, from `simplebutton_init` (the ctor).
Fix: call `button_construct_states` from the script-created arm of
`display_native_init`, immediately before `construct_frame_obj`.
`button_construct_states` is guarded by `btn_states_created`, so the later ctor
call is idempotent. File: `SWFModernRuntime/src/avm2/avm2_display.c`
(`display_native_init`, ~:11876 — a region **no sibling owns**).

Canaries (all PASS): `bitmapdata_clone`, `bitmapdata_dispose`,
`bitmapdata_constructor_from_timeline`, `simplebutton_constr`,
`simplebutton_symbolclass`, `simplebutton_constr_childevents`.

---

## Row 2 — `avm2/textfield_input_events` → PASS (board mechanism REFUTED)

**The board's mechanism is wrong.** It read the diff as "the `textInput` handler
must observe the OLD text — dispatch `textInput` before mutating the field,
`change` after". Our event order was already correct. The actual diff is a
**newline on the wrong side**:

```
expected  New text: \nR      (text == "\nR")
actual    New text: R\n      (text == "R\n")
```

The field's tag text is the HTML `<p align="left"></p>`, which lowers to a single
`"\n"`. Flash inserts the typed character **after** it; we inserted **before** it.
Root cause: Ruffle `display_object/edit_text.rs:308-312` —

```rust
// Selections are mandatory in AS3.
let selection = if swf_movie.is_action_script_3() {
    Some(TextSelection::for_position(text_spans.text().len()))
} else { None };
```

An AS3 EditText is born with the caret **at the end of its initial text**; ours
was born at index 0. Fix: set `sel_begin/sel_end/sel_from/sel_to =
u16_length(et->text)` at the end of `edittext_init_common`.

Deliberately conservative: `sel_active` is left cleared. In our runtime that flag
is the *render* gate for a visible caret (`et_visible_selection`), and setting it
would start painting a caret in every focused editable field from birth — a
pixel-axis change, not a trace one. Every trace consumer (`selectionBeginIndex`,
`caretIndex`, insert, backspace) reads the indices directly and is unaffected by
the flag.

File: `SWFModernRuntime/src/avm2/avm2_text.c`.
Canaries (all PASS): `edittext_focus_selection`, `edittext_input_control`,
`edittext_restrict_events`, `edittext_selected_text`,
`textfield_input_dead_keys_windows`.

---

## Row 3 — `avm2/large_preload_image_from_bytes` → PASS

Board mechanism confirmed and made exact. Two rules, both quoted from Ruffle:

**(a) The decoded Bitmap is not the Loader's child until `complete`.** Ruffle
builds it in `movie_loader_data` but only calls
`loader.insert_at_index(uc, dobj, 0)` from `movie_loader_complete`
(`loader.rs:2119`), so the second `progress` event still reads
`loader.numChildren = 0`. We inserted it at decode time (line 8 of the fixture).
Fix: park it in a new `Avm2LoaderInfoExt::pending_child` and attach it at the top
of `loaderinfo_fire_init_and_complete`.

**(b) A `from_bytes` image waits TWO frame boundaries.** `loader.rs:1883-1902`
nests two `PostFrameCallback`s with the comment *"Note - flash player seems to
delay this for \*two\* frames for some reason"*. Our active list already spends
one flush, so a new `defer_flushes` counter (set to 1 for `is_image &&
from_bytes`) makes `avm2_loader_run_exit_frame` re-track the entry once. That
moves `init`/`complete` from after the first `exitFrame in Test` to after the
second, which is the fixture's expected order.

File: `SWFModernRuntime/src/avm2/avm2_display.c` (LoaderInfo/loader region — no
sibling owns it; `w2-crossvm-legE` and the gfx agents are in the mouse-pick,
`compose_children`, `gfx_draw_graphics_data` and filters regions).
Canaries (all PASS): `loader_image`, `loader_loadbytes_events`,
`loader_bitmap_transparency`, `jpeg_loader_context`, `loader_events`,
`loader_loadbytes_invalid_png`.

---

## Row 4 — `from_shumway/.../loaderinfo/loaded-content-properties` → PASS

The board listed 4 rules over 12 lines. Re-graded at HEAD the row is **13 lines
and 5 rules** — it also names three SWF-only getters and the content size, which
the board's summary omitted. `test.toml` carries `known_failure = true`, so
Ruffle is **not** the oracle here (`output.ruffle.txt` differs from `output.txt`
on 6 lines); the fix targets `output.txt` (Flash) and lands a `pass`, not a
`ruffle_matched`.

1. `childSandboxBridge` / `parentSandboxBridge` → `null` with a no-op setter
   (Ruffle `globals/flash/display/LoaderInfo.as:55-69`). 4 lines.
2. `uncaughtErrorEvents` → an `[object UncaughtErrorEvents]`, minted once per
   LoaderInfo and cached (Ruffle `loader_info.rs:563-575`). 2 lines. **This
   required registering `flash.events.UncaughtErrorEvents`** — an empty
   `EventDispatcher` subclass, `[API("667")]` → SWF 10+ — which did not exist in
   our runtime at all.
3. `isURLInaccessible` → `true` while a **Loader's** stream is `NotYetLoaded`,
   `false` afterwards. 1 line. Ruffle stubs it to a flat `false`
   (`loader_info.rs:221`) and its own expectation file records that;
   `output.txt` (Flash) wants `true`/`false`.
   **A canary caught a regression here.** The first version keyed only on
   `!ext->loaded`, which flipped `avm2/stage_loaderinfo_properties` (a baseline
   `pass`) to `output_mismatch`: our ROOT and STAGE LoaderInfo flavours are
   permanently `NotYetLoaded` by construction, but Flash reports `false` for
   them. The rule is now `kind == LI_KIND_LOADER && !loaded`, and
   `stage_loaderinfo_properties`, `loaderinfo_root` and
   `loaderinfo_properties_not_loaded` were all re-graded PASS afterwards.
4. `actionScriptVersion` / `frameRate` / `swfVersion` raise **#2098** ("The
   loading object is not a .swf file…") once a NON-swf stream has loaded. 3
   lines. We answered with the ROOT movie's numbers (3 / 24 / 25).
5. `width` / `height` report the decoded bitmap's size (alf.jpg is 140×140), not
   the stage rect (550×400). 2 lines. They do **not** throw #2098.

Files: `SWFModernRuntime/src/avm2/avm2_display.c` (LoaderInfo getters + class
registration), `SWFModernRuntime/src/avm2/avm2_events.c` (the new class, at the
end of the events registration), `SWFModernRuntime/include/avm2/avm2_globals.h`
(one accessor declaration).

**Sibling note.** `w2-all-classes-events` (T4, pending) owns the `flash.events`
generated block in `avm2_globals.c` and the descriptor generator. My
`UncaughtErrorEvents` registration lives in `avm2_events.c`, not in their block,
but **if they also register that class the two will collide** —
`builtin_class_impl` is not idempotent and would build two classes of the same
name. If both patches land, keep one registration. It is api-gated at SWF 10,
which is what `all_classes/events/swf9`'s `UncaughtErrorEvents not accessible`
line requires; `all_classes/events/*` are all `output_mismatch` at baseline, so
there is no regression risk either way.

Canaries (all PASS): `loaderinfo_properties`, `loaderinfo_properties_not_loaded`,
`loaderinfo_more`, `loaderinfo_events`, `loaderinfo_quine`,
`from_shumway as3-loader/LoaderTest2`, `as3-loader/LoaderLoadBytesTest2`.

---

## Row 5 — `from_shumway/as3-loader/LoaderLoadBytesTest` → **NO-GO** (premise refuted)

Board: *"`Loader.loadBytes` does not run the loadee's frame-1 script before
dispatching `init`. Sibling of the `LoaderTest2` fix s16 landed."* **Refuted.**

We never compile the loadee's ActionScript at all. `Loadee.swf` is not a sibling
file — it is embedded inside the parent SWF as a `DefineBinaryData` tag:

```as3
[Embed(source='Loadee.swf', mimeType='application/octet-stream')]
private static const BYTES:Class;
```

`RecompiledABC/avm2_movie_tables.c` for this test shows
`avm2_generated_binaries, 1` and no ABC carrying the string `from loadee`, and
`loader_loadbytes` matches a payload to a recompiled movie by **file size against
the sibling-SWF registry** (`avm2_display.c`, `getMovieEntryAt` loop) — an
embedded payload is in no registry, so it stays content-less by construction.
There is no event-ordering component: the other two lines of the 3-line diff are
a pure shift caused by the missing trace.

**Completion mechanism (what flips it to GO):** the recompiler/harness must treat
a SWF-shaped `DefineBinaryData` payload as a child movie — extract it at
recompile time, run `recompile_child_swf` on the extracted bytes, and register
the resulting tables in the movie registry keyed by payload size so
`loader_loadbytes`'s existing size match finds it. That is the same machinery
`HAS_CHILD_MOVIES` already has, sourced from embedded bytes instead of a file.
It is recompiler + harness work, not an S-sized runtime change.

---

## Row 6 — `avm2/appdomain_lookup_edge_cases` → PASS

The board's MED "cascade" pricing was right about the shape and right about the
size — the row needed **three** fixes, in cascade order, and all 25 lines landed.

**(a) `Vector.<X>` definition names are resolved recursively.** Ruffle
`domain.rs:285-320` + `vector_parameter_from_name` (`domain.rs:439-453`): a name
starting `Vector.<` (or `__AS3__.vec::Vector.<`) and ending `>` is split into the
generic Vector plus the INNER name, and the inner name is resolved as a
definition **in its own right**. `hasDefinition` only checks that the parameter
*exists* (so `Vector.<integerValue>` is `true` — `integerValue` is a
package-level `var`), while `getDefinition` resolves it and then calls
`ClassObject::apply`, which rejects a non-class parameter with
`make_error_1107` → **VerifyError #1107**, which the fixture's
`catch (e:VerifyError)` handles. Our `avm2_vector_class_by_name` resolves the
same shape but answers NULL for a non-class inner name, collapsing both cases
into "not defined" — so we answered `false` and then threw an **uncaught** #1065
that killed the test at expected line 9.
Fix: `definition_has_in` / `definition_get_in` in `avm2_globals.c`, used by
`getDefinitionByName`, `ApplicationDomain.getDefinition` and `.hasDefinition`.
`Vector.<*>` keeps its special case (`*` is not a definition).

**(b) An UNQUALIFIED runtime name is looked up at `ApiVersion::VM_INTERNAL`.**
With (a) in, the test died at line 11 instead: `getDefinitionByName("JSON")` in a
**SWF 9** movie must answer `[class JSON]`. Ruffle
`QName::from_qualified_name` (`qname.rs:90-109`) uses
`public_for(ApiVersion::VM_INTERNAL)` — the version that sees everything — for a
name with no `::` and no `.`, and `root_api_version` for a package-qualified one.
That single rule explains eight further expected lines: `"JSON"` resolves,
`"::JSON"` and `".JSON"` are #1065 (package `""` at the root api version), and
`".Math"` / `"::Math"` resolve because Math is api-9.
We have no per-namespace api versions — `builtin_class_impl` simply declines to
expose an api-gated class. Fix: record such a class in a small side table when
its namespace is the default package (`ns_len == 0`), and let ONLY the
unqualified runtime-lookup path consult it. `avm2_register_json` now always runs,
with the class built through `avm2_builtin_class_api(..., 13)` so the global and
domain binding are still withheld below SWF 13 — `json_version_gated` (SWF 12,
`FindPropStrict`/`GetProperty`, i.e. the compiled multiname path) still gets
#1065 and still passes. Today JSON is the only default-package api-gated builtin,
so the table holds exactly one entry.

**(c) `flash.crypto` is `[API("674")]` too.** Same FP11/SWF13 threshold as JSON
(`globals/flash/crypto.as:4`). We registered `generateRandomBytes`
unconditionally, so the SWF 9 fixture found it where Flash reports #1065 (6
lines). Fix: gate `builtin_add_global_fn_ns("flash.crypto", …)` at
`swf_version >= 13`. `avm2/generate_random_bytes` is SWF 16 and still passes.

Files: `SWFModernRuntime/src/avm2/avm2_globals.c`,
`SWFModernRuntime/src/avm2/avm2_json.c`.
Canaries (all PASS): `json_version_gated`, `generate_random_bytes`,
`vector_class`, `loader_child_getdefinition`,
`applicationdomain_getqualifieddefinitionnames`, `get_qualified_class_name`.

---

## Riders

### `avm2/large_preload_from_url` (11) → **PASS**. Board classification REFUTED.

The board filed this as "the same loader event-ordering axis" as row 3. It is
not: at HEAD the test produces **nothing at all** after line 17 — no `open`, no
`progress`, no `init`, no `complete`. The child SWF simply never loads, and the
one non-truncation line (`bytes?.length = null` vs `0`) is the same root cause
(the load never starts, so the three-state `bytes` getter stays in state 1).

The blocker is in the **harness**, and it is documented in the harness's own
docstring: `find_child_swfs` (`ruffle-tests/verify_output.py:1065`) prunes any
subdirectory that holds a `test.swf`, on the theory that it is a separate test —
naming `avm2/large_preload_from_url/large_bytearray` explicitly. But
`discover_tests` needs `test.swf` **and** a resolvable expected-output file, and
those directories have no expected output, so they are not tests: they are the
very SWFs their parent loads by relative path
(`loader.load(new URLRequest("./large_bytearray/test.swf"))`). A second filter,
`f.name != "test.swf"`, then dropped the file even if the directory had been
walked.

Fix (2 edits, `ruffle-tests/verify_output.py`): prune a subdirectory only when it
is a *discoverable* test (new `_dir_is_own_test` helper — `test.swf` **and** an
existing expected-output file), and exclude only the test's **own** top-level
`test.swf` rather than every file of that name. A corpus scan finds exactly three
directories affected — `large_preload_from_url/large_bytearray`,
`large_preload_from_bytes/large_bytearray`, `large_preload_from_bytes/nested_load`
— so only the two `large_preload_from_*` tests change; every other test's child
list, and therefore every `movie_id` / `char_id_base` / symbol prefix, is
byte-identical (verified by re-running `find_child_swfs` over neighbours).

With that plus row 3's loader patch, `large_preload_from_url` **passes**.

**Delivered as its own patch** (`w2-smalls-large_preload_from_url.patch`) because
it is the only change outside the runtime. `w2-tooling-hygiene` also works in
`ruffle-tests/`, but on `ignored_tests.txt`, disposition docs and a new sweep
script — not on `verify_output.py` — so no textual overlap is expected.
**CI cost note:** this makes CI recompile a 500 KB child SWF for
`large_preload_from_url` and two children for `large_preload_from_bytes`; those
two tests get slower (locally ~55 s and ~5 min including the child recompile).

### `avm2/large_preload_from_bytes` (33) → **NO-GO**, improved but not flipped

With the harness fix + row 3, it goes from 33 diff lines to ~16 and stays
`output_mismatch`. Two independent blockers remain:

1. **The nested load's payload is empty.** The child (`LargeSWF`) itself
   `loadBytes`es an `[Embed]`ed `nested_load/test.swf` (424 bytes); we report
   `bytesTotal = 0` / `bytes.length = 0` for it. This is the *same* defect as
   row 5: a `DefineBinaryData` SWF payload inside a movie is never compiled —
   here inside a CHILD movie, so the child recompile would need to emit its
   binaries too.
2. **`exitFrame` vs `init`/`complete` interleave for a nested load** — expected
   puts one `exitFrame in Test` before the outer `init`, we put both after.

**Completion mechanism:** row 5's embedded-`DefineBinaryData`-as-child-movie work
(applied to child movies as well), then re-grade; the residual ordering is a
one-boundary shift of the same `defer_flushes` kind row 3 introduced, but it must
not be guessed at before (1) lands, because the payload's absence changes which
tick the outer load resolves on.

### `from_shumway/as3-loader/events/loader-events` (27) → **NOT TAKEN**

Confirmed still `output_mismatch` after the full patch (no regression; the diff
shape is the board's — a permutation of loader events against
enterFrame/exitFrame/run-frame, plus `null` where Flash has `instanceN`).

Two reasons for not taking it:

* `test.toml` has `known_failure = true` and `output.ruffle.txt` is a **third**
  ordering, different from both ours and Flash's, over 22 of 36 lines. So neither
  `pass` nor `ruffle_matched` is reachable by a partial fix — this row cannot
  flip on the naming half alone. The board itself priced the naming half at
  "6 of the 27 lines", i.e. **a diff-line lead, not a flip lead** (s16 lesson).
* The naming half changes the *shared global instance counter*, which every
  `instanceN` assertion in the corpus reads. That is a broad-blast-radius change
  whose only priced payoff is 6 lines on a row that still fails.

**Completion mechanism:** take it together with the loader event-ordering rework
(the T6 ordering axis), grading against `output.txt`, and canary the whole
`instanceN` family (`avm2/instance_names*`, `simplebutton_symbolclass`,
`avm2/displayobject_name*`) for counter drift.

---

## Refutations (yield, independent of the flips)

1. **`textfield_input_events` is not an event-ordering row.** It is the AS3
   initial caret position (`TextSelection::for_position(text.len())`). Anyone
   re-reading that diff as "`textInput` before `change`" will fix nothing.
2. **`LoaderLoadBytesTest` is not a `LoaderTest2` sibling.** It is blocked on
   embedded-`DefineBinaryData`-as-a-movie, one layer below the event model.
3. **`large_preload_from_url` is not on the loader-ordering axis.** It is a
   harness child-discovery prune, and it was a one-function fix worth a full flip
   — the cheapest +1 in the whole lead.
4. **`loaded-content-properties` is 13 lines and 5 rules, not 12 and 4.** The
   board's summary omits the #2098 SWF-property rule and the content-size rule,
   which are 5 of the 13 lines.
5. **`displayobject_early_init`'s "real defect is 3" is 3 + 2.** The 1-line-offset
   cascade hid a SimpleButton state-construction ordering defect that only
   becomes visible once the #2015 lines exist.

---

## Canaries — full ledger (all `--mode=graphics`, `--recompile` on first use)

Batch 1 (22/22 PASS):
`bitmapdata_clone`, `bitmapdata_dispose`, `bitmapdata_constructor_from_timeline`,
`simplebutton_constr`, `simplebutton_symbolclass`, `simplebutton_constr_childevents`,
`edittext_focus_selection`, `edittext_input_control`, `edittext_restrict_events`,
`edittext_selected_text`, `textfield_input_dead_keys_windows`,
`loaderinfo_properties`, `loaderinfo_properties_not_loaded`, `loaderinfo_more`,
`loaderinfo_events`, `loaderinfo_quine`, `json_version_gated`,
`generate_random_bytes`, `vector_class`, `loader_child_getdefinition`,
`applicationdomain_getqualifieddefinitionnames`, `get_qualified_class_name`.

Batch 2 (11/11 PASS — includes a re-confirmation of five headline rows against
the FINAL full patch): `loader_image`, `loader_loadbytes_events`,
`loader_bitmap_transparency`, `jpeg_loader_context`, `loader_events`,
`loader_loadbytes_invalid_png`, `displayobject_early_init`,
`textfield_input_events`, `appdomain_lookup_edge_cases`,
`large_preload_image_from_bytes`, `large_preload_from_url`.

Shumway batch (3 PASS / 1 expected-fail): `as3-loader/LoaderLoadBytesTest2` PASS,
`as3-loader/LoaderTest2` PASS, `as3-loader/loaderinfo/loaded-content-properties`
PASS (headline), `as3-loader/events/loader-events` MISMATCH (unchanged, see
riders).

Batch 3 (LoaderInfo / describeType blast radius) — this batch found the one
regression of the session and then confirmed its fix:

| test | first run | after the `LI_KIND_LOADER` fix |
|---|---|---|
| `stage_loaderinfo_properties` | **MISMATCH** (regression) | **PASS** |
| `loaderinfo_root` | PASS | PASS |
| `loaderinfo_properties_not_loaded` | PASS | PASS |
| `from_shumway as3-loader/loaderinfo/loaded-content-properties` | PASS | PASS (re-confirmed) |
| `all_classes/display/swf9` | — | **PASS** |
| `all_classes/display/swf30` | — | **PASS** |

(`all_classes/display/*` is the closest neighbour to both the new LoaderInfo
accessors and the new `flash.events.UncaughtErrorEvents` class: it `describeType`s
the whole `flash.display` surface, `LoaderInfo` included, at six SWF versions.
`all_classes/events/*` are all `output_mismatch` at baseline — T4's rows — so the
class addition cannot regress them.)

**Canary blind spot.** None of these are image-comparison tests, and the standing
`render_canary_tests.txt` set does not cover them. The one change with any
pixel-axis exposure is row 2's caret initialisation, and it was written
specifically to have none (`sel_active` untouched — see Row 2). Row 3 changes
*when* a loaded Bitmap becomes a Loader child, which could in principle move a
frame's rendering by one tick for a `loadBytes` image; `loader_image`,
`loader_bitmap_transparency` and `jpeg_loader_context` are the trace covers for
that path and all pass.

---

## Patches

All under `SWFRecompDocs/plans/session17-fanout-reports/` (worktree copy and, if
the guard allows, the main tree). Each per-row patch was verified to apply
cleanly to pristine `HEAD` **in isolation**, and applying all six together
reproduces the worktree byte-for-byte.

| patch | files | rows |
|---|---|---|
| `w2-smalls-displayobject_early_init.patch` | `avm2_bitmap.c`, `avm2_display.c` | row 1 |
| `w2-smalls-textfield_input_events.patch` | `avm2_text.c` | row 2 |
| `w2-smalls-large_preload_image_from_bytes.patch` | `avm2_display.c` | row 3 |
| `w2-smalls-loaded-content-properties.patch` | `avm2_display.c`, `avm2_events.c`, `avm2_globals.h` | row 4 |
| `w2-smalls-appdomain_lookup_edge_cases.patch` | `avm2_globals.c`, `avm2_json.c` | row 6 |
| `w2-smalls-large_preload_from_url.patch` | `ruffle-tests/verify_output.py` | rider |
| `w2-trace-smalls.patch` | all eight | everything |

**No two patches conflict.** Rows 1, 3 and 4 all touch `avm2_display.c` but in
disjoint regions (`display_native_init` ~:11876; the loader/LoaderInfo block
~:4460-6000; the LoaderInfo class registration ~:14377), and the
`Avm2LoaderInfoExt` struct additions were deliberately separated so rows 3 and 4
produce independent hunks.

## Files touched (for the sibling map)

- `SWFModernRuntime/src/avm2/avm2_bitmap.c` — new `bitmapdata_native_init` + one
  registration line. No sibling listed on this file.
- `SWFModernRuntime/src/avm2/avm2_display.c` — **LoaderInfo/loader region**
  (~:4460-6010), `display_native_init` (~:11876), LoaderInfo class registration
  (~:14377). Other owners this session are elsewhere in the file: transform/bounds
  = `w2-avm2-display`; `gfx_draw_graphics_data` = `w2-gfx-drawgraphicsdata`;
  filters = `w2-gfx-filters-cut2`; `compose_children` = `w2-gfx-cab-pixelsnap`;
  hit-test = `w2-avm2-smalls` / `w2-crossvm-legE`; `display_world_matrix`/scrollRect
  = `w2-scrollrect`. **No overlap with any of them.**
- `SWFModernRuntime/src/avm2/avm2_events.c` — appended to the end of the events
  registration + one accessor. **See the `UncaughtErrorEvents` collision note for
  `w2-all-classes-events` (T4) under Row 4.**
- `SWFModernRuntime/src/avm2/avm2_globals.c` — `builtin_class_impl` (2 lines + a
  32-entry static table), the definition-lookup helpers next to
  `global_get_definition_by_name`, `appdomain_has_definition` /
  `appdomain_get_definition`, the JSON and flash.crypto registration gates.
  `w2-all-classes-events` owns the *generated flash.events descriptor block* in
  this file — a different region.
- `SWFModernRuntime/src/avm2/avm2_json.c` — one call swapped for its api-gated form.
- `SWFModernRuntime/src/avm2/avm2_text.c` — 3 lines at the end of
  `edittext_init_common`. No sibling listed on this file.
- `SWFModernRuntime/include/avm2/avm2_globals.h` — one function declaration.
- `ruffle-tests/verify_output.py` — `find_child_swfs` + a new `_dir_is_own_test`
  helper. Delivered separately.
