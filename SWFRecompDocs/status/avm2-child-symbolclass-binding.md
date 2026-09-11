# A loaded AS3 child's timeline-placed characters get their SymbolClass class

**Date:** 2026-09-11 · **Arc:** Multi-SWF (loaded children), the last open
member of the "MAIN-only symbol map" family
**Baseline:** `177508686` · **Brief:** `/home/robert/.cache/wsl-launch-claude/run.zgyNICoA/prompt.txt`
(kickoff committed in `177508686`) · **Diagnosis inherited from:**
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader-report.md` §5.1
**Corpus baselines (read fresh off `origin/ruffle-test-results`):** graphics
`ae28d1ae1`, no-graphics `c184410f4` — `avm2/loader_duplicate_class` is
`output_mismatch` **32/48** in both.

`avm2/loader_duplicate_class` now passes, 48/48, in both modes (CI `34614830360`
graphics, `34621152628` no-graphics). A character a
Loader-loaded child places now resolves its SymbolClass name in the
ApplicationDomain of the movie **instance** that placed it.

## 1. The brief's lead was already in the code; the missing piece was the DOMAIN

Session 18 proposed "have the per-character class lookup consult the placing
movie's `symbol_classes` table". **`class_for_char` already did.** Its
`g_child_movies` fall-through scans every loaded child's `symbol_classes`, and
because a child's ids carry its `char_id_base` (1000, 3000, 5000 here) the id
alone picks the right row: `1003 -> "DuplicateClass"`.

The actual defect was the next line. The fall-through resolved the row's NAME
with `class_for_dotted_name(ctx, …)`, i.e. in the **root** domain. The default
`LoaderContext` loads a child into a **fresh** child domain, and
`DuplicateClass` exists there and nowhere else. So the lookup returned NULL, the
loop moved on, and `class_for_char` fell through to the character-kind default:
a bare `MovieClip`. That is exactly the session-18 symptom (no `DuplicateClass`
ctor, then `#1034` assigning the bare clip to `MainTimeline`'s typed field).

The same test shows why the root scope *looked* half-right. The repeated load
(the last ten expected rows, from `Starting repeated child domain load`) passes at the baseline: by then `loader_same_domain` has been
loaded into `ApplicationDomain.currentDomain`, so the root scope holds *its*
`DuplicateClass`. Flash's parent-first lookup from the repeated load's fresh
domain finds that same class, so the wrong scope gave the right answer by
coincidence.

