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
    md.append(f"**Total Opcodes**: {index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Implemented Opcodes**: {index['metadata']['implemented_opcodes']}")
    md.append("")
    md.append(f"**Total Entries**: {index['metadata']['total_entries']}")
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
    md.append("| Hex | Spec Name | Enum Name | Function Name | Tests | Docs | Branch |")
    md.append("|-----|-----------|-----------|---------------|-------|------|--------|")

    for hex_val in sorted(opcodes.keys()):
        entries = opcodes[hex_val]

        # Extract names by type
        spec_name = ""
        enum_name = ""
        func_name = ""
        test_count = 0
        has_docs = ""
        has_branch = ""

        for entry in entries:
            if entry['type'] == 'spec':
                spec_name = entry['name']
                test_count = len(entry.get('test_directories', []))
                has_docs = "✓" if entry.get('documentation_prompt') else ""
                has_branch = "✓" if entry.get('implementation_branch') else ""
            elif entry['type'] == 'enum':
                enum_name = entry['name']
            elif entry['type'] == 'function':
                func_name = entry['name']

        # Format test count
        test_str = str(test_count) if test_count > 0 else ""

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

        md.append(f"| {hex_link} | {spec_link} | {enum_link} | {func_link} | {test_str} | {has_docs} | {has_branch} |")

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

        # Test directories
        if first_entry.get('test_directories'):
            md.append("**Test Directories:**")
            for test_dir in first_entry['test_directories']:
                md.append(f"- `{test_dir}`")
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

        # Branch
        if first_entry.get('implementation_branch'):
            branch = first_entry['implementation_branch']
            md.append("**Implementation Branch:**")

            # Check if branch is a dict (new format) or string (old format)
            if isinstance(branch, dict):
                md.append(f"- **Branch**: `{branch.get('name', '')}`")
                if branch.get('head_commit'):
                    md.append(f"- **Commit**: `{branch['head_commit']}`")
                if branch.get('subject'):
                    md.append(f"- **Subject**: {branch['subject']}")
            else:
                # Old format - just a string
                md.append(f"- `{branch}`")
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
                'has_tests': False,
                'has_docs': False,
                'has_branch': False
            }

        if entry['type'] == 'spec':
            opcodes[hex_val]['spec_name'] = entry['name']
            opcodes[hex_val]['has_tests'] = len(entry.get('test_directories', [])) > 0
            opcodes[hex_val]['has_docs'] = bool(entry.get('documentation_prompt'))
            opcodes[hex_val]['has_branch'] = bool(entry.get('implementation_branch'))
        elif entry['type'] == 'enum':
            opcodes[hex_val]['has_enum'] = True
        elif entry['type'] == 'function':
            opcodes[hex_val]['has_function'] = True

    md.append("## Implementation Status")
    md.append("")

    # Fully implemented
    md.append("### ✅ Fully Implemented")
    md.append("(Has enum, function, and tests)")
    md.append("")
    md.append("| Hex | Spec Name | Enum | Function | Tests | Docs | Branch |")
    md.append("|-----|-----------|------|----------|-------|------|--------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if opc['has_enum'] and opc['has_function'] and opc['has_tests']:
            if with_links:
                hex_link = make_link(opc['hex'], opc['hex'], opc['spec_name']) if opc['spec_name'] else opc['hex']
                spec_link = make_link(opc['spec_name'], opc['hex'], opc['spec_name']) if opc['spec_name'] else ""
            else:
                hex_link = opc['hex']
                spec_link = opc['spec_name']
            md.append(f"| {hex_link} | {spec_link} | ✓ | ✓ | ✓ | {'✓' if opc['has_docs'] else ''} | {'✓' if opc['has_branch'] else ''} |")

    md.append("")

    # Partially implemented
    md.append("### 🔄 Partially Implemented")
    md.append("(Has enum or function, but missing tests)")
    md.append("")
    md.append("| Hex | Spec Name | Enum | Function | Tests | Docs | Branch |")
    md.append("|-----|-----------|------|----------|-------|------|--------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if (opc['has_enum'] or opc['has_function']) and not opc['has_tests']:
            if with_links:
                hex_link = make_link(opc['hex'], opc['hex'], opc['spec_name']) if opc['spec_name'] else opc['hex']
                spec_link = make_link(opc['spec_name'], opc['hex'], opc['spec_name']) if opc['spec_name'] else ""
            else:
                hex_link = opc['hex']
                spec_link = opc['spec_name']
            md.append(f"| {hex_link} | {spec_link} | {'✓' if opc['has_enum'] else ''} | {'✓' if opc['has_function'] else ''} | | {'✓' if opc['has_docs'] else ''} | {'✓' if opc['has_branch'] else ''} |")

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
