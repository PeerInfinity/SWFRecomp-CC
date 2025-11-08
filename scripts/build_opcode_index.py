#!/usr/bin/env python3
"""
Build a comprehensive index of all AS2 opcodes with their various names,
implementations, tests, documentation, and branch information.
"""

import json
import re
import os
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional, Set

# Base directory
BASE_DIR = Path(__file__).parent.parent


def parse_swf_spec() -> Dict[str, Dict]:
    """Parse the SWF specification to extract official opcode names and hex values."""
    spec_path = BASE_DIR / "SWFRecompDocs/specs/swf-spec-19.txt"
    opcodes = {}

    print(f"Parsing SWF specification: {spec_path}")

    with open(spec_path, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    i = 0
    while i < len(lines):
        line = lines[i].strip()

        # Look for Action definitions (lines starting with "Action" followed by uppercase)
        if line and re.match(r'^Action[A-Z]\w*$', line):
            action_name = line

            # Look ahead for ActionCode definition (within next 20 lines)
            for j in range(i + 1, min(i + 20, len(lines))):
                code_line = lines[j].strip()

                # Match patterns like "ActionCode = 0x0A" or "ActionCode = 0x0A;"
                match = re.search(r'ActionCode\s*=\s*(0x[0-9A-Fa-f]+)', code_line)
                if match:
                    hex_value = match.group(1).upper()

                    # Store the opcode
                    if hex_value not in opcodes:
                        opcodes[hex_value] = {
                            'hex': hex_value,
                            'spec_name': action_name,
                            'line_number': i + 1
                        }

                    print(f"  Found: {action_name} = {hex_value}")
                    break

        i += 1

    print(f"Total opcodes found in spec: {len(opcodes)}")
    return opcodes


def parse_action_hpp() -> Dict[str, Dict]:
    """Parse action.hpp to extract enum definitions."""
    hpp_path = BASE_DIR / "SWFRecomp/include/action/action.hpp"
    opcodes = {}

    print(f"\nParsing action.hpp: {hpp_path}")

    with open(hpp_path, 'r') as f:
        content = f.read()

    # Find the SWFActionType enum
    enum_match = re.search(r'enum\s+SWFActionType\s*\{([^}]+)\}', content, re.DOTALL)
    if not enum_match:
        print("  ERROR: Could not find SWFActionType enum")
        return opcodes

    enum_body = enum_match.group(1)

    # Parse each enum entry
    pattern = r'(SWF_ACTION_\w+)\s*=\s*(0x[0-9A-Fa-f]+)'
    for match in re.finditer(pattern, enum_body):
        enum_name = match.group(1)
        hex_value = match.group(2).upper()

        opcodes[hex_value] = {
            'hex': hex_value,
            'enum_name': enum_name
        }

        print(f"  Found: {enum_name} = {hex_value}")

    print(f"Total enum entries found: {len(opcodes)}")
    return opcodes


def parse_action_h() -> Dict[str, Dict]:
    """Parse action.h to extract function declarations."""
    h_path = BASE_DIR / "SWFModernRuntime/include/actionmodern/action.h"
    functions = {}

    print(f"\nParsing action.h: {h_path}")

    with open(h_path, 'r') as f:
        lines = f.readlines()

    # Pattern for function declarations like: void actionAdd(char* stack, u32* sp);
    pattern = r'void\s+(action[A-Z]\w*)\s*\([^)]*\)\s*;'

    for line_num, line in enumerate(lines, 1):
        match = re.search(pattern, line)
        if match:
            func_name = match.group(1)
            declaration = line.strip()

            functions[func_name] = {
                'function_name': func_name,
                'declaration': declaration,
                'line_number': line_num
            }

            print(f"  Found: {func_name} at line {line_num}")

    print(f"Total function declarations found: {len(functions)}")
    return functions


def scan_test_directories() -> Dict[str, Dict]:
    """
    Scan test directories and map them to opcodes by reading test_info.json files.

    Returns a dict mapping hex values to test information:
    {
        "0x0A": {
            "tested": ["SWFRecomp/tests/add_swf_4"],
            "supporting": ["SWFRecomp/tests/other_test_swf_4"],
            "fully_implemented": True,
            "fully_implemented_no_graphics": False,
            "missing_features": {"test_name": ["feature1", "feature2"]}
        }
    }
    """
    test_dir = BASE_DIR / "SWFRecomp/tests"
    test_map = {}

    print(f"\nScanning test directories: {test_dir}")

    if not test_dir.exists():
        print("  ERROR: Test directory not found")
        return test_map

    # Parse action.hpp to get mapping from opcode names to hex values
    hpp_path = BASE_DIR / "SWFRecomp/include/action/action.hpp"
    opcode_name_to_hex = {}

    with open(hpp_path, 'r') as f:
        content = f.read()

    # Find the SWFActionType enum
    enum_match = re.search(r'enum\s+SWFActionType\s*\{([^}]+)\}', content, re.DOTALL)
    if enum_match:
        enum_body = enum_match.group(1)
        pattern = r'(SWF_ACTION_\w+)\s*=\s*(0x[0-9A-Fa-f]+)'
        for match in re.finditer(pattern, enum_body):
            enum_name = match.group(1)
            hex_value = match.group(2).upper()
            # Store mapping from short name to hex
            # e.g., SWF_ACTION_ADD -> ADD
            short_name = enum_name.replace('SWF_ACTION_', '')
            opcode_name_to_hex[short_name] = hex_value

    # Find all test directories with test_info.json
    for item in sorted(test_dir.iterdir()):
        if item.is_dir() and '_swf_' in item.name:
            test_info_path = item / "test_info.json"

            if not test_info_path.exists():
                continue

            try:
                with open(test_info_path, 'r') as f:
                    test_info = json.load(f)

                test_name = item.name
                relative_path = f"SWFRecomp/tests/{test_name}"

                # Get the opcodes from test_info.json
                opcodes_tested = test_info.get('opcodes', {}).get('tested', [])
                opcodes_supporting = test_info.get('opcodes', {}).get('supporting', [])
                fully_implemented = test_info.get('metadata', {}).get('fully_implemented', False)
                fully_implemented_no_graphics = test_info.get('metadata', {}).get('fully_implemented_no_graphics', False)
                missing_features = test_info.get('metadata', {}).get('missing_features', [])

                # Map opcode names to hex values
                for opcode_name in opcodes_tested:
                    hex_value = opcode_name_to_hex.get(opcode_name)
                    if hex_value:
                        if hex_value not in test_map:
                            test_map[hex_value] = {
                                "tested": [],
                                "supporting": [],
                                "fully_implemented": False,
                                "fully_implemented_no_graphics": False,
                                "missing_features": {}
                            }
                        test_map[hex_value]["tested"].append(relative_path)
                        # If any test for this opcode marks it as fully implemented, mark it as such
                        if fully_implemented:
                            test_map[hex_value]["fully_implemented"] = True
                        if fully_implemented_no_graphics:
                            test_map[hex_value]["fully_implemented_no_graphics"] = True
                        # Store missing features per test
                        if missing_features:
                            test_map[hex_value]["missing_features"][test_name] = missing_features
                        print(f"  Found: {relative_path} tests {opcode_name} ({hex_value})")

                for opcode_name in opcodes_supporting:
                    hex_value = opcode_name_to_hex.get(opcode_name)
                    if hex_value:
                        if hex_value not in test_map:
                            test_map[hex_value] = {
                                "tested": [],
                                "supporting": [],
                                "fully_implemented": False,
                                "fully_implemented_no_graphics": False,
                                "missing_features": {}
                            }
                        test_map[hex_value]["supporting"].append(relative_path)

            except (json.JSONDecodeError, KeyError) as e:
                print(f"  WARNING: Could not parse {test_info_path}: {e}")

    print(f"Total opcodes with tests: {len(test_map)}")
    return test_map


def scan_documentation_prompts() -> Dict[str, str]:
    """Scan documentation prompt files and map them to opcodes."""
    prompts_dir = BASE_DIR / "SWFRecompDocs/prompts"
    prompt_map = {}

    print(f"\nScanning documentation prompts: {prompts_dir}")

    if not prompts_dir.exists():
        print("  ERROR: Prompts directory not found")
        return prompt_map

    # Recursively scan all subdirectories for opcode-*.md files
    for item in prompts_dir.rglob("opcode-*.md"):
        filename = item.name
        relative_path = str(item.relative_to(BASE_DIR))

        # Extract hex value from filename (e.g., "opcode-add2-0x47.md")
        hex_match = re.search(r'0x([0-9A-Fa-f]+)', filename)
        if hex_match:
            hex_value = f"0X{hex_match.group(1).upper()}"
            prompt_map[hex_value] = relative_path
            print(f"  Found: {filename} -> {hex_value}")

    print(f"Total documentation prompts found: {len(prompt_map)}")
    return prompt_map




def load_test_results() -> Dict[str, bool]:
    """
    Load test_results.json and return a mapping of test names to pass/fail status.

    Returns:
        Dict mapping test name to whether it passed (True/False)
    """
    test_results_path = BASE_DIR / "SWFRecomp/tests/test_results.json"
    test_status = {}

    print(f"\nLoading test results: {test_results_path}")

    if not test_results_path.exists():
        print("  WARNING: test_results.json not found")
        return test_status

    try:
        with open(test_results_path, 'r') as f:
            data = json.load(f)

        for test in data.get('tests', []):
            test_name = test.get('name')
            passed = test.get('passed', False)
            if test_name:
                test_status[test_name] = passed
                print(f"  {test_name}: {'PASS' if passed else 'FAIL'}")

        print(f"Total test results loaded: {len(test_status)}")
    except (json.JSONDecodeError, KeyError) as e:
        print(f"  WARNING: Could not parse test_results.json: {e}")

    return test_status


def normalize_name_for_matching(name: str) -> str:
    """Normalize a name for matching purposes."""
    # Remove common prefixes/suffixes
    name = name.replace('SWF_ACTION_', '')
    name = name.replace('Action', '')
    name = name.replace('action', '')

    # Convert to lowercase and remove underscores
    return name.lower().replace('_', '')


def get_test_directories_for_opcode(hex_value: str, test_map: Dict[str, Dict]) -> Dict:
    """Get test directories for an opcode by hex value."""
    return test_map.get(hex_value, {
        "tested": [],
        "supporting": [],
        "fully_implemented": False,
        "fully_implemented_no_graphics": False,
        "missing_features": {}
    })


def match_function_name(opcode_info: Dict, functions: Dict[str, Dict]) -> Optional[Dict]:
    """Match a function declaration to an opcode using normalized name matching."""
    if 'spec_name' not in opcode_info and 'enum_name' not in opcode_info:
        return None

    # Strategy 1: Try exact match with spec name
    if 'spec_name' in opcode_info:
        spec_name = opcode_info['spec_name']
        if spec_name.startswith('Action'):
            # Try direct transformation: "ActionAdd" -> "actionAdd"
            func_name = 'action' + spec_name[6:]
            if func_name in functions:
                return functions[func_name]

    # Strategy 2: Normalize and fuzzy match based on enum name or spec name
    search_name = opcode_info.get('enum_name', opcode_info.get('spec_name', ''))
    normalized_search = normalize_name_for_matching(search_name)

    # Find the best matching function by normalized name
    best_match = None
    for func_name, func_info in functions.items():
        normalized_func = normalize_name_for_matching(func_name)
        if normalized_func == normalized_search:
            best_match = func_info
            break

    return best_match


def build_opcode_index():
    """Build the complete opcode index."""
    print("=" * 80)
    print("Building AS2 Opcode Index")
    print("=" * 80)

    # Parse all data sources
    spec_opcodes = parse_swf_spec()
    enum_opcodes = parse_action_hpp()
    functions = parse_action_h()
    test_map = scan_test_directories()
    prompt_map = scan_documentation_prompts()
    test_results = load_test_results()

    # Merge all data
    print("\n" + "=" * 80)
    print("Merging data...")
    print("=" * 80)

    # Collect all unique hex values
    all_hex_values = set()
    all_hex_values.update(spec_opcodes.keys())
    all_hex_values.update(enum_opcodes.keys())

    entries = []

    for hex_value in sorted(all_hex_values):
        # Get base opcode info
        spec_info = spec_opcodes.get(hex_value, {})
        enum_info = enum_opcodes.get(hex_value, {})

        # Get test directories for this opcode
        test_info = get_test_directories_for_opcode(hex_value, test_map)
        tests_tested = test_info["tested"]
        tests_supporting = test_info["supporting"]
        fully_implemented = test_info["fully_implemented"]
        fully_implemented_no_graphics = test_info["fully_implemented_no_graphics"]
        missing_features = test_info["missing_features"]

        # Determine passing tests
        tests_tested_passing = []
        tests_supporting_passing = []

        for test_path in tests_tested:
            test_name = test_path.split('/')[-1]  # Extract test name from path
            if test_results.get(test_name, False):
                tests_tested_passing.append(test_path)

        for test_path in tests_supporting:
            test_name = test_path.split('/')[-1]
            if test_results.get(test_name, False):
                tests_supporting_passing.append(test_path)

        # Find matching function
        combined_info = {**spec_info, **enum_info}
        func_info = match_function_name(combined_info, functions)

        # Get documentation prompt
        doc_prompt = prompt_map.get(hex_value)

        # Create entry for spec name
        if 'spec_name' in spec_info:
            entries.append({
                'hex': hex_value,
                'name': spec_info['spec_name'],
                'source': 'SWF Specification v19',
                'type': 'spec',
                'function_declaration': None,
                'function_implementation': None,
                'tests_primary': tests_tested,
                'tests_secondary': tests_supporting,
                'tests_primary_passing': tests_tested_passing,
                'tests_secondary_passing': tests_supporting_passing,
                'documentation_prompt': doc_prompt,
                'fully_implemented': fully_implemented,
                'fully_implemented_no_graphics': fully_implemented_no_graphics,
                'missing_features': missing_features,
                'notes': f"Official SWF specification name (spec line {spec_info.get('line_number', 'unknown')})"
            })

        # Create entry for enum name
        if 'enum_name' in enum_info:
            entries.append({
                'hex': hex_value,
                'name': enum_info['enum_name'],
                'source': 'action.hpp',
                'type': 'enum',
                'function_declaration': None,
                'function_implementation': f"parseActions (case {enum_info['enum_name']})",
                'tests_primary': tests_tested,
                'tests_secondary': tests_supporting,
                'tests_primary_passing': tests_tested_passing,
                'tests_secondary_passing': tests_supporting_passing,
                'documentation_prompt': doc_prompt,
                'fully_implemented': fully_implemented,
                'fully_implemented_no_graphics': fully_implemented_no_graphics,
                'missing_features': missing_features,
                'notes': 'C++ enum value for opcode'
            })

        # Create entry for function name
        if func_info:
            entries.append({
                'hex': hex_value,
                'name': func_info['function_name'],
                'source': 'action.h',
                'type': 'function',
                'function_declaration': func_info['declaration'],
                'function_implementation': 'SWFModernRuntime/src/actionmodern/action.c',
                'tests_primary': tests_tested,
                'tests_secondary': tests_supporting,
                'tests_primary_passing': tests_tested_passing,
                'tests_secondary_passing': tests_supporting_passing,
                'documentation_prompt': doc_prompt,
                'fully_implemented': fully_implemented,
                'fully_implemented_no_graphics': fully_implemented_no_graphics,
                'missing_features': missing_features,
                'notes': f"Runtime function (action.h line {func_info.get('line_number', 'unknown')})"
            })

    # Count implemented opcodes (those with primary tests)
    implemented_hex_values = set()
    for entry in entries:
        if entry.get('tests_primary'):
            implemented_hex_values.add(entry['hex'])

    # Build final index
    index = {
        'metadata': {
            'generated_date': datetime.now().strftime('%Y-%m-%d'),
            'total_opcodes': len(all_hex_values),
            'implemented_opcodes': len(implemented_hex_values),
            'total_entries': len(entries)
        },
        'entries': entries
    }

    # Write to file
    output_path = BASE_DIR / "opcode-index.json"
    with open(output_path, 'w') as f:
        json.dump(index, f, indent=2)

    print(f"\n" + "=" * 80)
    print(f"Opcode index generated: {output_path}")
    print(f"  Total opcodes: {len(all_hex_values)}")
    print(f"  Implemented opcodes: {len(implemented_hex_values)}")
    print(f"  Total entries: {len(entries)}")
    print("=" * 80)

    return index


if __name__ == '__main__':
    build_opcode_index()
