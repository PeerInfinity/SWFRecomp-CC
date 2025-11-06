# Branch Merge History

This document tracks all branches created by Claude Code web interface and their merge status.

## Merged Branches

### 1. `claude/explore-repository-files-011CUq8amdz5YkRVreuCxPJ9`
**Status:** ✅ Merged
**Commits:** 5 commits
**Description:** Initial exploration and experiments for parallel opcode implementation
- Added parallel opcode implementation experiments plan
- Completed Experiment #1: Hello World Smoke Test
- Fixed build_test.sh to use NO_GRAPHICS mode for native builds
- Updated parallel-opcode-implementation-guide with validated build process
- Created experiment documentation framework

**Key Changes:**
- New: `SWFRecompDocs/parallel-opcode-experiments.md` (403 lines)
- New: `SWFRecompDocs/status/experiment-01-smoke-test-results.md` (315 lines)
- New: `SWFRecomp/tests/trace_swf_4/create_test_swf.py`
- Updated: `parallel-opcode-implementation-guide.md`
- Updated: `build_test.sh` with NO_GRAPHICS mode

### 2. `claude/continue-parallel-opcode-work-011CUqCEHZRwLHASQrVNhSyC`
**Status:** ✅ Merged
**Commits:** 2 commits
**Description:** Experiment #2 - Implemented the Modulo opcode (0x3F)
- Complete implementation in both SWFModernRuntime and SWFRecomp
- Full test suite and documentation

**Key Changes:**
- New: Modulo opcode (0x3F) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/modulo_swf_4/` test suite
- New: `SWFRecompDocs/status/experiment-02-minimal-opcode-results.md` (621 lines)
- New: `SWFRecompDocs/reference/wasm-build-process.md`
- Updated: Implementation guide and experiment documentation

### 3. `claude/continue-parallel-opcode-work-011CUqHGXn6TPTXStpMecyV4`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Experiment #4 - Reference Counting Proof of Concept
- Implemented thread-safe reference counting system for object management
- Critical foundation for parallel opcode execution

**Key Changes:**
- New: `SWFModernRuntime/include/actionmodern/object.h` (81 lines)
- New: `SWFModernRuntime/src/actionmodern/object.c` (342 lines)
- New: Complete test suite in `tests/refcount_test/` (293 lines of tests)
- New: `SWFRecompDocs/status/experiment-04-refcount-poc-results.md` (644 lines)
- Updated: `stackvalue.h` and experiment documentation

### 4. `claude/continue-parallel-opcode-work-011CUqJFWtbpfd9FcjpY5rWC`
**Status:** ✅ Merged
**Commits:** 5 commits
**Description:** Experiment #5 - Parallel Merge Test
- Validated parallel development workflow
- Implemented two opcodes on separate branches and successfully merged
- Demonstrated conflict resolution process

**Key Changes:**
- New: Increment opcode (0x50) implementation (Branch A)
- New: Decrement opcode (0x51) implementation (Branch B)
- New: Test suites for both opcodes
- New: `SWFRecompDocs/status/experiment-05-parallel-merge-results.md` (612 lines)
- Resolved 4 merge conflicts successfully

### 5. Original SWFRecomp commit (44e4ab0)
**Status:** ✅ Merged manually
**Source:** `https://github.com/PeerInfinity/SWFRecomp` wasm-support branch
**Description:** Build process improvements and test configurations
- Unpushed commit that was created before repository combination

**Key Changes:**
- New: `scripts/build_all_native.sh`, `add_configs_to_all_tests.sh`, `generate_examples_index.sh`
- Updated: `build_all_examples.sh`, `build_test.sh`, `deploy_example.sh`
- New: `config.toml` files for all 53 existing test directories
- New: `scripts/excluded_tests.conf`
- Updated: `wasm_wrappers/main.c`
- Conflict resolution: Changed -D_GNU_SOURCE to -D_POSIX_C_SOURCE=199309L

### 6. `claude/continue-parallel-opcode-work-011CUqPV4sPj13z8GfNRgG2v`
**Status:** ✅ Merged
**Commits:** 3 commits
**Description:** Opcode categorization and implementation prompt system
- Enhanced build script with auto-generation of test.swf files
- Completed all validation experiments and declared GREEN LIGHT status
- Created comprehensive opcode categorization (60+ opcodes)
- Built reusable implementation prompt templates

