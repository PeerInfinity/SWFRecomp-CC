# impl-fonts — child-movie font tables (TASK A steps 1 + 2)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af39d603f5f670ff2`
Patch: `../patches/fonts.patch` (runtime-only, 3 files, +117/−6)
Base: `master` @ `46dcf3a06`. Nothing committed, nothing pushed.

## Result

| test | baseline (results_graphics.json) | after |
|---|---|---|
| `avm2/font_enumeratefonts_order` | output_mismatch, 0/9, `ArgumentError #1508` | **PASS** (9/9) |
| `avm2/font_registerfont` | output_mismatch, 8/129 | **PASS** (129/129) |

Both targets converged. Step 2 (caller-scoped enumeration) did converge, so
it is shipped alongside step 1. DefineFont4 parsing was NOT implemented, per
the brief.

## What changed

Three files, all runtime.

### 1. `SWFModernRuntime/src/avm2/avm2_display.c` (+~58)

Three new exported helpers next to the existing `g_child_movies[]` table:

* `avm2_display_child_movie_count()` / `avm2_display_child_movie(i)` — expose
  the Loader-loaded child list so `avm2_text.c` can walk it.
* `avm2_display_movie_for_abc(const Avm2AbcFileData*)` — scans each child's
  `tables->abc_files[]` for a pointer match. `NULL` = the MAIN movie. This is
  Ruffle's `caller_movie_or_root()` `or_root` arm.
* `avm2_display_child_char_for_class(ctx, cls)` — `char_for_class()` first,
  then a child-movie arm.

### 2. `SWFModernRuntime/src/avm2/avm2_text.c` (+~46/−6)

* `font_by_id()` walks every child movie's `fonts[]` after the main table
  (step 1 as designed). Child font ids are already `char_id_base`-shifted at
  emission, so a bare id stays a unique key.
* `font_caller_movie(act)` — new static; `font_enumerate_fonts()` now
  enumerates `g_registered_fonts` + the **caller movie's** embedded fonts
  (`has_layout` filter unchanged) instead of always the main movie's.
* `font_register_font()` and `font_native_init()` use
  `avm2_display_child_char_for_class`.
* `font_register_font()` de-duplicates `g_registered_fonts` by
  `Avm2FontData*`.

### 3. `SWFModernRuntime/include/avm2/avm2_globals.h` (+10)

Declarations for the four new entry points.

## Two things the plan did not predict (and how they were resolved)

Both were found by running, not by reading; each cost one build cycle.

### (a) `act->file` is NULL inside a native — the caller must come off the callstack

The plan said "`font_enumerate_fonts()` takes `act->file` (already threaded)".
It is not: `Avm2Activation.file` is documented "NULL for pure natives"
(`avm2_abc.h:628`) and `avm2_globals.c:391` sets `e.method.file = NULL` for
every registered builtin. `Font.enumerateFonts` is a builtin, so `act->file`
is always NULL there.

The caller is instead the nearest **debug-callstack** frame with an ABC file.
`avm2_callstack_push(ctx, m, bound_class)` runs immediately before
`m->fn(&act)` in `avm2_class.c:1057` (and `:1116` for function objects), and
those are the only two invoke sites, so `ctx->call_frames[depth-1]` is the
native itself and the first non-NULL `.file` below it is the calling script:

```c
static const Avm2MovieTables* font_caller_movie(Avm2Activation* act)
{
	if (act->file != NULL) return avm2_display_movie_for_abc(act->file->data);
	Avm2Context* ctx = act->ctx;
	for (uint32_t i = ctx->call_depth; i > 0; i--)
	{
		Avm2AbcFileRt* f = ctx->call_frames[i - 1].method.file;
		if (f != NULL) return avm2_display_movie_for_abc(f->data);
	}
	return NULL;
}
```

The `act->file != NULL` arm is kept so the helper stays correct if the method
is ever re-homed onto an emitted body.

### (b) `font_by_id` was not the blocker for `font_enumeratefonts_order` — `char_for_class` was

Step 1 as specified (font_by_id over children) still threw `#1508`. The miss
is one level earlier: `g_symbol_map` (class → char) is built **once**, in
`avm2_display_build_stage()`, from `avm2_generated_symbol_classes` only — the
MAIN movie. A child's `SymbolClass` rows never enter it. `class_for_char`
(char → class) already had a child arm; the reverse direction did not.

The obvious repair — resolve each child row's `class_name` through
`class_for_dotted_name` and compare pointers, the way `class_for_char` does —
also fails here, because `class_for_dotted_name` searches the **root** scope
and `font_enumeratefonts_order` loads its child with a `LoaderContext` into a
fresh ApplicationDomain. The class reached by
`event.target.applicationDomain.getDefinition("FontSwf_TestFont4")` is simply
not visible from the root scope.

So the match runs the other way: start from the class, find the movie that
**defines** it via `instance_init.file`, and look that movie's own table up by
qualified name.

