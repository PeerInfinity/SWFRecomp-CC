# TellTarget / Target Path Resolution Implementation Plan
<!-- TESTS: tell_target, tell_target_invalid, tell_target_invalid_swf6, target_clip_swf5, target_clip_swf6, target_clip_removed, path_string, slash_syntax, string_paths_basic, string_paths_eval, string_paths_eval2, string_paths_hidden, string_paths_other, string_paths_reference_launder, string_paths_unload, string_paths_variable_alias, string_paths_variable_scopes, removed_base_clip_tell_target, removed_target_clip_scope -->

Last updated: 2026-02-22

## Status: PARTIALLY IMPLEMENTED

### CI Results (2026-02-22)
All core tellTarget tests still fail on CI:
- `tell_target` — output_mismatch
- `removed_base_clip_tell_target` — output_mismatch
- `removed_clip_halts_script` — output_mismatch
- `removed_target_clip_scope` — output_mismatch

### What's Implemented
- **actionSetTarget**: Resolves target names via `findDisplayObjectByName()`, sets `g_current_context`
- **actionSetTarget2**: Stack-based variant, fast path for MOVIECLIP type objects
- **Scope isolation**: Inside non-root context, variables resolve to clip's dynamic_props then _global
- **Empty/"_root" reset**: Resets targeted_sprite to NULL

### Still Missing
- Slash-path parsing (e.g. `/A/B`)
- Colon-syntax for variable access (e.g. `/A/B:FOO`)
- `..`/`_parent` navigation
- `eval()` function
- "Target not found" error messages
- Base clip tracking for nested tellTarget
- Recursive child lookup (only root display list scanned)

## Overview (original)

TellTarget (ActionSetTarget/ActionSetTarget2) and string path resolution are interconnected features that control how ActionScript code addresses movie clips and their variables by name. This involves two distinct but related path resolution algorithms — one for `GetVariable`/`SetVariable` (dot-path oriented) and one for `SetTarget`/`tellTarget` (slash-path oriented) — plus supporting features like `eval()`, `_parent` navigation, base clip tracking, and error messages.

**Key insight from the `path_string` test**: `GetVariable` (get) and `SetTarget` (tellTarget) use **fundamentally different path parsing algorithms**. The same path string can resolve successfully in `get()` but fail in `tellTarget()`, and vice versa. We must implement both algorithms correctly.

## SWF Spec Reference

From `SWFRecompDocs/specs/swf-spec-19.txt`:

- **ActionSetTarget (0x8B)**: "Instructs Flash Player to change the context of subsequent actions, so they apply to a named object (TargetName) rather than the current file."
- **ActionSetTarget2 (0x20)**: "Pops the target off the stack and makes it the current active context. This action behaves exactly like ActionSetTarget but is stack based."
- **ActionGetVariable (0x1C)**: "A variable in another execution context can be referenced by prefixing the variable name with the target path and a colon. For example: `/A/B:FOO` references variable FOO in movie clip `/A/B`."
- **ActionTargetPath (0x45)**: "If the object in the stack is of type MovieClip, the object's target path is pushed on the stack in dot notation."

Internal MovieClip `target` fields use slash-path format: `"/"` for root, `"/clip"` for root child, `"/parent/child"` for nested.

---

## Test Inventory (~20 tests, grouped by sub-feature)

### Core TellTarget (6 tests)
| Test | Lines | Current Match | Notes |
|------|-------|--------------|-------|
| tell_target | 37 | 0/37 (0%) | Comprehensive: nested tellTarget, base clip, toString, error msgs |
| tell_target_invalid | 6 | 0/6 (0%) | Invalid target + error msg + gotoAndPlay behavior |
| tell_target_invalid_swf6 | 5 | 0/5 (0%) | SWF6 variant of above |
| target_clip_swf5 | 2 | 0/2 (0%) | `_target` property returns "/circle" |
| target_clip_swf6 | 2 | 0/2 (0%) | `_target` property returns "/" (root context) |
| target_clip_removed | 5 | 4/5 (80%) | Near-passing, removed clip edge case |

### Path String Resolution (1 test)
| Test | Lines | Current Match | Notes |
|------|-------|--------------|-------|
| path_string | 322 | 44/322 (14%) | **SEGFAULT**. Exhaustive get() vs tellTarget() path combos |