**Key Changes:**
- Updated: `build_test.sh` with auto-detection of SWF generation scripts
- New: `SWFRecompDocs/opcode-categorization.md` (369 lines) - Complete AS2 opcode catalog
- Updated: `parallel-opcode-experiments.md` - All experiments marked COMPLETE, 5.5h total validation
- Updated: `parallel-opcode-implementation-guide.md` - Added auto-generation documentation
- New: `SWFRecompDocs/prompts/` directory with implementation templates:
  - `README.md` (156 lines) - Prompt usage guide
  - `opcode-greater-0x48.md` (187 lines) - Comparison operation template
  - `opcode-bit-and-0x60.md` (197 lines) - Bitwise operation template
  - `opcode-to-integer-0x18.md` (212 lines) - Type conversion template

**Opcode Categorization:**
- Batch 1 (Simple): 13 opcodes prioritized, 15-25h estimated (1-2 days with 10+ parallel agents)
- Batch 2 (Medium): 14 opcodes (string ops, stack ops, utilities)
- Batch 3 (Complex): 25+ opcodes (objects, functions, control flow)

**Status:** Ready for production parallel implementation

### 7. `claude/opcode-bit-and-0x60-011CUqSTKKr3twXcRVWnFhfN`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented BIT_AND opcode (0x60) - Bitwise AND operation
- Complete implementation in both SWFModernRuntime and SWFRecomp
- Full test suite with comprehensive README

**Key Changes:**
- New: BIT_AND opcode (0x60) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/bit_and_swf_4/` test suite
  - `README.md` (53 lines) - Test documentation
  - `create_test_swf.py` - SWF generation script
  - `config.toml` - Test configuration
- Total: 153 lines added

### 8. `claude/opcode-greater-0x48-011CUqSWXzS5k7R5QRW2VfrC`
**Status:** ✅ Merged (auto-resolved conflicts)
**Commits:** 2 commits
**Description:** Implemented GREATER opcode (0x48) - Comparison operation
- Complete implementation in both SWFModernRuntime and SWFRecomp
- Full test suite with detailed documentation
- Created IMPLEMENTATION_SUMMARY.md with implementation details

**Key Changes:**
- New: GREATER opcode (0x48) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/greater_swf_4/` test suite
  - `README.md` (76 lines) - Test documentation with edge cases
  - `create_test_swf.py` - SWF generation script
  - `config.toml` - Test configuration
- New: `IMPLEMENTATION_SUMMARY.md` (153 lines) - Comprehensive implementation notes
- Total: 344 lines added
- Auto-merged with BIT_AND changes

### 9. `claude/opcode-to-integer-0x18-011CUqSXyeJN7kwTdq2LSv4A`
**Status:** ✅ Merged (auto-resolved conflicts)
**Commits:** 2 commits
**Description:** Implemented TO_INTEGER opcode (0x18) - Type conversion operation
- Complete implementation in both SWFModernRuntime and SWFRecomp
- Comprehensive test suite with multiple test scripts
- Extensive README with edge case documentation

