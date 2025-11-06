# AS2 Opcode Index - Planning Document

## Overview
Create a comprehensive index of all AS2 opcodes with the following information for each:
- Opcode hex value
- Opcode name(s) - multiple entries if different parts of code use different names
- Function names in action.h and action.hpp that process the opcode
- Test directory path (if exists)
- Documentation prompt file (if exists)
- Branch name where the opcode was implemented

## Data Sources

### 1. Opcode Hex Values and Names
**Primary Source**: Official SWF Specification
- Location: `SWFRecompDocs/specs/pdf/swf-spec-19.pdf` or `SWFRecompDocs/specs/swf-spec-19.txt`
- Contains the official ActionScript 2 opcode names and hex values
- This is the authoritative source for opcode definitions

**Secondary Sources** (for implementation-specific naming):
- `SWFRecomp/include/action/action.hpp` - Contains `SWFActionType` enum (e.g., `SWF_ACTION_ADD = 0x0A`)
- `SWFModernRuntime/include/actionmodern/action.h` - Function declarations (e.g., `actionAdd`)
- `SWFRecomp/src/action/action.cpp` - Switch case implementations

**Note**: Each naming convention gets its own entry in the index

### 2. Function Names in action.h
**Source**: `SWFModernRuntime/include/actionmodern/action.h`
- Function declarations like `void actionAdd(char* stack, u32* sp);`
- Lines 75-150 contain most opcode function declarations
- Naming pattern: `action<OpcodeName>` (camelCase)
- Some opcodes may not have dedicated functions yet

### 3. Function Names in action.hpp
**Source**: `SWFRecomp/include/action/action.hpp`
- Class: `SWFAction`
- Primary method: `void parseActions(Context& context, char*& action_buffer, ofstream& out_script);`
- This method contains a switch statement that handles all opcodes
- Location: `SWFRecomp/src/action/action.cpp` (implementation file)

**Note**: action.hpp doesn't have separate functions per opcode - it has a single parseActions method with a switch statement

### 4. Test Directory Paths
**Source**: File system search in `SWFRecomp/tests/`
- Pattern: `*_swf_*` directories
- Naming convention: `<opcode_name>_swf_<version>/`
- Examples:
  - `add2_swf_5/` for ADD2 (0x47)
  - `bit_and_swf_4/` for BIT_AND (0x60)
  - `ascii_to_char_swf_4/` for ASCII_TO_CHAR (0x32)

**Method to gather**:
```bash
ls -d SWFRecomp/tests/*_swf_*/
```

### 5. Documentation Prompt Files
**Source**: `SWFRecompDocs/prompts/`
- Active prompts in root directory: `opcode-<name>-0x<hex>.md`
- Completed prompts in: `SWFRecompDocs/prompts/completed/`
- Pattern: `opcode-<name>-0x<hex>.md`
- Examples:
  - `opcode-add2-0x47.md`
  - `opcode-bit-and-0x60.md`
  - `opcode-ascii-to-char-0x32.md`

**Method to gather**:
```bash
ls SWFRecompDocs/prompts/*.md
ls SWFRecompDocs/prompts/completed/*.md
```

### 6. Implementation Branch Names
**Source**: Multiple sources available

**Option A: repository-data.json** (Recommended)
- Already parsed and structured
- Contains branch names, commit hashes, and subjects
- Format: `"name": "origin/claude/opcode-<name>-<hex>-<id>"`
- Example: `"origin/claude/opcode-add2-0x47-011CUqjUFFXqojvHMPRuv3Bb"`
- Location: `CC/SWFRecomp-CC/repository-data.json`

**Option B: branch-merge-history.md**
- Human-readable documentation of merged branches
- Contains branch status, descriptions, and key changes
- Location: `CC/SWFRecomp-CC/branch-merge-history.md`
- Format: Markdown with branch names like `claude/opcode-<name>-<hex>-<id>`

**Option C: Git log search**
```bash
git log --all --oneline --grep="opcode\|0x"
```
- Most direct but requires parsing commit messages
- Can match commits to branches with additional git commands

**Recommendation**: Use repository-data.json as primary source, fall back to git log for missing entries

## Data Structure

