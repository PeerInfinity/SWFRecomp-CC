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


def scan_test_directories() -> Dict[str, List[str]]:
    """Scan test directories and map them to opcodes."""
    test_dir = BASE_DIR / "SWFRecomp/tests"
    test_map = {}

    print(f"\nScanning test directories: {test_dir}")

    if not test_dir.exists():
        print("  ERROR: Test directory not found")
        return test_map

    # Find all test directories matching pattern *_swf_*
    for item in sorted(test_dir.iterdir()):
        if item.is_dir() and '_swf_' in item.name:
            test_name = item.name
            relative_path = f"SWFRecomp/tests/{test_name}"

            # Extract opcode name from directory name (e.g., "add2_swf_5" -> "add2")
            opcode_part = test_name.split('_swf_')[0]

            # Convert to various formats to match against
            # e.g., "add2" -> ["add2", "ADD2", "Add2"]
            key = opcode_part.lower()

            if key not in test_map:
                test_map[key] = []

            test_map[key].append(relative_path)
            print(f"  Found: {relative_path}")

    print(f"Total test directory groups: {len(test_map)}")
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


def parse_repository_data() -> Dict[str, Dict]:
    """Parse repository-data.json to extract branch information."""
    repo_data_path = BASE_DIR / "repository-data.json"
    branch_map = {}

    print(f"\nParsing repository data: {repo_data_path}")

    if not repo_data_path.exists():
        print("  ERROR: repository-data.json not found")
        return branch_map

    with open(repo_data_path, 'r') as f:
        data = json.load(f)

    # Extract branches with opcode information
    for branch in data.get('branches', []):
        branch_name = branch.get('name', '')
        subject = branch.get('subject', '')
        head_commit = branch.get('head_commit', '')

        hex_value = None

        # Look for hex value in branch name: opcode-<name>-0x<hex>
        match = re.search(r'opcode-[^-]+-0x([0-9A-Fa-f]+)', branch_name)
        if match:
            hex_value = f"0X{match.group(1).upper()}"
        else:
            # Look for hex value in subject: "Implement ... (0xHH)" or "... opcode (0xHH)"
            match = re.search(r'\(0x([0-9A-Fa-f]+)\)', subject)
            if match:
                hex_value = f"0X{match.group(1).upper()}"
            else:
                # Look for hex value anywhere in subject
                match = re.search(r'0x([0-9A-Fa-f]+)', subject)
                if match:
                    hex_value = f"0X{match.group(1).upper()}"

        if hex_value:
            # Store full branch details
            branch_info = {
                'name': branch_name,
                'head_commit': head_commit,
                'subject': subject
            }
            branch_map[hex_value] = branch_info
            print(f"  Found: {branch_name} -> {hex_value}")

    print(f"Total opcode branches found: {len(branch_map)}")
    return branch_map


def normalize_name_for_matching(name: str) -> str:
    """Normalize a name for matching purposes."""
    # Remove common prefixes/suffixes
    name = name.replace('SWF_ACTION_', '')
    name = name.replace('Action', '')
    name = name.replace('action', '')

    # Convert to lowercase and remove underscores
    return name.lower().replace('_', '')


def match_test_directories(opcode_info: Dict, test_map: Dict[str, List[str]]) -> List[str]:
    """Match test directories to an opcode based on various name formats."""
    tests = []

    # Try matching with spec name
    if 'spec_name' in opcode_info:
        key = normalize_name_for_matching(opcode_info['spec_name'])
        if key in test_map:
            tests.extend(test_map[key])

    # Try matching with enum name
    if 'enum_name' in opcode_info:
        key = normalize_name_for_matching(opcode_info['enum_name'])
        if key in test_map:
            tests.extend(test_map[key])

    # Remove duplicates while preserving order
    seen = set()
    unique_tests = []
    for test in tests:
        if test not in seen:
            seen.add(test)
            unique_tests.append(test)

    return unique_tests


def match_function_name(opcode_info: Dict, functions: Dict[str, Dict]) -> Optional[Dict]:
    """Match a function declaration to an opcode."""
    if 'spec_name' not in opcode_info:
        return None

    # Convert spec name to function name format
    # e.g., "ActionAdd" -> "actionAdd"
    spec_name = opcode_info['spec_name']
    if spec_name.startswith('Action'):
        func_name = 'action' + spec_name[6:]  # Remove "Action" and lowercase first letter

        if func_name in functions:
            return functions[func_name]

    return None


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
    branch_map = parse_repository_data()

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

        # Find matching test directories
        combined_info = {**spec_info, **enum_info}
        test_dirs = match_test_directories(combined_info, test_map)

        # Find matching function
        func_info = match_function_name(combined_info, functions)

        # Get documentation prompt
        doc_prompt = prompt_map.get(hex_value)

        # Get branch info
        branch = branch_map.get(hex_value)

        # Create entry for spec name
        if 'spec_name' in spec_info:
            entries.append({
                'hex': hex_value,
                'name': spec_info['spec_name'],
                'source': 'SWF Specification v19',
                'type': 'spec',
                'function_declaration': None,
                'function_implementation': None,
                'test_directories': test_dirs,
                'documentation_prompt': doc_prompt,
                'implementation_branch': branch,
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
                'test_directories': test_dirs,
                'documentation_prompt': doc_prompt,
                'implementation_branch': branch,
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
                'test_directories': test_dirs,
                'documentation_prompt': doc_prompt,
                'implementation_branch': branch,
                'notes': f"Runtime function (action.h line {func_info.get('line_number', 'unknown')})"
            })

    # Count implemented opcodes (those with test directories)
    implemented_hex_values = set()
    for entry in entries:
        if entry['test_directories']:
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