**Key Changes:**
- New: TO_INTEGER opcode (0x18) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/to_integer_swf_4/` test suite
  - `README.md` (135 lines) - Comprehensive documentation
  - `create_test_swf.py` - Basic SWF generation script
  - `create_comprehensive_test.py` - Extended test cases
  - `test_negative.py` - Negative number testing
  - `config.toml` - Test configuration
- Total: 363 lines added
- Auto-merged with previous opcode implementations

## Rejected Branches

### 1. `claude/explore-repository-files-011CUq1NmiHuuom4iGjkCrf1`
**Status:** ❌ Rejected
**Commits:** 1 commit
**Description:** Repository access notes (reverted flattening)
- This branch attempted to revert the submodule flattening
- Converted the repository back to using submodules
- Added a CC-note-root.md file
- Not compatible with our chosen architecture of flattened repositories

**Reason for Rejection:** Conflicts with the decision to flatten submodules into the main repository for easier Claude Code web interface access.

## Summary

**Total Branches Reviewed:** 44
**Merged:** 43
**Rejected:** 1

**Validation Phase Complete:** ✅ GREEN LIGHT
- Total validation time: 5.5 hours
- All 4 critical experiments completed successfully
- Ready for production parallel implementation

**Production Phase:** ✅ BATCH 1 COMPLETE! ✅ OBJECT/PROPERTY BATCH COMPLETE!
- 13 opcodes implemented from Batch 1 (100%)
- 10 additional opcodes for object/property operations (100%)
- Parallel implementation highly successful
- Complex merge conflicts successfully resolved

**Experiments Completed:**
- Experiment #1: Hello World Smoke Test ✅ (45 min)
- Experiment #2: Modulo opcode (0x3F) ✅ (45 min)
- Experiment #4: Reference Counting PoC ✅ (2 hours, 0 leaks)
- Experiment #5: Parallel Merge Test ✅ (2 min conflict resolution)

**Opcodes Implemented (Total: 37):**

*Validation Phase (3 opcodes):*
- 0x3F: Modulo
- 0x50: Increment
- 0x51: Decrement

*Production Phase - Batch 1 (13 opcodes - COMPLETE):*
- 0x18: TO_INTEGER (Type conversion)
- 0x48: LESS2 (Comparison - fixed from incorrect GREATER label)
- 0x4A: TO_NUMBER (Type conversion)
- 0x4B: TO_STRING (Type conversion)
- 0x60: BIT_AND (Bitwise)
- 0x61: BIT_OR (Bitwise)
- 0x62: BIT_XOR (Bitwise)
- 0x63: BIT_LSHIFT (Bitwise)
- 0x64: BIT_RSHIFT (Bitwise)
- 0x65: BIT_URSHIFT (Bitwise)
- 0x66: STRICT_EQUALS (Comparison)
- 0x67: GREATER (Comparison - moved to correct opcode value)
- 0x68: STRING_GREATER (String comparison)

*Production Phase - Additional Opcodes (13 opcodes):*
- 0x15: STRING_EXTRACT (String operation)
- 0x29: STRING_LESS (String comparison)
- 0x30: RANDOM_NUMBER (Utility - avmplus RNG)
- 0x31: CHAR_TO_ASCII (String conversion)
- 0x32: ASCII_TO_CHAR (String conversion)
- 0x33: MB_CHAR_TO_ASCII (Multibyte string - UTF-8)
- 0x35: MB_STRING_LENGTH (Multibyte string - UTF-8)
- 0x36: MB_ASCII_TO_CHAR (Multibyte string - UTF-8)
- 0x3C: TYPEOF (Type introspection)
- 0x3D: DUPLICATE (Stack operation)
- 0x45: TARGET_PATH (Movie clip - placeholder)
- 0x47: ADD2 (Type-aware arithmetic)
- 0x4C: STACK_SWAP (Stack operation)

*Production Phase - Object/Property Operations (10 opcodes - NEW):*
- 0x22: GET_PROPERTY (MovieClip property access)
- 0x23: SET_PROPERTY (MovieClip property mutation)
- 0x3E: RETURN (Function return)
- 0x40: NEW_OBJECT (Constructor call)
- 0x42: INIT_ARRAY (Array literal creation)
- 0x43: INIT_OBJECT (Object literal creation)
- 0x4E: GET_MEMBER (Object property access)
- 0x4F: SET_MEMBER (Object property mutation)
- 0x87: STORE_REGISTER (Register storage)
- 0x9E: CALL (Function call - placeholder)

**Infrastructure Added:**
- Reference counting system for memory management
- Comprehensive test framework with auto-generation
- Build process improvements (auto-detect SWF generation scripts)
- Documentation system for experiments
- Opcode categorization (60+ opcodes in 3 batches)
- Implementation prompt templates (3 examples covering different categories)

**Batch 1 Progress:**
- Target: 13 simple opcodes
- Completed: 13 opcodes (100% complete!)
- Status: Parallel implementation highly successful

### 10. `claude/opcode-bit-or-0x61-011CUqVjXPv9HusHiVtc6TGw`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented BIT_OR opcode (0x61) - Bitwise OR operation

**Key Changes:**
- New: BIT_OR opcode (0x61) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/bit_or_swf_4/` test suite with README, config, and test generation script
- Total: 238 lines added

### 11. `claude/opcode-bit-xor-0x62-011CUqVkkQnMQwzLk76tgFdA`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented BIT_XOR opcode (0x62) - Bitwise XOR operation