### Proposed Format: JSON
```json
{
  "metadata": {
    "generated_date": "2025-11-06",
    "total_opcodes": 89,
    "implemented_opcodes": 56,
    "total_entries": 178
  },
  "entries": [
    {
      "hex": "0x0A",
      "name": "ActionAdd",
      "source": "SWF Specification v19",
      "type": "spec",
      "function_declaration": null,
      "function_implementation": null,
      "test_directories": [
        "SWFRecomp/tests/add_floats_swf_4",
        "SWFRecomp/tests/add_strings_swf_4",
        "SWFRecomp/tests/add_floats_imprecise_swf_4",
        "SWFRecomp/tests/add_strings_imprecise_swf_4"
      ],
      "documentation_prompt": null,
      "implementation_branch": null,
      "notes": "Official SWF specification name for ADD opcode"
    },
    {
      "hex": "0x0A",
      "name": "SWF_ACTION_ADD",
      "source": "action.hpp",
      "type": "enum",
      "function_declaration": null,
      "function_implementation": "parseActions (case SWF_ACTION_ADD, line 96)",
      "test_directories": [
        "SWFRecomp/tests/add_floats_swf_4",
        "SWFRecomp/tests/add_strings_swf_4",
        "SWFRecomp/tests/add_floats_imprecise_swf_4",
        "SWFRecomp/tests/add_strings_imprecise_swf_4"
      ],
      "documentation_prompt": null,
      "implementation_branch": null,
      "notes": "Basic arithmetic operation - part of initial implementation"
    },
    {
      "hex": "0x0A",
      "name": "actionAdd",
      "source": "action.h",
      "type": "function",
      "function_declaration": "void actionAdd(char* stack, u32* sp)",
      "function_implementation": "SWFModernRuntime/src/actionmodern/action.c",
      "test_directories": [
        "SWFRecomp/tests/add_floats_swf_4",
        "SWFRecomp/tests/add_strings_swf_4",
        "SWFRecomp/tests/add_floats_imprecise_swf_4",
        "SWFRecomp/tests/add_strings_imprecise_swf_4"
      ],
      "documentation_prompt": null,
      "implementation_branch": null,
      "notes": "Runtime function for ADD opcode"
    },
    {
      "hex": "0x47",
      "name": "SWF_ACTION_ADD2",
      "source": "action.hpp",
      "type": "enum",
      "function_declaration": null,
      "function_implementation": "parseActions (case SWF_ACTION_ADD2, line 419)",
      "test_directories": [
        "SWFRecomp/tests/add2_swf_5"
      ],
      "documentation_prompt": "SWFRecompDocs/prompts/completed/opcode-add2-0x47.md",
      "implementation_branch": "origin/claude/opcode-add2-0x47-011CUqjUFFXqojvHMPRuv3Bb",
      "notes": "Type-aware addition operator for SWF 5+"
    },
    {
      "hex": "0x47",
      "name": "actionAdd2",
      "source": "action.h",
      "type": "function",
      "function_declaration": "void actionAdd2(char* stack, u32* sp, char* str_buffer)",
      "function_implementation": "SWFModernRuntime/src/actionmodern/action.c",
      "test_directories": [
        "SWFRecomp/tests/add2_swf_5"
      ],
      "documentation_prompt": "SWFRecompDocs/prompts/completed/opcode-add2-0x47.md",
      "implementation_branch": "origin/claude/opcode-add2-0x47-011CUqjUFFXqojvHMPRuv3Bb",
      "notes": "Runtime function for ADD2 opcode"
    }
  ]
}
```

### Alternative Format: Markdown Table
For easier human reading and editing:

```markdown
| Hex  | Enum Name          | action.h Function | action.hpp Method | Test Directory | Doc Prompt | Branch | Notes |
|------|-------------------|-------------------|-------------------|----------------|------------|--------|-------|
| 0x0A | SWF_ACTION_ADD    | actionAdd         | parseActions      | add_floats_swf_4 | completed/opcode-add-0x0a.md | master | Basic arithmetic |
| 0x47 | SWF_ACTION_ADD2   | actionAdd2        | parseActions      | add2_swf_5     | completed/opcode-add2-0x47.md | claude/opcode-add2-... | Type-aware addition |
```

## Implementation Strategy

### Phase 1: Extract Base Opcode List
1. **Parse official SWF specification** to extract all AS2 opcode names and hex values
   - Source: `SWFRecompDocs/specs/swf-spec-19.txt` (easier to parse than PDF)
   - Pattern: Look for lines starting with "Action[A-Z]" followed by "ActionCode = 0x[HH]"
   - Example: "ActionAdd" with "ActionCode = 0x0A"
   - Create primary entries with official names (e.g., "ActionAdd")
2. Parse `SWFRecomp/include/action/action.hpp` to extract all enum values
   - Pattern: `SWF_ACTION_NAME = 0xHH`
   - Create secondary entries for enum names (e.g., "SWF_ACTION_ADD")
