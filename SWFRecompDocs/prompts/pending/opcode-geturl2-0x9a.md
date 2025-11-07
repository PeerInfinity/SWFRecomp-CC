# AS2 Opcode Implementation Task: ActionGetURL2

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionGetURL2**

## Opcode Specification

**Opcode Name**: ActionGetURL2
**Hex Value**: 0x9A
**Category**: Movie Control / External Communication
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Stack-based version of GetURL with HTTP method support. Loads URLs with GET/POST methods and can load variables or SWF files.

**Operation**: Pop target and URL from stack, load URL using specified method and flags.

**Expected Behavior** (from SWF Spec 19):
- Stack-based version of ActionGetURL (0x83)
- Supports HTTP request methods (GET, POST)
- Can load variables or SWF content
- Pops target from stack
- Pops URL from stack
- Uses SendVarsMethod to specify HTTP method
- LoadTargetFlag indicates if target is browser window (0) or sprite path (1)
- LoadVariablesFlag indicates if loading variables (1) or content (0)

**Stack Operations**:
```
Before: [... url, target]
After:  [... ]
```

**Action Record Format**:
```
Field                Type    Comment
ActionCode           UI8     0x9A
Length               UI16    Always 1
SendVarsMethod       UB[2]   0=None, 1=GET, 2=POST
Reserved             UB[4]   Always 0
LoadTargetFlag       UB[1]   0=window, 1=sprite path
LoadVariablesFlag    UB[1]   0=load content, 1=load variables
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GET_URL2 = 0x9A` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse flags byte)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with URL loading
6. **Setup Test Directory** - Create `SWFRecomp/tests/get_url2_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Load URL in new window (no method)
```actionscript
var url = "https://www.example.com";
var target = "_blank";
getURL(url, target);
trace("URL load requested");
```
Expected output: `URL load requested`

### Test Case 2: GET request with variables
```actionscript
var url = "script.php";
var target = "_self";
// Movie variables: name="John", age=30
loadVariables(url, "_root", "GET");
trace("Loading variables");
```
Expected output: `Loading variables`

### Test Case 3: POST request
```actionscript
var url = "submit.php";
// POST movie variables to URL
loadVariables(url, "_root", "POST");
trace("Posting data");
```
Expected output: `Posting data`

### Test Case 4: Load SWF into sprite
```actionscript
var url = "movie.swf";
var target = "/clip";
loadMovie(url, target);
trace("Loading movie");
```
Expected output: `Loading movie`

### Test Case 5: Dynamic URL from expression
```actionscript
var base = "https://example.com/";
var page = "page.html";
getURL(base + page, "_blank");
trace("Opening page");
```
Expected output: `Opening page`

## Implementation Hints

**Pattern**: This is a stack-based external communication operation with method and flag support.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GET_URL2:
{
    // Read flags byte
    u8 flags;
    in.read((char*)&flags, 1);

    u8 send_vars_method = (flags & 0xC0) >> 6;  // Top 2 bits
    u8 load_target_flag = (flags & 0x02) >> 1;   // Bit 1
    u8 load_variables_flag = (flags & 0x01);     // Bit 0

    const char* method_str = "NONE";
    if (send_vars_method == 1) method_str = "GET";
    else if (send_vars_method == 2) method_str = "POST";

    out_script << "\t" << "// GetURL2: method=" << method_str
               << ", loadTarget=" << (int)load_target_flag
               << ", loadVars=" << (int)load_variables_flag << endl
               << "\t" << "actionGetURL2(stack, sp, "
               << (int)send_vars_method << ", "
               << (int)load_target_flag << ", "
               << (int)load_variables_flag << ");" << endl;
    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
void actionGetURL2(char* stack, u32* sp,
                   u8 send_vars_method,
                   u8 load_target_flag,
                   u8 load_variables_flag);
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGetURL2(char* stack, u32* sp,
                   u8 send_vars_method,
                   u8 load_target_flag,
                   u8 load_variables_flag)
{
    // Pop target from stack
    ActionVar target_var;
    convertString(stack, sp);
    popVar(stack, sp, &target_var);
    const char* target = (target_var.type == ACTION_STACK_VALUE_STRING) ?
                         (const char*)target_var.value.u64 : "";

    // Pop URL from stack
    ActionVar url_var;
    convertString(stack, sp);
    popVar(stack, sp, &url_var);
    const char* url = (url_var.type == ACTION_STACK_VALUE_STRING) ?
                      (const char*)url_var.value.u64 : "";

    // Determine HTTP method
    const char* method = NULL;
    if (send_vars_method == 1) method = "GET";
    else if (send_vars_method == 2) method = "POST";

    // Determine target type
    bool is_sprite = (load_target_flag == 1);
    bool load_vars = (load_variables_flag == 1);

    if (is_sprite) {
        // Load into sprite/movieclip
        if (load_vars) {
            // Load variables into sprite
            loadVariablesIntoTarget(url, target, method);
        } else {
            // Load SWF into sprite
            loadSWFIntoTarget(url, target);
        }
    } else {
        // Load into browser window
        if (load_vars) {
            // Load variables into timeline
            loadVariablesIntoWindow(url, target, method);
        } else {
            // Open URL in browser
            openURLInBrowser(url, target, method);
        }
    }
}
```

### Helper Functions

