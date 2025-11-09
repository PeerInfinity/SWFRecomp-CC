# AS2 Opcode Implementation Task: ActionGetURL

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionGetURL**

## Opcode Specification

**Opcode Name**: ActionGetURL
**Hex Value**: 0x83
**Category**: Movie Control / External Communication
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Instructs Flash Player to load a URL. Can load HTML pages, images, or SWF files into browser frames or Flash levels.

**Operation**: Load URL specified in action record into target window/level.

**Expected Behavior** (from SWF Spec 19):
- Gets the URL specified by UrlString
- URL can be any type: HTML file, image, or another SWF file
- If playing in browser, URL is displayed in the frame specified by TargetString
- Special targets "_level0" and "_level1" load SWF files into Flash Player levels 0 and 1
- Action record contains: ActionCode = 0x83, UrlString (STRING), TargetString (STRING)

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x83
Length         UI16    Variable
UrlString      STRING  Target URL string
TargetString   STRING  Target window/level
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GET_URL = 0x83` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse UrlString and TargetString)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with getURL calls
6. **Setup Test Directory** - Create `SWFRecomp/tests/get_url_swf_3/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Load external page
```actionscript
getURL("https://www.example.com", "_blank");
trace("URL load requested");
```
Expected output: `URL load requested`
(And URL load should be initiated)

### Test Case 2: Load into named frame
```actionscript
getURL("page.html", "content");
trace("Loading into frame");
```
Expected output: `Loading into frame`

### Test Case 3: Load SWF into level
```actionscript
getURL("movie.swf", "_level1");
trace("Loading SWF into level 1");
```
Expected output: `Loading SWF into level 1`

### Test Case 4: JavaScript call
```actionscript
getURL("javascript:alert('Hello')");
trace("JavaScript executed");
```
Expected output: `JavaScript executed`

### Test Case 5: Current window
```actionscript
getURL("https://www.example.com", "_self");
trace("Loading in current window");
```
Expected output: `Loading in current window`

## Implementation Hints

**Pattern**: This is an external communication operation that interacts with the browser or loads content.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GET_URL:
{
    // Read UrlString (null-terminated)
    std::string url_string;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        url_string += ch;
    }

    // Read TargetString (null-terminated)
    std::string target_string;
    while (in.read(&ch, 1) && ch != '\0') {
        target_string += ch;
    }

    out_script << "\t" << "// GetURL: \"" << url_string
               << "\" -> \"" << target_string << "\"" << endl
               << "\t" << "actionGetURL(stack, sp, "
               << "\"" << url_string << "\", "
               << "\"" << target_string << "\");" << endl;
    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
void actionGetURL(char* stack, u32* sp, const char* url, const char* target);
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGetURL(char* stack, u32* sp, const char* url, const char* target)
{
    // Parse target type
    bool is_level = (strncmp(target, "_level", 6) == 0);
    bool is_blank = (strcmp(target, "_blank") == 0);
    bool is_self = (strcmp(target, "_self") == 0);
    bool is_parent = (strcmp(target, "_parent") == 0);
    bool is_top = (strcmp(target, "_top") == 0);

    if (is_level) {
        // Loading SWF into Flash level
        int level = atoi(target + 6);  // Extract level number
        loadSWFIntoLevel(url, level);
    }
    else if (is_blank || is_self || is_parent || is_top) {
        // Browser window target
        openURLInBrowser(url, target);
    }
    else if (strlen(target) > 0) {
        // Named frame target
        openURLInFrame(url, target);
    }
    else {
        // Default: open in current window
        openURLInBrowser(url, "_self");
    }
}
```

### Helper Functions

```c
void loadSWFIntoLevel(const char* url, int level)
{
    // Load SWF file into specified level
    printf("// LoadSWF: %s -> level %d\n", url, level);

    // TODO: Implement SWF loading
    // - Download SWF file
    // - Parse SWF
    // - Create MovieClip for level
    // - Execute SWF in level context
}