### Slash Syntax (1 test)
| Test | Lines | Current Match | Notes |
|------|-------|--------------|-------|
| slash_syntax | 14 | 0/14 (0%) | Colon syntax, absolute/relative slash paths, `..` parent nav |

### String Paths (9 tests)
| Test | Lines | Current Match | Notes |
|------|-------|--------------|-------|
| string_paths_basic | 4 | 2/4 (50%) | Basic eval + path resolution |
| string_paths_eval | 4 | 0/4 (0%) | eval() function resolving paths |
| string_paths_eval2 | 7 | 1/7 (14%) | eval() with loadMovie (partially network) |
| string_paths_hidden | 54 | 34/54 (63%) | get() with shapes as path components |
| string_paths_other | 36 | 11/36 (31%) | Mixed path resolution scenarios |
| string_paths_reference_launder | 2 | 0/2 (0%) | Reference laundering via path resolution |
| string_paths_unload | 1 | 0/1 (0%) | Path resolution after unload |
| string_paths_variable_alias | 4 | 2/4 (50%) | Variable aliasing via paths |
| string_paths_variable_scopes | 5 | 0/5 (0%) | Variable scope resolution with `this`, `_root` |

### Removed Clip + TellTarget (2 tests)
| Test | Lines | Current Match | Notes |
|------|-------|--------------|-------|
| removed_base_clip_tell_target | 2 | 0/2 (0%) | Base clip removed during tellTarget |
| removed_target_clip_scope | 35 | 0/35 (0%) | Scope resolution after removeMovieClip |

**Total: ~20 tests, currently ~93/531 lines matching (~18%)**

---

## Path Resolution Algorithms

The most critical thing to understand is that **get() and tellTarget() parse paths differently**.

### Algorithm 1: GetVariable Path Resolution (get)

Used by: `actionGetVariable`, `actionSetVariable`, `actionCallFunction` (for function paths)

Parsing rules (derived from `path_string` and `string_paths_hidden` test expectations):

1. **Dot-only paths** (`clip1.clip2.clip3`): Split on `.`, walk clip tree. Each segment is a GetMember call. Works for any depth.

2. **Colon as separator**: `:` is treated like `.` for path segment separation in many contexts:
   - `clip1:clip2.clip3` → resolves as `clip1.clip2.clip3` ✓
   - `clip1:clip2:clip3` → resolves as `clip1.clip2.clip3` ✓
   - `clip1.clip2:clip3` → resolves as `clip1.clip2.clip3` ✓

3. **Slash-colon syntax** (`/clip1/clip2:var`): The SWF spec syntax. Split on `/` for clip navigation, then `:` separates the final variable name from the clip path:
   - `/clip1/clip2:clip3` → clip3 on clip at /clip1/clip2 ✓
   - `clip1/clip2:clip3` → same, relative ✓

4. **Slash introduces a "mode change"**: Once a `/` appears, the parsing rules change. After a `/`, dot (`.`) is no longer a path separator:
   - `clip1/clip2.clip3` → resolves as `clip1` / then `clip2.clip3` as a single name → **fails** (no clip named "clip2.clip3")
   - `clip1.clip2/clip3.clip4` → resolves as `clip1.clip2` (dot-path) / then `clip3.clip4` → **fails**
   - Exception: BEFORE the first `/`, dots still work: `clip1.clip2/shape2` → `clip1.clip2` dot-resolved, then `/shape2` fails because `shape2` is a shape not a clip

5. **After `/`, colon works but dot doesn't**:
   - `clip1/clip2:clip3` → ✓ (colon separates within slash-path)
   - `clip1/clip2.clip3` → fails (dot after slash = literal name match)

6. **`_parent` navigation**: Works as a dot-segment:
   - `clip1.clip2._parent` → `clip1` ✓
   - `clip1.clip2.shape2._parent` → `clip1` ✓

7. **`..` navigation**: Works in slash-paths:
   - `clip1/clip2/../clip2/clip3` → resolves `..` as parent ✓ (in get(), returns undefined though — quirk)
   - `/clip1/../clip1/clip2:val` → ✓ in slash_syntax test

