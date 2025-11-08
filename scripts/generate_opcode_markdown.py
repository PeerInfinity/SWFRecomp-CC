#!/usr/bin/env python3
"""
Generate a Markdown table from the opcode-index.json file.
"""

import json
from pathlib import Path
from typing import Dict, List

# Base directory
BASE_DIR = Path(__file__).parent.parent


def make_anchor(hex_val: str, spec_name: str) -> str:
    """Generate a Markdown anchor link for an opcode."""
    # GitHub-style anchor: lowercase, replace spaces with hyphens, remove special chars
    # Format: "#0x0a-actionadd"
    anchor = f"{hex_val.lower()}-{spec_name.lower()}"
    anchor = anchor.replace(' ', '-').replace(':', '')
    return anchor


def make_link(text: str, hex_val: str, spec_name: str) -> str:
    """Generate a Markdown link to the detailed section."""
    if not text:
        return ""
    anchor = make_anchor(hex_val, spec_name)
    return f"[{text}](#{anchor})"


def load_opcode_index() -> Dict:
    """Load the opcode index JSON file."""
    index_path = BASE_DIR / "opcode-index.json"

    with open(index_path, 'r') as f:
        return json.load(f)


def generate_summary_table(index: Dict, with_links: bool = True) -> str:
    """Generate a summary table grouped by opcode hex value."""
    md = []

    md.append("# AS2 Opcode Index")
    md.append("")
    md.append(f"**Generated**: {index['metadata']['generated_date']}")
    md.append("")

    # Calculate comprehensive statistics
    total_primary_tests = 0
    passing_primary_tests = 0
    total_secondary_tests = 0
    passing_secondary_tests = 0
    opcodes_with_primary = 0
    opcodes_with_failing_primary = 0
    opcodes_fully_implemented = 0
    opcodes_with_docs = 0
    opcodes_with_function = 0
    opcodes_with_enum = 0

    # Group entries by hex value for analysis
    opcodes = {}
    for entry in index['entries']:
        hex_val = entry['hex']
        if hex_val not in opcodes:
            opcodes[hex_val] = []
        opcodes[hex_val].append(entry)

    # Analyze each opcode
    for hex_val, entries in opcodes.items():
        for entry in entries:
            if entry['type'] == 'spec':
                primary_tests = entry.get('tests_primary', [])
                passing_primary = entry.get('tests_primary_passing', [])
                secondary_tests = entry.get('tests_secondary', [])
                passing_secondary = entry.get('tests_secondary_passing', [])

                total_primary_tests += len(primary_tests)
                passing_primary_tests += len(passing_primary)
                total_secondary_tests += len(secondary_tests)
                passing_secondary_tests += len(passing_secondary)

                if len(primary_tests) > 0:
                    opcodes_with_primary += 1
                    if len(passing_primary) < len(primary_tests):
                        opcodes_with_failing_primary += 1

                if entry.get('fully_implemented'):
                    opcodes_fully_implemented += 1

                if entry.get('documentation_prompt'):
                    opcodes_with_docs += 1

            elif entry['type'] == 'function':
                opcodes_with_function += 1
            elif entry['type'] == 'enum':
                opcodes_with_enum += 1

    # Calculate percentages
    primary_pass_rate = (passing_primary_tests / total_primary_tests * 100) if total_primary_tests > 0 else 0
    secondary_pass_rate = (passing_secondary_tests / total_secondary_tests * 100) if total_secondary_tests > 0 else 0
    total_tests = total_primary_tests + total_secondary_tests
    total_passing = passing_primary_tests + passing_secondary_tests
    overall_pass_rate = (total_passing / total_tests * 100) if total_tests > 0 else 0

    # Display basic metadata
    md.append(f"**Total Opcodes**: {index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Implemented Opcodes**: {index['metadata']['implemented_opcodes']}")
    md.append("")
    md.append(f"**Total Entries**: {index['metadata']['total_entries']}")
    md.append("")

    # Test Statistics Section
    md.append("## Test Statistics")
    md.append("")
    md.append(f"**Overall Test Results**: {total_passing}/{total_tests} passing ({overall_pass_rate:.1f}%)")
    md.append("")

    # Primary Tests
    failing_primary = total_primary_tests - passing_primary_tests
    md.append(f"**Primary Tests**: {passing_primary_tests}/{total_primary_tests} passing ({primary_pass_rate:.1f}%)")
    if failing_primary > 0:
        md.append(f"  - {failing_primary} failing primary tests")
        md.append(f"  - {opcodes_with_failing_primary} opcodes with failing primary tests")
    md.append("")

    # Secondary Tests
    failing_secondary = total_secondary_tests - passing_secondary_tests
    md.append(f"**Secondary Tests**: {passing_secondary_tests}/{total_secondary_tests} passing ({secondary_pass_rate:.1f}%)")
    if failing_secondary > 0:
        md.append(f"  - {failing_secondary} failing secondary tests")
    md.append("")

    # Implementation Progress
    md.append("## Implementation Progress")
    md.append("")
    md.append(f"**Fully Implemented Opcodes**: {opcodes_fully_implemented}/{index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Opcodes with Primary Tests**: {opcodes_with_primary}")
    md.append("")
    md.append(f"**Opcodes with Documentation**: {opcodes_with_docs}")
    md.append("")

    # What Needs Attention
    if failing_primary > 0 or failing_secondary > 0:
        md.append("## What Needs Attention")
        md.append("")
        if failing_primary > 0:
            md.append(f"- **{failing_primary} failing primary tests** across {opcodes_with_failing_primary} opcodes (see 'Failing Primary' column)")
        if failing_secondary > 0:
            md.append(f"- **{failing_secondary} failing secondary tests**")
        opcodes_not_fully_implemented = index['metadata']['total_opcodes'] - opcodes_fully_implemented
        if opcodes_not_fully_implemented > 0:
            md.append(f"- **{opcodes_not_fully_implemented} opcodes** not yet marked as fully implemented")
        md.append("")

    md.append("")

    # Group entries by hex value
    opcodes = {}
    for entry in index['entries']:
        hex_val = entry['hex']
        if hex_val not in opcodes:
            opcodes[hex_val] = []
        opcodes[hex_val].append(entry)

    # Generate summary table
    md.append("## Summary Table")
    md.append("")
    md.append("| Hex | Spec Name | Enum Name | Function Name | Primary Tests | Secondary Tests | Failing Primary | Docs | Fully Implemented |")
    md.append("|-----|-----------|-----------|---------------|---------------|-----------------|-----------------|------|-------------------|")

    for hex_val in sorted(opcodes.keys()):
        entries = opcodes[hex_val]

        # Extract names by type
        spec_name = ""
        enum_name = ""
        func_name = ""
        primary_count = 0
        secondary_count = 0
        passing_primary_count = 0
        passing_secondary_count = 0
        has_docs = ""
        fully_implemented = False

        for entry in entries:
            if entry['type'] == 'spec':
                spec_name = entry['name']
                primary_count = len(entry.get('tests_primary', []))
                secondary_count = len(entry.get('tests_secondary', []))
                passing_primary_count = len(entry.get('tests_primary_passing', []))
                passing_secondary_count = len(entry.get('tests_secondary_passing', []))
                has_docs = "✓" if entry.get('documentation_prompt') else ""
                fully_implemented = entry.get('fully_implemented', False)
            elif entry['type'] == 'enum':
                enum_name = entry['name']
            elif entry['type'] == 'function':
                func_name = entry['name']

        # Format test counts as "passing/total"
        primary_str = f"{passing_primary_count}/{primary_count}" if primary_count > 0 else ""
        secondary_str = f"{passing_secondary_count}/{secondary_count}" if secondary_count > 0 else ""

        # Calculate failing tests
        failing_primary_count = primary_count - passing_primary_count
        failing_str = str(failing_primary_count) if failing_primary_count > 0 else ""

        # Format fully_implemented as checkbox
        fully_impl_str = "✓" if fully_implemented else ""

        if with_links:
            # Create links to detailed section
            hex_link = make_link(hex_val, hex_val, spec_name) if spec_name else hex_val
            spec_link = make_link(spec_name, hex_val, spec_name) if spec_name else ""
            enum_link = make_link(enum_name, hex_val, spec_name) if enum_name and spec_name else enum_name
            func_link = make_link(func_name, hex_val, spec_name) if func_name and spec_name else func_name
        else:
            # Plain text without links
            hex_link = hex_val
            spec_link = spec_name
            enum_link = enum_name
            func_link = func_name

        md.append(f"| {hex_link} | {spec_link} | {enum_link} | {func_link} | {primary_str} | {secondary_str} | {failing_str} | {has_docs} | {fully_impl_str} |")

    md.append("")
    return "\n".join(md)