**Key Changes:**
- New: BIT_XOR opcode (0x62) implementation in action.c and action.cpp
- New: `SWFRecomp/tests/bit_xor_swf_4/` test suite
- Resolved merge conflicts with BIT_OR branch

### 12. `claude/opcode-bit-lshift-0x63-011CUqVnDyW9hL8bDRoCyrSZ`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented BIT_LSHIFT opcode (0x63) - Bitwise left shift operation

**Key Changes:**
- New: BIT_LSHIFT opcode (0x63) implementation with 5-bit mask for shift count
- New: `SWFRecomp/tests/bit_lshift_swf_4/` test suite
- Resolved merge conflicts with previous bitwise operations

### 13. `claude/opcode-bit-rshift-0x64-011CUqVp4jS5TmGv6wrUvggt`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented BIT_RSHIFT opcode (0x64) - Arithmetic right shift operation

**Key Changes:**
- New: BIT_RSHIFT opcode (0x64) with sign-extending arithmetic shift
- New: `SWFRecomp/tests/bit_rshift_swf_4/` test suite
- Uses signed integer for proper sign extension

### 14. `claude/opcode-bit-urshift-0x65-011CUqVqFVcxjU7FyuaVQmaJ`
**Status:** ✅ Merged (resolved complex nested conflicts)
**Commits:** 1 commit
**Description:** Implemented BIT_URSHIFT opcode (0x65) - Logical (unsigned) right shift operation

**Key Changes:**
- New: BIT_URSHIFT opcode (0x65) with zero-fill logical shift
- Uses unsigned integer for proper zero-fill behavior
- New: `SWFRecomp/tests/bit_urshift_swf_4/` test suite
- Resolved complex nested merge conflicts in action.c

### 15. `claude/opcode-strict-equals-0x66-011CUqVg8PjXUUbRMxgc4YVB`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented STRICT_EQUALS opcode (0x66) - Type-strict equality comparison

**Key Changes:**
- New: STRICT_EQUALS opcode (0x66) with type checking before value comparison
- Handles F32, F64, STRING, STR_LIST, and OBJECT types
- NULL-safe string comparison
- New: `SWFRecomp/tests/strict_equals_swf_4/` test suite

### 16. `claude/opcode-less2-0x48-011CUqVhjEkp43uiNZP73mVd`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Fixed opcode naming - GREATER (0x48) renamed to LESS2 (0x48)

**Key Changes:**
- Corrected: Renamed SWF_ACTION_GREATER from 0x48 to LESS2 (ActionLess2)
- Updated: `greater_swf_4/README.md` to document the correction
- New: `SWFRecomp/tests/less2_swf_4/` test suite for the correct opcode
- This fixed a naming error where 0x48 was incorrectly labeled as GREATER

### 17. `claude/opcode-greater-0x67-011CUqVaJqcbH4RtE6aUYjdr`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Moved GREATER opcode to correct value 0x67

**Key Changes:**
- New: SWF_ACTION_GREATER = 0x67 (correct opcode value per SWF spec)
- Updated: `greater_swf_4/README.md` and test files to use 0x67
- This completes the fix started by the LESS2 branch

### 18. `claude/opcode-to-number-0x4a-011CUqVrcGZ3S8hpgvoNmZFo`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented TO_NUMBER opcode (0x4A) - Type conversion to number

**Key Changes:**
- New: TO_NUMBER opcode (0x4A) using convertFloat for type conversion
- New: `SWFRecomp/tests/to_number_swf_4/` test suite
- Handles string parsing, boolean conversion, null/undefined → NaN

### 19. `claude/opcode-to-string-0x4b-011CUqVt3dKcYBkDFdbzzoiE`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented TO_STRING opcode (0x4B) - Type conversion to string

**Key Changes:**
- New: TO_STRING opcode (0x4B) using convertString with string buffer parameter
- New: `SWFRecomp/tests/to_string_swf_4/` test suite
- Uses %.15g format for float→string conversion

### 20. `claude/opcode-string-greater-0x68-011CUqVejVoGZ9nRiJM9nwVE`
**Status:** ✅ Merged (resolved conflicts, known runtime issue)
**Commits:** 1 commit
**Description:** Implemented STRING_GREATER opcode (0x68) - Lexicographic string comparison

