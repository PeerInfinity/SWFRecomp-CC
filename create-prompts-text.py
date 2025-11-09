#!/usr/bin/env python3
"""
Script to create a text file containing all prompts from md-files.json,
with three newlines between each prompt.
"""

import argparse
import json
import subprocess
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
    """Get mapping of documentation prompts to incomplete opcode info."""
    opcode_data = load_opcode_index()
    incomplete_info = {}  # Map prompt to dict with opcode info and missing features

    for entry in opcode_data['entries']:
        if entry.get('documentation_prompt'):
            # Check if BOTH fully_implemented and fully_implemented_no_graphics are False or missing
            fully_implemented = entry.get('fully_implemented', False)
            fully_implemented_no_graphics = entry.get('fully_implemented_no_graphics', False)

            if not fully_implemented and not fully_implemented_no_graphics:
                prompt = entry['documentation_prompt']

                # Store info for this prompt (take first entry with this prompt)
                if prompt not in incomplete_info:
                    incomplete_info[prompt] = {
                        'opcode_name': entry.get('name', 'Unknown'),
                        'hex': entry.get('hex', 'Unknown'),
                        'fully_implemented_no_graphics': fully_implemented_no_graphics,
                        'missing_features': entry.get('missing_features', {})
                    }

    return incomplete_info


def create_prompts_text(md_files, output_file, failing_info=None, incomplete_info=None):
    """Create a text file with all prompts.

    Args:
        md_files: List of markdown file paths
        output_file: Path to output file
        failing_info: Optional dict mapping prompts to failing test info
        incomplete_info: Optional dict mapping prompts to incomplete opcode info
    """
    script_dir = Path(__file__).parent

    with open(output_file, 'w') as f:
        for i, md_file in enumerate(md_files):
            # Choose guide based on mode
            if failing_info is not None:
                guide = "SWFRecompDocs/failing-test-fix-guide.md"
            elif incomplete_info is not None:
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

            # Add incomplete opcode info if available
            if incomplete_info and md_file in incomplete_info:
                info = incomplete_info[md_file]
                prompt += f"\n\nNOTE: Opcode {info['opcode_name']} ({info['hex']}) is marked as NOT fully implemented."

                # Add NO_GRAPHICS status if applicable
                if info['fully_implemented_no_graphics']:
                    prompt += f"\n- Status: Fully implemented in NO_GRAPHICS mode, but requires graphics support for full implementation."

                # Add missing features if documented
                missing_features = info.get('missing_features', {})
                if missing_features:
                    prompt += f"\n\nDocumented missing features:"
                    for test_name, features in missing_features.items():
                        if features:
                            prompt += f"\n  From test '{test_name}':"
                            for feature in features:
                                prompt += f"\n    - {feature}"
                    prompt += f"\n\nPlease address these missing features to complete the implementation."
                else:
                    prompt += f"\n\nNo specific missing features are documented. Please review the specification, identify what's incomplete, implement missing features, add comprehensive tests, and document any remaining missing features in test_info.json using the 'missing_features' field."

                prompt += f"\n\nWhen the opcode is fully complete, update test_info.json to set fully_implemented: true (or fully_implemented_no_graphics: true if graphics are the only missing piece)."

            # Write the prompt
            f.write(prompt)

            # Add three newlines between prompts (but not after the last one)
            if i < len(md_files) - 1:
                f.write("\n\n\n")

    print(f"Created {output_file} with {len(md_files)} prompts")


def regenerate_md_files_json():
    """Run create-md-files-json.py to regenerate md-files.json."""
    script_path = Path(__file__).parent / 'create-md-files-json.py'

    if not script_path.exists():
        print(f"Error: {script_path} does not exist", file=sys.stderr)
        sys.exit(1)

    print("Regenerating md-files.json...")
    try:
        result = subprocess.run(
            [sys.executable, str(script_path)],
            check=True,
            capture_output=True,
            text=True
        )
        # Print the output from create-md-files-json.py
        if result.stdout:
            print(result.stdout.rstrip())
    except subprocess.CalledProcessError as e:
        print(f"Error running create-md-files-json.py: {e}", file=sys.stderr)
        if e.stderr:
            print(e.stderr, file=sys.stderr)
        sys.exit(1)


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

    # Regenerate md-files.json before loading it
    regenerate_md_files_json()

    # Load the file list
    md_files = load_md_files()

    if not md_files:
        print("Warning: No .md files found in md-files.json")
        sys.exit(0)

    # Filter for failing opcodes if requested
    failing_info = None
    incomplete_info = None

    if args.fail:
        failing_info = get_failing_opcodes()
        md_files = [f for f in md_files if f in failing_info]
        print(f"Filtering for opcodes with failing tests: {len(md_files)} prompts")
    elif args.incomplete:
        incomplete_info = get_incomplete_opcodes()
        md_files = [f for f in md_files if f in incomplete_info]
        print(f"Filtering for opcodes not fully implemented: {len(md_files)} prompts")

    # Create the output file with appropriate name based on parameters
    if args.fail:
        output_filename = 'prompts-fail.txt'
    elif args.incomplete:
        output_filename = 'prompts-incomplete.txt'
    else:
        output_filename = 'prompts.txt'

    output_file = Path(__file__).parent / output_filename
    create_prompts_text(md_files, output_file, failing_info, incomplete_info)


if __name__ == '__main__':
    main()
