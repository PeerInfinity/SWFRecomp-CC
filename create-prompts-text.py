#!/usr/bin/env python3
"""
Script to create a text file containing all prompts from md-files.json,
with three newlines between each prompt.
"""

import argparse
import json
import sys
from pathlib import Path


def load_md_files():
    """Load the list of .md files from md-files.json."""
    json_file = Path(__file__).parent / 'md-files.json'

    if not json_file.exists():
        print(f"Error: {json_file} does not exist", file=sys.stderr)
        print("Please run create-md-files-json.py first", file=sys.stderr)
        sys.exit(1)

    with open(json_file, 'r') as f:
        return json.load(f)


def load_opcode_index():
    """Load the opcode index from opcode-index.json."""
    json_file = Path(__file__).parent / 'opcode-index.json'

    if not json_file.exists():
        print(f"Error: {json_file} does not exist", file=sys.stderr)
        sys.exit(1)

    with open(json_file, 'r') as f:
        return json.load(f)


def get_failing_opcodes():
    """Get mapping of documentation prompts to failing test info for opcodes with at least one failing primary test."""
    opcode_data = load_opcode_index()
    failing_info = {}  # Map prompt to dict with opcode info and failing tests

    for entry in opcode_data['entries']:
        if entry.get('documentation_prompt'):
            primary_tests = set(entry.get('tests_primary', []))
            primary_passing = set(entry.get('tests_primary_passing', []))

            # Check if there are any failing primary tests
            if len(primary_tests) > len(primary_passing):
                failing_tests = primary_tests - primary_passing
                prompt = entry['documentation_prompt']

                # Store failing test info for this prompt (take first entry with this prompt)
                if prompt not in failing_info:
                    failing_info[prompt] = {
                        'opcode_name': entry.get('name', 'Unknown'),
                        'hex': entry.get('hex', 'Unknown'),
                        'failing_tests': failing_tests
                    }

    return failing_info


def get_incomplete_opcodes():
    """Get set of documentation prompts for opcodes that are not fully implemented."""
    opcode_data = load_opcode_index()
    incomplete_prompts = set()

    for entry in opcode_data['entries']:
        if entry.get('documentation_prompt'):
            # Check if fully_implemented is False or missing
            if not entry.get('fully_implemented', False):
                incomplete_prompts.add(entry['documentation_prompt'])

    return incomplete_prompts


def create_prompts_text(md_files, output_file, failing_info=None, incomplete_mode=False):
    """Create a text file with all prompts.

    Args:
        md_files: List of markdown file paths
        output_file: Path to output file
        failing_info: Optional dict mapping prompts to failing test info
        incomplete_mode: If True, use the complete-implementation-guide.md
    """
    script_dir = Path(__file__).parent

    with open(output_file, 'w') as f:
        for i, md_file in enumerate(md_files):
            # Choose guide based on mode
            if failing_info is not None:
                guide = "SWFRecompDocs/failing-test-fix-guide.md"
            elif incomplete_mode:
                guide = "SWFRecompDocs/complete-implementation-guide.md"
            else:
                guide = "SWFRecompDocs/parallel-opcode-implementation-guide.md"

            # Build the base prompt
            prompt = f"Please read these files and follow their instructions:\n{guide}\n{md_file}"

            # Add failing test info if available
            if failing_info and md_file in failing_info:
                info = failing_info[md_file]
                test_list = '\n'.join(f"  - {test}" for test in sorted(info['failing_tests']))
                prompt += f"\n\nNOTE: The following test(s) for opcode {info['opcode_name']} ({info['hex']}) are currently FAILING:\n{test_list}\n\nPlease debug and fix these failing tests."

            # Add incomplete mode note
            if incomplete_mode:
                prompt += f"\n\nNOTE: This opcode is marked as NOT fully implemented. Please complete the implementation to meet all criteria for the fully_implemented tag. Review the specification, implement missing features, add comprehensive tests, and update test_info.json when complete."

            # Write the prompt
            f.write(prompt)

            # Add three newlines between prompts (but not after the last one)
            if i < len(md_files) - 1:
                f.write("\n\n\n")

    print(f"Created {output_file} with {len(md_files)} prompts")


def main():
    parser = argparse.ArgumentParser(
        description='Create a text file containing all prompts from md-files.json'
    )
    parser.add_argument(
        '--fail',
        action='store_true',
        help='Only output prompts for opcodes with at least one failing test'
    )
    parser.add_argument(
        '--incomplete',
        action='store_true',
        help='Only output prompts for opcodes that are not fully implemented'
    )
    args = parser.parse_args()

    # Check for mutually exclusive flags
    if args.fail and args.incomplete:
        print("Error: --fail and --incomplete are mutually exclusive")
        sys.exit(1)

    # Load the file list
    md_files = load_md_files()

    if not md_files:
        print("Warning: No .md files found in md-files.json")
        sys.exit(0)

    # Filter for failing opcodes if requested
    failing_info = None
    incomplete_mode = False

    if args.fail:
        failing_info = get_failing_opcodes()
        md_files = [f for f in md_files if f in failing_info]
        print(f"Filtering for opcodes with failing tests: {len(md_files)} prompts")
    elif args.incomplete:
        incomplete_prompts = get_incomplete_opcodes()
        md_files = [f for f in md_files if f in incomplete_prompts]
        incomplete_mode = True
        print(f"Filtering for opcodes not fully implemented: {len(md_files)} prompts")

    if not md_files:
        print("Warning: No matching .md files found")
        sys.exit(0)

    # Create the output file with appropriate name based on parameters
    if args.fail:
        output_filename = 'prompts-fail.txt'
    elif args.incomplete:
        output_filename = 'prompts-incomplete.txt'
    else:
        output_filename = 'prompts.txt'

    output_file = Path(__file__).parent / output_filename
    create_prompts_text(md_files, output_file, failing_info, incomplete_mode)


if __name__ == '__main__':
    main()