**Key Changes:**
- New: STRING_GREATER opcode (0x68) for case-sensitive string comparison
- Uses strcmp() for lexicographic byte-by-byte comparison
- New: `SWFRecomp/tests/string_greater_swf_4/` test suite

**Known Issue:**
- Runtime segfaults when pushing multiple strings in sequence
- Not specific to STRING_GREATER implementation
- Underlying issue in SWFModernRuntime's string handling needs investigation

### 21. `claude/opcode-add2-0x47-011CUqjUFFXqojvHMPRuv3Bb`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented ADD2 opcode (0x47) - Type-aware addition operation

**Key Changes:**
- New: ADD2 opcode (0x47) implementation in action.c and action.cpp
- Handles both numeric addition and string concatenation
- New: `SWFRecomp/tests/add2_swf_5/` test suite
- Total: 326 lines added

### 22. `claude/opcode-ascii-to-char-011CUqjDTN85jHrPQw6TcwG6`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented ASCII_TO_CHAR opcode (0x32) - Converts ASCII code to character

**Key Changes:**
- New: ASCII_TO_CHAR opcode (0x32) implementation
- Converts numeric ASCII code to single-character string
- New: `SWFRecomp/tests/ascii_to_char_swf_4/` test suite
- Total: 209 lines added

### 23. `claude/opcode-char-to-ascii-011CUqj9iRdh36YUoc2qi2cE`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented CHAR_TO_ASCII opcode (0x31) - Converts character to ASCII code

**Key Changes:**
- New: CHAR_TO_ASCII opcode (0x31) implementation
- Returns ASCII/Unicode code of first character
- New: `SWFRecomp/tests/char_to_ascii_swf_4/` test suite
- Resolved merge conflicts with ASCII_TO_CHAR branch

### 24. `claude/opcode-duplicate-0x3d-011CUqjMorPan5wAhTnAR7Xy`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented DUPLICATE opcode (0x3D) - Duplicates top stack value

**Key Changes:**
- New: DUPLICATE opcode (0x3D) implementation
- Handles both string and numeric types with shallow copy for strings
- New: `SWFRecomp/tests/duplicate_swf_4/` test suite
- Total: 165 lines added

### 25. `claude/opcode-mb-ascii-to-char-011CUqjGDDuJtLXjWDS2jnrB`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented MB_ASCII_TO_CHAR opcode (0x36) - Multi-byte ASCII to character (UTF-8)

**Key Changes:**
- New: MB_ASCII_TO_CHAR opcode (0x36) with full UTF-8 encoding support
- Handles 1-4 byte UTF-8 sequences (Unicode up to 0x10FFFF)
- New: `SWFRecomp/tests/mb_ascii_to_char_swf_4/` test suite
- Resolved merge conflicts in action files

### 26. `claude/opcode-mb-char-to-ascii-011CUqjErLGMw5t3U7fW8Ptx`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented MB_CHAR_TO_ASCII opcode (0x33) - Multi-byte character to ASCII (UTF-8)

**Key Changes:**
- New: MB_CHAR_TO_ASCII opcode (0x33) with full UTF-8 decoding support
- Decodes 1-4 byte UTF-8 sequences to Unicode codepoints
- New: `SWFRecomp/tests/mb_char_to_ascii_swf_4/` test suite
- Resolved merge conflicts with previous opcode implementations

### 27. `claude/opcode-mb-string-length-011CUqjHZGBt4RPFnmqHZUmK`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented MB_STRING_LENGTH opcode (0x35) - Multi-byte string length (UTF-8)

**Key Changes:**
- New: MB_STRING_LENGTH opcode (0x35) counting UTF-8 characters
- Properly handles multi-byte UTF-8 sequences (1-4 bytes)
- New: `SWFRecomp/tests/mb_string_length_swf_4/` test suite
- Resolved merge conflicts in C files

### 28. `claude/opcode-random-number-0x30-011CUqjQQSpPiu7TsdDaxd5P`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented RANDOM_NUMBER opcode (0x30) - Random number generation

**Key Changes:**
- New: RANDOM_NUMBER opcode (0x30) using avmplus-compatible RNG
- Implements Adobe's Flash Player RNG for deterministic speedrun behavior
- New: `SWFRecomp/tests/random_number_swf_4/` test suite
- Added complete avmplus RNG implementation to action.c
- Resolved merge conflicts