```c
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c->instance_init.file == NULL) continue;  // builtin
		const Avm2MovieTables* t =
			avm2_display_movie_for_abc(c->instance_init.file->data);
		if (t == NULL) continue;                      // the MAIN movie: done above
		char qn[256];
		avm2_class_qname_buf(c, qn, sizeof(qn));
		for (uint32_t i = 0; i < t->symbol_class_count; i++) { ... strcmp ... }
	}
```

Requiring `movie_for_abc(defining file) != NULL` is what makes the name
compare safe: it can only ever match inside the one child that defines the
class, so a same-named class in another movie cannot be hit. Emission
confirms the two sides agree — `font_abc_registry.c` writes
`{ 10001, "FontSwf_TestFont4" }` and `avm2_class_qname_buf` produces the same
dotted spelling.

This is kept as a **separate entry point** rather than folded into
`char_for_class`: the plain version is on the hot instantiation path and
stays a pure pointer scan, and widening it would also start binding a child's
`new SymbolClass()` to that child's timeline — a real behaviour change well
outside this task.

### A change considered and reverted

`loader_boot_child_swf` appends to `g_child_movies[]` *after*
`avm2_abc_register_movie()`, which eager-inits each child script. Publishing
the tables first is arguably more correct (a script initializer could ask a
table question about its own movie). It was not needed for either target and
the blast radius (every child char lookup, during every child's script init)
is far wider than this task's canary can cover, so it was reverted. Noted
here as a latent ordering wart.

## Canary

All 17 were **baseline-passing** in `results_graphics.json`. Run at `-P 2`
(machine shared). Default no-graphics mode.

| suite | test | result |
|---|---|---|
| avm2 | font_enumeratefonts | PASS |
| avm2 | font_enumeratefonts_filter | PASS (see note) |
| avm2 | font_embedded | PASS |
| avm2 | font_hasglyphs | PASS |
| avm2 | font_description_clone | PASS |
| avm2 | textline_splitting_basic | PASS |
| avm2 | textline_validity | PASS |
| visual | definefont4 | PASS (see note) |
| visual | fonts/font_lookup_as3 | PASS |
| visual | fonts/duplicate_font | PASS |
| visual | fonts/glyph | PASS |
| visual | text/String_path_variable_button | PASS |
| fonts | embed_matching/match_style | PASS |
| fonts | embed_matching/fallback_preferences | PASS |
| regression | avm2_timeline_text | PASS |
| regression | avm2_bitmapdata_draw_textfield | PASS |
| regression | avm2_static_text | PASS |

Three of the four DefineFont4-containing tests (`font_enumeratefonts`,
`textline_splitting_basic`, `textline_validity`) pass. `visual/definefont4`
is the 0-byte-expected silence assertion — see note.

**Note — `font_enumeratefonts_filter` COMPILE_FAIL was an artefact, not a
regression.** It failed to LINK (`undefined reference to
avm2_generated_shape_geom_count`, etc.) because this test's cached
`RecompiledABC/` in the source tree dates from **2026-07-11**, before those
tables existed, and `verify_output.py` skipped the recompile (`r=0.00s`).
Re-run with `--recompile`: **PASS** (`r=0.07s c=8.12s`). Nothing to do with
this patch — CI always recompiles. Worth knowing for any local sweep: an
`ld returned 1 exit status` on a font/text test is very likely a stale
per-test `RecompiledABC`, not a code fault.

**Note — the earlier `visual/definefont4` COMPILE_FAIL at `c=300.69s` was the
known false 300s gcc-timeout under `-P 2` load** (the hazard called out in the
brief). It was re-run sequentially with `SWFRECOMP_COMPILE_TIMEOUT=2400`;
result below.

> `visual/definefont4` → **PASS** (`r=0.00s c=615.98s x=0.13s`). Its expected
> `output.txt` is 0 bytes, so PASS *is* the silence assertion holding: stdout
> stayed empty. Its pre-existing stderr signature (`TypeError #1009 …
> getEffectiveLineHeight`, from TLF, present at baseline) is unchanged — no
> new stderr was emitted. Note the honest compile cost: 616 s single-threaded,
> i.e. the 300 s default gcc timeout cannot build this test at all under any
> parallel load. That is a property of the test, not of this patch.

## Not done (deliberate)

* **DefineFont4 parsing** (report step 3). Skipped per the brief: measured
  worth +0, all four tests containing the tag already pass.
* Suites not exercised locally: the change touches AVM2 runtime code, so the
  pipeline run for this should be `mode=graphics categories=full`.

## Reproducing

The worktree had no `SWFRecomp/build` and no downloaded test SWFs. Both were
copied in from the main checkout (`cp -r .../SWFRecomp/build`, plus the
individual test dirs) — valid because the change is runtime-only. Neither is
tracked, so `git diff` is clean of them.
