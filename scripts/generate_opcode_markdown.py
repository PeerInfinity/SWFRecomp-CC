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
    no_results_primary_tests = 0
    total_secondary_tests = 0
    passing_secondary_tests = 0
    no_results_secondary_tests = 0
    opcodes_with_primary = 0
    opcodes_with_failing_primary = 0
    opcodes_fully_implemented = 0
    opcodes_fully_implemented_no_graphics = 0
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
                no_results_primary = entry.get('tests_primary_no_results', [])
                secondary_tests = entry.get('tests_secondary', [])
                passing_secondary = entry.get('tests_secondary_passing', [])
                no_results_secondary = entry.get('tests_secondary_no_results', [])

                total_primary_tests += len(primary_tests)
                passing_primary_tests += len(passing_primary)
                no_results_primary_tests += len(no_results_primary)
                total_secondary_tests += len(secondary_tests)
                passing_secondary_tests += len(passing_secondary)
                no_results_secondary_tests += len(no_results_secondary)

                if len(primary_tests) > 0:
                    opcodes_with_primary += 1
                    # Only count as failing if the test was actually run and failed
                    failing_primary_count = len(primary_tests) - len(passing_primary) - len(no_results_primary)
                    if failing_primary_count > 0:
                        opcodes_with_failing_primary += 1

                if entry.get('fully_implemented'):
                    opcodes_fully_implemented += 1

                if entry.get('fully_implemented') or entry.get('fully_implemented_no_graphics'):
                    opcodes_fully_implemented_no_graphics += 1

                if entry.get('documentation_prompt'):
                    opcodes_with_docs += 1

            elif entry['type'] == 'function':
                opcodes_with_function += 1
            elif entry['type'] == 'enum':
                opcodes_with_enum += 1

    # Calculate counts and percentages
    failing_primary = total_primary_tests - passing_primary_tests - no_results_primary_tests
    tests_with_results = total_primary_tests - no_results_primary_tests
    primary_pass_rate = (passing_primary_tests / tests_with_results * 100) if tests_with_results > 0 else 0

    failing_secondary = total_secondary_tests - passing_secondary_tests - no_results_secondary_tests
    secondary_tests_with_results = total_secondary_tests - no_results_secondary_tests
    secondary_pass_rate = (passing_secondary_tests / secondary_tests_with_results * 100) if secondary_tests_with_results > 0 else 0

    # Display basic metadata
    md.append(f"**Total Opcodes**: {index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Implemented Opcodes**: {index['metadata']['implemented_opcodes']}")
    md.append("")

    # Test Statistics Section
    md.append("## Test Statistics")
    md.append("")

    # Primary Tests
    md.append(f"**Primary Tests**: {passing_primary_tests}/{tests_with_results} passing ({primary_pass_rate:.1f}%)")
    if failing_primary > 0:
        md.append(f"  - {failing_primary} failing primary tests")
        md.append(f"  - {opcodes_with_failing_primary} opcodes with failing primary tests")
    if no_results_primary_tests > 0:
        md.append(f"  - {no_results_primary_tests} primary tests with no results (not run)")
    md.append("")

    # Implementation Progress
    md.append("## Implementation Progress")
    md.append("")
    md.append(f"**Fully Implemented Opcodes**: {opcodes_fully_implemented}/{index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Fully Implemented Opcodes - No Graphics Mode**: {opcodes_fully_implemented_no_graphics}/{index['metadata']['total_opcodes']}")
    md.append("")
    md.append(f"**Opcodes with Primary Tests**: {opcodes_with_primary}")
    md.append("")
    md.append(f"**Opcodes with Documentation**: {opcodes_with_docs}")
    md.append("")

    # What Needs Attention
    if failing_primary > 0:
        md.append("## What Needs Attention")
        md.append("")
        if failing_primary > 0:
            md.append(f"- **{failing_primary} failing primary tests** across {opcodes_with_failing_primary} opcodes (see 'Failing Primary' column)")
        opcodes_not_fully_implemented = index['metadata']['total_opcodes'] - opcodes_fully_implemented
        if opcodes_not_fully_implemented > 0:
            md.append(f"- **{opcodes_not_fully_implemented} opcodes** not yet marked as fully implemented")
        opcodes_not_fully_implemented_no_graphics = index['metadata']['total_opcodes'] - opcodes_fully_implemented_no_graphics
        if opcodes_not_fully_implemented_no_graphics > 0:
            md.append(f"- **{opcodes_not_fully_implemented_no_graphics} opcodes** not yet marked as fully implemented for NO_GRAPHICS mode")
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
    md.append("| Hex | Spec Name | Enum Name | Function Name | Primary Tests | Secondary Tests | Failing Primary | Docs | Fully Impl | Fully Impl (No Graphics) |")
    md.append("|-----|-----------|-----------|---------------|---------------|-----------------|-----------------|------|------------|--------------------------|")

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
        no_results_primary_count = 0
        no_results_secondary_count = 0
        has_docs = ""
        fully_implemented = False
        fully_implemented_no_graphics = False

        for entry in entries:
            if entry['type'] == 'spec':
                spec_name = entry['name']
                primary_count = len(entry.get('tests_primary', []))
                secondary_count = len(entry.get('tests_secondary', []))
                passing_primary_count = len(entry.get('tests_primary_passing', []))
                passing_secondary_count = len(entry.get('tests_secondary_passing', []))
                no_results_primary_count = len(entry.get('tests_primary_no_results', []))
                no_results_secondary_count = len(entry.get('tests_secondary_no_results', []))
                has_docs = "✓" if entry.get('documentation_prompt') else ""
                fully_implemented = entry.get('fully_implemented', False)
                fully_implemented_no_graphics = entry.get('fully_implemented_no_graphics', False)
            elif entry['type'] == 'enum':
                enum_name = entry['name']
            elif entry['type'] == 'function':
                func_name = entry['name']

        # Format test counts as "passing/total" (excluding no-results tests from total)
        primary_with_results = primary_count - no_results_primary_count
        secondary_with_results = secondary_count - no_results_secondary_count
        primary_str = f"{passing_primary_count}/{primary_with_results}" if primary_with_results > 0 else ""
        secondary_str = f"{passing_secondary_count}/{secondary_with_results}" if secondary_with_results > 0 else ""

        # Calculate failing tests (only tests that were run and failed)
        failing_primary_count = primary_count - passing_primary_count - no_results_primary_count
        failing_str = str(failing_primary_count) if failing_primary_count > 0 else ""

        # Format fully_implemented as checkbox
        fully_impl_str = "✓" if fully_implemented else ""
        fully_impl_no_graphics_str = "✓" if fully_implemented_no_graphics else ""

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

        md.append(f"| {hex_link} | {spec_link} | {enum_link} | {func_link} | {primary_str} | {secondary_str} | {failing_str} | {has_docs} | {fully_impl_str} | {fully_impl_no_graphics_str} |")

    md.append("")
    return "\n".join(md)