### 29. `claude/opcode-stack-swap-0x4c-011CUqjPCoZCMmajEqhdp9Wc`
**Status:** ✅ Merged
**Commits:** 1 commit
**Description:** Implemented STACK_SWAP opcode (0x4C) - Swaps top two stack values

**Key Changes:**
- New: STACK_SWAP opcode (0x4C) implementation
- Pops two values and pushes them back in reverse order
- New: `SWFRecomp/tests/stack_swap_swf_4/` test suite
- Total: 141 lines added

### 30. `claude/opcode-string-extract-0x15-011CUqjJxEarFz94kS6esXja`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented STRING_EXTRACT opcode (0x15) - Extracts substring

**Key Changes:**
- New: STRING_EXTRACT opcode (0x15) for substring extraction
- Takes string, index, and length from stack
- Handles out-of-bounds cases gracefully
- New: `SWFRecomp/tests/string_extract_swf_4/` test suite
- Resolved merge conflicts

### 31. `claude/opcode-string-less-0x29-011CUqjLBvt11NbE5qovg15L`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented STRING_LESS opcode (0x29) - Lexicographic string comparison

**Key Changes:**
- New: STRING_LESS opcode (0x29) using strcmp
- Performs case-sensitive lexicographic comparison
- New: `SWFRecomp/tests/string_less_swf_4/` test suite
- Resolved merge conflicts

### 32. `claude/opcode-target-path-0x45-011CUqjSvUtwuKs7YmLXRRcD`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented TARGET_PATH opcode (0x45) - Get target path (placeholder)

**Key Changes:**
- New: TARGET_PATH opcode (0x45) with simplified implementation
- Returns "_root" placeholder for Object types (MovieClip infrastructure not yet available)
- New: `SWFRecomp/tests/target_path_swf_5/` test suite
- Documented limitations in README
- Resolved merge conflicts

### 33. `claude/opcode-typeof-0x3c-011CUqjRkgkmLYw99RCTrX2N`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented TYPEOF opcode (0x3C) - Returns type of value as string

**Key Changes:**
- New: TYPEOF opcode (0x3C) implementation
- Returns "number", "string", "object", or "undefined"
- New: `SWFRecomp/tests/typeof_swf_4/` test suite
- Resolved complex merge conflicts with multiple existing opcodes

### 34. `claude/run-all-tests-011CUqoyGxjxwnG7eQcS1Cth`
**Status:** ✅ Merged (fast-forward)
**Commits:** 2 commits
**Description:** Added comprehensive test vectors for all 27 newly implemented opcodes

**Key Changes:**
- Updated: `SWFRecomp/tests/test_vecs.txt` with expected outputs for 27 new opcodes
- Includes test vectors for: modulo, increment, decrement, duplicate, less2, strict_equals, to_integer, to_number, to_string, ascii_to_char, char_to_ascii, bit_and, bit_or, bit_xor, bit_lshift, bit_rshift, bit_urshift, stack_swap, string_extract, string_less, string_greater, add2, typeof, mb_ascii_to_char, mb_char_to_ascii, mb_string_length, target_path
- Enables automated regression testing for all newly implemented opcodes
- Total: 28 lines added to test_vecs.txt

### 35. `claude/opcode-init-array-0x42-011CUqqkAxTY8viyYWbxeESe`
**Status:** ✅ Merged (fast-forward)
**Commits:** 1 commit
**Description:** Implemented INIT_ARRAY opcode (0x42) - Creates array from stack values

**Key Changes:**
- New: INIT_ARRAY opcode (0x42) implementation in action.c and action.cpp
- Pops count, then count elements from stack to create array
- Proper refcount management for array elements
- New: `SWFRecomp/tests/init_array_swf_4/` test suite
- Total: 275 lines added

### 36. `claude/opcode-init-object-0x43-011CUqqmNYk4A15HTAzbUq5v`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented INIT_OBJECT opcode (0x43) - Creates object with properties

**Key Changes:**
- New: INIT_OBJECT opcode (0x43) implementation in action.c and action.cpp
- Creates object from property name/value pairs on stack
- Full integration with object API and refcount management
- New: `SWFRecomp/tests/init_object_swf_4/` test suite
- Resolved merge conflicts with INIT_ARRAY in action.h, action.c, action.hpp, action.cpp

