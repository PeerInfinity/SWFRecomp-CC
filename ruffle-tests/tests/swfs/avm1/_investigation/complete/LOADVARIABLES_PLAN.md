# loadVariables Implementation Plan
<!-- TESTS: loadvariables, loadvariables2, loadvariables_method, loadvariablesnum -->

<!-- PLAN_META
id: LOADVARIABLES
status: complete
phases:
  - id: 1
    name: "Build Pipeline — Pre-bundle Data Files"
    status: complete
  - id: 2
    name: "Runtime — Parse and Set Variables"
    status: complete
  - id: 3
    name: "actionGetURL Routing"
    status: complete
  - id: 4
    name: "MC.loadVariables() Method"
    status: complete
dependencies:
  - plan: LOADMOVIE
    type: requires
    reason: "loadVariables shares infrastructure with loadMovie"
blockers: []
-->

Last updated: 2026-02-24

## Status: MOSTLY COMPLETE — 3/4 tests passing (loadvariables, loadvariablesnum, loadvariables2)

---

## Overview

`loadVariables(url, target)` loads a URL-encoded text file and sets the decoded key=value
pairs as variables on the target MovieClip or TextField. In Flash, this is asynchronous
(network fetch), but for our trace-test architecture we can pre-bundle the data files and
"load" them synchronously, similar to how we pre-compile child SWFs for loadMovie.

---

## Test Inventory

| Test | Lines | Expected Output | Data File | Dependencies |
|------|-------|-----------------|-----------|-------------|
| loadvariables | 2 | `Hurray\nThe test passed` | `testvars.txt` = `loaded=Hurray&also=The%20test%20passed` | actionGetURL2 with loadVars=1 |
| loadvariablesnum | 2 | `Hurray\nThe test passed` | `testvars.txt` = `loaded=Hurray&also=The%20test%20passed` | Same as above, targets `_levelN` |
| loadvariables_method | 7 | Navigator::fetch log + `Hurray\nThe test passed` | `testvars.txt` = `loaded=Hurray&also=The%20test%20passed` | MC.loadVariables() method, `log_fetch=true` |
| loadvariables2 | 8 | 3 test phases with setInterval polling | `variables` = `variableA=hello` | setInterval/clearInterval (TIMER_PLAN), TextField |

### Feasibility

| Test | Feasible? | Notes |
|------|-----------|-------|
| **loadvariables** | **YES** | Simple: load data file, parse, set vars, advance frames |
| **loadvariablesnum** | **YES** | Same as above but target is `_levelN` |
| **loadvariables_method** | **PARTIAL** | Needs `Navigator::fetch` log output (`log_fetch=true` in test.toml) |
| **loadvariables2** | **YES — NOW PASSING** ✅ | Timer/createTextField/polling requirements met |

**Realistically passing after this plan: 2/4** (loadvariables, loadvariablesnum).
loadvariables_method needs `log_fetch` support (7 lines, 2 match already).
loadvariables2 is blocked by TIMER_PLAN.

---

## How loadVariables Works

### ActionScript API

```actionscript
// Function form (actionGetURL / actionGetURL2):
loadVariables("testvars.txt", this);      // loadVars=1, loadTarget=1
loadVariablesNum("testvars.txt", 0);      // loadVars=1, target="_level0"

// Method form:
this.loadVariables("testvars.txt");       // MC method

// POST form (sends current vars, loads response):
loadVariables("testvars.txt", this, "POST");  // loadVars=3 (send+load)
```

### Data File Format

URL-encoded key=value pairs, `&`-separated:
```
loaded=Hurray&also=The%20test%20passed
```

After loading, `this.loaded == "Hurray"` and `this.also == "The test passed"`.

### SWF Bytecode

