#!/usr/bin/env python3
"""
Script to create a text file containing all prompts from md-files.json,
with three newlines between each prompt.
"""

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


def create_prompts_text(md_files, output_file):
    """Create a text file with all prompts."""
    script_dir = Path(__file__).parent

    with open(output_file, 'w') as f:
        for i, md_file in enumerate(md_files):
            # Build the prompt
            prompt = f"Please read this file and follow its instructions:\n{md_file}"

            # Write the prompt
            f.write(prompt)

            # Add three newlines between prompts (but not after the last one)
            if i < len(md_files) - 1:
                f.write("\n\n\n")

    print(f"Created {output_file} with {len(md_files)} prompts")


def main():
    # Load the file list
    md_files = load_md_files()

    if not md_files:
        print("Warning: No .md files found in md-files.json")
        sys.exit(0)

    # Create the output file
    output_file = Path(__file__).parent / 'prompts.txt'
    create_prompts_text(md_files, output_file)


if __name__ == '__main__':
    main()
