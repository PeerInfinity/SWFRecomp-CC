# ActionGetURL2 (0x9A) Test

## Overview

This test validates the implementation of the ActionGetURL2 opcode (0x9A), which provides stack-based URL loading with HTTP method support.

## Opcode Details

- **Opcode**: 0x9A
- **Name**: ActionGetURL2
- **Category**: Movie Control / External Communication
- **SWF Version**: 4+
- **Complexity**: COMPLEX

## Description

ActionGetURL2 is the stack-based version of ActionGetURL (0x83). It pops a URL and target from the stack and supports HTTP request methods (GET, POST) for loading variables or content.

## Flags Byte Structure

```
Bit 7-6: SendVarsMethod
  00 = None (no variables sent)
  01 = GET (variables in query string)
  10 = POST (variables in request body)
  11 = Reserved

Bit 5-2: Reserved (0000)

Bit 1: LoadTargetFlag
  0 = Browser window/frame (_blank, _self, etc.)
  1 = Sprite path (/clip, _root.clip, etc.)

Bit 0: LoadVariablesFlag
  0 = Load content (HTML page, SWF file)
  1 = Load variables (parse as var1=value1&var2=value2)
```

## Stack Operations

```
Before: [... url, target]
After:  [... ]
```

The opcode pops two strings from the stack:
1. First pop: target (window name or sprite path)
2. Second pop: URL

## Test Cases

This test includes 5 comprehensive test cases:

### Test 1: Load URL in new window (no method)
- **URL**: https://www.example.com
- **Target**: _blank
- **Flags**: 0x00 (no method, window, load content)
- **Expected Output**: "URL load requested"
- **ActionScript Equivalent**: `getURL(url, target);`

### Test 2: GET request with variables
- **URL**: script.php
- **Target**: _self
- **Flags**: 0x41 (GET method, window, load variables)
- **Expected Output**: "Loading variables"
- **ActionScript Equivalent**: `loadVariables(url, target, "GET");`

### Test 3: POST request
- **URL**: submit.php
- **Target**: _root
- **Flags**: 0x81 (POST method, window, load variables)
- **Expected Output**: "Posting data"
- **ActionScript Equivalent**: `loadVariables(url, target, "POST");`

### Test 4: Load SWF into sprite
- **URL**: movie.swf
- **Target**: /clip
- **Flags**: 0x02 (no method, sprite, load content)
- **Expected Output**: "Loading movie"
- **ActionScript Equivalent**: `loadMovie(url, target);`

### Test 5: Dynamic URL from expression
- **URL**: Concatenated from "https://example.com/" + "page.html"
- **Target**: _blank
- **Flags**: 0x00 (no method, window, load content)
- **Expected Output**: "Opening page"
- **ActionScript Equivalent**: `getURL(base + page, target);`

## Implementation Details

### Runtime Behavior

The current implementation logs the operation to demonstrate correct flag parsing and parameter handling:

- **Browser window operations**: Prints OpenURL message
- **Variable loading operations**: Prints LoadVariables message with HTTP method
- **Movie loading operations**: Prints LoadMovie message with target sprite

Full implementation would require:
- HTTP client for GET/POST requests
- Variable parsing (x-www-form-urlencoded format)
- SWF file loading and parsing
- Browser integration for opening URLs
- Security sandbox enforcement

### Files Generated

When the test runs, SWFRecomp generates:
- `RecompiledScripts/script_0.c` - Translated ActionScript with GetURL2 calls
- `RecompiledTags/tagMain.c` - Frame execution logic

The generated C code includes calls to:
```c
actionGetURL2(stack, sp, send_vars_method, load_target_flag, load_variables_flag);
```

## Test Results

All 5 test cases pass successfully:

```
[PASS] test_1_url_new_window
[PASS] test_2_get_variables
[PASS] test_3_post_request
[PASS] test_4_load_movie_sprite
[PASS] test_5_dynamic_url
```

## Building and Running

### Build the test:
```bash
cd SWFRecomp
./scripts/build_test.sh get_url2_swf_4 native
```

### Run the test:
```bash
./tests/get_url2_swf_4/build/native/get_url2_swf_4
```

### Validate the test:
```bash
cd tests
./all_tests.sh get_url2_swf_4
```

## Future Enhancements

To make this a fully functional implementation:

1. **HTTP Client Integration**
   - Implement GET/POST request handling
   - Variable encoding (x-www-form-urlencoded)
   - Response parsing

2. **SWF Loading**
   - Download and parse SWF files
   - Create MovieClip instances
   - Load into target sprites

3. **Browser Integration**
   - Platform-specific URL opening
   - Window/frame management

4. **Security**
   - Cross-domain restrictions
   - JavaScript execution prevention
   - File:// access controls

## References

- SWF File Format Specification v19
- ActionScript 2.0 Language Reference
- SWFRecompDocs/prompts/pending/opcode-geturl2-0x9a.md
