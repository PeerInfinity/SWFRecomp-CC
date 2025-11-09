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

This test includes 10 comprehensive test cases covering all major scenarios and edge cases:

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

### Test 6: Empty URL
- **URL**: "" (empty string)
- **Target**: _self
- **Flags**: 0x00 (no method, window, load content)
- **Expected Output**: "Empty URL test"
- **Tests**: Edge case handling of empty URL

### Test 7: Empty Target
- **URL**: test.html
- **Target**: "" (empty string)
- **Flags**: 0x00 (no method, window, load content)
- **Expected Output**: "Empty target test"
- **Tests**: Edge case handling of empty target (current window)

### Test 8: Sprite target with GET
- **URL**: data.txt
- **Target**: _root.myClip
- **Flags**: 0x43 (GET method, sprite, load variables)
- **Expected Output**: "Sprite GET test"
- **Tests**: Loading variables into sprite with GET method

### Test 9: Sprite target with POST
- **URL**: upload.php
- **Target**: /level0/clip
- **Flags**: 0x83 (POST method, sprite, load variables)
- **Expected Output**: "Sprite POST test"
- **Tests**: Loading variables into sprite with POST method

### Test 10: Multiple concatenations
- **URL**: Concatenated from "https://" + "api.example.com" + "/v1/data"
- **Target**: _blank
- **Flags**: 0x00 (no method, window, load content)
- **Expected Output**: "Multi-concat test"
- **Tests**: STR_LIST with 3+ concatenated strings

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

All 10 test cases pass successfully:

```
[PASS] test_1_url_new_window
[PASS] test_2_get_variables
[PASS] test_3_post_request
[PASS] test_4_load_movie_sprite
[PASS] test_5_dynamic_url
[PASS] test_6_empty_url
[PASS] test_7_empty_target
[PASS] test_8_sprite_get
[PASS] test_9_sprite_post
[PASS] test_10_multi_concat
```

## Implementation Status

### ✅ What's Implemented

- **Opcode parsing**: Correctly reads and decodes the GetURL2 opcode (0x9A)
- **Flag byte parsing**: All flags correctly parsed
  - SendVarsMethod (bits 7-6): 0=None, 1=GET, 2=POST
  - LoadTargetFlag (bit 1): 0=window, 1=sprite
  - LoadVariablesFlag (bit 0): 0=content, 1=variables
- **Stack operations**: Correctly pops URL and target from stack
- **String handling**: Handles both regular strings and STR_LIST (concatenated strings)
- **Edge cases**: Empty strings, long URLs, all flag combinations
- **Logging**: Debug output showing intended operations

### ❌ What's NOT Implemented (Missing Features)

These features are documented in `test_info.json` under `missing_features`:

1. **HTTP client functionality** - No actual GET/POST requests are made
2. **Variable encoding** - Movie clip variables are not encoded as x-www-form-urlencoded
3. **Variable parsing** - HTTP responses are not parsed
4. **Variable setting** - Variables from responses are not set in target scope
5. **SWF file loading** - External SWF files are not actually downloaded or loaded
6. **MovieClip/sprite management** - Sprite paths are not resolved, no actual sprite loading
7. **Browser integration** - URLs are not opened in actual browser windows
8. **Security sandbox** - No cross-domain restrictions enforced

The current implementation correctly handles all bytecode-level operations (parsing, stack manipulation, flag interpretation) but does not implement the actual external communication functionality. This is expected for NO_GRAPHICS mode and would require significant infrastructure (HTTP client, SWF parser, browser integration) to fully implement.

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
