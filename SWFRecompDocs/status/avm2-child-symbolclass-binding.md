# A loaded AS3 child's timeline-placed characters get their SymbolClass class

**Date:** 2026-09-11 · **Arc:** Multi-SWF (loaded children), the last open
member of the "MAIN-only symbol map" family
**Baseline:** `177508686` · **Brief:** `/home/robert/.cache/wsl-launch-claude/run.zgyNICoA/prompt.txt`
(kickoff committed in `177508686`) · **Diagnosis inherited from:**
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader-report.md` §5.1
**Corpus baselines (read fresh off `origin/ruffle-test-results`):** graphics
`ae28d1ae1`, no-graphics `c184410f4` — `avm2/loader_duplicate_class` is
`output_mismatch` **32/48** in both.

`avm2/loader_duplicate_class` now passes, 48/48, in both modes. A character a
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

CI_SECTION

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