void openURLInBrowser(const char* url, const char* target)
{
    // Open URL in browser window
    printf("// OpenURL: %s (target: %s)\n", url, target);

    // TODO: Implement browser integration
    // Platform-specific:
    // - On web: window.open(url, target)
    // - On desktop: system browser or embedded browser
}

void openURLInFrame(const char* url, const char* frame)
{
    // Open URL in named frame
    printf("// OpenURL: %s (frame: %s)\n", url, frame);

    // TODO: Implement frame targeting
    // Requires browser frame API
}
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionGetURL(char* stack, u32* sp, const char* url, const char* target)
{
    // Simplified: just log the URL request
    printf("// GetURL: %s -> %s\n",
           url ? url : "(null)",
           target ? target : "(null)");

    // TODO: Implement actual URL loading
    // This requires:
    // - Browser integration or HTTP client
    // - SWF loader (for _level targets)
    // - Frame/window management
}
```

### Similar Opcodes

Reference these opcodes:
- `actionGetURL2` (0x9A) - Stack-based version with method support (GET/POST)
- `actionLoadMovie` - Similar functionality for loading movies
- `actionLoadVariables` - Load variables from URL

### Special Targets

```c
// Standard browser targets
_self    // Current window/frame
_blank   // New window
_parent  // Parent frame
_top     // Top-level frame

// Flash-specific targets
_level0  // Main timeline level
_level1  // Level 1
_level2  // Level 2, etc.

// Named targets
"frame_name"     // Named frame
"window_name"    // Named window
```

### Edge Cases to Handle

- Empty URL string
- Empty target string
- Invalid URL format
- Relative URLs (need base URL resolution)
- JavaScript URLs (javascript:...)
- Invalid level numbers
- Security restrictions (cross-domain)
- Missing protocol (http://, https://, etc.)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/get_url_swf_3/README.md` - Test description and expected output
- Document target string syntax
- Explain security considerations

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] URL and target parameters correctly parsed from action record
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] URL loading logged/implemented
- [ ] Special targets handled correctly
- [ ] Edge cases handled gracefully
- [ ] Documentation created

## Important Notes

**Security**: GetURL can be a security risk:
- Cross-domain requests may be restricted
- JavaScript URLs can execute arbitrary code
- File:// URLs may access local filesystem
- Consider implementing security sandbox

**Difference from GetURL2 (0x9A)**:
- GetURL (0x83): URL and target embedded in action record
- GetURL2 (0x9A): URL and target from stack, supports HTTP methods (GET/POST)

**Flash Version**: Available in SWF 3+

**ActionScript Equivalents**:
```actionscript
getURL("https://example.com", "_blank");
loadMovie("movie.swf", "_level1");
loadMovieNum("movie.swf", 1);
```

**Browser Integration**: For full implementation:
- Web environment: Use JavaScript bridge or browser API
- Desktop environment: Launch system browser
- Embedded environment: Use HTTP client or embedded browser

**Level Loading**: Loading SWF into _level requires:
- HTTP client to download SWF
- SWF parser
- MovieClip instance for the level
- Integration with display hierarchy

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add URL parsing and validation
- Test different target types
- Add browser integration (platform-specific)
- Add SWF loading (complex)
- Test security restrictions

**Coordination**: This opcode relates to:
- Browser/platform integration
- SWF loading infrastructure
- HTTP client
- Security sandbox
- MovieClip level management

**Platform Considerations**:
- Web: Use browser APIs (window.open, etc.)
- Desktop: Launch system browser or use WebView
- Embedded: Implement HTTP client
- Game console: May not support external URLs

**Action Record Parsing**: This opcode has two null-terminated strings:
```cpp
// In action.cpp translation:
case SWF_ACTION_GET_URL:
{
    std::string url_string;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        url_string += ch;
    }
    std::string target_string;
    while (in.read(&ch, 1) && ch != '\0') {
        target_string += ch;
    }
    // Use url_string and target_string...
}
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