`nondisplay_class_for_char` (a timeline `Bitmap`'s `BitmapData` subclass) had
the identical root-scope resolve and gets the identical fix. No test grades it.

## 2. The key, and why

**Key: (character id, domain of the placing movie instance).** The id selects
the defining movie's row; the domain resolves the name.

Ruffle: `movie_clip.rs` `preload_symbol_class` resolves every SymbolClass row in
`library_for_movie(self.movie()).avm2_domain()` and stores the class on **that
movie library's character** (`mc.set_avm2_class`). Every `Loader.load` builds a
fresh `SwfMovie`, so two loads of one SWF have two libraries, two domains and
two class bindings for the same character id.

That rules out the two keys the brief warned about (§2), and both are
discriminated by the corpus test itself:

| key | what it does to `loader_duplicate_class` |
|---|---|
| class **name** in one global scope (the baseline) | loads 1 and 2 find nothing: exp 4, 5, 19 missing, `#1034` |
| the character's **tables** (one scope per `Avm2MovieTables`) | `loader_domain_child.swf` is loaded TWICE (loads 1 and 4) and shares one table set. Keyed on the tables, load 4's char 1003 would bind to load 1's `DuplicateClass` instead of `loader_same_domain`'s, so the repeated load's `loader_same_domain DuplicateClass: …` rows would print `this.childFromDomainChild = …` / `Child name: …` instead (reasoned from the lookup, not run) |
| **placing instance's domain** (this change) | 48/48 |

The tables cannot carry the domain: `avm2_abc_register_movie` already keys its
reuse table by (tables, scope) for exactly this test.

## 3. The mechanism

`Avm2DisplayObjectExt.movie_scope` (new, `avm2_globals.h`) is the domain of the
movie instance the object's character came from: Ruffle's
`DisplayObject::movie()` projected onto the one thing the class lookup needs.
NULL means the main movie, i.e. the root scope. Zero-initialised, so every
existing object and every single-movie build is unchanged.

| site | what it does |
|---|---|
| `loader_boot_child_swf` | stamps the loaded root with `lx->scope` **before** its frame-1 places run |
| `instantiate_child` | passes `pext->movie_scope` to `class_for_char` / `nondisplay_class_for_char`, and the child inherits it (Ruffle: a child is built from `library_for_movie(self.movie())`) |
| `button_create_state` | same inheritance for button state records (see §8: child buttons have no records today) |
| script-created allocator arm | a symbol instance made by `new Cls()` of a child-bound class takes the load scope of the ABC file that defines the class (`child_class_movie_scope`, the same class walk `avm2_display_child_char_for_class` takes). It is that movie's character (Ruffle `class_symbol` -> (movie, id)), so the children its timeline places resolve there |
| `class_for_char` / `nondisplay_class_for_char` | take a `movie_scope` argument. The main movie's rows still resolve in the root scope. Child rows resolve in `movie_scope`, or the root scope when it is NULL, which is the old behaviour exactly |

**Why a stamped field and not `movie_scope_of()`.** `avm2_display.c` already
has `movie_scope_of(ctx, dobj)`, which walks to the display root and reads its
LoaderInfo's scope (it serves `loader_deliver`'s choice of a Loader's parent
domain). It would answer correctly for the timeline arm, because the loaded root
carries `loader_info` before its frame-1 places run. It answers **wrong** for the
script arm: `new Outer()` is an orphan, so the walk ends at the orphan itself,
finds no LoaderInfo and returns the root scope. That is the fixture's `script:`
row. Ruffle keeps `movie` per display object for the same reason.

**§3 of the brief (the Shape gate).** The script-created arm's
`if (char_id != 0 && … shape_class …) char_id = 0;` is untouched and still sits
between the lookup and its use. The new scope stamp is inside the following
`if (char_id != 0)`, so a Shape-linked class still gets no character and no
scope.

## 4. Revert attribution

Byte-level, against `--save-actual` output (no-graphics).

**`avm2/loader_duplicate_class`** (corpus). Whole patch reverted: 32/48 with
exactly the baseline diff:

```
-this.childFromDomainChild = [object MovieClip]      exp 4
-Child name: [object MovieClip]                      exp 5
+TypeError: Error #1034: Type Coercion failed: cannot convert flash.display::MovieClip@00000000000 to DuplicateClass.
+	at flash.display::MovieClip()
+	at loader_domain_child_fla::MainTimeline()
-this.childFromOtherDomain = [object MovieClip]      exp 19
```

The positional grader counts 16 lines because the three-line `#1034` shifts
everything after it. Content-wise it is those three rows. The script-created arm
alone reverted: still 48/48, because none of this test's script-created
instances places a bound child.

**`regression/avm2_parent_child_symbolclass_domain`** (new, §5): `output_mismatch` pre-fix (only the two `parent:`/`load` lead rows match) -> pass.

| reverted | `timeline:` rows (Inner/Outer ctors above `Child ctor`, `timeline:Outer kid:Inner`) | `script:` rows (`Inner ctor` + `Outer ctor, kid=Inner` under `script: new Outer()`, `script:Outer kid:Inner`) |
|---|---|---|
| nothing | pass | pass |
| script-created arm only (`child_class_movie_scope` stamp) | pass | **fail**: `Outer ctor, kid=flash.display::MovieClip`, no `Inner ctor`, `script:Outer kid:flash.display::MovieClip` |
| whole patch | **fail**: no ctor lines, `timeline:flash.display::MovieClip kid:flash.display::MovieClip` | **fail**, as above |

