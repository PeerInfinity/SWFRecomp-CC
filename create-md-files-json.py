#!/usr/bin/env python3
"""
Script to find all .md files in SWFRecompDocs/prompts and its subdirectories
(excluding README.md) and save the list to md-files.json.
"""

import json
import os
from pathlib import Path


def find_md_files():
    """Find all .md files in SWFRecompDocs/prompts, excluding README.md."""
    base_dir = Path(__file__).parent / 'SWFRecompDocs' / 'prompts'

    if not base_dir.exists():
        print(f"Error: Directory {base_dir} does not exist")
        return []

    md_files = []

    # Walk through all subdirectories
    for root, dirs, files in os.walk(base_dir):
        for file in files:
            if file.endswith('.md') and file.lower() != 'readme.md':
                # Get full path
                full_path = Path(root) / file
                # Convert to relative path from project root
                relative_path = full_path.relative_to(Path(__file__).parent)
                md_files.append(str(relative_path))

    # Sort the files for consistency
    md_files.sort()

    return md_files


def main():
    """Main function to find .md files and save to JSON."""
    print("Finding .md files in SWFRecompDocs/prompts...")

    md_files = find_md_files()

    if not md_files:
        print("Warning: No .md files found (excluding README.md)")
    else:
        print(f"Found {len(md_files)} .md files")

    # Save to JSON file
    output_file = Path(__file__).parent / 'md-files.json'
    with open(output_file, 'w') as f:
        json.dump(md_files, f, indent=2)

    print(f"Saved file list to {output_file}")

    # Print first few files as a sample
    if md_files:
        print("\nSample of files found:")
        for file in md_files[:5]:
            print(f"  - {file}")
        if len(md_files) > 5:
            print(f"  ... and {len(md_files) - 5} more")


if __name__ == '__main__':
    main()