def generate_detailed_sections(index: Dict) -> str:
    """Generate detailed sections for each opcode."""
    md = []

    # Group entries by hex value
    opcodes = {}
    for entry in index['entries']:
        hex_val = entry['hex']
        if hex_val not in opcodes:
            opcodes[hex_val] = []
        opcodes[hex_val].append(entry)

    md.append("## Detailed Information")
    md.append("")

    for hex_val in sorted(opcodes.keys()):
        entries = opcodes[hex_val]

        # Get spec name for section title
        spec_name = "Unknown"
        for entry in entries:
            if entry['type'] == 'spec':
                spec_name = entry['name']
                break

        md.append(f"### {hex_val}: {spec_name}")
        md.append("")

        # Show all name variations
        md.append("**Name Variations:**")
        for entry in entries:
            md.append(f"- `{entry['name']}` ({entry['type']}, source: {entry['source']})")
        md.append("")

        # Get common data from first entry
        first_entry = entries[0]

        # Primary Tests
        if first_entry.get('tests_primary'):
            md.append("**Primary Tests:**")
            tests_primary_passing = set(first_entry.get('tests_primary_passing', []))
            for test_dir in first_entry['tests_primary']:
                status = "✓" if test_dir in tests_primary_passing else "✗"
                md.append(f"- [{status}] `{test_dir}`")
            md.append("")

        # Secondary Tests
        if first_entry.get('tests_secondary'):
            md.append("**Secondary Tests:**")
            tests_secondary_passing = set(first_entry.get('tests_secondary_passing', []))
            for test_dir in first_entry['tests_secondary']:
                status = "✓" if test_dir in tests_secondary_passing else "✗"
                md.append(f"- [{status}] `{test_dir}`")
            md.append("")

        # Function declarations
        for entry in entries:
            if entry.get('function_declaration'):
                md.append("**Function Declaration:**")
                md.append(f"```c")
                md.append(entry['function_declaration'])
                md.append(f"```")
                md.append("")
                break

        # Function implementation
        for entry in entries:
            if entry.get('function_implementation'):
                md.append("**Implementation:**")
                md.append(f"- {entry['function_implementation']}")
                md.append("")
                break

        # Documentation
        if first_entry.get('documentation_prompt'):
            md.append("**Documentation:**")
            md.append(f"- [{first_entry['documentation_prompt']}]({first_entry['documentation_prompt']})")
            md.append("")

        # Notes
        if first_entry.get('notes'):
            md.append("**Notes:**")
            md.append(f"- {first_entry['notes']}")
            md.append("")

        md.append("---")
        md.append("")

    return "\n".join(md)