def generate_missing_features_section(index: Dict, with_links: bool = True) -> str:
    """Generate a section listing all missing features for each opcode."""
    md = []

    md.append("## Missing Features")
    md.append("")
    md.append("This section lists all missing features for opcodes that are not fully implemented.")
    md.append("")

    # Group entries by hex value
    opcodes_with_missing_features = []

    for entry in index['entries']:
        if entry['type'] == 'spec':
            hex_val = entry['hex']
            spec_name = entry['name']
            missing_features = entry.get('missing_features', {})

            if missing_features:
                opcodes_with_missing_features.append({
                    'hex': hex_val,
                    'spec_name': spec_name,
                    'missing_features': missing_features
                })

    if not opcodes_with_missing_features:
        md.append("**No opcodes with documented missing features! 🎉**")
        md.append("")
        return "\n".join(md)

    # Sort by hex value
    opcodes_with_missing_features.sort(key=lambda x: x['hex'])

    for opc in opcodes_with_missing_features:
        if with_links:
            header = f"### [{opc['hex']}: {opc['spec_name']}](#{make_anchor(opc['hex'], opc['spec_name'])})"
        else:
            header = f"### {opc['hex']}: {opc['spec_name']}"

        md.append(header)
        md.append("")

        # Group features by test
        for test_name, features in opc['missing_features'].items():
            if features:
                md.append(f"**From test `{test_name}`:**")
                for feature in features:
                    md.append(f"- {feature}")
                md.append("")

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
    md.append("**Test Result Legend:**")
    md.append("- **✓** - Test passed")
    md.append("- **✗** - Test failed")
    md.append("- **?** - Test not run (no results)")
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
            tests_primary_no_results = set(first_entry.get('tests_primary_no_results', []))
            for test_dir in first_entry['tests_primary']:
                if test_dir in tests_primary_passing:
                    status = "✓"
                elif test_dir in tests_primary_no_results:
                    status = "?"
                else:
                    status = "✗"
                md.append(f"- [{status}] `{test_dir}`")
            md.append("")

        # Secondary Tests
        if first_entry.get('tests_secondary'):
            md.append("**Secondary Tests:**")
            tests_secondary_passing = set(first_entry.get('tests_secondary_passing', []))
            tests_secondary_no_results = set(first_entry.get('tests_secondary_no_results', []))
            for test_dir in first_entry['tests_secondary']:
                if test_dir in tests_secondary_passing:
                    status = "✓"
                elif test_dir in tests_secondary_no_results:
                    status = "?"
                else:
                    status = "✗"
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