8. **`this` resolution**: `this.clip1.clip2` → resolves `this` as the current clip, then dot-walks. `this/clip1` → resolves `this` as current clip via slash-path.

9. **Leading `/:` syntax**: `/:FOO` means variable FOO on root. Already partially handled.

10. **`_level0` prefix**: `_level0.clip1` or `_level0/clip1` → starts at root.

11. **Colon-variable syntax in get**: `clip2:val` (no slash) → resolves `clip2` as a clip, reads `val` as a variable on it.

### Algorithm 2: SetTarget Path Resolution (tellTarget)

Used by: `actionSetTarget`, `actionSetTarget2`

This is simpler but stricter:

1. **Dot-only paths**: `clip1.clip2.clip3` → split on `.` and `:`, navigate child clips. ✓

2. **Colon-only paths**: `clip1:clip2:clip3` → split on `:`, navigate child clips. ✓

3. **Slash-paths**: `clip1/clip2/clip3` → split on `/`, navigate child clips. ✓. Also `/clip1/clip2/clip3` (absolute from root). ✓

4. **Mixed colons in slash-paths**: `clip1/clip2:clip3` → `:` after a slash-segment works as a separator. ✓

5. **Critical difference — dots after slash FAIL**:
   - `clip1/clip2.clip3` → **"Target not found"** ✗
   - `clip1.clip2/.clip3` → **"Target not found"** ✗
   - `/clip1.clip2.clip3.clip4` → **"Target not found"** ✗

   Rule: In tellTarget, once a `/` is present anywhere in the path, `.` is NOT a valid separator (except in the pre-slash prefix when no `/` comes before).

   More precisely: tellTarget first checks if the path contains `/`. If it does, it uses slash-based parsing where only `/` and `:` are separators. If no `/`, it uses dot/colon parsing.

6. **`..` parent navigation**: Works in slash-paths: `clip1/clip2/clip3/..` → `clip2`. ✓

7. **`_parent` navigation**: Works as a colon-segment or slash-segment: `_root/clip1/clip2:_parent` → `clip1`. ✓

8. **`this` does NOT resolve**: `this.clip1.clip2` → **"Target not found"** ✗. `this/clip1` → **"Target not found"** ✗. (tellTarget does not understand `this` as a keyword)

9. **Error message format**: When target resolution fails, Flash/Ruffle outputs:
   ```
   Target not found: Target="<path>" Base="_level0.clip_name"
   ```
   The Base is the current execution clip in dot notation.

10. **Trailing separators**: `clip3/clip4/` → resolves to `clip4` (trailing slash ignored). `clip3/clip4:` → resolves to `clip4` (trailing colon ignored). But `clip3/clip4.` → "Target not found" (trailing dot in slash mode fails).

11. **Leading colons are stripped**: `::::clip1` → resolves to `clip1`. Multiple leading colons are ignored.

### Summary of key differences

| Path | get() result | tellTarget() result |
|------|-------------|-------------------|
| `clip1.clip2.clip3` | ✓ resolves | ✓ resolves |
| `clip1:clip2:clip3` | ✓ resolves | ✓ resolves |
| `clip1/clip2:clip3` | ✓ resolves | ✓ resolves |
| `clip1/clip2.clip3` | ✗ undefined | ✗ Target not found |
| `/clip1.clip2.clip3` | ✗ undefined | ✗ Target not found |
| `clip1.clip2/.clip3` | ✓ resolves | ✗ Target not found |
| `this.clip1.clip2` | ✓ resolves | ✗ Target not found |
| `clip1/clip2/clip3/..` | ✗ undefined | ✓ resolves to clip2 |

---

## Implementation Phases

### Phase 1: Core Path Resolution Infrastructure

**Goal**: Implement the two path resolution algorithms as reusable functions, add recursive child clip lookup, and wire them into existing action functions.

#### 1a. Recursive child clip lookup

Currently `findDisplayObjectByName()` (graphics) and `ng_findDisplayEntryByName()` (NO_GRAPHICS) only search the root display list. We need a function that can search child display lists recursively, or more specifically, resolve a child name relative to a parent MovieClip.