```c
void openURLInBrowser(const char* url, const char* target, const char* method)
{
    printf("// OpenURL: %s (target: %s, method: %s)\n",
           url, target, method ? method : "NONE");

    // TODO: Implement browser integration
    // Platform-specific browser launch
}

void loadSWFIntoTarget(const char* url, const char* target)
{
    printf("// LoadMovie: %s -> %s\n", url, target);

    // TODO: Implement SWF loading
    // - Download SWF file
    // - Parse and load into target sprite
}

void loadVariablesIntoTarget(const char* url, const char* target, const char* method)
{
    printf("// LoadVariables: %s -> %s (method: %s)\n",
           url, target, method ? method : "GET");

    // TODO: Implement variable loading
    // - Make HTTP request
    // - Parse response (var1=value1&var2=value2)
    // - Set variables in target
}

void loadVariablesIntoWindow(const char* url, const char* target, const char* method)
{
    printf("// LoadVariables: %s (method: %s)\n",
           url, method ? method : "GET");

    // TODO: Similar to loadVariablesIntoTarget but for timeline
}
```

### Variable Encoding (for POST/GET)

```c
const char* encodeMovieVariables(MovieClip* mc)
{
    // Encode movie clip variables as x-www-form-urlencoded
    // Format: var1=value1&var2=value2&var3=value3
    // TODO: Implement URL encoding
    return "name=John&age=30";  // Placeholder
}
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionGetURL2(char* stack, u32* sp,
                   u8 send_vars_method,
                   u8 load_target_flag,
                   u8 load_variables_flag)
{
    // Pop target
    ActionVar target_var;
    popVar(stack, sp, &target_var);

    // Pop URL
    ActionVar url_var;
    popVar(stack, sp, &url_var);

    // Simplified: just log the request
    const char* method_str = "NONE";
    if (send_vars_method == 1) method_str = "GET";
    else if (send_vars_method == 2) method_str = "POST";

    printf("// GetURL2: method=%s, loadTarget=%d, loadVars=%d\n",
           method_str, load_target_flag, load_variables_flag);

    // TODO: Implement actual URL loading
}
```

### Similar Opcodes

Reference these opcodes:
- `actionGetURL` (0x83) - Static version with embedded URL/target
- `actionLoadVariables` - Specific for loading variables
- `actionLoadMovie` - Specific for loading movies

### Edge Cases to Handle

- Empty URL or target
- Invalid HTTP method
- Network errors (unreachable URL)
- Security restrictions (cross-domain)
- Variable encoding errors
- Invalid target sprite path
- Malformed variable response

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/get_url2_swf_4/README.md` - Test description and expected output
- Document HTTP methods and flags
- Explain variable encoding format
- Document security considerations

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Flags byte correctly parsed
- [ ] URL and target popped from stack correctly
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] HTTP method handling works
- [ ] LoadTarget and LoadVariables flags respected
- [ ] Edge cases handled gracefully
- [ ] Documentation created

## Important Notes

**Difference from GetURL (0x83)**:
- GetURL (0x83): URL and target embedded in action record (static)
- GetURL2 (0x9A): URL and target from stack (dynamic), supports HTTP methods

**Flash Version**: Available in SWF 4+

**ActionScript Equivalents**:
```actionscript
// Load URL in browser
getURL(url, target);

// Load variables
loadVariables(url, target, method);  // method: "GET" or "POST"

// Load movie
loadMovie(url, target);
loadMovieNum(url, level);
```

**HTTP Methods**:
- 0 (None): No variables sent, simple URL request
- 1 (GET): Variables sent as URL query string (?var1=value1&var2=value2)
- 2 (POST): Variables sent in HTTP POST body

**Variable Format**: x-www-form-urlencoded
```
name=John+Doe&age=30&city=New+York
```

**LoadTargetFlag**:
- 0: Target is browser window/frame (_blank, _self, etc.)
- 1: Target is Flash sprite path (/clip, _root.clip, etc.)

**LoadVariablesFlag**:
- 0: Load content (HTML page, SWF file)
- 1: Load variables (parse as var1=value1&var2=value2)

**Security**: Same security restrictions as GetURL:
- Cross-domain restrictions
- JavaScript execution risks
- File:// access restrictions

**Variable Loading Process**:
1. Make HTTP request to URL
2. Receive response (should be x-www-form-urlencoded)
3. Parse response: `var1=value1&var2=value2&...`
4. Set each variable in target scope

**Movie Loading Process**:
1. Download SWF file from URL
2. Parse SWF file
3. Create MovieClip instance
4. Load into target sprite or level
5. Start playback

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add URL and target popping
- Test different flag combinations
- Add HTTP method support (mock)
- Add variable loading (parse format)
- Add SWF loading (complex)
- Test edge cases

**Coordination**: This opcode relates to:
- HTTP client infrastructure
- SWF parser and loader
- Variable storage system
- Browser integration
- Security sandbox
- MovieClip level management

**Flags Byte Decoding**:
```
Bit 7-6: SendVarsMethod (00=None, 01=GET, 10=POST, 11=Reserved)
Bit 5-2: Reserved (0000)
Bit 1:   LoadTargetFlag (0=window, 1=sprite)
Bit 0:   LoadVariablesFlag (0=content, 1=variables)
```

**Common Usage Patterns**:
```actionscript
// Open page in new window
getURL("page.html", "_blank");

// Load variables from server
loadVariables("data.txt", _root, "GET");

// POST form data
loadVariables("submit.php", _root, "POST");

// Load external SWF
loadMovie("external.swf", _root.container);
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