### 37. `claude/opcode-get-member-0x4e-011CUqqnqRJSNy4EshrhTBUY`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented GET_MEMBER opcode (0x4E) - Gets object property value

**Key Changes:**
- New: GET_MEMBER opcode (0x4E) implementation in action.c and action.cpp
- Supports object properties and string.length
- Added helper function pushUndefined()
- Proper handling of null objects and missing properties
- New: `SWFRecomp/tests/get_member_swf_4/` test suite
- Resolved merge conflicts in action.c

### 38. `claude/implement-opcode-set-member-011CUqqpFbcbnzZ8QFBxdF1E`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented SET_MEMBER opcode (0x4F) - Sets object property value

**Key Changes:**
- New: SET_MEMBER opcode (0x4F) implementation in action.c and action.cpp
- Handles string and numeric property names (for arrays)
- Proper integration with object API
- New: `SWFRecomp/tests/set_member_swf_4/` test suite
- Resolved merge conflicts preserving all existing implementations

### 39. `claude/implement-opcode-new-object-011CUqqtdjVWnbspsyb3PyNS`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented NEW_OBJECT opcode (0x40) - Creates object instance (constructor call)

**Key Changes:**
- New: NEW_OBJECT opcode (0x40) implementation in action.c and action.cpp
- Creates new object instance and calls constructor with arguments
- Proper argument passing and stack management
- New: `SWFRecomp/tests/new_object_swf_4/` test suite
- Resolved merge conflicts in action.h, action.c, action.hpp, action.cpp

### 40. `claude/opcode-get-property-0x22-011CUqqqTnsyJjtfQywgWLjs`
**Status:** ✅ Merged (clean merge)
**Commits:** 1 commit
**Description:** Implemented GET_PROPERTY opcode (0x22) - Gets MovieClip property by index

**Key Changes:**
- New: GET_PROPERTY opcode (0x22) implementation in action.c and action.cpp
- Supports MovieClip properties (_x, _y, _xscale, _yscale, _currentframe, etc.)
- Added MovieClip structure and property enumeration
- New: `SWFRecomp/tests/get_property_swf_4/` test suite
- Clean merge with no conflicts

### 41. `claude/implement-opcode-set-property-011CUqqrbs54vXgh5PYu8tPB`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented SET_PROPERTY opcode (0x23) - Sets MovieClip property by index

**Key Changes:**
- New: SET_PROPERTY opcode (0x23) implementation in action.c and action.cpp
- Supports setting MovieClip properties (_x, _y, _xscale, etc.)
- New: `SWFRecomp/tests/set_property_swf_4/` test suite
- Resolved merge conflicts, unified duplicate MovieClip definitions
- Added actionSetProperty function

### 42. `claude/opcode-return-0x3e-011CUqqvqpagz6dnfYaZnpQz`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented RETURN opcode (0x3E) - Returns value from function

**Key Changes:**
- New: RETURN opcode (0x3E) implementation in action.c and action.cpp
- Returns value from current function execution
- Proper stack management for function returns
- New: `SWFRecomp/tests/return_swf_4/` test suite
- Resolved merge conflicts in action.h

### 43. `claude/opcode-call-0x9e-011CUqqxAw4Cd4VdGoYqDDVq`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented CALL opcode (0x9E) - Calls function by name

**Key Changes:**
- New: CALL opcode (0x9E) implementation in action.c and action.cpp
- Placeholder implementation for function calls
- New: `SWFRecomp/tests/call_swf_4/` test suite
- Resolved merge conflicts, removed duplicate actionCall definition

### 44. `claude/opcode-store-register-0x87-011CUqqydram99y3sZsbqWkT`
**Status:** ✅ Merged (resolved conflicts)
**Commits:** 1 commit
**Description:** Implemented STORE_REGISTER opcode (0x87) - Stores value in register

**Key Changes:**
- New: STORE_REGISTER opcode (0x87) implementation in action.c and action.cpp
- Added register storage support (4 or 256 registers depending on SWF version)
- Added helper functions for register management
- New: `SWFRecomp/tests/store_register_swf_4/` test suite
- Resolved merge conflicts in action.h