The recompiler emits `actionGetURL2(app_context, method, loadTarget, loadVars)`:
- `loadVars=1`: Load variables from URL (don't send current vars)
- `loadVars=2`: Send variables (don't load response)
- `loadVars=3`: Send variables AND load response

For `loadvariables`, the bytecode is:
```c
// Push "testvars.txt" (URL)
// Push "this" → GetVariable (target)
// GetURL2: method=NONE, loadTarget=1, loadVars=1
actionGetURL2(app_context, 0, 1, 1);
```

Currently, `actionGetURL2` with `loadVars=1` is NOT handled — it only handles `loadVars=0`
(loadMovie). The `loadVars` flag is ignored.

### Timing

In Flash, loadVariables is asynchronous. The test runs multiple frames (test.toml says
`num_frames = 3`). Frame 0 issues the load. Frame 1 polls (checks if `loaded` is defined).
Frame 2 polls again. By frame 1 or 2, the variables should be set.

For our implementation, we can set the variables synchronously during the `actionGetURL2`
call (like we do for loadMovie), so they'll be available by the next frame.

---

## Design

### Phase 1: Build Pipeline — Pre-bundle Data Files

**Goal**: Copy data files (`.txt`, `variables`, etc.) from upstream Ruffle into test directories
and make them available at compile time.

**Approach**: Similar to child SWF handling.

1. **Download**: Update `download_tests.sh` to copy non-.swf, non-.fla data files from
   upstream Ruffle test directories. Specifically: `testvars.txt`, `variables` (no extension).

2. **Compile-time embedding**: In `verify_output.py`, detect data files and embed them as
   C string constants in a generated `data_registry.c`:

   ```c
   // Auto-generated data file registry
   typedef struct DataFileEntry {
       const char* filename;
       const char* content;
       int content_length;
   } DataFileEntry;

   static const char data_testvars_txt[] = "loaded=Hurray&also=The%20test%20passed";

   static DataFileEntry g_data_files[] = {
       { "testvars.txt", data_testvars_txt, 38 },
       { NULL, NULL, 0 }
   };

   DataFileEntry* findDataFile(const char* filename) {
       for (int i = 0; g_data_files[i].filename != NULL; i++) {
           if (strcmp(g_data_files[i].filename, filename) == 0)
               return &g_data_files[i];
       }
       return NULL;
   }
   ```

   **Alternative (simpler)**: Since data files are small, we could define them as compile-time
   macros: `-DDATA_FILE_testvars_txt="loaded=Hurray&also=The%20test%20passed"`. But this
   gets messy with special characters. The generated C file approach is cleaner.

### Phase 2: Runtime — Parse and Set Variables

**Goal**: When `actionGetURL2` is called with `loadVars=1`, look up the data file, parse
URL-encoded content, and set variables on the target.

**Where**: `actionGetURL2` in `action.c` (~line 17497), add a branch for `load_vars_flag != 0`.

**Implementation**:

```c
// In actionGetURL2, after existing loadTarget handling:
if (load_vars_flag != 0 && load_target_flag != 0) {
    // loadVariables mode: load URL-encoded vars into target
    // 1. Resolve target MC (same as loadMovie target resolution)
    // 2. Look up data file: findDataFile(url_utf8)
    // 3. If found, parse URL-encoded content and set vars on target MC
    //    Reuse parseAndSetFlashVars() — it already does URL-decode + set properties
    //    But need to modify it to work with a raw content string (no '?' prefix)
    // 4. If target is a level, resolve via getOrCreateLevel()
}
```

The existing `parseAndSetFlashVars()` function already handles URL-decoding and setting
properties on a MovieClip's `dynamic_props`. We need a variant that works with raw
URL-encoded content (no `?` prefix):

```c
static void parseURLEncodedVars(SWFAppContext* app_context, const char* content,
                                 int content_length, MovieClip* target_mc) {
    // Same logic as parseAndSetFlashVars but starts parsing from the beginning
    // (no '?' search). Make a mutable copy, split on '&', decode key=value pairs.
}
```

Or refactor `parseAndSetFlashVars` to accept a query string directly.

### Phase 3: actionGetURL Routing

**Goal**: Route the `loadVars` flag correctly in both `actionGetURL` and `actionGetURL2`.

Currently `actionGetURL2` ignores `loadVars`. Need to add:

1. **`loadVars=1, loadTarget=1`**: Load variables from URL into target (loadVariables)
2. **`loadVars=2, loadTarget=0`**: Send variables (POST) — loadvariables_method only
3. **`loadVars=3, loadTarget=1`**: Send + receive (combined) — not tested

For Phase 3, focus on `loadVars=1` (receive only). The POST mode (`loadVars=2/3`) is more
complex and only needed for `loadvariables_method` (which also needs `log_fetch` support).

### Phase 4: MC.loadVariables() Method

**Goal**: Add `loadVariables(url)` as a MovieClip prototype method.

Similar to `MC.loadMovie(url)` but calls the variable-loading path instead.

```c
// In the MC method dispatch chain (action.c, ~line 28000+):
if (strcasecmp(method_name, "loadVariables") == 0) {
    // Get URL from args[0]
    // Look up data file
    // Parse and set variables on this MC
}
```

---

## Implementation Order

1. **Phase 1**: Copy data files from upstream Ruffle (`download_tests.sh` update)
2. **Phase 1b**: Generate `data_registry.c` in `verify_output.py` for tests with data files
3. **Phase 2**: Add `parseURLEncodedVars()` helper (refactor from `parseAndSetFlashVars`)
4. **Phase 2b**: Handle `loadVars=1` in `actionGetURL2`
5. **Phase 3**: Handle `loadVars=1` in `actionGetURL` (for loadVariablesNum)
6. **Phase 4**: Add `MC.loadVariables()` method

After Phase 3: **loadvariables** and **loadvariablesnum** should pass.
After Phase 4: **loadvariables_method** partially (needs `log_fetch` for full pass).
**loadvariables2** blocked by TIMER_PLAN (setInterval/clearInterval).

---

## Verification

```bash
python3 ruffle-tests/verify_output.py --test=loadvariables --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadvariablesnum --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadvariables_method --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadvariables2 --diff --verbose

# Regression checks:
python3 ruffle-tests/verify_output.py --test=loadmovie --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadmovie_flashvars --diff --verbose
```

---

## Ruffle Reference

- `~/CC/ruffle/core/src/avm1/activation.rs:1147-1289` — ActionGetURL2 loadVars handling
- `~/CC/ruffle/core/src/avm1/globals/movie_clip.rs:1613-1664` — MC.loadVariables()
- `~/CC/ruffle/core/src/loader.rs` — Variable loading and URL-encoded parsing