```c
// Resolve a single child name relative to a parent MovieClip
// Returns the child MovieClip, or NULL if not found
static MovieClip* resolveChildClip(SWFAppContext* app_context, MovieClip* parent, const char* child_name);
```

In NO_GRAPHICS mode, this needs to:
1. If parent is root: check `ng_findDisplayEntryByName(child_name)` at root level
2. If parent is a sprite: check child display entries within that sprite
3. Handle `_parent` → return `parent->parent`
4. Handle `_root` → return `&root_movieclip`
5. Handle `..` → return `parent->parent`

#### 1b. GetVariable path parser

Replace the current ad-hoc dot-splitting in `actionGetVariable` with a proper parser:

```c
// Resolve a string path to a variable value using GetVariable rules
// Returns 1 if resolved, 0 if not found
// Result is pushed onto the stack
static int resolveGetVariablePath(SWFAppContext* app_context, const char* path, int path_len);
```

Algorithm:
1. Check for `_level0`/`_root` prefix → start from root
2. If path contains `/`:
   - Split on `/` for clip navigation
   - Within each segment, `:` separates clip names
   - The LAST `:` segment is the variable name
   - After a `/`, dots are literal (not separators)
3. If no `/`:
   - Split on `.` and `:` interchangeably for path navigation
   - The last segment is the variable name (or a clip reference)
4. Navigate: for each segment, call `resolveChildClip()` or `actionGetMember()`
5. Handle `_parent`, `..`, `this` as special segments

#### 1c. SetTarget path parser

```c
// Resolve a string path to a MovieClip using SetTarget rules
// Returns the target MovieClip, or NULL if not found
static MovieClip* resolveSetTargetPath(SWFAppContext* app_context, const char* path, MovieClip* base_clip);
```

Algorithm:
1. Empty string / NULL → return base_clip
2. `_root` or `/` alone → return root
3. If path contains `/`:
   - Use slash-based parsing: split on `/` and `:`
   - Leading `/` → start from root; otherwise start from base_clip's parent scope
   - `.` is NOT a separator (literal part of name)
   - `..` and `_parent` navigate to parent
4. If no `/`:
   - Split on `.` and `:` for path navigation
   - `..` and `_parent` navigate to parent
5. Strip leading colons
6. On failure → return NULL (caller generates error message)

#### 1d. Base clip tracking

The `tell_target` test shows that `SetTarget2(undefined)` and `SetTarget2("")` inside a nested tellTarget should return to the **base clip** (the clip whose timeline code is executing), not `_root`.

We need a `base_clip` concept:
```c
static MovieClip* g_base_clip = NULL;  // The clip whose code is currently executing
```

