# getTextSnapshot User Constructor Plan
<!-- TESTS: movieclip_gettextsnapshot -->

Last updated: 2026-03-06

## Status: COMPLETE — movieclip_gettextsnapshot 112/112 PASS

### Overview

`getTextSnapshot()` should invoke the user-defined `_global.TextSnapshot` constructor (if overridden) instead of returning a built-in TextSnapshot object. The existing TEXTSNAPSHOT_PLAN implemented the built-in TextSnapshot functionality (getCount, getText, findText), but didn't handle the case where user code overrides `_global.TextSnapshot`.

**Test**: `movieclip_gettextsnapshot` — **112/112 PASS** (was 6/112).

### What Was Done

**Phase 1: Invoke user constructor** — DONE

Modified the `getTextSnapshot` MC builtin handler in `actionCallMethod` (action.c ~line 40741). Instead of always creating a built-in TextSnapshot object directly, it now:
1. Looks up `_global.TextSnapshot` via `actionGetVariable`
2. If the constructor has a callable body (type 1 simple_func or type 2 advanced_func), invokes it as `new TextSnapshot(mc)`:
   - Creates a new ASObject
   - Sets `__proto__` to constructor's prototype
   - Sets `__constructor__` on the instance
   - Pushes super context
   - Invokes the constructor with MC as first argument (handles both type 1 and type 2)
   - Respects constructor return value (if returns object, uses that instead)
3. If no callable body (stub ctor or missing), falls back to built-in TextSnapshot creation

**Phase 2: Dynamically created MC support** — Root cause was different

The `clip1.getTextSnapshot=undefined` issue was NOT about getTextSnapshot registration. It was about `createEmptyMovieClip` via `CallFunction` always creating on `root_movieclip` instead of `g_current_context`. Fixed at line 34550:
```c
// Was: MovieClip* mc = &root_movieclip;
MovieClip* mc = g_current_context ? g_current_context : &root_movieclip;
```

**Phase 3: Child MC context** — Already working

The getTextSnapshot handler correctly uses the `mc` parameter from CallMethod dispatch, which is the method receiver MC. No additional fix needed.

### Regression Testing

All 4 existing TextSnapshot tests still PASS:
- textsnapshot_gettext (55/55)
- textsnapshot_findtext (44/44)
- textsnapshot_text_order (1/1)
- textsnapshot_available_text (20/20)

All MC creation tests still PASS:
- create_empty_movie_clip, duplicate_movie_clip, movieclip_init_object, attach_movie, clip_events, on_construct, clip_constructors, register_class_return_value, movieclip_default_state, execution_order4, this_scoping, path_string, empty_movieclip_can_attach_movies