3. Output: ~267 entries (89 opcodes × 3 naming conventions each)

### Phase 2: Map Function Names
1. Parse `SWFModernRuntime/include/actionmodern/action.h` for function declarations
2. Match function names to opcodes by naming convention
   - Pattern: `actionAdd` → `SWF_ACTION_ADD`
   - Convert: camelCase → SNAKE_CASE
3. Parse `SWFRecomp/src/action/action.cpp` to find switch cases
4. Fill in `functions.action_h` and `functions.action_hpp_method` fields

### Phase 3: Find Test Directories
1. List all directories: `ls -d SWFRecomp/tests/*_swf_*/`
2. Extract opcode names from directory names
   - Pattern: `<opcode_name>_swf_<version>/`
   - Convert: snake_case → SNAKE_CASE → match to enum
3. Handle multiple test directories for same opcode (keep first or all?)
4. Fill in `test_directory` field

### Phase 4: Locate Documentation Prompts
1. List files: `ls SWFRecompDocs/prompts/*.md SWFRecompDocs/prompts/completed/*.md`
2. Extract opcode hex values from filenames
   - Pattern: `opcode-<name>-0x<hex>.md`
3. Match hex values to opcodes
4. Fill in `documentation_prompt` field

### Phase 5: Extract Branch Names
1. Load and parse `repository-data.json`
2. Search for branches with pattern: `opcode-<name>-0x<hex>`
3. Match branch names to opcodes by hex value or name
4. For opcodes without dedicated branches, check:
   - branch-merge-history.md for context
   - git log for commit messages mentioning the opcode
5. Fill in `implementation_branch` field

### Phase 6: Manual Review and Cleanup
1. Identify missing entries
2. Add notes for special cases
3. Verify accuracy of mappings
4. Generate final output in both JSON and Markdown formats

## Requirements (Confirmed)

1. **Multiple test directories**: ✅ List ALL test directories for each opcode
   - If ADD has `add_floats_swf_4`, `add_strings_swf_4`, include both
   - Store as array of test directories

2. **Name variations**: ✅ Create SEPARATE entries for each naming convention
   - Official spec name gets its own entry (e.g., "ActionAdd" from SWF spec)
   - "SWF_ACTION_ADD" gets its own entry (from action.hpp)
   - "actionAdd" gets its own entry (from action.h)
   - Each entry cross-references the same opcode hex value

3. **Output format**: ✅ JSON first, then generate Markdown
   - Primary format: JSON for data storage
   - Secondary: Script to generate Markdown table from JSON

4. **Missing data handling**: ✅ Leave fields blank (null/empty arrays in JSON)
   - No "Not implemented" markers
   - Keep the field structure, just leave values empty

5. **Scope of opcodes**: ✅ Include ALL AS2 opcodes (implemented and unimplemented)
   - **Primary Source**: Official SWF specification (`SWFRecompDocs/specs/pdf/swf-spec-19.pdf` or `swf-spec-19.txt`)
   - This is the authoritative list of all ActionScript 2 opcodes
   - Cross-reference with action.hpp enum to verify implementation coverage
   - Include opcodes from spec even if not yet in action.hpp enum

## Estimated Time
- Phase 1: 30 minutes (automated parsing)
- Phase 2: 1 hour (mapping function names)
- Phase 3: 30 minutes (finding test directories)
- Phase 4: 30 minutes (locating prompts)
- Phase 5: 1 hour (extracting branch info)
- Phase 6: 1-2 hours (manual review)

**Total**: 4-5 hours

## Tools Needed
- Python script for parsing (recommended)
  - Parse C++ enum definitions
  - Parse JSON (repository-data.json)
  - File system operations
  - String matching and normalization
- Or: Bash scripts + jq for JSON manipulation
- Or: Manual curation with spreadsheet + scripting assistance

## Next Steps (Ready to Execute)
1. ✅ Requirements confirmed
2. ✅ Data sources identified and verified
3. ✅ SWF specification found in repository
4. 🔄 Write Python extraction script to:
   - Parse SWF specification for official opcode names (PRIMARY)
   - Parse action.hpp enum for implementation names
   - Parse action.h for function declarations
   - Scan test directories
   - Scan documentation prompts
   - Parse repository-data.json for branch info
   - Generate opcode-index.json with 3 entries per opcode (spec, enum, function)
5. 🔄 Write script to generate Markdown table from JSON
6. 🔄 Execute and review output

## Implementation Ready
All requirements are confirmed and data sources are available. Ready to begin implementation.