- Set `g_base_clip` when entering a script (at script_N entry or when executing a clip's frame action)
- `actionSetTarget(app_context, "")` → reset to `g_base_clip` (not `_root`)
- `actionSetTarget2` with undefined/empty → reset to `g_base_clip`
- `actionSetTarget` with invalid path → keep current context unchanged? No — based on `tell_target` test, after invalid target, reading variable `n` returns "root", meaning context falls back to root for variable reads but the base clip is preserved for the reset.

Actually, looking more carefully at the test:
```
tellTarget('clip2') {
  n: clip2
  tellTarget('INVALID') {
    Target not found: Target="INVALID" Base="_level0.clip1"
    n: root        ← reads from root scope (invalid target → root context)
  }
  n: clip2         ← back to clip2 after tellTarget block ends
}
```

This means: invalid SetTarget falls back to root for the scope context. The "returning to clip2" is because the inner tellTarget block ends and the outer one is restored. This is actually about the **recompiler** emitting paired SetTarget/SetTarget("") calls.

Looking at how the recompiler emits tellTarget blocks:
```c
actionSetTarget(app_context, "clip2");
// ... actions inside tellTarget ...
actionSetTarget(app_context, "");   // end of tellTarget block → reset
```

The reset `actionSetTarget("")` needs to return to **clip1** (the code's base clip), not `_root`.

Implementation:
- Each script has a base clip. When `actionSetTarget("")` or `actionSetTarget2(undefined)` is called, restore to the base clip.
- Invalid target → set context to root (as the test shows, `n: root` is the result).
- The base clip needs to be set per-script-execution, not globally. We could:
  - Pass it via a function parameter (recompiler change needed)
  - Store it on the call stack
  - Use a static that gets set before each script invocation

The simplest approach: add a `g_base_clip` static, set it in the generated `script_N()` entry point.

#### 1e. "Target not found" error messages

When `resolveSetTargetPath()` returns NULL, output:
```
Target not found: Target="<path>" Base="<base_clip_dot_path>"
```

The Base uses dot notation: `_level0.clip1` (not slash). Convert `g_base_clip->target` (which is in slash format like `/clip1`) to dot format (`_level0.clip1`).

Conversion: `"/"` → `"_level0"`, `"/clip1"` → `"_level0.clip1"`, `"/clip1/clip2"` → `"_level0.clip1.clip2"`.

Special case from `removed_base_clip_tell_target`: if the base clip has been removed, Base is `"?"`.

### Phase 1 Tests Fixed

- **tell_target**: Should reach ~90%+ (core tellTarget + nested + error msgs + base clip)
- **tell_target_invalid**: Fixed (error msg + gotoAndPlay with invalid target)
- **tell_target_invalid_swf6**: Fixed
- **target_clip_removed**: 4/5 → 5/5 (edge case fixed)
- **slash_syntax**: Most lines fixed (colon syntax, absolute paths, `..` navigation)
- **path_string**: Fix segfault, significantly improve match rate

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=tell_target --test=tell_target_invalid --test=tell_target_invalid_swf6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=slash_syntax --test=target_clip_removed --diff --verbose
python3 ruffle-tests/verify_output.py --test=path_string --diff --verbose
```

---

### Phase 2: eval() and GetVariable Enhancements

**Goal**: Implement `eval()` built-in function, fix GetVariable slash-path + colon-variable resolution, and handle `_parent` navigation in dot-paths.

#### 2a. eval() function

In Flash, `eval("path")` is equivalent to `GetVariable("path")` — it resolves a string path to a clip reference or variable value.

Register `eval` as a built-in function in `actionCallFunction`:
```c
if (strcasecmp(func_name, "eval") == 0) {
    // Pop argument (path string), push resolved value
    // Reuse the GetVariable path resolution logic
    actionGetVariable(app_context);  // effectively the same operation
    return;
}
```

Actually, `eval()` in Flash specifically returns a MovieClip reference (not a variable value) when the path resolves to a clip. It's used for:
- `eval("clip1")` → MovieClip reference
- `eval("_root.clip1")` → MovieClip reference
- `eval("clip1.varname")` → variable value

This is the same as `GetVariable` behavior, which already returns MovieClip references for clip names.

#### 2b. _parent in dot-paths

Currently `_parent` is not handled in `actionGetVariable` dot-path splitting. Need to handle it as a special segment that returns `mc->parent`.

```c
// In the dot-path walker:
if (strcmp(segment, "_parent") == 0 || strcmp(segment, "..") == 0) {
    mc = mc->parent;  // Navigate to parent
    continue;
}
```

#### 2c. Variable-on-clip via colon in GetVariable

The `slash_syntax` test expects `clip2:val` to read variable `val` on clip `clip2`. Currently only the dot-path splitter works; we need to handle the colon case:

```c
// In actionGetVariable, before dot-path splitting:
// Check for colon-variable syntax: "clippath:varname"
const char* colon = find_last_colon_or_slash_colon(path);
if (colon) {
    // Everything before colon = clip path, everything after = variable name
    MovieClip* clip = resolveClipPath(path_before_colon);
    if (clip) return getVariableOnClip(clip, var_after_colon);
}
```

#### 2d. SetVariable slash-path + colon support

`actionSetVariable` needs matching updates. From `path_string` test lines 294-322:
- `set('clip5/foo', 1)` → sets `foo` on clip5 (slash-path without colon)
- `set('clip5/:foo', 2)` → sets `foo` on clip5 (slash + colon-variable)
- `set('clip5::foo', 3)` → sets `foo` on clip5 (double-colon = colon separator)
- `set('clip5/_parent.foo', 4)` → sets `foo` on clip5's parent
- `set('this:bar', 10)` → sets `bar` on `this` (current clip)
- `set('this/clip5:foo', 8)` → sets `foo` on clip5 via `this`

### Phase 2 Tests Fixed

- **string_paths_basic**: 2/4 → 4/4 (eval + path resolution)
- **string_paths_eval**: 0/4 → ~3/4 (eval function; eval2 needs loadMovie)
- **string_paths_variable_scopes**: 0/5 → ~5/5 (this, _root resolution)
- **string_paths_variable_alias**: 2/4 → 4/4
- **string_paths_reference_launder**: 0/2 → ~2/2
- **string_paths_hidden**: 34/54 → ~50/54 (improved path resolution)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_paths_basic --test=string_paths_eval --test=string_paths_variable_scopes --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_hidden --test=string_paths_other --diff --verbose
```

---

### Phase 3: Removed Clip Edge Cases

**Goal**: Handle scope resolution when target or base clips are removed via `removeMovieClip()`.

#### 3a. Removed target clip scope

From `removed_target_clip_scope` test:
- When the target clip of a tellTarget is removed, the scope falls back to the base clip
- When the base clip itself is removed, scope falls back to root
- When a clip that is both base and target is removed, variable writes go to `_root`'s scope

This requires:
1. Checking if the target clip is still "alive" (on the display list) before variable resolution
2. If target is removed → fall back to base clip scope
3. If base clip is removed → fall back to root scope

MovieClip needs a "removed" flag or we check if it's still on the display list:
```c
// Check if a MovieClip is still alive (on display list)
static int isClipAlive(MovieClip* mc);
```

#### 3b. Removed base clip tellTarget

From `removed_base_clip_tell_target`:
- When base clip is removed, the Base in error messages becomes `"?"`
- tellTarget to `_root` from a removed base clip still outputs the error (Base="?")

### Phase 3 Tests Fixed

- **removed_target_clip_scope**: 0/35 → ~30/35 (depends on other features like removeMovieClip)
- **removed_base_clip_tell_target**: 0/2 → 2/2
- **target_clip_swf5**: 0/2 → 2/2 (_target property)
- **target_clip_swf6**: 0/2 → 2/2 (_target property)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=removed_target_clip_scope --test=removed_base_clip_tell_target --diff --verbose
python3 ruffle-tests/verify_output.py --test=target_clip_swf5 --test=target_clip_swf6 --diff --verbose
```

---

### Phase 4: GetProperty/SetProperty Target Resolution

**Goal**: Fix `actionGetProperty()` and `actionSetProperty()` to resolve child clip targets.

Currently `getMovieClipByTarget()` only resolves `_root`/`/`/empty. All other targets return NULL, meaning property gets/sets on child clips silently fail.

Replace `getMovieClipByTarget()` with proper path resolution:
```c
static MovieClip* getMovieClipByTarget(const char* target) {
    if (!target || strlen(target) == 0)
        return g_current_context ? g_current_context : &root_movieclip;
    if (strcmp(target, "_root") == 0 || strcmp(target, "/") == 0)
        return &root_movieclip;
    // Use the GetVariable path resolver to find the clip
    return resolveClipByPath(app_context, target);
}
```

This fixes `actionGetProperty(target, prop_index)` and `actionSetProperty(target, prop_index, value)` for child clips.

### Phase 4 Tests Fixed

This phase primarily fixes tests in other categories that depend on property access via target paths. Direct impact on TellTarget tests is small, but it unblocks progress on other feature areas.

---

### Phase 5: actionTargetPath Fix

**Goal**: Fix the slash-to-dot conversion in `actionTargetPath()`.

Current bug: paths like `/clip` aren't properly converted to `_level0.clip` because the code only handles `/.clip` prefix (looking for `/.` after the leading `/`), not plain `/clip`.

Fix:
```c
// Convert slash-path to dot-notation
// "/" → "_level0"
// "/clip" → "_level0.clip"
// "/clip1/clip2" → "_level0.clip1.clip2"
static void slashPathToDotNotation(const char* slash_path, char* out, size_t out_size) {
    if (strcmp(slash_path, "/") == 0) {
        snprintf(out, out_size, "_level0");
        return;
    }
    // Replace leading "/" with "_level0" and remaining "/" with "."
    snprintf(out, out_size, "_level0");
    const char* p = slash_path + 1;  // skip leading "/"
    while (*p) {
        if (*p == '/') strcat(out, ".");
        else { char tmp[2] = {*p, 0}; strcat(out, tmp); }
        p++;
    }
}
```

This also affects the `_target` property getter and the Base path in "Target not found" messages.

---

## Implementation Priority and Dependencies

```
Phase 1 ──→ Phase 2 ──→ Phase 3
  │
  ├──→ Phase 4 (independent of 2,3)
  │
  └──→ Phase 5 (independent of 2,3,4)
```

Phase 1 is the foundation — everything else builds on the path resolution infrastructure.

**Estimated test impact:**

| Phase | Tests Fixed/Improved | Cumulative Passing Lines |
|-------|---------------------|------------------------|
| 1 | tell_target(~34), tell_target_invalid(~6), tell_target_invalid_swf6(~5), slash_syntax(~12), target_clip_removed(5), path_string(fix segfault + ~150) | ~212/531 |
| 2 | string_paths_basic(4), eval(~3), variable_scopes(5), variable_alias(4), reference_launder(2), hidden(~50), other(~25) | ~305/531 |
| 3 | removed_target_clip_scope(~30), removed_base_clip_tell_target(2), target_clip_swf5(2), target_clip_swf6(2) | ~341/531 |
| 4 | (Indirect; fixes property access for other test categories) | ~341/531 |
| 5 | (Small; fixes actionTargetPath output format) | ~345/531 |

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | New path resolution functions, rewrite actionSetTarget/actionSetTarget2, enhance actionGetVariable/actionSetVariable with slash-path + colon support, add eval() to actionCallFunction, add g_base_clip tracking, add "Target not found" messages, fix actionTargetPath, rewrite getMovieClipByTarget |
| `include/actionmodern/action.h` | New function declarations (if any are public), base_clip setter |
| `src/libswf/tag_stubs.c` | May need recursive child lookup helpers for NO_GRAPHICS mode |
| `include/libswf/tag.h` | New NO_GRAPHICS child lookup function declarations |

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | Emit `actionSetBaseClip(app_context, clip_name)` at script entry; OR pass base clip context to script functions |

### No new files needed — all changes are in existing files.

---

## Design Decisions

1. **Two separate resolver functions vs one**: We need two distinct functions because get() and tellTarget() use fundamentally different algorithms. Trying to unify them would make the code more complex and harder to verify against the test expectations. The resolvers share the child clip lookup helper but diverge in parsing logic.

2. **Base clip tracking**: Use a simple static `g_base_clip` that gets set before each script invocation. The recompiler already emits per-script functions (`script_0`, `script_1`, etc.) that are called from `tagMain.c`. We can set `g_base_clip` at the call site in tagMain or at the start of each script function. The simplest approach is to emit `actionSetBaseClip(app_context, "clip_name")` as the first line of each script that runs in a clip context.

3. **Slash-to-dot conversion**: Implement as a utility function since it's needed in multiple places (actionTargetPath, error messages, _target property). The conversion is simple: replace leading `/` with `_level0` and subsequent `/` with `.`.

4. **Path resolution ordering**: The `path_string` test is 322 lines and extremely precise about which paths resolve and which don't. We should focus on getting the algorithm right based on the patterns, then run the test to find remaining edge cases. The test is currently segfaulting, so fixing the segfault alone will reveal a lot of useful diff output.

5. **`this` handling in GetVariable vs SetTarget**: `this` resolves in GetVariable (returns the current clip) but NOT in SetTarget (returns "Target not found"). This is because `this` is a special variable, not a clip name. GetVariable checks special variables first, while SetTarget only does clip name resolution.

---

## Quick Win Estimate

**Phase 1 alone** would fix ~8 tests (tell_target family + slash_syntax + fix path_string segfault) and move ~212 lines from failing to passing. This is the highest-impact phase.

**Phases 1+2** would fix an additional ~7 string_paths tests, reaching ~15 tests fixed total.

The `path_string` test alone accounts for 322 expected lines — fixing the segfault and implementing the path resolution algorithms would have outsized impact on the overall line match count even if not all 322 lines pass immediately.