def generate_passing_tests_chart(index: Dict, with_links: bool = True) -> str:
    """Generate a chart showing all passing primary tests."""
    md = []

    md.append("## Passing Primary Tests")
    md.append("")

    # Collect all passing primary tests
    passing_tests = []

    for entry in index['entries']:
        if entry['type'] == 'spec':
            hex_val = entry['hex']
            spec_name = entry['name']

            # Get test lists
            primary_tests = entry.get('tests_primary', [])
            passing_primary = set(entry.get('tests_primary_passing', []))

            # Find passing primary tests
            for test in primary_tests:
                if test in passing_primary:
                    passing_tests.append({
                        'hex': hex_val,
                        'spec_name': spec_name,
                        'test_path': test,
                        'has_function': False,
                        'has_enum': False,
                        'has_docs': bool(entry.get('documentation_prompt'))
                    })

    # Add implementation info to passing tests
    for entry in index['entries']:
        if entry['type'] == 'enum':
            for test in passing_tests:
                if test['hex'] == entry['hex']:
                    test['has_enum'] = True
        elif entry['type'] == 'function':
            for test in passing_tests:
                if test['hex'] == entry['hex']:
                    test['has_function'] = True

    if not passing_tests:
        md.append("**No passing primary tests yet.**")
        md.append("")
        return "\n".join(md)

    # Sort by hex value, then by test path
    passing_tests.sort(key=lambda x: (x['hex'], x['test_path']))

    md.append(f"**Total Passing Primary Tests**: {len(passing_tests)}")
    md.append("")
    md.append("| Hex | Opcode | Test Path | Enum | Function | Docs |")
    md.append("|-----|--------|-----------|------|----------|------|")

    for test in passing_tests:
        if with_links:
            hex_link = make_link(test['hex'], test['hex'], test['spec_name'])
            spec_link = make_link(test['spec_name'], test['hex'], test['spec_name'])
        else:
            hex_link = test['hex']
            spec_link = test['spec_name']

        test_path = test['test_path']
        # Shorten test path for readability - keep just the test directory name
        test_name = test_path.split('/')[-1] if '/' in test_path else test_path

        md.append(f"| {hex_link} | {spec_link} | `{test_name}` | {'✓' if test['has_enum'] else ''} | {'✓' if test['has_function'] else ''} | {'✓' if test['has_docs'] else ''} |")

    md.append("")
    return "\n".join(md)