def generate_implementation_status(index: Dict, with_links: bool = True) -> str:
    """Generate implementation status section."""
    md = []

    # Group entries by hex value
    opcodes = {}
    for entry in index['entries']:
        hex_val = entry['hex']
        if hex_val not in opcodes:
            opcodes[hex_val] = {
                'hex': hex_val,
                'spec_name': '',
                'has_enum': False,
                'has_function': False,
                'has_primary_tests': False,
                'primary_count': 0,
                'passing_primary_count': 0,
                'has_docs': False,
                'fully_implemented': False
            }

        if entry['type'] == 'spec':
            opcodes[hex_val]['spec_name'] = entry['name']
            opcodes[hex_val]['has_primary_tests'] = len(entry.get('tests_primary', [])) > 0
            opcodes[hex_val]['primary_count'] = len(entry.get('tests_primary', []))
            opcodes[hex_val]['passing_primary_count'] = len(entry.get('tests_primary_passing', []))
            opcodes[hex_val]['has_docs'] = bool(entry.get('documentation_prompt'))
            opcodes[hex_val]['fully_implemented'] = entry.get('fully_implemented', False)
        elif entry['type'] == 'enum':
            opcodes[hex_val]['has_enum'] = True
        elif entry['type'] == 'function':
            opcodes[hex_val]['has_function'] = True

    md.append("## Implementation Status")
    md.append("")

    # Fully implemented
    md.append("### ✅ Fully Implemented")
    md.append("(Opcodes marked as fully_implemented in test_info.json)")
    md.append("")
    md.append("| Hex | Spec Name | Enum | Function | Primary Tests | Failing Primary | Docs |")
    md.append("|-----|-----------|------|----------|---------------|-----------------|------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if opc['fully_implemented']:
            if with_links:
                hex_link = make_link(opc['hex'], opc['hex'], opc['spec_name']) if opc['spec_name'] else opc['hex']
                spec_link = make_link(opc['spec_name'], opc['hex'], opc['spec_name']) if opc['spec_name'] else ""
            else:
                hex_link = opc['hex']
                spec_link = opc['spec_name']

            test_status = f"{opc['passing_primary_count']}/{opc['primary_count']}"
            failing_count = opc['primary_count'] - opc['passing_primary_count']
            failing_str = str(failing_count) if failing_count > 0 else ""
            md.append(f"| {hex_link} | {spec_link} | {'✓' if opc['has_enum'] else ''} | {'✓' if opc['has_function'] else ''} | {test_status} | {failing_str} | {'✓' if opc['has_docs'] else ''} |")

    md.append("")

    # Partially implemented
    md.append("### 🔄 Partially Implemented")
    md.append("(Has enum or function, but missing tests)")
    md.append("")
    md.append("| Hex | Spec Name | Enum | Function | Docs |")
    md.append("|-----|-----------|------|----------|------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if (opc['has_enum'] or opc['has_function']) and not opc['has_primary_tests']:
            if with_links:
                hex_link = make_link(opc['hex'], opc['hex'], opc['spec_name']) if opc['spec_name'] else opc['hex']
                spec_link = make_link(opc['spec_name'], opc['hex'], opc['spec_name']) if opc['spec_name'] else ""
            else:
                hex_link = opc['hex']
                spec_link = opc['spec_name']
            md.append(f"| {hex_link} | {spec_link} | {'✓' if opc['has_enum'] else ''} | {'✓' if opc['has_function'] else ''} | {'✓' if opc['has_docs'] else ''} |")

    md.append("")

    # Not implemented
    md.append("### ❌ Not Implemented")
    md.append("(Only in spec, no implementation yet)")
    md.append("")
    md.append("| Hex | Spec Name |")
    md.append("|-----|-----------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if not opc['has_enum'] and not opc['has_function']:
            if with_links:
                hex_link = make_link(opc['hex'], opc['hex'], opc['spec_name']) if opc['spec_name'] else opc['hex']
                spec_link = make_link(opc['spec_name'], opc['hex'], opc['spec_name']) if opc['spec_name'] else ""
            else:
                hex_link = opc['hex']
                spec_link = opc['spec_name']
            md.append(f"| {hex_link} | {spec_link} |")

    md.append("")

    return "\n".join(md)


def generate_markdown():
    """Generate the complete Markdown documentation in two versions."""
    print("Loading opcode index...")
    index = load_opcode_index()

    print("Generating detailed sections...")
    detailed = generate_detailed_sections(index)

    # Generate version WITH links
    print("\nGenerating version WITH links...")
    summary_with_links = generate_summary_table(index, with_links=True)
    status_with_links = generate_implementation_status(index, with_links=True)

    markdown_with_links = "\n".join([
        summary_with_links,
        status_with_links,
        detailed
    ])

    output_path_with_links = BASE_DIR / "opcode-index.md"
    with open(output_path_with_links, 'w') as f:
        f.write(markdown_with_links)

    print(f"  Generated: {output_path_with_links}")

    # Generate version WITHOUT links
    print("\nGenerating version WITHOUT links...")
    summary_no_links = generate_summary_table(index, with_links=False)
    status_no_links = generate_implementation_status(index, with_links=False)

    markdown_no_links = "\n".join([
        summary_no_links,
        status_no_links,
        detailed
    ])

    output_path_no_links = BASE_DIR / "opcode-index-plain.md"
    with open(output_path_no_links, 'w') as f:
        f.write(markdown_no_links)

    print(f"  Generated: {output_path_no_links}")

    print("\nMarkdown documentation generated successfully!")


if __name__ == '__main__':
    generate_markdown()