So each arm owns its own rows, and the `script:` rows flip on that arm alone.
`loader_duplicate_class` stays 48/48 with the script arm reverted.

## 5. The regression fixture

`regression/avm2_parent_child_symbolclass_domain` exists because the corpus test
does not grade the script-created arm (its `new DuplicateClass()` instances place
only unbound children). It is an mxmlc child with `DefineSprite`/`SymbolClass`/
`PlaceObject2` tags injected by `create_test_swf.py`: char 2 (`Outer`) places
char 1 (`Inner`), the child root places char 2, and the parent loads it with the
default context (fresh domain). `output.txt` is the local Ruffle exporter's
trace, byte for byte. Two rows grade the timeline arm and the script arm
separately; see its README.

## 6. Canary (local, individual tests, `-P 5`, no-graphics)

Captured `--diff` output per test on the patched tree, then again with the
runtime patch reversed (`git apply -R`), and compared **byte for byte**.

| group | tests | result |
|---|---|---|
| `avm2/loader_*`, `avm2/loaderinfo_*`, `avm2/delayed_symbolclass`, `avm2/simplebutton_symbolclass` | 34 | 33 byte-identical; `loader_duplicate_class` **fail -> pass** |
| `mixed_avm/*` | 12 | byte-identical |
| `from_shumway/as3-loader/*` (incl. `bug1157243/empty`) | 10 | byte-identical |
| `import_assets` | 3 | byte-identical |
| `regression` (whole suite, incl. the three `avm2_parent_child_*`) | 89 | byte-identical |
| new `regression/avm2_parent_child_symbolclass_domain` | 1 | fail -> pass |

148 + 1 tests, 1 + 1 moved, 0 other output changes. Eight canary tests fail
identically in both legs, so they are baseline failures and not this change's:
`avm2/loader_load`, `avm2/loader_events_2`, `avm2/loader_applicationDomain`,
`mixed_avm/avm1_loads_avm2`, `mixed_avm/avm2_loads_avm1_events`,
`from_shumway/as3-loader/{LoaderTest,LoaderLoadBytesTest,events/loader-events}`.

`gcc -fsyntax-only -Wall -Werror=return-type` over `avm2_display.c` is clean.
No recompiler change, so no emitted-C sweep is needed.

Both target tests also pass locally in `--mode=graphics`.

## 7. CI

Serial, `categories=full`, `images=false`, code at `c4a952960` (plus the
docs-only `bf6626aa5` another session committed on top).