def generate_failing_tests_chart(index: Dict, with_links: bool = True) -> str:
    """Generate a chart showing all failing primary tests."""
    md = []

    md.append("## Failing Primary Tests")
    md.append("")

    # Collect all failing primary tests
    failing_tests = []

    for entry in index['entries']:
        if entry['type'] == 'spec':
            hex_val = entry['hex']
            spec_name = entry['name']

            # Get test lists
            primary_tests = entry.get('tests_primary', [])
            passing_primary = set(entry.get('tests_primary_passing', []))
            no_results_primary = set(entry.get('tests_primary_no_results', []))

            # Find failing primary tests (exclude tests with no results)
            for test in primary_tests:
                if test not in passing_primary and test not in no_results_primary:
                    failing_tests.append({
                        'hex': hex_val,
                        'spec_name': spec_name,
                        'test_path': test,
                        'has_function': False,
                        'has_enum': False,
                        'has_docs': bool(entry.get('documentation_prompt'))
                    })

    # Add implementation info to failing tests
    for entry in index['entries']:
        if entry['type'] == 'enum':
            for test in failing_tests:
                if test['hex'] == entry['hex']:
                    test['has_enum'] = True
        elif entry['type'] == 'function':
            for test in failing_tests:
                if test['hex'] == entry['hex']:
                    test['has_function'] = True

    if not failing_tests:
        md.append("**No failing primary tests! 🎉**")
        md.append("")
        return "\n".join(md)

    # Sort by hex value, then by test path
    failing_tests.sort(key=lambda x: (x['hex'], x['test_path']))

    md.append(f"**Total Failing Primary Tests**: {len(failing_tests)}")
    md.append("")
    md.append("| Hex | Opcode | Test Path | Enum | Function | Docs |")
    md.append("|-----|--------|-----------|------|----------|------|")

    for test in failing_tests:
        if with_links:
            hex_link = make_link(test['hex'], test['hex'], test['spec_name'])
            spec_link = make_link(test['spec_name'], test['hex'], test['spec_name'])
        else:
            hex_link = test['hex']
            spec_link = test['spec_name']

        test_path = test['test_path']
        # Shorten test path for readability - keep just the test directory name
        test_name = test_path.split('/')[-1] if '/' in test_path else test_path

        md.append(f"| {hex_link} | {spec_link} | `{test_name}` | {'✓' if test['has_enum'] else ''} | {'✓' if test['has_function'] else ''} | {'✓' if test['has_docs'] else ''} |")

    md.append("")
    return "\n".join(md)


def generate_no_results_tests_chart(index: Dict, with_links: bool = True) -> str:
    """Generate a chart showing all primary tests with no results."""
    md = []

    md.append("## Tests With No Results")
    md.append("")

    # Collect all tests with no results
    no_results_tests = []

    for entry in index['entries']:
        if entry['type'] == 'spec':
            hex_val = entry['hex']
            spec_name = entry['name']

            # Get test lists
            no_results_primary = entry.get('tests_primary_no_results', [])

            # Find tests with no results
            for test in no_results_primary:
                no_results_tests.append({
                    'hex': hex_val,
                    'spec_name': spec_name,
                    'test_path': test,
                    'has_function': False,
                    'has_enum': False,
                    'has_docs': bool(entry.get('documentation_prompt'))
                })

    # Add implementation info to no-results tests
    for entry in index['entries']:
        if entry['type'] == 'enum':
            for test in no_results_tests:
                if test['hex'] == entry['hex']:
                    test['has_enum'] = True
        elif entry['type'] == 'function':
            for test in no_results_tests:
                if test['hex'] == entry['hex']:
                    test['has_function'] = True

    if not no_results_tests:
        md.append("**All tests have results! 🎉**")
        md.append("")
        return "\n".join(md)

    # Sort by hex value, then by test path
    no_results_tests.sort(key=lambda x: (x['hex'], x['test_path']))

    md.append(f"**Total Tests With No Results**: {len(no_results_tests)}")
    md.append("")
    md.append("| Hex | Opcode | Test Path | Enum | Function | Docs |")
    md.append("|-----|--------|-----------|------|----------|------|")

    for test in no_results_tests:
        if with_links:
            hex_link = make_link(test['hex'], test['hex'], test['spec_name'])
            spec_link = make_link(test['spec_name'], test['hex'], test['spec_name'])
        else:
            hex_link = test['hex']
            spec_link = test['spec_name']

        test_path = test['test_path']
        # Shorten test path for readability - keep just the test directory name
        test_name = test_path.split('/')[-1] if '/' in test_path else test_path

        md.append(f"| {hex_link} | {spec_link} | `{test_name}` | {'✓' if test['has_enum'] else ''} | {'✓' if test['has_function'] else ''} | {'✓' if test['has_docs'] else ''} |")

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
                'fully_implemented': False,
                'fully_implemented_no_graphics': False
            }

        if entry['type'] == 'spec':
            opcodes[hex_val]['spec_name'] = entry['name']
            opcodes[hex_val]['has_primary_tests'] = len(entry.get('tests_primary', [])) > 0
            opcodes[hex_val]['primary_count'] = len(entry.get('tests_primary', []))
            opcodes[hex_val]['passing_primary_count'] = len(entry.get('tests_primary_passing', []))
            opcodes[hex_val]['has_docs'] = bool(entry.get('documentation_prompt'))
            opcodes[hex_val]['fully_implemented'] = entry.get('fully_implemented', False)
            opcodes[hex_val]['fully_implemented_no_graphics'] = entry.get('fully_implemented_no_graphics', False)
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
    md.append("| Hex | Spec Name | Enum | Function | Primary Tests | Failing Primary | Docs | No Graphics |")
    md.append("|-----|-----------|------|----------|---------------|-----------------|------|-------------|")

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
            no_graphics_str = "✓" if opc['fully_implemented_no_graphics'] else ""
            md.append(f"| {hex_link} | {spec_link} | {'✓' if opc['has_enum'] else ''} | {'✓' if opc['has_function'] else ''} | {test_status} | {failing_str} | {'✓' if opc['has_docs'] else ''} | {no_graphics_str} |")

    md.append("")

    # Partially implemented
    md.append("### 🔄 Partially Implemented")
    md.append("(Has enum or function, but not marked as fully implemented)")
    md.append("")
    md.append("| Hex | Spec Name | Enum | Function | Docs |")
    md.append("|-----|-----------|------|----------|------|")

    for hex_val in sorted(opcodes.keys()):
        opc = opcodes[hex_val]
        if (opc['has_enum'] or opc['has_function']) and not opc['fully_implemented']:
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
        if not opc['has_enum'] and not opc['has_function'] and not opc['fully_implemented']:
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
    passing_tests_with_links = generate_passing_tests_chart(index, with_links=True)
    failing_tests_with_links = generate_failing_tests_chart(index, with_links=True)
    no_results_tests_with_links = generate_no_results_tests_chart(index, with_links=True)
    status_with_links = generate_implementation_status(index, with_links=True)
    missing_features_with_links = generate_missing_features_section(index, with_links=True)

    markdown_with_links = "\n".join([
        summary_with_links,
        passing_tests_with_links,
        failing_tests_with_links,
        no_results_tests_with_links,
        status_with_links,
        missing_features_with_links,
        detailed
    ])

    output_path_with_links = BASE_DIR / "opcode-index.md"
    with open(output_path_with_links, 'w') as f:
        f.write(markdown_with_links)

    print(f"  Generated: {output_path_with_links}")

    # Generate version WITHOUT links
    print("\nGenerating version WITHOUT links...")
    summary_no_links = generate_summary_table(index, with_links=False)
    passing_tests_no_links = generate_passing_tests_chart(index, with_links=False)
    failing_tests_no_links = generate_failing_tests_chart(index, with_links=False)
    no_results_tests_no_links = generate_no_results_tests_chart(index, with_links=False)
    status_no_links = generate_implementation_status(index, with_links=False)
    missing_features_no_links = generate_missing_features_section(index, with_links=False)

    markdown_no_links = "\n".join([
        summary_no_links,
        passing_tests_no_links,
        failing_tests_no_links,
        no_results_tests_no_links,
        status_no_links,
        missing_features_no_links,
        detailed
    ])

    output_path_no_links = BASE_DIR / "opcode-index-plain.md"
    with open(output_path_no_links, 'w') as f:
        f.write(markdown_no_links)

    print(f"  Generated: {output_path_no_links}")

    print("\nMarkdown documentation generated successfully!")


if __name__ == '__main__':
    generate_markdown()