**Graphics: run `34614830360`, `completed success`, every job green including
`wasm-link-smoke`.** Results `c7d24d557`, merged in `13dfc5b48`.
`scripts/corpus_status_diff.py bf6626aa5 WORKTREE --per-suite` over the
4501-test intersection (baseline = `ae28d1ae1`'s numbers, read fresh):

| | before | after |
|---|---|---|
| pass | 4168 | 4168 |
| ruffle_matched | 239 | 238 |
| output_mismatch | 93 | 94 |
| runtime_error | 1 | 1 |
| **effective** | **4407** | **4406** |

- **Gain:** `avm2/loader_duplicate_class` output_mismatch 32/48 -> **pass 48/48**.
- New `regression/avm2_parent_child_symbolclass_domain`: **pass 12/12**
  (outside the intersection; `regression` 90/90).
- **Two "regressions", both UPSTREAM DRIFT**, both proven. CI re-downloads
  every test from `ruffle-rs/ruffle` master, and both tests changed there after
  the baseline run (2026-09-05):
  - `avm2/geom_transform` pass -> output_mismatch (71/74). Upstream
    `45be8d5365` (2026-09-09, "avm2: Implement DisplayObject z getter/setter")
    replaced `test.swf` and `output.txt`. The three failing rows are the new
    `z` translation in `matrix3D.rawData` (`…,6,7,8,1` expected, we print
    `…,6,7,0,1`): we have no `DisplayObject.z`. Reproduced locally on the
    synced tree; nothing in this change touches Matrix3D or `z`.
  - `from_avmplus/ecma3/JSON/adhoc` ruffle_matched -> output_mismatch, **33/40
    on both sides** (our output did not change). Upstream `af88e41a58`
    (2026-09-07, "avm2: Improve number parsing in JSON") rewrote
    `output.ruffle.txt` (+4/-4): Ruffle now passes `JSON.parse(-1.75e12)` and
    `JSON.parse(-1e+12)`, so our seven diffs are no longer a subset of Ruffle's
    five. Our two extra rows are a real int32 truncation
    (`JSON.parse(-1e+12)` gives `727379968`).

So the corpus effective count is -1 at the headline, but on the code it is +1:
the gain is this slice, and the -2 is the test mirror moving under both
baselines. Any later run will show the same two moves.

**No-graphics: run `34621152628`, `completed success`, every job green.**
Results `c1df12d64`, merged in `d1721c233`.
`corpus_status_diff.py 13dfc5b48 WORKTREE --per-suite --stem results` over the
4503-test intersection (baseline = the `c184410f4` weekly canary of
2026-09-06, read fresh):

| | before | after |
|---|---|---|
| pass | 4169 | 4169 |
| ruffle_matched | 240 | 238 |
| output_mismatch | 93 | 95 |
| runtime_error | 1 | 1 |
| **effective** | **4409** | **4407** |

- **Gain:** `avm2/loader_duplicate_class` 32/48 -> **pass 48/48**.
- `regression/avm2_parent_child_symbolclass_domain` **pass 12/12**
  (`regression` 90/90).
- **Three "regressions", all upstream drift:** the same two as graphics, plus
  `avm1/bitmapdata_custom_rectangle` ruffle_matched -> output_mismatch. This
  change is AVM2-only, and that test's **expected line count moved 34 -> 42**:
  upstream `352718de29` (2026-09-09, "avm1: In
  `BitmapData.getColorBoundsRect`, coerce arguments even if `this` is invalid")
  changed it after the 2026-09-06 baseline. Today's graphics run grades it
  identically (30/42). It did not show up in the graphics diff only because
  upstream added the test (`5e9953c40c`, 2026-09-05 10:57) after the graphics
  baseline ran (05:22), so it was outside that intersection.

**Net, both modes: +1 effective on the code (the slice's target), zero
regressions from this change, and -2 (graphics) / -3 (no-graphics) of
upstream test drift that any later run at any code will reproduce.** The
next slice should take `13dfc5b48` (graphics) and `d1721c233` (no-graphics) as
its baselines. Those already include the drift.

## 8. Leads left on the board

- **A loaded child's `SimpleButton` has no states.** `button_data_for_char`
  scans `avm2_generated_buttons` only, with no `g_child_movies` fall-through,
  although `Avm2MovieTables` carries `buttons`. So a child's `DefineButton2`
  instantiates as a `SimpleButton` whose `button_create_state` returns NULL for
  every state. Found by code reading while threading `movie_scope` through
  `button_create_state`. No corpus test is known to grade it. Same family as
  every closed fall-through in BACKLOG §Multi-SWF.
- `nondisplay_class_for_char`'s scope fix (§1) is ungraded. A child whose
  timeline places a bitmap bound to a `BitmapData` subclass, loaded into a
  fresh domain, would grade it.
- **Three new targets the drift created** (§7): `DisplayObject.z` for
  `avm2/geom_transform`; JSON number parsing/stringify of values past int32
  for `ecma3/JSON/adhoc` (Ruffle fixed its own in `af88e41a58`); and the new
  `BitmapData.getColorBoundsRect` argument-coercion rows in
  `avm1/bitmapdata_custom_rectangle`.
